/* libyoyo.so 覆盖卡组 0000
 * 函数 0xb6fd0..0xbe6cc，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xb6fd0 · anon_b6fd0 · size=14144 · insn=3536 */
/* @0xb6fd0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xb6fd4 sub sp, sp, #8 */
/* @0xb6fd8 mov r6, r3 */
/* @0xb6fdc mov r3, #0 */
/* @0xb6fe0 ldr r4, [sp, #0x28] */
/* @0xb6fe4 mov r5, r2 */
/* @0xb6fe8 mov r7, r0 */
/* @0xb6fec and r9, r2, #2048 */
/* @0xb6ff0 mov r8, r1 */
/* @0xb6ff4 ldr r10, [r4] */
/* @0xb6ff8 cmp r10, r3 */
/* @0xb6ffc beq 0xb7014 <.text+0x44> */
/* @0xb7000 sub r10, r10, #1 */
/* @0xb7004 stm sp, {r3, r10} */
/* @0xb7008 add r3, r6, #4 */
/* @0xb700c bl 0x25fe2c <_pcre_ord2utf+0x94> */
/* @0xb7010 mov r10, r0 */
/* @0xb7014 add r6, r6, #4 */
/* @0xb7018 ldr r3, [r4] */
/* @0xb701c cmn r3, #1 */
/* @0xb7020 beq 0xb7084 <.text+0xb4> */
/* @0xb7024 mov lr, r4 */
/* @0xb7028 mov r4, lr */
/* @0xb702c add lr, lr, #4 */
/* @0xb7030 ldm r4, {r3, r12} */
/* @0xb7034 add r3, r3, #1 */
/* @0xb7038 cmp r12, r3 */
/* @0xb703c beq 0xb7028 <.text+0x58> */
/* @0xb7040 cmn r12, #1 */
/* @0xb7044 subne r12, r12, #1 */
/* @0xb7048 bne 0xb705c <.text+0x8c> */
/* @0xb704c add r12, r12, #65536 */
/* @0xb7050 cmp r9, #0 */
/* @0xb7054 movt r12, #0x10 */
/* @0xb7058 mvneq r12, #0 */
/* @0xb705c str r3, [sp] */
/* @0xb7060 mov r0, r7 */
/* @0xb7064 str r12, [sp, #0x4] */
/* @0xb7068 mov r1, r8 */
/* @0xb706c mov r2, r5 */
/* @0xb7070 mov r3, r6 */
/* @0xb7074 bl 0x25fe2c <_pcre_ord2utf+0x94> */
/* @0xb7078 add r4, r4, #4 */
/* @0xb707c add r10, r10, r0 */
/* @0xb7080 b 0xb7018 <.text+0x48> */
/* @0xb7084 mov r0, r10 */
/* @0xb7088 add sp, sp, #8 */
/* @0xb708c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xb7090 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xb7094 sub sp, sp, #8 */
/* @0xb7098 mov r7, r2 */
/* @0xb709c add r6, r3, #4 */
/* @0xb70a0 ldr r2, [sp, #0x28] */
/* @0xb70a4 mov r9, r0 */
/* @0xb70a8 mov r8, r1 */
/* @0xb70ac mov r10, #0 */
/* @0xb70b0 ldr r1, [r2] */
/* @0xb70b4 cmn r1, #1 */
/* @0xb70b8 beq 0xb7110 <.text+0x140> */
/* @0xb70bc add r12, r2, #4 */
/* @0xb70c0 add r0, r1, #1 */
/* @0xb70c4 mov lr, #0 */
/* @0xb70c8 ldr r3, [r12] */
/* @0xb70cc add r5, r0, lr */
/* @0xb70d0 mov r4, r12 */
/* @0xb70d4 add r12, r12, #4 */
/* @0xb70d8 cmp r3, r5 */
/* @0xb70dc addeq lr, lr, #1 */
/* @0xb70e0 beq 0xb70c8 <.text+0xf8> */
/* @0xb70e4 str r1, [sp] */
/* @0xb70e8 mov r0, r9 */
/* @0xb70ec ldr r12, [r2, lr, lsl #2] */
/* @0xb70f0 mov r1, r8 */
/* @0xb70f4 mov r2, r7 */
/* @0xb70f8 mov r3, r6 */
/* @0xb70fc str r12, [sp, #0x4] */
/* @0xb7100 bl 0x25fe2c <_pcre_ord2utf+0x94> */
/* @0xb7104 mov r2, r4 */
/* @0xb7108 add r10, r10, r0 */
/* @0xb710c b 0xb70b0 <.text+0xe0> */
/* @0xb7110 mov r0, r10 */
/* @0xb7114 add sp, sp, #8 */
/* @0xb7118 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xb711c ldrh r2, [r0, #4] */
/* @0xb7120 mov r3, #0 */
/* @0xb7124 str r3, [r0, #0xa0] */
/* @0xb7128 bic r2, r2, #2 */
/* @0xb712c str r3, [r0, #0x50] */
/* @0xb7130 str r3, [r0, #0x54] */
/* @0xb7134 str r3, [r0, #0x58] */
/* @0xb7138 strh r2, [r0, #4] */
/* @0xb713c str r3, [r0, #0x5c] */
/* @0xb7140 str r3, [r0, #0x60] */
/* @0xb7144 str r3, [r0, #0x64] */
/* @0xb7148 bx lr */
/* @0xb714c ldrblt r1, [r7, #0x25b]! */
/* @0xb7150 bicsmi r4, r8, #4, #12 */
/* @0xb7154 svclt #0xb84283 */
/* @0xb7158 .word 0xf8d44603 */
/* @0xb715c stcls p1, c0, [r8, #-304] */
/* @0xb7160 strle r0, [r7, #-0x780] */
/* @0xb7164 movweq pc, #0x83c3 */
/* @0xb7168 vstrle d2, [r6, #-1020] */
/* @0xb716c .word 0x73fff5c3 */
/* @0xb7170 and r3, r2, r1, lsl #6 */
/* @0xb7174 svclt #0xa82bff */
/* @0xb7178 .word 0xf8d423ff */
/* @0xb717c qdsublt r6, r8, r6 */
/* @0xb7180 andne pc, r0, sp, lsr #17 */
/* @0xb7184 .word 0xf88d4610 */
/* @0xb7188 mrshs r3, apsr */
/* @0xb718c andpl pc, r2, sp, lsr #17 */
/* @0xb7190 .word 0xf8d4466a */
/* @0xb7194 sbfxmi r3, r12, #0x2, #0x11 */
/* @0xb7198 .word 0xf8d4e021 */
/* @0xb719c blx 0xb76f6 <.text+0x726> */
/* @0xb71a0 .word 0xf8d41112 */
/* @0xb71a4 sbcslt r2, r12, #80, #2 */
/* @0xb71a8 stchs p8, c1, [r7, #-320] */
/* @0xb71ac ldm pc, {r0, r1, r4, r11, r12, lr, pc} ^ */
/* @0xb71b0 andsne pc, r6, r5 */
/* @0xb71b4 stmdaeq r10, {r1, r2, r3, r10, r11} */
/* @0xb71b8 andlo r0, r1, r6, lsl #8 */
/* @0xb71bc andvc r5, r4, r4, asr r4 */
/* @0xb71c0 andvc r3, r4, r1 */
/* @0xb71c4 andvc r3, r4, r1 */
/* @0xb71c8 andvc r3, r4, r1 */
/* @0xb71cc andvc r3, r4, r1 */
/* @0xb71d0 andvc r3, r4, r1 */
/* @0xb71d4 ldrmi lr, [r9], -r3 */
/* @0xb71d8 .word 0xf7ff462a */
/* @0xb71dc andlt lr, r3, r10, ror #19 */
/* @0xb71e0 strdeq r11, r12, [r0], -r0 */
/* @0xb71e4 movwhs r11, #0x51f */
/* @0xb71e8 movwls r9, #0x3001 */
/* @0xb71ec bl 0xfe3751f0 <b2_toiTime+0xfffffffffdc1bd4c> */
/* @0xb71f0 bls 0x1257d8 <_Z20InitGraphicFunctionsv+0x256c> */
/* @0xb71f4 .word 0xf502490a */
/* @0xb71f8 ldrbtmi r7, [r9], #-158 */
/* @0xb71fc .word 0xff3cf22e */
/* @0xb7200 .word 0xf8d29a01 */
/* @0xb7204 andls r3, r3, r0, lsr #2 */
/* @0xb7208 ldrmi r11, [r0], -r11, lsr #18 */
/* @0xb720c stc2l p2, c15, [pc, #-200] */
/* @0xb7210 movths lr, #0x1 */
/* @0xb7214 stmdals r3, {r0, r1, r8, r9, r12, pc} */
/* @0xb7218 .word 0xf85db005 */
/* @0xb721c svclt #0xfb04 */
/* @0xb7220 ldrhteq r1, [r3], -r2 */
/* @0xb7224 svcmi #0xf0e92d */
/* @0xb7228 .word 0xf8d04604 */
/* @0xb722c .word 0xf5ad9114 */
/* @0xb7230 .word 0xf8d04d81 */
/* @0xb7234 addlt r5, r5, r0, lsl r1 */
/* @0xb7238 andeq lr, r9, r5, asr #23 */
/* @0xb723c stcle p8, c2, [r8, #-512] */
/* @0xb7240 cmneq pc, r0, lsl #2 */
/* @0xb7244 strmi r1, [r8], #-457 */
/* @0xb7248 vadd.i32 d19, d1, d1 */
/* @0xb724c strmi lr, [r2], r2, ror #26 */
/* @0xb7250 .word 0xf04fe001 */
/* @0xb7254 .word 0xf10d0a80 */
/* @0xb7258 strbmi r0, [sp, #-0x810] */
/* @0xb725c addhi pc, r7, r0, lsl #5 */
/* @0xb7260 movweq lr, #0xab05 */
/* @0xb7264 strbmi r10, [r11, #-0x924] */
/* @0xb7268 strbmi r11, [r11], -r8, lsr #31 */
/* @0xb726c eoreq lr, r8, r8, lsl #17 */
/* @0xb7270 movwls r4, #0x2645 */
/* @0xb7274 ldm r5, {r0, r1, r8, r12, pc} */
/* @0xb7278 .word 0xf10d0081 */
/* @0xb727c .word 0xf8c40e90 */
/* @0xb7280 blne 0xff26f718 <b2_toiTime+0xfffffffffeb16274> */
/* @0xb7284 .word 0x463300b2 */
/* @0xb7288 ldmdbeq r2, {r0, r1, r2, r3, r9, r12, sp} */
/* @0xb728c .word 0x1102eb0e */
/* @0xb7290 smlawtne r8, r4, r8, pc */
/* @0xb7294 orrmi pc, r0, r6, lsl #2 */
/* @0xb7298 addvs pc, r0, #813694976 */
/* @0xb729c .word 0xf8c43901 */
/* @0xb72a0 andhs r2, r0, #44, #2 */
/* @0xb72a4 teqhs r0, r4, asr #17 */
/* @0xb72a8 ldrmi r0, [r6], r9, lsl #1 */
/* @0xb72ac .word 0xf8d4b133 */
/* @0xb72b0 bllo 0xff748 <_Z17F_DsMapReplaceMapR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xb72b4 and pc, r1, r2, asr #16 */
/* @0xb72b8 ldrb r3, [r7, r4, lsl #18]! */
/* @0xb72bc .word 0xf8c42301 */
/* @0xb72c0 .word 0xf8c40114 */
/* @0xb72c4 strtmi r3, [r0], -r0, lsr #2 */
/* @0xb72c8 tstvc r0, r4, asr #17 */
/* @0xb72cc .word 0xff8af7ff */
/* @0xb72d0 mrsle r2, spsr */
/* @0xb72d4 ldrsblt pc, [r0, -r4] */
/* @0xb72d8 ldrsblo pc, [r4, -r4] */
/* @0xb72dc ble 0xec8950 <b2_toiTime+0x76f4ac> */
/* @0xb72e0 ldrsblo pc, [r0, -r4] */
/* @0xb72e4 .word 0xf8d42600 */
/* @0xb72e8 bl 0xff17b710 <b2_toiTime+0xfffffffffea2226c> */
/* @0xb72ec .word 0xf8d4020b */
/* @0xb72f0 .word 0xf8533124 */
/* @0xb72f4 mvnslt r7, r2, lsr #32 */
/* @0xb72f8 ldmdavs r11!, {r1, r2, r3, r6, r8, r12, sp, pc} */
/* @0xb72fc stcle p2, c4, [r6, #-556] */
/* @0xb7300 qsaxmi r1, r0, r11 */
/* @0xb7304 ldrbmi r9, [r10], -r0, lsl #6 */
/* @0xb7308 .word 0xf7ff4633 */
/* @0xb730c ldmdavs r11!, {r0, r1, r2, r3, r4, r8, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0xb7310 strbhs lr, [r3], -r6, lsl #22 */
/* @0xb7314 bne 0xffd91608 <b2_toiTime+0xffffffffff638164> */
/* @0xb7318 ldmdavs r9!, {r1, r3, r12, lr, pc} */
/* @0xb731c .word 0x2108f8d4 */
/* @0xb7320 blle 0x207d6c <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue+0x50> */
/* @0xb7324 strtmi r2, [r0], -r1, lsl #4 */
/* @0xb7328 ldrbmi r9, [r10], -r0, lsl #4 */
/* @0xb732c .word 0xff0ef7ff */
/* @0xb7330 ldmvs pc!, {r0, r3, r4, r5, r11, sp, lr} ^ */
/* @0xb7334 ldrb r3, [lr, r1, lsl #2] */
/* @0xb7338 .word 0xf8d4b146 */
/* @0xb733c strtmi r3, [r0], -r12, lsl #2 */
/* @0xb7340 bne 0x1788cb0 <b2_toiTime+0x102f80c> */
/* @0xb7344 ldrtmi r9, [r3], -r0, lsl #6 */
/* @0xb7348 .word 0xff00f7ff */
/* @0xb734c bleq 0x133780 <_Z9F_CDTrackR6RValueP9CInstanceS2_iPS_+0x4> */
/* @0xb7350 stclo p7, c14, [r4, #-776] */
/* @0xb7354 stmdahs r0, {r0, r1, r2, sp, lr, pc} ^ */
/* @0xb7358 rsbsne sp, r6, r11, lsl #2 */
/* @0xb735c adcvs sp, pc, r9 */
/* @0xb7360 strlo r4, [r4, #-0x437] */
/* @0xb7364 strbmi r6, [r5, #-0x2f] */
/* @0xb7368 stcls p2, c13, [r2, #-532] */
/* @0xb736c andhs lr, r0, r5, ror r7 */
/* @0xb7370 andhs lr, r1, r0 */
/* @0xb7374 stcmi p5, c15, [r1, #52] */
/* @0xb7378 pop {r0, r2, r12, sp, pc} */
/* @0xb737c ldrlt r8, [r0, #-0xff0] */
/* @0xb7380 bvs 0xfe1d2994 <b2_toiTime+0xfffffffffda794f0> */
/* @0xb7384 bne 0xfe9515f4 <b2_toiTime+0xfffffffffe1f8150> */
/* @0xb7388 bhs 0xbb5d8 <_Z12GLFuncImportb+0xec8> */
/* @0xb738c .word 0x2363da01 */
/* @0xb7390 andsle lr, r12, r2, lsr #32 */
/* @0xb7394 .word 0xb141611a */
/* @0xb7398 ldmibhi r10, {r0, r1, r7, r8, r10, r11, sp, lr} */
/* @0xb739c svclt #0x4c0711 */
/* @0xb73a0 andseq pc, r0, #66 */
/* @0xb73a4 eoreq pc, r0, #66 */
/* @0xb73a8 bvs 0xfe197a18 <b2_toiTime+0xfffffffffda3e574> */
/* @0xb73ac .word 0xf1036d81 */
/* @0xb73b0 addvs r0, r2, #32, #4 */
/* @0xb73b4 andhs r6, r0, #549453824 */
/* @0xb73b8 stcvs p1, c6, [r3, #104] */
/* @0xb73bc addsvs r6, r10, r2, lsl #21 */
/* @0xb73c0 bicvs r6, r11, r3, lsl #27 */
/* @0xb73c4 ldrhlo pc, [r4], #-128 */
/* @0xb73c8 .word 0xf8a03301 */
/* @0xb73cc bvs 0xfe143524 <b2_toiTime+0xfffffffffd9ea080> */
/* @0xb73d0 addsmi r6, r10, #274432 */
/* @0xb73d4 .word 0x2362d303 */
/* @0xb73d8 andhs r6, r1, r3, asr #5 */
/* @0xb73dc movwhs r11, #0xd10 */
/* @0xb73e0 subslo pc, r7, r0, lsl #17 */
/* @0xb73e4 ldclt p6, c4, [r0, #-96] */
/* @0xb73e8 blvs 0x1e48b0 <_ZN7CSprite16PreciseCollisionEiP9tagYYRECTiifffPS_iS1_iifff+0x618> */
/* @0xb73ec vmulne.f32 s13, s6, s4 */
/* @0xb73f0 blne 0x537688 <obj_numb_event+0x718> */
/* @0xb73f4 blhs 0xc844c <_Z23F_Vertex_Normal_releaseR6RValueP9CInstanceS2_iPS_+0xc> */
/* @0xb73f8 .word 0xf854db19 */
/* @0xb73fc adcmi r5, r9, #4, #26 */
/* @0xb7400 bllo 0x12dc0c <_Z17F_PathDeletePointR6RValueP9CInstanceS2_iPS_+0x8> */
/* @0xb7404 stcle p7, c14, [r8, #-988] */
/* @0xb7408 blvs 0x1af434 <_ZN5CRoom9SortTilesEv+0x40> */
/* @0xb740c movwlo r6, #0x1a02 */
/* @0xb7410 .word 0xf06f6303 */
/* @0xb7414 movtmi r0, #0x3003 */
/* @0xb7418 ldrdhs r5, r6, [r0], -r1 */
/* @0xb741c bl 0x1668e4 <_ZN9CBitmap32C2Eiijji+0x17c> */
/* @0xb7420 bllo 0xf7e34 <_ZN7CFontGM6AssignEPS_+0x38> */
/* @0xb7424 ldmdavs r1, {r2, r3, r9, r10, lr} */
/* @0xb7428 stmdbmi r4, {r1, r6, r11, r12, sp, lr, pc} */
/* @0xb742c bvs 0x11acc18 <b2_toiTime+0xa53774> */
/* @0xb7430 bllo 0x1d1e40 <_Z22HandleInstanceMovementb+0x154> */
/* @0xb7434 addsmi r6, r3, #805306372 */
/* @0xb7438 .word 0x2362d8e7 */
/* @0xb743c andhs r6, r1, r3, asr #5 */
/* @0xb7440 push {r4, r5, r8, r10, r11, r12, sp, pc} */
/* @0xb7444 .word 0x46044ff0 */
/* @0xb7448 ldrsbtls pc, [r4], -r0 */
/* @0xb744c stmeq r1, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^ */
/* @0xb7450 ldrmi r11, [lr], -r5, lsl #1 */
/* @0xb7454 movweq lr, #0x8b09 */
/* @0xb7458 .word 0xf8d96aa5 */
/* @0xb745c andls r0, r3, #4 */
/* @0xb7460 bls 0x447f28 <g_RomDisk+0x50708> */
/* @0xb7464 vmov.i16 q11, #0xb */
/* @0xb7468 addsmi r8, r3, #129 */
/* @0xb746c stmdavs r7!, {r1, r2, r3, r4, r5, r6, r10, r11, r12, lr, pc} ^ */
/* @0xb7470 .word 0x0c00f1c7 */
/* @0xb7474 beq 0xf1cac <_ZN18DIALOG_REQ_CONTEXTD2Ev+0x4> */
/* @0xb7478 svclt #0xb84552 */
/* @0xb747c adcsmi r4, r3, #153092096 */
/* @0xb7480 ldmibne r8, {r0, r2, r4, r8, r9, r11, r12, lr, pc} ^ */
/* @0xb7484 eorsmi r3, r11, r1, lsl #30 */
/* @0xb7488 b 0xc5494 <_Z13F_BUFFER_ReadR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0xb748c andslt r0, r11, #12 */
/* @0xb7490 .word 0xf894b97b */
/* @0xb7494 tstlt r2, r7, asr r0 */
/* @0xb7498 .word 0xf8843d04 */
/* @0xb749c .word 0xf8593057 */
/* @0xb74a0 strlo r3, [r4, #-0x31] */
/* @0xb74a4 .word 0x3c04f845 */
/* @0xb74a8 strmi r6, [r6], #-2150 */
/* @0xb74ac ldrtmi lr, [r0], -r2 */
/* @0xb74b0 strmi lr, [r6], -r0 */
/* @0xb74b4 .word 0x3056f894 */
/* @0xb74b8 stcvs p1, c11, [r3, #236]! */
/* @0xb74bc blx 0x10d154c <b2_toiTime+0x9780a8> */
/* @0xb74c0 cmpvs r10, r2, lsl #4 */
/* @0xb74c4 .word 0xf8842300 */
/* @0xb74c8 ldrmi r3, [r2, #0x56]! */
/* @0xb74cc stmdavs r3!, {r1, r2, r3, r6, r8, r9, r11, r12, lr, pc} */
/* @0xb74d0 andeq lr, r10, #202752 */
/* @0xb74d4 bvs 0x1987944 <b2_toiTime+0x122e4a0> */
/* @0xb74d8 bl 0x203ce4 <_ZN7CDS_Map8FindLastEv+0x20> */
/* @0xb74dc addsmi r0, r3, #536870920 */
/* @0xb74e0 .word 0x2362d804 */
/* @0xb74e4 rscvs r6, r3, #1342177290 */
/* @0xb74e8 sub r2, r5, r1 */
/* @0xb74ec .word 0xf04f464f */
/* @0xb74f0 .word 0xf04f0b01 */
/* @0xb74f4 .word 0xf8840300 */
/* @0xb74f8 ldmdavs r9!, {r0, r1, r2, r4, r6, r12, sp} ^ */
/* @0xb74fc stcle p2, c4, [r6, #-708]! */
/* @0xb7500 andeq lr, r8, #7168 */
/* @0xb7504 .word 0xf8d26923 */
/* @0xb7508 bl 0xff46f520 <b2_toiTime+0xfffffffffed1607c> */
/* @0xb750c addsmi r0, r9, #1073741824 */
/* @0xb7510 ldrtmi sp, [r8], -r6, lsl #22 */
/* @0xb7514 blls 0x19bd20 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1428> */
/* @0xb7518 bls 0x109380 <_Z15F_CollisionLineR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0xb751c eor r4, r1, r7, lsl r6 */
/* @0xb7520 andlo pc, r8, r7, asr r8 */
/* @0xb7524 vmlseq.f64 d14, d22, d14 */
/* @0xb7528 stcne p8, c6, [r10, #-224]! */
/* @0xb752c bl 0xff2dbd38 <b2_toiTime+0xfffffffffeb82894> */
/* @0xb7530 bne 0xff0b9154 <b2_toiTime+0xfffffffffe95fcb0> */
/* @0xb7534 blx 0x45c146 <g_RomDisk+0x64926> */
/* @0xb7538 vhadd.s32 d31, d1, d0 */
/* @0xb753c blls 0x1724ec <_Z7SetFontv+0x8> */
/* @0xb7540 eorvs r4, r8, r8, lsl r4 */
/* @0xb7544 stmdavs r3!, {r0, r9, r11, r12, pc} ^ */
/* @0xb7548 ldrmi r4, [lr], #-1557 */
/* @0xb754c mrsle lr, apsr */
/* @0xb7550 subslt pc, r7, r4, lsl #17 */
/* @0xb7554 ldmdavs r11!, {r2, r8, r10, r12, sp} */
/* @0xb7558 .word 0x3c04f845 */
/* @0xb755c ldrmi r6, [lr], #-2147 */
/* @0xb7560 streq lr, [r7, -r8, asr #23] */
/* @0xb7564 movwle r4, #0x154f */
/* @0xb7568 stclle p5, c4, [r2, #344] */
/* @0xb756c andhs r6, r0, r3, ror #22 */
/* @0xb7570 bl 0xff2d000c <b2_toiTime+0xfffffffffeb76b68> */
/* @0xb7574 .word 0x63630303 */
/* @0xb7578 pop {r0, r2, r12, sp, pc} */
/* @0xb757c ldrblt r8, [r3, #-0xff0]! */
/* @0xb7580 blvs 0x11c8d9c <b2_toiTime+0xa6f8f8> */
/* @0xb7584 stmdavs r0!, {r1, r8, r11, sp} ^ */
/* @0xb7588 andeq pc, r0, r0, asr #3 */
/* @0xb758c stmvs r0!, {r5, r6, sp, lr} ^ */
/* @0xb7590 andeq pc, r0, r0, asr #3 */
/* @0xb7594 stmdbvs r0!, {r5, r6, r7, sp, lr} ^ */
/* @0xb7598 andeq pc, r0, r0, asr #3 */
/* @0xb759c stcle p1, c6, [r2, #-384] */
/* @0xb75a0 submi r6, r0, #224, #18 */
/* @0xb75a4 subsmi r6, r11, #224, #2 */
/* @0xb75a8 blls 0x25c1b0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1088> */
/* @0xb75ac .word 0xf8954628 */
/* @0xb75b0 subsmi r6, r11, #86 */
/* @0xb75b4 .word 0xff45f7ff */
/* @0xb75b8 .word 0xf895b136 */
/* @0xb75bc ldmdblt r11, {r1, r2, r4, r6, r12, sp} */
/* @0xb75c0 ldmdbvs r10, {r0, r1, r3, r5, r7, r8, r10, r11, sp, lr} ^ */
/* @0xb75c4 cmpvs r10, r2, asr r2 */
/* @0xb75c8 subsmi r6, r11, #6488064 */
/* @0xb75cc andlt r6, r2, r3, rrx */
/* @0xb75d0 ldrlt r11, [r0, #-0xd70] */
/* @0xb75d4 stmdavs r3, {r2, r3, r11, sp, lr} */
/* @0xb75d8 ldmdavs r10, {r0, r1, r3, r5, r8, r12, sp, pc} */
/* @0xb75dc blle 0x148034 <_Z20F_GPUGetBlendModeExtR6RValueP9CInstanceS2_iPS_+0x14> */
/* @0xb75e0 ldmdavs r11, {r3, r4, r8, r10, r11, r12} ^ */
/* @0xb75e4 strdvs lr, pc, [r11], #-120 */
/* @0xb75e8 ldclt p0, c6, [r0, #-4] */
/* @0xb75ec teqlt r11, r3, lsl #16 */
/* @0xb75f0 smlabble r2, r11, r2, r4 */
/* @0xb75f4 andvs r6, r3, r11, asr r8 */
/* @0xb75f8 ldcne p7, c4, [r8, #-448] */
/* @0xb75fc ubfx r6, r11, #0x10, #0x17 */
/* @0xb7600 stmdavs r3, {r4, r5, r6, r8, r9, r10, lr} */
/* @0xb7604 orrlt r11, r3, r0, lsr r5 */
/* @0xb7608 ldmdavs r1, {r1, r3, r4, r7, r11, sp, lr} */
/* @0xb760c ldmibhi r9, {r0, r3, r4, sp, lr} */
/* @0xb7610 svceq #0x8f011 */
/* @0xb7614 .word 0xf06fbf0c */
/* @0xb7618 .word 0x21040103 */
/* @0xb761c addsvs r4, r10, r10, lsl #8 */
/* @0xb7620 blo 0x111a90 <_Z16F_PointDirectionR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0xb7624 ldmdavs r11, {r1, r3, r4, r8, sp, lr} ^ */
/* @0xb7628 stmdavs r3, {r0, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0xb762c ldmdavs r10, {r0, r1, r4, r7, r8, r12, sp, pc} ^ */
/* @0xb7630 cmnlt r10, r1, lsl #12 */
/* @0xb7634 ldmdavs r4, {r0, r2, r3, r4, r11, sp, lr} */
/* @0xb7638 .word 0xdc0342a5 */
/* @0xb763c ldmdavs r11, {r0, r3, r4, r8, r10, r11, r12} ^ */
/* @0xb7640 ldclt p9, c11, [r0, #-204]! */
/* @0xb7644 ldmdavs r1, {r1, r3, sp, lr} ^ */
/* @0xb7648 .word 0x46016059 */
/* @0xb764c stmdavs r3, {r0, r1, r4, r6, sp, lr} */
/* @0xb7650 ubfx r6, r10, #0x10, #0xf */
/* @0xb7654 push {r4, r5, r8, r10, r11, r12, sp, pc} */
/* @0xb7658 .word 0x460447f0 */
/* @0xb765c .word 0x9020f8dd */
/* @0xb7660 .word 0xf8dd460d */
/* @0xb7664 bl 0xff1576fc <b2_toiTime+0xfffffffffe9fe258> */
/* @0xb7668 .word 0xf8dd0609 */
/* @0xb766c cdphs p0, #0x0, c10, c0, c8, #0x1 */
/* @0xb7670 addhi pc, r12, r0, asr #6 */
/* @0xb7674 .word 0xf2c045c1 */
/* @0xb7678 ldrbmi r8, [r2, #-0x89] */
/* @0xb767c addhi pc, r6, r0, lsl #6 */
/* @0xb7680 bl 0xff108b90 <b2_toiTime+0xfffffffffe9af6ec> */
/* @0xb7684 ble 0x379298 <_ZTS13C_UTF16String+0x10344> */
/* @0xb7688 smlabteq r8, r2, r11, lr */
/* @0xb768c shasxmi r4, r2, r8 */
/* @0xb7690 blx 0x15f3f4e <b2_toiTime+0xe9aaaa> */
/* @0xb7694 andhs r6, r0, #2293760 */
/* @0xb7698 .word 0xf803fa48 */
/* @0xb769c and r4, r5, r5, lsl #8 */
/* @0xb76a0 blx 0x11516b4 <b2_toiTime+0x9f8210> */
/* @0xb76a4 stmdavs r3, {r0, r1, r11, r12, sp, lr, pc} ^ */
/* @0xb76a8 andsmi r3, r10, r1, lsl #22 */
/* @0xb76ac stmdavs r3!, {r0, r4, r6, r7, r8, r10, lr} */
/* @0xb76b0 blx 0x136eac8 <b2_toiTime+0xc15624> */
/* @0xb76b4 .word 0xf04ffa03 */
/* @0xb76b8 and r0, r5, r0, lsl #18 */
/* @0xb76bc blx 0x1b5fe8 <_ZN10ObjectPoolI23CLayerBackgroundElementED2Ev+0xa4> */
/* @0xb76c0 bllo 0x111854 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1b0> */
/* @0xb76c4 stmdbeq r3, {r0, r3, r9, r11, sp, lr, pc} */
/* @0xb76c8 vstrle s4, [r11, #-0] */
/* @0xb76cc ldrsble r4, [sp], #-80 */
/* @0xb76d0 ldrtmi r6, [r8], -r1, ror #16 */
/* @0xb76d4 stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0xb76d8 ldrtmi r1, [r2], -r9, lsl #21 */
/* @0xb76dc blx 0xc73f9a <b2_toiTime+0x51aaf6> */
/* @0xb76e0 and r4, r5, r5, lsl #8 */
/* @0xb76e4 .word 0x3057f894 */
/* @0xb76e8 bvs 0xfe9a3b3c <b2_toiTime+0xfffffffffe24a698> */
/* @0xb76ec adcvs r3, r3, #4, #22 */
/* @0xb76f0 stmdbeq r1, {r0, r3, r4, r6, r7, r8, r12, sp, lr, pc} */
/* @0xb76f4 .word 0x3056f894 */
/* @0xb76f8 .word 0xf04fbf38 */
/* @0xb76fc .word 0xf8840900 */
/* @0xb7700 qsublt r9, r7, r11 */
/* @0xb7704 .word 0xf8c36da3 */
/* @0xb7708 movwhs r8, #0x14 */
/* @0xb770c subslo pc, r6, r4, lsl #17 */
/* @0xb7710 stmdaeq r10, {r3, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0xb7714 .word 0xf1086aa3 */
/* @0xb7718 bl 0x179724 <_Z15GR_3D_Draw_Wallffffffiff+0x44> */
/* @0xb771c bvs 0x1978144 <b2_toiTime+0x121eca0> */
/* @0xb7720 stmdale r4, {r0, r1, r4, r7, r9, lr} */
/* @0xb7724 andhs r2, r1, r2, ror #6 */
/* @0xb7728 pop {r0, r1, r5, r6, r7, r9, sp, lr} */
/* @0xb772c svchs #0x87f0 */
/* @0xb7730 ldrtmi sp, [r9], -r12, lsl #26 */
/* @0xb7734 stmdavs r0!, {r1, r4, r5, r9, r10, lr} ^ */
/* @0xb7738 blx 0x16f3ff6 <b2_toiTime+0xf9ab52> */
/* @0xb773c .word 0x46814631 */
/* @0xb7740 cmnmi r8, #96, #16 */
/* @0xb7744 bl 0x15740d0 <b2_toiTime+0xe1ac2c> */
/* @0xb7748 and r2, lr, r1 */
/* @0xb774c shsub16mi r4, r2, pc */
/* @0xb7750 ldrtmi r6, [r9], -r0, ror #16 */
/* @0xb7754 blx 0x1374012 <b2_toiTime+0xc1ab6e> */
/* @0xb7758 .word 0xf1c04631 */
/* @0xb775c stmdavs r0!, {r8, r11} ^ */
/* @0xb7760 .word 0xf2614378 */
/* @0xb7764 .word 0xf04feb44 */
/* @0xb7768 bvs 0xfe943b6c <b2_toiTime+0xfffffffffe1ea6c8> */
/* @0xb776c .word 0xf1b84273 */
/* @0xb7770 stcle p15, c0, [r10, #-0] */
/* @0xb7774 .word 0xf842185b */
/* @0xb7778 strbmi r5, [sp], #-2820 */
/* @0xb777c bl 0xff2674f4 <b2_toiTime+0xfffffffffeb0e050> */
/* @0xb7780 stmdane sp!, {r0, r1, r8, r9} */
/* @0xb7784 ldmlo pc!, {r3, r8, r12, sp, lr, pc} ^ */
/* @0xb7788 adcvs lr, r2, #63176704 */
/* @0xb778c ldm sp!, {sp} */
/* @0xb7790 ldrlt r8, [r0, #-0x7f0]! */
/* @0xb7794 stmdblt r3!, {r0, r1, r6, r7, r8, r10, r11, sp, lr} */
/* @0xb7798 strvs r6, [r3, #0xa83] */
/* @0xb779c .word 0x332065c3 */
/* @0xb77a0 bvs 0xfe1d01b4 <b2_toiTime+0xfffffffffda76d10> */
/* @0xb77a4 addsmi r6, r12, #274432 */
/* @0xb77a8 .word 0x2362d301 */
/* @0xb77ac stcvs p0, c14, [r4, #164] */
/* @0xb77b0 stmdbhs r1, {r8, r9, sp} */
/* @0xb77b4 stcvs p1, c8, [r4, #652] */
/* @0xb77b8 stcvs p1, c6, [r4, #396] */
/* @0xb77bc stcvs p1, c6, [r4, #140] */
/* @0xb77c0 adcvs r6, r5, r5, lsl #21 */
/* @0xb77c4 rsbvs r6, r3, r4, lsl #27 */
/* @0xb77c8 mvnvs r6, r4, lsl #27 */
/* @0xb77cc .word 0xf8906d83 */
/* @0xb77d0 ldrhhi r4, [r12, r0] */
/* @0xb77d4 stmdbhs r2, {r1, r12, lr, pc} */
/* @0xb77d8 ands sp, r1, r11 */
/* @0xb77dc ldmibhi r12, {r0, r1, r7, r8, r10, r11, sp, lr} */
/* @0xb77e0 streq pc, [r8], #-68 */
/* @0xb77e4 .word 0xb17a819c */
/* @0xb77e8 ldmibhi r10, {r0, r1, r7, r8, r10, r11, sp, lr} */
/* @0xb77ec eoreq pc, r0, #66 */
/* @0xb77f0 mrslt lr, spsr */
/* @0xb77f4 ldmibhi r10, {r0, r1, r7, r8, r10, r11, sp, lr} */
/* @0xb77f8 andseq pc, r0, #66 */
/* @0xb77fc mul r3, r10, r1 */
/* @0xb7800 sbcvs r2, r3, #20, #6 */
/* @0xb7804 ldclt p0, c2, [r0, #-4]! */
/* @0xb7808 stmdblt r11, {r0, r1, r9, r10, r11, sp, lr} */
/* @0xb780c strvs r6, [r3], -r3, lsl #27 */
/* @0xb7810 .word 0xf8802301 */
/* @0xb7814 movwhs r3, #0x56 */
/* @0xb7818 .word 0xf8806641 */
/* @0xb781c ssaxmi r3, r8, r7 */
/* @0xb7820 andeq r11, r0, r0, lsr sp */
/* @0xb7824 svcmi #0xf7e92d */
/* @0xb7828 .word 0xf1004604 */
/* @0xb782c movtvs r0, #0x66b4 */
/* @0xb7830 .word 0xf8df6c40 */
/* @0xb7834 .word 0xf8df80f4 */
/* @0xb7838 .word 0xf8c490f4 */
/* @0xb783c ldrbtmi r0, [r8], #196 */
/* @0xb7840 ldrbtmi r6, [r9], #3232 */
/* @0xb7844 adcslo pc, r4, r4, asr #17 */
/* @0xb7848 .word 0xf8c49b0c */
/* @0xb784c .word 0xf8c400c8 */
/* @0xb7850 .word 0xf8c410bc */
/* @0xb7854 .word 0xf8c420c0 */
/* @0xb7858 blvs 0x18c3b40 <b2_toiTime+0x116a69c> */
/* @0xb785c stmdavs r5, {r0, r1, r6, r8, r11, sp, lr} ^ */
/* @0xb7860 adcmi r6, r11, #12648448 */
/* @0xb7864 svclt #0xd96807 */
/* @0xb7868 ldrmi r4, [r12], r10, lsr #12 */
/* @0xb786c ssatmi r4, #0xd, r10, lsl #12 */
/* @0xb7870 blle 0x108dfc <_Z15F_MpGridGetCellR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0xb7874 stcle p2, c4, [r5, #-580] */
/* @0xb7878 ldc2 p2, c15, [lr, #232]! */
/* @0xb787c tstlo r0, #101376 */
/* @0xb7880 sub r6, r8, r3, ror #6 */
/* @0xb7884 smlatble r2, r11, r2, r4 */
/* @0xb7888 .word 0x63603810 */
/* @0xb788c cdpvs p0, #0x6, c14, c1, c3, #0x2 */
/* @0xb7890 .word 0xf04fbfb4 */
/* @0xb7894 .word 0xf04f0a01 */
/* @0xb7898 ldrbmi r0, [r1, #-0xa02] */
/* @0xb789c .word 0xf1bad10b */
/* @0xb78a0 stcvs p15, c0, [r3, #-4]! */
/* @0xb78a4 movwls sp, #0x12e */
/* @0xb78a8 .word 0x21024620 */
/* @0xb78ac stclvs p6, c4, [r3], #296 */
/* @0xb78b0 stc2l p7, c15, [r7, #1020] */
/* @0xb78b4 .word 0xf1bae02d */
/* @0xb78b8 stmdavs r2!, {r0, r8, r9, r10, r11} ^ */
/* @0xb78bc smlatble r8, r0, r8, r6 */
/* @0xb78c0 bleq 0x1724d4 <_Z15MakeDefaultFontv+0x6c> */
/* @0xb78c4 .word 0xf10b4252 */
/* @0xb78c8 b 0x3868cc <_ZTS13C_UTF16String+0x1d978> */
/* @0xb78cc bne 0xff5780dc <b2_toiTime+0xfffffffffee1ec38> */
/* @0xb78d0 blo 0x12f8dc <_Z13F_SoundDeleteR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xb78d4 addmi r4, r3, #19 */
/* @0xb78d8 .word 0xf04fbfb4 */
/* @0xb78dc .word 0xf04f0b00 */
/* @0xb78e0 ldmdblt r9!, {r0, r8, r9, r11} */
/* @0xb78e4 ldrbmi r4, [r1], -r0, lsr #12 */
/* @0xb78e8 .word 0xf7ff465a */
/* @0xb78ec stmdahs r0, {r1, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0xb78f0 ldrd sp, lr, [r5], -r5 */
/* @0xb78f4 ldrbmi r4, [r9], -r0, lsr #12 */
/* @0xb78f8 stc2l p7, c15, [r1, #-1020] */
/* @0xb78fc rscsle r2, r1, r0, lsl #16 */
/* @0xb7900 and r2, lr, r1 */
/* @0xb7904 strtmi r9, [r0], -r0, lsl #6 */
/* @0xb7908 strbmi r2, [r2], -r2, lsl #2 */
/* @0xb790c .word 0xf7ff6ce3 */
/* @0xb7910 stmdahs r0, {r1, r2, r4, r5, r9, r10, r11, r12, sp, lr, pc} */
/* @0xb7914 blvs 0x19ac0ec <b2_toiTime+0x1252c48> */
/* @0xb7918 addsle r4, lr, #805306379 */
/* @0xb791c strbtvs r2, [r7], #-0 */
/* @0xb7920 andlt r6, r3, r5, lsr #9 */
/* @0xb7924 svchi #0xf0e8bd */
/* @0xb7928 .word 0x0023abb7 */
/* @0xb792c .word 0x0023abb3 */
/* @0xb7930 svcmi #0xf7e92d */
/* @0xb7934 .word 0xf1004604 */
/* @0xb7938 movtvs r0, #0x66b4 */
/* @0xb793c .word 0xf8c46c40 */
/* @0xb7940 blls 0x3c3c38 <error_g0017+0x1c8dc> */
/* @0xb7944 .word 0x8104f8df */
/* @0xb7948 .word 0x9104f8df */
/* @0xb794c sbclo pc, r0, r4, asr #17 */
/* @0xb7950 blls 0x408d38 <g_RomDisk+0x11518> */
/* @0xb7954 .word 0xf8c444f9 */
/* @0xb7958 stcvs p0, c0, [r0], #816 */
/* @0xb795c adcslo pc, r4, r4, asr #17 */
/* @0xb7960 .word 0xf8c49b0e */
/* @0xb7964 .word 0xf8c400d0 */
/* @0xb7968 .word 0xf8c410c4 */
/* @0xb796c .word 0xf8c420c8 */
/* @0xb7970 blvs 0x18c3c58 <b2_toiTime+0x116a7b4> */
/* @0xb7974 stmdavs r5, {r0, r1, r6, r7, r8, r11, sp, lr} ^ */
/* @0xb7978 adcmi r6, r11, #1081344 */
/* @0xb797c stmdavs r7, {r0, r6, r7, r11, sp, lr} */
/* @0xb7980 ssatmi r11, #0xd, r9, asr #31 */
/* @0xb7984 .word 0x469c469a */
/* @0xb7988 addmi r4, r10, #178257920 */
/* @0xb798c strmi sp, [r11], r2, lsl #24 */
/* @0xb7990 uadd16mi r4, r10, r1 */
/* @0xb7994 blle 0x108ee0 <_Z20F_MpGridAddInstancesR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0xb7998 stcle p5, c4, [r5, #-392] */
/* @0xb799c ldc2l p2, c15, [r3, #-232] */
/* @0xb79a0 tstlo r8, #101376 */
/* @0xb79a4 sub r6, r8, r3, ror #6 */
/* @0xb79a8 smlatble r2, r11, r2, r4 */
/* @0xb79ac .word 0x63603818 */
/* @0xb79b0 cdpvs p0, #0x6, c14, c1, c3, #0x2 */
/* @0xb79b4 .word 0xf04fbfd4 */
/* @0xb79b8 .word 0xf04f0a01 */
/* @0xb79bc ldrbmi r0, [r1, #-0xa02] */
/* @0xb79c0 .word 0xf1bad10b */
/* @0xb79c4 stcvs p15, c0, [r3, #-4]! */
/* @0xb79c8 movwls sp, #0x12e */
/* @0xb79cc .word 0x21034620 */
/* @0xb79d0 stclvs p6, c4, [r3], #296 */
/* @0xb79d4 ldc2 p7, c15, [r5, #-1020]! */
/* @0xb79d8 .word 0xf1bae02d */
/* @0xb79dc stmdavs r2!, {r0, r8, r9, r10, r11} ^ */
/* @0xb79e0 smlatble r8, r0, r8, r6 */
/* @0xb79e4 bleq 0x1725f8 <_Z15Split_TextBlockPKciP11TStringList+0x98> */
/* @0xb79e8 .word 0xf10b4252 */
/* @0xb79ec b 0x3869f0 <_ZTS13C_UTF16String+0x1da9c> */
/* @0xb79f0 bne 0xff578200 <b2_toiTime+0xfffffffffee1ed5c> */
/* @0xb79f4 blo 0x12fa00 <_Z25F_BackgroundPrefetchMultiR6RValueP9CInstanceS2_iPS_+0x8> */
/* @0xb79f8 addmi r4, r3, #19 */
/* @0xb79fc .word 0xf04fbfb4 */
/* @0xb7a00 .word 0xf04f0b00 */
/* @0xb7a04 ldmdblt r9!, {r0, r8, r9, r11} */
/* @0xb7a08 ldrbmi r4, [r1], -r0, lsr #12 */
/* @0xb7a0c .word 0xf7ff465a */
/* @0xb7a10 stmdahs r0, {r6, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0xb7a14 ldrd sp, lr, [r5], -r5 */
/* @0xb7a18 ldrbmi r4, [r9], -r0, lsr #12 */
/* @0xb7a1c stc2 p7, c15, [pc], #1020 */
/* @0xb7a20 rscsle r2, r1, r0, lsl #16 */
/* @0xb7a24 and r2, lr, r1 */
/* @0xb7a28 strtmi r9, [r0], -r0, lsl #6 */
/* @0xb7a2c strbmi r2, [r2], -r3, lsl #2 */
/* @0xb7a30 .word 0xf7ff6ce3 */
/* @0xb7a34 stmdahs r0, {r2, r5, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0xb7a38 blvs 0x19ac210 <b2_toiTime+0x1252d6c> */
/* @0xb7a3c addsle r4, r8, #805306379 */
/* @0xb7a40 strbtvs r2, [r7], #-0 */
/* @0xb7a44 andlt r6, r3, r5, lsr #9 */
/* @0xb7a48 svchi #0xf0e8bd */
/* @0xb7a4c .word 0x0023aaf3 */
/* @0xb7a50 eoreq r10, r3, pc, ror #21 */
/* @0xb7a54 .word 0x4604b5f0 */
/* @0xb7a58 addlt r6, r5, r3, asr #28 */
/* @0xb7a5c ldrmi r4, [r5], -lr, lsl #12 */
/* @0xb7a60 andsle r2, pc, r1, lsl #22 */
/* @0xb7a64 blhs 0x16c674 <_ZN8yyMatrix6InvertEv+0x18> */
/* @0xb7a68 sub sp, pc, r4, lsr r0 */
/* @0xb7a6c addsmi r6, r5, #33280 */
/* @0xb7a70 stmdavs r3, {r1, r4, r8, r10, r11, r12, lr, pc} ^ */
/* @0xb7a74 ldmne r1, {r0, r1, r2, r7, r11, sp, lr} ^ */
/* @0xb7a78 stmdblo r1, {r0, r1, r3, r4, r6, r9, lr} */
/* @0xb7a7c bne 0xfe747ab0 <b2_toiTime+0xfffffffffdfee60c> */
/* @0xb7a80 .word 0xf04f42ba */
/* @0xb7a84 svclt #0xb40101 */
/* @0xb7a88 andhs r2, r1, #0, #4 */
/* @0xb7a8c mcr2 p7, #0x4, pc, c1, c15, #0x7 */
/* @0xb7a90 eorsle r2, r11, r0, lsl #16 */
/* @0xb7a94 rsb r2, r9, r1 */
/* @0xb7a98 stmdavs r3, {r3, r4, r5, r9, r11, r12, lr, pc} ^ */
/* @0xb7a9c andsmi r3, r10, r1, lsl #22 */
/* @0xb7aa0 ands r6, r4, r3, lsl #17 */
/* @0xb7aa4 addsmi r6, r10, #33536 */
/* @0xb7aa8 stmdavs r2, {r4, r5, r9, r11, r12, lr, pc} ^ */
/* @0xb7aac blo 0x111cb8 <_Z17InitMathFunctionsv+0x5c> */
/* @0xb7ab0 addmi r4, r11, #19 */
/* @0xb7ab4 strhhs r11, [r0, -r4] */
/* @0xb7ab8 .word 0xf7ff2101 */
/* @0xb7abc stmdahs r0, {r5, r6, r10, r11, r12, sp, lr, pc} */
/* @0xb7ac0 stmdavs r3!, {r3, r5, r6, r7, r8, r12, lr, pc} ^ */
/* @0xb7ac4 cdpne p6, #0x5, c4, c10, c0, #0x1 */
/* @0xb7ac8 andsmi r6, r10, r3, lsr #25 */
/* @0xb7acc smlatbhs r2, r3, r8, r6 */
/* @0xb7ad0 bfi r4, r10, #5, #20 */
/* @0xb7ad4 addsmi r6, r10, #33536 */
/* @0xb7ad8 stmdavs r2, {r3, r4, r8, r10, r11, r12, lr, pc} ^ */
/* @0xb7adc subsmi r1, r2, #10027008 */
/* @0xb7ae0 andmi r3, r10, r1, lsl #18 */
/* @0xb7ae4 bne 0xff591cf0 <b2_toiTime+0xfffffffffee3884c> */
/* @0xb7ae8 svclt #0xb4428b */
/* @0xb7aec mrshs r2, apsr */
/* @0xb7af0 mcrr2 p7, #0xf, pc, r5, c15 */
/* @0xb7af4 bicle r2, sp, r0, lsl #16 */
/* @0xb7af8 strtmi r6, [r0], -r3, lsr #25 */
/* @0xb7afc stmvs r7!, {r1, r5, r6, r11, sp, lr} */
/* @0xb7b00 subsmi r1, r2, #10027008 */
/* @0xb7b04 andmi r3, r10, r1, lsl #18 */
/* @0xb7b08 sbfx r1, r2, #0x15, #0x1a */
/* @0xb7b0c blhs 0x1134a0 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2c8> */
/* @0xb7b10 blhs 0x16bb20 <_Z20GR_Draw_Vertex_Colorffjf+0x40> */
/* @0xb7b14 eor sp, r6, r12 */
/* @0xb7b18 strtmi r6, [r0], -r3, ror #25 */
/* @0xb7b1c stclvs p5, c9, [r1], #-0 */
/* @0xb7b20 stcvs p3, c9, [r3, #-4]! */
/* @0xb7b24 movwls r6, #0x2ca2 */
/* @0xb7b28 .word 0xf7ff4633 */
/* @0xb7b2c muls r8, r4, sp */
/* @0xb7b30 movwls r4, #0x26b */
/* @0xb7b34 strtmi r6, [r0], -r3, lsr #26 */
/* @0xb7b38 subsmi r6, r11, #41472 */
/* @0xb7b3c stclvs p3, c9, [r3], #4 */
/* @0xb7b40 .word 0xf8944252 */
/* @0xb7b44 subsmi r7, r11, #86 */
/* @0xb7b48 movwls r6, #0x2c61 */
/* @0xb7b4c .word 0xf7ff4633 */
/* @0xb7b50 teqlt r7, r2, lsl #27 */
/* @0xb7b54 .word 0x3056f894 */
/* @0xb7b58 stcvs p9, c11, [r3, #108]! */
/* @0xb7b5c subsmi r6, r2, #1474560 */
/* @0xb7b60 stmdahs r0, {r1, r3, r4, r6, r8, sp, lr} */
/* @0xb7b64 mulhs r0, r6, r1 */
/* @0xb7b68 strtvs r6, [r5], #1126 */
/* @0xb7b6c ldcllt p0, c11, [r0, #20]! */
/* @0xb7b70 svcmi #0xf0e92d */
/* @0xb7b74 .word 0x4604b091 */
/* @0xb7b78 mrsls r2, apsr */
/* @0xb7b7c .word 0x23fcf8d4 */
/* @0xb7b80 vmlsl.s8 q9, d0, d0 */
/* @0xb7b84 bl 0x1d8304 <_Z17TestForNewRotatesx+0x128> */
/* @0xb7b88 stmdavs r3!, {r1, r7, r9} ^ */
/* @0xb7b8c strls r2, [r8, -r0, lsl #14] */
/* @0xb7b90 .word 0x13bef9b2 */
/* @0xb7b94 strvs r4, [r1, #-0x359]! */
/* @0xb7b98 .word 0x23bcf9b2 */
/* @0xb7b9c strbvs r6, [r5, #0x2e5]! */
/* @0xb7ba0 bvs 0x9488f4 <b2_toiTime+0x1ef450> */
/* @0xb7ba4 subspl pc, r7, r4, lsl #17 */
/* @0xb7ba8 subspl pc, r6, r4, lsl #17 */
/* @0xb7bac .word 0x63253a20 */
/* @0xb7bb0 strbtvs r6, [r3], #610 */
/* @0xb7bb4 adcvs r6, r3, #3719168 */
/* @0xb7bb8 addsvs r6, r11, r3, lsr #11 */
/* @0xb7bbc subspl pc, r4, r4, lsr #17 */
/* @0xb7bc0 strhlo pc, [r0], r4 */
/* @0xb7bc4 addsmi r9, r8, #8, #16 */
/* @0xb7bc8 teqhi r6, r0, lsl #5 */
/* @0xb7bcc .word 0x308cf8d4 */
/* @0xb7bd0 .word 0xf8d49908 */
/* @0xb7bd4 strbtvs r2, [r5], -r4, lsl #1 */
/* @0xb7bd8 rfeda r3! */
/* @0xb7bdc adcslt r8, r9, #17 */
/* @0xb7be0 .word 0xf8529808 */
/* @0xb7be4 stmibvs r7!, {r0, r4, r5, sp, lr} */
/* @0xb7be8 bleq 0xff2f27f8 <b2_toiTime+0xfffffffffeb99354> */
/* @0xb7bec subeq r6, r0, r3, lsr #17 */
/* @0xb7bf0 bl 0x15bc24 <_Z17InitYoYoFunctionsv+0x1b54> */
/* @0xb7bf4 adcsmi r0, lr, r1, asr #1 */
/* @0xb7bf8 eorshs pc, r8, r2, asr r8 */
/* @0xb7bfc beq 0x272b10 <pcre_dfa_exec+0x45a8> */
/* @0xb7c00 .word 0xc004f8db */
/* @0xb7c04 adcsmi r6, r10, r6, asr #16 */
/* @0xb7c08 .word 0xfc07fa0c */
/* @0xb7c0c ldrsbtmi r1, [lr], r2 */
/* @0xb7c10 bne 0xffe5f83c <b2_toiTime+0xffffffffff706398> */
/* @0xb7c14 movweq lr, #0xcbc3 */
/* @0xb7c18 ldrtmi r11, [r7], -pc, lsr #18 */
/* @0xb7c1c ssatmi r4, #0x1b, r6, asr #12 */
/* @0xb7c20 sadd16mi r4, r3, pc */
/* @0xb7c24 .word 0xf8d4463a */
/* @0xb7c28 bl 0x3e7e50 <error_g0017+0x40af4> */
/* @0xb7c2c .word 0xf81c0701 */
/* @0xb7c30 .word 0xf0199001 */
/* @0xb7c34 svclt #0x1c0f04 */
/* @0xb7c38 ldmdbne r9, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^ */
/* @0xb7c3c adcsls pc, r0, r4, lsl #17 */
/* @0xb7c40 andne pc, r1, r12, lsl r8 */
/* @0xb7c44 mrseq pc, apsr */
/* @0xb7c48 .word 0xf0002902 */
/* @0xb7c4c stmiblt r1!, {r1, r4, r5, r6, r7, pc} */
/* @0xb7c50 andne pc, r8, r12, lsl r8 */
/* @0xb7c54 mrseq pc, apsr */
/* @0xb7c58 .word 0xd1022901 */
/* @0xb7c5c bleq 0x2f4310 <ps_hints_apply+0x2f10> */
/* @0xb7c60 ldrtmi lr, [r3], #-7 */
/* @0xb7c64 bl 0x188db4 <_ZN16GraphicsRecorder12ReAllocVertsEP19SVertexNormal_FloatRiS2_i+0xc8> */
/* @0xb7c68 bl 0x154bbc <_Z19YYIAPEventsDispatchv+0xfd4> */
/* @0xb7c6c ldrsbne r7, [r11], #-34 */
/* @0xb7c70 stmdalo r8, {r1, r4, r6, r12} */
/* @0xb7c74 ldrmi r3, [r2], r1, lsl #30 */
/* @0xb7c78 strbtvs r4, [r6], #-1566 */
/* @0xb7c7c subge pc, r8, r4, asr #17 */
/* @0xb7c80 .word 0xf0804558 */
/* @0xb7c84 ldmdavc r11!, {r4, r6, r7, pc} ^ */
/* @0xb7c88 .word 0x0108f100 */
/* @0xb7c8c stmdbeq r1, {r0, r1, r2, r8, r12, sp, lr, pc} */
/* @0xb7c90 .word 0xf0139107 */
/* @0xb7c94 andsle r0, r3, r3, lsl #6 */
/* @0xb7c98 .word 0xd16c2b01 */
/* @0xb7c9c stmvs r0, {r1, r7, r11, sp, lr} ^ */
/* @0xb7ca0 stmvs r3!, {r0, r5, r7, r8, r11, sp, lr} */
/* @0xb7ca4 addmi r9, r10, r9, lsl #30 */
/* @0xb7ca8 .word 0xf101fa00 */
/* @0xb7cac bne 0xff2fe7fc <b2_toiTime+0xfffffffffeba5358> */
/* @0xb7cb0 .word 0x460bb917 */
/* @0xb7cb4 sadd16mi r4, r10, r1 */
/* @0xb7cb8 .word 0xf7ff4620 */
/* @0xb7cbc eors pc, r9, r11, asr #29 */
/* @0xb7cc0 stmvs r0, {r1, r7, r11, sp, lr} ^ */
/* @0xb7cc4 stmvs r3!, {r0, r5, r7, r8, r11, sp, lr} */
/* @0xb7cc8 blx 0xc7ef8 <_Z25F_Vertex_TexCoord_releaseR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xb7ccc stmdals r9, {r0, r8, r12, sp, lr, pc} */
/* @0xb7cd0 bne 0xff2fe820 <b2_toiTime+0xfffffffffeba537c> */
/* @0xb7cd4 .word 0x460bb910 */
/* @0xb7cd8 sadd16mi r4, r10, r1 */
/* @0xb7cdc strlo r9, [r2, -r7, lsl #22] */
/* @0xb7ce0 ldrbmi r9, [r11, #-0x706] */
/* @0xb7ce4 .word 0xf8ddd240 */
/* @0xb7ce8 .word 0xf1039018 */
/* @0xb7cec strls r0, [r10, -r8, lsl #14] */
/* @0xb7cf0 .word 0xf1099707 */
/* @0xb7cf4 strls r0, [r6, -r1, lsl #14] */
/* @0xb7cf8 stmibvs r0!, {r0, r1, r2, r3, r4, r7, r11, sp, lr} */
/* @0xb7cfc mulgt r0, r9, r8 */
/* @0xb7d00 .word 0xf000fa07 */
/* @0xb7d04 .word 0xf00c68a7 */
/* @0xb7d08 bl 0xff27ad1c <b2_toiTime+0xfffffffffeb21878> */
/* @0xb7d0c ldmvs r8, {r11} ^ */
/* @0xb7d10 blx 0xd23a4 <_Z22Variable_GetName_ScopePKcii+0x17c> */
/* @0xb7d14 stmdals r9, {r0, r1, r8, r9, r12, sp, lr, pc} */
/* @0xb7d18 ldmdblt r0, {r0, r1, r2, r3, r4, r6, r7, r8, r9, r11, r12} */
/* @0xb7d1c .word 0x4647463b */
/* @0xb7d20 .word 0xf1bc4698 */
/* @0xb7d24 .word 0xd1080f01 */
/* @0xb7d28 andhi pc, r0, sp, asr #17 */
/* @0xb7d2c ldrtmi r4, [r11], -r0, lsr #12 */
/* @0xb7d30 ldc2l p7, c15, [r8, #-1020]! */
/* @0xb7d34 rsbsle r2, r3, r0, lsl #16 */
/* @0xb7d38 .word 0xf1bce0d6 */
/* @0xb7d3c cmnle r8, r0, lsl #30 */
/* @0xb7d40 bl 0x13e474 <_Z26F_ActionCreateObjectRandomR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0xb7d44 bl 0x177d6c <_Z16GR_3D_Draw_Blockffffffiff+0x730> */
/* @0xb7d48 bl 0xd4c9c <_Z12DoPushGlobaljPhPKhP6VMExec+0xc4> */
/* @0xb7d4c ldrsbne r7, [r11], #-0 */
/* @0xb7d50 andls r1, r0, r0, asr #32 */
/* @0xb7d54 .word 0xf7ff4620 */
/* @0xb7d58 stmdahs r0, {r0, r2, r5, r6, r8, r10, r11, r12, sp, lr, pc} */
/* @0xb7d5c sbchi pc, r4, r0, asr #32 */
/* @0xb7d60 strbmi r9, [r2], -r10, lsl #22 */
/* @0xb7d64 .word 0xe7bc4639 */
/* @0xb7d68 andge pc, r0, sp, asr #17 */
/* @0xb7d6c ldrtmi r4, [r3], -r0, lsr #12 */
/* @0xb7d70 ldc2l p7, c15, [r8, #-1020] */
/* @0xb7d74 cps #0x11 */
/* @0xb7d78 ldrmi r0, [r11, #0x310] */
/* @0xb7d7c ldmvc r11!, {r0, r3, r4, r6, r8, r9, r12, lr, pc} */
/* @0xb7d80 movweq pc, #0x3003 */
/* @0xb7d84 cmple r4, r2, lsl #22 */
/* @0xb7d88 cps #0x2 */
/* @0xb7d8c stmibvs r3!, {r3, r4, r8} */
/* @0xb7d90 .word 0xe008f8d4 */
/* @0xb7d94 swpls r4, r10, [r7] */
/* @0xb7d98 stmdbeq r2, {r1, r2, r3, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0xb7d9c stmvs r1, {r1, r8, r11, sp, lr} ^ */
/* @0xb7da0 .word 0xfc03fa02 */
/* @0xb7da4 addsmi r6, r9, r2, asr #18 */
/* @0xb7da8 .word 0x0c0cebce */
/* @0xb7dac smlabteq r1, lr, r11, lr */
/* @0xb7db0 bl 0xff448020 <b2_toiTime+0xfffffffffeceeb7c> */
/* @0xb7db4 bls 0x2f89c4 <ps_hints_apply+0x75c4> */
/* @0xb7db8 ldrmi r11, [r8], r10, lsr #18 */
/* @0xb7dbc strbmi r4, [r4], r3, ror #12 */
/* @0xb7dc0 strbmi r4, [r9], -r8, lsl #13 */
/* @0xb7dc4 bls 0x2898d0 <spSkeleton_updateCache+0x2d4> */
/* @0xb7dc8 ldmdale sp, {r1, r3, r4, r6, r8, r10, lr} */
/* @0xb7dcc ldrsbhi pc, [r8], -r0 */
/* @0xb7dd0 stmibvs r2!, {r6, r7, r8, r11, sp, lr} */
/* @0xb7dd4 .word 0xf802fa08 */
/* @0xb7dd8 bls 0x308020 <TT_New_Context+0x7e18> */
/* @0xb7ddc stmdaeq r8, {r1, r2, r3, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0xb7de0 andeq lr, r0, lr, asr #23 */
/* @0xb7de4 pkhbtmi r11, r6, r2, lsl #18 */
/* @0xb7de8 ldrbtmi r4, [r0], r0, asr #12 */
/* @0xb7dec strbmi r9, [r10], -r1 */
/* @0xb7df0 andgt pc, r0, sp, asr #17 */
/* @0xb7df4 .word 0xf8cd4620 */
/* @0xb7df8 .word 0xf7ff8008 */
/* @0xb7dfc stmdahs r0, {r0, r3, r4, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0xb7e00 .word 0xf107d172 */
/* @0xb7e04 and r0, r11, r3, lsl #18 */
/* @0xb7e08 andgt pc, r0, sp, asr #17 */
/* @0xb7e0c strls r4, [r1], -r0, lsr #12 */
/* @0xb7e10 .word 0xf8cd464a */
/* @0xb7e14 .word 0xf7ffa008 */
/* @0xb7e18 stmdahs r0, {r0, r1, r3, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0xb7e1c sub sp, r2, r4, ror #2 */
/* @0xb7e20 stmdals r7, {r0, r1, r2, r3, r6, r9, r10, lr} */
/* @0xb7e24 strtmi lr, [r0], -r12, lsr #14 */
/* @0xb7e28 uasxmi r4, r2, r1 */
/* @0xb7e2c mrc2 p7, #0x0, apsr_nzcv, c2, c15, #0x7 */
/* @0xb7e30 tsths r4, #63700992 */
/* @0xb7e34 subs r6, r7, r3, ror #5 */
/* @0xb7e38 ldrhvc pc, [r4], #-132 */
/* @0xb7e3c svchs #0x16de6 */
/* @0xb7e40 cdphs p9, #0x0, c13, c0, c15, #0x1 */
/* @0xb7e44 svchs #0x1d02d */
/* @0xb7e48 svclt #0x946933 */
/* @0xb7e4c ldmvs r2!, {r0, r2, r4, r5, r6, sp, lr} */
/* @0xb7e50 svclt #0x846971 */
/* @0xb7e54 addeq lr, r3, #2048 */
/* @0xb7e58 ldmibhi r2!, {r1, r4, r5, r6, sp, lr} */
/* @0xb7e5c svceq #0x8f012 */
/* @0xb7e60 strmi sp, [r11], #-3 */
/* @0xb7e64 ldmlo pc!, {r0, r1, r8, r12, sp, lr, pc} ^ */
/* @0xb7e68 strmi lr, [r8], r10 */
/* @0xb7e6c .word 0xf1031ac9 */
/* @0xb7e70 ldmvs r2!, {r7, r8, r9, lr} */
/* @0xb7e74 .word 0x31013b01 */
/* @0xb7e78 bl 0x150444 <InitPhysicsFunctions+0x10> */
/* @0xb7e7c adcsvs r0, r3, r3, lsl #7 */
/* @0xb7e80 .word 0xf7ff4620 */
/* @0xb7e84 stmdahs r0, {r0, r4, r5, r7, r9, r11, r12, sp, lr, pc} */
/* @0xb7e88 strtmi sp, [r0], -lr, lsr #2 */
/* @0xb7e8c mrseq pc, apsr */
/* @0xb7e90 blx 0xfeb75e94 <b2_toiTime+0xfffffffffe41c9f0> */
/* @0xb7e94 svclo #0x1bb40 */
/* @0xb7e98 adcslt r6, pc, #7733248 */
/* @0xb7e9c bicsle r2, r2, r0, lsl #30 */
/* @0xb7ea0 strbvs lr, [r5, #0x73]! */
/* @0xb7ea4 .word 0xf8d4e071 */
/* @0xb7ea8 stmdals r11, {r2, r3, r7, r12, sp} */
/* @0xb7eac stcvs p8, c6, [r6, #388]! */
/* @0xb7eb0 .word 0xf1015a1f */
/* @0xb7eb4 stcvs p14, c3, [r3], #1020 */
/* @0xb7eb8 b 0x845ac4 <b2_toiTime+0xec620> */
/* @0xb7ebc .word 0xd1020e03 */
/* @0xb7ec0 addsmi r6, r3, #57856 */
/* @0xb7ec4 ldmvs r2!, {r0, r6, r9, r11, r12, lr, pc} */
/* @0xb7ec8 addsmi r6, r0, #160, #20 */
/* @0xb7ecc suble r6, r11, r2, lsr #17 */
/* @0xb7ed0 .word 0x070089b0 */
/* @0xb7ed4 ldrmi sp, [r6, #0x548] */
/* @0xb7ed8 strhhs r11, [r0, -r4] */
/* @0xb7edc strtmi r2, [r0], -r1, lsl #2 */
/* @0xb7ee0 blx 0x1435ee4 <b2_toiTime+0xcdca40> */
/* @0xb7ee4 suble r2, r9, r0, lsl #16 */
/* @0xb7ee8 blhs 0x1952a7c <b2_toiTime+0x11f95d8> */
/* @0xb7eec .word 0xf8d4d12b */
/* @0xb7ef0 rscvs r2, r5, #252, #6 */
/* @0xb7ef4 bl 0x1c2714 <_ZN13CLayerManager18InitLayerFunctionsEv+0x11d4> */
/* @0xb7ef8 rfeia r3! */
/* @0xb7efc rfeib r3! */
/* @0xb7f00 blx 0xb8df8 <.text+0x1e28> */
/* @0xb7f04 bl 0x134524 <_Z19F_SoundEffectReverbR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0xb7f08 b 0x1494654 <b2_toiTime+0xd3b1b0> */
/* @0xb7f0c addlt r0, pc, #1073741848 */
/* @0xb7f10 blx 0x4aef24 <SrcVerts+0xbf68> */
/* @0xb7f14 strmi pc, [r4, #0xc87] */
/* @0xb7f18 movwhs sp, #0xa03 */
/* @0xb7f1c .word 0x33fcf8c4 */
/* @0xb7f20 andlo lr, r1, #12 */
/* @0xb7f24 bl 0x1c6330 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers+0x2c0> */
/* @0xb7f28 .word 0xf8a00082 */
/* @0xb7f2c .word 0xf8a073bc */
/* @0xb7f30 .word 0xf8a363be */
/* @0xb7f34 .word 0xf8c413be */
/* @0xb7f38 ssub8 r2, pc, r12 */
/* @0xb7f3c rscvs r2, r0, #20 */
/* @0xb7f40 andhs lr, r0, r3, ror #2 */
/* @0xb7f44 andhs lr, r1, r1, ror #2 */
/* @0xb7f48 stcvs p1, c14, [r2, #-380]! */
/* @0xb7f4c ldcle p2, c4, [r10], #588 */
/* @0xb7f50 bhs 0xd37e0 <_ZN17TErrStreamConsole6OutputEPKcz+0x58> */
/* @0xb7f54 ldmibhi r0!, {r0, r1, r2, r4, r5, r7, r12, lr, pc} */
/* @0xb7f58 umaalmi r8, r2, r2, r9 */
/* @0xb7f5c ldrtle r0, [r2], #1810 */
/* @0xb7f60 blo 0x1d29f0 <CheckLicense+0x650> */
/* @0xb7f64 str r6, [lr, r2, lsr #5]! */
/* @0xb7f68 vmlaeq.f64 d14, d1, d3 */
/* @0xb7f6c .word 0xf10e4249 */
/* @0xb7f70 b 0x447b74 <g_RomDisk+0x50354> */
/* @0xb7f74 bne 0xff2f8380 <b2_toiTime+0xfffffffffeb9eedc> */
/* @0xb7f78 .word 0xe7ad4291 */
/* @0xb7f7c .word 0xb1036e23 */
/* @0xb7f80 blls 0x2d0754 <_ZN13b2PulleyJoint4DumpEv+0x20> */
/* @0xb7f84 movwls r3, #0x8301 */
/* @0xb7f88 bvs 0xfe9717f8 <b2_toiTime+0xfffffffffe218354> */
/* @0xb7f8c addsmi r6, r10, #405504 */
/* @0xb7f90 stclvs p2, c13, [r1, #680]! */
/* @0xb7f94 .word 0xf0002900 */
/* @0xb7f98 andhs r8, r0, #-2147483636 */
/* @0xb7f9c andls r9, lr, #-805306368 */
/* @0xb7fa0 andls r10, pc, #13, #30 */
/* @0xb7fa4 stmdavs r3!, {r1, r5, r6, r7, r10, r11, sp, lr} */
/* @0xb7fa8 tstmi r10, r6, lsl #14 */
/* @0xb7fac eorshs pc, r2, sp, lsr #17 */
/* @0xb7fb0 blx 0x1153440 <b2_toiTime+0x9f9f9c> */
/* @0xb7fb4 .word 0xf8adf303 */
/* @0xb7fb8 stmdbvs r8, {r4, r5, r12, sp} ^ */
/* @0xb7fbc rfeib sp! */
/* @0xb7fc0 strmi r7, [r3], #-48 */
/* @0xb7fc4 bllo 0x1249d4 <_Z20InitGraphicFunctionsv+0x1768> */
/* @0xb7fc8 andslt r6, r0, #5111808 */
/* @0xb7fcc addmi r11, r7, #-1342177271 */
/* @0xb7fd0 ldrhteq pc, [r2], -sp */
/* @0xb7fd4 .word 0xf8adbfc8 */
/* @0xb7fd8 andslt r2, r10, #48 */
/* @0xb7fdc stmdage sp, {r4, r7, r9, lr} */
/* @0xb7fe0 .word 0xf8adbfb8 */
/* @0xb7fe4 andvs r3, sp, r2, lsr r0 */
/* @0xb7fe8 blx 0xffdb5fec <b2_toiTime+0xffffffffff65cb48> */
/* @0xb7fec ldrtmi r11, [r1], -lr, lsl #2 */
/* @0xb7ff0 blvs 0x9b1f84 <b2_toiTime+0x258ae0> */
/* @0xb7ff4 adcle r2, r1, r0, lsl #22 */
/* @0xb7ff8 .word 0x30a0f8d4 */
/* @0xb7ffc strtmi r10, [r0], -r12, lsl #18 */
/* @0xb8000 eorseq pc, r2, #1073741827 */
/* @0xb8004 blls 0x409e6c <g_RomDisk+0x1264c> */
/* @0xb8008 ldrhtne pc, [r0], -sp */
/* @0xb800c ldmdbvs r10, {r0, r1, r5, r8, r12, sp, pc} ^ */
/* @0xb8010 orrsvs r1, r10, r2, asr r10 */
/* @0xb8014 ubfx r6, r11, #0x10, #0x1a */
/* @0xb8018 rfeia sp! */
/* @0xb801c blhs 0xd00e4 <_Z13STRING_RValuePPcS0_PiPK6RValue+0x16c> */
/* @0xb8020 .word 0xf06fdd09 */
/* @0xb8024 bvs 0x938438 <b2_toiTime+0x1def94> */
/* @0xb8028 eorslt r4, r0, #1677721601 */
/* @0xb802c addmi r5, r1, #5308416 */
/* @0xb8030 bllo 0x12c43c <_Z28F_BackgroundCreateFromScreenR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xb8034 .word 0xf10d6323 */
/* @0xb8038 .word 0xf10d093c */
/* @0xb803c smladxhs r0, r8, r10, r0 */
/* @0xb8040 blvs 0x99dc68 <b2_toiTime+0x2447c4> */
/* @0xb8044 .word 0xf3402b00 */
/* @0xb8048 stmdals r8, {r1, r3, r5, r7, pc} */
/* @0xb804c ldrsbtlt pc, [r4], -sp */
/* @0xb8050 .word 0xf1bbb207 */
/* @0xb8054 andsle r0, r6, r0, lsl #30 */
/* @0xb8058 ldrsblo pc, [r8], -r11 */
/* @0xb805c .word 0x8004f8db */
/* @0xb8060 .word 0xf8cb1bdb */
/* @0xb8064 stmdblt r3!, {r3, r4, r12, sp} ^ */
/* @0xb8068 ldrbmi r10, [r9], -sp, lsl #16 */
/* @0xb806c blx 0xff076070 <b2_toiTime+0xfffffffffe91cbcc> */
/* @0xb8070 strhlo pc, [r12], -r11 */
/* @0xb8074 .word 0x071b4659 */
/* @0xb8078 ldrbmi r11, [r0], -r12, asr #30 */
/* @0xb807c .word 0xf7ff4648 */
/* @0xb8080 strbmi pc, [r3], r8, lsr #21 */
/* @0xb8084 ldrbmi lr, [r0], -r5, ror #15 */
/* @0xb8088 blx 0xfefb608c <b2_toiTime+0xfffffffffe85cbe8> */
/* @0xb808c .word 0xf7ff4648 */
/* @0xb8090 blvs 0x9b6b78 <b2_toiTime+0x25d6d4> */
/* @0xb8094 vnmlsne.f32 s13, s18, s5 */
/* @0xb8098 .word 0xf06f6321 */
/* @0xb809c movtmi r0, #0xb103 */
/* @0xb80a0 blne 0xfe74e3f4 <b2_toiTime+0xfffffffffdff4f50> */
/* @0xb80a4 movwls r11, #0x721b */
/* @0xb80a8 andls r11, r8, #536870921 */
/* @0xb80ac eorslt r9, r3, #7, #30 */
/* @0xb80b0 adcsmi r9, r11, #229376 */
/* @0xb80b4 .word 0xf8ddda65 */
/* @0xb80b8 .word 0x4688b03c */
/* @0xb80bc .word 0x0c00f04f */
/* @0xb80c0 .word 0xf1b8930a */
/* @0xb80c4 eorsle r0, pc, r0, lsl #30 */
/* @0xb80c8 .word 0x3000f8d8 */
/* @0xb80cc .word 0x2000f8db */
/* @0xb80d0 .word 0xdc024293 */
/* @0xb80d4 sadd16mi r4, r10, r1 */
/* @0xb80d8 stmdavs r1!, {r0, r1, r3, r9, r10, lr} ^ */
/* @0xb80dc addmi r1, r8, #152, #20 */
/* @0xb80e0 submi sp, pc, #8704 */
/* @0xb80e4 andeq lr, r7, r2, lsl #20 */
/* @0xb80e8 mulsle sp, r0, r2 */
/* @0xb80ec vmlaeq.f64 d14, d1, d3 */
/* @0xb80f0 cdplo p1, #0xf, c15, c15, c14, #0x0 */
/* @0xb80f4 streq lr, [r7, -lr, lsl #20] */
/* @0xb80f8 mulsle r5, pc, r2 */
/* @0xb80fc .word 0xdc0242b8 */
/* @0xb8100 addmi r4, pc, #16777216 */
/* @0xb8104 rfeia r8! */
/* @0xb8108 .word 0xf001100c */
/* @0xb810c stmdbhs r2, {r0, r1, r2, r8} */
/* @0xb8110 .word 0x2101d015 */
/* @0xb8114 .word 0xf8c8448c */
/* @0xb8118 blx 0x880120 <b2_toiTime+0x126c7c> */
/* @0xb811c .word 0xf8cbfc8c */
/* @0xb8120 .word 0xf8c83000 */
/* @0xb8124 and r1, r10, r8, lsl r0 */
/* @0xb8128 andsgt pc, r4, sp, asr #17 */
/* @0xb812c stm sp, {r5, r9, r10, lr} */
/* @0xb8130 .word 0xf8d40900 */
/* @0xb8134 stmdbls r10, {r2, r5, r7, r12, sp, lr} */
/* @0xb8138 .word 0xf8dd47b8 */
/* @0xb813c .word 0xf8d8c014 */
/* @0xb8140 .word 0xf8db8004 */
/* @0xb8144 ldr r11, [r12, r4]! */
/* @0xb8148 stc2 p10, c15, [r12], {15} */
/* @0xb814c svceq #0xf1bc */
/* @0xb8150 .word 0x3601dc31 */
/* @0xb8154 .word 0x30acf8d4 */
/* @0xb8158 adcslt r4, r6, #32, #12 */
/* @0xb815c svcls #0x74798 */
/* @0xb8160 adcsmi r11, r11, #805306371 */
/* @0xb8164 ldrbmi sp, [r0], -r2, lsr #21 */
/* @0xb8168 blx 0x13b616c <b2_toiTime+0xc5ccc8> */
/* @0xb816c .word 0xf7ff4648 */
/* @0xb8170 ldr pc, [r11, r8, asr #20] */
/* @0xb8174 stmdavs pc, {r0, r1, r3, r8, r11, sp, lr} ^ */
/* @0xb8178 uadd16mi r11, r0, r3 */
/* @0xb817c blx 0xe76180 <b2_toiTime+0x71ccdc> */
/* @0xb8180 stmdbhs r0, {r0, r3, r4, r5, r9, r10, lr} */
/* @0xb8184 stmdbls pc, {r1, r2, r4, r5, r6, r7, r8, r12, lr, pc} */
/* @0xb8188 .word 0xf43f2900 */
/* @0xb818c stmdbvs r11, {r1, r3, r4, r6, r8, r9, r10, r11, sp, pc} */
/* @0xb8190 ldmdblt r3, {r0, r1, r2, r3, r6, r11, sp, lr} */
/* @0xb8194 .word 0xf7ff4648 */
/* @0xb8198 ldrtmi pc, [r9], -r9, lsr #20 */
/* @0xb819c rfeib sp! */
/* @0xb81a0 eorslt r2, r3, #50 */
/* @0xb81a4 blle 0xb48c14 <b2_toiTime+0x3ef770> */
/* @0xb81a8 .word 0xf8d43601 */
/* @0xb81ac strtmi r3, [r0], -r12, lsr #1 */
/* @0xb81b0 adcslt r4, r6, #152, #14 */
/* @0xb81b4 .word 0xf8dde7f3 */
/* @0xb81b8 blx 0x4a82a0 <SrcVerts+0x52e4> */
/* @0xb81bc .word 0xf8ddf886 */
/* @0xb81c0 .word 0xf1bcb03c */
/* @0xb81c4 sbcle r0, r4, r0, lsl #30 */
/* @0xb81c8 ldrsblo pc, [r8], -r12 */
/* @0xb81cc .word 0xf8ccb193 */
/* @0xb81d0 qadd16mi r5, r0, r8 */
/* @0xb81d4 andgt pc, r0, sp, asr #17 */
/* @0xb81d8 .word 0xf8cd4641 */
/* @0xb81dc .word 0xf8d4b004 */
/* @0xb81e0 .word 0xf8dc70a8 */
/* @0xb81e4 .word 0xf8db2000 */
/* @0xb81e8 .word 0xf8cd3000 */
/* @0xb81ec .word 0x47b8c014 */
/* @0xb81f0 ldrsbgt pc, [r4], -sp */
/* @0xb81f4 .word 0xc004f8dc */
/* @0xb81f8 .word 0xb004f8db */
/* @0xb81fc .word 0xf8d4e7e1 */
/* @0xb8200 bllo 0x1051f8 <dsMapAddRValue+0xc8> */
/* @0xb8204 .word 0x33fcf8c4 */
/* @0xb8208 ldrhlt lr, [r1], -r8 */
/* @0xb820c svchi #0xf0e8bd */
/* @0xb8210 stmdavs sp, {r4, r5, r6, r7, r8, r10, r12, sp, pc} */
/* @0xb8214 stclne p8, c6, [lr, #-784]! */
/* @0xb8218 stmdble r1, {r1, r2, r4, r7, r9, lr} */
/* @0xb821c ldcllt p0, c2, [r0, #24]! */
/* @0xb8220 eorhi r7, r7, pc, lsr #16 */
/* @0xb8224 rsbhi r7, r7, pc, ror #16 */
/* @0xb8228 mulvc r2, r5, r9 */
/* @0xb822c .word 0xf99580a7 */
/* @0xb8230 rschi r7, r7, r3 */
/* @0xb8234 .word 0x8127792f */
/* @0xb8238 .word 0xf105b15b */
/* @0xb823c addsmi r0, r6, #8, #12 */
/* @0xb8240 .word 0xf995d8ec */
/* @0xb8244 .word 0x81633005 */
/* @0xb8248 mullo r6, r5, r9 */
/* @0xb824c stmibvc r11!, {r0, r1, r5, r7, r8, pc} ^ */
/* @0xb8250 .word 0x8163e001 */
/* @0xb8254 mvnhi r8, r3, lsr #3 */
/* @0xb8258 strvc r2, [r3], #-769 */
/* @0xb825c andvs r2, lr, r0 */
/* @0xb8260 .word 0xf401bdf0 */
/* @0xb8264 push {r7, r8, lr} */
/* @0xb8268 .word 0xf04f47f0 */
/* @0xb826c addlt r0, r12, #0, #20 */
/* @0xb8270 ldrmi r4, [r0], r7, lsl #12 */
/* @0xb8274 vst1.32 {d20, d21, d22}, [pc:64], r9 */
/* @0xb8278 ldrbmi r3, [r6], -r0, lsl #1 */
/* @0xb827c addsmi r6, lr, #3866624 */
/* @0xb8280 .word 0xf858d22c */
/* @0xb8284 .word 0xb32a200a */
/* @0xb8288 .word 0xf85368bb */
/* @0xb828c teqlt r9, #10 */
/* @0xb8290 mulsle pc, r1, r2 */
/* @0xb8294 b 0x1667ac <_ZN9CBitmap32C2Eiijji+0x44> */
/* @0xb8298 addsmi r7, r9, #-2013265917 */
/* @0xb829c b 0x96ef30 <b2_toiTime+0x215a8c> */
/* @0xb82a0 addsmi r7, r9, #-2013265917 */
/* @0xb82a4 ands sp, lr, r4, lsl sp */
/* @0xb82a8 andpl pc, r10, r9, asr r8 */
/* @0xb82ac blle 0x808d58 <b2_toiTime+0xaf8b4> */
/* @0xb82b0 .word 0xc020f8dd */
/* @0xb82b4 andlo pc, r10, r12, asr r8 */
/* @0xb82b8 .word 0xdc174299 */
/* @0xb82bc svclt #0xb94291 */
/* @0xb82c0 smlabteq r1, r5, r11, lr */
/* @0xb82c4 andeq lr, r2, #201728 */
/* @0xb82c8 smlabteq r3, r1, r11, lr */
/* @0xb82cc andeq lr, r3, #198656 */
/* @0xb82d0 ldc2 p2, c15, [r4, #-176]! */
/* @0xb82d4 .word 0xf10a3601 */
/* @0xb82d8 strb r0, [pc, r4, lsl #20] */
/* @0xb82dc .word 0x87f0e8bd */
/* @0xb82e0 pop {r3, r9, r10, lr} */
/* @0xb82e4 qsub8mi r8, r0, r0 */
/* @0xb82e8 .word 0x87f0e8bd */
/* @0xb82ec ldm sp!, {sp} */
/* @0xb82f0 push {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xb82f4 strdlt r4, r5, [r7], r0 */
/* @0xb82f8 stmibvs r5, {r8, r9, sp} ^ */
/* @0xb82fc .word 0x46076013 */
/* @0xb8300 ldrmi r4, [r4], -r8, lsl #13 */
/* @0xb8304 vcgt.s32 d9, d14, d5 */
/* @0xb8308 sbclt pc, r6, #108544 */
/* @0xb830c rsble r2, pc, r0, lsl #28 */
/* @0xb8310 strle r0, [r7, #-0x633] */
/* @0xb8314 .word 0xf0064638 */
/* @0xb8318 .word 0xf22e067f */
/* @0xb831c eorseq pc, r6, #96, #22 */
/* @0xb8320 movwmi r11, #0x62c0 */
/* @0xb8324 stmdble r1, {r1, r2, r6, r8, r10, lr} */
/* @0xb8328 rsb r2, r3, r0 */
/* @0xb832c blge 0x200b34 <_Z17GV_PointerInvalidP9CInstanceiP6RValue+0xa8> */
/* @0xb8330 movwls r4, #0x1628 */
/* @0xb8334 .word 0x21029200 */
/* @0xb8338 .word 0xf22f1c73 */
/* @0xb833c stcls p14, c15, [r5, #-672] */
/* @0xb8340 stchs p6, c4, [r0, #-512] */
/* @0xb8344 .word 0x6026d1f0 */
/* @0xb8348 adcsmi r4, r4, #44, #12 */
/* @0xb834c ldrtmi sp, [r8], -lr, asr #4 */
/* @0xb8350 beq 0x134768 <_Z26F_AudioSetListenerVelocityR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xb8354 blx 0x11b4c16 <b2_toiTime+0xa5b772> */
/* @0xb8358 stmdbeq r4, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^ */
/* @0xb835c blx 0xfe0f6ce2 <b2_toiTime+0xfffffffffd99d83e> */
/* @0xb8360 cmneq pc, #43 */
/* @0xb8364 rscseq pc, pc, #3 */
/* @0xb8368 shsub8mi r11, r8, r11 */
/* @0xb836c bleq 0x20b43a0 <b2_toiTime+0x195aefc> */
/* @0xb8370 blx 0x10b4c32 <b2_toiTime+0x95b78e> */
/* @0xb8374 movweq lr, #0x9b08 */
/* @0xb8378 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0xb837c addlt r4, r5, #40, #8 */
/* @0xb8380 andspl pc, r4, r8, lsr #16 */
/* @0xb8384 ldrbmi r4, [r9, #0x654] */
/* @0xb8388 .word 0x4638d2df */
/* @0xb838c vcgt.s32 d9, d14, d3 */
/* @0xb8390 blls 0x1b7058 <_ZN13CLayerManager4InitEv+0x158> */
/* @0xb8394 bl 0x1853a0 <_ZN8Graphics5FlushEv+0xb4> */
/* @0xb8398 adcsmi r0, r4, #-1879048188 */
/* @0xb839c addlt r4, r5, #40, #8 */
/* @0xb83a0 sbcsle r8, r2, #85 */
/* @0xb83a4 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc} */
/* @0xb83a8 ldrtmi lr, [r8], -sp, ror #15 */
/* @0xb83ac vhsub.s32 d9, d14, d3 */
/* @0xb83b0 bl 0x2f7010 <ps_hints_apply+0x5c10> */
/* @0xb83b4 blx 0x15f8fe0 <b2_toiTime+0xe9fb3c> */
/* @0xb83b8 addlt pc, r5, #128 */
/* @0xb83bc andspl pc, r4, r8, lsr #16 */
/* @0xb83c0 ldrbmi r9, [r4], -r3, lsl #20 */
/* @0xb83c4 ldrbmi r4, [r9, #0x691] */
/* @0xb83c8 .word 0x4638d2bf */
/* @0xb83cc vcgt.s32 d9, d14, d3 */
/* @0xb83d0 blls 0x1b6ff0 <_ZN13CLayerManager4InitEv+0xf0> */
/* @0xb83d4 bl 0x1853e0 <_ZN8Graphics5FlushEv+0xf4> */
/* @0xb83d8 adcsmi r0, r4, #-1879048188 */
/* @0xb83dc .word 0xf080fa55 */
/* @0xb83e0 subshi r11, r5, r5, lsl #5 */
/* @0xb83e4 .word 0xf109d2b1 */
/* @0xb83e8 strb r0, [r12, r1, lsl #18]! */
/* @0xb83ec and r4, r1, r0, asr #12 */
/* @0xb83f0 rscslo pc, pc, pc, asr #32 */
/* @0xb83f4 pop {r0, r1, r2, r12, sp, pc} */
/* @0xb83f8 push {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xb83fc ssub8mi r4, r5, r0 */
/* @0xb8400 addmi r11, sp, #135 */
/* @0xb8404 andeq pc, r0, #79 */
/* @0xb8408 .word 0xf8d04607 */
/* @0xb840c andls r9, r5, #28 */
/* @0xb8410 blge 0x22e55c <res0_look+0x384> */
/* @0xb8414 movwls r9, #0x1200 */
/* @0xb8418 .word 0x21024648 */
/* @0xb841c vmax.s32 d4, d15, d27 */
/* @0xb8420 .word 0x9c05fe36 */
/* @0xb8424 strmi r4, [r6], -r2, lsr #13 */
/* @0xb8428 mrsle r2, spsr */
/* @0xb842c eorsle r4, r12, #172, #4 */
/* @0xb8430 vmin.s32 d4, d14, d24 */
/* @0xb8434 .word 0x0063fad4 */
/* @0xb8438 .word 0xf020b2c0 */
/* @0xb843c .word 0xf000027f */
/* @0xb8440 .word 0xf0020b3f */
/* @0xb8444 ldrshlt r0, [r10, #-31] */
/* @0xb8448 movwhs r1, #0x8f2 */
/* @0xb844c andsge pc, r3, r2, lsr #16 */
/* @0xb8450 ldrbmi r3, [r11, #-0x301] */
/* @0xb8454 streq pc, [r1], #-260 */
/* @0xb8458 adcmi sp, r12, #232, #16 */
/* @0xb845c .word 0xe026d3f6 */
/* @0xb8460 subeq pc, r0, r0 */
/* @0xb8464 .word 0xf0004433 */
/* @0xb8468 strdlt r0, r1, [r8, pc] */
/* @0xb846c ldrtmi r4, [r8], -r8, lsl #13 */
/* @0xb8470 vcgt.s32 d9, d14, d3 */
/* @0xb8474 blls 0x1b6f74 <_ZN13CLayerManager4InitEv+0x74> */
/* @0xb8478 .word 0xf8233401 */
/* @0xb847c .word 0xf1080018 */
/* @0xb8480 ldrbmi r0, [r8, #0x801] */
/* @0xb8484 adcmi sp, r12, #13762560 */
/* @0xb8488 ldrsh sp, [r0], -r1 */
/* @0xb848c andle r4, lr, #172, #4 */
/* @0xb8490 movwls r4, #0x3638 */
/* @0xb8494 blx 0xfe9b4d54 <b2_toiTime+0xfffffffffe25b8b0> */
/* @0xb8498 strlo r9, [r1], #-2819 */
/* @0xb849c andseq pc, r8, r3, lsr #16 */
/* @0xb84a0 stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0xb84a4 ldmible r1!, {r3, r4, r6, r7, r8, r10, lr} ^ */
/* @0xb84a8 ldrtmi lr, [r0], -r0, asr #15 */
/* @0xb84ac strbmi lr, [r8], -r4 */
/* @0xb84b0 vmin.s32 d4, d14, d17 */
/* @0xb84b4 andhs pc, r0, r0, asr #30 */
/* @0xb84b8 pop {r0, r1, r2, r12, sp, pc} */
/* @0xb84bc push {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xb84c0 strdlt r4, r5, [r11], r0 */
/* @0xb84c4 ldrmi r6, [r6], -r4, lsl #29 */
/* @0xb84c8 adcshi pc, r8, #208, #16 */
/* @0xb84cc strtmi r9, [r0], -r5, lsl #2 */
/* @0xb84d0 .word 0xf22e69e7 */
/* @0xb84d4 andls pc, r9, r8, ror #19 */
/* @0xb84d8 .word 0x2100b110 */
/* @0xb84dc cmn r11, r4, lsl #2 */
/* @0xb84e0 strtmi r10, [r0], -r9, lsl #26 */
/* @0xb84e4 vmax.s32 d4, d14, d25 */
/* @0xb84e8 blls 0x337124 */
/* @0xb84ec mvnsle r2, r0, lsl #22 */
/* @0xb84f0 tstle r1, r1, lsl #16 */
/* @0xb84f4 strtmi r4, [r9], -r0, lsr #12 */
/* @0xb84f8 stc2l p2, c15, [r4], #-184 */
/* @0xb84fc strmi r9, [r1], r9, lsl #22 */
/* @0xb8500 mvnle r2, r0, lsl #22 */
/* @0xb8504 strtmi r4, [r9], -r0, lsr #12 */
/* @0xb8508 blx 0xffff4dc8 <b2_toiTime+0xffffffffff89b924> */
/* @0xb850c strmi r9, [r3], -r9, lsl #20 */
/* @0xb8510 bhs 0xd05d8 <_Z20Code_Execute_SpecialP9CInstanceS0_P5CCodeP6RValuei+0x4> */
/* @0xb8514 ldmdblt r8, {r0, r5, r6, r7, r8, r12, lr, pc} */
/* @0xb8518 movwls r2, #0x4208 */
/* @0xb851c cmp r11, r9, lsl #4 */
/* @0xb8520 eoreq lr, r4, sp, lsl #17 */
/* @0xb8524 .word 0x21044638 */
/* @0xb8528 ldc2 p2, c15, [r1, #188]! */
/* @0xb852c andls r9, r4, r9, lsl #22 */
/* @0xb8530 .word 0xf0402b00 */
/* @0xb8534 .word 0x469a8151 */
/* @0xb8538 qasxmi r6, r0, r3 */
/* @0xb853c andle r4, r12, #645922816 */
/* @0xb8540 vmax.s32 d4, d14, d25 */
/* @0xb8544 bls 0x1f7648 <_ZN9RVariableC2EPKS_+0x244> */
/* @0xb8548 eoreq pc, r10, r2, asr #16 */
/* @0xb854c blhs 0xdf178 <_Z5DoAndjPhPKhP6VMExec+0x208> */
/* @0xb8550 .word 0x8142f040 */
/* @0xb8554 beq 0x134984 <_Z30F_AudioSetListenerOrientationNR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xb8558 stmdbls r5, {r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0xb855c .word 0xf22e4449 */
/* @0xb8560 andls pc, r9, r2, lsr #19 */
/* @0xb8564 .word 0xf0402800 */
/* @0xb8568 qasxmi r8, r0, r7 */
/* @0xb856c vmax.s32 d4, d14, d25 */
/* @0xb8570 blls 0x33709c */
/* @0xb8574 blhs 0xd8a3c <_ZN2VM18GetStructureCountsEP15Buffer_Standard+0x130> */
/* @0xb8578 .word 0x812ef040 */
/* @0xb857c strtmi r4, [r9], -r0, lsr #12 */
/* @0xb8580 blx 0xff0f4e40 <b2_toiTime+0xfffffffffe99b99c> */
/* @0xb8584 strmi r9, [r3], -r9, lsl #20 */
/* @0xb8588 bhs 0xd0950 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x304> */
/* @0xb858c .word 0x8124f040 */
/* @0xb8590 .word 0x100cf8d8 */
/* @0xb8594 stmdavs r9, {r4, r5, r8, r11, pc} */
/* @0xb8598 .word 0xf0404288 */
/* @0xb859c stm sp, {r0, r3, r5, r7, pc} */
/* @0xb85a0 ldrtmi r0, [r8], -r4, lsr #32 */
/* @0xb85a4 vrhadd.s32 d2, d15, d4 */
/* @0xb85a8 blls 0x337b78 */
/* @0xb85ac blhs 0xd0a74 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x428> */
/* @0xb85b0 tsthi r2, r0, asr #32 */
/* @0xb85b4 ldmvs r3!, {r3, r4, r7, r9, r10, lr} ^ */
/* @0xb85b8 subsle r4, r0, #152, #10 */
/* @0xb85bc andhs r2, r0, #0, #2 */
/* @0xb85c0 eoreq lr, r2, sp, lsl #17 */
/* @0xb85c4 ldmdbhi r3!, {r3, r4, r5, r9, r10, lr} */
/* @0xb85c8 .word 0xf8d6210c */
/* @0xb85cc vqadd.s32 d9, d15, d0 */
/* @0xb85d0 .word 0xf849fd5e */
/* @0xb85d4 bls 0x2f867c <ps_hints_apply+0x727c> */
/* @0xb85d8 .word 0xf0402a00 */
/* @0xb85dc ldmdbvs r3!, {r0, r2, r3, r4, r5, r6, r7, pc} */
/* @0xb85e0 .word 0xf8534691 */
/* @0xb85e4 ldmdbhi r2!, {r3, r5, sp, pc} */
/* @0xb85e8 eorsle r4, r5, #608174080 */
/* @0xb85ec strtmi r4, [r9], -r0, lsr #12 */
/* @0xb85f0 blx 0xfe2f4eb0 <b2_toiTime+0xfffffffffdb9ba0c> */
/* @0xb85f4 blx 0x89ee20 <b2_toiTime+0x14597c> */
/* @0xb85f8 bhs 0xf7400 <_ZN7CFontGMC2EiPKcbi+0x190> */
/* @0xb85fc rschi pc, r12, r0, asr #32 */
/* @0xb8600 strtmi r4, [r9], -r0, lsr #12 */
/* @0xb8604 blx 0x2074ec4 <b2_toiTime+0x191ba20> */
/* @0xb8608 blx 0x89ee34 <b2_toiTime+0x145990> */
/* @0xb860c bhs 0xf7814 <_ZN7CFontGMC2EP14YYEmbeddedFont+0x188> */
/* @0xb8610 rschi pc, r2, r0, asr #32 */
/* @0xb8614 strtmi r4, [r9], -r0, lsr #12 */
/* @0xb8618 andgt pc, r12, sp, asr #17 */
/* @0xb861c blx 0x1d74edc <b2_toiTime+0x161ba38> */
/* @0xb8620 .word 0xf10a9a09 */
/* @0xb8624 .word 0xf8dd0a0c */
/* @0xb8628 addlt r12, r0, #12 */
/* @0xb862c .word 0xf0402a00 */
/* @0xb8630 blx 0x498984 <g_prim_v+0x8978> */
/* @0xb8634 blx 0x4b7468 <SrcVerts+0x144ac> */
/* @0xb8638 .word 0xf109fc8c */
/* @0xb863c b 0x147aa48 <b2_toiTime+0xd215a4> */
/* @0xb8640 .word 0xf84a028b */
/* @0xb8644 b 0x148367c <b2_toiTime+0xd2a1d8> */
/* @0xb8648 .word 0xf84a028c */
/* @0xb864c andlt r2, r2, #8, #24 */
/* @0xb8650 .word 0xf84a0092 */
/* @0xb8654 strb r2, [r6, r4, lsl #24] */
/* @0xb8658 stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0xb865c andhs lr, r0, #44826624 */
/* @0xb8660 stm sp, {r0, r1, r4, r5, r11, sp, lr} */
/* @0xb8664 ldrtmi r0, [r8], -r4, lsr #32 */
/* @0xb8668 vorr d2, d15, d0 */
/* @0xb866c blls 0x337ab4 */
/* @0xb8670 blhs 0xd0838 <_Z20CopyRefArrayAndUnrefP23RefDynamicArrayOfRValuePv+0x1ec> */
/* @0xb8674 adcshi pc, r0, r0, asr #32 */
/* @0xb8678 ldrmi r10, [r11], r9, lsl #20 */
/* @0xb867c and r9, r1, r7, lsl #4 */
/* @0xb8680 bleq 0x134ab4 <_Z25F_AudioSetEmitterPositionR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0xb8684 ldrmi r6, [r11, #0x833] */
/* @0xb8688 adchi pc, r6, r0, lsl #1 */
/* @0xb868c strtmi r9, [r0], -r4, lsl #22 */
/* @0xb8690 b 0x149eeac <b2_toiTime+0xd45a08> */
/* @0xb8694 .word 0xf8d6190b */
/* @0xb8698 .word 0xf853a004 */
/* @0xb869c bl 0x33c750 */
/* @0xb86a0 ldrmi r0, [r1], #-2057 */
/* @0xb86a4 .word 0xf8fff22e */
/* @0xb86a8 stmdahs r0, {r0, r3, r12, pc} */
/* @0xb86ac addshi pc, r4, r0, asr #32 */
/* @0xb86b0 strtmi r4, [r9], -r0, lsr #12 */
/* @0xb86b4 blx 0xa74f74 <b2_toiTime+0x31bad0> */
/* @0xb86b8 andeq pc, r9, r10, asr #16 */
/* @0xb86bc blhs 0xdf2e8 <_Z5DoAndjPhPKhP6VMExec+0x378> */
/* @0xb86c0 addhi pc, r10, r0, asr #32 */
/* @0xb86c4 strtmi r4, [r9], -r0, lsr #12 */
/* @0xb86c8 blx 0x7f4f88 <b2_toiTime+0x9bae4> */
/* @0xb86cc andls r9, r6, r9, lsl #22 */
/* @0xb86d0 .word 0xf0402b00 */
/* @0xb86d4 strtmi r8, [r0], -r1, lsl #1 */
/* @0xb86d8 vmax.s32 d4, d14, d25 */
/* @0xb86dc bls 0x336f30 */
/* @0xb86e0 .word 0xf8c84603 */
/* @0xb86e4 bhs 0xb86fc <.text+0x172c> */
/* @0xb86e8 stmdbls r6, {r1, r2, r4, r5, r6, r8, r12, lr, pc} */
/* @0xb86ec stmdble r2, {r0, r7, r9, lr} */
/* @0xb86f0 movwls r2, #0x9308 */
/* @0xb86f4 ldmvs r1!, {r4, r5, r6, sp, lr, pc} ^ */
/* @0xb86f8 ldmle r9!, {r3, r7, r9, lr} ^ */
/* @0xb86fc eoreq lr, r4, sp, lsl #17 */
/* @0xb8700 .word 0x21044638 */
/* @0xb8704 stc2l p2, c15, [r3], {47} */
/* @0xb8708 .word 0xf8c89a09 */
/* @0xb870c bhs 0xb8734 <.text+0x1764> */
/* @0xb8710 .word 0xf8d8d162 */
/* @0xb8714 addsmi r3, r10, #4 */
/* @0xb8718 .word 0xf8d8d217 */
/* @0xb871c strtmi r3, [r0], -r8 */
/* @0xb8720 andls r4, r3, #42991616 */
/* @0xb8724 vcgt.s32 d9, d14, d2 */
/* @0xb8728 blls 0x176ee4 <_Z18GR_3D_Vertex_Colorfffjf+0x10> */
/* @0xb872c .word 0xf8439a03 */
/* @0xb8730 blls 0x2f87c0 <ps_hints_apply+0x73c0> */
/* @0xb8734 .word 0xd14f2b00 */
/* @0xb8738 .word 0x3008f8d8 */
/* @0xb873c eorne pc, r2, r3, asr r8 */
/* @0xb8740 addsmi r6, r9, #15925248 */
/* @0xb8744 andlo sp, r1, #212, #4 */
/* @0xb8748 .word 0xf85ae7e3 */
/* @0xb874c andhs lr, r0, #9 */
/* @0xb8750 stm sp, {r3, r4, r5, r9, r10, lr} */
/* @0xb8754 .word 0x21020024 */
/* @0xb8758 .word 0xf303fb0e */
/* @0xb875c ldc2 p2, c15, [r7], {47} */
/* @0xb8760 .word 0xf8c89b09 */
/* @0xb8764 blhs 0xb879c <.text+0x17cc> */
/* @0xb8768 ldm r8, {r1, r2, r4, r5, r8, r12, lr, pc} */
/* @0xb876c movtmi r0, #0xa006 */
/* @0xb8770 addle r4, r5, #805306377 */
/* @0xb8774 beq 0xf48b8 <_ZN18CExtensionConstant17LoadFromExeStreamEP7CStream+0x40> */
/* @0xb8778 bl 0x35ef98 <_ZTS12CDS_Priority+0xff0> */
/* @0xb877c ldrmi r0, [r2, #0x903] */
/* @0xb8780 strtmi sp, [r0], -pc, lsl #4 */
/* @0xb8784 movwls r10, #0x2909 */
/* @0xb8788 rfeib r12! */
/* @0xb878c blls 0x15efb8 <_Z15FacebookUserIdMv+0x3c> */
/* @0xb8790 bllt 0x365198 <_ZTS12CDS_Priority+0x71f0> */
/* @0xb8794 .word 0x200cf8d8 */
/* @0xb8798 beq 0x134bc8 <_Z16F_AudioPlaySoundR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0xb879c andseq pc, r9, r2, lsr #16 */
/* @0xb87a0 b 0x14b2750 <b2_toiTime+0xd592ac> */
/* @0xb87a4 bl 0xff2f94d0 <b2_toiTime+0xfffffffffeba002c> */
/* @0xb87a8 .word 0xf8d80a0a */
/* @0xb87ac bl 0x3407c4 */
/* @0xb87b0 addsmi r0, r1, #1073741826 */
/* @0xb87b4 strtmi sp, [r0], -lr, lsl #4 */
/* @0xb87b8 movwls r10, #0x2909 */
/* @0xb87bc .word 0xf97df22e */
/* @0xb87c0 blls 0x15efec <_Z15FacebookUserIdMv+0x70> */
/* @0xb87c4 .word 0xf8d8b942 */
/* @0xb87c8 .word 0xf109200c */
/* @0xb87cc sbcspl r0, r0, #16384 */
/* @0xb87d0 strb r3, [r10, r2, lsl #6]! */
/* @0xb87d4 strb r4, [r8, r11, asr #12] */
/* @0xb87d8 stmdbls r4, {r3, r4, r5, r9, r10, lr} */
/* @0xb87dc stc2 p2, c15, [r11, #184]! */
/* @0xb87e0 andlt r9, r11, r9, lsl #16 */
/* @0xb87e4 svchi #0xf0e8bd */
/* @0xb87e8 svcmi #0xf0e92d */
/* @0xb87ec ldrmi r11, [r5], -r9, lsl #1 */
/* @0xb87f0 .word 0x9c124698 */
/* @0xb87f4 cdpls p7, #0x1, c2, c3, c0, #0x0 */
/* @0xb87f8 mrsls r9, apsr */
/* @0xb87fc ldrtmi r4, [lr], #-1084 */
/* @0xb8800 eorshs pc, r5, r4, asr r8 */
/* @0xb8804 eorslo pc, r8, r4, asr r8 */
/* @0xb8808 stcle p2, c4, [r2, #-616] */
/* @0xb880c strbmi r4, [r5], -r11, lsr #12 */
/* @0xb8810 .word 0xf8544698 */
/* @0xb8814 .word 0xf854a035 */
/* @0xb8818 .word 0xf856b038 */
/* @0xb881c .word 0xf8563035 */
/* @0xb8820 ldrbmi r0, [r10, #0x38] */
/* @0xb8824 andeq lr, r3, #206848 */
/* @0xb8828 bl 0xff39d040 <b2_toiTime+0xfffffffffec43b9c> */
/* @0xb882c andls r0, r5, #0, #4 */
/* @0xb8830 addmi sp, r3, #-1073741823 */
/* @0xb8834 strlo sp, [r4, -lr] */
/* @0xb8838 bicsle r2, pc, r8, lsl #30 */
/* @0xb883c pop {r0, r3, r12, sp, pc} */
/* @0xb8840 bne 0xff0dc808 <b2_toiTime+0xfffffffffe983364> */
/* @0xb8844 smlabteq r11, r10, r11, lr */
/* @0xb8848 vcgt.s32 d9, d12, d1 */
/* @0xb884c blls 0x137524 <_Z18InitSoundFunctionsv+0xdf8> */
/* @0xb8850 and r4, r0, r2, lsl #12 */
/* @0xb8854 .word 0xf8dd2200 */
/* @0xb8858 stmdbls r7, {r3, r4, r12, pc} */
/* @0xb885c stclle p5, c4, [r10], #548 */
/* @0xb8860 eorseq pc, r9, r4, asr r8 */
/* @0xb8864 vstmiaeq r9, {s29, s30, s31} */
/* @0xb8868 .word 0xdc014550 */
/* @0xb886c and r9, r2, r4, lsl #18 */
/* @0xb8870 blle 0x149dd8 <_Z22F_D3DFrustumTestSphereR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0xb8874 strmi r9, [r8], #-2309 */
/* @0xb8878 ldrmi lr, [r1], -sp */
/* @0xb887c andeq lr, r0, r10, asr #23 */
/* @0xb8880 movwls r9, #0x1203 */
/* @0xb8884 andgt pc, r8, sp, asr #17 */
/* @0xb8888 blx 0xff0b5190 <b2_toiTime+0xfffffffffe95bcec> */
/* @0xb888c .word 0xf8dd9b01 */
/* @0xb8890 bls 0x1a88b8 <_Z19CreateDesktopWindowii+0x64> */
/* @0xb8894 .word 0xf8464418 */
/* @0xb8898 .word 0xf109000c */
/* @0xb889c ldrb r0, [r12, r1, lsl #18] */
/* @0xb88a0 andle r2, r12, r0, lsr #16 */
/* @0xb88a4 movweq pc, #0x91a0 */
/* @0xb88a8 stmdble r8, {r0, r8, r9, r11, sp} */
/* @0xb88ac andle r2, r6, sp, lsl #16 */
/* @0xb88b0 andle r2, r4, r12, lsl #16 */
/* @0xb88b4 .word 0x0001f1d0 */
/* @0xb88b8 andhs r11, r0, r8, lsr pc */
/* @0xb88bc andhs r4, r1, r0, ror r7 */
/* @0xb88c0 ldrblt r4, [r8, #0x770]! */
/* @0xb88c4 stmibvs r4, {r0, r1, r2, r3, r4, r9, r10, lr} ^ */
/* @0xb88c8 stmibvs r3, {r3, r5, r8, r10, sp} */
/* @0xb88cc blx 0x20a12e <_ZN12CDS_Priority6AssignEPS_+0x6b6> */
/* @0xb88d0 stmdblt r1!, {r0, r1, r8, r10, lr} ^ */
/* @0xb88d4 andle r4, r9, #172, #4 */
/* @0xb88d8 strheq pc, [r12], -r4 */
/* @0xb88dc vmin.s8 d20, d14, d17 */
/* @0xb88e0 strtlo pc, [r8], #-3301 */
/* @0xb88e4 .word 0xf8444438 */
/* @0xb88e8 .word 0xe7f30c18 */
/* @0xb88ec adcmi r11, r12, #248, #26 */
/* @0xb88f0 rfeib r4! */
/* @0xb88f4 ldrtmi r0, [r1], -lr */
/* @0xb88f8 ldc2l p2, c15, [r8], {78} */
/* @0xb88fc ldrtmi r3, [r8], #-1064 */
/* @0xb8900 .word 0x0c14f844 */
/* @0xb8904 ldcllt p7, c14, [r8, #972]! */
/* @0xb8908 ldrbmi lr, [r0, sp, lsr #18]! */
/* @0xb890c bvc 0xfeff6c54 <b2_toiTime+0xfffffffffe89d7b0> */
/* @0xb8910 beq 0xfeef6c58 <b2_toiTime+0xfffffffffe79d7b4> */
/* @0xb8914 .word 0xf1400744 */
/* @0xb8918 .word 0xf24280c5 */
/* @0xb891c blx 0x2060c6 <_ZN8CDS_List3SetEiP6RValueS1_+0x6> */
/* @0xb8920 strlo r7, [r12, #-0x501]! */
/* @0xb8924 smullsvs pc, r4, r5, r8 */
/* @0xb8928 .word 0xf0402e00 */
/* @0xb892c bhs 0xd8c20 <_ZN2VM18GetGlobalVariablesEP15Buffer_Standardb> */
/* @0xb8930 subsmi r11, r4, #744 */
/* @0xb8934 ldrmi r2, [r4], -r1, lsl #12 */
/* @0xb8938 .word 0x0c01f1b1 */
/* @0xb893c .word 0x0100f1dc */
/* @0xb8940 qaddeq lr, r1, r12 */
/* @0xb8944 .word 0xf010b111 */
/* @0xb8948 and r0, r1, r2, lsl #30 */
/* @0xb894c svceq #0x1f010 */
/* @0xb8950 stmdals r9, {r0, r4, r6, r8, r12, lr, pc} */
/* @0xb8954 strle r0, [r3, #-0x780] */
/* @0xb8958 ldchs p1, c11, [pc], #68 */
/* @0xb895c addshi pc, lr, r0, asr #6 */
/* @0xb8960 strbeq r9, [r9, r8, lsl #18] */
/* @0xb8964 mcrrhs p5, #0x0, sp, pc, c3 */
/* @0xb8968 strbhs r11, [r0], #-4056 */
/* @0xb896c ldchs p0, c14, [r8], #-8 */
/* @0xb8970 ldrths r11, [r8], #-4024 */
/* @0xb8974 stmdbhs r0, {r0, r3, r5, r7, r11, sp, lr} */
/* @0xb8978 addshi pc, r0, r0 */
/* @0xb897c bne 0x18d2e28 <b2_toiTime+0x1179984> */
/* @0xb8980 svclt #0xb82800 */
/* @0xb8984 stmdahs r7!, {r6, r9, lr} */
/* @0xb8988 ldmdbhs r0!, {r2, r10, r11, r12, lr, pc} */
/* @0xb898c strmi r11, [r12], -r12, lsr #31 */
/* @0xb8990 add r2, r3, r0, lsr r4 */
/* @0xb8994 .word 0xdc0f2cbf */
/* @0xb8998 teqeq pc, #4 */
/* @0xb899c .word 0xdd7d2b09 */
/* @0xb89a0 .word 0xf0242b1f */
/* @0xb89a4 .word 0xdc02023f */
/* @0xb89a8 streq pc, [r10], #-258 */
/* @0xb89ac blhs 0xe30b8c <b2_toiTime+0x6d76e8> */
/* @0xb89b0 .word 0xf102dc74 */
/* @0xb89b4 rsbs r0, r1, r6, lsr r4 */
/* @0xb89b8 vstrle s4, [r2, #-0] */
/* @0xb89bc .word 0xdc032b00 */
/* @0xb89c0 andsle lr, r5, r5, lsl r0 */
/* @0xb89c4 ble 0x5435cc <g_DecodeStringBuffer+0xb58> */
/* @0xb89c8 ldcvs p8, c6, [r2, #488] */
/* @0xb89cc stmdahs r9, {r4, r7, r8, r11, pc} */
/* @0xb89d0 ldmdahs sp, {r3, r8, r11, r12, lr, pc} */
/* @0xb89d4 .word 0xf1c0d80b */
/* @0xb89d8 tsths r4, lr, lsl r0 */
/* @0xb89dc vcge.s32 q10, q0, q4 */
/* @0xb89e0 .word 0x4603e998 */
/* @0xb89e4 rscvc lr, r3, #536576 */
/* @0xb89e8 rscvc lr, r3, #165888 */
/* @0xb89ec andhs lr, r0, #0 */
/* @0xb89f0 strtlo r1, [r0], #-2724 */
/* @0xb89f4 .word 0xf105e04c */
/* @0xb89f8 .word 0xf8d5090c */
/* @0xb89fc strtmi r8, [r3], -r8 */
/* @0xb8a00 andhs r2, r0, #411041792 */
/* @0xb8a04 beq 0x3f4b48 <SV_PixelShader+0xc0> */
/* @0xb8a08 andsle r4, r0, r2, asr #10 */
/* @0xb8a0c strls pc, [r2, -r10, lsl #22] */
/* @0xb8a10 .word 0xf8d73201 */
/* @0xb8a14 bl 0xff3e8a2c <b2_toiTime+0xfffffffffec8f588> */
/* @0xb8a18 svchs #0x704 */
/* @0xb8a1c rsbsmi r11, pc, #184, #30 */
/* @0xb8a20 svclt #0xa442af */
/* @0xb8a24 qadd8mi r4, pc, r12 */
/* @0xb8a28 ldrtmi r4, [sp], -r3, ror #12 */
/* @0xb8a2c addsmi lr, r12, #236, #14 */
/* @0xb8a30 eoreq pc, r0, #-1073741824 */
/* @0xb8a34 eorseq pc, pc, #34 */
/* @0xb8a38 eorlo sp, pc, #4, #22 */
/* @0xb8a3c svclt #0xb842a2 */
/* @0xb8a40 and r4, r3, r3, lsr #12 */
/* @0xb8a44 adcmi r3, r2, #192512 */
/* @0xb8a48 strtmi r11, [r3], -r8, asr #31 */
/* @0xb8a4c blhs 0x10a4ed8 <b2_toiTime+0x94ba34> */
/* @0xb8a50 .word 0xf103dd21 */
/* @0xb8a54 ands r0, r11, r0, lsl r4 */
/* @0xb8a58 strle r0, [r2, #-0x702] */
/* @0xb8a5c vldrle d2, [r10, #-252] */
/* @0xb8a60 blhs 0xcb0ab8 <b2_toiTime+0x557614> */
/* @0xb8a64 .word 0xf103dc02 */
/* @0xb8a68 and r0, sp, r0, asr #8 */
/* @0xb8a6c .word 0xdc0d2b7f */
/* @0xb8a70 .word 0xf0233316 */
/* @0xb8a74 blne 0x739778 <g_SWFvertbuff+0x666b0> */
/* @0xb8a78 svclt #0xb82a00 */
/* @0xb8a7c bhs 0x4893cc <g_States+0x3a04> */
/* @0xb8a80 stchs p13, c13, [pc], #-44 */
/* @0xb8a84 strblo sp, [r0], #-3082 */
/* @0xb8a88 and r1, r7, r4, rrx */
/* @0xb8a8c strteq pc, [r0], #-259 */
/* @0xb8a90 ldrteq pc, [pc], #-36 */
/* @0xb8a94 strbhs lr, [r0], #-2 */
/* @0xb8a98 ldrmi lr, [r12], -r0 */
/* @0xb8a9c rsbmi r11, r2, #-2147483645 */
/* @0xb8aa0 strtmi lr, [r2], -r0 */
/* @0xb8aa4 pop {r4, r9, r10, lr} */
/* @0xb8aa8 ldrblt r8, [r3, #-0x7f0]! */
/* @0xb8aac ldmvs r5, {r2, r3, r4, r9, r10, lr} */
/* @0xb8ab0 blvc 0x552c04 <gp_ActiveMaskObjects+0xdf3c> */
/* @0xb8ab4 andls r6, r0, #6684672 */
/* @0xb8ab8 andls r7, r1, #34816 */
/* @0xb8abc bne 0xffb7f68c <b2_toiTime+0xffffffffff4261e8> */
/* @0xb8ac0 .word 0xff22f7ff */
/* @0xb8ac4 adcvs r4, r0, r8, lsr #8 */
/* @0xb8ac8 ldcllt p0, c11, [r0, #-8]! */
/* @0xb8acc svcmi #0xf0e92d */
/* @0xb8ad0 strmi r11, [r10], sp, asr #1 */
/* @0xb8ad4 stmdbge r11, {r0, r1, r4, r7, r9, r10, lr} */
/* @0xb8ad8 strmi r2, [r4], -r0, lsl #4 */
/* @0xb8adc subspl r4, r0, r0, lsl r6 */
/* @0xb8ae0 .word 0xf5b23204 */
/* @0xb8ae4 mvnsle r7, r2, lsl #31 */
/* @0xb8ae8 stmdbvs r5!, {r1, r2, r4, r6, r8, r11, r12, pc} */
/* @0xb8aec stmibvs r0!, {r0, r3, r6, r7, r9, r11, r12} */
/* @0xb8af0 stmdbvs r7!, {r1, r2, r3, r5, r6, r11, r12} ^ */
/* @0xb8af4 stmvs r2!, {r1, r2, r7, r9, lr} */
/* @0xb8af8 bl 0xff1289e0 <b2_toiTime+0xfffffffffe9cf53c> */
/* @0xb8afc stmibvs r0!, {r8, r10} ^ */
/* @0xb8b00 addmi r1, r6, #8257536 */
/* @0xb8b04 bl 0xff128a2c <b2_toiTime+0xfffffffffe9cf588> */
/* @0xb8b08 bne 0xfebfa710 <b2_toiTime+0xfffffffffe4a126c> */
/* @0xb8b0c bne 0xff0adc78 <b2_toiTime+0xfffffffffe9547d4> */
/* @0xb8b10 mrrcle p2, #0xb, r4, r6, c13 */
/* @0xb8b14 mrrcle p15, #0x4, r2, r4, c0 */
/* @0xb8b18 stmdaeq r3, {r1, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0xb8b1c blge 0x3a0484 <ft_standard_glyph_names+0x1790> */
/* @0xb8b20 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0xb8b24 orreq lr, r5, #3072 */
/* @0xb8b28 blmi 0xa9d73c <b2_toiTime+0x344298> */
/* @0xb8b2c andeq lr, r5, #200, #22 */
/* @0xb8b30 ldrbtmi r9, [r11], #-520 */
/* @0xb8b34 blls 0x171d760 <b2_toiTime+0xfc42bc> */
/* @0xb8b38 ble 0xaca1a4 <b2_toiTime+0x370d00> */
/* @0xb8b3c strhne pc, [r8], -r6 */
/* @0xb8b40 strhhs pc, [r6], -r6 */
/* @0xb8b44 strheq pc, [r2], -r6 */
/* @0xb8b48 ldrbmi r1, [r1], -r10, lsl #21 */
/* @0xb8b4c vhsub.s8 d25, d14, d7 */
/* @0xb8b50 .word 0xf8ddfbad */
/* @0xb8b54 .word 0x2100c020 */
/* @0xb8b58 strbtmi r4, [r0], #-1112 */
/* @0xb8b5c andls r1, r4, #172032 */
/* @0xb8b60 .word 0xf0009b09 */
/* @0xb8b64 bls 0x17bc68 <_ZN12GraphicsPerf16BuildPerfDisplayEv+0x6c> */
/* @0xb8b68 .word 0xf8533001 */
/* @0xb8b6c ldmdapl r2, {r2, r3, r5, r12, sp} ^ */
/* @0xb8b70 ldrsbgt pc, [r12], -sp */
/* @0xb8b74 movwhs pc, #0xcb03 */
/* @0xb8b78 subspl r9, r3, r3, lsl #20 */
/* @0xb8b7c bls 0x1c4f94 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x7b4> */
/* @0xb8b80 adcsmi r4, r10, #33554432 */
/* @0xb8b84 .word 0xf109ddec */
/* @0xb8b88 strtlo r0, [r12], -r1, lsl #18 */
/* @0xb8b8c blls 0x16b2ae0 <b2_toiTime+0xf5963c> */
/* @0xb8b90 bl 0xff2e2bc4 <b2_toiTime+0xfffffffffeb89720> */
/* @0xb8b94 bl 0xff2ba3a8 <b2_toiTime+0xfffffffffeb60f04> */
/* @0xb8b98 .word 0xf850080b */
/* @0xb8b9c ldmdbne r3!, {r0, r2, r5, sp} ^ */
/* @0xb8ba0 addmi r6, r10, #99328 */
/* @0xb8ba4 mrsle sp, apsr */
/* @0xb8ba8 addmi r6, r11, #164864 */
/* @0xb8bac .word 0x63a3da06 */
/* @0xb8bb0 movweq lr, #0x5b08 */
/* @0xb8bb4 .word 0xf8c46362 */
/* @0xb8bb8 .word 0x6323a02c */
/* @0xb8bbc adcsmi r3, sp, #4194304 */
/* @0xb8bc0 sublt sp, sp, r11, ror #27 */
/* @0xb8bc4 svchi #0xf0e8bd */
/* @0xb8bc8 eoreq r7, lr, r6, lsr #22 */
/* @0xb8bcc push {r0, r9, r11, sp} */
/* @0xb8bd0 .word 0x469b4ff0 */
/* @0xb8bd4 .word 0xf8d1bf08 */
/* @0xb8bd8 .word 0xf04f800c */
/* @0xb8bdc svclt #0x84300 */
/* @0xb8be0 strmi r6, [lr], -sp, lsl #18 */
/* @0xb8be4 .word 0xf8d1bf18 */
/* @0xb8be8 addlt r8, r11, r4 */
/* @0xb8bec stmvs sp, {r3, r4, r8, r9, r10, r11, r12, sp, pc} */
/* @0xb8bf0 movtvs r4, #0x3604 */
/* @0xb8bf4 orrvs r2, r3, #0, #6 */
/* @0xb8bf8 movtpl pc, #0x4240 */
/* @0xb8bfc andne pc, r2, #3072 */
/* @0xb8c00 eorhi pc, r12, r0, asr #17 */
/* @0xb8c04 blls 0x5d1820 <g_SWFlineaavertbuff+0x7e758> */
/* @0xb8c08 ldmibvs r0!, {r3, r5, r9, r12, sp} */
/* @0xb8c0c ldmdavs r2, {r0, r4, r6, r7, r11, sp, lr} ^ */
/* @0xb8c10 andls r9, r7, #8, #2 */
/* @0xb8c14 ldmibvs r2!, {r0, r1, r2, r8, r11, r12, pc} ^ */
/* @0xb8c18 .word 0xf8cb2900 */
/* @0xb8c1c andsvs r8, sp, r0 */
/* @0xb8c20 sbcshi pc, lr, r0, asr #6 */
/* @0xb8c24 strhvc pc, [r12], -r2 */
/* @0xb8c28 .word 0xf04f2301 */
/* @0xb8c2c ldrtmi r0, [r10], r8, lsr #24 */
/* @0xb8c30 ble 0x389644 <_ZTS13C_UTF16String+0x206f0> */
/* @0xb8c34 .word 0x2103fb0c */
/* @0xb8c38 rfeib r1! */
/* @0xb8c3c addmi r1, pc, #12 */
/* @0xb8c40 strmi r11, [pc], -r8, lsr #31 */
/* @0xb8c44 svclt #0xb8458a */
/* @0xb8c48 ldrb r4, [r1, r10, lsl #13]! */
/* @0xb8c4c vorr.i32 q2, #0x70000 */
/* @0xb8c50 strbmi r8, [r1], -r7, asr #1 */
/* @0xb8c54 vmin.s8 d20, d14, d24 */
/* @0xb8c58 strbmi pc, [r1], -r9, lsr #22 */
/* @0xb8c5c eorvs r4, r0, r8, lsr #8 */
/* @0xb8c60 vmin.s8 q10, q7, q0 */
/* @0xb8c64 stmdavs r1!, {r0, r1, r5, r8, r9, r11, r12, sp, lr, pc} */
/* @0xb8c68 andseq pc, pc, #33 */
/* @0xb8c6c teqeq pc, #33 */
/* @0xb8c70 .word 0xf10260a3 */
/* @0xb8c74 .word 0xf8c40e20 */
/* @0xb8c78 .word 0x6122e014 */
/* @0xb8c7c rsbvs r4, r0, r8, lsr #8 */
/* @0xb8c80 teqeq pc, #0, #2 */
/* @0xb8c84 .word 0xf0234586 */
/* @0xb8c88 rscvs r0, r3, pc, lsr r3 */
/* @0xb8c8c tsteq pc, #32 */
/* @0xb8c90 smulbtvs r0, r8, pc */
/* @0xb8c94 addmi r6, r11, #-1073741784 */
/* @0xb8c98 streq pc, [r0, #-0x103]! */
/* @0xb8c9c movweq lr, #0xbc1 */
/* @0xb8ca0 strhvs r11, [r1, r8]! */
/* @0xb8ca4 svclt #0xd82b40 */
/* @0xb8ca8 bl 0xff151234 <b2_toiTime+0xfffffffffe9f7d90> */
/* @0xb8cac svclt #0xd80205 */
/* @0xb8cb0 blhs 0xfe0d1338 <b2_toiTime+0xfffffffffd977e94> */
/* @0xb8cb4 stmdbvs r1!, {r5, r7, r8, r11, sp, lr} ^ */
/* @0xb8cb8 bl 0xff111454 <b2_toiTime+0xfffffffffe9b7fb0> */
/* @0xb8cbc eorvs r0, r3, #0, #2 */
/* @0xb8cc0 adcvs r6, r2, #268435462 */
/* @0xb8cc4 blhs 0x18efce4 <b2_toiTime+0x1196840> */
/* @0xb8cc8 .word 0xf04fbfd4 */
/* @0xb8ccc .word 0xf04f0e04 */
/* @0xb8cd0 and r0, r1, r8, lsl #28 */
/* @0xb8cd4 cdpeq p0, #0x1, c15, c0, c15, #0x2 */
/* @0xb8cd8 andeq lr, r3, lr, asr #23 */
/* @0xb8cdc bl 0x1896e8 <_Z11loadTextureP7Texture+0xfc> */
/* @0xb8ce0 svclt #0xb8010e */
/* @0xb8ce4 addmi r6, r10, #96, #4 */
/* @0xb8ce8 andeq pc, r3, #79 */
/* @0xb8cec adcvs r11, r1, #200, #30 */
/* @0xb8cf0 svclt #0x48435a */
/* @0xb8cf4 bvs 0x1905508 <b2_toiTime+0x11ac064> */
/* @0xb8cf8 addsmi r1, r1, #146 */
/* @0xb8cfc rsbvs r11, r2, #184, #30 */
/* @0xb8d00 .word 0xf8d42205 */
/* @0xb8d04 cmpmi r3, #36 */
/* @0xb8d08 movwlo r11, #0x3f48 */
/* @0xb8d0c addsne r6, r11, r2, lsr #21 */
/* @0xb8d10 bl 0xff289780 <b2_toiTime+0xfffffffffeb302dc> */
/* @0xb8d14 svclt #0xc8020a */
/* @0xb8d18 andls r6, r9, #805306378 */
/* @0xb8d1c ldrmi r6, [r12, #0xaa3] */
/* @0xb8d20 bvs 0x8efe48 <b2_toiTime+0x1969a4> */
/* @0xb8d24 muleq r12, r4, r8 */
/* @0xb8d28 bl 0xff3ca340 <b2_toiTime+0xfffffffffec70e9c> */
/* @0xb8d2c ldrmi r0, [r5], #-1280 */
/* @0xb8d30 stmdbvs r1!, {r0, r1, r8, r9, r11, r12, lr, pc} */
/* @0xb8d34 ble 0x2c9770 <_ZN7b2World5SolveERK10b2TimeStep+0x134> */
/* @0xb8d38 stmdbvs r1!, {r1, sp, lr, pc} ^ */
/* @0xb8d3c stcle p2, c4, [r4, #-564] */
/* @0xb8d40 bl 0x17fa7c <_Z18GR_3D_Light_Enableib+0x15c> */
/* @0xb8d44 strmi r0, [sp], -r5, lsl #18 */
/* @0xb8d48 ldrmi lr, [r9], r0 */
/* @0xb8d4c bl 0xff0c97a8 <b2_toiTime+0xfffffffffe970304> */
/* @0xb8d50 svclt #0xb4000c */
/* @0xb8d54 andeq lr, r2, #201728 */
/* @0xb8d58 andeq lr, r5, #198656 */
/* @0xb8d5c stmdbls r9, {r0, r3, r4, r7, r8, r10, lr} */
/* @0xb8d60 bl 0xff328c38 <b2_toiTime+0xfffffffffebcf794> */
/* @0xb8d64 bl 0xff179978 <b2_toiTime+0xfffffffffea204d4> */
/* @0xb8d68 ldrmi r0, [r10], #-777 */
/* @0xb8d6c andsgt pc, r0, sp, asr #17 */
/* @0xb8d70 vhsub.s32 d9, d12, d5 */
/* @0xb8d74 bl 0x2f6ffc <ps_hints_apply+0x5bfc> */
/* @0xb8d78 ldrtmi r0, [r8], -r0, lsl #6 */
/* @0xb8d7c ldrmi r9, [r9], -r6, lsl #6 */
/* @0xb8d80 blx 0xfe5f56c0 <b2_toiTime+0xfffffffffde9c21c> */
/* @0xb8d84 .word 0x210a9a05 */
/* @0xb8d88 .word 0xf8cd9b06 */
/* @0xb8d8c movtmi r9, #0xa000 */
/* @0xb8d90 mrsls r9, apsr */
/* @0xb8d94 qadd16mi r4, r11, r9 */
/* @0xb8d98 bls 0x2dd5a4 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x244> */
/* @0xb8d9c bl 0xff0dd5ac <b2_toiTime+0xfffffffffe984108> */
/* @0xb8da0 strtmi r0, [r0], -r5, lsl #28 */
/* @0xb8da4 .word 0xf7ff4672 */
/* @0xb8da8 .word 0xf8ddfe91 */
/* @0xb8dac .word 0xf10cc010 */
/* @0xb8db0 ldr r0, [r3, r1, lsl #24]! */
/* @0xb8db4 ldrtmi r6, [r8], -r5, ror #21 */
/* @0xb8db8 bl 0xff2d3a50 <b2_toiTime+0xfffffffffeb7a5ac> */
/* @0xb8dbc strbmi r0, [r1], -r5, lsl #16 */
/* @0xb8dc0 blx 0x1df5700 <b2_toiTime+0x169c25c> */
/* @0xb8dc4 strtmi r4, [r0], #-1601 */
/* @0xb8dc8 beq 0xff0f70e8 <b2_toiTime+0xfffffffffe99dc44> */
/* @0xb8dcc vmin.s8 q10, q7, q0 */
/* @0xb8dd0 bls 0x5f778c <g_SWFaavertbuff+0x246c4> */
/* @0xb8dd4 .word 0xf8c64420 */
/* @0xb8dd8 .word 0xf8cb0ac4 */
/* @0xb8ddc andsvs r5, r4, r0 */
/* @0xb8de0 pop {r0, r1, r3, r12, sp, pc} */
/* @0xb8de4 strdeq r8, r9, [r0], -r0 */
/* @0xb8de8 subpl pc, r4, #64, #4 */
/* @0xb8dec svcmi #0xf0e92d */
/* @0xb8df0 bleq 0xbf4f34 <b2_toiTime+0x49ba90> */
/* @0xb8df4 addlt r6, r5, r5, asr #19 */
/* @0xb8df8 strmi r6, [r9], r3, lsl #19 */
/* @0xb8dfc andeq pc, r1, r2, lsl #22 */
/* @0xb8e00 svclt #0x142900 */
/* @0xb8e04 andhs r2, r4, #8, #4 */
/* @0xb8e08 .word 0x6c049202 */
/* @0xb8e0c blx 0x393c32 <ft_adobe_glyph_list+0x330e> */
/* @0xb8e10 adcsmi r4, r12, #1835008 */
/* @0xb8e14 addshi pc, r7, r0, lsl #1 */
/* @0xb8e18 blx 0x1416c2 <_Z17YYGML_action_pathP9CInstanceifib+0x26> */
/* @0xb8e1c blmi 0x138d630 <b2_toiTime+0xc3418c> */
/* @0xb8e20 blne 0xf5d634 <b2_toiTime+0x804190> */
/* @0xb8e24 blx 0x17d076 <_ZN12GraphicsPerf19oprintf_wrap_decodeEiijjPKcz+0x27a> */
/* @0xb8e28 strlo pc, [r8, #-0xa02]! */
/* @0xb8e2c .word 0xf1a59a03 */
/* @0xb8e30 addsmi r0, r10, #40, #6 */
/* @0xb8e34 addhi pc, r7, r0, asr #4 */
/* @0xb8e38 stclo p8, c15, [r8], #-212 */
/* @0xb8e3c andsmi r9, r3, #8192 */
/* @0xb8e40 .word 0x06dbd1f3 */
/* @0xb8e44 .word 0xf855d4f1 */
/* @0xb8e48 .word 0xf1b91c20 */
/* @0xb8e4c .word 0xf8550f01 */
/* @0xb8e50 svclt #0x63c24 */
/* @0xb8e54 .word 0x6c1af935 */
/* @0xb8e58 rfedb r5! */
/* @0xb8e5c rfeib r4! */
/* @0xb8e60 blne 0xfe2fce68 <b2_toiTime+0xfffffffffdba39c4> */
/* @0xb8e64 blle 0x18326c <_ZN8Graphics12UpdateRegionEPviiii+0x2c> */
/* @0xb8e68 bne 0x1792ff4 <b2_toiTime+0x1039b50> */
/* @0xb8e6c and r6, r9, r1, lsr #17 */
/* @0xb8e70 stcne p9, c15, [r12], #-220 */
/* @0xb8e74 stmdbhs r0, {r0, r4, r5, r6, r9, r11, r12} */
/* @0xb8e78 .word 0xf857db06 */
/* @0xb8e7c bne 0x177ff24 <b2_toiTime+0x1026a80> */
/* @0xb8e80 stcne p8, c15, [r4], #-348 */
/* @0xb8e84 sub r1, pc, r8, asr r8 */
/* @0xb8e88 svceq #0x8f1ba */
/* @0xb8e8c movwhs sp, #0xc11 */
/* @0xb8e90 ble 0x1ca3e4 <_Z26Command_CollisionRectangleP9CInstanceffffibb+0x94> */
/* @0xb8e94 .word 0xf103fb0b */
/* @0xb8e98 adcsmi r5, r1, #1552 */
/* @0xb8e9c blx 0x3afac2 <error_g0017+0x8766> */
/* @0xb8ea0 stmdane r0!, {r0, r1, r8, r12, sp, lr, pc} ^ */
/* @0xb8ea4 adcsmi r5, r1, #1552 */
/* @0xb8ea8 stmvs r0, {r3, r4, r8, r12, lr, pc} */
/* @0xb8eac movwlo lr, #0x103c */
/* @0xb8eb0 ldrbmi lr, [r1], -lr, ror #15 */
/* @0xb8eb4 addmi r2, r11, #0, #6 */
/* @0xb8eb8 stmne r8, {r4, r9, r11, r12, lr, pc} ^ */
/* @0xb8ebc blx 0x37cfc6 <_ZTS13C_UTF16String+0x14072> */
/* @0xb8ec0 bl 0x1f7ec8 <_Z19GV_BackgroundHTiledP9CInstanceiP6RValue+0x24> */
/* @0xb8ec4 rfedb r4! */
/* @0xb8ec8 strbmi r12, [r6, #-0xc]! */
/* @0xb8ecc strmi sp, [r1], -r1, lsl #20 */
/* @0xb8ed0 stcle p7, c14, [r1, #-964] */
/* @0xb8ed4 strb r1, [lr, r3, asr #24]! */
/* @0xb8ed8 mla r5, r0, r8, r6 */
/* @0xb8edc .word 0xf303fb0b */
/* @0xb8ee0 stceq p1, c15, [r12], #-652 */
/* @0xb8ee4 stmdaeq r12, {r2, r8, r9, r11, sp, lr, pc} */
/* @0xb8ee8 ldrsbne pc, [r0], -r8 */
/* @0xb8eec stmne r1!, {r0, r7, r8, r11, r12, sp, pc} ^ */
/* @0xb8ef0 .word 0x0008f8d8 */
/* @0xb8ef4 cdppl p8, #0xe, c6, c1, c10, #0x4 */
/* @0xb8ef8 andlo pc, r12, r4, lsr r9 */
/* @0xb8efc .word 0xf8cd1a10 */
/* @0xb8f00 bne 0xff328f18 <b2_toiTime+0xfffffffffebcfa74> */
/* @0xb8f04 .word 0xffd7f22b */
/* @0xb8f08 andseq pc, r0, r8, asr #17 */
/* @0xb8f0c .word 0xc004f8dd */
/* @0xb8f10 .word 0x3008f8d8 */
/* @0xb8f14 andeq pc, r12, r4, lsr r9 */
/* @0xb8f18 ldrsbne pc, [r0], -r8 */
/* @0xb8f1c movwls r1, #0x1a30 */
/* @0xb8f20 .word 0xf9c4f24e */
/* @0xb8f24 ldrmi r9, [r8], #-2817 */
/* @0xb8f28 svceq #0xf1b9 */
/* @0xb8f2c .word 0xf845d102 */
/* @0xb8f30 and r0, r1, r8, lsl r12 */
/* @0xb8f34 .word 0x0c14f845 */
/* @0xb8f38 stclo p8, c15, [r8], #-212 */
/* @0xb8f3c tstmi r3, #8192 */
/* @0xb8f40 stclo p8, c15, [r8], #-148 */
/* @0xb8f44 andlt lr, r5, r1, ror r7 */
/* @0xb8f48 svchi #0xf0e8bd */
/* @0xb8f4c blt 0xc5bde0 <b2_toiTime+0x50293c> */
/* @0xb8f50 ldrbmi lr, [r0, sp, lsr #18]! */
/* @0xb8f54 blo 0xfeff729c <b2_toiTime+0xfffffffffe89ddf8> */
/* @0xb8f58 beq 0xfeef72a0 <b2_toiTime+0xfffffffffe79ddfc> */
/* @0xb8f5c .word 0xf1400745 */
/* @0xb8f60 vst4.32 {d24, d25, d26, d27}, [pc], r6 */
/* @0xb8f64 bhs 0xce2f0 <_ZN5CCodeD2Ev+0x38> */
/* @0xb8f68 movwlo pc, #0x1b04 */
/* @0xb8f6c subsmi r11, r2, #744 */
/* @0xb8f70 .word 0x0c01f04f */
/* @0xb8f74 .word 0x0c00f04f */
/* @0xb8f78 .word 0x332c1e4c */
/* @0xb8f7c .word 0x41614261 */
/* @0xb8f80 .word 0x8008f8d3 */
/* @0xb8f84 .word 0xf010b111 */
/* @0xb8f88 and r0, r1, r2, lsl #30 */
/* @0xb8f8c svceq #0x1f010 */
/* @0xb8f90 .word 0xf1b8d126 */
/* @0xb8f94 andle r0, r9, r0, lsl #30 */
/* @0xb8f98 bne 0xff51340c <b2_toiTime+0xfffffffffedb9f68> */
/* @0xb8f9c stmdbhs lr, {r0, r1, r2, r5, r8, r12, sp} ^ */
/* @0xb8fa0 blhs 0xceefb8 <b2_toiTime+0x595b14> */
/* @0xb8fa4 ldrmi r11, [r10], -r12, lsr #31 */
/* @0xb8fa8 subs r2, r12, r0, lsr r2 */
/* @0xb8fac .word 0xdc042a35 */
/* @0xb8fb0 teqeq r6, #-2147483600 */
/* @0xb8fb4 rsbeq lr, r3, #2048 */
/* @0xb8fb8 bhs 0xff0b1114 <b2_toiTime+0xfffffffffe957c70> */
/* @0xb8fbc .word 0xf002dc53 */
/* @0xb8fc0 blhs 0x2f9cc4 <ps_hints_apply+0x88c4> */
/* @0xb8fc4 blhs 0x630508 <g_SWFaavertbuff+0x5d440> */
/* @0xb8fc8 teqeq pc, r2, lsr #32 */
/* @0xb8fcc .word 0xf101dc02 */
/* @0xb8fd0 sub r0, r8, r10, lsl #4 */
/* @0xb8fd4 blhs 0x387c84 <_ZTS13C_UTF16String+0x1ed30> */
/* @0xb8fd8 .word 0xf101d845 */
/* @0xb8fdc sub r0, r2, r6, lsr r2 */
/* @0xb8fe0 stmdbeq r12, {r0, r1, r8, r12, sp, lr, pc} */
/* @0xb8fe4 ldrmi r2, [r3], -r2, ror #10 */
/* @0xb8fe8 .word 0xf04f2400 */
/* @0xb8fec strbmi r0, [r4, #-0xa0c] */
/* @0xb8ff0 blx 0x36d032 <_ZTS13C_UTF16String+0x40de> */
/* @0xb8ff4 strlo r9, [r1], #-1540 */
/* @0xb8ff8 blne 0xff6531dc <b2_toiTime+0xfffffffffeef9d38> */
/* @0xb8ffc svclt #0xb82e00 */
/* @0xb9000 adcmi r4, lr, #1610612743 */
/* @0xb9004 ldrmi r11, [pc], -r4, lsr #31 */
/* @0xb9008 ldrtmi r4, [r11], -lr, lsr #12 */
/* @0xb900c .word 0xe7ee4635 */
/* @0xb9010 .word 0xf103429a */
/* @0xb9014 .word 0xf0240420 */
/* @0xb9018 blle 0x1ba11c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x278> */
/* @0xb901c addsmi r3, r4, #788529152 */
/* @0xb9020 .word 0x4613bfb8 */
/* @0xb9024 stclo p0, c14, [pc], #-12 */
/* @0xb9028 svclt #0xc84294 */
/* @0xb902c .word 0xb1214613 */
/* @0xb9030 vldrle d2, [r7, #-252] */
/* @0xb9034 andseq pc, r0, #-1073741824 */
/* @0xb9038 streq lr, [r2, -lr] */
/* @0xb903c blhs 0x10ae44c <b2_toiTime+0x954fa8> */
/* @0xb9040 and sp, r12, r0, lsl sp */
/* @0xb9044 .word 0xdc032b2f */
/* @0xb9048 subeq pc, r0, #-1073741824 */
/* @0xb904c and r1, r10, r2, asr r0 */
/* @0xb9050 .word 0xdc042b7f */
/* @0xb9054 andseq pc, r6, #-1073741824 */
/* @0xb9058 eorseq pc, pc, #34 */
/* @0xb905c .word 0xf103e003 */
/* @0xb9060 ldrb r0, [r9, r0, lsr #4]! */
/* @0xb9064 .word 0xf1bc2240 */
/* @0xb9068 andle r0, r0, r0, lsl #30 */
/* @0xb906c ssaxmi r4, r0, r2 */
/* @0xb9070 .word 0x87f0e8bd */
/* @0xb9074 svcmi #0xf7e92d */
/* @0xb9078 .word 0xf8d04691 */
/* @0xb907c selmi r2, r8, r8 */
/* @0xb9080 stmdbls r12, {r2, r3, r4, r9, r10, lr} */
/* @0xb9084 .word 0x0c04f012 */
/* @0xb9088 .word 0xf898d111 */
/* @0xb908c ldrbeq r3, [r10, r12] */
/* @0xb9090 .word 0xf899d508 */
/* @0xb9094 ldrbeq r3, [r11, r12] */
/* @0xb9098 stmdbhs r1, {r2, r8, r10, r12, lr, pc} */
/* @0xb909c ldrhs r11, [r1, #-0xf14]! */
/* @0xb90a0 and r2, r5, r7, lsr r5 */
/* @0xb90a4 svclt #0x142901 */
/* @0xb90a8 ldrhs r2, [sp, #-0x53b]! */
/* @0xb90ac strbhs lr, [r0, #-0x0] */
/* @0xb90b0 .word 0xa004f8d9 */
/* @0xb90b4 .word 0xb004f8d8 */
/* @0xb90b8 andgt pc, r4, sp, asr #17 */
/* @0xb90bc andeq lr, r10, #207872 */
/* @0xb90c0 .word 0xff46f7ff */
/* @0xb90c4 movweq lr, #0xab0b */
/* @0xb90c8 .word 0xc004f8dd */
/* @0xb90cc bicsvc lr, r3, #3072 */
/* @0xb90d0 .word 0x0363eb04 */
/* @0xb90d4 sbcsvc lr, r0, #0, #22 */
/* @0xb90d8 .word 0x0362eba3 */
/* @0xb90dc eorseq pc, pc, #19 */
/* @0xb90e0 ldmdane lr, {r3, r4, r6, r12, lr, pc} */
/* @0xb90e4 shadd16eq pc, pc, r6 */
/* @0xb90e8 adcmi sp, r8, #86 */
/* @0xb90ec strbeq pc, [r0], #-450 */
/* @0xb90f0 addmi sp, r6, #1280 */
/* @0xb90f4 adcsmi sp, r4, #335872 */
/* @0xb90f8 rsbsmi sp, r4, #3008 */
/* @0xb90fc ldchs p0, c14, [pc, #-316]! */
/* @0xb9100 adcmi sp, r10, #2304 */
/* @0xb9104 adcmi sp, r12, #303104 */
/* @0xb9108 adcmi sp, lr, #72, #20 */
/* @0xb910c .word 0xf1c6da46 */
/* @0xb9110 adcmi r0, r10, #64, #4 */
/* @0xb9114 .word 0xf000da42 */
/* @0xb9118 svchs #0x1f073f */
/* @0xb911c adcsmi sp, r12, #4, #24 */
/* @0xb9120 adcsmi sp, lr, #60, #26 */
/* @0xb9124 and sp, r1, r10, lsr sp */
/* @0xb9128 strbeq pc, [r0, -r5, asr #3] */
/* @0xb912c blne 0xff93fdd8 <b2_toiTime+0xffffffffff1e6934> */
/* @0xb9130 bl 0xff249b7c <b2_toiTime+0xfffffffffeaf06d8> */
/* @0xb9134 bl 0xff27a150 <b2_toiTime+0xfffffffffeb20cac> */
/* @0xb9138 svclt #0xd80606 */
/* @0xb913c adcmi r4, r6, #-1610612732 */
/* @0xb9140 rsbsmi r11, r4, #216, #30 */
/* @0xb9144 strbvc lr, [r2, #0xa82]! */
/* @0xb9148 strbvc lr, [r2, #0xba5]! */
/* @0xb914c mvnvc lr, r4, lsl #21 */
/* @0xb9150 mvnvc lr, r1, lsr #23 */
/* @0xb9154 svclt #0xd8428d */
/* @0xb9158 .word 0xf1bc4614 */
/* @0xb915c .word 0xd1080f00 */
/* @0xb9160 .word 0xdc052c0e */
/* @0xb9164 andeq pc, sp, #111 */
/* @0xb9168 svclt #0xb84294 */
/* @0xb916c and r4, r0, r4, lsl r6 */
/* @0xb9170 strtmi r2, [r3], #-1038 */
/* @0xb9174 ldrmi r4, [r8], #-1491 */
/* @0xb9178 .word 0xf8c8bfb6 */
/* @0xb917c .word 0xf8c83008 */
/* @0xb9180 .word 0xf8c90008 */
/* @0xb9184 strtmi r0, [r0], -r8 */
/* @0xb9188 .word 0xf8c9bfa8 */
/* @0xb918c andlt r3, r3, r8 */
/* @0xb9190 svchi #0xf0e8bd */
/* @0xb9194 and r4, r2, r4, lsl r6 */
/* @0xb9198 and r4, r0, r4, lsr r6 */
/* @0xb919c .word 0xf1bc2400 */
/* @0xb91a0 sbcsle r0, pc, r0, lsl #30 */
/* @0xb91a4 push {r0, r2, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0xb91a8 .word 0x46044ff8 */
/* @0xb91ac ldmibvs r0, {r3, r7, r9, r10, lr} ^ */
/* @0xb91b0 addmi r6, r8, #3555328 */
/* @0xb91b4 ldrmi sp, [r1], -r2, lsl #26 */
/* @0xb91b8 .word 0x460b461a */
/* @0xb91bc ldmibvs r8, {r0, r1, r2, r4, r7, r8, r11, sp, lr} */
/* @0xb91c0 ldmibvs lr, {r0, r2, r4, r6, r7, r8, r11, sp, lr} ^ */
/* @0xb91c4 bl 0xff209be8 <b2_toiTime+0xfffffffffeab0744> */
/* @0xb91c8 bl 0xff23b5ec <b2_toiTime+0xfffffffffeae2148> */
/* @0xb91cc andle r0, r8, r0, lsl #20 */
/* @0xb91d0 ldrhle r4, [r0, -r5] */
/* @0xb91d4 stmibvs r3!, {r0, r2, sp, lr, pc} ^ */
/* @0xb91d8 .word 0xdc0542ab */
/* @0xb91dc .word 0x61a3444b */
/* @0xb91e0 strbmi r3, [r4, #-0x428] */
/* @0xb91e4 strd sp, lr, [r4], -r7 */
/* @0xb91e8 svclt #0xac42b3 */
/* @0xb91ec shsaxmi r4, r11, r3 */
/* @0xb91f0 pop {r0, r2, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0xb91f4 blne 0xff0dd1dc <b2_toiTime+0xfffffffffe983d38> */
/* @0xb91f8 .word 0xf22b1b71 */
/* @0xb91fc pkhtbmi pc, r3, r12, asr #28 */
/* @0xb9200 ldmdale r0, {r2, r6, r8, r10, lr} */
/* @0xb9204 adcmi r6, r8, #224, #18 */
/* @0xb9208 strbmi sp, [r8], #-3073 */
/* @0xb920c adcsmi lr, r0, #8 */
/* @0xb9210 ldrbmi sp, [r0], #-2817 */
/* @0xb9214 blne 0x10f122c <b2_toiTime+0x997d88> */
/* @0xb9218 .word 0xf24e4659 */
/* @0xb921c ldrtmi pc, [r8], #-2119 */
/* @0xb9220 strtlo r6, [r8], #-416 */
/* @0xb9224 pop {r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0xb9228 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xb922c .word 0xf04f4ff0 */
/* @0xb9230 stmibvs r5, {r3, r5, r8, r11} ^ */
/* @0xb9234 stmibvs r3, {r0, r2, r7, r12, sp, pc} */
/* @0xb9238 smlabbls r2, r2, r10, r6 */
/* @0xb923c stmdbpl r3, {r0, r3, r8, r9, r11, r12, sp, lr, pc} */
/* @0xb9240 bl 0x153b54 <_Z16InitIAPFunctionsv+0x680> */
/* @0xb9244 movwls r0, #0x3383 */
/* @0xb9248 stmdblt r9!, {r0, r1, r3, r5, r9, r10, lr} ^ */
/* @0xb924c andle r4, r8, #314572800 */
/* @0xb9250 .word 0x33286919 */
/* @0xb9254 .word 0x1c10f843 */
/* @0xb9258 stcne p8, c15, [r4], #-332 */
/* @0xb925c .word 0x1c0cf843 */
/* @0xb9260 .word 0xf04fe7f4 */
/* @0xb9264 and r0, r12, r4, lsl #20 */
/* @0xb9268 andle r4, r8, #314572800 */
/* @0xb926c .word 0x33286959 */
/* @0xb9270 .word 0x1c10f843 */
/* @0xb9274 stcne p8, c15, [r0], #-332 */
/* @0xb9278 .word 0x1c0cf843 */
/* @0xb927c .word 0xf04fe7f4 */
/* @0xb9280 andls r0, r1, #8, #20 */
/* @0xb9284 bls 0x19fe90 <_Z11Option_LoadPhjS_+0x95c> */
/* @0xb9288 subsle r4, r8, #805306377 */
/* @0xb928c .word 0xf8529a01 */
/* @0xb9290 .word 0xf8d66b04 */
/* @0xb9294 ldrtmi r8, [r4], -r4, lsr #32 */
/* @0xb9298 strbmi r9, [r4, #-0x201] */
/* @0xb929c stmdahi r3!, {r1, r4, r5, r6, r7, r11, r12, lr, pc} */
/* @0xb92a0 svceq #0xaea13 */
/* @0xb92a4 strtmi sp, [r3], r1 */
/* @0xb92a8 strtlo lr, [r8], #-7 */
/* @0xb92ac stchi p7, c14, [r3, #-980]! */
/* @0xb92b0 svceq #0x3ea1a */
/* @0xb92b4 strmi sp, [r7], -r5 */
/* @0xb92b8 strbmi r4, [r4, #-0x63c] */
/* @0xb92bc eoreq pc, r8, r4, lsl #2 */
/* @0xb92c0 .word 0x4603d3f5 */
/* @0xb92c4 strbmi r4, [r7, #-0x607] */
/* @0xb92c8 ldmdahi r10!, {r1, r2, r3, r11, r12, lr, pc} */
/* @0xb92cc svceq #0xaea12 */
/* @0xb92d0 strlo sp, [r8, -r1, lsl #2]! */
/* @0xb92d4 .word 0xf1a7e7f7 */
/* @0xb92d8 addmi r0, r8, #40, #2 */
/* @0xb92dc strtmi sp, [r2], -r12, ror #17 */
/* @0xb92e0 .word 0xf7ff463b */
/* @0xb92e4 strb pc, [r7, r0, ror #30]! */
/* @0xb92e8 tstle r3, r12, asr r5 */
/* @0xb92ec stmibvs r2!, {r0, r5, r7, r8, r11, sp, lr} ^ */
/* @0xb92f0 sbcle r1, r7, r10, lsl #21 */
/* @0xb92f4 andle r4, r5, #1610612746 */
/* @0xb92f8 qsub8lo r6, r8, r1 */
/* @0xb92fc .word 0xf8464411 */
/* @0xb9300 .word 0xe7f71c10 */
/* @0xb9304 pople {r0, r1, r6, r8, r10, lr} */
/* @0xb9308 .word 0x332869d9 */
/* @0xb930c .word 0xf8434411 */
/* @0xb9310 .word 0xe7f71c10 */
/* @0xb9314 andle r4, r6, #68, #10 */
/* @0xb9318 stmdale r4, {r6, r8, r10, lr} */
/* @0xb931c strtmi r4, [r2], -r1, asr #12 */
/* @0xb9320 .word 0xf7ff465b */
/* @0xb9324 strmi pc, [r11, #0xf40]! */
/* @0xb9328 .word 0xf1abd9ac */
/* @0xb932c addmi r0, lr, #40, #2 */
/* @0xb9330 ldrtmi sp, [r0], -r8, lsr #17 */
/* @0xb9334 ldrbmi r4, [r11], -r2, lsr #12 */
/* @0xb9338 .word 0xff35f7ff */
/* @0xb933c blls 0x1731cc <_Z24GR_Text_Draw_TransformedffPKciifff+0x164> */
/* @0xb9340 strbmi r11, [sp, #-0x933] */
/* @0xb9344 stmibvs r11!, {r0, r1, r3, r9, r12, lr, pc} */
/* @0xb9348 .word 0xf8453528 */
/* @0xb934c .word 0xe7f83c18 */
/* @0xb9350 andle r4, r4, #322961408 */
/* @0xb9354 strlo r6, [r8, #-0x9ab]! */
/* @0xb9358 .word 0x3c14f845 */
/* @0xb935c strdlt lr, pc, [r5], -r8 */
/* @0xb9360 svchi #0xf0e8bd */
/* @0xb9364 movwhs r11, #0x57f */
/* @0xb9368 strmi r6, [r4], -r5, lsl #18 */
/* @0xb936c movwls r4, #0x360e */
/* @0xb9370 qasxmi r11, r11, sp */
/* @0xb9374 strhle r4, [r8], -r3 */
/* @0xb9378 rfeda r1! */
/* @0xb937c movwlo r1, #0x1013 */
/* @0xb9380 svclt #0x2842a9 */
/* @0xb9384 adclt r4, sp, #13631488 */
/* @0xb9388 movwhs lr, #0x7f4 */
/* @0xb938c movwls r10, #0x903 */
/* @0xb9390 .word 0x91014610 */
/* @0xb9394 .word 0x2102461a */
/* @0xb9398 .word 0xf22e1c6b */
/* @0xb939c blls 0x1b8d84 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi+0xcc> */
/* @0xb93a0 ldmdblt r3!, {r5, r6, r7, sp, lr} ^ */
/* @0xb93a4 rsbseq r1, r2, r3, ror lr */
/* @0xb93a8 .word 0xf1a22b00 */
/* @0xb93ac blle 0x239bbc <_ZN13CPhysicsWorld17ParticleGroupPolyEv+0x24> */
/* @0xb93b0 bpl 0xfe2d363c <b2_toiTime+0xfffffffffdb7a198> */
/* @0xb93b4 .word 0xf82168e1 */
/* @0xb93b8 bllo 0x105400 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x14> */
/* @0xb93bc strdvs lr, pc, [r5, -r4]! */
/* @0xb93c0 stmdals r3, {r1, r2, r5, r6, r8, sp, lr} */
/* @0xb93c4 ldcllt p0, c11, [r0, #-16]! */
/* @0xb93c8 ldr r0, [pc, #0x4] */
/* @0xb93cc add r0, pc, r0 */
/* @0xb93d0 b 0xb6508 <__cxa_finalize@plt> */
/* @0xb93d4 eorseq r8, r3, r12, lsr #24 */
/* @0xb93d8 push {r4, lr} */
/* @0xb93dc ldr r4, [pc, #0x44] */
/* @0xb93e0 ldr r1, [pc, #0x44] */
/* @0xb93e4 add r4, pc, r4 */
/* @0xb93e8 ldr r2, [pc, #0x40] */
/* @0xb93ec ldr r3, [pc, #0x40] */
/* @0xb93f0 ldr r0, [r4, r1] */
/* @0xb93f4 ldr r1, [r4, r2] */
/* @0xb93f8 ldr r2, [pc, #0x38] */
/* @0xb93fc add r1, r1, #8 */
/* @0xb9400 str r1, [r0] */
/* @0xb9404 add r2, pc, r2 */
/* @0xb9408 ldr r1, [r4, r3] */
/* @0xb940c bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9410 mov r0, #0 */
/* @0xb9414 bl 0xc4438 <_Z10InitRandomj> */
/* @0xb9418 ldr r3, [pc, #0x1c] */
/* @0xb941c ldr r3, [r4, r3] */
/* @0xb9420 str r0, [r3] */
/* @0xb9424 pop {r4, pc} */
/* @0xb9428 eorseq r8, r3, r12, ror #16 */
/* @0xb942c .word 0xffffbd20 */
/* @0xb9430 .word 0xffffbd24 */
/* @0xb9434 .word 0xffffbd28 */
/* @0xb9438 ldrshteq r8, [r3], -r4 */
/* @0xb943c .word 0xffffbd18 */
/* @0xb9440 push {r3, r4, r5, lr} */
/* @0xb9444 ldr r4, [pc, #0x5c] */
/* @0xb9448 ldr r1, [pc, #0x5c] */
/* @0xb944c add r4, pc, r4 */
/* @0xb9450 ldr r2, [pc, #0x58] */
/* @0xb9454 ldr r5, [pc, #0x58] */
/* @0xb9458 ldr r0, [r4, r1] */
/* @0xb945c ldr r3, [pc, #0x54] */
/* @0xb9460 add r5, pc, r5 */
/* @0xb9464 ldr r2, [r4, r2] */
/* @0xb9468 add r2, r2, #8 */
/* @0xb946c str r2, [r0] */
/* @0xb9470 mov r2, r5 */
/* @0xb9474 ldr r1, [r4, r3] */
/* @0xb9478 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb947c ldr r0, [pc, #0x38] */
/* @0xb9480 ldr r1, [pc, #0x38] */
/* @0xb9484 mov r2, r5 */
/* @0xb9488 ldr r3, [pc, #0x34] */
/* @0xb948c ldr r0, [r4, r0] */
/* @0xb9490 ldr r1, [r4, r1] */
/* @0xb9494 add r1, r1, #8 */
/* @0xb9498 str r1, [r0] */
/* @0xb949c ldr r1, [r4, r3] */
/* @0xb94a0 pop {r3, r4, r5, lr} */
/* @0xb94a4 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb94a8 eorseq r8, r3, r4, lsl #16 */
/* @0xb94ac .word 0xffffbd3c */
/* @0xb94b0 .word 0xffffbd40 */
/* @0xb94b4 mlaseq r3, r8, r11, r8 */
/* @0xb94b8 .word 0xffffbd44 */
/* @0xb94bc .word 0xffffbd48 */
/* @0xb94c0 .word 0xffffbd4c */
/* @0xb94c4 .word 0xffffbd50 */
/* @0xb94c8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xb94cc mov r5, #8 */
/* @0xb94d0 ldr r7, [pc, #0xac] */
/* @0xb94d4 mov r1, r5 */
/* @0xb94d8 ldr r3, [pc, #0xa8] */
/* @0xb94dc mov r4, #0 */
/* @0xb94e0 add r7, pc, r7 */
/* @0xb94e4 ldr r9, [pc, #0xa0] */
/* @0xb94e8 ldr r6, [r7, r3] */
/* @0xb94ec add r9, pc, r9 */
/* @0xb94f0 mov r0, r6 */
/* @0xb94f4 str r4, [r6, #0x4] */
/* @0xb94f8 str r4, [r6] */
/* @0xb94fc str r4, [r6, #0xc] */
/* @0xb9500 str r5, [r6, #0x8] */
/* @0xb9504 bl 0xd1b3c <_ZN18cARRAY_OF_POINTERS9setLengthEi> */
/* @0xb9508 ldr r3, [pc, #0x80] */
/* @0xb950c mov r2, r9 */
/* @0xb9510 mov r0, r6 */
/* @0xb9514 ldr r8, [r7, r3] */
/* @0xb9518 mov r1, r8 */
/* @0xb951c bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9520 ldr r3, [pc, #0x6c] */
/* @0xb9524 mov r1, r5 */
/* @0xb9528 ldr r6, [r7, r3] */
/* @0xb952c mov r0, r6 */
/* @0xb9530 stmib r6, {r4, r5} */
/* @0xb9534 str r4, [r6] */
/* @0xb9538 str r4, [r6, #0xc] */
/* @0xb953c bl 0xd1b3c <_ZN18cARRAY_OF_POINTERS9setLengthEi> */
/* @0xb9540 mov r2, r9 */
/* @0xb9544 mov r1, r8 */
/* @0xb9548 mov r0, r6 */
/* @0xb954c bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9550 ldr r3, [pc, #0x40] */
/* @0xb9554 mov r1, r5 */
/* @0xb9558 ldr r6, [r7, r3] */
/* @0xb955c mov r0, r6 */
/* @0xb9560 stmib r6, {r4, r5} */
/* @0xb9564 str r4, [r6] */
/* @0xb9568 str r4, [r6, #0xc] */
/* @0xb956c bl 0xd1b3c <_ZN18cARRAY_OF_POINTERS9setLengthEi> */
/* @0xb9570 mov r0, r6 */
/* @0xb9574 mov r1, r8 */
/* @0xb9578 mov r2, r9 */
/* @0xb957c pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xb9580 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9584 eorseq r8, r3, r0, ror r7 */
/* @0xb9588 .word 0xffffbf4c */
/* @0xb958c eorseq r8, r3, r12, lsl #22 */
/* @0xb9590 .word 0xffffbf6c */
/* @0xb9594 .word 0xffffbf50 */
/* @0xb9598 .word 0xffffbf70 */
/* @0xb959c ldr r2, [pc, #0x2c] */
/* @0xb95a0 mov r0, #420 */
/* @0xb95a4 ldr r3, [pc, #0x28] */
/* @0xb95a8 ldr r1, [pc, #0x28] */
/* @0xb95ac ldr r2, [pc, r2] */
/* @0xb95b0 add r3, pc, r3 */
/* @0xb95b4 ldr r1, [pc, r1] */
/* @0xb95b8 add r1, r1, #8 */
/* @0xb95bc str r3, [r3] */
/* @0xb95c0 str r1, [r2] */
/* @0xb95c4 str r3, [r3, #0x4] */
/* @0xb95c8 str r0, [r3, #0x8] */
/* @0xb95cc bx lr */
/* @0xb95d0 eorseq r4, r3, r8, lsl #15 */
/* @0xb95d4 eorseq r0, r12, r4, lsl #24 */
/* @0xb95d8 ldrhteq r4, [r3], -r8 */
/* @0xb95dc push {r3, r4, r5, lr} */
/* @0xb95e0 mov r2, #70 */
/* @0xb95e4 ldr r4, [pc, #0xa8] */
/* @0xb95e8 mov r3, #1 */
/* @0xb95ec ldr r1, [pc, #0xa4] */
/* @0xb95f0 mov r0, #96 */
/* @0xb95f4 add r4, pc, r4 */
/* @0xb95f8 mov r5, #0 */
/* @0xb95fc add r1, pc, r1 */
/* @0xb9600 mov lr, #8 */
/* @0xb9604 mov r12, #7 */
/* @0xb9608 str lr, [r4] */
/* @0xb960c str r12, [r4, #0x8] */
/* @0xb9610 str r5, [r4, #0x10] */
/* @0xb9614 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xb9618 mov r2, #96 */
/* @0xb961c mov r1, r5 */
/* @0xb9620 str r0, [r4, #0x10] */
/* @0xb9624 bl 0xb65b0 <memset@plt> */
/* @0xb9628 ldr r2, [r4] */
/* @0xb962c vldr s15, [pc, #92] */
/* @0xb9630 str r5, [r4, #0x4] */
/* @0xb9634 cmp r2, r5 */
/* @0xb9638 vmov s13, r2 */
/* @0xb963c vcvt.f32.s32 s14, s13 */
/* @0xb9640 vmul.f32 s15, s14, s15 */
/* @0xb9644 vcvt.s32.f32 s15, s15 */
/* @0xb9648 vstr s15, [r4, #12] */
/* @0xb964c ble 0xb9670 <.text+0x26a0> */
/* @0xb9650 ldr r3, [r4, #0x10] */
/* @0xb9654 add r2, r2, r2, lsl #1 */
/* @0xb9658 mov r1, r5 */
/* @0xb965c add r2, r3, r2, lsl #2 */
/* @0xb9660 str r1, [r3, #0x8] */
/* @0xb9664 add r3, r3, #12 */
/* @0xb9668 cmp r3, r2 */
/* @0xb966c bne 0xb9660 <.text+0x2690> */
/* @0xb9670 ldr r1, [pc, #0x24] */
/* @0xb9674 ldr r0, [pc, #0x24] */
/* @0xb9678 ldr r2, [pc, #0x24] */
/* @0xb967c ldr r1, [pc, r1] */
/* @0xb9680 add r0, pc, r0 */
/* @0xb9684 add r2, pc, r2 */
/* @0xb9688 pop {r3, r4, r5, lr} */
/* @0xb968c b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9690 svclo #0x19999a */
/* @0xb9694 eorseq r5, r12, r4, lsr #27 */
/* @0xb9698 eoreq r7, r7, r4, lsr r10 */
/* @0xb969c eorseq r4, r3, r8, lsl #14 */
/* @0xb96a0 eorseq r5, r12, r8, lsl sp */
/* @0xb96a4 eorseq r8, r3, r4, ror r9 */
/* @0xb96a8 ldr r0, [pc, #0x4] */
/* @0xb96ac ldr r0, [pc, r0] */
/* @0xb96b0 b 0x13aaac <_ZN10yyFindDataC2Ev> */
/* @0xb96b4 ldrsbteq r5, [r3], -r12 */
/* @0xb96b8 ldr r1, [pc, #0x2c] */
/* @0xb96bc movw r2, #0x4f80 */
/* @0xb96c0 movt r2, #0xc7c3 */
/* @0xb96c4 ldr r1, [pc, r1] */
/* @0xb96c8 add r3, r1, #16 */
/* @0xb96cc add r1, r1, #112 */
/* @0xb96d0 str r2, [r3, #-0x10] */
/* @0xb96d4 add r3, r3, #16 */
/* @0xb96d8 str r2, [r3, #-0x1c] */
/* @0xb96dc str r2, [r3, #-0x18] */
/* @0xb96e0 cmp r3, r1 */
/* @0xb96e4 bne 0xb96d0 <.text+0x2700> */
/* @0xb96e8 bx lr */
/* @0xb96ec eorseq r5, r3, r0, ror pc */
/* @0xb96f0 ldr r0, [pc, #0x4] */
/* @0xb96f4 ldr r0, [pc, r0] */
/* @0xb96f8 b 0x167e50 <_ZN18RenderStateManagerC2Ev> */
/* @0xb96fc eorseq r4, r3, r4, lsl #12 */
/* @0xb9700 push {r4, lr} */
/* @0xb9704 ldr r4, [pc, #0x24] */
/* @0xb9708 ldr r4, [pc, r4] */
/* @0xb970c mov r0, r4 */
/* @0xb9710 bl 0x16dce4 <_ZN14CCameraManagerC2Ev> */
/* @0xb9714 ldr r1, [pc, #0x18] */
/* @0xb9718 ldr r2, [pc, #0x18] */
/* @0xb971c mov r0, r4 */
/* @0xb9720 ldr r1, [pc, r1] */
/* @0xb9724 add r2, pc, r2 */
/* @0xb9728 pop {r4, lr} */
/* @0xb972c b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9730 eorseq r4, r3, r12, ror #10 */
/* @0xb9734 eorseq r6, r3, r0, asr #22 */
/* @0xb9738 ldrsbteq r8, [r3], -r4 */
/* @0xb973c push {r3, r4, r5, lr} */
/* @0xb9740 mov r2, #187 */
/* @0xb9744 ldr r4, [pc, #0x50] */
/* @0xb9748 mov r3, #1 */
/* @0xb974c ldr r1, [pc, #0x4c] */
/* @0xb9750 mov r0, #1024 */
/* @0xb9754 ldr r4, [pc, r4] */
/* @0xb9758 mov r12, #127 */
/* @0xb975c add r1, pc, r1 */
/* @0xb9760 mov r5, #0 */
/* @0xb9764 str r12, [r4, #0x4] */
/* @0xb9768 str r5, [r4, #0x8] */
/* @0xb976c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xb9770 mov r1, r5 */
/* @0xb9774 mov r2, #1024 */
/* @0xb9778 str r0, [r4] */
/* @0xb977c bl 0xb65b0 <memset@plt> */
/* @0xb9780 ldr r1, [pc, #0x1c] */
/* @0xb9784 mov r0, r4 */
/* @0xb9788 ldr r2, [pc, #0x18] */
/* @0xb978c ldr r1, [pc, r1] */
/* @0xb9790 add r2, pc, r2 */
/* @0xb9794 pop {r3, r4, r5, lr} */
/* @0xb9798 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb979c ldrhteq r4, [r3], -r12 */
/* @0xb97a0 eoreq r1, r9, r8, asr #24 */
/* @0xb97a4 eorseq r6, r3, r4, lsl #22 */
/* @0xb97a8 eorseq r8, r3, r8, ror #16 */
/* @0xb97ac ldr r0, [pc, #0x58] */
/* @0xb97b0 mvn r1, #0 */
/* @0xb97b4 ldr r12, [pc, #0x54] */
/* @0xb97b8 add r0, pc, r0 */
/* @0xb97bc str r4, [sp, #-0x4]! */
/* @0xb97c0 ldr r12, [pc, r12] */
/* @0xb97c4 mov r4, #0 */
/* @0xb97c8 add r3, r0, #32 */
/* @0xb97cc add r0, r0, #2832 */
/* @0xb97d0 mov r2, r4 */
/* @0xb97d4 str r4, [r12] */
/* @0xb97d8 str r4, [r12, #0x4] */
/* @0xb97dc str r2, [r3, #-0x1c] */
/* @0xb97e0 add r3, r3, #28 */
/* @0xb97e4 str r2, [r3, #-0x34] */
/* @0xb97e8 str r2, [r3, #-0x30] */
/* @0xb97ec str r2, [r3, #-0x2c] */
/* @0xb97f0 str r2, [r3, #-0x28] */
/* @0xb97f4 str r1, [r3, #-0x24] */
/* @0xb97f8 str r1, [r3, #-0x20] */
/* @0xb97fc cmp r3, r0 */
/* @0xb9800 bne 0xb97dc <.text+0x280c> */
/* @0xb9804 ldr r4, [sp], #4 */
/* @0xb9808 bx lr */
/* @0xb980c eorseq r8, lr, r4, asr #24 */
/* @0xb9810 eorseq r6, r3, r12, lsr #25 */
/* @0xb9814 push {r3, r4, r5, r6, r7, lr} */
/* @0xb9818 mov r2, #187 */
/* @0xb981c ldr r5, [pc, #0xf0] */
/* @0xb9820 mov r3, #1 */
/* @0xb9824 ldr lr, [pc, #0xec] */
/* @0xb9828 mov r0, #4096 */
/* @0xb982c add r5, pc, r5 */
/* @0xb9830 ldr r1, [pc, #0xe4] */
/* @0xb9834 movw r12, #0x1ff */
/* @0xb9838 mov r4, #0 */
/* @0xb983c ldr r6, [r5, lr] */
/* @0xb9840 add r1, pc, r1 */
/* @0xb9844 ldr r7, [pc, #0xd4] */
/* @0xb9848 str r12, [r6, #0x4] */
/* @0xb984c add r7, pc, r7 */
/* @0xb9850 str r4, [r6, #0x8] */
/* @0xb9854 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xb9858 mov r1, r4 */
/* @0xb985c mov r2, #4096 */
/* @0xb9860 str r0, [r6] */
/* @0xb9864 bl 0xb65b0 <memset@plt> */
/* @0xb9868 ldr r3, [pc, #0xb4] */
/* @0xb986c mov r2, r7 */
/* @0xb9870 mov r0, r6 */
/* @0xb9874 ldr r1, [r5, r3] */
/* @0xb9878 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb987c mov r0, #512 */
/* @0xb9880 bl 0xcef4c <_Z7YYAlloci> */
/* @0xb9884 ldr r3, [pc, #0x9c] */
/* @0xb9888 mov r1, r4 */
/* @0xb988c mov r2, #512 */
/* @0xb9890 ldr r6, [r5, r3] */
/* @0xb9894 str r0, [r6] */
/* @0xb9898 bl 0xb65b0 <memset@plt> */
/* @0xb989c ldr r3, [pc, #0x88] */
/* @0xb98a0 mov r1, #128 */
/* @0xb98a4 str r4, [r6, #0x8] */
/* @0xb98a8 mov r0, r6 */
/* @0xb98ac str r4, [r6, #0xc] */
/* @0xb98b0 mov r2, r7 */
/* @0xb98b4 str r1, [r6, #0x4] */
/* @0xb98b8 ldr r1, [r5, r3] */
/* @0xb98bc bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb98c0 ldr r3, [pc, #0x68] */
/* @0xb98c4 ldr r4, [r5, r3] */
/* @0xb98c8 add r6, r4, #352 */
/* @0xb98cc mov r0, r4 */
/* @0xb98d0 add r4, r4, #88 */
/* @0xb98d4 bl 0x190f58 <_ZN13CGCGenerationC2Ev> */
/* @0xb98d8 cmp r4, r6 */
/* @0xb98dc bne 0xb98cc <.text+0x28fc> */
/* @0xb98e0 ldr r1, [pc, #0x4c] */
/* @0xb98e4 mov r0, #0 */
/* @0xb98e8 ldr r2, [pc, #0x48] */
/* @0xb98ec add r1, pc, r1 */
/* @0xb98f0 add r2, pc, r2 */
/* @0xb98f4 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb98f8 ldr r3, [pc, #0x3c] */
/* @0xb98fc ldr r2, [pc, #0x3c] */
/* @0xb9900 ldr r3, [r5, r3] */
/* @0xb9904 ldr r2, [r5, r2] */
/* @0xb9908 add r2, r2, #8 */
/* @0xb990c str r2, [r3] */
/* @0xb9910 pop {r3, r4, r5, r6, r7, pc} */
/* @0xb9914 eorseq r8, r3, r4, lsr #8 */
/* @0xb9918 .word 0xffffbff4 */
/* @0xb991c eoreq r3, r9, r12, ror #8 */
/* @0xb9920 eorseq r8, r3, r12, lsr #15 */
/* @0xb9924 .word 0xffffea40 */
/* @0xb9928 .word 0xffffc014 */
/* @0xb992c .word 0xffffea44 */
/* @0xb9930 .word 0xffffc010 */
/* @0xb9934 andeq r7, sp, r0, asr #15 */
/* @0xb9938 eorseq r8, r3, r8, lsl #14 */
/* @0xb993c .word 0xffffea20 */
/* @0xb9940 .word 0xffffea48 */
/* @0xb9944 push {r4, r5, r6, lr} */
/* @0xb9948 mov r5, #0 */
/* @0xb994c ldr r4, [pc, #0x60] */
/* @0xb9950 ldr r6, [pc, #0x60] */
/* @0xb9954 add r4, pc, r4 */
/* @0xb9958 ldr r1, [pc, #0x5c] */
/* @0xb995c add r6, pc, r6 */
/* @0xb9960 mov r0, r4 */
/* @0xb9964 ldr r1, [pc, r1] */
/* @0xb9968 mov r2, r6 */
/* @0xb996c str r5, [r4] */
/* @0xb9970 str r5, [r4, #0x4] */
/* @0xb9974 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9978 ldr r1, [pc, #0x40] */
/* @0xb997c mov r2, r6 */
/* @0xb9980 add r0, r4, #8 */
/* @0xb9984 str r5, [r4, #0x8] */
/* @0xb9988 ldr r1, [pc, r1] */
/* @0xb998c str r5, [r4, #0xc] */
/* @0xb9990 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9994 ldr r1, [pc, #0x28] */
/* @0xb9998 mov r2, r6 */
/* @0xb999c add r0, r4, #16 */
/* @0xb99a0 str r5, [r4, #0x10] */
/* @0xb99a4 ldr r1, [pc, r1] */
/* @0xb99a8 str r5, [r4, #0x14] */
/* @0xb99ac pop {r4, r5, r6, lr} */
/* @0xb99b0 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb99b4 subeq r8, r8, r4, ror r12 */
/* @0xb99b8 mlaseq r3, r12, r6, r8 */
/* @0xb99bc eorseq r6, r3, r4, ror #29 */
/* @0xb99c0 eorseq r6, r3, r4, asr #29 */
/* @0xb99c4 eorseq r6, r3, r12, lsr #29 */
/* @0xb99c8 push {r3, r4, r5, r6, r7, lr} */
/* @0xb99cc mov r4, #0 */
/* @0xb99d0 ldr r5, [pc, #0x19c] */
/* @0xb99d4 mov r6, #1 */
/* @0xb99d8 ldr r3, [pc, #0x198] */
/* @0xb99dc add r5, pc, r5 */
/* @0xb99e0 ldr r7, [pc, #0x194] */
/* @0xb99e4 ldr r1, [pc, #0x194] */
/* @0xb99e8 ldr r3, [r5, r3] */
/* @0xb99ec add r7, pc, r7 */
/* @0xb99f0 mov r2, r7 */
/* @0xb99f4 str r4, [r3, #0x4] */
/* @0xb99f8 mov r0, r3 */
/* @0xb99fc str r4, [r3] */
/* @0xb9a00 str r4, [r3, #0x8] */
/* @0xb9a04 str r6, [r3, #0xc] */
/* @0xb9a08 ldr r1, [r5, r1] */
/* @0xb9a0c bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9a10 ldr r3, [pc, #0x16c] */
/* @0xb9a14 ldr r1, [pc, #0x16c] */
/* @0xb9a18 mov r2, r7 */
/* @0xb9a1c ldr r3, [r5, r3] */
/* @0xb9a20 str r4, [r3, #0x4] */
/* @0xb9a24 mov r0, r3 */
/* @0xb9a28 str r4, [r3] */
/* @0xb9a2c str r4, [r3, #0x8] */
/* @0xb9a30 str r6, [r3, #0xc] */
/* @0xb9a34 ldr r1, [r5, r1] */
/* @0xb9a38 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9a3c ldr r3, [pc, #0x148] */
/* @0xb9a40 ldr r1, [pc, #0x148] */
/* @0xb9a44 mov r2, r7 */
/* @0xb9a48 ldr r3, [r5, r3] */
/* @0xb9a4c str r4, [r3, #0x4] */
/* @0xb9a50 mov r0, r3 */
/* @0xb9a54 str r4, [r3] */
/* @0xb9a58 str r4, [r3, #0x8] */
/* @0xb9a5c str r6, [r3, #0xc] */
/* @0xb9a60 ldr r1, [r5, r1] */
/* @0xb9a64 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9a68 ldr r3, [pc, #0x124] */
/* @0xb9a6c ldr r1, [pc, #0x124] */
/* @0xb9a70 mov r2, r7 */
/* @0xb9a74 ldr r3, [r5, r3] */
/* @0xb9a78 str r4, [r3, #0x4] */
/* @0xb9a7c mov r0, r3 */
/* @0xb9a80 str r4, [r3] */
/* @0xb9a84 str r4, [r3, #0x8] */
/* @0xb9a88 str r6, [r3, #0xc] */
/* @0xb9a8c ldr r1, [r5, r1] */
/* @0xb9a90 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9a94 ldr r3, [pc, #0x100] */
/* @0xb9a98 ldr r1, [pc, #0x100] */
/* @0xb9a9c mov r2, r7 */
/* @0xb9aa0 ldr r3, [r5, r3] */
/* @0xb9aa4 str r4, [r3, #0x4] */
/* @0xb9aa8 mov r0, r3 */
/* @0xb9aac str r4, [r3] */
/* @0xb9ab0 str r4, [r3, #0x8] */
/* @0xb9ab4 str r6, [r3, #0xc] */
/* @0xb9ab8 ldr r1, [r5, r1] */
/* @0xb9abc bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9ac0 ldr r3, [pc, #0xdc] */
/* @0xb9ac4 ldr r1, [pc, #0xdc] */
/* @0xb9ac8 mov r2, r7 */
/* @0xb9acc ldr r3, [r5, r3] */
/* @0xb9ad0 str r4, [r3, #0x4] */
/* @0xb9ad4 mov r0, r3 */
/* @0xb9ad8 str r4, [r3] */
/* @0xb9adc str r4, [r3, #0x8] */
/* @0xb9ae0 str r6, [r3, #0xc] */
/* @0xb9ae4 ldr r1, [r5, r1] */
/* @0xb9ae8 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9aec ldr r3, [pc, #0xb8] */
/* @0xb9af0 ldr r1, [pc, #0xb8] */
/* @0xb9af4 mov r2, r7 */
/* @0xb9af8 ldr r3, [r5, r3] */
/* @0xb9afc str r4, [r3, #0x4] */
/* @0xb9b00 mov r0, r3 */
/* @0xb9b04 str r4, [r3] */
/* @0xb9b08 str r4, [r3, #0x8] */
/* @0xb9b0c str r6, [r3, #0xc] */
/* @0xb9b10 ldr r1, [r5, r1] */
/* @0xb9b14 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9b18 ldr r3, [pc, #0x94] */
/* @0xb9b1c ldr r1, [pc, #0x94] */
/* @0xb9b20 mov r2, r7 */
/* @0xb9b24 ldr r3, [r5, r3] */
/* @0xb9b28 str r4, [r3, #0x4] */
/* @0xb9b2c mov r0, r3 */
/* @0xb9b30 str r4, [r3] */
/* @0xb9b34 str r4, [r3, #0x8] */
/* @0xb9b38 str r6, [r3, #0xc] */
/* @0xb9b3c ldr r1, [r5, r1] */
/* @0xb9b40 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9b44 ldr r3, [pc, #0x70] */
/* @0xb9b48 ldr r1, [pc, #0x70] */
/* @0xb9b4c mov r2, r7 */
/* @0xb9b50 ldr r3, [r5, r3] */
/* @0xb9b54 str r6, [r3, #0xc] */
/* @0xb9b58 mov r0, r3 */
/* @0xb9b5c str r4, [r3, #0x4] */
/* @0xb9b60 str r4, [r3] */
/* @0xb9b64 str r4, [r3, #0x8] */
/* @0xb9b68 ldr r1, [r5, r1] */
/* @0xb9b6c pop {r3, r4, r5, r6, r7, lr} */
/* @0xb9b70 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9b74 eorseq r8, r3, r4, ror r2 */
/* @0xb9b78 .word 0xffffec0c */
/* @0xb9b7c eorseq r8, r3, r12, lsl #12 */
/* @0xb9b80 .word 0xffffee94 */
/* @0xb9b84 .word 0xffffec10 */
/* @0xb9b88 .word 0xffffee98 */
/* @0xb9b8c .word 0xffffec14 */
/* @0xb9b90 .word 0xffffee9c */
/* @0xb9b94 .word 0xffffec18 */
/* @0xb9b98 .word 0xffffeea0 */
/* @0xb9b9c .word 0xffffec1c */
/* @0xb9ba0 .word 0xffffeea4 */
/* @0xb9ba4 .word 0xffffec20 */
/* @0xb9ba8 .word 0xffffeea8 */
/* @0xb9bac .word 0xffffec24 */
/* @0xb9bb0 .word 0xffffeeac */
/* @0xb9bb4 .word 0xffffec28 */
/* @0xb9bb8 .word 0xffffeeb0 */
/* @0xb9bbc .word 0xffffec2c */
/* @0xb9bc0 .word 0xffffeeb4 */
/* @0xb9bc4 push {r3, lr} */
/* @0xb9bc8 mov r12, #0 */
/* @0xb9bcc ldr r3, [pc, #0x3c] */
/* @0xb9bd0 ldr r1, [pc, #0x3c] */
/* @0xb9bd4 ldr r3, [pc, r3] */
/* @0xb9bd8 ldr r2, [pc, #0x38] */
/* @0xb9bdc ldr r1, [pc, r1] */
/* @0xb9be0 add r2, pc, r2 */
/* @0xb9be4 mov r0, r3 */
/* @0xb9be8 str r12, [r3] */
/* @0xb9bec str r12, [r3, #0x4] */
/* @0xb9bf0 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9bf4 ldr r0, [pc, #0x20] */
/* @0xb9bf8 mov r3, #0 */
/* @0xb9bfc mov r2, #0 */
/* @0xb9c00 ldr r0, [pc, r0] */
/* @0xb9c04 strd r2, r3, [r0, #24] */
/* @0xb9c08 pop {r3, lr} */
/* @0xb9c0c b 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0xb9c10 eorseq r6, r3, r4, asr pc */
/* @0xb9c14 eorseq r6, r3, r12, ror #24 */
/* @0xb9c18 eorseq r8, r3, r8, lsl r4 */
/* @0xb9c1c eorseq r3, r3, r12, lsr #26 */
/* @0xb9c20 ldr r2, [pc, #0x2c] */
/* @0xb9c24 mov r0, #396 */
/* @0xb9c28 ldr r3, [pc, #0x28] */
/* @0xb9c2c mov r1, #408 */
/* @0xb9c30 ldr r2, [pc, r2] */
/* @0xb9c34 ldr r3, [pc, r3] */
/* @0xb9c38 str r2, [r2] */
/* @0xb9c3c str r2, [r2, #0x4] */
/* @0xb9c40 str r0, [r2, #0x8] */
/* @0xb9c44 str r3, [r3] */
/* @0xb9c48 str r3, [r3, #0x4] */
/* @0xb9c4c str r1, [r3, #0x8] */
/* @0xb9c50 bx lr */
/* @0xb9c54 eorseq r6, r3, r4, lsl #30 */
/* @0xb9c58 eorseq r6, r3, r8, lsl #30 */
/* @0xb9c5c ldr r1, [pc, #0x2c] */
/* @0xb9c60 mov r2, #50 */
/* @0xb9c64 push {r4, lr} */
/* @0xb9c68 mov r3, #1 */
/* @0xb9c6c mov r4, r0 */
/* @0xb9c70 add r1, pc, r1 */
/* @0xb9c74 mov r0, #128 */
/* @0xb9c78 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xb9c7c mov r2, #32 */
/* @0xb9c80 mov r3, #0 */
/* @0xb9c84 stmib r4, {r2, r3} */
/* @0xb9c88 str r0, [r4] */
/* @0xb9c8c pop {r4, pc} */
/* @0xb9c90 eoreq lr, r7, r8, lsl #21 */
/* @0xb9c94 push {r3, r4, r5, r6, r7, lr} */
/* @0xb9c98 ldr r4, [pc, #0x9c] */
/* @0xb9c9c ldr r3, [pc, #0x9c] */
/* @0xb9ca0 add r4, pc, r4 */
/* @0xb9ca4 ldr r5, [pc, #0x98] */
/* @0xb9ca8 ldr r6, [r4, r3] */
/* @0xb9cac add r5, pc, r5 */
/* @0xb9cb0 mov r0, r6 */
/* @0xb9cb4 bl 0xb9c5c <.text+0x2c8c> */
/* @0xb9cb8 ldr r3, [pc, #0x88] */
/* @0xb9cbc mov r0, r6 */
/* @0xb9cc0 mov r2, r5 */
/* @0xb9cc4 ldr r6, [r4, r3] */
/* @0xb9cc8 mov r1, r6 */
/* @0xb9ccc bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9cd0 ldr r3, [pc, #0x74] */
/* @0xb9cd4 ldr r7, [r4, r3] */
/* @0xb9cd8 mov r0, r7 */
/* @0xb9cdc bl 0xb9c5c <.text+0x2c8c> */
/* @0xb9ce0 mov r1, r6 */
/* @0xb9ce4 mov r2, r5 */
/* @0xb9ce8 mov r0, r7 */
/* @0xb9cec bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9cf0 ldr r3, [pc, #0x58] */
/* @0xb9cf4 ldr r7, [r4, r3] */
/* @0xb9cf8 mov r0, r7 */
/* @0xb9cfc bl 0xb9c5c <.text+0x2c8c> */
/* @0xb9d00 mov r1, r6 */
/* @0xb9d04 mov r2, r5 */
/* @0xb9d08 mov r0, r7 */
/* @0xb9d0c bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9d10 ldr r3, [pc, #0x3c] */
/* @0xb9d14 ldr r12, [pc, #0x3c] */
/* @0xb9d18 mov r1, #0 */
/* @0xb9d1c mov r2, r5 */
/* @0xb9d20 ldr r3, [r4, r3] */
/* @0xb9d24 str r1, [r3] */
/* @0xb9d28 mov r0, r3 */
/* @0xb9d2c str r1, [r3, #0x4] */
/* @0xb9d30 ldr r1, [r4, r12] */
/* @0xb9d34 pop {r3, r4, r5, r6, r7, lr} */
/* @0xb9d38 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9d3c ldrhteq r7, [r3], -r0 */
/* @0xb9d40 .word 0xffffbff0 */
/* @0xb9d44 eorseq r8, r3, r12, asr #6 */
/* @0xb9d48 .word 0xffffef6c */
/* @0xb9d4c .word 0xffffc454 */
/* @0xb9d50 .word 0xffffbff8 */
/* @0xb9d54 .word 0xffffeef8 */
/* @0xb9d58 .word 0xffffef70 */
/* @0xb9d5c push {r4, r5, r6, lr} */
/* @0xb9d60 mov r4, #0 */
/* @0xb9d64 ldr r5, [pc, #0x84] */
/* @0xb9d68 ldr r3, [pc, #0x84] */
/* @0xb9d6c add r5, pc, r5 */
/* @0xb9d70 ldr r6, [pc, #0x80] */
/* @0xb9d74 ldr r1, [pc, #0x80] */
/* @0xb9d78 ldr r3, [r5, r3] */
/* @0xb9d7c add r6, pc, r6 */
/* @0xb9d80 mov r2, r6 */
/* @0xb9d84 str r4, [r3, #0x4] */
/* @0xb9d88 mov r0, r3 */
/* @0xb9d8c str r4, [r3] */
/* @0xb9d90 str r4, [r3, #0x8] */
/* @0xb9d94 ldr r1, [r5, r1] */
/* @0xb9d98 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9d9c ldr r3, [pc, #0x5c] */
/* @0xb9da0 ldr r1, [pc, #0x5c] */
/* @0xb9da4 mov r2, r6 */
/* @0xb9da8 ldr r3, [r5, r3] */
/* @0xb9dac str r4, [r3, #0x4] */
/* @0xb9db0 mov r0, r3 */
/* @0xb9db4 str r4, [r3] */
/* @0xb9db8 str r4, [r3, #0x8] */
/* @0xb9dbc ldr r1, [r5, r1] */
/* @0xb9dc0 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9dc4 ldr r3, [pc, #0x3c] */
/* @0xb9dc8 ldr r1, [pc, #0x3c] */
/* @0xb9dcc mov r2, r6 */
/* @0xb9dd0 ldr r3, [r5, r3] */
/* @0xb9dd4 str r4, [r3, #0x4] */
/* @0xb9dd8 mov r0, r3 */
/* @0xb9ddc str r4, [r3] */
/* @0xb9de0 str r4, [r3, #0x8] */
/* @0xb9de4 ldr r1, [r5, r1] */
/* @0xb9de8 pop {r4, r5, r6, lr} */
/* @0xb9dec b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9df0 eorseq r7, r3, r4, ror #29 */
/* @0xb9df4 .word 0xffffefc4 */
/* @0xb9df8 eorseq r8, r3, r12, ror r2 */
/* @0xb9dfc .word 0xfffff030 */
/* @0xb9e00 .word 0xffffefb0 */
/* @0xb9e04 .word 0xfffff034 */
/* @0xb9e08 .word 0xffffefb4 */
/* @0xb9e0c .word 0xfffff038 */
/* @0xb9e10 push {r4, r5, r6, lr} */
/* @0xb9e14 mov r0, #12 */
/* @0xb9e18 bl 0x27c524 <_Znwj> */
/* @0xb9e1c ldr r4, [pc, #0xb4] */
/* @0xb9e20 mov r5, #1 */
/* @0xb9e24 add r4, pc, r4 */
/* @0xb9e28 mov r6, r0 */
/* @0xb9e2c ldr r0, [pc, #0xa8] */
/* @0xb9e30 add r1, r6, #8 */
/* @0xb9e34 add r0, pc, r0 */
/* @0xb9e38 bl 0x1dbe5c <_ZN11_RefFactoryIPKcE6CreateES1_Ri> */
/* @0xb9e3c ldr r3, [pc, #0x9c] */
/* @0xb9e40 str r5, [r6, #0x4] */
/* @0xb9e44 str r0, [r6] */
/* @0xb9e48 mov r0, #12 */
/* @0xb9e4c ldr r3, [r4, r3] */
/* @0xb9e50 str r6, [r3] */
/* @0xb9e54 bl 0x27c524 <_Znwj> */
/* @0xb9e58 mov r6, r0 */
/* @0xb9e5c ldr r0, [pc, #0x80] */
/* @0xb9e60 add r1, r6, #8 */
/* @0xb9e64 add r0, pc, r0 */
/* @0xb9e68 bl 0x1dbe5c <_ZN11_RefFactoryIPKcE6CreateES1_Ri> */
/* @0xb9e6c ldr r3, [pc, #0x74] */
/* @0xb9e70 stm r6, {r0, r5} */
/* @0xb9e74 mov r0, #12 */
/* @0xb9e78 ldr r3, [r4, r3] */
/* @0xb9e7c str r6, [r3] */
/* @0xb9e80 bl 0x27c524 <_Znwj> */
/* @0xb9e84 mov r6, r0 */
/* @0xb9e88 ldr r0, [pc, #0x5c] */
/* @0xb9e8c add r1, r6, #8 */
/* @0xb9e90 add r0, pc, r0 */
/* @0xb9e94 bl 0x1dbe5c <_ZN11_RefFactoryIPKcE6CreateES1_Ri> */
/* @0xb9e98 ldr r3, [pc, #0x50] */
/* @0xb9e9c stm r6, {r0, r5} */
/* @0xb9ea0 mov r0, #12 */
/* @0xb9ea4 ldr r3, [r4, r3] */
/* @0xb9ea8 str r6, [r3] */
/* @0xb9eac bl 0x27c524 <_Znwj> */
/* @0xb9eb0 mov r6, r0 */
/* @0xb9eb4 ldr r0, [pc, #0x38] */
/* @0xb9eb8 add r1, r6, #8 */
/* @0xb9ebc add r0, pc, r0 */
/* @0xb9ec0 bl 0x1dbe5c <_ZN11_RefFactoryIPKcE6CreateES1_Ri> */
/* @0xb9ec4 ldr r3, [pc, #0x2c] */
/* @0xb9ec8 stm r6, {r0, r5} */
/* @0xb9ecc ldr r3, [r4, r3] */
/* @0xb9ed0 str r6, [r3] */
/* @0xb9ed4 pop {r4, r5, r6, pc} */
/* @0xb9ed8 eorseq r7, r3, r12, lsr #28 */
/* @0xb9edc .word 0x002977f4 */
/* @0xb9ee0 .word 0xffffce3c */
/* @0xb9ee4 .word 0x002977d4 */
/* @0xb9ee8 .word 0xffffcff8 */
/* @0xb9eec .word 0x002977b8 */
/* @0xb9ef0 .word 0xffffcffc */
/* @0xb9ef4 mlaeq r9, r8, r7, r7 */
/* @0xb9ef8 .word 0xffffd000 */
/* @0xb9efc push {r3, r4, r5, lr} */
/* @0xb9f00 mov r2, #187 */
/* @0xb9f04 ldr r4, [pc, #0x50] */
/* @0xb9f08 mov r3, #1 */
/* @0xb9f0c ldr r1, [pc, #0x4c] */
/* @0xb9f10 mov r0, #1024 */
/* @0xb9f14 ldr r4, [pc, r4] */
/* @0xb9f18 mov r12, #127 */
/* @0xb9f1c add r1, pc, r1 */
/* @0xb9f20 mov r5, #0 */
/* @0xb9f24 str r12, [r4, #0x4] */
/* @0xb9f28 str r5, [r4, #0x8] */
/* @0xb9f2c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xb9f30 mov r1, r5 */
/* @0xb9f34 mov r2, #1024 */
/* @0xb9f38 str r0, [r4] */
/* @0xb9f3c bl 0xb65b0 <memset@plt> */
/* @0xb9f40 ldr r1, [pc, #0x1c] */
/* @0xb9f44 mov r0, r4 */
/* @0xb9f48 ldr r2, [pc, #0x18] */
/* @0xb9f4c ldr r1, [pc, r1] */
/* @0xb9f50 add r2, pc, r2 */
/* @0xb9f54 pop {r3, r4, r5, lr} */
/* @0xb9f58 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xb9f5c eorseq r6, r3, r8, lsl #29 */
/* @0xb9f60 eoreq r1, r9, r8, lsl #9 */
/* @0xb9f64 eorseq r6, r3, r12, ror lr */
/* @0xb9f68 eorseq r8, r3, r8, lsr #1 */
/* @0xb9f6c push {r3, r4, r5, lr} */
/* @0xb9f70 mov r2, #70 */
/* @0xb9f74 ldr r4, [pc, #0xa4] */
/* @0xb9f78 mov r3, #1 */
/* @0xb9f7c ldr r1, [pc, #0xa0] */
/* @0xb9f80 mov r0, #1536 */
/* @0xb9f84 ldr r4, [pc, r4] */
/* @0xb9f88 mov r5, #0 */
/* @0xb9f8c add r1, pc, r1 */
/* @0xb9f90 mov lr, #128 */
/* @0xb9f94 mov r12, #127 */
/* @0xb9f98 str lr, [r4] */
/* @0xb9f9c str r12, [r4, #0x8] */
/* @0xb9fa0 str r5, [r4, #0x10] */
/* @0xb9fa4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xb9fa8 mov r2, #1536 */
/* @0xb9fac mov r1, r5 */
/* @0xb9fb0 str r0, [r4, #0x10] */
/* @0xb9fb4 bl 0xb65b0 <memset@plt> */
/* @0xb9fb8 ldr r2, [r4] */
/* @0xb9fbc vldr s15, [pc, #88] */
/* @0xb9fc0 str r5, [r4, #0x4] */
/* @0xb9fc4 cmp r2, r5 */
/* @0xb9fc8 vmov s13, r2 */
/* @0xb9fcc vcvt.f32.s32 s14, s13 */
/* @0xb9fd0 vmul.f32 s15, s14, s15 */
/* @0xb9fd4 vcvt.s32.f32 s15, s15 */
/* @0xb9fd8 vstr s15, [r4, #12] */
/* @0xb9fdc ble 0xba000 <.text+0x3030> */
/* @0xb9fe0 add r2, r2, r2, lsl #1 */
/* @0xb9fe4 ldr r3, [r4, #0x10] */
/* @0xb9fe8 mov r1, r5 */
/* @0xb9fec add r2, r3, r2, lsl #2 */
/* @0xb9ff0 str r1, [r3, #0x8] */
/* @0xb9ff4 add r3, r3, #12 */
/* @0xb9ff8 cmp r3, r2 */
/* @0xb9ffc bne 0xb9ff0 <.text+0x3020> */
/* @0xba000 ldr r1, [pc, #0x20] */
/* @0xba004 mov r0, r4 */
/* @0xba008 ldr r2, [pc, #0x1c] */
/* @0xba00c ldr r1, [pc, r1] */
/* @0xba010 add r2, pc, r2 */
/* @0xba014 pop {r3, r4, r5, lr} */
/* @0xba018 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba01c svclo #0x19999a */
/* @0xba020 mlaseq r3, r0, lr, r6 */
/* @0xba024 eoreq r7, r7, r4, lsr #1 */
/* @0xba028 eorseq r6, r3, r4, lsl lr */
/* @0xba02c eorseq r7, r3, r8, ror #31 */
/* @0xba030 ldr r3, [pc, #0x24] */
/* @0xba034 mov r12, #0 */
/* @0xba038 ldr r1, [pc, #0x20] */
/* @0xba03c ldr r3, [pc, r3] */
/* @0xba040 ldr r2, [pc, #0x1c] */
/* @0xba044 ldr r1, [pc, r1] */
/* @0xba048 add r2, pc, r2 */
/* @0xba04c mov r0, r3 */
/* @0xba050 str r12, [r3] */
/* @0xba054 str r12, [r3, #0x4] */
/* @0xba058 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba05c eorseq r6, r3, r12, ror #27 */
/* @0xba060 eorseq r6, r3, r12, ror #27 */
/* @0xba064 ldrhteq r7, [r3], -r0 */
/* @0xba068 ldr r3, [pc, #0x24] */
/* @0xba06c mov r12, #0 */
/* @0xba070 ldr r1, [pc, #0x20] */
/* @0xba074 ldr r3, [pc, r3] */
/* @0xba078 ldr r2, [pc, #0x1c] */
/* @0xba07c ldr r1, [pc, r1] */
/* @0xba080 add r2, pc, r2 */
/* @0xba084 mov r0, r3 */
/* @0xba088 str r12, [r3] */
/* @0xba08c str r12, [r3, #0x4] */
/* @0xba090 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba094 eorseq r7, r3, r12, lsr r3 */
/* @0xba098 eorseq r7, r3, r12, lsr r3 */
/* @0xba09c eorseq r7, r3, r8, ror pc */
/* @0xba0a0 push {r4, r5, r6, r7, r8, lr} */
/* @0xba0a4 mov r5, #0 */
/* @0xba0a8 ldr r4, [pc, #0x16c] */
/* @0xba0ac ldr r6, [pc, #0x16c] */
/* @0xba0b0 ldr r7, [pc, #0x16c] */
/* @0xba0b4 add r4, pc, r4 */
/* @0xba0b8 ldr r3, [pc, #0x168] */
/* @0xba0bc add r6, pc, r6 */
/* @0xba0c0 add r7, pc, r7 */
/* @0xba0c4 str r5, [r4, #0x38] */
/* @0xba0c8 str r5, [r4, #0x3c] */
/* @0xba0cc add r0, r4, #56 */
/* @0xba0d0 ldr r1, [r6, r3] */
/* @0xba0d4 mov r2, r7 */
/* @0xba0d8 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba0dc ldr r3, [pc, #0x148] */
/* @0xba0e0 str r5, [r4, #0x40] */
/* @0xba0e4 mov r2, r7 */
/* @0xba0e8 str r5, [r4, #0x44] */
/* @0xba0ec add r0, r4, #64 */
/* @0xba0f0 ldr r1, [r6, r3] */
/* @0xba0f4 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba0f8 ldr r3, [pc, #0x130] */
/* @0xba0fc str r5, [r4, #0x20] */
/* @0xba100 mov r2, r7 */
/* @0xba104 str r5, [r4, #0x24] */
/* @0xba108 add r0, r4, #32 */
/* @0xba10c ldr r8, [r6, r3] */
/* @0xba110 mov r1, r8 */
/* @0xba114 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba118 ldr r3, [pc, #0x114] */
/* @0xba11c str r5, [r4, #0x48] */
/* @0xba120 mov r2, r7 */
/* @0xba124 str r5, [r4, #0x4c] */
/* @0xba128 add r0, r4, #72 */
/* @0xba12c ldr r1, [r6, r3] */
/* @0xba130 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba134 ldr r3, [pc, #0xfc] */
/* @0xba138 str r5, [r4, #0x58] */
/* @0xba13c mov r2, r7 */
/* @0xba140 str r5, [r4, #0x5c] */
/* @0xba144 add r0, r4, #88 */
/* @0xba148 ldr r1, [r6, r3] */
/* @0xba14c bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba150 ldr r12, [pc, #0xe4] */
/* @0xba154 ldr r3, [pc, #0xe4] */
/* @0xba158 mov r1, r8 */
/* @0xba15c mov r2, r7 */
/* @0xba160 add r0, r4, #40 */
/* @0xba164 ldr r12, [r6, r12] */
/* @0xba168 ldr r3, [r6, r3] */
/* @0xba16c str r5, [r4, #0x28] */
/* @0xba170 ldr r12, [r12] */
/* @0xba174 str r5, [r4, #0x2c] */
/* @0xba178 add r12, r12, #1 */
/* @0xba17c str r12, [r3] */
/* @0xba180 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba184 mov r1, r8 */
/* @0xba188 mov r2, r7 */
/* @0xba18c add r0, r4, #48 */
/* @0xba190 str r5, [r4, #0x30] */
/* @0xba194 str r5, [r4, #0x34] */
/* @0xba198 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba19c ldr r3, [pc, #0xa0] */
/* @0xba1a0 mov r1, r8 */
/* @0xba1a4 mov r2, r7 */
/* @0xba1a8 ldr r3, [r6, r3] */
/* @0xba1ac mov r0, r3 */
/* @0xba1b0 str r5, [r3] */
/* @0xba1b4 str r5, [r3, #0x4] */
/* @0xba1b8 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba1bc mov r0, r4 */
/* @0xba1c0 bl 0x225cb4 <_ZN9COggAudioC2Ev> */
/* @0xba1c4 ldr r3, [pc, #0x7c] */
/* @0xba1c8 mov r2, r7 */
/* @0xba1cc mov r0, r4 */
/* @0xba1d0 ldr r1, [r6, r3] */
/* @0xba1d4 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba1d8 ldr r3, [pc, #0x6c] */
/* @0xba1dc str r5, [r4, #0x50] */
/* @0xba1e0 mov r2, r7 */
/* @0xba1e4 str r5, [r4, #0x54] */
/* @0xba1e8 add r0, r4, #80 */
/* @0xba1ec ldr r1, [r6, r3] */
/* @0xba1f0 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba1f4 ldr r3, [pc, #0x54] */
/* @0xba1f8 ldr r1, [pc, #0x54] */
/* @0xba1fc mov r2, r7 */
/* @0xba200 ldr r3, [r6, r3] */
/* @0xba204 str r5, [r3] */
/* @0xba208 mov r0, r3 */
/* @0xba20c str r5, [r3, #0x4] */
/* @0xba210 ldr r1, [r6, r1] */
/* @0xba214 pop {r4, r5, r6, r7, r8, lr} */
/* @0xba218 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba21c rsbeq r11, r9, r0, ror #3 */
/* @0xba220 mlaseq r3, r4, r11, r7 */
/* @0xba224 eorseq r7, r3, r8, lsr pc */
/* @0xba228 .word 0xfffff7ac */
/* @0xba22c .word 0xfffff7b0 */
/* @0xba230 .word 0xfffff7b4 */
/* @0xba234 .word 0xffffebfc */
/* @0xba238 .word 0xffffec00 */
/* @0xba23c .word 0xfffff794 */
/* @0xba240 .word 0xfffff7a0 */
/* @0xba244 .word 0xfffff788 */
/* @0xba248 .word 0xfffff7b8 */
/* @0xba24c .word 0xfffff7bc */
/* @0xba250 .word 0xfffff7a8 */
/* @0xba254 .word 0xfffff7c0 */
/* @0xba258 ldr r0, [pc, #0x4] */
/* @0xba25c ldr r0, [pc, r0] */
/* @0xba260 b 0x21de3c <_ZN14CAudioGroupManC2Ev> */
/* @0xba264 ldrshteq r4, [r3], -r4 */
/* @0xba268 ldr r3, [pc, #0x24] */
/* @0xba26c mov r12, #0 */
/* @0xba270 ldr r1, [pc, #0x20] */
/* @0xba274 ldr r3, [pc, r3] */
/* @0xba278 ldr r2, [pc, #0x1c] */
/* @0xba27c ldr r1, [pc, r1] */
/* @0xba280 add r2, pc, r2 */
/* @0xba284 mov r0, r3 */
/* @0xba288 str r12, [r3] */
/* @0xba28c str r12, [r3, #0x4] */
/* @0xba290 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba294 eorseq r7, r3, r4, lsr #3 */
/* @0xba298 eorseq r7, r3, r4, lsr #3 */
/* @0xba29c eorseq r7, r3, r8, ror sp */
/* @0xba2a0 push {r4, r5, r6, lr} */
/* @0xba2a4 mov r5, #0 */
/* @0xba2a8 ldr r4, [pc, #0x44] */
/* @0xba2ac ldr r6, [pc, #0x44] */
/* @0xba2b0 add r4, pc, r4 */
/* @0xba2b4 ldr r1, [pc, #0x40] */
/* @0xba2b8 add r6, pc, r6 */
/* @0xba2bc mov r0, r4 */
/* @0xba2c0 ldr r1, [pc, r1] */
/* @0xba2c4 mov r2, r6 */
/* @0xba2c8 str r5, [r4] */
/* @0xba2cc str r5, [r4, #0x4] */
/* @0xba2d0 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba2d4 ldr r1, [pc, #0x24] */
/* @0xba2d8 mov r2, r6 */
/* @0xba2dc add r0, r4, #8 */
/* @0xba2e0 str r5, [r4, #0x8] */
/* @0xba2e4 str r5, [r4, #0xc] */
/* @0xba2e8 ldr r1, [pc, r1] */
/* @0xba2ec pop {r4, r5, r6, lr} */
/* @0xba2f0 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba2f4 rsbeq r11, r9, r8, lsl #1 */
/* @0xba2f8 eorseq r7, r3, r0, asr #26 */
/* @0xba2fc eorseq r7, r3, r4, ror #2 */
/* @0xba300 eorseq r6, r3, r4, ror #10 */
/* @0xba304 push {r3, r4, r5, lr} */
/* @0xba308 mov r2, #187 */
/* @0xba30c ldr r4, [pc, #0x50] */
/* @0xba310 mov r3, #1 */
/* @0xba314 ldr r1, [pc, #0x4c] */
/* @0xba318 mov r0, #8192 */
/* @0xba31c ldr r4, [pc, r4] */
/* @0xba320 movw r12, #0x3ff */
/* @0xba324 add r1, pc, r1 */
/* @0xba328 mov r5, #0 */
/* @0xba32c str r12, [r4, #0x4] */
/* @0xba330 str r5, [r4, #0x8] */
/* @0xba334 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xba338 mov r1, r5 */
/* @0xba33c mov r2, #8192 */
/* @0xba340 str r0, [r4] */
/* @0xba344 bl 0xb65b0 <memset@plt> */
/* @0xba348 ldr r1, [pc, #0x1c] */
/* @0xba34c mov r0, r4 */
/* @0xba350 ldr r2, [pc, #0x18] */
/* @0xba354 ldr r1, [pc, r1] */
/* @0xba358 add r2, pc, r2 */
/* @0xba35c pop {r3, r4, r5, lr} */
/* @0xba360 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba364 eorseq r7, r3, r8, lsl #3 */
/* @0xba368 eoreq r2, r9, r8, lsl #19 */
/* @0xba36c eorseq r7, r3, r8, ror #2 */
/* @0xba370 eorseq r7, r3, r0, lsr #25 */
/* @0xba374 push {r3, r4, r5, lr} */
/* @0xba378 mov r2, #187 */
/* @0xba37c ldr r4, [pc, #0x50] */
/* @0xba380 mov r3, #1 */
/* @0xba384 ldr r1, [pc, #0x4c] */
/* @0xba388 mov r0, #4096 */
/* @0xba38c ldr r4, [pc, r4] */
/* @0xba390 movw r12, #0x1ff */
/* @0xba394 add r1, pc, r1 */
/* @0xba398 mov r5, #0 */
/* @0xba39c str r12, [r4, #0x4] */
/* @0xba3a0 str r5, [r4, #0x8] */
/* @0xba3a4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xba3a8 mov r1, r5 */
/* @0xba3ac mov r2, #4096 */
/* @0xba3b0 str r0, [r4] */
/* @0xba3b4 bl 0xb65b0 <memset@plt> */
/* @0xba3b8 ldr r1, [pc, #0x1c] */
/* @0xba3bc mov r0, r4 */
/* @0xba3c0 ldr r2, [pc, #0x18] */
/* @0xba3c4 ldr r1, [pc, r1] */
/* @0xba3c8 add r2, pc, r2 */
/* @0xba3cc pop {r3, r4, r5, lr} */
/* @0xba3d0 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba3d4 eorseq r7, r3, r8, asr r1 */
/* @0xba3d8 eoreq r2, r9, r8, lsl r9 */
/* @0xba3dc eorseq r7, r3, r4, lsr #2 */
/* @0xba3e0 eorseq r7, r3, r0, lsr r12 */
/* @0xba3e4 push {r4, r5, r6, lr} */
/* @0xba3e8 mov r2, #70 */
/* @0xba3ec ldr r4, [pc, #0x154] */
/* @0xba3f0 mov r3, #1 */
/* @0xba3f4 ldr r5, [pc, #0x150] */
/* @0xba3f8 mov r0, #96 */
/* @0xba3fc add r4, pc, r4 */
/* @0xba400 ldr r1, [pc, #0x148] */
/* @0xba404 mov r6, #0 */
/* @0xba408 mov lr, #8 */
/* @0xba40c ldr r5, [r4, r5] */
/* @0xba410 add r1, pc, r1 */
/* @0xba414 mov r12, #7 */
/* @0xba418 str lr, [r5] */
/* @0xba41c str r12, [r5, #0x8] */
/* @0xba420 str r6, [r5, #0x10] */
/* @0xba424 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xba428 mov r2, #96 */
/* @0xba42c mov r1, r6 */
/* @0xba430 str r0, [r5, #0x10] */
/* @0xba434 bl 0xb65b0 <memset@plt> */
/* @0xba438 ldr r2, [r5] */
/* @0xba43c vldr s15, [pc, #256] */
/* @0xba440 str r6, [r5, #0x4] */
/* @0xba444 cmp r2, r6 */
/* @0xba448 vmov s13, r2 */
/* @0xba44c vcvt.f32.s32 s14, s13 */
/* @0xba450 vmul.f32 s15, s14, s15 */
/* @0xba454 vcvt.s32.f32 s15, s15 */
/* @0xba458 vstr s15, [r5, #12] */
/* @0xba45c ble 0xba480 <.text+0x34b0> */
/* @0xba460 add r2, r2, r2, lsl #1 */
/* @0xba464 ldr r3, [r5, #0x10] */
/* @0xba468 mov r1, r6 */
/* @0xba46c add r2, r3, r2, lsl #2 */
/* @0xba470 str r1, [r3, #0x8] */
/* @0xba474 add r3, r3, #12 */
/* @0xba478 cmp r3, r2 */
/* @0xba47c bne 0xba470 <.text+0x34a0> */
/* @0xba480 ldr r3, [pc, #0xcc] */
/* @0xba484 mov r0, r5 */
/* @0xba488 ldr r2, [pc, #0xc8] */
/* @0xba48c ldr r1, [r4, r3] */
/* @0xba490 add r2, pc, r2 */
/* @0xba494 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba498 ldr r2, [pc, #0xbc] */
/* @0xba49c ldr r3, [pc, #0xbc] */
/* @0xba4a0 ldr r1, [pc, #0xbc] */
/* @0xba4a4 ldr r0, [r4, r2] */
/* @0xba4a8 ldr r12, [r4, r3] */
/* @0xba4ac ldr r3, [pc, #0xb4] */
/* @0xba4b0 add r12, r12, #8 */
/* @0xba4b4 ldr r2, [pc, #0xb0] */
/* @0xba4b8 str r12, [r0] */
/* @0xba4bc ldr r0, [r4, r1] */
/* @0xba4c0 ldr r12, [r4, r3] */
/* @0xba4c4 ldr r3, [pc, #0xa4] */
/* @0xba4c8 add r12, r12, #8 */
/* @0xba4cc ldr r1, [pc, #0xa0] */
/* @0xba4d0 str r12, [r0] */
/* @0xba4d4 ldr r0, [r4, r2] */
/* @0xba4d8 ldr r12, [r4, r3] */
/* @0xba4dc ldr r3, [pc, #0x94] */
/* @0xba4e0 add r12, r12, #8 */
/* @0xba4e4 ldr r2, [pc, #0x90] */
/* @0xba4e8 str r12, [r0] */
/* @0xba4ec ldr r0, [r4, r1] */
/* @0xba4f0 ldr r12, [r4, r3] */
/* @0xba4f4 ldr r3, [pc, #0x84] */
/* @0xba4f8 add r12, r12, #8 */
/* @0xba4fc ldr r1, [pc, #0x80] */
/* @0xba500 str r12, [r0] */
/* @0xba504 ldr r0, [r4, r2] */
/* @0xba508 ldr r12, [r4, r3] */
/* @0xba50c ldr r2, [pc, #0x74] */
/* @0xba510 add r12, r12, #8 */
/* @0xba514 ldr r3, [pc, #0x70] */
/* @0xba518 str r12, [r0] */
/* @0xba51c ldr r1, [r4, r1] */
/* @0xba520 ldr r0, [r4, r2] */
/* @0xba524 ldr r2, [pc, #0x64] */
/* @0xba528 add r0, r0, #8 */
/* @0xba52c str r0, [r1] */
/* @0xba530 ldr r3, [r4, r3] */
/* @0xba534 ldr r2, [r4, r2] */
/* @0xba538 add r2, r2, #8 */
/* @0xba53c str r2, [r3] */
/* @0xba540 pop {r4, r5, r6, pc} */
/* @0xba544 svclo #0x19999a */
/* @0xba548 eorseq r7, r3, r4, asr r8 */
/* @0xba54c .word 0xfffffbd0 */
/* @0xba550 eoreq r6, r7, r0, lsr #24 */
/* @0xba554 .word 0xfffffc14 */
/* @0xba558 eorseq r7, r3, r8, ror #22 */
/* @0xba55c .word 0xfffffbe8 */
/* @0xba560 .word 0xfffffc18 */
/* @0xba564 .word 0xfffffbec */
/* @0xba568 .word 0xfffffc1c */
/* @0xba56c .word 0xfffffbf0 */
/* @0xba570 .word 0xfffffc20 */
/* @0xba574 .word 0xfffffbf4 */
/* @0xba578 .word 0xfffffc24 */
/* @0xba57c .word 0xfffffbf8 */
/* @0xba580 .word 0xfffffc28 */
/* @0xba584 .word 0xfffffbfc */
/* @0xba588 .word 0xfffffc2c */
/* @0xba58c .word 0xfffffc08 */
/* @0xba590 .word 0xfffffc30 */
/* @0xba594 ldr r0, [pc, #0x4] */
/* @0xba598 ldr r0, [pc, r0] */
/* @0xba59c b 0x2a00a4 <_ZN9CProfilerC2Ev> */
/* @0xba5a0 ldrsbteq r3, [r3], -r4 */
/* @0xba5a4 ldr r3, [pc, #0x10] */
/* @0xba5a8 mov r2, #0 */
/* @0xba5ac ldr r3, [pc, r3] */
/* @0xba5b0 str r2, [r3] */
/* @0xba5b4 str r2, [r3, #0x4] */
/* @0xba5b8 bx lr */
/* @0xba5bc eorseq r6, r3, r12, lsr #30 */
/* @0xba5c0 push {r3, r4, r5, lr} */
/* @0xba5c4 ldr r4, [pc, #0x5c] */
/* @0xba5c8 ldr r1, [pc, #0x5c] */
/* @0xba5cc add r4, pc, r4 */
/* @0xba5d0 ldr r2, [pc, #0x58] */
/* @0xba5d4 ldr r5, [pc, #0x58] */
/* @0xba5d8 ldr r0, [r4, r1] */
/* @0xba5dc ldr r3, [pc, #0x54] */
/* @0xba5e0 add r5, pc, r5 */
/* @0xba5e4 ldr r2, [r4, r2] */
/* @0xba5e8 add r2, r2, #8 */
/* @0xba5ec str r2, [r0] */
/* @0xba5f0 mov r2, r5 */
/* @0xba5f4 ldr r1, [r4, r3] */
/* @0xba5f8 bl 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba5fc ldr r0, [pc, #0x38] */
/* @0xba600 ldr r1, [pc, #0x38] */
/* @0xba604 mov r2, r5 */
/* @0xba608 ldr r3, [pc, #0x34] */
/* @0xba60c ldr r0, [r4, r0] */
/* @0xba610 ldr r1, [r4, r1] */
/* @0xba614 add r1, r1, #8 */
/* @0xba618 str r1, [r0] */
/* @0xba61c ldr r1, [r4, r3] */
/* @0xba620 pop {r3, r4, r5, lr} */
/* @0xba624 b 0xb65f8 <__aeabi_atexit@plt> */
/* @0xba628 eorseq r7, r3, r4, lsl #13 */
/* @0xba62c .word 0xfffffe94 */
/* @0xba630 .word 0xfffffe90 */
/* @0xba634 eorseq r7, r3, r8, lsl r10 */
/* @0xba638 .word 0xfffffea0 */
/* @0xba63c .word 0xfffffe98 */
/* @0xba640 .word 0xfffff870 */
/* @0xba644 .word 0xfffffea4 */
/* @0xba648 ldr r3, [pc, #0x18] */
/* @0xba64c mov r2, #0 */
/* @0xba650 ldr r3, [pc, r3] */
/* @0xba654 strb r2, [r3] */
/* @0xba658 strb r2, [r3, #0x1] */
/* @0xba65c strb r2, [r3, #0x2] */
/* @0xba660 strb r2, [r3, #0x3] */
/* @0xba664 bx lr */
/* @0xba668 eorseq r6, r3, r12, lsl #29 */
/* @0xba66c ldmdbmi r5, {r2, r4, r11, lr} */
/* @0xba670 ldrbtmi r11, [r8], #-1336 */
/* @0xba674 .word 0xf7fc4479 */
/* @0xba678 strmi lr, [r5], -r8, ror #22 */
/* @0xba67c .word 0x4c12b9d8 */
/* @0xba680 strmi r2, [r1], -r12, lsl #6 */
/* @0xba684 .word 0xf104447c */
/* @0xba688 eorvs r0, r3, r12 */
/* @0xba68c cmnvs pc, #12582912 */
/* @0xba690 vhadd.s8 d22, d16, d19 */
/* @0xba694 rsbvs r1, r3, r5, asr r3 */
/* @0xba698 bl 0x478690 <g_RomDisk+0x80e70> */
/* @0xba69c stmdbmi r12, {r0, r1, r3, r11, lr} */
/* @0xba6a0 ldrbtmi r4, [r8], #-2572 */
/* @0xba6a4 .word 0x61654479 */
/* @0xba6a8 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr} */
/* @0xba6ac pop {r0, r2, r5, r8, sp, lr} */
/* @0xba6b0 vqadd.s32 d20, d1, d24 */
/* @0xba6b4 stmdami r8, {r0, r1, r3, r4, r6, r9, r11, r12, sp, pc} */
/* @0xba6b8 .word 0xf25d4478 */
/* @0xba6bc svclt #0xfa0f */
/* @0xba6c0 rsbeq lr, r9, lr, asr #28 */
/* @0xba6c4 mlaeq r5, r9, sp, r12 */
/* @0xba6c8 rsbeq lr, r9, r4, lsr #28 */
/* @0xba6cc rsbeq lr, r9, r2, lsl #28 */
/* @0xba6d0 mlaeq r5, r5, sp, r12 */
/* @0xba6d4 eorseq r7, r3, r0, ror #10 */
/* @0xba6d8 mlaeq r10, r4, lr, r1 */
/* @0xba6dc cmp r0, #0 */
/* @0xba6e0 push {r3, lr} */
/* @0xba6e4 popeq {r3, pc} */
/* @0xba6e8 blx r0 */
/* @0xba6ec pop {r3, pc} */
/* @0xba6f0 mov r1, r0 */
/* @0xba6f4 ldr r2, [pc, #0xc] */
/* @0xba6f8 ldr r0, [pc, #0xc] */
/* @0xba6fc add r2, pc, r2 */
/* @0xba700 add r0, pc, r0 */
/* @0xba704 b 0xb64fc <__cxa_atexit@plt> */
/* @0xba708 ldrshteq r7, [r3], -r12 */
/* @0xba70c .word 0xffffffd4 */

/* ── FUNC 0xba710 · GLFuncImport(bool) · size=12180 · insn=3045 */
/* @0xba710 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xba714 mov r8, r0 */
/* @0xba718 ldr r4, [pc, #0xfdc] */
/* @0xba71c ldr r3, [pc, #0xfdc] */
/* @0xba720 add r4, pc, r4 */
/* @0xba724 ldr r7, [r4, r3] */
/* @0xba728 ldr r6, [r7] */
/* @0xba72c cmp r6, #0 */
/* @0xba730 beq 0xba73c <_Z12GLFuncImportb+0x2c> */
/* @0xba734 mov r0, r6 */
/* @0xba738 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xba73c ldr r3, [pc, #0xfc0] */
/* @0xba740 ldr r1, [pc, #0xfc0] */
/* @0xba744 ldr r3, [r4, r3] */
/* @0xba748 add r1, pc, r1 */
/* @0xba74c ldr r5, [r3] */
/* @0xba750 ldr r3, [r5] */
/* @0xba754 mov r0, r5 */
/* @0xba758 ldr r3, [r3, #0xc] */
/* @0xba75c blx r3 */
/* @0xba760 cmp r8, #0 */
/* @0xba764 bne 0xbb640 <_Z12GLFuncImportb+0xf30> */
/* @0xba768 ldr r3, [pc, #0xf9c] */
/* @0xba76c ldr r9, [pc, r3] */
/* @0xba770 cmp r9, #0 */
/* @0xba774 movne r6, r8 */
/* @0xba778 beq 0xbb69c <_Z12GLFuncImportb+0xf8c> */
/* @0xba77c ldr r1, [pc, #0xf8c] */
/* @0xba780 mov r0, r9 */
/* @0xba784 str r6, [r7] */
/* @0xba788 add r1, pc, r1 */
/* @0xba78c bl 0xb6514 <dlsym@plt> */
/* @0xba790 subs r9, r0, #0 */
/* @0xba794 beq 0xbc98c <_Z12GLFuncImportb+0x227c> */
/* @0xba798 ldr r3, [pc, #0xf74] */
/* @0xba79c ldr r2, [pc, #0xf74] */
/* @0xba7a0 ldr r1, [pc, #0xf74] */
/* @0xba7a4 ldr r3, [r4, r3] */
/* @0xba7a8 add r2, pc, r2 */
/* @0xba7ac add r1, pc, r1 */
/* @0xba7b0 ldr r0, [r2] */
/* @0xba7b4 str r9, [r3] */
/* @0xba7b8 bl 0xb6514 <dlsym@plt> */
/* @0xba7bc subs r9, r0, #0 */
/* @0xba7c0 beq 0xbc9ac <_Z12GLFuncImportb+0x229c> */
/* @0xba7c4 ldr r3, [pc, #0xf54] */
/* @0xba7c8 ldr r2, [pc, #0xf54] */
/* @0xba7cc ldr r1, [pc, #0xf54] */
/* @0xba7d0 ldr r3, [r4, r3] */
/* @0xba7d4 add r2, pc, r2 */
/* @0xba7d8 add r1, pc, r1 */
/* @0xba7dc ldr r0, [r2] */
/* @0xba7e0 str r9, [r3] */
/* @0xba7e4 bl 0xb6514 <dlsym@plt> */
/* @0xba7e8 subs r9, r0, #0 */
/* @0xba7ec beq 0xbc8cc <_Z12GLFuncImportb+0x21bc> */
/* @0xba7f0 ldr r3, [pc, #0xf34] */
/* @0xba7f4 ldr r2, [pc, #0xf34] */
/* @0xba7f8 ldr r1, [pc, #0xf34] */
/* @0xba7fc ldr r3, [r4, r3] */
/* @0xba800 add r2, pc, r2 */
/* @0xba804 add r1, pc, r1 */
/* @0xba808 ldr r0, [r2] */
/* @0xba80c str r9, [r3] */
/* @0xba810 bl 0xb6514 <dlsym@plt> */
/* @0xba814 subs r9, r0, #0 */
/* @0xba818 beq 0xbc8ec <_Z12GLFuncImportb+0x21dc> */
/* @0xba81c ldr r3, [pc, #0xf14] */
/* @0xba820 ldr r2, [pc, #0xf14] */
/* @0xba824 ldr r1, [pc, #0xf14] */
/* @0xba828 ldr r3, [r4, r3] */
/* @0xba82c add r2, pc, r2 */
/* @0xba830 add r1, pc, r1 */
/* @0xba834 ldr r0, [r2] */
/* @0xba838 str r9, [r3] */
/* @0xba83c bl 0xb6514 <dlsym@plt> */
/* @0xba840 subs r9, r0, #0 */
/* @0xba844 beq 0xbc90c <_Z12GLFuncImportb+0x21fc> */
/* @0xba848 ldr r3, [pc, #0xef4] */
/* @0xba84c ldr r2, [pc, #0xef4] */
/* @0xba850 ldr r1, [pc, #0xef4] */
/* @0xba854 ldr r3, [r4, r3] */
/* @0xba858 add r2, pc, r2 */
/* @0xba85c add r1, pc, r1 */
/* @0xba860 ldr r0, [r2] */
/* @0xba864 str r9, [r3] */
/* @0xba868 bl 0xb6514 <dlsym@plt> */
/* @0xba86c subs r9, r0, #0 */
/* @0xba870 beq 0xbc92c <_Z12GLFuncImportb+0x221c> */
/* @0xba874 ldr r3, [pc, #0xed4] */
/* @0xba878 ldr r2, [pc, #0xed4] */
/* @0xba87c ldr r1, [pc, #0xed4] */
/* @0xba880 ldr r3, [r4, r3] */
/* @0xba884 add r2, pc, r2 */
/* @0xba888 add r1, pc, r1 */
/* @0xba88c ldr r0, [r2] */
/* @0xba890 str r9, [r3] */
/* @0xba894 bl 0xb6514 <dlsym@plt> */
/* @0xba898 subs r9, r0, #0 */
/* @0xba89c beq 0xbc7cc <_Z12GLFuncImportb+0x20bc> */
/* @0xba8a0 ldr r3, [pc, #0xeb4] */
/* @0xba8a4 ldr r2, [pc, #0xeb4] */
/* @0xba8a8 ldr r1, [pc, #0xeb4] */
/* @0xba8ac ldr r3, [r4, r3] */
/* @0xba8b0 add r2, pc, r2 */
/* @0xba8b4 add r1, pc, r1 */
/* @0xba8b8 ldr r0, [r2] */
/* @0xba8bc str r9, [r3] */
/* @0xba8c0 bl 0xb6514 <dlsym@plt> */
/* @0xba8c4 subs r9, r0, #0 */
/* @0xba8c8 beq 0xbc7ec <_Z12GLFuncImportb+0x20dc> */
/* @0xba8cc ldr r3, [pc, #0xe94] */
/* @0xba8d0 ldr r2, [pc, #0xe94] */
/* @0xba8d4 ldr r1, [pc, #0xe94] */
/* @0xba8d8 ldr r3, [r4, r3] */
/* @0xba8dc add r2, pc, r2 */
/* @0xba8e0 add r1, pc, r1 */
/* @0xba8e4 ldr r0, [r2] */
/* @0xba8e8 str r9, [r3] */
/* @0xba8ec bl 0xb6514 <dlsym@plt> */
/* @0xba8f0 subs r9, r0, #0 */
/* @0xba8f4 beq 0xbc80c <_Z12GLFuncImportb+0x20fc> */
/* @0xba8f8 ldr r3, [pc, #0xe74] */
/* @0xba8fc ldr r2, [pc, #0xe74] */
/* @0xba900 ldr r1, [pc, #0xe74] */
/* @0xba904 ldr r3, [r4, r3] */
/* @0xba908 add r2, pc, r2 */
/* @0xba90c add r1, pc, r1 */
/* @0xba910 ldr r0, [r2] */
/* @0xba914 str r9, [r3] */
/* @0xba918 bl 0xb6514 <dlsym@plt> */
/* @0xba91c subs r9, r0, #0 */
/* @0xba920 beq 0xbc82c <_Z12GLFuncImportb+0x211c> */
/* @0xba924 ldr r3, [pc, #0xe54] */
/* @0xba928 ldr r2, [pc, #0xe54] */
/* @0xba92c ldr r1, [pc, #0xe54] */
/* @0xba930 ldr r3, [r4, r3] */
/* @0xba934 add r2, pc, r2 */
/* @0xba938 add r1, pc, r1 */
/* @0xba93c ldr r0, [r2] */
/* @0xba940 str r9, [r3] */
/* @0xba944 bl 0xb6514 <dlsym@plt> */
/* @0xba948 subs r9, r0, #0 */
/* @0xba94c beq 0xbc84c <_Z12GLFuncImportb+0x213c> */
/* @0xba950 ldr r3, [pc, #0xe34] */
/* @0xba954 ldr r2, [pc, #0xe34] */
/* @0xba958 ldr r1, [pc, #0xe34] */
/* @0xba95c ldr r3, [r4, r3] */
/* @0xba960 add r2, pc, r2 */
/* @0xba964 add r1, pc, r1 */
/* @0xba968 ldr r0, [r2] */
/* @0xba96c str r9, [r3] */
/* @0xba970 bl 0xb6514 <dlsym@plt> */
/* @0xba974 subs r9, r0, #0 */
/* @0xba978 beq 0xbc86c <_Z12GLFuncImportb+0x215c> */
/* @0xba97c ldr r3, [pc, #0xe14] */
/* @0xba980 ldr r2, [pc, #0xe14] */
/* @0xba984 ldr r1, [pc, #0xe14] */
/* @0xba988 ldr r3, [r4, r3] */
/* @0xba98c add r2, pc, r2 */
/* @0xba990 add r1, pc, r1 */
/* @0xba994 ldr r0, [r2] */
/* @0xba998 str r9, [r3] */
/* @0xba99c bl 0xb6514 <dlsym@plt> */
/* @0xba9a0 subs r9, r0, #0 */
/* @0xba9a4 beq 0xbc88c <_Z12GLFuncImportb+0x217c> */
/* @0xba9a8 ldr r3, [pc, #0xdf4] */
/* @0xba9ac ldr r2, [pc, #0xdf4] */
/* @0xba9b0 ldr r1, [pc, #0xdf4] */
/* @0xba9b4 ldr r3, [r4, r3] */
/* @0xba9b8 add r2, pc, r2 */
/* @0xba9bc add r1, pc, r1 */
/* @0xba9c0 ldr r0, [r2] */
/* @0xba9c4 str r9, [r3] */
/* @0xba9c8 bl 0xb6514 <dlsym@plt> */
/* @0xba9cc subs r9, r0, #0 */
/* @0xba9d0 beq 0xbc8ac <_Z12GLFuncImportb+0x219c> */
/* @0xba9d4 ldr r3, [pc, #0xdd4] */
/* @0xba9d8 ldr r2, [pc, #0xdd4] */
/* @0xba9dc ldr r1, [pc, #0xdd4] */
/* @0xba9e0 ldr r3, [r4, r3] */
/* @0xba9e4 add r2, pc, r2 */
/* @0xba9e8 add r1, pc, r1 */
/* @0xba9ec ldr r0, [r2] */
/* @0xba9f0 str r9, [r3] */
/* @0xba9f4 bl 0xb6514 <dlsym@plt> */
/* @0xba9f8 subs r9, r0, #0 */
/* @0xba9fc beq 0xbc5cc <_Z12GLFuncImportb+0x1ebc> */
/* @0xbaa00 ldr r3, [pc, #0xdb4] */
/* @0xbaa04 ldr r2, [pc, #0xdb4] */
/* @0xbaa08 ldr r1, [pc, #0xdb4] */
/* @0xbaa0c ldr r3, [r4, r3] */
/* @0xbaa10 add r2, pc, r2 */
/* @0xbaa14 add r1, pc, r1 */
/* @0xbaa18 ldr r0, [r2] */
/* @0xbaa1c str r9, [r3] */
/* @0xbaa20 bl 0xb6514 <dlsym@plt> */
/* @0xbaa24 subs r9, r0, #0 */
/* @0xbaa28 beq 0xbc5ec <_Z12GLFuncImportb+0x1edc> */
/* @0xbaa2c ldr r3, [pc, #0xd94] */
/* @0xbaa30 ldr r2, [pc, #0xd94] */
/* @0xbaa34 ldr r1, [pc, #0xd94] */
/* @0xbaa38 ldr r3, [r4, r3] */
/* @0xbaa3c add r2, pc, r2 */
/* @0xbaa40 add r1, pc, r1 */
/* @0xbaa44 ldr r0, [r2] */
/* @0xbaa48 str r9, [r3] */
/* @0xbaa4c bl 0xb6514 <dlsym@plt> */
/* @0xbaa50 subs r9, r0, #0 */
/* @0xbaa54 beq 0xbc60c <_Z12GLFuncImportb+0x1efc> */
/* @0xbaa58 ldr r3, [pc, #0xd74] */
/* @0xbaa5c ldr r2, [pc, #0xd74] */
/* @0xbaa60 ldr r1, [pc, #0xd74] */
/* @0xbaa64 ldr r3, [r4, r3] */
/* @0xbaa68 add r2, pc, r2 */
/* @0xbaa6c add r1, pc, r1 */
/* @0xbaa70 ldr r0, [r2] */
/* @0xbaa74 str r9, [r3] */
/* @0xbaa78 bl 0xb6514 <dlsym@plt> */
/* @0xbaa7c subs r9, r0, #0 */
/* @0xbaa80 beq 0xbc62c <_Z12GLFuncImportb+0x1f1c> */
/* @0xbaa84 ldr r3, [pc, #0xd54] */
/* @0xbaa88 ldr r2, [pc, #0xd54] */
/* @0xbaa8c ldr r1, [pc, #0xd54] */
/* @0xbaa90 ldr r3, [r4, r3] */
/* @0xbaa94 add r2, pc, r2 */
/* @0xbaa98 add r1, pc, r1 */
/* @0xbaa9c ldr r0, [r2] */
/* @0xbaaa0 str r9, [r3] */
/* @0xbaaa4 bl 0xb6514 <dlsym@plt> */
/* @0xbaaa8 subs r9, r0, #0 */
/* @0xbaaac beq 0xbc64c <_Z12GLFuncImportb+0x1f3c> */
/* @0xbaab0 ldr r3, [pc, #0xd34] */
/* @0xbaab4 ldr r2, [pc, #0xd34] */
/* @0xbaab8 ldr r1, [pc, #0xd34] */
/* @0xbaabc ldr r3, [r4, r3] */
/* @0xbaac0 add r2, pc, r2 */
/* @0xbaac4 add r1, pc, r1 */
/* @0xbaac8 ldr r0, [r2] */
/* @0xbaacc str r9, [r3] */
/* @0xbaad0 bl 0xb6514 <dlsym@plt> */
/* @0xbaad4 subs r9, r0, #0 */
/* @0xbaad8 beq 0xbc66c <_Z12GLFuncImportb+0x1f5c> */
/* @0xbaadc ldr r3, [pc, #0xd14] */
/* @0xbaae0 ldr r2, [pc, #0xd14] */
/* @0xbaae4 ldr r1, [pc, #0xd14] */
/* @0xbaae8 ldr r3, [r4, r3] */
/* @0xbaaec add r2, pc, r2 */
/* @0xbaaf0 add r1, pc, r1 */
/* @0xbaaf4 ldr r0, [r2] */
/* @0xbaaf8 str r9, [r3] */
/* @0xbaafc bl 0xb6514 <dlsym@plt> */
/* @0xbab00 subs r9, r0, #0 */
/* @0xbab04 beq 0xbc68c <_Z12GLFuncImportb+0x1f7c> */
/* @0xbab08 ldr r3, [pc, #0xcf4] */
/* @0xbab0c ldr r2, [pc, #0xcf4] */
/* @0xbab10 ldr r1, [pc, #0xcf4] */
/* @0xbab14 ldr r3, [r4, r3] */
/* @0xbab18 add r2, pc, r2 */
/* @0xbab1c add r1, pc, r1 */
/* @0xbab20 ldr r0, [r2] */
/* @0xbab24 str r9, [r3] */
/* @0xbab28 bl 0xb6514 <dlsym@plt> */
/* @0xbab2c subs r9, r0, #0 */
/* @0xbab30 beq 0xbc6ac <_Z12GLFuncImportb+0x1f9c> */
/* @0xbab34 ldr r3, [pc, #0xcd4] */
/* @0xbab38 ldr r2, [pc, #0xcd4] */
/* @0xbab3c ldr r1, [pc, #0xcd4] */
/* @0xbab40 ldr r3, [r4, r3] */
/* @0xbab44 add r2, pc, r2 */
/* @0xbab48 add r1, pc, r1 */
/* @0xbab4c ldr r0, [r2] */
/* @0xbab50 str r9, [r3] */
/* @0xbab54 bl 0xb6514 <dlsym@plt> */
/* @0xbab58 subs r9, r0, #0 */
/* @0xbab5c beq 0xbc6cc <_Z12GLFuncImportb+0x1fbc> */
/* @0xbab60 ldr r3, [pc, #0xcb4] */
/* @0xbab64 ldr r2, [pc, #0xcb4] */
/* @0xbab68 ldr r1, [pc, #0xcb4] */
/* @0xbab6c ldr r3, [r4, r3] */
/* @0xbab70 add r2, pc, r2 */
/* @0xbab74 add r1, pc, r1 */
/* @0xbab78 ldr r0, [r2] */
/* @0xbab7c str r9, [r3] */
/* @0xbab80 bl 0xb6514 <dlsym@plt> */
/* @0xbab84 subs r9, r0, #0 */
/* @0xbab88 beq 0xbc6ec <_Z12GLFuncImportb+0x1fdc> */
/* @0xbab8c ldr r3, [pc, #0xc94] */
/* @0xbab90 ldr r2, [pc, #0xc94] */
/* @0xbab94 ldr r1, [pc, #0xc94] */
/* @0xbab98 ldr r3, [r4, r3] */
/* @0xbab9c add r2, pc, r2 */
/* @0xbaba0 add r1, pc, r1 */
/* @0xbaba4 ldr r0, [r2] */
/* @0xbaba8 str r9, [r3] */
/* @0xbabac bl 0xb6514 <dlsym@plt> */
/* @0xbabb0 subs r9, r0, #0 */
/* @0xbabb4 beq 0xbc70c <_Z12GLFuncImportb+0x1ffc> */
/* @0xbabb8 ldr r3, [pc, #0xc74] */
/* @0xbabbc ldr r2, [pc, #0xc74] */
/* @0xbabc0 ldr r1, [pc, #0xc74] */
/* @0xbabc4 ldr r3, [r4, r3] */
/* @0xbabc8 add r2, pc, r2 */
/* @0xbabcc add r1, pc, r1 */
/* @0xbabd0 ldr r0, [r2] */
/* @0xbabd4 str r9, [r3] */
/* @0xbabd8 bl 0xb6514 <dlsym@plt> */
/* @0xbabdc subs r9, r0, #0 */
/* @0xbabe0 beq 0xbc72c <_Z12GLFuncImportb+0x201c> */
/* @0xbabe4 ldr r3, [pc, #0xc54] */
/* @0xbabe8 ldr r2, [pc, #0xc54] */
/* @0xbabec ldr r1, [pc, #0xc54] */
/* @0xbabf0 ldr r3, [r4, r3] */
/* @0xbabf4 add r2, pc, r2 */
/* @0xbabf8 add r1, pc, r1 */
/* @0xbabfc ldr r0, [r2] */
/* @0xbac00 str r9, [r3] */
/* @0xbac04 bl 0xb6514 <dlsym@plt> */
/* @0xbac08 subs r9, r0, #0 */
/* @0xbac0c beq 0xbc74c <_Z12GLFuncImportb+0x203c> */
/* @0xbac10 ldr r3, [pc, #0xc34] */
/* @0xbac14 ldr r2, [pc, #0xc34] */
/* @0xbac18 ldr r1, [pc, #0xc34] */
/* @0xbac1c ldr r3, [r4, r3] */
/* @0xbac20 add r2, pc, r2 */
/* @0xbac24 add r1, pc, r1 */
/* @0xbac28 ldr r0, [r2] */
/* @0xbac2c str r9, [r3] */
/* @0xbac30 bl 0xb6514 <dlsym@plt> */
/* @0xbac34 subs r9, r0, #0 */
/* @0xbac38 beq 0xbc76c <_Z12GLFuncImportb+0x205c> */
/* @0xbac3c ldr r3, [pc, #0xc14] */
/* @0xbac40 ldr r2, [pc, #0xc14] */
/* @0xbac44 ldr r1, [pc, #0xc14] */
/* @0xbac48 ldr r3, [r4, r3] */
/* @0xbac4c add r2, pc, r2 */
/* @0xbac50 add r1, pc, r1 */
/* @0xbac54 ldr r0, [r2] */
/* @0xbac58 str r9, [r3] */
/* @0xbac5c bl 0xb6514 <dlsym@plt> */
/* @0xbac60 subs r9, r0, #0 */
/* @0xbac64 beq 0xbc78c <_Z12GLFuncImportb+0x207c> */
/* @0xbac68 ldr r3, [pc, #0xbf4] */
/* @0xbac6c ldr r2, [pc, #0xbf4] */
/* @0xbac70 ldr r1, [pc, #0xbf4] */
/* @0xbac74 ldr r3, [r4, r3] */
/* @0xbac78 add r2, pc, r2 */
/* @0xbac7c add r1, pc, r1 */
/* @0xbac80 ldr r0, [r2] */
/* @0xbac84 str r9, [r3] */
/* @0xbac88 bl 0xb6514 <dlsym@plt> */
/* @0xbac8c subs r9, r0, #0 */
/* @0xbac90 beq 0xbc7ac <_Z12GLFuncImportb+0x209c> */
/* @0xbac94 ldr r3, [pc, #0xbd4] */
/* @0xbac98 ldr r2, [pc, #0xbd4] */
/* @0xbac9c ldr r1, [pc, #0xbd4] */
/* @0xbaca0 ldr r3, [r4, r3] */
/* @0xbaca4 add r2, pc, r2 */
/* @0xbaca8 add r1, pc, r1 */
/* @0xbacac ldr r0, [r2] */
/* @0xbacb0 str r9, [r3] */
/* @0xbacb4 bl 0xb6514 <dlsym@plt> */
/* @0xbacb8 subs r9, r0, #0 */
/* @0xbacbc beq 0xbc9cc <_Z12GLFuncImportb+0x22bc> */
/* @0xbacc0 ldr r3, [pc, #0xbb4] */
/* @0xbacc4 ldr r2, [pc, #0xbb4] */
/* @0xbacc8 ldr r1, [pc, #0xbb4] */
/* @0xbaccc ldr r3, [r4, r3] */
/* @0xbacd0 add r2, pc, r2 */
/* @0xbacd4 add r1, pc, r1 */
/* @0xbacd8 ldr r0, [r2] */
/* @0xbacdc str r9, [r3] */
/* @0xbace0 bl 0xb6514 <dlsym@plt> */
/* @0xbace4 subs r9, r0, #0 */
/* @0xbace8 beq 0xbc9ec <_Z12GLFuncImportb+0x22dc> */
/* @0xbacec ldr r3, [pc, #0xb94] */
/* @0xbacf0 ldr r2, [pc, #0xb94] */
/* @0xbacf4 ldr r1, [pc, #0xb94] */
/* @0xbacf8 ldr r3, [r4, r3] */
/* @0xbacfc add r2, pc, r2 */
/* @0xbad00 add r1, pc, r1 */
/* @0xbad04 ldr r0, [r2] */
/* @0xbad08 str r9, [r3] */
/* @0xbad0c bl 0xb6514 <dlsym@plt> */
/* @0xbad10 subs r9, r0, #0 */
/* @0xbad14 beq 0xbca0c <_Z12GLFuncImportb+0x22fc> */
/* @0xbad18 ldr r3, [pc, #0xb74] */
/* @0xbad1c ldr r2, [pc, #0xb74] */
/* @0xbad20 ldr r1, [pc, #0xb74] */
/* @0xbad24 ldr r3, [r4, r3] */
/* @0xbad28 add r2, pc, r2 */
/* @0xbad2c add r1, pc, r1 */
/* @0xbad30 ldr r0, [r2] */
/* @0xbad34 str r9, [r3] */
/* @0xbad38 bl 0xb6514 <dlsym@plt> */
/* @0xbad3c subs r9, r0, #0 */
/* @0xbad40 beq 0xbca2c <_Z12GLFuncImportb+0x231c> */
/* @0xbad44 ldr r3, [pc, #0xb54] */
/* @0xbad48 ldr r2, [pc, #0xb54] */
/* @0xbad4c ldr r1, [pc, #0xb54] */
/* @0xbad50 ldr r3, [r4, r3] */
/* @0xbad54 add r2, pc, r2 */
/* @0xbad58 add r1, pc, r1 */
/* @0xbad5c ldr r0, [r2] */
/* @0xbad60 str r9, [r3] */
/* @0xbad64 bl 0xb6514 <dlsym@plt> */
/* @0xbad68 subs r9, r0, #0 */
/* @0xbad6c beq 0xbca4c <_Z12GLFuncImportb+0x233c> */
/* @0xbad70 ldr r3, [pc, #0xb34] */
/* @0xbad74 ldr r2, [pc, #0xb34] */
/* @0xbad78 ldr r1, [pc, #0xb34] */
/* @0xbad7c ldr r3, [r4, r3] */
/* @0xbad80 add r2, pc, r2 */
/* @0xbad84 add r1, pc, r1 */
/* @0xbad88 ldr r0, [r2] */
/* @0xbad8c str r9, [r3] */
/* @0xbad90 bl 0xb6514 <dlsym@plt> */
/* @0xbad94 subs r9, r0, #0 */
/* @0xbad98 beq 0xbca6c <_Z12GLFuncImportb+0x235c> */
/* @0xbad9c ldr r3, [pc, #0xb14] */
/* @0xbada0 ldr r2, [pc, #0xb14] */
/* @0xbada4 ldr r1, [pc, #0xb14] */
/* @0xbada8 ldr r3, [r4, r3] */
/* @0xbadac add r2, pc, r2 */
/* @0xbadb0 add r1, pc, r1 */
/* @0xbadb4 ldr r0, [r2] */
/* @0xbadb8 str r9, [r3] */
/* @0xbadbc bl 0xb6514 <dlsym@plt> */
/* @0xbadc0 subs r9, r0, #0 */
/* @0xbadc4 beq 0xbca8c <_Z12GLFuncImportb+0x237c> */
/* @0xbadc8 ldr r3, [pc, #0xaf4] */
/* @0xbadcc ldr r2, [pc, #0xaf4] */
/* @0xbadd0 ldr r1, [pc, #0xaf4] */
/* @0xbadd4 ldr r3, [r4, r3] */
/* @0xbadd8 add r2, pc, r2 */
/* @0xbaddc add r1, pc, r1 */
/* @0xbade0 ldr r0, [r2] */
/* @0xbade4 str r9, [r3] */
/* @0xbade8 bl 0xb6514 <dlsym@plt> */
/* @0xbadec subs r9, r0, #0 */
/* @0xbadf0 beq 0xbcaac <_Z12GLFuncImportb+0x239c> */
/* @0xbadf4 ldr r3, [pc, #0xad4] */
/* @0xbadf8 ldr r2, [pc, #0xad4] */
/* @0xbadfc ldr r1, [pc, #0xad4] */
/* @0xbae00 ldr r3, [r4, r3] */
/* @0xbae04 add r2, pc, r2 */
/* @0xbae08 add r1, pc, r1 */
/* @0xbae0c ldr r0, [r2] */
/* @0xbae10 str r9, [r3] */
/* @0xbae14 bl 0xb6514 <dlsym@plt> */
/* @0xbae18 subs r9, r0, #0 */
/* @0xbae1c beq 0xbc94c <_Z12GLFuncImportb+0x223c> */
/* @0xbae20 ldr r3, [pc, #0xab4] */
/* @0xbae24 ldr r2, [pc, #0xab4] */
/* @0xbae28 ldr r1, [pc, #0xab4] */
/* @0xbae2c ldr r3, [r4, r3] */
/* @0xbae30 add r2, pc, r2 */
/* @0xbae34 add r1, pc, r1 */
/* @0xbae38 ldr r0, [r2] */
/* @0xbae3c str r9, [r3] */
/* @0xbae40 bl 0xb6514 <dlsym@plt> */
/* @0xbae44 subs r9, r0, #0 */
/* @0xbae48 beq 0xbc96c <_Z12GLFuncImportb+0x225c> */
/* @0xbae4c ldr r3, [pc, #0xa94] */
/* @0xbae50 cmp r8, #0 */
/* @0xbae54 ldr r3, [r4, r3] */
/* @0xbae58 str r9, [r3] */
/* @0xbae5c beq 0xbbe44 <_Z12GLFuncImportb+0x1734> */
/* @0xbae60 ldr r3, [pc, #0xa84] */
/* @0xbae64 ldr r1, [pc, #0xa84] */
/* @0xbae68 add r3, pc, r3 */
/* @0xbae6c add r1, pc, r1 */
/* @0xbae70 ldr r0, [r3] */
/* @0xbae74 bl 0xb6514 <dlsym@plt> */
/* @0xbae78 subs r8, r0, #0 */
/* @0xbae7c beq 0xbcc2c <_Z12GLFuncImportb+0x251c> */
/* @0xbae80 ldr r3, [pc, #0xa6c] */
/* @0xbae84 ldr r2, [pc, #0xa6c] */
/* @0xbae88 ldr r1, [pc, #0xa6c] */
/* @0xbae8c ldr r3, [r4, r3] */
/* @0xbae90 add r2, pc, r2 */
/* @0xbae94 add r1, pc, r1 */
/* @0xbae98 ldr r0, [r2] */
/* @0xbae9c str r8, [r3] */
/* @0xbaea0 bl 0xb6514 <dlsym@plt> */
/* @0xbaea4 subs r8, r0, #0 */
/* @0xbaea8 beq 0xbc5ac <_Z12GLFuncImportb+0x1e9c> */
/* @0xbaeac ldr r3, [pc, #0xa4c] */
/* @0xbaeb0 ldr r2, [pc, #0xa4c] */
/* @0xbaeb4 ldr r1, [pc, #0xa4c] */
/* @0xbaeb8 ldr r3, [r4, r3] */
/* @0xbaebc add r2, pc, r2 */
/* @0xbaec0 add r1, pc, r1 */
/* @0xbaec4 ldr r0, [r2] */
/* @0xbaec8 str r8, [r3] */
/* @0xbaecc bl 0xb6514 <dlsym@plt> */
/* @0xbaed0 subs r8, r0, #0 */
/* @0xbaed4 beq 0xbcc0c <_Z12GLFuncImportb+0x24fc> */
/* @0xbaed8 ldr r3, [pc, #0xa2c] */
/* @0xbaedc ldr r2, [pc, #0xa2c] */
/* @0xbaee0 ldr r1, [pc, #0xa2c] */
/* @0xbaee4 ldr r3, [r4, r3] */
/* @0xbaee8 add r2, pc, r2 */
/* @0xbaeec add r1, pc, r1 */
/* @0xbaef0 ldr r0, [r2] */
/* @0xbaef4 str r8, [r3] */
/* @0xbaef8 bl 0xb6514 <dlsym@plt> */
/* @0xbaefc subs r8, r0, #0 */
/* @0xbaf00 beq 0xbcbec <_Z12GLFuncImportb+0x24dc> */
/* @0xbaf04 ldr r3, [pc, #0xa0c] */
/* @0xbaf08 ldr r2, [pc, #0xa0c] */
/* @0xbaf0c ldr r1, [pc, #0xa0c] */
/* @0xbaf10 ldr r3, [r4, r3] */
/* @0xbaf14 add r2, pc, r2 */
/* @0xbaf18 add r1, pc, r1 */
/* @0xbaf1c ldr r0, [r2] */
/* @0xbaf20 str r8, [r3] */
/* @0xbaf24 bl 0xb6514 <dlsym@plt> */
/* @0xbaf28 subs r8, r0, #0 */
/* @0xbaf2c beq 0xbcbcc <_Z12GLFuncImportb+0x24bc> */
/* @0xbaf30 ldr r3, [pc, #0x9ec] */
/* @0xbaf34 ldr r2, [pc, #0x9ec] */
/* @0xbaf38 ldr r1, [pc, #0x9ec] */
/* @0xbaf3c ldr r3, [r4, r3] */
/* @0xbaf40 add r2, pc, r2 */
/* @0xbaf44 add r1, pc, r1 */
/* @0xbaf48 ldr r0, [r2] */
/* @0xbaf4c str r8, [r3] */
/* @0xbaf50 bl 0xb6514 <dlsym@plt> */
/* @0xbaf54 subs r8, r0, #0 */
/* @0xbaf58 beq 0xbcbac <_Z12GLFuncImportb+0x249c> */
/* @0xbaf5c ldr r3, [pc, #0x9cc] */
/* @0xbaf60 ldr r2, [pc, #0x9cc] */
/* @0xbaf64 ldr r1, [pc, #0x9cc] */
/* @0xbaf68 ldr r3, [r4, r3] */
/* @0xbaf6c add r2, pc, r2 */
/* @0xbaf70 add r1, pc, r1 */
/* @0xbaf74 ldr r0, [r2] */
/* @0xbaf78 str r8, [r3] */
/* @0xbaf7c bl 0xb6514 <dlsym@plt> */
/* @0xbaf80 subs r8, r0, #0 */
/* @0xbaf84 beq 0xbcb8c <_Z12GLFuncImportb+0x247c> */
/* @0xbaf88 ldr r3, [pc, #0x9ac] */
/* @0xbaf8c ldr r2, [pc, #0x9ac] */
/* @0xbaf90 ldr r1, [pc, #0x9ac] */
/* @0xbaf94 ldr r3, [r4, r3] */
/* @0xbaf98 add r2, pc, r2 */
/* @0xbaf9c add r1, pc, r1 */
/* @0xbafa0 ldr r0, [r2] */
/* @0xbafa4 str r8, [r3] */
/* @0xbafa8 bl 0xb6514 <dlsym@plt> */
/* @0xbafac subs r8, r0, #0 */
/* @0xbafb0 beq 0xbcb6c <_Z12GLFuncImportb+0x245c> */
/* @0xbafb4 ldr r3, [pc, #0x98c] */
/* @0xbafb8 ldr r2, [pc, #0x98c] */
/* @0xbafbc ldr r1, [pc, #0x98c] */
/* @0xbafc0 ldr r3, [r4, r3] */
/* @0xbafc4 add r2, pc, r2 */
/* @0xbafc8 add r1, pc, r1 */
/* @0xbafcc ldr r0, [r2] */
/* @0xbafd0 str r8, [r3] */
/* @0xbafd4 bl 0xb6514 <dlsym@plt> */
/* @0xbafd8 subs r8, r0, #0 */
/* @0xbafdc beq 0xbcb4c <_Z12GLFuncImportb+0x243c> */
/* @0xbafe0 ldr r3, [pc, #0x96c] */
/* @0xbafe4 ldr r2, [pc, #0x96c] */
/* @0xbafe8 ldr r1, [pc, #0x96c] */
/* @0xbafec ldr r3, [r4, r3] */
/* @0xbaff0 add r2, pc, r2 */
/* @0xbaff4 add r1, pc, r1 */
/* @0xbaff8 ldr r0, [r2] */
/* @0xbaffc str r8, [r3] */
/* @0xbb000 bl 0xb6514 <dlsym@plt> */
/* @0xbb004 subs r8, r0, #0 */
/* @0xbb008 beq 0xbcb2c <_Z12GLFuncImportb+0x241c> */
/* @0xbb00c ldr r3, [pc, #0x94c] */
/* @0xbb010 ldr r2, [pc, #0x94c] */
/* @0xbb014 ldr r1, [pc, #0x94c] */
/* @0xbb018 ldr r3, [r4, r3] */
/* @0xbb01c add r2, pc, r2 */
/* @0xbb020 add r1, pc, r1 */
/* @0xbb024 ldr r0, [r2] */
/* @0xbb028 str r8, [r3] */
/* @0xbb02c bl 0xb6514 <dlsym@plt> */
/* @0xbb030 subs r8, r0, #0 */
/* @0xbb034 beq 0xbcb0c <_Z12GLFuncImportb+0x23fc> */
/* @0xbb038 ldr r3, [pc, #0x92c] */
/* @0xbb03c ldr r2, [pc, #0x92c] */
/* @0xbb040 ldr r1, [pc, #0x92c] */
/* @0xbb044 ldr r3, [r4, r3] */
/* @0xbb048 add r2, pc, r2 */
/* @0xbb04c add r1, pc, r1 */
/* @0xbb050 ldr r0, [r2] */
/* @0xbb054 str r8, [r3] */
/* @0xbb058 bl 0xb6514 <dlsym@plt> */
/* @0xbb05c subs r8, r0, #0 */
/* @0xbb060 beq 0xbcaec <_Z12GLFuncImportb+0x23dc> */
/* @0xbb064 ldr r3, [pc, #0x90c] */
/* @0xbb068 ldr r2, [pc, #0x90c] */
/* @0xbb06c ldr r1, [pc, #0x90c] */
/* @0xbb070 ldr r3, [r4, r3] */
/* @0xbb074 add r2, pc, r2 */
/* @0xbb078 add r1, pc, r1 */
/* @0xbb07c ldr r0, [r2] */
/* @0xbb080 str r8, [r3] */
/* @0xbb084 bl 0xb6514 <dlsym@plt> */
/* @0xbb088 subs r8, r0, #0 */
/* @0xbb08c beq 0xbcacc <_Z12GLFuncImportb+0x23bc> */
/* @0xbb090 ldr r3, [pc, #0x8ec] */
/* @0xbb094 ldr r2, [pc, #0x8ec] */
/* @0xbb098 ldr r1, [pc, #0x8ec] */
/* @0xbb09c ldr r3, [r4, r3] */
/* @0xbb0a0 add r2, pc, r2 */
/* @0xbb0a4 add r1, pc, r1 */
/* @0xbb0a8 ldr r0, [r2] */
/* @0xbb0ac str r8, [r3] */
/* @0xbb0b0 bl 0xb6514 <dlsym@plt> */
/* @0xbb0b4 subs r8, r0, #0 */
/* @0xbb0b8 beq 0xbd18c <_Z12GLFuncImportb+0x2a7c> */
/* @0xbb0bc ldr r3, [pc, #0x8cc] */
/* @0xbb0c0 ldr r2, [pc, #0x8cc] */
/* @0xbb0c4 ldr r1, [pc, #0x8cc] */
/* @0xbb0c8 ldr r3, [r4, r3] */
/* @0xbb0cc add r2, pc, r2 */
/* @0xbb0d0 add r1, pc, r1 */
/* @0xbb0d4 ldr r0, [r2] */
/* @0xbb0d8 str r8, [r3] */
/* @0xbb0dc bl 0xb6514 <dlsym@plt> */
/* @0xbb0e0 subs r8, r0, #0 */
/* @0xbb0e4 beq 0xbd16c <_Z12GLFuncImportb+0x2a5c> */
/* @0xbb0e8 ldr r3, [pc, #0x8ac] */
/* @0xbb0ec ldr r2, [pc, #0x8ac] */
/* @0xbb0f0 ldr r1, [pc, #0x8ac] */
/* @0xbb0f4 ldr r3, [r4, r3] */
/* @0xbb0f8 add r2, pc, r2 */
/* @0xbb0fc add r1, pc, r1 */
/* @0xbb100 ldr r0, [r2] */
/* @0xbb104 str r8, [r3] */
/* @0xbb108 bl 0xb6514 <dlsym@plt> */
/* @0xbb10c subs r8, r0, #0 */
/* @0xbb110 beq 0xbd14c <_Z12GLFuncImportb+0x2a3c> */
/* @0xbb114 ldr r3, [pc, #0x88c] */
/* @0xbb118 ldr r2, [pc, #0x88c] */
/* @0xbb11c ldr r1, [pc, #0x88c] */
/* @0xbb120 ldr r3, [r4, r3] */
/* @0xbb124 add r2, pc, r2 */
/* @0xbb128 add r1, pc, r1 */
/* @0xbb12c ldr r0, [r2] */
/* @0xbb130 str r8, [r3] */
/* @0xbb134 bl 0xb6514 <dlsym@plt> */
/* @0xbb138 subs r8, r0, #0 */
/* @0xbb13c beq 0xbd12c <_Z12GLFuncImportb+0x2a1c> */
/* @0xbb140 ldr r3, [pc, #0x86c] */
/* @0xbb144 ldr r2, [pc, #0x86c] */
/* @0xbb148 ldr r1, [pc, #0x86c] */
/* @0xbb14c ldr r3, [r4, r3] */
/* @0xbb150 add r2, pc, r2 */
/* @0xbb154 add r1, pc, r1 */
/* @0xbb158 ldr r0, [r2] */
/* @0xbb15c str r8, [r3] */
/* @0xbb160 bl 0xb6514 <dlsym@plt> */
/* @0xbb164 subs r8, r0, #0 */
/* @0xbb168 beq 0xbd10c <_Z12GLFuncImportb+0x29fc> */
/* @0xbb16c ldr r3, [pc, #0x84c] */
/* @0xbb170 ldr r2, [pc, #0x84c] */
/* @0xbb174 ldr r1, [pc, #0x84c] */
/* @0xbb178 ldr r3, [r4, r3] */
/* @0xbb17c add r2, pc, r2 */
/* @0xbb180 add r1, pc, r1 */
/* @0xbb184 ldr r0, [r2] */
/* @0xbb188 str r8, [r3] */
/* @0xbb18c bl 0xb6514 <dlsym@plt> */
/* @0xbb190 subs r8, r0, #0 */
/* @0xbb194 beq 0xbd0ec <_Z12GLFuncImportb+0x29dc> */
/* @0xbb198 ldr r3, [pc, #0x82c] */
/* @0xbb19c ldr r2, [pc, #0x82c] */
/* @0xbb1a0 ldr r1, [pc, #0x82c] */
/* @0xbb1a4 ldr r3, [r4, r3] */
/* @0xbb1a8 add r2, pc, r2 */
/* @0xbb1ac add r1, pc, r1 */
/* @0xbb1b0 ldr r0, [r2] */
/* @0xbb1b4 str r8, [r3] */
/* @0xbb1b8 bl 0xb6514 <dlsym@plt> */
/* @0xbb1bc subs r8, r0, #0 */
/* @0xbb1c0 beq 0xbd0cc <_Z12GLFuncImportb+0x29bc> */
/* @0xbb1c4 ldr r3, [pc, #0x80c] */
/* @0xbb1c8 ldr r2, [pc, #0x80c] */
/* @0xbb1cc ldr r1, [pc, #0x80c] */
/* @0xbb1d0 ldr r3, [r4, r3] */
/* @0xbb1d4 add r2, pc, r2 */
/* @0xbb1d8 add r1, pc, r1 */
/* @0xbb1dc ldr r0, [r2] */
/* @0xbb1e0 str r8, [r3] */
/* @0xbb1e4 bl 0xb6514 <dlsym@plt> */
/* @0xbb1e8 subs r8, r0, #0 */
/* @0xbb1ec beq 0xbd0ac <_Z12GLFuncImportb+0x299c> */
/* @0xbb1f0 ldr r3, [pc, #0x7ec] */
/* @0xbb1f4 ldr r2, [pc, #0x7ec] */
/* @0xbb1f8 ldr r1, [pc, #0x7ec] */
/* @0xbb1fc ldr r3, [r4, r3] */
/* @0xbb200 add r2, pc, r2 */
/* @0xbb204 add r1, pc, r1 */
/* @0xbb208 ldr r0, [r2] */
/* @0xbb20c str r8, [r3] */
/* @0xbb210 bl 0xb6514 <dlsym@plt> */
/* @0xbb214 subs r8, r0, #0 */
/* @0xbb218 beq 0xbd08c <_Z12GLFuncImportb+0x297c> */
/* @0xbb21c ldr r3, [pc, #0x7cc] */
/* @0xbb220 ldr r2, [pc, #0x7cc] */
/* @0xbb224 ldr r1, [pc, #0x7cc] */
/* @0xbb228 ldr r3, [r4, r3] */
/* @0xbb22c add r2, pc, r2 */
/* @0xbb230 add r1, pc, r1 */
/* @0xbb234 ldr r0, [r2] */
/* @0xbb238 str r8, [r3] */
/* @0xbb23c bl 0xb6514 <dlsym@plt> */
/* @0xbb240 subs r8, r0, #0 */
/* @0xbb244 beq 0xbd06c <_Z12GLFuncImportb+0x295c> */
/* @0xbb248 ldr r3, [pc, #0x7ac] */
/* @0xbb24c ldr r2, [pc, #0x7ac] */
/* @0xbb250 ldr r1, [pc, #0x7ac] */
/* @0xbb254 ldr r3, [r4, r3] */
/* @0xbb258 add r2, pc, r2 */
/* @0xbb25c add r1, pc, r1 */
/* @0xbb260 ldr r0, [r2] */
/* @0xbb264 str r8, [r3] */
/* @0xbb268 bl 0xb6514 <dlsym@plt> */
/* @0xbb26c subs r8, r0, #0 */
/* @0xbb270 beq 0xbd04c <_Z12GLFuncImportb+0x293c> */
/* @0xbb274 ldr r3, [pc, #0x78c] */
/* @0xbb278 ldr r2, [pc, #0x78c] */
/* @0xbb27c ldr r1, [pc, #0x78c] */
/* @0xbb280 ldr r3, [r4, r3] */
/* @0xbb284 add r2, pc, r2 */
/* @0xbb288 add r1, pc, r1 */
/* @0xbb28c ldr r0, [r2] */
/* @0xbb290 str r8, [r3] */
/* @0xbb294 bl 0xb6514 <dlsym@plt> */
/* @0xbb298 subs r8, r0, #0 */
/* @0xbb29c beq 0xbd02c <_Z12GLFuncImportb+0x291c> */
/* @0xbb2a0 ldr r3, [pc, #0x76c] */
/* @0xbb2a4 ldr r2, [pc, #0x76c] */
/* @0xbb2a8 ldr r1, [pc, #0x76c] */
/* @0xbb2ac ldr r3, [r4, r3] */
/* @0xbb2b0 add r2, pc, r2 */
/* @0xbb2b4 add r1, pc, r1 */
/* @0xbb2b8 ldr r0, [r2] */
/* @0xbb2bc str r8, [r3] */
/* @0xbb2c0 bl 0xb6514 <dlsym@plt> */
/* @0xbb2c4 subs r8, r0, #0 */
/* @0xbb2c8 beq 0xbd00c <_Z12GLFuncImportb+0x28fc> */
/* @0xbb2cc ldr r3, [pc, #0x74c] */
/* @0xbb2d0 ldr r2, [pc, #0x74c] */
/* @0xbb2d4 ldr r1, [pc, #0x74c] */
/* @0xbb2d8 ldr r3, [r4, r3] */
/* @0xbb2dc add r2, pc, r2 */
/* @0xbb2e0 add r1, pc, r1 */
/* @0xbb2e4 ldr r0, [r2] */
/* @0xbb2e8 str r8, [r3] */
/* @0xbb2ec bl 0xb6514 <dlsym@plt> */
/* @0xbb2f0 subs r8, r0, #0 */
/* @0xbb2f4 beq 0xbcfec <_Z12GLFuncImportb+0x28dc> */
/* @0xbb2f8 ldr r3, [pc, #0x72c] */
/* @0xbb2fc ldr r2, [pc, #0x72c] */
/* @0xbb300 ldr r1, [pc, #0x72c] */
/* @0xbb304 ldr r3, [r4, r3] */
/* @0xbb308 add r2, pc, r2 */
/* @0xbb30c add r1, pc, r1 */
/* @0xbb310 ldr r0, [r2] */
/* @0xbb314 str r8, [r3] */
/* @0xbb318 bl 0xb6514 <dlsym@plt> */
/* @0xbb31c subs r8, r0, #0 */
/* @0xbb320 beq 0xbcfcc <_Z12GLFuncImportb+0x28bc> */
/* @0xbb324 ldr r3, [pc, #0x70c] */
/* @0xbb328 ldr r2, [pc, #0x70c] */
/* @0xbb32c ldr r1, [pc, #0x70c] */
/* @0xbb330 ldr r3, [r4, r3] */
/* @0xbb334 add r2, pc, r2 */
/* @0xbb338 add r1, pc, r1 */
/* @0xbb33c ldr r0, [r2] */
/* @0xbb340 str r8, [r3] */
/* @0xbb344 bl 0xb6514 <dlsym@plt> */
/* @0xbb348 subs r8, r0, #0 */
/* @0xbb34c beq 0xbcfac <_Z12GLFuncImportb+0x289c> */
/* @0xbb350 ldr r3, [pc, #0x6ec] */
/* @0xbb354 ldr r2, [pc, #0x6ec] */
/* @0xbb358 ldr r1, [pc, #0x6ec] */
/* @0xbb35c ldr r3, [r4, r3] */
/* @0xbb360 add r2, pc, r2 */
/* @0xbb364 add r1, pc, r1 */
/* @0xbb368 ldr r0, [r2] */
/* @0xbb36c str r8, [r3] */
/* @0xbb370 bl 0xb6514 <dlsym@plt> */
/* @0xbb374 subs r8, r0, #0 */
/* @0xbb378 beq 0xbcf8c <_Z12GLFuncImportb+0x287c> */
/* @0xbb37c ldr r3, [pc, #0x6cc] */
/* @0xbb380 ldr r2, [pc, #0x6cc] */
/* @0xbb384 ldr r1, [pc, #0x6cc] */
/* @0xbb388 ldr r3, [r4, r3] */
/* @0xbb38c add r2, pc, r2 */
/* @0xbb390 add r1, pc, r1 */
/* @0xbb394 ldr r0, [r2] */
/* @0xbb398 str r8, [r3] */
/* @0xbb39c bl 0xb6514 <dlsym@plt> */
/* @0xbb3a0 subs r8, r0, #0 */
/* @0xbb3a4 beq 0xbcf6c <_Z12GLFuncImportb+0x285c> */
/* @0xbb3a8 ldr r3, [pc, #0x6ac] */
/* @0xbb3ac ldr r2, [pc, #0x6ac] */
/* @0xbb3b0 ldr r1, [pc, #0x6ac] */
/* @0xbb3b4 ldr r3, [r4, r3] */
/* @0xbb3b8 add r2, pc, r2 */
/* @0xbb3bc add r1, pc, r1 */
/* @0xbb3c0 ldr r0, [r2] */
/* @0xbb3c4 str r8, [r3] */
/* @0xbb3c8 bl 0xb6514 <dlsym@plt> */
/* @0xbb3cc subs r8, r0, #0 */
/* @0xbb3d0 beq 0xbcf4c <_Z12GLFuncImportb+0x283c> */
/* @0xbb3d4 ldr r3, [pc, #0x68c] */
/* @0xbb3d8 ldr r2, [pc, #0x68c] */
/* @0xbb3dc ldr r1, [pc, #0x68c] */
/* @0xbb3e0 ldr r3, [r4, r3] */
/* @0xbb3e4 add r2, pc, r2 */
/* @0xbb3e8 add r1, pc, r1 */
/* @0xbb3ec ldr r0, [r2] */
/* @0xbb3f0 str r8, [r3] */
/* @0xbb3f4 bl 0xb6514 <dlsym@plt> */
/* @0xbb3f8 subs r8, r0, #0 */
/* @0xbb3fc beq 0xbcf2c <_Z12GLFuncImportb+0x281c> */
/* @0xbb400 ldr r3, [pc, #0x66c] */
/* @0xbb404 ldr r2, [pc, #0x66c] */
/* @0xbb408 ldr r1, [pc, #0x66c] */
/* @0xbb40c ldr r3, [r4, r3] */
/* @0xbb410 add r2, pc, r2 */
/* @0xbb414 add r1, pc, r1 */
/* @0xbb418 ldr r0, [r2] */
/* @0xbb41c str r8, [r3] */
/* @0xbb420 bl 0xb6514 <dlsym@plt> */
/* @0xbb424 subs r8, r0, #0 */
/* @0xbb428 beq 0xbcf0c <_Z12GLFuncImportb+0x27fc> */
/* @0xbb42c ldr r3, [pc, #0x64c] */
/* @0xbb430 ldr r2, [pc, #0x64c] */
/* @0xbb434 ldr r1, [pc, #0x64c] */
/* @0xbb438 ldr r3, [r4, r3] */
/* @0xbb43c add r2, pc, r2 */
/* @0xbb440 add r1, pc, r1 */
/* @0xbb444 ldr r0, [r2] */
/* @0xbb448 str r8, [r3] */
/* @0xbb44c bl 0xb6514 <dlsym@plt> */
/* @0xbb450 subs r8, r0, #0 */
/* @0xbb454 beq 0xbceec <_Z12GLFuncImportb+0x27dc> */
/* @0xbb458 ldr r3, [pc, #0x62c] */
/* @0xbb45c ldr r2, [pc, #0x62c] */
/* @0xbb460 ldr r1, [pc, #0x62c] */
/* @0xbb464 ldr r3, [r4, r3] */
/* @0xbb468 add r2, pc, r2 */
/* @0xbb46c add r1, pc, r1 */
/* @0xbb470 ldr r0, [r2] */
/* @0xbb474 str r8, [r3] */
/* @0xbb478 bl 0xb6514 <dlsym@plt> */
/* @0xbb47c subs r8, r0, #0 */
/* @0xbb480 beq 0xbcecc <_Z12GLFuncImportb+0x27bc> */
/* @0xbb484 ldr r3, [pc, #0x60c] */
/* @0xbb488 ldr r2, [pc, #0x60c] */
/* @0xbb48c ldr r1, [pc, #0x60c] */
/* @0xbb490 ldr r3, [r4, r3] */
/* @0xbb494 add r2, pc, r2 */
/* @0xbb498 add r1, pc, r1 */
/* @0xbb49c ldr r0, [r2] */
/* @0xbb4a0 str r8, [r3] */
/* @0xbb4a4 bl 0xb6514 <dlsym@plt> */
/* @0xbb4a8 subs r8, r0, #0 */
/* @0xbb4ac beq 0xbceac <_Z12GLFuncImportb+0x279c> */
/* @0xbb4b0 ldr r3, [pc, #0x5ec] */
/* @0xbb4b4 ldr r2, [pc, #0x5ec] */
/* @0xbb4b8 ldr r1, [pc, #0x5ec] */
/* @0xbb4bc ldr r3, [r4, r3] */
/* @0xbb4c0 add r2, pc, r2 */
/* @0xbb4c4 add r1, pc, r1 */
/* @0xbb4c8 ldr r0, [r2] */
/* @0xbb4cc str r8, [r3] */
/* @0xbb4d0 bl 0xb6514 <dlsym@plt> */
/* @0xbb4d4 subs r8, r0, #0 */
/* @0xbb4d8 beq 0xbce8c <_Z12GLFuncImportb+0x277c> */
/* @0xbb4dc ldr r3, [pc, #0x5cc] */
/* @0xbb4e0 ldr r2, [pc, #0x5cc] */
/* @0xbb4e4 ldr r1, [pc, #0x5cc] */
/* @0xbb4e8 ldr r3, [r4, r3] */
/* @0xbb4ec add r2, pc, r2 */
/* @0xbb4f0 add r1, pc, r1 */
/* @0xbb4f4 ldr r0, [r2] */
/* @0xbb4f8 str r8, [r3] */
/* @0xbb4fc bl 0xb6514 <dlsym@plt> */
/* @0xbb500 subs r8, r0, #0 */
/* @0xbb504 beq 0xbce6c <_Z12GLFuncImportb+0x275c> */
/* @0xbb508 ldr r3, [pc, #0x5ac] */
/* @0xbb50c ldr r2, [pc, #0x5ac] */
/* @0xbb510 ldr r1, [pc, #0x5ac] */
/* @0xbb514 ldr r3, [r4, r3] */
/* @0xbb518 add r2, pc, r2 */
/* @0xbb51c add r1, pc, r1 */
/* @0xbb520 ldr r0, [r2] */
/* @0xbb524 str r8, [r3] */
/* @0xbb528 bl 0xb6514 <dlsym@plt> */
/* @0xbb52c subs r8, r0, #0 */
/* @0xbb530 beq 0xbce4c <_Z12GLFuncImportb+0x273c> */
/* @0xbb534 ldr r3, [pc, #0x58c] */
/* @0xbb538 ldr r2, [pc, #0x58c] */
/* @0xbb53c ldr r1, [pc, #0x58c] */
/* @0xbb540 ldr r3, [r4, r3] */
/* @0xbb544 add r2, pc, r2 */
/* @0xbb548 add r1, pc, r1 */
/* @0xbb54c ldr r0, [r2] */
/* @0xbb550 str r8, [r3] */
/* @0xbb554 bl 0xb6514 <dlsym@plt> */
/* @0xbb558 subs r8, r0, #0 */
/* @0xbb55c beq 0xbce2c <_Z12GLFuncImportb+0x271c> */
/* @0xbb560 ldr r3, [pc, #0x56c] */
/* @0xbb564 ldr r2, [pc, #0x56c] */
/* @0xbb568 ldr r1, [pc, #0x56c] */
/* @0xbb56c ldr r3, [r4, r3] */
/* @0xbb570 add r2, pc, r2 */
/* @0xbb574 add r1, pc, r1 */
/* @0xbb578 ldr r0, [r2] */
/* @0xbb57c str r8, [r3] */
/* @0xbb580 bl 0xb6514 <dlsym@plt> */
/* @0xbb584 subs r8, r0, #0 */
/* @0xbb588 beq 0xbce0c <_Z12GLFuncImportb+0x26fc> */
/* @0xbb58c ldr r3, [pc, #0x54c] */
/* @0xbb590 ldr r2, [pc, #0x54c] */
/* @0xbb594 ldr r1, [pc, #0x54c] */
/* @0xbb598 ldr r3, [r4, r3] */
/* @0xbb59c add r2, pc, r2 */
/* @0xbb5a0 add r1, pc, r1 */
/* @0xbb5a4 ldr r0, [r2] */
/* @0xbb5a8 str r8, [r3] */
/* @0xbb5ac bl 0xb6514 <dlsym@plt> */
/* @0xbb5b0 subs r8, r0, #0 */
/* @0xbb5b4 beq 0xbcdec <_Z12GLFuncImportb+0x26dc> */
/* @0xbb5b8 ldr r3, [pc, #0x52c] */
/* @0xbb5bc ldr r2, [pc, #0x52c] */
/* @0xbb5c0 ldr r1, [pc, #0x52c] */
/* @0xbb5c4 ldr r3, [r4, r3] */
/* @0xbb5c8 add r2, pc, r2 */
/* @0xbb5cc add r1, pc, r1 */
/* @0xbb5d0 ldr r0, [r2] */
/* @0xbb5d4 str r8, [r3] */
/* @0xbb5d8 bl 0xb6514 <dlsym@plt> */
/* @0xbb5dc subs r8, r0, #0 */
/* @0xbb5e0 beq 0xbcdcc <_Z12GLFuncImportb+0x26bc> */
/* @0xbb5e4 ldr r3, [pc, #0x50c] */
/* @0xbb5e8 ldr r2, [pc, #0x50c] */
/* @0xbb5ec ldr r1, [pc, #0x50c] */
/* @0xbb5f0 ldr r3, [r4, r3] */
/* @0xbb5f4 add r2, pc, r2 */
/* @0xbb5f8 add r1, pc, r1 */
/* @0xbb5fc ldr r0, [r2] */
/* @0xbb600 str r8, [r3] */
/* @0xbb604 bl 0xb6514 <dlsym@plt> */
/* @0xbb608 subs r8, r0, #0 */
/* @0xbb60c beq 0xbcdac <_Z12GLFuncImportb+0x269c> */
/* @0xbb610 ldr r3, [pc, #0x4ec] */
/* @0xbb614 ldr r3, [r4, r3] */
/* @0xbb618 str r8, [r3] */
/* @0xbb61c ldr r3, [r5] */
/* @0xbb620 mov r0, r5 */
/* @0xbb624 ldr r1, [pc, #0x4dc] */
/* @0xbb628 ldr r3, [r3, #0xc] */
/* @0xbb62c add r1, pc, r1 */
/* @0xbb630 blx r3 */
/* @0xbb634 str r6, [r7] */
/* @0xbb638 mov r0, r6 */
/* @0xbb63c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xbb640 ldr r0, [pc, #0x4c4] */
/* @0xbb644 mov r1, r6 */
/* @0xbb648 ldr r6, [pc, #0x4c0] */
/* @0xbb64c add r0, pc, r0 */
/* @0xbb650 bl 0xb6520 <dlopen@plt> */
/* @0xbb654 ldr r3, [r5] */
/* @0xbb658 add r6, pc, r6 */
/* @0xbb65c ldr r1, [pc, #0x4b0] */
/* @0xbb660 ldr r3, [r3, #0xc] */
/* @0xbb664 add r1, pc, r1 */
/* @0xbb668 str r0, [r6] */
/* @0xbb66c mov r0, r5 */
/* @0xbb670 blx r3 */
/* @0xbb674 ldr r9, [r6] */
/* @0xbb678 cmp r9, #0 */
/* @0xbb67c movne r6, #2 */
/* @0xbb680 bne 0xba77c <_Z12GLFuncImportb+0x6c> */
/* @0xbb684 ldr r3, [r5] */
/* @0xbb688 mov r0, r5 */
/* @0xbb68c ldr r1, [pc, #0x484] */
/* @0xbb690 ldr r3, [r3, #0xc] */
/* @0xbb694 add r1, pc, r1 */
/* @0xbb698 blx r3 */
/* @0xbb69c ldr r0, [pc, #0x478] */
/* @0xbb6a0 mov r1, #0 */
/* @0xbb6a4 ldr r6, [pc, #0x474] */
/* @0xbb6a8 add r0, pc, r0 */
/* @0xbb6ac bl 0xb6520 <dlopen@plt> */
/* @0xbb6b0 ldr r3, [r5] */
/* @0xbb6b4 add r6, pc, r6 */
/* @0xbb6b8 ldr r1, [pc, #0x464] */
/* @0xbb6bc ldr r3, [r3, #0xc] */
/* @0xbb6c0 add r1, pc, r1 */
/* @0xbb6c4 str r0, [r6] */
/* @0xbb6c8 mov r0, r5 */
/* @0xbb6cc blx r3 */
/* @0xbb6d0 ldr r9, [r6] */
/* @0xbb6d4 cmp r9, #0 */
/* @0xbb6d8 bne 0xbd5ac <_Z12GLFuncImportb+0x2e9c> */
/* @0xbb6dc ldr r3, [r5] */
/* @0xbb6e0 mov r0, r5 */
/* @0xbb6e4 ldr r1, [pc, #0x43c] */
/* @0xbb6e8 ldr r3, [r3, #0xc] */
/* @0xbb6ec add r1, pc, r1 */
/* @0xbb6f0 blx r3 */
/* @0xbb6f4 mov r0, r9 */
/* @0xbb6f8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xbb6fc eorseq r7, r3, r0, lsr r5 */
/* @0xbb700 .word 0xffffbac0 */
/* @0xbb704 .word 0xffffbac4 */
/* @0xbb708 eoreq r4, r7, r0, ror #7 */
/* @0xbb70c eorseq pc, r11, r12, lsl r3 */
/* @0xbb710 eoreq r4, r7, r0, asr #8 */
/* @0xbb714 .word 0xffffbac8 */
/* @0xbb718 eorseq pc, r11, r0, ror #5 */
/* @0xbb71c eoreq r4, r7, r8, asr #8 */
/* @0xbb720 .word 0xffffbacc */
/* @0xbb724 ldrhteq pc, [r11], -r4 */
/* @0xbb728 eoreq r4, r7, r0, asr #8 */
/* @0xbb72c .word 0xffffbad0 */
/* @0xbb730 eorseq pc, r11, r8, lsl #5 */
/* @0xbb734 eoreq r4, r7, r0, asr #8 */
/* @0xbb738 .word 0xffffbad4 */
/* @0xbb73c eorseq pc, r11, r12, asr r2 */
/* @0xbb740 eoreq r4, r7, r8, asr #8 */
/* @0xbb744 .word 0xffffbad8 */
/* @0xbb748 eorseq pc, r11, r0, lsr r2 */
/* @0xbb74c eoreq r4, r7, r8, asr #8 */
/* @0xbb750 .word 0xffffbadc */
/* @0xbb754 eorseq pc, r11, r4, lsl #4 */
/* @0xbb758 eoreq r4, r7, r8, asr #8 */
/* @0xbb75c .word 0xffffbae0 */
/* @0xbb760 ldrsbteq pc, [r11], -r8 */
/* @0xbb764 eoreq r4, r7, r8, asr #8 */
/* @0xbb768 .word 0xffffbae4 */
/* @0xbb76c eorseq pc, r11, r12, lsr #3 */
/* @0xbb770 eoreq r4, r7, r8, asr #8 */
/* @0xbb774 .word 0xffffbae8 */
/* @0xbb778 eorseq pc, r11, r0, lsl #3 */
/* @0xbb77c eoreq r4, r7, r0, asr r4 */
/* @0xbb780 .word 0xffffbaec */
/* @0xbb784 eorseq pc, r11, r4, asr r1 */
/* @0xbb788 eoreq r4, r7, r0, asr r4 */
/* @0xbb78c .word 0xffffbaf0 */
/* @0xbb790 eorseq pc, r11, r8, lsr #2 */
/* @0xbb794 eoreq r4, r7, r0, asr r4 */
/* @0xbb798 .word 0xffffbaf4 */
/* @0xbb79c ldrshteq pc, [r11], -r12 */
/* @0xbb7a0 eoreq r4, r7, r8, asr r4 */
/* @0xbb7a4 .word 0xffffbaf8 */
/* @0xbb7a8 ldrsbteq pc, [r11], -r0 */
/* @0xbb7ac eoreq r4, r7, r0, ror #8 */
/* @0xbb7b0 .word 0xffffbafc */
/* @0xbb7b4 eorseq pc, r11, r4, lsr #1 */
/* @0xbb7b8 eoreq r4, r7, r8, asr r4 */
/* @0xbb7bc .word 0xffffbb00 */
/* @0xbb7c0 eorseq pc, r11, r8, ror r0 */
/* @0xbb7c4 eoreq r4, r7, r0, ror #8 */
/* @0xbb7c8 .word 0xffffbb04 */
/* @0xbb7cc eorseq pc, r11, r12, asr #32 */
/* @0xbb7d0 eoreq r4, r7, r8, ror #8 */
/* @0xbb7d4 .word 0xffffbb08 */
/* @0xbb7d8 eorseq pc, r11, r0, lsr #32 */
/* @0xbb7dc eoreq r4, r7, r0, ror r4 */
/* @0xbb7e0 .word 0xffffbb0c */
/* @0xbb7e4 ldrshteq lr, [r11], -r4 */
/* @0xbb7e8 eoreq r4, r7, r0, ror r4 */
/* @0xbb7ec .word 0xffffbb10 */
/* @0xbb7f0 eorseq lr, r11, r8, asr #31 */
/* @0xbb7f4 eoreq r4, r7, r0, ror r4 */
/* @0xbb7f8 .word 0xffffbb14 */
/* @0xbb7fc mlaseq r11, r12, pc, lr */
/* @0xbb800 eoreq r4, r7, r8, ror #8 */
/* @0xbb804 .word 0xffffbb18 */
/* @0xbb808 eorseq lr, r11, r0, ror pc */
/* @0xbb80c eoreq r4, r7, r8, ror #8 */
/* @0xbb810 .word 0xffffbb1c */
/* @0xbb814 eorseq lr, r11, r4, asr #30 */
/* @0xbb818 eoreq r4, r7, r0, ror r4 */
/* @0xbb81c .word 0xffffbb20 */
/* @0xbb820 eorseq lr, r11, r8, lsl pc */
/* @0xbb824 eoreq r4, r7, r8, ror r4 */
/* @0xbb828 .word 0xffffbb24 */
/* @0xbb82c eorseq lr, r11, r12, ror #29 */
/* @0xbb830 eoreq r4, r7, r8, lsl #9 */
/* @0xbb834 .word 0xffffbb28 */
/* @0xbb838 eorseq lr, r11, r0, asr #29 */
/* @0xbb83c mlaeq r7, r0, r4, r4 */
/* @0xbb840 .word 0xffffbb2c */
/* @0xbb844 mlaseq r11, r4, lr, lr */
/* @0xbb848 mlaeq r7, r8, r4, r4 */
/* @0xbb84c .word 0xffffbb30 */
/* @0xbb850 eorseq lr, r11, r8, ror #28 */
/* @0xbb854 eoreq r4, r7, r0, lsr #9 */
/* @0xbb858 .word 0xffffbb34 */
/* @0xbb85c eorseq lr, r11, r12, lsr lr */
/* @0xbb860 eoreq r4, r7, r8, lsr #9 */
/* @0xbb864 .word 0xffffbb38 */
/* @0xbb868 eorseq lr, r11, r0, lsl lr */
/* @0xbb86c .word 0x002744b0 */
/* @0xbb870 .word 0xffffbb3c */
/* @0xbb874 eorseq lr, r11, r4, ror #27 */
/* @0xbb878 .word 0x002744b8 */
/* @0xbb87c .word 0xffffbb40 */
/* @0xbb880 ldrhteq lr, [r11], -r8 */
/* @0xbb884 eoreq r4, r7, r0, asr #9 */
/* @0xbb888 .word 0xffffbb44 */
/* @0xbb88c eorseq lr, r11, r12, lsl #27 */
/* @0xbb890 eoreq r4, r7, r8, asr #9 */
/* @0xbb894 .word 0xffffbb48 */
/* @0xbb898 eorseq lr, r11, r0, ror #26 */
/* @0xbb89c .word 0x002744d0 */
/* @0xbb8a0 .word 0xffffbb4c */
/* @0xbb8a4 eorseq lr, r11, r4, lsr sp */
/* @0xbb8a8 .word 0x002744d0 */
/* @0xbb8ac .word 0xffffbb50 */
/* @0xbb8b0 eorseq lr, r11, r8, lsl #26 */
/* @0xbb8b4 .word 0x002744d0 */
/* @0xbb8b8 .word 0xffffbb54 */
/* @0xbb8bc ldrsbteq lr, [r11], -r12 */
/* @0xbb8c0 .word 0x002744d8 */
/* @0xbb8c4 .word 0xffffbb58 */
/* @0xbb8c8 ldrhteq lr, [r11], -r0 */
/* @0xbb8cc eoreq r4, r7, r0, ror #9 */
/* @0xbb8d0 .word 0xffffbb5c */
/* @0xbb8d4 eorseq lr, r11, r4, lsl #25 */
/* @0xbb8d8 eoreq r4, r7, r0, ror #9 */
/* @0xbb8dc .word 0xffffbb60 */
/* @0xbb8e0 eorseq lr, r11, r8, asr r12 */
/* @0xbb8e4 eoreq r4, r7, r0, ror #9 */
/* @0xbb8e8 .word 0xffffbb64 */
/* @0xbb8ec eorseq lr, r11, r0, lsr #24 */
/* @0xbb8f0 .word 0x002758b8 */
/* @0xbb8f4 .word 0xffffbb68 */
/* @0xbb8f8 ldrshteq lr, [r11], -r8 */
/* @0xbb8fc eoreq r4, r7, r0, asr lr */
/* @0xbb900 .word 0xffffbb6c */
/* @0xbb904 eorseq lr, r11, r12, asr #23 */
/* @0xbb908 eoreq r4, r7, r8, ror #28 */
/* @0xbb90c .word 0xffffbb70 */
/* @0xbb910 eorseq lr, r11, r0, lsr #23 */
/* @0xbb914 eoreq r4, r7, r0, lsl #29 */
/* @0xbb918 .word 0xffffbb74 */
/* @0xbb91c eorseq lr, r11, r4, ror r11 */
/* @0xbb920 mlaeq r7, r0, lr, r4 */
/* @0xbb924 .word 0xffffbb78 */
/* @0xbb928 eorseq lr, r11, r8, asr #22 */
/* @0xbb92c mlaeq r7, r8, lr, r4 */
/* @0xbb930 .word 0xffffbb7c */
/* @0xbb934 eorseq lr, r11, r12, lsl r11 */
/* @0xbb938 eoreq r4, r7, r0, lsr #29 */
/* @0xbb93c .word 0xffffbb80 */
/* @0xbb940 ldrshteq lr, [r11], -r0 */
/* @0xbb944 eoreq r4, r7, r8, lsr #29 */
/* @0xbb948 .word 0xffffbb84 */
/* @0xbb94c eorseq lr, r11, r4, asr #21 */
/* @0xbb950 eoreq r4, r7, r8, lsr #29 */
/* @0xbb954 .word 0xffffbb88 */
/* @0xbb958 mlaseq r11, r8, r10, lr */
/* @0xbb95c eoreq r4, r7, r8, asr #29 */
/* @0xbb960 .word 0xffffbb8c */
/* @0xbb964 eorseq lr, r11, r12, ror #20 */
/* @0xbb968 eoreq r4, r7, r8, ror #29 */
/* @0xbb96c .word 0xffffbb90 */
/* @0xbb970 eorseq lr, r11, r0, asr #20 */
/* @0xbb974 eoreq r4, r7, r0, lsl #30 */
/* @0xbb978 .word 0xffffbb94 */
/* @0xbb97c eorseq lr, r11, r4, lsl r10 */
/* @0xbb980 eoreq r4, r7, r8, lsl #30 */
/* @0xbb984 .word 0xffffbb98 */
/* @0xbb988 eorseq lr, r11, r8, ror #19 */
/* @0xbb98c eoreq r4, r7, r0, lsl pc */
/* @0xbb990 .word 0xffffbb9c */
/* @0xbb994 ldrhteq lr, [r11], -r12 */
/* @0xbb998 eoreq r4, r7, r8, lsl pc */
/* @0xbb99c .word 0xffffbba0 */
/* @0xbb9a0 mlaseq r11, r0, r9, lr */
/* @0xbb9a4 eoreq r4, r7, r0, lsr #30 */
/* @0xbb9a8 .word 0xffffbba4 */
/* @0xbb9ac eorseq lr, r11, r4, ror #18 */
/* @0xbb9b0 eoreq r4, r7, r0, lsr pc */
/* @0xbb9b4 .word 0xffffbba8 */
/* @0xbb9b8 eorseq lr, r11, r8, lsr r9 */
/* @0xbb9bc eoreq r4, r7, r8, lsr pc */
/* @0xbb9c0 .word 0xffffbbac */
/* @0xbb9c4 eorseq lr, r11, r12, lsl #18 */
/* @0xbb9c8 eoreq r4, r7, r0, asr #30 */
/* @0xbb9cc .word 0xffffbbb0 */
/* @0xbb9d0 eorseq lr, r11, r0, ror #17 */
/* @0xbb9d4 eoreq r4, r7, r8, asr #30 */
/* @0xbb9d8 .word 0xffffbbb4 */
/* @0xbb9dc ldrhteq lr, [r11], -r4 */
/* @0xbb9e0 eoreq r4, r7, r0, asr pc */
/* @0xbb9e4 .word 0xffffbbb8 */
/* @0xbb9e8 eorseq lr, r11, r8, lsl #17 */
/* @0xbb9ec eoreq r4, r7, r0, ror #30 */
/* @0xbb9f0 .word 0xffffbbbc */
/* @0xbb9f4 eorseq lr, r11, r12, asr r8 */
/* @0xbb9f8 eoreq r4, r7, r0, ror pc */
/* @0xbb9fc .word 0xffffbbc0 */
/* @0xbba00 eorseq lr, r11, r0, lsr r8 */
/* @0xbba04 eoreq r4, r7, r8, lsl #31 */
/* @0xbba08 .word 0xffffbbc4 */
/* @0xbba0c eorseq lr, r11, r4, lsl #16 */
/* @0xbba10 mlaeq r7, r0, pc, r4 */
/* @0xbba14 .word 0xffffbbc8 */
/* @0xbba18 ldrsbteq lr, [r11], -r8 */
/* @0xbba1c mlaeq r7, r8, pc, r4 */
/* @0xbba20 .word 0xffffbbcc */
/* @0xbba24 eorseq lr, r11, r12, lsr #15 */
/* @0xbba28 eoreq r4, r7, r0, lsr #31 */
/* @0xbba2c .word 0xffffbbd0 */
/* @0xbba30 eorseq lr, r11, r0, lsl #15 */
/* @0xbba34 eoreq r4, r7, r8, lsr #31 */
/* @0xbba38 .word 0xffffbbd4 */
/* @0xbba3c eorseq lr, r11, r4, asr r7 */
/* @0xbba40 .word 0x00274fb0 */
/* @0xbba44 .word 0xffffbbd8 */
/* @0xbba48 eorseq lr, r11, r8, lsr #14 */
/* @0xbba4c .word 0x00274fb8 */
/* @0xbba50 .word 0xffffbbdc */
/* @0xbba54 ldrshteq lr, [r11], -r12 */
/* @0xbba58 eoreq r4, r7, r0, asr #31 */
/* @0xbba5c .word 0xffffbbe0 */
/* @0xbba60 ldrsbteq lr, [r11], -r0 */
/* @0xbba64 eoreq r4, r7, r8, asr #31 */
/* @0xbba68 .word 0xffffbbe4 */
/* @0xbba6c eorseq lr, r11, r4, lsr #13 */
/* @0xbba70 .word 0x00274fd8 */
/* @0xbba74 .word 0xffffbbe8 */
/* @0xbba78 eorseq lr, r11, r8, ror r6 */
/* @0xbba7c eoreq r4, r7, r8, ror #31 */
/* @0xbba80 .word 0xffffbbec */
/* @0xbba84 eorseq lr, r11, r12, asr #12 */
/* @0xbba88 .word 0x00274ff8 */
/* @0xbba8c .word 0xffffbbf0 */
/* @0xbba90 eorseq lr, r11, r0, lsr #12 */
/* @0xbba94 eoreq r5, r7, r0 */
/* @0xbba98 .word 0xffffbbf4 */
/* @0xbba9c ldrshteq lr, [r11], -r4 */
/* @0xbbaa0 eoreq r5, r7, r0, lsr #32 */
/* @0xbbaa4 .word 0xffffbbf8 */
/* @0xbbaa8 eorseq lr, r11, r8, asr #11 */
/* @0xbbaac eoreq r5, r7, r0, lsr r0 */
/* @0xbbab0 .word 0xffffbbfc */
/* @0xbbab4 mlaseq r11, r12, r5, lr */
/* @0xbbab8 eoreq r5, r7, r0, lsr r0 */
/* @0xbbabc .word 0xffffbc00 */
/* @0xbbac0 eorseq lr, r11, r0, ror r5 */
/* @0xbbac4 eoreq r5, r7, r0, asr #32 */
/* @0xbbac8 .word 0xffffbc04 */
/* @0xbbacc eorseq lr, r11, r4, asr #10 */
/* @0xbbad0 eoreq r5, r7, r0, asr r0 */
/* @0xbbad4 .word 0xffffbc08 */
/* @0xbbad8 eorseq lr, r11, r8, lsl r5 */
/* @0xbbadc eoreq r5, r7, r8, rrx */
/* @0xbbae0 .word 0xffffbc0c */
/* @0xbbae4 eorseq lr, r11, r12, ror #9 */
/* @0xbbae8 eoreq r5, r7, r0, lsl #1 */
/* @0xbbaec .word 0xffffbc10 */
/* @0xbbaf0 eorseq lr, r11, r0, asr #9 */
/* @0xbbaf4 eoreq r5, r7, r0, lsr #1 */
/* @0xbbaf8 .word 0xffffbc14 */
/* @0xbbafc mlaseq r11, r4, r4, lr */
/* @0xbbb00 strhteq r5, [r7], -r0 */
/* @0xbbb04 .word 0xffffbc18 */
/* @0xbbb08 eoreq r5, r7, r0, ror #1 */
/* @0xbbb0c eoreq r3, r7, r12, ror #9 */
/* @0xbbb10 eorseq lr, r11, r0, lsr r4 */
/* @0xbbb14 eoreq r3, r7, r4, ror #9 */
/* @0xbbb18 .word 0x002734d4 */
/* @0xbbb1c .word 0x002734d8 */
/* @0xbbb20 ldrsbteq lr, [r11], -r4 */
/* @0xbbb24 .word 0x002734d0 */
/* @0xbbb28 eoreq r3, r7, r4, asr #9 */
/* @0xbbb2c eorseq sp, r11, r12, lsr r12 */
/* @0xbbb30 eoreq r3, r7, r8, lsl #10 */
/* @0xbbb34 .word 0xffffbc1c */
/* @0xbbb38 eorseq sp, r11, r4, lsl r12 */
/* @0xbbb3c eoreq r3, r7, r12, lsl #10 */
/* @0xbbb40 .word 0xffffbc20 */
/* @0xbbb44 eorseq sp, r11, r8, ror #23 */
/* @0xbbb48 eoreq r3, r7, r4, lsl r5 */
/* @0xbbb4c .word 0xffffbc24 */
/* @0xbbb50 ldrhteq sp, [r11], -r12 */
/* @0xbbb54 eoreq r3, r7, r4, lsl r5 */
/* @0xbbb58 .word 0xffffbc28 */
/* @0xbbb5c mlaseq r11, r0, r11, sp */
/* @0xbbb60 eoreq r3, r7, r12, lsl r5 */
/* @0xbbb64 .word 0xffffbc2c */
/* @0xbbb68 eorseq sp, r11, r4, ror #22 */
/* @0xbbb6c eoreq r3, r7, r4, lsr r5 */
/* @0xbbb70 .word 0xffffbc30 */
/* @0xbbb74 eorseq sp, r11, r8, lsr r11 */
/* @0xbbb78 eoreq r3, r7, r4, asr #10 */
/* @0xbbb7c .word 0xffffbc34 */
/* @0xbbb80 eorseq sp, r11, r12, lsl #22 */
/* @0xbbb84 eoreq r3, r7, r4, asr #10 */
/* @0xbbb88 .word 0xffffbc38 */
/* @0xbbb8c eorseq sp, r11, r0, ror #21 */
/* @0xbbb90 eoreq r3, r7, r4, asr #10 */
/* @0xbbb94 .word 0xffffbc3c */
/* @0xbbb98 ldrhteq sp, [r11], -r4 */
/* @0xbbb9c eoreq r3, r7, r12, asr #10 */
/* @0xbbba0 .word 0xffffbc40 */
/* @0xbbba4 eorseq sp, r11, r8, lsl #21 */
/* @0xbbba8 eoreq r3, r7, r12, asr #10 */
/* @0xbbbac .word 0xffffbc44 */
/* @0xbbbb0 eorseq sp, r11, r12, asr r10 */
/* @0xbbbb4 eoreq r3, r7, r4, asr r5 */
/* @0xbbbb8 .word 0xffffbc48 */
/* @0xbbbbc eorseq sp, r11, r0, lsr r10 */
/* @0xbbbc0 eoreq r3, r7, r12, asr r5 */
/* @0xbbbc4 .word 0xffffbc4c */
/* @0xbbbc8 eorseq sp, r11, r4, lsl #20 */
/* @0xbbbcc eoreq r3, r7, r4, ror #10 */
/* @0xbbbd0 .word 0xffffbc50 */
/* @0xbbbd4 ldrsbteq sp, [r11], -r8 */
/* @0xbbbd8 eoreq r3, r7, r12, ror #10 */
/* @0xbbbdc .word 0xffffbc54 */
/* @0xbbbe0 eorseq sp, r11, r12, lsr #19 */
/* @0xbbbe4 eoreq r3, r7, r12, ror #10 */
/* @0xbbbe8 .word 0xffffbc58 */
/* @0xbbbec eorseq sp, r11, r0, lsl #19 */
/* @0xbbbf0 eoreq r3, r7, r4, ror r5 */
/* @0xbbbf4 .word 0xffffbc5c */
/* @0xbbbf8 eorseq sp, r11, r4, asr r9 */
/* @0xbbbfc eoreq r3, r7, r4, ror r5 */
/* @0xbbc00 .word 0xffffbc60 */
/* @0xbbc04 eorseq sp, r11, r8, lsr #18 */
/* @0xbbc08 eoreq r3, r7, r4, ror r5 */
/* @0xbbc0c .word 0xffffbc64 */
/* @0xbbc10 ldrshteq sp, [r11], -r12 */
/* @0xbbc14 eoreq r3, r7, r12, ror r5 */
/* @0xbbc18 .word 0xffffbc68 */
/* @0xbbc1c ldrsbteq sp, [r11], -r0 */
/* @0xbbc20 eoreq r3, r7, r4, lsl #11 */
/* @0xbbc24 .word 0xffffbc6c */
/* @0xbbc28 eorseq sp, r11, r4, lsr #17 */
/* @0xbbc2c eoreq r3, r7, r12, lsl #11 */
/* @0xbbc30 .word 0xffffbc70 */
/* @0xbbc34 eorseq sp, r11, r8, ror r8 */
/* @0xbbc38 mlaeq r7, r4, r5, r3 */
/* @0xbbc3c .word 0xffffbc74 */
/* @0xbbc40 eorseq sp, r11, r12, asr #16 */
/* @0xbbc44 eoreq r3, r7, r12, lsr #11 */
/* @0xbbc48 .word 0xffffbc78 */
/* @0xbbc4c eorseq sp, r11, r0, lsr #16 */
/* @0xbbc50 eoreq r3, r7, r4, asr #11 */
/* @0xbbc54 .word 0xffffbc7c */
/* @0xbbc58 ldrshteq sp, [r11], -r4 */
/* @0xbbc5c eoreq r3, r7, r4, ror #11 */
/* @0xbbc60 .word 0xffffbc80 */
/* @0xbbc64 eorseq sp, r11, r8, asr #15 */
/* @0xbbc68 .word 0x002735fc */
/* @0xbbc6c .word 0xffffbc84 */
/* @0xbbc70 mlaseq r11, r12, r7, sp */
/* @0xbbc74 eoreq r3, r7, r12, lsl r6 */
/* @0xbbc78 .word 0xffffbc88 */
/* @0xbbc7c eorseq sp, r11, r0, ror r7 */
/* @0xbbc80 eoreq r3, r7, r4, lsr #12 */
/* @0xbbc84 .word 0xffffbc8c */
/* @0xbbc88 eorseq sp, r11, r4, asr #14 */
/* @0xbbc8c eoreq r3, r7, r12, lsr #12 */
/* @0xbbc90 .word 0xffffbc90 */
/* @0xbbc94 eorseq sp, r11, r8, lsl r7 */
/* @0xbbc98 eoreq r3, r7, r12, lsr #12 */
/* @0xbbc9c .word 0xffffbc94 */
/* @0xbbca0 eorseq sp, r11, r12, ror #13 */
/* @0xbbca4 eoreq r3, r7, r12, lsr #12 */
/* @0xbbca8 .word 0xffffbc98 */
/* @0xbbcac eorseq sp, r11, r0, asr #13 */
/* @0xbbcb0 eoreq r3, r7, r4, lsr #12 */
/* @0xbbcb4 .word 0xffffbc9c */
/* @0xbbcb8 mlaseq r11, r4, r6, sp */
/* @0xbbcbc eoreq r3, r7, r12, lsl r6 */
/* @0xbbcc0 .word 0xffffbca0 */
/* @0xbbcc4 eorseq sp, r11, r8, ror #12 */
/* @0xbbcc8 eoreq r3, r7, r12, lsl r6 */
/* @0xbbccc .word 0xffffbca4 */
/* @0xbbcd0 eorseq sp, r11, r12, lsr r6 */
/* @0xbbcd4 eoreq r3, r7, r12, lsl r6 */
/* @0xbbcd8 .word 0xffffbca8 */
/* @0xbbcdc eorseq sp, r11, r0, lsl r6 */
/* @0xbbce0 eoreq r3, r7, r12, lsr #12 */
/* @0xbbce4 .word 0xffffbcac */
/* @0xbbce8 eorseq sp, r11, r4, ror #11 */
/* @0xbbcec eoreq r3, r7, r4, lsr r6 */
/* @0xbbcf0 .word 0xffffbcb0 */
/* @0xbbcf4 ldrhteq sp, [r11], -r8 */
/* @0xbbcf8 eoreq r3, r7, r12, asr #12 */
/* @0xbbcfc .word 0xffffbcb4 */
/* @0xbbd00 eorseq sp, r11, r12, lsl #11 */
/* @0xbbd04 eoreq r3, r7, r4, ror #12 */
/* @0xbbd08 .word 0xffffbcb8 */
/* @0xbbd0c eorseq sp, r11, r0, ror #10 */
/* @0xbbd10 eoreq r3, r7, r4, lsl #13 */
/* @0xbbd14 .word 0xffffbcbc */
/* @0xbbd18 eorseq sp, r11, r4, lsr r5 */
/* @0xbbd1c eoreq r3, r7, r4, lsr #13 */
/* @0xbbd20 .word 0xffffbcc0 */
/* @0xbbd24 eorseq sp, r11, r8, lsl #10 */
/* @0xbbd28 eoreq r3, r7, r12, asr #13 */
/* @0xbbd2c .word 0xffffbcc4 */
/* @0xbbd30 eoreq r3, r7, r0, asr #14 */
/* @0xbbd34 eoreq r2, r7, r4, ror r8 */
/* @0xbbd38 eoreq r2, r7, r8, lsl #17 */
/* @0xbbd3c mlaeq r7, r12, r8, r2 */
/* @0xbbd40 eoreq r2, r7, r12, lsr #17 */
/* @0xbbd44 .word 0x002728b8 */
/* @0xbbd48 eoreq r2, r7, r0, asr #17 */
/* @0xbbd4c eoreq r2, r7, r8, asr #17 */
/* @0xbbd50 .word 0x002728d8 */
/* @0xbbd54 eoreq r2, r7, r12, ror #17 */
/* @0xbbd58 eoreq r2, r7, r4, lsl #18 */
/* @0xbbd5c eoreq r2, r7, r12, lsl r9 */
/* @0xbbd60 eoreq r2, r7, r0, lsr r9 */
/* @0xbbd64 eoreq r2, r7, r4, asr #18 */
/* @0xbbd68 eoreq r2, r7, r8, asr r9 */
/* @0xbbd6c eoreq r2, r7, r12, ror #18 */
/* @0xbbd70 eoreq r2, r7, r0, lsl #19 */
/* @0xbbd74 eoreq r2, r7, r0, lsl #10 */
/* @0xbbd78 eoreq r2, r7, r12, lsl #10 */
/* @0xbbd7c eoreq r2, r7, r12, lsl r5 */
/* @0xbbd80 eoreq r2, r7, r12, lsr #10 */
/* @0xbbd84 eoreq r2, r7, r8, lsr r5 */
/* @0xbbd88 eoreq r2, r7, r8, asr #10 */
/* @0xbbd8c eoreq r2, r7, r12, asr r5 */
/* @0xbbd90 eoreq r2, r7, r8, ror #10 */
/* @0xbbd94 eoreq r2, r7, r8, asr #6 */
/* @0xbbd98 eoreq r2, r7, r8, asr r3 */
/* @0xbbd9c eoreq r2, r7, r8, ror #6 */
/* @0xbbda0 eoreq r2, r7, r4, ror r3 */
/* @0xbbda4 mlaeq r7, r8, r9, r2 */
/* @0xbbda8 .word 0x002729b0 */
/* @0xbbdac eoreq r2, r7, r8, lsr r2 */
/* @0xbbdb0 eoreq r2, r7, r0, asr #4 */
/* @0xbbdb4 mlaeq r7, r4, r7, r2 */
/* @0xbbdb8 eoreq r2, r7, r8, lsr #15 */
/* @0xbbdbc .word 0x002727bc */
/* @0xbbdc0 eoreq r2, r7, r12, asr #15 */
/* @0xbbdc4 .word 0x002727d8 */
/* @0xbbdc8 eoreq r2, r7, r8, ror #15 */
/* @0xbbdcc .word 0x002727fc */
/* @0xbbdd0 eoreq r2, r7, r12, lsl #16 */
/* @0xbbdd4 .word 0x002734b4 */
/* @0xbbdd8 eoreq r3, r7, r0, ror #8 */
/* @0xbbddc eoreq r3, r7, r4, lsl #8 */
/* @0xbbde0 mlaeq r7, r12, r3, r3 */
/* @0xbbde4 eoreq r3, r7, r0, lsr r3 */
/* @0xbbde8 .word 0x002732d4 */
/* @0xbbdec eoreq r3, r7, r4, lsl #5 */
/* @0xbbdf0 eoreq r3, r7, r0, lsr r2 */
/* @0xbbdf4 .word 0x002731dc */
/* @0xbbdf8 eoreq r3, r7, r4, lsl #3 */
/* @0xbbdfc eoreq r3, r7, r4, lsr #2 */
/* @0xbbe00 eoreq r3, r7, r0, lsl #1 */
/* @0xbbe04 eoreq r3, r7, r0, lsr #32 */
/* @0xbbe08 eoreq r2, r7, r0, lsr #31 */
/* @0xbbe0c eoreq r2, r7, r0, lsr pc */
/* @0xbbe10 eoreq r2, r7, r4, asr #29 */
/* @0xbbe14 eoreq r2, r7, r12, asr lr */
/* @0xbbe18 .word 0x00272df8 */
/* @0xbbe1c mlaeq r7, r12, sp, r2 */
/* @0xbbe20 eoreq r2, r7, r4, asr #26 */
/* @0xbbe24 .word 0x00272cf0 */
/* @0xbbe28 eoreq r2, r7, r4, lsr #25 */
/* @0xbbe2c eoreq r2, r7, r12, asr r12 */
/* @0xbbe30 eoreq r3, r7, r4, lsl r9 */
/* @0xbbe34 eoreq r3, r7, r4, lsr #17 */
/* @0xbbe38 eoreq r3, r7, r0, asr #16 */
/* @0xbbe3c .word 0x002737d8 */
/* @0xbbe40 eoreq r3, r7, r4, ror r7 */
/* @0xbbe44 ldr r3, [pc, #-0x320] */
/* @0xbbe48 ldr r1, [pc, #-0x320] */
/* @0xbbe4c add r3, pc, r3 */
/* @0xbbe50 add r1, pc, r1 */
/* @0xbbe54 ldr r0, [r3] */
/* @0xbbe58 bl 0xb6514 <dlsym@plt> */
/* @0xbbe5c subs r8, r0, #0 */
/* @0xbbe60 beq 0xbd58c <_Z12GLFuncImportb+0x2e7c> */
/* @0xbbe64 ldr r3, [pc, #-0x338] */
/* @0xbbe68 ldr r2, [pc, #-0x338] */
/* @0xbbe6c ldr r1, [pc, #-0x338] */
/* @0xbbe70 ldr r3, [r4, r3] */
/* @0xbbe74 add r2, pc, r2 */
/* @0xbbe78 add r1, pc, r1 */
/* @0xbbe7c ldr r0, [r2] */
/* @0xbbe80 str r8, [r3] */
/* @0xbbe84 bl 0xb6514 <dlsym@plt> */
/* @0xbbe88 subs r8, r0, #0 */
/* @0xbbe8c beq 0xbd56c <_Z12GLFuncImportb+0x2e5c> */
/* @0xbbe90 ldr r3, [pc, #-0x358] */
/* @0xbbe94 ldr r2, [pc, #-0x358] */
/* @0xbbe98 ldr r1, [pc, #-0x358] */
/* @0xbbe9c ldr r3, [r4, r3] */
/* @0xbbea0 add r2, pc, r2 */
/* @0xbbea4 add r1, pc, r1 */
/* @0xbbea8 ldr r0, [r2] */
/* @0xbbeac str r8, [r3] */
/* @0xbbeb0 bl 0xb6514 <dlsym@plt> */
/* @0xbbeb4 subs r8, r0, #0 */
/* @0xbbeb8 beq 0xbd54c <_Z12GLFuncImportb+0x2e3c> */
/* @0xbbebc ldr r3, [pc, #-0x378] */
/* @0xbbec0 ldr r2, [pc, #-0x378] */
/* @0xbbec4 ldr r1, [pc, #-0x378] */
/* @0xbbec8 ldr r3, [r4, r3] */
/* @0xbbecc add r2, pc, r2 */
/* @0xbbed0 add r1, pc, r1 */
/* @0xbbed4 ldr r0, [r2] */
/* @0xbbed8 str r8, [r3] */
/* @0xbbedc bl 0xb6514 <dlsym@plt> */
/* @0xbbee0 subs r8, r0, #0 */
/* @0xbbee4 beq 0xbd52c <_Z12GLFuncImportb+0x2e1c> */
/* @0xbbee8 ldr r3, [pc, #-0x398] */
/* @0xbbeec ldr r2, [pc, #-0x398] */
/* @0xbbef0 ldr r1, [pc, #-0x398] */
/* @0xbbef4 ldr r3, [r4, r3] */
/* @0xbbef8 add r2, pc, r2 */
/* @0xbbefc add r1, pc, r1 */
/* @0xbbf00 ldr r0, [r2] */
/* @0xbbf04 str r8, [r3] */
/* @0xbbf08 bl 0xb6514 <dlsym@plt> */
/* @0xbbf0c subs r8, r0, #0 */
/* @0xbbf10 beq 0xbd50c <_Z12GLFuncImportb+0x2dfc> */
/* @0xbbf14 ldr r3, [pc, #-0x3b8] */
/* @0xbbf18 ldr r2, [pc, #-0x3b8] */
/* @0xbbf1c ldr r1, [pc, #-0x3b8] */
/* @0xbbf20 ldr r3, [r4, r3] */
/* @0xbbf24 add r2, pc, r2 */
/* @0xbbf28 add r1, pc, r1 */
/* @0xbbf2c ldr r0, [r2] */
/* @0xbbf30 str r8, [r3] */
/* @0xbbf34 bl 0xb6514 <dlsym@plt> */
/* @0xbbf38 subs r8, r0, #0 */
/* @0xbbf3c beq 0xbd4ec <_Z12GLFuncImportb+0x2ddc> */
/* @0xbbf40 ldr r3, [pc, #-0x3d8] */
/* @0xbbf44 ldr r2, [pc, #-0x3d8] */
/* @0xbbf48 ldr r1, [pc, #-0x3d8] */
/* @0xbbf4c ldr r3, [r4, r3] */
/* @0xbbf50 add r2, pc, r2 */
/* @0xbbf54 add r1, pc, r1 */
/* @0xbbf58 ldr r0, [r2] */
/* @0xbbf5c str r8, [r3] */
/* @0xbbf60 bl 0xb6514 <dlsym@plt> */
/* @0xbbf64 subs r8, r0, #0 */
/* @0xbbf68 beq 0xbd4cc <_Z12GLFuncImportb+0x2dbc> */
/* @0xbbf6c ldr r3, [pc, #-0x3f8] */
/* @0xbbf70 ldr r2, [pc, #-0x3f8] */
/* @0xbbf74 ldr r1, [pc, #-0x3f8] */
/* @0xbbf78 ldr r3, [r4, r3] */
/* @0xbbf7c add r2, pc, r2 */
/* @0xbbf80 add r1, pc, r1 */
/* @0xbbf84 ldr r0, [r2] */
/* @0xbbf88 str r8, [r3] */
/* @0xbbf8c bl 0xb6514 <dlsym@plt> */
/* @0xbbf90 subs r8, r0, #0 */
/* @0xbbf94 beq 0xbd4ac <_Z12GLFuncImportb+0x2d9c> */
/* @0xbbf98 ldr r3, [pc, #-0x418] */
/* @0xbbf9c ldr r2, [pc, #-0x418] */
/* @0xbbfa0 ldr r1, [pc, #-0x418] */
/* @0xbbfa4 ldr r3, [r4, r3] */
/* @0xbbfa8 add r2, pc, r2 */
/* @0xbbfac add r1, pc, r1 */
/* @0xbbfb0 ldr r0, [r2] */
/* @0xbbfb4 str r8, [r3] */
/* @0xbbfb8 bl 0xb6514 <dlsym@plt> */
/* @0xbbfbc subs r8, r0, #0 */
/* @0xbbfc0 beq 0xbd48c <_Z12GLFuncImportb+0x2d7c> */
/* @0xbbfc4 ldr r3, [pc, #-0x438] */
/* @0xbbfc8 ldr r2, [pc, #-0x438] */
/* @0xbbfcc ldr r1, [pc, #-0x438] */
/* @0xbbfd0 ldr r3, [r4, r3] */
/* @0xbbfd4 add r2, pc, r2 */
/* @0xbbfd8 add r1, pc, r1 */
/* @0xbbfdc ldr r0, [r2] */
/* @0xbbfe0 str r8, [r3] */
/* @0xbbfe4 bl 0xb6514 <dlsym@plt> */
/* @0xbbfe8 subs r8, r0, #0 */
/* @0xbbfec beq 0xbd46c <_Z12GLFuncImportb+0x2d5c> */
/* @0xbbff0 ldr r3, [pc, #-0x458] */
/* @0xbbff4 ldr r2, [pc, #-0x458] */
/* @0xbbff8 ldr r1, [pc, #-0x458] */
/* @0xbbffc ldr r3, [r4, r3] */
/* @0xbc000 add r2, pc, r2 */
/* @0xbc004 add r1, pc, r1 */
/* @0xbc008 ldr r0, [r2] */
/* @0xbc00c str r8, [r3] */
/* @0xbc010 bl 0xb6514 <dlsym@plt> */
/* @0xbc014 subs r8, r0, #0 */
/* @0xbc018 beq 0xbd44c <_Z12GLFuncImportb+0x2d3c> */
/* @0xbc01c ldr r3, [pc, #-0x478] */
/* @0xbc020 ldr r2, [pc, #-0x478] */
/* @0xbc024 ldr r1, [pc, #-0x478] */
/* @0xbc028 ldr r3, [r4, r3] */
/* @0xbc02c add r2, pc, r2 */
/* @0xbc030 add r1, pc, r1 */
/* @0xbc034 ldr r0, [r2] */
/* @0xbc038 str r8, [r3] */
/* @0xbc03c bl 0xb6514 <dlsym@plt> */
/* @0xbc040 subs r8, r0, #0 */
/* @0xbc044 beq 0xbd42c <_Z12GLFuncImportb+0x2d1c> */
/* @0xbc048 ldr r3, [pc, #-0x498] */
/* @0xbc04c ldr r2, [pc, #-0x498] */
/* @0xbc050 ldr r1, [pc, #-0x498] */
/* @0xbc054 ldr r3, [r4, r3] */
/* @0xbc058 add r2, pc, r2 */
/* @0xbc05c add r1, pc, r1 */
/* @0xbc060 ldr r0, [r2] */
/* @0xbc064 str r8, [r3] */
/* @0xbc068 bl 0xb6514 <dlsym@plt> */
/* @0xbc06c subs r8, r0, #0 */
/* @0xbc070 beq 0xbd40c <_Z12GLFuncImportb+0x2cfc> */
/* @0xbc074 ldr r3, [pc, #-0x4b8] */
/* @0xbc078 ldr r2, [pc, #-0x4b8] */
/* @0xbc07c ldr r1, [pc, #-0x4b8] */
/* @0xbc080 ldr r3, [r4, r3] */
/* @0xbc084 add r2, pc, r2 */
/* @0xbc088 add r1, pc, r1 */
/* @0xbc08c ldr r0, [r2] */
/* @0xbc090 str r8, [r3] */
/* @0xbc094 bl 0xb6514 <dlsym@plt> */
/* @0xbc098 subs r8, r0, #0 */
/* @0xbc09c beq 0xbd3ec <_Z12GLFuncImportb+0x2cdc> */
/* @0xbc0a0 ldr r3, [pc, #-0x4d8] */
/* @0xbc0a4 ldr r2, [pc, #-0x4d8] */
/* @0xbc0a8 ldr r1, [pc, #-0x4d8] */
/* @0xbc0ac ldr r3, [r4, r3] */
/* @0xbc0b0 add r2, pc, r2 */
/* @0xbc0b4 add r1, pc, r1 */
/* @0xbc0b8 ldr r0, [r2] */
/* @0xbc0bc str r8, [r3] */
/* @0xbc0c0 bl 0xb6514 <dlsym@plt> */
/* @0xbc0c4 subs r8, r0, #0 */
/* @0xbc0c8 beq 0xbd3cc <_Z12GLFuncImportb+0x2cbc> */
/* @0xbc0cc ldr r3, [pc, #-0x4f8] */
/* @0xbc0d0 ldr r2, [pc, #-0x4f8] */
/* @0xbc0d4 ldr r1, [pc, #-0x4f8] */
/* @0xbc0d8 ldr r3, [r4, r3] */
/* @0xbc0dc add r2, pc, r2 */
/* @0xbc0e0 add r1, pc, r1 */
/* @0xbc0e4 ldr r0, [r2] */
/* @0xbc0e8 str r8, [r3] */
/* @0xbc0ec bl 0xb6514 <dlsym@plt> */
/* @0xbc0f0 subs r8, r0, #0 */
/* @0xbc0f4 beq 0xbd3ac <_Z12GLFuncImportb+0x2c9c> */
/* @0xbc0f8 ldr r3, [pc, #-0x518] */
/* @0xbc0fc ldr r2, [pc, #-0x518] */
/* @0xbc100 ldr r1, [pc, #-0x518] */
/* @0xbc104 ldr r3, [r4, r3] */
/* @0xbc108 add r2, pc, r2 */
/* @0xbc10c add r1, pc, r1 */
/* @0xbc110 ldr r0, [r2] */
/* @0xbc114 str r8, [r3] */
/* @0xbc118 bl 0xb6514 <dlsym@plt> */
/* @0xbc11c subs r8, r0, #0 */
/* @0xbc120 beq 0xbd38c <_Z12GLFuncImportb+0x2c7c> */
/* @0xbc124 ldr r3, [pc, #-0x538] */
/* @0xbc128 ldr r2, [pc, #-0x538] */
/* @0xbc12c ldr r1, [pc, #-0x538] */
/* @0xbc130 ldr r3, [r4, r3] */
/* @0xbc134 add r2, pc, r2 */
/* @0xbc138 add r1, pc, r1 */
/* @0xbc13c ldr r0, [r2] */
/* @0xbc140 str r8, [r3] */
/* @0xbc144 bl 0xb6514 <dlsym@plt> */
/* @0xbc148 subs r8, r0, #0 */
/* @0xbc14c beq 0xbd36c <_Z12GLFuncImportb+0x2c5c> */
/* @0xbc150 ldr r3, [pc, #-0x558] */
/* @0xbc154 ldr r2, [pc, #-0x558] */
/* @0xbc158 ldr r1, [pc, #-0x558] */
/* @0xbc15c ldr r3, [r4, r3] */
/* @0xbc160 add r2, pc, r2 */
/* @0xbc164 add r1, pc, r1 */
/* @0xbc168 ldr r0, [r2] */
/* @0xbc16c str r8, [r3] */
/* @0xbc170 bl 0xb6514 <dlsym@plt> */
/* @0xbc174 subs r8, r0, #0 */
/* @0xbc178 beq 0xbd34c <_Z12GLFuncImportb+0x2c3c> */
/* @0xbc17c ldr r3, [pc, #-0x578] */
/* @0xbc180 ldr r2, [pc, #-0x578] */
/* @0xbc184 ldr r1, [pc, #-0x578] */
/* @0xbc188 ldr r3, [r4, r3] */
/* @0xbc18c add r2, pc, r2 */
/* @0xbc190 add r1, pc, r1 */
/* @0xbc194 ldr r0, [r2] */
/* @0xbc198 str r8, [r3] */
/* @0xbc19c bl 0xb6514 <dlsym@plt> */
/* @0xbc1a0 subs r8, r0, #0 */
/* @0xbc1a4 beq 0xbd32c <_Z12GLFuncImportb+0x2c1c> */
/* @0xbc1a8 ldr r3, [pc, #-0x598] */
/* @0xbc1ac ldr r2, [pc, #-0x598] */
/* @0xbc1b0 ldr r1, [pc, #-0x598] */
/* @0xbc1b4 ldr r3, [r4, r3] */
/* @0xbc1b8 add r2, pc, r2 */
/* @0xbc1bc add r1, pc, r1 */
/* @0xbc1c0 ldr r0, [r2] */
/* @0xbc1c4 str r8, [r3] */
/* @0xbc1c8 bl 0xb6514 <dlsym@plt> */
/* @0xbc1cc subs r8, r0, #0 */
/* @0xbc1d0 beq 0xbd30c <_Z12GLFuncImportb+0x2bfc> */
/* @0xbc1d4 ldr r3, [pc, #-0x5b8] */
/* @0xbc1d8 ldr r2, [pc, #-0x5b8] */
/* @0xbc1dc ldr r1, [pc, #-0x5b8] */
/* @0xbc1e0 ldr r3, [r4, r3] */
/* @0xbc1e4 add r2, pc, r2 */
/* @0xbc1e8 add r1, pc, r1 */
/* @0xbc1ec ldr r0, [r2] */
/* @0xbc1f0 str r8, [r3] */
/* @0xbc1f4 bl 0xb6514 <dlsym@plt> */
/* @0xbc1f8 subs r8, r0, #0 */
/* @0xbc1fc beq 0xbd2ec <_Z12GLFuncImportb+0x2bdc> */
/* @0xbc200 ldr r3, [pc, #-0x5d8] */
/* @0xbc204 ldr r2, [pc, #-0x5d8] */
/* @0xbc208 ldr r1, [pc, #-0x5d8] */
/* @0xbc20c ldr r3, [r4, r3] */
/* @0xbc210 add r2, pc, r2 */
/* @0xbc214 add r1, pc, r1 */
/* @0xbc218 ldr r0, [r2] */
/* @0xbc21c str r8, [r3] */
/* @0xbc220 bl 0xb6514 <dlsym@plt> */
/* @0xbc224 subs r8, r0, #0 */
/* @0xbc228 beq 0xbd2cc <_Z12GLFuncImportb+0x2bbc> */
/* @0xbc22c ldr r3, [pc, #-0x5f8] */
/* @0xbc230 ldr r2, [pc, #-0x5f8] */
/* @0xbc234 ldr r1, [pc, #-0x5f8] */
/* @0xbc238 ldr r3, [r4, r3] */
/* @0xbc23c add r2, pc, r2 */
/* @0xbc240 add r1, pc, r1 */
/* @0xbc244 ldr r0, [r2] */
/* @0xbc248 str r8, [r3] */
/* @0xbc24c bl 0xb6514 <dlsym@plt> */
/* @0xbc250 subs r8, r0, #0 */
/* @0xbc254 beq 0xbd2ac <_Z12GLFuncImportb+0x2b9c> */
/* @0xbc258 ldr r3, [pc, #-0x618] */
/* @0xbc25c ldr r2, [pc, #-0x618] */
/* @0xbc260 ldr r1, [pc, #-0x618] */
/* @0xbc264 ldr r3, [r4, r3] */
/* @0xbc268 add r2, pc, r2 */
/* @0xbc26c add r1, pc, r1 */
/* @0xbc270 ldr r0, [r2] */
/* @0xbc274 str r8, [r3] */
/* @0xbc278 bl 0xb6514 <dlsym@plt> */
/* @0xbc27c subs r8, r0, #0 */
/* @0xbc280 beq 0xbd28c <_Z12GLFuncImportb+0x2b7c> */
/* @0xbc284 ldr r3, [pc, #-0x638] */
/* @0xbc288 ldr r2, [pc, #-0x638] */
/* @0xbc28c ldr r1, [pc, #-0x638] */
/* @0xbc290 ldr r3, [r4, r3] */
/* @0xbc294 add r2, pc, r2 */
/* @0xbc298 add r1, pc, r1 */
/* @0xbc29c ldr r0, [r2] */
/* @0xbc2a0 str r8, [r3] */
/* @0xbc2a4 bl 0xb6514 <dlsym@plt> */
/* @0xbc2a8 subs r8, r0, #0 */
/* @0xbc2ac beq 0xbd26c <_Z12GLFuncImportb+0x2b5c> */
/* @0xbc2b0 ldr r3, [pc, #-0x658] */
/* @0xbc2b4 ldr r2, [pc, #-0x658] */
/* @0xbc2b8 ldr r1, [pc, #-0x658] */
/* @0xbc2bc ldr r3, [r4, r3] */
/* @0xbc2c0 add r2, pc, r2 */
/* @0xbc2c4 add r1, pc, r1 */
/* @0xbc2c8 ldr r0, [r2] */
/* @0xbc2cc str r8, [r3] */
/* @0xbc2d0 bl 0xb6514 <dlsym@plt> */
/* @0xbc2d4 subs r8, r0, #0 */
/* @0xbc2d8 beq 0xbd24c <_Z12GLFuncImportb+0x2b3c> */
/* @0xbc2dc ldr r3, [pc, #-0x678] */
/* @0xbc2e0 ldr r2, [pc, #-0x678] */
/* @0xbc2e4 ldr r1, [pc, #-0x678] */
/* @0xbc2e8 ldr r3, [r4, r3] */
/* @0xbc2ec add r2, pc, r2 */
/* @0xbc2f0 add r1, pc, r1 */
/* @0xbc2f4 ldr r0, [r2] */
/* @0xbc2f8 str r8, [r3] */
/* @0xbc2fc bl 0xb6514 <dlsym@plt> */
/* @0xbc300 subs r8, r0, #0 */
/* @0xbc304 beq 0xbd22c <_Z12GLFuncImportb+0x2b1c> */
/* @0xbc308 ldr r3, [pc, #-0x698] */
/* @0xbc30c ldr r2, [pc, #-0x698] */
/* @0xbc310 ldr r1, [pc, #-0x698] */
/* @0xbc314 ldr r3, [r4, r3] */
/* @0xbc318 add r2, pc, r2 */
/* @0xbc31c add r1, pc, r1 */
/* @0xbc320 ldr r0, [r2] */
/* @0xbc324 str r8, [r3] */
/* @0xbc328 bl 0xb6514 <dlsym@plt> */
/* @0xbc32c subs r8, r0, #0 */
/* @0xbc330 beq 0xbd20c <_Z12GLFuncImportb+0x2afc> */
/* @0xbc334 ldr r3, [pc, #-0x6b8] */
/* @0xbc338 ldr r2, [pc, #-0x6b8] */
/* @0xbc33c ldr r1, [pc, #-0x6b8] */
/* @0xbc340 ldr r3, [r4, r3] */
/* @0xbc344 add r2, pc, r2 */
/* @0xbc348 add r1, pc, r1 */
/* @0xbc34c ldr r0, [r2] */
/* @0xbc350 str r8, [r3] */
/* @0xbc354 bl 0xb6514 <dlsym@plt> */
/* @0xbc358 subs r8, r0, #0 */
/* @0xbc35c beq 0xbd1ec <_Z12GLFuncImportb+0x2adc> */
/* @0xbc360 ldr r3, [pc, #-0x6d8] */
/* @0xbc364 ldr r2, [pc, #-0x6d8] */
/* @0xbc368 ldr r1, [pc, #-0x6d8] */
/* @0xbc36c ldr r3, [r4, r3] */
/* @0xbc370 add r2, pc, r2 */
/* @0xbc374 add r1, pc, r1 */
/* @0xbc378 ldr r0, [r2] */
/* @0xbc37c str r8, [r3] */
/* @0xbc380 bl 0xb6514 <dlsym@plt> */
/* @0xbc384 subs r8, r0, #0 */
/* @0xbc388 beq 0xbd1cc <_Z12GLFuncImportb+0x2abc> */
/* @0xbc38c ldr r3, [pc, #-0x6f8] */
/* @0xbc390 ldr r2, [pc, #-0x6f8] */
/* @0xbc394 ldr r1, [pc, #-0x6f8] */
/* @0xbc398 ldr r3, [r4, r3] */
/* @0xbc39c add r2, pc, r2 */
/* @0xbc3a0 add r1, pc, r1 */
/* @0xbc3a4 ldr r0, [r2] */
/* @0xbc3a8 str r8, [r3] */
/* @0xbc3ac bl 0xb6514 <dlsym@plt> */
/* @0xbc3b0 subs r8, r0, #0 */
/* @0xbc3b4 beq 0xbd1ac <_Z12GLFuncImportb+0x2a9c> */
/* @0xbc3b8 ldr r3, [pc, #-0x718] */
/* @0xbc3bc ldr r2, [pc, #-0x718] */
/* @0xbc3c0 ldr r1, [pc, #-0x718] */
/* @0xbc3c4 ldr r3, [r4, r3] */
/* @0xbc3c8 add r2, pc, r2 */
/* @0xbc3cc add r1, pc, r1 */
/* @0xbc3d0 ldr r0, [r2] */
/* @0xbc3d4 str r8, [r3] */
/* @0xbc3d8 bl 0xb6514 <dlsym@plt> */
/* @0xbc3dc subs r8, r0, #0 */
/* @0xbc3e0 beq 0xbcd8c <_Z12GLFuncImportb+0x267c> */
/* @0xbc3e4 ldr r3, [pc, #-0x738] */
/* @0xbc3e8 ldr r2, [pc, #-0x738] */
/* @0xbc3ec ldr r1, [pc, #-0x738] */
/* @0xbc3f0 ldr r3, [r4, r3] */
/* @0xbc3f4 add r2, pc, r2 */
/* @0xbc3f8 add r1, pc, r1 */
/* @0xbc3fc ldr r0, [r2] */
/* @0xbc400 str r8, [r3] */
/* @0xbc404 bl 0xb6514 <dlsym@plt> */
/* @0xbc408 subs r8, r0, #0 */
/* @0xbc40c beq 0xbcd6c <_Z12GLFuncImportb+0x265c> */
/* @0xbc410 ldr r3, [pc, #-0x758] */
/* @0xbc414 ldr r2, [pc, #-0x758] */
/* @0xbc418 ldr r1, [pc, #-0x758] */
/* @0xbc41c ldr r3, [r4, r3] */
/* @0xbc420 add r2, pc, r2 */
/* @0xbc424 add r1, pc, r1 */
/* @0xbc428 ldr r0, [r2] */
/* @0xbc42c str r8, [r3] */
/* @0xbc430 bl 0xb6514 <dlsym@plt> */
/* @0xbc434 subs r8, r0, #0 */
/* @0xbc438 beq 0xbcd4c <_Z12GLFuncImportb+0x263c> */
/* @0xbc43c ldr r3, [pc, #-0x778] */
/* @0xbc440 ldr r2, [pc, #-0x778] */
/* @0xbc444 ldr r1, [pc, #-0x778] */
/* @0xbc448 ldr r3, [r4, r3] */
/* @0xbc44c add r2, pc, r2 */
/* @0xbc450 add r1, pc, r1 */
/* @0xbc454 ldr r0, [r2] */
/* @0xbc458 str r8, [r3] */
/* @0xbc45c bl 0xb6514 <dlsym@plt> */
/* @0xbc460 subs r8, r0, #0 */
/* @0xbc464 beq 0xbcd2c <_Z12GLFuncImportb+0x261c> */
/* @0xbc468 ldr r3, [pc, #-0x798] */
/* @0xbc46c ldr r2, [pc, #-0x798] */
/* @0xbc470 ldr r1, [pc, #-0x798] */
/* @0xbc474 ldr r3, [r4, r3] */
/* @0xbc478 add r2, pc, r2 */
/* @0xbc47c add r1, pc, r1 */
/* @0xbc480 ldr r0, [r2] */
/* @0xbc484 str r8, [r3] */
/* @0xbc488 bl 0xb6514 <dlsym@plt> */
/* @0xbc48c subs r8, r0, #0 */
/* @0xbc490 beq 0xbcd0c <_Z12GLFuncImportb+0x25fc> */
/* @0xbc494 ldr r3, [pc, #-0x7b8] */
/* @0xbc498 ldr r2, [pc, #-0x7b8] */
/* @0xbc49c ldr r1, [pc, #-0x7b8] */
/* @0xbc4a0 ldr r3, [r4, r3] */
/* @0xbc4a4 add r2, pc, r2 */
/* @0xbc4a8 add r1, pc, r1 */
/* @0xbc4ac ldr r0, [r2] */
/* @0xbc4b0 str r8, [r3] */
/* @0xbc4b4 bl 0xb6514 <dlsym@plt> */
/* @0xbc4b8 subs r8, r0, #0 */
/* @0xbc4bc beq 0xbccec <_Z12GLFuncImportb+0x25dc> */
/* @0xbc4c0 ldr r3, [pc, #-0x7d8] */
/* @0xbc4c4 ldr r2, [pc, #-0x7d8] */
/* @0xbc4c8 ldr r1, [pc, #-0x7d8] */
/* @0xbc4cc ldr r3, [r4, r3] */
/* @0xbc4d0 add r2, pc, r2 */
/* @0xbc4d4 add r1, pc, r1 */
/* @0xbc4d8 ldr r0, [r2] */
/* @0xbc4dc str r8, [r3] */
/* @0xbc4e0 bl 0xb6514 <dlsym@plt> */
/* @0xbc4e4 subs r8, r0, #0 */
/* @0xbc4e8 beq 0xbcccc <_Z12GLFuncImportb+0x25bc> */
/* @0xbc4ec ldr r3, [pc, #-0x7f8] */
/* @0xbc4f0 ldr r2, [pc, #-0x7f8] */
/* @0xbc4f4 ldr r1, [pc, #-0x7f8] */
/* @0xbc4f8 ldr r3, [r4, r3] */
/* @0xbc4fc add r2, pc, r2 */
/* @0xbc500 add r1, pc, r1 */
/* @0xbc504 ldr r0, [r2] */
/* @0xbc508 str r8, [r3] */
/* @0xbc50c bl 0xb6514 <dlsym@plt> */
/* @0xbc510 subs r8, r0, #0 */
/* @0xbc514 beq 0xbccac <_Z12GLFuncImportb+0x259c> */
/* @0xbc518 ldr r3, [pc, #-0x818] */
/* @0xbc51c ldr r2, [pc, #-0x818] */
/* @0xbc520 ldr r1, [pc, #-0x818] */
/* @0xbc524 ldr r3, [r4, r3] */
/* @0xbc528 add r2, pc, r2 */
/* @0xbc52c add r1, pc, r1 */
/* @0xbc530 ldr r0, [r2] */
/* @0xbc534 str r8, [r3] */
/* @0xbc538 bl 0xb6514 <dlsym@plt> */
/* @0xbc53c subs r8, r0, #0 */
/* @0xbc540 beq 0xbcc8c <_Z12GLFuncImportb+0x257c> */
/* @0xbc544 ldr r3, [pc, #-0x838] */
/* @0xbc548 ldr r2, [pc, #-0x838] */
/* @0xbc54c ldr r1, [pc, #-0x838] */
/* @0xbc550 ldr r3, [r4, r3] */
/* @0xbc554 add r2, pc, r2 */
/* @0xbc558 add r1, pc, r1 */
/* @0xbc55c ldr r0, [r2] */
/* @0xbc560 str r8, [r3] */
/* @0xbc564 bl 0xb6514 <dlsym@plt> */
/* @0xbc568 subs r8, r0, #0 */
/* @0xbc56c beq 0xbcc6c <_Z12GLFuncImportb+0x255c> */
/* @0xbc570 ldr r3, [pc, #-0x858] */
/* @0xbc574 ldr r2, [pc, #-0x858] */
/* @0xbc578 ldr r1, [pc, #-0x858] */
/* @0xbc57c ldr r3, [r4, r3] */
/* @0xbc580 add r2, pc, r2 */
/* @0xbc584 add r1, pc, r1 */
/* @0xbc588 ldr r0, [r2] */
/* @0xbc58c str r8, [r3] */
/* @0xbc590 bl 0xb6514 <dlsym@plt> */
/* @0xbc594 subs r8, r0, #0 */
/* @0xbc598 beq 0xbcc4c <_Z12GLFuncImportb+0x253c> */
/* @0xbc59c ldr r3, [pc, #-0x878] */
/* @0xbc5a0 ldr r3, [r4, r3] */
/* @0xbc5a4 str r8, [r3] */
/* @0xbc5a8 b 0xbb61c <_Z12GLFuncImportb+0xf0c> */
/* @0xbc5ac ldr r3, [r5] */
/* @0xbc5b0 mov r0, r5 */
/* @0xbc5b4 ldr r1, [pc, #-0x88c] */
/* @0xbc5b8 mov r6, #3 */
/* @0xbc5bc add r1, pc, r1 */
/* @0xbc5c0 ldr r3, [r3, #0xc] */
/* @0xbc5c4 blx r3 */
/* @0xbc5c8 b 0xbaeac <_Z12GLFuncImportb+0x79c> */
/* @0xbc5cc ldr r3, [r5] */
/* @0xbc5d0 mov r0, r5 */
/* @0xbc5d4 ldr r1, [pc, #-0x8a8] */
/* @0xbc5d8 mov r6, #3 */
/* @0xbc5dc add r1, pc, r1 */
/* @0xbc5e0 ldr r3, [r3, #0xc] */
/* @0xbc5e4 blx r3 */
/* @0xbc5e8 b 0xbaa00 <_Z12GLFuncImportb+0x2f0> */
/* @0xbc5ec ldr r3, [r5] */
/* @0xbc5f0 mov r0, r5 */
/* @0xbc5f4 ldr r1, [pc, #-0x8c4] */
/* @0xbc5f8 mov r6, #3 */
/* @0xbc5fc add r1, pc, r1 */
/* @0xbc600 ldr r3, [r3, #0xc] */
/* @0xbc604 blx r3 */
/* @0xbc608 b 0xbaa2c <_Z12GLFuncImportb+0x31c> */
/* @0xbc60c ldr r3, [r5] */
/* @0xbc610 mov r0, r5 */
/* @0xbc614 ldr r1, [pc, #-0x8e0] */
/* @0xbc618 mov r6, #3 */
/* @0xbc61c add r1, pc, r1 */
/* @0xbc620 ldr r3, [r3, #0xc] */
/* @0xbc624 blx r3 */
/* @0xbc628 b 0xbaa58 <_Z12GLFuncImportb+0x348> */
/* @0xbc62c ldr r3, [r5] */
/* @0xbc630 mov r0, r5 */
/* @0xbc634 ldr r1, [pc, #-0x8fc] */
/* @0xbc638 mov r6, #3 */
/* @0xbc63c add r1, pc, r1 */
/* @0xbc640 ldr r3, [r3, #0xc] */
/* @0xbc644 blx r3 */
/* @0xbc648 b 0xbaa84 <_Z12GLFuncImportb+0x374> */
/* @0xbc64c ldr r3, [r5] */
/* @0xbc650 mov r0, r5 */
/* @0xbc654 ldr r1, [pc, #-0x918] */
/* @0xbc658 mov r6, #3 */
/* @0xbc65c add r1, pc, r1 */
/* @0xbc660 ldr r3, [r3, #0xc] */
/* @0xbc664 blx r3 */
/* @0xbc668 b 0xbaab0 <_Z12GLFuncImportb+0x3a0> */
/* @0xbc66c ldr r3, [r5] */
/* @0xbc670 mov r0, r5 */
/* @0xbc674 ldr r1, [pc, #-0x934] */
/* @0xbc678 mov r6, #3 */
/* @0xbc67c add r1, pc, r1 */
/* @0xbc680 ldr r3, [r3, #0xc] */
/* @0xbc684 blx r3 */
/* @0xbc688 b 0xbaadc <_Z12GLFuncImportb+0x3cc> */
/* @0xbc68c ldr r3, [r5] */
/* @0xbc690 mov r0, r5 */
/* @0xbc694 ldr r1, [pc, #-0x950] */
/* @0xbc698 mov r6, #3 */
/* @0xbc69c add r1, pc, r1 */
/* @0xbc6a0 ldr r3, [r3, #0xc] */
/* @0xbc6a4 blx r3 */
/* @0xbc6a8 b 0xbab08 <_Z12GLFuncImportb+0x3f8> */
/* @0xbc6ac ldr r3, [r5] */
/* @0xbc6b0 mov r0, r5 */
/* @0xbc6b4 ldr r1, [pc, #-0x96c] */
/* @0xbc6b8 mov r6, #3 */
/* @0xbc6bc add r1, pc, r1 */
/* @0xbc6c0 ldr r3, [r3, #0xc] */
/* @0xbc6c4 blx r3 */
/* @0xbc6c8 b 0xbab34 <_Z12GLFuncImportb+0x424> */
/* @0xbc6cc ldr r3, [r5] */
/* @0xbc6d0 mov r0, r5 */
/* @0xbc6d4 ldr r1, [pc, #-0x988] */
/* @0xbc6d8 mov r6, #3 */
/* @0xbc6dc add r1, pc, r1 */
/* @0xbc6e0 ldr r3, [r3, #0xc] */
/* @0xbc6e4 blx r3 */
/* @0xbc6e8 b 0xbab60 <_Z12GLFuncImportb+0x450> */
/* @0xbc6ec ldr r3, [r5] */
/* @0xbc6f0 mov r0, r5 */
/* @0xbc6f4 ldr r1, [pc, #-0x9a4] */
/* @0xbc6f8 mov r6, #3 */
/* @0xbc6fc add r1, pc, r1 */
/* @0xbc700 ldr r3, [r3, #0xc] */
/* @0xbc704 blx r3 */
/* @0xbc708 b 0xbab8c <_Z12GLFuncImportb+0x47c> */
/* @0xbc70c ldr r3, [r5] */
/* @0xbc710 mov r0, r5 */
/* @0xbc714 ldr r1, [pc, #-0x9c0] */
/* @0xbc718 mov r6, #3 */
/* @0xbc71c add r1, pc, r1 */
/* @0xbc720 ldr r3, [r3, #0xc] */
/* @0xbc724 blx r3 */
/* @0xbc728 b 0xbabb8 <_Z12GLFuncImportb+0x4a8> */
/* @0xbc72c ldr r3, [r5] */
/* @0xbc730 mov r0, r5 */
/* @0xbc734 ldr r1, [pc, #-0x9dc] */
/* @0xbc738 mov r6, #3 */
/* @0xbc73c add r1, pc, r1 */
/* @0xbc740 ldr r3, [r3, #0xc] */
/* @0xbc744 blx r3 */
/* @0xbc748 b 0xbabe4 <_Z12GLFuncImportb+0x4d4> */
/* @0xbc74c ldr r3, [r5] */
/* @0xbc750 mov r0, r5 */
/* @0xbc754 ldr r1, [pc, #-0x9f8] */
/* @0xbc758 mov r6, #3 */
/* @0xbc75c add r1, pc, r1 */
/* @0xbc760 ldr r3, [r3, #0xc] */
/* @0xbc764 blx r3 */
/* @0xbc768 b 0xbac10 <_Z12GLFuncImportb+0x500> */
/* @0xbc76c ldr r3, [r5] */
/* @0xbc770 mov r0, r5 */
/* @0xbc774 ldr r1, [pc, #-0xa14] */
/* @0xbc778 mov r6, #3 */
/* @0xbc77c add r1, pc, r1 */
/* @0xbc780 ldr r3, [r3, #0xc] */
/* @0xbc784 blx r3 */
/* @0xbc788 b 0xbac3c <_Z12GLFuncImportb+0x52c> */
/* @0xbc78c ldr r3, [r5] */
/* @0xbc790 mov r0, r5 */
/* @0xbc794 ldr r1, [pc, #-0xa30] */
/* @0xbc798 mov r6, #3 */
/* @0xbc79c add r1, pc, r1 */
/* @0xbc7a0 ldr r3, [r3, #0xc] */
/* @0xbc7a4 blx r3 */
/* @0xbc7a8 b 0xbac68 <_Z12GLFuncImportb+0x558> */
/* @0xbc7ac ldr r3, [r5] */
/* @0xbc7b0 mov r0, r5 */
/* @0xbc7b4 ldr r1, [pc, #-0xa4c] */
/* @0xbc7b8 mov r6, #3 */
/* @0xbc7bc add r1, pc, r1 */
/* @0xbc7c0 ldr r3, [r3, #0xc] */
/* @0xbc7c4 blx r3 */
/* @0xbc7c8 b 0xbac94 <_Z12GLFuncImportb+0x584> */
/* @0xbc7cc ldr r3, [r5] */
/* @0xbc7d0 mov r0, r5 */
/* @0xbc7d4 ldr r1, [pc, #-0xa68] */
/* @0xbc7d8 mov r6, #3 */
/* @0xbc7dc add r1, pc, r1 */
/* @0xbc7e0 ldr r3, [r3, #0xc] */
/* @0xbc7e4 blx r3 */
/* @0xbc7e8 b 0xba8a0 <_Z12GLFuncImportb+0x190> */
/* @0xbc7ec ldr r3, [r5] */
/* @0xbc7f0 mov r0, r5 */
/* @0xbc7f4 ldr r1, [pc, #-0xa84] */
/* @0xbc7f8 mov r6, #3 */
/* @0xbc7fc add r1, pc, r1 */
/* @0xbc800 ldr r3, [r3, #0xc] */
/* @0xbc804 blx r3 */
/* @0xbc808 b 0xba8cc <_Z12GLFuncImportb+0x1bc> */
/* @0xbc80c ldr r3, [r5] */
/* @0xbc810 mov r0, r5 */
/* @0xbc814 ldr r1, [pc, #-0xaa0] */
/* @0xbc818 mov r6, #3 */
/* @0xbc81c add r1, pc, r1 */
/* @0xbc820 ldr r3, [r3, #0xc] */
/* @0xbc824 blx r3 */
/* @0xbc828 b 0xba8f8 <_Z12GLFuncImportb+0x1e8> */
/* @0xbc82c ldr r3, [r5] */
/* @0xbc830 mov r0, r5 */
/* @0xbc834 ldr r1, [pc, #-0xabc] */
/* @0xbc838 mov r6, #3 */
/* @0xbc83c add r1, pc, r1 */
/* @0xbc840 ldr r3, [r3, #0xc] */
/* @0xbc844 blx r3 */
/* @0xbc848 b 0xba924 <_Z12GLFuncImportb+0x214> */
/* @0xbc84c ldr r3, [r5] */
/* @0xbc850 mov r0, r5 */
/* @0xbc854 ldr r1, [pc, #-0xad8] */
/* @0xbc858 mov r6, #3 */
/* @0xbc85c add r1, pc, r1 */
/* @0xbc860 ldr r3, [r3, #0xc] */
/* @0xbc864 blx r3 */
/* @0xbc868 b 0xba950 <_Z12GLFuncImportb+0x240> */
/* @0xbc86c ldr r3, [r5] */
/* @0xbc870 mov r0, r5 */
/* @0xbc874 ldr r1, [pc, #-0xaf4] */
/* @0xbc878 mov r6, #3 */
/* @0xbc87c add r1, pc, r1 */
/* @0xbc880 ldr r3, [r3, #0xc] */
/* @0xbc884 blx r3 */
/* @0xbc888 b 0xba97c <_Z12GLFuncImportb+0x26c> */
/* @0xbc88c ldr r3, [r5] */
/* @0xbc890 mov r0, r5 */
/* @0xbc894 ldr r1, [pc, #-0xb10] */
/* @0xbc898 mov r6, #3 */
/* @0xbc89c add r1, pc, r1 */
/* @0xbc8a0 ldr r3, [r3, #0xc] */
/* @0xbc8a4 blx r3 */
/* @0xbc8a8 b 0xba9a8 <_Z12GLFuncImportb+0x298> */
/* @0xbc8ac ldr r3, [r5] */
/* @0xbc8b0 mov r0, r5 */
/* @0xbc8b4 ldr r1, [pc, #-0xb2c] */
/* @0xbc8b8 mov r6, #3 */
/* @0xbc8bc add r1, pc, r1 */
/* @0xbc8c0 ldr r3, [r3, #0xc] */
/* @0xbc8c4 blx r3 */
/* @0xbc8c8 b 0xba9d4 <_Z12GLFuncImportb+0x2c4> */
/* @0xbc8cc ldr r3, [r5] */
/* @0xbc8d0 mov r0, r5 */
/* @0xbc8d4 ldr r1, [pc, #-0xb48] */
/* @0xbc8d8 mov r6, #3 */
/* @0xbc8dc add r1, pc, r1 */
/* @0xbc8e0 ldr r3, [r3, #0xc] */
/* @0xbc8e4 blx r3 */
/* @0xbc8e8 b 0xba7f0 <_Z12GLFuncImportb+0xe0> */
/* @0xbc8ec ldr r3, [r5] */
/* @0xbc8f0 mov r0, r5 */
/* @0xbc8f4 ldr r1, [pc, #-0xb64] */
/* @0xbc8f8 mov r6, #3 */
/* @0xbc8fc add r1, pc, r1 */
/* @0xbc900 ldr r3, [r3, #0xc] */
/* @0xbc904 blx r3 */
/* @0xbc908 b 0xba81c <_Z12GLFuncImportb+0x10c> */
/* @0xbc90c ldr r3, [r5] */
/* @0xbc910 mov r0, r5 */
/* @0xbc914 ldr r1, [pc, #-0xb80] */
/* @0xbc918 mov r6, #3 */
/* @0xbc91c add r1, pc, r1 */
/* @0xbc920 ldr r3, [r3, #0xc] */
/* @0xbc924 blx r3 */
/* @0xbc928 b 0xba848 <_Z12GLFuncImportb+0x138> */
/* @0xbc92c ldr r3, [r5] */
/* @0xbc930 mov r0, r5 */
/* @0xbc934 ldr r1, [pc, #-0xb9c] */
/* @0xbc938 mov r6, #3 */
/* @0xbc93c add r1, pc, r1 */
/* @0xbc940 ldr r3, [r3, #0xc] */
/* @0xbc944 blx r3 */
/* @0xbc948 b 0xba874 <_Z12GLFuncImportb+0x164> */
/* @0xbc94c ldr r3, [r5] */
/* @0xbc950 mov r0, r5 */
/* @0xbc954 ldr r1, [pc, #-0xbb8] */
/* @0xbc958 mov r6, #3 */
/* @0xbc95c add r1, pc, r1 */
/* @0xbc960 ldr r3, [r3, #0xc] */
/* @0xbc964 blx r3 */
/* @0xbc968 b 0xbae20 <_Z12GLFuncImportb+0x710> */
/* @0xbc96c ldr r3, [r5] */
/* @0xbc970 mov r0, r5 */
/* @0xbc974 ldr r1, [pc, #-0xbd4] */
/* @0xbc978 mov r6, #3 */
/* @0xbc97c add r1, pc, r1 */
/* @0xbc980 ldr r3, [r3, #0xc] */
/* @0xbc984 blx r3 */
/* @0xbc988 b 0xbae4c <_Z12GLFuncImportb+0x73c> */
/* @0xbc98c ldr r3, [r5] */
/* @0xbc990 mov r0, r5 */
/* @0xbc994 ldr r1, [pc, #-0xbf0] */
/* @0xbc998 mov r6, #3 */
/* @0xbc99c add r1, pc, r1 */
/* @0xbc9a0 ldr r3, [r3, #0xc] */
/* @0xbc9a4 blx r3 */
/* @0xbc9a8 b 0xba798 <_Z12GLFuncImportb+0x88> */
/* @0xbc9ac ldr r3, [r5] */
/* @0xbc9b0 mov r0, r5 */
/* @0xbc9b4 ldr r1, [pc, #-0xc0c] */
/* @0xbc9b8 mov r6, #3 */
/* @0xbc9bc add r1, pc, r1 */
/* @0xbc9c0 ldr r3, [r3, #0xc] */
/* @0xbc9c4 blx r3 */
/* @0xbc9c8 b 0xba7c4 <_Z12GLFuncImportb+0xb4> */
/* @0xbc9cc ldr r3, [r5] */
/* @0xbc9d0 mov r0, r5 */
/* @0xbc9d4 ldr r1, [pc, #-0xc28] */
/* @0xbc9d8 mov r6, #3 */
/* @0xbc9dc add r1, pc, r1 */
/* @0xbc9e0 ldr r3, [r3, #0xc] */
/* @0xbc9e4 blx r3 */
/* @0xbc9e8 b 0xbacc0 <_Z12GLFuncImportb+0x5b0> */
/* @0xbc9ec ldr r3, [r5] */
/* @0xbc9f0 mov r0, r5 */
/* @0xbc9f4 ldr r1, [pc, #-0xc44] */
/* @0xbc9f8 mov r6, #3 */
/* @0xbc9fc add r1, pc, r1 */
/* @0xbca00 ldr r3, [r3, #0xc] */
/* @0xbca04 blx r3 */
/* @0xbca08 b 0xbacec <_Z12GLFuncImportb+0x5dc> */
/* @0xbca0c ldr r3, [r5] */
/* @0xbca10 mov r0, r5 */
/* @0xbca14 ldr r1, [pc, #-0xc60] */
/* @0xbca18 mov r6, #3 */
/* @0xbca1c add r1, pc, r1 */
/* @0xbca20 ldr r3, [r3, #0xc] */
/* @0xbca24 blx r3 */
/* @0xbca28 b 0xbad18 <_Z12GLFuncImportb+0x608> */
/* @0xbca2c ldr r3, [r5] */
/* @0xbca30 mov r0, r5 */
/* @0xbca34 ldr r1, [pc, #-0xc7c] */
/* @0xbca38 mov r6, #3 */
/* @0xbca3c add r1, pc, r1 */
/* @0xbca40 ldr r3, [r3, #0xc] */
/* @0xbca44 blx r3 */
/* @0xbca48 b 0xbad44 <_Z12GLFuncImportb+0x634> */
/* @0xbca4c ldr r3, [r5] */
/* @0xbca50 mov r0, r5 */
/* @0xbca54 ldr r1, [pc, #-0xc98] */
/* @0xbca58 mov r6, #3 */
/* @0xbca5c add r1, pc, r1 */
/* @0xbca60 ldr r3, [r3, #0xc] */
/* @0xbca64 blx r3 */
/* @0xbca68 b 0xbad70 <_Z12GLFuncImportb+0x660> */
/* @0xbca6c ldr r3, [r5] */
/* @0xbca70 mov r0, r5 */
/* @0xbca74 ldr r1, [pc, #-0xcb4] */
/* @0xbca78 mov r6, #3 */
/* @0xbca7c add r1, pc, r1 */
/* @0xbca80 ldr r3, [r3, #0xc] */
/* @0xbca84 blx r3 */
/* @0xbca88 b 0xbad9c <_Z12GLFuncImportb+0x68c> */
/* @0xbca8c ldr r3, [r5] */
/* @0xbca90 mov r0, r5 */
/* @0xbca94 ldr r1, [pc, #-0xcd0] */
/* @0xbca98 mov r6, #3 */
/* @0xbca9c add r1, pc, r1 */
/* @0xbcaa0 ldr r3, [r3, #0xc] */
/* @0xbcaa4 blx r3 */
/* @0xbcaa8 b 0xbadc8 <_Z12GLFuncImportb+0x6b8> */
/* @0xbcaac ldr r3, [r5] */
/* @0xbcab0 mov r0, r5 */
/* @0xbcab4 ldr r1, [pc, #-0xcec] */
/* @0xbcab8 mov r6, #3 */
/* @0xbcabc add r1, pc, r1 */
/* @0xbcac0 ldr r3, [r3, #0xc] */
/* @0xbcac4 blx r3 */
/* @0xbcac8 b 0xbadf4 <_Z12GLFuncImportb+0x6e4> */
/* @0xbcacc ldr r3, [r5] */
/* @0xbcad0 mov r0, r5 */
/* @0xbcad4 ldr r1, [pc, #-0xd08] */
/* @0xbcad8 mov r6, #3 */
/* @0xbcadc add r1, pc, r1 */
/* @0xbcae0 ldr r3, [r3, #0xc] */
/* @0xbcae4 blx r3 */
/* @0xbcae8 b 0xbb090 <_Z12GLFuncImportb+0x980> */
/* @0xbcaec ldr r3, [r5] */
/* @0xbcaf0 mov r0, r5 */
/* @0xbcaf4 ldr r1, [pc, #-0xd24] */
/* @0xbcaf8 mov r6, #3 */
/* @0xbcafc add r1, pc, r1 */
/* @0xbcb00 ldr r3, [r3, #0xc] */
/* @0xbcb04 blx r3 */
/* @0xbcb08 b 0xbb064 <_Z12GLFuncImportb+0x954> */
/* @0xbcb0c ldr r3, [r5] */
/* @0xbcb10 mov r0, r5 */
/* @0xbcb14 ldr r1, [pc, #-0xd40] */
/* @0xbcb18 mov r6, #3 */
/* @0xbcb1c add r1, pc, r1 */
/* @0xbcb20 ldr r3, [r3, #0xc] */
/* @0xbcb24 blx r3 */
/* @0xbcb28 b 0xbb038 <_Z12GLFuncImportb+0x928> */
/* @0xbcb2c ldr r3, [r5] */
/* @0xbcb30 mov r0, r5 */
/* @0xbcb34 ldr r1, [pc, #-0xd5c] */
/* @0xbcb38 mov r6, #3 */
/* @0xbcb3c add r1, pc, r1 */
/* @0xbcb40 ldr r3, [r3, #0xc] */
/* @0xbcb44 blx r3 */
/* @0xbcb48 b 0xbb00c <_Z12GLFuncImportb+0x8fc> */
/* @0xbcb4c ldr r3, [r5] */
/* @0xbcb50 mov r0, r5 */
/* @0xbcb54 ldr r1, [pc, #-0xd78] */
/* @0xbcb58 mov r6, #3 */
/* @0xbcb5c add r1, pc, r1 */
/* @0xbcb60 ldr r3, [r3, #0xc] */
/* @0xbcb64 blx r3 */
/* @0xbcb68 b 0xbafe0 <_Z12GLFuncImportb+0x8d0> */
/* @0xbcb6c ldr r3, [r5] */
/* @0xbcb70 mov r0, r5 */
/* @0xbcb74 ldr r1, [pc, #-0xd94] */
/* @0xbcb78 mov r6, #3 */
/* @0xbcb7c add r1, pc, r1 */
/* @0xbcb80 ldr r3, [r3, #0xc] */
/* @0xbcb84 blx r3 */
/* @0xbcb88 b 0xbafb4 <_Z12GLFuncImportb+0x8a4> */
/* @0xbcb8c ldr r3, [r5] */
/* @0xbcb90 mov r0, r5 */
/* @0xbcb94 ldr r1, [pc, #-0xdb0] */
/* @0xbcb98 mov r6, #3 */
/* @0xbcb9c add r1, pc, r1 */
/* @0xbcba0 ldr r3, [r3, #0xc] */
/* @0xbcba4 blx r3 */
/* @0xbcba8 b 0xbaf88 <_Z12GLFuncImportb+0x878> */
/* @0xbcbac ldr r3, [r5] */
/* @0xbcbb0 mov r0, r5 */
/* @0xbcbb4 ldr r1, [pc, #-0xdcc] */
/* @0xbcbb8 mov r6, #3 */
/* @0xbcbbc add r1, pc, r1 */
/* @0xbcbc0 ldr r3, [r3, #0xc] */
/* @0xbcbc4 blx r3 */
/* @0xbcbc8 b 0xbaf5c <_Z12GLFuncImportb+0x84c> */
/* @0xbcbcc ldr r3, [r5] */
/* @0xbcbd0 mov r0, r5 */
/* @0xbcbd4 ldr r1, [pc, #-0xde8] */
/* @0xbcbd8 mov r6, #3 */
/* @0xbcbdc add r1, pc, r1 */
/* @0xbcbe0 ldr r3, [r3, #0xc] */
/* @0xbcbe4 blx r3 */
/* @0xbcbe8 b 0xbaf30 <_Z12GLFuncImportb+0x820> */
/* @0xbcbec ldr r3, [r5] */
/* @0xbcbf0 mov r0, r5 */
/* @0xbcbf4 ldr r1, [pc, #-0xe04] */
/* @0xbcbf8 mov r6, #3 */
/* @0xbcbfc add r1, pc, r1 */
/* @0xbcc00 ldr r3, [r3, #0xc] */
/* @0xbcc04 blx r3 */
/* @0xbcc08 b 0xbaf04 <_Z12GLFuncImportb+0x7f4> */
/* @0xbcc0c ldr r3, [r5] */
/* @0xbcc10 mov r0, r5 */
/* @0xbcc14 ldr r1, [pc, #-0xe20] */
/* @0xbcc18 mov r6, #3 */
/* @0xbcc1c add r1, pc, r1 */
/* @0xbcc20 ldr r3, [r3, #0xc] */
/* @0xbcc24 blx r3 */
/* @0xbcc28 b 0xbaed8 <_Z12GLFuncImportb+0x7c8> */
/* @0xbcc2c ldr r3, [r5] */
/* @0xbcc30 mov r0, r5 */
/* @0xbcc34 ldr r1, [pc, #-0xe3c] */
/* @0xbcc38 mov r6, #3 */
/* @0xbcc3c add r1, pc, r1 */
/* @0xbcc40 ldr r3, [r3, #0xc] */
/* @0xbcc44 blx r3 */
/* @0xbcc48 b 0xbae80 <_Z12GLFuncImportb+0x770> */
/* @0xbcc4c ldr r3, [r5] */
/* @0xbcc50 mov r0, r5 */
/* @0xbcc54 ldr r1, [pc, #-0xe58] */
/* @0xbcc58 mov r6, #3 */
/* @0xbcc5c add r1, pc, r1 */
/* @0xbcc60 ldr r3, [r3, #0xc] */
/* @0xbcc64 blx r3 */
/* @0xbcc68 b 0xbc59c <_Z12GLFuncImportb+0x1e8c> */
/* @0xbcc6c ldr r3, [r5] */
/* @0xbcc70 mov r0, r5 */
/* @0xbcc74 ldr r1, [pc, #-0xe74] */
/* @0xbcc78 mov r6, #3 */
/* @0xbcc7c add r1, pc, r1 */
/* @0xbcc80 ldr r3, [r3, #0xc] */
/* @0xbcc84 blx r3 */
/* @0xbcc88 b 0xbc570 <_Z12GLFuncImportb+0x1e60> */
/* @0xbcc8c ldr r3, [r5] */
/* @0xbcc90 mov r0, r5 */
/* @0xbcc94 ldr r1, [pc, #-0xe90] */
/* @0xbcc98 mov r6, #3 */
/* @0xbcc9c add r1, pc, r1 */
/* @0xbcca0 ldr r3, [r3, #0xc] */
/* @0xbcca4 blx r3 */
/* @0xbcca8 b 0xbc544 <_Z12GLFuncImportb+0x1e34> */
/* @0xbccac ldr r3, [r5] */
/* @0xbccb0 mov r0, r5 */
/* @0xbccb4 ldr r1, [pc, #-0xeac] */
/* @0xbccb8 mov r6, #3 */
/* @0xbccbc add r1, pc, r1 */
/* @0xbccc0 ldr r3, [r3, #0xc] */
/* @0xbccc4 blx r3 */
/* @0xbccc8 b 0xbc518 <_Z12GLFuncImportb+0x1e08> */
/* @0xbcccc ldr r3, [r5] */
/* @0xbccd0 mov r0, r5 */
/* @0xbccd4 ldr r1, [pc, #-0xec8] */
/* @0xbccd8 mov r6, #3 */
/* @0xbccdc add r1, pc, r1 */
/* @0xbcce0 ldr r3, [r3, #0xc] */
/* @0xbcce4 blx r3 */
/* @0xbcce8 b 0xbc4ec <_Z12GLFuncImportb+0x1ddc> */
/* @0xbccec ldr r3, [r5] */
/* @0xbccf0 mov r0, r5 */
/* @0xbccf4 ldr r1, [pc, #-0xee4] */
/* @0xbccf8 mov r6, #3 */
/* @0xbccfc add r1, pc, r1 */
/* @0xbcd00 ldr r3, [r3, #0xc] */
/* @0xbcd04 blx r3 */
/* @0xbcd08 b 0xbc4c0 <_Z12GLFuncImportb+0x1db0> */
/* @0xbcd0c ldr r3, [r5] */
/* @0xbcd10 mov r0, r5 */
/* @0xbcd14 ldr r1, [pc, #-0xf00] */
/* @0xbcd18 mov r6, #3 */
/* @0xbcd1c add r1, pc, r1 */
/* @0xbcd20 ldr r3, [r3, #0xc] */
/* @0xbcd24 blx r3 */
/* @0xbcd28 b 0xbc494 <_Z12GLFuncImportb+0x1d84> */
/* @0xbcd2c ldr r3, [r5] */
/* @0xbcd30 mov r0, r5 */
/* @0xbcd34 ldr r1, [pc, #-0xf1c] */
/* @0xbcd38 mov r6, #3 */
/* @0xbcd3c add r1, pc, r1 */
/* @0xbcd40 ldr r3, [r3, #0xc] */
/* @0xbcd44 blx r3 */
/* @0xbcd48 b 0xbc468 <_Z12GLFuncImportb+0x1d58> */
/* @0xbcd4c ldr r3, [r5] */
/* @0xbcd50 mov r0, r5 */
/* @0xbcd54 ldr r1, [pc, #-0xf38] */
/* @0xbcd58 mov r6, #3 */
/* @0xbcd5c add r1, pc, r1 */
/* @0xbcd60 ldr r3, [r3, #0xc] */
/* @0xbcd64 blx r3 */
/* @0xbcd68 b 0xbc43c <_Z12GLFuncImportb+0x1d2c> */
/* @0xbcd6c ldr r3, [r5] */
/* @0xbcd70 mov r0, r5 */
/* @0xbcd74 ldr r1, [pc, #-0xf54] */
/* @0xbcd78 mov r6, #3 */
/* @0xbcd7c add r1, pc, r1 */
/* @0xbcd80 ldr r3, [r3, #0xc] */
/* @0xbcd84 blx r3 */
/* @0xbcd88 b 0xbc410 <_Z12GLFuncImportb+0x1d00> */
/* @0xbcd8c ldr r3, [r5] */
/* @0xbcd90 mov r0, r5 */
/* @0xbcd94 ldr r1, [pc, #-0xf70] */
/* @0xbcd98 mov r6, #3 */
/* @0xbcd9c add r1, pc, r1 */
/* @0xbcda0 ldr r3, [r3, #0xc] */
/* @0xbcda4 blx r3 */
/* @0xbcda8 b 0xbc3e4 <_Z12GLFuncImportb+0x1cd4> */
/* @0xbcdac ldr r3, [r5] */
/* @0xbcdb0 mov r0, r5 */
/* @0xbcdb4 ldr r1, [pc, #-0xf8c] */
/* @0xbcdb8 mov r6, #3 */
/* @0xbcdbc add r1, pc, r1 */
/* @0xbcdc0 ldr r3, [r3, #0xc] */
/* @0xbcdc4 blx r3 */
/* @0xbcdc8 b 0xbb610 <_Z12GLFuncImportb+0xf00> */
/* @0xbcdcc ldr r3, [r5] */
/* @0xbcdd0 mov r0, r5 */
/* @0xbcdd4 ldr r1, [pc, #-0xfa8] */
/* @0xbcdd8 mov r6, #3 */
/* @0xbcddc add r1, pc, r1 */
/* @0xbcde0 ldr r3, [r3, #0xc] */
/* @0xbcde4 blx r3 */
/* @0xbcde8 b 0xbb5e4 <_Z12GLFuncImportb+0xed4> */
/* @0xbcdec ldr r3, [r5] */
/* @0xbcdf0 mov r0, r5 */
/* @0xbcdf4 ldr r1, [pc, #-0xfc4] */
/* @0xbcdf8 mov r6, #3 */
/* @0xbcdfc add r1, pc, r1 */
/* @0xbce00 ldr r3, [r3, #0xc] */
/* @0xbce04 blx r3 */
/* @0xbce08 b 0xbb5b8 <_Z12GLFuncImportb+0xea8> */
/* @0xbce0c ldr r3, [r5] */
/* @0xbce10 mov r0, r5 */
/* @0xbce14 ldr r1, [pc, #-0xfe0] */
/* @0xbce18 mov r6, #3 */
/* @0xbce1c add r1, pc, r1 */
/* @0xbce20 ldr r3, [r3, #0xc] */
/* @0xbce24 blx r3 */
/* @0xbce28 b 0xbb58c <_Z12GLFuncImportb+0xe7c> */
/* @0xbce2c ldr r3, [r5] */
/* @0xbce30 mov r0, r5 */
/* @0xbce34 ldr r1, [pc, #-0xffc] */
/* @0xbce38 mov r6, #3 */
/* @0xbce3c add r1, pc, r1 */
/* @0xbce40 ldr r3, [r3, #0xc] */
/* @0xbce44 blx r3 */
/* @0xbce48 b 0xbb560 <_Z12GLFuncImportb+0xe50> */
/* @0xbce4c ldr r3, [r5] */
/* @0xbce50 mov r0, r5 */
/* @0xbce54 ldr r1, [pc, #0x75c] */
/* @0xbce58 mov r6, #3 */
/* @0xbce5c add r1, pc, r1 */
/* @0xbce60 ldr r3, [r3, #0xc] */
/* @0xbce64 blx r3 */
/* @0xbce68 b 0xbb534 <_Z12GLFuncImportb+0xe24> */
/* @0xbce6c ldr r3, [r5] */
/* @0xbce70 mov r0, r5 */
/* @0xbce74 ldr r1, [pc, #0x740] */
/* @0xbce78 mov r6, #3 */
/* @0xbce7c add r1, pc, r1 */
/* @0xbce80 ldr r3, [r3, #0xc] */
/* @0xbce84 blx r3 */
/* @0xbce88 b 0xbb508 <_Z12GLFuncImportb+0xdf8> */
/* @0xbce8c ldr r3, [r5] */
/* @0xbce90 mov r0, r5 */
/* @0xbce94 ldr r1, [pc, #0x724] */
/* @0xbce98 mov r6, #3 */
/* @0xbce9c add r1, pc, r1 */
/* @0xbcea0 ldr r3, [r3, #0xc] */
/* @0xbcea4 blx r3 */
/* @0xbcea8 b 0xbb4dc <_Z12GLFuncImportb+0xdcc> */
/* @0xbceac ldr r3, [r5] */
/* @0xbceb0 mov r0, r5 */
/* @0xbceb4 ldr r1, [pc, #0x708] */
/* @0xbceb8 mov r6, #3 */
/* @0xbcebc add r1, pc, r1 */
/* @0xbcec0 ldr r3, [r3, #0xc] */
/* @0xbcec4 blx r3 */
/* @0xbcec8 b 0xbb4b0 <_Z12GLFuncImportb+0xda0> */
/* @0xbcecc ldr r3, [r5] */
/* @0xbced0 mov r0, r5 */
/* @0xbced4 ldr r1, [pc, #0x6ec] */
/* @0xbced8 mov r6, #3 */
/* @0xbcedc add r1, pc, r1 */
/* @0xbcee0 ldr r3, [r3, #0xc] */
/* @0xbcee4 blx r3 */
/* @0xbcee8 b 0xbb484 <_Z12GLFuncImportb+0xd74> */
/* @0xbceec ldr r3, [r5] */
/* @0xbcef0 mov r0, r5 */
/* @0xbcef4 ldr r1, [pc, #0x6d0] */
/* @0xbcef8 mov r6, #3 */
/* @0xbcefc add r1, pc, r1 */
/* @0xbcf00 ldr r3, [r3, #0xc] */
/* @0xbcf04 blx r3 */
/* @0xbcf08 b 0xbb458 <_Z12GLFuncImportb+0xd48> */
/* @0xbcf0c ldr r3, [r5] */
/* @0xbcf10 mov r0, r5 */
/* @0xbcf14 ldr r1, [pc, #0x6b4] */
/* @0xbcf18 mov r6, #3 */
/* @0xbcf1c add r1, pc, r1 */
/* @0xbcf20 ldr r3, [r3, #0xc] */
/* @0xbcf24 blx r3 */
/* @0xbcf28 b 0xbb42c <_Z12GLFuncImportb+0xd1c> */
/* @0xbcf2c ldr r3, [r5] */
/* @0xbcf30 mov r0, r5 */
/* @0xbcf34 ldr r1, [pc, #0x698] */
/* @0xbcf38 mov r6, #3 */
/* @0xbcf3c add r1, pc, r1 */
/* @0xbcf40 ldr r3, [r3, #0xc] */
/* @0xbcf44 blx r3 */
/* @0xbcf48 b 0xbb400 <_Z12GLFuncImportb+0xcf0> */
/* @0xbcf4c ldr r3, [r5] */
/* @0xbcf50 mov r0, r5 */
/* @0xbcf54 ldr r1, [pc, #0x67c] */
/* @0xbcf58 mov r6, #3 */
/* @0xbcf5c add r1, pc, r1 */
/* @0xbcf60 ldr r3, [r3, #0xc] */
/* @0xbcf64 blx r3 */
/* @0xbcf68 b 0xbb3d4 <_Z12GLFuncImportb+0xcc4> */
/* @0xbcf6c ldr r3, [r5] */
/* @0xbcf70 mov r0, r5 */
/* @0xbcf74 ldr r1, [pc, #0x660] */
/* @0xbcf78 mov r6, #3 */
/* @0xbcf7c add r1, pc, r1 */
/* @0xbcf80 ldr r3, [r3, #0xc] */
/* @0xbcf84 blx r3 */
/* @0xbcf88 b 0xbb3a8 <_Z12GLFuncImportb+0xc98> */
/* @0xbcf8c ldr r3, [r5] */
/* @0xbcf90 mov r0, r5 */
/* @0xbcf94 ldr r1, [pc, #0x644] */
/* @0xbcf98 mov r6, #3 */
/* @0xbcf9c add r1, pc, r1 */
/* @0xbcfa0 ldr r3, [r3, #0xc] */
/* @0xbcfa4 blx r3 */
/* @0xbcfa8 b 0xbb37c <_Z12GLFuncImportb+0xc6c> */
/* @0xbcfac ldr r3, [r5] */
/* @0xbcfb0 mov r0, r5 */
/* @0xbcfb4 ldr r1, [pc, #0x628] */
/* @0xbcfb8 mov r6, #3 */
/* @0xbcfbc add r1, pc, r1 */
/* @0xbcfc0 ldr r3, [r3, #0xc] */
/* @0xbcfc4 blx r3 */
/* @0xbcfc8 b 0xbb350 <_Z12GLFuncImportb+0xc40> */
/* @0xbcfcc ldr r3, [r5] */
/* @0xbcfd0 mov r0, r5 */
/* @0xbcfd4 ldr r1, [pc, #0x60c] */
/* @0xbcfd8 mov r6, #3 */
/* @0xbcfdc add r1, pc, r1 */
/* @0xbcfe0 ldr r3, [r3, #0xc] */
/* @0xbcfe4 blx r3 */
/* @0xbcfe8 b 0xbb324 <_Z12GLFuncImportb+0xc14> */
/* @0xbcfec ldr r3, [r5] */
/* @0xbcff0 mov r0, r5 */
/* @0xbcff4 ldr r1, [pc, #0x5f0] */
/* @0xbcff8 mov r6, #3 */
/* @0xbcffc add r1, pc, r1 */
/* @0xbd000 ldr r3, [r3, #0xc] */
/* @0xbd004 blx r3 */
/* @0xbd008 b 0xbb2f8 <_Z12GLFuncImportb+0xbe8> */
/* @0xbd00c ldr r3, [r5] */
/* @0xbd010 mov r0, r5 */
/* @0xbd014 ldr r1, [pc, #0x5d4] */
/* @0xbd018 mov r6, #3 */
/* @0xbd01c add r1, pc, r1 */
/* @0xbd020 ldr r3, [r3, #0xc] */
/* @0xbd024 blx r3 */
/* @0xbd028 b 0xbb2cc <_Z12GLFuncImportb+0xbbc> */
/* @0xbd02c ldr r3, [r5] */
/* @0xbd030 mov r0, r5 */
/* @0xbd034 ldr r1, [pc, #0x5b8] */
/* @0xbd038 mov r6, #3 */
/* @0xbd03c add r1, pc, r1 */
/* @0xbd040 ldr r3, [r3, #0xc] */
/* @0xbd044 blx r3 */
/* @0xbd048 b 0xbb2a0 <_Z12GLFuncImportb+0xb90> */
/* @0xbd04c ldr r3, [r5] */
/* @0xbd050 mov r0, r5 */
/* @0xbd054 ldr r1, [pc, #0x59c] */
/* @0xbd058 mov r6, #3 */
/* @0xbd05c add r1, pc, r1 */
/* @0xbd060 ldr r3, [r3, #0xc] */
/* @0xbd064 blx r3 */
/* @0xbd068 b 0xbb274 <_Z12GLFuncImportb+0xb64> */
/* @0xbd06c ldr r3, [r5] */
/* @0xbd070 mov r0, r5 */
/* @0xbd074 ldr r1, [pc, #0x580] */
/* @0xbd078 mov r6, #3 */
/* @0xbd07c add r1, pc, r1 */
/* @0xbd080 ldr r3, [r3, #0xc] */
/* @0xbd084 blx r3 */
/* @0xbd088 b 0xbb248 <_Z12GLFuncImportb+0xb38> */
/* @0xbd08c ldr r3, [r5] */
/* @0xbd090 mov r0, r5 */
/* @0xbd094 ldr r1, [pc, #0x564] */
/* @0xbd098 mov r6, #3 */
/* @0xbd09c add r1, pc, r1 */
/* @0xbd0a0 ldr r3, [r3, #0xc] */
/* @0xbd0a4 blx r3 */
/* @0xbd0a8 b 0xbb21c <_Z12GLFuncImportb+0xb0c> */
/* @0xbd0ac ldr r3, [r5] */
/* @0xbd0b0 mov r0, r5 */
/* @0xbd0b4 ldr r1, [pc, #0x548] */
/* @0xbd0b8 mov r6, #3 */
/* @0xbd0bc add r1, pc, r1 */
/* @0xbd0c0 ldr r3, [r3, #0xc] */
/* @0xbd0c4 blx r3 */
/* @0xbd0c8 b 0xbb1f0 <_Z12GLFuncImportb+0xae0> */
/* @0xbd0cc ldr r3, [r5] */
/* @0xbd0d0 mov r0, r5 */
/* @0xbd0d4 ldr r1, [pc, #0x52c] */
/* @0xbd0d8 mov r6, #3 */
/* @0xbd0dc add r1, pc, r1 */
/* @0xbd0e0 ldr r3, [r3, #0xc] */
/* @0xbd0e4 blx r3 */
/* @0xbd0e8 b 0xbb1c4 <_Z12GLFuncImportb+0xab4> */
/* @0xbd0ec ldr r3, [r5] */
/* @0xbd0f0 mov r0, r5 */
/* @0xbd0f4 ldr r1, [pc, #0x510] */
/* @0xbd0f8 mov r6, #3 */
/* @0xbd0fc add r1, pc, r1 */
/* @0xbd100 ldr r3, [r3, #0xc] */
/* @0xbd104 blx r3 */
/* @0xbd108 b 0xbb198 <_Z12GLFuncImportb+0xa88> */
/* @0xbd10c ldr r3, [r5] */
/* @0xbd110 mov r0, r5 */
/* @0xbd114 ldr r1, [pc, #0x4f4] */
/* @0xbd118 mov r6, #3 */
/* @0xbd11c add r1, pc, r1 */
/* @0xbd120 ldr r3, [r3, #0xc] */
/* @0xbd124 blx r3 */
/* @0xbd128 b 0xbb16c <_Z12GLFuncImportb+0xa5c> */
/* @0xbd12c ldr r3, [r5] */
/* @0xbd130 mov r0, r5 */
/* @0xbd134 ldr r1, [pc, #0x4d8] */
/* @0xbd138 mov r6, #3 */
/* @0xbd13c add r1, pc, r1 */
/* @0xbd140 ldr r3, [r3, #0xc] */
/* @0xbd144 blx r3 */
/* @0xbd148 b 0xbb140 <_Z12GLFuncImportb+0xa30> */
/* @0xbd14c ldr r3, [r5] */
/* @0xbd150 mov r0, r5 */
/* @0xbd154 ldr r1, [pc, #0x4bc] */
/* @0xbd158 mov r6, #3 */
/* @0xbd15c add r1, pc, r1 */
/* @0xbd160 ldr r3, [r3, #0xc] */
/* @0xbd164 blx r3 */
/* @0xbd168 b 0xbb114 <_Z12GLFuncImportb+0xa04> */
/* @0xbd16c ldr r3, [r5] */
/* @0xbd170 mov r0, r5 */
/* @0xbd174 ldr r1, [pc, #0x4a0] */
/* @0xbd178 mov r6, #3 */
/* @0xbd17c add r1, pc, r1 */
/* @0xbd180 ldr r3, [r3, #0xc] */
/* @0xbd184 blx r3 */
/* @0xbd188 b 0xbb0e8 <_Z12GLFuncImportb+0x9d8> */
/* @0xbd18c ldr r3, [r5] */
/* @0xbd190 mov r0, r5 */
/* @0xbd194 ldr r1, [pc, #0x484] */
/* @0xbd198 mov r6, #3 */
/* @0xbd19c add r1, pc, r1 */
/* @0xbd1a0 ldr r3, [r3, #0xc] */
/* @0xbd1a4 blx r3 */
/* @0xbd1a8 b 0xbb0bc <_Z12GLFuncImportb+0x9ac> */
/* @0xbd1ac ldr r3, [r5] */
/* @0xbd1b0 mov r0, r5 */
/* @0xbd1b4 ldr r1, [pc, #0x468] */
/* @0xbd1b8 mov r6, #3 */
/* @0xbd1bc add r1, pc, r1 */
/* @0xbd1c0 ldr r3, [r3, #0xc] */
/* @0xbd1c4 blx r3 */
/* @0xbd1c8 b 0xbc3b8 <_Z12GLFuncImportb+0x1ca8> */
/* @0xbd1cc ldr r3, [r5] */
/* @0xbd1d0 mov r0, r5 */
/* @0xbd1d4 ldr r1, [pc, #0x44c] */
/* @0xbd1d8 mov r6, #3 */
/* @0xbd1dc add r1, pc, r1 */
/* @0xbd1e0 ldr r3, [r3, #0xc] */
/* @0xbd1e4 blx r3 */
/* @0xbd1e8 b 0xbc38c <_Z12GLFuncImportb+0x1c7c> */
/* @0xbd1ec ldr r3, [r5] */
/* @0xbd1f0 mov r0, r5 */
/* @0xbd1f4 ldr r1, [pc, #0x430] */
/* @0xbd1f8 mov r6, #3 */
/* @0xbd1fc add r1, pc, r1 */
/* @0xbd200 ldr r3, [r3, #0xc] */
/* @0xbd204 blx r3 */
/* @0xbd208 b 0xbc360 <_Z12GLFuncImportb+0x1c50> */
/* @0xbd20c ldr r3, [r5] */
/* @0xbd210 mov r0, r5 */
/* @0xbd214 ldr r1, [pc, #0x414] */
/* @0xbd218 mov r6, #3 */
/* @0xbd21c add r1, pc, r1 */
/* @0xbd220 ldr r3, [r3, #0xc] */
/* @0xbd224 blx r3 */
/* @0xbd228 b 0xbc334 <_Z12GLFuncImportb+0x1c24> */
/* @0xbd22c ldr r3, [r5] */
/* @0xbd230 mov r0, r5 */
/* @0xbd234 ldr r1, [pc, #0x3f8] */
/* @0xbd238 mov r6, #3 */
/* @0xbd23c add r1, pc, r1 */
/* @0xbd240 ldr r3, [r3, #0xc] */
/* @0xbd244 blx r3 */
/* @0xbd248 b 0xbc308 <_Z12GLFuncImportb+0x1bf8> */
/* @0xbd24c ldr r3, [r5] */
/* @0xbd250 mov r0, r5 */
/* @0xbd254 ldr r1, [pc, #0x3dc] */
/* @0xbd258 mov r6, #3 */
/* @0xbd25c add r1, pc, r1 */
/* @0xbd260 ldr r3, [r3, #0xc] */
/* @0xbd264 blx r3 */
/* @0xbd268 b 0xbc2dc <_Z12GLFuncImportb+0x1bcc> */
/* @0xbd26c ldr r3, [r5] */
/* @0xbd270 mov r0, r5 */
/* @0xbd274 ldr r1, [pc, #0x3c0] */
/* @0xbd278 mov r6, #3 */
/* @0xbd27c add r1, pc, r1 */
/* @0xbd280 ldr r3, [r3, #0xc] */
/* @0xbd284 blx r3 */
/* @0xbd288 b 0xbc2b0 <_Z12GLFuncImportb+0x1ba0> */
/* @0xbd28c ldr r3, [r5] */
/* @0xbd290 mov r0, r5 */
/* @0xbd294 ldr r1, [pc, #0x3a4] */
/* @0xbd298 mov r6, #3 */
/* @0xbd29c add r1, pc, r1 */
/* @0xbd2a0 ldr r3, [r3, #0xc] */
/* @0xbd2a4 blx r3 */
/* @0xbd2a8 b 0xbc284 <_Z12GLFuncImportb+0x1b74> */
/* @0xbd2ac ldr r3, [r5] */
/* @0xbd2b0 mov r0, r5 */
/* @0xbd2b4 ldr r1, [pc, #0x388] */
/* @0xbd2b8 mov r6, #3 */
/* @0xbd2bc add r1, pc, r1 */
/* @0xbd2c0 ldr r3, [r3, #0xc] */
/* @0xbd2c4 blx r3 */
/* @0xbd2c8 b 0xbc258 <_Z12GLFuncImportb+0x1b48> */
/* @0xbd2cc ldr r3, [r5] */
/* @0xbd2d0 mov r0, r5 */
/* @0xbd2d4 ldr r1, [pc, #0x36c] */
/* @0xbd2d8 mov r6, #3 */
/* @0xbd2dc add r1, pc, r1 */
/* @0xbd2e0 ldr r3, [r3, #0xc] */
/* @0xbd2e4 blx r3 */
/* @0xbd2e8 b 0xbc22c <_Z12GLFuncImportb+0x1b1c> */
/* @0xbd2ec ldr r3, [r5] */
/* @0xbd2f0 mov r0, r5 */
/* @0xbd2f4 ldr r1, [pc, #0x350] */
/* @0xbd2f8 mov r6, #3 */
/* @0xbd2fc add r1, pc, r1 */
/* @0xbd300 ldr r3, [r3, #0xc] */
/* @0xbd304 blx r3 */
/* @0xbd308 b 0xbc200 <_Z12GLFuncImportb+0x1af0> */
/* @0xbd30c ldr r3, [r5] */
/* @0xbd310 mov r0, r5 */
/* @0xbd314 ldr r1, [pc, #0x334] */
/* @0xbd318 mov r6, #3 */
/* @0xbd31c add r1, pc, r1 */
/* @0xbd320 ldr r3, [r3, #0xc] */
/* @0xbd324 blx r3 */
/* @0xbd328 b 0xbc1d4 <_Z12GLFuncImportb+0x1ac4> */
/* @0xbd32c ldr r3, [r5] */
/* @0xbd330 mov r0, r5 */
/* @0xbd334 ldr r1, [pc, #0x318] */
/* @0xbd338 mov r6, #3 */
/* @0xbd33c add r1, pc, r1 */
/* @0xbd340 ldr r3, [r3, #0xc] */
/* @0xbd344 blx r3 */
/* @0xbd348 b 0xbc1a8 <_Z12GLFuncImportb+0x1a98> */
/* @0xbd34c ldr r3, [r5] */
/* @0xbd350 mov r0, r5 */
/* @0xbd354 ldr r1, [pc, #0x2fc] */
/* @0xbd358 mov r6, #3 */
/* @0xbd35c add r1, pc, r1 */
/* @0xbd360 ldr r3, [r3, #0xc] */
/* @0xbd364 blx r3 */
/* @0xbd368 b 0xbc17c <_Z12GLFuncImportb+0x1a6c> */
/* @0xbd36c ldr r3, [r5] */
/* @0xbd370 mov r0, r5 */
/* @0xbd374 ldr r1, [pc, #0x2e0] */
/* @0xbd378 mov r6, #3 */
/* @0xbd37c add r1, pc, r1 */
/* @0xbd380 ldr r3, [r3, #0xc] */
/* @0xbd384 blx r3 */
/* @0xbd388 b 0xbc150 <_Z12GLFuncImportb+0x1a40> */
/* @0xbd38c ldr r3, [r5] */
/* @0xbd390 mov r0, r5 */
/* @0xbd394 ldr r1, [pc, #0x2c4] */
/* @0xbd398 mov r6, #3 */
/* @0xbd39c add r1, pc, r1 */
/* @0xbd3a0 ldr r3, [r3, #0xc] */
/* @0xbd3a4 blx r3 */
/* @0xbd3a8 b 0xbc124 <_Z12GLFuncImportb+0x1a14> */
/* @0xbd3ac ldr r3, [r5] */
/* @0xbd3b0 mov r0, r5 */
/* @0xbd3b4 ldr r1, [pc, #0x2a8] */
/* @0xbd3b8 mov r6, #3 */
/* @0xbd3bc add r1, pc, r1 */
/* @0xbd3c0 ldr r3, [r3, #0xc] */
/* @0xbd3c4 blx r3 */
/* @0xbd3c8 b 0xbc0f8 <_Z12GLFuncImportb+0x19e8> */
/* @0xbd3cc ldr r3, [r5] */
/* @0xbd3d0 mov r0, r5 */
/* @0xbd3d4 ldr r1, [pc, #0x28c] */
/* @0xbd3d8 mov r6, #3 */
/* @0xbd3dc add r1, pc, r1 */
/* @0xbd3e0 ldr r3, [r3, #0xc] */
/* @0xbd3e4 blx r3 */
/* @0xbd3e8 b 0xbc0cc <_Z12GLFuncImportb+0x19bc> */
/* @0xbd3ec ldr r3, [r5] */
/* @0xbd3f0 mov r0, r5 */
/* @0xbd3f4 ldr r1, [pc, #0x270] */
/* @0xbd3f8 mov r6, #3 */
/* @0xbd3fc add r1, pc, r1 */
/* @0xbd400 ldr r3, [r3, #0xc] */
/* @0xbd404 blx r3 */
/* @0xbd408 b 0xbc0a0 <_Z12GLFuncImportb+0x1990> */
/* @0xbd40c ldr r3, [r5] */
/* @0xbd410 mov r0, r5 */
/* @0xbd414 ldr r1, [pc, #0x254] */
/* @0xbd418 mov r6, #3 */
/* @0xbd41c add r1, pc, r1 */
/* @0xbd420 ldr r3, [r3, #0xc] */
/* @0xbd424 blx r3 */
/* @0xbd428 b 0xbc074 <_Z12GLFuncImportb+0x1964> */
/* @0xbd42c ldr r3, [r5] */
/* @0xbd430 mov r0, r5 */
/* @0xbd434 ldr r1, [pc, #0x238] */
/* @0xbd438 mov r6, #3 */
/* @0xbd43c add r1, pc, r1 */
/* @0xbd440 ldr r3, [r3, #0xc] */
/* @0xbd444 blx r3 */
/* @0xbd448 b 0xbc048 <_Z12GLFuncImportb+0x1938> */
/* @0xbd44c ldr r3, [r5] */
/* @0xbd450 mov r0, r5 */
/* @0xbd454 ldr r1, [pc, #0x21c] */
/* @0xbd458 mov r6, #3 */
/* @0xbd45c add r1, pc, r1 */
/* @0xbd460 ldr r3, [r3, #0xc] */
/* @0xbd464 blx r3 */
/* @0xbd468 b 0xbc01c <_Z12GLFuncImportb+0x190c> */
/* @0xbd46c ldr r3, [r5] */
/* @0xbd470 mov r0, r5 */
/* @0xbd474 ldr r1, [pc, #0x200] */
/* @0xbd478 mov r6, #3 */
/* @0xbd47c add r1, pc, r1 */
/* @0xbd480 ldr r3, [r3, #0xc] */
/* @0xbd484 blx r3 */
/* @0xbd488 b 0xbbff0 <_Z12GLFuncImportb+0x18e0> */
/* @0xbd48c ldr r3, [r5] */
/* @0xbd490 mov r0, r5 */
/* @0xbd494 ldr r1, [pc, #0x1e4] */
/* @0xbd498 mov r6, #3 */
/* @0xbd49c add r1, pc, r1 */
/* @0xbd4a0 ldr r3, [r3, #0xc] */
/* @0xbd4a4 blx r3 */
/* @0xbd4a8 b 0xbbfc4 <_Z12GLFuncImportb+0x18b4> */
/* @0xbd4ac ldr r3, [r5] */
/* @0xbd4b0 mov r0, r5 */
/* @0xbd4b4 ldr r1, [pc, #0x1c8] */
/* @0xbd4b8 mov r6, #3 */
/* @0xbd4bc add r1, pc, r1 */
/* @0xbd4c0 ldr r3, [r3, #0xc] */
/* @0xbd4c4 blx r3 */
/* @0xbd4c8 b 0xbbf98 <_Z12GLFuncImportb+0x1888> */
/* @0xbd4cc ldr r3, [r5] */
/* @0xbd4d0 mov r0, r5 */
/* @0xbd4d4 ldr r1, [pc, #0x1ac] */
/* @0xbd4d8 mov r6, #3 */
/* @0xbd4dc add r1, pc, r1 */
/* @0xbd4e0 ldr r3, [r3, #0xc] */
/* @0xbd4e4 blx r3 */
/* @0xbd4e8 b 0xbbf6c <_Z12GLFuncImportb+0x185c> */
/* @0xbd4ec ldr r3, [r5] */
/* @0xbd4f0 mov r0, r5 */
/* @0xbd4f4 ldr r1, [pc, #0x190] */
/* @0xbd4f8 mov r6, #3 */
/* @0xbd4fc add r1, pc, r1 */
/* @0xbd500 ldr r3, [r3, #0xc] */
/* @0xbd504 blx r3 */
/* @0xbd508 b 0xbbf40 <_Z12GLFuncImportb+0x1830> */
/* @0xbd50c ldr r3, [r5] */
/* @0xbd510 mov r0, r5 */
/* @0xbd514 ldr r1, [pc, #0x174] */
/* @0xbd518 mov r6, #3 */
/* @0xbd51c add r1, pc, r1 */
/* @0xbd520 ldr r3, [r3, #0xc] */
/* @0xbd524 blx r3 */
/* @0xbd528 b 0xbbf14 <_Z12GLFuncImportb+0x1804> */
/* @0xbd52c ldr r3, [r5] */
/* @0xbd530 mov r0, r5 */
/* @0xbd534 ldr r1, [pc, #0x158] */
/* @0xbd538 mov r6, #3 */
/* @0xbd53c add r1, pc, r1 */
/* @0xbd540 ldr r3, [r3, #0xc] */
/* @0xbd544 blx r3 */
/* @0xbd548 b 0xbbee8 <_Z12GLFuncImportb+0x17d8> */
/* @0xbd54c ldr r3, [r5] */
/* @0xbd550 mov r0, r5 */
/* @0xbd554 ldr r1, [pc, #0x13c] */
/* @0xbd558 mov r6, #3 */
/* @0xbd55c add r1, pc, r1 */
/* @0xbd560 ldr r3, [r3, #0xc] */
/* @0xbd564 blx r3 */
/* @0xbd568 b 0xbbebc <_Z12GLFuncImportb+0x17ac> */
/* @0xbd56c ldr r3, [r5] */
/* @0xbd570 mov r0, r5 */
/* @0xbd574 ldr r1, [pc, #0x120] */
/* @0xbd578 mov r6, #3 */
/* @0xbd57c add r1, pc, r1 */
/* @0xbd580 ldr r3, [r3, #0xc] */
/* @0xbd584 blx r3 */
/* @0xbd588 b 0xbbe90 <_Z12GLFuncImportb+0x1780> */
/* @0xbd58c ldr r3, [r5] */
/* @0xbd590 mov r0, r5 */
/* @0xbd594 ldr r1, [pc, #0x104] */
/* @0xbd598 mov r6, #3 */
/* @0xbd59c add r1, pc, r1 */
/* @0xbd5a0 ldr r3, [r3, #0xc] */
/* @0xbd5a4 blx r3 */
/* @0xbd5a8 b 0xbbe64 <_Z12GLFuncImportb+0x1754> */
/* @0xbd5ac mov r6, #1 */
/* @0xbd5b0 mov r8, #0 */
/* @0xbd5b4 b 0xba77c <_Z12GLFuncImportb+0x6c> */
/* @0xbd5b8 eoreq r3, r7, r4, lsl r7 */
/* @0xbd5bc .word 0x002736b8 */
/* @0xbd5c0 eoreq r3, r7, r4, ror #12 */
/* @0xbd5c4 eoreq r3, r7, r0, lsl r6 */
/* @0xbd5c8 eoreq r3, r7, r12, lsr #11 */
/* @0xbd5cc eoreq r3, r7, r12, asr #10 */
/* @0xbd5d0 .word 0x002734f4 */
/* @0xbd5d4 mlaeq r7, r8, r4, r3 */
/* @0xbd5d8 eoreq r3, r7, r12, lsr r4 */
/* @0xbd5dc eoreq r3, r7, r4, ror #7 */
/* @0xbd5e0 mlaeq r7, r0, r3, r3 */
/* @0xbd5e4 eoreq r3, r7, r12, lsr r3 */
/* @0xbd5e8 eoreq r3, r7, r8, ror #5 */
/* @0xbd5ec mlaeq r7, r4, r2, r3 */
/* @0xbd5f0 eoreq r3, r7, r0, asr #4 */
/* @0xbd5f4 eoreq r3, r7, r12, ror #3 */
/* @0xbd5f8 mlaeq r7, r8, r1, r3 */
/* @0xbd5fc eoreq r3, r7, r12, lsr r1 */
/* @0xbd600 .word 0x002730dc */
/* @0xbd604 eoreq r3, r7, r0, lsl #1 */
/* @0xbd608 eoreq r3, r7, r8, lsr #32 */
/* @0xbd60c .word 0x00272fd4 */
/* @0xbd610 eoreq r2, r7, r0, lsl #31 */
/* @0xbd614 eoreq r2, r7, r12, lsr #30 */
/* @0xbd618 .word 0x00272ed4 */
/* @0xbd61c eoreq r2, r7, r12, ror lr */
/* @0xbd620 eoreq r2, r7, r8, lsr #28 */
/* @0xbd624 eoreq r2, r7, r8, lsl r8 */
/* @0xbd628 .word 0x002727d0 */
/* @0xbd62c eoreq r2, r7, r4, lsl #15 */
/* @0xbd630 eoreq r2, r7, r4, lsr r7 */
/* @0xbd634 eoreq r2, r7, r0, ror #13 */
/* @0xbd638 eoreq r2, r7, r0, lsl #13 */
/* @0xbd63c eoreq r2, r7, r8, lsl r6 */
/* @0xbd640 .word 0x002725b0 */
/* @0xbd644 eoreq r2, r7, r8, asr #10 */
/* @0xbd648 eoreq r2, r7, r4, ror #9 */
/* @0xbd64c eoreq r2, r7, r8, lsl #9 */
/* @0xbd650 eoreq r2, r7, r4, lsr r4 */
/* @0xbd654 eoreq r2, r7, r0, ror #7 */
/* @0xbd658 eoreq r2, r7, r12, lsl #7 */
/* @0xbd65c eoreq r2, r7, r12, lsr r3 */
/* @0xbd660 .word 0x002722f0 */
/* @0xbd664 eoreq r2, r7, r0, lsr #5 */
/* @0xbd668 eoreq r2, r7, r0, asr r2 */
/* @0xbd66c eoreq r2, r7, r0, lsl #4 */
/* @0xbd670 eoreq r2, r7, r12, lsr #3 */
/* @0xbd674 eoreq r2, r7, r8, asr r1 */
/* @0xbd678 eoreq r2, r7, r4, lsl #2 */
/* @0xbd67c strhteq r2, [r7], -r4 */
/* @0xbd680 eoreq r2, r7, r4, rrx */
/* @0xbd684 eoreq r2, r7, r4, lsl r0 */
/* @0xbd688 eoreq r1, r7, r8, asr #31 */
/* @0xbd68c eoreq r1, r7, r4, ror pc */
/* @0xbd690 eoreq r1, r7, r4, lsl pc */
/* @0xbd694 .word 0x00271eb8 */
/* @0xbd698 eoreq r1, r7, r8, ror #28 */
/* @0xbd69c eoreq r1, r7, r8, lsl lr */
/* @0xbd6a0 eoreq r1, r7, r8, asr #27 */

/* ── FUNC 0xbd6a4 · GLFuncImportDestroy() · size=64 · insn=16 */
/* @0xbd6a4 push {r3, r4, r5, lr} */
/* @0xbd6a8 ldr r4, [pc, #0x2c] */
/* @0xbd6ac ldr r4, [pc, r4] */
/* @0xbd6b0 ldr r3, [r4] */
/* @0xbd6b4 cmp r3, #0 */
/* @0xbd6b8 popeq {r3, r4, r5, pc} */
/* @0xbd6bc ldr r5, [pc, #0x1c] */
/* @0xbd6c0 add r5, pc, r5 */
/* @0xbd6c4 ldr r0, [r5] */
/* @0xbd6c8 bl 0xb652c <dlclose@plt> */
/* @0xbd6cc mov r3, #0 */
/* @0xbd6d0 str r3, [r5] */
/* @0xbd6d4 str r3, [r4] */
/* @0xbd6d8 pop {r3, r4, r5, pc} */
/* @0xbd6dc eorseq r0, r3, r4, rrx */
/* @0xbd6e0 eorseq r12, r11, r8, asr #7 */

/* ── FUNC 0xbd6e4 · _spAtlasPage_createTexture · size=304 · insn=76 */
/* @0xbd6e4 push {r4, r5, r6, lr} */
/* @0xbd6e8 mov r5, r0 */
/* @0xbd6ec ldr r4, [pc, #0x11c] */
/* @0xbd6f0 sub sp, sp, #24 */
/* @0xbd6f4 mov r6, r1 */
/* @0xbd6f8 add r4, pc, r4 */
/* @0xbd6fc ldr r3, [r4] */
/* @0xbd700 cmp r3, #0 */
/* @0xbd704 beq 0xbd764 <_spAtlasPage_createTexture+0x80> */
/* @0xbd708 ldr r1, [r4, #0x4] */
/* @0xbd70c mov r0, r3 */
/* @0xbd710 add r2, sp, #16 */
/* @0xbd714 mov r3, #0 */
/* @0xbd718 str r3, [sp] */
/* @0xbd71c add r3, sp, #20 */
/* @0xbd720 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b> */
/* @0xbd724 subs r2, r0, #0 */
/* @0xbd728 beq 0xbd75c <_spAtlasPage_createTexture+0x78> */
/* @0xbd72c ldr r3, [sp, #0x10] */
/* @0xbd730 ldr r1, [sp, #0x14] */
/* @0xbd734 ldr lr, [r4, #0x8] */
/* @0xbd738 mov r0, r3 */
/* @0xbd73c ldr r12, [r4, #0xc] */
/* @0xbd740 mul r3, r1, r3 */
/* @0xbd744 str lr, [r5, #0x20] */
/* @0xbd748 str r12, [r5, #0x24] */
/* @0xbd74c lsl r3, r3, #2 */
/* @0xbd750 bl 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj> */
/* @0xbd754 str r0, [r5, #0x1c] */
/* @0xbd758 bl 0x18a518 <_Z11FreePNGFilev> */
/* @0xbd75c add sp, sp, #24 */
/* @0xbd760 pop {r4, r5, r6, pc} */
/* @0xbd764 mov r0, r1 */
/* @0xbd768 str r3, [sp, #0xc] */
/* @0xbd76c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0xbd770 cmp r0, #0 */
/* @0xbd774 mov r0, r6 */
/* @0xbd778 beq 0xbd7ec <_spAtlasPage_createTexture+0x108> */
/* @0xbd77c add r1, sp, #12 */
/* @0xbd780 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0xbd784 mov r4, r0 */
/* @0xbd788 cmp r4, #0 */
/* @0xbd78c beq 0xbd7dc <_spAtlasPage_createTexture+0xf8> */
/* @0xbd790 mov r3, #0 */
/* @0xbd794 add r2, sp, #16 */
/* @0xbd798 str r3, [sp] */
/* @0xbd79c mov r0, r4 */
/* @0xbd7a0 ldr r1, [sp, #0xc] */
/* @0xbd7a4 add r3, sp, #20 */
/* @0xbd7a8 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b> */
/* @0xbd7ac subs r2, r0, #0 */
/* @0xbd7b0 beq 0xbd7dc <_spAtlasPage_createTexture+0xf8> */
/* @0xbd7b4 ldr r3, [sp, #0x10] */
/* @0xbd7b8 ldr r1, [sp, #0x14] */
/* @0xbd7bc str r3, [r5, #0x20] */
/* @0xbd7c0 mov r0, r3 */
/* @0xbd7c4 mul r3, r1, r3 */
/* @0xbd7c8 str r1, [r5, #0x24] */
/* @0xbd7cc lsl r3, r3, #2 */
/* @0xbd7d0 bl 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj> */
/* @0xbd7d4 str r0, [r5, #0x1c] */
/* @0xbd7d8 bl 0x18a518 <_Z11FreePNGFilev> */
/* @0xbd7dc mov r0, r4 */
/* @0xbd7e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xbd7e4 add sp, sp, #24 */
/* @0xbd7e8 pop {r4, r5, r6, pc} */
/* @0xbd7ec bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0xbd7f0 cmp r0, #0 */
/* @0xbd7f4 moveq r4, r0 */
/* @0xbd7f8 beq 0xbd7dc <_spAtlasPage_createTexture+0xf8> */
/* @0xbd7fc mov r0, r6 */
/* @0xbd800 add r1, sp, #12 */
/* @0xbd804 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0xbd808 mov r4, r0 */
/* @0xbd80c b 0xbd788 <_spAtlasPage_createTexture+0xa4> */
/* @0xbd810 mlaseq r11, r8, r5, r12 */

/* ── FUNC 0xbd814 · _spAtlasPage_disposeTexture · size=40 · insn=10 */
/* @0xbd814 ldr r0, [r0, #0x1c] */
/* @0xbd818 cmp r0, #0 */
/* @0xbd81c bxeq lr */
/* @0xbd820 ldr r3, [pc, #0x10] */
/* @0xbd824 ldr r3, [pc, r3] */
/* @0xbd828 ldrb r3, [r3] */
/* @0xbd82c cmp r3, #0 */
/* @0xbd830 bxeq lr */
/* @0xbd834 b 0x173f84 <_Z15GR_Texture_Freei> */
/* @0xbd838 ldrshteq r0, [r3], -r4 */

/* ── FUNC 0xbd83c · _spUtil_readFile · size=4 · insn=1 */
/* @0xbd83c b 0x285cd8 <_readFile> */

/* ── FUNC 0xbd840 · CSkeletonSprite::SimpleDecode(unsigned char*, int) · size=44 · insn=11 */
/* @0xbd840 cmp r2, #0 */
/* @0xbd844 bxle lr */
/* @0xbd848 add r0, r1, r2 */
/* @0xbd84c mov r3, #42 */
/* @0xbd850 ldrb r2, [r1] */
/* @0xbd854 rsb r2, r3, r2 */
/* @0xbd858 strb r2, [r1], #1 */
/* @0xbd85c cmp r1, r0 */
/* @0xbd860 mla r3, r3, r3, r3 */
/* @0xbd864 bne 0xbd850 <_ZN15CSkeletonSprite12SimpleDecodeEPhi+0x10> */
/* @0xbd868 bx lr */

/* ── FUNC 0xbd86c · CSkeletonSprite::CSkeletonSprite(char*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int) · size=164 · insn=41 */
/* @0xbd86c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xbd870 add r8, r1, r2 */
/* @0xbd874 ldr r12, [pc, #0x8c] */
/* @0xbd878 mov r4, r0 */
/* @0xbd87c ldr r11, [sp, #0x28] */
/* @0xbd880 mov r7, r3 */
/* @0xbd884 ldr r10, [sp, #0x2c] */
/* @0xbd888 add r12, pc, r12 */
/* @0xbd88c ldr r9, [sp, #0x30] */
/* @0xbd890 mov r5, #0 */
/* @0xbd894 add lr, r2, r3 */
/* @0xbd898 str r5, [r0] */
/* @0xbd89c str r5, [r0, #0x4] */
/* @0xbd8a0 add lr, r1, lr */
/* @0xbd8a4 str r5, [r0, #0x8] */
/* @0xbd8a8 mov r6, r1 */
/* @0xbd8ac str lr, [r12] */
/* @0xbd8b0 str r11, [r12, #0x4] */
/* @0xbd8b4 str r10, [r12, #0x8] */
/* @0xbd8b8 str r9, [r12, #0xc] */
/* @0xbd8bc bl 0xbd840 <_ZN15CSkeletonSprite12SimpleDecodeEPhi> */
/* @0xbd8c0 mov r1, r8 */
/* @0xbd8c4 mov r0, r4 */
/* @0xbd8c8 mov r2, r7 */
/* @0xbd8cc bl 0xbd840 <_ZN15CSkeletonSprite12SimpleDecodeEPhi> */
/* @0xbd8d0 ldr r2, [pc, #0x34] */
/* @0xbd8d4 mov r1, r7 */
/* @0xbd8d8 mov r3, r5 */
/* @0xbd8dc add r2, pc, r2 */
/* @0xbd8e0 mov r0, r8 */
/* @0xbd8e4 bl 0x284174 <spAtlas_create> */
/* @0xbd8e8 str r0, [r4, #0x8] */
/* @0xbd8ec bl 0x28b734 <spSkeletonJson_create> */
/* @0xbd8f0 mov r1, r6 */
/* @0xbd8f4 str r0, [r4] */
/* @0xbd8f8 bl 0x28b84c <spSkeletonJson_readSkeletonData> */
/* @0xbd8fc str r0, [r4, #0x4] */
/* @0xbd900 mov r0, r4 */
/* @0xbd904 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xbd908 eorseq r12, r11, r8, lsl #8 */
/* @0xbd90c eoreq r1, r7, r10, asr r2 */

/* ── FUNC 0xbd86c · CSkeletonSprite::CSkeletonSprite(char*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int) · alias of the symbol above · insn=0 */

/* ── FUNC 0xbd910 · CSkeletonSprite::~CSkeletonSprite() · size=92 · insn=23 */
/* @0xbd910 push {r3, r4, r5, lr} */
/* @0xbd914 mov r5, r0 */
/* @0xbd918 ldr r0, [r0, #0x4] */
/* @0xbd91c cmp r0, #0 */
/* @0xbd920 beq 0xbd928 <_ZN15CSkeletonSpriteD2Ev+0x18> */
/* @0xbd924 bl 0x28adf8 <spSkeletonData_dispose> */
/* @0xbd928 ldr r0, [r5] */
/* @0xbd92c cmp r0, #0 */
/* @0xbd930 beq 0xbd938 <_ZN15CSkeletonSpriteD2Ev+0x28> */
/* @0xbd934 bl 0x28b74c <spSkeletonJson_dispose> */
/* @0xbd938 ldr r4, [pc, #0x28] */
/* @0xbd93c mov r3, #1 */
/* @0xbd940 ldr r0, [r5, #0x8] */
/* @0xbd944 ldr r4, [pc, r4] */
/* @0xbd948 cmp r0, #0 */
/* @0xbd94c strb r3, [r4] */
/* @0xbd950 beq 0xbd958 <_ZN15CSkeletonSpriteD2Ev+0x48> */
/* @0xbd954 bl 0x284120 <spAtlas_dispose> */
/* @0xbd958 mov r3, #0 */
/* @0xbd95c mov r0, r5 */
/* @0xbd960 strb r3, [r4] */
/* @0xbd964 pop {r3, r4, r5, pc} */
/* @0xbd968 ldrsbteq pc, [r2], -r4 */

/* ── FUNC 0xbd910 · CSkeletonSprite::~CSkeletonSprite() · alias of the symbol above · insn=0 */

/* ── FUNC 0xbd96c · CSkeletonSprite::HasData() · size=48 · insn=12 */
/* @0xbd96c ldr r3, [r0] */
/* @0xbd970 cmp r3, #0 */
/* @0xbd974 beq 0xbd994 <_ZN15CSkeletonSprite7HasDataEv+0x28> */
/* @0xbd978 ldr r3, [r0, #0x4] */
/* @0xbd97c cmp r3, #0 */
/* @0xbd980 beq 0xbd994 <_ZN15CSkeletonSprite7HasDataEv+0x28> */
/* @0xbd984 ldr r0, [r0, #0x8] */
/* @0xbd988 adds r0, r0, #0 */
/* @0xbd98c movne r0, #1 */
/* @0xbd990 bx lr */
/* @0xbd994 mov r0, r3 */
/* @0xbd998 bx lr */

/* ── FUNC 0xbd99c · CSkeletonSprite::LoadFromFile(char*, char*) · size=580 · insn=145 */
/* @0xbd99c push {r4, r5, r6, r7, r8, lr} */
/* @0xbd9a0 mov r8, r0 */
/* @0xbd9a4 sub sp, sp, #16 */
/* @0xbd9a8 mov r0, r2 */
/* @0xbd9ac mov r5, r1 */
/* @0xbd9b0 mov r6, r2 */
/* @0xbd9b4 bl 0xb6538 <strlen@plt> */
/* @0xbd9b8 mov r4, r0 */
/* @0xbd9bc mov r0, r5 */
/* @0xbd9c0 bl 0xb6538 <strlen@plt> */
/* @0xbd9c4 add r0, r4, r0 */
/* @0xbd9c8 add r0, r0, #7 */
/* @0xbd9cc bl 0xb6544 <malloc@plt> */
/* @0xbd9d0 ldr r1, [pc, #0x1e8] */
/* @0xbd9d4 mov r2, r6 */
/* @0xbd9d8 mov r3, r5 */
/* @0xbd9dc add r1, pc, r1 */
/* @0xbd9e0 mov r4, r0 */
/* @0xbd9e4 bl 0xb6550 <sprintf@plt> */
/* @0xbd9e8 mov r0, r4 */
/* @0xbd9ec mov r3, #0 */
/* @0xbd9f0 str r3, [sp, #0x8] */
/* @0xbd9f4 str r3, [sp, #0xc] */
/* @0xbd9f8 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0xbd9fc cmp r0, #0 */
/* @0xbda00 mov r0, r4 */
/* @0xbda04 beq 0xbdb74 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x1d8> */
/* @0xbda08 add r1, sp, #8 */
/* @0xbda0c bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0xbda10 mov r7, r0 */
/* @0xbda14 ldr r1, [pc, #0x1a8] */
/* @0xbda18 mov r2, r6 */
/* @0xbda1c mov r3, r5 */
/* @0xbda20 mov r0, r4 */
/* @0xbda24 add r1, pc, r1 */
/* @0xbda28 bl 0xb6550 <sprintf@plt> */
/* @0xbda2c mov r0, r4 */
/* @0xbda30 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0xbda34 cmp r0, #0 */
/* @0xbda38 mov r0, r4 */
/* @0xbda3c beq 0xbdb4c <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x1b0> */
/* @0xbda40 add r1, sp, #12 */
/* @0xbda44 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0xbda48 mov r5, r0 */
/* @0xbda4c cmp r5, #0 */
/* @0xbda50 cmpne r7, #0 */
/* @0xbda54 moveq r6, #0 */
/* @0xbda58 movne r6, #1 */
/* @0xbda5c beq 0xbdb28 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x18c> */
/* @0xbda60 ldr r2, [pc, #0x160] */
/* @0xbda64 mov r3, #0 */
/* @0xbda68 ldr r1, [sp, #0x8] */
/* @0xbda6c mov r0, r7 */
/* @0xbda70 add r2, pc, r2 */
/* @0xbda74 bl 0x284174 <spAtlas_create> */
/* @0xbda78 ldr r3, [pc, #0x14c] */
/* @0xbda7c ldr r1, [pc, #0x14c] */
/* @0xbda80 ldr r3, [pc, r3] */
/* @0xbda84 add r1, pc, r1 */
/* @0xbda88 ldr r6, [r3] */
/* @0xbda8c ldr lr, [r6] */
/* @0xbda90 ldr r12, [r0, #0x4] */
/* @0xbda94 str r0, [r8, #0x8] */
/* @0xbda98 mov r0, r6 */
/* @0xbda9c ldm r12, {r2, r3} */
/* @0xbdaa0 ldr r12, [r12, #0x8] */
/* @0xbdaa4 str r12, [sp] */
/* @0xbdaa8 ldr r12, [lr, #0xc] */
/* @0xbdaac blx r12 */
/* @0xbdab0 ldr r3, [r8, #0x8] */
/* @0xbdab4 ldr lr, [r6] */
/* @0xbdab8 mov r0, r6 */
/* @0xbdabc ldr r1, [pc, #0x110] */
/* @0xbdac0 ldr r12, [r3] */
/* @0xbdac4 add r1, pc, r1 */
/* @0xbdac8 ldr r3, [r12, #0x20] */
/* @0xbdacc ldr r2, [r12, #0x4] */
/* @0xbdad0 ldr r12, [r12, #0x24] */
/* @0xbdad4 str r12, [sp] */
/* @0xbdad8 ldr r12, [lr, #0xc] */
/* @0xbdadc blx r12 */
/* @0xbdae0 ldr r0, [r8, #0x8] */
/* @0xbdae4 bl 0x28b734 <spSkeletonJson_create> */
/* @0xbdae8 mov r1, r5 */
/* @0xbdaec str r0, [r8] */
/* @0xbdaf0 bl 0x28b84c <spSkeletonJson_readSkeletonData> */
/* @0xbdaf4 cmp r0, #0 */
/* @0xbdaf8 mov r3, r0 */
/* @0xbdafc str r0, [r8, #0x4] */
/* @0xbdb00 beq 0xbdb98 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x1fc> */
/* @0xbdb04 ldr r2, [r0, #0x28] */
/* @0xbdb08 mov r0, r6 */
/* @0xbdb0c ldr r3, [r6] */
/* @0xbdb10 mov r6, #1 */
/* @0xbdb14 ldr r1, [pc, #0xbc] */
/* @0xbdb18 ldr r2, [r2] */
/* @0xbdb1c add r1, pc, r1 */
/* @0xbdb20 ldr r3, [r3, #0xc] */
/* @0xbdb24 blx r3 */
/* @0xbdb28 mov r0, r7 */
/* @0xbdb2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xbdb30 mov r0, r5 */
/* @0xbdb34 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xbdb38 mov r0, r4 */
/* @0xbdb3c bl 0xb655c <free@plt> */
/* @0xbdb40 mov r0, r6 */
/* @0xbdb44 add sp, sp, #16 */
/* @0xbdb48 pop {r4, r5, r6, r7, r8, pc} */
/* @0xbdb4c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0xbdb50 cmp r0, #0 */
/* @0xbdb54 moveq r5, r0 */
/* @0xbdb58 moveq r6, r5 */
/* @0xbdb5c beq 0xbdb28 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x18c> */
/* @0xbdb60 mov r0, r4 */
/* @0xbdb64 add r1, sp, #12 */
/* @0xbdb68 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0xbdb6c mov r5, r0 */
/* @0xbdb70 b 0xbda4c <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0xb0> */
/* @0xbdb74 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0xbdb78 cmp r0, #0 */
/* @0xbdb7c moveq r7, r0 */
/* @0xbdb80 beq 0xbda14 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x78> */
/* @0xbdb84 mov r0, r4 */
/* @0xbdb88 add r1, sp, #8 */
/* @0xbdb8c bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0xbdb90 mov r7, r0 */
/* @0xbdb94 b 0xbda14 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x78> */
/* @0xbdb98 ldr r12, [r6] */
/* @0xbdb9c mov r0, r6 */
/* @0xbdba0 ldr r2, [r8] */
/* @0xbdba4 mov r6, r3 */
/* @0xbdba8 ldr r1, [pc, #0x2c] */
/* @0xbdbac ldr r3, [r12, #0xc] */
/* @0xbdbb0 add r1, pc, r1 */
/* @0xbdbb4 ldr r2, [r2, #0x8] */
/* @0xbdbb8 blx r3 */
/* @0xbdbbc b 0xbdb28 <_ZN15CSkeletonSprite12LoadFromFileEPcS0_+0x18c> */
/* @0xbdbc0 eoreq r2, r7, r12, asr sp */
/* @0xbdbc4 eoreq r2, r7, r0, lsr #26 */
/* @0xbdbc8 eoreq r1, r7, r6, asr #1 */
/* @0xbdbcc mlaseq r2, r4, r12, pc */
/* @0xbdbd0 eoreq r2, r7, r12, asr #25 */
/* @0xbdbd4 .word 0x00272cb4 */
/* @0xbdbd8 eoreq r2, r7, r12, lsl #25 */
/* @0xbdbdc eoreq r2, r7, r12, ror #23 */

/* ── FUNC 0xbdbe0 · CSkeletonSprite::CSkeletonSprite(char*) · size=336 · insn=84 */
/* @0xbdbe0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xbdbe4 mov r9, r0 */
/* @0xbdbe8 mov r7, #0 */
/* @0xbdbec mov r0, r1 */
/* @0xbdbf0 str r7, [r9] */
/* @0xbdbf4 mov r10, r1 */
/* @0xbdbf8 str r7, [r9, #0x4] */
/* @0xbdbfc str r7, [r9, #0x8] */
/* @0xbdc00 bl 0xb6538 <strlen@plt> */
/* @0xbdc04 subs r6, r0, #0 */
/* @0xbdc08 blt 0xbdd20 <_ZN15CSkeletonSpriteC2EPc+0x140> */
/* @0xbdc0c add r5, r6, #1 */
/* @0xbdc10 mov r11, r7 */
/* @0xbdc14 add r5, r10, r5 */
/* @0xbdc18 mov r4, r6 */
/* @0xbdc1c b 0xbdc3c <_ZN15CSkeletonSpriteC2EPc+0x5c> */
/* @0xbdc20 cmp r3, #92 */
/* @0xbdc24 cmpne r3, #47 */
/* @0xbdc28 beq 0xbdc94 <_ZN15CSkeletonSpriteC2EPc+0xb4> */
/* @0xbdc2c sub r4, r4, #1 */
/* @0xbdc30 sub r5, r5, #1 */
/* @0xbdc34 cmn r4, #1 */
/* @0xbdc38 beq 0xbdc88 <_ZN15CSkeletonSpriteC2EPc+0xa8> */
/* @0xbdc3c cmp r7, #0 */
/* @0xbdc40 ldrb r3, [r5, #-0x1] */
/* @0xbdc44 rsb r8, r4, r6 */
/* @0xbdc48 bne 0xbdc20 <_ZN15CSkeletonSpriteC2EPc+0x40> */
/* @0xbdc4c cmp r3, #46 */
/* @0xbdc50 bne 0xbdc20 <_ZN15CSkeletonSpriteC2EPc+0x40> */
/* @0xbdc54 mov r0, r8 */
/* @0xbdc58 mov r6, r4 */
/* @0xbdc5c bl 0xb6544 <malloc@plt> */
/* @0xbdc60 sub r4, r4, #1 */
/* @0xbdc64 mov r1, r5 */
/* @0xbdc68 sub r2, r8, #1 */
/* @0xbdc6c sub r5, r5, #1 */
/* @0xbdc70 mov r7, r0 */
/* @0xbdc74 bl 0xb6568 <strncpy@plt> */
/* @0xbdc78 add r8, r7, r8 */
/* @0xbdc7c cmn r4, #1 */
/* @0xbdc80 strb r11, [r8, #-0x1] */
/* @0xbdc84 bne 0xbdc3c <_ZN15CSkeletonSpriteC2EPc+0x5c> */
/* @0xbdc88 mov r4, #0 */
/* @0xbdc8c mov r5, r4 */
/* @0xbdc90 b 0xbdce0 <_ZN15CSkeletonSpriteC2EPc+0x100> */
/* @0xbdc94 mov r0, r8 */
/* @0xbdc98 mov r11, #0 */
/* @0xbdc9c bl 0xb6544 <malloc@plt> */
/* @0xbdca0 add r1, r4, #1 */
/* @0xbdca4 mov r2, r8 */
/* @0xbdca8 add r1, r10, r1 */
/* @0xbdcac mov r5, r0 */
/* @0xbdcb0 bl 0xb6568 <strncpy@plt> */
/* @0xbdcb4 add r3, r5, r8 */
/* @0xbdcb8 rsb r8, r8, #1 */
/* @0xbdcbc add r6, r6, r8 */
/* @0xbdcc0 strb r11, [r3, #-0x1] */
/* @0xbdcc4 add r0, r6, #1 */
/* @0xbdcc8 bl 0xb6544 <malloc@plt> */
/* @0xbdccc mov r1, r10 */
/* @0xbdcd0 mov r2, r6 */
/* @0xbdcd4 mov r4, r0 */
/* @0xbdcd8 bl 0xb6568 <strncpy@plt> */
/* @0xbdcdc strb r11, [r4, r6] */
/* @0xbdce0 ldr r3, [pc, #0x44] */
/* @0xbdce4 mov r1, r5 */
/* @0xbdce8 mov r2, r4 */
/* @0xbdcec mov r0, r9 */
/* @0xbdcf0 add r3, pc, r3 */
/* @0xbdcf4 mov r12, #0 */
/* @0xbdcf8 str r12, [r3] */
/* @0xbdcfc bl 0xbd99c <_ZN15CSkeletonSprite12LoadFromFileEPcS0_> */
/* @0xbdd00 mov r0, r5 */
/* @0xbdd04 bl 0xb655c <free@plt> */
/* @0xbdd08 mov r0, r7 */
/* @0xbdd0c bl 0xb655c <free@plt> */
/* @0xbdd10 mov r0, r4 */
/* @0xbdd14 bl 0xb655c <free@plt> */
/* @0xbdd18 mov r0, r9 */
/* @0xbdd1c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xbdd20 mov r4, r7 */
/* @0xbdd24 mov r5, r4 */
/* @0xbdd28 b 0xbdce0 <_ZN15CSkeletonSpriteC2EPc+0x100> */
/* @0xbdd2c eorseq r11, r11, r0, lsr #31 */

/* ── FUNC 0xbdbe0 · CSkeletonSprite::CSkeletonSprite(char*) · alias of the symbol above · insn=0 */

/* ── FUNC 0xbdd30 · CSkeletonSprite::DrawCollisionBounds(spSkeletonBounds*) · size=232 · insn=58 */
/* @0xbdd30 ldr r0, [r1, #0xc] */
/* @0xbdd34 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xbdd38 mov r10, r1 */
/* @0xbdd3c mov r2, r0 */
/* @0xbdd40 ldr r1, [r1, #0x10] */
/* @0xbdd44 ldr r3, [r10, #0x18] */
/* @0xbdd48 bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0xbdd4c ldr r1, [r10, #0x18] */
/* @0xbdd50 ldr r0, [r10, #0xc] */
/* @0xbdd54 ldr r2, [r10, #0x14] */
/* @0xbdd58 mov r3, r1 */
/* @0xbdd5c bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0xbdd60 ldr r0, [r10, #0x14] */
/* @0xbdd64 ldr r1, [r10, #0x18] */
/* @0xbdd68 ldr r3, [r10, #0x10] */
/* @0xbdd6c mov r2, r0 */
/* @0xbdd70 bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0xbdd74 ldr r1, [r10, #0x10] */
/* @0xbdd78 ldr r0, [r10, #0x14] */
/* @0xbdd7c ldr r2, [r10, #0xc] */
/* @0xbdd80 mov r3, r1 */
/* @0xbdd84 bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0xbdd88 ldr r3, [r10] */
/* @0xbdd8c cmp r3, #0 */
/* @0xbdd90 pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xbdd94 mov r9, #0 */
/* @0xbdd98 ldr r2, [r10, #0x8] */
/* @0xbdd9c ldr r7, [r2, r9, lsl #2] */
/* @0xbdda0 ldr r6, [r7, #0x4] */
/* @0xbdda4 add r6, r6, r6, lsr #31 */
/* @0xbdda8 asr r6, r6, #1 */
/* @0xbddac cmp r6, #0 */
/* @0xbddb0 subgt r8, r6, #1 */
/* @0xbddb4 movgt r4, #1 */
/* @0xbddb8 movgt r5, #0 */
/* @0xbddbc ble 0xbde08 <_ZN15CSkeletonSprite19DrawCollisionBoundsEP16spSkeletonBounds+0xd8> */
/* @0xbddc0 ldr r12, [r7] */
/* @0xbddc4 sub r3, r4, #1 */
/* @0xbddc8 cmp r3, r8 */
/* @0xbddcc mov r11, r4 */
/* @0xbddd0 add r3, r12, r5 */
/* @0xbddd4 addne r12, r12, r4, lsl #3 */
/* @0xbddd8 ldreq r2, [r12] */
/* @0xbdddc add r5, r5, #8 */
/* @0xbdde0 ldr r0, [r3] */
/* @0xbdde4 add r4, r4, #1 */
/* @0xbdde8 ldr r1, [r3, #0x4] */
/* @0xbddec ldrne r2, [r12] */
/* @0xbddf0 ldreq r3, [r12, #0x4] */
/* @0xbddf4 ldrne r3, [r3, #0xc] */
/* @0xbddf8 bl 0x16a21c <_Z12GR_Draw_Lineffff> */
/* @0xbddfc cmp r6, r11 */
/* @0xbde00 bgt 0xbddc0 <_ZN15CSkeletonSprite19DrawCollisionBoundsEP16spSkeletonBounds+0x90> */
/* @0xbde04 ldr r3, [r10] */
/* @0xbde08 add r9, r9, #1 */
/* @0xbde0c cmp r3, r9 */
/* @0xbde10 bgt 0xbdd98 <_ZN15CSkeletonSprite19DrawCollisionBoundsEP16spSkeletonBounds+0x68> */
/* @0xbde14 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0xbde18 · CSkeletonSprite::DrawRegion(spSlot*, unsigned int) · size=316 · insn=79 */
/* @0xbde18 push {r4, r5, lr} */
/* @0xbde1c sub sp, sp, #36 */
/* @0xbde20 ldr r4, [r1, #0x18] */
/* @0xbde24 mov r5, r2 */
/* @0xbde28 ldr r1, [r1, #0x4] */
/* @0xbde2c mov r2, sp */
/* @0xbde30 mov r0, r4 */
/* @0xbde34 bl 0x289174 <spRegionAttachment_computeWorldVertices> */
/* @0xbde38 ldr r12, [r4, #0x40] */
/* @0xbde3c ldr r1, [pc, #0x108] */
/* @0xbde40 mov r2, #24 */
/* @0xbde44 mov r3, #6 */
/* @0xbde48 mov r0, #4 */
/* @0xbde4c ldr r12, [r12, #0x48] */
/* @0xbde50 ldr r1, [pc, r1] */
/* @0xbde54 ldr r1, [r1, #0x4] */
/* @0xbde58 ldr r12, [r12, #0x1c] */
/* @0xbde5c ldr r1, [r1, r12, lsl #2] */
/* @0xbde60 ldr r1, [r1] */
/* @0xbde64 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0xbde68 ldr r2, [sp, #0x8] */
/* @0xbde6c str r2, [r0] */
/* @0xbde70 ldr r1, [sp, #0xc] */
/* @0xbde74 str r2, [r0, #0x78] */
/* @0xbde78 str r5, [r0, #0x6c] */
/* @0xbde7c str r1, [r0, #0x4] */
/* @0xbde80 ldr r3, [sp, #0x10] */
/* @0xbde84 str r1, [r0, #0x7c] */
/* @0xbde88 str r5, [r0, #0x3c] */
/* @0xbde8c str r3, [r0, #0x18] */
/* @0xbde90 ldr r3, [sp, #0x14] */
/* @0xbde94 str r5, [r0, #0x54] */
/* @0xbde98 str r3, [r0, #0x1c] */
/* @0xbde9c ldr r2, [sp, #0x18] */
/* @0xbdea0 ldr r3, [pc, #0xa8] */
/* @0xbdea4 ldr r1, [sp, #0x4] */
/* @0xbdea8 str r2, [r0, #0x30] */
/* @0xbdeac ldr r3, [pc, r3] */
/* @0xbdeb0 str r2, [r0, #0x48] */
/* @0xbdeb4 ldr r2, [sp] */
/* @0xbdeb8 ldr r3, [r3] */
/* @0xbdebc str r1, [r0, #0x64] */
/* @0xbdec0 str r2, [r0, #0x60] */
/* @0xbdec4 ldr r2, [sp, #0x1c] */
/* @0xbdec8 str r3, [r0, #0x68] */
/* @0xbdecc str r3, [r0, #0x38] */
/* @0xbded0 str r3, [r0, #0x50] */
/* @0xbded4 str r3, [r0, #0x20] */
/* @0xbded8 str r3, [r0, #0x8] */
/* @0xbdedc str r3, [r0, #0x80] */
/* @0xbdee0 str r2, [r0, #0x4c] */
/* @0xbdee4 str r2, [r0, #0x34] */
/* @0xbdee8 str r5, [r0, #0x24] */
/* @0xbdeec str r5, [r0, #0xc] */
/* @0xbdef0 str r5, [r0, #0x84] */
/* @0xbdef4 ldr r3, [r4, #0x84] */
/* @0xbdef8 str r3, [r0, #0x88] */
/* @0xbdefc str r3, [r0, #0x10] */
/* @0xbdf00 ldr r3, [r4, #0x88] */
/* @0xbdf04 str r3, [r0, #0x8c] */
/* @0xbdf08 str r3, [r0, #0x14] */
/* @0xbdf0c ldr r3, [r4, #0x8c] */
/* @0xbdf10 str r3, [r0, #0x28] */
/* @0xbdf14 ldr r3, [r4, #0x90] */
/* @0xbdf18 str r3, [r0, #0x2c] */
/* @0xbdf1c ldr r3, [r4, #0x94] */
/* @0xbdf20 str r3, [r0, #0x58] */
/* @0xbdf24 str r3, [r0, #0x40] */
/* @0xbdf28 ldr r3, [r4, #0x98] */
/* @0xbdf2c str r3, [r0, #0x5c] */
/* @0xbdf30 str r3, [r0, #0x44] */
/* @0xbdf34 ldr r3, [r4, #0x7c] */
/* @0xbdf38 str r3, [r0, #0x70] */
/* @0xbdf3c ldr r3, [r4, #0x80] */
/* @0xbdf40 str r3, [r0, #0x74] */
/* @0xbdf44 add sp, sp, #36 */
/* @0xbdf48 pop {r4, r5, pc} */
/* @0xbdf4c eorseq pc, r2, r12, asr #21 */
/* @0xbdf50 eorseq pc, r2, r4, ror r10 */

/* ── FUNC 0xbdf54 · CSkeletonSprite::DrawMesh(spSlot*, unsigned int) · size=256 · insn=64 */
/* @0xbdf54 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xbdf58 mov r7, r1 */
/* @0xbdf5c ldr r4, [r1, #0x18] */
/* @0xbdf60 mov r3, #1 */
/* @0xbdf64 ldr r1, [pc, #0xdc] */
/* @0xbdf68 mov r6, r2 */
/* @0xbdf6c movw r2, #0x275 */
/* @0xbdf70 ldr r0, [r4, #0x18] */
/* @0xbdf74 add r1, pc, r1 */
/* @0xbdf78 lsl r0, r0, #2 */
/* @0xbdf7c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xbdf80 mov r1, r7 */
/* @0xbdf84 mov r5, r0 */
/* @0xbdf88 mov r0, r4 */
/* @0xbdf8c mov r2, r5 */
/* @0xbdf90 bl 0x287650 <spMeshAttachment_computeWorldVertices> */
/* @0xbdf94 ldr r12, [r4, #0x24] */
/* @0xbdf98 ldr r1, [pc, #0xac] */
/* @0xbdf9c mov r0, #4 */
/* @0xbdfa0 ldr r3, [r4, #0x60] */
/* @0xbdfa4 mov r2, #24 */
/* @0xbdfa8 ldr r12, [r12, #0x48] */
/* @0xbdfac ldr r1, [pc, r1] */
/* @0xbdfb0 ldr r1, [r1, #0x4] */
/* @0xbdfb4 ldr r12, [r12, #0x1c] */
/* @0xbdfb8 ldr r1, [r1, r12, lsl #2] */
/* @0xbdfbc ldr r1, [r1] */
/* @0xbdfc0 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0xbdfc4 ldr r7, [r4, #0x60] */
/* @0xbdfc8 cmp r7, #0 */
/* @0xbdfcc ble 0xbe03c <_ZN15CSkeletonSprite8DrawMeshEP6spSlotj+0xe8> */
/* @0xbdfd0 ldr r2, [pc, #0x78] */
/* @0xbdfd4 add r3, r0, #24 */
/* @0xbdfd8 ldr r12, [r4, #0x64] */
/* @0xbdfdc ldr r2, [pc, r2] */
/* @0xbdfe0 ldr r0, [r4, #0x5c] */
/* @0xbdfe4 add r7, r12, r7, lsl #1 */
/* @0xbdfe8 ldr r9, [r2] */
/* @0xbdfec ldrh r1, [r12], #2 */
/* @0xbdff0 add r3, r3, #24 */
/* @0xbdff4 cmp r12, r7 */
/* @0xbdff8 lsl r1, r1, #3 */
/* @0xbdffc add r2, r5, r1 */
/* @0xbe000 add r4, r1, #4 */
/* @0xbe004 add r1, r0, r1 */
/* @0xbe008 ldr r8, [r2] */
/* @0xbe00c add r2, r5, r4 */
/* @0xbe010 add r4, r0, r4 */
/* @0xbe014 str r8, [r3, #-0x30] */
/* @0xbe018 ldr r2, [r2] */
/* @0xbe01c str r2, [r3, #-0x2c] */
/* @0xbe020 ldr r2, [r1] */
/* @0xbe024 str r2, [r3, #-0x20] */
/* @0xbe028 ldr r2, [r4] */
/* @0xbe02c str r9, [r3, #-0x28] */
/* @0xbe030 str r6, [r3, #-0x24] */
/* @0xbe034 str r2, [r3, #-0x1c] */
/* @0xbe038 bne 0xbdfec <_ZN15CSkeletonSprite8DrawMeshEP6spSlotj+0x98> */
/* @0xbe03c mov r0, r5 */
/* @0xbe040 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xbe044 b 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xbe048 eoreq r2, r7, r12, asr #16 */
/* @0xbe04c eorseq pc, r2, r0, ror r9 */
/* @0xbe050 eorseq pc, r2, r4, asr #18 */

/* ── FUNC 0xbe054 · CSkeletonSprite::DrawSkeleton(spSkeleton*, unsigned int, float) · size=320 · insn=80 */
/* @0xbe054 ubfx r12, r2, #0x8, #0x8 */
/* @0xbe058 push {r4, r5, r6, r7, r8, lr} */
/* @0xbe05c vpush {d8, d9, d10} */
/* @0xbe060 vmov s18, r12 */
/* @0xbe064 vldr s16, [pc, #292] */
/* @0xbe068 uxtb r12, r2 */
/* @0xbe06c ubfx r2, r2, #0x10, #0x8 */
/* @0xbe070 vcvt.f32.s32 s18, s18 */
/* @0xbe074 ldr r7, [r1, #0x10] */
/* @0xbe078 vmov s17, r12 */
/* @0xbe07c mov r4, r1 */
/* @0xbe080 vmov s19, r2 */
/* @0xbe084 cmp r7, #0 */
/* @0xbe088 mov r6, r0 */
/* @0xbe08c vmov s20, r3 */
/* @0xbe090 vcvt.f32.s32 s17, s17 */
/* @0xbe094 vcvt.f32.s32 s19, s19 */
/* @0xbe098 vdiv.f32 s17, s17, s16 */
/* @0xbe09c vdiv.f32 s18, s18, s16 */
/* @0xbe0a0 vdiv.f32 s19, s19, s16 */
/* @0xbe0a4 ble 0xbe188 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x134> */
/* @0xbe0a8 mov r5, #0 */
/* @0xbe0ac b 0xbe0c8 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x74> */
/* @0xbe0b0 cmp r3, #2 */
/* @0xbe0b4 bne 0xbe0bc <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x68> */
/* @0xbe0b8 bl 0xbdf54 <_ZN15CSkeletonSprite8DrawMeshEP6spSlotj> */
/* @0xbe0bc add r5, r5, #1 */
/* @0xbe0c0 cmp r5, r7 */
/* @0xbe0c4 beq 0xbe188 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x134> */
/* @0xbe0c8 ldr r3, [r4, #0x18] */
/* @0xbe0cc ldr r1, [r3, r5, lsl #2] */
/* @0xbe0d0 ldr r3, [r1, #0x18] */
/* @0xbe0d4 cmp r3, #0 */
/* @0xbe0d8 beq 0xbe0bc <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x68> */
/* @0xbe0dc vldr s15, [r1, #12] */
/* @0xbe0e0 vldr s12, [r4, #64] */
/* @0xbe0e4 vmul.f32 s12, s12, s15 */
/* @0xbe0e8 vldr s9, [r4, #68] */
/* @0xbe0ec vldr s13, [r1, #16] */
/* @0xbe0f0 vldr s10, [r4, #60] */
/* @0xbe0f4 vldr s14, [r1, #8] */
/* @0xbe0f8 vldr s11, [r4, #72] */
/* @0xbe0fc vldr s15, [r1, #20] */
/* @0xbe100 ldr r3, [r3, #0x4] */
/* @0xbe104 cmp r3, #0 */
/* @0xbe108 vmul.f32 s13, s9, s13 */
/* @0xbe10c vmul.f32 s14, s10, s14 */
/* @0xbe110 vmul.f32 s12, s12, s18 */
/* @0xbe114 vmul.f32 s13, s13, s19 */
/* @0xbe118 vmul.f32 s14, s14, s17 */
/* @0xbe11c vmul.f32 s15, s11, s15 */
/* @0xbe120 vmul.f32 s12, s12, s16 */
/* @0xbe124 vmul.f32 s13, s13, s16 */
/* @0xbe128 vmul.f32 s14, s14, s16 */
/* @0xbe12c vmul.f32 s15, s15, s20 */
/* @0xbe130 vcvt.u32.f32 s12, s12 */
/* @0xbe134 vcvt.u32.f32 s13, s13 */
/* @0xbe138 vmov r8, s12 */
/* @0xbe13c vcvt.u32.f32 s14, s14 */
/* @0xbe140 vmov r12, s13 */
/* @0xbe144 vmov r0, s14 */
/* @0xbe148 vmul.f32 s15, s15, s16 */
/* @0xbe14c uxtb r8, r8 */
/* @0xbe150 lsl r8, r8, #8 */
/* @0xbe154 vcvt.u32.f32 s15, s15 */
/* @0xbe158 uxtb r12, r12 */
/* @0xbe15c orr r12, r8, r12, lsl #16 */
/* @0xbe160 uxtb r0, r0 */
/* @0xbe164 orr r2, r12, r0 */
/* @0xbe168 vmov r0, s15 */
/* @0xbe16c orr r2, r2, r0, lsl #24 */
/* @0xbe170 mov r0, r6 */
/* @0xbe174 bne 0xbe0b0 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x5c> */
/* @0xbe178 add r5, r5, #1 */
/* @0xbe17c bl 0xbde18 <_ZN15CSkeletonSprite10DrawRegionEP6spSlotj> */
/* @0xbe180 cmp r5, r7 */
/* @0xbe184 bne 0xbe0c8 <_ZN15CSkeletonSprite12DrawSkeletonEP10spSkeletonjf+0x74> */
/* @0xbe188 vpop {d8, d9, d10} */
/* @0xbe18c pop {r4, r5, r6, r7, r8, pc} */
/* @0xbe190 cmnmi pc, #0 */

/* ── FUNC 0xbe194 · CSkeletonInstance::~CSkeletonInstance() · size=140 · insn=35 */
/* @0xbe194 push {r3, r4, r5, lr} */
/* @0xbe198 mov r5, r0 */
/* @0xbe19c ldr r0, [r0, #0x28] */
/* @0xbe1a0 cmp r0, #0 */
/* @0xbe1a4 beq 0xbe1b4 <_ZN17CSkeletonInstanceD2Ev+0x20> */
/* @0xbe1a8 bl 0x2831cc <spAnimationState_dispose> */
/* @0xbe1ac ldr r0, [r5, #0x2c] */
/* @0xbe1b0 bl 0x283b58 <spAnimationStateData_dispose> */
/* @0xbe1b4 ldr r3, [r5, #0x1c] */
/* @0xbe1b8 cmp r3, #0 */
/* @0xbe1bc beq 0xbe1d0 <_ZN17CSkeletonInstanceD2Ev+0x3c> */
/* @0xbe1c0 ldr r0, [r5, #0x20] */
/* @0xbe1c4 bl 0x28a858 <spSkeletonBounds_dispose> */
/* @0xbe1c8 ldr r0, [r5, #0x1c] */
/* @0xbe1cc bl 0x2894cc <spSkeleton_dispose> */
/* @0xbe1d0 ldr r3, [r5, #0x10] */
/* @0xbe1d4 cmp r3, #0 */
/* @0xbe1d8 ble 0xbe208 <_ZN17CSkeletonInstanceD2Ev+0x74> */
/* @0xbe1dc mov r4, #0 */
/* @0xbe1e0 ldr r3, [r5, #0x18] */
/* @0xbe1e4 ldr r0, [r3, r4, lsl #2] */
/* @0xbe1e8 bl 0x284120 <spAtlas_dispose> */
/* @0xbe1ec ldr r3, [r5, #0x14] */
/* @0xbe1f0 ldr r0, [r3, r4, lsl #2] */
/* @0xbe1f4 add r4, r4, #1 */
/* @0xbe1f8 bl 0x284cb4 <spAttachment_dispose> */
/* @0xbe1fc ldr r3, [r5, #0x10] */
/* @0xbe200 cmp r3, r4 */
/* @0xbe204 bgt 0xbe1e0 <_ZN17CSkeletonInstanceD2Ev+0x4c> */
/* @0xbe208 ldr r0, [r5, #0x14] */
/* @0xbe20c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xbe210 ldr r0, [r5, #0x18] */
/* @0xbe214 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xbe218 mov r0, r5 */
/* @0xbe21c pop {r3, r4, r5, pc} */

/* ── FUNC 0xbe194 · CSkeletonInstance::~CSkeletonInstance() · alias of the symbol above · insn=0 */

/* ── FUNC 0xbe220 · CSkeletonInstance::FrameCount(int) · size=236 · insn=59 */
/* @0xbe220 push {r3, r4, r5, lr} */
/* @0xbe224 subs r4, r1, #0 */
/* @0xbe228 mov r5, r0 */
/* @0xbe22c blt 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4> */
/* @0xbe230 ldr r3, [r0, #0x28] */
/* @0xbe234 cmp r3, #0 */
/* @0xbe238 beq 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4> */
/* @0xbe23c ldr r2, [r3, #0xc] */
/* @0xbe240 cmp r4, r2 */
/* @0xbe244 bge 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4> */
/* @0xbe248 ldr r2, [r3, #0x10] */
/* @0xbe24c ldr r3, [r2, r4, lsl #2] */
/* @0xbe250 cmp r3, #0 */
/* @0xbe254 beq 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4> */
/* @0xbe258 ldr r3, [pc, #0xa0] */
/* @0xbe25c ldr r3, [pc, r3] */
/* @0xbe260 ldrb r3, [r3] */
/* @0xbe264 cmp r3, #0 */
/* @0xbe268 bne 0xbe2b4 <_ZN17CSkeletonInstance10FrameCountEi+0x94> */
/* @0xbe26c ldr r3, [pc, #0x90] */
/* @0xbe270 ldr r3, [pc, r3] */
/* @0xbe274 ldr r3, [r3] */
/* @0xbe278 cmp r3, #0 */
/* @0xbe27c moveq r3, #30 */
/* @0xbe280 ldrne r3, [r3, #0xc] */
/* @0xbe284 ldr r2, [r2, r4, lsl #2] */
/* @0xbe288 ldr r2, [r2, #0xc] */
/* @0xbe28c cmp r2, #0 */
/* @0xbe290 beq 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4> */
/* @0xbe294 vmov.f32 s15, #5.000000e-01 */
/* @0xbe298 vldr s13, [r2, #4] */
/* @0xbe29c vmov s12, r3 */
/* @0xbe2a0 vcvt.f32.s32 s14, s12 */
/* @0xbe2a4 vmla.f32 s15, s14, s13 */
/* @0xbe2a8 vcvt.s32.f32 s15, s15 */
/* @0xbe2ac vmov r0, s15 */
/* @0xbe2b0 pop {r3, r4, r5, pc} */
/* @0xbe2b4 ldr r0, [pc, #0x4c] */
/* @0xbe2b8 ldr r0, [pc, r0] */
/* @0xbe2bc bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0xbe2c0 ldr r2, [r5, #0x28] */
/* @0xbe2c4 cmp r2, #0 */
/* @0xbe2c8 vmov d7, r0, r1 */
/* @0xbe2cc beq 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4> */
/* @0xbe2d0 vcvt.s32.f64 s12, d7 */
/* @0xbe2d4 ldr r1, [r2, #0xc] */
/* @0xbe2d8 cmp r1, r4 */
/* @0xbe2dc vmov r3, s12 */
/* @0xbe2e0 bgt 0xbe2ec <_ZN17CSkeletonInstance10FrameCountEi+0xcc> */
/* @0xbe2e4 mov r0, #0 */
/* @0xbe2e8 pop {r3, r4, r5, pc} */
/* @0xbe2ec ldr r2, [r2, #0x10] */
/* @0xbe2f0 ldr r2, [r2, r4, lsl #2] */
/* @0xbe2f4 cmp r2, #0 */
/* @0xbe2f8 beq 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4> */
/* @0xbe2fc b 0xbe288 <_ZN17CSkeletonInstance10FrameCountEi+0x68> */
/* @0xbe300 eorseq pc, r2, r8, asr #13 */
/* @0xbe304 ldrhteq pc, [r2], -r8 */
/* @0xbe308 eorseq pc, r2, r4, ror r6 */

/* ── FUNC 0xbe30c · CSkeletonInstance::ImageIndex(int) · size=220 · insn=55 */
/* @0xbe30c push {r3, r4, r5, lr} */
/* @0xbe310 subs r4, r1, #0 */
/* @0xbe314 mov r5, r0 */
/* @0xbe318 blt 0xbe3b0 <_ZN17CSkeletonInstance10ImageIndexEi+0xa4> */
/* @0xbe31c ldr r3, [r0, #0x28] */
/* @0xbe320 cmp r3, #0 */
/* @0xbe324 beq 0xbe3b0 <_ZN17CSkeletonInstance10ImageIndexEi+0xa4> */
/* @0xbe328 ldr r2, [r3, #0xc] */
/* @0xbe32c cmp r4, r2 */
/* @0xbe330 bge 0xbe3b0 <_ZN17CSkeletonInstance10ImageIndexEi+0xa4> */
/* @0xbe334 ldr r3, [r3, #0x10] */
/* @0xbe338 ldr r3, [r3, r4, lsl #2] */
/* @0xbe33c cmp r3, #0 */
/* @0xbe340 beq 0xbe3b0 <_ZN17CSkeletonInstance10ImageIndexEi+0xa4> */
/* @0xbe344 ldr r2, [pc, #0x90] */
/* @0xbe348 ldr r2, [pc, r2] */
/* @0xbe34c ldrb r2, [r2] */
/* @0xbe350 cmp r2, #0 */
/* @0xbe354 bne 0xbe3b8 <_ZN17CSkeletonInstance10ImageIndexEi+0xac> */
/* @0xbe358 ldr r2, [pc, #0x80] */
/* @0xbe35c ldr r2, [pc, r2] */
/* @0xbe360 ldr r2, [r2] */
/* @0xbe364 cmp r2, #0 */
/* @0xbe368 beq 0xbe3d4 <_ZN17CSkeletonInstance10ImageIndexEi+0xc8> */
/* @0xbe36c ldr r0, [r2, #0xc] */
/* @0xbe370 cmp r0, #0 */
/* @0xbe374 ble 0xbe3b0 <_ZN17CSkeletonInstance10ImageIndexEi+0xa4> */
/* @0xbe378 ldr r3, [r5, #0x28] */
/* @0xbe37c vmov s14, r0 */
/* @0xbe380 vcvt.f32.s32 s15, s14 */
/* @0xbe384 ldr r3, [r3, #0x10] */
/* @0xbe388 ldr r3, [r3, r4, lsl #2] */
/* @0xbe38c ldr r2, [r3, #0xc] */
/* @0xbe390 vldr s13, [r3, #24] */
/* @0xbe394 vldr s14, [r2, #4] */
/* @0xbe398 vmul.f32 s13, s15, s13 */
/* @0xbe39c pop {r3, r4, r5, lr} */
/* @0xbe3a0 vmul.f32 s14, s15, s14 */
/* @0xbe3a4 vmov r0, s13 */
/* @0xbe3a8 vmov r1, s14 */
/* @0xbe3ac b 0x1e62fc <_Z5fwrapff> */
/* @0xbe3b0 mov r0, #0 */
/* @0xbe3b4 pop {r3, r4, r5, pc} */
/* @0xbe3b8 ldr r0, [pc, #0x24] */
/* @0xbe3bc ldr r0, [pc, r0] */
/* @0xbe3c0 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0xbe3c4 vmov d7, r0, r1 */
/* @0xbe3c8 vcvt.s32.f64 s15, d7 */
/* @0xbe3cc vmov r0, s15 */
/* @0xbe3d0 b 0xbe370 <_ZN17CSkeletonInstance10ImageIndexEi+0x64> */
/* @0xbe3d4 vmov.f32 s15, #3.000000e+01 */
/* @0xbe3d8 b 0xbe38c <_ZN17CSkeletonInstance10ImageIndexEi+0x80> */
/* @0xbe3dc ldrsbteq pc, [r2], -r12 */
/* @0xbe3e0 eorseq pc, r2, r12, asr #11 */
/* @0xbe3e4 eorseq pc, r2, r0, ror r5 */

/* ── FUNC 0xbe3e8 · CSkeletonInstance::SetImageIndex(int, float) · size=260 · insn=65 */
/* @0xbe3e8 push {r4, r5, lr} */
/* @0xbe3ec vpush {d8} */
/* @0xbe3f0 subs r4, r1, #0 */
/* @0xbe3f4 sub sp, sp, #12 */
/* @0xbe3f8 mov r5, r0 */
/* @0xbe3fc blt 0xbe4a8 <_ZN17CSkeletonInstance13SetImageIndexEif+0xc0> */
/* @0xbe400 ldr r3, [r0, #0x28] */
/* @0xbe404 cmp r3, #0 */
/* @0xbe408 beq 0xbe4a8 <_ZN17CSkeletonInstance13SetImageIndexEif+0xc0> */
/* @0xbe40c ldr r1, [r3, #0xc] */
/* @0xbe410 cmp r4, r1 */
/* @0xbe414 bge 0xbe4a8 <_ZN17CSkeletonInstance13SetImageIndexEif+0xc0> */
/* @0xbe418 ldr r3, [r3, #0x10] */
/* @0xbe41c ldr r1, [r3, r4, lsl #2] */
/* @0xbe420 cmp r1, #0 */
/* @0xbe424 beq 0xbe4a8 <_ZN17CSkeletonInstance13SetImageIndexEif+0xc0> */
/* @0xbe428 ldr r3, [pc, #0xb0] */
/* @0xbe42c ldr r3, [pc, r3] */
/* @0xbe430 ldrb r3, [r3] */
/* @0xbe434 cmp r3, #0 */
/* @0xbe438 bne 0xbe4b4 <_ZN17CSkeletonInstance13SetImageIndexEif+0xcc> */
/* @0xbe43c ldr r3, [pc, #0xa0] */
/* @0xbe440 ldr r3, [pc, r3] */
/* @0xbe444 ldr r3, [r3] */
/* @0xbe448 cmp r3, #0 */
/* @0xbe44c beq 0xbe4d8 <_ZN17CSkeletonInstance13SetImageIndexEif+0xf0> */
/* @0xbe450 ldr r0, [r3, #0xc] */
/* @0xbe454 cmp r0, #0 */
/* @0xbe458 ble 0xbe4a8 <_ZN17CSkeletonInstance13SetImageIndexEif+0xc0> */
/* @0xbe45c ldr r3, [r5, #0x28] */
/* @0xbe460 vmov s14, r0 */
/* @0xbe464 vcvt.f32.s32 s16, s14 */
/* @0xbe468 ldr r3, [r3, #0x10] */
/* @0xbe46c ldr r1, [r3, r4, lsl #2] */
/* @0xbe470 ldr r3, [r1, #0xc] */
/* @0xbe474 vldr s15, [r3, #4] */
/* @0xbe478 vmul.f32 s15, s16, s15 */
/* @0xbe47c mov r0, r2 */
/* @0xbe480 vmov r1, s15 */
/* @0xbe484 bl 0x1e62fc <_Z5fwrapff> */
/* @0xbe488 ldr r2, [r5, #0x28] */
/* @0xbe48c mov r3, #1 */
/* @0xbe490 ldr r2, [r2, #0x10] */
/* @0xbe494 ldr r2, [r2, r4, lsl #2] */
/* @0xbe498 vmov s15, r0 */
/* @0xbe49c vdiv.f32 s16, s15, s16 */
/* @0xbe4a0 vstr s16, [r2, #24] */
/* @0xbe4a4 strb r3, [r5, #0x5] */
/* @0xbe4a8 add sp, sp, #12 */
/* @0xbe4ac vpop {d8} */
/* @0xbe4b0 pop {r4, r5, pc} */
/* @0xbe4b4 ldr r0, [pc, #0x2c] */
/* @0xbe4b8 str r2, [sp, #0x4] */
/* @0xbe4bc ldr r0, [pc, r0] */
/* @0xbe4c0 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0xbe4c4 ldr r2, [sp, #0x4] */
/* @0xbe4c8 vmov d7, r0, r1 */
/* @0xbe4cc vcvt.s32.f64 s15, d7 */
/* @0xbe4d0 vmov r0, s15 */
/* @0xbe4d4 b 0xbe454 <_ZN17CSkeletonInstance13SetImageIndexEif+0x6c> */
/* @0xbe4d8 vmov.f32 s16, #3.000000e+01 */
/* @0xbe4dc b 0xbe470 <_ZN17CSkeletonInstance13SetImageIndexEif+0x88> */
/* @0xbe4e0 ldrshteq pc, [r2], -r8 */
/* @0xbe4e4 eorseq pc, r2, r8, ror #9 */
/* @0xbe4e8 eorseq pc, r2, r0, ror r4 */

/* ── FUNC 0xbe4ec · CSkeletonInstance::SelectAnimationExt(char const*, int) · size=140 · insn=35 */
/* @0xbe4ec push {r4, r5, r6, lr} */
/* @0xbe4f0 mov r4, r0 */
/* @0xbe4f4 ldr r0, [r0, #0x30] */
/* @0xbe4f8 mov r5, r2 */
/* @0xbe4fc cmp r0, #0 */
/* @0xbe500 popeq {r4, r5, r6, pc} */
/* @0xbe504 rsbs r6, r2, #1 */
/* @0xbe508 movlo r6, #0 */
/* @0xbe50c cmp r1, #0 */
/* @0xbe510 cmpeq r2, #0 */
/* @0xbe514 bne 0xbe564 <_ZN17CSkeletonInstance18SelectAnimationExtEPKci+0x78> */
/* @0xbe518 ldr r3, [r0, #0x34] */
/* @0xbe51c cmp r3, #0 */
/* @0xbe520 pople {r4, r5, r6, pc} */
/* @0xbe524 ldr r3, [r0, #0x38] */
/* @0xbe528 ldr r3, [r3] */
/* @0xbe52c ldr r1, [r3] */
/* @0xbe530 bl 0x28b1dc <spSkeletonData_findAnimation> */
/* @0xbe534 mov r2, r0 */
/* @0xbe538 cmp r2, #0 */
/* @0xbe53c popeq {r4, r5, r6, pc} */
/* @0xbe540 cmp r6, #0 */
/* @0xbe544 ldr r0, [r4, #0x28] */
/* @0xbe548 strne r2, [r4, #0x24] */
/* @0xbe54c mov r1, r5 */
/* @0xbe550 movne r3, #0 */
/* @0xbe554 strne r3, [r4] */
/* @0xbe558 mov r3, #1 */
/* @0xbe55c pop {r4, r5, r6, lr} */
/* @0xbe560 b 0x283900 <spAnimationState_setAnimation> */
/* @0xbe564 bl 0x28b1dc <spSkeletonData_findAnimation> */
/* @0xbe568 mov r2, r0 */
/* @0xbe56c cmp r2, #0 */
/* @0xbe570 bne 0xbe540 <_ZN17CSkeletonInstance18SelectAnimationExtEPKci+0x54> */
/* @0xbe574 pop {r4, r5, r6, pc} */

/* ── FUNC 0xbe578 · CSkeletonInstance::SelectAnimation(char const*) · size=8 · insn=2 */
/* @0xbe578 mov r2, #0 */
/* @0xbe57c b 0xbe4ec <_ZN17CSkeletonInstance18SelectAnimationExtEPKci> */

/* ── FUNC 0xbe580 · CSkeletonInstance::SetAnimationMix(char const*, char const*, float) · size=16 · insn=4 */
/* @0xbe580 ldr r0, [r0, #0x2c] */
/* @0xbe584 cmp r0, #0 */
/* @0xbe588 bxeq lr */
/* @0xbe58c b 0x283c60 <spAnimationStateData_setMixByName> */

/* ── FUNC 0xbe590 · CSkeletonInstance::SelectSkin(char const*) · size=76 · insn=19 */
/* @0xbe590 cmp r1, #0 */
/* @0xbe594 push {r4, lr} */
/* @0xbe598 mov r4, r0 */
/* @0xbe59c beq 0xbe5b4 <_ZN17CSkeletonInstance10SelectSkinEPKc+0x24> */
/* @0xbe5a0 ldr r0, [r0, #0x1c] */
/* @0xbe5a4 bl 0x28a2dc <spSkeleton_setSkinByName> */
/* @0xbe5a8 ldr r0, [r4, #0x1c] */
/* @0xbe5ac pop {r4, lr} */
/* @0xbe5b0 b 0x28a064 <spSkeleton_setSlotsToSetupPose> */
/* @0xbe5b4 ldr r3, [r0, #0x30] */
/* @0xbe5b8 ldr r3, [r3, #0x28] */
/* @0xbe5bc cmp r3, #0 */
/* @0xbe5c0 beq 0xbe5a8 <_ZN17CSkeletonInstance10SelectSkinEPKc+0x18> */
/* @0xbe5c4 ldr r1, [r3] */
/* @0xbe5c8 ldr r0, [r0, #0x1c] */
/* @0xbe5cc bl 0x28a2dc <spSkeleton_setSkinByName> */
/* @0xbe5d0 ldr r0, [r4, #0x1c] */
/* @0xbe5d4 pop {r4, lr} */
/* @0xbe5d8 b 0x28a064 <spSkeleton_setSlotsToSetupPose> */

/* ── FUNC 0xbe5dc · CSkeletonInstance::SetupSkeletonData(spSkeletonData*) · size=160 · insn=40 */
/* @0xbe5dc push {r3, r4, r5, lr} */
/* @0xbe5e0 mov r4, r0 */
/* @0xbe5e4 str r1, [r4, #0x30] */
/* @0xbe5e8 mov r0, r1 */
/* @0xbe5ec mov r5, r1 */
/* @0xbe5f0 bl 0x289b40 <spSkeleton_create> */
/* @0xbe5f4 cmp r0, #0 */
/* @0xbe5f8 str r0, [r4, #0x1c] */
/* @0xbe5fc popeq {r3, r4, r5, pc} */
/* @0xbe600 ldr r3, [r0, #0xc] */
/* @0xbe604 ldr r0, [r0] */
/* @0xbe608 ldr r2, [r3, #0x20] */
/* @0xbe60c ldr r3, [r3, #0x24] */
/* @0xbe610 str r2, [r4, #0x8] */
/* @0xbe614 str r3, [r4, #0xc] */
/* @0xbe618 bl 0x283b2c <spAnimationStateData_create> */
/* @0xbe61c cmp r0, #0 */
/* @0xbe620 str r0, [r4, #0x2c] */
/* @0xbe624 popeq {r3, r4, r5, pc} */
/* @0xbe628 bl 0x283128 <spAnimationState_create> */
/* @0xbe62c cmp r0, #0 */
/* @0xbe630 str r0, [r4, #0x28] */
/* @0xbe634 popeq {r3, r4, r5, pc} */
/* @0xbe638 ldr r2, [r5, #0x34] */
/* @0xbe63c ldr r3, [pc, #0x34] */
/* @0xbe640 cmp r2, #0 */
/* @0xbe644 str r4, [r0, #0x14] */
/* @0xbe648 ldr r3, [pc, r3] */
/* @0xbe64c str r3, [r0, #0x8] */
/* @0xbe650 ble 0xbe660 <_ZN17CSkeletonInstance17SetupSkeletonDataEP14spSkeletonData+0x84> */
/* @0xbe654 mov r0, r4 */
/* @0xbe658 mov r1, #0 */
/* @0xbe65c bl 0xbe578 <_ZN17CSkeletonInstance15SelectAnimationEPKc> */
/* @0xbe660 mov r0, r4 */
/* @0xbe664 mov r1, #0 */
/* @0xbe668 bl 0xbe590 <_ZN17CSkeletonInstance10SelectSkinEPKc> */
/* @0xbe66c bl 0x28a834 <spSkeletonBounds_create> */
/* @0xbe670 str r0, [r4, #0x20] */
/* @0xbe674 pop {r3, r4, r5, pc} */
/* @0xbe678 eorseq pc, r2, r8, ror #5 */

/* ── FUNC 0xbe67c · CSkeletonInstance::CSkeletonInstance(CSkeletonSprite*) · size=80 · insn=20 */
/* @0xbe67c ldr r1, [r1, #0x4] */
/* @0xbe680 mov r3, #0 */
/* @0xbe684 push {r4, lr} */
/* @0xbe688 cmp r1, r3 */
/* @0xbe68c mov r4, r0 */
/* @0xbe690 str r3, [r0] */
/* @0xbe694 strb r3, [r0, #0x4] */
/* @0xbe698 strb r3, [r0, #0x5] */
/* @0xbe69c str r3, [r0, #0x10] */
/* @0xbe6a0 str r3, [r0, #0x14] */
/* @0xbe6a4 str r3, [r0, #0x18] */
/* @0xbe6a8 str r3, [r0, #0x1c] */
/* @0xbe6ac str r3, [r0, #0x20] */
/* @0xbe6b0 str r3, [r0, #0x28] */
/* @0xbe6b4 str r3, [r0, #0x2c] */
/* @0xbe6b8 str r3, [r0, #0x30] */
/* @0xbe6bc beq 0xbe6c4 <_ZN17CSkeletonInstanceC2EP15CSkeletonSprite+0x48> */
/* @0xbe6c0 bl 0xbe5dc <_ZN17CSkeletonInstance17SetupSkeletonDataEP14spSkeletonData> */
/* @0xbe6c4 mov r0, r4 */
/* @0xbe6c8 pop {r4, pc} */

/* ── FUNC 0xbe67c · CSkeletonInstance::CSkeletonInstance(CSkeletonSprite*) · alias of the symbol above · insn=0 */

/* ── FUNC 0xbe6cc · CSkeletonInstance::SetAttachment(char const*, char const*, bool) · size=292 · insn=73 */
/* @0xbe6cc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xbe6d0 mov r4, r0 */
/* @0xbe6d4 ldr r0, [r0, #0x1c] */
/* @0xbe6d8 mov r7, r2 */
/* @0xbe6dc mov r5, r3 */
/* @0xbe6e0 mov r6, r1 */
/* @0xbe6e4 bl 0x28a18c <spSkeleton_findSlot> */
/* @0xbe6e8 subs r9, r0, #0 */
/* @0xbe6ec popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xbe6f0 cmp r7, #0 */
/* @0xbe6f4 beq 0xbe7e4 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x118> */
/* @0xbe6f8 mov r1, r6 */
/* @0xbe6fc ldr r0, [r4, #0x1c] */
/* @0xbe700 bl 0x28a1f4 <spSkeleton_findSlotIndex> */
/* @0xbe704 cmp r5, #0 */
/* @0xbe708 mov r8, r0 */
/* @0xbe70c beq 0xbe764 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x98> */
/* @0xbe710 ldr r8, [r4, #0x10] */
/* @0xbe714 cmp r8, #0 */
/* @0xbe718 pople {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xbe71c ldr r5, [r4, #0x14] */
/* @0xbe720 mov r4, #0 */
/* @0xbe724 sub r5, r5, #4 */
/* @0xbe728 b 0xbe734 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x68> */
/* @0xbe72c cmp r4, r8 */
/* @0xbe730 beq 0xbe760 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x94> */
/* @0xbe734 ldr r6, [r5, #0x4]! */
/* @0xbe738 mov r1, r7 */
/* @0xbe73c add r4, r4, #1 */
/* @0xbe740 ldr r0, [r6] */
/* @0xbe744 bl 0xb6574 <strcmp@plt> */
/* @0xbe748 cmp r0, #0 */
/* @0xbe74c bne 0xbe72c <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x60> */
/* @0xbe750 mov r0, r9 */
/* @0xbe754 mov r1, r6 */
/* @0xbe758 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xbe75c b 0x28ee1c <spSlot_setAttachment> */
/* @0xbe760 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0xbe764 ldr r3, [r4, #0x1c] */
/* @0xbe768 mov r1, r0 */
/* @0xbe76c mov r2, r7 */
/* @0xbe770 ldr r6, [r3, #0x38] */
/* @0xbe774 mov r0, r6 */
/* @0xbe778 bl 0x28ed00 <spSkin_getAttachment> */
/* @0xbe77c subs r1, r0, #0 */
/* @0xbe780 beq 0xbe790 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0xc4> */
/* @0xbe784 mov r0, r9 */
/* @0xbe788 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xbe78c b 0x28ee1c <spSlot_setAttachment> */
/* @0xbe790 ldr r3, [r4, #0x30] */
/* @0xbe794 ldr r2, [r3, #0x20] */
/* @0xbe798 cmp r2, #0 */
/* @0xbe79c movgt r5, r1 */
/* @0xbe7a0 bgt 0xbe7bc <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0xf0> */
/* @0xbe7a4 b 0xbe710 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x44> */
/* @0xbe7a8 ldr r3, [r4, #0x30] */
/* @0xbe7ac ldr r2, [r3, #0x20] */
/* @0xbe7b0 add r5, r5, #1 */
/* @0xbe7b4 cmp r2, r5 */
/* @0xbe7b8 ble 0xbe710 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0x44> */
/* @0xbe7bc ldr r12, [r3, #0x24] */
/* @0xbe7c0 mov r1, r8 */
/* @0xbe7c4 mov r2, r7 */
/* @0xbe7c8 ldr r0, [r12, r5, lsl #2] */
/* @0xbe7cc cmp r0, r6 */
/* @0xbe7d0 beq 0xbe7ac <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0xe0> */
/* @0xbe7d4 bl 0x28ed00 <spSkin_getAttachment> */
/* @0xbe7d8 subs r1, r0, #0 */
/* @0xbe7dc beq 0xbe7a8 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0xdc> */
/* @0xbe7e0 b 0xbe784 <_ZN17CSkeletonInstance13SetAttachmentEPKcS1_b+0xb8> */
/* @0xbe7e4 mov r1, r7 */
/* @0xbe7e8 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0xbe7ec b 0x28ee1c <spSlot_setAttachment> */
