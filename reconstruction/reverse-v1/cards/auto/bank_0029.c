/* libyoyo.so 覆盖卡组 0029
 * 函数 0xfdf48..0xff49c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xfdf48 · F_DsGridGetMean(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0xfdf48 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfdf4c sub sp, sp, #12 */
/* @0xfdf50 mov r1, #0 */
/* @0xfdf54 mov r8, r0 */
/* @0xfdf58 ldr r4, [sp, #0x28] */
/* @0xfdf5c mov r0, r4 */
/* @0xfdf60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdf64 mov r1, #1 */
/* @0xfdf68 mov r5, r0 */
/* @0xfdf6c mov r0, r4 */
/* @0xfdf70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdf74 mov r1, #2 */
/* @0xfdf78 mov r7, r0 */
/* @0xfdf7c mov r0, r4 */
/* @0xfdf80 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdf84 mov r1, #3 */
/* @0xfdf88 mov r6, r0 */
/* @0xfdf8c mov r0, r4 */
/* @0xfdf90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdf94 mov r1, #4 */
/* @0xfdf98 mov r9, r0 */
/* @0xfdf9c mov r0, r4 */
/* @0xfdfa0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdfa4 cmp r5, #0 */
/* @0xfdfa8 mov r2, r0 */
/* @0xfdfac blt 0xfdffc <_Z15F_DsGridGetMeanR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfdfb0 ldr r12, [pc, #0x5c] */
/* @0xfdfb4 ldr r12, [pc, r12] */
/* @0xfdfb8 ldr r3, [r12] */
/* @0xfdfbc cmp r5, r3 */
/* @0xfdfc0 bge 0xfdffc <_Z15F_DsGridGetMeanR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfdfc4 ldr r12, [pc, #0x4c] */
/* @0xfdfc8 ldr r12, [pc, r12] */
/* @0xfdfcc ldr r3, [r12, #0x4] */
/* @0xfdfd0 ldr r0, [r3, r5, lsl #2] */
/* @0xfdfd4 cmp r0, #0 */
/* @0xfdfd8 beq 0xfdffc <_Z15F_DsGridGetMeanR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfdfdc str r2, [sp, #0x4] */
/* @0xfdfe0 mov r1, r8 */
/* @0xfdfe4 str r9, [sp] */
/* @0xfdfe8 mov r2, r7 */
/* @0xfdfec mov r3, r6 */
/* @0xfdff0 bl 0x2042c8 <_ZN8CDS_Grid8Get_MeanER6RValueiiii> */
/* @0xfdff4 add sp, sp, #12 */
/* @0xfdff8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xfdffc ldr r0, [pc, #0x18] */
/* @0xfe000 mov r1, #0 */
/* @0xfe004 add r0, pc, r0 */
/* @0xfe008 add sp, sp, #12 */
/* @0xfe00c pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfe010 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfe014 .word 0x002efed0 */
/* @0xfe018 eoreq pc, lr, r0, asr #29 */
/* @0xfe01c .word 0x00239bf8 */

/* ── FUNC 0xfe020 · F_DsGridGetDiskSum(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0xfe020 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe024 sub sp, sp, #16 */
/* @0xfe028 mov r1, #0 */
/* @0xfe02c mov r9, r0 */
/* @0xfe030 ldr r8, [sp, #0x30] */
/* @0xfe034 mov r0, r8 */
/* @0xfe038 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe03c mov r1, #1 */
/* @0xfe040 mov r10, r0 */
/* @0xfe044 mov r0, r8 */
/* @0xfe048 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe04c mov r4, r0 */
/* @0xfe050 mov r5, r1 */
/* @0xfe054 mov r0, r8 */
/* @0xfe058 mov r1, #2 */
/* @0xfe05c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe060 mov r6, r0 */
/* @0xfe064 mov r7, r1 */
/* @0xfe068 mov r0, r8 */
/* @0xfe06c mov r1, #3 */
/* @0xfe070 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe074 cmp r10, #0 */
/* @0xfe078 mov r2, r0 */
/* @0xfe07c mov r3, r1 */
/* @0xfe080 blt 0xfe0d0 <_Z18F_DsGridGetDiskSumR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xfe084 ldr r1, [pc, #0x5c] */
/* @0xfe088 ldr r1, [pc, r1] */
/* @0xfe08c ldr r1, [r1] */
/* @0xfe090 cmp r10, r1 */
/* @0xfe094 bge 0xfe0d0 <_Z18F_DsGridGetDiskSumR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xfe098 ldr r1, [pc, #0x4c] */
/* @0xfe09c ldr r1, [pc, r1] */
/* @0xfe0a0 ldr r1, [r1, #0x4] */
/* @0xfe0a4 ldr r0, [r1, r10, lsl #2] */
/* @0xfe0a8 cmp r0, #0 */
/* @0xfe0ac beq 0xfe0d0 <_Z18F_DsGridGetDiskSumR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xfe0b0 strd r2, r3, [sp, #8] */
/* @0xfe0b4 mov r1, r9 */
/* @0xfe0b8 strd r6, r7, [sp] */
/* @0xfe0bc mov r2, r4 */
/* @0xfe0c0 mov r3, r5 */
/* @0xfe0c4 bl 0x20441c <_ZN8CDS_Grid12Get_Disk_SumER6RValueddd> */
/* @0xfe0c8 add sp, sp, #16 */
/* @0xfe0cc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xfe0d0 ldr r0, [pc, #0x18] */
/* @0xfe0d4 mov r1, #0 */
/* @0xfe0d8 add r0, pc, r0 */
/* @0xfe0dc add sp, sp, #16 */
/* @0xfe0e0 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe0e4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfe0e8 .word 0x002efdfc */
/* @0xfe0ec eoreq pc, lr, r12, ror #27 */
/* @0xfe0f0 eoreq r9, r3, r4, lsr #22 */

/* ── FUNC 0xfe0f4 · F_DsGridGetDiskMin(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0xfe0f4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe0f8 sub sp, sp, #16 */
/* @0xfe0fc mov r1, #0 */
/* @0xfe100 mov r9, r0 */
/* @0xfe104 ldr r8, [sp, #0x30] */
/* @0xfe108 mov r0, r8 */
/* @0xfe10c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe110 mov r1, #1 */
/* @0xfe114 mov r10, r0 */
/* @0xfe118 mov r0, r8 */
/* @0xfe11c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe120 mov r4, r0 */
/* @0xfe124 mov r5, r1 */
/* @0xfe128 mov r0, r8 */
/* @0xfe12c mov r1, #2 */
/* @0xfe130 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe134 mov r6, r0 */
/* @0xfe138 mov r7, r1 */
/* @0xfe13c mov r0, r8 */
/* @0xfe140 mov r1, #3 */
/* @0xfe144 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe148 cmp r10, #0 */
/* @0xfe14c mov r2, r0 */
/* @0xfe150 mov r3, r1 */
/* @0xfe154 blt 0xfe1a4 <_Z18F_DsGridGetDiskMinR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xfe158 ldr r1, [pc, #0x5c] */
/* @0xfe15c ldr r1, [pc, r1] */
/* @0xfe160 ldr r1, [r1] */
/* @0xfe164 cmp r10, r1 */
/* @0xfe168 bge 0xfe1a4 <_Z18F_DsGridGetDiskMinR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xfe16c ldr r1, [pc, #0x4c] */
/* @0xfe170 ldr r1, [pc, r1] */
/* @0xfe174 ldr r1, [r1, #0x4] */
/* @0xfe178 ldr r0, [r1, r10, lsl #2] */
/* @0xfe17c cmp r0, #0 */
/* @0xfe180 beq 0xfe1a4 <_Z18F_DsGridGetDiskMinR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xfe184 strd r2, r3, [sp, #8] */
/* @0xfe188 mov r1, r9 */
/* @0xfe18c strd r6, r7, [sp] */
/* @0xfe190 mov r2, r4 */
/* @0xfe194 mov r3, r5 */
/* @0xfe198 bl 0x207588 <_ZN8CDS_Grid12Get_Disk_MinER6RValueddd> */
/* @0xfe19c add sp, sp, #16 */
/* @0xfe1a0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xfe1a4 ldr r0, [pc, #0x18] */
/* @0xfe1a8 mov r1, #0 */
/* @0xfe1ac add r0, pc, r0 */
/* @0xfe1b0 add sp, sp, #16 */
/* @0xfe1b4 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe1b8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfe1bc eoreq pc, lr, r8, lsr #26 */
/* @0xfe1c0 eoreq pc, lr, r8, lsl sp */
/* @0xfe1c4 eoreq r9, r3, r0, asr r10 */

