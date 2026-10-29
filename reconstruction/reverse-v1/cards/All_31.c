/* cally 逆向卡：All_31 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 31 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/31 vorbis_book_decodev_set  0x228afc  size 1060  265 条（0x228afc..0x228f20）
 * @func 0x228afc 0x228f20  size 1060  265 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: vorbis_book_decodev_set+0x1b8×7 / oggpack_adv×6 / oggpack_look×4 / vorbis_book_decodev_set+0x414×2 / vorbis_book_decodev_set+0x20c / vorbis_book_decodev_set+0x200 / vorbis_book_decodev_set+0x144 / vorbis_book_decodev_set+0x1c4
 * 字段偏移 top8: 0x4×9 / 0x2×8 / 0x8×5 / 0x1c×4 / 0x24×2 / 0x28×2 / 0x20×2 / 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x228afc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x228b00 sub sp, sp, #12
 *   @0x228b04 mov r8, r0
 *   @0x228b08 mov r6, r2
 *   @0x228b0c str r1, [sp, #0x4]
 *   @0x228b10 mov r5, r3
 *   @0x228b14 ldr r1, [r0, #0x8]
 *   @0x228b18 cmp r1, #0
 *   @0x228b1c ble 0x228d08 <vorbis_book_decodev_set+0x20c>
 *   @0x228b20 ldr r7, [r0, #0xc]
 *   @0x228b24 ldr r3, [sp, #0x30]
 *   @0x228b28 subs r7, r3, r7
 *   @0x228b2c bmi 0x228d3c <vorbis_book_decodev_set+0x240>
 *   @0x228b30 cmp r5, #0
 *   @0x228b34 ble 0x228cb4 <vorbis_book_decodev_set+0x1b8>
 *   @0x228b38 mov r9, #0
 *   @0x228b3c mov r0, r6
 *   @0x228b40 ldr r1, [r8, #0x24]
 *   @0x228b44 ldr r4, [r8, #0x28]
 *   @0x228b48 bl 0x23388c <oggpack_look>
 *   @0x228b4c cmp r0, #0
 *   @0x228b50 blt 0x228cfc <vorbis_book_decodev_set+0x200>
 *   @0x228b54 ldr r3, [r8, #0x20]
 *   @0x228b58 ldr r11, [r3, r0, lsl #2]
 *   @0x228b5c cmp r11, #0
 *   @0x228b60 bge 0x228cd4 <vorbis_book_decodev_set+0x1d8>
 *   @0x228b64 ldr r2, [r8, #0x8]
 *   @0x228b68 ubfx r3, r11, #0x0, #0xf
 *   @0x228b6c ubfx r11, r11, #0xf, #0xf
 *   @0x228b70 rsb r10, r3, r2
 *   @0x228b74 b 0x228b7c <vorbis_book_decodev_set+0x80>
 *   @0x228b78 sub r4, r4, #1
 *   @0x228b7c mov r0, r6
 *   @0x228b80 mov r1, r4
 *   @0x228b84 bl 0x23388c <oggpack_look>
 *   @0x228b88 cmp r4, #1
 *   @0x228b8c movle r3, #0
 *   @0x228b90 movgt r3, #1
 *   @0x228b94 ands r3, r3, r0, lsr #31
 *   @0x228b98 bne 0x228b78 <vorbis_book_decodev_set+0x7c>
 *   @0x228b9c cmp r0, #0
 *   @0x228ba0 blt 0x228f10 <vorbis_book_decodev_set+0x414>
 *   @0x228ba4 rev r0, r0
 *   @0x228ba8 movw r1, #0xf0f
 *   @0x228bac movw r3, #0xf0f0
 *   @0x228bb0 bfi r1, r1, #16, #16
 *   @0x228bb4 bfi r3, r3, #16, #16
 *   @0x228bb8 and r12, r1, r0, lsr #4
 *   @0x228bbc and r0, r3, r0, lsl #4
 *   @0x228bc0 movw r1, #0x3333
 *   @0x228bc4 orr r0, r0, r12
 *   @0x228bc8 bfi r1, r1, #16, #16
 *   @0x228bcc movw r3, #0xcccc
 *   @0x228bd0 bfi r3, r3, #16, #16
 *   @0x228bd4 and r1, r1, r0, lsr #2
 *   @0x228bd8 and r3, r3, r0, lsl #2
 *   @0x228bdc orr r12, r3, r1
 *   @0x228be0 rsb r3, r11, r10
 *   @0x228be4 movw r0, #0xaaaa
 *   @0x228be8 movw r1, #0x5555
 *   @0x228bec bfi r0, r0, #16, #16
 *   @0x228bf0 bfi r1, r1, #16, #16
 *   @0x228bf4 cmp r3, #1
 *   @0x228bf8 and r0, r0, r12, lsl #1
 *   @0x228bfc and r1, r1, r12, lsr #1
 *   @0x228c00 orr r0, r0, r1
 *   @0x228c04 ble 0x228c40 <vorbis_book_decodev_set+0x144>
 *   @0x228c08 ldr r12, [r8, #0x14]
 *   @0x228c0c asr r3, r3, #1
 *   @0x228c10 add r1, r3, r11
 *   @0x228c14 ldr r1, [r12, r1, lsl #2]
 *   @0x228c18 cmp r1, r0
 *   @0x228c1c movls lr, r3
 *   @0x228c20 movhi lr, #0
 *   @0x228c24 cmp r1, r0
 *   @0x228c28 add r11, r11, lr
 *   @0x228c2c movls r3, #0
 *   @0x228c30 rsb r10, r3, r10
 *   @0x228c34 rsb r3, r11, r10
 *   @0x228c38 cmp r3, #1
 *   @0x228c3c bgt 0x228c0c <vorbis_book_decodev_set+0x110>
 *   @0x228c40 ldr r3, [r8, #0x1c]
 *   @0x228c44 mov r0, r6
 *   @0x228c48 ldrb r1, [r3, r11]
 *   @0x228c4c cmp r1, r4
 *   @0x228c50 bgt 0x228d2c <vorbis_book_decodev_set+0x230>
 *   @0x228c54 bl 0x233a7c <oggpack_adv>
 *   @0x228c58 ldr r1, [r8]
 *   @0x228c5c ldr r3, [r8, #0x10]
 *   @0x228c60 cmp r1, #0
 *   @0x228c64 mul r11, r11, r1
 *   @0x228c68 add r2, r3, r11, lsl #2
 *   @0x228c6c ble 0x228cc0 <vorbis_book_decodev_set+0x1c4>
 *   @0x228c70 ldr r0, [r3, r11, lsl #2]
 *   @0x228c74 add r12, r9, #1
 *   @0x228c78 ldr r4, [sp, #0x4]
 *   @0x228c7c cmp r5, r12
 *   @0x228c80 asr r0, r0, r7
 *   @0x228c84 add r3, r4, r9, lsl #2
 *   @0x228c88 str r0, [r4, r9, lsl #2]
 *   @0x228c8c ble 0x228cb4 <vorbis_book_decodev_set+0x1b8>
 *   @0x228c90 add r9, r1, r9
 *   @0x228c94 cmp r12, r9
 *   @0x228c98 beq 0x228cc4 <vorbis_book_decodev_set+0x1c8>
 *   @0x228c9c ldr r1, [r2, #0x4]!
 *   @0x228ca0 add r12, r12, #1
 *   @0x228ca4 cmp r12, r5
 *   @0x228ca8 asr r1, r1, r7
 *   @0x228cac str r1, [r3, #0x4]!
 *   @0x228cb0 bne 0x228c94 <vorbis_book_decodev_set+0x198>
 *   @0x228cb4 mov r0, #0
 *   @0x228cb8 add sp, sp, #12
 *   @0x228cbc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x228cc0 mov r12, r9
 *   @0x228cc4 cmp r5, r12
 *   @0x228cc8 ble 0x228cb4 <vorbis_book_decodev_set+0x1b8>
 *   @0x228ccc mov r9, r12
 *   @0x228cd0 b 0x228b3c <vorbis_book_decodev_set+0x40>
 *   @0x228cd4 ldr r3, [r8, #0x1c]
 *   @0x228cd8 mov r0, r6
 *   @0x228cdc add r3, r3, r11
 *   @0x228ce0 ldrb r1, [r3, #-0x1]
 *   @0x228ce4 bl 0x233a7c <oggpack_adv>
 *   @0x228ce8 subs r11, r11, #1
 *   @0x228cec bhs 0x228c58 <vorbis_book_decodev_set+0x15c>
 *   @0x228cf0 mvn r0, #0
 *   @0x228cf4 add sp, sp, #12
 *   @0x228cf8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x228cfc ldr r10, [r8, #0x8]
 *   @0x228d00 mov r11, #0
 *   @0x228d04 b 0x228b7c <vorbis_book_decodev_set+0x80>
 *   @0x228d08 cmp r3, #0
 *   @0x228d0c ble 0x228cb4 <vorbis_book_decodev_set+0x1b8>
 *   @0x228d10 ldr r10, [sp, #0x4]
 *   @0x228d14 add r5, r10, r3, lsl #2
 *   @0x228d18 mov r3, #0
 *   @0x228d1c str r3, [r10], #4
 *   @0x228d20 cmp r10, r5
 *   @0x228d24 bne 0x228d1c <vorbis_book_decodev_set+0x220>
 *   @0x228d28 b 0x228cb4 <vorbis_book_decodev_set+0x1b8>
 *   @0x228d2c add r1, r4, #1
 *   @0x228d30 bl 0x233a7c <oggpack_adv>
 *   @0x228d34 mvn r0, #0
 *   @0x228d38 b 0x228cf4 <vorbis_book_decodev_set+0x1f8>
 *   @0x228d3c cmp r5, #0
 *   @0x228d40 movgt r10, #0
 *   @0x228d44 ble 0x228cb4 <vorbis_book_decodev_set+0x1b8>
 *   @0x228d48 mov r0, r6
 *   @0x228d4c ldr r1, [r8, #0x24]
 *   @0x228d50 ldr r4, [r8, #0x28]
 *   @0x228d54 bl 0x23388c <oggpack_look>
 *   @0x228d58 cmp r0, #0
 *   @0x228d5c blt 0x228efc <vorbis_book_decodev_set+0x400>
 *   @0x228d60 ldr r3, [r8, #0x20]
 *   @0x228d64 ldr r11, [r3, r0, lsl #2]
 *   @0x228d68 cmp r11, #0
 *   @0x228d6c bge 0x228edc <vorbis_book_decodev_set+0x3e0>
 *   @0x228d70 ldr r2, [r8, #0x8]
 *   @0x228d74 ubfx r3, r11, #0x0, #0xf
 *   @0x228d78 ubfx r11, r11, #0xf, #0xf
 *   @0x228d7c rsb r9, r3, r2
 *   @0x228d80 b 0x228d88 <vorbis_book_decodev_set+0x28c>
 *   @0x228d84 sub r4, r4, #1
 *   @0x228d88 mov r0, r6
 *   @0x228d8c mov r1, r4
 *   @0x228d90 bl 0x23388c <oggpack_look>
 *   @0x228d94 cmp r4, #1
 *   @0x228d98 movle r3, #0
 *   @0x228d9c movgt r3, #1
 *   @0x228da0 ands r3, r3, r0, lsr #31
 *   @0x228da4 bne 0x228d84 <vorbis_book_decodev_set+0x288>
 *   @0x228da8 cmp r0, #0
 *   @0x228dac blt 0x228f10 <vorbis_book_decodev_set+0x414>
 *   @0x228db0 rev r0, r0
 *   @0x228db4 movw r1, #0xf0f
 *   @0x228db8 movw r3, #0xf0f0
 *   @0x228dbc bfi r1, r1, #16, #16
 *   @0x228dc0 bfi r3, r3, #16, #16
 *   @0x228dc4 and r12, r1, r0, lsr #4
 *   @0x228dc8 and r0, r3, r0, lsl #4
 *   @0x228dcc movw r1, #0x3333
 *   @0x228dd0 orr r0, r0, r12
 *   @0x228dd4 bfi r1, r1, #16, #16
 *   @0x228dd8 movw r3, #0xcccc
 *   @0x228ddc bfi r3, r3, #16, #16
 *   @0x228de0 and r1, r1, r0, lsr #2
 *   @0x228de4 and r3, r3, r0, lsl #2
 *   @0x228de8 orr r12, r3, r1
 *   @0x228dec rsb r3, r11, r9
 *   @0x228df0 movw r0, #0xaaaa
 *   @0x228df4 movw r1, #0x5555
 *   @0x228df8 bfi r0, r0, #16, #16
 *   @0x228dfc bfi r1, r1, #16, #16
 *   @0x228e00 cmp r3, #1
 *   @0x228e04 and r0, r0, r12, lsl #1
 *   @0x228e08 and r1, r1, r12, lsr #1
 *   @0x228e0c orr r0, r0, r1
 *   @0x228e10 ble 0x228e4c <vorbis_book_decodev_set+0x350>
 *   @0x228e14 ldr r12, [r8, #0x14]
 *   @0x228e18 asr r3, r3, #1
 *   @0x228e1c add r1, r3, r11
 *   @0x228e20 ldr r1, [r12, r1, lsl #2]
 *   @0x228e24 cmp r1, r0
 *   @0x228e28 movls lr, r3
 *   @0x228e2c movhi lr, #0
 *   @0x228e30 cmp r1, r0
 *   @0x228e34 add r11, r11, lr
 *   @0x228e38 movls r3, #0
 *   @0x228e3c rsb r9, r3, r9
 *   @0x228e40 rsb r3, r11, r9
 *   @0x228e44 cmp r3, #1
 *   @0x228e48 bgt 0x228e18 <vorbis_book_decodev_set+0x31c>
 *   @0x228e4c ldr r3, [r8, #0x1c]
 *   @0x228e50 mov r0, r6
 *   @0x228e54 ldrb r1, [r3, r11]
 *   @0x228e58 cmp r1, r4
 *   @0x228e5c bgt 0x228d2c <vorbis_book_decodev_set+0x230>
 *   @0x228e60 bl 0x233a7c <oggpack_adv>
 *   @0x228e64 ldr r0, [r8]
 *   @0x228e68 ldr r3, [r8, #0x10]
 *   @0x228e6c cmp r0, #0
 *   @0x228e70 mul r11, r11, r0
 *   @0x228e74 add r1, r3, r11, lsl #2
 *   @0x228e78 ble 0x228f08 <vorbis_book_decodev_set+0x40c>
 *   @0x228e7c ldr r4, [r3, r11, lsl #2]
 *   @0x228e80 add r3, r10, #1
 *   @0x228e84 ldr r9, [sp, #0x4]
 *   @0x228e88 cmp r5, r3
 *   @0x228e8c rsb r12, r7, #0
 *   @0x228e90 lsl r4, r4, r12
 *   @0x228e94 add r2, r9, r10, lsl #2
 *   @0x228e98 str r4, [r9, r10, lsl #2]
 *   @0x228e9c ble 0x228cb4 <vorbis_book_decodev_set+0x1b8>
 *   @0x228ea0 add r9, r10, r0
 *   @0x228ea4 cmp r3, r9
 *   @0x228ea8 beq 0x228ecc <vorbis_book_decodev_set+0x3d0>
 *   @0x228eac ldr r0, [r1, #0x4]!
 *   @0x228eb0 add r3, r3, #1
 *   @0x228eb4 cmp r3, r5
 *   @0x228eb8 lsl r0, r0, r12
 *   @0x228ebc str r0, [r2, #0x4]!
 *   @0x228ec0 beq 0x228cb4 <vorbis_book_decodev_set+0x1b8>
 *   @0x228ec4 cmp r3, r9
 *   @0x228ec8 bne 0x228eac <vorbis_book_decodev_set+0x3b0>
 *   @0x228ecc cmp r5, r3
 *   @0x228ed0 ble 0x228cb4 <vorbis_book_decodev_set+0x1b8>
 *   @0x228ed4 mov r10, r3
 *   @0x228ed8 b 0x228d48 <vorbis_book_decodev_set+0x24c>
 *   @0x228edc ldr r3, [r8, #0x1c]
 *   @0x228ee0 mov r0, r6
 *   @0x228ee4 add r3, r3, r11
 *   @0x228ee8 ldrb r1, [r3, #-0x1]
 *   @0x228eec bl 0x233a7c <oggpack_adv>
 *   @0x228ef0 subs r11, r11, #1
 *   @0x228ef4 bhs 0x228e64 <vorbis_book_decodev_set+0x368>
 *   @0x228ef8 b 0x228cf0 <vorbis_book_decodev_set+0x1f4>
 *   @0x228efc ldr r9, [r8, #0x8]
 *   @0x228f00 mov r11, #0
 *   @0x228f04 b 0x228d88 <vorbis_book_decodev_set+0x28c>
 *   @0x228f08 mov r3, r10
 *   @0x228f0c b 0x228ecc <vorbis_book_decodev_set+0x3d0>
 *   @0x228f10 mov r0, r6
 *   @0x228f14 mov r1, #1
 *   @0x228f18 bl 0x233a7c <oggpack_adv>
 *   @0x228f1c b 0x228cf0 <vorbis_book_decodev_set+0x1f4>
 *
 * ══ §2/31 png_write_find_filter  0x2b29d8  size 1060  265 条（0x2b29d8..0x2b2dfc）
 * @func 0x2b29d8 0x2b2dfc  size 1060  265 条
 * 部分覆盖: 本节 265/464 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x335ab8 / 0xff4d2ad8 / 0x1a74afc / 0xff48eb34 / 0xff5e2b64 / 0x1a75b78 / png_write_find_filter+0x166 / 0xfed5abbc
 * 字段偏移 top8: 0x8×5 / 0x4×4 / 0xc×3 / 0x10×3 / 0x1×2 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b29d8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b29dc mov r11, r0
 *   @0x2b29e0 sub sp, #0x1c
 *   @0x2b29e4 stmdavs r10, {r0, r3, r5, r6, r7, r8} ^
 *   @0x2b29e8 adds r3, #0x7
 *   @0x2b29ec streq r4, [r7, -r12, lsr #3]
 *   @0x2b29f0 asr.w r3, r3, #0x3
 *   @0x2b29f4 str r2, [sp, #0xc]
 *   @0x2b29f8 ldr.w r2, [r11, #0x1b0]
 *   @0x2b29fc bpl 0x2b2a1e <png_write_find_filter+0x46>
 *   @0x2b2a00 beq 0x2b2a74 <png_write_find_filter+0x9c>
 *   @0x2b2a04 mov r4, r2
 *   @0x2b2a08 add r6, r2
 *   @0x2b2a0c beq 0x2b2a22 <png_write_find_filter+0x4a>
 *   @0x2b2a10 ldclhs p15, c5, [pc, #-4]!
 *   @0x2b2a14 it gt
 *   @0x2b2a18 strtmi r7, [r9], #-1408
 *   @0x2b2a1c b 0x2b2a0a <png_write_find_filter+0x32>
 *   @0x2b2a20 ldmdahs r0, {r8, lr}
 *   @0x2b2a24 bne 0x2b2a78 <png_write_find_filter+0xa0>
 *   @0x2b2a28 mrrcne p1, #0xb, r5, r6, c4
 *   @0x2b2a2c movs r4, #0x0
 *   @0x2b2a30 cmp r4, r3
 *   @0x2b2a34 add.w r12, r2, r4
 *   @0x2b2a38 ldrb.w r8, [r12, #0x1]
 *   @0x2b2a3c add.w r12, r5, r4
 *   @0x2b2a40 adds r4, #0x1
 *   @0x2b2a44 ldrb r8, [r3, r1]!
 *   @0x2b2a48 mov r9, r7
 *   @0x2b2a4c mov r4, r3
 *   @0x2b2a50 cmp r4, r5
 *   @0x2b2a54 add.w r12, r7, r4
 *   @0x2b2a58 ldrb.w r8, [r6, r4]
 *   @0x2b2a5c ldrb.w r12, [r12, #0x1]
 *   @0x2b2a60 rsb r12, r12, r8
 *   @0x2b2a64 strb.w r12, [r9, r4]
 *   @0x2b2a68 adds r4, #0x1
 *   @0x2b2a6c ldr.w r6, [r11, #0x1b4]
 *   @0x2b2a70 str r6, [sp, #0x8]
 *   @0x2b2a74 mvn r1, #0x80000000
 *   @0x2b2a78 lsls r6, r0, #0x1b
 *   @0x2b2a7c ldr.w r7, [r11, #0x1b4]
 *   @0x2b2a80 movs r5, #0x0
 *   @0x2b2a84 strtmi r0, [r12], -r1, lsl #16
 *   @0x2b2a88 add.w r12, r7, #0x1
 *   @0x2b2a8c cmp r5, r3
 *   @0x2b2a90 adds r6, r2, r5
 *   @0x2b2a94 strlo r0, [r1, #-0x905]
 *   @0x2b2a98 ldrb r6, [r6, #0x1]
 *   @0x2b2a9c strb.w r6, [r9, #0x1]
 *   @0x2b2aa0 it gt
 *   @0x2b2aa4 ldrtmi r7, [r4], #-1664
 *   @0x2b2aa8 b 0x2b2a8c <png_write_find_filter+0xb4>
 *   @0x2b2aac .word 0xf1c30903
 *   @0x2b2ab0 bl 0x335ab8
 *   @0x2b2ab4 strbmi r0, [r12], #1804
 *   @0x2b2ab8 mov r5, r3
 *   @0x2b2abc ldr r6, [sp, #0xc]
 *   @0x2b2ac0 bhs 0x2b2aee <png_write_find_filter+0x116>
 *   @0x2b2ac4 .word 0xf81a0805
 *   @0x2b2ac8 .word 0xf8989005
 *   @0x2b2acc bl 0xff4d2ad8 <b2_toiTime+0xfffffffffed79634>
 *   @0x2b2ad0 blx 0x1a74afc <b2_toiTime+0x131b658>
 *   @0x2b2ad4 .word 0xf80cf888
 *   @0x2b2ad8 .word 0xf1b88005
 *   @0x2b2adc svclt #0xc80f7f
 *   @0x2b2ae0 rsbgt.w r8, r8, #0x100
 *   @0x2b2ae4 add r4, r8
 *   @0x2b2ae8 bhi 0x2b2afc <png_write_find_filter+0x124>
 *   @0x2b2aec b 0x2b2abc <png_write_find_filter+0xe4>
 *   @0x2b2af0 bhs 0x2b2afc <png_write_find_filter+0x124>
 *   @0x2b2af4 strhls r1, [r2, -r4]
 *   @0x2b2af8 mov r1, r4
 *   @0x2b2afc str r2, [sp, #0x8]
 *   @0x2b2b00 bne 0x2b2b2e <png_write_find_filter+0x156>
 *   @0x2b2b04 ldr.w r6, [r11, #0x1b8]
 *   @0x2b2b08 adds r5, r4, #0x1
 *   @0x2b2b0c adds r4, #0x1
 *   @0x2b2b10 beq 0x2b2b26 <png_write_find_filter+0x14e>
 *   @0x2b2b14 .word 0xf8128004
 *   @0x2b2b18 .word 0xf818c004
 *   @0x2b2b1c bl 0xff48eb34 <b2_toiTime+0xfffffffffed35690>
 *   @0x2b2b20 ldrpl r0, [r7, #-0x70c]!
 *   @0x2b2b24 b 0x2b2b0c <png_write_find_filter+0x134>
 *   @0x2b2b28 strls r4, [r2], #-440
 *   @0x2b2b2c b 0x2b2be2 <png_write_find_filter+0x20a>
 *   @0x2b2b30 bpl 0x2b2b7c <png_write_find_filter+0x1a4>
 *   @0x2b2b34 movs r4, #0x1
 *   @0x2b2b38 stclne p1, c7, [lr], #-736
 *   @0x2b2b3c movs r5, #0x0
 *   @0x2b2b40 beq 0x2b2b70 <png_write_find_filter+0x198>
 *   @0x2b2b44 .word 0xf8129004
 *   @0x2b2b48 .word 0xf8198004
 *   @0x2b2b4c bl 0xff5e2b64 <b2_toiTime+0xfffffffffee896c0>
 *   @0x2b2b50 blx 0x1a75b78 <b2_toiTime+0x131c6d4>
 *   @0x2b2b54 .word 0xf807fc8c
 *   @0x2b2b58 .word 0xf1bcc004
 *   @0x2b2b5c .word 0xf1040f7f
 *   @0x2b2b60 svclt #0xc80401
 *   @0x2b2b64 rsbgt.w r12, r12, #0x100
 *   @0x2b2b68 add r5, r12
 *   @0x2b2b6c bls 0x2b2b3e <png_write_find_filter+0x166>
 *   @0x2b2b70 cmp r5, r1
 *   @0x2b2b74 ldr.w r1, [r11, #0x1b8]
 *   @0x2b2b78 str r1, [sp, #0x8]
 *   @0x2b2b7c cmp r0, #0x40
 *   @0x2b2b80 ldr.w r5, [r11, #0x1bc]
 *   @0x2b2b84 adds r7, r2, #0x1
 *   @0x2b2b88 add.w r8, r3, #0x1
 *   @0x2b2b8c add.w r12, r5, #0x1
 *   @0x2b2b90 adds r6, r4, #0x1
 *   @0x2b2b94 adds r4, #0x1
 *   @0x2b2b98 beq 0x2b2bb0 <png_write_find_filter+0x1d8>
 *   @0x2b2b9c .word 0xf81aa004
 *   @0x2b2ba0 .word 0xf8129004
 *   @0x2b2ba4 bl 0xfed5abbc <b2_toiTime+0xfffffffffe601718>
 *   @0x2b2ba8 .word 0xf8050959
 *   @0x2b2bac ldrb r9, [r1, r4]!
 *   @0x2b2bb0 rsb r10, r3, r2
 *   @0x2b2bb4 mov r4, r3
 *   @0x2b2bb8 cmp r4, r5
 *   @0x2b2bbc add.w r8, r10, r4
 *   @0x2b2bc0 ldrb.w r9, [r6, r4]
 *   @0x2b2bc4 ldrb.w r8, [r8, #0x1]
 *   @0x2b2bc8 add r8, r9
 *   @0x2b2bcc bl 0xfed16be4 <b2_toiTime+0xfffffffffe5bd740>
 *   @0x2b2bd0 .word 0xf80c0858
 *   @0x2b2bd4 strlo r8, [r1], #-4
 *   @0x2b2bd8 b 0x2b2bb6 <png_write_find_filter+0x1de>
 *   @0x2b2bdc .word 0x960261bc
 *   @0x2b2be0 b 0x2b2d18 <png_write_find_filter+0x340>
 *   @0x2b2be4 bpl 0x2b2c76 <png_write_find_filter+0x29e>
 *   @0x2b2be8 .word 0xf10261bc
 *   @0x2b2bec .word 0x9c010a01
 *   @0x2b2bf0 add.w r8, r3, #0x1
 *   @0x2b2bf4 add.w r9, r6, #0x1
 *   @0x2b2bf8 movs r5, #0x1
 *   @0x2b2bfc str r4, [sp, #0x10]
 *   @0x2b2c00 cmp r5, r8
 *   @0x2b2c04 ldr.w r12, [sp, #0x4]
 *   @0x2b2c08 ldrb.w r7, [r12, r5]
 *   @0x2b2c0c ldrb.w r12, [r2, r5]
 *   @0x2b2c10 sub.w r7, r12, r7, lsr #1
 *   @0x2b2c14 uxtb r7, r7
 *   @0x2b2c18 cmp r7, #0x7f
 *   @0x2b2c1c svclt #0xc80501
 *   @0x2b2c20 rsbgt.w r7, r7, #0x100
 *   @0x2b2c24 add r4, r7
 *   @0x2b2c28 rsbs r6, r3, #0
 *   @0x2b2c2c ldr.w r8, [sp, #0x10]
 *   @0x2b2c30 add.w r12, r2, r6
 *   @0x2b2c34 add r9, r6
 *   @0x2b2c38 ldr r6, [sp, #0xc]
 *   @0x2b2c3c bhs 0x2b2c6a <png_write_find_filter+0x292>
 *   @0x2b2c40 .word 0xf8180605
 *   @0x2b2c44 ldmdavc r6!, {r0, r2, r12, sp, lr} ^
 *   @0x2b2c48 add r6, r7
 *   @0x2b2c4c bl 0xfec8ec68 <b2_toiTime+0xfffffffffe5357c4>
 *   @0x2b2c50 rscslt r0, r6, #90177536
 *   @0x2b2c54 strb.w r6, [r9, r5]
 *   @0x2b2c58 cmp r6, #0x7f
 *   @0x2b2c5c rsbgt.w r6, r6, #0x100
 *   @0x2b2c60 add r4, r6
 *   @0x2b2c64 bhi 0x2b2c76 <png_write_find_filter+0x29e>
 *   @0x2b2c68 b 0x2b2c38 <png_write_find_filter+0x260>
 *   @0x2b2c6c bhs 0x2b2c76 <png_write_find_filter+0x29e>
 *   @0x2b2c70 strhls r1, [r2, -r12]
 *   @0x2b2c74 mov r1, r4
 *   @0x2b2c78 bne 0x2b2d18 <png_write_find_filter+0x340>
 *   @0x2b2c7c adds r4, r2, #0x1
 *   @0x2b2c80 smlabths r0, r0, r1, r0
 *   @0x2b2c84 add.w r12, r5, #0x1
 *   @0x2b2c88 adds r5, r3, #0x1
 *   @0x2b2c8c .word 0x31010a01
 *   @0x2b2c90 cmp r1, r5
 *   @0x2b2c94 ldr.w r8, [sp, #0x4]
 *   @0x2b2c98 ldrb r7, [r2, r1]
 *   @0x2b2c9c blne 0xff24aca8 <b2_toiTime+0xfffffffffeaf1804>
 *   @0x2b2ca0 strb r6, [r0, r1]
 *   @0x2b2ca4 ldr.w r8, [sp, #0x4]
 *   @0x2b2ca8 rsbs r1, r3, #0
 *   @0x2b2cac add r10, r3
 *   @0x2b2cb0 add r8, r1
 *   @0x2b2cb4 add.w r9, r2, r1
 *   @0x2b2cb8 add r10, r1
 *   @0x2b2cbc str r1, [sp, #0x4]
 *   @0x2b2cc0 cmp r3, r1
 *   @0x2b2cc4 add.w r2, r8, r3
 *   @0x2b2cc8 add.w r1, r9, r3
 *   @0x2b2ccc ldrb.w r0, [r12, r3]
 *   @0x2b2cd0 ldrb r2, [r2, #0x1]
 *   @0x2b2cd4 subs r7, r0, r2
 *   @0x2b2cd8 eor.w r5, r7, r7, asr #31
 *   @0x2b2cdc sub.w r5, r5, r7, asr #31
 *   @0x2b2ce0 eor.w r4, r6, r6, asr #31
 *   @0x2b2ce4 sub.w r4, r4, r6, asr #31
 *   @0x2b2ce8 add r6, r7
 *   @0x2b2cec it lt
 *   @0x2b2cf0 cmp r5, r4
 *   @0x2b2cf4 cmp r5, r6
 *   @0x2b2cf8 cmp r4, r6
 *   @0x2b2cfc movle r2, r0
 *   @0x2b2d00 mov r2, r1
 *   @0x2b2d04 ldrb r1, [r0, r3]
 *   @0x2b2d08 strb.w r2, [r10, r3]
 *   @0x2b2d0c adds r3, #0x1
 *   @0x2b2d10 ldr.w r2, [r11, #0x1c0]
 *   @0x2b2d14 str r2, [sp, #0x8]
 *   @0x2b2d18 lsls r0, r0, #0x18
 *   @0x2b2d1c ldr.w r5, [r11, #0x1c0]
 *   @0x2b2d20 add.w r9, r2, #0x1
 *   @0x2b2d24 ldr r4, [sp, #0x4]
 *   @0x2b2d28 add.w r10, r5, #0x1
 *   @0x2b2d2c adds r6, r3, #0x1
 *   @0x2b2d30 strhs r0, [r1], #-2049
 *   @0x2b2d34 str r6, [sp, #0x10]
 *   @0x2b2d38 strbmi r12, [r4, #-0x10]!
 *   @0x2b2d3c beq 0x2b2d5e <png_write_find_filter+0x386>
 *   @0x2b2d40 ldrb.w r12, [r2, r4]
 *   @0x2b2d44 ldrb r7, [r6, r4]
 *   @0x2b2d48 rscslt r0, pc, #12, #14
 *   @0x2b2d4c strb r7, [r5, r4]
 *   @0x2b2d50 add.w r4, r4, #0x1
 *   @0x2b2d54 it gt
 *   @0x2b2d58 ldrtmi r7, [r8], #-1920
 *   @0x2b2d5c b 0x2b2d36 <png_write_find_filter+0x35e>
 *   @0x2b2d60 add r9, r3
 *   @0x2b2d64 ldr r5, [sp, #0x4]
 *   @0x2b2d68 add r10, r4
 *   @0x2b2d6c add r5, r4
 *   @0x2b2d70 add r2, r4
 *   @0x2b2d74 strls r8, [r1, #-0x10]
 *   @0x2b2d78 str r2, [sp, #0x14]
 *   @0x2b2d7c cmp r3, r2
 *   @0x2b2d80 ldr r2, [sp, #0x4]
 *   @0x2b2d84 ldr r6, [sp, #0x10]
 *   @0x2b2d88 add r4, r3
 *   @0x2b2d8c ldrb r5, [r6, r3]
 *   @0x2b2d90 rsb r8, r2, r5
 *   @0x2b2d94 rsb r12, r2, r4
 *   @0x2b2d98 eor.w r7, r8, r8, asr #31
 *   @0x2b2d9c sub.w r7, r7, r8, asr #31
 *   @0x2b2da0 eor.w r6, r12, r12, asr #31
 *   @0x2b2da4 sub.w r6, r6, r12, asr #31
 *   @0x2b2da8 add r12, r8
 *   @0x2b2dac svclt #0xb80f00
 *   @0x2b2db0 rsblt.w r12, r12, #0x0
 *   @0x2b2db4 cmp r7, r6
 *   @0x2b2db8 cmp r7, r12
 *   @0x2b2dbc cmp r6, r12
 *   @0x2b2dc0 movle r2, r5
 *   @0x2b2dc4 mov r2, r4
 *   @0x2b2dc8 bne 0xfeb42ddc <b2_toiTime+0xfffffffffe3e9938>
 *   @0x2b2dcc uxtb r2, r2
 *   @0x2b2dd0 bhs 0x227ade4 <b2_toiTime+0x1b21940>
 *   @0x2b2dd4 it gt
 *   @0x2b2dd8 ldrmi r7, [r0], #-640
 *   @0x2b2ddc cmp r0, r1
 *   @0x2b2de0 adds r3, #0x1
 *   @0x2b2de4 cmp r0, r1
 *   @0x2b2de8 ldrlo.w r3, [r11, #0x1c0]
 *   @0x2b2dec strlo r3, [sp, #0x8]
 *   @0x2b2df0 ldr r1, [sp, #0x8]
 *   @0x2b2df4 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b2df8 b.w 0x2b293c <png_write_filtered_row>
 *
 * ══ §3/31 anon_2f0d1c  0x2f0d1c  size 1060  265 条（0x2f0d1c..0x2f1140）
 * @func 0x2f0d1c 0x2f1140  size 1060  265 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x160ee30 / 0x3ab9d4 / 0xff53f9e0 / 0x3c2768 / 0x33009c / 0x12f3e60 / 0x33ce70 / 0x368e88
 * 字段偏移 top8: 0x18×1 / 0xa×1 / 0x1a×1 / 0xe×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2f0d1c push {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2f0d20 strdlt r4, r5, [r9], r0
 *   @0x2f0d24 strmi r6, [r0], r7, lsl #16
 *   @0x2f0d28 svclo #0x19103
 *   @0x2f0d2c .word 0x1c07ea4f
 *   @0x2f0d30 .word 0xf8cd2f00
 *   @0x2f0d34 vhadd.u8 d28, d0, d4
 *   @0x2f0d38 .word 0xf8d880a6
 *   @0x2f0d3c svclo #0x15008
 *   @0x2f0d40 ldclne p8, c9, [r10], #-4
 *   @0x2f0d44 .word 0xc004f8dd
 *   @0x2f0d48 stmvs r3, {r3, r5, r10, lr}
 *   @0x2f0d4c andlt pc, r12, r5, asr r8
 *   @0x2f0d50 ldrtmi r9, [r11], -r2, lsl #6
 *   @0x2f0d54 .word 0x1c10f850
 *   @0x2f0d58 .word 0x9c024699
 *   @0x2f0d5c .word 0x6c08f850
 *   @0x2f0d60 svclt #0x38458b
 *   @0x2f0d64 stmdbhs r7, {r0, r3, r4, r6, r9, r10, lr}
 *   @0x2f0d68 .word 0x46a446b2
 *   @0x2f0d6c .word 0xf89ad90f
 *   @0x2f0d70 strlo r10, [r1], #-0
 *   @0x2f0d74 mulgt r0, r12, r8
 *   @0x2f0d78 b 0x97e584 <b2_toiTime+0x2250e0>
 *   @0x2f0d7c andle r0, r4, r12, lsl #30
 *   @0x2f0d80 ldmdale r0, {r0, r1, r4, r7, r9, lr}
 *   @0x2f0d84 sadd8mi r4, r10, r1
 *   @0x2f0d88 stmdblo r8, {r0, r2, r3, sp, lr, pc}
 *   @0x2f0d8c stmdbhs r0, {r0, r1, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2f0d90 ldmdavc r6!, {r0, r1, r2, r3, r5, r6, r12, lr, pc}
 *   @0x2f0d94 ldcleq p0, c15, [pc], #316
 *   @0x2f0d98 blx 0x160ee30 <b2_toiTime+0xeb598c>
 *   @0x2f0d9c eormi pc, r6, r1, lsl #2
 *   @0x2f0da0 rsble r4, r6, lr, lsl #7
 *   @0x2f0da4 strbmi lr, [r10, #-0x7ec]
 *   @0x2f0da8 .word 0xf8d8d268
 *   @0x2f0dac ldrmi r3, [r9]
 *   @0x2f0db0 b 0x16e5748 <b2_toiTime+0xf8c2a4>
 *   @0x2f0db4 tsteq r2, r9, lsl #6
 *   @0x2f0db8 bleq 0x3ab9d4 <error_g0017+0x4678>
 *   @0x2f0dbc .word 0xf85518ec
 *   @0x2f0dc0 stmpl lr!, {r0, r1, sp, pc}
 *   @0x2f0dc4 svceq #0xf1ba
 *   @0x2f0dc8 andhs sp, r0, #28, #2
 *   @0x2f0dcc rscvs r5, r2, r10, ror #1
 *   @0x2f0dd0 .word 0x3000f8d8
 *   @0x2f0dd4 bl 0xff53f9e0 <b2_toiTime+0xfffffffffede653c>
 *   @0x2f0dd8 ldrmi r0, [r1, #0x903]
 *   @0x2f0ddc ldm r4, {r0, r1, r6, r8, r10, r11, r12, lr, pc}
 *   @0x2f0de0 stcge p0, c0, [r4, #-60]
 *   @0x2f0de4 stmdbne r9, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f0de8 andeq lr, pc, r5, lsl #17
 *   @0x2f0dec tsteq r0, r4, lsl #2
 *   @0x2f0df0 strbmi r4, [r10], -r0, lsr #12
 *   @0x2f0df4 mcrr p5, #0xc, pc, lr, c5
 *   @0x2f0df8 muleq pc, r5, r8
 *   @0x2f0dfc stm r4, {r2, r3, r6, r10, lr}
 *   @0x2f0e00 eors r0, r0, pc
 *   @0x2f0e04 stmdale r8, {r1, r4, r5, r7, r8, r10, lr}
 *   @0x2f0e08 beq 0x4ed238 <SrcVerts+0x4a27c>
 *   @0x2f0e0c .word 0xf8db68a0
 *   @0x2f0e10 andhs r1, r0, #8
 *   @0x2f0e14 beq 0xff9ab758 <b2_toiTime+0xffffffffff2522b4>
 *   @0x2f0e18 uadd16mi lr, r8, r11
 *   @0x2f0e1c bls 0x3c2768 <error_g0017+0x1b40c>
 *   @0x2f0e20 .word 0xf7ff9300
 *   @0x2f0e24 blls 0x33009c
 *   @0x2f0e28 .word 0xf8dbbb70
 *   @0x2f0e2c addsmi r2, r6, #0
 *   @0x2f0e30 .word 0xf8dbd20b
 *   @0x2f0e34 ldmeq r2!, {r3, r12} ^
 *   @0x2f0e38 .word 0xf0062080
 *   @0x2f0e3c blx 0x12f3e60 <b2_toiTime+0xb9a9bc>
 *   @0x2f0e40 stcpl p12, c15, [r8], {12}
 *   @0x2f0e44 andeq lr, r12, r0, lsr #20
 *   @0x2f0e48 strlo r5, [r1], -r8, lsl #9
 *   @0x2f0e4c mvnle r4, r6, asr r5
 *   @0x2f0e50 ldrbmi lr, [r2, #-0x7da]
 *   @0x2f0e54 .word 0xf810d0b9
 *   @0x2f0e58 stcpl p0, c12, [lr], {2}
 *   @0x2f0e5c streq lr, [r6], -r12, asr #20
 *   @0x2f0e60 andlo r5, r1, #-1912602624
 *   @0x2f0e64 .word 0xf8d8e7f5
 *   @0x2f0e68 bllo 0x33ce70
 *   @0x2f0e6c andlo pc, r0, r8, asr #17
 *   @0x2f0e70 bllo 0x368e88 <_ZTS12CDS_Priority+0xaee0>
 *   @0x2f0e74 mrrcne p8, #0x1, r3, r9, c0
 *   @0x2f0e78 svcge #0x6cf47f
 *   @0x2f0e7c .word 0xc004f8dd
 *   @0x2f0e80 .word 0x0c10f1ac
 *   @0x2f0e84 andhs lr, r0, r4, asr r7
 *   @0x2f0e88 pop {r0, r3, r12, sp, pc}
 *   @0x2f0e8c push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2f0e90 strdlt r4, r5, [r5], r0
 *   @0x2f0e94 strmi r6, [r4], -sp, lsl #16
 *   @0x2f0e98 ldrmi r4, [r8], -r9, lsl #13
 *   @0x2f0e9c .word 0x46984616
 *   @0x2f0ea0 beq 0x146b7e4 <b2_toiTime+0xd12340>
 *   @0x2f0ea4 svcge #0x32200
 *   @0x2f0ea8 strls r9, [r1, -r0, lsl #4]
 *   @0x2f0eac ldrbmi r2, [r3], -r4, lsl #2
 *   @0x2f0eb0 .word 0xf8edf7f7
 *   @0x2f0eb4 rscvs r9, r0, r3, lsl #20
 *   @0x2f0eb8 stmdals r3, {r1, r3, r4, r8, r12, sp, pc}
 *   @0x2f0ebc pop {r0, r2, r12, sp, pc}
 *   @0x2f0ec0 stm sp, {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2f0ec4 strbmi r0, [r0], -r4, lsl #1
 *   @0x2f0ec8 qadd16mi r2, r11, r12
 *   @0x2f0ecc .word 0xf8dff7f7
 *   @0x2f0ed0 adcvs r9, r0, r3, lsl #20
 *   @0x2f0ed4 mvnsle r2, r0, lsl #20
 *   @0x2f0ed8 movweq pc, #0x110a
 *   @0x2f0edc addeq lr, r4, sp, lsl #17
 *   @0x2f0ee0 tsths r0, r0, asr #12
 *   @0x2f0ee4 .word 0xf8d3f7f7
 *   @0x2f0ee8 lslvs r9, r3, #22
 *   @0x2f0eec mvnle r2, r0, lsl #22
 *   @0x2f0ef0 rsbvs r6, r3, r2, ror #17
 *   @0x2f0ef4 bl 0x389488 <_ZTS13C_UTF16String+0x20534>
 *   @0x2f0ef8 mvnvs r0, r5, lsl #5
 *   @0x2f0efc .word 0x61226025
 *   @0x2f0f00 .word 0xf8d968a3
 *   @0x2f0f04 .word 0x310c1008
 *   @0x2f0f08 .word 0xb16d331c
 *   @0x2f0f0c .word 0x2c0cf851
 *   @0x2f0f10 .word 0xf8433d01
 *   @0x2f0f14 .word 0xf8512c1c
 *   @0x2f0f18 .word 0xf8432c08
 *   @0x2f0f1c .word 0xf8512c18
 *   @0x2f0f20 .word 0xf8432c04
 *   @0x2f0f24 strb r2, [lr, r12, lsl #24]!
 *   @0x2f0f28 stmdavs r6!, {r1, r2, r3, r5, r8, r11, r12, sp, pc}
 *   @0x2f0f2c adcsmi r6, r3, #6488064
 *   @0x2f0f30 strhs sp, [r0, #-0xc3]
 *   @0x2f0f34 ldmvs r7!, {r0, r1, r5, sp, lr, pc}
 *   @0x2f0f38 .word 0x8000f8d6
 *   @0x2f0f3c ldrlo r6, [r0, -r6, lsr #4]
 *   @0x2f0f40 svceq #0xf1b8
 *   @0x2f0f44 .word 0xf857d0f1
 *   @0x2f0f48 strhs r9, [r0, #-0xc08]
 *   @0x2f0f4c .word 0xbc10f857
 *   @0x2f0f50 strtmi r4, [lr], -r10, lsr #13
 *   @0x2f0f54 andle r4, pc, sp, asr r5
 *   @0x2f0f58 .word 0xf899b926
 *   @0x2f0f5c .word 0xf109a000
 *   @0x2f0f60 strhs r0, [r0], r1, lsl #18
 *   @0x2f0f64 svceq #0xaea16
 *   @0x2f0f68 strtmi sp, [r0], -r3
 *   @0x2f0f6c .word 0xf7ff4629
 *   @0x2f0f70 rsbsne pc, r6, r3, asr #17
 *   @0x2f0f74 strb r3, [sp, r1, lsl #10]!
 *   @0x2f0f78 ldmlo pc!, {r3, r8, r12, sp, lr, pc} ^
 *   @0x2f0f7c adcsmi lr, r5, #58458112
 *   @0x2f0f80 qadd8mi sp, r9, r11
 *   @0x2f0f84 .word 0xf7ff4620
 *   @0x2f0f88 strlo pc, [r1, #-0x8b7]
 *   @0x2f0f8c push {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2f0f90 stmdbhs r1, {r0, r1, r4, r5, r6, r7, r8, lr}
 *   @0x2f0f94 .word 0x2101bf28
 *   @0x2f0f98 stmdaeq r4!, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f0f9c streq pc, [r8], #-259
 *   @0x2f0fa0 stmdaeq r1, {r3, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2f0fa4 ldrmi r4, [r5], -r6, lsl #12
 *   @0x2f0fa8 .word 0xf1082700
 *   @0x2f0fac stchs p8, c0, [r0, #-64]
 *   @0x2f0fb0 strls sp, [r0, -r12, lsl #26]
 *   @0x2f0fb4 ldmdb r4, {r6, r9, r10, lr}
 *   @0x2f0fb8 strlo r0, [r8], #-6
 *   @0x2f0fbc .word 0xf7ff6833
 *   @0x2f0fc0 .word 0xb108fc06
 *   @0x2f0fc4 and r6, r1, r0, ror r0
 *   @0x2f0fc8 ldrb r3, [r0, r1, lsl #26]!
 *   @0x2f0fcc pop {r1, r12, sp, pc}
 *   @0x2f0fd0 push {r4, r5, r6, r7, r8, pc}
 *   @0x2f0fd4 .word 0xb0a34ff0
 *   @0x2f0fd8 strmi r10, [r0], r2, lsl #28
 *   @0x2f0fdc ldrmi r4, [r5], -r9, lsl #13
 *   @0x2f0fe0 .word 0x2700469a
 *   @0x2f0fe4 stcle p13, c2, [lr, #-0]!
 *   @0x2f0fe8 svclt #0xb42d10
 *   @0x2f0fec .word 0xf04f46ab
 *   @0x2f0ff0 strhs r0, [r0], #-2832
 *   @0x2f0ff4 movteq lr, #0xba4f
 *   @0x2f0ff8 eorhs pc, r4, r10, asr r8
 *   @0x2f0ffc ldrmi r9, [r7], #-769
 *   @0x2f1000 .word 0xf7f34638
 *   @0x2f1004 strne pc, [r0], #-3723
 *   @0x2f1008 eoreq pc, r4, r6, asr #16
 *   @0x2f100c strlo r9, [r1], #-2817
 *   @0x2f1010 blle 0xfff41a88 <b2_toiTime+0xffffffffff7e85e4>
 *   @0x2f1014 andhs r4, r0, r4, lsr r6
 *   @0x2f1018 stmdavs r1!, {r1, r12, sp} ^
 *   @0x2f101c addsmi r6, r8, #2228224
 *   @0x2f1020 streq pc, [r8], #-260
 *   @0x2f1024 andeq lr, r1, #198656
 *   @0x2f1028 .word 0x2c04f844
 *   @0x2f102c .word 0xf8d8dbf4
 *   @0x2f1030 stmdblt r11!, {r2, r12, sp}
 *   @0x2f1034 strbmi r4, [r9], -r0, asr #12
 *   @0x2f1038 shsaxmi r4, r3, r10
 *   @0x2f103c .word 0xffa7f7ff
 *   @0x2f1040 streq lr, [r5, #-0xbcb]
 *   @0x2f1044 eorlt lr, r3, lr, asr #15
 *   @0x2f1048 svchi #0xf0e8bd
 *   @0x2f104c svcmi #0xf0e92d
 *   @0x2f1050 stmdavs r7, {r2, r9, r10, lr} ^
 *   @0x2f1054 svchs #0xb087
 *   @0x2f1058 stmvs r3, {r4, r5, r6, r8, r12, lr, pc} ^
 *   @0x2f105c blhs 0x34b078
 *   @0x2f1060 stmdbhs r1, {r1, r3, r5, r6, r8, r12, lr, pc}
 *   @0x2f1064 .word 0x2101bf28
 *   @0x2f1068 .word 0xf1022624
 *   @0x2f106c .word 0xf10d0808
 *   @0x2f1070 blx 0x4734aa <g_RomDisk+0x7bc8a>
 *   @0x2f1074 ldrlo r0, [r0], -r1, lsl #12
 *   @0x2f1078 .word 0x0c08f858
 *   @0x2f107c mcr2 p7, #0x2, pc, c14, c3, #0x7
 *   @0x2f1080 .word 0xf8584682
 *   @0x2f1084 .word 0xf7f30c04
 *   @0x2f1088 bl 0x4f09b4 <SrcVerts+0x4d9f8>
 *   @0x2f108c b 0x16b1cb8 <b2_toiTime+0xf58814>
 *   @0x2f1090 movwls r4, #0x12a
 *   @0x2f1094 strne r4, [r2], #-1579
 *   @0x2f1098 .word 0xf7ff4630
 *   @0x2f109c stmdahs r0, {r3, r4, r7, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2f10a0 strlo sp, [r4, -r11, asr #2]
 *   @0x2f10a4 stmdaeq r8, {r3, r8, r12, sp, lr, pc}
 *   @0x2f10a8 mvnle r2, r12, lsl #30
 *   @0x2f10ac stmdaeq r12, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x2f10b0 .word 0xf8d66a33
 *   @0x2f10b4 ldm r8, {r3, r4, r12, sp, pc}
 *   @0x2f10b8 movwls r0, #0x2700
 *   @0x2f10bc svceq #0xf1bb
 *   @0x2f10c0 svcls #0x2d014
 *   @0x2f10c4 ldrtmi r4, [r8], -r1, asr #12
 *   @0x2f10c8 mrc2 p7, #0x0, apsr_nzcv, c10, c15, #0x7
 *   @0x2f10cc ldrtmi r11, [r8], -r8, lsr #19
 *   @0x2f10d0 .word 0xf7ff4649
 *   @0x2f10d4 stmiblt r0, {r0, r2, r4, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f10d8 uasxmi r4, r1, r8
 *   @0x2f10dc mrc2 p7, #0x0, apsr_nzcv, c0, c15, #0x7
 *   @0x2f10e0 .word 0x3710b958
 *   @0x2f10e4 bllo 0x2ed518 <FT_Done_Memory+0x38a4>
 *   @0x2f10e8 strb r9, [r7, r2, lsl #14]!
 *   @0x2f10ec andseq pc, r8, r6, lsl #2
 *   @0x2f10f0 bge 0x38299c <_ZTS13C_UTF16String+0x19a48>
 *   @0x2f10f4 blx 0x42f0fa <g_RomDisk+0x378da>
 *   @0x2f10f8 .word 0xf1b8b9e0
 *   @0x2f10fc ble 0x3b4d04 <error_g0017+0xd9a8>
 *   @0x2f1100 svceq #0xf1b9
 *   @0x2f1104 and sp, sp, r8, lsl #20
 *   @0x2f1108 strbmi r9, [r1], -r2, lsl #16
 *   @0x2f110c .word 0xf7ff462a
 *   @0x2f1110 stmdahs r0, {r1, r2, r6, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2f1114 strd sp, lr, [sp], -r4
 *   @0x2f1118 strbmi r9, [r9], -r2, lsl #16
 *   @0x2f111c .word 0xf7ff462a
 *   @0x2f1120 ldmdblt r8!, {r1, r2, r3, r4, r5, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2f1124 svceq #0xf1ba
 *   @0x2f1128 stmdals r2, {r3, r8, r9, r11, r12, lr, pc}
 *   @0x2f112c qsaxmi r4, r10, r1
 *   @0x2f1130 blx 0x106f136 <b2_toiTime+0x915c92>
 *   @0x2f1134 and r11, r1, r8, lsl #18
 *   @0x2f1138 rsbvs r2, r0, r6
 *   @0x2f113c pop {r0, r1, r2, r12, sp, pc}
 *
 * ══ §4/31 CFontGM::Draw_String(float, float, unsigned short*, unsigned int, float)  0xf7eec  size 1056  264 条（0xf7eec..0xf830c）
 * @func 0xf7eec 0xf830c  size 1056  264 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xf8008→0x48ffec, 0xf8048→0x483678, 0xf8128→0x4859ac, 0xf82e4→0x48ffec
 * 调用序列: CFontGM::Draw_String(float, float, unsigned short*, unsigned int, float)+0x48×2 / CFontGM::GetGlyph(int)×2 / yywcslen(unsigned short const*) / CFontGM::Draw_String(float, float, unsigned short*, unsigned int, float)+0x110 / Sprite_Exists(int) / Sprite_Data(int) / CSprite::Draw(int, float, float, float, float, float, unsigned int, float) / Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0x20×6 / 0x1c×4 / 0x24×4 / 0x3c×3 / 0x58×2 / 0x8×2 / 0x4×2 / 0xc×2
 * VFP 指令 110 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf7eec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf7ef0 vpush {d8}
 *   @0xf7ef4 mov r6, r0
 *   @0xf7ef8 sub sp, sp, #44
 *   @0xf7efc mov r0, r3
 *   @0xf7f00 mov r5, r3
 *   @0xf7f04 vmov s16, r1
 *   @0xf7f08 vmov s17, r2
 *   @0xf7f0c bl 0xf6c78 <_Z8yywcslenPKt>
 *   @0xf7f10 ldr r9, [pc, #0x3e4]
 *   @0xf7f14 add r9, pc, r9
 *   @0xf7f18 mov r4, r0
 *   @0xf7f1c ldr r0, [r6, #0x20]
 *   @0xf7f20 cmp r0, #0
 *   @0xf7f24 blt 0xf7ffc <_ZN7CFontGM11Draw_StringEffPtjf+0x110>
 *   @0xf7f28 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0xf7f2c cmp r0, #0
 *   @0xf7f30 bne 0xf7f40 <_ZN7CFontGM11Draw_StringEffPtjf+0x54>
 *   @0xf7f34 add sp, sp, #44
 *   @0xf7f38 vpop {d8}
 *   @0xf7f3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf7f40 ldr r0, [r6, #0x20]
 *   @0xf7f44 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0xf7f48 cmp r4, #0
 *   @0xf7f4c mov r10, r0
 *   @0xf7f50 ble 0xf7f34 <_ZN7CFontGM11Draw_StringEffPtjf+0x48>
 *   @0xf7f54 lsl r8, r4, #1
 *   @0xf7f58 mov r11, #0
 *   @0xf7f5c mov r4, #0
 *   @0xf7f60 b 0xf7f70 <_ZN7CFontGM11Draw_StringEffPtjf+0x84>
 *   @0xf7f64 add r4, r4, #2
 *   @0xf7f68 cmp r4, r8
 *   @0xf7f6c beq 0xf7f34 <_ZN7CFontGM11Draw_StringEffPtjf+0x48>
 *   @0xf7f70 ldrh r7, [r5, r4]
 *   @0xf7f74 cmp r7, #0
 *   @0xf7f78 beq 0xf7f64 <_ZN7CFontGM11Draw_StringEffPtjf+0x78>
 *   @0xf7f7c mov r0, r6
 *   @0xf7f80 mov r1, r7
 *   @0xf7f84 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi>
 *   @0xf7f88 vmov r3, s17
 *   @0xf7f8c subs r9, r0, #0
 *   @0xf7f90 mov r0, r10
 *   @0xf7f94 beq 0xf7f64 <_ZN7CFontGM11Draw_StringEffPtjf+0x78>
 *   @0xf7f98 cmp r7, #32
 *   @0xf7f9c beq 0xf7fe4 <_ZN7CFontGM11Draw_StringEffPtjf+0xf8>
 *   @0xf7fa0 ldrsh r2, [r9, #12]
 *   @0xf7fa4 vldr s15, [r6, #72]
 *   @0xf7fa8 ldrsh r1, [r9, #6]
 *   @0xf7fac vldr s13, [sp, #92]
 *   @0xf7fb0 ldr r12, [sp, #0x58]
 *   @0xf7fb4 vmov s14, r2
 *   @0xf7fb8 ldr r2, [r6, #0x4c]
 *   @0xf7fbc vstr s13, [sp, #16]
 *   @0xf7fc0 vmov.f32 s13, s16
 *   @0xf7fc4 vstr s15, [sp]
 *   @0xf7fc8 str r11, [sp, #0x8]
 *   @0xf7fcc str r2, [sp, #0x4]
 *   @0xf7fd0 str r12, [sp, #0xc]
 *   @0xf7fd4 vcvt.f32.s32 s14, s14
 *   @0xf7fd8 vmla.f32 s13, s14, s15
 *   @0xf7fdc vmov r2, s13
 *   @0xf7fe0 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf>
 *   @0xf7fe4 ldrsh r9, [r9, #10]
 *   @0xf7fe8 vldr s15, [r6, #72]
 *   @0xf7fec vmov s14, r9
 *   @0xf7ff0 vcvt.f32.s32 s14, s14
 *   @0xf7ff4 vmla.f32 s16, s14, s15
 *   @0xf7ff8 b 0xf7f64 <_ZN7CFontGM11Draw_StringEffPtjf+0x78>
 *   @0xf7ffc ldr r8, [r6, #0x3c]
 *   @0xf8000 cmp r8, #0
 *   @0xf8004 beq 0xf82dc <_ZN7CFontGM11Draw_StringEffPtjf+0x3f0>
 *   @0xf8008 ldr r3, [pc, #0x2f0]
 *   @0xf800c ldrsh r2, [r8, #20]
 *   @0xf8010 ldr r3, [r9, r3]
 *   @0xf8014 ldr r3, [r3, #0x4]
 *   @0xf8018 ldr r8, [r3, r2, lsl #2]
 *   @0xf801c vldr s15, [pc, #724]
 *   @0xf8020 vldr s14, [sp, #92]
 *   @0xf8024 vmul.f32 s15, s14, s15
 *   @0xf8028 vcvt.s32.f32 s15, s15
 *   @0xf802c vmov r10, s15
 *   @0xf8030 cmp r10, #255
 *   @0xf8034 movgt r10, #-16777216
 *   @0xf8038 bgt 0xf8048 <_ZN7CFontGM11Draw_StringEffPtjf+0x15c>
 *   @0xf803c cmp r10, #0
 *   @0xf8040 lslge r10, r10, #24
 *   @0xf8044 movlt r10, #0
 *   @0xf8048 ldr r3, [pc, #0x2b4]
 *   @0xf804c ldr r2, [sp, #0x58]
 *   @0xf8050 ldr r3, [r9, r3]
 *   @0xf8054 orr r10, r10, r2
 *   @0xf8058 ldrb r3, [r3]
 *   @0xf805c cmp r3, #0
 *   @0xf8060 beq 0xf8278 <_ZN7CFontGM11Draw_StringEffPtjf+0x38c>
 *   @0xf8064 bic r10, r10, #65536
 *   @0xf8068 bic r10, r10, #1
 *   @0xf806c orr r12, r10, #65536
 *   @0xf8070 str r12, [sp, #0x1c]
 *   @0xf8074 orr r12, r10, #1
 *   @0xf8078 str r12, [sp, #0x20]
 *   @0xf807c ldr r12, [sp, #0x1c]
 *   @0xf8080 orr r12, r12, #1
 *   @0xf8084 str r12, [sp, #0x24]
 *   @0xf8088 cmp r4, #0
 *   @0xf808c ble 0xf7f34 <_ZN7CFontGM11Draw_StringEffPtjf+0x48>
 *   @0xf8090 lsl r11, r4, #1
 *   @0xf8094 mov r3, r9
 *   @0xf8098 mov r4, #0
 *   @0xf809c mov r9, r11
 *   @0xf80a0 mov r11, r3
 *   @0xf80a4 b 0xf80b4 <_ZN7CFontGM11Draw_StringEffPtjf+0x1c8>
 *   @0xf80a8 add r4, r4, #2
 *   @0xf80ac cmp r4, r9
 *   @0xf80b0 beq 0xf7f34 <_ZN7CFontGM11Draw_StringEffPtjf+0x48>
 *   @0xf80b4 ldrh r1, [r5, r4]
 *   @0xf80b8 cmp r1, #0
 *   @0xf80bc beq 0xf80a8 <_ZN7CFontGM11Draw_StringEffPtjf+0x1bc>
 *   @0xf80c0 mov r0, r6
 *   @0xf80c4 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi>
 *   @0xf80c8 cmp r0, #0
 *   @0xf80cc cmpne r8, #0
 *   @0xf80d0 mov r7, r0
 *   @0xf80d4 beq 0xf80a8 <_ZN7CFontGM11Draw_StringEffPtjf+0x1bc>
 *   @0xf80d8 mov r0, #4
 *   @0xf80dc ldr r1, [r8]
 *   @0xf80e0 mov r2, #24
 *   @0xf80e4 mov r3, #6
 *   @0xf80e8 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0xf80ec cmp r0, #0
 *   @0xf80f0 beq 0xf7f34 <_ZN7CFontGM11Draw_StringEffPtjf+0x48>
 *   @0xf80f4 ldrsh r2, [r7, #12]
 *   @0xf80f8 vmov.f32 s13, s16
 *   @0xf80fc vldr s12, [r6, #72]
 *   @0xf8100 ldrsh r3, [r7, #6]
 *   @0xf8104 ldrsh r12, [r7, #8]
 *   @0xf8108 vldr s15, [r6, #80]
 *   @0xf810c vmov s11, r2
 *   @0xf8110 vldr s8, [r6, #76]
 *   @0xf8114 vadd.f32 s14, s17, s15
 *   @0xf8118 ldr r2, [r6, #0x3c]
 *   @0xf811c vmov s9, r3
 *   @0xf8120 ldrsh r1, [r7, #2]
 *   @0xf8124 vmov s10, r12
 *   @0xf8128 ldr r3, [pc, #0x1d8]
 *   @0xf812c ldrsh r12, [r7, #4]
 *   @0xf8130 cmp r2, #0
 *   @0xf8134 vcvt.f32.s32 s11, s11
 *   @0xf8138 vmla.f32 s13, s11, s12
 *   @0xf813c vmov.f32 s11, s13
 *   @0xf8140 vadd.f32 s13, s13, s15
 *   @0xf8144 vcvt.f32.s32 s9, s9
 *   @0xf8148 vcvt.f32.s32 s10, s10
 *   @0xf814c vmla.f32 s13, s12, s9
 *   @0xf8150 vmla.f32 s14, s10, s8
 *   @0xf8154 vstr s13, [r0, #24]
 *   @0xf8158 vstr s13, [r0, #48]
 *   @0xf815c vstr s13, [r0, #72]
 *   @0xf8160 vmov s8, r12
 *   @0xf8164 ldr r12, [sp, #0x20]
 *   @0xf8168 vsub.f32 s13, s11, s15
 *   @0xf816c vstr s14, [r0, #52]
 *   @0xf8170 vstr s14, [r0, #76]
 *   @0xf8174 vstr s14, [r0, #100]
 *   @0xf8178 vsub.f32 s14, s17, s15
 *   @0xf817c vstr s13, [r0]
 *   @0xf8180 vstr s13, [r0, #96]
 *   @0xf8184 vstr s13, [r0, #120]
 *   @0xf8188 vmov s13, r1
 *   @0xf818c vstr s14, [r0, #4]
 *   @0xf8190 vstr s14, [r0, #28]
 *   @0xf8194 vstr s14, [r0, #124]
 *   @0xf8198 vcvt.f32.s32 s11, s13
 *   @0xf819c ldr r3, [r11, r3]
 *   @0xf81a0 str r12, [r0, #0x24]
 *   @0xf81a4 ldr r12, [sp, #0x1c]
 *   @0xf81a8 ldr r3, [r3]
 *   @0xf81ac str r10, [r0, #0xc]
 *   @0xf81b0 str r10, [r0, #0x84]
 *   @0xf81b4 str r3, [r0, #0x80]
 *   @0xf81b8 vcvt.f32.s32 s14, s8
 *   @0xf81bc str r3, [r0, #0x68]
 *   @0xf81c0 str r3, [r0, #0x50]
 *   @0xf81c4 str r3, [r0, #0x38]
 *   @0xf81c8 str r3, [r0, #0x20]
 *   @0xf81cc str r3, [r0, #0x8]
 *   @0xf81d0 str r12, [r0, #0x3c]
 *   @0xf81d4 str r12, [r0, #0x54]
 *   @0xf81d8 ldr r12, [sp, #0x24]
 *   @0xf81dc str r12, [r0, #0x6c]
 *   @0xf81e0 beq 0xf8288 <_ZN7CFontGM11Draw_StringEffPtjf+0x39c>
 *   @0xf81e4 ldrsh r3, [r2]
 *   @0xf81e8 vldr s8, [r8, #8]
 *   @0xf81ec vmov s13, r3
 *   @0xf81f0 vcvt.f32.s32 s13, s13
 *   @0xf81f4 vadd.f32 s13, s13, s11
 *   @0xf81f8 vsub.f32 s11, s13, s15
 *   @0xf81fc vmul.f32 s11, s11, s8
 *   @0xf8200 vstr s11, [r0, #16]
 *   @0xf8204 vstr s11, [r0, #112]
 *   @0xf8208 vstr s11, [r0, #136]
 *   @0xf820c ldrsh r2, [r2, #2]
 *   @0xf8210 vadd.f32 s13, s9, s13
 *   @0xf8214 vldr s11, [r8, #12]
 *   @0xf8218 vmov s7, r2
 *   @0xf821c vcvt.f32.s32 s7, s7
 *   @0xf8220 vadd.f32 s7, s7, s14
 *   @0xf8224 vadd.f32 s14, s10, s7
 *   @0xf8228 vadd.f32 s13, s15, s13
 *   @0xf822c vadd.f32 s14, s15, s14
 *   @0xf8230 vsub.f32 s15, s7, s15
 *   @0xf8234 vmul.f32 s13, s8, s13
 *   @0xf8238 vmul.f32 s14, s11, s14
 *   @0xf823c vstr s13, [r0, #40]
 *   @0xf8240 vstr s13, [r0, #88]
 *   @0xf8244 vstr s13, [r0, #64]
 *   @0xf8248 vmul.f32 s15, s15, s11
 *   @0xf824c vstr s14, [r0, #68]
 *   @0xf8250 vstr s14, [r0, #92]
 *   @0xf8254 vstr s14, [r0, #116]
 *   @0xf8258 vstr s15, [r0, #20]
 *   @0xf825c vstr s15, [r0, #44]
 *   @0xf8260 vstr s15, [r0, #140]
 *   @0xf8264 ldrsh r7, [r7, #10]
 *   @0xf8268 vmov s15, r7
 *   @0xf826c vcvt.f32.s32 s15, s15
 *   @0xf8270 vmla.f32 s16, s12, s15
 *   @0xf8274 b 0xf80a8 <_ZN7CFontGM11Draw_StringEffPtjf+0x1bc>
 *   @0xf8278 str r10, [sp, #0x24]
 *   @0xf827c str r10, [sp, #0x1c]
 *   @0xf8280 str r10, [sp, #0x20]
 *   @0xf8284 b 0xf8088 <_ZN7CFontGM11Draw_StringEffPtjf+0x19c>
 *   @0xf8288 vldr s13, [r8, #8]
 *   @0xf828c vmul.f32 s15, s13, s11
 *   @0xf8290 vadd.f32 s10, s14, s10
 *   @0xf8294 vstr s15, [r0, #16]
 *   @0xf8298 vstr s15, [r0, #112]
 *   @0xf829c vstr s15, [r0, #136]
 *   @0xf82a0 vldr s15, [r8, #12]
 *   @0xf82a4 vadd.f32 s11, s11, s9
 *   @0xf82a8 vmul.f32 s14, s15, s14
 *   @0xf82ac vmul.f32 s13, s13, s11
 *   @0xf82b0 vstr s14, [r0, #20]
 *   @0xf82b4 vstr s14, [r0, #44]
 *   @0xf82b8 vstr s14, [r0, #140]
 *   @0xf82bc vmul.f32 s15, s15, s10
 *   @0xf82c0 vstr s13, [r0, #40]
 *   @0xf82c4 vstr s13, [r0, #64]
 *   @0xf82c8 vstr s13, [r0, #88]
 *   @0xf82cc vstr s15, [r0, #68]
 *   @0xf82d0 vstr s15, [r0, #92]
 *   @0xf82d4 vstr s15, [r0, #116]
 *   @0xf82d8 b 0xf8264 <_ZN7CFontGM11Draw_StringEffPtjf+0x378>
 *   @0xf82dc ldr r3, [r6, #0x38]
 *   @0xf82e0 cmp r3, #0
 *   @0xf82e4 ldrge r2, [pc, #0x14]
 *   @0xf82e8 ldrge r2, [r9, r2]
 *   @0xf82ec ldrge r2, [r2, #0x4]
 *   @0xf82f0 ldrge r8, [r2, r3, lsl #2]
 *   @0xf82f4 b 0xf801c <_ZN7CFontGM11Draw_StringEffPtjf+0x130>
 *   @0xf82f8 cmnmi pc, #0
 *   @0xf82fc eoreq r9, pc, r12, lsr sp
 *   @0xf8300 .word 0xffffbccc
 *   @0xf8304 .word 0xffffc1fc
 *   @0xf8308 .word 0xffffbcd0
 *
 * ══ §5/31 CFontGM::CFontGM(int, char const*, bool, int)  0xf7270  size 1052  263 条（0xf7270..0xf768c）
 * @func 0xf7270 0xf768c  size 1052  263 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CFontGM::Clear() / Sprite_Exists(int) / Sprite_Data(int) / utf8_strlen / CFontGM::CFontGM(int, char const*, bool, int)+0x3d8 / utf8_extract_char / MemoryManager::Alloc(unsigned int, char const*, int, bool) / CFontGM::CFontGM(int, char const*, bool, int)+0x394
 * 字段偏移 top8: 0x4×7 / 0x-50×7 / 0x-48×6 / 0x18×5 / 0x40×5 / 0x-4c×4 / 0x20×4 / 0x44×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf7270 ldr r12, [pc, #0x404]
 *   @0xf7274 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf7278 add r11, sp, #32
 *   @0xf727c sub sp, sp, #68
 *   @0xf7280 mov r5, #0
 *   @0xf7284 str r12, [r11, #-0x4c]
 *   @0xf7288 ldr lr, [r11, #-0x4c]
 *   @0xf728c mov r7, r1
 *   @0xf7290 ldr r12, [pc, #0x3e8]
 *   @0xf7294 mvn r1, #0
 *   @0xf7298 ldr lr, [pc, lr]
 *   @0xf729c str lr, [r11, #-0x4c]
 *   @0xf72a0 ldr r12, [pc, r12]
 *   @0xf72a4 str r1, [r0, #0x20]
 *   @0xf72a8 ldr lr, [lr]
 *   @0xf72ac add r12, r12, #8
 *   @0xf72b0 str r1, [r0, #0x38]
 *   @0xf72b4 mov r8, #1056964608
 *   @0xf72b8 str r12, [r0]
 *   @0xf72bc mov r6, r2
 *   @0xf72c0 str lr, [r11, #-0x28]
 *   @0xf72c4 mov r4, r0
 *   @0xf72c8 str r3, [r11, #-0x58]
 *   @0xf72cc mov r3, #1065353216
 *   @0xf72d0 str r5, [r0, #0x4]
 *   @0xf72d4 str r3, [r0, #0x48]
 *   @0xf72d8 str r3, [r0, #0x4c]
 *   @0xf72dc str r8, [r0, #0x50]
 *   @0xf72e0 str r5, [r0, #0x8]
 *   @0xf72e4 strb r5, [r0, #0xc]
 *   @0xf72e8 strb r5, [r0, #0xd]
 *   @0xf72ec str r5, [r0, #0x18]
 *   @0xf72f0 str r5, [r0, #0x1c]
 *   @0xf72f4 str r5, [r0, #0x24]
 *   @0xf72f8 str r5, [r0, #0x28]
 *   @0xf72fc str r5, [r0, #0x40]
 *   @0xf7300 str r5, [r0, #0x44]
 *   @0xf7304 str r5, [r0, #0x5c]
 *   @0xf7308 str r5, [r0, #0x60]
 *   @0xf730c str r5, [r0, #0x64]
 *   @0xf7310 str r5, [r0, #0x6c]
 *   @0xf7314 str r5, [r0, #0x70]
 *   @0xf7318 str r5, [r0, #0x74]
 *   @0xf731c str r5, [r0, #0x78]
 *   @0xf7320 str r5, [r0, #0x7c]
 *   @0xf7324 str r5, [r0, #0x80]
 *   @0xf7328 str r5, [r0, #0x84]
 *   @0xf732c str r5, [r0, #0x88]
 *   @0xf7330 str r5, [r0, #0x3c]
 *   @0xf7334 str r5, [r0, #0x34]
 *   @0xf7338 str r5, [r0, #0x30]
 *   @0xf733c str r5, [r0, #0x54]
 *   @0xf7340 str r5, [r0, #0x8c]
 *   @0xf7344 bl 0xf70a0 <_ZN7CFontGM5ClearEv>
 *   @0xf7348 mov r0, r7
 *   @0xf734c bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0xf7350 cmp r0, r5
 *   @0xf7354 bne 0xf7378 <_ZN7CFontGMC2EiPKcbi+0x108>
 *   @0xf7358 ldr r12, [r11, #-0x4c]
 *   @0xf735c mov r0, r4
 *   @0xf7360 ldr r2, [r11, #-0x28]
 *   @0xf7364 ldr r3, [r12]
 *   @0xf7368 cmp r2, r3
 *   @0xf736c bne 0xf7678 <_ZN7CFontGMC2EiPKcbi+0x408>
 *   @0xf7370 sub sp, r11, #32
 *   @0xf7374 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf7378 mov r0, r7
 *   @0xf737c bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0xf7380 str r7, [r4, #0x20]
 *   @0xf7384 mov r8, r0
 *   @0xf7388 mov r0, r6
 *   @0xf738c bl 0x110648 <utf8_strlen>
 *   @0xf7390 str r6, [r11, #-0x3c]
 *   @0xf7394 lsl r3, r0, #2
 *   @0xf7398 cmp r0, r5
 *   @0xf739c add r3, r3, #22
 *   @0xf73a0 mov r7, r0
 *   @0xf73a4 bic r3, r3, #7
 *   @0xf73a8 sub sp, sp, r3
 *   @0xf73ac str sp, [r11, #-0x48]
 *   @0xf73b0 ble 0xf7648 <_ZN7CFontGMC2EiPKcbi+0x3d8>
 *   @0xf73b4 sub r6, sp, #4
 *   @0xf73b8 sub r9, r11, #60
 *   @0xf73bc mov r10, r5
 *   @0xf73c0 mov r0, r9
 *   @0xf73c4 add r10, r10, #1
 *   @0xf73c8 bl 0x10fb38 <utf8_extract_char>
 *   @0xf73cc cmp r0, #32
 *   @0xf73d0 str r0, [r6, #0x4]!
 *   @0xf73d4 moveq r5, #1
 *   @0xf73d8 cmp r10, r7
 *   @0xf73dc bne 0xf73c0 <_ZN7CFontGMC2EiPKcbi+0x150>
 *   @0xf73e0 ldr r3, [r8, #0x18]
 *   @0xf73e4 cmp r3, r10
 *   @0xf73e8 movge r3, r10
 *   @0xf73ec cmp r5, #0
 *   @0xf73f0 str r3, [r11, #-0x50]
 *   @0xf73f4 movne r12, #0
 *   @0xf73f8 strne r12, [r11, #-0x60]
 *   @0xf73fc beq 0xf7654 <_ZN7CFontGMC2EiPKcbi+0x3e4>
 *   @0xf7400 ldr r12, [r11, #-0x50]
 *   @0xf7404 movw r2, #0x16d
 *   @0xf7408 ldr r1, [pc, #0x274]
 *   @0xf740c mov r3, #1
 *   @0xf7410 add r0, r12, r12, lsl #2
 *   @0xf7414 str r12, [r4, #0x40]
 *   @0xf7418 add r1, pc, r1
 *   @0xf741c lsl r0, r0, #2
 *   @0xf7420 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xf7424 ldr r12, [r11, #-0x50]
 *   @0xf7428 ldr r1, [r4, #0x40]
 *   @0xf742c cmp r12, #0
 *   @0xf7430 str r0, [r4, #0x44]
 *   @0xf7434 add r5, r0, r1, lsl #2
 *   @0xf7438 ble 0xf7604 <_ZN7CFontGMC2EiPKcbi+0x394>
 *   @0xf743c ldr lr, [r11, #-0x48]
 *   @0xf7440 mov r6, #0
 *   @0xf7444 ldr r2, [r11, #0x4]
 *   @0xf7448 sub r0, r0, #4
 *   @0xf744c sub r12, lr, #4
 *   @0xf7450 movw r1, #0xfc19
 *   @0xf7454 sub r3, r11, #56
 *   @0xf7458 movt r1, #0xffff
 *   @0xf745c uxth r2, r2
 *   @0xf7460 str r4, [r11, #-0x40]
 *   @0xf7464 add r5, r5, #16
 *   @0xf7468 str r0, [r11, #-0x44]
 *   @0xf746c str r2, [r11, #-0x54]
 *   @0xf7470 mov r10, r6
 *   @0xf7474 str r1, [r11, #-0x48]
 *   @0xf7478 mov r9, r6
 *   @0xf747c str r3, [r11, #-0x5c]
 *   @0xf7480 mov r4, r12
 *   @0xf7484 b 0xf7588 <_ZN7CFontGMC2EiPKcbi+0x318>
 *   @0xf7488 ldr r12, [r11, #-0x58]
 *   @0xf748c cmp r12, #0
 *   @0xf7490 beq 0xf75b4 <_ZN7CFontGMC2EiPKcbi+0x344>
 *   @0xf7494 ldr r3, [r8, #0x54]
 *   @0xf7498 cmp r3, #0
 *   @0xf749c beq 0xf7634 <_ZN7CFontGMC2EiPKcbi+0x3c4>
 *   @0xf74a0 mov r0, #16
 *   @0xf74a4 str r2, [r11, #-0x64]
 *   @0xf74a8 bl 0x27c524 <_Znwj>
 *   @0xf74ac ldr r2, [r11, #-0x64]
 *   @0xf74b0 ldr r3, [r8, #0x54]
 *   @0xf74b4 ldr r3, [r3, r2]
 *   @0xf74b8 ldrsh r1, [r3, #8]
 *   @0xf74bc ldrsh r2, [r3, #10]
 *   @0xf74c0 mov r12, r0
 *   @0xf74c4 ldrsh r0, [r3, #12]
 *   @0xf74c8 ldrsh r3, [r3, #14]
 *   @0xf74cc str r1, [r12]
 *   @0xf74d0 add r1, r1, r0
 *   @0xf74d4 add r3, r2, r3
 *   @0xf74d8 str r1, [r12, #0x8]
 *   @0xf74dc str r3, [r12, #0xc]
 *   @0xf74e0 str r2, [r12, #0x4]
 *   @0xf74e4 ldr r0, [r12]
 *   @0xf74e8 sub lr, r11, #56
 *   @0xf74ec ldr r1, [r12, #0x4]
 *   @0xf74f0 ldr r2, [r12, #0x8]
 *   @0xf74f4 ldr r3, [r12, #0xc]
 *   @0xf74f8 stm lr!, {r0, r1, r2, r3}
 *   @0xf74fc mov r0, r12
 *   @0xf7500 bl 0x27d1d0 <_ZdlPv>
 *   @0xf7504 ldrh r1, [r11, #-56]
 *   @0xf7508 ldr r3, [r8, #0x20]
 *   @0xf750c rsb r2, r1, #0
 *   @0xf7510 ldr r0, [r11, #-0x30]
 *   @0xf7514 uxth r2, r2
 *   @0xf7518 ldr lr, [r11, #-0x40]
 *   @0xf751c uxth r3, r3
 *   @0xf7520 rsb r1, r1, r0
 *   @0xf7524 ldr r12, [lr, #0x2c]
 *   @0xf7528 strh r3, [r5, #-8]
 *   @0xf752c sxth r3, r3
 *   @0xf7530 cmp r3, r12
 *   @0xf7534 ldr r12, [r11, #-0x54]
 *   @0xf7538 strh r7, [r5, #-16]
 *   @0xf753c strh r6, [r5, #-10]
 *   @0xf7540 add r1, r12, r1
 *   @0xf7544 strgt r3, [lr, #0x2c]
 *   @0xf7548 cmp r7, #32
 *   @0xf754c uxth r1, r1
 *   @0xf7550 strh r2, [r5, #-4]
 *   @0xf7554 strh r9, [r5, #-2]
 *   @0xf7558 strh r1, [r5, #-6]
 *   @0xf755c beq 0xf7574 <_ZN7CFontGMC2EiPKcbi+0x304>
 *   @0xf7560 ldr r12, [r11, #-0x48]
 *   @0xf7564 sxth r1, r1
 *   @0xf7568 cmp r12, r1
 *   @0xf756c movlt r12, r1
 *   @0xf7570 str r12, [r11, #-0x48]
 *   @0xf7574 ldr r12, [r11, #-0x50]
 *   @0xf7578 add r6, r6, #1
 *   @0xf757c add r5, r5, #16
 *   @0xf7580 cmp r6, r12
 *   @0xf7584 beq 0xf75dc <_ZN7CFontGMC2EiPKcbi+0x36c>
 *   @0xf7588 ldr r7, [r4, #0x4]!
 *   @0xf758c sub r3, r5, #16
 *   @0xf7590 ldr r12, [r11, #-0x44]
 *   @0xf7594 lsl r2, r6, #2
 *   @0xf7598 cmp r7, #32
 *   @0xf759c str r3, [r12, #0x4]!
 *   @0xf75a0 moveq r10, r3
 *   @0xf75a4 ldr r3, [r8, #0x18]
 *   @0xf75a8 str r12, [r11, #-0x44]
 *   @0xf75ac cmp r3, r6
 *   @0xf75b0 bgt 0xf7488 <_ZN7CFontGMC2EiPKcbi+0x218>
 *   @0xf75b4 ldr r12, [r8, #0x1c]
 *   @0xf75b8 mov r2, #0
 *   @0xf75bc ldr r3, [r8, #0x20]
 *   @0xf75c0 mov r1, r2
 *   @0xf75c4 str r9, [r11, #-0x38]
 *   @0xf75c8 str r9, [r11, #-0x34]
 *   @0xf75cc mov r0, r12
 *   @0xf75d0 str r12, [r11, #-0x30]
 *   @0xf75d4 str r3, [r11, #-0x2c]
 *   @0xf75d8 b 0xf7518 <_ZN7CFontGMC2EiPKcbi+0x2a8>
 *   @0xf75dc ldr r3, [r11, #-0x60]
 *   @0xf75e0 ldr r4, [r11, #-0x40]
 *   @0xf75e4 cmp r10, #0
 *   @0xf75e8 moveq r3, #0
 *   @0xf75ec andne r3, r3, #1
 *   @0xf75f0 cmp r3, #0
 *   @0xf75f4 ldr r0, [r4, #0x44]
 *   @0xf75f8 ldrne r12, [r11, #-0x48]
 *   @0xf75fc ldr r1, [r4, #0x40]
 *   @0xf7600 strhne r12, [r10, #10]
 *   @0xf7604 ldr r3, [pc, #0x7c]
 *   @0xf7608 mov r2, #4
 *   @0xf760c add r3, pc, r3
 *   @0xf7610 bl 0xb66dc <qsort@plt>
 *   @0xf7614 ldr r3, [r4, #0x44]
 *   @0xf7618 ldr r2, [r4, #0x40]
 *   @0xf761c ldr r3, [r3]
 *   @0xf7620 ldrh r3, [r3]
 *   @0xf7624 add r2, r3, r2
 *   @0xf7628 str r2, [r4, #0x1c]
 *   @0xf762c str r3, [r4, #0x18]
 *   @0xf7630 b 0xf7358 <_ZN7CFontGMC2EiPKcbi+0xe8>
 *   @0xf7634 mov r0, r8
 *   @0xf7638 mov r1, r6
 *   @0xf763c bl 0x1e63d4 <_ZN7CSprite17GetBoundingBoxImgEi>
 *   @0xf7640 mov r12, r0
 *   @0xf7644 b 0xf74e4 <_ZN7CFontGMC2EiPKcbi+0x274>
 *   @0xf7648 ldr r3, [r8, #0x18]
 *   @0xf764c and r3, r3, r3, asr #31
 *   @0xf7650 str r3, [r11, #-0x50]
 *   @0xf7654 mov r12, #1
 *   @0xf7658 ldr lr, [r11, #-0x48]
 *   @0xf765c str r12, [r11, #-0x60]
 *   @0xf7660 mov r3, #32
 *   @0xf7664 ldr r12, [r11, #-0x50]
 *   @0xf7668 str r3, [lr, r12, lsl #2]
 *   @0xf766c add r12, r12, #1
 *   @0xf7670 str r12, [r11, #-0x50]
 *   @0xf7674 b 0xf7400 <_ZN7CFontGMC2EiPKcbi+0x190>
 *   @0xf7678 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xf767c .word 0x002f66b8
 *   @0xf7680 eoreq r6, pc, r8, lsr #23
 *   @0xf7684 eoreq r0, r4, r12, ror #11
 *   @0xf7688 .word 0xfffff284
 *
 * ══ §6/31 DrawTile(tagYYRECT*, CBackground*, unsigned int, int, float, float, float)  0x1b1d08  size 1052  263 条（0x1b1d08..0x1b2124）
 * @func 0x1b1d08 0x1b2124  size 1052  263 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_uidivmod×2 / __udivsi3×2 / CalcLayerTilemapParams(CBackground*, RTexture**, float&, float&, float&, float&, float&, float&, float&, float&, bool&) / __aeabi_idivmod / CBackground::DrawGeneral(float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float) / Graphics::AllocVerts(ePrimType, void*, int, int)
 * 字段偏移 top8: 0x1c×3 / 0x20×3 / 0x24×3 / 0xc×2 / 0x18×2 / 0x54×2 / 0x2c×2 / 0x40×2
 * VFP 指令 145 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b1d08 cmp r0, #0
 *   @0x1b1d0c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1b1d10 vpush {d8, d9, d10, d11}
 *   @0x1b1d14 mov r4, r1
 *   @0x1b1d18 sub sp, sp, #92
 *   @0x1b1d1c mov r5, r2
 *   @0x1b1d20 mov r6, r3
 *   @0x1b1d24 beq 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0>
 *   @0x1b1d28 cmp r1, #0
 *   @0x1b1d2c beq 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0>
 *   @0x1b1d30 mov r0, r1
 *   @0x1b1d34 add r2, sp, #52
 *   @0x1b1d38 add r3, sp, #60
 *   @0x1b1d3c add r1, sp, #84
 *   @0x1b1d40 str r3, [sp]
 *   @0x1b1d44 add r3, sp, #64
 *   @0x1b1d48 str r3, [sp, #0x4]
 *   @0x1b1d4c add r3, sp, #68
 *   @0x1b1d50 str r3, [sp, #0x8]
 *   @0x1b1d54 add r3, sp, #72
 *   @0x1b1d58 str r3, [sp, #0xc]
 *   @0x1b1d5c add r3, sp, #76
 *   @0x1b1d60 str r3, [sp, #0x10]
 *   @0x1b1d64 add r3, sp, #80
 *   @0x1b1d68 str r3, [sp, #0x14]
 *   @0x1b1d6c add r3, sp, #51
 *   @0x1b1d70 str r3, [sp, #0x18]
 *   @0x1b1d74 add r3, sp, #56
 *   @0x1b1d78 bl 0x1b19c4 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb>
 *   @0x1b1d7c ldr r7, [r4, #0x30]
 *   @0x1b1d80 mov r0, r6
 *   @0x1b1d84 mov r1, r7
 *   @0x1b1d88 bl 0x318dec <__aeabi_idivmod>
 *   @0x1b1d8c ldr r2, [sp, #0x54]
 *   @0x1b1d90 cmp r2, #0
 *   @0x1b1d94 beq 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0>
 *   @0x1b1d98 ldr r3, [pc, #0x380]
 *   @0x1b1d9c ldrb r0, [sp, #0x33]
 *   @0x1b1da0 ldr r3, [pc, r3]
 *   @0x1b1da4 cmp r0, #0
 *   @0x1b1da8 ldr r3, [r3]
 *   @0x1b1dac beq 0x1b1dd4 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xcc>
 *   @0x1b1db0 ubfx r3, r5, #0x0, #0x13
 *   @0x1b1db4 ldr r9, [r4, #0x1c]
 *   @0x1b1db8 cmp r3, #0
 *   @0x1b1dbc ldr r8, [r4, #0x20]
 *   @0x1b1dc0 ldr r6, [r4, #0x2c]
 *   @0x1b1dc4 bne 0x1b1f50 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x248>
 *   @0x1b1dc8 add sp, sp, #92
 *   @0x1b1dcc vpop {d8, d9, d10, d11}
 *   @0x1b1dd0 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1b1dd4 and r5, r5, r3
 *   @0x1b1dd8 ldr r12, [r4, #0x1c]
 *   @0x1b1ddc ubfx r3, r5, #0x0, #0x13
 *   @0x1b1de0 vldr s17, [sp, #76]
 *   @0x1b1de4 cmp r3, #0
 *   @0x1b1de8 ldr r2, [r4, #0x20]
 *   @0x1b1dec vldr s16, [sp, #80]
 *   @0x1b1df0 ldr r0, [r4, #0x24]
 *   @0x1b1df4 ldr r8, [r4, #0x28]
 *   @0x1b1df8 beq 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0>
 *   @0x1b1dfc mla r7, r3, r7, r1
 *   @0x1b1e00 ldr r6, [r4, #0x40]
 *   @0x1b1e04 ldr r6, [r6, r7, lsl #2]
 *   @0x1b1e08 cmp r6, #0
 *   @0x1b1e0c beq 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0>
 *   @0x1b1e10 ldr r7, [r4, #0x2c]
 *   @0x1b1e14 vmov s10, r0
 *   @0x1b1e18 vmov s12, r8
 *   @0x1b1e1c mov r0, r6
 *   @0x1b1e20 vmov s13, r12
 *   @0x1b1e24 vmov s15, r2
 *   @0x1b1e28 mov r1, r7
 *   @0x1b1e2c vcvt.f32.s32 s22, s13
 *   @0x1b1e30 vcvt.f32.s32 s19, s10
 *   @0x1b1e34 vcvt.f32.s32 s18, s12
 *   @0x1b1e38 vcvt.f32.s32 s21, s15
 *   @0x1b1e3c bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x1b1e40 mov r0, r6
 *   @0x1b1e44 vmul.f32 s19, s17, s19
 *   @0x1b1e48 vmul.f32 s20, s22, s17
 *   @0x1b1e4c vadd.f32 s15, s19, s19
 *   @0x1b1e50 vmov s5, r1
 *   @0x1b1e54 mov r1, r7
 *   @0x1b1e58 vadd.f32 s15, s15, s20
 *   @0x1b1e5c vcvt.f32.u32 s14, s5
 *   @0x1b1e60 vmla.f32 s19, s14, s15
 *   @0x1b1e64 bl 0x318c48 <__udivsi3>
 *   @0x1b1e68 ubfx r3, r5, #0x1c, #0x1
 *   @0x1b1e6c tst r5, #1073741824
 *   @0x1b1e70 vldr s10, [pc, #676]
 *   @0x1b1e74 vmov s13, r3
 *   @0x1b1e78 ubfx r3, r5, #0x1d, #0x1
 *   @0x1b1e7c vmov s8, r3
 *   @0x1b1e80 ubfx r3, r5, #0x1e, #0x1
 *   @0x1b1e84 vmov s9, r3
 *   @0x1b1e88 vmul.f32 s18, s16, s18
 *   @0x1b1e8c vmov s5, r0
 *   @0x1b1e90 vmul.f32 s12, s21, s16
 *   @0x1b1e94 vadd.f32 s7, s18, s18
 *   @0x1b1e98 vmov.f32 s14, #1.000000e+00
 *   @0x1b1e9c vadd.f32 s7, s7, s12
 *   @0x1b1ea0 vcvt.f32.u32 s6, s5
 *   @0x1b1ea4 vmov.f32 s15, #-2.000000e+00
 *   @0x1b1ea8 vcvt.f32.s32 s13, s13
 *   @0x1b1eac vmla.f32 s18, s6, s7
 *   @0x1b1eb0 vmov.f32 s6, s14
 *   @0x1b1eb4 vmla.f32 s6, s13, s15
 *   @0x1b1eb8 vmov.f32 s11, #5.000000e-01
 *   @0x1b1ebc vcvt.f32.s32 s8, s8
 *   @0x1b1ec0 vcvt.f32.s32 s9, s9
 *   @0x1b1ec4 vmla.f32 s14, s8, s15
 *   @0x1b1ec8 vmul.f32 s22, s22, s11
 *   @0x1b1ecc vmov.f32 s13, s6
 *   @0x1b1ed0 vmul.f32 s15, s9, s10
 *   @0x1b1ed4 vmul.f32 s11, s21, s11
 *   @0x1b1ed8 bne 0x1b20d8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x3d0>
 *   @0x1b1edc vldr s9, [sp, #152]
 *   @0x1b1ee0 vldr s5, [sp, #156]
 *   @0x1b1ee4 vmls.f32 s22, s22, s6
 *   @0x1b1ee8 vmls.f32 s11, s11, s14
 *   @0x1b1eec vadd.f32 s10, s9, s22
 *   @0x1b1ef0 vadd.f32 s11, s5, s11
 *   @0x1b1ef4 vstr s15, [sp, #20]
 *   @0x1b1ef8 mvn r3, #0
 *   @0x1b1efc vstr s12, [sp]
 *   @0x1b1f00 str r3, [sp, #0x18]
 *   @0x1b1f04 str r3, [sp, #0x1c]
 *   @0x1b1f08 vstr s10, [sp, #4]
 *   @0x1b1f0c str r3, [sp, #0x20]
 *   @0x1b1f10 vstr s11, [sp, #8]
 *   @0x1b1f14 str r3, [sp, #0x24]
 *   @0x1b1f18 mov r0, r4
 *   @0x1b1f1c vmov r1, s19
 *   @0x1b1f20 vmov r2, s18
 *   @0x1b1f24 vmov r3, s20
 *   @0x1b1f28 vmov.f32 s15, #1.000000e+00
 *   @0x1b1f2c vdiv.f32 s17, s15, s17
 *   @0x1b1f30 vstr s15, [sp, #40]
 *   @0x1b1f34 vdiv.f32 s16, s15, s16
 *   @0x1b1f38 vmul.f32 s13, s13, s17
 *   @0x1b1f3c vmul.f32 s14, s14, s16
 *   @0x1b1f40 vstr s13, [sp, #12]
 *   @0x1b1f44 vstr s14, [sp, #16]
 *   @0x1b1f48 bl 0xc2238 <_ZN11CBackground11DrawGeneralEfffffffffjjjjf>
 *   @0x1b1f4c b 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0>
 *   @0x1b1f50 mla r7, r3, r7, r1
 *   @0x1b1f54 ldr r0, [r4, #0x40]
 *   @0x1b1f58 ldr r7, [r0, r7, lsl #2]
 *   @0x1b1f5c cmp r7, #0
 *   @0x1b1f60 beq 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0>
 *   @0x1b1f64 ldr r1, [r2]
 *   @0x1b1f68 mov r3, #6
 *   @0x1b1f6c mov r2, #24
 *   @0x1b1f70 mov r0, #4
 *   @0x1b1f74 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x1b1f78 mov r1, r6
 *   @0x1b1f7c mov r4, r0
 *   @0x1b1f80 mov r0, r7
 *   @0x1b1f84 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x1b1f88 mov r0, r7
 *   @0x1b1f8c vldr s15, [sp, #68]
 *   @0x1b1f90 vldr s16, [sp, #52]
 *   @0x1b1f94 vmov s5, r1
 *   @0x1b1f98 mov r1, r6
 *   @0x1b1f9c vcvt.f32.u32 s14, s5
 *   @0x1b1fa0 vmla.f32 s16, s14, s15
 *   @0x1b1fa4 bl 0x318c48 <__udivsi3>
 *   @0x1b1fa8 vldr s10, [sp, #72]
 *   @0x1b1fac vldr s15, [sp, #56]
 *   @0x1b1fb0 vmov s6, r9
 *   @0x1b1fb4 tst r5, #1879048192
 *   @0x1b1fb8 vmov s7, r8
 *   @0x1b1fbc vldr s14, [sp, #60]
 *   @0x1b1fc0 vldr s13, [sp, #64]
 *   @0x1b1fc4 vcvt.f32.s32 s11, s6
 *   @0x1b1fc8 vcvt.f32.s32 s12, s7
 *   @0x1b1fcc vmov s8, r0
 *   @0x1b1fd0 vcvt.f32.u32 s9, s8
 *   @0x1b1fd4 vmla.f32 s15, s9, s10
 *   @0x1b1fd8 vldr s9, [sp, #152]
 *   @0x1b1fdc vldr s10, [sp, #156]
 *   @0x1b1fe0 vadd.f32 s14, s16, s14
 *   @0x1b1fe4 vadd.f32 s13, s15, s13
 *   @0x1b1fe8 vadd.f32 s11, s9, s11
 *   @0x1b1fec vadd.f32 s12, s10, s12
 *   @0x1b1ff0 beq 0x1b20f4 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x3ec>
 *   @0x1b1ff4 tst r5, #268435456
 *   @0x1b1ff8 vmovne.f32 s8, s16
 *   @0x1b1ffc vmoveq.f32 s8, s14
 *   @0x1b2000 vmovne.f32 s16, s14
 *   @0x1b2004 tst r5, #536870912
 *   @0x1b2008 vmovne.f32 s10, s13
 *   @0x1b200c vmoveq.f32 s10, s15
 *   @0x1b2010 vmovne.f32 s13, s15
 *   @0x1b2014 tst r5, #1073741824
 *   @0x1b2018 bne 0x1b2108 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x400>
 *   @0x1b201c vmov.f32 s7, s13
 *   @0x1b2020 vmov.f32 s9, s16
 *   @0x1b2024 vmov.f32 s14, s8
 *   @0x1b2028 vmov.f32 s15, s10
 *   @0x1b202c mvn r3, #0
 *   @0x1b2030 vldr s6, [sp, #156]
 *   @0x1b2034 vldr s5, [sp, #152]
 *   @0x1b2038 vstr s6, [r4, #4]
 *   @0x1b203c vstr s5, [r4]
 *   @0x1b2040 vstr s6, [r4, #28]
 *   @0x1b2044 vldr s5, [sp, #160]
 *   @0x1b2048 vldr s6, [sp, #152]
 *   @0x1b204c vstr s9, [r4, #64]
 *   @0x1b2050 vstr s9, [r4, #88]
 *   @0x1b2054 vstr s5, [r4, #8]
 *   @0x1b2058 vldr s9, [sp, #156]
 *   @0x1b205c vstr s16, [r4, #16]
 *   @0x1b2060 vstr s15, [r4, #20]
 *   @0x1b2064 vstr s11, [r4, #24]
 *   @0x1b2068 vstr s5, [r4, #32]
 *   @0x1b206c vstr s14, [r4, #40]
 *   @0x1b2070 vstr s10, [r4, #44]
 *   @0x1b2074 vstr s6, [r4, #48]
 *   @0x1b2078 vstr s12, [r4, #52]
 *   @0x1b207c vstr s5, [r4, #56]
 *   @0x1b2080 vstr s13, [r4, #68]
 *   @0x1b2084 vstr s6, [r4, #72]
 *   @0x1b2088 vstr s12, [r4, #76]
 *   @0x1b208c vstr s5, [r4, #80]
 *   @0x1b2090 vstr s13, [r4, #92]
 *   @0x1b2094 vstr s11, [r4, #96]
 *   @0x1b2098 vstr s9, [r4, #100]
 *   @0x1b209c vstr s5, [r4, #104]
 *   @0x1b20a0 vstr s14, [r4, #112]
 *   @0x1b20a4 vstr s10, [r4, #116]
 *   @0x1b20a8 vstr s11, [r4, #120]
 *   @0x1b20ac vstr s12, [r4, #124]
 *   @0x1b20b0 vstr s5, [r4, #128]
 *   @0x1b20b4 str r3, [r4, #0xc]
 *   @0x1b20b8 vstr s8, [r4, #136]
 *   @0x1b20bc str r3, [r4, #0x24]
 *   @0x1b20c0 vstr s7, [r4, #140]
 *   @0x1b20c4 str r3, [r4, #0x3c]
 *   @0x1b20c8 str r3, [r4, #0x54]
 *   @0x1b20cc str r3, [r4, #0x6c]
 *   @0x1b20d0 str r3, [r4, #0x84]
 *   @0x1b20d4 b 0x1b1dc8 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0xc0>
 *   @0x1b20d8 vmla.f32 s11, s11, s14
 *   @0x1b20dc vldr s7, [sp, #152]
 *   @0x1b20e0 vldr s8, [sp, #156]
 *   @0x1b20e4 vmls.f32 s22, s22, s6
 *   @0x1b20e8 vadd.f32 s10, s7, s11
 *   @0x1b20ec vadd.f32 s11, s8, s22
 *   @0x1b20f0 b 0x1b1ef4 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x1ec>
 *   @0x1b20f4 vmov.f32 s7, s13
 *   @0x1b20f8 vmov.f32 s8, s14
 *   @0x1b20fc vmov.f32 s9, s16
 *   @0x1b2100 vmov.f32 s10, s15
 *   @0x1b2104 b 0x1b202c <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x324>
 *   @0x1b2108 vmov.f32 s7, s10
 *   @0x1b210c vmov.f32 s9, s8
 *   @0x1b2110 vmov.f32 s14, s16
 *   @0x1b2114 vmov.f32 s15, s13
 *   @0x1b2118 b 0x1b202c <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff+0x324>
 *   @0x1b211c adcsgt r0, r4, #0
 *   @0x1b2120 eoreq lr, r3, r8, ror r10
 *
 * ══ §7/31 b2Fixture::Dump(int)  0x2c89f4  size 1052  263 条（0x2c89f4..0x2c8e10）
 * @func 0x2c89f4 0x2c8e10  size 1052  263 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Log(char const*, ...)×34 / b2Fixture::Dump(int)+0x138 / b2Fixture::Dump(int)+0x220
 * 字段偏移 top8: 0x10×3 / 0x2c×2 / 0x24×2 / 0xc×2 / 0x94×2 / 0x384×1 / 0x36c×1 / 0x358×1
 * VFP 指令 69 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c89f4 push {r4, r5, r6, r7, r8, lr}
 *   @0x2c89f8 mov r4, r0
 *   @0x2c89fc ldr r0, [pc, #0x384]
 *   @0x2c8a00 sub sp, sp, #8
 *   @0x2c8a04 mov r7, r1
 *   @0x2c8a08 add r0, pc, r0
 *   @0x2c8a0c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8a10 vldr s15, [r4, #16]
 *   @0x2c8a14 vcvt.f64.f32 d5, s15
 *   @0x2c8a18 ldr r0, [pc, #0x36c]
 *   @0x2c8a1c add r0, pc, r0
 *   @0x2c8a20 vmov r2, r3, d5
 *   @0x2c8a24 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8a28 vldr s15, [r4, #20]
 *   @0x2c8a2c vcvt.f64.f32 d6, s15
 *   @0x2c8a30 ldr r0, [pc, #0x358]
 *   @0x2c8a34 add r0, pc, r0
 *   @0x2c8a38 vmov r2, r3, d6
 *   @0x2c8a3c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8a40 vldr s15, [r4]
 *   @0x2c8a44 vcvt.f64.f32 d5, s15
 *   @0x2c8a48 ldr r0, [pc, #0x344]
 *   @0x2c8a4c add r0, pc, r0
 *   @0x2c8a50 vmov r2, r3, d5
 *   @0x2c8a54 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8a58 ldr r0, [pc, #0x338]
 *   @0x2c8a5c ldrb r1, [r4, #0x2c]
 *   @0x2c8a60 add r0, pc, r0
 *   @0x2c8a64 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8a68 ldr r0, [pc, #0x32c]
 *   @0x2c8a6c ldr r1, [r4, #0x20]
 *   @0x2c8a70 add r0, pc, r0
 *   @0x2c8a74 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8a78 ldr r0, [pc, #0x320]
 *   @0x2c8a7c ldr r1, [r4, #0x24]
 *   @0x2c8a80 add r0, pc, r0
 *   @0x2c8a84 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8a88 ldr r0, [pc, #0x314]
 *   @0x2c8a8c ldrsh r1, [r4, #40]
 *   @0x2c8a90 add r0, pc, r0
 *   @0x2c8a94 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8a98 ldr r4, [r4, #0xc]
 *   @0x2c8a9c ldr r3, [r4, #0x4]
 *   @0x2c8aa0 cmp r3, #3
 *   @0x2c8aa4 addls pc, pc, r3, lsl #2
 *   @0x2c8aa8 b 0x2c8d80 <_ZN9b2Fixture4DumpEi+0x38c>
 *   @0x2c8aac b 0x2c8c24 <_ZN9b2Fixture4DumpEi+0x230>
 *   @0x2c8ab0 b 0x2c8ca8 <_ZN9b2Fixture4DumpEi+0x2b4>
 *   @0x2c8ab4 b 0x2c8ba4 <_ZN9b2Fixture4DumpEi+0x1b0>
 *   @0x2c8ab8 b 0x2c8abc <_ZN9b2Fixture4DumpEi+0xc8>
 *   @0x2c8abc ldr r0, [pc, #0x2e4]
 *   @0x2c8ac0 add r0, pc, r0
 *   @0x2c8ac4 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8ac8 ldr r0, [pc, #0x2dc]
 *   @0x2c8acc ldr r1, [r4, #0x10]
 *   @0x2c8ad0 add r0, pc, r0
 *   @0x2c8ad4 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8ad8 ldr r1, [r4, #0x10]
 *   @0x2c8adc cmp r1, #0
 *   @0x2c8ae0 ble 0x2c8b2c <_ZN9b2Fixture4DumpEi+0x138>
 *   @0x2c8ae4 ldr r6, [pc, #0x2c4]
 *   @0x2c8ae8 mov r5, #0
 *   @0x2c8aec add r6, pc, r6
 *   @0x2c8af0 ldr r3, [r4, #0xc]
 *   @0x2c8af4 mov r1, r5
 *   @0x2c8af8 mov r0, r6
 *   @0x2c8afc add r3, r3, r5, lsl #3
 *   @0x2c8b00 vldr s14, [r3, #4]
 *   @0x2c8b04 vldr s13, [r3]
 *   @0x2c8b08 vcvt.f64.f32 d7, s14
 *   @0x2c8b0c add r5, r5, #1
 *   @0x2c8b10 vcvt.f64.f32 d5, s13
 *   @0x2c8b14 vstr d7, [sp]
 *   @0x2c8b18 vmov r2, r3, d5
 *   @0x2c8b1c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8b20 ldr r1, [r4, #0x10]
 *   @0x2c8b24 cmp r1, r5
 *   @0x2c8b28 bgt 0x2c8af0 <_ZN9b2Fixture4DumpEi+0xfc>
 *   @0x2c8b2c ldr r0, [pc, #0x280]
 *   @0x2c8b30 add r0, pc, r0
 *   @0x2c8b34 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8b38 vldr s14, [r4, #24]
 *   @0x2c8b3c vcvt.f64.f32 d7, s14
 *   @0x2c8b40 vldr s13, [r4, #20]
 *   @0x2c8b44 ldr r0, [pc, #0x26c]
 *   @0x2c8b48 add r0, pc, r0
 *   @0x2c8b4c vstr d7, [sp]
 *   @0x2c8b50 vcvt.f64.f32 d7, s13
 *   @0x2c8b54 vmov r2, r3, d7
 *   @0x2c8b58 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8b5c vldr s13, [r4, #28]
 *   @0x2c8b60 vldr s14, [r4, #32]
 *   @0x2c8b64 vcvt.f64.f32 d5, s13
 *   @0x2c8b68 ldr r0, [pc, #0x24c]
 *   @0x2c8b6c add r0, pc, r0
 *   @0x2c8b70 vcvt.f64.f32 d7, s14
 *   @0x2c8b74 vmov r2, r3, d5
 *   @0x2c8b78 vstr d7, [sp]
 *   @0x2c8b7c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8b80 ldr r0, [pc, #0x238]
 *   @0x2c8b84 ldrb r1, [r4, #0x24]
 *   @0x2c8b88 add r0, pc, r0
 *   @0x2c8b8c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8b90 ldr r0, [pc, #0x22c]
 *   @0x2c8b94 ldrb r1, [r4, #0x25]
 *   @0x2c8b98 add r0, pc, r0
 *   @0x2c8b9c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8ba0 b 0x2c8c6c <_ZN9b2Fixture4DumpEi+0x278>
 *   @0x2c8ba4 ldr r0, [pc, #0x21c]
 *   @0x2c8ba8 add r0, pc, r0
 *   @0x2c8bac bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8bb0 ldr r0, [pc, #0x214]
 *   @0x2c8bb4 mov r1, #8
 *   @0x2c8bb8 add r0, pc, r0
 *   @0x2c8bbc bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8bc0 ldr r1, [r4, #0x94]
 *   @0x2c8bc4 cmp r1, #0
 *   @0x2c8bc8 ble 0x2c8c14 <_ZN9b2Fixture4DumpEi+0x220>
 *   @0x2c8bcc ldr r8, [pc, #0x1fc]
 *   @0x2c8bd0 add r6, r4, #20
 *   @0x2c8bd4 mov r5, #0
 *   @0x2c8bd8 add r8, pc, r8
 *   @0x2c8bdc vldr s14, [r6, #4]
 *   @0x2c8be0 vcvt.f64.f32 d7, s14
 *   @0x2c8be4 vldr s13, [r6]
 *   @0x2c8be8 mov r1, r5
 *   @0x2c8bec mov r0, r8
 *   @0x2c8bf0 add r5, r5, #1
 *   @0x2c8bf4 add r6, r6, #8
 *   @0x2c8bf8 vstr d7, [sp]
 *   @0x2c8bfc vcvt.f64.f32 d7, s13
 *   @0x2c8c00 vmov r2, r3, d7
 *   @0x2c8c04 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8c08 ldr r1, [r4, #0x94]
 *   @0x2c8c0c cmp r1, r5
 *   @0x2c8c10 bgt 0x2c8bdc <_ZN9b2Fixture4DumpEi+0x1e8>
 *   @0x2c8c14 ldr r0, [pc, #0x1b8]
 *   @0x2c8c18 add r0, pc, r0
 *   @0x2c8c1c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8c20 b 0x2c8c6c <_ZN9b2Fixture4DumpEi+0x278>
 *   @0x2c8c24 ldr r0, [pc, #0x1ac]
 *   @0x2c8c28 add r0, pc, r0
 *   @0x2c8c2c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8c30 vldr s15, [r4, #8]
 *   @0x2c8c34 vcvt.f64.f32 d6, s15
 *   @0x2c8c38 ldr r0, [pc, #0x19c]
 *   @0x2c8c3c add r0, pc, r0
 *   @0x2c8c40 vmov r2, r3, d6
 *   @0x2c8c44 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8c48 vldr s14, [r4, #16]
 *   @0x2c8c4c vldr s13, [r4, #12]
 *   @0x2c8c50 vcvt.f64.f32 d7, s14
 *   @0x2c8c54 ldr r0, [pc, #0x184]
 *   @0x2c8c58 add r0, pc, r0
 *   @0x2c8c5c vcvt.f64.f32 d5, s13
 *   @0x2c8c60 vstr d7, [sp]
 *   @0x2c8c64 vmov r2, r3, d5
 *   @0x2c8c68 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8c6c ldr r4, [pc, #0x170]
 *   @0x2c8c70 add r4, pc, r4
 *   @0x2c8c74 mov r0, r4
 *   @0x2c8c78 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8c7c ldr r0, [pc, #0x164]
 *   @0x2c8c80 add r0, pc, r0
 *   @0x2c8c84 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8c88 mov r0, r4
 *   @0x2c8c8c bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8c90 ldr r0, [pc, #0x154]
 *   @0x2c8c94 mov r1, r7
 *   @0x2c8c98 add r0, pc, r0
 *   @0x2c8c9c add sp, sp, #8
 *   @0x2c8ca0 pop {r4, r5, r6, r7, r8, lr}
 *   @0x2c8ca4 b 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8ca8 ldr r0, [pc, #0x140]
 *   @0x2c8cac add r0, pc, r0
 *   @0x2c8cb0 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8cb4 vldr s15, [r4, #8]
 *   @0x2c8cb8 vcvt.f64.f32 d6, s15
 *   @0x2c8cbc ldr r0, [pc, #0x130]
 *   @0x2c8cc0 add r0, pc, r0
 *   @0x2c8cc4 vmov r2, r3, d6
 *   @0x2c8cc8 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8ccc vldr s13, [r4, #28]
 *   @0x2c8cd0 vldr s14, [r4, #32]
 *   @0x2c8cd4 vcvt.f64.f32 d5, s13
 *   @0x2c8cd8 ldr r0, [pc, #0x118]
 *   @0x2c8cdc add r0, pc, r0
 *   @0x2c8ce0 vcvt.f64.f32 d7, s14
 *   @0x2c8ce4 vmov r2, r3, d5
 *   @0x2c8ce8 vstr d7, [sp]
 *   @0x2c8cec bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8cf0 vldr s13, [r4, #12]
 *   @0x2c8cf4 vldr s14, [r4, #16]
 *   @0x2c8cf8 vcvt.f64.f32 d5, s13
 *   @0x2c8cfc ldr r0, [pc, #0xf8]
 *   @0x2c8d00 add r0, pc, r0
 *   @0x2c8d04 vcvt.f64.f32 d7, s14
 *   @0x2c8d08 vmov r2, r3, d5
 *   @0x2c8d0c vstr d7, [sp]
 *   @0x2c8d10 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8d14 vldr s13, [r4, #20]
 *   @0x2c8d18 vldr s14, [r4, #24]
 *   @0x2c8d1c vcvt.f64.f32 d5, s13
 *   @0x2c8d20 ldr r0, [pc, #0xd8]
 *   @0x2c8d24 add r0, pc, r0
 *   @0x2c8d28 vcvt.f64.f32 d7, s14
 *   @0x2c8d2c vmov r2, r3, d5
 *   @0x2c8d30 vstr d7, [sp]
 *   @0x2c8d34 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8d38 vldr s13, [r4, #36]
 *   @0x2c8d3c vldr s14, [r4, #40]
 *   @0x2c8d40 vcvt.f64.f32 d5, s13
 *   @0x2c8d44 ldr r0, [pc, #0xb8]
 *   @0x2c8d48 add r0, pc, r0
 *   @0x2c8d4c vcvt.f64.f32 d7, s14
 *   @0x2c8d50 vmov r2, r3, d5
 *   @0x2c8d54 vstr d7, [sp]
 *   @0x2c8d58 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8d5c ldr r0, [pc, #0xa4]
 *   @0x2c8d60 ldrb r1, [r4, #0x2c]
 *   @0x2c8d64 add r0, pc, r0
 *   @0x2c8d68 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8d6c ldr r0, [pc, #0x98]
 *   @0x2c8d70 ldrb r1, [r4, #0x2d]
 *   @0x2c8d74 add r0, pc, r0
 *   @0x2c8d78 bl 0x2c6a74 <_Z5b2LogPKcz>
 *   @0x2c8d7c b 0x2c8c6c <_ZN9b2Fixture4DumpEi+0x278>
 *   @0x2c8d80 add sp, sp, #8
 *   @0x2c8d84 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2c8d88 andeq r2, r9, r0, asr #30
 *   @0x2c8d8c andeq r2, r9, r4, asr #30
 *   @0x2c8d90 andeq r2, r9, r8, asr #30
 *   @0x2c8d94 andeq r2, r9, r0, asr pc
 *   @0x2c8d98 andeq r2, r9, r8, asr pc
 *   @0x2c8d9c andeq r2, r9, r8, ror #30
 *   @0x2c8da0 andeq r2, r9, r4, lsl #31
 *   @0x2c8da4 muleq r9, r12, pc
 *   @0x2c8da8 andeq r3, r9, r4, ror r1
 *   @0x2c8dac andeq r3, r9, r4, lsl r1
 *   @0x2c8db0 andeq r3, r9, r12, lsl #2
 *   @0x2c8db4 andeq r3, r9, r0, lsr #2
 *   @0x2c8db8 andeq r3, r9, r8, lsr #2
 *   @0x2c8dbc andeq r3, r9, r4, lsr r1
 *   @0x2c8dc0 andeq r3, r9, r8, asr #2
 *   @0x2c8dc4 andeq r3, r9, r0, ror #2
 *   @0x2c8dc8 andeq r3, r9, r0, lsr #32
 *   @0x2c8dcc andeq r3, r9, r12, lsr #32
 *   @0x2c8dd0 andeq r3, r9, r0, lsr #32
 *   @0x2c8dd4 andeq r3, r9, r4
 *   @0x2c8dd8 andeq r2, r9, r12, lsr #28
 *   @0x2c8ddc andeq r2, r9, r4, lsr lr
 *   @0x2c8de0 andeq r2, r9, r8, lsr lr
 *   @0x2c8de4 andeq r10, r6, r8, lsr #32
 *   @0x2c8de8 andeq r3, r9, r0, lsr #1
 *   @0x2c8dec andeq r3, r9, r0, lsr #1
 *   @0x2c8df0 andeq r2, r9, r12, lsl #28
 *   @0x2c8df4 strheq r2, [r9], -r0
 *   @0x2c8df8 strdeq r2, r3, [r9], -r4
 *   @0x2c8dfc strdeq r2, r3, [r9], -r12
 *   @0x2c8e00 andeq r2, r9, r4, lsl #28
 *   @0x2c8e04 andeq r2, r9, r12, lsl #28
 *   @0x2c8e08 andeq r2, r9, r12, lsl lr
 *   @0x2c8e0c andeq r2, r9, r0, lsr lr
 *
 * ══ §8/31 YYObjectBase::AssignVars(YYObjectBase*)  0x1982d4  size 1048  262 条（0x1982d4..0x1986ec）
 * @func 0x1982d4 0x1986ec  size 1048  262 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / 0xb65b0×2 / operator new(unsigned int) / YYObjectBase::AssignVars(YYObjectBase*)+0xb4 / YYObjectBase::AssignVars(YYObjectBase*)+0x318 / YYObjectBase::AssignVars(YYObjectBase*)+0xf8 / GetRValue() / CHashMapCalculateHash(int)
 * 字段偏移 top8: 0x4×17 / 0x8×17 / 0x10×8 / 0xc×6 / 0x60×5 / 0x3dc×1 / 0x33c×1 / 0x-4×1
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1982d4 ldr r3, [r1, #0x60]
 *   @0x1982d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1982dc vpush {d8}
 *   @0x1982e0 cmp r3, #0
 *   @0x1982e4 sub sp, sp, #20
 *   @0x1982e8 str r1, [sp, #0x4]
 *   @0x1982ec str r0, [sp, #0x8]
 *   @0x1982f0 beq 0x1985ec <_ZN12YYObjectBase10AssignVarsEPS_+0x318>
 *   @0x1982f4 mov r0, #20
 *   @0x1982f8 mov r5, #0
 *   @0x1982fc bl 0x27c524 <_Znwj>
 *   @0x198300 ldr r1, [pc, #0x3dc]
 *   @0x198304 mov r2, #8
 *   @0x198308 mov r3, #7
 *   @0x19830c add r1, pc, r1
 *   @0x198310 mov r4, r0
 *   @0x198314 str r2, [r0]
 *   @0x198318 str r3, [r4, #0x8]
 *   @0x19831c mov r2, #70
 *   @0x198320 mov r3, #1
 *   @0x198324 mov r0, #96
 *   @0x198328 str r5, [r4, #0x10]
 *   @0x19832c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x198330 mov r2, #96
 *   @0x198334 mov r1, r5
 *   @0x198338 str r0, [r4, #0x10]
 *   @0x19833c bl 0xb65b0 <memset@plt>
 *   @0x198340 ldr r2, [r4]
 *   @0x198344 vldr s15, [pc, #916]
 *   @0x198348 str r5, [r4, #0x4]
 *   @0x19834c cmp r2, r5
 *   @0x198350 vmov s13, r2
 *   @0x198354 vcvt.f32.s32 s14, s13
 *   @0x198358 vmul.f32 s15, s14, s15
 *   @0x19835c vcvt.s32.f32 s15, s15
 *   @0x198360 vstr s15, [r4, #12]
 *   @0x198364 ble 0x198388 <_ZN12YYObjectBase10AssignVarsEPS_+0xb4>
 *   @0x198368 add r2, r2, r2, lsl #1
 *   @0x19836c ldr r3, [r4, #0x10]
 *   @0x198370 mov r1, r5
 *   @0x198374 add r2, r3, r2, lsl #2
 *   @0x198378 str r1, [r3, #0x8]
 *   @0x19837c add r3, r3, #12
 *   @0x198380 cmp r3, r2
 *   @0x198384 bne 0x198378 <_ZN12YYObjectBase10AssignVarsEPS_+0xa4>
 *   @0x198388 ldr r2, [sp, #0x4]
 *   @0x19838c ldr r1, [sp, #0x8]
 *   @0x198390 str r4, [r1, #0x60]
 *   @0x198394 ldr r3, [r2, #0x60]
 *   @0x198398 ldr r2, [r3, #0x4]
 *   @0x19839c cmp r2, #0
 *   @0x1983a0 ble 0x1985ec <_ZN12YYObjectBase10AssignVarsEPS_+0x318>
 *   @0x1983a4 ldr r1, [pc, #0x33c]
 *   @0x1983a8 mov r2, #0
 *   @0x1983ac vldr s16, [pc, #812]
 *   @0x1983b0 str r2, [sp]
 *   @0x1983b4 add r1, pc, r1
 *   @0x1983b8 str r1, [sp, #0xc]
 *   @0x1983bc ldr r4, [r3, #0x10]
 *   @0x1983c0 mov r3, #0
 *   @0x1983c4 ldr r1, [sp]
 *   @0x1983c8 b 0x1983d0 <_ZN12YYObjectBase10AssignVarsEPS_+0xfc>
 *   @0x1983cc add r4, r4, #12
 *   @0x1983d0 ldr r2, [r4, #0x8]
 *   @0x1983d4 cmp r2, #0
 *   @0x1983d8 ble 0x1983cc <_ZN12YYObjectBase10AssignVarsEPS_+0xf8>
 *   @0x1983dc cmp r1, r3
 *   @0x1983e0 add r3, r3, #1
 *   @0x1983e4 bne 0x1983cc <_ZN12YYObjectBase10AssignVarsEPS_+0xf8>
 *   @0x1983e8 ldr r7, [r4]
 *   @0x1983ec bl 0x190dc0 <_Z9GetRValuev>
 *   @0x1983f0 ldr r4, [r4, #0x4]
 *   @0x1983f4 ldr r3, [r4, #0xc]
 *   @0x1983f8 ldr r2, [r4, #0x8]
 *   @0x1983fc str r3, [r0, #0xc]
 *   @0x198400 mov r6, r0
 *   @0x198404 ldr r3, [r4, #0xc]
 *   @0x198408 str r2, [r0, #0x8]
 *   @0x19840c bic r3, r3, #-16777216
 *   @0x198410 cmp r3, #14
 *   @0x198414 addls pc, pc, r3, lsl #2
 *   @0x198418 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c>
 *   @0x19841c b 0x198548 <_ZN12YYObjectBase10AssignVarsEPS_+0x274>
 *   @0x198420 b 0x1985a4 <_ZN12YYObjectBase10AssignVarsEPS_+0x2d0>
 *   @0x198424 b 0x198578 <_ZN12YYObjectBase10AssignVarsEPS_+0x2a4>
 *   @0x198428 b 0x198458 <_ZN12YYObjectBase10AssignVarsEPS_+0x184>
 *   @0x19842c b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c>
 *   @0x198430 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c>
 *   @0x198434 b 0x198554 <_ZN12YYObjectBase10AssignVarsEPS_+0x280>
 *   @0x198438 b 0x198458 <_ZN12YYObjectBase10AssignVarsEPS_+0x184>
 *   @0x19843c b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c>
 *   @0x198440 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c>
 *   @0x198444 b 0x198548 <_ZN12YYObjectBase10AssignVarsEPS_+0x274>
 *   @0x198448 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c>
 *   @0x19844c b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c>
 *   @0x198450 b 0x198548 <_ZN12YYObjectBase10AssignVarsEPS_+0x274>
 *   @0x198454 b 0x198458 <_ZN12YYObjectBase10AssignVarsEPS_+0x184>
 *   @0x198458 ldr r3, [r4]
 *   @0x19845c str r3, [r6]
 *   @0x198460 ldr r3, [sp, #0x8]
 *   @0x198464 ldr r8, [r3, #0x60]
 *   @0x198468 ldr r3, [r8, #0x4]
 *   @0x19846c ldr r2, [r8, #0xc]
 *   @0x198470 cmp r3, r2
 *   @0x198474 bgt 0x1985f8 <_ZN12YYObjectBase10AssignVarsEPS_+0x324>
 *   @0x198478 add r3, r3, #1
 *   @0x19847c mov r0, r7
 *   @0x198480 str r3, [r8, #0x4]
 *   @0x198484 bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x198488 ldr r4, [r8, #0x8]
 *   @0x19848c ldr r10, [r8, #0x10]
 *   @0x198490 bic r0, r0, #-2147483648
 *   @0x198494 and r3, r0, r4
 *   @0x198498 add r2, r3, r3, lsl #1
 *   @0x19849c add r2, r10, r2, lsl #2
 *   @0x1984a0 ldr r1, [r2, #0x8]
 *   @0x1984a4 cmp r1, #0
 *   @0x1984a8 ldrne r11, [r8]
 *   @0x1984ac movne r5, #0
 *   @0x1984b0 bne 0x1984f8 <_ZN12YYObjectBase10AssignVarsEPS_+0x224>
 *   @0x1984b4 b 0x1985bc <_ZN12YYObjectBase10AssignVarsEPS_+0x2e8>
 *   @0x1984b8 ldr r9, [r2]
 *   @0x1984bc ldr r5, [r2, #0x4]
 *   @0x1984c0 str r0, [r2, #0x8]
 *   @0x1984c4 mov r0, r1
 *   @0x1984c8 str r7, [r2]
 *   @0x1984cc mov r7, r9
 *   @0x1984d0 str r6, [r2, #0x4]
 *   @0x1984d4 mov r6, r5
 *   @0x1984d8 add r3, r3, #1
 *   @0x1984dc add r5, r12, #1
 *   @0x1984e0 and r3, r3, r4
 *   @0x1984e4 add r2, r3, r3, lsl #1
 *   @0x1984e8 add r2, r10, r2, lsl #2
 *   @0x1984ec ldr r1, [r2, #0x8]
 *   @0x1984f0 cmp r1, #0
 *   @0x1984f4 beq 0x1985bc <_ZN12YYObjectBase10AssignVarsEPS_+0x2e8>
 *   @0x1984f8 add r12, r11, r3
 *   @0x1984fc and r9, r1, r4
 *   @0x198500 rsb r12, r9, r12
 *   @0x198504 and r12, r12, r4
 *   @0x198508 cmp r12, r5
 *   @0x19850c blt 0x1984b8 <_ZN12YYObjectBase10AssignVarsEPS_+0x1e4>
 *   @0x198510 movne r12, r5
 *   @0x198514 bne 0x1984d8 <_ZN12YYObjectBase10AssignVarsEPS_+0x204>
 *   @0x198518 cmp r1, r0
 *   @0x19851c bne 0x1984d8 <_ZN12YYObjectBase10AssignVarsEPS_+0x204>
 *   @0x198520 ldr r5, [r2]
 *   @0x198524 cmp r7, r5
 *   @0x198528 bne 0x1984d8 <_ZN12YYObjectBase10AssignVarsEPS_+0x204>
 *   @0x19852c ldr r3, [r8, #0x4]
 *   @0x198530 str r7, [r2]
 *   @0x198534 str r6, [r2, #0x4]
 *   @0x198538 sub r3, r3, #1
 *   @0x19853c str r1, [r2, #0x8]
 *   @0x198540 str r3, [r8, #0x4]
 *   @0x198544 b 0x1985c8 <_ZN12YYObjectBase10AssignVarsEPS_+0x2f4>
 *   @0x198548 ldm r4, {r2, r3}
 *   @0x19854c stm r0, {r2, r3}
 *   @0x198550 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c>
 *   @0x198554 ldr r3, [r4]
 *   @0x198558 str r3, [r0]
 *   @0x19855c ldr r3, [r4]
 *   @0x198560 cmp r3, #0
 *   @0x198564 beq 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c>
 *   @0x198568 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x19856c ldr r1, [r4]
 *   @0x198570 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x198574 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c>
 *   @0x198578 ldr r3, [r4]
 *   @0x19857c cmp r3, #0
 *   @0x198580 str r3, [r0]
 *   @0x198584 beq 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c>
 *   @0x198588 ldr r1, [r3, #0x8]
 *   @0x19858c ldr r2, [r3]
 *   @0x198590 cmp r1, #0
 *   @0x198594 streq r0, [r3, #0x8]
 *   @0x198598 add r2, r2, #1
 *   @0x19859c str r2, [r3]
 *   @0x1985a0 b 0x198460 <_ZN12YYObjectBase10AssignVarsEPS_+0x18c>
 *   @0x1985a4 ldr r3, [r4]
 *   @0x1985a8 cmp r3, #0
 *   @0x1985ac ldrne r2, [r3, #0x4]
 *   @0x1985b0 addne r2, r2, #1
 *   @0x1985b4 strne r2, [r3, #0x4]
 *   @0x1985b8 b 0x19845c <_ZN12YYObjectBase10AssignVarsEPS_+0x188>
 *   @0x1985bc str r7, [r2]
 *   @0x1985c0 str r6, [r2, #0x4]
 *   @0x1985c4 str r0, [r2, #0x8]
 *   @0x1985c8 ldr r1, [sp, #0x4]
 *   @0x1985cc ldr r2, [sp]
 *   @0x1985d0 ldr r3, [r1, #0x60]
 *   @0x1985d4 add r2, r2, #1
 *   @0x1985d8 str r2, [sp]
 *   @0x1985dc ldr r1, [sp]
 *   @0x1985e0 ldr r2, [r3, #0x4]
 *   @0x1985e4 cmp r2, r1
 *   @0x1985e8 bgt 0x1983bc <_ZN12YYObjectBase10AssignVarsEPS_+0xe8>
 *   @0x1985ec add sp, sp, #20
 *   @0x1985f0 vpop {d8}
 *   @0x1985f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1985f8 ldr r9, [r8]
 *   @0x1985fc mov r3, #1
 *   @0x198600 ldr r1, [sp, #0xc]
 *   @0x198604 mov r2, #70
 *   @0x198608 ldr r5, [r8, #0x10]
 *   @0x19860c lsl r0, r9, r3
 *   @0x198610 str r0, [r8]
 *   @0x198614 add r4, r0, r9, lsl #2
 *   @0x198618 sub r0, r0, #1
 *   @0x19861c str r0, [r8, #0x8]
 *   @0x198620 lsl r4, r4, #2
 *   @0x198624 mov r0, r4
 *   @0x198628 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x19862c mov r2, r4
 *   @0x198630 mov r1, #0
 *   @0x198634 str r0, [r8, #0x10]
 *   @0x198638 bl 0xb65b0 <memset@plt>
 *   @0x19863c ldr r2, [r8]
 *   @0x198640 mov r1, #0
 *   @0x198644 str r1, [r8, #0x4]
 *   @0x198648 cmp r2, r1
 *   @0x19864c vmov s13, r2
 *   @0x198650 vcvt.f32.s32 s15, s13
 *   @0x198654 vmul.f32 s15, s15, s16
 *   @0x198658 vcvt.s32.f32 s15, s15
 *   @0x19865c vstr s15, [r8, #12]
 *   @0x198660 ble 0x198684 <_ZN12YYObjectBase10AssignVarsEPS_+0x3b0>
 *   @0x198664 add r2, r2, r2, lsl #1
 *   @0x198668 ldr r3, [r8, #0x10]
 *   @0x19866c add r2, r3, r2, lsl #2
 *   @0x198670 mov r1, #0
 *   @0x198674 add r3, r3, #12
 *   @0x198678 str r1, [r3, #-0x4]
 *   @0x19867c cmp r3, r2
 *   @0x198680 bne 0x198670 <_ZN12YYObjectBase10AssignVarsEPS_+0x39c>
 *   @0x198684 cmp r9, #0
 *   @0x198688 movgt r4, r5
 *   @0x19868c movgt r10, #0
 *   @0x198690 ble 0x1986bc <_ZN12YYObjectBase10AssignVarsEPS_+0x3e8>
 *   @0x198694 ldr r3, [r4, #0x8]
 *   @0x198698 mov r0, r8
 *   @0x19869c add r10, r10, #1
 *   @0x1986a0 cmp r3, #0
 *   @0x1986a4 ble 0x1986b0 <_ZN12YYObjectBase10AssignVarsEPS_+0x3dc>
 *   @0x1986a8 ldm r4, {r1, r2}
 *   @0x1986ac bl 0x196408 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_>
 *   @0x1986b0 cmp r10, r9
 *   @0x1986b4 add r4, r4, #12
 *   @0x1986b8 bne 0x198694 <_ZN12YYObjectBase10AssignVarsEPS_+0x3c0>
 *   @0x1986bc mov r0, r5
 *   @0x1986c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1986c4 vldr s13, [r8]
 *   @0x1986c8 vcvt.f32.s32 s15, s13
 *   @0x1986cc ldr r3, [r8, #0x4]
 *   @0x1986d0 vmul.f32 s15, s15, s16
 *   @0x1986d4 vcvt.s32.f32 s15, s15
 *   @0x1986d8 vstr s15, [r8, #12]
 *   @0x1986dc b 0x198478 <_ZN12YYObjectBase10AssignVarsEPS_+0x1a4>
 *   @0x1986e0 svclo #0x19999a
 *   @0x1986e4 andseq r8, r9, r4, lsr #26
 *   @0x1986e8 andseq r8, r9, r12, ror r12
 *
 * ══ §9/31 CDS_Priority::Add(RValue*, RValue*)  0x206510  size 1044  261 条（0x206510..0x206924）
 * @func 0x206510 0x206938  size 1064  266 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / _RefThing<char const*>::dec()×2
 * 字段偏移 top8: 0x4×24 / 0x8×14 / 0xc×11 / 0x14×1 / 0x1e0×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x206510 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x206514 mov r6, r1
 *   @0x206518 ldr r3, [r0, #0x8]
 *   @0x20651c mov r4, r0
 *   @0x206520 ldr r1, [r0, #0x4]
 *   @0x206524 mov r5, r2
 *   @0x206528 cmp r1, r3
 *   @0x20652c bge 0x206738 <_ZN12CDS_Priority3AddEP6RValueS1_+0x228>
 *   @0x206530 ldr r8, [r4, #0xc]
 *   @0x206534 lsl r9, r1, #4
 *   @0x206538 add r7, r8, r9
 *   @0x20653c ldr r2, [r7, #0xc]
 *   @0x206540 bic r3, r2, #-16777216
 *   @0x206544 cmp r3, #1
 *   @0x206548 beq 0x2066d0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1c0>
 *   @0x20654c cmp r3, #2
 *   @0x206550 bne 0x206578 <_ZN12CDS_Priority3AddEP6RValueS1_+0x68>
 *   @0x206554 sub r2, r2, #1
 *   @0x206558 bic r2, r2, #-16777216
 *   @0x20655c bic r2, r2, #3
 *   @0x206560 cmp r2, #0
 *   @0x206564 beq 0x206908 <_ZN12CDS_Priority3AddEP6RValueS1_+0x3f8>
 *   @0x206568 mov r2, #0
 *   @0x20656c mov r3, #5
 *   @0x206570 str r2, [r7, #0x8]
 *   @0x206574 str r3, [r7, #0xc]
 *   @0x206578 ldr r3, [r6, #0xc]
 *   @0x20657c mov r1, #0
 *   @0x206580 ldr r2, [r6, #0x8]
 *   @0x206584 str r1, [r8, r9]
 *   @0x206588 str r3, [r7, #0xc]
 *   @0x20658c ldr r3, [r6, #0xc]
 *   @0x206590 str r2, [r7, #0x8]
 *   @0x206594 bic r3, r3, #-16777216
 *   @0x206598 cmp r3, #14
 *   @0x20659c addls pc, pc, r3, lsl #2
 *   @0x2065a0 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8>
 *   @0x2065a4 b 0x2066b0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1a0>
 *   @0x2065a8 b 0x2067b4 <_ZN12CDS_Priority3AddEP6RValueS1_+0x2a4>
 *   @0x2065ac b 0x2067cc <_ZN12CDS_Priority3AddEP6RValueS1_+0x2bc>
 *   @0x2065b0 b 0x2065e0 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd0>
 *   @0x2065b4 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8>
 *   @0x2065b8 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8>
 *   @0x2065bc b 0x2067f8 <_ZN12CDS_Priority3AddEP6RValueS1_+0x2e8>
 *   @0x2065c0 b 0x2065e0 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd0>
 *   @0x2065c4 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8>
 *   @0x2065c8 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8>
 *   @0x2065cc b 0x2066b0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1a0>
 *   @0x2065d0 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8>
 *   @0x2065d4 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8>
 *   @0x2065d8 b 0x2066b0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1a0>
 *   @0x2065dc b 0x2065e0 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd0>
 *   @0x2065e0 ldr r3, [r6]
 *   @0x2065e4 str r3, [r8, r9]
 *   @0x2065e8 ldr r8, [r4, #0x4]
 *   @0x2065ec ldr r7, [r4, #0x14]
 *   @0x2065f0 add r6, r7, r8, lsl #4
 *   @0x2065f4 ldr r2, [r6, #0xc]
 *   @0x2065f8 bic r3, r2, #-16777216
 *   @0x2065fc cmp r3, #1
 *   @0x206600 beq 0x206704 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1f4>
 *   @0x206604 cmp r3, #2
 *   @0x206608 bne 0x206630 <_ZN12CDS_Priority3AddEP6RValueS1_+0x120>
 *   @0x20660c sub r2, r2, #1
 *   @0x206610 bic r2, r2, #-16777216
 *   @0x206614 bic r2, r2, #3
 *   @0x206618 cmp r2, #0
 *   @0x20661c beq 0x206914 <_ZN12CDS_Priority3AddEP6RValueS1_+0x404>
 *   @0x206620 mov r2, #0
 *   @0x206624 mov r3, #5
 *   @0x206628 str r2, [r6, #0x8]
 *   @0x20662c str r3, [r6, #0xc]
 *   @0x206630 ldr r3, [r5, #0xc]
 *   @0x206634 mov r1, #0
 *   @0x206638 ldr r2, [r5, #0x8]
 *   @0x20663c str r1, [r7, r8, lsl #4]
 *   @0x206640 str r3, [r6, #0xc]
 *   @0x206644 ldr r3, [r5, #0xc]
 *   @0x206648 str r2, [r6, #0x8]
 *   @0x20664c bic r3, r3, #-16777216
 *   @0x206650 cmp r3, #14
 *   @0x206654 addls pc, pc, r3, lsl #2
 *   @0x206658 b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190>
 *   @0x20665c b 0x2066c0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1b0>
 *   @0x206660 b 0x206840 <_ZN12CDS_Priority3AddEP6RValueS1_+0x330>
 *   @0x206664 b 0x206788 <_ZN12CDS_Priority3AddEP6RValueS1_+0x278>
 *   @0x206668 b 0x206698 <_ZN12CDS_Priority3AddEP6RValueS1_+0x188>
 *   @0x20666c b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190>
 *   @0x206670 b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190>
 *   @0x206674 b 0x20681c <_ZN12CDS_Priority3AddEP6RValueS1_+0x30c>
 *   @0x206678 b 0x206698 <_ZN12CDS_Priority3AddEP6RValueS1_+0x188>
 *   @0x20667c b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190>
 *   @0x206680 b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190>
 *   @0x206684 b 0x2066c0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1b0>
 *   @0x206688 b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190>
 *   @0x20668c b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190>
 *   @0x206690 b 0x2066c0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1b0>
 *   @0x206694 b 0x206698 <_ZN12CDS_Priority3AddEP6RValueS1_+0x188>
 *   @0x206698 ldr r3, [r5]
 *   @0x20669c str r3, [r7, r8, lsl #4]
 *   @0x2066a0 ldr r3, [r4, #0x4]
 *   @0x2066a4 add r3, r3, #1
 *   @0x2066a8 str r3, [r4, #0x4]
 *   @0x2066ac pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2066b0 ldm r6, {r2, r3}
 *   @0x2066b4 str r2, [r8, r9]
 *   @0x2066b8 str r3, [r7, #0x4]
 *   @0x2066bc b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8>
 *   @0x2066c0 ldm r5, {r2, r3}
 *   @0x2066c4 str r2, [r7, r8, lsl #4]
 *   @0x2066c8 str r3, [r6, #0x4]
 *   @0x2066cc b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190>
 *   @0x2066d0 ldr r10, [r8, r1, lsl #4]
 *   @0x2066d4 cmp r10, #0
 *   @0x2066d8 beq 0x2066f8 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1e8>
 *   @0x2066dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2066e0 ldr r11, [r10, #0x4]
 *   @0x2066e4 sub r11, r11, #1
 *   @0x2066e8 str r11, [r10, #0x4]
 *   @0x2066ec cmp r11, #0
 *   @0x2066f0 beq 0x206858 <_ZN12CDS_Priority3AddEP6RValueS1_+0x348>
 *   @0x2066f4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2066f8 mov r3, #0
 *   @0x2066fc str r3, [r8, r9]
 *   @0x206700 b 0x206578 <_ZN12CDS_Priority3AddEP6RValueS1_+0x68>
 *   @0x206704 ldr r9, [r7, r8, lsl #4]
 *   @0x206708 cmp r9, #0
 *   @0x20670c beq 0x20672c <_ZN12CDS_Priority3AddEP6RValueS1_+0x21c>
 *   @0x206710 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x206714 ldr r10, [r9, #0x4]
 *   @0x206718 sub r10, r10, #1
 *   @0x20671c str r10, [r9, #0x4]
 *   @0x206720 cmp r10, #0
 *   @0x206724 beq 0x2068b0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x3a0>
 *   @0x206728 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20672c mov r3, #0
 *   @0x206730 str r3, [r7, r8, lsl #4]
 *   @0x206734 b 0x206630 <_ZN12CDS_Priority3AddEP6RValueS1_+0x120>
 *   @0x206738 ldr r7, [pc, #0x1e0]
 *   @0x20673c add r1, r1, #16
 *   @0x206740 add r0, r0, #12
 *   @0x206744 movw r3, #0xa5b
 *   @0x206748 add r7, pc, r7
 *   @0x20674c lsl r1, r1, #4
 *   @0x206750 mov r2, r7
 *   @0x206754 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x206758 ldr r1, [r4, #0x4]
 *   @0x20675c movw r3, #0xa5d
 *   @0x206760 mov r2, r7
 *   @0x206764 add r1, r1, #16
 *   @0x206768 add r0, r4, #20
 *   @0x20676c str r1, [r4, #0x8]
 *   @0x206770 lsl r1, r1, #4
 *   @0x206774 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x206778 ldr r1, [r4, #0x4]
 *   @0x20677c add r3, r1, #16
 *   @0x206780 str r3, [r4, #0x10]
 *   @0x206784 b 0x206530 <_ZN12CDS_Priority3AddEP6RValueS1_+0x20>
 *   @0x206788 ldr r3, [r5]
 *   @0x20678c cmp r3, #0
 *   @0x206790 str r3, [r7, r8, lsl #4]
 *   @0x206794 beq 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190>
 *   @0x206798 ldr r1, [r3, #0x8]
 *   @0x20679c ldr r2, [r3]
 *   @0x2067a0 cmp r1, #0
 *   @0x2067a4 streq r6, [r3, #0x8]
 *   @0x2067a8 add r2, r2, #1
 *   @0x2067ac str r2, [r3]
 *   @0x2067b0 b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190>
 *   @0x2067b4 ldr r3, [r6]
 *   @0x2067b8 cmp r3, #0
 *   @0x2067bc ldrne r2, [r3, #0x4]
 *   @0x2067c0 addne r2, r2, #1
 *   @0x2067c4 strne r2, [r3, #0x4]
 *   @0x2067c8 b 0x2065e4 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd4>
 *   @0x2067cc ldr r3, [r6]
 *   @0x2067d0 cmp r3, #0
 *   @0x2067d4 str r3, [r8, r9]
 *   @0x2067d8 beq 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8>
 *   @0x2067dc ldr r1, [r3, #0x8]
 *   @0x2067e0 ldr r2, [r3]
 *   @0x2067e4 cmp r1, #0
 *   @0x2067e8 streq r7, [r3, #0x8]
 *   @0x2067ec add r2, r2, #1
 *   @0x2067f0 str r2, [r3]
 *   @0x2067f4 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8>
 *   @0x2067f8 ldr r3, [r6]
 *   @0x2067fc str r3, [r8, r9]
 *   @0x206800 ldr r3, [r6]
 *   @0x206804 cmp r3, #0
 *   @0x206808 beq 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8>
 *   @0x20680c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x206810 ldr r1, [r6]
 *   @0x206814 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x206818 b 0x2065e8 <_ZN12CDS_Priority3AddEP6RValueS1_+0xd8>
 *   @0x20681c ldr r3, [r5]
 *   @0x206820 str r3, [r7, r8, lsl #4]
 *   @0x206824 ldr r3, [r5]
 *   @0x206828 cmp r3, #0
 *   @0x20682c beq 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190>
 *   @0x206830 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x206834 ldr r1, [r5]
 *   @0x206838 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20683c b 0x2066a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x190>
 *   @0x206840 ldr r3, [r5]
 *   @0x206844 cmp r3, #0
 *   @0x206848 ldrne r2, [r3, #0x4]
 *   @0x20684c addne r2, r2, #1
 *   @0x206850 strne r2, [r3, #0x4]
 *   @0x206854 b 0x20669c <_ZN12CDS_Priority3AddEP6RValueS1_+0x18c>
 *   @0x206858 ldr r0, [r10]
 *   @0x20685c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x206860 str r11, [r10]
 *   @0x206864 str r11, [r10, #0x8]
 *   @0x206868 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20686c ldr r11, [r10, #0x4]
 *   @0x206870 sub r11, r11, #1
 *   @0x206874 str r11, [r10, #0x4]
 *   @0x206878 cmp r11, #0
 *   @0x20687c bne 0x2068a0 <_ZN12CDS_Priority3AddEP6RValueS1_+0x390>
 *   @0x206880 ldr r0, [r10]
 *   @0x206884 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x206888 mov r0, r10
 *   @0x20688c str r11, [r10]
 *   @0x206890 str r11, [r10, #0x8]
 *   @0x206894 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x206898 mov r0, r10
 *   @0x20689c bl 0x27d1d0 <_ZdlPv>
 *   @0x2068a0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2068a4 mov r0, r10
 *   @0x2068a8 bl 0x27d1d0 <_ZdlPv>
 *   @0x2068ac b 0x2066f4 <_ZN12CDS_Priority3AddEP6RValueS1_+0x1e4>
 *   @0x2068b0 ldr r0, [r9]
 *   @0x2068b4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2068b8 str r10, [r9]
 *   @0x2068bc str r10, [r9, #0x8]
 *   @0x2068c0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2068c4 ldr r10, [r9, #0x4]
 *   @0x2068c8 sub r10, r10, #1
 *   @0x2068cc str r10, [r9, #0x4]
 *   @0x2068d0 cmp r10, #0
 *   @0x2068d4 bne 0x2068f8 <_ZN12CDS_Priority3AddEP6RValueS1_+0x3e8>
 *   @0x2068d8 ldr r0, [r9]
 *   @0x2068dc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2068e0 mov r0, r9
 *   @0x2068e4 str r10, [r9]
 *   @0x2068e8 str r10, [r9, #0x8]
 *   @0x2068ec bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x2068f0 mov r0, r9
 *   @0x2068f4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2068f8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2068fc mov r0, r9
 *   @0x206900 bl 0x27d1d0 <_ZdlPv>
 *   @0x206904 b 0x206728 <_ZN12CDS_Priority3AddEP6RValueS1_+0x218>
 *   @0x206908 mov r0, r7
 *   @0x20690c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x206910 b 0x206568 <_ZN12CDS_Priority3AddEP6RValueS1_+0x58>
 *   @0x206914 mov r0, r6
 *   @0x206918 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20691c b 0x206620 <_ZN12CDS_Priority3AddEP6RValueS1_+0x110>
 *   @0x206920 andseq sp, r4, r4, lsr #1
 *
 * ══ §10/31 Sprite_Load(unsigned char*, int, unsigned char*)  0x1effbc  size 1040  260 条（0x1effbc..0x1f03cc）
 * @func 0x1effbc 0x1f03cc  size 1040  260 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1effd0→0x7530d8, 0x1effe8→0x7530d0, 0x1f0034→0x7530dc, 0x1f00a4→0x544c44, 0x1f0120→0x7530e0
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / MemoryManager::Free(void const*)×2 / operator new(unsigned int) / CSprite::CSprite() / CSprite::LoadFromChunk(YYSprite*, unsigned char*) / 0xb6538 / 0xb65a4
 * 字段偏移 top8: 0x4×18 / 0x8×13 / 0x10×7 / 0x1c×6 / 0xc×6 / 0x14×5 / 0x20×4 / 0x18×3
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1effbc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1effc0 vpush {d8}
 *   @0x1effc4 sub sp, sp, #52
 *   @0x1effc8 ldr r12, [pc, #0x3d8]
 *   @0x1effcc mov r3, #228
 *   @0x1effd0 ldr r1, [pc, #0x3d4]
 *   @0x1effd4 mov r5, r0
 *   @0x1effd8 add r12, pc, r12
 *   @0x1effdc str r12, [sp, #0x1c]
 *   @0x1effe0 ldr r12, [r0]
 *   @0x1effe4 str r2, [sp, #0x24]
 *   @0x1effe8 ldr r2, [pc, #0x3c0]
 *   @0x1effec str r12, [sp, #0x20]
 *   @0x1efff0 ldr r12, [sp, #0x1c]
 *   @0x1efff4 ldr r6, [pc, #0x3b8]
 *   @0x1efff8 ldr r4, [r12, r1]
 *   @0x1efffc add r6, pc, r6
 *   @0x1f0000 ldr r12, [sp, #0x20]
 *   @0x1f0004 lsl r1, r12, #2
 *   @0x1f0008 str r12, [r4]
 *   @0x1f000c ldr r12, [sp, #0x1c]
 *   @0x1f0010 ldr r2, [r12, r2]
 *   @0x1f0014 str r2, [sp, #0x14]
 *   @0x1f0018 mov r2, r6
 *   @0x1f001c ldr r12, [sp, #0x14]
 *   @0x1f0020 add r0, r12, #4
 *   @0x1f0024 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1f0028 ldr r1, [r4]
 *   @0x1f002c ldr r12, [sp, #0x14]
 *   @0x1f0030 mov r2, r6
 *   @0x1f0034 ldr r0, [pc, #0x37c]
 *   @0x1f0038 mov r3, #230
 *   @0x1f003c str r1, [r12]
 *   @0x1f0040 lsl r1, r1, #2
 *   @0x1f0044 ldr r12, [sp, #0x1c]
 *   @0x1f0048 ldr r0, [r12, r0]
 *   @0x1f004c str r0, [sp, #0xc]
 *   @0x1f0050 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1f0054 ldr r12, [sp, #0x20]
 *   @0x1f0058 cmp r12, #0
 *   @0x1f005c beq 0x1f0298 <_Z11Sprite_LoadPhiS_+0x2dc>
 *   @0x1f0060 ldr r12, [pc, #0x354]
 *   @0x1f0064 vldr s16, [pc, #824]
 *   @0x1f0068 str r5, [sp, #0x18]
 *   @0x1f006c add r12, pc, r12
 *   @0x1f0070 str r12, [sp, #0x28]
 *   @0x1f0074 mov r12, #0
 *   @0x1f0078 str r12, [sp, #0x4]
 *   @0x1f007c ldr r12, [pc, #0x33c]
 *   @0x1f0080 add r12, pc, r12
 *   @0x1f0084 str r12, [sp, #0x2c]
 *   @0x1f0088 ldr r12, [sp, #0x18]
 *   @0x1f008c ldr r5, [r12, #0x4]!
 *   @0x1f0090 cmp r5, #0
 *   @0x1f0094 str r12, [sp, #0x18]
 *   @0x1f0098 streq r5, [sp, #0x8]
 *   @0x1f009c streq r5, [sp, #0x10]
 *   @0x1f00a0 beq 0x1f020c <_Z11Sprite_LoadPhiS_+0x250>
 *   @0x1f00a4 ldr r3, [pc, #0x318]
 *   @0x1f00a8 ldr r12, [sp, #0x1c]
 *   @0x1f00ac ldr r4, [r12, r3]
 *   @0x1f00b0 ldr r6, [r4]
 *   @0x1f00b4 adds r7, r6, r5
 *   @0x1f00b8 streq r7, [sp, #0x8]
 *   @0x1f00bc streq r7, [sp, #0x10]
 *   @0x1f00c0 beq 0x1f020c <_Z11Sprite_LoadPhiS_+0x250>
 *   @0x1f00c4 mov r0, #136
 *   @0x1f00c8 bl 0x27c524 <_Znwj>
 *   @0x1f00cc str r0, [sp, #0x10]
 *   @0x1f00d0 bl 0x1e761c <_ZN7CSpriteC2Ev>
 *   @0x1f00d4 mov r1, r7
 *   @0x1f00d8 ldr r2, [sp, #0x24]
 *   @0x1f00dc ldr r0, [sp, #0x10]
 *   @0x1f00e0 bl 0x1e972c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh>
 *   @0x1f00e4 ldr r3, [r6, r5]
 *   @0x1f00e8 cmp r3, #0
 *   @0x1f00ec ldrne r4, [r4]
 *   @0x1f00f0 moveq r4, r3
 *   @0x1f00f4 addne r4, r4, r3
 *   @0x1f00f8 mov r0, r4
 *   @0x1f00fc bl 0xb6538 <strlen@plt>
 *   @0x1f0100 mov r3, #1
 *   @0x1f0104 mov r2, #242
 *   @0x1f0108 ldr r1, [sp, #0x28]
 *   @0x1f010c add r0, r0, r3
 *   @0x1f0110 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1f0114 mov r1, r4
 *   @0x1f0118 str r0, [sp, #0x8]
 *   @0x1f011c bl 0xb65a4 <strcpy@plt>
 *   @0x1f0120 ldr r3, [pc, #0x2a0]
 *   @0x1f0124 ldr r12, [sp, #0x1c]
 *   @0x1f0128 ldr r8, [r12, r3]
 *   @0x1f012c ldr r3, [r8, #0x4]
 *   @0x1f0130 ldr r2, [r8, #0xc]
 *   @0x1f0134 cmp r3, r2
 *   @0x1f0138 bgt 0x1f02bc <_Z11Sprite_LoadPhiS_+0x300>
 *   @0x1f013c ldr r0, [sp, #0x8]
 *   @0x1f0140 add r3, r3, #1
 *   @0x1f0144 str r3, [r8, #0x4]
 *   @0x1f0148 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x1f014c ldr r4, [r8, #0x8]
 *   @0x1f0150 ldr r10, [r8, #0x10]
 *   @0x1f0154 bic r7, r0, #-2147483648
 *   @0x1f0158 and r3, r7, r4
 *   @0x1f015c add r2, r3, r3, lsl #1
 *   @0x1f0160 add r2, r10, r2, lsl #2
 *   @0x1f0164 ldr r1, [r2, #0x8]
 *   @0x1f0168 cmp r1, #0
 *   @0x1f016c beq 0x1f02a8 <_Z11Sprite_LoadPhiS_+0x2ec>
 *   @0x1f0170 ldr r11, [r8]
 *   @0x1f0174 mov r5, #0
 *   @0x1f0178 ldr r9, [sp, #0x4]
 *   @0x1f017c ldr r0, [sp, #0x8]
 *   @0x1f0180 b 0x1f01c4 <_Z11Sprite_LoadPhiS_+0x208>
 *   @0x1f0184 ldr r6, [r2]
 *   @0x1f0188 ldr r5, [r2, #0x4]
 *   @0x1f018c str r7, [r2, #0x8]
 *   @0x1f0190 mov r7, r1
 *   @0x1f0194 str r0, [r2]
 *   @0x1f0198 mov r0, r6
 *   @0x1f019c str r9, [r2, #0x4]
 *   @0x1f01a0 mov r9, r5
 *   @0x1f01a4 add r3, r3, #1
 *   @0x1f01a8 add r5, r12, #1
 *   @0x1f01ac and r3, r3, r4
 *   @0x1f01b0 add r2, r3, r3, lsl #1
 *   @0x1f01b4 add r2, r10, r2, lsl #2
 *   @0x1f01b8 ldr r1, [r2, #0x8]
 *   @0x1f01bc cmp r1, #0
 *   @0x1f01c0 beq 0x1f02b0 <_Z11Sprite_LoadPhiS_+0x2f4>
 *   @0x1f01c4 add r12, r3, r11
 *   @0x1f01c8 and r6, r1, r4
 *   @0x1f01cc rsb r12, r6, r12
 *   @0x1f01d0 and r12, r12, r4
 *   @0x1f01d4 cmp r12, r5
 *   @0x1f01d8 blt 0x1f0184 <_Z11Sprite_LoadPhiS_+0x1c8>
 *   @0x1f01dc movne r12, r5
 *   @0x1f01e0 bne 0x1f01a4 <_Z11Sprite_LoadPhiS_+0x1e8>
 *   @0x1f01e4 cmp r1, r7
 *   @0x1f01e8 bne 0x1f01a4 <_Z11Sprite_LoadPhiS_+0x1e8>
 *   @0x1f01ec ldr r5, [r2]
 *   @0x1f01f0 cmp r0, r5
 *   @0x1f01f4 bne 0x1f01a4 <_Z11Sprite_LoadPhiS_+0x1e8>
 *   @0x1f01f8 ldr r3, [r8, #0x4]
 *   @0x1f01fc str r1, [r2, #0x8]
 *   @0x1f0200 stm r2, {r0, r9}
 *   @0x1f0204 sub r3, r3, #1
 *   @0x1f0208 str r3, [r8, #0x4]
 *   @0x1f020c ldr r12, [sp, #0xc]
 *   @0x1f0210 ldr r3, [r12]
 *   @0x1f0214 ldr r12, [sp, #0x4]
 *   @0x1f0218 ldr r0, [r3, r12, lsl #2]
 *   @0x1f021c lsl r4, r12, #2
 *   @0x1f0220 cmp r0, #0
 *   @0x1f0224 beq 0x1f0240 <_Z11Sprite_LoadPhiS_+0x284>
 *   @0x1f0228 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f022c ldr r12, [sp, #0xc]
 *   @0x1f0230 mov r0, #0
 *   @0x1f0234 ldr r3, [r12]
 *   @0x1f0238 ldr r12, [sp, #0x4]
 *   @0x1f023c str r0, [r3, r12, lsl #2]
 *   @0x1f0240 ldr r12, [sp, #0x14]
 *   @0x1f0244 ldr r0, [sp, #0x20]
 *   @0x1f0248 ldr r3, [r12, #0x4]
 *   @0x1f024c ldr r12, [sp, #0x10]
 *   @0x1f0250 str r12, [r3, r4]
 *   @0x1f0254 ldr r12, [sp, #0xc]
 *   @0x1f0258 ldr r3, [r12]
 *   @0x1f025c ldr r12, [sp, #0x8]
 *   @0x1f0260 str r12, [r3, r4]
 *   @0x1f0264 ldr r12, [sp, #0x14]
 *   @0x1f0268 ldr r3, [r12, #0x4]
 *   @0x1f026c ldr r12, [sp, #0xc]
 *   @0x1f0270 ldr r3, [r3, r4]
 *   @0x1f0274 ldr r2, [r12]
 *   @0x1f0278 ldr r12, [sp, #0x4]
 *   @0x1f027c ldr r2, [r2, r4]
 *   @0x1f0280 str r12, [r3, #0x60]
 *   @0x1f0284 add r12, r12, #1
 *   @0x1f0288 cmp r12, r0
 *   @0x1f028c str r12, [sp, #0x4]
 *   @0x1f0290 str r2, [r3, #0x5c]
 *   @0x1f0294 bne 0x1f0088 <_Z11Sprite_LoadPhiS_+0xcc>
 *   @0x1f0298 mov r0, #1
 *   @0x1f029c add sp, sp, #52
 *   @0x1f02a0 vpop {d8}
 *   @0x1f02a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f02a8 ldr r9, [sp, #0x4]
 *   @0x1f02ac ldr r0, [sp, #0x8]
 *   @0x1f02b0 stm r2, {r0, r9}
 *   @0x1f02b4 str r7, [r2, #0x8]
 *   @0x1f02b8 b 0x1f020c <_Z11Sprite_LoadPhiS_+0x250>
 *   @0x1f02bc ldr r5, [r8]
 *   @0x1f02c0 mov r3, #1
 *   @0x1f02c4 ldr r1, [sp, #0x2c]
 *   @0x1f02c8 mov r2, #70
 *   @0x1f02cc ldr r7, [r8, #0x10]
 *   @0x1f02d0 lsl r0, r5, r3
 *   @0x1f02d4 str r0, [r8]
 *   @0x1f02d8 add r4, r0, r5, lsl #2
 *   @0x1f02dc sub r0, r0, #1
 *   @0x1f02e0 str r0, [r8, #0x8]
 *   @0x1f02e4 lsl r4, r4, #2
 *   @0x1f02e8 mov r0, r4
 *   @0x1f02ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1f02f0 mov r2, r4
 *   @0x1f02f4 mov r1, #0
 *   @0x1f02f8 str r0, [r8, #0x10]
 *   @0x1f02fc bl 0xb65b0 <memset@plt>
 *   @0x1f0300 ldr r2, [r8]
 *   @0x1f0304 mov r0, #0
 *   @0x1f0308 str r0, [r8, #0x4]
 *   @0x1f030c cmp r2, r0
 *   @0x1f0310 vmov s14, r2
 *   @0x1f0314 vcvt.f32.s32 s15, s14
 *   @0x1f0318 vmul.f32 s15, s15, s16
 *   @0x1f031c vcvt.s32.f32 s15, s15
 *   @0x1f0320 vstr s15, [r8, #12]
 *   @0x1f0324 ble 0x1f0348 <_Z11Sprite_LoadPhiS_+0x38c>
 *   @0x1f0328 add r2, r2, r2, lsl #1
 *   @0x1f032c ldr r3, [r8, #0x10]
 *   @0x1f0330 add r2, r3, r2, lsl #2
 *   @0x1f0334 mov r0, #0
 *   @0x1f0338 add r3, r3, #12
 *   @0x1f033c str r0, [r3, #-0x4]
 *   @0x1f0340 cmp r3, r2
 *   @0x1f0344 bne 0x1f0334 <_Z11Sprite_LoadPhiS_+0x378>
 *   @0x1f0348 cmp r5, #0
 *   @0x1f034c movgt r4, r7
 *   @0x1f0350 movgt r6, #0
 *   @0x1f0354 ble 0x1f0380 <_Z11Sprite_LoadPhiS_+0x3c4>
 *   @0x1f0358 ldr r3, [r4, #0x8]
 *   @0x1f035c mov r0, r8
 *   @0x1f0360 add r6, r6, #1
 *   @0x1f0364 cmp r3, #0
 *   @0x1f0368 ble 0x1f0374 <_Z11Sprite_LoadPhiS_+0x3b8>
 *   @0x1f036c ldm r4, {r1, r2}
 *   @0x1f0370 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i>
 *   @0x1f0374 cmp r6, r5
 *   @0x1f0378 add r4, r4, #12
 *   @0x1f037c bne 0x1f0358 <_Z11Sprite_LoadPhiS_+0x39c>
 *   @0x1f0380 mov r0, r7
 *   @0x1f0384 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f0388 vldr s14, [r8]
 *   @0x1f038c vcvt.f32.s32 s15, s14
 *   @0x1f0390 ldr r3, [r8, #0x4]
 *   @0x1f0394 vmul.f32 s15, s15, s16
 *   @0x1f0398 vcvt.s32.f32 s15, s15
 *   @0x1f039c vstr s15, [r8, #12]
 *   @0x1f03a0 b 0x1f013c <_Z11Sprite_LoadPhiS_+0x180>
 *   @0x1f03a4 svclo #0x19999a
 *   @0x1f03a8 eoreq r1, r0, r8, ror r12
 *   @0x1f03ac .word 0xfffff1c0
 *   @0x1f03b0 .word 0xfffff1b8
 *   @0x1f03b4 andseq r2, r6, r4, asr #12
 *   @0x1f03b8 .word 0xfffff1bc
 *   @0x1f03bc ldrsbeq r2, [r6], -r4
 *   @0x1f03c0 ldrheq r0, [r4], -r0
 *   @0x1f03c4 .word 0xffffbcf4
 *   @0x1f03c8 .word 0xfffff1c4
 *
 * ══ §11/31 JS_String_prototype_replace_RegEx(RValue&, CInstance*, CInstance*, YYObjectBase*, RValue*, RValue*)  0x258e3c  size 1040  260 条（0x258e3c..0x25924c）
 * @func 0x258e3c 0x25924c  size 1040  260 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DoRegExpExec(YYObjectBase*, char const*, int, int*, int, int*, int)×2 / pcre_get_substring×2 / DoReplace(YYStrBuilder&, CInstance*, bool, RValue*, RValue*, int, SMatches**, int, int)×2 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*) / YYGetBool(RValue const*, int) / JS_IsCallable(RValue&) / F_JS_ToString(RValue&, RValue*) / YYGetString(RValue const*, int)
 * 字段偏移 top8: 0x4×10 / 0x-394×6 / 0x8×6 / 0x-3a0×6 / 0x-390×6 / 0x-388×5 / 0x-3ac×4 / 0x-3a8×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x258e3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x258e40 add r11, sp, #32
 *   @0x258e44 sub sp, sp, #948
 *   @0x258e48 ldr r2, [pc, #0x3ec]
 *   @0x258e4c str r3, [r11, #-0x394]
 *   @0x258e50 ldr r3, [r11, #0x8]
 *   @0x258e54 ldr r2, [pc, r2]
 *   @0x258e58 ldr lr, [r11, #0x4]
 *   @0x258e5c sub r4, r11, #888
 *   @0x258e60 str r2, [r11, #-0x3a4]
 *   @0x258e64 mov r5, #0
 *   @0x258e68 str r3, [r11, #-0x3a0]
 *   @0x258e6c ldr r3, [r2]
 *   @0x258e70 ldr r2, [pc, #0x3c8]
 *   @0x258e74 str r0, [r11, #-0x3b8]
 *   @0x258e78 add r2, pc, r2
 *   @0x258e7c str r1, [r11, #-0x3b0]
 *   @0x258e80 ldr r0, [r11, #-0x394]
 *   @0x258e84 mov r1, r4
 *   @0x258e88 str r3, [r11, #-0x28]
 *   @0x258e8c str lr, [r11, #-0x3ac]
 *   @0x258e90 str r5, [r11, #-0x378]
 *   @0x258e94 str r5, [r11, #-0x374]
 *   @0x258e98 str r5, [r11, #-0x370]
 *   @0x258e9c str r5, [r11, #-0x36c]
 *   @0x258ea0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x258ea4 mov r0, r4
 *   @0x258ea8 mov r1, r5
 *   @0x258eac bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x258eb0 str r5, [r11, #-0x368]
 *   @0x258eb4 str r5, [r11, #-0x364]
 *   @0x258eb8 str r5, [r11, #-0x360]
 *   @0x258ebc str r5, [r11, #-0x35c]
 *   @0x258ec0 mov r4, r0
 *   @0x258ec4 ldr r0, [r11, #-0x3a0]
 *   @0x258ec8 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x258ecc cmp r0, #0
 *   @0x258ed0 str r0, [r11, #-0x3a8]
 *   @0x258ed4 bne 0x25908c <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x250>
 *   @0x258ed8 ldr r2, [r11, #-0x3a8]
 *   @0x258edc sub r0, r11, #872
 *   @0x258ee0 ldr r1, [r11, #-0x3a0]
 *   @0x258ee4 mvn r3, #-16777216
 *   @0x258ee8 str r3, [r11, #-0x35c]
 *   @0x258eec str r2, [r11, #-0x368]
 *   @0x258ef0 str r2, [r11, #-0x364]
 *   @0x258ef4 str r2, [r11, #-0x360]
 *   @0x258ef8 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x258efc cmp r0, #1
 *   @0x258f00 beq 0x259228 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x3ec>
 *   @0x258f04 mov r5, #0
 *   @0x258f08 ldr r0, [r11, #-0x3ac]
 *   @0x258f0c mov r1, r5
 *   @0x258f10 str r5, [r11, #-0x384]
 *   @0x258f14 str r5, [r11, #-0x380]
 *   @0x258f18 str r5, [r11, #-0x37c]
 *   @0x258f1c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x258f20 mov r6, r0
 *   @0x258f24 bl 0xb6538 <strlen@plt>
 *   @0x258f28 ldr lr, [r11, #-0x394]
 *   @0x258f2c mov r2, #2
 *   @0x258f30 sub r3, r11, #908
 *   @0x258f34 str r5, [r11, #-0x388]
 *   @0x258f38 ldr r1, [lr, #0x20]
 *   @0x258f3c str r0, [r11, #-0x398]
 *   @0x258f40 ldr r0, [lr, #0x1c]
 *   @0x258f44 bl 0x25ee20 <pcre_fullinfo>
 *   @0x258f48 cmp r4, r5
 *   @0x258f4c bne 0x2590ac <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x270>
 *   @0x258f50 sub r5, r11, #840
 *   @0x258f54 str r4, [sp, #0x8]
 *   @0x258f58 ldr r2, [r11, #-0x398]
 *   @0x258f5c mov r1, #100
 *   @0x258f60 mov r3, r5
 *   @0x258f64 str r1, [sp]
 *   @0x258f68 ldr r0, [r11, #-0x394]
 *   @0x258f6c sub r1, r11, #904
 *   @0x258f70 str r1, [sp, #0x4]
 *   @0x258f74 mov r1, r6
 *   @0x258f78 bl 0x24f2b0 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i>
 *   @0x258f7c ldr r2, [r11, #-0x388]
 *   @0x258f80 cmp r2, #0
 *   @0x258f84 add r3, r2, r2, lsl #1
 *   @0x258f88 str r2, [r11, #-0x1b8]
 *   @0x258f8c movgt r8, r4
 *   @0x258f90 movgt r7, r5
 *   @0x258f94 lsl r3, r3, #2
 *   @0x258f98 add r3, r3, #14
 *   @0x258f9c bic r3, r3, #7
 *   @0x258fa0 sub sp, sp, r3
 *   @0x258fa4 add r1, sp, #24
 *   @0x258fa8 str r1, [r11, #-0x1b4]
 *   @0x258fac mov r9, r0
 *   @0x258fb0 bgt 0x258fbc <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x180>
 *   @0x258fb4 b 0x259000 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x1c4>
 *   @0x258fb8 ldr r1, [r11, #-0x1b4]
 *   @0x258fbc ldr r0, [r7]
 *   @0x258fc0 add r3, r1, r4
 *   @0x258fc4 add r12, r3, #8
 *   @0x258fc8 add r7, r7, #8
 *   @0x258fcc str r0, [r1, r4]
 *   @0x258fd0 mov r0, r6
 *   @0x258fd4 ldr lr, [r7, #-0x4]
 *   @0x258fd8 mov r1, r5
 *   @0x258fdc add r4, r4, #12
 *   @0x258fe0 str lr, [r3, #0x4]
 *   @0x258fe4 mov r3, r8
 *   @0x258fe8 str r12, [sp]
 *   @0x258fec add r8, r8, #1
 *   @0x258ff0 bl 0x25f5e8 <pcre_get_substring>
 *   @0x258ff4 ldr r2, [r11, #-0x388]
 *   @0x258ff8 cmp r2, r8
 *   @0x258ffc bgt 0x258fb8 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x17c>
 *   @0x259000 ldr r1, [r11, #-0x3ac]
 *   @0x259004 mov r0, #0
 *   @0x259008 mov r12, #1
 *   @0x25900c str r0, [sp, #0x4]
 *   @0x259010 str r12, [sp, #0xc]
 *   @0x259014 sub r0, r11, #856
 *   @0x259018 str r1, [sp]
 *   @0x25901c sub r12, r11, #440
 *   @0x259020 str r0, [sp, #0x8]
 *   @0x259024 sub r0, r11, #900
 *   @0x259028 ldr r1, [r11, #-0x3b0]
 *   @0x25902c str r9, [sp, #0x10]
 *   @0x259030 ldr r2, [r11, #-0x3a8]
 *   @0x259034 ldr r3, [r11, #-0x3a0]
 *   @0x259038 str r12, [r11, #-0x358]
 *   @0x25903c bl 0x24a99c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii>
 *   @0x259040 ldr r3, [r11, #-0x37c]
 *   @0x259044 ldr r0, [r11, #-0x3b8]
 *   @0x259048 cmp r3, #0
 *   @0x25904c mov r3, #0
 *   @0x259050 subeq r1, r11, #892
 *   @0x259054 str r3, [r11, #-0x37c]
 *   @0x259058 ldrne r1, [r11, #-0x384]
 *   @0x25905c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x259060 ldr r0, [r11, #-0x384]
 *   @0x259064 cmp r0, #0
 *   @0x259068 beq 0x259070 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x234>
 *   @0x25906c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x259070 ldr r1, [r11, #-0x3a4]
 *   @0x259074 ldr r2, [r11, #-0x28]
 *   @0x259078 ldr r3, [r1]
 *   @0x25907c cmp r2, r3
 *   @0x259080 bne 0x259238 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x3fc>
 *   @0x259084 sub sp, r11, #32
 *   @0x259088 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x25908c ldr r3, [r11, #-0x3a0]
 *   @0x259090 sub r12, r11, #872
 *   @0x259094 ldr r0, [r3]
 *   @0x259098 ldr r1, [r3, #0x4]
 *   @0x25909c ldr r2, [r3, #0x8]
 *   @0x2590a0 ldr r3, [r3, #0xc]
 *   @0x2590a4 stm r12!, {r0, r1, r2, r3}
 *   @0x2590a8 b 0x258f04 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0xc8>
 *   @0x2590ac sub r2, r11, #440
 *   @0x2590b0 str r2, [r11, #-0x3b4]
 *   @0x2590b4 ldr r2, [pc, #0x188]
 *   @0x2590b8 mov r3, r5
 *   @0x2590bc ldr r0, [r11, #-0x394]
 *   @0x2590c0 sub r1, r11, #856
 *   @0x2590c4 add r2, pc, r2
 *   @0x2590c8 str r5, [r11, #-0x34c]
 *   @0x2590cc str r5, [r11, #-0x358]
 *   @0x2590d0 str r5, [r11, #-0x390]
 *   @0x2590d4 str r5, [r11, #-0x354]
 *   @0x2590d8 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x2590dc mov r1, r5
 *   @0x2590e0 sub r5, r11, #840
 *   @0x2590e4 sub r0, r11, #440
 *   @0x2590e8 mov r2, #400
 *   @0x2590ec ldr r9, [r11, #-0x390]
 *   @0x2590f0 bl 0xb65b0 <memset@plt>
 *   @0x2590f4 sub r3, r11, #904
 *   @0x2590f8 str r3, [r11, #-0x39c]
 *   @0x2590fc mov r3, #100
 *   @0x259100 sub lr, r11, #904
 *   @0x259104 str r3, [sp]
 *   @0x259108 mov r1, r6
 *   @0x25910c ldr r0, [r11, #-0x394]
 *   @0x259110 mov r3, r5
 *   @0x259114 str lr, [sp, #0x4]
 *   @0x259118 str r9, [sp, #0x8]
 *   @0x25911c ldr r2, [r11, #-0x398]
 *   @0x259120 bl 0x24f2b0 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i>
 *   @0x259124 cmn r0, #1
 *   @0x259128 mov r8, r0
 *   @0x25912c beq 0x2591ec <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x3b0>
 *   @0x259130 ldr r2, [r11, #-0x388]
 *   @0x259134 sub sp, sp, #24
 *   @0x259138 add r7, sp, #24
 *   @0x25913c cmp r2, #0
 *   @0x259140 add r3, r2, r2, lsl #1
 *   @0x259144 str r2, [r7]
 *   @0x259148 movgt r10, r5
 *   @0x25914c movgt r4, #0
 *   @0x259150 lsl r3, r3, #2
 *   @0x259154 add r3, r3, #14
 *   @0x259158 bic r3, r3, #7
 *   @0x25915c sub sp, sp, r3
 *   @0x259160 add r3, sp, #24
 *   @0x259164 str r3, [r7, #0x4]
 *   @0x259168 bgt 0x259174 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x338>
 *   @0x25916c b 0x2591b8 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x37c>
 *   @0x259170 ldr r3, [r7, #0x4]
 *   @0x259174 ldr r12, [r10]
 *   @0x259178 add r1, r4, r4, lsl #1
 *   @0x25917c mov r0, r6
 *   @0x259180 add r10, r10, #8
 *   @0x259184 str r12, [r3, r1, lsl #2]
 *   @0x259188 add r3, r3, r1, lsl #2
 *   @0x25918c ldr lr, [r10, #-0x4]
 *   @0x259190 add r12, r3, #8
 *   @0x259194 mov r1, r5
 *   @0x259198 str lr, [r3, #0x4]
 *   @0x25919c mov r3, r4
 *   @0x2591a0 str r12, [sp]
 *   @0x2591a4 add r4, r4, #1
 *   @0x2591a8 bl 0x25f5e8 <pcre_get_substring>
 *   @0x2591ac ldr r2, [r11, #-0x388]
 *   @0x2591b0 cmp r2, r4
 *   @0x2591b4 bgt 0x259170 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x334>
 *   @0x2591b8 ldr lr, [r11, #-0x390]
 *   @0x2591bc cmp lr, #99
 *   @0x2591c0 bhi 0x2591dc <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x3a0>
 *   @0x2591c4 ldr r1, [r11, #-0x390]
 *   @0x2591c8 sub r2, r11, #36
 *   @0x2591cc add r3, r2, r1, lsl #2
 *   @0x2591d0 add r1, r1, #1
 *   @0x2591d4 str r1, [r11, #-0x390]
 *   @0x2591d8 str r7, [r3, #-0x194]
 *   @0x2591dc cmp r9, r8
 *   @0x2591e0 addeq r8, r8, #1
 *   @0x2591e4 mov r9, r8
 *   @0x2591e8 b 0x2590fc <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x2c0>
 *   @0x2591ec ldr r1, [r11, #-0x3ac]
 *   @0x2591f0 sub r2, r11, #440
 *   @0x2591f4 ldr r3, [r11, #-0x390]
 *   @0x2591f8 mov r12, #0
 *   @0x2591fc str r2, [sp, #0x8]
 *   @0x259200 sub r0, r11, #900
 *   @0x259204 str r1, [sp]
 *   @0x259208 str r3, [sp, #0xc]
 *   @0x25920c ldr r1, [r11, #-0x3b0]
 *   @0x259210 ldr r2, [r11, #-0x3a8]
 *   @0x259214 ldr r3, [r11, #-0x3a0]
 *   @0x259218 str r12, [sp, #0x4]
 *   @0x25921c str r12, [sp, #0x10]
 *   @0x259220 bl 0x24a99c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii>
 *   @0x259224 b 0x259040 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x204>
 *   @0x259228 ldr r0, [pc, #0x18]
 *   @0x25922c add r0, pc, r0
 *   @0x259230 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x259234 b 0x259070 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x234>
 *   @0x259238 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x25923c ldrsheq r4, [r9], -r12
 *   @0x259240 andeq r12, sp, r0, rrx
 *   @0x259244 ldrdeq r12, sp, [pc], -r12
 *   @0x259248 andeq r12, pc, r12, lsl sp
 *
 * ══ §12/31 Code_Report_Error(CCode*, int, char const*)  0xed7f8  size 1036  259 条（0xed7f8..0xedc04）
 * @func 0xed7f8 0xedc04  size 1036  259 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×9 / operator delete(void*)×6 / LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / 0xb65b0×3 / 0xb65c8×2 / operator new(unsigned int)×2
 * 字段偏移 top8: 0x4×10 / 0x8×8 / 0x-38×5 / 0x-30×4 / 0x-3c×4 / 0x-34×3 / 0x-28×2 / 0x-1×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xed7f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xed7fc add r11, sp, #32
 *   @0xed800 ldr r5, [pc, #0x3e8]
 *   @0xed804 sub sp, sp, #44
 *   @0xed808 mov r4, r1
 *   @0xed80c ldr r5, [pc, r5]
 *   @0xed810 str r0, [r11, #-0x34]
 *   @0xed814 str r2, [r11, #-0x38]
 *   @0xed818 ldr r3, [r5]
 *   @0xed81c str r3, [r11, #-0x28]
 *   @0xed820 bl 0x17df38 <_Z14ExitFullScreenv>
 *   @0xed824 ldr r3, [pc, #0x3c8]
 *   @0xed828 ldr r3, [pc, r3]
 *   @0xed82c ldrb r7, [r3]
 *   @0xed830 cmp r7, #0
 *   @0xed834 beq 0xed850 <_Z17Code_Report_ErrorP5CCodeiPKc+0x58>
 *   @0xed838 ldr r2, [r11, #-0x28]
 *   @0xed83c ldr r3, [r5]
 *   @0xed840 cmp r2, r3
 *   @0xed844 bne 0xedbd0 <_Z17Code_Report_ErrorP5CCodeiPKc+0x3d8>
 *   @0xed848 sub sp, r11, #32
 *   @0xed84c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xed850 ldr r6, [pc, #0x3a0]
 *   @0xed854 mov r2, #1
 *   @0xed858 strb r2, [r3]
 *   @0xed85c bic r4, r4, r4, asr #31
 *   @0xed860 ldr r6, [pc, r6]
 *   @0xed864 ldr r0, [r6]
 *   @0xed868 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xed86c ldr r0, [r11, #-0x34]
 *   @0xed870 str r7, [r6]
 *   @0xed874 bl 0xcf470 <_ZN5CCode7GetTextEv>
 *   @0xed878 mov r9, r0
 *   @0xed87c bl 0xb6538 <strlen@plt>
 *   @0xed880 mov r1, #0
 *   @0xed884 cmp r4, r0
 *   @0xed888 movge r4, r0
 *   @0xed88c cmp r9, #0
 *   @0xed890 addne r2, r0, #1
 *   @0xed894 moveq r2, #32
 *   @0xed898 add r0, r2, #14
 *   @0xed89c bic r0, r0, #7
 *   @0xed8a0 mov r7, r2
 *   @0xed8a4 sub sp, sp, r0
 *   @0xed8a8 add r3, sp, #16
 *   @0xed8ac str r3, [r11, #-0x30]
 *   @0xed8b0 mov r0, r3
 *   @0xed8b4 bl 0xb65b0 <memset@plt>
 *   @0xed8b8 cmp r4, #0
 *   @0xed8bc ble 0xedbd4 <_Z17Code_Report_ErrorP5CCodeiPKc+0x3dc>
 *   @0xed8c0 add lr, r4, r9
 *   @0xed8c4 mov r2, r9
 *   @0xed8c8 mov r0, #0
 *   @0xed8cc mov r10, #1
 *   @0xed8d0 ldrb r1, [r2], #1
 *   @0xed8d4 cmp r1, #10
 *   @0xed8d8 addeq r10, r10, #1
 *   @0xed8dc moveq r0, #0
 *   @0xed8e0 beq 0xed8ec <_Z17Code_Report_ErrorP5CCodeiPKc+0xf4>
 *   @0xed8e4 cmp r1, #13
 *   @0xed8e8 addne r0, r0, #1
 *   @0xed8ec cmp r2, lr
 *   @0xed8f0 bne 0xed8d0 <_Z17Code_Report_ErrorP5CCodeiPKc+0xd8>
 *   @0xed8f4 ldrb r1, [r9]
 *   @0xed8f8 add r0, r0, #1
 *   @0xed8fc str r0, [r11, #-0x3c]
 *   @0xed900 cmp r1, #0
 *   @0xed904 beq 0xed974 <_Z17Code_Report_ErrorP5CCodeiPKc+0x17c>
 *   @0xed908 ldrb r1, [r2, #-0x1]
 *   @0xed90c cmp r1, #10
 *   @0xed910 bne 0xed928 <_Z17Code_Report_ErrorP5CCodeiPKc+0x130>
 *   @0xed914 b 0xed930 <_Z17Code_Report_ErrorP5CCodeiPKc+0x138>
 *   @0xed918 sub r2, r2, #1
 *   @0xed91c ldrb r1, [r2, #-0x1]
 *   @0xed920 cmp r1, #10
 *   @0xed924 beq 0xed930 <_Z17Code_Report_ErrorP5CCodeiPKc+0x138>
 *   @0xed928 subs r4, r4, #1
 *   @0xed92c bne 0xed918 <_Z17Code_Report_ErrorP5CCodeiPKc+0x120>
 *   @0xed930 mov r0, r9
 *   @0xed934 mov r8, #0
 *   @0xed938 bl 0xb6538 <strlen@plt>
 *   @0xed93c b 0xed96c <_Z17Code_Report_ErrorP5CCodeiPKc+0x174>
 *   @0xed940 ldrb r1, [r9, r4]
 *   @0xed944 cmp r1, #10
 *   @0xed948 beq 0xed974 <_Z17Code_Report_ErrorP5CCodeiPKc+0x17c>
 *   @0xed94c cmp r8, r7
 *   @0xed950 bge 0xed968 <_Z17Code_Report_ErrorP5CCodeiPKc+0x170>
 *   @0xed954 ldr r3, [r11, #-0x30]
 *   @0xed958 mov r0, r9
 *   @0xed95c strb r1, [r3, r8]
 *   @0xed960 add r8, r8, #1
 *   @0xed964 bl 0xb6538 <strlen@plt>
 *   @0xed968 add r4, r4, #1
 *   @0xed96c cmp r4, r0
 *   @0xed970 blt 0xed940 <_Z17Code_Report_ErrorP5CCodeiPKc+0x148>
 *   @0xed974 ldr r3, [r11, #-0x34]
 *   @0xed978 ldr r2, [r3, #0x8]
 *   @0xed97c cmp r2, #1
 *   @0xed980 beq 0xeda84 <_Z17Code_Report_ErrorP5CCodeiPKc+0x28c>
 *   @0xed984 mov r0, r9
 *   @0xed988 bl 0xb6538 <strlen@plt>
 *   @0xed98c mov r4, r0
 *   @0xed990 ldr r0, [r11, #-0x38]
 *   @0xed994 bl 0xb6538 <strlen@plt>
 *   @0xed998 mov r1, #0
 *   @0xed99c add r0, r4, r0
 *   @0xed9a0 add r4, r0, #40
 *   @0xed9a4 lsl r4, r4, #1
 *   @0xed9a8 add r0, r4, #14
 *   @0xed9ac bic r0, r0, #7
 *   @0xed9b0 mov r2, r4
 *   @0xed9b4 sub sp, sp, r0
 *   @0xed9b8 add r7, sp, #16
 *   @0xed9bc mov r0, r7
 *   @0xed9c0 bl 0xb65b0 <memset@plt>
 *   @0xed9c4 ldr r3, [r11, #-0x3c]
 *   @0xed9c8 ldr r2, [pc, #0x22c]
 *   @0xed9cc mov r1, r4
 *   @0xed9d0 mov r0, r7
 *   @0xed9d4 str r3, [sp]
 *   @0xed9d8 add r2, pc, r2
 *   @0xed9dc ldr r3, [r11, #-0x38]
 *   @0xed9e0 str r3, [sp, #0x4]
 *   @0xed9e4 mov r3, r9
 *   @0xed9e8 bl 0xb65c8 <snprintf@plt>
 *   @0xed9ec ldr r4, [r6]
 *   @0xed9f0 cmp r4, #0
 *   @0xed9f4 beq 0xeda1c <_Z17Code_Report_ErrorP5CCodeiPKc+0x224>
 *   @0xed9f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xed9fc ldr r8, [r4, #0x4]
 *   @0xeda00 sub r8, r8, #1
 *   @0xeda04 str r8, [r4, #0x4]
 *   @0xeda08 cmp r8, #0
 *   @0xeda0c beq 0xeda4c <_Z17Code_Report_ErrorP5CCodeiPKc+0x254>
 *   @0xeda10 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xeda14 mov r0, r4
 *   @0xeda18 bl 0x27d1d0 <_ZdlPv>
 *   @0xeda1c mov r0, #12
 *   @0xeda20 bl 0x27c524 <_Znwj>
 *   @0xeda24 mov r4, r0
 *   @0xeda28 mov r0, r7
 *   @0xeda2c bl 0xb6538 <strlen@plt>
 *   @0xeda30 str r0, [r4, #0x8]
 *   @0xeda34 mov r0, r7
 *   @0xeda38 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xeda3c mov r3, #1
 *   @0xeda40 stm r4, {r0, r3}
 *   @0xeda44 str r4, [r6]
 *   @0xeda48 b 0xed838 <_Z17Code_Report_ErrorP5CCodeiPKc+0x40>
 *   @0xeda4c ldr r0, [r4]
 *   @0xeda50 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xeda54 str r8, [r4]
 *   @0xeda58 str r8, [r4, #0x8]
 *   @0xeda5c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xeda60 ldr r8, [r4, #0x4]
 *   @0xeda64 sub r8, r8, #1
 *   @0xeda68 str r8, [r4, #0x4]
 *   @0xeda6c cmp r8, #0
 *   @0xeda70 beq 0xedbac <_Z17Code_Report_ErrorP5CCodeiPKc+0x3b4>
 *   @0xeda74 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xeda78 mov r0, r4
 *   @0xeda7c bl 0x27d1d0 <_ZdlPv>
 *   @0xeda80 b 0xeda10 <_Z17Code_Report_ErrorP5CCodeiPKc+0x218>
 *   @0xeda84 ldr r0, [r11, #-0x30]
 *   @0xeda88 bl 0xb6538 <strlen@plt>
 *   @0xeda8c mov r4, r0
 *   @0xeda90 ldr r0, [r11, #-0x38]
 *   @0xeda94 bl 0xb6538 <strlen@plt>
 *   @0xeda98 mov r1, #0
 *   @0xeda9c add r0, r4, r0
 *   @0xedaa0 add r7, r0, #51
 *   @0xedaa4 lsl r7, r7, #1
 *   @0xedaa8 add r3, r7, #14
 *   @0xedaac bic r3, r3, #7
 *   @0xedab0 mov r2, r7
 *   @0xedab4 sub sp, sp, r3
 *   @0xedab8 add r4, sp, #16
 *   @0xedabc mov r0, r4
 *   @0xedac0 bl 0xb65b0 <memset@plt>
 *   @0xedac4 ldr r3, [r11, #-0x30]
 *   @0xedac8 ldr r2, [pc, #0x130]
 *   @0xedacc mov r1, r7
 *   @0xedad0 mov r0, r4
 *   @0xedad4 str r3, [sp]
 *   @0xedad8 add r2, pc, r2
 *   @0xedadc ldr r3, [r11, #-0x3c]
 *   @0xedae0 str r3, [sp, #0x4]
 *   @0xedae4 ldr r3, [r11, #-0x38]
 *   @0xedae8 str r3, [sp, #0x8]
 *   @0xedaec mov r3, r10
 *   @0xedaf0 bl 0xb65c8 <snprintf@plt>
 *   @0xedaf4 ldr r7, [r6]
 *   @0xedaf8 cmp r7, #0
 *   @0xedafc beq 0xedb24 <_Z17Code_Report_ErrorP5CCodeiPKc+0x32c>
 *   @0xedb00 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xedb04 ldr r8, [r7, #0x4]
 *   @0xedb08 sub r8, r8, #1
 *   @0xedb0c str r8, [r7, #0x4]
 *   @0xedb10 cmp r8, #0
 *   @0xedb14 beq 0xedb54 <_Z17Code_Report_ErrorP5CCodeiPKc+0x35c>
 *   @0xedb18 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xedb1c mov r0, r7
 *   @0xedb20 bl 0x27d1d0 <_ZdlPv>
 *   @0xedb24 mov r0, #12
 *   @0xedb28 bl 0x27c524 <_Znwj>
 *   @0xedb2c mov r7, r0
 *   @0xedb30 mov r0, r4
 *   @0xedb34 bl 0xb6538 <strlen@plt>
 *   @0xedb38 str r0, [r7, #0x8]
 *   @0xedb3c mov r0, r4
 *   @0xedb40 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xedb44 mov r3, #1
 *   @0xedb48 stm r7, {r0, r3}
 *   @0xedb4c str r7, [r6]
 *   @0xedb50 b 0xed838 <_Z17Code_Report_ErrorP5CCodeiPKc+0x40>
 *   @0xedb54 ldr r0, [r7]
 *   @0xedb58 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xedb5c str r8, [r7]
 *   @0xedb60 str r8, [r7, #0x8]
 *   @0xedb64 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xedb68 ldr r8, [r7, #0x4]
 *   @0xedb6c sub r8, r8, #1
 *   @0xedb70 str r8, [r7, #0x4]
 *   @0xedb74 cmp r8, #0
 *   @0xedb78 bne 0xedb9c <_Z17Code_Report_ErrorP5CCodeiPKc+0x3a4>
 *   @0xedb7c ldr r0, [r7]
 *   @0xedb80 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xedb84 mov r0, r7
 *   @0xedb88 str r8, [r7]
 *   @0xedb8c str r8, [r7, #0x8]
 *   @0xedb90 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xedb94 mov r0, r7
 *   @0xedb98 bl 0x27d1d0 <_ZdlPv>
 *   @0xedb9c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xedba0 mov r0, r7
 *   @0xedba4 bl 0x27d1d0 <_ZdlPv>
 *   @0xedba8 b 0xedb18 <_Z17Code_Report_ErrorP5CCodeiPKc+0x320>
 *   @0xedbac ldr r0, [r4]
 *   @0xedbb0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xedbb4 mov r0, r4
 *   @0xedbb8 str r8, [r4]
 *   @0xedbbc str r8, [r4, #0x8]
 *   @0xedbc0 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xedbc4 mov r0, r4
 *   @0xedbc8 bl 0x27d1d0 <_ZdlPv>
 *   @0xedbcc b 0xeda74 <_Z17Code_Report_ErrorP5CCodeiPKc+0x27c>
 *   @0xedbd0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xedbd4 ldrb r2, [r9]
 *   @0xedbd8 mov r3, #1
 *   @0xedbdc mov r10, r3
 *   @0xedbe0 str r3, [r11, #-0x3c]
 *   @0xedbe4 cmp r2, #0
 *   @0xedbe8 bne 0xed930 <_Z17Code_Report_ErrorP5CCodeiPKc+0x138>
 *   @0xedbec b 0xed974 <_Z17Code_Report_ErrorP5CCodeiPKc+0x17c>
 *   @0xedbf0 eorseq r0, r0, r4, asr #2
 *   @0xedbf4 eorseq r0, r0, r12, lsr r3
 *   @0xedbf8 eorseq r0, r0, r0, lsl r3
 *   @0xedbfc eoreq r7, r4, r0, lsl #9
 *   @0xedc00 eoreq r7, r4, r12, asr #6
 *
 * ══ §13/31 JS_String_prototype_split_RegEx(RValue&, YYObjectBase*, char const*, int, int, RValue*)  0x2486b8  size 1036  259 条（0x2486b8..0x248ac4）
 * @func 0x2486b8 0x248ac4  size 1036  259 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×3 / YYCreateString(RValue*, char const*)×3 / JSArrayPut(RValue*, RValue*, RValue*)×3 / pcre_exec×2 / YYAlloc(int)×2 / 0xb65bc×2 / JS_String_prototype_split_RegEx(RValue&, YYObjectBase*, char const*, int, int, RValue*)+0x27c / JS_String_prototype_split_RegEx(RValue&, YYObjectBase*, char const*, int, int, RValue*)+0x3e0
 * 字段偏移 top8: 0x3c×10 / 0x44×9 / 0x40×7 / 0x20×6 / 0x18×5 / 0x1×4 / 0x220×3 / 0x2c×3
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2486b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2486bc sub sp, sp, #508
 *   @0x2486c0 mov r11, r2
 *   @0x2486c4 ldr r12, [sp, #0x220]
 *   @0x2486c8 str r0, [sp, #0x18]
 *   @0x2486cc cmp r12, #0
 *   @0x2486d0 str r1, [sp, #0x24]
 *   @0x2486d4 str r3, [sp, #0x2c]
 *   @0x2486d8 beq 0x248a48 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x390>
 *   @0x2486dc mov r3, #0
 *   @0x2486e0 add r12, sp, #104
 *   @0x2486e4 add r6, sp, #88
 *   @0x2486e8 str r12, [sp, #0x10]
 *   @0x2486ec add r12, sp, #72
 *   @0x2486f0 str r12, [sp, #0x14]
 *   @0x2486f4 ldr r12, [sp, #0x2c]
 *   @0x2486f8 mov r9, r3
 *   @0x2486fc mov r4, r3
 *   @0x248700 mov r5, r3
 *   @0x248704 sub r12, r12, #2
 *   @0x248708 str r3, [sp, #0x20]
 *   @0x24870c str r12, [sp, #0x34]
 *   @0x248710 add r12, sp, #56
 *   @0x248714 str r3, [sp, #0x3c]
 *   @0x248718 str r12, [sp, #0x1c]
 *   @0x24871c str r3, [sp, #0x40]
 *   @0x248720 str r3, [sp, #0x44]
 *   @0x248724 str r3, [sp, #0x48]
 *   @0x248728 str r3, [sp, #0x4c]
 *   @0x24872c str r3, [sp, #0x50]
 *   @0x248730 str r3, [sp, #0x54]
 *   @0x248734 str r3, [sp, #0x58]
 *   @0x248738 str r3, [sp, #0x5c]
 *   @0x24873c str r3, [sp, #0x60]
 *   @0x248740 str r3, [sp, #0x64]
 *   @0x248744 ldr r12, [sp, #0x24]
 *   @0x248748 add lr, sp, #104
 *   @0x24874c mov r2, r11
 *   @0x248750 ldr r3, [sp, #0x220]
 *   @0x248754 ldr r0, [r12, #0x1c]
 *   @0x248758 ldr r1, [r12, #0x20]
 *   @0x24875c mov r12, #100
 *   @0x248760 str r9, [sp]
 *   @0x248764 str r5, [sp, #0x4]
 *   @0x248768 str lr, [sp, #0x8]
 *   @0x24876c str r12, [sp, #0xc]
 *   @0x248770 bl 0x279390 <pcre_exec>
 *   @0x248774 subs r7, r0, #0
 *   @0x248778 ble 0x248934 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x27c>
 *   @0x24877c ldr r12, [sp, #0x6c]
 *   @0x248780 ldr r10, [sp, #0x68]
 *   @0x248784 cmp r12, r4
 *   @0x248788 str r12, [sp, #0x28]
 *   @0x24878c beq 0x248934 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x27c>
 *   @0x248790 cmp r10, r4
 *   @0x248794 str r5, [sp, #0x44]
 *   @0x248798 ble 0x248a98 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x3e0>
 *   @0x24879c add r4, r11, r4
 *   @0x2487a0 add r9, r11, r10
 *   @0x2487a4 mov r2, #0
 *   @0x2487a8 str r6, [sp, #0x30]
 *   @0x2487ac ldr r3, [sp, #0x40]
 *   @0x2487b0 mvn r1, r2
 *   @0x2487b4 ldrb r8, [r4], #1
 *   @0x2487b8 add r1, r3, r1
 *   @0x2487bc cmp r1, #1
 *   @0x2487c0 bgt 0x24881c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x164>
 *   @0x2487c4 add r1, r3, r3, lsl #1
 *   @0x2487c8 cmp r3, #0
 *   @0x2487cc add r2, r2, #2
 *   @0x2487d0 mov r10, #3
 *   @0x2487d4 add r1, r1, r1, lsr #31
 *   @0x2487d8 ldr r6, [sp, #0x3c]
 *   @0x2487dc asrne r10, r1, #1
 *   @0x2487e0 cmp r2, r10
 *   @0x2487e4 add r2, r2, r2, lsl #1
 *   @0x2487e8 addgt r2, r2, r2, lsr #31
 *   @0x2487ec asrgt r10, r2, #1
 *   @0x2487f0 mov r0, r10
 *   @0x2487f4 bl 0xcef4c <_Z7YYAlloci>
 *   @0x2487f8 mov r1, r6
 *   @0x2487fc ldr r2, [sp, #0x40]
 *   @0x248800 str r0, [sp, #0x3c]
 *   @0x248804 bl 0xb65bc <memcpy@plt>
 *   @0x248808 subs r0, r6, #0
 *   @0x24880c str r10, [sp, #0x40]
 *   @0x248810 beq 0x248818 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x160>
 *   @0x248814 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x248818 ldr r2, [sp, #0x44]
 *   @0x24881c ldr r3, [sp, #0x3c]
 *   @0x248820 cmp r4, r9
 *   @0x248824 add r1, r3, r2
 *   @0x248828 strb r8, [r3, r2]
 *   @0x24882c strb r5, [r1, #0x1]
 *   @0x248830 ldr r2, [sp, #0x44]
 *   @0x248834 add r2, r2, #1
 *   @0x248838 str r2, [sp, #0x44]
 *   @0x24883c bne 0x2487ac <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0xf4>
 *   @0x248840 vldr s13, [sp, #32]
 *   @0x248844 vcvt.f64.s32 d7, s13
 *   @0x248848 cmp r2, #0
 *   @0x24884c ldr r6, [sp, #0x30]
 *   @0x248850 addeq r1, sp, #68
 *   @0x248854 ldrne r1, [sp, #0x3c]
 *   @0x248858 vstr d7, [sp, #72]
 *   @0x24885c mov r0, r6
 *   @0x248860 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x248864 ldr r12, [sp, #0x20]
 *   @0x248868 ldr r0, [sp, #0x18]
 *   @0x24886c add r1, sp, #72
 *   @0x248870 mov r2, r6
 *   @0x248874 add r4, r12, #1
 *   @0x248878 bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_>
 *   @0x24887c ldr r12, [sp, #0x2c]
 *   @0x248880 cmp r4, r12
 *   @0x248884 beq 0x24891c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x264>
 *   @0x248888 cmp r7, #1
 *   @0x24888c beq 0x248a38 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x380>
 *   @0x248890 ldr lr, [sp, #0x20]
 *   @0x248894 mov r10, #0
 *   @0x248898 ldr r12, [sp, #0x34]
 *   @0x24889c add r8, lr, r7
 *   @0x2488a0 rsb r9, lr, r12
 *   @0x2488a4 mov r3, r8
 *   @0x2488a8 mov r8, r4
 *   @0x2488ac mov r4, r3
 *   @0x2488b0 b 0x2488bc <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x204>
 *   @0x2488b4 cmp r8, r4
 *   @0x2488b8 beq 0x248a34 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x37c>
 *   @0x2488bc vmov s13, r8
 *   @0x2488c0 mov r3, r10
 *   @0x2488c4 add r2, sp, #56
 *   @0x2488c8 add r1, sp, #104
 *   @0x2488cc vcvt.f64.s32 d7, s13
 *   @0x2488d0 str r2, [sp]
 *   @0x2488d4 mov r0, r11
 *   @0x2488d8 mov r2, r7
 *   @0x2488dc str r5, [sp, #0x38]
 *   @0x2488e0 add r8, r8, #1
 *   @0x2488e4 vstr d7, [sp, #72]
 *   @0x2488e8 bl 0x25f5e8 <pcre_get_substring>
 *   @0x2488ec mov r0, r6
 *   @0x2488f0 ldr r1, [sp, #0x38]
 *   @0x2488f4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x2488f8 add r1, sp, #72
 *   @0x2488fc mov r2, r6
 *   @0x248900 ldr r0, [sp, #0x18]
 *   @0x248904 bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_>
 *   @0x248908 ldr r0, [sp, #0x38]
 *   @0x24890c bl 0x25f6ac <pcre_free_substring>
 *   @0x248910 cmp r10, r9
 *   @0x248914 add r10, r10, #1
 *   @0x248918 bne 0x2488b4 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x1fc>
 *   @0x24891c ldr r0, [sp, #0x3c]
 *   @0x248920 cmp r0, #0
 *   @0x248924 beq 0x24892c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x274>
 *   @0x248928 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24892c add sp, sp, #508
 *   @0x248930 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x248934 add r9, r9, #1
 *   @0x248938 ldr r12, [sp, #0x220]
 *   @0x24893c cmp r12, r9
 *   @0x248940 bne 0x248744 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x8c>
 *   @0x248944 cmp r12, r4
 *   @0x248948 mov r3, #0
 *   @0x24894c str r3, [sp, #0x44]
 *   @0x248950 ble 0x248aac <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x3f4>
 *   @0x248954 add r4, r11, r4
 *   @0x248958 add r9, r11, r12
 *   @0x24895c mov r7, r3
 *   @0x248960 ldr r2, [sp, #0x40]
 *   @0x248964 mvn r1, r3
 *   @0x248968 ldrb r8, [r4], #1
 *   @0x24896c add r1, r2, r1
 *   @0x248970 cmp r1, #1
 *   @0x248974 bgt 0x2489d0 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x318>
 *   @0x248978 add r1, r2, r2, lsl #1
 *   @0x24897c cmp r2, #0
 *   @0x248980 add r3, r3, #2
 *   @0x248984 mov r5, #3
 *   @0x248988 add r1, r1, r1, lsr #31
 *   @0x24898c ldr r10, [sp, #0x3c]
 *   @0x248990 asrne r5, r1, #1
 *   @0x248994 cmp r3, r5
 *   @0x248998 add r3, r3, r3, lsl #1
 *   @0x24899c addgt r3, r3, r3, lsr #31
 *   @0x2489a0 asrgt r5, r3, #1
 *   @0x2489a4 mov r0, r5
 *   @0x2489a8 bl 0xcef4c <_Z7YYAlloci>
 *   @0x2489ac mov r1, r10
 *   @0x2489b0 ldr r2, [sp, #0x40]
 *   @0x2489b4 str r0, [sp, #0x3c]
 *   @0x2489b8 bl 0xb65bc <memcpy@plt>
 *   @0x2489bc subs r0, r10, #0
 *   @0x2489c0 str r5, [sp, #0x40]
 *   @0x2489c4 beq 0x2489cc <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x314>
 *   @0x2489c8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2489cc ldr r3, [sp, #0x44]
 *   @0x2489d0 ldr r2, [sp, #0x3c]
 *   @0x2489d4 cmp r4, r9
 *   @0x2489d8 add r1, r2, r3
 *   @0x2489dc strb r8, [r2, r3]
 *   @0x2489e0 strb r7, [r1, #0x1]
 *   @0x2489e4 ldr r3, [sp, #0x44]
 *   @0x2489e8 add r3, r3, #1
 *   @0x2489ec str r3, [sp, #0x44]
 *   @0x2489f0 bne 0x248960 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x2a8>
 *   @0x2489f4 vldr s13, [sp, #32]
 *   @0x2489f8 vcvt.f64.s32 d7, s13
 *   @0x2489fc cmp r3, #0
 *   @0x248a00 addeq r1, sp, #68
 *   @0x248a04 ldrne r1, [sp, #0x3c]
 *   @0x248a08 vstr d7, [sp, #72]
 *   @0x248a0c mov r0, r6
 *   @0x248a10 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x248a14 ldr r0, [sp, #0x18]
 *   @0x248a18 add r1, sp, #72
 *   @0x248a1c mov r2, r6
 *   @0x248a20 bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_>
 *   @0x248a24 ldr r0, [sp, #0x3c]
 *   @0x248a28 cmp r0, #0
 *   @0x248a2c bne 0x248928 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x270>
 *   @0x248a30 b 0x24892c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x274>
 *   @0x248a34 mov r4, r8
 *   @0x248a38 ldr r9, [sp, #0x28]
 *   @0x248a3c str r4, [sp, #0x20]
 *   @0x248a40 mov r4, r9
 *   @0x248a44 b 0x248938 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x280>
 *   @0x248a48 ldr r0, [r1, #0x1c]
 *   @0x248a4c mov r3, r12
 *   @0x248a50 ldr r1, [r1, #0x20]
 *   @0x248a54 add lr, sp, #104
 *   @0x248a58 str r12, [sp]
 *   @0x248a5c mov r12, #100
 *   @0x248a60 str r3, [sp, #0x4]
 *   @0x248a64 str lr, [sp, #0x8]
 *   @0x248a68 str r12, [sp, #0xc]
 *   @0x248a6c bl 0x279390 <pcre_exec>
 *   @0x248a70 cmp r0, #0
 *   @0x248a74 ble 0x24892c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x274>
 *   @0x248a78 ldr r12, [sp, #0x18]
 *   @0x248a7c ldr r2, [pc, #0x3c]
 *   @0x248a80 ldr r1, [sp, #0x224]
 *   @0x248a84 ldr r0, [r12]
 *   @0x248a88 add r2, pc, r2
 *   @0x248a8c bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc>
 *   @0x248a90 add sp, sp, #508
 *   @0x248a94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x248a98 vldr s13, [sp, #32]
 *   @0x248a9c vcvt.f64.s32 d7, s13
 *   @0x248aa0 add r1, sp, #68
 *   @0x248aa4 vstr d7, [sp, #72]
 *   @0x248aa8 b 0x24885c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x1a4>
 *   @0x248aac vldr s13, [sp, #32]
 *   @0x248ab0 vcvt.f64.s32 d7, s13
 *   @0x248ab4 add r1, sp, #68
 *   @0x248ab8 vstr d7, [sp, #72]
 *   @0x248abc b 0x248a0c <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_+0x354>
 *   @0x248ac0 andeq r9, lr, r4, ror #20
 *
 * ══ §14/31 anon_2e490c  0x2e490c  size 1036  259 条（0x2e490c..0x2e4d18）
 * @func 0x2e490c 0x2e4d18  size 1036  259 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x467942 / 0x361d22 / 0x3914fc / anon_2e9c78+0x1754 / 0x4b39f8 / 0x3f629c / 0x3b54ac / 0x4a7b12
 * 字段偏移 top8: 0xc×2 / 0x9×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e490c addlt r11, r4, #240, #10
 *   @0x2e4910 .word 0x0c00b28e
 *   @0x2e4914 blx 0x467942 <g_RomDisk+0x70122>
 *   @0x2e4918 blx 0x361d22 <_ZTS12CDS_Priority+0x3d7a>
 *   @0x2e491c adcmi r5, r11, #4, #6
 *   @0x2e4920 .word 0xf44fbf34
 *   @0x2e4924 strhs r3, [r0, -r0, lsl #15]
 *   @0x2e4928 .word 0x0c1b041d
 *   @0x2e492c strpl pc, [r4], #-2822
 *   @0x2e4930 andlo pc, r0, r1, lsl #22
 *   @0x2e4934 svclt #0x2c42ac
 *   @0x2e4938 mcrrne p6, #0x0, r4, r5, c5
 *   @0x2e493c ldrtmi r6, [sp], #-20
 *   @0x2e4940 ldcllt p0, c6, [r0, #340]!
 *   @0x2e4944 ldrhhs pc, [r6], -r0
 *   @0x2e4948 sbcseq r6, r3, r1, lsl #19
 *   @0x2e494c bicvs r4, r1, #419430400
 *   @0x2e4950 strmi r6, [r10], #-2497
 *   @0x2e4954 ldrhne pc, [r4], -r0
 *   @0x2e4958 bvs 0x37d968 <_ZTS13C_UTF16String+0x14a14>
 *   @0x2e495c subeq lr, r1, #2048
 *   @0x2e4960 .word 0x7c026442
 *   @0x2e4964 bvs 0xfe390e14 <b2_toiTime+0xfffffffffdc37970>
 *   @0x2e4968 strbvs r4, [r2], #1050
 *   @0x2e496c ldrmi r6, [r3], #-2754
 *   @0x2e4970 ldrbmi r6, [r0, -r3, lsl #10]!
 *   @0x2e4974 andhs r6, r0, r2, lsl #16
 *   @0x2e4978 .word 0xf8123a01
 *   @0x2e497c tstlt r11, r1, lsl #30
 *   @0x2e4980 bne 0x4e4e8c <SrcVerts+0x41ed0>
 *   @0x2e4984 .word 0xe7f84418
 *   @0x2e4988 stmdavs r3, {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2e498c andhs pc, r7, #201326595
 *   @0x2e4990 bl 0x3914fc <ft_adobe_glyph_list+0xbd8>
 *   @0x2e4994 bne 0x17692a0 <b2_toiTime+0x100fdfc>
 *   @0x2e4998 bne 0xfe564ee4 <b2_toiTime+0xfffffffffde0ba40>
 *   @0x2e499c smlabtmi r7, r3, r3, pc
 *   @0x2e49a0 cmpeq r1, r10, lsl #8
 *   @0x2e49a4 bl 0x2eb3cc <FT_Done_Memory+0x1758>
 *   @0x2e49a8 .word 0x47706013
 *   @0x2e49ac stmdavs r8, {r0, r1, r11, sp, lr}
 *   @0x2e49b0 subsmi r1, r8, #110592
 *   @0x2e49b4 .word 0x47704158
 *   @0x2e49b8 mcrge p5, #0x0, r11, c2, c7, #0x7
 *   @0x2e49bc strmi r6, [sp], -r11, asr #17
 *   @0x2e49c0 stceq p8, c15, [r4, #-280]
 *   @0x2e49c4 stmdbvs pc, {r4, r5, r9, r10, lr} ^
 *   @0x2e49c8 stmdavs r9!, {r3, r4, r7, r8, r9, r10, lr} ^
 *   @0x2e49cc ldmib r0, {r2, r4, r5, r12, sp, lr, pc}
 *   @0x2e49d0 streq lr, [r1], #2823
 *   @0x2e49d4 .word 0xb1686820
 *   @0x2e49d8 ldrtmi r6, [r1], -r11, lsr #18
 *   @0x2e49dc stmdblt r8, {r3, r4, r7, r8, r9, r10, lr} ^
 *   @0x2e49e0 adcsmi r3, r12, #4, #24
 *   @0x2e49e4 stmdavs r12!, {r1, r2, r4, r5, r6, r7, r9, r12, lr, pc} ^
 *   @0x2e49e8 strmi pc, [r0], #260
 *   @0x2e49ec bl 0x4b39f8 <SrcVerts+0x10a3c>
 *   @0x2e49f0 strb r0, [pc, r4, lsl #9]!
 *   @0x2e49f4 andlt r4, r3, r0, lsr #12
 *   @0x2e49f8 strdeq r11, r12, [r0], -r0
 *   @0x2e49fc bvs 0xfe3d21c4 <b2_toiTime+0xfffffffffdc78d20>
 *   @0x2e4a00 bvs 0x14111f4 <b2_toiTime+0xcb7d50>
 *   @0x2e4a04 svcmi #0x114e10
 *   @0x2e4a08 streq lr, [r4], #2819
 *   @0x2e4a0c blo 0x3f629c <g_MP3UpdateVolume+0xfc0>
 *   @0x2e4a10 movwle r4, #0xa29a
 *   @0x2e4a14 stmdavs sp, {r0, r4, r11, sp, lr} ^
 *   @0x2e4a18 ldrhle r4, [r8, #37]!
 *   @0x2e4a1c adcsmi r6, sp, #9240576
 *   @0x2e4a20 .word 0xf5b5d00c
 *   @0x2e4a24 mvnsle r2, r0, lsl #31
 *   @0x2e4a28 stcmi p0, c14, [r7, #-32]
 *   @0x2e4a2c addsmi r1, r10, #34, #30
 *   @0x2e4a30 .word 0xf852d307
 *   @0x2e4a34 stmdavs r12, {r2, r8, r11, r12} ^
 *   @0x2e4a38 mvnsle r4, r12, lsr #5
 *   @0x2e4a3c andhs r6, r0, r1, asr #11
 *   @0x2e4a40 .word 0x2026bdf0
 *   @0x2e4a44 svclt #0xbdf0
 *   @0x2e4a48 strbvc r6, [lr, #-0x963]!
 *   @0x2e4a4c andeq r0, r10, r3
 *   @0x2e4a50 strhlo pc, [r0], -r0
 *   @0x2e4a54 strhhs pc, [r0], -r1
 *   @0x2e4a58 blle 0x3b54ac <error_g0017+0xe150>
 *   @0x2e4a5c ldrdhs r11, r12, [r0], -r4
 *   @0x2e4a60 ldrbmi r2, [r0, -r1]!
 *   @0x2e4a64 rscslo pc, pc, pc, asr #32
 *   @0x2e4a68 stmdahs r0, {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2e4a6c submi r11, r0, #184, #30
 *   @0x2e4a70 b 0x16d2238 <b2_toiTime+0xf78d94>
 *   @0x2e4a74 addlt r4, r1, #16, #10
 *   @0x2e4a78 ldrlo pc, [r6, -r5, asr #12]
 *   @0x2e4a7c .word 0xf005fb07
 *   @0x2e4a80 ldrblo pc, [r9], sp, asr #12
 *   @0x2e4a84 movweq pc, #0x1b06
 *   @0x2e4a88 .word 0xf04fbfb4
 *   @0x2e4a8c andhs r3, r1, #-268435441
 *   @0x2e4a90 svclt #0x344283
 *   @0x2e4a94 addlo pc, r0, pc, asr #8
 *   @0x2e4a98 ldreq r2, [r12], #-0
 *   @0x2e4a9c blx 0x4a7b12 <SrcVerts+0x4b56>
 *   @0x2e4aa0 blx 0x474eae <g_RomDisk+0x7d68e>
 *   @0x2e4aa4 adcmi r3, r1, #20971520
 *   @0x2e4aa8 strtmi r11, [r12], -r12, lsr #30
 *   @0x2e4aac .word 0xf1b11c6c
 *   @0x2e4ab0 svclt #0x344f40
 *   @0x2e4ab4 stclne p6, c4, [r1], #-132
 *   @0x2e4ab8 strmi r3, [r8], #-513
 *   @0x2e4abc submi r11, r0, #8, #30
 *   @0x2e4ac0 strdeq r11, r12, [r0], -r0
 *   @0x2e4ac4 muleq r12, r0, r8
 *   @0x2e4ac8 mvnsmi lr, sp, lsr #18
 *   @0x2e4acc svcne #0x34f511
 *   @0x2e4ad0 subsmi sp, r4, #20480
 *   @0x2e4ad4 .word 0x01b4f501
 *   @0x2e4ad8 qadd16mi r4, r3, r10
 *   @0x2e4adc .word 0xf5b1e7f6
 *   @0x2e4ae0 stcle p15, c1, [r5, #-208]
 *   @0x2e4ae4 .word 0xf5a1425c
 *   @0x2e4ae8 .word 0x461301b4
 *   @0x2e4aec ldrb r4, [r6, r2, lsr #12]!
 *   @0x2e4af0 strhs r4, [r1, #-0xe10]
 *   @0x2e4af4 ldrbtmi r4, [lr], #-1580
 *   @0x2e4af8 .word 0x0c05eb03
 *   @0x2e4afc stmdbhs r0, {r0, r1, r2, r4, r6, r8, r11, r12}
 *   @0x2e4b00 stmdaeq r4, {r1, r2, r8, r12, sp, lr, pc}
 *   @0x2e4b04 .word 0xfc04fa4c
 *   @0x2e4b08 blx 0x14bebe8 <b2_toiTime+0xd65744>
 *   @0x2e4b0c ble 0x3e2724 <error_g0017+0x3b3c8>
 *   @0x2e4b10 ldrtmi r1, [r1], #-3035
 *   @0x2e4b14 and r4, r3, r2, ror #8
 *   @0x2e4b18 blne 0xfe535c0c <b2_toiTime+0xfffffffffdddc768>
 *   @0x2e4b1c andeq lr, r2, #204, #22
 *   @0x2e4b20 rsbeq r3, sp, r1, lsl #8
 *   @0x2e4b24 andle r2, r1, r7, lsl r12
 *   @0x2e4b28 strb r4, [r5, r6, asr #12]!
 *   @0x2e4b2c andeq lr, r12, r0, lsl #17
 *   @0x2e4b30 ldrhhi lr, [r0, #141]!
 *   @0x2e4b34 strheq r11, [r10], -r6
 *   @0x2e4b38 muleq r12, r0, r8
 *   @0x2e4b3c mvnsmi lr, sp, lsr #18
 *   @0x2e4b40 .word 0xf1c24293
 *   @0x2e4b44 stcle p1, c0, [lr, #-0]
 *   @0x2e4b48 strmi r4, [r10], -r11, lsl #5
 *   @0x2e4b4c stmdbmi r0!, {r1, r2, r10, r11, r12, lr, pc}
 *   @0x2e4b50 svclt #0xc82b00
 *   @0x2e4b54 teqeq r4, pc, asr #8
 *   @0x2e4b58 and r4, r7, r11, asr r2
 *   @0x2e4b5c .word 0x460b461a
 *   @0x2e4b60 .word 0x01b4f44f
 *   @0x2e4b64 addmi lr, r11, #2
 *   @0x2e4b68 .word 0x2100db05
 *   @0x2e4b6c strhs r4, [r1, #-0xe1a]
 *   @0x2e4b70 ldrbtmi r4, [lr], #-1580
 *   @0x2e4b74 subsmi lr, r9, #13
 *   @0x2e4b78 .word 0x460a4613
 *   @0x2e4b7c .word 0xe7f54915
 *   @0x2e4b80 blne 0xfe535c74 <b2_toiTime+0xfffffffffdddc7d0>
 *   @0x2e4b84 andeq lr, r2, #204, #22
 *   @0x2e4b88 rsbeq r3, sp, r1, lsl #8
 *   @0x2e4b8c andsle r2, r0, r7, lsl r12
 *   @0x2e4b90 bl 0x3b64b0 <error_g0017+0xf154>
 *   @0x2e4b94 ldmdbne r7, {r0, r2, r10, r11} ^
 *   @0x2e4b98 .word 0xf1062b00
 *   @0x2e4b9c blx 0x15e6bb4 <b2_toiTime+0xe8d710>
 *   @0x2e4ba0 ldmdavs r6!, {r2, r10, r11, r12, sp, lr, pc}
 *   @0x2e4ba4 .word 0xf704fa47
 *   @0x2e4ba8 blne 0xff9dc358 <b2_toiTime+0xffffffffff282eb4>
 *   @0x2e4bac strbtmi r4, [r2], #-1073
 *   @0x2e4bb0 stmdbhs r0, {r1, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2e4bb4 .word 0x3108db03
 *   @0x2e4bb8 .word 0x010ff021
 *   @0x2e4bbc .word 0xf1c1e004
 *   @0x2e4bc0 .word 0xf0210108
 *   @0x2e4bc4 submi r0, r9, #-1073741821
 *   @0x2e4bc8 subvs r6, r1, r2
 *   @0x2e4bcc ldrhhi lr, [r0, #141]!
 *   @0x2e4bd0 .word 0xff4c0000
 *   @0x2e4bd4 .word 0xffa60000
 *   @0x2e4bd8 andeq r11, r10, r10, lsr r10
 *   @0x2e4bdc .word 0x4603b510
 *   @0x2e4be0 muleq r6, r0, r8
 *   @0x2e4be4 strbtvc lr, [r2], #2690
 *   @0x2e4be8 strbtvc lr, [r2], #2980
 *   @0x2e4bec rscvc lr, r1, r1, lsl #21
 *   @0x2e4bf0 rscvc lr, r1, r0, lsr #23
 *   @0x2e4bf4 blx 0xfeef587c <b2_toiTime+0xfffffffffe79c3d8>
 *   @0x2e4bf8 .word 0xf1c0f080
 *   @0x2e4bfc .word 0x2c1d041f
 *   @0x2e4c00 stmdalo r2, {r0, r2, r10, r11, r12, lr, pc}
 *   @0x2e4c04 addmi r4, r2, r1, lsl #1
 *   @0x2e4c08 subsvs r6, r10, r9, lsl r0
 *   @0x2e4c0c .word 0xf1c0bd10
 *   @0x2e4c10 mrsmi r0, apsr
 *   @0x2e4c14 andsvs r4, r9, r2, lsl #2
 *   @0x2e4c18 subsvs r4, r10, r0, asr #4
 *   @0x2e4c1c strlt r11, [r8, #-0xd10]
 *   @0x2e4c20 stmdavs r9, {r11, sp, lr}
 *   @0x2e4c24 stmdavc r11, {r1, r11, r12, sp, lr}
 *   @0x2e4c28 swple r4, r10, [r6]
 *   @0x2e4c2c stc p5, c15, [r2], #836
 *   @0x2e4c30 .word 0x0001f1d0
 *   @0x2e4c34 andhs r11, r0, r8, lsr pc
 *   @0x2e4c38 andhs r11, r0, r8, lsl #26
 *   @0x2e4c3c ldrblt r11, [r8, #0xd08]!
 *   @0x2e4c40 blx 0xfeef649c <b2_toiTime+0xfffffffffe79cff8>
 *   @0x2e4c44 .word 0xf1c2f280
 *   @0x2e4c48 addsmi r0, r0, r0, lsr #8
 *   @0x2e4c4c .word 0xf704fa21
 *   @0x2e4c50 .word 0xf602fa01
 *   @0x2e4c54 strtmi r4, [r9], -r7, lsl #6
 *   @0x2e4c58 .word 0xf0334638
 *   @0x2e4c5c blx 0x460c3e <g_RomDisk+0x6941e>
 *   @0x2e4c60 svceq #0xf27310
 *   @0x2e4c64 b 0x1364d6c <b2_toiTime+0xc0b8c8>
 *   @0x2e4c68 rsbseq r0, r6, r3, asr #6
 *   @0x2e4c6c svclt #0x2442ab
 *   @0x2e4c70 movweq lr, #0x3bc5
 *   @0x2e4c74 andeq pc, r1, r0, asr #32
 *   @0x2e4c78 mvnsle r3, r1, lsl #24
 *   @0x2e4c7c strdeq r11, r12, [r0], -r8
 *   @0x2e4c80 .word 0x43f8e92d
 *   @0x2e4c84 ldrmi r4, [r6], -r8, lsl #13
 *   @0x2e4c88 stmdahs r0, {r0, r1, r2, r3, r4, r9, r10, lr}
 *   @0x2e4c8c stmdbhs r0, {r1, r2, r3, r4, r5, r12, lr, pc}
 *   @0x2e4c90 bhs 0x318d94 <__divsi3+0x84>
 *   @0x2e4c94 blhs 0x318d90 <__divsi3+0x80>
 *   @0x2e4c98 stmdbvs r3, {r0, r1, r3, r4, r5, r12, lr, pc}
 *   @0x2e4c9c ldreq pc, [r4, #-0x100]
 *   @0x2e4ca0 stmibeq r3, {r0, r2, r8, r9, r11, sp, lr, pc}
 *   @0x2e4ca4 strtmi r4, [r12], -sp, asr #10
 *   @0x2e4ca8 stmdavs r3!, {r3, r9, r12, lr, pc}
 *   @0x2e4cac strlo r4, [r4, #-0x641]
 *   @0x2e4cb0 ldmvs r8, {r0, r1, r3, r4, r11, sp, lr}
 *   @0x2e4cb4 mrrc p5, #0xd, pc, lr, c1
 *   @0x2e4cb8 mvnsle r2, r0, lsl #16
 *   @0x2e4cbc eorle r4, r2, r12, asr #10
 *   @0x2e4cc0 stmdavs r3, {r5, r11, sp, lr}
 *   @0x2e4cc4 ldmdblt r3, {r0, r1, r3, r4, r9, r11, sp, lr}
 *   @0x2e4cc8 pop {r0, r1, r2, sp}
 *   @0x2e4ccc ldmdbmi r2, {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2e4cd0 .word 0x47984479
 *   @0x2e4cd4 rscsle r2, r7, r0, lsl #16
 *   @0x2e4cd8 mlalo r0, sp, r8, pc
 *   @0x2e4cdc stmdavs r5, {r0, r1, r4, r6, r8, r12, sp, pc}
 *   @0x2e4ce0 rscsle r2, r1, r0, lsl #26
 *   @0x2e4ce4 ldrtmi r6, [r1], -r0, lsr #16
 *   @0x2e4ce8 .word 0xf89d463a
 *   @0x2e4cec strmi r3, [r8, r4, lsr #32]!
 *   @0x2e4cf0 .word 0x83f8e8bd
 *   @0x2e4cf4 blhs 0x2fee08 <TT_RunIns+0x2014>
 *   @0x2e4cf8 stmdavs r0!, {r1, r2, r5, r6, r7, r12, lr, pc}
 *   @0x2e4cfc shasxmi r4, r10, r1
 *   @0x2e4d00 pop {r3, r4, r7, r8, r9, r10, lr}
 *   @0x2e4d04 strdhs r8, r9, [r11], -r8
 *   @0x2e4d08 .word 0x83f8e8bd
 *   @0x2e4d0c pop {r0, r5, sp}
 *   @0x2e4d10 strdhs r8, r9, [r6], -r8
 *   @0x2e4d14 .word 0x83f8e8bd
 *
 * ══ §15/31 CSkeletonInstance::EllipseCollision(int, float, float, float, float, float, tagYYRECT*)  0xbf524  size 1032  258 条（0xbf524..0xbf92c）
 * @func 0xbf524 0xbf92c  size 1032  258 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::EllipseCollision(int, float, float, float, float, float, tagYYRECT*)+0x2f0×4 / CSkeletonInstance::EllipseCollision(int, float, float, float, float, float, tagYYRECT*)+0x1d0×2 / spSkeletonBounds_containsPoint×2 / 0xb6598×2 / CSkeletonInstance::SetAnimationTransform(int, float, float, float, float, float, CInstance*) / CSkeletonInstance::EllipseCollision(int, float, float, float, float, float, tagYYRECT*)+0x3ec / 0xb6580 / 0xb658c
 * 字段偏移 top8: 0x20×3 / 0xc×2 / 0x8c×1 / 0x8×1 / 0x4×1 / 0x1c×1
 * VFP 指令 164 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbf524 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xbf528 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0xbf52c sub sp, sp, #36
 *   @0xbf530 vldr s30, [sp, #128]
 *   @0xbf534 mov r12, #0
 *   @0xbf538 vldr s31, [sp, #132]
 *   @0xbf53c ldr r4, [sp, #0x8c]
 *   @0xbf540 vldr s16, [sp, #136]
 *   @0xbf544 str r12, [sp, #0xc]
 *   @0xbf548 vstr s30, [sp]
 *   @0xbf54c vstr s31, [sp, #4]
 *   @0xbf550 vstr s16, [sp, #8]
 *   @0xbf554 mov r9, r0
 *   @0xbf558 vmov s27, r2
 *   @0xbf55c vmov s29, r3
 *   @0xbf560 bl 0xbe80c <_ZN17CSkeletonInstance21SetAnimationTransformEifffffP9CInstance>
 *   @0xbf564 ldr r0, [r4]
 *   @0xbf568 vmov.f32 s19, #1.000000e+00
 *   @0xbf56c ldr r3, [r9, #0x20]
 *   @0xbf570 vldr s14, [r3, #12]
 *   @0xbf574 ldr r12, [r4, #0x8]
 *   @0xbf578 vldr s12, [r3, #20]
 *   @0xbf57c vmov s10, r0
 *   @0xbf580 ldr r2, [r4, #0x4]
 *   @0xbf584 ldr r1, [r4, #0xc]
 *   @0xbf588 add r4, r0, r12
 *   @0xbf58c vmov s13, r12
 *   @0xbf590 rsb r0, r0, r12
 *   @0xbf594 add r4, r4, r4, lsr #31
 *   @0xbf598 add r0, r0, r0, lsr #31
 *   @0xbf59c asr r4, r4, #1
 *   @0xbf5a0 asr r0, r0, #1
 *   @0xbf5a4 vcvt.f32.s32 s15, s10
 *   @0xbf5a8 vmov s10, r2
 *   @0xbf5ac vcmpe.f32 s14, s15
 *   @0xbf5b0 vmrs APSR_nzcv, fpscr
 *   @0xbf5b4 vcvtle.s32.f32 s15, s15
 *   @0xbf5b8 vmovle r6, s15
 *   @0xbf5bc vcvt.f32.s32 s15, s13
 *   @0xbf5c0 vcvtgt.s32.f32 s11, s14
 *   @0xbf5c4 vcmpe.f32 s12, s15
 *   @0xbf5c8 vmovgt r6, s11
 *   @0xbf5cc vcvt.f32.s32 s13, s10
 *   @0xbf5d0 vmrs APSR_nzcv, fpscr
 *   @0xbf5d4 vmov s10, r1
 *   @0xbf5d8 vcvtmi.s32.f32 s15, s12
 *   @0xbf5dc vcvtpl.s32.f32 s15, s15
 *   @0xbf5e0 vmov r8, s15
 *   @0xbf5e4 vldr s15, [r3, #16]
 *   @0xbf5e8 vcmpe.f32 s15, s13
 *   @0xbf5ec vmrs APSR_nzcv, fpscr
 *   @0xbf5f0 vcvtgt.s32.f32 s11, s15
 *   @0xbf5f4 vcvtle.s32.f32 s13, s13
 *   @0xbf5f8 vmovgt r7, s11
 *   @0xbf5fc vcvt.f32.s32 s11, s10
 *   @0xbf600 vmovle r7, s13
 *   @0xbf604 vldr s13, [r3, #24]
 *   @0xbf608 add r3, r2, r1
 *   @0xbf60c rsb r2, r2, r1
 *   @0xbf610 add r3, r3, r3, lsr #31
 *   @0xbf614 add r2, r2, r2, lsr #31
 *   @0xbf618 asr r3, r3, #1
 *   @0xbf61c asr r2, r2, #1
 *   @0xbf620 vcmpe.f32 s13, s11
 *   @0xbf624 vmov s17, r3
 *   @0xbf628 ldr r3, [r9, #0x1c]
 *   @0xbf62c vmov s10, r2
 *   @0xbf630 vldr s26, [r3, #88]
 *   @0xbf634 vldr s28, [r3, #92]
 *   @0xbf638 vmrs APSR_nzcv, fpscr
 *   @0xbf63c vsub.f32 s12, s12, s14
 *   @0xbf640 vcvtmi.s32.f32 s11, s13
 *   @0xbf644 vstr s12, [sp, #16]
 *   @0xbf648 vmov s12, r4
 *   @0xbf64c vsub.f32 s13, s13, s15
 *   @0xbf650 vcmp.f32 s30, s19
 *   @0xbf654 vstr s13, [sp, #20]
 *   @0xbf658 vmov s13, r0
 *   @0xbf65c vcvtpl.s32.f32 s11, s11
 *   @0xbf660 vmrs APSR_nzcv, fpscr
 *   @0xbf664 movne r1, #0
 *   @0xbf668 moveq r1, #1
 *   @0xbf66c vcvt.f32.s32 s12, s12
 *   @0xbf670 vmov r5, s11
 *   @0xbf674 vcvt.f32.s32 s13, s13
 *   @0xbf678 vstr s12, [sp, #24]
 *   @0xbf67c vcmp.f32 s31, s19
 *   @0xbf680 vstr s13, [sp, #28]
 *   @0xbf684 vmrs APSR_nzcv, fpscr
 *   @0xbf688 movne r1, #0
 *   @0xbf68c andeq r1, r1, #1
 *   @0xbf690 cmp r1, #0
 *   @0xbf694 vcvt.f32.s32 s17, s17
 *   @0xbf698 vcvt.f32.s32 s18, s10
 *   @0xbf69c vsub.f32 s26, s26, s14
 *   @0xbf6a0 vsub.f32 s28, s28, s15
 *   @0xbf6a4 beq 0xbf7ac <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x288>
 *   @0xbf6a8 vldr s15, [pc, #624]
 *   @0xbf6ac vabs.f32 s14, s16
 *   @0xbf6b0 vcmpe.f32 s14, s15
 *   @0xbf6b4 vmrs APSR_nzcv, fpscr
 *   @0xbf6b8 bpl 0xbf7ac <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x288>
 *   @0xbf6bc cmp r6, r8
 *   @0xbf6c0 bgt 0xbf900 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3dc>
 *   @0xbf6c4 vmov.f32 s20, #5.000000e-01
 *   @0xbf6c8 cmp r7, r5
 *   @0xbf6cc bgt 0xbf910 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3ec>
 *   @0xbf6d0 vmov s13, r6
 *   @0xbf6d4 vldr s14, [sp, #24]
 *   @0xbf6d8 vldr s15, [sp, #28]
 *   @0xbf6dc mov r4, r7
 *   @0xbf6e0 vcvt.f32.s32 s21, s13
 *   @0xbf6e4 vsub.f32 s16, s21, s14
 *   @0xbf6e8 vdiv.f32 s16, s16, s15
 *   @0xbf6ec vmul.f32 s16, s16, s16
 *   @0xbf6f0 b 0xbf700 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1dc>
 *   @0xbf6f4 add r4, r4, #1
 *   @0xbf6f8 cmp r5, r4
 *   @0xbf6fc blt 0xbf910 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3ec>
 *   @0xbf700 vmov s11, r4
 *   @0xbf704 vmov.f32 s12, s16
 *   @0xbf708 vcvt.f32.s32 s14, s11
 *   @0xbf70c vsub.f32 s15, s14, s17
 *   @0xbf710 vdiv.f32 s15, s15, s18
 *   @0xbf714 vmla.f32 s12, s15, s15
 *   @0xbf718 vcmpe.f32 s12, s19
 *   @0xbf71c vmrs APSR_nzcv, fpscr
 *   @0xbf720 bgt 0xbf6f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1d0>
 *   @0xbf724 vsub.f32 s15, s27, s26
 *   @0xbf728 vsub.f32 s15, s15, s20
 *   @0xbf72c vcvt.s32.f32 s15, s15
 *   @0xbf730 vmov r3, s15
 *   @0xbf734 subs r3, r6, r3
 *   @0xbf738 bmi 0xbf6f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1d0>
 *   @0xbf73c vmov s13, r3
 *   @0xbf740 vldr s10, [sp, #16]
 *   @0xbf744 vcvt.f32.s32 s15, s13
 *   @0xbf748 vcmpe.f32 s10, s15
 *   @0xbf74c vmrs APSR_nzcv, fpscr
 *   @0xbf750 bls 0xbf6f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1d0>
 *   @0xbf754 vsub.f32 s15, s29, s28
 *   @0xbf758 vsub.f32 s15, s15, s20
 *   @0xbf75c vcvt.s32.f32 s15, s15
 *   @0xbf760 vmov r3, s15
 *   @0xbf764 subs r3, r4, r3
 *   @0xbf768 bmi 0xbf6f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1d0>
 *   @0xbf76c vmov s11, r3
 *   @0xbf770 vldr s12, [sp, #20]
 *   @0xbf774 vcvt.f32.s32 s15, s11
 *   @0xbf778 vcmpe.f32 s12, s15
 *   @0xbf77c vmrs APSR_nzcv, fpscr
 *   @0xbf780 bls 0xbf6f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1d0>
 *   @0xbf784 ldr r0, [r9, #0x20]
 *   @0xbf788 vmov r1, s21
 *   @0xbf78c vmov r2, s14
 *   @0xbf790 bl 0x28ac8c <spSkeletonBounds_containsPoint>
 *   @0xbf794 cmp r0, #0
 *   @0xbf798 beq 0xbf6f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1d0>
 *   @0xbf79c mov r0, #1
 *   @0xbf7a0 add sp, sp, #36
 *   @0xbf7a4 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0xbf7a8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xbf7ac vldr s20, [pc, #368]
 *   @0xbf7b0 vnmul.f32 s15, s16, s20
 *   @0xbf7b4 vldr s19, [pc, #364]
 *   @0xbf7b8 vdiv.f32 s15, s15, s19
 *   @0xbf7bc vmul.f32 s16, s16, s20
 *   @0xbf7c0 vmov r0, s15
 *   @0xbf7c4 bl 0xb6580 <sinf@plt>
 *   @0xbf7c8 vdiv.f32 s16, s16, s19
 *   @0xbf7cc vmov s23, r0
 *   @0xbf7d0 vmov r0, s16
 *   @0xbf7d4 bl 0xb658c <cosf@plt>
 *   @0xbf7d8 cmp r6, r8
 *   @0xbf7dc vmov s24, r0
 *   @0xbf7e0 bgt 0xbf900 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3dc>
 *   @0xbf7e4 vmov.f32 s20, #1.000000e+00
 *   @0xbf7e8 cmp r7, r5
 *   @0xbf7ec bgt 0xbf8f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3d0>
 *   @0xbf7f0 vmov s11, r6
 *   @0xbf7f4 vldr s12, [sp, #24]
 *   @0xbf7f8 vldr s13, [sp, #28]
 *   @0xbf7fc mov r4, r7
 *   @0xbf800 vcvt.f32.s32 s25, s11
 *   @0xbf804 vsub.f32 s19, s25, s12
 *   @0xbf808 vdiv.f32 s19, s19, s13
 *   @0xbf80c vmul.f32 s19, s19, s19
 *   @0xbf810 b 0xbf81c <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f8>
 *   @0xbf814 cmp r5, r4
 *   @0xbf818 blt 0xbf8f4 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3d0>
 *   @0xbf81c vmov s10, r4
 *   @0xbf820 add r4, r4, #1
 *   @0xbf824 vmov.f32 s11, s19
 *   @0xbf828 vcvt.f32.s32 s16, s10
 *   @0xbf82c vsub.f32 s15, s16, s17
 *   @0xbf830 vdiv.f32 s15, s15, s18
 *   @0xbf834 vmla.f32 s11, s15, s15
 *   @0xbf838 vcmpe.f32 s11, s20
 *   @0xbf83c vmrs APSR_nzcv, fpscr
 *   @0xbf840 bgt 0xbf814 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f0>
 *   @0xbf844 vsub.f32 s21, s16, s29
 *   @0xbf848 vmul.f32 s15, s21, s23
 *   @0xbf84c vsub.f32 s22, s25, s27
 *   @0xbf850 vmla.f32 s15, s22, s24
 *   @0xbf854 vdiv.f32 s15, s15, s30
 *   @0xbf858 vmul.f32 s22, s23, s22
 *   @0xbf85c vnmls.f32 s22, s24, s21
 *   @0xbf860 vdiv.f32 s22, s22, s31
 *   @0xbf864 vadd.f32 s15, s15, s26
 *   @0xbf868 vcvt.f64.f32 d6, s15
 *   @0xbf86c vmov r0, r1, d6
 *   @0xbf870 bl 0xb6598 <floor@plt>
 *   @0xbf874 vadd.f32 s22, s22, s28
 *   @0xbf878 vcvt.f64.f32 d5, s22
 *   @0xbf87c vmov d7, r0, r1
 *   @0xbf880 vmov r0, r1, d5
 *   @0xbf884 vcvt.s32.f64 s21, d7
 *   @0xbf888 bl 0xb6598 <floor@plt>
 *   @0xbf88c vmov r3, s21
 *   @0xbf890 cmp r3, #0
 *   @0xbf894 vmov d7, r0, r1
 *   @0xbf898 blt 0xbf814 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f0>
 *   @0xbf89c vcvt.f32.s32 s21, s21
 *   @0xbf8a0 vldr s10, [sp, #16]
 *   @0xbf8a4 vcmpe.f32 s10, s21
 *   @0xbf8a8 vmrs APSR_nzcv, fpscr
 *   @0xbf8ac bls 0xbf814 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f0>
 *   @0xbf8b0 vcvt.s32.f64 s14, d7
 *   @0xbf8b4 vmov r3, s14
 *   @0xbf8b8 cmp r3, #0
 *   @0xbf8bc blt 0xbf814 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f0>
 *   @0xbf8c0 vcvt.f32.s32 s14, s14
 *   @0xbf8c4 vldr s10, [sp, #20]
 *   @0xbf8c8 vcmpe.f32 s10, s14
 *   @0xbf8cc vmrs APSR_nzcv, fpscr
 *   @0xbf8d0 bls 0xbf814 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f0>
 *   @0xbf8d4 ldr r0, [r9, #0x20]
 *   @0xbf8d8 vmov r1, s25
 *   @0xbf8dc vmov r2, s16
 *   @0xbf8e0 bl 0x28ac8c <spSkeletonBounds_containsPoint>
 *   @0xbf8e4 cmp r0, #0
 *   @0xbf8e8 bne 0xbf79c <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x278>
 *   @0xbf8ec cmp r5, r4
 *   @0xbf8f0 bge 0xbf81c <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2f8>
 *   @0xbf8f4 add r6, r6, #1
 *   @0xbf8f8 cmp r8, r6
 *   @0xbf8fc bge 0xbf7e8 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x2c4>
 *   @0xbf900 mov r0, #0
 *   @0xbf904 add sp, sp, #36
 *   @0xbf908 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0xbf90c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xbf910 add r6, r6, #1
 *   @0xbf914 cmp r8, r6
 *   @0xbf918 bge 0xbf6c8 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x1a4>
 *   @0xbf91c b 0xbf900 <_ZN17CSkeletonInstance16EllipseCollisionEifffffP9tagYYRECT+0x3dc>
 *   @0xbf920 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0xbf924 ldrdmi r0, r1, [r9], #-251
 *   @0xbf928 teqmi r4, #0
 *
 * ══ §16/31 loadTexture(zip*, char const*, int*, int*)  0x28fe70  size 1028  257 条（0x28fe70..0x290274）
 * @func 0x28fe70 0x290274  size 1028  257 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29004c→0x479bb4, 0x290068→0x479bbc, 0x290084→0x3eb70c, 0x2900bc→0x479bb0, 0x290104→0x479b88, 0x290180→0x3eb70c, 0x2901cc→0x3eb70c, 0x29020c→0x3eb70c
 * 调用序列: png_destroy_read_struct×4 / png_create_info_struct×2 / operator new[](unsigned int)×2 / operator delete[](void*)×2 / zip_fclose×2 / zip_fopen / zip_fread / png_sig_cmp
 * 字段偏移 top8: 0x18×11 / 0x2c×10 / 0x44×7 / 0xc×6 / 0x30×5 / 0x1c×4 / 0x54×3 / 0x40×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28fe70 push {r4, r5, r6, r7, lr}
 *   @0x28fe74 sub sp, sp, #92
 *   @0x28fe78 ldr r5, [pc, #0x3bc]
 *   @0x28fe7c mov r4, r1
 *   @0x28fe80 ldr r12, [pc, #0x3b8]
 *   @0x28fe84 add r5, pc, r5
 *   @0x28fe88 str r2, [sp, #0x20]
 *   @0x28fe8c str r5, [sp, #0x18]
 *   @0x28fe90 mov r2, #0
 *   @0x28fe94 str r3, [sp, #0x24]
 *   @0x28fe98 ldr r3, [r5, r12]
 *   @0x28fe9c ldr r3, [r3]
 *   @0x28fea0 str r3, [sp, #0x54]
 *   @0x28fea4 blx 0x2a44b8 <zip_fopen>
 *   @0x28fea8 subs r12, r0, #0
 *   @0x28feac str r12, [sp, #0x1c]
 *   @0x28feb0 beq 0x29020c <_Z11loadTextureP3zipPKcPiS3_+0x39c>
 *   @0x28feb4 add r4, sp, #76
 *   @0x28feb8 mov r2, #8
 *   @0x28febc mov r1, r4
 *   @0x28fec0 blx 0x2a476c <zip_fread>
 *   @0x28fec4 mov r1, #0
 *   @0x28fec8 mov r0, r4
 *   @0x28fecc mov r2, #8
 *   @0x28fed0 blx 0x2a5a4c <png_sig_cmp>
 *   @0x28fed4 subs r1, r0, #0
 *   @0x28fed8 bne 0x2901c8 <_Z11loadTextureP3zipPKcPiS3_+0x358>
 *   @0x28fedc ldr r0, [pc, #0x360]
 *   @0x28fee0 mov r2, r1
 *   @0x28fee4 mov r3, r1
 *   @0x28fee8 add r0, pc, r0
 *   @0x28feec blx 0x2a6fdc <png_create_read_struct>
 *   @0x28fef0 cmp r0, #0
 *   @0x28fef4 str r0, [sp, #0x2c]
 *   @0x28fef8 beq 0x290180 <_Z11loadTextureP3zipPKcPiS3_+0x310>
 *   @0x28fefc blx 0x2a5b64 <png_create_info_struct>
 *   @0x28ff00 cmp r0, #0
 *   @0x28ff04 str r0, [sp, #0x30]
 *   @0x28ff08 beq 0x2901f8 <_Z11loadTextureP3zipPKcPiS3_+0x388>
 *   @0x28ff0c ldr r0, [sp, #0x2c]
 *   @0x28ff10 blx 0x2a5b64 <png_create_info_struct>
 *   @0x28ff14 cmp r0, #0
 *   @0x28ff18 str r0, [sp, #0x34]
 *   @0x28ff1c beq 0x290170 <_Z11loadTextureP3zipPKcPiS3_+0x300>
 *   @0x28ff20 ldr r3, [pc, #0x320]
 *   @0x28ff24 mov r2, #256
 *   @0x28ff28 ldr lr, [sp, #0x18]
 *   @0x28ff2c ldr r0, [sp, #0x2c]
 *   @0x28ff30 ldr r1, [lr, r3]
 *   @0x28ff34 blx 0x2a653c <png_set_longjmp_fn>
 *   @0x28ff38 bl 0xb6904 <setjmp@plt>
 *   @0x28ff3c subs r4, r0, #0
 *   @0x28ff40 bne 0x2901b4 <_Z11loadTextureP3zipPKcPiS3_+0x344>
 *   @0x28ff44 ldr r3, [pc, #0x300]
 *   @0x28ff48 ldr r5, [sp, #0x18]
 *   @0x28ff4c ldr r1, [sp, #0x1c]
 *   @0x28ff50 ldr r0, [sp, #0x2c]
 *   @0x28ff54 ldr r2, [r5, r3]
 *   @0x28ff58 blx 0x2a804c <png_set_read_fn>
 *   @0x28ff5c ldr r0, [sp, #0x2c]
 *   @0x28ff60 mov r1, #8
 *   @0x28ff64 blx 0x2a5a24 <png_set_sig_bytes>
 *   @0x28ff68 ldr r0, [sp, #0x2c]
 *   @0x28ff6c ldr r1, [sp, #0x30]
 *   @0x28ff70 blx 0x2a6ff0 <png_read_info>
 *   @0x28ff74 ldr r1, [sp, #0x30]
 *   @0x28ff78 add r3, sp, #56
 *   @0x28ff7c add r2, sp, #64
 *   @0x28ff80 str r3, [sp]
 *   @0x28ff84 add r3, sp, #60
 *   @0x28ff88 ldr r0, [sp, #0x2c]
 *   @0x28ff8c str r3, [sp, #0x4]
 *   @0x28ff90 add r3, sp, #68
 *   @0x28ff94 str r4, [sp, #0x8]
 *   @0x28ff98 str r4, [sp, #0xc]
 *   @0x28ff9c str r4, [sp, #0x10]
 *   @0x28ffa0 blx 0x2a693e <png_get_IHDR>
 *   @0x28ffa4 ldr r2, [sp, #0x40]
 *   @0x28ffa8 ldr r3, [sp, #0x44]
 *   @0x28ffac ldr r12, [sp, #0x20]
 *   @0x28ffb0 ldr lr, [sp, #0x24]
 *   @0x28ffb4 ldr r0, [sp, #0x2c]
 *   @0x28ffb8 str r2, [r12]
 *   @0x28ffbc ldr r1, [sp, #0x30]
 *   @0x28ffc0 str r3, [lr]
 *   @0x28ffc4 blx 0x2a7448 <png_read_update_info>
 *   @0x28ffc8 ldr r1, [sp, #0x30]
 *   @0x28ffcc ldr r0, [sp, #0x2c]
 *   @0x28ffd0 blx 0x2a6574 <png_get_rowbytes>
 *   @0x28ffd4 mov r5, r0
 *   @0x28ffd8 ldr r0, [sp, #0x44]
 *   @0x28ffdc mul r0, r0, r5
 *   @0x28ffe0 bl 0x27d14c <_Znaj>
 *   @0x28ffe4 subs r6, r0, #0
 *   @0x28ffe8 beq 0x2901b4 <_Z11loadTextureP3zipPKcPiS3_+0x344>
 *   @0x28ffec ldr r0, [sp, #0x44]
 *   @0x28fff0 cmp r0, #532676608
 *   @0x28fff4 lslls r0, r0, #2
 *   @0x28fff8 mvnhi r0, #0
 *   @0x28fffc bl 0x27d14c <_Znaj>
 *   @0x290000 subs r4, r0, #0
 *   @0x290004 beq 0x2901b4 <_Z11loadTextureP3zipPKcPiS3_+0x344>
 *   @0x290008 ldr lr, [sp, #0x44]
 *   @0x29000c cmp lr, #0
 *   @0x290010 movne r12, #0
 *   @0x290014 movne r1, r5
 *   @0x290018 movne r3, r12
 *   @0x29001c movne r2, r6
 *   @0x290020 beq 0x29003c <_Z11loadTextureP3zipPKcPiS3_+0x1cc>
 *   @0x290024 add r3, r3, #1
 *   @0x290028 str r2, [r4, r12, lsl #2]
 *   @0x29002c cmp r3, lr
 *   @0x290030 add r2, r2, r1
 *   @0x290034 mov r12, r3
 *   @0x290038 bne 0x290024 <_Z11loadTextureP3zipPKcPiS3_+0x1b4>
 *   @0x29003c ldr r0, [sp, #0x2c]
 *   @0x290040 mov r1, r4
 *   @0x290044 blx 0x2a7840 <png_read_image>
 *   @0x290048 ldr r2, [sp, #0x18]
 *   @0x29004c ldr r3, [pc, #0x1fc]
 *   @0x290050 mov r0, #1
 *   @0x290054 add r1, sp, #72
 *   @0x290058 ldr r3, [r2, r3]
 *   @0x29005c ldr r3, [r3]
 *   @0x290060 blx r3
 *   @0x290064 ldr r12, [sp, #0x18]
 *   @0x290068 ldr r3, [pc, #0x1e4]
 *   @0x29006c movw r0, #0xde1
 *   @0x290070 ldr r1, [sp, #0x48]
 *   @0x290074 ldr r3, [r12, r3]
 *   @0x290078 ldr r3, [r3]
 *   @0x29007c blx r3
 *   @0x290080 ldr r0, [sp, #0x18]
 *   @0x290084 ldr r3, [pc, #0x1cc]
 *   @0x290088 ldr lr, [sp, #0x3c]
 *   @0x29008c ldr r7, [sp, #0x38]
 *   @0x290090 ldr r1, [r0, r3]
 *   @0x290094 ldr r2, [sp, #0x40]
 *   @0x290098 ldr r3, [sp, #0x44]
 *   @0x29009c ldr r0, [r1]
 *   @0x2900a0 ldr r1, [pc, #0x1b4]
 *   @0x2900a4 ldr r12, [r0]
 *   @0x2900a8 add r1, pc, r1
 *   @0x2900ac stm sp, {r5, r7, lr}
 *   @0x2900b0 ldr r12, [r12, #0xc]
 *   @0x2900b4 blx r12
 *   @0x2900b8 ldr r5, [sp, #0x18]
 *   @0x2900bc ldr r1, [pc, #0x19c]
 *   @0x2900c0 movw r12, #0x1908
 *   @0x2900c4 ldr r2, [sp, #0x44]
 *   @0x2900c8 mov r0, #0
 *   @0x2900cc ldr r3, [sp, #0x40]
 *   @0x2900d0 ldr lr, [r5, r1]
 *   @0x2900d4 mov r1, r0
 *   @0x2900d8 str r2, [sp]
 *   @0x2900dc mov r2, r12
 *   @0x2900e0 str r6, [sp, #0x10]
 *   @0x2900e4 ldr r5, [lr]
 *   @0x2900e8 movw lr, #0x1401
 *   @0x2900ec str r0, [sp, #0x4]
 *   @0x2900f0 movw r0, #0xde1
 *   @0x2900f4 str lr, [sp, #0xc]
 *   @0x2900f8 str r12, [sp, #0x8]
 *   @0x2900fc blx r5
 *   @0x290100 ldr r12, [sp, #0x18]
 *   @0x290104 ldr r3, [pc, #0x158]
 *   @0x290108 movw r0, #0xde1
 *   @0x29010c movw r1, #0x2801
 *   @0x290110 mov r2, #9728
 *   @0x290114 ldr r3, [r12, r3]
 *   @0x290118 ldr r3, [r3]
 *   @0x29011c blx r3
 *   @0x290120 add r1, sp, #48
 *   @0x290124 add r2, sp, #52
 *   @0x290128 add r0, sp, #44
 *   @0x29012c blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x290130 mov r0, r6
 *   @0x290134 bl 0x27d1d4 <_ZdaPv>
 *   @0x290138 mov r0, r4
 *   @0x29013c bl 0x27d1d4 <_ZdaPv>
 *   @0x290140 ldr r0, [sp, #0x1c]
 *   @0x290144 blx 0x2a4388 <zip_fclose>
 *   @0x290148 ldr r0, [sp, #0x48]
 *   @0x29014c ldr r3, [pc, #0xec]
 *   @0x290150 ldr r1, [sp, #0x18]
 *   @0x290154 ldr r2, [sp, #0x54]
 *   @0x290158 ldr r3, [r1, r3]
 *   @0x29015c ldr r3, [r3]
 *   @0x290160 cmp r2, r3
 *   @0x290164 bne 0x290238 <_Z11loadTextureP3zipPKcPiS3_+0x3c8>
 *   @0x290168 add sp, sp, #92
 *   @0x29016c pop {r4, r5, r6, r7, pc}
 *   @0x290170 mov r2, r0
 *   @0x290174 add r1, sp, #48
 *   @0x290178 add r0, sp, #44
 *   @0x29017c blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x290180 ldr r3, [pc, #0xd0]
 *   @0x290184 ldr lr, [sp, #0x18]
 *   @0x290188 ldr r3, [lr, r3]
 *   @0x29018c ldr r0, [r3]
 *   @0x290190 ldr r3, [r0]
 *   @0x290194 ldr r1, [pc, #0xcc]
 *   @0x290198 ldr r3, [r3, #0xc]
 *   @0x29019c add r1, pc, r1
 *   @0x2901a0 blx r3
 *   @0x2901a4 ldr r0, [sp, #0x1c]
 *   @0x2901a8 blx 0x2a4388 <zip_fclose>
 *   @0x2901ac mvn r0, #0
 *   @0x2901b0 b 0x29014c <_Z11loadTextureP3zipPKcPiS3_+0x2dc>
 *   @0x2901b4 add r0, sp, #44
 *   @0x2901b8 add r1, sp, #48
 *   @0x2901bc add r2, sp, #52
 *   @0x2901c0 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x2901c4 b 0x290180 <_Z11loadTextureP3zipPKcPiS3_+0x310>
 *   @0x2901c8 ldr r0, [sp, #0x18]
 *   @0x2901cc ldr r3, [pc, #0x84]
 *   @0x2901d0 ldr r1, [pc, #0x94]
 *   @0x2901d4 ldr r3, [r0, r3]
 *   @0x2901d8 add r1, pc, r1
 *   @0x2901dc ldr r4, [r3]
 *   @0x2901e0 ldr r3, [r4]
 *   @0x2901e4 mov r0, r4
 *   @0x2901e8 ldr r3, [r3, #0xc]
 *   @0x2901ec blx r3
 *   @0x2901f0 mov r0, r4
 *   @0x2901f4 b 0x290190 <_Z11loadTextureP3zipPKcPiS3_+0x320>
 *   @0x2901f8 mov r1, r0
 *   @0x2901fc add r0, sp, #44
 *   @0x290200 mov r2, r1
 *   @0x290204 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x290208 b 0x290180 <_Z11loadTextureP3zipPKcPiS3_+0x310>
 *   @0x29020c ldr r3, [pc, #0x44]
 *   @0x290210 mov r2, r4
 *   @0x290214 ldr r1, [pc, #0x54]
 *   @0x290218 ldr r3, [r5, r3]
 *   @0x29021c add r1, pc, r1
 *   @0x290220 ldr r0, [r3]
 *   @0x290224 ldr r3, [r0]
 *   @0x290228 ldr r3, [r3, #0xc]
 *   @0x29022c blx r3
 *   @0x290230 mvn r0, #0
 *   @0x290234 b 0x29014c <_Z11loadTextureP3zipPKcPiS3_+0x2dc>
 *   @0x290238 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x29023c andseq r1, r6, r12, asr #27
 *   @0x290240 .word 0xffffbd00
 *   @0x290244 andeq r10, r11, r4, asr r7
 *   @0x290248 .word 0xffffe4ac
 *   @0x29024c .word 0xfffffcd0
 *   @0x290250 .word 0xffffbb28
 *   @0x290254 .word 0xffffbb20
 *   @0x290258 .word 0xffffbac4
 *   @0x29025c ldrdeq r11, r12, [r11], -r4
 *   @0x290260 .word 0xffffbb2c
 *   @0x290264 .word 0xffffbb44
 *   @0x290268 strdeq r7, r8, [r12], -r0
 *   @0x29026c strdeq r11, r12, [r11], -r4
 *   @0x290270 andeq r7, r12, r0, asr pc
 *
 * ══ §17/31 Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess  0x293374  size 1028  257 条（0x293374..0x293778）
 * @func 0x293374 0x293778  size 1028  257 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×7 / 0xb6640×7 / setJNIEnv / operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool)
 * 字段偏移 top8: 0x2a4×7 / 0x2a8×7 / 0x34×4 / 0x2c×4 / 0x30×3 / 0x60×3 / 0x64×3 / 0x68×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x293374 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x293378 sub sp, sp, #60
 *   @0x29337c mov r4, r0
 *   @0x293380 ldr r5, [pc, #0x3cc]
 *   @0x293384 str r2, [sp, #0x30]
 *   @0x293388 str r3, [sp, #0x34]
 *   @0x29338c bl 0x290614 <setJNIEnv>
 *   @0x293390 ldr r3, [r4]
 *   @0x293394 mov r2, #0
 *   @0x293398 ldr r1, [sp, #0x30]
 *   @0x29339c mov r0, r4
 *   @0x2933a0 add r5, pc, r5
 *   @0x2933a4 ldr r3, [r3, #0x2a4]
 *   @0x2933a8 blx r3
 *   @0x2933ac ldr r3, [r4]
 *   @0x2933b0 ldr r1, [sp, #0x34]
 *   @0x2933b4 mov r2, #0
 *   @0x2933b8 ldr r3, [r3, #0x2a4]
 *   @0x2933bc str r0, [sp, #0x2c]
 *   @0x2933c0 mov r0, r4
 *   @0x2933c4 blx r3
 *   @0x2933c8 ldr r3, [r4]
 *   @0x2933cc ldr r1, [sp, #0x60]
 *   @0x2933d0 mov r2, #0
 *   @0x2933d4 ldr r3, [r3, #0x2a4]
 *   @0x2933d8 mov r9, r0
 *   @0x2933dc mov r0, r4
 *   @0x2933e0 blx r3
 *   @0x2933e4 ldr r3, [r4]
 *   @0x2933e8 ldr r1, [sp, #0x64]
 *   @0x2933ec mov r2, #0
 *   @0x2933f0 ldr r3, [r3, #0x2a4]
 *   @0x2933f4 mov r8, r0
 *   @0x2933f8 mov r0, r4
 *   @0x2933fc blx r3
 *   @0x293400 ldr r3, [r4]
 *   @0x293404 ldr r1, [sp, #0x68]
 *   @0x293408 mov r2, #0
 *   @0x29340c ldr r3, [r3, #0x2a4]
 *   @0x293410 mov r7, r0
 *   @0x293414 mov r0, r4
 *   @0x293418 blx r3
 *   @0x29341c ldr r3, [r4]
 *   @0x293420 ldr r1, [sp, #0x6c]
 *   @0x293424 mov r2, #0
 *   @0x293428 ldr r3, [r3, #0x2a4]
 *   @0x29342c mov r6, r0
 *   @0x293430 mov r0, r4
 *   @0x293434 blx r3
 *   @0x293438 ldr r3, [r4]
 *   @0x29343c ldr r1, [sp, #0x70]
 *   @0x293440 mov r2, #0
 *   @0x293444 ldr r3, [r3, #0x2a4]
 *   @0x293448 mov r11, r0
 *   @0x29344c mov r0, r4
 *   @0x293450 blx r3
 *   @0x293454 ldr r3, [pc, #0x2fc]
 *   @0x293458 ldr r3, [r5, r3]
 *   @0x29345c str r3, [sp, #0x14]
 *   @0x293460 mov r10, r0
 *   @0x293464 ldr r0, [r3]
 *   @0x293468 cmp r0, #0
 *   @0x29346c beq 0x293480 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x10c>
 *   @0x293470 bl 0xb655c <free@plt>
 *   @0x293474 ldr r2, [sp, #0x14]
 *   @0x293478 mov r3, #0
 *   @0x29347c str r3, [r2]
 *   @0x293480 ldr r3, [pc, #0x2d4]
 *   @0x293484 ldr r3, [r5, r3]
 *   @0x293488 ldr r0, [r3]
 *   @0x29348c str r3, [sp, #0x18]
 *   @0x293490 cmp r0, #0
 *   @0x293494 beq 0x2934a8 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x134>
 *   @0x293498 bl 0xb655c <free@plt>
 *   @0x29349c ldr r2, [sp, #0x18]
 *   @0x2934a0 mov r3, #0
 *   @0x2934a4 str r3, [r2]
 *   @0x2934a8 ldr r3, [pc, #0x2b0]
 *   @0x2934ac ldr r3, [r5, r3]
 *   @0x2934b0 ldr r0, [r3]
 *   @0x2934b4 str r3, [sp, #0x10]
 *   @0x2934b8 cmp r0, #0
 *   @0x2934bc beq 0x2934d0 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x15c>
 *   @0x2934c0 bl 0xb655c <free@plt>
 *   @0x2934c4 ldr r2, [sp, #0x10]
 *   @0x2934c8 mov r3, #0
 *   @0x2934cc str r3, [r2]
 *   @0x2934d0 ldr r3, [pc, #0x28c]
 *   @0x2934d4 ldr r3, [r5, r3]
 *   @0x2934d8 ldr r0, [r3]
 *   @0x2934dc str r3, [sp, #0x20]
 *   @0x2934e0 cmp r0, #0
 *   @0x2934e4 beq 0x2934f8 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x184>
 *   @0x2934e8 bl 0xb655c <free@plt>
 *   @0x2934ec ldr r2, [sp, #0x20]
 *   @0x2934f0 mov r3, #0
 *   @0x2934f4 str r3, [r2]
 *   @0x2934f8 ldr r3, [pc, #0x268]
 *   @0x2934fc ldr r3, [r5, r3]
 *   @0x293500 ldr r0, [r3]
 *   @0x293504 str r3, [sp, #0x1c]
 *   @0x293508 cmp r0, #0
 *   @0x29350c beq 0x293520 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x1ac>
 *   @0x293510 bl 0xb655c <free@plt>
 *   @0x293514 ldr r2, [sp, #0x1c]
 *   @0x293518 mov r3, #0
 *   @0x29351c str r3, [r2]
 *   @0x293520 ldr r3, [pc, #0x244]
 *   @0x293524 ldr r3, [r5, r3]
 *   @0x293528 ldr r0, [r3]
 *   @0x29352c str r3, [sp, #0x24]
 *   @0x293530 cmp r0, #0
 *   @0x293534 beq 0x293548 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x1d4>
 *   @0x293538 bl 0xb655c <free@plt>
 *   @0x29353c ldr r2, [sp, #0x24]
 *   @0x293540 mov r3, #0
 *   @0x293544 str r3, [r2]
 *   @0x293548 ldr r3, [pc, #0x220]
 *   @0x29354c ldr r3, [r5, r3]
 *   @0x293550 ldr r0, [r3]
 *   @0x293554 str r3, [sp, #0x28]
 *   @0x293558 cmp r0, #0
 *   @0x29355c beq 0x293570 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x1fc>
 *   @0x293560 bl 0xb655c <free@plt>
 *   @0x293564 ldr r2, [sp, #0x28]
 *   @0x293568 mov r3, #0
 *   @0x29356c str r3, [r2]
 *   @0x293570 ldr r0, [sp, #0x2c]
 *   @0x293574 bl 0xb6640 <strdup@plt>
 *   @0x293578 ldr r3, [sp, #0x14]
 *   @0x29357c str r0, [r3]
 *   @0x293580 mov r0, r9
 *   @0x293584 bl 0xb6640 <strdup@plt>
 *   @0x293588 ldr r2, [sp, #0x18]
 *   @0x29358c str r0, [r2]
 *   @0x293590 mov r0, r8
 *   @0x293594 bl 0xb6640 <strdup@plt>
 *   @0x293598 ldr r3, [sp, #0x10]
 *   @0x29359c str r0, [r3]
 *   @0x2935a0 mov r0, r7
 *   @0x2935a4 bl 0xb6640 <strdup@plt>
 *   @0x2935a8 ldr r2, [sp, #0x20]
 *   @0x2935ac str r0, [r2]
 *   @0x2935b0 mov r0, r6
 *   @0x2935b4 bl 0xb6640 <strdup@plt>
 *   @0x2935b8 ldr r3, [sp, #0x1c]
 *   @0x2935bc str r0, [r3]
 *   @0x2935c0 mov r0, r11
 *   @0x2935c4 bl 0xb6640 <strdup@plt>
 *   @0x2935c8 ldr r2, [sp, #0x24]
 *   @0x2935cc str r0, [r2]
 *   @0x2935d0 mov r0, r10
 *   @0x2935d4 bl 0xb6640 <strdup@plt>
 *   @0x2935d8 ldr r3, [sp, #0x2c]
 *   @0x2935dc ldr r2, [sp, #0x30]
 *   @0x2935e0 cmp r3, #0
 *   @0x2935e4 cmpne r2, #0
 *   @0x2935e8 ldr r3, [sp, #0x28]
 *   @0x2935ec str r0, [r3]
 *   @0x2935f0 bne 0x293738 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x3c4>
 *   @0x2935f4 ldr r3, [sp, #0x34]
 *   @0x2935f8 cmp r9, #0
 *   @0x2935fc cmpne r3, #0
 *   @0x293600 bne 0x29371c <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x3a8>
 *   @0x293604 ldr r3, [sp, #0x60]
 *   @0x293608 cmp r8, #0
 *   @0x29360c cmpne r3, #0
 *   @0x293610 bne 0x293700 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x38c>
 *   @0x293614 ldr r3, [sp, #0x64]
 *   @0x293618 cmp r7, #0
 *   @0x29361c cmpne r3, #0
 *   @0x293620 bne 0x2936e4 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x370>
 *   @0x293624 ldr r3, [sp, #0x68]
 *   @0x293628 cmp r6, #0
 *   @0x29362c cmpne r3, #0
 *   @0x293630 bne 0x2936c8 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x354>
 *   @0x293634 ldr r3, [sp, #0x6c]
 *   @0x293638 cmp r11, #0
 *   @0x29363c cmpne r3, #0
 *   @0x293640 bne 0x2936ac <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x338>
 *   @0x293644 ldr r3, [sp, #0x70]
 *   @0x293648 cmp r10, #0
 *   @0x29364c cmpne r3, #0
 *   @0x293650 beq 0x29366c <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x2f8>
 *   @0x293654 ldr r3, [r4]
 *   @0x293658 mov r2, r10
 *   @0x29365c ldr r1, [sp, #0x70]
 *   @0x293660 mov r0, r4
 *   @0x293664 ldr r3, [r3, #0x2a8]
 *   @0x293668 blx r3
 *   @0x29366c mov r0, #68
 *   @0x293670 bl 0x27c524 <_Znwj>
 *   @0x293674 ldr r3, [pc, #0xf8]
 *   @0x293678 mov r12, #0
 *   @0x29367c mov r1, r12
 *   @0x293680 mov r2, r12
 *   @0x293684 ldr r3, [r5, r3]
 *   @0x293688 str r12, [sp]
 *   @0x29368c str r12, [sp, #0x4]
 *   @0x293690 str r12, [sp, #0x8]
 *   @0x293694 mov r4, r0
 *   @0x293698 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0x29369c mov r3, #7
 *   @0x2936a0 str r3, [r4, #0xc]
 *   @0x2936a4 add sp, sp, #60
 *   @0x2936a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2936ac ldr r3, [r4]
 *   @0x2936b0 mov r2, r11
 *   @0x2936b4 ldr r1, [sp, #0x6c]
 *   @0x2936b8 mov r0, r4
 *   @0x2936bc ldr r3, [r3, #0x2a8]
 *   @0x2936c0 blx r3
 *   @0x2936c4 b 0x293644 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x2d0>
 *   @0x2936c8 ldr r3, [r4]
 *   @0x2936cc mov r2, r6
 *   @0x2936d0 ldr r1, [sp, #0x68]
 *   @0x2936d4 mov r0, r4
 *   @0x2936d8 ldr r3, [r3, #0x2a8]
 *   @0x2936dc blx r3
 *   @0x2936e0 b 0x293634 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x2c0>
 *   @0x2936e4 ldr r3, [r4]
 *   @0x2936e8 mov r2, r7
 *   @0x2936ec ldr r1, [sp, #0x64]
 *   @0x2936f0 mov r0, r4
 *   @0x2936f4 ldr r3, [r3, #0x2a8]
 *   @0x2936f8 blx r3
 *   @0x2936fc b 0x293624 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x2b0>
 *   @0x293700 ldr r3, [r4]
 *   @0x293704 mov r2, r8
 *   @0x293708 ldr r1, [sp, #0x60]
 *   @0x29370c mov r0, r4
 *   @0x293710 ldr r3, [r3, #0x2a8]
 *   @0x293714 blx r3
 *   @0x293718 b 0x293614 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x2a0>
 *   @0x29371c ldr r3, [r4]
 *   @0x293720 mov r2, r9
 *   @0x293724 ldr r1, [sp, #0x34]
 *   @0x293728 mov r0, r4
 *   @0x29372c ldr r3, [r3, #0x2a8]
 *   @0x293730 blx r3
 *   @0x293734 b 0x293604 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x290>
 *   @0x293738 ldr r3, [r4]
 *   @0x29373c mov r1, r2
 *   @0x293740 mov r0, r4
 *   @0x293744 ldr r2, [sp, #0x2c]
 *   @0x293748 ldr r3, [r3, #0x2a8]
 *   @0x29374c blx r3
 *   @0x293750 b 0x2935f4 <Java_com_yoyogames_runner_RunnerJNILib_OnLoginSuccess+0x280>
 *   @0x293754 ldrheq lr, [r5], -r0
 *   @0x293758 .word 0xfffffcbc
 *   @0x29375c .word 0xfffffcc0
 *   @0x293760 .word 0xfffffd20
 *   @0x293764 .word 0xfffffd24
 *   @0x293768 .word 0xfffffd28
 *   @0x29376c .word 0xfffffd2c
 *   @0x293770 .word 0xfffffd30
 *   @0x293774 .word 0xfffffd34
 *
 * ══ §18/31 CFontGM::Draw_String_Color(float, float, unsigned short*, unsigned int, unsigned int, unsigned int, unsigned int, float)  0xf8b58  size 1024  256 条（0xf8b58..0xf8f58）
 * @func 0xf8b58 0xf8f58  size 1024  256 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Color_Merge(unsigned int, unsigned int, float)×8 / CFontGM::Draw_String_Color(float, float, unsigned short*, unsigned int, unsigned int, unsigned int, unsigned int, float)+0x54×2 / CFontGM::GetGlyph(int)×2 / yywcslen(unsigned short const*) / CFontGM::TextWidth(unsigned short*) / CFontGM::Draw_String_Color(float, float, unsigned short*, unsigned int, unsigned int, unsigned int, unsigned int, float)+0xe8 / Sprite_Exists(int) / Sprite_Data(int)
 * 字段偏移 top8: 0x3c×5 / 0x20×5 / 0x8c×4 / 0x90×4 / 0x94×4 / 0x88×3 / 0x1c×3 / 0x24×3
 * VFP 指令 112 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf8b58 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf8b5c vpush {d8, d9, d10, d11}
 *   @0xf8b60 sub sp, sp, #68
 *   @0xf8b64 vldr s21, [sp, #152]
 *   @0xf8b68 mov r5, r0
 *   @0xf8b6c mov r0, r3
 *   @0xf8b70 mov r4, r3
 *   @0xf8b74 str r2, [sp, #0x3c]
 *   @0xf8b78 vmov s17, r1
 *   @0xf8b7c bl 0xf6c78 <_Z8yywcslenPKt>
 *   @0xf8b80 mov r1, r4
 *   @0xf8b84 mov r7, r0
 *   @0xf8b88 mov r0, r5
 *   @0xf8b8c bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt>
 *   @0xf8b90 vmov s20, r0
 *   @0xf8b94 ldr r0, [r5, #0x20]
 *   @0xf8b98 cmp r0, #0
 *   @0xf8b9c blt 0xf8c40 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0xe8>
 *   @0xf8ba0 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0xf8ba4 cmp r0, #0
 *   @0xf8ba8 bne 0xf8bb8 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x60>
 *   @0xf8bac add sp, sp, #68
 *   @0xf8bb0 vpop {d8, d9, d10, d11}
 *   @0xf8bb4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf8bb8 ldr r0, [r5, #0x20]
 *   @0xf8bbc bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0xf8bc0 cmp r7, #0
 *   @0xf8bc4 mov r9, r0
 *   @0xf8bc8 ble 0xf8bac <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x54>
 *   @0xf8bcc vldr s16, [pc, #896]
 *   @0xf8bd0 lsl r7, r7, #1
 *   @0xf8bd4 vmov.f32 s22, s16
 *   @0xf8bd8 mov r6, #0
 *   @0xf8bdc ldr r11, [sp, #0x88]
 *   @0xf8be0 b 0xf8bf0 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x98>
 *   @0xf8be4 add r6, r6, #2
 *   @0xf8be8 cmp r6, r7
 *   @0xf8bec beq 0xf8bac <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x54>
 *   @0xf8bf0 ldrh r10, [r4, r6]
 *   @0xf8bf4 cmp r10, #0
 *   @0xf8bf8 beq 0xf8be4 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x8c>
 *   @0xf8bfc mov r1, r10
 *   @0xf8c00 mov r0, r5
 *   @0xf8c04 bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi>
 *   @0xf8c08 ldr r1, [sp, #0x8c]
 *   @0xf8c0c subs r8, r0, #0
 *   @0xf8c10 mov r0, r11
 *   @0xf8c14 beq 0xf8be4 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x8c>
 *   @0xf8c18 cmp r10, #32
 *   @0xf8c1c bne 0xf8db4 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x25c>
 *   @0xf8c20 ldrsh r8, [r8, #10]
 *   @0xf8c24 vldr s14, [r5, #72]
 *   @0xf8c28 vmov s15, r8
 *   @0xf8c2c vcvt.f32.s32 s15, s15
 *   @0xf8c30 vmul.f32 s15, s15, s14
 *   @0xf8c34 vadd.f32 s17, s17, s15
 *   @0xf8c38 vadd.f32 s16, s16, s15
 *   @0xf8c3c b 0xf8be4 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x8c>
 *   @0xf8c40 cmp r7, #0
 *   @0xf8c44 ble 0xf8bac <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x54>
 *   @0xf8c48 vldr s16, [pc, #772]
 *   @0xf8c4c vmov.f32 s22, #1.000000e+00
 *   @0xf8c50 lsl r7, r7, #1
 *   @0xf8c54 mov r6, #0
 *   @0xf8c58 vmov.f32 s23, s16
 *   @0xf8c5c b 0xf8c6c <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x114>
 *   @0xf8c60 add r6, r6, #2
 *   @0xf8c64 cmp r6, r7
 *   @0xf8c68 beq 0xf8bac <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x54>
 *   @0xf8c6c ldrh r1, [r4, r6]
 *   @0xf8c70 cmp r1, #0
 *   @0xf8c74 beq 0xf8c60 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x108>
 *   @0xf8c78 mov r0, r5
 *   @0xf8c7c bl 0xf6d60 <_ZN7CFontGM8GetGlyphEi>
 *   @0xf8c80 ldr r1, [sp, #0x8c]
 *   @0xf8c84 subs r8, r0, #0
 *   @0xf8c88 ldr r0, [sp, #0x88]
 *   @0xf8c8c beq 0xf8c60 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x108>
 *   @0xf8c90 vcvt.f32.s32 s18, s20
 *   @0xf8c94 vdiv.f32 s19, s16, s18
 *   @0xf8c98 vmov r2, s19
 *   @0xf8c9c bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf8ca0 ldr r1, [sp, #0x8c]
 *   @0xf8ca4 mov r11, r0
 *   @0xf8ca8 ldrsh r0, [r8, #10]
 *   @0xf8cac vmov s15, r0
 *   @0xf8cb0 ldr r0, [sp, #0x88]
 *   @0xf8cb4 vcvt.f32.s32 s15, s15
 *   @0xf8cb8 vadd.f32 s15, s15, s16
 *   @0xf8cbc vdiv.f32 s15, s15, s18
 *   @0xf8cc0 vmov r2, s15
 *   @0xf8cc4 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf8cc8 ldrsh r3, [r8, #10]
 *   @0xf8ccc ldr r1, [sp, #0x90]
 *   @0xf8cd0 vmov s15, r3
 *   @0xf8cd4 vcvt.f32.s32 s15, s15
 *   @0xf8cd8 vadd.f32 s15, s15, s16
 *   @0xf8cdc vdiv.f32 s15, s15, s18
 *   @0xf8ce0 mov r10, r0
 *   @0xf8ce4 ldr r0, [sp, #0x94]
 *   @0xf8ce8 vmov r2, s15
 *   @0xf8cec bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf8cf0 ldr r1, [sp, #0x90]
 *   @0xf8cf4 vmov r2, s19
 *   @0xf8cf8 mov r9, r0
 *   @0xf8cfc ldr r0, [sp, #0x94]
 *   @0xf8d00 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf8d04 mov lr, r0
 *   @0xf8d08 ldr r0, [r5, #0x3c]
 *   @0xf8d0c cmp r0, #0
 *   @0xf8d10 beq 0xf8ecc <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x374>
 *   @0xf8d14 ldrsh r12, [r8, #8]
 *   @0xf8d18 vldr s14, [r5, #72]
 *   @0xf8d1c ldrsh r1, [r8, #2]
 *   @0xf8d20 ldrsh r2, [r8, #4]
 *   @0xf8d24 vmov s15, r12
 *   @0xf8d28 ldrsh r3, [r8, #6]
 *   @0xf8d2c vmov s13, r1
 *   @0xf8d30 vcvt.f32.s32 s15, s15
 *   @0xf8d34 vstr s15, [sp]
 *   @0xf8d38 ldrsh r12, [r8, #12]
 *   @0xf8d3c vcvt.f32.s32 s13, s13
 *   @0xf8d40 vstr s14, [sp, #12]
 *   @0xf8d44 vmov s14, r3
 *   @0xf8d48 vstr s23, [sp, #20]
 *   @0xf8d4c vmov s15, r12
 *   @0xf8d50 ldr r12, [sp, #0x3c]
 *   @0xf8d54 str r11, [sp, #0x18]
 *   @0xf8d58 vstr s21, [sp, #40]
 *   @0xf8d5c str r10, [sp, #0x1c]
 *   @0xf8d60 str r12, [sp, #0x8]
 *   @0xf8d64 str r9, [sp, #0x20]
 *   @0xf8d68 vcvt.f32.s32 s15, s15
 *   @0xf8d6c str lr, [sp, #0x24]
 *   @0xf8d70 vmov r1, s13
 *   @0xf8d74 vmov s13, r2
 *   @0xf8d78 ldr lr, [r5, #0x4c]
 *   @0xf8d7c str lr, [sp, #0x10]
 *   @0xf8d80 vadd.f32 s15, s15, s17
 *   @0xf8d84 vcvt.f32.s32 s13, s13
 *   @0xf8d88 vstr s15, [sp, #4]
 *   @0xf8d8c vcvt.f32.s32 s14, s14
 *   @0xf8d90 vmov r2, s13
 *   @0xf8d94 vmov r3, s14
 *   @0xf8d98 bl 0x175a90 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf>
 *   @0xf8d9c ldrsh r8, [r8, #10]
 *   @0xf8da0 vmov s15, r8
 *   @0xf8da4 vcvt.f32.s32 s15, s15
 *   @0xf8da8 vadd.f32 s17, s17, s15
 *   @0xf8dac vadd.f32 s16, s16, s15
 *   @0xf8db0 b 0xf8c60 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x108>
 *   @0xf8db4 vcvt.f32.s32 s18, s20
 *   @0xf8db8 vdiv.f32 s19, s16, s18
 *   @0xf8dbc vmov r2, s19
 *   @0xf8dc0 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf8dc4 ldr r1, [sp, #0x8c]
 *   @0xf8dc8 mov r12, r0
 *   @0xf8dcc ldrsh r0, [r8, #10]
 *   @0xf8dd0 str r12, [sp, #0x34]
 *   @0xf8dd4 vmov s15, r0
 *   @0xf8dd8 mov r0, r11
 *   @0xf8ddc vcvt.f32.s32 s15, s15
 *   @0xf8de0 vadd.f32 s15, s15, s16
 *   @0xf8de4 vdiv.f32 s15, s15, s18
 *   @0xf8de8 vmov r2, s15
 *   @0xf8dec bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf8df0 ldrsh r3, [r8, #10]
 *   @0xf8df4 ldr r1, [sp, #0x90]
 *   @0xf8df8 vmov s15, r3
 *   @0xf8dfc vcvt.f32.s32 s15, s15
 *   @0xf8e00 vadd.f32 s15, s15, s16
 *   @0xf8e04 vdiv.f32 s15, s15, s18
 *   @0xf8e08 str r0, [sp, #0x38]
 *   @0xf8e0c ldr r0, [sp, #0x94]
 *   @0xf8e10 vmov r2, s15
 *   @0xf8e14 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf8e18 ldr r1, [sp, #0x90]
 *   @0xf8e1c vmov r2, s19
 *   @0xf8e20 mov r10, r0
 *   @0xf8e24 ldr r0, [sp, #0x94]
 *   @0xf8e28 bl 0x20ffb8 <_Z11Color_Mergejjf>
 *   @0xf8e2c vldr s13, [r9, #28]
 *   @0xf8e30 vcvt.f32.s32 s14, s13
 *   @0xf8e34 vldr s15, [r5, #72]
 *   @0xf8e38 vldr s13, [r5, #76]
 *   @0xf8e3c ldrsh r1, [r8, #6]
 *   @0xf8e40 vstr s13, [sp, #48]
 *   @0xf8e44 ldr r12, [sp, #0x34]
 *   @0xf8e48 mov r2, #0
 *   @0xf8e4c mov r3, r2
 *   @0xf8e50 vstr s14, [sp]
 *   @0xf8e54 vldr s13, [r9, #32]
 *   @0xf8e58 vcvt.f32.s32 s14, s13
 *   @0xf8e5c vldr s13, [sp, #48]
 *   @0xf8e60 vstr s14, [sp, #4]
 *   @0xf8e64 ldrsh lr, [r8, #12]
 *   @0xf8e68 vstr s13, [sp, #20]
 *   @0xf8e6c vmov.f32 s13, s17
 *   @0xf8e70 str r12, [sp, #0x1c]
 *   @0xf8e74 vstr s15, [sp, #16]
 *   @0xf8e78 vmov s14, lr
 *   @0xf8e7c ldr r12, [sp, #0x3c]
 *   @0xf8e80 vstr s22, [sp, #24]
 *   @0xf8e84 str r10, [sp, #0x24]
 *   @0xf8e88 vcvt.f32.s32 s14, s14
 *   @0xf8e8c vstr s21, [sp, #44]
 *   @0xf8e90 str r12, [sp, #0xc]
 *   @0xf8e94 ldr r12, [sp, #0x38]
 *   @0xf8e98 str r12, [sp, #0x20]
 *   @0xf8e9c vmla.f32 s13, s14, s15
 *   @0xf8ea0 str r0, [sp, #0x28]
 *   @0xf8ea4 mov r0, r9
 *   @0xf8ea8 vstr s13, [sp, #8]
 *   @0xf8eac bl 0x1e5fa8 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf>
 *   @0xf8eb0 ldrsh r8, [r8, #10]
 *   @0xf8eb4 vldr s14, [r5, #72]
 *   @0xf8eb8 vmov s15, r8
 *   @0xf8ebc vcvt.f32.s32 s15, s15
 *   @0xf8ec0 vmla.f32 s17, s15, s14
 *   @0xf8ec4 vadd.f32 s16, s16, s15
 *   @0xf8ec8 b 0xf8be4 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x8c>
 *   @0xf8ecc ldrsh r0, [r8, #8]
 *   @0xf8ed0 ldrsh r1, [r8, #2]
 *   @0xf8ed4 ldrsh r2, [r8, #4]
 *   @0xf8ed8 vmov s15, r0
 *   @0xf8edc ldrsh r3, [r8, #6]
 *   @0xf8ee0 ldr r0, [r5, #0x38]
 *   @0xf8ee4 vmov s13, r1
 *   @0xf8ee8 vcvt.f32.s32 s15, s15
 *   @0xf8eec vmov s14, r3
 *   @0xf8ef0 vstr s15, [sp]
 *   @0xf8ef4 ldrsh r12, [r8, #12]
 *   @0xf8ef8 vcvt.f32.s32 s13, s13
 *   @0xf8efc vstr s22, [sp, #12]
 *   @0xf8f00 vstr s22, [sp, #16]
 *   @0xf8f04 vstr s23, [sp, #20]
 *   @0xf8f08 vmov s15, r12
 *   @0xf8f0c ldr r12, [sp, #0x3c]
 *   @0xf8f10 str r11, [sp, #0x18]
 *   @0xf8f14 vstr s21, [sp, #40]
 *   @0xf8f18 str r10, [sp, #0x1c]
 *   @0xf8f1c str r12, [sp, #0x8]
 *   @0xf8f20 str r9, [sp, #0x20]
 *   @0xf8f24 vcvt.f32.s32 s15, s15
 *   @0xf8f28 str lr, [sp, #0x24]
 *   @0xf8f2c vmov r1, s13
 *   @0xf8f30 vmov s13, r2
 *   @0xf8f34 vadd.f32 s15, s15, s17
 *   @0xf8f38 vcvt.f32.s32 s13, s13
 *   @0xf8f3c vstr s15, [sp, #4]
 *   @0xf8f40 vcvt.f32.s32 s14, s14
 *   @0xf8f44 vmov r2, s13
 *   @0xf8f48 vmov r3, s14
 *   @0xf8f4c bl 0x175834 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf>
 *   @0xf8f50 b 0xf8d9c <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf+0x244>
 *   @0xf8f54 andeq r0, r0, r0
 *
 * ══ §19/31 BeginToEnd()  0x2a180c  size 1024  249 条（0x2a180c..0x2a1c0c）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x2a180c 0x2a1c0c  size 1024  249 条
 * 部分覆盖: 本节 249/256 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2a181c→0x3eb6b8, 0x2a1850→0x47f3c8, 0x2a1860→0x75669a, 0x2a18a0→0x544b88, 0x2a18cc→0x544b78, 0x2a18d0→0x544b74, 0x2a1900→0x3f5228, 0x2a1904→0x3f5224
 * 调用序列: operator new(unsigned int)×3 / Code_Error::Create() / RunnerLoadGame() / 0xb67fc / GetResolution(unsigned char*, int) / CreateDesktopWindow(int, int) / InitGraphics() / IO_Init()
 * 字段偏移 top8: 0xc×17 / 0x2cc×2 / 0x2a4×2 / 0x134×2 / 0xec×2 / 0x364×1 / 0x360×1 / 0x358×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a180c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2a1810 sub sp, sp, #8
 *   @0x2a1814 ldr r7, [pc, #0x364]
 *   @0x2a1818 mov r8, #1
 *   @0x2a181c ldr r3, [pc, #0x360]
 *   @0x2a1820 movw r4, #0x70c
 *   @0x2a1824 add r7, pc, r7
 *   @0x2a1828 ldr r1, [pc, #0x358]
 *   @0x2a182c ldr r3, [r7, r3]
 *   @0x2a1830 add r1, pc, r1
 *   @0x2a1834 ldr r6, [r3]
 *   @0x2a1838 ldr r3, [r6]
 *   @0x2a183c mov r0, r6
 *   @0x2a1840 ldr r3, [r3, #0xc]
 *   @0x2a1844 blx r3
 *   @0x2a1848 mov r0, #8
 *   @0x2a184c bl 0x27c524 <_Znwj>
 *   @0x2a1850 ldr r3, [pc, #0x334]
 *   @0x2a1854 ldr r3, [r7, r3]
 *   @0x2a1858 str r0, [r3]
 *   @0x2a185c bl 0xf1c90 <_ZN10Code_Error6CreateEv>
 *   @0x2a1860 ldr r3, [pc, #0x328]
 *   @0x2a1864 movw lr, #0x808c
 *   @0x2a1868 ldr r1, [r6]
 *   @0x2a186c mov r2, r8
 *   @0x2a1870 mov r0, r6
 *   @0x2a1874 ldr r12, [r7, r3]
 *   @0x2a1878 mov r3, #0
 *   @0x2a187c stm sp, {r4, lr}
 *   @0x2a1880 strb r8, [r12]
 *   @0x2a1884 ldr r12, [r1, #0xc]
 *   @0x2a1888 ldr r1, [pc, #0x304]
 *   @0x2a188c add r1, pc, r1
 *   @0x2a1890 blx r12
 *   @0x2a1894 bl 0x1def08 <_Z14RunnerLoadGamev>
 *   @0x2a1898 mov r0, #0
 *   @0x2a189c bl 0xb67fc <time@plt>
 *   @0x2a18a0 ldr r2, [pc, #0x2f0]
 *   @0x2a18a4 ldr r3, [r6]
 *   @0x2a18a8 ldr r1, [pc, #0x2ec]
 *   @0x2a18ac ldr r2, [r7, r2]
 *   @0x2a18b0 add r1, pc, r1
 *   @0x2a18b4 ldr r3, [r3, #0xc]
 *   @0x2a18b8 mov r4, r0
 *   @0x2a18bc asr r5, r0, #31
 *   @0x2a18c0 mov r0, r6
 *   @0x2a18c4 strd r4, r5, [r2]
 *   @0x2a18c8 blx r3
 *   @0x2a18cc ldr r2, [pc, #0x2cc]
 *   @0x2a18d0 ldr r3, [pc, #0x2cc]
 *   @0x2a18d4 ldr r2, [r7, r2]
 *   @0x2a18d8 ldr r3, [r7, r3]
 *   @0x2a18dc ldr r0, [r2]
 *   @0x2a18e0 ldr r1, [r3]
 *   @0x2a18e4 bl 0x1dd46c <_Z13GetResolutionPhi>
 *   @0x2a18e8 ldr r3, [r6]
 *   @0x2a18ec ldr r1, [pc, #0x2b4]
 *   @0x2a18f0 mov r0, r6
 *   @0x2a18f4 add r1, pc, r1
 *   @0x2a18f8 ldr r3, [r3, #0xc]
 *   @0x2a18fc blx r3
 *   @0x2a1900 ldr r2, [pc, #0x2a4]
 *   @0x2a1904 ldr r3, [pc, #0x2a4]
 *   @0x2a1908 ldr r2, [r7, r2]
 *   @0x2a190c ldr r3, [r7, r3]
 *   @0x2a1910 ldr r0, [r2]
 *   @0x2a1914 ldr r1, [r3]
 *   @0x2a1918 bl 0x1a8854 <_Z19CreateDesktopWindowii>
 *   @0x2a191c ldr r3, [r6]
 *   @0x2a1920 ldr r1, [pc, #0x28c]
 *   @0x2a1924 mov r0, r6
 *   @0x2a1928 add r1, pc, r1
 *   @0x2a192c ldr r3, [r3, #0xc]
 *   @0x2a1930 blx r3
 *   @0x2a1934 bl 0x1df5f0 <_Z12InitGraphicsv>
 *   @0x2a1938 cmp r0, #0
 *   @0x2a193c bne 0x2a1948 <_Z10BeginToEndv+0x13c>
 *   @0x2a1940 add sp, sp, #8
 *   @0x2a1944 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2a1948 ldr r3, [r6]
 *   @0x2a194c mov r0, r6
 *   @0x2a1950 ldr r1, [pc, #0x260]
 *   @0x2a1954 ldr r3, [r3, #0xc]
 *   @0x2a1958 add r1, pc, r1
 *   @0x2a195c blx r3
 *   @0x2a1960 bl 0x18c33c <_Z7IO_Initv>
 *   @0x2a1964 ldr r3, [r6]
 *   @0x2a1968 ldr r1, [pc, #0x24c]
 *   @0x2a196c mov r0, r6
 *   @0x2a1970 add r1, pc, r1
 *   @0x2a1974 ldr r3, [r3, #0xc]
 *   @0x2a1978 blx r3
 *   @0x2a197c bl 0x28fe64 <_Z15ProcessMessagesv>
 *   @0x2a1980 ldr r3, [r6]
 *   @0x2a1984 ldr r1, [pc, #0x234]
 *   @0x2a1988 mov r0, r6
 *   @0x2a198c add r1, pc, r1
 *   @0x2a1990 ldr r3, [r3, #0xc]
 *   @0x2a1994 blx r3
 *   @0x2a1998 bl 0x2a1794 <_Z10DrawSplashv>
 *   @0x2a199c ldr r3, [r6]
 *   @0x2a19a0 ldr r1, [pc, #0x21c]
 *   @0x2a19a4 mov r0, r6
 *   @0x2a19a8 add r1, pc, r1
 *   @0x2a19ac ldr r3, [r3, #0xc]
 *   @0x2a19b0 blx r3
 *   @0x2a19b4 bl 0x1699c0 <_Z18GR_D3D_Start_Framev>
 *   @0x2a19b8 ldr r3, [r6]
 *   @0x2a19bc ldr r1, [pc, #0x204]
 *   @0x2a19c0 mov r0, r6
 *   @0x2a19c4 add r1, pc, r1
 *   @0x2a19c8 ldr r3, [r3, #0xc]
 *   @0x2a19cc blx r3
 *   @0x2a19d0 bl 0x1a5a3c <_Z19Part_CreateTexturesv>
 *   @0x2a19d4 ldr r3, [r6]
 *   @0x2a19d8 ldr r1, [pc, #0x1ec]
 *   @0x2a19dc mov r0, r6
 *   @0x2a19e0 add r1, pc, r1
 *   @0x2a19e4 ldr r3, [r3, #0xc]
 *   @0x2a19e8 blx r3
 *   @0x2a19ec bl 0x29bfc8 <_Z25Debug_InitRemoteInterfacev>
 *   @0x2a19f0 ldr r3, [r6]
 *   @0x2a19f4 ldr r1, [pc, #0x1d4]
 *   @0x2a19f8 mov r0, r6
 *   @0x2a19fc ldr r3, [r3, #0xc]
 *   @0x2a1a00 add r1, pc, r1
 *   @0x2a1a04 blx r3
 *   @0x2a1a08 bl 0xd83a8 <_ZN2VM4InitEv>
 *   @0x2a1a0c ldr r3, [pc, #0x1c0]
 *   @0x2a1a10 ldr r3, [r7, r3]
 *   @0x2a1a14 ldr r3, [r3]
 *   @0x2a1a18 cmp r3, #0
 *   @0x2a1a1c bne 0x2a1a48 <_Z10BeginToEndv+0x23c>
 *   @0x2a1a20 ldr r3, [pc, #0x1b0]
 *   @0x2a1a24 ldr r3, [r7, r3]
 *   @0x2a1a28 ldrb r3, [r3]
 *   @0x2a1a2c cmp r3, #0
 *   @0x2a1a30 beq 0x2a1a48 <_Z10BeginToEndv+0x23c>
 *   @0x2a1a34 ldr r3, [pc, #0x1a0]
 *   @0x2a1a38 ldr r4, [r7, r3]
 *   @0x2a1a3c ldr r5, [r4]
 *   @0x2a1a40 cmp r5, #0
 *   @0x2a1a44 beq 0x2a1ab4 <_Z10BeginToEndv+0x2a8>
 *   @0x2a1a48 ldr r3, [r6]
 *   @0x2a1a4c mov r0, r6
 *   @0x2a1a50 ldr r1, [pc, #0x188]
 *   @0x2a1a54 ldr r3, [r3, #0xc]
 *   @0x2a1a58 add r1, pc, r1
 *   @0x2a1a5c blx r3
 *   @0x2a1a60 mov r0, #1
 *   @0x2a1a64 bl 0x27c524 <_Znwj>
 *   @0x2a1a68 ldr r3, [pc, #0x174]
 *   @0x2a1a6c ldr r3, [r7, r3]
 *   @0x2a1a70 str r0, [r3]
 *   @0x2a1a74 bl 0x1dbe94 <_ZN9Run_Score6CreateEv>
 *   @0x2a1a78 ldr r3, [r6]
 *   @0x2a1a7c mov r0, r6
 *   @0x2a1a80 ldr r1, [pc, #0x160]
 *   @0x2a1a84 ldr r3, [r3, #0xc]
 *   @0x2a1a88 add r1, pc, r1
 *   @0x2a1a8c blx r3
 *   @0x2a1a90 ldr r3, [r6]
 *   @0x2a1a94 ldr r1, [pc, #0x150]
 *   @0x2a1a98 mov r0, r6
 *   @0x2a1a9c add r1, pc, r1
 *   @0x2a1aa0 ldr r3, [r3, #0xc]
 *   @0x2a1aa4 blx r3
 *   @0x2a1aa8 add sp, sp, #8
 *   @0x2a1aac pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2a1ab0 b 0x2a16dc <_Z9DoTheWorkv>
 *   @0x2a1ab4 ldr r3, [pc, #0x134]
 *   @0x2a1ab8 ldr r1, [pc, #0x134]
 *   @0x2a1abc ldr r3, [r7, r3]
 *   @0x2a1ac0 add r1, pc, r1
 *   @0x2a1ac4 ldr r9, [r3]
 *   @0x2a1ac8 ldr r3, [r9]
 *   @0x2a1acc mov r0, r9
 *   @0x2a1ad0 ldr r3, [r3, #0xc]
 *   @0x2a1ad4 blx r3
 *   @0x2a1ad8 mov r0, #8
 *   @0x2a1adc bl 0x27c524 <_Znwj>
 *   @0x2a1ae0 ldr r3, [pc, #0x110]
 *   @0x2a1ae4 ldr r3, [r7, r3]
 *   @0x2a1ae8 ldrb r1, [r3]
 *   @0x2a1aec mov r10, r0
 *   @0x2a1af0 bl 0x29cf24 <_ZN9DbgServerC2Eb>
 *   @0x2a1af4 mov r0, r10
 *   @0x2a1af8 str r10, [r4]
 *   @0x2a1afc bl 0x29cf64 <_ZN9DbgServer4InitEv>
 *   @0x2a1b1c eor r2, r2, r8
 *   @0x2a1b20 strb r2, [r3]
 *   @0x2a1b24 bl 0x29ccc8 <_Z22DebuggerCreateIPSocketv>
 *   @0x2a1b28 ldr r3, [pc, #0xd4]
 *   @0x2a1b2c mov r0, r5
 *   @0x2a1b30 ldr r3, [r7, r3]
 *   @0x2a1b34 strb r8, [r3]
 *   @0x2a1b38 bl 0x15f2a4 <_Z17YYPowersaveEnableb>
 *   @0x2a1b3c b 0x2a1a48 <_Z10BeginToEndv+0x23c>
 *   @0x2a1b40 ldr r3, [r9]
 *   @0x2a1b44 mov r0, r9
 *   @0x2a1b48 ldr r1, [pc, #0xb8]
 *   @0x2a1b4c ldr r3, [r3, #0xc]
 *   @0x2a1b50 add r1, pc, r1
 *   @0x2a1b54 blx r3
 *   @0x2a1b58 ldr r5, [r4]
 *   @0x2a1b5c cmp r5, #0
 *   @0x2a1b60 beq 0x2a1b74 <_Z10BeginToEndv+0x368>
 *   @0x2a1b64 mov r0, r5
 *   @0x2a1b68 bl 0x29d038 <_ZN9DbgServerD2Ev>
 *   @0x2a1b6c mov r0, r5
 *   @0x2a1b70 bl 0x27d1d0 <_ZdlPv>
 *   @0x2a1b74 mov r3, #0
 *   @0x2a1b78 str r3, [r4]
 *   @0x2a1b7c b 0x2a1a48 <_Z10BeginToEndv+0x23c>
 *   @0x2a1b80 andseq r0, r5, r12, lsr #8
 *   @0x2a1b84 .word 0xffffdecc
 *   @0x2a1b88 andeq r8, r11, r12, lsr #16
 *   @0x2a1b8c .word 0xffffc138
 *   @0x2a1b90 .word 0xfffffc00
 *   @0x2a1b94 andeq r8, r11, r4, ror #15
 *   @0x2a1b98 .word 0xfffffdd0
 *   @0x2a1b9c andeq r8, r11, r4, asr #16
 *   @0x2a1ba0 .word 0xfffff0bc
 *   @0x2a1ba4 .word 0xfffff0b8
 *   @0x2a1ba8 andeq r8, r11, r0, lsl r8
 *   @0x2a1bac .word 0xfffff05c
 *   @0x2a1bb0 .word 0xfffff060
 *   @0x2a1bb4 andeq r8, r11, r12, ror #15
 *   @0x2a1bb8 andeq r8, r11, r12, asr #15
 *   @0x2a1bbc andeq r8, r11, r0, asr #15
 *   @0x2a1bc0 strheq r8, [r11], -r8
 *   @0x2a1bc4 andeq r8, r11, r8, lsr #15
 *   @0x2a1bc8 muleq r11, r12, r7
 *   @0x2a1bcc muleq r11, r8, r7
 *   @0x2a1bd0 muleq r11, r8, r7
 *   @0x2a1bd4 .word 0xffffc7d0
 *   @0x2a1bd8 .word 0xfffff0a0
 *   @0x2a1bdc .word 0xffffc0a4
 *   @0x2a1be0 andeq r8, r11, r4, ror r7
 *   @0x2a1be4 .word 0xfffffdd4
 *   @0x2a1be8 andeq r8, r11, r8, asr r7
 *   @0x2a1bec andeq r8, r11, r8, asr r7
 *   @0x2a1bf0 .word 0xffffbcf0
 *   @0x2a1bf4 andeq r8, r11, r4, ror #13
 *   @0x2a1bf8 .word 0xfffffdd8
 *   @0x2a1bfc .word 0xffffbcd4
 *   @0x2a1c00 .word 0xffffbd2c
 *   @0x2a1c04 .word 0xffffdf9c
 *   @0x2a1c08 andeq r8, r11, r8, ror #12
 *
 * ══ §20/31 GR_Texture_Draw_Part_Color(YYTPageEntry*, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)  0x175a90  size 1020  253 条（0x175a90..0x175e8c）
 * @func 0x175a90 0x175e8c  size 1020  253 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: DrawIt_Color(void*, float, float, float, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int)×2 / GR_Texture_Exists(int) / GR_Texture_Draw_Part_Color(YYTPageEntry*, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)+0x3c0 / 0xb66e8 / 0xb6580 / 0xb658c / GR_Texture_Draw_Part_Color(YYTPageEntry*, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)+0x150 / GR_Texture_Draw_Part_Color(YYTPageEntry*, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)+0x1a8
 * 字段偏移 top8: 0x24×2 / 0x28×2 / 0x2c×2 / 0x30×2 / 0x94×1 / 0x378×1 / 0x9c×1 / 0x90×1
 * VFP 指令 163 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x175a90 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x175a94 vpush {d8, d9, d10, d11}
 *   @0x175a98 subs r4, r0, #0
 *   @0x175a9c sub sp, sp, #60
 *   @0x175aa0 vmov s22, r1
 *   @0x175aa4 vmov s21, r2
 *   @0x175aa8 vldr s18, [sp, #120]
 *   @0x175aac vmov s19, r3
 *   @0x175ab0 vldr s17, [sp, #124]
 *   @0x175ab4 vldr s16, [sp, #128]
 *   @0x175ab8 vldr s20, [sp, #140]
 *   @0x175abc beq 0x175d8c <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x2fc>
 *   @0x175ac0 ldrsh r0, [r4, #20]
 *   @0x175ac4 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x175ac8 subs r5, r0, #0
 *   @0x175acc beq 0x175d8c <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x2fc>
 *   @0x175ad0 vldr s15, [pc, #928]
 *   @0x175ad4 vldr s5, [sp, #160]
 *   @0x175ad8 vmul.f32 s14, s5, s15
 *   @0x175adc vcmpe.f32 s14, #0
 *   @0x175ae0 vmrs APSR_nzcv, fpscr
 *   @0x175ae4 bmi 0x175e48 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x3b8>
 *   @0x175ae8 vcmpe.f32 s14, s15
 *   @0x175aec vmrs APSR_nzcv, fpscr
 *   @0x175af0 ble 0x175e50 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x3c0>
 *   @0x175af4 vldr d7, [pc, #876]
 *   @0x175af8 vmov r0, r1, d7
 *   @0x175afc bl 0xb66e8 <lrint@plt>
 *   @0x175b00 ldr r3, [sp, #0x94]
 *   @0x175b04 ldr r2, [pc, #0x378]
 *   @0x175b08 bic r8, r3, #-16777216
 *   @0x175b0c ldr r3, [sp, #0x9c]
 *   @0x175b10 ldr r2, [pc, r2]
 *   @0x175b14 ldr r1, [sp, #0x90]
 *   @0x175b18 bic r6, r3, #-16777216
 *   @0x175b1c ldrb r3, [r2]
 *   @0x175b20 bic r9, r1, #-16777216
 *   @0x175b24 ldr r1, [sp, #0x98]
 *   @0x175b28 cmp r3, #0
 *   @0x175b2c bic r7, r1, #-16777216
 *   @0x175b30 lsl r0, r0, #24
 *   @0x175b34 orr r9, r0, r9
 *   @0x175b38 orr r8, r0, r8
 *   @0x175b3c orr r7, r0, r7
 *   @0x175b40 orr r6, r0, r6
 *   @0x175b44 beq 0x175b70 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0xe0>
 *   @0x175b48 bic r8, r8, #65536
 *   @0x175b4c bic r7, r7, #65536
 *   @0x175b50 bic r8, r8, #1
 *   @0x175b54 bic r7, r7, #1
 *   @0x175b58 bic r9, r9, #65536
 *   @0x175b5c orr r6, r6, #65536
 *   @0x175b60 orr r8, r8, #1
 *   @0x175b64 orr r7, r7, #65536
 *   @0x175b68 bic r9, r9, #1
 *   @0x175b6c orr r6, r6, #1
 *   @0x175b70 vmov r0, s20
 *   @0x175b74 bl 0xb6580 <sinf@plt>
 *   @0x175b78 vmov s23, r0
 *   @0x175b7c vmov r0, s20
 *   @0x175b80 bl 0xb658c <cosf@plt>
 *   @0x175b84 ldrsh r1, [r4, #8]
 *   @0x175b88 vmov s15, r1
 *   @0x175b8c vcvt.f32.s32 s15, s15
 *   @0x175b90 vcmpe.f32 s15, s22
 *   @0x175b94 vmrs APSR_nzcv, fpscr
 *   @0x175b98 vsuble.f32 s22, s22, s15
 *   @0x175b9c vmov s12, r0
 *   @0x175ba0 ble 0x175be0 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x150>
 *   @0x175ba4 vsub.f32 s14, s15, s22
 *   @0x175ba8 vldr s5, [sp, #132]
 *   @0x175bac vldr s9, [sp, #136]
 *   @0x175bb0 vldr s22, [pc, #708]
 *   @0x175bb4 vmul.f32 s13, s12, s14
 *   @0x175bb8 vmul.f32 s15, s23, s14
 *   @0x175bbc vmul.f32 s13, s13, s5
 *   @0x175bc0 vmul.f32 s15, s15, s9
 *   @0x175bc4 vcvt.s32.f32 s13, s13
 *   @0x175bc8 vcvt.s32.f32 s15, s15
 *   @0x175bcc vcvt.f32.s32 s13, s13
 *   @0x175bd0 vcvt.f32.s32 s15, s15
 *   @0x175bd4 vsub.f32 s19, s19, s14
 *   @0x175bd8 vadd.f32 s17, s17, s13
 *   @0x175bdc vsub.f32 s16, s16, s15
 *   @0x175be0 ldrsh r1, [r4, #10]
 *   @0x175be4 vmov s15, r1
 *   @0x175be8 vcvt.f32.s32 s15, s15
 *   @0x175bec vcmpe.f32 s15, s21
 *   @0x175bf0 vmrs APSR_nzcv, fpscr
 *   @0x175bf4 vsuble.f32 s21, s21, s15
 *   @0x175bf8 ble 0x175c38 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x1a8>
 *   @0x175bfc vldr s5, [sp, #132]
 *   @0x175c00 vldr s9, [sp, #136]
 *   @0x175c04 vsub.f32 s14, s15, s21
 *   @0x175c08 vldr s21, [pc, #620]
 *   @0x175c0c vmul.f32 s13, s23, s14
 *   @0x175c10 vmul.f32 s15, s12, s14
 *   @0x175c14 vmul.f32 s13, s13, s5
 *   @0x175c18 vmul.f32 s15, s15, s9
 *   @0x175c1c vcvt.s32.f32 s13, s13
 *   @0x175c20 vcvt.s32.f32 s15, s15
 *   @0x175c24 vcvt.f32.s32 s13, s13
 *   @0x175c28 vcvt.f32.s32 s15, s15
 *   @0x175c2c vsub.f32 s18, s18, s14
 *   @0x175c30 vadd.f32 s17, s17, s13
 *   @0x175c34 vadd.f32 s16, s16, s15
 *   @0x175c38 ldrsh r1, [r4, #12]
 *   @0x175c3c vldr s11, [pc, #572]
 *   @0x175c40 ldrsh r2, [r4, #14]
 *   @0x175c44 vldr s13, [pc, #560]
 *   @0x175c48 vldr s5, [sp, #132]
 *   @0x175c4c vldr s9, [sp, #136]
 *   @0x175c50 vmov s14, r1
 *   @0x175c54 ldrsh r1, [r4, #20]
 *   @0x175c58 vmov s15, r2
 *   @0x175c5c ldr r2, [pc, #0x224]
 *   @0x175c60 ldr r2, [pc, r2]
 *   @0x175c64 vcvt.f32.s32 s14, s14
 *   @0x175c68 ldr r3, [r2, #0x4]
 *   @0x175c6c ldr r3, [r3, r1, lsl #2]
 *   @0x175c70 vcvt.f32.s32 s15, s15
 *   @0x175c74 vcmpe.f32 s19, s14
 *   @0x175c78 vabs.f32 s20, s20
 *   @0x175c7c vmrs APSR_nzcv, fpscr
 *   @0x175c80 vcmpe.f32 s18, s15
 *   @0x175c84 vmovle.f32 s14, s19
 *   @0x175c88 vmrs APSR_nzcv, fpscr
 *   @0x175c8c vmov.f32 s10, s13
 *   @0x175c90 vcmpe.f32 s20, s11
 *   @0x175c94 vmovle.f32 s15, s18
 *   @0x175c98 vmrs APSR_nzcv, fpscr
 *   @0x175c9c vmov.f32 s11, s13
 *   @0x175ca0 vmla.f32 s10, s5, s14
 *   @0x175ca4 vmla.f32 s11, s9, s15
 *   @0x175ca8 bmi 0x175da0 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x310>
 *   @0x175cac ldrsh r2, [r4]
 *   @0x175cb0 vldr s6, [r3, #8]
 *   @0x175cb4 ldrsh r4, [r4, #2]
 *   @0x175cb8 vldr s7, [r3, #12]
 *   @0x175cbc ldr r0, [r3]
 *   @0x175cc0 vmov s5, r2
 *   @0x175cc4 str r9, [sp, #0x24]
 *   @0x175cc8 vmov s8, r4
 *   @0x175ccc str r8, [sp, #0x28]
 *   @0x175cd0 str r7, [sp, #0x2c]
 *   @0x175cd4 str r6, [sp, #0x30]
 *   @0x175cd8 vcvt.f32.s32 s5, s5
 *   @0x175cdc vcvt.f32.s32 s8, s8
 *   @0x175ce0 vadd.f32 s22, s5, s22
 *   @0x175ce4 vadd.f32 s21, s8, s21
 *   @0x175ce8 vmov.f32 s5, s16
 *   @0x175cec vmov.f32 s8, s17
 *   @0x175cf0 vmul.f32 s9, s12, s13
 *   @0x175cf4 vadd.f32 s14, s14, s22
 *   @0x175cf8 vmul.f32 s13, s23, s13
 *   @0x175cfc vadd.f32 s15, s15, s21
 *   @0x175d00 vmls.f32 s5, s10, s23
 *   @0x175d04 vmla.f32 s8, s10, s12
 *   @0x175d08 vmul.f32 s23, s11, s23
 *   @0x175d0c vmul.f32 s12, s11, s12
 *   @0x175d10 vmul.f32 s14, s6, s14
 *   @0x175d14 vmul.f32 s15, s7, s15
 *   @0x175d18 vstr s14, [sp, #28]
 *   @0x175d1c vadd.f32 s17, s9, s17
 *   @0x175d20 vstr s15, [sp, #32]
 *   @0x175d24 vsub.f32 s16, s16, s13
 *   @0x175d28 vmul.f32 s22, s22, s6
 *   @0x175d2c vmul.f32 s21, s21, s7
 *   @0x175d30 vstr s22, [sp, #20]
 *   @0x175d34 vadd.f32 s14, s17, s23
 *   @0x175d38 vstr s21, [sp, #24]
 *   @0x175d3c vadd.f32 s15, s16, s12
 *   @0x175d40 vstr s14, [sp, #12]
 *   @0x175d44 vadd.f32 s23, s8, s23
 *   @0x175d48 vstr s15, [sp, #16]
 *   @0x175d4c vadd.f32 s12, s5, s12
 *   @0x175d50 vstr s23, [sp, #4]
 *   @0x175d54 vadd.f32 s10, s9, s5
 *   @0x175d58 vstr s12, [sp, #8]
 *   @0x175d5c vadd.f32 s17, s17, s13
 *   @0x175d60 vstr s10, [sp]
 *   @0x175d64 vadd.f32 s16, s9, s16
 *   @0x175d68 vmov r1, s17
 *   @0x175d6c vadd.f32 s8, s13, s8
 *   @0x175d70 vmov r2, s16
 *   @0x175d74 vmov r3, s8
 *   @0x175d78 bl 0x17438c <_Z12DrawIt_ColorPvffffffffffffjjjj>
 *   @0x175d7c mov r0, r5
 *   @0x175d80 add sp, sp, #60
 *   @0x175d84 vpop {d8, d9, d10, d11}
 *   @0x175d88 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x175d8c mov r5, #0
 *   @0x175d90 mov r0, r5
 *   @0x175d94 add sp, sp, #60
 *   @0x175d98 vpop {d8, d9, d10, d11}
 *   @0x175d9c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x175da0 ldrsh r1, [r4]
 *   @0x175da4 vldr s9, [r3, #8]
 *   @0x175da8 ldrsh r4, [r4, #2]
 *   @0x175dac vldr s12, [r3, #12]
 *   @0x175db0 vadd.f32 s10, s17, s10
 *   @0x175db4 ldr r0, [r3]
 *   @0x175db8 vmov s7, r1
 *   @0x175dbc str r9, [sp, #0x24]
 *   @0x175dc0 vmov s8, r4
 *   @0x175dc4 str r8, [sp, #0x28]
 *   @0x175dc8 str r7, [sp, #0x2c]
 *   @0x175dcc str r6, [sp, #0x30]
 *   @0x175dd0 vcvt.f32.s32 s7, s7
 *   @0x175dd4 vstr s10, [sp, #4]
 *   @0x175dd8 vmov r3, s10
 *   @0x175ddc vcvt.f32.s32 s8, s8
 *   @0x175de0 vadd.f32 s22, s7, s22
 *   @0x175de4 vadd.f32 s21, s8, s21
 *   @0x175de8 vadd.f32 s14, s14, s22
 *   @0x175dec vadd.f32 s15, s15, s21
 *   @0x175df0 vmul.f32 s14, s9, s14
 *   @0x175df4 vmul.f32 s22, s22, s9
 *   @0x175df8 vstr s14, [sp, #28]
 *   @0x175dfc vmul.f32 s15, s12, s15
 *   @0x175e00 vstr s22, [sp, #20]
 *   @0x175e04 vmul.f32 s21, s21, s12
 *   @0x175e08 vstr s15, [sp, #32]
 *   @0x175e0c vadd.f32 s17, s17, s13
 *   @0x175e10 vstr s21, [sp, #24]
 *   @0x175e14 vadd.f32 s13, s16, s13
 *   @0x175e18 vstr s17, [sp, #12]
 *   @0x175e1c vmov r1, s17
 *   @0x175e20 vadd.f32 s16, s16, s11
 *   @0x175e24 vstr s13, [sp]
 *   @0x175e28 vmov r2, s13
 *   @0x175e2c vstr s16, [sp, #8]
 *   @0x175e30 vstr s16, [sp, #16]
 *   @0x175e34 bl 0x17438c <_Z12DrawIt_ColorPvffffffffffffjjjj>
 *   @0x175e38 mov r0, r5
 *   @0x175e3c add sp, sp, #60
 *   @0x175e40 vpop {d8, d9, d10, d11}
 *   @0x175e44 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x175e48 vldr d7, [pc, #32]
 *   @0x175e4c b 0x175af8 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x68>
 *   @0x175e50 vcmpe.f32 s14, #0
 *   @0x175e54 vmrs APSR_nzcv, fpscr
 *   @0x175e58 bmi 0x175e48 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x3b8>
 *   @0x175e5c vcvt.f64.f32 d7, s14
 *   @0x175e60 b 0x175af8 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf+0x68>
 *   @0x175e64 nop
 *   @0x175e68 andeq r0, r0, r0
 *   @0x175e6c rsbmi lr, pc, r0
 *   @0x175e78 cmnmi pc, #0
 *   @0x175e7c andeq r0, r0, r0
 *   @0x175e80 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0x175e84 eoreq r8, r7, r12, lsr r3
 *   @0x175e88 .word 0x00277cbc
 *
 * ══ §21/31 _CreateTexture(Texture*, bool, eMipEnable)  0x182104  size 1020  255 条（0x182104..0x182500）
 * @func 0x182104 0x182500  size 1020  255 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x182168→0x3eb70c, 0x1821b0→0x479bb4, 0x1821cc→0x479bbc, 0x182204→0x479bb4, 0x182220→0x479bbc, 0x18223c→0x479bb0, 0x1822cc→0x3eb70c, 0x182304→0x3eb70c
 * 调用序列: GenerateMips(Texture*, int, int, int, char*)×2 / _InvalidateTextureState() / LoadTextureFromPNG(Texture*, eMipEnable) / _SetupRenderTargetFBO(Texture*, int, int)
 * 字段偏移 top8: 0x4×14 / 0x8×14 / 0xc×9 / 0x10×8 / 0x14×5 / 0x2c×2 / 0x370×2 / 0x28×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x182104 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x182108 cmp r1, #0
 *   @0x18210c ldr r6, [pc, #0x3c8]
 *   @0x182110 sub sp, sp, #24
 *   @0x182114 mov r4, r0
 *   @0x182118 mov r7, r2
 *   @0x18211c add r6, pc, r6
 *   @0x182120 bne 0x182198 <_Z14_CreateTextureP7Textureb10eMipEnable+0x94>
 *   @0x182124 ldr r5, [r4, #0x2c]
 *   @0x182128 cmp r5, #0
 *   @0x18212c beq 0x182304 <_Z14_CreateTextureP7Textureb10eMipEnable+0x200>
 *   @0x182130 ldr r0, [r5]
 *   @0x182134 movw r3, #0x4152
 *   @0x182138 movt r3, #0x2057
 *   @0x18213c cmp r0, r3
 *   @0x182140 beq 0x1821f4 <_Z14_CreateTextureP7Textureb10eMipEnable+0xf0>
 *   @0x182144 movw r3, #0x5089
 *   @0x182148 movt r3, #0x474e
 *   @0x18214c cmp r0, r3
 *   @0x182150 beq 0x1822cc <_Z14_CreateTextureP7Textureb10eMipEnable+0x1c8>
 *   @0x182154 ldr r2, [r5, #0x2c]
 *   @0x182158 movw r3, #0x5650
 *   @0x18215c movt r3, #0x2152
 *   @0x182160 cmp r2, r3
 *   @0x182164 beq 0x1821a0 <_Z14_CreateTextureP7Textureb10eMipEnable+0x9c>
 *   @0x182168 ldr r3, [pc, #0x370]
 *   @0x18216c ldr r1, [pc, #0x370]
 *   @0x182170 ldr r3, [r6, r3]
 *   @0x182174 add r1, pc, r1
 *   @0x182178 ldr r0, [r3]
 *   @0x18217c ldr r3, [r0]
 *   @0x182180 ldr r3, [r3, #0xc]
 *   @0x182184 blx r3
 *   @0x182188 mov r0, r4
 *   @0x18218c add sp, sp, #24
 *   @0x182190 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x182194 b 0x180aec <_Z20_SetTextureNPOTFlagsP7Texture>
 *   @0x182198 bl 0x182598 <_Z23_InvalidateTextureStatev>
 *   @0x18219c b 0x182124 <_Z14_CreateTextureP7Textureb10eMipEnable+0x20>
 *   @0x1821a0 ldr lr, [r5, #0x4]
 *   @0x1821a4 mov r1, r4
 *   @0x1821a8 ldr r12, [r5, #0x8]
 *   @0x1821ac mov r2, #6
 *   @0x1821b0 ldr r3, [pc, #0x330]
 *   @0x1821b4 mov r0, #1
 *   @0x1821b8 stmib r4, {r12, lr}
 *   @0x1821bc str r2, [r1], #20
 *   @0x1821c0 ldr r3, [r6, r3]
 *   @0x1821c4 ldr r3, [r3]
 *   @0x1821c8 blx r3
 *   @0x1821cc ldr r3, [pc, #0x318]
 *   @0x1821d0 movw r0, #0xde1
 *   @0x1821d4 ldr r1, [r4, #0x14]
 *   @0x1821d8 ldr r3, [r6, r3]
 *   @0x1821dc ldr r3, [r3]
 *   @0x1821e0 blx r3
 *   @0x1821e4 mov r0, r4
 *   @0x1821e8 add sp, sp, #24
 *   @0x1821ec pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1821f0 b 0x180aec <_Z20_SetTextureNPOTFlagsP7Texture>
 *   @0x1821f4 ldr r9, [r5, #0x4]
 *   @0x1821f8 mov r0, #1
 *   @0x1821fc ldr r8, [r5, #0x8]
 *   @0x182200 add r1, r4, #20
 *   @0x182204 ldr r3, [pc, #0x2dc]
 *   @0x182208 ldr r10, [r5, #0xc]
 *   @0x18220c str r9, [r4, #0x4]
 *   @0x182210 str r8, [r4, #0x8]
 *   @0x182214 ldr r3, [r6, r3]
 *   @0x182218 ldr r3, [r3]
 *   @0x18221c blx r3
 *   @0x182220 ldr r3, [pc, #0x2c4]
 *   @0x182224 movw r0, #0xde1
 *   @0x182228 ldr r1, [r4, #0x14]
 *   @0x18222c ldr r3, [r6, r3]
 *   @0x182230 ldr r3, [r3]
 *   @0x182234 blx r3
 *   @0x182238 cmp r10, #1
 *   @0x18223c ldr r3, [pc, #0x2ac]
 *   @0x182240 beq 0x182410 <_Z14_CreateTextureP7Textureb10eMipEnable+0x30c>
 *   @0x182244 mov r2, #6
 *   @0x182248 str r2, [r4]
 *   @0x18224c ldr lr, [r6, r3]
 *   @0x182250 mov r0, #0
 *   @0x182254 movw r12, #0x1908
 *   @0x182258 mov r3, r9
 *   @0x18225c mov r1, r0
 *   @0x182260 str r8, [sp]
 *   @0x182264 mov r2, r12
 *   @0x182268 add r5, r5, #16
 *   @0x18226c str r5, [sp, #0x10]
 *   @0x182270 ldr r6, [lr]
 *   @0x182274 movw lr, #0x1401
 *   @0x182278 str r0, [sp, #0x4]
 *   @0x18227c movw r0, #0xde1
 *   @0x182280 str r12, [sp, #0x8]
 *   @0x182284 str lr, [sp, #0xc]
 *   @0x182288 blx r6
 *   @0x18228c ldr r3, [r4, #0x10]
 *   @0x182290 cmp r7, #1
 *   @0x182294 orr r2, r3, #64
 *   @0x182298 str r2, [r4, #0x10]
 *   @0x18229c beq 0x1822b0 <_Z14_CreateTextureP7Textureb10eMipEnable+0x1ac>
 *   @0x1822a0 cmp r7, #2
 *   @0x1822a4 bne 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84>
 *   @0x1822a8 tst r3, #16
 *   @0x1822ac beq 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84>
 *   @0x1822b0 ldr r1, [r4, #0x4]
 *   @0x1822b4 mov r0, r4
 *   @0x1822b8 ldr r2, [r4, #0x8]
 *   @0x1822bc mov r3, #4
 *   @0x1822c0 str r5, [sp]
 *   @0x1822c4 bl 0x181db0 <_Z12GenerateMipsP7TextureiiiPc>
 *   @0x1822c8 b 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84>
 *   @0x1822cc ldr r3, [pc, #0x20c]
 *   @0x1822d0 ldr r1, [pc, #0x21c]
 *   @0x1822d4 ldr r2, [r4, #0x4]
 *   @0x1822d8 ldr r0, [r6, r3]
 *   @0x1822dc add r1, pc, r1
 *   @0x1822e0 ldr r3, [r4, #0x8]
 *   @0x1822e4 ldr r0, [r0]
 *   @0x1822e8 ldr r12, [r0]
 *   @0x1822ec ldr r12, [r12, #0xc]
 *   @0x1822f0 blx r12
 *   @0x1822f4 mov r0, r4
 *   @0x1822f8 mov r1, r7
 *   @0x1822fc bl 0x1828a4 <_Z18LoadTextureFromPNGP7Texture10eMipEnable>
 *   @0x182300 b 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84>
 *   @0x182304 ldr r3, [pc, #0x1d4]
 *   @0x182308 ldr r1, [pc, #0x1e8]
 *   @0x18230c ldr r2, [r4, #0x4]
 *   @0x182310 ldr r0, [r6, r3]
 *   @0x182314 add r1, pc, r1
 *   @0x182318 ldr r3, [r4, #0x8]
 *   @0x18231c ldr r8, [r0]
 *   @0x182320 ldr r12, [r8]
 *   @0x182324 mov r0, r8
 *   @0x182328 ldr r12, [r12, #0xc]
 *   @0x18232c blx r12
 *   @0x182330 ldr r9, [r4, #0x28]
 *   @0x182334 cmp r9, #0
 *   @0x182338 beq 0x18245c <_Z14_CreateTextureP7Textureb10eMipEnable+0x358>
 *   @0x18233c ldr r3, [r8]
 *   @0x182340 mov r0, r8
 *   @0x182344 ldr r1, [pc, #0x1b0]
 *   @0x182348 ldr r2, [r4, #0x4]
 *   @0x18234c ldr r12, [r3, #0xc]
 *   @0x182350 add r1, pc, r1
 *   @0x182354 ldr r3, [r4, #0x8]
 *   @0x182358 blx r12
 *   @0x18235c ldr r3, [pc, #0x184]
 *   @0x182360 mov r0, #1
 *   @0x182364 add r1, r4, #20
 *   @0x182368 ldr r8, [r4, #0x28]
 *   @0x18236c ldr r3, [r6, r3]
 *   @0x182370 ldr r3, [r3]
 *   @0x182374 blx r3
 *   @0x182378 ldr r3, [pc, #0x16c]
 *   @0x18237c movw r0, #0xde1
 *   @0x182380 ldr r1, [r4, #0x14]
 *   @0x182384 ldr r3, [r6, r3]
 *   @0x182388 ldr r3, [r3]
 *   @0x18238c blx r3
 *   @0x182390 ldr r2, [pc, #0x158]
 *   @0x182394 ldr r9, [r4, #0x8]
 *   @0x182398 movw r12, #0x1908
 *   @0x18239c ldr r3, [r4, #0x4]
 *   @0x1823a0 mov r1, r5
 *   @0x1823a4 ldr r0, [r6, r2]
 *   @0x1823a8 movw lr, #0x1401
 *   @0x1823ac mov r2, r12
 *   @0x1823b0 str r8, [sp, #0x10]
 *   @0x1823b4 str r5, [sp, #0x4]
 *   @0x1823b8 ldr r5, [r0]
 *   @0x1823bc movw r0, #0xde1
 *   @0x1823c0 str r9, [sp]
 *   @0x1823c4 str r12, [sp, #0x8]
 *   @0x1823c8 str lr, [sp, #0xc]
 *   @0x1823cc blx r5
 *   @0x1823d0 ldr r3, [r4, #0x10]
 *   @0x1823d4 cmp r7, #1
 *   @0x1823d8 orr r2, r3, #64
 *   @0x1823dc str r2, [r4, #0x10]
 *   @0x1823e0 beq 0x1823f4 <_Z14_CreateTextureP7Textureb10eMipEnable+0x2f0>
 *   @0x1823e4 cmp r7, #2
 *   @0x1823e8 bne 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84>
 *   @0x1823ec tst r3, #16
 *   @0x1823f0 beq 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84>
 *   @0x1823f4 ldr r1, [r4, #0x4]
 *   @0x1823f8 mov r0, r4
 *   @0x1823fc ldr r2, [r4, #0x8]
 *   @0x182400 mov r3, #4
 *   @0x182404 str r8, [sp]
 *   @0x182408 bl 0x181db0 <_Z12GenerateMipsP7TextureiiiPc>
 *   @0x18240c b 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84>
 *   @0x182410 mov r2, #11
 *   @0x182414 str r2, [r4]
 *   @0x182418 ldr lr, [r6, r3]
 *   @0x18241c mov r0, #0
 *   @0x182420 movw r12, #0x1908
 *   @0x182424 add r5, r5, #16
 *   @0x182428 mov r1, r0
 *   @0x18242c str r5, [sp, #0x10]
 *   @0x182430 str r8, [sp]
 *   @0x182434 mov r3, r9
 *   @0x182438 ldr r5, [lr]
 *   @0x18243c mov r2, r12
 *   @0x182440 movw lr, #0x8033
 *   @0x182444 str r0, [sp, #0x4]
 *   @0x182448 str r12, [sp, #0x8]
 *   @0x18244c movw r0, #0xde1
 *   @0x182450 str lr, [sp, #0xc]
 *   @0x182454 blx r5
 *   @0x182458 b 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84>
 *   @0x18245c ldr r3, [pc, #0x84]
 *   @0x182460 add r1, r4, #20
 *   @0x182464 mov r0, #1
 *   @0x182468 ldr r3, [r6, r3]
 *   @0x18246c ldr r3, [r3]
 *   @0x182470 blx r3
 *   @0x182474 ldr r3, [pc, #0x70]
 *   @0x182478 ldr r1, [r4, #0x14]
 *   @0x18247c movw r0, #0xde1
 *   @0x182480 ldr r3, [r6, r3]
 *   @0x182484 ldr r3, [r3]
 *   @0x182488 blx r3
 *   @0x18248c ldr r2, [pc, #0x5c]
 *   @0x182490 ldr r7, [r4, #0x8]
 *   @0x182494 movw r12, #0x1908
 *   @0x182498 ldr r3, [r4, #0x4]
 *   @0x18249c mov r1, r9
 *   @0x1824a0 ldr r0, [r6, r2]
 *   @0x1824a4 movw lr, #0x1401
 *   @0x1824a8 mov r2, r12
 *   @0x1824ac str r9, [sp, #0x4]
 *   @0x1824b0 str r9, [sp, #0x10]
 *   @0x1824b4 ldr r5, [r0]
 *   @0x1824b8 movw r0, #0xde1
 *   @0x1824bc str r7, [sp]
 *   @0x1824c0 str r12, [sp, #0x8]
 *   @0x1824c4 str lr, [sp, #0xc]
 *   @0x1824c8 blx r5
 *   @0x1824cc mov r0, r4
 *   @0x1824d0 ldmib r4, {r1, r2}
 *   @0x1824d4 bl 0x1814a0 <_Z21_SetupRenderTargetFBOP7Textureii>
 *   @0x1824d8 b 0x182188 <_Z14_CreateTextureP7Textureb10eMipEnable+0x84>
 *   @0x1824dc eoreq pc, r6, r4, lsr r11
 *   @0x1824e0 .word 0xffffbac4
 *   @0x1824e4 andseq r9, r12, r0, lsl #19
 *   @0x1824e8 .word 0xffffbb28
 *   @0x1824ec .word 0xffffbb20
 *   @0x1824f0 .word 0xffffbb2c
 *   @0x1824f4 andseq r9, r12, r4, lsl #16
 *   @0x1824f8 andseq r9, r12, r4, lsr #15
 *   @0x1824fc andseq r9, r12, r12, ror r7
 *
 * ══ §22/31 JS_Array_prototype_unshift(RValue&, CInstance*, CInstance*, int, RValue*)  0x25b128  size 1020  255 条（0x25b128..0x25b524）
 * @func 0x25b128 0x25b524  size 1020  255 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYObjectBase::InternalGetYYVar(int)×4 / JS_Array_prototype_unshift(RValue&, CInstance*, CInstance*, int, RValue*)+0x2bc / PushContextStack(YYObjectBase*) / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×33 / 0x4×13 / 0x8×8 / 0x10×8 / 0x-c×6 / 0x14×2 / 0x24×2 / 0x40×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25b128 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25b12c sub sp, sp, #28
 *   @0x25b130 ldr r2, [r1, #0x4]
 *   @0x25b134 mov r9, r3
 *   @0x25b138 ldr r3, [sp, #0x40]
 *   @0x25b13c mov r6, r0
 *   @0x25b140 cmp r2, #0
 *   @0x25b144 str r3, [sp, #0x14]
 *   @0x25b148 beq 0x25b448 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x320>
 *   @0x25b14c add r0, r2, #16
 *   @0x25b150 ldr r8, [r0]
 *   @0x25b154 cmp r9, #0
 *   @0x25b158 mov r11, #0
 *   @0x25b15c ldr r10, [r8, #0x24]
 *   @0x25b160 str r11, [r6, #0xc]
 *   @0x25b164 add r7, r9, r10
 *   @0x25b168 vmov s15, r7
 *   @0x25b16c vcvt.f64.u32 d7, s15
 *   @0x25b170 vmov r4, r5, d7
 *   @0x25b174 vmov r1, s14
 *   @0x25b178 mov r2, r5
 *   @0x25b17c stm r6, {r1, r2}
 *   @0x25b180 ble 0x25b3e4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2bc>
 *   @0x25b184 mov r0, r8
 *   @0x25b188 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x25b18c ldr r2, [pc, #0x38c]
 *   @0x25b190 ldr r0, [r8, #0x4]
 *   @0x25b194 lsl r1, r7, #4
 *   @0x25b198 str r11, [sp]
 *   @0x25b19c add r2, pc, r2
 *   @0x25b1a0 mov r3, #74
 *   @0x25b1a4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x25b1a8 str r7, [r8, #0x2c]
 *   @0x25b1ac str r7, [r8, #0x24]
 *   @0x25b1b0 cmp r0, r11
 *   @0x25b1b4 str r0, [r8, #0x4]
 *   @0x25b1b8 beq 0x25b4f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3cc>
 *   @0x25b1bc add r4, r0, r9, lsl #4
 *   @0x25b1c0 mov r1, r0
 *   @0x25b1c4 lsl r2, r10, #4
 *   @0x25b1c8 mov r0, r4
 *   @0x25b1cc bl 0xb6694 <memmove@plt>
 *   @0x25b1d0 ldr r3, [sp, #0x14]
 *   @0x25b1d4 mov r6, #0
 *   @0x25b1d8 add r11, r3, #12
 *   @0x25b1dc mov r7, r6
 *   @0x25b1e0 mov r10, r6
 *   @0x25b1e4 mov r5, r3
 *   @0x25b1e8 ldr r4, [r8, #0x4]
 *   @0x25b1ec cmp r4, #0
 *   @0x25b1f0 beq 0x25b3d0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a8>
 *   @0x25b1f4 add r4, r4, r6
 *   @0x25b1f8 ldr r1, [r4, #0xc]
 *   @0x25b1fc bic r3, r1, #-16777216
 *   @0x25b200 cmp r3, #1
 *   @0x25b204 beq 0x25b334 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x25b208 cmp r3, #2
 *   @0x25b20c bne 0x25b230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x25b210 sub r1, r1, #1
 *   @0x25b214 bic r1, r1, #-16777216
 *   @0x25b218 bic r1, r1, #3
 *   @0x25b21c cmp r1, #0
 *   @0x25b220 beq 0x25b3c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x25b224 mov r3, #5
 *   @0x25b228 str r10, [r4, #0x8]
 *   @0x25b22c str r3, [r4, #0xc]
 *   @0x25b230 str r10, [r4]
 *   @0x25b234 ldr r3, [r5, #0xc]
 *   @0x25b238 str r3, [r4, #0xc]
 *   @0x25b23c ldr r3, [r5, #0x8]
 *   @0x25b240 str r3, [r4, #0x8]
 *   @0x25b244 ldr r3, [r5, #0xc]
 *   @0x25b248 bic r3, r3, #-16777216
 *   @0x25b24c cmp r3, #14
 *   @0x25b250 addls pc, pc, r3, lsl #2
 *   @0x25b254 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x25b258 b 0x25b2c0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x25b25c b 0x25b2f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x25b260 b 0x25b2cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x25b264 b 0x25b294 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x25b268 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x25b26c b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x25b270 b 0x25b310 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0x25b274 b 0x25b294 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x25b278 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x25b27c b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x25b280 b 0x25b2c0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x25b284 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x25b288 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x25b28c b 0x25b2c0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x25b290 b 0x25b294 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x25b294 ldr r3, [r11, #-0xc]
 *   @0x25b298 str r3, [r4]
 *   @0x25b29c add r7, r7, #1
 *   @0x25b2a0 add r11, r11, #16
 *   @0x25b2a4 cmp r7, r9
 *   @0x25b2a8 add r6, r6, #16
 *   @0x25b2ac add r5, r5, #16
 *   @0x25b2b0 bne 0x25b1e8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xc0>
 *   @0x25b2b4 add sp, sp, #28
 *   @0x25b2b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25b2bc b 0xd3a34 <_Z15PopContextStackv>
 *   @0x25b2c0 ldm r5, {r1, r3}
 *   @0x25b2c4 stm r4, {r1, r3}
 *   @0x25b2c8 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x25b2cc ldr r3, [r11, #-0xc]
 *   @0x25b2d0 cmp r3, #0
 *   @0x25b2d4 str r3, [r4]
 *   @0x25b2d8 beq 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x25b2dc ldr r0, [r3, #0x8]
 *   @0x25b2e0 ldr r1, [r3]
 *   @0x25b2e4 cmp r0, #0
 *   @0x25b2e8 streq r4, [r3, #0x8]
 *   @0x25b2ec add r1, r1, #1
 *   @0x25b2f0 str r1, [r3]
 *   @0x25b2f4 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x25b2f8 ldr r3, [r11, #-0xc]
 *   @0x25b2fc cmp r3, #0
 *   @0x25b300 ldrne r1, [r3, #0x4]
 *   @0x25b304 addne r1, r1, #1
 *   @0x25b308 strne r1, [r3, #0x4]
 *   @0x25b30c b 0x25b298 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x25b310 ldr r3, [r11, #-0xc]
 *   @0x25b314 str r3, [r4]
 *   @0x25b318 ldr r3, [r11, #-0xc]
 *   @0x25b31c cmp r3, #0
 *   @0x25b320 beq 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x25b324 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x25b328 ldr r1, [r11, #-0xc]
 *   @0x25b32c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x25b330 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x25b334 ldr r3, [r4]
 *   @0x25b338 cmp r3, #0
 *   @0x25b33c beq 0x25b364 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x25b340 str r3, [sp, #0xc]
 *   @0x25b344 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x25b348 ldr r3, [sp, #0xc]
 *   @0x25b34c ldr r1, [r3, #0x4]
 *   @0x25b350 sub r1, r1, #1
 *   @0x25b354 str r1, [r3, #0x4]
 *   @0x25b358 cmp r1, #0
 *   @0x25b35c beq 0x25b36c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x244>
 *   @0x25b360 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x25b364 str r10, [r4]
 *   @0x25b368 b 0x25b230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x25b36c ldr r0, [r3]
 *   @0x25b370 str r1, [sp, #0x10]
 *   @0x25b374 str r3, [sp, #0xc]
 *   @0x25b378 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x25b37c ldr r3, [sp, #0xc]
 *   @0x25b380 ldr r1, [sp, #0x10]
 *   @0x25b384 str r1, [r3]
 *   @0x25b388 str r1, [r3, #0x8]
 *   @0x25b38c str r3, [sp, #0xc]
 *   @0x25b390 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x25b394 ldr r3, [sp, #0xc]
 *   @0x25b398 ldr r1, [r3, #0x4]
 *   @0x25b39c sub r1, r1, #1
 *   @0x25b3a0 str r1, [r3, #0x4]
 *   @0x25b3a4 cmp r1, #0
 *   @0x25b3a8 beq 0x25b3ec <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c4>
 *   @0x25b3ac str r3, [sp, #0xc]
 *   @0x25b3b0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x25b3b4 ldr r3, [sp, #0xc]
 *   @0x25b3b8 mov r0, r3
 *   @0x25b3bc bl 0x27d1d0 <_ZdlPv>
 *   @0x25b3c0 b 0x25b360 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x238>
 *   @0x25b3c4 mov r0, r4
 *   @0x25b3c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x25b3cc b 0x25b224 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x25b3d0 mov r0, r8
 *   @0x25b3d4 mov r1, r7
 *   @0x25b3d8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x25b3dc mov r4, r0
 *   @0x25b3e0 b 0x25b1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x25b3e4 add sp, sp, #28
 *   @0x25b3e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x25b3ec ldr r0, [r3]
 *   @0x25b3f0 str r1, [sp, #0x10]
 *   @0x25b3f4 str r3, [sp, #0xc]
 *   @0x25b3f8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x25b3fc ldr r3, [sp, #0xc]
 *   @0x25b400 ldr r1, [sp, #0x10]
 *   @0x25b404 str r1, [r3]
 *   @0x25b408 str r1, [r3, #0x8]
 *   @0x25b40c str r3, [sp, #0xc]
 *   @0x25b410 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x25b414 ldr r3, [sp, #0xc]
 *   @0x25b418 ldr r1, [r3, #0x4]
 *   @0x25b41c sub r1, r1, #1
 *   @0x25b420 str r1, [r3, #0x4]
 *   @0x25b424 cmp r1, #0
 *   @0x25b428 beq 0x25b458 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x330>
 *   @0x25b42c str r3, [sp, #0xc]
 *   @0x25b430 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x25b434 ldr r3, [sp, #0xc]
 *   @0x25b438 mov r0, r3
 *   @0x25b43c bl 0x27d1d0 <_ZdlPv>
 *   @0x25b440 ldr r3, [sp, #0xc]
 *   @0x25b444 b 0x25b3ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x25b448 mov r0, r1
 *   @0x25b44c mov r1, #1
 *   @0x25b450 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x25b454 b 0x25b150 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x25b458 ldr r0, [r3]
 *   @0x25b45c str r1, [sp, #0x10]
 *   @0x25b460 str r3, [sp, #0xc]
 *   @0x25b464 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x25b468 ldr r3, [sp, #0xc]
 *   @0x25b46c ldr r1, [sp, #0x10]
 *   @0x25b470 str r1, [r3]
 *   @0x25b474 str r1, [r3, #0x8]
 *   @0x25b478 str r3, [sp, #0xc]
 *   @0x25b47c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x25b480 ldr r3, [sp, #0xc]
 *   @0x25b484 ldr r1, [r3, #0x4]
 *   @0x25b488 sub r1, r1, #1
 *   @0x25b48c str r1, [r3, #0x4]
 *   @0x25b490 cmp r1, #0
 *   @0x25b494 beq 0x25b4b4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x38c>
 *   @0x25b498 str r3, [sp, #0xc]
 *   @0x25b49c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x25b4a0 ldr r3, [sp, #0xc]
 *   @0x25b4a4 mov r0, r3
 *   @0x25b4a8 bl 0x27d1d0 <_ZdlPv>
 *   @0x25b4ac ldr r3, [sp, #0xc]
 *   @0x25b4b0 b 0x25b42c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x304>
 *   @0x25b4b4 ldr r0, [r3]
 *   @0x25b4b8 str r1, [sp, #0x10]
 *   @0x25b4bc str r3, [sp, #0xc]
 *   @0x25b4c0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x25b4c4 ldr r3, [sp, #0xc]
 *   @0x25b4c8 ldr r1, [sp, #0x10]
 *   @0x25b4cc mov r0, r3
 *   @0x25b4d0 str r1, [r3]
 *   @0x25b4d4 str r1, [r3, #0x8]
 *   @0x25b4d8 str r3, [sp, #0xc]
 *   @0x25b4dc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x25b4e0 ldr r3, [sp, #0xc]
 *   @0x25b4e4 mov r0, r3
 *   @0x25b4e8 bl 0x27d1d0 <_ZdlPv>
 *   @0x25b4ec ldr r3, [sp, #0xc]
 *   @0x25b4f0 b 0x25b498 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x370>
 *   @0x25b4f4 mov r1, r9
 *   @0x25b4f8 mov r0, r8
 *   @0x25b4fc bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x25b500 ldr r1, [r8, #0x4]
 *   @0x25b504 cmp r1, #0
 *   @0x25b508 mov r4, r0
 *   @0x25b50c bne 0x25b1c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x25b510 mov r0, r8
 *   @0x25b514 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x25b518 mov r1, r0
 *   @0x25b51c b 0x25b1c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x25b520 muleq sp, r4, lr
 *
 * ══ §23/31 BuildFacebookWallPost(int, _jobjectArray*&)  0x15faa8  size 1012  253 条（0x15faa8..0x15fe9c）
 * @func 0x15faa8 0x15fe9c  size 1012  253 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x15fb24→0x3eb70c, 0x15fccc→0x3eb70c
 * 调用序列: getJNIEnv×12 / FREE_RValue__Pre(RValue*)×2 / BuildFacebookWallPost(int, _jobjectArray*&)+0x9c / F_DsMapFindFirst(RValue&, CInstance*, CInstance*, int, RValue*) / F_DsMapSize(RValue&, CInstance*, CInstance*, int, RValue*) / YYSetString(RValue*, char const*) / F_DsMapFindValue(RValue&, CInstance*, CInstance*, int, RValue*) / F_DsMapFindNext(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x24×9 / 0xc×9 / 0x30×7 / 0x29c×5 / 0x18×4 / 0x2b8×3 / 0x264×2 / 0x350×2
 * VFP 指令 7 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15faa8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x15faac sub sp, sp, #620
 *   @0x15fab0 ldr r7, [pc, #0x3bc]
 *   @0x15fab4 cmp r0, #0
 *   @0x15fab8 ldr r3, [pc, #0x3b8]
 *   @0x15fabc mov r6, #0
 *   @0x15fac0 add r7, pc, r7
 *   @0x15fac4 mov r9, r1
 *   @0x15fac8 ldr r3, [r7, r3]
 *   @0x15facc str r6, [sp, #0x24]
 *   @0x15fad0 str r3, [sp, #0x18]
 *   @0x15fad4 ldr r3, [r3]
 *   @0x15fad8 str r3, [sp, #0x264]
 *   @0x15fadc blt 0x15fb44 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x9c>
 *   @0x15fae0 vmov s15, r0
 *   @0x15fae4 add r8, sp, #36
 *   @0x15fae8 mov r3, #1
 *   @0x15faec add r10, sp, #68
 *   @0x15faf0 vcvt.f64.s32 d7, s15
 *   @0x15faf4 mov r1, r6
 *   @0x15faf8 mov r0, r8
 *   @0x15fafc str r10, [sp]
 *   @0x15fb00 mov r2, r6
 *   @0x15fb04 str r6, [sp, #0x50]
 *   @0x15fb08 vmov r4, r5, d7
 *   @0x15fb0c vstr s14, [sp, #68]
 *   @0x15fb10 str r5, [sp, #0x48]
 *   @0x15fb14 bl 0x104394 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_>
 *   @0x15fb18 ldr r3, [sp, #0x30]
 *   @0x15fb1c cmp r3, #1
 *   @0x15fb20 beq 0x15fc00 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x158>
 *   @0x15fb24 ldr r3, [pc, #0x350]
 *   @0x15fb28 ldr r1, [pc, #0x350]
 *   @0x15fb2c ldr r3, [r7, r3]
 *   @0x15fb30 add r1, pc, r1
 *   @0x15fb34 ldr r0, [r3]
 *   @0x15fb38 ldr r3, [r0]
 *   @0x15fb3c ldr r3, [r3, #0xc]
 *   @0x15fb40 blx r3
 *   @0x15fb44 bl 0x290274 <getJNIEnv>
 *   @0x15fb48 ldr r4, [pc, #0x334]
 *   @0x15fb4c add r4, pc, r4
 *   @0x15fb50 mov r5, r0
 *   @0x15fb54 bl 0x290274 <getJNIEnv>
 *   @0x15fb58 ldr r1, [pc, #0x328]
 *   @0x15fb5c add r1, pc, r1
 *   @0x15fb60 ldr r3, [r0]
 *   @0x15fb64 ldr r3, [r3, #0x18]
 *   @0x15fb68 blx r3
 *   @0x15fb6c mov r6, r0
 *   @0x15fb70 bl 0x290274 <getJNIEnv>
 *   @0x15fb74 mov r1, r4
 *   @0x15fb78 ldr r3, [r0]
 *   @0x15fb7c ldr r3, [r3, #0x29c]
 *   @0x15fb80 blx r3
 *   @0x15fb84 ldr r12, [r5]
 *   @0x15fb88 mov r2, r6
 *   @0x15fb8c mov r1, #2
 *   @0x15fb90 ldr r12, [r12, #0x2b0]
 *   @0x15fb94 mov r3, r0
 *   @0x15fb98 mov r0, r5
 *   @0x15fb9c blx r12
 *   @0x15fba0 str r0, [r9]
 *   @0x15fba4 bl 0x290274 <getJNIEnv>
 *   @0x15fba8 ldr r6, [r9]
 *   @0x15fbac mov r5, r0
 *   @0x15fbb0 bl 0x290274 <getJNIEnv>
 *   @0x15fbb4 mov r1, r4
 *   @0x15fbb8 ldr r3, [r0]
 *   @0x15fbbc ldr r3, [r3, #0x29c]
 *   @0x15fbc0 blx r3
 *   @0x15fbc4 ldr r12, [r5]
 *   @0x15fbc8 mov r1, r6
 *   @0x15fbcc mov r2, #1
 *   @0x15fbd0 ldr r12, [r12, #0x2b8]
 *   @0x15fbd4 mov r3, r0
 *   @0x15fbd8 mov r0, r5
 *   @0x15fbdc blx r12
 *   @0x15fbe0 mov r0, #0
 *   @0x15fbe4 ldr r12, [sp, #0x18]
 *   @0x15fbe8 ldr r2, [sp, #0x264]
 *   @0x15fbec ldr r3, [r12]
 *   @0x15fbf0 cmp r2, r3
 *   @0x15fbf4 bne 0x15fe70 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x3c8>
 *   @0x15fbf8 add sp, sp, #620
 *   @0x15fbfc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x15fc00 ldr r2, [sp, #0x24]
 *   @0x15fc04 cmp r2, r6
 *   @0x15fc08 beq 0x15fb24 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x7c>
 *   @0x15fc0c mov r1, r6
 *   @0x15fc10 mov r2, r6
 *   @0x15fc14 add r0, sp, #52
 *   @0x15fc18 str r10, [sp]
 *   @0x15fc1c str r6, [sp, #0x34]
 *   @0x15fc20 mov r5, r6
 *   @0x15fc24 str r6, [sp, #0x38]
 *   @0x15fc28 bl 0xfeea0 <_Z11F_DsMapSizeR6RValueP9CInstanceS2_iPS_>
 *   @0x15fc2c bl 0x290274 <getJNIEnv>
 *   @0x15fc30 ldr r2, [sp, #0x34]
 *   @0x15fc34 ldr r3, [sp, #0x38]
 *   @0x15fc38 add r12, sp, #84
 *   @0x15fc3c str r12, [sp, #0x10]
 *   @0x15fc40 mov r4, r6
 *   @0x15fc44 ldr r1, [pc, #0x240]
 *   @0x15fc48 add r6, sp, #100
 *   @0x15fc4c vmov d7, r2, r3
 *   @0x15fc50 ldr r2, [pc, #0x238]
 *   @0x15fc54 add r1, pc, r1
 *   @0x15fc58 str r1, [sp, #0x1c]
 *   @0x15fc5c vcvt.s32.f64 s15, d7
 *   @0x15fc60 add r2, pc, r2
 *   @0x15fc64 str r2, [sp, #0x14]
 *   @0x15fc68 vmov r12, s15
 *   @0x15fc6c mov r11, r0
 *   @0x15fc70 lsl r12, r12, #1
 *   @0x15fc74 str r12, [sp, #0x8]
 *   @0x15fc78 bl 0x290274 <getJNIEnv>
 *   @0x15fc7c ldr r1, [pc, #0x210]
 *   @0x15fc80 add r1, pc, r1
 *   @0x15fc84 ldr r3, [r0]
 *   @0x15fc88 ldr r3, [r3, #0x18]
 *   @0x15fc8c blx r3
 *   @0x15fc90 str r0, [sp, #0xc]
 *   @0x15fc94 bl 0x290274 <getJNIEnv>
 *   @0x15fc98 ldr r1, [pc, #0x1f8]
 *   @0x15fc9c add r1, pc, r1
 *   @0x15fca0 ldr r3, [r0]
 *   @0x15fca4 ldr r3, [r3, #0x29c]
 *   @0x15fca8 blx r3
 *   @0x15fcac ldr lr, [r11]
 *   @0x15fcb0 ldr r12, [sp, #0x8]
 *   @0x15fcb4 ldr r2, [sp, #0xc]
 *   @0x15fcb8 mov r1, r12
 *   @0x15fcbc ldr r12, [lr, #0x2b0]
 *   @0x15fcc0 mov r3, r0
 *   @0x15fcc4 mov r0, r11
 *   @0x15fcc8 blx r12
 *   @0x15fccc ldr r2, [pc, #0x1a8]
 *   @0x15fcd0 ldr r3, [sp, #0x24]
 *   @0x15fcd4 ldr r11, [sp, #0x30]
 *   @0x15fcd8 str r0, [r9]
 *   @0x15fcdc ldr r2, [r7, r2]
 *   @0x15fce0 ldr r7, [r2]
 *   @0x15fce4 b 0x15fe2c <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x384>
 *   @0x15fce8 mov r1, #5
 *   @0x15fcec str r4, [sp, #0x2c]
 *   @0x15fcf0 str r1, [sp, #0x30]
 *   @0x15fcf4 add r11, r5, #1
 *   @0x15fcf8 str r4, [sp, #0x24]
 *   @0x15fcfc bl 0x290274 <getJNIEnv>
 *   @0x15fd00 mov r1, r6
 *   @0x15fd04 ldr r3, [r0]
 *   @0x15fd08 ldr r3, [r3, #0x29c]
 *   @0x15fd0c blx r3
 *   @0x15fd10 str r0, [sp, #0xc]
 *   @0x15fd14 bl 0x290274 <getJNIEnv>
 *   @0x15fd18 ldr r3, [sp, #0xc]
 *   @0x15fd1c mov r2, r5
 *   @0x15fd20 ldr r1, [r9]
 *   @0x15fd24 ldr r12, [r0]
 *   @0x15fd28 ldr r12, [r12, #0x2b8]
 *   @0x15fd2c blx r12
 *   @0x15fd30 add r0, sp, #84
 *   @0x15fd34 mov r1, r6
 *   @0x15fd38 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x15fd3c mov r1, #0
 *   @0x15fd40 mov r3, #2
 *   @0x15fd44 str r10, [sp]
 *   @0x15fd48 mov r2, r1
 *   @0x15fd4c mov r0, r8
 *   @0x15fd50 bl 0x106bcc <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_>
 *   @0x15fd54 ldr r3, [sp, #0x30]
 *   @0x15fd58 cmp r3, #1
 *   @0x15fd5c beq 0x15fd78 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x2d0>
 *   @0x15fd60 ldr r3, [r7]
 *   @0x15fd64 mov r0, r7
 *   @0x15fd68 ldr r1, [sp, #0x1c]
 *   @0x15fd6c ldr r3, [r3, #0xc]
 *   @0x15fd70 blx r3
 *   @0x15fd74 str r4, [sp, #0x24]
 *   @0x15fd78 bl 0x290274 <getJNIEnv>
 *   @0x15fd7c ldr r3, [sp, #0x24]
 *   @0x15fd80 add r5, r5, #2
 *   @0x15fd84 ldr r1, [r3]
 *   @0x15fd88 ldr r3, [r0]
 *   @0x15fd8c ldr r3, [r3, #0x29c]
 *   @0x15fd90 blx r3
 *   @0x15fd94 str r0, [sp, #0xc]
 *   @0x15fd98 bl 0x290274 <getJNIEnv>
 *   @0x15fd9c ldr r3, [sp, #0xc]
 *   @0x15fda0 mov r2, r11
 *   @0x15fda4 ldr r1, [r9]
 *   @0x15fda8 ldr r12, [r0]
 *   @0x15fdac ldr r12, [r12, #0x2b8]
 *   @0x15fdb0 blx r12
 *   @0x15fdb4 ldr r12, [r7]
 *   @0x15fdb8 ldr r3, [sp, #0x24]
 *   @0x15fdbc mov r0, r7
 *   @0x15fdc0 ldr r1, [sp, #0x14]
 *   @0x15fdc4 mov r2, r6
 *   @0x15fdc8 ldr r12, [r12, #0xc]
 *   @0x15fdcc ldr r3, [r3]
 *   @0x15fdd0 blx r12
 *   @0x15fdd4 ldr r3, [sp, #0x30]
 *   @0x15fdd8 sub r3, r3, #1
 *   @0x15fddc bic r3, r3, #-16777216
 *   @0x15fde0 bic r3, r3, #3
 *   @0x15fde4 cmp r3, #0
 *   @0x15fde8 beq 0x15fe5c <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x3b4>
 *   @0x15fdec mov r1, #0
 *   @0x15fdf0 str r10, [sp]
 *   @0x15fdf4 mov r2, r1
 *   @0x15fdf8 mov r0, r8
 *   @0x15fdfc mov r3, #2
 *   @0x15fe00 mov r12, #5
 *   @0x15fe04 str r4, [sp, #0x2c]
 *   @0x15fe08 str r12, [sp, #0x30]
 *   @0x15fe0c str r4, [sp, #0x24]
 *   @0x15fe10 bl 0x104080 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_>
 *   @0x15fe14 ldr r11, [sp, #0x30]
 *   @0x15fe18 cmp r11, #1
 *   @0x15fe1c bne 0x15fe68 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x3c0>
 *   @0x15fe20 ldr r3, [sp, #0x24]
 *   @0x15fe24 cmp r3, #0
 *   @0x15fe28 beq 0x15fe68 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x3c0>
 *   @0x15fe2c sub r11, r11, #1
 *   @0x15fe30 ldr r1, [r3]
 *   @0x15fe34 bic r11, r11, #-16777216
 *   @0x15fe38 mov r0, r6
 *   @0x15fe3c movw r2, #0x1ff
 *   @0x15fe40 bic r11, r11, #3
 *   @0x15fe44 bl 0xb6568 <strncpy@plt>
 *   @0x15fe48 cmp r11, #0
 *   @0x15fe4c bne 0x15fce8 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x240>
 *   @0x15fe50 mov r0, r8
 *   @0x15fe54 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x15fe58 b 0x15fce8 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x240>
 *   @0x15fe5c mov r0, r8
 *   @0x15fe60 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x15fe64 b 0x15fdec <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x344>
 *   @0x15fe68 mov r0, #1
 *   @0x15fe6c b 0x15fbe4 <_Z21BuildFacebookWallPostiRP13_jobjectArray+0x13c>
 *   @0x15fe70 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x15fe74 mlaeq r9, r0, r1, r2
 *   @0x15fe78 .word 0xffffbd00
 *   @0x15fe7c .word 0xffffbac4
 *   @0x15fe80 andseq r9, lr, r12, ror #26
 *   @0x15fe84 andseq lr, r12, r10, ror #31
 *   @0x15fe88 andseq r9, lr, r4, lsl #24
 *   @0x15fe8c ldrsbeq r9, [lr], -r12
 *   @0x15fe90 andseq r9, lr, r4, lsl #24
 *   @0x15fe94 andseq r9, lr, r0, ror #21
 *   @0x15fe98 mulseq r12, r10, lr
 *
 * ══ §24/31 CDS_Grid::Get_Max(RValue&, int, int, int, int)  0x206924  size 1008  252 条（0x206924..0x206d14）
 * @func 0x206924 0x206d28  size 1028  257 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYCompareVal(RValue const&, RValue const&, double) / CDS_Grid::Get_Max(RValue&, int, int, int, int)+0xa4 / GetContextStackTop() / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0x4×21 / 0x8×9 / 0xc×8 / 0x180×2 / 0x30×1 / 0x34×1 / 0x31c×1 / 0x2f4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x206924 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x206928 sub sp, sp, #12
 *   @0x20692c mov r6, r0
 *   @0x206930 mov r9, #0
 *   @0x206934 ldr r4, [sp, #0x30]
 *   @0x206938 mov r8, r9
 *   @0x20693c str r1, [sp, #0x4]
 *   @0x206940 cmp r2, r4
 *   @0x206944 ldr r1, [sp, #0x34]
 *   @0x206948 lsrlt r0, r2, #31
 *   @0x20694c lsrge r0, r4, #31
 *   @0x206950 cmp r2, r4
 *   @0x206954 movlt r11, r2
 *   @0x206958 movge r11, r4
 *   @0x20695c cmp r0, #0
 *   @0x206960 movne r11, #0
 *   @0x206964 cmp r3, r1
 *   @0x206968 movlt r0, r3
 *   @0x20696c movge r0, r1
 *   @0x206970 cmp r3, r1
 *   @0x206974 lsrge r12, r1, #31
 *   @0x206978 lsrlt r12, r3, #31
 *   @0x20697c cmp r2, r4
 *   @0x206980 movge r10, r2
 *   @0x206984 movlt r10, r4
 *   @0x206988 cmp r12, r9
 *   @0x20698c movne r0, r9
 *   @0x206990 str r0, [sp]
 *   @0x206994 ldr r0, [r6, #0x4]
 *   @0x206998 cmp r3, r1
 *   @0x20699c movge r7, r3
 *   @0x2069a0 movlt r7, r1
 *   @0x2069a4 mov r1, #1
 *   @0x2069a8 cmp r10, r0
 *   @0x2069ac subge r3, r0, #1
 *   @0x2069b0 movlt r3, r10
 *   @0x2069b4 cmp r11, r3
 *   @0x2069b8 bgt 0x206a60 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x13c>
 *   @0x2069bc ldr r3, [r6, #0x8]
 *   @0x2069c0 ldr r4, [sp]
 *   @0x2069c4 b 0x206a38 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x114>
 *   @0x2069c8 mla r5, r0, r4, r11
 *   @0x2069cc ldr r2, [r6]
 *   @0x2069d0 cmp r1, #0
 *   @0x2069d4 add r5, r2, r5, lsl #4
 *   @0x2069d8 movne r8, r5
 *   @0x2069dc bne 0x206a30 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x10c>
 *   @0x2069e0 ldr r3, [pc, #0x31c]
 *   @0x2069e4 ldr r3, [pc, r3]
 *   @0x2069e8 ldrb r3, [r3]
 *   @0x2069ec cmp r3, #0
 *   @0x2069f0 beq 0x206a0c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0xe8>
 *   @0x2069f4 ldr r3, [r8, #0xc]
 *   @0x2069f8 cmp r3, #1
 *   @0x2069fc ldr r3, [r5, #0xc]
 *   @0x206a00 beq 0x206a54 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x130>
 *   @0x206a04 cmp r3, #1
 *   @0x206a08 moveq r9, #1
 *   @0x206a0c ldr r3, [pc, #0x2f4]
 *   @0x206a10 mov r0, r8
 *   @0x206a14 mov r1, r5
 *   @0x206a18 ldr r3, [pc, r3]
 *   @0x206a1c ldrd r2, r3, [r3]
 *   @0x206a20 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x206a24 cmp r0, #0
 *   @0x206a28 ldmib r6, {r0, r3}
 *   @0x206a2c movlt r8, r5
 *   @0x206a30 add r4, r4, #1
 *   @0x206a34 mov r1, #0
 *   @0x206a38 cmp r7, r3
 *   @0x206a3c subge r2, r3, #1
 *   @0x206a40 movlt r2, r7
 *   @0x206a44 cmp r4, r2
 *   @0x206a48 ble 0x2069c8 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0xa4>
 *   @0x206a4c add r11, r11, #1
 *   @0x206a50 b 0x2069a8 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x84>
 *   @0x206a54 cmp r3, #1
 *   @0x206a58 movne r9, #1
 *   @0x206a5c b 0x206a0c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0xe8>
 *   @0x206a60 cmp r8, #0
 *   @0x206a64 beq 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208>
 *   @0x206a68 cmp r9, #0
 *   @0x206a6c bne 0x206b84 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x260>
 *   @0x206a70 ldr r0, [sp, #0x4]
 *   @0x206a74 ldr r2, [r0, #0xc]
 *   @0x206a78 bic r3, r2, #-16777216
 *   @0x206a7c cmp r3, #1
 *   @0x206a80 beq 0x206b48 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x224>
 *   @0x206a84 cmp r3, #2
 *   @0x206a88 bne 0x206ab4 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x190>
 *   @0x206a8c sub r3, r2, #1
 *   @0x206a90 bic r3, r3, #-16777216
 *   @0x206a94 bic r3, r3, #3
 *   @0x206a98 cmp r3, #0
 *   @0x206a9c beq 0x206c64 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x340>
 *   @0x206aa0 ldr r0, [sp, #0x4]
 *   @0x206aa4 mov r2, #0
 *   @0x206aa8 mov r3, #5
 *   @0x206aac str r2, [r0, #0x8]
 *   @0x206ab0 str r3, [r0, #0xc]
 *   @0x206ab4 ldr r3, [r8, #0xc]
 *   @0x206ab8 mov r1, #0
 *   @0x206abc ldr r0, [sp, #0x4]
 *   @0x206ac0 ldr r2, [r8, #0x8]
 *   @0x206ac4 str r3, [r0, #0xc]
 *   @0x206ac8 ldr r3, [r8, #0xc]
 *   @0x206acc str r1, [r0]
 *   @0x206ad0 bic r3, r3, #-16777216
 *   @0x206ad4 str r2, [r0, #0x8]
 *   @0x206ad8 cmp r3, #14
 *   @0x206adc addls pc, pc, r3, lsl #2
 *   @0x206ae0 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208>
 *   @0x206ae4 b 0x206b34 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x210>
 *   @0x206ae8 b 0x206bd4 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x2b0>
 *   @0x206aec b 0x206bf8 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x2d4>
 *   @0x206af0 b 0x206b20 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x1fc>
 *   @0x206af4 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208>
 *   @0x206af8 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208>
 *   @0x206afc b 0x206ba8 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x284>
 *   @0x206b00 b 0x206b20 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x1fc>
 *   @0x206b04 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208>
 *   @0x206b08 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208>
 *   @0x206b0c b 0x206b34 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x210>
 *   @0x206b10 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208>
 *   @0x206b14 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208>
 *   @0x206b18 b 0x206b34 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x210>
 *   @0x206b1c b 0x206b20 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x1fc>
 *   @0x206b20 ldr r3, [r8]
 *   @0x206b24 ldr r1, [sp, #0x4]
 *   @0x206b28 str r3, [r1]
 *   @0x206b2c add sp, sp, #12
 *   @0x206b30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x206b34 ldm r8, {r2, r3}
 *   @0x206b38 ldr r0, [sp, #0x4]
 *   @0x206b3c stm r0, {r2, r3}
 *   @0x206b40 add sp, sp, #12
 *   @0x206b44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x206b48 ldr r1, [sp, #0x4]
 *   @0x206b4c ldr r4, [r1]
 *   @0x206b50 cmp r4, #0
 *   @0x206b54 beq 0x206b74 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x250>
 *   @0x206b58 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x206b5c ldr r5, [r4, #0x4]
 *   @0x206b60 sub r5, r5, #1
 *   @0x206b64 str r5, [r4, #0x4]
 *   @0x206b68 cmp r5, #0
 *   @0x206b6c beq 0x206c2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x308>
 *   @0x206b70 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x206b74 ldr r2, [sp, #0x4]
 *   @0x206b78 mov r3, #0
 *   @0x206b7c str r3, [r2]
 *   @0x206b80 b 0x206ab4 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x190>
 *   @0x206b84 ldr r3, [pc, #0x180]
 *   @0x206b88 ldr r1, [pc, #0x180]
 *   @0x206b8c ldr r3, [pc, r3]
 *   @0x206b90 add r1, pc, r1
 *   @0x206b94 ldr r0, [r3]
 *   @0x206b98 ldr r3, [r0]
 *   @0x206b9c ldr r3, [r3, #0xc]
 *   @0x206ba0 blx r3
 *   @0x206ba4 b 0x206a70 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x14c>
 *   @0x206ba8 ldr r3, [r8]
 *   @0x206bac ldr r0, [sp, #0x4]
 *   @0x206bb0 str r3, [r0]
 *   @0x206bb4 ldr r3, [r8]
 *   @0x206bb8 cmp r3, #0
 *   @0x206bbc beq 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208>
 *   @0x206bc0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x206bc4 ldr r1, [r8]
 *   @0x206bc8 add sp, sp, #12
 *   @0x206bcc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x206bd0 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x206bd4 ldr r3, [r8]
 *   @0x206bd8 cmp r3, #0
 *   @0x206bdc ldrne r2, [r3, #0x4]
 *   @0x206be0 addne r2, r2, #1
 *   @0x206be4 strne r2, [r3, #0x4]
 *   @0x206be8 ldr r2, [sp, #0x4]
 *   @0x206bec str r3, [r2]
 *   @0x206bf0 add sp, sp, #12
 *   @0x206bf4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x206bf8 ldr r3, [r8]
 *   @0x206bfc ldr r1, [sp, #0x4]
 *   @0x206c00 cmp r3, #0
 *   @0x206c04 str r3, [r1]
 *   @0x206c08 beq 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208>
 *   @0x206c0c ldr r1, [r3, #0x8]
 *   @0x206c10 ldr r2, [r3]
 *   @0x206c14 cmp r1, #0
 *   @0x206c18 add r2, r2, #1
 *   @0x206c1c str r2, [r3]
 *   @0x206c20 ldreq r2, [sp, #0x4]
 *   @0x206c24 streq r2, [r3, #0x8]
 *   @0x206c28 b 0x206b2c <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x208>
 *   @0x206c2c ldr r0, [r4]
 *   @0x206c30 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x206c34 str r5, [r4]
 *   @0x206c38 str r5, [r4, #0x8]
 *   @0x206c3c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x206c40 ldr r5, [r4, #0x4]
 *   @0x206c44 sub r5, r5, #1
 *   @0x206c48 str r5, [r4, #0x4]
 *   @0x206c4c cmp r5, #0
 *   @0x206c50 beq 0x206c70 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x34c>
 *   @0x206c54 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x206c58 mov r0, r4
 *   @0x206c5c bl 0x27d1d0 <_ZdlPv>
 *   @0x206c60 b 0x206b70 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x24c>
 *   @0x206c64 ldr r0, [sp, #0x4]
 *   @0x206c68 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x206c6c b 0x206aa0 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x17c>
 *   @0x206c70 ldr r0, [r4]
 *   @0x206c74 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x206c78 str r5, [r4]
 *   @0x206c7c str r5, [r4, #0x8]
 *   @0x206c80 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x206c84 ldr r5, [r4, #0x4]
 *   @0x206c88 sub r5, r5, #1
 *   @0x206c8c str r5, [r4, #0x4]
 *   @0x206c90 cmp r5, #0
 *   @0x206c94 beq 0x206ca8 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x384>
 *   @0x206c98 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x206c9c mov r0, r4
 *   @0x206ca0 bl 0x27d1d0 <_ZdlPv>
 *   @0x206ca4 b 0x206c54 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x330>
 *   @0x206ca8 ldr r0, [r4]
 *   @0x206cac bl 0xcef90 <_Z6YYFreePKv>
 *   @0x206cb0 str r5, [r4]
 *   @0x206cb4 str r5, [r4, #0x8]
 *   @0x206cb8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x206cbc ldr r5, [r4, #0x4]
 *   @0x206cc0 sub r5, r5, #1
 *   @0x206cc4 str r5, [r4, #0x4]
 *   @0x206cc8 cmp r5, #0
 *   @0x206ccc beq 0x206ce0 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x3bc>
 *   @0x206cd0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x206cd4 mov r0, r4
 *   @0x206cd8 bl 0x27d1d0 <_ZdlPv>
 *   @0x206cdc b 0x206c98 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x374>
 *   @0x206ce0 ldr r0, [r4]
 *   @0x206ce4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x206ce8 mov r0, r4
 *   @0x206cec str r5, [r4]
 *   @0x206cf0 str r5, [r4, #0x8]
 *   @0x206cf4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x206cf8 mov r0, r4
 *   @0x206cfc bl 0x27d1d0 <_ZdlPv>
 *   @0x206d00 b 0x206cd0 <_ZN8CDS_Grid7Get_MaxER6RValueiiii+0x3ac>
 *   @0x206d04 andseq r7, lr, r12, lsr #9
 *   @0x206d08 andseq r10, lr, r12, ror #18
 *   @0x206d0c ldrheq r6, [lr], -r4
 *   @0x206d10 andseq r12, r4, r0, lsr #25
 *
 * ══ §25/31 CDS_Grid::Get_Min(RValue&, int, int, int, int)  0x206d14  size 1008  252 条（0x206d14..0x207104）
 * @func 0x206d14 0x207104  size 1008  252 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / YYCompareVal(RValue const&, RValue const&, double) / CDS_Grid::Get_Min(RValue&, int, int, int, int)+0xa4 / GetContextStackTop() / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0x4×21 / 0x8×9 / 0xc×8 / 0x180×2 / 0x30×1 / 0x34×1 / 0x320×1 / 0x2f8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x206d14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x206d18 sub sp, sp, #12
 *   @0x206d1c mov r6, r0
 *   @0x206d20 mov r9, #0
 *   @0x206d24 ldr r4, [sp, #0x30]
 *   @0x206d28 mov r7, r9
 *   @0x206d2c str r1, [sp, #0x4]
 *   @0x206d30 cmp r2, r4
 *   @0x206d34 ldr r1, [sp, #0x34]
 *   @0x206d38 lsrlt r0, r2, #31
 *   @0x206d3c lsrge r0, r4, #31
 *   @0x206d40 cmp r2, r4
 *   @0x206d44 movlt r11, r2
 *   @0x206d48 movge r11, r4
 *   @0x206d4c cmp r0, #0
 *   @0x206d50 movne r11, #0
 *   @0x206d54 cmp r3, r1
 *   @0x206d58 movlt r0, r3
 *   @0x206d5c movge r0, r1
 *   @0x206d60 cmp r3, r1
 *   @0x206d64 lsrge r12, r1, #31
 *   @0x206d68 lsrlt r12, r3, #31
 *   @0x206d6c cmp r2, r4
 *   @0x206d70 movge r10, r2
 *   @0x206d74 movlt r10, r4
 *   @0x206d78 cmp r12, r9
 *   @0x206d7c movne r0, r9
 *   @0x206d80 str r0, [sp]
 *   @0x206d84 ldr r0, [r6, #0x4]
 *   @0x206d88 cmp r3, r1
 *   @0x206d8c movge r8, r3
 *   @0x206d90 movlt r8, r1
 *   @0x206d94 mov r1, #1
 *   @0x206d98 cmp r10, r0
 *   @0x206d9c subge r3, r0, #1
 *   @0x206da0 movlt r3, r10
 *   @0x206da4 cmp r11, r3
 *   @0x206da8 bgt 0x206e50 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x13c>
 *   @0x206dac ldr r3, [r6, #0x8]
 *   @0x206db0 ldr r4, [sp]
 *   @0x206db4 b 0x206e28 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x114>
 *   @0x206db8 mla r5, r0, r4, r11
 *   @0x206dbc ldr r2, [r6]
 *   @0x206dc0 cmp r1, #0
 *   @0x206dc4 add r5, r2, r5, lsl #4
 *   @0x206dc8 bne 0x206e1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x108>
 *   @0x206dcc ldr r3, [pc, #0x320]
 *   @0x206dd0 ldr r3, [pc, r3]
 *   @0x206dd4 ldrb r3, [r3]
 *   @0x206dd8 cmp r3, #0
 *   @0x206ddc beq 0x206df8 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0xe4>
 *   @0x206de0 ldr r3, [r7, #0xc]
 *   @0x206de4 cmp r3, #1
 *   @0x206de8 ldr r3, [r5, #0xc]
 *   @0x206dec beq 0x206e44 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x130>
 *   @0x206df0 cmp r3, #1
 *   @0x206df4 moveq r9, #1
 *   @0x206df8 ldr r3, [pc, #0x2f8]
 *   @0x206dfc mov r1, r5
 *   @0x206e00 mov r0, r7
 *   @0x206e04 ldr r3, [pc, r3]
 *   @0x206e08 ldrd r2, r3, [r3]
 *   @0x206e0c bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x206e10 cmp r0, #0
 *   @0x206e14 ldmib r6, {r0, r3}
 *   @0x206e18 movle r5, r7
 *   @0x206e1c add r4, r4, #1
 *   @0x206e20 mov r7, r5
 *   @0x206e24 mov r1, #0
 *   @0x206e28 cmp r8, r3
 *   @0x206e2c subge r2, r3, #1
 *   @0x206e30 movlt r2, r8
 *   @0x206e34 cmp r4, r2
 *   @0x206e38 ble 0x206db8 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0xa4>
 *   @0x206e3c add r11, r11, #1
 *   @0x206e40 b 0x206d98 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x84>
 *   @0x206e44 cmp r3, #1
 *   @0x206e48 movne r9, #1
 *   @0x206e4c b 0x206df8 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0xe4>
 *   @0x206e50 cmp r7, #0
 *   @0x206e54 beq 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208>
 *   @0x206e58 cmp r9, #0
 *   @0x206e5c bne 0x206f74 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x260>
 *   @0x206e60 ldr r0, [sp, #0x4]
 *   @0x206e64 ldr r2, [r0, #0xc]
 *   @0x206e68 bic r3, r2, #-16777216
 *   @0x206e6c cmp r3, #1
 *   @0x206e70 beq 0x206f38 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x224>
 *   @0x206e74 cmp r3, #2
 *   @0x206e78 bne 0x206ea4 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x190>
 *   @0x206e7c sub r3, r2, #1
 *   @0x206e80 bic r3, r3, #-16777216
 *   @0x206e84 bic r3, r3, #3
 *   @0x206e88 cmp r3, #0
 *   @0x206e8c beq 0x207054 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x340>
 *   @0x206e90 ldr r0, [sp, #0x4]
 *   @0x206e94 mov r2, #0
 *   @0x206e98 mov r3, #5
 *   @0x206e9c str r2, [r0, #0x8]
 *   @0x206ea0 str r3, [r0, #0xc]
 *   @0x206ea4 ldr r3, [r7, #0xc]
 *   @0x206ea8 mov r1, #0
 *   @0x206eac ldr r0, [sp, #0x4]
 *   @0x206eb0 ldr r2, [r7, #0x8]
 *   @0x206eb4 str r3, [r0, #0xc]
 *   @0x206eb8 ldr r3, [r7, #0xc]
 *   @0x206ebc str r1, [r0]
 *   @0x206ec0 bic r3, r3, #-16777216
 *   @0x206ec4 str r2, [r0, #0x8]
 *   @0x206ec8 cmp r3, #14
 *   @0x206ecc addls pc, pc, r3, lsl #2
 *   @0x206ed0 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208>
 *   @0x206ed4 b 0x206f24 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x210>
 *   @0x206ed8 b 0x206fc4 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x2b0>
 *   @0x206edc b 0x206fe8 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x2d4>
 *   @0x206ee0 b 0x206f10 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x1fc>
 *   @0x206ee4 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208>
 *   @0x206ee8 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208>
 *   @0x206eec b 0x206f98 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x284>
 *   @0x206ef0 b 0x206f10 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x1fc>
 *   @0x206ef4 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208>
 *   @0x206ef8 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208>
 *   @0x206efc b 0x206f24 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x210>
 *   @0x206f00 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208>
 *   @0x206f04 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208>
 *   @0x206f08 b 0x206f24 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x210>
 *   @0x206f0c b 0x206f10 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x1fc>
 *   @0x206f10 ldr r3, [r7]
 *   @0x206f14 ldr r1, [sp, #0x4]
 *   @0x206f18 str r3, [r1]
 *   @0x206f1c add sp, sp, #12
 *   @0x206f20 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x206f24 ldm r7, {r2, r3}
 *   @0x206f28 ldr r0, [sp, #0x4]
 *   @0x206f2c stm r0, {r2, r3}
 *   @0x206f30 add sp, sp, #12
 *   @0x206f34 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x206f38 ldr r1, [sp, #0x4]
 *   @0x206f3c ldr r4, [r1]
 *   @0x206f40 cmp r4, #0
 *   @0x206f44 beq 0x206f64 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x250>
 *   @0x206f48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x206f4c ldr r5, [r4, #0x4]
 *   @0x206f50 sub r5, r5, #1
 *   @0x206f54 str r5, [r4, #0x4]
 *   @0x206f58 cmp r5, #0
 *   @0x206f5c beq 0x20701c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x308>
 *   @0x206f60 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x206f64 ldr r2, [sp, #0x4]
 *   @0x206f68 mov r3, #0
 *   @0x206f6c str r3, [r2]
 *   @0x206f70 b 0x206ea4 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x190>
 *   @0x206f74 ldr r3, [pc, #0x180]
 *   @0x206f78 ldr r1, [pc, #0x180]
 *   @0x206f7c ldr r3, [pc, r3]
 *   @0x206f80 add r1, pc, r1
 *   @0x206f84 ldr r0, [r3]
 *   @0x206f88 ldr r3, [r0]
 *   @0x206f8c ldr r3, [r3, #0xc]
 *   @0x206f90 blx r3
 *   @0x206f94 b 0x206e60 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x14c>
 *   @0x206f98 ldr r3, [r7]
 *   @0x206f9c ldr r0, [sp, #0x4]
 *   @0x206fa0 str r3, [r0]
 *   @0x206fa4 ldr r3, [r7]
 *   @0x206fa8 cmp r3, #0
 *   @0x206fac beq 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208>
 *   @0x206fb0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x206fb4 ldr r1, [r7]
 *   @0x206fb8 add sp, sp, #12
 *   @0x206fbc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x206fc0 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x206fc4 ldr r3, [r7]
 *   @0x206fc8 cmp r3, #0
 *   @0x206fcc ldrne r2, [r3, #0x4]
 *   @0x206fd0 addne r2, r2, #1
 *   @0x206fd4 strne r2, [r3, #0x4]
 *   @0x206fd8 ldr r2, [sp, #0x4]
 *   @0x206fdc str r3, [r2]
 *   @0x206fe0 add sp, sp, #12
 *   @0x206fe4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x206fe8 ldr r3, [r7]
 *   @0x206fec ldr r1, [sp, #0x4]
 *   @0x206ff0 cmp r3, #0
 *   @0x206ff4 str r3, [r1]
 *   @0x206ff8 beq 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208>
 *   @0x206ffc ldr r1, [r3, #0x8]
 *   @0x207000 ldr r2, [r3]
 *   @0x207004 cmp r1, #0
 *   @0x207008 add r2, r2, #1
 *   @0x20700c str r2, [r3]
 *   @0x207010 ldreq r2, [sp, #0x4]
 *   @0x207014 streq r2, [r3, #0x8]
 *   @0x207018 b 0x206f1c <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x208>
 *   @0x20701c ldr r0, [r4]
 *   @0x207020 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x207024 str r5, [r4]
 *   @0x207028 str r5, [r4, #0x8]
 *   @0x20702c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x207030 ldr r5, [r4, #0x4]
 *   @0x207034 sub r5, r5, #1
 *   @0x207038 str r5, [r4, #0x4]
 *   @0x20703c cmp r5, #0
 *   @0x207040 beq 0x207060 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x34c>
 *   @0x207044 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x207048 mov r0, r4
 *   @0x20704c bl 0x27d1d0 <_ZdlPv>
 *   @0x207050 b 0x206f60 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x24c>
 *   @0x207054 ldr r0, [sp, #0x4]
 *   @0x207058 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20705c b 0x206e90 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x17c>
 *   @0x207060 ldr r0, [r4]
 *   @0x207064 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x207068 str r5, [r4]
 *   @0x20706c str r5, [r4, #0x8]
 *   @0x207070 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x207074 ldr r5, [r4, #0x4]
 *   @0x207078 sub r5, r5, #1
 *   @0x20707c str r5, [r4, #0x4]
 *   @0x207080 cmp r5, #0
 *   @0x207084 beq 0x207098 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x384>
 *   @0x207088 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20708c mov r0, r4
 *   @0x207090 bl 0x27d1d0 <_ZdlPv>
 *   @0x207094 b 0x207044 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x330>
 *   @0x207098 ldr r0, [r4]
 *   @0x20709c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2070a0 str r5, [r4]
 *   @0x2070a4 str r5, [r4, #0x8]
 *   @0x2070a8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2070ac ldr r5, [r4, #0x4]
 *   @0x2070b0 sub r5, r5, #1
 *   @0x2070b4 str r5, [r4, #0x4]
 *   @0x2070b8 cmp r5, #0
 *   @0x2070bc beq 0x2070d0 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x3bc>
 *   @0x2070c0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2070c4 mov r0, r4
 *   @0x2070c8 bl 0x27d1d0 <_ZdlPv>
 *   @0x2070cc b 0x207088 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x374>
 *   @0x2070d0 ldr r0, [r4]
 *   @0x2070d4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2070d8 mov r0, r4
 *   @0x2070dc str r5, [r4]
 *   @0x2070e0 str r5, [r4, #0x8]
 *   @0x2070e4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x2070e8 mov r0, r4
 *   @0x2070ec bl 0x27d1d0 <_ZdlPv>
 *   @0x2070f0 b 0x2070c0 <_ZN8CDS_Grid7Get_MinER6RValueiiii+0x3ac>
 *   @0x2070f4 andseq r7, lr, r0, asr #1
 *   @0x2070f8 andseq r10, lr, r0, lsl #11
 *   @0x2070fc andseq r6, lr, r4, asr #19
 *   @0x207100 andseq r12, r4, r4, lsl #18
 *
 * ══ §26/31 b2WheelJoint::InitVelocityConstraints(b2SolverData const&)  0x2d3d80  size 1008  252 条（0x2d3d80..0x2d4170）
 * @func 0x2d3d80 0x2d4170  size 1008  252 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / b2WheelJoint::InitVelocityConstraints(b2SolverData const&)+0x2c0×2
 * 字段偏移 top8: 0x8×4 / 0x84×2 / 0x88×2 / 0x14×2 / 0x70×2 / 0x30×1 / 0x34×1 / 0x18×1
 * VFP 指令 183 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d3d80 ldr r2, [r0, #0x30]
 *   @0x2d3d84 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2d3d88 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2d3d8c mov r6, r1
 *   @0x2d3d90 vldr s21, [r2, #136]
 *   @0x2d3d94 ldr r3, [r0, #0x34]
 *   @0x2d3d98 add r1, r2, #44
 *   @0x2d3d9c ldr lr, [r2, #0x8]
 *   @0x2d3da0 mov r4, r0
 *   @0x2d3da4 vldr s20, [r3, #136]
 *   @0x2d3da8 ldr r8, [r6, #0x18]
 *   @0x2d3dac ldr r12, [r3, #0x8]
 *   @0x2d3db0 add r10, r0, #140
 *   @0x2d3db4 add r9, r0, #148
 *   @0x2d3db8 ldm r1, {r0, r1}
 *   @0x2d3dbc str lr, [r4, #0x84]
 *   @0x2d3dc0 add lr, lr, lr, lsl #1
 *   @0x2d3dc4 add r7, r3, #44
 *   @0x2d3dc8 vldr s19, [r2, #144]
 *   @0x2d3dcc lsl lr, lr, #2
 *   @0x2d3dd0 ldr r5, [r6, #0x1c]
 *   @0x2d3dd4 str r12, [r4, #0x88]
 *   @0x2d3dd8 add r12, r12, r12, lsl #1
 *   @0x2d3ddc stm r10, {r0, r1}
 *   @0x2d3de0 vldr s18, [r3, #144]
 *   @0x2d3de4 ldm r7, {r0, r1}
 *   @0x2d3de8 add r7, r8, lr
 *   @0x2d3dec lsl r12, r12, #2
 *   @0x2d3df0 add lr, r5, lr
 *   @0x2d3df4 ldr r10, [r7, #0x8]
 *   @0x2d3df8 vldr s27, [lr]
 *   @0x2d3dfc stm r9, {r0, r1}
 *   @0x2d3e00 vstr s20, [r4, #160]
 *   @0x2d3e04 vstr s21, [r4, #156]
 *   @0x2d3e08 vstr s19, [r4, #164]
 *   @0x2d3e0c mov r0, r10
 *   @0x2d3e10 vstr s18, [r4, #168]
 *   @0x2d3e14 vldr s26, [lr, #4]
 *   @0x2d3e18 vldr s25, [lr, #8]
 *   @0x2d3e1c add r8, r8, r12
 *   @0x2d3e20 add r12, r5, r12
 *   @0x2d3e24 vldr s24, [r12]
 *   @0x2d3e28 vldr s23, [r12, #4]
 *   @0x2d3e2c vldr s22, [r12, #8]
 *   @0x2d3e30 bl 0xb6580 <sinf@plt>
 *   @0x2d3e34 ldr r9, [r8, #0x8]
 *   @0x2d3e38 vadd.f32 s20, s21, s20
 *   @0x2d3e3c vmov s16, r0
 *   @0x2d3e40 mov r0, r10
 *   @0x2d3e44 bl 0xb658c <cosf@plt>
 *   @0x2d3e48 vmov s17, r0
 *   @0x2d3e4c mov r0, r9
 *   @0x2d3e50 bl 0xb6580 <sinf@plt>
 *   @0x2d3e54 vmov s28, r0
 *   @0x2d3e58 mov r0, r9
 *   @0x2d3e5c bl 0xb658c <cosf@plt>
 *   @0x2d3e60 vldr s14, [r4, #152]
 *   @0x2d3e64 vldr s12, [r4, #88]
 *   @0x2d3e68 vsub.f32 s12, s12, s14
 *   @0x2d3e6c vldr s1, [r4, #84]
 *   @0x2d3e70 vldr s7, [r4, #148]
 *   @0x2d3e74 vldr s14, [r4, #144]
 *   @0x2d3e78 vldr s10, [r4, #80]
 *   @0x2d3e7c vldr s2, [r4, #76]
 *   @0x2d3e80 vldr s8, [r4, #140]
 *   @0x2d3e84 vldr s3, [r8, #4]
 *   @0x2d3e88 vldr s13, [r4, #104]
 *   @0x2d3e8c vldr s4, [r7, #4]
 *   @0x2d3e90 vldr s6, [r8]
 *   @0x2d3e94 vldr s9, [r4, #100]
 *   @0x2d3e98 vldr s5, [r7]
 *   @0x2d3e9c mov r3, #0
 *   @0x2d3ea0 vsub.f32 s7, s1, s7
 *   @0x2d3ea4 vsub.f32 s10, s10, s14
 *   @0x2d3ea8 vmul.f32 s14, s10, s17
 *   @0x2d3eac vmov s15, r0
 *   @0x2d3eb0 vmul.f32 s11, s12, s15
 *   @0x2d3eb4 vmul.f32 s12, s12, s28
 *   @0x2d3eb8 vmla.f32 s11, s7, s28
 *   @0x2d3ebc vsub.f32 s8, s2, s8
 *   @0x2d3ec0 vnmls.f32 s12, s7, s15
 *   @0x2d3ec4 vmla.f32 s14, s8, s16
 *   @0x2d3ec8 vmul.f32 s10, s10, s16
 *   @0x2d3ecc vadd.f32 s7, s11, s3
 *   @0x2d3ed0 vmul.f32 s15, s13, s16
 *   @0x2d3ed4 vsub.f32 s7, s7, s4
 *   @0x2d3ed8 vnmls.f32 s10, s8, s17
 *   @0x2d3edc vadd.f32 s6, s12, s6
 *   @0x2d3ee0 vnmls.f32 s15, s9, s17
 *   @0x2d3ee4 vmul.f32 s13, s13, s17
 *   @0x2d3ee8 vstr s15, [r4, #180]
 *   @0x2d3eec str r3, [r4, #0xd4]
 *   @0x2d3ef0 str r3, [r4, #0xd8]
 *   @0x2d3ef4 str r3, [r4, #0xdc]
 *   @0x2d3ef8 vsub.f32 s7, s7, s14
 *   @0x2d3efc vsub.f32 s6, s6, s5
 *   @0x2d3f00 vadd.f32 s8, s14, s7
 *   @0x2d3f04 vmla.f32 s13, s9, s16
 *   @0x2d3f08 vsub.f32 s9, s6, s10
 *   @0x2d3f0c vstr s13, [r4, #184]
 *   @0x2d3f10 vmul.f32 s14, s15, s8
 *   @0x2d3f14 vadd.f32 s10, s10, s9
 *   @0x2d3f18 vnmls.f32 s14, s13, s10
 *   @0x2d3f1c vmul.f32 s15, s11, s15
 *   @0x2d3f20 vstr s14, [r4, #196]
 *   @0x2d3f24 vnmls.f32 s15, s12, s13
 *   @0x2d3f28 vmul.f32 s13, s19, s14
 *   @0x2d3f2c vstr s15, [r4, #200]
 *   @0x2d3f30 vmov.f32 s6, s20
 *   @0x2d3f34 vmla.f32 s6, s13, s14
 *   @0x2d3f38 vmul.f32 s13, s18, s15
 *   @0x2d3f3c vmov.f32 s14, s6
 *   @0x2d3f40 vldr s6, [r4, #68]
 *   @0x2d3f44 vmla.f32 s14, s13, s15
 *   @0x2d3f48 vcmpe.f32 s14, #0
 *   @0x2d3f4c vmrs APSR_nzcv, fpscr
 *   @0x2d3f50 vmovgt.f32 s15, #1.000000e+00
 *   @0x2d3f54 vdivgt.f32 s14, s15, s14
 *   @0x2d3f58 vcmpe.f32 s6, #0
 *   @0x2d3f5c vstr s14, [r4, #204]
 *   @0x2d3f60 vmrs APSR_nzcv, fpscr
 *   @0x2d3f64 strle r3, [r4, #0x74]
 *   @0x2d3f68 ble 0x2d4040 <_ZN12b2WheelJoint23InitVelocityConstraintsERK12b2SolverData+0x2c0>
 *   @0x2d3f6c vldr s13, [r4, #96]
 *   @0x2d3f70 vmul.f32 s15, s13, s16
 *   @0x2d3f74 vldr s14, [r4, #92]
 *   @0x2d3f78 vmul.f32 s13, s13, s17
 *   @0x2d3f7c vnmls.f32 s15, s14, s17
 *   @0x2d3f80 vmla.f32 s13, s14, s16
 *   @0x2d3f84 vstr s15, [r4, #172]
 *   @0x2d3f88 vmul.f32 s14, s8, s15
 *   @0x2d3f8c vstr s13, [r4, #176]
 *   @0x2d3f90 vnmls.f32 s14, s10, s13
 *   @0x2d3f94 vmul.f32 s11, s11, s15
 *   @0x2d3f98 vstr s14, [r4, #188]
 *   @0x2d3f9c vnmls.f32 s11, s12, s13
 *   @0x2d3fa0 vmul.f32 s12, s19, s14
 *   @0x2d3fa4 vstr s11, [r4, #192]
 *   @0x2d3fa8 vmla.f32 s20, s12, s14
 *   @0x2d3fac vmul.f32 s14, s18, s11
 *   @0x2d3fb0 vmla.f32 s20, s14, s11
 *   @0x2d3fb4 vcmpe.f32 s20, #0
 *   @0x2d3fb8 vmrs APSR_nzcv, fpscr
 *   @0x2d3fbc ble 0x2d4040 <_ZN12b2WheelJoint23InitVelocityConstraintsERK12b2SolverData+0x2c0>
 *   @0x2d3fc0 vmov.f32 s11, #1.000000e+00
 *   @0x2d3fc4 vldr s8, [pc, #416]
 *   @0x2d3fc8 vldr s12, [r6]
 *   @0x2d3fcc vldr s10, [r4, #72]
 *   @0x2d3fd0 vdiv.f32 s14, s11, s20
 *   @0x2d3fd4 vmul.f32 s6, s6, s8
 *   @0x2d3fd8 vstr s14, [r4, #212]
 *   @0x2d3fdc vadd.f32 s8, s14, s14
 *   @0x2d3fe0 vmul.f32 s14, s14, s6
 *   @0x2d3fe4 vmul.f32 s10, s8, s10
 *   @0x2d3fe8 vmul.f32 s14, s14, s6
 *   @0x2d3fec vmul.f32 s6, s10, s6
 *   @0x2d3ff0 vmla.f32 s6, s12, s14
 *   @0x2d3ff4 vmul.f32 s6, s6, s12
 *   @0x2d3ff8 vcmpe.f32 s6, #0
 *   @0x2d3ffc vmrs APSR_nzcv, fpscr
 *   @0x2d4000 vdivgt.f32 s11, s11, s6
 *   @0x2d4004 vstrle s6, [r4, #220]
 *   @0x2d4008 vmul.f32 s13, s7, s13
 *   @0x2d400c vstrgt s11, [r4, #220]
 *   @0x2d4010 vmovgt.f32 s6, s11
 *   @0x2d4014 vadd.f32 s20, s20, s6
 *   @0x2d4018 vmla.f32 s13, s9, s15
 *   @0x2d401c vcmpe.f32 s20, #0
 *   @0x2d4020 vmrs APSR_nzcv, fpscr
 *   @0x2d4024 vmovgt.f32 s15, #1.000000e+00
 *   @0x2d4028 vdivgt.f32 s20, s15, s20
 *   @0x2d402c vmul.f32 s13, s12, s13
 *   @0x2d4030 vstr s20, [r4, #212]
 *   @0x2d4034 vmul.f32 s14, s13, s14
 *   @0x2d4038 vmul.f32 s6, s14, s6
 *   @0x2d403c vstr s6, [r4, #216]
 *   @0x2d4040 ldrb r3, [r4, #0x80]
 *   @0x2d4044 cmp r3, #0
 *   @0x2d4048 beq 0x2d40b8 <_ZN12b2WheelJoint23InitVelocityConstraintsERK12b2SolverData+0x338>
 *   @0x2d404c vadd.f32 s18, s19, s18
 *   @0x2d4050 ldrb r3, [r6, #0x14]
 *   @0x2d4054 vcmpe.f32 s18, #0
 *   @0x2d4058 vmrs APSR_nzcv, fpscr
 *   @0x2d405c vmovgt.f32 s19, #1.000000e+00
 *   @0x2d4060 vdivgt.f32 s18, s19, s18
 *   @0x2d4064 cmp r3, #0
 *   @0x2d4068 vstr s18, [r4, #208]
 *   @0x2d406c bne 0x2d40d0 <_ZN12b2WheelJoint23InitVelocityConstraintsERK12b2SolverData+0x350>
 *   @0x2d4070 mov r3, #0
 *   @0x2d4074 str r3, [r4, #0x6c]
 *   @0x2d4078 str r3, [r4, #0x74]
 *   @0x2d407c str r3, [r4, #0x70]
 *   @0x2d4080 ldr r3, [r4, #0x84]
 *   @0x2d4084 ldr r2, [r4, #0x88]
 *   @0x2d4088 add r3, r3, r3, lsl #1
 *   @0x2d408c add r2, r2, r2, lsl #1
 *   @0x2d4090 add r3, r5, r3, lsl #2
 *   @0x2d4094 vstr s27, [r3]
 *   @0x2d4098 vstr s26, [r3, #4]
 *   @0x2d409c vstr s25, [r3, #8]
 *   @0x2d40a0 add r5, r5, r2, lsl #2
 *   @0x2d40a4 vstr s24, [r5]
 *   @0x2d40a8 vstr s23, [r5, #4]
 *   @0x2d40ac vstr s22, [r5, #8]
 *   @0x2d40b0 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2d40b4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2d40b8 mov r3, #0
 *   @0x2d40bc str r3, [r4, #0xd0]
 *   @0x2d40c0 str r3, [r4, #0x70]
 *   @0x2d40c4 ldrb r3, [r6, #0x14]
 *   @0x2d40c8 cmp r3, #0
 *   @0x2d40cc beq 0x2d4070 <_ZN12b2WheelJoint23InitVelocityConstraintsERK12b2SolverData+0x2f0>
 *   @0x2d40d0 vldr s11, [r6, #8]
 *   @0x2d40d4 vldr s14, [r4, #116]
 *   @0x2d40d8 vmul.f32 s14, s11, s14
 *   @0x2d40dc vldr s15, [r4, #108]
 *   @0x2d40e0 vldr s10, [r4, #188]
 *   @0x2d40e4 vldr s12, [r4, #192]
 *   @0x2d40e8 vldr s13, [r4, #172]
 *   @0x2d40ec vldr s0, [r4, #176]
 *   @0x2d40f0 vldr s1, [r4, #196]
 *   @0x2d40f4 vldr s2, [r4, #200]
 *   @0x2d40f8 vldr s3, [r4, #112]
 *   @0x2d40fc vldr s4, [r4, #180]
 *   @0x2d4100 vldr s5, [r4, #184]
 *   @0x2d4104 vldr s8, [r4, #156]
 *   @0x2d4108 vldr s9, [r4, #160]
 *   @0x2d410c vldr s6, [r4, #164]
 *   @0x2d4110 vldr s7, [r4, #168]
 *   @0x2d4114 vmul.f32 s15, s11, s15
 *   @0x2d4118 vstr s14, [r4, #116]
 *   @0x2d411c vmul.f32 s10, s14, s10
 *   @0x2d4120 vstr s15, [r4, #108]
 *   @0x2d4124 vmul.f32 s12, s14, s12
 *   @0x2d4128 vmul.f32 s13, s14, s13
 *   @0x2d412c vmul.f32 s14, s14, s0
 *   @0x2d4130 vmla.f32 s10, s15, s1
 *   @0x2d4134 vmla.f32 s12, s15, s2
 *   @0x2d4138 vmul.f32 s11, s11, s3
 *   @0x2d413c vmla.f32 s13, s15, s4
 *   @0x2d4140 vstr s11, [r4, #112]
 *   @0x2d4144 vmla.f32 s14, s15, s5
 *   @0x2d4148 vadd.f32 s10, s11, s10
 *   @0x2d414c vadd.f32 s12, s11, s12
 *   @0x2d4150 vmls.f32 s25, s10, s6
 *   @0x2d4154 vmla.f32 s22, s12, s7
 *   @0x2d4158 vmls.f32 s27, s8, s13
 *   @0x2d415c vmls.f32 s26, s8, s14
 *   @0x2d4160 vmla.f32 s24, s9, s13
 *   @0x2d4164 vmla.f32 s23, s9, s14
 *   @0x2d4168 b 0x2d4080 <_ZN12b2WheelJoint23InitVelocityConstraintsERK12b2SolverData+0x300>
 *   @0x2d416c ldrdmi r0, r1, [r9], #251
 *
 * ══ §27/31 anon_319db4  0x319db4  size 1004  251 条（0x319db4..0x31a1a0）
 * @func 0x319db4 0x31a1a0  size 1004  251 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_319c40×6 / anon_319cc4×4 / anon_319630×3 / anon_319630+0x28c×2 / __cxa_type_match×2 / anon_319db4+0x118 / __cxa_begin_cleanup / anon_319db4+0x390
 * 字段偏移 top8: 0x4×5 / 0x10×4 / 0x20×4 / 0x28×4 / 0x14×3 / 0x18×2 / 0x1d×2 / 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x319db4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x319db8 mov r6, r2
 *   @0x319dbc ldr r2, [r1, #0x4c]
 *   @0x319dc0 sub sp, sp, #36
 *   @0x319dc4 subs r9, r3, #0
 *   @0x319dc8 mov r4, r1
 *   @0x319dcc add r5, r2, #4
 *   @0x319dd0 and r7, r0, #3
 *   @0x319dd4 ldr r2, [r2]
 *   @0x319dd8 str r5, [sp, #0x18]
 *   @0x319ddc str r2, [sp, #0x14]
 *   @0x319de0 bne 0x319dfc <__gnu_Unwind_Backtrace+0x10c>
 *   @0x319de4 lsl r2, r2, #8
 *   @0x319de8 mov r3, #3
 *   @0x319dec str r2, [sp, #0x14]
 *   @0x319df0 strb r9, [sp, #0x1d]
 *   @0x319df4 strb r3, [sp, #0x1c]
 *   @0x319df8 b 0x319e24 <__gnu_Unwind_Backtrace+0x134>
 *   @0x319dfc cmp r9, #2
 *   @0x319e00 bgt 0x319e24 <__gnu_Unwind_Backtrace+0x134>
 *   @0x319e04 lsr r3, r2, #16
 *   @0x319e08 strb r3, [sp, #0x1d]
 *   @0x319e0c lsl r2, r2, #16
 *   @0x319e10 str r2, [sp, #0x14]
 *   @0x319e14 uxtb r3, r3
 *   @0x319e18 mov r2, #2
 *   @0x319e1c strb r2, [sp, #0x1c]
 *   @0x319e20 add r5, r5, r3, lsl #2
 *   @0x319e24 cmp r7, #2
 *   @0x319e28 ldr r10, [r4, #0x50]
 *   @0x319e2c ldreq r5, [r4, #0x38]
 *   @0x319e30 ands r10, r10, #1
 *   @0x319e34 bne 0x31a130 <__gnu_Unwind_Backtrace+0x440>
 *   @0x319e38 eor r0, r0, #8
 *   @0x319e3c ubfx r0, r0, #0x3, #0x1
 *   @0x319e40 str r0, [sp, #0xc]
 *   @0x319e44 ldr r8, [r5]
 *   @0x319e48 cmp r8, #0
 *   @0x319e4c beq 0x31a134 <__gnu_Unwind_Backtrace+0x444>
 *   @0x319e50 cmp r9, #2
 *   @0x319e54 ldr r2, [r4, #0x48]
 *   @0x319e58 mov r0, r6
 *   @0x319e5c mov r1, #15
 *   @0x319e60 ldreq r11, [r5, #0x4]
 *   @0x319e64 addeq r5, r5, #8
 *   @0x319e68 ldrhne r11, [r5, #2]
 *   @0x319e6c ldrhne r8, [r5]
 *   @0x319e70 addne r5, r5, #4
 *   @0x319e74 bic r3, r11, #1
 *   @0x319e78 add r3, r3, r2
 *   @0x319e7c str r3, [sp, #0x4]
 *   @0x319e80 bl 0x319c40 <_Unwind_VRS_Get+0x5c>
 *   @0x319e84 ldr r3, [sp, #0x4]
 *   @0x319e88 cmp r3, r0
 *   @0x319e8c movhi r0, #0
 *   @0x319e90 bhi 0x319ea8 <__gnu_Unwind_Backtrace+0x1b8>
 *   @0x319e94 bic r2, r8, #1
 *   @0x319e98 add r3, r3, r2
 *   @0x319e9c cmp r0, r3
 *   @0x319ea0 movhs r0, #0
 *   @0x319ea4 movlo r0, #1
 *   @0x319ea8 and r11, r11, #1
 *   @0x319eac and r8, r8, #1
 *   @0x319eb0 orr r8, r8, r11, lsl #1
 *   @0x319eb4 cmp r8, #1
 *   @0x319eb8 beq 0x319f1c <__gnu_Unwind_Backtrace+0x22c>
 *   @0x319ebc blo 0x319ecc <__gnu_Unwind_Backtrace+0x1dc>
 *   @0x319ec0 cmp r8, #2
 *   @0x319ec4 beq 0x319ffc <__gnu_Unwind_Backtrace+0x30c>
 *   @0x319ec8 b 0x31a194 <__gnu_Unwind_Backtrace+0x4a4>
 *   @0x319ecc cmp r7, #0
 *   @0x319ed0 moveq r0, #0
 *   @0x319ed4 andne r0, r0, #1
 *   @0x319ed8 add r8, r5, #4
 *   @0x319edc cmp r0, #0
 *   @0x319ee0 beq 0x319f14 <__gnu_Unwind_Backtrace+0x224>
 *   @0x319ee4 mov r0, r5
 *   @0x319ee8 bl 0x319630 <__gnu_uldivmod_helper+0x3c>
 *   @0x319eec str r8, [r4, #0x38]
 *   @0x319ef0 mov r5, r0
 *   @0x319ef4 mov r0, r4
 *   @0x319ef8 blx 0x318628 <__cxa_begin_cleanup>
 *   @0x319efc cmp r0, #0
 *   @0x319f00 beq 0x31a194 <__gnu_Unwind_Backtrace+0x4a4>
 *   @0x319f04 mov r0, r6
 *   @0x319f08 mov r1, #15
 *   @0x319f0c mov r2, r5
 *   @0x319f10 b 0x319fe8 <__gnu_Unwind_Backtrace+0x2f8>
 *   @0x319f14 mov r5, r8
 *   @0x319f18 b 0x319e44 <__gnu_Unwind_Backtrace+0x154>
 *   @0x319f1c cmp r7, #0
 *   @0x319f20 bne 0x319fa0 <__gnu_Unwind_Backtrace+0x2b0>
 *   @0x319f24 cmp r0, #0
 *   @0x319f28 beq 0x319ff4 <__gnu_Unwind_Backtrace+0x304>
 *   @0x319f2c ldr r3, [r5, #0x4]
 *   @0x319f30 ldr r11, [r5]
 *   @0x319f34 cmn r3, #2
 *   @0x319f38 lsr r11, r11, #31
 *   @0x319f3c beq 0x31a194 <__gnu_Unwind_Backtrace+0x4a4>
 *   @0x319f40 cmn r3, #1
 *   @0x319f44 add r2, r4, #88
 *   @0x319f48 str r2, [sp, #0x10]
 *   @0x319f4c beq 0x319f74 <__gnu_Unwind_Backtrace+0x284>
 *   @0x319f50 add r0, r5, #4
 *   @0x319f54 bl 0x3198bc <__gnu_uldivmod_helper+0x2c8>
 *   @0x319f58 mov r2, r11
 *   @0x319f5c add r3, sp, #16
 *   @0x319f60 mov r1, r0
 *   @0x319f64 mov r0, r4
 *   @0x319f68 blx 0x3185b4 <__cxa_type_match>
 *   @0x319f6c subs r8, r0, #0
 *   @0x319f70 beq 0x319ff4 <__gnu_Unwind_Backtrace+0x304>
 *   @0x319f74 mov r0, r6
 *   @0x319f78 mov r1, #13
 *   @0x319f7c bl 0x319c40 <_Unwind_VRS_Get+0x5c>
 *   @0x319f80 cmp r8, #2
 *   @0x319f84 ldr r2, [sp, #0x10]
 *   @0x319f88 moveq r3, r4
 *   @0x319f8c strne r2, [r4, #0x24]
 *   @0x319f90 str r0, [r4, #0x20]
 *   @0x319f94 streq r2, [r3, #0x2c]!
 *   @0x319f98 bne 0x31a094 <__gnu_Unwind_Backtrace+0x3a4>
 *   @0x319f9c b 0x31a090 <__gnu_Unwind_Backtrace+0x3a0>
 *   @0x319fa0 mov r0, r6
 *   @0x319fa4 mov r1, #13
 *   @0x319fa8 ldr r8, [r4, #0x20]
 *   @0x319fac bl 0x319c40 <_Unwind_VRS_Get+0x5c>
 *   @0x319fb0 cmp r8, r0
 *   @0x319fb4 bne 0x319ff4 <__gnu_Unwind_Backtrace+0x304>
 *   @0x319fb8 ldr r3, [r4, #0x28]
 *   @0x319fbc cmp r5, r3
 *   @0x319fc0 bne 0x319ff4 <__gnu_Unwind_Backtrace+0x304>
 *   @0x319fc4 mov r0, r5
 *   @0x319fc8 bl 0x319630 <__gnu_uldivmod_helper+0x3c>
 *   @0x319fcc mov r1, #15
 *   @0x319fd0 mov r2, r0
 *   @0x319fd4 mov r0, r6
 *   @0x319fd8 bl 0x319cc4 <_Unwind_VRS_Set+0x5c>
 *   @0x319fdc mov r0, r6
 *   @0x319fe0 mov r1, #0
 *   @0x319fe4 mov r2, r4
 *   @0x319fe8 bl 0x319cc4 <_Unwind_VRS_Set+0x5c>
 *   @0x319fec mov r0, #7
 *   @0x319ff0 b 0x31a198 <__gnu_Unwind_Backtrace+0x4a8>
 *   @0x319ff4 add r5, r5, #8
 *   @0x319ff8 b 0x319e44 <__gnu_Unwind_Backtrace+0x154>
 *   @0x319ffc ldr r8, [r5]
 *   @0x31a000 cmp r7, #0
 *   @0x31a004 bic r8, r8, #-2147483648
 *   @0x31a008 bne 0x31a0a0 <__gnu_Unwind_Backtrace+0x3b0>
 *   @0x31a00c cmp r0, #0
 *   @0x31a010 beq 0x31a118 <__gnu_Unwind_Backtrace+0x428>
 *   @0x31a014 ldr r3, [sp, #0xc]
 *   @0x31a018 cmp r8, #0
 *   @0x31a01c orreq r3, r3, #1
 *   @0x31a020 cmp r3, #0
 *   @0x31a024 beq 0x31a118 <__gnu_Unwind_Backtrace+0x428>
 *   @0x31a028 add r11, sp, #16
 *   @0x31a02c mov r12, r7
 *   @0x31a030 add r3, r4, #88
 *   @0x31a034 str r3, [sp, #0x8]
 *   @0x31a038 cmp r12, r8
 *   @0x31a03c beq 0x31a07c <__gnu_Unwind_Backtrace+0x38c>
 *   @0x31a040 add r12, r12, #1
 *   @0x31a044 ldr r3, [sp, #0x8]
 *   @0x31a048 str r12, [sp, #0x4]
 *   @0x31a04c add r0, r5, r12, lsl #2
 *   @0x31a050 str r3, [sp, #0x10]
 *   @0x31a054 bl 0x3198bc <__gnu_uldivmod_helper+0x2c8>
 *   @0x31a058 mov r2, #0
 *   @0x31a05c mov r3, r11
 *   @0x31a060 mov r1, r0
 *   @0x31a064 mov r0, r4
 *   @0x31a068 blx 0x3185b4 <__cxa_type_match>
 *   @0x31a06c ldr r12, [sp, #0x4]
 *   @0x31a070 cmp r0, #0
 *   @0x31a074 beq 0x31a038 <__gnu_Unwind_Backtrace+0x348>
 *   @0x31a078 b 0x31a118 <__gnu_Unwind_Backtrace+0x428>
 *   @0x31a07c mov r0, r6
 *   @0x31a080 mov r1, #13
 *   @0x31a084 bl 0x319c40 <_Unwind_VRS_Get+0x5c>
 *   @0x31a088 ldr r3, [sp, #0x10]
 *   @0x31a08c str r0, [r4, #0x20]
 *   @0x31a090 str r3, [r4, #0x24]
 *   @0x31a094 str r5, [r4, #0x28]
 *   @0x31a098 mov r0, #6
 *   @0x31a09c b 0x31a198 <__gnu_Unwind_Backtrace+0x4a8>
 *   @0x31a0a0 mov r0, r6
 *   @0x31a0a4 mov r1, #13
 *   @0x31a0a8 ldr r11, [r4, #0x20]
 *   @0x31a0ac bl 0x319c40 <_Unwind_VRS_Get+0x5c>
 *   @0x31a0b0 cmp r11, r0
 *   @0x31a0b4 bne 0x31a118 <__gnu_Unwind_Backtrace+0x428>
 *   @0x31a0b8 ldr r3, [r4, #0x28]
 *   @0x31a0bc cmp r5, r3
 *   @0x31a0c0 bne 0x31a118 <__gnu_Unwind_Backtrace+0x428>
 *   @0x31a0c4 mov r10, #0
 *   @0x31a0c8 mov r3, #4
 *   @0x31a0cc str r8, [r4, #0x28]
 *   @0x31a0d0 str r3, [r4, #0x30]
 *   @0x31a0d4 add r3, r5, r3
 *   @0x31a0d8 str r10, [r4, #0x2c]
 *   @0x31a0dc str r3, [r4, #0x34]
 *   @0x31a0e0 ldr r3, [r5]
 *   @0x31a0e4 cmp r3, r10
 *   @0x31a0e8 bge 0x31a114 <__gnu_Unwind_Backtrace+0x424>
 *   @0x31a0ec add r0, r8, #1
 *   @0x31a0f0 add r0, r5, r0, lsl #2
 *   @0x31a0f4 bl 0x319630 <__gnu_uldivmod_helper+0x3c>
 *   @0x31a0f8 mov r1, #15
 *   @0x31a0fc mov r2, r0
 *   @0x31a100 mov r0, r6
 *   @0x31a104 bl 0x319cc4 <_Unwind_VRS_Set+0x5c>
 *   @0x31a108 mov r0, r6
 *   @0x31a10c mov r1, r10
 *   @0x31a110 b 0x319fe4 <__gnu_Unwind_Backtrace+0x2f4>
 *   @0x31a114 mov r10, #1
 *   @0x31a118 ldr r3, [r5]
 *   @0x31a11c add r8, r8, #1
 *   @0x31a120 cmp r3, #0
 *   @0x31a124 addlt r5, r5, #4
 *   @0x31a128 add r5, r5, r8, lsl #2
 *   @0x31a12c b 0x319e44 <__gnu_Unwind_Backtrace+0x154>
 *   @0x31a130 mov r10, #0
 *   @0x31a134 cmp r9, #2
 *   @0x31a138 ble 0x31a144 <__gnu_Unwind_Backtrace+0x454>
 *   @0x31a13c bl 0x3198d0 <__gnu_uldivmod_helper+0x2dc>
 *   @0x31a140 b 0x31a150 <__gnu_Unwind_Backtrace+0x460>
 *   @0x31a144 mov r0, r6
 *   @0x31a148 add r1, sp, #20
 *   @0x31a14c bl 0x31a73c <__gnu_unwind_execute>
 *   @0x31a150 cmp r0, #0
 *   @0x31a154 bne 0x31a194 <__gnu_Unwind_Backtrace+0x4a4>
 *   @0x31a158 cmp r10, #0
 *   @0x31a15c moveq r0, #8
 *   @0x31a160 beq 0x31a198 <__gnu_Unwind_Backtrace+0x4a8>
 *   @0x31a164 mov r1, #15
 *   @0x31a168 mov r0, r6
 *   @0x31a16c bl 0x319c40 <_Unwind_VRS_Get+0x5c>
 *   @0x31a170 mov r1, #14
 *   @0x31a174 mov r2, r0
 *   @0x31a178 mov r0, r6
 *   @0x31a17c bl 0x319cc4 <_Unwind_VRS_Set+0x5c>
 *   @0x31a180 ldr r2, [pc, #0x18]
 *   @0x31a184 mov r0, r6
 *   @0x31a188 mov r1, #15
 *   @0x31a18c ldr r2, [pc, r2]
 *   @0x31a190 b 0x319fe8 <__gnu_Unwind_Backtrace+0x2f8>
 *   @0x31a194 mov r0, #9
 *   @0x31a198 add sp, sp, #36
 *   @0x31a19c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §28/31 Sprite_Add_BIN(void*, int, int, int, bool, bool, int, int)  0x1efbd8  size 996  249 条（0x1efbd8..0x1effbc）
 * @func 0x1efbd8 0x1effd0  size 1016  254 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1efc04→0x7530d8, 0x1efc08→0x7530d0, 0x1efc64→0x7530dc, 0x1efcb8→0x7530e0
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / 0xb65c8 / YYStrDup(char const*) / unsigned int CHashMapCalculateHash<char const*>(char const*) / Sprite_Add_BIN(void*, int, int, int, bool, bool, int, int)+0x158 / operator new(unsigned int) / CSprite::CSprite() / CSprite::LoadFromData(void*, int, int, int, bool, bool, bool, int, int, bool)
 * 字段偏移 top8: 0x4×12 / 0x8×10 / 0x2×6 / 0x10×5 / 0x24×4 / 0x28×4 / 0x2c×3 / 0x3b0×2
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1efbd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1efbdc sub sp, sp, #340
 *   @0x1efbe0 ldr r4, [pc, #0x3b0]
 *   @0x1efbe4 ldr r12, [pc, #0x3b0]
 *   @0x1efbe8 add r4, pc, r4
 *   @0x1efbec str r0, [sp, #0x30]
 *   @0x1efbf0 str r1, [sp, #0x34]
 *   @0x1efbf4 str r2, [sp, #0x38]
 *   @0x1efbf8 str r3, [sp, #0x3c]
 *   @0x1efbfc movw r3, #0x255
 *   @0x1efc00 ldr r12, [r4, r12]
 *   @0x1efc04 ldr r1, [pc, #0x394]
 *   @0x1efc08 ldr r0, [pc, #0x394]
 *   @0x1efc0c str r12, [sp, #0x2c]
 *   @0x1efc10 ldr lr, [sp, #0x2c]
 *   @0x1efc14 ldrb r12, [sp, #0x178]
 *   @0x1efc18 ldr r5, [pc, #0x388]
 *   @0x1efc1c str r12, [sp, #0x40]
 *   @0x1efc20 add r5, pc, r5
 *   @0x1efc24 ldr r12, [lr]
 *   @0x1efc28 ldrb lr, [sp, #0x17c]
 *   @0x1efc2c mov r2, r5
 *   @0x1efc30 str r12, [sp, #0x14c]
 *   @0x1efc34 str lr, [sp, #0x44]
 *   @0x1efc38 ldr r6, [r4, r1]
 *   @0x1efc3c ldr r1, [r6]
 *   @0x1efc40 add r1, r1, #1
 *   @0x1efc44 str r1, [r6]
 *   @0x1efc48 ldr r0, [r4, r0]
 *   @0x1efc4c lsl r1, r1, #2
 *   @0x1efc50 str r0, [sp, #0x24]
 *   @0x1efc54 add r0, r0, #4
 *   @0x1efc58 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1efc5c ldr r1, [r6]
 *   @0x1efc60 mov r2, r5
 *   @0x1efc64 ldr r0, [pc, #0x340]
 *   @0x1efc68 ldr r5, [sp, #0x24]
 *   @0x1efc6c movw r3, #0x257
 *   @0x1efc70 str r1, [r5]
 *   @0x1efc74 lsl r1, r1, #2
 *   @0x1efc78 ldr r0, [r4, r0]
 *   @0x1efc7c add r5, sp, #76
 *   @0x1efc80 str r0, [sp, #0x28]
 *   @0x1efc84 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1efc88 ldr r3, [r6]
 *   @0x1efc8c mov r1, #256
 *   @0x1efc90 ldr r2, [pc, #0x318]
 *   @0x1efc94 mov r0, r5
 *   @0x1efc98 sub r3, r3, #1
 *   @0x1efc9c add r2, pc, r2
 *   @0x1efca0 bl 0xb65c8 <snprintf@plt>
 *   @0x1efca4 ldr r12, [sp, #0x28]
 *   @0x1efca8 mov r0, r5
 *   @0x1efcac ldr r8, [r6]
 *   @0x1efcb0 ldr r7, [r12]
 *   @0x1efcb4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1efcb8 ldr r2, [pc, #0x2f4]
 *   @0x1efcbc sub r8, r8, #-1073741823
 *   @0x1efcc0 ldr r5, [r6]
 *   @0x1efcc4 sub r3, r5, #-1073741823
 *   @0x1efcc8 sub r5, r5, #1
 *   @0x1efccc str r0, [r7, r8, lsl #2]
 *   @0x1efcd0 ldr r7, [r4, r2]
 *   @0x1efcd4 ldr r4, [sp, #0x28]
 *   @0x1efcd8 ldr r2, [r7, #0x4]
 *   @0x1efcdc ldr r1, [r7, #0xc]
 *   @0x1efce0 ldr r0, [r4]
 *   @0x1efce4 cmp r2, r1
 *   @0x1efce8 ldr r4, [r0, r3, lsl #2]
 *   @0x1efcec bgt 0x1efe8c <_Z14Sprite_Add_BINPviiibbii+0x2b4>
 *   @0x1efcf0 mov r0, r4
 *   @0x1efcf4 add r2, r2, #1
 *   @0x1efcf8 str r2, [r7, #0x4]
 *   @0x1efcfc bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x1efd00 ldr lr, [r7, #0x8]
 *   @0x1efd04 ldr r10, [r7, #0x10]
 *   @0x1efd08 bic r0, r0, #-2147483648
 *   @0x1efd0c and r3, r0, lr
 *   @0x1efd10 add r2, r3, r3, lsl #1
 *   @0x1efd14 add r2, r10, r2, lsl #2
 *   @0x1efd18 ldr r1, [r2, #0x8]
 *   @0x1efd1c cmp r1, #0
 *   @0x1efd20 ldrne r11, [r7]
 *   @0x1efd24 movne r8, #0
 *   @0x1efd28 bne 0x1efd70 <_Z14Sprite_Add_BINPviiibbii+0x198>
 *   @0x1efd2c b 0x1efdbc <_Z14Sprite_Add_BINPviiibbii+0x1e4>
 *   @0x1efd30 ldr r9, [r2]
 *   @0x1efd34 ldr r8, [r2, #0x4]
 *   @0x1efd38 str r0, [r2, #0x8]
 *   @0x1efd3c mov r0, r1
 *   @0x1efd40 str r4, [r2]
 *   @0x1efd44 mov r4, r9
 *   @0x1efd48 str r5, [r2, #0x4]
 *   @0x1efd4c mov r5, r8
 *   @0x1efd50 add r3, r3, #1
 *   @0x1efd54 add r8, r12, #1
 *   @0x1efd58 and r3, r3, lr
 *   @0x1efd5c add r2, r3, r3, lsl #1
 *   @0x1efd60 add r2, r10, r2, lsl #2
 *   @0x1efd64 ldr r1, [r2, #0x8]
 *   @0x1efd68 cmp r1, #0
 *   @0x1efd6c beq 0x1efdbc <_Z14Sprite_Add_BINPviiibbii+0x1e4>
 *   @0x1efd70 add r12, r11, r3
 *   @0x1efd74 and r9, r1, lr
 *   @0x1efd78 rsb r12, r9, r12
 *   @0x1efd7c and r12, r12, lr
 *   @0x1efd80 cmp r12, r8
 *   @0x1efd84 blt 0x1efd30 <_Z14Sprite_Add_BINPviiibbii+0x158>
 *   @0x1efd88 movne r12, r8
 *   @0x1efd8c bne 0x1efd50 <_Z14Sprite_Add_BINPviiibbii+0x178>
 *   @0x1efd90 cmp r1, r0
 *   @0x1efd94 bne 0x1efd50 <_Z14Sprite_Add_BINPviiibbii+0x178>
 *   @0x1efd98 ldr r8, [r2]
 *   @0x1efd9c cmp r4, r8
 *   @0x1efda0 bne 0x1efd50 <_Z14Sprite_Add_BINPviiibbii+0x178>
 *   @0x1efda4 ldr r3, [r7, #0x4]
 *   @0x1efda8 str r1, [r2, #0x8]
 *   @0x1efdac stm r2, {r4, r5}
 *   @0x1efdb0 sub r3, r3, #1
 *   @0x1efdb4 str r3, [r7, #0x4]
 *   @0x1efdb8 b 0x1efdc4 <_Z14Sprite_Add_BINPviiibbii+0x1ec>
 *   @0x1efdbc stm r2, {r4, r5}
 *   @0x1efdc0 str r0, [r2, #0x8]
 *   @0x1efdc4 mov r0, #136
 *   @0x1efdc8 bl 0x27c524 <_Znwj>
 *   @0x1efdcc mov r4, r0
 *   @0x1efdd0 bl 0x1e761c <_ZN7CSpriteC2Ev>
 *   @0x1efdd4 ldr r5, [sp, #0x24]
 *   @0x1efdd8 mov r12, #0
 *   @0x1efddc ldr r0, [r6]
 *   @0x1efde0 ldr r1, [sp, #0x30]
 *   @0x1efde4 ldr lr, [r5, #0x4]
 *   @0x1efde8 sub r0, r0, #-1073741823
 *   @0x1efdec ldr r2, [sp, #0x34]
 *   @0x1efdf0 ldr r3, [sp, #0x38]
 *   @0x1efdf4 str r4, [lr, r0, lsl #2]
 *   @0x1efdf8 mov lr, #1
 *   @0x1efdfc ldr r4, [r5, #0x4]
 *   @0x1efe00 ldr r5, [sp, #0x40]
 *   @0x1efe04 ldr r0, [r4, r0, lsl #2]
 *   @0x1efe08 ldr r4, [sp, #0x3c]
 *   @0x1efe0c str r5, [sp, #0x4]
 *   @0x1efe10 ldr r5, [sp, #0x180]
 *   @0x1efe14 str r4, [sp]
 *   @0x1efe18 ldr r4, [sp, #0x44]
 *   @0x1efe1c str r5, [sp, #0x10]
 *   @0x1efe20 str r12, [sp, #0x8]
 *   @0x1efe24 str r4, [sp, #0xc]
 *   @0x1efe28 ldr r4, [sp, #0x184]
 *   @0x1efe2c str lr, [sp, #0x18]
 *   @0x1efe30 str r4, [sp, #0x14]
 *   @0x1efe34 bl 0x1e6fd4 <_ZN7CSprite12LoadFromDataEPviiibbbiib>
 *   @0x1efe38 cmp r0, #0
 *   @0x1efe3c beq 0x1eff7c <_Z14Sprite_Add_BINPviiibbii+0x3a4>
 *   @0x1efe40 ldr r5, [sp, #0x24]
 *   @0x1efe44 ldr r12, [sp, #0x28]
 *   @0x1efe48 ldr r2, [r6]
 *   @0x1efe4c ldr r3, [r5, #0x4]
 *   @0x1efe50 ldr r0, [r12]
 *   @0x1efe54 sub r1, r2, #-1073741823
 *   @0x1efe58 sub r2, r2, #1
 *   @0x1efe5c ldr r3, [r3, r1, lsl #2]
 *   @0x1efe60 ldr r1, [r0, r1, lsl #2]
 *   @0x1efe64 mov r0, r2
 *   @0x1efe68 str r2, [r3, #0x60]
 *   @0x1efe6c str r1, [r3, #0x5c]
 *   @0x1efe70 ldr r4, [sp, #0x2c]
 *   @0x1efe74 ldr r2, [sp, #0x14c]
 *   @0x1efe78 ldr r3, [r4]
 *   @0x1efe7c cmp r2, r3
 *   @0x1efe80 bne 0x1eff90 <_Z14Sprite_Add_BINPviiibbii+0x3b8>
 *   @0x1efe84 add sp, sp, #340
 *   @0x1efe88 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1efe8c ldr r10, [r7]
 *   @0x1efe90 mov r3, #1
 *   @0x1efe94 ldr r1, [pc, #0x11c]
 *   @0x1efe98 mov r2, #70
 *   @0x1efe9c ldr r9, [r7, #0x10]
 *   @0x1efea0 lsl r0, r10, r3
 *   @0x1efea4 add r1, pc, r1
 *   @0x1efea8 add r8, r0, r10, lsl #2
 *   @0x1efeac str r0, [r7]
 *   @0x1efeb0 sub r0, r0, #1
 *   @0x1efeb4 str r0, [r7, #0x8]
 *   @0x1efeb8 lsl r8, r8, #2
 *   @0x1efebc mov r0, r8
 *   @0x1efec0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1efec4 mov r2, r8
 *   @0x1efec8 mov r1, #0
 *   @0x1efecc str r0, [r7, #0x10]
 *   @0x1efed0 bl 0xb65b0 <memset@plt>
 *   @0x1efed4 ldr r2, [r7]
 *   @0x1efed8 vldr s15, [pc, #180]
 *   @0x1efedc mov r1, #0
 *   @0x1efee0 str r1, [r7, #0x4]
 *   @0x1efee4 cmp r2, r1
 *   @0x1efee8 vmov s13, r2
 *   @0x1efeec vcvt.f32.s32 s14, s13
 *   @0x1efef0 vmul.f32 s15, s14, s15
 *   @0x1efef4 vcvt.s32.f32 s15, s15
 *   @0x1efef8 vstr s15, [r7, #12]
 *   @0x1efefc ble 0x1eff1c <_Z14Sprite_Add_BINPviiibbii+0x344>
 *   @0x1eff00 add r2, r2, r2, lsl #1
 *   @0x1eff04 ldr r3, [r7, #0x10]
 *   @0x1eff08 add r2, r3, r2, lsl #2
 *   @0x1eff0c str r1, [r3, #0x8]
 *   @0x1eff10 add r3, r3, #12
 *   @0x1eff14 cmp r3, r2
 *   @0x1eff18 bne 0x1eff0c <_Z14Sprite_Add_BINPviiibbii+0x334>
 *   @0x1eff1c cmp r10, #0
 *   @0x1eff20 movgt r8, r9
 *   @0x1eff24 movgt r11, #0
 *   @0x1eff28 ble 0x1eff54 <_Z14Sprite_Add_BINPviiibbii+0x37c>
 *   @0x1eff2c ldr r3, [r8, #0x8]
 *   @0x1eff30 cmp r3, #0
 *   @0x1eff34 ble 0x1eff44 <_Z14Sprite_Add_BINPviiibbii+0x36c>
 *   @0x1eff38 mov r0, r7
 *   @0x1eff3c ldm r8, {r1, r2}
 *   @0x1eff40 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i>
 *   @0x1eff44 add r11, r11, #1
 *   @0x1eff48 add r8, r8, #12
 *   @0x1eff4c cmp r11, r10
 *   @0x1eff50 bne 0x1eff2c <_Z14Sprite_Add_BINPviiibbii+0x354>
 *   @0x1eff54 mov r0, r9
 *   @0x1eff58 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1eff5c vldr s13, [r7]
 *   @0x1eff60 vcvt.f32.s32 s14, s13
 *   @0x1eff64 vldr s15, [pc, #40]
 *   @0x1eff68 ldr r2, [r7, #0x4]
 *   @0x1eff6c vmul.f32 s15, s14, s15
 *   @0x1eff70 vcvt.s32.f32 s15, s15
 *   @0x1eff74 vstr s15, [r7, #12]
 *   @0x1eff78 b 0x1efcf0 <_Z14Sprite_Add_BINPviiibbii+0x118>
 *   @0x1eff7c ldr r3, [r6]
 *   @0x1eff80 mvn r0, #0
 *   @0x1eff84 add r3, r3, r0
 *   @0x1eff88 str r3, [r6]
 *   @0x1eff8c b 0x1efe70 <_Z14Sprite_Add_BINPviiibbii+0x298>
 *   @0x1eff90 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1eff94 svclo #0x19999a
 *   @0x1eff98 eoreq r2, r0, r8, rrx
 *   @0x1eff9c .word 0xffffbd00
 *   @0x1effa0 .word 0xfffff1c0
 *   @0x1effa4 .word 0xfffff1b8
 *   @0x1effa8 andseq r2, r6, r0, lsr #20
 *   @0x1effac .word 0xfffff1bc
 *   @0x1effb0 ldrsbeq r2, [r6], -r12
 *   @0x1effb4 .word 0xfffff1c4
 *   @0x1effb8 andseq r1, r4, r12, lsl #3
 *
 * ══ §29/31 __udivdi3  0x31b698  size 996  249 条（0x31b698..0x31ba7c）
 * @func 0x31b698 0x31ba7c  size 996  249 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __udivsi3×9 / __aeabi_uidivmod×8 / __udivdi3+0xec
 * 字段偏移 top8: 0x4×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31b698 cmp r3, #0
 *   @0x31b69c push {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x31b6a0 mov r6, r0
 *   @0x31b6a4 mov r5, r1
 *   @0x31b6a8 mov r4, r2
 *   @0x31b6ac mov r7, r0
 *   @0x31b6b0 mov r8, r1
 *   @0x31b6b4 bne 0x31b91c <__udivdi3+0x284>
 *   @0x31b6b8 cmp r2, r1
 *   @0x31b6bc bls 0x31b784 <__udivdi3+0xec>
 *   @0x31b6c0 clz r3, r2
 *   @0x31b6c4 cmp r3, #0
 *   @0x31b6c8 rsbne r8, r3, #32
 *   @0x31b6cc lslne r4, r2, r3
 *   @0x31b6d0 lsrne r8, r0, r8
 *   @0x31b6d4 lslne r7, r0, r3
 *   @0x31b6d8 orrne r8, r8, r1, lsl r3
 *   @0x31b6dc lsr r5, r4, #16
 *   @0x31b6e0 uxth r9, r4
 *   @0x31b6e4 mov r0, r8
 *   @0x31b6e8 mov r1, r5
 *   @0x31b6ec bl 0x318c48 <__udivsi3>
 *   @0x31b6f0 mov r1, r5
 *   @0x31b6f4 mov r6, r0
 *   @0x31b6f8 mul r10, r9, r0
 *   @0x31b6fc mov r0, r8
 *   @0x31b700 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b704 lsr r3, r7, #16
 *   @0x31b708 orr r1, r3, r1, lsl #16
 *   @0x31b70c cmp r1, r10
 *   @0x31b710 movhs r8, r6
 *   @0x31b714 bhs 0x31b730 <__udivdi3+0x98>
 *   @0x31b718 adds r1, r1, r4
 *   @0x31b71c sub r8, r6, #1
 *   @0x31b720 bhs 0x31b730 <__udivdi3+0x98>
 *   @0x31b724 cmp r1, r10
 *   @0x31b728 sublo r8, r6, #2
 *   @0x31b72c addlo r1, r1, r4
 *   @0x31b730 rsb r10, r10, r1
 *   @0x31b734 mov r1, r5
 *   @0x31b738 uxth r7, r7
 *   @0x31b73c mov r0, r10
 *   @0x31b740 bl 0x318c48 <__udivsi3>
 *   @0x31b744 mov r1, r5
 *   @0x31b748 mov r6, r0
 *   @0x31b74c mul r9, r9, r0
 *   @0x31b750 mov r0, r10
 *   @0x31b754 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b758 orr r1, r7, r1, lsl #16
 *   @0x31b75c cmp r1, r9
 *   @0x31b760 movhs r0, r6
 *   @0x31b764 bhs 0x31b77c <__udivdi3+0xe4>
 *   @0x31b768 adds r4, r1, r4
 *   @0x31b76c sub r0, r6, #1
 *   @0x31b770 bhs 0x31b77c <__udivdi3+0xe4>
 *   @0x31b774 cmp r4, r9
 *   @0x31b778 sublo r0, r6, #2
 *   @0x31b77c orr r0, r0, r8, lsl #16
 *   @0x31b780 b 0x31ba60 <__udivdi3+0x3c8>
 *   @0x31b784 cmp r2, #0
 *   @0x31b788 bne 0x31b79c <__udivdi3+0x104>
 *   @0x31b78c mov r0, #1
 *   @0x31b790 mov r1, r2
 *   @0x31b794 bl 0x318c48 <__udivsi3>
 *   @0x31b798 mov r4, r0
 *   @0x31b79c clz r3, r4
 *   @0x31b7a0 cmp r3, #0
 *   @0x31b7a4 rsbeq r10, r4, r5
 *   @0x31b7a8 moveq r5, #1
 *   @0x31b7ac beq 0x31b874 <__udivdi3+0x1dc>
 *   @0x31b7b0 lsl r4, r4, r3
 *   @0x31b7b4 rsb r9, r3, #32
 *   @0x31b7b8 lsr r11, r5, r9
 *   @0x31b7bc lsl r7, r6, r3
 *   @0x31b7c0 lsr r9, r6, r9
 *   @0x31b7c4 lsr r6, r4, #16
 *   @0x31b7c8 mov r0, r11
 *   @0x31b7cc orr r9, r9, r5, lsl r3
 *   @0x31b7d0 mov r1, r6
 *   @0x31b7d4 uxth r10, r4
 *   @0x31b7d8 bl 0x318c48 <__udivsi3>
 *   @0x31b7dc mov r1, r6
 *   @0x31b7e0 mov r8, r0
 *   @0x31b7e4 mul r5, r10, r0
 *   @0x31b7e8 mov r0, r11
 *   @0x31b7ec bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b7f0 lsr r3, r9, #16
 *   @0x31b7f4 orr r1, r3, r1, lsl #16
 *   @0x31b7f8 cmp r1, r5
 *   @0x31b7fc movhs r11, r8
 *   @0x31b800 bhs 0x31b81c <__udivdi3+0x184>
 *   @0x31b804 adds r1, r1, r4
 *   @0x31b808 sub r11, r8, #1
 *   @0x31b80c bhs 0x31b81c <__udivdi3+0x184>
 *   @0x31b810 cmp r1, r5
 *   @0x31b814 sublo r11, r8, #2
 *   @0x31b818 addlo r1, r1, r4
 *   @0x31b81c rsb r5, r5, r1
 *   @0x31b820 mov r1, r6
 *   @0x31b824 uxth r9, r9
 *   @0x31b828 mov r0, r5
 *   @0x31b82c bl 0x318c48 <__udivsi3>
 *   @0x31b830 mov r1, r6
 *   @0x31b834 mov r8, r0
 *   @0x31b838 mul r10, r10, r0
 *   @0x31b83c mov r0, r5
 *   @0x31b840 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b844 orr r1, r9, r1, lsl #16
 *   @0x31b848 cmp r1, r10
 *   @0x31b84c movhs r5, r8
 *   @0x31b850 bhs 0x31b86c <__udivdi3+0x1d4>
 *   @0x31b854 adds r1, r1, r4
 *   @0x31b858 sub r5, r8, #1
 *   @0x31b85c bhs 0x31b86c <__udivdi3+0x1d4>
 *   @0x31b860 cmp r1, r10
 *   @0x31b864 sublo r5, r8, #2
 *   @0x31b868 addlo r1, r1, r4
 *   @0x31b86c rsb r10, r10, r1
 *   @0x31b870 orr r5, r5, r11, lsl #16
 *   @0x31b874 lsr r6, r4, #16
 *   @0x31b878 mov r0, r10
 *   @0x31b87c uxth r9, r4
 *   @0x31b880 mov r1, r6
 *   @0x31b884 bl 0x318c48 <__udivsi3>
 *   @0x31b888 mov r1, r6
 *   @0x31b88c mov r8, r0
 *   @0x31b890 mul r11, r9, r0
 *   @0x31b894 mov r0, r10
 *   @0x31b898 bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b89c lsr r3, r7, #16
 *   @0x31b8a0 orr r1, r3, r1, lsl #16
 *   @0x31b8a4 cmp r1, r11
 *   @0x31b8a8 movhs r10, r8
 *   @0x31b8ac bhs 0x31b8c8 <__udivdi3+0x230>
 *   @0x31b8b0 adds r1, r1, r4
 *   @0x31b8b4 sub r10, r8, #1
 *   @0x31b8b8 bhs 0x31b8c8 <__udivdi3+0x230>
 *   @0x31b8bc cmp r1, r11
 *   @0x31b8c0 sublo r10, r8, #2
 *   @0x31b8c4 addlo r1, r1, r4
 *   @0x31b8c8 rsb r11, r11, r1
 *   @0x31b8cc mov r1, r6
 *   @0x31b8d0 uxth r7, r7
 *   @0x31b8d4 mov r0, r11
 *   @0x31b8d8 bl 0x318c48 <__udivsi3>
 *   @0x31b8dc mov r1, r6
 *   @0x31b8e0 mov r8, r0
 *   @0x31b8e4 mul r9, r9, r0
 *   @0x31b8e8 mov r0, r11
 *   @0x31b8ec bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b8f0 orr r1, r7, r1, lsl #16
 *   @0x31b8f4 cmp r1, r9
 *   @0x31b8f8 movhs r0, r8
 *   @0x31b8fc bhs 0x31b914 <__udivdi3+0x27c>
 *   @0x31b900 adds r4, r1, r4
 *   @0x31b904 sub r0, r8, #1
 *   @0x31b908 bhs 0x31b914 <__udivdi3+0x27c>
 *   @0x31b90c cmp r4, r9
 *   @0x31b910 sublo r0, r8, #2
 *   @0x31b914 orr r0, r0, r10, lsl #16
 *   @0x31b918 b 0x31ba70 <__udivdi3+0x3d8>
 *   @0x31b91c cmp r3, r1
 *   @0x31b920 bhi 0x31ba68 <__udivdi3+0x3d0>
 *   @0x31b924 clz r7, r3
 *   @0x31b928 cmp r7, #0
 *   @0x31b92c bne 0x31b950 <__udivdi3+0x2b8>
 *   @0x31b930 cmp r1, r3
 *   @0x31b934 cmpls r0, r2
 *   @0x31b938 movlo r5, #0
 *   @0x31b93c movhs r5, #1
 *   @0x31b940 movhs r0, #1
 *   @0x31b944 movhs r5, r7
 *   @0x31b948 bhs 0x31ba70 <__udivdi3+0x3d8>
 *   @0x31b94c b 0x31ba6c <__udivdi3+0x3d4>
 *   @0x31b950 rsb r1, r7, #32
 *   @0x31b954 lsl r8, r2, r7
 *   @0x31b958 lsr r4, r2, r1
 *   @0x31b95c orr r4, r4, r3, lsl r7
 *   @0x31b960 lsr r3, r5, r1
 *   @0x31b964 lsr r1, r0, r1
 *   @0x31b968 str r3, [sp]
 *   @0x31b96c lsr r9, r4, #16
 *   @0x31b970 orr r5, r1, r5, lsl r7
 *   @0x31b974 mov r0, r3
 *   @0x31b978 uxth r10, r4
 *   @0x31b97c mov r1, r9
 *   @0x31b980 bl 0x318c48 <__udivsi3>
 *   @0x31b984 ldr r3, [sp]
 *   @0x31b988 mov r1, r9
 *   @0x31b98c mul r2, r10, r0
 *   @0x31b990 mov r11, r0
 *   @0x31b994 mov r0, r3
 *   @0x31b998 str r2, [sp, #0x4]
 *   @0x31b99c bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31b9a0 lsr r12, r5, #16
 *   @0x31b9a4 ldr r2, [sp, #0x4]
 *   @0x31b9a8 orr r1, r12, r1, lsl #16
 *   @0x31b9ac cmp r1, r2
 *   @0x31b9b0 movhs r3, r11
 *   @0x31b9b4 bhs 0x31b9d0 <__udivdi3+0x338>
 *   @0x31b9b8 adds r1, r1, r4
 *   @0x31b9bc sub r3, r11, #1
 *   @0x31b9c0 bhs 0x31b9d0 <__udivdi3+0x338>
 *   @0x31b9c4 cmp r1, r2
 *   @0x31b9c8 sublo r3, r11, #2
 *   @0x31b9cc addlo r1, r1, r4
 *   @0x31b9d0 rsb r12, r2, r1
 *   @0x31b9d4 mov r1, r9
 *   @0x31b9d8 stm sp, {r3, r12}
 *   @0x31b9dc uxth r5, r5
 *   @0x31b9e0 mov r0, r12
 *   @0x31b9e4 bl 0x318c48 <__udivsi3>
 *   @0x31b9e8 ldr r12, [sp, #0x4]
 *   @0x31b9ec mov r1, r9
 *   @0x31b9f0 mov r11, r0
 *   @0x31b9f4 mul r10, r10, r0
 *   @0x31b9f8 mov r0, r12
 *   @0x31b9fc bl 0x318cf0 <__aeabi_uidivmod>
 *   @0x31ba00 ldr r3, [sp]
 *   @0x31ba04 orr r1, r5, r1, lsl #16
 *   @0x31ba08 cmp r1, r10
 *   @0x31ba0c movhs r0, r11
 *   @0x31ba10 bhs 0x31ba2c <__udivdi3+0x394>
 *   @0x31ba14 adds r1, r1, r4
 *   @0x31ba18 sub r0, r11, #1
 *   @0x31ba1c bhs 0x31ba2c <__udivdi3+0x394>
 *   @0x31ba20 cmp r1, r10
 *   @0x31ba24 sublo r0, r11, #2
 *   @0x31ba28 addlo r1, r1, r4
 *   @0x31ba2c orr r0, r0, r3, lsl #16
 *   @0x31ba30 rsb r10, r10, r1
 *   @0x31ba34 umull r2, r3, r0, r8
 *   @0x31ba38 cmp r3, r10
 *   @0x31ba3c bhi 0x31ba5c <__udivdi3+0x3c4>
 *   @0x31ba40 movne r5, #0
 *   @0x31ba44 moveq r5, #1
 *   @0x31ba48 cmp r2, r6, lsl r7
 *   @0x31ba4c movls r5, #0
 *   @0x31ba50 andhi r5, r5, #1
 *   @0x31ba54 cmp r5, #0
 *   @0x31ba58 beq 0x31ba70 <__udivdi3+0x3d8>
 *   @0x31ba5c sub r0, r0, #1
 *   @0x31ba60 mov r5, #0
 *   @0x31ba64 b 0x31ba70 <__udivdi3+0x3d8>
 *   @0x31ba68 mov r5, #0
 *   @0x31ba6c mov r0, r5
 *   @0x31ba70 mov r1, r5
 *   @0x31ba74 add sp, sp, #12
 *   @0x31ba78 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §30/31 Sound_Tick()  0x21f17c  size 148  30 条（0x21f17c..0x21f210）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x21f198 0x21f210  size 120  30 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x21f184→0x755363, 0x21f19c→0x757e7c, 0x21f1d4→0x757e80, 0x21f1e4→0x757e80
 * 调用序列: SoundHardware::Tick() / Audio_Tick() / CProfiler::Push(int, int)
 * 字段偏移 top8: 0x74×2 / 0x60×1 / 0x50×1 / 0x30×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x21f198 popne {r3, r4, r5, pc}
 *   @0x21f19c ldr r3, [pc, #0x60]
 *   @0x21f1a0 ldr r5, [r4, r3]
 *   @0x21f1a4 ldrb r3, [r5]
 *   @0x21f1a8 cmp r3, #0
 *   @0x21f1ac bne 0x21f1e4 <_Z10Sound_Tickv+0x68>
 *   @0x21f1b0 ldr r3, [pc, #0x50]
 *   @0x21f1b4 ldr r0, [pc, r3]
 *   @0x21f1b8 cmp r0, #0
 *   @0x21f1bc beq 0x21f1c4 <_Z10Sound_Tickv+0x48>
 *   @0x21f1c0 bl 0x221134 <_ZN13SoundHardware4TickEv>
 *   @0x21f1c4 bl 0x21bc30 <_Z10Audio_Tickv>
 *   @0x21f1c8 ldrb r3, [r5]
 *   @0x21f1cc cmp r3, #0
 *   @0x21f1d0 popeq {r3, r4, r5, pc}
 *   @0x21f1d4 ldr r3, [pc, #0x30]
 *   @0x21f1d8 ldr r0, [r4, r3]
 *   @0x21f1dc pop {r3, r4, r5, lr}
 *   @0x21f1e0 b 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x21f1e4 ldr r3, [pc, #0x20]
 *   @0x21f1e8 mov r1, #6
 *   @0x21f1ec mov r2, #17
 *   @0x21f1f0 ldr r0, [r4, r3]
 *   @0x21f1f4 bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x21f1f8 b 0x21f1b0 <_Z10Sound_Tickv+0x34>
 *   @0x21f1fc andseq r2, sp, r8, asr #21
 *   @0x21f200 .word 0xffffd3fc
 *   @0x21f204 .word 0xffffbf18
 *   @0x21f208 subseq r6, r3, r0, ror r1
 *   @0x21f20c .word 0xffffbf1c
 *
 * ══ §31/31 CBackground::GetBitmap24()  0xc2c34  size 16  4 条（0xc2c34..0xc2c44）
 * @func 0xc2c34 0xc2c44  size 16  4 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc2c34 ldr r0, [r0, #0x10]
 *   @0xc2c38 cmp r0, #0
 *   @0xc2c3c bxeq lr
 *   @0xc2c40 b 0x1675e8 <_ZN9CBitmap3214CreateBitmap24Ev>
 */
