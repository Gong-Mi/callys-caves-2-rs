/* libyoyo.so 覆盖卡组 0102
 * 函数 0x165250..0x1661fc，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x165250 · GR_3DM_LoadFromFile(int, char const*) · size=72 · insn=18 */
/* @0x165250 cmp r0, #0 */
/* @0x165254 blt 0x165288 <_Z19GR_3DM_LoadFromFileiPKc+0x38> */
/* @0x165258 ldr r3, [pc, #0x30] */
/* @0x16525c ldr r3, [pc, r3] */
/* @0x165260 ldr r3, [r3] */
/* @0x165264 cmp r0, r3 */
/* @0x165268 bge 0x165288 <_Z19GR_3DM_LoadFromFileiPKc+0x38> */
/* @0x16526c ldr r3, [pc, #0x20] */
/* @0x165270 ldr r3, [pc, r3] */
/* @0x165274 ldr r3, [r3, #0x4] */
/* @0x165278 ldr r0, [r3, r0, lsl #2] */
/* @0x16527c cmp r0, #0 */
/* @0x165280 beq 0x165288 <_Z19GR_3DM_LoadFromFileiPKc+0x38> */
/* @0x165284 b 0x163efc <_ZN9C3D_Model12LoadFromFileEPKc> */
/* @0x165288 mov r0, #0 */
/* @0x16528c bx lr */
/* @0x165290 mlaeq r8, r4, lr, r10 */
/* @0x165294 eoreq r10, r8, r4, lsl #29 */

/* ── FUNC 0x165298 · GR_3DM_LoadFromBuffer(int, int) · size=72 · insn=18 */
/* @0x165298 cmp r0, #0 */
/* @0x16529c blt 0x1652d0 <_Z21GR_3DM_LoadFromBufferii+0x38> */
/* @0x1652a0 ldr r3, [pc, #0x30] */
/* @0x1652a4 ldr r3, [pc, r3] */
/* @0x1652a8 ldr r3, [r3] */
/* @0x1652ac cmp r0, r3 */
/* @0x1652b0 bge 0x1652d0 <_Z21GR_3DM_LoadFromBufferii+0x38> */
/* @0x1652b4 ldr r3, [pc, #0x20] */
/* @0x1652b8 ldr r3, [pc, r3] */
/* @0x1652bc ldr r3, [r3, #0x4] */
/* @0x1652c0 ldr r0, [r3, r0, lsl #2] */
/* @0x1652c4 cmp r0, #0 */
/* @0x1652c8 beq 0x1652d0 <_Z21GR_3DM_LoadFromBufferii+0x38> */
/* @0x1652cc b 0x1641f0 <_ZN9C3D_Model14LoadFromBufferEi> */
/* @0x1652d0 mov r0, #0 */
/* @0x1652d4 bx lr */
/* @0x1652d8 eoreq r10, r8, r12, asr #28 */
/* @0x1652dc eoreq r10, r8, r12, lsr lr */

/* ── FUNC 0x1652e0 · GR_3DM_SaveToFile(int, char const*) · size=72 · insn=18 */
/* @0x1652e0 cmp r0, #0 */
/* @0x1652e4 blt 0x165318 <_Z17GR_3DM_SaveToFileiPKc+0x38> */
/* @0x1652e8 ldr r3, [pc, #0x30] */
/* @0x1652ec ldr r3, [pc, r3] */
/* @0x1652f0 ldr r3, [r3] */
/* @0x1652f4 cmp r0, r3 */
/* @0x1652f8 bge 0x165318 <_Z17GR_3DM_SaveToFileiPKc+0x38> */
/* @0x1652fc ldr r3, [pc, #0x20] */
/* @0x165300 ldr r3, [pc, r3] */
/* @0x165304 ldr r3, [r3, #0x4] */
/* @0x165308 ldr r0, [r3, r0, lsl #2] */
/* @0x16530c cmp r0, #0 */
/* @0x165310 beq 0x165318 <_Z17GR_3DM_SaveToFileiPKc+0x38> */
/* @0x165314 b 0x1644f8 <_ZN9C3D_Model10SaveToFileEPKc> */
/* @0x165318 mov r0, #0 */
/* @0x16531c bx lr */
/* @0x165320 eoreq r10, r8, r4, lsl #28 */
/* @0x165324 .word 0x0028adf4 */

/* ── FUNC 0x165328 · GR_3DM_SaveToBuffer(int, int) · size=72 · insn=18 */
/* @0x165328 cmp r0, #0 */
/* @0x16532c blt 0x165360 <_Z19GR_3DM_SaveToBufferii+0x38> */
/* @0x165330 ldr r3, [pc, #0x30] */
/* @0x165334 ldr r3, [pc, r3] */
/* @0x165338 ldr r3, [r3] */
/* @0x16533c cmp r0, r3 */
/* @0x165340 bge 0x165360 <_Z19GR_3DM_SaveToBufferii+0x38> */
/* @0x165344 ldr r3, [pc, #0x20] */
/* @0x165348 ldr r3, [pc, r3] */
/* @0x16534c ldr r3, [r3, #0x4] */
/* @0x165350 ldr r0, [r3, r0, lsl #2] */
/* @0x165354 cmp r0, #0 */
/* @0x165358 beq 0x165360 <_Z19GR_3DM_SaveToBufferii+0x38> */
/* @0x16535c b 0x1646f4 <_ZN9C3D_Model12SaveToBufferEi> */
/* @0x165360 mov r0, #0 */
/* @0x165364 bx lr */
/* @0x165368 .word 0x0028adbc */
/* @0x16536c eoreq r10, r8, r12, lsr #27 */

/* ── FUNC 0x165370 · GR_3DM_Draw(int, float, float, float, int) · size=80 · insn=20 */
/* @0x165370 cmp r0, #0 */
/* @0x165374 str r4, [sp, #-0x4]! */
/* @0x165378 blt 0x1653b0 <_Z11GR_3DM_Drawifffi+0x40> */
/* @0x16537c ldr r12, [pc, #0x34] */
/* @0x165380 ldr r12, [pc, r12] */
/* @0x165384 ldr r12, [r12] */
/* @0x165388 cmp r0, r12 */
/* @0x16538c bge 0x1653b0 <_Z11GR_3DM_Drawifffi+0x40> */
/* @0x165390 ldr r12, [pc, #0x24] */
/* @0x165394 ldr r12, [pc, r12] */
/* @0x165398 ldr r12, [r12, #0x4] */
/* @0x16539c ldr r0, [r12, r0, lsl #2] */
/* @0x1653a0 cmp r0, #0 */
/* @0x1653a4 beq 0x1653b0 <_Z11GR_3DM_Drawifffi+0x40> */
/* @0x1653a8 ldr r4, [sp], #4 */
/* @0x1653ac b 0x1649ac <_ZN9C3D_Model4DrawEfffi> */
/* @0x1653b0 ldr r4, [sp], #4 */
/* @0x1653b4 bx lr */
/* @0x1653b8 eoreq r10, r8, r0, ror sp */
/* @0x1653bc eoreq r10, r8, r0, ror #26 */

/* ── FUNC 0x1653c0 · GR_3DM_Primitive_Begin(int, int) · size=132 · insn=33 */
/* @0x1653c0 cmp r0, #0 */
/* @0x1653c4 str lr, [sp, #-0x4]! */
/* @0x1653c8 sub sp, sp, #36 */
/* @0x1653cc blt 0x165434 <_Z22GR_3DM_Primitive_Beginii+0x74> */
/* @0x1653d0 ldr r3, [pc, #0x64] */
/* @0x1653d4 ldr r3, [pc, r3] */
/* @0x1653d8 ldr r3, [r3] */
/* @0x1653dc cmp r0, r3 */
/* @0x1653e0 bge 0x165434 <_Z22GR_3DM_Primitive_Beginii+0x74> */
/* @0x1653e4 ldr r3, [pc, #0x54] */
/* @0x1653e8 ldr r3, [pc, r3] */
/* @0x1653ec ldr r3, [r3, #0x4] */
/* @0x1653f0 ldr r0, [r3, r0, lsl #2] */
/* @0x1653f4 cmp r0, #0 */
/* @0x1653f8 beq 0x165434 <_Z22GR_3DM_Primitive_Beginii+0x74> */
/* @0x1653fc vmov s15, r1 */
/* @0x165400 mov r3, #0 */
/* @0x165404 mov r1, #0 */
/* @0x165408 str r3, [sp] */
/* @0x16540c vcvt.f32.s32 s15, s15 */
/* @0x165410 str r3, [sp, #0x4] */
/* @0x165414 str r3, [sp, #0x8] */
/* @0x165418 str r3, [sp, #0xc] */
/* @0x16541c str r3, [sp, #0x10] */
/* @0x165420 str r3, [sp, #0x14] */
/* @0x165424 str r3, [sp, #0x18] */
/* @0x165428 str r3, [sp, #0x1c] */
/* @0x16542c vmov r2, s15 */
/* @0x165430 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x165434 add sp, sp, #36 */
/* @0x165438 ldr pc, [sp], #4 */
/* @0x16543c eoreq r10, r8, r12, lsl sp */
/* @0x165440 eoreq r10, r8, r12, lsl #26 */