/* ── FUNC 0xfe1c8 · F_DsGridGetDiskMax(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0xfe1c8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe1cc sub sp, sp, #16 */
/* @0xfe1d0 mov r1, #0 */
/* @0xfe1d4 mov r9, r0 */
/* @0xfe1d8 ldr r8, [sp, #0x30] */
/* @0xfe1dc mov r0, r8 */
/* @0xfe1e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe1e4 mov r1, #1 */
/* @0xfe1e8 mov r10, r0 */
/* @0xfe1ec mov r0, r8 */
/* @0xfe1f0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe1f4 mov r4, r0 */
/* @0xfe1f8 mov r5, r1 */
/* @0xfe1fc mov r0, r8 */
/* @0xfe200 mov r1, #2 */
/* @0xfe204 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe208 mov r6, r0 */
/* @0xfe20c mov r7, r1 */
/* @0xfe210 mov r0, r8 */
/* @0xfe214 mov r1, #3 */
/* @0xfe218 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe21c cmp r10, #0 */
/* @0xfe220 mov r2, r0 */
/* @0xfe224 mov r3, r1 */
/* @0xfe228 blt 0xfe278 <_Z18F_DsGridGetDiskMaxR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xfe22c ldr r1, [pc, #0x5c] */
/* @0xfe230 ldr r1, [pc, r1] */
/* @0xfe234 ldr r1, [r1] */
/* @0xfe238 cmp r10, r1 */
/* @0xfe23c bge 0xfe278 <_Z18F_DsGridGetDiskMaxR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xfe240 ldr r1, [pc, #0x4c] */
/* @0xfe244 ldr r1, [pc, r1] */
/* @0xfe248 ldr r1, [r1, #0x4] */
/* @0xfe24c ldr r0, [r1, r10, lsl #2] */
/* @0xfe250 cmp r0, #0 */
/* @0xfe254 beq 0xfe278 <_Z18F_DsGridGetDiskMaxR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xfe258 strd r2, r3, [sp, #8] */
/* @0xfe25c mov r1, r9 */
/* @0xfe260 strd r6, r7, [sp] */
/* @0xfe264 mov r2, r4 */
/* @0xfe268 mov r3, r5 */
/* @0xfe26c bl 0x207104 <_ZN8CDS_Grid12Get_Disk_MaxER6RValueddd> */
/* @0xfe270 add sp, sp, #16 */
/* @0xfe274 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xfe278 ldr r0, [pc, #0x18] */
/* @0xfe27c mov r1, #0 */
/* @0xfe280 add r0, pc, r0 */
/* @0xfe284 add sp, sp, #16 */
/* @0xfe288 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe28c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfe290 eoreq pc, lr, r4, asr r12 */
/* @0xfe294 eoreq pc, lr, r4, asr #24 */
/* @0xfe298 eoreq r9, r3, r12, ror r9 */

/* ── FUNC 0xfe29c · F_DsGridGetDiskMean(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0xfe29c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe2a0 sub sp, sp, #16 */
/* @0xfe2a4 mov r1, #0 */
/* @0xfe2a8 mov r9, r0 */
/* @0xfe2ac ldr r8, [sp, #0x30] */
/* @0xfe2b0 mov r0, r8 */
/* @0xfe2b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe2b8 mov r1, #1 */
/* @0xfe2bc mov r10, r0 */
/* @0xfe2c0 mov r0, r8 */
/* @0xfe2c4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe2c8 mov r4, r0 */
/* @0xfe2cc mov r5, r1 */
/* @0xfe2d0 mov r0, r8 */
/* @0xfe2d4 mov r1, #2 */
/* @0xfe2d8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe2dc mov r6, r0 */
/* @0xfe2e0 mov r7, r1 */
/* @0xfe2e4 mov r0, r8 */
/* @0xfe2e8 mov r1, #3 */
/* @0xfe2ec bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe2f0 cmp r10, #0 */
/* @0xfe2f4 mov r2, r0 */
/* @0xfe2f8 mov r3, r1 */
/* @0xfe2fc blt 0xfe34c <_Z19F_DsGridGetDiskMeanR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xfe300 ldr r1, [pc, #0x5c] */
/* @0xfe304 ldr r1, [pc, r1] */
/* @0xfe308 ldr r1, [r1] */
/* @0xfe30c cmp r10, r1 */
/* @0xfe310 bge 0xfe34c <_Z19F_DsGridGetDiskMeanR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xfe314 ldr r1, [pc, #0x4c] */
/* @0xfe318 ldr r1, [pc, r1] */
/* @0xfe31c ldr r1, [r1, #0x4] */
/* @0xfe320 ldr r0, [r1, r10, lsl #2] */
/* @0xfe324 cmp r0, #0 */
/* @0xfe328 beq 0xfe34c <_Z19F_DsGridGetDiskMeanR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xfe32c strd r2, r3, [sp, #8] */
/* @0xfe330 mov r1, r9 */
/* @0xfe334 strd r6, r7, [sp] */
/* @0xfe338 mov r2, r4 */
/* @0xfe33c mov r3, r5 */
/* @0xfe340 bl 0x2045bc <_ZN8CDS_Grid13Get_Disk_MeanER6RValueddd> */
/* @0xfe344 add sp, sp, #16 */
/* @0xfe348 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xfe34c ldr r0, [pc, #0x18] */
/* @0xfe350 mov r1, #0 */
/* @0xfe354 add r0, pc, r0 */
/* @0xfe358 add sp, sp, #16 */
/* @0xfe35c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe360 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfe364 eoreq pc, lr, r0, lsl #23 */
/* @0xfe368 eoreq pc, lr, r0, ror r11 */
/* @0xfe36c eoreq r9, r3, r8, lsr #17 */

/* ── FUNC 0xfe370 · F_DsGridValueExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0xfe370 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfe374 sub sp, sp, #20 */
/* @0xfe378 mov r1, #0 */
/* @0xfe37c mov r8, r0 */
/* @0xfe380 ldr r4, [sp, #0x30] */
/* @0xfe384 mov r0, r4 */
/* @0xfe388 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe38c mov r1, #1 */
/* @0xfe390 mov r5, r0 */
/* @0xfe394 mov r0, r4 */
/* @0xfe398 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe39c mov r1, #2 */
/* @0xfe3a0 mov r7, r0 */
/* @0xfe3a4 mov r0, r4 */
/* @0xfe3a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe3ac mov r1, #3 */
/* @0xfe3b0 mov r6, r0 */
/* @0xfe3b4 mov r0, r4 */
/* @0xfe3b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe3bc mov r1, #4 */
/* @0xfe3c0 mov r9, r0 */
/* @0xfe3c4 mov r0, r4 */
/* @0xfe3c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe3cc cmp r5, #0 */
/* @0xfe3d0 mov r2, r0 */
/* @0xfe3d4 blt 0xfe428 <_Z19F_DsGridValueExistsR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe3d8 ldr r12, [pc, #0x60] */
/* @0xfe3dc ldr r12, [pc, r12] */
/* @0xfe3e0 ldr r3, [r12] */
/* @0xfe3e4 cmp r5, r3 */
/* @0xfe3e8 bge 0xfe428 <_Z19F_DsGridValueExistsR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe3ec ldr r12, [pc, #0x50] */
/* @0xfe3f0 ldr r12, [pc, r12] */
/* @0xfe3f4 ldr r3, [r12, #0x4] */
/* @0xfe3f8 ldr r0, [r3, r5, lsl #2] */
/* @0xfe3fc cmp r0, #0 */
/* @0xfe400 beq 0xfe428 <_Z19F_DsGridValueExistsR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe404 add r4, r4, #80 */
/* @0xfe408 str r9, [sp] */
/* @0xfe40c stmib sp, {r2, r4} */
/* @0xfe410 mov r1, r8 */
/* @0xfe414 mov r2, r7 */
/* @0xfe418 mov r3, r6 */
/* @0xfe41c bl 0x20478c <_ZN8CDS_Grid12Value_ExistsER6RValueiiiiPS0_> */
/* @0xfe420 add sp, sp, #20 */
/* @0xfe424 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xfe428 ldr r0, [pc, #0x18] */
/* @0xfe42c mov r1, #0 */
/* @0xfe430 add r0, pc, r0 */
/* @0xfe434 add sp, sp, #20 */
/* @0xfe438 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfe43c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfe440 eoreq pc, lr, r8, lsr #21 */
/* @0xfe444 mlaeq lr, r8, r10, pc */
/* @0xfe448 eoreq r9, r3, r12, asr #15 */

/* ── FUNC 0xfe44c · F_DsGridValueX(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0xfe44c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfe450 sub sp, sp, #20 */
/* @0xfe454 mov r1, #0 */
/* @0xfe458 mov r8, r0 */
/* @0xfe45c ldr r4, [sp, #0x30] */
/* @0xfe460 mov r0, r4 */
/* @0xfe464 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe468 mov r1, #1 */
/* @0xfe46c mov r5, r0 */
/* @0xfe470 mov r0, r4 */
/* @0xfe474 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe478 mov r1, #2 */
/* @0xfe47c mov r7, r0 */
/* @0xfe480 mov r0, r4 */
/* @0xfe484 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe488 mov r1, #3 */
/* @0xfe48c mov r6, r0 */
/* @0xfe490 mov r0, r4 */
/* @0xfe494 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe498 mov r1, #4 */
/* @0xfe49c mov r9, r0 */
/* @0xfe4a0 mov r0, r4 */
/* @0xfe4a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe4a8 cmp r5, #0 */
/* @0xfe4ac mov r2, r0 */
/* @0xfe4b0 blt 0xfe504 <_Z14F_DsGridValueXR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe4b4 ldr r12, [pc, #0x60] */
/* @0xfe4b8 ldr r12, [pc, r12] */
/* @0xfe4bc ldr r3, [r12] */
/* @0xfe4c0 cmp r5, r3 */
/* @0xfe4c4 bge 0xfe504 <_Z14F_DsGridValueXR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe4c8 ldr r12, [pc, #0x50] */
/* @0xfe4cc ldr r12, [pc, r12] */
/* @0xfe4d0 ldr r3, [r12, #0x4] */
/* @0xfe4d4 ldr r0, [r3, r5, lsl #2] */
/* @0xfe4d8 cmp r0, #0 */
/* @0xfe4dc beq 0xfe504 <_Z14F_DsGridValueXR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe4e0 add r4, r4, #80 */
/* @0xfe4e4 str r9, [sp] */
/* @0xfe4e8 stmib sp, {r2, r4} */
/* @0xfe4ec mov r1, r8 */
/* @0xfe4f0 mov r2, r7 */
/* @0xfe4f4 mov r3, r6 */
/* @0xfe4f8 bl 0x20489c <_ZN8CDS_Grid7Value_XER6RValueiiiiPS0_> */
/* @0xfe4fc add sp, sp, #20 */
/* @0xfe500 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xfe504 ldr r0, [pc, #0x18] */
/* @0xfe508 mov r1, #0 */
/* @0xfe50c add r0, pc, r0 */
/* @0xfe510 add sp, sp, #20 */
/* @0xfe514 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfe518 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfe51c eoreq pc, lr, r12, asr #19 */
/* @0xfe520 .word 0x002ef9bc */
/* @0xfe524 .word 0x002396f0 */

