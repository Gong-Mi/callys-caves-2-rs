/* libyoyo.so 覆盖卡组 0026
 * 函数 0xf954c..0xfb3c0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xf954c · CFontGM::CFont_Draw_String_Transformed_Color(void*, float, float, unsigned short*, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float) · size=28 · insn=7 */
/* @0xf954c cmp r0, #0 */
/* @0xf9550 push {r4, r5, r6, r7, r8, r9, r10} */
/* @0xf9554 beq 0xf9560 <_ZN7CFontGM35CFont_Draw_String_Transformed_ColorEPvffPtfffjjjjf+0x14> */
/* @0xf9558 pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0xf955c b 0xf8f58 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf> */
/* @0xf9560 pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0xf9564 bx lr */

/* ── FUNC 0xf9568 · CFontGM::CFont_TextWidth(void*, unsigned short*) · size=12 · insn=3 */
/* @0xf9568 cmp r0, #0 */
/* @0xf956c bxeq lr */
/* @0xf9570 b 0xf8b04 <_ZN7CFontGM9TextWidthEPt> */

/* ── FUNC 0xf9574 · CFontGM::CFont_TextHeight(void*, unsigned short*) · size=12 · insn=3 */
/* @0xf9574 cmp r0, #0 */
/* @0xf9578 bxeq lr */
/* @0xf957c b 0xf93a4 <_ZN7CFontGM10TextHeightEPt> */

/* ── FUNC 0xf9580 · FindFaceIndex(unsigned char*, int, long) · size=224 · insn=56 */
/* @0xf9580 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf9584 sub sp, sp, #20 */
/* @0xf9588 ldr r9, [pc, #0xcc] */
/* @0xf958c add r8, sp, #16 */
/* @0xf9590 mov r10, r0 */
/* @0xf9594 mov r11, r1 */
/* @0xf9598 ldr r9, [pc, r9] */
/* @0xf959c mov r4, #0 */
/* @0xf95a0 mov r7, r2 */
/* @0xf95a4 str r4, [r8, #-0x4]! */
/* @0xf95a8 ldr r0, [r9] */
/* @0xf95ac mov r1, r10 */
/* @0xf95b0 str r8, [sp] */
/* @0xf95b4 mov r2, r11 */
/* @0xf95b8 mov r3, r4 */
/* @0xf95bc blx 0x2e96f0 <FT_New_Memory_Face> */
/* @0xf95c0 subs r6, r0, #0 */
/* @0xf95c4 beq 0xf9654 <_Z13FindFaceIndexPhil+0xd4> */
/* @0xf95c8 ldr r3, [sp, #0xc] */
/* @0xf95cc ldr r5, [r3] */
/* @0xf95d0 b 0xf95f0 <_Z13FindFaceIndexPhil+0x70> */
/* @0xf95d4 rsbs r3, r6, #1 */
/* @0xf95d8 movlo r3, #0 */
/* @0xf95dc cmp r4, r5 */
/* @0xf95e0 movge r3, #0 */
/* @0xf95e4 cmp r3, #0 */
/* @0xf95e8 ldr r3, [sp, #0xc] */
/* @0xf95ec beq 0xf9634 <_Z13FindFaceIndexPhil+0xb4> */
/* @0xf95f0 ldr r2, [r3, #0xc] */
/* @0xf95f4 mov r0, r3 */
/* @0xf95f8 and r2, r2, #3 */
/* @0xf95fc cmp r2, r7 */
/* @0xf9600 beq 0xf9640 <_Z13FindFaceIndexPhil+0xc0> */
/* @0xf9604 add r4, r4, #1 */
/* @0xf9608 blx 0x2e8bdc <FT_Done_Face> */
/* @0xf960c cmp r5, r4 */
/* @0xf9610 ble 0xf95d4 <_Z13FindFaceIndexPhil+0x54> */
/* @0xf9614 ldr r0, [r9] */
/* @0xf9618 mov r1, r10 */
/* @0xf961c str r8, [sp] */
/* @0xf9620 mov r2, r11 */
/* @0xf9624 mov r3, r4 */
/* @0xf9628 blx 0x2e96f0 <FT_New_Memory_Face> */
/* @0xf962c mov r6, r0 */
/* @0xf9630 b 0xf95d4 <_Z13FindFaceIndexPhil+0x54> */
/* @0xf9634 cmp r3, #0 */
/* @0xf9638 mvn r4, #0 */
/* @0xf963c beq 0xf9648 <_Z13FindFaceIndexPhil+0xc8> */
/* @0xf9640 mov r0, r3 */
/* @0xf9644 blx 0x2e8bdc <FT_Done_Face> */
/* @0xf9648 mov r0, r4 */
/* @0xf964c add sp, sp, #20 */
/* @0xf9650 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf9654 mvn r4, #0 */
/* @0xf9658 b 0xf9648 <_Z13FindFaceIndexPhil+0xc8> */
/* @0xf965c .word 0x002f48b8 */