/* ── FUNC 0x165444 · GR_3DM_Vertex(int, float, float, float) · size=132 · insn=33 */
/* @0x165444 cmp r0, #0 */
/* @0x165448 push {r4, lr} */
/* @0x16544c mov r4, r2 */
/* @0x165450 sub sp, sp, #32 */
/* @0x165454 blt 0x1654b8 <_Z13GR_3DM_Vertexifff+0x74> */
/* @0x165458 ldr r12, [pc, #0x60] */
/* @0x16545c ldr r12, [pc, r12] */
/* @0x165460 ldr r12, [r12] */
/* @0x165464 cmp r0, r12 */
/* @0x165468 bge 0x1654b8 <_Z13GR_3DM_Vertexifff+0x74> */
/* @0x16546c ldr r12, [pc, #0x50] */
/* @0x165470 ldr r12, [pc, r12] */
/* @0x165474 ldr r2, [r12, #0x4] */
/* @0x165478 ldr r0, [r2, r0, lsl #2] */
/* @0x16547c cmp r0, #0 */
/* @0x165480 beq 0x1654b8 <_Z13GR_3DM_Vertexifff+0x74> */
/* @0x165484 str r3, [sp] */
/* @0x165488 mov r2, r1 */
/* @0x16548c mov r3, r4 */
/* @0x165490 mov r1, #0 */
/* @0x165494 str r1, [sp, #0x4] */
/* @0x165498 str r1, [sp, #0x8] */
/* @0x16549c str r1, [sp, #0xc] */
/* @0x1654a0 str r1, [sp, #0x10] */
/* @0x1654a4 str r1, [sp, #0x14] */
/* @0x1654a8 str r1, [sp, #0x18] */
/* @0x1654ac str r1, [sp, #0x1c] */
/* @0x1654b0 mov r1, #2 */
/* @0x1654b4 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x1654b8 add sp, sp, #32 */
/* @0x1654bc pop {r4, pc} */
/* @0x1654c0 mlaeq r8, r4, r12, r10 */
/* @0x1654c4 eoreq r10, r8, r4, lsl #25 */

/* ── FUNC 0x1654c8 · GR_3DM_Vertex_Color(int, float, float, float, unsigned int, float) · size=140 · insn=35 */
/* @0x1654c8 cmp r0, #0 */
/* @0x1654cc push {r4, lr} */
/* @0x1654d0 mov r4, r2 */
/* @0x1654d4 sub sp, sp, #32 */
/* @0x1654d8 blt 0x165544 <_Z19GR_3DM_Vertex_Colorifffjf+0x7c> */
/* @0x1654dc ldr r12, [pc, #0x68] */
/* @0x1654e0 ldr r12, [pc, r12] */
/* @0x1654e4 ldr r12, [r12] */
/* @0x1654e8 cmp r0, r12 */
/* @0x1654ec bge 0x165544 <_Z19GR_3DM_Vertex_Colorifffjf+0x7c> */
/* @0x1654f0 ldr r12, [pc, #0x58] */
/* @0x1654f4 ldr r12, [pc, r12] */
/* @0x1654f8 ldr r2, [r12, #0x4] */
/* @0x1654fc ldr r0, [r2, r0, lsl #2] */
/* @0x165500 cmp r0, #0 */
/* @0x165504 beq 0x165544 <_Z19GR_3DM_Vertex_Colorifffjf+0x7c> */
/* @0x165508 ldr r12, [sp, #0x28] */
/* @0x16550c vldr s15, [sp, #44] */
/* @0x165510 str r3, [sp] */
/* @0x165514 mov r2, r1 */
/* @0x165518 vstr s15, [sp, #8] */
/* @0x16551c mov r1, #0 */
/* @0x165520 mov r3, r4 */
/* @0x165524 str r1, [sp, #0xc] */
/* @0x165528 str r1, [sp, #0x10] */
/* @0x16552c str r1, [sp, #0x14] */
/* @0x165530 str r1, [sp, #0x18] */
/* @0x165534 str r1, [sp, #0x1c] */
/* @0x165538 mov r1, #3 */
/* @0x16553c str r12, [sp, #0x4] */
/* @0x165540 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x165544 add sp, sp, #32 */
/* @0x165548 pop {r4, pc} */
/* @0x16554c eoreq r10, r8, r0, lsl r12 */
/* @0x165550 eoreq r10, r8, r0, lsl #24 */

/* ── FUNC 0x165554 · GR_3DM_Vertex_Texture(int, float, float, float, float, float) · size=140 · insn=35 */
/* @0x165554 cmp r0, #0 */
/* @0x165558 push {r4, lr} */
/* @0x16555c mov r4, r2 */
/* @0x165560 sub sp, sp, #32 */
/* @0x165564 blt 0x1655d0 <_Z21GR_3DM_Vertex_Textureifffff+0x7c> */
/* @0x165568 ldr r12, [pc, #0x68] */
/* @0x16556c ldr r12, [pc, r12] */
/* @0x165570 ldr r12, [r12] */
/* @0x165574 cmp r0, r12 */
/* @0x165578 bge 0x1655d0 <_Z21GR_3DM_Vertex_Textureifffff+0x7c> */
/* @0x16557c ldr r12, [pc, #0x58] */
/* @0x165580 ldr r12, [pc, r12] */
/* @0x165584 ldr r2, [r12, #0x4] */
/* @0x165588 ldr r0, [r2, r0, lsl #2] */
/* @0x16558c cmp r0, #0 */
/* @0x165590 beq 0x1655d0 <_Z21GR_3DM_Vertex_Textureifffff+0x7c> */
/* @0x165594 vldr s15, [sp, #40] */
/* @0x165598 str r3, [sp] */
/* @0x16559c vstr s15, [sp, #4] */
/* @0x1655a0 mov r2, r1 */
/* @0x1655a4 vldr s15, [sp, #44] */
/* @0x1655a8 mov r1, #0 */
/* @0x1655ac vstr s15, [sp, #8] */
/* @0x1655b0 str r1, [sp, #0xc] */
/* @0x1655b4 str r1, [sp, #0x10] */
/* @0x1655b8 mov r3, r4 */
/* @0x1655bc str r1, [sp, #0x14] */
/* @0x1655c0 str r1, [sp, #0x18] */
/* @0x1655c4 str r1, [sp, #0x1c] */
/* @0x1655c8 mov r1, #4 */
/* @0x1655cc bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x1655d0 add sp, sp, #32 */
/* @0x1655d4 pop {r4, pc} */
/* @0x1655d8 eoreq r10, r8, r4, lsl #23 */
/* @0x1655dc eoreq r10, r8, r4, ror r11 */

/* ── FUNC 0x1655e0 · GR_3DM_Vertex_Texture_Color(int, float, float, float, float, float, unsigned int, float) · size=148 · insn=37 */
/* @0x1655e0 cmp r0, #0 */
/* @0x1655e4 push {r4, lr} */
/* @0x1655e8 mov r4, r2 */
/* @0x1655ec sub sp, sp, #32 */
/* @0x1655f0 blt 0x165664 <_Z27GR_3DM_Vertex_Texture_Colorifffffjf+0x84> */
/* @0x1655f4 ldr r12, [pc, #0x70] */
/* @0x1655f8 ldr r12, [pc, r12] */
/* @0x1655fc ldr r12, [r12] */
/* @0x165600 cmp r0, r12 */
/* @0x165604 bge 0x165664 <_Z27GR_3DM_Vertex_Texture_Colorifffffjf+0x84> */
/* @0x165608 ldr r12, [pc, #0x60] */
/* @0x16560c ldr r12, [pc, r12] */
/* @0x165610 ldr r2, [r12, #0x4] */
/* @0x165614 ldr r0, [r2, r0, lsl #2] */
/* @0x165618 cmp r0, #0 */
/* @0x16561c beq 0x165664 <_Z27GR_3DM_Vertex_Texture_Colorifffffjf+0x84> */
/* @0x165620 ldr r12, [sp, #0x30] */
/* @0x165624 vldr s15, [sp, #40] */
/* @0x165628 str r3, [sp] */
/* @0x16562c vstr s15, [sp, #4] */
/* @0x165630 mov r2, r1 */
/* @0x165634 vldr s15, [sp, #44] */
/* @0x165638 mov r1, #0 */
/* @0x16563c vstr s15, [sp, #8] */
/* @0x165640 str r1, [sp, #0x14] */
/* @0x165644 vldr s15, [sp, #52] */
/* @0x165648 str r1, [sp, #0x18] */
/* @0x16564c vstr s15, [sp, #16] */
/* @0x165650 str r1, [sp, #0x1c] */
/* @0x165654 mov r3, r4 */
/* @0x165658 str r12, [sp, #0xc] */
/* @0x16565c mov r1, #5 */
/* @0x165660 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x165664 add sp, sp, #32 */
/* @0x165668 pop {r4, pc} */
/* @0x16566c .word 0x0028aaf8 */
/* @0x165670 eoreq r10, r8, r8, ror #21 */

