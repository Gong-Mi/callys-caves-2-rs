/* libyoyo.so 覆盖卡组 0071
 * 函数 0x13aac0..0x13c3ac，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x13aac0 · yyFindData::Reset() · size=80 · insn=20 */
/* @0x13aac0 push {r3, r4, r5, lr} */
/* @0x13aac4 mov r5, r0 */
/* @0x13aac8 ldr r3, [r0, #0x4] */
/* @0x13aacc cmp r3, #0 */
/* @0x13aad0 movgt r4, #0 */
/* @0x13aad4 ble 0x13aaf4 <_ZN10yyFindData5ResetEv+0x34> */
/* @0x13aad8 ldr r3, [r5, #0x8] */
/* @0x13aadc ldr r0, [r3, r4, lsl #2] */
/* @0x13aae0 add r4, r4, #1 */
/* @0x13aae4 bl 0xb655c <free@plt> */
/* @0x13aae8 ldr r3, [r5, #0x4] */
/* @0x13aaec cmp r3, r4 */
/* @0x13aaf0 bgt 0x13aad8 <_ZN10yyFindData5ResetEv+0x18> */
/* @0x13aaf4 ldr r0, [r5, #0x8] */
/* @0x13aaf8 bl 0xb655c <free@plt> */
/* @0x13aafc mov r3, #0 */
/* @0x13ab00 str r3, [r5, #0x8] */
/* @0x13ab04 str r3, [r5] */
/* @0x13ab08 str r3, [r5, #0x4] */
/* @0x13ab0c pop {r3, r4, r5, pc} */

/* ── FUNC 0x13ab10 · F_FileFindFirst(RValue&, CInstance*, CInstance*, int, RValue*) · size=280 · insn=70 */
/* @0x13ab10 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13ab14 sub sp, sp, #2064 */
/* @0x13ab18 ldr r7, [pc, #0xfc] */
/* @0x13ab1c sub sp, sp, #12 */
/* @0x13ab20 ldr r8, [pc, #0xf8] */
/* @0x13ab24 mov r3, #0 */
/* @0x13ab28 ldr r7, [pc, r7] */
/* @0x13ab2c ldr r4, [sp, #0x840] */
/* @0x13ab30 mov r10, r0 */
/* @0x13ab34 ldr r8, [pc, r8] */
/* @0x13ab38 ldr r2, [r7] */
/* @0x13ab3c mov r1, r3 */
/* @0x13ab40 str r3, [r0] */
/* @0x13ab44 mov r9, #1 */
/* @0x13ab48 mov r0, r4 */
/* @0x13ab4c str r9, [r10, #0xc] */
/* @0x13ab50 strb r3, [r8] */
/* @0x13ab54 str r2, [sp, #0x814] */
/* @0x13ab58 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13ab5c mov r1, r9 */
/* @0x13ab60 ldr r6, [pc, #0xbc] */
/* @0x13ab64 mov r11, r0 */
/* @0x13ab68 mov r0, r4 */
/* @0x13ab6c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13ab70 ldr r6, [pc, r6] */
/* @0x13ab74 mov r4, r0 */
/* @0x13ab78 mov r0, r6 */
/* @0x13ab7c mov r5, r1 */
/* @0x13ab80 bl 0x13aac0 <_ZN10yyFindData5ResetEv> */
/* @0x13ab84 add r12, sp, #20 */
/* @0x13ab88 mov r2, r11 */
/* @0x13ab8c mov r1, #1024 */
/* @0x13ab90 str r12, [sp, #0x8] */
/* @0x13ab94 mov r0, r12 */
/* @0x13ab98 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x13ab9c add r3, sp, #1040 */
/* @0x13aba0 add r3, r3, #8 */
/* @0x13aba4 mov r2, r11 */
/* @0x13aba8 sub r3, r3, #4 */
/* @0x13abac mov r1, #1024 */
/* @0x13abb0 str r3, [sp, #0xc] */
/* @0x13abb4 mov r0, r3 */
/* @0x13abb8 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x13abbc ldr r3, [sp, #0xc] */
/* @0x13abc0 ldr r12, [sp, #0x8] */
/* @0x13abc4 mov r0, r6 */
/* @0x13abc8 strd r4, r5, [sp] */
/* @0x13abcc mov r2, r3 */
/* @0x13abd0 mov r1, r12 */
/* @0x13abd4 bl 0x160818 <_Z14CreateFindDataP10yyFindDataPKcS2_d> */
/* @0x13abd8 ldr r3, [r6] */
/* @0x13abdc ldr r2, [r6, #0x4] */
/* @0x13abe0 cmp r3, r2 */
/* @0x13abe4 bge 0x13abfc <_Z15F_FileFindFirstR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x13abe8 ldr r2, [r6, #0x8] */
/* @0x13abec mov r0, r10 */
/* @0x13abf0 strb r9, [r8] */
/* @0x13abf4 ldr r1, [r2, r3, lsl #2] */
/* @0x13abf8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x13abfc ldr r2, [sp, #0x814] */
/* @0x13ac00 ldr r3, [r7] */
/* @0x13ac04 cmp r2, r3 */
/* @0x13ac08 bne 0x13ac18 <_Z15F_FileFindFirstR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x13ac0c add sp, sp, #2064 */
/* @0x13ac10 add sp, sp, #12 */
/* @0x13ac14 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13ac18 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13ac1c eoreq r2, r11, r8, lsr #28 */
/* @0x13ac20 eoreq r4, r11, r0, asr r7 */
/* @0x13ac24 eoreq r4, r11, r8, lsl r7 */

/* ── FUNC 0x13ac28 · F_FileFindClose(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x13ac28 push {r4, lr} */
/* @0x13ac2c ldr r4, [pc, #0x24] */
/* @0x13ac30 ldr r4, [pc, r4] */
/* @0x13ac34 ldrb r3, [r4] */
/* @0x13ac38 cmp r3, #0 */
/* @0x13ac3c beq 0x13ac4c <_Z15F_FileFindCloseR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x13ac40 ldr r0, [pc, #0x14] */
/* @0x13ac44 ldr r0, [pc, r0] */
/* @0x13ac48 bl 0x13aac0 <_ZN10yyFindData5ResetEv> */
/* @0x13ac4c mov r3, #0 */
/* @0x13ac50 strb r3, [r4] */
/* @0x13ac54 pop {r4, pc} */
/* @0x13ac58 eoreq r4, r11, r4, asr r6 */
/* @0x13ac5c eoreq r4, r11, r4, asr #12 */

/* ── FUNC 0x13ac60 · yyFindData::AddFile(char const*) · size=192 · insn=48 */
/* @0x13ac60 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x13ac64 mov r6, r1 */
/* @0x13ac68 ldr r1, [pc, #0xa8] */
/* @0x13ac6c mov r8, r0 */
/* @0x13ac70 mov r0, r6 */
/* @0x13ac74 add r1, pc, r1 */
/* @0x13ac78 bl 0xb6574 <strcmp@plt> */
/* @0x13ac7c cmp r0, #0 */
/* @0x13ac80 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x13ac84 ldr r1, [pc, #0x90] */
/* @0x13ac88 mov r0, r6 */
/* @0x13ac8c add r1, pc, r1 */
/* @0x13ac90 bl 0xb6574 <strcmp@plt> */
/* @0x13ac94 cmp r0, #0 */
/* @0x13ac98 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x13ac9c ldmib r8, {r7, r9} */
/* @0x13aca0 cmp r7, #0 */
/* @0x13aca4 subgt r5, r9, #4 */
/* @0x13aca8 movgt r4, #0 */
/* @0x13acac ble 0x13acd0 <_ZN10yyFindData7AddFileEPKc+0x70> */
/* @0x13acb0 mov r0, r6 */
/* @0x13acb4 ldr r1, [r5, #0x4]! */
/* @0x13acb8 bl 0xb6574 <strcmp@plt> */
/* @0x13acbc add r4, r4, #1 */
/* @0x13acc0 cmp r0, #0 */
/* @0x13acc4 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x13acc8 cmp r4, r7 */
/* @0x13accc bne 0x13acb0 <_ZN10yyFindData7AddFileEPKc+0x50> */
/* @0x13acd0 add r7, r7, #1 */
/* @0x13acd4 str r7, [r8, #0x4] */
/* @0x13acd8 lsl r7, r7, #2 */
/* @0x13acdc mov r0, r7 */
/* @0x13ace0 bl 0xb6544 <malloc@plt> */
/* @0x13ace4 mov r1, r9 */
/* @0x13ace8 sub r2, r7, #4 */
/* @0x13acec mov r4, r0 */
/* @0x13acf0 bl 0xb65bc <memcpy@plt> */
/* @0x13acf4 ldr r0, [r8, #0x8] */
/* @0x13acf8 bl 0xb655c <free@plt> */
/* @0x13acfc str r4, [r8, #0x8] */
/* @0x13ad00 mov r0, r6 */
/* @0x13ad04 ldr r5, [r8, #0x4] */
/* @0x13ad08 bl 0xb6640 <strdup@plt> */
/* @0x13ad0c sub r5, r5, #-1073741823 */
/* @0x13ad10 str r0, [r4, r5, lsl #2] */
/* @0x13ad14 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x13ad18 eoreq r5, r0, r8, asr #13 */
/* @0x13ad1c .word 0x002056b4 */

/* ── FUNC 0x13ad20 · EnsureDirectoryIsCreated(char const*) · size=140 · insn=35 */
/* @0x13ad20 push {r4, r5, lr} */
/* @0x13ad24 sub sp, sp, #2048 */
/* @0x13ad28 ldr r4, [pc, #0x78] */
/* @0x13ad2c sub sp, sp, #12 */
/* @0x13ad30 add r5, sp, #4 */
/* @0x13ad34 mov r1, r0 */
/* @0x13ad38 ldr r4, [pc, r4] */
/* @0x13ad3c mov r0, r5 */
/* @0x13ad40 ldr r3, [r4] */
/* @0x13ad44 str r3, [sp, #0x804] */
/* @0x13ad48 bl 0xb65a4 <strcpy@plt> */
/* @0x13ad4c mov r0, r5 */
/* @0x13ad50 mov r1, #92 */
/* @0x13ad54 bl 0xb6868 <strrchr@plt> */
/* @0x13ad58 subs r3, r0, #0 */
/* @0x13ad5c beq 0x13ad8c <_Z24EnsureDirectoryIsCreatedPKc+0x6c> */
/* @0x13ad60 mov r2, #0 */
/* @0x13ad64 mov r0, r5 */
/* @0x13ad68 strb r2, [r3] */
/* @0x13ad6c bl 0x2150b4 <_Z16ForceDirectoriesPKc> */
/* @0x13ad70 ldr r2, [sp, #0x804] */
/* @0x13ad74 ldr r3, [r4] */
/* @0x13ad78 cmp r2, r3 */
/* @0x13ad7c bne 0x13ada4 <_Z24EnsureDirectoryIsCreatedPKc+0x84> */
/* @0x13ad80 add sp, sp, #2048 */
/* @0x13ad84 add sp, sp, #12 */
/* @0x13ad88 pop {r4, r5, pc} */
/* @0x13ad8c mov r0, r5 */
/* @0x13ad90 mov r1, #47 */
/* @0x13ad94 bl 0xb6868 <strrchr@plt> */
/* @0x13ad98 subs r3, r0, #0 */
/* @0x13ad9c beq 0x13ad70 <_Z24EnsureDirectoryIsCreatedPKc+0x50> */
/* @0x13ada0 b 0x13ad60 <_Z24EnsureDirectoryIsCreatedPKc+0x40> */
/* @0x13ada4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13ada8 eoreq r2, r11, r8, lsl r12 */