/* ── FUNC 0xf9660 · CFontGM::CreateIt() · size=1960 · insn=490 */
/* @0xf9660 ldr r12, [pc, #0x768] */
/* @0xf9664 mov r3, #0 */
/* @0xf9668 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf966c add r11, sp, #32 */
/* @0xf9670 ldr r2, [pc, #0x75c] */
/* @0xf9674 sub sp, sp, #596 */
/* @0xf9678 add r12, pc, r12 */
/* @0xf967c str r12, [r11, #-0x240] */
/* @0xf9680 mov r5, r0 */
/* @0xf9684 ldr r2, [r12, r2] */
/* @0xf9688 ldr r0, [r0, #0x4] */
/* @0xf968c str r3, [r5, #0x54] */
/* @0xf9690 ldr r3, [r2] */
/* @0xf9694 str r2, [r11, #-0x248] */
/* @0xf9698 str r3, [r11, #-0x28] */
/* @0xf969c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0xf96a0 cmp r0, #0 */
/* @0xf96a4 ldr r0, [r5, #0x4] */
/* @0xf96a8 beq 0xf9738 <_ZN7CFontGM8CreateItEv+0xd8> */
/* @0xf96ac add r1, r5, #88 */
/* @0xf96b0 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0xf96b4 mov r1, r0 */
/* @0xf96b8 str r0, [r5, #0x54] */
/* @0xf96bc ldr r12, [r11, #-0x240] */
/* @0xf96c0 mov r3, #0 */
/* @0xf96c4 ldr r0, [pc, #0x70c] */
/* @0xf96c8 ldr r2, [r5, #0x58] */
/* @0xf96cc ldr r0, [r12, r0] */
/* @0xf96d0 sub r12, r11, #568 */
/* @0xf96d4 str r12, [sp] */
/* @0xf96d8 ldr r0, [r0] */
/* @0xf96dc blx 0x2e96f0 <FT_New_Memory_Face> */
/* @0xf96e0 subs r1, r0, #0 */
/* @0xf96e4 beq 0xf975c <_ZN7CFontGM8CreateItEv+0xfc> */
/* @0xf96e8 mov r2, r1 */
/* @0xf96ec mov r3, r1 */
/* @0xf96f0 ldr r1, [pc, #0x6e4] */
/* @0xf96f4 ldr r0, [pc, #0x6e4] */
/* @0xf96f8 ldr lr, [r5, #0x4] */
/* @0xf96fc add r1, pc, r1 */
/* @0xf9700 ldr r12, [r11, #-0x240] */
/* @0xf9704 ldr r0, [r12, r0] */
/* @0xf9708 ldr r0, [r0] */
/* @0xf970c ldr r12, [r0] */
/* @0xf9710 str lr, [sp] */
/* @0xf9714 ldr r12, [r12, #0xc] */
/* @0xf9718 blx r12 */
/* @0xf971c ldr r12, [r11, #-0x248] */
/* @0xf9720 ldr r2, [r11, #-0x28] */
/* @0xf9724 ldr r3, [r12] */
/* @0xf9728 cmp r2, r3 */
/* @0xf972c bne 0xf9dcc <_ZN7CFontGM8CreateItEv+0x76c> */
/* @0xf9730 sub sp, r11, #32 */
/* @0xf9734 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf9738 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0xf973c cmp r0, #0 */
/* @0xf9740 beq 0xf97c0 <_ZN7CFontGM8CreateItEv+0x160> */
/* @0xf9744 add r1, r5, #88 */
/* @0xf9748 ldr r0, [r5, #0x4] */
/* @0xf974c bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0xf9750 mov r1, r0 */
/* @0xf9754 str r0, [r5, #0x54] */
/* @0xf9758 b 0xf96bc <_ZN7CFontGM8CreateItEv+0x5c> */
/* @0xf975c ldr r2, [r5, #0x8] */
/* @0xf9760 mov r3, #96 */
/* @0xf9764 ldr r0, [r11, #-0x238] */
/* @0xf9768 str r3, [sp] */
/* @0xf976c lsl r2, r2, #6 */
/* @0xf9770 blx 0x2e578c <FT_Set_Char_Size> */
/* @0xf9774 subs r2, r0, #0 */
/* @0xf9778 bne 0xf97ec <_ZN7CFontGM8CreateItEv+0x18c> */
/* @0xf977c movw r1, #0x6963 */
/* @0xf9780 ldr r0, [r11, #-0x238] */
/* @0xf9784 movt r1, #0x756e */
/* @0xf9788 blx 0x2e58f4 <FT_Select_Charmap> */
/* @0xf978c subs r2, r0, #0 */
/* @0xf9790 beq 0xf9804 <_ZN7CFontGM8CreateItEv+0x1a4> */
/* @0xf9794 ldr r12, [r11, #-0x240] */
/* @0xf9798 mov r3, r2 */
/* @0xf979c ldr r0, [pc, #0x63c] */
/* @0xf97a0 ldr r1, [pc, #0x63c] */
/* @0xf97a4 ldr r0, [r12, r0] */
/* @0xf97a8 add r1, pc, r1 */
/* @0xf97ac ldr r0, [r0] */
/* @0xf97b0 ldr r12, [r0] */
/* @0xf97b4 ldr r12, [r12, #0xc] */
/* @0xf97b8 blx r12 */
/* @0xf97bc b 0xf971c <_ZN7CFontGM8CreateItEv+0xbc> */
/* @0xf97c0 ldr r12, [r11, #-0x240] */
/* @0xf97c4 ldr r3, [pc, #0x614] */
/* @0xf97c8 ldr r1, [pc, #0x618] */
/* @0xf97cc ldr r2, [r5, #0x4] */
/* @0xf97d0 ldr r3, [r12, r3] */
/* @0xf97d4 add r1, pc, r1 */
/* @0xf97d8 ldr r0, [r3] */
/* @0xf97dc ldr r3, [r0] */
/* @0xf97e0 ldr r3, [r3, #0xc] */
/* @0xf97e4 blx r3 */
/* @0xf97e8 b 0xf971c <_ZN7CFontGM8CreateItEv+0xbc> */
/* @0xf97ec ldr r1, [pc, #0x5f8] */
/* @0xf97f0 mov r3, r2 */
/* @0xf97f4 ldr r0, [pc, #0x5e4] */
/* @0xf97f8 ldr lr, [r5, #0x8] */
/* @0xf97fc add r1, pc, r1 */
/* @0xf9800 b 0xf9700 <_ZN7CFontGM8CreateItEv+0xa0> */
/* @0xf9804 ldr r0, [r11, #-0x238] */
/* @0xf9808 sub r12, r11, #564 */
/* @0xf980c str r12, [r11, #-0x250] */
/* @0xf9810 mov r1, r12 */
/* @0xf9814 ldr r3, [r0, #0x58] */
/* @0xf9818 ldr r3, [r3, #0x18] */
/* @0xf981c str r3, [r11, #-0x258] */
/* @0xf9820 blx 0x2e59bc <FT_Get_First_Char> */
/* @0xf9824 ldr r3, [r11, #-0x234] */
/* @0xf9828 cmp r3, #0 */
/* @0xf982c beq 0xf9db0 <_ZN7CFontGM8CreateItEv+0x750> */
/* @0xf9830 sub r6, r11, #564 */
/* @0xf9834 mov r4, #1 */
/* @0xf9838 mov r1, r0 */
/* @0xf983c mov r2, r6 */
/* @0xf9840 ldr r0, [r11, #-0x238] */
/* @0xf9844 add r4, r4, #1 */
/* @0xf9848 blx 0x2e597e <FT_Get_Next_Char> */
/* @0xf984c ldr r3, [r11, #-0x234] */
/* @0xf9850 cmp r3, #0 */
/* @0xf9854 bne 0xf9838 <_ZN7CFontGM8CreateItEv+0x1d8> */
/* @0xf9858 cmp r4, #532676608 */
/* @0xf985c str r4, [r5, #0x40] */
/* @0xf9860 lsl r4, r4, #2 */
/* @0xf9864 mvnhi r0, #0 */
/* @0xf9868 bls 0xf9dbc <_ZN7CFontGM8CreateItEv+0x75c> */
/* @0xf986c bl 0x27d14c <_Znaj> */
/* @0xf9870 ldr r2, [r5, #0x40] */
/* @0xf9874 mov r1, #0 */
/* @0xf9878 lsl r2, r2, #2 */
/* @0xf987c str r0, [r5, #0x44] */
/* @0xf9880 bl 0xb65b0 <memset@plt> */
/* @0xf9884 mov r1, #32 */
/* @0xf9888 ldr r0, [r11, #-0x238] */
/* @0xf988c blx 0x2e5960 <FT_Get_Char_Index> */
/* @0xf9890 mov r2, #0 */
/* @0xf9894 mov r1, r0 */
/* @0xf9898 ldr r0, [r11, #-0x238] */
/* @0xf989c blx 0x2e7564 <FT_Load_Glyph> */
/* @0xf98a0 mov r0, #16 */
/* @0xf98a4 bl 0x27c524 <_Znwj> */
/* @0xf98a8 ldr r1, [r5, #0x44] */
/* @0xf98ac mov r12, #32 */
/* @0xf98b0 add r2, r4, #14 */
/* @0xf98b4 bic r2, r2, #7 */
/* @0xf98b8 sub sp, sp, r2 */
/* @0xf98bc mov r2, #0 */
/* @0xf98c0 add lr, sp, #8 */
/* @0xf98c4 str lr, [r11, #-0x264] */
/* @0xf98c8 str r0, [r1] */
/* @0xf98cc mov r3, r0 */
/* @0xf98d0 ldr r0, [r11, #-0x238] */
/* @0xf98d4 sub r1, r11, #564 */
/* @0xf98d8 strh r12, [r3] */
/* @0xf98dc strh r2, [r3, #14] */
/* @0xf98e0 ldr r12, [r0, #0x54] */
/* @0xf98e4 strh r2, [r3, #2] */
/* @0xf98e8 strh r2, [r3, #4] */
/* @0xf98ec ldr r12, [r12, #0x28] */
/* @0xf98f0 strh r2, [r3, #6] */
/* @0xf98f4 add r12, r12, #63 */
/* @0xf98f8 strh r2, [r3, #8] */
/* @0xf98fc strh r2, [r3, #12] */
/* @0xf9900 asr r2, r12, #6 */
/* @0xf9904 strh r2, [r3, #10] */
/* @0xf9908 blx 0x2e59bc <FT_Get_First_Char> */
/* @0xf990c ldr r2, [r11, #-0x234] */
/* @0xf9910 cmp r2, #0 */
/* @0xf9914 mov r3, r0 */
/* @0xf9918 beq 0xf994c <_ZN7CFontGM8CreateItEv+0x2ec> */
/* @0xf991c ldr r12, [r11, #-0x264] */
/* @0xf9920 sub r6, r11, #564 */
/* @0xf9924 sub r4, r12, #4 */
/* @0xf9928 mov r1, r3 */
/* @0xf992c str r3, [r4, #0x4]! */
/* @0xf9930 ldr r0, [r11, #-0x238] */
/* @0xf9934 mov r2, r6 */
/* @0xf9938 blx 0x2e597e <FT_Get_Next_Char> */
/* @0xf993c ldr r1, [r11, #-0x234] */
/* @0xf9940 cmp r1, #0 */
/* @0xf9944 mov r3, r0 */
/* @0xf9948 bne 0xf9928 <_ZN7CFontGM8CreateItEv+0x2c8> */
/* @0xf994c ldr r0, [r11, #-0x238] */
/* @0xf9950 sub r1, r11, #564 */
/* @0xf9954 ldr r3, [r0, #0x8] */
/* @0xf9958 and r3, r3, #64 */
/* @0xf995c str r3, [r11, #-0x24c] */
/* @0xf9960 blx 0x2e59bc <FT_Get_First_Char> */
/* @0xf9964 ldr r1, [r11, #-0x234] */
/* @0xf9968 cmp r1, #0 */
/* @0xf996c mov r7, r0 */
/* @0xf9970 beq 0xf9b0c <_ZN7CFontGM8CreateItEv+0x4ac> */
/* @0xf9974 ldr r12, [pc, #0x474] */
/* @0xf9978 mov r9, #1 */
/* @0xf997c str r5, [r11, #-0x254] */
/* @0xf9980 add r12, pc, r12 */
/* @0xf9984 str r12, [r11, #-0x25c] */
/* @0xf9988 sub r12, r11, #552 */
/* @0xf998c str r12, [r11, #-0x244] */
/* @0xf9990 sub r12, r11, #560 */
/* @0xf9994 str r12, [r11, #-0x268] */
/* @0xf9998 ldr r0, [r11, #-0x238] */
/* @0xf999c mov r2, #0 */
/* @0xf99a0 blx 0x2e7564 <FT_Load_Glyph> */
/* @0xf99a4 ldr r12, [r11, #-0x24c] */
/* @0xf99a8 ldr r3, [r11, #-0x238] */
/* @0xf99ac cmp r12, #0 */
/* @0xf99b0 ldr r10, [r3, #0x54] */
/* @0xf99b4 beq 0xf9d90 <_ZN7CFontGM8CreateItEv+0x730> */
/* @0xf99b8 ldr r12, [r11, #-0x264] */
/* @0xf99bc mov r4, #0 */
/* @0xf99c0 sub r8, r11, #560 */
/* @0xf99c4 str r10, [r11, #-0x260] */
/* @0xf99c8 sub r6, r12, #4 */
/* @0xf99cc mov r10, r9 */
/* @0xf99d0 mov r9, r4 */
/* @0xf99d4 ldr r5, [r6, #0x4]! */
/* @0xf99d8 cmp r7, r5 */
/* @0xf99dc beq 0xf9a2c <_ZN7CFontGM8CreateItEv+0x3cc> */
/* @0xf99e0 ldr r0, [r11, #-0x238] */
/* @0xf99e4 mov r1, r5 */
/* @0xf99e8 str r8, [sp] */
/* @0xf99ec mov r2, r7 */
/* @0xf99f0 mov r3, #0 */
/* @0xf99f4 blx 0x2e581c <FT_Get_Kerning> */
/* @0xf99f8 cmp r0, #0 */
/* @0xf99fc bne 0xf9a2c <_ZN7CFontGM8CreateItEv+0x3cc> */
/* @0xf9a00 ldr r3, [r11, #-0x230] */
/* @0xf9a04 cmp r3, #0 */
/* @0xf9a08 beq 0xf9a2c <_ZN7CFontGM8CreateItEv+0x3cc> */
/* @0xf9a0c lsl r2, r9, #2 */
/* @0xf9a10 sub lr, r11, #552 */
/* @0xf9a14 add r3, r3, #63 */
/* @0xf9a18 add r1, lr, r2 */
/* @0xf9a1c add r9, r9, #1 */
/* @0xf9a20 strh r5, [lr, r2] */
/* @0xf9a24 asr r3, r3, #6 */
/* @0xf9a28 strh r3, [r1, #2] */
/* @0xf9a2c add r4, r4, #1 */
/* @0xf9a30 cmp r4, r10 */
/* @0xf9a34 blt 0xf99d4 <_ZN7CFontGM8CreateItEv+0x374> */
/* @0xf9a38 mov r8, r9 */
/* @0xf9a3c mov r9, r10 */
/* @0xf9a40 lsl r4, r8, #2 */
/* @0xf9a44 ldr r10, [r11, #-0x260] */
/* @0xf9a48 uxth r8, r8 */
/* @0xf9a4c add r0, r4, #16 */
/* @0xf9a50 ldr r1, [r11, #-0x25c] */
/* @0xf9a54 movw r2, #0x85e */
/* @0xf9a58 mov r3, #1 */
/* @0xf9a5c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf9a60 ldr r1, [r10, #0x24] */
/* @0xf9a64 ldr r12, [r11, #-0x258] */
/* @0xf9a68 mov r2, r4 */
/* @0xf9a6c ldr r4, [r10, #0x18] */
/* @0xf9a70 mvn lr, #0 */
/* @0xf9a74 rsb r1, r1, r12 */
/* @0xf9a78 ldr r12, [r11, #-0x254] */
/* @0xf9a7c add r4, r4, #63 */
/* @0xf9a80 ldr r5, [r12, #0x44] */
/* @0xf9a84 asr r4, r4, #6 */
/* @0xf9a88 ldr r12, [r10, #0x20] */
/* @0xf9a8c add r12, r12, #63 */
/* @0xf9a90 asr r12, r12, #6 */
/* @0xf9a94 mov r3, r0 */
/* @0xf9a98 ldr r0, [r10, #0x1c] */
/* @0xf9a9c add r1, r1, r0 */
/* @0xf9aa0 ldr r0, [r10, #0x28] */
/* @0xf9aa4 add r1, r1, #63 */
/* @0xf9aa8 str r3, [r5, r9, lsl #2] */
/* @0xf9aac add r0, r0, #63 */
/* @0xf9ab0 strh r7, [r3] */
/* @0xf9ab4 asr r1, r1, #6 */
/* @0xf9ab8 strh r4, [r3, #6] */
/* @0xf9abc strh r1, [r3, #8] */
/* @0xf9ac0 asr r0, r0, #6 */
/* @0xf9ac4 strh r12, [r3, #12] */
/* @0xf9ac8 sub r1, r11, #552 */
/* @0xf9acc strh r0, [r3, #10] */
/* @0xf9ad0 add r0, r3, #16 */
/* @0xf9ad4 strh r8, [r3, #14] */
/* @0xf9ad8 add r9, r9, #1 */
/* @0xf9adc strh lr, [r3, #2] */
/* @0xf9ae0 strh lr, [r3, #4] */
/* @0xf9ae4 bl 0xb65bc <memcpy@plt> */
/* @0xf9ae8 mov r1, r7 */
/* @0xf9aec ldr r0, [r11, #-0x238] */
/* @0xf9af0 sub r2, r11, #564 */
/* @0xf9af4 blx 0x2e597e <FT_Get_Next_Char> */
/* @0xf9af8 ldr r1, [r11, #-0x234] */
/* @0xf9afc cmp r1, #0 */
/* @0xf9b00 mov r7, r0 */
/* @0xf9b04 bne 0xf9998 <_ZN7CFontGM8CreateItEv+0x338> */
/* @0xf9b08 ldr r5, [r11, #-0x254] */
/* @0xf9b0c ldr r3, [pc, #0x2e0] */
/* @0xf9b10 mov r2, #4 */
/* @0xf9b14 ldr r0, [r5, #0x44] */
/* @0xf9b18 ldr r1, [r5, #0x40] */
/* @0xf9b1c add r3, pc, r3 */
/* @0xf9b20 bl 0xb66dc <qsort@plt> */
/* @0xf9b24 ldr r4, [r11, #-0x238] */
/* @0xf9b28 ldr r2, [pc, #0x2c8] */
/* @0xf9b2c ldr r12, [r11, #-0x240] */
/* @0xf9b30 ldr r3, [r4, #0x58] */
/* @0xf9b34 ldr r9, [r3, #0x20] */
/* @0xf9b38 ldr r8, [r3, #0x24] */
/* @0xf9b3c add r9, r9, #63 */
/* @0xf9b40 add r8, r8, #63 */
/* @0xf9b44 asr r9, r9, #6 */
/* @0xf9b48 str r9, [r5, #0x2c] */
/* @0xf9b4c ldr r3, [r12, r2] */
/* @0xf9b50 asr r8, r8, #6 */
/* @0xf9b54 add r8, r8, #4 */
/* @0xf9b58 add r9, r9, #4 */
/* @0xf9b5c ldr r6, [r3] */
/* @0xf9b60 mov r1, r8 */
/* @0xf9b64 mul r8, r9, r8 */
/* @0xf9b68 mov r0, r6 */
/* @0xf9b6c bl 0x318d10 <__divsi3> */
/* @0xf9b70 mov r1, r9 */
/* @0xf9b74 mov r7, r0 */
/* @0xf9b78 mov r0, r6 */
/* @0xf9b7c bl 0x318d10 <__divsi3> */
/* @0xf9b80 mov r1, r8 */
/* @0xf9b84 mul r7, r0, r7 */
/* @0xf9b88 mul r0, r6, r6 */
/* @0xf9b8c bl 0x318d10 <__divsi3> */
/* @0xf9b90 cmp r7, r0 */
/* @0xf9b94 ble 0xf9bb0 <_ZN7CFontGM8CreateItEv+0x550> */
/* @0xf9b98 lsl r6, r6, #1 */
/* @0xf9b9c mov r1, r8 */
/* @0xf9ba0 mul r0, r6, r6 */
/* @0xf9ba4 bl 0x318d10 <__divsi3> */
/* @0xf9ba8 cmp r7, r0 */
/* @0xf9bac bgt 0xf9b98 <_ZN7CFontGM8CreateItEv+0x538> */
/* @0xf9bb0 mov r2, #0 */
/* @0xf9bb4 mov r12, #4 */
/* @0xf9bb8 mov r3, r2 */
/* @0xf9bbc mov r0, r6 */
/* @0xf9bc0 mov r1, r6 */
/* @0xf9bc4 str r12, [sp] */
/* @0xf9bc8 bl 0x173a24 <_Z23GR_Texture_Create_Emptyiibbi> */
/* @0xf9bcc ldr r3, [pc, #0x228] */
/* @0xf9bd0 ldr r12, [r11, #-0x240] */
/* @0xf9bd4 str r0, [r5, #0x68] */
/* @0xf9bd8 ldr r3, [r12, r3] */
/* @0xf9bdc ldr r3, [r3, #0x4] */
/* @0xf9be0 ldr r3, [r3, r0, lsl #2] */
/* @0xf9be4 ldr r3, [r3] */
/* @0xf9be8 str r4, [r5, #0x70] */
/* @0xf9bec ldr r2, [r3] */
/* @0xf9bf0 ldr r6, [r3, #0x4] */
/* @0xf9bf4 sub r2, r2, #6 */
/* @0xf9bf8 str r3, [r5, #0x64] */
/* @0xf9bfc cmp r2, #5 */
/* @0xf9c00 ldr r7, [r3, #0x8] */
/* @0xf9c04 movhi r8, #1 */
/* @0xf9c08 bls 0xf9da0 <_ZN7CFontGM8CreateItEv+0x740> */
/* @0xf9c0c cmp r7, #0 */
/* @0xf9c10 ldr r0, [r3, #0x28] */
/* @0xf9c14 mul r8, r8, r6 */
/* @0xf9c18 ble 0xf9c68 <_ZN7CFontGM8CreateItEv+0x608> */
/* @0xf9c1c mov lr, #0 */
/* @0xf9c20 mvn r1, #0 */
/* @0xf9c24 mov r12, lr */
/* @0xf9c28 cmp r6, #0 */
/* @0xf9c2c ble 0xf9c58 <_ZN7CFontGM8CreateItEv+0x5f8> */
/* @0xf9c30 mov r3, r0 */
/* @0xf9c34 mov r2, #0 */
/* @0xf9c38 add r2, r2, #1 */
/* @0xf9c3c strb r1, [r3] */
/* @0xf9c40 cmp r2, r6 */
/* @0xf9c44 strb r1, [r3, #0x1] */
/* @0xf9c48 strb r1, [r3, #0x2] */
/* @0xf9c4c add r3, r3, #4 */
/* @0xf9c50 strb r12, [r3, #-0x1] */
/* @0xf9c54 bne 0xf9c38 <_ZN7CFontGM8CreateItEv+0x5d8> */
/* @0xf9c58 add lr, lr, #1 */
/* @0xf9c5c add r0, r0, r8 */
/* @0xf9c60 cmp lr, r7 */
/* @0xf9c64 bne 0xf9c28 <_ZN7CFontGM8CreateItEv+0x5c8> */
/* @0xf9c68 ldr r3, [r4, #0x58] */
/* @0xf9c6c mov r9, #2 */
/* @0xf9c70 sub r0, r6, #4 */
/* @0xf9c74 str r9, [r5, #0x84] */
/* @0xf9c78 str r9, [r5, #0x88] */
/* @0xf9c7c ldr r1, [r3, #0x24] */
/* @0xf9c80 ldr r4, [r3, #0x20] */
/* @0xf9c84 add r1, r1, #63 */
/* @0xf9c88 str r6, [r5, #0x7c] */
/* @0xf9c8c add r4, r4, #63 */
/* @0xf9c90 str r7, [r5, #0x80] */
/* @0xf9c94 asr r1, r1, #6 */
/* @0xf9c98 str r1, [r5, #0x74] */
/* @0xf9c9c asr r4, r4, #6 */
/* @0xf9ca0 add r1, r1, r9 */
/* @0xf9ca4 str r4, [r5, #0x78] */
/* @0xf9ca8 bl 0x318d10 <__divsi3> */
/* @0xf9cac add r1, r4, r9 */
/* @0xf9cb0 mov r8, r0 */
/* @0xf9cb4 sub r0, r7, #4 */
/* @0xf9cb8 bl 0x318d10 <__divsi3> */
/* @0xf9cbc mul r0, r0, r8 */
/* @0xf9cc0 cmp r0, #0 */
/* @0xf9cc4 str r0, [r5, #0x6c] */
/* @0xf9cc8 ble 0xf9dc4 <_ZN7CFontGM8CreateItEv+0x764> */
/* @0xf9ccc mov r8, #0 */
/* @0xf9cd0 mov r4, r9 */
/* @0xf9cd4 mov r7, r8 */
/* @0xf9cd8 mov r10, r8 */
/* @0xf9cdc b 0xf9ce4 <_ZN7CFontGM8CreateItEv+0x684> */
/* @0xf9ce0 mov r7, r0 */
/* @0xf9ce4 mov r0, #24 */
/* @0xf9ce8 add r8, r8, #1 */
/* @0xf9cec bl 0x27c524 <_Znwj> */
/* @0xf9cf0 ldr r3, [r5, #0x74] */
/* @0xf9cf4 ldr r2, [r5, #0x84] */
/* @0xf9cf8 rsb r1, r3, r6 */
/* @0xf9cfc add r3, r3, r2 */
/* @0xf9d00 str r4, [r0, #0xc] */
/* @0xf9d04 add r4, r4, r3 */
/* @0xf9d08 cmp r4, r1 */
/* @0xf9d0c str r9, [r0, #0x10] */
/* @0xf9d10 str r10, [r0] */
/* @0xf9d14 ldrgt r3, [r5, #0x88] */
/* @0xf9d18 movgt r4, r2 */
/* @0xf9d1c ldrgt r1, [r5, #0x78] */
/* @0xf9d20 str r7, [r0, #0x4] */
/* @0xf9d24 addgt r3, r1, r3 */
/* @0xf9d28 str r10, [r0, #0x8] */
/* @0xf9d2c addgt r9, r9, r3 */
/* @0xf9d30 ldr r3, [r5, #0x6c] */
/* @0xf9d34 cmp r7, #0 */
/* @0xf9d38 strne r0, [r7] */
/* @0xf9d3c streq r0, [r5, #0x5c] */
/* @0xf9d40 cmp r8, r3 */
/* @0xf9d44 blt 0xf9ce0 <_ZN7CFontGM8CreateItEv+0x680> */
/* @0xf9d48 ldr r12, [r5, #0x40] */
/* @0xf9d4c mov r3, #1 */
/* @0xf9d50 ldr r1, [pc, #0xa8] */
/* @0xf9d54 mov r2, #2176 */
/* @0xf9d58 str r0, [r5, #0x60] */
/* @0xf9d5c add r1, pc, r1 */
/* @0xf9d60 lsl r0, r12, #2 */
/* @0xf9d64 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xf9d68 ldr r2, [r5, #0x40] */
/* @0xf9d6c mov r1, #0 */
/* @0xf9d70 lsl r2, r2, #2 */
/* @0xf9d74 str r0, [r5, #0x8c] */
/* @0xf9d78 bl 0xb65b0 <memset@plt> */
/* @0xf9d7c ldr r3, [r5, #0x68] */
/* @0xf9d80 mov r2, #0 */
/* @0xf9d84 str r2, [r5, #0x50] */
/* @0xf9d88 str r3, [r5, #0x38] */
/* @0xf9d8c b 0xf971c <_ZN7CFontGM8CreateItEv+0xbc> */
/* @0xf9d90 ldr r8, [r11, #-0x24c] */
/* @0xf9d94 mov r0, #16 */
/* @0xf9d98 mov r4, r8 */
/* @0xf9d9c b 0xf9a50 <_ZN7CFontGM8CreateItEv+0x3f0> */
/* @0xf9da0 ldr r1, [pc, #0x5c] */
/* @0xf9da4 add r1, pc, r1 */
/* @0xf9da8 ldr r8, [r1, r2, lsl #2] */
/* @0xf9dac b 0xf9c0c <_ZN7CFontGM8CreateItEv+0x5ac> */
/* @0xf9db0 mov r4, #4 */
/* @0xf9db4 mov r3, #1 */
/* @0xf9db8 str r3, [r5, #0x40] */
/* @0xf9dbc mov r0, r4 */
/* @0xf9dc0 b 0xf986c <_ZN7CFontGM8CreateItEv+0x20c> */
/* @0xf9dc4 mov r0, #0 */
/* @0xf9dc8 b 0xf9d48 <_ZN7CFontGM8CreateItEv+0x6e8> */
/* @0xf9dcc bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xf9dd0 .word 0x002f85d8 */
/* @0xf9dd4 .word 0xffffbd00 */
/* @0xf9dd8 .word 0xffffc200 */
/* @0xf9ddc eoreq lr, r3, r8, ror #6 */
/* @0xf9de0 .word 0xffffbac4 */
/* @0xf9de4 eoreq lr, r3, r12, lsr r3 */
/* @0xf9de8 eoreq lr, r3, r4, ror #4 */
/* @0xf9dec eoreq lr, r3, r8, lsr #5 */
/* @0xf9df0 eoreq lr, r3, r4, lsl #1 */
/* @0xf9df4 .word 0xffffcd8c */
/* @0xf9df8 .word 0xffffc204 */
/* @0xf9dfc .word 0xffffbccc */
/* @0xf9e00 eoreq sp, r3, r8, lsr #25 */
/* @0xf9e04 eoreq r2, r6, r4, ror r11 */