/* ── FUNC 0x165674 · GR_3DM_Vertex_N(int, float, float, float, float, float, float) · size=144 · insn=36 */
/* @0x165674 cmp r0, #0 */
/* @0x165678 push {r4, lr} */
/* @0x16567c mov r4, r2 */
/* @0x165680 sub sp, sp, #32 */
/* @0x165684 blt 0x1656f4 <_Z15GR_3DM_Vertex_Niffffff+0x80> */
/* @0x165688 ldr r12, [pc, #0x6c] */
/* @0x16568c ldr r12, [pc, r12] */
/* @0x165690 ldr r12, [r12] */
/* @0x165694 cmp r0, r12 */
/* @0x165698 bge 0x1656f4 <_Z15GR_3DM_Vertex_Niffffff+0x80> */
/* @0x16569c ldr r12, [pc, #0x5c] */
/* @0x1656a0 ldr r12, [pc, r12] */
/* @0x1656a4 ldr r2, [r12, #0x4] */
/* @0x1656a8 ldr r0, [r2, r0, lsl #2] */
/* @0x1656ac cmp r0, #0 */
/* @0x1656b0 beq 0x1656f4 <_Z15GR_3DM_Vertex_Niffffff+0x80> */
/* @0x1656b4 mov r12, #0 */
/* @0x1656b8 vldr s15, [sp, #40] */
/* @0x1656bc str r3, [sp] */
/* @0x1656c0 vstr s15, [sp, #4] */
/* @0x1656c4 mov r2, r1 */
/* @0x1656c8 vldr s15, [sp, #44] */
/* @0x1656cc mov r3, r4 */
/* @0x1656d0 vstr s15, [sp, #8] */
/* @0x1656d4 mov r1, #6 */
/* @0x1656d8 vldr s15, [sp, #48] */
/* @0x1656dc str r12, [sp, #0x10] */
/* @0x1656e0 vstr s15, [sp, #12] */
/* @0x1656e4 str r12, [sp, #0x14] */
/* @0x1656e8 str r12, [sp, #0x18] */
/* @0x1656ec str r12, [sp, #0x1c] */
/* @0x1656f0 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x1656f4 add sp, sp, #32 */
/* @0x1656f8 pop {r4, pc} */
/* @0x1656fc eoreq r10, r8, r4, ror #20 */
/* @0x165700 eoreq r10, r8, r4, asr r10 */

/* ── FUNC 0x165704 · GR_3DM_Vertex_N_Color(int, float, float, float, float, float, float, unsigned int, float) · size=152 · insn=38 */
/* @0x165704 cmp r0, #0 */
/* @0x165708 push {r4, lr} */
/* @0x16570c mov r4, r2 */
/* @0x165710 sub sp, sp, #32 */
/* @0x165714 blt 0x16578c <_Z21GR_3DM_Vertex_N_Coloriffffffjf+0x88> */
/* @0x165718 ldr r12, [pc, #0x74] */
/* @0x16571c ldr r12, [pc, r12] */
/* @0x165720 ldr r12, [r12] */
/* @0x165724 cmp r0, r12 */
/* @0x165728 bge 0x16578c <_Z21GR_3DM_Vertex_N_Coloriffffffjf+0x88> */
/* @0x16572c ldr r12, [pc, #0x64] */
/* @0x165730 ldr r12, [pc, r12] */
/* @0x165734 ldr r2, [r12, #0x4] */
/* @0x165738 ldr r0, [r2, r0, lsl #2] */
/* @0x16573c cmp r0, #0 */
/* @0x165740 beq 0x16578c <_Z21GR_3DM_Vertex_N_Coloriffffffjf+0x88> */
/* @0x165744 ldr r12, [sp, #0x34] */
/* @0x165748 vldr s15, [sp, #40] */
/* @0x16574c str r3, [sp] */
/* @0x165750 vstr s15, [sp, #4] */
/* @0x165754 mov r2, r1 */
/* @0x165758 vldr s15, [sp, #44] */
/* @0x16575c mov r1, #0 */
/* @0x165760 vstr s15, [sp, #8] */
/* @0x165764 str r1, [sp, #0x18] */
/* @0x165768 vldr s15, [sp, #48] */
/* @0x16576c str r1, [sp, #0x1c] */
/* @0x165770 vstr s15, [sp, #12] */
/* @0x165774 mov r3, r4 */
/* @0x165778 vldr s15, [sp, #56] */
/* @0x16577c str r12, [sp, #0x10] */
/* @0x165780 vstr s15, [sp, #20] */
/* @0x165784 mov r1, #7 */
/* @0x165788 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x16578c add sp, sp, #32 */
/* @0x165790 pop {r4, pc} */
/* @0x165794 .word 0x0028a9d4 */
/* @0x165798 eoreq r10, r8, r4, asr #19 */

/* ── FUNC 0x16579c · GR_3DM_Vertex_N_Texture(int, float, float, float, float, float, float, float, float) · size=152 · insn=38 */
/* @0x16579c cmp r0, #0 */
/* @0x1657a0 push {r4, lr} */
/* @0x1657a4 mov r4, r2 */
/* @0x1657a8 sub sp, sp, #32 */
/* @0x1657ac blt 0x165824 <_Z23GR_3DM_Vertex_N_Textureiffffffff+0x88> */
/* @0x1657b0 ldr r12, [pc, #0x74] */
/* @0x1657b4 ldr r12, [pc, r12] */
/* @0x1657b8 ldr r12, [r12] */
/* @0x1657bc cmp r0, r12 */
/* @0x1657c0 bge 0x165824 <_Z23GR_3DM_Vertex_N_Textureiffffffff+0x88> */
/* @0x1657c4 ldr r12, [pc, #0x64] */
/* @0x1657c8 ldr r12, [pc, r12] */
/* @0x1657cc ldr r2, [r12, #0x4] */
/* @0x1657d0 ldr r0, [r2, r0, lsl #2] */
/* @0x1657d4 cmp r0, #0 */
/* @0x1657d8 beq 0x165824 <_Z23GR_3DM_Vertex_N_Textureiffffffff+0x88> */
/* @0x1657dc vldr s15, [sp, #40] */
/* @0x1657e0 mov r12, #0 */
/* @0x1657e4 str r3, [sp] */
/* @0x1657e8 vstr s15, [sp, #4] */
/* @0x1657ec mov r2, r1 */
/* @0x1657f0 vldr s15, [sp, #44] */
/* @0x1657f4 mov r3, r4 */
/* @0x1657f8 vstr s15, [sp, #8] */
/* @0x1657fc mov r1, #8 */
/* @0x165800 vldr s15, [sp, #48] */
/* @0x165804 str r12, [sp, #0x18] */
/* @0x165808 vstr s15, [sp, #12] */
/* @0x16580c str r12, [sp, #0x1c] */
/* @0x165810 vldr s15, [sp, #52] */
/* @0x165814 vstr s15, [sp, #16] */
/* @0x165818 vldr s15, [sp, #56] */
/* @0x16581c vstr s15, [sp, #20] */
/* @0x165820 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x165824 add sp, sp, #32 */
/* @0x165828 pop {r4, pc} */
/* @0x16582c eoreq r10, r8, r12, lsr r9 */
/* @0x165830 eoreq r10, r8, r12, lsr #18 */

