/* cally 逆向卡：All_34 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 36 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/36 Debug_GetTextures(Buffer_Standard*, Buffer_Standard*)  0x29ad38  size 864  216 条（0x29ad38..0x29b098）
 * @func 0x29ad38 0x29b098  size 864  216 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics::Flush()×2 / GR_Texture_Get_Surface(int)×2 / YYGetUint32(RValue const*, int)×2 / YYGetInt32(RValue const*, int) / Debug_GetTextures(Buffer_Standard*, Buffer_Standard*)+0x340 / GR_Surface_Get(int) / Graphics::Surface_GrabRect(void*, int, int, int, int) / IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool)
 * 字段偏移 top8: 0x8×10 / 0x38×7 / 0x30×6 / 0xc×4 / 0x4×4 / 0x1c×4 / 0x28×3 / 0x24×3
 * VFP 指令 28 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29ad38 ldr r3, [r0]
 *   @0x29ad3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29ad40 vpush {d8}
 *   @0x29ad44 add r8, r0, #44
 *   @0x29ad48 mov r10, r1
 *   @0x29ad4c sub sp, sp, #52
 *   @0x29ad50 mov r2, r8
 *   @0x29ad54 mov r4, #0
 *   @0x29ad58 ldr r3, [r3, #0xc]
 *   @0x29ad5c mov r1, #6
 *   @0x29ad60 mov r9, r0
 *   @0x29ad64 blx r3
 *   @0x29ad68 mov r1, r4
 *   @0x29ad6c mov r0, r8
 *   @0x29ad70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29ad74 ldr r3, [r10]
 *   @0x29ad78 add r7, r10, #44
 *   @0x29ad7c str r4, [r10, #0x38]
 *   @0x29ad80 mov r1, #5
 *   @0x29ad84 mov r2, r7
 *   @0x29ad88 vmov s13, r0
 *   @0x29ad8c str r0, [sp, #0x28]
 *   @0x29ad90 mov r0, r10
 *   @0x29ad94 vcvt.f64.u32 d7, s13
 *   @0x29ad98 vstr s14, [r10, #44]
 *   @0x29ad9c vstr s15, [r10, #48]
 *   @0x29ada0 ldr r3, [r3, #0x8]
 *   @0x29ada4 blx r3
 *   @0x29ada8 ldr r12, [sp, #0x28]
 *   @0x29adac cmp r12, r4
 *   @0x29adb0 ble 0x29b078 <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x340>
 *   @0x29adb4 mov r12, r4
 *   @0x29adb8 str r4, [sp, #0x24]
 *   @0x29adbc movt r12, #0xbff0
 *   @0x29adc0 mov r6, r4
 *   @0x29adc4 str r12, [sp, #0x2c]
 *   @0x29adc8 b 0x29af9c <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x264>
 *   @0x29adcc mov r0, r4
 *   @0x29add0 vmov s17, r4
 *   @0x29add4 bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x29add8 cmp r0, #0
 *   @0x29addc beq 0x29b084 <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x34c>
 *   @0x29ade0 ldr r3, [pc, #0x2a8]
 *   @0x29ade4 ldr r4, [r0, #0x4]
 *   @0x29ade8 ldr r3, [pc, r3]
 *   @0x29adec ldrb r11, [r3]
 *   @0x29adf0 cmp r11, #0
 *   @0x29adf4 beq 0x29b04c <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x314>
 *   @0x29adf8 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x29adfc mov r0, r4
 *   @0x29ae00 bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x29ae04 subs r11, r0, #0
 *   @0x29ae08 beq 0x29b04c <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x314>
 *   @0x29ae0c ldr r12, [r11, #0x4]
 *   @0x29ae10 mov r1, r5
 *   @0x29ae14 ldr r11, [r11, #0x8]
 *   @0x29ae18 mov r2, r5
 *   @0x29ae1c mov r3, r12
 *   @0x29ae20 str r12, [sp, #0x1c]
 *   @0x29ae24 str r11, [sp]
 *   @0x29ae28 str r11, [sp, #0x20]
 *   @0x29ae2c bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii>
 *   @0x29ae30 mov r11, r0
 *   @0x29ae34 cmp r11, #0
 *   @0x29ae38 beq 0x29b04c <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x314>
 *   @0x29ae3c vmov s15, r4
 *   @0x29ae40 ldr r2, [sp, #0x20]
 *   @0x29ae44 ldr r3, [sp, #0x1c]
 *   @0x29ae48 mov r1, #6
 *   @0x29ae4c vcvt.f64.s32 d7, s15
 *   @0x29ae50 str r6, [r10, #0x38]
 *   @0x29ae54 mov r0, r10
 *   @0x29ae58 mul r12, r2, r3
 *   @0x29ae5c mov r2, r7
 *   @0x29ae60 vmov r4, r5, d7
 *   @0x29ae64 vstr s14, [r10, #44]
 *   @0x29ae68 lsl r12, r12, #2
 *   @0x29ae6c vmov s16, r12
 *   @0x29ae70 ldr r12, [r10]
 *   @0x29ae74 str r5, [r10, #0x30]
 *   @0x29ae78 ldr r3, [r12, #0x8]
 *   @0x29ae7c blx r3
 *   @0x29ae80 vcvt.f64.s32 d7, s17
 *   @0x29ae84 ldr r12, [r10]
 *   @0x29ae88 mov r1, #6
 *   @0x29ae8c mov r2, r7
 *   @0x29ae90 mov r0, r10
 *   @0x29ae94 str r6, [r10, #0x38]
 *   @0x29ae98 vmov r4, r5, d7
 *   @0x29ae9c vstr s14, [r10, #44]
 *   @0x29aea0 str r5, [r10, #0x30]
 *   @0x29aea4 ldr r3, [r12, #0x8]
 *   @0x29aea8 blx r3
 *   @0x29aeac vldr s15, [sp, #28]
 *   @0x29aeb0 vcvt.f64.u32 d7, s15
 *   @0x29aeb4 ldr r12, [r10]
 *   @0x29aeb8 mov r1, #5
 *   @0x29aebc mov r2, r7
 *   @0x29aec0 mov r0, r10
 *   @0x29aec4 str r6, [r10, #0x38]
 *   @0x29aec8 vmov r4, r5, d7
 *   @0x29aecc vstr s14, [r10, #44]
 *   @0x29aed0 str r5, [r10, #0x30]
 *   @0x29aed4 ldr r3, [r12, #0x8]
 *   @0x29aed8 blx r3
 *   @0x29aedc vldr s15, [sp, #32]
 *   @0x29aee0 vcvt.f64.u32 d7, s15
 *   @0x29aee4 ldr r12, [r10]
 *   @0x29aee8 mov r1, #5
 *   @0x29aeec mov r2, r7
 *   @0x29aef0 mov r0, r10
 *   @0x29aef4 str r6, [r10, #0x38]
 *   @0x29aef8 vmov r4, r5, d7
 *   @0x29aefc vstr s14, [r10, #44]
 *   @0x29af00 str r5, [r10, #0x30]
 *   @0x29af04 ldr r3, [r12, #0x8]
 *   @0x29af08 blx r3
 *   @0x29af0c vcvt.f64.u32 d7, s16
 *   @0x29af10 ldr r12, [r10]
 *   @0x29af14 mov r1, #5
 *   @0x29af18 mov r2, r7
 *   @0x29af1c mov r0, r10
 *   @0x29af20 str r6, [r10, #0x38]
 *   @0x29af24 vmov r4, r5, d7
 *   @0x29af28 vstr s14, [r10, #44]
 *   @0x29af2c str r5, [r10, #0x30]
 *   @0x29af30 ldr r3, [r12, #0x8]
 *   @0x29af34 blx r3
 *   @0x29af38 ldr lr, [r10, #0x1c]
 *   @0x29af3c vmov r2, s16
 *   @0x29af40 mvn r3, #0
 *   @0x29af44 mov r12, #1
 *   @0x29af48 str r3, [sp]
 *   @0x29af4c mov r1, r11
 *   @0x29af50 mov r3, #0
 *   @0x29af54 str r12, [sp, #0x8]
 *   @0x29af58 mov r0, r10
 *   @0x29af5c str r6, [sp, #0xc]
 *   @0x29af60 str r6, [sp, #0x10]
 *   @0x29af64 str lr, [sp, #0x4]
 *   @0x29af68 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb>
 *   @0x29af6c ldr r3, [r10]
 *   @0x29af70 mov r1, #0
 *   @0x29af74 ldr r3, [r3, #0x10]
 *   @0x29af78 mov r2, r0
 *   @0x29af7c mov r0, r10
 *   @0x29af80 blx r3
 *   @0x29af84 ldr r12, [sp, #0x24]
 *   @0x29af88 ldr r2, [sp, #0x28]
 *   @0x29af8c add r12, r12, #1
 *   @0x29af90 str r12, [sp, #0x24]
 *   @0x29af94 cmp r12, r2
 *   @0x29af98 beq 0x29b078 <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x340>
 *   @0x29af9c ldr r3, [r9]
 *   @0x29afa0 mov r2, r8
 *   @0x29afa4 mov r1, #5
 *   @0x29afa8 mov r0, r9
 *   @0x29afac ldr r3, [r3, #0xc]
 *   @0x29afb0 blx r3
 *   @0x29afb4 mov r1, #0
 *   @0x29afb8 mov r0, r8
 *   @0x29afbc bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29afc0 ldr r3, [r9]
 *   @0x29afc4 mov r1, #5
 *   @0x29afc8 mov r2, r8
 *   @0x29afcc ldr r3, [r3, #0xc]
 *   @0x29afd0 mov r4, r0
 *   @0x29afd4 mov r0, r9
 *   @0x29afd8 blx r3
 *   @0x29afdc mov r0, r8
 *   @0x29afe0 mov r1, #0
 *   @0x29afe4 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x29afe8 subs r5, r0, #0
 *   @0x29afec beq 0x29adcc <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x94>
 *   @0x29aff0 ldr r3, [pc, #0x9c]
 *   @0x29aff4 ldr r3, [pc, r3]
 *   @0x29aff8 ldrb r11, [r3]
 *   @0x29affc cmp r11, #0
 *   @0x29b000 beq 0x29b040 <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x308>
 *   @0x29b004 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x29b008 mov r0, r4
 *   @0x29b00c bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x29b010 subs r11, r0, #0
 *   @0x29b014 beq 0x29b040 <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x308>
 *   @0x29b018 ldr r12, [r11, #0x4]
 *   @0x29b01c mov r1, #0
 *   @0x29b020 ldr r11, [r11, #0x8]
 *   @0x29b024 mov r2, r1
 *   @0x29b028 mov r3, r12
 *   @0x29b02c str r12, [sp, #0x1c]
 *   @0x29b030 str r11, [sp]
 *   @0x29b034 str r11, [sp, #0x20]
 *   @0x29b038 bl 0x17e2a8 <_ZN8Graphics16Texture_GrabRectEPviiii>
 *   @0x29b03c mov r11, r0
 *   @0x29b040 cmp r11, #0
 *   @0x29b044 vldr s17, [pc, #64]
 *   @0x29b048 bne 0x29ae3c <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x104>
 *   @0x29b04c ldr r3, [r10]
 *   @0x29b050 mov r0, r10
 *   @0x29b054 ldr r12, [sp, #0x2c]
 *   @0x29b058 mov r1, #6
 *   @0x29b05c str r11, [r10, #0x2c]
 *   @0x29b060 mov r2, r7
 *   @0x29b064 str r11, [r10, #0x38]
 *   @0x29b068 str r12, [r10, #0x30]
 *   @0x29b06c ldr r3, [r3, #0x8]
 *   @0x29b070 blx r3
 *   @0x29b074 b 0x29af84 <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x24c>
 *   @0x29b078 add sp, sp, #52
 *   @0x29b07c vpop {d8}
 *   @0x29b080 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x29b084 mov r11, r0
 *   @0x29b088 b 0x29b04c <_Z17Debug_GetTexturesP15Buffer_StandardS0_+0x314>
 *   @0x29b08c .word 0xffffffff
 *   @0x29b090 andseq r5, r5, r8, lsr r3
 *   @0x29b094 andseq r5, r5, r12, lsr #2
 *
 * ══ §2/36 jinit_master_decompress  0x2b66d8  size 864  216 条（0x2b66d8..0x2b6a38）
 * @func 0x2b66d8 0x2b6a38  size 864  216 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0×2 / jpeg_calc_output_dimensions / 0xb65bc / anon_2b60ec+0x214 / jinit_1pass_quantizer / jinit_2pass_quantizer / jinit_inverse_dct / jinit_huff_decoder
 * 字段偏移 top8: 0x10×5 / 0x58×5 / 0x4×4 / 0x8×4 / 0xc×4 / 0x14×4 / 0x41×4 / 0x5a×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b66d8 push {r3, r4, r5, r6, r7, lr}
 *   @0x2b66dc mov r1, #1
 *   @0x2b66e0 ldr r3, [r0, #0x4]
 *   @0x2b66e4 mov r2, #28
 *   @0x2b66e8 mov r4, r0
 *   @0x2b66ec mov r7, #0
 *   @0x2b66f0 ldr r3, [r3]
 *   @0x2b66f4 blx r3
 *   @0x2b66f8 ldr r1, [pc, #0x330]
 *   @0x2b66fc ldr r2, [pc, #0x330]
 *   @0x2b6700 add r1, pc, r1
 *   @0x2b6704 add r2, pc, r2
 *   @0x2b6708 mov r3, r0
 *   @0x2b670c mov r0, r4
 *   @0x2b6710 str r3, [r4, #0x180]
 *   @0x2b6714 stm r3, {r1, r2}
 *   @0x2b6718 strb r7, [r3, #0x8]
 *   @0x2b671c ldr r5, [r4, #0x180]
 *   @0x2b6720 bl 0x2b63dc <jpeg_calc_output_dimensions>
 *   @0x2b6724 ldr r3, [r4, #0x4]
 *   @0x2b6728 mov r1, #1
 *   @0x2b672c mov r2, #1408
 *   @0x2b6730 mov r0, r4
 *   @0x2b6734 ldr r3, [r3]
 *   @0x2b6738 blx r3
 *   @0x2b673c mov r1, r7
 *   @0x2b6740 mov r2, #256
 *   @0x2b6744 add r3, r0, #256
 *   @0x2b6748 str r3, [r4, #0x120]
 *   @0x2b674c mov r6, r0
 *   @0x2b6750 bl 0xb65b0 <memset@plt>
 *   @0x2b6754 add r3, r6, #255
 *   @0x2b6758 mov r1, r7
 *   @0x2b675c strb r1, [r3, #0x1]!
 *   @0x2b6760 add r1, r1, #1
 *   @0x2b6764 cmp r1, #256
 *   @0x2b6768 bne 0x2b675c <jinit_master_decompress+0x84>
 *   @0x2b676c add r1, r6, #384
 *   @0x2b6770 mov r3, #128
 *   @0x2b6774 mvn r2, #0
 *   @0x2b6778 strb r2, [r1, r3]
 *   @0x2b677c add r3, r3, #1
 *   @0x2b6780 cmp r3, #512
 *   @0x2b6784 bne 0x2b6778 <jinit_master_decompress+0xa0>
 *   @0x2b6788 mov r1, #0
 *   @0x2b678c mov r2, #384
 *   @0x2b6790 add r0, r6, #896
 *   @0x2b6794 mov r7, r1
 *   @0x2b6798 bl 0xb65b0 <memset@plt>
 *   @0x2b679c ldr r1, [r4, #0x120]
 *   @0x2b67a0 mov r2, #128
 *   @0x2b67a4 add r0, r6, #1280
 *   @0x2b67a8 bl 0xb65bc <memcpy@plt>
 *   @0x2b67ac str r7, [r5, #0xc]
 *   @0x2b67b0 mov r0, r4
 *   @0x2b67b4 bl 0x2b6300 <jpeg_set_marker_processor+0x25c>
 *   @0x2b67b8 str r7, [r5, #0x14]
 *   @0x2b67bc str r7, [r5, #0x18]
 *   @0x2b67c0 strb r0, [r5, #0x10]
 *   @0x2b67c4 ldrb r3, [r4, #0x4a]
 *   @0x2b67c8 cmp r3, r7
 *   @0x2b67cc beq 0x2b6948 <jinit_master_decompress+0x270>
 *   @0x2b67d0 ldrb r3, [r4, #0x40]
 *   @0x2b67d4 cmp r3, r7
 *   @0x2b67d8 strbeq r3, [r4, #0x58]
 *   @0x2b67dc strbeq r3, [r4, #0x59]
 *   @0x2b67e0 strbeq r3, [r4, #0x5a]
 *   @0x2b67e4 ldrb r3, [r4, #0x41]
 *   @0x2b67e8 cmp r3, #0
 *   @0x2b67ec bne 0x2b69c4 <jinit_master_decompress+0x2ec>
 *   @0x2b67f0 ldr r3, [r4, #0x64]
 *   @0x2b67f4 cmp r3, #3
 *   @0x2b67f8 beq 0x2b69e8 <jinit_master_decompress+0x310>
 *   @0x2b67fc mov r3, #0
 *   @0x2b6800 mov r2, #1
 *   @0x2b6804 strb r3, [r4, #0x59]
 *   @0x2b6808 strb r2, [r4, #0x58]
 *   @0x2b680c strb r3, [r4, #0x5a]
 *   @0x2b6810 str r3, [r4, #0x74]
 *   @0x2b6814 mov r0, r4
 *   @0x2b6818 bl 0x2bad30 <jinit_1pass_quantizer>
 *   @0x2b681c ldr r3, [r4, #0x1a8]
 *   @0x2b6820 str r3, [r5, #0x14]
 *   @0x2b6824 ldr r3, [r4, #0x58]
 *   @0x2b6828 bic r3, r3, #-16777216
 *   @0x2b682c bic r3, r3, #255
 *   @0x2b6830 cmp r3, #0
 *   @0x2b6834 beq 0x2b6954 <jinit_master_decompress+0x27c>
 *   @0x2b6838 mov r0, r4
 *   @0x2b683c bl 0x2bc654 <jinit_2pass_quantizer>
 *   @0x2b6840 ldr r3, [r4, #0x1a8]
 *   @0x2b6844 str r3, [r5, #0x18]
 *   @0x2b6848 ldrb r3, [r4, #0x41]
 *   @0x2b684c cmp r3, #0
 *   @0x2b6850 beq 0x2b6960 <jinit_master_decompress+0x288>
 *   @0x2b6854 mov r0, r4
 *   @0x2b6858 bl 0x2be47c <jinit_inverse_dct>
 *   @0x2b685c ldrb r3, [r4, #0xc9]
 *   @0x2b6860 cmp r3, #0
 *   @0x2b6864 bne 0x2b69a8 <jinit_master_decompress+0x2d0>
 *   @0x2b6868 ldrb r3, [r4, #0xc8]
 *   @0x2b686c mov r0, r4
 *   @0x2b6870 cmp r3, #0
 *   @0x2b6874 bne 0x2b698c <jinit_master_decompress+0x2b4>
 *   @0x2b6878 bl 0x2bf19c <jinit_huff_decoder>
 *   @0x2b687c ldr r3, [r4, #0x190]
 *   @0x2b6880 ldrb r3, [r3, #0x10]
 *   @0x2b6884 cmp r3, #0
 *   @0x2b6888 movne r1, #1
 *   @0x2b688c bne 0x2b689c <jinit_master_decompress+0x1c4>
 *   @0x2b6890 ldrb r1, [r4, #0x40]
 *   @0x2b6894 adds r1, r1, #0
 *   @0x2b6898 movne r1, #1
 *   @0x2b689c mov r0, r4
 *   @0x2b68a0 bl 0x2bd9a0 <jinit_d_coef_controller>
 *   @0x2b68a4 ldrb r1, [r4, #0x41]
 *   @0x2b68a8 cmp r1, #0
 *   @0x2b68ac beq 0x2b699c <jinit_master_decompress+0x2c4>
 *   @0x2b68b0 ldr r3, [r4, #0x4]
 *   @0x2b68b4 mov r0, r4
 *   @0x2b68b8 ldr r3, [r3, #0x18]
 *   @0x2b68bc blx r3
 *   @0x2b68c0 ldr r3, [r4, #0x190]
 *   @0x2b68c4 mov r0, r4
 *   @0x2b68c8 ldr r3, [r3, #0x8]
 *   @0x2b68cc blx r3
 *   @0x2b68d0 ldr r3, [r4, #0x8]
 *   @0x2b68d4 cmp r3, #0
 *   @0x2b68d8 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x2b68dc ldrb r2, [r4, #0x40]
 *   @0x2b68e0 cmp r2, #0
 *   @0x2b68e4 popne {r3, r4, r5, r6, r7, pc}
 *   @0x2b68e8 ldr r2, [r4, #0x190]
 *   @0x2b68ec ldrb r2, [r2, #0x10]
 *   @0x2b68f0 cmp r2, #0
 *   @0x2b68f4 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x2b68f8 ldr r12, [r4, #0x24]
 *   @0x2b68fc ldrb r2, [r4, #0xc8]
 *   @0x2b6900 ldr r1, [r4, #0x11c]
 *   @0x2b6904 cmp r2, #0
 *   @0x2b6908 ldr r0, [r5, #0xc]
 *   @0x2b690c addne r12, r12, r12, lsl #1
 *   @0x2b6910 mov r2, #0
 *   @0x2b6914 addne r12, r12, #2
 *   @0x2b6918 str r2, [r3, #0x4]
 *   @0x2b691c str r2, [r3, #0xc]
 *   @0x2b6920 add r2, r0, #1
 *   @0x2b6924 mul r1, r12, r1
 *   @0x2b6928 str r1, [r3, #0x8]
 *   @0x2b692c ldrb r1, [r4, #0x5a]
 *   @0x2b6930 cmp r1, #0
 *   @0x2b6934 moveq r1, #2
 *   @0x2b6938 movne r1, #3
 *   @0x2b693c str r1, [r3, #0x10]
 *   @0x2b6940 str r2, [r5, #0xc]
 *   @0x2b6944 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2b6948 strb r3, [r4, #0x58]
 *   @0x2b694c strb r3, [r4, #0x59]
 *   @0x2b6950 strb r3, [r4, #0x5a]
 *   @0x2b6954 ldrb r3, [r4, #0x41]
 *   @0x2b6958 cmp r3, #0
 *   @0x2b695c bne 0x2b6854 <jinit_master_decompress+0x17c>
 *   @0x2b6960 ldrb r3, [r5, #0x10]
 *   @0x2b6964 mov r0, r4
 *   @0x2b6968 cmp r3, #0
 *   @0x2b696c bne 0x2b6994 <jinit_master_decompress+0x2bc>
 *   @0x2b6970 bl 0x2bdf68 <jinit_color_deconverter>
 *   @0x2b6974 mov r0, r4
 *   @0x2b6978 bl 0x2b8ad0 <jinit_upsampler>
 *   @0x2b697c mov r0, r4
 *   @0x2b6980 ldrb r1, [r4, #0x5a]
 *   @0x2b6984 bl 0x2b840c <jinit_d_post_controller>
 *   @0x2b6988 b 0x2b6854 <jinit_master_decompress+0x17c>
 *   @0x2b698c bl 0x2b7fdc <jinit_phuff_decoder>
 *   @0x2b6990 b 0x2b687c <jinit_master_decompress+0x1a4>
 *   @0x2b6994 bl 0x2b6f9c <jinit_merged_upsampler>
 *   @0x2b6998 b 0x2b697c <jinit_master_decompress+0x2a4>
 *   @0x2b699c mov r0, r4
 *   @0x2b69a0 bl 0x2bf814 <jinit_d_main_controller>
 *   @0x2b69a4 b 0x2b68b0 <jinit_master_decompress+0x1d8>
 *   @0x2b69a8 ldr r3, [r4]
 *   @0x2b69ac mov r2, #1
 *   @0x2b69b0 mov r0, r4
 *   @0x2b69b4 str r2, [r3, #0x14]
 *   @0x2b69b8 ldr r3, [r3]
 *   @0x2b69bc blx r3
 *   @0x2b69c0 b 0x2b687c <jinit_master_decompress+0x1a4>
 *   @0x2b69c4 ldr r3, [r4]
 *   @0x2b69c8 mov r2, #47
 *   @0x2b69cc mov r0, r4
 *   @0x2b69d0 str r2, [r3, #0x14]
 *   @0x2b69d4 ldr r3, [r3]
 *   @0x2b69d8 blx r3
 *   @0x2b69dc ldr r3, [r4, #0x64]
 *   @0x2b69e0 cmp r3, #3
 *   @0x2b69e4 bne 0x2b67fc <jinit_master_decompress+0x124>
 *   @0x2b69e8 ldr r3, [r4, #0x74]
 *   @0x2b69ec cmp r3, #0
 *   @0x2b69f0 beq 0x2b6a0c <jinit_master_decompress+0x334>
 *   @0x2b69f4 ldrb r3, [r4, #0x58]
 *   @0x2b69f8 mov r2, #1
 *   @0x2b69fc strb r2, [r4, #0x59]
 *   @0x2b6a00 cmp r3, #0
 *   @0x2b6a04 beq 0x2b6824 <jinit_master_decompress+0x14c>
 *   @0x2b6a08 b 0x2b6814 <jinit_master_decompress+0x13c>
 *   @0x2b6a0c ldrb r3, [r4, #0x50]
 *   @0x2b6a10 cmp r3, #0
 *   @0x2b6a14 movne r2, #1
 *   @0x2b6a18 ldrbne r3, [r4, #0x58]
 *   @0x2b6a1c strbne r2, [r4, #0x5a]
 *   @0x2b6a20 bne 0x2b6a00 <jinit_master_decompress+0x328>
 *   @0x2b6a24 mov r3, #1
 *   @0x2b6a28 strb r3, [r4, #0x58]
 *   @0x2b6a2c b 0x2b6814 <jinit_master_decompress+0x13c>
 *   @0x2b6a30 .word 0xfffff9e4
 *   @0x2b6a34 .word 0xfffffbc4
 *
 * ══ §3/36 IBuffer::Read(eBuffer_Type, RValue*)  0xcd304  size 860  215 条（0xcd304..0xcd660）
 * @func 0xcd304 0xcd660  size 860  215 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __aeabi_idivmod×2 / IBuffer::Read(eBuffer_Type, RValue*)+0xa0 / IBuffer::Read(eBuffer_Type, RValue*)+0x80 / IBuffer::SizeOf(eBuffer_Type) / IBuffer::Read(eBuffer_Type, RValue*)+0x108 / IBuffer::Read(eBuffer_Type, RValue*)+0x10c / IBuffer::Read(eBuffer_Type, RValue*)+0x1b0 / YYstrnlen(char const*, int)
 * 字段偏移 top8: 0x1c×12 / 0xc×12 / 0x4×6 / 0x24×4 / 0x1×3 / 0x14×2 / 0x10×2 / 0x18×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcd304 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xcd308 mov r3, #0
 *   @0xcd30c mov r7, r1
 *   @0xcd310 str r3, [r2]
 *   @0xcd314 str r3, [r2, #0x4]
 *   @0xcd318 mov r4, r0
 *   @0xcd31c ldr r1, [r0, #0x24]
 *   @0xcd320 mov r6, r2
 *   @0xcd324 ldr r5, [r0, #0x1c]
 *   @0xcd328 sub sp, sp, #12
 *   @0xcd32c ldr r9, [r0, #0x14]
 *   @0xcd330 ldr r8, [r0, #0x10]
 *   @0xcd334 add r5, r1, r5
 *   @0xcd338 sub r0, r9, #1
 *   @0xcd33c rsb r2, r9, #0
 *   @0xcd340 add r5, r5, r0
 *   @0xcd344 str r3, [r6, #0xc]
 *   @0xcd348 and r5, r5, r2
 *   @0xcd34c rsb r5, r1, r5
 *   @0xcd350 str r5, [r4, #0x1c]
 *   @0xcd354 cmp r5, r8
 *   @0xcd358 blt 0xcd3a4 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0xa0>
 *   @0xcd35c ldr r2, [r4, #0x18]
 *   @0xcd360 cmp r2, #2
 *   @0xcd364 beq 0xcd384 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x80>
 *   @0xcd368 mvn r0, #0
 *   @0xcd36c str r3, [r6]
 *   @0xcd370 mov r3, #0
 *   @0xcd374 movt r3, #0xc008
 *   @0xcd378 str r3, [r6, #0x4]
 *   @0xcd37c add sp, sp, #12
 *   @0xcd380 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcd384 add r0, r8, r1
 *   @0xcd388 rsb r5, r8, r5
 *   @0xcd38c mov r1, r9
 *   @0xcd390 bl 0x318dec <__aeabi_idivmod>
 *   @0xcd394 cmp r8, r5
 *   @0xcd398 ble 0xcd384 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x80>
 *   @0xcd39c str r1, [r4, #0x24]
 *   @0xcd3a0 str r5, [r4, #0x1c]
 *   @0xcd3a4 mov r0, r7
 *   @0xcd3a8 bl 0xcd100 <_ZN7IBuffer6SizeOfE12eBuffer_Type>
 *   @0xcd3ac cmp r7, #11
 *   @0xcd3b0 cmpne r7, #13
 *   @0xcd3b4 movne r12, #0
 *   @0xcd3b8 moveq r12, #1
 *   @0xcd3bc beq 0xcd4c0 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x1bc>
 *   @0xcd3c0 ldr r2, [r4, #0x1c]
 *   @0xcd3c4 ldr r9, [r4, #0x10]
 *   @0xcd3c8 add r1, r2, r0
 *   @0xcd3cc ldr r3, [r4, #0x18]
 *   @0xcd3d0 cmp r1, r9
 *   @0xcd3d4 bgt 0xcd450 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x14c>
 *   @0xcd3d8 ldr r10, [r4, #0xc]
 *   @0xcd3dc cmp r3, #2
 *   @0xcd3e0 add r3, r10, r2
 *   @0xcd3e4 beq 0xcd460 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x15c>
 *   @0xcd3e8 cmp r0, #0
 *   @0xcd3ec subgt r12, sp, #1
 *   @0xcd3f0 addgt r1, r3, r0
 *   @0xcd3f4 ble 0xcd40c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x108>
 *   @0xcd3f8 ldrb r5, [r3], #1
 *   @0xcd3fc cmp r3, r1
 *   @0xcd400 strb r5, [r12, #0x1]!
 *   @0xcd404 bne 0xcd3f8 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0xf4>
 *   @0xcd408 add r1, r0, r2
 *   @0xcd40c str r1, [r4, #0x1c]
 *   @0xcd410 sub r7, r7, #1
 *   @0xcd414 cmp r7, #11
 *   @0xcd418 addls pc, pc, r7, lsl #2
 *   @0xcd41c b 0xcd63c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x338>
 *   @0xcd420 b 0xcd550 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x24c>
 *   @0xcd424 b 0xcd608 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x304>
 *   @0xcd428 b 0xcd5f0 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x2ec>
 *   @0xcd42c b 0xcd5d8 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x2d4>
 *   @0xcd430 b 0xcd5b8 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x2b4>
 *   @0xcd434 b 0xcd5a0 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x29c>
 *   @0xcd438 b 0xcd63c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x338>
 *   @0xcd43c b 0xcd580 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x27c>
 *   @0xcd440 b 0xcd56c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x268>
 *   @0xcd444 b 0xcd550 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x24c>
 *   @0xcd448 b 0xcd63c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x338>
 *   @0xcd44c b 0xcd620 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x31c>
 *   @0xcd450 cmp r3, #2
 *   @0xcd454 ldreq r10, [r4, #0xc]
 *   @0xcd458 addeq r3, r10, r2
 *   @0xcd45c bne 0xcd644 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x340>
 *   @0xcd460 cmp r0, #0
 *   @0xcd464 ble 0xcd410 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x10c>
 *   @0xcd468 sub r5, sp, #1
 *   @0xcd46c mov r8, #0
 *   @0xcd470 add r11, r5, r0
 *   @0xcd474 b 0xcd47c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x178>
 *   @0xcd478 ldr r2, [r4, #0x1c]
 *   @0xcd47c ldrb r1, [r3]
 *   @0xcd480 add r2, r2, #1
 *   @0xcd484 cmp r2, r9
 *   @0xcd488 str r2, [r4, #0x1c]
 *   @0xcd48c add r3, r3, #1
 *   @0xcd490 strb r1, [r5, #0x1]!
 *   @0xcd494 blt 0xcd4b4 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x1b0>
 *   @0xcd498 ldr r0, [r4, #0x24]
 *   @0xcd49c ldr r1, [r4, #0x14]
 *   @0xcd4a0 add r0, r9, r0
 *   @0xcd4a4 bl 0x318dec <__aeabi_idivmod>
 *   @0xcd4a8 mov r3, r10
 *   @0xcd4ac str r8, [r4, #0x1c]
 *   @0xcd4b0 str r1, [r4, #0x24]
 *   @0xcd4b4 cmp r5, r11
 *   @0xcd4b8 bne 0xcd478 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x174>
 *   @0xcd4bc b 0xcd410 <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x10c>
 *   @0xcd4c0 ldr r3, [r4, #0x1c]
 *   @0xcd4c4 mov r7, #1
 *   @0xcd4c8 ldr r0, [r4, #0xc]
 *   @0xcd4cc mov r8, #0
 *   @0xcd4d0 ldr r1, [r4, #0x20]
 *   @0xcd4d4 add r0, r0, r3
 *   @0xcd4d8 str r7, [r6, #0xc]
 *   @0xcd4dc rsb r1, r3, r1
 *   @0xcd4e0 bl 0xdc3ec <_Z9YYstrnlenPKci>
 *   @0xcd4e4 ldr r1, [pc, #0x170]
 *   @0xcd4e8 mov r3, r7
 *   @0xcd4ec movw r2, #0x2fb
 *   @0xcd4f0 add r1, pc, r1
 *   @0xcd4f4 add r5, r0, r7
 *   @0xcd4f8 mov r9, r0
 *   @0xcd4fc mov r0, r5
 *   @0xcd500 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xcd504 ldr r3, [r4, #0x1c]
 *   @0xcd508 ldr r1, [r4, #0xc]
 *   @0xcd50c mov r2, r9
 *   @0xcd510 add r1, r1, r3
 *   @0xcd514 mov r7, r0
 *   @0xcd518 bl 0xb65bc <memcpy@plt>
 *   @0xcd51c add r3, r7, r5
 *   @0xcd520 mov r0, r6
 *   @0xcd524 mov r1, r7
 *   @0xcd528 strb r8, [r3, #-0x1]
 *   @0xcd52c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xcd530 mov r0, r7
 *   @0xcd534 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcd538 ldr r3, [r4, #0x1c]
 *   @0xcd53c mov r0, r8
 *   @0xcd540 add r5, r3, r5
 *   @0xcd544 str r5, [r4, #0x1c]
 *   @0xcd548 add sp, sp, #12
 *   @0xcd54c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcd550 ldrb r3, [sp]
 *   @0xcd554 mov r2, #7
 *   @0xcd558 mov r0, #0
 *   @0xcd55c str r2, [r6, #0xc]
 *   @0xcd560 str r3, [r6]
 *   @0xcd564 add sp, sp, #12
 *   @0xcd568 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcd56c ldr r2, [sp]
 *   @0xcd570 mov r0, #0
 *   @0xcd574 ldr r3, [sp, #0x4]
 *   @0xcd578 stm r6, {r2, r3}
 *   @0xcd57c b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78>
 *   @0xcd580 vldr s15, [sp]
 *   @0xcd584 vcvt.f64.f32 d6, s15
 *   @0xcd588 mov r0, #0
 *   @0xcd58c vmov r4, r5, d6
 *   @0xcd590 vmov r2, s12
 *   @0xcd594 mov r3, r5
 *   @0xcd598 stm r6, {r2, r3}
 *   @0xcd59c b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78>
 *   @0xcd5a0 ldr r3, [sp]
 *   @0xcd5a4 mov r2, #7
 *   @0xcd5a8 mov r0, #0
 *   @0xcd5ac str r2, [r6, #0xc]
 *   @0xcd5b0 str r3, [r6]
 *   @0xcd5b4 b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78>
 *   @0xcd5b8 ldr r2, [sp]
 *   @0xcd5bc mov r3, #0
 *   @0xcd5c0 mov r0, r3
 *   @0xcd5c4 str r3, [r6, #0x4]
 *   @0xcd5c8 mov r3, #10
 *   @0xcd5cc str r3, [r6, #0xc]
 *   @0xcd5d0 str r2, [r6]
 *   @0xcd5d4 b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78>
 *   @0xcd5d8 ldrsh r3, [sp]
 *   @0xcd5dc mov r2, #7
 *   @0xcd5e0 mov r0, #0
 *   @0xcd5e4 str r2, [r6, #0xc]
 *   @0xcd5e8 str r3, [r6]
 *   @0xcd5ec b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78>
 *   @0xcd5f0 ldrh r3, [sp]
 *   @0xcd5f4 mov r2, #7
 *   @0xcd5f8 mov r0, #0
 *   @0xcd5fc str r2, [r6, #0xc]
 *   @0xcd600 str r3, [r6]
 *   @0xcd604 b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78>
 *   @0xcd608 ldrsb r3, [sp]
 *   @0xcd60c mov r2, #7
 *   @0xcd610 mov r0, #0
 *   @0xcd614 str r2, [r6, #0xc]
 *   @0xcd618 str r3, [r6]
 *   @0xcd61c b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78>
 *   @0xcd620 ldr r2, [sp]
 *   @0xcd624 mov r1, #10
 *   @0xcd628 ldr r3, [sp, #0x4]
 *   @0xcd62c mov r0, #0
 *   @0xcd630 str r1, [r6, #0xc]
 *   @0xcd634 stm r6, {r2, r3}
 *   @0xcd638 b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78>
 *   @0xcd63c mvn r0, #0
 *   @0xcd640 b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78>
 *   @0xcd644 mov r3, #0
 *   @0xcd648 str r12, [r6]
 *   @0xcd64c movt r3, #0xc008
 *   @0xcd650 mvn r0, #0
 *   @0xcd654 str r3, [r6, #0x4]
 *   @0xcd658 b 0xcd37c <_ZN7IBuffer4ReadE12eBuffer_TypeP6RValue+0x78>
 *   @0xcd65c eoreq r4, r6, r0, lsl #25
 *
 * ══ §4/36 JS_Number_Prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*)  0x256b18  size 860  215 条（0x256b18..0x256e74）
 * @func 0x256b18 0x256e74  size 860  215 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::FindValue(char const*)×4 / 0xb6538×3 / F_JS_ToString(RValue&, RValue*)×2 / 0xb6718×2 / YYCreateString(RValue*, char const*)×2 / 0xb6574 / JSThrowTypeError(char const*) / F_JS_ToInteger(RValue&)
 * 字段偏移 top8: 0xa24×2 / 0xc×2 / 0x4×2 / 0x85c×2 / 0x1×2 / 0x31c×1 / 0x318×1 / 0x40×1
 * VFP 指令 44 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x256b18 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x256b1c vpush {d8, d9, d10}
 *   @0x256b20 mov r6, r1
 *   @0x256b24 ldr r7, [pc, #0x31c]
 *   @0x256b28 sub sp, sp, #2592
 *   @0x256b2c ldr r1, [pc, #0x318]
 *   @0x256b30 sub sp, sp, #12
 *   @0x256b34 ldr r7, [pc, r7]
 *   @0x256b38 mov r8, r0
 *   @0x256b3c add r1, pc, r1
 *   @0x256b40 ldr r0, [r6, #0x40]
 *   @0x256b44 ldr r2, [r7]
 *   @0x256b48 mov r4, r3
 *   @0x256b4c ldr r5, [sp, #0xa68]
 *   @0x256b50 str r2, [sp, #0xa24]
 *   @0x256b54 bl 0xb6574 <strcmp@plt>
 *   @0x256b58 subs r3, r0, #0
 *   @0x256b5c bne 0x256ba4 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x256b60 cmp r4, #1
 *   @0x256b64 beq 0x256bb4 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x256b68 ldr r1, [pc, #0x2e0]
 *   @0x256b6c mov r0, r6
 *   @0x256b70 add r1, pc, r1
 *   @0x256b74 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x256b78 mov r1, r0
 *   @0x256b7c mov r0, r8
 *   @0x256b80 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x256b84 ldr r2, [sp, #0xa24]
 *   @0x256b88 ldr r3, [r7]
 *   @0x256b8c cmp r2, r3
 *   @0x256b90 bne 0x256e44 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x32c>
 *   @0x256b94 add sp, sp, #2592
 *   @0x256b98 add sp, sp, #12
 *   @0x256b9c vpop {d8, d9, d10}
 *   @0x256ba0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x256ba4 ldr r0, [pc, #0x2a8]
 *   @0x256ba8 add r0, pc, r0
 *   @0x256bac bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x256bb0 b 0x256b84 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x256bb4 ldr r2, [r5, #0xc]
 *   @0x256bb8 bic r2, r2, #-16777216
 *   @0x256bbc cmp r2, #5
 *   @0x256bc0 beq 0x256b68 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x256bc4 mov r0, r5
 *   @0x256bc8 str r3, [sp, #0x4]
 *   @0x256bcc bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue>
 *   @0x256bd0 ldr r3, [sp, #0x4]
 *   @0x256bd4 vmov d7, r0, r1
 *   @0x256bd8 vcvt.s32.f64 s15, d7
 *   @0x256bdc vmov r1, s15
 *   @0x256be0 vstr s15, [sp, #8]
 *   @0x256be4 cmp r1, #10
 *   @0x256be8 beq 0x256b68 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x256bec ldr r1, [sp, #0x8]
 *   @0x256bf0 sub r2, r1, #2
 *   @0x256bf4 cmp r2, #34
 *   @0x256bf8 bls 0x256c0c <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x256bfc ldr r0, [pc, #0x254]
 *   @0x256c00 add r0, pc, r0
 *   @0x256c04 bl 0x253ea4 <_Z17JSThrowRangeErrorPKc>
 *   @0x256c08 b 0x256b84 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x256c0c ldr r11, [pc, #0x248]
 *   @0x256c10 add r9, sp, #36
 *   @0x256c14 mov r1, r3
 *   @0x256c18 mov r2, #1280
 *   @0x256c1c add r11, pc, r11
 *   @0x256c20 mov r0, r9
 *   @0x256c24 bl 0xb65b0 <memset@plt>
 *   @0x256c28 mov r0, r6
 *   @0x256c2c mov r1, r11
 *   @0x256c30 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x256c34 ldm r0, {r4, r5}
 *   @0x256c38 vmov d6, r4, r5
 *   @0x256c3c vmov d7, r4, r5
 *   @0x256c40 vcmp.f64 d6, d7
 *   @0x256c44 vmrs APSR_nzcv, fpscr
 *   @0x256c48 bvs 0x256e30 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x318>
 *   @0x256c4c mov r1, r11
 *   @0x256c50 mov r0, r6
 *   @0x256c54 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x256c58 bl 0x240970 <_Z7yyisinfR6RValue>
 *   @0x256c5c cmp r0, #0
 *   @0x256c60 beq 0x256c80 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x256c64 mov r1, r11
 *   @0x256c68 mov r0, r6
 *   @0x256c6c bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x256c70 mov r1, r0
 *   @0x256c74 mov r0, r8
 *   @0x256c78 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x256c7c b 0x256b84 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x256c80 add r11, sp, #24
 *   @0x256c84 mov r0, r4
 *   @0x256c88 sub r4, r11, #8
 *   @0x256c8c mov r1, r5
 *   @0x256c90 mov r2, r4
 *   @0x256c94 bl 0xb6718 <modf@plt>
 *   @0x256c98 vldr d8, [r11, #-8]
 *   @0x256c9c vcmpe.f64 d8, #0
 *   @0x256ca0 vmrs APSR_nzcv, fpscr
 *   @0x256ca4 vnegmi.f64 d8, d8
 *   @0x256ca8 movmi r3, #45
 *   @0x256cac vcmp.f64 d8, #0
 *   @0x256cb0 vstrmi d8, [r11, #-8]
 *   @0x256cb4 vmov d10, r0, r1
 *   @0x256cb8 strhmi r3, [r9]
 *   @0x256cbc mov r0, r9
 *   @0x256cc0 vmrs APSR_nzcv, fpscr
 *   @0x256cc4 beq 0x256d84 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x26c>
 *   @0x256cc8 vldr s15, [sp, #8]
 *   @0x256ccc vcvt.f64.s32 d9, s15
 *   @0x256cd0 bl 0xb6538 <strlen@plt>
 *   @0x256cd4 ldr r6, [pc, #0x184]
 *   @0x256cd8 add r1, sp, #1312
 *   @0x256cdc mov r10, #0
 *   @0x256ce0 add r1, r1, #8
 *   @0x256ce4 add r6, pc, r6
 *   @0x256ce8 sub r4, r1, #5
 *   @0x256cec str r1, [sp, #0xc]
 *   @0x256cf0 add r5, r9, r0
 *   @0x256cf4 vmov r2, r3, d9
 *   @0x256cf8 add r10, r10, #1
 *   @0x256cfc vmov r0, r1, d8
 *   @0x256d00 bl 0xb66ac <fmod@plt>
 *   @0x256d04 vdiv.f64 d7, d8, d9
 *   @0x256d08 vmov d6, r0, r1
 *   @0x256d0c vcvt.s32.f64 s13, d6
 *   @0x256d10 vmov r0, s13
 *   @0x256d14 add r3, r6, r0
 *   @0x256d18 vmov r0, r1, d7
 *   @0x256d1c ldrb r3, [r3, #0x85c]
 *   @0x256d20 strb r3, [r4, #0x1]!
 *   @0x256d24 bl 0xb6598 <floor@plt>
 *   @0x256d28 vmov d8, r0, r1
 *   @0x256d2c vcmpe.f64 d8, #0
 *   @0x256d30 vmrs APSR_nzcv, fpscr
 *   @0x256d34 bgt 0x256cf4 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x1dc>
 *   @0x256d38 add r1, sp, #1312
 *   @0x256d3c mov r3, #0
 *   @0x256d40 add r1, r1, #8
 *   @0x256d44 sub r2, r1, #4
 *   @0x256d48 add r2, r2, r10
 *   @0x256d4c ldrb r1, [r2, #-0x1]!
 *   @0x256d50 strb r1, [r5, r3]
 *   @0x256d54 add r3, r3, #1
 *   @0x256d58 cmp r3, r10
 *   @0x256d5c blt 0x256d4c <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0x256d60 mov r3, #0
 *   @0x256d64 strb r3, [r5, r10]
 *   @0x256d68 vcmp.f64 d10, #0
 *   @0x256d6c vmrs APSR_nzcv, fpscr
 *   @0x256d70 bne 0x256d9c <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x284>
 *   @0x256d74 mov r0, r8
 *   @0x256d78 mov r1, r9
 *   @0x256d7c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x256d80 b 0x256b84 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x256d84 bl 0xb6538 <strlen@plt>
 *   @0x256d88 ldr r3, [pc, #0xd4]
 *   @0x256d8c add r3, pc, r3
 *   @0x256d90 ldrh r3, [r3]
 *   @0x256d94 strh r3, [r9, r0]
 *   @0x256d98 b 0x256d68 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x250>
 *   @0x256d9c mov r0, r9
 *   @0x256da0 bl 0xb6538 <strlen@plt>
 *   @0x256da4 ldr r3, [pc, #0xbc]
 *   @0x256da8 vcmpe.f64 d10, #0
 *   @0x256dac add r3, pc, r3
 *   @0x256db0 ldrh r3, [r3]
 *   @0x256db4 vmrs APSR_nzcv, fpscr
 *   @0x256db8 add r6, r0, #1
 *   @0x256dbc strh r3, [r9, r0]
 *   @0x256dc0 add r6, r9, r6
 *   @0x256dc4 ble 0x256e28 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x310>
 *   @0x256dc8 vldr s12, [sp, #8]
 *   @0x256dcc vcvt.f64.s32 d8, s12
 *   @0x256dd0 ldr r10, [pc, #0x94]
 *   @0x256dd4 sub r5, r6, #1
 *   @0x256dd8 mov r4, #0
 *   @0x256ddc add r10, pc, r10
 *   @0x256de0 mov r2, r11
 *   @0x256de4 add r4, r4, #1
 *   @0x256de8 vmul.f64 d7, d10, d8
 *   @0x256dec vmov r0, r1, d7
 *   @0x256df0 bl 0xb6718 <modf@plt>
 *   @0x256df4 vldr d7, [r11]
 *   @0x256df8 vcvt.s32.f64 s12, d7
 *   @0x256dfc vmov r3, s12
 *   @0x256e00 add r3, r10, r3
 *   @0x256e04 ldrb r3, [r3, #0x85c]
 *   @0x256e08 vmov d10, r0, r1
 *   @0x256e0c strb r3, [r5, #0x1]!
 *   @0x256e10 vcmpe.f64 d10, #0
 *   @0x256e14 vmrs APSR_nzcv, fpscr
 *   @0x256e18 bgt 0x256de0 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x2c8>
 *   @0x256e1c mov r3, #0
 *   @0x256e20 strb r3, [r6, r4]
 *   @0x256e24 b 0x256d74 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x25c>
 *   @0x256e28 mov r4, #0
 *   @0x256e2c b 0x256e1c <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x304>
 *   @0x256e30 ldr r1, [pc, #0x38]
 *   @0x256e34 mov r0, r8
 *   @0x256e38 add r1, pc, r1
 *   @0x256e3c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x256e40 b 0x256b84 <_Z28JS_Number_Prototype_toStringR6RValueP9CInstanceS2_iPS_+0x6c>
 *   @0x256e44 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x256e48 andseq r6, r9, r12, lsl lr
 *   @0x256e4c andeq lr, pc, r4, asr lr
 *   @0x256e50 andeq lr, pc, r0, lsr #19
 *   @0x256e54 andeq pc, pc, r12, lsr #28
 *   @0x256e58 andeq pc, pc, r4, lsr #28
 *   @0x256e5c strdeq lr, pc, [pc], -r4
 *   @0x256e60 andseq r6, r2, r12, lsr #4
 *   @0x256e64 andeq r11, sp, r0, ror #14
 *   @0x256e68 muleq lr, r0, r5
 *   @0x256e6c andseq r6, r2, r4, lsr r1
 *   @0x256e70 strheq r11, [sp], -r12
 *
 * ══ §5/36 b2RevoluteJoint::SolvePositionConstraints(b2SolverData const&)  0x2d1c7c  size 860  215 条（0x2d1c7c..0x2d1fd8）
 * @func 0x2d1c7c 0x2d1fd8  size 860  215 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / 0xb6700 / 0xfebc7bf8
 * 字段偏移 top8: 0x80×2 / 0x84×2 / 0x18×2 / 0x70×1 / 0xe0×1
 * VFP 指令 157 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d1c7c push {r4, r5, r6, r7, r8, lr}
 *   @0x2d1c80 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2d1c84 mov r8, r1
 *   @0x2d1c88 vldr s20, [r0, #176]
 *   @0x2d1c8c ldr r6, [r0, #0x80]
 *   @0x2d1c90 mov r4, r0
 *   @0x2d1c94 ldr r7, [r0, #0x84]
 *   @0x2d1c98 vldr s23, [r0, #180]
 *   @0x2d1c9c ldrb r1, [r0, #0x70]
 *   @0x2d1ca0 ldr r5, [r8, #0x18]
 *   @0x2d1ca4 add r2, r6, r6, lsl #1
 *   @0x2d1ca8 add r3, r7, r7, lsl #1
 *   @0x2d1cac cmp r1, #0
 *   @0x2d1cb0 add r2, r5, r2, lsl #2
 *   @0x2d1cb4 vldr s29, [r2]
 *   @0x2d1cb8 add r3, r5, r3, lsl #2
 *   @0x2d1cbc vldr s28, [r2, #4]
 *   @0x2d1cc0 vldr s24, [r2, #8]
 *   @0x2d1cc4 vldr s27, [r3]
 *   @0x2d1cc8 vldr s26, [r3, #4]
 *   @0x2d1ccc vldr s25, [r3, #8]
 *   @0x2d1cd0 beq 0x2d1ce0 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x64>
 *   @0x2d1cd4 ldr r3, [r0, #0xe0]
 *   @0x2d1cd8 cmp r3, #0
 *   @0x2d1cdc bne 0x2d1e84 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x208>
 *   @0x2d1ce0 vldr s30, [pc, #732]
 *   @0x2d1ce4 vmov r0, s24
 *   @0x2d1ce8 bl 0xb6580 <sinf@plt>
 *   @0x2d1cec vmov s21, r0
 *   @0x2d1cf0 vmov r0, s24
 *   @0x2d1cf4 bl 0xb658c <cosf@plt>
 *   @0x2d1cf8 vmov s22, r0
 *   @0x2d1cfc vmov r0, s25
 *   @0x2d1d00 bl 0xb6580 <sinf@plt>
 *   @0x2d1d04 vmov s18, r0
 *   @0x2d1d08 vmov r0, s25
 *   @0x2d1d0c bl 0xb658c <cosf@plt>
 *   @0x2d1d10 vldr s15, [r4, #164]
 *   @0x2d1d14 vldr s19, [r4, #80]
 *   @0x2d1d18 vsub.f32 s19, s19, s15
 *   @0x2d1d1c vldr s10, [r4, #76]
 *   @0x2d1d20 vldr s13, [r4, #160]
 *   @0x2d1d24 vldr s16, [r4, #72]
 *   @0x2d1d28 vldr s11, [r4, #156]
 *   @0x2d1d2c vldr s12, [r4, #68]
 *   @0x2d1d30 vldr s15, [r4, #152]
 *   @0x2d1d34 vsub.f32 s13, s10, s13
 *   @0x2d1d38 vsub.f32 s16, s16, s11
 *   @0x2d1d3c vsub.f32 s15, s12, s15
 *   @0x2d1d40 vmov s14, r0
 *   @0x2d1d44 vmul.f32 s17, s19, s14
 *   @0x2d1d48 vmul.f32 s19, s19, s18
 *   @0x2d1d4c vmla.f32 s17, s13, s18
 *   @0x2d1d50 vmul.f32 s18, s16, s22
 *   @0x2d1d54 vnmls.f32 s19, s13, s14
 *   @0x2d1d58 vmla.f32 s18, s15, s21
 *   @0x2d1d5c vmul.f32 s16, s16, s21
 *   @0x2d1d60 vadd.f32 s21, s26, s17
 *   @0x2d1d64 vsub.f32 s21, s21, s28
 *   @0x2d1d68 vnmls.f32 s16, s15, s22
 *   @0x2d1d6c vadd.f32 s22, s27, s19
 *   @0x2d1d70 vsub.f32 s21, s21, s18
 *   @0x2d1d74 vsub.f32 s22, s22, s29
 *   @0x2d1d78 vmul.f32 s15, s21, s21
 *   @0x2d1d7c vsub.f32 s22, s22, s16
 *   @0x2d1d80 vmla.f32 s15, s22, s22
 *   @0x2d1d84 vsqrt.f32 s10, s15
 *   @0x2d1d88 vcmp.f32 s10, s10
 *   @0x2d1d8c vmrs APSR_nzcv, fpscr
 *   @0x2d1d90 bne 0x2d1f88 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x30c>
 *   @0x2d1d94 vldr s8, [r4, #168]
 *   @0x2d1d98 vldr s9, [r4, #172]
 *   @0x2d1d9c vadd.f32 s12, s8, s9
 *   @0x2d1da0 add r6, r6, r6, lsl #1
 *   @0x2d1da4 add r7, r7, r7, lsl #1
 *   @0x2d1da8 add r6, r5, r6, lsl #2
 *   @0x2d1dac add r5, r5, r7, lsl #2
 *   @0x2d1db0 vmul.f32 s11, s20, s16
 *   @0x2d1db4 vmul.f32 s15, s23, s19
 *   @0x2d1db8 vmul.f32 s7, s20, s18
 *   @0x2d1dbc vmov.f32 s6, s12
 *   @0x2d1dc0 vmla.f32 s6, s11, s16
 *   @0x2d1dc4 vmul.f32 s14, s15, s17
 *   @0x2d1dc8 vnmul.f32 s13, s20, s16
 *   @0x2d1dcc vmla.f32 s12, s7, s18
 *   @0x2d1dd0 vldr s7, [pc, #496]
 *   @0x2d1dd4 vnmls.f32 s14, s13, s18
 *   @0x2d1dd8 vmul.f32 s13, s23, s17
 *   @0x2d1ddc vmov.f32 s11, s6
 *   @0x2d1de0 vmla.f32 s12, s13, s17
 *   @0x2d1de4 vmla.f32 s11, s15, s19
 *   @0x2d1de8 vmul.f32 s15, s14, s14
 *   @0x2d1dec vnmls.f32 s15, s12, s11
 *   @0x2d1df0 vcmp.f32 s15, #0
 *   @0x2d1df4 vmrs APSR_nzcv, fpscr
 *   @0x2d1df8 vmovne.f32 s13, #1.000000e+00
 *   @0x2d1dfc vdivne.f32 s15, s13, s15
 *   @0x2d1e00 vmul.f32 s13, s14, s21
 *   @0x2d1e04 vmul.f32 s14, s14, s22
 *   @0x2d1e08 vnmls.f32 s13, s11, s22
 *   @0x2d1e0c vnmls.f32 s14, s12, s21
 *   @0x2d1e10 vnmul.f32 s13, s15, s13
 *   @0x2d1e14 vnmul.f32 s15, s14, s15
 *   @0x2d1e18 vmul.f32 s18, s18, s13
 *   @0x2d1e1c vmul.f32 s17, s17, s13
 *   @0x2d1e20 vnmls.f32 s18, s16, s15
 *   @0x2d1e24 vnmls.f32 s17, s19, s15
 *   @0x2d1e28 vmls.f32 s29, s8, s13
 *   @0x2d1e2c vmls.f32 s24, s20, s18
 *   @0x2d1e30 vstr s29, [r6]
 *   @0x2d1e34 vmla.f32 s25, s23, s17
 *   @0x2d1e38 vstr s24, [r6, #8]
 *   @0x2d1e3c vmls.f32 s28, s8, s15
 *   @0x2d1e40 vmla.f32 s27, s9, s13
 *   @0x2d1e44 vstr s28, [r6, #4]
 *   @0x2d1e48 vstr s25, [r5, #8]
 *   @0x2d1e4c vmla.f32 s26, s9, s15
 *   @0x2d1e50 vstr s27, [r5]
 *   @0x2d1e54 vcmpe.f32 s10, s7
 *   @0x2d1e58 vstr s26, [r5, #4]
 *   @0x2d1e5c vmrs APSR_nzcv, fpscr
 *   @0x2d1e60 movhi r0, #0
 *   @0x2d1e64 bhi 0x2d1e7c <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x200>
 *   @0x2d1e68 vldr s15, [pc, #348]
 *   @0x2d1e6c vcmpe.f32 s30, s15
 *   @0x2d1e70 vmrs APSR_nzcv, fpscr
 *   @0x2d1e74 movhi r0, #0
 *   @0x2d1e78 movls r0, #1
 *   @0x2d1e7c vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2d1e80 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2d1e84 vadd.f32 s15, s20, s23
 *   @0x2d1e88 vcmp.f32 s15, #0
 *   @0x2d1e8c vmrs APSR_nzcv, fpscr
 *   @0x2d1e90 beq 0x2d1ce0 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x64>
 *   @0x2d1e94 vsub.f32 s30, s25, s24
 *   @0x2d1e98 cmp r3, #3
 *   @0x2d1e9c vldr s15, [r0, #116]
 *   @0x2d1ea0 vsub.f32 s30, s30, s15
 *   @0x2d1ea4 beq 0x2d1f08 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x28c>
 *   @0x2d1ea8 cmp r3, #1
 *   @0x2d1eac beq 0x2d1f40 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x2c4>
 *   @0x2d1eb0 cmp r3, #2
 *   @0x2d1eb4 beq 0x2d1ecc <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x250>
 *   @0x2d1eb8 vldr s15, [pc, #260]
 *   @0x2d1ebc vmov.f32 s30, s15
 *   @0x2d1ec0 vmls.f32 s24, s15, s20
 *   @0x2d1ec4 vmla.f32 s25, s15, s23
 *   @0x2d1ec8 b 0x2d1ce4 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x68>
 *   @0x2d1ecc vldr s15, [r0, #124]
 *   @0x2d1ed0 vsub.f32 s30, s30, s15
 *   @0x2d1ed4 vldr s14, [pc, #240]
 *   @0x2d1ed8 vldr s15, [pc, #240]
 *   @0x2d1edc vsub.f32 s14, s30, s14
 *   @0x2d1ee0 vcmpe.f32 s14, s15
 *   @0x2d1ee4 vmrs APSR_nzcv, fpscr
 *   @0x2d1ee8 bpl 0x2d1efc <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x280>
 *   @0x2d1eec vcmpe.f32 s14, #0
 *   @0x2d1ef0 vmrs APSR_nzcv, fpscr
 *   @0x2d1ef4 bpl 0x2d1f70 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x2f4>
 *   @0x2d1ef8 vldr s15, [pc, #196]
 *   @0x2d1efc vldr s13, [r4, #220]
 *   @0x2d1f00 vnmul.f32 s15, s13, s15
 *   @0x2d1f04 b 0x2d1ec0 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x244>
 *   @0x2d1f08 vldr s15, [r0, #120]
 *   @0x2d1f0c vsub.f32 s30, s30, s15
 *   @0x2d1f10 vldr s14, [pc, #184]
 *   @0x2d1f14 vcmpe.f32 s30, s14
 *   @0x2d1f18 vmrs APSR_nzcv, fpscr
 *   @0x2d1f1c bpl 0x2d1f78 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x2fc>
 *   @0x2d1f20 vldr s15, [pc, #172]
 *   @0x2d1f24 vcmpe.f32 s30, s15
 *   @0x2d1f28 vmrs APSR_nzcv, fpscr
 *   @0x2d1f2c bpl 0x2d1fac <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x330>
 *   @0x2d1f30 vmov.f32 s30, s14
 *   @0x2d1f34 vldr s14, [r0, #220]
 *   @0x2d1f38 vnmul.f32 s15, s14, s15
 *   @0x2d1f3c b 0x2d1ec0 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x244>
 *   @0x2d1f40 vldr s15, [r0, #120]
 *   @0x2d1f44 vsub.f32 s30, s30, s15
 *   @0x2d1f48 vldr s14, [pc, #124]
 *   @0x2d1f4c vadd.f32 s14, s30, s14
 *   @0x2d1f50 vcmpe.f32 s14, #0
 *   @0x2d1f54 vneg.f32 s30, s30
 *   @0x2d1f58 vmrs APSR_nzcv, fpscr
 *   @0x2d1f5c bpl 0x2d1ef8 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x27c>
 *   @0x2d1f60 vldr s15, [pc, #108]
 *   @0x2d1f64 vcmpe.f32 s14, s15
 *   @0x2d1f68 vmrs APSR_nzcv, fpscr
 *   @0x2d1f6c bmi 0x2d1efc <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x280>
 *   @0x2d1f70 vmov.f32 s15, s14
 *   @0x2d1f74 b 0x2d1efc <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x280>
 *   @0x2d1f78 vldr s15, [r0, #220]
 *   @0x2d1f7c vmov.f32 s30, s14
 *   @0x2d1f80 vnmul.f32 s15, s15, s14
 *   @0x2d1f84 b 0x2d1ec0 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x244>
 *   @0x2d1f88 vmov r0, s15
 *   @0x2d1f8c bl 0xb6700 <sqrtf@plt>
 *   @0x2d1f90 ldr r5, [r8, #0x18]
 *   @0x2d1f94 vldr s20, [r4, #176]
 *   @0x2d1f98 ldr r6, [r4, #0x80]
 *   @0x2d1f9c vldr s23, [r4, #180]
 *   @0x2d1fa0 ldr r7, [r4, #0x84]
 *   @0x2d1fa4 vmov s10, r0
 *   @0x2d1fa8 b 0x2d1d94 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x118>
 *   @0x2d1fac vcmpe.f32 s30, #0
 *   @0x2d1fb0 vldr s15, [r0, #220]
 *   @0x2d1fb4 vmrs APSR_nzcv, fpscr
 *   @0x2d1fb8 vnmul.f32 s15, s15, s30
 *   @0x2d1fbc vnegle.f32 s30, s30
 *   @0x2d1fc0 b 0x2d1ec0 <_ZN15b2RevoluteJoint24SolvePositionConstraintsERK12b2SolverData+0x244>
 *   @0x2d1fc4 andeq r0, r0, r0
 *   @0x2d1fc8 bllo 0xfebc7bf8 <b2_toiTime+0xfffffffffe46e754>
 *   @0x2d1fcc vstrlo s30, [lr, #-216]
 *   @0x2d1fd0 .word 0x3e0efa36
 *   @0x2d1fd4 .word 0xbe0efa36
 *
 * ══ §6/36 CDS_Queue::Assign(CDS_Queue*)  0x20edac  size 856  214 条（0x20edac..0x20f104）
 * @func 0x20edac 0x20f104  size 856  214 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CDS_Queue::Assign(CDS_Queue*)+0x134 / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x4×40 / 0x8×18 / 0xc×14 / 0x10×2 / 0x31c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20edac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20edb0 subs r11, r1, #0
 *   @0x20edb4 sub sp, sp, #20
 *   @0x20edb8 str r0, [sp, #0xc]
 *   @0x20edbc beq 0x20f0f4 <_ZN9CDS_Queue6AssignEPS_+0x348>
 *   @0x20edc0 ldr r12, [sp, #0xc]
 *   @0x20edc4 mov r3, #768
 *   @0x20edc8 ldr r2, [r11, #0x8]
 *   @0x20edcc ldr r1, [r11, #0xc]
 *   @0x20edd0 add r0, r12, #16
 *   @0x20edd4 ldr lr, [r11, #0x4]
 *   @0x20edd8 str r2, [r12, #0x8]
 *   @0x20eddc ldr r2, [pc, #0x31c]
 *   @0x20ede0 lsl r1, r1, #4
 *   @0x20ede4 str lr, [r12, #0x4]
 *   @0x20ede8 add r2, pc, r2
 *   @0x20edec bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x20edf0 ldr r3, [r11, #0xc]
 *   @0x20edf4 ldr r12, [sp, #0xc]
 *   @0x20edf8 str r3, [r12, #0xc]
 *   @0x20edfc ldr r3, [r11, #0xc]
 *   @0x20ee00 cmp r3, #1
 *   @0x20ee04 ble 0x20eee0 <_ZN9CDS_Queue6AssignEPS_+0x134>
 *   @0x20ee08 mov r7, #0
 *   @0x20ee0c mov r9, r7
 *   @0x20ee10 ldr r12, [sp, #0xc]
 *   @0x20ee14 lsl r4, r7, #4
 *   @0x20ee18 ldr r10, [r11, #0x10]
 *   @0x20ee1c ldr r6, [r12, #0x10]
 *   @0x20ee20 add r8, r10, r4
 *   @0x20ee24 add r5, r6, r4
 *   @0x20ee28 ldr r1, [r5, #0xc]
 *   @0x20ee2c bic r2, r1, #-16777216
 *   @0x20ee30 cmp r2, #1
 *   @0x20ee34 beq 0x20ef64 <_ZN9CDS_Queue6AssignEPS_+0x1b8>
 *   @0x20ee38 cmp r2, #2
 *   @0x20ee3c bne 0x20ee60 <_ZN9CDS_Queue6AssignEPS_+0xb4>
 *   @0x20ee40 sub r1, r1, #1
 *   @0x20ee44 bic r1, r1, #-16777216
 *   @0x20ee48 bic r1, r1, #3
 *   @0x20ee4c cmp r1, #0
 *   @0x20ee50 beq 0x20eff4 <_ZN9CDS_Queue6AssignEPS_+0x248>
 *   @0x20ee54 mov r2, #5
 *   @0x20ee58 str r9, [r5, #0x8]
 *   @0x20ee5c str r2, [r5, #0xc]
 *   @0x20ee60 ldr r2, [r8, #0xc]
 *   @0x20ee64 ldr r1, [r8, #0x8]
 *   @0x20ee68 str r9, [r6, r4]
 *   @0x20ee6c str r2, [r5, #0xc]
 *   @0x20ee70 ldr r2, [r8, #0xc]
 *   @0x20ee74 str r1, [r5, #0x8]
 *   @0x20ee78 bic r2, r2, #-16777216
 *   @0x20ee7c cmp r2, #14
 *   @0x20ee80 addls pc, pc, r2, lsl #2
 *   @0x20ee84 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120>
 *   @0x20ee88 b 0x20eee8 <_ZN9CDS_Queue6AssignEPS_+0x13c>
 *   @0x20ee8c b 0x20ef4c <_ZN9CDS_Queue6AssignEPS_+0x1a0>
 *   @0x20ee90 b 0x20ef20 <_ZN9CDS_Queue6AssignEPS_+0x174>
 *   @0x20ee94 b 0x20eec4 <_ZN9CDS_Queue6AssignEPS_+0x118>
 *   @0x20ee98 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120>
 *   @0x20ee9c b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120>
 *   @0x20eea0 b 0x20eefc <_ZN9CDS_Queue6AssignEPS_+0x150>
 *   @0x20eea4 b 0x20eec4 <_ZN9CDS_Queue6AssignEPS_+0x118>
 *   @0x20eea8 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120>
 *   @0x20eeac b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120>
 *   @0x20eeb0 b 0x20eee8 <_ZN9CDS_Queue6AssignEPS_+0x13c>
 *   @0x20eeb4 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120>
 *   @0x20eeb8 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120>
 *   @0x20eebc b 0x20eee8 <_ZN9CDS_Queue6AssignEPS_+0x13c>
 *   @0x20eec0 b 0x20eec4 <_ZN9CDS_Queue6AssignEPS_+0x118>
 *   @0x20eec4 ldr r3, [r10, r4]
 *   @0x20eec8 str r3, [r6, r4]
 *   @0x20eecc ldr r3, [r11, #0xc]
 *   @0x20eed0 add r7, r7, #1
 *   @0x20eed4 sub r3, r3, #1
 *   @0x20eed8 cmp r3, r7
 *   @0x20eedc bgt 0x20ee10 <_ZN9CDS_Queue6AssignEPS_+0x64>
 *   @0x20eee0 add sp, sp, #20
 *   @0x20eee4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20eee8 ldr r2, [r10, r4]
 *   @0x20eeec ldr r3, [r8, #0x4]
 *   @0x20eef0 str r2, [r6, r4]
 *   @0x20eef4 str r3, [r5, #0x4]
 *   @0x20eef8 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120>
 *   @0x20eefc ldr r2, [r10, r4]
 *   @0x20ef00 str r2, [r6, r4]
 *   @0x20ef04 ldr r2, [r10, r4]
 *   @0x20ef08 cmp r2, #0
 *   @0x20ef0c beq 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120>
 *   @0x20ef10 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20ef14 ldr r1, [r10, r4]
 *   @0x20ef18 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20ef1c b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120>
 *   @0x20ef20 ldr r3, [r10, r4]
 *   @0x20ef24 cmp r3, #0
 *   @0x20ef28 str r3, [r6, r4]
 *   @0x20ef2c beq 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120>
 *   @0x20ef30 ldr r1, [r3, #0x8]
 *   @0x20ef34 ldr r2, [r3]
 *   @0x20ef38 cmp r1, #0
 *   @0x20ef3c streq r5, [r3, #0x8]
 *   @0x20ef40 add r2, r2, #1
 *   @0x20ef44 str r2, [r3]
 *   @0x20ef48 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120>
 *   @0x20ef4c ldr r3, [r10, r4]
 *   @0x20ef50 cmp r3, #0
 *   @0x20ef54 ldrne r2, [r3, #0x4]
 *   @0x20ef58 addne r2, r2, #1
 *   @0x20ef5c strne r2, [r3, #0x4]
 *   @0x20ef60 b 0x20eec8 <_ZN9CDS_Queue6AssignEPS_+0x11c>
 *   @0x20ef64 ldr r2, [r6, r7, lsl #4]
 *   @0x20ef68 cmp r2, #0
 *   @0x20ef6c beq 0x20ef94 <_ZN9CDS_Queue6AssignEPS_+0x1e8>
 *   @0x20ef70 str r2, [sp, #0x4]
 *   @0x20ef74 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20ef78 ldr r2, [sp, #0x4]
 *   @0x20ef7c ldr r1, [r2, #0x4]
 *   @0x20ef80 sub r1, r1, #1
 *   @0x20ef84 str r1, [r2, #0x4]
 *   @0x20ef88 cmp r1, #0
 *   @0x20ef8c beq 0x20ef9c <_ZN9CDS_Queue6AssignEPS_+0x1f0>
 *   @0x20ef90 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20ef94 str r9, [r6, r4]
 *   @0x20ef98 b 0x20ee60 <_ZN9CDS_Queue6AssignEPS_+0xb4>
 *   @0x20ef9c ldr r0, [r2]
 *   @0x20efa0 str r1, [sp, #0x8]
 *   @0x20efa4 str r2, [sp, #0x4]
 *   @0x20efa8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20efac ldr r2, [sp, #0x4]
 *   @0x20efb0 ldr r1, [sp, #0x8]
 *   @0x20efb4 str r1, [r2]
 *   @0x20efb8 str r1, [r2, #0x8]
 *   @0x20efbc str r2, [sp, #0x4]
 *   @0x20efc0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20efc4 ldr r2, [sp, #0x4]
 *   @0x20efc8 ldr r1, [r2, #0x4]
 *   @0x20efcc sub r1, r1, #1
 *   @0x20efd0 str r1, [r2, #0x4]
 *   @0x20efd4 cmp r1, #0
 *   @0x20efd8 beq 0x20f000 <_ZN9CDS_Queue6AssignEPS_+0x254>
 *   @0x20efdc str r2, [sp, #0x4]
 *   @0x20efe0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20efe4 ldr r2, [sp, #0x4]
 *   @0x20efe8 mov r0, r2
 *   @0x20efec bl 0x27d1d0 <_ZdlPv>
 *   @0x20eff0 b 0x20ef90 <_ZN9CDS_Queue6AssignEPS_+0x1e4>
 *   @0x20eff4 mov r0, r5
 *   @0x20eff8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20effc b 0x20ee54 <_ZN9CDS_Queue6AssignEPS_+0xa8>
 *   @0x20f000 ldr r0, [r2]
 *   @0x20f004 str r1, [sp, #0x8]
 *   @0x20f008 str r2, [sp, #0x4]
 *   @0x20f00c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20f010 ldr r2, [sp, #0x4]
 *   @0x20f014 ldr r1, [sp, #0x8]
 *   @0x20f018 str r1, [r2]
 *   @0x20f01c str r1, [r2, #0x8]
 *   @0x20f020 str r2, [sp, #0x4]
 *   @0x20f024 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20f028 ldr r2, [sp, #0x4]
 *   @0x20f02c ldr r1, [r2, #0x4]
 *   @0x20f030 sub r1, r1, #1
 *   @0x20f034 str r1, [r2, #0x4]
 *   @0x20f038 cmp r1, #0
 *   @0x20f03c beq 0x20f05c <_ZN9CDS_Queue6AssignEPS_+0x2b0>
 *   @0x20f040 str r2, [sp, #0x4]
 *   @0x20f044 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20f048 ldr r2, [sp, #0x4]
 *   @0x20f04c mov r0, r2
 *   @0x20f050 bl 0x27d1d0 <_ZdlPv>
 *   @0x20f054 ldr r2, [sp, #0x4]
 *   @0x20f058 b 0x20efdc <_ZN9CDS_Queue6AssignEPS_+0x230>
 *   @0x20f05c ldr r0, [r2]
 *   @0x20f060 str r1, [sp, #0x8]
 *   @0x20f064 str r2, [sp, #0x4]
 *   @0x20f068 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20f06c ldr r2, [sp, #0x4]
 *   @0x20f070 ldr r1, [sp, #0x8]
 *   @0x20f074 str r1, [r2]
 *   @0x20f078 str r1, [r2, #0x8]
 *   @0x20f07c str r2, [sp, #0x4]
 *   @0x20f080 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20f084 ldr r2, [sp, #0x4]
 *   @0x20f088 ldr r1, [r2, #0x4]
 *   @0x20f08c sub r1, r1, #1
 *   @0x20f090 str r1, [r2, #0x4]
 *   @0x20f094 cmp r1, #0
 *   @0x20f098 bne 0x20f0d8 <_ZN9CDS_Queue6AssignEPS_+0x32c>
 *   @0x20f09c ldr r0, [r2]
 *   @0x20f0a0 str r1, [sp, #0x8]
 *   @0x20f0a4 str r2, [sp, #0x4]
 *   @0x20f0a8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20f0ac ldr r2, [sp, #0x4]
 *   @0x20f0b0 ldr r1, [sp, #0x8]
 *   @0x20f0b4 mov r0, r2
 *   @0x20f0b8 str r1, [r2]
 *   @0x20f0bc str r1, [r2, #0x8]
 *   @0x20f0c0 str r2, [sp, #0x4]
 *   @0x20f0c4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20f0c8 ldr r2, [sp, #0x4]
 *   @0x20f0cc mov r0, r2
 *   @0x20f0d0 bl 0x27d1d0 <_ZdlPv>
 *   @0x20f0d4 ldr r2, [sp, #0x4]
 *   @0x20f0d8 str r2, [sp, #0x4]
 *   @0x20f0dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20f0e0 ldr r2, [sp, #0x4]
 *   @0x20f0e4 mov r0, r2
 *   @0x20f0e8 bl 0x27d1d0 <_ZdlPv>
 *   @0x20f0ec ldr r2, [sp, #0x4]
 *   @0x20f0f0 b 0x20f040 <_ZN9CDS_Queue6AssignEPS_+0x294>
 *   @0x20f0f4 add sp, sp, #20
 *   @0x20f0f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20f0fc b 0x20eacc <_ZN9CDS_Queue5ClearEv>
 *   @0x20f100 andseq r4, r4, r4, lsl #20
 *
 * ══ §7/36 F_JSNewArray(RValue&, CInstance*, CInstance*, int, RValue*)  0x24c4ec  size 856  214 条（0x24c4ec..0x24c844）
 * @func 0x24c4ec 0x24c844  size 856  214 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×6 / UNLOCK_RVALUE_MUTEX()×6 / YYFree(void const*)×6 / operator delete(void*)×6 / F_JSNewArray_NoArguments(RValue&, CInstance*, CInstance*, int, RValue*) / PushContextStack(YYObjectBase*) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x4×14 / 0xc×12 / 0x-10×11 / 0x8×7 / 0x-4×5 / 0x-8×4 / 0x38×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24c4ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24c4f0 sub sp, sp, #20
 *   @0x24c4f4 mov r6, r0
 *   @0x24c4f8 mov r4, r3
 *   @0x24c4fc ldr r5, [sp, #0x38]
 *   @0x24c500 cmp r3, #8
 *   @0x24c504 movlt r3, #8
 *   @0x24c508 str r5, [sp]
 *   @0x24c50c bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x24c510 ldr r0, [r6]
 *   @0x24c514 ldr r3, [r0, #0x4]
 *   @0x24c518 cmp r3, #0
 *   @0x24c51c beq 0x24c78c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x2a0>
 *   @0x24c520 add r0, r3, #16
 *   @0x24c524 ldr r7, [r0]
 *   @0x24c528 mov r0, r7
 *   @0x24c52c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x24c530 subs r6, r4, #1
 *   @0x24c534 str r4, [r7, #0x24]
 *   @0x24c538 addpl r5, r5, #16
 *   @0x24c53c ldr r4, [r7, #0x4]
 *   @0x24c540 movpl r9, #0
 *   @0x24c544 movpl r10, #7
 *   @0x24c548 addpl r4, r4, #16
 *   @0x24c54c bmi 0x24c614 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x24c550 ldr r2, [r4, #-0x4]
 *   @0x24c554 sub r8, r5, #16
 *   @0x24c558 sub r7, r4, #16
 *   @0x24c55c bic r3, r2, #-16777216
 *   @0x24c560 cmp r3, #1
 *   @0x24c564 beq 0x24c694 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x24c568 cmp r3, #2
 *   @0x24c56c bne 0x24c590 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x24c570 sub r2, r2, #1
 *   @0x24c574 bic r2, r2, #-16777216
 *   @0x24c578 bic r2, r2, #3
 *   @0x24c57c cmp r2, #0
 *   @0x24c580 beq 0x24c700 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x24c584 mov r3, #5
 *   @0x24c588 str r9, [r4, #-0x8]
 *   @0x24c58c str r3, [r4, #-0x4]
 *   @0x24c590 str r9, [r4, #-0x10]
 *   @0x24c594 ldr r3, [r5, #-0x4]
 *   @0x24c598 str r3, [r4, #-0x4]
 *   @0x24c59c ldr r3, [r5, #-0x8]
 *   @0x24c5a0 str r3, [r4, #-0x8]
 *   @0x24c5a4 ldr r3, [r5, #-0x4]
 *   @0x24c5a8 bic r3, r3, #-16777216
 *   @0x24c5ac cmp r3, #14
 *   @0x24c5b0 addls pc, pc, r3, lsl #2
 *   @0x24c5b4 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x24c5b8 b 0x24c620 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x24c5bc b 0x24c67c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x24c5c0 b 0x24c650 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x24c5c4 b 0x24c5f4 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x24c5c8 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x24c5cc b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x24c5d0 b 0x24c62c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x24c5d4 b 0x24c5f4 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x24c5d8 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x24c5dc b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x24c5e0 b 0x24c620 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x24c5e4 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x24c5e8 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x24c5ec b 0x24c620 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x24c5f0 b 0x24c5f4 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0x24c5f4 ldr r3, [r5, #-0x10]
 *   @0x24c5f8 str r3, [r4, #-0x10]
 *   @0x24c5fc sub r6, r6, #1
 *   @0x24c600 str r10, [r4, #-0x8]
 *   @0x24c604 cmn r6, #1
 *   @0x24c608 add r5, r5, #16
 *   @0x24c60c add r4, r4, #16
 *   @0x24c610 bne 0x24c550 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x24c614 add sp, sp, #20
 *   @0x24c618 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24c61c b 0xd3a34 <_Z15PopContextStackv>
 *   @0x24c620 ldm r8, {r2, r3}
 *   @0x24c624 stm r7, {r2, r3}
 *   @0x24c628 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x24c62c ldr r3, [r5, #-0x10]
 *   @0x24c630 str r3, [r4, #-0x10]
 *   @0x24c634 ldr r3, [r5, #-0x10]
 *   @0x24c638 cmp r3, #0
 *   @0x24c63c beq 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x24c640 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x24c644 ldr r1, [r5, #-0x10]
 *   @0x24c648 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x24c64c b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x24c650 ldr r3, [r5, #-0x10]
 *   @0x24c654 cmp r3, #0
 *   @0x24c658 str r3, [r4, #-0x10]
 *   @0x24c65c beq 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x24c660 ldr r1, [r3, #0x8]
 *   @0x24c664 ldr r2, [r3]
 *   @0x24c668 cmp r1, #0
 *   @0x24c66c streq r7, [r3, #0x8]
 *   @0x24c670 add r2, r2, #1
 *   @0x24c674 str r2, [r3]
 *   @0x24c678 b 0x24c5fc <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x110>
 *   @0x24c67c ldr r3, [r5, #-0x10]
 *   @0x24c680 cmp r3, #0
 *   @0x24c684 ldrne r2, [r3, #0x4]
 *   @0x24c688 addne r2, r2, #1
 *   @0x24c68c strne r2, [r3, #0x4]
 *   @0x24c690 b 0x24c5f8 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x24c694 ldr r11, [r4, #-0x10]
 *   @0x24c698 cmp r11, #0
 *   @0x24c69c beq 0x24c590 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x24c6a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24c6a4 ldr r2, [r11, #0x4]
 *   @0x24c6a8 sub r2, r2, #1
 *   @0x24c6ac str r2, [r11, #0x4]
 *   @0x24c6b0 cmp r2, #0
 *   @0x24c6b4 beq 0x24c6c0 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x24c6b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24c6bc b 0x24c590 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x24c6c0 ldr r0, [r11]
 *   @0x24c6c4 str r2, [sp, #0xc]
 *   @0x24c6c8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24c6cc ldr r2, [sp, #0xc]
 *   @0x24c6d0 str r2, [r11]
 *   @0x24c6d4 str r2, [r11, #0x8]
 *   @0x24c6d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24c6dc ldr r2, [r11, #0x4]
 *   @0x24c6e0 sub r2, r2, #1
 *   @0x24c6e4 str r2, [r11, #0x4]
 *   @0x24c6e8 cmp r2, #0
 *   @0x24c6ec beq 0x24c70c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x24c6f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24c6f4 mov r0, r11
 *   @0x24c6f8 bl 0x27d1d0 <_ZdlPv>
 *   @0x24c6fc b 0x24c6b8 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x24c700 mov r0, r7
 *   @0x24c704 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24c708 b 0x24c584 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x24c70c ldr r0, [r11]
 *   @0x24c710 str r2, [sp, #0xc]
 *   @0x24c714 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24c718 ldr r2, [sp, #0xc]
 *   @0x24c71c str r2, [r11]
 *   @0x24c720 str r2, [r11, #0x8]
 *   @0x24c724 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24c728 ldr r2, [r11, #0x4]
 *   @0x24c72c sub r2, r2, #1
 *   @0x24c730 str r2, [r11, #0x4]
 *   @0x24c734 cmp r2, #0
 *   @0x24c738 beq 0x24c74c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x260>
 *   @0x24c73c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24c740 mov r0, r11
 *   @0x24c744 bl 0x27d1d0 <_ZdlPv>
 *   @0x24c748 b 0x24c6f0 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x24c74c ldr r0, [r11]
 *   @0x24c750 str r2, [sp, #0xc]
 *   @0x24c754 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24c758 ldr r2, [sp, #0xc]
 *   @0x24c75c str r2, [r11]
 *   @0x24c760 str r2, [r11, #0x8]
 *   @0x24c764 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24c768 ldr r2, [r11, #0x4]
 *   @0x24c76c sub r2, r2, #1
 *   @0x24c770 str r2, [r11, #0x4]
 *   @0x24c774 cmp r2, #0
 *   @0x24c778 beq 0x24c798 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x2ac>
 *   @0x24c77c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24c780 mov r0, r11
 *   @0x24c784 bl 0x27d1d0 <_ZdlPv>
 *   @0x24c788 b 0x24c73c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x250>
 *   @0x24c78c mov r1, #1
 *   @0x24c790 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24c794 b 0x24c524 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x38>
 *   @0x24c798 ldr r0, [r11]
 *   @0x24c79c str r2, [sp, #0xc]
 *   @0x24c7a0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24c7a4 ldr r2, [sp, #0xc]
 *   @0x24c7a8 str r2, [r11]
 *   @0x24c7ac str r2, [r11, #0x8]
 *   @0x24c7b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24c7b4 ldr r2, [r11, #0x4]
 *   @0x24c7b8 sub r2, r2, #1
 *   @0x24c7bc str r2, [r11, #0x4]
 *   @0x24c7c0 cmp r2, #0
 *   @0x24c7c4 beq 0x24c7d8 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x2ec>
 *   @0x24c7c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24c7cc mov r0, r11
 *   @0x24c7d0 bl 0x27d1d0 <_ZdlPv>
 *   @0x24c7d4 b 0x24c77c <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x290>
 *   @0x24c7d8 ldr r0, [r11]
 *   @0x24c7dc str r2, [sp, #0xc]
 *   @0x24c7e0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24c7e4 ldr r2, [sp, #0xc]
 *   @0x24c7e8 str r2, [r11]
 *   @0x24c7ec str r2, [r11, #0x8]
 *   @0x24c7f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24c7f4 ldr r2, [r11, #0x4]
 *   @0x24c7f8 sub r2, r2, #1
 *   @0x24c7fc str r2, [r11, #0x4]
 *   @0x24c800 cmp r2, #0
 *   @0x24c804 beq 0x24c818 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x32c>
 *   @0x24c808 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24c80c mov r0, r11
 *   @0x24c810 bl 0x27d1d0 <_ZdlPv>
 *   @0x24c814 b 0x24c7c8 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x2dc>
 *   @0x24c818 ldr r0, [r11]
 *   @0x24c81c str r2, [sp, #0xc]
 *   @0x24c820 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24c824 ldr r2, [sp, #0xc]
 *   @0x24c828 mov r0, r11
 *   @0x24c82c str r2, [r11]
 *   @0x24c830 str r2, [r11, #0x8]
 *   @0x24c834 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x24c838 mov r0, r11
 *   @0x24c83c bl 0x27d1d0 <_ZdlPv>
 *   @0x24c840 b 0x24c808 <_Z12F_JSNewArrayR6RValueP9CInstanceS2_iPS_+0x31c>
 *
 * ══ §8/36 GenerateMips(Texture*, int, int, int, char*)  0x181db0  size 852  213 条（0x181db0..0x182104）
 * @func 0x181db0 0x182104  size 852  213 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / GenerateMips(Texture*, int, int, int, char*)+0x164×2 / __divsi3 / __aeabi_idivmod / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x18×10 / 0x20×6 / 0x34×4 / 0x30×4 / 0x28×4 / 0x4×4 / 0x38×3 / 0x2c×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x181db0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x181db4 mov r4, r2
 *   @0x181db8 add r2, r1, r1, lsr #31
 *   @0x181dbc sub sp, sp, #76
 *   @0x181dc0 mov r6, r1
 *   @0x181dc4 add r1, r4, r4, lsr #31
 *   @0x181dc8 asrs r7, r2, #1
 *   @0x181dcc str r0, [sp, #0x3c]
 *   @0x181dd0 ldr r8, [pc, #0x324]
 *   @0x181dd4 mov r2, #70
 *   @0x181dd8 moveq r7, #1
 *   @0x181ddc asrs r1, r1, #1
 *   @0x181de0 mul r0, r3, r7
 *   @0x181de4 moveq r1, #1
 *   @0x181de8 str r1, [sp, #0x18]
 *   @0x181dec add r8, pc, r8
 *   @0x181df0 ldr r12, [sp, #0x18]
 *   @0x181df4 mov r3, #1
 *   @0x181df8 mov r1, r8
 *   @0x181dfc ldr r5, [sp, #0x70]
 *   @0x181e00 mul r9, r12, r0
 *   @0x181e04 mov r0, r9
 *   @0x181e08 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x181e0c mov r1, r8
 *   @0x181e10 mov r2, #70
 *   @0x181e14 mov r3, #1
 *   @0x181e18 str r0, [sp, #0x34]
 *   @0x181e1c mov r0, r9
 *   @0x181e20 ldr r12, [sp, #0x34]
 *   @0x181e24 str r12, [sp, #0x40]
 *   @0x181e28 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x181e2c cmp r4, #1
 *   @0x181e30 cmpeq r6, #1
 *   @0x181e34 str r0, [sp, #0x38]
 *   @0x181e38 str r0, [sp, #0x44]
 *   @0x181e3c beq 0x1820d4 <_Z12GenerateMipsP7TextureiiiPc+0x324>
 *   @0x181e40 ldr r12, [pc, #0x2b8]
 *   @0x181e44 str r12, [sp, #0x30]
 *   @0x181e48 mov r12, #0
 *   @0x181e4c str r12, [sp, #0x28]
 *   @0x181e50 ldr r12, [sp, #0x38]
 *   @0x181e54 str r12, [sp, #0x2c]
 *   @0x181e58 ldr r12, [sp, #0x30]
 *   @0x181e5c ldr r12, [pc, r12]
 *   @0x181e60 str r12, [sp, #0x30]
 *   @0x181e64 ldr r12, [sp, #0x34]
 *   @0x181e68 str r12, [sp, #0x20]
 *   @0x181e6c mov r12, #1
 *   @0x181e70 str r12, [sp, #0x24]
 *   @0x181e74 cmp r6, #1
 *   @0x181e78 cmpne r4, #1
 *   @0x181e7c movne r4, #0
 *   @0x181e80 moveq r4, #1
 *   @0x181e84 bne 0x181fc8 <_Z12GenerateMipsP7TextureiiiPc+0x218>
 *   @0x181e88 ldr r12, [sp, #0x18]
 *   @0x181e8c cmp r12, #0
 *   @0x181e90 ble 0x181f14 <_Z12GenerateMipsP7TextureiiiPc+0x164>
 *   @0x181e94 ldr r12, [sp, #0x20]
 *   @0x181e98 sub r1, r12, #4
 *   @0x181e9c ldr r12, [sp, #0x18]
 *   @0x181ea0 add r6, r5, r12, lsl #3
 *   @0x181ea4 ldr r3, [r5]
 *   @0x181ea8 add r5, r5, #8
 *   @0x181eac ldr r2, [r5, #-0x4]
 *   @0x181eb0 cmp r5, r6
 *   @0x181eb4 and r4, r3, #65280
 *   @0x181eb8 and r12, r3, #16711680
 *   @0x181ebc and r0, r2, #16711680
 *   @0x181ec0 and lr, r2, #65280
 *   @0x181ec4 add lr, r4, lr
 *   @0x181ec8 add r12, r12, r0
 *   @0x181ecc asr r4, r3, #8
 *   @0x181ed0 asr r0, r2, #8
 *   @0x181ed4 and r4, r4, #16711680
 *   @0x181ed8 and r0, r0, #16711680
 *   @0x181edc asr lr, lr, #1
 *   @0x181ee0 asr r12, r12, #1
 *   @0x181ee4 uxtb r2, r2
 *   @0x181ee8 add r0, r4, r0
 *   @0x181eec and lr, lr, #65280
 *   @0x181ef0 and r12, r12, #16711680
 *   @0x181ef4 uxtab r3, r2, r3
 *   @0x181ef8 orr r12, lr, r12
 *   @0x181efc lsl r0, r0, #7
 *   @0x181f00 orr r3, r12, r3, lsr #1
 *   @0x181f04 and r0, r0, #-16777216
 *   @0x181f08 orr r3, r3, r0
 *   @0x181f0c str r3, [r1, #0x4]!
 *   @0x181f10 bne 0x181ea4 <_Z12GenerateMipsP7TextureiiiPc+0xf4>
 *   @0x181f14 ldr r12, [sp, #0x18]
 *   @0x181f18 mov lr, #0
 *   @0x181f1c str lr, [sp, #0x4]
 *   @0x181f20 movw r2, #0x1908
 *   @0x181f24 ldr lr, [sp, #0x30]
 *   @0x181f28 movw r3, #0x1401
 *   @0x181f2c str r12, [sp]
 *   @0x181f30 movw r0, #0xde1
 *   @0x181f34 ldr r12, [sp, #0x20]
 *   @0x181f38 ldr r1, [sp, #0x24]
 *   @0x181f3c str r2, [sp, #0x8]
 *   @0x181f40 str r3, [sp, #0xc]
 *   @0x181f44 mov r3, r7
 *   @0x181f48 str r12, [sp, #0x10]
 *   @0x181f4c add r12, r1, #1
 *   @0x181f50 str r12, [sp, #0x24]
 *   @0x181f54 ldr r12, [lr]
 *   @0x181f58 blx r12
 *   @0x181f5c ldr r12, [sp, #0x18]
 *   @0x181f60 add r3, r7, r7, lsr #31
 *   @0x181f64 add r2, r12, r12, lsr #31
 *   @0x181f68 asrs r3, r3, #1
 *   @0x181f6c ldr r12, [sp, #0x28]
 *   @0x181f70 moveq r3, #1
 *   @0x181f74 asrs r2, r2, #1
 *   @0x181f78 eor r1, r12, #1
 *   @0x181f7c ldr r12, [sp, #0x18]
 *   @0x181f80 moveq r2, #1
 *   @0x181f84 cmp r7, #1
 *   @0x181f88 cmpeq r12, #1
 *   @0x181f8c beq 0x1820d4 <_Z12GenerateMipsP7TextureiiiPc+0x324>
 *   @0x181f90 ldr r12, [sp, #0x28]
 *   @0x181f94 add lr, sp, #72
 *   @0x181f98 ldr r5, [sp, #0x20]
 *   @0x181f9c mov r6, r7
 *   @0x181fa0 ldr r4, [sp, #0x18]
 *   @0x181fa4 mov r7, r3
 *   @0x181fa8 add r0, lr, r12, lsl #2
 *   @0x181fac ldr r12, [sp, #0x2c]
 *   @0x181fb0 str r1, [sp, #0x28]
 *   @0x181fb4 ldr r0, [r0, #-0x8]
 *   @0x181fb8 str r12, [sp, #0x20]
 *   @0x181fbc str r2, [sp, #0x18]
 *   @0x181fc0 str r0, [sp, #0x2c]
 *   @0x181fc4 b 0x181e74 <_Z12GenerateMipsP7TextureiiiPc+0xc4>
 *   @0x181fc8 ldr r2, [sp, #0x18]
 *   @0x181fcc mul r2, r2, r7
 *   @0x181fd0 cmp r2, #0
 *   @0x181fd4 str r2, [sp, #0x1c]
 *   @0x181fd8 ble 0x181f14 <_Z12GenerateMipsP7TextureiiiPc+0x164>
 *   @0x181fdc ldr r12, [sp, #0x20]
 *   @0x181fe0 sub r8, r12, #4
 *   @0x181fe4 mov r0, r4
 *   @0x181fe8 mov r1, r7
 *   @0x181fec bl 0x318d10 <__divsi3>
 *   @0x181ff0 mov r1, r7
 *   @0x181ff4 mul r9, r6, r0
 *   @0x181ff8 mov r0, r4
 *   @0x181ffc bl 0x318dec <__aeabi_idivmod>
 *   @0x182000 ldr r2, [sp, #0x1c]
 *   @0x182004 add r4, r4, #1
 *   @0x182008 cmp r4, r2
 *   @0x18200c add r1, r9, r1
 *   @0x182010 lsl r1, r1, #1
 *   @0x182014 add r3, r1, r6
 *   @0x182018 add r2, r1, #1
 *   @0x18201c ldr r0, [r5, r1, lsl #2]
 *   @0x182020 ldr r12, [r5, r2, lsl #2]
 *   @0x182024 add lr, r5, r3, lsl #2
 *   @0x182028 ldr r2, [r5, r3, lsl #2]
 *   @0x18202c and r9, r0, #65280
 *   @0x182030 ldr r3, [lr, #0x4]
 *   @0x182034 and r1, r12, #65280
 *   @0x182038 and lr, r12, #16711680
 *   @0x18203c and r11, r0, #16711680
 *   @0x182040 add r1, r9, r1
 *   @0x182044 and r9, r2, #65280
 *   @0x182048 add r11, r11, lr
 *   @0x18204c add r1, r1, r9
 *   @0x182050 and lr, r2, #16711680
 *   @0x182054 and r9, r3, #65280
 *   @0x182058 add r11, r11, lr
 *   @0x18205c add r1, r1, r9
 *   @0x182060 asr lr, r12, #8
 *   @0x182064 asr r9, r0, #8
 *   @0x182068 and r9, r9, #16711680
 *   @0x18206c and lr, lr, #16711680
 *   @0x182070 and r10, r3, #16711680
 *   @0x182074 add lr, r9, lr
 *   @0x182078 asr r9, r2, #8
 *   @0x18207c add r10, r11, r10
 *   @0x182080 uxtb r12, r12
 *   @0x182084 asr r11, r3, #8
 *   @0x182088 and r9, r9, #16711680
 *   @0x18208c uxtab r0, r12, r0
 *   @0x182090 and r11, r11, #16711680
 *   @0x182094 add lr, lr, r9
 *   @0x182098 asr r1, r1, #2
 *   @0x18209c asr r10, r10, #2
 *   @0x1820a0 uxtab r0, r0, r2
 *   @0x1820a4 add r12, lr, r11
 *   @0x1820a8 and r1, r1, #65280
 *   @0x1820ac and r10, r10, #16711680
 *   @0x1820b0 uxtab r3, r0, r3
 *   @0x1820b4 orr r1, r1, r10
 *   @0x1820b8 lsl r12, r12, #6
 *   @0x1820bc orr r3, r1, r3, lsr #2
 *   @0x1820c0 and r12, r12, #-16777216
 *   @0x1820c4 orr r3, r3, r12
 *   @0x1820c8 str r3, [r8, #0x4]!
 *   @0x1820cc bne 0x181fe4 <_Z12GenerateMipsP7TextureiiiPc+0x234>
 *   @0x1820d0 b 0x181f14 <_Z12GenerateMipsP7TextureiiiPc+0x164>
 *   @0x1820d4 ldr r12, [sp, #0x3c]
 *   @0x1820d8 ldr r0, [sp, #0x34]
 *   @0x1820dc ldr r3, [r12, #0x10]
 *   @0x1820e0 orr r3, r3, #32
 *   @0x1820e4 str r3, [r12, #0x10]
 *   @0x1820e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1820ec ldr r0, [sp, #0x38]
 *   @0x1820f0 add sp, sp, #76
 *   @0x1820f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1820f8 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1820fc andseq pc, r10, r4, asr #4
 *   @0x182100 eoreq r11, r6, r0, lsr #18
 *
 * ══ §9/36 CSprite::DrawGeneral(int, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)  0x1e5fa8  size 852  206 条（0x1e5fa8..0x1e62fc）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1e5fa8 0x1e62fc  size 852  206 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1e6004→0x3f50dc, 0x1e6070→0x7530c9, 0x1e608c→0x5425b0, 0x1e61bc→0x5428e8, 0x1e61d0→0x48f78c, 0x1e6204→0x3eb70c, 0x1e62b0→0x3eb70c
 * 调用序列: CSprite::DrawGeneral(int, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)+0x214×4 / CCameraManager::GetActiveCamera()×2 / CSprite::DrawGeneral(int, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)+0x208 / __aeabi_idivmod / YYGML_degtorad(double) / 0xb658c / 0xb6580 / GR_Texture_Draw_Part_Color(YYTPageEntry*, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)
 * 字段偏移 top8: 0x18×3 / 0x2×2 / 0x8c×2 / 0x90×2 / 0x94×2 / 0x1c×2 / 0x98×2 / 0x20×2
 * VFP 指令 94 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e5fa8 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1e5fac vpush {d8, d9, d10, d11}
 *   @0x1e5fb0 mov r5, r0
 *   @0x1e5fb4 ldr r6, [r0, #0x18]
 *   @0x1e5fb8 sub sp, sp, #52
 *   @0x1e5fbc ldr r4, [pc, #0x314]
 *   @0x1e5fc0 mov r8, r2
 *   @0x1e5fc4 cmp r6, #0
 *   @0x1e5fc8 mov r9, r3
 *   @0x1e5fcc add r4, pc, r4
 *   @0x1e5fd0 vldr s16, [sp, #112]
 *   @0x1e5fd4 vldr s17, [sp, #116]
 *   @0x1e5fd8 vldr s18, [sp, #128]
 *   @0x1e5fdc vldr s19, [sp, #132]
 *   @0x1e5fe0 ble 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208>
 *   @0x1e5fe4 mov r0, r1
 *   @0x1e5fe8 mov r1, r6
 *   @0x1e5fec bl 0x318dec <__aeabi_idivmod>
 *   @0x1e5ff0 ldr r0, [r5, #0x74]
 *   @0x1e5ff4 subs r7, r1, #0
 *   @0x1e5ff8 addlt r7, r7, r6
 *   @0x1e5ffc cmp r0, #0
 *   @0x1e6000 bne 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208>
 *   @0x1e6004 ldr r3, [pc, #0x2d0]
 *   @0x1e6008 ldr r3, [r4, r3]
 *   @0x1e600c ldrb r3, [r3]
 *   @0x1e6010 cmp r3, #0
 *   @0x1e6014 bne 0x1e6228 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x280>
 *   @0x1e6018 vldr s13, [sp, #136]
 *   @0x1e601c vcvt.f64.f32 d6, s13
 *   @0x1e6020 vmov r0, r1, d6
 *   @0x1e6024 bl 0x111070 <_Z14YYGML_degtoradd>
 *   @0x1e6028 vmov d7, r0, r1
 *   @0x1e602c vcvt.f32.f64 s20, d7
 *   @0x1e6030 vmov r0, s20
 *   @0x1e6034 bl 0xb658c <cosf@plt>
 *   @0x1e6038 vmov s21, r0
 *   @0x1e603c vmov r0, s20
 *   @0x1e6040 bl 0xb6580 <sinf@plt>
 *   @0x1e6044 vmul.f32 s15, s17, s17
 *   @0x1e6048 vmla.f32 s15, s16, s16
 *   @0x1e604c vmov s22, r0
 *   @0x1e6050 vsqrt.f32 s14, s15
 *   @0x1e6054 vcmpe.f32 s18, s19
 *   @0x1e6058 vmrs APSR_nzcv, fpscr
 *   @0x1e605c vcmp.f32 s14, s14
 *   @0x1e6060 vmovle.f32 s20, s19
 *   @0x1e6064 vmovgt.f32 s20, s18
 *   @0x1e6068 vmrs APSR_nzcv, fpscr
 *   @0x1e606c bne 0x1e62c0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x318>
 *   @0x1e6070 ldr r3, [pc, #0x268]
 *   @0x1e6074 ldr r3, [r4, r3]
 *   @0x1e6078 ldrb r3, [r3]
 *   @0x1e607c cmp r3, #0
 *   @0x1e6080 bne 0x1e612c <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x184>
 *   @0x1e6084 vmul.f32 s13, s21, s17
 *   @0x1e6088 vldr s11, [sp, #124]
 *   @0x1e608c ldr r3, [pc, #0x250]
 *   @0x1e6090 ldr r3, [r4, r3]
 *   @0x1e6094 vmov.f32 s15, #5.000000e-01
 *   @0x1e6098 vmul.f32 s12, s22, s16
 *   @0x1e609c vmul.f32 s13, s13, s15
 *   @0x1e60a0 vnmls.f32 s13, s12, s15
 *   @0x1e60a4 vmls.f32 s11, s20, s13
 *   @0x1e60a8 vmul.f32 s14, s20, s14
 *   @0x1e60ac vmov.f32 s13, s11
 *   @0x1e60b0 vldr s11, [r3, #4]
 *   @0x1e60b4 vcvt.f32.s32 s12, s11
 *   @0x1e60b8 vmul.f32 s14, s14, s15
 *   @0x1e60bc vsub.f32 s12, s12, s13
 *   @0x1e60c0 vcmpe.f32 s14, s12
 *   @0x1e60c4 vmrs APSR_nzcv, fpscr
 *   @0x1e60c8 blt 0x1e61bc <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x214>
 *   @0x1e60cc vldr s11, [r3, #12]
 *   @0x1e60d0 vcvt.f32.s32 s12, s11
 *   @0x1e60d4 vsub.f32 s13, s13, s12
 *   @0x1e60d8 vcmpe.f32 s14, s13
 *   @0x1e60dc vmrs APSR_nzcv, fpscr
 *   @0x1e60e0 blt 0x1e61bc <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x214>
 *   @0x1e60e4 vmul.f32 s22, s22, s17
 *   @0x1e60e8 vldr s12, [r3]
 *   @0x1e60ec vmul.f32 s22, s22, s15
 *   @0x1e60f0 vmul.f32 s21, s21, s16
 *   @0x1e60f4 vmla.f32 s22, s21, s15
 *   @0x1e60f8 vldr s15, [sp, #120]
 *   @0x1e60fc vmla.f32 s15, s20, s22
 *   @0x1e6100 vcvt.f32.s32 s13, s12
 *   @0x1e6104 vsub.f32 s13, s13, s15
 *   @0x1e6108 vcmpe.f32 s14, s13
 *   @0x1e610c vmrs APSR_nzcv, fpscr
 *   @0x1e6110 blt 0x1e61bc <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x214>
 *   @0x1e6114 vldr s13, [r3, #8]
 *   @0x1e6118 vcvt.f32.s32 s13, s13
 *   @0x1e611c vsub.f32 s15, s15, s13
 *   @0x1e6120 vcmpe.f32 s14, s15
 *   @0x1e6124 vmrs APSR_nzcv, fpscr
 *   @0x1e6128 blt 0x1e61bc <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x214>
 *   @0x1e612c ldr r3, [r5, #0x54]
 *   @0x1e6130 cmp r3, #0
 *   @0x1e6134 beq 0x1e6230 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x288>
 *   @0x1e6138 vldr s13, [sp, #136]
 *   @0x1e613c vldr s15, [pc, #396]
 *   @0x1e6140 vmul.f32 s15, s13, s15
 *   @0x1e6144 vldr s14, [pc, #392]
 *   @0x1e6148 ldr r0, [r3, r7, lsl #2]
 *   @0x1e614c vldr s11, [sp, #120]
 *   @0x1e6150 ldr r2, [sp, #0x8c]
 *   @0x1e6154 vstr s11, [sp, #4]
 *   @0x1e6158 ldr r3, [sp, #0x90]
 *   @0x1e615c vldr s12, [sp, #124]
 *   @0x1e6160 vldr s11, [sp, #156]
 *   @0x1e6164 mov r1, r8
 *   @0x1e6168 str r2, [sp, #0x18]
 *   @0x1e616c vstr s17, [sp]
 *   @0x1e6170 ldr r2, [sp, #0x94]
 *   @0x1e6174 vstr s12, [sp, #8]
 *   @0x1e6178 str r3, [sp, #0x1c]
 *   @0x1e617c vstr s18, [sp, #12]
 *   @0x1e6180 ldr r3, [sp, #0x98]
 *   @0x1e6184 vstr s19, [sp, #16]
 *   @0x1e6188 str r2, [sp, #0x20]
 *   @0x1e618c vstr s11, [sp, #40]
 *   @0x1e6190 mov r2, r9
 *   @0x1e6194 str r3, [sp, #0x24]
 *   @0x1e6198 vdiv.f32 s15, s15, s14
 *   @0x1e619c vmov r3, s16
 *   @0x1e61a0 vstr s15, [sp, #20]
 *   @0x1e61a4 bl 0x175a90 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf>
 *   @0x1e61a8 cmp r0, #0
 *   @0x1e61ac beq 0x1e6200 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x258>
 *   @0x1e61b0 add sp, sp, #52
 *   @0x1e61d0 ldr r3, [pc, #0x114]
 *   @0x1e61d4 ldr r6, [r4, r3]
 *   @0x1e61d8 mov r0, r6
 *   @0x1e61dc bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv>
 *   @0x1e61e0 cmp r0, #0
 *   @0x1e61e4 beq 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208>
 *   @0x1e61e8 mov r0, r6
 *   @0x1e61ec bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv>
 *   @0x1e61f0 bl 0x16d398 <_ZN7CCamera4Is2DEv>
 *   @0x1e61f4 cmp r0, #0
 *   @0x1e61f8 bne 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208>
 *   @0x1e61fc b 0x1e612c <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x184>
 *   @0x1e6200 ldr r1, [pc, #0xe8]
 *   @0x1e6204 ldr r3, [pc, #0xe8]
 *   @0x1e6208 ldr r2, [r5, #0x5c]
 *   @0x1e620c add r1, pc, r1
 *   @0x1e6210 ldr r3, [r4, r3]
 *   @0x1e6214 ldr r0, [r3]
 *   @0x1e6218 ldr r3, [r0]
 *   @0x1e621c ldr r3, [r3, #0xc]
 *   @0x1e6220 blx r3
 *   @0x1e6224 b 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208>
 *   @0x1e6228 bl 0x168d94 <_Z22UpdateTransRoomExtentsv>
 *   @0x1e622c b 0x1e6018 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x70>
 *   @0x1e6230 vldr s11, [sp, #136]
 *   @0x1e6234 vldr s14, [pc, #148]
 *   @0x1e6238 vmul.f32 s14, s11, s14
 *   @0x1e623c vldr s15, [pc, #144]
 *   @0x1e6240 ldr r3, [r5, #0x50]
 *   @0x1e6244 vldr s12, [sp, #120]
 *   @0x1e6248 vldr s13, [sp, #124]
 *   @0x1e624c vldr s11, [sp, #156]
 *   @0x1e6250 mov r1, r8
 *   @0x1e6254 mov r2, r9
 *   @0x1e6258 ldr r0, [r3, r7, lsl #2]
 *   @0x1e625c vstr s17, [sp]
 *   @0x1e6260 ldr r3, [sp, #0x8c]
 *   @0x1e6264 vstr s12, [sp, #4]
 *   @0x1e6268 vstr s13, [sp, #8]
 *   @0x1e626c vstr s18, [sp, #12]
 *   @0x1e6270 vstr s19, [sp, #16]
 *   @0x1e6274 vstr s11, [sp, #40]
 *   @0x1e6278 str r3, [sp, #0x18]
 *   @0x1e627c ldr r3, [sp, #0x90]
 *   @0x1e6280 vdiv.f32 s15, s14, s15
 *   @0x1e6284 str r3, [sp, #0x1c]
 *   @0x1e6288 ldr r3, [sp, #0x94]
 *   @0x1e628c str r3, [sp, #0x20]
 *   @0x1e6290 ldr r3, [sp, #0x98]
 *   @0x1e6294 str r3, [sp, #0x24]
 *   @0x1e6298 vmov r3, s16
 *   @0x1e629c vstr s15, [sp, #20]
 *   @0x1e62a0 bl 0x175834 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf>
 *   @0x1e62a4 cmp r0, #0
 *   @0x1e62a8 bne 0x1e61b0 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x208>
 *   @0x1e62ac ldr r1, [pc, #0x44]
 *   @0x1e62b0 ldr r3, [pc, #0x3c]
 *   @0x1e62b4 ldr r2, [r5, #0x5c]
 *   @0x1e62b8 add r1, pc, r1
 *   @0x1e62bc b 0x1e6210 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0x268>
 *   @0x1e62c0 vmov r0, s15
 *   @0x1e62c4 bl 0xb6700 <sqrtf@plt>
 *   @0x1e62c8 vmov s14, r0
 *   @0x1e62cc b 0x1e6070 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf+0xc8>
 *   @0x1e62d0 ldrdmi r0, r1, [r9], #-251
 *   @0x1e62d4 teqmi r4, #0
 *   @0x1e62d8 eoreq r11, r0, r4, lsl #25
 *   @0x1e62dc .word 0xffffd9e0
 *   @0x1e62e0 .word 0xffffe490
 *   @0x1e62e4 .word 0xffffe500
 *   @0x1e62e8 .word 0xffffbcd4
 *   @0x1e62ec .word 0xffffc024
 *   @0x1e62f0 andseq r12, r6, r8, lsl #7
 *   @0x1e62f4 .word 0xffffbac4
 *   @0x1e62f8 ldrsbeq r12, [r6], -r12
 *
 * ══ §10/36 JS_String_prototype_match(RValue&, CInstance*, CInstance*, int, RValue*)  0x256398  size 852  211 条（0x256398..0x2566ec）
 * @func 0x256398 0x2566ec  size 852  211 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×2 / JS_RegExp_prototype_exec(RValue&, CInstance*, CInstance*, int, RValue*)×2 / JS_Object_Put(YYObjectBase*, RValue*, char const*, bool)×2 / JS_CheckObjectCoercible(RValue&) / F_JS_ToString(RValue&, RValue*) / JS_String_prototype_match(RValue&, CInstance*, CInstance*, int, RValue*)+0x10c / JS_RegExp(RValue&, CInstance*, CInstance*, int, RValue*) / JSThrowTypeError(char const*)
 * 字段偏移 top8: 0x14×5 / 0xc×5 / 0x98×3 / 0x9c×3 / 0x40×2 / 0x6c×2 / 0x7c×2 / 0x18×2
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x256398 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25639c vpush {d8}
 *   @0x2563a0 sub sp, sp, #164
 *   @0x2563a4 add r6, sp, #160
 *   @0x2563a8 mov r5, r1
 *   @0x2563ac str r0, [sp, #0x14]
 *   @0x2563b0 mov r9, r2
 *   @0x2563b4 str r1, [r6, #-0x80]!
 *   @0x2563b8 mov r0, r6
 *   @0x2563bc mov r4, r3
 *   @0x2563c0 ldr r7, [sp, #0xd0]
 *   @0x2563c4 mov r3, #6
 *   @0x2563c8 str r3, [sp, #0x2c]
 *   @0x2563cc bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue>
 *   @0x2563d0 cmp r0, #1
 *   @0x2563d4 beq 0x25648c <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x2563d8 mov r1, r6
 *   @0x2563dc add r0, sp, #48
 *   @0x2563e0 add r2, sp, #48
 *   @0x2563e4 mov r3, #0
 *   @0x2563e8 str r2, [sp, #0x10]
 *   @0x2563ec mov r6, #0
 *   @0x2563f0 mov r2, #0
 *   @0x2563f4 str r6, [sp, #0x38]
 *   @0x2563f8 strd r2, r3, [sp, #48]
 *   @0x2563fc mvn r3, #-16777216
 *   @0x256400 str r3, [sp, #0x3c]
 *   @0x256404 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x256408 cmp r0, #1
 *   @0x25640c beq 0x25648c <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x256410 cmp r4, r6
 *   @0x256414 mov r3, #5
 *   @0x256418 str r6, [sp, #0x40]
 *   @0x25641c str r6, [sp, #0x44]
 *   @0x256420 str r6, [sp, #0x48]
 *   @0x256424 str r3, [sp, #0x4c]
 *   @0x256428 ble 0x2564a4 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x25642c ldr r3, [r7, #0xc]
 *   @0x256430 bic r3, r3, #-16777216
 *   @0x256434 cmp r3, #6
 *   @0x256438 beq 0x2564ac <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x25643c mov r3, #1
 *   @0x256440 str r7, [sp]
 *   @0x256444 add r0, sp, #144
 *   @0x256448 mov r1, r5
 *   @0x25644c mov r2, r9
 *   @0x256450 mov r12, #0
 *   @0x256454 mov r10, #0
 *   @0x256458 str r12, [sp, #0x98]
 *   @0x25645c mov r11, #0
 *   @0x256460 mvn r12, #-16777216
 *   @0x256464 strd r10, r11, [sp, #144]
 *   @0x256468 str r12, [sp, #0x9c]
 *   @0x25646c bl 0x259ea8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_>
 *   @0x256470 ldr r3, [sp, #0x9c]
 *   @0x256474 bic r3, r3, #-16777216
 *   @0x256478 cmp r3, #6
 *   @0x25647c beq 0x2566bc <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x324>
 *   @0x256480 add sp, sp, #164
 *   @0x256484 vpop {d8}
 *   @0x256488 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x25648c ldr r0, [pc, #0x244]
 *   @0x256490 add r0, pc, r0
 *   @0x256494 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x256498 add sp, sp, #164
 *   @0x25649c vpop {d8}
 *   @0x2564a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2564a4 add r7, sp, #64
 *   @0x2564a8 b 0x25643c <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x2564ac ldr r4, [r7]
 *   @0x2564b0 ldr r1, [pc, #0x224]
 *   @0x2564b4 ldr r0, [r4, #0x40]
 *   @0x2564b8 add r1, pc, r1
 *   @0x2564bc bl 0xb6574 <strcmp@plt>
 *   @0x2564c0 cmp r0, r6
 *   @0x2564c4 bne 0x25643c <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0x2564c8 add r8, sp, #80
 *   @0x2564cc ldr r2, [pc, #0x20c]
 *   @0x2564d0 mov r6, #0
 *   @0x2564d4 mov r0, r4
 *   @0x2564d8 add r2, pc, r2
 *   @0x2564dc mov r1, r8
 *   @0x2564e0 str r6, [sp, #0x50]
 *   @0x2564e4 str r6, [sp, #0x54]
 *   @0x2564e8 str r6, [sp, #0x58]
 *   @0x2564ec str r6, [sp, #0x5c]
 *   @0x2564f0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x2564f4 mov r0, r8
 *   @0x2564f8 mov r1, r6
 *   @0x2564fc bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x256500 cmp r0, r6
 *   @0x256504 bne 0x256530 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x256508 add r3, sp, #48
 *   @0x25650c mov r1, r4
 *   @0x256510 str r3, [sp]
 *   @0x256514 mov r2, r4
 *   @0x256518 ldr r0, [sp, #0x14]
 *   @0x25651c mov r3, #1
 *   @0x256520 bl 0x257248 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_>
 *   @0x256524 add sp, sp, #164
 *   @0x256528 vpop {d8}
 *   @0x25652c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x256530 vldr d8, [pc, #408]
 *   @0x256534 vmov r2, r3, d8
 *   @0x256538 add r8, sp, #160
 *   @0x25653c mov r0, r4
 *   @0x256540 str r6, [sp, #0x6c]
 *   @0x256544 mov r10, r6
 *   @0x256548 add r11, sp, #112
 *   @0x25654c strd r2, r3, [r8, #-64]!
 *   @0x256550 mov r3, r6
 *   @0x256554 ldr r2, [pc, #0x188]
 *   @0x256558 mov r1, r8
 *   @0x25655c add r2, pc, r2
 *   @0x256560 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x256564 mov r1, r5
 *   @0x256568 mov r2, r9
 *   @0x25656c mov r3, r6
 *   @0x256570 str r7, [sp]
 *   @0x256574 mov r5, r6
 *   @0x256578 ldr r0, [sp, #0x14]
 *   @0x25657c mov r9, r6
 *   @0x256580 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x256584 mvn r3, #-16777216
 *   @0x256588 str r3, [sp, #0x7c]
 *   @0x25658c mov r1, #0
 *   @0x256590 ldr r3, [pc, #0x150]
 *   @0x256594 str r6, [sp, #0x78]
 *   @0x256598 add r3, pc, r3
 *   @0x25659c str r1, [sp, #0x70]
 *   @0x2565a0 str r1, [sp, #0x18]
 *   @0x2565a4 str r1, [sp, #0x74]
 *   @0x2565a8 str r1, [sp, #0x1c]
 *   @0x2565ac str r3, [sp, #0xc]
 *   @0x2565b0 b 0x25662c <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x294>
 *   @0x2565b4 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x2565b8 mov r0, r8
 *   @0x2565bc bl 0xd11b0 <_Z12INT32_RValuePK6RValue>
 *   @0x2565c0 cmp r0, r10
 *   @0x2565c4 mov r12, r0
 *   @0x2565c8 beq 0x256688 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x2f0>
 *   @0x2565cc ldr r3, [sp, #0x18]
 *   @0x2565d0 mov r1, r7
 *   @0x2565d4 mov r2, r6
 *   @0x2565d8 mov r0, r11
 *   @0x2565dc str r9, [sp, #0x8c]
 *   @0x2565e0 vstr d8, [sp, #128]
 *   @0x2565e4 str r3, [sp, #0x90]
 *   @0x2565e8 mov r10, r12
 *   @0x2565ec ldr r3, [sp, #0x1c]
 *   @0x2565f0 str r9, [sp, #0x98]
 *   @0x2565f4 str r3, [sp, #0x94]
 *   @0x2565f8 mvn r3, #-16777216
 *   @0x2565fc str r3, [sp, #0x9c]
 *   @0x256600 bl 0x249cdc <_Z10JSArrayGetP6RValueS0_S0_>
 *   @0x256604 vmov s13, r5
 *   @0x256608 mov r1, r7
 *   @0x25660c mov r2, r6
 *   @0x256610 ldr r0, [sp, #0x14]
 *   @0x256614 vcvt.f64.s32 d7, s13
 *   @0x256618 mov r3, #7
 *   @0x25661c add r5, r5, #1
 *   @0x256620 str r3, [sp, #0x98]
 *   @0x256624 vstr d7, [sp, #128]
 *   @0x256628 bl 0x247c68 <_Z10JSArrayPutP6RValueS0_S0_>
 *   @0x25662c add r2, sp, #48
 *   @0x256630 mov r0, r11
 *   @0x256634 str r2, [sp]
 *   @0x256638 mov r1, r4
 *   @0x25663c mov r2, r4
 *   @0x256640 mov r3, #1
 *   @0x256644 bl 0x257248 <_Z24JS_RegExp_prototype_execR6RValueP9CInstanceS2_iPS_>
 *   @0x256648 ldr r3, [sp, #0x7c]
 *   @0x25664c add r7, sp, #128
 *   @0x256650 add r6, sp, #144
 *   @0x256654 bic r3, r3, #-16777216
 *   @0x256658 mov r1, r8
 *   @0x25665c cmp r3, #12
 *   @0x256660 ldr r2, [sp, #0xc]
 *   @0x256664 mov r0, r4
 *   @0x256668 bne 0x2565b4 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x21c>
 *   @0x25666c cmp r5, #0
 *   @0x256670 bne 0x256480 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x256674 ldr r2, [sp, #0x14]
 *   @0x256678 str r3, [r2, #0xc]
 *   @0x25667c add sp, sp, #164
 *   @0x256680 vpop {d8}
 *   @0x256684 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x256688 add r12, r10, #1
 *   @0x25668c mov r0, r4
 *   @0x256690 mov r1, r8
 *   @0x256694 ldr r2, [sp, #0xc]
 *   @0x256698 vmov s13, r12
 *   @0x25669c mov r3, #0
 *   @0x2566a0 str r12, [sp, #0x8]
 *   @0x2566a4 vcvt.f64.s32 d7, s13
 *   @0x2566a8 str r9, [sp, #0x6c]
 *   @0x2566ac vstr d7, [sp, #96]
 *   @0x2566b0 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x2566b4 ldr r12, [sp, #0x8]
 *   @0x2566b8 b 0x2565cc <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0x2566bc ldr r4, [sp, #0x90]
 *   @0x2566c0 cmp r4, #0
 *   @0x2566c4 bne 0x2564c8 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x2566c8 b 0x256480 <_Z25JS_String_prototype_matchR6RValueP9CInstanceS2_iPS_+0xe8>
 *   @0x2566cc nop
 *   @0x2566d8 strheq pc, [pc], -r8
 *   @0x2566dc andeq pc, pc, r4, ror r7
 *   @0x2566e0 andeq lr, sp, r0, lsl #20
 *   @0x2566e4 andeq pc, pc, r4, asr #22
 *   @0x2566e8 andeq pc, pc, r8, lsl #22
 *
 * ══ §11/36 anon_2e9398  0x2e9398  size 852  213 条（0x2e9398..0x2e96ec）
 * @func 0x2e9398 0x2e96ec  size 852  213 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x6513d0 / 0x70dfdc / 0x57abe4 / 0xb79e48 / 0x1ce73d0 / anon_30a7b2+0x5882 / 0x761724 / 0x585978
 * 字段偏移 top8: 无
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9398 bls 0x6513d0 <g_SWFaavertbuff+0x7e308>
 *   @0x2e939c .word 0xf7ff9b0e
 *   @0x2e93a0 stmdahs r0, {r0, r1, r3, r8, r11, r12, sp, lr, pc}
 *   @0x2e93a4 .word 0x810af040
 *   @0x2e93a8 strtmi r9, [r6], #-2831
 *   @0x2e93ac ldrls r4, [r1], #-678
 *   @0x2e93b0 blls 0x70dfdc <g_SWFvertbuff+0x3af14>
 *   @0x2e93b4 .word 0xf8d8930a
 *   @0x2e93b8 movwls r3, #0xb000
 *   @0x2e93bc rscshi pc, r2, r0, lsl #4
 *   @0x2e93c0 pkhbtmi r10, r1, r1, lsl #24
 *   @0x2e93c4 blls 0x57abe4 <g_SWFlineaavertbuff+0x27b1c>
 *   @0x2e93c8 ble 0xb79e48 <b2_toiTime+0x4209a4>
 *   @0x2e93cc strtmi r9, [r8], -r9, lsl #22
 *   @0x2e93d0 eorne pc, r6, r3, asr r8
 *   @0x2e93d4 blx 0x1ce73d0 <b2_toiTime+0x158df2c>
 *   @0x2e93d8 stmdahs r0, {r0, r4, r12, pc}
 *   @0x2e93dc rschi pc, r1, r0, asr #32
 *   @0x2e93e0 strtmi r4, [r1], -r8, lsr #12
 *   @0x2e93e4 stc2l p7, c15, [lr], #1012
 *   @0x2e93e8 blhs 0x310034 <af_shaper_get_elem+0x58a2>
 *   @0x2e93ec sbcshi pc, r9, r0, asr #32
 *   @0x2e93f0 svcvc #0x80f1b0
 *   @0x2e93f4 .word 0xf1c0d207
 *   @0x2e93f8 .word 0xf10913ff
 *   @0x2e93fc .word 0xf5030206
 *   @0x2e9400 addsmi r4, r3, #-67108863
 *   @0x2e9404 movwhs sp, #0x9201
 *   @0x2e9408 andlo lr, r6, r9
 *   @0x2e940c strmi r3, [r1], #1537
 *   @0x2e9410 .word 0xf109e7d9
 *   @0x2e9414 movwls r0, #0x5302
 *   @0x2e9418 stmdale r2, {r0, r2, r8, r9, r11, sp}
 *   @0x2e941c tstls r1, #671088640
 *   @0x2e9420 blge 0x761724 <b2_toiTime+0x8280>
 *   @0x2e9424 stmdbls r5, {r0, r1, r3, r11, r12, pc}
 *   @0x2e9428 movwls r4, #0x761a
 *   @0x2e942c mrc2 p7, #0x3, apsr_nzcv, c11, c13, #0x7
 *   @0x2e9430 .word 0x46049e11
 *   @0x2e9434 .word 0xf0402e00
 *   @0x2e9438 .word 0xf04f80b4
 *   @0x2e943c .word 0xf04f0b01
 *   @0x2e9440 .word 0xf8800a02
 *   @0x2e9444 strhs r11, [r6, -r1]
 *   @0x2e9448 andslt pc, r8, sp, asr #17
 *   @0x2e944c addhs r4, r0, #187695104
 *   @0x2e9450 andvc r7, r2, r6, lsl #1
 *   @0x2e9454 smlabtvc r6, r6, r0, r7
 *   @0x2e9458 blls 0x585978 <g_SWFlineaavertbuff+0x328b0>
 *   @0x2e945c ble 0x14baad0 <b2_toiTime+0xd6162c>
 *   @0x2e9460 strtmi r9, [r8], -r9, lsl #22
 *   @0x2e9464 eorne pc, r11, r3, asr r8
 *   @0x2e9468 blx 0xa67464 <b2_toiTime+0x30dfc0>
 *   @0x2e946c stmdahs r0, {r0, r4, r12, pc}
 *   @0x2e9470 addhi pc, pc, r0, asr #32
 *   @0x2e9474 qadd16mi r10, r8, r1
 *   @0x2e9478 stc2 p7, c15, [r4], #1012
 *   @0x2e947c .word 0x46029911
 *   @0x2e9480 .word 0xf0402900
 *   @0x2e9484 stmdahs r0, {r1, r2, r7, pc}
 *   @0x2e9488 movwhs sp, #0x9a02
 *   @0x2e948c add r9, r0, r1, lsl r3
 *   @0x2e9490 qadd16mi r10, r8, r1
 *   @0x2e9494 .word 0xf7fd9204
 *   @0x2e9498 ldmdbls r1, {r0, r2, r4, r5, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2e949c stmdbhs r0, {r2, r9, r11, r12, pc}
 *   @0x2e94a0 b 0x1adda84 <b2_toiTime+0x13845e0>
 *   @0x2e94a4 .word 0xf04f2c20
 *   @0x2e94a8 tstls r1, #671088640
 *   @0x2e94ac bhs 0x39d5e0 <ft_adobe_glyph_list+0xccbc>
 *   @0x2e94b0 svclt #0x8c9b06
 *   @0x2e94b4 strmi r3, [r10], -r2, lsl #20
 *   @0x2e94b8 swple r4, r12, [r2]
 *   @0x2e94bc shadd16mi r4, r9, r6
 *   @0x2e94c0 blls 0x46158c <g_RomDisk+0x69d6c>
 *   @0x2e94c4 mrseq pc, apsr
 *   @0x2e94c8 stmdale r2!, {r0, r3, r4, r7, r9, lr} ^
 *   @0x2e94cc andeq lr, r10, r4, lsl #22
 *   @0x2e94d0 svceq #0x5f1bc
 *   @0x2e94d4 andvs pc, r10, r4, lsl #16
 *   @0x2e94d8 vnmlahs.f32 s28, s12, s30
 *   @0x2e94dc and pc, r1, r0, lsl #17
 *   @0x2e94e0 vnmlami.f32 s28, s12, s30
 *   @0x2e94e4 and pc, r2, r0, lsl #17
 *   @0x2e94e8 andsvs lr, r6, pc, asr #20
 *   @0x2e94ec .word 0xd1065460
 *   @0x2e94f0 andhs r9, r10, #5120
 *   @0x2e94f4 ldcne p2, c9, [r10], #68
 *   @0x2e94f8 stmdale r10, {r1, r3, r4, r7, r9, lr} ^
 *   @0x2e94fc blls 0x4615ac <g_RomDisk+0x69d8c>
 *   @0x2e9500 addsmi r1, r9, #11840
 *   @0x2e9504 .word 0xf06fd845
 *   @0x2e9508 .word 0xf107037f
 *   @0x2e950c strbpl r0, [r3, #0xa02]!
 *   @0x2e9510 ldrmi r4, [r6], -r7, lsr #8
 *   @0x2e9514 movweq pc, #0x4f
 *   @0x2e9518 andgt pc, r1, r7, lsl #17
 *   @0x2e951c andlo pc, r10, r4, lsl #16
 *   @0x2e9520 ldrshvc r7, [r11, -r11]!
 *   @0x2e9524 strbmi r7, [r9, #-0x17b]
 *   @0x2e9528 stmne pc, {r0, r1, r4, r5, r11, r12, lr, pc}
 *   @0x2e952c ldmdale r0!, {r0, r1, r2, r3, r6, r8, r10, lr}
 *   @0x2e9530 strtmi r4, [r1], #-1576
 *   @0x2e9534 andsgt pc, r0, sp, asr #17
 *   @0x2e9538 blx 0xd67534 <b2_toiTime+0x60e090>
 *   @0x2e953c ldrsbgt pc, [r0], -sp
 *   @0x2e9540 tstlt r0, r1, lsl r0
 *   @0x2e9544 .word 0xf8dde025
 *   @0x2e9548 .word 0xf10bc018
 *   @0x2e954c .word 0xf8cd0b01
 *   @0x2e9550 usada8 r2, r8, r0, r12
 *   @0x2e9554 strbpl r2, [r1, #0x180]!
 *   @0x2e9558 blls 0x43a5fc <g_RomDisk+0x42ddc>
 *   @0x2e955c rsbsvc r2, r9, r3, lsl #2
 *   @0x2e9560 addsmi r4, r9, #1358954496
 *   @0x2e9564 bl 0x41f5c0 <g_RomDisk+0x27da0>
 *   @0x2e9568 .word 0xf804030a
 *   @0x2e956c beq 0xf0159c <b2_toiTime+0x7a80f8>
 *   @0x2e9570 ldceq p0, c7, [r0], #-352
 *   @0x2e9574 mrceq p0, #0x1, r7, c6, c8, #0x4
 *   @0x2e9578 strbmi r4, [r0], -r1, lsr #22
 *   @0x2e957c strtmi r5, [r1], -r6, ror #8
 *   @0x2e9580 movwls r4, #0x47b
 *   @0x2e9584 movwls r9, #0x1b1c
 *   @0x2e9588 .word 0xf7ff2300
 *   @0x2e958c .word 0x4604fdb7
 *   @0x2e9590 blls 0x7615b8 <b2_toiTime+0x8114>
 *   @0x2e9594 movwhs r11, #0x110b
 *   @0x2e9598 stmdals r11, {r0, r4, r8, r9, r12, pc}
 *   @0x2e959c .word 0xf7fd4621
 *   @0x2e95a0 .word 0x9c11feca
 *   @0x2e95a4 stmdbls pc, {r3, r11, r12, pc}
 *   @0x2e95a8 mcr2 p7, #0x6, pc, c5, c13, #0x7
 *   @0x2e95ac .word 0xf0402c00
 *   @0x2e95b0 bls 0xa09800 <b2_toiTime+0x2b035c>
 *   @0x2e95b4 andhs r6, r1, #1245184
 *   @0x2e95b8 add r6, r12, r10, lsl r0
 *   @0x2e95bc strbmi r4, [r0], -pc, lsl #22
 *   @0x2e95c0 andge pc, r12, sp, asr #17
 *   @0x2e95c4 bls 0x63ae70 <g_SWFaavertbuff+0x67da8>
 *   @0x2e95c8 stmeq r8, {r0, r2, r3, r7, r11, sp, lr, pc}
 *   @0x2e95cc .word 0xf7fe9b0e
 *   @0x2e95d0 stmdahs r0, {r0, r1, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2e95d4 svcls #0x10d17e
 *   @0x2e95d8 shasxmi r4, r9, r0
 *   @0x2e95dc .word 0xec06f02f
 *   @0x2e95e0 .word 0xf8d89b0f
 *   @0x2e95e4 b 0x1eb95ec <b2_toiTime+0x1760148>
 *   @0x2e95e8 strmi r0, [r10, #0xa01]
 *   @0x2e95ec selmi r11, r10, r8
 *   @0x2e95f0 blle 0x4bace0 <SrcVerts+0x17d24>
 *   @0x2e95f4 rsb r2, r1, r1, lsl #8
 *   @0x2e95f8 subpl r5, pc, r4, asr r3
 *   @0x2e95fc .word 0x73666e74
 *   @0x2e9600 andeq r5, r10, r1, lsl #4
 *   @0x2e9604 eorls pc, r10, r3, asr r8
 *   @0x2e9608 strbmi r4, [r9], -r8, lsr #12
 *   @0x2e960c .word 0xf94bf7fd
 *   @0x2e9610 stmdahs r0, {r0, r4, r12, pc}
 *   @0x2e9614 svcge #0x11d14d
 *   @0x2e9618 ldrtmi r4, [r9], -r8, lsr #12
 *   @0x2e961c blx 0xff7a761a <b2_toiTime+0xffffffffff04e176>
 *   @0x2e9620 .word 0x46069b11
 *   @0x2e9624 .word 0xd1442b00
 *   @0x2e9628 stclle p8, c2, [r3, #0]!
 *   @0x2e962c svcvc #0x80f1b0
 *   @0x2e9630 strbmi sp, [r0], -r1, asr #4
 *   @0x2e9634 ldrbmi r4, [r2], -r9, lsr #12
 *   @0x2e9638 .word 0xf7ff9b1c
 *   @0x2e963c ldrhls pc, [r1], -r3
 *   @0x2e9640 eorsle r2, r6, r0, lsl #16
 *   @0x2e9644 .word 0xf1094628
 *   @0x2e9648 .word 0xf7fd0104
 *   @0x2e964c andsls pc, r1, r12, lsr #18
 *   @0x2e9650 .word 0xd12e2800
 *   @0x2e9654 qasxmi r4, r0, r10
 *   @0x2e9658 .word 0xf7fd4631
 *   @0x2e965c blls 0x768bf4 <b2_toiTime+0xf750>
 *   @0x2e9660 bllt 0x17bae84 <b2_toiTime+0x10619e0>
 *   @0x2e9664 ldrtmi r4, [r9], -r8, lsr #12
 *   @0x2e9668 .word 0xf7fd4632
 *   @0x2e966c mulsls r1, r0, r9
 *   @0x2e9670 strtmi r11, [r0], -r0, lsr #2
 *   @0x2e9674 .word 0xf7fd4639
 *   @0x2e9678 ands pc, r10, lr, asr lr
 *   @0x2e967c stcle p14, c2, [r9, #-16]
 *   @0x2e9680 shadd16mi r4, r8, r7
 *   @0x2e9684 ldrbtmi r2, [r9], #-516
 *   @0x2e9688 b 0xff9a6dc4 <b2_toiTime+0xffffffffff24d920>
 *   @0x2e968c blmi 0x855b34 <b2_toiTime+0xfc690>
 *   @0x2e9690 and r4, r4, r11, ror r4
 *   @0x2e9694 ldrbtmi r4, [r11], #-2836
 *   @0x2e9698 blmi 0x8216a4 <b2_toiTime+0xc8200>
 *   @0x2e969c movwls r4, #0x47b
 *   @0x2e96a0 blls 0x9fafa8 <b2_toiTime+0x2a1b04>
 *   @0x2e96a4 shasxmi r4, r2, r9
 *   @0x2e96a8 movwhs r9, #0x301
 *   @0x2e96ac stc2 p7, c15, [r6, #-1020]!
 *   @0x2e96b0 .word 0x9c119011
 *   @0x2e96b4 strhs lr, [r9], #-2
 *   @0x2e96b8 ldrmi lr, [r12], -r0
 *   @0x2e96bc stmdbls pc, {r3, r11, r12, pc}
 *   @0x2e96c0 mrc2 p7, #0x1, apsr_nzcv, c9, c13, #0x7
 *   @0x2e96c4 blls 0xa17bbc <b2_toiTime+0x2be718>
 *   @0x2e96c8 blls 0x703738 <g_SWFvertbuff+0x30670>
 *   @0x2e96cc and r6, r2, r3, lsl r0
 *   @0x2e96d0 and r4, r0, r4, lsl #12
 *   @0x2e96d4 strtmi r4, [r0], -r4, lsl #12
 *   @0x2e96d8 pop {r0, r1, r4, r12, sp, pc}
 *   @0x2e96dc svclt #0x8ff0
 *   @0x2e96e0 andeq r5, r10, r5, lsl #2
 *   @0x2e96e4 muleq r10, r0, r0
 *   @0x2e96e8 andeq r5, r10, r10, lsl #1
 *
 * ══ §12/36 GR_3D_Draw_Cylinder(float, float, float, float, float, float, int, float, float, bool, int)  0x178d44  size 848  212 条（0x178d44..0x179094）
 * @func 0x178d44 0x179094  size 848  212 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_3D_Vertex_N_Texture(float, float, float, float, float, float, float, float)×6 / GR_3D_Primitive_Begin(int, int)×3 / GR_3D_Primitive_End()×3 / Graphics::Flush()×2 / 0xb658c×2 / 0xb6580×2 / GR_D3D_Get_Texture_Repeat() / GR_D3D_Set_Texture_Repeat(bool)
 * 字段偏移 top8: 0x18×4 / 0x4×4 / 0x8×4 / 0x14×3 / 0x1c×2 / 0xc×2 / 0x490×1 / 0x-374×1
 * VFP 指令 82 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x178d44 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x178d48 vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x178d4c sub sp, sp, #1056
 *   @0x178d50 sub sp, sp, #12
 *   @0x178d54 mov r7, r2
 *   @0x178d58 add r2, sp, #2048
 *   @0x178d5c vldr s19, [r2, #-888]
 *   @0x178d60 add r2, sp, #2048
 *   @0x178d64 vmov s21, r3
 *   @0x178d68 vldr s25, [r2, #-876]
 *   @0x178d6c ldr r3, [sp, #0x490]
 *   @0x178d70 ldr r8, [r2, #-0x374]
 *   @0x178d74 vmov s18, r1
 *   @0x178d78 ldrb r2, [sp, #0x49c]
 *   @0x178d7c vmov s20, r0
 *   @0x178d80 ldr r5, [sp, #0x4a0]
 *   @0x178d84 str r3, [sp, #0x18]
 *   @0x178d88 add r3, sp, #2048
 *   @0x178d8c str r2, [sp, #0x14]
 *   @0x178d90 vldr s24, [r3, #-872]
 *   @0x178d94 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x178d98 bl 0x1689e0 <_Z25GR_D3D_Get_Texture_Repeatv>
 *   @0x178d9c str r0, [sp, #0x1c]
 *   @0x178da0 mov r0, #1
 *   @0x178da4 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *   @0x178da8 cmp r5, #2
 *   @0x178dac ble 0x178f1c <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x1d8>
 *   @0x178db0 cmp r5, #128
 *   @0x178db4 ble 0x179070 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x32c>
 *   @0x178db8 mov r10, #1065353216
 *   @0x178dbc mov r5, #128
 *   @0x178dc0 mov r0, #0
 *   @0x178dc4 vldr s22, [pc, #700]
 *   @0x178dc8 add r2, sp, #548
 *   @0x178dcc add r11, sp, #32
 *   @0x178dd0 str r2, [sp, #0x10]
 *   @0x178dd4 mov r4, #0
 *   @0x178dd8 mov r9, r2
 *   @0x178ddc vldr s17, [pc, #680]
 *   @0x178de0 mov r6, r11
 *   @0x178de4 b 0x178e10 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0xcc>
 *   @0x178de8 vmov s13, r4
 *   @0x178dec vcvt.f32.s32 s16, s13
 *   @0x178df0 vadd.f32 s16, s16, s16
 *   @0x178df4 vmul.f32 s16, s16, s17
 *   @0x178df8 vdiv.f32 s16, s16, s22
 *   @0x178dfc vmov r0, s16
 *   @0x178e00 bl 0xb658c <cosf@plt>
 *   @0x178e04 mov r10, r0
 *   @0x178e08 vmov r0, s16
 *   @0x178e0c bl 0xb6580 <sinf@plt>
 *   @0x178e10 add r4, r4, #1
 *   @0x178e14 str r10, [r6], #4
 *   @0x178e18 cmp r5, r4
 *   @0x178e1c str r0, [r9], #4
 *   @0x178e20 bge 0x178de8 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0xa4>
 *   @0x178e24 vmov.f32 s15, #5.000000e-01
 *   @0x178e28 ldr r2, [sp, #0x14]
 *   @0x178e2c cmp r2, #0
 *   @0x178e30 vadd.f32 s26, s21, s20
 *   @0x178e34 vadd.f32 s23, s19, s18
 *   @0x178e38 vsub.f32 s20, s21, s20
 *   @0x178e3c vsub.f32 s18, s19, s18
 *   @0x178e40 vmul.f32 s26, s26, s15
 *   @0x178e44 vmul.f32 s27, s20, s15
 *   @0x178e48 vmul.f32 s23, s23, s15
 *   @0x178e4c vmul.f32 s28, s18, s15
 *   @0x178e50 bne 0x178fdc <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x298>
 *   @0x178e54 mov r0, #5
 *   @0x178e58 ldr r1, [sp, #0x18]
 *   @0x178e5c bl 0x1769dc <_Z21GR_3D_Primitive_Beginii>
 *   @0x178e60 add r10, sp, #548
 *   @0x178e64 mov r6, r11
 *   @0x178e68 mov r4, #0
 *   @0x178e6c vldr s18, [pc, #540]
 *   @0x178e70 vmov s15, r4
 *   @0x178e74 vldmia r6!, {s16}
 *   @0x178e78 vldmia r10!, {s17}
 *   @0x178e7c vmov r3, s16
 *   @0x178e80 mov r2, r8
 *   @0x178e84 vstr s18, [sp, #4]
 *   @0x178e88 vstr s24, [sp, #12]
 *   @0x178e8c vstr s17, [sp]
 *   @0x178e90 add r4, r4, #1
 *   @0x178e94 mov r9, #0
 *   @0x178e98 vcvt.f32.s32 s21, s15
 *   @0x178e9c vmul.f32 s21, s21, s25
 *   @0x178ea0 vdiv.f32 s21, s21, s22
 *   @0x178ea4 vmov.f32 s20, s26
 *   @0x178ea8 vstr s21, [sp, #8]
 *   @0x178eac vmov.f32 s19, s23
 *   @0x178eb0 vmla.f32 s20, s16, s27
 *   @0x178eb4 vmla.f32 s19, s17, s28
 *   @0x178eb8 vmov r0, s20
 *   @0x178ebc vmov r1, s19
 *   @0x178ec0 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x178ec4 vstr s21, [sp, #8]
 *   @0x178ec8 vstr s17, [sp]
 *   @0x178ecc vstr s18, [sp, #4]
 *   @0x178ed0 vstr s18, [sp, #12]
 *   @0x178ed4 vmov r0, s20
 *   @0x178ed8 vmov r1, s19
 *   @0x178edc mov r2, r7
 *   @0x178ee0 vmov r3, s16
 *   @0x178ee4 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x178ee8 cmp r5, r4
 *   @0x178eec bge 0x178e70 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x12c>
 *   @0x178ef0 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv>
 *   @0x178ef4 ldr r2, [sp, #0x14]
 *   @0x178ef8 cmp r2, #0
 *   @0x178efc bne 0x178f40 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x1fc>
 *   @0x178f00 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x178f04 ldr r0, [sp, #0x1c]
 *   @0x178f08 add sp, sp, #1056
 *   @0x178f0c add sp, sp, #12
 *   @0x178f10 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x178f14 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x178f18 b 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb>
 *   @0x178f1c vmov.f32 s22, #3.000000e+00
 *   @0x178f20 mov r5, #3
 *   @0x178f24 mov r4, #0
 *   @0x178f28 mov r0, r4
 *   @0x178f2c bl 0xb658c <cosf@plt>
 *   @0x178f30 mov r10, r0
 *   @0x178f34 mov r0, r4
 *   @0x178f38 bl 0xb6580 <sinf@plt>
 *   @0x178f3c b 0x178dc8 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x84>
 *   @0x178f40 ldr r1, [sp, #0x18]
 *   @0x178f44 mov r0, #6
 *   @0x178f48 bl 0x1769dc <_Z21GR_3D_Primitive_Beginii>
 *   @0x178f4c mov r6, #0
 *   @0x178f50 mov r2, r7
 *   @0x178f54 mov r3, r9
 *   @0x178f58 movt r6, #0xbf80
 *   @0x178f5c str r9, [sp]
 *   @0x178f60 str r9, [sp, #0x8]
 *   @0x178f64 mov r4, r9
 *   @0x178f68 str r9, [sp, #0xc]
 *   @0x178f6c vmov r0, s26
 *   @0x178f70 vmov r1, s23
 *   @0x178f74 str r6, [sp, #0x4]
 *   @0x178f78 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x178f7c add r3, r5, #1
 *   @0x178f80 add r2, sp, #548
 *   @0x178f84 lsl r3, r3, #2
 *   @0x178f88 add r11, r11, r3
 *   @0x178f8c add r10, r2, r3
 *   @0x178f90 vmov.f32 s13, s26
 *   @0x178f94 str r4, [sp]
 *   @0x178f98 str r6, [sp, #0x4]
 *   @0x178f9c mov r3, #0
 *   @0x178fa0 str r4, [sp, #0x8]
 *   @0x178fa4 mov r2, r7
 *   @0x178fa8 str r4, [sp, #0xc]
 *   @0x178fac vldmdb r10!, {s15}
 *   @0x178fb0 vldmdb r11!, {s14}
 *   @0x178fb4 vmla.f32 s13, s27, s14
 *   @0x178fb8 vmov.f32 s14, s23
 *   @0x178fbc vmov r0, s13
 *   @0x178fc0 vmla.f32 s14, s28, s15
 *   @0x178fc4 vmov r1, s14
 *   @0x178fc8 bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x178fcc subs r5, r5, #1
 *   @0x178fd0 bpl 0x178f90 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x24c>
 *   @0x178fd4 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv>
 *   @0x178fd8 b 0x178f00 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x1bc>
 *   @0x178fdc vmov.f32 s16, #1.000000e+00
 *   @0x178fe0 mov r6, #0
 *   @0x178fe4 mov r0, #6
 *   @0x178fe8 ldr r1, [sp, #0x18]
 *   @0x178fec bl 0x1769dc <_Z21GR_3D_Primitive_Beginii>
 *   @0x178ff0 vstr s24, [sp, #12]
 *   @0x178ff4 str r6, [sp]
 *   @0x178ff8 mov r3, r6
 *   @0x178ffc str r6, [sp, #0x8]
 *   @0x179000 mov r2, r8
 *   @0x179004 vmov r0, s26
 *   @0x179008 add r9, sp, #548
 *   @0x17900c vmov r1, s23
 *   @0x179010 mov r4, r11
 *   @0x179014 mov r10, #0
 *   @0x179018 vstr s16, [sp, #4]
 *   @0x17901c bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x179020 vmov.f32 s13, s26
 *   @0x179024 str r6, [sp]
 *   @0x179028 vstr s16, [sp, #4]
 *   @0x17902c str r6, [sp, #0x8]
 *   @0x179030 vstr s24, [sp, #12]
 *   @0x179034 vldmia r4!, {s14}
 *   @0x179038 vldmia r9!, {s15}
 *   @0x17903c add r10, r10, #1
 *   @0x179040 vmla.f32 s13, s14, s27
 *   @0x179044 mov r2, r8
 *   @0x179048 mov r3, #0
 *   @0x17904c vmov.f32 s14, s23
 *   @0x179050 vmov r0, s13
 *   @0x179054 vmla.f32 s14, s15, s28
 *   @0x179058 vmov r1, s14
 *   @0x17905c bl 0x17738c <_Z22GR_3D_Vertex_N_Textureffffffff>
 *   @0x179060 cmp r5, r10
 *   @0x179064 bge 0x179020 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x2dc>
 *   @0x179068 bl 0x176ad0 <_Z19GR_3D_Primitive_Endv>
 *   @0x17906c b 0x178e54 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x110>
 *   @0x179070 vmov s13, r5
 *   @0x179074 vldr s15, [pc, #20]
 *   @0x179078 vcvt.f32.s32 s22, s13
 *   @0x17907c vdiv.f32 s15, s15, s22
 *   @0x179080 vmov r4, s15
 *   @0x179084 b 0x178f28 <_Z19GR_3D_Draw_Cylinderffffffiffbi+0x1e4>
 *   @0x179088 movwmi r0, #0x0
 *   @0x17908c ldrdmi r0, r1, [r9], #-251
 *   @0x179090 andeq r0, r0, r0
 *
 * ══ §13/36 ov_pcm_seek  0x2326f4  size 848  212 条（0x2326f4..0x232a44）
 * @func 0x2326f4 0x232a44  size 848  212 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_22fd0c+0x588×2 / ogg_stream_packetout×2 / ov_pcm_seek+0x144×2 / ogg_page_serialno×2 / ov_pcm_seek_page / ov_pcm_seek+0x1dc / ogg_stream_packetpeek / ov_pcm_seek+0x1e4
 * 字段偏移 top8: 0x4×4 / 0x60×3 / 0x58×3 / 0x48×2 / 0x44×1 / 0x34×1 / 0x40×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2326f4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2326f8 sub sp, sp, #68
 *   @0x2326fc mov r6, r0
 *   @0x232700 strd r2, r3, [sp, #8]
 *   @0x232704 bl 0x231ed4 <ov_pcm_seek_page>
 *   @0x232708 cmp r0, #0
 *   @0x23270c blt 0x2328d0 <ov_pcm_seek+0x1dc>
 *   @0x232710 mov r0, r6
 *   @0x232714 bl 0x230294 <vorbis_packet_blocksize+0x618>
 *   @0x232718 cmp r0, #0
 *   @0x23271c bne 0x2328d0 <ov_pcm_seek+0x1dc>
 *   @0x232720 add r9, r6, #120
 *   @0x232724 add r7, sp, #32
 *   @0x232728 add r10, sp, #16
 *   @0x23272c add r11, r6, #560
 *   @0x232730 mov r4, r0
 *   @0x232734 add r1, r6, #480
 *   @0x232738 str r1, [sp, #0x4]
 *   @0x23273c mov r0, r9
 *   @0x232740 mov r1, r7
 *   @0x232744 bl 0x23535c <ogg_stream_packetpeek>
 *   @0x232748 cmp r0, #0
 *   @0x23274c ble 0x2328d8 <ov_pcm_seek+0x1e4>
 *   @0x232750 ldr r0, [r6, #0x60]
 *   @0x232754 mov r1, r7
 *   @0x232758 ldr r3, [r6, #0x48]
 *   @0x23275c add r0, r3, r0, lsl #5
 *   @0x232760 bl 0x22fc7c <vorbis_packet_blocksize>
 *   @0x232764 subs r8, r0, #0
 *   @0x232768 blt 0x2329f0 <ov_pcm_seek+0x2fc>
 *   @0x23276c cmp r4, #0
 *   @0x232770 bne 0x23293c <ov_pcm_seek+0x248>
 *   @0x232774 ldrd r4, r5, [r6, #80]
 *   @0x232778 ldr r0, [r6, #0x48]
 *   @0x23277c mov r1, #1
 *   @0x232780 bl 0x22acd4 <vorbis_info_blocksize>
 *   @0x232784 add r0, r0, r8
 *   @0x232788 asr r3, r0, #2
 *   @0x23278c adds r4, r4, r3
 *   @0x232790 adc r5, r5, r3, asr #31
 *   @0x232794 ldrd r2, r3, [sp, #8]
 *   @0x232798 cmp r4, r2
 *   @0x23279c sbcs r3, r5, r3
 *   @0x2327a0 bge 0x232840 <ov_pcm_seek+0x14c>
 *   @0x2327a4 mov r1, #0
 *   @0x2327a8 mov r0, r9
 *   @0x2327ac bl 0x235328 <ogg_stream_packetout>
 *   @0x2327b0 mov r1, r7
 *   @0x2327b4 mov r0, r11
 *   @0x2327b8 bl 0x22fc74 <vorbis_synthesis_trackonly>
 *   @0x2327bc mov r1, r11
 *   @0x2327c0 ldr r0, [sp, #0x4]
 *   @0x2327c4 bl 0x227638 <vorbis_synthesis_blockin>
 *   @0x2327c8 ldrd r0, r1, [sp, #48]
 *   @0x2327cc cmp r0, #0
 *   @0x2327d0 sbcs r2, r1, #0
 *   @0x2327d4 blt 0x232838 <ov_pcm_seek+0x144>
 *   @0x2327d8 ldr r4, [r6, #0x60]
 *   @0x2327dc ldr r12, [r6, #0x44]
 *   @0x2327e0 lsl lr, r4, #4
 *   @0x2327e4 ldrd r2, r3, [r12, lr]
 *   @0x2327e8 subs r2, r0, r2
 *   @0x2327ec sbc r3, r1, r3
 *   @0x2327f0 cmp r2, #0
 *   @0x2327f4 sbcs r1, r3, #0
 *   @0x2327f8 movlt r2, #0
 *   @0x2327fc movlt r3, #0
 *   @0x232800 cmp r4, #0
 *   @0x232804 strd r2, r3, [r6, #80]
 *   @0x232808 ble 0x232838 <ov_pcm_seek+0x144>
 *   @0x23280c ldrd r0, r1, [r6, #80]
 *   @0x232810 add lr, r12, lr
 *   @0x232814 ldrd r2, r3, [r12, #8]
 *   @0x232818 add r12, r12, #16
 *   @0x23281c adds r2, r2, r0
 *   @0x232820 adc r3, r3, r1
 *   @0x232824 cmp r12, lr
 *   @0x232828 mov r0, r2
 *   @0x23282c strd r2, r3, [r6, #80]
 *   @0x232830 mov r1, r3
 *   @0x232834 bne 0x232814 <ov_pcm_seek+0x120>
 *   @0x232838 mov r4, r8
 *   @0x23283c b 0x23273c <ov_pcm_seek+0x48>
 *   @0x232840 mov r2, #0
 *   @0x232844 mov r3, #0
 *   @0x232848 ldrd r4, r5, [r6, #80]
 *   @0x23284c add r7, r6, #480
 *   @0x232850 strd r2, r3, [r6, #104]
 *   @0x232854 strd r2, r3, [r6, #112]
 *   @0x232858 ldrd r10, r11, [sp, #8]
 *   @0x23285c b 0x2328b8 <ov_pcm_seek+0x1c4>
 *   @0x232860 bl 0x227c80 <vorbis_synthesis_pcmout>
 *   @0x232864 subs r4, r10, r4
 *   @0x232868 sbc r5, r11, r5
 *   @0x23286c mov r1, r0
 *   @0x232870 mov r0, r7
 *   @0x232874 asr r9, r1, #31
 *   @0x232878 mov r8, r1
 *   @0x23287c cmp r4, r8
 *   @0x232880 sbcs r2, r5, r9
 *   @0x232884 movlt r8, r4
 *   @0x232888 movlt r1, r4
 *   @0x23288c asrlt r9, r8, #31
 *   @0x232890 bl 0x227cfc <vorbis_synthesis_read>
 *   @0x232894 ldrd r2, r3, [r6, #80]
 *   @0x232898 adds r2, r2, r8
 *   @0x23289c adc r3, r3, r9
 *   @0x2328a0 cmp r8, r4
 *   @0x2328a4 sbcs r1, r9, r5
 *   @0x2328a8 strd r2, r3, [r6, #80]
 *   @0x2328ac mov r4, r2
 *   @0x2328b0 mov r5, r3
 *   @0x2328b4 blt 0x232a00 <ov_pcm_seek+0x30c>
 *   @0x2328b8 cmp r4, r10
 *   @0x2328bc sbcs r2, r5, r11
 *   @0x2328c0 mov r0, r7
 *   @0x2328c4 mov r1, #0
 *   @0x2328c8 blt 0x232860 <ov_pcm_seek+0x16c>
 *   @0x2328cc mov r0, r1
 *   @0x2328d0 add sp, sp, #68
 *   @0x2328d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2328d8 adds r3, r0, #3
 *   @0x2328dc movne r3, #1
 *   @0x2328e0 ands r3, r3, r0, lsr #31
 *   @0x2328e4 bne 0x232840 <ov_pcm_seek+0x14c>
 *   @0x2328e8 mvn r2, #0
 *   @0x2328ec mov r0, r6
 *   @0x2328f0 mov r1, r10
 *   @0x2328f4 mvn r3, #0
 *   @0x2328f8 bl 0x22fd0c <vorbis_packet_blocksize+0x90>
 *   @0x2328fc cmp r0, #0
 *   @0x232900 sbcs r2, r1, #0
 *   @0x232904 blt 0x232840 <ov_pcm_seek+0x14c>
 *   @0x232908 mov r0, r10
 *   @0x23290c bl 0x233f90 <ogg_page_bos>
 *   @0x232910 cmp r0, #0
 *   @0x232914 bne 0x232958 <ov_pcm_seek+0x264>
 *   @0x232918 ldr r3, [r6, #0x58]
 *   @0x23291c cmp r3, #2
 *   @0x232920 ble 0x232970 <ov_pcm_seek+0x27c>
 *   @0x232924 mov r0, r9
 *   @0x232928 mov r1, r10
 *   @0x23292c mov r8, r4
 *   @0x232930 bl 0x234eac <ogg_stream_pagein>
 *   @0x232934 mov r4, r8
 *   @0x232938 b 0x23273c <ov_pcm_seek+0x48>
 *   @0x23293c add r3, r4, r8
 *   @0x232940 ldrd r4, r5, [r6, #80]
 *   @0x232944 asr r3, r3, #2
 *   @0x232948 adds r4, r4, r3
 *   @0x23294c adc r5, r5, r3, asr #31
 *   @0x232950 strd r4, r5, [r6, #80]
 *   @0x232954 b 0x232778 <ov_pcm_seek+0x84>
 *   @0x232958 ldr r0, [sp, #0x4]
 *   @0x23295c bl 0x2272ac <vorbis_dsp_clear>
 *   @0x232960 mov r0, r11
 *   @0x232964 bl 0x227208 <vorbis_block_clear>
 *   @0x232968 mov r3, #2
 *   @0x23296c str r3, [r6, #0x58]
 *   @0x232970 mov r0, r10
 *   @0x232974 bl 0x23409c <ogg_page_serialno>
 *   @0x232978 ldr r1, [r6, #0x34]
 *   @0x23297c cmp r1, #0
 *   @0x232980 mov r5, r0
 *   @0x232984 ble 0x232a18 <ov_pcm_seek+0x324>
 *   @0x232988 ldr r2, [r6, #0x40]
 *   @0x23298c ldr r3, [r2]
 *   @0x232990 cmp r3, r0
 *   @0x232994 mov r3, #0
 *   @0x232998 beq 0x2329b4 <ov_pcm_seek+0x2c0>
 *   @0x23299c add r3, r3, #1
 *   @0x2329a0 cmp r3, r1
 *   @0x2329a4 beq 0x23273c <ov_pcm_seek+0x48>
 *   @0x2329a8 ldr r0, [r2, #0x4]!
 *   @0x2329ac cmp r0, r5
 *   @0x2329b0 bne 0x23299c <ov_pcm_seek+0x2a8>
 *   @0x2329b4 str r3, [r6, #0x60]
 *   @0x2329b8 mov r0, r10
 *   @0x2329bc mov r3, #3
 *   @0x2329c0 str r3, [r6, #0x58]
 *   @0x2329c4 bl 0x23409c <ogg_page_serialno>
 *   @0x2329c8 mov r1, r5
 *   @0x2329cc str r0, [r6, #0x5c]
 *   @0x2329d0 mov r0, r9
 *   @0x2329d4 bl 0x2352f4 <ogg_stream_reset_serialno>
 *   @0x2329d8 mov r0, r6
 *   @0x2329dc bl 0x230294 <vorbis_packet_blocksize+0x618>
 *   @0x2329e0 cmp r0, #0
 *   @0x2329e4 bne 0x2328d0 <ov_pcm_seek+0x1dc>
 *   @0x2329e8 mov r4, r0
 *   @0x2329ec b 0x232924 <ov_pcm_seek+0x230>
 *   @0x2329f0 mov r0, r9
 *   @0x2329f4 mov r1, #0
 *   @0x2329f8 bl 0x235328 <ogg_stream_packetout>
 *   @0x2329fc b 0x23273c <ov_pcm_seek+0x48>
 *   @0x232a00 mov r0, r6
 *   @0x232a04 bl 0x230b68 <vorbis_packet_blocksize+0xeec>
 *   @0x232a08 cmp r0, #0
 *   @0x232a0c ble 0x232a24 <ov_pcm_seek+0x330>
 *   @0x232a10 ldrd r4, r5, [r6, #80]
 *   @0x232a14 b 0x2328b8 <ov_pcm_seek+0x1c4>
 *   @0x232a18 beq 0x23273c <ov_pcm_seek+0x48>
 *   @0x232a1c mov r3, #0
 *   @0x232a20 b 0x2329b4 <ov_pcm_seek+0x2c0>
 *   @0x232a24 mov r0, r6
 *   @0x232a28 mvn r1, #0
 *   @0x232a2c bl 0x23138c <ov_pcm_total>
 *   @0x232a30 str r1, [r6, #0x54]
 *   @0x232a34 mov r4, r0
 *   @0x232a38 str r0, [r6, #0x50]
 *   @0x232a3c mov r5, r1
 *   @0x232a40 b 0x2328b8 <ov_pcm_seek+0x1c4>
 *
 * ══ §14/36 F_JS_ToPropertyDescriptor(RValue*, RValue*)  0x24195c  size 848  212 条（0x24195c..0x241cac）
 * @func 0x24195c 0x241cac  size 848  212 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_HasProperty(YYObjectBase*, char const*)×6 / JS_GetProperty(YYObjectBase*, RValue*, char const*)×6 / YYObjectBase::InternalGetYYVar(int)×4 / JS_ToBoolean(RValue&)×3 / JS_IsCallable(RValue&)×2 / YYObjectBase::Alloc(unsigned int, int, bool)×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2
 * 字段偏移 top8: 0xc×9 / 0x4×5 / 0x8×3 / 0x48×2 / 0x308×1 / 0x2bc×1 / 0x2a4×1 / 0x28c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24195c ldr r3, [r1, #0xc]
 *   @0x241960 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x241964 bic r3, r3, #-16777216
 *   @0x241968 cmp r3, #6
 *   @0x24196c sub sp, sp, #20
 *   @0x241970 mov r6, r0
 *   @0x241974 beq 0x241984 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x28>
 *   @0x241978 mov r0, #1
 *   @0x24197c add sp, sp, #20
 *   @0x241980 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x241984 ldr r9, [pc, #0x308]
 *   @0x241988 mov r8, #0
 *   @0x24198c ldr r7, [r1]
 *   @0x241990 mov r3, #5
 *   @0x241994 add r9, pc, r9
 *   @0x241998 str r8, [r0, #0x8]
 *   @0x24199c str r8, [r6, #0x4]
 *   @0x2419a0 mov r5, #0
 *   @0x2419a4 mov r0, r7
 *   @0x2419a8 mov r1, r9
 *   @0x2419ac str r8, [r6]
 *   @0x2419b0 mov r4, #0
 *   @0x2419b4 str r3, [r6, #0xc]
 *   @0x2419b8 strd r4, r5, [sp]
 *   @0x2419bc str r8, [sp, #0x8]
 *   @0x2419c0 str r3, [sp, #0xc]
 *   @0x2419c4 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc>
 *   @0x2419c8 cmp r0, #0
 *   @0x2419cc moveq r5, r0
 *   @0x2419d0 bne 0x241c0c <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x2b0>
 *   @0x2419d4 ldr r4, [pc, #0x2bc]
 *   @0x2419d8 mov r0, r7
 *   @0x2419dc add r4, pc, r4
 *   @0x2419e0 mov r1, r4
 *   @0x2419e4 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc>
 *   @0x2419e8 cmp r0, #0
 *   @0x2419ec bne 0x241be0 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x284>
 *   @0x2419f0 ldr r4, [pc, #0x2a4]
 *   @0x2419f4 mov r0, r7
 *   @0x2419f8 add r4, pc, r4
 *   @0x2419fc mov r1, r4
 *   @0x241a00 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc>
 *   @0x241a04 cmp r0, #0
 *   @0x241a08 bne 0x241bb4 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x258>
 *   @0x241a0c ldr r4, [pc, #0x28c]
 *   @0x241a10 mov r0, r7
 *   @0x241a14 add r4, pc, r4
 *   @0x241a18 mov r1, r4
 *   @0x241a1c bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc>
 *   @0x241a20 cmp r0, #0
 *   @0x241a24 bne 0x241b80 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x224>
 *   @0x241a28 ldr r4, [pc, #0x274]
 *   @0x241a2c mov r0, r7
 *   @0x241a30 add r4, pc, r4
 *   @0x241a34 mov r1, r4
 *   @0x241a38 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc>
 *   @0x241a3c cmp r0, #0
 *   @0x241a40 beq 0x241ad8 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x17c>
 *   @0x241a44 mov r2, r4
 *   @0x241a48 mov r0, r7
 *   @0x241a4c mov r1, sp
 *   @0x241a50 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x241a54 mov r0, sp
 *   @0x241a58 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x241a5c cmp r0, #0
 *   @0x241a60 bne 0x241a74 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x118>
 *   @0x241a64 ldr r3, [sp, #0xc]
 *   @0x241a68 bic r3, r3, #-16777216
 *   @0x241a6c cmp r3, #5
 *   @0x241a70 bne 0x241978 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1c>
 *   @0x241a74 cmp r5, #0
 *   @0x241a78 bne 0x241978 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1c>
 *   @0x241a7c mov r2, r5
 *   @0x241a80 mov r0, #2
 *   @0x241a84 mvn r1, #-16777216
 *   @0x241a88 bl 0x19198c <_ZN12YYObjectBase5AllocEjib>
 *   @0x241a8c mov r3, #2
 *   @0x241a90 mov r2, #6
 *   @0x241a94 str r3, [r0, #0x48]
 *   @0x241a98 mov r4, r0
 *   @0x241a9c str r0, [r6]
 *   @0x241aa0 ldr r3, [r0, #0x4]
 *   @0x241aa4 str r2, [r6, #0xc]
 *   @0x241aa8 cmp r3, #0
 *   @0x241aac beq 0x241c28 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x2cc>
 *   @0x241ab0 ldr r2, [sp]
 *   @0x241ab4 mov r0, r4
 *   @0x241ab8 str r2, [r3]
 *   @0x241abc ldr r1, [sp]
 *   @0x241ac0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x241ac4 ldr r1, [r4, #0x4]
 *   @0x241ac8 cmp r1, #0
 *   @0x241acc beq 0x241c38 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x2dc>
 *   @0x241ad0 mov r3, #11
 *   @0x241ad4 str r3, [r1, #0xc]
 *   @0x241ad8 ldr r4, [pc, #0x1c8]
 *   @0x241adc mov r0, r7
 *   @0x241ae0 add r4, pc, r4
 *   @0x241ae4 mov r1, r4
 *   @0x241ae8 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc>
 *   @0x241aec cmp r0, #0
 *   @0x241af0 beq 0x24197c <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x20>
 *   @0x241af4 mov r0, r7
 *   @0x241af8 mov r2, r4
 *   @0x241afc mov r1, sp
 *   @0x241b00 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x241b04 mov r0, sp
 *   @0x241b08 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x241b0c cmp r0, #0
 *   @0x241b10 bne 0x241b24 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1c8>
 *   @0x241b14 ldr r3, [sp, #0xc]
 *   @0x241b18 bic r3, r3, #-16777216
 *   @0x241b1c cmp r3, #5
 *   @0x241b20 bne 0x241978 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1c>
 *   @0x241b24 cmp r5, #0
 *   @0x241b28 bne 0x241978 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1c>
 *   @0x241b2c ldr r3, [r6]
 *   @0x241b30 cmp r3, #0
 *   @0x241b34 beq 0x241c68 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x30c>
 *   @0x241b38 ldr r2, [r3, #0x4]
 *   @0x241b3c cmp r2, #0
 *   @0x241b40 beq 0x241c58 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x2fc>
 *   @0x241b44 add r0, r2, #16
 *   @0x241b48 ldr r3, [sp]
 *   @0x241b4c str r3, [r0]
 *   @0x241b50 ldr r1, [sp]
 *   @0x241b54 ldr r0, [r6]
 *   @0x241b58 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x241b5c ldr r0, [r6]
 *   @0x241b60 ldr r3, [r0, #0x4]
 *   @0x241b64 cmp r3, #0
 *   @0x241b68 beq 0x241c48 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x2ec>
 *   @0x241b6c add r3, r3, #16
 *   @0x241b70 mov r2, #11
 *   @0x241b74 mov r0, #0
 *   @0x241b78 str r2, [r3, #0xc]
 *   @0x241b7c b 0x24197c <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x20>
 *   @0x241b80 mov r2, r4
 *   @0x241b84 mov r0, r7
 *   @0x241b88 mov r1, sp
 *   @0x241b8c bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x241b90 mov r0, sp
 *   @0x241b94 bl 0x2404bc <_Z12JS_ToBooleanR6RValue>
 *   @0x241b98 cmp r0, #0
 *   @0x241b9c ldrne r3, [r6, #0x8]
 *   @0x241ba0 movne r5, #1
 *   @0x241ba4 moveq r5, #1
 *   @0x241ba8 orrne r3, r3, #4
 *   @0x241bac strne r3, [r6, #0x8]
 *   @0x241bb0 b 0x241a28 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0xcc>
 *   @0x241bb4 mov r2, r4
 *   @0x241bb8 mov r0, r7
 *   @0x241bbc mov r1, sp
 *   @0x241bc0 bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x241bc4 mov r0, sp
 *   @0x241bc8 bl 0x2404bc <_Z12JS_ToBooleanR6RValue>
 *   @0x241bcc cmp r0, #0
 *   @0x241bd0 ldrne r3, [r6, #0x8]
 *   @0x241bd4 orrne r3, r3, #2
 *   @0x241bd8 strne r3, [r6, #0x8]
 *   @0x241bdc b 0x241a0c <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0xb0>
 *   @0x241be0 mov r2, r4
 *   @0x241be4 mov r0, r7
 *   @0x241be8 mov r1, sp
 *   @0x241bec bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x241bf0 mov r0, sp
 *   @0x241bf4 bl 0x2404bc <_Z12JS_ToBooleanR6RValue>
 *   @0x241bf8 cmp r0, #0
 *   @0x241bfc ldrne r3, [r6, #0x8]
 *   @0x241c00 orrne r3, r3, #1
 *   @0x241c04 strne r3, [r6, #0x8]
 *   @0x241c08 b 0x2419f0 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x94>
 *   @0x241c0c mov r2, r9
 *   @0x241c10 mov r0, r7
 *   @0x241c14 mov r1, r6
 *   @0x241c18 mov r5, #1
 *   @0x241c1c bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc>
 *   @0x241c20 str r8, [r6, #0x8]
 *   @0x241c24 b 0x2419d4 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x78>
 *   @0x241c28 mov r1, r5
 *   @0x241c2c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x241c30 mov r3, r0
 *   @0x241c34 b 0x241ab0 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x154>
 *   @0x241c38 mov r0, r4
 *   @0x241c3c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x241c40 mov r1, r0
 *   @0x241c44 b 0x241ad0 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x174>
 *   @0x241c48 mov r1, #1
 *   @0x241c4c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x241c50 mov r3, r0
 *   @0x241c54 b 0x241b70 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x214>
 *   @0x241c58 mov r0, r3
 *   @0x241c5c mov r1, #1
 *   @0x241c60 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x241c64 b 0x241b48 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1ec>
 *   @0x241c68 mov r2, r5
 *   @0x241c6c mvn r1, #-16777216
 *   @0x241c70 mov r0, #2
 *   @0x241c74 bl 0x19198c <_ZN12YYObjectBase5AllocEjib>
 *   @0x241c78 mov r1, #2
 *   @0x241c7c mov r2, #6
 *   @0x241c80 str r1, [r0, #0x48]
 *   @0x241c84 mov r3, r0
 *   @0x241c88 str r0, [r6]
 *   @0x241c8c str r2, [r6, #0xc]
 *   @0x241c90 b 0x241b38 <_Z25F_JS_ToPropertyDescriptorP6RValueS0_+0x1dc>
 *   @0x241c94 andeq r5, pc, r12, asr #11
 *   @0x241c98 andseq r3, r1, r0, lsr r12
 *   @0x241c9c andseq r3, r1, r0, lsr #24
 *   @0x241ca0 andseq r3, r1, r4, lsl r12
 *   @0x241ca4 andseq r3, r1, r4, lsl #24
 *   @0x241ca8 andseq r3, r1, r8, asr r11
 *
 * ══ §15/36 b2WeldJoint::InitVelocityConstraints(b2SolverData const&)  0x2d3348  size 848  212 条（0x2d3348..0x2d3698）
 * @func 0x2d3348 0x2d3698  size 848  212 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / b2WeldJoint::InitVelocityConstraints(b2SolverData const&)+0x338 / b2Mat33::GetInverse22(b2Mat33*) const / b2Mat33::GetSymInverse33(b2Mat33*) const
 * 字段偏移 top8: 0x8×2 / 0x1c×2 / 0x74×2 / 0x78×2 / 0x30×1 / 0x34×1 / 0x18×1 / 0x14×1
 * VFP 指令 155 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d3348 ldr r2, [r0, #0x30]
 *   @0x2d334c ldr r3, [r0, #0x34]
 *   @0x2d3350 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2d3354 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2d3358 mov r5, r1
 *   @0x2d335c vldr s17, [r2, #144]
 *   @0x2d3360 add r1, r2, #44
 *   @0x2d3364 mov r4, r0
 *   @0x2d3368 ldr r12, [r3, #0x8]
 *   @0x2d336c add r10, r0, #140
 *   @0x2d3370 ldr lr, [r2, #0x8]
 *   @0x2d3374 add r7, r0, #148
 *   @0x2d3378 ldm r1, {r0, r1}
 *   @0x2d337c add r9, r3, #44
 *   @0x2d3380 vldr s18, [r3, #136]
 *   @0x2d3384 ldr r8, [r5, #0x18]
 *   @0x2d3388 vldr s19, [r2, #136]
 *   @0x2d338c ldr r6, [r5, #0x1c]
 *   @0x2d3390 str lr, [r4, #0x74]
 *   @0x2d3394 add lr, lr, lr, lsl #1
 *   @0x2d3398 str r12, [r4, #0x78]
 *   @0x2d339c add r12, r12, r12, lsl #1
 *   @0x2d33a0 stm r10, {r0, r1}
 *   @0x2d33a4 lsl lr, lr, #2
 *   @0x2d33a8 ldm r9, {r0, r1}
 *   @0x2d33ac vldr s16, [r3, #144]
 *   @0x2d33b0 sub sp, sp, #40
 *   @0x2d33b4 add r2, r8, lr
 *   @0x2d33b8 lsl r12, r12, #2
 *   @0x2d33bc vldr s20, [r2, #8]
 *   @0x2d33c0 stm r7, {r0, r1}
 *   @0x2d33c4 vstr s19, [r4, #156]
 *   @0x2d33c8 vmov r0, s20
 *   @0x2d33cc vstr s18, [r4, #160]
 *   @0x2d33d0 vstr s17, [r4, #164]
 *   @0x2d33d4 vstr s16, [r4, #168]
 *   @0x2d33d8 add lr, r6, lr
 *   @0x2d33dc add r8, r8, r12
 *   @0x2d33e0 vldr s30, [lr]
 *   @0x2d33e4 add r12, r6, r12
 *   @0x2d33e8 vldr s29, [lr, #4]
 *   @0x2d33ec vldr s28, [lr, #8]
 *   @0x2d33f0 vldr s27, [r12]
 *   @0x2d33f4 vldr s26, [r12, #4]
 *   @0x2d33f8 vldr s25, [r12, #8]
 *   @0x2d33fc bl 0xb6580 <sinf@plt>
 *   @0x2d3400 vldr s21, [r8, #8]
 *   @0x2d3404 vldr s31, [pc, #644]
 *   @0x2d3408 vmov s24, r0
 *   @0x2d340c vmov r0, s20
 *   @0x2d3410 bl 0xb658c <cosf@plt>
 *   @0x2d3414 vmov s23, r0
 *   @0x2d3418 vmov r0, s21
 *   @0x2d341c bl 0xb6580 <sinf@plt>
 *   @0x2d3420 vmov s22, r0
 *   @0x2d3424 vmov r0, s21
 *   @0x2d3428 bl 0xb658c <cosf@plt>
 *   @0x2d342c vldr s14, [r4, #84]
 *   @0x2d3430 vldr s15, [r4, #144]
 *   @0x2d3434 vsub.f32 s15, s14, s15
 *   @0x2d3438 vldr s12, [r4, #92]
 *   @0x2d343c vldr s14, [r4, #152]
 *   @0x2d3440 vldr s13, [r4, #140]
 *   @0x2d3444 vldr s9, [r4, #80]
 *   @0x2d3448 vldr s8, [r4, #88]
 *   @0x2d344c vldr s10, [r4, #148]
 *   @0x2d3450 add r1, r4, #172
 *   @0x2d3454 vsub.f32 s14, s12, s14
 *   @0x2d3458 vmul.f32 s12, s15, s23
 *   @0x2d345c vmov s11, r0
 *   @0x2d3460 add r0, sp, #4
 *   @0x2d3464 vsub.f32 s9, s9, s13
 *   @0x2d3468 vmul.f32 s15, s15, s24
 *   @0x2d346c vmla.f32 s12, s9, s24
 *   @0x2d3470 vmul.f32 s13, s14, s11
 *   @0x2d3474 vstr s12, [r4, #128]
 *   @0x2d3478 vmul.f32 s14, s14, s22
 *   @0x2d347c vsub.f32 s10, s8, s10
 *   @0x2d3480 vldr s8, [r4, #68]
 *   @0x2d3484 vnmls.f32 s15, s9, s23
 *   @0x2d3488 vmla.f32 s13, s10, s22
 *   @0x2d348c vstr s15, [r4, #124]
 *   @0x2d3490 vnmls.f32 s14, s10, s11
 *   @0x2d3494 vstr s13, [r4, #136]
 *   @0x2d3498 vadd.f32 s10, s19, s18
 *   @0x2d349c vstr s14, [r4, #132]
 *   @0x2d34a0 vmul.f32 s9, s12, s12
 *   @0x2d34a4 vmov.f32 s6, s10
 *   @0x2d34a8 vmul.f32 s7, s15, s15
 *   @0x2d34ac vmla.f32 s6, s17, s9
 *   @0x2d34b0 vmul.f32 s11, s14, s13
 *   @0x2d34b4 vmla.f32 s10, s17, s7
 *   @0x2d34b8 vneg.f32 s12, s12
 *   @0x2d34bc vmov.f32 s9, s6
 *   @0x2d34c0 vmul.f32 s5, s13, s13
 *   @0x2d34c4 vmul.f32 s6, s14, s14
 *   @0x2d34c8 vmul.f32 s7, s12, s15
 *   @0x2d34cc vmul.f32 s11, s16, s11
 *   @0x2d34d0 vmul.f32 s13, s16, s13
 *   @0x2d34d4 vmul.f32 s14, s16, s14
 *   @0x2d34d8 vnmls.f32 s11, s17, s7
 *   @0x2d34dc vnmls.f32 s13, s17, s12
 *   @0x2d34e0 vstr s11, [sp, #16]
 *   @0x2d34e4 vstr s11, [sp, #8]
 *   @0x2d34e8 vmla.f32 s14, s17, s15
 *   @0x2d34ec vstr s13, [sp, #28]
 *   @0x2d34f0 vstr s13, [sp, #12]
 *   @0x2d34f4 vmla.f32 s9, s16, s5
 *   @0x2d34f8 vstr s14, [sp, #32]
 *   @0x2d34fc vstr s14, [sp, #24]
 *   @0x2d3500 vmla.f32 s10, s16, s6
 *   @0x2d3504 vstr s9, [sp, #4]
 *   @0x2d3508 vadd.f32 s22, s17, s16
 *   @0x2d350c vstr s10, [sp, #20]
 *   @0x2d3510 vcmpe.f32 s8, s31
 *   @0x2d3514 vstr s22, [sp, #36]
 *   @0x2d3518 vmrs APSR_nzcv, fpscr
 *   @0x2d351c ble 0x2d3680 <_ZN11b2WeldJoint23InitVelocityConstraintsERK12b2SolverData+0x338>
 *   @0x2d3520 bl 0x2c6940 <_ZNK7b2Mat3312GetInverse22EPS_>
 *   @0x2d3524 vcmpe.f32 s22, s31
 *   @0x2d3528 vldr s15, [pc, #356]
 *   @0x2d352c vldr s13, [r4, #68]
 *   @0x2d3530 vldr s14, [r5]
 *   @0x2d3534 vldr s11, [r4, #96]
 *   @0x2d3538 vmrs APSR_nzcv, fpscr
 *   @0x2d353c vmovgt.f32 s12, #1.000000e+00
 *   @0x2d3540 vmul.f32 s13, s13, s15
 *   @0x2d3544 vldr s15, [r4, #72]
 *   @0x2d3548 vmovle.f32 s12, s31
 *   @0x2d354c vsub.f32 s20, s21, s20
 *   @0x2d3550 vdivgt.f32 s12, s12, s22
 *   @0x2d3554 vaddgt.f32 s31, s12, s12
 *   @0x2d3558 vmul.f32 s12, s12, s13
 *   @0x2d355c vmul.f32 s31, s31, s15
 *   @0x2d3560 vmul.f32 s12, s12, s13
 *   @0x2d3564 vmul.f32 s15, s31, s13
 *   @0x2d3568 vmla.f32 s15, s14, s12
 *   @0x2d356c vmul.f32 s15, s15, s14
 *   @0x2d3570 vcmp.f32 s15, #0
 *   @0x2d3574 vmrs APSR_nzcv, fpscr
 *   @0x2d3578 vmovne.f32 s13, #1.000000e+00
 *   @0x2d357c vldreq s15, [pc, #268]
 *   @0x2d3580 vdivne.f32 s15, s13, s15
 *   @0x2d3584 vsub.f32 s20, s20, s11
 *   @0x2d3588 vstr s15, [r4, #100]
 *   @0x2d358c vmul.f32 s14, s20, s14
 *   @0x2d3590 vmul.f32 s12, s14, s12
 *   @0x2d3594 vadd.f32 s22, s15, s22
 *   @0x2d3598 vmul.f32 s15, s15, s12
 *   @0x2d359c vcmp.f32 s22, #0
 *   @0x2d35a0 vstr s15, [r4, #76]
 *   @0x2d35a4 vmrs APSR_nzcv, fpscr
 *   @0x2d35a8 vmovne.f32 s15, #1.000000e+00
 *   @0x2d35ac vldreq s22, [pc, #220]
 *   @0x2d35b0 vdivne.f32 s22, s15, s22
 *   @0x2d35b4 vstr s22, [r4, #204]
 *   @0x2d35b8 ldrb r3, [r5, #0x14]
 *   @0x2d35bc cmp r3, #0
 *   @0x2d35c0 bne 0x2d3614 <_ZN11b2WeldJoint23InitVelocityConstraintsERK12b2SolverData+0x2cc>
 *   @0x2d35c4 mov r3, #0
 *   @0x2d35c8 str r3, [r4, #0x68]
 *   @0x2d35cc str r3, [r4, #0x6c]
 *   @0x2d35d0 str r3, [r4, #0x70]
 *   @0x2d35d4 ldr r2, [r4, #0x74]
 *   @0x2d35d8 ldr r3, [r4, #0x78]
 *   @0x2d35dc ldr r1, [r5, #0x1c]
 *   @0x2d35e0 add r2, r2, r2, lsl #1
 *   @0x2d35e4 add r3, r3, r3, lsl #1
 *   @0x2d35e8 add r2, r1, r2, lsl #2
 *   @0x2d35ec vstr s30, [r2]
 *   @0x2d35f0 vstr s29, [r2, #4]
 *   @0x2d35f4 vstr s28, [r2, #8]
 *   @0x2d35f8 add r3, r1, r3, lsl #2
 *   @0x2d35fc vstr s27, [r3]
 *   @0x2d3600 vstr s26, [r3, #4]
 *   @0x2d3604 vstr s25, [r3, #8]
 *   @0x2d3608 add sp, sp, #40
 *   @0x2d360c vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2d3610 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2d3614 vldr s12, [r5, #8]
 *   @0x2d3618 vldr s14, [r4, #104]
 *   @0x2d361c vmul.f32 s14, s12, s14
 *   @0x2d3620 vldr s15, [r4, #108]
 *   @0x2d3624 vldr s11, [r4, #128]
 *   @0x2d3628 vldr s13, [r4, #136]
 *   @0x2d362c vldr s8, [r4, #124]
 *   @0x2d3630 vldr s9, [r4, #132]
 *   @0x2d3634 vldr s10, [r4, #112]
 *   @0x2d3638 vmul.f32 s15, s12, s15
 *   @0x2d363c vstr s14, [r4, #104]
 *   @0x2d3640 vmul.f32 s11, s14, s11
 *   @0x2d3644 vstr s15, [r4, #108]
 *   @0x2d3648 vmul.f32 s13, s14, s13
 *   @0x2d364c vnmls.f32 s11, s15, s8
 *   @0x2d3650 vnmls.f32 s13, s15, s9
 *   @0x2d3654 vmul.f32 s12, s12, s10
 *   @0x2d3658 vadd.f32 s11, s12, s11
 *   @0x2d365c vstr s12, [r4, #112]
 *   @0x2d3660 vadd.f32 s13, s12, s13
 *   @0x2d3664 vmls.f32 s30, s19, s14
 *   @0x2d3668 vmla.f32 s27, s18, s14
 *   @0x2d366c vmls.f32 s29, s19, s15
 *   @0x2d3670 vmla.f32 s26, s18, s15
 *   @0x2d3674 vmls.f32 s28, s17, s11
 *   @0x2d3678 vmla.f32 s25, s16, s13
 *   @0x2d367c b 0x2d35d4 <_ZN11b2WeldJoint23InitVelocityConstraintsERK12b2SolverData+0x28c>
 *   @0x2d3680 bl 0x2c69a8 <_ZNK7b2Mat3315GetSymInverse33EPS_>
 *   @0x2d3684 vstr s31, [r4, #100]
 *   @0x2d3688 vstr s31, [r4, #76]
 *   @0x2d368c b 0x2d35b8 <_ZN11b2WeldJoint23InitVelocityConstraintsERK12b2SolverData+0x270>
 *   @0x2d3690 andeq r0, r0, r0
 *   @0x2d3694 ldrdmi r0, r1, [r9], #251
 *
 * ══ §16/36 Shader_Load(unsigned char*, unsigned int, unsigned char*)  0x1e1cd8  size 844  211 条（0x1e1cd8..0x1e2024）
 * @func 0x1e1cd8 0x1e2024  size 844  211 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1e1ce8→0x544c88, 0x1e1d0c→0x544c84, 0x1e1efc→0x544c44, 0x1e1fdc→0x3eb70c
 * 调用序列: operator delete(void*)×2 / Shader_Load(unsigned char*, unsigned int, unsigned char*)+0x9c / AddShader(char*, int, char*, char*, char*, char*, char*, char*, char*, char*, char*, int, char*, int, char*, int, char*, int, char*, char*, int, unsigned int*) / Shader_Load(Shader*) / Shader_Load(unsigned char*, unsigned int, unsigned char*)+0xd4
 * 字段偏移 top8: 0x60×5 / 0x54×5 / 0x4×5 / 0x7c×4 / 0xc×4 / 0x78×3 / 0x74×3 / 0x70×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e1cd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e1cdc sub sp, sp, #140
 *   @0x1e1ce0 ldr r6, [pc, #0x320]
 *   @0x1e1ce4 mov r7, r0
 *   @0x1e1ce8 ldr r3, [pc, #0x31c]
 *   @0x1e1cec ldr r12, [r0]
 *   @0x1e1cf0 add r6, pc, r6
 *   @0x1e1cf4 str r6, [sp, #0x7c]
 *   @0x1e1cf8 str r12, [sp, #0x78]
 *   @0x1e1cfc ldr r8, [r6, r3]
 *   @0x1e1d00 ldr r3, [r8]
 *   @0x1e1d04 cmp r3, #0
 *   @0x1e1d08 ble 0x1e1d74 <_Z11Shader_LoadPhjS_+0x9c>
 *   @0x1e1d0c ldr r3, [pc, #0x2fc]
 *   @0x1e1d10 mov r4, #0
 *   @0x1e1d14 ldr r12, [sp, #0x7c]
 *   @0x1e1d18 mov r6, r4
 *   @0x1e1d1c ldr r9, [r12, r3]
 *   @0x1e1d20 ldr r3, [r9]
 *   @0x1e1d24 lsl r5, r4, #2
 *   @0x1e1d28 ldr r3, [r3, r4, lsl #2]
 *   @0x1e1d2c add r4, r4, #1
 *   @0x1e1d30 cmp r3, #0
 *   @0x1e1d34 beq 0x1e1d68 <_Z11Shader_LoadPhjS_+0x90>
 *   @0x1e1d38 ldr r0, [r3, #0x60]
 *   @0x1e1d3c cmp r0, #0
 *   @0x1e1d40 beq 0x1e1d58 <_Z11Shader_LoadPhjS_+0x80>
 *   @0x1e1d44 bl 0x27d1d0 <_ZdlPv>
 *   @0x1e1d48 ldr r3, [r9]
 *   @0x1e1d4c ldr r2, [r3, r5]
 *   @0x1e1d50 str r6, [r2, #0x60]
 *   @0x1e1d54 ldr r3, [r3, r5]
 *   @0x1e1d58 mov r0, r3
 *   @0x1e1d5c bl 0x27d1d0 <_ZdlPv>
 *   @0x1e1d60 ldr r3, [r9]
 *   @0x1e1d64 str r6, [r3, r5]
 *   @0x1e1d68 ldr r3, [r8]
 *   @0x1e1d6c cmp r3, r4
 *   @0x1e1d70 bgt 0x1e1d20 <_Z11Shader_LoadPhjS_+0x48>
 *   @0x1e1d74 ldr r6, [sp, #0x78]
 *   @0x1e1d78 mov r3, #0
 *   @0x1e1d7c str r3, [r8]
 *   @0x1e1d80 cmp r6, #0
 *   @0x1e1d84 beq 0x1e1fcc <_Z11Shader_LoadPhjS_+0x2f4>
 *   @0x1e1d88 ldr r6, [pc, #0x284]
 *   @0x1e1d8c mov r5, r3
 *   @0x1e1d90 ldr r12, [pc, #0x280]
 *   @0x1e1d94 add r6, pc, r6
 *   @0x1e1d98 str r7, [sp, #0x54]
 *   @0x1e1d9c add r12, pc, r12
 *   @0x1e1da0 str r6, [sp, #0x80]
 *   @0x1e1da4 str r12, [sp, #0x84]
 *   @0x1e1da8 b 0x1e1ee4 <_Z11Shader_LoadPhjS_+0x20c>
 *   @0x1e1dac mov lr, #0
 *   @0x1e1db0 str lr, [sp, #0x74]
 *   @0x1e1db4 mov r11, lr
 *   @0x1e1db8 str lr, [sp, #0x70]
 *   @0x1e1dbc str lr, [sp, #0x6c]
 *   @0x1e1dc0 str lr, [sp, #0x58]
 *   @0x1e1dc4 str lr, [sp, #0x68]
 *   @0x1e1dc8 str lr, [sp, #0x64]
 *   @0x1e1dcc str lr, [sp, #0x60]
 *   @0x1e1dd0 str lr, [sp, #0x5c]
 *   @0x1e1dd4 ldr r0, [r3, r4]
 *   @0x1e1dd8 ldr r2, [r12, #0x8]
 *   @0x1e1ddc ldr r3, [r12, #0xc]
 *   @0x1e1de0 cmp r0, #0
 *   @0x1e1de4 ldr r10, [r12, #0x10]
 *   @0x1e1de8 addne r0, r4, r0
 *   @0x1e1dec cmp r2, #0
 *   @0x1e1df0 ldr r9, [r12, #0x14]
 *   @0x1e1df4 addne r2, r4, r2
 *   @0x1e1df8 cmp r3, #0
 *   @0x1e1dfc ldr r8, [r12, #0x18]
 *   @0x1e1e00 addne r3, r4, r3
 *   @0x1e1e04 cmp r10, #0
 *   @0x1e1e08 ldr r7, [r12, #0x1c]
 *   @0x1e1e0c addne r10, r4, r10
 *   @0x1e1e10 cmp r9, #0
 *   @0x1e1e14 ldr r6, [r12, #0x20]
 *   @0x1e1e18 addne r9, r4, r9
 *   @0x1e1e1c cmp r8, #0
 *   @0x1e1e20 ldr r12, [r12, #0x24]
 *   @0x1e1e24 addne r8, r4, r8
 *   @0x1e1e28 cmp r7, #0
 *   @0x1e1e2c addne r7, r4, r7
 *   @0x1e1e30 cmp r6, #0
 *   @0x1e1e34 addne r6, r4, r6
 *   @0x1e1e38 cmp r12, #0
 *   @0x1e1e3c addne r4, r4, r12
 *   @0x1e1e40 str r6, [sp, #0x10]
 *   @0x1e1e44 moveq r4, r12
 *   @0x1e1e48 ldr r6, [sp, #0x6c]
 *   @0x1e1e4c ldr r12, [sp, #0x5c]
 *   @0x1e1e50 str lr, [sp, #0x34]
 *   @0x1e1e54 str r6, [sp, #0x1c]
 *   @0x1e1e58 str r12, [sp, #0x18]
 *   @0x1e1e5c ldr r6, [sp, #0x70]
 *   @0x1e1e60 ldr r12, [sp, #0x60]
 *   @0x1e1e64 ldr lr, [sp, #0x58]
 *   @0x1e1e68 str r6, [sp, #0x24]
 *   @0x1e1e6c str r12, [sp, #0x20]
 *   @0x1e1e70 ldr r6, [sp, #0x74]
 *   @0x1e1e74 ldr r12, [sp, #0x64]
 *   @0x1e1e78 str lr, [sp, #0x38]
 *   @0x1e1e7c str r6, [sp, #0x2c]
 *   @0x1e1e80 str r12, [sp, #0x28]
 *   @0x1e1e84 ldr r6, [sp, #0x4c]
 *   @0x1e1e88 ldr r12, [sp, #0x68]
 *   @0x1e1e8c str r4, [sp, #0x14]
 *   @0x1e1e90 str r10, [sp]
 *   @0x1e1e94 str r12, [sp, #0x30]
 *   @0x1e1e98 str r9, [sp, #0x4]
 *   @0x1e1e9c str r8, [sp, #0x8]
 *   @0x1e1ea0 str r7, [sp, #0xc]
 *   @0x1e1ea4 str r11, [sp, #0x3c]
 *   @0x1e1ea8 str r6, [sp, #0x40]
 *   @0x1e1eac ldr r12, [sp, #0x50]
 *   @0x1e1eb0 str r12, [sp, #0x44]
 *   @0x1e1eb4 bl 0x1e1350 <_Z9AddShaderPciS_S_S_S_S_S_S_S_S_iS_iS_iS_iS_S_iPj>
 *   @0x1e1eb8 mov r4, r0
 *   @0x1e1ebc bl 0x1884f4 <_Z11Shader_LoadP6Shader>
 *   @0x1e1ec0 cmp r0, #0
 *   @0x1e1ec4 bne 0x1e1ed4 <_Z11Shader_LoadPhjS_+0x1fc>
 *   @0x1e1ec8 ldr r3, [r4, #0x54]
 *   @0x1e1ecc cmp r3, #0
 *   @0x1e1ed0 beq 0x1e1fd8 <_Z11Shader_LoadPhjS_+0x300>
 *   @0x1e1ed4 ldr r6, [sp, #0x78]
 *   @0x1e1ed8 add r5, r5, #1
 *   @0x1e1edc cmp r5, r6
 *   @0x1e1ee0 beq 0x1e1fcc <_Z11Shader_LoadPhjS_+0x2f4>
 *   @0x1e1ee4 ldr r6, [sp, #0x54]
 *   @0x1e1ee8 ldr r3, [r6, #0x4]!
 *   @0x1e1eec cmp r3, #0
 *   @0x1e1ef0 str r6, [sp, #0x54]
 *   @0x1e1ef4 beq 0x1e1ed4 <_Z11Shader_LoadPhjS_+0x1fc>
 *   @0x1e1ef8 ldr r12, [sp, #0x7c]
 *   @0x1e1efc ldr r2, [pc, #0x118]
 *   @0x1e1f00 ldr r2, [r12, r2]
 *   @0x1e1f04 ldr r4, [r2]
 *   @0x1e1f08 adds r12, r3, r4
 *   @0x1e1f0c beq 0x1e1ed4 <_Z11Shader_LoadPhjS_+0x1fc>
 *   @0x1e1f10 ldr r1, [r12, #0x4]
 *   @0x1e1f14 add lr, r12, #44
 *   @0x1e1f18 ldr r6, [r12, #0x28]
 *   @0x1e1f1c cmp r1, #0
 *   @0x1e1f20 str lr, [sp, #0x50]
 *   @0x1e1f24 str r6, [sp, #0x4c]
 *   @0x1e1f28 bge 0x1e1dac <_Z11Shader_LoadPhjS_+0xd4>
 *   @0x1e1f2c ldr r0, [lr, r6, lsl #2]
 *   @0x1e1f30 bic r1, r1, #-2147483648
 *   @0x1e1f34 add r2, lr, r6, lsl #2
 *   @0x1e1f38 cmp r0, #0
 *   @0x1e1f3c ble 0x1e1dac <_Z11Shader_LoadPhjS_+0xd4>
 *   @0x1e1f40 ldr lr, [r2, #0x4]
 *   @0x1e1f44 ldr r6, [r2, #0x8]
 *   @0x1e1f48 cmp lr, #0
 *   @0x1e1f4c addne lr, r4, lr
 *   @0x1e1f50 str lr, [sp, #0x5c]
 *   @0x1e1f54 ldr lr, [r2, #0xc]
 *   @0x1e1f58 str r6, [sp, #0x6c]
 *   @0x1e1f5c cmp lr, #0
 *   @0x1e1f60 ldr r6, [r2, #0x10]
 *   @0x1e1f64 addne lr, r4, lr
 *   @0x1e1f68 str lr, [sp, #0x60]
 *   @0x1e1f6c ldr lr, [r2, #0x14]
 *   @0x1e1f70 str r6, [sp, #0x70]
 *   @0x1e1f74 cmp lr, #0
 *   @0x1e1f78 ldr r6, [r2, #0x18]
 *   @0x1e1f7c addne lr, r4, lr
 *   @0x1e1f80 str lr, [sp, #0x64]
 *   @0x1e1f84 ldr lr, [r2, #0x1c]
 *   @0x1e1f88 str r6, [sp, #0x74]
 *   @0x1e1f8c cmp lr, #0
 *   @0x1e1f90 addne lr, r4, lr
 *   @0x1e1f94 cmp r0, #1
 *   @0x1e1f98 str lr, [sp, #0x68]
 *   @0x1e1f9c moveq r11, #0
 *   @0x1e1fa0 ldr lr, [r2, #0x20]
 *   @0x1e1fa4 streq r11, [sp, #0x58]
 *   @0x1e1fa8 beq 0x1e1dd4 <_Z11Shader_LoadPhjS_+0xfc>
 *   @0x1e1fac ldr r0, [r2, #0x24]
 *   @0x1e1fb0 ldr r11, [r2, #0x2c]
 *   @0x1e1fb4 cmp r0, #0
 *   @0x1e1fb8 addne r0, r4, r0
 *   @0x1e1fbc cmp r11, #0
 *   @0x1e1fc0 str r0, [sp, #0x58]
 *   @0x1e1fc4 addne r11, r4, r11
 *   @0x1e1fc8 b 0x1e1dd4 <_Z11Shader_LoadPhjS_+0xfc>
 *   @0x1e1fcc mov r0, #1
 *   @0x1e1fd0 add sp, sp, #140
 *   @0x1e1fd4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e1fd8 ldr r6, [sp, #0x7c]
 *   @0x1e1fdc ldr r3, [pc, #0x3c]
 *   @0x1e1fe0 ldr r1, [sp, #0x80]
 *   @0x1e1fe4 ldr r2, [r4, #0x4]
 *   @0x1e1fe8 ldr r3, [r6, r3]
 *   @0x1e1fec ldr r0, [r3]
 *   @0x1e1ff0 ldr r3, [r0]
 *   @0x1e1ff4 ldr r3, [r3, #0xc]
 *   @0x1e1ff8 blx r3
 *   @0x1e1ffc ldr r12, [sp, #0x84]
 *   @0x1e2000 str r12, [r4, #0x54]
 *   @0x1e2004 b 0x1e1ed4 <_Z11Shader_LoadPhjS_+0x1fc>
 *   @0x1e2008 eoreq pc, r0, r0, ror #30
 *   @0x1e200c .word 0xfffff0f4
 *   @0x1e2010 .word 0xfffff0f8
 *   @0x1e2014 andseq r0, r7, r12
 *   @0x1e2018 andseq r0, r7, r0, asr r0
 *   @0x1e201c .word 0xffffbcf4
 *   @0x1e2020 .word 0xffffbac4
 *
 * ══ §17/36 CDS_List::Assign(CDS_List*)  0x20e61c  size 844  211 条（0x20e61c..0x20e968）
 * @func 0x20e61c 0x20e968  size 844  211 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CDS_List::Assign(CDS_List*)+0x128 / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x4×40 / 0x8×21 / 0xc×11 / 0x318×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20e61c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20e620 subs r11, r1, #0
 *   @0x20e624 sub sp, sp, #20
 *   @0x20e628 str r0, [sp, #0xc]
 *   @0x20e62c beq 0x20e958 <_ZN8CDS_List6AssignEPS_+0x33c>
 *   @0x20e630 ldr r12, [sp, #0xc]
 *   @0x20e634 movw r3, #0x44d
 *   @0x20e638 ldr r1, [r11, #0x8]
 *   @0x20e63c ldr lr, [r11, #0x4]
 *   @0x20e640 add r0, r12, #12
 *   @0x20e644 ldr r2, [pc, #0x318]
 *   @0x20e648 lsl r1, r1, #4
 *   @0x20e64c str lr, [r12, #0x4]
 *   @0x20e650 add r2, pc, r2
 *   @0x20e654 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x20e658 ldr r3, [r11, #0x8]
 *   @0x20e65c ldr r12, [sp, #0xc]
 *   @0x20e660 str r3, [r12, #0x8]
 *   @0x20e664 ldr r3, [r11, #0x8]
 *   @0x20e668 cmp r3, #0
 *   @0x20e66c ble 0x20e744 <_ZN8CDS_List6AssignEPS_+0x128>
 *   @0x20e670 mov r7, #0
 *   @0x20e674 mov r9, r7
 *   @0x20e678 ldr r12, [sp, #0xc]
 *   @0x20e67c lsl r4, r7, #4
 *   @0x20e680 ldr r10, [r11, #0xc]
 *   @0x20e684 ldr r6, [r12, #0xc]
 *   @0x20e688 add r8, r10, r4
 *   @0x20e68c add r5, r6, r4
 *   @0x20e690 ldr r1, [r5, #0xc]
 *   @0x20e694 bic r2, r1, #-16777216
 *   @0x20e698 cmp r2, #1
 *   @0x20e69c beq 0x20e7c8 <_ZN8CDS_List6AssignEPS_+0x1ac>
 *   @0x20e6a0 cmp r2, #2
 *   @0x20e6a4 bne 0x20e6c8 <_ZN8CDS_List6AssignEPS_+0xac>
 *   @0x20e6a8 sub r1, r1, #1
 *   @0x20e6ac bic r1, r1, #-16777216
 *   @0x20e6b0 bic r1, r1, #3
 *   @0x20e6b4 cmp r1, #0
 *   @0x20e6b8 beq 0x20e858 <_ZN8CDS_List6AssignEPS_+0x23c>
 *   @0x20e6bc mov r2, #5
 *   @0x20e6c0 str r9, [r5, #0x8]
 *   @0x20e6c4 str r2, [r5, #0xc]
 *   @0x20e6c8 ldr r2, [r8, #0xc]
 *   @0x20e6cc ldr r1, [r8, #0x8]
 *   @0x20e6d0 str r9, [r6, r4]
 *   @0x20e6d4 str r2, [r5, #0xc]
 *   @0x20e6d8 ldr r2, [r8, #0xc]
 *   @0x20e6dc str r1, [r5, #0x8]
 *   @0x20e6e0 bic r2, r2, #-16777216
 *   @0x20e6e4 cmp r2, #14
 *   @0x20e6e8 addls pc, pc, r2, lsl #2
 *   @0x20e6ec b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118>
 *   @0x20e6f0 b 0x20e74c <_ZN8CDS_List6AssignEPS_+0x130>
 *   @0x20e6f4 b 0x20e7b0 <_ZN8CDS_List6AssignEPS_+0x194>
 *   @0x20e6f8 b 0x20e784 <_ZN8CDS_List6AssignEPS_+0x168>
 *   @0x20e6fc b 0x20e72c <_ZN8CDS_List6AssignEPS_+0x110>
 *   @0x20e700 b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118>
 *   @0x20e704 b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118>
 *   @0x20e708 b 0x20e760 <_ZN8CDS_List6AssignEPS_+0x144>
 *   @0x20e70c b 0x20e72c <_ZN8CDS_List6AssignEPS_+0x110>
 *   @0x20e710 b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118>
 *   @0x20e714 b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118>
 *   @0x20e718 b 0x20e74c <_ZN8CDS_List6AssignEPS_+0x130>
 *   @0x20e71c b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118>
 *   @0x20e720 b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118>
 *   @0x20e724 b 0x20e74c <_ZN8CDS_List6AssignEPS_+0x130>
 *   @0x20e728 b 0x20e72c <_ZN8CDS_List6AssignEPS_+0x110>
 *   @0x20e72c ldr r3, [r10, r4]
 *   @0x20e730 str r3, [r6, r4]
 *   @0x20e734 ldr r3, [r11, #0x8]
 *   @0x20e738 add r7, r7, #1
 *   @0x20e73c cmp r3, r7
 *   @0x20e740 bgt 0x20e678 <_ZN8CDS_List6AssignEPS_+0x5c>
 *   @0x20e744 add sp, sp, #20
 *   @0x20e748 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20e74c ldr r2, [r10, r4]
 *   @0x20e750 ldr r3, [r8, #0x4]
 *   @0x20e754 str r2, [r6, r4]
 *   @0x20e758 str r3, [r5, #0x4]
 *   @0x20e75c b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118>
 *   @0x20e760 ldr r2, [r10, r4]
 *   @0x20e764 str r2, [r6, r4]
 *   @0x20e768 ldr r2, [r10, r4]
 *   @0x20e76c cmp r2, #0
 *   @0x20e770 beq 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118>
 *   @0x20e774 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20e778 ldr r1, [r10, r4]
 *   @0x20e77c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20e780 b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118>
 *   @0x20e784 ldr r3, [r10, r4]
 *   @0x20e788 cmp r3, #0
 *   @0x20e78c str r3, [r6, r4]
 *   @0x20e790 beq 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118>
 *   @0x20e794 ldr r1, [r3, #0x8]
 *   @0x20e798 ldr r2, [r3]
 *   @0x20e79c cmp r1, #0
 *   @0x20e7a0 streq r5, [r3, #0x8]
 *   @0x20e7a4 add r2, r2, #1
 *   @0x20e7a8 str r2, [r3]
 *   @0x20e7ac b 0x20e734 <_ZN8CDS_List6AssignEPS_+0x118>
 *   @0x20e7b0 ldr r3, [r10, r4]
 *   @0x20e7b4 cmp r3, #0
 *   @0x20e7b8 ldrne r2, [r3, #0x4]
 *   @0x20e7bc addne r2, r2, #1
 *   @0x20e7c0 strne r2, [r3, #0x4]
 *   @0x20e7c4 b 0x20e730 <_ZN8CDS_List6AssignEPS_+0x114>
 *   @0x20e7c8 ldr r2, [r6, r7, lsl #4]
 *   @0x20e7cc cmp r2, #0
 *   @0x20e7d0 beq 0x20e7f8 <_ZN8CDS_List6AssignEPS_+0x1dc>
 *   @0x20e7d4 str r2, [sp, #0x4]
 *   @0x20e7d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20e7dc ldr r2, [sp, #0x4]
 *   @0x20e7e0 ldr r1, [r2, #0x4]
 *   @0x20e7e4 sub r1, r1, #1
 *   @0x20e7e8 str r1, [r2, #0x4]
 *   @0x20e7ec cmp r1, #0
 *   @0x20e7f0 beq 0x20e800 <_ZN8CDS_List6AssignEPS_+0x1e4>
 *   @0x20e7f4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20e7f8 str r9, [r6, r4]
 *   @0x20e7fc b 0x20e6c8 <_ZN8CDS_List6AssignEPS_+0xac>
 *   @0x20e800 ldr r0, [r2]
 *   @0x20e804 str r1, [sp, #0x8]
 *   @0x20e808 str r2, [sp, #0x4]
 *   @0x20e80c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20e810 ldr r2, [sp, #0x4]
 *   @0x20e814 ldr r1, [sp, #0x8]
 *   @0x20e818 str r1, [r2]
 *   @0x20e81c str r1, [r2, #0x8]
 *   @0x20e820 str r2, [sp, #0x4]
 *   @0x20e824 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20e828 ldr r2, [sp, #0x4]
 *   @0x20e82c ldr r1, [r2, #0x4]
 *   @0x20e830 sub r1, r1, #1
 *   @0x20e834 str r1, [r2, #0x4]
 *   @0x20e838 cmp r1, #0
 *   @0x20e83c beq 0x20e864 <_ZN8CDS_List6AssignEPS_+0x248>
 *   @0x20e840 str r2, [sp, #0x4]
 *   @0x20e844 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20e848 ldr r2, [sp, #0x4]
 *   @0x20e84c mov r0, r2
 *   @0x20e850 bl 0x27d1d0 <_ZdlPv>
 *   @0x20e854 b 0x20e7f4 <_ZN8CDS_List6AssignEPS_+0x1d8>
 *   @0x20e858 mov r0, r5
 *   @0x20e85c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20e860 b 0x20e6bc <_ZN8CDS_List6AssignEPS_+0xa0>
 *   @0x20e864 ldr r0, [r2]
 *   @0x20e868 str r1, [sp, #0x8]
 *   @0x20e86c str r2, [sp, #0x4]
 *   @0x20e870 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20e874 ldr r2, [sp, #0x4]
 *   @0x20e878 ldr r1, [sp, #0x8]
 *   @0x20e87c str r1, [r2]
 *   @0x20e880 str r1, [r2, #0x8]
 *   @0x20e884 str r2, [sp, #0x4]
 *   @0x20e888 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20e88c ldr r2, [sp, #0x4]
 *   @0x20e890 ldr r1, [r2, #0x4]
 *   @0x20e894 sub r1, r1, #1
 *   @0x20e898 str r1, [r2, #0x4]
 *   @0x20e89c cmp r1, #0
 *   @0x20e8a0 beq 0x20e8c0 <_ZN8CDS_List6AssignEPS_+0x2a4>
 *   @0x20e8a4 str r2, [sp, #0x4]
 *   @0x20e8a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20e8ac ldr r2, [sp, #0x4]
 *   @0x20e8b0 mov r0, r2
 *   @0x20e8b4 bl 0x27d1d0 <_ZdlPv>
 *   @0x20e8b8 ldr r2, [sp, #0x4]
 *   @0x20e8bc b 0x20e840 <_ZN8CDS_List6AssignEPS_+0x224>
 *   @0x20e8c0 ldr r0, [r2]
 *   @0x20e8c4 str r1, [sp, #0x8]
 *   @0x20e8c8 str r2, [sp, #0x4]
 *   @0x20e8cc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20e8d0 ldr r2, [sp, #0x4]
 *   @0x20e8d4 ldr r1, [sp, #0x8]
 *   @0x20e8d8 str r1, [r2]
 *   @0x20e8dc str r1, [r2, #0x8]
 *   @0x20e8e0 str r2, [sp, #0x4]
 *   @0x20e8e4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20e8e8 ldr r2, [sp, #0x4]
 *   @0x20e8ec ldr r1, [r2, #0x4]
 *   @0x20e8f0 sub r1, r1, #1
 *   @0x20e8f4 str r1, [r2, #0x4]
 *   @0x20e8f8 cmp r1, #0
 *   @0x20e8fc bne 0x20e93c <_ZN8CDS_List6AssignEPS_+0x320>
 *   @0x20e900 ldr r0, [r2]
 *   @0x20e904 str r1, [sp, #0x8]
 *   @0x20e908 str r2, [sp, #0x4]
 *   @0x20e90c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20e910 ldr r2, [sp, #0x4]
 *   @0x20e914 ldr r1, [sp, #0x8]
 *   @0x20e918 mov r0, r2
 *   @0x20e91c str r1, [r2]
 *   @0x20e920 str r1, [r2, #0x8]
 *   @0x20e924 str r2, [sp, #0x4]
 *   @0x20e928 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20e92c ldr r2, [sp, #0x4]
 *   @0x20e930 mov r0, r2
 *   @0x20e934 bl 0x27d1d0 <_ZdlPv>
 *   @0x20e938 ldr r2, [sp, #0x4]
 *   @0x20e93c str r2, [sp, #0x4]
 *   @0x20e940 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20e944 ldr r2, [sp, #0x4]
 *   @0x20e948 mov r0, r2
 *   @0x20e94c bl 0x27d1d0 <_ZdlPv>
 *   @0x20e950 ldr r2, [sp, #0x4]
 *   @0x20e954 b 0x20e8a4 <_ZN8CDS_List6AssignEPS_+0x288>
 *   @0x20e958 add sp, sp, #20
 *   @0x20e95c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20e960 b 0x20e478 <_ZN8CDS_List5ClearEv>
 *   @0x20e964 mulseq r4, r12, r1
 *
 * ══ §18/36 CDS_Stack::Assign(CDS_Stack*)  0x20f514  size 844  211 条（0x20f514..0x20f860）
 * @func 0x20f514 0x20f860  size 844  211 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CDS_Stack::Assign(CDS_Stack*)+0x128 / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x4×40 / 0x8×21 / 0xc×11 / 0x318×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20f514 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20f518 subs r11, r1, #0
 *   @0x20f51c sub sp, sp, #20
 *   @0x20f520 str r0, [sp, #0xc]
 *   @0x20f524 beq 0x20f850 <_ZN9CDS_Stack6AssignEPS_+0x33c>
 *   @0x20f528 ldr r12, [sp, #0xc]
 *   @0x20f52c movw r3, #0x1e2
 *   @0x20f530 ldr r1, [r11, #0x8]
 *   @0x20f534 ldr lr, [r11, #0x4]
 *   @0x20f538 add r0, r12, #12
 *   @0x20f53c ldr r2, [pc, #0x318]
 *   @0x20f540 lsl r1, r1, #4
 *   @0x20f544 str lr, [r12, #0x4]
 *   @0x20f548 add r2, pc, r2
 *   @0x20f54c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x20f550 ldr r3, [r11, #0x8]
 *   @0x20f554 ldr r12, [sp, #0xc]
 *   @0x20f558 str r3, [r12, #0x8]
 *   @0x20f55c ldr r3, [r11, #0x8]
 *   @0x20f560 cmp r3, #0
 *   @0x20f564 ble 0x20f63c <_ZN9CDS_Stack6AssignEPS_+0x128>
 *   @0x20f568 mov r7, #0
 *   @0x20f56c mov r9, r7
 *   @0x20f570 ldr r12, [sp, #0xc]
 *   @0x20f574 lsl r4, r7, #4
 *   @0x20f578 ldr r10, [r11, #0xc]
 *   @0x20f57c ldr r6, [r12, #0xc]
 *   @0x20f580 add r8, r10, r4
 *   @0x20f584 add r5, r6, r4
 *   @0x20f588 ldr r1, [r5, #0xc]
 *   @0x20f58c bic r2, r1, #-16777216
 *   @0x20f590 cmp r2, #1
 *   @0x20f594 beq 0x20f6c0 <_ZN9CDS_Stack6AssignEPS_+0x1ac>
 *   @0x20f598 cmp r2, #2
 *   @0x20f59c bne 0x20f5c0 <_ZN9CDS_Stack6AssignEPS_+0xac>
 *   @0x20f5a0 sub r1, r1, #1
 *   @0x20f5a4 bic r1, r1, #-16777216
 *   @0x20f5a8 bic r1, r1, #3
 *   @0x20f5ac cmp r1, #0
 *   @0x20f5b0 beq 0x20f750 <_ZN9CDS_Stack6AssignEPS_+0x23c>
 *   @0x20f5b4 mov r2, #5
 *   @0x20f5b8 str r9, [r5, #0x8]
 *   @0x20f5bc str r2, [r5, #0xc]
 *   @0x20f5c0 ldr r2, [r8, #0xc]
 *   @0x20f5c4 ldr r1, [r8, #0x8]
 *   @0x20f5c8 str r9, [r6, r4]
 *   @0x20f5cc str r2, [r5, #0xc]
 *   @0x20f5d0 ldr r2, [r8, #0xc]
 *   @0x20f5d4 str r1, [r5, #0x8]
 *   @0x20f5d8 bic r2, r2, #-16777216
 *   @0x20f5dc cmp r2, #14
 *   @0x20f5e0 addls pc, pc, r2, lsl #2
 *   @0x20f5e4 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118>
 *   @0x20f5e8 b 0x20f644 <_ZN9CDS_Stack6AssignEPS_+0x130>
 *   @0x20f5ec b 0x20f6a8 <_ZN9CDS_Stack6AssignEPS_+0x194>
 *   @0x20f5f0 b 0x20f67c <_ZN9CDS_Stack6AssignEPS_+0x168>
 *   @0x20f5f4 b 0x20f624 <_ZN9CDS_Stack6AssignEPS_+0x110>
 *   @0x20f5f8 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118>
 *   @0x20f5fc b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118>
 *   @0x20f600 b 0x20f658 <_ZN9CDS_Stack6AssignEPS_+0x144>
 *   @0x20f604 b 0x20f624 <_ZN9CDS_Stack6AssignEPS_+0x110>
 *   @0x20f608 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118>
 *   @0x20f60c b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118>
 *   @0x20f610 b 0x20f644 <_ZN9CDS_Stack6AssignEPS_+0x130>
 *   @0x20f614 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118>
 *   @0x20f618 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118>
 *   @0x20f61c b 0x20f644 <_ZN9CDS_Stack6AssignEPS_+0x130>
 *   @0x20f620 b 0x20f624 <_ZN9CDS_Stack6AssignEPS_+0x110>
 *   @0x20f624 ldr r3, [r10, r4]
 *   @0x20f628 str r3, [r6, r4]
 *   @0x20f62c ldr r3, [r11, #0x8]
 *   @0x20f630 add r7, r7, #1
 *   @0x20f634 cmp r3, r7
 *   @0x20f638 bgt 0x20f570 <_ZN9CDS_Stack6AssignEPS_+0x5c>
 *   @0x20f63c add sp, sp, #20
 *   @0x20f640 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20f644 ldr r2, [r10, r4]
 *   @0x20f648 ldr r3, [r8, #0x4]
 *   @0x20f64c str r2, [r6, r4]
 *   @0x20f650 str r3, [r5, #0x4]
 *   @0x20f654 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118>
 *   @0x20f658 ldr r2, [r10, r4]
 *   @0x20f65c str r2, [r6, r4]
 *   @0x20f660 ldr r2, [r10, r4]
 *   @0x20f664 cmp r2, #0
 *   @0x20f668 beq 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118>
 *   @0x20f66c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20f670 ldr r1, [r10, r4]
 *   @0x20f674 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20f678 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118>
 *   @0x20f67c ldr r3, [r10, r4]
 *   @0x20f680 cmp r3, #0
 *   @0x20f684 str r3, [r6, r4]
 *   @0x20f688 beq 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118>
 *   @0x20f68c ldr r1, [r3, #0x8]
 *   @0x20f690 ldr r2, [r3]
 *   @0x20f694 cmp r1, #0
 *   @0x20f698 streq r5, [r3, #0x8]
 *   @0x20f69c add r2, r2, #1
 *   @0x20f6a0 str r2, [r3]
 *   @0x20f6a4 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118>
 *   @0x20f6a8 ldr r3, [r10, r4]
 *   @0x20f6ac cmp r3, #0
 *   @0x20f6b0 ldrne r2, [r3, #0x4]
 *   @0x20f6b4 addne r2, r2, #1
 *   @0x20f6b8 strne r2, [r3, #0x4]
 *   @0x20f6bc b 0x20f628 <_ZN9CDS_Stack6AssignEPS_+0x114>
 *   @0x20f6c0 ldr r2, [r6, r7, lsl #4]
 *   @0x20f6c4 cmp r2, #0
 *   @0x20f6c8 beq 0x20f6f0 <_ZN9CDS_Stack6AssignEPS_+0x1dc>
 *   @0x20f6cc str r2, [sp, #0x4]
 *   @0x20f6d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20f6d4 ldr r2, [sp, #0x4]
 *   @0x20f6d8 ldr r1, [r2, #0x4]
 *   @0x20f6dc sub r1, r1, #1
 *   @0x20f6e0 str r1, [r2, #0x4]
 *   @0x20f6e4 cmp r1, #0
 *   @0x20f6e8 beq 0x20f6f8 <_ZN9CDS_Stack6AssignEPS_+0x1e4>
 *   @0x20f6ec bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20f6f0 str r9, [r6, r4]
 *   @0x20f6f4 b 0x20f5c0 <_ZN9CDS_Stack6AssignEPS_+0xac>
 *   @0x20f6f8 ldr r0, [r2]
 *   @0x20f6fc str r1, [sp, #0x8]
 *   @0x20f700 str r2, [sp, #0x4]
 *   @0x20f704 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20f708 ldr r2, [sp, #0x4]
 *   @0x20f70c ldr r1, [sp, #0x8]
 *   @0x20f710 str r1, [r2]
 *   @0x20f714 str r1, [r2, #0x8]
 *   @0x20f718 str r2, [sp, #0x4]
 *   @0x20f71c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20f720 ldr r2, [sp, #0x4]
 *   @0x20f724 ldr r1, [r2, #0x4]
 *   @0x20f728 sub r1, r1, #1
 *   @0x20f72c str r1, [r2, #0x4]
 *   @0x20f730 cmp r1, #0
 *   @0x20f734 beq 0x20f75c <_ZN9CDS_Stack6AssignEPS_+0x248>
 *   @0x20f738 str r2, [sp, #0x4]
 *   @0x20f73c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20f740 ldr r2, [sp, #0x4]
 *   @0x20f744 mov r0, r2
 *   @0x20f748 bl 0x27d1d0 <_ZdlPv>
 *   @0x20f74c b 0x20f6ec <_ZN9CDS_Stack6AssignEPS_+0x1d8>
 *   @0x20f750 mov r0, r5
 *   @0x20f754 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20f758 b 0x20f5b4 <_ZN9CDS_Stack6AssignEPS_+0xa0>
 *   @0x20f75c ldr r0, [r2]
 *   @0x20f760 str r1, [sp, #0x8]
 *   @0x20f764 str r2, [sp, #0x4]
 *   @0x20f768 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20f76c ldr r2, [sp, #0x4]
 *   @0x20f770 ldr r1, [sp, #0x8]
 *   @0x20f774 str r1, [r2]
 *   @0x20f778 str r1, [r2, #0x8]
 *   @0x20f77c str r2, [sp, #0x4]
 *   @0x20f780 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20f784 ldr r2, [sp, #0x4]
 *   @0x20f788 ldr r1, [r2, #0x4]
 *   @0x20f78c sub r1, r1, #1
 *   @0x20f790 str r1, [r2, #0x4]
 *   @0x20f794 cmp r1, #0
 *   @0x20f798 beq 0x20f7b8 <_ZN9CDS_Stack6AssignEPS_+0x2a4>
 *   @0x20f79c str r2, [sp, #0x4]
 *   @0x20f7a0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20f7a4 ldr r2, [sp, #0x4]
 *   @0x20f7a8 mov r0, r2
 *   @0x20f7ac bl 0x27d1d0 <_ZdlPv>
 *   @0x20f7b0 ldr r2, [sp, #0x4]
 *   @0x20f7b4 b 0x20f738 <_ZN9CDS_Stack6AssignEPS_+0x224>
 *   @0x20f7b8 ldr r0, [r2]
 *   @0x20f7bc str r1, [sp, #0x8]
 *   @0x20f7c0 str r2, [sp, #0x4]
 *   @0x20f7c4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20f7c8 ldr r2, [sp, #0x4]
 *   @0x20f7cc ldr r1, [sp, #0x8]
 *   @0x20f7d0 str r1, [r2]
 *   @0x20f7d4 str r1, [r2, #0x8]
 *   @0x20f7d8 str r2, [sp, #0x4]
 *   @0x20f7dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20f7e0 ldr r2, [sp, #0x4]
 *   @0x20f7e4 ldr r1, [r2, #0x4]
 *   @0x20f7e8 sub r1, r1, #1
 *   @0x20f7ec str r1, [r2, #0x4]
 *   @0x20f7f0 cmp r1, #0
 *   @0x20f7f4 bne 0x20f834 <_ZN9CDS_Stack6AssignEPS_+0x320>
 *   @0x20f7f8 ldr r0, [r2]
 *   @0x20f7fc str r1, [sp, #0x8]
 *   @0x20f800 str r2, [sp, #0x4]
 *   @0x20f804 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20f808 ldr r2, [sp, #0x4]
 *   @0x20f80c ldr r1, [sp, #0x8]
 *   @0x20f810 mov r0, r2
 *   @0x20f814 str r1, [r2]
 *   @0x20f818 str r1, [r2, #0x8]
 *   @0x20f81c str r2, [sp, #0x4]
 *   @0x20f820 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20f824 ldr r2, [sp, #0x4]
 *   @0x20f828 mov r0, r2
 *   @0x20f82c bl 0x27d1d0 <_ZdlPv>
 *   @0x20f830 ldr r2, [sp, #0x4]
 *   @0x20f834 str r2, [sp, #0x4]
 *   @0x20f838 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20f83c ldr r2, [sp, #0x4]
 *   @0x20f840 mov r0, r2
 *   @0x20f844 bl 0x27d1d0 <_ZdlPv>
 *   @0x20f848 ldr r2, [sp, #0x4]
 *   @0x20f84c b 0x20f79c <_ZN9CDS_Stack6AssignEPS_+0x288>
 *   @0x20f850 add sp, sp, #20
 *   @0x20f854 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20f858 b 0x20f270 <_ZN9CDS_Stack5ClearEv>
 *   @0x20f85c andseq r4, r4, r4, lsr #5
 *
 * ══ §19/36 b2WeldJoint::SolvePositionConstraints(b2SolverData const&)  0x2d2ffc  size 844  211 条（0x2d2ffc..0x2d3348）
 * @func 0x2d2ffc 0x2d3348  size 844  211 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / 0xb6700×2 / b2WeldJoint::SolvePositionConstraints(b2SolverData const&)+0x254 / b2Mat33::Solve22(b2Vec2 const&) const / b2Mat33::Solve33(b2Vec3 const&) const / 0xfebc8f70
 * 字段偏移 top8: 0x74×2 / 0x78×2 / 0x18×2
 * VFP 指令 165 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d2ffc ldr r2, [r0, #0x74]
 *   @0x2d3000 ldr r3, [r0, #0x78]
 *   @0x2d3004 push {r4, r5, lr}
 *   @0x2d3008 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2d300c mov r5, r1
 *   @0x2d3010 add r2, r2, r2, lsl #1
 *   @0x2d3014 ldr r1, [r1, #0x18]
 *   @0x2d3018 add r3, r3, r3, lsl #1
 *   @0x2d301c sub sp, sp, #84
 *   @0x2d3020 mov r4, r0
 *   @0x2d3024 add r2, r1, r2, lsl #2
 *   @0x2d3028 vldr s23, [r2, #8]
 *   @0x2d302c vmov r0, s23
 *   @0x2d3030 vldr s31, [r2]
 *   @0x2d3034 vldr s29, [r2, #4]
 *   @0x2d3038 add r3, r1, r3, lsl #2
 *   @0x2d303c vldr s12, [r3, #4]
 *   @0x2d3040 vldr s30, [r3]
 *   @0x2d3044 vldr s22, [r3, #8]
 *   @0x2d3048 vstr s12, [sp, #4]
 *   @0x2d304c bl 0xb6580 <sinf@plt>
 *   @0x2d3050 vmov s27, r0
 *   @0x2d3054 vmov r0, s23
 *   @0x2d3058 bl 0xb658c <cosf@plt>
 *   @0x2d305c vmov s28, r0
 *   @0x2d3060 vmov r0, s22
 *   @0x2d3064 bl 0xb6580 <sinf@plt>
 *   @0x2d3068 vmov s26, r0
 *   @0x2d306c vmov r0, s22
 *   @0x2d3070 bl 0xb658c <cosf@plt>
 *   @0x2d3074 vldr s14, [r4, #144]
 *   @0x2d3078 vldr s21, [r4, #84]
 *   @0x2d307c vsub.f32 s21, s21, s14
 *   @0x2d3080 vldr s10, [r4, #152]
 *   @0x2d3084 vldr s16, [r4, #92]
 *   @0x2d3088 vldr s11, [r4, #80]
 *   @0x2d308c vldr s13, [r4, #140]
 *   @0x2d3090 vldr s12, [r4, #88]
 *   @0x2d3094 vldr s14, [r4, #148]
 *   @0x2d3098 vldr s25, [r4, #156]
 *   @0x2d309c vldr s24, [r4, #160]
 *   @0x2d30a0 vldr s20, [r4, #164]
 *   @0x2d30a4 vldr s19, [r4, #168]
 *   @0x2d30a8 vsub.f32 s16, s16, s10
 *   @0x2d30ac vmul.f32 s17, s21, s27
 *   @0x2d30b0 vmov s15, r0
 *   @0x2d30b4 vmul.f32 s21, s21, s28
 *   @0x2d30b8 vsub.f32 s13, s11, s13
 *   @0x2d30bc vmul.f32 s18, s16, s15
 *   @0x2d30c0 vmul.f32 s16, s16, s26
 *   @0x2d30c4 vsub.f32 s14, s12, s14
 *   @0x2d30c8 vmla.f32 s21, s13, s27
 *   @0x2d30cc vnmls.f32 s17, s13, s28
 *   @0x2d30d0 vnmls.f32 s16, s14, s15
 *   @0x2d30d4 vmla.f32 s18, s14, s26
 *   @0x2d30d8 vadd.f32 s12, s25, s24
 *   @0x2d30dc vmul.f32 s14, s21, s21
 *   @0x2d30e0 vmul.f32 s15, s17, s17
 *   @0x2d30e4 vmov.f32 s11, s12
 *   @0x2d30e8 vmul.f32 s13, s16, s18
 *   @0x2d30ec vmla.f32 s11, s14, s20
 *   @0x2d30f0 vmul.f32 s14, s19, s18
 *   @0x2d30f4 vmla.f32 s12, s15, s20
 *   @0x2d30f8 vneg.f32 s10, s21
 *   @0x2d30fc vmul.f32 s7, s18, s18
 *   @0x2d3100 vmul.f32 s8, s16, s16
 *   @0x2d3104 vmul.f32 s9, s10, s17
 *   @0x2d3108 vmul.f32 s13, s13, s19
 *   @0x2d310c vmul.f32 s15, s19, s16
 *   @0x2d3110 vnmls.f32 s14, s20, s10
 *   @0x2d3114 vmla.f32 s15, s20, s17
 *   @0x2d3118 vstr s14, [sp, #68]
 *   @0x2d311c vstr s14, [sp, #52]
 *   @0x2d3120 vnmls.f32 s13, s9, s20
 *   @0x2d3124 vstr s15, [sp, #72]
 *   @0x2d3128 vstr s15, [sp, #64]
 *   @0x2d312c vmla.f32 s11, s7, s19
 *   @0x2d3130 vstr s13, [sp, #56]
 *   @0x2d3134 vstr s13, [sp, #48]
 *   @0x2d3138 vmla.f32 s12, s8, s19
 *   @0x2d313c vstr s11, [sp, #44]
 *   @0x2d3140 vadd.f32 s14, s20, s19
 *   @0x2d3144 vstr s12, [sp, #60]
 *   @0x2d3148 vstr s14, [sp, #76]
 *   @0x2d314c vldr s15, [r4, #68]
 *   @0x2d3150 vcmpe.f32 s15, #0
 *   @0x2d3154 vmrs APSR_nzcv, fpscr
 *   @0x2d3158 ble 0x2d3250 <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x254>
 *   @0x2d315c vldr s13, [sp, #4]
 *   @0x2d3160 vadd.f32 s15, s18, s13
 *   @0x2d3164 vsub.f32 s15, s15, s29
 *   @0x2d3168 vadd.f32 s14, s16, s30
 *   @0x2d316c vsub.f32 s15, s15, s21
 *   @0x2d3170 vsub.f32 s14, s14, s31
 *   @0x2d3174 vstr s15, [sp, #24]
 *   @0x2d3178 vmul.f32 s15, s15, s15
 *   @0x2d317c vsub.f32 s14, s14, s17
 *   @0x2d3180 vmla.f32 s15, s14, s14
 *   @0x2d3184 vstr s14, [sp, #20]
 *   @0x2d3188 vsqrt.f32 s26, s15
 *   @0x2d318c vcmp.f32 s26, s26
 *   @0x2d3190 vmrs APSR_nzcv, fpscr
 *   @0x2d3194 bne 0x2d331c <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x320>
 *   @0x2d3198 add r0, sp, #32
 *   @0x2d319c add r1, sp, #44
 *   @0x2d31a0 add r2, sp, #20
 *   @0x2d31a4 vldr s27, [pc, #400]
 *   @0x2d31a8 bl 0x2c68e8 <_ZNK7b2Mat337Solve22ERK6b2Vec2>
 *   @0x2d31ac vldr s14, [sp, #32]
 *   @0x2d31b0 vneg.f32 s14, s14
 *   @0x2d31b4 vldr s15, [sp, #36]
 *   @0x2d31b8 vmul.f32 s21, s21, s14
 *   @0x2d31bc vmul.f32 s18, s18, s14
 *   @0x2d31c0 vneg.f32 s15, s15
 *   @0x2d31c4 vnmls.f32 s21, s17, s15
 *   @0x2d31c8 vnmls.f32 s18, s16, s15
 *   @0x2d31cc vmls.f32 s31, s25, s14
 *   @0x2d31d0 vmla.f32 s30, s24, s14
 *   @0x2d31d4 vldr s14, [sp, #4]
 *   @0x2d31d8 vmls.f32 s23, s20, s21
 *   @0x2d31dc vmla.f32 s22, s19, s18
 *   @0x2d31e0 vmls.f32 s29, s25, s15
 *   @0x2d31e4 vmla.f32 s14, s24, s15
 *   @0x2d31e8 ldr r2, [r4, #0x74]
 *   @0x2d31ec vldr s15, [pc, #332]
 *   @0x2d31f0 ldr r3, [r4, #0x78]
 *   @0x2d31f4 ldr r1, [r5, #0x18]
 *   @0x2d31f8 add r2, r2, r2, lsl #1
 *   @0x2d31fc add r3, r3, r3, lsl #1
 *   @0x2d3200 add r2, r1, r2, lsl #2
 *   @0x2d3204 vstr s31, [r2]
 *   @0x2d3208 vstr s29, [r2, #4]
 *   @0x2d320c vstr s23, [r2, #8]
 *   @0x2d3210 add r3, r1, r3, lsl #2
 *   @0x2d3214 vstr s30, [r3]
 *   @0x2d3218 vstr s14, [r3, #4]
 *   @0x2d321c vstr s22, [r3, #8]
 *   @0x2d3220 vcmpe.f32 s26, s15
 *   @0x2d3224 vmrs APSR_nzcv, fpscr
 *   @0x2d3228 movhi r0, #0
 *   @0x2d322c bhi 0x2d3244 <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x248>
 *   @0x2d3230 vldr s15, [pc, #268]
 *   @0x2d3234 vcmpe.f32 s27, s15
 *   @0x2d3238 vmrs APSR_nzcv, fpscr
 *   @0x2d323c movhi r0, #0
 *   @0x2d3240 movls r0, #1
 *   @0x2d3244 add sp, sp, #84
 *   @0x2d3248 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2d324c pop {r4, r5, pc}
 *   @0x2d3250 vldr s14, [sp, #4]
 *   @0x2d3254 vadd.f32 s15, s18, s14
 *   @0x2d3258 vldr s14, [r4, #96]
 *   @0x2d325c vsub.f32 s15, s15, s29
 *   @0x2d3260 vadd.f32 s28, s16, s30
 *   @0x2d3264 vsub.f32 s15, s15, s21
 *   @0x2d3268 vsub.f32 s28, s28, s31
 *   @0x2d326c vstr s15, [sp, #12]
 *   @0x2d3270 vmul.f32 s15, s15, s15
 *   @0x2d3274 vsub.f32 s28, s28, s17
 *   @0x2d3278 vmla.f32 s15, s28, s28
 *   @0x2d327c vsqrt.f32 s26, s15
 *   @0x2d3280 vsub.f32 s13, s22, s23
 *   @0x2d3284 vsub.f32 s14, s13, s14
 *   @0x2d3288 vcmp.f32 s26, s26
 *   @0x2d328c vstr s14, [sp, #8]
 *   @0x2d3290 vmrs APSR_nzcv, fpscr
 *   @0x2d3294 bne 0x2d332c <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x330>
 *   @0x2d3298 vldr s13, [sp, #8]
 *   @0x2d329c vcmpe.f32 s13, #0
 *   @0x2d32a0 add r0, sp, #32
 *   @0x2d32a4 add r1, sp, #44
 *   @0x2d32a8 add r2, sp, #20
 *   @0x2d32ac vldr s14, [sp, #12]
 *   @0x2d32b0 vldr s15, [sp, #8]
 *   @0x2d32b4 vstr s14, [sp, #24]
 *   @0x2d32b8 vmrs APSR_nzcv, fpscr
 *   @0x2d32bc vstr s15, [sp, #28]
 *   @0x2d32c0 vnegle.f32 s27, s13
 *   @0x2d32c4 vldrgt s27, [sp, #8]
 *   @0x2d32c8 vstr s28, [sp, #20]
 *   @0x2d32cc bl 0x2c6808 <_ZNK7b2Mat337Solve33ERK6b2Vec3>
 *   @0x2d32d0 vldr s14, [sp, #32]
 *   @0x2d32d4 vldr s15, [sp, #36]
 *   @0x2d32d8 vldr s13, [sp, #40]
 *   @0x2d32dc vneg.f32 s14, s14
 *   @0x2d32e0 vmul.f32 s21, s21, s14
 *   @0x2d32e4 vmul.f32 s18, s18, s14
 *   @0x2d32e8 vneg.f32 s15, s15
 *   @0x2d32ec vnmls.f32 s21, s17, s15
 *   @0x2d32f0 vnmls.f32 s18, s16, s15
 *   @0x2d32f4 vsub.f32 s21, s21, s13
 *   @0x2d32f8 vsub.f32 s18, s18, s13
 *   @0x2d32fc vmls.f32 s31, s25, s14
 *   @0x2d3300 vmla.f32 s30, s24, s14
 *   @0x2d3304 vldr s14, [sp, #4]
 *   @0x2d3308 vmls.f32 s29, s25, s15
 *   @0x2d330c vmla.f32 s14, s24, s15
 *   @0x2d3310 vmls.f32 s23, s21, s20
 *   @0x2d3314 vmla.f32 s22, s18, s19
 *   @0x2d3318 b 0x2d31e8 <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x1ec>
 *   @0x2d331c vmov r0, s15
 *   @0x2d3320 bl 0xb6700 <sqrtf@plt>
 *   @0x2d3324 vmov s26, r0
 *   @0x2d3328 b 0x2d3198 <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x19c>
 *   @0x2d332c vmov r0, s15
 *   @0x2d3330 bl 0xb6700 <sqrtf@plt>
 *   @0x2d3334 vmov s26, r0
 *   @0x2d3338 b 0x2d3298 <_ZN11b2WeldJoint24SolvePositionConstraintsERK12b2SolverData+0x29c>
 *   @0x2d333c andeq r0, r0, r0
 *   @0x2d3340 bllo 0xfebc8f70 <b2_toiTime+0xfffffffffe46facc>
 *   @0x2d3344 vstrlo s30, [lr, #-216]
 *
 * ══ §20/36 _Unwind_VRS_Pop  0x31a1bc  size 844  211 条（0x31a1bc..0x31a508）
 * @func 0x31a1bc 0x31a508  size 844  211 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_31a51c+0x18×2 / anon_31a51c+0x8×2 / anon_31a51c+0x28×2 / anon_31a51c+0x74×2 / anon_31a51c+0xcc×2 / _Unwind_VRS_Pop+0x1cc / anon_31a51c / anon_31a51c+0x10
 * 字段偏移 top8: 0x38×7 / 0x48×1 / 0xd0×1 / 0x150×1 / 0x1d0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x31a1bc push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x31a1c0 mov r4, r0
 *   @0x31a1c4 sub sp, sp, #268
 *   @0x31a1c8 mov r5, r2
 *   @0x31a1cc cmp r1, #4
 *   @0x31a1d0 addls pc, pc, r1, lsl #2
 *   @0x31a1d4 b 0x31a4f4 <_Unwind_VRS_Pop+0x338>
 *   @0x31a1d8 b 0x31a1ec <_Unwind_VRS_Pop+0x30>
 *   @0x31a1dc b 0x31a230 <_Unwind_VRS_Pop+0x74>
 *   @0x31a1e0 b 0x31a4f4 <_Unwind_VRS_Pop+0x338>
 *   @0x31a1e4 b 0x31a410 <_Unwind_VRS_Pop+0x254>
 *   @0x31a1e8 b 0x31a48c <_Unwind_VRS_Pop+0x2d0>
 *   @0x31a1ec cmp r3, #0
 *   @0x31a1f0 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338>
 *   @0x31a1f4 uxth r1, r2
 *   @0x31a1f8 ldr r2, [r0, #0x38]
 *   @0x31a1fc mov r0, #1
 *   @0x31a200 ands r12, r1, r0, lsl r3
 *   @0x31a204 addne r12, r4, r3, lsl #2
 *   @0x31a208 add r3, r3, #1
 *   @0x31a20c ldrne r6, [r2]
 *   @0x31a210 addne r2, r2, #4
 *   @0x31a214 strne r6, [r12, #0x4]
 *   @0x31a218 cmp r3, #16
 *   @0x31a21c bne 0x31a200 <_Unwind_VRS_Pop+0x44>
 *   @0x31a220 ands r0, r5, #8192
 *   @0x31a224 streq r2, [r4, #0x38]
 *   @0x31a228 beq 0x31a500 <_Unwind_VRS_Pop+0x344>
 *   @0x31a22c b 0x31a4fc <_Unwind_VRS_Pop+0x340>
 *   @0x31a230 bic r2, r3, #4
 *   @0x31a234 cmp r2, #1
 *   @0x31a238 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338>
 *   @0x31a23c cmp r3, #1
 *   @0x31a240 lsr r6, r5, #16
 *   @0x31a244 uxth r5, r5
 *   @0x31a248 add r2, r5, r6
 *   @0x31a24c movne r1, #32
 *   @0x31a250 moveq r1, #16
 *   @0x31a254 cmp r2, r1
 *   @0x31a258 bhi 0x31a4f4 <_Unwind_VRS_Pop+0x338>
 *   @0x31a25c subs r1, r3, #1
 *   @0x31a260 rsbs r9, r1, #0
 *   @0x31a264 adcs r9, r9, r1
 *   @0x31a268 cmp r6, #15
 *   @0x31a26c movls r8, #0
 *   @0x31a270 movhi r8, #1
 *   @0x31a274 tst r9, r8
 *   @0x31a278 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338>
 *   @0x31a27c cmp r8, #0
 *   @0x31a280 movne r8, r5
 *   @0x31a284 bne 0x31a290 <_Unwind_VRS_Pop+0xd4>
 *   @0x31a288 cmp r2, #16
 *   @0x31a28c subhi r8, r2, #16
 *   @0x31a290 adds r7, r8, #0
 *   @0x31a294 movne r7, #1
 *   @0x31a298 cmp r3, #5
 *   @0x31a29c cmpne r8, #0
 *   @0x31a2a0 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338>
 *   @0x31a2a4 cmp r6, #15
 *   @0x31a2a8 bhi 0x31a2e8 <_Unwind_VRS_Pop+0x12c>
 *   @0x31a2ac ldr r2, [r4]
 *   @0x31a2b0 tst r2, #1
 *   @0x31a2b4 beq 0x31a2e8 <_Unwind_VRS_Pop+0x12c>
 *   @0x31a2b8 cmp r3, #5
 *   @0x31a2bc mov r0, r4
 *   @0x31a2c0 bic r1, r2, #1
 *   @0x31a2c4 str r1, [r0], #72
 *   @0x31a2c8 bne 0x31a2dc <_Unwind_VRS_Pop+0x120>
 *   @0x31a2cc orr r1, r1, #2
 *   @0x31a2d0 str r1, [r4]
 *   @0x31a2d4 bl 0x31a534 <__gnu_Unwind_Save_VFP_D>
 *   @0x31a2d8 b 0x31a2e8 <_Unwind_VRS_Pop+0x12c>
 *   @0x31a2dc bic r2, r2, #3
 *   @0x31a2e0 str r2, [r4]
 *   @0x31a2e4 bl 0x31a524 <__gnu_Unwind_Save_VFP>
 *   @0x31a2e8 cmp r7, #0
 *   @0x31a2ec beq 0x31a30c <_Unwind_VRS_Pop+0x150>
 *   @0x31a2f0 ldr r3, [r4]
 *   @0x31a2f4 tst r3, #4
 *   @0x31a2f8 beq 0x31a30c <_Unwind_VRS_Pop+0x150>
 *   @0x31a2fc mov r0, r4
 *   @0x31a300 bic r3, r3, #4
 *   @0x31a304 str r3, [r0], #208
 *   @0x31a308 bl 0x31a544 <__gnu_Unwind_Save_VFP_D_16_to_31>
 *   @0x31a30c cmp r9, #0
 *   @0x31a310 beq 0x31a328 <_Unwind_VRS_Pop+0x16c>
 *   @0x31a314 add r0, sp, #128
 *   @0x31a318 bl 0x31a524 <__gnu_Unwind_Save_VFP>
 *   @0x31a31c cmp r7, #0
 *   @0x31a320 bne 0x31a348 <_Unwind_VRS_Pop+0x18c>
 *   @0x31a324 b 0x31a34c <_Unwind_VRS_Pop+0x190>
 *   @0x31a328 cmp r6, #15
 *   @0x31a32c bhi 0x31a338 <_Unwind_VRS_Pop+0x17c>
 *   @0x31a330 add r0, sp, #128
 *   @0x31a334 bl 0x31a534 <__gnu_Unwind_Save_VFP_D>
 *   @0x31a338 cmp r7, #0
 *   @0x31a33c beq 0x31a34c <_Unwind_VRS_Pop+0x190>
 *   @0x31a340 mov r0, sp
 *   @0x31a344 bl 0x31a544 <__gnu_Unwind_Save_VFP_D_16_to_31>
 *   @0x31a348 rsb r5, r6, #16
 *   @0x31a34c ldr r2, [r4, #0x38]
 *   @0x31a350 cmp r5, #0
 *   @0x31a354 mov r3, r2
 *   @0x31a358 ble 0x31a388 <_Unwind_VRS_Pop+0x1cc>
 *   @0x31a35c add r3, sp, #128
 *   @0x31a360 lsl r5, r5, #1
 *   @0x31a364 add r3, r3, r6, lsl #3
 *   @0x31a368 sub r0, r2, #4
 *   @0x31a36c rsb r3, r2, r3
 *   @0x31a370 mov r1, r5
 *   @0x31a374 subs r1, r1, #1
 *   @0x31a378 ldrhs r12, [r0, #0x4]!
 *   @0x31a37c strhs r12, [r3, r0]
 *   @0x31a380 bhs 0x31a374 <_Unwind_VRS_Pop+0x1b8>
 *   @0x31a384 add r3, r2, r5, lsl #2
 *   @0x31a388 cmp r7, #0
 *   @0x31a38c beq 0x31a3cc <_Unwind_VRS_Pop+0x210>
 *   @0x31a390 cmp r6, #16
 *   @0x31a394 movhs r0, r6
 *   @0x31a398 movlo r0, #16
 *   @0x31a39c add r2, sp, #264
 *   @0x31a3a0 lsl r8, r8, #1
 *   @0x31a3a4 add r0, r2, r0, lsl #3
 *   @0x31a3a8 mov r2, #0
 *   @0x31a3ac sub r0, r0, #392
 *   @0x31a3b0 cmp r2, r8
 *   @0x31a3b4 lsl r1, r2, #2
 *   @0x31a3b8 ldrne r1, [r3, r2, lsl #2]
 *   @0x31a3bc strne r1, [r0, r2, lsl #2]
 *   @0x31a3c0 addne r2, r2, #1
 *   @0x31a3c4 bne 0x31a3b0 <_Unwind_VRS_Pop+0x1f4>
 *   @0x31a3c8 add r3, r3, r1
 *   @0x31a3cc cmp r9, #0
 *   @0x31a3d0 addne r3, r3, #4
 *   @0x31a3d4 cmp r9, #0
 *   @0x31a3d8 str r3, [r4, #0x38]
 *   @0x31a3dc beq 0x31a3ec <_Unwind_VRS_Pop+0x230>
 *   @0x31a3e0 add r0, sp, #128
 *   @0x31a3e4 bl 0x31a51c <__gnu_Unwind_Restore_VFP>
 *   @0x31a3e8 b 0x31a4fc <_Unwind_VRS_Pop+0x340>
 *   @0x31a3ec cmp r6, #15
 *   @0x31a3f0 bhi 0x31a3fc <_Unwind_VRS_Pop+0x240>
 *   @0x31a3f4 add r0, sp, #128
 *   @0x31a3f8 bl 0x31a52c <__gnu_Unwind_Restore_VFP_D>
 *   @0x31a3fc cmp r7, #0
 *   @0x31a400 beq 0x31a4fc <_Unwind_VRS_Pop+0x340>
 *   @0x31a404 mov r0, sp
 *   @0x31a408 bl 0x31a53c <__gnu_Unwind_Restore_VFP_D_16_to_31>
 *   @0x31a40c b 0x31a4fc <_Unwind_VRS_Pop+0x340>
 *   @0x31a410 cmp r3, #3
 *   @0x31a414 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338>
 *   @0x31a418 lsr r7, r2, #16
 *   @0x31a41c uxth r5, r2
 *   @0x31a420 add r3, r5, r7
 *   @0x31a424 cmp r3, #16
 *   @0x31a428 bhi 0x31a4f4 <_Unwind_VRS_Pop+0x338>
 *   @0x31a42c ldr r3, [r0]
 *   @0x31a430 tst r3, #8
 *   @0x31a434 beq 0x31a444 <_Unwind_VRS_Pop+0x288>
 *   @0x31a438 bic r3, r3, #8
 *   @0x31a43c str r3, [r0], #336
 *   @0x31a440 bl 0x31a590 <__gnu_Unwind_Save_WMMXD>
 *   @0x31a444 add r6, sp, #128
 *   @0x31a448 lsl r5, r5, #1
 *   @0x31a44c add r7, r6, r7, lsl #3
 *   @0x31a450 mov r0, r6
 *   @0x31a454 bl 0x31a590 <__gnu_Unwind_Save_WMMXD>
 *   @0x31a458 ldr r3, [r4, #0x38]
 *   @0x31a45c mov r2, r5
 *   @0x31a460 sub r1, r3, #4
 *   @0x31a464 rsb r7, r3, r7
 *   @0x31a468 subs r2, r2, #1
 *   @0x31a46c ldrhs r0, [r1, #0x4]!
 *   @0x31a470 strhs r0, [r7, r1]
 *   @0x31a474 bhs 0x31a468 <_Unwind_VRS_Pop+0x2ac>
 *   @0x31a478 add r5, r3, r5, lsl #2
 *   @0x31a47c mov r0, r6
 *   @0x31a480 str r5, [r4, #0x38]
 *   @0x31a484 bl 0x31a54c <__gnu_Unwind_Restore_WMMXD>
 *   @0x31a488 b 0x31a4fc <_Unwind_VRS_Pop+0x340>
 *   @0x31a48c cmp r2, #16
 *   @0x31a490 cmpls r3, #0
 *   @0x31a494 bne 0x31a4f4 <_Unwind_VRS_Pop+0x338>
 *   @0x31a498 ldr r3, [r0]
 *   @0x31a49c tst r3, #16
 *   @0x31a4a0 beq 0x31a4b0 <_Unwind_VRS_Pop+0x2f4>
 *   @0x31a4a4 bic r3, r3, #16
 *   @0x31a4a8 str r3, [r0], #464
 *   @0x31a4ac bl 0x31a5e8 <__gnu_Unwind_Save_WMMXC>
 *   @0x31a4b0 add r6, sp, #128
 *   @0x31a4b4 mov r0, r6
 *   @0x31a4b8 bl 0x31a5e8 <__gnu_Unwind_Save_WMMXC>
 *   @0x31a4bc ldr r2, [r4, #0x38]
 *   @0x31a4c0 mov r3, #0
 *   @0x31a4c4 mov r1, #1
 *   @0x31a4c8 ands r12, r5, r1, lsl r3
 *   @0x31a4cc ldrne r0, [r2]
 *   @0x31a4d0 addne r2, r2, #4
 *   @0x31a4d4 strne r0, [r6, r3, lsl #2]
 *   @0x31a4d8 add r3, r3, #1
 *   @0x31a4dc cmp r3, #4
 *   @0x31a4e0 bne 0x31a4c8 <_Unwind_VRS_Pop+0x30c>
 *   @0x31a4e4 str r2, [r4, #0x38]
 *   @0x31a4e8 mov r0, r6
 *   @0x31a4ec bl 0x31a5d4 <__gnu_Unwind_Restore_WMMXC>
 *   @0x31a4f0 b 0x31a4fc <_Unwind_VRS_Pop+0x340>
 *   @0x31a4f4 mov r0, #2
 *   @0x31a4f8 b 0x31a500 <_Unwind_VRS_Pop+0x344>
 *   @0x31a4fc mov r0, #0
 *   @0x31a500 add sp, sp, #268
 *   @0x31a504 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §21/36 Sprite_AddEmpty()  0x1ef890  size 840  210 条（0x1ef890..0x1efbd8）
 * @func 0x1ef890 0x1efbd8  size 840  210 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1ef8a8→0x7530d8, 0x1ef8ac→0x7530d0, 0x1ef8fc→0x7530dc, 0x1ef94c→0x7530e0
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / 0xb65c8 / YYStrDup(char const*) / unsigned int CHashMapCalculateHash<char const*>(char const*) / Sprite_AddEmpty()+0x134 / operator new(unsigned int) / CSprite::CSprite() / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×13 / 0x8×13 / 0x2×5 / 0x10×4 / 0xc×3 / 0x30c×2 / 0x114×2 / 0x314×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ef890 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ef894 sub sp, sp, #284
 *   @0x1ef898 ldr r4, [pc, #0x314]
 *   @0x1ef89c movw r3, #0x3cd
 *   @0x1ef8a0 ldr r2, [pc, #0x310]
 *   @0x1ef8a4 add r4, pc, r4
 *   @0x1ef8a8 ldr r1, [pc, #0x30c]
 *   @0x1ef8ac ldr r0, [pc, #0x30c]
 *   @0x1ef8b0 ldr r2, [r4, r2]
 *   @0x1ef8b4 ldr r5, [pc, #0x308]
 *   @0x1ef8b8 ldr r12, [r2]
 *   @0x1ef8bc add r5, pc, r5
 *   @0x1ef8c0 str r2, [sp, #0xc]
 *   @0x1ef8c4 mov r2, r5
 *   @0x1ef8c8 str r12, [sp, #0x114]
 *   @0x1ef8cc ldr r6, [r4, r1]
 *   @0x1ef8d0 ldr r1, [r6]
 *   @0x1ef8d4 add r1, r1, #1
 *   @0x1ef8d8 str r1, [r6]
 *   @0x1ef8dc ldr r0, [r4, r0]
 *   @0x1ef8e0 lsl r1, r1, #2
 *   @0x1ef8e4 str r0, [sp, #0x4]
 *   @0x1ef8e8 add r0, r0, #4
 *   @0x1ef8ec bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1ef8f0 ldr r12, [sp, #0x4]
 *   @0x1ef8f4 ldr r1, [r6]
 *   @0x1ef8f8 mov r2, r5
 *   @0x1ef8fc ldr r0, [pc, #0x2c4]
 *   @0x1ef900 movw r3, #0x3cf
 *   @0x1ef904 add r5, sp, #20
 *   @0x1ef908 str r1, [r12]
 *   @0x1ef90c lsl r1, r1, #2
 *   @0x1ef910 ldr r0, [r4, r0]
 *   @0x1ef914 str r0, [sp, #0x8]
 *   @0x1ef918 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1ef91c ldr r3, [r6]
 *   @0x1ef920 mov r1, #256
 *   @0x1ef924 ldr r2, [pc, #0x2a0]
 *   @0x1ef928 mov r0, r5
 *   @0x1ef92c sub r3, r3, #1
 *   @0x1ef930 add r2, pc, r2
 *   @0x1ef934 bl 0xb65c8 <snprintf@plt>
 *   @0x1ef938 ldr r12, [sp, #0x8]
 *   @0x1ef93c mov r0, r5
 *   @0x1ef940 ldr r8, [r6]
 *   @0x1ef944 ldr r7, [r12]
 *   @0x1ef948 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1ef94c ldr r3, [pc, #0x27c]
 *   @0x1ef950 sub r8, r8, #-1073741823
 *   @0x1ef954 ldr r5, [r6]
 *   @0x1ef958 ldr r12, [sp, #0x8]
 *   @0x1ef95c sub r2, r5, #-1073741823
 *   @0x1ef960 sub r5, r5, #1
 *   @0x1ef964 str r0, [r7, r8, lsl #2]
 *   @0x1ef968 ldr r7, [r4, r3]
 *   @0x1ef96c ldr r0, [r12]
 *   @0x1ef970 ldr r3, [r7, #0x4]
 *   @0x1ef974 ldr r1, [r7, #0xc]
 *   @0x1ef978 ldr r4, [r0, r2, lsl #2]
 *   @0x1ef97c cmp r3, r1
 *   @0x1ef980 bgt 0x1efabc <_Z15Sprite_AddEmptyv+0x22c>
 *   @0x1ef984 mov r0, r4
 *   @0x1ef988 add r3, r3, #1
 *   @0x1ef98c str r3, [r7, #0x4]
 *   @0x1ef990 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x1ef994 ldr lr, [r7, #0x8]
 *   @0x1ef998 ldr r10, [r7, #0x10]
 *   @0x1ef99c bic r0, r0, #-2147483648
 *   @0x1ef9a0 and r3, r0, lr
 *   @0x1ef9a4 add r2, r3, r3, lsl #1
 *   @0x1ef9a8 add r2, r10, r2, lsl #2
 *   @0x1ef9ac ldr r1, [r2, #0x8]
 *   @0x1ef9b0 cmp r1, #0
 *   @0x1ef9b4 ldrne r11, [r7]
 *   @0x1ef9b8 movne r8, #0
 *   @0x1ef9bc bne 0x1efa04 <_Z15Sprite_AddEmptyv+0x174>
 *   @0x1ef9c0 b 0x1efa50 <_Z15Sprite_AddEmptyv+0x1c0>
 *   @0x1ef9c4 ldr r9, [r2]
 *   @0x1ef9c8 ldr r8, [r2, #0x4]
 *   @0x1ef9cc str r0, [r2, #0x8]
 *   @0x1ef9d0 mov r0, r1
 *   @0x1ef9d4 str r4, [r2]
 *   @0x1ef9d8 mov r4, r9
 *   @0x1ef9dc str r5, [r2, #0x4]
 *   @0x1ef9e0 mov r5, r8
 *   @0x1ef9e4 add r3, r3, #1
 *   @0x1ef9e8 add r8, r12, #1
 *   @0x1ef9ec and r3, r3, lr
 *   @0x1ef9f0 add r2, r3, r3, lsl #1
 *   @0x1ef9f4 add r2, r10, r2, lsl #2
 *   @0x1ef9f8 ldr r1, [r2, #0x8]
 *   @0x1ef9fc cmp r1, #0
 *   @0x1efa00 beq 0x1efa50 <_Z15Sprite_AddEmptyv+0x1c0>
 *   @0x1efa04 add r12, r11, r3
 *   @0x1efa08 and r9, r1, lr
 *   @0x1efa0c rsb r12, r9, r12
 *   @0x1efa10 and r12, r12, lr
 *   @0x1efa14 cmp r12, r8
 *   @0x1efa18 blt 0x1ef9c4 <_Z15Sprite_AddEmptyv+0x134>
 *   @0x1efa1c movne r12, r8
 *   @0x1efa20 bne 0x1ef9e4 <_Z15Sprite_AddEmptyv+0x154>
 *   @0x1efa24 cmp r1, r0
 *   @0x1efa28 bne 0x1ef9e4 <_Z15Sprite_AddEmptyv+0x154>
 *   @0x1efa2c ldr r8, [r2]
 *   @0x1efa30 cmp r4, r8
 *   @0x1efa34 bne 0x1ef9e4 <_Z15Sprite_AddEmptyv+0x154>
 *   @0x1efa38 ldr r3, [r7, #0x4]
 *   @0x1efa3c str r1, [r2, #0x8]
 *   @0x1efa40 stm r2, {r4, r5}
 *   @0x1efa44 sub r3, r3, #1
 *   @0x1efa48 str r3, [r7, #0x4]
 *   @0x1efa4c b 0x1efa58 <_Z15Sprite_AddEmptyv+0x1c8>
 *   @0x1efa50 stm r2, {r4, r5}
 *   @0x1efa54 str r0, [r2, #0x8]
 *   @0x1efa58 mov r0, #136
 *   @0x1efa5c bl 0x27c524 <_Znwj>
 *   @0x1efa60 mov r5, r0
 *   @0x1efa64 bl 0x1e761c <_ZN7CSpriteC2Ev>
 *   @0x1efa68 ldr r1, [r6]
 *   @0x1efa6c ldr r6, [sp, #0x4]
 *   @0x1efa70 sub r3, r1, #-1073741823
 *   @0x1efa74 ldr r12, [sp, #0x8]
 *   @0x1efa78 ldr r4, [sp, #0x114]
 *   @0x1efa7c sub r1, r1, #1
 *   @0x1efa80 ldr r2, [r6, #0x4]
 *   @0x1efa84 mov r0, r1
 *   @0x1efa88 str r5, [r2, r3, lsl #2]
 *   @0x1efa8c ldr r2, [r6, #0x4]
 *   @0x1efa90 ldr r6, [sp, #0xc]
 *   @0x1efa94 ldr r5, [r12]
 *   @0x1efa98 ldr r2, [r2, r3, lsl #2]
 *   @0x1efa9c ldr r12, [r6]
 *   @0x1efaa0 ldr r3, [r5, r3, lsl #2]
 *   @0x1efaa4 cmp r4, r12
 *   @0x1efaa8 str r1, [r2, #0x60]
 *   @0x1efaac str r3, [r2, #0x5c]
 *   @0x1efab0 bne 0x1efbac <_Z15Sprite_AddEmptyv+0x31c>
 *   @0x1efab4 add sp, sp, #284
 *   @0x1efab8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1efabc ldr r10, [r7]
 *   @0x1efac0 mov r3, #1
 *   @0x1efac4 ldr r1, [pc, #0x108]
 *   @0x1efac8 mov r2, #70
 *   @0x1efacc ldr r9, [r7, #0x10]
 *   @0x1efad0 lsl r0, r10, r3
 *   @0x1efad4 add r1, pc, r1
 *   @0x1efad8 add r8, r0, r10, lsl #2
 *   @0x1efadc str r0, [r7]
 *   @0x1efae0 sub r0, r0, #1
 *   @0x1efae4 str r0, [r7, #0x8]
 *   @0x1efae8 lsl r8, r8, #2
 *   @0x1efaec mov r0, r8
 *   @0x1efaf0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1efaf4 mov r2, r8
 *   @0x1efaf8 mov r1, #0
 *   @0x1efafc str r0, [r7, #0x10]
 *   @0x1efb00 bl 0xb65b0 <memset@plt>
 *   @0x1efb04 ldr r2, [r7]
 *   @0x1efb08 vldr s15, [pc, #160]
 *   @0x1efb0c mov r1, #0
 *   @0x1efb10 str r1, [r7, #0x4]
 *   @0x1efb14 cmp r2, r1
 *   @0x1efb18 vmov s13, r2
 *   @0x1efb1c vcvt.f32.s32 s14, s13
 *   @0x1efb20 vmul.f32 s15, s14, s15
 *   @0x1efb24 vcvt.s32.f32 s15, s15
 *   @0x1efb28 vstr s15, [r7, #12]
 *   @0x1efb2c ble 0x1efb4c <_Z15Sprite_AddEmptyv+0x2bc>
 *   @0x1efb30 add r2, r2, r2, lsl #1
 *   @0x1efb34 ldr r3, [r7, #0x10]
 *   @0x1efb38 add r2, r3, r2, lsl #2
 *   @0x1efb3c str r1, [r3, #0x8]
 *   @0x1efb40 add r3, r3, #12
 *   @0x1efb44 cmp r3, r2
 *   @0x1efb48 bne 0x1efb3c <_Z15Sprite_AddEmptyv+0x2ac>
 *   @0x1efb4c cmp r10, #0
 *   @0x1efb50 movgt r8, r9
 *   @0x1efb54 movgt r11, #0
 *   @0x1efb58 ble 0x1efb84 <_Z15Sprite_AddEmptyv+0x2f4>
 *   @0x1efb5c ldr r3, [r8, #0x8]
 *   @0x1efb60 cmp r3, #0
 *   @0x1efb64 ble 0x1efb74 <_Z15Sprite_AddEmptyv+0x2e4>
 *   @0x1efb68 mov r0, r7
 *   @0x1efb6c ldm r8, {r1, r2}
 *   @0x1efb70 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i>
 *   @0x1efb74 add r11, r11, #1
 *   @0x1efb78 add r8, r8, #12
 *   @0x1efb7c cmp r11, r10
 *   @0x1efb80 bne 0x1efb5c <_Z15Sprite_AddEmptyv+0x2cc>
 *   @0x1efb84 mov r0, r9
 *   @0x1efb88 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1efb8c vldr s13, [r7]
 *   @0x1efb90 vcvt.f32.s32 s14, s13
 *   @0x1efb94 vldr s15, [pc, #20]
 *   @0x1efb98 ldr r3, [r7, #0x4]
 *   @0x1efb9c vmul.f32 s15, s14, s15
 *   @0x1efba0 vcvt.s32.f32 s15, s15
 *   @0x1efba4 vstr s15, [r7, #12]
 *   @0x1efba8 b 0x1ef984 <_Z15Sprite_AddEmptyv+0xf4>
 *   @0x1efbac bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1efbb0 svclo #0x19999a
 *   @0x1efbb4 eoreq r2, r0, r12, lsr #7
 *   @0x1efbb8 .word 0xffffbd00
 *   @0x1efbbc .word 0xfffff1c0
 *   @0x1efbc0 .word 0xfffff1b8
 *   @0x1efbc4 andseq r2, r6, r4, lsl #27
 *   @0x1efbc8 .word 0xfffff1bc
 *   @0x1efbcc andseq r2, r6, r8, asr #26
 *   @0x1efbd0 .word 0xfffff1c4
 *   @0x1efbd4 andseq r1, r4, r12, asr r5
 *
 * ══ §22/36 anon_222bd4  0x222bd4  size 840  208 条（0x222bd4..0x222f1c）
 * @func 0x222bd4 0x222f1c  size 840  208 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutOutputStreamWriteInt32BE×6 / 0xb6598×4 / _alutSetError×2 / anon_222bd4+0x298 / _alutOutputStreamConstruct / _alutOutputStreamWriteInt16BE / _alutOutputStreamDestroy / 0xb6c10
 * 字段偏移 top8: 0x218×1 / 0x74×1 / 0x6c×1 / 0x64×1 / 0x5c×1
 * VFP 指令 83 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x222bd4 vmov.f64 d5, #5.000000e-01
 *   @0x222bd8 vmov d4, r2, r3
 *   @0x222bdc vmov.f64 d6, #-1.000000e+00
 *   @0x222be0 vmov.f64 d7, #1.000000e+00
 *   @0x222be4 vcmpe.f64 d4, d5
 *   @0x222be8 vmrs APSR_nzcv, fpscr
 *   @0x222bec vmovlt r0, r1, d7
 *   @0x222bf0 vmovge r0, r1, d6
 *   @0x222bf4 bx lr
 *   @0x222bf8 vmov d5, r2, r3
 *   @0x222bfc vmov.f64 d7, #1.000000e+00
 *   @0x222c00 vadd.f64 d6, d5, d5
 *   @0x222c04 vsub.f64 d5, d6, d7
 *   @0x222c08 vmov r0, r1, d5
 *   @0x222c0c bx lr
 *   @0x222c10 vmov.f64 d6, #1.000000e+00
 *   @0x222c14 vldr d7, [pc, #28]
 *   @0x222c18 vmov d4, r0, r1
 *   @0x222c1c vmov d5, r2, r3
 *   @0x222c20 vcmpe.f64 d4, d5
 *   @0x222c24 vmrs APSR_nzcv, fpscr
 *   @0x222c28 vmovle r0, r1, d7
 *   @0x222c2c vmovgt r0, r1, d6
 *   @0x222c30 bx lr
 *   @0x222c34 nop
 *   @0x222c40 sub r0, r0, #256
 *   @0x222c44 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x222c48 vpush {d8, d9, d10, d11, d12}
 *   @0x222c4c vmov.f32 s18, s0
 *   @0x222c50 vmov.f32 s20, s1
 *   @0x222c54 cmp r0, #4
 *   @0x222c58 addls pc, pc, r0, lsl #2
 *   @0x222c5c b 0x222e58 <alutGetMinorVersion+0x28c>
 *   @0x222c60 b 0x222e1c <alutGetMinorVersion+0x250>
 *   @0x222c64 b 0x222c74 <alutGetMinorVersion+0xa8>
 *   @0x222c68 b 0x222e28 <alutGetMinorVersion+0x25c>
 *   @0x222c6c b 0x222e34 <alutGetMinorVersion+0x268>
 *   @0x222c70 b 0x222e40 <alutGetMinorVersion+0x274>
 *   @0x222c74 ldr r9, [pc, #0x218]
 *   @0x222c78 add r9, pc, r9
 *   @0x222c7c vcmpe.f32 s18, #0
 *   @0x222c80 vmrs APSR_nzcv, fpscr
 *   @0x222c84 bls 0x222e6c <alutGetMinorVersion+0x2a0>
 *   @0x222c88 vcmpe.f32 s2, #0
 *   @0x222c8c vmrs APSR_nzcv, fpscr
 *   @0x222c90 bmi 0x222e6c <alutGetMinorVersion+0x2a0>
 *   @0x222c94 vmul.f32 s2, s18, s2
 *   @0x222c98 vldr d8, [pc, #480]
 *   @0x222c9c vmov.f64 d7, #5.000000e-01
 *   @0x222ca0 vcvt.f64.f32 d1, s2
 *   @0x222ca4 vadd.f64 d6, d1, d7
 *   @0x222ca8 vmov r0, r1, d6
 *   @0x222cac bl 0xb6598 <floor@plt>
 *   @0x222cb0 vcvt.f64.f32 d9, s18
 *   @0x222cb4 vmov d6, r0, r1
 *   @0x222cb8 vdiv.f64 d7, d6, d9
 *   @0x222cbc vmul.f64 d6, d7, d8
 *   @0x222cc0 vmov r0, r1, d6
 *   @0x222cc4 bl 0xb6598 <floor@plt>
 *   @0x222cc8 vmov d7, r0, r1
 *   @0x222ccc vcvt.u32.f64 s15, d7
 *   @0x222cd0 vmov r8, s15
 *   @0x222cd4 lsl r4, r8, #1
 *   @0x222cd8 add r0, r4, #24
 *   @0x222cdc bl 0x2228a4 <_alutOutputStreamConstruct>
 *   @0x222ce0 subs r7, r0, #0
 *   @0x222ce4 beq 0x222e4c <alutGetMinorVersion+0x280>
 *   @0x222ce8 movw r1, #0x6e64
 *   @0x222cec movt r1, #0x2e73
 *   @0x222cf0 bl 0x2229b4 <_alutOutputStreamWriteInt32BE>
 *   @0x222cf4 cmp r0, #0
 *   @0x222cf8 beq 0x222e08 <alutGetMinorVersion+0x23c>
 *   @0x222cfc mov r0, r7
 *   @0x222d00 mov r1, #24
 *   @0x222d04 bl 0x2229b4 <_alutOutputStreamWriteInt32BE>
 *   @0x222d08 cmp r0, #0
 *   @0x222d0c beq 0x222e08 <alutGetMinorVersion+0x23c>
 *   @0x222d10 mov r1, r4
 *   @0x222d14 mov r0, r7
 *   @0x222d18 bl 0x2229b4 <_alutOutputStreamWriteInt32BE>
 *   @0x222d1c cmp r0, #0
 *   @0x222d20 beq 0x222e08 <alutGetMinorVersion+0x23c>
 *   @0x222d24 mov r0, r7
 *   @0x222d28 mov r1, #3
 *   @0x222d2c bl 0x2229b4 <_alutOutputStreamWriteInt32BE>
 *   @0x222d30 cmp r0, #0
 *   @0x222d34 beq 0x222e08 <alutGetMinorVersion+0x23c>
 *   @0x222d38 mov r0, r7
 *   @0x222d3c movw r1, #0xac44
 *   @0x222d40 bl 0x2229b4 <_alutOutputStreamWriteInt32BE>
 *   @0x222d44 cmp r0, #0
 *   @0x222d48 beq 0x222e08 <alutGetMinorVersion+0x23c>
 *   @0x222d4c mov r0, r7
 *   @0x222d50 mov r1, #1
 *   @0x222d54 bl 0x2229b4 <_alutOutputStreamWriteInt32BE>
 *   @0x222d58 cmp r0, #0
 *   @0x222d5c beq 0x222e08 <alutGetMinorVersion+0x23c>
 *   @0x222d60 vdiv.f64 d8, d9, d8
 *   @0x222d64 vldr s15, [pc, #292]
 *   @0x222d68 vdiv.f32 s20, s20, s15
 *   @0x222d6c vcvt.f64.f32 d10, s20
 *   @0x222d70 vsub.f64 d8, d10, d8
 *   @0x222d74 vmov r0, r1, d8
 *   @0x222d78 bl 0xb6598 <floor@plt>
 *   @0x222d7c cmp r8, #0
 *   @0x222d80 vmov d6, r0, r1
 *   @0x222d84 vsub.f64 d6, d8, d6
 *   @0x222d88 vmov r4, r5, d6
 *   @0x222d8c beq 0x222e4c <alutGetMinorVersion+0x280>
 *   @0x222d90 mov r6, #0
 *   @0x222d94 vldr d12, [pc, #228]
 *   @0x222d98 vldr d11, [pc, #232]
 *   @0x222d9c b 0x222da8 <alutGetMinorVersion+0x1dc>
 *   @0x222da0 cmp r6, r8
 *   @0x222da4 beq 0x222e4c <alutGetMinorVersion+0x280>
 *   @0x222da8 vmov s13, r6
 *   @0x222dac add r6, r6, #1
 *   @0x222db0 vcvt.f64.u32 d8, s13
 *   @0x222db4 vmul.f64 d8, d9, d8
 *   @0x222db8 vdiv.f64 d8, d8, d12
 *   @0x222dbc vadd.f64 d8, d10, d8
 *   @0x222dc0 vmov r0, r1, d8
 *   @0x222dc4 bl 0xb6598 <floor@plt>
 *   @0x222dc8 vmov d7, r0, r1
 *   @0x222dcc mov r0, r4
 *   @0x222dd0 mov r1, r5
 *   @0x222dd4 vsub.f64 d8, d8, d7
 *   @0x222dd8 vmov r2, r3, d8
 *   @0x222ddc blx r9
 *   @0x222de0 vmov r4, r5, d8
 *   @0x222de4 vmov d6, r0, r1
 *   @0x222de8 mov r0, r7
 *   @0x222dec vmul.f64 d7, d6, d11
 *   @0x222df0 vcvt.s32.f64 s13, d7
 *   @0x222df4 vmov r1, s13
 *   @0x222df8 sxth r1, r1
 *   @0x222dfc bl 0x222988 <_alutOutputStreamWriteInt16BE>
 *   @0x222e00 subs r10, r0, #0
 *   @0x222e04 bne 0x222da0 <alutGetMinorVersion+0x1d4>
 *   @0x222e08 mov r0, r7
 *   @0x222e0c bl 0x2228fc <_alutOutputStreamDestroy>
 *   @0x222e10 vpop {d8, d9, d10, d11, d12}
 *   @0x222e14 mov r0, #0
 *   @0x222e18 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x222e1c ldr r9, [pc, #0x74]
 *   @0x222e20 add r9, pc, r9
 *   @0x222e24 b 0x222c7c <alutGetMinorVersion+0xb0>
 *   @0x222e28 ldr r9, [pc, #0x6c]
 *   @0x222e2c add r9, pc, r9
 *   @0x222e30 b 0x222c7c <alutGetMinorVersion+0xb0>
 *   @0x222e34 ldr r9, [pc, #0x64]
 *   @0x222e38 add r9, pc, r9
 *   @0x222e3c b 0x222c7c <alutGetMinorVersion+0xb0>
 *   @0x222e40 ldr r9, [pc, #0x5c]
 *   @0x222e44 add r9, pc, r9
 *   @0x222e48 b 0x222c7c <alutGetMinorVersion+0xb0>
 *   @0x222e4c vpop {d8, d9, d10, d11, d12}
 *   @0x222e50 mov r0, r7
 *   @0x222e54 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x222e58 movw r0, #0x201
 *   @0x222e5c bl 0x221940 <_alutSetError>
 *   @0x222e60 vpop {d8, d9, d10, d11, d12}
 *   @0x222e64 mov r0, #0
 *   @0x222e68 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x222e6c movw r0, #0x202
 *   @0x222e70 bl 0x221940 <_alutSetError>
 *   @0x222e74 vpop {d8, d9, d10, d11, d12}
 *   @0x222e78 mov r0, #0
 *   @0x222e7c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x222e80 andeq r0, r0, r0
 *   @0x222e84 rscmi r8, r5, r0, lsl #17
 *   @0x222e88 andeq r0, r0, r0
 *   @0x222e8c sbcsmi pc, pc, r0, asr #31
 *   @0x222e90 teqmi r4, #0
 *   @0x222e94 .word 0xffffff54
 *   @0x222e98 ldrdeq r0, r1, [r0], -r8
 *   @0x222e9c .word 0xfffffdc4
 *   @0x222ea0 andeq r0, r0, r8, rrx
 *   @0x222ea4 .word 0xfffffdc4
 *   @0x222ea8 push {r3, lr}
 *   @0x222eac bl 0xb6c10 <lrand48@plt>
 *   @0x222eb0 movw r2, #0x7d73
 *   @0x222eb4 movt r2, #0x7e91
 *   @0x222eb8 movw r3, #0x953f
 *   @0x222ebc movt r3, #0x40b
 *   @0x222ec0 vldr d5, [pc, #48]
 *   @0x222ec4 vmov.f64 d6, #1.000000e+00
 *   @0x222ec8 smull r12, r2, r2, r0
 *   @0x222ecc asr r1, r0, #31
 *   @0x222ed0 rsb r2, r1, r2, asr #25
 *   @0x222ed4 mls r0, r3, r2, r0
 *   @0x222ed8 vmov s9, r0
 *   @0x222edc vcvt.f64.s32 d7, s9
 *   @0x222ee0 vadd.f64 d7, d7, d7
 *   @0x222ee4 vdiv.f64 d7, d7, d5
 *   @0x222ee8 vsub.f64 d5, d7, d6
 *   @0x222eec vmov r0, r1, d5
 *   @0x222ef0 pop {r3, pc}
 *   @0x222ef4 nop
 *   @0x222ef8 .word 0xfc000000
 *   @0x222efc orrsmi r2, r0, r4, asr lr
 *   @0x222f00 vmov d6, r2, r3
 *   @0x222f04 vldr d7, [pc, #12]
 *   @0x222f08 vmul.f64 d6, d6, d7
 *   @0x222f0c vmov r0, r1, d6
 *   @0x222f10 b 0xb67d8 <sin@plt>
 *   @0x222f14 nop
 *   @0x222f18 strbpl r2, [r4], #-3352
 *
 * ══ §23/36 FT_Bitmap_Embolden  0x314e46  size 838  210 条（0x314e46..0x31518c）
 * @func 0x314e46 0x31518c  size 838  210 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc×2 / FT_Bitmap_Init / FT_Bitmap_Convert / 0x3e7166 / 0x3d6ac6 / 0xd17f8e / ft_mem_qrealloc / 0x5fd060
 * 字段偏移 top8: 0xc×4 / 0x-1×4 / 0x8×3 / 0x18×1 / 0x4×1 / 0x14×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x314e46 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x314e4a mov r4, r1
 *   @0x314e4e mov r9, r0
 *   @0x314e52 beq.w 0x315178 <FT_Bitmap_Embolden+0x332>
 *   @0x314e56 cmp r1, #0x0
 *   @0x314e5a stmvs r9, {r1, r4, r7, r8, pc} ^
 *   @0x314e5e cmp r1, #0x0
 *   @0x314e62 cps #0xe
 *   @0x314e66 .word 0x33200520
 *   @0x314e6a asrs r5, r5, #0x6
 *   @0x314e6e vstrhs d1, [r0, #-652]
 *   @0x314e72 bne 0x314e7c <FT_Bitmap_Embolden+0x36>
 *   @0x314e76 .word 0xd1020f00
 *   @0x314e7a b 0x31517c <FT_Bitmap_Embolden+0x336>
 *   @0x314e7e .word 0xf1bb8180
 *   @0x314e82 .word 0xf2c00f00
 *   @0x314e86 stcvc p1, c8, [r3], #496
 *   @0x314e8a subs r3, #0x1
 *   @0x314e8e bhi 0x314ee8 <FT_Bitmap_Embolden+0xa2>
 *   @0x314e92 eoreq pc, r0, r3, lsl r0
 *   @0x314e96 movs r2, r5
 *   @0x314e9a movs r7, r0
 *   @0x314e9e movs r7, r4
 *   @0x314ea2 add r7, sp, #0x20
 *   @0x314ea6 bl 0x3149bc <FT_Bitmap_Init>
 *   @0x314eaa mov r0, r9
 *   @0x314eae mov r2, r7
 *   @0x314eb2 bl 0x314ad0 <FT_Bitmap_Convert>
 *   @0x314eb6 cmp r0, #0x0
 *   @0x314eba strtmi r8, [r1], -r5, ror #2
 *   @0x314ebe mov r0, r9
 *   @0x314ec2 svcgt #0xfffac
 *   @0x314ec6 mov r6, r4
 *   @0x314eca ldm.w r7, {r0, r1}
 *   @0x314ece stm.w r6, {r0, r1}
 *   @0x314ed2 b 0x314ee8 <FT_Bitmap_Embolden+0xa2>
 *   @0x314ed6 it ge
 *   @0x314eda b 0x314ee8 <FT_Bitmap_Embolden+0xa2>
 *   @0x314ede muls r5, r3, r5
 *   @0x314ee2 movs r3, #0x3
 *   @0x314ee6 .word 0xf8d9fb0b
 *   @0x314eea stcvc p0, c6, [r3], #0
 *   @0x314eee ldr r7, [r4, #0x8]
 *   @0x314ef2 str r6, [sp, #0x18]
 *   @0x314ef6 svchs #0x600
 *   @0x314efa it lt
 *   @0x314efe cmp r3, #0x5
 *   @0x314f02 ldm pc, {r1, r3, r4, r5, r7, pc} ^
 *   @0x314f06 stmdane r3, {r0, r1, r12, sp, lr, pc}
 *   @0x314f0a asrs r2, r1, #0x4
 *   @0x314f0e add.w r6, r10, #0x7
 *   @0x314f12 mov.w r8, #0x1
 *   @0x314f16 add r6, r5
 *   @0x314f1a b 0x314f40 <FT_Bitmap_Embolden+0xfa>
 *   @0x314f1e .word 0xf04f0603
 *   @0x314f22 strtmi r0, [lr], #-2050
 *   @0x314f26 lsrs r6, r6, #0x2
 *   @0x314f2a add.w r6, r10, #0x1
 *   @0x314f2e mov.w r8, #0x4
 *   @0x314f32 add r6, r5
 *   @0x314f36 b 0x314f40 <FT_Bitmap_Embolden+0xfa>
 *   @0x314f3a .word 0xf04f060a
 *   @0x314f3e .word 0xf1bb0808
 *   @0x314f42 teqle r3, r0, lsl #30
 *   @0x314f46 cmp r6, r7
 *   @0x314f4a add.w r6, r5, r10
 *   @0x314f4e mul r6, r6, r8
 *   @0x314f52 cmp.w r6, r7, lsl #3
 *   @0x314f56 bhs.w 0x315068 <FT_Bitmap_Embolden+0x222>
 *   @0x314f5a ldr r3, [r4, #0xc]
 *   @0x314f5e vst1.8 {d16, d17}, [pc], r7
 *   @0x314f62 bl 0x3e7166 <error_g0017+0x3fe0a>
 *   @0x314f66 bl 0x3d6ac6 <error_g0017+0x2f76a>
 *   @0x314f6a blx 0xd17f8e <b2_toiTime+0x5beaea>
 *   @0x314f6e strlo pc, [r1], -r10, lsl #16
 *   @0x314f72 subs r0, r6, #0x1
 *   @0x314f76 rsbsle r0, r6, r0, lsl #30
 *   @0x314f7a cmp.w r10, #0x0
 *   @0x314f7e beq 0x314f8e <FT_Bitmap_Embolden+0x148>
 *   @0x314f82 ldrtmi r3, [r0], -r1, lsl #24
 *   @0x314f86 and.w r3, r3, r8
 *   @0x314f8a strb r3, [r6, #-1]
 *   @0x314f8e cmp r0, r12
 *   @0x314f92 rsb r2, r0, r12
 *   @0x314f96 movs r1, #0x0
 *   @0x314f9a .word 0xf5a1c010
 *   @0x314f9e .word 0xf8ddeb08
 *   @0x314fa2 .word 0xf109c010
 *   @0x314fa6 ldrtmi r3, [r12], #2559
 *   @0x314faa add r6, r7
 *   @0x314fae movs r2, #0x0
 *   @0x314fb2 add.w r1, r11, r9
 *   @0x314fb6 str r3, [sp, #0x4]
 *   @0x314fba mov r3, r6
 *   @0x314fbe bl 0x2e8010 <ft_mem_qrealloc>
 *   @0x314fc2 mov r9, r0
 *   @0x314fc6 cmp r0, #0x0
 *   @0x314fca stmvs r3!, {r0, r2, r3, r4, r6, r7, pc}
 *   @0x314fce mul r10, r10, r8
 *   @0x314fd2 cmp r3, #0x0
 *   @0x314fd6 vstmdble r11!, {s0, s1, s2, s3, s4, s5, s6}
 *   @0x314fda rsb r12, r6, r9
 *   @0x314fde lsr.w r10, r10, #0x3
 *   @0x314fe2 mov r8, r0
 *   @0x314fe6 blx 0x5fd060 <g_SWFaavertbuff+0x29f98>
 *   @0x314fea strmi r12, [r2], -r6, lsl #24
 *   @0x314fee mov r10, r0
 *   @0x314ff2 adds r3, r2, r7
 *   @0x314ff6 cmp r10, r1
 *   @0x314ffa ldr r1, [r4, #0xc]
 *   @0x314ffe movwls r0, #0x5008
 *   @0x315002 add.w r10, r10, #0x1
 *   @0x315006 add r1, r2
 *   @0x31500a str.w r12, [sp, #0x10]
 *   @0x31500e blx 0xb65bc <memcpy@plt>
 *   @0x315012 ldr r3, [sp, #0x14]
 *   @0x315016 sadd16mi r12, r10, r0
 *   @0x31501a b 0x314ff0 <FT_Bitmap_Embolden+0x1aa>
 *   @0x31501e ldr r1, [r4, #0xc]
 *   @0x315022 stmvs r3!, {r0, r3, r7, r8, r11, r12, sp, lr, pc}
 *   @0x315026 str.w r9, [r4, #0xc]
 *   @0x31502a cmp r3, #0x0
 *   @0x31502e rsbs r6, r6, #0
 *   @0x315032 lsr.w r12, r10, #0x3
 *   @0x315036 mov r3, r9
 *   @0x31503a mov r10, r0
 *   @0x31503e add.w r8, r2, r7
 *   @0x315042 cmp r10, r1
 *   @0x315046 ldr r1, [r4, #0xc]
 *   @0x31504a str.w r12, [sp, #0x10]
 *   @0x31504e add.w r10, r10, #0x1
 *   @0x315052 add r1, r2
 *   @0x315056 blx 0xb65bc <memcpy@plt>
 *   @0x31505a mov r2, r8
 *   @0x31505e .word 0x4603c010
 *   @0x315062 add r3, r6
 *   @0x315066 str r6, [r4, #0x8]
 *   @0x31506a movs r0, #0x0
 *   @0x31506e cmp r2, #0x0
 *   @0x315072 mla r1, r11, r2, r1
 *   @0x315076 b 0x315086 <FT_Bitmap_Embolden+0x240>
 *   @0x31507a b 0x315186 <FT_Bitmap_Embolden+0x340>
 *   @0x31507e rsbs r2, r2, #0
 *   @0x315082 mla r1, r3, r2, r1
 *   @0x315086 mov.w r12, #0x0
 *   @0x31508a ldr r3, [r4]
 *   @0x31508e bhs 0x31516c <FT_Bitmap_Embolden+0x326>
 *   @0x315092 adds r3, r1, r2
 *   @0x315096 beq 0x31513a <FT_Bitmap_Embolden+0x2f4>
 *   @0x31509a bl 0x3700a6 <_ZTS13C_UTF16String+0x7152>
 *   @0x31509e .word 0xf8cd0807
 *   @0x3150a2 .word 0x9606801c
 *   @0x3150a6 movs r6, #0x1
 *   @0x3150aa bgt 0x315134 <FT_Bitmap_Embolden+0x2ee>
 *   @0x3150ae .word 0xf1b88012
 *   @0x3150b2 tstle r7, r1, lsl #30
 *   @0x3150b6 ldr.w r9, [sp, #0x18]
 *   @0x3150ba asr.w r8, r9, r6
 *   @0x3150be ldrb r9, [r3, #-1]
 *   @0x3150c2 orr.w r8, r8, r9
 *   @0x3150c6 uxtb.w r8, r8
 *   @0x3150ca strb r8, [r3, #-1]
 *   @0x3150ce cbz r7, 0x315130 <FT_Bitmap_Embolden+0x2ea>
 *   @0x3150d2 .word 0xf1c6ac02
 *   @0x3150d6 blx 0x5974fe <g_SWFlineaavertbuff+0x44436>
 *   @0x3150da b 0x1553506 <b2_toiTime+0xdfa062>
 *   @0x3150de .word 0xf8030909
 *   @0x3150e2 eor r9, r4, r1, lsl #24
 *   @0x3150e6 rsb r8, r6, r7
 *   @0x3150ea cmp.w r8, #0x0
 *   @0x3150ee blt 0x315134 <FT_Bitmap_Embolden+0x2ee>
 *   @0x3150f2 .word 0xf1c6ac01
 *   @0x3150f6 rfeia r4!
 *   @0x3150fa .word 0xf8cd8010
 *   @0x3150fe .word 0xf8dda00c
 *   @0x315102 .word 0xf81aa01c
 *   @0x315106 .word 0xf8dd9009
 *   @0x31510a ldrbmi r10, [r1], #12
 *   @0x31510e cmp r8, r9
 *   @0x315112 add.w r8, r8, #0xffffffff
 *   @0x315116 strb r8, [r3, #-1]
 *   @0x31511a b 0x315134 <FT_Bitmap_Embolden+0x2ee>
 *   @0x31511e .word 0xf803f989
 *   @0x315122 rfeia r4!
 *   @0x315126 .word 0xf1088010
 *   @0x31512a strbmi r3, [r1, #0x8ff]
 *   @0x31512e beq 0x315134 <FT_Bitmap_Embolden+0x2ee>
 *   @0x315132 b 0x3150a8 <FT_Bitmap_Embolden+0x262>
 *   @0x315136 subs r3, #0x1
 *   @0x31513a movs r6, #0x1
 *   @0x31513e ldr r3, [r4, #0x8]
 *   @0x315142 mls r7, r3, r6, r1
 *   @0x315146 movs r3, #0x0
 *   @0x31514a bge 0x315160 <FT_Bitmap_Embolden+0x31a>
 *   @0x31514e .word 0xf8179003
 *   @0x315152 b 0x1575166 <b2_toiTime+0xe1bcc2>
 *   @0x315156 .word 0xf8070808
 *   @0x31515a movwlo r8, #0x1003
 *   @0x31515e b 0x315148 <FT_Bitmap_Embolden+0x302>
 *   @0x315162 b 0x31513c <FT_Bitmap_Embolden+0x2f6>
 *   @0x315166 add.w r12, r12, #0x1
 *   @0x31516a b 0x31508a <FT_Bitmap_Embolden+0x244>
 *   @0x31516e add r3, r11
 *   @0x315172 add r5, r2
 *   @0x315176 b 0x315186 <FT_Bitmap_Embolden+0x340>
 *   @0x31517a b 0x315186 <FT_Bitmap_Embolden+0x340>
 *   @0x31517e b 0x315186 <FT_Bitmap_Embolden+0x340>
 *   @0x315182 b 0x315186 <FT_Bitmap_Embolden+0x340>
 *   @0x315186 add sp, #0x3c
 *   @0x31518a push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §24/36 JS_Array_prototype_pop(RValue&, CInstance*, CInstance*, int, RValue*)  0x24f4b8  size 832  208 条（0x24f4b8..0x24f7f8）
 * @func 0x24f4b8 0x24f7f8  size 832  208 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / F_JS_Object_Get(YYObjectBase*, RValue*, char const*)×2 / YYGetUint32(RValue const*, int) / 0xb65c8 / JS_DeleteProperty(YYObjectBase*, RValue*, char const*, bool)
 * 字段偏移 top8: 0x4×9 / 0x8×8 / 0x24×7 / 0xc×4 / 0x54×2 / 0x10×2 / 0x28×2 / 0x2c×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24f4b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24f4bc sub sp, sp, #92
 *   @0x24f4c0 ldr r6, [pc, #0x320]
 *   @0x24f4c4 add r8, sp, #4
 *   @0x24f4c8 ldr r2, [pc, #0x31c]
 *   @0x24f4cc mov r5, #0
 *   @0x24f4d0 ldr r6, [pc, r6]
 *   @0x24f4d4 mov r7, r0
 *   @0x24f4d8 add r2, pc, r2
 *   @0x24f4dc mov r0, r1
 *   @0x24f4e0 ldr r3, [r6]
 *   @0x24f4e4 mov r9, r1
 *   @0x24f4e8 mov r1, r8
 *   @0x24f4ec mvn r10, #-16777216
 *   @0x24f4f0 str r5, [sp, #0x4]
 *   @0x24f4f4 str r3, [sp, #0x54]
 *   @0x24f4f8 str r5, [sp, #0x8]
 *   @0x24f4fc str r5, [sp, #0xc]
 *   @0x24f500 str r10, [sp, #0x10]
 *   @0x24f504 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24f508 mov r0, r8
 *   @0x24f50c mov r1, r5
 *   @0x24f510 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x24f514 mov r3, #5
 *   @0x24f518 str r3, [r7, #0xc]
 *   @0x24f51c str r3, [sp, #0x20]
 *   @0x24f520 cmp r0, #0
 *   @0x24f524 bne 0x24f540 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0x24f528 ldr r2, [sp, #0x54]
 *   @0x24f52c ldr r3, [r6]
 *   @0x24f530 cmp r2, r3
 *   @0x24f534 bne 0x24f7e4 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x32c>
 *   @0x24f538 add sp, sp, #92
 *   @0x24f53c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24f540 sub r4, r0, #1
 *   @0x24f544 add r11, sp, #52
 *   @0x24f548 ldr r2, [pc, #0x2a0]
 *   @0x24f54c mov r1, #32
 *   @0x24f550 mov r3, r4
 *   @0x24f554 mov r0, r11
 *   @0x24f558 add r2, pc, r2
 *   @0x24f55c bl 0xb65c8 <snprintf@plt>
 *   @0x24f560 mov r2, r11
 *   @0x24f564 mov r0, r9
 *   @0x24f568 add r1, sp, #36
 *   @0x24f56c str r5, [sp, #0x24]
 *   @0x24f570 str r5, [sp, #0x28]
 *   @0x24f574 str r5, [sp, #0x2c]
 *   @0x24f578 str r10, [sp, #0x30]
 *   @0x24f57c bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc>
 *   @0x24f580 ldr r2, [r7, #0xc]
 *   @0x24f584 and r3, r2, r10
 *   @0x24f588 cmp r3, #1
 *   @0x24f58c beq 0x24f674 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x24f590 cmp r3, #2
 *   @0x24f594 bne 0x24f5ac <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x24f598 sub r2, r2, #1
 *   @0x24f59c bic r2, r2, #-16777216
 *   @0x24f5a0 bic r2, r2, #3
 *   @0x24f5a4 cmp r2, #0
 *   @0x24f5a8 beq 0x24f70c <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x254>
 *   @0x24f5ac ldr r1, [sp, #0x30]
 *   @0x24f5b0 mov r0, #0
 *   @0x24f5b4 ldr r3, [sp, #0x2c]
 *   @0x24f5b8 bic r2, r1, #-16777216
 *   @0x24f5bc str r0, [r7]
 *   @0x24f5c0 str r1, [r7, #0xc]
 *   @0x24f5c4 str r3, [r7, #0x8]
 *   @0x24f5c8 cmp r2, #14
 *   @0x24f5cc addls pc, pc, r2, lsl #2
 *   @0x24f5d0 b 0x24f618 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24f5d4 b 0x24f664 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x24f5d8 b 0x24f6c8 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x210>
 *   @0x24f5dc b 0x24f6e0 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x228>
 *   @0x24f5e0 b 0x24f610 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x24f5e4 b 0x24f618 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24f5e8 b 0x24f618 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24f5ec b 0x24f6a8 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x24f5f0 b 0x24f610 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x24f5f4 b 0x24f618 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24f5f8 b 0x24f618 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24f5fc b 0x24f664 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x24f600 b 0x24f618 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24f604 b 0x24f618 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24f608 b 0x24f664 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x24f60c b 0x24f610 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x24f610 ldr r3, [sp, #0x24]
 *   @0x24f614 str r3, [r7]
 *   @0x24f618 mov r0, r9
 *   @0x24f61c add r1, sp, #20
 *   @0x24f620 mov r2, r11
 *   @0x24f624 mov r3, #1
 *   @0x24f628 bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb>
 *   @0x24f62c vmov s15, r4
 *   @0x24f630 ldr r2, [pc, #0x1bc]
 *   @0x24f634 mov r12, #0
 *   @0x24f638 vcvt.f64.u32 d7, s15
 *   @0x24f63c mov r0, r9
 *   @0x24f640 mov r3, r12
 *   @0x24f644 mov r1, r8
 *   @0x24f648 add r2, pc, r2
 *   @0x24f64c str r12, [sp, #0x10]
 *   @0x24f650 vmov r4, r5, d7
 *   @0x24f654 vstr s14, [sp, #4]
 *   @0x24f658 str r5, [sp, #0x8]
 *   @0x24f65c bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb>
 *   @0x24f660 b 0x24f528 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x24f664 ldr r2, [sp, #0x24]
 *   @0x24f668 ldr r3, [sp, #0x28]
 *   @0x24f66c stm r7, {r2, r3}
 *   @0x24f670 b 0x24f618 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24f674 ldr r5, [r7]
 *   @0x24f678 cmp r5, #0
 *   @0x24f67c beq 0x24f69c <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x24f680 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24f684 ldr r10, [r5, #0x4]
 *   @0x24f688 sub r10, r10, #1
 *   @0x24f68c str r10, [r5, #0x4]
 *   @0x24f690 cmp r10, #0
 *   @0x24f694 beq 0x24f718 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x260>
 *   @0x24f698 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24f69c mov r3, #0
 *   @0x24f6a0 str r3, [r7]
 *   @0x24f6a4 b 0x24f5ac <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x24f6a8 ldr r3, [sp, #0x24]
 *   @0x24f6ac cmp r3, #0
 *   @0x24f6b0 str r3, [r7]
 *   @0x24f6b4 beq 0x24f618 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24f6b8 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x24f6bc ldr r1, [sp, #0x24]
 *   @0x24f6c0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x24f6c4 b 0x24f618 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24f6c8 ldr r3, [sp, #0x24]
 *   @0x24f6cc cmp r3, #0
 *   @0x24f6d0 ldrne r2, [r3, #0x4]
 *   @0x24f6d4 addne r2, r2, #1
 *   @0x24f6d8 strne r2, [r3, #0x4]
 *   @0x24f6dc b 0x24f614 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x24f6e0 ldr r3, [sp, #0x24]
 *   @0x24f6e4 cmp r3, #0
 *   @0x24f6e8 str r3, [r7]
 *   @0x24f6ec beq 0x24f618 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24f6f0 ldr r1, [r3, #0x8]
 *   @0x24f6f4 ldr r2, [r3]
 *   @0x24f6f8 cmp r1, #0
 *   @0x24f6fc streq r7, [r3, #0x8]
 *   @0x24f700 add r2, r2, #1
 *   @0x24f704 str r2, [r3]
 *   @0x24f708 b 0x24f618 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x24f70c mov r0, r7
 *   @0x24f710 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24f714 b 0x24f5ac <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x24f718 ldr r0, [r5]
 *   @0x24f71c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24f720 str r10, [r5]
 *   @0x24f724 str r10, [r5, #0x8]
 *   @0x24f728 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24f72c ldr r10, [r5, #0x4]
 *   @0x24f730 sub r10, r10, #1
 *   @0x24f734 str r10, [r5, #0x4]
 *   @0x24f738 cmp r10, #0
 *   @0x24f73c beq 0x24f750 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x298>
 *   @0x24f740 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24f744 mov r0, r5
 *   @0x24f748 bl 0x27d1d0 <_ZdlPv>
 *   @0x24f74c b 0x24f698 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x24f750 ldr r0, [r5]
 *   @0x24f754 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24f758 str r10, [r5]
 *   @0x24f75c str r10, [r5, #0x8]
 *   @0x24f760 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24f764 ldr r10, [r5, #0x4]
 *   @0x24f768 sub r10, r10, #1
 *   @0x24f76c str r10, [r5, #0x4]
 *   @0x24f770 cmp r10, #0
 *   @0x24f774 beq 0x24f788 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x2d0>
 *   @0x24f778 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24f77c mov r0, r5
 *   @0x24f780 bl 0x27d1d0 <_ZdlPv>
 *   @0x24f784 b 0x24f740 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x288>
 *   @0x24f788 ldr r0, [r5]
 *   @0x24f78c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24f790 str r10, [r5]
 *   @0x24f794 str r10, [r5, #0x8]
 *   @0x24f798 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x24f79c ldr r10, [r5, #0x4]
 *   @0x24f7a0 sub r10, r10, #1
 *   @0x24f7a4 str r10, [r5, #0x4]
 *   @0x24f7a8 cmp r10, #0
 *   @0x24f7ac beq 0x24f7c0 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x308>
 *   @0x24f7b0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x24f7b4 mov r0, r5
 *   @0x24f7b8 bl 0x27d1d0 <_ZdlPv>
 *   @0x24f7bc b 0x24f778 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x2c0>
 *   @0x24f7c0 ldr r0, [r5]
 *   @0x24f7c4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x24f7c8 mov r0, r5
 *   @0x24f7cc str r10, [r5]
 *   @0x24f7d0 str r10, [r5, #0x8]
 *   @0x24f7d4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x24f7d8 mov r0, r5
 *   @0x24f7dc bl 0x27d1d0 <_ZdlPv>
 *   @0x24f7e0 b 0x24f7b0 <_Z22JS_Array_prototype_popR6RValueP9CInstanceS2_iPS_+0x2f8>
 *   @0x24f7e4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x24f7e8 andseq lr, r9, r0, lsl #9
 *   @0x24f7ec muleq lr, r4, r3
 *   @0x24f7f0 andseq r6, r0, r8, lsl #18
 *   @0x24f7f4 andeq r1, lr, r4, lsr #4
 *
 * ══ §25/36 anon_283d14  0x283d14  size 832  208 条（0x283d14..0x284054）
 * @func 0x283d14 0x284054  size 832  208 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_283d14×4 / anon_283d14+0xd4×2 / anon_283d14+0xc0 / _malloc / 0xb65bc / 0xb65e0
 * 字段偏移 top8: 0x4×11 / 0x1×4 / 0x-1×4 / 0xc8×1 / 0x28×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x283d14 ldr r3, [pc, #0xc8]
 *   @0x283d18 ldr r2, [r0]
 *   @0x283d1c ldr r3, [pc, r3]
 *   @0x283d20 push {r4, r5}
 *   @0x283d24 ldr r1, [r3]
 *   @0x283d28 ldrb r12, [r2]
 *   @0x283d2c ldr r5, [r0, #0x4]
 *   @0x283d30 add r3, r1, r12
 *   @0x283d34 ldrb r3, [r3, #0x1]
 *   @0x283d38 tst r3, #8
 *   @0x283d3c beq 0x283d78 <spAnimationStateData_getMix+0xd0>
 *   @0x283d40 cmp r2, r5
 *   @0x283d44 bhs 0x283d78 <spAnimationStateData_getMix+0xd0>
 *   @0x283d48 add r3, r2, #1
 *   @0x283d4c add r4, r5, #1
 *   @0x283d50 str r3, [r0]
 *   @0x283d54 mov r2, r3
 *   @0x283d58 ldrb r12, [r3]
 *   @0x283d5c add r3, r3, #1
 *   @0x283d60 add r12, r1, r12
 *   @0x283d64 ldrb r12, [r12, #0x1]
 *   @0x283d68 tst r12, #8
 *   @0x283d6c beq 0x283d78 <spAnimationStateData_getMix+0xd0>
 *   @0x283d70 cmp r3, r4
 *   @0x283d74 bne 0x283d50 <spAnimationStateData_getMix+0xa8>
 *   @0x283d78 cmp r2, r5
 *   @0x283d7c beq 0x283ddc <spAnimationStateData_getMix+0x134>
 *   @0x283d80 sub r12, r5, #1
 *   @0x283d84 str r12, [r0, #0x4]
 *   @0x283d88 ldrb r3, [r5, #-0x1]
 *   @0x283d8c add r3, r1, r3
 *   @0x283d90 ldrb r3, [r3, #0x1]
 *   @0x283d94 tst r3, #8
 *   @0x283d98 beq 0x283dd4 <spAnimationStateData_getMix+0x12c>
 *   @0x283d9c cmp r12, r2
 *   @0x283da0 blo 0x283dd4 <spAnimationStateData_getMix+0x12c>
 *   @0x283da4 sub r3, r5, #2
 *   @0x283da8 sub r2, r2, #2
 *   @0x283dac str r3, [r0, #0x4]
 *   @0x283db0 mov r12, r3
 *   @0x283db4 ldrb r4, [r3]
 *   @0x283db8 sub r3, r3, #1
 *   @0x283dbc add r4, r1, r4
 *   @0x283dc0 ldrb r4, [r4, #0x1]
 *   @0x283dc4 tst r4, #8
 *   @0x283dc8 beq 0x283dd4 <spAnimationStateData_getMix+0x12c>
 *   @0x283dcc cmp r3, r2
 *   @0x283dd0 bne 0x283dac <spAnimationStateData_getMix+0x104>
 *   @0x283dd4 add r12, r12, #1
 *   @0x283dd8 str r12, [r0, #0x4]
 *   @0x283ddc pop {r4, r5}
 *   @0x283de0 bx lr
 *   @0x283de4 andseq r9, r6, r4, ror #24
 *   @0x283de8 push {r3, r4, r5, lr}
 *   @0x283dec mov r4, r0
 *   @0x283df0 ldr r3, [r0]
 *   @0x283df4 mov r5, r1
 *   @0x283df8 cmp r3, r1
 *   @0x283dfc beq 0x283e6c <spAnimationStateData_getMix+0x1c4>
 *   @0x283e00 str r3, [r2]
 *   @0x283e04 ldr r12, [r0]
 *   @0x283e08 cmp r12, r1
 *   @0x283e0c beq 0x283e44 <spAnimationStateData_getMix+0x19c>
 *   @0x283e10 ldrb r3, [r12]
 *   @0x283e14 cmp r3, #10
 *   @0x283e18 beq 0x283e44 <spAnimationStateData_getMix+0x19c>
 *   @0x283e1c add r3, r12, #1
 *   @0x283e20 b 0x283e30 <spAnimationStateData_getMix+0x188>
 *   @0x283e24 ldrb lr, [r12]
 *   @0x283e28 cmp lr, #10
 *   @0x283e2c beq 0x283e44 <spAnimationStateData_getMix+0x19c>
 *   @0x283e30 cmp r3, r5
 *   @0x283e34 str r3, [r4]
 *   @0x283e38 mov r12, r3
 *   @0x283e3c add r3, r3, #1
 *   @0x283e40 bne 0x283e24 <spAnimationStateData_getMix+0x17c>
 *   @0x283e44 str r12, [r2, #0x4]
 *   @0x283e48 mov r0, r2
 *   @0x283e4c bl 0x283d14 <spAnimationStateData_getMix+0x6c>
 *   @0x283e50 ldr r3, [r4]
 *   @0x283e54 cmp r3, r5
 *   @0x283e58 beq 0x283e74 <spAnimationStateData_getMix+0x1cc>
 *   @0x283e5c add r3, r3, #1
 *   @0x283e60 mov r0, #1
 *   @0x283e64 str r3, [r4]
 *   @0x283e68 pop {r3, r4, r5, pc}
 *   @0x283e6c mov r0, #0
 *   @0x283e70 pop {r3, r4, r5, pc}
 *   @0x283e74 mov r0, #1
 *   @0x283e78 pop {r3, r4, r5, pc}
 *   @0x283e7c push {r3, r4, r5, lr}
 *   @0x283e80 mov r5, r2
 *   @0x283e84 bl 0x283de8 <spAnimationStateData_getMix+0x140>
 *   @0x283e88 ldm r5, {r3, r12}
 *   @0x283e8c add r3, r3, #1
 *   @0x283e90 add r12, r12, #1
 *   @0x283e94 b 0x283ea0 <spAnimationStateData_getMix+0x1f8>
 *   @0x283e98 cmp r1, #58
 *   @0x283e9c beq 0x283ebc <spAnimationStateData_getMix+0x214>
 *   @0x283ea0 cmp r3, r12
 *   @0x283ea4 mov r4, r3
 *   @0x283ea8 ldrb r1, [r3, #-0x1]
 *   @0x283eac add r3, r3, #1
 *   @0x283eb0 bne 0x283e98 <spAnimationStateData_getMix+0x1f0>
 *   @0x283eb4 mov r0, #0
 *   @0x283eb8 pop {r3, r4, r5, pc}
 *   @0x283ebc mov r0, r5
 *   @0x283ec0 str r4, [r5]
 *   @0x283ec4 bl 0x283d14 <spAnimationStateData_getMix+0x6c>
 *   @0x283ec8 mov r0, #1
 *   @0x283ecc pop {r3, r4, r5, pc}
 *   @0x283ed0 push {r4, r5, r6, r7, r8, lr}
 *   @0x283ed4 sub sp, sp, #8
 *   @0x283ed8 mov r5, r2
 *   @0x283edc mov r3, #0
 *   @0x283ee0 mov r2, sp
 *   @0x283ee4 str r3, [sp]
 *   @0x283ee8 str r3, [sp, #0x4]
 *   @0x283eec bl 0x283de8 <spAnimationStateData_getMix+0x140>
 *   @0x283ef0 ldm sp, {r3, r7}
 *   @0x283ef4 add r12, r7, #1
 *   @0x283ef8 add r3, r3, #1
 *   @0x283efc b 0x283f08 <spAnimationStateData_getMix+0x260>
 *   @0x283f00 cmp r1, #58
 *   @0x283f04 beq 0x283f2c <spAnimationStateData_getMix+0x284>
 *   @0x283f08 cmp r3, r12
 *   @0x283f0c mov r4, r3
 *   @0x283f10 ldrb r1, [r3, #-0x1]
 *   @0x283f14 add r3, r3, #1
 *   @0x283f18 bne 0x283f00 <spAnimationStateData_getMix+0x258>
 *   @0x283f1c mov r8, #0
 *   @0x283f20 mov r0, r8
 *   @0x283f24 add sp, sp, #8
 *   @0x283f28 pop {r4, r5, r6, r7, r8, pc}
 *   @0x283f2c mov r2, r4
 *   @0x283f30 mov r6, r5
 *   @0x283f34 mov r8, #0
 *   @0x283f38 str r4, [sp]
 *   @0x283f3c add r3, r2, #1
 *   @0x283f40 mov r4, r6
 *   @0x283f44 str r2, [r6]
 *   @0x283f48 b 0x283f54 <spAnimationStateData_getMix+0x2ac>
 *   @0x283f4c cmp r1, #44
 *   @0x283f50 beq 0x283f88 <spAnimationStateData_getMix+0x2e0>
 *   @0x283f54 cmp r3, r12
 *   @0x283f58 mov lr, r3
 *   @0x283f5c ldrb r1, [r3, #-0x1]
 *   @0x283f60 add r3, r3, #1
 *   @0x283f64 bne 0x283f4c <spAnimationStateData_getMix+0x2a4>
 *   @0x283f68 add r8, r8, #1
 *   @0x283f6c mov r0, r4
 *   @0x283f70 str r2, [r4]
 *   @0x283f74 str r7, [r4, #0x4]
 *   @0x283f78 bl 0x283d14 <spAnimationStateData_getMix+0x6c>
 *   @0x283f7c mov r0, r8
 *   @0x283f80 add sp, sp, #8
 *   @0x283f84 pop {r4, r5, r6, r7, r8, pc}
 *   @0x283f88 sub r3, lr, #2
 *   @0x283f8c mov r0, r6
 *   @0x283f90 str r3, [r6, #0x4]
 *   @0x283f94 add r8, r8, #1
 *   @0x283f98 str lr, [sp]
 *   @0x283f9c bl 0x283d14 <spAnimationStateData_getMix+0x6c>
 *   @0x283fa0 cmp r8, #3
 *   @0x283fa4 add r6, r6, #8
 *   @0x283fa8 ldmne sp, {r2, r7}
 *   @0x283fac addne r12, r7, #1
 *   @0x283fb0 bne 0x283f3c <spAnimationStateData_getMix+0x294>
 *   @0x283fb4 ldr r2, [sp]
 *   @0x283fb8 add r4, r5, #24
 *   @0x283fbc ldr r7, [sp, #0x4]
 *   @0x283fc0 mov r8, #4
 *   @0x283fc4 b 0x283f6c <spAnimationStateData_getMix+0x2c4>
 *   @0x283fc8 push {r3, r4, r5, lr}
 *   @0x283fcc mov r2, #137
 *   @0x283fd0 ldr r3, [r0]
 *   @0x283fd4 mov r5, r0
 *   @0x283fd8 ldr r4, [r0, #0x4]
 *   @0x283fdc ldr r1, [pc, #0x28]
 *   @0x283fe0 rsb r4, r3, r4
 *   @0x283fe4 add r1, pc, r1
 *   @0x283fe8 add r0, r4, #1
 *   @0x283fec bl 0x285c10 <_malloc>
 *   @0x283ff0 mov r2, r4
 *   @0x283ff4 ldr r1, [r5]
 *   @0x283ff8 bl 0xb65bc <memcpy@plt>
 *   @0x283ffc mov r2, #0
 *   @0x284000 mov r3, r0
 *   @0x284004 strb r2, [r3, r4]
 *   @0x284008 pop {r3, r4, r5, pc}
 *   @0x28400c andeq r3, sp, r0, lsr #10
 *   @0x284010 push {r3, r4, r5, r6, r7, lr}
 *   @0x284014 add r5, r0, #32
 *   @0x284018 ldr r6, [r1]
 *   @0x28401c mov r4, #7
 *   @0x284020 ldr r7, [r1, #0x4]
 *   @0x284024 rsb r7, r6, r7
 *   @0x284028 ldr r0, [r5, #-0x4]!
 *   @0x28402c mov r1, r6
 *   @0x284030 mov r2, r7
 *   @0x284034 bl 0xb65e0 <strncmp@plt>
 *   @0x284038 cmp r0, #0
 *   @0x28403c beq 0x284050 <spAnimationStateData_getMix+0x3a8>
 *   @0x284040 subs r4, r4, #1
 *   @0x284044 bhs 0x284028 <spAnimationStateData_getMix+0x380>
 *   @0x284048 mov r0, #0
 *   @0x28404c pop {r3, r4, r5, r6, r7, pc}
 *   @0x284050 mov r0, r4
 *
 * ══ §26/36 CPhysicsJoint::SetValue(int, float)  0x23bb14  size 824  206 条（0x23bb14..0x23be4c）
 * @func 0x23bb14 0x23be4c  size 824  206 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2RevoluteJoint::GetUpperLimit() const / b2RevoluteJoint::GetLowerLimit() const
 * 字段偏移 top8: 0x4×34 / 0x30×3 / 0x34×3 / 0x44×1 / 0x48×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23bb14 sub r1, r1, #7
 *   @0x23bb18 push {r4, lr}
 *   @0x23bb1c sub sp, sp, #8
 *   @0x23bb20 cmp r1, #17
 *   @0x23bb24 addls pc, pc, r1, lsl #2
 *   @0x23bb28 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bb2c b 0x23bbc0 <_ZN13CPhysicsJoint8SetValueEif+0xac>
 *   @0x23bb30 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bb34 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bb38 b 0x23bc28 <_ZN13CPhysicsJoint8SetValueEif+0x114>
 *   @0x23bb3c b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bb40 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bb44 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bb48 b 0x23bc50 <_ZN13CPhysicsJoint8SetValueEif+0x13c>
 *   @0x23bb4c b 0x23bc70 <_ZN13CPhysicsJoint8SetValueEif+0x15c>
 *   @0x23bb50 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bb54 b 0x23bc84 <_ZN13CPhysicsJoint8SetValueEif+0x170>
 *   @0x23bb58 b 0x23bb74 <_ZN13CPhysicsJoint8SetValueEif+0x60>
 *   @0x23bb5c b 0x23bcac <_ZN13CPhysicsJoint8SetValueEif+0x198>
 *   @0x23bb60 b 0x23bcf0 <_ZN13CPhysicsJoint8SetValueEif+0x1dc>
 *   @0x23bb64 b 0x23bd3c <_ZN13CPhysicsJoint8SetValueEif+0x228>
 *   @0x23bb68 b 0x23bd70 <_ZN13CPhysicsJoint8SetValueEif+0x25c>
 *   @0x23bb6c b 0x23bd84 <_ZN13CPhysicsJoint8SetValueEif+0x270>
 *   @0x23bb70 b 0x23bba0 <_ZN13CPhysicsJoint8SetValueEif+0x8c>
 *   @0x23bb74 ldr r1, [r0, #0x4]
 *   @0x23bb78 ldr r3, [r1, #0x4]
 *   @0x23bb7c cmp r3, #3
 *   @0x23bb80 beq 0x23bb94 <_ZN13CPhysicsJoint8SetValueEif+0x80>
 *   @0x23bb84 cmp r3, #7
 *   @0x23bb88 beq 0x23bb94 <_ZN13CPhysicsJoint8SetValueEif+0x80>
 *   @0x23bb8c cmp r3, #8
 *   @0x23bb90 bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bb94 str r2, [r1, #0x44]
 *   @0x23bb98 add sp, sp, #8
 *   @0x23bb9c pop {r4, pc}
 *   @0x23bba0 ldr r0, [r0, #0x4]
 *   @0x23bba4 ldr r3, [r0, #0x4]
 *   @0x23bba8 cmp r3, #9
 *   @0x23bbac bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bbb0 mov r1, r2
 *   @0x23bbb4 add sp, sp, #8
 *   @0x23bbb8 pop {r4, lr}
 *   @0x23bbbc b 0x2cda80 <_ZN15b2FrictionJoint11SetMaxForceEf>
 *   @0x23bbc0 ldr r0, [r0, #0x4]
 *   @0x23bbc4 ldr r3, [r0, #0x4]
 *   @0x23bbc8 cmp r3, #2
 *   @0x23bbcc beq 0x23bdec <_ZN13CPhysicsJoint8SetValueEif+0x2d8>
 *   @0x23bbd0 cmp r3, #7
 *   @0x23bbd4 beq 0x23bda4 <_ZN13CPhysicsJoint8SetValueEif+0x290>
 *   @0x23bbd8 cmp r3, #1
 *   @0x23bbdc bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bbe0 ldr r3, [r0, #0x30]
 *   @0x23bbe4 ldrh r1, [r3, #4]
 *   @0x23bbe8 tst r1, #2
 *   @0x23bbec orreq r1, r1, #2
 *   @0x23bbf0 strheq r1, [r3, #4]
 *   @0x23bbf4 moveq r12, #0
 *   @0x23bbf8 streq r12, [r3, #0xa0]
 *   @0x23bbfc ldr r3, [r0, #0x34]
 *   @0x23bc00 ldrh r1, [r3, #4]
 *   @0x23bc04 tst r1, #2
 *   @0x23bc08 orreq r1, r1, #2
 *   @0x23bc0c strheq r1, [r3, #4]
 *   @0x23bc10 moveq r12, #0
 *   @0x23bc14 mov r1, r2
 *   @0x23bc18 streq r12, [r3, #0xa0]
 *   @0x23bc1c add sp, sp, #8
 *   @0x23bc20 pop {r4, lr}
 *   @0x23bc24 b 0x2d21a0 <_ZN15b2RevoluteJoint13SetMotorSpeedEf>
 *   @0x23bc28 ldr r0, [r0, #0x4]
 *   @0x23bc2c ldr r3, [r0, #0x4]
 *   @0x23bc30 cmp r3, #1
 *   @0x23bc34 beq 0x23be34 <_ZN13CPhysicsJoint8SetValueEif+0x320>
 *   @0x23bc38 cmp r3, #7
 *   @0x23bc3c bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bc40 mov r1, r2
 *   @0x23bc44 add sp, sp, #8
 *   @0x23bc48 pop {r4, lr}
 *   @0x23bc4c b 0x2d4424 <_ZN12b2WheelJoint17SetMaxMotorTorqueEf>
 *   @0x23bc50 ldr r0, [r0, #0x4]
 *   @0x23bc54 ldr r3, [r0, #0x4]
 *   @0x23bc58 cmp r3, #2
 *   @0x23bc5c bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bc60 mov r1, r2
 *   @0x23bc64 add sp, sp, #8
 *   @0x23bc68 pop {r4, lr}
 *   @0x23bc6c b 0x2d04bc <_ZN16b2PrismaticJoint16SetMaxMotorForceEf>
 *   @0x23bc70 ldr r3, [r0, #0x4]
 *   @0x23bc74 ldr r1, [r3, #0x4]
 *   @0x23bc78 cmp r1, #3
 *   @0x23bc7c streq r2, [r3, #0x68]
 *   @0x23bc80 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bc84 ldr r1, [r0, #0x4]
 *   @0x23bc88 ldr r3, [r1, #0x4]
 *   @0x23bc8c cmp r3, #3
 *   @0x23bc90 beq 0x23bca4 <_ZN13CPhysicsJoint8SetValueEif+0x190>
 *   @0x23bc94 cmp r3, #7
 *   @0x23bc98 beq 0x23bca4 <_ZN13CPhysicsJoint8SetValueEif+0x190>
 *   @0x23bc9c cmp r3, #8
 *   @0x23bca0 bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bca4 str r2, [r1, #0x48]
 *   @0x23bca8 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bcac ldr r4, [r0, #0x4]
 *   @0x23bcb0 ldr r3, [r4, #0x4]
 *   @0x23bcb4 cmp r3, #1
 *   @0x23bcb8 bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bcbc mov r0, r4
 *   @0x23bcc0 str r2, [sp, #0x4]
 *   @0x23bcc4 bl 0x2d2284 <_ZNK15b2RevoluteJoint13GetUpperLimitEv>
 *   @0x23bcc8 ldr r2, [sp, #0x4]
 *   @0x23bccc vldr s14, [pc, #368]
 *   @0x23bcd0 vmov s15, r2
 *   @0x23bcd4 vmul.f32 s14, s15, s14
 *   @0x23bcd8 vldr s15, [pc, #360]
 *   @0x23bcdc vdiv.f32 s15, s14, s15
 *   @0x23bce0 mov r2, r0
 *   @0x23bce4 mov r0, r4
 *   @0x23bce8 vmov r1, s15
 *   @0x23bcec b 0x23bd30 <_ZN13CPhysicsJoint8SetValueEif+0x21c>
 *   @0x23bcf0 ldr r4, [r0, #0x4]
 *   @0x23bcf4 ldr r3, [r4, #0x4]
 *   @0x23bcf8 cmp r3, #1
 *   @0x23bcfc bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bd00 mov r0, r4
 *   @0x23bd04 str r2, [sp, #0x4]
 *   @0x23bd08 bl 0x2d227c <_ZNK15b2RevoluteJoint13GetLowerLimitEv>
 *   @0x23bd0c ldr r2, [sp, #0x4]
 *   @0x23bd10 vldr s14, [pc, #300]
 *   @0x23bd14 vmov s15, r2
 *   @0x23bd18 vmul.f32 s14, s15, s14
 *   @0x23bd1c vldr s15, [pc, #292]
 *   @0x23bd20 vdiv.f32 s15, s14, s15
 *   @0x23bd24 mov r1, r0
 *   @0x23bd28 mov r0, r4
 *   @0x23bd2c vmov r2, s15
 *   @0x23bd30 add sp, sp, #8
 *   @0x23bd34 pop {r4, lr}
 *   @0x23bd38 b 0x2d228c <_ZN15b2RevoluteJoint9SetLimitsEff>
 *   @0x23bd3c ldr r0, [r0, #0x4]
 *   @0x23bd40 ldr r3, [r0, #0x4]
 *   @0x23bd44 cmp r3, #1
 *   @0x23bd48 bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bd4c vmov.f32 s15, #5.000000e-01
 *   @0x23bd50 vmov s14, r2
 *   @0x23bd54 vcmpe.f32 s14, s15
 *   @0x23bd58 vmrs APSR_nzcv, fpscr
 *   @0x23bd5c movle r1, #0
 *   @0x23bd60 movgt r1, #1
 *   @0x23bd64 add sp, sp, #8
 *   @0x23bd68 pop {r4, lr}
 *   @0x23bd6c b 0x2d2228 <_ZN15b2RevoluteJoint11EnableLimitEb>
 *   @0x23bd70 ldr r3, [r0, #0x4]
 *   @0x23bd74 ldr r1, [r3, #0x4]
 *   @0x23bd78 cmp r1, #10
 *   @0x23bd7c streq r2, [r3, #0x54]
 *   @0x23bd80 b 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bd84 ldr r0, [r0, #0x4]
 *   @0x23bd88 ldr r3, [r0, #0x4]
 *   @0x23bd8c cmp r3, #9
 *   @0x23bd90 bne 0x23bb98 <_ZN13CPhysicsJoint8SetValueEif+0x84>
 *   @0x23bd94 mov r1, r2
 *   @0x23bd98 add sp, sp, #8
 *   @0x23bd9c pop {r4, lr}
 *   @0x23bda0 b 0x2cdb20 <_ZN15b2FrictionJoint12SetMaxTorqueEf>
 *   @0x23bda4 ldr r3, [r0, #0x30]
 *   @0x23bda8 ldrh r1, [r3, #4]
 *   @0x23bdac tst r1, #2
 *   @0x23bdb0 orreq r1, r1, #2
 *   @0x23bdb4 strheq r1, [r3, #4]
 *   @0x23bdb8 moveq r12, #0
 *   @0x23bdbc streq r12, [r3, #0xa0]
 *   @0x23bdc0 ldr r3, [r0, #0x34]
 *   @0x23bdc4 ldrh r1, [r3, #4]
 *   @0x23bdc8 tst r1, #2
 *   @0x23bdcc orreq r1, r1, #2
 *   @0x23bdd0 strheq r1, [r3, #4]
 *   @0x23bdd4 moveq r12, #0
 *   @0x23bdd8 mov r1, r2
 *   @0x23bddc streq r12, [r3, #0xa0]
 *   @0x23bde0 add sp, sp, #8
 *   @0x23bde4 pop {r4, lr}
 *   @0x23bde8 b 0x2d43e4 <_ZN12b2WheelJoint13SetMotorSpeedEf>
 *   @0x23bdec ldr r3, [r0, #0x30]
 *   @0x23bdf0 ldrh r1, [r3, #4]
 *   @0x23bdf4 tst r1, #2
 *   @0x23bdf8 orreq r1, r1, #2
 *   @0x23bdfc strheq r1, [r3, #4]
 *   @0x23be00 moveq r12, #0
 *   @0x23be04 streq r12, [r3, #0xa0]
 *   @0x23be08 ldr r3, [r0, #0x34]
 *   @0x23be0c ldrh r1, [r3, #4]
 *   @0x23be10 tst r1, #2
 *   @0x23be14 orreq r1, r1, #2
 *   @0x23be18 strheq r1, [r3, #4]
 *   @0x23be1c moveq r12, #0
 *   @0x23be20 mov r1, r2
 *   @0x23be24 streq r12, [r3, #0xa0]
 *   @0x23be28 add sp, sp, #8
 *   @0x23be2c pop {r4, lr}
 *   @0x23be30 b 0x2d047c <_ZN16b2PrismaticJoint13SetMotorSpeedEf>
 *   @0x23be34 mov r1, r2
 *   @0x23be38 add sp, sp, #8
 *   @0x23be3c pop {r4, lr}
 *   @0x23be40 b 0x2d21e0 <_ZN15b2RevoluteJoint17SetMaxMotorTorqueEf>
 *   @0x23be44 ldrdmi r0, r1, [r9], #-251
 *   @0x23be48 teqmi r4, #0
 *
 * ══ §27/36 WritePNG32(char*, void*, int, int)  0x16cc8c  size 820  205 条（0x16cc8c..0x16cfc0）
 * @func 0x16cc8c 0x16cfc0  size 820  205 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16cd58→0x3eb70c, 0x16ce5c→0x3eb70c, 0x16ce74→0x3eb70c, 0x16ce84→0x3eb70c, 0x16ce94→0x3eb70c, 0x16cf60→0x3eb70c
 * 调用序列: png_set_longjmp_fn×4 / 0xb6904×4 / LoadSave::_GetSaveFileName(char*, int, char const*) / EnsureDirectoryIsCreated(char const*) / LoadSave::fopen(char const*, char const*) / png_create_write_struct / png_create_info_struct / png_destroy_write_struct
 * 字段偏移 top8: 0x18×10 / 0x34×10 / 0x38×5 / 0x24×4 / 0x20×4 / 0xc×4 / 0x2c×4 / 0x1c×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16cc8c push {r4, lr}
 *   @0x16cc90 sub sp, sp, #2112
 *   @0x16cc94 ldr r12, [pc, #0x2ec]
 *   @0x16cc98 add r4, sp, #60
 *   @0x16cc9c str r1, [sp, #0x1c]
 *   @0x16cca0 mov lr, r0
 *   @0x16cca4 add r12, pc, r12
 *   @0x16cca8 str r12, [sp, #0x18]
 *   @0x16ccac ldr r1, [sp, #0x18]
 *   @0x16ccb0 mov r0, r4
 *   @0x16ccb4 ldr r12, [pc, #0x2d0]
 *   @0x16ccb8 str r2, [sp, #0x28]
 *   @0x16ccbc mov r2, lr
 *   @0x16ccc0 ldr r12, [r1, r12]
 *   @0x16ccc4 mov r1, #2048
 *   @0x16ccc8 str r3, [sp, #0x24]
 *   @0x16cccc ldr r3, [r12]
 *   @0x16ccd0 str r3, [sp, #0x83c]
 *   @0x16ccd4 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x16ccd8 mov r0, r4
 *   @0x16ccdc bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc>
 *   @0x16cce0 ldr r1, [pc, #0x2a8]
 *   @0x16cce4 mov r0, r4
 *   @0x16cce8 add r1, pc, r1
 *   @0x16ccec bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_>
 *   @0x16ccf0 cmp r0, #0
 *   @0x16ccf4 str r0, [sp, #0x20]
 *   @0x16ccf8 beq 0x16ce68 <_Z10WritePNG32PcPvii+0x1dc>
 *   @0x16ccfc ldr r0, [pc, #0x290]
 *   @0x16cd00 mov r1, #0
 *   @0x16cd04 mov r2, r1
 *   @0x16cd08 mov r3, r1
 *   @0x16cd0c add r0, pc, r0
 *   @0x16cd10 blx 0x2b0364 <png_create_write_struct>
 *   @0x16cd14 cmp r0, #0
 *   @0x16cd18 str r0, [sp, #0x34]
 *   @0x16cd1c beq 0x16ce80 <_Z10WritePNG32PcPvii+0x1f4>
 *   @0x16cd20 blx 0x2a5b64 <png_create_info_struct>
 *   @0x16cd24 cmp r0, #0
 *   @0x16cd28 str r0, [sp, #0x38]
 *   @0x16cd2c beq 0x16ce90 <_Z10WritePNG32PcPvii+0x204>
 *   @0x16cd30 ldr r3, [pc, #0x260]
 *   @0x16cd34 mov r2, #256
 *   @0x16cd38 ldr r12, [sp, #0x18]
 *   @0x16cd3c ldr r0, [sp, #0x34]
 *   @0x16cd40 ldr r1, [r12, r3]
 *   @0x16cd44 blx 0x2a653c <png_set_longjmp_fn>
 *   @0x16cd48 bl 0xb6904 <setjmp@plt>
 *   @0x16cd4c cmp r0, #0
 *   @0x16cd50 beq 0x16cdb8 <_Z10WritePNG32PcPvii+0x12c>
 *   @0x16cd54 ldr r1, [pc, #0x240]
 *   @0x16cd58 ldr r3, [pc, #0x240]
 *   @0x16cd5c add r1, pc, r1
 *   @0x16cd60 ldr r2, [sp, #0x18]
 *   @0x16cd64 ldr r3, [r2, r3]
 *   @0x16cd68 ldr r0, [r3]
 *   @0x16cd6c ldr r3, [r0]
 *   @0x16cd70 ldr r3, [r3, #0xc]
 *   @0x16cd74 blx r3
 *   @0x16cd78 mov r4, #0
 *   @0x16cd7c add r0, sp, #52
 *   @0x16cd80 add r1, sp, #56
 *   @0x16cd84 blx 0x2b0692 <png_destroy_write_struct>
 *   @0x16cd88 ldr r0, [sp, #0x20]
 *   @0x16cd8c bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE>
 *   @0x16cd90 mov r0, r4
 *   @0x16cd94 ldr r3, [pc, #0x1f0]
 *   @0x16cd98 ldr r12, [sp, #0x18]
 *   @0x16cd9c ldr r2, [sp, #0x83c]
 *   @0x16cda0 ldr r3, [r12, r3]
 *   @0x16cda4 ldr r3, [r3]
 *   @0x16cda8 cmp r2, r3
 *   @0x16cdac bne 0x16cf84 <_Z10WritePNG32PcPvii+0x2f8>
 *   @0x16cdb0 add sp, sp, #2112
 *   @0x16cdb4 pop {r4, pc}
 *   @0x16cdb8 ldr r2, [pc, #0x1e4]
 *   @0x16cdbc ldr r3, [pc, #0x1e4]
 *   @0x16cdc0 ldr r0, [sp, #0x34]
 *   @0x16cdc4 add r2, pc, r2
 *   @0x16cdc8 ldr r1, [sp, #0x20]
 *   @0x16cdcc add r3, pc, r3
 *   @0x16cdd0 blx 0x2afc18 <png_set_write_fn>
 *   @0x16cdd4 ldr r3, [pc, #0x1bc]
 *   @0x16cdd8 ldr r12, [sp, #0x18]
 *   @0x16cddc mov r2, #256
 *   @0x16cde0 ldr r0, [sp, #0x34]
 *   @0x16cde4 ldr r1, [r12, r3]
 *   @0x16cde8 blx 0x2a653c <png_set_longjmp_fn>
 *   @0x16cdec bl 0xb6904 <setjmp@plt>
 *   @0x16cdf0 subs r3, r0, #0
 *   @0x16cdf4 bne 0x16ce70 <_Z10WritePNG32PcPvii+0x1e4>
 *   @0x16cdf8 mov lr, #8
 *   @0x16cdfc mov r12, #6
 *   @0x16ce00 ldr r2, [sp, #0x28]
 *   @0x16ce04 str lr, [sp]
 *   @0x16ce08 str r12, [sp, #0x4]
 *   @0x16ce0c ldr r0, [sp, #0x34]
 *   @0x16ce10 ldr r1, [sp, #0x38]
 *   @0x16ce14 str r3, [sp, #0x8]
 *   @0x16ce18 str r3, [sp, #0xc]
 *   @0x16ce1c str r3, [sp, #0x10]
 *   @0x16ce20 ldr r3, [sp, #0x24]
 *   @0x16ce24 blx 0x2aea84 <png_set_IHDR>
 *   @0x16ce28 ldr r0, [sp, #0x34]
 *   @0x16ce2c ldr r1, [sp, #0x38]
 *   @0x16ce30 blx 0x2afe14 <png_write_info>
 *   @0x16ce34 ldr r3, [pc, #0x15c]
 *   @0x16ce38 ldr r12, [sp, #0x18]
 *   @0x16ce3c mov r2, #256
 *   @0x16ce40 ldr r0, [sp, #0x34]
 *   @0x16ce44 ldr r1, [r12, r3]
 *   @0x16ce48 blx 0x2a653c <png_set_longjmp_fn>
 *   @0x16ce4c bl 0xb6904 <setjmp@plt>
 *   @0x16ce50 cmp r0, #0
 *   @0x16ce54 beq 0x16ceb8 <_Z10WritePNG32PcPvii+0x22c>
 *   @0x16ce58 ldr r1, [pc, #0x14c]
 *   @0x16ce5c ldr r3, [pc, #0x13c]
 *   @0x16ce60 add r1, pc, r1
 *   @0x16ce64 b 0x16cd60 <_Z10WritePNG32PcPvii+0xd4>
 *   @0x16ce68 ldr r0, [sp, #0x20]
 *   @0x16ce6c b 0x16cd94 <_Z10WritePNG32PcPvii+0x108>
 *   @0x16ce70 ldr r1, [pc, #0x138]
 *   @0x16ce74 ldr r3, [pc, #0x124]
 *   @0x16ce78 add r1, pc, r1
 *   @0x16ce7c b 0x16cd60 <_Z10WritePNG32PcPvii+0xd4>
 *   @0x16ce80 ldr r1, [pc, #0x12c]
 *   @0x16ce84 ldr r3, [pc, #0x114]
 *   @0x16ce88 add r1, pc, r1
 *   @0x16ce8c b 0x16cd60 <_Z10WritePNG32PcPvii+0xd4>
 *   @0x16ce90 ldr r12, [sp, #0x18]
 *   @0x16ce94 ldr r3, [pc, #0x104]
 *   @0x16ce98 ldr r1, [pc, #0x118]
 *   @0x16ce9c ldr r3, [r12, r3]
 *   @0x16cea0 add r1, pc, r1
 *   @0x16cea4 ldr r0, [r3]
 *   @0x16cea8 ldr r3, [r0]
 *   @0x16ceac ldr r3, [r3, #0xc]
 *   @0x16ceb0 blx r3
 *   @0x16ceb4 b 0x16cd78 <_Z10WritePNG32PcPvii+0xec>
 *   @0x16ceb8 ldr r3, [sp, #0x24]
 *   @0x16cebc lsl r4, r3, #2
 *   @0x16cec0 mov r0, r4
 *   @0x16cec4 bl 0xb6544 <malloc@plt>
 *   @0x16cec8 ldr r12, [sp, #0x24]
 *   @0x16cecc cmp r12, #0
 *   @0x16ced0 str r0, [sp, #0x2c]
 *   @0x16ced4 ble 0x16cf00 <_Z10WritePNG32PcPvii+0x274>
 *   @0x16ced8 ldr r1, [sp, #0x28]
 *   @0x16cedc ldr r3, [sp, #0x2c]
 *   @0x16cee0 lsl r2, r1, #2
 *   @0x16cee4 add r0, r3, r4
 *   @0x16cee8 ldr r12, [sp, #0x1c]
 *   @0x16ceec str r12, [r3], #4
 *   @0x16cef0 cmp r3, r0
 *   @0x16cef4 add r12, r12, r2
 *   @0x16cef8 str r12, [sp, #0x1c]
 *   @0x16cefc bne 0x16cee8 <_Z10WritePNG32PcPvii+0x25c>
 *   @0x16cf00 ldr r0, [sp, #0x34]
 *   @0x16cf04 ldr r1, [sp, #0x2c]
 *   @0x16cf08 blx 0x2b0510 <png_write_image>
 *   @0x16cf0c ldr r3, [pc, #0x84]
 *   @0x16cf10 ldr r12, [sp, #0x18]
 *   @0x16cf14 mov r2, #256
 *   @0x16cf18 ldr r0, [sp, #0x34]
 *   @0x16cf1c ldr r1, [r12, r3]
 *   @0x16cf20 blx 0x2a653c <png_set_longjmp_fn>
 *   @0x16cf24 bl 0xb6904 <setjmp@plt>
 *   @0x16cf28 cmp r0, #0
 *   @0x16cf2c bne 0x16cf58 <_Z10WritePNG32PcPvii+0x2cc>
 *   @0x16cf30 ldr r0, [sp, #0x34]
 *   @0x16cf34 mov r4, #1
 *   @0x16cf38 ldr r1, [sp, #0x38]
 *   @0x16cf3c blx 0x2b002c <png_write_end>
 *   @0x16cf40 ldr r3, [sp, #0x2c]
 *   @0x16cf44 cmp r3, #0
 *   @0x16cf48 beq 0x16cd7c <_Z10WritePNG32PcPvii+0xf0>
 *   @0x16cf4c mov r0, r3
 *   @0x16cf50 bl 0xb655c <free@plt>
 *   @0x16cf54 b 0x16cd7c <_Z10WritePNG32PcPvii+0xf0>
 *   @0x16cf58 ldr r2, [sp, #0x18]
 *   @0x16cf5c mov r4, #0
 *   @0x16cf60 ldr r3, [pc, #0x38]
 *   @0x16cf64 ldr r1, [pc, #0x50]
 *   @0x16cf68 ldr r3, [r2, r3]
 *   @0x16cf6c add r1, pc, r1
 *   @0x16cf70 ldr r0, [r3]
 *   @0x16cf74 ldr r3, [r0]
 *   @0x16cf78 ldr r3, [r3, #0xc]
 *   @0x16cf7c blx r3
 *   @0x16cf80 b 0x16cf40 <_Z10WritePNG32PcPvii+0x2b4>
 *   @0x16cf84 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x16cf88 eoreq r4, r8, r12, lsr #31
 *   @0x16cf8c .word 0xffffbd00
 *   @0x16cf90 andseq r3, sp, r12, asr r6
 *   @0x16cf94 andseq sp, sp, r0, lsr r9
 *   @0x16cf98 .word 0xffffe4ac
 *   @0x16cf9c andseq sp, sp, r12, asr #18
 *   @0x16cfa0 .word 0xffffbac4
 *   @0x16cfa4 .word 0xfffff500
 *   @0x16cfa8 .word 0xfffff4f4
 *   @0x16cfac andseq sp, sp, r8, lsr r10
 *   @0x16cfb0 andseq sp, sp, r8, asr r8
 *   @0x16cfb4 ldrheq sp, [sp], -r12
 *   @0x16cfb8 ldrsbeq sp, [sp], -r8
 *   @0x16cfbc andseq sp, sp, r8, asr r9
 *
 * ══ §28/36 CPhysicsWorld::GetParticleData(IBuffer*, unsigned int, int, int)  0x23a248  size 820  205 条（0x23a248..0x23a57c）
 * @func 0x23a248 0x23a57c  size 820  205 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::GetParticleData(IBuffer*, unsigned int, int, int)+0x58 / b2World::GetParticleFlagsBuffer() / b2World::GetParticlePositionBuffer() / b2World::GetParticleVelocityBuffer() / b2World::GetParticleColorBuffer() / b2World::GetParticleUserDataBuffer()
 * 字段偏移 top8: 0x8×10 / 0x10×9 / 0x38×7 / 0x1c×3 / 0x14×3 / 0x18×3 / 0x2×3 / 0x4×2
 * VFP 指令 38 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23a248 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x23a24c vpush {d8}
 *   @0x23a250 mov r11, r0
 *   @0x23a254 ldr r0, [r0, #0x10]
 *   @0x23a258 movw r12, #0x9298
 *   @0x23a25c movt r12, #0x1
 *   @0x23a260 mov r4, r1
 *   @0x23a264 sub sp, sp, #44
 *   @0x23a268 ldr r1, [r0, r12]
 *   @0x23a26c ldr r7, [sp, #0x58]
 *   @0x23a270 cmp r3, r1
 *   @0x23a274 movlt r5, #0
 *   @0x23a278 movge r5, #1
 *   @0x23a27c orrs r5, r5, r3, lsr #31
 *   @0x23a280 bne 0x23a294 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x4c>
 *   @0x23a284 cmp r3, r7
 *   @0x23a288 bgt 0x23a294 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x4c>
 *   @0x23a28c cmp r7, r1
 *   @0x23a290 ble 0x23a2a0 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x58>
 *   @0x23a294 add sp, sp, #44
 *   @0x23a298 vpop {d8}
 *   @0x23a29c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23a2a0 str r2, [sp, #0x4]
 *   @0x23a2a4 vmov.f32 s16, #1.000000e+00
 *   @0x23a2a8 str r3, [sp]
 *   @0x23a2ac bl 0x2cb568 <_ZN7b2World22GetParticleFlagsBufferEv>
 *   @0x23a2b0 mov r10, r0
 *   @0x23a2b4 ldr r0, [r11, #0x10]
 *   @0x23a2b8 bl 0x2cb574 <_ZN7b2World25GetParticlePositionBufferEv>
 *   @0x23a2bc mov r8, r0
 *   @0x23a2c0 ldr r0, [r11, #0x10]
 *   @0x23a2c4 bl 0x2cb580 <_ZN7b2World25GetParticleVelocityBufferEv>
 *   @0x23a2c8 mov r9, r0
 *   @0x23a2cc ldr r0, [r11, #0x10]
 *   @0x23a2d0 bl 0x2cb58c <_ZN7b2World22GetParticleColorBufferEv>
 *   @0x23a2d4 mov r6, r0
 *   @0x23a2d8 ldr r0, [r11, #0x10]
 *   @0x23a2dc bl 0x2cb598 <_ZN7b2World25GetParticleUserDataBufferEv>
 *   @0x23a2e0 ldr r3, [sp]
 *   @0x23a2e4 ldr r1, [r4, #0x1c]
 *   @0x23a2e8 vldr s15, [r11, #96]
 *   @0x23a2ec cmp r3, r7
 *   @0x23a2f0 vdiv.f32 s16, s16, s15
 *   @0x23a2f4 ldr r2, [sp, #0x4]
 *   @0x23a2f8 str r1, [sp, #0x24]
 *   @0x23a2fc bge 0x23a558 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x310>
 *   @0x23a300 lsl r1, r3, #2
 *   @0x23a304 lsl r12, r3, #3
 *   @0x23a308 add r10, r10, r1
 *   @0x23a30c rsb r7, r3, r7
 *   @0x23a310 str r10, [sp, #0x20]
 *   @0x23a314 and r3, r2, #1
 *   @0x23a318 add r0, r0, r1
 *   @0x23a31c str r3, [sp, #0xc]
 *   @0x23a320 add r6, r6, r1
 *   @0x23a324 and r3, r2, #2
 *   @0x23a328 str r0, [sp, #0x1c]
 *   @0x23a32c add r9, r9, r12
 *   @0x23a330 str r3, [sp, #0x10]
 *   @0x23a334 add r8, r8, r12
 *   @0x23a338 and r3, r2, #4
 *   @0x23a33c add r11, r4, #44
 *   @0x23a340 str r3, [sp, #0x14]
 *   @0x23a344 mov r10, r5
 *   @0x23a348 and r3, r2, #8
 *   @0x23a34c and r2, r2, #16
 *   @0x23a350 str r3, [sp, #0x8]
 *   @0x23a354 str r2, [sp, #0x18]
 *   @0x23a358 b 0x23a3a4 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x15c>
 *   @0x23a35c ldr r3, [sp, #0x10]
 *   @0x23a360 cmp r3, #0
 *   @0x23a364 bne 0x23a3f0 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x1a8>
 *   @0x23a368 ldr r3, [sp, #0x14]
 *   @0x23a36c cmp r3, #0
 *   @0x23a370 bne 0x23a45c <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x214>
 *   @0x23a374 ldr r3, [sp, #0x8]
 *   @0x23a378 cmp r3, #0
 *   @0x23a37c bne 0x23a4c8 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x280>
 *   @0x23a380 ldr r3, [sp, #0x18]
 *   @0x23a384 cmp r3, #0
 *   @0x23a388 bne 0x23a520 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x2d8>
 *   @0x23a38c add r5, r5, #1
 *   @0x23a390 add r6, r6, #4
 *   @0x23a394 cmp r5, r7
 *   @0x23a398 add r9, r9, #8
 *   @0x23a39c add r8, r8, #8
 *   @0x23a3a0 beq 0x23a558 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x310>
 *   @0x23a3a4 ldr r3, [sp, #0xc]
 *   @0x23a3a8 cmp r3, #0
 *   @0x23a3ac beq 0x23a35c <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x114>
 *   @0x23a3b0 ldr r1, [sp, #0x20]
 *   @0x23a3b4 mov r0, r4
 *   @0x23a3b8 ldr lr, [r4]
 *   @0x23a3bc mov r2, r11
 *   @0x23a3c0 ldr r1, [r1, r5, lsl #2]
 *   @0x23a3c4 str r10, [r4, #0x38]
 *   @0x23a3c8 vmov s14, r1
 *   @0x23a3cc mov r1, #5
 *   @0x23a3d0 vcvt.f64.u32 d7, s14
 *   @0x23a3d4 vstr s14, [r4, #44]
 *   @0x23a3d8 vstr s15, [r4, #48]
 *   @0x23a3dc ldr r3, [lr, #0x8]
 *   @0x23a3e0 blx r3
 *   @0x23a3e4 ldr r3, [sp, #0x10]
 *   @0x23a3e8 cmp r3, #0
 *   @0x23a3ec beq 0x23a368 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x120>
 *   @0x23a3f0 vldr s14, [r8]
 *   @0x23a3f4 vmul.f32 s14, s16, s14
 *   @0x23a3f8 ldr lr, [r4]
 *   @0x23a3fc mov r1, #8
 *   @0x23a400 mov r2, r11
 *   @0x23a404 mov r0, r4
 *   @0x23a408 str r10, [r4, #0x38]
 *   @0x23a40c vcvt.f64.f32 d7, s14
 *   @0x23a410 vstr s14, [r4, #44]
 *   @0x23a414 vstr s15, [r4, #48]
 *   @0x23a418 ldr r3, [lr, #0x8]
 *   @0x23a41c blx r3
 *   @0x23a420 vldr s14, [r8, #4]
 *   @0x23a424 vmul.f32 s14, s16, s14
 *   @0x23a428 ldr lr, [r4]
 *   @0x23a42c str r10, [r4, #0x38]
 *   @0x23a430 mov r0, r4
 *   @0x23a434 mov r1, #8
 *   @0x23a438 mov r2, r11
 *   @0x23a43c vcvt.f64.f32 d7, s14
 *   @0x23a440 vstr s14, [r4, #44]
 *   @0x23a444 vstr s15, [r4, #48]
 *   @0x23a448 ldr r3, [lr, #0x8]
 *   @0x23a44c blx r3
 *   @0x23a450 ldr r3, [sp, #0x14]
 *   @0x23a454 cmp r3, #0
 *   @0x23a458 beq 0x23a374 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x12c>
 *   @0x23a45c vldr s14, [r9]
 *   @0x23a460 vmul.f32 s14, s16, s14
 *   @0x23a464 ldr lr, [r4]
 *   @0x23a468 mov r1, #8
 *   @0x23a46c mov r2, r11
 *   @0x23a470 mov r0, r4
 *   @0x23a474 str r10, [r4, #0x38]
 *   @0x23a478 vcvt.f64.f32 d7, s14
 *   @0x23a47c vstr s14, [r4, #44]
 *   @0x23a480 vstr s15, [r4, #48]
 *   @0x23a484 ldr r3, [lr, #0x8]
 *   @0x23a488 blx r3
 *   @0x23a48c vldr s14, [r9, #4]
 *   @0x23a490 vmul.f32 s14, s16, s14
 *   @0x23a494 ldr lr, [r4]
 *   @0x23a498 str r10, [r4, #0x38]
 *   @0x23a49c mov r0, r4
 *   @0x23a4a0 mov r1, #8
 *   @0x23a4a4 mov r2, r11
 *   @0x23a4a8 vcvt.f64.f32 d7, s14
 *   @0x23a4ac vstr s14, [r4, #44]
 *   @0x23a4b0 vstr s15, [r4, #48]
 *   @0x23a4b4 ldr r3, [lr, #0x8]
 *   @0x23a4b8 blx r3
 *   @0x23a4bc ldr r3, [sp, #0x8]
 *   @0x23a4c0 cmp r3, #0
 *   @0x23a4c4 beq 0x23a380 <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x138>
 *   @0x23a4c8 ldrb r12, [r6]
 *   @0x23a4cc mov r0, r4
 *   @0x23a4d0 ldrb lr, [r6, #0x3]
 *   @0x23a4d4 mov r1, #5
 *   @0x23a4d8 ldrb r2, [r6, #0x2]
 *   @0x23a4dc ldrb r3, [r6, #0x1]
 *   @0x23a4e0 lsl r12, r12, #16
 *   @0x23a4e4 orr r12, r12, lr, lsl #24
 *   @0x23a4e8 ldr lr, [r4]
 *   @0x23a4ec orr r12, r12, r2
 *   @0x23a4f0 str r10, [r4, #0x38]
 *   @0x23a4f4 orr r12, r12, r3, lsl #8
 *   @0x23a4f8 mov r2, r11
 *   @0x23a4fc vmov s13, r12
 *   @0x23a500 vcvt.f64.u32 d7, s13
 *   @0x23a504 vstr s14, [r4, #44]
 *   @0x23a508 vstr s15, [r4, #48]
 *   @0x23a50c ldr r3, [lr, #0x8]
 *   @0x23a510 blx r3
 *   @0x23a514 ldr r3, [sp, #0x18]
 *   @0x23a518 cmp r3, #0
 *   @0x23a51c beq 0x23a38c <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x144>
 *   @0x23a520 ldr r1, [sp, #0x1c]
 *   @0x23a524 mov r0, r4
 *   @0x23a528 ldr lr, [r4]
 *   @0x23a52c mov r2, r11
 *   @0x23a530 ldr r1, [r1, r5, lsl #2]
 *   @0x23a534 str r10, [r4, #0x38]
 *   @0x23a538 vmov s14, r1
 *   @0x23a53c mov r1, #6
 *   @0x23a540 vcvt.f64.s32 d7, s14
 *   @0x23a544 vstr s14, [r4, #44]
 *   @0x23a548 vstr s15, [r4, #48]
 *   @0x23a54c ldr r3, [lr, #0x8]
 *   @0x23a550 blx r3
 *   @0x23a554 b 0x23a38c <_ZN13CPhysicsWorld15GetParticleDataEP7IBufferjii+0x144>
 *   @0x23a558 ldr r3, [r4]
 *   @0x23a55c mov r0, r4
 *   @0x23a560 ldr r2, [sp, #0x24]
 *   @0x23a564 mov r1, #0
 *   @0x23a568 ldr r3, [r3, #0x10]
 *   @0x23a56c blx r3
 *   @0x23a570 add sp, sp, #44
 *   @0x23a574 vpop {d8}
 *   @0x23a578 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §29/36 CDS_Priority::DeleteMin(RValue*)  0x20a99c  size 816  204 条（0x20a99c..0x20accc）
 * @func 0x20a99c 0x20accc  size 816  204 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×3 / LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / 0xb6694×2 / YYFree(void const*)×2 / operator delete(void*)×2 / CDS_Priority::DeleteMin(RValue*)+0x2fc / YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0xc×17 / 0x4×11 / 0x8×8 / 0x14×4 / 0x2f4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20a99c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x20a9a0 mov r7, #0
 *   @0x20a9a4 str r7, [r1]
 *   @0x20a9a8 mov r9, r1
 *   @0x20a9ac str r7, [r1, #0x4]
 *   @0x20a9b0 mov r6, r0
 *   @0x20a9b4 ldr r3, [r0, #0x4]
 *   @0x20a9b8 str r7, [r1, #0xc]
 *   @0x20a9bc cmp r3, r7
 *   @0x20a9c0 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x20a9c4 cmp r3, #1
 *   @0x20a9c8 ble 0x20ac98 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x2fc>
 *   @0x20a9cc ldr r10, [pc, #0x2f4]
 *   @0x20a9d0 mov r4, #1
 *   @0x20a9d4 ldr r10, [pc, r10]
 *   @0x20a9d8 ldr r1, [r6, #0x14]
 *   @0x20a9dc lsl r8, r4, #4
 *   @0x20a9e0 lsl r5, r7, #4
 *   @0x20a9e4 ldrd r2, r3, [r10]
 *   @0x20a9e8 add r0, r1, r8
 *   @0x20a9ec add r1, r1, r5
 *   @0x20a9f0 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x20a9f4 ldr r3, [r6, #0x4]
 *   @0x20a9f8 cmp r0, #0
 *   @0x20a9fc movlt r7, r4
 *   @0x20aa00 add r4, r4, #1
 *   @0x20aa04 movlt r5, r8
 *   @0x20aa08 cmp r3, r4
 *   @0x20aa0c bgt 0x20a9d8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x3c>
 *   @0x20aa10 ldr r2, [r9, #0xc]
 *   @0x20aa14 ldr r4, [r6, #0xc]
 *   @0x20aa18 bic r3, r2, #-16777216
 *   @0x20aa1c cmp r3, #1
 *   @0x20aa20 add r4, r4, r5
 *   @0x20aa24 beq 0x20aabc <_ZN12CDS_Priority9DeleteMinEP6RValue+0x120>
 *   @0x20aa28 cmp r3, #2
 *   @0x20aa2c bne 0x20aa54 <_ZN12CDS_Priority9DeleteMinEP6RValue+0xb8>
 *   @0x20aa30 sub r3, r2, #1
 *   @0x20aa34 bic r3, r3, #-16777216
 *   @0x20aa38 bic r3, r3, #3
 *   @0x20aa3c cmp r3, #0
 *   @0x20aa40 beq 0x20ac3c <_ZN12CDS_Priority9DeleteMinEP6RValue+0x2a0>
 *   @0x20aa44 mov r2, #0
 *   @0x20aa48 mov r3, #5
 *   @0x20aa4c str r2, [r9, #0x8]
 *   @0x20aa50 str r3, [r9, #0xc]
 *   @0x20aa54 ldr r3, [r4, #0xc]
 *   @0x20aa58 mov r1, #0
 *   @0x20aa5c ldr r2, [r4, #0x8]
 *   @0x20aa60 str r1, [r9]
 *   @0x20aa64 str r3, [r9, #0xc]
 *   @0x20aa68 ldr r3, [r4, #0xc]
 *   @0x20aa6c str r2, [r9, #0x8]
 *   @0x20aa70 bic r3, r3, #-16777216
 *   @0x20aa74 cmp r3, #14
 *   @0x20aa78 addls pc, pc, r3, lsl #2
 *   @0x20aa7c b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c>
 *   @0x20aa80 b 0x20abc8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x22c>
 *   @0x20aa84 b 0x20ac00 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x264>
 *   @0x20aa88 b 0x20abd4 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x238>
 *   @0x20aa8c b 0x20aaf0 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x154>
 *   @0x20aa90 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c>
 *   @0x20aa94 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c>
 *   @0x20aa98 b 0x20ac18 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x27c>
 *   @0x20aa9c b 0x20aaf0 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x154>
 *   @0x20aaa0 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c>
 *   @0x20aaa4 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c>
 *   @0x20aaa8 b 0x20abc8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x22c>
 *   @0x20aaac b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c>
 *   @0x20aab0 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c>
 *   @0x20aab4 b 0x20abc8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x22c>
 *   @0x20aab8 b 0x20aaf0 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x154>
 *   @0x20aabc ldr r7, [r9]
 *   @0x20aac0 cmp r7, #0
 *   @0x20aac4 beq 0x20aae4 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x148>
 *   @0x20aac8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20aacc ldr r8, [r7, #0x4]
 *   @0x20aad0 sub r8, r8, #1
 *   @0x20aad4 str r8, [r7, #0x4]
 *   @0x20aad8 cmp r8, #0
 *   @0x20aadc beq 0x20ac60 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x2c4>
 *   @0x20aae0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20aae4 mov r3, #0
 *   @0x20aae8 str r3, [r9]
 *   @0x20aaec b 0x20aa54 <_ZN12CDS_Priority9DeleteMinEP6RValue+0xb8>
 *   @0x20aaf0 ldr r3, [r4]
 *   @0x20aaf4 str r3, [r9]
 *   @0x20aaf8 ldr r7, [r6, #0xc]
 *   @0x20aafc add r7, r7, r5
 *   @0x20ab00 ldr r3, [r7, #0xc]
 *   @0x20ab04 sub r3, r3, #1
 *   @0x20ab08 bic r3, r3, #-16777216
 *   @0x20ab0c bic r3, r3, #3
 *   @0x20ab10 cmp r3, #0
 *   @0x20ab14 beq 0x20ac54 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x2b8>
 *   @0x20ab18 mov r3, #0
 *   @0x20ab1c str r3, [r7]
 *   @0x20ab20 ldr r4, [r6, #0x14]
 *   @0x20ab24 mov r2, #5
 *   @0x20ab28 str r3, [r7, #0x8]
 *   @0x20ab2c add r4, r4, r5
 *   @0x20ab30 str r2, [r7, #0xc]
 *   @0x20ab34 ldr r3, [r4, #0xc]
 *   @0x20ab38 sub r3, r3, #1
 *   @0x20ab3c bic r3, r3, #-16777216
 *   @0x20ab40 bic r3, r3, #3
 *   @0x20ab44 cmp r3, #0
 *   @0x20ab48 beq 0x20ac48 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x2ac>
 *   @0x20ab4c mov r7, #0
 *   @0x20ab50 str r7, [r4]
 *   @0x20ab54 ldr r1, [r6, #0x4]
 *   @0x20ab58 mov r12, #5
 *   @0x20ab5c ldr r3, [r6, #0xc]
 *   @0x20ab60 mov r2, #16
 *   @0x20ab64 sub r1, r1, #-268435455
 *   @0x20ab68 str r12, [r4, #0xc]
 *   @0x20ab6c add r0, r3, r5
 *   @0x20ab70 str r7, [r4, #0x8]
 *   @0x20ab74 add r1, r3, r1, lsl #4
 *   @0x20ab78 bl 0xb6694 <memmove@plt>
 *   @0x20ab7c ldr r3, [r6, #0x4]
 *   @0x20ab80 ldr r12, [r6, #0xc]
 *   @0x20ab84 mov r2, #16
 *   @0x20ab88 sub r3, r3, #-268435455
 *   @0x20ab8c ldr r1, [r6, #0x14]
 *   @0x20ab90 lsl r3, r3, #4
 *   @0x20ab94 add r0, r1, r5
 *   @0x20ab98 add r12, r12, r3
 *   @0x20ab9c add r1, r1, r3
 *   @0x20aba0 str r7, [r12, #0xc]
 *   @0x20aba4 bl 0xb6694 <memmove@plt>
 *   @0x20aba8 ldr r3, [r6, #0x4]
 *   @0x20abac ldr r2, [r6, #0x14]
 *   @0x20abb0 sub r1, r3, #-268435455
 *   @0x20abb4 sub r3, r3, #1
 *   @0x20abb8 add r2, r2, r1, lsl #4
 *   @0x20abbc str r7, [r2, #0xc]
 *   @0x20abc0 str r3, [r6, #0x4]
 *   @0x20abc4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x20abc8 ldm r4, {r2, r3}
 *   @0x20abcc stm r9, {r2, r3}
 *   @0x20abd0 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c>
 *   @0x20abd4 ldr r3, [r4]
 *   @0x20abd8 cmp r3, #0
 *   @0x20abdc str r3, [r9]
 *   @0x20abe0 beq 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c>
 *   @0x20abe4 ldr r1, [r3, #0x8]
 *   @0x20abe8 ldr r2, [r3]
 *   @0x20abec cmp r1, #0
 *   @0x20abf0 streq r9, [r3, #0x8]
 *   @0x20abf4 add r2, r2, #1
 *   @0x20abf8 str r2, [r3]
 *   @0x20abfc b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c>
 *   @0x20ac00 ldr r3, [r4]
 *   @0x20ac04 cmp r3, #0
 *   @0x20ac08 ldrne r2, [r3, #0x4]
 *   @0x20ac0c addne r2, r2, #1
 *   @0x20ac10 strne r2, [r3, #0x4]
 *   @0x20ac14 b 0x20aaf4 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x158>
 *   @0x20ac18 ldr r3, [r4]
 *   @0x20ac1c str r3, [r9]
 *   @0x20ac20 ldr r3, [r4]
 *   @0x20ac24 cmp r3, #0
 *   @0x20ac28 beq 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c>
 *   @0x20ac2c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20ac30 ldr r1, [r4]
 *   @0x20ac34 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20ac38 b 0x20aaf8 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x15c>
 *   @0x20ac3c mov r0, r9
 *   @0x20ac40 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20ac44 b 0x20aa44 <_ZN12CDS_Priority9DeleteMinEP6RValue+0xa8>
 *   @0x20ac48 mov r0, r4
 *   @0x20ac4c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20ac50 b 0x20ab4c <_ZN12CDS_Priority9DeleteMinEP6RValue+0x1b0>
 *   @0x20ac54 mov r0, r7
 *   @0x20ac58 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20ac5c b 0x20ab18 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x17c>
 *   @0x20ac60 ldr r0, [r7]
 *   @0x20ac64 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20ac68 str r8, [r7]
 *   @0x20ac6c str r8, [r7, #0x8]
 *   @0x20ac70 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20ac74 ldr r8, [r7, #0x4]
 *   @0x20ac78 sub r8, r8, #1
 *   @0x20ac7c str r8, [r7, #0x4]
 *   @0x20ac80 cmp r8, #0
 *   @0x20ac84 beq 0x20aca4 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x308>
 *   @0x20ac88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20ac8c mov r0, r7
 *   @0x20ac90 bl 0x27d1d0 <_ZdlPv>
 *   @0x20ac94 b 0x20aae0 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x144>
 *   @0x20ac98 mov r5, r7
 *   @0x20ac9c ldr r4, [r0, #0xc]
 *   @0x20aca0 b 0x20aa54 <_ZN12CDS_Priority9DeleteMinEP6RValue+0xb8>
 *   @0x20aca4 ldr r0, [r7]
 *   @0x20aca8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20acac mov r0, r7
 *   @0x20acb0 str r8, [r7]
 *   @0x20acb4 str r8, [r7, #0x8]
 *   @0x20acb8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20acbc mov r0, r7
 *   @0x20acc0 bl 0x27d1d0 <_ZdlPv>
 *   @0x20acc4 b 0x20ac88 <_ZN12CDS_Priority9DeleteMinEP6RValue+0x2ec>
 *   @0x20acc8 ldrheq r6, [lr], -r0
 *
 * ══ §30/36 CDS_Priority::DeleteMax(RValue*)  0x20accc  size 816  204 条（0x20accc..0x20affc）
 * @func 0x20accc 0x20affc  size 816  204 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×3 / LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / 0xb6694×2 / YYFree(void const*)×2 / operator delete(void*)×2 / CDS_Priority::DeleteMax(RValue*)+0x2fc / YYCompareVal(RValue const&, RValue const&, double)
 * 字段偏移 top8: 0xc×17 / 0x4×11 / 0x8×8 / 0x14×4 / 0x2f4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20accc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x20acd0 mov r7, #0
 *   @0x20acd4 str r7, [r1]
 *   @0x20acd8 mov r9, r1
 *   @0x20acdc str r7, [r1, #0x4]
 *   @0x20ace0 mov r6, r0
 *   @0x20ace4 ldr r3, [r0, #0x4]
 *   @0x20ace8 str r7, [r1, #0xc]
 *   @0x20acec cmp r3, r7
 *   @0x20acf0 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x20acf4 cmp r3, #1
 *   @0x20acf8 ble 0x20afc8 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x2fc>
 *   @0x20acfc ldr r10, [pc, #0x2f4]
 *   @0x20ad00 mov r4, #1
 *   @0x20ad04 ldr r10, [pc, r10]
 *   @0x20ad08 ldr r1, [r6, #0x14]
 *   @0x20ad0c lsl r5, r4, #4
 *   @0x20ad10 lsl r8, r7, #4
 *   @0x20ad14 ldrd r2, r3, [r10]
 *   @0x20ad18 add r0, r1, r5
 *   @0x20ad1c add r1, r1, r8
 *   @0x20ad20 bl 0x2026c4 <_Z12YYCompareValRK6RValueS1_d>
 *   @0x20ad24 ldr r3, [r6, #0x4]
 *   @0x20ad28 cmp r0, #0
 *   @0x20ad2c movgt r7, r4
 *   @0x20ad30 add r4, r4, #1
 *   @0x20ad34 movle r5, r8
 *   @0x20ad38 cmp r3, r4
 *   @0x20ad3c bgt 0x20ad08 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x3c>
 *   @0x20ad40 ldr r2, [r9, #0xc]
 *   @0x20ad44 ldr r4, [r6, #0xc]
 *   @0x20ad48 bic r3, r2, #-16777216
 *   @0x20ad4c cmp r3, #1
 *   @0x20ad50 add r4, r4, r5
 *   @0x20ad54 beq 0x20adec <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x120>
 *   @0x20ad58 cmp r3, #2
 *   @0x20ad5c bne 0x20ad84 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0xb8>
 *   @0x20ad60 sub r3, r2, #1
 *   @0x20ad64 bic r3, r3, #-16777216
 *   @0x20ad68 bic r3, r3, #3
 *   @0x20ad6c cmp r3, #0
 *   @0x20ad70 beq 0x20af6c <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x2a0>
 *   @0x20ad74 mov r2, #0
 *   @0x20ad78 mov r3, #5
 *   @0x20ad7c str r2, [r9, #0x8]
 *   @0x20ad80 str r3, [r9, #0xc]
 *   @0x20ad84 ldr r3, [r4, #0xc]
 *   @0x20ad88 mov r1, #0
 *   @0x20ad8c ldr r2, [r4, #0x8]
 *   @0x20ad90 str r1, [r9]
 *   @0x20ad94 str r3, [r9, #0xc]
 *   @0x20ad98 ldr r3, [r4, #0xc]
 *   @0x20ad9c str r2, [r9, #0x8]
 *   @0x20ada0 bic r3, r3, #-16777216
 *   @0x20ada4 cmp r3, #14
 *   @0x20ada8 addls pc, pc, r3, lsl #2
 *   @0x20adac b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c>
 *   @0x20adb0 b 0x20aef8 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x22c>
 *   @0x20adb4 b 0x20af30 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x264>
 *   @0x20adb8 b 0x20af04 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x238>
 *   @0x20adbc b 0x20ae20 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x154>
 *   @0x20adc0 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c>
 *   @0x20adc4 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c>
 *   @0x20adc8 b 0x20af48 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x27c>
 *   @0x20adcc b 0x20ae20 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x154>
 *   @0x20add0 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c>
 *   @0x20add4 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c>
 *   @0x20add8 b 0x20aef8 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x22c>
 *   @0x20addc b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c>
 *   @0x20ade0 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c>
 *   @0x20ade4 b 0x20aef8 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x22c>
 *   @0x20ade8 b 0x20ae20 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x154>
 *   @0x20adec ldr r7, [r9]
 *   @0x20adf0 cmp r7, #0
 *   @0x20adf4 beq 0x20ae14 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x148>
 *   @0x20adf8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20adfc ldr r8, [r7, #0x4]
 *   @0x20ae00 sub r8, r8, #1
 *   @0x20ae04 str r8, [r7, #0x4]
 *   @0x20ae08 cmp r8, #0
 *   @0x20ae0c beq 0x20af90 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x2c4>
 *   @0x20ae10 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20ae14 mov r3, #0
 *   @0x20ae18 str r3, [r9]
 *   @0x20ae1c b 0x20ad84 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0xb8>
 *   @0x20ae20 ldr r3, [r4]
 *   @0x20ae24 str r3, [r9]
 *   @0x20ae28 ldr r7, [r6, #0xc]
 *   @0x20ae2c add r7, r7, r5
 *   @0x20ae30 ldr r3, [r7, #0xc]
 *   @0x20ae34 sub r3, r3, #1
 *   @0x20ae38 bic r3, r3, #-16777216
 *   @0x20ae3c bic r3, r3, #3
 *   @0x20ae40 cmp r3, #0
 *   @0x20ae44 beq 0x20af84 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x2b8>
 *   @0x20ae48 mov r3, #0
 *   @0x20ae4c str r3, [r7]
 *   @0x20ae50 ldr r4, [r6, #0x14]
 *   @0x20ae54 mov r2, #5
 *   @0x20ae58 str r3, [r7, #0x8]
 *   @0x20ae5c add r4, r4, r5
 *   @0x20ae60 str r2, [r7, #0xc]
 *   @0x20ae64 ldr r3, [r4, #0xc]
 *   @0x20ae68 sub r3, r3, #1
 *   @0x20ae6c bic r3, r3, #-16777216
 *   @0x20ae70 bic r3, r3, #3
 *   @0x20ae74 cmp r3, #0
 *   @0x20ae78 beq 0x20af78 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x2ac>
 *   @0x20ae7c mov r7, #0
 *   @0x20ae80 str r7, [r4]
 *   @0x20ae84 ldr r1, [r6, #0x4]
 *   @0x20ae88 mov r12, #5
 *   @0x20ae8c ldr r3, [r6, #0xc]
 *   @0x20ae90 mov r2, #16
 *   @0x20ae94 sub r1, r1, #-268435455
 *   @0x20ae98 str r12, [r4, #0xc]
 *   @0x20ae9c add r0, r3, r5
 *   @0x20aea0 str r7, [r4, #0x8]
 *   @0x20aea4 add r1, r3, r1, lsl #4
 *   @0x20aea8 bl 0xb6694 <memmove@plt>
 *   @0x20aeac ldr r3, [r6, #0x4]
 *   @0x20aeb0 ldr r12, [r6, #0xc]
 *   @0x20aeb4 mov r2, #16
 *   @0x20aeb8 sub r3, r3, #-268435455
 *   @0x20aebc ldr r1, [r6, #0x14]
 *   @0x20aec0 lsl r3, r3, #4
 *   @0x20aec4 add r0, r1, r5
 *   @0x20aec8 add r12, r12, r3
 *   @0x20aecc add r1, r1, r3
 *   @0x20aed0 str r7, [r12, #0xc]
 *   @0x20aed4 bl 0xb6694 <memmove@plt>
 *   @0x20aed8 ldr r3, [r6, #0x4]
 *   @0x20aedc ldr r2, [r6, #0x14]
 *   @0x20aee0 sub r1, r3, #-268435455
 *   @0x20aee4 sub r3, r3, #1
 *   @0x20aee8 add r2, r2, r1, lsl #4
 *   @0x20aeec str r7, [r2, #0xc]
 *   @0x20aef0 str r3, [r6, #0x4]
 *   @0x20aef4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x20aef8 ldm r4, {r2, r3}
 *   @0x20aefc stm r9, {r2, r3}
 *   @0x20af00 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c>
 *   @0x20af04 ldr r3, [r4]
 *   @0x20af08 cmp r3, #0
 *   @0x20af0c str r3, [r9]
 *   @0x20af10 beq 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c>
 *   @0x20af14 ldr r1, [r3, #0x8]
 *   @0x20af18 ldr r2, [r3]
 *   @0x20af1c cmp r1, #0
 *   @0x20af20 streq r9, [r3, #0x8]
 *   @0x20af24 add r2, r2, #1
 *   @0x20af28 str r2, [r3]
 *   @0x20af2c b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c>
 *   @0x20af30 ldr r3, [r4]
 *   @0x20af34 cmp r3, #0
 *   @0x20af38 ldrne r2, [r3, #0x4]
 *   @0x20af3c addne r2, r2, #1
 *   @0x20af40 strne r2, [r3, #0x4]
 *   @0x20af44 b 0x20ae24 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x158>
 *   @0x20af48 ldr r3, [r4]
 *   @0x20af4c str r3, [r9]
 *   @0x20af50 ldr r3, [r4]
 *   @0x20af54 cmp r3, #0
 *   @0x20af58 beq 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c>
 *   @0x20af5c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20af60 ldr r1, [r4]
 *   @0x20af64 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20af68 b 0x20ae28 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x15c>
 *   @0x20af6c mov r0, r9
 *   @0x20af70 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20af74 b 0x20ad74 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0xa8>
 *   @0x20af78 mov r0, r4
 *   @0x20af7c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20af80 b 0x20ae7c <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x1b0>
 *   @0x20af84 mov r0, r7
 *   @0x20af88 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20af8c b 0x20ae48 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x17c>
 *   @0x20af90 ldr r0, [r7]
 *   @0x20af94 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20af98 str r8, [r7]
 *   @0x20af9c str r8, [r7, #0x8]
 *   @0x20afa0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20afa4 ldr r8, [r7, #0x4]
 *   @0x20afa8 sub r8, r8, #1
 *   @0x20afac str r8, [r7, #0x4]
 *   @0x20afb0 cmp r8, #0
 *   @0x20afb4 beq 0x20afd4 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x308>
 *   @0x20afb8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20afbc mov r0, r7
 *   @0x20afc0 bl 0x27d1d0 <_ZdlPv>
 *   @0x20afc4 b 0x20ae10 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x144>
 *   @0x20afc8 mov r5, r7
 *   @0x20afcc ldr r4, [r0, #0xc]
 *   @0x20afd0 b 0x20ad84 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0xb8>
 *   @0x20afd4 ldr r0, [r7]
 *   @0x20afd8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20afdc mov r0, r7
 *   @0x20afe0 str r8, [r7]
 *   @0x20afe4 str r8, [r7, #0x8]
 *   @0x20afe8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20afec mov r0, r7
 *   @0x20aff0 bl 0x27d1d0 <_ZdlPv>
 *   @0x20aff4 b 0x20afb8 <_ZN12CDS_Priority9DeleteMaxEP6RValue+0x2ec>
 *   @0x20aff8 andseq r6, lr, r0, lsl #13
 *
 * ══ §31/36 AddGestureFunctions()  0x1dbb30  size 812  203 条（0x1dbb30..0x1dbe5c）
 * @func 0x1dbb30 0x1dbe5c  size 812  203 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Function_Add(char const*, void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×21
 * 字段偏移 top8: 0x254×2 / 0x240×2 / 0x22c×2 / 0x218×2 / 0x204×2 / 0x1f0×2 / 0x1dc×2 / 0x1c8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1dbb30 push {r4, lr}
 *   @0x1dbb34 mov r2, #1
 *   @0x1dbb38 ldr r4, [pc, #0x268]
 *   @0x1dbb3c mov r3, #0
 *   @0x1dbb40 ldr r1, [pc, #0x264]
 *   @0x1dbb44 add r4, pc, r4
 *   @0x1dbb48 ldr r0, [pc, #0x260]
 *   @0x1dbb4c ldr r1, [r4, r1]
 *   @0x1dbb50 add r0, pc, r0
 *   @0x1dbb54 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbb58 ldr r1, [pc, #0x254]
 *   @0x1dbb5c ldr r0, [pc, #0x254]
 *   @0x1dbb60 mov r2, #1
 *   @0x1dbb64 mov r3, #0
 *   @0x1dbb68 ldr r1, [r4, r1]
 *   @0x1dbb6c add r0, pc, r0
 *   @0x1dbb70 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbb74 ldr r1, [pc, #0x240]
 *   @0x1dbb78 ldr r0, [pc, #0x240]
 *   @0x1dbb7c mov r2, #1
 *   @0x1dbb80 mov r3, #0
 *   @0x1dbb84 ldr r1, [r4, r1]
 *   @0x1dbb88 add r0, pc, r0
 *   @0x1dbb8c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbb90 ldr r1, [pc, #0x22c]
 *   @0x1dbb94 ldr r0, [pc, #0x22c]
 *   @0x1dbb98 mov r2, #1
 *   @0x1dbb9c mov r3, #0
 *   @0x1dbba0 ldr r1, [r4, r1]
 *   @0x1dbba4 add r0, pc, r0
 *   @0x1dbba8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbbac ldr r1, [pc, #0x218]
 *   @0x1dbbb0 ldr r0, [pc, #0x218]
 *   @0x1dbbb4 mov r2, #1
 *   @0x1dbbb8 mov r3, #0
 *   @0x1dbbbc ldr r1, [r4, r1]
 *   @0x1dbbc0 add r0, pc, r0
 *   @0x1dbbc4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbbc8 ldr r1, [pc, #0x204]
 *   @0x1dbbcc ldr r0, [pc, #0x204]
 *   @0x1dbbd0 mov r2, #1
 *   @0x1dbbd4 mov r3, #0
 *   @0x1dbbd8 ldr r1, [r4, r1]
 *   @0x1dbbdc add r0, pc, r0
 *   @0x1dbbe0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbbe4 ldr r1, [pc, #0x1f0]
 *   @0x1dbbe8 ldr r0, [pc, #0x1f0]
 *   @0x1dbbec mov r2, #1
 *   @0x1dbbf0 mov r3, #0
 *   @0x1dbbf4 ldr r1, [r4, r1]
 *   @0x1dbbf8 add r0, pc, r0
 *   @0x1dbbfc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbc00 ldr r1, [pc, #0x1dc]
 *   @0x1dbc04 ldr r0, [pc, #0x1dc]
 *   @0x1dbc08 mov r2, #1
 *   @0x1dbc0c mov r3, #0
 *   @0x1dbc10 ldr r1, [r4, r1]
 *   @0x1dbc14 add r0, pc, r0
 *   @0x1dbc18 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbc1c ldr r1, [pc, #0x1c8]
 *   @0x1dbc20 ldr r0, [pc, #0x1c8]
 *   @0x1dbc24 mov r2, #1
 *   @0x1dbc28 mov r3, #0
 *   @0x1dbc2c ldr r1, [r4, r1]
 *   @0x1dbc30 add r0, pc, r0
 *   @0x1dbc34 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbc38 ldr r1, [pc, #0x1b4]
 *   @0x1dbc3c ldr r0, [pc, #0x1b4]
 *   @0x1dbc40 mov r2, #1
 *   @0x1dbc44 mov r3, #0
 *   @0x1dbc48 ldr r1, [r4, r1]
 *   @0x1dbc4c add r0, pc, r0
 *   @0x1dbc50 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbc54 ldr r1, [pc, #0x1a0]
 *   @0x1dbc58 ldr r0, [pc, #0x1a0]
 *   @0x1dbc5c mov r2, #1
 *   @0x1dbc60 mov r3, #0
 *   @0x1dbc64 ldr r1, [r4, r1]
 *   @0x1dbc68 add r0, pc, r0
 *   @0x1dbc6c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbc70 ldr r1, [pc, #0x18c]
 *   @0x1dbc74 ldr r0, [pc, #0x18c]
 *   @0x1dbc78 mov r2, #0
 *   @0x1dbc7c mov r3, r2
 *   @0x1dbc80 ldr r1, [r4, r1]
 *   @0x1dbc84 add r0, pc, r0
 *   @0x1dbc88 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbc8c ldr r1, [pc, #0x178]
 *   @0x1dbc90 ldr r0, [pc, #0x178]
 *   @0x1dbc94 mov r2, #0
 *   @0x1dbc98 mov r3, r2
 *   @0x1dbc9c ldr r1, [r4, r1]
 *   @0x1dbca0 add r0, pc, r0
 *   @0x1dbca4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbca8 ldr r1, [pc, #0x164]
 *   @0x1dbcac ldr r0, [pc, #0x164]
 *   @0x1dbcb0 mov r2, #0
 *   @0x1dbcb4 mov r3, r2
 *   @0x1dbcb8 ldr r1, [r4, r1]
 *   @0x1dbcbc add r0, pc, r0
 *   @0x1dbcc0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbcc4 ldr r1, [pc, #0x150]
 *   @0x1dbcc8 ldr r0, [pc, #0x150]
 *   @0x1dbccc mov r2, #0
 *   @0x1dbcd0 mov r3, r2
 *   @0x1dbcd4 ldr r1, [r4, r1]
 *   @0x1dbcd8 add r0, pc, r0
 *   @0x1dbcdc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbce0 ldr r1, [pc, #0x13c]
 *   @0x1dbce4 ldr r0, [pc, #0x13c]
 *   @0x1dbce8 mov r2, #0
 *   @0x1dbcec mov r3, r2
 *   @0x1dbcf0 ldr r1, [r4, r1]
 *   @0x1dbcf4 add r0, pc, r0
 *   @0x1dbcf8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbcfc ldr r1, [pc, #0x128]
 *   @0x1dbd00 ldr r0, [pc, #0x128]
 *   @0x1dbd04 mov r2, #0
 *   @0x1dbd08 mov r3, r2
 *   @0x1dbd0c ldr r1, [r4, r1]
 *   @0x1dbd10 add r0, pc, r0
 *   @0x1dbd14 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbd18 ldr r1, [pc, #0x114]
 *   @0x1dbd1c ldr r0, [pc, #0x114]
 *   @0x1dbd20 mov r2, #0
 *   @0x1dbd24 mov r3, r2
 *   @0x1dbd28 ldr r1, [r4, r1]
 *   @0x1dbd2c add r0, pc, r0
 *   @0x1dbd30 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbd34 ldr r1, [pc, #0x100]
 *   @0x1dbd38 ldr r0, [pc, #0x100]
 *   @0x1dbd3c mov r2, #0
 *   @0x1dbd40 mov r3, r2
 *   @0x1dbd44 ldr r1, [r4, r1]
 *   @0x1dbd48 add r0, pc, r0
 *   @0x1dbd4c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbd50 ldr r1, [pc, #0xec]
 *   @0x1dbd54 ldr r0, [pc, #0xec]
 *   @0x1dbd58 mov r2, #0
 *   @0x1dbd5c mov r3, r2
 *   @0x1dbd60 ldr r1, [r4, r1]
 *   @0x1dbd64 add r0, pc, r0
 *   @0x1dbd68 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbd6c ldr r1, [pc, #0xd8]
 *   @0x1dbd70 ldr r0, [pc, #0xd8]
 *   @0x1dbd74 mov r2, #0
 *   @0x1dbd78 mov r3, r2
 *   @0x1dbd7c ldr r1, [r4, r1]
 *   @0x1dbd80 add r0, pc, r0
 *   @0x1dbd84 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbd88 ldr r1, [pc, #0xc4]
 *   @0x1dbd8c ldr r0, [pc, #0xc4]
 *   @0x1dbd90 mov r2, #0
 *   @0x1dbd94 mov r3, r2
 *   @0x1dbd98 ldr r1, [r4, r1]
 *   @0x1dbd9c add r0, pc, r0
 *   @0x1dbda0 pop {r4, lr}
 *   @0x1dbda4 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib>
 *   @0x1dbda8 eoreq r6, r1, r12, lsl #2
 *   @0x1dbdac .word 0xffffefd8
 *   @0x1dbdb0 andseq r5, r7, r0, ror r8
 *   @0x1dbdb4 .word 0xffffefdc
 *   @0x1dbdb8 andseq r5, r7, r8, ror #16
 *   @0x1dbdbc .word 0xffffefe0
 *   @0x1dbdc0 andseq r5, r7, r4, ror #16
 *   @0x1dbdc4 .word 0xffffefe4
 *   @0x1dbdc8 andseq r5, r7, r12, asr r8
 *   @0x1dbdcc .word 0xffffefe8
 *   @0x1dbdd0 andseq r5, r7, r8, asr r8
 *   @0x1dbdd4 .word 0xffffefec
 *   @0x1dbdd8 andseq r5, r7, r8, asr r8
 *   @0x1dbddc .word 0xffffeff0
 *   @0x1dbde0 andseq r5, r7, r4, asr r8
 *   @0x1dbde4 .word 0xffffeff4
 *   @0x1dbde8 andseq r5, r7, r4, asr r8
 *   @0x1dbdec .word 0xffffeff8
 *   @0x1dbdf0 andseq r5, r7, r4, asr r8
 *   @0x1dbdf4 .word 0xffffeffc
 *   @0x1dbdf8 andseq r5, r7, r12, asr #16
 *   @0x1dbdfc .word 0xfffff000
 *   @0x1dbe00 andseq r5, r7, r8, asr #16
 *   @0x1dbe04 .word 0xfffff004
 *   @0x1dbe08 andseq r5, r7, r0, asr #16
 *   @0x1dbe0c .word 0xfffff008
 *   @0x1dbe10 andseq r5, r7, r12, lsr r8
 *   @0x1dbe14 .word 0xfffff00c
 *   @0x1dbe18 andseq r5, r7, r12, lsr r8
 *   @0x1dbe1c .word 0xfffff010
 *   @0x1dbe20 andseq r5, r7, r8, lsr r8
 *   @0x1dbe24 .word 0xfffff014
 *   @0x1dbe28 andseq r5, r7, r8, lsr r8
 *   @0x1dbe2c .word 0xfffff018
 *   @0x1dbe30 andseq r5, r7, r12, lsr r8
 *   @0x1dbe34 .word 0xfffff01c
 *   @0x1dbe38 andseq r5, r7, r12, lsr r8
 *   @0x1dbe3c .word 0xfffff020
 *   @0x1dbe40 andseq r5, r7, r0, asr #16
 *   @0x1dbe44 .word 0xfffff024
 *   @0x1dbe48 andseq r5, r7, r4, asr #16
 *   @0x1dbe4c .word 0xfffff028
 *   @0x1dbe50 andseq r5, r7, r0, asr #16
 *   @0x1dbe54 .word 0xfffff02c
 *   @0x1dbe58 andseq r5, r7, r0, asr #16
 *
 * ══ §32/36 ReadValue(RValue&, CStream&, int)  0x208638  size 812  203 条（0x208638..0x208964）
 * @func 0x208638 0x208964  size 812  203 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×6 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×4 / CStream::ReadString(char const*&)×3 / CStream::ReadReal()×2 / YYSetString(RValue*, char const*)×2 / ARRAY_RefAlloc(void*)×2 / ReadValue(RValue&, CStream&, int)×2 / CStream::ReadInteger64()×2
 * 字段偏移 top8: 0x4×10 / 0x10×6 / 0xc×5 / 0x3×4 / 0x8×1 / 0x26c×1 / 0x268×1 / 0x1e4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x208638 ldr r3, [r0, #0xc]
 *   @0x20863c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x208640 sub r3, r3, #1
 *   @0x208644 bic r3, r3, #-16777216
 *   @0x208648 sub sp, sp, #12
 *   @0x20864c bic r3, r3, #3
 *   @0x208650 mov r7, r2
 *   @0x208654 mov r2, #0
 *   @0x208658 cmp r3, r2
 *   @0x20865c mov r8, r0
 *   @0x208660 mov r5, r1
 *   @0x208664 str r2, [sp, #0x4]
 *   @0x208668 beq 0x208714 <_Z9ReadValueR6RValueR7CStreami+0xdc>
 *   @0x20866c mov r4, #0
 *   @0x208670 mov r3, #5
 *   @0x208674 str r4, [r8, #0x8]
 *   @0x208678 mov r0, r5
 *   @0x20867c str r4, [r8]
 *   @0x208680 str r3, [r8, #0xc]
 *   @0x208684 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x208688 cmp r7, #1
 *   @0x20868c str r0, [r8, #0xc]
 *   @0x208690 beq 0x208870 <_Z9ReadValueR6RValueR7CStreami+0x238>
 *   @0x208694 cmp r7, #2
 *   @0x208698 beq 0x20871c <_Z9ReadValueR6RValueR7CStreami+0xe4>
 *   @0x20869c cmp r0, #13
 *   @0x2086a0 addls pc, pc, r0, lsl #2
 *   @0x2086a4 b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8>
 *   @0x2086a8 b 0x208734 <_Z9ReadValueR6RValueR7CStreami+0xfc>
 *   @0x2086ac b 0x208748 <_Z9ReadValueR6RValueR7CStreami+0x110>
 *   @0x2086b0 b 0x20876c <_Z9ReadValueR6RValueR7CStreami+0x134>
 *   @0x2086b4 b 0x208824 <_Z9ReadValueR6RValueR7CStreami+0x1ec>
 *   @0x2086b8 b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8>
 *   @0x2086bc b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4>
 *   @0x2086c0 b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8>
 *   @0x2086c4 b 0x208834 <_Z9ReadValueR6RValueR7CStreami+0x1fc>
 *   @0x2086c8 b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8>
 *   @0x2086cc b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8>
 *   @0x2086d0 b 0x208844 <_Z9ReadValueR6RValueR7CStreami+0x20c>
 *   @0x2086d4 b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8>
 *   @0x2086d8 b 0x2086e0 <_Z9ReadValueR6RValueR7CStreami+0xa8>
 *   @0x2086dc b 0x208734 <_Z9ReadValueR6RValueR7CStreami+0xfc>
 *   @0x2086e0 ldr r3, [pc, #0x26c]
 *   @0x2086e4 mov r2, r0
 *   @0x2086e8 ldr r1, [pc, #0x268]
 *   @0x2086ec ldr r3, [pc, r3]
 *   @0x2086f0 add r1, pc, r1
 *   @0x2086f4 ldr r0, [r3]
 *   @0x2086f8 ldr r3, [r0]
 *   @0x2086fc ldr r3, [r3, #0xc]
 *   @0x208700 blx r3
 *   @0x208704 mov r3, #5
 *   @0x208708 str r3, [r8, #0xc]
 *   @0x20870c add sp, sp, #12
 *   @0x208710 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x208714 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x208718 b 0x20866c <_Z9ReadValueR6RValueR7CStreami+0x34>
 *   @0x20871c cmp r0, #1
 *   @0x208720 beq 0x208854 <_Z9ReadValueR6RValueR7CStreami+0x21c>
 *   @0x208724 cmp r0, #2
 *   @0x208728 beq 0x20889c <_Z9ReadValueR6RValueR7CStreami+0x264>
 *   @0x20872c cmp r0, #0
 *   @0x208730 bne 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4>
 *   @0x208734 mov r0, r5
 *   @0x208738 bl 0x20187c <_ZN7CStream8ReadRealEv>
 *   @0x20873c stm r8, {r0, r1}
 *   @0x208740 add sp, sp, #12
 *   @0x208744 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x208748 mov r0, r5
 *   @0x20874c add r1, sp, #4
 *   @0x208750 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0x208754 mov r0, r8
 *   @0x208758 ldr r1, [sp, #0x4]
 *   @0x20875c bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x208760 ldr r0, [sp, #0x4]
 *   @0x208764 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x208768 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4>
 *   @0x20876c mov r0, r8
 *   @0x208770 ldr r11, [pc, #0x1e4]
 *   @0x208774 bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x208778 add r11, pc, r11
 *   @0x20877c mov r10, r0
 *   @0x208780 mov r0, r5
 *   @0x208784 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x208788 mov r3, #400
 *   @0x20878c mov r2, r11
 *   @0x208790 lsl r1, r0, #3
 *   @0x208794 str r0, [r10, #0x10]
 *   @0x208798 add r0, r10, #4
 *   @0x20879c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x2087a0 ldr r3, [r10, #0x10]
 *   @0x2087a4 cmp r3, #0
 *   @0x2087a8 movgt r9, #0
 *   @0x2087ac ble 0x20881c <_Z9ReadValueR6RValueR7CStreami+0x1e4>
 *   @0x2087b0 mov r0, r5
 *   @0x2087b4 ldr r4, [r10, #0x4]
 *   @0x2087b8 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x2087bc mov r3, #404
 *   @0x2087c0 add r6, r4, r9, lsl #3
 *   @0x2087c4 mov r2, r11
 *   @0x2087c8 str r0, [r4, r9, lsl #3]
 *   @0x2087cc lsl r1, r0, #4
 *   @0x2087d0 add r0, r6, #4
 *   @0x2087d4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x2087d8 ldr r3, [r4, r9, lsl #3]
 *   @0x2087dc cmp r3, #0
 *   @0x2087e0 movgt r4, #0
 *   @0x2087e4 ble 0x20880c <_Z9ReadValueR6RValueR7CStreami+0x1d4>
 *   @0x2087e8 ldr r0, [r6, #0x4]
 *   @0x2087ec mov r1, r5
 *   @0x2087f0 mov r2, r7
 *   @0x2087f4 add r0, r0, r4, lsl #4
 *   @0x2087f8 add r4, r4, #1
 *   @0x2087fc bl 0x208638 <_Z9ReadValueR6RValueR7CStreami>
 *   @0x208800 ldr r3, [r6]
 *   @0x208804 cmp r3, r4
 *   @0x208808 bgt 0x2087e8 <_Z9ReadValueR6RValueR7CStreami+0x1b0>
 *   @0x20880c ldr r3, [r10, #0x10]
 *   @0x208810 add r9, r9, #1
 *   @0x208814 cmp r3, r9
 *   @0x208818 bgt 0x2087b0 <_Z9ReadValueR6RValueR7CStreami+0x178>
 *   @0x20881c str r10, [r8]
 *   @0x208820 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4>
 *   @0x208824 mov r0, r5
 *   @0x208828 bl 0x201784 <_ZN7CStream13ReadInteger64Ev>
 *   @0x20882c str r0, [r8]
 *   @0x208830 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4>
 *   @0x208834 mov r0, r5
 *   @0x208838 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x20883c str r0, [r8]
 *   @0x208840 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4>
 *   @0x208844 mov r0, r5
 *   @0x208848 bl 0x201784 <_ZN7CStream13ReadInteger64Ev>
 *   @0x20884c stm r8, {r0, r1}
 *   @0x208850 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4>
 *   @0x208854 mov r0, r5
 *   @0x208858 add r1, sp, #4
 *   @0x20885c bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0x208860 mov r0, r8
 *   @0x208864 ldr r1, [sp, #0x4]
 *   @0x208868 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x20886c b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4>
 *   @0x208870 mov r0, r5
 *   @0x208874 bl 0x20187c <_ZN7CStream8ReadRealEv>
 *   @0x208878 str r0, [r8]
 *   @0x20887c mov r0, r5
 *   @0x208880 str r1, [r8, #0x4]
 *   @0x208884 add r1, sp, #4
 *   @0x208888 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0x20888c mov r0, r8
 *   @0x208890 ldr r1, [sp, #0x4]
 *   @0x208894 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x208898 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4>
 *   @0x20889c mov r0, r8
 *   @0x2088a0 ldr r10, [pc, #0xb8]
 *   @0x2088a4 bl 0xced9c <_Z14ARRAY_RefAllocPv>
 *   @0x2088a8 add r10, pc, r10
 *   @0x2088ac mov r9, r0
 *   @0x2088b0 mov r0, r5
 *   @0x2088b4 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x2088b8 mov r3, #372
 *   @0x2088bc mov r2, r10
 *   @0x2088c0 lsl r1, r0, #3
 *   @0x2088c4 str r0, [r9, #0x10]
 *   @0x2088c8 add r0, r9, #4
 *   @0x2088cc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x2088d0 ldr r3, [r9, #0x10]
 *   @0x2088d4 cmp r3, #0
 *   @0x2088d8 movgt r7, r4
 *   @0x2088dc ble 0x20894c <_Z9ReadValueR6RValueR7CStreami+0x314>
 *   @0x2088e0 mov r0, r5
 *   @0x2088e4 ldr r4, [r9, #0x4]
 *   @0x2088e8 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x2088ec mov r3, #376
 *   @0x2088f0 add r6, r4, r7, lsl #3
 *   @0x2088f4 mov r2, r10
 *   @0x2088f8 str r0, [r4, r7, lsl #3]
 *   @0x2088fc lsl r1, r0, #4
 *   @0x208900 add r0, r6, #4
 *   @0x208904 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x208908 ldr r3, [r4, r7, lsl #3]
 *   @0x20890c cmp r3, #0
 *   @0x208910 movgt r4, #0
 *   @0x208914 ble 0x20893c <_Z9ReadValueR6RValueR7CStreami+0x304>
 *   @0x208918 ldr r0, [r6, #0x4]
 *   @0x20891c mov r1, r5
 *   @0x208920 mov r2, #2
 *   @0x208924 add r0, r0, r4, lsl #4
 *   @0x208928 add r4, r4, #1
 *   @0x20892c bl 0x208638 <_Z9ReadValueR6RValueR7CStreami>
 *   @0x208930 ldr r3, [r6]
 *   @0x208934 cmp r3, r4
 *   @0x208938 bgt 0x208918 <_Z9ReadValueR6RValueR7CStreami+0x2e0>
 *   @0x20893c ldr r3, [r9, #0x10]
 *   @0x208940 add r7, r7, #1
 *   @0x208944 cmp r3, r7
 *   @0x208948 bgt 0x2088e0 <_Z9ReadValueR6RValueR7CStreami+0x2a8>
 *   @0x20894c str r9, [r8]
 *   @0x208950 b 0x20870c <_Z9ReadValueR6RValueR7CStreami+0xd4>
 *   @0x208954 andseq r5, lr, r8, lsr #32
 *   @0x208958 andseq r11, r4, r0, asr #4
 *   @0x20895c andseq r11, r4, r4, ror r0
 *   @0x208960 andseq r10, r4, r4, asr #30
 *
 * ══ §33/36 png_do_read_interlace  0x2ade1c  size 812  203 条（0x2ade1c..0x2ae148）
 * @func 0x2ade1c 0x2ae148  size 812  203 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc×2 / anon_2f1de8+0x47a4 / 0x1511ef8 / 0x330308 / 0x59a000 / 0x43be24 / 0x42e56c / 0x154c8d0
 * 字段偏移 top8: 0x8×3 / 0x34×1 / 0x-28×1 / 0x4×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ade1c push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ade20 sub sp, #0x3c
 *   @0x2ade24 .word 0x4604a31c
 *   @0x2ade28 ldr.w r12, [pc, #0x318]
 *   @0x2ade2c add.w r9, r0, #0x1c4
 *   @0x2ade30 add r10, pc
 *   @0x2ade34 .word 0xf8d0a000
 *   @0x2ade38 ldrbtmi r6, [r12], #432
 *   @0x2ade3c ldrb.w r8, [r0, #0x1e8]
 *   @0x2ade40 ldr.w r3, [r10]
 *   @0x2ade44 add.w r12, r12, #0x8
 *   @0x2ade48 ldr.w r7, [r0, #0x134]
 *   @0x2ade4c add r5, sp, #0x10
 *   @0x2ade50 str.w r10, [sp, #0xc]
 *   @0x2ade54 str r3, [sp, #0x34]
 *   @0x2ade58 strgt r0, [pc, #-0xf]
 *   @0x2ade5c ldm.w r12, {r0, r1, r2}
 *   @0x2ade60 stm.w r5, {r0, r1, r2}
 *   @0x2ade64 beq.w 0x2ae12c <png_do_read_interlace+0x310>
 *   @0x2ade68 cmp.w r9, #0x0
 *   @0x2ade6c beq.w 0x2ae12c <png_do_read_interlace+0x310>
 *   @0x2ade70 add r1, sp, #0x38
 *   @0x2ade74 bl 0x2f658c <ps_hints_apply+0x518c>
 *   @0x2ade78 .word 0xf8940388
 *   @0x2ade7c cdpne p1, #0x5, c8, c1, c15, #0x6
 *   @0x2ade80 ldr r3, [r3, #-40]
 *   @0x2ade84 cmp.w r8, #0x2
 *   @0x2ade88 mul r5, r2, r3
 *   @0x2ade8c str r3, [sp, #0x8]
 *   @0x2ade90 .word 0xd06930ff
 *   @0x2ade94 cmp.w r8, #0x4
 *   @0x2ade98 beq.w 0x2ae01a <png_do_read_interlace+0x1fe>
 *   @0x2ade9c cmp.w r8, #0x1
 *   @0x2adea0 bne.w 0x2ae0d6 <png_do_read_interlace+0x2ba>
 *   @0x2adea4 ands r12, r7, #0x10000
 *   @0x2adea8 add.w r1, r6, r1, lsr #3
 *   @0x2adeac add.w r0, r6, r0, lsr #3
 *   @0x2adeb0 add.w r3, r5, #0x7
 *   @0x2adeb4 add.w r6, r2, #0x7
 *   @0x2adeb8 beq 0x2aded0 <png_do_read_interlace+0xb4>
 *   @0x2adebc and r6, r6, #0x7
 *   @0x2adec0 and r3, r3, #0x7
 *   @0x2adec4 mov.w r8, #0xffffffff
 *   @0x2adec8 str r2, [sp]
 *   @0x2adecc and r0, r9, r7, lsl #24
 *   @0x2aded0 mvns r6, r6
 *   @0x2aded4 and r6, r6, #0x7
 *   @0x2aded8 and r3, r3, #0x7
 *   @0x2adedc mov.w r10, #0x7
 *   @0x2adee0 str.w r10, [sp]
 *   @0x2adee4 movs r7, #0x0
 *   @0x2adee8 addsmi r2, r7, #196, #2
 *   @0x2adeec bhs 0x2adf54 <png_do_read_interlace+0x138>
 *   @0x2adef0 blx 0x1511ef8 <b2_toiTime+0xdb8a54>
 *   @0x2adef4 .word 0xf009f906
 *   @0x2adef8 .word 0xf8cd0901
 *   @0x2adefc .word 0xf04f9004
 *   @0x2adf00 bls 0x330308
 *   @0x2adf04 cmp r9, r2
 *   @0x2adf08 ldrb.w r10, [r0]
 *   @0x2adf0c rsb.w r11, r3, #0x7
 *   @0x2adf10 movw r2, #0x7f7f
 *   @0x2adf14 add.w r9, r9, #0x1
 *   @0x2adf18 asr.w r11, r2, r11
 *   @0x2adf1c and.w r2, r11, r10
 *   @0x2adf20 ldr.w r11, [sp, #0x4]
 *   @0x2adf24 lsl.w r10, r11, r3
 *   @0x2adf28 orr.w r10, r2, r10
 *   @0x2adf2c ldr r2, [sp]
 *   @0x2adf30 addsmi r10, r3, #0
 *   @0x2adf34 itet eq
 *   @0x2adf38 strbmi r3, [r3], #-255
 *   @0x2adf3c moveq r3, r12
 *   @0x2adf40 ldr.w r10, [sp]
 *   @0x2adf44 adds r7, #0x1
 *   @0x2adf48 itet eq
 *   @0x2adf4c strbmi r3, [r6], #-511
 *   @0x2adf50 moveq r6, r12
 *   @0x2adf54 ldrb.w r3, [r4, #0x1cf]
 *   @0x2adf58 str.w r5, [r4, #0x1c4]
 *   @0x2adf5c cmp r3, #0x7
 *   @0x2adf60 ldmeq r11, {r5, r6, r7, pc} ^
 *   @0x2adf64 muls r5, r3, r5
 *   @0x2adf68 ands r12, r7, #0x10000
 *   @0x2adf6c add.w r1, r6, r1, lsr #2
 *   @0x2adf70 add.w r0, r6, r0, lsr #2
 *   @0x2adf74 str r1, [sp]
 *   @0x2adf78 .word 0xf1050203
 *   @0x2adf7c andle r0, r12, r3, lsl #6
 *   @0x2adf80 and r2, r2, #0x3
 *   @0x2adf84 and r3, r3, #0x3
 *   @0x2adf88 mvn r8, #0x1
 *   @0x2adf8c mov.w r9, #0x0
 *   @0x2adf90 lsls r6, r2, #0x1
 *   @0x2adf94 mov.w r12, #0x6
 *   @0x2adf98 b 0x2adfae <png_do_read_interlace+0x192>
 *   @0x2adf9c mvns r3, r3
 *   @0x2adfa0 .word 0xf0030603
 *   @0x2adfa4 .word 0xf04f0303
 *   @0x2adfa8 rsbseq r0, r6, r6, lsl #18
 *   @0x2adfac lsls r3, r3, #0x1
 *   @0x2adfb0 ldr.w r2, [r4, #0x1c4]
 *   @0x2adfb4 cmp r7, r2
 *   @0x2adfb8 ldr r1, [sp]
 *   @0x2adfbc asrs r2, r6
 *   @0x2adfc0 andls r0, r1, #805306368
 *   @0x2adfc4 movs r2, #0x0
 *   @0x2adfc8 cmp r2, r1
 *   @0x2adfcc rsb.w r11, r3, #0x6
 *   @0x2adfd0 movw r10, #0x3f3f
 *   @0x2adfd4 asr.w r11, r10, r11
 *   @0x2adfd8 ldrb.w r10, [r0]
 *   @0x2adfdc cmp r3, r9
 *   @0x2adfe0 b 0x56e7ec <g_SWFlineaavertbuff+0x1b724>
 *   @0x2adfe4 .word 0xf8dd010a
 *   @0x2adfe8 blx 0x59a000 <g_SWFlineaavertbuff+0x46f38>
 *   @0x2adfec svclt #0x8fa03
 *   @0x2adff0 moveq r3, r12
 *   @0x2adff4 svclt #0x180a0a
 *   @0x2adff8 addne r3, r8
 *   @0x2adffc svclt #0x8a000
 *   @0x2ae000 addeq.w r0, r0, #0xffffffff
 *   @0x2ae004 b 0x2adfc6 <png_do_read_interlace+0x1aa>
 *   @0x2ae008 bne 0x2ae014 <png_do_read_interlace+0x1f8>
 *   @0x2ae00c mov r6, r12
 *   @0x2ae010 str r2, [sp]
 *   @0x2ae014 add r6, r8
 *   @0x2ae018 b 0x2adfb0 <png_do_read_interlace+0x194>
 *   @0x2ae01c bl 0x43be24 <g_RomDisk+0x44604>
 *   @0x2ae020 bl 0x42e56c <g_RomDisk+0x36d4c>
 *   @0x2ae024 qaddls r0, r0, r0
 *   @0x2ae028 add.w r2, r2, #0x1
 *   @0x2ae02c add.w r3, r5, #0x1
 *   @0x2ae030 beq 0x2ae048 <png_do_read_interlace+0x22c>
 *   @0x2ae034 .word 0xf0030201
 *   @0x2ae038 .word 0xf04f0301
 *   @0x2ae03c addseq r0, r6, r0, lsl #18
 *   @0x2ae040 lsls r3, r3, #0x2
 *   @0x2ae044 and r0, sp, r3, lsl #4
 *   @0x2ae048 tst.w r2, #0x1
 *   @0x2ae04c mov r9, r8
 *   @0x2ae050 movne r6, #0x0
 *   @0x2ae054 ands r3, r3, #0x1
 *   @0x2ae058 mov r2, r8
 *   @0x2ae05c movne r8, r7
 *   @0x2ae060 movne r3, r8
 *   @0x2ae064 mov.w r12, #0x0
 *   @0x2ae068 ldr.w r7, [r4, #0x1c4]
 *   @0x2ae06c cmp r12, r7
 *   @0x2ae070 stmdbls r0, {r0, r4, r5, r6, r8, r9, r10, r11, sp, pc}
 *   @0x2ae074 ldrb r7, [r1]
 *   @0x2ae078 and r7, r7, #0xf
 *   @0x2ae07c str r7, [sp, #0x4]
 *   @0x2ae080 ldr r1, [sp, #0x8]
 *   @0x2ae084 bge 0x2ae0c0 <png_do_read_interlace+0x2a4>
 *   @0x2ae088 .word 0xf6400b04
 *   @0x2ae08c blx 0x154c8d0 <b2_toiTime+0xdf342c>
 *   @0x2ae090 .word 0xf890fb0b
 *   @0x2ae094 strbmi r10, [r11, #-0x0]
 *   @0x2ae098 add.w r7, r7, #0x1
 *   @0x2ae09c and.w r1, r11, r10
 *   @0x2ae0a0 ldr.w r11, [sp, #0x4]
 *   @0x2ae0a4 lsl.w r10, r11, r3
 *   @0x2ae0a8 it eq
 *   @0x2ae0ac orr.w r10, r1, r10
 *   @0x2ae0b0 it ne
 *   @0x2ae0b4 strb.w r10, [r0]
 *   @0x2ae0b8 it eq
 *   @0x2ae0bc .word 0xe7df30ff
 *   @0x2ae0c0 cmp r6, r9
 *   @0x2ae0c4 ldr r1, [sp]
 *   @0x2ae0c8 subs r1, #0x1
 *   @0x2ae0cc b 0x2ae0d0 <png_do_read_interlace+0x2b4>
 *   @0x2ae0d0 add.w r12, r12, #0x1
 *   @0x2ae0d4 b 0x2ae068 <png_do_read_interlace+0x24c>
 *   @0x2ae0d8 .word 0xf10d08d8
 *   @0x2ae0dc strhs r0, [r0, -r12, lsr #20]
 *   @0x2ae0e0 mla r9, r1, r8, r6
 *   @0x2ae0e4 mla r6, r8, r0, r6
 *   @0x2ae0e8 ldr.w r3, [r4, #0x1c4]
 *   @0x2ae0ec cmp r7, r3
 *   @0x2ae0f0 uasxmi r10, r0, r1
 *   @0x2ae0f4 mov r1, r9
 *   @0x2ae0f8 mov.w r11, #0x0
 *   @0x2ae0fc blx 0xb65bc <memcpy@plt>
 *   @0x2ae100 ldr r3, [sp, #0x8]
 *   @0x2ae104 bge 0x2ae11a <png_do_read_interlace+0x2fe>
 *   @0x2ae108 mov r1, r10
 *   @0x2ae10c rsb r6, r8, r6
 *   @0x2ae110 blx 0xb65bc <memcpy@plt>
 *   @0x2ae114 add.w r11, r11, #0x1
 *   @0x2ae118 b 0x2ae100 <png_do_read_interlace+0x2e4>
 *   @0x2ae11c strlo r0, [r1, -r9, lsl #18]
 *   @0x2ae120 b 0x2ae0e8 <png_do_read_interlace+0x2cc>
 *   @0x2ae124 adds r5, #0x7
 *   @0x2ae128 str.w r5, [r4, #0x1c8]
 *   @0x2ae12c ldr r1, [sp, #0xc]
 *   @0x2ae130 ldr r3, [r1]
 *   @0x2ae134 beq 0x2ae13a <png_do_read_interlace+0x31e>
 *   @0x2ae138 andlt lr, pc, lr, asr #20
 *   @0x2ae13c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ae140 smladx r0, r4, r3, r0
 *   @0x2ae144 subs r6, r5, r6
 *
 * ══ §34/36 Setup_VertexBufferFunctions(bool)  0xca678  size 808  202 条（0xca678..0xca9a0）
 * @func 0xca678 0xca9a0  size 808  202 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Function_Replace(char const*, void (*)(RValue&, CInstance*, CInstance*, int, RValue*))×26
 * 字段偏移 top8: 0x234×2 / 0x228×2 / 0x21c×2 / 0x200×2 / 0x1f4×2 / 0x1e8×2 / 0x1dc×2 / 0x1d0×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xca678 push {r3, r4, r5, lr}
 *   @0xca67c cmp r0, #0
 *   @0xca680 ldr r4, [pc, #0x23c]
 *   @0xca684 add r4, pc, r4
 *   @0xca688 bne 0xca7a8 <_Z27Setup_VertexBufferFunctionsb+0x130>
 *   @0xca68c ldr r3, [pc, #0x234]
 *   @0xca690 ldr r0, [pc, #0x234]
 *   @0xca694 ldr r1, [r4, r3]
 *   @0xca698 add r0, pc, r0
 *   @0xca69c bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca6a0 ldr r3, [pc, #0x228]
 *   @0xca6a4 ldr r0, [pc, #0x228]
 *   @0xca6a8 ldr r1, [r4, r3]
 *   @0xca6ac add r0, pc, r0
 *   @0xca6b0 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca6b4 ldr r3, [pc, #0x21c]
 *   @0xca6b8 ldr r0, [pc, #0x21c]
 *   @0xca6bc ldr r5, [r4, r3]
 *   @0xca6c0 add r0, pc, r0
 *   @0xca6c4 mov r1, r5
 *   @0xca6c8 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca6cc ldr r0, [pc, #0x20c]
 *   @0xca6d0 mov r1, r5
 *   @0xca6d4 add r0, pc, r0
 *   @0xca6d8 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca6dc ldr r3, [pc, #0x200]
 *   @0xca6e0 ldr r0, [pc, #0x200]
 *   @0xca6e4 ldr r1, [r4, r3]
 *   @0xca6e8 add r0, pc, r0
 *   @0xca6ec bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca6f0 ldr r3, [pc, #0x1f4]
 *   @0xca6f4 ldr r0, [pc, #0x1f4]
 *   @0xca6f8 ldr r1, [r4, r3]
 *   @0xca6fc add r0, pc, r0
 *   @0xca700 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca704 ldr r3, [pc, #0x1e8]
 *   @0xca708 ldr r0, [pc, #0x1e8]
 *   @0xca70c ldr r1, [r4, r3]
 *   @0xca710 add r0, pc, r0
 *   @0xca714 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca718 ldr r3, [pc, #0x1dc]
 *   @0xca71c ldr r0, [pc, #0x1dc]
 *   @0xca720 ldr r1, [r4, r3]
 *   @0xca724 add r0, pc, r0
 *   @0xca728 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca72c ldr r3, [pc, #0x1d0]
 *   @0xca730 ldr r0, [pc, #0x1d0]
 *   @0xca734 ldr r1, [r4, r3]
 *   @0xca738 add r0, pc, r0
 *   @0xca73c bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca740 ldr r3, [pc, #0x1c4]
 *   @0xca744 ldr r0, [pc, #0x1c4]
 *   @0xca748 ldr r1, [r4, r3]
 *   @0xca74c add r0, pc, r0
 *   @0xca750 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca754 ldr r3, [pc, #0x1b8]
 *   @0xca758 ldr r0, [pc, #0x1b8]
 *   @0xca75c ldr r1, [r4, r3]
 *   @0xca760 add r0, pc, r0
 *   @0xca764 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca768 ldr r3, [pc, #0x1ac]
 *   @0xca76c ldr r0, [pc, #0x1ac]
 *   @0xca770 ldr r1, [r4, r3]
 *   @0xca774 add r0, pc, r0
 *   @0xca778 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca77c ldr r3, [pc, #0x1a0]
 *   @0xca780 ldr r0, [pc, #0x1a0]
 *   @0xca784 ldr r1, [r4, r3]
 *   @0xca788 add r0, pc, r0
 *   @0xca78c bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca790 ldr r3, [pc, #0x194]
 *   @0xca794 ldr r0, [pc, #0x194]
 *   @0xca798 ldr r1, [r4, r3]
 *   @0xca79c add r0, pc, r0
 *   @0xca7a0 pop {r3, r4, r5, lr}
 *   @0xca7a4 b 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca7a8 ldr r3, [pc, #0x184]
 *   @0xca7ac ldr r0, [pc, #0x184]
 *   @0xca7b0 ldr r1, [r4, r3]
 *   @0xca7b4 add r0, pc, r0
 *   @0xca7b8 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca7bc ldr r3, [pc, #0x178]
 *   @0xca7c0 ldr r0, [pc, #0x178]
 *   @0xca7c4 ldr r1, [r4, r3]
 *   @0xca7c8 add r0, pc, r0
 *   @0xca7cc bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca7d0 ldr r3, [pc, #0x16c]
 *   @0xca7d4 ldr r0, [pc, #0x16c]
 *   @0xca7d8 ldr r5, [r4, r3]
 *   @0xca7dc add r0, pc, r0
 *   @0xca7e0 mov r1, r5
 *   @0xca7e4 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca7e8 ldr r0, [pc, #0x15c]
 *   @0xca7ec mov r1, r5
 *   @0xca7f0 add r0, pc, r0
 *   @0xca7f4 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca7f8 ldr r3, [pc, #0x150]
 *   @0xca7fc ldr r0, [pc, #0x150]
 *   @0xca800 ldr r1, [r4, r3]
 *   @0xca804 add r0, pc, r0
 *   @0xca808 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca80c ldr r3, [pc, #0x144]
 *   @0xca810 ldr r0, [pc, #0x144]
 *   @0xca814 ldr r1, [r4, r3]
 *   @0xca818 add r0, pc, r0
 *   @0xca81c bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca820 ldr r3, [pc, #0x138]
 *   @0xca824 ldr r0, [pc, #0x138]
 *   @0xca828 ldr r1, [r4, r3]
 *   @0xca82c add r0, pc, r0
 *   @0xca830 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca834 ldr r3, [pc, #0x12c]
 *   @0xca838 ldr r0, [pc, #0x12c]
 *   @0xca83c ldr r1, [r4, r3]
 *   @0xca840 add r0, pc, r0
 *   @0xca844 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca848 ldr r3, [pc, #0x120]
 *   @0xca84c ldr r0, [pc, #0x120]
 *   @0xca850 ldr r1, [r4, r3]
 *   @0xca854 add r0, pc, r0
 *   @0xca858 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca85c ldr r3, [pc, #0x114]
 *   @0xca860 ldr r0, [pc, #0x114]
 *   @0xca864 ldr r1, [r4, r3]
 *   @0xca868 add r0, pc, r0
 *   @0xca86c bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca870 ldr r3, [pc, #0x108]
 *   @0xca874 ldr r0, [pc, #0x108]
 *   @0xca878 ldr r1, [r4, r3]
 *   @0xca87c add r0, pc, r0
 *   @0xca880 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca884 ldr r3, [pc, #0xfc]
 *   @0xca888 ldr r0, [pc, #0xfc]
 *   @0xca88c ldr r1, [r4, r3]
 *   @0xca890 add r0, pc, r0
 *   @0xca894 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca898 ldr r3, [pc, #0xf0]
 *   @0xca89c ldr r0, [pc, #0xf0]
 *   @0xca8a0 ldr r1, [r4, r3]
 *   @0xca8a4 add r0, pc, r0
 *   @0xca8a8 bl 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca8ac ldr r3, [pc, #0xe4]
 *   @0xca8b0 ldr r0, [pc, #0xe4]
 *   @0xca8b4 ldr r1, [r4, r3]
 *   @0xca8b8 add r0, pc, r0
 *   @0xca8bc pop {r3, r4, r5, lr}
 *   @0xca8c0 b 0xce070 <_Z16Function_ReplacePKcPFvR6RValueP9CInstanceS4_iPS1_E>
 *   @0xca8c4 eorseq r7, r2, r12, asr #11
 *   @0xca8c8 .word 0xffffbe2c
 *   @0xca8cc .word 0x002678dc
 *   @0xca8d0 .word 0xffffbe30
 *   @0xca8d4 .word 0x002678d8
 *   @0xca8d8 .word 0xffffbe34
 *   @0xca8dc .word 0x002678d8
 *   @0xca8e0 .word 0x002678d4
 *   @0xca8e4 .word 0xffffbe38
 *   @0xca8e8 .word 0x002678d0
 *   @0xca8ec .word 0xffffbe3c
 *   @0xca8f0 eoreq r7, r6, r8, asr #17
 *   @0xca8f4 .word 0xffffbe40
 *   @0xca8f8 eoreq r7, r6, r4, asr #17
 *   @0xca8fc .word 0xffffbe44
 *   @0xca900 eoreq r7, r6, r0, asr #17
 *   @0xca904 .word 0xffffbe48
 *   @0xca908 .word 0x002678bc
 *   @0xca90c .word 0xffffbe4c
 *   @0xca910 .word 0x002678b8
 *   @0xca914 .word 0xffffbe50
 *   @0xca918 .word 0x002678b4
 *   @0xca91c .word 0xffffbe54
 *   @0xca920 .word 0x002678b0
 *   @0xca924 .word 0xffffbe58
 *   @0xca928 eoreq r7, r6, r12, lsr #17
 *   @0xca92c .word 0xffffbe5c
 *   @0xca930 eoreq r7, r6, r8, lsr #17
 *   @0xca934 .word 0xffffbe60
 *   @0xca938 eoreq r7, r6, r0, asr #15
 *   @0xca93c .word 0xffffbe64
 *   @0xca940 .word 0x002677bc
 *   @0xca944 .word 0xffffbe68
 *   @0xca948 .word 0x002677bc
 *   @0xca94c .word 0x002677b8
 *   @0xca950 .word 0xffffbe6c
 *   @0xca954 .word 0x002677b4
 *   @0xca958 .word 0xffffbe70
 *   @0xca95c eoreq r7, r6, r12, lsr #15
 *   @0xca960 .word 0xffffbe74
 *   @0xca964 eoreq r7, r6, r8, lsr #15
 *   @0xca968 .word 0xffffbe78
 *   @0xca96c eoreq r7, r6, r4, lsr #15
 *   @0xca970 .word 0xffffbe7c
 *   @0xca974 eoreq r7, r6, r0, lsr #15
 *   @0xca978 .word 0xffffbe80
 *   @0xca97c mlaeq r6, r12, r7, r7
 *   @0xca980 .word 0xffffbe84
 *   @0xca984 mlaeq r6, r8, r7, r7
 *   @0xca988 .word 0xffffbe88
 *   @0xca98c mlaeq r6, r4, r7, r7
 *   @0xca990 .word 0xffffbe8c
 *   @0xca994 mlaeq r6, r0, r7, r7
 *   @0xca998 .word 0xffffbe90
 *   @0xca99c eoreq r7, r6, r12, lsl #15
 *
 * ══ §35/36 YYObjectBase::InternalGetYYVarRef(int)  0x197fac  size 808  202 条（0x197fac..0x1982d4）
 * @func 0x197fac 0x1982d4  size 808  202 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CHashMapCalculateHash(int)×2 / YYObjectBase::InternalGetYYVarRef(int)+0xb8 / GetRValue() / YYObjectBase::InternalGetYYVarRef(int)+0x13c / YYObjectBase::AllocVars() / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65b0 / YYObjectBase::InternalGetYYVarRef(int)+0x2ac
 * 字段偏移 top8: 0x4×19 / 0x8×12 / 0x10×5 / 0x60×3 / 0xc×2 / 0x58×1 / 0xfc×1
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x197fac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x197fb0 mov r6, r0
 *   @0x197fb4 ldr r7, [r0, #0x60]
 *   @0x197fb8 sub sp, sp, #12
 *   @0x197fbc mov r5, r1
 *   @0x197fc0 cmp r7, #0
 *   @0x197fc4 beq 0x1981a0 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x1f4>
 *   @0x197fc8 mov r0, r5
 *   @0x197fcc bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x197fd0 ldr r1, [r7, #0x8]
 *   @0x197fd4 ldr r9, [r7, #0x10]
 *   @0x197fd8 bic r0, r0, #-2147483648
 *   @0x197fdc and r3, r1, r0
 *   @0x197fe0 lsl r4, r3, #1
 *   @0x197fe4 add r2, r4, r3
 *   @0x197fe8 add r2, r9, r2, lsl #2
 *   @0x197fec ldr r2, [r2, #0x8]
 *   @0x197ff0 cmp r2, #0
 *   @0x197ff4 beq 0x198064 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0xb8>
 *   @0x197ff8 cmp r0, r2
 *   @0x197ffc beq 0x198180 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x1d4>
 *   @0x198000 ldr r10, [r7]
 *   @0x198004 and r2, r1, r2
 *   @0x198008 add r12, r3, r10
 *   @0x19800c rsb r2, r2, r12
 *   @0x198010 tst r2, r1
 *   @0x198014 bmi 0x198064 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0xb8>
 *   @0x198018 mov r12, #0
 *   @0x19801c b 0x198030 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x84>
 *   @0x198020 cmp r0, r2
 *   @0x198024 beq 0x198178 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x1cc>
 *   @0x198028 cmp r7, r12
 *   @0x19802c blt 0x198064 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0xb8>
 *   @0x198030 add r3, r3, #1
 *   @0x198034 add r12, r12, #1
 *   @0x198038 and r3, r1, r3
 *   @0x19803c add r8, r3, r10
 *   @0x198040 lsl r4, r3, #1
 *   @0x198044 add r2, r4, r3
 *   @0x198048 add r2, r9, r2, lsl #2
 *   @0x19804c ldr r2, [r2, #0x8]
 *   @0x198050 and r7, r1, r2
 *   @0x198054 cmp r2, #0
 *   @0x198058 rsb r7, r7, r8
 *   @0x19805c and r7, r7, r1
 *   @0x198060 bne 0x198020 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x74>
 *   @0x198064 bl 0x190dc0 <_Z9GetRValuev>
 *   @0x198068 mov r7, #0
 *   @0x19806c ldr r3, [r6, #0x58]
 *   @0x198070 str r7, [r0]
 *   @0x198074 mov r4, r0
 *   @0x198078 ldr r6, [r6, #0x60]
 *   @0x19807c str r3, [r0, #0xc]
 *   @0x198080 ldr r2, [r6, #0xc]
 *   @0x198084 mov r12, r6
 *   @0x198088 ldr r3, [r6, #0x4]
 *   @0x19808c str r6, [sp, #0x4]
 *   @0x198090 cmp r3, r2
 *   @0x198094 bgt 0x1981bc <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x210>
 *   @0x198098 ldr r12, [sp, #0x4]
 *   @0x19809c add r3, r3, #1
 *   @0x1980a0 mov r0, r5
 *   @0x1980a4 str r3, [r12, #0x4]
 *   @0x1980a8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x1980ac ldr r12, [sp, #0x4]
 *   @0x1980b0 ldr r6, [r12, #0x8]
 *   @0x1980b4 ldr r10, [r12, #0x10]
 *   @0x1980b8 bic r0, r0, #-2147483648
 *   @0x1980bc and r3, r0, r6
 *   @0x1980c0 add r2, r3, r3, lsl #1
 *   @0x1980c4 add r2, r10, r2, lsl #2
 *   @0x1980c8 ldr r1, [r2, #0x8]
 *   @0x1980cc cmp r1, #0
 *   @0x1980d0 beq 0x1981ac <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x200>
 *   @0x1980d4 ldr r12, [sp, #0x4]
 *   @0x1980d8 mov r9, r4
 *   @0x1980dc mov r7, #0
 *   @0x1980e0 ldr r11, [r12]
 *   @0x1980e4 b 0x198128 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x17c>
 *   @0x1980e8 ldr r8, [r2]
 *   @0x1980ec ldr r7, [r2, #0x4]
 *   @0x1980f0 str r0, [r2, #0x8]
 *   @0x1980f4 mov r0, r1
 *   @0x1980f8 str r5, [r2]
 *   @0x1980fc mov r5, r8
 *   @0x198100 str r9, [r2, #0x4]
 *   @0x198104 mov r9, r7
 *   @0x198108 add r3, r3, #1
 *   @0x19810c add r7, r12, #1
 *   @0x198110 and r3, r3, r6
 *   @0x198114 add r2, r3, r3, lsl #1
 *   @0x198118 add r2, r10, r2, lsl #2
 *   @0x19811c ldr r1, [r2, #0x8]
 *   @0x198120 cmp r1, #0
 *   @0x198124 beq 0x1981b0 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x204>
 *   @0x198128 add r12, r3, r11
 *   @0x19812c and r8, r1, r6
 *   @0x198130 rsb r12, r8, r12
 *   @0x198134 and r12, r12, r6
 *   @0x198138 cmp r12, r7
 *   @0x19813c blt 0x1980e8 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x13c>
 *   @0x198140 movne r12, r7
 *   @0x198144 bne 0x198108 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x15c>
 *   @0x198148 cmp r1, r0
 *   @0x19814c bne 0x198108 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x15c>
 *   @0x198150 ldr r7, [r2]
 *   @0x198154 cmp r5, r7
 *   @0x198158 bne 0x198108 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x15c>
 *   @0x19815c ldr r12, [sp, #0x4]
 *   @0x198160 ldr r3, [r12, #0x4]
 *   @0x198164 stm r2, {r5, r9}
 *   @0x198168 sub r3, r3, #1
 *   @0x19816c str r1, [r2, #0x8]
 *   @0x198170 str r3, [r12, #0x4]
 *   @0x198174 b 0x198194 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x1e8>
 *   @0x198178 cmn r3, #1
 *   @0x19817c beq 0x198064 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0xb8>
 *   @0x198180 add r3, r4, r3
 *   @0x198184 add r9, r9, r3, lsl #2
 *   @0x198188 cmn r9, #4
 *   @0x19818c ldrne r4, [r9, #0x4]
 *   @0x198190 beq 0x198064 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0xb8>
 *   @0x198194 mov r0, r4
 *   @0x198198 add sp, sp, #12
 *   @0x19819c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1981a0 bl 0x1917dc <_ZN12YYObjectBase9AllocVarsEv>
 *   @0x1981a4 ldr r7, [r6, #0x60]
 *   @0x1981a8 b 0x197fc8 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x1c>
 *   @0x1981ac mov r9, r4
 *   @0x1981b0 stm r2, {r5, r9}
 *   @0x1981b4 str r0, [r2, #0x8]
 *   @0x1981b8 b 0x198194 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x1e8>
 *   @0x1981bc ldr r9, [r6]
 *   @0x1981c0 mov r3, #1
 *   @0x1981c4 ldr r8, [r6, #0x10]
 *   @0x1981c8 mov r2, #70
 *   @0x1981cc ldr r1, [pc, #0xfc]
 *   @0x1981d0 lsl r0, r9, r3
 *   @0x1981d4 str r0, [r6]
 *   @0x1981d8 add r6, r0, r9, lsl #2
 *   @0x1981dc add r1, pc, r1
 *   @0x1981e0 sub r0, r0, #1
 *   @0x1981e4 str r0, [r12, #0x8]
 *   @0x1981e8 lsl r6, r6, #2
 *   @0x1981ec mov r0, r6
 *   @0x1981f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1981f4 ldr r12, [sp, #0x4]
 *   @0x1981f8 mov r2, r6
 *   @0x1981fc mov r1, r7
 *   @0x198200 str r0, [r12, #0x10]
 *   @0x198204 bl 0xb65b0 <memset@plt>
 *   @0x198208 ldr r12, [sp, #0x4]
 *   @0x19820c vldr s15, [pc, #184]
 *   @0x198210 ldr r2, [r12]
 *   @0x198214 str r7, [r12, #0x4]
 *   @0x198218 cmp r2, r7
 *   @0x19821c vmov s13, r2
 *   @0x198220 vcvt.f32.s32 s14, s13
 *   @0x198224 vmul.f32 s15, s14, s15
 *   @0x198228 vcvt.s32.f32 s15, s15
 *   @0x19822c vstr s15, [r12, #12]
 *   @0x198230 ble 0x198258 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x2ac>
 *   @0x198234 ldr r12, [sp, #0x4]
 *   @0x198238 add r2, r2, r2, lsl #1
 *   @0x19823c mov r1, r7
 *   @0x198240 ldr r3, [r12, #0x10]
 *   @0x198244 add r2, r3, r2, lsl #2
 *   @0x198248 str r1, [r3, #0x8]
 *   @0x19824c add r3, r3, #12
 *   @0x198250 cmp r3, r2
 *   @0x198254 bne 0x198248 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x29c>
 *   @0x198258 cmp r9, #0
 *   @0x19825c ble 0x198294 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x2e8>
 *   @0x198260 ldr r10, [sp, #0x4]
 *   @0x198264 mov r6, r8
 *   @0x198268 mov r7, #0
 *   @0x19826c ldr r3, [r6, #0x8]
 *   @0x198270 mov r0, r10
 *   @0x198274 add r7, r7, #1
 *   @0x198278 cmp r3, #0
 *   @0x19827c ble 0x198288 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x2dc>
 *   @0x198280 ldm r6, {r1, r2}
 *   @0x198284 bl 0x196408 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_>
 *   @0x198288 cmp r7, r9
 *   @0x19828c add r6, r6, #12
 *   @0x198290 bne 0x19826c <_ZN12YYObjectBase19InternalGetYYVarRefEi+0x2c0>
 *   @0x198294 mov r0, r8
 *   @0x198298 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x19829c ldr r12, [sp, #0x4]
 *   @0x1982a0 vldr s15, [pc, #36]
 *   @0x1982a4 ldr r12, [r12]
 *   @0x1982a8 str r12, [sp]
 *   @0x1982ac vldr s13, [sp]
 *   @0x1982b0 vcvt.f32.s32 s14, s13
 *   @0x1982b4 ldr r12, [sp, #0x4]
 *   @0x1982b8 ldr r3, [r12, #0x4]
 *   @0x1982bc vmul.f32 s15, s14, s15
 *   @0x1982c0 vcvt.s32.f32 s15, s15
 *   @0x1982c4 vstr s15, [r12, #12]
 *   @0x1982c8 b 0x198098 <_ZN12YYObjectBase19InternalGetYYVarRefEi+0xec>
 *   @0x1982cc svclo #0x19999a
 *   @0x1982d0 andseq r8, r9, r4, asr lr
 *
 * ══ §36/36 YYGML_NewWithIterator(SWithIterator*, YYObjectBase**, YYObjectBase**, int)  0xd7f58  size 672  168 条（0xd7f58..0xd81f8）
 * @func 0xd7f58 0xd81f8  size 672  168 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×4 / YYGML_NewWithIterator(SWithIterator*, YYObjectBase**, YYObjectBase**, int)+0x1dc
 * 字段偏移 top8: 0x8×9 / 0xc×6 / 0x4×4 / 0x68×3 / 0x69×3 / 0x80×2 / 0x178×2 / 0x21c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd7f58 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xd7f5c mov r4, r0
 *   @0xd7f60 ldr r0, [r1]
 *   @0xd7f64 mov r8, r2
 *   @0xd7f68 add r2, r3, #7
 *   @0xd7f6c mov r7, r1
 *   @0xd7f70 mov r1, #0
 *   @0xd7f74 str r0, [r4]
 *   @0xd7f78 ldr r0, [r8]
 *   @0xd7f7c str r1, [r4, #0x8]
 *   @0xd7f80 str r1, [r4, #0xc]
 *   @0xd7f84 str r0, [r4, #0x4]
 *   @0xd7f88 cmp r2, #6
 *   @0xd7f8c addls pc, pc, r2, lsl #2
 *   @0xd7f90 b 0xd8108 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x1b0>
 *   @0xd7f94 b 0xd7fb0 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x58>
 *   @0xd7f98 b 0xd80c4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x16c>
 *   @0xd7f9c b 0xd7fb0 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x58>
 *   @0xd7fa0 b 0xd7fb0 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x58>
 *   @0xd7fa4 b 0xd8008 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0xb0>
 *   @0xd7fa8 b 0xd7fbc <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x64>
 *   @0xd7fac b 0xd80c4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x16c>
 *   @0xd7fb0 mvn r6, #0
 *   @0xd7fb4 mov r0, r6
 *   @0xd7fb8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xd7fbc ldr r1, [pc, #0x21c]
 *   @0xd7fc0 movw r2, #0x2125
 *   @0xd7fc4 mov r3, #1
 *   @0xd7fc8 mov r0, #4
 *   @0xd7fcc add r1, pc, r1
 *   @0xd7fd0 mov r6, #1
 *   @0xd7fd4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xd7fd8 mov r3, #0
 *   @0xd7fdc str r0, [r4, #0x8]
 *   @0xd7fe0 str r3, [r0]
 *   @0xd7fe4 mov r0, r6
 *   @0xd7fe8 ldr r3, [r4, #0x4]
 *   @0xd7fec ldr r2, [r4, #0x8]
 *   @0xd7ff0 add r2, r2, #4
 *   @0xd7ff4 str r2, [r4, #0xc]
 *   @0xd7ff8 str r3, [r7]
 *   @0xd7ffc ldr r3, [r4]
 *   @0xd8000 str r3, [r8]
 *   @0xd8004 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xd8008 ldr r9, [pc, #0x1d4]
 *   @0xd800c ldr r9, [pc, r9]
 *   @0xd8010 ldr r3, [r9]
 *   @0xd8014 ldr r3, [r3, #0x80]
 *   @0xd8018 cmp r3, #0
 *   @0xd801c beq 0xd8134 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x1dc>
 *   @0xd8020 mov r6, #0
 *   @0xd8024 ldrb r0, [r3, #0x68]
 *   @0xd8028 ldr r5, [r3, #0x178]
 *   @0xd802c cmp r0, #0
 *   @0xd8030 bne 0xd8040 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0xe8>
 *   @0xd8034 ldrb r3, [r3, #0x69]
 *   @0xd8038 cmp r3, #0
 *   @0xd803c addeq r6, r6, #1
 *   @0xd8040 cmp r5, #0
 *   @0xd8044 mov r3, r5
 *   @0xd8048 bne 0xd8024 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0xcc>
 *   @0xd804c cmp r6, #0
 *   @0xd8050 beq 0xd7fb4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x5c>
 *   @0xd8054 ldr r1, [pc, #0x18c]
 *   @0xd8058 mov r3, #1
 *   @0xd805c lsl r0, r6, #2
 *   @0xd8060 movw r2, #0x2141
 *   @0xd8064 add r1, pc, r1
 *   @0xd8068 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xd806c ldr r3, [r4]
 *   @0xd8070 str r0, [r4, #0x8]
 *   @0xd8074 str r3, [r8]
 *   @0xd8078 ldr r3, [r9]
 *   @0xd807c ldr r3, [r3, #0x80]
 *   @0xd8080 cmp r3, #0
 *   @0xd8084 beq 0xd80b4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x15c>
 *   @0xd8088 ldrb r1, [r3, #0x68]
 *   @0xd808c ldr r2, [r3, #0x178]
 *   @0xd8090 cmp r1, #0
 *   @0xd8094 bne 0xd80a8 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x150>
 *   @0xd8098 ldrb r1, [r3, #0x69]
 *   @0xd809c cmp r1, #0
 *   @0xd80a0 streq r5, [r0], #4
 *   @0xd80a4 moveq r5, r3
 *   @0xd80a8 cmp r2, #0
 *   @0xd80ac mov r3, r2
 *   @0xd80b0 bne 0xd8088 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x130>
 *   @0xd80b4 str r5, [r7]
 *   @0xd80b8 str r0, [r4, #0xc]
 *   @0xd80bc mov r0, r6
 *   @0xd80c0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xd80c4 ldr r1, [pc, #0x120]
 *   @0xd80c8 movw r2, #0x211b
 *   @0xd80cc mov r3, #1
 *   @0xd80d0 mov r0, #4
 *   @0xd80d4 add r1, pc, r1
 *   @0xd80d8 mov r6, #1
 *   @0xd80dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xd80e0 mov r3, #0
 *   @0xd80e4 str r0, [r4, #0x8]
 *   @0xd80e8 str r3, [r0]
 *   @0xd80ec mov r0, r6
 *   @0xd80f0 ldr r3, [r4]
 *   @0xd80f4 ldr r2, [r4, #0x8]
 *   @0xd80f8 add r2, r2, #4
 *   @0xd80fc str r2, [r4, #0xc]
 *   @0xd8100 str r3, [r8]
 *   @0xd8104 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xd8108 cmp r3, #0
 *   @0xd810c blt 0xd8134 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x1dc>
 *   @0xd8110 movw r2, #0x869f
 *   @0xd8114 movt r2, #0x1
 *   @0xd8118 cmp r3, r2
 *   @0xd811c bgt 0xd8140 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x1e8>
 *   @0xd8120 mov r0, r4
 *   @0xd8124 mov r1, r7
 *   @0xd8128 mov r2, r8
 *   @0xd812c pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xd8130 b 0xd7df8 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i>
 *   @0xd8134 mov r6, #0
 *   @0xd8138 mov r0, r6
 *   @0xd813c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xd8140 ldr r2, [pc, #0xa8]
 *   @0xd8144 ldr r2, [pc, r2]
 *   @0xd8148 ldr r1, [r2, #0x4]
 *   @0xd814c ldr r2, [r2]
 *   @0xd8150 and r1, r3, r1
 *   @0xd8154 ldr r6, [r2, r1, lsl #3]
 *   @0xd8158 cmp r6, #0
 *   @0xd815c bne 0xd8170 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x218>
 *   @0xd8160 b 0xd7fb4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x5c>
 *   @0xd8164 ldr r6, [r6, #0x4]
 *   @0xd8168 cmp r6, #0
 *   @0xd816c beq 0xd7fb4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x5c>
 *   @0xd8170 ldr r2, [r6, #0x8]
 *   @0xd8174 cmp r3, r2
 *   @0xd8178 bne 0xd8164 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x20c>
 *   @0xd817c ldr r5, [r6, #0xc]
 *   @0xd8180 cmp r5, #0
 *   @0xd8184 beq 0xd8134 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x1dc>
 *   @0xd8188 ldrb r6, [r5, #0x68]
 *   @0xd818c cmp r6, #0
 *   @0xd8190 bne 0xd8134 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x1dc>
 *   @0xd8194 ldrb r9, [r5, #0x69]
 *   @0xd8198 cmp r9, #0
 *   @0xd819c bne 0xd7fb4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x5c>
 *   @0xd81a0 ldr r1, [pc, #0x4c]
 *   @0xd81a4 movw r2, #0x2178
 *   @0xd81a8 mov r3, #1
 *   @0xd81ac mov r0, #4
 *   @0xd81b0 add r1, pc, r1
 *   @0xd81b4 mov r6, #1
 *   @0xd81b8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xd81bc str r0, [r4, #0x8]
 *   @0xd81c0 str r9, [r0]
 *   @0xd81c4 ldr r3, [r4]
 *   @0xd81c8 ldr r2, [r4, #0x8]
 *   @0xd81cc add r2, r2, #4
 *   @0xd81d0 str r2, [r4, #0xc]
 *   @0xd81d4 str r3, [r8]
 *   @0xd81d8 str r5, [r7]
 *   @0xd81dc b 0xd7fb4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x5c>
 *   @0xd81e0 .word 0x0025a7b0
 *   @0xd81e4 eorseq r5, r1, r12, lsl r9
 *   @0xd81e8 eoreq r10, r5, r8, lsl r7
 *   @0xd81ec eoreq r10, r5, r8, lsr #13
 *   @0xd81f0 eorseq r5, r1, r0, lsl #22
 *   @0xd81f4 eoreq r10, r5, r12, asr #11
 */