/* ── FUNC 0x13adac · F_FileBinOpen(RValue&, CInstance*, CInstance*, int, RValue*) · size=728 · insn=182 */
/* @0x13adac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13adb0 sub sp, sp, #1040 */
/* @0x13adb4 ldr r4, [pc, #0x2a0] */
/* @0x13adb8 sub sp, sp, #12 */
/* @0x13adbc ldr r3, [pc, #0x29c] */
/* @0x13adc0 mov r5, r0 */
/* @0x13adc4 add r4, pc, r4 */
/* @0x13adc8 ldr r6, [sp, #0x440] */
/* @0x13adcc mov r1, #0 */
/* @0x13add0 mov r11, #1 */
/* @0x13add4 ldr r3, [r4, r3] */
/* @0x13add8 mov r0, r6 */
/* @0x13addc str r3, [sp, #0x4] */
/* @0x13ade0 ldr r3, [r3] */
/* @0x13ade4 str r3, [sp, #0x414] */
/* @0x13ade8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13adec mov r1, #1 */
/* @0x13adf0 str r0, [sp, #0xc] */
/* @0x13adf4 mov r0, r6 */
/* @0x13adf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13adfc ldr r1, [pc, #0x260] */
/* @0x13ae00 mov r2, #0 */
/* @0x13ae04 mov r3, r2 */
/* @0x13ae08 movt r2, #0xbff0 */
/* @0x13ae0c str r3, [r5, #0xc] */
/* @0x13ae10 str r2, [r5, #0x4] */
/* @0x13ae14 str r3, [r5] */
/* @0x13ae18 str r0, [sp, #0x8] */
/* @0x13ae1c ldr r10, [r4, r1] */
/* @0x13ae20 ldrb r3, [r10, #0x1] */
/* @0x13ae24 cmp r3, #0 */
/* @0x13ae28 beq 0x13ae3c <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x13ae2c add r11, r11, #1 */
/* @0x13ae30 ldrb r3, [r10, r11] */
/* @0x13ae34 cmp r3, #0 */
/* @0x13ae38 bne 0x13ae2c <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x13ae3c ldr r2, [pc, #0x224] */
/* @0x13ae40 add r6, r11, r11, lsl #1 */
/* @0x13ae44 lsl r6, r6, #2 */
/* @0x13ae48 ldr r2, [r4, r2] */
/* @0x13ae4c add r7, r6, r2 */
/* @0x13ae50 str r2, [sp] */
/* @0x13ae54 ldr r0, [r7, #0x8] */
/* @0x13ae58 cmp r0, #0 */
/* @0x13ae5c beq 0x13ae98 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x13ae60 ldr r2, [r7, #0x4] */
/* @0x13ae64 cmp r2, #0 */
/* @0x13ae68 beq 0x13ae78 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x13ae6c blt 0x13ae7c <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x13ae70 cmp r2, #2 */
/* @0x13ae74 bgt 0x13ae7c <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x13ae78 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE> */
/* @0x13ae7c ldr r3, [sp] */
/* @0x13ae80 mov r8, #0 */
/* @0x13ae84 ldr r0, [r3, r6] */
/* @0x13ae88 str r8, [r7, #0x8] */
/* @0x13ae8c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13ae90 ldr r3, [sp] */
/* @0x13ae94 str r8, [r6, r3] */
/* @0x13ae98 ldr r0, [sp, #0xc] */
/* @0x13ae9c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x13aea0 cmp r0, #0 */
/* @0x13aea4 beq 0x13af84 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x13aea8 add r8, sp, #20 */
/* @0x13aeac ldr r2, [sp, #0xc] */
/* @0x13aeb0 mov r1, #1024 */
/* @0x13aeb4 mov r0, r8 */
/* @0x13aeb8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x13aebc ldr r2, [pc, #0x1a8] */
/* @0x13aec0 ldr r9, [r4, r2] */
/* @0x13aec4 ldr r3, [sp] */
/* @0x13aec8 ldr r0, [r6, r3] */
/* @0x13aecc cmp r0, #0 */
/* @0x13aed0 beq 0x13aed8 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x13aed4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x13aed8 mov r0, r8 */
/* @0x13aedc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x13aee0 ldr r3, [sp, #0x8] */
/* @0x13aee4 cmp r3, #0 */
/* @0x13aee8 ldr r3, [sp] */
/* @0x13aeec str r0, [r3, r6] */
/* @0x13aef0 beq 0x13afb4 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x13aef4 ldr r3, [sp, #0x8] */
/* @0x13aef8 cmp r3, #1 */
/* @0x13aefc beq 0x13b03c <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x290> */
/* @0x13af00 ldr r2, [pc, #0x168] */
/* @0x13af04 add r2, pc, r2 */
/* @0x13af08 ldr r2, [r2] */
/* @0x13af0c strh r2, [r9] */
/* @0x13af10 lsr r2, r2, #16 */
/* @0x13af14 strb r2, [r9, #0x2] */
/* @0x13af18 mov r0, r8 */
/* @0x13af1c bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc> */
/* @0x13af20 mov r0, r8 */
/* @0x13af24 mov r1, r9 */
/* @0x13af28 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0x13af2c mov r2, r0 */
/* @0x13af30 cmp r2, #0 */
/* @0x13af34 str r0, [r7, #0x8] */
/* @0x13af38 beq 0x13afe8 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x13af3c vmov s15, r11 */
/* @0x13af40 mov r2, #1 */
/* @0x13af44 strb r2, [r10, r11] */
/* @0x13af48 vcvt.f64.s32 d7, s15 */
/* @0x13af4c ldr r3, [sp, #0x8] */
/* @0x13af50 str r3, [r7, #0x4] */
/* @0x13af54 vmov r0, r1, d7 */
/* @0x13af58 vmov r2, s14 */
/* @0x13af5c mov r3, r1 */
/* @0x13af60 stm r5, {r2, r3} */
/* @0x13af64 ldr r1, [sp, #0x4] */
/* @0x13af68 ldr r2, [sp, #0x414] */
/* @0x13af6c ldr r3, [r1] */
/* @0x13af70 cmp r2, r3 */
/* @0x13af74 bne 0x13b058 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x2ac> */
/* @0x13af78 add sp, sp, #1040 */
/* @0x13af7c add sp, sp, #12 */
/* @0x13af80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13af84 ldr r0, [sp, #0xc] */
/* @0x13af88 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x13af8c cmp r0, #0 */
/* @0x13af90 beq 0x13b010 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x13af94 add r8, sp, #20 */
/* @0x13af98 ldr r2, [sp, #0xc] */
/* @0x13af9c mov r1, #1024 */
/* @0x13afa0 mov r0, r8 */
/* @0x13afa4 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x13afa8 ldr r2, [pc, #0xbc] */
/* @0x13afac ldr r9, [r4, r2] */
/* @0x13afb0 b 0x13aec4 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x13afb4 ldr r2, [pc, #0xb8] */
/* @0x13afb8 mov r0, r8 */
/* @0x13afbc mov r1, r9 */
/* @0x13afc0 add r2, pc, r2 */
/* @0x13afc4 ldr r2, [r2] */
/* @0x13afc8 strh r2, [r9] */
/* @0x13afcc lsr r2, r2, #16 */
/* @0x13afd0 strb r2, [r9, #0x2] */
/* @0x13afd4 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0x13afd8 mov r2, r0 */
/* @0x13afdc cmp r2, #0 */
/* @0x13afe0 str r0, [r7, #0x8] */
/* @0x13afe4 bne 0x13af3c <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x13afe8 ldr r3, [pc, #0x88] */
/* @0x13afec ldr r1, [pc, #0x88] */
/* @0x13aff0 ldr r2, [sp, #0xc] */
/* @0x13aff4 ldr r3, [r4, r3] */
/* @0x13aff8 add r1, pc, r1 */
/* @0x13affc ldr r0, [r3] */
/* @0x13b000 ldr r3, [r0] */
/* @0x13b004 ldr r3, [r3, #0xc] */
/* @0x13b008 blx r3 */
/* @0x13b00c b 0x13af64 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x13b010 ldr r2, [pc, #0x54] */
/* @0x13b014 add r8, sp, #20 */
/* @0x13b018 movw lr, #0x6261 */
/* @0x13b01c mov r1, #1024 */
/* @0x13b020 movt lr, #0x2b */
/* @0x13b024 mov r0, r8 */
/* @0x13b028 ldr r9, [r4, r2] */
/* @0x13b02c ldr r2, [sp, #0xc] */
/* @0x13b030 str lr, [r9] */
/* @0x13b034 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x13b038 b 0x13aec4 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x13b03c ldr r2, [pc, #0x3c] */
/* @0x13b040 add r2, pc, r2 */
/* @0x13b044 ldr r2, [r2] */
/* @0x13b048 strh r2, [r9] */
/* @0x13b04c lsr r2, r2, #16 */
/* @0x13b050 strb r2, [r9, #0x2] */
/* @0x13b054 b 0x13af18 <_Z13F_FileBinOpenR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x13b058 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13b05c eoreq r6, r11, r12, lsl #29 */
/* @0x13b060 .word 0xffffbd00 */
/* @0x13b064 .word 0xffffd63c */
/* @0x13b068 .word 0xffffd640 */
/* @0x13b06c .word 0xffffd630 */
/* @0x13b070 eoreq r5, r0, r4, asr #8 */
/* @0x13b074 andseq r12, pc, r8, lsr r12 */
/* @0x13b078 .word 0xffffbac4 */
/* @0x13b07c eoreq r5, r0, r4, asr r3 */
/* @0x13b080 eoreq r5, r0, r4, lsl #6 */

/* ── FUNC 0x13b084 · F_FileTextOpenWrite(RValue&, CInstance*, CInstance*, int, RValue*) · size=428 · insn=107 */
/* @0x13b084 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13b088 sub sp, sp, #1040 */
/* @0x13b08c ldr r6, [pc, #0x178] */
/* @0x13b090 sub sp, sp, #12 */
/* @0x13b094 ldr r3, [pc, #0x174] */
/* @0x13b098 mov r5, r0 */
/* @0x13b09c add r6, pc, r6 */
/* @0x13b0a0 mov r1, #0 */
/* @0x13b0a4 ldr r0, [sp, #0x440] */
/* @0x13b0a8 mov r4, #1 */
/* @0x13b0ac ldr r3, [r6, r3] */
/* @0x13b0b0 str r3, [sp, #0x8] */
/* @0x13b0b4 ldr r3, [r3] */
/* @0x13b0b8 str r3, [sp, #0x414] */
/* @0x13b0bc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13b0c0 mov r1, #0 */
/* @0x13b0c4 mov r3, r1 */
/* @0x13b0c8 movt r1, #0xbff0 */
/* @0x13b0cc str r3, [r5, #0xc] */
/* @0x13b0d0 str r1, [r5, #0x4] */
/* @0x13b0d4 str r3, [r5] */
/* @0x13b0d8 mov r2, r0 */
/* @0x13b0dc ldr r0, [pc, #0x130] */
/* @0x13b0e0 ldr r3, [r6, r0] */
/* @0x13b0e4 str r3, [sp, #0xc] */
/* @0x13b0e8 b 0x13b0f8 <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x13b0ec add r4, r4, #1 */
/* @0x13b0f0 cmp r4, #32 */
/* @0x13b0f4 beq 0x13b1cc <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x13b0f8 ldr r11, [r3, #0x4]! */
/* @0x13b0fc cmp r11, #0 */
/* @0x13b100 bne 0x13b0ec <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x13b104 ldr r3, [pc, #0x10c] */
/* @0x13b108 add r10, r4, r4, lsl #1 */
/* @0x13b10c add r9, sp, #20 */
/* @0x13b110 lsl r10, r10, #2 */
/* @0x13b114 ldr r8, [r6, r3] */
/* @0x13b118 add r7, r8, r10 */
/* @0x13b11c ldr r0, [r8, r10] */
/* @0x13b120 str r2, [sp, #0x4] */
/* @0x13b124 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13b128 ldr r2, [sp, #0x4] */
/* @0x13b12c mov r1, #1024 */
/* @0x13b130 str r11, [r8, r10] */
/* @0x13b134 mov r0, r9 */
/* @0x13b138 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x13b13c mov r0, r9 */
/* @0x13b140 bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc> */
/* @0x13b144 mov r0, r9 */
/* @0x13b148 bl 0xb6538 <strlen@plt> */
/* @0x13b14c ldr r1, [pc, #0xc8] */
/* @0x13b150 mov r3, #1 */
/* @0x13b154 movw r2, #0x35b */
/* @0x13b158 add r1, pc, r1 */
/* @0x13b15c add r0, r0, r3 */
/* @0x13b160 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13b164 mov r1, r9 */
/* @0x13b168 mov r11, r0 */
/* @0x13b16c bl 0xb65a4 <strcpy@plt> */
/* @0x13b170 ldr r1, [pc, #0xa8] */
/* @0x13b174 mov r0, r11 */
/* @0x13b178 str r11, [r8, r10] */
/* @0x13b17c add r1, pc, r1 */
/* @0x13b180 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0x13b184 cmp r0, #0 */
/* @0x13b188 str r0, [r7, #0x8] */
/* @0x13b18c beq 0x13b1e0 <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x13b190 vmov s15, r4 */
/* @0x13b194 ldr r0, [sp, #0xc] */
/* @0x13b198 mov r1, #2 */
/* @0x13b19c vcvt.f64.s32 d7, s15 */
/* @0x13b1a0 str r1, [r0, r4, lsl #2] */
/* @0x13b1a4 vmov r2, r3, d7 */
/* @0x13b1a8 stm r5, {r2, r3} */
/* @0x13b1ac ldr r1, [sp, #0x8] */
/* @0x13b1b0 ldr r2, [sp, #0x414] */
/* @0x13b1b4 ldr r3, [r1] */
/* @0x13b1b8 cmp r2, r3 */
/* @0x13b1bc bne 0x13b208 <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x13b1c0 add sp, sp, #1040 */
/* @0x13b1c4 add sp, sp, #12 */
/* @0x13b1c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13b1cc ldr r0, [pc, #0x50] */
/* @0x13b1d0 mov r1, #0 */
/* @0x13b1d4 add r0, pc, r0 */
/* @0x13b1d8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13b1dc b 0x13b1ac <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x13b1e0 ldr r3, [pc, #0x40] */
/* @0x13b1e4 mov r2, r11 */
/* @0x13b1e8 ldr r1, [pc, #0x3c] */
/* @0x13b1ec ldr r3, [r6, r3] */
/* @0x13b1f0 add r1, pc, r1 */
/* @0x13b1f4 ldr r0, [r3] */
/* @0x13b1f8 ldr r3, [r0] */
/* @0x13b1fc ldr r3, [r3, #0xc] */
/* @0x13b200 blx r3 */
/* @0x13b204 b 0x13b1ac <_Z19F_FileTextOpenWriteR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x13b208 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13b20c .word 0x002b6bb4 */
/* @0x13b210 .word 0xffffbd00 */
/* @0x13b214 .word 0xffffd620 */
/* @0x13b218 .word 0xffffd624 */
/* @0x13b21c .word 0x00204ef8 */
/* @0x13b220 .word 0x002051f0 */
/* @0x13b224 eoreq r4, r0, r12, lsr #28 */
/* @0x13b228 .word 0xffffbac4 */
/* @0x13b22c eoreq r4, r0, r4, ror #27 */