/* ── FUNC 0xfe528 · F_DsGridValueY(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0xfe528 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfe52c sub sp, sp, #20 */
/* @0xfe530 mov r1, #0 */
/* @0xfe534 mov r8, r0 */
/* @0xfe538 ldr r4, [sp, #0x30] */
/* @0xfe53c mov r0, r4 */
/* @0xfe540 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe544 mov r1, #1 */
/* @0xfe548 mov r5, r0 */
/* @0xfe54c mov r0, r4 */
/* @0xfe550 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe554 mov r1, #2 */
/* @0xfe558 mov r7, r0 */
/* @0xfe55c mov r0, r4 */
/* @0xfe560 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe564 mov r1, #3 */
/* @0xfe568 mov r6, r0 */
/* @0xfe56c mov r0, r4 */
/* @0xfe570 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe574 mov r1, #4 */
/* @0xfe578 mov r9, r0 */
/* @0xfe57c mov r0, r4 */
/* @0xfe580 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe584 cmp r5, #0 */
/* @0xfe588 mov r2, r0 */
/* @0xfe58c blt 0xfe5e0 <_Z14F_DsGridValueYR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe590 ldr r12, [pc, #0x60] */
/* @0xfe594 ldr r12, [pc, r12] */
/* @0xfe598 ldr r3, [r12] */
/* @0xfe59c cmp r5, r3 */
/* @0xfe5a0 bge 0xfe5e0 <_Z14F_DsGridValueYR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe5a4 ldr r12, [pc, #0x50] */
/* @0xfe5a8 ldr r12, [pc, r12] */
/* @0xfe5ac ldr r3, [r12, #0x4] */
/* @0xfe5b0 ldr r0, [r3, r5, lsl #2] */
/* @0xfe5b4 cmp r0, #0 */
/* @0xfe5b8 beq 0xfe5e0 <_Z14F_DsGridValueYR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe5bc add r4, r4, #80 */
/* @0xfe5c0 str r9, [sp] */
/* @0xfe5c4 stmib sp, {r2, r4} */
/* @0xfe5c8 mov r1, r8 */
/* @0xfe5cc mov r2, r7 */
/* @0xfe5d0 mov r3, r6 */
/* @0xfe5d4 bl 0x2049b4 <_ZN8CDS_Grid7Value_YER6RValueiiiiPS0_> */
/* @0xfe5d8 add sp, sp, #20 */
/* @0xfe5dc pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xfe5e0 ldr r0, [pc, #0x18] */
/* @0xfe5e4 mov r1, #0 */
/* @0xfe5e8 add r0, pc, r0 */
/* @0xfe5ec add sp, sp, #20 */
/* @0xfe5f0 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfe5f4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfe5f8 .word 0x002ef8f0 */
/* @0xfe5fc eoreq pc, lr, r0, ror #17 */
/* @0xfe600 eoreq r9, r3, r4, lsl r6 */

/* ── FUNC 0xfe604 · F_DsGridValueDiskExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0xfe604 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe608 sub sp, sp, #24 */
/* @0xfe60c mov r1, #0 */
/* @0xfe610 mov r9, r0 */
/* @0xfe614 ldr r8, [sp, #0x38] */
/* @0xfe618 mov r0, r8 */
/* @0xfe61c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe620 mov r1, #1 */
/* @0xfe624 mov r10, r0 */
/* @0xfe628 mov r0, r8 */
/* @0xfe62c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe630 mov r4, r0 */
/* @0xfe634 mov r5, r1 */
/* @0xfe638 mov r0, r8 */
/* @0xfe63c mov r1, #2 */
/* @0xfe640 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe644 mov r6, r0 */
/* @0xfe648 mov r7, r1 */
/* @0xfe64c mov r0, r8 */
/* @0xfe650 mov r1, #3 */
/* @0xfe654 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe658 cmp r10, #0 */
/* @0xfe65c mov r2, r0 */
/* @0xfe660 mov r3, r1 */
/* @0xfe664 blt 0xfe6bc <_Z23F_DsGridValueDiskExistsR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe668 ldr r1, [pc, #0x64] */
/* @0xfe66c ldr r1, [pc, r1] */
/* @0xfe670 ldr r1, [r1] */
/* @0xfe674 cmp r10, r1 */
/* @0xfe678 bge 0xfe6bc <_Z23F_DsGridValueDiskExistsR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe67c ldr r1, [pc, #0x54] */
/* @0xfe680 ldr r1, [pc, r1] */
/* @0xfe684 ldr r1, [r1, #0x4] */
/* @0xfe688 ldr r0, [r1, r10, lsl #2] */
/* @0xfe68c cmp r0, #0 */
/* @0xfe690 beq 0xfe6bc <_Z23F_DsGridValueDiskExistsR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe694 strd r2, r3, [sp, #8] */
/* @0xfe698 add r8, r8, #64 */
/* @0xfe69c strd r6, r7, [sp] */
/* @0xfe6a0 mov r1, r9 */
/* @0xfe6a4 str r8, [sp, #0x10] */
/* @0xfe6a8 mov r2, r4 */
/* @0xfe6ac mov r3, r5 */
/* @0xfe6b0 bl 0x204acc <_ZN8CDS_Grid17Value_Disk_ExistsER6RValuedddPS0_> */
/* @0xfe6b4 add sp, sp, #24 */
/* @0xfe6b8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xfe6bc ldr r0, [pc, #0x18] */
/* @0xfe6c0 mov r1, #0 */
/* @0xfe6c4 add r0, pc, r0 */
/* @0xfe6c8 add sp, sp, #24 */
/* @0xfe6cc pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe6d0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfe6d4 eoreq pc, lr, r8, lsl r8 */
/* @0xfe6d8 eoreq pc, lr, r8, lsl #16 */
/* @0xfe6dc eoreq r9, r3, r8, lsr r5 */

/* ── FUNC 0xfe6e0 · F_DsGridValueDiskX(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0xfe6e0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe6e4 sub sp, sp, #24 */
/* @0xfe6e8 mov r1, #0 */
/* @0xfe6ec mov r9, r0 */
/* @0xfe6f0 ldr r8, [sp, #0x38] */
/* @0xfe6f4 mov r0, r8 */
/* @0xfe6f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe6fc mov r1, #1 */
/* @0xfe700 mov r10, r0 */
/* @0xfe704 mov r0, r8 */
/* @0xfe708 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe70c mov r4, r0 */
/* @0xfe710 mov r5, r1 */
/* @0xfe714 mov r0, r8 */
/* @0xfe718 mov r1, #2 */
/* @0xfe71c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe720 mov r6, r0 */
/* @0xfe724 mov r7, r1 */
/* @0xfe728 mov r0, r8 */
/* @0xfe72c mov r1, #3 */
/* @0xfe730 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe734 cmp r10, #0 */
/* @0xfe738 mov r2, r0 */
/* @0xfe73c mov r3, r1 */
/* @0xfe740 blt 0xfe798 <_Z18F_DsGridValueDiskXR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe744 ldr r1, [pc, #0x64] */
/* @0xfe748 ldr r1, [pc, r1] */
/* @0xfe74c ldr r1, [r1] */
/* @0xfe750 cmp r10, r1 */
/* @0xfe754 bge 0xfe798 <_Z18F_DsGridValueDiskXR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe758 ldr r1, [pc, #0x54] */
/* @0xfe75c ldr r1, [pc, r1] */
/* @0xfe760 ldr r1, [r1, #0x4] */
/* @0xfe764 ldr r0, [r1, r10, lsl #2] */
/* @0xfe768 cmp r0, #0 */
/* @0xfe76c beq 0xfe798 <_Z18F_DsGridValueDiskXR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe770 strd r2, r3, [sp, #8] */
/* @0xfe774 add r8, r8, #64 */
/* @0xfe778 strd r6, r7, [sp] */
/* @0xfe77c mov r1, r9 */
/* @0xfe780 str r8, [sp, #0x10] */
/* @0xfe784 mov r2, r4 */
/* @0xfe788 mov r3, r5 */
/* @0xfe78c bl 0x204c54 <_ZN8CDS_Grid12Value_Disk_XER6RValuedddPS0_> */
/* @0xfe790 add sp, sp, #24 */
/* @0xfe794 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xfe798 ldr r0, [pc, #0x18] */
/* @0xfe79c mov r1, #0 */
/* @0xfe7a0 add r0, pc, r0 */
/* @0xfe7a4 add sp, sp, #24 */
/* @0xfe7a8 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe7ac b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfe7b0 eoreq pc, lr, r12, lsr r7 */
/* @0xfe7b4 eoreq pc, lr, r12, lsr #14 */
/* @0xfe7b8 eoreq r9, r3, r12, asr r4 */