/* ── FUNC 0x165834 · GR_3DM_Vertex_N_Texture_Color(int, float, float, float, float, float, float, float, float, unsigned int, float) · size=156 · insn=39 */
/* @0x165834 cmp r0, #0 */
/* @0x165838 push {r4, lr} */
/* @0x16583c mov r4, r2 */
/* @0x165840 sub sp, sp, #32 */
/* @0x165844 blt 0x1658c0 <_Z29GR_3DM_Vertex_N_Texture_Coloriffffffffjf+0x8c> */
/* @0x165848 ldr r12, [pc, #0x78] */
/* @0x16584c ldr r12, [pc, r12] */
/* @0x165850 ldr r12, [r12] */
/* @0x165854 cmp r0, r12 */
/* @0x165858 bge 0x1658c0 <_Z29GR_3DM_Vertex_N_Texture_Coloriffffffffjf+0x8c> */
/* @0x16585c ldr r12, [pc, #0x68] */
/* @0x165860 ldr r12, [pc, r12] */
/* @0x165864 ldr r2, [r12, #0x4] */
/* @0x165868 ldr r0, [r2, r0, lsl #2] */
/* @0x16586c cmp r0, #0 */
/* @0x165870 beq 0x1658c0 <_Z29GR_3DM_Vertex_N_Texture_Coloriffffffffjf+0x8c> */
/* @0x165874 ldr r12, [sp, #0x3c] */
/* @0x165878 vldr s15, [sp, #40] */
/* @0x16587c str r3, [sp] */
/* @0x165880 vstr s15, [sp, #4] */
/* @0x165884 mov r2, r1 */
/* @0x165888 vldr s15, [sp, #44] */
/* @0x16588c mov r1, #9 */
/* @0x165890 vstr s15, [sp, #8] */
/* @0x165894 mov r3, r4 */
/* @0x165898 vldr s15, [sp, #48] */
/* @0x16589c str r12, [sp, #0x18] */
/* @0x1658a0 vstr s15, [sp, #12] */
/* @0x1658a4 vldr s15, [sp, #52] */
/* @0x1658a8 vstr s15, [sp, #16] */
/* @0x1658ac vldr s15, [sp, #56] */
/* @0x1658b0 vstr s15, [sp, #20] */
/* @0x1658b4 vldr s15, [sp, #64] */
/* @0x1658b8 vstr s15, [sp, #28] */
/* @0x1658bc bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x1658c0 add sp, sp, #32 */
/* @0x1658c4 pop {r4, pc} */
/* @0x1658c8 eoreq r10, r8, r4, lsr #17 */
/* @0x1658cc mlaeq r8, r4, r8, r10 */

/* ── FUNC 0x1658d0 · GR_3DM_Primitive_End(int) · size=124 · insn=31 */
/* @0x1658d0 cmp r0, #0 */
/* @0x1658d4 str lr, [sp, #-0x4]! */
/* @0x1658d8 sub sp, sp, #36 */
/* @0x1658dc blt 0x16593c <_Z20GR_3DM_Primitive_Endi+0x6c> */
/* @0x1658e0 ldr r3, [pc, #0x5c] */
/* @0x1658e4 ldr r3, [pc, r3] */
/* @0x1658e8 ldr r3, [r3] */
/* @0x1658ec cmp r0, r3 */
/* @0x1658f0 bge 0x16593c <_Z20GR_3DM_Primitive_Endi+0x6c> */
/* @0x1658f4 ldr r3, [pc, #0x4c] */
/* @0x1658f8 ldr r3, [pc, r3] */
/* @0x1658fc ldr r3, [r3, #0x4] */
/* @0x165900 ldr r0, [r3, r0, lsl #2] */
/* @0x165904 cmp r0, #0 */
/* @0x165908 beq 0x16593c <_Z20GR_3DM_Primitive_Endi+0x6c> */
/* @0x16590c mov r3, #0 */
/* @0x165910 mov r1, #1 */
/* @0x165914 mov r2, r3 */
/* @0x165918 str r3, [sp] */
/* @0x16591c str r3, [sp, #0x4] */
/* @0x165920 str r3, [sp, #0x8] */
/* @0x165924 str r3, [sp, #0xc] */
/* @0x165928 str r3, [sp, #0x10] */
/* @0x16592c str r3, [sp, #0x14] */
/* @0x165930 str r3, [sp, #0x18] */
/* @0x165934 str r3, [sp, #0x1c] */
/* @0x165938 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x16593c add sp, sp, #36 */
/* @0x165940 ldr pc, [sp], #4 */
/* @0x165944 eoreq r10, r8, r12, lsl #16 */
/* @0x165948 .word 0x0028a7fc */

/* ── FUNC 0x16594c · GR_3DM_Block(int, float, float, float, float, float, float, float, float) · size=152 · insn=38 */
/* @0x16594c cmp r0, #0 */
/* @0x165950 push {r4, lr} */
/* @0x165954 mov r4, r2 */
/* @0x165958 sub sp, sp, #32 */
/* @0x16595c blt 0x1659d4 <_Z12GR_3DM_Blockiffffffff+0x88> */
/* @0x165960 ldr r12, [pc, #0x74] */
/* @0x165964 ldr r12, [pc, r12] */
/* @0x165968 ldr r12, [r12] */
/* @0x16596c cmp r0, r12 */
/* @0x165970 bge 0x1659d4 <_Z12GR_3DM_Blockiffffffff+0x88> */
/* @0x165974 ldr r12, [pc, #0x64] */
/* @0x165978 ldr r12, [pc, r12] */
/* @0x16597c ldr r2, [r12, #0x4] */
/* @0x165980 ldr r0, [r2, r0, lsl #2] */
/* @0x165984 cmp r0, #0 */
/* @0x165988 beq 0x1659d4 <_Z12GR_3DM_Blockiffffffff+0x88> */
/* @0x16598c vldr s15, [sp, #40] */
/* @0x165990 mov r12, #0 */
/* @0x165994 str r3, [sp] */
/* @0x165998 vstr s15, [sp, #4] */
/* @0x16599c mov r2, r1 */
/* @0x1659a0 vldr s15, [sp, #44] */
/* @0x1659a4 mov r3, r4 */
/* @0x1659a8 vstr s15, [sp, #8] */
/* @0x1659ac mov r1, #10 */
/* @0x1659b0 vldr s15, [sp, #48] */
/* @0x1659b4 str r12, [sp, #0x18] */
/* @0x1659b8 vstr s15, [sp, #12] */
/* @0x1659bc str r12, [sp, #0x1c] */
/* @0x1659c0 vldr s15, [sp, #52] */
/* @0x1659c4 vstr s15, [sp, #16] */
/* @0x1659c8 vldr s15, [sp, #56] */
/* @0x1659cc vstr s15, [sp, #20] */
/* @0x1659d0 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x1659d4 add sp, sp, #32 */
/* @0x1659d8 pop {r4, pc} */
/* @0x1659dc eoreq r10, r8, r12, lsl #15 */
/* @0x1659e0 eoreq r10, r8, r12, ror r7 */

/* ── FUNC 0x1659e4 · GR_3DM_Cylinder(int, float, float, float, float, float, float, float, float, bool, int) · size=156 · insn=39 */
/* @0x1659e4 push {r4, lr} */
/* @0x1659e8 cmp r0, #0 */
/* @0x1659ec sub sp, sp, #32 */
/* @0x1659f0 mov r4, r2 */
/* @0x1659f4 ldrb r2, [sp, #0x3c] */
/* @0x1659f8 blt 0x165a70 <_Z15GR_3DM_Cylinderiffffffffbi+0x8c> */
/* @0x1659fc ldr r12, [pc, #0x74] */
/* @0x165a00 ldr r12, [pc, r12] */
/* @0x165a04 ldr r12, [r12] */
/* @0x165a08 cmp r0, r12 */
/* @0x165a0c bge 0x165a70 <_Z15GR_3DM_Cylinderiffffffffbi+0x8c> */
/* @0x165a10 ldr r12, [pc, #0x64] */
/* @0x165a14 ldr r12, [pc, r12] */
/* @0x165a18 ldr r12, [r12, #0x4] */
/* @0x165a1c ldr r0, [r12, r0, lsl #2] */
/* @0x165a20 cmp r0, #0 */
/* @0x165a24 beq 0x165a70 <_Z15GR_3DM_Cylinderiffffffffbi+0x8c> */
/* @0x165a28 ldr r12, [sp, #0x40] */
/* @0x165a2c vldr s15, [sp, #40] */
/* @0x165a30 str r3, [sp] */
/* @0x165a34 vstr s15, [sp, #4] */
/* @0x165a38 str r2, [sp, #0x18] */
/* @0x165a3c vldr s15, [sp, #44] */
/* @0x165a40 mov r2, r1 */
/* @0x165a44 vstr s15, [sp, #8] */
/* @0x165a48 mov r3, r4 */
/* @0x165a4c vldr s15, [sp, #48] */
/* @0x165a50 mov r1, #11 */
/* @0x165a54 vstr s15, [sp, #12] */
/* @0x165a58 str r12, [sp, #0x1c] */
/* @0x165a5c vldr s15, [sp, #52] */
/* @0x165a60 vstr s15, [sp, #16] */
/* @0x165a64 vldr s15, [sp, #56] */
/* @0x165a68 vstr s15, [sp, #20] */
/* @0x165a6c bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x165a70 add sp, sp, #32 */
/* @0x165a74 pop {r4, pc} */
/* @0x165a78 .word 0x0028a6f0 */
/* @0x165a7c eoreq r10, r8, r0, ror #13 */