/* ── FUNC 0x13b230 · F_FileTextOpenAppend(RValue&, CInstance*, CInstance*, int, RValue*) · size=568 · insn=142 */
/* @0x13b230 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13b234 sub sp, sp, #1040 */
/* @0x13b238 ldr r7, [pc, #0x1fc] */
/* @0x13b23c sub sp, sp, #12 */
/* @0x13b240 ldr r3, [pc, #0x1f8] */
/* @0x13b244 mov r6, r0 */
/* @0x13b248 add r7, pc, r7 */
/* @0x13b24c mov r1, #0 */
/* @0x13b250 ldr r0, [sp, #0x440] */
/* @0x13b254 mov r4, #1 */
/* @0x13b258 ldr r3, [r7, r3] */
/* @0x13b25c str r3, [sp, #0x8] */
/* @0x13b260 ldr r3, [r3] */
/* @0x13b264 str r3, [sp, #0x414] */
/* @0x13b268 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13b26c ldr r1, [pc, #0x1d0] */
/* @0x13b270 mov r2, #0 */
/* @0x13b274 mov r3, r2 */
/* @0x13b278 movt r2, #0xbff0 */
/* @0x13b27c str r3, [r6, #0xc] */
/* @0x13b280 str r2, [r6, #0x4] */
/* @0x13b284 str r3, [r6] */
/* @0x13b288 ldr r3, [r7, r1] */
/* @0x13b28c str r3, [sp, #0xc] */
/* @0x13b290 mov r10, r0 */
/* @0x13b294 b 0x13b2a4 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x13b298 add r4, r4, #1 */
/* @0x13b29c cmp r4, #32 */
/* @0x13b2a0 beq 0x13b398 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x13b2a4 ldr r5, [r3, #0x4]! */
/* @0x13b2a8 cmp r5, #0 */
/* @0x13b2ac bne 0x13b298 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x13b2b0 ldr r2, [pc, #0x190] */
/* @0x13b2b4 lsl r11, r4, #1 */
/* @0x13b2b8 add r3, r11, r4 */
/* @0x13b2bc add r9, sp, #20 */
/* @0x13b2c0 ldr r8, [r7, r2] */
/* @0x13b2c4 lsl r3, r3, #2 */
/* @0x13b2c8 ldr r0, [r8, r3] */
/* @0x13b2cc str r3, [sp, #0x4] */
/* @0x13b2d0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13b2d4 ldr r3, [sp, #0x4] */
/* @0x13b2d8 mov r1, #1024 */
/* @0x13b2dc mov r2, r10 */
/* @0x13b2e0 mov r0, r9 */
/* @0x13b2e4 str r5, [r8, r3] */
/* @0x13b2e8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x13b2ec mov r0, r10 */
/* @0x13b2f0 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x13b2f4 cmp r0, #0 */
/* @0x13b2f8 beq 0x13b3ac <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x13b2fc mov r0, r9 */
/* @0x13b300 add r11, r11, r4 */
/* @0x13b304 bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc> */
/* @0x13b308 mov r0, r9 */
/* @0x13b30c bl 0xb6538 <strlen@plt> */
/* @0x13b310 ldr r1, [pc, #0x134] */
/* @0x13b314 mov r3, #1 */
/* @0x13b318 movw r2, #0x3b2 */
/* @0x13b31c add r1, pc, r1 */
/* @0x13b320 lsl r11, r11, #2 */
/* @0x13b324 add r0, r0, r3 */
/* @0x13b328 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13b32c mov r1, r9 */
/* @0x13b330 add r9, r8, r11 */
/* @0x13b334 mov r5, r0 */
/* @0x13b338 bl 0xb65a4 <strcpy@plt> */
/* @0x13b33c ldr r1, [pc, #0x10c] */
/* @0x13b340 mov r0, r5 */
/* @0x13b344 str r5, [r8, r11] */
/* @0x13b348 add r1, pc, r1 */
/* @0x13b34c bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0x13b350 cmp r0, #0 */
/* @0x13b354 str r0, [r9, #0x8] */
/* @0x13b358 beq 0x13b410 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x13b35c vmov s15, r4 */
/* @0x13b360 ldr r0, [sp, #0xc] */
/* @0x13b364 mov r1, #2 */
/* @0x13b368 vcvt.f64.s32 d7, s15 */
/* @0x13b36c str r1, [r0, r4, lsl #2] */
/* @0x13b370 vmov r2, r3, d7 */
/* @0x13b374 stm r6, {r2, r3} */
/* @0x13b378 ldr r1, [sp, #0x8] */
/* @0x13b37c ldr r2, [sp, #0x414] */
/* @0x13b380 ldr r3, [r1] */
/* @0x13b384 cmp r2, r3 */
/* @0x13b388 bne 0x13b438 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x13b38c add sp, sp, #1040 */
/* @0x13b390 add sp, sp, #12 */
/* @0x13b394 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13b398 ldr r0, [pc, #0xb4] */
/* @0x13b39c mov r1, #0 */
/* @0x13b3a0 add r0, pc, r0 */
/* @0x13b3a4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13b3a8 b 0x13b378 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x13b3ac mov r0, r10 */
/* @0x13b3b0 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x13b3b4 cmp r0, #0 */
/* @0x13b3b8 beq 0x13b2fc <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x13b3bc ldr r1, [pc, #0x94] */
/* @0x13b3c0 mov r0, r10 */
/* @0x13b3c4 add r1, pc, r1 */
/* @0x13b3c8 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0x13b3cc ldr r1, [pc, #0x88] */
/* @0x13b3d0 add r1, pc, r1 */
/* @0x13b3d4 mov r5, r0 */
/* @0x13b3d8 mov r0, r9 */
/* @0x13b3dc bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0x13b3e0 ldr r2, [r5] */
/* @0x13b3e4 mov r1, #1 */
/* @0x13b3e8 mov r3, r0 */
/* @0x13b3ec mov r10, r0 */
/* @0x13b3f0 ldr r0, [r2, #0xc] */
/* @0x13b3f4 ldr r2, [r2, #0x10] */
/* @0x13b3f8 bl 0x18e2b0 <_ZN8LoadSave6fwriteEPKvjjP7_YYFILE> */
/* @0x13b3fc mov r0, r5 */
/* @0x13b400 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE> */
/* @0x13b404 mov r0, r10 */
/* @0x13b408 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE> */
/* @0x13b40c b 0x13b2fc <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x13b410 ldr r3, [pc, #0x48] */
/* @0x13b414 mov r2, r5 */
/* @0x13b418 ldr r1, [pc, #0x44] */
/* @0x13b41c ldr r3, [r7, r3] */
/* @0x13b420 add r1, pc, r1 */
/* @0x13b424 ldr r0, [r3] */
/* @0x13b428 ldr r3, [r0] */
/* @0x13b42c ldr r3, [r3, #0xc] */
/* @0x13b430 blx r3 */
/* @0x13b434 b 0x13b378 <_Z20F_FileTextOpenAppendR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x13b438 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13b43c eoreq r6, r11, r8, lsl #20 */
/* @0x13b440 .word 0xffffbd00 */
/* @0x13b444 .word 0xffffd620 */
/* @0x13b448 .word 0xffffd624 */
/* @0x13b44c eoreq r4, r0, r4, lsr sp */
/* @0x13b450 eoreq r4, r0, r8, lsr #29 */
/* @0x13b454 eoreq r4, r0, r0, ror #24 */
/* @0x13b458 andseq r12, pc, r4, lsr r8 */
/* @0x13b45c eoreq r4, r0, r4, ror pc */
/* @0x13b460 .word 0xffffbac4 */
/* @0x13b464 .word 0x00204bb4 */