/* ── FUNC 0xf9e08 · CFontGM::CFontGM(char const*, int, bool, bool, int, int) · size=324 · insn=81 */
/* @0xf9e08 ldr r12, [pc, #0x134] */
/* @0xf9e0c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xf9e10 ldr r12, [pc, r12] */
/* @0xf9e14 mov r5, #0 */
/* @0xf9e18 mvn lr, #0 */
/* @0xf9e1c mov r8, r1 */
/* @0xf9e20 str lr, [r0, #0x20] */
/* @0xf9e24 str lr, [r0, #0x38] */
/* @0xf9e28 mov r6, #1056964608 */
/* @0xf9e2c add r12, r12, #8 */
/* @0xf9e30 str r6, [r0, #0x50] */
/* @0xf9e34 str r12, [r0] */
/* @0xf9e38 mov r12, #1065353216 */
/* @0xf9e3c str r5, [r0, #0x4] */
/* @0xf9e40 mov r4, r0 */
/* @0xf9e44 str r12, [r0, #0x48] */
/* @0xf9e48 mov r9, r2 */
/* @0xf9e4c str r12, [r0, #0x4c] */
/* @0xf9e50 mov r11, r3 */
/* @0xf9e54 str r5, [r0, #0x8] */
/* @0xf9e58 strb r5, [r0, #0xc] */
/* @0xf9e5c strb r5, [r0, #0xd] */
/* @0xf9e60 str r5, [r0, #0x18] */
/* @0xf9e64 str r5, [r0, #0x1c] */
/* @0xf9e68 str r5, [r0, #0x24] */
/* @0xf9e6c str r5, [r0, #0x28] */
/* @0xf9e70 str r5, [r0, #0x2c] */
/* @0xf9e74 str r5, [r0, #0x40] */
/* @0xf9e78 str r5, [r0, #0x44] */
/* @0xf9e7c str r5, [r0, #0x5c] */
/* @0xf9e80 str r5, [r0, #0x60] */
/* @0xf9e84 str r5, [r0, #0x64] */
/* @0xf9e88 str r5, [r0, #0x6c] */
/* @0xf9e8c str r5, [r0, #0x70] */
/* @0xf9e90 str r5, [r0, #0x74] */
/* @0xf9e94 str r5, [r0, #0x78] */
/* @0xf9e98 str r5, [r0, #0x7c] */
/* @0xf9e9c str r5, [r0, #0x80] */
/* @0xf9ea0 str r5, [r0, #0x84] */
/* @0xf9ea4 str r5, [r0, #0x88] */
/* @0xf9ea8 str r5, [r0, #0x3c] */
/* @0xf9eac ldrb r10, [sp, #0x28] */
/* @0xf9eb0 ldr r7, [sp, #0x2c] */
/* @0xf9eb4 ldr r6, [sp, #0x30] */
/* @0xf9eb8 str r5, [r0, #0x34] */
/* @0xf9ebc bic r7, r7, r7, asr #31 */
/* @0xf9ec0 str r5, [r0, #0x30] */
/* @0xf9ec4 cmp r6, #255 */
/* @0xf9ec8 movge r6, #255 */
/* @0xf9ecc str r5, [r0, #0x54] */
/* @0xf9ed0 str r5, [r0, #0x8c] */
/* @0xf9ed4 bl 0xf70a0 <_ZN7CFontGM5ClearEv> */
/* @0xf9ed8 mov r0, r8 */
/* @0xf9edc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xf9ee0 ldr r1, [pc, #0x60] */
/* @0xf9ee4 str r9, [r4, #0x8] */
/* @0xf9ee8 ldr r1, [pc, r1] */
/* @0xf9eec str r7, [r4, #0x18] */
/* @0xf9ef0 strb r11, [r4, #0xc] */
/* @0xf9ef4 ldrb r3, [r1] */
/* @0xf9ef8 str r6, [r4, #0x1c] */
/* @0xf9efc cmp r3, r5 */
/* @0xf9f00 strb r10, [r4, #0xd] */
/* @0xf9f04 str r5, [r4, #0x10] */
/* @0xf9f08 movne r3, #3 */
/* @0xf9f0c moveq r3, r5 */
/* @0xf9f10 str r3, [r4, #0x14] */
/* @0xf9f14 str r0, [r4, #0x4] */
/* @0xf9f18 mov r0, r4 */
/* @0xf9f1c bl 0xf9660 <_ZN7CFontGM8CreateItEv> */
/* @0xf9f20 ldr r3, [r4, #0x38] */
/* @0xf9f24 cmn r3, #1 */
/* @0xf9f28 beq 0xf9f34 <_ZN7CFontGMC2EPKcibbii+0x12c> */
/* @0xf9f2c mov r0, r4 */
/* @0xf9f30 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf9f34 mov r0, r4 */
/* @0xf9f38 bl 0xf7db4 <_ZN7CFontGM11InitTextureEv> */
/* @0xf9f3c mov r0, r4 */
/* @0xf9f40 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xf9f44 eoreq r4, pc, r8, lsr r0 */
/* @0xf9f48 eoreq r3, pc, r0, ror pc */

/* ── FUNC 0xf9e08 · CFontGM::CFontGM(char const*, int, bool, bool, int, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0xf9f4c · CFontGM::CFont_CreateFont(char const*, int, int, int, int, int) · size=104 · insn=26 */
/* @0xf9f4c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xf9f50 sub sp, sp, #16 */
/* @0xf9f54 mov r9, r0 */
/* @0xf9f58 mov r0, #144 */
/* @0xf9f5c mov r8, r1 */
/* @0xf9f60 mov r7, r2 */
/* @0xf9f64 mov r10, r3 */
/* @0xf9f68 ldr r5, [sp, #0x30] */
/* @0xf9f6c ldr r4, [sp, #0x34] */
/* @0xf9f70 bl 0x27c524 <_Znwj> */
/* @0xf9f74 subs r2, r10, #1 */
/* @0xf9f78 mov r1, r9 */
/* @0xf9f7c rsbs r3, r2, #0 */
/* @0xf9f80 str r5, [sp, #0x4] */
/* @0xf9f84 adcs r3, r3, r2 */
/* @0xf9f88 subs r12, r7, #1 */
/* @0xf9f8c str r3, [sp] */
/* @0xf9f90 rsbs r3, r12, #0 */
/* @0xf9f94 str r4, [sp, #0x8] */
/* @0xf9f98 mov r2, r8 */
/* @0xf9f9c adcs r3, r3, r12 */
/* @0xf9fa0 mov r6, r0 */
/* @0xf9fa4 bl 0xf9e08 <_ZN7CFontGMC2EPKcibbii> */
/* @0xf9fa8 mov r0, r6 */
/* @0xf9fac add sp, sp, #16 */
/* @0xf9fb0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0xf9fb4 · Font_Init() · size=288 · insn=72 */
/* @0xf9fb4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xf9fb8 ldr r5, [pc, #0xf8] */
/* @0xf9fbc ldr r3, [pc, #0xf8] */
/* @0xf9fc0 add r5, pc, r5 */
/* @0xf9fc4 ldr r0, [r5, r3] */
/* @0xf9fc8 blx 0x2e9b30 <FT_Init_FreeType> */
/* @0xf9fcc subs r2, r0, #0 */
/* @0xf9fd0 bne 0xfa094 <_Z9Font_Initv+0xe0> */
/* @0xf9fd4 ldr r3, [pc, #0xe4] */
/* @0xf9fd8 ldr r6, [r5, r3] */
/* @0xf9fdc ldr r0, [r6, #0x4] */
/* @0xf9fe0 cmp r0, #0 */
/* @0xf9fe4 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xf9fe8 ldr r3, [pc, #0xd4] */
/* @0xf9fec ldr r8, [r5, r3] */
/* @0xf9ff0 ldr r3, [r8] */
/* @0xf9ff4 cmp r3, #0 */
/* @0xf9ff8 ldr r3, [pc, #0xc8] */
/* @0xf9ffc ldrle r9, [r5, r3] */
/* @0xfa000 ble 0xfa070 <_Z9Font_Initv+0xbc> */
/* @0xfa004 ldr r9, [r5, r3] */
/* @0xfa008 mov r4, #0 */
/* @0xfa00c mov r7, r4 */
/* @0xfa010 ldr r3, [r0, r4, lsl #2] */
/* @0xfa014 lsl r5, r4, #2 */
/* @0xfa018 add r2, r0, r5 */
/* @0xfa01c add r4, r4, #1 */
/* @0xfa020 cmp r3, #0 */
/* @0xfa024 mov r0, r3 */
/* @0xfa028 beq 0xfa040 <_Z9Font_Initv+0x8c> */
/* @0xfa02c ldr r3, [r3] */
/* @0xfa030 ldr r3, [r3, #0x4] */
/* @0xfa034 blx r3 */
/* @0xfa038 ldr r2, [r6, #0x4] */
/* @0xfa03c add r2, r2, r5 */
/* @0xfa040 str r7, [r2] */
/* @0xfa044 ldr r3, [r9] */
/* @0xfa048 ldr r0, [r3, r5] */
/* @0xfa04c cmp r0, #0 */
/* @0xfa050 beq 0xfa060 <_Z9Font_Initv+0xac> */
/* @0xfa054 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfa058 ldr r3, [r9] */
/* @0xfa05c str r7, [r3, r5] */
/* @0xfa060 ldr r3, [r8] */
/* @0xfa064 ldr r0, [r6, #0x4] */
/* @0xfa068 cmp r3, r4 */
/* @0xfa06c bgt 0xfa010 <_Z9Font_Initv+0x5c> */
/* @0xfa070 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfa074 ldr r0, [r9] */
/* @0xfa078 mov r4, #0 */
/* @0xfa07c str r4, [r6, #0x4] */
/* @0xfa080 str r4, [r6] */
/* @0xfa084 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfa088 str r4, [r8] */
/* @0xfa08c str r4, [r9] */
/* @0xfa090 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xfa094 ldr r3, [pc, #0x30] */
/* @0xfa098 ldr r1, [pc, #0x30] */
/* @0xfa09c ldr r3, [r5, r3] */
/* @0xfa0a0 add r1, pc, r1 */
/* @0xfa0a4 ldr r0, [r3] */
/* @0xfa0a8 ldr r3, [r0] */
/* @0xfa0ac ldr r3, [r3, #0xc] */
/* @0xfa0b0 blx r3 */
/* @0xfa0b4 b 0xf9fd4 <_Z9Font_Initv+0x20> */
/* @0xfa0b8 mlaeq pc, r0, r12, r7 */
/* @0xfa0bc .word 0xffffc200 */
/* @0xfa0c0 .word 0xffffc20c */
/* @0xfa0c4 .word 0xffffc210 */
/* @0xfa0c8 .word 0xffffc214 */
/* @0xfa0cc .word 0xffffbac4 */
/* @0xfa0d0 mlaeq r3, r4, r10, sp */