/* ── FUNC 0x165a80 · GR_3DM_Cone(int, float, float, float, float, float, float, float, float, bool, int) · size=156 · insn=39 */
/* @0x165a80 push {r4, lr} */
/* @0x165a84 cmp r0, #0 */
/* @0x165a88 sub sp, sp, #32 */
/* @0x165a8c mov r4, r2 */
/* @0x165a90 ldrb r2, [sp, #0x3c] */
/* @0x165a94 blt 0x165b0c <_Z11GR_3DM_Coneiffffffffbi+0x8c> */
/* @0x165a98 ldr r12, [pc, #0x74] */
/* @0x165a9c ldr r12, [pc, r12] */
/* @0x165aa0 ldr r12, [r12] */
/* @0x165aa4 cmp r0, r12 */
/* @0x165aa8 bge 0x165b0c <_Z11GR_3DM_Coneiffffffffbi+0x8c> */
/* @0x165aac ldr r12, [pc, #0x64] */
/* @0x165ab0 ldr r12, [pc, r12] */
/* @0x165ab4 ldr r12, [r12, #0x4] */
/* @0x165ab8 ldr r0, [r12, r0, lsl #2] */
/* @0x165abc cmp r0, #0 */
/* @0x165ac0 beq 0x165b0c <_Z11GR_3DM_Coneiffffffffbi+0x8c> */
/* @0x165ac4 ldr r12, [sp, #0x40] */
/* @0x165ac8 vldr s15, [sp, #40] */
/* @0x165acc str r3, [sp] */
/* @0x165ad0 vstr s15, [sp, #4] */
/* @0x165ad4 str r2, [sp, #0x18] */
/* @0x165ad8 vldr s15, [sp, #44] */
/* @0x165adc mov r2, r1 */
/* @0x165ae0 vstr s15, [sp, #8] */
/* @0x165ae4 mov r3, r4 */
/* @0x165ae8 vldr s15, [sp, #48] */
/* @0x165aec mov r1, #12 */
/* @0x165af0 vstr s15, [sp, #12] */
/* @0x165af4 str r12, [sp, #0x1c] */
/* @0x165af8 vldr s15, [sp, #52] */
/* @0x165afc vstr s15, [sp, #16] */
/* @0x165b00 vldr s15, [sp, #56] */
/* @0x165b04 vstr s15, [sp, #20] */
/* @0x165b08 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x165b0c add sp, sp, #32 */
/* @0x165b10 pop {r4, pc} */
/* @0x165b14 eoreq r10, r8, r4, asr r6 */
/* @0x165b18 eoreq r10, r8, r4, asr #12 */

/* ── FUNC 0x165b1c · GR_3DM_Ellipsoid(int, float, float, float, float, float, float, float, float, int) · size=156 · insn=39 */
/* @0x165b1c cmp r0, #0 */
/* @0x165b20 push {r4, lr} */
/* @0x165b24 mov r4, r2 */
/* @0x165b28 sub sp, sp, #32 */
/* @0x165b2c blt 0x165ba8 <_Z16GR_3DM_Ellipsoidiffffffffi+0x8c> */
/* @0x165b30 ldr r12, [pc, #0x78] */
/* @0x165b34 ldr r12, [pc, r12] */
/* @0x165b38 ldr r12, [r12] */
/* @0x165b3c cmp r0, r12 */
/* @0x165b40 bge 0x165ba8 <_Z16GR_3DM_Ellipsoidiffffffffi+0x8c> */
/* @0x165b44 ldr r12, [pc, #0x68] */
/* @0x165b48 ldr r12, [pc, r12] */
/* @0x165b4c ldr r2, [r12, #0x4] */
/* @0x165b50 ldr r0, [r2, r0, lsl #2] */
/* @0x165b54 cmp r0, #0 */
/* @0x165b58 beq 0x165ba8 <_Z16GR_3DM_Ellipsoidiffffffffi+0x8c> */
/* @0x165b5c mov r2, r1 */
/* @0x165b60 ldr r1, [sp, #0x3c] */
/* @0x165b64 vldr s15, [sp, #40] */
/* @0x165b68 str r3, [sp] */
/* @0x165b6c vstr s15, [sp, #4] */
/* @0x165b70 mov r12, #0 */
/* @0x165b74 vldr s15, [sp, #44] */
/* @0x165b78 str r1, [sp, #0x18] */
/* @0x165b7c vstr s15, [sp, #8] */
/* @0x165b80 mov r3, r4 */
/* @0x165b84 vldr s15, [sp, #48] */
/* @0x165b88 str r12, [sp, #0x1c] */
/* @0x165b8c vstr s15, [sp, #12] */
/* @0x165b90 mov r1, #13 */
/* @0x165b94 vldr s15, [sp, #52] */
/* @0x165b98 vstr s15, [sp, #16] */
/* @0x165b9c vldr s15, [sp, #56] */
/* @0x165ba0 vstr s15, [sp, #20] */
/* @0x165ba4 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x165ba8 add sp, sp, #32 */
/* @0x165bac pop {r4, pc} */
/* @0x165bb0 .word 0x0028a5bc */
/* @0x165bb4 eoreq r10, r8, r12, lsr #11 */

/* ── FUNC 0x165bb8 · GR_3DM_Wall(int, float, float, float, float, float, float, float, float) · size=152 · insn=38 */
/* @0x165bb8 cmp r0, #0 */
/* @0x165bbc push {r4, lr} */
/* @0x165bc0 mov r4, r2 */
/* @0x165bc4 sub sp, sp, #32 */
/* @0x165bc8 blt 0x165c40 <_Z11GR_3DM_Walliffffffff+0x88> */
/* @0x165bcc ldr r12, [pc, #0x74] */
/* @0x165bd0 ldr r12, [pc, r12] */
/* @0x165bd4 ldr r12, [r12] */
/* @0x165bd8 cmp r0, r12 */
/* @0x165bdc bge 0x165c40 <_Z11GR_3DM_Walliffffffff+0x88> */
/* @0x165be0 ldr r12, [pc, #0x64] */
/* @0x165be4 ldr r12, [pc, r12] */
/* @0x165be8 ldr r2, [r12, #0x4] */
/* @0x165bec ldr r0, [r2, r0, lsl #2] */
/* @0x165bf0 cmp r0, #0 */
/* @0x165bf4 beq 0x165c40 <_Z11GR_3DM_Walliffffffff+0x88> */
/* @0x165bf8 vldr s15, [sp, #40] */
/* @0x165bfc mov r12, #0 */
/* @0x165c00 str r3, [sp] */
/* @0x165c04 vstr s15, [sp, #4] */
/* @0x165c08 mov r2, r1 */
/* @0x165c0c vldr s15, [sp, #44] */
/* @0x165c10 mov r3, r4 */
/* @0x165c14 vstr s15, [sp, #8] */
/* @0x165c18 mov r1, #14 */
/* @0x165c1c vldr s15, [sp, #48] */
/* @0x165c20 str r12, [sp, #0x18] */
/* @0x165c24 vstr s15, [sp, #12] */
/* @0x165c28 str r12, [sp, #0x1c] */
/* @0x165c2c vldr s15, [sp, #52] */
/* @0x165c30 vstr s15, [sp, #16] */
/* @0x165c34 vldr s15, [sp, #56] */
/* @0x165c38 vstr s15, [sp, #20] */
/* @0x165c3c bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x165c40 add sp, sp, #32 */
/* @0x165c44 pop {r4, pc} */
/* @0x165c48 eoreq r10, r8, r0, lsr #10 */
/* @0x165c4c eoreq r10, r8, r0, lsl r5 */