/* ── FUNC 0x13b468 · F_FileCopy(RValue&, CInstance*, CInstance*, int, RValue*) · size=592 · insn=148 */
/* @0x13b468 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13b46c sub sp, sp, #6144 */
/* @0x13b470 ldr r8, [pc, #0x220] */
/* @0x13b474 sub sp, sp, #20 */
/* @0x13b478 ldr r3, [pc, #0x21c] */
/* @0x13b47c add r2, sp, #8192 */
/* @0x13b480 add r8, pc, r8 */
/* @0x13b484 mov r5, r0 */
/* @0x13b488 ldr r6, [r2, #-0x7c8] */
/* @0x13b48c mov r1, #0 */
/* @0x13b490 ldr r3, [r8, r3] */
/* @0x13b494 mov r0, r6 */
/* @0x13b498 str r3, [sp, #0x4] */
/* @0x13b49c ldr r3, [r3] */
/* @0x13b4a0 str r3, [r2, #-0x7f4] */
/* @0x13b4a4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13b4a8 mov r1, #1 */
/* @0x13b4ac mov r4, r0 */
/* @0x13b4b0 mov r0, r6 */
/* @0x13b4b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13b4b8 mov r2, #0 */
/* @0x13b4bc mov r3, r2 */
/* @0x13b4c0 movt r2, #0xbff0 */
/* @0x13b4c4 str r3, [r5, #0xc] */
/* @0x13b4c8 str r2, [r5, #0x4] */
/* @0x13b4cc str r3, [r5] */
/* @0x13b4d0 mov r10, r0 */
/* @0x13b4d4 mov r0, r4 */
/* @0x13b4d8 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x13b4dc cmp r0, #0 */
/* @0x13b4e0 beq 0x13b600 <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x13b4e4 add r11, sp, #16 */
/* @0x13b4e8 mov r1, #1024 */
/* @0x13b4ec sub r7, r11, #4 */
/* @0x13b4f0 mov r2, r4 */
/* @0x13b4f4 mov r0, r7 */
/* @0x13b4f8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x13b4fc add r6, sp, #1040 */
/* @0x13b500 mov r2, r10 */
/* @0x13b504 sub r6, r6, #4 */
/* @0x13b508 mov r1, #1024 */
/* @0x13b50c movw r9, #0xe7f8 */
/* @0x13b510 movt r9, #0xffff */
/* @0x13b514 mov r0, r6 */
/* @0x13b518 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x13b51c mov r0, r6 */
/* @0x13b520 bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc> */
/* @0x13b524 ldr r1, [pc, #0x174] */
/* @0x13b528 mov r0, r7 */
/* @0x13b52c add r1, pc, r1 */
/* @0x13b530 bl 0xb6844 <fopen@plt> */
/* @0x13b534 add r3, sp, #6144 */
/* @0x13b538 add r3, r3, #16 */
/* @0x13b53c mov r2, #0 */
/* @0x13b540 str r2, [r3, r9] */
/* @0x13b544 subs r7, r0, #0 */
/* @0x13b548 beq 0x13b630 <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x13b54c ldr r1, [pc, #0x150] */
/* @0x13b550 mov r0, r6 */
/* @0x13b554 add r1, pc, r1 */
/* @0x13b558 bl 0xb6844 <fopen@plt> */
/* @0x13b55c subs r6, r0, #0 */
/* @0x13b560 addne r4, sp, #2048 */
/* @0x13b564 addne r4, r4, #12 */
/* @0x13b568 bne 0x13b5a4 <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x13b56c ldr r1, [pc, #0x134] */
/* @0x13b570 mov r2, r10 */
/* @0x13b574 ldr r3, [pc, #0x130] */
/* @0x13b578 add r1, pc, r1 */
/* @0x13b57c ldr r3, [r8, r3] */
/* @0x13b580 ldr r0, [r3] */
/* @0x13b584 ldr r3, [r0] */
/* @0x13b588 ldr r3, [r3, #0xc] */
/* @0x13b58c blx r3 */
/* @0x13b590 b 0x13b5dc <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x13b594 mov r0, r4 */
/* @0x13b598 mov r1, #1 */
/* @0x13b59c mov r3, r6 */
/* @0x13b5a0 bl 0xb68bc <fwrite@plt> */
/* @0x13b5a4 mov r2, #4096 */
/* @0x13b5a8 mov r0, r4 */
/* @0x13b5ac mov r1, #1 */
/* @0x13b5b0 mov r3, r7 */
/* @0x13b5b4 bl 0xb68c8 <fread@plt> */
/* @0x13b5b8 subs r2, r0, #0 */
/* @0x13b5bc bne 0x13b594 <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x13b5c0 mov r0, r7 */
/* @0x13b5c4 bl 0xb6850 <fclose@plt> */
/* @0x13b5c8 mov r0, r6 */
/* @0x13b5cc bl 0xb6850 <fclose@plt> */
/* @0x13b5d0 mov r3, #0 */
/* @0x13b5d4 str r3, [r5] */
/* @0x13b5d8 str r3, [r5, #0x4] */
/* @0x13b5dc ldr r1, [sp, #0x4] */
/* @0x13b5e0 add r3, sp, #8192 */
/* @0x13b5e4 ldr r2, [r3, #-0x7f4] */
/* @0x13b5e8 ldr r3, [r1] */
/* @0x13b5ec cmp r2, r3 */
/* @0x13b5f0 bne 0x13b694 <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x13b5f4 add sp, sp, #6144 */
/* @0x13b5f8 add sp, sp, #20 */
/* @0x13b5fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13b600 mov r0, r4 */
/* @0x13b604 add r11, sp, #16 */
/* @0x13b608 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x13b60c cmp r0, #0 */
/* @0x13b610 addeq r7, sp, #12 */
/* @0x13b614 beq 0x13b4fc <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x13b618 add r7, sp, #12 */
/* @0x13b61c mov r1, #1024 */
/* @0x13b620 mov r2, r4 */
/* @0x13b624 mov r0, r7 */
/* @0x13b628 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x13b62c b 0x13b4fc <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x13b630 sub r1, r11, #8 */
/* @0x13b634 mov r0, r4 */
/* @0x13b638 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0x13b63c ldr r1, [pc, #0x6c] */
/* @0x13b640 ldr r3, [pc, #0x64] */
/* @0x13b644 mov r2, r4 */
/* @0x13b648 add r1, pc, r1 */
/* @0x13b64c subs r7, r0, #0 */
/* @0x13b650 beq 0x13b57c <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x13b654 ldr r1, [pc, #0x58] */
/* @0x13b658 mov r0, r6 */
/* @0x13b65c add r1, pc, r1 */
/* @0x13b660 bl 0xb6844 <fopen@plt> */
/* @0x13b664 subs r6, r0, #0 */
/* @0x13b668 beq 0x13b56c <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x13b66c add r1, sp, #6144 */
/* @0x13b670 mov r0, r7 */
/* @0x13b674 add r1, r1, #16 */
/* @0x13b678 mov r3, r6 */
/* @0x13b67c ldr r2, [r1, r9] */
/* @0x13b680 mov r1, #1 */
/* @0x13b684 bl 0xb68bc <fwrite@plt> */
/* @0x13b688 mov r0, r7 */
/* @0x13b68c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13b690 b 0x13b5c8 <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x13b694 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13b698 .word 0x002b67d0 */
/* @0x13b69c .word 0xffffbd00 */
/* @0x13b6a0 andseq r12, pc, r12, asr #13 */
/* @0x13b6a4 .word 0x00204df0 */
/* @0x13b6a8 eoreq r4, r0, r8, lsl lr */
/* @0x13b6ac .word 0xffffbac4 */
/* @0x13b6b0 eoreq r4, r0, r8, lsr #26 */
/* @0x13b6b4 eoreq r4, r0, r8, ror #25 */

/* ── FUNC 0x13b6b8 · F_HttpGetFile(RValue&, CInstance*, CInstance*, int, RValue*) · size=376 · insn=94 */
/* @0x13b6b8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x13b6bc sub sp, sp, #1040 */
/* @0x13b6c0 ldr r5, [pc, #0x148] */
/* @0x13b6c4 sub sp, sp, #4 */
/* @0x13b6c8 ldr r2, [pc, #0x144] */
/* @0x13b6cc mov r4, r0 */
/* @0x13b6d0 add r5, pc, r5 */
/* @0x13b6d4 ldr r3, [pc, #0x13c] */
/* @0x13b6d8 ldr r9, [sp, #0x430] */
/* @0x13b6dc mov r1, #0 */
/* @0x13b6e0 ldr r7, [r5, r2] */
/* @0x13b6e4 mov r8, #1 */
/* @0x13b6e8 mov r0, r9 */
/* @0x13b6ec ldr r2, [r7] */
/* @0x13b6f0 str r2, [sp, #0x40c] */
/* @0x13b6f4 ldr r3, [r5, r3] */
/* @0x13b6f8 strb r8, [r3] */
/* @0x13b6fc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13b700 mov r1, r8 */
/* @0x13b704 mov r6, r0 */
/* @0x13b708 mov r0, r9 */
/* @0x13b70c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13b710 cmp r6, #0 */
/* @0x13b714 mov r1, #0 */
/* @0x13b718 mov r3, r1 */
/* @0x13b71c movt r1, #0xbff0 */
/* @0x13b720 str r3, [r4, #0xc] */
/* @0x13b724 str r1, [r4, #0x4] */
/* @0x13b728 str r3, [r4] */
/* @0x13b72c mov r8, r0 */
/* @0x13b730 beq 0x13b76c <_Z13F_HttpGetFileR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x13b734 ldr r0, [pc, #0xe0] */
/* @0x13b738 mov r1, r6 */
/* @0x13b73c mov r2, #7 */
/* @0x13b740 add r0, pc, r0 */
/* @0x13b744 bl 0xb65e0 <strncmp@plt> */
/* @0x13b748 cmp r0, #0 */
/* @0x13b74c beq 0x13b788 <_Z13F_HttpGetFileR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x13b750 ldr r0, [pc, #0xc8] */
/* @0x13b754 mov r1, r6 */
/* @0x13b758 mov r2, #8 */
/* @0x13b75c add r0, pc, r0 */
/* @0x13b760 bl 0xb65e0 <strncmp@plt> */
/* @0x13b764 cmp r0, #0 */
/* @0x13b768 beq 0x13b788 <_Z13F_HttpGetFileR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x13b76c ldr r2, [sp, #0x40c] */
/* @0x13b770 ldr r3, [r7] */
/* @0x13b774 cmp r2, r3 */
/* @0x13b778 bne 0x13b80c <_Z13F_HttpGetFileR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x13b77c add sp, sp, #1040 */
/* @0x13b780 add sp, sp, #4 */
/* @0x13b784 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x13b788 mov r2, r8 */
/* @0x13b78c add r8, sp, #12 */
/* @0x13b790 mov r1, #1024 */
/* @0x13b794 mov r0, r8 */
/* @0x13b798 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x13b79c mov r0, r8 */
/* @0x13b7a0 bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc> */
/* @0x13b7a4 mov r0, r8 */
/* @0x13b7a8 bl 0xb6538 <strlen@plt> */
/* @0x13b7ac ldr r1, [pc, #0x70] */
/* @0x13b7b0 mov r3, #1 */
/* @0x13b7b4 movw r2, #0x97b */
/* @0x13b7b8 add r1, pc, r1 */
/* @0x13b7bc add r0, r0, r3 */
/* @0x13b7c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x13b7c4 mov r1, r8 */
/* @0x13b7c8 bl 0xb65a4 <strcpy@plt> */
/* @0x13b7cc ldr lr, [pc, #0x54] */
/* @0x13b7d0 ldr r2, [pc, #0x54] */
/* @0x13b7d4 mov r3, #0 */
/* @0x13b7d8 mvn r1, #0 */
/* @0x13b7dc ldr lr, [r5, lr] */
/* @0x13b7e0 ldr r2, [r5, r2] */
/* @0x13b7e4 mov r12, r0 */
/* @0x13b7e8 str r12, [sp] */
/* @0x13b7ec ldr r5, [lr] */
/* @0x13b7f0 mov r0, r6 */
/* @0x13b7f4 bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_> */
/* @0x13b7f8 vmov s15, r5 */
/* @0x13b7fc vcvt.f64.s32 d7, s15 */
/* @0x13b800 vmov r2, r3, d7 */
/* @0x13b804 stm r4, {r2, r3} */
/* @0x13b808 b 0x13b76c <_Z13F_HttpGetFileR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x13b80c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13b810 eoreq r6, r11, r0, lsl #11 */
/* @0x13b814 .word 0xffffbd00 */
/* @0x13b818 .word 0xffffbd04 */
/* @0x13b81c andseq r5, pc, r0, lsr #7 */
/* @0x13b820 andseq r5, pc, r12, lsl #7 */
/* @0x13b824 mlaeq r0, r8, r8, r4 */
/* @0x13b828 .word 0xffffd628 */
/* @0x13b82c .word 0xffffd64c */

/* ── FUNC 0x13b830 · InitBinFiles() · size=68 · insn=17 */
/* @0x13b830 ldr r0, [pc, #0x34] */
/* @0x13b834 mov r2, #0 */
/* @0x13b838 ldr r1, [pc, #0x30] */
/* @0x13b83c ldr r0, [pc, r0] */
/* @0x13b840 ldr r1, [pc, r1] */
/* @0x13b844 add r3, r0, #8 */
/* @0x13b848 sub r1, r1, #1 */
/* @0x13b84c add r0, r0, #392 */
/* @0x13b850 str r2, [r3] */
/* @0x13b854 add r3, r3, #12 */
/* @0x13b858 str r2, [r3, #-0x14] */
/* @0x13b85c cmp r3, r0 */
/* @0x13b860 strb r2, [r1, #0x1]! */
/* @0x13b864 bne 0x13b850 <_Z12InitBinFilesv+0x20> */
/* @0x13b868 bx lr */
/* @0x13b86c eoreq r3, r11, r4, asr r10 */
/* @0x13b870 eoreq r3, r11, r12, asr #20 */