/* ── FUNC 0xfa0d4 · Font_Load(unsigned char*, unsigned int, unsigned char*) · size=448 · insn=112 */
/* @0xfa0d4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xfa0d8 mov r7, r0 */
/* @0xfa0dc ldr r3, [r7] */
/* @0xfa0e0 sub sp, sp, #28 */
/* @0xfa0e4 ldr r11, [pc, #0x188] */
/* @0xfa0e8 mov r6, r1 */
/* @0xfa0ec ldr r0, [pc, #0x184] */
/* @0xfa0f0 sub r6, r6, #512 */
/* @0xfa0f4 add r11, pc, r11 */
/* @0xfa0f8 str r3, [sp, #0x4] */
/* @0xfa0fc str r2, [sp, #0xc] */
/* @0xfa100 mov r3, #98 */
/* @0xfa104 ldr r1, [r11, r0] */
/* @0xfa108 add r6, r7, r6 */
/* @0xfa10c ldr r0, [sp, #0x4] */
/* @0xfa110 ldr r2, [pc, #0x164] */
/* @0xfa114 ldr r4, [pc, #0x164] */
/* @0xfa118 str r0, [r1] */
/* @0xfa11c lsl r5, r0, #2 */
/* @0xfa120 ldr r10, [r11, r2] */
/* @0xfa124 add r4, pc, r4 */
/* @0xfa128 mov r1, r5 */
/* @0xfa12c mov r2, r4 */
/* @0xfa130 add r0, r10, #4 */
/* @0xfa134 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xfa138 ldr r2, [sp, #0x4] */
/* @0xfa13c ldr r0, [pc, #0x140] */
/* @0xfa140 mov r3, #100 */
/* @0xfa144 mov r1, r5 */
/* @0xfa148 str r2, [r10] */
/* @0xfa14c mov r2, r4 */
/* @0xfa150 ldr r8, [r11, r0] */
/* @0xfa154 mov r0, r8 */
/* @0xfa158 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xfa15c ldr r3, [pc, #0x124] */
/* @0xfa160 ldr r0, [sp, #0x4] */
/* @0xfa164 ldr r3, [r11, r3] */
/* @0xfa168 cmp r0, #0 */
/* @0xfa16c str r6, [r3] */
/* @0xfa170 beq 0xfa260 <_Z9Font_LoadPhjS_+0x18c> */
/* @0xfa174 ldr r2, [pc, #0x110] */
/* @0xfa178 mov r4, #0 */
/* @0xfa17c str r11, [sp, #0x14] */
/* @0xfa180 add r2, pc, r2 */
/* @0xfa184 str r2, [sp, #0x10] */
/* @0xfa188 b 0xfa24c <_Z9Font_LoadPhjS_+0x178> */
/* @0xfa18c ldr r3, [pc, #0xfc] */
/* @0xfa190 ldr r0, [sp, #0x14] */
/* @0xfa194 ldr r3, [r0, r3] */
/* @0xfa198 ldr r11, [r3] */
/* @0xfa19c str r3, [sp, #0x8] */
/* @0xfa1a0 adds r9, r11, r6 */
/* @0xfa1a4 beq 0xfa26c <_Z9Font_LoadPhjS_+0x198> */
/* @0xfa1a8 mov r0, #144 */
/* @0xfa1ac bl 0x27c524 <_Znwj> */
/* @0xfa1b0 mov r5, r0 */
/* @0xfa1b4 bl 0xf71c8 <_ZN7CFontGMC2Ev> */
/* @0xfa1b8 mov r1, r9 */
/* @0xfa1bc ldr r2, [sp, #0xc] */
/* @0xfa1c0 mov r0, r5 */
/* @0xfa1c4 bl 0xf7bc4 <_ZN7CFontGM13LoadFromChunkEP6YYFontPh> */
/* @0xfa1c8 ldr r12, [r11, r6] */
/* @0xfa1cc cmp r12, #0 */
/* @0xfa1d0 ldrne r2, [sp, #0x8] */
/* @0xfa1d4 moveq r9, r12 */
/* @0xfa1d8 ldrne r3, [r2] */
/* @0xfa1dc addne r9, r3, r12 */
/* @0xfa1e0 mov r0, r9 */
/* @0xfa1e4 bl 0xb6538 <strlen@plt> */
/* @0xfa1e8 ldr r1, [sp, #0x10] */
/* @0xfa1ec mov r3, #1 */
/* @0xfa1f0 mov r2, #114 */
/* @0xfa1f4 add r0, r0, r3 */
/* @0xfa1f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfa1fc mov r1, r9 */
/* @0xfa200 mov r6, r0 */
/* @0xfa204 bl 0xb65a4 <strcpy@plt> */
/* @0xfa208 ldr r2, [r8] */
/* @0xfa20c lsl r9, r4, #2 */
/* @0xfa210 ldr r0, [r2, r4, lsl #2] */
/* @0xfa214 cmp r0, #0 */
/* @0xfa218 beq 0xfa22c <_Z9Font_LoadPhjS_+0x158> */
/* @0xfa21c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfa220 ldr r2, [r8] */
/* @0xfa224 mov r3, #0 */
/* @0xfa228 str r3, [r2, r4, lsl #2] */
/* @0xfa22c ldr r2, [r10, #0x4] */
/* @0xfa230 add r4, r4, #1 */
/* @0xfa234 ldr r0, [sp, #0x4] */
/* @0xfa238 str r5, [r2, r9] */
/* @0xfa23c cmp r4, r0 */
/* @0xfa240 ldr r2, [r8] */
/* @0xfa244 str r6, [r2, r9] */
/* @0xfa248 beq 0xfa260 <_Z9Font_LoadPhjS_+0x18c> */
/* @0xfa24c ldr r6, [r7, #0x4]! */
/* @0xfa250 cmp r6, #0 */
/* @0xfa254 bne 0xfa18c <_Z9Font_LoadPhjS_+0xb8> */
/* @0xfa258 mov r5, r6 */
/* @0xfa25c b 0xfa208 <_Z9Font_LoadPhjS_+0x134> */
/* @0xfa260 mov r0, #1 */
/* @0xfa264 add sp, sp, #28 */
/* @0xfa268 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xfa26c mov r6, r9 */
/* @0xfa270 b 0xfa258 <_Z9Font_LoadPhjS_+0x184> */
/* @0xfa274 eoreq r7, pc, r12, asr r11 */
/* @0xfa278 .word 0xffffc210 */
/* @0xfa27c .word 0xffffc20c */
/* @0xfa280 eoreq sp, r3, r8, lsr r10 */
/* @0xfa284 .word 0xffffc214 */
/* @0xfa288 .word 0xffffc218 */
/* @0xfa28c .word 0x0023d9dc */
/* @0xfa290 .word 0xffffbcf4 */

/* ── FUNC 0xfa294 · Font_Number() · size=20 · insn=5 */
/* @0xfa294 ldr r3, [pc, #0x8] */
/* @0xfa298 ldr r3, [pc, r3] */
/* @0xfa29c ldr r0, [r3] */
/* @0xfa2a0 bx lr */
/* @0xfa2a4 eoreq r3, pc, r8, asr #23 */

/* ── FUNC 0xfa2a8 · Font_Exists(int) · size=72 · insn=18 */
/* @0xfa2a8 cmp r0, #0 */
/* @0xfa2ac blt 0xfa2e0 <_Z11Font_Existsi+0x38> */
/* @0xfa2b0 ldr r3, [pc, #0x30] */
/* @0xfa2b4 ldr r3, [pc, r3] */
/* @0xfa2b8 ldr r3, [r3] */
/* @0xfa2bc cmp r0, r3 */
/* @0xfa2c0 bge 0xfa2e0 <_Z11Font_Existsi+0x38> */
/* @0xfa2c4 ldr r3, [pc, #0x20] */
/* @0xfa2c8 ldr r3, [pc, r3] */
/* @0xfa2cc ldr r3, [r3, #0x4] */
/* @0xfa2d0 ldr r0, [r3, r0, lsl #2] */
/* @0xfa2d4 adds r0, r0, #0 */
/* @0xfa2d8 movne r0, #1 */
/* @0xfa2dc bx lr */
/* @0xfa2e0 mov r0, #0 */
/* @0xfa2e4 bx lr */
/* @0xfa2e8 eoreq r3, pc, r12, lsr #23 */
/* @0xfa2ec mlaeq pc, r4, r11, r3 */

/* ── FUNC 0xfa2f0 · Font_Name(int) · size=132 · insn=33 */
/* @0xfa2f0 cmp r0, #0 */
/* @0xfa2f4 blt 0xfa344 <_Z9Font_Namei+0x54> */
/* @0xfa2f8 ldr r3, [pc, #0x5c] */
/* @0xfa2fc ldr r3, [pc, r3] */
/* @0xfa300 ldr r3, [r3] */
/* @0xfa304 cmp r0, r3 */
/* @0xfa308 bge 0xfa338 <_Z9Font_Namei+0x48> */
/* @0xfa30c ldr r3, [pc, #0x4c] */
/* @0xfa310 ldr r3, [pc, r3] */
/* @0xfa314 ldr r3, [r3, #0x4] */
/* @0xfa318 ldr r3, [r3, r0, lsl #2] */
/* @0xfa31c cmp r3, #0 */
/* @0xfa320 beq 0xfa350 <_Z9Font_Namei+0x60> */
/* @0xfa324 ldr r3, [pc, #0x38] */
/* @0xfa328 ldr r3, [pc, r3] */
/* @0xfa32c ldr r3, [r3] */
/* @0xfa330 ldr r0, [r3, r0, lsl #2] */
/* @0xfa334 bx lr */
/* @0xfa338 ldr r0, [pc, #0x28] */
/* @0xfa33c add r0, pc, r0 */
/* @0xfa340 bx lr */
/* @0xfa344 ldr r0, [pc, #0x20] */
/* @0xfa348 add r0, pc, r0 */
/* @0xfa34c bx lr */
/* @0xfa350 ldr r0, [pc, #0x18] */
/* @0xfa354 add r0, pc, r0 */
/* @0xfa358 bx lr */
/* @0xfa35c eoreq r3, pc, r4, ror #22 */
/* @0xfa360 eoreq r3, pc, r12, asr #22 */
/* @0xfa364 eoreq r3, pc, r12, lsr r11 */
/* @0xfa368 eoreq r6, r3, r4, lsl #15 */
/* @0xfa36c eoreq r6, r3, r8, ror r7 */
/* @0xfa370 eoreq r6, r3, r12, ror #14 */

/* ── FUNC 0xfa374 · Font_Find(char const*) · size=136 · insn=34 */
/* @0xfa374 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xfa378 mov r7, r0 */
/* @0xfa37c ldr r3, [pc, #0x6c] */
/* @0xfa380 ldr r3, [pc, r3] */
/* @0xfa384 ldr r6, [r3] */
/* @0xfa388 cmp r6, #0 */
/* @0xfa38c ble 0xfa3e0 <_Z9Font_FindPKc+0x6c> */
/* @0xfa390 ldr r2, [pc, #0x5c] */
/* @0xfa394 mov r4, #0 */
/* @0xfa398 ldr r3, [pc, #0x58] */
/* @0xfa39c mov r5, r4 */
/* @0xfa3a0 ldr r2, [pc, r2] */
/* @0xfa3a4 ldr r3, [pc, r3] */
/* @0xfa3a8 ldr r8, [r2, #0x4] */
/* @0xfa3ac ldr r9, [r3] */
/* @0xfa3b0 ldr r3, [r8, r4] */
/* @0xfa3b4 mov r1, r7 */
/* @0xfa3b8 cmp r3, #0 */
/* @0xfa3bc beq 0xfa3d0 <_Z9Font_FindPKc+0x5c> */
/* @0xfa3c0 ldr r0, [r9, r4] */
/* @0xfa3c4 bl 0xb6574 <strcmp@plt> */
/* @0xfa3c8 cmp r0, #0 */
/* @0xfa3cc beq 0xfa3e8 <_Z9Font_FindPKc+0x74> */
/* @0xfa3d0 add r5, r5, #1 */
/* @0xfa3d4 add r4, r4, #4 */
/* @0xfa3d8 cmp r5, r6 */
/* @0xfa3dc bne 0xfa3b0 <_Z9Font_FindPKc+0x3c> */
/* @0xfa3e0 mvn r0, #0 */
/* @0xfa3e4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xfa3e8 mov r0, r5 */
/* @0xfa3ec pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xfa3f0 eoreq r3, pc, r0, ror #21 */
/* @0xfa3f4 .word 0x002f3abc */
/* @0xfa3f8 eoreq r3, pc, r0, asr #21 */

/* ── FUNC 0xfa3fc · Font_Data(int) · size=64 · insn=16 */
/* @0xfa3fc cmp r0, #0 */
/* @0xfa400 blt 0xfa42c <_Z9Font_Datai+0x30> */
/* @0xfa404 ldr r3, [pc, #0x28] */
/* @0xfa408 ldr r3, [pc, r3] */
/* @0xfa40c ldr r3, [r3] */
/* @0xfa410 cmp r0, r3 */
/* @0xfa414 bge 0xfa42c <_Z9Font_Datai+0x30> */
/* @0xfa418 ldr r3, [pc, #0x18] */
/* @0xfa41c ldr r3, [pc, r3] */
/* @0xfa420 ldr r3, [r3, #0x4] */
/* @0xfa424 ldr r0, [r3, r0, lsl #2] */
/* @0xfa428 bx lr */
/* @0xfa42c mov r0, #0 */
/* @0xfa430 bx lr */
/* @0xfa434 eoreq r3, pc, r8, asr r10 */
/* @0xfa438 eoreq r3, pc, r0, asr #20 */

