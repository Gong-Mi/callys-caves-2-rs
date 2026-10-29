/* cally 逆向卡：All_28 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 23 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/23 vorbis_lsp_to_curve  0x2298ac  size 1400  350 条（0x2298ac..0x229e24）
 * @func 0x2298ac 0x229e24  size 1400  350 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: vorbis_lsp_to_curve+0x4ac×2 / vorbis_lsp_to_curve+0xec / vorbis_lsp_to_curve+0x4bc / vorbis_lsp_to_curve+0x53c / vorbis_lsp_to_curve+0x288 / 0xb65b0 / 0xb65d4
 * 字段偏移 top8: 0x8×8 / 0x-34×6 / 0x-44×4 / 0x-30×4 / 0x4×3 / 0x-40×3 / 0x-3c×3 / 0x2×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2298ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2298b0 add r11, sp, #32
 *   @0x2298b4 sub sp, sp, #84
 *   @0x2298b8 ldr r3, [pc, #0x550]
 *   @0x2298bc str r2, [r11, #-0x44]
 *   @0x2298c0 ldr r4, [r11, #0x8]
 *   @0x2298c4 ldr r3, [pc, r3]
 *   @0x2298c8 ldr r5, [r11, #0x14]
 *   @0x2298cc mov r8, r1
 *   @0x2298d0 str r3, [r11, #-0x48]
 *   @0x2298d4 cmp r4, #0
 *   @0x2298d8 lsl r2, r4, #2
 *   @0x2298dc ldr r3, [r3]
 *   @0x2298e0 add r2, r2, #14
 *   @0x2298e4 ldr r6, [r11, #0x4]
 *   @0x2298e8 bic r2, r2, #7
 *   @0x2298ec str r5, [r11, #-0x50]
 *   @0x2298f0 sub sp, sp, r2
 *   @0x2298f4 str r3, [r11, #-0x28]
 *   @0x2298f8 str sp, [r11, #-0x34]
 *   @0x2298fc ble 0x229998 <vorbis_lsp_to_curve+0xec>
 *   @0x229900 ldr r2, [r6]
 *   @0x229904 movw r7, #0x7cc2
 *   @0x229908 movt r7, #0x51
 *   @0x22990c smull r2, r3, r2, r7
 *   @0x229910 cmp r3, #0
 *   @0x229914 mov r5, r3
 *   @0x229918 blt 0x229d58 <vorbis_lsp_to_curve+0x4ac>
 *   @0x22991c asr r3, r3, #9
 *   @0x229920 cmp r3, #127
 *   @0x229924 bgt 0x229d58 <vorbis_lsp_to_curve+0x4ac>
 *   @0x229928 ldr r4, [pc, #0x4e4]
 *   @0x22992c mov r12, #0
 *   @0x229930 mov r1, r12
 *   @0x229934 ldr r9, [r11, #-0x34]
 *   @0x229938 add r4, pc, r4
 *   @0x22993c ldr r10, [r11, #0x8]
 *   @0x229940 b 0x229968 <vorbis_lsp_to_curve+0xbc>
 *   @0x229944 ldr r2, [r6, #0x4]!
 *   @0x229948 lsl r12, r1, #2
 *   @0x22994c smull r2, r3, r2, r7
 *   @0x229950 cmp r3, #0
 *   @0x229954 mov r5, r3
 *   @0x229958 blt 0x229d58 <vorbis_lsp_to_curve+0x4ac>
 *   @0x22995c asr r3, r3, #9
 *   @0x229960 cmp r3, #127
 *   @0x229964 bgt 0x229d58 <vorbis_lsp_to_curve+0x4ac>
 *   @0x229968 add r2, r4, r3, lsl #2
 *   @0x22996c ubfx r5, r5, #0x0, #0x9
 *   @0x229970 add r1, r1, #1
 *   @0x229974 mov r3, r2
 *   @0x229978 ldr r2, [r2, #0x70]
 *   @0x22997c ldr r3, [r3, #0x74]
 *   @0x229980 cmp r1, r10
 *   @0x229984 rsb r3, r3, r2
 *   @0x229988 mul r5, r3, r5
 *   @0x22998c sub r2, r2, r5, asr #9
 *   @0x229990 str r2, [r9, r12]
 *   @0x229994 bne 0x229944 <vorbis_lsp_to_curve+0x98>
 *   @0x229998 ldr r6, [r11, #-0x44]
 *   @0x22999c cmp r6, #0
 *   @0x2299a0 ble 0x229d68 <vorbis_lsp_to_curve+0x4bc>
 *   @0x2299a4 ldr r12, [r11, #0x8]
 *   @0x2299a8 mov r10, #0
 *   @0x2299ac ldr r2, [pc, #0x464]
 *   @0x2299b0 mov r9, r8
 *   @0x2299b4 add r1, r12, #1
 *   @0x2299b8 sub r3, r12, #4
 *   @0x2299bc ldr r7, [r11, #-0x34]
 *   @0x2299c0 add r2, pc, r2
 *   @0x2299c4 asr r1, r1, #1
 *   @0x2299c8 lsr r3, r3, #1
 *   @0x2299cc str r2, [r11, #-0x40]
 *   @0x2299d0 and r4, r12, #1
 *   @0x2299d4 sub r1, r1, r1, lsl #3
 *   @0x2299d8 add r2, r7, r3, lsl #3
 *   @0x2299dc add r2, r2, #8
 *   @0x2299e0 str r2, [r11, #-0x60]
 *   @0x2299e4 lsl r1, r1, #1
 *   @0x2299e8 ldr r2, [r11, #-0x40]
 *   @0x2299ec str r1, [r11, #-0x70]
 *   @0x2299f0 sub r6, r12, r12, lsl #3
 *   @0x2299f4 ldr r1, [r11, #0x10]
 *   @0x2299f8 lsl r3, r3, #1
 *   @0x2299fc ldr r5, [pc, #0x418]
 *   @0x229a00 add r3, r3, #5
 *   @0x229a04 ldr r12, [pc, #0x414]
 *   @0x229a08 add r5, pc, r5
 *   @0x229a0c lsl r1, r1, #12
 *   @0x229a10 add r12, pc, r12
 *   @0x229a14 str r4, [r11, #-0x58]
 *   @0x229a18 str r5, [r11, #-0x68]
 *   @0x229a1c str r6, [r11, #-0x6c]
 *   @0x229a20 str r12, [r11, #-0x5c]
 *   @0x229a24 str r3, [r11, #-0x64]
 *   @0x229a28 str r1, [r11, #-0x54]
 *   @0x229a2c str r2, [r11, #-0x3c]
 *   @0x229a30 ldr r4, [r11, #0x8]
 *   @0x229a34 lsl r8, r10, #2
 *   @0x229a38 ldr r3, [r9, r10, lsl #2]
 *   @0x229a3c ldr r5, [r11, #-0x50]
 *   @0x229a40 cmp r4, #1
 *   @0x229a44 str r3, [r11, #-0x38]
 *   @0x229a48 ldr r4, [r5, r3, lsl #2]
 *   @0x229a4c ble 0x229de8 <vorbis_lsp_to_curve+0x53c>
 *   @0x229a50 ldr r6, [r11, #-0x34]
 *   @0x229a54 movw r2, #0xb505
 *   @0x229a58 ldr r7, [r11, #0x8]
 *   @0x229a5c ldm r6, {r1, r12}
 *   @0x229a60 rsb r1, r4, r1
 *   @0x229a64 rsb r12, r4, r12
 *   @0x229a68 cmp r1, #0
 *   @0x229a6c rsblt r1, r1, #0
 *   @0x229a70 cmp r12, #0
 *   @0x229a74 rsblt r12, r12, #0
 *   @0x229a78 cmp r7, #3
 *   @0x229a7c mul r1, r2, r1
 *   @0x229a80 movle r5, #0
 *   @0x229a84 mul r12, r2, r12
 *   @0x229a88 movle r6, #3
 *   @0x229a8c orrle r2, r12, r1
 *   @0x229a90 lsrle r3, r2, #25
 *   @0x229a94 ble 0x229b34 <vorbis_lsp_to_curve+0x288>
 *   @0x229a98 ldr r2, [r11, #-0x34]
 *   @0x229a9c mov r5, #0
 *   @0x229aa0 ldr r7, [r11, #-0x60]
 *   @0x229aa4 ldr r6, [r11, #-0x68]
 *   @0x229aa8 str r10, [r11, #-0x4c]
 *   @0x229aac mov r10, r0
 *   @0x229ab0 str r8, [r11, #-0x30]
 *   @0x229ab4 orr r0, r12, r1
 *   @0x229ab8 add r3, r6, r0, lsr #25
 *   @0x229abc ldrb r3, [r3, #0x274]
 *   @0x229ac0 cmp r3, #0
 *   @0x229ac4 bne 0x229adc <vorbis_lsp_to_curve+0x230>
 *   @0x229ac8 add r3, r6, r0, lsr #19
 *   @0x229acc ldrb r3, [r3, #0x2b4]
 *   @0x229ad0 cmp r3, #0
 *   @0x229ad4 addeq r0, r6, r0, lsr #16
 *   @0x229ad8 ldrbeq r3, [r0, #0x2f4]
 *   @0x229adc ldr r8, [r2, #0x8]
 *   @0x229ae0 add r2, r2, #8
 *   @0x229ae4 ldr r0, [r2, #0x4]
 *   @0x229ae8 lsr r1, r1, r3
 *   @0x229aec rsb r8, r4, r8
 *   @0x229af0 lsr r12, r12, r3
 *   @0x229af4 rsb r0, r4, r0
 *   @0x229af8 cmp r8, #0
 *   @0x229afc rsblt r8, r8, #0
 *   @0x229b00 cmp r0, #0
 *   @0x229b04 rsblt r0, r0, #0
 *   @0x229b08 cmp r2, r7
 *   @0x229b0c add r5, r5, r3
 *   @0x229b10 mul r1, r8, r1
 *   @0x229b14 mul r12, r0, r12
 *   @0x229b18 bne 0x229ab4 <vorbis_lsp_to_curve+0x208>
 *   @0x229b1c orr r2, r1, r12
 *   @0x229b20 mov r0, r10
 *   @0x229b24 ldr r8, [r11, #-0x30]
 *   @0x229b28 ldr r10, [r11, #-0x4c]
 *   @0x229b2c lsr r3, r2, #25
 *   @0x229b30 ldr r6, [r11, #-0x64]
 *   @0x229b34 ldr r7, [r11, #-0x40]
 *   @0x229b38 add r3, r7, r3
 *   @0x229b3c ldrb r3, [r3, #0x274]
 *   @0x229b40 cmp r3, #0
 *   @0x229b44 bne 0x229b5c <vorbis_lsp_to_curve+0x2b0>
 *   @0x229b48 add r3, r7, r2, lsr #19
 *   @0x229b4c ldrb r3, [r3, #0x2b4]
 *   @0x229b50 cmp r3, #0
 *   @0x229b54 addeq r2, r7, r2, lsr #16
 *   @0x229b58 ldrbeq r3, [r2, #0x2f4]
 *   @0x229b5c ldr r2, [r11, #-0x58]
 *   @0x229b60 cmp r2, #0
 *   @0x229b64 beq 0x229d98 <vorbis_lsp_to_curve+0x4ec>
 *   @0x229b68 lsr r1, r1, r3
 *   @0x229b6c lsr r12, r12, r3
 *   @0x229b70 add r3, r5, r3
 *   @0x229b74 ldr r5, [r11, #-0x34]
 *   @0x229b78 sub r6, r6, #-1073741823
 *   @0x229b7c lsl r12, r12, #14
 *   @0x229b80 ldr r2, [r5, r6, lsl #2]
 *   @0x229b84 ldr r6, [r11, #-0x5c]
 *   @0x229b88 rsb r2, r4, r2
 *   @0x229b8c cmp r2, #0
 *   @0x229b90 rsblt r2, r2, #0
 *   @0x229b94 mul r1, r2, r1
 *   @0x229b98 orr r5, r12, r1
 *   @0x229b9c add r2, r6, r5, lsr #25
 *   @0x229ba0 ldrb r2, [r2, #0x274]
 *   @0x229ba4 cmp r2, #0
 *   @0x229ba8 bne 0x229bc0 <vorbis_lsp_to_curve+0x314>
 *   @0x229bac add r2, r6, r5, lsr #19
 *   @0x229bb0 ldrb r2, [r2, #0x2b4]
 *   @0x229bb4 cmp r2, #0
 *   @0x229bb8 addeq r5, r6, r5, lsr #16
 *   @0x229bbc ldrbeq r2, [r5, #0x2f4]
 *   @0x229bc0 lsr r12, r12, r2
 *   @0x229bc4 lsr r1, r1, r2
 *   @0x229bc8 mul r4, r4, r4
 *   @0x229bcc ldr r7, [r11, #-0x70]
 *   @0x229bd0 mul r12, r12, r12
 *   @0x229bd4 add r2, r7, r2
 *   @0x229bd8 mul r1, r1, r1
 *   @0x229bdc add r3, r2, r3
 *   @0x229be0 asr r4, r4, #14
 *   @0x229be4 ldr r5, [r11, #0x8]
 *   @0x229be8 rsb r4, r4, #16384
 *   @0x229bec lsr r12, r12, #16
 *   @0x229bf0 add r3, r5, r3, lsl #1
 *   @0x229bf4 mul r12, r4, r12
 *   @0x229bf8 lsr r12, r12, #14
 *   @0x229bfc add r1, r12, r1, lsr #16
 *   @0x229c00 lsrs r12, r1, #16
 *   @0x229c04 bne 0x229d84 <vorbis_lsp_to_curve+0x4d8>
 *   @0x229c08 cmp r1, #0
 *   @0x229c0c bne 0x229c20 <vorbis_lsp_to_curve+0x374>
 *   @0x229c10 b 0x229e04 <vorbis_lsp_to_curve+0x558>
 *   @0x229c14 lsls r1, r1, #1
 *   @0x229c18 sub r3, r3, #1
 *   @0x229c1c beq 0x229e04 <vorbis_lsp_to_curve+0x558>
 *   @0x229c20 tst r1, #32768
 *   @0x229c24 beq 0x229c14 <vorbis_lsp_to_curve+0x368>
 *   @0x229c28 ubfx r2, r1, #0x9, #0x6
 *   @0x229c2c ubfx r1, r1, #0x0, #0xa
 *   @0x229c30 ldr r4, [r11, #-0x3c]
 *   @0x229c34 ldr r5, [r11, #-0x3c]
 *   @0x229c38 add r2, r4, r2, lsl #2
 *   @0x229c3c and r4, r3, #1
 *   @0x229c40 asr r3, r3, #1
 *   @0x229c44 ldr r6, [r11, #0xc]
 *   @0x229c48 ldr r12, [r2, #0x400]
 *   @0x229c4c add r4, r5, r4, lsl #2
 *   @0x229c50 ldr r2, [r2, #0x2fc]
 *   @0x229c54 add r3, r3, #21
 *   @0x229c58 ldr r4, [r4, #0x500]
 *   @0x229c5c mul r1, r12, r1
 *   @0x229c60 ldr r7, [r11, #-0x54]
 *   @0x229c64 sub r1, r2, r1, asr #10
 *   @0x229c68 mul r1, r4, r1
 *   @0x229c6c asr r3, r1, r3
 *   @0x229c70 mls r3, r3, r6, r7
 *   @0x229c74 asrs r2, r3, #9
 *   @0x229c78 bmi 0x229ddc <vorbis_lsp_to_curve+0x530>
 *   @0x229c7c cmp r2, #1120
 *   @0x229c80 movge r2, #0
 *   @0x229c84 movge r3, #0
 *   @0x229c88 bge 0x229cac <vorbis_lsp_to_curve+0x400>
 *   @0x229c8c asr r3, r3, #14
 *   @0x229c90 and r2, r2, #31
 *   @0x229c94 add r3, r5, r3, lsl #2
 *   @0x229c98 add r2, r5, r2, lsl #2
 *   @0x229c9c ldr r3, [r3, #0x508]
 *   @0x229ca0 ldr r2, [r2, #0x594]
 *   @0x229ca4 mul r2, r2, r3
 *   @0x229ca8 asr r3, r2, #31
 *   @0x229cac ldr r4, [r0, r8]
 *   @0x229cb0 add r1, r8, #4
 *   @0x229cb4 add r10, r10, #1
 *   @0x229cb8 asr r7, r4, #31
 *   @0x229cbc mul r12, r4, r3
 *   @0x229cc0 umull r4, r5, r4, r2
 *   @0x229cc4 mla r12, r2, r7, r12
 *   @0x229cc8 add r12, r12, r5
 *   @0x229ccc lsr r4, r4, #15
 *   @0x229cd0 orr r12, r4, r12, lsl #17
 *   @0x229cd4 ldr r4, [r11, #-0x38]
 *   @0x229cd8 str r12, [r0, r8]
 *   @0x229cdc ldr r12, [r9, r1]
 *   @0x229ce0 cmp r12, r4
 *   @0x229ce4 str r12, [r11, #-0x30]
 *   @0x229ce8 bne 0x229d48 <vorbis_lsp_to_curve+0x49c>
 *   @0x229cec add r12, r8, #8
 *   @0x229cf0 mov r7, r9
 *   @0x229cf4 mov r8, r2
 *   @0x229cf8 mov r9, r3
 *   @0x229cfc b 0x229d08 <vorbis_lsp_to_curve+0x45c>
 *   @0x229d00 mov r1, r12
 *   @0x229d04 mov r12, r6
 *   @0x229d08 ldr r2, [r0, r1]
 *   @0x229d0c add r10, r10, #1
 *   @0x229d10 add r6, r12, #4
 *   @0x229d14 asr r5, r2, #31
 *   @0x229d18 mul r4, r2, r9
 *   @0x229d1c umull r2, r3, r2, r8
 *   @0x229d20 mla r4, r8, r5, r4
 *   @0x229d24 ldr r5, [r11, #-0x30]
 *   @0x229d28 add r4, r4, r3
 *   @0x229d2c lsr r2, r2, #15
 *   @0x229d30 orr r2, r2, r4, lsl #17
 *   @0x229d34 str r2, [r0, r1]
 *   @0x229d38 ldr r3, [r7, r12]
 *   @0x229d3c cmp r3, r5
 *   @0x229d40 beq 0x229d00 <vorbis_lsp_to_curve+0x454>
 *   @0x229d44 mov r9, r7
 *   @0x229d48 ldr r6, [r11, #-0x44]
 *   @0x229d4c cmp r6, r10
 *   @0x229d50 bgt 0x229a30 <vorbis_lsp_to_curve+0x184>
 *   @0x229d54 b 0x229d68 <vorbis_lsp_to_curve+0x4bc>
 *   @0x229d58 ldr r7, [r11, #-0x44]
 *   @0x229d5c mov r1, #0
 *   @0x229d60 lsl r2, r7, #2
 *   @0x229d64 bl 0xb65b0 <memset@plt>
 *   @0x229d68 ldr r7, [r11, #-0x48]
 *   @0x229d6c ldr r2, [r11, #-0x28]
 *   @0x229d70 ldr r3, [r7]
 *   @0x229d74 cmp r2, r3
 *   @0x229d78 bne 0x229e0c <vorbis_lsp_to_curve+0x560>
 *   @0x229d7c sub sp, r11, #32
 *   @0x229d80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x229d84 lsr r1, r1, #1
 *   @0x229d88 add r3, r3, #1
 *   @0x229d8c ubfx r2, r1, #0x9, #0x6
 *   @0x229d90 ubfx r1, r1, #0x0, #0xa
 *   @0x229d94 b 0x229c30 <vorbis_lsp_to_curve+0x384>
 *   @0x229d98 lsr r12, r12, r3
 *   @0x229d9c lsr r1, r1, r3
 *   @0x229da0 rsb r2, r4, #16384
 *   @0x229da4 add r4, r4, #16384
 *   @0x229da8 mul r12, r12, r12
 *   @0x229dac ldr r6, [r11, #-0x6c]
 *   @0x229db0 mul r1, r1, r1
 *   @0x229db4 add r3, r6, r3
 *   @0x229db8 add r3, r3, r5
 *   @0x229dbc ldr r7, [r11, #0x8]
 *   @0x229dc0 lsr r12, r12, #16
 *   @0x229dc4 add r3, r7, r3, lsl #1
 *   @0x229dc8 lsr r1, r1, #16
 *   @0x229dcc mul r12, r2, r12
 *   @0x229dd0 mla r1, r4, r1, r12
 *   @0x229dd4 lsr r1, r1, #14
 *   @0x229dd8 b 0x229c00 <vorbis_lsp_to_curve+0x354>
 *   @0x229ddc mvn r2, #-2147483648
 *   @0x229de0 mov r3, #0
 *   @0x229de4 b 0x229cac <vorbis_lsp_to_curve+0x400>
 *   @0x229de8 movw r2, #0xb505
 *   @0x229dec mov r3, #0
 *   @0x229df0 mov r5, r3
 *   @0x229df4 mov r1, r2
 *   @0x229df8 mov r12, r2
 *   @0x229dfc mov r6, #1
 *   @0x229e00 b 0x229b34 <vorbis_lsp_to_curve+0x288>
 *   @0x229e04 mov r2, r1
 *   @0x229e08 b 0x229c30 <vorbis_lsp_to_curve+0x384>
 *   @0x229e0c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x229e10 andseq r4, r12, r12, lsl #1
 *   @0x229e14 andseq r4, r3, r4, asr r7
 *   @0x229e18 andseq r4, r3, r12, asr #13
 *   @0x229e1c andseq r4, r3, r4, lsl #13
 *   @0x229e20 andseq r4, r3, r12, ror r6
 *
 * ══ §2/23 JS_MathObjectSetup()  0x243680  size 1392  348 条（0x243680..0x243bf0）
 * @func 0x243680 0x243bf0  size 1392  348 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2436ac→0x756450, 0x243b0c→0x544be0
 * 调用序列: YYObjectBase::Add(char const*, YYObjectBase*, int)×19 / JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×18 / YYObjectBase::Add(char const*, double, int)×8 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x488×1 / 0x8×1 / 0x480×1 / 0x47c×1 / 0x40×1 / 0x18×1 / 0x460×1 / 0x440×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x243680 push {r4, r5, r6, r7, lr}
 *   @0x243684 sub sp, sp, #28
 *   @0x243688 mov r4, #0
 *   @0x24368c add r0, sp, #8
 *   @0x243690 mov r2, r4
 *   @0x243694 mov r1, r4
 *   @0x243698 mov r3, r4
 *   @0x24369c str r4, [sp]
 *   @0x2436a0 ldr r6, [pc, #0x488]
 *   @0x2436a4 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x2436a8 ldr r5, [sp, #0x8]
 *   @0x2436ac ldr r3, [pc, #0x480]
 *   @0x2436b0 add r6, pc, r6
 *   @0x2436b4 ldr r7, [pc, #0x47c]
 *   @0x2436b8 mov r0, r5
 *   @0x2436bc add r7, pc, r7
 *   @0x2436c0 str r7, [r5, #0x40]
 *   @0x2436c4 ldr r3, [r6, r3]
 *   @0x2436c8 ldr r1, [r3]
 *   @0x2436cc str r1, [r5, #0x18]
 *   @0x2436d0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2436d4 ldr r1, [pc, #0x460]
 *   @0x2436d8 mov r0, r5
 *   @0x2436dc str r4, [sp]
 *   @0x2436e0 add r1, pc, r1
 *   @0x2436e4 movw r2, #0x5769
 *   @0x2436e8 movw r3, #0xbf0a
 *   @0x2436ec movt r2, #0x8b14
 *   @0x2436f0 movt r3, #0x4005
 *   @0x2436f4 bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi>
 *   @0x2436f8 ldr r1, [pc, #0x440]
 *   @0x2436fc mov r0, r5
 *   @0x243700 str r4, [sp]
 *   @0x243704 add r1, pc, r1
 *   @0x243708 movw r2, #0x5516
 *   @0x24370c movw r3, #0x6bb1
 *   @0x243710 movt r2, #0xbbb5
 *   @0x243714 movt r3, #0x4002
 *   @0x243718 bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi>
 *   @0x24371c ldr r1, [pc, #0x420]
 *   @0x243720 mov r0, r5
 *   @0x243724 str r4, [sp]
 *   @0x243728 add r1, pc, r1
 *   @0x24372c movw r2, #0x39ef
 *   @0x243730 movw r3, #0x2e42
 *   @0x243734 movt r2, #0xfefa
 *   @0x243738 movt r3, #0x3fe6
 *   @0x24373c bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi>
 *   @0x243740 ldr r1, [pc, #0x400]
 *   @0x243744 mov r0, r5
 *   @0x243748 str r4, [sp]
 *   @0x24374c add r1, pc, r1
 *   @0x243750 movw r2, #0x82fe
 *   @0x243754 movw r3, #0x1547
 *   @0x243758 movt r2, #0x652b
 *   @0x24375c movt r3, #0x3ff7
 *   @0x243760 bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi>
 *   @0x243764 ldr r1, [pc, #0x3e0]
 *   @0x243768 mov r0, r5
 *   @0x24376c str r4, [sp]
 *   @0x243770 add r1, pc, r1
 *   @0x243774 movw r2, #0xe50e
 *   @0x243778 movw r3, #0xcb7b
 *   @0x24377c movt r2, #0x1526
 *   @0x243780 movt r3, #0x3fdb
 *   @0x243784 bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi>
 *   @0x243788 ldr r1, [pc, #0x3c0]
 *   @0x24378c mov r0, r5
 *   @0x243790 str r4, [sp]
 *   @0x243794 add r1, pc, r1
 *   @0x243798 movw r2, #0x2d18
 *   @0x24379c movw r3, #0x21fb
 *   @0x2437a0 movt r2, #0x5444
 *   @0x2437a4 movt r3, #0x4009
 *   @0x2437a8 bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi>
 *   @0x2437ac ldr r1, [pc, #0x3a0]
 *   @0x2437b0 mov r0, r5
 *   @0x2437b4 str r4, [sp]
 *   @0x2437b8 add r1, pc, r1
 *   @0x2437bc movw r2, #0x3bcd
 *   @0x2437c0 movw r3, #0xa09e
 *   @0x2437c4 movt r2, #0x667f
 *   @0x2437c8 movt r3, #0x3fe6
 *   @0x2437cc bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi>
 *   @0x2437d0 ldr r1, [pc, #0x380]
 *   @0x2437d4 mov r0, r5
 *   @0x2437d8 str r4, [sp]
 *   @0x2437dc add r1, pc, r1
 *   @0x2437e0 movw r2, #0x3bcd
 *   @0x2437e4 movw r3, #0xa09e
 *   @0x2437e8 movt r2, #0x667f
 *   @0x2437ec movt r3, #0x3ff6
 *   @0x2437f0 bl 0x1999d0 <_ZN12YYObjectBase3AddEPKcdi>
 *   @0x2437f4 ldr r3, [pc, #0x360]
 *   @0x2437f8 mov r1, r4
 *   @0x2437fc mov r2, r4
 *   @0x243800 ldr r0, [r6, r3]
 *   @0x243804 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243808 ldr r1, [pc, #0x350]
 *   @0x24380c mov r3, r4
 *   @0x243810 add r1, pc, r1
 *   @0x243814 mov r2, r0
 *   @0x243818 mov r0, r5
 *   @0x24381c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243820 ldr r3, [pc, #0x33c]
 *   @0x243824 mov r1, r4
 *   @0x243828 mov r2, r4
 *   @0x24382c ldr r0, [r6, r3]
 *   @0x243830 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243834 ldr r1, [pc, #0x32c]
 *   @0x243838 mov r3, r4
 *   @0x24383c add r1, pc, r1
 *   @0x243840 mov r2, r0
 *   @0x243844 mov r0, r5
 *   @0x243848 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x24384c ldr r3, [pc, #0x318]
 *   @0x243850 mov r1, r4
 *   @0x243854 mov r2, r4
 *   @0x243858 ldr r0, [r6, r3]
 *   @0x24385c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243860 ldr r1, [pc, #0x308]
 *   @0x243864 mov r3, r4
 *   @0x243868 add r1, pc, r1
 *   @0x24386c mov r2, r0
 *   @0x243870 mov r0, r5
 *   @0x243874 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243878 ldr r3, [pc, #0x2f4]
 *   @0x24387c mov r1, r4
 *   @0x243880 mov r2, r4
 *   @0x243884 ldr r0, [r6, r3]
 *   @0x243888 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24388c ldr r1, [pc, #0x2e4]
 *   @0x243890 mov r3, r4
 *   @0x243894 add r1, pc, r1
 *   @0x243898 mov r2, r0
 *   @0x24389c mov r0, r5
 *   @0x2438a0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2438a4 ldr r3, [pc, #0x2d0]
 *   @0x2438a8 mov r1, r4
 *   @0x2438ac mov r2, r4
 *   @0x2438b0 ldr r0, [r6, r3]
 *   @0x2438b4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2438b8 ldr r1, [pc, #0x2c0]
 *   @0x2438bc mov r3, r4
 *   @0x2438c0 add r1, pc, r1
 *   @0x2438c4 mov r2, r0
 *   @0x2438c8 mov r0, r5
 *   @0x2438cc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2438d0 ldr r3, [pc, #0x2ac]
 *   @0x2438d4 mov r1, r4
 *   @0x2438d8 mov r2, r4
 *   @0x2438dc ldr r0, [r6, r3]
 *   @0x2438e0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2438e4 ldr r1, [pc, #0x29c]
 *   @0x2438e8 mov r3, r4
 *   @0x2438ec add r1, pc, r1
 *   @0x2438f0 mov r2, r0
 *   @0x2438f4 mov r0, r5
 *   @0x2438f8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2438fc ldr r3, [pc, #0x288]
 *   @0x243900 mov r1, r4
 *   @0x243904 mov r2, r4
 *   @0x243908 ldr r0, [r6, r3]
 *   @0x24390c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243910 ldr r1, [pc, #0x278]
 *   @0x243914 mov r3, r4
 *   @0x243918 add r1, pc, r1
 *   @0x24391c mov r2, r0
 *   @0x243920 mov r0, r5
 *   @0x243924 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243928 ldr r3, [pc, #0x264]
 *   @0x24392c mov r1, r4
 *   @0x243930 mov r2, r4
 *   @0x243934 ldr r0, [r6, r3]
 *   @0x243938 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24393c ldr r1, [pc, #0x254]
 *   @0x243940 mov r3, r4
 *   @0x243944 add r1, pc, r1
 *   @0x243948 mov r2, r0
 *   @0x24394c mov r0, r5
 *   @0x243950 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243954 ldr r3, [pc, #0x240]
 *   @0x243958 mov r1, r4
 *   @0x24395c mov r2, r4
 *   @0x243960 ldr r0, [r6, r3]
 *   @0x243964 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243968 ldr r1, [pc, #0x230]
 *   @0x24396c mov r3, r4
 *   @0x243970 add r1, pc, r1
 *   @0x243974 mov r2, r0
 *   @0x243978 mov r0, r5
 *   @0x24397c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243980 ldr r3, [pc, #0x21c]
 *   @0x243984 mov r1, r4
 *   @0x243988 mov r2, r4
 *   @0x24398c ldr r0, [r6, r3]
 *   @0x243990 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243994 ldr r1, [pc, #0x20c]
 *   @0x243998 mov r3, r4
 *   @0x24399c add r1, pc, r1
 *   @0x2439a0 mov r2, r0
 *   @0x2439a4 mov r0, r5
 *   @0x2439a8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2439ac ldr r3, [pc, #0x1f8]
 *   @0x2439b0 mov r1, r4
 *   @0x2439b4 mov r2, r4
 *   @0x2439b8 ldr r0, [r6, r3]
 *   @0x2439bc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2439c0 ldr r1, [pc, #0x1e8]
 *   @0x2439c4 mov r3, r4
 *   @0x2439c8 add r1, pc, r1
 *   @0x2439cc mov r2, r0
 *   @0x2439d0 mov r0, r5
 *   @0x2439d4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2439d8 ldr r3, [pc, #0x1d4]
 *   @0x2439dc mov r1, r4
 *   @0x2439e0 mov r2, r4
 *   @0x2439e4 ldr r0, [r6, r3]
 *   @0x2439e8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2439ec ldr r1, [pc, #0x1c4]
 *   @0x2439f0 mov r3, r4
 *   @0x2439f4 add r1, pc, r1
 *   @0x2439f8 mov r2, r0
 *   @0x2439fc mov r0, r5
 *   @0x243a00 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243a04 ldr r3, [pc, #0x1b0]
 *   @0x243a08 mov r1, r4
 *   @0x243a0c mov r2, r4
 *   @0x243a10 ldr r0, [r6, r3]
 *   @0x243a14 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243a18 ldr r1, [pc, #0x1a0]
 *   @0x243a1c mov r3, r4
 *   @0x243a20 add r1, pc, r1
 *   @0x243a24 mov r2, r0
 *   @0x243a28 mov r0, r5
 *   @0x243a2c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243a30 ldr r3, [pc, #0x18c]
 *   @0x243a34 mov r1, r4
 *   @0x243a38 mov r2, r4
 *   @0x243a3c ldr r0, [r6, r3]
 *   @0x243a40 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243a44 ldr r1, [pc, #0x17c]
 *   @0x243a48 mov r3, r4
 *   @0x243a4c add r1, pc, r1
 *   @0x243a50 mov r2, r0
 *   @0x243a54 mov r0, r5
 *   @0x243a58 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243a5c ldr r3, [pc, #0x168]
 *   @0x243a60 mov r1, r4
 *   @0x243a64 mov r2, r4
 *   @0x243a68 ldr r0, [r6, r3]
 *   @0x243a6c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243a70 ldr r1, [pc, #0x158]
 *   @0x243a74 mov r3, r4
 *   @0x243a78 add r1, pc, r1
 *   @0x243a7c mov r2, r0
 *   @0x243a80 mov r0, r5
 *   @0x243a84 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243a88 ldr r3, [pc, #0x144]
 *   @0x243a8c mov r1, r4
 *   @0x243a90 mov r2, r4
 *   @0x243a94 ldr r0, [r6, r3]
 *   @0x243a98 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243a9c ldr r1, [pc, #0x134]
 *   @0x243aa0 mov r3, r4
 *   @0x243aa4 add r1, pc, r1
 *   @0x243aa8 mov r2, r0
 *   @0x243aac mov r0, r5
 *   @0x243ab0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243ab4 ldr r3, [pc, #0x120]
 *   @0x243ab8 mov r1, r4
 *   @0x243abc mov r2, r4
 *   @0x243ac0 ldr r0, [r6, r3]
 *   @0x243ac4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243ac8 ldr r1, [pc, #0x110]
 *   @0x243acc mov r3, r4
 *   @0x243ad0 add r1, pc, r1
 *   @0x243ad4 mov r2, r0
 *   @0x243ad8 mov r0, r5
 *   @0x243adc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243ae0 ldr r3, [pc, #0xfc]
 *   @0x243ae4 mov r1, r4
 *   @0x243ae8 mov r2, r4
 *   @0x243aec ldr r0, [r6, r3]
 *   @0x243af0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x243af4 ldr r1, [pc, #0xec]
 *   @0x243af8 mov r3, r4
 *   @0x243afc add r1, pc, r1
 *   @0x243b00 mov r2, r0
 *   @0x243b04 mov r0, r5
 *   @0x243b08 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243b0c ldr r0, [pc, #0xd8]
 *   @0x243b10 mov r1, r7
 *   @0x243b14 mov r2, r5
 *   @0x243b18 mov r3, r4
 *   @0x243b1c ldr r0, [r6, r0]
 *   @0x243b20 ldr r0, [r0]
 *   @0x243b24 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x243b28 add sp, sp, #28
 *   @0x243b2c pop {r4, r5, r6, r7, pc}
 *   @0x243b30 andseq lr, r10, r0, lsr #11
 *   @0x243b34 .word 0xffffc050
 *   @0x243b38 andseq r2, r1, r4, lsl #4
 *   @0x243b3c andseq r2, r1, r8, ror #3
 *   @0x243b40 andseq r2, r1, r8, asr #3
 *   @0x243b44 andseq r2, r1, r12, lsr #3
 *   @0x243b48 andseq r2, r1, r12, lsl #3
 *   @0x243b4c andseq r2, r1, r0, ror r1
 *   @0x243b50 andseq r2, r1, r4, asr r1
 *   @0x243b54 andseq r2, r1, r4, lsr r1
 *   @0x243b58 andseq r2, r1, r8, lsl r1
 *   @0x243b5c .word 0xfffffa20
 *   @0x243b60 andeq r5, pc, r12, ror #20
 *   @0x243b64 .word 0xfffffa24
 *   @0x243b68 andseq r2, r1, r0, asr #1
 *   @0x243b6c .word 0xfffffa28
 *   @0x243b70 mulseq r1, r12, r0
 *   @0x243b74 .word 0xfffffa2c
 *   @0x243b78 andseq r2, r1, r8, ror r0
 *   @0x243b7c .word 0xfffffa30
 *   @0x243b80 andseq r2, r1, r4, asr r0
 *   @0x243b84 .word 0xfffffa34
 *   @0x243b88 andeq r5, pc, r4, lsr #19
 *   @0x243b8c .word 0xfffffa38
 *   @0x243b90 strheq r5, [pc], -r8
 *   @0x243b94 .word 0xfffffa3c
 *   @0x243b98 andeq r5, pc, r0, ror r9
 *   @0x243b9c .word 0xfffffa40
 *   @0x243ba0 andeq r5, pc, r8, lsl r9
 *   @0x243ba4 .word 0xfffffa44
 *   @0x243ba8 andseq r1, r1, r0, lsl #31
 *   @0x243bac .word 0xfffffa48
 *   @0x243bb0 muleq pc, r8, r9
 *   @0x243bb4 .word 0xfffffa4c
 *   @0x243bb8 andeq r5, pc, r8, ror #18
 *   @0x243bbc .word 0xfffffa50
 *   @0x243bc0 andseq r1, r1, r0, lsl #30
 *   @0x243bc4 .word 0xfffffa54
 *   @0x243bc8 strheq r5, [pc], -r0
 *   @0x243bcc .word 0xfffffa58
 *   @0x243bd0 andeq r5, pc, r8, lsl #16
 *   @0x243bd4 .word 0xfffffa5c
 *   @0x243bd8 andeq r5, pc, r8, lsr #16
 *   @0x243bdc .word 0xfffffa60
 *   @0x243be0 ldrdeq r5, r6, [pc], -r8
 *   @0x243be4 .word 0xfffffa64
 *   @0x243be8 ldrdeq r5, r6, [pc], -r8
 *   @0x243bec .word 0xffffbf64
 *
 * ══ §3/23 InstanceRegionDeactivateSpecial(CInstance*)  0x10a708  size 1388  347 条（0x10a708..0x10ac74）
 * @func 0x10a708 0x10ac74  size 1388  347 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x10a734→0x483700, 0x10a798→0x542374, 0x10a84c→0x542a4c, 0x10a888→0x483704, 0x10a8ec→0x542374, 0x10a9ac→0x483704, 0x10aa10→0x542374, 0x10aac8→0x542a4c
 * 调用序列: CObjectGM::IsDecendentOf(int)×3 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / InstanceRegionDeactivateSpecial(CInstance*)+0x180 / InstanceRegionDeactivateSpecial(CInstance*)+0x3fc / InstanceRegionDeactivateSpecial(CInstance*)+0x29c / CInstance::Compute_BoundingBox(bool)
 * 字段偏移 top8: 0x4×18 / 0x8×10 / 0xc×7 / 0x80×3 / 0x3×3 / 0x2×2 / 0xf0×2 / 0x68×1
 * VFP 指令 86 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x10a708 ldrb r3, [r0, #0x68]
 *   @0x10a70c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x10a710 cmp r3, #0
 *   @0x10a714 ldr r4, [pc, #0x530]
 *   @0x10a718 sub sp, sp, #8
 *   @0x10a71c mov r5, r0
 *   @0x10a720 add r4, pc, r4
 *   @0x10a724 bne 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c>
 *   @0x10a728 ldrb r10, [r0, #0x69]
 *   @0x10a72c cmp r10, #0
 *   @0x10a730 bne 0x10a9ac <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x2a4>
 *   @0x10a734 ldr r2, [pc, #0x514]
 *   @0x10a738 mvn r3, #-16777216
 *   @0x10a73c ldr r2, [r4, r2]
 *   @0x10a740 ldr r7, [r2]
 *   @0x10a744 ldr r2, [r7, #0xc]
 *   @0x10a748 cmp r2, r3
 *   @0x10a74c beq 0x10a888 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x180>
 *   @0x10a750 ldr r0, [r7]
 *   @0x10a754 ldr r8, [r5, #0x80]
 *   @0x10a758 ldr r3, [r0, #0x4]
 *   @0x10a75c ldm r3, {r2, r9}
 *   @0x10a760 cmp r2, #0
 *   @0x10a764 ble 0x10a888 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x180>
 *   @0x10a768 vldr s11, [r5, #124]
 *   @0x10a76c vcvt.f64.s32 d6, s11
 *   @0x10a770 vldr s14, [r9]
 *   @0x10a774 vldr s15, [r9, #4]
 *   @0x10a778 vcmp.f64 d6, d7
 *   @0x10a77c vmrs APSR_nzcv, fpscr
 *   @0x10a780 beq 0x10a84c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x144>
 *   @0x10a784 vldr s11, [r5, #120]
 *   @0x10a788 vcvt.f64.s32 d6, s11
 *   @0x10a78c vcmp.f64 d7, d6
 *   @0x10a790 vmrs APSR_nzcv, fpscr
 *   @0x10a794 beq 0x10a84c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x144>
 *   @0x10a798 ldr r3, [pc, #0x4b4]
 *   @0x10a79c add r9, r9, #16
 *   @0x10a7a0 ldr r6, [r4, r3]
 *   @0x10a7a4 vcvt.s32.f64 s12, d7
 *   @0x10a7a8 ldr r3, [r6]
 *   @0x10a7ac ldr r2, [r3, #0x4]
 *   @0x10a7b0 ldr r3, [r3]
 *   @0x10a7b4 vmov r1, s12
 *   @0x10a7b8 and r2, r1, r2
 *   @0x10a7bc ldr r3, [r3, r2, lsl #3]
 *   @0x10a7c0 cmp r3, #0
 *   @0x10a7c4 bne 0x10a7d8 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0xd0>
 *   @0x10a7c8 b 0x10a804 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0xfc>
 *   @0x10a7cc ldr r3, [r3, #0x4]
 *   @0x10a7d0 cmp r3, #0
 *   @0x10a7d4 beq 0x10a804 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0xfc>
 *   @0x10a7d8 ldr r2, [r3, #0x8]
 *   @0x10a7dc cmp r1, r2
 *   @0x10a7e0 bne 0x10a7cc <_Z31InstanceRegionDeactivateSpecialP9CInstance+0xc4>
 *   @0x10a7e4 ldr r3, [r3, #0xc]
 *   @0x10a7e8 cmp r3, #0
 *   @0x10a7ec beq 0x10a804 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0xfc>
 *   @0x10a7f0 mov r0, r8
 *   @0x10a7f4 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi>
 *   @0x10a7f8 cmp r0, #0
 *   @0x10a7fc bne 0x10a84c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x144>
 *   @0x10a800 ldr r0, [r7]
 *   @0x10a804 ldr r3, [r0, #0x4]
 *   @0x10a808 add r10, r10, #1
 *   @0x10a80c ldr r3, [r3]
 *   @0x10a810 cmp r10, r3
 *   @0x10a814 bge 0x10a888 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x180>
 *   @0x10a818 vldr s11, [r5, #124]
 *   @0x10a81c vcvt.f64.s32 d6, s11
 *   @0x10a820 vldr s14, [r9]
 *   @0x10a824 vldr s15, [r9, #4]
 *   @0x10a828 vcmp.f64 d6, d7
 *   @0x10a82c vmrs APSR_nzcv, fpscr
 *   @0x10a830 beq 0x10a84c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x144>
 *   @0x10a834 vldr s11, [r5, #120]
 *   @0x10a838 vcvt.f64.s32 d6, s11
 *   @0x10a83c add r9, r9, #16
 *   @0x10a840 vcmp.f64 d7, d6
 *   @0x10a844 vmrs APSR_nzcv, fpscr
 *   @0x10a848 bne 0x10a7a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x9c>
 *   @0x10a84c ldr r3, [pc, #0x404]
 *   @0x10a850 ldr r4, [r4, r3]
 *   @0x10a854 ldr r1, [r4, #0x8]
 *   @0x10a858 ldr r3, [r4, #0x4]
 *   @0x10a85c cmp r1, r3
 *   @0x10a860 beq 0x10abf4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x4ec>
 *   @0x10a864 ldr r3, [r4]
 *   @0x10a868 str r5, [r3, r1, lsl #2]
 *   @0x10a86c mov r0, r5
 *   @0x10a870 add r3, r1, #1
 *   @0x10a874 mov r1, #1
 *   @0x10a878 str r3, [r4, #0x8]
 *   @0x10a87c add sp, sp, #8
 *   @0x10a880 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x10a884 b 0x19230c <_ZN9CInstance14SetDeactivatedEb>
 *   @0x10a888 ldr r2, [pc, #0x3cc]
 *   @0x10a88c mvn r3, #-16777216
 *   @0x10a890 ldr r2, [r4, r2]
 *   @0x10a894 ldr r7, [r2]
 *   @0x10a898 ldr r2, [r7, #0xc]
 *   @0x10a89c cmp r2, r3
 *   @0x10a8a0 beq 0x10ab04 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3fc>
 *   @0x10a8a4 ldr r0, [r7]
 *   @0x10a8a8 ldr r8, [r5, #0x80]
 *   @0x10a8ac ldr r3, [r0, #0x4]
 *   @0x10a8b0 ldm r3, {r2, r9}
 *   @0x10a8b4 cmp r2, #0
 *   @0x10a8b8 ble 0x10ab04 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3fc>
 *   @0x10a8bc vldr s11, [r5, #124]
 *   @0x10a8c0 vcvt.f64.s32 d6, s11
 *   @0x10a8c4 vldr s14, [r9]
 *   @0x10a8c8 vldr s15, [r9, #4]
 *   @0x10a8cc vcmp.f64 d6, d7
 *   @0x10a8d0 vmrs APSR_nzcv, fpscr
 *   @0x10a8d4 beq 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c>
 *   @0x10a8d8 vldr s11, [r5, #120]
 *   @0x10a8dc vcvt.f64.s32 d6, s11
 *   @0x10a8e0 vcmp.f64 d7, d6
 *   @0x10a8e4 vmrs APSR_nzcv, fpscr
 *   @0x10a8e8 beq 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c>
 *   @0x10a8ec ldr r3, [pc, #0x360]
 *   @0x10a8f0 add r9, r9, #16
 *   @0x10a8f4 mov r10, #0
 *   @0x10a8f8 ldr r6, [r4, r3]
 *   @0x10a8fc vcvt.s32.f64 s12, d7
 *   @0x10a900 ldr r3, [r6]
 *   @0x10a904 ldr r2, [r3, #0x4]
 *   @0x10a908 ldr r3, [r3]
 *   @0x10a90c vmov r1, s12
 *   @0x10a910 and r2, r1, r2
 *   @0x10a914 ldr r3, [r3, r2, lsl #3]
 *   @0x10a918 cmp r3, #0
 *   @0x10a91c bne 0x10a930 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x228>
 *   @0x10a920 b 0x10a95c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x254>
 *   @0x10a924 ldr r3, [r3, #0x4]
 *   @0x10a928 cmp r3, #0
 *   @0x10a92c beq 0x10a95c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x254>
 *   @0x10a930 ldr r2, [r3, #0x8]
 *   @0x10a934 cmp r1, r2
 *   @0x10a938 bne 0x10a924 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x21c>
 *   @0x10a93c ldr r3, [r3, #0xc]
 *   @0x10a940 cmp r3, #0
 *   @0x10a944 beq 0x10a95c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x254>
 *   @0x10a948 mov r0, r8
 *   @0x10a94c bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi>
 *   @0x10a950 cmp r0, #0
 *   @0x10a954 bne 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c>
 *   @0x10a958 ldr r0, [r7]
 *   @0x10a95c ldr r3, [r0, #0x4]
 *   @0x10a960 add r10, r10, #1
 *   @0x10a964 ldr r3, [r3]
 *   @0x10a968 cmp r10, r3
 *   @0x10a96c bge 0x10ab04 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3fc>
 *   @0x10a970 vldr s11, [r5, #124]
 *   @0x10a974 vcvt.f64.s32 d6, s11
 *   @0x10a978 vldr s14, [r9]
 *   @0x10a97c vldr s15, [r9, #4]
 *   @0x10a980 vcmp.f64 d6, d7
 *   @0x10a984 vmrs APSR_nzcv, fpscr
 *   @0x10a988 beq 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c>
 *   @0x10a98c vldr s11, [r5, #120]
 *   @0x10a990 vcvt.f64.s32 d6, s11
 *   @0x10a994 add r9, r9, #16
 *   @0x10a998 vcmp.f64 d7, d6
 *   @0x10a99c vmrs APSR_nzcv, fpscr
 *   @0x10a9a0 bne 0x10a8fc <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x1f4>
 *   @0x10a9a4 add sp, sp, #8
 *   @0x10a9a8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x10a9ac ldr r1, [pc, #0x2a8]
 *   @0x10a9b0 mvn r2, #-16777216
 *   @0x10a9b4 ldr r1, [r4, r1]
 *   @0x10a9b8 ldr r7, [r1]
 *   @0x10a9bc ldr r1, [r7, #0xc]
 *   @0x10a9c0 cmp r1, r2
 *   @0x10a9c4 beq 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c>
 *   @0x10a9c8 ldr r0, [r7]
 *   @0x10a9cc ldr r8, [r5, #0x80]
 *   @0x10a9d0 ldr r2, [r0, #0x4]
 *   @0x10a9d4 ldm r2, {r1, r9}
 *   @0x10a9d8 cmp r1, #0
 *   @0x10a9dc ble 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c>
 *   @0x10a9e0 vldr s11, [r5, #124]
 *   @0x10a9e4 vcvt.f64.s32 d6, s11
 *   @0x10a9e8 vldr s14, [r9]
 *   @0x10a9ec vldr s15, [r9, #4]
 *   @0x10a9f0 vcmp.f64 d6, d7
 *   @0x10a9f4 vmrs APSR_nzcv, fpscr
 *   @0x10a9f8 beq 0x10aac8 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3c0>
 *   @0x10a9fc vldr s11, [r5, #120]
 *   @0x10aa00 vcvt.f64.s32 d6, s11
 *   @0x10aa04 vcmp.f64 d7, d6
 *   @0x10aa08 vmrs APSR_nzcv, fpscr
 *   @0x10aa0c beq 0x10aac8 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3c0>
 *   @0x10aa10 ldr r2, [pc, #0x23c]
 *   @0x10aa14 add r9, r9, #16
 *   @0x10aa18 mov r10, r3
 *   @0x10aa1c ldr r6, [r4, r2]
 *   @0x10aa20 vcvt.s32.f64 s12, d7
 *   @0x10aa24 ldr r3, [r6]
 *   @0x10aa28 ldr r2, [r3, #0x4]
 *   @0x10aa2c ldr r3, [r3]
 *   @0x10aa30 vmov r1, s12
 *   @0x10aa34 and r2, r1, r2
 *   @0x10aa38 ldr r3, [r3, r2, lsl #3]
 *   @0x10aa3c cmp r3, #0
 *   @0x10aa40 bne 0x10aa54 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x34c>
 *   @0x10aa44 b 0x10aa80 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x378>
 *   @0x10aa48 ldr r3, [r3, #0x4]
 *   @0x10aa4c cmp r3, #0
 *   @0x10aa50 beq 0x10aa80 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x378>
 *   @0x10aa54 ldr r2, [r3, #0x8]
 *   @0x10aa58 cmp r1, r2
 *   @0x10aa5c bne 0x10aa48 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x340>
 *   @0x10aa60 ldr r3, [r3, #0xc]
 *   @0x10aa64 cmp r3, #0
 *   @0x10aa68 beq 0x10aa80 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x378>
 *   @0x10aa6c mov r0, r8
 *   @0x10aa70 bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi>
 *   @0x10aa74 cmp r0, #0
 *   @0x10aa78 bne 0x10aac8 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3c0>
 *   @0x10aa7c ldr r0, [r7]
 *   @0x10aa80 ldr r3, [r0, #0x4]
 *   @0x10aa84 add r10, r10, #1
 *   @0x10aa88 ldr r3, [r3]
 *   @0x10aa8c cmp r10, r3
 *   @0x10aa90 bge 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c>
 *   @0x10aa94 vldr s11, [r5, #124]
 *   @0x10aa98 vcvt.f64.s32 d6, s11
 *   @0x10aa9c vldr s14, [r9]
 *   @0x10aaa0 vldr s15, [r9, #4]
 *   @0x10aaa4 vcmp.f64 d6, d7
 *   @0x10aaa8 vmrs APSR_nzcv, fpscr
 *   @0x10aaac beq 0x10aac8 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3c0>
 *   @0x10aab0 vldr s11, [r5, #120]
 *   @0x10aab4 vcvt.f64.s32 d6, s11
 *   @0x10aab8 add r9, r9, #16
 *   @0x10aabc vcmp.f64 d7, d6
 *   @0x10aac0 vmrs APSR_nzcv, fpscr
 *   @0x10aac4 bne 0x10aa20 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x318>
 *   @0x10aac8 ldr r3, [pc, #0x188]
 *   @0x10aacc ldr r4, [r4, r3]
 *   @0x10aad0 ldr r1, [r4, #0x8]
 *   @0x10aad4 ldr r3, [r4, #0x4]
 *   @0x10aad8 cmp r1, r3
 *   @0x10aadc beq 0x10ac14 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x50c>
 *   @0x10aae0 ldr r3, [r4]
 *   @0x10aae4 str r5, [r3, r1, lsl #2]
 *   @0x10aae8 mov r0, r5
 *   @0x10aaec add r3, r1, #1
 *   @0x10aaf0 mov r1, #0
 *   @0x10aaf4 str r3, [r4, #0x8]
 *   @0x10aaf8 add sp, sp, #8
 *   @0x10aafc pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x10ab00 b 0x19230c <_ZN9CInstance14SetDeactivatedEb>
 *   @0x10ab04 ldrb r3, [r5, #0x64]
 *   @0x10ab08 cmp r3, #0
 *   @0x10ab0c beq 0x10ab1c <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x414>
 *   @0x10ab10 mov r0, r5
 *   @0x10ab14 mov r1, #1
 *   @0x10ab18 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x10ab1c vldr s12, [r5, #232]
 *   @0x10ab20 vcvt.f32.s32 s14, s12
 *   @0x10ab24 ldr r3, [pc, #0x134]
 *   @0x10ab28 add r3, pc, r3
 *   @0x10ab2c vldr s15, [r3, #24]
 *   @0x10ab30 vldr s13, [r3, #16]
 *   @0x10ab34 ldr r3, [r5, #0xf0]
 *   @0x10ab38 vcmpe.f32 s14, s15
 *   @0x10ab3c vmrs APSR_nzcv, fpscr
 *   @0x10ab40 movgt r3, #1
 *   @0x10ab44 bgt 0x10ab60 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x458>
 *   @0x10ab48 vmov s14, r3
 *   @0x10ab4c vcvt.f32.s32 s15, s14
 *   @0x10ab50 vcmpe.f32 s15, s13
 *   @0x10ab54 vmrs APSR_nzcv, fpscr
 *   @0x10ab58 movpl r3, #0
 *   @0x10ab5c movmi r3, #1
 *   @0x10ab60 vldr s15, [r5, #244]
 *   @0x10ab64 vcvt.f32.s32 s12, s15
 *   @0x10ab68 vldr s11, [r5, #236]
 *   @0x10ab6c ldr r2, [pc, #0xf0]
 *   @0x10ab70 add r2, pc, r2
 *   @0x10ab74 vldr s13, [r2, #20]
 *   @0x10ab78 vldr s15, [r2, #28]
 *   @0x10ab7c ldrb r2, [r2, #0xc]
 *   @0x10ab80 vcvt.f32.s32 s14, s11
 *   @0x10ab84 vcmp.f32 s12, s13
 *   @0x10ab88 vmrs APSR_nzcv, fpscr
 *   @0x10ab8c vcmp.f32 s14, s15
 *   @0x10ab90 movmi r3, #1
 *   @0x10ab94 vmrs APSR_nzcv, fpscr
 *   @0x10ab98 movgt r3, #1
 *   @0x10ab9c cmp r2, r3
 *   @0x10aba0 beq 0x10a9a4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x29c>
 *   @0x10aba4 ldr r3, [pc, #0xac]
 *   @0x10aba8 ldr r4, [r4, r3]
 *   @0x10abac ldr r1, [r4, #0x8]
 *   @0x10abb0 ldr r3, [r4, #0x4]
 *   @0x10abb4 cmp r1, r3
 *   @0x10abb8 bne 0x10a864 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x15c>
 *   @0x10abbc ldr r2, [pc, #0xa4]
 *   @0x10abc0 lsl r3, r1, #1
 *   @0x10abc4 ldr r0, [r4]
 *   @0x10abc8 lsl r1, r1, #3
 *   @0x10abcc add r2, pc, r2
 *   @0x10abd0 str r3, [r4, #0x4]
 *   @0x10abd4 mov r3, #0
 *   @0x10abd8 str r3, [sp]
 *   @0x10abdc mov r3, #74
 *   @0x10abe0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x10abe4 ldr r1, [r4, #0x8]
 *   @0x10abe8 mov r3, r0
 *   @0x10abec str r0, [r4]
 *   @0x10abf0 b 0x10a868 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x160>
 *   @0x10abf4 ldr r2, [pc, #0x70]
 *   @0x10abf8 lsl r3, r1, #1
 *   @0x10abfc ldr r0, [r4]
 *   @0x10ac00 lsl r1, r1, #3
 *   @0x10ac04 str r3, [r4, #0x4]
 *   @0x10ac08 add r2, pc, r2
 *   @0x10ac0c mov r3, #0
 *   @0x10ac10 b 0x10abd8 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x4d0>
 *   @0x10ac14 ldr r2, [pc, #0x54]
 *   @0x10ac18 lsl r3, r1, #1
 *   @0x10ac1c ldr r0, [r4]
 *   @0x10ac20 lsl r1, r1, #3
 *   @0x10ac24 str r3, [r4, #0x4]
 *   @0x10ac28 add r2, pc, r2
 *   @0x10ac2c mov r3, #0
 *   @0x10ac30 str r3, [sp]
 *   @0x10ac34 mov r3, #74
 *   @0x10ac38 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x10ac3c ldr r1, [r4, #0x8]
 *   @0x10ac40 mov r3, r0
 *   @0x10ac44 str r0, [r4]
 *   @0x10ac48 b 0x10aae4 <_Z31InstanceRegionDeactivateSpecialP9CInstance+0x3dc>
 *   @0x10ac4c eoreq r7, lr, r0, lsr r5
 *   @0x10ac50 .word 0xffffc45c
 *   @0x10ac54 .word 0xffffbfec
 *   @0x10ac58 .word 0xffffbff8
 *   @0x10ac5c .word 0xffffc460
 *   @0x10ac60 ldrhteq r8, [r7], -r0
 *   @0x10ac64 eorseq r8, r7, r8, ror #22
 *   @0x10ac68 eoreq r6, r2, r4, ror #8
 *   @0x10ac6c eoreq r6, r2, r8, lsr #8
 *   @0x10ac70 eoreq r6, r2, r8, lsl #8
 *
 * ══ §4/23 TestForNewPinches(long long)  0x1d7c70  size 1388  347 条（0x1d7c70..0x1d81dc）
 * @func 0x1d7c70 0x1d81dc  size 1388  347 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d7c84→0x3f5148, 0x1d7ca4→0x3f5144, 0x1d7cc0→0x3f5140, 0x1d7ce0→0x544a90, 0x1d7ce4→0x3f514c, 0x1d7d68→0x544aa8, 0x1d8088→0x3ebe00
 * 调用序列: 0xb658c×3 / 0xb6700×3 / TestForNewPinches(long long)+0x160 / 0xfe29c838 / TestForNewPinches(long long)+0x1c0 / TestForNewPinches(long long)+0x528 / operator new(unsigned int) / CGesture::CGesture()
 * 字段偏移 top8: 0x8×13 / 0x4×10 / 0x10×6 / 0x828×5 / 0x82c×5 / 0x14×4 / 0x1f0×2 / 0x1a0×2
 * VFP 指令 118 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d7c70 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d7c74 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x1d7c78 sub sp, sp, #28
 *   @0x1d7c7c vldr s16, [pc, #492]
 *   @0x1d7c80 ldr r10, [pc, #0x1f0]
 *   @0x1d7c84 ldr r3, [pc, #0x1f0]
 *   @0x1d7c88 add r10, pc, r10
 *   @0x1d7c8c strd r0, r1, [sp, #8]
 *   @0x1d7c90 ldr r3, [r10, r3]
 *   @0x1d7c94 vldr s15, [r3]
 *   @0x1d7c98 vmul.f32 s15, s15, s16
 *   @0x1d7c9c vmov r0, s15
 *   @0x1d7ca0 bl 0xb658c <cosf@plt>
 *   @0x1d7ca4 ldr r3, [pc, #0x1d4]
 *   @0x1d7ca8 ldr r3, [r10, r3]
 *   @0x1d7cac vldr s15, [r3]
 *   @0x1d7cb0 vmul.f32 s15, s15, s16
 *   @0x1d7cb4 vmov s26, r0
 *   @0x1d7cb8 vmov r0, s15
 *   @0x1d7cbc bl 0xb658c <cosf@plt>
 *   @0x1d7cc0 ldr r3, [pc, #0x1bc]
 *   @0x1d7cc4 ldr r3, [r10, r3]
 *   @0x1d7cc8 vldr s15, [r3]
 *   @0x1d7ccc vmul.f32 s15, s15, s16
 *   @0x1d7cd0 vmov s14, r0
 *   @0x1d7cd4 vmov r0, s15
 *   @0x1d7cd8 vneg.f32 s27, s14
 *   @0x1d7cdc bl 0xb658c <cosf@plt>
 *   @0x1d7ce0 ldr r3, [pc, #0x1a0]
 *   @0x1d7ce4 ldr r2, [pc, #0x1a0]
 *   @0x1d7ce8 ldr r3, [r10, r3]
 *   @0x1d7cec ldr r2, [r10, r2]
 *   @0x1d7cf0 vldr s23, [r2]
 *   @0x1d7cf4 vmul.f32 s23, s23, s23
 *   @0x1d7cf8 ldr r8, [r3]
 *   @0x1d7cfc cmp r8, #0
 *   @0x1d7d00 vmov s15, r0
 *   @0x1d7d04 vneg.f32 s28, s15
 *   @0x1d7d08 beq 0x1d7e64 <_Z17TestForNewPinchesx+0x1f4>
 *   @0x1d7d0c ldr r3, [r8, #0x8]
 *   @0x1d7d10 cmp r3, #0
 *   @0x1d7d14 beq 0x1d7e64 <_Z17TestForNewPinchesx+0x1f4>
 *   @0x1d7d18 ldr r5, [pc, #0x170]
 *   @0x1d7d1c vldr s24, [pc, #336]
 *   @0x1d7d20 vldr s25, [pc, #376]
 *   @0x1d7d24 add r5, pc, r5
 *   @0x1d7d28 str r5, [sp, #0x14]
 *   @0x1d7d2c ldr r4, [r8, #0x8]
 *   @0x1d7d30 ldrb r3, [r4, #0x830]
 *   @0x1d7d34 cmp r3, #0
 *   @0x1d7d38 bne 0x1d7e4c <_Z17TestForNewPinchesx+0x1dc>
 *   @0x1d7d3c ldr r6, [r8]
 *   @0x1d7d40 cmp r6, #0
 *   @0x1d7d44 beq 0x1d7e64 <_Z17TestForNewPinchesx+0x1f4>
 *   @0x1d7d48 ldr r3, [r6, #0x8]
 *   @0x1d7d4c cmp r3, #0
 *   @0x1d7d50 beq 0x1d81d4 <_Z17TestForNewPinchesx+0x564>
 *   @0x1d7d54 str r8, [sp, #0x10]
 *   @0x1d7d58 ldr r5, [r6, #0x8]
 *   @0x1d7d5c ldrb r3, [r5, #0x830]
 *   @0x1d7d60 cmp r3, #0
 *   @0x1d7d64 bne 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0>
 *   @0x1d7d68 ldr r3, [pc, #0x124]
 *   @0x1d7d6c ldr r7, [r10, r3]
 *   @0x1d7d70 ldr r11, [r7]
 *   @0x1d7d74 cmp r11, #0
 *   @0x1d7d78 bne 0x1d7ddc <_Z17TestForNewPinchesx+0x16c>
 *   @0x1d7d7c b 0x1d7ea4 <_Z17TestForNewPinchesx+0x234>
 *   @0x1d7d80 ldr r3, [r8]
 *   @0x1d7d84 mov r0, r8
 *   @0x1d7d88 ldr r3, [r3, #0x14]
 *   @0x1d7d8c blx r3
 *   @0x1d7d90 cmp r0, #1
 *   @0x1d7d94 mov r0, r8
 *   @0x1d7d98 ble 0x1d7dd0 <_Z17TestForNewPinchesx+0x160>
 *   @0x1d7d9c ldr r3, [r8]
 *   @0x1d7da0 ldr r1, [r4, #0x4]
 *   @0x1d7da4 ldr r3, [r3, #0x10]
 *   @0x1d7da8 blx r3
 *   @0x1d7dac ldr r3, [r8]
 *   @0x1d7db0 ldr r1, [r5, #0x4]
 *   @0x1d7db4 ldr r3, [r3, #0x10]
 *   @0x1d7db8 mov r9, r0
 *   @0x1d7dbc mov r0, r8
 *   @0x1d7dc0 blx r3
 *   @0x1d7dc4 eor r0, r0, r9
 *   @0x1d7dc8 tst r0, #255
 *   @0x1d7dcc bne 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0>
 *   @0x1d7dd0 ldr r11, [r11]
 *   @0x1d7dd4 cmp r11, #0
 *   @0x1d7dd8 beq 0x1d7ea4 <_Z17TestForNewPinchesx+0x234>
 *   @0x1d7ddc ldr r3, [r11, #0x8]
 *   @0x1d7de0 cmp r3, #0
 *   @0x1d7de4 beq 0x1d7ea4 <_Z17TestForNewPinchesx+0x234>
 *   @0x1d7de8 ldr r8, [r11, #0x8]
 *   @0x1d7dec ldr r3, [r8, #0x8]
 *   @0x1d7df0 cmp r3, #4
 *   @0x1d7df4 bne 0x1d7d80 <_Z17TestForNewPinchesx+0x110>
 *   @0x1d7df8 ldr r3, [r8]
 *   @0x1d7dfc mov r0, r8
 *   @0x1d7e00 ldr r1, [r4, #0x4]
 *   @0x1d7e04 ldr r3, [r3, #0x10]
 *   @0x1d7e08 blx r3
 *   @0x1d7e0c cmp r0, #0
 *   @0x1d7e10 beq 0x1d7d80 <_Z17TestForNewPinchesx+0x110>
 *   @0x1d7e14 ldr r3, [r8]
 *   @0x1d7e18 mov r0, r8
 *   @0x1d7e1c ldr r1, [r5, #0x4]
 *   @0x1d7e20 ldr r3, [r3, #0x10]
 *   @0x1d7e24 blx r3
 *   @0x1d7e28 cmp r0, #0
 *   @0x1d7e2c beq 0x1d7d80 <_Z17TestForNewPinchesx+0x110>
 *   @0x1d7e30 ldr r6, [r6]
 *   @0x1d7e34 cmp r6, #0
 *   @0x1d7e38 beq 0x1d7e48 <_Z17TestForNewPinchesx+0x1d8>
 *   @0x1d7e3c ldr r3, [r6, #0x8]
 *   @0x1d7e40 cmp r3, #0
 *   @0x1d7e44 bne 0x1d7d58 <_Z17TestForNewPinchesx+0xe8>
 *   @0x1d7e48 ldr r8, [sp, #0x10]
 *   @0x1d7e4c ldr r8, [r8]
 *   @0x1d7e50 cmp r8, #0
 *   @0x1d7e54 beq 0x1d7e64 <_Z17TestForNewPinchesx+0x1f4>
 *   @0x1d7e58 ldr r3, [r8, #0x8]
 *   @0x1d7e5c cmp r3, #0
 *   @0x1d7e60 bne 0x1d7d2c <_Z17TestForNewPinchesx+0xbc>
 *   @0x1d7e64 add sp, sp, #28
 *   @0x1d7e68 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x1d7e6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d7e70 vstmialo lr, {s30, s31}
 *   @0x1d7e74 blo 0xfe29c838 <b2_toiTime+0xfffffffffdb43394>
 *   @0x1d7e78 eoreq r9, r1, r8, asr #31
 *   @0x1d7e7c .word 0xffffef8c
 *   @0x1d7e80 .word 0xffffef90
 *   @0x1d7e84 .word 0xffffefc0
 *   @0x1d7e88 .word 0xffffefb4
 *   @0x1d7e8c .word 0xffffef88
 *   @0x1d7e90 andseq r5, r7, r12, lsl #2
 *   @0x1d7e94 .word 0xffffefc4
 *   @0x1d7e98 .word 0xffffefa8
 *   @0x1d7e9c andhi r0, r0, r0
 *   @0x1d7ea0 andeq r0, r0, r0
 *   @0x1d7ea4 ldr r3, [r4, #0x828]
 *   @0x1d7ea8 ldr r2, [r4, #0x82c]
 *   @0x1d7eac cmp r3, r2
 *   @0x1d7eb0 beq 0x1d812c <_Z17TestForNewPinchesx+0x4bc>
 *   @0x1d7eb4 add r3, r3, #63
 *   @0x1d7eb8 vldr s15, [r4, #24]
 *   @0x1d7ebc and r3, r3, #63
 *   @0x1d7ec0 vldr s14, [r4, #28]
 *   @0x1d7ec4 ldr r2, [r5, #0x82c]
 *   @0x1d7ec8 add r3, r4, r3, lsl #5
 *   @0x1d7ecc vldr s16, [r3, #56]
 *   @0x1d7ed0 vsub.f32 s16, s16, s15
 *   @0x1d7ed4 vldr s17, [r3, #60]
 *   @0x1d7ed8 ldr r3, [r5, #0x828]
 *   @0x1d7edc cmp r3, r2
 *   @0x1d7ee0 vmul.f32 s15, s16, s16
 *   @0x1d7ee4 vsub.f32 s17, s17, s14
 *   @0x1d7ee8 vmla.f32 s15, s17, s17
 *   @0x1d7eec beq 0x1d8148 <_Z17TestForNewPinchesx+0x4d8>
 *   @0x1d7ef0 add r3, r3, #63
 *   @0x1d7ef4 vldr s13, [r5, #28]
 *   @0x1d7ef8 and r3, r3, #63
 *   @0x1d7efc vldr s14, [r5, #24]
 *   @0x1d7f00 add r3, r5, r3, lsl #5
 *   @0x1d7f04 vldr s22, [r3, #60]
 *   @0x1d7f08 vldr s21, [r3, #56]
 *   @0x1d7f0c vsub.f32 s22, s22, s13
 *   @0x1d7f10 vmul.f32 s18, s22, s22
 *   @0x1d7f14 vsub.f32 s21, s21, s14
 *   @0x1d7f18 vmla.f32 s18, s21, s21
 *   @0x1d7f1c vcmpe.f32 s23, s15
 *   @0x1d7f20 vmrs APSR_nzcv, fpscr
 *   @0x1d7f24 bmi 0x1d7f34 <_Z17TestForNewPinchesx+0x2c4>
 *   @0x1d7f28 vcmpe.f32 s23, s18
 *   @0x1d7f2c vmrs APSR_nzcv, fpscr
 *   @0x1d7f30 bpl 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0>
 *   @0x1d7f34 vsqrt.f32 s19, s15
 *   @0x1d7f38 vcmp.f32 s19, s19
 *   @0x1d7f3c vmrs APSR_nzcv, fpscr
 *   @0x1d7f40 bne 0x1d81c4 <_Z17TestForNewPinchesx+0x554>
 *   @0x1d7f44 vsqrt.f32 s20, s18
 *   @0x1d7f48 vcmp.f32 s20, s20
 *   @0x1d7f4c vmrs APSR_nzcv, fpscr
 *   @0x1d7f50 bne 0x1d81b4 <_Z17TestForNewPinchesx+0x544>
 *   @0x1d7f54 ldr r3, [r4, #0x828]
 *   @0x1d7f58 ldr r2, [r4, #0x82c]
 *   @0x1d7f5c ldr r1, [r5, #0x82c]
 *   @0x1d7f60 cmp r3, r2
 *   @0x1d7f64 ldr r2, [r5, #0x828]
 *   @0x1d7f68 addne r3, r3, #63
 *   @0x1d7f6c andne r3, r3, #63
 *   @0x1d7f70 moveq r3, #0
 *   @0x1d7f74 addne r3, r4, r3, lsl #5
 *   @0x1d7f78 addne r3, r3, #40
 *   @0x1d7f7c cmp r2, r1
 *   @0x1d7f80 addne r2, r2, #63
 *   @0x1d7f84 vldr s15, [r3, #20]
 *   @0x1d7f88 andne r2, r2, #63
 *   @0x1d7f8c moveq r2, #0
 *   @0x1d7f90 addne r2, r5, r2, lsl #5
 *   @0x1d7f94 addne r2, r2, #40
 *   @0x1d7f98 vldr s18, [r2, #20]
 *   @0x1d7f9c vsub.f32 s18, s18, s15
 *   @0x1d7fa0 vldr s29, [r2, #16]
 *   @0x1d7fa4 vldr s15, [r3, #16]
 *   @0x1d7fa8 vmul.f32 s14, s18, s18
 *   @0x1d7fac vsub.f32 s29, s29, s15
 *   @0x1d7fb0 vmla.f32 s14, s29, s29
 *   @0x1d7fb4 vsqrt.f32 s15, s14
 *   @0x1d7fb8 vcmp.f32 s15, s15
 *   @0x1d7fbc vmrs APSR_nzcv, fpscr
 *   @0x1d7fc0 bne 0x1d81a4 <_Z17TestForNewPinchesx+0x534>
 *   @0x1d7fc4 vcmpe.f32 s15, #0
 *   @0x1d7fc8 vmrs APSR_nzcv, fpscr
 *   @0x1d7fcc vdivgt.f32 s29, s29, s15
 *   @0x1d7fd0 vldrle s14, [pc, #-316]
 *   @0x1d7fd4 vldrle s15, [pc, #-316]
 *   @0x1d7fd8 vdivgt.f32 s15, s18, s15
 *   @0x1d7fdc vdiv.f32 s17, s17, s19
 *   @0x1d7fe0 vdiv.f32 s22, s22, s20
 *   @0x1d7fe4 vdiv.f32 s16, s16, s19
 *   @0x1d7fe8 vdiv.f32 s21, s21, s20
 *   @0x1d7fec vneggt.f32 s14, s15
 *   @0x1d7ff0 vmovle.f32 s13, s14
 *   @0x1d7ff4 vmovle.f32 s29, s15
 *   @0x1d7ff8 vmul.f32 s14, s22, s14
 *   @0x1d7ffc vmul.f32 s15, s17, s15
 *   @0x1d8000 vneggt.f32 s13, s29
 *   @0x1d8004 vcmpe.f32 s19, s24
 *   @0x1d8008 vmla.f32 s15, s16, s29
 *   @0x1d800c vmrs APSR_nzcv, fpscr
 *   @0x1d8010 vmla.f32 s14, s21, s13
 *   @0x1d8014 vcmpe.f32 s20, s24
 *   @0x1d8018 bmi 0x1d8158 <_Z17TestForNewPinchesx+0x4e8>
 *   @0x1d801c vmrs APSR_nzcv, fpscr
 *   @0x1d8020 bmi 0x1d817c <_Z17TestForNewPinchesx+0x50c>
 *   @0x1d8024 vmul.f32 s17, s17, s22
 *   @0x1d8028 vmla.f32 s17, s16, s21
 *   @0x1d802c vcmpe.f32 s28, s17
 *   @0x1d8030 vmrs APSR_nzcv, fpscr
 *   @0x1d8034 ble 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0>
 *   @0x1d8038 vcmpe.f32 s26, s15
 *   @0x1d803c vmrs APSR_nzcv, fpscr
 *   @0x1d8040 movmi r3, #1
 *   @0x1d8044 bmi 0x1d8058 <_Z17TestForNewPinchesx+0x3e8>
 *   @0x1d8048 vcmpe.f32 s27, s15
 *   @0x1d804c vmrs APSR_nzcv, fpscr
 *   @0x1d8050 movle r3, #0
 *   @0x1d8054 movgt r3, #1
 *   @0x1d8058 vcmpe.f32 s26, s14
 *   @0x1d805c vmrs APSR_nzcv, fpscr
 *   @0x1d8060 bmi 0x1d8070 <_Z17TestForNewPinchesx+0x400>
 *   @0x1d8064 vcmpe.f32 s27, s14
 *   @0x1d8068 vmrs APSR_nzcv, fpscr
 *   @0x1d806c ble 0x1d8198 <_Z17TestForNewPinchesx+0x528>
 *   @0x1d8070 mov r0, #72
 *   @0x1d8074 mov r9, #4
 *   @0x1d8078 bl 0x27c524 <_Znwj>
 *   @0x1d807c mov r11, #0
 *   @0x1d8080 str r0, [sp, #0x4]
 *   @0x1d8084 bl 0x1d7c0c <_ZN8CGestureC2Ev>
 *   @0x1d8088 ldr r12, [pc, #-0x1f8]
 *   @0x1d808c mvn r1, #0
 *   @0x1d8090 ldr r2, [r4, #0x4]
 *   @0x1d8094 mov r0, #12
 *   @0x1d8098 ldr r3, [r5, #0x4]
 *   @0x1d809c ldr r8, [sp, #0x4]
 *   @0x1d80a0 ldr r12, [r10, r12]
 *   @0x1d80a4 vstr s25, [r8, #52]
 *   @0x1d80a8 vstr s25, [r8, #48]
 *   @0x1d80ac vstr s25, [r8, #56]
 *   @0x1d80b0 str r9, [r8, #0x8]
 *   @0x1d80b4 vstr s25, [r8, #60]
 *   @0x1d80b8 str r1, [r8, #0x40]
 *   @0x1d80bc add r12, r12, #8
 *   @0x1d80c0 str r2, [r8, #0x28]
 *   @0x1d80c4 mov r2, #143
 *   @0x1d80c8 str r12, [r8]
 *   @0x1d80cc str r3, [r8, #0x2c]
 *   @0x1d80d0 mov r3, #1
 *   @0x1d80d4 ldr r5, [sp, #0x4]
 *   @0x1d80d8 ldrd r8, r9, [sp, #8]
 *   @0x1d80dc ldr r12, [r7, #0x8]
 *   @0x1d80e0 ldr r1, [sp, #0x14]
 *   @0x1d80e4 strd r8, r9, [r5, #24]
 *   @0x1d80e8 add r12, r12, r3
 *   @0x1d80ec strd r8, r9, [r5, #32]
 *   @0x1d80f0 str r11, [r5, #0x14]
 *   @0x1d80f4 str r12, [r7, #0x8]
 *   @0x1d80f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1d80fc ldr r3, [r7, #0x4]
 *   @0x1d8100 cmp r3, r11
 *   @0x1d8104 str r5, [r0, #0x8]
 *   @0x1d8108 streq r0, [r7, #0x4]
 *   @0x1d810c strne r0, [r3]
 *   @0x1d8110 streq r0, [r7]
 *   @0x1d8114 strne r3, [r0, #0x4]
 *   @0x1d8118 streq r3, [r0, #0x4]
 *   @0x1d811c strne r0, [r7, #0x4]
 *   @0x1d8120 streq r3, [r0]
 *   @0x1d8124 strne r11, [r0]
 *   @0x1d8128 b 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0>
 *   @0x1d812c ldr r3, [r5, #0x828]
 *   @0x1d8130 vldr s15, [pc, #-664]
 *   @0x1d8134 ldr r2, [r5, #0x82c]
 *   @0x1d8138 vmov.f32 s17, s15
 *   @0x1d813c cmp r3, r2
 *   @0x1d8140 vmov.f32 s16, s15
 *   @0x1d8144 bne 0x1d7ef0 <_Z17TestForNewPinchesx+0x280>
 *   @0x1d8148 vldr s18, [pc, #-688]
 *   @0x1d814c vmov.f32 s22, s18
 *   @0x1d8150 vmov.f32 s21, s18
 *   @0x1d8154 b 0x1d7f1c <_Z17TestForNewPinchesx+0x2ac>
 *   @0x1d8158 vmrs APSR_nzcv, fpscr
 *   @0x1d815c bmi 0x1d817c <_Z17TestForNewPinchesx+0x50c>
 *   @0x1d8160 vcmpe.f32 s26, s14
 *   @0x1d8164 vmrs APSR_nzcv, fpscr
 *   @0x1d8168 bmi 0x1d8070 <_Z17TestForNewPinchesx+0x400>
 *   @0x1d816c vcmpe.f32 s27, s14
 *   @0x1d8170 vmrs APSR_nzcv, fpscr
 *   @0x1d8174 bgt 0x1d8070 <_Z17TestForNewPinchesx+0x400>
 *   @0x1d8178 b 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0>
 *   @0x1d817c vcmpe.f32 s26, s15
 *   @0x1d8180 vmrs APSR_nzcv, fpscr
 *   @0x1d8184 bmi 0x1d8070 <_Z17TestForNewPinchesx+0x400>
 *   @0x1d8188 vcmpe.f32 s27, s15
 *   @0x1d818c vmrs APSR_nzcv, fpscr
 *   @0x1d8190 bgt 0x1d8070 <_Z17TestForNewPinchesx+0x400>
 *   @0x1d8194 b 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0>
 *   @0x1d8198 cmp r3, #0
 *   @0x1d819c beq 0x1d7e30 <_Z17TestForNewPinchesx+0x1c0>
 *   @0x1d81a0 b 0x1d8070 <_Z17TestForNewPinchesx+0x400>
 *   @0x1d81a4 vmov r0, s14
 *   @0x1d81a8 bl 0xb6700 <sqrtf@plt>
 *   @0x1d81ac vmov s15, r0
 *   @0x1d81b0 b 0x1d7fc4 <_Z17TestForNewPinchesx+0x354>
 *   @0x1d81b4 vmov r0, s18
 *   @0x1d81b8 bl 0xb6700 <sqrtf@plt>
 *   @0x1d81bc vmov s20, r0
 *   @0x1d81c0 b 0x1d7f54 <_Z17TestForNewPinchesx+0x2e4>
 *   @0x1d81c4 vmov r0, s15
 *   @0x1d81c8 bl 0xb6700 <sqrtf@plt>
 *   @0x1d81cc vmov s19, r0
 *   @0x1d81d0 b 0x1d7f44 <_Z17TestForNewPinchesx+0x2d4>
 *   @0x1d81d4 mov r8, r6
 *   @0x1d81d8 b 0x1d7e58 <_Z17TestForNewPinchesx+0x1e8>
 *
 * ══ §5/23 Split_TextBlock(char const*, int, TStringList*)  0x172560  size 1384  346 条（0x172560..0x172ac8）
 * @func 0x172560 0x172ac8  size 1384  346 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / Split_TextBlock(char const*, int, TStringList*)+0x178×2 / CFontGM::GetShift(int)×2 / String_Replace_Hash(char*) / Split_TextBlock(char const*, int, TStringList*)+0x510 / utf8_extract_char / Split_TextBlock(char const*, int, TStringList*)+0x200
 * 字段偏移 top8: 0x4×19 / 0x8×18 / 0xc×15 / 0x2×5 / 0x10×5 / 0x-2×3 / 0x14×3 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x172560 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x172564 subs r5, r0, #0
 *   @0x172568 sub sp, sp, #52
 *   @0x17256c mov r8, r1
 *   @0x172570 str r2, [sp, #0xc]
 *   @0x172574 beq 0x1727e8 <_Z15Split_TextBlockPKciP11TStringList+0x288>
 *   @0x172578 cmp r1, #0
 *   @0x17257c ldr r0, [r2]
 *   @0x172580 movw r3, #0x9680
 *   @0x172584 movt r3, #0x98
 *   @0x172588 movlt r8, r3
 *   @0x17258c cmp r0, #0
 *   @0x172590 beq 0x1725a8 <_Z15Split_TextBlockPKciP11TStringList+0x48>
 *   @0x172594 ldr r4, [r0]
 *   @0x172598 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x17259c cmp r4, #0
 *   @0x1725a0 mov r0, r4
 *   @0x1725a4 bne 0x172594 <_Z15Split_TextBlockPKciP11TStringList+0x34>
 *   @0x1725a8 ldr r12, [sp, #0xc]
 *   @0x1725ac mov r3, #0
 *   @0x1725b0 ldr r0, [r12, #0xc]
 *   @0x1725b4 str r3, [r12, #0x8]
 *   @0x1725b8 cmp r0, r3
 *   @0x1725bc str r3, [r12]
 *   @0x1725c0 beq 0x1725c8 <_Z15Split_TextBlockPKciP11TStringList+0x68>
 *   @0x1725c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1725c8 ldr r12, [sp, #0xc]
 *   @0x1725cc mov r4, #0
 *   @0x1725d0 mov r0, r5
 *   @0x1725d4 str r4, [r12, #0xc]
 *   @0x1725d8 bl 0x212da8 <_Z19String_Replace_HashPc>
 *   @0x1725dc ldr r1, [pc, #0x4d0]
 *   @0x1725e0 mov r3, r4
 *   @0x1725e4 movw r2, #0x117
 *   @0x1725e8 add r1, pc, r1
 *   @0x1725ec add r6, r0, #1
 *   @0x1725f0 mov r11, r0
 *   @0x1725f4 lsl r6, r6, #1
 *   @0x1725f8 mov r0, r6
 *   @0x1725fc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x172600 cmp r11, r4
 *   @0x172604 str r5, [sp, #0x2c]
 *   @0x172608 str r0, [sp, #0x4]
 *   @0x17260c ble 0x172a70 <_Z15Split_TextBlockPKciP11TStringList+0x510>
 *   @0x172610 sub r4, r6, #2
 *   @0x172614 add r6, sp, #44
 *   @0x172618 add r4, r0, r4
 *   @0x17261c mov r5, r0
 *   @0x172620 mov r0, r6
 *   @0x172624 bl 0x10fb38 <utf8_extract_char>
 *   @0x172628 strh r0, [r5], #2
 *   @0x17262c cmp r5, r4
 *   @0x172630 bne 0x172620 <_Z15Split_TextBlockPKciP11TStringList+0xc0>
 *   @0x172634 ldr r12, [sp, #0x4]
 *   @0x172638 mov r3, #0
 *   @0x17263c ldr r0, [sp, #0xc]
 *   @0x172640 mov r4, r3
 *   @0x172644 strh r3, [r5]
 *   @0x172648 ldrh r9, [r12]
 *   @0x17264c str r12, [r0, #0xc]
 *   @0x172650 movw r12, #0x9680
 *   @0x172654 movt r12, #0x98
 *   @0x172658 str r12, [sp, #0x18]
 *   @0x17265c ldr r12, [pc, #0x454]
 *   @0x172660 str r3, [sp, #0x8]
 *   @0x172664 add r12, pc, r12
 *   @0x172668 str r12, [sp, #0x20]
 *   @0x17266c ldr r12, [pc, #0x448]
 *   @0x172670 str r8, [sp, #0x10]
 *   @0x172674 add r12, pc, r12
 *   @0x172678 str r12, [sp, #0x24]
 *   @0x17267c ldr r12, [pc, #0x43c]
 *   @0x172680 add r12, pc, r12
 *   @0x172684 str r12, [sp, #0x1c]
 *   @0x172688 ldr r12, [sp, #0x10]
 *   @0x17268c lsl r2, r4, #1
 *   @0x172690 ldr r0, [sp, #0x18]
 *   @0x172694 cmp r12, r0
 *   @0x172698 beq 0x172910 <_Z15Split_TextBlockPKciP11TStringList+0x3b0>
 *   @0x17269c cmp r11, r4
 *   @0x1726a0 ble 0x1726d8 <_Z15Split_TextBlockPKciP11TStringList+0x178>
 *   @0x1726a4 ldr r12, [sp, #0x4]
 *   @0x1726a8 add r3, r12, r2
 *   @0x1726ac ldrh r1, [r12, r2]
 *   @0x1726b0 cmp r1, #32
 *   @0x1726b4 beq 0x1726c8 <_Z15Split_TextBlockPKciP11TStringList+0x168>
 *   @0x1726b8 b 0x1727f4 <_Z15Split_TextBlockPKciP11TStringList+0x294>
 *   @0x1726bc ldrh r2, [r3, #2]!
 *   @0x1726c0 cmp r2, #32
 *   @0x1726c4 bne 0x1727f0 <_Z15Split_TextBlockPKciP11TStringList+0x290>
 *   @0x1726c8 add r4, r4, #1
 *   @0x1726cc cmp r4, r11
 *   @0x1726d0 bne 0x1726bc <_Z15Split_TextBlockPKciP11TStringList+0x15c>
 *   @0x1726d4 lsl r2, r4, #1
 *   @0x1726d8 ldr r12, [sp, #0x4]
 *   @0x1726dc mov r1, r4
 *   @0x1726e0 mov r5, r4
 *   @0x1726e4 add r10, r12, r2
 *   @0x1726e8 ldrh r2, [r12, r2]
 *   @0x1726ec cmp r2, #10
 *   @0x1726f0 beq 0x1728b0 <_Z15Split_TextBlockPKciP11TStringList+0x350>
 *   @0x1726f4 ldr r12, [sp, #0x8]
 *   @0x1726f8 cmp r4, r12
 *   @0x1726fc beq 0x1727e8 <_Z15Split_TextBlockPKciP11TStringList+0x288>
 *   @0x172700 cmp r4, r11
 *   @0x172704 beq 0x1728cc <_Z15Split_TextBlockPKciP11TStringList+0x36c>
 *   @0x172708 cmp r2, #32
 *   @0x17270c beq 0x1729b8 <_Z15Split_TextBlockPKciP11TStringList+0x458>
 *   @0x172710 ldr r12, [sp, #0x8]
 *   @0x172714 cmp r4, r12
 *   @0x172718 ble 0x172760 <_Z15Split_TextBlockPKciP11TStringList+0x200>
 *   @0x17271c sub r5, r4, #1
 *   @0x172720 ldr r12, [sp, #0x4]
 *   @0x172724 lsl r3, r5, #1
 *   @0x172728 ldrh r2, [r12, r3]
 *   @0x17272c cmp r2, #32
 *   @0x172730 beq 0x1729b4 <_Z15Split_TextBlockPKciP11TStringList+0x454>
 *   @0x172734 add r3, r12, r3
 *   @0x172738 ldr r1, [sp, #0x8]
 *   @0x17273c b 0x172750 <_Z15Split_TextBlockPKciP11TStringList+0x1f0>
 *   @0x172740 ldrh r2, [r3, #-2]!
 *   @0x172744 sub r5, r5, #1
 *   @0x172748 cmp r2, #32
 *   @0x17274c beq 0x1729b4 <_Z15Split_TextBlockPKciP11TStringList+0x454>
 *   @0x172750 cmp r5, r1
 *   @0x172754 bne 0x172740 <_Z15Split_TextBlockPKciP11TStringList+0x1e0>
 *   @0x172758 ldr r12, [sp, #0x4]
 *   @0x17275c add r10, r12, r5, lsl #1
 *   @0x172760 ldr r12, [sp, #0x8]
 *   @0x172764 cmp r5, r12
 *   @0x172768 beq 0x1729d8 <_Z15Split_TextBlockPKciP11TStringList+0x478>
 *   @0x17276c ldr r12, [sp, #0xc]
 *   @0x172770 mov r1, #0
 *   @0x172774 mov r0, #8
 *   @0x172778 ldr r2, [r12, #0x8]
 *   @0x17277c strh r1, [r10]
 *   @0x172780 ldr r1, [sp, #0x1c]
 *   @0x172784 add r3, r2, #1
 *   @0x172788 mov r2, #93
 *   @0x17278c str r3, [r12, #0x8]
 *   @0x172790 mov r3, #1
 *   @0x172794 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x172798 ldr r12, [sp, #0xc]
 *   @0x17279c ldr r1, [sp, #0x8]
 *   @0x1727a0 mov r2, #0
 *   @0x1727a4 ldr r3, [r12]
 *   @0x1727a8 ldr r12, [sp, #0x4]
 *   @0x1727ac cmp r3, r2
 *   @0x1727b0 add r10, r12, r1, lsl #1
 *   @0x1727b4 ldr r12, [sp, #0xc]
 *   @0x1727b8 str r2, [r0]
 *   @0x1727bc str r10, [r0, #0x4]
 *   @0x1727c0 streq r0, [r12]
 *   @0x1727c4 ldrne r3, [r12, #0x4]
 *   @0x1727c8 ldr r12, [sp, #0xc]
 *   @0x1727cc strne r0, [r3]
 *   @0x1727d0 str r0, [r12, #0x4]
 *   @0x1727d4 add r4, r5, #1
 *   @0x1727d8 str r4, [sp, #0x8]
 *   @0x1727dc ldr r12, [sp, #0x8]
 *   @0x1727e0 cmp r11, r12
 *   @0x1727e4 bgt 0x172688 <_Z15Split_TextBlockPKciP11TStringList+0x128>
 *   @0x1727e8 add sp, sp, #52
 *   @0x1727ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1727f0 lsl r2, r4, #1
 *   @0x1727f4 ldr r12, [sp, #0x10]
 *   @0x1727f8 cmp r11, r4
 *   @0x1727fc cmpgt r12, #0
 *   @0x172800 ble 0x1726d8 <_Z15Split_TextBlockPKciP11TStringList+0x178>
 *   @0x172804 ldr r12, [sp, #0x4]
 *   @0x172808 add r10, r12, r2
 *   @0x17280c ldrh r1, [r12, r2]
 *   @0x172810 cmp r1, #10
 *   @0x172814 beq 0x172a54 <_Z15Split_TextBlockPKciP11TStringList+0x4f4>
 *   @0x172818 ldr r7, [pc, #0x2a4]
 *   @0x17281c mov r6, r10
 *   @0x172820 str r9, [sp, #0x14]
 *   @0x172824 mov r8, #0
 *   @0x172828 mov r9, r4
 *   @0x17282c ldr r7, [pc, r7]
 *   @0x172830 ldr r4, [sp, #0x10]
 *   @0x172834 b 0x17284c <_Z15Split_TextBlockPKciP11TStringList+0x2ec>
 *   @0x172838 ldrh r1, [r6, #2]
 *   @0x17283c mov r9, r5
 *   @0x172840 mov r6, r10
 *   @0x172844 cmp r1, #10
 *   @0x172848 beq 0x1728ac <_Z15Split_TextBlockPKciP11TStringList+0x34c>
 *   @0x17284c ldr r0, [r7]
 *   @0x172850 add r5, r9, #1
 *   @0x172854 bl 0xf6e78 <_ZN7CFontGM8GetShiftEi>
 *   @0x172858 add r10, r10, #2
 *   @0x17285c add r8, r8, r0
 *   @0x172860 cmp r4, r8
 *   @0x172864 cmpgt r11, r5
 *   @0x172868 bgt 0x172838 <_Z15Split_TextBlockPKciP11TStringList+0x2d8>
 *   @0x17286c ldr r12, [sp, #0x10]
 *   @0x172870 mov r4, r9
 *   @0x172874 ldr r9, [sp, #0x14]
 *   @0x172878 cmp r12, r8
 *   @0x17287c bge 0x172a84 <_Z15Split_TextBlockPKciP11TStringList+0x524>
 *   @0x172880 ldr r12, [sp, #0x4]
 *   @0x172884 lsl r6, r4, #1
 *   @0x172888 ldr r0, [r7]
 *   @0x17288c mov r5, r4
 *   @0x172890 add r10, r12, r6
 *   @0x172894 ldrh r1, [r12, r6]
 *   @0x172898 bl 0xf6e78 <_ZN7CFontGM8GetShiftEi>
 *   @0x17289c ldr r12, [sp, #0x4]
 *   @0x1728a0 mov r1, r4
 *   @0x1728a4 ldrh r2, [r12, r6]
 *   @0x1728a8 b 0x1726ec <_Z15Split_TextBlockPKciP11TStringList+0x18c>
 *   @0x1728ac ldr r9, [sp, #0x14]
 *   @0x1728b0 ldr r12, [sp, #0xc]
 *   @0x1728b4 mov r1, #0
 *   @0x1728b8 mov r0, #8
 *   @0x1728bc ldr r2, [r12, #0x8]
 *   @0x1728c0 strh r1, [r10]
 *   @0x1728c4 ldr r1, [sp, #0x24]
 *   @0x1728c8 b 0x172784 <_Z15Split_TextBlockPKciP11TStringList+0x224>
 *   @0x1728cc ldr r12, [sp, #0x4]
 *   @0x1728d0 add r1, r12, r1, lsl #1
 *   @0x1728d4 ldrh r3, [r1, #-2]
 *   @0x1728d8 cmp r3, #32
 *   @0x1728dc bne 0x1728f8 <_Z15Split_TextBlockPKciP11TStringList+0x398>
 *   @0x1728e0 add r3, r12, r5, lsl #1
 *   @0x1728e4 sub r3, r3, #2
 *   @0x1728e8 ldrh r2, [r3, #-2]
 *   @0x1728ec sub r5, r5, #1
 *   @0x1728f0 cmp r2, #32
 *   @0x1728f4 beq 0x1728e4 <_Z15Split_TextBlockPKciP11TStringList+0x384>
 *   @0x1728f8 ldr r12, [sp, #0x8]
 *   @0x1728fc cmp r5, r12
 *   @0x172900 beq 0x1727d4 <_Z15Split_TextBlockPKciP11TStringList+0x274>
 *   @0x172904 ldr r12, [sp, #0x4]
 *   @0x172908 add r10, r12, r5, lsl #1
 *   @0x17290c b 0x17276c <_Z15Split_TextBlockPKciP11TStringList+0x20c>
 *   @0x172910 cmp r11, r4
 *   @0x172914 ble 0x172a5c <_Z15Split_TextBlockPKciP11TStringList+0x4fc>
 *   @0x172918 ldr r12, [sp, #0x4]
 *   @0x17291c add r3, r12, r2
 *   @0x172920 ldrh r2, [r12, r2]
 *   @0x172924 cmp r2, #13
 *   @0x172928 beq 0x172aa4 <_Z15Split_TextBlockPKciP11TStringList+0x544>
 *   @0x17292c cmp r2, #10
 *   @0x172930 beq 0x172a30 <_Z15Split_TextBlockPKciP11TStringList+0x4d0>
 *   @0x172934 mov r2, r3
 *   @0x172938 b 0x17294c <_Z15Split_TextBlockPKciP11TStringList+0x3ec>
 *   @0x17293c cmp r9, #13
 *   @0x172940 beq 0x172a98 <_Z15Split_TextBlockPKciP11TStringList+0x538>
 *   @0x172944 cmp r9, #10
 *   @0x172948 beq 0x172a8c <_Z15Split_TextBlockPKciP11TStringList+0x52c>
 *   @0x17294c add r4, r4, #1
 *   @0x172950 add r3, r3, #2
 *   @0x172954 cmp r4, r11
 *   @0x172958 ldrh r9, [r2, #2]
 *   @0x17295c mov r2, r3
 *   @0x172960 bne 0x17293c <_Z15Split_TextBlockPKciP11TStringList+0x3dc>
 *   @0x172964 mov r4, r9
 *   @0x172968 mov r5, r11
 *   @0x17296c cmp r9, #10
 *   @0x172970 beq 0x172a1c <_Z15Split_TextBlockPKciP11TStringList+0x4bc>
 *   @0x172974 cmp r9, #13
 *   @0x172978 bne 0x172984 <_Z15Split_TextBlockPKciP11TStringList+0x424>
 *   @0x17297c cmp r4, #10
 *   @0x172980 beq 0x172a48 <_Z15Split_TextBlockPKciP11TStringList+0x4e8>
 *   @0x172984 ldr r12, [sp, #0xc]
 *   @0x172988 mov r1, #0
 *   @0x17298c mov r0, #8
 *   @0x172990 mov r9, r4
 *   @0x172994 ldr r2, [r12, #0x8]
 *   @0x172998 strh r1, [r3]
 *   @0x17299c add r3, r2, #1
 *   @0x1729a0 ldr r1, [sp, #0x20]
 *   @0x1729a4 str r3, [r12, #0x8]
 *   @0x1729a8 mov r2, #93
 *   @0x1729ac mov r3, #1
 *   @0x1729b0 b 0x172794 <_Z15Split_TextBlockPKciP11TStringList+0x234>
 *   @0x1729b4 mov r1, r5
 *   @0x1729b8 ldr r12, [sp, #0x8]
 *   @0x1729bc cmp r5, r12
 *   @0x1729c0 bgt 0x1728cc <_Z15Split_TextBlockPKciP11TStringList+0x36c>
 *   @0x1729c4 ldr r12, [sp, #0x4]
 *   @0x1729c8 add r10, r12, r1, lsl #1
 *   @0x1729cc ldr r12, [sp, #0x8]
 *   @0x1729d0 cmp r5, r12
 *   @0x1729d4 bne 0x17276c <_Z15Split_TextBlockPKciP11TStringList+0x20c>
 *   @0x1729d8 ldrh r2, [r10]
 *   @0x1729dc movw r3, #0xffdf
 *   @0x1729e0 and r3, r2, r3
 *   @0x1729e4 cmp r3, #0
 *   @0x1729e8 beq 0x1727d4 <_Z15Split_TextBlockPKciP11TStringList+0x274>
 *   @0x1729ec ldr r12, [sp, #0x4]
 *   @0x1729f0 add r2, r12, r5, lsl #1
 *   @0x1729f4 ldrh r1, [r2, #2]!
 *   @0x1729f8 movw r3, #0xffdf
 *   @0x1729fc add r5, r5, #1
 *   @0x172a00 and r3, r1, r3
 *   @0x172a04 cmp r3, #0
 *   @0x172a08 bne 0x1729f4 <_Z15Split_TextBlockPKciP11TStringList+0x494>
 *   @0x172a0c ldr r12, [sp, #0x8]
 *   @0x172a10 cmp r5, r12
 *   @0x172a14 beq 0x1727d4 <_Z15Split_TextBlockPKciP11TStringList+0x274>
 *   @0x172a18 b 0x172904 <_Z15Split_TextBlockPKciP11TStringList+0x3a4>
 *   @0x172a1c cmp r4, #13
 *   @0x172a20 bne 0x172984 <_Z15Split_TextBlockPKciP11TStringList+0x424>
 *   @0x172a24 add r4, r5, #1
 *   @0x172a28 mov r9, #10
 *   @0x172a2c b 0x1727dc <_Z15Split_TextBlockPKciP11TStringList+0x27c>
 *   @0x172a30 cmp r9, #10
 *   @0x172a34 beq 0x172a8c <_Z15Split_TextBlockPKciP11TStringList+0x52c>
 *   @0x172a38 cmp r9, #13
 *   @0x172a3c mov r5, r4
 *   @0x172a40 movne r4, r2
 *   @0x172a44 bne 0x172984 <_Z15Split_TextBlockPKciP11TStringList+0x424>
 *   @0x172a48 add r4, r5, #1
 *   @0x172a4c mov r9, #13
 *   @0x172a50 b 0x1727dc <_Z15Split_TextBlockPKciP11TStringList+0x27c>
 *   @0x172a54 mov r5, r4
 *   @0x172a58 b 0x1728b0 <_Z15Split_TextBlockPKciP11TStringList+0x350>
 *   @0x172a5c ldr r12, [sp, #0x4]
 *   @0x172a60 mov r5, r4
 *   @0x172a64 add r3, r12, r2
 *   @0x172a68 ldrh r4, [r12, r2]
 *   @0x172a6c b 0x17296c <_Z15Split_TextBlockPKciP11TStringList+0x40c>
 *   @0x172a70 ldr r12, [sp, #0x4]
 *   @0x172a74 ldr r0, [sp, #0xc]
 *   @0x172a78 strh r4, [r12]
 *   @0x172a7c str r12, [r0, #0xc]
 *   @0x172a80 b 0x1727e8 <_Z15Split_TextBlockPKciP11TStringList+0x288>
 *   @0x172a84 mov r4, r5
 *   @0x172a88 b 0x1726d4 <_Z15Split_TextBlockPKciP11TStringList+0x174>
 *   @0x172a8c mov r5, r4
 *   @0x172a90 mov r4, #10
 *   @0x172a94 b 0x172984 <_Z15Split_TextBlockPKciP11TStringList+0x424>
 *   @0x172a98 mov r5, r4
 *   @0x172a9c mov r4, #13
 *   @0x172aa0 b 0x172984 <_Z15Split_TextBlockPKciP11TStringList+0x424>
 *   @0x172aa4 cmp r9, #10
 *   @0x172aa8 bne 0x172a98 <_Z15Split_TextBlockPKciP11TStringList+0x538>
 *   @0x172aac mov r5, r4
 *   @0x172ab0 b 0x172a24 <_Z15Split_TextBlockPKciP11TStringList+0x4c4>
 *   @0x172ab4 andseq r8, sp, r4, lsr #29
 *   @0x172ab8 andseq r8, sp, r4, ror #28
 *   @0x172abc andseq r8, sp, r4, asr lr
 *   @0x172ac0 andseq r8, sp, r8, asr #28
 *   @0x172ac4 eoreq sp, r7, r8, ror r10
 *
 * ══ §6/23 jpeg_idct_ifast  0x2bfe54  size 1380  345 条（0x2bfe54..0x2c03b8）
 * @func 0x2bfe54 0x2c03b8  size 1380  345 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x10×13 / 0xc×13 / 0x18×13 / 0x20×11 / 0x1c×10 / 0x14×9 / 0x50×5 / 0x60×5
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bfe54 ldr r12, [r0, #0x120]
 *   @0x2bfe58 ldr r0, [r1, #0x50]
 *   @0x2bfe5c push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2bfe60 sub sp, sp, #296
 *   @0x2bfe64 add r1, sp, #40
 *   @0x2bfe68 add r12, r12, #128
 *   @0x2bfe6c str r1, [sp, #0x20]
 *   @0x2bfe70 add r4, r0, #4
 *   @0x2bfe74 mov r1, r2
 *   @0x2bfe78 str r3, [sp, #0x1c]
 *   @0x2bfe7c add r2, r2, #2
 *   @0x2bfe80 str r12, [sp, #0x24]
 *   @0x2bfe84 str r2, [sp, #0x10]
 *   @0x2bfe88 add r3, sp, #40
 *   @0x2bfe8c add r2, r1, #16
 *   @0x2bfe90 str r4, [sp, #0xc]
 *   @0x2bfe94 str r2, [sp, #0x18]
 *   @0x2bfe98 mov r2, r0
 *   @0x2bfe9c b 0x2c0034 <jpeg_idct_ifast+0x1e0>
 *   @0x2bfea0 cmp r8, #0
 *   @0x2bfea4 bne 0x2c0044 <jpeg_idct_ifast+0x1f0>
 *   @0x2bfea8 ldrh r10, [r1, #48]
 *   @0x2bfeac ldrh r4, [r1, #64]
 *   @0x2bfeb0 cmp r10, #0
 *   @0x2bfeb4 beq 0x2c0254 <jpeg_idct_ifast+0x400>
 *   @0x2bfeb8 ldrh r7, [r1, #96]
 *   @0x2bfebc mov r8, r0
 *   @0x2bfec0 ldrh r5, [r1, #80]
 *   @0x2bfec4 ldrh r9, [r1, #112]
 *   @0x2bfec8 ldr r6, [r2, #0x60]
 *   @0x2bfecc sxth r10, r10
 *   @0x2bfed0 ldr r11, [r2, #0xa0]
 *   @0x2bfed4 sxth r0, r0
 *   @0x2bfed8 ldr r12, [r2, #0x20]
 *   @0x2bfedc sxth r5, r5
 *   @0x2bfee0 mul r10, r6, r10
 *   @0x2bfee4 ldr r6, [r2, #0xe0]
 *   @0x2bfee8 sxth r9, r9
 *   @0x2bfeec sxth r8, r8
 *   @0x2bfef0 mul r0, r12, r0
 *   @0x2bfef4 ldr r12, [r2, #0x40]
 *   @0x2bfef8 mul r9, r6, r9
 *   @0x2bfefc ldr r6, [r2, #0xc0]
 *   @0x2bff00 mul r5, r11, r5
 *   @0x2bff04 sxth r7, r7
 *   @0x2bff08 mul r8, r12, r8
 *   @0x2bff0c rsb r11, r9, r0
 *   @0x2bff10 rsb r12, r10, r5
 *   @0x2bff14 add r0, r0, r9
 *   @0x2bff18 mul r7, r6, r7
 *   @0x2bff1c add r6, r12, r11
 *   @0x2bff20 movw r9, #0x1d9
 *   @0x2bff24 add r5, r5, r10
 *   @0x2bff28 mul r6, r9, r6
 *   @0x2bff2c mvn r9, #668
 *   @0x2bff30 mul r12, r9, r12
 *   @0x2bff34 rsb r10, r5, r0
 *   @0x2bff38 add r0, r0, r5
 *   @0x2bff3c rsb r9, r7, r8
 *   @0x2bff40 sxth r4, r4
 *   @0x2bff44 add r7, r8, r7
 *   @0x2bff48 asr r6, r6, #8
 *   @0x2bff4c add r3, r3, #4
 *   @0x2bff50 str r12, [sp, #0x14]
 *   @0x2bff54 movw r12, #0x115
 *   @0x2bff58 mul r11, r12, r11
 *   @0x2bff5c add r12, r12, #85
 *   @0x2bff60 mul r10, r12, r10
 *   @0x2bff64 mul r9, r12, r9
 *   @0x2bff68 str r11, [sp, #0x4]
 *   @0x2bff6c ldr r11, [sp, #0x10]
 *   @0x2bff70 ldr r12, [r2, #0x80]
 *   @0x2bff74 ldr r8, [sp, #0x4]
 *   @0x2bff78 ldrsh r5, [r11, #-2]
 *   @0x2bff7c ldr r11, [sp, #0xc]
 *   @0x2bff80 rsb r9, r7, r9, asr #8
 *   @0x2bff84 mul r4, r12, r4
 *   @0x2bff88 ldr r11, [r11, #-0x4]
 *   @0x2bff8c str r11, [sp, #0x8]
 *   @0x2bff90 ldr r11, [sp, #0x14]
 *   @0x2bff94 add r12, r6, r11, asr #8
 *   @0x2bff98 ldr r11, [sp, #0x8]
 *   @0x2bff9c rsb r12, r0, r12
 *   @0x2bffa0 rsb r6, r6, r8, asr #8
 *   @0x2bffa4 rsb r10, r12, r10, asr #8
 *   @0x2bffa8 mul r5, r11, r5
 *   @0x2bffac add r6, r6, r10
 *   @0x2bffb0 add r8, r5, r4
 *   @0x2bffb4 rsb r4, r4, r5
 *   @0x2bffb8 rsb r11, r7, r8
 *   @0x2bffbc add r7, r8, r7
 *   @0x2bffc0 rsb r8, r9, r4
 *   @0x2bffc4 add r9, r4, r9
 *   @0x2bffc8 add r4, r11, r6
 *   @0x2bffcc rsb r6, r6, r11
 *   @0x2bffd0 str r4, [r3, #0x7c]
 *   @0x2bffd4 add r4, r8, r10
 *   @0x2bffd8 str r6, [r3, #0x5c]
 *   @0x2bffdc rsb r10, r10, r8
 *   @0x2bffe0 str r4, [r3, #0x3c]
 *   @0x2bffe4 add r4, r9, r12
 *   @0x2bffe8 str r10, [r3, #0x9c]
 *   @0x2bffec rsb r9, r12, r9
 *   @0x2bfff0 str r4, [r3, #0x1c]
 *   @0x2bfff4 add r12, r7, r0
 *   @0x2bfff8 str r9, [r3, #0xbc]
 *   @0x2bfffc rsb r7, r0, r7
 *   @0x2c0000 str r12, [r3, #-0x4]
 *   @0x2c0004 str r7, [r3, #0xdc]
 *   @0x2c0008 ldr r10, [sp, #0x18]
 *   @0x2c000c add r1, r1, #2
 *   @0x2c0010 ldr r9, [sp, #0x10]
 *   @0x2c0014 add r2, r2, #4
 *   @0x2c0018 ldr r11, [sp, #0xc]
 *   @0x2c001c cmp r1, r10
 *   @0x2c0020 add r9, r9, #2
 *   @0x2c0024 str r9, [sp, #0x10]
 *   @0x2c0028 add r11, r11, #4
 *   @0x2c002c str r11, [sp, #0xc]
 *   @0x2c0030 beq 0x2c005c <jpeg_idct_ifast+0x208>
 *   @0x2c0034 ldrh r0, [r1, #16]
 *   @0x2c0038 ldrh r8, [r1, #32]
 *   @0x2c003c cmp r0, #0
 *   @0x2c0040 beq 0x2bfea0 <jpeg_idct_ifast+0x4c>
 *   @0x2c0044 ldrh r4, [r1, #64]
 *   @0x2c0048 ldrh r7, [r1, #96]
 *   @0x2c004c ldrh r10, [r1, #48]
 *   @0x2c0050 ldrh r5, [r1, #80]
 *   @0x2c0054 ldrh r9, [r1, #112]
 *   @0x2c0058 b 0x2bfec8 <jpeg_idct_ifast+0x74>
 *   @0x2c005c add r6, sp, #40
 *   @0x2c0060 mov r12, #0
 *   @0x2c0064 ldr r2, [sp, #0x24]
 *   @0x2c0068 str r12, [sp, #0x10]
 *   @0x2c006c mov r8, r6
 *   @0x2c0070 b 0x2c01f4 <jpeg_idct_ifast+0x3a0>
 *   @0x2c0074 ldr r1, [r8, #0x8]
 *   @0x2c0078 cmp r1, #0
 *   @0x2c007c beq 0x2c0234 <jpeg_idct_ifast+0x3e0>
 *   @0x2c0080 ldr r12, [r8, #0x10]
 *   @0x2c0084 ldr r10, [r8, #0x18]
 *   @0x2c0088 ldr r11, [r8, #0x14]
 *   @0x2c008c ldr r5, [r8, #0xc]
 *   @0x2c0090 ldr r9, [r8, #0x1c]
 *   @0x2c0094 rsb r6, r9, r4
 *   @0x2c0098 rsb r0, r5, r11
 *   @0x2c009c add r11, r11, r5
 *   @0x2c00a0 add r5, r0, r6
 *   @0x2c00a4 str r6, [sp, #0x14]
 *   @0x2c00a8 rsb r6, r10, r1
 *   @0x2c00ac str r6, [sp, #0x20]
 *   @0x2c00b0 movw r6, #0x1d9
 *   @0x2c00b4 mul r5, r6, r5
 *   @0x2c00b8 ldr r7, [r8], #32
 *   @0x2c00bc add r9, r4, r9
 *   @0x2c00c0 add r1, r1, r10
 *   @0x2c00c4 add r4, r7, r12
 *   @0x2c00c8 rsb r7, r12, r7
 *   @0x2c00cc add r12, r9, r11
 *   @0x2c00d0 rsb r9, r11, r9
 *   @0x2c00d4 movw r10, #0x16a
 *   @0x2c00d8 str r5, [sp, #0x18]
 *   @0x2c00dc ldr r5, [sp, #0x20]
 *   @0x2c00e0 str r9, [sp, #0x20]
 *   @0x2c00e4 ldr r9, [sp, #0x18]
 *   @0x2c00e8 mul r6, r10, r5
 *   @0x2c00ec mvn r10, #668
 *   @0x2c00f0 asr r5, r9, #8
 *   @0x2c00f4 ldr r9, [sp, #0x20]
 *   @0x2c00f8 mul r0, r10, r0
 *   @0x2c00fc add r10, r4, r1
 *   @0x2c0100 add r11, r10, r12
 *   @0x2c0104 rsb r10, r12, r10
 *   @0x2c0108 ubfx r10, r10, #0x5, #0xa
 *   @0x2c010c str r10, [sp, #0x18]
 *   @0x2c0110 movw r10, #0x16a
 *   @0x2c0114 ubfx r11, r11, #0x5, #0xa
 *   @0x2c0118 mul r10, r10, r9
 *   @0x2c011c add r0, r5, r0, asr #8
 *   @0x2c0120 ldrb r11, [r2, r11]
 *   @0x2c0124 rsb r0, r12, r0
 *   @0x2c0128 ldr r9, [sp, #0x18]
 *   @0x2c012c rsb r6, r1, r6, asr #8
 *   @0x2c0130 ldr r12, [sp, #0xc]
 *   @0x2c0134 rsb r1, r1, r4
 *   @0x2c0138 str r10, [sp, #0x20]
 *   @0x2c013c ldr r10, [sp, #0x148]
 *   @0x2c0140 strb r11, [r12, r10]
 *   @0x2c0144 movw r11, #0x115
 *   @0x2c0148 ldrb r9, [r2, r9]
 *   @0x2c014c add r12, r7, r6
 *   @0x2c0150 add r10, r12, r0
 *   @0x2c0154 rsb r12, r0, r12
 *   @0x2c0158 ubfx r10, r10, #0x5, #0xa
 *   @0x2c015c ubfx r12, r12, #0x5, #0xa
 *   @0x2c0160 str r9, [sp, #0x18]
 *   @0x2c0164 rsb r6, r6, r7
 *   @0x2c0168 ldr r9, [sp, #0x14]
 *   @0x2c016c mul r11, r11, r9
 *   @0x2c0170 ldr r9, [sp, #0x20]
 *   @0x2c0174 rsb r0, r0, r9, asr #8
 *   @0x2c0178 add r9, r6, r0
 *   @0x2c017c rsb r6, r0, r6
 *   @0x2c0180 str r11, [sp, #0xc]
 *   @0x2c0184 ubfx r9, r9, #0x5, #0xa
 *   @0x2c0188 ldr r11, [sp, #0x18]
 *   @0x2c018c ubfx r6, r6, #0x5, #0xa
 *   @0x2c0190 strb r11, [r3, #0x7]
 *   @0x2c0194 ldrb r10, [r2, r10]
 *   @0x2c0198 strb r10, [r3, #0x1]
 *   @0x2c019c ldrb r12, [r2, r12]
 *   @0x2c01a0 ldr r10, [sp, #0xc]
 *   @0x2c01a4 strb r12, [r3, #0x6]
 *   @0x2c01a8 ldrb r7, [r2, r9]
 *   @0x2c01ac rsb r5, r5, r10, asr #8
 *   @0x2c01b0 add r0, r5, r0
 *   @0x2c01b4 add r12, r1, r0
 *   @0x2c01b8 rsb r0, r0, r1
 *   @0x2c01bc strb r7, [r3, #0x2]
 *   @0x2c01c0 ubfx r12, r12, #0x5, #0xa
 *   @0x2c01c4 ldrb r1, [r2, r6]
 *   @0x2c01c8 ubfx r0, r0, #0x5, #0xa
 *   @0x2c01cc strb r1, [r3, #0x5]
 *   @0x2c01d0 ldrb r1, [r2, r12]
 *   @0x2c01d4 strb r1, [r3, #0x4]
 *   @0x2c01d8 ldrb r1, [r2, r0]
 *   @0x2c01dc strb r1, [r3, #0x3]
 *   @0x2c01e0 ldr r11, [sp, #0x10]
 *   @0x2c01e4 add r11, r11, #4
 *   @0x2c01e8 str r11, [sp, #0x10]
 *   @0x2c01ec cmp r11, #32
 *   @0x2c01f0 beq 0x2c0274 <jpeg_idct_ifast+0x420>
 *   @0x2c01f4 ldr r1, [sp, #0x1c]
 *   @0x2c01f8 ldr r0, [sp, #0x10]
 *   @0x2c01fc ldr r4, [r8, #0x4]
 *   @0x2c0200 ldr r5, [sp, #0x148]
 *   @0x2c0204 ldr r0, [r1, r0]
 *   @0x2c0208 cmp r4, #0
 *   @0x2c020c add r3, r0, r5
 *   @0x2c0210 str r0, [sp, #0xc]
 *   @0x2c0214 beq 0x2c0074 <jpeg_idct_ifast+0x220>
 *   @0x2c0218 ldr r12, [r8, #0x10]
 *   @0x2c021c ldr r1, [r8, #0x8]
 *   @0x2c0220 ldr r10, [r8, #0x18]
 *   @0x2c0224 ldr r11, [r8, #0x14]
 *   @0x2c0228 ldr r5, [r8, #0xc]
 *   @0x2c022c ldr r9, [r8, #0x1c]
 *   @0x2c0230 b 0x2c0094 <jpeg_idct_ifast+0x240>
 *   @0x2c0234 ldr r5, [r8, #0xc]
 *   @0x2c0238 ldr r12, [r8, #0x10]
 *   @0x2c023c cmp r5, #0
 *   @0x2c0240 beq 0x2c0280 <jpeg_idct_ifast+0x42c>
 *   @0x2c0244 ldr r10, [r8, #0x18]
 *   @0x2c0248 ldr r11, [r8, #0x14]
 *   @0x2c024c ldr r9, [r8, #0x1c]
 *   @0x2c0250 b 0x2c0094 <jpeg_idct_ifast+0x240>
 *   @0x2c0254 cmp r4, #0
 *   @0x2c0258 beq 0x2c029c <jpeg_idct_ifast+0x448>
 *   @0x2c025c ldrh r7, [r1, #96]
 *   @0x2c0260 mov r10, r0
 *   @0x2c0264 ldrh r5, [r1, #80]
 *   @0x2c0268 mov r8, r0
 *   @0x2c026c ldrh r9, [r1, #112]
 *   @0x2c0270 b 0x2bfec8 <jpeg_idct_ifast+0x74>
 *   @0x2c0274 add sp, sp, #296
 *   @0x2c0278 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2c027c bx lr
 *   @0x2c0280 cmp r12, #0
 *   @0x2c0284 beq 0x2c02fc <jpeg_idct_ifast+0x4a8>
 *   @0x2c0288 ldr r10, [r8, #0x18]
 *   @0x2c028c mov r1, r5
 *   @0x2c0290 ldr r11, [r8, #0x14]
 *   @0x2c0294 ldr r9, [r8, #0x1c]
 *   @0x2c0298 b 0x2c0094 <jpeg_idct_ifast+0x240>
 *   @0x2c029c ldrh r5, [r1, #80]
 *   @0x2c02a0 ldrh r7, [r1, #96]
 *   @0x2c02a4 cmp r5, #0
 *   @0x2c02a8 ldrh r9, [r1, #112]
 *   @0x2c02ac bne 0x2c035c <jpeg_idct_ifast+0x508>
 *   @0x2c02b0 cmp r7, #0
 *   @0x2c02b4 bne 0x2c0358 <jpeg_idct_ifast+0x504>
 *   @0x2c02b8 cmp r9, #0
 *   @0x2c02bc bne 0x2c03a0 <jpeg_idct_ifast+0x54c>
 *   @0x2c02c0 ldr r5, [sp, #0x10]
 *   @0x2c02c4 add r3, r3, #4
 *   @0x2c02c8 ldr r6, [sp, #0xc]
 *   @0x2c02cc ldrsh r0, [r5, #-2]
 *   @0x2c02d0 ldr r12, [r6, #-0x4]
 *   @0x2c02d4 mul r0, r12, r0
 *   @0x2c02d8 str r0, [r3, #-0x4]
 *   @0x2c02dc str r0, [r3, #0x1c]
 *   @0x2c02e0 str r0, [r3, #0x3c]
 *   @0x2c02e4 str r0, [r3, #0x5c]
 *   @0x2c02e8 str r0, [r3, #0x7c]
 *   @0x2c02ec str r0, [r3, #0x9c]
 *   @0x2c02f0 str r0, [r3, #0xbc]
 *   @0x2c02f4 str r0, [r3, #0xdc]
 *   @0x2c02f8 b 0x2c0008 <jpeg_idct_ifast+0x1b4>
 *   @0x2c02fc ldr r11, [r8, #0x14]
 *   @0x2c0300 ldr r10, [r8, #0x18]
 *   @0x2c0304 cmp r11, #0
 *   @0x2c0308 bne 0x2c036c <jpeg_idct_ifast+0x518>
 *   @0x2c030c cmp r10, #0
 *   @0x2c0310 ldr r9, [r8, #0x1c]
 *   @0x2c0314 bne 0x2c037c <jpeg_idct_ifast+0x528>
 *   @0x2c0318 cmp r9, #0
 *   @0x2c031c bne 0x2c038c <jpeg_idct_ifast+0x538>
 *   @0x2c0320 ldr r1, [r8], #32
 *   @0x2c0324 ldr r7, [sp, #0xc]
 *   @0x2c0328 ubfx r1, r1, #0x5, #0xa
 *   @0x2c032c ldr r6, [sp, #0x148]
 *   @0x2c0330 ldrb r1, [r2, r1]
 *   @0x2c0334 strb r1, [r7, r6]
 *   @0x2c0338 strb r1, [r3, #0x1]
 *   @0x2c033c strb r1, [r3, #0x2]
 *   @0x2c0340 strb r1, [r3, #0x3]
 *   @0x2c0344 strb r1, [r3, #0x4]
 *   @0x2c0348 strb r1, [r3, #0x5]
 *   @0x2c034c strb r1, [r3, #0x6]
 *   @0x2c0350 strb r1, [r3, #0x7]
 *   @0x2c0354 b 0x2c01e0 <jpeg_idct_ifast+0x38c>
 *   @0x2c0358 mov r5, r0
 *   @0x2c035c mov r10, r0
 *   @0x2c0360 mov r4, r0
 *   @0x2c0364 mov r8, r0
 *   @0x2c0368 b 0x2bfec8 <jpeg_idct_ifast+0x74>
 *   @0x2c036c mov r5, r12
 *   @0x2c0370 ldr r9, [r8, #0x1c]
 *   @0x2c0374 mov r1, r12
 *   @0x2c0378 b 0x2c0094 <jpeg_idct_ifast+0x240>
 *   @0x2c037c mov r5, r11
 *   @0x2c0380 mov r1, r11
 *   @0x2c0384 mov r12, r11
 *   @0x2c0388 b 0x2c0094 <jpeg_idct_ifast+0x240>
 *   @0x2c038c mov r5, r10
 *   @0x2c0390 mov r11, r10
 *   @0x2c0394 mov r1, r10
 *   @0x2c0398 mov r12, r10
 *   @0x2c039c b 0x2c0094 <jpeg_idct_ifast+0x240>
 *   @0x2c03a0 mov r5, r0
 *   @0x2c03a4 mov r10, r0
 *   @0x2c03a8 mov r7, r0
 *   @0x2c03ac mov r4, r0
 *   @0x2c03b0 mov r8, r0
 *   @0x2c03b4 b 0x2bfec8 <jpeg_idct_ifast+0x74>
 *
 * ══ §7/23 F_VMGetCallStack(RValue&, CInstance*, CInstance*, int, RValue*)  0xe52cc  size 1348  337 条（0xe52cc..0xe5810）
 * @func 0xe52cc 0xe5810  size 1348  337 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYFree(void const*)×5 / YYAlloc(int)×4 / 0xb65bc×4 / YYCreateString(RValue*, char const*)×4 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / VM::DebugInfo(VMBuffer*, int)×2 / VM::DebugLineNumber(VMDebugInfo*, char const*, char**)×2 / 0xb6538×2
 * 字段偏移 top8: 0x4×19 / 0x2c×19 / 0x24×16 / 0x28×14 / 0x20×4 / 0x14×4 / 0xc×3 / 0x1c×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xe52cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xe52d0 mov r11, r0
 *   @0xe52d4 ldr r4, [pc, #0x520]
 *   @0xe52d8 sub sp, sp, #52
 *   @0xe52dc ldr r4, [pc, r4]
 *   @0xe52e0 ldr r3, [r4]
 *   @0xe52e4 cmp r3, #0
 *   @0xe52e8 beq 0xe57f0 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x524>
 *   @0xe52ec mov r2, #0
 *   @0xe52f0 ldr r1, [r3, #0x4c]
 *   @0xe52f4 add r2, r2, #1
 *   @0xe52f8 ldr r3, [r3, #0x4]
 *   @0xe52fc add r2, r2, r1
 *   @0xe5300 cmp r3, #0
 *   @0xe5304 bne 0xe52f0 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x24>
 *   @0xe5308 add r7, r2, #1
 *   @0xe530c lsl r8, r7, #4
 *   @0xe5310 mov r3, #2
 *   @0xe5314 mov r0, r11
 *   @0xe5318 str r3, [r11, #0xc]
 *   @0xe531c mov r6, #1
 *   @0xe5320 bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0xe5324 ldr r1, [pc, #0x4d4]
 *   @0xe5328 mov r3, r6
 *   @0xe532c mov r2, #70
 *   @0xe5330 add r1, pc, r1
 *   @0xe5334 mov r9, #0
 *   @0xe5338 mov r5, r0
 *   @0xe533c str r0, [r11]
 *   @0xe5340 str r6, [r5, #0x10]
 *   @0xe5344 mov r0, #8
 *   @0xe5348 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xe534c ldr r1, [pc, #0x4b0]
 *   @0xe5350 mov r3, r6
 *   @0xe5354 movw r2, #0x299f
 *   @0xe5358 add r1, pc, r1
 *   @0xe535c str r0, [r5, #0x4]
 *   @0xe5360 mov r0, r8
 *   @0xe5364 ldr r12, [r11]
 *   @0xe5368 ldr r5, [r12, #0x4]
 *   @0xe536c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xe5370 ldr r4, [r4]
 *   @0xe5374 cmp r4, r9
 *   @0xe5378 str r0, [r5, #0x4]
 *   @0xe537c ldr r3, [r11]
 *   @0xe5380 ldr r3, [r3, #0x4]
 *   @0xe5384 str r7, [r3]
 *   @0xe5388 str r9, [sp, #0x24]
 *   @0xe538c str r9, [sp, #0x28]
 *   @0xe5390 str r9, [sp, #0x2c]
 *   @0xe5394 beq 0xe55c4 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x2f8>
 *   @0xe5398 ldr r3, [pc, #0x468]
 *   @0xe539c mov r10, r9
 *   @0xe53a0 str r11, [sp, #0x4]
 *   @0xe53a4 add r3, pc, r3
 *   @0xe53a8 str r3, [sp, #0x1c]
 *   @0xe53ac ldr r3, [pc, #0x458]
 *   @0xe53b0 add r3, pc, r3
 *   @0xe53b4 str r3, [sp, #0x18]
 *   @0xe53b8 add r3, sp, #32
 *   @0xe53bc str r3, [sp, #0xc]
 *   @0xe53c0 add r3, sp, #36
 *   @0xe53c4 str r3, [sp, #0x10]
 *   @0xe53c8 ldr r0, [r4, #0x38]
 *   @0xe53cc str r10, [sp, #0x20]
 *   @0xe53d0 cmp r0, #0
 *   @0xe53d4 beq 0xe57a0 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x4d4>
 *   @0xe53d8 ldr r1, [r4, #0x54]
 *   @0xe53dc bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi>
 *   @0xe53e0 ldr r1, [r4, #0x3c]
 *   @0xe53e4 add r2, sp, #32
 *   @0xe53e8 bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc>
 *   @0xe53ec ldr r8, [r4, #0x34]
 *   @0xe53f0 cmp r8, #0
 *   @0xe53f4 ldreq r5, [sp, #0x2c]
 *   @0xe53f8 mov r6, r0
 *   @0xe53fc beq 0xe54a0 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0xe5400 mov r0, r8
 *   @0xe5404 bl 0xb6538 <strlen@plt>
 *   @0xe5408 ldr r2, [sp, #0x2c]
 *   @0xe540c ldr r3, [sp, #0x28]
 *   @0xe5410 add r1, r0, #1
 *   @0xe5414 mov r5, r0
 *   @0xe5418 mvn r0, r2
 *   @0xe541c add r0, r3, r0
 *   @0xe5420 cmp r1, r0
 *   @0xe5424 ble 0xe5484 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0xe5428 cmp r3, #0
 *   @0xe542c add r2, r1, r2
 *   @0xe5430 ldr r7, [sp, #0x24]
 *   @0xe5434 moveq r3, r1
 *   @0xe5438 add r3, r3, r3, lsl #1
 *   @0xe543c add r3, r3, r3, lsr #31
 *   @0xe5440 asr r11, r3, #1
 *   @0xe5444 cmp r11, r2
 *   @0xe5448 addlt r2, r2, r2, lsl #1
 *   @0xe544c addlt r2, r2, r2, lsr #31
 *   @0xe5450 asrlt r11, r2, #1
 *   @0xe5454 mov r0, r11
 *   @0xe5458 bl 0xcef4c <_Z7YYAlloci>
 *   @0xe545c ldr r2, [sp, #0x28]
 *   @0xe5460 mov r1, r7
 *   @0xe5464 str r0, [sp, #0x24]
 *   @0xe5468 bl 0xb65bc <memcpy@plt>
 *   @0xe546c cmp r7, #0
 *   @0xe5470 str r11, [sp, #0x28]
 *   @0xe5474 beq 0xe5480 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0xe5478 mov r0, r7
 *   @0xe547c bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe5480 ldr r2, [sp, #0x2c]
 *   @0xe5484 ldr r0, [sp, #0x24]
 *   @0xe5488 mov r1, r8
 *   @0xe548c add r0, r0, r2
 *   @0xe5490 bl 0xb65a4 <strcpy@plt>
 *   @0xe5494 ldr r3, [sp, #0x2c]
 *   @0xe5498 add r5, r5, r3
 *   @0xe549c str r5, [sp, #0x2c]
 *   @0xe54a0 ldr r3, [sp, #0x28]
 *   @0xe54a4 mvn r2, r5
 *   @0xe54a8 add r2, r3, r2
 *   @0xe54ac cmp r2, #1
 *   @0xe54b0 bgt 0xe5510 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x244>
 *   @0xe54b4 cmp r3, #0
 *   @0xe54b8 add r5, r5, #2
 *   @0xe54bc addne r3, r3, r3, lsl #1
 *   @0xe54c0 moveq r7, #3
 *   @0xe54c4 addne r3, r3, r3, lsr #31
 *   @0xe54c8 asrne r7, r3, #1
 *   @0xe54cc cmp r5, r7
 *   @0xe54d0 addgt r5, r5, r5, lsl #1
 *   @0xe54d4 addgt r5, r5, r5, lsr #31
 *   @0xe54d8 asrgt r7, r5, #1
 *   @0xe54dc ldr r5, [sp, #0x24]
 *   @0xe54e0 mov r0, r7
 *   @0xe54e4 bl 0xcef4c <_Z7YYAlloci>
 *   @0xe54e8 ldr r2, [sp, #0x28]
 *   @0xe54ec mov r1, r5
 *   @0xe54f0 str r0, [sp, #0x24]
 *   @0xe54f4 bl 0xb65bc <memcpy@plt>
 *   @0xe54f8 cmp r5, #0
 *   @0xe54fc str r7, [sp, #0x28]
 *   @0xe5500 beq 0xe550c <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x240>
 *   @0xe5504 mov r0, r5
 *   @0xe5508 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe550c ldr r5, [sp, #0x2c]
 *   @0xe5510 ldr r0, [sp, #0x1c]
 *   @0xe5514 mov r1, r6
 *   @0xe5518 ldr r3, [sp, #0x24]
 *   @0xe551c add r8, r9, #1
 *   @0xe5520 ldrh r2, [r0]
 *   @0xe5524 add r0, sp, #36
 *   @0xe5528 strh r2, [r3, r5]
 *   @0xe552c ldr r3, [sp, #0x2c]
 *   @0xe5530 add r3, r3, #1
 *   @0xe5534 str r3, [sp, #0x2c]
 *   @0xe5538 bl 0xd58c4 <_ZN12YYStrBuilderlsEi>
 *   @0xe553c ldr r2, [sp, #0x4]
 *   @0xe5540 ldr r3, [r2]
 *   @0xe5544 ldr r2, [sp, #0x2c]
 *   @0xe5548 ldr r3, [r3, #0x4]
 *   @0xe554c cmp r2, #0
 *   @0xe5550 addeq r1, sp, #44
 *   @0xe5554 ldrne r1, [sp, #0x24]
 *   @0xe5558 ldr r0, [r3, #0x4]
 *   @0xe555c str r10, [sp, #0x2c]
 *   @0xe5560 add r0, r0, r9, lsl #4
 *   @0xe5564 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xe5568 ldr r5, [r4, #0x28]
 *   @0xe556c add r7, r8, #1
 *   @0xe5570 ldr r6, [r4, #0x4c]
 *   @0xe5574 lsl r11, r8, #4
 *   @0xe5578 cmp r6, #0
 *   @0xe557c sub r9, r7, #1
 *   @0xe5580 ble 0xe5594 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x2c8>
 *   @0xe5584 ldr r3, [r5, #0x18]
 *   @0xe5588 cmp r3, #0
 *   @0xe558c bne 0xe55cc <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x300>
 *   @0xe5590 b 0xe5590 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x2c4>
 *   @0xe5594 cmp r9, #49
 *   @0xe5598 ldr r4, [r4, #0x4]
 *   @0xe559c movgt r3, #0
 *   @0xe55a0 movle r3, #1
 *   @0xe55a4 cmp r4, #0
 *   @0xe55a8 moveq r3, #0
 *   @0xe55ac cmp r3, #0
 *   @0xe55b0 bne 0xe53c8 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0xe55b4 ldr r0, [sp, #0x24]
 *   @0xe55b8 cmp r0, #0
 *   @0xe55bc beq 0xe55c4 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x2f8>
 *   @0xe55c0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe55c4 add sp, sp, #52
 *   @0xe55c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xe55cc ldr r0, [r5, #0x1c]
 *   @0xe55d0 cmp r0, #0
 *   @0xe55d4 beq 0xe57d0 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x504>
 *   @0xe55d8 ldr r1, [r5]
 *   @0xe55dc bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi>
 *   @0xe55e0 ldr r1, [r5, #0x20]
 *   @0xe55e4 add r2, sp, #32
 *   @0xe55e8 str r10, [sp, #0x20]
 *   @0xe55ec bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc>
 *   @0xe55f0 ldr r9, [r5, #0x24]
 *   @0xe55f4 str r10, [sp, #0x2c]
 *   @0xe55f8 cmp r9, #0
 *   @0xe55fc str r0, [sp, #0x8]
 *   @0xe5600 beq 0xe57c4 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x4f8>
 *   @0xe5604 mov r0, r9
 *   @0xe5608 bl 0xb6538 <strlen@plt>
 *   @0xe560c ldr r3, [sp, #0x28]
 *   @0xe5610 add r2, r0, #1
 *   @0xe5614 mov r8, r0
 *   @0xe5618 cmp r2, r3
 *   @0xe561c movlt r0, #0
 *   @0xe5620 blt 0xe568c <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x3c0>
 *   @0xe5624 cmp r3, #0
 *   @0xe5628 moveq r3, r2
 *   @0xe562c add r3, r3, r3, lsl #1
 *   @0xe5630 add r3, r3, r3, lsr #31
 *   @0xe5634 asr r3, r3, #1
 *   @0xe5638 cmp r2, r3
 *   @0xe563c addgt r2, r2, r2, lsl #1
 *   @0xe5640 addgt r2, r2, r2, lsr #31
 *   @0xe5644 asrgt r3, r2, #1
 *   @0xe5648 ldr r2, [sp, #0x24]
 *   @0xe564c str r3, [sp]
 *   @0xe5650 mov r0, r3
 *   @0xe5654 str r2, [sp, #0x14]
 *   @0xe5658 bl 0xcef4c <_Z7YYAlloci>
 *   @0xe565c ldr r2, [sp, #0x28]
 *   @0xe5660 ldr r1, [sp, #0x14]
 *   @0xe5664 str r0, [sp, #0x24]
 *   @0xe5668 bl 0xb65bc <memcpy@plt>
 *   @0xe566c ldr r0, [sp, #0x14]
 *   @0xe5670 ldr r3, [sp]
 *   @0xe5674 cmp r0, #0
 *   @0xe5678 str r3, [sp, #0x28]
 *   @0xe567c beq 0xe5688 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x3bc>
 *   @0xe5680 ldr r0, [sp, #0x14]
 *   @0xe5684 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe5688 ldr r0, [sp, #0x2c]
 *   @0xe568c ldr r3, [sp, #0x24]
 *   @0xe5690 mov r1, r9
 *   @0xe5694 add r0, r3, r0
 *   @0xe5698 bl 0xb65a4 <strcpy@plt>
 *   @0xe569c ldr r3, [sp, #0x2c]
 *   @0xe56a0 add r8, r8, r3
 *   @0xe56a4 str r8, [sp, #0x2c]
 *   @0xe56a8 mvn r2, r8
 *   @0xe56ac ldr r3, [sp, #0x28]
 *   @0xe56b0 add r2, r3, r2
 *   @0xe56b4 cmp r2, #1
 *   @0xe56b8 bgt 0xe5718 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x44c>
 *   @0xe56bc cmp r3, #0
 *   @0xe56c0 add r8, r8, #2
 *   @0xe56c4 addne r3, r3, r3, lsl #1
 *   @0xe56c8 moveq r9, #3
 *   @0xe56cc addne r3, r3, r3, lsr #31
 *   @0xe56d0 asrne r9, r3, #1
 *   @0xe56d4 cmp r8, r9
 *   @0xe56d8 addgt r8, r8, r8, lsl #1
 *   @0xe56dc addgt r8, r8, r8, lsr #31
 *   @0xe56e0 asrgt r9, r8, #1
 *   @0xe56e4 ldr r8, [sp, #0x24]
 *   @0xe56e8 mov r0, r9
 *   @0xe56ec bl 0xcef4c <_Z7YYAlloci>
 *   @0xe56f0 ldr r2, [sp, #0x28]
 *   @0xe56f4 mov r1, r8
 *   @0xe56f8 str r0, [sp, #0x24]
 *   @0xe56fc bl 0xb65bc <memcpy@plt>
 *   @0xe5700 cmp r8, #0
 *   @0xe5704 str r9, [sp, #0x28]
 *   @0xe5708 beq 0xe5714 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x448>
 *   @0xe570c mov r0, r8
 *   @0xe5710 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xe5714 ldr r8, [sp, #0x2c]
 *   @0xe5718 ldr r0, [sp, #0x18]
 *   @0xe571c ldr r3, [sp, #0x24]
 *   @0xe5720 ldr r1, [sp, #0x8]
 *   @0xe5724 ldrh r2, [r0]
 *   @0xe5728 add r0, sp, #36
 *   @0xe572c strh r2, [r3, r8]
 *   @0xe5730 ldr r3, [sp, #0x2c]
 *   @0xe5734 add r3, r3, #1
 *   @0xe5738 str r3, [sp, #0x2c]
 *   @0xe573c bl 0xd58c4 <_ZN12YYStrBuilderlsEi>
 *   @0xe5740 ldr r2, [sp, #0x4]
 *   @0xe5744 ldr r3, [r2]
 *   @0xe5748 ldr r2, [sp, #0x2c]
 *   @0xe574c ldr r3, [r3, #0x4]
 *   @0xe5750 cmp r2, #0
 *   @0xe5754 addeq r1, sp, #44
 *   @0xe5758 ldrne r1, [sp, #0x24]
 *   @0xe575c ldr r0, [r3, #0x4]
 *   @0xe5760 str r10, [sp, #0x2c]
 *   @0xe5764 add r0, r0, r11
 *   @0xe5768 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xe576c ldr r0, [sp, #0x20]
 *   @0xe5770 cmp r0, #0
 *   @0xe5774 beq 0xe577c <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x4b0>
 *   @0xe5778 bl 0xb655c <free@plt>
 *   @0xe577c ldr r3, [r5, #0xc]
 *   @0xe5780 sub r6, r6, #1
 *   @0xe5784 ldr r2, [r4, #0x40]
 *   @0xe5788 add r7, r7, #1
 *   @0xe578c ldr r5, [r4, #0x8]
 *   @0xe5790 add r11, r11, #16
 *   @0xe5794 rsb r3, r3, r2
 *   @0xe5798 add r5, r5, r3
 *   @0xe579c b 0xe5578 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x2ac>
 *   @0xe57a0 ldr r0, [sp, #0x4]
 *   @0xe57a4 add r8, r9, #1
 *   @0xe57a8 ldr r1, [r4, #0x34]
 *   @0xe57ac ldr r3, [r0]
 *   @0xe57b0 ldr r3, [r3, #0x4]
 *   @0xe57b4 ldr r0, [r3, #0x4]
 *   @0xe57b8 add r0, r0, r9, lsl #4
 *   @0xe57bc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xe57c0 b 0xe5568 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0xe57c4 mov r8, r9
 *   @0xe57c8 mvn r2, #0
 *   @0xe57cc b 0xe56ac <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x3e0>
 *   @0xe57d0 ldr r0, [sp, #0x4]
 *   @0xe57d4 ldr r1, [r5, #0x24]
 *   @0xe57d8 ldr r3, [r0]
 *   @0xe57dc ldr r3, [r3, #0x4]
 *   @0xe57e0 ldr r0, [r3, #0x4]
 *   @0xe57e4 add r0, r0, r11
 *   @0xe57e8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xe57ec b 0xe577c <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x4b0>
 *   @0xe57f0 mov r8, #16
 *   @0xe57f4 mov r7, #1
 *   @0xe57f8 b 0xe5310 <_Z16F_VMGetCallStackR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0xe57fc eorseq r8, r0, r12, asr #17
 *   @0xe5800 eoreq r11, r4, r0, lsl #26
 *   @0xe5804 eoreq sp, r4, r4, lsr #8
 *   @0xe5808 .word 0x0024d8f0
 *   @0xe580c eoreq sp, r4, r4, ror #17
 *
 * ══ §8/23 JS_RegExp(RValue&, CInstance*, CInstance*, int, RValue*)  0x259ea8  size 1344  336 条（0x259ea8..0x25a3e8）
 * @func 0x259ea8 0x25a3e8  size 1344  336 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYStrDup(char const*)×4 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×4 / YYGetString(RValue const*, int)×3 / YYObjectBase::Add(char const*, bool, int)×3 / JSThrowTypeError(char const*)×3 / YYGetBool(RValue const*, int)×3 / F_JS_ToString(RValue&, RValue*)×2 / YYFree(void const*)×2
 * 字段偏移 top8: 0x-84×7 / 0x-80×5 / 0x-88×5 / 0x-38×3 / 0x-34×3 / 0x-30×3 / 0x-2c×3 / 0x-28×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x259ea8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x259eac add r11, sp, #32
 *   @0x259eb0 ldr r5, [pc, #0x4e4]
 *   @0x259eb4 sub sp, sp, #116
 *   @0x259eb8 mov r4, r0
 *   @0x259ebc ldr r5, [pc, r5]
 *   @0x259ec0 ldr r7, [r11, #0x4]
 *   @0x259ec4 mov r8, r3
 *   @0x259ec8 mov r6, #5
 *   @0x259ecc ldr r12, [r5]
 *   @0x259ed0 str r7, [sp]
 *   @0x259ed4 str r12, [r11, #-0x28]
 *   @0x259ed8 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x259edc ldr r2, [pc, #0x4bc]
 *   @0x259ee0 ldr r4, [r4]
 *   @0x259ee4 ldr r2, [pc, r2]
 *   @0x259ee8 ldr r3, [pc, #0x4b4]
 *   @0x259eec ldr r1, [r2]
 *   @0x259ef0 add r3, pc, r3
 *   @0x259ef4 mov r0, r4
 *   @0x259ef8 str r3, [r4, #0x40]
 *   @0x259efc str r1, [r4, #0x18]
 *   @0x259f00 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x259f04 ldr r3, [r4, #0x28]
 *   @0x259f08 cmp r8, #0
 *   @0x259f0c mov r2, #0
 *   @0x259f10 orr r3, r3, #1
 *   @0x259f14 str r2, [r11, #-0x78]
 *   @0x259f18 str r2, [r11, #-0x74]
 *   @0x259f1c str r3, [r4, #0x28]
 *   @0x259f20 str r2, [r11, #-0x70]
 *   @0x259f24 str r6, [r11, #-0x6c]
 *   @0x259f28 ble 0x25a1a0 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x2f8>
 *   @0x259f2c cmp r8, #1
 *   @0x259f30 ldr r3, [r7, #0xc]
 *   @0x259f34 subeq r9, r11, #120
 *   @0x259f38 addne r9, r7, #16
 *   @0x259f3c ldrne r6, [r7, #0x1c]
 *   @0x259f40 biceq r3, r3, #-16777216
 *   @0x259f44 bicne r3, r3, #-16777216
 *   @0x259f48 bicne r6, r6, #-16777216
 *   @0x259f4c cmp r3, #6
 *   @0x259f50 beq 0x25a15c <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x2b4>
 *   @0x259f54 cmp r3, #5
 *   @0x259f58 beq 0x25a1a4 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x2fc>
 *   @0x259f5c sub r8, r11, #56
 *   @0x259f60 mov r1, r7
 *   @0x259f64 mvn r3, #-16777216
 *   @0x259f68 mov r7, #0
 *   @0x259f6c mov r0, r8
 *   @0x259f70 str r7, [r11, #-0x38]
 *   @0x259f74 str r7, [r11, #-0x34]
 *   @0x259f78 str r7, [r11, #-0x30]
 *   @0x259f7c str r3, [r11, #-0x2c]
 *   @0x259f80 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x259f84 cmp r0, #2
 *   @0x259f88 beq 0x25a144 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x259f8c cmp r0, #1
 *   @0x259f90 beq 0x25a1f0 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x348>
 *   @0x259f94 mov r1, r7
 *   @0x259f98 mov r0, r8
 *   @0x259f9c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x259fa0 cmp r6, #5
 *   @0x259fa4 mov r10, r0
 *   @0x259fa8 beq 0x25a1c0 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x318>
 *   @0x259fac mov r1, r9
 *   @0x259fb0 mov r0, r8
 *   @0x259fb4 mov r6, #0
 *   @0x259fb8 mvn r3, #-16777216
 *   @0x259fbc str r6, [r11, #-0x38]
 *   @0x259fc0 str r6, [r11, #-0x34]
 *   @0x259fc4 str r6, [r11, #-0x30]
 *   @0x259fc8 str r3, [r11, #-0x2c]
 *   @0x259fcc bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x259fd0 cmp r0, #2
 *   @0x259fd4 beq 0x25a144 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x259fd8 cmp r0, #1
 *   @0x259fdc beq 0x25a21c <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x259fe0 mov r1, r6
 *   @0x259fe4 mov r0, r8
 *   @0x259fe8 sub r12, r11, #72
 *   @0x259fec str r12, [r11, #-0x84]
 *   @0x259ff0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x259ff4 str r0, [r11, #-0x80]
 *   @0x259ff8 ldr r12, [r11, #-0x80]
 *   @0x259ffc ldrb r3, [r12]
 *   @0x25a000 cmp r3, #0
 *   @0x25a004 beq 0x25a1dc <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x334>
 *   @0x25a008 mov r2, #0
 *   @0x25a00c mov r1, r12
 *   @0x25a010 mov r7, r2
 *   @0x25a014 mov r6, r2
 *   @0x25a018 mov r9, r2
 *   @0x25a01c b 0x25a048 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x25a020 cmp r3, #109
 *   @0x25a024 beq 0x25a190 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x2e8>
 *   @0x25a028 cmp r3, #103
 *   @0x25a02c orreq r2, r9, r2
 *   @0x25a030 moveq r9, #1
 *   @0x25a034 uxtbeq r2, r2
 *   @0x25a038 movne r2, #1
 *   @0x25a03c ldrb r3, [r1, #0x1]!
 *   @0x25a040 cmp r3, #0
 *   @0x25a044 beq 0x25a068 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x1c0>
 *   @0x25a048 cmp r3, #105
 *   @0x25a04c bne 0x25a020 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x25a050 ldrb r3, [r1, #0x1]!
 *   @0x25a054 orr r2, r6, r2
 *   @0x25a058 mov r6, #1
 *   @0x25a05c cmp r3, #0
 *   @0x25a060 uxtb r2, r2
 *   @0x25a064 bne 0x25a048 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x25a068 cmp r2, #0
 *   @0x25a06c bne 0x25a200 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x358>
 *   @0x25a070 cmp r6, #0
 *   @0x25a074 movne r1, #1
 *   @0x25a078 movtne r1, #0x200
 *   @0x25a07c beq 0x25a1e8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x340>
 *   @0x25a080 cmp r7, #0
 *   @0x25a084 mov r3, r8
 *   @0x25a088 orrne r1, r1, #2
 *   @0x25a08c mov r8, #0
 *   @0x25a090 mov r0, r10
 *   @0x25a094 str r8, [sp]
 *   @0x25a098 ldr r2, [r11, #-0x84]
 *   @0x25a09c bl 0x268f88 <pcre_compile>
 *   @0x25a0a0 subs r3, r0, #0
 *   @0x25a0a4 beq 0x25a210 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x368>
 *   @0x25a0a8 str r3, [r4, #0x1c]
 *   @0x25a0ac mov r1, r8
 *   @0x25a0b0 ldr r2, [r11, #-0x84]
 *   @0x25a0b4 bl 0x2665e0 <pcre_study>
 *   @0x25a0b8 ldr r1, [pc, #0x2e8]
 *   @0x25a0bc mov r2, r10
 *   @0x25a0c0 mov r3, r8
 *   @0x25a0c4 add r1, pc, r1
 *   @0x25a0c8 str r0, [r4, #0x20]
 *   @0x25a0cc mov r0, r4
 *   @0x25a0d0 bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i>
 *   @0x25a0d4 ldr r1, [pc, #0x2d0]
 *   @0x25a0d8 mov r0, r4
 *   @0x25a0dc mov r2, r9
 *   @0x25a0e0 add r1, pc, r1
 *   @0x25a0e4 mov r3, r8
 *   @0x25a0e8 bl 0x1998e0 <_ZN12YYObjectBase3AddEPKcbi>
 *   @0x25a0ec ldr r1, [pc, #0x2bc]
 *   @0x25a0f0 mov r0, r4
 *   @0x25a0f4 mov r2, r6
 *   @0x25a0f8 add r1, pc, r1
 *   @0x25a0fc mov r3, r8
 *   @0x25a100 bl 0x1998e0 <_ZN12YYObjectBase3AddEPKcbi>
 *   @0x25a104 ldr r1, [pc, #0x2a8]
 *   @0x25a108 mov r0, r4
 *   @0x25a10c mov r2, r7
 *   @0x25a110 add r1, pc, r1
 *   @0x25a114 mov r3, r8
 *   @0x25a118 bl 0x1998e0 <_ZN12YYObjectBase3AddEPKcbi>
 *   @0x25a11c ldr r1, [pc, #0x294]
 *   @0x25a120 mov r0, r4
 *   @0x25a124 mov r2, r8
 *   @0x25a128 add r1, pc, r1
 *   @0x25a12c mov r3, #4
 *   @0x25a130 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii>
 *   @0x25a134 mov r0, r10
 *   @0x25a138 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x25a13c ldr r0, [r11, #-0x80]
 *   @0x25a140 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x25a144 ldr r2, [r11, #-0x28]
 *   @0x25a148 ldr r3, [r5]
 *   @0x25a14c cmp r2, r3
 *   @0x25a150 bne 0x25a398 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x4f0>
 *   @0x25a154 sub sp, r11, #32
 *   @0x25a158 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x25a15c ldr r8, [r7]
 *   @0x25a160 ldr r1, [pc, #0x254]
 *   @0x25a164 ldr r0, [r8, #0x40]
 *   @0x25a168 add r1, pc, r1
 *   @0x25a16c bl 0xb6574 <strcmp@plt>
 *   @0x25a170 subs r3, r0, #0
 *   @0x25a174 bne 0x259f5c <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x25a178 cmp r6, #5
 *   @0x25a17c beq 0x25a22c <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x384>
 *   @0x25a180 ldr r0, [pc, #0x238]
 *   @0x25a184 add r0, pc, r0
 *   @0x25a188 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25a18c b 0x25a144 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x25a190 orr r2, r7, r2
 *   @0x25a194 mov r7, #1
 *   @0x25a198 uxtb r2, r2
 *   @0x25a19c b 0x25a03c <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x25a1a0 sub r9, r11, #120
 *   @0x25a1a4 ldr r0, [pc, #0x218]
 *   @0x25a1a8 sub r8, r11, #56
 *   @0x25a1ac add r0, pc, r0
 *   @0x25a1b0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x25a1b4 cmp r6, #5
 *   @0x25a1b8 mov r10, r0
 *   @0x25a1bc bne 0x259fac <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x25a1c0 ldr r0, [pc, #0x200]
 *   @0x25a1c4 sub r12, r11, #72
 *   @0x25a1c8 str r12, [r11, #-0x84]
 *   @0x25a1cc add r0, pc, r0
 *   @0x25a1d0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x25a1d4 str r0, [r11, #-0x80]
 *   @0x25a1d8 b 0x259ff8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x25a1dc mov r6, r3
 *   @0x25a1e0 mov r7, r3
 *   @0x25a1e4 mov r9, r3
 *   @0x25a1e8 mov r1, #33554432
 *   @0x25a1ec b 0x25a080 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x1d8>
 *   @0x25a1f0 ldr r0, [pc, #0x1d4]
 *   @0x25a1f4 add r0, pc, r0
 *   @0x25a1f8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25a1fc b 0x25a144 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x25a200 ldr r0, [pc, #0x1c8]
 *   @0x25a204 add r0, pc, r0
 *   @0x25a208 bl 0x253d88 <_Z18JSThrowSyntaxErrorPKc>
 *   @0x25a20c b 0x25a070 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x25a210 ldr r0, [r11, #-0x48]
 *   @0x25a214 bl 0x253d88 <_Z18JSThrowSyntaxErrorPKc>
 *   @0x25a218 b 0x25a144 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x25a21c ldr r0, [pc, #0x1b0]
 *   @0x25a220 add r0, pc, r0
 *   @0x25a224 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25a228 b 0x25a144 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x29c>
 *   @0x25a22c sub r6, r11, #104
 *   @0x25a230 ldr r2, [pc, #0x1a0]
 *   @0x25a234 mov r0, r8
 *   @0x25a238 sub r12, r11, #72
 *   @0x25a23c add r2, pc, r2
 *   @0x25a240 mov r1, r6
 *   @0x25a244 str r12, [r11, #-0x84]
 *   @0x25a248 sub r9, r11, #88
 *   @0x25a24c str r3, [r11, #-0x68]
 *   @0x25a250 sub r8, r11, #56
 *   @0x25a254 str r3, [r11, #-0x64]
 *   @0x25a258 str r3, [r11, #-0x60]
 *   @0x25a25c str r3, [r11, #-0x5c]
 *   @0x25a260 str r3, [r11, #-0x58]
 *   @0x25a264 str r3, [r11, #-0x54]
 *   @0x25a268 str r3, [r11, #-0x50]
 *   @0x25a26c str r3, [r11, #-0x4c]
 *   @0x25a270 str r3, [r11, #-0x48]
 *   @0x25a274 str r3, [r11, #-0x44]
 *   @0x25a278 str r3, [r11, #-0x40]
 *   @0x25a27c str r3, [r11, #-0x3c]
 *   @0x25a280 str r3, [r11, #-0x38]
 *   @0x25a284 str r3, [r11, #-0x34]
 *   @0x25a288 str r3, [r11, #-0x30]
 *   @0x25a28c str r3, [r11, #-0x2c]
 *   @0x25a290 str r3, [r11, #-0x88]
 *   @0x25a294 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x25a298 ldr r2, [pc, #0x13c]
 *   @0x25a29c mov r1, r9
 *   @0x25a2a0 ldr r0, [r7]
 *   @0x25a2a4 add r2, pc, r2
 *   @0x25a2a8 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x25a2ac ldr r2, [pc, #0x12c]
 *   @0x25a2b0 ldr r0, [r7]
 *   @0x25a2b4 ldr r1, [r11, #-0x84]
 *   @0x25a2b8 add r2, pc, r2
 *   @0x25a2bc bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x25a2c0 ldr r2, [pc, #0x11c]
 *   @0x25a2c4 ldr r0, [r7]
 *   @0x25a2c8 mov r1, r8
 *   @0x25a2cc add r2, pc, r2
 *   @0x25a2d0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x25a2d4 ldr r3, [r11, #-0x88]
 *   @0x25a2d8 mov r0, r6
 *   @0x25a2dc mov r1, r3
 *   @0x25a2e0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x25a2e4 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x25a2e8 ldr r3, [r11, #-0x88]
 *   @0x25a2ec mov r1, r3
 *   @0x25a2f0 mov r10, r0
 *   @0x25a2f4 mov r0, r9
 *   @0x25a2f8 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x25a2fc ldr r3, [r11, #-0x88]
 *   @0x25a300 mov r1, r3
 *   @0x25a304 mov r9, r0
 *   @0x25a308 ldr r0, [r11, #-0x84]
 *   @0x25a30c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x25a310 ldr r3, [r11, #-0x88]
 *   @0x25a314 mov r1, r3
 *   @0x25a318 mov r7, r0
 *   @0x25a31c mov r0, r8
 *   @0x25a320 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x25a324 sub sp, sp, #16
 *   @0x25a328 cmp r9, #0
 *   @0x25a32c add r2, sp, #8
 *   @0x25a330 addne r3, r2, #1
 *   @0x25a334 movne r1, #103
 *   @0x25a338 moveq r3, r2
 *   @0x25a33c strbne r1, [r2]
 *   @0x25a340 cmp r7, #0
 *   @0x25a344 movne r1, #105
 *   @0x25a348 strbne r1, [r3]
 *   @0x25a34c addne r3, r3, #1
 *   @0x25a350 cmp r0, #0
 *   @0x25a354 mov r0, r2
 *   @0x25a358 mov r2, #0
 *   @0x25a35c movne r1, #109
 *   @0x25a360 strbne r1, [r3]
 *   @0x25a364 addne r3, r3, #1
 *   @0x25a368 strb r2, [r3]
 *   @0x25a36c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x25a370 ldr r3, [r11, #-0x5c]
 *   @0x25a374 sub r3, r3, #1
 *   @0x25a378 bic r3, r3, #-16777216
 *   @0x25a37c bic r3, r3, #3
 *   @0x25a380 cmp r3, #0
 *   @0x25a384 str r0, [r11, #-0x80]
 *   @0x25a388 bne 0x259ff8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x25a38c mov r0, r6
 *   @0x25a390 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x25a394 b 0x259ff8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x25a398 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x25a39c mulseq r9, r4, r10
 *   @0x25a3a0 andseq r7, r9, r8, ror #16
 *   @0x25a3a4 andeq r11, pc, r12, lsr sp
 *   @0x25a3a8 andeq r12, pc, r8, ror #10
 *   @0x25a3ac strdeq r10, r11, [sp], -r8
 *   @0x25a3b0 andeq r12, pc, r12, lsr r5
 *   @0x25a3b4 andeq r12, pc, r0, lsr r5
 *   @0x25a3b8 andeq r11, pc, r8, ror pc
 *   @0x25a3bc andeq r11, pc, r4, asr #21
 *   @0x25a3c0 andeq r12, pc, r8, lsl #22
 *   @0x25a3c4 andeq r4, sp, r10, lsl #19
 *   @0x25a3c8 andeq r4, sp, r10, ror #18
 *   @0x25a3cc andeq r12, pc, r0, lsl r9
 *   @0x25a3d0 strdeq r12, sp, [pc], -r4
 *   @0x25a3d4 muleq pc, r12, r10
 *   @0x25a3d8 strdeq r12, sp, [pc], -r0
 *   @0x25a3dc andeq r10, sp, r4, lsr r12
 *   @0x25a3e0 andeq r12, pc, r12, ror r3
 *   @0x25a3e4 andeq r12, pc, r4, ror r3
 *
 * ══ §9/23 Sprite_Duplicate(int)  0x1f07f0  size 1336  334 条（0x1f07f0..0x1f0d28）
 * @func 0x1f07f0 0x1f0d28  size 1336  334 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1f0820→0x7530d8, 0x1f0834→0x7530d0, 0x1f0884→0x7530dc, 0x1f08d4→0x7530e0
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / MemoryManager::Free(void const*)×2 / CSprite::InitTexture()×2 / CSprite::InitLocalTPE()×2 / Sprite_Duplicate(int)+0x4f4 / 0xb65c8 / YYStrDup(char const*)
 * 字段偏移 top8: 0x4×25 / 0x2×15 / 0x8×13 / 0xc×7 / 0x10×7 / 0x54×4 / 0x18×3 / 0x114×2
 * VFP 指令 19 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f07f0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1f07f4 sub sp, sp, #284
 *   @0x1f07f8 ldr r4, [pc, #0x500]
 *   @0x1f07fc cmp r0, #0
 *   @0x1f0800 ldr r3, [pc, #0x4fc]
 *   @0x1f0804 add r4, pc, r4
 *   @0x1f0808 str r0, [sp, #0x8]
 *   @0x1f080c ldr r3, [r4, r3]
 *   @0x1f0810 str r3, [sp, #0xc]
 *   @0x1f0814 ldr r3, [r3]
 *   @0x1f0818 str r3, [sp, #0x114]
 *   @0x1f081c blt 0x1f0ce4 <_Z16Sprite_Duplicatei+0x4f4>
 *   @0x1f0820 ldr r3, [pc, #0x4e0]
 *   @0x1f0824 ldr r5, [r4, r3]
 *   @0x1f0828 ldr r3, [r5]
 *   @0x1f082c cmp r0, r3
 *   @0x1f0830 bge 0x1f0ce4 <_Z16Sprite_Duplicatei+0x4f4>
 *   @0x1f0834 ldr r2, [pc, #0x4d0]
 *   @0x1f0838 ldr r2, [r4, r2]
 *   @0x1f083c str r2, [sp]
 *   @0x1f0840 ldr r2, [r2, #0x4]
 *   @0x1f0844 ldr r2, [r2, r0, lsl #2]
 *   @0x1f0848 cmp r2, #0
 *   @0x1f084c beq 0x1f0ce4 <_Z16Sprite_Duplicatei+0x4f4>
 *   @0x1f0850 ldr r6, [pc, #0x4b8]
 *   @0x1f0854 add r2, r3, #1
 *   @0x1f0858 ldr r12, [sp]
 *   @0x1f085c movw r3, #0x357
 *   @0x1f0860 add r6, pc, r6
 *   @0x1f0864 lsl r1, r2, #2
 *   @0x1f0868 add r0, r12, #4
 *   @0x1f086c str r2, [r5]
 *   @0x1f0870 mov r2, r6
 *   @0x1f0874 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1f0878 ldr r1, [r5]
 *   @0x1f087c ldr r12, [sp]
 *   @0x1f0880 mov r2, r6
 *   @0x1f0884 ldr r0, [pc, #0x488]
 *   @0x1f0888 movw r3, #0x359
 *   @0x1f088c str r1, [r12]
 *   @0x1f0890 lsl r1, r1, #2
 *   @0x1f0894 ldr r0, [r4, r0]
 *   @0x1f0898 str r0, [sp, #0x4]
 *   @0x1f089c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1f08a0 ldr r7, [r5]
 *   @0x1f08a4 add r5, sp, #20
 *   @0x1f08a8 ldr r2, [pc, #0x468]
 *   @0x1f08ac mov r1, #256
 *   @0x1f08b0 sub r7, r7, #1
 *   @0x1f08b4 mov r0, r5
 *   @0x1f08b8 add r2, pc, r2
 *   @0x1f08bc mov r3, r7
 *   @0x1f08c0 bl 0xb65c8 <snprintf@plt>
 *   @0x1f08c4 ldr r12, [sp, #0x4]
 *   @0x1f08c8 mov r0, r5
 *   @0x1f08cc ldr r5, [r12]
 *   @0x1f08d0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1f08d4 ldr r3, [pc, #0x440]
 *   @0x1f08d8 ldr r12, [sp, #0x4]
 *   @0x1f08dc str r0, [r5, r7, lsl #2]
 *   @0x1f08e0 ldr r8, [r4, r3]
 *   @0x1f08e4 ldr r1, [r12]
 *   @0x1f08e8 ldr r3, [r8, #0x4]
 *   @0x1f08ec ldr r2, [r8, #0xc]
 *   @0x1f08f0 ldr r6, [r1, r7, lsl #2]
 *   @0x1f08f4 cmp r3, r2
 *   @0x1f08f8 bgt 0x1f0a50 <_Z16Sprite_Duplicatei+0x260>
 *   @0x1f08fc mov r0, r6
 *   @0x1f0900 add r3, r3, #1
 *   @0x1f0904 str r3, [r8, #0x4]
 *   @0x1f0908 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x1f090c ldr r4, [r8, #0x8]
 *   @0x1f0910 ldr r10, [r8, #0x10]
 *   @0x1f0914 bic r0, r0, #-2147483648
 *   @0x1f0918 and r2, r0, r4
 *   @0x1f091c add r1, r2, r2, lsl #1
 *   @0x1f0920 add r1, r10, r1, lsl #2
 *   @0x1f0924 ldr r12, [r1, #0x8]
 *   @0x1f0928 cmp r12, #0
 *   @0x1f092c beq 0x1f09c8 <_Z16Sprite_Duplicatei+0x1d8>
 *   @0x1f0930 ldr r11, [r8]
 *   @0x1f0934 mov r9, r7
 *   @0x1f0938 mov r5, #0
 *   @0x1f093c b 0x1f097c <_Z16Sprite_Duplicatei+0x18c>
 *   @0x1f0940 ldm r1, {r5, lr}
 *   @0x1f0944 str r0, [r1, #0x8]
 *   @0x1f0948 mov r0, r12
 *   @0x1f094c str r6, [r1]
 *   @0x1f0950 str r9, [r1, #0x4]
 *   @0x1f0954 mov r6, r5
 *   @0x1f0958 mov r9, lr
 *   @0x1f095c add r2, r2, #1
 *   @0x1f0960 add r5, r3, #1
 *   @0x1f0964 and r2, r2, r4
 *   @0x1f0968 add r1, r2, r2, lsl #1
 *   @0x1f096c add r1, r10, r1, lsl #2
 *   @0x1f0970 ldr r12, [r1, #0x8]
 *   @0x1f0974 cmp r12, #0
 *   @0x1f0978 beq 0x1f09cc <_Z16Sprite_Duplicatei+0x1dc>
 *   @0x1f097c add r3, r2, r11
 *   @0x1f0980 and lr, r12, r4
 *   @0x1f0984 rsb r3, lr, r3
 *   @0x1f0988 and r3, r3, r4
 *   @0x1f098c cmp r3, r5
 *   @0x1f0990 blt 0x1f0940 <_Z16Sprite_Duplicatei+0x150>
 *   @0x1f0994 movne r3, r5
 *   @0x1f0998 bne 0x1f095c <_Z16Sprite_Duplicatei+0x16c>
 *   @0x1f099c cmp r12, r0
 *   @0x1f09a0 bne 0x1f095c <_Z16Sprite_Duplicatei+0x16c>
 *   @0x1f09a4 ldr lr, [r1]
 *   @0x1f09a8 cmp r6, lr
 *   @0x1f09ac bne 0x1f095c <_Z16Sprite_Duplicatei+0x16c>
 *   @0x1f09b0 ldr r3, [r8, #0x4]
 *   @0x1f09b4 str r12, [r1, #0x8]
 *   @0x1f09b8 stm r1, {r6, r9}
 *   @0x1f09bc sub r3, r3, #1
 *   @0x1f09c0 str r3, [r8, #0x4]
 *   @0x1f09c4 b 0x1f09d4 <_Z16Sprite_Duplicatei+0x1e4>
 *   @0x1f09c8 mov r9, r7
 *   @0x1f09cc stm r1, {r6, r9}
 *   @0x1f09d0 str r0, [r1, #0x8]
 *   @0x1f09d4 mov r0, #136
 *   @0x1f09d8 bl 0x27c524 <_Znwj>
 *   @0x1f09dc mov r4, r0
 *   @0x1f09e0 bl 0x1e761c <_ZN7CSpriteC2Ev>
 *   @0x1f09e4 ldr r12, [sp]
 *   @0x1f09e8 ldr r3, [r12, #0x4]
 *   @0x1f09ec str r4, [r3, r7, lsl #2]
 *   @0x1f09f0 ldr r3, [r12, #0x4]
 *   @0x1f09f4 ldr r12, [sp, #0x8]
 *   @0x1f09f8 ldr r0, [r3, r7, lsl #2]
 *   @0x1f09fc ldr r1, [r3, r12, lsl #2]
 *   @0x1f0a00 bl 0x1e76e8 <_ZN7CSprite6AssignEPS_>
 *   @0x1f0a04 ldr r12, [sp]
 *   @0x1f0a08 ldr r3, [r12, #0x4]
 *   @0x1f0a0c ldr r3, [r3, r7, lsl #2]
 *   @0x1f0a10 ldr r5, [r3, #0x44]
 *   @0x1f0a14 cmp r5, #0
 *   @0x1f0a18 beq 0x1f0b40 <_Z16Sprite_Duplicatei+0x350>
 *   @0x1f0a1c ldr r12, [sp, #0x4]
 *   @0x1f0a20 mov r0, r7
 *   @0x1f0a24 str r7, [r3, #0x60]
 *   @0x1f0a28 ldr r2, [r12]
 *   @0x1f0a2c ldr r2, [r2, r7, lsl #2]
 *   @0x1f0a30 str r2, [r3, #0x5c]
 *   @0x1f0a34 ldr r12, [sp, #0xc]
 *   @0x1f0a38 ldr r2, [sp, #0x114]
 *   @0x1f0a3c ldr r3, [r12]
 *   @0x1f0a40 cmp r2, r3
 *   @0x1f0a44 bne 0x1f0cf8 <_Z16Sprite_Duplicatei+0x508>
 *   @0x1f0a48 add sp, sp, #284
 *   @0x1f0a4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1f0a50 ldr r9, [r8]
 *   @0x1f0a54 mov r3, #1
 *   @0x1f0a58 ldr r1, [pc, #0x2c0]
 *   @0x1f0a5c mov r2, #70
 *   @0x1f0a60 ldr r5, [r8, #0x10]
 *   @0x1f0a64 lsl r0, r9, r3
 *   @0x1f0a68 add r1, pc, r1
 *   @0x1f0a6c add r4, r0, r9, lsl #2
 *   @0x1f0a70 str r0, [r8]
 *   @0x1f0a74 sub r0, r0, #1
 *   @0x1f0a78 str r0, [r8, #0x8]
 *   @0x1f0a7c lsl r4, r4, #2
 *   @0x1f0a80 mov r0, r4
 *   @0x1f0a84 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1f0a88 mov r2, r4
 *   @0x1f0a8c mov r1, #0
 *   @0x1f0a90 str r0, [r8, #0x10]
 *   @0x1f0a94 bl 0xb65b0 <memset@plt>
 *   @0x1f0a98 ldr r2, [r8]
 *   @0x1f0a9c vldr s15, [pc, #600]
 *   @0x1f0aa0 mov r1, #0
 *   @0x1f0aa4 str r1, [r8, #0x4]
 *   @0x1f0aa8 cmp r2, r1
 *   @0x1f0aac vmov s13, r2
 *   @0x1f0ab0 vcvt.f32.s32 s14, s13
 *   @0x1f0ab4 vmul.f32 s15, s14, s15
 *   @0x1f0ab8 vcvt.s32.f32 s15, s15
 *   @0x1f0abc vstr s15, [r8, #12]
 *   @0x1f0ac0 ble 0x1f0ae0 <_Z16Sprite_Duplicatei+0x2f0>
 *   @0x1f0ac4 add r2, r2, r2, lsl #1
 *   @0x1f0ac8 ldr r3, [r8, #0x10]
 *   @0x1f0acc add r2, r3, r2, lsl #2
 *   @0x1f0ad0 str r1, [r3, #0x8]
 *   @0x1f0ad4 add r3, r3, #12
 *   @0x1f0ad8 cmp r3, r2
 *   @0x1f0adc bne 0x1f0ad0 <_Z16Sprite_Duplicatei+0x2e0>
 *   @0x1f0ae0 cmp r9, #0
 *   @0x1f0ae4 movgt r4, r5
 *   @0x1f0ae8 movgt r10, #0
 *   @0x1f0aec ble 0x1f0b18 <_Z16Sprite_Duplicatei+0x328>
 *   @0x1f0af0 ldr r3, [r4, #0x8]
 *   @0x1f0af4 cmp r3, #0
 *   @0x1f0af8 ble 0x1f0b08 <_Z16Sprite_Duplicatei+0x318>
 *   @0x1f0afc mov r0, r8
 *   @0x1f0b00 ldm r4, {r1, r2}
 *   @0x1f0b04 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i>
 *   @0x1f0b08 add r10, r10, #1
 *   @0x1f0b0c add r4, r4, #12
 *   @0x1f0b10 cmp r10, r9
 *   @0x1f0b14 bne 0x1f0af0 <_Z16Sprite_Duplicatei+0x300>
 *   @0x1f0b18 mov r0, r5
 *   @0x1f0b1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f0b20 vldr s13, [r8]
 *   @0x1f0b24 vcvt.f32.s32 s14, s13
 *   @0x1f0b28 vldr s15, [pc, #460]
 *   @0x1f0b2c ldr r3, [r8, #0x4]
 *   @0x1f0b30 vmul.f32 s15, s14, s15
 *   @0x1f0b34 vcvt.s32.f32 s15, s15
 *   @0x1f0b38 vstr s15, [r8, #12]
 *   @0x1f0b3c b 0x1f08fc <_Z16Sprite_Duplicatei+0x10c>
 *   @0x1f0b40 mov r0, r3
 *   @0x1f0b44 bl 0x1e65d8 <_ZN7CSprite18GenerateBitmapDataEv>
 *   @0x1f0b48 ldr r12, [sp]
 *   @0x1f0b4c ldr r3, [r12, #0x4]
 *   @0x1f0b50 cmp r0, #0
 *   @0x1f0b54 beq 0x1f0cc0 <_Z16Sprite_Duplicatei+0x4d0>
 *   @0x1f0b58 ldr r0, [r3, r7, lsl #2]
 *   @0x1f0b5c ldr r3, [r0, #0x54]
 *   @0x1f0b60 cmp r3, #0
 *   @0x1f0b64 beq 0x1f0cc8 <_Z16Sprite_Duplicatei+0x4d8>
 *   @0x1f0b68 ldr r3, [r0, #0x18]
 *   @0x1f0b6c cmp r3, #0
 *   @0x1f0b70 ble 0x1f0cc8 <_Z16Sprite_Duplicatei+0x4d8>
 *   @0x1f0b74 ldr r1, [pc, #0x1a8]
 *   @0x1f0b78 mov r0, #22
 *   @0x1f0b7c mul r0, r0, r3
 *   @0x1f0b80 add r1, pc, r1
 *   @0x1f0b84 mov r2, #70
 *   @0x1f0b88 mov r3, #1
 *   @0x1f0b8c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1f0b90 ldr r12, [sp]
 *   @0x1f0b94 ldr r10, [r12, #0x4]
 *   @0x1f0b98 mov r4, r0
 *   @0x1f0b9c ldr r0, [r10, r7, lsl #2]
 *   @0x1f0ba0 ldr r9, [r0, #0x18]
 *   @0x1f0ba4 cmp r9, #0
 *   @0x1f0ba8 ble 0x1f0bfc <_Z16Sprite_Duplicatei+0x40c>
 *   @0x1f0bac ldr lr, [r0, #0x54]
 *   @0x1f0bb0 mov r1, r5
 *   @0x1f0bb4 add r9, lr, r9, lsl #2
 *   @0x1f0bb8 ldr r3, [lr], #4
 *   @0x1f0bbc add r2, r4, r1
 *   @0x1f0bc0 cmp lr, r9
 *   @0x1f0bc4 ldr r12, [r3]
 *   @0x1f0bc8 ldr r8, [r3, #0x4]
 *   @0x1f0bcc ldr r6, [r3, #0x8]
 *   @0x1f0bd0 ldr r5, [r3, #0xc]
 *   @0x1f0bd4 str r12, [r4, r1]
 *   @0x1f0bd8 add r1, r1, #22
 *   @0x1f0bdc str r8, [r2, #0x4]
 *   @0x1f0be0 str r6, [r2, #0x8]
 *   @0x1f0be4 str r5, [r2, #0xc]
 *   @0x1f0be8 ldr r12, [r3, #0x10]
 *   @0x1f0bec str r12, [r2, #0x10]
 *   @0x1f0bf0 ldrh r3, [r3, #20]
 *   @0x1f0bf4 strh r3, [r2, #20]
 *   @0x1f0bf8 bne 0x1f0bb8 <_Z16Sprite_Duplicatei+0x3c8>
 *   @0x1f0bfc ldrb r3, [r0, #0x36]
 *   @0x1f0c00 cmp r3, #0
 *   @0x1f0c04 beq 0x1f0cec <_Z16Sprite_Duplicatei+0x4fc>
 *   @0x1f0c08 bl 0x1e5748 <_ZN7CSprite11InitTextureEv>
 *   @0x1f0c0c ldr r12, [sp]
 *   @0x1f0c10 ldr r3, [r12, #0x4]
 *   @0x1f0c14 ldr r0, [r3, r7, lsl #2]
 *   @0x1f0c18 bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv>
 *   @0x1f0c1c cmp r4, #0
 *   @0x1f0c20 beq 0x1f0cb0 <_Z16Sprite_Duplicatei+0x4c0>
 *   @0x1f0c24 ldr r12, [sp]
 *   @0x1f0c28 ldr r3, [r12, #0x4]
 *   @0x1f0c2c ldr r3, [r3, r7, lsl #2]
 *   @0x1f0c30 ldr r1, [r3, #0x54]
 *   @0x1f0c34 cmp r1, #0
 *   @0x1f0c38 beq 0x1f0cb0 <_Z16Sprite_Duplicatei+0x4c0>
 *   @0x1f0c3c ldr lr, [r3, #0x18]
 *   @0x1f0c40 cmp lr, #0
 *   @0x1f0c44 ble 0x1f0cb0 <_Z16Sprite_Duplicatei+0x4c0>
 *   @0x1f0c48 add lr, r1, lr, lsl #2
 *   @0x1f0c4c mov r2, r4
 *   @0x1f0c50 ldrsh r3, [r2, #12]
 *   @0x1f0c54 add r2, r2, #22
 *   @0x1f0c58 ldrsh r12, [r2, #-18]
 *   @0x1f0c5c vmov s14, r3
 *   @0x1f0c60 ldr r3, [r1], #4
 *   @0x1f0c64 vmov s15, r12
 *   @0x1f0c68 vcvt.f32.s32 s14, s14
 *   @0x1f0c6c cmp r1, lr
 *   @0x1f0c70 ldrh r12, [r3, #12]
 *   @0x1f0c74 ldrh r5, [r3, #14]
 *   @0x1f0c78 vcvt.f32.s32 s15, s15
 *   @0x1f0c7c vdiv.f32 s15, s14, s15
 *   @0x1f0c80 vcvt.s32.f32 s15, s15
 *   @0x1f0c84 vmov r0, s15
 *   @0x1f0c88 uxth r0, r0
 *   @0x1f0c8c mul r12, r12, r0
 *   @0x1f0c90 mul r0, r5, r0
 *   @0x1f0c94 uxth r12, r12
 *   @0x1f0c98 strh r12, [r3, #12]
 *   @0x1f0c9c strh r12, [r3, #16]
 *   @0x1f0ca0 uxth r0, r0
 *   @0x1f0ca4 strh r0, [r3, #14]
 *   @0x1f0ca8 strh r0, [r3, #18]
 *   @0x1f0cac bne 0x1f0c50 <_Z16Sprite_Duplicatei+0x460>
 *   @0x1f0cb0 mov r0, r4
 *   @0x1f0cb4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f0cb8 ldr r12, [sp]
 *   @0x1f0cbc ldr r3, [r12, #0x4]
 *   @0x1f0cc0 ldr r3, [r3, r7, lsl #2]
 *   @0x1f0cc4 b 0x1f0a1c <_Z16Sprite_Duplicatei+0x22c>
 *   @0x1f0cc8 bl 0x1e5748 <_ZN7CSprite11InitTextureEv>
 *   @0x1f0ccc ldr r12, [sp]
 *   @0x1f0cd0 mov r4, #0
 *   @0x1f0cd4 ldr r3, [r12, #0x4]
 *   @0x1f0cd8 ldr r0, [r3, r7, lsl #2]
 *   @0x1f0cdc bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv>
 *   @0x1f0ce0 b 0x1f0cb0 <_Z16Sprite_Duplicatei+0x4c0>
 *   @0x1f0ce4 mvn r0, #0
 *   @0x1f0ce8 b 0x1f0a34 <_Z16Sprite_Duplicatei+0x244>
 *   @0x1f0cec str r3, [r0, #0x54]
 *   @0x1f0cf0 ldr r0, [r10, r7, lsl #2]
 *   @0x1f0cf4 b 0x1f0c08 <_Z16Sprite_Duplicatei+0x418>
 *   @0x1f0cf8 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1f0cfc svclo #0x19999a
 *   @0x1f0d00 eoreq r1, r0, r12, asr #8
 *   @0x1f0d04 .word 0xffffbd00
 *   @0x1f0d08 .word 0xfffff1c0
 *   @0x1f0d0c .word 0xfffff1b8
 *   @0x1f0d10 andseq r1, r6, r0, ror #27
 *   @0x1f0d14 .word 0xfffff1bc
 *   @0x1f0d18 andseq r1, r6, r0, asr #27
 *   @0x1f0d1c .word 0xfffff1c4
 *   @0x1f0d20 andseq r0, r4, r8, asr #11
 *   @0x1f0d24 ldrheq r0, [r4], -r0
 *
 * ══ §10/23 CPhysicsWorld::DrawParticlesExt(unsigned int, int, CSprite*, int, float, float, float, unsigned int, float)  0x23acf4  size 1324  331 条（0x23acf4..0x23b220）
 * @func 0x23acf4 0x23b220  size 1324  331 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_idivmod / GR_Texture_Exists(int) / b2World::GetParticlePositionBuffer() / b2World::GetParticleFlagsBuffer() / b2World::GetParticleUserDataBuffer() / CPhysicsWorld::DrawParticlesExt(unsigned int, int, CSprite*, int, float, float, float, unsigned int, float)+0x54 / Graphics::AllocVerts(ePrimType, void*, int, int) / 0xb6580
 * 字段偏移 top8: 0x10×4 / 0x4×4 / 0x8×4 / 0x54×3 / 0xc×3 / 0x2×2 / 0x84×2 / 0x6c×2
 * VFP 指令 143 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23acf4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x23acf8 vpush {d8, d9, d10}
 *   @0x23acfc sub sp, sp, #20
 *   @0x23ad00 ldr r4, [r3, #0x18]
 *   @0x23ad04 mov r5, r0
 *   @0x23ad08 mov r9, r1
 *   @0x23ad0c ldr r0, [sp, #0x50]
 *   @0x23ad10 mov r10, r3
 *   @0x23ad14 mov r6, r2
 *   @0x23ad18 mov r1, r4
 *   @0x23ad1c bl 0x318dec <__aeabi_idivmod>
 *   @0x23ad20 ldr r3, [r10, #0x54]
 *   @0x23ad24 cmp r1, #0
 *   @0x23ad28 addlt r1, r1, r4
 *   @0x23ad2c cmp r3, #0
 *   @0x23ad30 beq 0x23ad48 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x54>
 *   @0x23ad34 ldr r4, [r3, r1, lsl #2]
 *   @0x23ad38 ldrsh r0, [r4, #20]
 *   @0x23ad3c bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x23ad40 cmp r0, #0
 *   @0x23ad44 bne 0x23ad54 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x60>
 *   @0x23ad48 add sp, sp, #20
 *   @0x23ad4c vpop {d8, d9, d10}
 *   @0x23ad50 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23ad54 ldr r3, [pc, #0x374]
 *   @0x23ad58 ldrsh r2, [r4, #20]
 *   @0x23ad5c ldr r3, [pc, r3]
 *   @0x23ad60 ldr r0, [r5, #0x10]
 *   @0x23ad64 ldr r3, [r3, #0x4]
 *   @0x23ad68 ldr r11, [r3, r2, lsl #2]
 *   @0x23ad6c bl 0x2cb574 <_ZN7b2World25GetParticlePositionBufferEv>
 *   @0x23ad70 str r0, [sp, #0xc]
 *   @0x23ad74 ldr r0, [r5, #0x10]
 *   @0x23ad78 bl 0x2cb568 <_ZN7b2World22GetParticleFlagsBufferEv>
 *   @0x23ad7c mov r7, r0
 *   @0x23ad80 ldr r0, [r5, #0x10]
 *   @0x23ad84 bl 0x2cb598 <_ZN7b2World25GetParticleUserDataBufferEv>
 *   @0x23ad88 ldr r2, [r5, #0x10]
 *   @0x23ad8c movw r3, #0x9298
 *   @0x23ad90 movt r3, #0x1
 *   @0x23ad94 vldr s15, [r5, #96]
 *   @0x23ad98 ldr r8, [r2, r3]
 *   @0x23ad9c cmp r8, #0
 *   @0x23ada0 mov r12, r0
 *   @0x23ada4 ble 0x23ad48 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x54>
 *   @0x23ada8 cmp r6, #0
 *   @0x23adac lsl r8, r8, #2
 *   @0x23adb0 beq 0x23b040 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x34c>
 *   @0x23adb4 mov r3, #0
 *   @0x23adb8 mov r2, r3
 *   @0x23adbc b 0x23add8 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0xe4>
 *   @0x23adc0 ldr r1, [r12, r3]
 *   @0x23adc4 cmp r1, r6
 *   @0x23adc8 addeq r2, r2, #1
 *   @0x23adcc add r3, r3, #4
 *   @0x23add0 cmp r3, r8
 *   @0x23add4 beq 0x23adf8 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x104>
 *   @0x23add8 ldr r1, [r7, r3]
 *   @0x23addc cmp r1, #0
 *   @0x23ade0 beq 0x23adc0 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0xcc>
 *   @0x23ade4 tst r1, r9
 *   @0x23ade8 bne 0x23adc0 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0xcc>
 *   @0x23adec add r3, r3, #4
 *   @0x23adf0 cmp r3, r8
 *   @0x23adf4 bne 0x23add8 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0xe4>
 *   @0x23adf8 cmp r2, #0
 *   @0x23adfc beq 0x23ad48 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x54>
 *   @0x23ae00 vldr s14, [pc, #704]
 *   @0x23ae04 vldr s11, [sp, #100]
 *   @0x23ae08 vmul.f32 s14, s11, s14
 *   @0x23ae0c vcvt.s32.f32 s14, s14
 *   @0x23ae10 vmov r5, s14
 *   @0x23ae14 cmp r5, #255
 *   @0x23ae18 movgt r5, #-16777216
 *   @0x23ae1c bgt 0x23ae2c <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x138>
 *   @0x23ae20 cmp r5, #0
 *   @0x23ae24 lslge r5, r5, #24
 *   @0x23ae28 movlt r5, #0
 *   @0x23ae2c ldrsh r3, [r4, #12]
 *   @0x23ae30 vmov.f32 s16, #1.000000e+00
 *   @0x23ae34 ldr r0, [sp, #0x60]
 *   @0x23ae38 cmp r3, #0
 *   @0x23ae3c bic r1, r0, #-16777216
 *   @0x23ae40 mov r0, #4
 *   @0x23ae44 moveq r3, #1
 *   @0x23ae48 strheq r3, [r4, #12]
 *   @0x23ae4c ldrsh r3, [r4, #14]
 *   @0x23ae50 orr r5, r5, r1
 *   @0x23ae54 ldr r1, [r11]
 *   @0x23ae58 cmp r3, #0
 *   @0x23ae5c moveq r3, #1
 *   @0x23ae60 strheq r3, [r4, #14]
 *   @0x23ae64 add r3, r2, r2, lsl #1
 *   @0x23ae68 mov r2, #24
 *   @0x23ae6c vdiv.f32 s16, s16, s15
 *   @0x23ae70 str r12, [sp]
 *   @0x23ae74 lsl r3, r3, #1
 *   @0x23ae78 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x23ae7c ldrsh r1, [r4, #10]
 *   @0x23ae80 ldrsh r2, [r4, #8]
 *   @0x23ae84 vldr s11, [sp, #84]
 *   @0x23ae88 vldr s12, [sp, #88]
 *   @0x23ae8c vldr s13, [pc, #568]
 *   @0x23ae90 ldr r12, [sp]
 *   @0x23ae94 mov r3, r0
 *   @0x23ae98 ldr r0, [r10, #0x28]
 *   @0x23ae9c ldr r10, [r10, #0x24]
 *   @0x23aea0 rsb r0, r1, r0
 *   @0x23aea4 ldrsh r1, [r4, #12]
 *   @0x23aea8 rsb r10, r2, r10
 *   @0x23aeac ldrsh r2, [r4, #14]
 *   @0x23aeb0 vmov s17, r0
 *   @0x23aeb4 vmov s18, r10
 *   @0x23aeb8 vcvt.f32.s32 s17, s17
 *   @0x23aebc vmov s14, r1
 *   @0x23aec0 vmov s15, r2
 *   @0x23aec4 vcvt.f32.s32 s18, s18
 *   @0x23aec8 vnmul.f32 s17, s12, s17
 *   @0x23aecc vnmul.f32 s18, s11, s18
 *   @0x23aed0 vldr s11, [sp, #92]
 *   @0x23aed4 vabs.f32 s12, s11
 *   @0x23aed8 vcvt.f32.s32 s14, s14
 *   @0x23aedc vcvt.f32.s32 s15, s15
 *   @0x23aee0 vcmpe.f32 s12, s13
 *   @0x23aee4 vldr s12, [sp, #84]
 *   @0x23aee8 vldr s13, [sp, #88]
 *   @0x23aeec vmov.f32 s20, s18
 *   @0x23aef0 vmrs APSR_nzcv, fpscr
 *   @0x23aef4 vmov.f32 s19, s17
 *   @0x23aef8 vmla.f32 s20, s14, s12
 *   @0x23aefc vmla.f32 s19, s15, s13
 *   @0x23af00 bpl 0x23b070 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x37c>
 *   @0x23af04 ldr r1, [sp, #0xc]
 *   @0x23af08 mov r2, #0
 *   @0x23af0c str r9, [sp, #0x8]
 *   @0x23af10 b 0x23af30 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x23c>
 *   @0x23af14 ldr r0, [r12, r2]
 *   @0x23af18 cmp r0, r6
 *   @0x23af1c beq 0x23af50 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x25c>
 *   @0x23af20 add r2, r2, #4
 *   @0x23af24 add r1, r1, #8
 *   @0x23af28 cmp r2, r8
 *   @0x23af2c beq 0x23ad48 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x54>
 *   @0x23af30 ldr r0, [r7, r2]
 *   @0x23af34 cmp r0, #0
 *   @0x23af38 beq 0x23af48 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x254>
 *   @0x23af3c ldr r9, [sp, #0x8]
 *   @0x23af40 tst r0, r9
 *   @0x23af44 beq 0x23af20 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x22c>
 *   @0x23af48 cmp r6, #0
 *   @0x23af4c bne 0x23af14 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x220>
 *   @0x23af50 ldrsh r9, [r4]
 *   @0x23af54 vldr s8, [r11, #8]
 *   @0x23af58 vldr s10, [r1]
 *   @0x23af5c vldr s12, [r1, #4]
 *   @0x23af60 vmul.f32 s10, s16, s10
 *   @0x23af64 str r5, [r3, #0x84]
 *   @0x23af68 vmov s11, r9
 *   @0x23af6c str r5, [r3, #0x6c]
 *   @0x23af70 str r5, [r3, #0x54]
 *   @0x23af74 add r3, r3, #144
 *   @0x23af78 str r5, [r3, #-0x54]
 *   @0x23af7c str r5, [r3, #-0x6c]
 *   @0x23af80 str r5, [r3, #-0x84]
 *   @0x23af84 vcvt.f32.s32 s15, s11
 *   @0x23af88 vmul.f32 s15, s15, s8
 *   @0x23af8c vstr s15, [r3, #-32]
 *   @0x23af90 vstr s15, [r3, #-128]
 *   @0x23af94 vstr s15, [r3, #-8]
 *   @0x23af98 ldrsh r0, [r4, #2]
 *   @0x23af9c vldr s9, [r11, #12]
 *   @0x23afa0 vmul.f32 s12, s16, s12
 *   @0x23afa4 vmov s14, r0
 *   @0x23afa8 vcvt.f32.s32 s13, s14
 *   @0x23afac vmul.f32 s13, s13, s9
 *   @0x23afb0 vstr s13, [r3, #-100]
 *   @0x23afb4 vstr s13, [r3, #-124]
 *   @0x23afb8 vstr s13, [r3, #-4]
 *   @0x23afbc ldrsh r10, [r4, #4]
 *   @0x23afc0 vadd.f32 s11, s10, s18
 *   @0x23afc4 add r10, r9, r10
 *   @0x23afc8 vmov s14, r10
 *   @0x23afcc vcvt.f32.s32 s14, s14
 *   @0x23afd0 vstr s11, [r3, #-144]
 *   @0x23afd4 vstr s11, [r3, #-24]
 *   @0x23afd8 vstr s11, [r3, #-48]
 *   @0x23afdc vmul.f32 s14, s8, s14
 *   @0x23afe0 vadd.f32 s11, s12, s17
 *   @0x23afe4 vstr s14, [r3, #-80]
 *   @0x23afe8 vstr s14, [r3, #-56]
 *   @0x23afec vadd.f32 s10, s10, s20
 *   @0x23aff0 vstr s11, [r3, #-116]
 *   @0x23aff4 vstr s11, [r3, #-140]
 *   @0x23aff8 vstr s11, [r3, #-20]
 *   @0x23affc vadd.f32 s12, s12, s19
 *   @0x23b000 vstr s10, [r3, #-96]
 *   @0x23b004 vstr s10, [r3, #-72]
 *   @0x23b008 vstr s10, [r3, #-120]
 *   @0x23b00c vstr s12, [r3, #-44]
 *   @0x23b010 vstr s12, [r3, #-92]
 *   @0x23b014 vstr s12, [r3, #-68]
 *   @0x23b018 vstr s14, [r3, #-104]
 *   @0x23b01c ldrsh r10, [r4, #6]
 *   @0x23b020 add r10, r0, r10
 *   @0x23b024 vmov s15, r10
 *   @0x23b028 vcvt.f32.s32 s15, s15
 *   @0x23b02c vmul.f32 s15, s9, s15
 *   @0x23b030 vstr s15, [r3, #-28]
 *   @0x23b034 vstr s15, [r3, #-76]
 *   @0x23b038 vstr s15, [r3, #-52]
 *   @0x23b03c b 0x23af20 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x22c>
 *   @0x23b040 add r0, r7, r8
 *   @0x23b044 mov r3, r7
 *   @0x23b048 mov r2, r6
 *   @0x23b04c ldr r1, [r3], #4
 *   @0x23b050 cmp r1, #0
 *   @0x23b054 beq 0x23b060 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x36c>
 *   @0x23b058 tst r1, r9
 *   @0x23b05c beq 0x23b064 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x370>
 *   @0x23b060 add r2, r2, #1
 *   @0x23b064 cmp r3, r0
 *   @0x23b068 bne 0x23b04c <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x358>
 *   @0x23b06c b 0x23adf8 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x104>
 *   @0x23b070 ldr r0, [sp, #0x5c]
 *   @0x23b074 str r3, [sp, #0x4]
 *   @0x23b078 str r12, [sp]
 *   @0x23b07c bl 0xb6580 <sinf@plt>
 *   @0x23b080 vmov s21, r0
 *   @0x23b084 ldr r0, [sp, #0x5c]
 *   @0x23b088 bl 0xb658c <cosf@plt>
 *   @0x23b08c ldr r1, [sp, #0xc]
 *   @0x23b090 vmul.f32 s2, s18, s21
 *   @0x23b094 mov r2, #0
 *   @0x23b098 ldr r3, [sp, #0x4]
 *   @0x23b09c ldr r12, [sp]
 *   @0x23b0a0 str r9, [sp, #0x8]
 *   @0x23b0a4 vmul.f32 s3, s20, s21
 *   @0x23b0a8 vmul.f32 s4, s17, s21
 *   @0x23b0ac vmov s15, r0
 *   @0x23b0b0 vmul.f32 s5, s19, s21
 *   @0x23b0b4 vmul.f32 s18, s18, s15
 *   @0x23b0b8 vmul.f32 s20, s20, s15
 *   @0x23b0bc vmul.f32 s17, s17, s15
 *   @0x23b0c0 vmul.f32 s19, s19, s15
 *   @0x23b0c4 b 0x23b0f0 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x3fc>
 *   @0x23b0c8 cmnmi pc, #0
 *   @0x23b0cc blo 0xfe2ffa90 <b2_toiTime+0xfffffffffdba65ec>
 *   @0x23b0d0 andseq r2, r11, r0, asr #23
 *   @0x23b0d4 ldr r0, [r12, r2]
 *   @0x23b0d8 cmp r0, r6
 *   @0x23b0dc beq 0x23b110 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x41c>
 *   @0x23b0e0 add r2, r2, #4
 *   @0x23b0e4 add r1, r1, #8
 *   @0x23b0e8 cmp r2, r8
 *   @0x23b0ec beq 0x23ad48 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x54>
 *   @0x23b0f0 ldr r0, [r7, r2]
 *   @0x23b0f4 cmp r0, #0
 *   @0x23b0f8 beq 0x23b108 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x414>
 *   @0x23b0fc ldr r9, [sp, #0x8]
 *   @0x23b100 tst r0, r9
 *   @0x23b104 beq 0x23b0e0 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x3ec>
 *   @0x23b108 cmp r6, #0
 *   @0x23b10c bne 0x23b0d4 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x3e0>
 *   @0x23b110 ldrsh r9, [r4]
 *   @0x23b114 vldr s11, [r11, #8]
 *   @0x23b118 vldr s7, [r1]
 *   @0x23b11c vldr s10, [r1, #4]
 *   @0x23b120 vmul.f32 s7, s16, s7
 *   @0x23b124 str r5, [r3, #0x84]
 *   @0x23b128 vmov s12, r9
 *   @0x23b12c str r5, [r3, #0x6c]
 *   @0x23b130 str r5, [r3, #0x54]
 *   @0x23b134 add r3, r3, #144
 *   @0x23b138 str r5, [r3, #-0x54]
 *   @0x23b13c str r5, [r3, #-0x6c]
 *   @0x23b140 str r5, [r3, #-0x84]
 *   @0x23b144 vcvt.f32.s32 s15, s12
 *   @0x23b148 vmul.f32 s15, s15, s11
 *   @0x23b14c vstr s15, [r3, #-32]
 *   @0x23b150 vstr s15, [r3, #-128]
 *   @0x23b154 vstr s15, [r3, #-8]
 *   @0x23b158 ldrsh r0, [r4, #2]
 *   @0x23b15c vldr s12, [r11, #12]
 *   @0x23b160 vmul.f32 s10, s16, s10
 *   @0x23b164 vmov s14, r0
 *   @0x23b168 vcvt.f32.s32 s13, s14
 *   @0x23b16c vmul.f32 s13, s13, s12
 *   @0x23b170 vadd.f32 s6, s7, s18
 *   @0x23b174 vstr s13, [r3, #-100]
 *   @0x23b178 vstr s13, [r3, #-124]
 *   @0x23b17c vstr s13, [r3, #-4]
 *   @0x23b180 ldrsh r10, [r4, #4]
 *   @0x23b184 add r10, r9, r10
 *   @0x23b188 vmov s14, r10
 *   @0x23b18c vadd.f32 s7, s7, s20
 *   @0x23b190 vadd.f32 s9, s6, s4
 *   @0x23b194 vsub.f32 s8, s10, s2
 *   @0x23b198 vstr s9, [r3, #-144]
 *   @0x23b19c vstr s9, [r3, #-24]
 *   @0x23b1a0 vadd.f32 s15, s7, s4
 *   @0x23b1a4 vsub.f32 s10, s10, s3
 *   @0x23b1a8 vstr s15, [r3, #-120]
 *   @0x23b1ac vcvt.f32.s32 s14, s14
 *   @0x23b1b0 vmul.f32 s14, s11, s14
 *   @0x23b1b4 vadd.f32 s9, s8, s17
 *   @0x23b1b8 vstr s14, [r3, #-80]
 *   @0x23b1bc vstr s14, [r3, #-56]
 *   @0x23b1c0 vadd.f32 s15, s10, s17
 *   @0x23b1c4 vstr s9, [r3, #-140]
 *   @0x23b1c8 vstr s9, [r3, #-20]
 *   @0x23b1cc vadd.f32 s7, s5, s7
 *   @0x23b1d0 vstr s15, [r3, #-116]
 *   @0x23b1d4 vadd.f32 s10, s19, s10
 *   @0x23b1d8 vstr s7, [r3, #-96]
 *   @0x23b1dc vstr s7, [r3, #-72]
 *   @0x23b1e0 vadd.f32 s6, s5, s6
 *   @0x23b1e4 vstr s10, [r3, #-92]
 *   @0x23b1e8 vstr s10, [r3, #-68]
 *   @0x23b1ec vadd.f32 s8, s19, s8
 *   @0x23b1f0 vstr s6, [r3, #-48]
 *   @0x23b1f4 vstr s8, [r3, #-44]
 *   @0x23b1f8 vstr s14, [r3, #-104]
 *   @0x23b1fc ldrsh r10, [r4, #6]
 *   @0x23b200 add r10, r0, r10
 *   @0x23b204 vmov s15, r10
 *   @0x23b208 vcvt.f32.s32 s15, s15
 *   @0x23b20c vmul.f32 s15, s12, s15
 *   @0x23b210 vstr s15, [r3, #-28]
 *   @0x23b214 vstr s15, [r3, #-76]
 *   @0x23b218 vstr s15, [r3, #-52]
 *   @0x23b21c b 0x23b0e0 <_ZN13CPhysicsWorld16DrawParticlesExtEjiP7CSpriteifffjf+0x3ec>
 *
 * ══ §11/23 b2GearJoint::InitVelocityConstraints(b2SolverData const&)  0x2e4064  size 1316  329 条（0x2e4064..0x2e4588）
 * @func 0x2e4064 0x2e4588  size 1316  329 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×4 / 0xb658c×4
 * 字段偏移 top8: 0x8×10 / 0x4×4 / 0xac×2 / 0x18×2 / 0x1c×2 / 0x30×1 / 0x34×1 / 0x54×1
 * VFP 指令 214 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e4064 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e4068 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e406c sub sp, sp, #44
 *   @0x2e4070 ldr r9, [r0, #0x30]
 *   @0x2e4074 add r3, r0, #184
 *   @0x2e4078 ldr r12, [r0, #0x34]
 *   @0x2e407c mov r6, r1
 *   @0x2e4080 ldr r2, [r0, #0x54]
 *   @0x2e4084 add r1, r9, #44
 *   @0x2e4088 str r3, [sp, #0x4]
 *   @0x2e408c mov r4, r0
 *   @0x2e4090 ldr r3, [r0, #0x58]
 *   @0x2e4094 add lr, r0, #176
 *   @0x2e4098 ldr r7, [r12, #0x8]
 *   @0x2e409c add r5, r12, #44
 *   @0x2e40a0 ldr r11, [r2, #0x8]
 *   @0x2e40a4 vldr s30, [r2, #136]
 *   @0x2e40a8 ldr r8, [r9, #0x8]
 *   @0x2e40ac vldr s5, [r9, #136]
 *   @0x2e40b0 ldr r10, [r3, #0x8]
 *   @0x2e40b4 vldr s15, [r12, #136]
 *   @0x2e40b8 ldm r1, {r0, r1}
 *   @0x2e40bc vstr s5, [sp, #20]
 *   @0x2e40c0 str r8, [r4, #0xa0]
 *   @0x2e40c4 add r8, r8, r8, lsl #1
 *   @0x2e40c8 str r7, [r4, #0xa4]
 *   @0x2e40cc add r7, r7, r7, lsl #1
 *   @0x2e40d0 str r11, [r4, #0xa8]
 *   @0x2e40d4 lsl r8, r8, #2
 *   @0x2e40d8 str r10, [r4, #0xac]
 *   @0x2e40dc lsl r7, r7, #2
 *   @0x2e40e0 stm lr, {r0, r1}
 *   @0x2e40e4 add lr, r2, #44
 *   @0x2e40e8 ldm r5, {r0, r1}
 *   @0x2e40ec add r5, r4, #192
 *   @0x2e40f0 str r5, [sp, #0x8]
 *   @0x2e40f4 add r11, r11, r11, lsl #1
 *   @0x2e40f8 ldr r5, [sp, #0x4]
 *   @0x2e40fc add r10, r10, r10, lsl #1
 *   @0x2e4100 lsl r11, r11, #2
 *   @0x2e4104 lsl r10, r10, #2
 *   @0x2e4108 stm r5, {r0, r1}
 *   @0x2e410c add r5, r3, #44
 *   @0x2e4110 ldm lr, {r0, r1}
 *   @0x2e4114 add lr, r4, #200
 *   @0x2e4118 str lr, [sp, #0x4]
 *   @0x2e411c ldr lr, [sp, #0x8]
 *   @0x2e4120 stm lr, {r0, r1}
 *   @0x2e4124 vldr s21, [r9, #144]
 *   @0x2e4128 ldm r5, {r0, r1}
 *   @0x2e412c vldr s20, [r3, #144]
 *   @0x2e4130 ldr r5, [sp, #0x4]
 *   @0x2e4134 vldr s19, [r12, #144]
 *   @0x2e4138 ldr lr, [r6, #0x18]
 *   @0x2e413c vldr s22, [r2, #144]
 *   @0x2e4140 stm r5, {r0, r1}
 *   @0x2e4144 vstr s15, [r4, #212]
 *   @0x2e4148 ldr r1, [r3, #0x88]
 *   @0x2e414c add r3, lr, r7
 *   @0x2e4150 ldr r5, [r6, #0x1c]
 *   @0x2e4154 vstr s5, [r4, #208]
 *   @0x2e4158 vstr s30, [r4, #216]
 *   @0x2e415c str r1, [r4, #0xdc]
 *   @0x2e4160 add r1, lr, r8
 *   @0x2e4164 add r8, r5, r8
 *   @0x2e4168 vldr s29, [r8]
 *   @0x2e416c ldr r9, [r1, #0x8]
 *   @0x2e4170 vldr s28, [r8, #4]
 *   @0x2e4174 vldr s27, [r8, #8]
 *   @0x2e4178 ldr r8, [r3, #0x8]
 *   @0x2e417c add r3, lr, r11
 *   @0x2e4180 add lr, lr, r10
 *   @0x2e4184 mov r0, r9
 *   @0x2e4188 add r7, r5, r7
 *   @0x2e418c add r10, r5, r10
 *   @0x2e4190 vldr s26, [r7]
 *   @0x2e4194 vldr s25, [r7, #4]
 *   @0x2e4198 vldr s24, [r7, #8]
 *   @0x2e419c vstr s21, [r4, #224]
 *   @0x2e41a0 ldr r7, [r3, #0x8]
 *   @0x2e41a4 vstr s19, [r4, #228]
 *   @0x2e41a8 add r3, r5, r11
 *   @0x2e41ac vstr s22, [r4, #232]
 *   @0x2e41b0 ldr r11, [lr, #0x8]
 *   @0x2e41b4 vldr s23, [r3]
 *   @0x2e41b8 vldr s5, [r3, #4]
 *   @0x2e41bc vstr s20, [r4, #236]
 *   @0x2e41c0 vstr s5, [sp, #16]
 *   @0x2e41c4 vldr s6, [r3, #8]
 *   @0x2e41c8 vldr s11, [r10, #4]
 *   @0x2e41cc vldr s8, [r10]
 *   @0x2e41d0 vstr s11, [sp, #8]
 *   @0x2e41d4 vstr s6, [sp, #4]
 *   @0x2e41d8 vstr s8, [sp, #12]
 *   @0x2e41dc bl 0xb6580 <sinf@plt>
 *   @0x2e41e0 vldr s31, [r10, #8]
 *   @0x2e41e4 str r0, [sp, #0x18]
 *   @0x2e41e8 mov r0, r9
 *   @0x2e41ec bl 0xb658c <cosf@plt>
 *   @0x2e41f0 str r0, [sp, #0x1c]
 *   @0x2e41f4 mov r0, r8
 *   @0x2e41f8 bl 0xb6580 <sinf@plt>
 *   @0x2e41fc str r0, [sp, #0x20]
 *   @0x2e4200 mov r0, r8
 *   @0x2e4204 bl 0xb658c <cosf@plt>
 *   @0x2e4208 str r0, [sp, #0x24]
 *   @0x2e420c mov r0, r7
 *   @0x2e4210 bl 0xb6580 <sinf@plt>
 *   @0x2e4214 vmov s17, r0
 *   @0x2e4218 mov r0, r7
 *   @0x2e421c bl 0xb658c <cosf@plt>
 *   @0x2e4220 vmov s18, r0
 *   @0x2e4224 mov r0, r11
 *   @0x2e4228 bl 0xb6580 <sinf@plt>
 *   @0x2e422c vmov s16, r0
 *   @0x2e4230 mov r0, r11
 *   @0x2e4234 bl 0xb658c <cosf@plt>
 *   @0x2e4238 ldr r3, [r4, #0x4c]
 *   @0x2e423c vldr s11, [pc, #832]
 *   @0x2e4240 vstr s11, [r4, #272]
 *   @0x2e4244 cmp r3, #1
 *   @0x2e4248 vmov s12, r0
 *   @0x2e424c beq 0x2e4560 <_ZN11b2GearJoint23InitVelocityConstraintsERK12b2SolverData+0x4fc>
 *   @0x2e4250 vldr s15, [r4, #196]
 *   @0x2e4254 vldr s8, [r4, #112]
 *   @0x2e4258 vsub.f32 s8, s8, s15
 *   @0x2e425c vldr s13, [r4, #128]
 *   @0x2e4260 vldr s15, [r4, #192]
 *   @0x2e4264 vldr s9, [r4, #108]
 *   @0x2e4268 vldr s7, [r4, #96]
 *   @0x2e426c vldr s10, [r4, #180]
 *   @0x2e4270 vldr s6, [r4, #124]
 *   @0x2e4274 vldr s5, [sp, #28]
 *   @0x2e4278 vsub.f32 s9, s9, s15
 *   @0x2e427c vmul.f32 s14, s8, s18
 *   @0x2e4280 vmul.f32 s15, s13, s17
 *   @0x2e4284 vmul.f32 s8, s8, s17
 *   @0x2e4288 vsub.f32 s10, s7, s10
 *   @0x2e428c vldr s7, [r4, #92]
 *   @0x2e4290 vnmls.f32 s15, s6, s18
 *   @0x2e4294 vmla.f32 s14, s9, s17
 *   @0x2e4298 vstr s15, [r4, #240]
 *   @0x2e429c vmul.f32 s13, s13, s18
 *   @0x2e42a0 vnmls.f32 s8, s9, s18
 *   @0x2e42a4 vldr s9, [r4, #176]
 *   @0x2e42a8 vsub.f32 s7, s7, s9
 *   @0x2e42ac vmul.f32 s9, s10, s5
 *   @0x2e42b0 vmla.f32 s13, s6, s17
 *   @0x2e42b4 vldr s6, [sp, #24]
 *   @0x2e42b8 vmul.f32 s14, s15, s14
 *   @0x2e42bc vstr s13, [r4, #244]
 *   @0x2e42c0 vmul.f32 s10, s10, s6
 *   @0x2e42c4 vmla.f32 s9, s7, s6
 *   @0x2e42c8 vnmls.f32 s14, s13, s8
 *   @0x2e42cc vldr s8, [sp, #20]
 *   @0x2e42d0 vnmls.f32 s10, s7, s5
 *   @0x2e42d4 vstr s14, [r4, #264]
 *   @0x2e42d8 vmul.f32 s15, s15, s9
 *   @0x2e42dc vmul.f32 s22, s22, s14
 *   @0x2e42e0 vnmls.f32 s15, s13, s10
 *   @0x2e42e4 vadd.f32 s30, s8, s30
 *   @0x2e42e8 vstr s15, [r4, #256]
 *   @0x2e42ec vmla.f32 s30, s22, s14
 *   @0x2e42f0 vmul.f32 s21, s21, s15
 *   @0x2e42f4 vmla.f32 s30, s21, s15
 *   @0x2e42f8 vadd.f32 s30, s30, s11
 *   @0x2e42fc vmov.f32 s21, s30
 *   @0x2e4300 vstr s30, [r4, #272]
 *   @0x2e4304 ldr r3, [r4, #0x50]
 *   @0x2e4308 cmp r3, #1
 *   @0x2e430c beq 0x2e4534 <_ZN11b2GearJoint23InitVelocityConstraintsERK12b2SolverData+0x4d0>
 *   @0x2e4310 vldr s15, [r4, #204]
 *   @0x2e4314 vldr s8, [r4, #120]
 *   @0x2e4318 vsub.f32 s8, s8, s15
 *   @0x2e431c vldr s14, [r4, #136]
 *   @0x2e4320 vldr s1, [r4, #116]
 *   @0x2e4324 vldr s4, [r4, #200]
 *   @0x2e4328 vldr s5, [r4, #132]
 *   @0x2e432c vldr s2, [r4, #104]
 *   @0x2e4330 vldr s9, [r4, #188]
 *   @0x2e4334 vldr s3, [r4, #100]
 *   @0x2e4338 vldr s7, [r4, #184]
 *   @0x2e433c vldr s15, [r4, #152]
 *   @0x2e4340 vldr s6, [r4, #220]
 *   @0x2e4344 vldr s11, [r4, #212]
 *   @0x2e4348 vmul.f32 s10, s8, s12
 *   @0x2e434c vmul.f32 s13, s14, s16
 *   @0x2e4350 vsub.f32 s4, s1, s4
 *   @0x2e4354 vnmls.f32 s13, s5, s12
 *   @0x2e4358 vmul.f32 s14, s14, s12
 *   @0x2e435c vmul.f32 s8, s8, s16
 *   @0x2e4360 vmla.f32 s10, s4, s16
 *   @0x2e4364 vsub.f32 s9, s2, s9
 *   @0x2e4368 vmla.f32 s14, s5, s16
 *   @0x2e436c vldr s5, [sp, #36]
 *   @0x2e4370 vnmls.f32 s8, s4, s12
 *   @0x2e4374 vmul.f32 s10, s13, s10
 *   @0x2e4378 vmul.f32 s12, s9, s5
 *   @0x2e437c vsub.f32 s7, s3, s7
 *   @0x2e4380 vnmls.f32 s10, s14, s8
 *   @0x2e4384 vldr s8, [sp, #32]
 *   @0x2e4388 vmul.f32 s9, s9, s8
 *   @0x2e438c vmla.f32 s12, s7, s8
 *   @0x2e4390 vnmls.f32 s9, s7, s5
 *   @0x2e4394 vmul.f32 s10, s15, s10
 *   @0x2e4398 vmul.f32 s12, s13, s12
 *   @0x2e439c vstr s10, [r4, #268]
 *   @0x2e43a0 vnmls.f32 s12, s14, s9
 *   @0x2e43a4 vmul.f32 s20, s20, s10
 *   @0x2e43a8 vmul.f32 s9, s15, s15
 *   @0x2e43ac vmul.f32 s20, s10, s20
 *   @0x2e43b0 vadd.f32 s11, s6, s11
 *   @0x2e43b4 vmul.f32 s12, s15, s12
 *   @0x2e43b8 vmla.f32 s20, s9, s11
 *   @0x2e43bc vstr s12, [r4, #260]
 *   @0x2e43c0 vmul.f32 s19, s19, s12
 *   @0x2e43c4 vmla.f32 s20, s12, s19
 *   @0x2e43c8 vmul.f32 s13, s15, s13
 *   @0x2e43cc vmul.f32 s15, s15, s14
 *   @0x2e43d0 vstr s13, [r4, #248]
 *   @0x2e43d4 vadd.f32 s20, s21, s20
 *   @0x2e43d8 vstr s15, [r4, #252]
 *   @0x2e43dc ldrb r3, [r6, #0x14]
 *   @0x2e43e0 vcmpe.f32 s20, #0
 *   @0x2e43e4 vmrs APSR_nzcv, fpscr
 *   @0x2e43e8 vmovgt.f32 s15, #1.000000e+00
 *   @0x2e43ec vldrle s20, [pc, #400]
 *   @0x2e43f0 vdivgt.f32 s20, s15, s20
 *   @0x2e43f4 cmp r3, #0
 *   @0x2e43f8 moveq r3, #0
 *   @0x2e43fc streq r3, [r4, #0x9c]
 *   @0x2e4400 vstr s20, [r4, #272]
 *   @0x2e4404 beq 0x2e44bc <_ZN11b2GearJoint23InitVelocityConstraintsERK12b2SolverData+0x458>
 *   @0x2e4408 vldr s15, [r4, #156]
 *   @0x2e440c vldr s7, [r4, #208]
 *   @0x2e4410 vldr s9, [r4, #216]
 *   @0x2e4414 vmul.f32 s7, s15, s7
 *   @0x2e4418 vldr s0, [r4, #224]
 *   @0x2e441c vldr s11, [r4, #212]
 *   @0x2e4420 vldr s13, [r4, #220]
 *   @0x2e4424 vldr s2, [r4, #228]
 *   @0x2e4428 vldr s4, [r4, #232]
 *   @0x2e442c vldr s16, [r4, #236]
 *   @0x2e4430 vldr s8, [r4, #240]
 *   @0x2e4434 vldr s12, [r4, #248]
 *   @0x2e4438 vldr s10, [r4, #244]
 *   @0x2e443c vldr s14, [r4, #252]
 *   @0x2e4440 vldr s1, [r4, #256]
 *   @0x2e4444 vldr s3, [r4, #260]
 *   @0x2e4448 vldr s5, [r4, #264]
 *   @0x2e444c vldr s6, [r4, #268]
 *   @0x2e4450 vmul.f32 s11, s15, s11
 *   @0x2e4454 vmul.f32 s13, s15, s13
 *   @0x2e4458 vmul.f32 s9, s15, s9
 *   @0x2e445c vmul.f32 s0, s15, s0
 *   @0x2e4460 vmul.f32 s2, s15, s2
 *   @0x2e4464 vmul.f32 s4, s15, s4
 *   @0x2e4468 vmul.f32 s15, s15, s16
 *   @0x2e446c vmla.f32 s26, s11, s12
 *   @0x2e4470 vmla.f32 s29, s7, s8
 *   @0x2e4474 vmls.f32 s23, s9, s8
 *   @0x2e4478 vldr s8, [sp, #16]
 *   @0x2e447c vmla.f32 s25, s11, s14
 *   @0x2e4480 vldr s11, [sp, #12]
 *   @0x2e4484 vmls.f32 s8, s9, s10
 *   @0x2e4488 vmls.f32 s11, s13, s12
 *   @0x2e448c vldr s12, [sp, #8]
 *   @0x2e4490 vstr s8, [sp, #16]
 *   @0x2e4494 vmls.f32 s12, s13, s14
 *   @0x2e4498 vldr s13, [sp, #4]
 *   @0x2e449c vstr s11, [sp, #12]
 *   @0x2e44a0 vmls.f32 s13, s4, s5
 *   @0x2e44a4 vstr s12, [sp, #8]
 *   @0x2e44a8 vmla.f32 s28, s7, s10
 *   @0x2e44ac vstr s13, [sp, #4]
 *   @0x2e44b0 vmla.f32 s27, s0, s1
 *   @0x2e44b4 vmla.f32 s24, s2, s3
 *   @0x2e44b8 vmls.f32 s31, s15, s6
 *   @0x2e44bc add r1, r4, #160
 *   @0x2e44c0 ldr r0, [r4, #0xac]
 *   @0x2e44c4 vldr s14, [sp, #16]
 *   @0x2e44c8 vldr s15, [sp, #4]
 *   @0x2e44cc ldm r1, {r1, r2, r3}
 *   @0x2e44d0 vldr s5, [sp, #12]
 *   @0x2e44d4 add r0, r0, r0, lsl #1
 *   @0x2e44d8 vldr s6, [sp, #8]
 *   @0x2e44dc add r2, r2, r2, lsl #1
 *   @0x2e44e0 add r3, r3, r3, lsl #1
 *   @0x2e44e4 add r1, r1, r1, lsl #1
 *   @0x2e44e8 add r2, r5, r2, lsl #2
 *   @0x2e44ec add r3, r5, r3, lsl #2
 *   @0x2e44f0 add r1, r5, r1, lsl #2
 *   @0x2e44f4 add r5, r5, r0, lsl #2
 *   @0x2e44f8 vstr s29, [r1]
 *   @0x2e44fc vstr s28, [r1, #4]
 *   @0x2e4500 vstr s27, [r1, #8]
 *   @0x2e4504 vstr s26, [r2]
 *   @0x2e4508 vstr s25, [r2, #4]
 *   @0x2e450c vstr s24, [r2, #8]
 *   @0x2e4510 vstr s23, [r3]
 *   @0x2e4514 vstr s14, [r3, #4]
 *   @0x2e4518 vstr s15, [r3, #8]
 *   @0x2e451c vstr s5, [r5]
 *   @0x2e4520 vstr s6, [r5, #4]
 *   @0x2e4524 vstr s31, [r5, #8]
 *   @0x2e4528 add sp, sp, #44
 *   @0x2e452c vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e4530 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e4534 vldr s15, [r4, #152]
 *   @0x2e4538 vmul.f32 s14, s15, s15
 *   @0x2e453c mov r3, #0
 *   @0x2e4540 vstr s15, [r4, #260]
 *   @0x2e4544 vstr s15, [r4, #268]
 *   @0x2e4548 str r3, [r4, #0xf8]
 *   @0x2e454c str r3, [r4, #0xfc]
 *   @0x2e4550 vadd.f32 s19, s19, s20
 *   @0x2e4554 vmov.f32 s20, s21
 *   @0x2e4558 vmla.f32 s20, s14, s19
 *   @0x2e455c b 0x2e43dc <_ZN11b2GearJoint23InitVelocityConstraintsERK12b2SolverData+0x378>
 *   @0x2e4560 vadd.f32 s21, s21, s22
 *   @0x2e4564 mov r3, #1065353216
 *   @0x2e4568 vstr s11, [r4, #240]
 *   @0x2e456c vstr s11, [r4, #244]
 *   @0x2e4570 str r3, [r4, #0x100]
 *   @0x2e4574 str r3, [r4, #0x108]
 *   @0x2e4578 vadd.f32 s21, s21, s11
 *   @0x2e457c vstr s21, [r4, #272]
 *   @0x2e4580 b 0x2e4304 <_ZN11b2GearJoint23InitVelocityConstraintsERK12b2SolverData+0x2a0>
 *   @0x2e4584 andeq r0, r0, r0
 *
 * ══ §12/23 F_JS_Object_DefaultValue(YYObjectBase*, RValue&, int)  0x24c844  size 1312  328 条（0x24c844..0x24cd64）
 * @func 0x24c844 0x24cd64  size 1312  328 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×6 / YYFree(void const*)×6 / FREE_RValue__Pre(RValue*)×5 / operator delete(void*)×5 / UNLOCK_RVALUE_MUTEX()×4 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×3 / JS_IsCallable(RValue&)×3 / Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*)×3
 * 字段偏移 top8: 0x4×12 / 0x34×8 / 0x8×8 / 0x28×6 / 0xc×3 / 0x14×2 / 0x4e4×1 / 0x4bc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24c844 cmp r2, #10
 *   @0x24c848 push {r4, r5, r6, r7, r8, lr}
 *   @0x24c84c mov r4, r0
 *   @0x24c850 sub sp, sp, #56
 *   @0x24c854 mov r5, r1
 *   @0x24c858 bne 0x24c8c8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x84>
 *   @0x24c85c add r7, sp, #8
 *   @0x24c860 ldr r2, [pc, #0x4e4]
 *   @0x24c864 mov r0, r4
 *   @0x24c868 mov r8, #5
 *   @0x24c86c add r2, pc, r2
 *   @0x24c870 mov r1, r7
 *   @0x24c874 str r8, [sp, #0x14]
 *   @0x24c878 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24c87c mov r0, r7
 *   @0x24c880 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x24c884 cmp r0, #0
 *   @0x24c888 bne 0x24ca6c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x228>
 *   @0x24c88c ldr r2, [pc, #0x4bc]
 *   @0x24c890 add r7, sp, #24
 *   @0x24c894 mov r0, r4
 *   @0x24c898 add r2, pc, r2
 *   @0x24c89c mov r1, r7
 *   @0x24c8a0 mov r8, #5
 *   @0x24c8a4 str r8, [sp, #0x24]
 *   @0x24c8a8 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24c8ac mov r0, r7
 *   @0x24c8b0 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x24c8b4 cmp r0, #0
 *   @0x24c8b8 bne 0x24cb0c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2c8>
 *   @0x24c8bc mov r0, #1
 *   @0x24c8c0 add sp, sp, #56
 *   @0x24c8c4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x24c8c8 cmp r2, #7
 *   @0x24c8cc cmpne r2, #1
 *   @0x24c8d0 bls 0x24c9f0 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x1ac>
 *   @0x24c8d4 ldr r1, [pc, #0x478]
 *   @0x24c8d8 ldr r0, [r0, #0x40]
 *   @0x24c8dc add r1, pc, r1
 *   @0x24c8e0 bl 0xb6574 <strcmp@plt>
 *   @0x24c8e4 cmp r0, #0
 *   @0x24c8e8 bne 0x24c85c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x18>
 *   @0x24c8ec add r7, sp, #8
 *   @0x24c8f0 ldr r2, [pc, #0x460]
 *   @0x24c8f4 mov r0, r4
 *   @0x24c8f8 mov r8, #5
 *   @0x24c8fc add r2, pc, r2
 *   @0x24c900 mov r1, r7
 *   @0x24c904 str r8, [sp, #0x14]
 *   @0x24c908 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24c90c mov r0, r7
 *   @0x24c910 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x24c914 cmp r0, #0
 *   @0x24c918 beq 0x24ca48 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x204>
 *   @0x24c91c add r6, sp, #40
 *   @0x24c920 mov r3, #0
 *   @0x24c924 mov r2, r7
 *   @0x24c928 str r3, [sp]
 *   @0x24c92c mov r1, r6
 *   @0x24c930 mov r0, r4
 *   @0x24c934 str r8, [sp, #0x34]
 *   @0x24c938 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x24c93c cmp r0, #2
 *   @0x24c940 beq 0x24c8c0 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x7c>
 *   @0x24c944 mov r0, r6
 *   @0x24c948 bl 0x241dc0 <_Z16F_JS_IsPrimitiveR6RValue>
 *   @0x24c94c cmp r0, #0
 *   @0x24c950 beq 0x24ca28 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x1e4>
 *   @0x24c954 ldr r2, [r5, #0xc]
 *   @0x24c958 bic r3, r2, #-16777216
 *   @0x24c95c cmp r3, #1
 *   @0x24c960 beq 0x24cc18 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x3d4>
 *   @0x24c964 cmp r3, #2
 *   @0x24c968 bne 0x24c988 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x144>
 *   @0x24c96c sub r3, r2, #1
 *   @0x24c970 bic r3, r3, #-16777216
 *   @0x24c974 bic r3, r3, #3
 *   @0x24c978 cmp r3, #0
 *   @0x24c97c bne 0x24c988 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x144>
 *   @0x24c980 mov r0, r5
 *   @0x24c984 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24c988 ldr r3, [sp, #0x34]
 *   @0x24c98c mov r0, #0
 *   @0x24c990 ldr r1, [sp, #0x30]
 *   @0x24c994 bic r2, r3, #-16777216
 *   @0x24c998 str r0, [r5]
 *   @0x24c99c str r3, [r5, #0xc]
 *   @0x24c9a0 mov r0, r3
 *   @0x24c9a4 str r1, [r5, #0x8]
 *   @0x24c9a8 cmp r2, #14
 *   @0x24c9ac addls pc, pc, r2, lsl #2
 *   @0x24c9b0 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4>
 *   @0x24c9b4 b 0x24cbb8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x374>
 *   @0x24c9b8 b 0x24cbf4 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x3b0>
 *   @0x24c9bc b 0x24cbc8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x384>
 *   @0x24c9c0 b 0x24cb88 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x344>
 *   @0x24c9c4 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4>
 *   @0x24c9c8 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4>
 *   @0x24c9cc b 0x24cac8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x284>
 *   @0x24c9d0 b 0x24cb88 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x344>
 *   @0x24c9d4 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4>
 *   @0x24c9d8 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4>
 *   @0x24c9dc b 0x24cbb8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x374>
 *   @0x24c9e0 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4>
 *   @0x24c9e4 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4>
 *   @0x24c9e8 b 0x24cbb8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x374>
 *   @0x24c9ec b 0x24cb88 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x344>
 *   @0x24c9f0 cmp r2, #10
 *   @0x24c9f4 addls pc, pc, r2, lsl #2
 *   @0x24c9f8 b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218>
 *   @0x24c9fc b 0x24c85c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x18>
 *   @0x24ca00 b 0x24c8ec <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0xa8>
 *   @0x24ca04 b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218>
 *   @0x24ca08 b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218>
 *   @0x24ca0c b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218>
 *   @0x24ca10 b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218>
 *   @0x24ca14 b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218>
 *   @0x24ca18 b 0x24c85c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x18>
 *   @0x24ca1c b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218>
 *   @0x24ca20 b 0x24ca5c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x218>
 *   @0x24ca24 b 0x24c85c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x18>
 *   @0x24ca28 ldr r3, [sp, #0x34]
 *   @0x24ca2c sub r3, r3, #1
 *   @0x24ca30 bic r3, r3, #-16777216
 *   @0x24ca34 bic r3, r3, #3
 *   @0x24ca38 cmp r3, #0
 *   @0x24ca3c bne 0x24ca48 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x204>
 *   @0x24ca40 mov r0, r6
 *   @0x24ca44 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24ca48 ldr r2, [pc, #0x30c]
 *   @0x24ca4c add r7, sp, #24
 *   @0x24ca50 mov r0, r4
 *   @0x24ca54 add r2, pc, r2
 *   @0x24ca58 b 0x24c89c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x58>
 *   @0x24ca5c ldr r0, [pc, #0x2fc]
 *   @0x24ca60 add r0, pc, r0
 *   @0x24ca64 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0x24ca68 b 0x24c8bc <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x78>
 *   @0x24ca6c add r6, sp, #40
 *   @0x24ca70 mov r3, #0
 *   @0x24ca74 mov r2, r7
 *   @0x24ca78 str r3, [sp]
 *   @0x24ca7c mov r1, r6
 *   @0x24ca80 mov r0, r4
 *   @0x24ca84 str r8, [sp, #0x34]
 *   @0x24ca88 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x24ca8c cmp r0, #2
 *   @0x24ca90 beq 0x24c8c0 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x7c>
 *   @0x24ca94 mov r0, r6
 *   @0x24ca98 bl 0x241dc0 <_Z16F_JS_IsPrimitiveR6RValue>
 *   @0x24ca9c cmp r0, #0
 *   @0x24caa0 bne 0x24c954 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x110>
 *   @0x24caa4 ldr r3, [sp, #0x34]
 *   @0x24caa8 sub r3, r3, #1
 *   @0x24caac bic r3, r3, #-16777216
 *   @0x24cab0 bic r3, r3, #3
 *   @0x24cab4 cmp r3, #0
 *   @0x24cab8 bne 0x24c88c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x48>
 *   @0x24cabc mov r0, r6
 *   @0x24cac0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24cac4 b 0x24c88c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x48>
 *   @0x24cac8 ldr r3, [sp, #0x28]
 *   @0x24cacc cmp r3, #0
 *   @0x24cad0 str r3, [r5]
 *   @0x24cad4 beq 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4>
 *   @0x24cad8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x24cadc ldr r1, [sp, #0x28]
 *   @0x24cae0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x24cae4 ldr r0, [sp, #0x34]
 *   @0x24cae8 sub r0, r0, #1
 *   @0x24caec bic r0, r0, #-16777216
 *   @0x24caf0 bics r4, r0, #3
 *   @0x24caf4 movne r0, #0
 *   @0x24caf8 bne 0x24c8c0 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x7c>
 *   @0x24cafc mov r0, r6
 *   @0x24cb00 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24cb04 mov r0, r4
 *   @0x24cb08 b 0x24c8c0 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x7c>
 *   @0x24cb0c add r6, sp, #40
 *   @0x24cb10 mov r3, #0
 *   @0x24cb14 mov r0, r4
 *   @0x24cb18 mov r2, r7
 *   @0x24cb1c mov r1, r6
 *   @0x24cb20 str r3, [sp]
 *   @0x24cb24 str r8, [sp, #0x34]
 *   @0x24cb28 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x24cb2c cmp r0, #2
 *   @0x24cb30 beq 0x24c8c0 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x7c>
 *   @0x24cb34 mov r0, r6
 *   @0x24cb38 bl 0x241dc0 <_Z16F_JS_IsPrimitiveR6RValue>
 *   @0x24cb3c cmp r0, #0
 *   @0x24cb40 beq 0x24cb94 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x350>
 *   @0x24cb44 ldr r2, [r5, #0xc]
 *   @0x24cb48 bic r3, r2, #-16777216
 *   @0x24cb4c cmp r3, #1
 *   @0x24cb50 bne 0x24c964 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x120>
 *   @0x24cb54 ldr r4, [r5]
 *   @0x24cb58 cmp r4, #0
 *   @0x24cb5c beq 0x24cb7c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x338>
 *   @0x24cb60 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24cb64 ldr r7, [r4, #0x4]
 *   @0x24cb68 sub r7, r7, #1
 *   @0x24cb6c str r7, [r4, #0x4]
 *   @0x24cb70 cmp r7, #0
 *   @0x24cb74 beq 0x24cc94 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x450>
 *   @0x24cb78 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24cb7c mov r3, #0
 *   @0x24cb80 str r3, [r5]
 *   @0x24cb84 b 0x24c988 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x144>
 *   @0x24cb88 ldr r3, [sp, #0x28]
 *   @0x24cb8c str r3, [r5]
 *   @0x24cb90 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4>
 *   @0x24cb94 ldr r3, [sp, #0x34]
 *   @0x24cb98 sub r3, r3, #1
 *   @0x24cb9c bic r3, r3, #-16777216
 *   @0x24cba0 bic r3, r3, #3
 *   @0x24cba4 cmp r3, #0
 *   @0x24cba8 bne 0x24c8bc <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x78>
 *   @0x24cbac mov r0, r6
 *   @0x24cbb0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24cbb4 b 0x24c8bc <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x78>
 *   @0x24cbb8 ldr r2, [sp, #0x28]
 *   @0x24cbbc ldr r3, [sp, #0x2c]
 *   @0x24cbc0 stm r5, {r2, r3}
 *   @0x24cbc4 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4>
 *   @0x24cbc8 ldr r3, [sp, #0x28]
 *   @0x24cbcc cmp r3, #0
 *   @0x24cbd0 str r3, [r5]
 *   @0x24cbd4 beq 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4>
 *   @0x24cbd8 ldr r1, [r3, #0x8]
 *   @0x24cbdc ldr r2, [r3]
 *   @0x24cbe0 cmp r1, #0
 *   @0x24cbe4 streq r5, [r3, #0x8]
 *   @0x24cbe8 add r2, r2, #1
 *   @0x24cbec str r2, [r3]
 *   @0x24cbf0 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4>
 *   @0x24cbf4 ldr r2, [sp, #0x28]
 *   @0x24cbf8 cmp r2, #0
 *   @0x24cbfc ldrne r3, [r2, #0x4]
 *   @0x24cc00 addne r3, r3, #1
 *   @0x24cc04 strne r3, [r2, #0x4]
 *   @0x24cc08 ldrne r3, [sp, #0x34]
 *   @0x24cc0c str r2, [r5]
 *   @0x24cc10 mov r0, r3
 *   @0x24cc14 b 0x24cae8 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x2a4>
 *   @0x24cc18 ldr r4, [r5]
 *   @0x24cc1c cmp r4, #0
 *   @0x24cc20 beq 0x24cb7c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x338>
 *   @0x24cc24 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24cc28 ldr r7, [r4, #0x4]
 *   @0x24cc2c sub r7, r7, #1
 *   @0x24cc30 str r7, [r4, #0x4]
 *   @0x24cc34 cmp r7, #0
 *   @0x24cc38 bne 0x24cb78 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x334>
 *   @0x24cc3c ldr r0, [r4]
 *   @0x24cc40 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24cc44 str r7, [r4]
 *   @0x24cc48 str r7, [r4, #0x8]
 *   @0x24cc4c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24cc50 ldr r7, [r4, #0x4]
 *   @0x24cc54 sub r7, r7, #1
 *   @0x24cc58 str r7, [r4, #0x4]
 *   @0x24cc5c cmp r7, #0
 *   @0x24cc60 bne 0x24cc84 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x440>
 *   @0x24cc64 ldr r0, [r4]
 *   @0x24cc68 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24cc6c mov r0, r4
 *   @0x24cc70 str r7, [r4]
 *   @0x24cc74 str r7, [r4, #0x8]
 *   @0x24cc78 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x24cc7c mov r0, r4
 *   @0x24cc80 bl 0x27d1d0 <_ZdlPv>
 *   @0x24cc84 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24cc88 mov r0, r4
 *   @0x24cc8c bl 0x27d1d0 <_ZdlPv>
 *   @0x24cc90 b 0x24cb78 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x334>
 *   @0x24cc94 ldr r0, [r4]
 *   @0x24cc98 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24cc9c str r7, [r4]
 *   @0x24cca0 str r7, [r4, #0x8]
 *   @0x24cca4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24cca8 ldr r7, [r4, #0x4]
 *   @0x24ccac sub r7, r7, #1
 *   @0x24ccb0 str r7, [r4, #0x4]
 *   @0x24ccb4 cmp r7, #0
 *   @0x24ccb8 bne 0x24cc84 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x440>
 *   @0x24ccbc ldr r0, [r4]
 *   @0x24ccc0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24ccc4 str r7, [r4]
 *   @0x24ccc8 str r7, [r4, #0x8]
 *   @0x24cccc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24ccd0 ldr r7, [r4, #0x4]
 *   @0x24ccd4 sub r7, r7, #1
 *   @0x24ccd8 str r7, [r4, #0x4]
 *   @0x24ccdc cmp r7, #0
 *   @0x24cce0 beq 0x24ccf4 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x4b0>
 *   @0x24cce4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24cce8 mov r0, r4
 *   @0x24ccec bl 0x27d1d0 <_ZdlPv>
 *   @0x24ccf0 b 0x24cc84 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x440>
 *   @0x24ccf4 ldr r0, [r4]
 *   @0x24ccf8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24ccfc str r7, [r4]
 *   @0x24cd00 str r7, [r4, #0x8]
 *   @0x24cd04 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24cd08 ldr r7, [r4, #0x4]
 *   @0x24cd0c sub r7, r7, #1
 *   @0x24cd10 str r7, [r4, #0x4]
 *   @0x24cd14 cmp r7, #0
 *   @0x24cd18 bne 0x24cd3c <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x4f8>
 *   @0x24cd1c ldr r0, [r4]
 *   @0x24cd20 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24cd24 mov r0, r4
 *   @0x24cd28 str r7, [r4]
 *   @0x24cd2c str r7, [r4, #0x8]
 *   @0x24cd30 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x24cd34 mov r0, r4
 *   @0x24cd38 bl 0x27d1d0 <_ZdlPv>
 *   @0x24cd3c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24cd40 mov r0, r4
 *   @0x24cd44 bl 0x27d1d0 <_ZdlPv>
 *   @0x24cd48 b 0x24cce4 <_Z24F_JS_Object_DefaultValueP12YYObjectBaseR6RValuei+0x4a0>
 *   @0x24cd4c andseq r8, r0, r12, ror #27
 *   @0x24cd50 andeq r5, lr, r8, ror r12
 *   @0x24cd54 andseq r9, r0, r0, lsr #2
 *   @0x24cd58 andeq r5, lr, r4, lsl r12
 *   @0x24cd5c andseq r8, r0, r4, lsl #24
 *   @0x24cd60 andseq r9, r0, r4, lsl #8
 *
 * ══ §13/23 JS_Array_prototype_toLocaleString(RValue&, CInstance*, CInstance*, int, RValue*)  0x253428  size 1312  328 条（0x253428..0x253948）
 * @func 0x253428 0x253948  size 1312  328 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×8 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×3 / YYFree(void const*)×3 / YYAlloc(int)×2 / 0xb65bc×2 / YYGetUint32(RValue const*, int) / 0xb65c8 / F_JS_ToObject(RValue&, RValue*)
 * 字段偏移 top8: 0x38×11 / 0x30×10 / 0x34×7 / 0x48×5 / 0x58×5 / 0x14×4 / 0x78×4 / 0x88×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x253428 ldr r12, [pc, #0x500]
 *   @0x25342c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x253430 sub sp, sp, #180
 *   @0x253434 ldr r2, [pc, #0x4f8]
 *   @0x253438 mov r7, r1
 *   @0x25343c str r12, [sp, #0x14]
 *   @0x253440 add r12, sp, #60
 *   @0x253444 str r12, [sp, #0x20]
 *   @0x253448 add r2, pc, r2
 *   @0x25344c ldr r12, [sp, #0x14]
 *   @0x253450 mov r6, #5
 *   @0x253454 str r0, [sp, #0x2c]
 *   @0x253458 mov r0, r1
 *   @0x25345c ldr r12, [pc, r12]
 *   @0x253460 add r1, sp, #60
 *   @0x253464 str r12, [sp, #0x14]
 *   @0x253468 ldr r3, [r12]
 *   @0x25346c str r6, [sp, #0x48]
 *   @0x253470 str r3, [sp, #0xac]
 *   @0x253474 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x253478 add r0, sp, #60
 *   @0x25347c mov r1, #0
 *   @0x253480 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x253484 mov r12, #0
 *   @0x253488 str r12, [sp, #0x30]
 *   @0x25348c str r12, [sp, #0x34]
 *   @0x253490 str r12, [sp, #0x38]
 *   @0x253494 cmp r0, #0
 *   @0x253498 str r0, [sp, #0xc]
 *   @0x25349c beq 0x253818 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3f0>
 *   @0x2534a0 mov r10, r12
 *   @0x2534a4 ldr r11, [pc, #0x48c]
 *   @0x2534a8 ldr r12, [pc, #0x48c]
 *   @0x2534ac add r4, sp, #140
 *   @0x2534b0 add r5, sp, #76
 *   @0x2534b4 add r11, pc, r11
 *   @0x2534b8 add r12, pc, r12
 *   @0x2534bc str r12, [sp, #0x18]
 *   @0x2534c0 ldr r12, [pc, #0x478]
 *   @0x2534c4 add r12, pc, r12
 *   @0x2534c8 str r12, [sp, #0x10]
 *   @0x2534cc mov r3, r10
 *   @0x2534d0 mov r1, #32
 *   @0x2534d4 mov r2, r11
 *   @0x2534d8 mov r0, r4
 *   @0x2534dc bl 0xb65c8 <snprintf@plt>
 *   @0x2534e0 mov r2, r4
 *   @0x2534e4 mov r0, r7
 *   @0x2534e8 mov r1, r5
 *   @0x2534ec str r6, [sp, #0x58]
 *   @0x2534f0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x2534f4 ldr r2, [sp, #0x58]
 *   @0x2534f8 bic r3, r2, #-16777216
 *   @0x2534fc cmp r3, #12
 *   @0x253500 beq 0x25365c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0x253504 mvn r8, #-16777216
 *   @0x253508 cmp r3, r8
 *   @0x25350c beq 0x253654 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x22c>
 *   @0x253510 cmp r3, #5
 *   @0x253514 beq 0x25365c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0x253518 add r0, sp, #92
 *   @0x25351c mov r1, r5
 *   @0x253520 bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_>
 *   @0x253524 cmp r0, #1
 *   @0x253528 beq 0x253820 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3f8>
 *   @0x25352c ldr r3, [sp, #0x68]
 *   @0x253530 bic r3, r3, #-16777216
 *   @0x253534 cmp r3, r8
 *   @0x253538 beq 0x25357c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x25353c add r8, sp, #108
 *   @0x253540 ldr r0, [sp, #0x5c]
 *   @0x253544 ldr r2, [sp, #0x18]
 *   @0x253548 mov r1, r8
 *   @0x25354c str r6, [sp, #0x78]
 *   @0x253550 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x253554 mov r0, r8
 *   @0x253558 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x25355c cmp r0, #0
 *   @0x253560 bne 0x2536f4 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x2cc>
 *   @0x253564 ldr r3, [sp, #0x78]
 *   @0x253568 sub r3, r3, #1
 *   @0x25356c bic r3, r3, #-16777216
 *   @0x253570 bic r3, r3, #3
 *   @0x253574 cmp r3, #0
 *   @0x253578 beq 0x25380c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3e4>
 *   @0x25357c ldr r2, [sp, #0x58]
 *   @0x253580 mov r8, #0
 *   @0x253584 sub r2, r2, #1
 *   @0x253588 bic r2, r2, #-16777216
 *   @0x25358c bic r2, r2, #3
 *   @0x253590 cmp r2, #0
 *   @0x253594 beq 0x253664 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x23c>
 *   @0x253598 ldr r12, [sp, #0xc]
 *   @0x25359c add r10, r10, #1
 *   @0x2535a0 cmp r10, r12
 *   @0x2535a4 beq 0x25367c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x254>
 *   @0x2535a8 eor r8, r8, #1
 *   @0x2535ac cmp r10, #0
 *   @0x2535b0 moveq r8, #0
 *   @0x2535b4 andne r8, r8, #1
 *   @0x2535b8 cmp r8, #0
 *   @0x2535bc beq 0x2534cc <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x2535c0 ldr r3, [sp, #0x38]
 *   @0x2535c4 ldr r2, [sp, #0x34]
 *   @0x2535c8 mvn r1, r3
 *   @0x2535cc add r1, r2, r1
 *   @0x2535d0 cmp r1, #1
 *   @0x2535d4 bgt 0x253634 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x2535d8 cmp r2, #0
 *   @0x2535dc add r3, r3, #2
 *   @0x2535e0 addne r2, r2, r2, lsl #1
 *   @0x2535e4 ldr r9, [sp, #0x30]
 *   @0x2535e8 moveq r8, #3
 *   @0x2535ec addne r2, r2, r2, lsr #31
 *   @0x2535f0 asrne r8, r2, #1
 *   @0x2535f4 cmp r3, r8
 *   @0x2535f8 addgt r3, r3, r3, lsl #1
 *   @0x2535fc addgt r3, r3, r3, lsr #31
 *   @0x253600 asrgt r8, r3, #1
 *   @0x253604 mov r0, r8
 *   @0x253608 bl 0xcef4c <_Z7YYAlloci>
 *   @0x25360c ldr r2, [sp, #0x34]
 *   @0x253610 mov r1, r9
 *   @0x253614 str r0, [sp, #0x30]
 *   @0x253618 bl 0xb65bc <memcpy@plt>
 *   @0x25361c cmp r9, #0
 *   @0x253620 str r8, [sp, #0x34]
 *   @0x253624 beq 0x253630 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x253628 mov r0, r9
 *   @0x25362c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x253630 ldr r3, [sp, #0x38]
 *   @0x253634 ldr r12, [sp, #0x10]
 *   @0x253638 ldr r2, [sp, #0x30]
 *   @0x25363c ldrh r1, [r12]
 *   @0x253640 strh r1, [r2, r3]
 *   @0x253644 ldr r3, [sp, #0x38]
 *   @0x253648 add r3, r3, #1
 *   @0x25364c str r3, [sp, #0x38]
 *   @0x253650 b 0x2534cc <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x253654 mov r8, #1
 *   @0x253658 b 0x253584 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x25365c mov r8, #0
 *   @0x253660 b 0x253584 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x253664 mov r0, r5
 *   @0x253668 add r10, r10, #1
 *   @0x25366c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253670 ldr r12, [sp, #0xc]
 *   @0x253674 cmp r10, r12
 *   @0x253678 bne 0x2535a8 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x25367c ldr r3, [sp, #0x38]
 *   @0x253680 cmp r3, #0
 *   @0x253684 beq 0x253818 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3f0>
 *   @0x253688 ldr r1, [sp, #0x30]
 *   @0x25368c ldr r0, [sp, #0x2c]
 *   @0x253690 mov r3, #0
 *   @0x253694 str r3, [sp, #0x38]
 *   @0x253698 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x25369c ldr r3, [sp, #0x48]
 *   @0x2536a0 sub r3, r3, #1
 *   @0x2536a4 bic r3, r3, #-16777216
 *   @0x2536a8 bic r3, r3, #3
 *   @0x2536ac cmp r3, #0
 *   @0x2536b0 beq 0x25383c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x414>
 *   @0x2536b4 ldr r0, [sp, #0x30]
 *   @0x2536b8 mov r3, #0
 *   @0x2536bc mov r2, #5
 *   @0x2536c0 str r3, [sp, #0x44]
 *   @0x2536c4 cmp r0, r3
 *   @0x2536c8 str r3, [sp, #0x3c]
 *   @0x2536cc str r2, [sp, #0x48]
 *   @0x2536d0 beq 0x2536d8 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x2b0>
 *   @0x2536d4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2536d8 ldr r12, [sp, #0x14]
 *   @0x2536dc ldr r2, [sp, #0xac]
 *   @0x2536e0 ldr r3, [r12]
 *   @0x2536e4 cmp r2, r3
 *   @0x2536e8 bne 0x25392c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x504>
 *   @0x2536ec add sp, sp, #180
 *   @0x2536f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2536f4 add r12, sp, #124
 *   @0x2536f8 mov r1, #0
 *   @0x2536fc ldr r0, [sp, #0x5c]
 *   @0x253700 mov r2, r8
 *   @0x253704 str r1, [sp]
 *   @0x253708 mov r3, #0
 *   @0x25370c mov r1, r12
 *   @0x253710 str r12, [sp, #0x1c]
 *   @0x253714 str r6, [sp, #0x88]
 *   @0x253718 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x25371c cmp r0, #2
 *   @0x253720 beq 0x253848 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x420>
 *   @0x253724 add r0, sp, #124
 *   @0x253728 mov r1, #0
 *   @0x25372c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x253730 subs r3, r0, #0
 *   @0x253734 str r3, [sp, #0x24]
 *   @0x253738 beq 0x2537e8 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3c0>
 *   @0x25373c bl 0xb6538 <strlen@plt>
 *   @0x253740 ldr r2, [sp, #0x38]
 *   @0x253744 ldr r3, [sp, #0x34]
 *   @0x253748 add r1, r0, #1
 *   @0x25374c mov r9, r0
 *   @0x253750 mvn r0, r2
 *   @0x253754 add r0, r3, r0
 *   @0x253758 cmp r1, r0
 *   @0x25375c ble 0x2537cc <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3a4>
 *   @0x253760 cmp r3, #0
 *   @0x253764 add r2, r1, r2
 *   @0x253768 ldr r12, [sp, #0x30]
 *   @0x25376c moveq r3, r1
 *   @0x253770 add r3, r3, r3, lsl #1
 *   @0x253774 str r12, [sp, #0x28]
 *   @0x253778 add r3, r3, r3, lsr #31
 *   @0x25377c asr r3, r3, #1
 *   @0x253780 cmp r3, r2
 *   @0x253784 addlt r2, r2, r2, lsl #1
 *   @0x253788 addlt r2, r2, r2, lsr #31
 *   @0x25378c asrlt r3, r2, #1
 *   @0x253790 str r3, [sp, #0x8]
 *   @0x253794 mov r0, r3
 *   @0x253798 bl 0xcef4c <_Z7YYAlloci>
 *   @0x25379c ldr r2, [sp, #0x34]
 *   @0x2537a0 ldr r1, [sp, #0x28]
 *   @0x2537a4 str r0, [sp, #0x30]
 *   @0x2537a8 bl 0xb65bc <memcpy@plt>
 *   @0x2537ac ldr r12, [sp, #0x28]
 *   @0x2537b0 ldr r3, [sp, #0x8]
 *   @0x2537b4 cmp r12, #0
 *   @0x2537b8 str r3, [sp, #0x34]
 *   @0x2537bc beq 0x2537c8 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3a0>
 *   @0x2537c0 ldr r0, [sp, #0x28]
 *   @0x2537c4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2537c8 ldr r2, [sp, #0x38]
 *   @0x2537cc ldr r0, [sp, #0x30]
 *   @0x2537d0 ldr r1, [sp, #0x24]
 *   @0x2537d4 add r0, r0, r2
 *   @0x2537d8 bl 0xb65a4 <strcpy@plt>
 *   @0x2537dc ldr r3, [sp, #0x38]
 *   @0x2537e0 add r9, r3, r9
 *   @0x2537e4 str r9, [sp, #0x38]
 *   @0x2537e8 ldr r3, [sp, #0x88]
 *   @0x2537ec sub r3, r3, #1
 *   @0x2537f0 bic r3, r3, #-16777216
 *   @0x2537f4 bic r3, r3, #3
 *   @0x2537f8 cmp r3, #0
 *   @0x2537fc bne 0x253564 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x253800 add r0, sp, #124
 *   @0x253804 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253808 b 0x253564 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x25380c mov r0, r8
 *   @0x253810 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253814 b 0x25357c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x253818 add r1, sp, #56
 *   @0x25381c b 0x25368c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x264>
 *   @0x253820 ldr r0, [pc, #0x11c]
 *   @0x253824 add r0, pc, r0
 *   @0x253828 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25382c ldr r0, [sp, #0x30]
 *   @0x253830 cmp r0, #0
 *   @0x253834 bne 0x2536d4 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x2ac>
 *   @0x253838 b 0x2536d8 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x2b0>
 *   @0x25383c add r0, sp, #60
 *   @0x253840 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253844 b 0x2536b4 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x28c>
 *   @0x253848 ldr r3, [sp, #0x88]
 *   @0x25384c sub r3, r3, #1
 *   @0x253850 bic r3, r3, #-16777216
 *   @0x253854 bic r3, r3, #3
 *   @0x253858 cmp r3, #0
 *   @0x25385c beq 0x2538fc <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x4d4>
 *   @0x253860 ldr r1, [sp, #0x78]
 *   @0x253864 mov r3, #0
 *   @0x253868 str r3, [sp, #0x84]
 *   @0x25386c mov r2, #5
 *   @0x253870 sub r1, r1, #1
 *   @0x253874 str r3, [sp, #0x7c]
 *   @0x253878 bic r3, r1, #-16777216
 *   @0x25387c str r2, [sp, #0x88]
 *   @0x253880 bic r3, r3, #3
 *   @0x253884 cmp r3, #0
 *   @0x253888 beq 0x253920 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x4f8>
 *   @0x25388c ldr r1, [sp, #0x58]
 *   @0x253890 mov r3, #0
 *   @0x253894 str r3, [sp, #0x74]
 *   @0x253898 mov r2, #5
 *   @0x25389c sub r1, r1, #1
 *   @0x2538a0 str r3, [sp, #0x6c]
 *   @0x2538a4 bic r3, r1, #-16777216
 *   @0x2538a8 str r2, [sp, #0x78]
 *   @0x2538ac bic r3, r3, #3
 *   @0x2538b0 cmp r3, #0
 *   @0x2538b4 beq 0x253914 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x4ec>
 *   @0x2538b8 ldr r1, [sp, #0x48]
 *   @0x2538bc mov r3, #0
 *   @0x2538c0 str r3, [sp, #0x54]
 *   @0x2538c4 mov r2, #5
 *   @0x2538c8 sub r1, r1, #1
 *   @0x2538cc str r3, [sp, #0x4c]
 *   @0x2538d0 bic r3, r1, #-16777216
 *   @0x2538d4 str r2, [sp, #0x58]
 *   @0x2538d8 bic r3, r3, #3
 *   @0x2538dc cmp r3, #0
 *   @0x2538e0 beq 0x253908 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x4e0>
 *   @0x2538e4 mov r3, #0
 *   @0x2538e8 mov r2, #5
 *   @0x2538ec str r3, [sp, #0x44]
 *   @0x2538f0 str r3, [sp, #0x3c]
 *   @0x2538f4 str r2, [sp, #0x48]
 *   @0x2538f8 b 0x25382c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x404>
 *   @0x2538fc add r0, sp, #124
 *   @0x253900 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253904 b 0x253860 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x438>
 *   @0x253908 add r0, sp, #60
 *   @0x25390c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253910 b 0x2538e4 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x4bc>
 *   @0x253914 mov r0, r5
 *   @0x253918 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x25391c b 0x2538b8 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x490>
 *   @0x253920 mov r0, r8
 *   @0x253924 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x253928 b 0x25388c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x464>
 *   @0x25392c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x253930 ldrsheq r10, [r9], -r4
 *   @0x253934 andeq sp, sp, r4, lsr #8
 *   @0x253938 andseq r2, r0, r12, lsr #19
 *   @0x25393c mulseq r0, r0, r1
 *   @0x253940 andeq pc, sp, r0, rrx
 *   @0x253944 andseq r2, r0, r12, asr #27
 *
 * ══ §14/23 CDS_Map::Assign(CDS_Map*)  0x20c87c  size 1308  327 条（0x20c87c..0x20cd98）
 * @func 0x20c87c 0x20cd98  size 1308  327 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×4 / 0xb65b0×2 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / CalcCRC(char const*, int)×2 / CDS_Map::Assign(CDS_Map*)+0xe0 / operator delete(void*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×14 / 0x10×13 / 0xc×12 / 0x4×8 / 0x1c×7 / 0x18×4 / 0x3×2 / 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20c87c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20c880 sub sp, sp, #28
 *   @0x20c884 ldr r10, [r0]
 *   @0x20c888 str r0, [sp, #0x4]
 *   @0x20c88c str r1, [sp]
 *   @0x20c890 ldr r9, [r10, #0x4]
 *   @0x20c894 cmp r9, #0
 *   @0x20c898 lslge r7, r9, #3
 *   @0x20c89c movge r6, #0
 *   @0x20c8a0 movge r8, #5
 *   @0x20c8a4 blt 0x20c95c <_ZN7CDS_Map6AssignEPS_+0xe0>
 *   @0x20c8a8 ldr r3, [r10]
 *   @0x20c8ac add r2, r3, r7
 *   @0x20c8b0 ldr r4, [r3, r7]
 *   @0x20c8b4 str r6, [r3, r7]
 *   @0x20c8b8 cmp r4, #0
 *   @0x20c8bc str r6, [r2, #0x4]
 *   @0x20c8c0 beq 0x20c94c <_ZN7CDS_Map6AssignEPS_+0xd0>
 *   @0x20c8c4 ldr r5, [r4, #0xc]
 *   @0x20c8c8 ldr r11, [r4, #0x4]
 *   @0x20c8cc cmp r5, #0
 *   @0x20c8d0 beq 0x20c92c <_ZN7CDS_Map6AssignEPS_+0xb0>
 *   @0x20c8d4 ldr r3, [r5, #0xc]
 *   @0x20c8d8 sub r3, r3, #1
 *   @0x20c8dc bic r3, r3, #-16777216
 *   @0x20c8e0 bic r3, r3, #3
 *   @0x20c8e4 cmp r3, #0
 *   @0x20c8e8 beq 0x20ccf0 <_ZN7CDS_Map6AssignEPS_+0x474>
 *   @0x20c8ec ldr r3, [r5, #0x1c]
 *   @0x20c8f0 str r6, [r5, #0x8]
 *   @0x20c8f4 sub r3, r3, #1
 *   @0x20c8f8 str r8, [r5, #0xc]
 *   @0x20c8fc bic r3, r3, #-16777216
 *   @0x20c900 str r6, [r5]
 *   @0x20c904 bic r3, r3, #3
 *   @0x20c908 cmp r3, #0
 *   @0x20c90c bne 0x20c918 <_ZN7CDS_Map6AssignEPS_+0x9c>
 *   @0x20c910 add r0, r5, #16
 *   @0x20c914 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20c918 str r6, [r5, #0x18]
 *   @0x20c91c mov r0, r5
 *   @0x20c920 str r8, [r5, #0x1c]
 *   @0x20c924 str r6, [r5, #0x10]
 *   @0x20c928 bl 0x27d1d0 <_ZdlPv>
 *   @0x20c92c mov r0, r4
 *   @0x20c930 mov r4, r11
 *   @0x20c934 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x20c938 ldr r3, [r10, #0x8]
 *   @0x20c93c cmp r11, #0
 *   @0x20c940 sub r3, r3, #1
 *   @0x20c944 str r3, [r10, #0x8]
 *   @0x20c948 bne 0x20c8c4 <_ZN7CDS_Map6AssignEPS_+0x48>
 *   @0x20c94c sub r9, r9, #1
 *   @0x20c950 sub r7, r7, #8
 *   @0x20c954 cmn r9, #1
 *   @0x20c958 bne 0x20c8a8 <_ZN7CDS_Map6AssignEPS_+0x2c>
 *   @0x20c95c ldr r2, [sp]
 *   @0x20c960 mov r6, #0
 *   @0x20c964 ldr r11, [r2]
 *   @0x20c968 ldr r2, [r11]
 *   @0x20c96c b 0x20c980 <_ZN7CDS_Map6AssignEPS_+0x104>
 *   @0x20c970 ldr r3, [r11, #0x4]
 *   @0x20c974 add r6, r6, #1
 *   @0x20c978 cmp r6, r3
 *   @0x20c97c bgt 0x20cd8c <_ZN7CDS_Map6AssignEPS_+0x510>
 *   @0x20c980 ldr r5, [r2, r6, lsl #3]
 *   @0x20c984 cmp r5, #0
 *   @0x20c988 beq 0x20c970 <_ZN7CDS_Map6AssignEPS_+0xf4>
 *   @0x20c98c ldr r0, [pc, #0x400]
 *   @0x20c990 mov r8, #0
 *   @0x20c994 add r3, sp, #16
 *   @0x20c998 str r11, [sp, #0x8]
 *   @0x20c99c add r0, pc, r0
 *   @0x20c9a0 str r3, [sp, #0xc]
 *   @0x20c9a4 str r0, [sp]
 *   @0x20c9a8 cmp r5, #0
 *   @0x20c9ac beq 0x20cbf8 <_ZN7CDS_Map6AssignEPS_+0x37c>
 *   @0x20c9b0 ldr r9, [r5, #0xc]
 *   @0x20c9b4 cmp r9, #0
 *   @0x20c9b8 beq 0x20cbf8 <_ZN7CDS_Map6AssignEPS_+0x37c>
 *   @0x20c9bc ldr r3, [r9, #0xc]
 *   @0x20c9c0 bic r3, r3, #-16777216
 *   @0x20c9c4 cmp r3, #6
 *   @0x20c9c8 beq 0x20cd6c <_ZN7CDS_Map6AssignEPS_+0x4f0>
 *   @0x20c9cc bgt 0x20ccfc <_ZN7CDS_Map6AssignEPS_+0x480>
 *   @0x20c9d0 cmp r3, #4
 *   @0x20c9d4 bgt 0x20cd14 <_ZN7CDS_Map6AssignEPS_+0x498>
 *   @0x20c9d8 cmp r3, #2
 *   @0x20c9dc bge 0x20cd6c <_ZN7CDS_Map6AssignEPS_+0x4f0>
 *   @0x20c9e0 cmp r3, #1
 *   @0x20c9e4 bne 0x20cd40 <_ZN7CDS_Map6AssignEPS_+0x4c4>
 *   @0x20c9e8 ldr r0, [r9]
 *   @0x20c9ec cmp r0, #0
 *   @0x20c9f0 ldrne r0, [r0]
 *   @0x20c9f4 bl 0x27dfa8 <_Z14CalcCRC_stringPKc>
 *   @0x20c9f8 mov r10, r0
 *   @0x20c9fc mov r0, #32
 *   @0x20ca00 bl 0x27c524 <_Znwj>
 *   @0x20ca04 mov r1, #0
 *   @0x20ca08 mov r2, #16
 *   @0x20ca0c add r7, r0, #16
 *   @0x20ca10 mov r4, r0
 *   @0x20ca14 bl 0xb65b0 <memset@plt>
 *   @0x20ca18 mov r1, #0
 *   @0x20ca1c mov r0, r7
 *   @0x20ca20 mov r2, #16
 *   @0x20ca24 bl 0xb65b0 <memset@plt>
 *   @0x20ca28 ldr r3, [r4, #0xc]
 *   @0x20ca2c sub r3, r3, #1
 *   @0x20ca30 bic r3, r3, #-16777216
 *   @0x20ca34 bic r3, r3, #3
 *   @0x20ca38 cmp r3, #0
 *   @0x20ca3c beq 0x20cd28 <_ZN7CDS_Map6AssignEPS_+0x4ac>
 *   @0x20ca40 mov r3, #5
 *   @0x20ca44 str r3, [r4, #0xc]
 *   @0x20ca48 ldr r3, [r9, #0xc]
 *   @0x20ca4c str r8, [r4, #0x8]
 *   @0x20ca50 ldr r2, [r9, #0x8]
 *   @0x20ca54 str r3, [r4, #0xc]
 *   @0x20ca58 ldr r3, [r9, #0xc]
 *   @0x20ca5c str r8, [r4]
 *   @0x20ca60 bic r3, r3, #-16777216
 *   @0x20ca64 str r2, [r4, #0x8]
 *   @0x20ca68 cmp r3, #14
 *   @0x20ca6c addls pc, pc, r3, lsl #2
 *   @0x20ca70 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c>
 *   @0x20ca74 b 0x20cc14 <_ZN7CDS_Map6AssignEPS_+0x398>
 *   @0x20ca78 b 0x20cc4c <_ZN7CDS_Map6AssignEPS_+0x3d0>
 *   @0x20ca7c b 0x20cc20 <_ZN7CDS_Map6AssignEPS_+0x3a4>
 *   @0x20ca80 b 0x20cab0 <_ZN7CDS_Map6AssignEPS_+0x234>
 *   @0x20ca84 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c>
 *   @0x20ca88 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c>
 *   @0x20ca8c b 0x20cc64 <_ZN7CDS_Map6AssignEPS_+0x3e8>
 *   @0x20ca90 b 0x20cab0 <_ZN7CDS_Map6AssignEPS_+0x234>
 *   @0x20ca94 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c>
 *   @0x20ca98 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c>
 *   @0x20ca9c b 0x20cc14 <_ZN7CDS_Map6AssignEPS_+0x398>
 *   @0x20caa0 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c>
 *   @0x20caa4 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c>
 *   @0x20caa8 b 0x20cc14 <_ZN7CDS_Map6AssignEPS_+0x398>
 *   @0x20caac b 0x20cab0 <_ZN7CDS_Map6AssignEPS_+0x234>
 *   @0x20cab0 ldr r3, [r9]
 *   @0x20cab4 str r3, [r4]
 *   @0x20cab8 ldr r3, [r4, #0x1c]
 *   @0x20cabc sub r3, r3, #1
 *   @0x20cac0 bic r3, r3, #-16777216
 *   @0x20cac4 bic r3, r3, #3
 *   @0x20cac8 cmp r3, #0
 *   @0x20cacc beq 0x20cd1c <_ZN7CDS_Map6AssignEPS_+0x4a0>
 *   @0x20cad0 mov r3, #5
 *   @0x20cad4 str r3, [r4, #0x1c]
 *   @0x20cad8 ldr r3, [r9, #0x1c]
 *   @0x20cadc str r8, [r4, #0x18]
 *   @0x20cae0 ldr r2, [r9, #0x18]
 *   @0x20cae4 str r3, [r4, #0x1c]
 *   @0x20cae8 ldr r3, [r9, #0x1c]
 *   @0x20caec str r8, [r4, #0x10]
 *   @0x20caf0 bic r3, r3, #-16777216
 *   @0x20caf4 str r2, [r4, #0x18]
 *   @0x20caf8 cmp r3, #14
 *   @0x20cafc addls pc, pc, r3, lsl #2
 *   @0x20cb00 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc>
 *   @0x20cb04 b 0x20cc00 <_ZN7CDS_Map6AssignEPS_+0x384>
 *   @0x20cb08 b 0x20ccd8 <_ZN7CDS_Map6AssignEPS_+0x45c>
 *   @0x20cb0c b 0x20ccac <_ZN7CDS_Map6AssignEPS_+0x430>
 *   @0x20cb10 b 0x20cb40 <_ZN7CDS_Map6AssignEPS_+0x2c4>
 *   @0x20cb14 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc>
 *   @0x20cb18 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc>
 *   @0x20cb1c b 0x20cc88 <_ZN7CDS_Map6AssignEPS_+0x40c>
 *   @0x20cb20 b 0x20cb40 <_ZN7CDS_Map6AssignEPS_+0x2c4>
 *   @0x20cb24 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc>
 *   @0x20cb28 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc>
 *   @0x20cb2c b 0x20cc00 <_ZN7CDS_Map6AssignEPS_+0x384>
 *   @0x20cb30 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc>
 *   @0x20cb34 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc>
 *   @0x20cb38 b 0x20cc00 <_ZN7CDS_Map6AssignEPS_+0x384>
 *   @0x20cb3c b 0x20cb40 <_ZN7CDS_Map6AssignEPS_+0x2c4>
 *   @0x20cb40 ldr r3, [r9, #0x10]
 *   @0x20cb44 str r3, [r4, #0x10]
 *   @0x20cb48 ldr r3, [sp, #0x4]
 *   @0x20cb4c movw r2, #0x132
 *   @0x20cb50 mov r0, #16
 *   @0x20cb54 ldr r1, [sp]
 *   @0x20cb58 ldr r7, [r3]
 *   @0x20cb5c mov r3, #1
 *   @0x20cb60 ldm r7, {r9, r12}
 *   @0x20cb64 and r11, r10, r12
 *   @0x20cb68 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x20cb6c ldr r2, [r9, r11, lsl #3]
 *   @0x20cb70 add r3, r9, r11, lsl #3
 *   @0x20cb74 cmp r2, #0
 *   @0x20cb78 ldrne r2, [r3, #0x4]
 *   @0x20cb7c str r10, [r0, #0x8]
 *   @0x20cb80 str r4, [r0, #0xc]
 *   @0x20cb84 strne r2, [r0]
 *   @0x20cb88 streq r0, [r3, #0x4]
 *   @0x20cb8c strne r0, [r2, #0x4]
 *   @0x20cb90 streq r0, [r9, r11, lsl #3]
 *   @0x20cb94 strne r0, [r3, #0x4]
 *   @0x20cb98 streq r2, [r0, #0x4]
 *   @0x20cb9c strne r8, [r0, #0x4]
 *   @0x20cba0 ldr r5, [r5, #0x4]
 *   @0x20cba4 streq r2, [r0]
 *   @0x20cba8 ldr r3, [r7, #0x8]
 *   @0x20cbac cmp r5, #0
 *   @0x20cbb0 add r3, r3, #1
 *   @0x20cbb4 str r3, [r7, #0x8]
 *   @0x20cbb8 bne 0x20c9a8 <_ZN7CDS_Map6AssignEPS_+0x12c>
 *   @0x20cbbc ldr r0, [sp, #0x8]
 *   @0x20cbc0 add r3, r6, #1
 *   @0x20cbc4 ldr r1, [r0, #0x4]
 *   @0x20cbc8 cmp r3, r1
 *   @0x20cbcc bgt 0x20cbf8 <_ZN7CDS_Map6AssignEPS_+0x37c>
 *   @0x20cbd0 ldr r2, [r0]
 *   @0x20cbd4 add r2, r2, r6, lsl #3
 *   @0x20cbd8 ldr r5, [r2, #0x8]
 *   @0x20cbdc mov r6, r3
 *   @0x20cbe0 add r2, r2, #8
 *   @0x20cbe4 add r3, r3, #1
 *   @0x20cbe8 cmp r5, #0
 *   @0x20cbec bne 0x20c9a8 <_ZN7CDS_Map6AssignEPS_+0x12c>
 *   @0x20cbf0 cmp r1, r3
 *   @0x20cbf4 bge 0x20cbd8 <_ZN7CDS_Map6AssignEPS_+0x35c>
 *   @0x20cbf8 add sp, sp, #28
 *   @0x20cbfc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20cc00 ldr r2, [r9, #0x10]
 *   @0x20cc04 ldr r3, [r9, #0x14]
 *   @0x20cc08 str r2, [r4, #0x10]
 *   @0x20cc0c str r3, [r4, #0x14]
 *   @0x20cc10 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc>
 *   @0x20cc14 ldm r9, {r2, r3}
 *   @0x20cc18 stm r4, {r2, r3}
 *   @0x20cc1c b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c>
 *   @0x20cc20 ldr r3, [r9]
 *   @0x20cc24 cmp r3, #0
 *   @0x20cc28 str r3, [r4]
 *   @0x20cc2c beq 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c>
 *   @0x20cc30 ldr r1, [r3, #0x8]
 *   @0x20cc34 ldr r2, [r3]
 *   @0x20cc38 cmp r1, #0
 *   @0x20cc3c streq r4, [r3, #0x8]
 *   @0x20cc40 add r2, r2, #1
 *   @0x20cc44 str r2, [r3]
 *   @0x20cc48 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c>
 *   @0x20cc4c ldr r3, [r9]
 *   @0x20cc50 cmp r3, #0
 *   @0x20cc54 ldrne r2, [r3, #0x4]
 *   @0x20cc58 addne r2, r2, #1
 *   @0x20cc5c strne r2, [r3, #0x4]
 *   @0x20cc60 b 0x20cab4 <_ZN7CDS_Map6AssignEPS_+0x238>
 *   @0x20cc64 ldr r3, [r9]
 *   @0x20cc68 str r3, [r4]
 *   @0x20cc6c ldr r3, [r9]
 *   @0x20cc70 cmp r3, #0
 *   @0x20cc74 beq 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c>
 *   @0x20cc78 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20cc7c ldr r1, [r9]
 *   @0x20cc80 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20cc84 b 0x20cab8 <_ZN7CDS_Map6AssignEPS_+0x23c>
 *   @0x20cc88 ldr r3, [r9, #0x10]
 *   @0x20cc8c str r3, [r4, #0x10]
 *   @0x20cc90 ldr r3, [r9, #0x10]
 *   @0x20cc94 cmp r3, #0
 *   @0x20cc98 beq 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc>
 *   @0x20cc9c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20cca0 ldr r1, [r9, #0x10]
 *   @0x20cca4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20cca8 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc>
 *   @0x20ccac ldr r3, [r9, #0x10]
 *   @0x20ccb0 cmp r3, #0
 *   @0x20ccb4 str r3, [r4, #0x10]
 *   @0x20ccb8 beq 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc>
 *   @0x20ccbc ldr r1, [r3, #0x8]
 *   @0x20ccc0 ldr r2, [r3]
 *   @0x20ccc4 cmp r1, #0
 *   @0x20ccc8 streq r7, [r3, #0x8]
 *   @0x20cccc add r2, r2, #1
 *   @0x20ccd0 str r2, [r3]
 *   @0x20ccd4 b 0x20cb48 <_ZN7CDS_Map6AssignEPS_+0x2cc>
 *   @0x20ccd8 ldr r3, [r9, #0x10]
 *   @0x20ccdc cmp r3, #0
 *   @0x20cce0 ldrne r2, [r3, #0x4]
 *   @0x20cce4 addne r2, r2, #1
 *   @0x20cce8 strne r2, [r3, #0x4]
 *   @0x20ccec b 0x20cb44 <_ZN7CDS_Map6AssignEPS_+0x2c8>
 *   @0x20ccf0 mov r0, r5
 *   @0x20ccf4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20ccf8 b 0x20c8ec <_ZN7CDS_Map6AssignEPS_+0x70>
 *   @0x20ccfc cmp r3, #11
 *   @0x20cd00 beq 0x20cd6c <_ZN7CDS_Map6AssignEPS_+0x4f0>
 *   @0x20cd04 ble 0x20cd34 <_ZN7CDS_Map6AssignEPS_+0x4b8>
 *   @0x20cd08 mvn r2, #-16777216
 *   @0x20cd0c cmp r3, r2
 *   @0x20cd10 bne 0x20cd40 <_ZN7CDS_Map6AssignEPS_+0x4c4>
 *   @0x20cd14 mov r10, #0
 *   @0x20cd18 b 0x20c9fc <_ZN7CDS_Map6AssignEPS_+0x180>
 *   @0x20cd1c mov r0, r7
 *   @0x20cd20 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20cd24 b 0x20cad0 <_ZN7CDS_Map6AssignEPS_+0x254>
 *   @0x20cd28 mov r0, r4
 *   @0x20cd2c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20cd30 b 0x20ca40 <_ZN7CDS_Map6AssignEPS_+0x1c4>
 *   @0x20cd34 sub r2, r3, #8
 *   @0x20cd38 cmp r2, #1
 *   @0x20cd3c bls 0x20cd6c <_ZN7CDS_Map6AssignEPS_+0x4f0>
 *   @0x20cd40 cmp r3, #0
 *   @0x20cd44 bne 0x20cd80 <_ZN7CDS_Map6AssignEPS_+0x504>
 *   @0x20cd48 ldm r9, {r0, r1}
 *   @0x20cd4c mov r2, r0
 *   @0x20cd50 mov r3, r1
 *   @0x20cd54 add r0, sp, #16
 *   @0x20cd58 mov r1, #8
 *   @0x20cd5c strd r2, r3, [sp, #16]
 *   @0x20cd60 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x20cd64 mov r10, r0
 *   @0x20cd68 b 0x20c9fc <_ZN7CDS_Map6AssignEPS_+0x180>
 *   @0x20cd6c mov r0, r9
 *   @0x20cd70 mov r1, #8
 *   @0x20cd74 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x20cd78 mov r10, r0
 *   @0x20cd7c b 0x20c9fc <_ZN7CDS_Map6AssignEPS_+0x180>
 *   @0x20cd80 mov r0, r9
 *   @0x20cd84 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x20cd88 b 0x20cd4c <_ZN7CDS_Map6AssignEPS_+0x4d0>
 *   @0x20cd8c mvn r6, #0
 *   @0x20cd90 b 0x20c98c <_ZN7CDS_Map6AssignEPS_+0x110>
 *   @0x20cd94 andseq r0, r4, r0, lsl r3
 *
 * ══ §15/23 anon_229390  0x229390  size 1304  326 条（0x229390..0x2298a8）
 * @func 0x229390 0x2298a8  size 1304  326 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_read×9 / __divsi3×6 / anon_229390+0x2cc×5 / 0xb6544×3 / 0xb655c×2 / 0xb65b0×2 / anon_229390+0x144 / _ilog
 * 字段偏移 top8: 0x4×14 / 0xc×10 / 0x8×10 / 0x14×7 / 0x2×5 / 0x10×4 / 0x1c×4 / 0x40×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x229390 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x229394 add r11, r0, #4
 *   @0x229398 ldr r4, [r1, #0x10]
 *   @0x22939c sub sp, sp, #12
 *   @0x2293a0 mov r5, r1
 *   @0x2293a4 mov r9, r0
 *   @0x2293a8 mov r0, r11
 *   @0x2293ac ldr r1, [r4, #0xc]
 *   @0x2293b0 bl 0x233b28 <oggpack_read>
 *   @0x2293b4 subs r6, r0, #0
 *   @0x2293b8 ble 0x2294d4 <vorbis_book_decodevv_add+0x5b4>
 *   @0x2293bc ldr r0, [r4, #0x14]
 *   @0x2293c0 ldr r7, [r4, #0xc]
 *   @0x2293c4 ldr r8, [r4, #0x10]
 *   @0x2293c8 bl 0x22eaf0 <_ilog>
 *   @0x2293cc mov r1, r0
 *   @0x2293d0 mov r0, r11
 *   @0x2293d4 bl 0x233b28 <oggpack_read>
 *   @0x2293d8 cmn r0, #1
 *   @0x2293dc beq 0x2294d4 <vorbis_book_decodevv_add+0x5b4>
 *   @0x2293e0 ldr r3, [r4, #0x14]
 *   @0x2293e4 cmp r0, r3
 *   @0x2293e8 bge 0x2294d4 <vorbis_book_decodevv_add+0x5b4>
 *   @0x2293ec ldr r3, [r9, #0x40]
 *   @0x2293f0 add r0, r0, #6
 *   @0x2293f4 ldr r1, [r5, #0x8]
 *   @0x2293f8 mov r10, #52
 *   @0x2293fc ldr r2, [r4, r0, lsl #2]
 *   @0x229400 mov r0, r9
 *   @0x229404 ldr r3, [r3, #0x4]
 *   @0x229408 add r1, r1, #1
 *   @0x22940c lsl r1, r1, #2
 *   @0x229410 ldr r3, [r3, #0x1c]
 *   @0x229414 ldr r3, [r3, #0xc20]
 *   @0x229418 mla r10, r10, r2, r3
 *   @0x22941c bl 0x2270e4 <_vorbis_block_alloc>
 *   @0x229420 ldr r3, [r5, #0x8]
 *   @0x229424 mov r2, r11
 *   @0x229428 mov r1, r0
 *   @0x22942c mov r9, r0
 *   @0x229430 mvn r0, #23
 *   @0x229434 str r0, [sp]
 *   @0x229438 mov r0, r10
 *   @0x22943c bl 0x228afc <vorbis_book_decodev_set>
 *   @0x229440 cmn r0, #1
 *   @0x229444 beq 0x2294d4 <vorbis_book_decodevv_add+0x5b4>
 *   @0x229448 ldr r4, [r5, #0x8]
 *   @0x22944c cmp r4, #0
 *   @0x229450 ble 0x229498 <vorbis_book_decodevv_add+0x578>
 *   @0x229454 ldr lr, [r10]
 *   @0x229458 mov r1, #0
 *   @0x22945c mov r3, r1
 *   @0x229460 cmp lr, #0
 *   @0x229464 ble 0x2294c0 <vorbis_book_decodevv_add+0x5a0>
 *   @0x229468 add r2, r9, r3, lsl #2
 *   @0x22946c add r0, r3, lr
 *   @0x229470 b 0x22947c <vorbis_book_decodevv_add+0x55c>
 *   @0x229474 cmp r3, r0
 *   @0x229478 beq 0x2294c0 <vorbis_book_decodevv_add+0x5a0>
 *   @0x22947c ldr r12, [r2]
 *   @0x229480 add r3, r3, #1
 *   @0x229484 add r12, r12, r1
 *   @0x229488 str r12, [r2], #4
 *   @0x22948c ldr r4, [r5, #0x8]
 *   @0x229490 cmp r4, r3
 *   @0x229494 bgt 0x229474 <vorbis_book_decodevv_add+0x554>
 *   @0x229498 mul r0, r6, r8
 *   @0x22949c mvn r1, #0
 *   @0x2294a0 mvn r1, r1, lsl r7
 *   @0x2294a4 lsl r0, r0, #4
 *   @0x2294a8 bl 0x318d10 <__divsi3>
 *   @0x2294ac mov r3, r9
 *   @0x2294b0 str r0, [r9, r4, lsl #2]
 *   @0x2294b4 mov r0, r3
 *   @0x2294b8 add sp, sp, #12
 *   @0x2294bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2294c0 sub r2, r3, #-1073741823
 *   @0x2294c4 cmp r3, r4
 *   @0x2294c8 ldr r1, [r9, r2, lsl #2]
 *   @0x2294cc blt 0x229460 <vorbis_book_decodevv_add+0x540>
 *   @0x2294d0 b 0x229498 <vorbis_book_decodevv_add+0x578>
 *   @0x2294d4 mov r3, #0
 *   @0x2294d8 mov r0, r3
 *   @0x2294dc add sp, sp, #12
 *   @0x2294e0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2294e4 push {r4, lr}
 *   @0x2294e8 subs r4, r0, #0
 *   @0x2294ec popeq {r4, pc}
 *   @0x2294f0 ldr r0, [r4, #0xc]
 *   @0x2294f4 cmp r0, #0
 *   @0x2294f8 beq 0x229500 <vorbis_book_decodevv_add+0x5e0>
 *   @0x2294fc bl 0xb655c <free@plt>
 *   @0x229500 ldr r0, [r4, #0x14]
 *   @0x229504 cmp r0, #0
 *   @0x229508 beq 0x229510 <vorbis_book_decodevv_add+0x5f0>
 *   @0x22950c bl 0xb655c <free@plt>
 *   @0x229510 mov r0, r4
 *   @0x229514 mov r1, #0
 *   @0x229518 mov r2, #24
 *   @0x22951c bl 0xb65b0 <memset@plt>
 *   @0x229520 mov r0, r4
 *   @0x229524 pop {r4, lr}
 *   @0x229528 b 0xb655c <free@plt>
 *   @0x22952c push {r4, lr}
 *   @0x229530 subs r4, r0, #0
 *   @0x229534 popeq {r4, pc}
 *   @0x229538 mov r1, #0
 *   @0x22953c mov r2, #88
 *   @0x229540 bl 0xb65b0 <memset@plt>
 *   @0x229544 mov r0, r4
 *   @0x229548 pop {r4, lr}
 *   @0x22954c b 0xb655c <free@plt>
 *   @0x229550 push {r4, r5, r6, r7, r8, lr}
 *   @0x229554 mov r8, r1
 *   @0x229558 ldr r7, [r0, #0x1c]
 *   @0x22955c mov r0, #88
 *   @0x229560 bl 0xb6544 <malloc@plt>
 *   @0x229564 mov r1, #8
 *   @0x229568 mov r6, r0
 *   @0x22956c mov r0, r8
 *   @0x229570 bl 0x233b28 <oggpack_read>
 *   @0x229574 mov r1, #16
 *   @0x229578 str r0, [r6]
 *   @0x22957c mov r0, r8
 *   @0x229580 bl 0x233b28 <oggpack_read>
 *   @0x229584 mov r1, #16
 *   @0x229588 str r0, [r6, #0x4]
 *   @0x22958c mov r0, r8
 *   @0x229590 bl 0x233b28 <oggpack_read>
 *   @0x229594 mov r1, #6
 *   @0x229598 str r0, [r6, #0x8]
 *   @0x22959c mov r0, r8
 *   @0x2295a0 bl 0x233b28 <oggpack_read>
 *   @0x2295a4 mov r1, #8
 *   @0x2295a8 str r0, [r6, #0xc]
 *   @0x2295ac mov r0, r8
 *   @0x2295b0 bl 0x233b28 <oggpack_read>
 *   @0x2295b4 mov r1, #4
 *   @0x2295b8 str r0, [r6, #0x10]
 *   @0x2295bc mov r0, r8
 *   @0x2295c0 bl 0x233b28 <oggpack_read>
 *   @0x2295c4 ldr r3, [r6]
 *   @0x2295c8 cmp r3, #0
 *   @0x2295cc add r0, r0, #1
 *   @0x2295d0 str r0, [r6, #0x14]
 *   @0x2295d4 ble 0x22965c <vorbis_book_decodevv_add+0x73c>
 *   @0x2295d8 ldr r3, [r6, #0x4]
 *   @0x2295dc cmp r3, #0
 *   @0x2295e0 ble 0x22965c <vorbis_book_decodevv_add+0x73c>
 *   @0x2295e4 ldr r3, [r6, #0x8]
 *   @0x2295e8 cmp r3, #0
 *   @0x2295ec ble 0x22965c <vorbis_book_decodevv_add+0x73c>
 *   @0x2295f0 cmp r0, #0
 *   @0x2295f4 ble 0x22965c <vorbis_book_decodevv_add+0x73c>
 *   @0x2295f8 mov r4, r6
 *   @0x2295fc mov r5, #0
 *   @0x229600 b 0x229638 <vorbis_book_decodevv_add+0x718>
 *   @0x229604 ldr r1, [r7, #0x1c]
 *   @0x229608 cmp r0, r1
 *   @0x22960c bge 0x22965c <vorbis_book_decodevv_add+0x73c>
 *   @0x229610 ldr r3, [r7, r2, lsl #2]
 *   @0x229614 ldr r2, [r3, #0xc]
 *   @0x229618 cmp r2, #0
 *   @0x22961c beq 0x22965c <vorbis_book_decodevv_add+0x73c>
 *   @0x229620 ldr r3, [r3]
 *   @0x229624 cmp r3, #0
 *   @0x229628 ble 0x22965c <vorbis_book_decodevv_add+0x73c>
 *   @0x22962c ldr r3, [r6, #0x14]
 *   @0x229630 cmp r3, r5
 *   @0x229634 ble 0x22966c <vorbis_book_decodevv_add+0x74c>
 *   @0x229638 mov r0, r8
 *   @0x22963c mov r1, #8
 *   @0x229640 bl 0x233b28 <oggpack_read>
 *   @0x229644 add r5, r5, #1
 *   @0x229648 add r4, r4, #4
 *   @0x22964c cmp r0, #0
 *   @0x229650 str r0, [r4, #0x14]
 *   @0x229654 add r2, r0, #520
 *   @0x229658 bge 0x229604 <vorbis_book_decodevv_add+0x6e4>
 *   @0x22965c mov r0, r6
 *   @0x229660 bl 0x22952c <vorbis_book_decodevv_add+0x60c>
 *   @0x229664 mov r0, #0
 *   @0x229668 pop {r4, r5, r6, r7, r8, pc}
 *   @0x22966c mov r0, r6
 *   @0x229670 pop {r4, r5, r6, r7, r8, pc}
 *   @0x229674 ldr r3, [r0, #0x4]
 *   @0x229678 mov r0, #1
 *   @0x22967c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x229680 mov r5, r1
 *   @0x229684 sub sp, sp, #20
 *   @0x229688 mov r1, #24
 *   @0x22968c mov r4, r2
 *   @0x229690 ldr r6, [r3, #0x1c]
 *   @0x229694 bl 0xb6c34 <calloc@plt>
 *   @0x229698 ldr r2, [r5]
 *   @0x22969c ldr r3, [r4]
 *   @0x2296a0 ldr r5, [r4, #0x8]
 *   @0x2296a4 ldr r8, [r6, r2, lsl #2]
 *   @0x2296a8 add r8, r8, r8, lsr #31
 *   @0x2296ac asr r8, r8, #1
 *   @0x2296b0 add r6, r8, #1
 *   @0x2296b4 lsl r6, r6, #2
 *   @0x2296b8 str r3, [r0, #0x8]
 *   @0x2296bc str r0, [sp, #0xc]
 *   @0x2296c0 str r4, [r0, #0x10]
 *   @0x2296c4 str r5, [r0, #0x4]
 *   @0x2296c8 str r8, [r0]
 *   @0x2296cc mov r0, r6
 *   @0x2296d0 bl 0xb6544 <malloc@plt>
 *   @0x2296d4 ldr r3, [sp, #0xc]
 *   @0x2296d8 cmp r8, #0
 *   @0x2296dc mov r9, r0
 *   @0x2296e0 str r0, [r3, #0xc]
 *   @0x2296e4 ble 0x22989c <vorbis_book_decodevv_add+0x97c>
 *   @0x2296e8 ldr r11, [r4, #0x4]
 *   @0x2296ec mov r4, #0
 *   @0x2296f0 ldr r10, [pc, #0x1ac]
 *   @0x2296f4 sub r6, r6, #4
 *   @0x2296f8 str r6, [sp, #0x8]
 *   @0x2296fc mov r6, r4
 *   @0x229700 add r11, r11, r11, lsr #31
 *   @0x229704 add r10, pc, r10
 *   @0x229708 sub r7, r10, #4
 *   @0x22970c add r10, r10, #104
 *   @0x229710 asr r11, r11, #1
 *   @0x229714 mov r0, r6
 *   @0x229718 mov r1, r8
 *   @0x22971c bl 0x318d10 <__divsi3>
 *   @0x229720 mov r3, r7
 *   @0x229724 mov r2, #1
 *   @0x229728 ldr r1, [r3, #0x4]!
 *   @0x22972c sub r12, r2, #1
 *   @0x229730 add r2, r2, #1
 *   @0x229734 cmp r0, r1
 *   @0x229738 blt 0x229748 <vorbis_book_decodevv_add+0x828>
 *   @0x22973c ldr lr, [r3, #0x4]
 *   @0x229740 cmp r0, lr
 *   @0x229744 blt 0x229848 <vorbis_book_decodevv_add+0x928>
 *   @0x229748 cmp r3, r10
 *   @0x22974c bne 0x229728 <vorbis_book_decodevv_add+0x808>
 *   @0x229750 mov r12, #1811939328
 *   @0x229754 mov r3, r7
 *   @0x229758 mov r2, #1
 *   @0x22975c ldr r1, [r3, #0x4]!
 *   @0x229760 sub lr, r2, #1
 *   @0x229764 add r2, r2, #1
 *   @0x229768 cmp r1, r11
 *   @0x22976c bgt 0x22977c <vorbis_book_decodevv_add+0x85c>
 *   @0x229770 ldr r0, [r3, #0x4]
 *   @0x229774 cmp r0, r11
 *   @0x229778 bgt 0x229870 <vorbis_book_decodevv_add+0x950>
 *   @0x22977c cmp r3, r10
 *   @0x229780 bne 0x22975c <vorbis_book_decodevv_add+0x83c>
 *   @0x229784 mov r1, #884736
 *   @0x229788 mov r0, r12
 *   @0x22978c add r6, r6, r11
 *   @0x229790 bl 0x318d10 <__divsi3>
 *   @0x229794 ldr r2, [sp, #0x8]
 *   @0x229798 mul r0, r0, r5
 *   @0x22979c asr r3, r0, #11
 *   @0x2297a0 cmp r5, r3
 *   @0x2297a4 suble r3, r5, #1
 *   @0x2297a8 str r3, [r9, r4]
 *   @0x2297ac add r4, r4, #4
 *   @0x2297b0 cmp r4, r2
 *   @0x2297b4 bne 0x229714 <vorbis_book_decodevv_add+0x7f4>
 *   @0x2297b8 lsl r0, r5, #2
 *   @0x2297bc mvn r3, #0
 *   @0x2297c0 str r3, [r9, r4]
 *   @0x2297c4 bl 0xb6544 <malloc@plt>
 *   @0x2297c8 ldr r3, [sp, #0xc]
 *   @0x2297cc cmp r5, #0
 *   @0x2297d0 str r0, [r3, #0x14]
 *   @0x2297d4 ble 0x22983c <vorbis_book_decodevv_add+0x91c>
 *   @0x2297d8 ldr r8, [pc, #0xc8]
 *   @0x2297dc sub r6, r0, #4
 *   @0x2297e0 lsl r7, r5, #16
 *   @0x2297e4 mov r4, #0
 *   @0x2297e8 add r8, pc, r8
 *   @0x2297ec mov r0, r4
 *   @0x2297f0 mov r1, r5
 *   @0x2297f4 bl 0x318d10 <__divsi3>
 *   @0x2297f8 add r4, r4, #65536
 *   @0x2297fc ubfx r3, r0, #0x0, #0x11
 *   @0x229800 cmp r3, #65536
 *   @0x229804 rsbgt r3, r3, #131072
 *   @0x229808 cmp r4, r7
 *   @0x22980c ubfx r1, r3, #0x0, #0x9
 *   @0x229810 asr r3, r3, #9
 *   @0x229814 add r2, r8, r3, lsl #2
 *   @0x229818 mov r3, r2
 *   @0x22981c ldr r2, [r2, #0x70]
 *   @0x229820 ldr r3, [r3, #0x74]
 *   @0x229824 rsb r3, r2, r3
 *   @0x229828 mul r3, r3, r1
 *   @0x22982c add r2, r3, r2, lsl #9
 *   @0x229830 asr r2, r2, #9
 *   @0x229834 str r2, [r6, #0x4]!
 *   @0x229838 bne 0x2297ec <vorbis_book_decodevv_add+0x8cc>
 *   @0x22983c ldr r0, [sp, #0xc]
 *   @0x229840 add sp, sp, #20
 *   @0x229844 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x229848 rsb r0, r1, r0
 *   @0x22984c rsb r1, r1, lr
 *   @0x229850 lsl r12, r12, #15
 *   @0x229854 str r12, [sp]
 *   @0x229858 lsl r0, r0, #15
 *   @0x22985c bl 0x318d10 <__divsi3>
 *   @0x229860 ldr r12, [sp]
 *   @0x229864 add r0, r12, r0
 *   @0x229868 lsl r12, r0, #11
 *   @0x22986c b 0x229754 <vorbis_book_decodevv_add+0x834>
 *   @0x229870 rsb r3, r1, r11
 *   @0x229874 rsb r1, r1, r0
 *   @0x229878 lsl r2, lr, #15
 *   @0x22987c str r12, [sp]
 *   @0x229880 lsl r0, r3, #15
 *   @0x229884 str r2, [sp, #0x4]
 *   @0x229888 bl 0x318d10 <__divsi3>
 *   @0x22988c ldr r2, [sp, #0x4]
 *   @0x229890 ldr r12, [sp]
 *   @0x229894 add r1, r2, r0
 *   @0x229898 b 0x229788 <vorbis_book_decodevv_add+0x868>
 *   @0x22989c mov r4, #0
 *   @0x2298a0 b 0x2297b8 <vorbis_book_decodevv_add+0x898>
 *   @0x2298a4 andseq r4, r3, r8, lsl #19
 *
 * ══ §16/23 JS_GlobalObjectSetup()  0x240ffc  size 1288  322 条（0x240ffc..0x241504）
 * @func 0x240ffc 0x241504  size 1288  322 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x241014→0x544be0, 0x241240→0x756450, 0x2412b0→0x756474, 0x2412b4→0x47a148, 0x2412d4→0x47a14c, 0x241320→0x47f3cc, 0x241334→0x47f3d4, 0x241378→0x47f3d0
 * 调用序列: YYObjectBase::Add(char const*, YYObjectBase*, int)×12 / JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×9 / YYObjectBase::Add(char const*, RValue&, int)×4 / JS_GlobalObjectSetup()+0x3ac×2 / JS_GlobalObjectSetup()+0x424×2 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / JS_GlobalObjectSetup()+0x324 / 0xb6574
 * 字段偏移 top8: 0x438×2 / 0x28×2 / 0x40×2 / 0x21c×2 / 0xc×2 / 0x468×1 / 0x464×1 / 0x460×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x240ffc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x241000 mov r3, #5
 *   @0x241004 ldr r4, [pc, #0x468]
 *   @0x241008 mov r6, #0
 *   @0x24100c ldr r7, [pc, #0x464]
 *   @0x241010 sub sp, sp, #28
 *   @0x241014 ldr r1, [pc, #0x460]
 *   @0x241018 add r4, pc, r4
 *   @0x24101c add r7, pc, r7
 *   @0x241020 add r2, r4, #2336
 *   @0x241024 str r3, [r4, #0x938]
 *   @0x241028 add r2, r2, #12
 *   @0x24102c str r6, [r4, #0x934]
 *   @0x241030 mov r3, r6
 *   @0x241034 str r6, [r4, #0x92c]
 *   @0x241038 str r6, [r4, #0x930]
 *   @0x24103c ldr r8, [r7, r1]
 *   @0x241040 ldr r1, [pc, #0x438]
 *   @0x241044 ldr r9, [pc, #0x438]
 *   @0x241048 add r1, pc, r1
 *   @0x24104c ldr r0, [r8]
 *   @0x241050 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x241054 ldr r1, [pc, #0x42c]
 *   @0x241058 add r2, r4, #2352
 *   @0x24105c ldr r0, [r8]
 *   @0x241060 add r2, r2, #12
 *   @0x241064 mov r3, r6
 *   @0x241068 add r1, pc, r1
 *   @0x24106c mvn lr, #0
 *   @0x241070 mvn r12, #-2147483648
 *   @0x241074 str lr, [r4, #0x93c]
 *   @0x241078 str r12, [r4, #0x940]
 *   @0x24107c str r6, [r4, #0x948]
 *   @0x241080 str r6, [r4, #0x944]
 *   @0x241084 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x241088 ldr r1, [pc, #0x3fc]
 *   @0x24108c add r2, r4, #2368
 *   @0x241090 ldr r0, [r8]
 *   @0x241094 add r2, r2, #12
 *   @0x241098 mov r3, r6
 *   @0x24109c add r1, pc, r1
 *   @0x2410a0 str r6, [r4, #0x958]
 *   @0x2410a4 mov r12, r6
 *   @0x2410a8 str r6, [r4, #0x954]
 *   @0x2410ac movt r12, #0x7ff0
 *   @0x2410b0 str r6, [r4, #0x94c]
 *   @0x2410b4 str r12, [r4, #0x950]
 *   @0x2410b8 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x2410bc ldr r3, [pc, #0x3cc]
 *   @0x2410c0 mov r1, r6
 *   @0x2410c4 mov r2, r6
 *   @0x2410c8 ldr r4, [r8]
 *   @0x2410cc ldr r10, [pc, #0x3c0]
 *   @0x2410d0 ldr r0, [r7, r3]
 *   @0x2410d4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2410d8 ldr r1, [pc, #0x3b8]
 *   @0x2410dc mov r3, #6
 *   @0x2410e0 add r1, pc, r1
 *   @0x2410e4 mov r2, r0
 *   @0x2410e8 mov r0, r4
 *   @0x2410ec bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2410f0 ldr r3, [pc, #0x3a4]
 *   @0x2410f4 mov r1, r6
 *   @0x2410f8 mov r2, r6
 *   @0x2410fc ldr r4, [r8]
 *   @0x241100 ldr r0, [r7, r3]
 *   @0x241104 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241108 ldr r1, [pc, #0x390]
 *   @0x24110c mov r3, #6
 *   @0x241110 add r1, pc, r1
 *   @0x241114 mov r2, r0
 *   @0x241118 mov r0, r4
 *   @0x24111c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241120 ldr r3, [pc, #0x37c]
 *   @0x241124 mov r1, r6
 *   @0x241128 mov r2, r6
 *   @0x24112c ldr r4, [r8]
 *   @0x241130 ldr r0, [r7, r3]
 *   @0x241134 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241138 ldr r1, [pc, #0x368]
 *   @0x24113c mov r3, #6
 *   @0x241140 add r1, pc, r1
 *   @0x241144 mov r2, r0
 *   @0x241148 mov r0, r4
 *   @0x24114c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241150 ldr r3, [pc, #0x354]
 *   @0x241154 mov r1, r6
 *   @0x241158 mov r2, r6
 *   @0x24115c ldr r4, [r8]
 *   @0x241160 ldr r0, [r7, r3]
 *   @0x241164 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241168 ldr r1, [pc, #0x340]
 *   @0x24116c mov r3, #6
 *   @0x241170 add r1, pc, r1
 *   @0x241174 mov r2, r0
 *   @0x241178 mov r0, r4
 *   @0x24117c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241180 ldr r3, [pc, #0x32c]
 *   @0x241184 mov r1, r6
 *   @0x241188 mov r2, r6
 *   @0x24118c ldr r5, [r8]
 *   @0x241190 ldr r4, [r7, r3]
 *   @0x241194 mov r0, r4
 *   @0x241198 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24119c ldr r1, [pc, #0x314]
 *   @0x2411a0 mov r3, #6
 *   @0x2411a4 add r1, pc, r1
 *   @0x2411a8 mov r2, r0
 *   @0x2411ac mov r0, r5
 *   @0x2411b0 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2411b4 mov r0, r4
 *   @0x2411b8 mov r1, r6
 *   @0x2411bc mov r2, r6
 *   @0x2411c0 ldr r5, [r8]
 *   @0x2411c4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2411c8 ldr r1, [pc, #0x2ec]
 *   @0x2411cc mov r3, #6
 *   @0x2411d0 add r1, pc, r1
 *   @0x2411d4 mov r2, r0
 *   @0x2411d8 mov r0, r5
 *   @0x2411dc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2411e0 mov r0, r4
 *   @0x2411e4 mov r1, r6
 *   @0x2411e8 mov r2, r6
 *   @0x2411ec ldr r5, [r8]
 *   @0x2411f0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2411f4 ldr r1, [pc, #0x2c4]
 *   @0x2411f8 mov r3, #6
 *   @0x2411fc add r1, pc, r1
 *   @0x241200 mov r2, r0
 *   @0x241204 mov r0, r5
 *   @0x241208 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x24120c mov r0, r4
 *   @0x241210 mov r1, r6
 *   @0x241214 mov r2, r6
 *   @0x241218 ldr r4, [r8]
 *   @0x24121c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241220 ldr r1, [pc, #0x29c]
 *   @0x241224 mov r3, #6
 *   @0x241228 ldr r5, [pc, #0x298]
 *   @0x24122c add r1, pc, r1
 *   @0x241230 add r5, pc, r5
 *   @0x241234 mov r2, r0
 *   @0x241238 mov r0, r4
 *   @0x24123c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241240 ldr r3, [pc, #0x284]
 *   @0x241244 ldr r12, [r8]
 *   @0x241248 mov r1, r6
 *   @0x24124c mov r2, r6
 *   @0x241250 add r0, sp, #8
 *   @0x241254 ldr r4, [r7, r3]
 *   @0x241258 mov r3, r6
 *   @0x24125c ldr r11, [r12, #0x28]
 *   @0x241260 mvn lr, #-16777216
 *   @0x241264 str r5, [r12, #0x40]
 *   @0x241268 mov r5, #0
 *   @0x24126c ldr r4, [r4]
 *   @0x241270 orr r11, r11, #1
 *   @0x241274 str r11, [r12, #0x28]
 *   @0x241278 str r4, [r12, #0x18]
 *   @0x24127c mov r4, #0
 *   @0x241280 ldr r11, [r7, r9]
 *   @0x241284 ldr r9, [pc, #0x244]
 *   @0x241288 str r11, [r12, #0x4c]
 *   @0x24128c ldr r10, [r7, r10]
 *   @0x241290 str r10, [r12, #0x50]
 *   @0x241294 ldr r9, [r7, r9]
 *   @0x241298 str r6, [sp, #0x10]
 *   @0x24129c strd r4, r5, [sp, #8]
 *   @0x2412a0 str r9, [r12, #0x54]
 *   @0x2412a4 str r6, [sp]
 *   @0x2412a8 str lr, [sp, #0x14]
 *   @0x2412ac bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x2412b0 ldr r1, [pc, #0x21c]
 *   @0x2412b4 ldr r3, [pc, #0x21c]
 *   @0x2412b8 ldr r2, [sp, #0x8]
 *   @0x2412bc ldr r9, [r7, r1]
 *   @0x2412c0 str r2, [r9]
 *   @0x2412c4 ldr r10, [r7, r3]
 *   @0x2412c8 ldr r3, [r10]
 *   @0x2412cc cmp r3, r6
 *   @0x2412d0 ble 0x241320 <_Z20JS_GlobalObjectSetupv+0x324>
 *   @0x2412d4 ldr r3, [pc, #0x200]
 *   @0x2412d8 mov r5, r6
 *   @0x2412dc ldr r11, [r7, r3]
 *   @0x2412e0 ldr r4, [r11]
 *   @0x2412e4 mov r2, #0
 *   @0x2412e8 add r5, r5, #1
 *   @0x2412ec add r4, r4, r6
 *   @0x2412f0 add r6, r6, #80
 *   @0x2412f4 ldr r1, [r4, #0x44]
 *   @0x2412f8 ldr r0, [r4, #0x40]
 *   @0x2412fc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241300 mov r3, #1
 *   @0x241304 mov r1, r4
 *   @0x241308 mov r2, r0
 *   @0x24130c ldr r0, [r9]
 *   @0x241310 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241314 ldr r3, [r10]
 *   @0x241318 cmp r3, r5
 *   @0x24131c bgt 0x2412e0 <_Z20JS_GlobalObjectSetupv+0x2e4>
 *   @0x241320 ldr r3, [pc, #0x1b8]
 *   @0x241324 ldr r6, [r7, r3]
 *   @0x241328 ldr r3, [r6]
 *   @0x24132c cmp r3, #0
 *   @0x241330 ble 0x2413a8 <_Z20JS_GlobalObjectSetupv+0x3ac>
 *   @0x241334 ldr r3, [pc, #0x1a8]
 *   @0x241338 mov r4, #0
 *   @0x24133c ldr r11, [pc, #0x1a4]
 *   @0x241340 ldr r10, [r7, r3]
 *   @0x241344 add r11, pc, r11
 *   @0x241348 b 0x24135c <_Z20JS_GlobalObjectSetupv+0x360>
 *   @0x24134c ldr r3, [r6]
 *   @0x241350 add r4, r4, #1
 *   @0x241354 cmp r3, r4
 *   @0x241358 ble 0x2413a8 <_Z20JS_GlobalObjectSetupv+0x3ac>
 *   @0x24135c ldr r3, [r10]
 *   @0x241360 mov r1, r11
 *   @0x241364 ldr r5, [r3, r4, lsl #2]
 *   @0x241368 mov r0, r5
 *   @0x24136c bl 0xb6574 <strcmp@plt>
 *   @0x241370 cmp r0, #0
 *   @0x241374 beq 0x24134c <_Z20JS_GlobalObjectSetupv+0x350>
 *   @0x241378 ldr r2, [pc, #0x16c]
 *   @0x24137c mov r3, #1
 *   @0x241380 mov r1, r5
 *   @0x241384 ldr r0, [r9]
 *   @0x241388 ldr r2, [r7, r2]
 *   @0x24138c ldr r2, [r2]
 *   @0x241390 add r2, r2, r4, lsl #4
 *   @0x241394 add r4, r4, #1
 *   @0x241398 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x24139c ldr r3, [r6]
 *   @0x2413a0 cmp r3, r4
 *   @0x2413a4 bgt 0x24135c <_Z20JS_GlobalObjectSetupv+0x360>
 *   @0x2413a8 ldr r3, [pc, #0x140]
 *   @0x2413ac ldr r6, [r7, r3]
 *   @0x2413b0 ldr r3, [r6]
 *   @0x2413b4 cmp r3, #0
 *   @0x2413b8 ble 0x241420 <_Z20JS_GlobalObjectSetupv+0x424>
 *   @0x2413bc ldr r3, [pc, #0x130]
 *   @0x2413c0 mov r5, #0
 *   @0x2413c4 ldr r4, [r7, r3]
 *   @0x2413c8 add r4, r4, #8
 *   @0x2413cc b 0x2413e0 <_Z20JS_GlobalObjectSetupv+0x3e4>
 *   @0x2413d0 ldr r3, [r6]
 *   @0x2413d4 add r4, r4, #16
 *   @0x2413d8 cmp r3, r5
 *   @0x2413dc ble 0x241420 <_Z20JS_GlobalObjectSetupv+0x424>
 *   @0x2413e0 ldr r0, [r4, #-0x8]
 *   @0x2413e4 add r5, r5, #1
 *   @0x2413e8 bl 0x23f8f0 <_Z18isGlobalBuiltinVarPKc>
 *   @0x2413ec cmp r0, #0
 *   @0x2413f0 beq 0x2413d0 <_Z20JS_GlobalObjectSetupv+0x3d4>
 *   @0x2413f4 ldmda r4, {r0, r1}
 *   @0x2413f8 add r4, r4, #16
 *   @0x2413fc bl 0x23ffac <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_>
 *   @0x241400 ldr r1, [r4, #-0x18]
 *   @0x241404 mov r3, #1
 *   @0x241408 mov r2, r0
 *   @0x24140c ldr r0, [r9]
 *   @0x241410 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241414 ldr r3, [r6]
 *   @0x241418 cmp r3, r5
 *   @0x24141c bgt 0x2413e0 <_Z20JS_GlobalObjectSetupv+0x3e4>
 *   @0x241420 ldr r1, [pc, #0xd0]
 *   @0x241424 mov r3, #1
 *   @0x241428 ldr r0, [r8]
 *   @0x24142c ldr r2, [r9]
 *   @0x241430 add r1, pc, r1
 *   @0x241434 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241438 ldr r0, [r8]
 *   @0x24143c ldr r1, [pc, #0xb8]
 *   @0x241440 mov r3, #1
 *   @0x241444 mov r2, r0
 *   @0x241448 add r1, pc, r1
 *   @0x24144c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241450 ldr r1, [pc, #0xa8]
 *   @0x241454 ldr r3, [r9]
 *   @0x241458 mov r2, #0
 *   @0x24145c ldr r1, [r7, r1]
 *   @0x241460 ldr r1, [r1]
 *   @0x241464 str r3, [r1, #0xc]
 *   @0x241468 str r2, [r3, #0xc]
 *   @0x24146c add sp, sp, #28
 *   @0x241470 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x241474 subseq r4, r1, r8, lsl #21
 *   @0x241478 andseq r0, r11, r4, lsr r12
 *   @0x24147c .word 0xffffbf64
 *   @0x241480 andeq r1, pc, r8, lsl r2
 *   @0x241484 .word 0xfffff8ac
 *   @0x241488 andeq r1, pc, r12, lsl #9
 *   @0x24148c andseq r4, r1, r0, asr r3
 *   @0x241490 .word 0xfffff8dc
 *   @0x241494 .word 0xfffff8b0
 *   @0x241498 mulseq r1, r4, r4
 *   @0x24149c .word 0xfffff8e0
 *   @0x2414a0 andseq r4, r1, r12, ror #8
 *   @0x2414a4 .word 0xfffff8e4
 *   @0x2414a8 andseq r4, r1, r8, asr #8
 *   @0x2414ac .word 0xfffff8e8
 *   @0x2414b0 andseq r4, r1, r4, lsr #8
 *   @0x2414b4 .word 0xfffff8ec
 *   @0x2414b8 ldrsheq r4, [r1], -r12
 *   @0x2414bc ldrsbeq r4, [r1], -r12
 *   @0x2414c0 andseq r4, r1, r4, asr #7
 *   @0x2414c4 andseq r4, r1, r0, lsr #7
 *   @0x2414c8 andseq r4, r1, r4, lsr #3
 *   @0x2414cc .word 0xffffc050
 *   @0x2414d0 .word 0xfffff8b4
 *   @0x2414d4 .word 0xfffff8f0
 *   @0x2414d8 .word 0xffffbec4
 *   @0x2414dc .word 0xffffbec8
 *   @0x2414e0 .word 0xffffc174
 *   @0x2414e4 .word 0xffffc178
 *   @0x2414e8 muleq pc, r4, r11
 *   @0x2414ec .word 0xffffc17c
 *   @0x2414f0 .word 0xffffbfe4
 *   @0x2414f4 .word 0xffffbfe8
 *   @0x2414f8 ldrheq r4, [r1], -r0
 *   @0x2414fc muleq pc, r0, r10
 *   @0x241500 .word 0xffffc058
 *
 * ══ §17/23 CPhysicsJoint::GetValue(int)  0x23b610  size 1284  321 条（0x23b610..0x23bb14）
 * @func 0x23b610 0x23bb14  size 1284  321 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x23b708→0x54298c, 0x23b7f0→0x54298c, 0x23b964→0x54298c, 0x23b9a0→0x54298c, 0x23b9ac→0x54298c, 0x23b9ec→0x54298c, 0x23ba2c→0x54298c, 0x23ba90→0x54298c
 * 调用序列: b2RopeJoint::GetMaxLength() const / b2RevoluteJoint::IsLimitEnabled() const / b2RevoluteJoint::GetUpperLimit() const / b2RevoluteJoint::GetLowerLimit() const / b2PulleyJoint::GetLengthB() const / b2PulleyJoint::GetLengthA() const / b2WheelJoint::GetJointTranslation() const / b2PrismaticJoint::GetJointTranslation() const
 * 字段偏移 top8: 0x4×45 / 0xb4×6 / 0x8×2 / 0x488×1 / 0x39c×1 / 0x2b4×1 / 0x140×1 / 0x104×1
 * VFP 指令 64 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23b610 push {r4, lr}
 *   @0x23b614 sub sp, sp, #8
 *   @0x23b618 ldr r4, [pc, #0x488]
 *   @0x23b61c add r4, pc, r4
 *   @0x23b620 cmp r1, #24
 *   @0x23b624 addls pc, pc, r1, lsl #2
 *   @0x23b628 b 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b62c b 0x23ba7c <_ZN13CPhysicsJoint8GetValueEi+0x46c>
 *   @0x23b630 b 0x23ba68 <_ZN13CPhysicsJoint8GetValueEi+0x458>
 *   @0x23b634 b 0x23b98c <_ZN13CPhysicsJoint8GetValueEi+0x37c>
 *   @0x23b638 b 0x23b950 <_ZN13CPhysicsJoint8GetValueEi+0x340>
 *   @0x23b63c b 0x23b9ec <_ZN13CPhysicsJoint8GetValueEi+0x3dc>
 *   @0x23b640 b 0x23b9ac <_ZN13CPhysicsJoint8GetValueEi+0x39c>
 *   @0x23b644 b 0x23ba2c <_ZN13CPhysicsJoint8GetValueEi+0x41c>
 *   @0x23b648 b 0x23b928 <_ZN13CPhysicsJoint8GetValueEi+0x318>
 *   @0x23b64c b 0x23b690 <_ZN13CPhysicsJoint8GetValueEi+0x80>
 *   @0x23b650 b 0x23b8c4 <_ZN13CPhysicsJoint8GetValueEi+0x2b4>
 *   @0x23b654 b 0x23b904 <_ZN13CPhysicsJoint8GetValueEi+0x2f4>
 *   @0x23b658 b 0x23b8a4 <_ZN13CPhysicsJoint8GetValueEi+0x294>
 *   @0x23b65c b 0x23b880 <_ZN13CPhysicsJoint8GetValueEi+0x270>
 *   @0x23b660 b 0x23b848 <_ZN13CPhysicsJoint8GetValueEi+0x238>
 *   @0x23b664 b 0x23b830 <_ZN13CPhysicsJoint8GetValueEi+0x220>
 *   @0x23b668 b 0x23b810 <_ZN13CPhysicsJoint8GetValueEi+0x200>
 *   @0x23b66c b 0x23b7dc <_ZN13CPhysicsJoint8GetValueEi+0x1cc>
 *   @0x23b670 b 0x23b7b4 <_ZN13CPhysicsJoint8GetValueEi+0x1a4>
 *   @0x23b674 b 0x23b78c <_ZN13CPhysicsJoint8GetValueEi+0x17c>
 *   @0x23b678 b 0x23b774 <_ZN13CPhysicsJoint8GetValueEi+0x164>
 *   @0x23b67c b 0x23b748 <_ZN13CPhysicsJoint8GetValueEi+0x138>
 *   @0x23b680 b 0x23b728 <_ZN13CPhysicsJoint8GetValueEi+0x118>
 *   @0x23b684 b 0x23b6f4 <_ZN13CPhysicsJoint8GetValueEi+0xe4>
 *   @0x23b688 b 0x23b6d8 <_ZN13CPhysicsJoint8GetValueEi+0xc8>
 *   @0x23b68c b 0x23b6bc <_ZN13CPhysicsJoint8GetValueEi+0xac>
 *   @0x23b690 ldr r0, [r0, #0x4]
 *   @0x23b694 ldr r3, [r0, #0x4]
 *   @0x23b698 cmp r3, #1
 *   @0x23b69c beq 0x23bacc <_ZN13CPhysicsJoint8GetValueEi+0x4bc>
 *   @0x23b6a0 cmp r3, #8
 *   @0x23b6a4 vldreq s15, [r0, #96]
 *   @0x23b6a8 beq 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23b6ac vldr s15, [pc, #1000]
 *   @0x23b6b0 vmov r0, s15
 *   @0x23b6b4 add sp, sp, #8
 *   @0x23b6b8 pop {r4, pc}
 *   @0x23b6bc ldr r0, [r0, #0x4]
 *   @0x23b6c0 ldr r3, [r0, #0x4]
 *   @0x23b6c4 cmp r3, #9
 *   @0x23b6c8 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b6cc add sp, sp, #8
 *   @0x23b6d0 pop {r4, lr}
 *   @0x23b6d4 b 0x2cdb18 <_ZNK15b2FrictionJoint11GetMaxForceEv>
 *   @0x23b6d8 ldr r0, [r0, #0x4]
 *   @0x23b6dc ldr r3, [r0, #0x4]
 *   @0x23b6e0 cmp r3, #9
 *   @0x23b6e4 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b6e8 add sp, sp, #8
 *   @0x23b6ec pop {r4, lr}
 *   @0x23b6f0 b 0x2cdbb8 <_ZNK15b2FrictionJoint12GetMaxTorqueEv>
 *   @0x23b6f4 ldr r0, [r0, #0x4]
 *   @0x23b6f8 ldr r3, [r0, #0x4]
 *   @0x23b6fc cmp r3, #10
 *   @0x23b700 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b704 bl 0x2d2bb4 <_ZNK11b2RopeJoint12GetMaxLengthEv>
 *   @0x23b708 ldr r3, [pc, #0x39c]
 *   @0x23b70c vmov s13, r0
 *   @0x23b710 ldr r3, [r4, r3]
 *   @0x23b714 ldr r3, [r3]
 *   @0x23b718 ldr r3, [r3, #0xb4]
 *   @0x23b71c vldr s15, [r3, #96]
 *   @0x23b720 vdiv.f32 s15, s13, s15
 *   @0x23b724 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23b728 ldr r0, [r0, #0x4]
 *   @0x23b72c ldr r3, [r0, #0x4]
 *   @0x23b730 cmp r3, #1
 *   @0x23b734 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b738 bl 0x2d2220 <_ZNK15b2RevoluteJoint14IsLimitEnabledEv>
 *   @0x23b73c vmov s14, r0
 *   @0x23b740 vcvt.f32.u32 s15, s14
 *   @0x23b744 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23b748 ldr r0, [r0, #0x4]
 *   @0x23b74c ldr r3, [r0, #0x4]
 *   @0x23b750 cmp r3, #1
 *   @0x23b754 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b758 bl 0x2d2284 <_ZNK15b2RevoluteJoint13GetUpperLimitEv>
 *   @0x23b75c vmov s13, r0
 *   @0x23b760 vldr s14, [pc, #824]
 *   @0x23b764 vldr s15, [pc, #824]
 *   @0x23b768 vmul.f32 s14, s13, s14
 *   @0x23b76c vdiv.f32 s15, s14, s15
 *   @0x23b770 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23b774 ldr r0, [r0, #0x4]
 *   @0x23b778 ldr r3, [r0, #0x4]
 *   @0x23b77c cmp r3, #1
 *   @0x23b780 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b784 bl 0x2d227c <_ZNK15b2RevoluteJoint13GetLowerLimitEv>
 *   @0x23b788 b 0x23b75c <_ZN13CPhysicsJoint8GetValueEi+0x14c>
 *   @0x23b78c ldr r2, [r0, #0x4]
 *   @0x23b790 ldr r3, [r2, #0x4]
 *   @0x23b794 cmp r3, #3
 *   @0x23b798 beq 0x23b7ac <_ZN13CPhysicsJoint8GetValueEi+0x19c>
 *   @0x23b79c cmp r3, #7
 *   @0x23b7a0 beq 0x23b7ac <_ZN13CPhysicsJoint8GetValueEi+0x19c>
 *   @0x23b7a4 cmp r3, #8
 *   @0x23b7a8 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b7ac vldr s15, [r2, #68]
 *   @0x23b7b0 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23b7b4 ldr r2, [r0, #0x4]
 *   @0x23b7b8 ldr r3, [r2, #0x4]
 *   @0x23b7bc cmp r3, #3
 *   @0x23b7c0 beq 0x23b7d4 <_ZN13CPhysicsJoint8GetValueEi+0x1c4>
 *   @0x23b7c4 cmp r3, #7
 *   @0x23b7c8 beq 0x23b7d4 <_ZN13CPhysicsJoint8GetValueEi+0x1c4>
 *   @0x23b7cc cmp r3, #8
 *   @0x23b7d0 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b7d4 vldr s15, [r2, #72]
 *   @0x23b7d8 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23b7dc ldr r0, [r0, #0x4]
 *   @0x23b7e0 ldr r3, [r0, #0x4]
 *   @0x23b7e4 cmp r3, #4
 *   @0x23b7e8 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b7ec bl 0x2d118c <_ZNK13b2PulleyJoint10GetLengthBEv>
 *   @0x23b7f0 ldr r3, [pc, #0x2b4]
 *   @0x23b7f4 vmov s14, r0
 *   @0x23b7f8 ldr r3, [r4, r3]
 *   @0x23b7fc ldr r3, [r3]
 *   @0x23b800 ldr r3, [r3, #0xb4]
 *   @0x23b804 vldr s15, [r3, #96]
 *   @0x23b808 vdiv.f32 s15, s14, s15
 *   @0x23b80c b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23b810 ldr r0, [r0, #0x4]
 *   @0x23b814 ldr r3, [r0, #0x4]
 *   @0x23b818 cmp r3, #3
 *   @0x23b81c beq 0x23bab0 <_ZN13CPhysicsJoint8GetValueEi+0x4a0>
 *   @0x23b820 cmp r3, #4
 *   @0x23b824 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b828 bl 0x2d1184 <_ZNK13b2PulleyJoint10GetLengthAEv>
 *   @0x23b82c b 0x23b708 <_ZN13CPhysicsJoint8GetValueEi+0xf8>
 *   @0x23b830 ldr r3, [r0, #0x4]
 *   @0x23b834 ldr r2, [r3, #0x4]
 *   @0x23b838 cmp r2, #2
 *   @0x23b83c vldreq s15, [r3, #128]
 *   @0x23b840 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b844 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23b848 ldr r3, [r0, #0x4]
 *   @0x23b84c ldr r2, [r3, #0x4]
 *   @0x23b850 cmp r2, #2
 *   @0x23b854 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b858 vmov.f32 s14, #1.000000e+00
 *   @0x23b85c ldr r2, [r0]
 *   @0x23b860 vldr s15, [r2, #88]
 *   @0x23b864 mov r0, r3
 *   @0x23b868 vcvt.f32.s32 s15, s15
 *   @0x23b86c vdiv.f32 s14, s14, s15
 *   @0x23b870 vmov r1, s14
 *   @0x23b874 add sp, sp, #8
 *   @0x23b878 pop {r4, lr}
 *   @0x23b87c b 0x2d04fc <_ZNK16b2PrismaticJoint13GetMotorForceEf>
 *   @0x23b880 ldr r0, [r0, #0x4]
 *   @0x23b884 ldr r3, [r0, #0x4]
 *   @0x23b888 cmp r3, #2
 *   @0x23b88c beq 0x23bae0 <_ZN13CPhysicsJoint8GetValueEi+0x4d0>
 *   @0x23b890 cmp r3, #7
 *   @0x23b894 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b898 add sp, sp, #8
 *   @0x23b89c pop {r4, lr}
 *   @0x23b8a0 b 0x2d4380 <_ZNK12b2WheelJoint13GetJointSpeedEv>
 *   @0x23b8a4 ldr r0, [r0, #0x4]
 *   @0x23b8a8 ldr r3, [r0, #0x4]
 *   @0x23b8ac cmp r3, #2
 *   @0x23b8b0 beq 0x23bad8 <_ZN13CPhysicsJoint8GetValueEi+0x4c8>
 *   @0x23b8b4 cmp r3, #7
 *   @0x23b8b8 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b8bc bl 0x2d42e0 <_ZNK12b2WheelJoint19GetJointTranslationEv>
 *   @0x23b8c0 b 0x23b7f0 <_ZN13CPhysicsJoint8GetValueEi+0x1e0>
 *   @0x23b8c4 ldr r2, [r0, #0x4]
 *   @0x23b8c8 ldr r3, [r2, #0x4]
 *   @0x23b8cc cmp r3, #1
 *   @0x23b8d0 beq 0x23baec <_ZN13CPhysicsJoint8GetValueEi+0x4dc>
 *   @0x23b8d4 cmp r3, #7
 *   @0x23b8d8 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b8dc vmov.f32 s14, #1.000000e+00
 *   @0x23b8e0 ldr r3, [r0]
 *   @0x23b8e4 vldr s15, [r3, #88]
 *   @0x23b8e8 mov r0, r2
 *   @0x23b8ec vcvt.f32.s32 s15, s15
 *   @0x23b8f0 vdiv.f32 s14, s14, s15
 *   @0x23b8f4 vmov r1, s14
 *   @0x23b8f8 add sp, sp, #8
 *   @0x23b8fc pop {r4, lr}
 *   @0x23b900 b 0x2d4464 <_ZNK12b2WheelJoint14GetMotorTorqueEf>
 *   @0x23b904 ldr r2, [r0, #0x4]
 *   @0x23b908 ldr r3, [r2, #0x4]
 *   @0x23b90c cmp r3, #1
 *   @0x23b910 vldreq s15, [r2, #104]
 *   @0x23b914 beq 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23b918 cmp r3, #7
 *   @0x23b91c vldreq s15, [r2, #120]
 *   @0x23b920 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b924 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23b928 ldr r2, [r0, #0x4]
 *   @0x23b92c ldr r3, [r2, #0x4]
 *   @0x23b930 cmp r3, #2
 *   @0x23b934 beq 0x23bac4 <_ZN13CPhysicsJoint8GetValueEi+0x4b4>
 *   @0x23b938 cmp r3, #7
 *   @0x23b93c beq 0x23babc <_ZN13CPhysicsJoint8GetValueEi+0x4ac>
 *   @0x23b940 cmp r3, #1
 *   @0x23b944 vldreq s15, [r2, #108]
 *   @0x23b948 bne 0x23b6ac <_ZN13CPhysicsJoint8GetValueEi+0x9c>
 *   @0x23b94c b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23b950 ldr r1, [r0, #0x4]
 *   @0x23b954 mov r0, sp
 *   @0x23b958 ldr r3, [r1]
 *   @0x23b95c ldr r3, [r3, #0x4]
 *   @0x23b960 blx r3
 *   @0x23b964 ldr r3, [pc, #0x140]
 *   @0x23b968 vldr s14, [sp, #4]
 *   @0x23b96c ldr r3, [r4, r3]
 *   @0x23b970 ldr r3, [r3]
 *   @0x23b974 ldr r3, [r3, #0xb4]
 *   @0x23b978 vldr s15, [r3, #96]
 *   @0x23b97c vdiv.f32 s15, s14, s15
 *   @0x23b980 vmov r0, s15
 *   @0x23b984 add sp, sp, #8
 *   @0x23b988 pop {r4, pc}
 *   @0x23b98c ldr r1, [r0, #0x4]
 *   @0x23b990 mov r0, sp
 *   @0x23b994 ldr r3, [r1]
 *   @0x23b998 ldr r3, [r3, #0x4]
 *   @0x23b99c blx r3
 *   @0x23b9a0 ldr r3, [pc, #0x104]
 *   @0x23b9a4 vldr s14, [sp]
 *   @0x23b9a8 b 0x23b96c <_ZN13CPhysicsJoint8GetValueEi+0x35c>
 *   @0x23b9ac ldr r3, [pc, #0xf8]
 *   @0x23b9b0 vmov.f32 s14, #1.000000e+00
 *   @0x23b9b4 ldr r1, [r0, #0x4]
 *   @0x23b9b8 mov r0, sp
 *   @0x23b9bc ldr r2, [r4, r3]
 *   @0x23b9c0 ldr r3, [r1]
 *   @0x23b9c4 ldr r2, [r2]
 *   @0x23b9c8 ldr r3, [r3, #0x8]
 *   @0x23b9cc ldr r2, [r2, #0xb4]
 *   @0x23b9d0 vldr s15, [r2, #88]
 *   @0x23b9d4 vcvt.f32.s32 s15, s15
 *   @0x23b9d8 vdiv.f32 s14, s14, s15
 *   @0x23b9dc vmov r2, s14
 *   @0x23b9e0 blx r3
 *   @0x23b9e4 vldr s15, [sp, #4]
 *   @0x23b9e8 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23b9ec ldr r3, [pc, #0xb8]
 *   @0x23b9f0 vmov.f32 s14, #1.000000e+00
 *   @0x23b9f4 ldr r1, [r0, #0x4]
 *   @0x23b9f8 mov r0, sp
 *   @0x23b9fc ldr r2, [r4, r3]
 *   @0x23ba00 ldr r3, [r1]
 *   @0x23ba04 ldr r2, [r2]
 *   @0x23ba08 ldr r3, [r3, #0x8]
 *   @0x23ba0c ldr r2, [r2, #0xb4]
 *   @0x23ba10 vldr s15, [r2, #88]
 *   @0x23ba14 vcvt.f32.s32 s15, s15
 *   @0x23ba18 vdiv.f32 s14, s14, s15
 *   @0x23ba1c vmov r2, s14
 *   @0x23ba20 blx r3
 *   @0x23ba24 vldr s15, [sp]
 *   @0x23ba28 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23ba2c ldr r3, [pc, #0x78]
 *   @0x23ba30 vmov.f32 s14, #1.000000e+00
 *   @0x23ba34 ldr r0, [r0, #0x4]
 *   @0x23ba38 ldr r2, [r4, r3]
 *   @0x23ba3c ldr r3, [r0]
 *   @0x23ba40 ldr r2, [r2]
 *   @0x23ba44 ldr r3, [r3, #0xc]
 *   @0x23ba48 ldr r2, [r2, #0xb4]
 *   @0x23ba4c vldr s15, [r2, #88]
 *   @0x23ba50 vcvt.f32.s32 s15, s15
 *   @0x23ba54 vdiv.f32 s14, s14, s15
 *   @0x23ba58 vmov r1, s14
 *   @0x23ba5c blx r3
 *   @0x23ba60 vmov s15, r0
 *   @0x23ba64 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23ba68 ldr r1, [r0, #0x4]
 *   @0x23ba6c mov r0, sp
 *   @0x23ba70 ldr r3, [r1]
 *   @0x23ba74 ldr r3, [r3]
 *   @0x23ba78 b 0x23b960 <_ZN13CPhysicsJoint8GetValueEi+0x350>
 *   @0x23ba7c ldr r1, [r0, #0x4]
 *   @0x23ba80 mov r0, sp
 *   @0x23ba84 ldr r3, [r1]
 *   @0x23ba88 ldr r3, [r3]
 *   @0x23ba8c blx r3
 *   @0x23ba90 ldr r3, [pc, #0x14]
 *   @0x23ba94 vldr s14, [sp]
 *   @0x23ba98 b 0x23b96c <_ZN13CPhysicsJoint8GetValueEi+0x35c>
 *   @0x23ba9c andeq r0, r0, r0
 *   @0x23baa0 teqmi r4, #0
 *   @0x23baa4 ldrdmi r0, r1, [r9], #-251
 *   @0x23baa8 andseq r6, r11, r4, lsr r6
 *   @0x23baac .word 0xffffbcd8
 *   @0x23bab0 ldr r3, [pc, #-0xc]
 *   @0x23bab4 vldr s14, [r0, #104]
 *   @0x23bab8 b 0x23b96c <_ZN13CPhysicsJoint8GetValueEi+0x35c>
 *   @0x23babc vldr s15, [r2, #124]
 *   @0x23bac0 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23bac4 vldr s15, [r2, #132]
 *   @0x23bac8 b 0x23b6b0 <_ZN13CPhysicsJoint8GetValueEi+0xa0>
 *   @0x23bacc add sp, sp, #8
 *   @0x23bad0 pop {r4, lr}
 *   @0x23bad4 b 0x2d2104 <_ZNK15b2RevoluteJoint13GetJointAngleEv>
 *   @0x23bad8 bl 0x2d016c <_ZNK16b2PrismaticJoint19GetJointTranslationEv>
 *   @0x23badc b 0x23b708 <_ZN13CPhysicsJoint8GetValueEi+0xf8>
 *   @0x23bae0 add sp, sp, #8
 *   @0x23bae4 pop {r4, lr}
 *   @0x23bae8 b 0x2d020c <_ZNK16b2PrismaticJoint13GetJointSpeedEv>
 *   @0x23baec vmov.f32 s14, #1.000000e+00
 *   @0x23baf0 ldr r3, [r0]
 *   @0x23baf4 vldr s15, [r3, #88]
 *   @0x23baf8 mov r0, r2
 *   @0x23bafc vcvt.f32.s32 s15, s15
 *   @0x23bb00 vdiv.f32 s14, s14, s15
 *   @0x23bb04 vmov r1, s14
 *   @0x23bb08 add sp, sp, #8
 *   @0x23bb0c pop {r4, lr}
 *   @0x23bb10 b 0x2d218c <_ZNK15b2RevoluteJoint14GetMotorTorqueEf>
 *
 * ══ §18/23 vorbis_book_decodevs_add  0x22825c  size 1272  318 条（0x22825c..0x228754）
 * @func 0x22825c 0x228754  size 1272  318 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_adv×6 / oggpack_look×4 / vorbis_book_decodevs_add+0x258×3 / vorbis_book_decodevs_add+0x4e0×2 / __divsi3 / vorbis_book_decodevs_add+0x1e8 / vorbis_book_decodevs_add+0x2a8 / vorbis_book_decodevs_add+0x198
 * 字段偏移 top8: 0x-30×10 / 0x-34×6 / 0x8×5 / 0x4×5 / 0x-38×5 / 0x2×4 / 0x1c×4 / 0x-44×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22825c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x228260 add r11, sp, #32
 *   @0x228264 ldr r4, [pc, #0x4e4]
 *   @0x228268 sub sp, sp, #44
 *   @0x22826c mov r7, r0
 *   @0x228270 ldr r4, [pc, r4]
 *   @0x228274 mov r6, r2
 *   @0x228278 ldr r0, [r0, #0x8]
 *   @0x22827c ldr r2, [r4]
 *   @0x228280 cmp r0, #0
 *   @0x228284 str r1, [r11, #-0x44]
 *   @0x228288 str r4, [r11, #-0x3c]
 *   @0x22828c str r2, [r11, #-0x28]
 *   @0x228290 ble 0x2284b4 <vorbis_book_decodevs_add+0x258>
 *   @0x228294 ldr r5, [r7]
 *   @0x228298 mov r0, r3
 *   @0x22829c mov r1, r5
 *   @0x2282a0 bl 0x318d10 <__divsi3>
 *   @0x2282a4 ldr r8, [r7, #0xc]
 *   @0x2282a8 ldr r1, [r11, #0x4]
 *   @0x2282ac subs r8, r1, r8
 *   @0x2282b0 lsl r12, r0, #2
 *   @0x2282b4 str r0, [r11, #-0x30]
 *   @0x2282b8 add r3, r12, #14
 *   @0x2282bc str r12, [r11, #-0x40]
 *   @0x2282c0 bic r3, r3, #7
 *   @0x2282c4 sub sp, sp, r3
 *   @0x2282c8 str sp, [r11, #-0x38]
 *   @0x2282cc sub sp, sp, r3
 *   @0x2282d0 str sp, [r11, #-0x34]
 *   @0x2282d4 bmi 0x228510 <vorbis_book_decodevs_add+0x2b4>
 *   @0x2282d8 ldr r2, [r11, #-0x30]
 *   @0x2282dc cmp r2, #0
 *   @0x2282e0 ble 0x228444 <vorbis_book_decodevs_add+0x1e8>
 *   @0x2282e4 mov r9, #0
 *   @0x2282e8 str r8, [r11, #-0x48]
 *   @0x2282ec mov r8, r9
 *   @0x2282f0 mov r0, r6
 *   @0x2282f4 ldr r1, [r7, #0x24]
 *   @0x2282f8 ldr r5, [r7, #0x28]
 *   @0x2282fc bl 0x23388c <oggpack_look>
 *   @0x228300 cmp r0, #0
 *   @0x228304 blt 0x228504 <vorbis_book_decodevs_add+0x2a8>
 *   @0x228308 ldr r3, [r7, #0x20]
 *   @0x22830c ldr r4, [r3, r0, lsl #2]
 *   @0x228310 cmp r4, #0
 *   @0x228314 bge 0x2284d4 <vorbis_book_decodevs_add+0x278>
 *   @0x228318 ldr r2, [r7, #0x8]
 *   @0x22831c ubfx r3, r4, #0x0, #0xf
 *   @0x228320 ubfx r4, r4, #0xf, #0xf
 *   @0x228324 rsb r10, r3, r2
 *   @0x228328 b 0x228330 <vorbis_book_decodevs_add+0xd4>
 *   @0x22832c sub r5, r5, #1
 *   @0x228330 mov r0, r6
 *   @0x228334 mov r1, r5
 *   @0x228338 bl 0x23388c <oggpack_look>
 *   @0x22833c cmp r5, #1
 *   @0x228340 movle r3, #0
 *   @0x228344 movgt r3, #1
 *   @0x228348 ands r3, r3, r0, lsr #31
 *   @0x22834c bne 0x22832c <vorbis_book_decodevs_add+0xd0>
 *   @0x228350 cmp r0, #0
 *   @0x228354 blt 0x22873c <vorbis_book_decodevs_add+0x4e0>
 *   @0x228358 rev r0, r0
 *   @0x22835c movw r3, #0xf0f
 *   @0x228360 movw r1, #0xf0f0
 *   @0x228364 bfi r3, r3, #16, #16
 *   @0x228368 bfi r1, r1, #16, #16
 *   @0x22836c and r3, r3, r0, lsr #4
 *   @0x228370 and r0, r1, r0, lsl #4
 *   @0x228374 movw r1, #0x3333
 *   @0x228378 orr r0, r0, r3
 *   @0x22837c bfi r1, r1, #16, #16
 *   @0x228380 movw r3, #0xcccc
 *   @0x228384 bfi r3, r3, #16, #16
 *   @0x228388 and r1, r1, r0, lsr #2
 *   @0x22838c and r3, r3, r0, lsl #2
 *   @0x228390 orr r12, r3, r1
 *   @0x228394 rsb r3, r4, r10
 *   @0x228398 movw r0, #0xaaaa
 *   @0x22839c movw r1, #0x5555
 *   @0x2283a0 bfi r0, r0, #16, #16
 *   @0x2283a4 bfi r1, r1, #16, #16
 *   @0x2283a8 cmp r3, #1
 *   @0x2283ac and r0, r0, r12, lsl #1
 *   @0x2283b0 and r1, r1, r12, lsr #1
 *   @0x2283b4 orr r0, r0, r1
 *   @0x2283b8 ble 0x2283f4 <vorbis_book_decodevs_add+0x198>
 *   @0x2283bc ldr lr, [r7, #0x14]
 *   @0x2283c0 asr r3, r3, #1
 *   @0x2283c4 add r2, r3, r4
 *   @0x2283c8 ldr r2, [lr, r2, lsl #2]
 *   @0x2283cc cmp r2, r0
 *   @0x2283d0 movls r1, r3
 *   @0x2283d4 movhi r1, #0
 *   @0x2283d8 cmp r2, r0
 *   @0x2283dc add r4, r4, r1
 *   @0x2283e0 movls r3, #0
 *   @0x2283e4 rsb r10, r3, r10
 *   @0x2283e8 rsb r3, r4, r10
 *   @0x2283ec cmp r3, #1
 *   @0x2283f0 bgt 0x2283c0 <vorbis_book_decodevs_add+0x164>
 *   @0x2283f4 ldr r3, [r7, #0x1c]
 *   @0x2283f8 mov r0, r6
 *   @0x2283fc ldrb r1, [r3, r4]
 *   @0x228400 cmp r1, r5
 *   @0x228404 bgt 0x22872c <vorbis_book_decodevs_add+0x4d0>
 *   @0x228408 bl 0x233a7c <oggpack_adv>
 *   @0x22840c ldr r12, [r11, #-0x38]
 *   @0x228410 str r4, [r12, r9]
 *   @0x228414 ldr r5, [r7]
 *   @0x228418 add r8, r8, #1
 *   @0x22841c ldr r3, [r7, #0x10]
 *   @0x228420 ldr r2, [r11, #-0x30]
 *   @0x228424 mul r4, r4, r5
 *   @0x228428 cmp r8, r2
 *   @0x22842c add r4, r3, r4, lsl #2
 *   @0x228430 ldr r3, [r11, #-0x34]
 *   @0x228434 str r4, [r3, r9]
 *   @0x228438 add r9, r9, #4
 *   @0x22843c bne 0x2282f0 <vorbis_book_decodevs_add+0x94>
 *   @0x228440 ldr r8, [r11, #-0x48]
 *   @0x228444 cmp r5, #0
 *   @0x228448 ble 0x2284b4 <vorbis_book_decodevs_add+0x258>
 *   @0x22844c ldr r2, [r11, #-0x40]
 *   @0x228450 ldr r4, [r11, #-0x34]
 *   @0x228454 ldr r6, [r11, #-0x44]
 *   @0x228458 ldr r7, [r11, #-0x30]
 *   @0x22845c add r12, r4, r2
 *   @0x228460 ldr r10, [r11, #-0x34]
 *   @0x228464 mov r4, #0
 *   @0x228468 mov r9, r2
 *   @0x22846c cmp r7, #0
 *   @0x228470 ble 0x2284a4 <vorbis_book_decodevs_add+0x248>
 *   @0x228474 lsl r0, r4, #2
 *   @0x228478 mov r2, r10
 *   @0x22847c mov r3, r6
 *   @0x228480 str r4, [r11, #-0x30]
 *   @0x228484 ldr r1, [r2], #4
 *   @0x228488 ldr r4, [r3]
 *   @0x22848c cmp r2, r12
 *   @0x228490 ldr r1, [r1, r0]
 *   @0x228494 add r1, r4, r1, asr r8
 *   @0x228498 str r1, [r3], #4
 *   @0x22849c bne 0x228484 <vorbis_book_decodevs_add+0x228>
 *   @0x2284a0 ldr r4, [r11, #-0x30]
 *   @0x2284a4 add r4, r4, #1
 *   @0x2284a8 add r6, r6, r9
 *   @0x2284ac cmp r4, r5
 *   @0x2284b0 bne 0x22846c <vorbis_book_decodevs_add+0x210>
 *   @0x2284b4 mov r0, #0
 *   @0x2284b8 ldr r12, [r11, #-0x3c]
 *   @0x2284bc ldr r2, [r11, #-0x28]
 *   @0x2284c0 ldr r3, [r12]
 *   @0x2284c4 cmp r2, r3
 *   @0x2284c8 bne 0x22874c <vorbis_book_decodevs_add+0x4f0>
 *   @0x2284cc sub sp, r11, #32
 *   @0x2284d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2284d4 ldr r3, [r7, #0x1c]
 *   @0x2284d8 mov r0, r6
 *   @0x2284dc add r3, r3, r4
 *   @0x2284e0 sub r4, r4, #1
 *   @0x2284e4 ldrb r1, [r3, #-0x1]
 *   @0x2284e8 bl 0x233a7c <oggpack_adv>
 *   @0x2284ec ldr r3, [r11, #-0x38]
 *   @0x2284f0 cmn r4, #1
 *   @0x2284f4 str r4, [r3, r9]
 *   @0x2284f8 bne 0x228414 <vorbis_book_decodevs_add+0x1b8>
 *   @0x2284fc mvn r0, #0
 *   @0x228500 b 0x2284b8 <vorbis_book_decodevs_add+0x25c>
 *   @0x228504 ldr r10, [r7, #0x8]
 *   @0x228508 mov r4, #0
 *   @0x22850c b 0x228330 <vorbis_book_decodevs_add+0xd4>
 *   @0x228510 cmp r0, #0
 *   @0x228514 strgt r8, [r11, #-0x48]
 *   @0x228518 movgt r9, #0
 *   @0x22851c movgt r3, r9
 *   @0x228520 movgt r8, r3
 *   @0x228524 ble 0x22867c <vorbis_book_decodevs_add+0x420>
 *   @0x228528 mov r0, r6
 *   @0x22852c ldr r1, [r7, #0x24]
 *   @0x228530 ldr r5, [r7, #0x28]
 *   @0x228534 bl 0x23388c <oggpack_look>
 *   @0x228538 cmp r0, #0
 *   @0x22853c blt 0x228720 <vorbis_book_decodevs_add+0x4c4>
 *   @0x228540 ldr r3, [r7, #0x20]
 *   @0x228544 ldr r4, [r3, r0, lsl #2]
 *   @0x228548 cmp r4, #0
 *   @0x22854c bge 0x2286f4 <vorbis_book_decodevs_add+0x498>
 *   @0x228550 ldr r2, [r7, #0x8]
 *   @0x228554 ubfx r3, r4, #0x0, #0xf
 *   @0x228558 ubfx r4, r4, #0xf, #0xf
 *   @0x22855c rsb r10, r3, r2
 *   @0x228560 b 0x228568 <vorbis_book_decodevs_add+0x30c>
 *   @0x228564 sub r5, r5, #1
 *   @0x228568 mov r0, r6
 *   @0x22856c mov r1, r5
 *   @0x228570 bl 0x23388c <oggpack_look>
 *   @0x228574 cmp r5, #1
 *   @0x228578 movle r3, #0
 *   @0x22857c movgt r3, #1
 *   @0x228580 ands r3, r3, r0, lsr #31
 *   @0x228584 bne 0x228564 <vorbis_book_decodevs_add+0x308>
 *   @0x228588 cmp r0, #0
 *   @0x22858c blt 0x22873c <vorbis_book_decodevs_add+0x4e0>
 *   @0x228590 rev r0, r0
 *   @0x228594 movw r12, #0xf0f
 *   @0x228598 movw r3, #0xf0f0
 *   @0x22859c bfi r12, r12, #16, #16
 *   @0x2285a0 bfi r3, r3, #16, #16
 *   @0x2285a4 and r12, r12, r0, lsr #4
 *   @0x2285a8 and r0, r3, r0, lsl #4
 *   @0x2285ac movw r1, #0x3333
 *   @0x2285b0 orr r0, r0, r12
 *   @0x2285b4 bfi r1, r1, #16, #16
 *   @0x2285b8 movw r3, #0xcccc
 *   @0x2285bc bfi r3, r3, #16, #16
 *   @0x2285c0 and r1, r1, r0, lsr #2
 *   @0x2285c4 and r12, r3, r0, lsl #2
 *   @0x2285c8 orr r12, r12, r1
 *   @0x2285cc rsb r3, r4, r10
 *   @0x2285d0 movw r0, #0xaaaa
 *   @0x2285d4 movw r1, #0x5555
 *   @0x2285d8 bfi r0, r0, #16, #16
 *   @0x2285dc bfi r1, r1, #16, #16
 *   @0x2285e0 cmp r3, #1
 *   @0x2285e4 and r0, r0, r12, lsl #1
 *   @0x2285e8 and r1, r1, r12, lsr #1
 *   @0x2285ec orr r0, r0, r1
 *   @0x2285f0 ble 0x22862c <vorbis_book_decodevs_add+0x3d0>
 *   @0x2285f4 ldr lr, [r7, #0x14]
 *   @0x2285f8 asr r3, r3, #1
 *   @0x2285fc add r2, r3, r4
 *   @0x228600 ldr r2, [lr, r2, lsl #2]
 *   @0x228604 cmp r2, r0
 *   @0x228608 movls r1, r3
 *   @0x22860c movhi r1, #0
 *   @0x228610 cmp r2, r0
 *   @0x228614 add r4, r4, r1
 *   @0x228618 movls r3, #0
 *   @0x22861c rsb r10, r3, r10
 *   @0x228620 rsb r3, r4, r10
 *   @0x228624 cmp r3, #1
 *   @0x228628 bgt 0x2285f8 <vorbis_book_decodevs_add+0x39c>
 *   @0x22862c ldr r3, [r7, #0x1c]
 *   @0x228630 mov r0, r6
 *   @0x228634 ldrb r1, [r3, r4]
 *   @0x228638 cmp r1, r5
 *   @0x22863c bgt 0x22872c <vorbis_book_decodevs_add+0x4d0>
 *   @0x228640 bl 0x233a7c <oggpack_adv>
 *   @0x228644 ldr r2, [r11, #-0x38]
 *   @0x228648 str r4, [r2, r9]
 *   @0x22864c ldr r5, [r7]
 *   @0x228650 add r8, r8, #1
 *   @0x228654 ldr r3, [r11, #-0x30]
 *   @0x228658 ldr r12, [r11, #-0x34]
 *   @0x22865c mul r4, r4, r5
 *   @0x228660 cmp r8, r3
 *   @0x228664 ldr r3, [r7, #0x10]
 *   @0x228668 add r4, r3, r4, lsl #2
 *   @0x22866c str r4, [r12, r9]
 *   @0x228670 add r9, r9, #4
 *   @0x228674 bne 0x228528 <vorbis_book_decodevs_add+0x2cc>
 *   @0x228678 ldr r8, [r11, #-0x48]
 *   @0x22867c cmp r5, #0
 *   @0x228680 ble 0x2284b4 <vorbis_book_decodevs_add+0x258>
 *   @0x228684 ldr r2, [r11, #-0x34]
 *   @0x228688 rsb r8, r8, #0
 *   @0x22868c ldr r3, [r11, #-0x40]
 *   @0x228690 mov r4, #0
 *   @0x228694 ldr r6, [r11, #-0x44]
 *   @0x228698 ldr r7, [r11, #-0x30]
 *   @0x22869c add r12, r2, r3
 *   @0x2286a0 mov r9, r3
 *   @0x2286a4 mov r10, r2
 *   @0x2286a8 cmp r7, #0
 *   @0x2286ac ble 0x2286e0 <vorbis_book_decodevs_add+0x484>
 *   @0x2286b0 lsl r0, r4, #2
 *   @0x2286b4 mov r2, r10
 *   @0x2286b8 mov r3, r6
 *   @0x2286bc str r4, [r11, #-0x30]
 *   @0x2286c0 ldr r1, [r2], #4
 *   @0x2286c4 ldr r4, [r3]
 *   @0x2286c8 cmp r2, r12
 *   @0x2286cc ldr r1, [r1, r0]
 *   @0x2286d0 add r1, r4, r1, lsl r8
 *   @0x2286d4 str r1, [r3], #4
 *   @0x2286d8 bne 0x2286c0 <vorbis_book_decodevs_add+0x464>
 *   @0x2286dc ldr r4, [r11, #-0x30]
 *   @0x2286e0 add r4, r4, #1
 *   @0x2286e4 add r6, r6, r9
 *   @0x2286e8 cmp r4, r5
 *   @0x2286ec bne 0x2286a8 <vorbis_book_decodevs_add+0x44c>
 *   @0x2286f0 b 0x2284b4 <vorbis_book_decodevs_add+0x258>
 *   @0x2286f4 ldr r3, [r7, #0x1c]
 *   @0x2286f8 mov r0, r6
 *   @0x2286fc add r3, r3, r4
 *   @0x228700 sub r4, r4, #1
 *   @0x228704 ldrb r1, [r3, #-0x1]
 *   @0x228708 bl 0x233a7c <oggpack_adv>
 *   @0x22870c ldr r12, [r11, #-0x38]
 *   @0x228710 cmn r4, #1
 *   @0x228714 str r4, [r12, r9]
 *   @0x228718 bne 0x22864c <vorbis_book_decodevs_add+0x3f0>
 *   @0x22871c b 0x2284fc <vorbis_book_decodevs_add+0x2a0>
 *   @0x228720 ldr r10, [r7, #0x8]
 *   @0x228724 mov r4, #0
 *   @0x228728 b 0x228568 <vorbis_book_decodevs_add+0x30c>
 *   @0x22872c add r1, r5, #1
 *   @0x228730 bl 0x233a7c <oggpack_adv>
 *   @0x228734 mvn r0, #0
 *   @0x228738 b 0x2284b8 <vorbis_book_decodevs_add+0x25c>
 *   @0x22873c mov r0, r6
 *   @0x228740 mov r1, #1
 *   @0x228744 bl 0x233a7c <oggpack_adv>
 *   @0x228748 b 0x2284fc <vorbis_book_decodevs_add+0x2a0>
 *   @0x22874c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x228750 andseq r5, r12, r0, ror #13
 *
 * ══ §19/23 F_HttpRequest(RValue&, CInstance*, CInstance*, int, RValue*)  0x13a5bc  size 1264  316 条（0x13a5bc..0x13aaac）
 * @func 0x13a5bc 0x13aaac  size 1264  316 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x13a5cc→0x533c54, 0x13a680→0x4836b0, 0x13a93c→0x5356b4
 * 调用序列: 0xb6538×3 / LoadSave::HTTP_Request(char const*, char const*, char const*, char const*, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, int)×3 / YYGetString(RValue const*, int)×2 / YYGetInt32(RValue const*, int)×2 / DS_AutoMutex::DS_AutoMutex()×2 / CDS_Map::FindFirst()×2 / CDS_Map::FindNext(RValue*)×2 / DS_AutoMutex::~DS_AutoMutex()×2
 * 字段偏移 top8: 0x4×12 / 0xc×9 / 0x8×7 / 0x1c×6 / 0x20×6 / 0x30×5 / 0x10×5 / 0x28×4
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13a5bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13a5c0 sub sp, sp, #100
 *   @0x13a5c4 ldr r7, [pc, #0x4ac]
 *   @0x13a5c8 mov r1, #0
 *   @0x13a5cc ldr r3, [pc, #0x4a8]
 *   @0x13a5d0 mov r5, #1
 *   @0x13a5d4 add r7, pc, r7
 *   @0x13a5d8 ldr r4, [sp, #0x88]
 *   @0x13a5dc str r7, [sp, #0x1c]
 *   @0x13a5e0 str r0, [sp, #0x18]
 *   @0x13a5e4 ldr r3, [r7, r3]
 *   @0x13a5e8 mov r0, r4
 *   @0x13a5ec strb r5, [r3]
 *   @0x13a5f0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a5f4 mov r1, r5
 *   @0x13a5f8 str r0, [sp, #0x20]
 *   @0x13a5fc mov r0, r4
 *   @0x13a600 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a604 mov r1, #2
 *   @0x13a608 str r0, [sp, #0x30]
 *   @0x13a60c mov r0, r4
 *   @0x13a610 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13a614 ldr r3, [r4, #0x3c]
 *   @0x13a618 bic r3, r3, #-16777216
 *   @0x13a61c cmp r3, r5
 *   @0x13a620 mov r8, r0
 *   @0x13a624 beq 0x13a9b0 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x3f4>
 *   @0x13a628 mov r0, r4
 *   @0x13a62c mov r1, #3
 *   @0x13a630 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13a634 mov r12, #0
 *   @0x13a638 str r12, [sp, #0x2c]
 *   @0x13a63c str r0, [sp, #0x34]
 *   @0x13a640 add r12, sp, #56
 *   @0x13a644 str r12, [sp, #0x24]
 *   @0x13a648 mov r2, #0
 *   @0x13a64c add r7, sp, #60
 *   @0x13a650 mov r0, r12
 *   @0x13a654 ldr r12, [sp, #0x18]
 *   @0x13a658 mov r3, r2
 *   @0x13a65c movt r2, #0xbff0
 *   @0x13a660 str r7, [sp, #0x10]
 *   @0x13a664 lsl r10, r8, #2
 *   @0x13a668 str r3, [r12, #0xc]
 *   @0x13a66c str r3, [r12]
 *   @0x13a670 str r2, [r12, #0x4]
 *   @0x13a674 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x13a678 add r0, sp, #60
 *   @0x13a67c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x13a680 ldr r3, [pc, #0x3f8]
 *   @0x13a684 ldr r7, [sp, #0x1c]
 *   @0x13a688 ldr r6, [r7, r3]
 *   @0x13a68c ldr r3, [r6, #0x4]
 *   @0x13a690 ldr r0, [r3, r8, lsl #2]
 *   @0x13a694 bl 0x203c8c <_ZN7CDS_Map9FindFirstEv>
 *   @0x13a698 subs r3, r0, #0
 *   @0x13a69c beq 0x13aa68 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x4ac>
 *   @0x13a6a0 ldr r9, [pc, #0x3dc]
 *   @0x13a6a4 mvn r12, #0
 *   @0x13a6a8 add r4, sp, #64
 *   @0x13a6ac add r7, sp, #80
 *   @0x13a6b0 add r9, pc, r9
 *   @0x13a6b4 mov r5, #1
 *   @0x13a6b8 str r12, [sp, #0x28]
 *   @0x13a6bc str r8, [sp, #0x14]
 *   @0x13a6c0 b 0x13a710 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x13a6c4 cmp r3, #1
 *   @0x13a6c8 movne r11, #0
 *   @0x13a6cc beq 0x13a784 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x13a6d0 cmp lr, #1
 *   @0x13a6d4 beq 0x13a798 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x1dc>
 *   @0x13a6d8 mov r0, r8
 *   @0x13a6dc bl 0xb6538 <strlen@plt>
 *   @0x13a6e0 mov r8, r0
 *   @0x13a6e4 mov r0, r11
 *   @0x13a6e8 bl 0xb6538 <strlen@plt>
 *   @0x13a6ec ldr r2, [r6, #0x4]
 *   @0x13a6f0 mov r1, r4
 *   @0x13a6f4 add r3, r8, r0
 *   @0x13a6f8 ldr r0, [r2, r10]
 *   @0x13a6fc add r3, r3, #4
 *   @0x13a700 add r5, r5, r3
 *   @0x13a704 bl 0x203b94 <_ZN7CDS_Map8FindNextEP6RValue>
 *   @0x13a708 subs r3, r0, #0
 *   @0x13a70c beq 0x13a7bc <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x200>
 *   @0x13a710 ldr r0, [r3]
 *   @0x13a714 mov r11, r3
 *   @0x13a718 ldr r1, [r3, #0x4]
 *   @0x13a71c mov lr, r4
 *   @0x13a720 ldr r2, [r3, #0x8]
 *   @0x13a724 mov r12, r7
 *   @0x13a728 ldr r3, [r3, #0xc]
 *   @0x13a72c stm lr!, {r0, r1, r2, r3}
 *   @0x13a730 ldr lr, [sp, #0x4c]
 *   @0x13a734 bic lr, lr, #-16777216
 *   @0x13a738 str lr, [sp, #0x4c]
 *   @0x13a73c ldr r0, [r11, #0x10]!
 *   @0x13a740 cmp lr, #1
 *   @0x13a744 movne r8, #0
 *   @0x13a748 ldr r3, [r11, #0xc]
 *   @0x13a74c ldr r1, [r11, #0x4]
 *   @0x13a750 ldr r2, [r11, #0x8]
 *   @0x13a754 stm r12!, {r0, r1, r2, r3}
 *   @0x13a758 ldr r3, [sp, #0x5c]
 *   @0x13a75c bic r3, r3, #-16777216
 *   @0x13a760 str r3, [sp, #0x5c]
 *   @0x13a764 bne 0x13a6c4 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x13a768 ldr r2, [sp, #0x40]
 *   @0x13a76c cmp r2, #0
 *   @0x13a770 ldrne r8, [r2]
 *   @0x13a774 moveq r8, r2
 *   @0x13a778 cmp r3, #1
 *   @0x13a77c movne r11, #0
 *   @0x13a780 bne 0x13a6d0 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x13a784 ldr r11, [sp, #0x50]
 *   @0x13a788 cmp r11, #0
 *   @0x13a78c ldrne r11, [r11]
 *   @0x13a790 cmp lr, #1
 *   @0x13a794 bne 0x13a6d8 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x13a798 mov r0, r9
 *   @0x13a79c mov r1, r8
 *   @0x13a7a0 bl 0xb6574 <strcmp@plt>
 *   @0x13a7a4 cmp r0, #0
 *   @0x13a7a8 bne 0x13a6d8 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x13a7ac mov r0, r11
 *   @0x13a7b0 bl 0xb66b8 <atoi@plt>
 *   @0x13a7b4 str r0, [sp, #0x28]
 *   @0x13a7b8 b 0x13a6d8 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x11c>
 *   @0x13a7bc ldr r8, [sp, #0x14]
 *   @0x13a7c0 add r0, sp, #60
 *   @0x13a7c4 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x13a7c8 ldr r1, [pc, #0x2b8]
 *   @0x13a7cc mov r0, r5
 *   @0x13a7d0 movw r2, #0x8c6
 *   @0x13a7d4 add r1, pc, r1
 *   @0x13a7d8 mov r3, #1
 *   @0x13a7dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13a7e0 mov r3, #0
 *   @0x13a7e4 strb r3, [r0]
 *   @0x13a7e8 mov r5, r0
 *   @0x13a7ec ldr r3, [r6, #0x4]
 *   @0x13a7f0 ldr r0, [r3, r8, lsl #2]
 *   @0x13a7f4 bl 0x203c8c <_ZN7CDS_Map9FindFirstEv>
 *   @0x13a7f8 subs r3, r0, #0
 *   @0x13a7fc beq 0x13a8fc <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x340>
 *   @0x13a800 ldr r8, [pc, #0x284]
 *   @0x13a804 add r4, sp, #64
 *   @0x13a808 ldr r9, [pc, #0x280]
 *   @0x13a80c add r7, sp, #80
 *   @0x13a810 ldr r12, [pc, #0x27c]
 *   @0x13a814 add r8, pc, r8
 *   @0x13a818 add r9, pc, r9
 *   @0x13a81c str r8, [sp, #0x10]
 *   @0x13a820 add r12, pc, r12
 *   @0x13a824 str r12, [sp, #0x14]
 *   @0x13a828 b 0x13a878 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x2bc>
 *   @0x13a82c cmp r3, #1
 *   @0x13a830 movne r11, #0
 *   @0x13a834 beq 0x13a8ec <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x330>
 *   @0x13a838 mov r0, r5
 *   @0x13a83c bl 0xb6538 <strlen@plt>
 *   @0x13a840 ldr r12, [sp, #0x14]
 *   @0x13a844 mov r2, r8
 *   @0x13a848 ldr r1, [sp, #0x10]
 *   @0x13a84c mov r3, r9
 *   @0x13a850 str r11, [sp]
 *   @0x13a854 str r12, [sp, #0x4]
 *   @0x13a858 add r0, r5, r0
 *   @0x13a85c bl 0xb6550 <sprintf@plt>
 *   @0x13a860 ldr r3, [r6, #0x4]
 *   @0x13a864 mov r1, r4
 *   @0x13a868 ldr r0, [r3, r10]
 *   @0x13a86c bl 0x203b94 <_ZN7CDS_Map8FindNextEP6RValue>
 *   @0x13a870 subs r3, r0, #0
 *   @0x13a874 beq 0x13a8fc <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x340>
 *   @0x13a878 ldr r0, [r3]
 *   @0x13a87c mov r11, r3
 *   @0x13a880 ldr r1, [r3, #0x4]
 *   @0x13a884 mov lr, r4
 *   @0x13a888 ldr r2, [r3, #0x8]
 *   @0x13a88c mov r12, r7
 *   @0x13a890 ldr r3, [r3, #0xc]
 *   @0x13a894 stm lr!, {r0, r1, r2, r3}
 *   @0x13a898 ldr r3, [sp, #0x4c]
 *   @0x13a89c bic r3, r3, #-16777216
 *   @0x13a8a0 str r3, [sp, #0x4c]
 *   @0x13a8a4 ldr r0, [r11, #0x10]!
 *   @0x13a8a8 cmp r3, #1
 *   @0x13a8ac movne r8, #0
 *   @0x13a8b0 ldr r3, [r11, #0xc]
 *   @0x13a8b4 ldr r1, [r11, #0x4]
 *   @0x13a8b8 ldr r2, [r11, #0x8]
 *   @0x13a8bc stm r12!, {r0, r1, r2, r3}
 *   @0x13a8c0 ldr r3, [sp, #0x5c]
 *   @0x13a8c4 bic r3, r3, #-16777216
 *   @0x13a8c8 str r3, [sp, #0x5c]
 *   @0x13a8cc bne 0x13a82c <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x270>
 *   @0x13a8d0 ldr r2, [sp, #0x40]
 *   @0x13a8d4 cmp r2, #0
 *   @0x13a8d8 ldrne r8, [r2]
 *   @0x13a8dc moveq r8, r2
 *   @0x13a8e0 cmp r3, #1
 *   @0x13a8e4 movne r11, #0
 *   @0x13a8e8 bne 0x13a838 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x27c>
 *   @0x13a8ec ldr r11, [sp, #0x50]
 *   @0x13a8f0 cmp r11, #0
 *   @0x13a8f4 ldrne r11, [r11]
 *   @0x13a8f8 b 0x13a838 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x27c>
 *   @0x13a8fc add r0, sp, #56
 *   @0x13a900 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x13a904 ldr r0, [pc, #0x18c]
 *   @0x13a908 ldr r1, [sp, #0x20]
 *   @0x13a90c mov r2, #7
 *   @0x13a910 add r0, pc, r0
 *   @0x13a914 bl 0xb65e0 <strncmp@plt>
 *   @0x13a918 cmp r0, #0
 *   @0x13a91c beq 0x13a93c <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x380>
 *   @0x13a920 ldr r0, [pc, #0x174]
 *   @0x13a924 mov r2, #8
 *   @0x13a928 ldr r1, [sp, #0x20]
 *   @0x13a92c add r0, pc, r0
 *   @0x13a930 bl 0xb65e0 <strncmp@plt>
 *   @0x13a934 cmp r0, #0
 *   @0x13a938 bne 0x13a9a8 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x3ec>
 *   @0x13a93c ldr r3, [pc, #0x15c]
 *   @0x13a940 ldr r8, [sp, #0x1c]
 *   @0x13a944 ldr r7, [sp, #0x2c]
 *   @0x13a948 ldr r3, [r8, r3]
 *   @0x13a94c cmp r7, #0
 *   @0x13a950 ldr r4, [r3]
 *   @0x13a954 beq 0x13a9d8 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x41c>
 *   @0x13a958 ldr r2, [pc, #0x144]
 *   @0x13a95c mov r12, #0
 *   @0x13a960 mvn lr, #0
 *   @0x13a964 ldr r0, [sp, #0x20]
 *   @0x13a968 ldr r1, [sp, #0x30]
 *   @0x13a96c mov r3, r7
 *   @0x13a970 ldr r6, [r8, r2]
 *   @0x13a974 mov r2, r5
 *   @0x13a978 str r12, [sp, #0x4]
 *   @0x13a97c str r12, [sp, #0x8]
 *   @0x13a980 str r6, [sp]
 *   @0x13a984 str lr, [sp, #0xc]
 *   @0x13a988 bl 0x18fdb8 <_ZN8LoadSave12HTTP_RequestEPKcS1_S1_S1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_i>
 *   @0x13a98c mov r0, r5
 *   @0x13a990 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13a994 vmov s15, r4
 *   @0x13a998 ldr r7, [sp, #0x18]
 *   @0x13a99c vcvt.f64.s32 d7, s15
 *   @0x13a9a0 vmov r2, r3, d7
 *   @0x13a9a4 stm r7, {r2, r3}
 *   @0x13a9a8 add sp, sp, #100
 *   @0x13a9ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13a9b0 ldr r3, [r4, #0x30]
 *   @0x13a9b4 cmp r3, #0
 *   @0x13a9b8 beq 0x13a628 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x13a9bc ldr r3, [r3]
 *   @0x13a9c0 cmp r3, #0
 *   @0x13a9c4 strne r3, [sp, #0x2c]
 *   @0x13a9c8 mvnne r7, #0
 *   @0x13a9cc strne r7, [sp, #0x34]
 *   @0x13a9d0 bne 0x13a640 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x13a9d4 b 0x13a628 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x13a9d8 ldr r0, [sp, #0x34]
 *   @0x13a9dc bl 0xc6720 <_Z10GetIBufferi>
 *   @0x13a9e0 subs r12, r0, #0
 *   @0x13a9e4 beq 0x13aa30 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x474>
 *   @0x13a9e8 ldr r3, [r12, #0x1c]
 *   @0x13a9ec cmp r3, #0
 *   @0x13a9f0 beq 0x13aa30 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x474>
 *   @0x13a9f4 ldr r8, [sp, #0x1c]
 *   @0x13a9f8 mov r2, r5
 *   @0x13a9fc ldr lr, [pc, #0xa0]
 *   @0x13aa00 ldr r3, [r12, #0xc]
 *   @0x13aa04 ldr r7, [sp, #0x2c]
 *   @0x13aa08 ldr r12, [r8, lr]
 *   @0x13aa0c ldr r8, [sp, #0x28]
 *   @0x13aa10 ldr r0, [sp, #0x20]
 *   @0x13aa14 ldr r1, [sp, #0x30]
 *   @0x13aa18 str r7, [sp, #0x4]
 *   @0x13aa1c str r7, [sp, #0x8]
 *   @0x13aa20 str r12, [sp]
 *   @0x13aa24 str r8, [sp, #0xc]
 *   @0x13aa28 bl 0x18fdb8 <_ZN8LoadSave12HTTP_RequestEPKcS1_S1_S1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_i>
 *   @0x13aa2c b 0x13a98c <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x3d0>
 *   @0x13aa30 ldr r2, [pc, #0x70]
 *   @0x13aa34 mov lr, #0
 *   @0x13aa38 ldr r8, [sp, #0x1c]
 *   @0x13aa3c mvn r6, #0
 *   @0x13aa40 ldr r0, [sp, #0x20]
 *   @0x13aa44 mov r3, lr
 *   @0x13aa48 ldr r1, [sp, #0x30]
 *   @0x13aa4c ldr r7, [r8, r2]
 *   @0x13aa50 mov r2, r5
 *   @0x13aa54 str r12, [sp, #0x8]
 *   @0x13aa58 str r6, [sp, #0xc]
 *   @0x13aa5c stm sp, {r7, lr}
 *   @0x13aa60 bl 0x18fdb8 <_ZN8LoadSave12HTTP_RequestEPKcS1_S1_S1_PFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_i>
 *   @0x13aa64 b 0x13a98c <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x3d0>
 *   @0x13aa68 mvn r7, #0
 *   @0x13aa6c mov r5, #1
 *   @0x13aa70 str r7, [sp, #0x28]
 *   @0x13aa74 b 0x13a7c0 <_Z13F_HttpRequestR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x13aa78 eoreq r7, r11, r12, ror r6
 *   @0x13aa7c .word 0xffffbd04
 *   @0x13aa80 .word 0xffffbcec
 *   @0x13aa84 eoreq r5, r0, r8, ror #24
 *   @0x13aa88 eoreq r5, r0, r12, ror r8
 *   @0x13aa8c eoreq r5, r0, r4, lsl r11
 *   @0x13aa90 eoreq r5, r0, r12, lsl r11
 *   @0x13aa94 eoreq r5, r0, r8, lsl r11
 *   @0x13aa98 ldrsbeq r6, [pc], -r0
 *   @0x13aa9c ldrheq r6, [pc], -r12
 *   @0x13aaa0 .word 0xffffd628
 *   @0x13aaa4 .word 0xffffd62c
 *   @0x13aaa8 .word 0xffffd648
 *
 * ══ §20/23 Java_com_yoyogames_runner_RunnerJNILib_Process  0x294518  size 1244  311 条（0x294518..0x2949f4）
 * @func 0x294518 0x2949f4  size 1244  311 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29452c→0x3f5120, 0x294554→0x7577bc, 0x29456c→0x3f26dc, 0x29458c→0x479c24, 0x2945a4→0x479c80, 0x2945f8→0x479c20, 0x294624→0x7577b8, 0x294648→0x756d44
 * 调用序列: Timing_Time×2 / Java_com_yoyogames_runner_RunnerJNILib_Process+0x74×2 / operator delete(void*)×2 / MemoryManager::Free(void const*)×2 / setJNIEnv / GR_D3D_Settings_Init() / GR_D3D_Lights_Resume() / getJNIEnv
 * 字段偏移 top8: 0x4×10 / 0x8×6 / 0xc×6 / 0x344×3 / 0x28c×3 / 0x330×2 / 0x320×2 / 0x2d4×2
 * VFP 指令 8 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294518 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29451c vpush {d8, d9}
 *   @0x294520 mov r9, r2
 *   @0x294524 ldr r4, [pc, #0x448]
 *   @0x294528 sub sp, sp, #20
 *   @0x29452c ldr r2, [pc, #0x444]
 *   @0x294530 vldr s18, [sp, #72]
 *   @0x294534 add r4, pc, r4
 *   @0x294538 str r3, [sp, #0x4]
 *   @0x29453c ldr r1, [sp, #0x5c]
 *   @0x294540 vldr s17, [sp, #76]
 *   @0x294544 ldr r3, [r4, r2]
 *   @0x294548 vldr s16, [sp, #80]
 *   @0x29454c str r1, [r3]
 *   @0x294550 bl 0x290614 <setJNIEnv>
 *   @0x294554 ldr r3, [pc, #0x420]
 *   @0x294558 ldr r3, [r4, r3]
 *   @0x29455c str r3, [sp, #0x8]
 *   @0x294560 ldrb r3, [r3]
 *   @0x294564 cmp r3, #0
 *   @0x294568 beq 0x294644 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x12c>
 *   @0x29456c ldr r3, [pc, #0x40c]
 *   @0x294570 ldr r3, [r4, r3]
 *   @0x294574 str r3, [sp, #0xc]
 *   @0x294578 ldr r3, [r3]
 *   @0x29457c cmp r3, #0
 *   @0x294580 beq 0x2947ec <Java_com_yoyogames_runner_RunnerJNILib_Process+0x2d4>
 *   @0x294584 cmp r3, #1
 *   @0x294588 beq 0x2948f4 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x3dc>
 *   @0x29458c ldr r3, [pc, #0x3f0]
 *   @0x294590 mov r1, #1065353216
 *   @0x294594 mov r0, #0
 *   @0x294598 ldr r3, [r4, r3]
 *   @0x29459c ldr r3, [r3]
 *   @0x2945a0 blx r3
 *   @0x2945a4 ldr r3, [pc, #0x3dc]
 *   @0x2945a8 movw r0, #0xbe2
 *   @0x2945ac ldr r5, [r4, r3]
 *   @0x2945b0 ldr r3, [r5]
 *   @0x2945b4 blx r3
 *   @0x2945b8 ldr r3, [r5]
 *   @0x2945bc movw r0, #0xb44
 *   @0x2945c0 blx r3
 *   @0x2945c4 ldr r3, [r5]
 *   @0x2945c8 mov r0, #2960
 *   @0x2945cc blx r3
 *   @0x2945d0 ldr r3, [r5]
 *   @0x2945d4 movw r0, #0x1702
 *   @0x2945d8 blx r3
 *   @0x2945dc ldr r3, [r5]
 *   @0x2945e0 mov r0, #3024
 *   @0x2945e4 blx r3
 *   @0x2945e8 ldr r12, [sp, #0xc]
 *   @0x2945ec ldr r3, [r12]
 *   @0x2945f0 cmp r3, #0
 *   @0x2945f4 beq 0x2948c4 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x3ac>
 *   @0x2945f8 ldr r3, [pc, #0x38c]
 *   @0x2945fc movw r0, #0x203
 *   @0x294600 ldr r3, [r4, r3]
 *   @0x294604 ldr r3, [r3]
 *   @0x294608 blx r3
 *   @0x29460c bl 0x168a50 <_Z20GR_D3D_Settings_Initv>
 *   @0x294610 bl 0x17fb70 <_Z20GR_D3D_Lights_Resumev>
 *   @0x294614 ldr r2, [sp, #0xc]
 *   @0x294618 ldr r3, [r2]
 *   @0x29461c cmp r3, #1
 *   @0x294620 beq 0x2948ec <Java_com_yoyogames_runner_RunnerJNILib_Process+0x3d4>
 *   @0x294624 ldr r3, [pc, #0x364]
 *   @0x294628 mov r2, #0
 *   @0x29462c ldr r12, [sp, #0x8]
 *   @0x294630 ldr r3, [r4, r3]
 *   @0x294634 strb r2, [r12]
 *   @0x294638 ldr r2, [r3]
 *   @0x29463c add r2, r2, #1
 *   @0x294640 str r2, [r3]
 *   @0x294644 bl 0x290274 <getJNIEnv>
 *   @0x294648 ldr r2, [pc, #0x344]
 *   @0x29464c ldr r3, [pc, #0x344]
 *   @0x294650 ldr r10, [pc, #0x344]
 *   @0x294654 ldr r2, [r4, r2]
 *   @0x294658 ldr r3, [r4, r3]
 *   @0x29465c ldr r7, [pc, #0x33c]
 *   @0x294660 ldr r1, [r2]
 *   @0x294664 ldr r2, [r3]
 *   @0x294668 bl 0xf2878 <_ZN7_JNIEnv19CallStaticIntMethodEP7_jclassP10_jmethodIDz>
 *   @0x29466c ldr r3, [pc, #0x330]
 *   @0x294670 ldr r6, [pc, #0x330]
 *   @0x294674 mov r2, #2560
 *   @0x294678 ldr r11, [pc, #0x32c]
 *   @0x29467c ldr r5, [r4, r3]
 *   @0x294680 ldr r12, [sp, #0x54]
 *   @0x294684 ldr r3, [pc, #0x324]
 *   @0x294688 and lr, r12, #1
 *   @0x29468c ldr r12, [pc, #0x320]
 *   @0x294690 ldr r1, [pc, #0x320]
 *   @0x294694 subs r8, r0, #1
 *   @0x294698 rsbs r0, r8, #0
 *   @0x29469c adcs r0, r0, r8
 *   @0x2946a0 strb r0, [r5]
 *   @0x2946a4 ldr r0, [r4, r10]
 *   @0x2946a8 vstr s18, [r0]
 *   @0x2946ac ldr r0, [r4, r11]
 *   @0x2946b0 vstr s17, [r0]
 *   @0x2946b4 ldr r0, [r4, r7]
 *   @0x2946b8 vstr s16, [r0]
 *   @0x2946bc ldr r0, [r4, r6]
 *   @0x2946c0 strb lr, [r0]
 *   @0x2946c4 ldr r0, [r4, r12]
 *   @0x2946c8 ldr r12, [sp, #0x58]
 *   @0x2946cc str r12, [r0]
 *   @0x2946d0 ldr r0, [r4, r1]
 *   @0x2946d4 ldr r1, [r4, r3]
 *   @0x2946d8 bl 0xb65bc <memcpy@plt>
 *   @0x2946dc bl 0x215148 <Timing_Time>
 *   @0x2946e0 ldr lr, [pc, #0x2d4]
 *   @0x2946e4 ldr r12, [pc, #0x2d4]
 *   @0x2946e8 mov r2, r9
 *   @0x2946ec add lr, pc, lr
 *   @0x2946f0 ldr r3, [sp, #0x4]
 *   @0x2946f4 mov r6, r0
 *   @0x2946f8 mov r7, r1
 *   @0x2946fc strd r6, r7, [lr, #16]
 *   @0x294700 mov r0, #0
 *   @0x294704 ldr r12, [r4, r12]
 *   @0x294708 mov r1, r0
 *   @0x29470c ldr r12, [r12]
 *   @0x294710 blx r12
 *   @0x294714 ldr r12, [pc, #0x2a8]
 *   @0x294718 mov r0, #0
 *   @0x29471c mov r2, r9
 *   @0x294720 mov r1, r0
 *   @0x294724 ldr r3, [sp, #0x4]
 *   @0x294728 ldr r12, [r4, r12]
 *   @0x29472c ldr r12, [r12]
 *   @0x294730 blx r12
 *   @0x294734 ldr r3, [pc, #0x28c]
 *   @0x294738 ldr r1, [pc, #0x28c]
 *   @0x29473c ldr r2, [pc, #0x28c]
 *   @0x294740 ldr r0, [r4, r3]
 *   @0x294744 ldr r12, [sp, #0x4]
 *   @0x294748 ldr r3, [pc, #0x284]
 *   @0x29474c str r9, [r0]
 *   @0x294750 ldr r1, [r4, r1]
 *   @0x294754 str r9, [r1]
 *   @0x294758 ldr r2, [r4, r2]
 *   @0x29475c str r12, [r2]
 *   @0x294760 ldr r3, [r4, r3]
 *   @0x294764 str r12, [r3]
 *   @0x294768 bl 0x1d4778 <_Z16MainLoop_Processv>
 *   @0x29476c ldr r3, [pc, #0x264]
 *   @0x294770 ldr r3, [r4, r3]
 *   @0x294774 ldrb r3, [r3]
 *   @0x294778 cmp r3, #0
 *   @0x29477c bne 0x29478c <Java_com_yoyogames_runner_RunnerJNILib_Process+0x274>
 *   @0x294780 ldrb r3, [r5]
 *   @0x294784 cmp r3, #0
 *   @0x294788 bne 0x2948bc <Java_com_yoyogames_runner_RunnerJNILib_Process+0x3a4>
 *   @0x29478c ldr r3, [pc, #0x248]
 *   @0x294790 ldr r5, [r4, r3]
 *   @0x294794 ldrb r8, [r5]
 *   @0x294798 cmp r8, #0
 *   @0x29479c beq 0x294894 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x37c>
 *   @0x2947a0 bl 0x215148 <Timing_Time>
 *   @0x2947a4 ldr r3, [pc, #0x234]
 *   @0x2947a8 ldrb r2, [r5]
 *   @0x2947ac ldr r3, [r4, r3]
 *   @0x2947b0 subs r0, r0, r6
 *   @0x2947b4 sbc r1, r1, r7
 *   @0x2947b8 cmp r2, #0
 *   @0x2947bc strd r0, r1, [r3]
 *   @0x2947c0 movne r0, #1
 *   @0x2947c4 bne 0x2947e0 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x2c8>
 *   @0x2947c8 ldr r3, [pc, #0x214]
 *   @0x2947cc ldr r3, [r4, r3]
 *   @0x2947d0 ldrb r0, [r3]
 *   @0x2947d4 cmp r0, #0
 *   @0x2947d8 movne r0, #2
 *   @0x2947dc moveq r0, #0
 *   @0x2947e0 add sp, sp, #20
 *   @0x2947e4 vpop {d8, d9}
 *   @0x2947e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2947ec ldr r3, [pc, #0x1f4]
 *   @0x2947f0 ldr r3, [r4, r3]
 *   @0x2947f4 ldr r3, [r3]
 *   @0x2947f8 cmp r3, #0
 *   @0x2947fc mvnne r2, #0
 *   @0x294800 beq 0x294814 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x2fc>
 *   @0x294804 str r2, [r3, #0x14]
 *   @0x294808 ldr r3, [r3, #0x34]
 *   @0x29480c cmp r3, #0
 *   @0x294810 bne 0x294804 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x2ec>
 *   @0x294814 ldr r3, [pc, #0x1d0]
 *   @0x294818 ldr r10, [r4, r3]
 *   @0x29481c ldr r6, [r10, #0x4]
 *   @0x294820 cmp r6, #0
 *   @0x294824 lslge r5, r6, #3
 *   @0x294828 movge r7, #0
 *   @0x29482c blt 0x29458c <Java_com_yoyogames_runner_RunnerJNILib_Process+0x74>
 *   @0x294830 ldr r3, [r10]
 *   @0x294834 add r2, r3, r5
 *   @0x294838 ldr r8, [r3, r5]
 *   @0x29483c str r7, [r3, r5]
 *   @0x294840 cmp r8, #0
 *   @0x294844 str r7, [r2, #0x4]
 *   @0x294848 beq 0x294878 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x360>
 *   @0x29484c ldr r11, [r8, #0x4]
 *   @0x294850 ldr r0, [r8, #0xc]
 *   @0x294854 bl 0x27d1d0 <_ZdlPv>
 *   @0x294858 mov r0, r8
 *   @0x29485c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x294860 ldr r3, [r10, #0x8]
 *   @0x294864 cmp r11, #0
 *   @0x294868 mov r8, r11
 *   @0x29486c sub r3, r3, #1
 *   @0x294870 str r3, [r10, #0x8]
 *   @0x294874 bne 0x29484c <Java_com_yoyogames_runner_RunnerJNILib_Process+0x334>
 *   @0x294878 sub r6, r6, #1
 *   @0x29487c sub r5, r5, #8
 *   @0x294880 cmn r6, #1
 *   @0x294884 bne 0x294830 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x318>
 *   @0x294888 ldr r2, [sp, #0xc]
 *   @0x29488c ldr r3, [r2]
 *   @0x294890 b 0x294584 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x6c>
 *   @0x294894 bl 0x1d1b38 <_Z11Run_EndGamev>
 *   @0x294898 bl 0x2a16bc <_Z9EndOfGamev>
 *   @0x29489c bl 0x28fe4c <_Z9Terminatev>
 *   @0x2948a0 bl 0x2a27fc <_Z4Quitv>
 *   @0x2948a4 bl 0x2a2c3c <_Z7RunGamev>
 *   @0x2948a8 bl 0x1cba6c <_Z19FINALIZE_Run_Globalv>
 *   @0x2948ac ldr r3, [pc, #0x13c]
 *   @0x2948b0 ldr r3, [r4, r3]
 *   @0x2948b4 strb r8, [r3]
 *   @0x2948b8 b 0x2947a0 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x288>
 *   @0x2948bc bl 0x2903f8 <_Z13DoFrameTimingv>
 *   @0x2948c0 b 0x29478c <Java_com_yoyogames_runner_RunnerJNILib_Process+0x274>
 *   @0x2948c4 ldr r3, [r5]
 *   @0x2948c8 mov r0, #3008
 *   @0x2948cc blx r3
 *   @0x2948d0 ldr r3, [r5]
 *   @0x2948d4 mov r0, #2912
 *   @0x2948d8 blx r3
 *   @0x2948dc ldr r3, [r5]
 *   @0x2948e0 mov r0, #2896
 *   @0x2948e4 blx r3
 *   @0x2948e8 b 0x2945f8 <Java_com_yoyogames_runner_RunnerJNILib_Process+0xe0>
 *   @0x2948ec bl 0x182d50 <_Z20ResetCurrentTexturesv>
 *   @0x2948f0 b 0x294624 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x10c>
 *   @0x2948f4 bl 0x17daa8 <_Z22InvalidateOGLResourcesv>
 *   @0x2948f8 bl 0x17da94 <_Z16InitOGLResourcesv>
 *   @0x2948fc ldr r3, [pc, #0xe8]
 *   @0x294900 ldr r10, [r4, r3]
 *   @0x294904 ldr r6, [r10, #0x4]
 *   @0x294908 cmp r6, #0
 *   @0x29490c blt 0x29458c <Java_com_yoyogames_runner_RunnerJNILib_Process+0x74>
 *   @0x294910 lsl r5, r6, #3
 *   @0x294914 mov r8, #0
 *   @0x294918 ldr r3, [r10]
 *   @0x29491c add r2, r3, r5
 *   @0x294920 ldr r7, [r3, r5]
 *   @0x294924 str r8, [r3, r5]
 *   @0x294928 cmp r7, #0
 *   @0x29492c str r8, [r2, #0x4]
 *   @0x294930 beq 0x294960 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x448>
 *   @0x294934 ldr r11, [r7, #0x4]
 *   @0x294938 ldr r0, [r7, #0xc]
 *   @0x29493c bl 0x27d1d0 <_ZdlPv>
 *   @0x294940 mov r0, r7
 *   @0x294944 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x294948 ldr r3, [r10, #0x8]
 *   @0x29494c cmp r11, #0
 *   @0x294950 mov r7, r11
 *   @0x294954 sub r3, r3, #1
 *   @0x294958 str r3, [r10, #0x8]
 *   @0x29495c bne 0x294934 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x41c>
 *   @0x294960 sub r6, r6, #1
 *   @0x294964 sub r5, r5, #8
 *   @0x294968 cmn r6, #1
 *   @0x29496c bne 0x294918 <Java_com_yoyogames_runner_RunnerJNILib_Process+0x400>
 *   @0x294970 b 0x29458c <Java_com_yoyogames_runner_RunnerJNILib_Process+0x74>
 *   @0x294974 andseq sp, r5, r12, lsl r7
 *   @0x294978 .word 0xffffef5c
 *   @0x29497c .word 0xfffffcec
 *   @0x294980 .word 0xffffe7b8
 *   @0x294984 .word 0xffffbae8
 *   @0x294988 .word 0xffffbad0
 *   @0x29498c .word 0xffffbaec
 *   @0x294990 .word 0xffffe90c
 *   @0x294994 .word 0xffffbd54
 *   @0x294998 .word 0xfffffd0c
 *   @0x29499c .word 0xffffdee4
 *   @0x2949a0 .word 0xffffdeec
 *   @0x2949a4 .word 0xffffef54
 *   @0x2949a8 .word 0xffffdef0
 *   @0x2949ac .word 0xffffdee8
 *   @0x2949b0 .word 0xfffffcf4
 *   @0x2949b4 .word 0xffffe21c
 *   @0x2949b8 .word 0xffffe9c4
 *   @0x2949bc ldrdeq r2, r3, [r12], #-76
 *   @0x2949c0 .word 0xffffbae4
 *   @0x2949c4 .word 0xffffbaf0
 *   @0x2949c8 .word 0xffffe6b8
 *   @0x2949cc .word 0xffffe24c
 *   @0x2949d0 .word 0xffffe6c0
 *   @0x2949d4 .word 0xffffe250
 *   @0x2949d8 .word 0xffffc960
 *   @0x2949dc .word 0xffffeebc
 *   @0x2949e0 .word 0xffffe778
 *   @0x2949e4 .word 0xfffffcf0
 *   @0x2949e8 .word 0xffffe664
 *   @0x2949ec .word 0xffffbec0
 *   @0x2949f0 .word 0xffffdefc
 *
 * ══ §21/23 Header_Load(unsigned char*, unsigned int, unsigned char*)  0x1dcf94  size 1240  303 条（0x1dcf94..0x1dd46c）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1dcf94 0x1dd46c  size 1240  303 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1dcfa4→0x544bcc, 0x1dcfac→0x544bd0, 0x1dcfb8→0x542974, 0x1dcfc8→0x542964, 0x1dd01c→0x3f5228, 0x1dd024→0x3f5224, 0x1dd030→0x3f5220, 0x1dd03c→0x757f10
 * 调用序列: Room_Set_maxid(int) / Room_Set_maxtileid(int) / Header_Load(unsigned char*, unsigned int, unsigned char*)+0xd0 / Room_LoadOrder(YYHeader*, int) / Header_Load(unsigned char*, unsigned int, unsigned char*)+0x464 / CTimingSource::SetFrameRate(double) / INITIALIZE_JavaScript()
 * 字段偏移 top8: 0x18×7 / 0x8×6 / 0x14×5 / 0xc×4 / 0x1c×3 / 0x4×3 / 0x10×3 / 0x20×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dcf94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1dcf98 sub sp, sp, #52
 *   @0x1dcf9c ldr r6, [pc, #0x47c]
 *   @0x1dcfa0 mov r7, r0
 *   @0x1dcfa4 ldr r2, [pc, #0x478]
 *   @0x1dcfa8 add r6, pc, r6
 *   @0x1dcfac ldr r3, [pc, #0x474]
 *   @0x1dcfb0 ldrb r4, [r0, #0x1]
 *   @0x1dcfb4 ldr r9, [r6, r2]
 *   @0x1dcfb8 ldr r1, [pc, #0x46c]
 *   @0x1dcfbc ldr r2, [r0, #0x14]
 *   @0x1dcfc0 str r0, [r9]
 *   @0x1dcfc4 ldr r8, [r6, r3]
 *   @0x1dcfc8 ldr r3, [pc, #0x460]
 *   @0x1dcfcc ldr lr, [r0, #0x18]
 *   @0x1dcfd0 str r4, [r8]
 *   @0x1dcfd4 ldr r1, [r6, r1]
 *   @0x1dcfd8 ldr r12, [r0, #0x1c]
 *   @0x1dcfdc str r1, [sp, #0x8]
 *   @0x1dcfe0 ldr r5, [sp, #0x8]
 *   @0x1dcfe4 ldr r1, [r0, #0x20]
 *   @0x1dcfe8 str r2, [r5]
 *   @0x1dcfec ldr r2, [r0, #0x24]
 *   @0x1dcff0 ldr r3, [r6, r3]
 *   @0x1dcff4 ldr r0, [r0, #0xc]
 *   @0x1dcff8 str lr, [r3]
 *   @0x1dcffc str r12, [r3, #0x4]
 *   @0x1dd000 str r1, [r3, #0x8]
 *   @0x1dd004 str r2, [r3, #0xc]
 *   @0x1dd008 bl 0x1b5e18 <_Z14Room_Set_maxidi>
 *   @0x1dd00c ldr r0, [r7, #0x10]
 *   @0x1dd010 bl 0x1b5e40 <_Z18Room_Set_maxtileidi>
 *   @0x1dd014 cmp r4, #7
 *   @0x1dd018 ble 0x1dd064 <_Z11Header_LoadPhjS_+0xd0>
 *   @0x1dd01c ldr r3, [pc, #0x410]
 *   @0x1dd020 ldr r0, [r7, #0x3c]
 *   @0x1dd024 ldr r2, [pc, #0x40c]
 *   @0x1dd028 ldr r1, [r6, r3]
 *   @0x1dd02c ldr r12, [r7, #0x40]
 *   @0x1dd030 ldr r3, [pc, #0x404]
 *   @0x1dd034 str r0, [r1]
 *   @0x1dd038 ldr r0, [r6, r2]
 *   @0x1dd03c ldr r1, [pc, #0x3fc]
 *   @0x1dd040 ldr r2, [r7, #0x44]
 *   @0x1dd044 str r12, [r0]
 *   @0x1dd048 ldr r3, [r6, r3]
 *   @0x1dd04c str r2, [r3]
 *   @0x1dd050 ldr r1, [r6, r1]
 *   @0x1dd054 ldrb r1, [r1]
 *   @0x1dd058 cmp r1, #0
 *   @0x1dd05c bicne r2, r2, #1
 *   @0x1dd060 strne r2, [r3]
 *   @0x1dd064 ldr r4, [r9]
 *   @0x1dd068 ldr r2, [pc, #0x3d4]
 *   @0x1dd06c ldr r11, [pc, #0x3d4]
 *   @0x1dd070 mov r3, r4
 *   @0x1dd074 ldr r10, [r4, #0x48]
 *   @0x1dd078 ldr r0, [r3, #0x4c]!
 *   @0x1dd07c ldr r12, [r6, r2]
 *   @0x1dd080 ldr lr, [pc, #0x3c4]
 *   @0x1dd084 ldr r1, [r3, #0x4]
 *   @0x1dd088 ldr r2, [r3, #0x8]
 *   @0x1dd08c ldr r3, [r3, #0xc]
 *   @0x1dd090 ldrd r4, r5, [r4, #92]
 *   @0x1dd094 stm r12!, {r0, r1, r2, r3}
 *   @0x1dd098 mov r0, r7
 *   @0x1dd09c ldr r3, [r6, r11]
 *   @0x1dd0a0 ldr r1, [r8]
 *   @0x1dd0a4 str r10, [r3]
 *   @0x1dd0a8 ldr r7, [r6, lr]
 *   @0x1dd0ac strd r4, r5, [r7]
 *   @0x1dd0b0 bl 0x1b5ba0 <_Z14Room_LoadOrderP8YYHeaderi>
 *   @0x1dd0b4 ldr r2, [pc, #0x394]
 *   @0x1dd0b8 mov r1, #1
 *   @0x1dd0bc ldr r3, [pc, #0x390]
 *   @0x1dd0c0 ldr r2, [r6, r2]
 *   @0x1dd0c4 strb r1, [r2]
 *   @0x1dd0c8 ldr r3, [r6, r3]
 *   @0x1dd0cc ldrb r3, [r3]
 *   @0x1dd0d0 cmp r3, #0
 *   @0x1dd0d4 bne 0x1dd418 <_Z11Header_LoadPhjS_+0x484>
 *   @0x1dd0d8 ldr r12, [r8]
 *   @0x1dd0f8 ldrd r10, r11, [r7]
 *   @0x1dd0fc movw r8, #0x2493
 *   @0x1dd100 movt r8, #0x9249
 *   @0x1dd104 ldr r3, [r9]
 *   @0x1dd108 strd r10, r11, [sp, #32]
 *   @0x1dd10c add lr, r3, #132
 *   @0x1dd110 ldr r11, [sp, #0x8]
 *   @0x1dd114 ldrh r2, [sp, #32]
 *   @0x1dd118 ldr r1, [r3, #0x3c]
 *   @0x1dd11c ldr r5, [r11]
 *   @0x1dd120 smull r11, r8, r8, r2
 *   @0x1dd124 ldr r0, [r3, #0x40]
 *   @0x1dd128 rsb r7, r1, r5
 *   @0x1dd12c ldr r4, [r3, #0x80]
 *   @0x1dd130 add r8, r8, r2
 *   @0x1dd134 ldr r2, [r3, #0x44]
 *   @0x1dd138 str r5, [sp, #0xc]
 *   @0x1dd13c add r0, r2, r0
 *   @0x1dd140 add r9, r7, r8, asr #2
 *   @0x1dd144 add r9, r4, r9
 *   @0x1dd148 add r1, r1, r2
 *   @0x1dd14c asr r3, r0, #31
 *   @0x1dd150 cmp r9, #0
 *   @0x1dd154 rsblt r9, r9, #0
 *   @0x1dd158 lsl r4, r4, #2
 *   @0x1dd15c and r9, r9, #3
 *   @0x1dd160 str r0, [sp, #0x14]
 *   @0x1dd164 add r8, r4, lr
 *   @0x1dd168 mov r7, #0
 *   @0x1dd16c lsl r11, r3, #16
 *   @0x1dd170 str r7, [sp, #0x28]
 *   @0x1dd174 lsl r3, r1, #16
 *   @0x1dd178 str r7, [sp, #0x10]
 *   @0x1dd17c orr r11, r11, r0, lsr #16
 *   @0x1dd180 str r3, [sp, #0x2c]
 *   @0x1dd184 add r10, r8, r9, lsl #3
 *   @0x1dd188 ldrd r2, r3, [sp, #16]
 *   @0x1dd18c lsl r0, r0, #16
 *   @0x1dd190 str r10, [sp, #0x18]
 *   @0x1dd194 str r11, [sp, #0x4]
 *   @0x1dd198 ldrd r10, r11, [sp, #40]
 *   @0x1dd19c str r7, [sp, #0x8]
 *   @0x1dd1a0 orr r11, r11, r3
 *   @0x1dd1a4 ldr r3, [sp, #0x18]
 *   @0x1dd1a8 orr r10, r10, r2
 *   @0x1dd1ac str r0, [sp]
 *   @0x1dd1b0 orr r10, r10, r1
 *   @0x1dd1b4 orr r11, r11, r1, asr #31
 *   @0x1dd1b8 ldrd r2, r3, [r3, #8]
 *   @0x1dd1bc ldrd r0, r1, [sp, #8]
 *   @0x1dd1c0 strd r2, r3, [sp, #40]
 *   @0x1dd1c4 orr r0, r0, r5
 *   @0x1dd1c8 ldrd r2, r3, [sp]
 *   @0x1dd1cc orr r1, r1, r5, asr #31
 *   @0x1dd1d0 eor r0, r0, r12
 *   @0x1dd1d4 eor r1, r1, r12, asr #31
 *   @0x1dd1d8 orr r2, r2, r10
 *   @0x1dd1dc orr r3, r3, r11
 *   @0x1dd1e0 eor r5, r1, r3
 *   @0x1dd1e4 ldrd r10, r11, [r4, lr]
 *   @0x1dd1e8 eor r4, r0, r2
 *   @0x1dd1ec ldrd r2, r3, [sp, #40]
 *   @0x1dd1f0 mov r0, #0
 *   @0x1dd1f4 mov r1, #0
 *   @0x1dd1f8 eor r5, r5, r3
 *   @0x1dd1fc strd r0, r1, [sp, #16]
 *   @0x1dd200 ldrd r0, r1, [sp, #32]
 *   @0x1dd204 eor r4, r4, r2
 *   @0x1dd208 mvn r5, r5
 *   @0x1dd20c eor r5, r5, r11
 *   @0x1dd210 mvn r4, r4
 *   @0x1dd214 eor r4, r4, r10
 *   @0x1dd218 mvn r0, r0
 *   @0x1dd21c mvn r1, r1
 *   @0x1dd220 strd r0, r1, [sp, #32]
 *   @0x1dd224 lsl r1, r5, #16
 *   @0x1dd228 str r1, [sp, #0x14]
 *   @0x1dd22c lsl r3, r4, #16
 *   @0x1dd230 ldr r2, [sp, #0x14]
 *   @0x1dd234 lsl r1, r5, #8
 *   @0x1dd238 mov r10, #0
 *   @0x1dd23c mov r11, #16711680
 *   @0x1dd240 orr r2, r2, r4, lsr #16
 *   @0x1dd244 str r2, [sp, #0x14]
 *   @0x1dd248 str r3, [sp, #0x10]
 *   @0x1dd24c orr r1, r1, r4, lsr #24
 *   @0x1dd250 ldrd r2, r3, [sp, #16]
 *   @0x1dd254 lsl r0, r4, #8
 *   @0x1dd258 lsl r7, r5, #24
 *   @0x1dd25c and r10, r10, r2
 *   @0x1dd260 and r11, r11, r3
 *   @0x1dd264 strd r10, r11, [sp]
 *   @0x1dd268 mov r10, #0
 *   @0x1dd26c ldrd r2, r3, [sp]
 *   @0x1dd270 and r0, r0, r10
 *   @0x1dd274 mov r11, #-16777216
 *   @0x1dd278 and r1, r1, r11
 *   @0x1dd27c orr r2, r2, r0
 *   @0x1dd280 orr r3, r3, r1
 *   @0x1dd284 strd r2, r3, [sp]
 *   @0x1dd288 lsl r3, r4, #24
 *   @0x1dd28c str r3, [sp, #0x18]
 *   @0x1dd290 orr r12, r7, r4, lsr #8
 *   @0x1dd294 ldrd r2, r3, [sp]
 *   @0x1dd298 lsr r10, r5, #24
 *   @0x1dd29c str r12, [sp, #0x1c]
 *   @0x1dd2a0 mov r11, #0
 *   @0x1dd2a4 orr r2, r2, r10
 *   @0x1dd2a8 orr r3, r3, r11
 *   @0x1dd2ac strd r2, r3, [sp]
 *   @0x1dd2b0 mov r10, #0
 *   @0x1dd2b4 ldrd r2, r3, [sp, #24]
 *   @0x1dd2b8 mov r11, #65280
 *   @0x1dd2bc mov r0, #0
 *   @0x1dd2c0 ldr r12, [pc, #0x194]
 *   @0x1dd2c4 and r10, r10, r2
 *   @0x1dd2c8 and r11, r11, r3
 *   @0x1dd2cc mov r2, #0
 *   @0x1dd2d0 mov r3, #0
 *   @0x1dd2d4 strd r2, r3, [sp, #24]
 *   @0x1dd2d8 mov r1, #0
 *   @0x1dd2dc ldrd r2, r3, [sp]
 *   @0x1dd2e0 orr r10, r10, r2
 *   @0x1dd2e4 orr r11, r11, r3
 *   @0x1dd2e8 mov r2, #0
 *   @0x1dd2ec lsr r3, r4, #8
 *   @0x1dd2f0 and r2, r2, r0
 *   @0x1dd2f4 str r3, [sp, #0x18]
 *   @0x1dd2f8 mov r3, #255
 *   @0x1dd2fc and r3, r3, r4
 *   @0x1dd300 orr r2, r2, r10
 *   @0x1dd304 orr r3, r3, r11
 *   @0x1dd308 ldr r7, [sp, #0x18]
 *   @0x1dd30c mov r0, #-16777216
 *   @0x1dd310 ldrd r10, r11, [sp, #16]
 *   @0x1dd314 orr r7, r7, r5, lsl #24
 *   @0x1dd318 str r7, [sp, #0x18]
 *   @0x1dd31c and r1, r1, r11
 *   @0x1dd320 and r0, r0, r10
 *   @0x1dd324 asr r11, r5, #8
 *   @0x1dd328 str r11, [sp, #0x1c]
 *   @0x1dd32c orr r10, r2, r0
 *   @0x1dd330 orr r11, r3, r1
 *   @0x1dd334 ldr lr, [r6, r12]
 *   @0x1dd338 mov r0, #16711680
 *   @0x1dd33c ldrd r2, r3, [sp, #24]
 *   @0x1dd340 mov r1, #0
 *   @0x1dd344 strd r10, r11, [sp, #16]
 *   @0x1dd348 mov r10, r5
 *   @0x1dd34c asr r11, r5, #31
 *   @0x1dd350 ldrd r4, r5, [sp, #16]
 *   @0x1dd354 and r0, r0, r2
 *   @0x1dd358 and r1, r1, r3
 *   @0x1dd35c orr r0, r0, r4
 *   @0x1dd360 orr r1, r1, r5
 *   @0x1dd364 mov r2, #65280
 *   @0x1dd368 mov r3, #0
 *   @0x1dd36c and r2, r2, r10
 *   @0x1dd370 and r3, r3, r11
 *   @0x1dd374 orr r2, r2, r0
 *   @0x1dd378 orr r3, r3, r1
 *   @0x1dd37c ldrd r10, r11, [sp, #32]
 *   @0x1dd380 mov r12, #0
 *   @0x1dd384 ldrd r0, r1, [sp, #40]
 *   @0x1dd388 mov r4, r8
 *   @0x1dd38c strd r2, r3, [lr]
 *   @0x1dd390 cmp r12, r9
 *   @0x1dd394 add r12, r12, #1
 *   @0x1dd398 beq 0x1dd3ac <_Z11Header_LoadPhjS_+0x418>
 *   @0x1dd39c ldrd r2, r3, [r4, #8]
 *   @0x1dd3a0 cmp r3, r1
 *   @0x1dd3a4 cmpeq r2, r0
 *   @0x1dd3a8 strdeq r10, r11, [lr]
 *   @0x1dd3ac cmp r12, #4
 *   @0x1dd3b0 add r4, r4, #8
 *   @0x1dd3b4 bne 0x1dd390 <_Z11Header_LoadPhjS_+0x3fc>
 *   @0x1dd3b8 vldr s14, [r8, #40]
 *   @0x1dd3bc vcvt.f64.f32 d7, s14
 *   @0x1dd3c0 ldr r1, [pc, #0x98]
 *   @0x1dd3c4 add r8, r8, #40
 *   @0x1dd3c8 ldr r3, [pc, #0x94]
 *   @0x1dd3cc ldr r2, [pc, #0x94]
 *   @0x1dd3d0 ldr r1, [r6, r1]
 *   @0x1dd3d4 str r8, [r1]
 *   @0x1dd3d8 ldr r2, [r6, r2]
 *   @0x1dd3dc vstr d7, [r2]
 *   @0x1dd3e0 ldr r0, [r6, r3]
 *   @0x1dd3e4 vmov r2, r3, d7
 *   @0x1dd3e8 bl 0x214800 <_ZN13CTimingSource12SetFrameRateEd>
 *   @0x1dd3ec mov r0, #1
 *   @0x1dd3f0 add sp, sp, #52
 *   @0x1dd3f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1dd3f8 ldr r1, [pc, #0x5c]
 *   @0x1dd3fc mov r2, #0
 *   @0x1dd400 mov r3, #0
 *   @0x1dd404 mov r0, #1
 *   @0x1dd408 ldr r1, [r6, r1]
 *   @0x1dd40c strd r2, r3, [r1]
 *   @0x1dd410 add sp, sp, #52
 *   @0x1dd414 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1dd418 bl 0x246fa8 <_Z21INITIALIZE_JavaScriptv>
 *   @0x1dd41c b 0x1dd0d8 <_Z11Header_LoadPhjS_+0x144>
 *   @0x1dd420 eoreq r4, r1, r8, lsr #25
 *   @0x1dd424 .word 0xffffe79c
 *   @0x1dd428 .word 0xffffea88
 *   @0x1dd42c .word 0xffffeec4
 *   @0x1dd430 .word 0xffffeed4
 *   @0x1dd434 .word 0xfffff05c
 *   @0x1dd438 .word 0xfffff060
 *   @0x1dd43c .word 0xfffff064
 *   @0x1dd440 .word 0xffffeb04
 *   @0x1dd444 .word 0xffffef14
 *   @0x1dd448 .word 0xfffff068
 *   @0x1dd44c .word 0xffffef0c
 *   @0x1dd450 .word 0xfffff06c
 *   @0x1dd454 .word 0xffffbf68
 *   @0x1dd458 .word 0xffffbcd4
 *   @0x1dd45c .word 0xffffef08
 *   @0x1dd460 .word 0xffffef04
 *   @0x1dd464 .word 0xffffbcdc
 *   @0x1dd468 .word 0xffffebc4
 *
 * ══ §22/23 JS_ResourceSetup()  0x23f93c  size 1240  310 条（0x23f93c..0x23fe14）
 * @func 0x23f93c 0x23fe14  size 1240  310 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::Add(char const*, RValue&, int)×11 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / Object_Exists(int) / Object_Name(int) / JS_ResourceSetup()+0x74 / Sprite_Number() / Sprite_Exists(int) / Sprite_Name(int)
 * 字段偏移 top8: 0x24×12 / 0x4b4×1 / 0x10×1 / 0x14×1 / 0x8×1 / 0xa4×1 / 0x4×1 / 0x28×1
 * VFP 指令 33 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23f93c push {r4, r5, r6, r7, r8, lr}
 *   @0x23f940 sub sp, sp, #40
 *   @0x23f944 mov r7, #0
 *   @0x23f948 ldr r6, [pc, #0x4b4]
 *   @0x23f94c mov r3, r7
 *   @0x23f950 str r7, [sp]
 *   @0x23f954 mov r1, r7
 *   @0x23f958 mov r2, r7
 *   @0x23f95c add r0, sp, #8
 *   @0x23f960 mov r4, #0
 *   @0x23f964 str r7, [sp, #0x10]
 *   @0x23f968 mov r5, #0
 *   @0x23f96c mvn r12, #-16777216
 *   @0x23f970 strd r4, r5, [sp, #8]
 *   @0x23f974 str r12, [sp, #0x14]
 *   @0x23f978 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x23f97c ldr r6, [pc, r6]
 *   @0x23f980 ldr r5, [sp, #0x8]
 *   @0x23f984 ldr r3, [r6]
 *   @0x23f988 cmp r3, r7
 *   @0x23f98c addgt r8, sp, #24
 *   @0x23f990 movgt r4, r7
 *   @0x23f994 movgt r7, r4
 *   @0x23f998 bgt 0x23f9b0 <_Z16JS_ResourceSetupv+0x74>
 *   @0x23f99c b 0x23f9fc <_Z16JS_ResourceSetupv+0xc0>
 *   @0x23f9a0 ldr r3, [r6]
 *   @0x23f9a4 add r4, r4, #1
 *   @0x23f9a8 cmp r4, r3
 *   @0x23f9ac bge 0x23f9fc <_Z16JS_ResourceSetupv+0xc0>
 *   @0x23f9b0 mov r0, r4
 *   @0x23f9b4 bl 0x19ecf8 <_Z13Object_Existsi>
 *   @0x23f9b8 cmp r0, #0
 *   @0x23f9bc beq 0x23f9a0 <_Z16JS_ResourceSetupv+0x64>
 *   @0x23f9c0 vmov s13, r4
 *   @0x23f9c4 mov r0, r4
 *   @0x23f9c8 str r7, [sp, #0x24]
 *   @0x23f9cc add r4, r4, #1
 *   @0x23f9d0 vcvt.f64.s32 d7, s13
 *   @0x23f9d4 vstr d7, [sp, #24]
 *   @0x23f9d8 bl 0x19ed54 <_Z11Object_Namei>
 *   @0x23f9dc mov r3, #1
 *   @0x23f9e0 mov r2, r8
 *   @0x23f9e4 mov r1, r0
 *   @0x23f9e8 mov r0, r5
 *   @0x23f9ec bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x23f9f0 ldr r3, [r6]
 *   @0x23f9f4 cmp r4, r3
 *   @0x23f9f8 blt 0x23f9b0 <_Z16JS_ResourceSetupv+0x74>
 *   @0x23f9fc mov r4, #0
 *   @0x23fa00 add r7, sp, #24
 *   @0x23fa04 mov r6, r4
 *   @0x23fa08 b 0x23fa10 <_Z16JS_ResourceSetupv+0xd4>
 *   @0x23fa0c add r4, r4, #1
 *   @0x23fa10 bl 0x1eee84 <_Z13Sprite_Numberv>
 *   @0x23fa14 cmp r4, r0
 *   @0x23fa18 mov r0, r4
 *   @0x23fa1c bge 0x23fa5c <_Z16JS_ResourceSetupv+0x120>
 *   @0x23fa20 bl 0x1eee98 <_Z13Sprite_Existsi>
 *   @0x23fa24 cmp r0, #0
 *   @0x23fa28 beq 0x23fa0c <_Z16JS_ResourceSetupv+0xd0>
 *   @0x23fa2c vmov s13, r4
 *   @0x23fa30 mov r0, r4
 *   @0x23fa34 str r6, [sp, #0x24]
 *   @0x23fa38 vcvt.f64.s32 d7, s13
 *   @0x23fa3c vstr d7, [sp, #24]
 *   @0x23fa40 bl 0x1eeee0 <_Z11Sprite_Namei>
 *   @0x23fa44 mov r2, r7
 *   @0x23fa48 mov r3, #1
 *   @0x23fa4c mov r1, r0
 *   @0x23fa50 mov r0, r5
 *   @0x23fa54 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x23fa58 b 0x23fa0c <_Z16JS_ResourceSetupv+0xd0>
 *   @0x23fa5c mov r4, #0
 *   @0x23fa60 add r7, sp, #24
 *   @0x23fa64 mov r6, r4
 *   @0x23fa68 b 0x23fa70 <_Z16JS_ResourceSetupv+0x134>
 *   @0x23fa6c add r4, r4, #1
 *   @0x23fa70 bl 0x21fb6c <_Z12Sound_Numberv>
 *   @0x23fa74 cmp r4, r0
 *   @0x23fa78 mov r0, r4
 *   @0x23fa7c bge 0x23fabc <_Z16JS_ResourceSetupv+0x180>
 *   @0x23fa80 bl 0x21fbd0 <_Z12Sound_Existsi>
 *   @0x23fa84 cmp r0, #0
 *   @0x23fa88 beq 0x23fa6c <_Z16JS_ResourceSetupv+0x130>
 *   @0x23fa8c vmov s13, r4
 *   @0x23fa90 mov r0, r4
 *   @0x23fa94 str r6, [sp, #0x24]
 *   @0x23fa98 vcvt.f64.s32 d7, s13
 *   @0x23fa9c vstr d7, [sp, #24]
 *   @0x23faa0 bl 0x21fc18 <_Z10Sound_Namei>
 *   @0x23faa4 mov r2, r7
 *   @0x23faa8 mov r3, #1
 *   @0x23faac mov r1, r0
 *   @0x23fab0 mov r0, r5
 *   @0x23fab4 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x23fab8 b 0x23fa6c <_Z16JS_ResourceSetupv+0x130>
 *   @0x23fabc mov r4, #0
 *   @0x23fac0 add r7, sp, #24
 *   @0x23fac4 mov r6, r4
 *   @0x23fac8 b 0x23fad0 <_Z16JS_ResourceSetupv+0x194>
 *   @0x23facc add r4, r4, #1
 *   @0x23fad0 bl 0x2172f8 <_Z12Audio_Numberv>
 *   @0x23fad4 cmp r4, r0
 *   @0x23fad8 mov r0, r4
 *   @0x23fadc bge 0x23fb1c <_Z16JS_ResourceSetupv+0x1e0>
 *   @0x23fae0 bl 0x217260 <_Z12Audio_Existsi>
 *   @0x23fae4 cmp r0, #0
 *   @0x23fae8 beq 0x23facc <_Z16JS_ResourceSetupv+0x190>
 *   @0x23faec vmov s13, r4
 *   @0x23faf0 mov r0, r4
 *   @0x23faf4 str r6, [sp, #0x24]
 *   @0x23faf8 vcvt.f64.s32 d7, s13
 *   @0x23fafc vstr d7, [sp, #24]
 *   @0x23fb00 bl 0x21730c <_Z10Audio_Namei>
 *   @0x23fb04 mov r2, r7
 *   @0x23fb08 mov r3, #1
 *   @0x23fb0c mov r1, r0
 *   @0x23fb10 mov r0, r5
 *   @0x23fb14 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x23fb18 b 0x23facc <_Z16JS_ResourceSetupv+0x190>
 *   @0x23fb1c mov r4, #0
 *   @0x23fb20 add r7, sp, #24
 *   @0x23fb24 mov r6, r4
 *   @0x23fb28 b 0x23fb30 <_Z16JS_ResourceSetupv+0x1f4>
 *   @0x23fb2c add r4, r4, #1
 *   @0x23fb30 bl 0xc362c <_Z17Background_Numberv>
 *   @0x23fb34 cmp r4, r0
 *   @0x23fb38 mov r0, r4
 *   @0x23fb3c bge 0x23fb7c <_Z16JS_ResourceSetupv+0x240>
 *   @0x23fb40 bl 0xc3640 <_Z17Background_Existsi>
 *   @0x23fb44 cmp r0, #0
 *   @0x23fb48 beq 0x23fb2c <_Z16JS_ResourceSetupv+0x1f0>
 *   @0x23fb4c vmov s13, r4
 *   @0x23fb50 mov r0, r4
 *   @0x23fb54 str r6, [sp, #0x24]
 *   @0x23fb58 vcvt.f64.s32 d7, s13
 *   @0x23fb5c vstr d7, [sp, #24]
 *   @0x23fb60 bl 0xc3688 <_Z15Background_Namei>
 *   @0x23fb64 mov r2, r7
 *   @0x23fb68 mov r3, #1
 *   @0x23fb6c mov r1, r0
 *   @0x23fb70 mov r0, r5
 *   @0x23fb74 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x23fb78 b 0x23fb2c <_Z16JS_ResourceSetupv+0x1f0>
 *   @0x23fb7c mov r4, #0
 *   @0x23fb80 add r7, sp, #24
 *   @0x23fb84 mov r6, r4
 *   @0x23fb88 b 0x23fb90 <_Z16JS_ResourceSetupv+0x254>
 *   @0x23fb8c add r4, r4, #1
 *   @0x23fb90 bl 0x1a7ff4 <_Z11Path_Numberv>
 *   @0x23fb94 cmp r4, r0
 *   @0x23fb98 mov r0, r4
 *   @0x23fb9c bge 0x23fbdc <_Z16JS_ResourceSetupv+0x2a0>
 *   @0x23fba0 bl 0x1a8008 <_Z11Path_Existsi>
 *   @0x23fba4 cmp r0, #0
 *   @0x23fba8 beq 0x23fb8c <_Z16JS_ResourceSetupv+0x250>
 *   @0x23fbac vmov s13, r4
 *   @0x23fbb0 mov r0, r4
 *   @0x23fbb4 str r6, [sp, #0x24]
 *   @0x23fbb8 vcvt.f64.s32 d7, s13
 *   @0x23fbbc vstr d7, [sp, #24]
 *   @0x23fbc0 bl 0x1a8050 <_Z9Path_Namei>
 *   @0x23fbc4 mov r2, r7
 *   @0x23fbc8 mov r3, #1
 *   @0x23fbcc mov r1, r0
 *   @0x23fbd0 mov r0, r5
 *   @0x23fbd4 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x23fbd8 b 0x23fb8c <_Z16JS_ResourceSetupv+0x250>
 *   @0x23fbdc mov r4, #0
 *   @0x23fbe0 add r7, sp, #24
 *   @0x23fbe4 mov r6, r4
 *   @0x23fbe8 b 0x23fbf0 <_Z16JS_ResourceSetupv+0x2b4>
 *   @0x23fbec add r4, r4, #1
 *   @0x23fbf0 bl 0xfa294 <_Z11Font_Numberv>
 *   @0x23fbf4 cmp r4, r0
 *   @0x23fbf8 mov r0, r4
 *   @0x23fbfc bge 0x23fc3c <_Z16JS_ResourceSetupv+0x300>
 *   @0x23fc00 bl 0xfa2a8 <_Z11Font_Existsi>
 *   @0x23fc04 cmp r0, #0
 *   @0x23fc08 beq 0x23fbec <_Z16JS_ResourceSetupv+0x2b0>
 *   @0x23fc0c vmov s13, r4
 *   @0x23fc10 mov r0, r4
 *   @0x23fc14 str r6, [sp, #0x24]
 *   @0x23fc18 vcvt.f64.s32 d7, s13
 *   @0x23fc1c vstr d7, [sp, #24]
 *   @0x23fc20 bl 0xfa2f0 <_Z9Font_Namei>
 *   @0x23fc24 mov r2, r7
 *   @0x23fc28 mov r3, #1
 *   @0x23fc2c mov r1, r0
 *   @0x23fc30 mov r0, r5
 *   @0x23fc34 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x23fc38 b 0x23fbec <_Z16JS_ResourceSetupv+0x2b0>
 *   @0x23fc3c mov r4, #0
 *   @0x23fc40 add r7, sp, #24
 *   @0x23fc44 mov r6, r4
 *   @0x23fc48 b 0x23fc50 <_Z16JS_ResourceSetupv+0x314>
 *   @0x23fc4c add r4, r4, #1
 *   @0x23fc50 bl 0x1f2b00 <_Z15TimeLine_Numberv>
 *   @0x23fc54 cmp r4, r0
 *   @0x23fc58 mov r0, r4
 *   @0x23fc5c bge 0x23fc9c <_Z16JS_ResourceSetupv+0x360>
 *   @0x23fc60 bl 0x1f2b18 <_Z15TimeLine_Existsi>
 *   @0x23fc64 cmp r0, #0
 *   @0x23fc68 beq 0x23fc4c <_Z16JS_ResourceSetupv+0x310>
 *   @0x23fc6c vmov s13, r4
 *   @0x23fc70 mov r0, r4
 *   @0x23fc74 str r6, [sp, #0x24]
 *   @0x23fc78 vcvt.f64.s32 d7, s13
 *   @0x23fc7c vstr d7, [sp, #24]
 *   @0x23fc80 bl 0x1f2b58 <_Z13TimeLine_Namei>
 *   @0x23fc84 mov r2, r7
 *   @0x23fc88 mov r3, #1
 *   @0x23fc8c mov r1, r0
 *   @0x23fc90 mov r0, r5
 *   @0x23fc94 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x23fc98 b 0x23fc4c <_Z16JS_ResourceSetupv+0x310>
 *   @0x23fc9c mov r4, #0
 *   @0x23fca0 add r7, sp, #24
 *   @0x23fca4 mov r6, r4
 *   @0x23fca8 b 0x23fcb0 <_Z16JS_ResourceSetupv+0x374>
 *   @0x23fcac add r4, r4, #1
 *   @0x23fcb0 bl 0x1e0530 <_Z13Script_Numberv>
 *   @0x23fcb4 cmp r4, r0
 *   @0x23fcb8 mov r0, r4
 *   @0x23fcbc bge 0x23fcfc <_Z16JS_ResourceSetupv+0x3c0>
 *   @0x23fcc0 bl 0x1e0544 <_Z13Script_Existsi>
 *   @0x23fcc4 cmp r0, #0
 *   @0x23fcc8 beq 0x23fcac <_Z16JS_ResourceSetupv+0x370>
 *   @0x23fccc vmov s13, r4
 *   @0x23fcd0 mov r0, r4
 *   @0x23fcd4 str r6, [sp, #0x24]
 *   @0x23fcd8 vcvt.f64.s32 d7, s13
 *   @0x23fcdc vstr d7, [sp, #24]
 *   @0x23fce0 bl 0x1e058c <_Z11Script_Namei>
 *   @0x23fce4 mov r2, r7
 *   @0x23fce8 mov r3, #1
 *   @0x23fcec mov r1, r0
 *   @0x23fcf0 mov r0, r5
 *   @0x23fcf4 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x23fcf8 b 0x23fcac <_Z16JS_ResourceSetupv+0x370>
 *   @0x23fcfc mov r4, #0
 *   @0x23fd00 add r7, sp, #24
 *   @0x23fd04 mov r6, r4
 *   @0x23fd08 b 0x23fd10 <_Z16JS_ResourceSetupv+0x3d4>
 *   @0x23fd0c add r4, r4, #1
 *   @0x23fd10 bl 0x1b523c <_Z11Room_Numberv>
 *   @0x23fd14 cmp r4, r0
 *   @0x23fd18 mov r0, r4
 *   @0x23fd1c bge 0x23fd5c <_Z16JS_ResourceSetupv+0x420>
 *   @0x23fd20 bl 0x1b52f8 <_Z11Room_Existsi>
 *   @0x23fd24 cmp r0, #0
 *   @0x23fd28 beq 0x23fd0c <_Z16JS_ResourceSetupv+0x3d0>
 *   @0x23fd2c vmov s13, r4
 *   @0x23fd30 mov r0, r4
 *   @0x23fd34 str r6, [sp, #0x24]
 *   @0x23fd38 vcvt.f64.s32 d7, s13
 *   @0x23fd3c vstr d7, [sp, #24]
 *   @0x23fd40 bl 0x1b530c <_Z9Room_Namei>
 *   @0x23fd44 mov r2, r7
 *   @0x23fd48 mov r3, #1
 *   @0x23fd4c mov r1, r0
 *   @0x23fd50 mov r0, r5
 *   @0x23fd54 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x23fd58 b 0x23fd0c <_Z16JS_ResourceSetupv+0x3d0>
 *   @0x23fd5c ldr r6, [pc, #0xa4]
 *   @0x23fd60 ldr r6, [pc, r6]
 *   @0x23fd64 ldr r3, [r6]
 *   @0x23fd68 cmp r3, #0
 *   @0x23fd6c addgt r8, sp, #24
 *   @0x23fd70 movgt r4, #0
 *   @0x23fd74 movgt r7, r4
 *   @0x23fd78 bgt 0x23fd90 <_Z16JS_ResourceSetupv+0x454>
 *   @0x23fd7c b 0x23fddc <_Z16JS_ResourceSetupv+0x4a0>
 *   @0x23fd80 ldr r3, [r6]
 *   @0x23fd84 add r4, r4, #1
 *   @0x23fd88 cmp r3, r4
 *   @0x23fd8c ble 0x23fddc <_Z16JS_ResourceSetupv+0x4a0>
 *   @0x23fd90 mov r0, r4
 *   @0x23fd94 bl 0x1e1294 <_Z12ShaderExistsi>
 *   @0x23fd98 cmp r0, #0
 *   @0x23fd9c beq 0x23fd80 <_Z16JS_ResourceSetupv+0x444>
 *   @0x23fda0 mov r0, r4
 *   @0x23fda4 bl 0x1e1254 <_Z9GetShaderi>
 *   @0x23fda8 vmov s13, r4
 *   @0x23fdac mov r3, #1
 *   @0x23fdb0 mov r2, r8
 *   @0x23fdb4 vcvt.f64.s32 d7, s13
 *   @0x23fdb8 str r7, [sp, #0x24]
 *   @0x23fdbc add r4, r4, #1
 *   @0x23fdc0 vstr d7, [sp, #24]
 *   @0x23fdc4 ldr r1, [r0, #0x4]
 *   @0x23fdc8 mov r0, r5
 *   @0x23fdcc bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x23fdd0 ldr r3, [r6]
 *   @0x23fdd4 cmp r3, r4
 *   @0x23fdd8 bgt 0x23fd90 <_Z16JS_ResourceSetupv+0x454>
 *   @0x23fddc ldr r0, [pc, #0x28]
 *   @0x23fde0 mov r2, r5
 *   @0x23fde4 ldr r1, [pc, #0x24]
 *   @0x23fde8 mov r3, #1
 *   @0x23fdec ldr r0, [pc, r0]
 *   @0x23fdf0 add r1, pc, r1
 *   @0x23fdf4 ldr r0, [r0]
 *   @0x23fdf8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x23fdfc add sp, sp, #40
 *   @0x23fe00 pop {r4, r5, r6, r7, r8, pc}
 *   @0x23fe04 andseq r0, r11, r8, ror #26
 *   @0x23fe08 andseq r0, r11, r4, ror #31
 *   @0x23fe0c andseq sp, r10, r8, asr #27
 *   @0x23fe10 andseq r5, r1, r12, lsl r6
 *
 * ══ §23/23 CProfiler::WriteProfileData(Buffer_Standard*)  0x2a0ae0  size 960  240 条（0x2a0ae0..0x2a0ea0）
 * @func 0x2a0ae0 0x2a0ea0  size 960  240 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __floatundidf×3 / CProfiler::WriteProfileData(Buffer_Standard*)+0x2d0 / IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool)
 * 字段偏移 top8: 0x8×15 / 0x38×13 / 0x30×9 / 0x1c×5 / 0x2c×4 / 0xc×3 / 0x10×3 / 0x4×2
 * VFP 指令 50 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a0ae0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a0ae4 vpush {d8}
 *   @0x2a0ae8 mov r9, r0
 *   @0x2a0aec ldrb r8, [r0, #0x13]
 *   @0x2a0af0 sub sp, sp, #36
 *   @0x2a0af4 mov r4, r1
 *   @0x2a0af8 cmp r8, #0
 *   @0x2a0afc bne 0x2a0b0c <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard+0x2c>
 *   @0x2a0b00 ldr r10, [r0, #0x30]
 *   @0x2a0b04 cmp r10, #0
 *   @0x2a0b08 bne 0x2a0b40 <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard+0x60>
 *   @0x2a0b0c mov r2, r4
 *   @0x2a0b10 mov r3, #0
 *   @0x2a0b14 ldr r12, [r2], #44
 *   @0x2a0b18 mov r0, r4
 *   @0x2a0b1c str r3, [r4, #0x2c]
 *   @0x2a0b20 mov r1, #6
 *   @0x2a0b24 str r3, [r4, #0x30]
 *   @0x2a0b28 ldr r12, [r12, #0x8]
 *   @0x2a0b2c str r3, [r4, #0x38]
 *   @0x2a0b30 blx r12
 *   @0x2a0b34 add sp, sp, #36
 *   @0x2a0b38 vpop {d8}
 *   @0x2a0b3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2a0b40 vmov s13, r10
 *   @0x2a0b44 ldr r3, [r1]
 *   @0x2a0b48 add r6, r1, #44
 *   @0x2a0b4c str r8, [r1, #0x38]
 *   @0x2a0b50 vcvt.f64.s32 d6, s13
 *   @0x2a0b54 mov r0, r1
 *   @0x2a0b58 mov r2, r6
 *   @0x2a0b5c mov r1, #6
 *   @0x2a0b60 vldr d8, [pc, #816]
 *   @0x2a0b64 vmov r10, r11, d6
 *   @0x2a0b68 vstr s12, [r4, #44]
 *   @0x2a0b6c str r11, [r4, #0x30]
 *   @0x2a0b70 ldr r3, [r3, #0x8]
 *   @0x2a0b74 blx r3
 *   @0x2a0b78 ldrd r0, r1, [r9, #72]
 *   @0x2a0b7c bl 0x319150 <__floatundidf>
 *   @0x2a0b80 ldr r3, [r4]
 *   @0x2a0b84 mov r2, r6
 *   @0x2a0b88 str r8, [r4, #0x38]
 *   @0x2a0b8c vmov d6, r0, r1
 *   @0x2a0b90 mov r1, #8
 *   @0x2a0b94 mov r0, r4
 *   @0x2a0b98 vdiv.f64 d7, d6, d8
 *   @0x2a0b9c vcvt.f32.f64 s14, d7
 *   @0x2a0ba0 vcvt.f64.f32 d6, s14
 *   @0x2a0ba4 vmov r10, r11, d6
 *   @0x2a0ba8 vstr s12, [r4, #44]
 *   @0x2a0bac str r11, [r4, #0x30]
 *   @0x2a0bb0 ldr r3, [r3, #0x8]
 *   @0x2a0bb4 blx r3
 *   @0x2a0bb8 ldrd r0, r1, [r9, #96]
 *   @0x2a0bbc bl 0x319150 <__floatundidf>
 *   @0x2a0bc0 ldr r3, [r4]
 *   @0x2a0bc4 mov r2, r6
 *   @0x2a0bc8 str r8, [r4, #0x38]
 *   @0x2a0bcc vmov d6, r0, r1
 *   @0x2a0bd0 mov r1, #8
 *   @0x2a0bd4 mov r0, r4
 *   @0x2a0bd8 vdiv.f64 d7, d6, d8
 *   @0x2a0bdc vcvt.f32.f64 s14, d7
 *   @0x2a0be0 vcvt.f64.f32 d6, s14
 *   @0x2a0be4 vmov r10, r11, d6
 *   @0x2a0be8 vstr s12, [r4, #44]
 *   @0x2a0bec str r11, [r4, #0x30]
 *   @0x2a0bf0 ldr r3, [r3, #0x8]
 *   @0x2a0bf4 blx r3
 *   @0x2a0bf8 ldrd r0, r1, [r9, #80]
 *   @0x2a0bfc bl 0x319150 <__floatundidf>
 *   @0x2a0c00 ldr r3, [r4]
 *   @0x2a0c04 mov r2, r6
 *   @0x2a0c08 str r8, [r4, #0x38]
 *   @0x2a0c0c vmov d7, r0, r1
 *   @0x2a0c10 mov r1, #8
 *   @0x2a0c14 mov r0, r4
 *   @0x2a0c18 vdiv.f64 d8, d7, d8
 *   @0x2a0c1c vcvt.f32.f64 s16, d8
 *   @0x2a0c20 vcvt.f64.f32 d6, s16
 *   @0x2a0c24 vmov r10, r11, d6
 *   @0x2a0c28 vstr s12, [r4, #44]
 *   @0x2a0c2c str r11, [r4, #0x30]
 *   @0x2a0c30 ldr r3, [r3, #0x8]
 *   @0x2a0c34 blx r3
 *   @0x2a0c38 ldr r12, [r9, #0xc]
 *   @0x2a0c3c ldr r3, [r4]
 *   @0x2a0c40 mov r2, r6
 *   @0x2a0c44 mov r0, r4
 *   @0x2a0c48 mov r1, #6
 *   @0x2a0c4c ldr r12, [r12, #0x4]
 *   @0x2a0c50 str r8, [r4, #0x38]
 *   @0x2a0c54 vmov s15, r12
 *   @0x2a0c58 str r12, [sp, #0x1c]
 *   @0x2a0c5c vcvt.f64.s32 d7, s15
 *   @0x2a0c60 vmov r10, r11, d7
 *   @0x2a0c64 vstr s14, [r4, #44]
 *   @0x2a0c68 str r11, [r4, #0x30]
 *   @0x2a0c6c ldr r3, [r3, #0x8]
 *   @0x2a0c70 blx r3
 *   @0x2a0c74 ldr r3, [sp, #0x1c]
 *   @0x2a0c78 cmp r3, #1
 *   @0x2a0c7c ble 0x2a0db0 <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard+0x2d0>
 *   @0x2a0c80 movw r11, #0x86a0
 *   @0x2a0c84 movt r11, #0x1
 *   @0x2a0c88 mov r10, r8
 *   @0x2a0c8c mov r7, r8
 *   @0x2a0c90 mov r3, r11
 *   @0x2a0c94 mov r11, r9
 *   @0x2a0c98 mov r9, r3
 *   @0x2a0c9c ldr r3, [r11, #0xc]
 *   @0x2a0ca0 mov r1, #5
 *   @0x2a0ca4 ldr r12, [r4]
 *   @0x2a0ca8 mov r0, r4
 *   @0x2a0cac add r10, r10, #1
 *   @0x2a0cb0 ldr r3, [r3, #0x8]
 *   @0x2a0cb4 add r5, r3, r8
 *   @0x2a0cb8 ldr r3, [r3, r8]
 *   @0x2a0cbc add r8, r8, #40
 *   @0x2a0cc0 ldrb r2, [r5, #0x3]
 *   @0x2a0cc4 ubfx r3, r3, #0x0, #0x1c
 *   @0x2a0cc8 str r7, [r4, #0x38]
 *   @0x2a0ccc lsr r2, r2, #4
 *   @0x2a0cd0 mla r3, r9, r2, r3
 *   @0x2a0cd4 mov r2, r6
 *   @0x2a0cd8 vmov s12, r3
 *   @0x2a0cdc vcvt.f64.s32 d7, s12
 *   @0x2a0ce0 vstr s14, [r4, #44]
 *   @0x2a0ce4 vstr s15, [r4, #48]
 *   @0x2a0ce8 ldr r3, [r12, #0x8]
 *   @0x2a0cec blx r3
 *   @0x2a0cf0 vldr s14, [r5, #8]
 *   @0x2a0cf4 vcvt.f64.u32 d7, s14
 *   @0x2a0cf8 ldr r12, [r4]
 *   @0x2a0cfc mov r1, #5
 *   @0x2a0d00 mov r2, r6
 *   @0x2a0d04 mov r0, r4
 *   @0x2a0d08 str r7, [r4, #0x38]
 *   @0x2a0d0c vstr s14, [r4, #44]
 *   @0x2a0d10 vstr s15, [r4, #48]
 *   @0x2a0d14 ldr r3, [r12, #0x8]
 *   @0x2a0d18 blx r3
 *   @0x2a0d1c vldr s14, [r5, #16]
 *   @0x2a0d20 vcvt.f64.u32 d7, s14
 *   @0x2a0d24 ldr r12, [r4]
 *   @0x2a0d28 mov r1, #5
 *   @0x2a0d2c mov r2, r6
 *   @0x2a0d30 mov r0, r4
 *   @0x2a0d34 str r7, [r4, #0x38]
 *   @0x2a0d38 vstr s14, [r4, #44]
 *   @0x2a0d3c vstr s15, [r4, #48]
 *   @0x2a0d40 ldr r3, [r12, #0x8]
 *   @0x2a0d44 blx r3
 *   @0x2a0d48 vldr s14, [r5, #24]
 *   @0x2a0d4c vcvt.f64.s32 d7, s14
 *   @0x2a0d50 ldr r12, [r4]
 *   @0x2a0d54 mov r1, #6
 *   @0x2a0d58 mov r2, r6
 *   @0x2a0d5c mov r0, r4
 *   @0x2a0d60 str r7, [r4, #0x38]
 *   @0x2a0d64 vstr s14, [r4, #44]
 *   @0x2a0d68 vstr s15, [r4, #48]
 *   @0x2a0d6c ldr r3, [r12, #0x8]
 *   @0x2a0d70 blx r3
 *   @0x2a0d74 vldr s14, [r5, #28]
 *   @0x2a0d78 vcvt.f64.s32 d7, s14
 *   @0x2a0d7c ldr r3, [r4]
 *   @0x2a0d80 mov r0, r4
 *   @0x2a0d84 str r7, [r4, #0x38]
 *   @0x2a0d88 mov r1, #6
 *   @0x2a0d8c mov r2, r6
 *   @0x2a0d90 vstr s14, [r4, #44]
 *   @0x2a0d94 vstr s15, [r4, #48]
 *   @0x2a0d98 ldr r3, [r3, #0x8]
 *   @0x2a0d9c blx r3
 *   @0x2a0da0 ldr r3, [sp, #0x1c]
 *   @0x2a0da4 cmp r10, r3
 *   @0x2a0da8 bne 0x2a0c9c <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard+0x1bc>
 *   @0x2a0dac mov r9, r11
 *   @0x2a0db0 ldrb r3, [r9, #0x14]
 *   @0x2a0db4 cmp r3, #0
 *   @0x2a0db8 bne 0x2a0e0c <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard+0x32c>
 *   @0x2a0dbc ldr r12, [r4]
 *   @0x2a0dc0 mov r2, r6
 *   @0x2a0dc4 str r3, [r4, #0x2c]
 *   @0x2a0dc8 mov r0, r4
 *   @0x2a0dcc str r3, [r4, #0x30]
 *   @0x2a0dd0 mov r1, #5
 *   @0x2a0dd4 str r3, [r4, #0x38]
 *   @0x2a0dd8 ldr r3, [r12, #0x8]
 *   @0x2a0ddc blx r3
 *   @0x2a0de0 ldr r3, [r4]
 *   @0x2a0de4 mov r0, r4
 *   @0x2a0de8 ldr r2, [r4, #0x1c]
 *   @0x2a0dec mov r1, #0
 *   @0x2a0df0 ldr r3, [r3, #0x10]
 *   @0x2a0df4 blx r3
 *   @0x2a0df8 mov r0, r9
 *   @0x2a0dfc add sp, sp, #36
 *   @0x2a0e00 vpop {d8}
 *   @0x2a0e04 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a0e08 b 0x2a09a0 <_ZN9CProfiler9ResetDataEv>
 *   @0x2a0e0c ldr r12, [r4]
 *   @0x2a0e10 mov r3, #0
 *   @0x2a0e14 mov r5, r3
 *   @0x2a0e18 mov r2, r6
 *   @0x2a0e1c movt r3, #0x3ff0
 *   @0x2a0e20 str r5, [r4, #0x2c]
 *   @0x2a0e24 str r3, [r4, #0x30]
 *   @0x2a0e28 mov r1, #5
 *   @0x2a0e2c ldr r3, [r12, #0x8]
 *   @0x2a0e30 mov r0, r4
 *   @0x2a0e34 str r5, [r4, #0x38]
 *   @0x2a0e38 blx r3
 *   @0x2a0e3c ldr r6, [r4, #0x1c]
 *   @0x2a0e40 ldr r2, [r9, #0x7c]
 *   @0x2a0e44 mov r12, #1
 *   @0x2a0e48 ldr r1, [r9, #0x74]
 *   @0x2a0e4c mov r3, r5
 *   @0x2a0e50 mvn r0, #0
 *   @0x2a0e54 str r12, [sp, #0x8]
 *   @0x2a0e58 lsl r2, r2, #2
 *   @0x2a0e5c str r0, [sp]
 *   @0x2a0e60 str r5, [sp, #0xc]
 *   @0x2a0e64 mov r0, r4
 *   @0x2a0e68 str r5, [sp, #0x10]
 *   @0x2a0e6c str r6, [sp, #0x4]
 *   @0x2a0e70 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb>
 *   @0x2a0e74 ldr r3, [r4]
 *   @0x2a0e78 mov r1, r5
 *   @0x2a0e7c ldr r3, [r3, #0x10]
 *   @0x2a0e80 add r2, r6, r0
 *   @0x2a0e84 mov r0, r4
 *   @0x2a0e88 blx r3
 *   @0x2a0e8c str r5, [r9, #0x7c]
 *   @0x2a0e90 b 0x2a0de0 <_ZN9CProfiler16WriteProfileDataEP15Buffer_Standard+0x300>
 *   @0x2a0e94 nop
 *   @0x2a0e98 andeq r0, r0, r0
 *   @0x2a0e9c addmi r4, pc, r0
 */