/* ── FUNC 0x13b874 · InitTextFiles() · size=68 · insn=17 */
/* @0x13b874 ldr r0, [pc, #0x34] */
/* @0x13b878 mov r2, #0 */
/* @0x13b87c ldr r1, [pc, #0x30] */
/* @0x13b880 ldr r0, [pc, r0] */
/* @0x13b884 ldr r1, [pc, r1] */
/* @0x13b888 add r3, r0, #8 */
/* @0x13b88c sub r1, r1, #4 */
/* @0x13b890 add r0, r0, #392 */
/* @0x13b894 str r2, [r3] */
/* @0x13b898 add r3, r3, #12 */
/* @0x13b89c str r2, [r3, #-0x14] */
/* @0x13b8a0 cmp r3, r0 */
/* @0x13b8a4 str r2, [r1, #0x4]! */
/* @0x13b8a8 bne 0x13b894 <_Z13InitTextFilesv+0x20> */
/* @0x13b8ac bx lr */
/* @0x13b8b0 .word 0x002b39f4 */
/* @0x13b8b4 eoreq r3, r11, r12, ror #19 */

/* ── FUNC 0x13b8b8 · MyStrToFloat(char const*) · size=208 · insn=52 */
/* @0x13b8b8 push {r4, r5, r6, lr} */
/* @0x13b8bc subs r6, r0, #0 */
/* @0x13b8c0 ldr r4, [pc, #0xb8] */
/* @0x13b8c4 sub sp, sp, #72 */
/* @0x13b8c8 ldr r4, [pc, r4] */
/* @0x13b8cc ldr r3, [r4] */
/* @0x13b8d0 str r3, [sp, #0x44] */
/* @0x13b8d4 beq 0x13b8f0 <_Z12MyStrToFloatPKc+0x38> */
/* @0x13b8d8 ldrb r3, [r6] */
/* @0x13b8dc cmp r3, #0 */
/* @0x13b8e0 beq 0x13b8f0 <_Z12MyStrToFloatPKc+0x38> */
/* @0x13b8e4 bl 0xb6538 <strlen@plt> */
/* @0x13b8e8 cmp r0, #63 */
/* @0x13b8ec bls 0x13b910 <_Z12MyStrToFloatPKc+0x58> */
/* @0x13b8f0 mov r0, #0 */
/* @0x13b8f4 mov r1, #0 */
/* @0x13b8f8 ldr r2, [sp, #0x44] */
/* @0x13b8fc ldr r3, [r4] */
/* @0x13b900 cmp r2, r3 */
/* @0x13b904 bne 0x13b97c <_Z12MyStrToFloatPKc+0xc4> */
/* @0x13b908 add sp, sp, #72 */
/* @0x13b90c pop {r4, r5, r6, pc} */
/* @0x13b910 add r5, sp, #4 */
/* @0x13b914 mov r1, #0 */
/* @0x13b918 mov r2, #64 */
/* @0x13b91c mov r0, r5 */
/* @0x13b920 bl 0xb65b0 <memset@plt> */
/* @0x13b924 ldr r2, [pc, #0x58] */
/* @0x13b928 mov r3, r6 */
/* @0x13b92c mov r1, #64 */
/* @0x13b930 add r2, pc, r2 */
/* @0x13b934 mov r0, r5 */
/* @0x13b938 bl 0xb65c8 <snprintf@plt> */
/* @0x13b93c mov r0, r5 */
/* @0x13b940 mov r1, #44 */
/* @0x13b944 bl 0xb6634 <strchr@plt> */
/* @0x13b948 cmp r0, #0 */
/* @0x13b94c movne r6, #46 */
/* @0x13b950 beq 0x13b96c <_Z12MyStrToFloatPKc+0xb4> */
/* @0x13b954 strb r6, [r0] */
/* @0x13b958 mov r1, #44 */
/* @0x13b95c mov r0, r5 */
/* @0x13b960 bl 0xb6634 <strchr@plt> */
/* @0x13b964 cmp r0, #0 */
/* @0x13b968 bne 0x13b954 <_Z12MyStrToFloatPKc+0x9c> */
/* @0x13b96c mov r0, r5 */
/* @0x13b970 mov r1, #0 */
/* @0x13b974 bl 0xb6658 <strtod@plt> */
/* @0x13b978 b 0x13b8f8 <_Z12MyStrToFloatPKc+0x40> */
/* @0x13b97c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13b980 eoreq r2, r11, r8, lsl #1 */
/* @0x13b984 ldrsbeq r9, [pc], -r8 */

/* ── FUNC 0x13b988 · YYGML_ini_close() · size=88 · insn=22 */
/* @0x13b988 push {r4, r5, r6, lr} */
/* @0x13b98c ldr r4, [pc, #0x48] */
/* @0x13b990 ldr r4, [pc, r4] */
/* @0x13b994 ldr r0, [r4] */
/* @0x13b998 cmp r0, #0 */
/* @0x13b99c beq 0x13b9d4 <_Z15YYGML_ini_closev+0x4c> */
/* @0x13b9a0 bl 0x235d3c <_ZN7IniFile12WriteIniFileEv> */
/* @0x13b9a4 ldr r5, [r4] */
/* @0x13b9a8 cmp r5, #0 */
/* @0x13b9ac mov r6, r0 */
/* @0x13b9b0 beq 0x13b9c4 <_Z15YYGML_ini_closev+0x3c> */
/* @0x13b9b4 mov r0, r5 */
/* @0x13b9b8 bl 0x235428 <_ZN7IniFileD2Ev> */
/* @0x13b9bc mov r0, r5 */
/* @0x13b9c0 bl 0x27d1d0 <_ZdlPv> */
/* @0x13b9c4 mov r3, #0 */
/* @0x13b9c8 str r3, [r4] */
/* @0x13b9cc mov r0, r6 */
/* @0x13b9d0 pop {r4, r5, r6, pc} */
/* @0x13b9d4 mov r6, r0 */
/* @0x13b9d8 b 0x13b9cc <_Z15YYGML_ini_closev+0x44> */
/* @0x13b9dc eoreq r3, r11, r4, lsl #18 */

/* ── FUNC 0x13b9e0 · F_IniClose(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x13b9e0 push {r3, r4, r5, lr} */
/* @0x13b9e4 mov r5, r0 */
/* @0x13b9e8 bl 0x13b988 <_Z15YYGML_ini_closev> */
/* @0x13b9ec mov r4, r0 */
/* @0x13b9f0 mov r0, r5 */
/* @0x13b9f4 mov r1, r4 */
/* @0x13b9f8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x13b9fc mov r0, r4 */
/* @0x13ba00 pop {r3, r4, r5, lr} */
/* @0x13ba04 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── FUNC 0x13ba08 · YYGML_ini_open_from_string(char const*) · size=112 · insn=28 */
/* @0x13ba08 push {r4, r5, r6, lr} */
/* @0x13ba0c mov r6, r0 */
/* @0x13ba10 ldr r4, [pc, #0x5c] */
/* @0x13ba14 ldr r4, [pc, r4] */
/* @0x13ba18 ldr r0, [r4] */
/* @0x13ba1c cmp r0, #0 */
/* @0x13ba20 beq 0x13ba50 <_Z26YYGML_ini_open_from_stringPKc+0x48> */
/* @0x13ba24 bl 0x235d3c <_ZN7IniFile12WriteIniFileEv> */
/* @0x13ba28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13ba2c ldr r5, [r4] */
/* @0x13ba30 cmp r5, #0 */
/* @0x13ba34 beq 0x13ba48 <_Z26YYGML_ini_open_from_stringPKc+0x40> */
/* @0x13ba38 mov r0, r5 */
/* @0x13ba3c bl 0x235428 <_ZN7IniFileD2Ev> */
/* @0x13ba40 mov r0, r5 */
/* @0x13ba44 bl 0x27d1d0 <_ZdlPv> */
/* @0x13ba48 mov r3, #0 */
/* @0x13ba4c str r3, [r4] */
/* @0x13ba50 mov r0, #28 */
/* @0x13ba54 bl 0x27c524 <_Znwj> */
/* @0x13ba58 mov r5, r0 */
/* @0x13ba5c bl 0x235488 <_ZN7IniFileC2Ev> */
/* @0x13ba60 mov r0, r5 */
/* @0x13ba64 mov r1, r6 */
/* @0x13ba68 str r5, [r4] */
/* @0x13ba6c pop {r4, r5, r6, lr} */
/* @0x13ba70 b 0x236250 <_ZN7IniFile7SetTextEPKc> */
/* @0x13ba74 eoreq r3, r11, r0, lsl #17 */

/* ── FUNC 0x13ba78 · F_IniOpenFromString(RValue&, CInstance*, CInstance*, int, RValue*) · size=52 · insn=13 */
/* @0x13ba78 push {r3, lr} */
/* @0x13ba7c mov r1, #0 */
/* @0x13ba80 ldr r0, [sp, #0x8] */
/* @0x13ba84 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13ba88 cmp r0, #0 */
/* @0x13ba8c beq 0x13ba98 <_Z19F_IniOpenFromStringR6RValueP9CInstanceS2_iPS_+0x20> */
/* @0x13ba90 pop {r3, lr} */
/* @0x13ba94 b 0x13ba08 <_Z26YYGML_ini_open_from_stringPKc> */
/* @0x13ba98 ldr r0, [pc, #0x8] */
/* @0x13ba9c pop {r3, lr} */
/* @0x13baa0 add r0, pc, r0 */
/* @0x13baa4 b 0x13ba08 <_Z26YYGML_ini_open_from_stringPKc> */
/* @0x13baa8 mulseq pc, r6, r0 */

/* ── FUNC 0x13baac · YYGML_ini_open(char const*) · size=112 · insn=28 */
/* @0x13baac push {r4, r5, r6, lr} */
/* @0x13bab0 subs r6, r0, #0 */
/* @0x13bab4 popeq {r4, r5, r6, pc} */
/* @0x13bab8 ldr r4, [pc, #0x58] */
/* @0x13babc ldr r4, [pc, r4] */
/* @0x13bac0 ldr r0, [r4] */
/* @0x13bac4 cmp r0, #0 */
/* @0x13bac8 beq 0x13baf8 <_Z14YYGML_ini_openPKc+0x4c> */
/* @0x13bacc bl 0x235d3c <_ZN7IniFile12WriteIniFileEv> */
/* @0x13bad0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x13bad4 ldr r5, [r4] */
/* @0x13bad8 cmp r5, #0 */
/* @0x13badc beq 0x13baf0 <_Z14YYGML_ini_openPKc+0x44> */
/* @0x13bae0 mov r0, r5 */
/* @0x13bae4 bl 0x235428 <_ZN7IniFileD2Ev> */
/* @0x13bae8 mov r0, r5 */
/* @0x13baec bl 0x27d1d0 <_ZdlPv> */
/* @0x13baf0 mov r3, #0 */
/* @0x13baf4 str r3, [r4] */
/* @0x13baf8 mov r0, #28 */
/* @0x13bafc bl 0x27c524 <_Znwj> */
/* @0x13bb00 mov r1, r6 */
/* @0x13bb04 mov r2, #0 */
/* @0x13bb08 mov r5, r0 */
/* @0x13bb0c bl 0x2362b8 <_ZN7IniFileC2EPcb> */
/* @0x13bb10 str r5, [r4] */
/* @0x13bb14 pop {r4, r5, r6, pc} */
/* @0x13bb18 .word 0x002b37d8 */

/* ── FUNC 0x13bb1c · F_IniOpen(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x13bb1c push {r3, lr} */
/* @0x13bb20 mov r1, #0 */
/* @0x13bb24 ldr r0, [sp, #0x8] */
/* @0x13bb28 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13bb2c pop {r3, lr} */
/* @0x13bb30 b 0x13baac <_Z14YYGML_ini_openPKc> */