/* ── FUNC 0xfe7bc · F_DsGridValueDiskY(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0xfe7bc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe7c0 sub sp, sp, #24 */
/* @0xfe7c4 mov r1, #0 */
/* @0xfe7c8 mov r9, r0 */
/* @0xfe7cc ldr r8, [sp, #0x38] */
/* @0xfe7d0 mov r0, r8 */
/* @0xfe7d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe7d8 mov r1, #1 */
/* @0xfe7dc mov r10, r0 */
/* @0xfe7e0 mov r0, r8 */
/* @0xfe7e4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe7e8 mov r4, r0 */
/* @0xfe7ec mov r5, r1 */
/* @0xfe7f0 mov r0, r8 */
/* @0xfe7f4 mov r1, #2 */
/* @0xfe7f8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe7fc mov r6, r0 */
/* @0xfe800 mov r7, r1 */
/* @0xfe804 mov r0, r8 */
/* @0xfe808 mov r1, #3 */
/* @0xfe80c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfe810 cmp r10, #0 */
/* @0xfe814 mov r2, r0 */
/* @0xfe818 mov r3, r1 */
/* @0xfe81c blt 0xfe874 <_Z18F_DsGridValueDiskYR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe820 ldr r1, [pc, #0x64] */
/* @0xfe824 ldr r1, [pc, r1] */
/* @0xfe828 ldr r1, [r1] */
/* @0xfe82c cmp r10, r1 */
/* @0xfe830 bge 0xfe874 <_Z18F_DsGridValueDiskYR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe834 ldr r1, [pc, #0x54] */
/* @0xfe838 ldr r1, [pc, r1] */
/* @0xfe83c ldr r1, [r1, #0x4] */
/* @0xfe840 ldr r0, [r1, r10, lsl #2] */
/* @0xfe844 cmp r0, #0 */
/* @0xfe848 beq 0xfe874 <_Z18F_DsGridValueDiskYR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xfe84c strd r2, r3, [sp, #8] */
/* @0xfe850 add r8, r8, #64 */
/* @0xfe854 strd r6, r7, [sp] */
/* @0xfe858 mov r1, r9 */
/* @0xfe85c str r8, [sp, #0x10] */
/* @0xfe860 mov r2, r4 */
/* @0xfe864 mov r3, r5 */
/* @0xfe868 bl 0x204de0 <_ZN8CDS_Grid12Value_Disk_YER6RValuedddPS0_> */
/* @0xfe86c add sp, sp, #24 */
/* @0xfe870 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xfe874 ldr r0, [pc, #0x18] */
/* @0xfe878 mov r1, #0 */
/* @0xfe87c add r0, pc, r0 */
/* @0xfe880 add sp, sp, #24 */
/* @0xfe884 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xfe888 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfe88c eoreq pc, lr, r0, ror #12 */
/* @0xfe890 eoreq pc, lr, r0, asr r6 */
/* @0xfe894 eoreq r9, r3, r0, lsl #7 */

/* ── FUNC 0xfe898 · F_DsGridShuffle(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0xfe898 push {r3, lr} */
/* @0xfe89c mov r1, #0 */
/* @0xfe8a0 ldr r0, [sp, #0x8] */
/* @0xfe8a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe8a8 cmp r0, #0 */
/* @0xfe8ac blt 0xfe8e4 <_Z15F_DsGridShuffleR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfe8b0 ldr r3, [pc, #0x40] */
/* @0xfe8b4 ldr r3, [pc, r3] */
/* @0xfe8b8 ldr r3, [r3] */
/* @0xfe8bc cmp r0, r3 */
/* @0xfe8c0 bge 0xfe8e4 <_Z15F_DsGridShuffleR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfe8c4 ldr r3, [pc, #0x30] */
/* @0xfe8c8 ldr r3, [pc, r3] */
/* @0xfe8cc ldr r3, [r3, #0x4] */
/* @0xfe8d0 ldr r0, [r3, r0, lsl #2] */
/* @0xfe8d4 cmp r0, #0 */
/* @0xfe8d8 beq 0xfe8e4 <_Z15F_DsGridShuffleR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfe8dc pop {r3, lr} */
/* @0xfe8e0 b 0x20cd98 <_ZN8CDS_Grid7ShuffleEv> */
/* @0xfe8e4 ldr r0, [pc, #0x14] */
/* @0xfe8e8 mov r1, #0 */
/* @0xfe8ec pop {r3, lr} */
/* @0xfe8f0 add r0, pc, r0 */
/* @0xfe8f4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfe8f8 .word 0x002ef5d0 */
/* @0xfe8fc eoreq pc, lr, r0, asr #11 */
/* @0xfe900 eoreq r9, r3, r12, lsl #6 */

/* ── FUNC 0xfe904 · F_DsGridWrite(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0xfe904 push {r4, lr} */
/* @0xfe908 sub sp, sp, #8 */
/* @0xfe90c mov r4, r0 */
/* @0xfe910 mov r1, #0 */
/* @0xfe914 ldr r0, [sp, #0x10] */
/* @0xfe918 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe91c subs r2, r0, #0 */
/* @0xfe920 blt 0xfe980 <_Z13F_DsGridWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfe924 ldr r3, [pc, #0x6c] */
/* @0xfe928 ldr r3, [pc, r3] */
/* @0xfe92c ldr r3, [r3] */
/* @0xfe930 cmp r2, r3 */
/* @0xfe934 bge 0xfe980 <_Z13F_DsGridWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfe938 ldr r3, [pc, #0x5c] */
/* @0xfe93c ldr r3, [pc, r3] */
/* @0xfe940 ldr r3, [r3, #0x4] */
/* @0xfe944 ldr r1, [r3, r2, lsl #2] */
/* @0xfe948 cmp r1, #0 */
/* @0xfe94c beq 0xfe980 <_Z13F_DsGridWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfe950 add r1, sp, #8 */
/* @0xfe954 mov r0, #0 */
/* @0xfe958 str r0, [r1, #-0x4]! */
/* @0xfe95c ldr r0, [r3, r2, lsl #2] */
/* @0xfe960 bl 0x204108 <_ZN8CDS_Grid13WriteToStringERPKc> */
/* @0xfe964 mov r0, r4 */
/* @0xfe968 ldr r1, [sp, #0x4] */
/* @0xfe96c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xfe970 ldr r0, [sp, #0x4] */
/* @0xfe974 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xfe978 add sp, sp, #8 */
/* @0xfe97c pop {r4, pc} */
/* @0xfe980 ldr r0, [pc, #0x18] */
/* @0xfe984 mov r1, #0 */
/* @0xfe988 add r0, pc, r0 */
/* @0xfe98c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfe990 add sp, sp, #8 */
/* @0xfe994 pop {r4, pc} */
/* @0xfe998 eoreq pc, lr, r12, asr r5 */
/* @0xfe99c eoreq pc, lr, r12, asr #10 */
/* @0xfe9a0 eoreq r9, r3, r4, ror r2 */

/* ── FUNC 0xfe9a4 · F_DsGridRead(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0xfe9a4 push {r3, r4, r5, r6, r7, lr} */
/* @0xfe9a8 mov r1, #0 */
/* @0xfe9ac ldr r5, [sp, #0x18] */
/* @0xfe9b0 mov r6, r3 */
/* @0xfe9b4 mov r0, r5 */
/* @0xfe9b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfe9bc mov r1, #1 */
/* @0xfe9c0 mov r4, r0 */
/* @0xfe9c4 mov r0, r5 */
/* @0xfe9c8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xfe9cc cmp r6, #3 */
/* @0xfe9d0 movne r2, #0 */
/* @0xfe9d4 mov r7, r0 */
/* @0xfe9d8 beq 0xfea30 <_Z12F_DsGridReadR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0xfe9dc cmp r4, #0 */
/* @0xfe9e0 blt 0xfea1c <_Z12F_DsGridReadR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfe9e4 ldr r3, [pc, #0x60] */
/* @0xfe9e8 ldr r3, [pc, r3] */
/* @0xfe9ec ldr r3, [r3] */
/* @0xfe9f0 cmp r4, r3 */
/* @0xfe9f4 bge 0xfea1c <_Z12F_DsGridReadR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfe9f8 ldr r3, [pc, #0x50] */
/* @0xfe9fc ldr r3, [pc, r3] */
/* @0xfea00 ldr r3, [r3, #0x4] */
/* @0xfea04 ldr r0, [r3, r4, lsl #2] */
/* @0xfea08 cmp r0, #0 */
/* @0xfea0c beq 0xfea1c <_Z12F_DsGridReadR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfea10 mov r1, r7 */
/* @0xfea14 pop {r3, r4, r5, r6, r7, lr} */
/* @0xfea18 b 0x20b138 <_ZN8CDS_Grid14ReadFromStringEPKcb> */
/* @0xfea1c ldr r0, [pc, #0x30] */
/* @0xfea20 mov r1, #0 */
/* @0xfea24 pop {r3, r4, r5, r6, r7, lr} */
/* @0xfea28 add r0, pc, r0 */
/* @0xfea2c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfea30 mov r0, r5 */
/* @0xfea34 mov r1, #2 */
/* @0xfea38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfea3c cmp r0, #0 */
/* @0xfea40 movle r2, #0 */
/* @0xfea44 movgt r2, #1 */
/* @0xfea48 b 0xfe9dc <_Z12F_DsGridReadR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0xfea4c mlaeq lr, r12, r4, pc */
/* @0xfea50 eoreq pc, lr, r12, lsl #9 */
/* @0xfea54 .word 0x002391d4 */