/* ── FUNC 0xfa43c · Font_Add(char const*, int, bool, bool, int, int) · size=368 · insn=92 */
/* @0xfa43c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xfa440 mov r10, r0 */
/* @0xfa444 ldr r5, [pc, #0x144] */
/* @0xfa448 mov r9, r1 */
/* @0xfa44c ldr r0, [pc, #0x140] */
/* @0xfa450 mov r8, r2 */
/* @0xfa454 add r5, pc, r5 */
/* @0xfa458 ldr r2, [pc, #0x138] */
/* @0xfa45c ldr r1, [pc, #0x138] */
/* @0xfa460 mov r11, r3 */
/* @0xfa464 ldr r0, [r5, r0] */
/* @0xfa468 sub sp, sp, #292 */
/* @0xfa46c ldr r3, [r0] */
/* @0xfa470 str r0, [sp, #0x14] */
/* @0xfa474 str r3, [sp, #0x11c] */
/* @0xfa478 ldr r4, [r5, r2] */
/* @0xfa47c ldr r6, [r5, r1] */
/* @0xfa480 ldr r3, [r4] */
/* @0xfa484 ldr r2, [r6] */
/* @0xfa488 cmp r2, r3 */
/* @0xfa48c beq 0xfa538 <_Z8Font_AddPKcibbii+0xfc> */
/* @0xfa490 ldr r2, [pc, #0x108] */
/* @0xfa494 ldr r5, [r5, r2] */
/* @0xfa498 mov r0, #144 */
/* @0xfa49c add r3, r3, #1 */
/* @0xfa4a0 str r3, [r4] */
/* @0xfa4a4 bl 0x27c524 <_Znwj> */
/* @0xfa4a8 ldr r3, [sp, #0x148] */
/* @0xfa4ac mov r1, r10 */
/* @0xfa4b0 mov r2, r9 */
/* @0xfa4b4 str r11, [sp] */
/* @0xfa4b8 str r3, [sp, #0x4] */
/* @0xfa4bc ldr r3, [sp, #0x14c] */
/* @0xfa4c0 str r3, [sp, #0x8] */
/* @0xfa4c4 mov r3, r8 */
/* @0xfa4c8 mov r7, r0 */
/* @0xfa4cc bl 0xf9e08 <_ZN7CFontGMC2EPKcibbii> */
/* @0xfa4d0 ldr r3, [r4] */
/* @0xfa4d4 mov r1, #256 */
/* @0xfa4d8 ldr r2, [r6, #0x4] */
/* @0xfa4dc add r6, sp, #28 */
/* @0xfa4e0 sub lr, r3, #-1073741823 */
/* @0xfa4e4 sub r3, r3, #1 */
/* @0xfa4e8 mov r0, r6 */
/* @0xfa4ec str r7, [r2, lr, lsl #2] */
/* @0xfa4f0 ldr r2, [pc, #0xac] */
/* @0xfa4f4 add r2, pc, r2 */
/* @0xfa4f8 bl 0xb65c8 <snprintf@plt> */
/* @0xfa4fc ldr r3, [r4] */
/* @0xfa500 mov r0, r6 */
/* @0xfa504 ldr r5, [r5] */
/* @0xfa508 sub r6, r3, #-1073741823 */
/* @0xfa50c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xfa510 ldr r1, [sp, #0x14] */
/* @0xfa514 ldr r3, [r4] */
/* @0xfa518 ldr r2, [sp, #0x11c] */
/* @0xfa51c str r0, [r5, r6, lsl #2] */
/* @0xfa520 sub r0, r3, #1 */
/* @0xfa524 ldr r3, [r1] */
/* @0xfa528 cmp r2, r3 */
/* @0xfa52c bne 0xfa58c <_Z8Font_AddPKcibbii+0x150> */
/* @0xfa530 add sp, sp, #292 */
/* @0xfa534 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xfa538 ldr r12, [pc, #0x68] */
/* @0xfa53c add r1, r2, #5 */
/* @0xfa540 add r0, r6, #4 */
/* @0xfa544 movw r3, #0x101 */
/* @0xfa548 add r12, pc, r12 */
/* @0xfa54c lsl r1, r1, #2 */
/* @0xfa550 mov r2, r12 */
/* @0xfa554 mov r7, r12 */
/* @0xfa558 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xfa55c ldr r0, [pc, #0x3c] */
/* @0xfa560 ldr r1, [r4] */
/* @0xfa564 movw r3, #0x103 */
/* @0xfa568 mov r2, r7 */
/* @0xfa56c add r1, r1, #5 */
/* @0xfa570 str r1, [r6] */
/* @0xfa574 ldr r5, [r5, r0] */
/* @0xfa578 lsl r1, r1, #2 */
/* @0xfa57c mov r0, r5 */
/* @0xfa580 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xfa584 ldr r3, [r4] */
/* @0xfa588 b 0xfa498 <_Z8Font_AddPKcibbii+0x5c> */
/* @0xfa58c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xfa590 .word 0x002f77fc */
/* @0xfa594 .word 0xffffbd00 */
/* @0xfa598 .word 0xffffc210 */
/* @0xfa59c .word 0xffffc20c */
/* @0xfa5a0 .word 0xffffc214 */
/* @0xfa5a4 mlaeq r3, r12, r6, sp */
/* @0xfa5a8 eoreq sp, r3, r4, lsl r6 */

/* ── FUNC 0xfa5ac · Font_AddSprite(int, int, bool, int) · size=508 · insn=127 */
/* @0xfa5ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xfa5b0 add r11, sp, #32 */
/* @0xfa5b4 ldr r10, [pc, #0x1cc] */
/* @0xfa5b8 sub sp, sp, #300 */
/* @0xfa5bc str r0, [r11, #-0x134] */
/* @0xfa5c0 ldr r0, [pc, #0x1c4] */
/* @0xfa5c4 add r10, pc, r10 */
/* @0xfa5c8 str r2, [r11, #-0x140] */
/* @0xfa5cc mov r4, r1 */
/* @0xfa5d0 str r3, [r11, #-0x144] */
/* @0xfa5d4 ldr r0, [r10, r0] */
/* @0xfa5d8 ldr r1, [pc, #0x1b0] */
/* @0xfa5dc ldr r2, [pc, #0x1b0] */
/* @0xfa5e0 ldr r3, [r0] */
/* @0xfa5e4 str r0, [r11, #-0x138] */
/* @0xfa5e8 str r3, [r11, #-0x28] */
/* @0xfa5ec ldr r1, [r10, r1] */
/* @0xfa5f0 str r1, [r11, #-0x130] */
/* @0xfa5f4 ldr r6, [r10, r2] */
/* @0xfa5f8 ldr r2, [r1] */
/* @0xfa5fc ldr r3, [r6] */
/* @0xfa600 cmp r2, r3 */
/* @0xfa604 beq 0xfa724 <_Z14Font_AddSpriteiibi+0x178> */
/* @0xfa608 ldr r2, [pc, #0x188] */
/* @0xfa60c ldr r2, [r10, r2] */
/* @0xfa610 str r2, [r11, #-0x13c] */
/* @0xfa614 ldr r0, [r11, #-0x134] */
/* @0xfa618 add r3, r3, #1 */
/* @0xfa61c str r3, [r6] */
/* @0xfa620 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0xfa624 ldr r2, [r0, #0x18] */
/* @0xfa628 mov r8, r0 */
/* @0xfa62c cmp r2, #0 */
/* @0xfa630 lsl r2, r2, #2 */
/* @0xfa634 add r2, r2, #18 */
/* @0xfa638 bic r2, r2, #7 */
/* @0xfa63c sub sp, sp, r2 */
/* @0xfa640 add r7, sp, #8 */
/* @0xfa644 str r7, [r11, #-0x12c] */
/* @0xfa648 ble 0xfa77c <_Z14Font_AddSpriteiibi+0x1d0> */
/* @0xfa64c ldr r1, [pc, #0x148] */
/* @0xfa650 sub r5, r11, #300 */
/* @0xfa654 lsl r9, r4, #1 */
/* @0xfa658 mov r4, #0 */
/* @0xfa65c ldr r10, [r10, r1] */
/* @0xfa660 ldr r3, [r10] */
/* @0xfa664 mov r0, r5 */
/* @0xfa668 add r4, r4, #1 */
/* @0xfa66c ldrh r1, [r3, r9] */
/* @0xfa670 add r9, r9, #2 */
/* @0xfa674 bl 0x10fe28 <utf8_add_char> */
/* @0xfa678 ldr r3, [r8, #0x18] */
/* @0xfa67c cmp r3, r4 */
/* @0xfa680 bgt 0xfa660 <_Z14Font_AddSpriteiibi+0xb4> */
/* @0xfa684 ldr r2, [r11, #-0x12c] */
/* @0xfa688 mov r3, #0 */
/* @0xfa68c mov r0, #144 */
/* @0xfa690 strb r3, [r2] */
/* @0xfa694 sub r5, r11, #296 */
/* @0xfa698 bl 0x27c524 <_Znwj> */
/* @0xfa69c ldr r12, [r11, #-0x144] */
/* @0xfa6a0 ldr r1, [r11, #-0x134] */
/* @0xfa6a4 mov r2, r7 */
/* @0xfa6a8 ldr r3, [r11, #-0x140] */
/* @0xfa6ac str r12, [sp] */
/* @0xfa6b0 mov r4, r0 */
/* @0xfa6b4 bl 0xf7270 <_ZN7CFontGMC2EiPKcbi> */
/* @0xfa6b8 ldr r0, [r11, #-0x130] */
/* @0xfa6bc mov r1, #256 */
/* @0xfa6c0 ldr r3, [r6] */
/* @0xfa6c4 ldr r2, [pc, #0xd4] */
/* @0xfa6c8 ldr r12, [r0, #0x4] */
/* @0xfa6cc sub lr, r3, #-1073741823 */
/* @0xfa6d0 add r2, pc, r2 */
/* @0xfa6d4 mov r0, r5 */
/* @0xfa6d8 sub r3, r3, #1 */
/* @0xfa6dc str r4, [r12, lr, lsl #2] */
/* @0xfa6e0 bl 0xb65c8 <snprintf@plt> */
/* @0xfa6e4 ldr r12, [r11, #-0x13c] */
/* @0xfa6e8 ldr r3, [r6] */
/* @0xfa6ec mov r0, r5 */
/* @0xfa6f0 ldr r4, [r12] */
/* @0xfa6f4 sub r5, r3, #-1073741823 */
/* @0xfa6f8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xfa6fc ldr r12, [r11, #-0x138] */
/* @0xfa700 ldr r3, [r6] */
/* @0xfa704 ldr r2, [r11, #-0x28] */
/* @0xfa708 str r0, [r4, r5, lsl #2] */
/* @0xfa70c sub r0, r3, #1 */
/* @0xfa710 ldr r3, [r12] */
/* @0xfa714 cmp r2, r3 */
/* @0xfa718 bne 0xfa784 <_Z14Font_AddSpriteiibi+0x1d8> */
/* @0xfa71c sub sp, r11, #32 */
/* @0xfa720 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xfa724 ldr r5, [pc, #0x78] */
/* @0xfa728 add r1, r2, #5 */
/* @0xfa72c ldr r12, [r11, #-0x130] */
/* @0xfa730 movw r3, #0x121 */
/* @0xfa734 add r5, pc, r5 */
/* @0xfa738 lsl r1, r1, #2 */
/* @0xfa73c add r0, r12, #4 */
/* @0xfa740 mov r2, r5 */
/* @0xfa744 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xfa748 ldr r12, [r11, #-0x130] */
/* @0xfa74c ldr r0, [pc, #0x44] */
/* @0xfa750 movw r3, #0x123 */
/* @0xfa754 ldr r1, [r6] */
/* @0xfa758 mov r2, r5 */
/* @0xfa75c add r1, r1, #5 */
/* @0xfa760 str r1, [r12] */
/* @0xfa764 ldr r0, [r10, r0] */
/* @0xfa768 lsl r1, r1, #2 */
/* @0xfa76c str r0, [r11, #-0x13c] */
/* @0xfa770 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xfa774 ldr r3, [r6] */
/* @0xfa778 b 0xfa614 <_Z14Font_AddSpriteiibi+0x68> */
/* @0xfa77c mov r2, r7 */
/* @0xfa780 b 0xfa688 <_Z14Font_AddSpriteiibi+0xdc> */
/* @0xfa784 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xfa788 eoreq r7, pc, r12, lsl #13 */
/* @0xfa78c .word 0xffffbd00 */
/* @0xfa790 .word 0xffffc20c */
/* @0xfa794 .word 0xffffc210 */
/* @0xfa798 .word 0xffffc214 */
/* @0xfa79c .word 0xffffc218 */
/* @0xfa7a0 eoreq sp, r3, r0, asr #9 */
/* @0xfa7a4 eoreq sp, r3, r8, lsr #8 */

/* ── FUNC 0xfa7a8 · Font_AddSpriteExt(int, char const*, bool, int) · size=352 · insn=88 */
/* @0xfa7a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xfa7ac mov r10, r0 */
/* @0xfa7b0 ldr r5, [pc, #0x134] */
/* @0xfa7b4 mov r9, r1 */
/* @0xfa7b8 ldr r0, [pc, #0x130] */
/* @0xfa7bc mov r8, r2 */
/* @0xfa7c0 add r5, pc, r5 */
/* @0xfa7c4 ldr r1, [pc, #0x128] */
/* @0xfa7c8 ldr r2, [pc, #0x128] */
/* @0xfa7cc mov r11, r3 */
/* @0xfa7d0 ldr r0, [r5, r0] */
/* @0xfa7d4 sub sp, sp, #284 */
/* @0xfa7d8 ldr r3, [r0] */
/* @0xfa7dc str r0, [sp, #0xc] */
/* @0xfa7e0 str r3, [sp, #0x114] */
/* @0xfa7e4 ldr r6, [r5, r1] */
/* @0xfa7e8 ldr r4, [r5, r2] */
/* @0xfa7ec ldr r1, [r6] */
/* @0xfa7f0 ldr r3, [r4] */
/* @0xfa7f4 cmp r1, r3 */
/* @0xfa7f8 beq 0xfa894 <_Z17Font_AddSpriteExtiPKcbi+0xec> */
/* @0xfa7fc ldr r2, [pc, #0xf8] */
/* @0xfa800 ldr r5, [r5, r2] */
/* @0xfa804 mov r0, #144 */
/* @0xfa808 add r3, r3, #1 */
/* @0xfa80c str r3, [r4] */
/* @0xfa810 bl 0x27c524 <_Znwj> */
/* @0xfa814 mov r1, r10 */
/* @0xfa818 mov r2, r9 */
/* @0xfa81c mov r3, r8 */
/* @0xfa820 str r11, [sp] */
/* @0xfa824 mov r7, r0 */
/* @0xfa828 bl 0xf7270 <_ZN7CFontGMC2EiPKcbi> */
/* @0xfa82c ldr r3, [r4] */
/* @0xfa830 mov r1, #256 */
/* @0xfa834 ldr r2, [r6, #0x4] */
/* @0xfa838 add r6, sp, #20 */
/* @0xfa83c sub lr, r3, #-1073741823 */
/* @0xfa840 sub r3, r3, #1 */
/* @0xfa844 mov r0, r6 */
/* @0xfa848 str r7, [r2, lr, lsl #2] */
/* @0xfa84c ldr r2, [pc, #0xac] */
/* @0xfa850 add r2, pc, r2 */
/* @0xfa854 bl 0xb65c8 <snprintf@plt> */
/* @0xfa858 ldr r3, [r4] */
/* @0xfa85c mov r0, r6 */
/* @0xfa860 ldr r5, [r5] */
/* @0xfa864 sub r6, r3, #-1073741823 */
/* @0xfa868 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xfa86c ldr r1, [sp, #0xc] */
/* @0xfa870 ldr r3, [r4] */
/* @0xfa874 ldr r2, [sp, #0x114] */
/* @0xfa878 str r0, [r5, r6, lsl #2] */
/* @0xfa87c sub r0, r3, #1 */
/* @0xfa880 ldr r3, [r1] */
/* @0xfa884 cmp r2, r3 */
/* @0xfa888 bne 0xfa8e8 <_Z17Font_AddSpriteExtiPKcbi+0x140> */
/* @0xfa88c add sp, sp, #284 */
/* @0xfa890 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xfa894 ldr r12, [pc, #0x68] */
/* @0xfa898 add r1, r1, #5 */
/* @0xfa89c add r0, r6, #4 */
/* @0xfa8a0 movw r3, #0x14f */
/* @0xfa8a4 add r12, pc, r12 */
/* @0xfa8a8 lsl r1, r1, #2 */
/* @0xfa8ac mov r2, r12 */
/* @0xfa8b0 mov r7, r12 */
/* @0xfa8b4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xfa8b8 ldr r0, [pc, #0x3c] */
/* @0xfa8bc ldr r1, [r4] */
/* @0xfa8c0 movw r3, #0x151 */
/* @0xfa8c4 mov r2, r7 */
/* @0xfa8c8 add r1, r1, #5 */
/* @0xfa8cc str r1, [r6] */
/* @0xfa8d0 ldr r5, [r5, r0] */
/* @0xfa8d4 lsl r1, r1, #2 */
/* @0xfa8d8 mov r0, r5 */
/* @0xfa8dc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xfa8e0 ldr r3, [r4] */
/* @0xfa8e4 b 0xfa804 <_Z17Font_AddSpriteExtiPKcbi+0x5c> */
/* @0xfa8e8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xfa8ec mlaeq pc, r0, r4, r7 */
/* @0xfa8f0 .word 0xffffbd00 */
/* @0xfa8f4 .word 0xffffc20c */
/* @0xfa8f8 .word 0xffffc210 */
/* @0xfa8fc .word 0xffffc214 */
/* @0xfa900 eoreq sp, r3, r0, asr #6 */
/* @0xfa904 .word 0x0023d2b8 */