/* ── FUNC 0x13bb34 · YYGML_ini_read_real(char const*, char const*, double) · size=112 · insn=28 */
/* @0x13bb34 ldr r12, [pc, #0x60] */
/* @0x13bb38 push {r4, r5, r6, lr} */
/* @0x13bb3c ldr r12, [pc, r12] */
/* @0x13bb40 mov r6, r0 */
/* @0x13bb44 mov lr, r1 */
/* @0x13bb48 ldr r0, [r12] */
/* @0x13bb4c mov r4, r2 */
/* @0x13bb50 mov r5, r3 */
/* @0x13bb54 cmp r0, #0 */
/* @0x13bb58 beq 0x13bb80 <_Z19YYGML_ini_read_realPKcS0_d+0x4c> */
/* @0x13bb5c mov r1, r6 */
/* @0x13bb60 mov r2, lr */
/* @0x13bb64 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x13bb68 cmp r0, #0 */
/* @0x13bb6c beq 0x13bb90 <_Z19YYGML_ini_read_realPKcS0_d+0x5c> */
/* @0x13bb70 ldr r0, [r0, #0x8] */
/* @0x13bb74 mov r1, #0 */
/* @0x13bb78 pop {r4, r5, r6, lr} */
/* @0x13bb7c b 0xb6658 <strtod@plt> */
/* @0x13bb80 mov r1, r0 */
/* @0x13bb84 ldr r0, [pc, #0x14] */
/* @0x13bb88 add r0, pc, r0 */
/* @0x13bb8c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13bb90 mov r0, r4 */
/* @0x13bb94 mov r1, r5 */
/* @0x13bb98 pop {r4, r5, r6, pc} */
/* @0x13bb9c eoreq r3, r11, r8, asr r7 */
/* @0x13bba0 eoreq r4, r0, r0, ror #13 */

/* ── FUNC 0x13bba4 · F_IniReadReal(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x13bba4 push {r3, r4, r5, r6, r7, lr} */
/* @0x13bba8 mov r1, #0 */
/* @0x13bbac ldr r4, [sp, #0x18] */
/* @0x13bbb0 mov r5, r0 */
/* @0x13bbb4 mov r0, r4 */
/* @0x13bbb8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13bbbc mov r1, #1 */
/* @0x13bbc0 mov r7, r0 */
/* @0x13bbc4 mov r0, r4 */
/* @0x13bbc8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13bbcc mov r1, #2 */
/* @0x13bbd0 mov r6, r0 */
/* @0x13bbd4 mov r0, r4 */
/* @0x13bbd8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13bbdc mov r12, #0 */
/* @0x13bbe0 str r12, [r5, #0xc] */
/* @0x13bbe4 mov r2, r0 */
/* @0x13bbe8 mov r3, r1 */
/* @0x13bbec mov r0, r7 */
/* @0x13bbf0 mov r1, r6 */
/* @0x13bbf4 bl 0x13bb34 <_Z19YYGML_ini_read_realPKcS0_d> */
/* @0x13bbf8 stm r5, {r0, r1} */
/* @0x13bbfc pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x13bc00 · YYGML_ini_write_real(char const*, char const*, double) · size=160 · insn=40 */
/* @0x13bc00 push {r4, r5, r6, r7, r8, lr} */
/* @0x13bc04 mov r7, r1 */
/* @0x13bc08 ldr r5, [pc, #0x80] */
/* @0x13bc0c sub sp, sp, #272 */
/* @0x13bc10 ldr r4, [pc, #0x7c] */
/* @0x13bc14 mov r8, r0 */
/* @0x13bc18 ldr r5, [pc, r5] */
/* @0x13bc1c ldr r4, [pc, r4] */
/* @0x13bc20 ldr r1, [r5] */
/* @0x13bc24 ldr lr, [r4] */
/* @0x13bc28 cmp r1, #0 */
/* @0x13bc2c str lr, [sp, #0x10c] */
/* @0x13bc30 beq 0x13bc7c <_Z20YYGML_ini_write_realPKcS0_d+0x7c> */
/* @0x13bc34 strd r2, r3, [sp] */
/* @0x13bc38 add r6, sp, #12 */
/* @0x13bc3c ldr r2, [pc, #0x54] */
/* @0x13bc40 mov r1, #256 */
/* @0x13bc44 mov r0, r6 */
/* @0x13bc48 add r2, pc, r2 */
/* @0x13bc4c bl 0xb65c8 <snprintf@plt> */
/* @0x13bc50 mov r3, r6 */
/* @0x13bc54 ldr r0, [r5] */
/* @0x13bc58 mov r1, r8 */
/* @0x13bc5c mov r2, r7 */
/* @0x13bc60 bl 0x235edc <_ZN7IniFile6SetKeyEPKcS1_S1_> */
/* @0x13bc64 ldr r2, [sp, #0x10c] */
/* @0x13bc68 ldr r3, [r4] */
/* @0x13bc6c cmp r2, r3 */
/* @0x13bc70 bne 0x13bc8c <_Z20YYGML_ini_write_realPKcS0_d+0x8c> */
/* @0x13bc74 add sp, sp, #272 */
/* @0x13bc78 pop {r4, r5, r6, r7, r8, pc} */
/* @0x13bc7c ldr r0, [pc, #0x18] */
/* @0x13bc80 add r0, pc, r0 */
/* @0x13bc84 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x13bc88 b 0x13bc64 <_Z20YYGML_ini_write_realPKcS0_d+0x64> */
/* @0x13bc8c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13bc90 eoreq r3, r11, r12, ror r6 */
/* @0x13bc94 eoreq r1, r11, r4, lsr sp */
/* @0x13bc98 eoreq r4, r0, r12, ror #14 */
/* @0x13bc9c eoreq r4, r0, r8, ror #11 */

/* ── FUNC 0x13bca0 · F_IniWriteReal(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x13bca0 push {r4, r5, r6, lr} */
/* @0x13bca4 mov r1, #0 */
/* @0x13bca8 ldr r4, [sp, #0x10] */
/* @0x13bcac mov r0, r4 */
/* @0x13bcb0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13bcb4 mov r1, #1 */
/* @0x13bcb8 mov r6, r0 */
/* @0x13bcbc mov r0, r4 */
/* @0x13bcc0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x13bcc4 mov r1, #2 */
/* @0x13bcc8 mov r5, r0 */
/* @0x13bccc mov r0, r4 */
/* @0x13bcd0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x13bcd4 mov r2, r0 */
/* @0x13bcd8 mov r3, r1 */
/* @0x13bcdc mov r0, r6 */
/* @0x13bce0 mov r1, r5 */
/* @0x13bce4 pop {r4, r5, r6, lr} */
/* @0x13bce8 b 0x13bc00 <_Z20YYGML_ini_write_realPKcS0_d> */

/* ── FUNC 0x13bcec · EncodeDSMap(CDS_Map*) · size=320 · insn=80 */
/* @0x13bcec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x13bcf0 sub sp, sp, #140 */
/* @0x13bcf4 ldr r10, [pc, #0x12c] */
/* @0x13bcf8 mov r4, r0 */
/* @0x13bcfc mov r7, #0 */
/* @0x13bd00 ldr r10, [pc, r10] */
/* @0x13bd04 ldr r3, [r10] */
/* @0x13bd08 str r3, [sp, #0x84] */
/* @0x13bd0c bl 0x27e89c <json_object_new_object> */
/* @0x13bd10 ldr r4, [r4] */
/* @0x13bd14 ldr r2, [r4] */
/* @0x13bd18 mov r8, r0 */
/* @0x13bd1c b 0x13bd30 <_Z11EncodeDSMapP7CDS_Map+0x44> */
/* @0x13bd20 ldr r3, [r4, #0x4] */
/* @0x13bd24 add r7, r7, #1 */
/* @0x13bd28 cmp r7, r3 */
/* @0x13bd2c bgt 0x13be1c <_Z11EncodeDSMapP7CDS_Map+0x130> */
/* @0x13bd30 ldr r6, [r2, r7, lsl #3] */
/* @0x13bd34 cmp r6, #0 */
/* @0x13bd38 beq 0x13bd20 <_Z11EncodeDSMapP7CDS_Map+0x34> */
/* @0x13bd3c add r9, sp, #4 */
/* @0x13bd40 cmp r6, #0 */
/* @0x13bd44 beq 0x13bdf0 <_Z11EncodeDSMapP7CDS_Map+0x104> */
/* @0x13bd48 ldr r0, [r6, #0xc] */
/* @0x13bd4c cmp r0, #0 */
/* @0x13bd50 beq 0x13bdf0 <_Z11EncodeDSMapP7CDS_Map+0x104> */
/* @0x13bd54 ldr r2, [r0, #0xc] */
/* @0x13bd58 add r5, r0, #16 */
/* @0x13bd5c bic r1, r2, #-16777216 */
/* @0x13bd60 cmp r1, #1 */
/* @0x13bd64 beq 0x13be0c <_Z11EncodeDSMapP7CDS_Map+0x120> */
/* @0x13bd68 cmp r2, #0 */
/* @0x13bd6c movne r11, #0 */
/* @0x13bd70 bne 0x13bd94 <_Z11EncodeDSMapP7CDS_Map+0xa8> */
/* @0x13bd74 vldr s14, [r0] */
/* @0x13bd78 vldr s15, [r0, #4] */
/* @0x13bd7c vcvt.s32.f64 s13, d7 */
/* @0x13bd80 mov r1, r9 */
/* @0x13bd84 mov r2, #10 */
/* @0x13bd88 mov r11, r9 */
/* @0x13bd8c vmov r0, s13 */
/* @0x13bd90 bl 0xc4964 <_Z5_itoaiPci> */
/* @0x13bd94 mov r0, r5 */
/* @0x13bd98 bl 0x13be2c <_Z11EncodeValueP6RValue> */
/* @0x13bd9c mov r1, r11 */
/* @0x13bda0 mov r2, r0 */
/* @0x13bda4 mov r0, r8 */
/* @0x13bda8 bl 0x27ea00 <json_object_object_add> */
/* @0x13bdac ldr r6, [r6, #0x4] */
/* @0x13bdb0 cmp r6, #0 */
/* @0x13bdb4 bne 0x13bd40 <_Z11EncodeDSMapP7CDS_Map+0x54> */
/* @0x13bdb8 ldr r1, [r4, #0x4] */
/* @0x13bdbc add r3, r7, #1 */
/* @0x13bdc0 cmp r3, r1 */
/* @0x13bdc4 bgt 0x13bdf0 <_Z11EncodeDSMapP7CDS_Map+0x104> */
/* @0x13bdc8 ldr r2, [r4] */
/* @0x13bdcc add r2, r2, r7, lsl #3 */
/* @0x13bdd0 ldr r6, [r2, #0x8] */
/* @0x13bdd4 mov r7, r3 */
/* @0x13bdd8 cmp r6, #0 */
/* @0x13bddc bne 0x13bd40 <_Z11EncodeDSMapP7CDS_Map+0x54> */
/* @0x13bde0 add r3, r3, #1 */
/* @0x13bde4 add r2, r2, #8 */
/* @0x13bde8 cmp r3, r1 */
/* @0x13bdec ble 0x13bdd0 <_Z11EncodeDSMapP7CDS_Map+0xe4> */
/* @0x13bdf0 ldr r2, [sp, #0x84] */
/* @0x13bdf4 mov r0, r8 */
/* @0x13bdf8 ldr r3, [r10] */
/* @0x13bdfc cmp r2, r3 */
/* @0x13be00 bne 0x13be24 <_Z11EncodeDSMapP7CDS_Map+0x138> */
/* @0x13be04 add sp, sp, #140 */
/* @0x13be08 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x13be0c ldr r11, [r0] */
/* @0x13be10 cmp r11, #0 */
/* @0x13be14 ldrne r11, [r11] */
/* @0x13be18 b 0x13bd94 <_Z11EncodeDSMapP7CDS_Map+0xa8> */
/* @0x13be1c mvn r7, #0 */
/* @0x13be20 b 0x13bd3c <_Z11EncodeDSMapP7CDS_Map+0x50> */
/* @0x13be24 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13be28 eoreq r1, r11, r0, asr r12 */