/* ── FUNC 0xfea58 · F_DsGridSort(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0xfea58 push {r4, r5, r6, lr} */
/* @0xfea5c mov r1, #0 */
/* @0xfea60 ldr r4, [sp, #0x10] */
/* @0xfea64 mov r0, r4 */
/* @0xfea68 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfea6c mov r1, #1 */
/* @0xfea70 mov r5, r0 */
/* @0xfea74 mov r0, r4 */
/* @0xfea78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfea7c mov r1, #2 */
/* @0xfea80 mov r6, r0 */
/* @0xfea84 mov r0, r4 */
/* @0xfea88 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0xfea8c cmp r0, #0 */
/* @0xfea90 mvneq r2, #0 */
/* @0xfea94 movne r2, #1 */
/* @0xfea98 cmp r5, #0 */
/* @0xfea9c blt 0xfead8 <_Z12F_DsGridSortR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfeaa0 ldr r3, [pc, #0x44] */
/* @0xfeaa4 ldr r3, [pc, r3] */
/* @0xfeaa8 ldr r3, [r3] */
/* @0xfeaac cmp r5, r3 */
/* @0xfeab0 bge 0xfead8 <_Z12F_DsGridSortR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfeab4 ldr r3, [pc, #0x34] */
/* @0xfeab8 ldr r3, [pc, r3] */
/* @0xfeabc ldr r3, [r3, #0x4] */
/* @0xfeac0 ldr r0, [r3, r5, lsl #2] */
/* @0xfeac4 cmp r0, #0 */
/* @0xfeac8 beq 0xfead8 <_Z12F_DsGridSortR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfeacc mov r1, r6 */
/* @0xfead0 pop {r4, r5, r6, lr} */
/* @0xfead4 b 0x204f6c <_ZN8CDS_Grid4SortEii> */
/* @0xfead8 ldr r0, [pc, #0x14] */
/* @0xfeadc mov r1, #0 */
/* @0xfeae0 pop {r4, r5, r6, lr} */
/* @0xfeae4 add r0, pc, r0 */
/* @0xfeae8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfeaec eoreq pc, lr, r0, ror #7 */
/* @0xfeaf0 .word 0x002ef3d0 */
/* @0xfeaf4 eoreq r9, r3, r8, lsl r1 */

/* ── FUNC 0xfeaf8 · F_DsGridWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0xfeaf8 push {r4, lr} */
/* @0xfeafc mov r1, #0 */
/* @0xfeb00 mov r4, r0 */
/* @0xfeb04 ldr r0, [sp, #0x8] */
/* @0xfeb08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfeb0c mov r3, #0 */
/* @0xfeb10 str r3, [r4, #0xc] */
/* @0xfeb14 str r3, [r4] */
/* @0xfeb18 str r3, [r4, #0x4] */
/* @0xfeb1c cmp r0, #0 */
/* @0xfeb20 blt 0xfeb68 <_Z13F_DsGridWidthR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfeb24 ldr r3, [pc, #0x50] */
/* @0xfeb28 ldr r3, [pc, r3] */
/* @0xfeb2c ldr r3, [r3] */
/* @0xfeb30 cmp r0, r3 */
/* @0xfeb34 bge 0xfeb68 <_Z13F_DsGridWidthR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfeb38 ldr r3, [pc, #0x40] */
/* @0xfeb3c ldr r3, [pc, r3] */
/* @0xfeb40 ldr r3, [r3, #0x4] */
/* @0xfeb44 ldr r3, [r3, r0, lsl #2] */
/* @0xfeb48 cmp r3, #0 */
/* @0xfeb4c beq 0xfeb68 <_Z13F_DsGridWidthR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfeb50 ldr r2, [r3, #0x4] */
/* @0xfeb54 vmov s15, r2 */
/* @0xfeb58 vcvt.f64.s32 d7, s15 */
/* @0xfeb5c vmov r2, r3, d7 */
/* @0xfeb60 stm r4, {r2, r3} */
/* @0xfeb64 pop {r4, pc} */
/* @0xfeb68 ldr r0, [pc, #0x14] */
/* @0xfeb6c mov r1, #0 */
/* @0xfeb70 pop {r4, lr} */
/* @0xfeb74 add r0, pc, r0 */
/* @0xfeb78 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfeb7c eoreq pc, lr, r12, asr r3 */
/* @0xfeb80 eoreq pc, lr, r12, asr #6 */
/* @0xfeb84 eoreq r9, r3, r8, lsl #1 */

/* ── FUNC 0xfeb88 · F_DsGridHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0xfeb88 push {r4, lr} */
/* @0xfeb8c mov r1, #0 */
/* @0xfeb90 mov r4, r0 */
/* @0xfeb94 ldr r0, [sp, #0x8] */
/* @0xfeb98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfeb9c mov r3, #0 */
/* @0xfeba0 str r3, [r4, #0xc] */
/* @0xfeba4 str r3, [r4] */
/* @0xfeba8 str r3, [r4, #0x4] */
/* @0xfebac cmp r0, #0 */
/* @0xfebb0 blt 0xfebf8 <_Z14F_DsGridHeightR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfebb4 ldr r3, [pc, #0x50] */
/* @0xfebb8 ldr r3, [pc, r3] */
/* @0xfebbc ldr r3, [r3] */
/* @0xfebc0 cmp r0, r3 */
/* @0xfebc4 bge 0xfebf8 <_Z14F_DsGridHeightR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfebc8 ldr r3, [pc, #0x40] */
/* @0xfebcc ldr r3, [pc, r3] */
/* @0xfebd0 ldr r3, [r3, #0x4] */
/* @0xfebd4 ldr r3, [r3, r0, lsl #2] */
/* @0xfebd8 cmp r3, #0 */
/* @0xfebdc beq 0xfebf8 <_Z14F_DsGridHeightR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfebe0 ldr r2, [r3, #0x8] */
/* @0xfebe4 vmov s15, r2 */
/* @0xfebe8 vcvt.f64.s32 d7, s15 */
/* @0xfebec vmov r2, r3, d7 */
/* @0xfebf0 stm r4, {r2, r3} */
/* @0xfebf4 pop {r4, pc} */
/* @0xfebf8 ldr r0, [pc, #0x14] */
/* @0xfebfc mov r1, #0 */
/* @0xfec00 pop {r4, lr} */
/* @0xfec04 add r0, pc, r0 */
/* @0xfec08 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfec0c eoreq pc, lr, r12, asr #5 */
/* @0xfec10 .word 0x002ef2bc */
/* @0xfec14 .word 0x00238ff8 */

/* ── FUNC 0xfec18 · DS_AutoMutex::DS_AutoMutex() · size=84 · insn=21 */
/* @0xfec18 push {r3, r4, r5, lr} */
/* @0xfec1c mov r5, r0 */
/* @0xfec20 ldr r4, [pc, #0x3c] */
/* @0xfec24 ldr r4, [pc, r4] */
/* @0xfec28 ldr r3, [r4] */
/* @0xfec2c cmp r3, #0 */
/* @0xfec30 movne r0, r3 */
/* @0xfec34 beq 0xfec44 <_ZN12DS_AutoMutexC2Ev+0x2c> */
/* @0xfec38 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0xfec3c mov r0, r5 */
/* @0xfec40 pop {r3, r4, r5, pc} */
/* @0xfec44 mov r0, #8 */
/* @0xfec48 bl 0xb6544 <malloc@plt> */
/* @0xfec4c ldr r1, [pc, #0x14] */
/* @0xfec50 add r1, pc, r1 */
/* @0xfec54 str r0, [r4] */
/* @0xfec58 bl 0x27e038 <_ZN5Mutex4InitEPKc> */
/* @0xfec5c ldr r0, [r4] */
/* @0xfec60 b 0xfec38 <_ZN12DS_AutoMutexC2Ev+0x20> */
/* @0xfec64 eoreq pc, lr, r8, ror #4 */
/* @0xfec68 eoreq r9, r3, r0, lsl r0 */

/* ── FUNC 0xfec18 · DS_AutoMutex::DS_AutoMutex() · alias of the symbol above · insn=0 */

/* ── FUNC 0xfec6c · DS_AutoMutex::~DS_AutoMutex() · size=36 · insn=9 */
/* @0xfec6c ldr r3, [pc, #0x18] */
/* @0xfec70 push {r4, lr} */
/* @0xfec74 ldr r3, [pc, r3] */
/* @0xfec78 mov r4, r0 */
/* @0xfec7c ldr r0, [r3] */
/* @0xfec80 bl 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0xfec84 mov r0, r4 */
/* @0xfec88 pop {r4, pc} */
/* @0xfec8c eoreq pc, lr, r8, lsl r2 */

/* ── FUNC 0xfec6c · DS_AutoMutex::~DS_AutoMutex() · alias of the symbol above · insn=0 */