/* ── FUNC 0xfa908 · Font_Replace(int, char const*, int, bool, bool, int, int) · size=188 · insn=47 */
/* @0xfa908 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfa90c subs r4, r0, #0 */
/* @0xfa910 sub sp, sp, #16 */
/* @0xfa914 mov r8, r1 */
/* @0xfa918 mov r7, r2 */
/* @0xfa91c mov r6, r3 */
/* @0xfa920 ldrb r9, [sp, #0x30] */
/* @0xfa924 blt 0xfa93c <_Z12Font_ReplaceiPKcibbii+0x34> */
/* @0xfa928 ldr r12, [pc, #0x8c] */
/* @0xfa92c ldr r12, [pc, r12] */
/* @0xfa930 ldr r0, [r12] */
/* @0xfa934 cmp r4, r0 */
/* @0xfa938 blt 0xfa948 <_Z12Font_ReplaceiPKcibbii+0x40> */
/* @0xfa93c mov r0, #0 */
/* @0xfa940 add sp, sp, #16 */
/* @0xfa944 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xfa948 mov r0, #144 */
/* @0xfa94c ldr r5, [pc, #0x6c] */
/* @0xfa950 bl 0x27c524 <_Znwj> */
/* @0xfa954 ldr r3, [sp, #0x34] */
/* @0xfa958 mov r2, r7 */
/* @0xfa95c str r9, [sp] */
/* @0xfa960 mov r1, r8 */
/* @0xfa964 str r3, [sp, #0x4] */
/* @0xfa968 ldr r3, [sp, #0x38] */
/* @0xfa96c str r3, [sp, #0x8] */
/* @0xfa970 mov r3, r6 */
/* @0xfa974 lsl r6, r4, #2 */
/* @0xfa978 mov r10, r0 */
/* @0xfa97c bl 0xf9e08 <_ZN7CFontGMC2EPKcibbii> */
/* @0xfa980 ldr r5, [pc, r5] */
/* @0xfa984 ldr r3, [r5, #0x4] */
/* @0xfa988 add r2, r3, r6 */
/* @0xfa98c ldr r0, [r3, r4, lsl #2] */
/* @0xfa990 cmp r0, #0 */
/* @0xfa994 beq 0xfa9ac <_Z12Font_ReplaceiPKcibbii+0xa4> */
/* @0xfa998 ldr r3, [r0] */
/* @0xfa99c ldr r3, [r3, #0x4] */
/* @0xfa9a0 blx r3 */
/* @0xfa9a4 ldr r2, [r5, #0x4] */
/* @0xfa9a8 add r2, r2, r6 */
/* @0xfa9ac mov r0, #1 */
/* @0xfa9b0 str r10, [r2] */
/* @0xfa9b4 add sp, sp, #16 */
/* @0xfa9b8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xfa9bc eoreq r3, pc, r4, lsr r5 */
/* @0xfa9c0 .word 0x002f34dc */

/* ── FUNC 0xfa9c4 · Font_ReplaceSprite(int, int, int, bool, int) · size=328 · insn=82 */
/* @0xfa9c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xfa9c8 add r11, sp, #32 */
/* @0xfa9cc ldr r4, [pc, #0x12c] */
/* @0xfa9d0 sub sp, sp, #28 */
/* @0xfa9d4 str r3, [r11, #-0x30] */
/* @0xfa9d8 ldr r4, [pc, r4] */
/* @0xfa9dc subs r7, r0, #0 */
/* @0xfa9e0 mov r8, r1 */
/* @0xfa9e4 mov r6, r2 */
/* @0xfa9e8 ldr r3, [r4] */
/* @0xfa9ec str r3, [r11, #-0x28] */
/* @0xfa9f0 blt 0xfaa08 <_Z18Font_ReplaceSpriteiiibi+0x44> */
/* @0xfa9f4 ldr r3, [pc, #0x108] */
/* @0xfa9f8 ldr r3, [pc, r3] */
/* @0xfa9fc ldr r3, [r3] */
/* @0xfaa00 cmp r7, r3 */
/* @0xfaa04 blt 0xfaa24 <_Z18Font_ReplaceSpriteiiibi+0x60> */
/* @0xfaa08 mov r0, #0 */
/* @0xfaa0c ldr r2, [r11, #-0x28] */
/* @0xfaa10 ldr r3, [r4] */
/* @0xfaa14 cmp r2, r3 */
/* @0xfaa18 bne 0xfaafc <_Z18Font_ReplaceSpriteiiibi+0x138> */
/* @0xfaa1c sub sp, r11, #32 */
/* @0xfaa20 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xfaa24 mov r0, r1 */
/* @0xfaa28 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0xfaa2c ldr r3, [r0, #0x18] */
/* @0xfaa30 mov r9, r0 */
/* @0xfaa34 cmp r3, #0 */
/* @0xfaa38 lsl r3, r3, #2 */
/* @0xfaa3c add r3, r3, #18 */
/* @0xfaa40 bic r3, r3, #7 */
/* @0xfaa44 sub sp, sp, r3 */
/* @0xfaa48 add r3, sp, #8 */
/* @0xfaa4c str r3, [r11, #-0x34] */
/* @0xfaa50 str r3, [r11, #-0x2c] */
/* @0xfaa54 ble 0xfaaf4 <_Z18Font_ReplaceSpriteiiibi+0x130> */
/* @0xfaa58 uxth r6, r6 */
/* @0xfaa5c sub r5, r11, #44 */
/* @0xfaa60 mov r10, #0 */
/* @0xfaa64 add r1, r6, r10 */
/* @0xfaa68 mov r0, r5 */
/* @0xfaa6c add r10, r10, #1 */
/* @0xfaa70 uxth r1, r1 */
/* @0xfaa74 bl 0x10fe28 <utf8_add_char> */
/* @0xfaa78 ldr r2, [r9, #0x18] */
/* @0xfaa7c cmp r2, r10 */
/* @0xfaa80 bgt 0xfaa64 <_Z18Font_ReplaceSpriteiiibi+0xa0> */
/* @0xfaa84 ldr r2, [r11, #-0x2c] */
/* @0xfaa88 mov r3, #0 */
/* @0xfaa8c mov r0, #144 */
/* @0xfaa90 strb r3, [r2] */
/* @0xfaa94 lsl r5, r7, #2 */
/* @0xfaa98 bl 0x27c524 <_Znwj> */
/* @0xfaa9c ldr r3, [r11, #0x4] */
/* @0xfaaa0 ldr r6, [pc, #0x60] */
/* @0xfaaa4 mov r1, r8 */
/* @0xfaaa8 ldr r2, [r11, #-0x34] */
/* @0xfaaac str r3, [sp] */
/* @0xfaab0 ldr r3, [r11, #-0x30] */
/* @0xfaab4 mov r9, r0 */
/* @0xfaab8 bl 0xf7270 <_ZN7CFontGMC2EiPKcbi> */
/* @0xfaabc ldr r6, [pc, r6] */
/* @0xfaac0 ldr r3, [r6, #0x4] */
/* @0xfaac4 add r2, r3, r5 */
/* @0xfaac8 ldr r0, [r3, r7, lsl #2] */
/* @0xfaacc cmp r0, #0 */
/* @0xfaad0 beq 0xfaae8 <_Z18Font_ReplaceSpriteiiibi+0x124> */
/* @0xfaad4 ldr r3, [r0] */
/* @0xfaad8 ldr r3, [r3, #0x4] */
/* @0xfaadc blx r3 */
/* @0xfaae0 ldr r2, [r6, #0x4] */
/* @0xfaae4 add r2, r2, r5 */
/* @0xfaae8 str r9, [r2] */
/* @0xfaaec mov r0, #1 */
/* @0xfaaf0 b 0xfaa0c <_Z18Font_ReplaceSpriteiiibi+0x48> */
/* @0xfaaf4 ldr r2, [r11, #-0x34] */
/* @0xfaaf8 b 0xfaa88 <_Z18Font_ReplaceSpriteiiibi+0xc4> */
/* @0xfaafc bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xfab00 eoreq r2, pc, r8, ror pc */
/* @0xfab04 eoreq r3, pc, r8, ror #8 */
/* @0xfab08 eoreq r3, pc, r0, lsr #7 */

/* ── FUNC 0xfab0c · Font_ReplaceSpriteExt(int, int, char const*, bool, int) · size=172 · insn=43 */
/* @0xfab0c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfab10 subs r4, r0, #0 */
/* @0xfab14 sub sp, sp, #12 */
/* @0xfab18 mov r8, r1 */
/* @0xfab1c mov r7, r2 */
/* @0xfab20 mov r6, r3 */
/* @0xfab24 blt 0xfab3c <_Z21Font_ReplaceSpriteExtiiPKcbi+0x30> */
/* @0xfab28 ldr r12, [pc, #0x80] */
/* @0xfab2c ldr r12, [pc, r12] */
/* @0xfab30 ldr r0, [r12] */
/* @0xfab34 cmp r4, r0 */
/* @0xfab38 blt 0xfab48 <_Z21Font_ReplaceSpriteExtiiPKcbi+0x3c> */
/* @0xfab3c mov r0, #0 */
/* @0xfab40 add sp, sp, #12 */
/* @0xfab44 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xfab48 mov r0, #144 */
/* @0xfab4c ldr r5, [pc, #0x60] */
/* @0xfab50 bl 0x27c524 <_Znwj> */
/* @0xfab54 ldr r3, [sp, #0x28] */
/* @0xfab58 mov r2, r7 */
/* @0xfab5c mov r1, r8 */
/* @0xfab60 str r3, [sp] */
/* @0xfab64 mov r3, r6 */
/* @0xfab68 lsl r6, r4, #2 */
/* @0xfab6c mov r9, r0 */
/* @0xfab70 bl 0xf7270 <_ZN7CFontGMC2EiPKcbi> */
/* @0xfab74 ldr r5, [pc, r5] */
/* @0xfab78 ldr r3, [r5, #0x4] */
/* @0xfab7c add r2, r3, r6 */
/* @0xfab80 ldr r0, [r3, r4, lsl #2] */
/* @0xfab84 cmp r0, #0 */
/* @0xfab88 beq 0xfaba0 <_Z21Font_ReplaceSpriteExtiiPKcbi+0x94> */
/* @0xfab8c ldr r3, [r0] */
/* @0xfab90 ldr r3, [r3, #0x4] */
/* @0xfab94 blx r3 */
/* @0xfab98 ldr r2, [r5, #0x4] */
/* @0xfab9c add r2, r2, r6 */
/* @0xfaba0 mov r0, #1 */
/* @0xfaba4 str r9, [r2] */
/* @0xfaba8 add sp, sp, #12 */
/* @0xfabac pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xfabb0 eoreq r3, pc, r4, lsr r3 */
/* @0xfabb4 eoreq r3, pc, r8, ror #5 */

/* ── FUNC 0xfabb8 · Font_Delete(int) · size=136 · insn=34 */
/* @0xfabb8 push {r3, r4, r5, r6, r7, lr} */
/* @0xfabbc subs r4, r0, #0 */
/* @0xfabc0 blt 0xfac2c <_Z11Font_Deletei+0x74> */
/* @0xfabc4 ldr r3, [pc, #0x68] */
/* @0xfabc8 ldr r3, [pc, r3] */
/* @0xfabcc ldr r3, [r3] */
/* @0xfabd0 cmp r4, r3 */
/* @0xfabd4 bge 0xfac2c <_Z11Font_Deletei+0x74> */
/* @0xfabd8 ldr r5, [pc, #0x58] */
/* @0xfabdc ldr r5, [pc, r5] */
/* @0xfabe0 ldr r3, [r5, #0x4] */
/* @0xfabe4 ldr r0, [r3, r4, lsl #2] */
/* @0xfabe8 cmp r0, #0 */
/* @0xfabec popeq {r3, r4, r5, r6, r7, pc} */
/* @0xfabf0 ldr r3, [r0] */
/* @0xfabf4 mov r7, #0 */
/* @0xfabf8 ldr r6, [pc, #0x3c] */
/* @0xfabfc ldr r3, [r3, #0x4] */
/* @0xfac00 blx r3 */
/* @0xfac04 ldr r3, [r5, #0x4] */
/* @0xfac08 ldr r6, [pc, r6] */
/* @0xfac0c str r7, [r3, r4, lsl #2] */
/* @0xfac10 ldr r3, [r6] */
/* @0xfac14 ldr r0, [r3, r4, lsl #2] */
/* @0xfac18 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfac1c ldr r3, [r6] */
/* @0xfac20 mov r0, #1 */
/* @0xfac24 str r7, [r3, r4, lsl #2] */
/* @0xfac28 pop {r3, r4, r5, r6, r7, pc} */
/* @0xfac2c mov r0, #0 */
/* @0xfac30 pop {r3, r4, r5, r6, r7, pc} */
/* @0xfac34 mlaeq pc, r8, r2, r3 */
/* @0xfac38 eoreq r3, pc, r0, lsl #5 */
/* @0xfac3c eoreq r3, pc, r12, asr r2 */

/* ── FUNC 0xfac40 · Font_InitTextures() · size=84 · insn=21 */
/* @0xfac40 push {r4, r5, r6, lr} */
/* @0xfac44 ldr r5, [pc, #0x40] */
/* @0xfac48 ldr r5, [pc, r5] */
/* @0xfac4c ldr r3, [r5] */
/* @0xfac50 cmp r3, #0 */
/* @0xfac54 pople {r4, r5, r6, pc} */
/* @0xfac58 ldr r6, [pc, #0x30] */
/* @0xfac5c mov r4, #0 */
/* @0xfac60 ldr r6, [pc, r6] */
/* @0xfac64 ldr r3, [r6, #0x4] */
/* @0xfac68 ldr r0, [r3, r4, lsl #2] */
/* @0xfac6c add r4, r4, #1 */
/* @0xfac70 cmp r0, #0 */
/* @0xfac74 beq 0xfac7c <_Z17Font_InitTexturesv+0x3c> */
/* @0xfac78 bl 0xf7db4 <_ZN7CFontGM11InitTextureEv> */
/* @0xfac7c ldr r3, [r5] */
/* @0xfac80 cmp r3, r4 */
/* @0xfac84 bgt 0xfac64 <_Z17Font_InitTexturesv+0x24> */
/* @0xfac88 pop {r4, r5, r6, pc} */
/* @0xfac8c eoreq r3, pc, r8, lsl r2 */
/* @0xfac90 .word 0x002f31fc */

/* ── FUNC 0xfac94 · Font_FreeTextures() · size=84 · insn=21 */
/* @0xfac94 push {r4, r5, r6, lr} */
/* @0xfac98 ldr r5, [pc, #0x40] */
/* @0xfac9c ldr r5, [pc, r5] */
/* @0xfaca0 ldr r3, [r5] */
/* @0xfaca4 cmp r3, #0 */
/* @0xfaca8 pople {r4, r5, r6, pc} */
/* @0xfacac ldr r6, [pc, #0x30] */
/* @0xfacb0 mov r4, #0 */
/* @0xfacb4 ldr r6, [pc, r6] */
/* @0xfacb8 ldr r3, [r6, #0x4] */
/* @0xfacbc ldr r0, [r3, r4, lsl #2] */
/* @0xfacc0 add r4, r4, #1 */
/* @0xfacc4 cmp r0, #0 */
/* @0xfacc8 beq 0xfacd0 <_Z17Font_FreeTexturesv+0x3c> */
/* @0xfaccc bl 0xf707c <_ZN7CFontGM11FreeTextureEv> */
/* @0xfacd0 ldr r3, [r5] */
/* @0xfacd4 cmp r3, r4 */
/* @0xfacd8 bgt 0xfacb8 <_Z17Font_FreeTexturesv+0x24> */
/* @0xfacdc pop {r4, r5, r6, pc} */
/* @0xface0 eoreq r3, pc, r4, asr #3 */
/* @0xface4 eoreq r3, pc, r8, lsr #3 */