/* ── FUNC 0x165c50 · GR_3DM_Floor(int, float, float, float, float, float, float, float, float) · size=152 · insn=38 */
/* @0x165c50 cmp r0, #0 */
/* @0x165c54 push {r4, lr} */
/* @0x165c58 mov r4, r2 */
/* @0x165c5c sub sp, sp, #32 */
/* @0x165c60 blt 0x165cd8 <_Z12GR_3DM_Flooriffffffff+0x88> */
/* @0x165c64 ldr r12, [pc, #0x74] */
/* @0x165c68 ldr r12, [pc, r12] */
/* @0x165c6c ldr r12, [r12] */
/* @0x165c70 cmp r0, r12 */
/* @0x165c74 bge 0x165cd8 <_Z12GR_3DM_Flooriffffffff+0x88> */
/* @0x165c78 ldr r12, [pc, #0x64] */
/* @0x165c7c ldr r12, [pc, r12] */
/* @0x165c80 ldr r2, [r12, #0x4] */
/* @0x165c84 ldr r0, [r2, r0, lsl #2] */
/* @0x165c88 cmp r0, #0 */
/* @0x165c8c beq 0x165cd8 <_Z12GR_3DM_Flooriffffffff+0x88> */
/* @0x165c90 vldr s15, [sp, #40] */
/* @0x165c94 mov r12, #0 */
/* @0x165c98 str r3, [sp] */
/* @0x165c9c vstr s15, [sp, #4] */
/* @0x165ca0 mov r2, r1 */
/* @0x165ca4 vldr s15, [sp, #44] */
/* @0x165ca8 mov r3, r4 */
/* @0x165cac vstr s15, [sp, #8] */
/* @0x165cb0 mov r1, #15 */
/* @0x165cb4 vldr s15, [sp, #48] */
/* @0x165cb8 str r12, [sp, #0x18] */
/* @0x165cbc vstr s15, [sp, #12] */
/* @0x165cc0 str r12, [sp, #0x1c] */
/* @0x165cc4 vldr s15, [sp, #52] */
/* @0x165cc8 vstr s15, [sp, #16] */
/* @0x165ccc vldr s15, [sp, #56] */
/* @0x165cd0 vstr s15, [sp, #20] */
/* @0x165cd4 bl 0x1648d4 <_ZN9C3D_Model8AddEntryEiffffffffff> */
/* @0x165cd8 add sp, sp, #32 */
/* @0x165cdc pop {r4, pc} */
/* @0x165ce0 eoreq r10, r8, r8, lsl #9 */
/* @0x165ce4 eoreq r10, r8, r8, ror r4 */

/* ── FUNC 0x165ce8 · Graphics_Bitmap32::Color_Merge(unsigned int, unsigned int, double) · size=196 · insn=49 */
/* @0x165ce8 push {r3, r4, r5, r6, r7, lr} */
/* @0x165cec vpush {d8, d9} */
/* @0x165cf0 mov r4, r1 */
/* @0x165cf4 uxtb r1, r1 */
/* @0x165cf8 vmov d8, r2, r3 */
/* @0x165cfc uxtb r3, r0 */
/* @0x165d00 mov r5, r0 */
/* @0x165d04 vmov s14, r1 */
/* @0x165d08 vmov.f64 d9, #1.000000e+00 */
/* @0x165d0c vmov s12, r3 */
/* @0x165d10 vcvt.f64.s32 d7, s14 */
/* @0x165d14 vmul.f64 d7, d7, d8 */
/* @0x165d18 vsub.f64 d9, d9, d8 */
/* @0x165d1c vcvt.f64.s32 d6, s12 */
/* @0x165d20 vmov.f64 d5, d7 */
/* @0x165d24 vmla.f64 d5, d6, d9 */
/* @0x165d28 vmov r0, r1, d5 */
/* @0x165d2c bl 0xb66e8 <lrint@plt> */
/* @0x165d30 ubfx r1, r4, #0x8, #0x8 */
/* @0x165d34 ubfx r3, r5, #0x8, #0x8 */
/* @0x165d38 ubfx r4, r4, #0x10, #0x8 */
/* @0x165d3c vmov s14, r1 */
/* @0x165d40 ubfx r5, r5, #0x10, #0x8 */
/* @0x165d44 vmov s12, r3 */
/* @0x165d48 vcvt.f64.s32 d7, s14 */
/* @0x165d4c vmul.f64 d7, d7, d8 */
/* @0x165d50 vcvt.f64.s32 d6, s12 */
/* @0x165d54 mov r6, r0 */
/* @0x165d58 vmov.f64 d5, d7 */
/* @0x165d5c vmla.f64 d5, d9, d6 */
/* @0x165d60 vmov r0, r1, d5 */
/* @0x165d64 bl 0xb66e8 <lrint@plt> */
/* @0x165d68 vmov s11, r4 */
/* @0x165d6c vcvt.f64.s32 d6, s11 */
/* @0x165d70 vmul.f64 d8, d6, d8 */
/* @0x165d74 vmov s12, r5 */
/* @0x165d78 vcvt.f64.s32 d7, s12 */
/* @0x165d7c mov r7, r0 */
/* @0x165d80 lsl r7, r7, #8 */
/* @0x165d84 vmov.f64 d5, d8 */
/* @0x165d88 uxth r7, r7 */
/* @0x165d8c uxtab r6, r7, r6 */
/* @0x165d90 vmla.f64 d5, d9, d7 */
/* @0x165d94 vmov r0, r1, d5 */
/* @0x165d98 bl 0xb66e8 <lrint@plt> */
/* @0x165d9c vpop {d8, d9} */
/* @0x165da0 uxtb r0, r0 */
/* @0x165da4 add r0, r6, r0, lsl #16 */
/* @0x165da8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x165dac · CBitmap32::Assign(CBitmap32*) · size=128 · insn=32 */
/* @0x165dac push {r3, r4, r5, lr} */
/* @0x165db0 mov r5, r1 */
/* @0x165db4 ldr r3, [r0, #0x10] */
/* @0x165db8 mov r4, r0 */
/* @0x165dbc ldrb r1, [r1, #0x4] */
/* @0x165dc0 ldr r2, [r5, #0x8] */
/* @0x165dc4 cmp r3, #0 */
/* @0x165dc8 ldr r3, [r5, #0xc] */
/* @0x165dcc strb r1, [r0, #0x4] */
/* @0x165dd0 str r2, [r0, #0x8] */
/* @0x165dd4 str r3, [r0, #0xc] */
/* @0x165dd8 movle r3, #0 */
/* @0x165ddc strle r3, [r0, #0x14] */
/* @0x165de0 ble 0x165df4 <_ZN9CBitmap326AssignEPS_+0x48> */
/* @0x165de4 ldr r0, [r0, #0x14] */
/* @0x165de8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x165dec mov r3, #0 */
/* @0x165df0 str r3, [r4, #0x10] */
/* @0x165df4 ldr r1, [r5, #0x10] */
/* @0x165df8 add r0, r4, #20 */
/* @0x165dfc ldr r2, [pc, #0x24] */
/* @0x165e00 mov r3, #111 */
/* @0x165e04 str r1, [r4, #0x10] */
/* @0x165e08 add r2, pc, r2 */
/* @0x165e0c ldr r1, [r5, #0x10] */
/* @0x165e10 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x165e14 ldr r0, [r4, #0x14] */
/* @0x165e18 ldr r1, [r5, #0x14] */
/* @0x165e1c ldr r2, [r5, #0x10] */
/* @0x165e20 pop {r3, r4, r5, lr} */
/* @0x165e24 b 0xb65bc <memcpy@plt> */
/* @0x165e28 ldrheq r4, [lr], -r8 */