/* ── FUNC 0xfec90 · F_DsMapDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0xfec90 push {r4, r5, r6, r7, lr} */
/* @0xfec94 sub sp, sp, #12 */
/* @0xfec98 add r4, sp, #4 */
/* @0xfec9c ldr r5, [sp, #0x20] */
/* @0xfeca0 mov r0, r4 */
/* @0xfeca4 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xfeca8 mov r1, #0 */
/* @0xfecac mov r0, r5 */
/* @0xfecb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfecb4 subs r5, r0, #0 */
/* @0xfecb8 blt 0xfed14 <_Z14F_DsMapDestroyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfecbc ldr r3, [pc, #0x70] */
/* @0xfecc0 ldr r3, [pc, r3] */
/* @0xfecc4 ldr r3, [r3] */
/* @0xfecc8 cmp r5, r3 */
/* @0xfeccc bge 0xfed14 <_Z14F_DsMapDestroyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfecd0 ldr r6, [pc, #0x60] */
/* @0xfecd4 ldr r6, [pc, r6] */
/* @0xfecd8 ldr r3, [r6, #0x4] */
/* @0xfecdc ldr r7, [r3, r5, lsl #2] */
/* @0xfece0 cmp r7, #0 */
/* @0xfece4 beq 0xfed04 <_Z14F_DsMapDestroyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfece8 mov r0, r7 */
/* @0xfecec bl 0x20d9e8 <_ZN7CDS_MapD2Ev> */
/* @0xfecf0 mov r0, r7 */
/* @0xfecf4 bl 0x27d1d0 <_ZdlPv> */
/* @0xfecf8 ldr r3, [r6, #0x4] */
/* @0xfecfc mov r2, #0 */
/* @0xfed00 str r2, [r3, r5, lsl #2] */
/* @0xfed04 mov r0, r4 */
/* @0xfed08 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xfed0c add sp, sp, #12 */
/* @0xfed10 pop {r4, r5, r6, r7, pc} */
/* @0xfed14 ldr r0, [pc, #0x20] */
/* @0xfed18 mov r1, #0 */
/* @0xfed1c add r0, pc, r0 */
/* @0xfed20 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfed24 mov r0, r4 */
/* @0xfed28 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xfed2c add sp, sp, #12 */
/* @0xfed30 pop {r4, r5, r6, r7, pc} */
/* @0xfed34 .word 0x002eefb8 */
/* @0xfed38 eoreq lr, lr, r8, ror #24 */
/* @0xfed3c eoreq r8, r3, r0, ror #29 */

/* ── FUNC 0xfed40 · F_DsMapClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0xfed40 push {r4, r5, lr} */
/* @0xfed44 sub sp, sp, #12 */
/* @0xfed48 add r4, sp, #4 */
/* @0xfed4c ldr r5, [sp, #0x18] */
/* @0xfed50 mov r0, r4 */
/* @0xfed54 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xfed58 mov r1, #0 */
/* @0xfed5c mov r0, r5 */
/* @0xfed60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfed64 cmp r0, #0 */
/* @0xfed68 blt 0xfedac <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0xfed6c ldr r3, [pc, #0x58] */
/* @0xfed70 ldr r3, [pc, r3] */
/* @0xfed74 ldr r3, [r3] */
/* @0xfed78 cmp r0, r3 */
/* @0xfed7c bge 0xfedac <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0xfed80 ldr r3, [pc, #0x48] */
/* @0xfed84 ldr r3, [pc, r3] */
/* @0xfed88 ldr r3, [r3, #0x4] */
/* @0xfed8c ldr r0, [r3, r0, lsl #2] */
/* @0xfed90 cmp r0, #0 */
/* @0xfed94 beq 0xfedac <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0xfed98 bl 0x20daf8 <_ZN7CDS_Map5ClearEv> */
/* @0xfed9c mov r0, r4 */
/* @0xfeda0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xfeda4 add sp, sp, #12 */
/* @0xfeda8 pop {r4, r5, pc} */
/* @0xfedac ldr r0, [pc, #0x20] */
/* @0xfedb0 mov r1, #0 */
/* @0xfedb4 add r0, pc, r0 */
/* @0xfedb8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfedbc mov r0, r4 */
/* @0xfedc0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xfedc4 add sp, sp, #12 */
/* @0xfedc8 pop {r4, r5, pc} */
/* @0xfedcc eoreq lr, lr, r8, lsl #30 */
/* @0xfedd0 .word 0x002eebb8 */
/* @0xfedd4 eoreq r8, r3, r8, asr #28 */

/* ── FUNC 0xfedd8 · F_DsMapCopy(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0xfedd8 push {r4, r5, r6, r7, r8, lr} */
/* @0xfeddc sub sp, sp, #8 */
/* @0xfede0 add r5, sp, #4 */
/* @0xfede4 ldr r7, [sp, #0x20] */
/* @0xfede8 mov r0, r5 */
/* @0xfedec bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xfedf0 mov r1, #0 */
/* @0xfedf4 mov r0, r7 */
/* @0xfedf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfedfc subs r6, r0, #0 */
/* @0xfee00 blt 0xfee50 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfee04 ldr r4, [pc, #0x88] */
/* @0xfee08 ldr r4, [pc, r4] */
/* @0xfee0c ldr r3, [r4] */
/* @0xfee10 cmp r6, r3 */
/* @0xfee14 bge 0xfee50 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfee18 ldr r8, [pc, #0x78] */
/* @0xfee1c ldr r8, [pc, r8] */
/* @0xfee20 ldr r3, [r8, #0x4] */
/* @0xfee24 ldr r3, [r3, r6, lsl #2] */
/* @0xfee28 cmp r3, #0 */
/* @0xfee2c beq 0xfee50 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfee30 mov r0, r7 */
/* @0xfee34 mov r1, #1 */
/* @0xfee38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfee3c cmp r0, #0 */
/* @0xfee40 blt 0xfee50 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfee44 ldr r3, [r4] */
/* @0xfee48 cmp r0, r3 */
/* @0xfee4c blt 0xfee70 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xfee50 ldr r0, [pc, #0x44] */
/* @0xfee54 mov r1, #0 */
/* @0xfee58 add r0, pc, r0 */
/* @0xfee5c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfee60 mov r0, r5 */
/* @0xfee64 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xfee68 add sp, sp, #8 */
/* @0xfee6c pop {r4, r5, r6, r7, r8, pc} */
/* @0xfee70 ldr r3, [r8, #0x4] */
/* @0xfee74 ldr r1, [r3, r0, lsl #2] */
/* @0xfee78 cmp r1, #0 */
/* @0xfee7c beq 0xfee50 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfee80 ldr r0, [r3, r6, lsl #2] */
/* @0xfee84 bl 0x20c87c <_ZN7CDS_Map6AssignEPS_> */
/* @0xfee88 mov r0, r5 */
/* @0xfee8c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xfee90 b 0xfee68 <_Z11F_DsMapCopyR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0xfee94 eoreq lr, lr, r0, ror lr */
/* @0xfee98 eoreq lr, lr, r0, lsr #22 */
/* @0xfee9c eoreq r8, r3, r4, lsr #27 */

/* ── FUNC 0xfeea0 · F_DsMapSize(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0xfeea0 push {r4, r5, r6, lr} */
/* @0xfeea4 sub sp, sp, #8 */
/* @0xfeea8 add r4, sp, #4 */
/* @0xfeeac mov r5, r0 */
/* @0xfeeb0 ldr r6, [sp, #0x18] */
/* @0xfeeb4 mov r0, r4 */
/* @0xfeeb8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xfeebc mov r1, #0 */
/* @0xfeec0 mov r0, r6 */
/* @0xfeec4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfeec8 cmp r0, #0 */
/* @0xfeecc blt 0xfef28 <_Z11F_DsMapSizeR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xfeed0 ldr r3, [pc, #0x70] */
/* @0xfeed4 ldr r3, [pc, r3] */
/* @0xfeed8 ldr r3, [r3] */
/* @0xfeedc cmp r0, r3 */
/* @0xfeee0 bge 0xfef28 <_Z11F_DsMapSizeR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xfeee4 ldr r3, [pc, #0x60] */
/* @0xfeee8 ldr r3, [pc, r3] */
/* @0xfeeec ldr r3, [r3, #0x4] */
/* @0xfeef0 ldr r0, [r3, r0, lsl #2] */
/* @0xfeef4 cmp r0, #0 */
/* @0xfeef8 beq 0xfef28 <_Z11F_DsMapSizeR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xfeefc mov r3, #0 */
/* @0xfef00 str r3, [r5, #0xc] */
/* @0xfef04 bl 0x2052c0 <_ZN7CDS_Map4SizeEv> */
/* @0xfef08 vmov s15, r0 */
/* @0xfef0c mov r0, r4 */
/* @0xfef10 vcvt.f64.s32 d7, s15 */
/* @0xfef14 vmov r2, r3, d7 */
/* @0xfef18 stm r5, {r2, r3} */
/* @0xfef1c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xfef20 add sp, sp, #8 */
/* @0xfef24 pop {r4, r5, r6, pc} */
/* @0xfef28 ldr r0, [pc, #0x20] */
/* @0xfef2c mov r1, #0 */
/* @0xfef30 add r0, pc, r0 */
/* @0xfef34 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfef38 mov r0, r4 */
/* @0xfef3c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xfef40 add sp, sp, #8 */
/* @0xfef44 pop {r4, r5, r6, pc} */
/* @0xfef48 eoreq lr, lr, r4, lsr #27 */
/* @0xfef4c eoreq lr, lr, r4, asr r10 */
/* @0xfef50 eoreq r8, r3, r12, asr #25 */