/* ── FUNC 0xface8 · FINALIZE_Font_Main() · size=16 · insn=4 */
/* @0xface8 push {r3, lr} */
/* @0xfacec bl 0xfac94 <_Z17Font_FreeTexturesv> */
/* @0xfacf0 pop {r3, lr} */
/* @0xfacf4 b 0xf9fb4 <_Z9Font_Initv> */

/* ── FUNC 0xfacf8 · F_DsSetPrecision(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0xfacf8 push {r3, lr} */
/* @0xfacfc mov r1, #0 */
/* @0xfad00 ldr r0, [sp, #0x8] */
/* @0xfad04 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfad08 pop {r3, lr} */
/* @0xfad0c b 0x2026a8 <_Z15DS_SetPrecisiond> */

/* ── FUNC 0xfad10 · F_DsQueueCreate(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0xfad10 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xfad14 mov r7, r0 */
/* @0xfad18 ldr r3, [pc, #0xe8] */
/* @0xfad1c ldr r2, [pc, #0xe8] */
/* @0xfad20 add r3, pc, r3 */
/* @0xfad24 ldr r9, [r3, r2] */
/* @0xfad28 ldr r2, [pc, #0xe0] */
/* @0xfad2c ldr r5, [r9] */
/* @0xfad30 ldr r8, [r3, r2] */
/* @0xfad34 cmp r5, #0 */
/* @0xfad38 ble 0xfad70 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xfad3c ldr r3, [r8, #0x4] */
/* @0xfad40 ldr r6, [r3] */
/* @0xfad44 cmp r6, #0 */
/* @0xfad48 beq 0xfae00 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0xfad4c mov r4, #0 */
/* @0xfad50 b 0xfad60 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0xfad54 ldr r2, [r3, #0x4]! */
/* @0xfad58 cmp r2, #0 */
/* @0xfad5c beq 0xfad90 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfad60 add r4, r4, #1 */
/* @0xfad64 cmp r4, r5 */
/* @0xfad68 lsl r6, r4, #2 */
/* @0xfad6c bne 0xfad54 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0xfad70 ldr r3, [r8] */
/* @0xfad74 cmp r5, r3 */
/* @0xfad78 movlt r3, r5 */
/* @0xfad7c bge 0xfadc4 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfad80 lsl r6, r5, #2 */
/* @0xfad84 mov r4, r5 */
/* @0xfad88 add r3, r3, #1 */
/* @0xfad8c str r3, [r9] */
/* @0xfad90 mov r0, #20 */
/* @0xfad94 bl 0x27c524 <_Znwj> */
/* @0xfad98 mov r5, r0 */
/* @0xfad9c bl 0x20ed58 <_ZN9CDS_QueueC2Ev> */
/* @0xfada0 vmov s15, r4 */
/* @0xfada4 ldr r0, [r8, #0x4] */
/* @0xfada8 mov r1, #0 */
/* @0xfadac vcvt.f64.s32 d7, s15 */
/* @0xfadb0 str r5, [r0, r6] */
/* @0xfadb4 str r1, [r7, #0xc] */
/* @0xfadb8 vmov r2, r3, d7 */
/* @0xfadbc stm r7, {r2, r3} */
/* @0xfadc0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xfadc4 add r1, r5, #16 */
/* @0xfadc8 ldr r2, [pc, #0x44] */
/* @0xfadcc movw r3, #0x182 */
/* @0xfadd0 add r0, r8, #4 */
/* @0xfadd4 add r2, pc, r2 */
/* @0xfadd8 lsl r1, r1, #2 */
/* @0xfaddc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0xfade0 ldr r3, [r9] */
/* @0xfade4 lsl r6, r5, #2 */
/* @0xfade8 mov r4, r5 */
/* @0xfadec add r2, r3, #16 */
/* @0xfadf0 add r3, r3, #1 */
/* @0xfadf4 str r2, [r8] */
/* @0xfadf8 str r3, [r9] */
/* @0xfadfc b 0xfad90 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfae00 mov r4, r6 */
/* @0xfae04 b 0xfad90 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfae08 eoreq r6, pc, r0, lsr pc */
/* @0xfae0c .word 0xffffc21c */
/* @0xfae10 .word 0xffffc220 */
/* @0xfae14 eoreq r12, r3, r8, asr #27 */

/* ── FUNC 0xfae18 · anon_fae18 · size=488 · insn=123 */
/* @0xfae18 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xfae1c add r11, sp, #32 */
/* @0xfae20 ldr r1, [pc, #0x1c8] */
/* @0xfae24 sub sp, sp, #252 */
/* @0xfae28 sub r0, r11, #36 */
/* @0xfae2c ldr r1, [pc, r1] */
/* @0xfae30 mov r3, #0 */
/* @0xfae34 str r3, [r0, #-0xe4]! */
/* @0xfae38 sub r8, r11, #260 */
/* @0xfae3c ldr r3, [r1] */
/* @0xfae40 sub r7, r11, #248 */
/* @0xfae44 str r1, [r11, #-0x114] */
/* @0xfae48 sub r6, r11, #144 */
/* @0xfae4c ldr r5, [pc, #0x1a0] */
/* @0xfae50 str r3, [r11, #-0x28] */
/* @0xfae54 bl 0x15f574 <_Z6YYUDIDPPc> */
/* @0xfae58 ldr r4, [r11, #-0x108] */
/* @0xfae5c add r5, pc, r5 */
/* @0xfae60 mov r0, r4 */
/* @0xfae64 bl 0xb6538 <strlen@plt> */
/* @0xfae68 str r0, [r11, #-0x110] */
/* @0xfae6c mov r1, r0 */
/* @0xfae70 mov r0, #2 */
/* @0xfae74 bl 0x318dec <__aeabi_idivmod> */
/* @0xfae78 ldrb r0, [r4, r1] */
/* @0xfae7c ldr r1, [r11, #-0x110] */
/* @0xfae80 bl 0x318dec <__aeabi_idivmod> */
/* @0xfae84 mov r0, r8 */
/* @0xfae88 tst r1, #1 */
/* @0xfae8c mov r10, r1 */
/* @0xfae90 ldrb r2, [r4, r1] */
/* @0xfae94 mov r4, #0 */
/* @0xfae98 ldr r1, [pc, #0x158] */
/* @0xfae9c eoreq r2, r2, #41 */
/* @0xfaea0 eorne r2, r2, #154 */
/* @0xfaea4 add r1, pc, r1 */
/* @0xfaea8 bl 0xb6550 <sprintf@plt> */
/* @0xfaeac ldr r3, [r11, #-0x110] */
/* @0xfaeb0 add r2, r3, #18 */
/* @0xfaeb4 ldr r3, [r11, #-0x108] */
/* @0xfaeb8 bic r2, r2, #7 */
/* @0xfaebc sub sp, sp, r2 */
/* @0xfaec0 mov r2, r10 */
/* @0xfaec4 mov r1, r3 */
/* @0xfaec8 str r3, [r11, #-0x11c] */
/* @0xfaecc mov r0, sp */
/* @0xfaed0 bl 0xb65bc <memcpy@plt> */
/* @0xfaed4 mov r0, r8 */
/* @0xfaed8 bl 0xb6538 <strlen@plt> */
/* @0xfaedc mov r1, r8 */
/* @0xfaee0 mov r12, r0 */
/* @0xfaee4 add r0, sp, r10 */
/* @0xfaee8 mov r2, r12 */
/* @0xfaeec str r12, [r11, #-0x118] */
/* @0xfaef0 bl 0xb65bc <memcpy@plt> */
/* @0xfaef4 ldr r12, [r11, #-0x118] */
/* @0xfaef8 ldr r1, [r11, #-0x110] */
/* @0xfaefc ldr r3, [r11, #-0x11c] */
/* @0xfaf00 add r0, r10, r12 */
/* @0xfaf04 add r2, r1, #1 */
/* @0xfaf08 add r0, sp, r0 */
/* @0xfaf0c add r1, r3, r10 */
/* @0xfaf10 rsb r2, r10, r2 */
/* @0xfaf14 bl 0xb65bc <memcpy@plt> */
/* @0xfaf18 mov r0, r7 */
/* @0xfaf1c bl 0x214294 <_Z9SHA1ResetP11SHA1Context> */
/* @0xfaf20 mov r0, sp */
/* @0xfaf24 bl 0xb6538 <strlen@plt> */
/* @0xfaf28 mov r1, sp */
/* @0xfaf2c add r2, r0, #1 */
/* @0xfaf30 mov r0, r7 */
/* @0xfaf34 bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj> */
/* @0xfaf38 mov r0, r7 */
/* @0xfaf3c bl 0x2146e4 <_Z10SHA1ResultP11SHA1Context> */
/* @0xfaf40 ldr r1, [pc, #0xb4] */
/* @0xfaf44 mov r2, r10 */
/* @0xfaf48 sub r0, r11, #256 */
/* @0xfaf4c add r1, pc, r1 */
/* @0xfaf50 bl 0xb6550 <sprintf@plt> */
/* @0xfaf54 mov r0, r6 */
/* @0xfaf58 bl 0x214294 <_Z9SHA1ResetP11SHA1Context> */
/* @0xfaf5c mov r0, r8 */
/* @0xfaf60 bl 0xb6538 <strlen@plt> */
/* @0xfaf64 mov r1, r8 */
/* @0xfaf68 add r2, r0, #1 */
/* @0xfaf6c mov r0, r6 */
/* @0xfaf70 bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj> */
/* @0xfaf74 mov r0, r6 */
/* @0xfaf78 bl 0x2146e4 <_Z10SHA1ResultP11SHA1Context> */
/* @0xfaf7c ldr r1, [pc, #0x7c] */
/* @0xfaf80 mov r0, #81 */
/* @0xfaf84 movw r2, #0x696 */
/* @0xfaf88 add r1, pc, r1 */
/* @0xfaf8c mov r3, #1 */
/* @0xfaf90 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfaf94 mov r9, r0 */
/* @0xfaf98 mov r8, r0 */
/* @0xfaf9c ldr r2, [r7, r4] */
/* @0xfafa0 mov r0, r8 */
/* @0xfafa4 mov r1, r5 */
/* @0xfafa8 bl 0xb6550 <sprintf@plt> */
/* @0xfafac add r0, r8, #8 */
/* @0xfafb0 ldr r2, [r6, r4] */
/* @0xfafb4 mov r1, r5 */
/* @0xfafb8 add r4, r4, #4 */
/* @0xfafbc bl 0xb6550 <sprintf@plt> */
/* @0xfafc0 cmp r4, #20 */
/* @0xfafc4 add r8, r8, #16 */
/* @0xfafc8 bne 0xfaf9c <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x28c> */
/* @0xfafcc ldr r1, [r11, #-0x114] */
/* @0xfafd0 mov r0, r9 */
/* @0xfafd4 ldr r2, [r11, #-0x28] */
/* @0xfafd8 ldr r3, [r1] */
/* @0xfafdc cmp r2, r3 */
/* @0xfafe0 bne 0xfafec <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x2dc> */
/* @0xfafe4 sub sp, r11, #32 */
/* @0xfafe8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xfafec bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xfaff0 eoreq r2, pc, r4, lsr #22 */
/* @0xfaff4 eoreq r7, r3, r0, asr r3 */
/* @0xfaff8 eoreq r12, r3, r0, asr #26 */
/* @0xfaffc eoreq r12, r3, r0, lsr #25 */
/* @0xfb000 eoreq r12, r3, r4, lsl r12 */

/* ── FUNC 0xfb004 · F_DsMapSecureSaveBuffer(RValue&, CInstance*, CInstance*, int, RValue*) · size=444 · insn=111 */
/* @0xfb004 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfb008 sub sp, sp, #24 */
/* @0xfb00c mov r4, #0 */
/* @0xfb010 mov r8, r0 */
/* @0xfb014 ldr r5, [sp, #0x38] */
/* @0xfb018 mov r1, r4 */
/* @0xfb01c str r4, [r0, #0xc] */
/* @0xfb020 str r4, [r0] */
/* @0xfb024 str r4, [r0, #0x4] */
/* @0xfb028 mov r0, r5 */
/* @0xfb02c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfb030 mov r1, #1 */
/* @0xfb034 mov r6, r0 */
/* @0xfb038 mov r0, r5 */
/* @0xfb03c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfb040 mov r5, r0 */
/* @0xfb044 bl 0xfae18 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0xfb048 add r1, sp, #24 */
/* @0xfb04c str r4, [r1, #-0x14]! */
/* @0xfb050 mov r7, r0 */
/* @0xfb054 mov r0, r6 */
/* @0xfb058 bl 0x13c1d8 <_Z11DSMapToJSONiPPc> */
/* @0xfb05c ldr r0, [sp, #0x4] */
/* @0xfb060 subs r3, r0, r4 */
/* @0xfb064 rsbs r10, r3, #0 */
/* @0xfb068 adcs r10, r10, r3 */
/* @0xfb06c cmp r10, r4 */
/* @0xfb070 bne 0xfb1a4 <_Z23F_DsMapSecureSaveBufferR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0xfb074 bl 0xb6538 <strlen@plt> */
/* @0xfb078 movw r3, #0xaaab */
/* @0xfb07c movt r3, #0xaaaa */
/* @0xfb080 add r0, r0, #1 */
/* @0xfb084 lsl r0, r0, #2 */
/* @0xfb088 umull r2, r0, r3, r0 */
/* @0xfb08c lsr r0, r0, #1 */
/* @0xfb090 add r0, r0, #4 */
/* @0xfb094 ldr r4, [pc, #0x11c] */
/* @0xfb098 mov r3, #1 */
/* @0xfb09c movw r2, #0x6dc */
/* @0xfb0a0 add r4, pc, r4 */
/* @0xfb0a4 mov r1, r4 */
/* @0xfb0a8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfb0ac ldr r9, [sp, #0x4] */
/* @0xfb0b0 mov r6, r0 */
/* @0xfb0b4 mov r0, r9 */
/* @0xfb0b8 bl 0xb6538 <strlen@plt> */
/* @0xfb0bc mov r2, r6 */
/* @0xfb0c0 add r1, r0, #1 */
/* @0xfb0c4 mov r0, r9 */
/* @0xfb0c8 bl 0x1d1e60 <_Z13base64_encodePKcjPc> */
/* @0xfb0cc mov r0, r7 */
/* @0xfb0d0 bl 0xb6538 <strlen@plt> */
/* @0xfb0d4 mov r9, r0 */
/* @0xfb0d8 mov r0, r6 */
/* @0xfb0dc bl 0xb6538 <strlen@plt> */
/* @0xfb0e0 mov r3, #1 */
/* @0xfb0e4 mov r1, r4 */
/* @0xfb0e8 movw r2, #0x6e1 */
/* @0xfb0ec add r0, r0, r9 */
/* @0xfb0f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfb0f4 mov r9, r0 */
/* @0xfb0f8 mov r0, r7 */
/* @0xfb0fc bl 0xb6538 <strlen@plt> */
/* @0xfb100 mov r1, r7 */
/* @0xfb104 mov r2, r0 */
/* @0xfb108 mov r0, r9 */
/* @0xfb10c bl 0xb65bc <memcpy@plt> */
/* @0xfb110 mov r0, r7 */
/* @0xfb114 bl 0xb6538 <strlen@plt> */
/* @0xfb118 mov r4, r0 */
/* @0xfb11c mov r0, r6 */
/* @0xfb120 bl 0xb6538 <strlen@plt> */
/* @0xfb124 mov r1, r6 */
/* @0xfb128 mov r2, r0 */
/* @0xfb12c add r0, r9, r4 */
/* @0xfb130 add r4, sp, #8 */
/* @0xfb134 bl 0xb65bc <memcpy@plt> */
/* @0xfb138 mov r1, r9 */
/* @0xfb13c mov r3, #1 */
/* @0xfb140 mov r0, r4 */
/* @0xfb144 str r3, [sp, #0x14] */
/* @0xfb148 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xfb14c mov r2, r4 */
/* @0xfb150 mov r0, r5 */
/* @0xfb154 mov r1, #13 */
/* @0xfb158 bl 0xc7064 <_Z18YYGML_BUFFER_WriteiiRK8YYRValue> */
/* @0xfb15c vmov s15, r0 */
/* @0xfb160 mov r0, r7 */
/* @0xfb164 vcvt.f64.s32 d7, s15 */
/* @0xfb168 vmov r4, r5, d7 */
/* @0xfb16c vmov r2, s14 */
/* @0xfb170 mov r3, r5 */
/* @0xfb174 stm r8, {r2, r3} */
/* @0xfb178 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb17c cmp r10, #0 */
/* @0xfb180 bne 0xfb18c <_Z23F_DsMapSecureSaveBufferR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0xfb184 ldr r0, [sp, #0x4] */
/* @0xfb188 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb18c mov r0, r6 */
/* @0xfb190 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb194 mov r0, r9 */
/* @0xfb198 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb19c add sp, sp, #24 */
/* @0xfb1a0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xfb1a4 ldr r3, [pc, #0x10] */
/* @0xfb1a8 mov r0, #9 */
/* @0xfb1ac add r3, pc, r3 */
/* @0xfb1b0 str r3, [sp, #0x4] */
/* @0xfb1b4 b 0xfb094 <_Z23F_DsMapSecureSaveBufferR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0xfb1b8 .word 0x0023cafc */
/* @0xfb1bc eoreq r12, r3, r8, asr #20 */