/* ── FUNC 0x165e2c · CBitmap32::CBitmap32(CStream*) · size=364 · insn=91 */
/* @0x165e2c ldr r2, [pc, #0x158] */
/* @0x165e30 mov r3, #0 */
/* @0x165e34 push {r4, r5, r6, lr} */
/* @0x165e38 ldr r2, [pc, r2] */
/* @0x165e3c mov r4, r0 */
/* @0x165e40 strb r3, [r0, #0x4] */
/* @0x165e44 str r3, [r0, #0x8] */
/* @0x165e48 add r2, r2, #8 */
/* @0x165e4c str r2, [r0] */
/* @0x165e50 mov r0, r1 */
/* @0x165e54 str r3, [r4, #0xc] */
/* @0x165e58 mov r5, r1 */
/* @0x165e5c str r3, [r4, #0x14] */
/* @0x165e60 str r3, [r4, #0x10] */
/* @0x165e64 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x165e68 cmp r0, #540 */
/* @0x165e6c beq 0x165f1c <_ZN9CBitmap32C2EP7CStream+0xf0> */
/* @0x165e70 cmp r0, #800 */
/* @0x165e74 beq 0x165e80 <_ZN9CBitmap32C2EP7CStream+0x54> */
/* @0x165e78 mov r0, r4 */
/* @0x165e7c pop {r4, r5, r6, pc} */
/* @0x165e80 mov r6, #1 */
/* @0x165e84 mov r0, r5 */
/* @0x165e88 strb r6, [r4, #0x4] */
/* @0x165e8c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x165e90 str r0, [r4, #0x8] */
/* @0x165e94 mov r0, r5 */
/* @0x165e98 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x165e9c ldr r12, [r4, #0x8] */
/* @0x165ea0 ldr r1, [pc, #0xe8] */
/* @0x165ea4 mov r3, r6 */
/* @0x165ea8 mov r2, #171 */
/* @0x165eac add r1, pc, r1 */
/* @0x165eb0 str r0, [r4, #0xc] */
/* @0x165eb4 mul r0, r12, r0 */
/* @0x165eb8 lsl r0, r0, #2 */
/* @0x165ebc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x165ec0 ldr r3, [r4, #0x8] */
/* @0x165ec4 ldr r2, [r4, #0xc] */
/* @0x165ec8 mul r3, r2, r3 */
/* @0x165ecc lsl r3, r3, #2 */
/* @0x165ed0 str r3, [r4, #0x10] */
/* @0x165ed4 str r0, [r4, #0x14] */
/* @0x165ed8 mov r0, r5 */
/* @0x165edc bl 0x2019c4 <_ZN7CStream10ReadStreamEv> */
/* @0x165ee0 ldr r3, [r4, #0x8] */
/* @0x165ee4 mov r5, r0 */
/* @0x165ee8 ldr r2, [r4, #0xc] */
/* @0x165eec ldr r1, [r4, #0x14] */
/* @0x165ef0 mul r2, r2, r3 */
/* @0x165ef4 lsl r2, r2, #2 */
/* @0x165ef8 bl 0x2011e4 <_ZN7CStream10ReadBufferEPvi> */
/* @0x165efc cmp r5, #0 */
/* @0x165f00 beq 0x165e78 <_ZN9CBitmap32C2EP7CStream+0x4c> */
/* @0x165f04 mov r0, r5 */
/* @0x165f08 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x165f0c mov r0, r5 */
/* @0x165f10 bl 0x27d1d0 <_ZdlPv> */
/* @0x165f14 mov r0, r4 */
/* @0x165f18 pop {r4, r5, r6, pc} */
/* @0x165f1c mov r0, r5 */
/* @0x165f20 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x165f24 cmp r0, #0 */
/* @0x165f28 strb r0, [r4, #0x4] */
/* @0x165f2c beq 0x165e78 <_ZN9CBitmap32C2EP7CStream+0x4c> */
/* @0x165f30 mov r0, r5 */
/* @0x165f34 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x165f38 str r0, [r4, #0x8] */
/* @0x165f3c mov r0, r5 */
/* @0x165f40 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x165f44 ldr r12, [r4, #0x8] */
/* @0x165f48 ldr r1, [pc, #0x44] */
/* @0x165f4c mov r2, #159 */
/* @0x165f50 mov r3, #1 */
/* @0x165f54 add r1, pc, r1 */
/* @0x165f58 str r0, [r4, #0xc] */
/* @0x165f5c mul r0, r12, r0 */
/* @0x165f60 lsl r0, r0, #2 */
/* @0x165f64 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x165f68 ldr r3, [r4, #0x8] */
/* @0x165f6c ldr r2, [r4, #0xc] */
/* @0x165f70 mul r3, r2, r3 */
/* @0x165f74 lsl r3, r3, #2 */
/* @0x165f78 str r3, [r4, #0x10] */
/* @0x165f7c str r0, [r4, #0x14] */
/* @0x165f80 mov r0, r5 */
/* @0x165f84 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv> */
/* @0x165f88 b 0x165ee0 <_ZN9CBitmap32C2EP7CStream+0xb4> */
/* @0x165f8c eoreq r10, r8, r0, asr #5 */
/* @0x165f90 andseq r4, lr, r4, lsl r7 */
/* @0x165f94 andseq r4, lr, r12, ror #12 */

/* ── FUNC 0x165e2c · CBitmap32::CBitmap32(CStream*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x165f98 · CBitmap32::CBitmap32(CBitmap32*) · size=136 · insn=34 */
/* @0x165f98 push {r3, r4, r5, lr} */
/* @0x165f9c mov r5, r1 */
/* @0x165fa0 ldrb r2, [r1, #0x4] */
/* @0x165fa4 mov r4, r0 */
/* @0x165fa8 ldr r1, [r1, #0x8] */
/* @0x165fac ldr r0, [r5, #0xc] */
/* @0x165fb0 cmp r2, #0 */
/* @0x165fb4 ldr r3, [pc, #0x5c] */
/* @0x165fb8 strb r2, [r4, #0x4] */
/* @0x165fbc ldr r3, [pc, r3] */
/* @0x165fc0 str r1, [r4, #0x8] */
/* @0x165fc4 add r3, r3, #8 */
/* @0x165fc8 str r0, [r4, #0xc] */
/* @0x165fcc str r3, [r4] */
/* @0x165fd0 beq 0x166010 <_ZN9CBitmap32C2EPS_+0x78> */
/* @0x165fd4 mul r0, r0, r1 */
/* @0x165fd8 ldr r1, [pc, #0x3c] */
/* @0x165fdc mov r2, #204 */
/* @0x165fe0 mov r3, #1 */
/* @0x165fe4 add r1, pc, r1 */
/* @0x165fe8 lsl r0, r0, #2 */
/* @0x165fec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x165ff0 ldr r3, [r4, #0x8] */
/* @0x165ff4 ldr r2, [r4, #0xc] */
/* @0x165ff8 mul r2, r2, r3 */
/* @0x165ffc lsl r2, r2, #2 */
/* @0x166000 str r2, [r4, #0x10] */
/* @0x166004 str r0, [r4, #0x14] */
/* @0x166008 ldr r1, [r5, #0x14] */
/* @0x16600c bl 0xb65bc <memcpy@plt> */
/* @0x166010 mov r0, r4 */
/* @0x166014 pop {r3, r4, r5, pc} */
/* @0x166018 eoreq r10, r8, r12, lsr r1 */
/* @0x16601c ldrsbeq r4, [lr], -r12 */

/* ── FUNC 0x165f98 · CBitmap32::CBitmap32(CBitmap32*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x166020 · CBitmap32::CBitmap32(CBitmap32*, int, int, int, int) · size=288 · insn=72 */
/* @0x166020 push {r4, r5, r6, r7, r8, lr} */
/* @0x166024 mov r4, r0 */
/* @0x166028 mov r6, #0 */
/* @0x16602c strb r6, [r0, #0x4] */
/* @0x166030 ldrb r0, [r1, #0x4] */
/* @0x166034 mov r7, r1 */
/* @0x166038 ldr r1, [pc, #0xf8] */
/* @0x16603c mov r8, r2 */
/* @0x166040 cmp r0, r6 */
/* @0x166044 mov r5, r3 */
/* @0x166048 ldr r1, [pc, r1] */
/* @0x16604c str r6, [r4, #0x8] */
/* @0x166050 add r1, r1, #8 */
/* @0x166054 str r6, [r4, #0xc] */
/* @0x166058 str r1, [r4] */
/* @0x16605c str r6, [r4, #0x14] */
/* @0x166060 str r6, [r4, #0x10] */
/* @0x166064 beq 0x166130 <_ZN9CBitmap32C2EPS_iiii+0x110> */
/* @0x166068 ldr r1, [sp, #0x18] */
/* @0x16606c ldr r2, [r7, #0x8] */
/* @0x166070 add r3, r8, r1 */
/* @0x166074 cmp r2, r3 */
/* @0x166078 blt 0x166130 <_ZN9CBitmap32C2EPS_iiii+0x110> */
/* @0x16607c ldr r1, [sp, #0x1c] */
/* @0x166080 ldr r2, [r7, #0xc] */
/* @0x166084 add r3, r5, r1 */
/* @0x166088 cmp r2, r3 */
/* @0x16608c blt 0x166130 <_ZN9CBitmap32C2EPS_iiii+0x110> */
/* @0x166090 ldr r2, [sp, #0x1c] */
/* @0x166094 mov r1, #1 */
/* @0x166098 ldr r3, [sp, #0x18] */
/* @0x16609c strb r1, [r4, #0x4] */
/* @0x1660a0 str r2, [r4, #0xc] */
/* @0x1660a4 mul r0, r2, r3 */
/* @0x1660a8 str r3, [r4, #0x8] */
/* @0x1660ac mov r3, r1 */
/* @0x1660b0 ldr r1, [pc, #0x84] */
/* @0x1660b4 mov r2, #222 */
/* @0x1660b8 add r1, pc, r1 */
/* @0x1660bc lsl r0, r0, #2 */
/* @0x1660c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1660c4 ldr r2, [r7, #0x8] */
/* @0x1660c8 ldr r3, [r4, #0xc] */
/* @0x1660cc mla r5, r2, r5, r8 */
/* @0x1660d0 cmp r3, #0 */
/* @0x1660d4 mov r12, r0 */
/* @0x1660d8 ldr r0, [r4, #0x8] */
/* @0x1660dc str r12, [r4, #0x14] */
/* @0x1660e0 ldr r1, [r7, #0x14] */
/* @0x1660e4 mul r2, r3, r0 */
/* @0x1660e8 add r5, r1, r5, lsl #2 */
/* @0x1660ec lsl r3, r2, #2 */
/* @0x1660f0 str r3, [r4, #0x10] */
/* @0x1660f4 ble 0x166130 <_ZN9CBitmap32C2EPS_iiii+0x110> */
/* @0x1660f8 lsl r2, r0, #2 */
/* @0x1660fc mov r0, r12 */
/* @0x166100 mov r1, r5 */
/* @0x166104 bl 0xb65bc <memcpy@plt> */
/* @0x166108 ldr r2, [r4, #0xc] */
/* @0x16610c add r6, r6, #1 */
/* @0x166110 ldr r3, [r7, #0x8] */
/* @0x166114 cmp r2, r6 */
/* @0x166118 add r5, r5, r3, lsl #2 */
/* @0x16611c mov r12, r0 */
/* @0x166120 ldr r0, [r4, #0x8] */
/* @0x166124 lsl r2, r0, #2 */
/* @0x166128 add r12, r12, r2 */
/* @0x16612c bgt 0x1660fc <_ZN9CBitmap32C2EPS_iiii+0xdc> */
/* @0x166130 mov r0, r4 */
/* @0x166134 pop {r4, r5, r6, r7, r8, pc} */
/* @0x166138 strhteq r10, [r8], -r0 */
/* @0x16613c andseq r4, lr, r8, lsl #10 */