/* ── FUNC 0xfef54 · F_DsMapEmpty(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0xfef54 push {r4, r5, r6, lr} */
/* @0xfef58 sub sp, sp, #8 */
/* @0xfef5c add r4, sp, #4 */
/* @0xfef60 mov r5, r0 */
/* @0xfef64 ldr r6, [sp, #0x18] */
/* @0xfef68 mov r0, r4 */
/* @0xfef6c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xfef70 mov r1, #0 */
/* @0xfef74 mov r0, r6 */
/* @0xfef78 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfef7c cmp r0, #0 */
/* @0xfef80 blt 0xfefe8 <_Z12F_DsMapEmptyR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0xfef84 ldr r3, [pc, #0x7c] */
/* @0xfef88 ldr r3, [pc, r3] */
/* @0xfef8c ldr r3, [r3] */
/* @0xfef90 cmp r0, r3 */
/* @0xfef94 bge 0xfefe8 <_Z12F_DsMapEmptyR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0xfef98 ldr r3, [pc, #0x6c] */
/* @0xfef9c ldr r3, [pc, r3] */
/* @0xfefa0 ldr r3, [r3, #0x4] */
/* @0xfefa4 ldr r0, [r3, r0, lsl #2] */
/* @0xfefa8 cmp r0, #0 */
/* @0xfefac beq 0xfefe8 <_Z12F_DsMapEmptyR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0xfefb0 mov r6, #0 */
/* @0xfefb4 str r6, [r5, #0xc] */
/* @0xfefb8 bl 0x203a58 <_ZN7CDS_Map5EmptyEv> */
/* @0xfefbc cmp r0, #0 */
/* @0xfefc0 moveq r6, r0 */
/* @0xfefc4 movne r3, r6 */
/* @0xfefc8 moveq r3, r6 */
/* @0xfefcc movtne r3, #0x3ff0 */
/* @0xfefd0 str r6, [r5] */
/* @0xfefd4 mov r0, r4 */
/* @0xfefd8 str r3, [r5, #0x4] */
/* @0xfefdc bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xfefe0 add sp, sp, #8 */
/* @0xfefe4 pop {r4, r5, r6, pc} */
/* @0xfefe8 ldr r0, [pc, #0x20] */
/* @0xfefec mov r1, #0 */
/* @0xfeff0 add r0, pc, r0 */
/* @0xfeff4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfeff8 mov r0, r4 */
/* @0xfeffc bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff000 add sp, sp, #8 */
/* @0xff004 pop {r4, r5, r6, pc} */
/* @0xff008 .word 0x002eecf0 */
/* @0xff00c eoreq lr, lr, r0, lsr #19 */
/* @0xff010 eoreq r8, r3, r12, lsl #24 */

/* ── FUNC 0xff014 · F_DsMapAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0xff014 push {r4, r5, r6, r7, lr} */
/* @0xff018 sub sp, sp, #12 */
/* @0xff01c add r6, sp, #4 */
/* @0xff020 mov r5, r0 */
/* @0xff024 ldr r7, [sp, #0x20] */
/* @0xff028 mov r4, #0 */
/* @0xff02c mov r0, r6 */
/* @0xff030 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xff034 str r4, [r5, #0xc] */
/* @0xff038 str r4, [r5] */
/* @0xff03c mov r0, r7 */
/* @0xff040 str r4, [r5, #0x4] */
/* @0xff044 mov r1, r4 */
/* @0xff048 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff04c cmp r0, #0 */
/* @0xff050 blt 0xff0b0 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0xff054 ldr r3, [pc, #0x74] */
/* @0xff058 ldr r3, [pc, r3] */
/* @0xff05c ldr r3, [r3] */
/* @0xff060 cmp r0, r3 */
/* @0xff064 bge 0xff0b0 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0xff068 ldr r3, [pc, #0x64] */
/* @0xff06c ldr r3, [pc, r3] */
/* @0xff070 ldr r3, [r3, #0x4] */
/* @0xff074 ldr r0, [r3, r0, lsl #2] */
/* @0xff078 cmp r0, r4 */
/* @0xff07c beq 0xff0b0 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0xff080 add r1, r7, #16 */
/* @0xff084 add r2, r7, #32 */
/* @0xff088 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0xff08c cmp r0, #0 */
/* @0xff090 mov r0, r6 */
/* @0xff094 strne r4, [r5] */
/* @0xff098 movne r3, #0 */
/* @0xff09c movtne r3, #0x3ff0 */
/* @0xff0a0 strne r3, [r5, #0x4] */
/* @0xff0a4 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff0a8 add sp, sp, #12 */
/* @0xff0ac pop {r4, r5, r6, r7, pc} */
/* @0xff0b0 ldr r0, [pc, #0x20] */
/* @0xff0b4 mov r1, #0 */
/* @0xff0b8 add r0, pc, r0 */
/* @0xff0bc bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff0c0 mov r0, r6 */
/* @0xff0c4 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff0c8 add sp, sp, #12 */
/* @0xff0cc pop {r4, r5, r6, r7, pc} */
/* @0xff0d0 eoreq lr, lr, r0, lsr #24 */
/* @0xff0d4 .word 0x002ee8d0 */
/* @0xff0d8 eoreq r8, r3, r4, asr #22 */

/* ── FUNC 0xff0dc · F_DsMapSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0xff0dc push {r4, r5, lr} */
/* @0xff0e0 sub sp, sp, #12 */
/* @0xff0e4 add r4, sp, #4 */
/* @0xff0e8 ldr r5, [sp, #0x18] */
/* @0xff0ec mov r0, r4 */
/* @0xff0f0 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xff0f4 mov r1, #0 */
/* @0xff0f8 mov r0, r5 */
/* @0xff0fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff100 cmp r0, #0 */
/* @0xff104 blt 0xff154 <_Z10F_DsMapSetR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xff108 ldr r3, [pc, #0x64] */
/* @0xff10c ldr r3, [pc, r3] */
/* @0xff110 ldr r3, [r3] */
/* @0xff114 cmp r0, r3 */
/* @0xff118 bge 0xff154 <_Z10F_DsMapSetR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xff11c ldr r3, [pc, #0x54] */
/* @0xff120 ldr r3, [pc, r3] */
/* @0xff124 ldr r3, [r3, #0x4] */
/* @0xff128 ldr r0, [r3, r0, lsl #2] */
/* @0xff12c cmp r0, #0 */
/* @0xff130 beq 0xff154 <_Z10F_DsMapSetR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xff134 add r1, r5, #16 */
/* @0xff138 add r2, r5, #32 */
/* @0xff13c mov r3, #0 */
/* @0xff140 bl 0x208c3c <_ZN7CDS_Map3SetEP6RValueS1_S1_> */
/* @0xff144 mov r0, r4 */
/* @0xff148 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff14c add sp, sp, #12 */
/* @0xff150 pop {r4, r5, pc} */
/* @0xff154 ldr r0, [pc, #0x20] */
/* @0xff158 mov r1, #0 */
/* @0xff15c add r0, pc, r0 */
/* @0xff160 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff164 mov r0, r4 */
/* @0xff168 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff16c add sp, sp, #12 */
/* @0xff170 pop {r4, r5, pc} */
/* @0xff174 eoreq lr, lr, r12, ror #22 */
/* @0xff178 eoreq lr, lr, r12, lsl r8 */
/* @0xff17c eoreq r8, r3, r0, lsr #21 */

/* ── FUNC 0xff180 · F_DsMapSetPost(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0xff180 push {r4, r5, r6, lr} */
/* @0xff184 sub sp, sp, #8 */
/* @0xff188 add r4, sp, #4 */
/* @0xff18c mov r6, r0 */
/* @0xff190 ldr r5, [sp, #0x18] */
/* @0xff194 mov r0, r4 */
/* @0xff198 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xff19c mov r1, #0 */
/* @0xff1a0 mov r0, r5 */
/* @0xff1a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff1a8 cmp r0, #0 */
/* @0xff1ac blt 0xff1fc <_Z14F_DsMapSetPostR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xff1b0 ldr r1, [pc, #0x64] */
/* @0xff1b4 ldr r1, [pc, r1] */
/* @0xff1b8 ldr r1, [r1] */
/* @0xff1bc cmp r0, r1 */
/* @0xff1c0 bge 0xff1fc <_Z14F_DsMapSetPostR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xff1c4 ldr r1, [pc, #0x54] */
/* @0xff1c8 ldr r1, [pc, r1] */
/* @0xff1cc ldr r3, [r1, #0x4] */
/* @0xff1d0 ldr r0, [r3, r0, lsl #2] */
/* @0xff1d4 cmp r0, #0 */
/* @0xff1d8 beq 0xff1fc <_Z14F_DsMapSetPostR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xff1dc mov r3, r6 */
/* @0xff1e0 add r1, r5, #16 */
/* @0xff1e4 add r2, r5, #32 */
/* @0xff1e8 bl 0x208c3c <_ZN7CDS_Map3SetEP6RValueS1_S1_> */
/* @0xff1ec mov r0, r4 */
/* @0xff1f0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff1f4 add sp, sp, #8 */
/* @0xff1f8 pop {r4, r5, r6, pc} */
/* @0xff1fc ldr r0, [pc, #0x20] */
/* @0xff200 mov r1, #0 */
/* @0xff204 add r0, pc, r0 */
/* @0xff208 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff20c mov r0, r4 */
/* @0xff210 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff214 add sp, sp, #8 */
/* @0xff218 pop {r4, r5, r6, pc} */
/* @0xff21c eoreq lr, lr, r4, asr #21 */
/* @0xff220 eoreq lr, lr, r4, ror r7 */
/* @0xff224 .word 0x002389f8 */