/* ── FUNC 0x13be2c · EncodeValue(RValue*) · size=560 · insn=140 */
/* @0x13be2c push {r4, r5, r6, lr} */
/* @0x13be30 sub sp, sp, #40 */
/* @0x13be34 ldr r4, [pc, #0x210] */
/* @0x13be38 mov r6, r0 */
/* @0x13be3c mov r0, sp */
/* @0x13be40 ldr r4, [pc, r4] */
/* @0x13be44 ldr r3, [r4] */
/* @0x13be48 str r3, [sp, #0x24] */
/* @0x13be4c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x13be50 ldr r3, [r6, #0xc] */
/* @0x13be54 cmp r3, #0 */
/* @0x13be58 blt 0x13bf28 <_Z11EncodeValueP6RValue+0xfc> */
/* @0x13be5c ands r12, r3, #1073741824 */
/* @0x13be60 beq 0x13bed0 <_Z11EncodeValueP6RValue+0xa4> */
/* @0x13be64 ldr r1, [pc, #0x1e4] */
/* @0x13be68 ldr r2, [r6] */
/* @0x13be6c ldr r1, [pc, r1] */
/* @0x13be70 vldr s12, [r1] */
/* @0x13be74 vcvt.f64.s32 d7, s12 */
/* @0x13be78 ldr r3, [r6, #0x4] */
/* @0x13be7c vmov d6, r2, r3 */
/* @0x13be80 vcmpe.f64 d6, d7 */
/* @0x13be84 vmrs APSR_nzcv, fpscr */
/* @0x13be88 bpl 0x13bf74 <_Z11EncodeValueP6RValue+0x148> */
/* @0x13be8c vcvt.s32.f64 s13, d6 */
/* @0x13be90 ldr r3, [r1, #0x4] */
/* @0x13be94 vmov r2, s13 */
/* @0x13be98 ldr r0, [r3, r2, lsl #2] */
/* @0x13be9c cmp r0, #0 */
/* @0x13bea0 beq 0x13c024 <_Z11EncodeValueP6RValue+0x1f8> */
/* @0x13bea4 bl 0x13c0e0 <_Z12EncodeDSListP8CDS_List> */
/* @0x13bea8 mov r6, r0 */
/* @0x13beac mov r0, sp */
/* @0x13beb0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x13beb4 ldr r2, [sp, #0x24] */
/* @0x13beb8 ldr r3, [r4] */
/* @0x13bebc mov r0, r6 */
/* @0x13bec0 cmp r2, r3 */
/* @0x13bec4 bne 0x13c048 <_Z11EncodeValueP6RValue+0x21c> */
/* @0x13bec8 add sp, sp, #40 */
/* @0x13becc pop {r4, r5, r6, pc} */
/* @0x13bed0 cmp r3, #7 */
/* @0x13bed4 beq 0x13bf7c <_Z11EncodeValueP6RValue+0x150> */
/* @0x13bed8 cmp r3, #10 */
/* @0x13bedc beq 0x13bf7c <_Z11EncodeValueP6RValue+0x150> */
/* @0x13bee0 cmp r3, #13 */
/* @0x13bee4 beq 0x13c000 <_Z11EncodeValueP6RValue+0x1d4> */
/* @0x13bee8 cmp r3, #0 */
/* @0x13beec beq 0x13bf8c <_Z11EncodeValueP6RValue+0x160> */
/* @0x13bef0 cmp r3, #3 */
/* @0x13bef4 beq 0x13bfb4 <_Z11EncodeValueP6RValue+0x188> */
/* @0x13bef8 cmp r3, #1 */
/* @0x13befc beq 0x13bf9c <_Z11EncodeValueP6RValue+0x170> */
/* @0x13bf00 cmp r3, #2 */
/* @0x13bf04 beq 0x13c02c <_Z11EncodeValueP6RValue+0x200> */
/* @0x13bf08 cmp r3, #5 */
/* @0x13bf0c beq 0x13c03c <_Z11EncodeValueP6RValue+0x210> */
/* @0x13bf10 cmp r3, #6 */
/* @0x13bf14 bne 0x13bf74 <_Z11EncodeValueP6RValue+0x148> */
/* @0x13bf18 mov r0, r6 */
/* @0x13bf1c bl 0x24a810 <_Z12EncodeObjectP6RValue> */
/* @0x13bf20 mov r6, r0 */
/* @0x13bf24 b 0x13beac <_Z11EncodeValueP6RValue+0x80> */
/* @0x13bf28 ldr r1, [pc, #0x124] */
/* @0x13bf2c ldr r2, [r6] */
/* @0x13bf30 ldr r1, [pc, r1] */
/* @0x13bf34 vldr s12, [r1] */
/* @0x13bf38 vcvt.f64.s32 d7, s12 */
/* @0x13bf3c ldr r3, [r6, #0x4] */
/* @0x13bf40 vmov d6, r2, r3 */
/* @0x13bf44 vcmpe.f64 d6, d7 */
/* @0x13bf48 vmrs APSR_nzcv, fpscr */
/* @0x13bf4c bpl 0x13bf74 <_Z11EncodeValueP6RValue+0x148> */
/* @0x13bf50 vcvt.s32.f64 s13, d6 */
/* @0x13bf54 ldr r3, [r1, #0x4] */
/* @0x13bf58 vmov r2, s13 */
/* @0x13bf5c ldr r0, [r3, r2, lsl #2] */
/* @0x13bf60 cmp r0, #0 */
/* @0x13bf64 beq 0x13c024 <_Z11EncodeValueP6RValue+0x1f8> */
/* @0x13bf68 bl 0x13bcec <_Z11EncodeDSMapP7CDS_Map> */
/* @0x13bf6c mov r6, r0 */
/* @0x13bf70 b 0x13beac <_Z11EncodeValueP6RValue+0x80> */
/* @0x13bf74 mov r6, #0 */
/* @0x13bf78 b 0x13beac <_Z11EncodeValueP6RValue+0x80> */
/* @0x13bf7c ldr r0, [r6] */
/* @0x13bf80 bl 0x27eaf8 <json_object_new_int> */
/* @0x13bf84 mov r6, r0 */
/* @0x13bf88 b 0x13beac <_Z11EncodeValueP6RValue+0x80> */
/* @0x13bf8c ldm r6, {r0, r1} */
/* @0x13bf90 bl 0x27ebb8 <json_object_new_double> */
/* @0x13bf94 mov r6, r0 */
/* @0x13bf98 b 0x13beac <_Z11EncodeValueP6RValue+0x80> */
/* @0x13bf9c ldr r0, [r6] */
/* @0x13bfa0 cmp r0, #0 */
/* @0x13bfa4 ldrne r0, [r0] */
/* @0x13bfa8 bl 0x27ecc0 <json_object_new_string> */
/* @0x13bfac mov r6, r0 */
/* @0x13bfb0 b 0x13beac <_Z11EncodeValueP6RValue+0x80> */
/* @0x13bfb4 ldr r3, [r6] */
/* @0x13bfb8 add r6, sp, #4 */
/* @0x13bfbc ldr r2, [pc, #0x94] */
/* @0x13bfc0 mov r1, #16 */
/* @0x13bfc4 mov r0, r6 */
/* @0x13bfc8 str r12, [sp, #0x4] */
/* @0x13bfcc add r2, pc, r2 */
/* @0x13bfd0 str r12, [sp, #0x8] */
/* @0x13bfd4 str r12, [sp, #0xc] */
/* @0x13bfd8 str r12, [sp, #0x10] */
/* @0x13bfdc str r12, [sp, #0x14] */
/* @0x13bfe0 str r12, [sp, #0x18] */
/* @0x13bfe4 str r12, [sp, #0x1c] */
/* @0x13bfe8 str r12, [sp, #0x20] */
/* @0x13bfec bl 0xb65c8 <snprintf@plt> */
/* @0x13bff0 mov r0, r6 */
/* @0x13bff4 bl 0x27ecc0 <json_object_new_string> */
/* @0x13bff8 mov r6, r0 */
/* @0x13bffc b 0x13beac <_Z11EncodeValueP6RValue+0x80> */
/* @0x13c000 ldm r6, {r2, r3} */
/* @0x13c004 vmov d7, r2, r3 */
/* @0x13c008 vcmp.f64 d7, #0 */
/* @0x13c00c vmrs APSR_nzcv, fpscr */
/* @0x13c010 moveq r0, #0 */
/* @0x13c014 movne r0, #1 */
/* @0x13c018 bl 0x27ea48 <json_object_new_boolean> */
/* @0x13c01c mov r6, r0 */
/* @0x13c020 b 0x13beac <_Z11EncodeValueP6RValue+0x80> */
/* @0x13c024 mov r6, r0 */
/* @0x13c028 b 0x13beac <_Z11EncodeValueP6RValue+0x80> */
/* @0x13c02c mov r0, r6 */
/* @0x13c030 bl 0x13c05c <_Z11EncodeArrayP6RValue> */
/* @0x13c034 mov r6, r0 */
/* @0x13c038 b 0x13beac <_Z11EncodeValueP6RValue+0x80> */
/* @0x13c03c bl 0x27ec98 <json_object_new_null> */
/* @0x13c040 mov r6, r0 */
/* @0x13c044 b 0x13beac <_Z11EncodeValueP6RValue+0x80> */
/* @0x13c048 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x13c04c eoreq r1, r11, r0, lsl r11 */
/* @0x13c050 eoreq r1, r11, r4, lsl lr */
/* @0x13c054 eoreq r1, r11, r12, lsl #20 */
/* @0x13c058 andseq r6, pc, r12, lsr r5 */

/* ── FUNC 0x13c05c · EncodeArray(RValue*) · size=132 · insn=33 */
/* @0x13c05c push {r4, r5, r6, r7, r8, lr} */
/* @0x13c060 mov r4, r0 */
/* @0x13c064 bl 0x27ed80 <json_object_new_array> */
/* @0x13c068 ldr r8, [r4] */
/* @0x13c06c cmp r8, #0 */
/* @0x13c070 mov r6, r0 */
/* @0x13c074 beq 0x13c0d8 <_Z11EncodeArrayP6RValue+0x7c> */
/* @0x13c078 ldr r2, [r8, #0x10] */
/* @0x13c07c cmp r2, #0 */
/* @0x13c080 ble 0x13c0d8 <_Z11EncodeArrayP6RValue+0x7c> */
/* @0x13c084 mov r7, #0 */
/* @0x13c088 ldr r3, [r8, #0x4] */
/* @0x13c08c add r5, r3, r7, lsl #3 */
/* @0x13c090 ldr r3, [r3, r7, lsl #3] */
/* @0x13c094 cmp r3, #0 */
/* @0x13c098 movgt r4, #0 */
/* @0x13c09c ble 0x13c0cc <_Z11EncodeArrayP6RValue+0x70> */
/* @0x13c0a0 ldr r0, [r5, #0x4] */
/* @0x13c0a4 add r0, r0, r4, lsl #4 */
/* @0x13c0a8 add r4, r4, #1 */
/* @0x13c0ac bl 0x13be2c <_Z11EncodeValueP6RValue> */
/* @0x13c0b0 mov r1, r0 */
/* @0x13c0b4 mov r0, r6 */
/* @0x13c0b8 bl 0x27edf0 <json_object_array_add> */
/* @0x13c0bc ldr r3, [r5] */
/* @0x13c0c0 cmp r3, r4 */
/* @0x13c0c4 bgt 0x13c0a0 <_Z11EncodeArrayP6RValue+0x44> */
/* @0x13c0c8 ldr r2, [r8, #0x10] */
/* @0x13c0cc add r7, r7, #1 */
/* @0x13c0d0 cmp r2, r7 */
/* @0x13c0d4 bgt 0x13c088 <_Z11EncodeArrayP6RValue+0x2c> */
/* @0x13c0d8 mov r0, r6 */
/* @0x13c0dc pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x13c0e0 · EncodeDSList(CDS_List*) · size=80 · insn=20 */
/* @0x13c0e0 push {r4, r5, r6, lr} */
/* @0x13c0e4 mov r5, r0 */
/* @0x13c0e8 bl 0x27ed80 <json_object_new_array> */
/* @0x13c0ec ldr r3, [r5, #0x4] */
/* @0x13c0f0 cmp r3, #0 */
/* @0x13c0f4 mov r6, r0 */
/* @0x13c0f8 ble 0x13c128 <_Z12EncodeDSListP8CDS_List+0x48> */
/* @0x13c0fc mov r4, #0 */
/* @0x13c100 ldr r0, [r5, #0xc] */
/* @0x13c104 add r0, r0, r4, lsl #4 */
/* @0x13c108 add r4, r4, #1 */
/* @0x13c10c bl 0x13be2c <_Z11EncodeValueP6RValue> */
/* @0x13c110 mov r1, r0 */
/* @0x13c114 mov r0, r6 */
/* @0x13c118 bl 0x27edf0 <json_object_array_add> */
/* @0x13c11c ldr r3, [r5, #0x4] */
/* @0x13c120 cmp r3, r4 */
/* @0x13c124 bgt 0x13c100 <_Z12EncodeDSListP8CDS_List+0x20> */
/* @0x13c128 mov r0, r6 */
/* @0x13c12c pop {r4, r5, r6, pc} */