/* ── FUNC 0x166020 · CBitmap32::CBitmap32(CBitmap32*, int, int, int, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x166140 · CBitmap32::CBitmap32(int, int, unsigned int) · size=188 · insn=47 */
/* @0x166140 cmp r1, #1 */
/* @0x166144 movlt r1, #1 */
/* @0x166148 cmp r2, #1 */
/* @0x16614c movlt r2, #1 */
/* @0x166150 push {r4, r5, r6, lr} */
/* @0x166154 mov r4, r0 */
/* @0x166158 mul r0, r2, r1 */
/* @0x16615c ldr r12, [pc, #0x90] */
/* @0x166160 str r1, [r4, #0x8] */
/* @0x166164 mov lr, #1 */
/* @0x166168 ldr r1, [pc, #0x88] */
/* @0x16616c ldr r12, [pc, r12] */
/* @0x166170 mov r5, #0 */
/* @0x166174 str r2, [r4, #0xc] */
/* @0x166178 mov r6, r3 */
/* @0x16617c add r12, r12, #8 */
/* @0x166180 mov r3, lr */
/* @0x166184 movw r2, #0x105 */
/* @0x166188 add r1, pc, r1 */
/* @0x16618c str r12, [r4] */
/* @0x166190 lsl r0, r0, #2 */
/* @0x166194 str r5, [r4, #0x10] */
/* @0x166198 str r5, [r4, #0x14] */
/* @0x16619c strb lr, [r4, #0x4] */
/* @0x1661a0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1661a4 ldr r2, [r4, #0x8] */
/* @0x1661a8 ldr r1, [r4, #0xc] */
/* @0x1661ac orr r3, r6, #-16777216 */
/* @0x1661b0 mul r2, r1, r2 */
/* @0x1661b4 cmp r2, r5 */
/* @0x1661b8 lsl r2, r2, #2 */
/* @0x1661bc str r2, [r4, #0x10] */
/* @0x1661c0 str r0, [r4, #0x14] */
/* @0x1661c4 ble 0x1661ec <_ZN9CBitmap32C2Eiij+0xac> */
/* @0x1661c8 sub r0, r0, #4 */
/* @0x1661cc mov r2, r5 */
/* @0x1661d0 str r3, [r0, #0x4]! */
/* @0x1661d4 add r2, r2, #1 */
/* @0x1661d8 ldr r1, [r4, #0xc] */
/* @0x1661dc ldr r12, [r4, #0x8] */
/* @0x1661e0 mul r1, r12, r1 */
/* @0x1661e4 cmp r1, r2 */
/* @0x1661e8 bgt 0x1661d0 <_ZN9CBitmap32C2Eiij+0x90> */
/* @0x1661ec mov r0, r4 */
/* @0x1661f0 pop {r4, r5, r6, pc} */
/* @0x1661f4 eoreq r9, r8, r12, lsl #31 */
/* @0x1661f8 andseq r4, lr, r8, lsr r4 */

/* ── FUNC 0x166140 · CBitmap32::CBitmap32(int, int, unsigned int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x1661fc · CBitmap32::SmoothEdges() · size=264 · insn=66 */
/* @0x1661fc ldrb r3, [r0, #0x4] */
/* @0x166200 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x166204 cmp r3, #0 */
/* @0x166208 sub sp, sp, #8 */
/* @0x16620c beq 0x1662f8 <_ZN9CBitmap3211SmoothEdgesEv+0xfc> */
/* @0x166210 ldr r3, [r0, #0xc] */
/* @0x166214 cmp r3, #0 */
/* @0x166218 beq 0x1662f8 <_ZN9CBitmap3211SmoothEdgesEv+0xfc> */
/* @0x16621c ldr r2, [r0, #0x8] */
/* @0x166220 cmp r2, #0 */
/* @0x166224 beq 0x1662f8 <_ZN9CBitmap3211SmoothEdgesEv+0xfc> */
/* @0x166228 cmp r3, #0 */
/* @0x16622c ble 0x1662f8 <_ZN9CBitmap3211SmoothEdgesEv+0xfc> */
/* @0x166230 mov r8, #1 */
/* @0x166234 cmp r2, #0 */
/* @0x166238 sub r10, r8, #1 */
/* @0x16623c strle r8, [sp, #0x4] */
/* @0x166240 ble 0x1662e8 <_ZN9CBitmap3211SmoothEdgesEv+0xec> */
/* @0x166244 cmp r10, #0 */
/* @0x166248 ldr r5, [r0, #0x14] */
/* @0x16624c mov r9, #0 */
/* @0x166250 subgt r11, r8, #2 */
/* @0x166254 movle r11, #0 */
/* @0x166258 mov r7, r9 */
/* @0x16625c str r8, [sp, #0x4] */
/* @0x166260 mla r1, r2, r10, r7 */
/* @0x166264 add r4, r7, #1 */
/* @0x166268 ldr r1, [r5, r1, lsl #2] */
/* @0x16626c tst r1, #-16777216 */
/* @0x166270 bne 0x1662dc <_ZN9CBitmap3211SmoothEdgesEv+0xe0> */
/* @0x166274 cmp r7, #0 */
/* @0x166278 mov r6, r11 */
/* @0x16627c subne r7, r7, #1 */
/* @0x166280 moveq r7, #0 */
/* @0x166284 cmp r3, r8 */
/* @0x166288 suble r1, r3, #1 */
/* @0x16628c movgt r1, r8 */
/* @0x166290 cmp r6, r1 */
/* @0x166294 bgt 0x1662dc <_ZN9CBitmap3211SmoothEdgesEv+0xe0> */
/* @0x166298 mov r3, r7 */
/* @0x16629c b 0x1662b4 <_ZN9CBitmap3211SmoothEdgesEv+0xb8> */
/* @0x1662a0 ldr r1, [r5, r12, lsl #2] */
/* @0x1662a4 cmn r1, #-536870911 */
/* @0x1662a8 add r9, r1, #-536870912 */
/* @0x1662ac strhi r9, [r5, r12, lsl #2] */
/* @0x1662b0 ldrhi r2, [r0, #0x8] */
/* @0x1662b4 cmp r4, r2 */
/* @0x1662b8 sub r1, r2, #1 */
/* @0x1662bc mla r12, r2, r6, r3 */
/* @0x1662c0 movlt r1, r4 */
/* @0x1662c4 cmp r3, r1 */
/* @0x1662c8 add r3, r3, #1 */
/* @0x1662cc ble 0x1662a0 <_ZN9CBitmap3211SmoothEdgesEv+0xa4> */
/* @0x1662d0 ldr r3, [r0, #0xc] */
/* @0x1662d4 add r6, r6, #1 */
/* @0x1662d8 b 0x166284 <_ZN9CBitmap3211SmoothEdgesEv+0x88> */
/* @0x1662dc cmp r4, r2 */
/* @0x1662e0 mov r7, r4 */
/* @0x1662e4 blt 0x166260 <_ZN9CBitmap3211SmoothEdgesEv+0x64> */
/* @0x1662e8 ldr r1, [sp, #0x4] */
/* @0x1662ec add r8, r8, #1 */
/* @0x1662f0 cmp r1, r3 */
/* @0x1662f4 blt 0x166234 <_ZN9CBitmap3211SmoothEdgesEv+0x38> */
/* @0x1662f8 add sp, sp, #8 */
/* @0x1662fc pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x166300 bx lr */