/* ── FUNC 0xfb1c0 · F_DsMapSecureSave(RValue&, CInstance*, CInstance*, int, RValue*) · size=396 · insn=99 */
/* @0xfb1c0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfb1c4 sub sp, sp, #8 */
/* @0xfb1c8 mov r4, #0 */
/* @0xfb1cc str r4, [r0, #0xc] */
/* @0xfb1d0 ldr r5, [sp, #0x28] */
/* @0xfb1d4 mov r1, r4 */
/* @0xfb1d8 str r4, [r0] */
/* @0xfb1dc str r4, [r0, #0x4] */
/* @0xfb1e0 mov r0, r5 */
/* @0xfb1e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfb1e8 mov r1, #1 */
/* @0xfb1ec mov r6, r0 */
/* @0xfb1f0 mov r0, r5 */
/* @0xfb1f4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xfb1f8 mov r9, r0 */
/* @0xfb1fc bl 0xfae18 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0xfb200 add r1, sp, #8 */
/* @0xfb204 str r4, [r1, #-0x4]! */
/* @0xfb208 mov r5, r0 */
/* @0xfb20c mov r0, r6 */
/* @0xfb210 bl 0x13c1d8 <_Z11DSMapToJSONiPPc> */
/* @0xfb214 ldr r0, [sp, #0x4] */
/* @0xfb218 subs r3, r0, r4 */
/* @0xfb21c rsbs r7, r3, #0 */
/* @0xfb220 adcs r7, r7, r3 */
/* @0xfb224 cmp r7, r4 */
/* @0xfb228 bne 0xfb330 <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0xfb22c bl 0xb6538 <strlen@plt> */
/* @0xfb230 movw r3, #0xaaab */
/* @0xfb234 movt r3, #0xaaaa */
/* @0xfb238 add r0, r0, #1 */
/* @0xfb23c lsl r0, r0, #2 */
/* @0xfb240 umull r2, r0, r3, r0 */
/* @0xfb244 lsr r0, r0, #1 */
/* @0xfb248 add r0, r0, #4 */
/* @0xfb24c ldr r6, [pc, #0xf0] */
/* @0xfb250 mov r3, #1 */
/* @0xfb254 movw r2, #0x71b */
/* @0xfb258 add r6, pc, r6 */
/* @0xfb25c mov r1, r6 */
/* @0xfb260 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfb264 ldr r8, [sp, #0x4] */
/* @0xfb268 mov r4, r0 */
/* @0xfb26c mov r0, r8 */
/* @0xfb270 bl 0xb6538 <strlen@plt> */
/* @0xfb274 mov r2, r4 */
/* @0xfb278 add r1, r0, #1 */
/* @0xfb27c mov r0, r8 */
/* @0xfb280 bl 0x1d1e60 <_Z13base64_encodePKcjPc> */
/* @0xfb284 mov r0, r5 */
/* @0xfb288 bl 0xb6538 <strlen@plt> */
/* @0xfb28c mov r8, r0 */
/* @0xfb290 mov r0, r4 */
/* @0xfb294 bl 0xb6538 <strlen@plt> */
/* @0xfb298 mov r3, #1 */
/* @0xfb29c mov r1, r6 */
/* @0xfb2a0 mov r2, #1824 */
/* @0xfb2a4 add r8, r0, r8 */
/* @0xfb2a8 mov r0, r8 */
/* @0xfb2ac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfb2b0 mov r6, r0 */
/* @0xfb2b4 mov r0, r5 */
/* @0xfb2b8 bl 0xb6538 <strlen@plt> */
/* @0xfb2bc mov r1, r5 */
/* @0xfb2c0 mov r2, r0 */
/* @0xfb2c4 mov r0, r6 */
/* @0xfb2c8 bl 0xb65bc <memcpy@plt> */
/* @0xfb2cc mov r0, r5 */
/* @0xfb2d0 bl 0xb6538 <strlen@plt> */
/* @0xfb2d4 mov r10, r0 */
/* @0xfb2d8 mov r0, r4 */
/* @0xfb2dc bl 0xb6538 <strlen@plt> */
/* @0xfb2e0 mov r1, r4 */
/* @0xfb2e4 mov r2, r0 */
/* @0xfb2e8 add r0, r6, r10 */
/* @0xfb2ec bl 0xb65bc <memcpy@plt> */
/* @0xfb2f0 mov r1, r6 */
/* @0xfb2f4 mov r2, r8 */
/* @0xfb2f8 mov r0, r9 */
/* @0xfb2fc bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i> */
/* @0xfb300 mov r0, r5 */
/* @0xfb304 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb308 cmp r7, #0 */
/* @0xfb30c bne 0xfb318 <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0xfb310 ldr r0, [sp, #0x4] */
/* @0xfb314 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb318 mov r0, r4 */
/* @0xfb31c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb320 mov r0, r6 */
/* @0xfb324 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb328 add sp, sp, #8 */
/* @0xfb32c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xfb330 ldr r3, [pc, #0x10] */
/* @0xfb334 mov r0, #9 */
/* @0xfb338 add r3, pc, r3 */
/* @0xfb33c str r3, [sp, #0x4] */
/* @0xfb340 b 0xfb24c <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0xfb344 eoreq r12, r3, r4, asr #18 */
/* @0xfb348 .word 0x0023c8bc */

/* ── FUNC 0xfb34c · anon_fb34c · size=112 · insn=29 */
/* @0xfb34c push {r4, r5, r6, r7, r8, lr} */
/* @0xfb350 mov r4, r0 */
/* @0xfb354 bl 0xfae18 <_Z15F_DsQueueCreateR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0xfb358 add r6, r4, #80 */
/* @0xfb35c mov r8, r0 */
/* @0xfb360 mov r5, r0 */
/* @0xfb364 mov r1, r4 */
/* @0xfb368 mov r0, r5 */
/* @0xfb36c mov r2, #8 */
/* @0xfb370 bl 0xb65e0 <strncmp@plt> */
/* @0xfb374 add r1, r4, #8 */
/* @0xfb378 mov r2, #8 */
/* @0xfb37c add r4, r4, #16 */
/* @0xfb380 subs r7, r0, #0 */
/* @0xfb384 add r0, r5, r2 */
/* @0xfb388 add r5, r5, #16 */
/* @0xfb38c bne 0xfb3b8 <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0xfb390 bl 0xb65e0 <strncmp@plt> */
/* @0xfb394 cmp r0, #0 */
/* @0xfb398 bne 0xfb3a8 <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0xfb39c cmp r4, r6 */
/* @0xfb3a0 bne 0xfb364 <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0xfb3a4 mov r7, #1 */
/* @0xfb3a8 mov r0, r8 */
/* @0xfb3ac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb3b0 mov r0, r7 */
/* @0xfb3b4 pop {r4, r5, r6, r7, r8, pc} */
/* @0xfb3b8 mov r7, #0 */
/* @0xfb3bc b 0xfb3a8 <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x1e8> */

/* ── FUNC 0xfb3c0 · F_DsMapSecureLoad(RValue&, CInstance*, CInstance*, int, RValue*) · size=456 · insn=114 */
/* @0xfb3c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xfb3c4 sub sp, sp, #1024 */
/* @0xfb3c8 ldr r6, [pc, #0x1ac] */
/* @0xfb3cc sub sp, sp, #12 */
/* @0xfb3d0 mov r7, r0 */
/* @0xfb3d4 mov r4, #0 */
/* @0xfb3d8 ldr r6, [pc, r6] */
/* @0xfb3dc mov r1, r4 */
/* @0xfb3e0 ldr r0, [sp, #0x430] */
/* @0xfb3e4 mov r3, r4 */
/* @0xfb3e8 ldr r2, [r6] */
/* @0xfb3ec movt r3, #0xbff0 */
/* @0xfb3f0 str r4, [r7, #0xc] */
/* @0xfb3f4 add r5, sp, #4 */
/* @0xfb3f8 str r3, [r7, #0x4] */
/* @0xfb3fc str r4, [r7] */
/* @0xfb400 str r2, [sp, #0x404] */
/* @0xfb404 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xfb408 mov r1, #1024 */
/* @0xfb40c mov r2, r0 */
/* @0xfb410 mov r0, r5 */
/* @0xfb414 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0xfb418 ldr r1, [pc, #0x160] */
/* @0xfb41c mov r0, r5 */
/* @0xfb420 add r1, pc, r1 */
/* @0xfb424 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0xfb428 subs r8, r0, #0 */
/* @0xfb42c beq 0xfb4ac <_Z17F_DsMapSecureLoadR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0xfb430 mov r1, r4 */
/* @0xfb434 mov r2, #2 */
/* @0xfb438 bl 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli> */
/* @0xfb43c mov r0, r8 */
/* @0xfb440 bl 0x18de24 <_ZN8LoadSave5ftellEP7_YYFILE> */
/* @0xfb444 ldr r5, [pc, #0x138] */
/* @0xfb448 mov r1, r4 */
/* @0xfb44c mov r2, r4 */
/* @0xfb450 add r5, pc, r5 */
/* @0xfb454 mov r10, r0 */
/* @0xfb458 mov r0, r8 */
/* @0xfb45c bl 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli> */
/* @0xfb460 mov r1, r5 */
/* @0xfb464 movw r2, #0x751 */
/* @0xfb468 mov r3, #1 */
/* @0xfb46c mov r0, #81 */
/* @0xfb470 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfb474 mov r1, #1 */
/* @0xfb478 mov r2, #80 */
/* @0xfb47c mov r3, r8 */
/* @0xfb480 mov r9, r0 */
/* @0xfb484 bl 0x18e070 <_ZN8LoadSave5freadEPKvjjP7_YYFILE> */
/* @0xfb488 strb r4, [r9, #0x50] */
/* @0xfb48c mov r0, r9 */
/* @0xfb490 bl 0xfb34c <_Z17F_DsMapSecureSaveR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0xfb494 cmp r0, r4 */
/* @0xfb498 bne 0xfb4c8 <_Z17F_DsMapSecureLoadR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0xfb49c mov r0, r9 */
/* @0xfb4a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb4a4 mov r0, r8 */
/* @0xfb4a8 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE> */
/* @0xfb4ac ldr r2, [sp, #0x404] */
/* @0xfb4b0 ldr r3, [r6] */
/* @0xfb4b4 cmp r2, r3 */
/* @0xfb4b8 bne 0xfb578 <_Z17F_DsMapSecureLoadR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0xfb4bc add sp, sp, #1024 */
/* @0xfb4c0 add sp, sp, #12 */
/* @0xfb4c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xfb4c8 mov r1, r5 */
/* @0xfb4cc sub r0, r10, #78 */
/* @0xfb4d0 movw r2, #0x759 */
/* @0xfb4d4 mov r3, #1 */
/* @0xfb4d8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfb4dc sub r11, r10, #79 */
/* @0xfb4e0 mov r3, r8 */
/* @0xfb4e4 mov r1, #1 */
/* @0xfb4e8 mov r2, r11 */
/* @0xfb4ec mov r10, r0 */
/* @0xfb4f0 bl 0x18e070 <_ZN8LoadSave5freadEPKvjjP7_YYFILE> */
/* @0xfb4f4 add r3, r11, r11, lsl #1 */
/* @0xfb4f8 strb r4, [r10, r11] */
/* @0xfb4fc cmp r3, r4 */
/* @0xfb500 add r2, r3, #3 */
/* @0xfb504 mov r1, r5 */
/* @0xfb508 movge r4, r3 */
/* @0xfb50c movlt r4, r2 */
/* @0xfb510 asr r4, r4, #2 */
/* @0xfb514 movw r2, #0x75e */
/* @0xfb518 add r4, r4, #4 */
/* @0xfb51c mov r3, #1 */
/* @0xfb520 mov r0, r4 */
/* @0xfb524 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xfb528 mov r1, r4 */
/* @0xfb52c mov r3, #1 */
/* @0xfb530 mov r11, r0 */
/* @0xfb534 mov r0, r10 */
/* @0xfb538 mov r2, r11 */
/* @0xfb53c bl 0x1d1ff0 <_Z13base64_decodePKcjPcb> */
/* @0xfb540 mvn r1, #0 */
/* @0xfb544 mov r0, r11 */
/* @0xfb548 bl 0x13d5ac <_Z11JSONToDSMapPci> */
/* @0xfb54c vmov s15, r0 */
/* @0xfb550 mov r0, r11 */
/* @0xfb554 vcvt.f64.s32 d7, s15 */
/* @0xfb558 vmov r4, r5, d7 */
/* @0xfb55c vmov r2, s14 */
/* @0xfb560 mov r3, r5 */
/* @0xfb564 stm r7, {r2, r3} */
/* @0xfb568 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb56c mov r0, r10 */
/* @0xfb570 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xfb574 b 0xfb49c <_Z17F_DsMapSecureLoadR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0xfb578 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xfb57c eoreq r2, pc, r8, ror r5 */
/* @0xfb580 .word 0x0023c7d8 */
/* @0xfb584 eoreq r12, r3, r12, asr #14 */
