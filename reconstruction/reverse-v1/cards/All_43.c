/* cally 逆向卡：All_43 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 66 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/66 F_SpriteReplace(RValue&, CInstance*, CInstance*, int, RValue*)  0x12bb80  size 484  121 条（0x12bb80..0x12bd64）
 * @func 0x12bb80 0x12bd64  size 484  121 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×13 / YYGetString(RValue const*, int)×2 / Sprite_Data(int) / Sprite_Replace(int, char const*, int, bool, bool, bool, bool, int, int)
 * 字段偏移 top8: 0xc×3 / 0x18×2 / 0x1c×2 / 0x8×2 / 0x48×1 / 0x10×1 / 0x4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12bb80 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x12bb84 sub sp, sp, #36
 *   @0x12bb88 mov r1, #0
 *   @0x12bb8c mov r5, r0
 *   @0x12bb90 ldr r4, [sp, #0x48]
 *   @0x12bb94 mov r6, r3
 *   @0x12bb98 mov r0, r4
 *   @0x12bb9c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bba0 mov r7, r0
 *   @0x12bba4 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x12bba8 cmp r0, #0
 *   @0x12bbac beq 0x12bcac <_Z15F_SpriteReplaceR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x12bbb0 cmp r6, #7
 *   @0x12bbb4 beq 0x12bccc <_Z15F_SpriteReplaceR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0x12bbb8 cmp r6, #9
 *   @0x12bbbc bne 0x12bcac <_Z15F_SpriteReplaceR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x12bbc0 mov r1, #1
 *   @0x12bbc4 mov r0, r4
 *   @0x12bbc8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12bbcc mov r1, #2
 *   @0x12bbd0 mov r9, r0
 *   @0x12bbd4 mov r0, r4
 *   @0x12bbd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bbdc mov r1, #3
 *   @0x12bbe0 mov r8, r0
 *   @0x12bbe4 mov r0, r4
 *   @0x12bbe8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bbec mov r1, #4
 *   @0x12bbf0 mov r6, r0
 *   @0x12bbf4 mov r0, r4
 *   @0x12bbf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bbfc mov r1, #5
 *   @0x12bc00 mov r2, r0
 *   @0x12bc04 mov r0, r4
 *   @0x12bc08 str r2, [sp, #0x18]
 *   @0x12bc0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bc10 mov r1, #6
 *   @0x12bc14 mov r3, r0
 *   @0x12bc18 mov r0, r4
 *   @0x12bc1c str r3, [sp, #0x1c]
 *   @0x12bc20 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bc24 mov r1, #7
 *   @0x12bc28 mov r11, r0
 *   @0x12bc2c mov r0, r4
 *   @0x12bc30 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bc34 mov r1, #8
 *   @0x12bc38 mov r10, r0
 *   @0x12bc3c mov r0, r4
 *   @0x12bc40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bc44 ldr r2, [sp, #0x18]
 *   @0x12bc48 ldr r3, [sp, #0x1c]
 *   @0x12bc4c mov r1, r9
 *   @0x12bc50 cmp r2, #0
 *   @0x12bc54 str r10, [sp, #0xc]
 *   @0x12bc58 movle r2, #0
 *   @0x12bc5c movgt r2, #1
 *   @0x12bc60 cmp r3, #0
 *   @0x12bc64 movle r3, #0
 *   @0x12bc68 movgt r3, #1
 *   @0x12bc6c cmp r11, #0
 *   @0x12bc70 stm sp, {r2, r3}
 *   @0x12bc74 mov r2, r8
 *   @0x12bc78 movle r11, #0
 *   @0x12bc7c movgt r11, #1
 *   @0x12bc80 cmp r6, #0
 *   @0x12bc84 str r11, [sp, #0x8]
 *   @0x12bc88 movle r3, #0
 *   @0x12bc8c movgt r3, #1
 *   @0x12bc90 str r0, [sp, #0x10]
 *   @0x12bc94 mov r0, r7
 *   @0x12bc98 bl 0x1ef5a8 <_Z14Sprite_ReplaceiPKcibbbbii>
 *   @0x12bc9c vmov s15, r0
 *   @0x12bca0 vcvt.f64.s32 d7, s15
 *   @0x12bca4 vmov r2, r3, d7
 *   @0x12bca8 b 0x12bcb8 <_Z15F_SpriteReplaceR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x12bcac mov r3, #0
 *   @0x12bcb0 movt r3, #0xbff0
 *   @0x12bcb4 mov r2, #0
 *   @0x12bcb8 mov r1, #0
 *   @0x12bcbc stm r5, {r2, r3}
 *   @0x12bcc0 str r1, [r5, #0xc]
 *   @0x12bcc4 add sp, sp, #36
 *   @0x12bcc8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x12bccc mov r1, #1
 *   @0x12bcd0 mov r0, r4
 *   @0x12bcd4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x12bcd8 mov r1, #2
 *   @0x12bcdc mov r9, r0
 *   @0x12bce0 mov r0, r4
 *   @0x12bce4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bce8 mov r1, #3
 *   @0x12bcec mov r8, r0
 *   @0x12bcf0 mov r0, r4
 *   @0x12bcf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bcf8 mov r1, #4
 *   @0x12bcfc mov r11, r0
 *   @0x12bd00 mov r0, r4
 *   @0x12bd04 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bd08 mov r1, #5
 *   @0x12bd0c mov r10, r0
 *   @0x12bd10 mov r0, r4
 *   @0x12bd14 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bd18 mov r1, #6
 *   @0x12bd1c mov r6, r0
 *   @0x12bd20 mov r0, r4
 *   @0x12bd24 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12bd28 cmp r11, #0
 *   @0x12bd2c mov r12, #1
 *   @0x12bd30 mov r1, r9
 *   @0x12bd34 movle r11, #0
 *   @0x12bd38 movgt r11, #1
 *   @0x12bd3c cmp r10, #0
 *   @0x12bd40 str r11, [sp]
 *   @0x12bd44 mov r2, r8
 *   @0x12bd48 str r6, [sp, #0xc]
 *   @0x12bd4c movle r10, #0
 *   @0x12bd50 movgt r10, #1
 *   @0x12bd54 mov r3, r12
 *   @0x12bd58 str r10, [sp, #0x4]
 *   @0x12bd5c str r12, [sp, #0x8]
 *   @0x12bd60 b 0x12bc90 <_Z15F_SpriteReplaceR6RValueP9CInstanceS2_iPS_+0x110>
 *
 * ══ §2/66 F_FileTextSet(RValue&, CInstance*, CInstance*, int, RValue*)  0x13a3d8  size 484  121 条（0x13a3d8..0x13a5bc）
 * @func 0x13a3d8 0x13a5bc  size 484  121 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x13a40c→0x483724, 0x13a43c→0x4837a4, 0x13a478→0x3eb70c, 0x13a4d4→0x3eb788
 * 调用序列: operator new(unsigned int)×2 / YYGetString(RValue const*, int) / MemoryManager::Free(void const*) / 0xb6538 / IBuffer::IBuffer(int, eBuffer_Format, int) / 0xb65bc / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×8 / 0x4×7 / 0x8×5 / 0x124×2 / 0x2×2 / 0x38×1 / 0x18c×1 / 0x188×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13a3d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13a3dc sub sp, sp, #20
 *   @0x13a3e0 mov r1, #0
 *   @0x13a3e4 mov r5, r0
 *   @0x13a3e8 ldr r7, [sp, #0x38]
 *   @0x13a3ec mov r3, r1
 *   @0x13a3f0 str r1, [r0, #0xc]
 *   @0x13a3f4 movt r3, #0xbff0
 *   @0x13a3f8 stm r0, {r1, r3}
 *   @0x13a3fc mov r4, #1
 *   @0x13a400 mov r0, r7
 *   @0x13a404 ldr r6, [pc, #0x18c]
 *   @0x13a408 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13a40c ldr r3, [pc, #0x188]
 *   @0x13a410 add r6, pc, r6
 *   @0x13a414 ldr r3, [r6, r3]
 *   @0x13a418 str r3, [sp, #0x8]
 *   @0x13a41c mov r9, r0
 *   @0x13a420 b 0x13a430 <_Z13F_FileTextSetR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x13a424 add r4, r4, #1
 *   @0x13a428 cmp r4, #32
 *   @0x13a42c beq 0x13a580 <_Z13F_FileTextSetR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x13a430 ldr r11, [r3, #0x4]!
 *   @0x13a434 cmp r11, #0
 *   @0x13a438 bne 0x13a424 <_Z13F_FileTextSetR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x13a43c ldr r2, [pc, #0x15c]
 *   @0x13a440 lsl r10, r4, #1
 *   @0x13a444 add r3, r10, r4
 *   @0x13a448 ldr r8, [r6, r2]
 *   @0x13a44c lsl r3, r3, #2
 *   @0x13a450 ldr r0, [r8, r3]
 *   @0x13a454 cmp r0, #0
 *   @0x13a458 beq 0x13a46c <_Z13F_FileTextSetR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x13a45c str r3, [sp, #0x4]
 *   @0x13a460 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13a464 ldr r3, [sp, #0x4]
 *   @0x13a468 str r11, [r8, r3]
 *   @0x13a46c ldr r7, [r7, #0xc]
 *   @0x13a470 cmp r7, #1
 *   @0x13a474 beq 0x13a4a0 <_Z13F_FileTextSetR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x13a478 ldr r3, [pc, #0x124]
 *   @0x13a47c ldr r1, [pc, #0x124]
 *   @0x13a480 ldr r3, [r6, r3]
 *   @0x13a484 add r1, pc, r1
 *   @0x13a488 ldr r0, [r3]
 *   @0x13a48c ldr r3, [r0]
 *   @0x13a490 ldr r3, [r3, #0xc]
 *   @0x13a494 blx r3
 *   @0x13a498 add sp, sp, #20
 *   @0x13a49c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13a4a0 mov r0, #16
 *   @0x13a4a4 bl 0x27c524 <_Znwj>
 *   @0x13a4a8 mov r11, r0
 *   @0x13a4ac mov r0, r9
 *   @0x13a4b0 bl 0xb6538 <strlen@plt>
 *   @0x13a4b4 str r0, [sp, #0xc]
 *   @0x13a4b8 mov r0, #64
 *   @0x13a4bc bl 0x27c524 <_Znwj>
 *   @0x13a4c0 ldr r1, [sp, #0xc]
 *   @0x13a4c4 mov r2, r7
 *   @0x13a4c8 mov r3, r7
 *   @0x13a4cc str r0, [sp, #0x4]
 *   @0x13a4d0 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati>
 *   @0x13a4d4 ldr r3, [pc, #0xd0]
 *   @0x13a4d8 mov r1, r9
 *   @0x13a4dc ldr r12, [sp, #0x4]
 *   @0x13a4e0 ldr r2, [sp, #0xc]
 *   @0x13a4e4 ldr r3, [r6, r3]
 *   @0x13a4e8 add r6, r10, r4
 *   @0x13a4ec ldr r0, [r12, #0xc]
 *   @0x13a4f0 add r3, r3, #8
 *   @0x13a4f4 lsl r6, r6, #2
 *   @0x13a4f8 str r3, [r12]
 *   @0x13a4fc str r12, [r11]
 *   @0x13a500 bl 0xb65bc <memcpy@plt>
 *   @0x13a504 add r12, r8, r6
 *   @0x13a508 ldr r1, [pc, #0xa0]
 *   @0x13a50c mov r3, #0
 *   @0x13a510 movw r2, #0x2ee
 *   @0x13a514 str r3, [r11, #0x8]
 *   @0x13a518 add r1, pc, r1
 *   @0x13a51c mov r3, r7
 *   @0x13a520 str r11, [r12, #0x8]
 *   @0x13a524 mov r0, #15
 *   @0x13a528 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13a52c vmov s15, r4
 *   @0x13a530 ldr r3, [pc, #0x7c]
 *   @0x13a534 vcvt.f64.s32 d7, s15
 *   @0x13a538 add r3, pc, r3
 *   @0x13a53c vmov r10, r11, d7
 *   @0x13a540 str r0, [r8, r6]
 *   @0x13a544 mov r12, r0
 *   @0x13a548 ldm r3!, {r0, r1, r2}
 *   @0x13a54c ldrh r9, [r3]
 *   @0x13a550 ldrb r3, [r3, #0x2]
 *   @0x13a554 str r0, [r12]
 *   @0x13a558 str r1, [r12, #0x4]
 *   @0x13a55c strb r3, [r12, #0xe]
 *   @0x13a560 ldr r3, [sp, #0x8]
 *   @0x13a564 str r2, [r12, #0x8]
 *   @0x13a568 strh r9, [r12, #12]
 *   @0x13a56c str r7, [r3, r4, lsl #2]
 *   @0x13a570 vstr s14, [r5]
 *   @0x13a574 str r11, [r5, #0x4]
 *   @0x13a578 add sp, sp, #20
 *   @0x13a57c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13a580 ldr r0, [pc, #0x30]
 *   @0x13a584 mov r1, #0
 *   @0x13a588 add r0, pc, r0
 *   @0x13a58c add sp, sp, #20
 *   @0x13a590 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13a594 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x13a598 eoreq r7, r11, r0, asr #16
 *   @0x13a59c .word 0xffffd620
 *   @0x13a5a0 .word 0xffffd624
 *   @0x13a5a4 .word 0xffffbac4
 *   @0x13a5a8 eoreq r5, r0, r12, asr lr
 *   @0x13a5ac .word 0xffffbd60
 *   @0x13a5b0 eoreq r5, r0, r8, lsr r11
 *   @0x13a5b4 .word 0x00205dd0
 *   @0x13a5b8 eoreq r5, r0, r8, ror r10
 *
 * ══ §3/66 F_YoYo_MD5File(RValue&, CInstance*, CInstance*, int, RValue*)  0x157d38  size 484  121 条（0x157d38..0x157f1c）
 * @func 0x157d38 0x157f1c  size 484  121 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68d4×2 / MD5Update(MD5_CTX*, unsigned char*, unsigned int)×2 / YYGetString(RValue const*, int) / LoadSave::BundleFileExists(char const*) / LoadSave::SaveFileExists(char const*) / YYCreateString(RValue*, char const*) / MD5Init(MD5_CTX*) / LoadSave::_GetSaveFileName(char*, int, char const*)
 * 字段偏移 top8: 0x86c×2 / 0x1c0×1 / 0x898×1 / 0x128×1 / 0x8c×1 / 0xc×1 / 0x10×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x157d38 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x157d3c sub sp, sp, #2160
 *   @0x157d40 ldr r8, [pc, #0x1c0]
 *   @0x157d44 sub sp, sp, #4
 *   @0x157d48 mov r1, #0
 *   @0x157d4c mov r9, r0
 *   @0x157d50 ldr r8, [pc, r8]
 *   @0x157d54 ldr r0, [sp, #0x898]
 *   @0x157d58 ldr r3, [r8]
 *   @0x157d5c str r3, [sp, #0x86c]
 *   @0x157d60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x157d64 mov r4, r0
 *   @0x157d68 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x157d6c mov r6, r0
 *   @0x157d70 mov r0, r4
 *   @0x157d74 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x157d78 orr r1, r0, r6
 *   @0x157d7c mov r5, r0
 *   @0x157d80 ands r10, r1, #255
 *   @0x157d84 bne 0x157db0 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x157d88 mov r0, r9
 *   @0x157d8c mov r1, r10
 *   @0x157d90 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x157d94 ldr r2, [sp, #0x86c]
 *   @0x157d98 ldr r3, [r8]
 *   @0x157d9c cmp r2, r3
 *   @0x157da0 bne 0x157f04 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x157da4 add sp, sp, #2160
 *   @0x157da8 add sp, sp, #4
 *   @0x157dac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x157db0 add r6, sp, #16
 *   @0x157db4 sub r10, r6, #12
 *   @0x157db8 mov r0, r10
 *   @0x157dbc bl 0x2140d8 <_Z7MD5InitP7MD5_CTX>
 *   @0x157dc0 cmp r5, #0
 *   @0x157dc4 mov r2, r4
 *   @0x157dc8 beq 0x157e6c <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x157dcc add r7, sp, #108
 *   @0x157dd0 mov r1, #2048
 *   @0x157dd4 mov r0, r7
 *   @0x157dd8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x157ddc ldr r1, [pc, #0x128]
 *   @0x157de0 mov r0, r7
 *   @0x157de4 add r1, pc, r1
 *   @0x157de8 bl 0xb6844 <fopen@plt>
 *   @0x157dec mov r1, #0
 *   @0x157df0 mov r2, #2
 *   @0x157df4 mov r11, r0
 *   @0x157df8 bl 0xb68d4 <fseek@plt>
 *   @0x157dfc mov r0, r11
 *   @0x157e00 bl 0xb68e0 <ftell@plt>
 *   @0x157e04 mov r1, #0
 *   @0x157e08 mov r2, r1
 *   @0x157e0c mov r4, r0
 *   @0x157e10 mov r0, r11
 *   @0x157e14 bl 0xb68d4 <fseek@plt>
 *   @0x157e18 cmp r4, #0
 *   @0x157e1c bne 0x157e3c <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x157e20 b 0x157e60 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x157e24 mov r0, r10
 *   @0x157e28 mov r1, r7
 *   @0x157e2c mov r2, r5
 *   @0x157e30 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj>
 *   @0x157e34 subs r4, r4, r5
 *   @0x157e38 beq 0x157e60 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x157e3c cmp r4, #2048
 *   @0x157e40 movlo r2, r4
 *   @0x157e44 movhs r2, #2048
 *   @0x157e48 mov r0, r7
 *   @0x157e4c mov r1, #1
 *   @0x157e50 mov r3, r11
 *   @0x157e54 bl 0xb68c8 <fread@plt>
 *   @0x157e58 subs r5, r0, #0
 *   @0x157e5c bne 0x157e24 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x157e60 mov r0, r11
 *   @0x157e64 bl 0xb6850 <fclose@plt>
 *   @0x157e68 b 0x157eac <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x157e6c add r4, sp, #108
 *   @0x157e70 mov r1, #2048
 *   @0x157e74 mov r0, r4
 *   @0x157e78 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x157e7c ldr r1, [pc, #0x8c]
 *   @0x157e80 mov r0, r4
 *   @0x157e84 add r1, pc, r1
 *   @0x157e88 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_>
 *   @0x157e8c ldr r3, [r0]
 *   @0x157e90 mov r4, r0
 *   @0x157e94 mov r0, r10
 *   @0x157e98 ldr r1, [r3, #0xc]
 *   @0x157e9c ldr r2, [r3, #0x10]
 *   @0x157ea0 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj>
 *   @0x157ea4 mov r0, r4
 *   @0x157ea8 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE>
 *   @0x157eac mov r0, r10
 *   @0x157eb0 ldr r7, [pc, #0x5c]
 *   @0x157eb4 bl 0x2141d0 <_Z8MD5FinalP7MD5_CTX>
 *   @0x157eb8 ldr r1, [pc, #0x58]
 *   @0x157ebc mov r0, #33
 *   @0x157ec0 movw r2, #0x9c4
 *   @0x157ec4 add r1, pc, r1
 *   @0x157ec8 mov r3, #1
 *   @0x157ecc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x157ed0 add r4, r6, #75
 *   @0x157ed4 add r7, pc, r7
 *   @0x157ed8 add r6, r6, #91
 *   @0x157edc mov r10, r0
 *   @0x157ee0 mov r5, r0
 *   @0x157ee4 ldrb r2, [r4, #0x1]!
 *   @0x157ee8 mov r0, r5
 *   @0x157eec mov r1, r7
 *   @0x157ef0 add r5, r5, #2
 *   @0x157ef4 bl 0xb6550 <sprintf@plt>
 *   @0x157ef8 cmp r4, r6
 *   @0x157efc bne 0x157ee4 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x157f00 b 0x157d88 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x157f04 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x157f08 eoreq r5, r9, r0, lsl #24
 *   @0x157f0c andseq pc, sp, r4, lsl lr
 *   @0x157f10 andseq pc, sp, r4, ror sp
 *   @0x157f14 ldrsbeq r10, [sp], -r0
 *   @0x157f18 andseq lr, lr, r0, lsr #13
 *
 * ══ §4/66 F_YoYo_SHA1File(RValue&, CInstance*, CInstance*, int, RValue*)  0x15815c  size 484  121 条（0x15815c..0x158340）
 * @func 0x15815c 0x158340  size 484  121 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb68d4×2 / SHA1Input(SHA1Context*, unsigned char const*, unsigned int)×2 / YYGetString(RValue const*, int) / LoadSave::BundleFileExists(char const*) / LoadSave::SaveFileExists(char const*) / YYCreateString(RValue*, char const*) / SHA1Reset(SHA1Context*) / LoadSave::_GetSaveFileName(char*, int, char const*)
 * 字段偏移 top8: 0x86c×2 / 0x1c0×1 / 0x898×1 / 0x128×1 / 0x8c×1 / 0xc×1 / 0x10×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15815c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x158160 sub sp, sp, #2160
 *   @0x158164 ldr r6, [pc, #0x1c0]
 *   @0x158168 sub sp, sp, #4
 *   @0x15816c mov r1, #0
 *   @0x158170 mov r9, r0
 *   @0x158174 ldr r6, [pc, r6]
 *   @0x158178 ldr r0, [sp, #0x898]
 *   @0x15817c ldr r3, [r6]
 *   @0x158180 str r3, [sp, #0x86c]
 *   @0x158184 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x158188 mov r4, r0
 *   @0x15818c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x158190 mov r7, r0
 *   @0x158194 mov r0, r4
 *   @0x158198 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x15819c orr r1, r0, r7
 *   @0x1581a0 mov r5, r0
 *   @0x1581a4 ands r7, r1, #255
 *   @0x1581a8 bne 0x1581d4 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x1581ac mov r0, r9
 *   @0x1581b0 mov r1, r7
 *   @0x1581b4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x1581b8 ldr r2, [sp, #0x86c]
 *   @0x1581bc ldr r3, [r6]
 *   @0x1581c0 cmp r2, r3
 *   @0x1581c4 bne 0x158328 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x1581c8 add sp, sp, #2160
 *   @0x1581cc add sp, sp, #4
 *   @0x1581d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1581d4 add r10, sp, #16
 *   @0x1581d8 sub r8, r10, #12
 *   @0x1581dc mov r0, r8
 *   @0x1581e0 bl 0x214294 <_Z9SHA1ResetP11SHA1Context>
 *   @0x1581e4 cmp r5, #0
 *   @0x1581e8 mov r2, r4
 *   @0x1581ec beq 0x158290 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x1581f0 add r7, sp, #108
 *   @0x1581f4 mov r1, #2048
 *   @0x1581f8 mov r0, r7
 *   @0x1581fc bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x158200 ldr r1, [pc, #0x128]
 *   @0x158204 mov r0, r7
 *   @0x158208 add r1, pc, r1
 *   @0x15820c bl 0xb6844 <fopen@plt>
 *   @0x158210 mov r1, #0
 *   @0x158214 mov r2, #2
 *   @0x158218 mov r11, r0
 *   @0x15821c bl 0xb68d4 <fseek@plt>
 *   @0x158220 mov r0, r11
 *   @0x158224 bl 0xb68e0 <ftell@plt>
 *   @0x158228 mov r1, #0
 *   @0x15822c mov r2, r1
 *   @0x158230 mov r4, r0
 *   @0x158234 mov r0, r11
 *   @0x158238 bl 0xb68d4 <fseek@plt>
 *   @0x15823c cmp r4, #0
 *   @0x158240 bne 0x158260 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x158244 b 0x158284 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x158248 mov r0, r8
 *   @0x15824c mov r1, r7
 *   @0x158250 mov r2, r5
 *   @0x158254 bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj>
 *   @0x158258 subs r4, r4, r5
 *   @0x15825c beq 0x158284 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x128>
 *   @0x158260 cmp r4, #2048
 *   @0x158264 movlo r2, r4
 *   @0x158268 movhs r2, #2048
 *   @0x15826c mov r0, r7
 *   @0x158270 mov r1, #1
 *   @0x158274 mov r3, r11
 *   @0x158278 bl 0xb68c8 <fread@plt>
 *   @0x15827c subs r5, r0, #0
 *   @0x158280 bne 0x158248 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x158284 mov r0, r11
 *   @0x158288 bl 0xb6850 <fclose@plt>
 *   @0x15828c b 0x1582d0 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x158290 add r4, sp, #108
 *   @0x158294 mov r1, #2048
 *   @0x158298 mov r0, r4
 *   @0x15829c bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x1582a0 ldr r1, [pc, #0x8c]
 *   @0x1582a4 mov r0, r4
 *   @0x1582a8 add r1, pc, r1
 *   @0x1582ac bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_>
 *   @0x1582b0 ldr r3, [r0]
 *   @0x1582b4 mov r4, r0
 *   @0x1582b8 mov r0, r8
 *   @0x1582bc ldr r1, [r3, #0xc]
 *   @0x1582c0 ldr r2, [r3, #0x10]
 *   @0x1582c4 bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj>
 *   @0x1582c8 mov r0, r4
 *   @0x1582cc bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE>
 *   @0x1582d0 mov r0, r8
 *   @0x1582d4 ldr r8, [pc, #0x5c]
 *   @0x1582d8 bl 0x2146e4 <_Z10SHA1ResultP11SHA1Context>
 *   @0x1582dc ldr r1, [pc, #0x58]
 *   @0x1582e0 mov r0, #45
 *   @0x1582e4 movw r2, #0xa34
 *   @0x1582e8 add r1, pc, r1
 *   @0x1582ec mov r3, #1
 *   @0x1582f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1582f4 sub r4, r10, #16
 *   @0x1582f8 add r8, pc, r8
 *   @0x1582fc add r10, r10, #4
 *   @0x158300 mov r7, r0
 *   @0x158304 mov r5, r0
 *   @0x158308 ldr r2, [r4, #0x4]!
 *   @0x15830c mov r0, r5
 *   @0x158310 mov r1, r8
 *   @0x158314 add r5, r5, #8
 *   @0x158318 bl 0xb6550 <sprintf@plt>
 *   @0x15831c cmp r4, r10
 *   @0x158320 bne 0x158308 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x158324 b 0x1581ac <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x158328 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x15832c .word 0x002957dc
 *   @0x158330 ldrsheq pc, [sp], -r0
 *   @0x158334 andseq pc, sp, r0, asr r9
 *   @0x158338 ldrheq r9, [sp], -r4
 *   @0x15833c andseq lr, lr, r12, ror r2
 *
 * ══ §5/66 png_handle_iTXt  0x2ad850  size 484  121 条（0x2ad850..0x2ada34）
 * @func 0x2ad850 0x2ada34  size 484  121 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning×4 / png_crc_finish×2 / png_error×2 / png_free×2 / png_crc_read / png_handle_iTXt+0xca / 0xb6538 / 0xff57a67c
 * 字段偏移 top8: 0x1a4×1 / 0x15c×1 / 0xdc×1 / 0xc×1 / 0x14×1 / 0x10×1 / 0x8×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ad850 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ad854 mov r4, r0
 *   @0x2ad858 addlt r3, r5, r0, lsl r3
 *   @0x2ad85c mov r10, r1
 *   @0x2ad860 cbz r3, 0x2ad882 <png_handle_iTXt+0x32>
 *   @0x2ad864 beq 0x2ad87a <png_handle_iTXt+0x2a>
 *   @0x2ad868 str.w r3, [r0, #0x310]
 *   @0x2ad86c cmp r3, #0x1
 *   @0x2ad870 ldr r1, [pc, #0x1a4]
 *   @0x2ad874 bl 0x2a6474 <png_warning>
 *   @0x2ad878 mov r0, r4
 *   @0x2ad87c bl 0x2abc94 <png_crc_finish>
 *   @0x2ad880 b 0x2ada10 <png_handle_iTXt+0x1c0>
 *   @0x2ad884 ldrbeq r3, [r9, r12, lsr #2]
 *   @0x2ad888 bmi 0x2ad894 <png_handle_iTXt+0x44>
 *   @0x2ad88c mov r0, r4
 *   @0x2ad890 bl 0x2a642c <png_error>
 *   @0x2ad894 ldr.w r3, [r4, #0x12c]
 *   @0x2ad898 mov r0, r4
 *   @0x2ad89c smmlareq r10, r0, r3, r1
 *   @0x2ad8a0 itt mi
 *   @0x2ad8a4 .word 0xf8c40308
 *   @0x2ad8a8 .word 0xf7f9312c
 *   @0x2ad8ac .word 0x1c69fa27
 *   @0x2ad8b0 mov r0, r4
 *   @0x2ad8b4 .word 0x4601fa30
 *   @0x2ad8b8 str.w r0, [r4, #0x330]
 *   @0x2ad8bc mov r0, r4
 *   @0x2ad8c0 ldr r1, [pc, #0x15c]
 *   @0x2ad8c4 bl 0x2a6474 <png_warning>
 *   @0x2ad8c8 b 0x2ada10 <png_handle_iTXt+0x1c0>
 *   @0x2ad8cc bl 0x2abc0c <png_crc_read>
 *   @0x2ad8d0 mov r0, r4
 *   @0x2ad8d4 bl 0x2abc94 <png_crc_finish>
 *   @0x2ad8d8 cbnz r0, 0x2ad908 <png_handle_iTXt+0xb8>
 *   @0x2ad8dc ldrbpl r3, [r8, #-0x330]
 *   @0x2ad8e0 ldr.w r11, [r4, #0x330]
 *   @0x2ad8e4 mov r2, r11
 *   @0x2ad8e8 adds r2, #0x1
 *   @0x2ad8ec cmp r1, #0x0
 *   @0x2ad8f0 cmp r5, #0x2
 *   @0x2ad8f4 mov r1, r2
 *   @0x2ad8f8 add r2, r11
 *   @0x2ad8fc blo 0x2ad91a <png_handle_iTXt+0xca>
 *   @0x2ad900 mov r0, r4
 *   @0x2ad904 bl 0x2a6474 <png_warning>
 *   @0x2ad908 mov r0, r4
 *   @0x2ad90c .word 0xf7f91330
 *   @0x2ad910 movwhs pc, #0x9f5
 *   @0x2ad914 str.w r3, [r4, #0x330]
 *   @0x2ad918 b 0x2ada10 <png_handle_iTXt+0x1c0>
 *   @0x2ad91c .word 0xf8930803
 *   @0x2ad920 ldmvc r9, {r0, r12, pc}
 *   @0x2ad924 mov r3, r8
 *   @0x2ad928 adds r3, #0x1
 *   @0x2ad92c cmp r2, #0x0
 *   @0x2ad930 add.w r2, r11, r5
 *   @0x2ad934 mov r7, r3
 *   @0x2ad938 bhs 0x2ad8fe <png_handle_iTXt+0xae>
 *   @0x2ad93c adds r3, #0x1
 *   @0x2ad940 cmp r6, #0x0
 *   @0x2ad944 cmp r3, r2
 *   @0x2ad948 ldr r1, [pc, #0xdc]
 *   @0x2ad94c add r1, pc
 *   @0x2ad950 qadd8mi pc, r0, r1
 *   @0x2ad954 ldr.w r1, [r4, #0x330]
 *   @0x2ad958 bl 0x2a6cfc <png_free>
 *   @0x2ad95c str.w r6, [r4, #0x330]
 *   @0x2ad960 b 0x2ada10 <png_handle_iTXt+0x1c0>
 *   @0x2ad964 .word 0xf1b90603
 *   @0x2ad968 andle r0, r7, r0, lsl #30
 *   @0x2ad96c add r3, sp, #0xc
 *   @0x2ad970 str r3, [sp]
 *   @0x2ad974 mov r3, r6
 *   @0x2ad978 and pc, r4, r7, asr #19
 *   @0x2ad97c add.w r0, r11, r6
 *   @0x2ad980 blx 0xb6538 <strlen@plt>
 *   @0x2ad984 str r0, [sp, #0xc]
 *   @0x2ad988 movs r1, #0x1c
 *   @0x2ad98c strmi pc, [r5], -r4, asr #19
 *   @0x2ad990 cbnz r0, 0x2ad9ac <png_handle_iTXt+0x15c>
 *   @0x2ad994 mov r0, r4
 *   @0x2ad998 bl 0x2a6474 <png_warning>
 *   @0x2ad99c mov r0, r4
 *   @0x2ad9a0 .word 0xf7f91330
 *   @0x2ad9a4 .word 0xf8c4f9ab
 *   @0x2ad9a8 eors r5, r1, r0, lsr r3
 *   @0x2ad9ac add.w r3, r9, #0x1
 *   @0x2ad9b0 str r3, [r0]
 *   @0x2ad9b4 bl 0xff57a67c <b2_toiTime+0xfffffffffee211d8>
 *   @0x2ad9b8 bl 0xff56f5dc <b2_toiTime+0xfffffffffee16138>
 *   @0x2ad9bc strtmi r0, [r10], -r8, lsl #16
 *   @0x2ad9c0 add r3, r7
 *   @0x2ad9c4 ldr.w r3, [r4, #0x330]
 *   @0x2ad9c8 movs r7, #0x0
 *   @0x2ad9cc mov r1, r10
 *   @0x2ad9d0 str r3, [r0, #0x14]
 *   @0x2ad9d4 str r3, [r0, #0x10]
 *   @0x2ad9d8 subvs r3, r3, r0, lsr r3
 *   @0x2ad9dc ldr.w r3, [r4, #0x330]
 *   @0x2ad9e0 add r6, r3
 *   @0x2ad9e4 str r6, [r0, #0x8]
 *   @0x2ad9e8 bl 0x2aeef8 <png_set_text_2>
 *   @0x2ad9ec mov r1, r5
 *   @0x2ad9f0 mov r0, r4
 *   @0x2ad9f4 strtmi pc, [r0], -r3, lsl #19
 *   @0x2ad9f8 ldr.w r1, [r4, #0x330]
 *   @0x2ad9fc bl 0x2a6cfc <png_free>
 *   @0x2ada00 str.w r7, [r4, #0x330]
 *   @0x2ada04 cbz r6, 0x2ada10 <png_handle_iTXt+0x1c0>
 *   @0x2ada08 mov r0, r4
 *   @0x2ada0c bl 0x2a642c <png_error>
 *   @0x2ada10 add sp, #0x14
 *   @0x2ada14 svclt #0x8ff0
 *   @0x2ada18 lsls r6, r1, #0x1
 *   @0x2ada1c lsls r3, r2, #0x1
 *   @0x2ada20 movs r0, r7
 *   @0x2ada24 movs r0, r3
 *   @0x2ada28 vaddl.u32 q8, d3, d13
 *   @0x2ada2c vaddl.u32 q0, d14, d13
 *   @0x2ada30 vhadd.u32 d16, d2, d13
 *
 * ══ §6/66 anon_2b0f3e  0x2b0f3e  size 484  121 条（0x2b0f3e..0x2b1122）
 * @func 0x2b0f3e 0x2b1122  size 484  121 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xc6e796 / 0x20aef5e / anon_2bc92c+0xbbe / 0x8024fa / anon_2bc92c+0xc0a
 * 字段偏移 top8: 无
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0f3e .word 0x468947f0
 *   @0x2b0f42 addlt r4, lr, r4, ror pc
 *   @0x2b0f46 strmi r2, [r4], -r0, lsl #12
 *   @0x2b0f4a ldmdavs pc!, {r0, r1, r2, r3, r4, r5, r6, r10, lr}
 *   @0x2b0f4e .word 0x46909d16
 *   @0x2b0f52 adcvs r6, lr, r9, lsr r8
 *   @0x2b0f56 smlattls sp, lr, r0, r6
 *   @0x2b0f5a qsubvs r1, r9, lr
 *   @0x2b0f5e rsbvs r6, lr, lr, lsr #32
 *   @0x2b0f62 .word 0xf8c5d104
 *   @0x2b0f66 .word 0xf8c59000
 *   @0x2b0f6a sbc r8, r7, r4
 *   @0x2b0f6e vstrle d2, [r9, #-8]
 *   @0x2b0f72 teqhs r2, r9, ror #20
 *   @0x2b0f76 ldrbtmi r4, [r10], #-1640
 *   @0x2b0f7a bl 0xc6e796 <b2_toiTime+0x5152f2>
 *   @0x2b0f7e strbtmi r4, [r9], -r0, lsr #12
 *   @0x2b0f82 blx 0x20aef5e <b2_toiTime+0x1955aba>
 *   @0x2b0f86 ldrsblo pc, [r4, #-132]!
 *   @0x2b0f8a ldrsbge pc, [r0, pc]
 *   @0x2b0f8e teqhi r12, r4, asr #17
 *   @0x2b0f92 ldmvc r12, {r2, r8, r10, r12, sp, lr, pc}
 *   @0x2b0f96 smlalbtlo pc, r8, r4, r8
 *   @0x2b0f9a .word 0xf8d444fa
 *   @0x2b0f9e .word 0xf8c43170
 *   @0x2b0fa2 .word 0xf8c49138
 *   @0x2b0fa6 strbmi r3, [r0], -r4, asr #2
 *   @0x2b0faa .word 0xf6052100
 *   @0x2b0fae ldrshlt lr, [r0, -lr]!
 *   @0x2b0fb2 ldrsbne pc, [r0, #-132]
 *   @0x2b0fb6 stmdblt r1, {r5, r9, r10, lr}
 *   @0x2b0fba .word 0xf7f54651
 *   @0x2b0fbe .word 0xf8d4fa36
 *   @0x2b0fc2 blhs 0x2bd4ea <jpeg_alloc_huff_table+0xbe2>
 *   @0x2b0fc6 stmvs r9!, {r0, r3, r4, r5, r8, r12, lr, pc}
 *   @0x2b0fca .word 0x900cf8d5
 *   @0x2b0fce blle 0x8024fa <b2_toiTime+0xa9056>
 *   @0x2b0fd2 stmdbvs lr!, {r2, r8, r12, sp}
 *   @0x2b0fd6 strtmi r6, [r0], -r9, ror #1
 *   @0x2b0fda smulbblt r6, r9, r0
 *   @0x2b0fde mrc2 p7, #0x2, apsr_nzcv, c15, c5, #0x7
 *   @0x2b0fe2 b 0x16828ae <b2_toiTime+0xf2940a>
 *   @0x2b0fe6 smlawbvs r8, r9, r2, r0
 *   @0x2b0fea b 0xffcee806 <b2_toiTime+0xffffffffff595362>
 *   @0x2b0fee ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2b0ff2 mcr2 p7, #0x4, pc, c3, c5, #0x7
 *   @0x2b0ff6 .word 0xf7f5e002
 *   @0x2b0ffa qsubvs pc, r2, r8
 *   @0x2b0ffe ldrsbne pc, [r4, #-132]!
 *   @0x2b1002 .word 0xf8d54620
 *   @0x2b1006 stmdbvs lr!, {r3, r12, pc}
 *   @0x2b100a mcr2 p7, #0x2, pc, c9, c5, #0x7
 *   @0x2b100e eoreq pc, r9, r6, asr #16
 *   @0x2b1012 stmdbvs r11!, {r1, r3, r5, r7, r11, sp, lr}
 *   @0x2b1016 ldrsbne pc, [r0, #-132]!
 *   @0x2b101a eoreq pc, r2, r3, asr r8
 *   @0x2b101e ldrsbhs pc, [r4, #-132]!
 *   @0x2b1022 b 0xff5ee83e <b2_toiTime+0xfffffffffee9539a>
 *   @0x2b1026 movwlo r6, #0x18ab
 *   @0x2b102a .word 0xf8d460ab
 *   @0x2b102e .word 0xf8c43174
 *   @0x2b1032 .word 0xf8d43148
 *   @0x2b1036 .word 0xf8c43170
 *   @0x2b103a .word 0xf8d43144
 *   @0x2b103e blhs 0x2bd536 <jpeg_alloc_huff_table+0xc2e>
 *   @0x2b1042 .word 0xf8dfd1b1
 *   @0x2b1046 ldrbtmi r10, [r10], #216
 *   @0x2b104a .word 0x21044640
 *   @0x2b104e stc p6, c15, [lr], #20
 *   @0x2b1052 teqle lr, r0, lsl #16
 *   @0x2b1056 .word 0x3148f8d4
 *   @0x2b105a mvnsle r2, r0, lsl #22
 *   @0x2b105e .word 0xf8d568a9
 *   @0x2b1062 strbmi r9, [r9, #-0xc]
 *   @0x2b1066 .word 0x3104db15
 *   @0x2b106a rscvs r6, r9, lr, lsr #18
 *   @0x2b106e addeq r4, r9, r0, lsr #12
 *   @0x2b1072 .word 0xf7f5b166
 *   @0x2b1076 shadd16mi pc, r1, r4
 *   @0x2b107a addeq lr, r9, #323584
 *   @0x2b107e .word 0xf6056128
 *   @0x2b1082 qadd8mi lr, r0, r12
 *   @0x2b1086 .word 0xf7f54631
 *   @0x2b108a and pc, r2, r8, lsr lr
 *   @0x2b108e mcr2 p7, #0x0, pc, c7, c5, #0x7
 *   @0x2b1092 .word 0xf8d46128
 *   @0x2b1096 qsub16mi r1, r0, r4
 *   @0x2b109a .word 0x9008f8d5
 *   @0x2b109e .word 0xf7f5692e
 *   @0x2b10a2 .word 0xf846fdfe
 *   @0x2b10a6 stmvs r10!, {r0, r3, r5}
 *   @0x2b10aa .word 0xf8d4692b
 *   @0x2b10ae .word 0xf8531170
 *   @0x2b10b2 .word 0xf8d40022
 *   @0x2b10b6 .word 0xf6052174
 *   @0x2b10ba stmvs r11!, {r7, r9, r11, sp, lr, pc}
 *   @0x2b10be adcvs r3, r11, r1, lsl #6
 *   @0x2b10c2 ldrsblo pc, [r4, #-132]!
 *   @0x2b10c6 smlalbtlo pc, r8, r4, r8
 *   @0x2b10ca ldrsblo pc, [r0, #-132]!
 *   @0x2b10ce smlalbtlo pc, r4, r4, r8
 *   @0x2b10d2 stmdahs r1, {r1, r3, r4, r5, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2b10d6 .word 0xf8d4d007
 *   @0x2b10da qsaxmi r1, r0, r0
 *   @0x2b10de ldrbmi r11, [r1], -r1, lsl #18
 *   @0x2b10e2 .word 0xf9a3f7f5
 *   @0x2b10e6 .word 0xf8d4e7b0
 *   @0x2b10ea stmvs r10!, {r2, r4, r5, r6, r8, r12, sp}
 *   @0x2b10ee .word 0xf803fb02
 *   @0x2b10f2 .word 0x2148f8d4
 *   @0x2b10f6 andle r4, r1, #-1610612727
 *   @0x2b10fa ldrmi r1, [r8], #2715
 *   @0x2b10fe strbmi r9, [r0], -sp, lsl #20
 *   @0x2b1102 addsmi r6, r10, #3866624
 *   @0x2b1106 .word 0xf605d001
 *   @0x2b110a andlt lr, lr, r4, ror #20
 *   @0x2b110e .word 0x87f0e8bd
 *   @0x2b1112 bgt 0x560d1a <g_SWFlineaavertbuff+0xdc52>
 *   @0x2b1116 cmnle r7, r3, lsl r0
 *   @0x2b111a svcgt #0xe3000d
 *   @0x2b111e svcgt #0x35000d
 *
 * ══ §7/66 C3D_Model::SaveToBuffer(int)  0x1646f4  size 480  120 条（0x1646f4..0x1648d4）
 * @func 0x1646f4 0x1648d4  size 480  120 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65c8×3 / IBuffer::Write(char const*)×3 / GetIBuffer(int) / C3D_Model::SaveToBuffer(int)+0x17c / 0xb65d4
 * 字段偏移 top8: 0x854×2 / 0x1c0×1 / 0x198×1 / 0x184×1 / 0x8×1 / 0x2×1 / 0x10×1
 * VFP 指令 36 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1646f4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1646f8 vpush {d8, d9}
 *   @0x1646fc sub sp, sp, #2128
 *   @0x164700 ldr r8, [pc, #0x1c0]
 *   @0x164704 sub sp, sp, #12
 *   @0x164708 mov r9, r0
 *   @0x16470c mov r0, r1
 *   @0x164710 ldr r8, [pc, r8]
 *   @0x164714 ldr r3, [r8]
 *   @0x164718 str r3, [sp, #0x854]
 *   @0x16471c bl 0xc6720 <_Z10GetIBufferi>
 *   @0x164720 subs r6, r0, #0
 *   @0x164724 moveq r0, r6
 *   @0x164728 beq 0x16488c <_ZN9C3D_Model12SaveToBufferEi+0x198>
 *   @0x16472c ldr r4, [pc, #0x198]
 *   @0x164730 add r5, sp, #84
 *   @0x164734 mov r3, #100
 *   @0x164738 mov r1, #2048
 *   @0x16473c add r4, pc, r4
 *   @0x164740 mov r0, r5
 *   @0x164744 ldr r7, [pc, #0x184]
 *   @0x164748 mov r2, r4
 *   @0x16474c bl 0xb65c8 <snprintf@plt>
 *   @0x164750 mov r1, r5
 *   @0x164754 mov r0, r6
 *   @0x164758 add r7, pc, r7
 *   @0x16475c bl 0xcddb8 <_ZN7IBuffer5WriteEPKc>
 *   @0x164760 mov r2, r4
 *   @0x164764 ldr r3, [r9]
 *   @0x164768 mov r1, #2048
 *   @0x16476c mov r0, r5
 *   @0x164770 mov r4, #0
 *   @0x164774 bl 0xb65c8 <snprintf@plt>
 *   @0x164778 mov r0, r6
 *   @0x16477c mov r1, r5
 *   @0x164780 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc>
 *   @0x164784 ldr r3, [r9]
 *   @0x164788 cmp r3, #0
 *   @0x16478c ble 0x164870 <_ZN9C3D_Model12SaveToBufferEi+0x17c>
 *   @0x164790 ldr r3, [r9, #0x8]
 *   @0x164794 ldr r12, [r3, r4, lsl #2]
 *   @0x164798 vldr s18, [r12, #4]
 *   @0x16479c vldr s16, [r12, #8]
 *   @0x1647a0 vldr s0, [r12, #12]
 *   @0x1647a4 vldr s2, [r12, #16]
 *   @0x1647a8 vldr s4, [r12, #20]
 *   @0x1647ac ldr r3, [r12]
 *   @0x1647b0 vldr s6, [r12, #24]
 *   @0x1647b4 vldr s8, [r12, #28]
 *   @0x1647b8 vldr s10, [r12, #32]
 *   @0x1647bc sub lr, r3, #3
 *   @0x1647c0 vldr s12, [r12, #36]
 *   @0x1647c4 vldr s14, [r12, #40]
 *   @0x1647c8 cmp lr, #6
 *   @0x1647cc addls pc, pc, lr, lsl #2
 *   @0x1647d0 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100>
 *   @0x1647d4 b 0x1648ac <_ZN9C3D_Model12SaveToBufferEi+0x1b8>
 *   @0x1647d8 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100>
 *   @0x1647dc b 0x1648bc <_ZN9C3D_Model12SaveToBufferEi+0x1c8>
 *   @0x1647e0 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100>
 *   @0x1647e4 b 0x1648b4 <_ZN9C3D_Model12SaveToBufferEi+0x1c0>
 *   @0x1647e8 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100>
 *   @0x1647ec b 0x1647f0 <_ZN9C3D_Model12SaveToBufferEi+0xfc>
 *   @0x1647f0 vcvt.f32.s32 s12, s12
 *   @0x1647f4 mov r1, #2048
 *   @0x1647f8 mov r2, r7
 *   @0x1647fc mov r0, r5
 *   @0x164800 add r4, r4, #1
 *   @0x164804 vcvt.f64.f32 d0, s0
 *   @0x164808 vcvt.f64.f32 d1, s2
 *   @0x16480c vstr d0, [sp, #16]
 *   @0x164810 vcvt.f64.f32 d2, s4
 *   @0x164814 vstr d1, [sp, #24]
 *   @0x164818 vcvt.f64.f32 d3, s6
 *   @0x16481c vstr d2, [sp, #32]
 *   @0x164820 vcvt.f64.f32 d4, s8
 *   @0x164824 vstr d3, [sp, #40]
 *   @0x164828 vcvt.f64.f32 d5, s10
 *   @0x16482c vstr d4, [sp, #48]
 *   @0x164830 vcvt.f64.f32 d6, s12
 *   @0x164834 vstr d5, [sp, #56]
 *   @0x164838 vcvt.f64.f32 d7, s14
 *   @0x16483c vstr d6, [sp, #64]
 *   @0x164840 vcvt.f64.f32 d9, s18
 *   @0x164844 vstr d7, [sp, #72]
 *   @0x164848 vcvt.f64.f32 d8, s16
 *   @0x16484c vstr d9, [sp]
 *   @0x164850 vstr d8, [sp, #8]
 *   @0x164854 bl 0xb65c8 <snprintf@plt>
 *   @0x164858 mov r0, r6
 *   @0x16485c mov r1, r5
 *   @0x164860 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc>
 *   @0x164864 ldr r3, [r9]
 *   @0x164868 cmp r3, r4
 *   @0x16486c bgt 0x164790 <_ZN9C3D_Model12SaveToBufferEi+0x9c>
 *   @0x164870 ldr r3, [r6]
 *   @0x164874 mov r1, #0
 *   @0x164878 mov r0, r6
 *   @0x16487c mov r2, r1
 *   @0x164880 ldr r3, [r3, #0x10]
 *   @0x164884 blx r3
 *   @0x164888 mov r0, #1
 *   @0x16488c ldr r2, [sp, #0x854]
 *   @0x164890 ldr r3, [r8]
 *   @0x164894 cmp r2, r3
 *   @0x164898 bne 0x1648c4 <_ZN9C3D_Model12SaveToBufferEi+0x1d0>
 *   @0x16489c add sp, sp, #2128
 *   @0x1648a0 add sp, sp, #12
 *   @0x1648a4 vpop {d8, d9}
 *   @0x1648a8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1648ac vcvt.f32.s32 s2, s2
 *   @0x1648b0 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100>
 *   @0x1648b4 vcvt.f32.s32 s8, s8
 *   @0x1648b8 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100>
 *   @0x1648bc vcvt.f32.s32 s6, s6
 *   @0x1648c0 b 0x1647f4 <_ZN9C3D_Model12SaveToBufferEi+0x100>
 *   @0x1648c4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1648c8 eoreq r9, r8, r0, asr #4
 *   @0x1648cc andseq r5, lr, r0, asr #28
 *   @0x1648d0 andseq r5, lr, r0, lsr lr
 *
 * ══ §8/66 HalfTextureRGBA(int, int, unsigned int*, int, int, unsigned int*)  0x18923c  size 480  120 条（0x18923c..0x18941c）
 * @func 0x18923c 0x18941c  size 480  120 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×2 / HalfTextureRGBA(int, int, unsigned int*, int, int, unsigned int*)+0x1b8 / HalfTextureRGBA(int, int, unsigned int*, int, int, unsigned int*)+0x18c
 * 字段偏移 top8: 0x1c×6 / 0x2c×4 / 0x14×4 / 0x10×4 / 0xc×4 / 0x4×4 / 0x20×3 / 0x18×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18923c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x189240 sub sp, sp, #52
 *   @0x189244 mov r4, r2
 *   @0x189248 mov r11, r3
 *   @0x18924c ldr r12, [sp, #0x58]
 *   @0x189250 str r0, [sp, #0x1c]
 *   @0x189254 str r1, [sp, #0x2c]
 *   @0x189258 lsl r0, r12, #16
 *   @0x18925c bl 0x318d10 <__divsi3>
 *   @0x189260 ldr r2, [sp, #0x2c]
 *   @0x189264 cmp r2, #0
 *   @0x189268 str r0, [sp, #0x24]
 *   @0x18926c ble 0x1893f4 <_Z15HalfTextureRGBAiiPjiiS_+0x1b8>
 *   @0x189270 lsl r0, r11, #16
 *   @0x189274 ldr r1, [sp, #0x1c]
 *   @0x189278 bl 0x318d10 <__divsi3>
 *   @0x18927c ldr r2, [sp, #0x2c]
 *   @0x189280 ldr r3, [sp, #0x1c]
 *   @0x189284 str r4, [sp, #0x14]
 *   @0x189288 mul r3, r3, r2
 *   @0x18928c ldr r2, [sp, #0x1c]
 *   @0x189290 lsl r2, r2, #2
 *   @0x189294 str r2, [sp, #0x20]
 *   @0x189298 str r3, [sp, #0x28]
 *   @0x18929c mov r3, #0
 *   @0x1892a0 str r3, [sp, #0x10]
 *   @0x1892a4 str r3, [sp, #0x18]
 *   @0x1892a8 str r3, [sp, #0xc]
 *   @0x1892ac str r0, [sp, #0x8]
 *   @0x1892b0 ldr r3, [sp, #0xc]
 *   @0x1892b4 ldr r2, [sp, #0x1c]
 *   @0x1892b8 asr r12, r3, #16
 *   @0x1892bc cmp r2, #0
 *   @0x1892c0 ldr r3, [sp, #0x5c]
 *   @0x1892c4 mul r12, r11, r12
 *   @0x1892c8 add r12, r3, r12, lsl #2
 *   @0x1892cc ble 0x1893c8 <_Z15HalfTextureRGBAiiPjiiS_+0x18c>
 *   @0x1892d0 ldr r3, [sp, #0x14]
 *   @0x1892d4 mov r4, #0
 *   @0x1892d8 ldr r2, [sp, #0x20]
 *   @0x1892dc mov r5, r3
 *   @0x1892e0 add r2, r2, r3
 *   @0x1892e4 str r2, [sp, #0x4]
 *   @0x1892e8 asr r3, r4, #16
 *   @0x1892ec ldr r2, [sp, #0x8]
 *   @0x1892f0 add r1, r12, r3, lsl #2
 *   @0x1892f4 add r4, r4, r2
 *   @0x1892f8 add r2, r3, r11
 *   @0x1892fc ldr r1, [r1, #0x4]
 *   @0x189300 add r8, r2, #1
 *   @0x189304 ldr r0, [r12, r2, lsl #2]
 *   @0x189308 ldr r2, [r12, r3, lsl #2]
 *   @0x18930c and r7, r1, #65280
 *   @0x189310 ldr r3, [r12, r8, lsl #2]
 *   @0x189314 and r6, r0, #65280
 *   @0x189318 and r8, r0, #16711680
 *   @0x18931c add r6, r7, r6
 *   @0x189320 and r10, r1, #16711680
 *   @0x189324 and r7, r2, #65280
 *   @0x189328 add r10, r10, r8
 *   @0x18932c add r6, r6, r7
 *   @0x189330 and r8, r2, #16711680
 *   @0x189334 and r7, r3, #65280
 *   @0x189338 add r10, r10, r8
 *   @0x18933c add r6, r6, r7
 *   @0x189340 lsr r8, r1, #8
 *   @0x189344 lsr r7, r0, #8
 *   @0x189348 and r8, r8, #16711680
 *   @0x18934c and r7, r7, #16711680
 *   @0x189350 and r9, r3, #16711680
 *   @0x189354 add r7, r8, r7
 *   @0x189358 lsr r8, r2, #8
 *   @0x18935c add r9, r10, r9
 *   @0x189360 uxtb r0, r0
 *   @0x189364 lsr r10, r3, #8
 *   @0x189368 and r8, r8, #16711680
 *   @0x18936c uxtab r0, r0, r1
 *   @0x189370 and r10, r10, #16711680
 *   @0x189374 add r8, r7, r8
 *   @0x189378 lsr r6, r6, #2
 *   @0x18937c lsr r9, r9, #2
 *   @0x189380 uxtab r0, r0, r2
 *   @0x189384 add r10, r8, r10
 *   @0x189388 and r6, r6, #65280
 *   @0x18938c and r9, r9, #16711680
 *   @0x189390 uxtab r3, r0, r3
 *   @0x189394 orr r9, r6, r9
 *   @0x189398 lsl r10, r10, #6
 *   @0x18939c orr r3, r9, r3, lsr #2
 *   @0x1893a0 and r10, r10, #-16777216
 *   @0x1893a4 orr r3, r3, r10
 *   @0x1893a8 str r3, [r5], #4
 *   @0x1893ac ldr r3, [sp, #0x4]
 *   @0x1893b0 cmp r3, r5
 *   @0x1893b4 bne 0x1892e8 <_Z15HalfTextureRGBAiiPjiiS_+0xac>
 *   @0x1893b8 ldr r2, [sp, #0x10]
 *   @0x1893bc ldr r3, [sp, #0x1c]
 *   @0x1893c0 add r2, r2, r3
 *   @0x1893c4 str r2, [sp, #0x10]
 *   @0x1893c8 ldr r2, [sp, #0x28]
 *   @0x1893cc ldr r3, [sp, #0x10]
 *   @0x1893d0 cmp r2, r3
 *   @0x1893d4 ldr r2, [sp, #0xc]
 *   @0x1893d8 ldr r3, [sp, #0x24]
 *   @0x1893dc add r2, r2, r3
 *   @0x1893e0 str r2, [sp, #0xc]
 *   @0x1893e4 ldr r2, [sp, #0x18]
 *   @0x1893e8 add r2, r2, #1
 *   @0x1893ec str r2, [sp, #0x18]
 *   @0x1893f0 bge 0x1893fc <_Z15HalfTextureRGBAiiPjiiS_+0x1c0>
 *   @0x1893f4 add sp, sp, #52
 *   @0x1893f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1893fc ldr r3, [sp, #0x2c]
 *   @0x189400 cmp r3, r2
 *   @0x189404 ldr r2, [sp, #0x14]
 *   @0x189408 ldr r3, [sp, #0x20]
 *   @0x18940c add r2, r2, r3
 *   @0x189410 str r2, [sp, #0x14]
 *   @0x189414 bgt 0x1892b0 <_Z15HalfTextureRGBAiiPjiiS_+0x74>
 *   @0x189418 b 0x1893f4 <_Z15HalfTextureRGBAiiPjiiS_+0x1b8>
 *
 * ══ §9/66 Audio_Unqueue_Processed_Buffers(CNoise*, int, bool)  0x219e68  size 480  118 条（0x219e68..0x21a048）
 * @func 0x219e68 0x21a048  size 480  118 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6a9c×2 / Audio_Unqueue_Processed_Buffers(CNoise*, int, bool)+0x19c / 0xb6b08 / Audio_Unqueue_Processed_Buffers(CNoise*, int, bool)+0x114 / Audio_GetSound(int) / CreateDsMap(int, ...) / CreateAsynEventWithDSMap(int, int) / Audio_FreeBufferSound(int)
 * 字段偏移 top8: 0x10×3 / 0x34×2 / 0x2c×2 / 0x2×2 / 0x44×2 / 0x38×2 / 0x3c×2 / 0x4c×2
 * VFP 指令 12 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x219e68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x219e6c vpush {d8, d9}
 *   @0x219e70 subs r8, r0, #0
 *   @0x219e74 sub sp, sp, #84
 *   @0x219e78 vmov s18, r1
 *   @0x219e7c str r2, [sp, #0x34]
 *   @0x219e80 beq 0x21a004 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x19c>
 *   @0x219e84 ldr r6, [pc, #0x1a4]
 *   @0x219e88 add r2, sp, #80
 *   @0x219e8c ldr r4, [r8, #0x10]
 *   @0x219e90 mvn r5, #0
 *   @0x219e94 ldr r6, [pc, r6]
 *   @0x219e98 str r5, [r2, #-0xc]!
 *   @0x219e9c movw r1, #0x1016
 *   @0x219ea0 ldr r3, [r6]
 *   @0x219ea4 lsl r12, r4, #2
 *   @0x219ea8 str r12, [sp, #0x2c]
 *   @0x219eac ldr r0, [r3, r4, lsl #2]
 *   @0x219eb0 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x219eb4 ldr r3, [r6]
 *   @0x219eb8 add r2, sp, #80
 *   @0x219ebc movw r1, #0x1015
 *   @0x219ec0 str r5, [r2, #-0x8]!
 *   @0x219ec4 ldr r0, [r3, r4, lsl #2]
 *   @0x219ec8 bl 0xb6a9c <alGetSourcei@plt>
 *   @0x219ecc ldr r3, [sp, #0x44]
 *   @0x219ed0 cmp r3, #0
 *   @0x219ed4 ble 0x21a004 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x19c>
 *   @0x219ed8 ldr r11, [pc, #0x154]
 *   @0x219edc movw r9, #0x869f
 *   @0x219ee0 ldr r4, [pc, #0x150]
 *   @0x219ee4 movt r9, #0x1
 *   @0x219ee8 ldr r12, [pc, #0x14c]
 *   @0x219eec add r11, pc, r11
 *   @0x219ef0 add r4, pc, r4
 *   @0x219ef4 mov r5, #0
 *   @0x219ef8 add r12, pc, r12
 *   @0x219efc str r12, [sp, #0x38]
 *   @0x219f00 add r12, sp, #76
 *   @0x219f04 str r12, [sp, #0x30]
 *   @0x219f08 ldr r12, [pc, #0x130]
 *   @0x219f0c vldr d8, [pc, #276]
 *   @0x219f10 add r12, pc, r12
 *   @0x219f14 str r12, [sp, #0x3c]
 *   @0x219f18 ldr r3, [r6]
 *   @0x219f1c mov r7, #0
 *   @0x219f20 ldr r12, [sp, #0x2c]
 *   @0x219f24 mov r1, #1
 *   @0x219f28 str r7, [sp, #0x4c]
 *   @0x219f2c add r2, sp, #76
 *   @0x219f30 ldr r0, [r3, r12]
 *   @0x219f34 bl 0xb6b08 <alSourceUnqueueBuffers@plt>
 *   @0x219f38 ldr r3, [r11, #0x28]
 *   @0x219f3c cmp r3, r7
 *   @0x219f40 ble 0x219f7c <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x114>
 *   @0x219f44 add r10, r7, #99328
 *   @0x219f48 add r7, r7, #1
 *   @0x219f4c add r10, r10, #672
 *   @0x219f50 mov r0, r10
 *   @0x219f54 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x219f58 cmp r0, #0
 *   @0x219f5c beq 0x219f70 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x108>
 *   @0x219f60 ldr r2, [r0, #0x18]
 *   @0x219f64 ldr r3, [sp, #0x4c]
 *   @0x219f68 cmp r2, r3
 *   @0x219f6c beq 0x21a010 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x1a8>
 *   @0x219f70 ldr r3, [r4, #0x28]
 *   @0x219f74 cmp r3, r7
 *   @0x219f78 bgt 0x219f44 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0xdc>
 *   @0x219f7c mvn r7, #0
 *   @0x219f80 ldr r3, [r8, #0x18]
 *   @0x219f84 sub r3, r3, #199680
 *   @0x219f88 sub r3, r3, #320
 *   @0x219f8c cmp r3, r9
 *   @0x219f90 bhi 0x219ff4 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x18c>
 *   @0x219f94 vmov.f64 d7, #1.000000e+00
 *   @0x219f98 ldr r12, [sp, #0x34]
 *   @0x219f9c vmov s11, r7
 *   @0x219fa0 ldr r2, [pc, #0x9c]
 *   @0x219fa4 cmp r12, #0
 *   @0x219fa8 ldr r12, [sp, #0x3c]
 *   @0x219fac mov r3, #0
 *   @0x219fb0 add r2, pc, r2
 *   @0x219fb4 ldr r1, [sp, #0x38]
 *   @0x219fb8 mov r0, #3
 *   @0x219fbc str r2, [sp, #0x14]
 *   @0x219fc0 str r3, [sp]
 *   @0x219fc4 str r3, [sp, #0x10]
 *   @0x219fc8 str r3, [sp, #0x20]
 *   @0x219fcc str r12, [sp, #0x4]
 *   @0x219fd0 vmoveq.f64 d7, d8
 *   @0x219fd4 vstr d7, [sp, #24]
 *   @0x219fd8 vcvt.f64.s32 d6, s11
 *   @0x219fdc vcvt.f64.s32 d7, s18
 *   @0x219fe0 vstr d6, [sp, #8]
 *   @0x219fe4 vmov r2, r3, d7
 *   @0x219fe8 bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0x219fec mov r1, #74
 *   @0x219ff0 bl 0x18da04 <_Z24CreateAsynEventWithDSMapii>
 *   @0x219ff4 ldr r3, [sp, #0x44]
 *   @0x219ff8 add r5, r5, #1
 *   @0x219ffc cmp r3, r5
 *   @0x21a000 bgt 0x219f18 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0xb0>
 *   @0x21a004 add sp, sp, #84
 *   @0x21a008 vpop {d8, d9}
 *   @0x21a00c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21a010 mov r2, r0
 *   @0x21a014 mov r0, r10
 *   @0x21a018 ldr r7, [r2, #0x10]
 *   @0x21a01c bl 0x219d70 <_Z21Audio_FreeBufferSoundi>
 *   @0x21a020 b 0x219f80 <_Z31Audio_Unqueue_Processed_BuffersP6CNoiseib+0x118>
 *   @0x21a024 nop
 *   @0x21a030 andseq r7, sp, r8, lsr r5
 *   @0x21a034 subseq r11, r3, r8, lsr #7
 *   @0x21a038 subseq r11, r3, r4, lsr #7
 *   @0x21a03c andseq r10, r3, r0, asr #1
 *   @0x21a040 ldrheq r10, [r3], -r4
 *   @0x21a044 andseq r10, r3, r0, lsr #32
 *
 * ══ §10/66 JS_Array_prototype_reduce(RValue&, CInstance*, CInstance*, int, RValue*)  0x251d84  size 480  120 条（0x251d84..0x251f64）
 * @func 0x251d84 0x251f64  size 480  120 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×4 / JSThrowTypeError(char const*)×2 / JS_Array_prototype_reduce(RValue&, CInstance*, CInstance*, int, RValue*)+0x16c / JS_IsCallable(RValue&) / F_JSNewArray_NoArguments(RValue&, CInstance*, CInstance*, int, RValue*) / JS_Array_prototype_reduce(RValue&, CInstance*, CInstance*, int, RValue*)+0x150 / Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*) / JS_Array_prototype_reduce(RValue&, CInstance*, CInstance*, int, RValue*)+0x190
 * 字段偏移 top8: 0xc×5 / 0x4×4 / 0x98×3 / 0x24×1 / 0x5c×1 / 0x6c×1 / 0x60×1 / 0x64×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x251d84 ldr r12, [r1, #0x4]
 *   @0x251d88 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x251d8c cmp r12, #0
 *   @0x251d90 sub sp, sp, #116
 *   @0x251d94 mov r5, r3
 *   @0x251d98 mov r6, r1
 *   @0x251d9c mov r3, #5
 *   @0x251da0 str r0, [sp, #0xc]
 *   @0x251da4 mov r7, r2
 *   @0x251da8 str r3, [r0, #0xc]
 *   @0x251dac beq 0x251f3c <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x251db0 add r0, r12, #16
 *   @0x251db4 ldr r11, [r0]
 *   @0x251db8 cmp r5, #0
 *   @0x251dbc ldr r9, [r11, #0x24]
 *   @0x251dc0 ble 0x251ef0 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x251dc4 ldr r0, [sp, #0x98]
 *   @0x251dc8 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x251dcc cmp r0, #0
 *   @0x251dd0 beq 0x251ef0 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x251dd4 ldr r1, [r11, #0x4]
 *   @0x251dd8 cmp r1, #0
 *   @0x251ddc beq 0x251f4c <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x251de0 cmp r5, #1
 *   @0x251de4 addeq r4, sp, #16
 *   @0x251de8 addne r4, sp, #16
 *   @0x251dec ldrne r12, [sp, #0x98]
 *   @0x251df0 movne r5, #0
 *   @0x251df4 ldmeq r1, {r0, r1, r2, r3}
 *   @0x251df8 addne r3, r12, #16
 *   @0x251dfc ldr r12, [sp, #0x98]
 *   @0x251e00 ldmne r3, {r0, r1, r2, r3}
 *   @0x251e04 stm r4, {r0, r1, r2, r3}
 *   @0x251e08 mov r1, r6
 *   @0x251e0c mov r2, r7
 *   @0x251e10 str r12, [sp]
 *   @0x251e14 ldr r0, [sp, #0xc]
 *   @0x251e18 mov r3, #0
 *   @0x251e1c bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x251e20 cmp r5, r9
 *   @0x251e24 lsllo r7, r5, #4
 *   @0x251e28 addlo r6, sp, #48
 *   @0x251e2c addlo r8, sp, #32
 *   @0x251e30 mvnlo r10, #-16777216
 *   @0x251e34 blo 0x251ed4 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x251e38 b 0x251f14 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x251e3c add r0, r0, r7
 *   @0x251e40 ldr r3, [r0, #0xc]
 *   @0x251e44 bic r3, r3, #-16777216
 *   @0x251e48 cmp r3, r10
 *   @0x251e4c beq 0x251ec4 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x251e50 ldm r4, {r0, r1, r2, r3}
 *   @0x251e54 ldr lr, [r11, #0x4]
 *   @0x251e58 cmp lr, #0
 *   @0x251e5c stm r6, {r0, r1, r2, r3}
 *   @0x251e60 beq 0x251f04 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x251e64 add r0, lr, r7
 *   @0x251e68 vmov s13, r5
 *   @0x251e6c add lr, sp, #64
 *   @0x251e70 ldm r0, {r0, r1, r2, r3}
 *   @0x251e74 vcvt.f64.u32 d7, s13
 *   @0x251e78 str r6, [sp]
 *   @0x251e7c mov r12, #0
 *   @0x251e80 str r12, [sp, #0x5c]
 *   @0x251e84 mov r12, #6
 *   @0x251e88 str r12, [sp, #0x6c]
 *   @0x251e8c stm lr, {r0, r1, r2, r3}
 *   @0x251e90 mov r0, #0
 *   @0x251e94 mov r1, r8
 *   @0x251e98 ldr r2, [sp, #0x98]
 *   @0x251e9c mov r3, #3
 *   @0x251ea0 str r11, [sp, #0x60]
 *   @0x251ea4 vstr d7, [sp, #80]
 *   @0x251ea8 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x251eac cmp r0, #2
 *   @0x251eb0 beq 0x251efc <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x251eb4 cmp r0, #1
 *   @0x251eb8 beq 0x251f28 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x1a4>
 *   @0x251ebc ldm r8, {r0, r1, r2, r3}
 *   @0x251ec0 stm r4, {r0, r1, r2, r3}
 *   @0x251ec4 add r5, r5, #1
 *   @0x251ec8 add r7, r7, #16
 *   @0x251ecc cmp r9, r5
 *   @0x251ed0 bls 0x251f14 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x190>
 *   @0x251ed4 ldr r0, [r11, #0x4]
 *   @0x251ed8 cmp r0, #0
 *   @0x251edc bne 0x251e3c <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x251ee0 mov r0, r11
 *   @0x251ee4 mov r1, r5
 *   @0x251ee8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251eec b 0x251e40 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x251ef0 ldr r0, [pc, #0x64]
 *   @0x251ef4 add r0, pc, r0
 *   @0x251ef8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x251efc add sp, sp, #116
 *   @0x251f00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x251f04 mov r0, r11
 *   @0x251f08 mov r1, r5
 *   @0x251f0c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251f10 b 0x251e68 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0xe4>
 *   @0x251f14 ldm r4, {r0, r1, r2, r3}
 *   @0x251f18 ldr r12, [sp, #0xc]
 *   @0x251f1c stm r12, {r0, r1, r2, r3}
 *   @0x251f20 add sp, sp, #116
 *   @0x251f24 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x251f28 ldr r0, [pc, #0x30]
 *   @0x251f2c add r0, pc, r0
 *   @0x251f30 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x251f34 add sp, sp, #116
 *   @0x251f38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x251f3c mov r0, r1
 *   @0x251f40 mov r1, #1
 *   @0x251f44 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251f48 b 0x251db4 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x251f4c mov r0, r11
 *   @0x251f50 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251f54 mov r1, r0
 *   @0x251f58 b 0x251de0 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x251f5c andseq r4, r0, r8, lsr #11
 *   @0x251f60 andseq r4, r0, r12, lsr #10
 *
 * ══ §11/66 png_create_write_struct_2  0x2b0184  size 480  120 条（0x2b0184..0x2b0364）
 * @func 0x2b0184 0x2b0364  size 480  120 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_create_struct_2 / 0x5504a0 / 0x53cdf0 / TT_RunIns+0x14 / png_set_longjmp_fn / 0xb6904 / 0xb6c88 / png_set_error_fn
 * 字段偏移 top8: 0x28×13 / 0x24×3 / 0x18×2 / 0x2×2 / 0x1c×1 / 0x8×1 / 0x1ac×1 / 0x14×1
 * VFP 指令 1 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b0184 push {r4, r5, r6, r7, lr}
 *   @0x2b0188 str r0, [sp]
 *   @0x2b018c str r3, [sp, #0x1c]
 *   @0x2b0190 str r0, [sp, #0x8]
 *   @0x2b0194 str r2, [sp, #0x18]
 *   @0x2b0198 add r0, pc
 *   @0x2b019c ldr r3, [pc, #0x1ac]
 *   @0x2b01a0 str r1, [sp, #0x14]
 *   @0x2b01a4 str r2, [sp, #0xc]
 *   @0x2b01a8 movs r0, #0x1
 *   @0x2b01ac ldr r3, [r3]
 *   @0x2b01b0 movs r3, #0x0
 *   @0x2b01b4 bl 0x2a6c02 <png_create_struct_2>
 *   @0x2b01b8 str r0, [sp, #0x28]
 *   @0x2b01bc cmp r0, #0x0
 *   @0x2b01c0 bls 0x5504a0 <gp_ActiveMaskObjects+0xb7d8>
 *   @0x2b01c4 ldr r3, [pc, #0x17c]
 *   @0x2b01c8 bls 0x53cdf0 <obj_has_event+0x2280>
 *   @0x2b01cc ldr r0, [sp, #0x28]
 *   @0x2b01d0 bls 0x2fce08 <TT_RunIns+0x14>
 *   @0x2b01d4 ldr r3, [pc, #0x178]
 *   @0x2b01d8 mov.w r2, #0x100
 *   @0x2b01dc bl 0x2a653c <png_set_longjmp_fn>
 *   @0x2b01e0 blx 0xb6904 <setjmp@plt>
 *   @0x2b01e4 mov r4, r0
 *   @0x2b01e8 blx 0xb6c88 <abort@plt>
 *   @0x2b01ec add r1, sp, #0x8
 *   @0x2b01f0 ldm r1, {r1, r2, r3}
 *   @0x2b01f4 stmdbge r5, {r0, r1, r2, r3, r4, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2b01f8 ldr r0, [sp, #0x28]
 *   @0x2b01fc bl 0x2a654e <png_set_error_fn>
 *   @0x2b0200 ldr r3, [sp]
 *   @0x2b0204 ldr r3, [sp, #0x28]
 *   @0x2b0208 orrseq r3, r11, #48, #2
 *   @0x2b020c bmi 0x2b0250 <png_create_write_struct_2+0xcc>
 *   @0x2b0210 ldr r5, [pc, #0x140]
 *   @0x2b0214 .word 0x260133ff
 *   @0x2b0218 add r5, pc
 *   @0x2b021c adds r3, #0x1
 *   @0x2b0220 mov r7, r3
 *   @0x2b0224 cmp r1, r2
 *   @0x2b0228 ldr r1, [sp, #0x28]
 *   @0x2b022c vst4.8 {d16, d18, d20, d22}, [r0:256], r0
 *   @0x2b0230 .word 0xf8c13000
 *   @0x2b0234 stmdals r0, {r4, r5, r8}
 *   @0x2b0238 ldrb r1, [r0, r7]
 *   @0x2b023c bne 0x2b0246 <png_create_write_struct_2+0xc2>
 *   @0x2b0240 bne 0x2b0204 <png_create_write_struct_2+0x80>
 *   @0x2b0244 b 0x2b024a <png_create_write_struct_2+0xc6>
 *   @0x2b0248 beq 0x2b0204 <png_create_write_struct_2+0x80>
 *   @0x2b024c bne 0x2b021a <png_create_write_struct_2+0x96>
 *   @0x2b0250 ldr r2, [sp]
 *   @0x2b0254 movs r0, #0x0
 *   @0x2b0258 bl 0x2a5fcc <png_get_header_ver>
 *   @0x2b025c ldrb r3, [r0]
 *   @0x2b0260 bne 0x2b028e <png_create_write_struct_2+0x10a>
 *   @0x2b0264 ldrb r3, [r0]
 *   @0x2b0268 beq 0x2b0274 <png_create_write_struct_2+0xf0>
 *   @0x2b026c ldrb r3, [r2]
 *   @0x2b0270 bne 0x2b02d2 <png_create_write_struct_2+0x14e>
 *   @0x2b0274 ldr r3, [sp]
 *   @0x2b0278 ldrb r4, [r3, #0x2]
 *   @0x2b027c stmvc r3, {r0, r1, r2, r5, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2b0280 cmp r3, r4
 *   @0x2b0284 b 0x2b026a <png_create_write_struct_2+0xe6>
 *   @0x2b0288 ldrb r3, [r0, #0x2]
 *   @0x2b028c bhi 0x2b02d2 <png_create_write_struct_2+0x14e>
 *   @0x2b0290 ldr r2, [pc, #0xc4]
 *   @0x2b0294 ldr r3, [sp]
 *   @0x2b0298 add r2, pc
 *   @0x2b029c stmdals r10, {r1, r2, r4, r7, r8, r11, sp, lr, pc}
 *   @0x2b02a0 mov r1, r4
 *   @0x2b02a4 andhs pc, r0, r7, ror #17
 *   @0x2b02a8 add r4, sp, #0x2c
 *   @0x2b02ac bmi 0xdafcf0 <b2_toiTime+0x65684c>
 *   @0x2b02b0 movs r1, #0x50
 *   @0x2b02b4 mov r3, r0
 *   @0x2b02b8 blx 0xb65c8 <snprintf@plt>
 *   @0x2b02bc ldr r0, [sp, #0x28]
 *   @0x2b02c0 bl 0x2a6474 <png_warning>
 *   @0x2b02c4 ldr r1, [pc, #0x98]
 *   @0x2b02c8 add r1, pc
 *   @0x2b02cc movwhs pc, #0x18d3
 *   @0x2b02d0 str r3, [sp, #0x24]
 *   @0x2b02d4 mov.w r2, #0x2000
 *   @0x2b02d8 str.w r2, [r3, #0x174]
 *   @0x2b02dc ldr r3, [sp, #0x24]
 *   @0x2b02e0 ldr r4, [sp, #0x28]
 *   @0x2b02e4 ldr r3, [sp, #0x28]
 *   @0x2b02e8 .word 0xf7f61174
 *   @0x2b02ec blls 0x56f744 <g_SWFlineaavertbuff+0x1c67c>
 *   @0x2b02f0 str.w r0, [r4, #0x170]
 *   @0x2b02f4 ldr.w r3, [r3, #0x170]
 *   @0x2b02f8 cbnz r3, 0x2b02fe <png_create_write_struct_2+0x17a>
 *   @0x2b02fc str r3, [sp, #0x24]
 *   @0x2b0300 ldr r0, [sp, #0x28]
 *   @0x2b0304 ldr r3, [sp, #0x28]
 *   @0x2b0308 ldr.w r1, [r3, #0x170]
 *   @0x2b030c bl 0x2a6cfc <png_free>
 *   @0x2b0310 ldr r3, [sp, #0x28]
 *   @0x2b0314 ldr r0, [sp, #0x28]
 *   @0x2b0318 bls 0x3408e0
 *   @0x2b031c bl 0x2a6c5e <png_destroy_struct_2>
 *   @0x2b0320 mov r0, r4
 *   @0x2b0324 mov r2, r1
 *   @0x2b0328 bl 0x2afc18 <png_set_write_fn>
 *   @0x2b032c ldr r0, [sp, #0x28]
 *   @0x2b0330 ldr r3, [pc, #0x18]
 *   @0x2b0334 ldr r2, [sp, #0x7c]
 *   @0x2b0338 cmp r2, r3
 *   @0x2b033c blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2b0340 add sp, #0x84
 *   @0x2b0344 rsbs r0, r0, #0
 *   @0x2b0348 subs r4, r7, r2
 *   @0x2b034c pop {pc}
 *   @0x2b0350 .word 0xffffe4ac
 *   @0x2b0354 andeq r12, sp, r8, asr r1
 *   @0x2b0358 stm r5!, {r3}
 *   @0x2b035c stm r4!, {r0, r3, r6}
 *   @0x2b0360 stm r4!, {r0, r3, r5, r6}
 *
 * ══ §12/66 anon_2c811c  0x2c811c  size 480  120 条（0x2c811c..0x2c82fc）
 * @func 0x2c811c 0x2c82fc  size 480  120 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2c811c+0x1dc×2 / void std::__adjust_heap<b2Pair*, int, b2Pair, bool (*)(b2Pair const&, b2Pair const&)>(b2Pair*, int, int, b2Pair, bool (*)(b2Pair const&, b2Pair const&))×2 / anon_2c811c+0xf4 / anon_2c811c
 * 字段偏移 top8: 0x4×5 / 0x-8×1 / 0xc×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c811c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2c8120 mov r9, r1
 *   @0x2c8124 rsb r1, r0, r1
 *   @0x2c8128 sub sp, sp, #24
 *   @0x2c812c cmp r1, #135
 *   @0x2c8130 mov r8, r0
 *   @0x2c8134 mov r10, r2
 *   @0x2c8138 mov r6, r3
 *   @0x2c813c ble 0x2c82f8 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x318>
 *   @0x2c8140 cmp r2, #0
 *   @0x2c8144 beq 0x2c8274 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x294>
 *   @0x2c8148 add r7, sp, #16
 *   @0x2c814c asr r1, r1, #4
 *   @0x2c8150 mov r0, r8
 *   @0x2c8154 sub r10, r10, #1
 *   @0x2c8158 sub r5, r9, #8
 *   @0x2c815c add r4, r8, r1, lsl #3
 *   @0x2c8160 mov r1, r4
 *   @0x2c8164 blx r6
 *   @0x2c8168 cmp r0, #0
 *   @0x2c816c beq 0x2c8240 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x260>
 *   @0x2c8170 mov r0, r4
 *   @0x2c8174 mov r1, r5
 *   @0x2c8178 blx r6
 *   @0x2c817c cmp r0, #0
 *   @0x2c8180 movne r0, r4
 *   @0x2c8184 bne 0x2c81a0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1c0>
 *   @0x2c8188 mov r0, r8
 *   @0x2c818c mov r1, r5
 *   @0x2c8190 blx r6
 *   @0x2c8194 cmp r0, #0
 *   @0x2c8198 moveq r0, r8
 *   @0x2c819c movne r0, r5
 *   @0x2c81a0 ldm r0, {r0, r1}
 *   @0x2c81a4 mov r5, r9
 *   @0x2c81a8 mov r3, r8
 *   @0x2c81ac stm r7, {r0, r1}
 *   @0x2c81b0 mov r4, r3
 *   @0x2c81b4 b 0x2c81bc <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1dc>
 *   @0x2c81b8 add r4, r4, #8
 *   @0x2c81bc mov r0, r4
 *   @0x2c81c0 mov r1, r7
 *   @0x2c81c4 blx r6
 *   @0x2c81c8 cmp r0, #0
 *   @0x2c81cc bne 0x2c81b8 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1d8>
 *   @0x2c81d0 sub r5, r5, #8
 *   @0x2c81d4 mov r0, r7
 *   @0x2c81d8 mov r1, r5
 *   @0x2c81dc blx r6
 *   @0x2c81e0 cmp r0, #0
 *   @0x2c81e4 bne 0x2c81d0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1f0>
 *   @0x2c81e8 cmp r5, r4
 *   @0x2c81ec bls 0x2c8210 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x230>
 *   @0x2c81f0 ldr r12, [r4]
 *   @0x2c81f4 add r3, r4, #8
 *   @0x2c81f8 ldr r2, [r4, #0x4]
 *   @0x2c81fc ldm r5, {r0, r1}
 *   @0x2c8200 stm r4, {r0, r1}
 *   @0x2c8204 str r12, [r5]
 *   @0x2c8208 str r2, [r5, #0x4]
 *   @0x2c820c b 0x2c81b0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1d0>
 *   @0x2c8210 mov r1, r9
 *   @0x2c8214 mov r0, r4
 *   @0x2c8218 mov r2, r10
 *   @0x2c821c mov r3, r6
 *   @0x2c8220 bl 0x2c811c <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x13c>
 *   @0x2c8224 rsb r1, r8, r4
 *   @0x2c8228 cmp r1, #135
 *   @0x2c822c ble 0x2c82f8 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x318>
 *   @0x2c8230 cmp r10, #0
 *   @0x2c8234 beq 0x2c8278 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x298>
 *   @0x2c8238 mov r9, r4
 *   @0x2c823c b 0x2c814c <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x16c>
 *   @0x2c8240 mov r0, r8
 *   @0x2c8244 mov r1, r5
 *   @0x2c8248 blx r6
 *   @0x2c824c cmp r0, #0
 *   @0x2c8250 movne r0, r8
 *   @0x2c8254 bne 0x2c81a0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1c0>
 *   @0x2c8258 mov r0, r4
 *   @0x2c825c mov r1, r5
 *   @0x2c8260 blx r6
 *   @0x2c8264 cmp r0, #0
 *   @0x2c8268 moveq r0, r4
 *   @0x2c826c movne r0, r5
 *   @0x2c8270 b 0x2c81a0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1c0>
 *   @0x2c8274 mov r4, r9
 *   @0x2c8278 asr r9, r1, #3
 *   @0x2c827c sub r5, r9, #2
 *   @0x2c8280 asr r5, r5, #1
 *   @0x2c8284 add r7, r8, r5, lsl #3
 *   @0x2c8288 str r6, [sp, #0x4]
 *   @0x2c828c mov r1, r5
 *   @0x2c8290 ldr r12, [r7, #0x4]
 *   @0x2c8294 mov r0, r8
 *   @0x2c8298 ldr r3, [r7], #-8
 *   @0x2c829c mov r2, r9
 *   @0x2c82a0 str r12, [sp]
 *   @0x2c82a4 bl 0x2c7fe0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_>
 *   @0x2c82a8 cmp r5, #0
 *   @0x2c82ac sub r5, r5, #1
 *   @0x2c82b0 bne 0x2c8288 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x2a8>
 *   @0x2c82b4 add r7, sp, #8
 *   @0x2c82b8 sub r4, r4, #8
 *   @0x2c82bc rsb r5, r8, r4
 *   @0x2c82c0 ldm r4, {r0, r1}
 *   @0x2c82c4 asr r2, r5, #3
 *   @0x2c82c8 stm r7, {r0, r1}
 *   @0x2c82cc ldm r8, {r0, r1}
 *   @0x2c82d0 ldr r12, [sp, #0xc]
 *   @0x2c82d4 ldr r3, [sp, #0x8]
 *   @0x2c82d8 stm r4, {r0, r1}
 *   @0x2c82dc mov r0, r8
 *   @0x2c82e0 str r6, [sp, #0x4]
 *   @0x2c82e4 mov r1, #0
 *   @0x2c82e8 str r12, [sp]
 *   @0x2c82ec bl 0x2c7fe0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_>
 *   @0x2c82f0 cmp r5, #15
 *   @0x2c82f4 bgt 0x2c82b8 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x2d8>
 *   @0x2c82f8 add sp, sp, #24
 *
 * ══ §13/66 IBuffer::Peek(int, eBuffer_Type, RValue*)  0xcd128  size 476  119 条（0xcd128..0xcd304）
 * @func 0xcd128 0xcd304  size 476  119 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: IBuffer::Peek(int, eBuffer_Type, RValue*)+0x74×2 / IBuffer::SizeOf(eBuffer_Type) / IBuffer::Peek(int, eBuffer_Type, RValue*)+0xc8 / IBuffer::Peek(int, eBuffer_Type, RValue*)+0xe8 / IBuffer::Peek(int, eBuffer_Type, RValue*)+0xdc
 * 字段偏移 top8: 0xc×10 / 0x1×3 / 0x4×3 / 0x10×2 / 0x18×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcd128 push {r4, r5, r6, r7, r8, lr}
 *   @0xcd12c mov r6, r3
 *   @0xcd130 sub sp, sp, #8
 *   @0xcd134 mov r3, #0
 *   @0xcd138 mov r8, r0
 *   @0xcd13c str r3, [r6, #0xc]
 *   @0xcd140 mov r0, r2
 *   @0xcd144 mov r4, r1
 *   @0xcd148 mov r7, r2
 *   @0xcd14c bl 0xcd100 <_ZN7IBuffer6SizeOfE12eBuffer_Type>
 *   @0xcd150 cmp r4, #0
 *   @0xcd154 blt 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8>
 *   @0xcd158 ldr r3, [r8, #0x18]
 *   @0xcd15c cmp r3, #2
 *   @0xcd160 beq 0xcd1f8 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xd0>
 *   @0xcd164 ldr r3, [r8, #0x10]
 *   @0xcd168 rsb r3, r0, r3
 *   @0xcd16c cmp r4, r3
 *   @0xcd170 bgt 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8>
 *   @0xcd174 ldr r3, [r8, #0xc]
 *   @0xcd178 cmp r0, #0
 *   @0xcd17c add r4, r3, r4
 *   @0xcd180 ble 0xcd19c <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x74>
 *   @0xcd184 add r5, r4, r0
 *   @0xcd188 sub r1, sp, #1
 *   @0xcd18c ldrb r12, [r4], #1
 *   @0xcd190 cmp r4, r5
 *   @0xcd194 strb r12, [r1, #0x1]!
 *   @0xcd198 bne 0xcd18c <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x64>
 *   @0xcd19c sub r7, r7, #1
 *   @0xcd1a0 cmp r7, #11
 *   @0xcd1a4 addls pc, pc, r7, lsl #2
 *   @0xcd1a8 b 0xcd2f4 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x1cc>
 *   @0xcd1ac b 0xcd250 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x128>
 *   @0xcd1b0 b 0xcd2e0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x1b8>
 *   @0xcd1b4 b 0xcd2cc <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x1a4>
 *   @0xcd1b8 b 0xcd2b8 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x190>
 *   @0xcd1bc b 0xcd29c <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x174>
 *   @0xcd1c0 b 0xcd288 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x160>
 *   @0xcd1c4 b 0xcd2f4 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x1cc>
 *   @0xcd1c8 b 0xcd274 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x14c>
 *   @0xcd1cc b 0xcd268 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x140>
 *   @0xcd1d0 b 0xcd250 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x128>
 *   @0xcd1d4 b 0xcd2f4 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x1cc>
 *   @0xcd1d8 b 0xcd1dc <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xb4>
 *   @0xcd1dc ldr r2, [sp]
 *   @0xcd1e0 mov r1, #10
 *   @0xcd1e4 ldr r3, [sp, #0x4]
 *   @0xcd1e8 str r1, [r6, #0xc]
 *   @0xcd1ec stm r6, {r2, r3}
 *   @0xcd1f0 add sp, sp, #8
 *   @0xcd1f4 pop {r4, r5, r6, r7, r8, pc}
 *   @0xcd1f8 ldr r1, [r8, #0x10]
 *   @0xcd1fc cmp r4, r1
 *   @0xcd200 blt 0xcd210 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xe8>
 *   @0xcd204 rsb r4, r1, r4
 *   @0xcd208 cmp r1, r4
 *   @0xcd20c ble 0xcd204 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xdc>
 *   @0xcd210 ldr r2, [r8, #0xc]
 *   @0xcd214 cmp r0, #0
 *   @0xcd218 add r12, r2, r4
 *   @0xcd21c ble 0xcd19c <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x74>
 *   @0xcd220 sub r5, sp, #1
 *   @0xcd224 add r0, r5, r0
 *   @0xcd228 ldrb r3, [r12]
 *   @0xcd22c add r4, r4, #1
 *   @0xcd230 cmp r4, r1
 *   @0xcd234 add r12, r12, #1
 *   @0xcd238 strb r3, [r5, #0x1]!
 *   @0xcd23c movge r12, r2
 *   @0xcd240 movge r4, #0
 *   @0xcd244 cmp r5, r0
 *   @0xcd248 bne 0xcd228 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x100>
 *   @0xcd24c b 0xcd19c <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0x74>
 *   @0xcd250 ldrb r3, [sp]
 *   @0xcd254 mov r2, #7
 *   @0xcd258 str r2, [r6, #0xc]
 *   @0xcd25c str r3, [r6]
 *   @0xcd260 add sp, sp, #8
 *   @0xcd264 pop {r4, r5, r6, r7, r8, pc}
 *   @0xcd268 ldm sp, {r2, r3}
 *   @0xcd26c stm r6, {r2, r3}
 *   @0xcd270 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8>
 *   @0xcd274 vldr s15, [sp]
 *   @0xcd278 vcvt.f64.f32 d6, s15
 *   @0xcd27c vmov r2, r3, d6
 *   @0xcd280 stm r6, {r2, r3}
 *   @0xcd284 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8>
 *   @0xcd288 ldr r3, [sp]
 *   @0xcd28c mov r2, #7
 *   @0xcd290 str r2, [r6, #0xc]
 *   @0xcd294 str r3, [r6]
 *   @0xcd298 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8>
 *   @0xcd29c ldr r3, [sp]
 *   @0xcd2a0 mov r1, #10
 *   @0xcd2a4 mov r2, #0
 *   @0xcd2a8 str r1, [r6, #0xc]
 *   @0xcd2ac str r2, [r6, #0x4]
 *   @0xcd2b0 str r3, [r6]
 *   @0xcd2b4 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8>
 *   @0xcd2b8 ldrsh r3, [sp]
 *   @0xcd2bc mov r2, #7
 *   @0xcd2c0 str r2, [r6, #0xc]
 *   @0xcd2c4 str r3, [r6]
 *   @0xcd2c8 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8>
 *   @0xcd2cc ldrh r3, [sp]
 *   @0xcd2d0 mov r2, #7
 *   @0xcd2d4 str r2, [r6, #0xc]
 *   @0xcd2d8 str r3, [r6]
 *   @0xcd2dc b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8>
 *   @0xcd2e0 ldrsb r3, [sp]
 *   @0xcd2e4 mov r2, #7
 *   @0xcd2e8 str r2, [r6, #0xc]
 *   @0xcd2ec str r3, [r6]
 *   @0xcd2f0 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8>
 *   @0xcd2f4 mov r3, #0
 *   @0xcd2f8 str r3, [r6]
 *   @0xcd2fc str r3, [r6, #0x4]
 *   @0xcd300 b 0xcd1f0 <_ZN7IBuffer4PeekEi12eBuffer_TypeP6RValue+0xc8>
 *
 * ══ §14/66 F_FileTextOpenRead(RValue&, CInstance*, CInstance*, int, RValue*)  0x137b2c  size 476  119 条（0x137b2c..0x137d08）
 * @func 0x137b2c 0x137d08  size 476  119 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x137b7c→0x483724, 0x137ba8→0x4837a4, 0x137c80→0x3eb70c, 0x137cd4→0x3eb70c
 * 调用序列: YYGetString(RValue const*, int) / MemoryManager::Free(void const*) / LoadSave::SaveFileExists(char const*) / LoadSave::_GetSaveFileName(char*, int, char const*) / YYStrDup(char const*) / LoadSave::fopen(char const*, char const*) / LoadSave::BundleFileExists(char const*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x4×4 / 0xc×2 / 0x40c×2 / 0x1a8×1 / 0x1a4×1 / 0x438×1 / 0x168×1 / 0x140×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x137b2c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x137b30 mov r3, #0
 *   @0x137b34 ldr r6, [pc, #0x1a8]
 *   @0x137b38 mov r5, r0
 *   @0x137b3c ldr r12, [pc, #0x1a4]
 *   @0x137b40 sub sp, sp, #1040
 *   @0x137b44 add r6, pc, r6
 *   @0x137b48 sub sp, sp, #4
 *   @0x137b4c mov r2, r3
 *   @0x137b50 movt r2, #0xbff0
 *   @0x137b54 ldr r7, [r6, r12]
 *   @0x137b58 mov r1, r3
 *   @0x137b5c str r2, [r5, #0x4]
 *   @0x137b60 mov r4, #1
 *   @0x137b64 str r3, [r5, #0xc]
 *   @0x137b68 ldr r2, [r7]
 *   @0x137b6c ldr r0, [sp, #0x438]
 *   @0x137b70 str r3, [r5]
 *   @0x137b74 str r2, [sp, #0x40c]
 *   @0x137b78 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x137b7c ldr r3, [pc, #0x168]
 *   @0x137b80 ldr r3, [r6, r3]
 *   @0x137b84 str r3, [sp, #0x4]
 *   @0x137b88 mov r9, r0
 *   @0x137b8c b 0x137b9c <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x137b90 add r4, r4, #1
 *   @0x137b94 cmp r4, #32
 *   @0x137b98 beq 0x137ca0 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x137b9c ldr r2, [r3, #0x4]!
 *   @0x137ba0 cmp r2, #0
 *   @0x137ba4 bne 0x137b90 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x137ba8 ldr r1, [pc, #0x140]
 *   @0x137bac lsl r11, r4, #1
 *   @0x137bb0 add r3, r11, r4
 *   @0x137bb4 ldr r10, [r6, r1]
 *   @0x137bb8 lsl r8, r3, #2
 *   @0x137bbc ldr r0, [r10, r8]
 *   @0x137bc0 cmp r0, #0
 *   @0x137bc4 beq 0x137bd8 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x137bc8 str r2, [sp]
 *   @0x137bcc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x137bd0 ldr r2, [sp]
 *   @0x137bd4 str r2, [r10, r8]
 *   @0x137bd8 mov r0, r9
 *   @0x137bdc bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x137be0 cmp r0, #0
 *   @0x137be4 beq 0x137c68 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x137be8 mov r2, r9
 *   @0x137bec add r9, sp, #12
 *   @0x137bf0 mov r1, #1024
 *   @0x137bf4 mov r0, r9
 *   @0x137bf8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x137bfc mov r0, r9
 *   @0x137c00 add r11, r11, r4
 *   @0x137c04 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x137c08 ldr r1, [pc, #0xe4]
 *   @0x137c0c lsl r11, r11, #2
 *   @0x137c10 add r1, pc, r1
 *   @0x137c14 add r8, r10, r11
 *   @0x137c18 str r0, [r10, r11]
 *   @0x137c1c mov r9, r0
 *   @0x137c20 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_>
 *   @0x137c24 cmp r0, #0
 *   @0x137c28 str r0, [r8, #0x8]
 *   @0x137c2c beq 0x137ccc <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x137c30 vmov s15, r4
 *   @0x137c34 ldr r0, [sp, #0x4]
 *   @0x137c38 mov r1, #1
 *   @0x137c3c vcvt.f64.s32 d7, s15
 *   @0x137c40 str r1, [r0, r4, lsl #2]
 *   @0x137c44 vmov r2, r3, d7
 *   @0x137c48 stm r5, {r2, r3}
 *   @0x137c4c ldr r2, [sp, #0x40c]
 *   @0x137c50 ldr r3, [r7]
 *   @0x137c54 cmp r2, r3
 *   @0x137c58 bne 0x137ce0 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x137c5c add sp, sp, #1040
 *   @0x137c60 add sp, sp, #4
 *   @0x137c64 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x137c68 mov r0, r9
 *   @0x137c6c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x137c70 cmp r0, #0
 *   @0x137c74 bne 0x137cb4 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x137c78 ldr r1, [pc, #0x78]
 *   @0x137c7c mov r2, r9
 *   @0x137c80 ldr r3, [pc, #0x74]
 *   @0x137c84 add r1, pc, r1
 *   @0x137c88 ldr r3, [r6, r3]
 *   @0x137c8c ldr r0, [r3]
 *   @0x137c90 ldr r3, [r0]
 *   @0x137c94 ldr r3, [r3, #0xc]
 *   @0x137c98 blx r3
 *   @0x137c9c b 0x137c4c <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x137ca0 ldr r0, [pc, #0x58]
 *   @0x137ca4 mov r1, #0
 *   @0x137ca8 add r0, pc, r0
 *   @0x137cac bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x137cb0 b 0x137c4c <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x137cb4 mov r2, r9
 *   @0x137cb8 add r9, sp, #12
 *   @0x137cbc mov r1, #1024
 *   @0x137cc0 mov r0, r9
 *   @0x137cc4 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x137cc8 b 0x137bfc <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0x137ccc ldr r1, [pc, #0x30]
 *   @0x137cd0 mov r2, r9
 *   @0x137cd4 ldr r3, [pc, #0x20]
 *   @0x137cd8 add r1, pc, r1
 *   @0x137cdc b 0x137c88 <_Z18F_FileTextOpenReadR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x137ce0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x137ce4 eoreq r10, r11, r12, lsl #2
 *   @0x137ce8 .word 0xffffbd00
 *   @0x137cec .word 0xffffd620
 *   @0x137cf0 .word 0xffffd624
 *   @0x137cf4 eoreq r8, r0, r12, ror #7
 *   @0x137cf8 eoreq r8, r0, r0, asr r3
 *   @0x137cfc .word 0xffffbac4
 *   @0x137d00 eoreq r8, r0, r8, asr r3
 *   @0x137d04 .word 0x002082fc
 *
 * ══ §15/66 F_YoYo_OpenURL(RValue&, CInstance*, CInstance*, int, RValue*)  0x156be8  size 472  118 条（0x156be8..0x156dc0）
 * @func 0x156be8 0x156dc0  size 472  118 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show_Action(char const*, bool)×4 / OpenURL(char const*)×2 / YYGetString(RValue const*, int) / 0xb6634 / 0xb66d0 / 0xb65b0 / 0xb6538 / LoadSave::SaveFileExists(char const*)
 * 字段偏移 top8: 0x4×5 / 0xc×2 / 0x404×2 / 0x6×2 / 0x1ac×1 / 0x420×1 / 0x17c×1 / 0x14c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x156be8 push {r4, r5, r6, r7, r8, lr}
 *   @0x156bec cmp r3, #1
 *   @0x156bf0 ldr r4, [pc, #0x1ac]
 *   @0x156bf4 sub sp, sp, #1024
 *   @0x156bf8 sub sp, sp, #8
 *   @0x156bfc mov r5, r0
 *   @0x156c00 ldr r4, [pc, r4]
 *   @0x156c04 mov r1, #0
 *   @0x156c08 str r1, [r0, #0xc]
 *   @0x156c0c ldr r3, [r4]
 *   @0x156c10 str r1, [r0, #0x4]
 *   @0x156c14 ldr r0, [sp, #0x420]
 *   @0x156c18 str r1, [r5]
 *   @0x156c1c str r3, [sp, #0x404]
 *   @0x156c20 beq 0x156c4c <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x156c24 ldr r0, [pc, #0x17c]
 *   @0x156c28 add r0, pc, r0
 *   @0x156c2c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x156c30 ldr r2, [sp, #0x404]
 *   @0x156c34 ldr r3, [r4]
 *   @0x156c38 cmp r2, r3
 *   @0x156c3c bne 0x156da0 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x156c40 add sp, sp, #1024
 *   @0x156c44 add sp, sp, #8
 *   @0x156c48 pop {r4, r5, r6, r7, r8, pc}
 *   @0x156c4c ldr r3, [r0, #0xc]
 *   @0x156c50 cmp r3, #1
 *   @0x156c54 beq 0x156c68 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x156c58 ldr r0, [pc, #0x14c]
 *   @0x156c5c add r0, pc, r0
 *   @0x156c60 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x156c64 b 0x156c30 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x156c68 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x156c6c mov r1, #58
 *   @0x156c70 mov r6, r0
 *   @0x156c74 bl 0xb6634 <strchr@plt>
 *   @0x156c78 cmp r0, #0
 *   @0x156c7c beq 0x156ce8 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x156c80 rsb r0, r6, r0
 *   @0x156c84 cmp r0, #1
 *   @0x156c88 addne r7, sp, #4
 *   @0x156c8c beq 0x156ce8 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x156c90 ldr r0, [r6]
 *   @0x156c94 mov r1, r7
 *   @0x156c98 mov r3, #0
 *   @0x156c9c str r0, [sp, #0x4]
 *   @0x156ca0 ldr r0, [pc, #0x108]
 *   @0x156ca4 ldrh r12, [r6, #4]
 *   @0x156ca8 ldrb r2, [r6, #0x6]
 *   @0x156cac add r0, pc, r0
 *   @0x156cb0 strh r12, [r7, #4]
 *   @0x156cb4 strb r2, [r7, #0x6]
 *   @0x156cb8 strb r3, [sp, #0xb]
 *   @0x156cbc bl 0xb66d0 <strcasecmp@plt>
 *   @0x156cc0 subs r1, r0, #0
 *   @0x156cc4 beq 0x156cd8 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x156cc8 mov r0, r6
 *   @0x156ccc bl 0x160eec <_Z7OpenURLPKc>
 *   @0x156cd0 stm r5, {r0, r1}
 *   @0x156cd4 b 0x156c30 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x156cd8 ldr r0, [pc, #0xd4]
 *   @0x156cdc add r0, pc, r0
 *   @0x156ce0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x156ce4 b 0x156c30 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x156ce8 ldr r3, [pc, #0xc8]
 *   @0x156cec add r7, sp, #8
 *   @0x156cf0 movw r2, #0x3f9
 *   @0x156cf4 add r3, pc, r3
 *   @0x156cf8 ldm r3, {r0, r1}
 *   @0x156cfc lsr r3, r1, #16
 *   @0x156d00 strb r3, [sp, #0xa]
 *   @0x156d04 strh r1, [r7], #-4
 *   @0x156d08 mov r1, #0
 *   @0x156d0c str r0, [sp, #0x4]
 *   @0x156d10 add r0, sp, #11
 *   @0x156d14 bl 0xb65b0 <memset@plt>
 *   @0x156d18 mov r0, r7
 *   @0x156d1c bl 0xb6538 <strlen@plt>
 *   @0x156d20 mov r8, r0
 *   @0x156d24 mov r0, r6
 *   @0x156d28 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x156d2c cmp r0, #0
 *   @0x156d30 beq 0x156d6c <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x156d34 add r0, r7, r8
 *   @0x156d38 rsb r1, r8, #1024
 *   @0x156d3c mov r2, r6
 *   @0x156d40 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x156d44 add r3, sp, #1024
 *   @0x156d48 add r3, r3, #8
 *   @0x156d4c add r8, r3, r8
 *   @0x156d50 ldrb r3, [r8, #-0x404]
 *   @0x156d54 cmp r3, #0
 *   @0x156d58 beq 0x156c90 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0xa8>
 *   @0x156d5c mov r0, r7
 *   @0x156d60 bl 0x160eec <_Z7OpenURLPKc>
 *   @0x156d64 stm r5, {r0, r1}
 *   @0x156d68 b 0x156c30 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x156d6c mov r0, r6
 *   @0x156d70 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x156d74 subs r1, r0, #0
 *   @0x156d78 beq 0x156d90 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x156d7c add r0, r7, r8
 *   @0x156d80 rsb r1, r8, #1024
 *   @0x156d84 mov r2, r6
 *   @0x156d88 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x156d8c b 0x156d44 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x156d90 ldr r0, [pc, #0x24]
 *   @0x156d94 add r0, pc, r0
 *   @0x156d98 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x156d9c b 0x156c30 <_Z14F_YoYo_OpenURLR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x156da0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x156da4 eoreq r6, r9, r0, asr sp
 *   @0x156da8 andseq pc, lr, r0, lsr #19
 *   @0x156dac andseq r11, lr, r0, asr sp
 *   @0x156db0 eoreq r5, r0, r12, lsl #28
 *   @0x156db4 andseq pc, lr, r0, lsr #19
 *   @0x156db8 eoreq r5, r0, r4, asr #27
 *   @0x156dbc andseq pc, lr, r12, ror r8
 *
 * ══ §16/66 Audio_GetTrackPos(int)  0x218908  size 472  118 条（0x218908..0x218ae0）
 * @func 0x218908 0x218ae0  size 472  118 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Audio_GetSound(int)×2 / Audio_GetTrackPos(int)+0x54 / Audio_GetTrackPos(int)+0x118 / Audio_GetTrackPos(int)+0x10c / Audio_GetNoiseFromID(int) / Audio_GetTrackPos(int)+0x1b0 / 0xb6a9c / checkAL(char const*)
 * 字段偏移 top8: 0x10×2 / 0x38×2 / 0x4×2 / 0x1bc×1 / 0x48×1 / 0x18×1 / 0x144×1 / 0x24×1
 * VFP 指令 15 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x218908 ldr r3, [pc, #0x1bc]
 *   @0x21890c push {r4, r5, r6, r7, lr}
 *   @0x218910 ldr r3, [pc, r3]
 *   @0x218914 sub sp, sp, #12
 *   @0x218918 ldr r3, [r3]
 *   @0x21891c cmp r3, r0
 *   @0x218920 ble 0x21895c <_Z17Audio_GetTrackPosi+0x54>
 *   @0x218924 sub r1, r0, #199680
 *   @0x218928 movw r3, #0x869f
 *   @0x21892c sub r1, r1, #320
 *   @0x218930 movt r3, #0x1
 *   @0x218934 cmp r1, r3
 *   @0x218938 bls 0x218a20 <_Z17Audio_GetTrackPosi+0x118>
 *   @0x21893c cmp r0, #0
 *   @0x218940 blt 0x218a14 <_Z17Audio_GetTrackPosi+0x10c>
 *   @0x218944 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x218948 cmp r0, #0
 *   @0x21894c beq 0x218a14 <_Z17Audio_GetTrackPosi+0x10c>
 *   @0x218950 ldr r0, [r0, #0x48]
 *   @0x218954 add sp, sp, #12
 *   @0x218958 pop {r4, r5, r6, r7, pc}
 *   @0x21895c bl 0x216fbc <_Z20Audio_GetNoiseFromIDi>
 *   @0x218960 mov r4, r0
 *   @0x218964 cmp r4, #0
 *   @0x218968 mov r3, #0
 *   @0x21896c str r3, [sp]
 *   @0x218970 beq 0x218a14 <_Z17Audio_GetTrackPosi+0x10c>
 *   @0x218974 ldr r0, [r4, #0x18]
 *   @0x218978 bl 0x21632c <_Z14Audio_GetSoundi>
 *   @0x21897c subs r5, r0, #0
 *   @0x218980 beq 0x218a14 <_Z17Audio_GetTrackPosi+0x10c>
 *   @0x218984 ldr r3, [pc, #0x144]
 *   @0x218988 ldrb r1, [r5, #0x24]
 *   @0x21898c ldr r3, [pc, r3]
 *   @0x218990 ldr r2, [r4, #0x10]
 *   @0x218994 cmp r1, #0
 *   @0x218998 ldr r3, [r3]
 *   @0x21899c ldr r6, [r3, r2, lsl #2]
 *   @0x2189a0 bne 0x2189b0 <_Z17Audio_GetTrackPosi+0xa8>
 *   @0x2189a4 ldrb r3, [r5, #0x25]
 *   @0x2189a8 cmp r3, #0
 *   @0x2189ac beq 0x218a9c <_Z17Audio_GetTrackPosi+0x194>
 *   @0x2189b0 ldrb r3, [r4, #0xd]
 *   @0x2189b4 cmp r3, #0
 *   @0x2189b8 bne 0x218a14 <_Z17Audio_GetTrackPosi+0x10c>
 *   @0x2189bc ldr r3, [r5, #0x38]
 *   @0x2189c0 cmp r3, #0
 *   @0x2189c4 ble 0x218ab8 <_Z17Audio_GetTrackPosi+0x1b0>
 *   @0x2189c8 add r2, sp, #8
 *   @0x2189cc mov r3, #0
 *   @0x2189d0 movw r1, #0x1025
 *   @0x2189d4 mov r0, r6
 *   @0x2189d8 str r3, [r2, #-0x4]!
 *   @0x2189dc bl 0xb6a9c <alGetSourcei@plt>
 *   @0x2189e0 ldr r0, [pc, #0xec]
 *   @0x2189e4 add r0, pc, r0
 *   @0x2189e8 bl 0x215fd0 <_Z7checkALPKc>
 *   @0x2189ec ldr r0, [pc, #0xe4]
 *   @0x2189f0 ldr r1, [r4, #0x10]
 *   @0x2189f4 add r0, pc, r0
 *   @0x2189f8 ldr r2, [r4, #0x30]
 *   @0x2189fc bl 0x226118 <_ZN9COggAudio13GetOggChannelEii>
 *   @0x218a00 subs r7, r0, #0
 *   @0x218a04 beq 0x218a14 <_Z17Audio_GetTrackPosi+0x10c>
 *   @0x218a08 ldr r6, [r5, #0x38]
 *   @0x218a0c cmp r6, #0
 *   @0x218a10 bgt 0x218a2c <_Z17Audio_GetTrackPosi+0x124>
 *   @0x218a14 mov r0, #0
 *   @0x218a18 add sp, sp, #12
 *   @0x218a1c pop {r4, r5, r6, r7, pc}
 *   @0x218a20 bl 0x216560 <_Z31Audio_GetNoiseFromQueuedSoundIDi>
 *   @0x218a24 mov r4, r0
 *   @0x218a28 b 0x218964 <_Z17Audio_GetTrackPosi+0x5c>
 *   @0x218a2c ldr r1, [r5, #0x3c]
 *   @0x218a30 mov r0, #16384
 *   @0x218a34 lsl r1, r1, #1
 *   @0x218a38 bl 0x318d10 <__divsi3>
 *   @0x218a3c ldr r2, [r7, #0x2e0]
 *   @0x218a40 ldr r3, [sp, #0x4]
 *   @0x218a44 vmov s11, r6
 *   @0x218a48 vldr s13, [r7, #744]
 *   @0x218a4c vldr s14, [r5, #52]
 *   @0x218a50 vcvt.f32.s32 s12, s11
 *   @0x218a54 mla r0, r2, r0, r3
 *   @0x218a58 vmov s11, r0
 *   @0x218a5c vcvt.f32.s32 s15, s11
 *   @0x218a60 vdiv.f32 s15, s15, s12
 *   @0x218a64 vadd.f32 s15, s15, s13
 *   @0x218a68 vcmpe.f32 s15, s14
 *   @0x218a6c vstr s15, [sp]
 *   @0x218a70 vmrs APSR_nzcv, fpscr
 *   @0x218a74 vmovle r0, s15
 *   @0x218a78 ble 0x218a18 <_Z17Audio_GetTrackPosi+0x110>
 *   @0x218a7c ldrb r3, [r4, #0x4]
 *   @0x218a80 cmp r3, #0
 *   @0x218a84 vmoveq r0, s14
 *   @0x218a88 beq 0x218a18 <_Z17Audio_GetTrackPosi+0x110>
 *   @0x218a8c vmov r0, s15
 *   @0x218a90 vmov r1, s14
 *   @0x218a94 bl 0xb6790 <fmodf@plt>
 *   @0x218a98 b 0x218a18 <_Z17Audio_GetTrackPosi+0x110>
 *   @0x218a9c mov r0, r6
 *   @0x218aa0 movw r1, #0x1024
 *   @0x218aa4 mov r2, sp
 *   @0x218aa8 bl 0xb6acc <alGetSourcef@plt>
 *   @0x218aac ldr r0, [sp]
 *   @0x218ab0 add sp, sp, #12
 *   @0x218ab4 pop {r4, r5, r6, r7, pc}
 *   @0x218ab8 ldr r0, [pc, #0x1c]
 *   @0x218abc mov r1, r5
 *   @0x218ac0 add r0, pc, r0
 *   @0x218ac4 bl 0x22688c <_ZN9COggAudio13CalcSoundInfoEP12cAudio_Sound>
 *   @0x218ac8 b 0x2189c8 <_Z17Audio_GetTrackPosi+0xc0>
 *   @0x218acc ldrsbeq r8, [sp], -r4
 *   @0x218ad0 andseq r8, sp, r0, asr #20
 *   @0x218ad4 andseq r11, r3, r8, lsr r3
 *   @0x218ad8 subseq r12, r3, r0, lsr #17
 *   @0x218adc ldrsbeq r12, [r3], #-116
 *
 * ══ §17/66 COggSyncThread::Create(int, int, int, bool)  0x224a4c  size 472  118 条（0x224a4c..0x224c24）
 * @func 0x224a4c 0x224c24  size 472  118 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new[](unsigned int)×2 / COggSyncThread::Create(int, int, int, bool)+0xf4×2 / SOggChannel::Init(unsigned int)×2 / SOggChannel::SOggChannel() / operator new(unsigned int) / Mutex::Mutex(char const*) / COggSyncThread::StartThread() / 0xb6544
 * 字段偏移 top8: 0x804×4 / 0x4×3 / 0x2b8×2 / 0x808×1 / 0x30×1 / 0x84c×1 / 0x810×1 / 0x800×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x224a4c cmp r3, #2785280
 *   @0x224a50 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x224a54 mov r7, r0
 *   @0x224a58 addls r0, r3, r3, lsl #1
 *   @0x224a5c sub sp, sp, #12
 *   @0x224a60 str r3, [r7, #0x808]
 *   @0x224a64 mvnhi r0, #0
 *   @0x224a68 lslls r0, r0, #8
 *   @0x224a6c mov r8, r3
 *   @0x224a70 addls r0, r0, #8
 *   @0x224a74 mov r10, r1
 *   @0x224a78 mov r9, r2
 *   @0x224a7c ldrb r4, [sp, #0x30]
 *   @0x224a80 bl 0x27d14c <_Znaj>
 *   @0x224a84 sub r6, r8, #1
 *   @0x224a88 cmn r6, #1
 *   @0x224a8c mov r3, #768
 *   @0x224a90 add r11, r0, #8
 *   @0x224a94 str r8, [r0, #0x4]
 *   @0x224a98 str r3, [r0]
 *   @0x224a9c movne r5, r11
 *   @0x224aa0 beq 0x224abc <_ZN14COggSyncThread6CreateEiiib+0x70>
 *   @0x224aa4 mov r0, r5
 *   @0x224aa8 sub r6, r6, #1
 *   @0x224aac bl 0x2233f4 <_ZN11SOggChannelC2Ev>
 *   @0x224ab0 cmn r6, #1
 *   @0x224ab4 add r5, r5, #768
 *   @0x224ab8 bne 0x224aa4 <_ZN14COggSyncThread6CreateEiiib+0x58>
 *   @0x224abc cmp r4, #0
 *   @0x224ac0 mov r5, #0
 *   @0x224ac4 mov r0, r11
 *   @0x224ac8 strb r5, [r7, #0x84c]
 *   @0x224acc str r10, [r7, #0x810]
 *   @0x224ad0 str r11, [r7, #0x804]
 *   @0x224ad4 strb r5, [r7, #0x800]
 *   @0x224ad8 strb r5, [r7, #0x801]
 *   @0x224adc strb r5, [r7, #0x802]
 *   @0x224ae0 strb r5, [r7, #0x84d]
 *   @0x224ae4 bne 0x224b8c <_ZN14COggSyncThread6CreateEiiib+0x140>
 *   @0x224ae8 cmp r8, #0
 *   @0x224aec ble 0x224b40 <_ZN14COggSyncThread6CreateEiiib+0xf4>
 *   @0x224af0 ldr r11, [pc, #0x124]
 *   @0x224af4 lsl r6, r10, #2
 *   @0x224af8 lsl r3, r9, #2
 *   @0x224afc str r3, [sp, #0x4]
 *   @0x224b00 ldr r11, [pc, r11]
 *   @0x224b04 add r3, r4, r4, lsl #1
 *   @0x224b08 ldr r2, [r11]
 *   @0x224b0c add r4, r4, #1
 *   @0x224b10 lsl r5, r3, #8
 *   @0x224b14 add r0, r0, r5
 *   @0x224b18 ldr r1, [r2, r6]
 *   @0x224b1c bl 0x223474 <_ZN11SOggChannel4InitEj>
 *   @0x224b20 ldr r0, [r7, #0x804]
 *   @0x224b24 ldr r3, [sp, #0x4]
 *   @0x224b28 cmp r4, r8
 *   @0x224b2c add r6, r6, r3
 *   @0x224b30 add r3, r0, r5
 *   @0x224b34 str r10, [r3, #0x2b8]
 *   @0x224b38 add r10, r10, r9
 *   @0x224b3c bne 0x224b04 <_ZN14COggSyncThread6CreateEiiib+0xb8>
 *   @0x224b40 cmp r8, #266338304
 *   @0x224b44 mvnhi r0, #0
 *   @0x224b48 lslls r0, r8, #3
 *   @0x224b4c bl 0x27d14c <_Znaj>
 *   @0x224b50 str r0, [r7, #0x82c]
 *   @0x224b54 mov r0, #8
 *   @0x224b58 bl 0x27c524 <_Znwj>
 *   @0x224b5c ldr r1, [pc, #0xbc]
 *   @0x224b60 add r1, pc, r1
 *   @0x224b64 mov r4, r0
 *   @0x224b68 bl 0x27e070 <_ZN5MutexC2EPKc>
 *   @0x224b6c str r4, [r7, #0x830]
 *   @0x224b70 mov r0, r7
 *   @0x224b74 bl 0x2249e0 <_ZN14COggSyncThread11StartThreadEv>
 *   @0x224b78 cmp r0, #0
 *   @0x224b7c movne r0, #1
 *   @0x224b80 strbne r0, [r7, #0x803]
 *   @0x224b84 add sp, sp, #12
 *   @0x224b88 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x224b8c movw r0, #0x807f
 *   @0x224b90 mov r4, r7
 *   @0x224b94 bl 0xb6544 <malloc@plt>
 *   @0x224b98 add r3, r0, #127
 *   @0x224b9c str r0, [r7, #0x858]
 *   @0x224ba0 bic r3, r3, #127
 *   @0x224ba4 mov r0, #1
 *   @0x224ba8 str r3, [r7, #0x85c]
 *   @0x224bac add r3, r3, #16384
 *   @0x224bb0 str r3, [r4, #0x860]!
 *   @0x224bb4 add r1, r4, #12
 *   @0x224bb8 bl 0xb6a90 <alGenSources@plt>
 *   @0x224bbc ldr r0, [r7, #0x86c]
 *   @0x224bc0 movw r1, #0x100a
 *   @0x224bc4 mov r2, #0
 *   @0x224bc8 bl 0xb6a78 <alSourcef@plt>
 *   @0x224bcc add r1, r4, #4
 *   @0x224bd0 mov r0, #2
 *   @0x224bd4 bl 0xb6af0 <alGenBuffers@plt>
 *   @0x224bd8 cmp r8, #0
 *   @0x224bdc str r5, [r7, #0x870]
 *   @0x224be0 ble 0x224b40 <_ZN14COggSyncThread6CreateEiiib+0xf4>
 *   @0x224be4 ldr r0, [r7, #0x804]
 *   @0x224be8 mov r4, r5
 *   @0x224bec mvn r6, #0
 *   @0x224bf0 add r0, r0, r4
 *   @0x224bf4 mvn r1, #0
 *   @0x224bf8 bl 0x223474 <_ZN11SOggChannel4InitEj>
 *   @0x224bfc ldr r0, [r7, #0x804]
 *   @0x224c00 add r5, r5, #1
 *   @0x224c04 add r3, r0, r4
 *   @0x224c08 cmp r5, r8
 *   @0x224c0c add r4, r4, #768
 *   @0x224c10 str r6, [r3, #0x2b8]
 *   @0x224c14 bne 0x224bf0 <_ZN14COggSyncThread6CreateEiiib+0x1a4>
 *   @0x224c18 b 0x224b40 <_ZN14COggSyncThread6CreateEiiib+0xf4>
 *   @0x224c1c andseq r12, r12, r12, asr #17
 *   @0x224c20 andseq r0, r3, r4, ror #3
 *
 * ══ §18/66 png_handle_iCCP  0x2ac814  size 472  118 条（0x2ac814..0x2ac9ec）
 * @func 0x2ac814 0x2ac9ec  size 472  118 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning×2 / png_crc_finish×2 / png_free×2 / png_crc_read / png_handle_iCCP+0xbe / png_decompress_chunk / png_handle_iCCP+0x178 / 0xb65c8
 * 字段偏移 top8: 0x1a8×1 / 0x180×1 / 0x16c×1 / 0x10c×1 / 0x1×1 / 0xfc×1 / 0xc×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ac814 ldr r3, [pc, #0x1a8]
 *   @0x2ac818 ldrbtmi r4, [r11], #-1008
 *   @0x2ac81c ldr r3, [r3]
 *   @0x2ac820 sub sp, #0x4c
 *   @0x2ac824 mov r4, r0
 *   @0x2ac828 mov r8, r3
 *   @0x2ac82c ldr.w r2, [r0, #0x12c]
 *   @0x2ac830 tst.w r2, #0x1
 *   @0x2ac834 bne 0x2ac840 <png_handle_iCCP+0x2c>
 *   @0x2ac838 add r1, pc
 *   @0x2ac83c .word 0xe00afdf7
 *   @0x2ac840 lsls r1, r2, #0x1d
 *   @0x2ac844 ldr r1, [pc, #0x180]
 *   @0x2ac848 b 0x2ac864 <png_handle_iCCP+0x50>
 *   @0x2ac84c bpl 0x2ac856 <png_handle_iCCP+0x42>
 *   @0x2ac850 add r1, pc
 *   @0x2ac854 strtmi pc, [r0], -pc, lsl #28
 *   @0x2ac858 cbz r7, 0x2ac872 <png_handle_iCCP+0x5e>
 *   @0x2ac85c lsls r3, r3, #0x13
 *   @0x2ac860 ldr r1, [pc, #0x16c]
 *   @0x2ac864 bl 0x2a6474 <png_warning>
 *   @0x2ac868 mov r0, r4
 *   @0x2ac86c bl 0x2abc94 <png_crc_finish>
 *   @0x2ac870 b 0x2ac9aa <png_handle_iCCP+0x196>
 *   @0x2ac874 .word 0xf7fa1330
 *   @0x2ac878 .word 0x1c69fa41
 *   @0x2ac87c mov r0, r4
 *   @0x2ac880 strtmi pc, [r10], -pc, lsl #20
 *   @0x2ac884 mov r1, r0
 *   @0x2ac888 qasxmi r0, r0, r0
 *   @0x2ac88c bl 0x2abc0c <png_crc_read>
 *   @0x2ac890 mov r0, r4
 *   @0x2ac894 bl 0x2abc94 <png_crc_finish>
 *   @0x2ac898 cmp r0, #0x0
 *   @0x2ac89c ldr.w r3, [r4, #0x330]
 *   @0x2ac8a0 strb r0, [r3, r5]
 *   @0x2ac8a4 .word 0x460a1330
 *   @0x2ac8a8 mov r3, r2
 *   @0x2ac8ac ldrb r0, [r3]
 *   @0x2ac8b0 bne 0x2ac8a8 <png_handle_iCCP+0x94>
 *   @0x2ac8b4 mov r0, r2
 *   @0x2ac8b8 add r2, r1
 *   @0x2ac8bc blo 0x2ac8d2 <png_handle_iCCP+0xbe>
 *   @0x2ac8c0 bl 0x2a6cfc <png_free>
 *   @0x2ac8c4 ldr r1, [pc, #0x10c]
 *   @0x2ac8c8 mov r0, r4
 *   @0x2ac8cc ldrbtmi r3, [r9], #-816
 *   @0x2ac8d0 b 0x2ac984 <png_handle_iCCP+0x170>
 *   @0x2ac8d4 ldrb r3, [r3, #0x1]
 *   @0x2ac8d8 ldr r1, [pc, #0xfc]
 *   @0x2ac8dc add r1, pc
 *   @0x2ac8e0 .word 0xf8d4fdc9
 *   @0x2ac8e4 qasxmi r3, r10, r0
 *   @0x2ac8e8 mov r0, r4
 *   @0x2ac8ec subs r6, r6, r3
 *   @0x2ac8f0 str r3, [sp]
 *   @0x2ac8f4 bl 0x2abd08 <png_decompress_chunk>
 *   @0x2ac8f8 ldr r5, [sp, #0xc]
 *   @0x2ac8fc bhi 0x2ac904 <png_handle_iCCP+0xf0>
 *   @0x2ac900 cmp r5, #0x3
 *   @0x2ac904 mov r0, r4
 *   @0x2ac908 .word 0xf7fa1330
 *   @0x2ac90c ldmdbmi r3!, {r0, r1, r2, r4, r5, r6, r7, r8, r11, r12, sp, lr, pc}
 *   @0x2ac910 movs r3, #0x0
 *   @0x2ac914 str.w r3, [r4, #0x330]
 *   @0x2ac918 add r1, pc
 *   @0x2ac91c ldr.w r2, [r4, #0x330]
 *   @0x2ac920 adds r1, r2, r6
 *   @0x2ac924 ldrb.w r9, [r1, #0x1]
 *   @0x2ac928 lsl.w r9, r9, #0x10
 *   @0x2ac92c orr.w r9, r9, r3, lsl #24
 *   @0x2ac930 ldrb r3, [r1, #0x3]
 *   @0x2ac934 stmvc r11, {r0, r1, r8, r11}
 *   @0x2ac938 orr.w r9, r9, r3, lsl #8
 *   @0x2ac93c cmp r9, r5
 *   @0x2ac940 bls 0x2ac98c <png_handle_iCCP+0x178>
 *   @0x2ac944 mov r0, r4
 *   @0x2ac948 stmdbmi r5!, {r0, r3, r4, r6, r7, r8, r11, r12, sp, lr, pc}
 *   @0x2ac94c movs r3, #0x0
 *   @0x2ac950 str.w r3, [r4, #0x330]
 *   @0x2ac954 add r1, pc
 *   @0x2ac958 cdpge p13, #0x0, c15, c4, c13, #0x4
 *   @0x2ac95c ldr r2, [pc, #0x84]
 *   @0x2ac960 movs r1, #0x32
 *   @0x2ac964 add r2, pc
 *   @0x2ac968 qasxmi lr, r0, r0
 *   @0x2ac96c mov r1, r6
 *   @0x2ac970 bmi 0xa2bf7c <b2_toiTime+0x2d2ad8>
 *   @0x2ac974 movs r1, #0x32
 *   @0x2ac978 add r2, pc
 *   @0x2ac97c blx 0xb65c8 <snprintf@plt>
 *   @0x2ac980 mov r0, r4
 *   @0x2ac984 bl 0x2a6474 <png_warning>
 *   @0x2ac988 b 0x2ac9aa <png_handle_iCCP+0x196>
 *   @0x2ac98c stm.w sp, {r1, r5}
 *   @0x2ac990 mov r0, r4
 *   @0x2ac994 movs r3, #0x0
 *   @0x2ac998 qsaxmi pc, r0, r7
 *   @0x2ac99c ldr.w r1, [r4, #0x330]
 *   @0x2ac9a0 bl 0x2a6cfc <png_free>
 *   @0x2ac9a4 movs r3, #0x0
 *   @0x2ac9a8 bls 0x6f9670 <g_SWFvertbuff+0x265a8>
 *   @0x2ac9ac ldr.w r3, [r8]
 *   @0x2ac9b0 cmp r2, r3
 *   @0x2ac9b4 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2ac9b8 add sp, #0x4c
 *   @0x2ac9bc svclt #0x83f0
 *   @0x2ac9c0 asrs r2, r7, #0x4
 *   @0x2ac9c4 lsrs r3, r3, #0x1
 *   @0x2ac9c8 lsrs r6, r4, #0x1
 *   @0x2ac9cc lsrs r4, r6, #0x1
 *   @0x2ac9d0 lsrs r2, r7, #0x1
 *   @0x2ac9d4 lsrs r3, r4, #0x20
 *   @0x2ac9d8 lsrs r2, r5, #0x20
 *   @0x2ac9dc lsrs r6, r3, #0x20
 *   @0x2ac9e0 lsrs r5, r1, #0x20
 *   @0x2ac9e4 lsrs r5, r3, #0x20
 *   @0x2ac9e8 lsrs r5, r4, #0x20
 *
 * ══ §19/66 void b2BroadPhase::UpdatePairs<b2ContactManager>(b2ContactManager*)  0x2c8300  size 472  118 条（0x2c8300..0x2c84d8）
 * @func 0x2c8300 0x2c84d8  size 472  118 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2c7f2c×2 / void b2BroadPhase::UpdatePairs<b2ContactManager>(b2ContactManager*)+0x1c8 / void b2DynamicTree::Query<b2BroadPhase>(b2BroadPhase*, b2AABB const&) const / anon_2c811c / void b2BroadPhase::UpdatePairs<b2ContactManager>(b2ContactManager*)+0x1b0 / void std::priv::__unguarded_linear_insert<b2Pair*, b2Pair, bool (*)(b2Pair const&, b2Pair const&)>(b2Pair*, b2Pair, bool (*)(b2Pair const&, b2Pair const&)) / b2ContactManager::AddPair(void*, void*) / void b2BroadPhase::UpdatePairs<b2ContactManager>(b2ContactManager*)+0x104
 * 字段偏移 top8: 0x34×5 / 0x4×5 / 0x28×4 / 0x2c×3 / 0x10×3 / 0x20×1 / 0x2×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c8300 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2c8304 mov r4, #0
 *   @0x2c8308 ldr r5, [r0, #0x28]
 *   @0x2c830c mov r8, r0
 *   @0x2c8310 mov r7, r1
 *   @0x2c8314 str r4, [r0, #0x34]
 *   @0x2c8318 cmp r5, r4
 *   @0x2c831c ble 0x2c84c8 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x1c8>
 *   @0x2c8320 ldr r3, [r8, #0x20]
 *   @0x2c8324 mov r0, r8
 *   @0x2c8328 mov r1, r8
 *   @0x2c832c ldr r3, [r3, r4, lsl #2]
 *   @0x2c8330 add r4, r4, #1
 *   @0x2c8334 cmn r3, #1
 *   @0x2c8338 add r2, r3, r3, lsl #3
 *   @0x2c833c str r3, [r8, #0x38]
 *   @0x2c8340 beq 0x2c8354 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x54>
 *   @0x2c8344 ldr r3, [r8, #0x4]
 *   @0x2c8348 add r2, r3, r2, lsl #2
 *   @0x2c834c bl 0x2c7cd4 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB>
 *   @0x2c8350 ldr r5, [r8, #0x28]
 *   @0x2c8354 cmp r5, r4
 *   @0x2c8358 bgt 0x2c8320 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x20>
 *   @0x2c835c ldr r12, [r8, #0x34]
 *   @0x2c8360 mov r2, #0
 *   @0x2c8364 ldr r9, [r8, #0x2c]
 *   @0x2c8368 str r2, [r8, #0x28]
 *   @0x2c836c add r6, r9, r12, lsl #3
 *   @0x2c8370 cmp r9, r6
 *   @0x2c8374 beq 0x2c83f8 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xf8>
 *   @0x2c8378 rsb r4, r9, r6
 *   @0x2c837c asr r3, r4, #3
 *   @0x2c8380 cmp r3, #1
 *   @0x2c8384 beq 0x2c839c <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x9c>
 *   @0x2c8388 asr r3, r3, #1
 *   @0x2c838c add r2, r2, #1
 *   @0x2c8390 cmp r3, #1
 *   @0x2c8394 bne 0x2c8388 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x88>
 *   @0x2c8398 lsl r2, r2, #1
 *   @0x2c839c ldr r5, [pc, #0x130]
 *   @0x2c83a0 mov r0, r9
 *   @0x2c83a4 mov r1, r6
 *   @0x2c83a8 ldr r5, [pc, r5]
 *   @0x2c83ac mov r3, r5
 *   @0x2c83b0 bl 0x2c811c <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x13c>
 *   @0x2c83b4 cmp r4, #135
 *   @0x2c83b8 ble 0x2c84b0 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x1b0>
 *   @0x2c83bc add r4, r9, #128
 *   @0x2c83c0 mov r0, r9
 *   @0x2c83c4 mov r2, r5
 *   @0x2c83c8 mov r1, r4
 *   @0x2c83cc bl 0x2c7f2c <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0x5c>
 *   @0x2c83d0 cmp r6, r4
 *   @0x2c83d4 beq 0x2c84c0 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x1c0>
 *   @0x2c83d8 mov r0, r4
 *   @0x2c83dc ldm r4, {r1, r2}
 *   @0x2c83e0 mov r3, r5
 *   @0x2c83e4 add r4, r4, #8
 *   @0x2c83e8 bl 0x2c7ed0 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_>
 *   @0x2c83ec cmp r6, r4
 *   @0x2c83f0 bne 0x2c83d8 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xd8>
 *   @0x2c83f4 ldr r12, [r8, #0x34]
 *   @0x2c83f8 mov r4, #0
 *   @0x2c83fc cmp r4, r12
 *   @0x2c8400 bge 0x2c84ac <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x1ac>
 *   @0x2c8404 ldr r5, [r8, #0x2c]
 *   @0x2c8408 lsl r9, r4, #3
 *   @0x2c840c ldr r3, [r8, #0x4]
 *   @0x2c8410 mov r0, r7
 *   @0x2c8414 add r10, r5, r9
 *   @0x2c8418 ldr r1, [r5, r4, lsl #3]
 *   @0x2c841c add r4, r4, #1
 *   @0x2c8420 ldr r2, [r10, #0x4]
 *   @0x2c8424 add r1, r1, r1, lsl #3
 *   @0x2c8428 add r2, r2, r2, lsl #3
 *   @0x2c842c add r1, r3, r1, lsl #2
 *   @0x2c8430 add r3, r3, r2, lsl #2
 *   @0x2c8434 ldr r1, [r1, #0x10]
 *   @0x2c8438 ldr r2, [r3, #0x10]
 *   @0x2c843c bl 0x2c7b08 <_ZN16b2ContactManager7AddPairEPvS0_>
 *   @0x2c8440 ldr r12, [r8, #0x34]
 *   @0x2c8444 cmp r4, r12
 *   @0x2c8448 bge 0x2c83fc <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xfc>
 *   @0x2c844c ldr r3, [r8, #0x2c]
 *   @0x2c8450 add r2, r9, #8
 *   @0x2c8454 ldr r1, [r5, r9]
 *   @0x2c8458 add r0, r3, r2
 *   @0x2c845c ldr r5, [r3, r2]
 *   @0x2c8460 cmp r5, r1
 *   @0x2c8464 bne 0x2c83fc <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xfc>
 *   @0x2c8468 ldr r6, [r0, #0x4]
 *   @0x2c846c ldr r2, [r10, #0x4]
 *   @0x2c8470 cmp r6, r2
 *   @0x2c8474 bne 0x2c83fc <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xfc>
 *   @0x2c8478 add r3, r3, r9
 *   @0x2c847c add r4, r4, #1
 *   @0x2c8480 cmp r4, r12
 *   @0x2c8484 beq 0x2c83fc <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xfc>
 *   @0x2c8488 ldr r2, [r3, #0x10]
 *   @0x2c848c add r3, r3, #8
 *   @0x2c8490 cmp r2, r5
 *   @0x2c8494 bne 0x2c83fc <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xfc>
 *   @0x2c8498 ldr r2, [r3, #0xc]
 *   @0x2c849c cmp r2, r6
 *   @0x2c84a0 beq 0x2c847c <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x17c>
 *   @0x2c84a4 cmp r4, r12
 *   @0x2c84a8 blt 0x2c8404 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x104>
 *   @0x2c84ac pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2c84b0 mov r0, r9
 *   @0x2c84b4 mov r1, r6
 *   @0x2c84b8 mov r2, r5
 *   @0x2c84bc bl 0x2c7f2c <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0x5c>
 *   @0x2c84c0 ldr r12, [r8, #0x34]
 *   @0x2c84c4 b 0x2c83f8 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xf8>
 *   @0x2c84c8 str r4, [r0, #0x28]
 *   @0x2c84cc mov r12, r4
 *   @0x2c84d0 b 0x2c83f8 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xf8>
 *   @0x2c84d4 andseq r9, r2, r4, asr #14
 *
 * ══ §20/66 b2Joint::Create(b2JointDef const*, b2BlockAllocator*)  0x2cdbc0  size 472  118 条（0x2cdbc0..0x2cdd98）
 * @func 0x2cdbc0 0x2cdd98  size 472  118 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Allocate(int)×11 / b2MotorJoint::b2MotorJoint(b2MotorJointDef const*) / b2RevoluteJoint::b2RevoluteJoint(b2RevoluteJointDef const*) / b2PrismaticJoint::b2PrismaticJoint(b2PrismaticJointDef const*) / b2DistanceJoint::b2DistanceJoint(b2DistanceJointDef const*) / b2PulleyJoint::b2PulleyJoint(b2PulleyJointDef const*) / b2MouseJoint::b2MouseJoint(b2MouseJointDef const*) / b2GearJoint::b2GearJoint(b2GearJointDef const*)
 * 字段偏移 top8: 0x1c×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cdbc0 push {r3, r4, r5, lr}
 *   @0x2cdbc4 mov r4, r0
 *   @0x2cdbc8 ldr r3, [r0]
 *   @0x2cdbcc sub r3, r3, #1
 *   @0x2cdbd0 cmp r3, #10
 *   @0x2cdbd4 addls pc, pc, r3, lsl #2
 *   @0x2cdbd8 b 0x2cdd6c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x1ac>
 *   @0x2cdbdc b 0x2cdc2c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x6c>
 *   @0x2cdbe0 b 0x2cdc4c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x8c>
 *   @0x2cdbe4 b 0x2cdc6c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0xac>
 *   @0x2cdbe8 b 0x2cdc8c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0xcc>
 *   @0x2cdbec b 0x2cdcac <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0xec>
 *   @0x2cdbf0 b 0x2cdccc <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x10c>
 *   @0x2cdbf4 b 0x2cdcec <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x12c>
 *   @0x2cdbf8 b 0x2cdd0c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x14c>
 *   @0x2cdbfc b 0x2cdd2c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x16c>
 *   @0x2cdc00 b 0x2cdd4c <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x18c>
 *   @0x2cdc04 b 0x2cdc08 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x48>
 *   @0x2cdc08 mov r0, r1
 *   @0x2cdc0c mov r1, #192
 *   @0x2cdc10 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cdc14 subs r5, r0, #0
 *   @0x2cdc18 beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdc1c mov r1, r4
 *   @0x2cdc20 bl 0x2ce6c4 <_ZN12b2MotorJointC2EPK15b2MotorJointDef>
 *   @0x2cdc24 mov r0, r5
 *   @0x2cdc28 pop {r3, r4, r5, pc}
 *   @0x2cdc2c mov r0, r1
 *   @0x2cdc30 mov r1, #228
 *   @0x2cdc34 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cdc38 subs r5, r0, #0
 *   @0x2cdc3c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdc40 mov r1, r4
 *   @0x2cdc44 bl 0x2d2064 <_ZN15b2RevoluteJointC2EPK18b2RevoluteJointDef>
 *   @0x2cdc48 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdc4c mov r0, r1
 *   @0x2cdc50 mov r1, #256
 *   @0x2cdc54 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cdc58 subs r5, r0, #0
 *   @0x2cdc5c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdc60 mov r1, r4
 *   @0x2cdc64 bl 0x2d0028 <_ZN16b2PrismaticJointC2EPK19b2PrismaticJointDef>
 *   @0x2cdc68 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdc6c mov r0, r1
 *   @0x2cdc70 mov r1, #176
 *   @0x2cdc74 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cdc78 subs r5, r0, #0
 *   @0x2cdc7c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdc80 mov r1, r4
 *   @0x2cdc84 bl 0x2cd2ac <_ZN15b2DistanceJointC2EPK18b2DistanceJointDef>
 *   @0x2cdc88 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdc8c mov r0, r1
 *   @0x2cdc90 mov r1, #196
 *   @0x2cdc94 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cdc98 subs r5, r0, #0
 *   @0x2cdc9c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdca0 mov r1, r4
 *   @0x2cdca4 bl 0x2d1084 <_ZN13b2PulleyJointC2EPK16b2PulleyJointDef>
 *   @0x2cdca8 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdcac mov r0, r1
 *   @0x2cdcb0 mov r1, #168
 *   @0x2cdcb4 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cdcb8 subs r5, r0, #0
 *   @0x2cdcbc beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdcc0 mov r1, r4
 *   @0x2cdcc4 bl 0x2cedbc <_ZN12b2MouseJointC2EPK15b2MouseJointDef>
 *   @0x2cdcc8 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdccc mov r0, r1
 *   @0x2cdcd0 mov r1, #276
 *   @0x2cdcd4 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cdcd8 subs r5, r0, #0
 *   @0x2cdcdc beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdce0 mov r1, r4
 *   @0x2cdce4 bl 0x2e4588 <_ZN11b2GearJointC2EPK14b2GearJointDef>
 *   @0x2cdce8 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdcec mov r0, r1
 *   @0x2cdcf0 mov r1, #224
 *   @0x2cdcf4 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cdcf8 subs r5, r0, #0
 *   @0x2cdcfc beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdd00 mov r1, r4
 *   @0x2cdd04 bl 0x2d4214 <_ZN12b2WheelJointC2EPK15b2WheelJointDef>
 *   @0x2cdd08 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdd0c mov r0, r1
 *   @0x2cdd10 mov r1, #208
 *   @0x2cdd14 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cdd18 subs r5, r0, #0
 *   @0x2cdd1c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdd20 mov r1, r4
 *   @0x2cdd24 bl 0x2d3724 <_ZN11b2WeldJointC2EPK14b2WeldJointDef>
 *   @0x2cdd28 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdd2c mov r0, r1
 *   @0x2cdd30 mov r1, #180
 *   @0x2cdd34 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cdd38 subs r5, r0, #0
 *   @0x2cdd3c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdd40 mov r1, r4
 *   @0x2cdd44 bl 0x2cda14 <_ZN15b2FrictionJointC2EPK18b2FrictionJointDef>
 *   @0x2cdd48 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdd4c mov r0, r1
 *   @0x2cdd50 mov r1, #168
 *   @0x2cdd54 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi>
 *   @0x2cdd58 subs r5, r0, #0
 *   @0x2cdd5c beq 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdd60 mov r1, r4
 *   @0x2cdd64 bl 0x2d2b48 <_ZN11b2RopeJointC2EPK14b2RopeJointDef>
 *   @0x2cdd68 b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdd6c ldr r3, [pc, #0x1c]
 *   @0x2cdd70 mov r0, #0
 *   @0x2cdd74 ldr r1, [pc, #0x18]
 *   @0x2cdd78 mov r5, r0
 *   @0x2cdd7c ldr r3, [pc, r3]
 *   @0x2cdd80 add r1, pc, r1
 *   @0x2cdd84 ldr r3, [r3]
 *   @0x2cdd88 blx r3
 *   @0x2cdd8c b 0x2cdc24 <_ZN7b2Joint6CreateEPK10b2JointDefP16b2BlockAllocator+0x64>
 *   @0x2cdd90 andseq r3, r2, r12, asr #14
 *   @0x2cdd94 andeq pc, r8, r0, asr #14
 *
 * ══ §21/66 F_RoomTileAddExt(RValue&, CInstance*, CInstance*, int, RValue*)  0x12ea48  size 468  117 条（0x12ea48..0x12ec1c）
 * @func 0x12ea48 0x12ec1c  size 468  117 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×9 / YYGetFloat(RValue const*, int)×3 / Background_Exists(int) / Room_Data(int) / CRoom::AddTileToStorage(int, int, int, int, int, int, int, int, float, float, unsigned int) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x24×2 / 0x30×2 / 0x28×2 / 0x34×2 / 0x2c×2 / 0xc×2 / 0x60×1 / 0x4×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12ea48 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x12ea4c sub sp, sp, #60
 *   @0x12ea50 mov r1, #0
 *   @0x12ea54 mov r5, r0
 *   @0x12ea58 ldr r4, [sp, #0x60]
 *   @0x12ea5c mov r0, r4
 *   @0x12ea60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ea64 mov r1, #1
 *   @0x12ea68 mov r7, r0
 *   @0x12ea6c mov r0, r4
 *   @0x12ea70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12ea74 mov r6, r0
 *   @0x12ea78 bl 0xc3640 <_Z17Background_Existsi>
 *   @0x12ea7c subs r1, r0, #0
 *   @0x12ea80 beq 0x12ebd0 <_Z16F_RoomTileAddExtR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x12ea84 mov r0, r7
 *   @0x12ea88 bl 0x1b52c4 <_Z9Room_Datai>
 *   @0x12ea8c subs r7, r0, #0
 *   @0x12ea90 beq 0x12ec04 <_Z16F_RoomTileAddExtR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x12ea94 mov r0, r4
 *   @0x12ea98 mov r1, #11
 *   @0x12ea9c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12eaa0 vmov s15, r0
 *   @0x12eaa4 vcmpe.f32 s15, #0
 *   @0x12eaa8 vmrs APSR_nzcv, fpscr
 *   @0x12eaac mvnmi r12, #-16777216
 *   @0x12eab0 bmi 0x12eae0 <_Z16F_RoomTileAddExtR6RValueP9CInstanceS2_iPS_+0x98>
 *   @0x12eab4 vmov.f32 s14, #1.000000e+00
 *   @0x12eab8 vcmpe.f32 s15, s14
 *   @0x12eabc vmrs APSR_nzcv, fpscr
 *   @0x12eac0 vldrle s14, [pc, #332]
 *   @0x12eac4 vmulle.f32 s15, s15, s14
 *   @0x12eac8 mvngt r12, #0
 *   @0x12eacc vcvtle.s32.f32 s15, s15
 *   @0x12ead0 vmovle r1, s15
 *   @0x12ead4 lslle r3, r1, #24
 *   @0x12ead8 mvnle r12, r3, lsr #24
 *   @0x12eadc mvnle r12, r12, lsl #24
 *   @0x12eae0 mov r1, #2
 *   @0x12eae4 mov r0, r4
 *   @0x12eae8 str r12, [sp, #0x24]
 *   @0x12eaec bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12eaf0 mov r1, #3
 *   @0x12eaf4 mov r10, r0
 *   @0x12eaf8 mov r0, r4
 *   @0x12eafc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12eb00 mov r1, #4
 *   @0x12eb04 mov r8, r0
 *   @0x12eb08 mov r0, r4
 *   @0x12eb0c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12eb10 mov r1, #5
 *   @0x12eb14 str r0, [sp, #0x30]
 *   @0x12eb18 mov r0, r4
 *   @0x12eb1c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12eb20 mov r1, #6
 *   @0x12eb24 mov r2, r0
 *   @0x12eb28 mov r0, r4
 *   @0x12eb2c str r2, [sp, #0x28]
 *   @0x12eb30 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12eb34 mov r1, #7
 *   @0x12eb38 mov r11, r0
 *   @0x12eb3c mov r0, r4
 *   @0x12eb40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12eb44 mov r1, #8
 *   @0x12eb48 mov r9, r0
 *   @0x12eb4c mov r0, r4
 *   @0x12eb50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12eb54 mov r1, #9
 *   @0x12eb58 str r0, [sp, #0x34]
 *   @0x12eb5c mov r0, r4
 *   @0x12eb60 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12eb64 mov r1, #10
 *   @0x12eb68 mov r3, r0
 *   @0x12eb6c mov r0, r4
 *   @0x12eb70 str r3, [sp, #0x2c]
 *   @0x12eb74 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x12eb78 ldr r1, [sp, #0x30]
 *   @0x12eb7c ldr r2, [sp, #0x28]
 *   @0x12eb80 ldr r3, [sp, #0x2c]
 *   @0x12eb84 str r1, [sp]
 *   @0x12eb88 ldr r12, [sp, #0x24]
 *   @0x12eb8c ldr r1, [sp, #0x34]
 *   @0x12eb90 str r2, [sp, #0x4]
 *   @0x12eb94 mov r2, r10
 *   @0x12eb98 str r3, [sp, #0x14]
 *   @0x12eb9c mov r3, r8
 *   @0x12eba0 str r1, [sp, #0x10]
 *   @0x12eba4 mov r1, r6
 *   @0x12eba8 str r11, [sp, #0x8]
 *   @0x12ebac str r9, [sp, #0xc]
 *   @0x12ebb0 str r12, [sp, #0x1c]
 *   @0x12ebb4 str r0, [sp, #0x18]
 *   @0x12ebb8 mov r0, r7
 *   @0x12ebbc bl 0x1aaf78 <_ZN5CRoom16AddTileToStorageEiiiiiiiiffj>
 *   @0x12ebc0 vmov s15, r0
 *   @0x12ebc4 vcvt.f64.s32 d7, s15
 *   @0x12ebc8 vmov r0, r1, d7
 *   @0x12ebcc b 0x12ebe8 <_Z16F_RoomTileAddExtR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x12ebd0 ldr r0, [pc, #0x40]
 *   @0x12ebd4 add r0, pc, r0
 *   @0x12ebd8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x12ebdc mov r1, #0
 *   @0x12ebe0 movt r1, #0xbff0
 *   @0x12ebe4 mov r0, #0
 *   @0x12ebe8 mov r3, #0
 *   @0x12ebec mov r2, r0
 *   @0x12ebf0 str r3, [r5, #0xc]
 *   @0x12ebf4 mov r3, r1
 *   @0x12ebf8 stm r5, {r2, r3}
 *   @0x12ebfc add sp, sp, #60
 *   @0x12ec00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x12ec04 mov r1, #0
 *   @0x12ec08 mov r0, #0
 *   @0x12ec0c movt r1, #0xbff0
 *   @0x12ec10 b 0x12ebe8 <_Z16F_RoomTileAddExtR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x12ec14 cmnmi pc, #0
 *   @0x12ec18 eoreq r11, r0, r4, lsl #8
 *
 * ══ §22/66 getTextureInfo(Texture*)  0x189968  size 468  117 条（0x189968..0x189b3c）
 * @func 0x189968 0x189b3c  size 468  117 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x189a10→0x3eb70c, 0x189a28→0x3eb70c, 0x189a78→0x3ebef0
 * 调用序列: png_destroy_read_struct×3 / png_create_info_struct×2 / png_sig_cmp / png_create_read_struct / png_set_longjmp_fn / 0xb6904 / png_set_read_fn / png_set_sig_bytes
 * 字段偏移 top8: 0x24×7 / 0x1c×4 / 0x18×4 / 0x2c×3 / 0x28×3 / 0xc×3 / 0xfc×2 / 0x194×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x189968 push {r4, lr}
 *   @0x18996c sub sp, sp, #72
 *   @0x189970 mov r1, #0
 *   @0x189974 mov r2, #8
 *   @0x189978 str r0, [sp, #0x1c]
 *   @0x18997c ldr r0, [r0, #0x2c]
 *   @0x189980 blx 0x2a5a4c <png_sig_cmp>
 *   @0x189984 ldr r1, [pc, #0x194]
 *   @0x189988 add r1, pc, r1
 *   @0x18998c str r1, [sp, #0x18]
 *   @0x189990 subs r1, r0, #0
 *   @0x189994 bne 0x189a24 <_Z14getTextureInfoP7Texture+0xbc>
 *   @0x189998 ldr r0, [pc, #0x184]
 *   @0x18999c mov r2, r1
 *   @0x1899a0 mov r3, r1
 *   @0x1899a4 add r0, pc, r0
 *   @0x1899a8 blx 0x2a6fdc <png_create_read_struct>
 *   @0x1899ac cmp r0, #0
 *   @0x1899b0 str r0, [sp, #0x24]
 *   @0x1899b4 beq 0x189a10 <_Z14getTextureInfoP7Texture+0xa8>
 *   @0x1899b8 blx 0x2a5b64 <png_create_info_struct>
 *   @0x1899bc cmp r0, #0
 *   @0x1899c0 str r0, [sp, #0x28]
 *   @0x1899c4 beq 0x189af8 <_Z14getTextureInfoP7Texture+0x190>
 *   @0x1899c8 ldr r0, [sp, #0x24]
 *   @0x1899cc blx 0x2a5b64 <png_create_info_struct>
 *   @0x1899d0 cmp r0, #0
 *   @0x1899d4 str r0, [sp, #0x2c]
 *   @0x1899d8 beq 0x189b0c <_Z14getTextureInfoP7Texture+0x1a4>
 *   @0x1899dc ldr r3, [pc, #0x144]
 *   @0x1899e0 mov r2, #256
 *   @0x1899e4 ldr r12, [sp, #0x18]
 *   @0x1899e8 ldr r0, [sp, #0x24]
 *   @0x1899ec ldr r1, [r12, r3]
 *   @0x1899f0 blx 0x2a653c <png_set_longjmp_fn>
 *   @0x1899f4 bl 0xb6904 <setjmp@plt>
 *   @0x1899f8 subs r4, r0, #0
 *   @0x1899fc beq 0x189a6c <_Z14getTextureInfoP7Texture+0x104>
 *   @0x189a00 add r0, sp, #36
 *   @0x189a04 add r1, sp, #40
 *   @0x189a08 add r2, sp, #44
 *   @0x189a0c blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x189a10 ldr r3, [pc, #0x114]
 *   @0x189a14 ldr r1, [sp, #0x18]
 *   @0x189a18 ldr r3, [r1, r3]
 *   @0x189a1c ldr r0, [r3]
 *   @0x189a20 b 0x189a50 <_Z14getTextureInfoP7Texture+0xe8>
 *   @0x189a24 ldr r2, [sp, #0x18]
 *   @0x189a28 ldr r3, [pc, #0xfc]
 *   @0x189a2c ldr r1, [pc, #0xfc]
 *   @0x189a30 ldr r3, [r2, r3]
 *   @0x189a34 add r1, pc, r1
 *   @0x189a38 ldr r4, [r3]
 *   @0x189a3c ldr r3, [r4]
 *   @0x189a40 mov r0, r4
 *   @0x189a44 ldr r3, [r3, #0xc]
 *   @0x189a48 blx r3
 *   @0x189a4c mov r0, r4
 *   @0x189a50 ldr r3, [r0]
 *   @0x189a54 ldr r1, [pc, #0xd8]
 *   @0x189a58 ldr r3, [r3, #0xc]
 *   @0x189a5c add r1, pc, r1
 *   @0x189a60 blx r3
 *   @0x189a64 add sp, sp, #72
 *   @0x189a68 pop {r4, pc}
 *   @0x189a6c ldr r0, [sp, #0x1c]
 *   @0x189a70 add r1, sp, #64
 *   @0x189a74 ldr r12, [sp, #0x1c]
 *   @0x189a78 ldr r2, [pc, #0xb8]
 *   @0x189a7c ldr r3, [r0, #0x2c]
 *   @0x189a80 add r2, pc, r2
 *   @0x189a84 ldr r0, [sp, #0x24]
 *   @0x189a88 add r3, r3, #8
 *   @0x189a8c str r12, [sp, #0x40]
 *   @0x189a90 str r3, [sp, #0x44]
 *   @0x189a94 blx 0x2a804c <png_set_read_fn>
 *   @0x189a98 ldr r0, [sp, #0x24]
 *   @0x189a9c mov r1, #8
 *   @0x189aa0 blx 0x2a5a24 <png_set_sig_bytes>
 *   @0x189aa4 ldr r0, [sp, #0x24]
 *   @0x189aa8 ldr r1, [sp, #0x28]
 *   @0x189aac blx 0x2a6ff0 <png_read_info>
 *   @0x189ab0 ldr r1, [sp, #0x28]
 *   @0x189ab4 add r3, sp, #48
 *   @0x189ab8 add r2, sp, #56
 *   @0x189abc str r3, [sp]
 *   @0x189ac0 add r3, sp, #52
 *   @0x189ac4 ldr r0, [sp, #0x24]
 *   @0x189ac8 str r3, [sp, #0x4]
 *   @0x189acc add r3, sp, #60
 *   @0x189ad0 str r4, [sp, #0x8]
 *   @0x189ad4 str r4, [sp, #0xc]
 *   @0x189ad8 str r4, [sp, #0x10]
 *   @0x189adc blx 0x2a693e <png_get_IHDR>
 *   @0x189ae0 ldr r2, [sp, #0x38]
 *   @0x189ae4 ldr r3, [sp, #0x3c]
 *   @0x189ae8 mov r1, #6
 *   @0x189aec ldr r0, [sp, #0x1c]
 *   @0x189af0 stm r0, {r1, r2, r3}
 *   @0x189af4 b 0x189a64 <_Z14getTextureInfoP7Texture+0xfc>
 *   @0x189af8 mov r1, r0
 *   @0x189afc add r0, sp, #36
 *   @0x189b00 mov r2, r1
 *   @0x189b04 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x189b08 b 0x189a10 <_Z14getTextureInfoP7Texture+0xa8>
 *   @0x189b0c mov r2, r0
 *   @0x189b10 add r1, sp, #40
 *   @0x189b14 add r0, sp, #36
 *   @0x189b18 blx 0x2a7e2c <png_destroy_read_struct>
 *   @0x189b1c b 0x189a10 <_Z14getTextureInfoP7Texture+0xa8>
 *   @0x189b20 eoreq r8, r6, r8, asr #5
 *   @0x189b24 mulseq r12, r8, r12
 *   @0x189b28 .word 0xffffe4ac
 *   @0x189b2c .word 0xffffbac4
 *   @0x189b30 mulseq r12, r8, r6
 *   @0x189b34 mulseq r12, r0, r6
 *   @0x189b38 .word 0xfffff74c
 *
 * ══ §23/66 CLayerManager::UpdateInstanceActivation(CRoom*, CInstance*)  0x1b8a28  size 468  117 条（0x1b8a28..0x1b8bfc）
 * @func 0x1b8a28 0x1b8bfc  size 468  117 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CLayerManager::GetLayerFromID(CRoom*, int) / CHashMapCalculateHash(int)
 * 字段偏移 top8: 0x60×4 / 0x4×3 / 0x8×2 / 0x1c8×1 / 0x174×1 / 0x170×1 / 0x78×1 / 0x118×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b8a28 ldr r3, [pc, #0x1c8]
 *   @0x1b8a2c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1b8a30 ldr r3, [pc, r3]
 *   @0x1b8a34 mov r8, r1
 *   @0x1b8a38 mov r4, r0
 *   @0x1b8a3c ldrb r3, [r3]
 *   @0x1b8a40 cmp r3, #0
 *   @0x1b8a44 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8a48 cmp r0, #0
 *   @0x1b8a4c popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8a50 cmp r1, #0
 *   @0x1b8a54 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8a58 ldrb r3, [r1, #0x174]
 *   @0x1b8a5c cmp r3, #0
 *   @0x1b8a60 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8a64 ldr r1, [r1, #0x170]
 *   @0x1b8a68 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1b8a6c subs r10, r0, #0
 *   @0x1b8a70 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8a74 ldr r0, [r8, #0x78]
 *   @0x1b8a78 bl 0x1b6e44 <_Z21CHashMapCalculateHashi>
 *   @0x1b8a7c ldr r12, [r4, #0x118]
 *   @0x1b8a80 ldr r1, [r4, #0x120]
 *   @0x1b8a84 bic r9, r0, #-2147483648
 *   @0x1b8a88 and r3, r9, r12
 *   @0x1b8a8c lsl r5, r3, #1
 *   @0x1b8a90 add r2, r5, r3
 *   @0x1b8a94 add r2, r1, r2, lsl #2
 *   @0x1b8a98 ldr r2, [r2, #0x8]
 *   @0x1b8a9c cmp r2, #0
 *   @0x1b8aa0 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8aa4 cmp r9, r2
 *   @0x1b8aa8 beq 0x1b8b1c <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance+0xf4>
 *   @0x1b8aac ldr r0, [r4, #0x110]
 *   @0x1b8ab0 and r2, r12, r2
 *   @0x1b8ab4 add r4, r3, r0
 *   @0x1b8ab8 rsb r2, r2, r4
 *   @0x1b8abc tst r2, r12
 *   @0x1b8ac0 popmi {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8ac4 mov r4, #0
 *   @0x1b8ac8 b 0x1b8adc <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance+0xb4>
 *   @0x1b8acc cmp r9, r2
 *   @0x1b8ad0 beq 0x1b8b14 <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance+0xec>
 *   @0x1b8ad4 cmp r6, r4
 *   @0x1b8ad8 poplt {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8adc add r3, r3, #1
 *   @0x1b8ae0 add r4, r4, #1
 *   @0x1b8ae4 and r3, r12, r3
 *   @0x1b8ae8 add r7, r3, r0
 *   @0x1b8aec lsl r5, r3, #1
 *   @0x1b8af0 add r2, r5, r3
 *   @0x1b8af4 add r2, r1, r2, lsl #2
 *   @0x1b8af8 ldr r2, [r2, #0x8]
 *   @0x1b8afc and r6, r12, r2
 *   @0x1b8b00 cmp r2, #0
 *   @0x1b8b04 rsb r6, r6, r7
 *   @0x1b8b08 and r6, r6, r12
 *   @0x1b8b0c bne 0x1b8acc <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance+0xa4>
 *   @0x1b8b10 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8b14 cmn r3, #1
 *   @0x1b8b18 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8b1c add r3, r5, r3
 *   @0x1b8b20 add r1, r1, r3, lsl #2
 *   @0x1b8b24 cmn r1, #4
 *   @0x1b8b28 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8b2c ldr r2, [r1, #0x4]
 *   @0x1b8b30 cmp r2, #0
 *   @0x1b8b34 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8b38 ldr r3, [r2, #0x10]
 *   @0x1b8b3c cmp r3, #0
 *   @0x1b8b40 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8b44 ldr r0, [r2, #0x18]
 *   @0x1b8b48 ldr r3, [r2, #0x14]
 *   @0x1b8b4c cmp r0, #0
 *   @0x1b8b50 strne r3, [r0, #0x14]
 *   @0x1b8b54 ldrne r3, [r2, #0x14]
 *   @0x1b8b58 ldrne r0, [r2, #0x18]
 *   @0x1b8b5c streq r3, [r10, #0x58]
 *   @0x1b8b60 cmp r3, #0
 *   @0x1b8b64 streq r0, [r10, #0x5c]
 *   @0x1b8b68 strne r0, [r3, #0x18]
 *   @0x1b8b6c ldrb r2, [r8, #0x69]
 *   @0x1b8b70 ldr r3, [r10, #0x60]
 *   @0x1b8b74 cmp r2, #0
 *   @0x1b8b78 sub r0, r3, #1
 *   @0x1b8b7c str r0, [r10, #0x60]
 *   @0x1b8b80 beq 0x1b8bc0 <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance+0x198>
 *   @0x1b8b84 ldr r0, [r10, #0x5c]
 *   @0x1b8b88 ldr r2, [r1, #0x4]
 *   @0x1b8b8c cmp r0, #0
 *   @0x1b8b90 str r3, [r10, #0x60]
 *   @0x1b8b94 strne r2, [r0, #0x14]
 *   @0x1b8b98 movne r3, #0
 *   @0x1b8b9c ldrne r1, [r10, #0x5c]
 *   @0x1b8ba0 streq r2, [r10, #0x5c]
 *   @0x1b8ba4 streq r2, [r10, #0x58]
 *   @0x1b8ba8 strne r1, [r2, #0x18]
 *   @0x1b8bac streq r0, [r2, #0x18]
 *   @0x1b8bb0 strne r2, [r10, #0x5c]
 *   @0x1b8bb4 streq r0, [r2, #0x14]
 *   @0x1b8bb8 strne r3, [r2, #0x14]
 *   @0x1b8bbc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8bc0 ldr r0, [r10, #0x58]
 *   @0x1b8bc4 ldr r1, [r1, #0x4]
 *   @0x1b8bc8 cmp r0, #0
 *   @0x1b8bcc str r3, [r10, #0x60]
 *   @0x1b8bd0 strne r1, [r0, #0x18]
 *   @0x1b8bd4 ldrne r3, [r10, #0x58]
 *   @0x1b8bd8 streq r1, [r10, #0x5c]
 *   @0x1b8bdc streq r1, [r10, #0x58]
 *   @0x1b8be0 strne r3, [r1, #0x14]
 *   @0x1b8be4 streq r0, [r1, #0x18]
 *   @0x1b8be8 strne r1, [r10, #0x58]
 *   @0x1b8bec streq r0, [r1, #0x14]
 *   @0x1b8bf0 strne r2, [r1, #0x18]
 *   @0x1b8bf4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b8bf8 .word 0x00234ef4
 *
 * ══ §24/66 F_JSScriptRef(RValue&, CInstance*, CInstance*, int, RValue*)  0x240da8  size 468  117 条（0x240da8..0x240f7c）
 * @func 0x240da8 0x240f7c  size 468  117 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x240e10→0x47f298, 0x240e80→0x544b48, 0x240eb8→0x756450
 * 调用序列: DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×3 / YYObjectBase::InternalGetYYVar(int)×3 / YYGetInt32(RValue const*, int) / Script_Data(int) / JS_StandardScriptRefConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / YYObjectBase::Add(char const*, int, int) / YYObjectBase::Alloc(unsigned int, int, bool) / YYObjectBase::Add(char const*, YYObjectBase*, int)
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0xe4×2 / 0x28×1 / 0x188×1 / 0x14c×1 / 0x148×1 / 0x68×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x240da8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x240dac sub sp, sp, #8
 *   @0x240db0 mov r7, r0
 *   @0x240db4 mov r8, r1
 *   @0x240db8 ldr r4, [sp, #0x28]
 *   @0x240dbc mov r1, #0
 *   @0x240dc0 mov r10, r2
 *   @0x240dc4 mov r9, r3
 *   @0x240dc8 ldr r5, [pc, #0x188]
 *   @0x240dcc mov r0, r4
 *   @0x240dd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x240dd4 add r5, pc, r5
 *   @0x240dd8 sub r0, r0, #99328
 *   @0x240ddc sub r0, r0, #672
 *   @0x240de0 bl 0x1e069c <_Z11Script_Datai>
 *   @0x240de4 subs r6, r0, #0
 *   @0x240de8 beq 0x240f14 <_Z13F_JSScriptRefR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x240dec str r4, [sp]
 *   @0x240df0 mov r1, r8
 *   @0x240df4 mov r2, r10
 *   @0x240df8 mov r3, r9
 *   @0x240dfc mov r0, r7
 *   @0x240e00 bl 0x240d20 <_Z31JS_StandardScriptRefConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x240e04 ldr r4, [r7]
 *   @0x240e08 ldr r2, [pc, #0x14c]
 *   @0x240e0c mov r1, #0
 *   @0x240e10 ldr r3, [pc, #0x148]
 *   @0x240e14 str r1, [r4, #0x68]
 *   @0x240e18 mov r0, r4
 *   @0x240e1c ldr r2, [r5, r2]
 *   @0x240e20 str r2, [r4, #0x90]
 *   @0x240e24 ldr r3, [r5, r3]
 *   @0x240e28 ldr r3, [r3]
 *   @0x240e2c cmp r3, r1
 *   @0x240e30 ldrne r2, [r3, #0xc]
 *   @0x240e34 moveq r1, r3
 *   @0x240e38 ldrne r1, [r3, #0x10]
 *   @0x240e3c addne r2, r2, #1
 *   @0x240e40 strne r2, [r3, #0xc]
 *   @0x240e44 mov r3, #6
 *   @0x240e48 str r1, [r4, #0x6c]
 *   @0x240e4c str r3, [r4, #0x78]
 *   @0x240e50 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x240e54 ldr r2, [r6, #0x8]
 *   @0x240e58 ldr r1, [pc, #0x104]
 *   @0x240e5c mov r0, r4
 *   @0x240e60 cmp r2, #0
 *   @0x240e64 str r6, [r4, #0x64]
 *   @0x240e68 str r2, [r4, #0x8c]
 *   @0x240e6c add r1, pc, r1
 *   @0x240e70 ldrne r2, [r2, #0x74]
 *   @0x240e74 mov r3, #0
 *   @0x240e78 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii>
 *   @0x240e7c ldr r0, [pc, #0xe4]
 *   @0x240e80 ldr r3, [pc, #0xe4]
 *   @0x240e84 mvn r1, #-16777216
 *   @0x240e88 mov r2, #0
 *   @0x240e8c ldr r0, [r5, r0]
 *   @0x240e90 str r0, [r4, #0x94]
 *   @0x240e94 ldr r3, [r5, r3]
 *   @0x240e98 ldr r0, [r3]
 *   @0x240e9c bl 0x19198c <_ZN12YYObjectBase5AllocEjib>
 *   @0x240ea0 ldr r1, [pc, #0xc8]
 *   @0x240ea4 ldr r2, [r7]
 *   @0x240ea8 mov r3, #6
 *   @0x240eac add r1, pc, r1
 *   @0x240eb0 mov r6, r0
 *   @0x240eb4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x240eb8 ldr r3, [pc, #0xb4]
 *   @0x240ebc mov r0, r6
 *   @0x240ec0 ldr r2, [pc, #0xb0]
 *   @0x240ec4 ldr r3, [r5, r3]
 *   @0x240ec8 add r2, pc, r2
 *   @0x240ecc str r2, [r6, #0x40]
 *   @0x240ed0 ldr r1, [r3]
 *   @0x240ed4 str r1, [r6, #0x18]
 *   @0x240ed8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x240edc ldr r1, [r4, #0x4]
 *   @0x240ee0 cmp r1, #0
 *   @0x240ee4 beq 0x240f1c <_Z13F_JSScriptRefR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x240ee8 str r6, [r1]
 *   @0x240eec mov r0, r4
 *   @0x240ef0 mov r1, r6
 *   @0x240ef4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x240ef8 ldr r1, [r4, #0x4]
 *   @0x240efc cmp r1, #0
 *   @0x240f00 movne r3, #6
 *   @0x240f04 strne r3, [r1, #0xc]
 *   @0x240f08 beq 0x240f2c <_Z13F_JSScriptRefR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x240f0c mov r3, #6
 *   @0x240f10 str r3, [r1, #0x8]
 *   @0x240f14 add sp, sp, #8
 *   @0x240f18 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x240f1c mov r0, r4
 *   @0x240f20 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x240f24 mov r1, r0
 *   @0x240f28 b 0x240ee8 <_Z13F_JSScriptRefR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x240f2c mov r0, r4
 *   @0x240f30 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x240f34 ldr r1, [r4, #0x4]
 *   @0x240f38 mov r3, #6
 *   @0x240f3c cmp r1, #0
 *   @0x240f40 str r3, [r0, #0xc]
 *   @0x240f44 bne 0x240f0c <_Z13F_JSScriptRefR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x240f48 mov r0, r4
 *   @0x240f4c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x240f50 mov r1, r0
 *   @0x240f54 b 0x240f0c <_Z13F_JSScriptRefR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x240f58 andseq r0, r11, r12, ror lr
 *   @0x240f5c .word 0xfffff8cc
 *   @0x240f60 .word 0xffffbf58
 *   @0x240f64 andeq pc, lr, r0, lsl #20
 *   @0x240f68 .word 0xfffff8d8
 *   @0x240f6c .word 0xffffc0c4
 *   @0x240f70 andseq r4, r1, r8, ror r6
 *   @0x240f74 .word 0xffffc050
 *   @0x240f78 mulseq r1, r8, r6
 *
 * ══ §25/66 _spEventTimeline_apply  0x280f40  size 468  117 条（0x280f40..0x281114）
 * @func 0x280f40 0x281114  size 468  117 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spEventTimeline_apply+0xf4×2 / _spEventTimeline_apply / _spEventTimeline_apply+0x74
 * 字段偏移 top8: 0x8×3 / 0xc×3 / 0x4×2 / 0x30×1 / 0x34×1 / 0x10×1
 * VFP 指令 37 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x280f40 push {r4, r5, r6, r7, r8, lr}
 *   @0x280f44 vpush {d8}
 *   @0x280f48 sub sp, sp, #16
 *   @0x280f4c mov r4, r0
 *   @0x280f50 vmov s15, r2
 *   @0x280f54 ldr r5, [sp, #0x30]
 *   @0x280f58 vmov s16, r3
 *   @0x280f5c ldr r6, [sp, #0x34]
 *   @0x280f60 cmp r5, #0
 *   @0x280f64 beq 0x281034 <_spEventTimeline_apply+0xf4>
 *   @0x280f68 vcmpe.f32 s15, s16
 *   @0x280f6c vmrs APSR_nzcv, fpscr
 *   @0x280f70 bgt 0x281040 <_spEventTimeline_apply+0x100>
 *   @0x280f74 ldr r3, [r0, #0x8]
 *   @0x280f78 ldr r0, [r0, #0xc]
 *   @0x280f7c add r3, r0, r3, lsl #2
 *   @0x280f80 vldr s14, [r3, #-4]
 *   @0x280f84 vcmpe.f32 s15, s14
 *   @0x280f88 vmrs APSR_nzcv, fpscr
 *   @0x280f8c bge 0x281034 <_spEventTimeline_apply+0xf4>
 *   @0x280f90 vldr s14, [r0]
 *   @0x280f94 vcmpe.f32 s16, s14
 *   @0x280f98 vmrs APSR_nzcv, fpscr
 *   @0x280f9c bmi 0x281034 <_spEventTimeline_apply+0xf4>
 *   @0x280fa0 vcmpe.f32 s15, s14
 *   @0x280fa4 ldr r8, [r4, #0x8]
 *   @0x280fa8 vmrs APSR_nzcv, fpscr
 *   @0x280fac movmi r3, #0
 *   @0x280fb0 bpl 0x281074 <_spEventTimeline_apply+0x134>
 *   @0x280fb4 cmp r3, r8
 *   @0x280fb8 bge 0x281034 <_spEventTimeline_apply+0xf4>
 *   @0x280fbc lsl r1, r3, #2
 *   @0x280fc0 add r0, r0, r1
 *   @0x280fc4 vldr s15, [r0]
 *   @0x280fc8 vcmpe.f32 s16, s15
 *   @0x280fcc vmrs APSR_nzcv, fpscr
 *   @0x280fd0 blt 0x281034 <_spEventTimeline_apply+0xf4>
 *   @0x280fd4 ldr r0, [r6]
 *   @0x280fd8 add r2, r1, #4
 *   @0x280fdc add r8, r0, #1
 *   @0x280fe0 rsb r8, r3, r8
 *   @0x280fe4 add r0, r5, r0, lsl #2
 *   @0x280fe8 b 0x281008 <_spEventTimeline_apply+0xc8>
 *   @0x280fec ldr r12, [r4, #0xc]
 *   @0x280ff0 add r2, r12, r2
 *   @0x280ff4 vldr s15, [r2]
 *   @0x280ff8 vcmpe.f32 s16, s15
 *   @0x280ffc mov r2, r7
 *   @0x281000 vmrs APSR_nzcv, fpscr
 *   @0x281004 blt 0x281034 <_spEventTimeline_apply+0xf4>
 *   @0x281008 ldr r5, [r4, #0x10]
 *   @0x28100c add r12, r8, r3
 *   @0x281010 add r3, r3, #1
 *   @0x281014 add r7, r2, #4
 *   @0x281018 ldr r5, [r5, r1]
 *   @0x28101c mov r1, r2
 *   @0x281020 str r5, [r0], #4
 *   @0x281024 str r12, [r6]
 *   @0x281028 ldr r12, [r4, #0x8]
 *   @0x28102c cmp r12, r3
 *   @0x281030 bgt 0x280fec <_spEventTimeline_apply+0xac>
 *   @0x281034 add sp, sp, #16
 *   @0x281038 vpop {d8}
 *   @0x28103c pop {r4, r5, r6, r7, r8, pc}
 *   @0x281040 vldr s15, [sp, #56]
 *   @0x281044 str r5, [sp]
 *   @0x281048 vstr s15, [sp, #8]
 *   @0x28104c str r6, [sp, #0x4]
 *   @0x281050 mov r3, #1325400064
 *   @0x281054 bl 0x280f40 <_spEventTimeline_apply>
 *   @0x281058 ldr r0, [r4, #0xc]
 *   @0x28105c vldr s14, [r0]
 *   @0x281060 vcmpe.f32 s16, s14
 *   @0x281064 vmov.f32 s15, #-1.000000e+00
 *   @0x281068 vmrs APSR_nzcv, fpscr
 *   @0x28106c bpl 0x280fa0 <_spEventTimeline_apply+0x60>
 *   @0x281070 b 0x281034 <_spEventTimeline_apply+0xf4>
 *   @0x281074 subs r2, r8, #2
 *   @0x281078 beq 0x281108 <_spEventTimeline_apply+0x1c8>
 *   @0x28107c asr r1, r2, #1
 *   @0x281080 mov r3, #0
 *   @0x281084 add r12, r1, #1
 *   @0x281088 add r7, r0, r12, lsl #2
 *   @0x28108c vldr s14, [r7]
 *   @0x281090 vcmpe.f32 s15, s14
 *   @0x281094 vmrs APSR_nzcv, fpscr
 *   @0x281098 movge r3, r12
 *   @0x28109c movlt r2, r1
 *   @0x2810a0 add r1, r3, r2
 *   @0x2810a4 cmp r3, r2
 *   @0x2810a8 asr r1, r1, #1
 *   @0x2810ac bne 0x281084 <_spEventTimeline_apply+0x144>
 *   @0x2810b0 add r3, r3, #1
 *   @0x2810b4 cmp r3, #0
 *   @0x2810b8 lsl r2, r3, #2
 *   @0x2810bc add r1, r0, r2
 *   @0x2810c0 vldr s14, [r1]
 *   @0x2810c4 ble 0x280fb4 <_spEventTimeline_apply+0x74>
 *   @0x2810c8 sub r2, r2, #4
 *   @0x2810cc add r2, r0, r2
 *   @0x2810d0 vldr s15, [r2]
 *   @0x2810d4 vcmp.f32 s15, s14
 *   @0x2810d8 vmrs APSR_nzcv, fpscr
 *   @0x2810dc bne 0x280fb4 <_spEventTimeline_apply+0x74>
 *   @0x2810e0 add r2, r0, r3, lsl #2
 *   @0x2810e4 b 0x2810f8 <_spEventTimeline_apply+0x1b8>
 *   @0x2810e8 vldr s15, [r2, #-4]
 *   @0x2810ec vcmp.f32 s15, s14
 *   @0x2810f0 vmrs APSR_nzcv, fpscr
 *   @0x2810f4 bne 0x280fb4 <_spEventTimeline_apply+0x74>
 *   @0x2810f8 subs r3, r3, #1
 *   @0x2810fc sub r2, r2, #4
 *   @0x281100 bne 0x2810e8 <_spEventTimeline_apply+0x1a8>
 *   @0x281104 b 0x280fb4 <_spEventTimeline_apply+0x74>
 *   @0x281108 vldr s14, [r0, #4]
 *   @0x28110c mov r3, #1
 *   @0x281110 b 0x2810cc <_spEventTimeline_apply+0x18c>
 *
 * ══ §26/66 Java_com_yoyogames_runner_RunnerJNILib_TouchEvent  0x291c6c  size 468  117 条（0x291c6c..0x291e40）
 * @func 0x291c6c 0x291e40  size 468  117 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x291c8c→0x3f26c0, 0x291ccc→0x3f26bc, 0x291d18→0x756d48, 0x291d68→0x535700, 0x291d8c→0x53468c, 0x291d90→0x534664, 0x291db8→0x535700, 0x291de0→0x535700
 * 调用序列: setJNIEnv / Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x110
 * 字段偏移 top8: 0x2×4 / 0x18c×2 / 0x9c×2 / 0x38×2 / 0x150×1 / 0x108×1 / 0x10×1 / 0x6c×1
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x291c6c push {r4, r5, r6, lr}
 *   @0x291c70 vpush {d8}
 *   @0x291c74 mov r4, r3
 *   @0x291c78 vldr s17, [sp, #24]
 *   @0x291c7c vldr s16, [sp, #28]
 *   @0x291c80 mov r5, r2
 *   @0x291c84 bl 0x290614 <setJNIEnv>
 *   @0x291c88 ldr r3, [pc, #0x18c]
 *   @0x291c8c ldr r2, [pc, #0x18c]
 *   @0x291c90 vldr s15, [pc, #384]
 *   @0x291c94 add r3, pc, r3
 *   @0x291c98 vcmp.f32 s17, s15
 *   @0x291c9c vldr s14, [pc, #372]
 *   @0x291ca0 ldr r2, [r3, r2]
 *   @0x291ca4 vmrs APSR_nzcv, fpscr
 *   @0x291ca8 vmovmi.f32 s17, s15
 *   @0x291cac ldr r2, [r2]
 *   @0x291cb0 vmov s13, r2
 *   @0x291cb4 vcvt.f32.s32 s15, s13
 *   @0x291cb8 vcmpe.f32 s17, s15
 *   @0x291cbc vmrs APSR_nzcv, fpscr
 *   @0x291cc0 subge r2, r2, #1
 *   @0x291cc4 vcmp.f32 s16, s14
 *   @0x291cc8 vmovge s17, r2
 *   @0x291ccc ldr r2, [pc, #0x150]
 *   @0x291cd0 ldr r2, [r3, r2]
 *   @0x291cd4 vcvtge.f32.s32 s17, s17
 *   @0x291cd8 vmrs APSR_nzcv, fpscr
 *   @0x291cdc ldr r2, [r2]
 *   @0x291ce0 vmov s13, r2
 *   @0x291ce4 vmovmi.f32 s16, s14
 *   @0x291ce8 vcvt.f32.s32 s15, s13
 *   @0x291cec vcmpe.f32 s16, s15
 *   @0x291cf0 vcvt.s32.f32 s17, s17
 *   @0x291cf4 vmrs APSR_nzcv, fpscr
 *   @0x291cf8 subge r2, r2, #1
 *   @0x291cfc vmovge s16, r2
 *   @0x291d00 vcvtge.f32.s32 s16, s16
 *   @0x291d04 cmp r4, #9
 *   @0x291d08 vmov r6, s17
 *   @0x291d0c bls 0x291d7c <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x110>
 *   @0x291d10 vcvt.s32.f32 s16, s16
 *   @0x291d14 vmov r12, s16
 *   @0x291d18 ldr r2, [pc, #0x108]
 *   @0x291d1c add r0, r4, r4, lsl #2
 *   @0x291d20 lsl r0, r0, #2
 *   @0x291d24 ldr r2, [r3, r2]
 *   @0x291d28 add r1, r0, r2
 *   @0x291d2c stmib r1, {r6, r12}
 *   @0x291d30 str r4, [r1, #0x10]
 *   @0x291d34 cmp r5, #6
 *   @0x291d38 addls pc, pc, r5, lsl #2
 *   @0x291d3c b 0x291d74 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x108>
 *   @0x291d40 b 0x291dd0 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x164>
 *   @0x291d44 b 0x291d5c <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0xf0>
 *   @0x291d48 b 0x291da8 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x13c>
 *   @0x291d4c b 0x291d74 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x108>
 *   @0x291d50 b 0x291d74 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x108>
 *   @0x291d54 b 0x291dd0 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x164>
 *   @0x291d58 b 0x291d5c <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0xf0>
 *   @0x291d5c cmp r4, #9
 *   @0x291d60 mov r1, #0
 *   @0x291d64 str r1, [r0, r2]
 *   @0x291d68 ldrls r2, [pc, #0xbc]
 *   @0x291d6c ldrls r3, [r3, r2]
 *   @0x291d70 strls r1, [r3, r4, lsl #2]
 *   @0x291d74 vpop {d8}
 *   @0x291d78 pop {r4, r5, r6, pc}
 *   @0x291d7c cmp r4, #0
 *   @0x291d80 beq 0x291df4 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x188>
 *   @0x291d84 vcvt.s32.f32 s16, s16
 *   @0x291d88 vmov r12, s16
 *   @0x291d8c ldr r1, [pc, #0x9c]
 *   @0x291d90 ldr r2, [pc, #0x9c]
 *   @0x291d94 ldr r1, [r3, r1]
 *   @0x291d98 str r6, [r1, r4, lsl #2]
 *   @0x291d9c ldr r2, [r3, r2]
 *   @0x291da0 str r12, [r2, r4, lsl #2]
 *   @0x291da4 b 0x291d18 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0xac>
 *   @0x291da8 cmp r4, #9
 *   @0x291dac mov r1, #-2147483646
 *   @0x291db0 str r1, [r0, r2]
 *   @0x291db4 bhi 0x291d74 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x108>
 *   @0x291db8 ldr r1, [pc, #0x6c]
 *   @0x291dbc mov r2, #1
 *   @0x291dc0 ldr r3, [r3, r1]
 *   @0x291dc4 str r2, [r3, r4, lsl #2]
 *   @0x291dc8 vpop {d8}
 *   @0x291dcc pop {r4, r5, r6, pc}
 *   @0x291dd0 cmp r4, #9
 *   @0x291dd4 mov r1, #-2147483645
 *   @0x291dd8 str r1, [r0, r2]
 *   @0x291ddc bhi 0x291d74 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x108>
 *   @0x291de0 ldr r1, [pc, #0x44]
 *   @0x291de4 mov r2, #1
 *   @0x291de8 ldr r3, [r3, r1]
 *   @0x291dec str r2, [r3, r4, lsl #2]
 *   @0x291df0 b 0x291dc8 <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x15c>
 *   @0x291df4 vcvt.s32.f32 s16, s16
 *   @0x291df8 ldr r2, [pc, #0x38]
 *   @0x291dfc ldr r1, [pc, #0x38]
 *   @0x291e00 ldr r0, [r3, r2]
 *   @0x291e04 vstr s17, [r0]
 *   @0x291e08 ldr r1, [r3, r1]
 *   @0x291e0c vmov r12, s16
 *   @0x291e10 vstr s16, [r1]
 *   @0x291e14 b 0x291d8c <Java_com_yoyogames_runner_RunnerJNILib_TouchEvent+0x120>
 *   @0x291e18 andeq r0, r0, r0
 *   @0x291e1c ldrheq pc, [r5], -r12
 *   @0x291e20 .word 0xffffe24c
 *   @0x291e24 .word 0xffffe250
 *   @0x291e28 .word 0xfffffcf4
 *   @0x291e2c .word 0xffffe9dc
 *   @0x291e30 .word 0xffffdf4c
 *   @0x291e34 .word 0xffffdf48
 *   @0x291e38 .word 0xffffe720
 *   @0x291e3c .word 0xffffe724
 *
 * ══ §27/66 FT_Raccess_Get_HeaderInfo  0x2e6b50  size 468  117 条（0x2e6b50..0x2e6d24）
 * @func 0x2e6b50 0x2e6d24  size 468  117 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FT_Stream_Seek×2 / FT_Raccess_Get_HeaderInfo+0x46×2 / 0x3b0c5c / FT_Stream_Read / FT_Stream_Skip / FT_Stream_ReadUShort
 * 字段偏移 top8: 0xc×2 / 0x10×2 / 0x8×1 / 0x5c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e6b50 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e6b54 sub sp, #0x3c
 *   @0x2e6b58 mov r0, r1
 *   @0x2e6b5c mov r4, r1
 *   @0x2e6b60 ldr r6, [r6]
 *   @0x2e6b64 mov r5, r2
 *   @0x2e6b68 ldr r3, [r6]
 *   @0x2e6b6c bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2e6b70 str r6, [sp, #0xc]
 *   @0x2e6b74 cmp r0, #0x0
 *   @0x2e6b78 cdpge p0, #0x0, c8, c5, c9, #0x6
 *   @0x2e6b7c mov r0, r4
 *   @0x2e6b80 mov r1, r6
 *   @0x2e6b84 andls pc, r4, r4, lsl #30
 *   @0x2e6b88 cmp r0, #0x0
 *   @0x2e6b8c .word 0xf89d80bf
 *   @0x2e6b90 .word 0x06081014
 *   @0x2e6b94 bpl 0x2e6b9a <FT_Raccess_Get_HeaderInfo+0x4a>
 *   @0x2e6b98 b 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc>
 *   @0x2e6b9c .word 0xf01cc018
 *   @0x2e6ba0 mvnsle r0, r0, lsl #31
 *   @0x2e6ba4 ldrb.w r0, [sp, #0x1c]
 *   @0x2e6ba8 lsls r2, r0, #0x18
 *   @0x2e6bac ldrb.w r2, [sp, #0x20]
 *   @0x2e6bb0 lsls r3, r2, #0x18
 *   @0x2e6bb4 ldrb.w r3, [sp, #0x15]
 *   @0x2e6bb8 ldrb.w r8, [sp, #0x17]
 *   @0x2e6bbc ldrb.w r11, [sp, #0x1d]
 *   @0x2e6bc0 lsls r3, r3, #0x10
 *   @0x2e6bc4 b 0x13cec48 <b2_toiTime+0xc757a4>
 *   @0x2e6bc8 .word 0xf89d6101
 *   @0x2e6bcc b 0x1332c2c <b2_toiTime+0xbd9788>
 *   @0x2e6bd0 .word 0xf89d0108
 *   @0x2e6bd4 .word 0xf89d801b
 *   @0x2e6bd8 b 0x134ac6c <b2_toiTime+0xbf17c8>
 *   @0x2e6bdc .word 0xf89d2303
 *   @0x2e6be0 eorsvs r1, r11, r9, lsl r0
 *   @0x2e6be4 lsls r1, r1, #0x10
 *   @0x2e6be8 .word 0xf89d610c
 *   @0x2e6bec b 0x1356c5c <b2_toiTime+0xbfd7b8>
 *   @0x2e6bf0 .word 0xf89d0108
 *   @0x2e6bf4 b 0x1746c74 <b2_toiTime+0xfed7d0>
 *   @0x2e6bf8 .word 0xf8cd210c
 *   @0x2e6bfc .word 0xf89d8000
 *   @0x2e6c00 .word 0xf8cd8021
 *   @0x2e6c04 .word 0xf89d8004
 *   @0x2e6c08 sbcle r8, r4, r2, lsr #32
 *   @0x2e6c0c ldr.w r12, [sp]
 *   @0x2e6c10 lsl.w r11, r11, #0x10
 *   @0x2e6c14 orr.w r11, r11, r0, lsl #24
 *   @0x2e6c18 cmp r3, r1
 *   @0x2e6c1c b 0x15a984c <b2_toiTime+0xe503a8>
 *   @0x2e6c20 .word 0xf8dd2b0c
 *   @0x2e6c24 b 0x16d6c3c <b2_toiTime+0xf7d798>
 *   @0x2e6c28 b 0x12f6c60 <b2_toiTime+0xb9d7bc>
 *   @0x2e6c2c b 0x137f43c <b2_toiTime+0xc25f98>
 *   @0x2e6c30 b 0x152905c <b2_toiTime+0xdcfbb8>
 *   @0x2e6c34 ble 0x3b0c5c <error_g0017+0x9900>
 *   @0x2e6c38 rsb r2, r11, r1
 *   @0x2e6c3c cmp r3, r2
 *   @0x2e6c40 rsb r2, r8, r3
 *   @0x2e6c44 cmp r1, r2
 *   @0x2e6c48 mvn r2, #0x80000000
 *   @0x2e6c4c rsb r2, r11, r2
 *   @0x2e6c50 cmp r2, r3
 *   @0x2e6c54 mvn r2, #0x80000000
 *   @0x2e6c58 rsb r2, r8, r2
 *   @0x2e6c5c cmp r2, r1
 *   @0x2e6c60 add.w r0, r3, r11
 *   @0x2e6c64 mvn r2, #0x80000000
 *   @0x2e6c68 subs r2, r2, r0
 *   @0x2e6c6c blt 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46>
 *   @0x2e6c70 .word 0xf06f0008
 *   @0x2e6c74 bne 0x77747c <b2_toiTime+0x1dfd8>
 *   @0x2e6c78 cmp r2, r5
 *   @0x2e6c7c add r3, r5
 *   @0x2e6c80 add r11, r3
 *   @0x2e6c84 bhi 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46>
 *   @0x2e6c88 add r8, r5
 *   @0x2e6c8c bhi 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46>
 *   @0x2e6c90 mov r0, r4
 *   @0x2e6c94 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2e6c98 str r0, [sp, #0x10]
 *   @0x2e6c9c bne 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc>
 *   @0x2e6ca0 ldrb.w r3, [sp, #0x23]
 *   @0x2e6ca4 mov r0, r4
 *   @0x2e6ca8 mov r1, r7
 *   @0x2e6cac strb.w r3, [sp, #0x33]
 *   @0x2e6cb0 bl 0x2e698e <FT_Stream_Read>
 *   @0x2e6cb4 str r0, [sp, #0x10]
 *   @0x2e6cb8 movs r3, #0x1
 *   @0x2e6cbc ldrb r1, [r7, r0]
 *   @0x2e6cc0 andlo r12, r1, r0
 *   @0x2e6cc4 cmp r1, #0x0
 *   @0x2e6cc8 movne r2, #0x0
 *   @0x2e6ccc it ne
 *   @0x2e6cd0 cmp r0, #0x10
 *   @0x2e6cd4 cbnz r2, 0x2e6cdc <FT_Raccess_Get_HeaderInfo+0x18c>
 *   @0x2e6cd8 beq.w 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46>
 *   @0x2e6cdc movs r1, #0x8
 *   @0x2e6ce0 bl 0x2e6930 <FT_Stream_Skip>
 *   @0x2e6ce4 add r1, sp, #0x38
 *   @0x2e6ce8 strtmi r0, [r0], -r8, lsr #26
 *   @0x2e6cec bl 0x2e6b04 <FT_Stream_ReadUShort>
 *   @0x2e6cf0 sxth r1, r0
 *   @0x2e6cf4 cbnz r0, 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc>
 *   @0x2e6cf8 blt.w 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46>
 *   @0x2e6cfc add r5, r1
 *   @0x2e6d00 mov r1, r5
 *   @0x2e6d04 stmdblt r8, {r4, r6, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2e6d08 ldr r3, [sp, #0x8]
 *   @0x2e6d0c ldr r1, [sp, #0xc]
 *   @0x2e6d10 ldr r3, [r1]
 *   @0x2e6d14 beq 0x2e6d1a <FT_Raccess_Get_HeaderInfo+0x1ca>
 *   @0x2e6d18 andlt lr, pc, lr, asr r12
 *   @0x2e6d1c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e6d20 ldr r6, [r6, #0x5c]
 *
 * ══ §28/66 KickAsyncBuffer(bool, SAsyncBuffer*, char const*, bool)  0xc70c4  size 464  116 条（0xc70c4..0xc7294）
 * @func 0xc70c4 0xc7294  size 464  116 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xc70d4→0x47a138, 0xc70fc→0x47a134, 0xc7120→0x3eb70c, 0xc71d4→0x3eb7d8
 * 调用序列: LoadSave::BundleFileExists(char const*) / operator new(unsigned int) / HTTP_REQ_CONTEXT::HTTP_REQ_CONTEXT(char const*, int, int (*)(HTTP_REQ_CONTEXT*, void*, int*), void (*)(HTTP_REQ_CONTEXT*), void*, bool) / YYStrDup(char const*) / YYError(char const*, ...)
 * 字段偏移 top8: 0x8×3 / 0xc×3 / 0x14×2 / 0x4c×2 / 0x194×1 / 0x190×1 / 0x16c×1 / 0x14c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc70c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc70c8 mov r8, r0
 *   @0xc70cc ldr r6, [pc, #0x194]
 *   @0xc70d0 sub sp, sp, #28
 *   @0xc70d4 ldr r0, [pc, #0x190]
 *   @0xc70d8 mov r11, r3
 *   @0xc70dc add r6, pc, r6
 *   @0xc70e0 str r2, [sp, #0x14]
 *   @0xc70e4 mov r9, r1
 *   @0xc70e8 ldr r3, [r6, r0]
 *   @0xc70ec ldr r2, [r3]
 *   @0xc70f0 cmp r2, #0
 *   @0xc70f4 movne r2, #0
 *   @0xc70f8 strne r2, [r3]
 *   @0xc70fc ldr r3, [pc, #0x16c]
 *   @0xc7100 ldr r3, [r6, r3]
 *   @0xc7104 ldr r2, [r3]
 *   @0xc7108 cmp r2, #0
 *   @0xc710c movne r2, #0
 *   @0xc7110 strne r2, [r3]
 *   @0xc7114 cmp r8, #0
 *   @0xc7118 bne 0xc71a4 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0xe0>
 *   @0xc711c cmp r1, #0
 *   @0xc7120 ldr r3, [pc, #0x14c]
 *   @0xc7124 beq 0xc7224 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0x160>
 *   @0xc7128 ldr r3, [r6, r3]
 *   @0xc712c mov r4, r1
 *   @0xc7130 ldr r7, [pc, #0x140]
 *   @0xc7134 mov r10, r8
 *   @0xc7138 add r7, pc, r7
 *   @0xc713c ldr r5, [r3]
 *   @0xc7140 b 0xc7150 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0x8c>
 *   @0xc7144 ldr r4, [r4]
 *   @0xc7148 cmp r4, #0
 *   @0xc714c beq 0xc7230 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0x16c>
 *   @0xc7150 ldr r3, [r5]
 *   @0xc7154 mov r0, r5
 *   @0xc7158 mov r1, r7
 *   @0xc715c ldr r2, [r4, #0x8]
 *   @0xc7160 add r10, r10, #1
 *   @0xc7164 ldr r3, [r3, #0xc]
 *   @0xc7168 blx r3
 *   @0xc716c ldr r0, [r4, #0x8]
 *   @0xc7170 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0xc7174 cmp r0, #0
 *   @0xc7178 beq 0xc7144 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0x80>
 *   @0xc717c ldr lr, [r5]
 *   @0xc7180 mov r0, r5
 *   @0xc7184 ldr r1, [pc, #0xf0]
 *   @0xc7188 mov r2, r10
 *   @0xc718c mov r3, #1
 *   @0xc7190 add r1, pc, r1
 *   @0xc7194 ldr r4, [lr, #0xc]
 *   @0xc7198 blx r4
 *   @0xc719c cmp r10, #1
 *   @0xc71a0 bne 0xc7254 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0x190>
 *   @0xc71a4 mov r0, #92
 *   @0xc71a8 mov r5, #0
 *   @0xc71ac bl 0x27c524 <_Znwj>
 *   @0xc71b0 ldr r3, [pc, #0xc8]
 *   @0xc71b4 mov r2, r5
 *   @0xc71b8 mov r1, r5
 *   @0xc71bc ldr r3, [r6, r3]
 *   @0xc71c0 str r5, [sp]
 *   @0xc71c4 str r5, [sp, #0x4]
 *   @0xc71c8 str r5, [sp, #0x8]
 *   @0xc71cc mov r4, r0
 *   @0xc71d0 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b>
 *   @0xc71d4 ldr r3, [pc, #0xa8]
 *   @0xc71d8 ldr r0, [sp, #0x14]
 *   @0xc71dc ldr r3, [r6, r3]
 *   @0xc71e0 str r9, [r4, #0x44]
 *   @0xc71e4 add r3, r3, #8
 *   @0xc71e8 str r3, [r4]
 *   @0xc71ec bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xc71f0 ldr r2, [pc, #0x90]
 *   @0xc71f4 mov r3, #1
 *   @0xc71f8 strb r8, [r4, #0x4c]
 *   @0xc71fc str r3, [r4, #0x50]
 *   @0xc7200 str r5, [r4, #0x54]
 *   @0xc7204 strb r11, [r4, #0x58]
 *   @0xc7208 ldr r3, [r4, #0x24]
 *   @0xc720c str r0, [r4, #0x48]
 *   @0xc7210 ldr r2, [r6, r2]
 *   @0xc7214 str r2, [r4, #0x18]
 *   @0xc7218 mov r0, r3
 *   @0xc721c add sp, sp, #28
 *   @0xc7220 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc7224 ldr r3, [r6, r3]
 *   @0xc7228 mov r10, r1
 *   @0xc722c ldr r5, [r3]
 *   @0xc7230 ldr lr, [r5]
 *   @0xc7234 mov r2, r10
 *   @0xc7238 ldr r1, [pc, #0x4c]
 *   @0xc723c mov r0, r5
 *   @0xc7240 mov r3, #0
 *   @0xc7244 add r1, pc, r1
 *   @0xc7248 ldr r12, [lr, #0xc]
 *   @0xc724c blx r12
 *   @0xc7250 b 0xc71a4 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0xe0>
 *   @0xc7254 ldr r0, [pc, #0x34]
 *   @0xc7258 add r0, pc, r0
 *   @0xc725c bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xc7260 mvn r3, #0
 *   @0xc7264 b 0xc7218 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0x154>
 *   @0xc7268 eorseq r10, r2, r4, ror r11
 *   @0xc726c .word 0xffffbd88
 *   @0xc7270 .word 0xffffbd8c
 *   @0xc7274 .word 0xffffbac4
 *   @0xc7278 eoreq r10, r6, r4, ror r3
 *   @0xc727c eoreq r10, r6, r4, lsr r3
 *   @0xc7280 .word 0xffffbd90
 *   @0xc7284 .word 0xffffbd64
 *   @0xc7288 .word 0xffffbd94
 *   @0xc728c eoreq r10, r6, r0, lsl #5
 *   @0xc7290 mlaeq r6, r4, r2, r10
 *
 * ══ §29/66 F_DrawSpriteGeneral(RValue&, CInstance*, CInstance*, int, RValue*)  0x122b44  size 464  116 条（0x122b44..0x122d14）
 * @func 0x122b44 0x122d14  size 464  116 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetFloat(RValue const*, int)×10 / YYGetInt32(RValue const*, int)×4 / Error_Show_Action(char const*, bool)×2 / GetSpriteIndices(CInstance*, RValue*, int&, int&) / Sprite_Data(int) / CSprite::DrawGeneral(int, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)
 * 字段偏移 top8: 0x3c×2 / 0x30×2 / 0x34×2 / 0x38×2 / 0x40×2 / 0x44×2 / 0x48×2 / 0x4c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x122b44 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x122b48 sub sp, sp, #92
 *   @0x122b4c mov r0, r1
 *   @0x122b50 add r2, sp, #80
 *   @0x122b54 ldr r4, [sp, #0x80]
 *   @0x122b58 add r3, sp, #84
 *   @0x122b5c mov r1, r4
 *   @0x122b60 bl 0x1226c4 <_Z16GetSpriteIndicesP9CInstanceP6RValueRiS3_>
 *   @0x122b64 cmp r0, #0
 *   @0x122b68 bne 0x122b74 <_Z19F_DrawSpriteGeneralR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x122b6c add sp, sp, #92
 *   @0x122b70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x122b74 ldr r0, [sp, #0x50]
 *   @0x122b78 bl 0x1ef03c <_Z11Sprite_Datai>
 *   @0x122b7c ldr r3, [r0, #0x74]
 *   @0x122b80 mov r5, r0
 *   @0x122b84 cmp r3, #1
 *   @0x122b88 beq 0x122cf8 <_Z19F_DrawSpriteGeneralR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x122b8c cmp r3, #2
 *   @0x122b90 beq 0x122ce4 <_Z19F_DrawSpriteGeneralR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x122b94 ldr r3, [sp, #0x54]
 *   @0x122b98 mov r0, r4
 *   @0x122b9c mov r1, #2
 *   @0x122ba0 str r3, [sp, #0x3c]
 *   @0x122ba4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122ba8 mov r1, #3
 *   @0x122bac mov r2, r0
 *   @0x122bb0 mov r0, r4
 *   @0x122bb4 str r2, [sp, #0x30]
 *   @0x122bb8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122bbc mov r1, #4
 *   @0x122bc0 mov r3, r0
 *   @0x122bc4 mov r0, r4
 *   @0x122bc8 str r3, [sp, #0x34]
 *   @0x122bcc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122bd0 mov r1, #5
 *   @0x122bd4 mov r12, r0
 *   @0x122bd8 mov r0, r4
 *   @0x122bdc str r12, [sp, #0x38]
 *   @0x122be0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122be4 mov r1, #6
 *   @0x122be8 str r0, [sp, #0x40]
 *   @0x122bec mov r0, r4
 *   @0x122bf0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122bf4 mov r1, #7
 *   @0x122bf8 str r0, [sp, #0x44]
 *   @0x122bfc mov r0, r4
 *   @0x122c00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122c04 mov r1, #8
 *   @0x122c08 mov r11, r0
 *   @0x122c0c mov r0, r4
 *   @0x122c10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122c14 mov r1, #9
 *   @0x122c18 mov r10, r0
 *   @0x122c1c mov r0, r4
 *   @0x122c20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122c24 mov r1, #10
 *   @0x122c28 str r0, [sp, #0x48]
 *   @0x122c2c mov r0, r4
 *   @0x122c30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122c34 mov r1, #11
 *   @0x122c38 str r0, [sp, #0x4c]
 *   @0x122c3c mov r0, r4
 *   @0x122c40 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122c44 mov r1, #12
 *   @0x122c48 mov r9, r0
 *   @0x122c4c mov r0, r4
 *   @0x122c50 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122c54 mov r1, #13
 *   @0x122c58 mov r8, r0
 *   @0x122c5c mov r0, r4
 *   @0x122c60 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122c64 mov r1, #14
 *   @0x122c68 mov r7, r0
 *   @0x122c6c mov r0, r4
 *   @0x122c70 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x122c74 mov r1, #15
 *   @0x122c78 mov r6, r0
 *   @0x122c7c mov r0, r4
 *   @0x122c80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x122c84 ldr r1, [sp, #0x40]
 *   @0x122c88 ldr r12, [sp, #0x38]
 *   @0x122c8c str r11, [sp, #0xc]
 *   @0x122c90 str r1, [sp, #0x4]
 *   @0x122c94 ldr r1, [sp, #0x44]
 *   @0x122c98 str r12, [sp]
 *   @0x122c9c str r10, [sp, #0x10]
 *   @0x122ca0 str r1, [sp, #0x8]
 *   @0x122ca4 ldr r1, [sp, #0x48]
 *   @0x122ca8 str r9, [sp, #0x1c]
 *   @0x122cac str r8, [sp, #0x20]
 *   @0x122cb0 str r1, [sp, #0x14]
 *   @0x122cb4 ldr r1, [sp, #0x4c]
 *   @0x122cb8 str r7, [sp, #0x24]
 *   @0x122cbc str r6, [sp, #0x28]
 *   @0x122cc0 str r1, [sp, #0x18]
 *   @0x122cc4 ldr r2, [sp, #0x30]
 *   @0x122cc8 ldr r1, [sp, #0x3c]
 *   @0x122ccc ldr r3, [sp, #0x34]
 *   @0x122cd0 str r0, [sp, #0x2c]
 *   @0x122cd4 mov r0, r5
 *   @0x122cd8 bl 0x1e5fa8 <_ZN7CSprite11DrawGeneralEifffffffffjjjjf>
 *   @0x122cdc add sp, sp, #92
 *   @0x122ce0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x122ce4 ldr r0, [pc, #0x20]
 *   @0x122ce8 mov r1, #0
 *   @0x122cec add r0, pc, r0
 *   @0x122cf0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x122cf4 b 0x122b6c <_Z19F_DrawSpriteGeneralR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x122cf8 ldr r0, [pc, #0x10]
 *   @0x122cfc mov r1, #0
 *   @0x122d00 add r0, pc, r0
 *   @0x122d04 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x122d08 b 0x122b6c <_Z19F_DrawSpriteGeneralR6RValueP9CInstanceS2_iPS_+0x28>
 *   @0x122d0c .word 0x002178b8
 *   @0x122d10 eoreq r7, r1, r12, ror #16
 *
 * ══ §30/66 GraphicsPerf::EndFrame()  0x17c7e8  size 464  116 条（0x17c7e8..0x17c9b8）
 * @func 0x17c7e8 0x17c9b8  size 464  116 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17c7f4→0x49932c, 0x17c810→0x499338, 0x17c814→0x49a018, 0x17c81c→0x4a2028, 0x17c868→0x4a201c, 0x17c884→0x3f26b4, 0x17c8a0→0x3f26b0, 0x17c8b4→0x3f26ac
 * 调用序列: __floatdisf×2 / GraphicsPerf::Pop() / GraphicsPerf::EndFrame()+0xe8 / GraphicsPerf::HandleInput() / GraphicsPerf::BeginDebugDraw() / GraphicsPerf::DisplayAudioSync() / GraphicsPerf::EndDebugDraw() / GraphicsPerf::DisplayXBGameChat()
 * 字段偏移 top8: 0x194×2 / 0x17c×2 / 0xc8×2 / 0x178×1 / 0x130×1 / 0x118×1 / 0x100×1 / 0xf0×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17c7e8 push {r3, r4, r5, r6, r7, lr}
 *   @0x17c7ec vpush {d8}
 *   @0x17c7f0 ldr r6, [pc, #0x194]
 *   @0x17c7f4 ldr r3, [pc, #0x194]
 *   @0x17c7f8 add r6, pc, r6
 *   @0x17c7fc ldr r7, [r6, r3]
 *   @0x17c800 ldr r3, [r7]
 *   @0x17c804 cmp r3, #0
 *   @0x17c808 beq 0x17c980 <_ZN12GraphicsPerf8EndFrameEv+0x198>
 *   @0x17c80c bl 0x17bb10 <_ZN12GraphicsPerf3PopEv>
 *   @0x17c810 ldr r1, [pc, #0x17c]
 *   @0x17c814 ldr r3, [pc, #0x17c]
 *   @0x17c818 mov r0, #0
 *   @0x17c81c ldr r2, [pc, #0x178]
 *   @0x17c820 vldr s16, [pc, #352]
 *   @0x17c824 ldr r1, [r6, r1]
 *   @0x17c828 str r0, [r1]
 *   @0x17c82c ldr r3, [r6, r3]
 *   @0x17c830 ldr r1, [r6, r2]
 *   @0x17c834 ldrd r4, r5, [r3, #8]
 *   @0x17c838 ldrd r2, r3, [r3]
 *   @0x17c83c ldrd r0, r1, [r1]
 *   @0x17c840 subs r4, r4, r2
 *   @0x17c844 sbc r5, r5, r3
 *   @0x17c848 adds r0, r0, r4
 *   @0x17c84c adc r1, r1, r5
 *   @0x17c850 bl 0x319398 <__floatdisf>
 *   @0x17c854 mov r1, r5
 *   @0x17c858 vmov s15, r0
 *   @0x17c85c mov r0, r4
 *   @0x17c860 vdiv.f32 s17, s16, s15
 *   @0x17c864 bl 0x319398 <__floatdisf>
 *   @0x17c868 ldr r3, [pc, #0x130]
 *   @0x17c86c ldr r3, [r6, r3]
 *   @0x17c870 ldr r2, [r3]
 *   @0x17c874 cmp r2, #100
 *   @0x17c878 vmov s15, r0
 *   @0x17c87c vdiv.f32 s16, s16, s15
 *   @0x17c880 ble 0x17c8d0 <_ZN12GraphicsPerf8EndFrameEv+0xe8>
 *   @0x17c884 ldr r1, [pc, #0x118]
 *   @0x17c888 ldr r0, [r6, r1]
 *   @0x17c88c ldr r12, [r0]
 *   @0x17c890 vcvt.s32.f32 s15, s17
 *   @0x17c894 vmov r1, s15
 *   @0x17c898 cmp r1, r12
 *   @0x17c89c strlt r1, [r0]
 *   @0x17c8a0 ldr r0, [pc, #0x100]
 *   @0x17c8a4 ldr r0, [r6, r0]
 *   @0x17c8a8 ldr r12, [r0]
 *   @0x17c8ac cmp r1, r12
 *   @0x17c8b0 strgt r1, [r0]
 *   @0x17c8b4 ldr r0, [pc, #0xf0]
 *   @0x17c8b8 ldr r0, [r6, r0]
 *   @0x17c8bc ldr r12, [r0]
 *   @0x17c8c0 add r1, r1, r12
 *   @0x17c8c4 add r1, r1, r1, lsr #31
 *   @0x17c8c8 asr r1, r1, #1
 *   @0x17c8cc str r1, [r0]
 *   @0x17c8d0 add r2, r2, #1
 *   @0x17c8d4 str r2, [r3]
 *   @0x17c8d8 bl 0x17b624 <_ZN12GraphicsPerf11HandleInputEv>
 *   @0x17c8dc bl 0x17b114 <_ZN12GraphicsPerf14BeginDebugDrawEv>
 *   @0x17c8e0 ldr r3, [pc, #0xc8]
 *   @0x17c8e4 ldr r2, [pc, #0xc8]
 *   @0x17c8e8 ldr r2, [r6, r2]
 *   @0x17c8ec vstr s16, [r2]
 *   @0x17c8f0 ldr r4, [r6, r3]
 *   @0x17c8f4 ldr r3, [r4]
 *   @0x17c8f8 tst r3, #2
 *   @0x17c8fc bne 0x17c970 <_ZN12GraphicsPerf8EndFrameEv+0x188>
 *   @0x17c900 tst r3, #1
 *   @0x17c904 bne 0x17c964 <_ZN12GraphicsPerf8EndFrameEv+0x17c>
 *   @0x17c908 tst r3, #4
 *   @0x17c90c bne 0x17c958 <_ZN12GraphicsPerf8EndFrameEv+0x170>
 *   @0x17c910 tst r3, #16
 *   @0x17c914 bne 0x17c94c <_ZN12GraphicsPerf8EndFrameEv+0x164>
 *   @0x17c918 tst r3, #64
 *   @0x17c91c bne 0x17c940 <_ZN12GraphicsPerf8EndFrameEv+0x158>
 *   @0x17c920 tst r3, #32
 *   @0x17c924 beq 0x17c92c <_ZN12GraphicsPerf8EndFrameEv+0x144>
 *   @0x17c928 bl 0x17b8ec <_ZN12GraphicsPerf16DisplayAudioSyncEv>
 *   @0x17c92c bl 0x17b3e4 <_ZN12GraphicsPerf12EndDebugDrawEv>
 *   @0x17c930 vpop {d8}
 *   @0x17c934 mov r3, #0
 *   @0x17c938 str r3, [r7]
 *   @0x17c93c pop {r3, r4, r5, r6, r7, pc}
 *   @0x17c940 bl 0x17b8e8 <_ZN12GraphicsPerf17DisplayXBGameChatEv>
 *   @0x17c944 ldr r3, [r4]
 *   @0x17c948 b 0x17c920 <_ZN12GraphicsPerf8EndFrameEv+0x138>
 *   @0x17c94c bl 0x17b8e4 <_ZN12GraphicsPerf12DisplayAudioEv>
 *   @0x17c950 ldr r3, [r4]
 *   @0x17c954 b 0x17c918 <_ZN12GraphicsPerf8EndFrameEv+0x130>
 *   @0x17c958 bl 0x17b8e0 <_ZN12GraphicsPerf14DisplayConsoleEv>
 *   @0x17c95c ldr r3, [r4]
 *   @0x17c960 b 0x17c910 <_ZN12GraphicsPerf8EndFrameEv+0x128>
 *   @0x17c964 bl 0x17c5d8 <_ZN12GraphicsPerf18DisplayVersionInfoEv>
 *   @0x17c968 ldr r3, [r4]
 *   @0x17c96c b 0x17c908 <_ZN12GraphicsPerf8EndFrameEv+0x120>
 *   @0x17c970 vmov r0, s17
 *   @0x17c974 bl 0x17c428 <_ZN12GraphicsPerf10DisplayFPSEf>
 *   @0x17c978 ldr r3, [r4]
 *   @0x17c97c b 0x17c900 <_ZN12GraphicsPerf8EndFrameEv+0x118>
 *   @0x17c980 bl 0x17b9a0 <_ZN12GraphicsPerf10BeginFrameEv>
 *   @0x17c984 b 0x17c80c <_ZN12GraphicsPerf8EndFrameEv+0x24>
 *   @0x17c988 ldmdbmi r4!, {r10, sp} ^
 *   @0x17c98c eoreq r5, r7, r8, asr r4
 *   @0x17c990 .word 0xffffe6e0
 *   @0x17c994 .word 0xffffe6dc
 *   @0x17c998 .word 0xffffe738
 *   @0x17c99c .word 0xffffe518
 *   @0x17c9a0 .word 0xffffc1f4
 *   @0x17c9a4 .word 0xffffe6ec
 *   @0x17c9a8 .word 0xffffe6f0
 *   @0x17c9ac .word 0xffffe6e8
 *   @0x17c9b0 .word 0xffffc7dc
 *   @0x17c9b4 .word 0xffffe7a8
 *
 * ══ §31/66 HalfTextureRGB(int, int, unsigned char*, int, int, unsigned char*)  0x18941c  size 464  116 条（0x18941c..0x1895ec）
 * @func 0x18941c 0x1895ec  size 464  116 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×2 / HalfTextureRGB(int, int, unsigned char*, int, int, unsigned char*)+0x1a0 / HalfTextureRGB(int, int, unsigned char*, int, int, unsigned char*)+0x178
 * 字段偏移 top8: 0x18×6 / 0x30×5 / 0x14×5 / 0x20×4 / 0x24×3 / 0x64×2 / 0xc×2 / 0x34×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18941c ldr r12, [pc, #0x1c0]
 *   @0x189420 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x189424 ldr r12, [pc, r12]
 *   @0x189428 sub sp, sp, #60
 *   @0x18942c mov r4, r2
 *   @0x189430 mov r5, r3
 *   @0x189434 mov r3, r1
 *   @0x189438 str r0, [sp, #0x18]
 *   @0x18943c add r8, r5, r5, lsl #1
 *   @0x189440 ldr r0, [r12]
 *   @0x189444 ldr r6, [sp, #0x60]
 *   @0x189448 ldr r2, [sp, #0x18]
 *   @0x18944c ldr r12, [r0]
 *   @0x189450 ldr r9, [sp, #0x64]
 *   @0x189454 str r1, [sp, #0x30]
 *   @0x189458 add r7, r2, r2, lsl #1
 *   @0x18945c ldr r1, [pc, #0x184]
 *   @0x189460 stm sp, {r4, r5, r6}
 *   @0x189464 add r1, pc, r1
 *   @0x189468 str r9, [sp, #0xc]
 *   @0x18946c str r7, [sp, #0x34]
 *   @0x189470 ldr r12, [r12, #0xc]
 *   @0x189474 blx r12
 *   @0x189478 lsl r0, r6, #16
 *   @0x18947c ldr r1, [sp, #0x30]
 *   @0x189480 bl 0x318d10 <__divsi3>
 *   @0x189484 ldr r12, [sp, #0x30]
 *   @0x189488 cmp r12, #0
 *   @0x18948c str r0, [sp, #0x28]
 *   @0x189490 ble 0x1895bc <_Z14HalfTextureRGBiiPhiiS_+0x1a0>
 *   @0x189494 ldr r1, [sp, #0x18]
 *   @0x189498 lsl r0, r5, #16
 *   @0x18949c bl 0x318d10 <__divsi3>
 *   @0x1894a0 ldr r1, [sp, #0x30]
 *   @0x1894a4 ldr r7, [sp, #0x18]
 *   @0x1894a8 mov r2, #0
 *   @0x1894ac mov r11, r2
 *   @0x1894b0 str r4, [sp, #0x14]
 *   @0x1894b4 str r2, [sp, #0x24]
 *   @0x1894b8 mul r1, r1, r7
 *   @0x1894bc str r2, [sp, #0x20]
 *   @0x1894c0 str r1, [sp, #0x2c]
 *   @0x1894c4 str r0, [sp, #0x1c]
 *   @0x1894c8 ldr r12, [sp, #0x20]
 *   @0x1894cc ldr r9, [sp, #0x18]
 *   @0x1894d0 ldr r7, [sp, #0x64]
 *   @0x1894d4 asr r3, r12, #16
 *   @0x1894d8 cmp r9, #0
 *   @0x1894dc mla r3, r8, r3, r7
 *   @0x1894e0 ble 0x189594 <_Z14HalfTextureRGBiiPhiiS_+0x178>
 *   @0x1894e4 ldr r12, [sp, #0x14]
 *   @0x1894e8 mov r0, #0
 *   @0x1894ec mov r6, r0
 *   @0x1894f0 asr r2, r6, #16
 *   @0x1894f4 ldr r9, [sp, #0x1c]
 *   @0x1894f8 add r11, r11, #1
 *   @0x1894fc add r12, r12, #3
 *   @0x189500 add r2, r2, r2, lsl #1
 *   @0x189504 add r6, r6, r9
 *   @0x189508 add r1, r2, #3
 *   @0x18950c add r5, r2, r8
 *   @0x189510 ldrb r10, [r3, r2]
 *   @0x189514 add r4, r1, r8
 *   @0x189518 ldrb r7, [r3, r1]
 *   @0x18951c ldrb r9, [r3, r5]
 *   @0x189520 add r10, r10, r7
 *   @0x189524 ldrb r7, [r3, r4]
 *   @0x189528 add r9, r10, r9
 *   @0x18952c add r9, r9, r7
 *   @0x189530 ldr r7, [sp, #0x14]
 *   @0x189534 asr r9, r9, #2
 *   @0x189538 strb r9, [r7, r0]
 *   @0x18953c add r0, r0, #3
 *   @0x189540 ldr r9, [sp, #0x18]
 *   @0x189544 ldrb r7, [r3, r1]
 *   @0x189548 ldrb r10, [r3, r2]
 *   @0x18954c cmp r9, r0
 *   @0x189550 ldrb r9, [r3, r5]
 *   @0x189554 add r10, r10, r7
 *   @0x189558 ldrb r7, [r3, r4]
 *   @0x18955c add r9, r10, r9
 *   @0x189560 add r9, r9, r7
 *   @0x189564 asr r9, r9, #2
 *   @0x189568 strb r9, [r12, #-0x2]
 *   @0x18956c ldrb r7, [r3, r2]
 *   @0x189570 ldrb r1, [r3, r1]
 *   @0x189574 ldrb r5, [r3, r5]
 *   @0x189578 ldrb r4, [r3, r4]
 *   @0x18957c add r2, r7, r1
 *   @0x189580 add r2, r2, r5
 *   @0x189584 add r2, r2, r4
 *   @0x189588 asr r2, r2, #2
 *   @0x18958c strb r2, [r12, #-0x1]
 *   @0x189590 bgt 0x1894f0 <_Z14HalfTextureRGBiiPhiiS_+0xd4>
 *   @0x189594 ldr r12, [sp, #0x2c]
 *   @0x189598 ldr r1, [sp, #0x20]
 *   @0x18959c ldr r3, [sp, #0x24]
 *   @0x1895a0 cmp r12, r11
 *   @0x1895a4 ldr r2, [sp, #0x28]
 *   @0x1895a8 add r3, r3, #1
 *   @0x1895ac str r3, [sp, #0x24]
 *   @0x1895b0 add r1, r1, r2
 *   @0x1895b4 str r1, [sp, #0x20]
 *   @0x1895b8 bge 0x1895c4 <_Z14HalfTextureRGBiiPhiiS_+0x1a8>
 *   @0x1895bc add sp, sp, #60
 *   @0x1895c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1895c4 ldr r7, [sp, #0x30]
 *   @0x1895c8 ldr r9, [sp, #0x14]
 *   @0x1895cc ldr r12, [sp, #0x34]
 *   @0x1895d0 cmp r7, r3
 *   @0x1895d4 add r9, r9, r12
 *   @0x1895d8 str r9, [sp, #0x14]
 *   @0x1895dc bgt 0x1894c8 <_Z14HalfTextureRGBiiPhiiS_+0xac>
 *   @0x1895e0 b 0x1895bc <_Z14HalfTextureRGBiiPhiiS_+0x1a0>
 *   @0x1895e4 .word 0x002642f0
 *   @0x1895e8 andseq r2, r12, r12, lsr r12
 *
 * ══ §32/66 HTTP_REQ_CONTEXT::SetResponseHeaders(char*)  0x18e2d4  size 464  116 条（0x18e2d4..0x18e4a4）
 * @func 0x18e2d4 0x18e4a4  size 464  116 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6940×2 / YYCreateString(RValue*, char const*)×2 / FREE_RValue__Pre(RValue*)×2 / DS_AutoMutex::DS_AutoMutex() / MemoryManager::Free(void const*) / 0xb6604 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb6568
 * 字段偏移 top8: 0x44×3 / 0x34×3 / 0x2c×2 / 0x4×2 / 0x14×2 / 0x10×2 / 0x18×2 / 0x30×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18e2d4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18e2d8 subs r5, r1, #0
 *   @0x18e2dc sub sp, sp, #76
 *   @0x18e2e0 mov r6, r0
 *   @0x18e2e4 beq 0x18e48c <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0x1b8>
 *   @0x18e2e8 add r3, sp, #36
 *   @0x18e2ec str r3, [sp, #0x1c]
 *   @0x18e2f0 ldr r4, [pc, #0x19c]
 *   @0x18e2f4 mov r0, r3
 *   @0x18e2f8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x18e2fc ldr r3, [pc, #0x194]
 *   @0x18e300 ldr r2, [r6, #0x2c]
 *   @0x18e304 add r4, pc, r4
 *   @0x18e308 ldr r3, [pc, r3]
 *   @0x18e30c mov r0, r5
 *   @0x18e310 mov r1, r4
 *   @0x18e314 ldr r3, [r3, #0x4]
 *   @0x18e318 ldr r3, [r3, r2, lsl #2]
 *   @0x18e31c str r3, [sp, #0x14]
 *   @0x18e320 bl 0xb6940 <strtok@plt>
 *   @0x18e324 subs r10, r0, #0
 *   @0x18e328 beq 0x18e484 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0x1b0>
 *   @0x18e32c ldr r11, [pc, #0x168]
 *   @0x18e330 add r8, sp, #40
 *   @0x18e334 ldr r3, [pc, #0x164]
 *   @0x18e338 add r6, sp, #56
 *   @0x18e33c str r4, [sp, #0x10]
 *   @0x18e340 add r11, pc, r11
 *   @0x18e344 add r3, pc, r3
 *   @0x18e348 mov r4, #0
 *   @0x18e34c str r3, [sp, #0x18]
 *   @0x18e350 mov r9, #1
 *   @0x18e354 add r3, sp, #44
 *   @0x18e358 str r3, [sp, #0x8]
 *   @0x18e35c add r3, sp, #48
 *   @0x18e360 str r3, [sp, #0xc]
 *   @0x18e364 add r3, sp, #60
 *   @0x18e368 str r3, [sp]
 *   @0x18e36c add r3, sp, #64
 *   @0x18e370 str r3, [sp, #0x4]
 *   @0x18e374 b 0x18e3cc <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0xf8>
 *   @0x18e378 ldr r3, [sp, #0x44]
 *   @0x18e37c mov r2, #5
 *   @0x18e380 str r4, [sp, #0x30]
 *   @0x18e384 sub r3, r3, #1
 *   @0x18e388 str r4, [sp, #0x28]
 *   @0x18e38c bic r3, r3, #-16777216
 *   @0x18e390 str r2, [sp, #0x34]
 *   @0x18e394 bic r3, r3, #3
 *   @0x18e398 cmp r3, #0
 *   @0x18e39c beq 0x18e478 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0x1a4>
 *   @0x18e3a0 mov r0, r7
 *   @0x18e3a4 mov r3, #5
 *   @0x18e3a8 str r4, [sp, #0x40]
 *   @0x18e3ac str r4, [sp, #0x38]
 *   @0x18e3b0 str r3, [sp, #0x44]
 *   @0x18e3b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x18e3b8 mov r0, #0
 *   @0x18e3bc ldr r1, [sp, #0x10]
 *   @0x18e3c0 bl 0xb6940 <strtok@plt>
 *   @0x18e3c4 subs r10, r0, #0
 *   @0x18e3c8 beq 0x18e484 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0x1b0>
 *   @0x18e3cc mov r1, r11
 *   @0x18e3d0 mov r0, r10
 *   @0x18e3d4 str r4, [r8]
 *   @0x18e3d8 str r4, [sp, #0x2c]
 *   @0x18e3dc str r4, [sp, #0x30]
 *   @0x18e3e0 str r4, [r6]
 *   @0x18e3e4 str r4, [sp, #0x3c]
 *   @0x18e3e8 str r4, [sp, #0x40]
 *   @0x18e3ec str r9, [sp, #0x34]
 *   @0x18e3f0 str r9, [sp, #0x44]
 *   @0x18e3f4 bl 0xb6604 <strstr@plt>
 *   @0x18e3f8 subs r1, r0, #0
 *   @0x18e3fc mov r0, r6
 *   @0x18e400 rsb r5, r10, r1
 *   @0x18e404 add r1, r1, #2
 *   @0x18e408 beq 0x18e3b8 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0xe4>
 *   @0x18e40c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18e410 mov r3, #1
 *   @0x18e414 ldr r1, [sp, #0x18]
 *   @0x18e418 mov r2, #125
 *   @0x18e41c add r0, r5, #1
 *   @0x18e420 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18e424 mov r2, r5
 *   @0x18e428 mov r1, r10
 *   @0x18e42c mov r7, r0
 *   @0x18e430 bl 0xb6568 <strncpy@plt>
 *   @0x18e434 mov r1, r7
 *   @0x18e438 mov r0, r8
 *   @0x18e43c strb r4, [r7, r5]
 *   @0x18e440 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x18e444 ldr r0, [sp, #0x14]
 *   @0x18e448 mov r1, r8
 *   @0x18e44c mov r2, r6
 *   @0x18e450 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x18e454 ldr r3, [sp, #0x34]
 *   @0x18e458 sub r3, r3, #1
 *   @0x18e45c bic r3, r3, #-16777216
 *   @0x18e460 bic r3, r3, #3
 *   @0x18e464 cmp r3, #0
 *   @0x18e468 bne 0x18e378 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0xa4>
 *   @0x18e46c mov r0, r8
 *   @0x18e470 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x18e474 b 0x18e378 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0xa4>
 *   @0x18e478 mov r0, r6
 *   @0x18e47c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x18e480 b 0x18e3a0 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc+0xcc>
 *   @0x18e484 add r0, sp, #36
 *   @0x18e488 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x18e48c add sp, sp, #76
 *   @0x18e490 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x18e494 andseq r2, r11, r4, lsr r0
 *   @0x18e498 eoreq pc, r5, r4, lsr r6
 *   @0x18e49c ldrsheq r1, [r11], -r4
 *   @0x18e4a0 mulseq r11, r4, pc
 *
 * ══ §33/66 AddShader(char*, int, char*, char*, char*, char*, char*, char*, char*, char*, char*, int, char*, int, char*, int, char*, int, char*, char*, int, unsigned int*)  0x1e1350  size 464  116 条（0x1e1350..0x1e1520）
 * @func 0x1e1350 0x1e1520  size 464  116 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool) / operator new(unsigned int) / operator new[](unsigned int) / AddShader(char*, int, char*, char*, char*, char*, char*, char*, char*, char*, char*, int, char*, int, char*, int, char*, int, char*, char*, int, unsigned int*)+0x1a0
 * 字段偏移 top8: 0x8×4 / 0x60×4 / 0xc×3 / 0x5c×3 / 0x38×2 / 0x3c×2 / 0x40×2 / 0x44×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e1350 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e1354 sub sp, sp, #20
 *   @0x1e1358 ldr lr, [pc, #0x1b0]
 *   @0x1e135c mov r12, r2
 *   @0x1e1360 ldr r5, [pc, #0x1ac]
 *   @0x1e1364 mov r7, #0
 *   @0x1e1368 ldr lr, [pc, lr]
 *   @0x1e136c str r1, [sp, #0xc]
 *   @0x1e1370 ldr r5, [pc, r5]
 *   @0x1e1374 ldr r2, [pc, #0x19c]
 *   @0x1e1378 ldr r9, [lr]
 *   @0x1e137c mov r11, r3
 *   @0x1e1380 add r2, pc, r2
 *   @0x1e1384 mov r3, #74
 *   @0x1e1388 add r1, r9, #1
 *   @0x1e138c mov r10, r0
 *   @0x1e1390 str r1, [lr]
 *   @0x1e1394 ldr r0, [r5]
 *   @0x1e1398 lsl r1, r1, #2
 *   @0x1e139c str r7, [sp]
 *   @0x1e13a0 sub r6, r1, #4
 *   @0x1e13a4 ldr r8, [sp, #0x78]
 *   @0x1e13a8 str r12, [sp, #0x8]
 *   @0x1e13ac ldr r4, [sp, #0x7c]
 *   @0x1e13b0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1e13b4 str r0, [r5]
 *   @0x1e13b8 mov r0, #132
 *   @0x1e13bc bl 0x27c524 <_Znwj>
 *   @0x1e13c0 ldr r12, [sp, #0x8]
 *   @0x1e13c4 ldr r2, [r5]
 *   @0x1e13c8 mvn r3, #0
 *   @0x1e13cc mov r1, #1
 *   @0x1e13d0 cmp r8, #532676608
 *   @0x1e13d4 str r12, [r0, #0xc]
 *   @0x1e13d8 ldr r12, [sp, #0x38]
 *   @0x1e13dc str r11, [r0, #0x10]
 *   @0x1e13e0 str r12, [r0, #0x14]
 *   @0x1e13e4 ldr r12, [sp, #0x3c]
 *   @0x1e13e8 str r12, [r0, #0x18]
 *   @0x1e13ec ldr r12, [sp, #0x40]
 *   @0x1e13f0 str r12, [r0, #0x1c]
 *   @0x1e13f4 ldr r12, [sp, #0x44]
 *   @0x1e13f8 str r12, [r0, #0x20]
 *   @0x1e13fc ldr r12, [sp, #0x48]
 *   @0x1e1400 str r12, [r0, #0x24]
 *   @0x1e1404 ldr r12, [sp, #0x4c]
 *   @0x1e1408 str r12, [r0, #0x28]
 *   @0x1e140c ldr r12, [sp, #0x50]
 *   @0x1e1410 str r12, [r0, #0x2c]
 *   @0x1e1414 ldr r12, [sp, #0x54]
 *   @0x1e1418 str r12, [r0, #0x44]
 *   @0x1e141c ldr r12, [sp, #0x58]
 *   @0x1e1420 str r12, [r0, #0x30]
 *   @0x1e1424 ldr r12, [sp, #0x5c]
 *   @0x1e1428 str r12, [r0, #0x48]
 *   @0x1e142c ldr r12, [sp, #0x60]
 *   @0x1e1430 str r12, [r0, #0x34]
 *   @0x1e1434 ldr r12, [sp, #0x64]
 *   @0x1e1438 str r12, [r0, #0x4c]
 *   @0x1e143c ldr r12, [sp, #0x68]
 *   @0x1e1440 str r12, [r0, #0x38]
 *   @0x1e1444 ldr r12, [sp, #0x6c]
 *   @0x1e1448 str r12, [r0, #0x50]
 *   @0x1e144c ldr r12, [sp, #0x70]
 *   @0x1e1450 str r12, [r0, #0x3c]
 *   @0x1e1454 ldr r12, [sp, #0x74]
 *   @0x1e1458 str r3, [r0, #0x64]
 *   @0x1e145c str r7, [r0, #0x4]
 *   @0x1e1460 str r12, [r0, #0x40]
 *   @0x1e1464 str r7, [r0, #0x54]
 *   @0x1e1468 str r7, [r0, #0x60]
 *   @0x1e146c str r7, [r0, #0x5c]
 *   @0x1e1470 str r3, [r0]
 *   @0x1e1474 str r1, [r0, #0x8]
 *   @0x1e1478 str r0, [r2, r6]
 *   @0x1e147c movhi r0, r3
 *   @0x1e1480 ldr r2, [r5]
 *   @0x1e1484 lslls r0, r8, #2
 *   @0x1e1488 ldr r7, [r2, r6]
 *   @0x1e148c str r8, [r7, #0x5c]
 *   @0x1e1490 bl 0x27d14c <_Znaj>
 *   @0x1e1494 ldr r3, [r5]
 *   @0x1e1498 cmp r8, #0
 *   @0x1e149c add r2, r3, r6
 *   @0x1e14a0 str r0, [r7, #0x60]
 *   @0x1e14a4 ldr r3, [r3, r6]
 *   @0x1e14a8 ldr r12, [r3, #0x60]
 *   @0x1e14ac ble 0x1e14f0 <_Z9AddShaderPciS_S_S_S_S_S_S_S_S_iS_iS_iS_iS_S_iPj+0x1a0>
 *   @0x1e14b0 lsl r8, r8, #2
 *   @0x1e14b4 mov r3, #0
 *   @0x1e14b8 ldr r2, [r4, r3]
 *   @0x1e14bc ldr r0, [pc, #0x58]
 *   @0x1e14c0 cmp r2, #0
 *   @0x1e14c4 ldrne r0, [pc, r0]
 *   @0x1e14c8 mov r1, r2
 *   @0x1e14cc ldrne r1, [r0]
 *   @0x1e14d0 addne r1, r1, r2
 *   @0x1e14d4 str r1, [r12, r3]
 *   @0x1e14d8 add r3, r3, #4
 *   @0x1e14dc cmp r3, r8
 *   @0x1e14e0 bne 0x1e14b8 <_Z9AddShaderPciS_S_S_S_S_S_S_S_S_iS_iS_iS_iS_S_iPj+0x168>
 *   @0x1e14e4 ldr r3, [r5]
 *   @0x1e14e8 add r2, r3, r6
 *   @0x1e14ec ldr r3, [r3, r6]
 *   @0x1e14f0 str r10, [r3, #0x4]
 *   @0x1e14f4 ldr r12, [sp, #0xc]
 *   @0x1e14f8 ldr r2, [r2]
 *   @0x1e14fc str r9, [r3]
 *   @0x1e1500 mov r0, r2
 *   @0x1e1504 str r12, [r2, #0x8]
 *   @0x1e1508 add sp, sp, #20
 *   @0x1e150c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e1510 .word 0x0020f9dc
 *   @0x1e1514 .word 0x0020f9d8
 *   @0x1e1518 ldrheq pc, [r4], -r0
 *   @0x1e151c eoreq r12, r0, r0, lsl #9
 *
 * ══ §34/66 CSprite::LoadStrip(IBitmapLoader*, bool, bool, int, bool)  0x1e6e04  size 464  116 条（0x1e6e04..0x1e6fd4）
 * @func 0x1e6e04 0x1e6fd4  size 464  116 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×3 / CBitmap32::CBitmap32(IBitmap*, bool, bool, bool)×2 / CSprite::Clear() / __divsi3 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / CSprite::LoadStrip(IBitmapLoader*, bool, bool, int, bool)+0x15c / CBitmap32::CBitmap32(CBitmap32*, int, int, int, int)
 * 字段偏移 top8: 0x18×6 / 0x20×4 / 0x4×4 / 0x10×2 / 0x32×2 / 0x33×2 / 0x1c×2 / 0x48×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e6e04 ldr r12, [r1]
 *   @0x1e6e08 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1e6e0c sub sp, sp, #12
 *   @0x1e6e10 mov r4, r0
 *   @0x1e6e14 mov r9, r3
 *   @0x1e6e18 mov r0, r1
 *   @0x1e6e1c ldr r3, [r12, #0x10]
 *   @0x1e6e20 mov r1, #0
 *   @0x1e6e24 mov r8, r2
 *   @0x1e6e28 ldr r6, [sp, #0x28]
 *   @0x1e6e2c ldrb r7, [sp, #0x2c]
 *   @0x1e6e30 blx r3
 *   @0x1e6e34 mov r5, r0
 *   @0x1e6e38 mov r0, r4
 *   @0x1e6e3c bl 0x1e6b4c <_ZN7CSprite5ClearEv>
 *   @0x1e6e40 cmp r5, #0
 *   @0x1e6e44 strb r8, [r4, #0x32]
 *   @0x1e6e48 strb r9, [r4, #0x33]
 *   @0x1e6e4c str r6, [r4, #0x18]
 *   @0x1e6e50 beq 0x1e6fa4 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0x1a0>
 *   @0x1e6e54 cmp r6, #0
 *   @0x1e6e58 mov r0, r5
 *   @0x1e6e5c movle r3, #1
 *   @0x1e6e60 strle r3, [r4, #0x18]
 *   @0x1e6e64 ldr r3, [r5]
 *   @0x1e6e68 ldr r3, [r3, #0x10]
 *   @0x1e6e6c blx r3
 *   @0x1e6e70 ldr r1, [r4, #0x18]
 *   @0x1e6e74 bl 0x318d10 <__divsi3>
 *   @0x1e6e78 ldr r3, [r5]
 *   @0x1e6e7c ldr r3, [r3, #0x18]
 *   @0x1e6e80 str r0, [r4, #0x1c]
 *   @0x1e6e84 mov r0, r5
 *   @0x1e6e88 blx r3
 *   @0x1e6e8c cmp r7, #0
 *   @0x1e6e90 str r0, [r4, #0x20]
 *   @0x1e6e94 mov r0, #24
 *   @0x1e6e98 bne 0x1e6f80 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0x17c>
 *   @0x1e6e9c bl 0x27c524 <_Znwj>
 *   @0x1e6ea0 ldrb r2, [r4, #0x32]
 *   @0x1e6ea4 ldrb r3, [r4, #0x33]
 *   @0x1e6ea8 mov r1, r5
 *   @0x1e6eac str r7, [sp]
 *   @0x1e6eb0 mov r8, r0
 *   @0x1e6eb4 bl 0x167188 <_ZN9CBitmap32C2EP7IBitmapbbb>
 *   @0x1e6eb8 ldr r3, [r5]
 *   @0x1e6ebc mov r0, r5
 *   @0x1e6ec0 ldr r3, [r3, #0x4]
 *   @0x1e6ec4 blx r3
 *   @0x1e6ec8 ldr r1, [r4, #0x18]
 *   @0x1e6ecc ldr r2, [pc, #0xf4]
 *   @0x1e6ed0 movw r3, #0x512
 *   @0x1e6ed4 add r0, r4, #72
 *   @0x1e6ed8 add r2, pc, r2
 *   @0x1e6edc lsl r1, r1, #2
 *   @0x1e6ee0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e6ee4 ldr r3, [r4, #0x18]
 *   @0x1e6ee8 cmp r3, #0
 *   @0x1e6eec str r3, [r4, #0x44]
 *   @0x1e6ef0 movgt r5, #0
 *   @0x1e6ef4 ble 0x1e6f60 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0x15c>
 *   @0x1e6ef8 ldr r3, [r4, #0x48]
 *   @0x1e6efc lsl r6, r5, #2
 *   @0x1e6f00 ldr r3, [r3, r5, lsl #2]
 *   @0x1e6f04 cmp r3, #0
 *   @0x1e6f08 mov r0, r3
 *   @0x1e6f0c beq 0x1e6f1c <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0x118>
 *   @0x1e6f10 ldr r3, [r3]
 *   @0x1e6f14 ldr r3, [r3, #0x4]
 *   @0x1e6f18 blx r3
 *   @0x1e6f1c mov r0, #24
 *   @0x1e6f20 bl 0x27c524 <_Znwj>
 *   @0x1e6f24 ldr r2, [r4, #0x1c]
 *   @0x1e6f28 ldr r12, [r4, #0x20]
 *   @0x1e6f2c mov r3, #0
 *   @0x1e6f30 mov r1, r8
 *   @0x1e6f34 str r2, [sp]
 *   @0x1e6f38 str r12, [sp, #0x4]
 *   @0x1e6f3c mul r2, r5, r2
 *   @0x1e6f40 add r5, r5, #1
 *   @0x1e6f44 mov r7, r0
 *   @0x1e6f48 bl 0x166020 <_ZN9CBitmap32C2EPS_iiii>
 *   @0x1e6f4c ldr r2, [r4, #0x18]
 *   @0x1e6f50 ldr r3, [r4, #0x48]
 *   @0x1e6f54 cmp r2, r5
 *   @0x1e6f58 str r7, [r3, r6]
 *   @0x1e6f5c bgt 0x1e6ef8 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0xf4>
 *   @0x1e6f60 cmp r8, #0
 *   @0x1e6f64 beq 0x1e6f78 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0x174>
 *   @0x1e6f68 ldr r3, [r8]
 *   @0x1e6f6c mov r0, r8
 *   @0x1e6f70 ldr r3, [r3, #0x4]
 *   @0x1e6f74 blx r3
 *   @0x1e6f78 add sp, sp, #12
 *   @0x1e6f7c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1e6f80 bl 0x27c524 <_Znwj>
 *   @0x1e6f84 mov r2, #0
 *   @0x1e6f88 mov r1, #1
 *   @0x1e6f8c mov r3, r2
 *   @0x1e6f90 str r1, [sp]
 *   @0x1e6f94 mov r1, r5
 *   @0x1e6f98 mov r8, r0
 *   @0x1e6f9c bl 0x167188 <_ZN9CBitmap32C2EP7IBitmapbbb>
 *   @0x1e6fa0 b 0x1e6eb8 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0xb4>
 *   @0x1e6fa4 ldr r3, [pc, #0x20]
 *   @0x1e6fa8 ldr r1, [pc, #0x20]
 *   @0x1e6fac ldr r3, [pc, r3]
 *   @0x1e6fb0 add r1, pc, r1
 *   @0x1e6fb4 ldr r0, [r3]
 *   @0x1e6fb8 ldr r3, [r0]
 *   @0x1e6fbc ldr r3, [r3, #0xc]
 *   @0x1e6fc0 blx r3
 *   @0x1e6fc4 b 0x1e6f78 <_ZN7CSprite9LoadStripEP13IBitmapLoaderbbib+0x174>
 *   @0x1e6fc8 andseq r11, r6, r12, asr #10
 *   @0x1e6fcc eoreq r6, r0, r8, ror #14
 *   @0x1e6fd0 andseq r11, r6, r8, lsl #12
 *
 * ══ §35/66 CDS_Grid::Get_Disk_Mean(RValue&, double, double, double)  0x2045bc  size 464  116 条（0x2045bc..0x20478c）
 * @func 0x2045bc 0x20478c  size 464  116 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6598×2 / 0xb670c×2 / CDS_Grid::Get_Disk_Mean(RValue&, double, double, double)+0x17c
 * 字段偏移 top8: 0x4×4 / 0xc×2 / 0x8×1
 * VFP 指令 61 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2045bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2045c0 vpush {d8, d9, d10}
 *   @0x2045c4 vmov d10, r2, r3
 *   @0x2045c8 sub sp, sp, #12
 *   @0x2045cc vldr d9, [sp, #80]
 *   @0x2045d0 vsub.f64 d5, d10, d9
 *   @0x2045d4 mov r5, r1
 *   @0x2045d8 mov r9, #0
 *   @0x2045dc mov r8, r0
 *   @0x2045e0 str r9, [r1, #0xc]
 *   @0x2045e4 str r9, [r1]
 *   @0x2045e8 str r9, [r5, #0x4]
 *   @0x2045ec vmov r0, r1, d5
 *   @0x2045f0 bl 0xb6598 <floor@plt>
 *   @0x2045f4 ldr r6, [r8, #0x4]
 *   @0x2045f8 vadd.f64 d6, d10, d9
 *   @0x2045fc vldr d8, [sp, #72]
 *   @0x204600 sub r4, r6, #1
 *   @0x204604 vmov d7, r0, r1
 *   @0x204608 vcmpe.f64 d7, #0
 *   @0x20460c vmov r0, r1, d6
 *   @0x204610 vmrs APSR_nzcv, fpscr
 *   @0x204614 vcvtpl.s32.f64 s11, d7
 *   @0x204618 vmovpl r9, s11
 *   @0x20461c bl 0xb670c <ceil@plt>
 *   @0x204620 vmov s10, r4
 *   @0x204624 vcvt.f64.s32 d6, s10
 *   @0x204628 vmov d7, r0, r1
 *   @0x20462c vcmpe.f64 d6, d7
 *   @0x204630 vsub.f64 d6, d8, d9
 *   @0x204634 vmrs APSR_nzcv, fpscr
 *   @0x204638 vcvtpl.s32.f64 s11, d7
 *   @0x20463c vmov r0, r1, d6
 *   @0x204640 vmovpl r4, s11
 *   @0x204644 bl 0xb6598 <floor@plt>
 *   @0x204648 ldr r3, [r8, #0x8]
 *   @0x20464c sub r7, r3, #1
 *   @0x204650 vmov d7, r0, r1
 *   @0x204654 vcmpe.f64 d7, #0
 *   @0x204658 vmrs APSR_nzcv, fpscr
 *   @0x20465c vcvtpl.s32.f64 s13, d7
 *   @0x204660 movmi r10, #0
 *   @0x204664 vadd.f64 d7, d8, d9
 *   @0x204668 vmovpl r10, s13
 *   @0x20466c vmov r0, r1, d7
 *   @0x204670 bl 0xb670c <ceil@plt>
 *   @0x204674 vmov s10, r7
 *   @0x204678 vcvt.f64.s32 d6, s10
 *   @0x20467c vmov d7, r0, r1
 *   @0x204680 vcmpe.f64 d6, d7
 *   @0x204684 vmrs APSR_nzcv, fpscr
 *   @0x204688 vcvtpl.s32.f64 s11, d7
 *   @0x20468c vmovpl r7, s11
 *   @0x204690 cmp r9, r4
 *   @0x204694 bgt 0x204780 <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0x1c4>
 *   @0x204698 mla r11, r6, r10, r9
 *   @0x20469c add r1, r7, #1
 *   @0x2046a0 lsl r6, r6, #4
 *   @0x2046a4 mov r0, #0
 *   @0x2046a8 add r4, r4, #1
 *   @0x2046ac str r4, [sp, #0x4]
 *   @0x2046b0 lsl r11, r11, #4
 *   @0x2046b4 cmp r10, r7
 *   @0x2046b8 bgt 0x204748 <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0x18c>
 *   @0x2046bc vmov s10, r9
 *   @0x2046c0 mov r2, r11
 *   @0x2046c4 vmul.f64 d4, d9, d9
 *   @0x2046c8 mov r3, r10
 *   @0x2046cc str r7, [sp]
 *   @0x2046d0 vcvt.f64.s32 d6, s10
 *   @0x2046d4 vsub.f64 d6, d6, d10
 *   @0x2046d8 vmul.f64 d6, d6, d6
 *   @0x2046dc vmov s10, r3
 *   @0x2046e0 add r3, r3, #1
 *   @0x2046e4 vcvt.f64.s32 d7, s10
 *   @0x2046e8 vsub.f64 d7, d7, d8
 *   @0x2046ec vmov.f64 d5, d6
 *   @0x2046f0 vmla.f64 d5, d7, d7
 *   @0x2046f4 vcmpe.f64 d4, d5
 *   @0x2046f8 vmrs APSR_nzcv, fpscr
 *   @0x2046fc blt 0x204738 <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0x17c>
 *   @0x204700 ldr r4, [r8]
 *   @0x204704 add r12, r4, r2
 *   @0x204708 ldr r7, [r12, #0xc]
 *   @0x20470c cmp r7, #0
 *   @0x204710 bne 0x204738 <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0x17c>
 *   @0x204714 ldr r4, [r4, r2]
 *   @0x204718 vldr s15, [r12, #4]
 *   @0x20471c vldr s10, [r5]
 *   @0x204720 vldr s11, [r5, #4]
 *   @0x204724 add r0, r0, #1
 *   @0x204728 vmov s14, r4
 *   @0x20472c vadd.f64 d7, d5, d7
 *   @0x204730 vstr s14, [r5]
 *   @0x204734 vstr s15, [r5, #4]
 *   @0x204738 cmp r3, r1
 *   @0x20473c add r2, r2, r6
 *   @0x204740 bne 0x2046dc <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0x120>
 *   @0x204744 ldr r7, [sp]
 *   @0x204748 ldr r3, [sp, #0x4]
 *   @0x20474c add r9, r9, #1
 *   @0x204750 add r11, r11, #16
 *   @0x204754 cmp r9, r3
 *   @0x204758 bne 0x2046b4 <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0xf8>
 *   @0x20475c cmp r0, #0
 *   @0x204760 beq 0x204780 <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd+0x1c4>
 *   @0x204764 vmov s11, r0
 *   @0x204768 ldm r5, {r2, r3}
 *   @0x20476c vcvt.f64.s32 d7, s11
 *   @0x204770 vmov d6, r2, r3
 *   @0x204774 vdiv.f64 d6, d6, d7
 *   @0x204778 vmov r2, r3, d6
 *   @0x20477c stm r5, {r2, r3}
 *   @0x204780 add sp, sp, #12
 *   @0x204784 vpop {d8, d9, d10}
 *   @0x204788 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §36/66 CBackground::CreateFromBitmap(IBitmap*, bool, bool, bool, bool)  0xc244c  size 460  115 条（0xc244c..0xc2618）
 * @func 0xc244c 0xc2618  size 460  115 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×3 / CBackground::CreateFromBitmap(IBitmap*, bool, bool, bool, bool)+0xf4×2 / CBackground::Clear() / Graphics::GetMaxTextureSize() / CBitmap32::CBitmap32(IBitmap*, bool, bool, int) / CBackground::InitTexture() / CBitmap32::CBitmap32(int, int, unsigned int) / CBitmap32::CreateBitmap32()
 * 字段偏移 top8: 0x4×7 / 0x10×5 / 0x8×3 / 0x9×3 / 0x28×1 / 0x2c×1 / 0xa×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc244c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xc2450 sub sp, sp, #12
 *   @0xc2454 mov r5, r1
 *   @0xc2458 mov r4, r0
 *   @0xc245c mov r6, r2
 *   @0xc2460 mov r9, r3
 *   @0xc2464 ldrb r8, [sp, #0x28]
 *   @0xc2468 ldrb r7, [sp, #0x2c]
 *   @0xc246c bl 0xc23c0 <_ZN11CBackground5ClearEv>
 *   @0xc2470 ldr r3, [r5]
 *   @0xc2474 mov r0, r5
 *   @0xc2478 strb r6, [r4, #0x8]
 *   @0xc247c strb r9, [r4, #0x9]
 *   @0xc2480 ldr r3, [r3, #0x10]
 *   @0xc2484 strb r8, [r4, #0xa]
 *   @0xc2488 blx r3
 *   @0xc248c ldr r3, [r5]
 *   @0xc2490 ldr r3, [r3, #0x18]
 *   @0xc2494 str r0, [r4]
 *   @0xc2498 mov r0, r5
 *   @0xc249c blx r3
 *   @0xc24a0 str r0, [r4, #0x4]
 *   @0xc24a4 bl 0x181374 <_ZN8Graphics17GetMaxTextureSizeEv>
 *   @0xc24a8 ldr r3, [r4]
 *   @0xc24ac cmp r0, r3
 *   @0xc24b0 mov r6, r0
 *   @0xc24b4 blt 0xc2540 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0xf4>
 *   @0xc24b8 ldr r3, [r4, #0x4]
 *   @0xc24bc cmp r0, r3
 *   @0xc24c0 movge r6, #0
 *   @0xc24c4 blt 0xc2540 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0xf4>
 *   @0xc24c8 cmp r7, #0
 *   @0xc24cc ldr r0, [r4, #0x10]
 *   @0xc24d0 beq 0xc25d8 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0x18c>
 *   @0xc24d4 cmp r0, #0
 *   @0xc24d8 beq 0xc24e8 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0x9c>
 *   @0xc24dc ldr r3, [r0]
 *   @0xc24e0 ldr r3, [r3, #0x4]
 *   @0xc24e4 blx r3
 *   @0xc24e8 mov r0, #24
 *   @0xc24ec bl 0x27c524 <_Znwj>
 *   @0xc24f0 ldrb r2, [r4, #0x8]
 *   @0xc24f4 ldrb r3, [r4, #0x9]
 *   @0xc24f8 mov r12, #0
 *   @0xc24fc mov r1, r5
 *   @0xc2500 str r12, [sp]
 *   @0xc2504 mov r7, r0
 *   @0xc2508 bl 0x166fd0 <_ZN9CBitmap32C2EP7IBitmapbbi>
 *   @0xc250c str r7, [r4, #0x10]
 *   @0xc2510 cmp r6, #0
 *   @0xc2514 beq 0xc2528 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0xdc>
 *   @0xc2518 ldr r3, [r6]
 *   @0xc251c mov r0, r6
 *   @0xc2520 ldr r3, [r3, #0x4]
 *   @0xc2524 blx r3
 *   @0xc2528 mov r0, r4
 *   @0xc252c bl 0xc1e60 <_ZN11CBackground11InitTextureEv>
 *   @0xc2530 mov r0, r4
 *   @0xc2534 add sp, sp, #12
 *   @0xc2538 pop {r4, r5, r6, r7, r8, r9, lr}
 *   @0xc253c b 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv>
 *   @0xc2540 ldr r3, [pc, #0xc8]
 *   @0xc2544 mov r2, r6
 *   @0xc2548 ldr r1, [pc, #0xc4]
 *   @0xc254c ldr r3, [pc, r3]
 *   @0xc2550 add r1, pc, r1
 *   @0xc2554 ldr r0, [r3]
 *   @0xc2558 ldr r3, [r0]
 *   @0xc255c ldr r3, [r3, #0xc]
 *   @0xc2560 blx r3
 *   @0xc2564 ldm r4, {r2, r3}
 *   @0xc2568 mov r0, #24
 *   @0xc256c cmp r2, r6
 *   @0xc2570 strle r2, [r4]
 *   @0xc2574 strgt r6, [r4]
 *   @0xc2578 cmp r3, r6
 *   @0xc257c strle r3, [r4, #0x4]
 *   @0xc2580 strgt r6, [r4, #0x4]
 *   @0xc2584 bl 0x27c524 <_Znwj>
 *   @0xc2588 ldr r1, [r4]
 *   @0xc258c ldr r2, [r4, #0x4]
 *   @0xc2590 mov r3, #255
 *   @0xc2594 movt r3, #0xff00
 *   @0xc2598 mov r6, r0
 *   @0xc259c bl 0x166140 <_ZN9CBitmap32C2Eiij>
 *   @0xc25a0 mov r0, r6
 *   @0xc25a4 bl 0x167724 <_ZN9CBitmap3214CreateBitmap32Ev>
 *   @0xc25a8 cmp r6, #0
 *   @0xc25ac mov r5, r0
 *   @0xc25b0 moveq r6, r0
 *   @0xc25b4 beq 0xc24c8 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0x7c>
 *   @0xc25b8 ldr r3, [r6]
 *   @0xc25bc mov r0, r6
 *   @0xc25c0 mov r6, r5
 *   @0xc25c4 ldr r3, [r3, #0x4]
 *   @0xc25c8 blx r3
 *   @0xc25cc cmp r7, #0
 *   @0xc25d0 ldr r0, [r4, #0x10]
 *   @0xc25d4 bne 0xc24d4 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0x88>
 *   @0xc25d8 cmp r0, #0
 *   @0xc25dc beq 0xc25ec <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0x1a0>
 *   @0xc25e0 ldr r3, [r0]
 *   @0xc25e4 ldr r3, [r3, #0x4]
 *   @0xc25e8 blx r3
 *   @0xc25ec mov r0, #24
 *   @0xc25f0 bl 0x27c524 <_Znwj>
 *   @0xc25f4 mov r1, r5
 *   @0xc25f8 ldrb r2, [r4, #0x8]
 *   @0xc25fc ldrb r3, [r4, #0x9]
 *   @0xc2600 mov r7, r0
 *   @0xc2604 bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb>
 *   @0xc2608 str r7, [r4, #0x10]
 *   @0xc260c b 0xc2510 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0xc4>
 *   @0xc2610 eorseq r11, r2, r8, asr #3
 *   @0xc2614 eoreq lr, r6, r4, ror #8
 *
 * ══ §37/66 Graphics::GrabScreenRect(int, int, int, int, int*, int*)  0x17e0dc  size 460  115 条（0x17e0dc..0x17e2a8）
 * @func 0x17e0dc 0x17e2a8  size 460  115 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Window_Get_Height()×2 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / GR_Window_Get_Width() / Graphics::GrabScreenRect(int, int, int, int, int*, int*)+0x1b4 / Graphics::Flush() / 0xb65bc / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x18×2 / 0x1c×2 / 0x50×1 / 0x54×1 / 0x194×1 / 0xd4×1 / 0x94×1 / 0x14×1
 * VFP 指令 25 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17e0dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17e0e0 vpush {d8}
 *   @0x17e0e4 sub sp, sp, #36
 *   @0x17e0e8 mov r9, r0
 *   @0x17e0ec mov r5, r2
 *   @0x17e0f0 ldr r12, [sp, #0x50]
 *   @0x17e0f4 mov r6, r3
 *   @0x17e0f8 ldr r0, [sp, #0x54]
 *   @0x17e0fc mov r10, r1
 *   @0x17e100 ldr r4, [pc, #0x194]
 *   @0x17e104 vmov.f32 s16, #5.000000e-01
 *   @0x17e108 ldr r8, [r12]
 *   @0x17e10c ldr r7, [r0]
 *   @0x17e110 bl 0x17af50 <_Z19GR_Window_Get_Widthv>
 *   @0x17e114 vmov s12, r5
 *   @0x17e118 ldr r4, [pc, r4]
 *   @0x17e11c ldr r3, [r4]
 *   @0x17e120 vldr s15, [r3, #16]
 *   @0x17e124 vcvt.f32.s32 s14, s12
 *   @0x17e128 vcvt.f32.s32 s15, s15
 *   @0x17e12c vmov s12, r0
 *   @0x17e130 vcvt.f32.s32 s13, s12
 *   @0x17e134 vdiv.f32 s15, s13, s15
 *   @0x17e138 vmov.f32 s13, s16
 *   @0x17e13c vmla.f32 s13, s14, s15
 *   @0x17e140 vcvt.s32.f32 s15, s13
 *   @0x17e144 vstr s15, [sp, #24]
 *   @0x17e148 bl 0x17af64 <_Z20GR_Window_Get_Heightv>
 *   @0x17e14c vmov s12, r6
 *   @0x17e150 ldr r3, [r4]
 *   @0x17e154 vldr s15, [r3, #20]
 *   @0x17e158 vcvt.f32.s32 s15, s15
 *   @0x17e15c ldr r12, [sp, #0x18]
 *   @0x17e160 add r3, r12, r8
 *   @0x17e164 cmp r12, #0
 *   @0x17e168 movlt r5, #0
 *   @0x17e16c vcvt.f32.s32 s14, s12
 *   @0x17e170 vmov s12, r0
 *   @0x17e174 vcvt.f32.s32 s13, s12
 *   @0x17e178 vdiv.f32 s15, s13, s15
 *   @0x17e17c vmla.f32 s16, s14, s15
 *   @0x17e180 vcvt.s32.f32 s16, s16
 *   @0x17e184 vmov r12, s16
 *   @0x17e188 cmp r12, #0
 *   @0x17e18c movlt r6, #0
 *   @0x17e190 cmp r3, r9
 *   @0x17e194 add r3, r12, r7
 *   @0x17e198 rsbgt r8, r5, r9
 *   @0x17e19c cmp r3, r10
 *   @0x17e1a0 rsbgt r7, r6, r10
 *   @0x17e1a4 cmp r8, #0
 *   @0x17e1a8 cmpgt r7, #0
 *   @0x17e1ac movgt r5, #0
 *   @0x17e1b0 movle r5, #1
 *   @0x17e1b4 movle r0, #0
 *   @0x17e1b8 ble 0x17e290 <_ZN8Graphics14GrabScreenRectEiiiiPiS0_+0x1b4>
 *   @0x17e1bc mul r11, r7, r8
 *   @0x17e1c0 vstr s16, [sp, #20]
 *   @0x17e1c4 ldr r4, [pc, #0xd4]
 *   @0x17e1c8 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x17e1cc mov r2, #70
 *   @0x17e1d0 mov r3, #1
 *   @0x17e1d4 add r4, pc, r4
 *   @0x17e1d8 lsl r6, r8, #2
 *   @0x17e1dc mov r1, r4
 *   @0x17e1e0 lsl r9, r11, #2
 *   @0x17e1e4 rsb r11, r8, r11
 *   @0x17e1e8 mov r0, r9
 *   @0x17e1ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x17e1f0 mov r1, r4
 *   @0x17e1f4 mov r2, #70
 *   @0x17e1f8 mov r3, #1
 *   @0x17e1fc mov r10, r0
 *   @0x17e200 mov r0, r9
 *   @0x17e204 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x17e208 ldr r3, [pc, #0x94]
 *   @0x17e20c mov r4, r10
 *   @0x17e210 ldr r3, [pc, r3]
 *   @0x17e214 ldr r3, [r3]
 *   @0x17e218 str r3, [sp, #0x1c]
 *   @0x17e21c mov r9, r0
 *   @0x17e220 bl 0x17af64 <_Z20GR_Window_Get_Heightv>
 *   @0x17e224 ldr r12, [sp, #0x14]
 *   @0x17e228 movw r2, #0x1908
 *   @0x17e22c movw r3, #0x1401
 *   @0x17e230 str r9, [sp, #0x8]
 *   @0x17e234 add r1, r12, r7
 *   @0x17e238 stm sp, {r2, r3}
 *   @0x17e23c ldr r12, [sp, #0x1c]
 *   @0x17e240 mov r2, r8
 *   @0x17e244 mov r3, r7
 *   @0x17e248 add r11, r9, r11, lsl #2
 *   @0x17e24c rsb r1, r1, r0
 *   @0x17e250 ldr r0, [sp, #0x18]
 *   @0x17e254 blx r12
 *   @0x17e258 rsb r12, r8, r8, lsl #30
 *   @0x17e25c lsl r8, r12, #2
 *   @0x17e260 mov r0, r4
 *   @0x17e264 mov r1, r11
 *   @0x17e268 add r5, r5, #1
 *   @0x17e26c mov r2, r6
 *   @0x17e270 bl 0xb65bc <memcpy@plt>
 *   @0x17e274 cmp r7, r5
 *   @0x17e278 add r4, r4, r6
 *   @0x17e27c add r11, r11, r8
 *   @0x17e280 bgt 0x17e260 <_ZN8Graphics14GrabScreenRectEiiiiPiS0_+0x184>
 *   @0x17e284 mov r0, r9
 *   @0x17e288 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x17e28c mov r0, r10
 *   @0x17e290 add sp, sp, #36
 *   @0x17e294 vpop {d8}
 *   @0x17e298 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17e29c eoreq pc, r6, r0, lsl r8
 *   @0x17e2a0 andseq r2, r11, r12, asr lr
 *   @0x17e2a4 eoreq pc, r6, r4, lsr r5
 *
 * ══ §38/66 Motion_Potential_Step(CInstance*, float, float, float, int, bool)  0x19ccc8  size 460  115 条（0x19ccc8..0x19ce94）
 * @func 0x19ccc8 0x19ce94  size 460  115 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ComputeDir(float, float, float, float)×2 / TryDir(float, CInstance*, float, int, bool)×2 / CInstance::SetDirection(float)×2 / Motion_Potential_Step(CInstance*, float, float, float, int, bool)+0x118 / TestFree(CInstance*, float, float, int, bool) / CInstance::SetPosition(float, float) / 0xb6700
 * 字段偏移 top8: 0xb4×2 / 0xb8×2 / 0x38×1 / 0x3c×1 / 0x104×1 / 0x50×1 / 0x40×1
 * VFP 指令 48 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19ccc8 push {r4, r5, r6, r7, lr}
 *   @0x19cccc vpush {d8, d9, d10}
 *   @0x19ccd0 vmov s18, r1
 *   @0x19ccd4 vldr s15, [r0, #180]
 *   @0x19ccd8 sub sp, sp, #12
 *   @0x19ccdc mov r4, r0
 *   @0x19cce0 vcmp.f32 s15, s18
 *   @0x19cce4 vldr s14, [r0, #184]
 *   @0x19cce8 vmov s19, r2
 *   @0x19ccec ldr r5, [sp, #0x38]
 *   @0x19ccf0 vmov s17, r3
 *   @0x19ccf4 ldrb r6, [sp, #0x3c]
 *   @0x19ccf8 vmrs APSR_nzcv, fpscr
 *   @0x19ccfc bne 0x19cd1c <_Z21Motion_Potential_StepP9CInstancefffib+0x54>
 *   @0x19cd00 vcmp.f32 s14, s19
 *   @0x19cd04 vmrs APSR_nzcv, fpscr
 *   @0x19cd08 bne 0x19cd1c <_Z21Motion_Potential_StepP9CInstancefffib+0x54>
 *   @0x19cd0c mov r0, #1
 *   @0x19cd10 add sp, sp, #12
 *   @0x19cd14 vpop {d8, d9, d10}
 *   @0x19cd18 pop {r4, r5, r6, r7, pc}
 *   @0x19cd1c vsub.f32 s14, s14, s19
 *   @0x19cd20 vmul.f32 s14, s14, s14
 *   @0x19cd24 vsub.f32 s15, s15, s18
 *   @0x19cd28 vmla.f32 s14, s15, s15
 *   @0x19cd2c vsqrt.f32 s15, s14
 *   @0x19cd30 vcmp.f32 s15, s15
 *   @0x19cd34 vmrs APSR_nzcv, fpscr
 *   @0x19cd38 bne 0x19ce70 <_Z21Motion_Potential_StepP9CInstancefffib+0x1a8>
 *   @0x19cd3c vcmpe.f32 s15, s17
 *   @0x19cd40 vmrs APSR_nzcv, fpscr
 *   @0x19cd44 bls 0x19cde0 <_Z21Motion_Potential_StepP9CInstancefffib+0x118>
 *   @0x19cd48 vmov r2, s18
 *   @0x19cd4c vldr s16, [pc, #300]
 *   @0x19cd50 ldr r0, [r4, #0xb4]
 *   @0x19cd54 vldr s20, [pc, #296]
 *   @0x19cd58 ldr r1, [r4, #0xb8]
 *   @0x19cd5c vmov r3, s19
 *   @0x19cd60 bl 0x19c740 <_Z10ComputeDirffff>
 *   @0x19cd64 vmov s18, r0
 *   @0x19cd68 b 0x19cda0 <_Z21Motion_Potential_StepP9CInstancefffib+0xd8>
 *   @0x19cd6c vadd.f32 s15, s18, s16
 *   @0x19cd70 str r6, [sp]
 *   @0x19cd74 vmov r0, s15
 *   @0x19cd78 bl 0x19cba8 <_Z6TryDirfP9CInstancefib>
 *   @0x19cd7c ldr r2, [pc, #0x104]
 *   @0x19cd80 subs r7, r0, #0
 *   @0x19cd84 bne 0x19cdd0 <_Z21Motion_Potential_StepP9CInstancefffib+0x108>
 *   @0x19cd88 ldr r2, [pc, r2]
 *   @0x19cd8c vldr s15, [r2]
 *   @0x19cd90 vadd.f32 s16, s16, s15
 *   @0x19cd94 vcmpe.f32 s16, s20
 *   @0x19cd98 vmrs APSR_nzcv, fpscr
 *   @0x19cd9c bpl 0x19ce34 <_Z21Motion_Potential_StepP9CInstancefffib+0x16c>
 *   @0x19cda0 vsub.f32 s15, s18, s16
 *   @0x19cda4 mov r1, r4
 *   @0x19cda8 vmov r2, s17
 *   @0x19cdac mov r3, r5
 *   @0x19cdb0 str r6, [sp]
 *   @0x19cdb4 vmov r0, s15
 *   @0x19cdb8 bl 0x19cba8 <_Z6TryDirfP9CInstancefib>
 *   @0x19cdbc mov r1, r4
 *   @0x19cdc0 vmov r2, s17
 *   @0x19cdc4 mov r3, r5
 *   @0x19cdc8 cmp r0, #0
 *   @0x19cdcc beq 0x19cd6c <_Z21Motion_Potential_StepP9CInstancefffib+0xa4>
 *   @0x19cdd0 mov r0, #0
 *   @0x19cdd4 add sp, sp, #12
 *   @0x19cdd8 vpop {d8, d9, d10}
 *   @0x19cddc pop {r4, r5, r6, r7, pc}
 *   @0x19cde0 str r6, [sp]
 *   @0x19cde4 mov r3, r5
 *   @0x19cde8 mov r0, r4
 *   @0x19cdec vmov r1, s18
 *   @0x19cdf0 vmov r2, s19
 *   @0x19cdf4 bl 0x19c6f4 <_Z8TestFreeP9CInstanceffib>
 *   @0x19cdf8 cmp r0, #0
 *   @0x19cdfc beq 0x19cd0c <_Z21Motion_Potential_StepP9CInstancefffib+0x44>
 *   @0x19ce00 vmov r2, s18
 *   @0x19ce04 ldr r1, [r4, #0xb8]
 *   @0x19ce08 vmov r3, s19
 *   @0x19ce0c ldr r0, [r4, #0xb4]
 *   @0x19ce10 bl 0x19c740 <_Z10ComputeDirffff>
 *   @0x19ce14 mov r1, r0
 *   @0x19ce18 mov r0, r4
 *   @0x19ce1c bl 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x19ce20 mov r0, r4
 *   @0x19ce24 vmov r1, s18
 *   @0x19ce28 vmov r2, s19
 *   @0x19ce2c bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x19ce30 b 0x19cd0c <_Z21Motion_Potential_StepP9CInstancefffib+0x44>
 *   @0x19ce34 ldr r3, [pc, #0x50]
 *   @0x19ce38 ldr r3, [pc, r3]
 *   @0x19ce3c ldrb r3, [r3]
 *   @0x19ce40 cmp r3, #0
 *   @0x19ce44 beq 0x19cdd0 <_Z21Motion_Potential_StepP9CInstancefffib+0x108>
 *   @0x19ce48 ldr r3, [pc, #0x40]
 *   @0x19ce4c vldr s14, [r4, #204]
 *   @0x19ce50 mov r0, r4
 *   @0x19ce54 ldr r3, [pc, r3]
 *   @0x19ce58 vldr s15, [r3]
 *   @0x19ce5c vadd.f32 s15, s14, s15
 *   @0x19ce60 vmov r1, s15
 *   @0x19ce64 bl 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x19ce68 mov r0, r7
 *   @0x19ce6c b 0x19cd10 <_Z21Motion_Potential_StepP9CInstancefffib+0x48>
 *   @0x19ce70 vmov r0, s14
 *   @0x19ce74 bl 0xb6700 <sqrtf@plt>
 *   @0x19ce78 vmov s15, r0
 *   @0x19ce7c b 0x19cd3c <_Z21Motion_Potential_StepP9CInstancefffib+0x74>
 *   @0x19ce80 andeq r0, r0, r0
 *   @0x19ce84 teqmi r4, #0
 *   @0x19ce88 eoreq r3, r5, r4, asr #18
 *   @0x19ce8c mlaeq r5, r12, r8, r3
 *   @0x19ce90 eoreq r3, r5, r4, ror r8
 *
 * ══ §39/66 Motion_Potential_Path(CInstance*, CPath*, float, float, float, float, int, bool)  0x19ce94  size 460  115 条（0x19ce94..0x19d060）
 * @func 0x19ce94 0x19d060  size 460  115 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::AddPoint(float, float, float)×3 / Motion_Potential_Path(CInstance*, CPath*, float, float, float, float, int, bool)+0x168 / CPath::Clear() / CPath::SetKind(int) / CPath::SetClosed(bool) / Motion_Potential_Step(CInstance*, float, float, float, int, bool) / CPath::GetPathLength() / Motion_Potential_Path(CInstance*, CPath*, float, float, float, float, int, bool)+0xc8
 * 字段偏移 top8: 0xc×2 / 0xb4×2 / 0xb8×2 / 0x48×1 / 0x54×1 / 0xcc×1 / 0x50×1 / 0x4×1
 * VFP 指令 36 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19ce94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x19ce98 vpush {d8, d9}
 *   @0x19ce9c subs r6, r1, #0
 *   @0x19cea0 sub sp, sp, #20
 *   @0x19cea4 mov r4, r0
 *   @0x19cea8 mov r10, r2
 *   @0x19ceac mov r9, r3
 *   @0x19ceb0 ldr r8, [sp, #0x48]
 *   @0x19ceb4 vldr s16, [sp, #76]
 *   @0x19ceb8 ldrb r11, [sp, #0x54]
 *   @0x19cebc beq 0x19d034 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x1a0>
 *   @0x19cec0 vmov.f32 s15, #1.000000e+00
 *   @0x19cec4 vcmpe.f32 s16, s15
 *   @0x19cec8 vmrs APSR_nzcv, fpscr
 *   @0x19cecc bmi 0x19cffc <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x168>
 *   @0x19ced0 vmov s13, r8
 *   @0x19ced4 vcmpe.f32 s13, #0
 *   @0x19ced8 vmrs APSR_nzcv, fpscr
 *   @0x19cedc bls 0x19cffc <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x168>
 *   @0x19cee0 vmov s14, r3
 *   @0x19cee4 vldr s18, [r0, #184]
 *   @0x19cee8 vmov s13, r2
 *   @0x19ceec vldr s19, [r0, #180]
 *   @0x19cef0 vsub.f32 s15, s14, s18
 *   @0x19cef4 vmul.f32 s15, s15, s15
 *   @0x19cef8 vsub.f32 s14, s13, s19
 *   @0x19cefc vmla.f32 s15, s14, s14
 *   @0x19cf00 vsqrt.f32 s17, s15
 *   @0x19cf04 vcmp.f32 s17, s17
 *   @0x19cf08 vmrs APSR_nzcv, fpscr
 *   @0x19cf0c bne 0x19d044 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x1b0>
 *   @0x19cf10 ldr r3, [r4, #0xcc]
 *   @0x19cf14 mov r0, r6
 *   @0x19cf18 vmul.f32 s17, s17, s16
 *   @0x19cf1c vldr s16, [pc, #312]
 *   @0x19cf20 str r3, [sp, #0xc]
 *   @0x19cf24 bl 0x1a6f98 <_ZN5CPath5ClearEv>
 *   @0x19cf28 mov r1, #0
 *   @0x19cf2c mov r0, r6
 *   @0x19cf30 mov r5, r1
 *   @0x19cf34 bl 0x1a6e64 <_ZN5CPath7SetKindEi>
 *   @0x19cf38 mov r0, r6
 *   @0x19cf3c mov r1, r5
 *   @0x19cf40 bl 0x1a6e78 <_ZN5CPath9SetClosedEb>
 *   @0x19cf44 mov r3, #0
 *   @0x19cf48 mov r0, r6
 *   @0x19cf4c ldr r1, [r4, #0xb4]
 *   @0x19cf50 ldr r2, [r4, #0xb8]
 *   @0x19cf54 movt r3, #0x42c8
 *   @0x19cf58 bl 0x1a72c0 <_ZN5CPath8AddPointEfff>
 *   @0x19cf5c ldr r3, [sp, #0x50]
 *   @0x19cf60 mov r0, r4
 *   @0x19cf64 str r11, [sp, #0x4]
 *   @0x19cf68 mov r1, r10
 *   @0x19cf6c mov r2, r9
 *   @0x19cf70 add r5, r5, #1
 *   @0x19cf74 str r3, [sp]
 *   @0x19cf78 mov r3, r8
 *   @0x19cf7c bl 0x19ccc8 <_Z21Motion_Potential_StepP9CInstancefffib>
 *   @0x19cf80 mov r3, #0
 *   @0x19cf84 movt r3, #0x42c8
 *   @0x19cf88 subs r7, r0, #0
 *   @0x19cf8c mov r0, r6
 *   @0x19cf90 bne 0x19d014 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x180>
 *   @0x19cf94 ldr r1, [r4, #0xb4]
 *   @0x19cf98 ldr r2, [r4, #0xb8]
 *   @0x19cf9c bl 0x1a72c0 <_ZN5CPath8AddPointEfff>
 *   @0x19cfa0 mov r0, r6
 *   @0x19cfa4 bl 0x1a7ab8 <_ZN5CPath13GetPathLengthEv>
 *   @0x19cfa8 vmov s15, r0
 *   @0x19cfac vcmpe.f32 s17, s15
 *   @0x19cfb0 vmrs APSR_nzcv, fpscr
 *   @0x19cfb4 bmi 0x19cfd0 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x13c>
 *   @0x19cfb8 vcmp.f32 s16, s15
 *   @0x19cfbc vmov s16, r0
 *   @0x19cfc0 vmrs APSR_nzcv, fpscr
 *   @0x19cfc4 bne 0x19d00c <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x178>
 *   @0x19cfc8 cmp r5, #100
 *   @0x19cfcc ble 0x19cf5c <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0xc8>
 *   @0x19cfd0 mov r0, r4
 *   @0x19cfd4 vmov r1, s19
 *   @0x19cfd8 vmov r2, s18
 *   @0x19cfdc bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x19cfe0 mov r0, r4
 *   @0x19cfe4 ldr r1, [sp, #0xc]
 *   @0x19cfe8 bl 0x193064 <_ZN9CInstance12SetDirectionEf>
 *   @0x19cfec mov r0, r7
 *   @0x19cff0 add sp, sp, #20
 *   @0x19cff4 vpop {d8, d9}
 *   @0x19cff8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19cffc mov r0, #0
 *   @0x19d000 add sp, sp, #20
 *   @0x19d004 vpop {d8, d9}
 *   @0x19d008 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19d00c mov r5, r7
 *   @0x19d010 b 0x19cf5c <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0xc8>
 *   @0x19d014 mov r0, r6
 *   @0x19d018 mov r1, r10
 *   @0x19d01c mov r2, r9
 *   @0x19d020 mov r3, #0
 *   @0x19d024 movt r3, #0x42c8
 *   @0x19d028 mov r7, #1
 *   @0x19d02c bl 0x1a72c0 <_ZN5CPath8AddPointEfff>
 *   @0x19d030 b 0x19cfd0 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x13c>
 *   @0x19d034 mov r0, r6
 *   @0x19d038 add sp, sp, #20
 *   @0x19d03c vpop {d8, d9}
 *   @0x19d040 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19d044 vmov r0, s15
 *   @0x19d048 bl 0xb6700 <sqrtf@plt>
 *   @0x19d04c vldr s19, [r4, #180]
 *   @0x19d050 vldr s18, [r4, #184]
 *   @0x19d054 vmov s17, r0
 *   @0x19d058 b 0x19cf10 <_Z21Motion_Potential_PathP9CInstanceP5CPathffffib+0x7c>
 *   @0x19d05c andeq r0, r0, r0
 *
 * ══ §40/66 Script_Load(CStream*)  0x1e0018  size 460  115 条（0x1e0018..0x1e01e4）
 * @func 0x1e0018 0x1e01e4  size 460  115 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×2 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / MemoryManager::Free(void const*)×2 / Script_Init() / Script_Load(CStream*)+0x1a0 / CStream::ReadBoolean() / CStream::ReadString(char const*&) / operator new(unsigned int)
 * 字段偏移 top8: 0x4×7 / 0x2×4 / 0x170×2 / 0x16c×1 / 0x164×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e0018 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e001c sub sp, sp, #12
 *   @0x1e0020 str r0, [sp, #0x4]
 *   @0x1e0024 bl 0x1dff7c <_Z11Script_Initv>
 *   @0x1e0028 ldr r0, [sp, #0x4]
 *   @0x1e002c bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e0030 cmp r0, #800
 *   @0x1e0034 cmpne r0, #400
 *   @0x1e0038 mov r7, r0
 *   @0x1e003c moveq r4, #0
 *   @0x1e0040 movne r4, #1
 *   @0x1e0044 beq 0x1e0054 <_Z11Script_LoadP7CStream+0x3c>
 *   @0x1e0048 mov r0, #0
 *   @0x1e004c add sp, sp, #12
 *   @0x1e0050 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e0054 ldr r0, [sp, #0x4]
 *   @0x1e0058 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1e005c ldr r5, [pc, #0x170]
 *   @0x1e0060 ldr r11, [pc, #0x170]
 *   @0x1e0064 mov r3, #107
 *   @0x1e0068 ldr r9, [pc, #0x16c]
 *   @0x1e006c add r5, pc, r5
 *   @0x1e0070 ldr r11, [pc, r11]
 *   @0x1e0074 ldr r10, [pc, #0x164]
 *   @0x1e0078 ldr r9, [pc, r9]
 *   @0x1e007c mov r2, r5
 *   @0x1e0080 mov lr, r0
 *   @0x1e0084 lsl r1, r0, #2
 *   @0x1e0088 add r0, r9, #4
 *   @0x1e008c str lr, [r11]
 *   @0x1e0090 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e0094 ldr r1, [r11]
 *   @0x1e0098 ldr r10, [pc, r10]
 *   @0x1e009c mov r3, #108
 *   @0x1e00a0 mov r2, r5
 *   @0x1e00a4 mov r0, r10
 *   @0x1e00a8 lsl r1, r1, #2
 *   @0x1e00ac bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1e00b0 ldr r3, [r11]
 *   @0x1e00b4 cmp r3, #0
 *   @0x1e00b8 movgt r8, r4
 *   @0x1e00bc bgt 0x1e00d4 <_Z11Script_LoadP7CStream+0xbc>
 *   @0x1e00c0 b 0x1e01b8 <_Z11Script_LoadP7CStream+0x1a0>
 *   @0x1e00c4 ldr r3, [r11]
 *   @0x1e00c8 add r4, r4, #1
 *   @0x1e00cc cmp r3, r4
 *   @0x1e00d0 ble 0x1e01b8 <_Z11Script_LoadP7CStream+0x1a0>
 *   @0x1e00d4 cmp r7, #800
 *   @0x1e00d8 ldrne r6, [sp, #0x4]
 *   @0x1e00dc beq 0x1e01c4 <_Z11Script_LoadP7CStream+0x1ac>
 *   @0x1e00e0 mov r0, r6
 *   @0x1e00e4 lsl r5, r4, #2
 *   @0x1e00e8 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x1e00ec ldr r2, [r9, #0x4]
 *   @0x1e00f0 str r8, [r2, r4, lsl #2]
 *   @0x1e00f4 ldr r2, [r10]
 *   @0x1e00f8 mov r3, r0
 *   @0x1e00fc ldr r0, [r2, r4, lsl #2]
 *   @0x1e0100 str r3, [sp]
 *   @0x1e0104 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e0108 ldr r3, [sp]
 *   @0x1e010c ldr r2, [r10]
 *   @0x1e0110 cmp r3, #0
 *   @0x1e0114 str r8, [r2, r4, lsl #2]
 *   @0x1e0118 beq 0x1e0188 <_Z11Script_LoadP7CStream+0x170>
 *   @0x1e011c ldr r3, [r10]
 *   @0x1e0120 add r1, r3, r5
 *   @0x1e0124 ldr r0, [r3, r4, lsl #2]
 *   @0x1e0128 cmp r0, #0
 *   @0x1e012c beq 0x1e0144 <_Z11Script_LoadP7CStream+0x12c>
 *   @0x1e0130 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1e0134 ldr r3, [r10]
 *   @0x1e0138 str r8, [r3, r5]
 *   @0x1e013c ldr r1, [r10]
 *   @0x1e0140 add r1, r1, r5
 *   @0x1e0144 mov r0, r6
 *   @0x1e0148 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0x1e014c mov r0, #28
 *   @0x1e0150 bl 0x27c524 <_Znwj>
 *   @0x1e0154 ldr r2, [r10]
 *   @0x1e0158 ldr r1, [r2, r5]
 *   @0x1e015c str r0, [sp]
 *   @0x1e0160 bl 0x1dfc04 <_ZN7CScriptC2EPKc>
 *   @0x1e0164 ldr r3, [sp]
 *   @0x1e0168 mov r1, r6
 *   @0x1e016c ldr r2, [r9, #0x4]
 *   @0x1e0170 str r3, [r2, r5]
 *   @0x1e0174 ldr r3, [r9, #0x4]
 *   @0x1e0178 ldr r0, [r3, r5]
 *   @0x1e017c bl 0x1dfc88 <_ZN7CScript14LoadFromStreamEP7CStream>
 *   @0x1e0180 cmp r0, #0
 *   @0x1e0184 beq 0x1e0048 <_Z11Script_LoadP7CStream+0x30>
 *   @0x1e0188 cmp r7, #800
 *   @0x1e018c bne 0x1e00c4 <_Z11Script_LoadP7CStream+0xac>
 *   @0x1e0190 cmp r6, #0
 *   @0x1e0194 beq 0x1e00c4 <_Z11Script_LoadP7CStream+0xac>
 *   @0x1e0198 mov r0, r6
 *   @0x1e019c add r4, r4, #1
 *   @0x1e01a0 bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x1e01a4 mov r0, r6
 *   @0x1e01a8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1e01ac ldr r3, [r11]
 *   @0x1e01b0 cmp r3, r4
 *   @0x1e01b4 bgt 0x1e00d4 <_Z11Script_LoadP7CStream+0xbc>
 *   @0x1e01b8 mov r0, #1
 *   @0x1e01bc add sp, sp, #12
 *   @0x1e01c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e01c4 ldr r0, [sp, #0x4]
 *   @0x1e01c8 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv>
 *   @0x1e01cc mov r6, r0
 *   @0x1e01d0 b 0x1e00e0 <_Z11Script_LoadP7CStream+0xc8>
 *   @0x1e01d4 mulseq r7, r8, r12
 *   @0x1e01d8 .word 0x00210cbc
 *   @0x1e01dc .word 0x00210cb0
 *   @0x1e01e0 mlaeq r1, r8, r12, r0
 *
 * ══ §41/66 CTimeLine::DeleteMoment(int)  0x1f2250  size 460  115 条（0x1f2250..0x1f241c）
 * @func 0x1f2250 0x1f241c  size 460  115 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / CTimeLine::DeleteMoment(int)+0x1ac / CTimeLine::DeleteMoment(int)+0x1bc / CTimeLine::DeleteMoment(int)+0x118 / operator delete(void*) / CTimeLine::DeleteMoment(int)+0x12c / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x10×5 / 0x14×5 / 0xc×5 / 0x4×3 / 0x2×2 / 0x8×2 / 0x60×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f2250 push {r4, r5, r6, r7, lr}
 *   @0x1f2254 mov r6, r0
 *   @0x1f2258 ldr r5, [r0, #0x10]
 *   @0x1f225c sub sp, sp, #12
 *   @0x1f2260 cmp r5, #0
 *   @0x1f2264 beq 0x1f22bc <_ZN9CTimeLine12DeleteMomentEi+0x6c>
 *   @0x1f2268 sub r12, r5, #1
 *   @0x1f226c ldr r0, [r0, #0x14]
 *   @0x1f2270 ble 0x1f23fc <_ZN9CTimeLine12DeleteMomentEi+0x1ac>
 *   @0x1f2274 ldr r3, [r0]
 *   @0x1f2278 cmp r1, r3
 *   @0x1f227c ble 0x1f240c <_ZN9CTimeLine12DeleteMomentEi+0x1bc>
 *   @0x1f2280 mov r2, r0
 *   @0x1f2284 mov r4, #0
 *   @0x1f2288 b 0x1f2298 <_ZN9CTimeLine12DeleteMomentEi+0x48>
 *   @0x1f228c ldr r3, [r2, #0x4]!
 *   @0x1f2290 cmp r3, r1
 *   @0x1f2294 bge 0x1f22b4 <_ZN9CTimeLine12DeleteMomentEi+0x64>
 *   @0x1f2298 add r4, r4, #1
 *   @0x1f229c cmp r4, r5
 *   @0x1f22a0 lsl r7, r4, #2
 *   @0x1f22a4 bne 0x1f228c <_ZN9CTimeLine12DeleteMomentEi+0x3c>
 *   @0x1f22a8 ldr r3, [r0, r12, lsl #2]
 *   @0x1f22ac lsl r7, r12, #2
 *   @0x1f22b0 mov r4, r12
 *   @0x1f22b4 cmp r1, r3
 *   @0x1f22b8 beq 0x1f22c4 <_ZN9CTimeLine12DeleteMomentEi+0x74>
 *   @0x1f22bc add sp, sp, #12
 *   @0x1f22c0 pop {r4, r5, r6, r7, pc}
 *   @0x1f22c4 ldr lr, [r6, #0x8]
 *   @0x1f22c8 cmp r4, lr
 *   @0x1f22cc bge 0x1f236c <_ZN9CTimeLine12DeleteMomentEi+0x11c>
 *   @0x1f22d0 ldr r3, [r6, #0xc]
 *   @0x1f22d4 ldr r2, [r3, r7]
 *   @0x1f22d8 tst r2, #1
 *   @0x1f22dc movne r2, #0
 *   @0x1f22e0 strne r2, [r3, r7]
 *   @0x1f22e4 cmp r4, #0
 *   @0x1f22e8 blt 0x1f2368 <_ZN9CTimeLine12DeleteMomentEi+0x118>
 *   @0x1f22ec ldr r3, [r6, #0xc]
 *   @0x1f22f0 cmp r3, #0
 *   @0x1f22f4 beq 0x1f2368 <_ZN9CTimeLine12DeleteMomentEi+0x118>
 *   @0x1f22f8 ldr r0, [r3, r7]
 *   @0x1f22fc add r2, r3, r7
 *   @0x1f2300 cmp r0, #0
 *   @0x1f2304 beq 0x1f2328 <_ZN9CTimeLine12DeleteMomentEi+0xd8>
 *   @0x1f2308 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f230c ldr r3, [r6, #0xc]
 *   @0x1f2310 mov r2, #0
 *   @0x1f2314 ldr lr, [r6, #0x8]
 *   @0x1f2318 ldr r5, [r6, #0x10]
 *   @0x1f231c str r2, [r3, r7]
 *   @0x1f2320 ldr r3, [r6, #0xc]
 *   @0x1f2324 add r2, r3, r7
 *   @0x1f2328 sub lr, lr, #2
 *   @0x1f232c cmp r4, lr
 *   @0x1f2330 bge 0x1f2360 <_ZN9CTimeLine12DeleteMomentEi+0x110>
 *   @0x1f2334 lsl r1, r4, #2
 *   @0x1f2338 mov r2, r4
 *   @0x1f233c add r0, r1, #4
 *   @0x1f2340 add r2, r2, #1
 *   @0x1f2344 cmp r2, lr
 *   @0x1f2348 ldr r12, [r3, r0]
 *   @0x1f234c str r12, [r3, r1]
 *   @0x1f2350 mov r1, r0
 *   @0x1f2354 ldr r3, [r6, #0xc]
 *   @0x1f2358 bne 0x1f233c <_ZN9CTimeLine12DeleteMomentEi+0xec>
 *   @0x1f235c add r2, r3, r2, lsl #2
 *   @0x1f2360 mov r3, #0
 *   @0x1f2364 str r3, [r2]
 *   @0x1f2368 ldr r0, [r6, #0x14]
 *   @0x1f236c sub r3, r5, #2
 *   @0x1f2370 cmp r4, r3
 *   @0x1f2374 bge 0x1f2398 <_ZN9CTimeLine12DeleteMomentEi+0x148>
 *   @0x1f2378 add r3, r0, r4, lsl #2
 *   @0x1f237c ldr r2, [r3, #0x4]
 *   @0x1f2380 add r4, r4, #1
 *   @0x1f2384 str r2, [r3], #4
 *   @0x1f2388 ldr r5, [r6, #0x10]
 *   @0x1f238c sub r2, r5, #2
 *   @0x1f2390 cmp r4, r2
 *   @0x1f2394 blt 0x1f237c <_ZN9CTimeLine12DeleteMomentEi+0x12c>
 *   @0x1f2398 cmp r5, #0
 *   @0x1f239c sub r3, r5, #1
 *   @0x1f23a0 str r3, [r6, #0x10]
 *   @0x1f23a4 beq 0x1f23d8 <_ZN9CTimeLine12DeleteMomentEi+0x188>
 *   @0x1f23a8 lsls r1, r5, #2
 *   @0x1f23ac beq 0x1f23ec <_ZN9CTimeLine12DeleteMomentEi+0x19c>
 *   @0x1f23b0 ldr r2, [pc, #0x60]
 *   @0x1f23b4 mov r3, #0
 *   @0x1f23b8 str r3, [sp]
 *   @0x1f23bc mov r3, #106
 *   @0x1f23c0 add r2, pc, r2
 *   @0x1f23c4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f23c8 str r0, [r6, #0x14]
 *   @0x1f23cc str r5, [r6, #0x10]
 *   @0x1f23d0 add sp, sp, #12
 *   @0x1f23d4 pop {r4, r5, r6, r7, pc}
 *   @0x1f23d8 cmp r0, #0
 *   @0x1f23dc beq 0x1f23ec <_ZN9CTimeLine12DeleteMomentEi+0x19c>
 *   @0x1f23e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f23e4 str r5, [r6, #0x14]
 *   @0x1f23e8 b 0x1f23cc <_ZN9CTimeLine12DeleteMomentEi+0x17c>
 *   @0x1f23ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f23f0 mov r3, #0
 *   @0x1f23f4 str r3, [r6, #0x14]
 *   @0x1f23f8 b 0x1f23cc <_ZN9CTimeLine12DeleteMomentEi+0x17c>
 *   @0x1f23fc lsl r7, r12, #2
 *   @0x1f2400 mov r4, r12
 *   @0x1f2404 ldr r3, [r0, r12, lsl #2]
 *   @0x1f2408 b 0x1f22b4 <_ZN9CTimeLine12DeleteMomentEi+0x64>
 *   @0x1f240c mov r7, #0
 *   @0x1f2410 mov r4, r7
 *   @0x1f2414 b 0x1f22b4 <_ZN9CTimeLine12DeleteMomentEi+0x64>
 *   @0x1f2418 andseq r0, r6, r4, lsl r3
 *
 * ══ §42/66 ZDecompressStream(CStream&, CStream&)  0x201bbc  size 460  115 条（0x201bbc..0x201d88）
 * @func 0x201bbc 0x201d88  size 460  115 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb69e8×4 / 0xb65b0×2 / 0xb69d0 / CStream::Read(void*, int) / 0xb69dc / ZDecompressStream(CStream&, CStream&)+0x144 / ZDecompressStream(CStream&, CStream&)+0x118 / CStream::Write(void*, int)
 * 字段偏移 top8: 0x10×4 / 0x4×3 / 0x44×2 / 0xc×2 / 0x1ac×1 / 0x1a8×1 / 0x198×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x201bbc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x201bc0 sub sp, sp, #32768
 *   @0x201bc4 ldr r6, [pc, #0x1ac]
 *   @0x201bc8 sub sp, sp, #76
 *   @0x201bcc ldr lr, [pc, #0x1a8]
 *   @0x201bd0 add r12, sp, #12
 *   @0x201bd4 ldr r6, [pc, r6]
 *   @0x201bd8 str r1, [sp, #0x4]
 *   @0x201bdc ldr lr, [pc, lr]
 *   @0x201be0 ldr r1, [pc, #0x198]
 *   @0x201be4 ldr r5, [r6]
 *   @0x201be8 add r7, sp, #32768
 *   @0x201bec str lr, [sp, #0x2c]
 *   @0x201bf0 add lr, sp, #32768
 *   @0x201bf4 add lr, lr, #72
 *   @0x201bf8 movw r10, #0x7fc4
 *   @0x201bfc ldr r3, [pc, #0x180]
 *   @0x201c00 movt r10, #0xffff
 *   @0x201c04 mov r9, r0
 *   @0x201c08 add r1, pc, r1
 *   @0x201c0c mov r0, r12
 *   @0x201c10 mov r2, #56
 *   @0x201c14 str r5, [r7, #0x44]
 *   @0x201c18 ldr r3, [pc, r3]
 *   @0x201c1c mov r4, r12
 *   @0x201c20 str r3, [sp, #0x30]
 *   @0x201c24 mov r3, #0
 *   @0x201c28 str r3, [lr, r10]
 *   @0x201c2c str r3, [sp, #0x34]
 *   @0x201c30 add r7, sp, #72
 *   @0x201c34 str r3, [sp, #0x10]
 *   @0x201c38 bl 0xb69d0 <inflateInit_@plt>
 *   @0x201c3c subs r5, r0, #0
 *   @0x201c40 movne r0, r5
 *   @0x201c44 bne 0x201ce0 <_Z17ZDecompressStreamR7CStreamS0_+0x124>
 *   @0x201c48 add r8, sp, #16384
 *   @0x201c4c sub r11, r7, #60
 *   @0x201c50 add r8, r8, #68
 *   @0x201c54 add r7, sp, #68
 *   @0x201c58 mov r10, #16384
 *   @0x201c5c mov r1, #0
 *   @0x201c60 mov r2, #16384
 *   @0x201c64 mov r0, r7
 *   @0x201c68 bl 0xb65b0 <memset@plt>
 *   @0x201c6c mov r1, #0
 *   @0x201c70 mov r2, #16384
 *   @0x201c74 mov r0, r8
 *   @0x201c78 bl 0xb65b0 <memset@plt>
 *   @0x201c7c mov r0, r9
 *   @0x201c80 mov r1, r7
 *   @0x201c84 mov r2, #16384
 *   @0x201c88 bl 0x20172c <_ZN7CStream4ReadEPvi>
 *   @0x201c8c cmp r0, #0
 *   @0x201c90 str r0, [r4, #0x4]
 *   @0x201c94 beq 0x201d4c <_Z17ZDecompressStreamR7CStreamS0_+0x190>
 *   @0x201c98 str r7, [sp, #0xc]
 *   @0x201c9c mov r0, r11
 *   @0x201ca0 mov r1, #0
 *   @0x201ca4 str r10, [r4, #0x10]
 *   @0x201ca8 str r8, [r4, #0xc]
 *   @0x201cac bl 0xb69dc <inflate@plt>
 *   @0x201cb0 mov r4, r11
 *   @0x201cb4 cmn r0, #4
 *   @0x201cb8 mov r5, r0
 *   @0x201cbc blt 0x201d00 <_Z17ZDecompressStreamR7CStreamS0_+0x144>
 *   @0x201cc0 cmn r0, #3
 *   @0x201cc4 ble 0x201cd4 <_Z17ZDecompressStreamR7CStreamS0_+0x118>
 *   @0x201cc8 cmp r0, #2
 *   @0x201ccc bne 0x201d00 <_Z17ZDecompressStreamR7CStreamS0_+0x144>
 *   @0x201cd0 mvn r5, #2
 *   @0x201cd4 mov r0, r11
 *   @0x201cd8 bl 0xb69e8 <inflateEnd@plt>
 *   @0x201cdc mov r0, r5
 *   @0x201ce0 add r3, sp, #32768
 *   @0x201ce4 ldr r2, [r3, #0x44]
 *   @0x201ce8 ldr r3, [r6]
 *   @0x201cec cmp r2, r3
 *   @0x201cf0 bne 0x201d74 <_Z17ZDecompressStreamR7CStreamS0_+0x1b8>
 *   @0x201cf4 add sp, sp, #32768
 *   @0x201cf8 add sp, sp, #76
 *   @0x201cfc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x201d00 ldr r3, [r11, #0x10]
 *   @0x201d04 mov r1, r8
 *   @0x201d08 ldr r0, [sp, #0x4]
 *   @0x201d0c rsb r3, r3, #16384
 *   @0x201d10 str r3, [sp]
 *   @0x201d14 mov r2, r3
 *   @0x201d18 bl 0x2014c8 <_ZN7CStream5WriteEPvi>
 *   @0x201d1c ldr r3, [sp]
 *   @0x201d20 cmp r3, r0
 *   @0x201d24 bne 0x201d64 <_Z17ZDecompressStreamR7CStreamS0_+0x1a8>
 *   @0x201d28 ldr r3, [r11, #0x10]
 *   @0x201d2c cmp r3, #0
 *   @0x201d30 beq 0x201c9c <_Z17ZDecompressStreamR7CStreamS0_+0xe0>
 *   @0x201d34 cmp r5, #1
 *   @0x201d38 bne 0x201c5c <_Z17ZDecompressStreamR7CStreamS0_+0xa0>
 *   @0x201d3c mov r0, r11
 *   @0x201d40 bl 0xb69e8 <inflateEnd@plt>
 *   @0x201d44 mov r0, #0
 *   @0x201d48 b 0x201ce0 <_Z17ZDecompressStreamR7CStreamS0_+0x124>
 *   @0x201d4c mov r0, r4
 *   @0x201d50 bl 0xb69e8 <inflateEnd@plt>
 *   @0x201d54 cmp r5, #1
 *   @0x201d58 mvnne r0, #2
 *   @0x201d5c moveq r0, #0
 *   @0x201d60 b 0x201ce0 <_Z17ZDecompressStreamR7CStreamS0_+0x124>
 *   @0x201d64 mov r0, r11
 *   @0x201d68 bl 0xb69e8 <inflateEnd@plt>
 *   @0x201d6c mvn r0, #0
 *   @0x201d70 b 0x201ce0 <_Z17ZDecompressStreamR7CStreamS0_+0x124>
 *   @0x201d74 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x201d78 andseq r11, lr, r12, ror sp
 *   @0x201d7c mulseq lr, r8, r7
 *   @0x201d80 andseq pc, r4, r8, lsl r4
 *   @0x201d84 andseq pc, lr, r0, ror #14
 *
 * ══ §43/66 F_JS_Array_setLength(RValue&, CInstance*, CInstance*, int, RValue*)  0x24b934  size 460  115 条（0x24b934..0x24bb00）
 * @func 0x24b934 0x24bb00  size 460  115 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×3 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / YYGetUint32(RValue const*, int) / 0xb6574 / F_JS_Array_setLength(RValue&, CInstance*, CInstance*, int, RValue*)+0xec / F_JS_Array_setLength(RValue&, CInstance*, CInstance*, int, RValue*)+0x50 / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0x4×6 / 0xc×3 / 0x2c×3 / 0x30×1 / 0x1a0×1 / 0x40×1 / 0x140×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24b934 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x24b938 sub sp, sp, #12
 *   @0x24b93c mov r4, r1
 *   @0x24b940 mov r1, #0
 *   @0x24b944 ldr r0, [sp, #0x30]
 *   @0x24b948 bl 0xce950 <_Z11YYGetUint32PK6RValuei>
 *   @0x24b94c ldr r1, [pc, #0x1a0]
 *   @0x24b950 add r1, pc, r1
 *   @0x24b954 mov r7, r0
 *   @0x24b958 ldr r0, [r4, #0x40]
 *   @0x24b95c bl 0xb6574 <strcmp@plt>
 *   @0x24b960 cmp r0, #0
 *   @0x24b964 bne 0x24b984 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x24b968 ldr r3, [r4, #0x4]
 *   @0x24b96c cmp r3, #0
 *   @0x24b970 beq 0x24babc <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x24b974 add r0, r3, #16
 *   @0x24b978 ldr r3, [r0, #0xc]
 *   @0x24b97c cmp r3, #6
 *   @0x24b980 beq 0x24b98c <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x58>
 *   @0x24b984 add sp, sp, #12
 *   @0x24b988 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24b98c ldr r10, [r0]
 *   @0x24b990 ldr r6, [r10, #0x2c]
 *   @0x24b994 subs r4, r7, r6
 *   @0x24b998 sbc r5, r7, r7
 *   @0x24b99c cmp r4, #0
 *   @0x24b9a0 sbcs r0, r5, #0
 *   @0x24b9a4 blt 0x24ba20 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x24b9a8 orrs r0, r4, r5
 *   @0x24b9ac beq 0x24b984 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x24b9b0 ldr r2, [pc, #0x140]
 *   @0x24b9b4 mov r3, #0
 *   @0x24b9b8 ldr r0, [r10, #0x4]
 *   @0x24b9bc lsl r1, r7, #4
 *   @0x24b9c0 str r3, [sp]
 *   @0x24b9c4 add r2, pc, r2
 *   @0x24b9c8 mov r3, #74
 *   @0x24b9cc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x24b9d0 cmp r4, #1
 *   @0x24b9d4 sbcs r3, r5, #0
 *   @0x24b9d8 str r7, [r10, #0x2c]
 *   @0x24b9dc str r0, [r10, #0x4]
 *   @0x24b9e0 blt 0x24b984 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x24b9e4 cmp r0, #0
 *   @0x24b9e8 beq 0x24bacc <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x24b9ec add r0, r0, r6, lsl #4
 *   @0x24b9f0 add r3, r0, #16
 *   @0x24b9f4 mov r1, #5
 *   @0x24b9f8 mov r2, #0
 *   @0x24b9fc subs r4, r4, #1
 *   @0x24ba00 str r1, [r3, #-0x4]
 *   @0x24ba04 sbc r5, r5, #0
 *   @0x24ba08 str r2, [r3, #-0x10]
 *   @0x24ba0c orrs r0, r4, r5
 *   @0x24ba10 add r3, r3, #16
 *   @0x24ba14 bne 0x24b9fc <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x24ba18 add sp, sp, #12
 *   @0x24ba1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x24ba20 ldr r6, [r10, #0x4]
 *   @0x24ba24 cmp r6, #0
 *   @0x24ba28 beq 0x24badc <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x24ba2c lsl r9, r7, #4
 *   @0x24ba30 add r6, r6, r9
 *   @0x24ba34 rsbs r4, r4, #0
 *   @0x24ba38 rsc r5, r5, #0
 *   @0x24ba3c mov r8, #0
 *   @0x24ba40 mvn r11, #-16777216
 *   @0x24ba44 b 0x24ba6c <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x24ba48 subs r4, r4, #1
 *   @0x24ba4c str r8, [r6, #0x8]
 *   @0x24ba50 sbc r5, r5, #0
 *   @0x24ba54 str r8, [r6]
 *   @0x24ba58 orrs r3, r4, r5
 *   @0x24ba5c str r11, [r6, #0xc]
 *   @0x24ba60 mov r2, #0
 *   @0x24ba64 add r6, r6, #16
 *   @0x24ba68 beq 0x24ba90 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x15c>
 *   @0x24ba6c ldr r3, [r6, #0xc]
 *   @0x24ba70 sub r3, r3, #1
 *   @0x24ba74 bic r3, r3, #-16777216
 *   @0x24ba78 bic r3, r3, #3
 *   @0x24ba7c cmp r3, #0
 *   @0x24ba80 bne 0x24ba48 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x24ba84 mov r0, r6
 *   @0x24ba88 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24ba8c b 0x24ba48 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x24ba90 ldr r0, [r10, #0x4]
 *   @0x24ba94 mov r1, r9
 *   @0x24ba98 str r7, [r10, #0x24]
 *   @0x24ba9c mov r3, #74
 *   @0x24baa0 str r2, [sp]
 *   @0x24baa4 ldr r2, [pc, #0x50]
 *   @0x24baa8 add r2, pc, r2
 *   @0x24baac bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x24bab0 str r7, [r10, #0x2c]
 *   @0x24bab4 str r0, [r10, #0x4]
 *   @0x24bab8 b 0x24b984 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x50>
 *   @0x24babc mov r0, r4
 *   @0x24bac0 mov r1, #1
 *   @0x24bac4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24bac8 b 0x24b978 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x44>
 *   @0x24bacc mov r0, r10
 *   @0x24bad0 mov r1, r6
 *   @0x24bad4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24bad8 b 0x24b9f0 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x24badc mov r0, r10
 *   @0x24bae0 mov r1, r7
 *   @0x24bae4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x24bae8 lsl r9, r7, #4
 *   @0x24baec mov r6, r0
 *   @0x24baf0 b 0x24ba34 <_Z20F_JS_Array_setLengthR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x24baf4 andeq r8, lr, r8, asr #31
 *   @0x24baf8 andeq r5, lr, r12, ror #12
 *   @0x24bafc andeq r5, lr, r8, lsl #11
 *
 * ══ §44/66 b2ContactManager::AddPair(void*, void*)  0x2c7b08  size 460  115 条（0x2c7b08..0x2c7cd4）
 * @func 0x2c7b08 0x2c7cd4  size 460  115 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Body::ShouldCollide(b2Body const*) const / b2Contact::Create(b2Fixture*, int, b2Fixture*, int, b2BlockAllocator*)
 * 字段偏移 top8: 0x8×7 / 0x80×5 / 0x10×3 / 0x14×3 / 0xc×3 / 0x4×3 / 0x3c×3 / 0x2c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c7b08 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c7b0c mov r9, r0
 *   @0x2c7b10 ldr r7, [r1, #0x10]
 *   @0x2c7b14 sub sp, sp, #12
 *   @0x2c7b18 ldr r6, [r2, #0x10]
 *   @0x2c7b1c ldr r10, [r1, #0x14]
 *   @0x2c7b20 ldr r1, [r7, #0x8]
 *   @0x2c7b24 ldr r0, [r6, #0x8]
 *   @0x2c7b28 ldr r8, [r2, #0x14]
 *   @0x2c7b2c cmp r1, r0
 *   @0x2c7b30 beq 0x2c7b9c <_ZN16b2ContactManager7AddPairEPvS0_+0x94>
 *   @0x2c7b34 ldr r12, [r0, #0x80]
 *   @0x2c7b38 cmp r12, #0
 *   @0x2c7b3c bne 0x2c7b50 <_ZN16b2ContactManager7AddPairEPvS0_+0x48>
 *   @0x2c7b40 b 0x2c7ba4 <_ZN16b2ContactManager7AddPairEPvS0_+0x9c>
 *   @0x2c7b44 ldr r12, [r12, #0xc]
 *   @0x2c7b48 cmp r12, #0
 *   @0x2c7b4c beq 0x2c7ba4 <_ZN16b2ContactManager7AddPairEPvS0_+0x9c>
 *   @0x2c7b50 ldr r4, [r12]
 *   @0x2c7b54 cmp r1, r4
 *   @0x2c7b58 bne 0x2c7b44 <_ZN16b2ContactManager7AddPairEPvS0_+0x3c>
 *   @0x2c7b5c ldr r4, [r12, #0x4]
 *   @0x2c7b60 add r3, r4, #48
 *   @0x2c7b64 ldr r2, [r4, #0x3c]
 *   @0x2c7b68 ldm r3, {r3, r5, r11}
 *   @0x2c7b6c cmp r7, r3
 *   @0x2c7b70 cmpeq r6, r5
 *   @0x2c7b74 bne 0x2c7b84 <_ZN16b2ContactManager7AddPairEPvS0_+0x7c>
 *   @0x2c7b78 cmp r10, r11
 *   @0x2c7b7c cmpeq r8, r2
 *   @0x2c7b80 beq 0x2c7b9c <_ZN16b2ContactManager7AddPairEPvS0_+0x94>
 *   @0x2c7b84 cmp r6, r3
 *   @0x2c7b88 cmpeq r7, r5
 *   @0x2c7b8c bne 0x2c7b44 <_ZN16b2ContactManager7AddPairEPvS0_+0x3c>
 *   @0x2c7b90 cmp r8, r11
 *   @0x2c7b94 cmpeq r10, r2
 *   @0x2c7b98 bne 0x2c7b44 <_ZN16b2ContactManager7AddPairEPvS0_+0x3c>
 *   @0x2c7b9c add sp, sp, #12
 *   @0x2c7ba0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c7ba4 bl 0x2c7158 <_ZNK6b2Body13ShouldCollideEPKS_>
 *   @0x2c7ba8 cmp r0, #0
 *   @0x2c7bac beq 0x2c7b9c <_ZN16b2ContactManager7AddPairEPvS0_+0x94>
 *   @0x2c7bb0 ldr r0, [r9, #0x44]
 *   @0x2c7bb4 cmp r0, #0
 *   @0x2c7bb8 beq 0x2c7bd8 <_ZN16b2ContactManager7AddPairEPvS0_+0xd0>
 *   @0x2c7bbc ldr r3, [r0]
 *   @0x2c7bc0 mov r1, r7
 *   @0x2c7bc4 mov r2, r6
 *   @0x2c7bc8 ldr r3, [r3, #0x8]
 *   @0x2c7bcc blx r3
 *   @0x2c7bd0 cmp r0, #0
 *   @0x2c7bd4 beq 0x2c7b9c <_ZN16b2ContactManager7AddPairEPvS0_+0x94>
 *   @0x2c7bd8 ldr r12, [r9, #0x4c]
 *   @0x2c7bdc mov r0, r7
 *   @0x2c7be0 mov r1, r10
 *   @0x2c7be4 mov r2, r6
 *   @0x2c7be8 mov r3, r8
 *   @0x2c7bec str r12, [sp]
 *   @0x2c7bf0 bl 0x2cbfbc <_ZN9b2Contact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator>
 *   @0x2c7bf4 cmp r0, #0
 *   @0x2c7bf8 beq 0x2c7b9c <_ZN16b2ContactManager7AddPairEPvS0_+0x94>
 *   @0x2c7bfc ldr r12, [r0, #0x30]
 *   @0x2c7c00 mov r4, #0
 *   @0x2c7c04 ldr r1, [r9, #0x3c]
 *   @0x2c7c08 ldr r5, [r0, #0x34]
 *   @0x2c7c0c ldr r2, [r12, #0x8]
 *   @0x2c7c10 cmp r1, r4
 *   @0x2c7c14 ldr r3, [r5, #0x8]
 *   @0x2c7c18 str r1, [r0, #0xc]
 *   @0x2c7c1c str r4, [r0, #0x8]
 *   @0x2c7c20 mov r4, #0
 *   @0x2c7c24 strne r0, [r1, #0x8]
 *   @0x2c7c28 ldr r1, [r2, #0x80]
 *   @0x2c7c2c str r0, [r9, #0x3c]
 *   @0x2c7c30 cmp r1, r4
 *   @0x2c7c34 str r4, [r0, #0x18]
 *   @0x2c7c38 str r1, [r0, #0x1c]
 *   @0x2c7c3c add r4, r0, #16
 *   @0x2c7c40 str r0, [r0, #0x14]
 *   @0x2c7c44 str r3, [r0, #0x10]
 *   @0x2c7c48 strne r4, [r1, #0x8]
 *   @0x2c7c4c str r4, [r2, #0x80]
 *   @0x2c7c50 mov r4, #0
 *   @0x2c7c54 ldr r1, [r3, #0x80]
 *   @0x2c7c58 str r0, [r0, #0x24]
 *   @0x2c7c5c add r0, r0, #32
 *   @0x2c7c60 str r2, [r0]
 *   @0x2c7c64 cmp r1, r4
 *   @0x2c7c68 str r1, [r0, #0xc]
 *   @0x2c7c6c str r4, [r0, #0x8]
 *   @0x2c7c70 strne r0, [r1, #0x8]
 *   @0x2c7c74 ldrb r1, [r12, #0x2c]
 *   @0x2c7c78 str r0, [r3, #0x80]
 *   @0x2c7c7c cmp r1, #0
 *   @0x2c7c80 bne 0x2c7cc0 <_ZN16b2ContactManager7AddPairEPvS0_+0x1b8>
 *   @0x2c7c84 ldrb r1, [r5, #0x2c]
 *   @0x2c7c88 cmp r1, #0
 *   @0x2c7c8c bne 0x2c7cc0 <_ZN16b2ContactManager7AddPairEPvS0_+0x1b8>
 *   @0x2c7c90 ldrh r1, [r2, #4]
 *   @0x2c7c94 tst r1, #2
 *   @0x2c7c98 orreq r1, r1, #2
 *   @0x2c7c9c moveq r0, #0
 *   @0x2c7ca0 strheq r1, [r2, #4]
 *   @0x2c7ca4 streq r0, [r2, #0xa0]
 *   @0x2c7ca8 ldrh r2, [r3, #4]
 *   @0x2c7cac tst r2, #2
 *   @0x2c7cb0 orreq r2, r2, #2
 *   @0x2c7cb4 strheq r2, [r3, #4]
 *   @0x2c7cb8 moveq r1, #0
 *   @0x2c7cbc streq r1, [r3, #0xa0]
 *   @0x2c7cc0 ldr r3, [r9, #0x40]
 *   @0x2c7cc4 add r3, r3, #1
 *   @0x2c7cc8 str r3, [r9, #0x40]
 *   @0x2c7ccc add sp, sp, #12
 *   @0x2c7cd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §45/66 F_DsMapSecureLoad(RValue&, CInstance*, CInstance*, int, RValue*)  0xfb3c0  size 456  114 条（0xfb3c0..0xfb588）
 * @func 0xfb3c0 0xfb588  size 456  114 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / MemoryManager::Free(void const*)×3 / LoadSave::fseek(_YYFILE*, long, int)×2 / LoadSave::fread(void const*, unsigned int, unsigned int, _YYFILE*)×2 / YYGetString(RValue const*, int) / LoadSave::_GetSaveFileName(char*, int, char const*) / LoadSave::fopen(char const*, char const*) / LoadSave::ftell(_YYFILE*)
 * 字段偏移 top8: 0x404×2 / 0x1ac×1 / 0x430×1 / 0xc×1 / 0x4×1 / 0x160×1 / 0x138×1 / 0x50×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfb3c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xfb3c4 sub sp, sp, #1024
 *   @0xfb3c8 ldr r6, [pc, #0x1ac]
 *   @0xfb3cc sub sp, sp, #12
 *   @0xfb3d0 mov r7, r0
 *   @0xfb3d4 mov r4, #0
 *   @0xfb3d8 ldr r6, [pc, r6]
 *   @0xfb3dc mov r1, r4
 *   @0xfb3e0 ldr r0, [sp, #0x430]
 *   @0xfb3e4 mov r3, r4
 *   @0xfb3e8 ldr r2, [r6]
 *   @0xfb3ec movt r3, #0xbff0
 *   @0xfb3f0 str r4, [r7, #0xc]
 *   @0xfb3f4 add r5, sp, #4
 *   @0xfb3f8 str r3, [r7, #0x4]
 *   @0xfb3fc str r4, [r7]
 *   @0xfb400 str r2, [sp, #0x404]
 *   @0xfb404 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xfb408 mov r1, #1024
 *   @0xfb40c mov r2, r0
 *   @0xfb410 mov r0, r5
 *   @0xfb414 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0xfb418 ldr r1, [pc, #0x160]
 *   @0xfb41c mov r0, r5
 *   @0xfb420 add r1, pc, r1
 *   @0xfb424 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_>
 *   @0xfb428 subs r8, r0, #0
 *   @0xfb42c beq 0xfb4ac <_Z17F_DsMapSecureLoadR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0xfb430 mov r1, r4
 *   @0xfb434 mov r2, #2
 *   @0xfb438 bl 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli>
 *   @0xfb43c mov r0, r8
 *   @0xfb440 bl 0x18de24 <_ZN8LoadSave5ftellEP7_YYFILE>
 *   @0xfb444 ldr r5, [pc, #0x138]
 *   @0xfb448 mov r1, r4
 *   @0xfb44c mov r2, r4
 *   @0xfb450 add r5, pc, r5
 *   @0xfb454 mov r10, r0
 *   @0xfb458 mov r0, r8
 *   @0xfb45c bl 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli>
 *   @0xfb460 mov r1, r5
 *   @0xfb464 movw r2, #0x751
 *   @0xfb468 mov r3, #1
 *   @0xfb46c mov r0, #81
 *   @0xfb470 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xfb474 mov r1, #1
 *   @0xfb478 mov r2, #80
 *   @0xfb47c mov r3, r8
 *   @0xfb480 mov r9, r0
 *   @0xfb484 bl 0x18e070 <_ZN8LoadSave5freadEPKvjjP7_YYFILE>
 *   @0xfb488 strb r4, [r9, #0x50]
 *   @0xfb48c mov r0, r9
 *   @0xfb490 bl 0xfb34c <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0xfb494 cmp r0, r4
 *   @0xfb498 bne 0xfb4c8 <_Z17F_DsMapSecureLoadR6RValueP9CInstanceS2_iPS_+0x108>
 *   @0xfb49c mov r0, r9
 *   @0xfb4a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfb4a4 mov r0, r8
 *   @0xfb4a8 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE>
 *   @0xfb4ac ldr r2, [sp, #0x404]
 *   @0xfb4b0 ldr r3, [r6]
 *   @0xfb4b4 cmp r2, r3
 *   @0xfb4b8 bne 0xfb578 <_Z17F_DsMapSecureLoadR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0xfb4bc add sp, sp, #1024
 *   @0xfb4c0 add sp, sp, #12
 *   @0xfb4c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xfb4c8 mov r1, r5
 *   @0xfb4cc sub r0, r10, #78
 *   @0xfb4d0 movw r2, #0x759
 *   @0xfb4d4 mov r3, #1
 *   @0xfb4d8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xfb4dc sub r11, r10, #79
 *   @0xfb4e0 mov r3, r8
 *   @0xfb4e4 mov r1, #1
 *   @0xfb4e8 mov r2, r11
 *   @0xfb4ec mov r10, r0
 *   @0xfb4f0 bl 0x18e070 <_ZN8LoadSave5freadEPKvjjP7_YYFILE>
 *   @0xfb4f4 add r3, r11, r11, lsl #1
 *   @0xfb4f8 strb r4, [r10, r11]
 *   @0xfb4fc cmp r3, r4
 *   @0xfb500 add r2, r3, #3
 *   @0xfb504 mov r1, r5
 *   @0xfb508 movge r4, r3
 *   @0xfb50c movlt r4, r2
 *   @0xfb510 asr r4, r4, #2
 *   @0xfb514 movw r2, #0x75e
 *   @0xfb518 add r4, r4, #4
 *   @0xfb51c mov r3, #1
 *   @0xfb520 mov r0, r4
 *   @0xfb524 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xfb528 mov r1, r4
 *   @0xfb52c mov r3, #1
 *   @0xfb530 mov r11, r0
 *   @0xfb534 mov r0, r10
 *   @0xfb538 mov r2, r11
 *   @0xfb53c bl 0x1d1ff0 <_Z13base64_decodePKcjPcb>
 *   @0xfb540 mvn r1, #0
 *   @0xfb544 mov r0, r11
 *   @0xfb548 bl 0x13d5ac <_Z11JSONToDSMapPci>
 *   @0xfb54c vmov s15, r0
 *   @0xfb550 mov r0, r11
 *   @0xfb554 vcvt.f64.s32 d7, s15
 *   @0xfb558 vmov r4, r5, d7
 *   @0xfb55c vmov r2, s14
 *   @0xfb560 mov r3, r5
 *   @0xfb564 stm r7, {r2, r3}
 *   @0xfb568 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfb56c mov r0, r10
 *   @0xfb570 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfb574 b 0xfb49c <_Z17F_DsMapSecureLoadR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0xfb578 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xfb57c eoreq r2, pc, r8, ror r5
 *   @0xfb580 .word 0x0023c7d8
 *   @0xfb584 eoreq r12, r3, r12, asr #14
 *
 * ══ §46/66 F_FileTextReadString(RValue&, CInstance*, CInstance*, int, RValue*)  0x137e30  size 456  114 条（0x137e30..0x137ff8）
 * @func 0x137e30 0x137ff8  size 456  114 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LoadSave::yyfeof(_YYFILE*)×2 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / YYGetInt32(RValue const*, int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / LoadSave::fgetc(_YYFILE*) / F_FileTextReadString(RValue&, CInstance*, CInstance*, int, RValue*)+0x184 / YYCreateString(RValue*, char const*) / LoadSave::ftell(_YYFILE*)
 * 字段偏移 top8: 0x8×7 / 0xc×3 / 0x38×1 / 0x180×1 / 0x2×1 / 0x170×1 / 0x15c×1 / 0x138×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x137e30 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x137e34 sub sp, sp, #20
 *   @0x137e38 mov r9, r0
 *   @0x137e3c mov r1, #0
 *   @0x137e40 ldr r0, [sp, #0x38]
 *   @0x137e44 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x137e48 sub r3, r0, #1
 *   @0x137e4c mov r5, r0
 *   @0x137e50 cmp r3, #30
 *   @0x137e54 bhi 0x137e6c <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x3c>
 *   @0x137e58 ldr r3, [pc, #0x180]
 *   @0x137e5c ldr r3, [pc, r3]
 *   @0x137e60 ldr r3, [r3, r0, lsl #2]
 *   @0x137e64 cmp r3, #1
 *   @0x137e68 beq 0x137e84 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x137e6c ldr r0, [pc, #0x170]
 *   @0x137e70 mov r1, #0
 *   @0x137e74 add r0, pc, r0
 *   @0x137e78 add sp, sp, #20
 *   @0x137e7c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x137e80 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x137e84 ldr r1, [pc, #0x15c]
 *   @0x137e88 mov r0, #1024
 *   @0x137e8c movw r2, #0x409
 *   @0x137e90 mov r3, #0
 *   @0x137e94 add r1, pc, r1
 *   @0x137e98 lsl r12, r5, #1
 *   @0x137e9c str r12, [sp, #0xc]
 *   @0x137ea0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x137ea4 ldr r12, [sp, #0xc]
 *   @0x137ea8 mov r4, #0
 *   @0x137eac ldr r10, [pc, #0x138]
 *   @0x137eb0 mov r7, #1024
 *   @0x137eb4 add r6, r12, r5
 *   @0x137eb8 ldr r12, [pc, #0x130]
 *   @0x137ebc ldr r10, [pc, r10]
 *   @0x137ec0 add r6, r10, r6, lsl #2
 *   @0x137ec4 add r12, pc, r12
 *   @0x137ec8 str r12, [sp, #0x8]
 *   @0x137ecc mov r8, r0
 *   @0x137ed0 ldr r0, [r6, #0x8]
 *   @0x137ed4 bl 0x18df2c <_ZN8LoadSave5fgetcEP7_YYFILE>
 *   @0x137ed8 cmp r0, #10
 *   @0x137edc cmpne r0, #13
 *   @0x137ee0 mov r11, r0
 *   @0x137ee4 bne 0x137f30 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x100>
 *   @0x137ee8 mov r3, #12
 *   @0x137eec mla r3, r3, r5, r10
 *   @0x137ef0 ldr r0, [r3, #0x8]
 *   @0x137ef4 bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE>
 *   @0x137ef8 cmp r11, #13
 *   @0x137efc cmpne r11, #10
 *   @0x137f00 beq 0x137f60 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0x137f04 cmp r7, r4
 *   @0x137f08 ble 0x137fb4 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x137f0c mov r0, r9
 *   @0x137f10 mov r3, #0
 *   @0x137f14 mov r1, r8
 *   @0x137f18 strb r3, [r8, r4]
 *   @0x137f1c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x137f20 mov r0, r8
 *   @0x137f24 add sp, sp, #20
 *   @0x137f28 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x137f2c b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x137f30 cmp r4, r7
 *   @0x137f34 add r4, r4, #1
 *   @0x137f38 bge 0x137f88 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x137f3c add r3, r8, r4
 *   @0x137f40 strb r11, [r3, #-0x1]
 *   @0x137f44 ldr r0, [r6, #0x8]
 *   @0x137f48 bl 0x18de7c <_ZN8LoadSave6yyfeofEP7_YYFILE>
 *   @0x137f4c cmp r0, #0
 *   @0x137f50 beq 0x137ed0 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x137f54 cmp r11, #13
 *   @0x137f58 cmpne r11, #10
 *   @0x137f5c bne 0x137f04 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x137f60 ldr r12, [sp, #0xc]
 *   @0x137f64 add r5, r12, r5
 *   @0x137f68 add r10, r10, r5, lsl #2
 *   @0x137f6c ldr r0, [r10, #0x8]
 *   @0x137f70 bl 0x18de24 <_ZN8LoadSave5ftellEP7_YYFILE>
 *   @0x137f74 mov r2, #0
 *   @0x137f78 sub r1, r0, #1
 *   @0x137f7c ldr r0, [r10, #0x8]
 *   @0x137f80 bl 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli>
 *   @0x137f84 b 0x137f04 <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0xd4>
 *   @0x137f88 add r3, r7, r7, lsr #31
 *   @0x137f8c mov r2, #0
 *   @0x137f90 mov r0, r8
 *   @0x137f94 str r2, [sp]
 *   @0x137f98 add r7, r7, r3, asr #1
 *   @0x137f9c ldr r2, [sp, #0x8]
 *   @0x137fa0 movw r3, #0x412
 *   @0x137fa4 mov r1, r7
 *   @0x137fa8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x137fac mov r8, r0
 *   @0x137fb0 b 0x137f3c <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x137fb4 add r1, r7, r7, lsr #31
 *   @0x137fb8 ldr r2, [pc, #0x34]
 *   @0x137fbc mov r0, r8
 *   @0x137fc0 mov r3, #0
 *   @0x137fc4 add r2, pc, r2
 *   @0x137fc8 str r3, [sp]
 *   @0x137fcc add r1, r7, r1, asr #1
 *   @0x137fd0 movw r3, #0x421
 *   @0x137fd4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x137fd8 mov r8, r0
 *   @0x137fdc b 0x137f0c <_Z20F_FileTextReadStringR6RValueP9CInstanceS2_iPS_+0xdc>
 *   @0x137fe0 eoreq r7, r11, r4, lsl r4
 *   @0x137fe4 .word 0x002081bc
 *   @0x137fe8 .word 0x002081bc
 *   @0x137fec .word 0x002b73b8
 *   @0x137ff0 eoreq r8, r0, r12, lsl #3
 *   @0x137ff4 eoreq r8, r0, r12, lsl #1
 *
 * ══ §47/66 CreateVertexBuffer(void*, int)  0x18585c  size 456  114 条（0x18585c..0x185a24）
 * @func 0x18585c 0x185a24  size 456  114 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×2 / CreateVertexBuffer(void*, int)+0x1a0
 * 字段偏移 top8: 0x4×6 / 0x8×6 / 0x10×2 / 0xc×2 / 0x1c×2 / 0x190×1 / 0x184×1 / 0x168×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18585c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x185860 sub sp, sp, #36
 *   @0x185864 mov r2, #70
 *   @0x185868 mov r3, #1
 *   @0x18586c str r1, [sp, #0x4]
 *   @0x185870 ldr r1, [pc, #0x190]
 *   @0x185874 str r0, [sp, #0x10]
 *   @0x185878 mov r0, #12
 *   @0x18587c add r1, pc, r1
 *   @0x185880 ldr r5, [pc, #0x184]
 *   @0x185884 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x185888 ldr r9, [sp, #0x4]
 *   @0x18588c movw r3, #0xe035
 *   @0x185890 movt r3, #0x8637
 *   @0x185894 ldr r12, [sp, #0x4]
 *   @0x185898 add r5, pc, r5
 *   @0x18589c asr r1, r9, #31
 *   @0x1858a0 ldr r2, [pc, #0x168]
 *   @0x1858a4 smull r9, r8, r3, r9
 *   @0x1858a8 movw r3, #0xa11e
 *   @0x1858ac movt r3, #0x7
 *   @0x1858b0 add r8, r8, r12
 *   @0x1858b4 rsb r1, r1, r8, asr #18
 *   @0x1858b8 mls r3, r3, r1, r12
 *   @0x1858bc cmp r3, #0
 *   @0x1858c0 mov r3, #1
 *   @0x1858c4 str r0, [sp, #0x8]
 *   @0x1858c8 ldr r2, [r5, r2]
 *   @0x1858cc str r1, [sp]
 *   @0x1858d0 addgt r1, r1, #1
 *   @0x1858d4 ldr r12, [sp, #0x8]
 *   @0x1858d8 strgt r1, [sp]
 *   @0x1858dc ldr r2, [r2]
 *   @0x1858e0 ldr r9, [sp]
 *   @0x1858e4 ldr r1, [pc, #0x128]
 *   @0x1858e8 str r2, [r0, #0x8]
 *   @0x1858ec mov r2, #70
 *   @0x1858f0 str r9, [r12, #0x4]
 *   @0x1858f4 lsl r0, r9, #3
 *   @0x1858f8 add r1, pc, r1
 *   @0x1858fc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x185900 cmp r9, #0
 *   @0x185904 ldr r9, [sp, #0x8]
 *   @0x185908 str r0, [r9]
 *   @0x18590c ble 0x1859fc <_Z18CreateVertexBufferPvi+0x1a0>
 *   @0x185910 ldr r1, [pc, #0x100]
 *   @0x185914 movw r12, #0xa11d
 *   @0x185918 ldr r2, [pc, #0xfc]
 *   @0x18591c movt r12, #0x7
 *   @0x185920 ldr r3, [pc, #0xf8]
 *   @0x185924 add r9, sp, #28
 *   @0x185928 str r12, [sp, #0xc]
 *   @0x18592c mov r6, r0
 *   @0x185930 str r9, [sp, #0x14]
 *   @0x185934 ldr r4, [sp, #0x4]
 *   @0x185938 ldr r11, [r5, r1]
 *   @0x18593c ldr r7, [r5, r2]
 *   @0x185940 ldr r10, [r5, r3]
 *   @0x185944 mov r5, #0
 *   @0x185948 b 0x185954 <_Z18CreateVertexBufferPvi+0xf8>
 *   @0x18594c ldr r9, [sp, #0x8]
 *   @0x185950 ldr r6, [r9]
 *   @0x185954 ldr r3, [r11]
 *   @0x185958 mov r0, #1
 *   @0x18595c add r1, sp, #28
 *   @0x185960 movw r9, #0x5ee2
 *   @0x185964 blx r3
 *   @0x185968 ldr r3, [r7]
 *   @0x18596c movw r0, #0x8892
 *   @0x185970 ldr r1, [sp, #0x1c]
 *   @0x185974 blx r3
 *   @0x185978 ldr r12, [sp, #0xc]
 *   @0x18597c movt r9, #0xfff8
 *   @0x185980 mov r8, r4
 *   @0x185984 cmp r4, r12
 *   @0x185988 ldr r12, [sp, #0x4]
 *   @0x18598c add r9, r4, r9
 *   @0x185990 add r1, r4, r4, lsl #3
 *   @0x185994 rsb r4, r4, r12
 *   @0x185998 movle r9, #0
 *   @0x18599c lsl r1, r1, #2
 *   @0x1859a0 ldr r12, [r10]
 *   @0x1859a4 add lr, r4, r4, lsl #3
 *   @0x1859a8 mov r4, r9
 *   @0x1859ac ldr r9, [sp, #0x10]
 *   @0x1859b0 movwgt r1, #0xa838
 *   @0x1859b4 movw r0, #0x8892
 *   @0x1859b8 movtgt r1, #0x112
 *   @0x1859bc movw r3, #0x88e4
 *   @0x1859c0 add r2, r9, lr, lsl #2
 *   @0x1859c4 movwgt r8, #0xa11e
 *   @0x1859c8 movtgt r8, #0x7
 *   @0x1859cc blx r12
 *   @0x1859d0 ldr r3, [r7]
 *   @0x1859d4 movw r0, #0x8892
 *   @0x1859d8 mov r1, #0
 *   @0x1859dc blx r3
 *   @0x1859e0 ldr r12, [sp]
 *   @0x1859e4 add r6, r6, r5, lsl #3
 *   @0x1859e8 ldr r3, [sp, #0x1c]
 *   @0x1859ec add r5, r5, #1
 *   @0x1859f0 cmp r5, r12
 *   @0x1859f4 stm r6, {r3, r8}
 *   @0x1859f8 bne 0x18594c <_Z18CreateVertexBufferPvi+0xf0>
 *   @0x1859fc ldr r0, [sp, #0x8]
 *   @0x185a00 add sp, sp, #36
 *   @0x185a04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x185a08 ldrheq r11, [r10], -r4
 *   @0x185a0c .word 0x0026c3b8
 *   @0x185a10 .word 0xffffe90c
 *   @0x185a14 andseq r11, r10, r8, lsr r7
 *   @0x185a18 .word 0xffffbb38
 *   @0x185a1c .word 0xffffbb3c
 *   @0x185a20 .word 0xffffbb40
 *
 * ══ §48/66 Path_Load(CStream*)  0x1a7cac  size 456  114 条（0x1a7cac..0x1a7e74）
 * @func 0x1a7cac 0x1a7e74  size 456  114 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CStream::ReadInteger()×2 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / Path_Load(CStream*)+0x198×2 / Path_Init() / CStream::ReadBoolean() / MemoryManager::Free(void const*) / CStream::ReadString(char const*&) / operator new(unsigned int)
 * 字段偏移 top8: 0x4×5 / 0x8×4 / 0x2×3 / 0x168×2 / 0xc×2 / 0x164×1 / 0x15c×1 / 0x114×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a7cac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a7cb0 sub sp, sp, #20
 *   @0x1a7cb4 str r0, [sp, #0x8]
 *   @0x1a7cb8 bl 0x1a7ca8 <_Z9Path_Initv>
 *   @0x1a7cbc ldr r0, [sp, #0x8]
 *   @0x1a7cc0 bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1a7cc4 cmp r0, #800
 *   @0x1a7cc8 cmpne r0, #420
 *   @0x1a7ccc mov r6, r0
 *   @0x1a7cd0 moveq r4, #0
 *   @0x1a7cd4 movne r4, #1
 *   @0x1a7cd8 beq 0x1a7ce8 <_Z9Path_LoadP7CStream+0x3c>
 *   @0x1a7cdc mov r0, #0
 *   @0x1a7ce0 add sp, sp, #20
 *   @0x1a7ce4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a7ce8 ldr r0, [sp, #0x8]
 *   @0x1a7cec bl 0x201730 <_ZN7CStream11ReadIntegerEv>
 *   @0x1a7cf0 ldr r5, [pc, #0x168]
 *   @0x1a7cf4 ldr r9, [pc, #0x168]
 *   @0x1a7cf8 mov r3, #106
 *   @0x1a7cfc ldr r10, [pc, #0x164]
 *   @0x1a7d00 add r5, pc, r5
 *   @0x1a7d04 ldr r9, [pc, r9]
 *   @0x1a7d08 ldr r11, [pc, #0x15c]
 *   @0x1a7d0c add r10, pc, r10
 *   @0x1a7d10 mov r2, r5
 *   @0x1a7d14 mov lr, r0
 *   @0x1a7d18 lsl r1, r0, #2
 *   @0x1a7d1c add r0, r10, #4
 *   @0x1a7d20 str lr, [r9]
 *   @0x1a7d24 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a7d28 ldr lr, [r9]
 *   @0x1a7d2c ldr r11, [pc, r11]
 *   @0x1a7d30 mov r3, #108
 *   @0x1a7d34 mov r2, r5
 *   @0x1a7d38 mov r0, r11
 *   @0x1a7d3c lsl r1, lr, #2
 *   @0x1a7d40 str lr, [r10]
 *   @0x1a7d44 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a7d48 ldr r3, [r9]
 *   @0x1a7d4c cmp r3, #0
 *   @0x1a7d50 ble 0x1a7e44 <_Z9Path_LoadP7CStream+0x198>
 *   @0x1a7d54 ldr r3, [pc, #0x114]
 *   @0x1a7d58 mov r8, r4
 *   @0x1a7d5c mov r7, r4
 *   @0x1a7d60 add r3, pc, r3
 *   @0x1a7d64 str r3, [sp, #0xc]
 *   @0x1a7d68 b 0x1a7d7c <_Z9Path_LoadP7CStream+0xd0>
 *   @0x1a7d6c ldr r2, [r9]
 *   @0x1a7d70 add r8, r8, #1
 *   @0x1a7d74 cmp r2, r8
 *   @0x1a7d78 ble 0x1a7e44 <_Z9Path_LoadP7CStream+0x198>
 *   @0x1a7d7c cmp r6, #800
 *   @0x1a7d80 ldrne r4, [sp, #0x8]
 *   @0x1a7d84 beq 0x1a7e50 <_Z9Path_LoadP7CStream+0x1a4>
 *   @0x1a7d88 mov r0, r4
 *   @0x1a7d8c lsl r5, r8, #2
 *   @0x1a7d90 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv>
 *   @0x1a7d94 ldr r2, [r10, #0x4]
 *   @0x1a7d98 str r7, [r2, r8, lsl #2]
 *   @0x1a7d9c ldr r2, [r11]
 *   @0x1a7da0 str r7, [r2, r8, lsl #2]
 *   @0x1a7da4 cmp r0, #0
 *   @0x1a7da8 beq 0x1a7e14 <_Z9Path_LoadP7CStream+0x168>
 *   @0x1a7dac ldr r2, [r11]
 *   @0x1a7db0 add r1, r2, r5
 *   @0x1a7db4 ldr r0, [r2, r8, lsl #2]
 *   @0x1a7db8 cmp r0, #0
 *   @0x1a7dbc beq 0x1a7dd4 <_Z9Path_LoadP7CStream+0x128>
 *   @0x1a7dc0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1a7dc4 ldr r2, [r11]
 *   @0x1a7dc8 str r7, [r2, r5]
 *   @0x1a7dcc ldr r1, [r11]
 *   @0x1a7dd0 add r1, r1, r5
 *   @0x1a7dd4 mov r0, r4
 *   @0x1a7dd8 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc>
 *   @0x1a7ddc mov r0, #44
 *   @0x1a7de0 bl 0x27c524 <_Znwj>
 *   @0x1a7de4 str r0, [sp, #0x4]
 *   @0x1a7de8 bl 0x1a6e9c <_ZN5CPathC2Ev>
 *   @0x1a7dec ldr r3, [sp, #0xc]
 *   @0x1a7df0 mov r1, r4
 *   @0x1a7df4 ldr r2, [sp, #0x4]
 *   @0x1a7df8 ldr r0, [r3, #0x4]
 *   @0x1a7dfc str r2, [r0, r5]
 *   @0x1a7e00 ldr r2, [r3, #0x4]
 *   @0x1a7e04 ldr r0, [r2, r5]
 *   @0x1a7e08 bl 0x1a7018 <_ZN5CPath14LoadFromStreamEP7CStream>
 *   @0x1a7e0c cmp r0, #0
 *   @0x1a7e10 beq 0x1a7cdc <_Z9Path_LoadP7CStream+0x30>
 *   @0x1a7e14 cmp r6, #800
 *   @0x1a7e18 bne 0x1a7d6c <_Z9Path_LoadP7CStream+0xc0>
 *   @0x1a7e1c cmp r4, #0
 *   @0x1a7e20 beq 0x1a7d6c <_Z9Path_LoadP7CStream+0xc0>
 *   @0x1a7e24 mov r0, r4
 *   @0x1a7e28 add r8, r8, #1
 *   @0x1a7e2c bl 0x201328 <_ZN7CStreamD2Ev>
 *   @0x1a7e30 mov r0, r4
 *   @0x1a7e34 bl 0x27d1d0 <_ZdlPv>
 *   @0x1a7e38 ldr r2, [r9]
 *   @0x1a7e3c cmp r2, r8
 *   @0x1a7e40 bgt 0x1a7d7c <_Z9Path_LoadP7CStream+0xd0>
 *   @0x1a7e44 mov r0, #1
 *   @0x1a7e48 add sp, sp, #20
 *   @0x1a7e4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a7e50 ldr r0, [sp, #0x8]
 *   @0x1a7e54 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv>
 *   @0x1a7e58 mov r4, r0
 *   @0x1a7e5c b 0x1a7d88 <_Z9Path_LoadP7CStream+0xdc>
 *   @0x1a7e60 andseq r5, r10, r12, lsl #8
 *   @0x1a7e64 eoreq r8, r4, r8, asr #21
 *   @0x1a7e68 eorseq r10, r9, r12, lsl r8
 *   @0x1a7e6c eoreq r8, r4, r4, lsr #21
 *   @0x1a7e70 eorseq r10, r9, r8, asr #15
 *
 * ══ §49/66 _PopulateDSGrid(char**, int, int, int)  0x213360  size 456  114 条（0x213360..0x213528）
 * @func 0x213360 0x213528  size 456  114 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AddStringToGrid(CDS_Grid*, int, int, char*)×2 / GetTheGrids(int&) / _PopulateDSGrid(char**, int, int, int)+0x13c / _PopulateDSGrid(char**, int, int, int)+0x130 / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x1×6 / 0x4×3 / 0xc×1 / 0x2×1 / 0x178×1 / 0x-4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x213360 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x213364 subs r9, r0, #0
 *   @0x213368 sub sp, sp, #20
 *   @0x21336c mov r4, r3
 *   @0x213370 str r1, [sp]
 *   @0x213374 beq 0x21349c <_Z15_PopulateDSGridPPciii+0x13c>
 *   @0x213378 add r0, sp, #12
 *   @0x21337c bl 0x10026c <_Z11GetTheGridsRi>
 *   @0x213380 cmp r4, #0
 *   @0x213384 blt 0x21349c <_Z15_PopulateDSGridPPciii+0x13c>
 *   @0x213388 ldr r3, [sp, #0xc]
 *   @0x21338c cmp r4, r3
 *   @0x213390 bge 0x21349c <_Z15_PopulateDSGridPPciii+0x13c>
 *   @0x213394 ldr r3, [sp]
 *   @0x213398 ldr r10, [r0, r4, lsl #2]
 *   @0x21339c cmp r3, #0
 *   @0x2133a0 ble 0x213490 <_Z15_PopulateDSGridPPciii+0x130>
 *   @0x2133a4 ldr r3, [pc, #0x178]
 *   @0x2133a8 mov r8, #0
 *   @0x2133ac add r3, pc, r3
 *   @0x2133b0 str r3, [sp, #0x4]
 *   @0x2133b4 ldr r0, [r9]
 *   @0x2133b8 bl 0xb6538 <strlen@plt>
 *   @0x2133bc mov r3, #1
 *   @0x2133c0 ldr r1, [sp, #0x4]
 *   @0x2133c4 movw r2, #0x172
 *   @0x2133c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2133cc ldr r4, [r9], #4
 *   @0x2133d0 ldrb r3, [r4]
 *   @0x2133d4 cmp r3, #0
 *   @0x2133d8 mov r7, r0
 *   @0x2133dc beq 0x213518 <_Z15_PopulateDSGridPPciii+0x1b8>
 *   @0x2133e0 mov r6, #0
 *   @0x2133e4 mov r2, r0
 *   @0x2133e8 mov r11, r6
 *   @0x2133ec mov r1, r6
 *   @0x2133f0 mov r5, r6
 *   @0x2133f4 b 0x213418 <_Z15_PopulateDSGridPPciii+0xb8>
 *   @0x2133f8 cmp r3, #34
 *   @0x2133fc beq 0x2134a8 <_Z15_PopulateDSGridPPciii+0x148>
 *   @0x213400 strb r3, [r2], #1
 *   @0x213404 mov r1, #0
 *   @0x213408 ldrb r3, [r4, #0x1]
 *   @0x21340c cmp r3, #0
 *   @0x213410 add r4, r4, #1
 *   @0x213414 beq 0x21345c <_Z15_PopulateDSGridPPciii+0xfc>
 *   @0x213418 cmp r3, #44
 *   @0x21341c bne 0x2133f8 <_Z15_PopulateDSGridPPciii+0x98>
 *   @0x213420 cmp r5, #0
 *   @0x213424 bne 0x213400 <_Z15_PopulateDSGridPPciii+0xa0>
 *   @0x213428 mov r1, r6
 *   @0x21342c strb r5, [r2]
 *   @0x213430 mov r3, r7
 *   @0x213434 mov r2, r8
 *   @0x213438 mov r0, r10
 *   @0x21343c add r6, r6, #1
 *   @0x213440 bl 0x2130a4 <_Z15AddStringToGridP8CDS_GridiiPc>
 *   @0x213444 ldrb r3, [r4, #0x1]
 *   @0x213448 mov r2, r7
 *   @0x21344c mov r1, #1
 *   @0x213450 cmp r3, #0
 *   @0x213454 add r4, r4, #1
 *   @0x213458 bne 0x213418 <_Z15_PopulateDSGridPPciii+0xb8>
 *   @0x21345c mov r3, #0
 *   @0x213460 mov r1, r6
 *   @0x213464 strb r3, [r2]
 *   @0x213468 mov r0, r10
 *   @0x21346c mov r2, r8
 *   @0x213470 mov r3, r7
 *   @0x213474 bl 0x2130a4 <_Z15AddStringToGridP8CDS_GridiiPc>
 *   @0x213478 mov r0, r7
 *   @0x21347c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x213480 ldr r3, [sp]
 *   @0x213484 add r8, r8, #1
 *   @0x213488 cmp r8, r3
 *   @0x21348c bne 0x2133b4 <_Z15_PopulateDSGridPPciii+0x54>
 *   @0x213490 mov r0, #1
 *   @0x213494 add sp, sp, #20
 *   @0x213498 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x21349c mov r0, #0
 *   @0x2134a0 add sp, sp, #20
 *   @0x2134a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2134a8 cmp r5, #0
 *   @0x2134ac beq 0x2134c8 <_Z15_PopulateDSGridPPciii+0x168>
 *   @0x2134b0 ldrb r3, [r4, #0x1]
 *   @0x2134b4 cmp r3, #44
 *   @0x2134b8 cmpne r3, #0
 *   @0x2134bc moveq r1, #0
 *   @0x2134c0 moveq r5, r1
 *   @0x2134c4 beq 0x21340c <_Z15_PopulateDSGridPPciii+0xac>
 *   @0x2134c8 cmp r1, #0
 *   @0x2134cc bne 0x2134fc <_Z15_PopulateDSGridPPciii+0x19c>
 *   @0x2134d0 ldr r3, [r9, #-0x4]
 *   @0x2134d4 cmp r3, r4
 *   @0x2134d8 beq 0x21350c <_Z15_PopulateDSGridPPciii+0x1ac>
 *   @0x2134dc cmp r11, #0
 *   @0x2134e0 movne r3, #34
 *   @0x2134e4 ldrbeq r3, [r4, #0x1]
 *   @0x2134e8 strbne r3, [r2], #1
 *   @0x2134ec moveq r11, #1
 *   @0x2134f0 movne r11, r1
 *   @0x2134f4 ldrbne r3, [r4, #0x1]
 *   @0x2134f8 b 0x21340c <_Z15_PopulateDSGridPPciii+0xac>
 *   @0x2134fc ldrb r3, [r4, #0x1]
 *   @0x213500 mov r1, #0
 *   @0x213504 mov r5, #1
 *   @0x213508 b 0x21340c <_Z15_PopulateDSGridPPciii+0xac>
 *   @0x21350c ldrb r3, [r4, #0x1]
 *   @0x213510 mov r5, #1
 *   @0x213514 b 0x21340c <_Z15_PopulateDSGridPPciii+0xac>
 *   @0x213518 mov r6, r3
 *   @0x21351c mov r2, r0
 *   @0x213520 b 0x21345c <_Z15_PopulateDSGridPPciii+0xfc>
 *   @0x213524 ldrsbeq r0, [r4], -r12
 *
 * ══ §50/66 F_NETWORK_Create_Socket_Ext(RValue&, CInstance*, CInstance*, int, RValue*)  0x299394  size 456  114 条（0x299394..0x29955c）
 * @func 0x299394 0x29955c  size 456  114 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2993b0→0x7578e9, 0x2993f4→0x3f5230, 0x29943c→0x75790c
 * 调用序列: YYGetInt32(RValue const*, int)×2 / AllocSocket()×2 / Error_Show_Action(char const*, bool)×2 / F_NETWORK_Create_Socket_Ext(RValue&, CInstance*, CInstance*, int, RValue*)+0x154 / F_NETWORK_Create_Socket_Ext(RValue&, CInstance*, CInstance*, int, RValue*)+0x178 / operator new(unsigned int) / yySocket::yySocket(eSocketType) / yySocket::Init()
 * 字段偏移 top8: 0x4×4 / 0xc×2 / 0x14×2 / 0x19c×1 / 0x198×1 / 0x190×1 / 0x40×1 / 0x150×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x299394 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x299398 mov r5, r0
 *   @0x29939c ldr r4, [pc, #0x19c]
 *   @0x2993a0 mov r2, #0
 *   @0x2993a4 ldr r0, [pc, #0x198]
 *   @0x2993a8 movt r2, #0xbff0
 *   @0x2993ac add r4, pc, r4
 *   @0x2993b0 ldr r1, [pc, #0x190]
 *   @0x2993b4 sub sp, sp, #28
 *   @0x2993b8 mov r3, #0
 *   @0x2993bc ldr r9, [r4, r0]
 *   @0x2993c0 str r2, [r5, #0x4]
 *   @0x2993c4 str r3, [r5, #0xc]
 *   @0x2993c8 ldr r2, [r9]
 *   @0x2993cc str r3, [r5]
 *   @0x2993d0 ldr r10, [sp, #0x40]
 *   @0x2993d4 str r2, [sp, #0x14]
 *   @0x2993d8 ldr r6, [r4, r1]
 *   @0x2993dc ldrb r3, [r6]
 *   @0x2993e0 cmp r3, #0
 *   @0x2993e4 beq 0x299520 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x2993e8 mov r0, r10
 *   @0x2993ec mov r1, #0
 *   @0x2993f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x2993f4 ldr r3, [pc, #0x150]
 *   @0x2993f8 ldr r3, [r4, r3]
 *   @0x2993fc ldr r3, [r3]
 *   @0x299400 sub r3, r3, #2
 *   @0x299404 cmp r3, #2
 *   @0x299408 mov r7, r0
 *   @0x29940c bls 0x2994e8 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x299410 cmp r0, #0
 *   @0x299414 bne 0x2994d0 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x299418 bl 0x298e28 <_Z11AllocSocketv>
 *   @0x29941c subs r8, r0, #0
 *   @0x299420 blt 0x29950c <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x178>
 *   @0x299424 mov r0, #200
 *   @0x299428 add r11, sp, #4
 *   @0x29942c bl 0x27c524 <_Znwj>
 *   @0x299430 mov r1, r7
 *   @0x299434 mov r6, r0
 *   @0x299438 bl 0x2970ac <_ZN8yySocketC2E11eSocketType>
 *   @0x29943c ldr r2, [pc, #0x10c]
 *   @0x299440 add r3, r8, r8, lsl #1
 *   @0x299444 mov r0, r6
 *   @0x299448 ldr r2, [r4, r2]
 *   @0x29944c add r3, r2, r3, lsl #2
 *   @0x299450 str r6, [r3, #0x4]
 *   @0x299454 bl 0x294ec8 <_ZN8yySocket4InitEv>
 *   @0x299458 mov r0, r6
 *   @0x29945c mov r1, #65536
 *   @0x299460 str r8, [r6, #0x68]
 *   @0x299464 bl 0x296080 <_ZN8yySocket14AllocateBufferEi>
 *   @0x299468 mov r0, r6
 *   @0x29946c bl 0x295fec <_ZN8yySocket12CreateSocketEv>
 *   @0x299470 mov r0, r10
 *   @0x299474 mov r1, #1
 *   @0x299478 mov r3, #0
 *   @0x29947c mov r2, #2
 *   @0x299480 str r3, [sp, #0x4]
 *   @0x299484 str r3, [sp, #0x8]
 *   @0x299488 str r3, [sp, #0xc]
 *   @0x29948c str r3, [sp, #0x10]
 *   @0x299490 strh r2, [sp, #4]
 *   @0x299494 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x299498 rev16 r0, r0
 *   @0x29949c cmp r7, #3
 *   @0x2994a0 strh r0, [sp, #6]
 *   @0x2994a4 beq 0x2994c0 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x2994a8 mov r0, r6
 *   @0x2994ac mov r1, r11
 *   @0x2994b0 mov r2, #16
 *   @0x2994b4 bl 0x2951c4 <_ZN8yySocket4BindEPK8sockaddri>
 *   @0x2994b8 cmp r0, #0
 *   @0x2994bc blt 0x299530 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0x2994c0 vmov s15, r8
 *   @0x2994c4 vcvt.f64.s32 d7, s15
 *   @0x2994c8 vmov r2, r3, d7
 *   @0x2994cc stm r5, {r2, r3}
 *   @0x2994d0 ldr r2, [sp, #0x14]
 *   @0x2994d4 ldr r3, [r9]
 *   @0x2994d8 cmp r2, r3
 *   @0x2994dc bne 0x29953c <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x2994e0 add sp, sp, #28
 *   @0x2994e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2994e8 cmp r0, #2
 *   @0x2994ec bne 0x299418 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x2994f0 ldr r0, [pc, #0x5c]
 *   @0x2994f4 mov r1, #0
 *   @0x2994f8 add r0, pc, r0
 *   @0x2994fc bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x299500 bl 0x298e28 <_Z11AllocSocketv>
 *   @0x299504 subs r8, r0, #0
 *   @0x299508 bge 0x299424 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x29950c ldr r0, [pc, #0x44]
 *   @0x299510 mov r1, #0
 *   @0x299514 add r0, pc, r0
 *   @0x299518 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x29951c b 0x2994d0 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x299520 bl 0x294d18 <_ZN8yySocket7StartupEv>
 *   @0x299524 mov r3, #1
 *   @0x299528 strb r3, [r6]
 *   @0x29952c b 0x2993e8 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x299530 mov r0, r8
 *   @0x299534 bl 0x299244 <_Z10FreeSocketi>
 *   @0x299538 b 0x2994d0 <_Z27F_NETWORK_Create_Socket_ExtR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x29953c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x299540 andseq r8, r5, r4, lsr #17
 *   @0x299544 .word 0xffffbd00
 *   @0x299548 .word 0xfffffd4c
 *   @0x29954c .word 0xffffe6d0
 *   @0x299550 .word 0xfffffd54
 *   @0x299554 andeq r0, r12, r12, asr #3
 *   @0x299558 ldrdeq r0, r1, [r12], -r8
 *
 * ══ §51/66 AddTimelineCode(Buffer_Standard*)  0x29f1b8  size 456  114 条（0x29f1b8..0x29f380）
 * @func 0x29f1b8 0x29f380  size 456  114 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: TimeLine_Number() / AddTimelineCode(Buffer_Standard*)+0x1c0 / TimeLine_Data(int) / TimeLine_Name(int) / WriteString(Buffer_Standard*, char const*) / CTimeLine::GetCount() / AddTimelineCode(Buffer_Standard*)+0x1a8 / CTimeLine::GetEvent(int)
 * 字段偏移 top8: 0x8×10 / 0x38×5 / 0x30×4 / 0xc×3 / 0x4×2 / 0x60×1 / 0x50×1 / 0x10×1
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29f1b8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x29f1bc sub sp, sp, #20
 *   @0x29f1c0 mov r11, r0
 *   @0x29f1c4 bl 0x1f2b00 <_Z15TimeLine_Numberv>
 *   @0x29f1c8 ldr r3, [r11]
 *   @0x29f1cc add r5, r11, #44
 *   @0x29f1d0 mov r10, #0
 *   @0x29f1d4 mov r1, #5
 *   @0x29f1d8 str r10, [r11, #0x38]
 *   @0x29f1dc mov r2, r5
 *   @0x29f1e0 str r0, [sp, #0xc]
 *   @0x29f1e4 mov r0, r11
 *   @0x29f1e8 vldr s15, [sp, #12]
 *   @0x29f1ec vcvt.f64.u32 d7, s15
 *   @0x29f1f0 vmov r6, r7, d7
 *   @0x29f1f4 vstr s14, [r11, #44]
 *   @0x29f1f8 str r7, [r11, #0x30]
 *   @0x29f1fc ldr r3, [r3, #0x8]
 *   @0x29f200 blx r3
 *   @0x29f204 ldr r3, [sp, #0xc]
 *   @0x29f208 cmp r3, r10
 *   @0x29f20c ble 0x29f378 <_Z15AddTimelineCodeP15Buffer_Standard+0x1c0>
 *   @0x29f210 mov r9, #10
 *   @0x29f214 mov r7, r10
 *   @0x29f218 str r10, [sp, #0x8]
 *   @0x29f21c ldr r0, [sp, #0x8]
 *   @0x29f220 bl 0x1f2c48 <_Z13TimeLine_Datai>
 *   @0x29f224 mov r6, r0
 *   @0x29f228 ldr r0, [sp, #0x8]
 *   @0x29f22c bl 0x1f2b58 <_Z13TimeLine_Namei>
 *   @0x29f230 mov r1, r0
 *   @0x29f234 mov r0, r11
 *   @0x29f238 bl 0x29e624 <_Z11WriteStringP15Buffer_StandardPKc>
 *   @0x29f23c mov r0, r6
 *   @0x29f240 bl 0x1f1760 <_ZN9CTimeLine8GetCountEv>
 *   @0x29f244 ldr r3, [r11]
 *   @0x29f248 str r7, [r11, #0x38]
 *   @0x29f24c mov r1, #5
 *   @0x29f250 mov r2, r5
 *   @0x29f254 vmov s13, r0
 *   @0x29f258 mov r8, r0
 *   @0x29f25c mov r0, r11
 *   @0x29f260 vcvt.f64.u32 d7, s13
 *   @0x29f264 vstr s14, [r11, #44]
 *   @0x29f268 vstr s15, [r11, #48]
 *   @0x29f26c ldr r3, [r3, #0x8]
 *   @0x29f270 blx r3
 *   @0x29f274 cmp r8, #0
 *   @0x29f278 strgt r8, [sp, #0x4]
 *   @0x29f27c movgt r4, #0
 *   @0x29f280 movgt r8, r11
 *   @0x29f284 ble 0x29f360 <_Z15AddTimelineCodeP15Buffer_Standard+0x1a8>
 *   @0x29f288 mov r1, r4
 *   @0x29f28c mov r0, r6
 *   @0x29f290 bl 0x1f1710 <_ZN9CTimeLine8GetEventEi>
 *   @0x29f294 mov r1, r4
 *   @0x29f298 add r4, r4, #1
 *   @0x29f29c mov r12, r0
 *   @0x29f2a0 mov r0, r6
 *   @0x29f2a4 str r12, [sp]
 *   @0x29f2a8 bl 0x1f1738 <_ZN9CTimeLine7GetStepEi>
 *   @0x29f2ac ldr lr, [r8]
 *   @0x29f2b0 mov r1, #5
 *   @0x29f2b4 mov r2, r5
 *   @0x29f2b8 str r7, [r8, #0x38]
 *   @0x29f2bc vmov s15, r0
 *   @0x29f2c0 mov r0, r8
 *   @0x29f2c4 vcvt.f64.u32 d7, s15
 *   @0x29f2c8 vmov r10, r11, d7
 *   @0x29f2cc vstr s14, [r8, #44]
 *   @0x29f2d0 str r11, [r8, #0x30]
 *   @0x29f2d4 ldr r10, [lr, #0x8]
 *   @0x29f2d8 blx r10
 *   @0x29f2dc ldr r12, [sp]
 *   @0x29f2e0 ldr lr, [r8]
 *   @0x29f2e4 mov r1, #5
 *   @0x29f2e8 mov r2, r5
 *   @0x29f2ec mov r0, r8
 *   @0x29f2f0 ldr r12, [r12, #0x4]
 *   @0x29f2f4 ldr r10, [r12, #0x60]
 *   @0x29f2f8 str r7, [r8, #0x38]
 *   @0x29f2fc vmov s15, r10
 *   @0x29f300 vcvt.f64.u32 d7, s15
 *   @0x29f304 vmov r10, r11, d7
 *   @0x29f308 vstr s14, [r8, #44]
 *   @0x29f30c str r11, [r8, #0x30]
 *   @0x29f310 ldr r10, [lr, #0x8]
 *   @0x29f314 str r12, [sp]
 *   @0x29f318 blx r10
 *   @0x29f31c ldr r12, [sp]
 *   @0x29f320 ldr lr, [r8]
 *   @0x29f324 mov r0, r8
 *   @0x29f328 mov r1, #12
 *   @0x29f32c mov r2, r5
 *   @0x29f330 ldr r12, [r12, #0x50]
 *   @0x29f334 ldr r12, [r12, #0x10]
 *   @0x29f338 str r9, [r8, #0x38]
 *   @0x29f33c asr r11, r12, #31
 *   @0x29f340 str r12, [r8, #0x2c]
 *   @0x29f344 str r11, [r8, #0x30]
 *   @0x29f348 ldr r12, [lr, #0x8]
 *   @0x29f34c blx r12
 *   @0x29f350 ldr r3, [sp, #0x4]
 *   @0x29f354 cmp r4, r3
 *   @0x29f358 bne 0x29f288 <_Z15AddTimelineCodeP15Buffer_Standard+0xd0>
 *   @0x29f35c mov r11, r8
 *   @0x29f360 ldr r3, [sp, #0x8]
 *   @0x29f364 ldr r2, [sp, #0xc]
 *   @0x29f368 add r3, r3, #1
 *   @0x29f36c str r3, [sp, #0x8]
 *   @0x29f370 cmp r3, r2
 *   @0x29f374 bne 0x29f21c <_Z15AddTimelineCodeP15Buffer_Standard+0x64>
 *   @0x29f378 add sp, sp, #20
 *   @0x29f37c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §52/66 jinit_d_main_controller  0x2bf814  size 456  114 条（0x2bf814..0x2bf9dc）
 * @func 0x2bf814 0x2bf9dc  size 456  114 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×2 / jinit_d_main_controller+0x1a4 / jinit_d_main_controller+0x104 / jinit_d_main_controller+0xa0
 * 字段偏移 top8: 0x118×6 / 0x24×6 / 0x4×5 / 0xc4×3 / 0x184×2 / 0x8×2 / 0x38×2 / 0x3c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bf814 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2bf818 mov r2, #80
 *   @0x2bf81c ldr r3, [r0, #0x4]
 *   @0x2bf820 mov r5, r1
 *   @0x2bf824 mov r1, #1
 *   @0x2bf828 mov r4, r0
 *   @0x2bf82c ldr r3, [r3]
 *   @0x2bf830 blx r3
 *   @0x2bf834 ldr r3, [pc, #0x19c]
 *   @0x2bf838 cmp r5, #0
 *   @0x2bf83c add r3, pc, r3
 *   @0x2bf840 str r0, [r4, #0x184]
 *   @0x2bf844 mov r7, r0
 *   @0x2bf848 str r3, [r0]
 *   @0x2bf84c bne 0x2bf99c <jinit_d_main_controller+0x188>
 *   @0x2bf850 ldr r3, [r4, #0x1a0]
 *   @0x2bf854 ldrb r3, [r3, #0x8]
 *   @0x2bf858 cmp r3, #0
 *   @0x2bf85c beq 0x2bf984 <jinit_d_main_controller+0x170>
 *   @0x2bf860 ldr r10, [r4, #0x118]
 *   @0x2bf864 cmp r10, #1
 *   @0x2bf868 ble 0x2bf9b8 <jinit_d_main_controller+0x1a4>
 *   @0x2bf86c ldr r3, [r4, #0x4]
 *   @0x2bf870 mov r0, r4
 *   @0x2bf874 ldr r2, [r4, #0x24]
 *   @0x2bf878 mov r1, #1
 *   @0x2bf87c ldr r11, [r4, #0x184]
 *   @0x2bf880 ldr r3, [r3]
 *   @0x2bf884 lsl r2, r2, #3
 *   @0x2bf888 blx r3
 *   @0x2bf88c ldr r3, [r4, #0x24]
 *   @0x2bf890 ldr r6, [r4, #0xc4]
 *   @0x2bf894 cmp r3, #0
 *   @0x2bf898 mov r5, r6
 *   @0x2bf89c str r0, [r11, #0x38]
 *   @0x2bf8a0 add r0, r0, r3, lsl #2
 *   @0x2bf8a4 str r0, [r11, #0x3c]
 *   @0x2bf8a8 ble 0x2bf918 <jinit_d_main_controller+0x104>
 *   @0x2bf8ac add r10, r10, #4
 *   @0x2bf8b0 mov r5, #0
 *   @0x2bf8b4 ldr r3, [r6, #0xc]
 *   @0x2bf8b8 add r6, r6, #84
 *   @0x2bf8bc ldr r0, [r6, #-0x30]
 *   @0x2bf8c0 ldr r1, [r4, #0x118]
 *   @0x2bf8c4 mul r0, r0, r3
 *   @0x2bf8c8 bl 0x318d10 <__divsi3>
 *   @0x2bf8cc ldr r3, [r4, #0x4]
 *   @0x2bf8d0 mov r1, #1
 *   @0x2bf8d4 ldr r3, [r3]
 *   @0x2bf8d8 mul r8, r10, r0
 *   @0x2bf8dc mov r9, r0
 *   @0x2bf8e0 mov r0, r4
 *   @0x2bf8e4 lsl r2, r8, #3
 *   @0x2bf8e8 blx r3
 *   @0x2bf8ec ldr r2, [r11, #0x38]
 *   @0x2bf8f0 ldr r3, [r4, #0x24]
 *   @0x2bf8f4 add r0, r0, r9, lsl #2
 *   @0x2bf8f8 str r0, [r2, r5, lsl #2]
 *   @0x2bf8fc ldr r2, [r11, #0x3c]
 *   @0x2bf900 add r9, r0, r8, lsl #2
 *   @0x2bf904 str r9, [r2, r5, lsl #2]
 *   @0x2bf908 add r5, r5, #1
 *   @0x2bf90c cmp r5, r3
 *   @0x2bf910 blt 0x2bf8b4 <jinit_d_main_controller+0xa0>
 *   @0x2bf914 ldr r5, [r4, #0xc4]
 *   @0x2bf918 ldr r8, [r4, #0x118]
 *   @0x2bf91c cmp r3, #0
 *   @0x2bf920 add r8, r8, #2
 *   @0x2bf924 pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bf928 mov r6, #0
 *   @0x2bf92c ldr r3, [r5, #0x24]
 *   @0x2bf930 add r6, r6, #1
 *   @0x2bf934 ldr r0, [r5, #0xc]
 *   @0x2bf938 add r7, r7, #4
 *   @0x2bf93c ldr r9, [r5, #0x1c]
 *   @0x2bf940 add r5, r5, #84
 *   @0x2bf944 ldr r1, [r4, #0x118]
 *   @0x2bf948 mul r0, r0, r3
 *   @0x2bf94c ldr r10, [r4, #0x4]
 *   @0x2bf950 mul r9, r9, r3
 *   @0x2bf954 bl 0x318d10 <__divsi3>
 *   @0x2bf958 mov r1, #1
 *   @0x2bf95c ldr r12, [r10, #0x8]
 *   @0x2bf960 mov r2, r9
 *   @0x2bf964 mul r3, r8, r0
 *   @0x2bf968 mov r0, r4
 *   @0x2bf96c blx r12
 *   @0x2bf970 str r0, [r7, #0x4]
 *   @0x2bf974 ldr r3, [r4, #0x24]
 *   @0x2bf978 cmp r3, r6
 *   @0x2bf97c bgt 0x2bf92c <jinit_d_main_controller+0x118>
 *   @0x2bf980 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bf984 ldr r3, [r4, #0x24]
 *   @0x2bf988 ldr r8, [r4, #0x118]
 *   @0x2bf98c cmp r3, #0
 *   @0x2bf990 ldr r5, [r4, #0xc4]
 *   @0x2bf994 bgt 0x2bf928 <jinit_d_main_controller+0x114>
 *   @0x2bf998 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bf99c ldr r3, [r4]
 *   @0x2bf9a0 mov r2, #4
 *   @0x2bf9a4 mov r0, r4
 *   @0x2bf9a8 str r2, [r3, #0x14]
 *   @0x2bf9ac ldr r3, [r3]
 *   @0x2bf9b0 blx r3
 *   @0x2bf9b4 b 0x2bf850 <jinit_d_main_controller+0x3c>
 *   @0x2bf9b8 ldr r3, [r4]
 *   @0x2bf9bc mov r2, #47
 *   @0x2bf9c0 mov r0, r4
 *   @0x2bf9c4 str r2, [r3, #0x14]
 *   @0x2bf9c8 ldr r3, [r3]
 *   @0x2bf9cc blx r3
 *   @0x2bf9d0 ldr r10, [r4, #0x118]
 *   @0x2bf9d4 b 0x2bf86c <jinit_d_main_controller+0x58>
 *   @0x2bf9d8 .word 0xfffffe18
 *
 * ══ §53/66 F_ActionDrawHealth(RValue&, CInstance*, CInstance*, int, RValue*)  0x13f6f0  size 452  113 条（0x13f6f0..0x13f8b4）
 * @func 0x13f6f0 0x13f8b4  size 452  113 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x13f7b4→0x47a174, 0x13f7d4→0x542930, 0x13f840→0x542930
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×2 / GR_Draw_Healthbar(float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, int, bool, bool)×2 / YYGetBool(RValue const*, int)
 * 字段偏移 top8: 0xc×2 / 0x10×2 / 0x14×2 / 0x18×2 / 0x1c×2 / 0x48×1 / 0x190×1 / 0x104×1
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13f6f0 push {r4, r5, r6, r7, r8, lr}
 *   @0x13f6f4 vpush {d8, d9}
 *   @0x13f6f8 sub sp, sp, #32
 *   @0x13f6fc mov r7, r1
 *   @0x13f700 mov r1, #0
 *   @0x13f704 ldr r4, [sp, #0x48]
 *   @0x13f708 ldr r5, [pc, #0x190]
 *   @0x13f70c mov r0, r4
 *   @0x13f710 add r5, pc, r5
 *   @0x13f714 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f718 mov r1, #1
 *   @0x13f71c vmov s19, r0
 *   @0x13f720 mov r0, r4
 *   @0x13f724 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f728 mov r1, #2
 *   @0x13f72c vmov s18, r0
 *   @0x13f730 mov r0, r4
 *   @0x13f734 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f738 mov r1, #3
 *   @0x13f73c vmov s17, r0
 *   @0x13f740 mov r0, r4
 *   @0x13f744 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x13f748 mov r1, #4
 *   @0x13f74c vmov s16, r0
 *   @0x13f750 mov r0, r4
 *   @0x13f754 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13f758 mov r1, #5
 *   @0x13f75c mov r8, r0
 *   @0x13f760 mov r0, r4
 *   @0x13f764 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x13f768 mov r1, #4
 *   @0x13f76c mov r6, r0
 *   @0x13f770 mov r0, r4
 *   @0x13f774 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x13f778 sub r3, r8, #2
 *   @0x13f77c cmp r3, #14
 *   @0x13f780 movhi r8, #0
 *   @0x13f784 mov r4, r0
 *   @0x13f788 ldrls r2, [pc, #0x114]
 *   @0x13f78c addls r2, pc, r2
 *   @0x13f790 ldrls r8, [r2, r3, lsl #2]
 *   @0x13f794 cmp r6, #17
 *   @0x13f798 bhi 0x13f824 <_Z18F_ActionDrawHealthR6RValueP9CInstanceS2_iPS_+0x134>
 *   @0x13f79c ldr r3, [pc, #0x104]
 *   @0x13f7a0 add r3, pc, r3
 *   @0x13f7a4 add r3, r3, r6, lsl #2
 *   @0x13f7a8 ldr r12, [r3, #0x3c]
 *   @0x13f7ac ldr r2, [r3, #0x84]
 *   @0x13f7b0 ldr r3, [r3, #0xcc]
 *   @0x13f7b4 ldr r1, [pc, #0xf0]
 *   @0x13f7b8 cmp r6, #2
 *   @0x13f7bc movge r3, r12
 *   @0x13f7c0 movge r2, r12
 *   @0x13f7c4 ldr r1, [r5, r1]
 *   @0x13f7c8 ldrb lr, [r1]
 *   @0x13f7cc cmp lr, #0
 *   @0x13f7d0 bne 0x13f834 <_Z18F_ActionDrawHealthR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x13f7d4 ldr r7, [pc, #0xd4]
 *   @0x13f7d8 mov r6, #1
 *   @0x13f7dc vmov r0, s19
 *   @0x13f7e0 vmov r1, s18
 *   @0x13f7e4 ldr r5, [r5, r7]
 *   @0x13f7e8 vldr d7, [r5]
 *   @0x13f7ec vcvt.f32.f64 s14, d7
 *   @0x13f7f0 str r2, [sp, #0xc]
 *   @0x13f7f4 str r3, [sp, #0x10]
 *   @0x13f7f8 stmib sp, {r8, r12}
 *   @0x13f7fc str lr, [sp, #0x14]
 *   @0x13f800 str r4, [sp, #0x18]
 *   @0x13f804 str r6, [sp, #0x1c]
 *   @0x13f808 vmov r2, s17
 *   @0x13f80c vstr s14, [sp]
 *   @0x13f810 vmov r3, s16
 *   @0x13f814 bl 0x16c0d8 <_Z17GR_Draw_Healthbarfffffjjjjibb>
 *   @0x13f818 add sp, sp, #32
 *   @0x13f81c vpop {d8, d9}
 *   @0x13f820 pop {r4, r5, r6, r7, r8, pc}
 *   @0x13f824 mov r3, #0
 *   @0x13f828 mov r2, r3
 *   @0x13f82c mov r12, r3
 *   @0x13f830 b 0x13f7b4 <_Z18F_ActionDrawHealthR6RValueP9CInstanceS2_iPS_+0xc4>
 *   @0x13f834 vldr s12, [r7, #180]
 *   @0x13f838 vldr s13, [r7, #184]
 *   @0x13f83c vadd.f32 s19, s19, s12
 *   @0x13f840 ldr r6, [pc, #0x68]
 *   @0x13f844 mov lr, #0
 *   @0x13f848 mov r1, #1
 *   @0x13f84c ldr r5, [r5, r6]
 *   @0x13f850 vldr d7, [r5]
 *   @0x13f854 str r2, [sp, #0xc]
 *   @0x13f858 str r3, [sp, #0x10]
 *   @0x13f85c str r1, [sp, #0x1c]
 *   @0x13f860 stmib sp, {r8, r12}
 *   @0x13f864 str r4, [sp, #0x18]
 *   @0x13f868 str lr, [sp, #0x14]
 *   @0x13f86c vadd.f32 s12, s17, s12
 *   @0x13f870 vmov r0, s19
 *   @0x13f874 vadd.f32 s18, s18, s13
 *   @0x13f878 vmov r2, s12
 *   @0x13f87c vadd.f32 s13, s16, s13
 *   @0x13f880 vmov r1, s18
 *   @0x13f884 vcvt.f32.f64 s14, d7
 *   @0x13f888 vmov r3, s13
 *   @0x13f88c vstr s14, [sp]
 *   @0x13f890 bl 0x16c0d8 <_Z17GR_Draw_Healthbarfffffjjjjibb>
 *   @0x13f894 add sp, sp, #32
 *   @0x13f898 vpop {d8, d9}
 *   @0x13f89c pop {r4, r5, r6, r7, r8, pc}
 *   @0x13f8a0 eoreq r2, r11, r0, asr #10
 *   @0x13f8a4 eoreq sp, r1, r8, lsl r2
 *   @0x13f8a8 eoreq sp, r1, r4, lsl #4
 *   @0x13f8ac .word 0xffffbeec
 *   @0x13f8b0 .word 0xffffd788
 *
 * ══ §54/66 F_ActionIf(RValue&, CInstance*, CInstance*, int, RValue*)  0x1434a4  size 452  113 条（0x1434a4..0x143668）
 * @func 0x1434a4 0x143668  size 452  113 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / operator delete(void*)×2 / GetContextStackTop() / _RefThing<char const*>::dec() / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0x8×6 / 0xc×5 / 0x4×4 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1434a4 ldr r2, [r0, #0xc]
 *   @0x1434a8 push {r3, r4, r5, r6, r7, lr}
 *   @0x1434ac bic r3, r2, #-16777216
 *   @0x1434b0 cmp r3, #1
 *   @0x1434b4 mov r4, r0
 *   @0x1434b8 ldr r5, [sp, #0x18]
 *   @0x1434bc beq 0x14356c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xc8>
 *   @0x1434c0 cmp r3, #2
 *   @0x1434c4 bne 0x1434ec <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1434c8 sub r2, r2, #1
 *   @0x1434cc bic r2, r2, #-16777216
 *   @0x1434d0 bic r2, r2, #3
 *   @0x1434d4 cmp r2, #0
 *   @0x1434d8 beq 0x143660 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x1434dc mov r2, #0
 *   @0x1434e0 mov r3, #5
 *   @0x1434e4 str r2, [r4, #0x8]
 *   @0x1434e8 str r3, [r4, #0xc]
 *   @0x1434ec ldr r3, [r5, #0xc]
 *   @0x1434f0 mov r1, #0
 *   @0x1434f4 ldr r2, [r5, #0x8]
 *   @0x1434f8 str r1, [r4]
 *   @0x1434fc str r3, [r4, #0xc]
 *   @0x143500 ldr r3, [r5, #0xc]
 *   @0x143504 str r2, [r4, #0x8]
 *   @0x143508 bic r3, r3, #-16777216
 *   @0x14350c cmp r3, #14
 *   @0x143510 addls pc, pc, r3, lsl #2
 *   @0x143514 b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x143518 b 0x143560 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x14351c b 0x1435c4 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x143520 b 0x1435dc <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x138>
 *   @0x143524 b 0x143554 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x143528 b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x14352c b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x143530 b 0x1435a0 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xfc>
 *   @0x143534 b 0x143554 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x143538 b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x14353c b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x143540 b 0x143560 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x143544 b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x143548 b 0x14355c <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x14354c b 0x143560 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xbc>
 *   @0x143550 b 0x143554 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb0>
 *   @0x143554 ldr r3, [r5]
 *   @0x143558 str r3, [r4]
 *   @0x14355c pop {r3, r4, r5, r6, r7, pc}
 *   @0x143560 ldm r5, {r2, r3}
 *   @0x143564 stm r4, {r2, r3}
 *   @0x143568 pop {r3, r4, r5, r6, r7, pc}
 *   @0x14356c ldr r6, [r0]
 *   @0x143570 cmp r6, #0
 *   @0x143574 beq 0x143594 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x143578 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x14357c ldr r7, [r6, #0x4]
 *   @0x143580 sub r7, r7, #1
 *   @0x143584 str r7, [r6, #0x4]
 *   @0x143588 cmp r7, #0
 *   @0x14358c beq 0x143608 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x143590 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x143594 mov r3, #0
 *   @0x143598 str r3, [r4]
 *   @0x14359c b 0x1434ec <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x1435a0 ldr r3, [r5]
 *   @0x1435a4 str r3, [r4]
 *   @0x1435a8 ldr r3, [r5]
 *   @0x1435ac cmp r3, #0
 *   @0x1435b0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1435b4 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1435b8 ldr r1, [r5]
 *   @0x1435bc pop {r3, r4, r5, r6, r7, lr}
 *   @0x1435c0 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1435c4 ldr r3, [r5]
 *   @0x1435c8 cmp r3, #0
 *   @0x1435cc ldrne r2, [r3, #0x4]
 *   @0x1435d0 addne r2, r2, #1
 *   @0x1435d4 strne r2, [r3, #0x4]
 *   @0x1435d8 b 0x143558 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xb4>
 *   @0x1435dc ldr r3, [r5]
 *   @0x1435e0 cmp r3, #0
 *   @0x1435e4 str r3, [r4]
 *   @0x1435e8 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x1435ec ldr r1, [r3, #0x8]
 *   @0x1435f0 ldr r2, [r3]
 *   @0x1435f4 cmp r1, #0
 *   @0x1435f8 streq r4, [r3, #0x8]
 *   @0x1435fc add r2, r2, #1
 *   @0x143600 str r2, [r3]
 *   @0x143604 pop {r3, r4, r5, r6, r7, pc}
 *   @0x143608 ldr r0, [r6]
 *   @0x14360c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x143610 str r7, [r6]
 *   @0x143614 str r7, [r6, #0x8]
 *   @0x143618 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x14361c ldr r7, [r6, #0x4]
 *   @0x143620 sub r7, r7, #1
 *   @0x143624 str r7, [r6, #0x4]
 *   @0x143628 cmp r7, #0
 *   @0x14362c bne 0x143650 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x143630 ldr r0, [r6]
 *   @0x143634 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x143638 mov r0, r6
 *   @0x14363c str r7, [r6]
 *   @0x143640 str r7, [r6, #0x8]
 *   @0x143644 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x143648 mov r0, r6
 *   @0x14364c bl 0x27d1d0 <_ZdlPv>
 *   @0x143650 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x143654 mov r0, r6
 *   @0x143658 bl 0x27d1d0 <_ZdlPv>
 *   @0x14365c b 0x143590 <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0xec>
 *   @0x143660 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x143664 b 0x1434dc <_Z10F_ActionIfR6RValueP9CInstanceS2_iPS_+0x38>
 *
 * ══ §55/66 CInstance::Compute_Speed1()  0x1928d8  size 452  110 条（0x1928d8..0x192a9c）
 * @func 0x1928d8 0x192a9c  size 452  110 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66e8×4 / CInstance::Compute_Speed1()+0x164 / 0xb6790 / 0xb6778 / 0xb6700
 * 字段偏移 top8: 0xcc×1 / 0x64×1 / 0xe4×1
 * VFP 指令 72 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1928d8 vldr s15, [r0, #224]
 *   @0x1928dc vcmp.f32 s15, #0
 *   @0x1928e0 push {r4, lr}
 *   @0x1928e4 vpush {d8}
 *   @0x1928e8 mov r4, r0
 *   @0x1928ec vldr s16, [pc, #396]
 *   @0x1928f0 vmrs APSR_nzcv, fpscr
 *   @0x1928f4 bne 0x1929f4 <_ZN9CInstance14Compute_Speed1Ev+0x11c>
 *   @0x1928f8 vldr s15, [r0, #228]
 *   @0x1928fc vcmpe.f32 s15, s16
 *   @0x192900 vmrs APSR_nzcv, fpscr
 *   @0x192904 ble 0x192a3c <_ZN9CInstance14Compute_Speed1Ev+0x164>
 *   @0x192908 vldr s16, [pc, #372]
 *   @0x19290c vldr d7, [pc, #340]
 *   @0x192910 vstr s16, [r0, #204]
 *   @0x192914 vmov r0, r1, d7
 *   @0x192918 bl 0xb66e8 <lrint@plt>
 *   @0x19291c vldr s15, [pc, #356]
 *   @0x192920 vmov s13, r0
 *   @0x192924 vcvt.f32.s32 s14, s13
 *   @0x192928 vsub.f32 s16, s16, s14
 *   @0x19292c vabs.f32 s16, s16
 *   @0x192930 vcmpe.f32 s16, s15
 *   @0x192934 vldr s15, [r4, #204]
 *   @0x192938 vmrs APSR_nzcv, fpscr
 *   @0x19293c bmi 0x1929d8 <_ZN9CInstance14Compute_Speed1Ev+0x100>
 *   @0x192940 vmov r0, s15
 *   @0x192944 mov r1, #0
 *   @0x192948 movt r1, #0x43b4
 *   @0x19294c bl 0xb6790 <fmodf@plt>
 *   @0x192950 vldr s15, [r4, #228]
 *   @0x192954 vmul.f32 s15, s15, s15
 *   @0x192958 vldr s14, [r4, #224]
 *   @0x19295c vmla.f32 s15, s14, s14
 *   @0x192960 str r0, [r4, #0xcc]
 *   @0x192964 vsqrt.f32 s16, s15
 *   @0x192968 vcmp.f32 s16, s16
 *   @0x19296c vmrs APSR_nzcv, fpscr
 *   @0x192970 bne 0x192a54 <_ZN9CInstance14Compute_Speed1Ev+0x17c>
 *   @0x192974 vcvt.f64.f32 d7, s16
 *   @0x192978 vstr s16, [r4, #208]
 *   @0x19297c vmov r0, r1, d7
 *   @0x192980 bl 0xb66e8 <lrint@plt>
 *   @0x192984 vldr s15, [pc, #252]
 *   @0x192988 vmov s12, r0
 *   @0x19298c vcvt.f32.s32 s14, s12
 *   @0x192990 vsub.f32 s16, s16, s14
 *   @0x192994 vabs.f32 s16, s16
 *   @0x192998 vcmpe.f32 s16, s15
 *   @0x19299c vmrs APSR_nzcv, fpscr
 *   @0x1929a0 bpl 0x1929c0 <_ZN9CInstance14Compute_Speed1Ev+0xe8>
 *   @0x1929a4 vldr s15, [r4, #208]
 *   @0x1929a8 vcvt.f64.f32 d6, s15
 *   @0x1929ac vmov r0, r1, d6
 *   @0x1929b0 bl 0xb66e8 <lrint@plt>
 *   @0x1929b4 vmov s13, r0
 *   @0x1929b8 vcvt.f32.s32 s15, s13
 *   @0x1929bc vstr s15, [r4, #208]
 *   @0x1929c0 vpop {d8}
 *   @0x1929c4 mov r3, #1
 *   @0x1929c8 mov r0, r4
 *   @0x1929cc strb r3, [r4, #0x64]
 *   @0x1929d0 pop {r4, lr}
 *   @0x1929d4 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance>
 *   @0x1929d8 vcvt.f64.f32 d6, s15
 *   @0x1929dc vmov r0, r1, d6
 *   @0x1929e0 bl 0xb66e8 <lrint@plt>
 *   @0x1929e4 vmov s13, r0
 *   @0x1929e8 vcvt.f32.s32 s15, s13
 *   @0x1929ec vstr s15, [r4, #204]
 *   @0x1929f0 b 0x192940 <_ZN9CInstance14Compute_Speed1Ev+0x68>
 *   @0x1929f4 vmov r1, s15
 *   @0x1929f8 vldr s16, [pc, #140]
 *   @0x1929fc ldr r0, [r0, #0xe4]
 *   @0x192a00 bl 0xb6778 <atan2f@plt>
 *   @0x192a04 vldr s15, [pc, #132]
 *   @0x192a08 vmov s12, r0
 *   @0x192a0c vmul.f32 s16, s12, s16
 *   @0x192a10 vdiv.f32 s16, s16, s15
 *   @0x192a14 vcmpe.f32 s16, #0
 *   @0x192a18 vmrs APSR_nzcv, fpscr
 *   @0x192a1c vldrhi s15, [pc, #112]
 *   @0x192a20 vsubhi.f32 s16, s15, s16
 *   @0x192a24 vnegls.f32 s16, s16
 *   @0x192a28 vstrhi s16, [r4, #204]
 *   @0x192a2c vstrls s16, [r4, #204]
 *   @0x192a30 vcvtls.f64.f32 d7, s16
 *   @0x192a34 vcvthi.f64.f32 d7, s16
 *   @0x192a38 b 0x192914 <_ZN9CInstance14Compute_Speed1Ev+0x3c>
 *   @0x192a3c vldrmi s16, [pc, #84]
 *   @0x192a40 vldrmi d7, [pc, #40]
 *   @0x192a44 vstrmi s16, [r0, #204]
 *   @0x192a48 vstrpl s16, [r0, #204]
 *   @0x192a4c vldrpl d7, [pc, #36]
 *   @0x192a50 b 0x192914 <_ZN9CInstance14Compute_Speed1Ev+0x3c>
 *   @0x192a54 vmov r0, s15
 *   @0x192a58 bl 0xb6700 <sqrtf@plt>
 *   @0x192a5c vmov s16, r0
 *   @0x192a60 b 0x192974 <_ZN9CInstance14Compute_Speed1Ev+0x9c>
 *   @0x192a64 nop
 *   @0x192a68 andeq r0, r0, r0
 *   @0x192a6c rsbsmi lr, r0, r0
 *   @0x192a70 andeq r0, r0, r0
 *   @0x192a74 subsmi r8, r6, r0
 *   @0x192a84 orrmi r0, r7, #0
 *   @0x192a88 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0x192a8c teqmi r4, #0
 *   @0x192a90 ldrdmi r0, r1, [r9], #-251
 *   @0x192a94 .word 0x43b40000
 *   @0x192a98 adcsmi r0, r4, #0
 *
 * ══ §56/66 GetStreamInfo(cAudio_Sound*)  0x223eb0  size 452  113 条（0x223eb0..0x224074）
 * @func 0x223eb0 0x224074  size 452  113 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: SOggChannel::~SOggChannel()×2 / SOggChannel::SOggChannel() / anon_223cb4+0x74 / ov_info / ov_pcm_total / __floatdisf / anon_223cb4 / anon_223cb4+0x15c
 * 字段偏移 top8: 0x30×3 / 0x704×2 / 0x8×2 / 0x38×2 / 0x1a8×1 / 0x24×1 / 0x2bc×1 / 0x2c0×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x223eb0 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x223eb4 sub sp, sp, #1792
 *   @0x223eb8 ldr r8, [pc, #0x1a8]
 *   @0x223ebc sub sp, sp, #12
 *   @0x223ec0 mov r7, r0
 *   @0x223ec4 ldr r8, [pc, r8]
 *   @0x223ec8 mov r0, sp
 *   @0x223ecc ldr r3, [r8]
 *   @0x223ed0 str r3, [sp, #0x704]
 *   @0x223ed4 bl 0x2233f4 <_ZN11SOggChannelC2Ev>
 *   @0x223ed8 ldrb r1, [r7, #0x24]
 *   @0x223edc mov r3, #0
 *   @0x223ee0 str r7, [sp, #0x2bc]
 *   @0x223ee4 cmp r1, r3
 *   @0x223ee8 str r3, [sp, #0x2c0]
 *   @0x223eec beq 0x223fa8 <_Z13GetStreamInfoP12cAudio_Sound+0xf8>
 *   @0x223ef0 ldr r4, [r7, #0x30]
 *   @0x223ef4 cmp r4, #0
 *   @0x223ef8 beq 0x223fcc <_Z13GetStreamInfoP12cAudio_Sound+0x11c>
 *   @0x223efc mov r2, #0
 *   @0x223f00 mov r0, r4
 *   @0x223f04 mov r1, sp
 *   @0x223f08 bl 0x223d28 <_ZN10COggThread8LogErrorEPKcz+0x110>
 *   @0x223f0c subs r2, r0, #0
 *   @0x223f10 beq 0x223fbc <_Z13GetStreamInfoP12cAudio_Sound+0x10c>
 *   @0x223f14 mvn r1, #0
 *   @0x223f18 mov r0, sp
 *   @0x223f1c bl 0x232e28 <ov_info>
 *   @0x223f20 mvn r1, #0
 *   @0x223f24 mov r9, r0
 *   @0x223f28 mov r0, sp
 *   @0x223f2c bl 0x23138c <ov_pcm_total>
 *   @0x223f30 mvn r2, #130
 *   @0x223f34 mvn r3, #0
 *   @0x223f38 mov r4, r0
 *   @0x223f3c mov r5, r1
 *   @0x223f40 cmp r5, r3
 *   @0x223f44 cmpeq r4, r2
 *   @0x223f48 beq 0x224020 <_Z13GetStreamInfoP12cAudio_Sound+0x170>
 *   @0x223f4c bl 0x319398 <__floatdisf>
 *   @0x223f50 ldr r3, [r9, #0x8]
 *   @0x223f54 vmov s14, r3
 *   @0x223f58 vcvt.f32.s32 s15, s14
 *   @0x223f5c vmov s14, r0
 *   @0x223f60 vdiv.f32 s15, s14, s15
 *   @0x223f64 ldr r1, [sp, #0x2c4]
 *   @0x223f68 vstr s15, [r7, #52]
 *   @0x223f6c ldr r2, [r9, #0x4]
 *   @0x223f70 cmp r1, #0
 *   @0x223f74 str r3, [r7, #0x38]
 *   @0x223f78 strd r4, r5, [r7, #64]
 *   @0x223f7c str r2, [r7, #0x3c]
 *   @0x223f80 bne 0x224014 <_Z13GetStreamInfoP12cAudio_Sound+0x164>
 *   @0x223f84 mov r0, sp
 *   @0x223f88 bl 0x2234d0 <_ZN11SOggChannelD2Ev>
 *   @0x223f8c ldr r2, [sp, #0x704]
 *   @0x223f90 ldr r3, [r8]
 *   @0x223f94 cmp r2, r3
 *   @0x223f98 bne 0x224060 <_Z13GetStreamInfoP12cAudio_Sound+0x1b0>
 *   @0x223f9c add sp, sp, #1792
 *   @0x223fa0 add sp, sp, #12
 *   @0x223fa4 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x223fa8 mov r0, sp
 *   @0x223fac bl 0x223cb4 <_ZN10COggThread8LogErrorEPKcz+0x9c>
 *   @0x223fb0 cmp r0, #0
 *   @0x223fb4 beq 0x223f84 <_Z13GetStreamInfoP12cAudio_Sound+0xd4>
 *   @0x223fb8 b 0x223f14 <_Z13GetStreamInfoP12cAudio_Sound+0x64>
 *   @0x223fbc mov r0, r4
 *   @0x223fc0 mov r1, sp
 *   @0x223fc4 bl 0x223e10 <_ZN10COggThread8LogErrorEPKcz+0x1f8>
 *   @0x223fc8 b 0x223fb0 <_Z13GetStreamInfoP12cAudio_Sound+0x100>
 *   @0x223fcc add r4, sp, #772
 *   @0x223fd0 mov r1, #1024
 *   @0x223fd4 ldr r2, [r7]
 *   @0x223fd8 mov r0, r4
 *   @0x223fdc bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x223fe0 mov r0, r4
 *   @0x223fe4 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x223fe8 cmp r0, #0
 *   @0x223fec beq 0x22402c <_Z13GetStreamInfoP12cAudio_Sound+0x17c>
 *   @0x223ff0 ldr r0, [r7, #0x30]
 *   @0x223ff4 cmp r0, #0
 *   @0x223ff8 beq 0x224000 <_Z13GetStreamInfoP12cAudio_Sound+0x150>
 *   @0x223ffc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x224000 mov r0, r4
 *   @0x224004 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x224008 mov r4, r0
 *   @0x22400c str r0, [r7, #0x30]
 *   @0x224010 b 0x223efc <_Z13GetStreamInfoP12cAudio_Sound+0x4c>
 *   @0x224014 mov r0, sp
 *   @0x224018 bl 0x2236d4 <_Z8ogg_readPvjjS_+0x48>
 *   @0x22401c b 0x223f84 <_Z13GetStreamInfoP12cAudio_Sound+0xd4>
 *   @0x224020 ldr r3, [r9, #0x8]
 *   @0x224024 vldr s15, [pc, #56]
 *   @0x224028 b 0x223f64 <_Z13GetStreamInfoP12cAudio_Sound+0xb4>
 *   @0x22402c ldr r0, [pc, #0x38]
 *   @0x224030 mov r3, r4
 *   @0x224034 ldr r1, [pc, #0x34]
 *   @0x224038 ldr r0, [pc, r0]
 *   @0x22403c ldr r2, [r7]
 *   @0x224040 add r1, pc, r1
 *   @0x224044 ldr r0, [r0]
 *   @0x224048 ldr r12, [r0]
 *   @0x22404c ldr r12, [r12, #0xc]
 *   @0x224050 blx r12
 *   @0x224054 mov r0, sp
 *   @0x224058 bl 0x2234d0 <_ZN11SOggChannelD2Ev>
 *   @0x22405c b 0x223f8c <_Z13GetStreamInfoP12cAudio_Sound+0xdc>
 *   @0x224060 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x224064 andeq r0, r0, r0
 *   @0x224068 andseq r9, r12, r12, lsl #21
 *   @0x22406c ldrsbeq r9, [r12], -r12
 *   @0x224070 andseq r0, r3, r12, ror sp
 *
 * ══ §57/66 spSkeletonData_dispose  0x28adf8  size 452  113 条（0x28adf8..0x28afbc）
 * @func 0x28adf8 0x28afbc  size 452  113 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _free×10 / spSkeletonData_dispose+0x34 / spBoneData_dispose / spSkeletonData_dispose+0x68 / spSlotData_dispose / spSkeletonData_dispose+0x9c / spSkin_dispose / spSkeletonData_dispose+0xd0
 * 字段偏移 top8: 0x2×8 / 0x10×2 / 0x14×2 / 0x18×2 / 0x1c×2 / 0x20×2 / 0x24×2 / 0x2c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x28adf8 push {r3, r4, r5, lr}
 *   @0x28adfc mov r4, r0
 *   @0x28ae00 ldr r3, [r0, #0x10]
 *   @0x28ae04 cmp r3, #0
 *   @0x28ae08 movgt r5, #0
 *   @0x28ae0c ble 0x28ae2c <spSkeletonData_dispose+0x34>
 *   @0x28ae10 ldr r3, [r4, #0x14]
 *   @0x28ae14 ldr r0, [r3, r5, lsl #2]
 *   @0x28ae18 add r5, r5, #1
 *   @0x28ae1c bl 0x285ac4 <spBoneData_dispose>
 *   @0x28ae20 ldr r3, [r4, #0x10]
 *   @0x28ae24 cmp r3, r5
 *   @0x28ae28 bgt 0x28ae10 <spSkeletonData_dispose+0x18>
 *   @0x28ae2c ldr r0, [r4, #0x14]
 *   @0x28ae30 bl 0x285c80 <_free>
 *   @0x28ae34 ldr r3, [r4, #0x18]
 *   @0x28ae38 cmp r3, #0
 *   @0x28ae3c movgt r5, #0
 *   @0x28ae40 ble 0x28ae60 <spSkeletonData_dispose+0x68>
 *   @0x28ae44 ldr r3, [r4, #0x1c]
 *   @0x28ae48 ldr r0, [r3, r5, lsl #2]
 *   @0x28ae4c add r5, r5, #1
 *   @0x28ae50 bl 0x28efa8 <spSlotData_dispose>
 *   @0x28ae54 ldr r3, [r4, #0x18]
 *   @0x28ae58 cmp r3, r5
 *   @0x28ae5c bgt 0x28ae44 <spSkeletonData_dispose+0x4c>
 *   @0x28ae60 ldr r0, [r4, #0x1c]
 *   @0x28ae64 bl 0x285c80 <_free>
 *   @0x28ae68 ldr r3, [r4, #0x20]
 *   @0x28ae6c cmp r3, #0
 *   @0x28ae70 movgt r5, #0
 *   @0x28ae74 ble 0x28ae94 <spSkeletonData_dispose+0x9c>
 *   @0x28ae78 ldr r3, [r4, #0x24]
 *   @0x28ae7c ldr r0, [r3, r5, lsl #2]
 *   @0x28ae80 add r5, r5, #1
 *   @0x28ae84 bl 0x28ec9c <spSkin_dispose>
 *   @0x28ae88 ldr r3, [r4, #0x20]
 *   @0x28ae8c cmp r3, r5
 *   @0x28ae90 bgt 0x28ae78 <spSkeletonData_dispose+0x80>
 *   @0x28ae94 ldr r0, [r4, #0x24]
 *   @0x28ae98 bl 0x285c80 <_free>
 *   @0x28ae9c ldr r3, [r4, #0x2c]
 *   @0x28aea0 cmp r3, #0
 *   @0x28aea4 movgt r5, #0
 *   @0x28aea8 ble 0x28aec8 <spSkeletonData_dispose+0xd0>
 *   @0x28aeac ldr r3, [r4, #0x30]
 *   @0x28aeb0 ldr r0, [r3, r5, lsl #2]
 *   @0x28aeb4 add r5, r5, #1
 *   @0x28aeb8 bl 0x285bec <spEventData_dispose>
 *   @0x28aebc ldr r3, [r4, #0x2c]
 *   @0x28aec0 cmp r3, r5
 *   @0x28aec4 bgt 0x28aeac <spSkeletonData_dispose+0xb4>
 *   @0x28aec8 ldr r0, [r4, #0x30]
 *   @0x28aecc bl 0x285c80 <_free>
 *   @0x28aed0 ldr r3, [r4, #0x34]
 *   @0x28aed4 cmp r3, #0
 *   @0x28aed8 movgt r5, #0
 *   @0x28aedc ble 0x28aefc <spSkeletonData_dispose+0x104>
 *   @0x28aee0 ldr r3, [r4, #0x38]
 *   @0x28aee4 ldr r0, [r3, r5, lsl #2]
 *   @0x28aee8 add r5, r5, #1
 *   @0x28aeec bl 0x28147c <spAnimation_dispose>
 *   @0x28aef0 ldr r3, [r4, #0x34]
 *   @0x28aef4 cmp r3, r5
 *   @0x28aef8 bgt 0x28aee0 <spSkeletonData_dispose+0xe8>
 *   @0x28aefc ldr r0, [r4, #0x38]
 *   @0x28af00 bl 0x285c80 <_free>
 *   @0x28af04 ldr r3, [r4, #0x3c]
 *   @0x28af08 cmp r3, #0
 *   @0x28af0c movgt r5, #0
 *   @0x28af10 ble 0x28af30 <spSkeletonData_dispose+0x138>
 *   @0x28af14 ldr r3, [r4, #0x40]
 *   @0x28af18 ldr r0, [r3, r5, lsl #2]
 *   @0x28af1c add r5, r5, #1
 *   @0x28af20 bl 0x286758 <spIkConstraintData_dispose>
 *   @0x28af24 ldr r3, [r4, #0x3c]
 *   @0x28af28 cmp r3, r5
 *   @0x28af2c bgt 0x28af14 <spSkeletonData_dispose+0x11c>
 *   @0x28af30 ldr r0, [r4, #0x40]
 *   @0x28af34 bl 0x285c80 <_free>
 *   @0x28af38 ldr r3, [r4, #0x44]
 *   @0x28af3c cmp r3, #0
 *   @0x28af40 movgt r5, #0
 *   @0x28af44 ble 0x28af64 <spSkeletonData_dispose+0x16c>
 *   @0x28af48 ldr r3, [r4, #0x48]
 *   @0x28af4c ldr r0, [r3, r5, lsl #2]
 *   @0x28af50 add r5, r5, #1
 *   @0x28af54 bl 0x28f608 <spTransformConstraintData_dispose>
 *   @0x28af58 ldr r3, [r4, #0x44]
 *   @0x28af5c cmp r3, r5
 *   @0x28af60 bgt 0x28af48 <spSkeletonData_dispose+0x150>
 *   @0x28af64 ldr r0, [r4, #0x48]
 *   @0x28af68 bl 0x285c80 <_free>
 *   @0x28af6c ldr r3, [r4, #0x4c]
 *   @0x28af70 cmp r3, #0
 *   @0x28af74 movgt r5, #0
 *   @0x28af78 ble 0x28af98 <spSkeletonData_dispose+0x1a0>
 *   @0x28af7c ldr r3, [r4, #0x50]
 *   @0x28af80 ldr r0, [r3, r5, lsl #2]
 *   @0x28af84 add r5, r5, #1
 *   @0x28af88 bl 0x288f34 <spPathConstraintData_dispose>
 *   @0x28af8c ldr r3, [r4, #0x4c]
 *   @0x28af90 cmp r3, r5
 *   @0x28af94 bgt 0x28af7c <spSkeletonData_dispose+0x184>
 *   @0x28af98 ldr r0, [r4, #0x50]
 *   @0x28af9c bl 0x285c80 <_free>
 *   @0x28afa0 ldr r0, [r4, #0x4]
 *   @0x28afa4 bl 0x285c80 <_free>
 *   @0x28afa8 ldr r0, [r4]
 *   @0x28afac bl 0x285c80 <_free>
 *   @0x28afb0 mov r0, r4
 *   @0x28afb4 pop {r3, r4, r5, lr}
 *   @0x28afb8 b 0x285c80 <_free>
 *
 * ══ §58/66 Font_Load(unsigned char*, unsigned int, unsigned char*)  0xfa0d4  size 448  112 条（0xfa0d4..0xfa294）
 * @func 0xfa0d4 0xfa294  size 448  112 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xfa0ec→0x483680, 0xfa110→0x483688, 0xfa13c→0x483684, 0xfa15c→0x48367c, 0xfa18c→0x544c44
 * 调用序列: MemoryManager::SetLength(void**, unsigned int, char const*, int)×2 / operator new(unsigned int) / CFontGM::CFontGM() / CFontGM::LoadFromChunk(YYFont*, unsigned char*) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65a4 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x4×7 / 0xc×2 / 0x164×2 / 0x14×2 / 0x10×2 / 0x2×2 / 0x188×1 / 0x184×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xfa0d4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xfa0d8 mov r7, r0
 *   @0xfa0dc ldr r3, [r7]
 *   @0xfa0e0 sub sp, sp, #28
 *   @0xfa0e4 ldr r11, [pc, #0x188]
 *   @0xfa0e8 mov r6, r1
 *   @0xfa0ec ldr r0, [pc, #0x184]
 *   @0xfa0f0 sub r6, r6, #512
 *   @0xfa0f4 add r11, pc, r11
 *   @0xfa0f8 str r3, [sp, #0x4]
 *   @0xfa0fc str r2, [sp, #0xc]
 *   @0xfa100 mov r3, #98
 *   @0xfa104 ldr r1, [r11, r0]
 *   @0xfa108 add r6, r7, r6
 *   @0xfa10c ldr r0, [sp, #0x4]
 *   @0xfa110 ldr r2, [pc, #0x164]
 *   @0xfa114 ldr r4, [pc, #0x164]
 *   @0xfa118 str r0, [r1]
 *   @0xfa11c lsl r5, r0, #2
 *   @0xfa120 ldr r10, [r11, r2]
 *   @0xfa124 add r4, pc, r4
 *   @0xfa128 mov r1, r5
 *   @0xfa12c mov r2, r4
 *   @0xfa130 add r0, r10, #4
 *   @0xfa134 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xfa138 ldr r2, [sp, #0x4]
 *   @0xfa13c ldr r0, [pc, #0x140]
 *   @0xfa140 mov r3, #100
 *   @0xfa144 mov r1, r5
 *   @0xfa148 str r2, [r10]
 *   @0xfa14c mov r2, r4
 *   @0xfa150 ldr r8, [r11, r0]
 *   @0xfa154 mov r0, r8
 *   @0xfa158 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0xfa15c ldr r3, [pc, #0x124]
 *   @0xfa160 ldr r0, [sp, #0x4]
 *   @0xfa164 ldr r3, [r11, r3]
 *   @0xfa168 cmp r0, #0
 *   @0xfa16c str r6, [r3]
 *   @0xfa170 beq 0xfa260 <_Z9Font_LoadPhjS_+0x18c>
 *   @0xfa174 ldr r2, [pc, #0x110]
 *   @0xfa178 mov r4, #0
 *   @0xfa17c str r11, [sp, #0x14]
 *   @0xfa180 add r2, pc, r2
 *   @0xfa184 str r2, [sp, #0x10]
 *   @0xfa188 b 0xfa24c <_Z9Font_LoadPhjS_+0x178>
 *   @0xfa18c ldr r3, [pc, #0xfc]
 *   @0xfa190 ldr r0, [sp, #0x14]
 *   @0xfa194 ldr r3, [r0, r3]
 *   @0xfa198 ldr r11, [r3]
 *   @0xfa19c str r3, [sp, #0x8]
 *   @0xfa1a0 adds r9, r11, r6
 *   @0xfa1a4 beq 0xfa26c <_Z9Font_LoadPhjS_+0x198>
 *   @0xfa1a8 mov r0, #144
 *   @0xfa1ac bl 0x27c524 <_Znwj>
 *   @0xfa1b0 mov r5, r0
 *   @0xfa1b4 bl 0xf71c8 <_ZN7CFontGMC2Ev>
 *   @0xfa1b8 mov r1, r9
 *   @0xfa1bc ldr r2, [sp, #0xc]
 *   @0xfa1c0 mov r0, r5
 *   @0xfa1c4 bl 0xf7bc4 <_ZN7CFontGM13LoadFromChunkEP6YYFontPh>
 *   @0xfa1c8 ldr r12, [r11, r6]
 *   @0xfa1cc cmp r12, #0
 *   @0xfa1d0 ldrne r2, [sp, #0x8]
 *   @0xfa1d4 moveq r9, r12
 *   @0xfa1d8 ldrne r3, [r2]
 *   @0xfa1dc addne r9, r3, r12
 *   @0xfa1e0 mov r0, r9
 *   @0xfa1e4 bl 0xb6538 <strlen@plt>
 *   @0xfa1e8 ldr r1, [sp, #0x10]
 *   @0xfa1ec mov r3, #1
 *   @0xfa1f0 mov r2, #114
 *   @0xfa1f4 add r0, r0, r3
 *   @0xfa1f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xfa1fc mov r1, r9
 *   @0xfa200 mov r6, r0
 *   @0xfa204 bl 0xb65a4 <strcpy@plt>
 *   @0xfa208 ldr r2, [r8]
 *   @0xfa20c lsl r9, r4, #2
 *   @0xfa210 ldr r0, [r2, r4, lsl #2]
 *   @0xfa214 cmp r0, #0
 *   @0xfa218 beq 0xfa22c <_Z9Font_LoadPhjS_+0x158>
 *   @0xfa21c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xfa220 ldr r2, [r8]
 *   @0xfa224 mov r3, #0
 *   @0xfa228 str r3, [r2, r4, lsl #2]
 *   @0xfa22c ldr r2, [r10, #0x4]
 *   @0xfa230 add r4, r4, #1
 *   @0xfa234 ldr r0, [sp, #0x4]
 *   @0xfa238 str r5, [r2, r9]
 *   @0xfa23c cmp r4, r0
 *   @0xfa240 ldr r2, [r8]
 *   @0xfa244 str r6, [r2, r9]
 *   @0xfa248 beq 0xfa260 <_Z9Font_LoadPhjS_+0x18c>
 *   @0xfa24c ldr r6, [r7, #0x4]!
 *   @0xfa250 cmp r6, #0
 *   @0xfa254 bne 0xfa18c <_Z9Font_LoadPhjS_+0xb8>
 *   @0xfa258 mov r5, r6
 *   @0xfa25c b 0xfa208 <_Z9Font_LoadPhjS_+0x134>
 *   @0xfa260 mov r0, #1
 *   @0xfa264 add sp, sp, #28
 *   @0xfa268 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xfa26c mov r6, r9
 *   @0xfa270 b 0xfa258 <_Z9Font_LoadPhjS_+0x184>
 *   @0xfa274 eoreq r7, pc, r12, asr r11
 *   @0xfa278 .word 0xffffc210
 *   @0xfa27c .word 0xffffc20c
 *   @0xfa280 eoreq sp, r3, r8, lsr r10
 *   @0xfa284 .word 0xffffc214
 *   @0xfa288 .word 0xffffc218
 *   @0xfa28c .word 0x0023d9dc
 *   @0xfa290 .word 0xffffbcf4
 *
 * ══ §59/66 F_BackgroundFlushMulti(RValue&, CInstance*, CInstance*, int, RValue*)  0x12fbb0  size 448  112 条（0x12fbb0..0x12fd70）
 * @func 0x12fbb0 0x12fd70  size 448  112 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x12fc10→0x3eb70c, 0x12fc34→0x3eb70c, 0x12fc98→0x3eb70c, 0x12fcd0→0x48ffec, 0x12fd30→0x3eb70c
 * 调用序列: F_BackgroundFlushMulti(RValue&, CInstance*, CInstance*, int, RValue*)+0x170×2 / Graphics::FlushTexture(void*)×2 / Graphics::Flush() / YYGetInt32(RValue const*, int) / Background_Data(int) / CBackground::GetTexture() / F_BackgroundFlushMulti(RValue&, CInstance*, CInstance*, int, RValue*)+0x154
 * 字段偏移 top8: 0x4×8 / 0xc×6 / 0x144×2 / 0x108×2 / 0x2×2 / 0x20×1 / 0x184×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x12fbb0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x12fbb4 mov r4, #0
 *   @0x12fbb8 ldr r2, [sp, #0x20]
 *   @0x12fbbc mov r3, r4
 *   @0x12fbc0 str r4, [r0, #0xc]
 *   @0x12fbc4 movt r3, #0xbff0
 *   @0x12fbc8 ldr r6, [pc, #0x184]
 *   @0x12fbcc mov r5, r0
 *   @0x12fbd0 ldr r1, [r2, #0xc]
 *   @0x12fbd4 add r6, pc, r6
 *   @0x12fbd8 str r4, [r0]
 *   @0x12fbdc cmp r1, #2
 *   @0x12fbe0 str r3, [r0, #0x4]
 *   @0x12fbe4 bne 0x12fc30 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x12fbe8 ldr r7, [r2]
 *   @0x12fbec cmp r7, #0
 *   @0x12fbf0 beq 0x12fc0c <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x12fbf4 ldr r3, [r7, #0x4]
 *   @0x12fbf8 cmp r3, #0
 *   @0x12fbfc beq 0x12fc0c <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x5c>
 *   @0x12fc00 ldr r3, [r7, #0x10]
 *   @0x12fc04 cmp r3, #1
 *   @0x12fc08 beq 0x12fc40 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x12fc0c ldr r1, [pc, #0x144]
 *   @0x12fc10 ldr r3, [pc, #0x144]
 *   @0x12fc14 add r1, pc, r1
 *   @0x12fc18 ldr r3, [r6, r3]
 *   @0x12fc1c ldr r0, [r3]
 *   @0x12fc20 ldr r3, [r0]
 *   @0x12fc24 ldr r3, [r3, #0xc]
 *   @0x12fc28 blx r3
 *   @0x12fc2c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x12fc30 ldr r1, [pc, #0x128]
 *   @0x12fc34 ldr r3, [pc, #0x120]
 *   @0x12fc38 add r1, pc, r1
 *   @0x12fc3c b 0x12fc18 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0x12fc40 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x12fc44 ldr r3, [r7, #0x4]
 *   @0x12fc48 ldr r2, [r3]
 *   @0x12fc4c cmp r2, #0
 *   @0x12fc50 ble 0x12fd20 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x12fc54 ldr r8, [pc, #0x108]
 *   @0x12fc58 ldr r9, [pc, #0x108]
 *   @0x12fc5c add r8, pc, r8
 *   @0x12fc60 add r9, pc, r9
 *   @0x12fc64 b 0x12fc90 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0xe0>
 *   @0x12fc68 ldr r3, [r6, r12]
 *   @0x12fc6c ldr r0, [r3]
 *   @0x12fc70 ldr r3, [r0]
 *   @0x12fc74 ldr r3, [r3, #0xc]
 *   @0x12fc78 blx r3
 *   @0x12fc7c ldr r3, [r7, #0x4]
 *   @0x12fc80 add r4, r4, #1
 *   @0x12fc84 ldr r2, [r3]
 *   @0x12fc88 cmp r2, r4
 *   @0x12fc8c ble 0x12fd20 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x170>
 *   @0x12fc90 ldr r3, [r3, #0x4]
 *   @0x12fc94 mov r1, r9
 *   @0x12fc98 ldr r12, [pc, #0xbc]
 *   @0x12fc9c mov r2, r4
 *   @0x12fca0 add r3, r3, r4, lsl #4
 *   @0x12fca4 mov r0, r3
 *   @0x12fca8 ldr r3, [r3, #0xc]
 *   @0x12fcac cmp r3, #0
 *   @0x12fcb0 bne 0x12fc68 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x12fcb4 mov r1, r3
 *   @0x12fcb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x12fcbc mov r10, r0
 *   @0x12fcc0 bl 0xc3794 <_Z15Background_Datai>
 *   @0x12fcc4 cmp r0, #0
 *   @0x12fcc8 beq 0x12fd30 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x180>
 *   @0x12fccc bl 0xc1e8c <_ZN11CBackground10GetTextureEv>
 *   @0x12fcd0 ldr r3, [pc, #0x94]
 *   @0x12fcd4 ldr r3, [r6, r3]
 *   @0x12fcd8 ldr r2, [r3]
 *   @0x12fcdc cmp r0, r2
 *   @0x12fce0 bls 0x12fd04 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x12fce4 cmn r0, #1
 *   @0x12fce8 beq 0x12fd04 <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x12fcec ldrsh r2, [r0, #20]
 *   @0x12fcf0 ldr r3, [r3, #0x4]
 *   @0x12fcf4 ldr r3, [r3, r2, lsl #2]
 *   @0x12fcf8 ldr r0, [r3]
 *   @0x12fcfc bl 0x1811bc <_ZN8Graphics12FlushTextureEPv>
 *   @0x12fd00 b 0x12fc7c <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x12fd04 ldr r3, [r3, #0x4]
 *   @0x12fd08 ldr r3, [r3, r0, lsl #2]
 *   @0x12fd0c cmp r3, #0
 *   @0x12fd10 beq 0x12fc7c <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x12fd14 ldr r0, [r3]
 *   @0x12fd18 bl 0x1811bc <_ZN8Graphics12FlushTextureEPv>
 *   @0x12fd1c b 0x12fc7c <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x12fd20 mov r3, #0
 *   @0x12fd24 str r3, [r5]
 *   @0x12fd28 str r3, [r5, #0x4]
 *   @0x12fd2c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x12fd30 ldr r3, [pc, #0x24]
 *   @0x12fd34 mov r2, r10
 *   @0x12fd38 mov r1, r8
 *   @0x12fd3c ldr r3, [r6, r3]
 *   @0x12fd40 ldr r0, [r3]
 *   @0x12fd44 ldr r3, [r0]
 *   @0x12fd48 ldr r3, [r3, #0xc]
 *   @0x12fd4c blx r3
 *   @0x12fd50 b 0x12fc7c <_Z22F_BackgroundFlushMultiR6RValueP9CInstanceS2_iPS_+0xcc>
 *   @0x12fd54 eoreq r2, r12, r12, ror r0
 *   @0x12fd58 .word 0x0020defc
 *   @0x12fd5c .word 0xffffbac4
 *   @0x12fd60 mlaeq r0, r0, lr, sp
 *   @0x12fd64 eoreq sp, r0, r0, lsr #30
 *   @0x12fd68 eoreq sp, r0, r4, ror #29
 *   @0x12fd6c .word 0xffffbccc
 *
 * ══ §60/66 F_D3DLightDefinePoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x1471a4  size 448  112 条（0x1471a4..0x147364）
 * @func 0x1471a4 0x147364  size 448  112 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x147258→0x4849c4, 0x147294→0x484944, 0x1472a0→0x4848c4, 0x1472ec→0x484884
 * 调用序列: YYGetFloat(RValue const*, int)×4 / YYGetInt32(RValue const*, int)×2 / GR_3D_Light_Define_Point(int, float, float, float, float, unsigned int) / 0xfe167554
 * 字段偏移 top8: 0xc×3 / 0x194×1 / 0x38×1 / 0xf0×1 / 0xb8×1 / 0xb0×1 / 0x68×1 / 0x4×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1471a4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1471a8 sub sp, sp, #20
 *   @0x1471ac mov r1, #0
 *   @0x1471b0 ldr r5, [pc, #0x194]
 *   @0x1471b4 ldr r6, [sp, #0x38]
 *   @0x1471b8 add r5, pc, r5
 *   @0x1471bc mov r0, r6
 *   @0x1471c0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1471c4 cmp r0, #7
 *   @0x1471c8 mov r4, r0
 *   @0x1471cc bhi 0x147330 <_Z21F_D3DLightDefinePointR6RValueP9CInstanceS2_iPS_+0x18c>
 *   @0x1471d0 mov r0, r6
 *   @0x1471d4 mov r1, #1
 *   @0x1471d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1471dc mov r1, #2
 *   @0x1471e0 mov r10, r0
 *   @0x1471e4 mov r0, r6
 *   @0x1471e8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1471ec mov r1, #3
 *   @0x1471f0 mov r11, r0
 *   @0x1471f4 mov r0, r6
 *   @0x1471f8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1471fc mov r1, #4
 *   @0x147200 mov r7, r0
 *   @0x147204 mov r0, r6
 *   @0x147208 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14720c mov r1, #5
 *   @0x147210 str r0, [sp, #0xc]
 *   @0x147214 mov r0, r6
 *   @0x147218 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14721c lsl lr, r4, #2
 *   @0x147220 lsl r2, r4, #4
 *   @0x147224 add r9, lr, #1
 *   @0x147228 add r8, lr, #2
 *   @0x14722c add lr, lr, #3
 *   @0x147230 lsl r9, r9, #2
 *   @0x147234 vldr s15, [pc, #268]
 *   @0x147238 lsl r8, r8, #2
 *   @0x14723c lsl lr, lr, #2
 *   @0x147240 orr r12, r0, #-16777216
 *   @0x147244 uxtb r0, r0
 *   @0x147248 ubfx r3, r12, #0x8, #0x8
 *   @0x14724c ubfx r6, r12, #0x10, #0x8
 *   @0x147250 vmov s12, r0
 *   @0x147254 vmov s14, r3
 *   @0x147258 ldr r3, [pc, #0xf0]
 *   @0x14725c vmov s13, r6
 *   @0x147260 vcvt.f32.s32 s12, s12
 *   @0x147264 ldr r1, [r5, r3]
 *   @0x147268 mov r3, #0
 *   @0x14726c add r0, r1, r2
 *   @0x147270 str r3, [r0]
 *   @0x147274 add r0, r1, r9
 *   @0x147278 str r3, [r0]
 *   @0x14727c add r0, r1, r8
 *   @0x147280 add r1, r1, lr
 *   @0x147284 vcvt.f32.s32 s13, s13
 *   @0x147288 str r3, [r0]
 *   @0x14728c mov r0, r4
 *   @0x147290 str r3, [r1]
 *   @0x147294 ldr r3, [pc, #0xb8]
 *   @0x147298 ldr r1, [r5, r3]
 *   @0x14729c vcvt.f32.s32 s14, s14
 *   @0x1472a0 ldr r3, [pc, #0xb0]
 *   @0x1472a4 add r6, r1, r2
 *   @0x1472a8 str r10, [r6]
 *   @0x1472ac add r6, r1, r9
 *   @0x1472b0 str r11, [r6]
 *   @0x1472b4 add r6, r1, r8
 *   @0x1472b8 add r1, r1, lr
 *   @0x1472bc vmul.f32 s12, s12, s15
 *   @0x1472c0 str r7, [r6]
 *   @0x1472c4 ldr r6, [sp, #0xc]
 *   @0x1472c8 str r6, [r1]
 *   @0x1472cc mov r1, r10
 *   @0x1472d0 ldr r3, [r5, r3]
 *   @0x1472d4 mov r6, #1
 *   @0x1472d8 add r10, r3, r2
 *   @0x1472dc add r9, r3, r9
 *   @0x1472e0 add r8, r3, r8
 *   @0x1472e4 add lr, r3, lr
 *   @0x1472e8 mov r3, r7
 *   @0x1472ec ldr r7, [pc, #0x68]
 *   @0x1472f0 mov r2, r11
 *   @0x1472f4 vmul.f32 s14, s14, s15
 *   @0x1472f8 vstr s12, [r10]
 *   @0x1472fc vmul.f32 s15, s13, s15
 *   @0x147300 vstr s14, [r9]
 *   @0x147304 mov r9, #1065353216
 *   @0x147308 vstr s15, [r8]
 *   @0x14730c str r9, [lr]
 *   @0x147310 ldr lr, [r5, r7]
 *   @0x147314 ldr r5, [sp, #0xc]
 *   @0x147318 str r12, [sp, #0x4]
 *   @0x14731c str r5, [sp]
 *   @0x147320 str r6, [lr, r4, lsl #2]
 *   @0x147324 bl 0x17f7e8 <_Z24GR_3D_Light_Define_Pointiffffj>
 *   @0x147328 add sp, sp, #20
 *   @0x14732c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x147330 ldr r0, [pc, #0x28]
 *   @0x147334 mov r1, #0
 *   @0x147338 add r0, pc, r0
 *   @0x14733c add sp, sp, #20
 *   @0x147340 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x147344 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x147348 bllo 0xfe167554 <b2_toiTime+0xfffffffffda0e0b0>
 *   @0x14734c mlaeq r10, r8, r10, r10
 *   @0x147350 .word 0xffffd9dc
 *   @0x147354 .word 0xffffd9d0
 *   @0x147358 .word 0xffffd9d8
 *   @0x14735c .word 0xffffd9cc
 *   @0x147360 andseq r10, pc, r8, asr #13
 *
 * ══ §61/66 GR_Draw_Triangle_Ext(float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, bool)  0x16a85c  size 448  112 条（0x16a85c..0x16aa1c）
 * @func 0x16a85c 0x16aa1c  size 448  112 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16a870→0x3f23d8, 0x16a87c→0x3f23d4, 0x16a8c4→0x4859c0, 0x16a8f8→0x4859ac, 0x16a8fc→0x3f23cc, 0x16a988→0x4859ac, 0x16a98c→0x3f23cc
 * 调用序列: GR_Color_To_D3DColor(unsigned int, unsigned int)×5 / Graphics::AllocVerts(ePrimType, void*, int, int)×2
 * 字段偏移 top8: 0x114×2 / 0x8×2 / 0x20×2 / 0x38×2 / 0xc×2 / 0x84×2 / 0x194×1 / 0x190×1
 * VFP 指令 32 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16a85c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x16a860 vldr s13, [pc, #408]
 *   @0x16a864 vpush {d8, d9, d10}
 *   @0x16a868 ldr r5, [pc, #0x194]
 *   @0x16a86c vldr s19, [sp, #56]
 *   @0x16a870 ldr r4, [pc, #0x190]
 *   @0x16a874 vldr s18, [sp, #60]
 *   @0x16a878 add r5, pc, r5
 *   @0x16a87c ldr lr, [pc, #0x188]
 *   @0x16a880 ldrb r12, [sp, #0x4c]
 *   @0x16a884 ldr r4, [r5, r4]
 *   @0x16a888 vldr s14, [r4]
 *   @0x16a88c vmul.f32 s14, s14, s13
 *   @0x16a890 ldr lr, [r5, lr]
 *   @0x16a894 vldr s15, [lr]
 *   @0x16a898 cmp r12, #0
 *   @0x16a89c ldr r8, [sp, #0x40]
 *   @0x16a8a0 ldr r7, [sp, #0x44]
 *   @0x16a8a4 ldr r6, [sp, #0x48]
 *   @0x16a8a8 vmul.f32 s15, s15, s13
 *   @0x16a8ac vmov s13, r0
 *   @0x16a8b0 vadd.f32 s17, s14, s13
 *   @0x16a8b4 vmov s13, r2
 *   @0x16a8b8 vadd.f32 s19, s14, s19
 *   @0x16a8bc vadd.f32 s21, s14, s13
 *   @0x16a8c0 vmov s14, r1
 *   @0x16a8c4 ldr r1, [pc, #0x144]
 *   @0x16a8c8 vmov s13, r3
 *   @0x16a8cc vadd.f32 s16, s15, s14
 *   @0x16a8d0 vadd.f32 s20, s15, s13
 *   @0x16a8d4 vadd.f32 s18, s15, s18
 *   @0x16a8d8 bne 0x16a96c <_Z20GR_Draw_Triangle_Extffffffjjjb+0x110>
 *   @0x16a8dc ldr r1, [r5, r1]
 *   @0x16a8e0 mov r2, #24
 *   @0x16a8e4 mov r3, #3
 *   @0x16a8e8 mov r0, #4
 *   @0x16a8ec ldr r1, [r1]
 *   @0x16a8f0 ldr r1, [r1]
 *   @0x16a8f4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16a8f8 ldr r3, [pc, #0x114]
 *   @0x16a8fc ldr r2, [pc, #0x114]
 *   @0x16a900 vstr s17, [r0]
 *   @0x16a904 vstr s16, [r0, #4]
 *   @0x16a908 ldr r3, [r5, r3]
 *   @0x16a90c mov r4, r0
 *   @0x16a910 mov r0, r8
 *   @0x16a914 ldr r3, [r3]
 *   @0x16a918 str r3, [r4, #0x8]
 *   @0x16a91c str r3, [r4, #0x20]
 *   @0x16a920 str r3, [r4, #0x38]
 *   @0x16a924 ldr r5, [r5, r2]
 *   @0x16a928 ldr r1, [r5]
 *   @0x16a92c bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16a930 ldr r1, [r5]
 *   @0x16a934 vstr s21, [r4, #24]
 *   @0x16a938 vstr s20, [r4, #28]
 *   @0x16a93c str r0, [r4, #0xc]
 *   @0x16a940 mov r0, r7
 *   @0x16a944 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16a948 ldr r1, [r5]
 *   @0x16a94c vstr s19, [r4, #48]
 *   @0x16a950 vstr s18, [r4, #52]
 *   @0x16a954 str r0, [r4, #0x24]
 *   @0x16a958 mov r0, r6
 *   @0x16a95c bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16a960 vpop {d8, d9, d10}
 *   @0x16a964 str r0, [r4, #0x3c]
 *   @0x16a968 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x16a96c ldr r1, [r5, r1]
 *   @0x16a970 mov r2, #24
 *   @0x16a974 mov r3, #4
 *   @0x16a978 mov r0, #3
 *   @0x16a97c ldr r1, [r1]
 *   @0x16a980 ldr r1, [r1]
 *   @0x16a984 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16a988 ldr r3, [pc, #0x84]
 *   @0x16a98c ldr r2, [pc, #0x84]
 *   @0x16a990 vstr s17, [r0]
 *   @0x16a994 vstr s17, [r0, #72]
 *   @0x16a998 vstr s16, [r0, #4]
 *   @0x16a99c vstr s16, [r0, #76]
 *   @0x16a9a0 ldr r9, [r5, r3]
 *   @0x16a9a4 mov r4, r0
 *   @0x16a9a8 ldr r3, [r9]
 *   @0x16a9ac str r3, [r0, #0x8]
 *   @0x16a9b0 str r3, [r0, #0x50]
 *   @0x16a9b4 mov r0, r8
 *   @0x16a9b8 ldr r5, [r5, r2]
 *   @0x16a9bc ldr r1, [r5]
 *   @0x16a9c0 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16a9c4 ldr r1, [r5]
 *   @0x16a9c8 vstr s21, [r4, #24]
 *   @0x16a9cc vstr s20, [r4, #28]
 *   @0x16a9d0 mov r3, r0
 *   @0x16a9d4 str r3, [r4, #0x54]
 *   @0x16a9d8 ldr r3, [r9]
 *   @0x16a9dc str r0, [r4, #0xc]
 *   @0x16a9e0 mov r0, r7
 *   @0x16a9e4 str r3, [r4, #0x20]
 *   @0x16a9e8 bl 0x16ca94 <_Z20GR_Color_To_D3DColorjj>
 *   @0x16a9ec ldr r3, [r9]
 *   @0x16a9f0 ldr r1, [r5]
 *   @0x16a9f4 vstr s19, [r4, #48]
 *   @0x16a9f8 str r3, [r4, #0x38]
 *   @0x16a9fc b 0x16a950 <_Z20GR_Draw_Triangle_Extffffffjjjb+0xf4>
 *   @0x16aa00 stclo p7, c13, [r3], #-40
 *   @0x16aa04 .word 0x002873d8
 *   @0x16aa08 .word 0xffffe524
 *   @0x16aa0c .word 0xffffe520
 *   @0x16aa10 .word 0xffffe4e0
 *   @0x16aa14 .word 0xffffbcd0
 *   @0x16aa18 .word 0xffffc0b0
 *
 * ══ §62/66 GenerateShaderVariation(int, char*, char*, char*, bool)  0x1839b0  size 448  112 条（0x1839b0..0x183b70）
 * @func 0x1839b0 0x183b70  size 448  112 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6538×5 / 0xb6628×3 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65a4 / 0xb6550 / 0xb65d4
 * 字段偏移 top8: 0x4×5 / 0x4c×2 / 0x8×2 / 0xc×2 / 0x10×2 / 0x198×1 / 0x78×1 / 0x12c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1839b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1839b4 mov r7, r3
 *   @0x1839b8 ldr r5, [pc, #0x198]
 *   @0x1839bc sub sp, sp, #84
 *   @0x1839c0 mov r6, r0
 *   @0x1839c4 mov r0, r1
 *   @0x1839c8 ldr r5, [pc, r5]
 *   @0x1839cc mov r10, r1
 *   @0x1839d0 mov r8, r2
 *   @0x1839d4 ldrb r9, [sp, #0x78]
 *   @0x1839d8 ldr r3, [r5]
 *   @0x1839dc ubfx r11, r6, #0x1, #0x1
 *   @0x1839e0 str r3, [sp, #0x4c]
 *   @0x1839e4 bl 0xb6538 <strlen@plt>
 *   @0x1839e8 ands r3, r6, #1
 *   @0x1839ec str r3, [sp, #0x4]
 *   @0x1839f0 moveq r4, r0
 *   @0x1839f4 addne r4, r0, #16
 *   @0x1839f8 cmp r11, #0
 *   @0x1839fc mov r0, r8
 *   @0x183a00 addne r4, r4, #22
 *   @0x183a04 cmp r9, #0
 *   @0x183a08 addne r4, r4, #24
 *   @0x183a0c bl 0xb6538 <strlen@plt>
 *   @0x183a10 mov r12, r0
 *   @0x183a14 mov r0, r7
 *   @0x183a18 str r12, [sp]
 *   @0x183a1c bl 0xb6538 <strlen@plt>
 *   @0x183a20 ldr r12, [sp]
 *   @0x183a24 mov r3, #1
 *   @0x183a28 ldr r1, [pc, #0x12c]
 *   @0x183a2c mov r2, #70
 *   @0x183a30 add r1, pc, r1
 *   @0x183a34 add r0, r0, r12
 *   @0x183a38 add r0, r0, r4
 *   @0x183a3c add r0, r0, r3
 *   @0x183a40 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x183a44 mov r1, r10
 *   @0x183a48 mov r4, r0
 *   @0x183a4c bl 0xb65a4 <strcpy@plt>
 *   @0x183a50 ldr r3, [sp, #0x4]
 *   @0x183a54 cmp r3, #0
 *   @0x183a58 bne 0x183b1c <_Z23GenerateShaderVariationiPcS_S_b+0x16c>
 *   @0x183a5c cmp r11, #0
 *   @0x183a60 bne 0x183ad4 <_Z23GenerateShaderVariationiPcS_S_b+0x124>
 *   @0x183a64 cmp r9, #0
 *   @0x183a68 beq 0x183aa0 <_Z23GenerateShaderVariationiPcS_S_b+0xf0>
 *   @0x183a6c ubfx r6, r6, #0x2, #0x2
 *   @0x183a70 mov r3, #1
 *   @0x183a74 lsl r3, r3, r6
 *   @0x183a78 ldr r1, [pc, #0xe0]
 *   @0x183a7c add r6, sp, #12
 *   @0x183a80 ldr r2, [pc, #0xdc]
 *   @0x183a84 add r1, pc, r1
 *   @0x183a88 mov r0, r6
 *   @0x183a8c add r2, pc, r2
 *   @0x183a90 bl 0xb6550 <sprintf@plt>
 *   @0x183a94 mov r0, r4
 *   @0x183a98 mov r1, r6
 *   @0x183a9c bl 0xb6628 <strcat@plt>
 *   @0x183aa0 mov r1, r8
 *   @0x183aa4 mov r0, r4
 *   @0x183aa8 bl 0xb6628 <strcat@plt>
 *   @0x183aac mov r0, r4
 *   @0x183ab0 mov r1, r7
 *   @0x183ab4 bl 0xb6628 <strcat@plt>
 *   @0x183ab8 ldr r2, [sp, #0x4c]
 *   @0x183abc ldr r3, [r5]
 *   @0x183ac0 mov r0, r4
 *   @0x183ac4 cmp r2, r3
 *   @0x183ac8 bne 0x183b54 <_Z23GenerateShaderVariationiPcS_S_b+0x1a4>
 *   @0x183acc add sp, sp, #84
 *   @0x183ad0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x183ad4 mov r0, r4
 *   @0x183ad8 bl 0xb6538 <strlen@plt>
 *   @0x183adc ldr r12, [pc, #0x84]
 *   @0x183ae0 add r12, pc, r12
 *   @0x183ae4 add lr, r4, r0
 *   @0x183ae8 mov r10, r0
 *   @0x183aec ldm r12!, {r0, r1, r2, r3}
 *   @0x183af0 str r0, [r4, r10]
 *   @0x183af4 ldrh r10, [r12, #4]
 *   @0x183af8 ldr r0, [r12]
 *   @0x183afc ldrb r12, [r12, #0x6]
 *   @0x183b00 str r1, [lr, #0x4]
 *   @0x183b04 str r2, [lr, #0x8]
 *   @0x183b08 str r3, [lr, #0xc]
 *   @0x183b0c str r0, [lr, #0x10]
 *   @0x183b10 strh r10, [lr, #20]
 *   @0x183b14 strb r12, [lr, #0x16]
 *   @0x183b18 b 0x183a64 <_Z23GenerateShaderVariationiPcS_S_b+0xb4>
 *   @0x183b1c mov r0, r4
 *   @0x183b20 bl 0xb6538 <strlen@plt>
 *   @0x183b24 ldr r12, [pc, #0x40]
 *   @0x183b28 add r12, pc, r12
 *   @0x183b2c add lr, r4, r0
 *   @0x183b30 mov r10, r0
 *   @0x183b34 ldm r12!, {r0, r1, r2, r3}
 *   @0x183b38 ldrb r12, [r12]
 *   @0x183b3c str r0, [r4, r10]
 *   @0x183b40 str r1, [lr, #0x4]
 *   @0x183b44 strb r12, [lr, #0x10]
 *   @0x183b48 str r2, [lr, #0x8]
 *   @0x183b4c str r3, [lr, #0xc]
 *   @0x183b50 b 0x183a5c <_Z23GenerateShaderVariationiPcS_S_b+0xac>
 *   @0x183b54 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x183b58 eoreq r9, r6, r8, lsl #31
 *   @0x183b5c andseq sp, r10, r0, lsl #12
 *   @0x183b60 andseq r8, r12, r4, asr #2
 *   @0x183b64 andseq r8, r12, r4, asr #2
 *   @0x183b68 ldrsbeq r8, [r12], -r0
 *   @0x183b6c andseq r8, r12, r4, ror r0
 *
 * ══ §63/66 GamepadInitM()  0x190014  size 448  112 条（0x190014..0x1901d4）
 * @func 0x190014 0x1901d4  size 448  112 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×7 / GMGamePad::SetGamePadCount(int) / operator new(unsigned int) / GMGamePad::GMGamePad(int, int)
 * 字段偏移 top8: 0x1c4×6 / 0x150×2 / 0x124×2 / 0x104×2 / 0xa4×2 / 0x178×1 / 0x14c×1 / 0x148×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x190014 push {r4, r5, r6, lr}
 *   @0x190018 ldr r4, [pc, #0x178]
 *   @0x19001c add r4, pc, r4
 *   @0x190020 ldr r3, [r4]
 *   @0x190024 tst r3, #1
 *   @0x190028 beq 0x190150 <_Z12GamepadInitMv+0x13c>
 *   @0x19002c tst r3, #2
 *   @0x190030 popne {r4, r5, r6, pc}
 *   @0x190034 bl 0x290274 <getJNIEnv>
 *   @0x190038 cmp r0, #0
 *   @0x19003c popeq {r4, r5, r6, pc}
 *   @0x190040 bl 0x290274 <getJNIEnv>
 *   @0x190044 ldr r5, [pc, #0x150]
 *   @0x190048 ldr r2, [pc, #0x150]
 *   @0x19004c ldr r5, [pc, r5]
 *   @0x190050 ldr r3, [pc, #0x14c]
 *   @0x190054 add r2, pc, r2
 *   @0x190058 ldr r4, [pc, #0x148]
 *   @0x19005c add r3, pc, r3
 *   @0x190060 ldr r1, [r5]
 *   @0x190064 add r4, pc, r4
 *   @0x190068 ldr r6, [pc, #0x13c]
 *   @0x19006c add r6, pc, r6
 *   @0x190070 ldr r12, [r0]
 *   @0x190074 ldr r12, [r12, #0x1c4]
 *   @0x190078 blx r12
 *   @0x19007c str r0, [r4, #0x4]
 *   @0x190080 bl 0x290274 <getJNIEnv>
 *   @0x190084 ldr r2, [pc, #0x124]
 *   @0x190088 ldr r3, [pc, #0x124]
 *   @0x19008c ldr r1, [r5]
 *   @0x190090 add r2, pc, r2
 *   @0x190094 add r3, pc, r3
 *   @0x190098 ldr r12, [r0]
 *   @0x19009c ldr r12, [r12, #0x1c4]
 *   @0x1900a0 blx r12
 *   @0x1900a4 str r0, [r4, #0x8]
 *   @0x1900a8 bl 0x290274 <getJNIEnv>
 *   @0x1900ac ldr r2, [pc, #0x104]
 *   @0x1900b0 ldr r3, [pc, #0x104]
 *   @0x1900b4 ldr r1, [r5]
 *   @0x1900b8 add r2, pc, r2
 *   @0x1900bc add r3, pc, r3
 *   @0x1900c0 ldr r12, [r0]
 *   @0x1900c4 ldr r12, [r12, #0x1c4]
 *   @0x1900c8 blx r12
 *   @0x1900cc str r0, [r4, #0xc]
 *   @0x1900d0 bl 0x290274 <getJNIEnv>
 *   @0x1900d4 ldr r2, [pc, #0xe4]
 *   @0x1900d8 mov r3, r6
 *   @0x1900dc ldr r1, [r5]
 *   @0x1900e0 add r2, pc, r2
 *   @0x1900e4 ldr r12, [r0]
 *   @0x1900e8 ldr r12, [r12, #0x1c4]
 *   @0x1900ec blx r12
 *   @0x1900f0 str r0, [r4, #0x10]
 *   @0x1900f4 bl 0x290274 <getJNIEnv>
 *   @0x1900f8 ldr r2, [pc, #0xc4]
 *   @0x1900fc mov r3, r6
 *   @0x190100 ldr r1, [r5]
 *   @0x190104 add r2, pc, r2
 *   @0x190108 ldr r12, [r0]
 *   @0x19010c ldr r12, [r12, #0x1c4]
 *   @0x190110 blx r12
 *   @0x190114 str r0, [r4, #0x14]
 *   @0x190118 bl 0x290274 <getJNIEnv>
 *   @0x19011c ldr r2, [pc, #0xa4]
 *   @0x190120 ldr r3, [pc, #0xa4]
 *   @0x190124 ldr r1, [r5]
 *   @0x190128 add r2, pc, r2
 *   @0x19012c add r3, pc, r3
 *   @0x190130 ldr r12, [r0]
 *   @0x190134 ldr r12, [r12, #0x1c4]
 *   @0x190138 blx r12
 *   @0x19013c ldr r3, [r4]
 *   @0x190140 orr r3, r3, #2
 *   @0x190144 str r3, [r4]
 *   @0x190148 str r0, [r4, #0x18]
 *   @0x19014c pop {r4, r5, r6, pc}
 *   @0x190150 mov r0, #1
 *   @0x190154 orr r3, r3, r0
 *   @0x190158 str r3, [r4]
 *   @0x19015c bl 0x18e4a4 <_ZN9GMGamePad15SetGamePadCountEi>
 *   @0x190160 ldr r3, [pc, #0x68]
 *   @0x190164 mov r0, #556
 *   @0x190168 ldr r3, [pc, r3]
 *   @0x19016c ldr r5, [r3]
 *   @0x190170 bl 0x27c524 <_Znwj>
 *   @0x190174 mov r1, #8
 *   @0x190178 mov r2, #2
 *   @0x19017c mov r6, r0
 *   @0x190180 bl 0x18e9d4 <_ZN9GMGamePadC2Eii>
 *   @0x190184 ldr r3, [r4]
 *   @0x190188 str r6, [r5]
 *   @0x19018c tst r3, #2
 *   @0x190190 popne {r4, r5, r6, pc}
 *   @0x190194 b 0x190034 <_Z12GamepadInitMv+0x20>
 *   @0x190198 eorseq r5, r10, r12, lsl #16
 *   @0x19019c eoreq sp, r5, r8, asr r9
 *   @0x1901a0 mulseq r11, r4, r4
 *   @0x1901a4 mulseq r11, r12, r4
 *   @0x1901a8 eorseq r5, r10, r4, asr #15
 *   @0x1901ac andseq r12, r11, r12, ror #9
 *   @0x1901b0 andseq r12, r11, r12, ror #8
 *   @0x1901b4 andseq r12, r11, r12, ror r4
 *   @0x1901b8 andseq r12, r11, r0, ror #8
 *   @0x1901bc andseq r12, r11, r0, ror r4
 *   @0x1901c0 andseq r12, r11, r4, ror #8
 *   @0x1901c4 andseq r12, r11, r12, asr r4
 *   @0x1901c8 andseq r12, r11, r12, asr #8
 *   @0x1901cc andseq r12, r11, r12, asr r4
 *   @0x1901d0 .word 0x0025f8fc
 *
 * ══ §64/66 TimeLine_Delete(int)  0x1f2fb4  size 448  112 条（0x1f2fb4..0x1f3174）
 * @func 0x1f2fb4 0x1f3174  size 448  112 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×4 / TimeLine_Delete(int)+0x164 / operator delete(void*) / MemoryManager::IsAllocated(void const*) / TimeLine_Delete(int)+0x130 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×17 / 0x19c×1 / 0x2×1 / 0x118×1 / 0x38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f2fb4 push {r4, r5, r6, r7, lr}
 *   @0x1f2fb8 subs r4, r0, #0
 *   @0x1f2fbc sub sp, sp, #12
 *   @0x1f2fc0 blt 0x1f3118 <_Z15TimeLine_Deletei+0x164>
 *   @0x1f2fc4 ldr r3, [pc, #0x19c]
 *   @0x1f2fc8 ldr r5, [pc, r3]
 *   @0x1f2fcc ldr r3, [r5]
 *   @0x1f2fd0 cmp r4, r3
 *   @0x1f2fd4 bge 0x1f3118 <_Z15TimeLine_Deletei+0x164>
 *   @0x1f2fd8 ldr r3, [r5, #0x4]
 *   @0x1f2fdc lsl r6, r4, #2
 *   @0x1f2fe0 ldr r0, [r3, r4, lsl #2]
 *   @0x1f2fe4 cmp r0, #0
 *   @0x1f2fe8 beq 0x1f311c <_Z15TimeLine_Deletei+0x168>
 *   @0x1f2fec cmp r3, #0
 *   @0x1f2ff0 beq 0x1f304c <_Z15TimeLine_Deletei+0x98>
 *   @0x1f2ff4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f2ff8 ldr r3, [r5]
 *   @0x1f2ffc ldr r2, [r5, #0x4]
 *   @0x1f3000 mov r1, #0
 *   @0x1f3004 sub r3, r3, #2
 *   @0x1f3008 cmp r4, r3
 *   @0x1f300c str r1, [r2, r6]
 *   @0x1f3010 bge 0x1f3160 <_Z15TimeLine_Deletei+0x1ac>
 *   @0x1f3014 mov r1, r6
 *   @0x1f3018 mov r2, r4
 *   @0x1f301c ldr r12, [r5, #0x4]
 *   @0x1f3020 add r0, r1, #4
 *   @0x1f3024 add r2, r2, #1
 *   @0x1f3028 cmp r2, r3
 *   @0x1f302c ldr lr, [r12, r0]
 *   @0x1f3030 str lr, [r12, r1]
 *   @0x1f3034 mov r1, r0
 *   @0x1f3038 bne 0x1f301c <_Z15TimeLine_Deletei+0x68>
 *   @0x1f303c lsl r2, r2, #2
 *   @0x1f3040 ldr r3, [r5, #0x4]
 *   @0x1f3044 mov r1, #0
 *   @0x1f3048 str r1, [r3, r2]
 *   @0x1f304c ldr r7, [pc, #0x118]
 *   @0x1f3050 add r7, pc, r7
 *   @0x1f3054 ldr r5, [r7, #0x4]
 *   @0x1f3058 ldr r3, [r5, #0x4]
 *   @0x1f305c add r2, r3, r6
 *   @0x1f3060 ldr r0, [r3, r6]
 *   @0x1f3064 cmp r0, #0
 *   @0x1f3068 beq 0x1f307c <_Z15TimeLine_Deletei+0xc8>
 *   @0x1f306c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f3070 ldr r5, [r7, #0x4]
 *   @0x1f3074 ldr r2, [r5, #0x4]
 *   @0x1f3078 add r2, r2, r6
 *   @0x1f307c mov r3, #0
 *   @0x1f3080 str r3, [r2]
 *   @0x1f3084 ldr r3, [r5, #0x4]
 *   @0x1f3088 ldr r0, [r3, r6]
 *   @0x1f308c bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv>
 *   @0x1f3090 cmp r0, #0
 *   @0x1f3094 beq 0x1f30a4 <_Z15TimeLine_Deletei+0xf0>
 *   @0x1f3098 ldr r3, [r5, #0x4]
 *   @0x1f309c ldr r0, [r3, r6]
 *   @0x1f30a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f30a4 ldr r7, [r5]
 *   @0x1f30a8 mov r2, #0
 *   @0x1f30ac ldr r3, [r5, #0x4]
 *   @0x1f30b0 sub r12, r7, #2
 *   @0x1f30b4 cmp r12, r4
 *   @0x1f30b8 str r2, [r3, r6]
 *   @0x1f30bc movgt r3, r6
 *   @0x1f30c0 ble 0x1f30e4 <_Z15TimeLine_Deletei+0x130>
 *   @0x1f30c4 ldr r1, [r5, #0x4]
 *   @0x1f30c8 add r2, r3, #4
 *   @0x1f30cc add r4, r4, #1
 *   @0x1f30d0 cmp r4, r12
 *   @0x1f30d4 ldr r0, [r1, r2]
 *   @0x1f30d8 str r0, [r1, r3]
 *   @0x1f30dc mov r3, r2
 *   @0x1f30e0 bne 0x1f30c4 <_Z15TimeLine_Deletei+0x110>
 *   @0x1f30e4 cmp r7, #0
 *   @0x1f30e8 sub r3, r7, #1
 *   @0x1f30ec str r3, [r5]
 *   @0x1f30f0 bne 0x1f3124 <_Z15TimeLine_Deletei+0x170>
 *   @0x1f30f4 ldr r0, [r5, #0x4]
 *   @0x1f30f8 cmp r0, #0
 *   @0x1f30fc beq 0x1f3150 <_Z15TimeLine_Deletei+0x19c>
 *   @0x1f3100 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f3104 str r7, [r5, #0x4]
 *   @0x1f3108 mov r0, #1
 *   @0x1f310c str r7, [r5]
 *   @0x1f3110 add sp, sp, #12
 *   @0x1f3114 pop {r4, r5, r6, r7, pc}
 *   @0x1f3118 mov r0, #0
 *   @0x1f311c add sp, sp, #12
 *   @0x1f3120 pop {r4, r5, r6, r7, pc}
 *   @0x1f3124 lsls r1, r7, #2
 *   @0x1f3128 ldr r0, [r5, #0x4]
 *   @0x1f312c beq 0x1f3150 <_Z15TimeLine_Deletei+0x19c>
 *   @0x1f3130 ldr r2, [pc, #0x38]
 *   @0x1f3134 mov r3, #0
 *   @0x1f3138 str r3, [sp]
 *   @0x1f313c mov r3, #92
 *   @0x1f3140 add r2, pc, r2
 *   @0x1f3144 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1f3148 str r0, [r5, #0x4]
 *   @0x1f314c b 0x1f3108 <_Z15TimeLine_Deletei+0x154>
 *   @0x1f3150 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1f3154 mov r3, #0
 *   @0x1f3158 str r3, [r5, #0x4]
 *   @0x1f315c b 0x1f3108 <_Z15TimeLine_Deletei+0x154>
 *   @0x1f3160 mov r2, r6
 *   @0x1f3164 b 0x1f3040 <_Z15TimeLine_Deletei+0x8c>
 *   @0x1f3168 subseq r0, r6, r4, lsr #2
 *   @0x1f316c .word 0x0056009c
 *   @0x1f3170 ldrsbeq pc, [r5], -r12
 *
 * ══ §65/66 SoundHardware::Play(void*, bool)  0x220764  size 288  65 条（0x220764..0x220884）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x220764 0x220884  size 288  65 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x220774→0x755361, 0x220790→0x755363, 0x2207a4→0x755362, 0x2207b8→0x755360, 0x220834→0x3eb70c
 * 调用序列: CheckALError()×2 / 0xb6a78 / 0xb6a6c / 0xb6a84
 * 字段偏移 top8: 0x3c×3 / 0x14×2 / 0xf0×1 / 0xec×1 / 0xd4×1 / 0xc4×1 / 0xb4×1 / 0x4×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x220764 push {r3, r4, r5, r6, r7, lr}
 *   @0x220768 mov r7, r0
 *   @0x22076c ldr r4, [pc, #0xf0]
 *   @0x220770 mov r5, r1
 *   @0x220774 ldr r3, [pc, #0xec]
 *   @0x220778 mov r6, r2
 *   @0x22077c add r4, pc, r4
 *   @0x220780 ldr r3, [r4, r3]
 *   @0x220784 ldrb r3, [r3]
 *   @0x2207a4 ldr r3, [pc, #0xc4]
 *   @0x2207a8 ldr r3, [r4, r3]
 *   @0x2207ac ldrb r3, [r3]
 *   @0x2207b0 cmp r3, #0
 *   @0x2207b4 popne {r3, r4, r5, r6, r7, pc}
 *   @0x2207b8 ldr r3, [pc, #0xb4]
 *   @0x2207bc ldr r3, [r4, r3]
 *   @0x2207c0 ldrb r3, [r3]
 *   @0x2207c4 cmp r3, #0
 *   @0x2207c8 popne {r3, r4, r5, r6, r7, pc}
 *   @0x2207cc cmp r5, #0
 *   @0x2207d0 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x2207d4 vldr s14, [r5, #24]
 *   @0x2207d8 vldr s15, [r7]
 *   @0x2207dc vmul.f32 s15, s14, s15
 *   @0x2207e0 ldr r2, [r5, #0x14]
 *   @0x2207e4 add r1, r2, #1
 *   @0x2207e8 str r1, [r5, #0x14]
 *   @0x2207ec add r2, r5, r2, lsl #2
 *   @0x2207f0 cmp r1, #3
 *   @0x2207f4 movw r1, #0x100a
 *   @0x2207f8 ldr r4, [r2, #0x4]
 *   @0x2207fc strgt r3, [r5, #0x14]
 *   @0x220800 mov r0, r4
 *   @0x220804 vmov r2, s15
 *   @0x220808 bl 0xb6a78 <alSourcef@plt>
 *   @0x22080c bl 0x220198 <_Z12CheckALErrorv>
 *   @0x220810 mov r0, r4
 *   @0x220814 mov r2, r6
 *   @0x220818 movw r1, #0x1007
 *   @0x22081c bl 0xb6a6c <alSourcei@plt>
 *   @0x220820 bl 0x220198 <_Z12CheckALErrorv>
 *   @0x220824 mov r0, r4
 *   @0x220828 bl 0xb6a84 <alSourcePlay@plt>
 *   @0x22082c pop {r3, r4, r5, r6, r7, lr}
 *   @0x220830 b 0x220198 <_Z12CheckALErrorv>
 *   @0x220834 ldr r3, [pc, #0x3c]
 *   @0x220838 ldr r2, [pc, #0x3c]
 *   @0x22083c ldr r1, [pc, #0x3c]
 *   @0x220840 ldr r3, [r4, r3]
 *   @0x220844 add r2, pc, r2
 *   @0x220848 add r1, pc, r1
 *   @0x22084c add r2, r2, #76
 *   @0x220850 ldr r0, [r3]
 *   @0x220854 ldr r3, [r0]
 *   @0x220858 ldr r3, [r3, #0xc]
 *   @0x22085c blx r3
 *   @0x220860 b 0x220790 <_ZN13SoundHardware4PlayEPvb+0x2c>
 *   @0x220864 ldrsbeq r1, [sp], -r4
 *   @0x220868 .word 0xfffff7d8
 *   @0x22086c .word 0xffffd3fc
 *   @0x220870 .word 0xfffff7e0
 *   @0x220874 .word 0xfffff7e4
 *   @0x220878 .word 0xffffbac4
 *   @0x22087c andseq sp, r3, r4, lsl #15
 *   @0x220880 ldrsheq r3, [r3], -r4
 *
 * ══ §66/66 Background_Number()  0xc362c  size 20  5 条（0xc362c..0xc3640）
 * @func 0xc362c 0xc3640  size 20  5 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc362c ldr r3, [pc, #0x8]
 *   @0xc3630 ldr r3, [pc, r3]
 *   @0xc3634 ldr r0, [r3]
 *   @0xc3638 bx lr
 *   @0xc363c eorseq r10, r2, r8, lsl r3
 */