/* ── FUNC 0x13c130 · F_JsonEncode(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0x13c130 push {r4, r5, r6, lr} */
/* @0x13c134 sub sp, sp, #8 */
/* @0x13c138 mov r4, r0 */
/* @0x13c13c mov r1, #0 */
/* @0x13c140 ldr r0, [sp, #0x18] */
/* @0x13c144 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x13c148 mov r2, #1 */
/* @0x13c14c mov r3, #0 */
/* @0x13c150 str r2, [r4, #0xc] */
/* @0x13c154 str r3, [r4] */
/* @0x13c158 subs r5, r0, #0 */
/* @0x13c15c blt 0x13c174 <_Z12F_JsonEncodeR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x13c160 ldr r3, [pc, #0x68] */
/* @0x13c164 ldr r3, [pc, r3] */
/* @0x13c168 ldr r3, [r3] */
/* @0x13c16c cmp r5, r3 */
/* @0x13c170 blt 0x13c17c <_Z12F_JsonEncodeR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x13c174 add sp, sp, #8 */
/* @0x13c178 pop {r4, r5, r6, pc} */
/* @0x13c17c add r6, sp, #4 */
/* @0x13c180 mov r0, r6 */
/* @0x13c184 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x13c188 ldr r3, [pc, #0x44] */
/* @0x13c18c ldr r3, [pc, r3] */
/* @0x13c190 ldr r3, [r3, #0x4] */
/* @0x13c194 ldr r0, [r3, r5, lsl #2] */
/* @0x13c198 cmp r0, #0 */
/* @0x13c19c beq 0x13c1c0 <_Z12F_JsonEncodeR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x13c1a0 bl 0x13bcec <_Z11EncodeDSMapP7CDS_Map> */
/* @0x13c1a4 mov r5, r0 */
/* @0x13c1a8 bl 0x27e830 <json_object_to_json_string> */
/* @0x13c1ac mov r1, r0 */
/* @0x13c1b0 mov r0, r4 */
/* @0x13c1b4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x13c1b8 mov r0, r5 */
/* @0x13c1bc bl 0x27e7c8 <json_object_put> */
/* @0x13c1c0 mov r0, r6 */
/* @0x13c1c4 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x13c1c8 add sp, sp, #8 */
/* @0x13c1cc pop {r4, r5, r6, pc} */
/* @0x13c1d0 eoreq r1, r11, r4, lsl r11 */
/* @0x13c1d4 .word 0x002b17b0 */

/* ── FUNC 0x13c1d8 · DSMapToJSON(int, char**) · size=156 · insn=39 */
/* @0x13c1d8 push {r4, r5, r6, lr} */
/* @0x13c1dc subs r4, r0, #0 */
/* @0x13c1e0 sub sp, sp, #8 */
/* @0x13c1e4 mov r5, r1 */
/* @0x13c1e8 blt 0x13c200 <_Z11DSMapToJSONiPPc+0x28> */
/* @0x13c1ec ldr r3, [pc, #0x78] */
/* @0x13c1f0 ldr r3, [pc, r3] */
/* @0x13c1f4 ldr r3, [r3] */
/* @0x13c1f8 cmp r4, r3 */
/* @0x13c1fc blt 0x13c208 <_Z11DSMapToJSONiPPc+0x30> */
/* @0x13c200 add sp, sp, #8 */
/* @0x13c204 pop {r4, r5, r6, pc} */
/* @0x13c208 add r6, sp, #4 */
/* @0x13c20c mov r0, r6 */
/* @0x13c210 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x13c214 ldr r3, [pc, #0x54] */
/* @0x13c218 ldr r3, [pc, r3] */
/* @0x13c21c ldr r3, [r3, #0x4] */
/* @0x13c220 ldr r0, [r3, r4, lsl #2] */
/* @0x13c224 cmp r0, #0 */
/* @0x13c228 beq 0x13c25c <_Z11DSMapToJSONiPPc+0x84> */
/* @0x13c22c bl 0x13bcec <_Z11EncodeDSMapP7CDS_Map> */
/* @0x13c230 mov r4, r0 */
/* @0x13c234 ldr r0, [r5] */
/* @0x13c238 cmp r0, #0 */
/* @0x13c23c beq 0x13c244 <_Z11DSMapToJSONiPPc+0x6c> */
/* @0x13c240 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x13c244 mov r0, r4 */
/* @0x13c248 bl 0x27e830 <json_object_to_json_string> */
/* @0x13c24c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x13c250 str r0, [r5] */
/* @0x13c254 mov r0, r4 */
/* @0x13c258 bl 0x27e7c8 <json_object_put> */
/* @0x13c25c mov r0, r6 */
/* @0x13c260 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x13c264 add sp, sp, #8 */
/* @0x13c268 pop {r4, r5, r6, pc} */
/* @0x13c26c eoreq r1, r11, r8, lsl #21 */
/* @0x13c270 eoreq r1, r11, r4, lsr #14 */

/* ── FUNC 0x13c274 · json_value(json_object*, RValue*) · size=220 · insn=55 */
/* @0x13c274 push {r3, r4, r5, lr} */
/* @0x13c278 subs r5, r0, #0 */
/* @0x13c27c mov r4, r1 */
/* @0x13c280 beq 0x13c2b0 <_Z10json_valueP11json_objectP6RValue+0x3c> */
/* @0x13c284 bl 0x27e828 <json_object_get_type> */
/* @0x13c288 cmp r0, #6 */
/* @0x13c28c addls pc, pc, r0, lsl #2 */
/* @0x13c290 b 0x13c2c4 <_Z10json_valueP11json_objectP6RValue+0x50> */
/* @0x13c294 b 0x13c2b0 <_Z10json_valueP11json_objectP6RValue+0x3c> */
/* @0x13c298 b 0x13c2e0 <_Z10json_valueP11json_objectP6RValue+0x6c> */
/* @0x13c29c b 0x13c30c <_Z10json_valueP11json_objectP6RValue+0x98> */
/* @0x13c2a0 b 0x13c324 <_Z10json_valueP11json_objectP6RValue+0xb0> */
/* @0x13c2a4 b 0x13c2c4 <_Z10json_valueP11json_objectP6RValue+0x50> */
/* @0x13c2a8 b 0x13c2c4 <_Z10json_valueP11json_objectP6RValue+0x50> */
/* @0x13c2ac b 0x13c2c8 <_Z10json_valueP11json_objectP6RValue+0x54> */
/* @0x13c2b0 mov r3, #0 */
/* @0x13c2b4 mov r2, #5 */
/* @0x13c2b8 str r3, [r4] */
/* @0x13c2bc str r2, [r4, #0xc] */
/* @0x13c2c0 str r3, [r4, #0x4] */
/* @0x13c2c4 pop {r3, r4, r5, pc} */
/* @0x13c2c8 mov r0, r5 */
/* @0x13c2cc bl 0x27ed58 <json_object_get_string> */
/* @0x13c2d0 mov r1, r0 */
/* @0x13c2d4 mov r0, r4 */
/* @0x13c2d8 pop {r3, r4, r5, lr} */
/* @0x13c2dc b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x13c2e0 mov r0, r5 */
/* @0x13c2e4 mov r5, #0 */
/* @0x13c2e8 str r5, [r4, #0xc] */
/* @0x13c2ec bl 0x27ea78 <json_object_get_boolean> */
/* @0x13c2f0 cmp r0, #0 */
/* @0x13c2f4 movne r0, r5 */
/* @0x13c2f8 moveq r3, r0 */
/* @0x13c2fc movne r3, r0 */
/* @0x13c300 movtne r3, #0x3ff0 */
/* @0x13c304 stm r4, {r0, r3} */
/* @0x13c308 pop {r3, r4, r5, pc} */
/* @0x13c30c mov r3, #0 */
/* @0x13c310 mov r0, r5 */
/* @0x13c314 str r3, [r4, #0xc] */
/* @0x13c318 bl 0x27ebf0 <json_object_get_double> */
/* @0x13c31c stm r4, {r0, r1} */
/* @0x13c320 pop {r3, r4, r5, pc} */
/* @0x13c324 mov r3, #0 */
/* @0x13c328 mov r0, r5 */
/* @0x13c32c str r3, [r4, #0xc] */
/* @0x13c330 bl 0x27eb28 <json_object_get_int> */
/* @0x13c334 vmov s15, r0 */
/* @0x13c338 vcvt.f64.s32 d7, s15 */
/* @0x13c33c vmov r0, r1, d7 */
/* @0x13c340 vmov r2, s14 */
/* @0x13c344 mov r3, r1 */
/* @0x13c348 stm r4, {r2, r3} */
/* @0x13c34c pop {r3, r4, r5, pc} */

/* ── FUNC 0x13c350 · findfirstnonspace(char const*, int, int) · size=92 · insn=23 */
/* @0x13c350 cmp r2, #0 */
/* @0x13c354 str r4, [sp, #-0x4]! */
/* @0x13c358 ble 0x13c3a0 <_Z17findfirstnonspacePKcii+0x50> */
/* @0x13c35c ldr r3, [pc, #0x44] */
/* @0x13c360 ldrb r4, [r0] */
/* @0x13c364 ldr r3, [pc, r3] */
/* @0x13c368 ldr r12, [r3] */
/* @0x13c36c add r3, r12, r4 */
/* @0x13c370 ldrb r3, [r3, #0x1] */
/* @0x13c374 tst r3, #8 */
/* @0x13c378 bne 0x13c394 <_Z17findfirstnonspacePKcii+0x44> */
/* @0x13c37c b 0x13c3a0 <_Z17findfirstnonspacePKcii+0x50> */
/* @0x13c380 ldrb r3, [r0] */
/* @0x13c384 add r3, r12, r3 */
/* @0x13c388 ldrb r3, [r3, #0x1] */
/* @0x13c38c tst r3, #8 */
/* @0x13c390 beq 0x13c3a0 <_Z17findfirstnonspacePKcii+0x50> */
/* @0x13c394 subs r2, r2, #1 */
/* @0x13c398 add r0, r0, r1 */
/* @0x13c39c bne 0x13c380 <_Z17findfirstnonspacePKcii+0x30> */
/* @0x13c3a0 ldr r4, [sp], #4 */
/* @0x13c3a4 bx lr */
/* @0x13c3a8 eoreq r1, r11, r12, lsl r6 */

/* ── FUNC 0x13c3ac · ParamCount() · size=20 · insn=5 */
/* @0x13c3ac ldr r3, [pc, #0x8] */
/* @0x13c3b0 ldr r3, [pc, r3] */
/* @0x13c3b4 ldr r0, [r3] */
/* @0x13c3b8 bx lr */
/* @0x13c3bc .word 0x002b2ef0 */