/* ── FUNC 0xff228 · F_DsMapAddList(RValue&, CInstance*, CInstance*, int, RValue*) · size=336 · insn=84 */
/* @0xff228 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xff22c sub sp, sp, #8 */
/* @0xff230 add r9, sp, #4 */
/* @0xff234 mov r6, r0 */
/* @0xff238 ldr r8, [sp, #0x28] */
/* @0xff23c mov r0, r9 */
/* @0xff240 ldr r7, [pc, #0x114] */
/* @0xff244 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xff248 mov r3, #0 */
/* @0xff24c mov r1, r3 */
/* @0xff250 str r3, [r6, #0xc] */
/* @0xff254 str r3, [r6] */
/* @0xff258 mov r0, r8 */
/* @0xff25c str r3, [r6, #0x4] */
/* @0xff260 add r7, pc, r7 */
/* @0xff264 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff268 cmp r0, #0 */
/* @0xff26c blt 0xff31c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0xff270 ldr r3, [pc, #0xe8] */
/* @0xff274 ldr r3, [r7, r3] */
/* @0xff278 ldr r3, [r3] */
/* @0xff27c cmp r0, r3 */
/* @0xff280 bge 0xff31c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0xff284 ldr r3, [pc, #0xd8] */
/* @0xff288 ldr r3, [r7, r3] */
/* @0xff28c ldr r3, [r3, #0x4] */
/* @0xff290 ldr r0, [r3, r0, lsl #2] */
/* @0xff294 cmp r0, #0 */
/* @0xff298 beq 0xff31c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0xff29c ldr r10, [r8, #0x2c] */
/* @0xff2a0 ldr r4, [r8, #0x20] */
/* @0xff2a4 cmp r10, #0 */
/* @0xff2a8 ldr r5, [r8, #0x24] */
/* @0xff2ac bne 0xff33c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0xff2b0 vmov d7, r4, r5 */
/* @0xff2b4 vcvt.s32.f64 s15, d7 */
/* @0xff2b8 vmov r4, s15 */
/* @0xff2bc cmp r4, #0 */
/* @0xff2c0 blt 0xff33c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0xff2c4 ldr r3, [pc, #0x9c] */
/* @0xff2c8 ldr r3, [r7, r3] */
/* @0xff2cc ldr r3, [r3] */
/* @0xff2d0 cmp r4, r3 */
/* @0xff2d4 bge 0xff33c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0xff2d8 ldr r3, [pc, #0x8c] */
/* @0xff2dc ldr r3, [r7, r3] */
/* @0xff2e0 ldr r3, [r3, #0x4] */
/* @0xff2e4 ldr r3, [r3, r4, lsl #2] */
/* @0xff2e8 cmp r3, #0 */
/* @0xff2ec beq 0xff33c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0xff2f0 mov r3, #1073741824 */
/* @0xff2f4 add r1, r8, #16 */
/* @0xff2f8 str r3, [r8, #0x2c] */
/* @0xff2fc add r2, r8, #32 */
/* @0xff300 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0xff304 cmp r0, #0 */
/* @0xff308 movne r3, #0 */
/* @0xff30c strne r10, [r6] */
/* @0xff310 movtne r3, #0x3ff0 */
/* @0xff314 strne r3, [r6, #0x4] */
/* @0xff318 b 0xff32c <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xff31c ldr r0, [pc, #0x4c] */
/* @0xff320 mov r1, #0 */
/* @0xff324 add r0, pc, r0 */
/* @0xff328 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff32c mov r0, r9 */
/* @0xff330 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff334 add sp, sp, #8 */
/* @0xff338 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xff33c ldr r0, [pc, #0x30] */
/* @0xff340 mov r1, #0 */
/* @0xff344 add r0, pc, r0 */
/* @0xff348 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff34c mov r0, r9 */
/* @0xff350 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff354 add sp, sp, #8 */
/* @0xff358 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xff35c .word 0x002f29f0 */
/* @0xff360 .word 0xffffc028 */
/* @0xff364 .word 0xffffbcec */
/* @0xff368 .word 0xffffc02c */
/* @0xff36c .word 0xffffc030 */
/* @0xff370 .word 0x002388d8 */
/* @0xff374 eoreq r8, r3, r4, lsr #18 */

/* ── FUNC 0xff378 · F_DsMapAddMap(RValue&, CInstance*, CInstance*, int, RValue*) · size=292 · insn=73 */
/* @0xff378 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xff37c sub sp, sp, #12 */
/* @0xff380 add r8, sp, #4 */
/* @0xff384 mov r6, r0 */
/* @0xff388 ldr r7, [sp, #0x28] */
/* @0xff38c mov r0, r8 */
/* @0xff390 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xff394 mov r3, #0 */
/* @0xff398 mov r1, r3 */
/* @0xff39c str r3, [r6, #0xc] */
/* @0xff3a0 str r3, [r6] */
/* @0xff3a4 mov r0, r7 */
/* @0xff3a8 str r3, [r6, #0x4] */
/* @0xff3ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff3b0 cmp r0, #0 */
/* @0xff3b4 blt 0xff44c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0xff3b8 ldr r3, [pc, #0xcc] */
/* @0xff3bc ldr r3, [pc, r3] */
/* @0xff3c0 ldr r3, [r3] */
/* @0xff3c4 cmp r0, r3 */
/* @0xff3c8 bge 0xff44c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0xff3cc ldr r2, [pc, #0xbc] */
/* @0xff3d0 ldr r2, [pc, r2] */
/* @0xff3d4 ldr r2, [r2, #0x4] */
/* @0xff3d8 ldr r0, [r2, r0, lsl #2] */
/* @0xff3dc cmp r0, #0 */
/* @0xff3e0 beq 0xff44c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0xff3e4 ldr r9, [r7, #0x2c] */
/* @0xff3e8 ldr r4, [r7, #0x20] */
/* @0xff3ec cmp r9, #0 */
/* @0xff3f0 ldr r5, [r7, #0x24] */
/* @0xff3f4 bne 0xff46c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0xff3f8 vmov d7, r4, r5 */
/* @0xff3fc vcvt.s32.f64 s15, d7 */
/* @0xff400 vmov r4, s15 */
/* @0xff404 cmp r4, #0 */
/* @0xff408 blt 0xff46c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0xff40c cmp r3, r4 */
/* @0xff410 ble 0xff46c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0xff414 ldr r3, [r2, r4, lsl #2] */
/* @0xff418 cmp r3, #0 */
/* @0xff41c beq 0xff46c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0xff420 mov r3, #-2147483648 */
/* @0xff424 add r1, r7, #16 */
/* @0xff428 str r3, [r7, #0x2c] */
/* @0xff42c add r2, r7, #32 */
/* @0xff430 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0xff434 cmp r0, #0 */
/* @0xff438 movne r3, #0 */
/* @0xff43c strne r9, [r6] */
/* @0xff440 movtne r3, #0x3ff0 */
/* @0xff444 strne r3, [r6, #0x4] */
/* @0xff448 b 0xff45c <_Z13F_DsMapAddMapR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0xff44c ldr r0, [pc, #0x40] */
/* @0xff450 mov r1, #0 */
/* @0xff454 add r0, pc, r0 */
/* @0xff458 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff45c mov r0, r8 */
/* @0xff460 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff464 add sp, sp, #12 */
/* @0xff468 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xff46c ldr r0, [pc, #0x24] */
/* @0xff470 mov r1, #0 */
/* @0xff474 add r0, pc, r0 */
/* @0xff478 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff47c mov r0, r8 */
/* @0xff480 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff484 add sp, sp, #12 */
/* @0xff488 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xff48c .word 0x002ee8bc */
/* @0xff490 eoreq lr, lr, r12, ror #10 */
/* @0xff494 eoreq r8, r3, r8, lsr #15 */
/* @0xff498 eoreq r8, r3, r4, lsl r8 */

/* ── FUNC 0xff49c · F_DsMapReplace(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0xff49c push {r4, r5, r6, r7, lr} */
/* @0xff4a0 sub sp, sp, #12 */
/* @0xff4a4 add r6, sp, #4 */
/* @0xff4a8 mov r5, r0 */
/* @0xff4ac ldr r7, [sp, #0x20] */
/* @0xff4b0 mov r4, #0 */
/* @0xff4b4 mov r0, r6 */
/* @0xff4b8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xff4bc str r4, [r5, #0xc] */
/* @0xff4c0 str r4, [r5] */
/* @0xff4c4 mov r0, r7 */
/* @0xff4c8 str r4, [r5, #0x4] */
/* @0xff4cc mov r1, r4 */
/* @0xff4d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xff4d4 cmp r0, #0 */
/* @0xff4d8 blt 0xff538 <_Z14F_DsMapReplaceR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0xff4dc ldr r3, [pc, #0x74] */
/* @0xff4e0 ldr r3, [pc, r3] */
/* @0xff4e4 ldr r3, [r3] */
/* @0xff4e8 cmp r0, r3 */
/* @0xff4ec bge 0xff538 <_Z14F_DsMapReplaceR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0xff4f0 ldr r3, [pc, #0x64] */
/* @0xff4f4 ldr r3, [pc, r3] */
/* @0xff4f8 ldr r3, [r3, #0x4] */
/* @0xff4fc ldr r0, [r3, r0, lsl #2] */
/* @0xff500 cmp r0, r4 */
/* @0xff504 beq 0xff538 <_Z14F_DsMapReplaceR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0xff508 add r1, r7, #16 */
/* @0xff50c add r2, r7, #32 */
/* @0xff510 bl 0x20bc44 <_ZN7CDS_Map7ReplaceEP6RValueS1_> */
/* @0xff514 cmp r0, #0 */
/* @0xff518 mov r0, r6 */
/* @0xff51c strne r4, [r5] */
/* @0xff520 movne r3, #0 */
/* @0xff524 movtne r3, #0x3ff0 */
/* @0xff528 strne r3, [r5, #0x4] */
/* @0xff52c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff530 add sp, sp, #12 */
/* @0xff534 pop {r4, r5, r6, r7, pc} */
/* @0xff538 ldr r0, [pc, #0x20] */
/* @0xff53c mov r1, #0 */
/* @0xff540 add r0, pc, r0 */
/* @0xff544 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xff548 mov r0, r6 */
/* @0xff54c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xff550 add sp, sp, #12 */
/* @0xff554 pop {r4, r5, r6, r7, pc} */
/* @0xff558 mlaeq lr, r8, r7, lr */
/* @0xff55c eoreq lr, lr, r8, asr #8 */
/* @0xff560 .word 0x002386bc */
