/* libyoyo.so 覆盖卡组 0040
 * 函数 0x111070..0x1143ac，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x111070 · YYGML_degtorad(double) · size=48 · insn=12 */
/* @0x111070 vmov d5, r0, r1 */
/* @0x111074 vldr d6, [pc, #20] */
/* @0x111078 vldr d7, [pc, #24] */
/* @0x11107c vmul.f64 d6, d5, d6 */
/* @0x111080 vdiv.f64 d5, d6, d7 */
/* @0x111084 vmov r0, r1, d5 */
/* @0x111088 bx lr */
/* @0x11108c nop */
/* @0x111090 andvs r0, r0, r0 */
/* @0x111094 strdmi r2, r3, [r9], -r11 */
/* @0x111098 andeq r0, r0, r0 */
/* @0x11109c rsbmi r8, r6, r0 */

/* ── FUNC 0x1110a0 · UTF8ToASCII(char const*) · size=144 · insn=36 */
/* @0x1110a0 push {r4, r5, r6, r7, lr} */
/* @0x1110a4 subs r5, r0, #0 */
/* @0x1110a8 sub sp, sp, #12 */
/* @0x1110ac beq 0x111124 <_Z11UTF8ToASCIIPKc+0x84> */
/* @0x1110b0 ldrb r7, [r5] */
/* @0x1110b4 cmp r7, #0 */
/* @0x1110b8 moveq r0, r7 */
/* @0x1110bc beq 0x11111c <_Z11UTF8ToASCIIPKc+0x7c> */
/* @0x1110c0 bl 0x110648 <utf8_strlen> */
/* @0x1110c4 ldr r1, [pc, #0x60] */
/* @0x1110c8 mov r3, #1 */
/* @0x1110cc mov r2, #1536 */
/* @0x1110d0 add r1, pc, r1 */
/* @0x1110d4 add r4, sp, #8 */
/* @0x1110d8 add r0, r0, r3 */
/* @0x1110dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1110e0 str r5, [r4, #-0x4]! */
/* @0x1110e4 mov r3, r5 */
/* @0x1110e8 mov r7, r0 */
/* @0x1110ec mov r6, r0 */
/* @0x1110f0 b 0x111104 <_Z11UTF8ToASCIIPKc+0x64> */
/* @0x1110f4 bl 0x10fb38 <utf8_extract_char> */
/* @0x1110f8 cmp r0, #127 */
/* @0x1110fc strbls r0, [r6], #1 */
/* @0x111100 ldr r3, [sp, #0x4] */
/* @0x111104 ldrb r3, [r3] */
/* @0x111108 mov r0, r4 */
/* @0x11110c cmp r3, #0 */
/* @0x111110 bne 0x1110f4 <_Z11UTF8ToASCIIPKc+0x54> */
/* @0x111114 mov r0, r7 */
/* @0x111118 strb r3, [r6] */
/* @0x11111c add sp, sp, #12 */
/* @0x111120 pop {r4, r5, r6, r7, pc} */
/* @0x111124 mov r0, r5 */
/* @0x111128 b 0x11111c <_Z11UTF8ToASCIIPKc+0x7c> */
/* @0x11112c eoreq r7, r2, r4, ror sp */

/* ── FUNC 0x111130 · YYGML_string(RValue const&) · size=136 · insn=34 */
/* @0x111130 ldr r1, [pc, #0x78] */
/* @0x111134 mov r12, #256 */
/* @0x111138 push {r4, lr} */
/* @0x11113c sub sp, sp, #24 */
/* @0x111140 mov r4, r0 */
/* @0x111144 add r1, pc, r1 */
/* @0x111148 mov r0, r12 */
/* @0x11114c movw r2, #0x63b */
/* @0x111150 mov r3, #1 */
/* @0x111154 str r12, [sp, #0xc] */
/* @0x111158 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x11115c mov r3, r4 */
/* @0x111160 add r1, sp, #16 */
/* @0x111164 mov r4, #0 */
/* @0x111168 mov r2, r0 */
/* @0x11116c str r0, [sp, #0x10] */
/* @0x111170 add r0, sp, #24 */
/* @0x111174 str r2, [r0, #-0x4]! */
/* @0x111178 strb r4, [r2] */
/* @0x11117c add r2, sp, #12 */
/* @0x111180 bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x111184 ldr r0, [sp, #0x10] */
/* @0x111188 ldr r1, [sp, #0x14] */
/* @0x11118c mov r3, #74 */
/* @0x111190 ldr r2, [pc, #0x1c] */
/* @0x111194 rsb r1, r0, r1 */
/* @0x111198 str r4, [sp] */
/* @0x11119c add r1, r1, #1 */
/* @0x1111a0 add r2, pc, r2 */
/* @0x1111a4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1111a8 add sp, sp, #24 */
/* @0x1111ac pop {r4, pc} */
/* @0x1111b0 eoreq r7, r2, r0, lsl #26 */
/* @0x1111b4 mlaeq r1, r0, lr, pc */

/* ── FUNC 0x1111b8 · YYGML_ord(char const*) · size=40 · insn=10 */
/* @0x1111b8 str lr, [sp, #-0x4]! */
/* @0x1111bc subs r3, r0, #0 */
/* @0x1111c0 sub sp, sp, #12 */
/* @0x1111c4 str r0, [sp, #0x4] */
/* @0x1111c8 moveq r0, r3 */
/* @0x1111cc beq 0x1111d8 <_Z9YYGML_ordPKc+0x20> */
/* @0x1111d0 add r0, sp, #4 */
/* @0x1111d4 bl 0x10fb38 <utf8_extract_char> */
/* @0x1111d8 add sp, sp, #12 */
/* @0x1111dc ldr pc, [sp], #4 */

/* ── FUNC 0x1111e0 · StringPos(char const*, char const*) · size=180 · insn=45 */
/* @0x1111e0 cmp r0, #0 */
/* @0x1111e4 cmpne r1, #0 */
/* @0x1111e8 push {r4, r5, r6, r7, lr} */
/* @0x1111ec movne r4, #0 */
/* @0x1111f0 moveq r4, #1 */
/* @0x1111f4 sub sp, sp, #12 */
/* @0x1111f8 mov r5, r0 */
/* @0x1111fc beq 0x111234 <_Z9StringPosPKcS0_+0x54> */
/* @0x111200 ldrb r2, [r1] */
/* @0x111204 cmp r2, #0 */
/* @0x111208 beq 0x111234 <_Z9StringPosPKcS0_+0x54> */
/* @0x11120c ldrb r2, [r0] */
/* @0x111210 cmp r2, #0 */
/* @0x111214 beq 0x111234 <_Z9StringPosPKcS0_+0x54> */
/* @0x111218 str r1, [sp, #0x4] */
/* @0x11121c bl 0x110648 <utf8_strlen> */
/* @0x111220 mov r6, r0 */
/* @0x111224 ldr r0, [sp, #0x4] */
/* @0x111228 ldrb r2, [r0] */
/* @0x11122c cmp r2, #0 */
/* @0x111230 bne 0x111240 <_Z9StringPosPKcS0_+0x60> */
/* @0x111234 mvn r0, #0 */
/* @0x111238 add sp, sp, #12 */
/* @0x11123c pop {r4, r5, r6, r7, pc} */
/* @0x111240 add r7, sp, #4 */
/* @0x111244 mov r1, r5 */
/* @0x111248 mov r2, r6 */
/* @0x11124c bl 0x110b34 <utf8_strncmp> */
/* @0x111250 cmp r0, #0 */
/* @0x111254 mov r0, r7 */
/* @0x111258 beq 0x111278 <_Z9StringPosPKcS0_+0x98> */
/* @0x11125c bl 0x10fb38 <utf8_extract_char> */
/* @0x111260 ldr r0, [sp, #0x4] */
/* @0x111264 add r4, r4, #1 */
/* @0x111268 ldrb r2, [r0] */
/* @0x11126c cmp r2, #0 */
/* @0x111270 beq 0x111234 <_Z9StringPosPKcS0_+0x54> */
/* @0x111274 b 0x111244 <_Z9StringPosPKcS0_+0x64> */
/* @0x111278 ldr r3, [sp, #0x4] */
/* @0x11127c ldrb r3, [r3] */
/* @0x111280 cmp r3, #0 */
/* @0x111284 movne r0, r4 */
/* @0x111288 beq 0x111234 <_Z9StringPosPKcS0_+0x54> */
/* @0x11128c add sp, sp, #12 */
/* @0x111290 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x111294 · F_StringPos(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x111294 push {r4, r5, r6, lr} */
/* @0x111298 mov r1, #0 */
/* @0x11129c ldr r5, [sp, #0x10] */
/* @0x1112a0 mov r4, r0 */
/* @0x1112a4 mov r0, r5 */
/* @0x1112a8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1112ac mov r1, #1 */
/* @0x1112b0 mov r6, r0 */
/* @0x1112b4 mov r0, r5 */
/* @0x1112b8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1112bc mov r3, #0 */
/* @0x1112c0 str r3, [r4, #0xc] */
/* @0x1112c4 cmp r6, r3 */
/* @0x1112c8 cmpne r0, r3 */
/* @0x1112cc mov r1, r0 */
/* @0x1112d0 streq r3, [r4] */
/* @0x1112d4 streq r3, [r4, #0x4] */
/* @0x1112d8 popeq {r4, r5, r6, pc} */
/* @0x1112dc mov r0, r6 */
/* @0x1112e0 bl 0x1111e0 <_Z9StringPosPKcS0_> */
/* @0x1112e4 add r0, r0, #1 */
/* @0x1112e8 vmov s15, r0 */
/* @0x1112ec vcvt.f64.s32 d7, s15 */
/* @0x1112f0 vmov r2, r3, d7 */
/* @0x1112f4 stm r4, {r2, r3} */
/* @0x1112f8 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1112fc · YYGML_StringByteAt(char const*, int) · size=48 · insn=12 */
/* @0x1112fc push {r3, r4, r5, lr} */
/* @0x111300 sub r5, r1, #1 */
/* @0x111304 mov r4, r0 */
/* @0x111308 bl 0xb6538 <strlen@plt> */
/* @0x11130c bic r1, r5, r5, asr #31 */
/* @0x111310 cmp r0, r1 */
/* @0x111314 suble r1, r0, #1 */
/* @0x111318 ldrb r0, [r4, r1] */
/* @0x11131c vmov s15, r0 */
/* @0x111320 vcvt.f64.u32 d7, s15 */
/* @0x111324 vmov r0, r1, d7 */
/* @0x111328 pop {r3, r4, r5, pc} */

/* ── FUNC 0x11132c · F_StringByteAt(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x11132c push {r4, r5, r6, lr} */
/* @0x111330 mov r1, #0 */
/* @0x111334 ldr r5, [sp, #0x10] */
/* @0x111338 mov r4, r0 */
/* @0x11133c mov r0, r5 */
/* @0x111340 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x111344 mov r1, #1 */
/* @0x111348 mov r6, r0 */
/* @0x11134c mov r0, r5 */
/* @0x111350 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x111354 mov r3, #0 */
/* @0x111358 str r3, [r4, #0xc] */
/* @0x11135c str r3, [r4] */
/* @0x111360 str r3, [r4, #0x4] */
/* @0x111364 mov r1, r0 */
/* @0x111368 mov r0, r6 */
/* @0x11136c bl 0x1112fc <_Z18YYGML_StringByteAtPKci> */
/* @0x111370 stm r4, {r0, r1} */
/* @0x111374 pop {r4, r5, r6, pc} */

/* ── FUNC 0x111378 · Delete(char const*&, int, int) · size=208 · insn=52 */
/* @0x111378 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x11137c mov r6, r0 */
/* @0x111380 ldr r0, [r0] */
/* @0x111384 sub sp, sp, #12 */
/* @0x111388 mov r9, r2 */
/* @0x11138c cmp r0, #0 */
/* @0x111390 beq 0x111438 <_Z6DeleteRPKcii+0xc0> */
/* @0x111394 cmp r2, #0 */
/* @0x111398 ble 0x111438 <_Z6DeleteRPKcii+0xc0> */
/* @0x11139c sub r7, r1, #1 */
/* @0x1113a0 bl 0x110648 <utf8_strlen> */
/* @0x1113a4 lsr r5, r7, #31 */
/* @0x1113a8 cmp r0, r7 */
/* @0x1113ac orrle r5, r5, #1 */
/* @0x1113b0 mov r8, r0 */
/* @0x1113b4 cmp r5, #0 */
/* @0x1113b8 bne 0x111438 <_Z6DeleteRPKcii+0xc0> */
/* @0x1113bc rsb r4, r7, r0 */
/* @0x1113c0 ldr r3, [r6] */
/* @0x1113c4 cmp r4, r9 */
/* @0x1113c8 addle r4, r7, r4 */
/* @0x1113cc addgt r4, r7, r9 */
/* @0x1113d0 cmp r4, #0 */
/* @0x1113d4 str r3, [sp] */
/* @0x1113d8 str r3, [sp, #0x4] */
/* @0x1113dc ble 0x111440 <_Z6DeleteRPKcii+0xc8> */
/* @0x1113e0 cmp r5, r7 */
/* @0x1113e4 mov r0, sp */
/* @0x1113e8 add r5, r5, #1 */
/* @0x1113ec ldreq r3, [sp] */
/* @0x1113f0 streq r3, [sp, #0x4] */
/* @0x1113f4 bl 0x10fb38 <utf8_extract_char> */
/* @0x1113f8 cmp r5, r4 */
/* @0x1113fc bne 0x1113e0 <_Z6DeleteRPKcii+0x68> */
/* @0x111400 cmp r8, r4 */
/* @0x111404 ble 0x11142c <_Z6DeleteRPKcii+0xb4> */
/* @0x111408 add r5, sp, #4 */
/* @0x11140c mov r0, sp */
/* @0x111410 add r4, r4, #1 */
/* @0x111414 bl 0x10fb38 <utf8_extract_char> */
/* @0x111418 mov r1, r0 */
/* @0x11141c mov r0, r5 */
/* @0x111420 bl 0x10fe28 <utf8_add_char> */
/* @0x111424 cmp r4, r8 */
/* @0x111428 bne 0x11140c <_Z6DeleteRPKcii+0x94> */
/* @0x11142c ldr r3, [sp, #0x4] */
/* @0x111430 mov r2, #0 */
/* @0x111434 strb r2, [r3] */
/* @0x111438 add sp, sp, #12 */
/* @0x11143c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x111440 mov r4, r5 */
/* @0x111444 b 0x111408 <_Z6DeleteRPKcii+0x90> */

/* ── FUNC 0x111448 · F_StringDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x111448 push {r4, r5, r6, r7, lr} */
/* @0x11144c sub sp, sp, #12 */
/* @0x111450 mov r5, r0 */
/* @0x111454 mov r1, #0 */
/* @0x111458 ldr r4, [sp, #0x20] */
/* @0x11145c mov r0, r4 */
/* @0x111460 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x111464 mov r1, #1 */
/* @0x111468 mov r7, r0 */
/* @0x11146c mov r0, r4 */
/* @0x111470 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x111474 mov r1, #2 */
/* @0x111478 mov r6, r0 */
/* @0x11147c mov r0, r4 */
/* @0x111480 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x111484 mov r4, r0 */
/* @0x111488 mov r0, r7 */
/* @0x11148c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x111490 add r3, sp, #8 */
/* @0x111494 mov r2, r4 */
/* @0x111498 mov r1, r6 */
/* @0x11149c str r0, [r3, #-0x4]! */
/* @0x1114a0 mov r0, r3 */
/* @0x1114a4 bl 0x111378 <_Z6DeleteRPKcii> */
/* @0x1114a8 mov r0, r5 */
/* @0x1114ac ldr r1, [sp, #0x4] */
/* @0x1114b0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1114b4 ldr r0, [sp, #0x4] */
/* @0x1114b8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1114bc add sp, sp, #12 */
/* @0x1114c0 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x1114c4 · String_Copy(char const*&, char const*, int, int) · size=288 · insn=72 */
/* @0x1114c4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1114c8 mov r8, r1 */
/* @0x1114cc sub sp, sp, #12 */
/* @0x1114d0 mov r5, r0 */
/* @0x1114d4 ldr r0, [r0] */
/* @0x1114d8 mov r6, r2 */
/* @0x1114dc mov r7, r3 */
/* @0x1114e0 mov r4, #0 */
/* @0x1114e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1114e8 str r4, [r5] */
/* @0x1114ec mov r0, r8 */
/* @0x1114f0 bl 0x110648 <utf8_strlen> */
/* @0x1114f4 cmp r0, r6 */
/* @0x1114f8 mov r9, r0 */
/* @0x1114fc blt 0x1115a0 <_Z11String_CopyRPKcS0_ii+0xdc> */
/* @0x111500 rsb r3, r6, r0 */
/* @0x111504 mov r0, r8 */
/* @0x111508 cmp r7, r3 */
/* @0x11150c movge r7, r3 */
/* @0x111510 bl 0xb6538 <strlen@plt> */
/* @0x111514 ldr r1, [pc, #0xc0] */
/* @0x111518 mov r3, #1 */
/* @0x11151c movw r2, #0x899 */
/* @0x111520 add r1, pc, r1 */
/* @0x111524 add r0, r0, r3 */
/* @0x111528 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x11152c cmp r9, r6 */
/* @0x111530 str r8, [sp] */
/* @0x111534 str r0, [r5] */
/* @0x111538 str r0, [sp, #0x4] */
/* @0x11153c ble 0x1115d4 <_Z11String_CopyRPKcS0_ii+0x110> */
/* @0x111540 cmp r6, #0 */
/* @0x111544 ble 0x11155c <_Z11String_CopyRPKcS0_ii+0x98> */
/* @0x111548 add r4, r4, #1 */
/* @0x11154c mov r0, sp */
/* @0x111550 bl 0x10fb38 <utf8_extract_char> */
/* @0x111554 cmp r4, r6 */
/* @0x111558 bne 0x111548 <_Z11String_CopyRPKcS0_ii+0x84> */
/* @0x11155c cmp r7, #0 */
/* @0x111560 addgt r6, sp, #4 */
/* @0x111564 movgt r4, #0 */
/* @0x111568 ble 0x1115d4 <_Z11String_CopyRPKcS0_ii+0x110> */
/* @0x11156c mov r0, sp */
/* @0x111570 add r4, r4, #1 */
/* @0x111574 bl 0x10fb38 <utf8_extract_char> */
/* @0x111578 mov r1, r0 */
/* @0x11157c mov r0, r6 */
/* @0x111580 bl 0x10fe28 <utf8_add_char> */
/* @0x111584 cmp r4, r7 */
/* @0x111588 bne 0x11156c <_Z11String_CopyRPKcS0_ii+0xa8> */
/* @0x11158c mov r0, r6 */
/* @0x111590 mov r1, #0 */
/* @0x111594 bl 0x10fe28 <utf8_add_char> */
/* @0x111598 add sp, sp, #12 */
/* @0x11159c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1115a0 mov r0, r8 */
/* @0x1115a4 add r6, sp, #8 */
/* @0x1115a8 bl 0xb6538 <strlen@plt> */
/* @0x1115ac ldr r1, [pc, #0x2c] */
/* @0x1115b0 mov r3, #1 */
/* @0x1115b4 movw r2, #0x899 */
/* @0x1115b8 add r1, pc, r1 */
/* @0x1115bc add r0, r0, r3 */
/* @0x1115c0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1115c4 str r8, [sp] */
/* @0x1115c8 str r0, [r5] */
/* @0x1115cc str r0, [r6, #-0x4]! */
/* @0x1115d0 b 0x11158c <_Z11String_CopyRPKcS0_ii+0xc8> */
/* @0x1115d4 add r6, sp, #4 */
/* @0x1115d8 b 0x11158c <_Z11String_CopyRPKcS0_ii+0xc8> */
/* @0x1115dc eoreq r7, r2, r4, lsr #18 */
/* @0x1115e0 eoreq r7, r2, r12, lsl #17 */

/* ── FUNC 0x1115e4 · String_Add(char const*&, char const*) · size=192 · insn=48 */
/* @0x1115e4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1115e8 mov r4, r0 */
/* @0x1115ec ldr r5, [r0] */
/* @0x1115f0 mov r8, r1 */
/* @0x1115f4 cmp r5, #0 */
/* @0x1115f8 beq 0x11166c <_Z10String_AddRPKcS0_+0x88> */
/* @0x1115fc mov r0, r5 */
/* @0x111600 bl 0xb6538 <strlen@plt> */
/* @0x111604 mov r5, r0 */
/* @0x111608 mov r0, r8 */
/* @0x11160c bl 0xb6538 <strlen@plt> */
/* @0x111610 ldr r1, [pc, #0x84] */
/* @0x111614 movw r2, #0x8b4 */
/* @0x111618 mov r3, #1 */
/* @0x11161c add r1, pc, r1 */
/* @0x111620 mov r7, r0 */
/* @0x111624 add r0, r5, r0 */
/* @0x111628 add r0, r0, #1 */
/* @0x11162c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x111630 cmp r5, #0 */
/* @0x111634 mov r6, r0 */
/* @0x111638 ble 0x111648 <_Z10String_AddRPKcS0_+0x64> */
/* @0x11163c ldr r1, [r4] */
/* @0x111640 mov r2, r5 */
/* @0x111644 bl 0xb65bc <memcpy@plt> */
/* @0x111648 mov r0, r5 */
/* @0x11164c mov r1, r8 */
/* @0x111650 mov r2, r7 */
/* @0x111654 add r0, r6, r0 */
/* @0x111658 bl 0xb65bc <memcpy@plt> */
/* @0x11165c ldr r0, [r4] */
/* @0x111660 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x111664 str r6, [r4] */
/* @0x111668 pop {r4, r5, r6, r7, r8, pc} */
/* @0x11166c mov r0, r1 */
/* @0x111670 bl 0xb6538 <strlen@plt> */
/* @0x111674 ldr r1, [pc, #0x24] */
/* @0x111678 movw r2, #0x8b4 */
/* @0x11167c mov r3, #1 */
/* @0x111680 add r1, pc, r1 */
/* @0x111684 mov r7, r0 */
/* @0x111688 add r0, r0, #1 */
/* @0x11168c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x111690 mov r6, r0 */
/* @0x111694 mov r0, r5 */
/* @0x111698 b 0x11164c <_Z10String_AddRPKcS0_+0x68> */
/* @0x11169c eoreq r7, r2, r8, lsr #16 */
/* @0x1116a0 eoreq r7, r2, r4, asr #15 */

/* ── FUNC 0x1116a4 · StringReplace(char const*&, char const*, char const*, char const*, bool) · size=516 · insn=129 */
/* @0x1116a4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1116a8 sub sp, sp, #28 */
/* @0x1116ac cmp r1, #0 */
/* @0x1116b0 mov r9, r0 */
/* @0x1116b4 str r3, [sp, #0x4] */
/* @0x1116b8 mov r11, r2 */
/* @0x1116bc ldrb r3, [sp, #0x40] */
/* @0x1116c0 str r1, [sp, #0xc] */
/* @0x1116c4 str r3, [sp, #0x8] */
/* @0x1116c8 beq 0x111874 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1d0> */
/* @0x1116cc mov r0, r1 */
/* @0x1116d0 mov r7, #0 */
/* @0x1116d4 str r7, [sp, #0x14] */
/* @0x1116d8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1116dc mov r4, r0 */
/* @0x1116e0 mov r0, r11 */
/* @0x1116e4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1116e8 mov r10, r0 */
/* @0x1116ec ldr r0, [sp, #0xc] */
/* @0x1116f0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1116f4 cmp r4, r7 */
/* @0x1116f8 mov r6, r0 */
/* @0x1116fc beq 0x111888 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1e4> */
/* @0x111700 ldrb r3, [r4] */
/* @0x111704 cmp r3, #0 */
/* @0x111708 beq 0x111888 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1e4> */
/* @0x11170c add r8, sp, #20 */
/* @0x111710 b 0x111798 <_Z13StringReplaceRPKcS0_S0_S0_b+0xf4> */
/* @0x111714 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x111718 ldr r0, [sp, #0x14] */
/* @0x11171c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x111720 mov r6, r0 */
/* @0x111724 ldr r0, [sp, #0x14] */
/* @0x111728 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x11172c ldr r3, [sp, #0x8] */
/* @0x111730 mov r0, r10 */
/* @0x111734 str r7, [sp, #0x14] */
/* @0x111738 cmp r3, #0 */
/* @0x11173c beq 0x11187c <_Z13StringReplaceRPKcS0_S0_S0_b+0x1d8> */
/* @0x111740 bl 0x110648 <utf8_strlen> */
/* @0x111744 mvn r3, #-2147483648 */
/* @0x111748 mov r1, r4 */
/* @0x11174c add r2, r5, r0 */
/* @0x111750 mov r0, r8 */
/* @0x111754 bl 0x1114c4 <_Z11String_CopyRPKcS0_ii> */
/* @0x111758 ldr r5, [sp, #0x14] */
/* @0x11175c mov r0, r4 */
/* @0x111760 cmp r5, #0 */
/* @0x111764 beq 0x11182c <_Z13StringReplaceRPKcS0_S0_S0_b+0x188> */
/* @0x111768 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x11176c ldr r0, [sp, #0x14] */
/* @0x111770 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x111774 mov r4, r0 */
/* @0x111778 ldr r0, [sp, #0x14] */
/* @0x11177c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x111780 cmp r4, #0 */
/* @0x111784 str r7, [sp, #0x14] */
/* @0x111788 beq 0x1118a0 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1fc> */
/* @0x11178c ldrb r0, [r4] */
/* @0x111790 cmp r0, #0 */
/* @0x111794 beq 0x111844 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1a0> */
/* @0x111798 mov r0, r10 */
/* @0x11179c mov r1, r4 */
/* @0x1117a0 bl 0x1111e0 <_Z9StringPosPKcS0_> */
/* @0x1117a4 cmn r0, #1 */
/* @0x1117a8 mov r5, r0 */
/* @0x1117ac beq 0x11187c <_Z13StringReplaceRPKcS0_S0_S0_b+0x1d8> */
/* @0x1117b0 ldr r0, [sp, #0x14] */
/* @0x1117b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1117b8 mov r2, #0 */
/* @0x1117bc mov r3, r5 */
/* @0x1117c0 mov r0, r8 */
/* @0x1117c4 mov r1, r6 */
/* @0x1117c8 str r7, [sp, #0x14] */
/* @0x1117cc bl 0x1114c4 <_Z11String_CopyRPKcS0_ii> */
/* @0x1117d0 mov r0, r9 */
/* @0x1117d4 ldr r1, [sp, #0x14] */
/* @0x1117d8 bl 0x1115e4 <_Z10String_AddRPKcS0_> */
/* @0x1117dc ldr r1, [sp, #0x4] */
/* @0x1117e0 mov r0, r9 */
/* @0x1117e4 bl 0x1115e4 <_Z10String_AddRPKcS0_> */
/* @0x1117e8 ldr r0, [sp, #0x14] */
/* @0x1117ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1117f0 mov r0, r11 */
/* @0x1117f4 str r7, [sp, #0x14] */
/* @0x1117f8 bl 0x110648 <utf8_strlen> */
/* @0x1117fc mvn r3, #-2147483648 */
/* @0x111800 mov r1, r6 */
/* @0x111804 add r2, r5, r0 */
/* @0x111808 mov r0, r8 */
/* @0x11180c bl 0x1114c4 <_Z11String_CopyRPKcS0_ii> */
/* @0x111810 ldr r3, [sp, #0x14] */
/* @0x111814 mov r0, r6 */
/* @0x111818 cmp r3, #0 */
/* @0x11181c bne 0x111714 <_Z13StringReplaceRPKcS0_S0_S0_b+0x70> */
/* @0x111820 mov r6, r3 */
/* @0x111824 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x111828 b 0x111724 <_Z13StringReplaceRPKcS0_S0_S0_b+0x80> */
/* @0x11182c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x111830 ldr r0, [sp, #0x14] */
/* @0x111834 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x111838 mov r4, r5 */
/* @0x11183c mov r0, r5 */
/* @0x111840 str r5, [sp, #0x14] */
/* @0x111844 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x111848 mov r0, r4 */
/* @0x11184c mov r3, #0 */
/* @0x111850 str r3, [sp, #0x14] */
/* @0x111854 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x111858 mov r0, r10 */
/* @0x11185c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x111860 mov r0, r6 */
/* @0x111864 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x111868 ldr r3, [r9] */
/* @0x11186c cmp r3, #0 */
/* @0x111870 beq 0x111890 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1ec> */
/* @0x111874 add sp, sp, #28 */
/* @0x111878 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x11187c mov r0, r9 */
/* @0x111880 mov r1, r6 */
/* @0x111884 bl 0x1115e4 <_Z10String_AddRPKcS0_> */
/* @0x111888 ldr r0, [sp, #0x14] */
/* @0x11188c b 0x111844 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1a0> */
/* @0x111890 mov r0, r9 */
/* @0x111894 ldr r1, [sp, #0xc] */
/* @0x111898 bl 0x1115e4 <_Z10String_AddRPKcS0_> */
/* @0x11189c b 0x111874 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1d0> */
/* @0x1118a0 mov r0, r4 */
/* @0x1118a4 b 0x111844 <_Z13StringReplaceRPKcS0_S0_S0_b+0x1a0> */

/* ── FUNC 0x1118a8 · F_StringReplace(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x1118a8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1118ac sub sp, sp, #20 */
/* @0x1118b0 mov r6, #0 */
/* @0x1118b4 add r5, sp, #16 */
/* @0x1118b8 ldr r4, [sp, #0x30] */
/* @0x1118bc mov r7, r0 */
/* @0x1118c0 mov r1, r6 */
/* @0x1118c4 str r6, [r5, #-0x4]! */
/* @0x1118c8 mov r0, r4 */
/* @0x1118cc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1118d0 mov r1, #1 */
/* @0x1118d4 mov r9, r0 */
/* @0x1118d8 mov r0, r4 */
/* @0x1118dc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1118e0 mov r1, #2 */
/* @0x1118e4 mov r8, r0 */
/* @0x1118e8 mov r0, r4 */
/* @0x1118ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1118f0 mov r2, r8 */
/* @0x1118f4 mov r1, r9 */
/* @0x1118f8 str r6, [sp] */
/* @0x1118fc mov r3, r0 */
/* @0x111900 mov r0, r5 */
/* @0x111904 bl 0x1116a4 <_Z13StringReplaceRPKcS0_S0_S0_b> */
/* @0x111908 mov r0, r7 */
/* @0x11190c ldr r1, [sp, #0xc] */
/* @0x111910 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x111914 ldr r0, [sp, #0xc] */
/* @0x111918 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x11191c add sp, sp, #20 */
/* @0x111920 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x111924 · F_StringReplaceAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x111924 push {r4, r5, r6, r7, r8, lr} */
/* @0x111928 sub sp, sp, #16 */
/* @0x11192c mov r3, #0 */
/* @0x111930 add r5, sp, #16 */
/* @0x111934 ldr r4, [sp, #0x28] */
/* @0x111938 mov r1, r3 */
/* @0x11193c mov r6, r0 */
/* @0x111940 str r3, [r5, #-0x4]! */
/* @0x111944 mov r0, r4 */
/* @0x111948 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11194c mov r1, #1 */
/* @0x111950 mov r8, r0 */
/* @0x111954 mov r0, r4 */
/* @0x111958 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11195c mov r1, #2 */
/* @0x111960 mov r7, r0 */
/* @0x111964 mov r0, r4 */
/* @0x111968 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x11196c mov r12, #1 */
/* @0x111970 mov r2, r7 */
/* @0x111974 str r12, [sp] */
/* @0x111978 mov r1, r8 */
/* @0x11197c mov r3, r0 */
/* @0x111980 mov r0, r5 */
/* @0x111984 bl 0x1116a4 <_Z13StringReplaceRPKcS0_S0_S0_b> */
/* @0x111988 mov r0, r6 */
/* @0x11198c ldr r1, [sp, #0xc] */
/* @0x111990 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x111994 ldr r0, [sp, #0xc] */
/* @0x111998 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x11199c add sp, sp, #16 */
/* @0x1119a0 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x1119a4 · YYGML_point_direction(float, float, float, float) · size=172 · insn=43 */
/* @0x1119a4 vmov s12, r2 */
/* @0x1119a8 vmov s13, r0 */
/* @0x1119ac push {r3, lr} */
/* @0x1119b0 vsub.f32 s15, s12, s13 */
/* @0x1119b4 vmov s12, r3 */
/* @0x1119b8 vmov s13, r1 */
/* @0x1119bc vcmp.f32 s15, #0 */
/* @0x1119c0 vsub.f32 s14, s12, s13 */
/* @0x1119c4 vmrs APSR_nzcv, fpscr */
/* @0x1119c8 bne 0x1119f4 <_Z21YYGML_point_directionffff+0x50> */
/* @0x1119cc vcmpe.f32 s14, #0 */
/* @0x1119d0 vmrs APSR_nzcv, fpscr */
/* @0x1119d4 ble 0x1119e4 <_Z21YYGML_point_directionffff+0x40> */
/* @0x1119d8 vldr s15, [pc, #88] */
/* @0x1119dc vmov r0, s15 */
/* @0x1119e0 pop {r3, pc} */
/* @0x1119e4 bmi 0x111a30 <_Z21YYGML_point_directionffff+0x8c> */
/* @0x1119e8 vldr s15, [pc, #76] */
/* @0x1119ec vmov r0, s15 */
/* @0x1119f0 pop {r3, pc} */
/* @0x1119f4 vmov r1, s15 */
/* @0x1119f8 vmov r0, s14 */
/* @0x1119fc bl 0xb6778 <atan2f@plt> */
/* @0x111a00 vldr s15, [pc, #56] */
/* @0x111a04 vldr s14, [pc, #56] */
/* @0x111a08 vmov s12, r0 */
/* @0x111a0c vmul.f32 s15, s12, s15 */
/* @0x111a10 vdiv.f32 s15, s15, s14 */
/* @0x111a14 vcmpe.f32 s15, #0 */
/* @0x111a18 vmrs APSR_nzcv, fpscr */
/* @0x111a1c vldrhi s14, [pc, #36] */
/* @0x111a20 vsubhi.f32 s15, s14, s15 */
/* @0x111a24 vnegls.f32 s15, s15 */
/* @0x111a28 vmov r0, s15 */
/* @0x111a2c pop {r3, pc} */
/* @0x111a30 vldr s15, [pc, #20] */
/* @0x111a34 b 0x1119dc <_Z21YYGML_point_directionffff+0x38> */
/* @0x111a38 orrmi r0, r7, #0 */
/* @0x111a3c andeq r0, r0, r0 */
/* @0x111a40 teqmi r4, #0 */
/* @0x111a44 ldrdmi r0, r1, [r9], #-251 */
/* @0x111a48 .word 0x43b40000 */
/* @0x111a4c adcsmi r0, r4, #0 */

/* ── FUNC 0x111a50 · F_PointDirection(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x111a50 push {r4, r5, r6, r7, r8, lr} */
/* @0x111a54 mov r1, #0 */
/* @0x111a58 ldr r4, [sp, #0x18] */
/* @0x111a5c mov r5, r0 */
/* @0x111a60 str r1, [r0, #0xc] */
/* @0x111a64 mov r0, r4 */
/* @0x111a68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x111a6c mov r1, #1 */
/* @0x111a70 mov r8, r0 */
/* @0x111a74 mov r0, r4 */
/* @0x111a78 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x111a7c mov r1, #2 */
/* @0x111a80 mov r7, r0 */
/* @0x111a84 mov r0, r4 */
/* @0x111a88 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x111a8c mov r1, #3 */
/* @0x111a90 mov r6, r0 */
/* @0x111a94 mov r0, r4 */
/* @0x111a98 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x111a9c mov r1, r7 */
/* @0x111aa0 mov r2, r6 */
/* @0x111aa4 mov r3, r0 */
/* @0x111aa8 mov r0, r8 */
/* @0x111aac bl 0x1119a4 <_Z21YYGML_point_directionffff> */
/* @0x111ab0 vmov s15, r0 */
/* @0x111ab4 vcvt.f64.f32 d7, s15 */
/* @0x111ab8 vmov r0, r1, d7 */
/* @0x111abc vmov r2, s14 */
/* @0x111ac0 mov r3, r1 */
/* @0x111ac4 stm r5, {r2, r3} */
/* @0x111ac8 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x111acc · YYGML_lengthdir_x(float, float) · size=116 · insn=29 */
/* @0x111acc vmov s13, r1 */
/* @0x111ad0 vldr s14, [pc, #92] */
/* @0x111ad4 vldr s15, [pc, #92] */
/* @0x111ad8 str lr, [sp, #-0x4]! */
/* @0x111adc vmul.f32 s14, s13, s14 */
/* @0x111ae0 vpush {d8} */
/* @0x111ae4 vmov s16, r0 */
/* @0x111ae8 sub sp, sp, #12 */
/* @0x111aec vdiv.f32 s15, s14, s15 */
/* @0x111af0 vmov r0, s15 */
/* @0x111af4 bl 0xb658c <cosf@plt> */
/* @0x111af8 add r1, sp, #4 */
/* @0x111afc vmov s15, r0 */
/* @0x111b00 vmul.f32 s16, s15, s16 */
/* @0x111b04 vmov r0, s16 */
/* @0x111b08 bl 0xb67f0 <modff@plt> */
/* @0x111b0c vldr s15, [pc, #40] */
/* @0x111b10 vmov s13, r0 */
/* @0x111b14 vabs.f32 s14, s13 */
/* @0x111b18 vcmpe.f32 s14, s15 */
/* @0x111b1c vmrs APSR_nzcv, fpscr */
/* @0x111b20 vldrmi s16, [sp, #4] */
/* @0x111b24 vmov r0, s16 */
/* @0x111b28 add sp, sp, #12 */
/* @0x111b2c vpop {d8} */
/* @0x111b30 ldr pc, [sp], #4 */
/* @0x111b34 ldrdmi r0, r1, [r9], #-251 */
/* @0x111b38 teqmi r4, #0 */
/* @0x111b3c ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */

/* ── FUNC 0x111b40 · F_LengthDirX(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x111b40 push {r4, r5, r6, lr} */
/* @0x111b44 mov r1, #0 */
/* @0x111b48 ldr r5, [sp, #0x10] */
/* @0x111b4c mov r4, r0 */
/* @0x111b50 str r1, [r0, #0xc] */
/* @0x111b54 mov r0, r5 */
/* @0x111b58 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x111b5c mov r1, #1 */
/* @0x111b60 mov r6, r0 */
/* @0x111b64 mov r0, r5 */
/* @0x111b68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x111b6c mov r1, r0 */
/* @0x111b70 mov r0, r6 */
/* @0x111b74 bl 0x111acc <_Z17YYGML_lengthdir_xff> */
/* @0x111b78 vmov s15, r0 */
/* @0x111b7c vcvt.f64.f32 d7, s15 */
/* @0x111b80 vmov r0, r1, d7 */
/* @0x111b84 vmov r2, s14 */
/* @0x111b88 mov r3, r1 */
/* @0x111b8c stm r4, {r2, r3} */
/* @0x111b90 pop {r4, r5, r6, pc} */

/* ── FUNC 0x111b94 · YYGML_lengthdir_y(float, float) · size=116 · insn=29 */
/* @0x111b94 vmov s13, r1 */
/* @0x111b98 vldr s14, [pc, #92] */
/* @0x111b9c vldr s15, [pc, #92] */
/* @0x111ba0 str lr, [sp, #-0x4]! */
/* @0x111ba4 vmul.f32 s14, s13, s14 */
/* @0x111ba8 vpush {d8} */
/* @0x111bac vmov s16, r0 */
/* @0x111bb0 sub sp, sp, #12 */
/* @0x111bb4 vdiv.f32 s15, s14, s15 */
/* @0x111bb8 vmov r0, s15 */
/* @0x111bbc bl 0xb6580 <sinf@plt> */
/* @0x111bc0 add r1, sp, #4 */
/* @0x111bc4 vmov s15, r0 */
/* @0x111bc8 vnmul.f32 s16, s16, s15 */
/* @0x111bcc vmov r0, s16 */
/* @0x111bd0 bl 0xb67f0 <modff@plt> */
/* @0x111bd4 vldr s15, [pc, #40] */
/* @0x111bd8 vmov s13, r0 */
/* @0x111bdc vabs.f32 s14, s13 */
/* @0x111be0 vcmpe.f32 s14, s15 */
/* @0x111be4 vmrs APSR_nzcv, fpscr */
/* @0x111be8 vldrmi s16, [sp, #4] */
/* @0x111bec vmov r0, s16 */
/* @0x111bf0 add sp, sp, #12 */
/* @0x111bf4 vpop {d8} */
/* @0x111bf8 ldr pc, [sp], #4 */
/* @0x111bfc ldrdmi r0, r1, [r9], #-251 */
/* @0x111c00 teqmi r4, #0 */
/* @0x111c04 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */

/* ── FUNC 0x111c08 · F_LengthDirY(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x111c08 push {r4, r5, r6, lr} */
/* @0x111c0c mov r1, #0 */
/* @0x111c10 ldr r5, [sp, #0x10] */
/* @0x111c14 mov r4, r0 */
/* @0x111c18 str r1, [r0, #0xc] */
/* @0x111c1c mov r0, r5 */
/* @0x111c20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x111c24 mov r1, #1 */
/* @0x111c28 mov r6, r0 */
/* @0x111c2c mov r0, r5 */
/* @0x111c30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x111c34 mov r1, r0 */
/* @0x111c38 mov r0, r6 */
/* @0x111c3c bl 0x111b94 <_Z17YYGML_lengthdir_yff> */
/* @0x111c40 vmov s15, r0 */
/* @0x111c44 vcvt.f64.f32 d7, s15 */
/* @0x111c48 vmov r0, r1, d7 */
/* @0x111c4c vmov r2, s14 */
/* @0x111c50 mov r3, r1 */
/* @0x111c54 stm r4, {r2, r3} */
/* @0x111c58 pop {r4, r5, r6, pc} */

/* ── FUNC 0x111c5c · InitMathFunctions() · size=4220 · insn=1055 */
/* @0x111c5c push {r4, r5, r6, lr} */
/* @0x111c60 mov r2, #1 */
/* @0x111c64 ldr r4, [pc, #0xccc] */
/* @0x111c68 mov r3, #0 */
/* @0x111c6c ldr r1, [pc, #0xcc8] */
/* @0x111c70 add r4, pc, r4 */
/* @0x111c74 ldr r0, [pc, #0xcc4] */
/* @0x111c78 ldr r1, [r4, r1] */
/* @0x111c7c add r0, pc, r0 */
/* @0x111c80 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111c84 ldr r1, [pc, #0xcb8] */
/* @0x111c88 ldr r0, [pc, #0xcb8] */
/* @0x111c8c mov r2, #1 */
/* @0x111c90 mov r3, #0 */
/* @0x111c94 ldr r1, [r4, r1] */
/* @0x111c98 add r0, pc, r0 */
/* @0x111c9c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111ca0 ldr r1, [pc, #0xca4] */
/* @0x111ca4 ldr r0, [pc, #0xca4] */
/* @0x111ca8 mov r2, #1 */
/* @0x111cac mov r3, #0 */
/* @0x111cb0 ldr r1, [r4, r1] */
/* @0x111cb4 add r0, pc, r0 */
/* @0x111cb8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111cbc ldr r1, [pc, #0xc90] */
/* @0x111cc0 ldr r0, [pc, #0xc90] */
/* @0x111cc4 mov r2, #1 */
/* @0x111cc8 mov r3, #0 */
/* @0x111ccc ldr r1, [r4, r1] */
/* @0x111cd0 add r0, pc, r0 */
/* @0x111cd4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111cd8 ldr r1, [pc, #0xc7c] */
/* @0x111cdc ldr r0, [pc, #0xc7c] */
/* @0x111ce0 mov r2, #1 */
/* @0x111ce4 mov r3, #0 */
/* @0x111ce8 ldr r1, [r4, r1] */
/* @0x111cec add r0, pc, r0 */
/* @0x111cf0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111cf4 ldr r1, [pc, #0xc68] */
/* @0x111cf8 ldr r0, [pc, #0xc68] */
/* @0x111cfc mov r2, #1 */
/* @0x111d00 mov r3, #0 */
/* @0x111d04 ldr r1, [r4, r1] */
/* @0x111d08 add r0, pc, r0 */
/* @0x111d0c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111d10 ldr r1, [pc, #0xc54] */
/* @0x111d14 ldr r0, [pc, #0xc54] */
/* @0x111d18 mov r2, #1 */
/* @0x111d1c mov r3, #0 */
/* @0x111d20 ldr r1, [r4, r1] */
/* @0x111d24 add r0, pc, r0 */
/* @0x111d28 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111d2c ldr r1, [pc, #0xc40] */
/* @0x111d30 ldr r0, [pc, #0xc40] */
/* @0x111d34 mov r2, #1 */
/* @0x111d38 mov r3, #0 */
/* @0x111d3c ldr r1, [r4, r1] */
/* @0x111d40 add r0, pc, r0 */
/* @0x111d44 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111d48 ldr r1, [pc, #0xc2c] */
/* @0x111d4c ldr r0, [pc, #0xc2c] */
/* @0x111d50 mov r2, #1 */
/* @0x111d54 mov r3, #0 */
/* @0x111d58 ldr r1, [r4, r1] */
/* @0x111d5c add r0, pc, r0 */
/* @0x111d60 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111d64 ldr r1, [pc, #0xc18] */
/* @0x111d68 ldr r0, [pc, #0xc18] */
/* @0x111d6c mov r2, #1 */
/* @0x111d70 mov r3, #0 */
/* @0x111d74 ldr r1, [r4, r1] */
/* @0x111d78 add r0, pc, r0 */
/* @0x111d7c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111d80 ldr r1, [pc, #0xc04] */
/* @0x111d84 ldr r0, [pc, #0xc04] */
/* @0x111d88 mov r2, #1 */
/* @0x111d8c mov r3, #0 */
/* @0x111d90 ldr r1, [r4, r1] */
/* @0x111d94 add r0, pc, r0 */
/* @0x111d98 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111d9c ldr r1, [pc, #0xbf0] */
/* @0x111da0 ldr r0, [pc, #0xbf0] */
/* @0x111da4 mov r2, #1 */
/* @0x111da8 mov r3, #0 */
/* @0x111dac ldr r1, [r4, r1] */
/* @0x111db0 add r0, pc, r0 */
/* @0x111db4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111db8 ldr r1, [pc, #0xbdc] */
/* @0x111dbc ldr r0, [pc, #0xbdc] */
/* @0x111dc0 mov r2, #1 */
/* @0x111dc4 mov r3, #0 */
/* @0x111dc8 ldr r1, [r4, r1] */
/* @0x111dcc add r0, pc, r0 */
/* @0x111dd0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111dd4 ldr r1, [pc, #0xbc8] */
/* @0x111dd8 ldr r0, [pc, #0xbc8] */
/* @0x111ddc mov r2, #2 */
/* @0x111de0 mov r3, #0 */
/* @0x111de4 ldr r1, [r4, r1] */
/* @0x111de8 add r0, pc, r0 */
/* @0x111dec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111df0 ldr r1, [pc, #0xbb4] */
/* @0x111df4 ldr r0, [pc, #0xbb4] */
/* @0x111df8 mov r2, #1 */
/* @0x111dfc mov r3, #0 */
/* @0x111e00 ldr r1, [r4, r1] */
/* @0x111e04 add r0, pc, r0 */
/* @0x111e08 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111e0c ldr r1, [pc, #0xba0] */
/* @0x111e10 ldr r0, [pc, #0xba0] */
/* @0x111e14 mov r2, #2 */
/* @0x111e18 mov r3, #0 */
/* @0x111e1c ldr r1, [r4, r1] */
/* @0x111e20 add r0, pc, r0 */
/* @0x111e24 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111e28 ldr r1, [pc, #0xb8c] */
/* @0x111e2c ldr r0, [pc, #0xb8c] */
/* @0x111e30 mov r2, #3 */
/* @0x111e34 mov r3, #0 */
/* @0x111e38 ldr r1, [r4, r1] */
/* @0x111e3c add r0, pc, r0 */
/* @0x111e40 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111e44 ldr r1, [pc, #0xb78] */
/* @0x111e48 ldr r0, [pc, #0xb78] */
/* @0x111e4c mov r2, #3 */
/* @0x111e50 mov r3, #0 */
/* @0x111e54 ldr r1, [r4, r1] */
/* @0x111e58 add r0, pc, r0 */
/* @0x111e5c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111e60 ldr r1, [pc, #0xb64] */
/* @0x111e64 ldr r0, [pc, #0xb64] */
/* @0x111e68 mov r2, #3 */
/* @0x111e6c mov r3, #0 */
/* @0x111e70 ldr r1, [r4, r1] */
/* @0x111e74 add r0, pc, r0 */
/* @0x111e78 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111e7c ldr r1, [pc, #0xb50] */
/* @0x111e80 ldr r0, [pc, #0xb50] */
/* @0x111e84 mov r2, #2 */
/* @0x111e88 mov r3, #0 */
/* @0x111e8c ldr r1, [r4, r1] */
/* @0x111e90 add r0, pc, r0 */
/* @0x111e94 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111e98 ldr r1, [pc, #0xb3c] */
/* @0x111e9c ldr r0, [pc, #0xb3c] */
/* @0x111ea0 mov r2, #3 */
/* @0x111ea4 mov r3, #0 */
/* @0x111ea8 ldr r1, [r4, r1] */
/* @0x111eac add r0, pc, r0 */
/* @0x111eb0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111eb4 ldr r1, [pc, #0xb28] */
/* @0x111eb8 ldr r0, [pc, #0xb28] */
/* @0x111ebc mov r2, #3 */
/* @0x111ec0 mov r3, #0 */
/* @0x111ec4 ldr r1, [r4, r1] */
/* @0x111ec8 add r0, pc, r0 */
/* @0x111ecc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111ed0 ldr r1, [pc, #0xb14] */
/* @0x111ed4 ldr r0, [pc, #0xb14] */
/* @0x111ed8 mov r2, #3 */
/* @0x111edc mov r3, #0 */
/* @0x111ee0 ldr r1, [r4, r1] */
/* @0x111ee4 add r0, pc, r0 */
/* @0x111ee8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111eec ldr r1, [pc, #0xb00] */
/* @0x111ef0 ldr r0, [pc, #0xb00] */
/* @0x111ef4 mov r2, #2 */
/* @0x111ef8 mov r3, #0 */
/* @0x111efc ldr r1, [r4, r1] */
/* @0x111f00 add r0, pc, r0 */
/* @0x111f04 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111f08 ldr r1, [pc, #0xaec] */
/* @0x111f0c ldr r0, [pc, #0xaec] */
/* @0x111f10 mvn r2, #0 */
/* @0x111f14 mov r3, #0 */
/* @0x111f18 ldr r1, [r4, r1] */
/* @0x111f1c add r0, pc, r0 */
/* @0x111f20 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111f24 ldr r1, [pc, #0xad8] */
/* @0x111f28 ldr r0, [pc, #0xad8] */
/* @0x111f2c mov r2, #5 */
/* @0x111f30 mov r3, #0 */
/* @0x111f34 ldr r1, [r4, r1] */
/* @0x111f38 add r0, pc, r0 */
/* @0x111f3c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111f40 ldr r1, [pc, #0xac4] */
/* @0x111f44 ldr r0, [pc, #0xac4] */
/* @0x111f48 mov r2, #1 */
/* @0x111f4c mov r3, #0 */
/* @0x111f50 ldr r1, [r4, r1] */
/* @0x111f54 add r0, pc, r0 */
/* @0x111f58 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111f5c ldr r1, [pc, #0xab0] */
/* @0x111f60 ldr r0, [pc, #0xab0] */
/* @0x111f64 mov r2, #2 */
/* @0x111f68 mov r3, #0 */
/* @0x111f6c ldr r1, [r4, r1] */
/* @0x111f70 add r0, pc, r0 */
/* @0x111f74 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111f78 ldr r1, [pc, #0xa9c] */
/* @0x111f7c ldr r0, [pc, #0xa9c] */
/* @0x111f80 mov r2, #1 */
/* @0x111f84 mov r3, #0 */
/* @0x111f88 ldr r1, [r4, r1] */
/* @0x111f8c add r0, pc, r0 */
/* @0x111f90 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111f94 ldr r1, [pc, #0xa88] */
/* @0x111f98 ldr r0, [pc, #0xa88] */
/* @0x111f9c mov r2, #2 */
/* @0x111fa0 mov r3, #0 */
/* @0x111fa4 ldr r1, [r4, r1] */
/* @0x111fa8 add r0, pc, r0 */
/* @0x111fac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111fb0 ldr r1, [pc, #0xa74] */
/* @0x111fb4 ldr r0, [pc, #0xa74] */
/* @0x111fb8 mov r2, #1 */
/* @0x111fbc mov r3, #0 */
/* @0x111fc0 ldr r1, [r4, r1] */
/* @0x111fc4 add r0, pc, r0 */
/* @0x111fc8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111fcc ldr r1, [pc, #0xa60] */
/* @0x111fd0 ldr r0, [pc, #0xa60] */
/* @0x111fd4 mov r2, #1 */
/* @0x111fd8 mov r3, #0 */
/* @0x111fdc ldr r1, [r4, r1] */
/* @0x111fe0 add r0, pc, r0 */
/* @0x111fe4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x111fe8 ldr r1, [pc, #0xa4c] */
/* @0x111fec ldr r0, [pc, #0xa4c] */
/* @0x111ff0 mov r2, #0 */
/* @0x111ff4 mov r3, r2 */
/* @0x111ff8 ldr r1, [r4, r1] */
/* @0x111ffc add r0, pc, r0 */
/* @0x112000 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112004 ldr r1, [pc, #0xa38] */
/* @0x112008 ldr r0, [pc, #0xa38] */
/* @0x11200c mov r2, #0 */
/* @0x112010 mov r3, r2 */
/* @0x112014 ldr r5, [r4, r1] */
/* @0x112018 add r0, pc, r0 */
/* @0x11201c mov r1, r5 */
/* @0x112020 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112024 ldr r0, [pc, #0xa20] */
/* @0x112028 mov r2, #0 */
/* @0x11202c mov r1, r5 */
/* @0x112030 mov r3, r2 */
/* @0x112034 add r0, pc, r0 */
/* @0x112038 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11203c ldr r1, [pc, #0xa0c] */
/* @0x112040 ldr r0, [pc, #0xa0c] */
/* @0x112044 mov r2, #1 */
/* @0x112048 mov r3, #0 */
/* @0x11204c ldr r1, [r4, r1] */
/* @0x112050 add r0, pc, r0 */
/* @0x112054 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112058 ldr r1, [pc, #0x9f8] */
/* @0x11205c ldr r0, [pc, #0x9f8] */
/* @0x112060 mov r2, #1 */
/* @0x112064 mov r3, #0 */
/* @0x112068 ldr r1, [r4, r1] */
/* @0x11206c add r0, pc, r0 */
/* @0x112070 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112074 ldr r1, [pc, #0x9e4] */
/* @0x112078 ldr r0, [pc, #0x9e4] */
/* @0x11207c mov r2, #1 */
/* @0x112080 mov r3, #0 */
/* @0x112084 ldr r1, [r4, r1] */
/* @0x112088 add r0, pc, r0 */
/* @0x11208c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112090 ldr r1, [pc, #0x9d0] */
/* @0x112094 ldr r0, [pc, #0x9d0] */
/* @0x112098 mov r2, #1 */
/* @0x11209c mov r3, #0 */
/* @0x1120a0 ldr r1, [r4, r1] */
/* @0x1120a4 add r0, pc, r0 */
/* @0x1120a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1120ac ldr r1, [pc, #0x9bc] */
/* @0x1120b0 ldr r0, [pc, #0x9bc] */
/* @0x1120b4 mov r2, #1 */
/* @0x1120b8 mov r3, #0 */
/* @0x1120bc ldr r1, [r4, r1] */
/* @0x1120c0 add r0, pc, r0 */
/* @0x1120c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1120c8 ldr r1, [pc, #0x9a8] */
/* @0x1120cc ldr r0, [pc, #0x9a8] */
/* @0x1120d0 mov r2, #1 */
/* @0x1120d4 mov r3, #0 */
/* @0x1120d8 ldr r1, [r4, r1] */
/* @0x1120dc add r0, pc, r0 */
/* @0x1120e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1120e4 ldr r1, [pc, #0x994] */
/* @0x1120e8 ldr r0, [pc, #0x994] */
/* @0x1120ec mov r2, #1 */
/* @0x1120f0 mov r3, #0 */
/* @0x1120f4 ldr r1, [r4, r1] */
/* @0x1120f8 add r0, pc, r0 */
/* @0x1120fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112100 ldr r1, [pc, #0x980] */
/* @0x112104 ldr r0, [pc, #0x980] */
/* @0x112108 mov r2, #1 */
/* @0x11210c mov r3, #0 */
/* @0x112110 ldr r1, [r4, r1] */
/* @0x112114 add r0, pc, r0 */
/* @0x112118 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11211c ldr r1, [pc, #0x96c] */
/* @0x112120 ldr r0, [pc, #0x96c] */
/* @0x112124 mov r2, #1 */
/* @0x112128 mov r3, #0 */
/* @0x11212c ldr r1, [r4, r1] */
/* @0x112130 add r0, pc, r0 */
/* @0x112134 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112138 ldr r1, [pc, #0x958] */
/* @0x11213c ldr r0, [pc, #0x958] */
/* @0x112140 mov r2, #1 */
/* @0x112144 mov r3, #0 */
/* @0x112148 ldr r1, [r4, r1] */
/* @0x11214c add r0, pc, r0 */
/* @0x112150 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112154 ldr r1, [pc, #0x944] */
/* @0x112158 ldr r0, [pc, #0x944] */
/* @0x11215c mov r2, #1 */
/* @0x112160 mov r3, #0 */
/* @0x112164 ldr r1, [r4, r1] */
/* @0x112168 add r0, pc, r0 */
/* @0x11216c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112170 ldr r1, [pc, #0x930] */
/* @0x112174 ldr r0, [pc, #0x930] */
/* @0x112178 mov r2, #1 */
/* @0x11217c mov r3, #0 */
/* @0x112180 ldr r1, [r4, r1] */
/* @0x112184 add r0, pc, r0 */
/* @0x112188 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11218c ldr r1, [pc, #0x91c] */
/* @0x112190 ldr r0, [pc, #0x91c] */
/* @0x112194 mov r2, #1 */
/* @0x112198 mov r3, #0 */
/* @0x11219c ldr r1, [r4, r1] */
/* @0x1121a0 add r0, pc, r0 */
/* @0x1121a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1121a8 ldr r1, [pc, #0x908] */
/* @0x1121ac ldr r0, [pc, #0x908] */
/* @0x1121b0 mov r2, #1 */
/* @0x1121b4 mov r3, #0 */
/* @0x1121b8 ldr r1, [r4, r1] */
/* @0x1121bc add r0, pc, r0 */
/* @0x1121c0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1121c4 ldr r1, [pc, #0x8f4] */
/* @0x1121c8 ldr r0, [pc, #0x8f4] */
/* @0x1121cc mov r2, #1 */
/* @0x1121d0 mov r3, #0 */
/* @0x1121d4 ldr r1, [r4, r1] */
/* @0x1121d8 add r0, pc, r0 */
/* @0x1121dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1121e0 ldr r1, [pc, #0x8e0] */
/* @0x1121e4 ldr r0, [pc, #0x8e0] */
/* @0x1121e8 mov r2, #1 */
/* @0x1121ec mov r3, #0 */
/* @0x1121f0 ldr r1, [r4, r1] */
/* @0x1121f4 add r0, pc, r0 */
/* @0x1121f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1121fc ldr r1, [pc, #0x8cc] */
/* @0x112200 ldr r0, [pc, #0x8cc] */
/* @0x112204 mov r2, #1 */
/* @0x112208 mov r3, #0 */
/* @0x11220c ldr r1, [r4, r1] */
/* @0x112210 add r0, pc, r0 */
/* @0x112214 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112218 ldr r1, [pc, #0x8b8] */
/* @0x11221c ldr r0, [pc, #0x8b8] */
/* @0x112220 mov r2, #1 */
/* @0x112224 mov r3, #0 */
/* @0x112228 ldr r1, [r4, r1] */
/* @0x11222c add r0, pc, r0 */
/* @0x112230 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112234 ldr r1, [pc, #0x8a4] */
/* @0x112238 ldr r0, [pc, #0x8a4] */
/* @0x11223c mov r2, #2 */
/* @0x112240 mov r3, #0 */
/* @0x112244 ldr r1, [r4, r1] */
/* @0x112248 add r0, pc, r0 */
/* @0x11224c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112250 ldr r1, [pc, #0x890] */
/* @0x112254 ldr r0, [pc, #0x890] */
/* @0x112258 mov r2, #1 */
/* @0x11225c mov r3, #0 */
/* @0x112260 ldr r1, [r4, r1] */
/* @0x112264 add r0, pc, r0 */
/* @0x112268 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11226c ldr r1, [pc, #0x87c] */
/* @0x112270 ldr r0, [pc, #0x87c] */
/* @0x112274 mov r2, #1 */
/* @0x112278 mov r3, #0 */
/* @0x11227c ldr r1, [r4, r1] */
/* @0x112280 add r0, pc, r0 */
/* @0x112284 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112288 ldr r1, [pc, #0x868] */
/* @0x11228c ldr r0, [pc, #0x868] */
/* @0x112290 mov r2, #1 */
/* @0x112294 mov r3, #0 */
/* @0x112298 ldr r1, [r4, r1] */
/* @0x11229c add r0, pc, r0 */
/* @0x1122a0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1122a4 ldr r1, [pc, #0x854] */
/* @0x1122a8 ldr r0, [pc, #0x854] */
/* @0x1122ac mov r2, #1 */
/* @0x1122b0 mov r3, #0 */
/* @0x1122b4 ldr r1, [r4, r1] */
/* @0x1122b8 add r0, pc, r0 */
/* @0x1122bc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1122c0 ldr r1, [pc, #0x840] */
/* @0x1122c4 ldr r0, [pc, #0x840] */
/* @0x1122c8 mov r2, #1 */
/* @0x1122cc mov r3, #0 */
/* @0x1122d0 ldr r1, [r4, r1] */
/* @0x1122d4 add r0, pc, r0 */
/* @0x1122d8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1122dc ldr r1, [pc, #0x82c] */
/* @0x1122e0 ldr r0, [pc, #0x82c] */
/* @0x1122e4 mov r2, #1 */
/* @0x1122e8 mov r3, #0 */
/* @0x1122ec ldr r1, [r4, r1] */
/* @0x1122f0 add r0, pc, r0 */
/* @0x1122f4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1122f8 ldr r1, [pc, #0x818] */
/* @0x1122fc ldr r0, [pc, #0x818] */
/* @0x112300 mov r2, #2 */
/* @0x112304 mov r3, #0 */
/* @0x112308 ldr r1, [r4, r1] */
/* @0x11230c add r0, pc, r0 */
/* @0x112310 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112314 ldr r1, [pc, #0x804] */
/* @0x112318 ldr r0, [pc, #0x804] */
/* @0x11231c mov r2, #1 */
/* @0x112320 mov r3, #0 */
/* @0x112324 ldr r1, [r4, r1] */
/* @0x112328 add r0, pc, r0 */
/* @0x11232c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112330 ldr r1, [pc, #0x7f0] */
/* @0x112334 ldr r0, [pc, #0x7f0] */
/* @0x112338 mov r2, #1 */
/* @0x11233c mov r3, #0 */
/* @0x112340 ldr r1, [r4, r1] */
/* @0x112344 add r0, pc, r0 */
/* @0x112348 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11234c ldr r1, [pc, #0x7dc] */
/* @0x112350 ldr r0, [pc, #0x7dc] */
/* @0x112354 mov r2, #2 */
/* @0x112358 mov r3, #0 */
/* @0x11235c ldr r1, [r4, r1] */
/* @0x112360 add r0, pc, r0 */
/* @0x112364 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112368 ldr r1, [pc, #0x7c8] */
/* @0x11236c ldr r0, [pc, #0x7c8] */
/* @0x112370 mov r2, #2 */
/* @0x112374 mov r3, #0 */
/* @0x112378 ldr r1, [r4, r1] */
/* @0x11237c add r0, pc, r0 */
/* @0x112380 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112384 ldr r1, [pc, #0x7b4] */
/* @0x112388 ldr r0, [pc, #0x7b4] */
/* @0x11238c mvn r2, #0 */
/* @0x112390 mov r3, #0 */
/* @0x112394 ldr r1, [r4, r1] */
/* @0x112398 add r0, pc, r0 */
/* @0x11239c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1123a0 ldr r1, [pc, #0x7a0] */
/* @0x1123a4 ldr r0, [pc, #0x7a0] */
/* @0x1123a8 mvn r2, #0 */
/* @0x1123ac mov r3, #0 */
/* @0x1123b0 ldr r1, [r4, r1] */
/* @0x1123b4 add r0, pc, r0 */
/* @0x1123b8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1123bc ldr r1, [pc, #0x78c] */
/* @0x1123c0 ldr r0, [pc, #0x78c] */
/* @0x1123c4 mov r2, #3 */
/* @0x1123c8 mov r3, #0 */
/* @0x1123cc ldr r1, [r4, r1] */
/* @0x1123d0 add r0, pc, r0 */
/* @0x1123d4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1123d8 ldr r1, [pc, #0x778] */
/* @0x1123dc ldr r0, [pc, #0x778] */
/* @0x1123e0 mov r2, #3 */
/* @0x1123e4 mov r3, #0 */
/* @0x1123e8 ldr r1, [r4, r1] */
/* @0x1123ec add r0, pc, r0 */
/* @0x1123f0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1123f4 ldr r1, [pc, #0x764] */
/* @0x1123f8 ldr r0, [pc, #0x764] */
/* @0x1123fc mvn r2, #0 */
/* @0x112400 mov r3, #0 */
/* @0x112404 ldr r1, [r4, r1] */
/* @0x112408 add r0, pc, r0 */
/* @0x11240c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112410 ldr r1, [pc, #0x750] */
/* @0x112414 ldr r0, [pc, #0x750] */
/* @0x112418 mvn r2, #0 */
/* @0x11241c mov r3, #0 */
/* @0x112420 ldr r1, [r4, r1] */
/* @0x112424 add r0, pc, r0 */
/* @0x112428 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11242c ldr r1, [pc, #0x73c] */
/* @0x112430 ldr r0, [pc, #0x73c] */
/* @0x112434 mvn r2, #0 */
/* @0x112438 mov r3, #0 */
/* @0x11243c ldr r1, [r4, r1] */
/* @0x112440 add r0, pc, r0 */
/* @0x112444 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112448 ldr r1, [pc, #0x728] */
/* @0x11244c ldr r0, [pc, #0x728] */
/* @0x112450 mov r2, #3 */
/* @0x112454 mov r3, #1 */
/* @0x112458 ldr r1, [r4, r1] */
/* @0x11245c add r0, pc, r0 */
/* @0x112460 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112464 ldr r1, [pc, #0x714] */
/* @0x112468 ldr r0, [pc, #0x714] */
/* @0x11246c mov r2, #3 */
/* @0x112470 mov r3, #1 */
/* @0x112474 ldr r1, [r4, r1] */
/* @0x112478 add r0, pc, r0 */
/* @0x11247c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112480 ldr r1, [pc, #0x700] */
/* @0x112484 ldr r0, [pc, #0x700] */
/* @0x112488 mov r2, #1 */
/* @0x11248c mov r3, #0 */
/* @0x112490 ldr r1, [r4, r1] */
/* @0x112494 add r0, pc, r0 */
/* @0x112498 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11249c ldr r1, [pc, #0x6ec] */
/* @0x1124a0 ldr r0, [pc, #0x6ec] */
/* @0x1124a4 mov r2, #1 */
/* @0x1124a8 mov r3, #0 */
/* @0x1124ac ldr r1, [r4, r1] */
/* @0x1124b0 add r0, pc, r0 */
/* @0x1124b4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1124b8 ldr r1, [pc, #0x6d8] */
/* @0x1124bc ldr r0, [pc, #0x6d8] */
/* @0x1124c0 mov r2, #1 */
/* @0x1124c4 mov r3, #0 */
/* @0x1124c8 ldr r1, [r4, r1] */
/* @0x1124cc add r0, pc, r0 */
/* @0x1124d0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1124d4 ldr r1, [pc, #0x6c4] */
/* @0x1124d8 ldr r0, [pc, #0x6c4] */
/* @0x1124dc mov r2, #1 */
/* @0x1124e0 mov r3, #0 */
/* @0x1124e4 ldr r1, [r4, r1] */
/* @0x1124e8 add r0, pc, r0 */
/* @0x1124ec bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1124f0 ldr r1, [pc, #0x6b0] */
/* @0x1124f4 ldr r0, [pc, #0x6b0] */
/* @0x1124f8 mov r2, #1 */
/* @0x1124fc mov r3, #0 */
/* @0x112500 ldr r1, [r4, r1] */
/* @0x112504 add r0, pc, r0 */
/* @0x112508 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11250c ldr r1, [pc, #0x69c] */
/* @0x112510 ldr r0, [pc, #0x69c] */
/* @0x112514 mov r2, #3 */
/* @0x112518 mov r3, #0 */
/* @0x11251c ldr r1, [r4, r1] */
/* @0x112520 add r0, pc, r0 */
/* @0x112524 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112528 ldr r1, [pc, #0x688] */
/* @0x11252c ldr r0, [pc, #0x688] */
/* @0x112530 mov r2, #1 */
/* @0x112534 mov r3, #0 */
/* @0x112538 ldr r1, [r4, r1] */
/* @0x11253c add r0, pc, r0 */
/* @0x112540 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112544 ldr r1, [pc, #0x674] */
/* @0x112548 ldr r0, [pc, #0x674] */
/* @0x11254c mov r2, #1 */
/* @0x112550 mov r3, #0 */
/* @0x112554 ldr r1, [r4, r1] */
/* @0x112558 add r0, pc, r0 */
/* @0x11255c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112560 ldr r1, [pc, #0x660] */
/* @0x112564 ldr r0, [pc, #0x660] */
/* @0x112568 mov r2, #1 */
/* @0x11256c mov r3, #0 */
/* @0x112570 ldr r1, [r4, r1] */
/* @0x112574 add r0, pc, r0 */
/* @0x112578 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11257c ldr r1, [pc, #0x64c] */
/* @0x112580 ldr r0, [pc, #0x64c] */
/* @0x112584 mov r2, #1 */
/* @0x112588 mov r3, #0 */
/* @0x11258c ldr r1, [r4, r1] */
/* @0x112590 add r0, pc, r0 */
/* @0x112594 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112598 ldr r1, [pc, #0x638] */
/* @0x11259c ldr r0, [pc, #0x638] */
/* @0x1125a0 mov r2, #2 */
/* @0x1125a4 mov r3, #0 */
/* @0x1125a8 ldr r1, [r4, r1] */
/* @0x1125ac add r0, pc, r0 */
/* @0x1125b0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1125b4 ldr r1, [pc, #0x624] */
/* @0x1125b8 ldr r0, [pc, #0x624] */
/* @0x1125bc mov r2, #3 */
/* @0x1125c0 mov r3, #0 */
/* @0x1125c4 ldr r1, [r4, r1] */
/* @0x1125c8 add r0, pc, r0 */
/* @0x1125cc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1125d0 ldr r1, [pc, #0x610] */
/* @0x1125d4 ldr r0, [pc, #0x610] */
/* @0x1125d8 mov r2, #2 */
/* @0x1125dc mov r3, #0 */
/* @0x1125e0 ldr r1, [r4, r1] */
/* @0x1125e4 add r0, pc, r0 */
/* @0x1125e8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1125ec ldr r1, [pc, #0x5fc] */
/* @0x1125f0 ldr r0, [pc, #0x5fc] */
/* @0x1125f4 mov r2, #2 */
/* @0x1125f8 mov r3, #0 */
/* @0x1125fc ldr r1, [r4, r1] */
/* @0x112600 add r0, pc, r0 */
/* @0x112604 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112608 ldr r1, [pc, #0x5e8] */
/* @0x11260c ldr r0, [pc, #0x5e8] */
/* @0x112610 mov r2, #1 */
/* @0x112614 mov r3, #0 */
/* @0x112618 ldr r1, [r4, r1] */
/* @0x11261c add r0, pc, r0 */
/* @0x112620 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112624 ldr r1, [pc, #0x5d4] */
/* @0x112628 ldr r0, [pc, #0x5d4] */
/* @0x11262c mov r2, #2 */
/* @0x112630 mov r3, #0 */
/* @0x112634 ldr r1, [r4, r1] */
/* @0x112638 add r0, pc, r0 */
/* @0x11263c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112640 ldr r1, [pc, #0x5c0] */
/* @0x112644 ldr r0, [pc, #0x5c0] */
/* @0x112648 mov r2, #3 */
/* @0x11264c mov r3, #0 */
/* @0x112650 ldr r1, [r4, r1] */
/* @0x112654 add r0, pc, r0 */
/* @0x112658 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11265c ldr r1, [pc, #0x5ac] */
/* @0x112660 ldr r0, [pc, #0x5ac] */
/* @0x112664 mov r2, #3 */
/* @0x112668 mov r3, #0 */
/* @0x11266c ldr r1, [r4, r1] */
/* @0x112670 add r0, pc, r0 */
/* @0x112674 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112678 ldr r1, [pc, #0x598] */
/* @0x11267c ldr r0, [pc, #0x598] */
/* @0x112680 mov r2, #3 */
/* @0x112684 mov r3, #0 */
/* @0x112688 ldr r1, [r4, r1] */
/* @0x11268c add r0, pc, r0 */
/* @0x112690 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112694 ldr r1, [pc, #0x584] */
/* @0x112698 ldr r0, [pc, #0x584] */
/* @0x11269c mov r2, #1 */
/* @0x1126a0 mov r3, #0 */
/* @0x1126a4 ldr r1, [r4, r1] */
/* @0x1126a8 add r0, pc, r0 */
/* @0x1126ac bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1126b0 ldr r1, [pc, #0x570] */
/* @0x1126b4 ldr r0, [pc, #0x570] */
/* @0x1126b8 mov r2, #1 */
/* @0x1126bc mov r3, #0 */
/* @0x1126c0 ldr r1, [r4, r1] */
/* @0x1126c4 add r0, pc, r0 */
/* @0x1126c8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1126cc ldr r1, [pc, #0x55c] */
/* @0x1126d0 ldr r0, [pc, #0x55c] */
/* @0x1126d4 mov r2, #2 */
/* @0x1126d8 mov r3, #0 */
/* @0x1126dc ldr r1, [r4, r1] */
/* @0x1126e0 add r0, pc, r0 */
/* @0x1126e4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1126e8 ldr r1, [pc, #0x548] */
/* @0x1126ec ldr r0, [pc, #0x548] */
/* @0x1126f0 mov r2, #1 */
/* @0x1126f4 mov r3, #0 */
/* @0x1126f8 ldr r1, [r4, r1] */
/* @0x1126fc add r0, pc, r0 */
/* @0x112700 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112704 ldr r1, [pc, #0x534] */
/* @0x112708 ldr r0, [pc, #0x534] */
/* @0x11270c mov r2, #1 */
/* @0x112710 mov r3, #0 */
/* @0x112714 ldr r1, [r4, r1] */
/* @0x112718 add r0, pc, r0 */
/* @0x11271c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112720 ldr r1, [pc, #0x520] */
/* @0x112724 ldr r0, [pc, #0x520] */
/* @0x112728 mov r2, #1 */
/* @0x11272c mov r3, #0 */
/* @0x112730 ldr r1, [r4, r1] */
/* @0x112734 add r0, pc, r0 */
/* @0x112738 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11273c ldr r1, [pc, #0x50c] */
/* @0x112740 ldr r0, [pc, #0x50c] */
/* @0x112744 mov r2, #3 */
/* @0x112748 mov r3, #0 */
/* @0x11274c ldr r1, [r4, r1] */
/* @0x112750 add r0, pc, r0 */
/* @0x112754 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112758 ldr r1, [pc, #0x4f8] */
/* @0x11275c ldr r0, [pc, #0x4f8] */
/* @0x112760 mov r2, #3 */
/* @0x112764 mov r3, #0 */
/* @0x112768 ldr r1, [r4, r1] */
/* @0x11276c add r0, pc, r0 */
/* @0x112770 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112774 ldr r1, [pc, #0x4e4] */
/* @0x112778 ldr r0, [pc, #0x4e4] */
/* @0x11277c mov r2, #2 */
/* @0x112780 mov r3, #0 */
/* @0x112784 ldr r1, [r4, r1] */
/* @0x112788 add r0, pc, r0 */
/* @0x11278c bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112790 ldr r1, [pc, #0x4d0] */
/* @0x112794 ldr r0, [pc, #0x4d0] */
/* @0x112798 mov r2, #1 */
/* @0x11279c mov r3, #0 */
/* @0x1127a0 ldr r1, [r4, r1] */
/* @0x1127a4 add r0, pc, r0 */
/* @0x1127a8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1127ac ldr r1, [pc, #0x4bc] */
/* @0x1127b0 ldr r0, [pc, #0x4bc] */
/* @0x1127b4 mov r2, #4 */
/* @0x1127b8 mov r3, #0 */
/* @0x1127bc ldr r1, [r4, r1] */
/* @0x1127c0 add r0, pc, r0 */
/* @0x1127c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1127c8 ldr r1, [pc, #0x4a8] */
/* @0x1127cc ldr r0, [pc, #0x4a8] */
/* @0x1127d0 mov r2, #4 */
/* @0x1127d4 mov r3, #0 */
/* @0x1127d8 ldr r1, [r4, r1] */
/* @0x1127dc add r0, pc, r0 */
/* @0x1127e0 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1127e4 ldr r1, [pc, #0x494] */
/* @0x1127e8 ldr r0, [pc, #0x494] */
/* @0x1127ec mov r2, #2 */
/* @0x1127f0 mov r3, #0 */
/* @0x1127f4 ldr r1, [r4, r1] */
/* @0x1127f8 add r0, pc, r0 */
/* @0x1127fc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112800 ldr r1, [pc, #0x480] */
/* @0x112804 ldr r0, [pc, #0x480] */
/* @0x112808 mov r2, #2 */
/* @0x11280c mov r3, #0 */
/* @0x112810 ldr r1, [r4, r1] */
/* @0x112814 add r0, pc, r0 */
/* @0x112818 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11281c ldr r1, [pc, #0x46c] */
/* @0x112820 ldr r0, [pc, #0x46c] */
/* @0x112824 mov r2, #6 */
/* @0x112828 mov r3, #0 */
/* @0x11282c ldr r1, [r4, r1] */
/* @0x112830 add r0, pc, r0 */
/* @0x112834 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112838 ldr r1, [pc, #0x458] */
/* @0x11283c ldr r0, [pc, #0x458] */
/* @0x112840 mov r2, #4 */
/* @0x112844 mov r3, #0 */
/* @0x112848 ldr r1, [r4, r1] */
/* @0x11284c add r0, pc, r0 */
/* @0x112850 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112854 ldr r1, [pc, #0x444] */
/* @0x112858 ldr r0, [pc, #0x444] */
/* @0x11285c mov r2, #4 */
/* @0x112860 mov r3, #0 */
/* @0x112864 ldr r5, [r4, r1] */
/* @0x112868 add r0, pc, r0 */
/* @0x11286c mov r1, r5 */
/* @0x112870 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112874 ldr r0, [pc, #0x42c] */
/* @0x112878 mov r1, r5 */
/* @0x11287c mov r2, #4 */
/* @0x112880 add r0, pc, r0 */
/* @0x112884 mov r3, #0 */
/* @0x112888 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x11288c ldr r1, [pc, #0x418] */
/* @0x112890 ldr r0, [pc, #0x418] */
/* @0x112894 mov r2, #6 */
/* @0x112898 mov r3, #0 */
/* @0x11289c ldr r1, [r4, r1] */
/* @0x1128a0 add r0, pc, r0 */
/* @0x1128a4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1128a8 ldr r1, [pc, #0x404] */
/* @0x1128ac ldr r0, [pc, #0x404] */
/* @0x1128b0 mov r2, #6 */
/* @0x1128b4 mov r3, #0 */
/* @0x1128b8 ldr r5, [r4, r1] */
/* @0x1128bc add r0, pc, r0 */
/* @0x1128c0 mov r1, r5 */
/* @0x1128c4 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1128c8 ldr r0, [pc, #0x3ec] */
/* @0x1128cc mov r1, r5 */
/* @0x1128d0 mov r2, #6 */
/* @0x1128d4 add r0, pc, r0 */
/* @0x1128d8 mov r3, #0 */
/* @0x1128dc bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1128e0 ldr r1, [pc, #0x3d8] */
/* @0x1128e4 ldr r0, [pc, #0x3d8] */
/* @0x1128e8 mov r2, #1 */
/* @0x1128ec mov r3, #0 */
/* @0x1128f0 ldr r1, [r4, r1] */
/* @0x1128f4 add r0, pc, r0 */
/* @0x1128f8 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x1128fc ldr r1, [pc, #0x3c4] */
/* @0x112900 ldr r0, [pc, #0x3c4] */
/* @0x112904 mov r2, #0 */
/* @0x112908 mov r3, r2 */
/* @0x11290c ldr r1, [r4, r1] */
/* @0x112910 add r0, pc, r0 */
/* @0x112914 bl 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112918 ldr r1, [pc, #0x3b0] */
/* @0x11291c ldr r0, [pc, #0x3b0] */
/* @0x112920 mov r2, #1 */
/* @0x112924 mov r3, #0 */
/* @0x112928 ldr r1, [r4, r1] */
/* @0x11292c add r0, pc, r0 */
/* @0x112930 pop {r4, r5, r6, lr} */
/* @0x112934 b 0xcdf84 <_Z12Function_AddPKcPFvR6RValueP9CInstanceS4_iPS1_Eib> */
/* @0x112938 eoreq pc, sp, r0, ror #31 */
/* @0x11293c .word 0xffffc604 */
/* @0x112940 eoreq r7, r2, r8, lsr #8 */
/* @0x112944 .word 0xffffc608 */
/* @0x112948 eoreq r7, r2, r4, lsl r4 */
/* @0x11294c .word 0xffffc60c */
/* @0x112950 eoreq r7, r2, r0, lsl #8 */
/* @0x112954 .word 0xffffc610 */
/* @0x112958 .word 0x002273f0 */
/* @0x11295c .word 0xffffc614 */
/* @0x112960 eoreq r7, r2, r0, ror #7 */
/* @0x112964 .word 0xffffc618 */
/* @0x112968 .word 0x002273d4 */
/* @0x11296c .word 0xffffc61c */
/* @0x112970 eoreq r7, r2, r4, asr #7 */
/* @0x112974 .word 0xffffc620 */
/* @0x112978 .word 0x002273b4 */
/* @0x11297c .word 0xffffc624 */
/* @0x112980 eoreq r7, r2, r0, lsr #7 */
/* @0x112984 .word 0xffffc628 */
/* @0x112988 eoreq r7, r2, r12, lsl #7 */
/* @0x11298c .word 0xffffc62c */
/* @0x112990 eoreq r7, r2, r8, ror r3 */
/* @0x112994 .word 0xffffc630 */
/* @0x112998 eoreq r7, r2, r8, ror #6 */
/* @0x11299c .word 0xffffc634 */
/* @0x1129a0 eoreq r7, r2, r4, asr r3 */
/* @0x1129a4 .word 0xffffc638 */
/* @0x1129a8 eoreq r7, r2, r8, asr #6 */
/* @0x1129ac .word 0xffffc63c */
/* @0x1129b0 eoreq r7, r2, r12, lsr r3 */
/* @0x1129b4 .word 0xffffc640 */
/* @0x1129b8 eoreq r7, r2, r0, lsr r3 */
/* @0x1129bc .word 0xffffc644 */
/* @0x1129c0 eoreq r7, r2, r0, lsr #6 */
/* @0x1129c4 .word 0xffffc648 */
/* @0x1129c8 eoreq r7, r2, r0, lsl r3 */
/* @0x1129cc .word 0xffffc64c */
/* @0x1129d0 eoreq r7, r2, r4, lsl #6 */
/* @0x1129d4 .word 0xffffc650 */
/* @0x1129d8 .word 0x002272f8 */
/* @0x1129dc .word 0xffffc654 */
/* @0x1129e0 eoreq r7, r2, r12, ror #5 */
/* @0x1129e4 .word 0xffffc658 */
/* @0x1129e8 eoreq r7, r2, r0, ror #5 */
/* @0x1129ec .word 0xffffc65c */
/* @0x1129f0 .word 0x002272d8 */
/* @0x1129f4 .word 0xffffc660 */
/* @0x1129f8 .word 0x002272d0 */
/* @0x1129fc .word 0xffffc664 */
/* @0x112a00 eoreq r7, r2, r4, asr #5 */
/* @0x112a04 .word 0xffffc668 */
/* @0x112a08 .word 0x002272b8 */
/* @0x112a0c .word 0xffffc66c */
/* @0x112a10 eoreq r7, r2, r8, lsr #5 */
/* @0x112a14 .word 0xffffc670 */
/* @0x112a18 mlaeq r2, r4, r2, r7 */
/* @0x112a1c .word 0xffffc674 */
/* @0x112a20 eoreq r7, r2, r8, lsl #5 */
/* @0x112a24 .word 0xffffc678 */
/* @0x112a28 eoreq r7, r2, r4, ror r2 */
/* @0x112a2c .word 0xffffc67c */
/* @0x112a30 eoreq r7, r2, r8, ror #4 */
/* @0x112a34 .word 0xffffc680 */
/* @0x112a38 eoreq r7, r2, r4, ror #4 */
/* @0x112a3c .word 0xffffc684 */
/* @0x112a40 eoreq r7, r2, r8, asr r2 */
/* @0x112a44 .word 0xffffc688 */
/* @0x112a48 eoreq r7, r2, r12, asr #4 */
/* @0x112a4c eoreq r7, r2, r12, lsr r2 */
/* @0x112a50 .word 0xffffc68c */
/* @0x112a54 eoreq r7, r2, r12, lsr #4 */
/* @0x112a58 .word 0xffffc690 */
/* @0x112a5c eoreq r7, r2, r4, lsl r2 */
/* @0x112a60 .word 0xffffc694 */
/* @0x112a64 eoreq r7, r2, r0, lsl #4 */
/* @0x112a68 .word 0xffffc698 */
/* @0x112a6c eoreq r7, r2, r12, ror #3 */
/* @0x112a70 .word 0xffffc69c */
/* @0x112a74 .word 0x002271d8 */
/* @0x112a78 .word 0xffffc6a0 */
/* @0x112a7c eoreq r7, r2, r4, asr #3 */
/* @0x112a80 .word 0xffffc6a4 */
/* @0x112a84 .word 0x002271b0 */
/* @0x112a88 .word 0xffffc6a8 */
/* @0x112a8c mlaeq r2, r12, r1, r7 */
/* @0x112a90 .word 0xffffc6ac */
/* @0x112a94 eoreq r7, r2, r4, lsl #3 */
/* @0x112a98 .word 0xffffc6b0 */
/* @0x112a9c eoreq r7, r2, r12, ror #2 */
/* @0x112aa0 .word 0xffffc6b4 */
/* @0x112aa4 eoreq r7, r2, r4, asr r1 */
/* @0x112aa8 .word 0xffffc6b8 */
/* @0x112aac eoreq r7, r2, r0, asr #2 */
/* @0x112ab0 .word 0xffffc6bc */
/* @0x112ab4 eoreq r7, r2, r12, lsr #2 */
/* @0x112ab8 .word 0xffffc6c0 */
/* @0x112abc eoreq r7, r2, r4, lsl r1 */
/* @0x112ac0 .word 0xffffc6c4 */
/* @0x112ac4 .word 0x002270fc */
/* @0x112ac8 .word 0xffffc6c8 */
/* @0x112acc eoreq r7, r2, r4, ror #1 */
/* @0x112ad0 .word 0xffffc6cc */
/* @0x112ad4 .word 0x002270d0 */
/* @0x112ad8 .word 0xffffc6d0 */
/* @0x112adc strhteq r7, [r2], -r12 */
/* @0x112ae0 .word 0xffffc6d4 */
/* @0x112ae4 eoreq r7, r2, r8, lsr #1 */
/* @0x112ae8 .word 0xffffc6d8 */
/* @0x112aec mlaeq r2, r4, r0, r7 */
/* @0x112af0 .word 0xffffc6dc */
/* @0x112af4 eoreq r7, r2, r0, lsl #1 */
/* @0x112af8 .word 0xffffc6e0 */
/* @0x112afc eoreq r7, r2, r12, rrx */
/* @0x112b00 .word 0xffffc6e4 */
/* @0x112b04 eoreq r7, r2, r8, asr r0 */
/* @0x112b08 .word 0xffffc6e8 */
/* @0x112b0c eoreq r7, r2, r4, asr #32 */
/* @0x112b10 .word 0xffffc6ec */
/* @0x112b14 eoreq r7, r2, r0, lsr r0 */
/* @0x112b18 .word 0xffffc6f0 */
/* @0x112b1c eoreq r7, r2, r12, lsl r0 */
/* @0x112b20 .word 0xffffc6f4 */
/* @0x112b24 eoreq r7, r2, r12 */
/* @0x112b28 .word 0xffffc6f8 */
/* @0x112b2c .word 0x00226ffc */
/* @0x112b30 .word 0xffffc6fc */
/* @0x112b34 eoreq r6, r2, r12, ror #31 */
/* @0x112b38 .word 0xffffc700 */
/* @0x112b3c .word 0x00226fd8 */
/* @0x112b40 .word 0xffffc704 */
/* @0x112b44 eoreq r6, r2, r4, asr #31 */
/* @0x112b48 .word 0xffffc708 */
/* @0x112b4c eoreq r6, r2, r12, lsr #31 */
/* @0x112b50 .word 0xffffc70c */
/* @0x112b54 mlaeq r2, r4, pc, r6 */
/* @0x112b58 .word 0xffffc710 */
/* @0x112b5c eoreq r6, r2, r0, lsl #31 */
/* @0x112b60 .word 0xffffc714 */
/* @0x112b64 eoreq r6, r2, r12, ror #30 */
/* @0x112b68 .word 0xffffc718 */
/* @0x112b6c eoreq r6, r2, r8, asr pc */
/* @0x112b70 .word 0xffffc71c */
/* @0x112b74 eoreq r6, r2, r4, asr #30 */
/* @0x112b78 .word 0xffffc720 */
/* @0x112b7c eoreq r6, r2, r0, lsr pc */
/* @0x112b80 .word 0xffffc724 */
/* @0x112b84 eoreq r6, r2, r12, lsl pc */
/* @0x112b88 .word 0xffffc728 */
/* @0x112b8c eoreq r6, r2, r8, lsl #30 */
/* @0x112b90 .word 0xffffc72c */
/* @0x112b94 eoreq pc, r1, r0, asr #27 */
/* @0x112b98 .word 0xffffc730 */
/* @0x112b9c eoreq lr, r1, r12, asr r3 */
/* @0x112ba0 .word 0xffffc734 */
/* @0x112ba4 mlaeq r1, r0, sp, pc */
/* @0x112ba8 .word 0xffffc738 */
/* @0x112bac eoreq pc, r1, r8, ror #26 */
/* @0x112bb0 .word 0xffffc73c */
/* @0x112bb4 eoreq r6, r2, r4, lsl #29 */
/* @0x112bb8 .word 0xffffc740 */
/* @0x112bbc eoreq r6, r2, r8, ror lr */
/* @0x112bc0 .word 0xffffc744 */
/* @0x112bc4 eoreq r6, r2, r0, ror #28 */
/* @0x112bc8 .word 0xffffc748 */
/* @0x112bcc eoreq r6, r2, r0, asr lr */
/* @0x112bd0 .word 0xffffc74c */
/* @0x112bd4 eoreq r6, r2, r8, lsr lr */
/* @0x112bd8 .word 0xffffc750 */
/* @0x112bdc eoreq r6, r2, r12, lsr #28 */
/* @0x112be0 .word 0xffffc754 */
/* @0x112be4 eoreq r6, r2, r12, lsl lr */
/* @0x112be8 .word 0xffffc758 */
/* @0x112bec eoreq r6, r2, r12, lsl #28 */
/* @0x112bf0 .word 0xffffc75c */
/* @0x112bf4 eoreq r6, r2, r0, lsl #28 */
/* @0x112bf8 .word 0xffffc760 */
/* @0x112bfc .word 0x00226df4 */
/* @0x112c00 .word 0xffffc764 */
/* @0x112c04 eoreq r6, r2, r12, ror #27 */
/* @0x112c08 .word 0xffffc768 */
/* @0x112c0c eoreq r6, r2, r0, ror #27 */
/* @0x112c10 .word 0xffffc76c */
/* @0x112c14 .word 0x00226dd8 */
/* @0x112c18 .word 0xffffc770 */
/* @0x112c1c eoreq r6, r2, r12, asr #27 */
/* @0x112c20 .word 0xffffc774 */
/* @0x112c24 eoreq r6, r2, r0, asr #27 */
/* @0x112c28 .word 0xffffc778 */
/* @0x112c2c .word 0x00226db4 */
/* @0x112c30 .word 0xffffc77c */
/* @0x112c34 eoreq r6, r2, r8, lsr #27 */
/* @0x112c38 .word 0xffffc780 */
/* @0x112c3c mlaeq r2, r12, sp, r6 */
/* @0x112c40 .word 0xffffc784 */
/* @0x112c44 mlaeq r2, r0, sp, r6 */
/* @0x112c48 .word 0xffffc788 */
/* @0x112c4c eoreq r6, r2, r4, lsl #27 */
/* @0x112c50 .word 0xffffc78c */
/* @0x112c54 eoreq r6, r2, r0, lsl #27 */
/* @0x112c58 .word 0xffffc790 */
/* @0x112c5c eoreq r6, r2, r4, ror sp */
/* @0x112c60 .word 0xffffc794 */
/* @0x112c64 eoreq r6, r2, r12, ror #26 */
/* @0x112c68 .word 0xffffc798 */
/* @0x112c6c eoreq r6, r2, r0, ror #26 */
/* @0x112c70 .word 0xffffc79c */
/* @0x112c74 eoreq r6, r2, r12, asr sp */
/* @0x112c78 .word 0xffffc7a0 */
/* @0x112c7c eoreq r6, r2, r0, asr sp */
/* @0x112c80 .word 0xffffc7a4 */
/* @0x112c84 eoreq r6, r2, r4, asr #26 */
/* @0x112c88 .word 0xffffc7a8 */
/* @0x112c8c eoreq r6, r2, r4, lsr sp */
/* @0x112c90 .word 0xffffc7ac */
/* @0x112c94 eoreq r6, r2, r4, lsr #26 */
/* @0x112c98 .word 0xffffc7b0 */
/* @0x112c9c eoreq r6, r2, r12, lsl sp */
/* @0x112ca0 .word 0xffffc7b4 */
/* @0x112ca4 eoreq r6, r2, r12, lsl #26 */
/* @0x112ca8 eoreq r6, r2, r12, lsl #26 */
/* @0x112cac .word 0xffffc7b8 */
/* @0x112cb0 eoreq r6, r2, r4, lsl #26 */
/* @0x112cb4 .word 0xffffc7bc */
/* @0x112cb8 .word 0x00226cf8 */
/* @0x112cbc .word 0x00226cfc */
/* @0x112cc0 .word 0xffffc7c0 */
/* @0x112cc4 .word 0x00226cf8 */
/* @0x112cc8 .word 0xffffc7c4 */
/* @0x112ccc .word 0x00226cf0 */
/* @0x112cd0 .word 0xffffc7c8 */
/* @0x112cd4 eoreq r6, r2, r8, ror #25 */

/* ── FUNC 0x112cd8 · F_ArraySetPre(RValue&, CInstance*, CInstance*, int, RValue*) · size=628 · insn=157 */
/* @0x112cd8 push {r3, r4, r5, r6, r7, lr} */
/* @0x112cdc cmp r3, #3 */
/* @0x112ce0 ldr r4, [sp, #0x18] */
/* @0x112ce4 mov r5, r0 */
/* @0x112ce8 ldr r3, [r4, #0xc] */
/* @0x112cec beq 0x112d18 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x112cf0 cmp r3, #2 */
/* @0x112cf4 beq 0x112d08 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x112cf8 ldr r0, [pc, #0x244] */
/* @0x112cfc pop {r3, r4, r5, r6, r7, lr} */
/* @0x112d00 add r0, pc, r0 */
/* @0x112d04 b 0xd547c <_Z7YYErrorPKcz> */
/* @0x112d08 ldr r0, [pc, #0x238] */
/* @0x112d0c pop {r3, r4, r5, r6, r7, lr} */
/* @0x112d10 add r0, pc, r0 */
/* @0x112d14 b 0xd547c <_Z7YYErrorPKcz> */
/* @0x112d18 cmp r3, #2 */
/* @0x112d1c bne 0x112cf8 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x20> */
/* @0x112d20 ldr r3, [r4] */
/* @0x112d24 cmp r3, #0 */
/* @0x112d28 beq 0x112d08 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x112d2c mov r1, #1 */
/* @0x112d30 mov r0, r4 */
/* @0x112d34 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x112d38 add r1, r4, #32 */
/* @0x112d3c mov r2, r0 */
/* @0x112d40 mov r0, r4 */
/* @0x112d44 bl 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i> */
/* @0x112d48 ldr r2, [r5, #0xc] */
/* @0x112d4c bic r3, r2, #-16777216 */
/* @0x112d50 cmp r3, #1 */
/* @0x112d54 beq 0x112df8 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x112d58 cmp r3, #2 */
/* @0x112d5c bne 0x112d84 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x112d60 sub r3, r2, #1 */
/* @0x112d64 bic r3, r3, #-16777216 */
/* @0x112d68 bic r3, r3, #3 */
/* @0x112d6c cmp r3, #0 */
/* @0x112d70 beq 0x112ee0 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x112d74 mov r2, #0 */
/* @0x112d78 mov r3, #5 */
/* @0x112d7c str r2, [r5, #0x8] */
/* @0x112d80 str r3, [r5, #0xc] */
/* @0x112d84 ldr r3, [r4, #0x2c] */
/* @0x112d88 mov r1, #0 */
/* @0x112d8c ldr r2, [r4, #0x28] */
/* @0x112d90 str r1, [r5] */
/* @0x112d94 str r3, [r5, #0xc] */
/* @0x112d98 ldr r3, [r4, #0x2c] */
/* @0x112d9c str r2, [r5, #0x8] */
/* @0x112da0 bic r3, r3, #-16777216 */
/* @0x112da4 cmp r3, #14 */
/* @0x112da8 addls pc, pc, r3, lsl #2 */
/* @0x112dac b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x112db0 b 0x112e2c <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x112db4 b 0x112e8c <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x112db8 b 0x112e60 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x112dbc b 0x112dec <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x112dc0 b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x112dc4 b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x112dc8 b 0x112e3c <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x112dcc b 0x112dec <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x112dd0 b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x112dd4 b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x112dd8 b 0x112e2c <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x112ddc b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x112de0 b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x112de4 b 0x112e2c <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x112de8 b 0x112dec <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x112dec ldr r3, [r4, #0x20] */
/* @0x112df0 str r3, [r5] */
/* @0x112df4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x112df8 ldr r6, [r5] */
/* @0x112dfc cmp r6, #0 */
/* @0x112e00 beq 0x112e20 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x112e04 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x112e08 ldr r7, [r6, #0x4] */
/* @0x112e0c sub r7, r7, #1 */
/* @0x112e10 str r7, [r6, #0x4] */
/* @0x112e14 cmp r7, #0 */
/* @0x112e18 beq 0x112ea8 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x112e1c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x112e20 mov r3, #0 */
/* @0x112e24 str r3, [r5] */
/* @0x112e28 b 0x112d84 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x112e2c ldr r2, [r4, #0x20] */
/* @0x112e30 ldr r3, [r4, #0x24] */
/* @0x112e34 stm r5, {r2, r3} */
/* @0x112e38 pop {r3, r4, r5, r6, r7, pc} */
/* @0x112e3c ldr r3, [r4, #0x20] */
/* @0x112e40 str r3, [r5] */
/* @0x112e44 ldr r3, [r4, #0x20] */
/* @0x112e48 cmp r3, #0 */
/* @0x112e4c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x112e50 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x112e54 ldr r1, [r4, #0x20] */
/* @0x112e58 pop {r3, r4, r5, r6, r7, lr} */
/* @0x112e5c b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x112e60 ldr r3, [r4, #0x20] */
/* @0x112e64 cmp r3, #0 */
/* @0x112e68 str r3, [r5] */
/* @0x112e6c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x112e70 ldr r1, [r3, #0x8] */
/* @0x112e74 ldr r2, [r3] */
/* @0x112e78 cmp r1, #0 */
/* @0x112e7c streq r5, [r3, #0x8] */
/* @0x112e80 add r2, r2, #1 */
/* @0x112e84 str r2, [r3] */
/* @0x112e88 pop {r3, r4, r5, r6, r7, pc} */
/* @0x112e8c ldr r3, [r4, #0x20] */
/* @0x112e90 cmp r3, #0 */
/* @0x112e94 ldrne r2, [r3, #0x4] */
/* @0x112e98 addne r2, r2, #1 */
/* @0x112e9c strne r2, [r3, #0x4] */
/* @0x112ea0 b 0x112df0 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x112ea4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x112ea8 ldr r0, [r6] */
/* @0x112eac bl 0xcef90 <_Z6YYFreePKv> */
/* @0x112eb0 str r7, [r6] */
/* @0x112eb4 str r7, [r6, #0x8] */
/* @0x112eb8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x112ebc ldr r7, [r6, #0x4] */
/* @0x112ec0 sub r7, r7, #1 */
/* @0x112ec4 str r7, [r6, #0x4] */
/* @0x112ec8 cmp r7, #0 */
/* @0x112ecc beq 0x112eec <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x112ed0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x112ed4 mov r0, r6 */
/* @0x112ed8 bl 0x27d1d0 <_ZdlPv> */
/* @0x112edc b 0x112e1c <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x112ee0 mov r0, r5 */
/* @0x112ee4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x112ee8 b 0x112d74 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x112eec ldr r0, [r6] */
/* @0x112ef0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x112ef4 str r7, [r6] */
/* @0x112ef8 str r7, [r6, #0x8] */
/* @0x112efc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x112f00 ldr r7, [r6, #0x4] */
/* @0x112f04 sub r7, r7, #1 */
/* @0x112f08 str r7, [r6, #0x4] */
/* @0x112f0c cmp r7, #0 */
/* @0x112f10 bne 0x112f34 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x25c> */
/* @0x112f14 ldr r0, [r6] */
/* @0x112f18 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x112f1c mov r0, r6 */
/* @0x112f20 str r7, [r6] */
/* @0x112f24 str r7, [r6, #0x8] */
/* @0x112f28 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x112f2c mov r0, r6 */
/* @0x112f30 bl 0x27d1d0 <_ZdlPv> */
/* @0x112f34 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x112f38 mov r0, r6 */
/* @0x112f3c bl 0x27d1d0 <_ZdlPv> */
/* @0x112f40 b 0x112ed0 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x112f44 eoreq r6, r2, r0, ror #3 */
/* @0x112f48 .word 0x002261f8 */

/* ── FUNC 0x112f4c · F_ArraySet2DPre(RValue&, CInstance*, CInstance*, int, RValue*) · size=652 · insn=163 */
/* @0x112f4c cmp r3, #4 */
/* @0x112f50 push {r3, r4, r5, r6, r7, lr} */
/* @0x112f54 mov r5, r0 */
/* @0x112f58 ldr r4, [sp, #0x18] */
/* @0x112f5c beq 0x112f8c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x112f60 ldr r3, [r4, #0xc] */
/* @0x112f64 cmp r3, #2 */
/* @0x112f68 beq 0x112f7c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x112f6c ldr r0, [pc, #0x25c] */
/* @0x112f70 pop {r3, r4, r5, r6, r7, lr} */
/* @0x112f74 add r0, pc, r0 */
/* @0x112f78 b 0xd547c <_Z7YYErrorPKcz> */
/* @0x112f7c ldr r0, [pc, #0x250] */
/* @0x112f80 pop {r3, r4, r5, r6, r7, lr} */
/* @0x112f84 add r0, pc, r0 */
/* @0x112f88 b 0xd547c <_Z7YYErrorPKcz> */
/* @0x112f8c ldr r6, [r4, #0xc] */
/* @0x112f90 cmp r6, #2 */
/* @0x112f94 bne 0x112f6c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x20> */
/* @0x112f98 ldr r3, [r4] */
/* @0x112f9c cmp r3, #0 */
/* @0x112fa0 beq 0x112f7c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x112fa4 mov r1, #1 */
/* @0x112fa8 mov r0, r4 */
/* @0x112fac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x112fb0 mov r1, r6 */
/* @0x112fb4 mov r7, r0 */
/* @0x112fb8 mov r0, r4 */
/* @0x112fbc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x112fc0 mov r2, #32000 */
/* @0x112fc4 add r1, r4, #48 */
/* @0x112fc8 mla r2, r2, r7, r0 */
/* @0x112fcc mov r0, r4 */
/* @0x112fd0 bl 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i> */
/* @0x112fd4 ldr r2, [r5, #0xc] */
/* @0x112fd8 bic r3, r2, #-16777216 */
/* @0x112fdc cmp r3, #1 */
/* @0x112fe0 beq 0x113084 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x112fe4 cmp r3, #2 */
/* @0x112fe8 bne 0x113010 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x112fec sub r3, r2, #1 */
/* @0x112ff0 bic r3, r3, #-16777216 */
/* @0x112ff4 bic r3, r3, #3 */
/* @0x112ff8 cmp r3, #0 */
/* @0x112ffc beq 0x11316c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x113000 mov r2, #0 */
/* @0x113004 mov r3, #5 */
/* @0x113008 str r2, [r5, #0x8] */
/* @0x11300c str r3, [r5, #0xc] */
/* @0x113010 ldr r3, [r4, #0x3c] */
/* @0x113014 mov r1, #0 */
/* @0x113018 ldr r2, [r4, #0x38] */
/* @0x11301c str r1, [r5] */
/* @0x113020 str r3, [r5, #0xc] */
/* @0x113024 ldr r3, [r4, #0x3c] */
/* @0x113028 str r2, [r5, #0x8] */
/* @0x11302c bic r3, r3, #-16777216 */
/* @0x113030 cmp r3, #14 */
/* @0x113034 addls pc, pc, r3, lsl #2 */
/* @0x113038 b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x11303c b 0x1130b8 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x113040 b 0x113118 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x113044 b 0x1130ec <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x113048 b 0x113078 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x11304c b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113050 b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113054 b 0x1130c8 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x113058 b 0x113078 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x11305c b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113060 b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113064 b 0x1130b8 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x113068 b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x11306c b 0x113130 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113070 b 0x1130b8 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x113074 b 0x113078 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x113078 ldr r3, [r4, #0x30] */
/* @0x11307c str r3, [r5] */
/* @0x113080 pop {r3, r4, r5, r6, r7, pc} */
/* @0x113084 ldr r6, [r5] */
/* @0x113088 cmp r6, #0 */
/* @0x11308c beq 0x1130ac <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x113090 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113094 ldr r7, [r6, #0x4] */
/* @0x113098 sub r7, r7, #1 */
/* @0x11309c str r7, [r6, #0x4] */
/* @0x1130a0 cmp r7, #0 */
/* @0x1130a4 beq 0x113134 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x1130a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1130ac mov r3, #0 */
/* @0x1130b0 str r3, [r5] */
/* @0x1130b4 b 0x113010 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x1130b8 ldr r2, [r4, #0x30] */
/* @0x1130bc ldr r3, [r4, #0x34] */
/* @0x1130c0 stm r5, {r2, r3} */
/* @0x1130c4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1130c8 ldr r3, [r4, #0x30] */
/* @0x1130cc str r3, [r5] */
/* @0x1130d0 ldr r3, [r4, #0x30] */
/* @0x1130d4 cmp r3, #0 */
/* @0x1130d8 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1130dc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1130e0 ldr r1, [r4, #0x30] */
/* @0x1130e4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1130e8 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1130ec ldr r3, [r4, #0x30] */
/* @0x1130f0 cmp r3, #0 */
/* @0x1130f4 str r3, [r5] */
/* @0x1130f8 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1130fc ldr r1, [r3, #0x8] */
/* @0x113100 ldr r2, [r3] */
/* @0x113104 cmp r1, #0 */
/* @0x113108 streq r5, [r3, #0x8] */
/* @0x11310c add r2, r2, #1 */
/* @0x113110 str r2, [r3] */
/* @0x113114 pop {r3, r4, r5, r6, r7, pc} */
/* @0x113118 ldr r3, [r4, #0x30] */
/* @0x11311c cmp r3, #0 */
/* @0x113120 ldrne r2, [r3, #0x4] */
/* @0x113124 addne r2, r2, #1 */
/* @0x113128 strne r2, [r3, #0x4] */
/* @0x11312c b 0x11307c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x113130 pop {r3, r4, r5, r6, r7, pc} */
/* @0x113134 ldr r0, [r6] */
/* @0x113138 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x11313c str r7, [r6] */
/* @0x113140 str r7, [r6, #0x8] */
/* @0x113144 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113148 ldr r7, [r6, #0x4] */
/* @0x11314c sub r7, r7, #1 */
/* @0x113150 str r7, [r6, #0x4] */
/* @0x113154 cmp r7, #0 */
/* @0x113158 beq 0x113178 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x11315c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113160 mov r0, r6 */
/* @0x113164 bl 0x27d1d0 <_ZdlPv> */
/* @0x113168 b 0x1130a8 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x11316c mov r0, r5 */
/* @0x113170 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x113174 b 0x113000 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x113178 ldr r0, [r6] */
/* @0x11317c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113180 str r7, [r6] */
/* @0x113184 str r7, [r6, #0x8] */
/* @0x113188 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x11318c ldr r7, [r6, #0x4] */
/* @0x113190 sub r7, r7, #1 */
/* @0x113194 str r7, [r6, #0x4] */
/* @0x113198 cmp r7, #0 */
/* @0x11319c bne 0x1131c0 <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x1131a0 ldr r0, [r6] */
/* @0x1131a4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1131a8 mov r0, r6 */
/* @0x1131ac str r7, [r6] */
/* @0x1131b0 str r7, [r6, #0x8] */
/* @0x1131b4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1131b8 mov r0, r6 */
/* @0x1131bc bl 0x27d1d0 <_ZdlPv> */
/* @0x1131c0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1131c4 mov r0, r6 */
/* @0x1131c8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1131cc b 0x11315c <_Z15F_ArraySet2DPreR6RValueP9CInstanceS2_iPS_+0x210> */
/* @0x1131d0 .word 0x00225fb4 */
/* @0x1131d4 .word 0x00225fd0 */

/* ── FUNC 0x1131d8 · F_Min(RValue&, CInstance*, CInstance*, int, RValue*) · size=972 · insn=243 */
/* @0x1131d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1131dc vpush {d8, d9} */
/* @0x1131e0 subs r9, r3, #0 */
/* @0x1131e4 sub sp, sp, #12 */
/* @0x1131e8 mov r3, #0 */
/* @0x1131ec mov r4, r0 */
/* @0x1131f0 str r3, [r0, #0xc] */
/* @0x1131f4 ldr r8, [sp, #0x40] */
/* @0x1131f8 str r3, [r0] */
/* @0x1131fc str r3, [r0, #0x4] */
/* @0x113200 beq 0x11336c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x113204 ldr r1, [r8, #0xc] */
/* @0x113208 ldr r2, [r8, #0x8] */
/* @0x11320c str r1, [r0, #0xc] */
/* @0x113210 ldr r3, [r8, #0xc] */
/* @0x113214 str r2, [r0, #0x8] */
/* @0x113218 bic r3, r3, #-16777216 */
/* @0x11321c cmp r3, #14 */
/* @0x113220 addls pc, pc, r3, lsl #2 */
/* @0x113224 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113228 b 0x113488 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x11322c b 0x1134d4 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x113230 b 0x1134ec <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x314> */
/* @0x113234 b 0x113264 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x113238 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11323c b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113240 b 0x113518 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x340> */
/* @0x113244 b 0x113264 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x113248 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11324c b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113250 b 0x113488 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x113254 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113258 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11325c b 0x113488 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x113260 b 0x113264 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x113264 ldr r3, [r8] */
/* @0x113268 str r3, [r4] */
/* @0x11326c mov r0, r8 */
/* @0x113270 mov r1, #0 */
/* @0x113274 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x113278 cmp r9, #1 */
/* @0x11327c vmov d9, r0, r1 */
/* @0x113280 ble 0x11336c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x113284 mov r6, r8 */
/* @0x113288 mov r5, #1 */
/* @0x11328c mov r10, #0 */
/* @0x113290 mov r0, r8 */
/* @0x113294 mov r1, r5 */
/* @0x113298 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11329c vmov d8, r0, r1 */
/* @0x1132a0 vcmpe.f64 d8, d9 */
/* @0x1132a4 vmrs APSR_nzcv, fpscr */
/* @0x1132a8 addpl r7, r6, #16 */
/* @0x1132ac bpl 0x11335c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x1132b0 ldr r2, [r4, #0xc] */
/* @0x1132b4 add r7, r6, #16 */
/* @0x1132b8 bic r3, r2, #-16777216 */
/* @0x1132bc cmp r3, #1 */
/* @0x1132c0 beq 0x1133c4 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x1132c4 cmp r3, #2 */
/* @0x1132c8 bne 0x1132ec <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x1132cc sub r2, r2, #1 */
/* @0x1132d0 bic r2, r2, #-16777216 */
/* @0x1132d4 bic r2, r2, #3 */
/* @0x1132d8 cmp r2, #0 */
/* @0x1132dc beq 0x11347c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2a4> */
/* @0x1132e0 mov r3, #5 */
/* @0x1132e4 str r10, [r4, #0x8] */
/* @0x1132e8 str r3, [r4, #0xc] */
/* @0x1132ec str r10, [r4] */
/* @0x1132f0 ldr r3, [r6, #0x1c] */
/* @0x1132f4 str r3, [r4, #0xc] */
/* @0x1132f8 ldr r3, [r6, #0x18] */
/* @0x1132fc str r3, [r4, #0x8] */
/* @0x113300 ldr r3, [r6, #0x1c] */
/* @0x113304 bic r3, r3, #-16777216 */
/* @0x113308 cmp r3, #14 */
/* @0x11330c addls pc, pc, r3, lsl #2 */
/* @0x113310 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113314 b 0x113378 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x113318 b 0x11341c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x244> */
/* @0x11331c b 0x11338c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x113320 b 0x113350 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x113324 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113328 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x11332c b 0x1133f4 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x113330 b 0x113350 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x113334 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113338 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x11333c b 0x113378 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x113340 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113344 b 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113348 b 0x113378 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x11334c b 0x113350 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x113350 vmov.f64 d9, d8 */
/* @0x113354 ldr r3, [r6, #0x10] */
/* @0x113358 str r3, [r4] */
/* @0x11335c add r5, r5, #1 */
/* @0x113360 mov r6, r7 */
/* @0x113364 cmp r5, r9 */
/* @0x113368 bne 0x113290 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x11336c add sp, sp, #12 */
/* @0x113370 vpop {d8, d9} */
/* @0x113374 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x113378 ldr r2, [r7] */
/* @0x11337c vmov.f64 d9, d8 */
/* @0x113380 ldr r3, [r7, #0x4] */
/* @0x113384 stm r4, {r2, r3} */
/* @0x113388 b 0x11335c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x11338c ldr r3, [r6, #0x10] */
/* @0x113390 cmp r3, #0 */
/* @0x113394 str r3, [r4] */
/* @0x113398 beq 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x11339c ldr r1, [r3, #0x8] */
/* @0x1133a0 ldr r2, [r3] */
/* @0x1133a4 cmp r1, #0 */
/* @0x1133a8 streq r4, [r3, #0x8] */
/* @0x1133ac add r2, r2, #1 */
/* @0x1133b0 str r2, [r3] */
/* @0x1133b4 vmoveq.f64 d9, d8 */
/* @0x1133b8 beq 0x11335c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x1133bc vmov.f64 d9, d8 */
/* @0x1133c0 b 0x11335c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x1133c4 ldr r11, [r4] */
/* @0x1133c8 cmp r11, #0 */
/* @0x1133cc beq 0x1133ec <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x1133d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1133d4 ldr r2, [r11, #0x4] */
/* @0x1133d8 sub r2, r2, #1 */
/* @0x1133dc str r2, [r11, #0x4] */
/* @0x1133e0 cmp r2, #0 */
/* @0x1133e4 beq 0x11343c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x1133e8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1133ec str r10, [r4] */
/* @0x1133f0 b 0x1132ec <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x1133f4 ldr r3, [r6, #0x10] */
/* @0x1133f8 str r3, [r4] */
/* @0x1133fc ldr r3, [r6, #0x10] */
/* @0x113400 cmp r3, #0 */
/* @0x113404 beq 0x1133bc <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113408 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x11340c ldr r1, [r6, #0x10] */
/* @0x113410 vmov.f64 d9, d8 */
/* @0x113414 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x113418 b 0x11335c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x11341c ldr r3, [r6, #0x10] */
/* @0x113420 vmov.f64 d9, d8 */
/* @0x113424 cmp r3, #0 */
/* @0x113428 ldrne r2, [r3, #0x4] */
/* @0x11342c addne r2, r2, #1 */
/* @0x113430 strne r2, [r3, #0x4] */
/* @0x113434 str r3, [r4] */
/* @0x113438 b 0x11335c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x11343c ldr r0, [r11] */
/* @0x113440 str r2, [sp, #0x4] */
/* @0x113444 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113448 ldr r2, [sp, #0x4] */
/* @0x11344c str r2, [r11] */
/* @0x113450 str r2, [r11, #0x8] */
/* @0x113454 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113458 ldr r2, [r11, #0x4] */
/* @0x11345c sub r2, r2, #1 */
/* @0x113460 str r2, [r11, #0x4] */
/* @0x113464 cmp r2, #0 */
/* @0x113468 beq 0x113494 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2bc> */
/* @0x11346c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113470 mov r0, r11 */
/* @0x113474 bl 0x27d1d0 <_ZdlPv> */
/* @0x113478 b 0x1133e8 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x210> */
/* @0x11347c mov r0, r4 */
/* @0x113480 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x113484 b 0x1132e0 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x113488 ldm r8, {r2, r3} */
/* @0x11348c stm r0, {r2, r3} */
/* @0x113490 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113494 ldr r0, [r11] */
/* @0x113498 str r2, [sp, #0x4] */
/* @0x11349c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1134a0 ldr r2, [sp, #0x4] */
/* @0x1134a4 str r2, [r11] */
/* @0x1134a8 str r2, [r11, #0x8] */
/* @0x1134ac bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1134b0 ldr r2, [r11, #0x4] */
/* @0x1134b4 sub r2, r2, #1 */
/* @0x1134b8 str r2, [r11, #0x4] */
/* @0x1134bc cmp r2, #0 */
/* @0x1134c0 beq 0x11353c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x364> */
/* @0x1134c4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1134c8 mov r0, r11 */
/* @0x1134cc bl 0x27d1d0 <_ZdlPv> */
/* @0x1134d0 b 0x11346c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x294> */
/* @0x1134d4 ldr r3, [r8] */
/* @0x1134d8 cmp r3, #0 */
/* @0x1134dc ldrne r2, [r3, #0x4] */
/* @0x1134e0 addne r2, r2, #1 */
/* @0x1134e4 strne r2, [r3, #0x4] */
/* @0x1134e8 b 0x113268 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1134ec ldr r3, [r8] */
/* @0x1134f0 cmp r3, #0 */
/* @0x1134f4 str r3, [r0] */
/* @0x1134f8 beq 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1134fc ldr r1, [r3, #0x8] */
/* @0x113500 ldr r2, [r3] */
/* @0x113504 cmp r1, #0 */
/* @0x113508 streq r0, [r3, #0x8] */
/* @0x11350c add r2, r2, #1 */
/* @0x113510 str r2, [r3] */
/* @0x113514 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113518 ldr r3, [r8] */
/* @0x11351c str r3, [r0] */
/* @0x113520 ldr r3, [r8] */
/* @0x113524 cmp r3, #0 */
/* @0x113528 beq 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11352c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x113530 ldr r1, [r8] */
/* @0x113534 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x113538 b 0x11326c <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11353c ldr r0, [r11] */
/* @0x113540 str r2, [sp, #0x4] */
/* @0x113544 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113548 ldr r2, [sp, #0x4] */
/* @0x11354c str r2, [r11] */
/* @0x113550 str r2, [r11, #0x8] */
/* @0x113554 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113558 ldr r2, [r11, #0x4] */
/* @0x11355c sub r2, r2, #1 */
/* @0x113560 str r2, [r11, #0x4] */
/* @0x113564 cmp r2, #0 */
/* @0x113568 bne 0x113594 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x3bc> */
/* @0x11356c ldr r0, [r11] */
/* @0x113570 str r2, [sp, #0x4] */
/* @0x113574 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113578 ldr r2, [sp, #0x4] */
/* @0x11357c mov r0, r11 */
/* @0x113580 str r2, [r11] */
/* @0x113584 str r2, [r11, #0x8] */
/* @0x113588 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x11358c mov r0, r11 */
/* @0x113590 bl 0x27d1d0 <_ZdlPv> */
/* @0x113594 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113598 mov r0, r11 */
/* @0x11359c bl 0x27d1d0 <_ZdlPv> */
/* @0x1135a0 b 0x1134c4 <_Z5F_MinR6RValueP9CInstanceS2_iPS_+0x2ec> */

/* ── FUNC 0x1135a4 · F_Min3(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x1135a4 b 0x1131d8 <_Z5F_MinR6RValueP9CInstanceS2_iPS_> */

/* ── FUNC 0x1135a8 · F_Max(RValue&, CInstance*, CInstance*, int, RValue*) · size=972 · insn=243 */
/* @0x1135a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1135ac vpush {d8, d9} */
/* @0x1135b0 subs r9, r3, #0 */
/* @0x1135b4 sub sp, sp, #12 */
/* @0x1135b8 mov r3, #0 */
/* @0x1135bc mov r4, r0 */
/* @0x1135c0 str r3, [r0, #0xc] */
/* @0x1135c4 ldr r8, [sp, #0x40] */
/* @0x1135c8 str r3, [r0] */
/* @0x1135cc str r3, [r0, #0x4] */
/* @0x1135d0 beq 0x11373c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x1135d4 ldr r1, [r8, #0xc] */
/* @0x1135d8 ldr r2, [r8, #0x8] */
/* @0x1135dc str r1, [r0, #0xc] */
/* @0x1135e0 ldr r3, [r8, #0xc] */
/* @0x1135e4 str r2, [r0, #0x8] */
/* @0x1135e8 bic r3, r3, #-16777216 */
/* @0x1135ec cmp r3, #14 */
/* @0x1135f0 addls pc, pc, r3, lsl #2 */
/* @0x1135f4 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1135f8 b 0x113858 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x1135fc b 0x1138a4 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x113600 b 0x1138bc <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x314> */
/* @0x113604 b 0x113634 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x113608 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11360c b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113610 b 0x1138e8 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x340> */
/* @0x113614 b 0x113634 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x113618 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11361c b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113620 b 0x113858 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x113624 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113628 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11362c b 0x113858 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x113630 b 0x113634 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x113634 ldr r3, [r8] */
/* @0x113638 str r3, [r4] */
/* @0x11363c mov r0, r8 */
/* @0x113640 mov r1, #0 */
/* @0x113644 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x113648 cmp r9, #1 */
/* @0x11364c vmov d9, r0, r1 */
/* @0x113650 ble 0x11373c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x113654 mov r6, r8 */
/* @0x113658 mov r5, #1 */
/* @0x11365c mov r10, #0 */
/* @0x113660 mov r0, r8 */
/* @0x113664 mov r1, r5 */
/* @0x113668 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11366c vmov d8, r0, r1 */
/* @0x113670 vcmpe.f64 d8, d9 */
/* @0x113674 vmrs APSR_nzcv, fpscr */
/* @0x113678 addle r7, r6, #16 */
/* @0x11367c ble 0x11372c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x113680 ldr r2, [r4, #0xc] */
/* @0x113684 add r7, r6, #16 */
/* @0x113688 bic r3, r2, #-16777216 */
/* @0x11368c cmp r3, #1 */
/* @0x113690 beq 0x113794 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x113694 cmp r3, #2 */
/* @0x113698 bne 0x1136bc <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x11369c sub r2, r2, #1 */
/* @0x1136a0 bic r2, r2, #-16777216 */
/* @0x1136a4 bic r2, r2, #3 */
/* @0x1136a8 cmp r2, #0 */
/* @0x1136ac beq 0x11384c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2a4> */
/* @0x1136b0 mov r3, #5 */
/* @0x1136b4 str r10, [r4, #0x8] */
/* @0x1136b8 str r3, [r4, #0xc] */
/* @0x1136bc str r10, [r4] */
/* @0x1136c0 ldr r3, [r6, #0x1c] */
/* @0x1136c4 str r3, [r4, #0xc] */
/* @0x1136c8 ldr r3, [r6, #0x18] */
/* @0x1136cc str r3, [r4, #0x8] */
/* @0x1136d0 ldr r3, [r6, #0x1c] */
/* @0x1136d4 bic r3, r3, #-16777216 */
/* @0x1136d8 cmp r3, #14 */
/* @0x1136dc addls pc, pc, r3, lsl #2 */
/* @0x1136e0 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x1136e4 b 0x113748 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x1136e8 b 0x1137ec <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x244> */
/* @0x1136ec b 0x11375c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x1136f0 b 0x113720 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x1136f4 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x1136f8 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x1136fc b 0x1137c4 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x113700 b 0x113720 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x113704 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113708 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x11370c b 0x113748 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x113710 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113714 b 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x113718 b 0x113748 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x11371c b 0x113720 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x113720 vmov.f64 d9, d8 */
/* @0x113724 ldr r3, [r6, #0x10] */
/* @0x113728 str r3, [r4] */
/* @0x11372c add r5, r5, #1 */
/* @0x113730 mov r6, r7 */
/* @0x113734 cmp r5, r9 */
/* @0x113738 bne 0x113660 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x11373c add sp, sp, #12 */
/* @0x113740 vpop {d8, d9} */
/* @0x113744 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x113748 ldr r2, [r7] */
/* @0x11374c vmov.f64 d9, d8 */
/* @0x113750 ldr r3, [r7, #0x4] */
/* @0x113754 stm r4, {r2, r3} */
/* @0x113758 b 0x11372c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x11375c ldr r3, [r6, #0x10] */
/* @0x113760 cmp r3, #0 */
/* @0x113764 str r3, [r4] */
/* @0x113768 beq 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x11376c ldr r1, [r3, #0x8] */
/* @0x113770 ldr r2, [r3] */
/* @0x113774 cmp r1, #0 */
/* @0x113778 streq r4, [r3, #0x8] */
/* @0x11377c add r2, r2, #1 */
/* @0x113780 str r2, [r3] */
/* @0x113784 vmoveq.f64 d9, d8 */
/* @0x113788 beq 0x11372c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x11378c vmov.f64 d9, d8 */
/* @0x113790 b 0x11372c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x113794 ldr r11, [r4] */
/* @0x113798 cmp r11, #0 */
/* @0x11379c beq 0x1137bc <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x1137a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1137a4 ldr r2, [r11, #0x4] */
/* @0x1137a8 sub r2, r2, #1 */
/* @0x1137ac str r2, [r11, #0x4] */
/* @0x1137b0 cmp r2, #0 */
/* @0x1137b4 beq 0x11380c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x1137b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1137bc str r10, [r4] */
/* @0x1137c0 b 0x1136bc <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x1137c4 ldr r3, [r6, #0x10] */
/* @0x1137c8 str r3, [r4] */
/* @0x1137cc ldr r3, [r6, #0x10] */
/* @0x1137d0 cmp r3, #0 */
/* @0x1137d4 beq 0x11378c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x1137d8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1137dc ldr r1, [r6, #0x10] */
/* @0x1137e0 vmov.f64 d9, d8 */
/* @0x1137e4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1137e8 b 0x11372c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x1137ec ldr r3, [r6, #0x10] */
/* @0x1137f0 vmov.f64 d9, d8 */
/* @0x1137f4 cmp r3, #0 */
/* @0x1137f8 ldrne r2, [r3, #0x4] */
/* @0x1137fc addne r2, r2, #1 */
/* @0x113800 strne r2, [r3, #0x4] */
/* @0x113804 str r3, [r4] */
/* @0x113808 b 0x11372c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x11380c ldr r0, [r11] */
/* @0x113810 str r2, [sp, #0x4] */
/* @0x113814 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113818 ldr r2, [sp, #0x4] */
/* @0x11381c str r2, [r11] */
/* @0x113820 str r2, [r11, #0x8] */
/* @0x113824 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113828 ldr r2, [r11, #0x4] */
/* @0x11382c sub r2, r2, #1 */
/* @0x113830 str r2, [r11, #0x4] */
/* @0x113834 cmp r2, #0 */
/* @0x113838 beq 0x113864 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2bc> */
/* @0x11383c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113840 mov r0, r11 */
/* @0x113844 bl 0x27d1d0 <_ZdlPv> */
/* @0x113848 b 0x1137b8 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x210> */
/* @0x11384c mov r0, r4 */
/* @0x113850 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x113854 b 0x1136b0 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x113858 ldm r8, {r2, r3} */
/* @0x11385c stm r0, {r2, r3} */
/* @0x113860 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x113864 ldr r0, [r11] */
/* @0x113868 str r2, [sp, #0x4] */
/* @0x11386c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113870 ldr r2, [sp, #0x4] */
/* @0x113874 str r2, [r11] */
/* @0x113878 str r2, [r11, #0x8] */
/* @0x11387c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113880 ldr r2, [r11, #0x4] */
/* @0x113884 sub r2, r2, #1 */
/* @0x113888 str r2, [r11, #0x4] */
/* @0x11388c cmp r2, #0 */
/* @0x113890 beq 0x11390c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x364> */
/* @0x113894 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113898 mov r0, r11 */
/* @0x11389c bl 0x27d1d0 <_ZdlPv> */
/* @0x1138a0 b 0x11383c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x294> */
/* @0x1138a4 ldr r3, [r8] */
/* @0x1138a8 cmp r3, #0 */
/* @0x1138ac ldrne r2, [r3, #0x4] */
/* @0x1138b0 addne r2, r2, #1 */
/* @0x1138b4 strne r2, [r3, #0x4] */
/* @0x1138b8 b 0x113638 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1138bc ldr r3, [r8] */
/* @0x1138c0 cmp r3, #0 */
/* @0x1138c4 str r3, [r0] */
/* @0x1138c8 beq 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1138cc ldr r1, [r3, #0x8] */
/* @0x1138d0 ldr r2, [r3] */
/* @0x1138d4 cmp r1, #0 */
/* @0x1138d8 streq r0, [r3, #0x8] */
/* @0x1138dc add r2, r2, #1 */
/* @0x1138e0 str r2, [r3] */
/* @0x1138e4 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1138e8 ldr r3, [r8] */
/* @0x1138ec str r3, [r0] */
/* @0x1138f0 ldr r3, [r8] */
/* @0x1138f4 cmp r3, #0 */
/* @0x1138f8 beq 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1138fc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x113900 ldr r1, [r8] */
/* @0x113904 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x113908 b 0x11363c <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x11390c ldr r0, [r11] */
/* @0x113910 str r2, [sp, #0x4] */
/* @0x113914 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113918 ldr r2, [sp, #0x4] */
/* @0x11391c str r2, [r11] */
/* @0x113920 str r2, [r11, #0x8] */
/* @0x113924 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113928 ldr r2, [r11, #0x4] */
/* @0x11392c sub r2, r2, #1 */
/* @0x113930 str r2, [r11, #0x4] */
/* @0x113934 cmp r2, #0 */
/* @0x113938 bne 0x113964 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x3bc> */
/* @0x11393c ldr r0, [r11] */
/* @0x113940 str r2, [sp, #0x4] */
/* @0x113944 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113948 ldr r2, [sp, #0x4] */
/* @0x11394c mov r0, r11 */
/* @0x113950 str r2, [r11] */
/* @0x113954 str r2, [r11, #0x8] */
/* @0x113958 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x11395c mov r0, r11 */
/* @0x113960 bl 0x27d1d0 <_ZdlPv> */
/* @0x113964 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113968 mov r0, r11 */
/* @0x11396c bl 0x27d1d0 <_ZdlPv> */
/* @0x113970 b 0x113894 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_+0x2ec> */

/* ── FUNC 0x113974 · F_Max3(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x113974 b 0x1135a8 <_Z5F_MaxR6RValueP9CInstanceS2_iPS_> */

/* ── FUNC 0x113978 · F_Choose(RValue&, CInstance*, CInstance*, int, RValue*) · size=668 · insn=167 */
/* @0x113978 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x11397c subs r5, r3, #0 */
/* @0x113980 mov r2, #0 */
/* @0x113984 mov r4, r0 */
/* @0x113988 ldr r6, [sp, #0x20] */
/* @0x11398c str r2, [r0, #0xc] */
/* @0x113990 str r2, [r0] */
/* @0x113994 str r2, [r0, #0x4] */
/* @0x113998 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x11399c mov r0, r5 */
/* @0x1139a0 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1139a4 vldr s15, [pc, #612] */
/* @0x1139a8 vmov s12, r0 */
/* @0x1139ac vcvt.f32.u32 s14, s12 */
/* @0x1139b0 vadd.f32 s15, s14, s15 */
/* @0x1139b4 vcvt.f64.f32 d6, s15 */
/* @0x1139b8 vmov r0, r1, d6 */
/* @0x1139bc bl 0xb6598 <floor@plt> */
/* @0x1139c0 ldr r2, [r4, #0xc] */
/* @0x1139c4 bic r3, r2, #-16777216 */
/* @0x1139c8 vmov d7, r0, r1 */
/* @0x1139cc vcvt.s32.f64 s15, d7 */
/* @0x1139d0 vmov r0, s15 */
/* @0x1139d4 cmp r5, r0 */
/* @0x1139d8 suble r0, r5, #1 */
/* @0x1139dc cmp r3, #1 */
/* @0x1139e0 lsl r7, r0, #4 */
/* @0x1139e4 add r5, r6, r7 */
/* @0x1139e8 beq 0x113a9c <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1139ec cmp r3, #2 */
/* @0x1139f0 bne 0x113a18 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1139f4 sub r2, r2, #1 */
/* @0x1139f8 bic r2, r2, #-16777216 */
/* @0x1139fc bic r2, r2, #3 */
/* @0x113a00 cmp r2, #0 */
/* @0x113a04 beq 0x113b70 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x113a08 mov r2, #0 */
/* @0x113a0c mov r3, #5 */
/* @0x113a10 str r2, [r4, #0x8] */
/* @0x113a14 str r3, [r4, #0xc] */
/* @0x113a18 ldr r3, [r5, #0xc] */
/* @0x113a1c mov r1, #0 */
/* @0x113a20 ldr r2, [r5, #0x8] */
/* @0x113a24 str r1, [r4] */
/* @0x113a28 str r3, [r4, #0xc] */
/* @0x113a2c ldr r3, [r5, #0xc] */
/* @0x113a30 str r2, [r4, #0x8] */
/* @0x113a34 bic r3, r3, #-16777216 */
/* @0x113a38 cmp r3, #14 */
/* @0x113a3c addls pc, pc, r3, lsl #2 */
/* @0x113a40 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a44 b 0x113a8c <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x113a48 b 0x113af4 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x113a4c b 0x113b0c <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x113a50 b 0x113a80 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x113a54 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a58 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a5c b 0x113ad0 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x113a60 b 0x113a80 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x113a64 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a68 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a6c b 0x113a8c <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x113a70 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a74 b 0x113a88 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x113a78 b 0x113a8c <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x113a7c b 0x113a80 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x113a80 ldr r3, [r6, r7] */
/* @0x113a84 str r3, [r4] */
/* @0x113a88 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x113a8c ldr r2, [r6, r7] */
/* @0x113a90 ldr r3, [r5, #0x4] */
/* @0x113a94 stm r4, {r2, r3} */
/* @0x113a98 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x113a9c ldr r8, [r4] */
/* @0x113aa0 cmp r8, #0 */
/* @0x113aa4 beq 0x113ac4 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x113aa8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113aac ldr r9, [r8, #0x4] */
/* @0x113ab0 sub r9, r9, #1 */
/* @0x113ab4 str r9, [r8, #0x4] */
/* @0x113ab8 cmp r9, #0 */
/* @0x113abc beq 0x113b38 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x1c0> */
/* @0x113ac0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113ac4 mov r3, #0 */
/* @0x113ac8 str r3, [r4] */
/* @0x113acc b 0x113a18 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x113ad0 ldr r3, [r6, r7] */
/* @0x113ad4 str r3, [r4] */
/* @0x113ad8 ldr r3, [r6, r7] */
/* @0x113adc cmp r3, #0 */
/* @0x113ae0 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x113ae4 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x113ae8 ldr r1, [r6, r7] */
/* @0x113aec pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x113af0 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x113af4 ldr r3, [r6, r7] */
/* @0x113af8 cmp r3, #0 */
/* @0x113afc ldrne r2, [r3, #0x4] */
/* @0x113b00 addne r2, r2, #1 */
/* @0x113b04 strne r2, [r3, #0x4] */
/* @0x113b08 b 0x113a84 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x113b0c ldr r3, [r6, r7] */
/* @0x113b10 cmp r3, #0 */
/* @0x113b14 str r3, [r4] */
/* @0x113b18 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x113b1c ldr r1, [r3, #0x8] */
/* @0x113b20 ldr r2, [r3] */
/* @0x113b24 cmp r1, #0 */
/* @0x113b28 streq r4, [r3, #0x8] */
/* @0x113b2c add r2, r2, #1 */
/* @0x113b30 str r2, [r3] */
/* @0x113b34 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x113b38 ldr r0, [r8] */
/* @0x113b3c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113b40 str r9, [r8] */
/* @0x113b44 str r9, [r8, #0x8] */
/* @0x113b48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113b4c ldr r9, [r8, #0x4] */
/* @0x113b50 sub r9, r9, #1 */
/* @0x113b54 str r9, [r8, #0x4] */
/* @0x113b58 cmp r9, #0 */
/* @0x113b5c beq 0x113b7c <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x113b60 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113b64 mov r0, r8 */
/* @0x113b68 bl 0x27d1d0 <_ZdlPv> */
/* @0x113b6c b 0x113ac0 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x113b70 mov r0, r4 */
/* @0x113b74 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x113b78 b 0x113a08 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x113b7c ldr r0, [r8] */
/* @0x113b80 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113b84 str r9, [r8] */
/* @0x113b88 str r9, [r8, #0x8] */
/* @0x113b8c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113b90 ldr r9, [r8, #0x4] */
/* @0x113b94 sub r9, r9, #1 */
/* @0x113b98 str r9, [r8, #0x4] */
/* @0x113b9c cmp r9, #0 */
/* @0x113ba0 beq 0x113bb4 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x113ba4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113ba8 mov r0, r8 */
/* @0x113bac bl 0x27d1d0 <_ZdlPv> */
/* @0x113bb0 b 0x113b60 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x113bb4 ldr r0, [r8] */
/* @0x113bb8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113bbc str r9, [r8] */
/* @0x113bc0 str r9, [r8, #0x8] */
/* @0x113bc4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113bc8 ldr r9, [r8, #0x4] */
/* @0x113bcc sub r9, r9, #1 */
/* @0x113bd0 str r9, [r8, #0x4] */
/* @0x113bd4 cmp r9, #0 */
/* @0x113bd8 beq 0x113bec <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x113bdc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113be0 mov r0, r8 */
/* @0x113be4 bl 0x27d1d0 <_ZdlPv> */
/* @0x113be8 b 0x113ba4 <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x113bec ldr r0, [r8] */
/* @0x113bf0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113bf4 mov r0, r8 */
/* @0x113bf8 str r9, [r8] */
/* @0x113bfc str r9, [r8, #0x8] */
/* @0x113c00 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x113c04 mov r0, r8 */
/* @0x113c08 bl 0x27d1d0 <_ZdlPv> */
/* @0x113c0c b 0x113bdc <_Z8F_ChooseR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x113c10 andeq r0, r0, r0 */

/* ── FUNC 0x113c14 · YYGML_min(YYRValue&, int, YYRValue**) · size=972 · insn=243 */
/* @0x113c14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x113c18 vpush {d8, d9} */
/* @0x113c1c subs r8, r1, #0 */
/* @0x113c20 mov r3, #0 */
/* @0x113c24 sub sp, sp, #12 */
/* @0x113c28 mov r4, r0 */
/* @0x113c2c mov r7, r2 */
/* @0x113c30 str r3, [r0, #0xc] */
/* @0x113c34 str r3, [r0] */
/* @0x113c38 str r3, [r0, #0x4] */
/* @0x113c3c beq 0x113da4 <_Z9YYGML_minR8YYRValueiPPS_+0x190> */
/* @0x113c40 ldr r5, [r2] */
/* @0x113c44 ldr r3, [r5, #0xc] */
/* @0x113c48 ldr r2, [r5, #0x8] */
/* @0x113c4c str r3, [r0, #0xc] */
/* @0x113c50 ldr r3, [r5, #0xc] */
/* @0x113c54 str r2, [r0, #0x8] */
/* @0x113c58 bic r3, r3, #-16777216 */
/* @0x113c5c cmp r3, #14 */
/* @0x113c60 addls pc, pc, r3, lsl #2 */
/* @0x113c64 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98> */
/* @0x113c68 b 0x113ec4 <_Z9YYGML_minR8YYRValueiPPS_+0x2b0> */
/* @0x113c6c b 0x113f10 <_Z9YYGML_minR8YYRValueiPPS_+0x2fc> */
/* @0x113c70 b 0x113f28 <_Z9YYGML_minR8YYRValueiPPS_+0x314> */
/* @0x113c74 b 0x113ca4 <_Z9YYGML_minR8YYRValueiPPS_+0x90> */
/* @0x113c78 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98> */
/* @0x113c7c b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98> */
/* @0x113c80 b 0x113f54 <_Z9YYGML_minR8YYRValueiPPS_+0x340> */
/* @0x113c84 b 0x113ca4 <_Z9YYGML_minR8YYRValueiPPS_+0x90> */
/* @0x113c88 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98> */
/* @0x113c8c b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98> */
/* @0x113c90 b 0x113ec4 <_Z9YYGML_minR8YYRValueiPPS_+0x2b0> */
/* @0x113c94 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98> */
/* @0x113c98 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98> */
/* @0x113c9c b 0x113ec4 <_Z9YYGML_minR8YYRValueiPPS_+0x2b0> */
/* @0x113ca0 b 0x113ca4 <_Z9YYGML_minR8YYRValueiPPS_+0x90> */
/* @0x113ca4 ldr r3, [r5] */
/* @0x113ca8 str r3, [r4] */
/* @0x113cac ldr r0, [r7] */
/* @0x113cb0 mov r1, #0 */
/* @0x113cb4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x113cb8 cmp r8, #1 */
/* @0x113cbc vmov d9, r0, r1 */
/* @0x113cc0 ble 0x113da4 <_Z9YYGML_minR8YYRValueiPPS_+0x190> */
/* @0x113cc4 add r7, r7, #4 */
/* @0x113cc8 mov r5, #1 */
/* @0x113ccc mov r9, #0 */
/* @0x113cd0 mov r10, #5 */
/* @0x113cd4 ldr r0, [r7], #4 */
/* @0x113cd8 mov r1, #0 */
/* @0x113cdc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x113ce0 vmov d8, r0, r1 */
/* @0x113ce4 vcmpe.f64 d8, d9 */
/* @0x113ce8 vmrs APSR_nzcv, fpscr */
/* @0x113cec bpl 0x113d98 <_Z9YYGML_minR8YYRValueiPPS_+0x184> */
/* @0x113cf0 ldr r2, [r4, #0xc] */
/* @0x113cf4 ldr r6, [r7, #-0x4] */
/* @0x113cf8 bic r3, r2, #-16777216 */
/* @0x113cfc cmp r3, #1 */
/* @0x113d00 beq 0x113e00 <_Z9YYGML_minR8YYRValueiPPS_+0x1ec> */
/* @0x113d04 cmp r3, #2 */
/* @0x113d08 bne 0x113d28 <_Z9YYGML_minR8YYRValueiPPS_+0x114> */
/* @0x113d0c sub r2, r2, #1 */
/* @0x113d10 bic r2, r2, #-16777216 */
/* @0x113d14 bic r2, r2, #3 */
/* @0x113d18 cmp r2, #0 */
/* @0x113d1c beq 0x113eb8 <_Z9YYGML_minR8YYRValueiPPS_+0x2a4> */
/* @0x113d20 str r9, [r4, #0x8] */
/* @0x113d24 str r10, [r4, #0xc] */
/* @0x113d28 ldr r3, [r6, #0xc] */
/* @0x113d2c ldr r2, [r6, #0x8] */
/* @0x113d30 str r9, [r4] */
/* @0x113d34 str r3, [r4, #0xc] */
/* @0x113d38 ldr r3, [r6, #0xc] */
/* @0x113d3c str r2, [r4, #0x8] */
/* @0x113d40 bic r3, r3, #-16777216 */
/* @0x113d44 cmp r3, #14 */
/* @0x113d48 addls pc, pc, r3, lsl #2 */
/* @0x113d4c b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4> */
/* @0x113d50 b 0x113db4 <_Z9YYGML_minR8YYRValueiPPS_+0x1a0> */
/* @0x113d54 b 0x113e58 <_Z9YYGML_minR8YYRValueiPPS_+0x244> */
/* @0x113d58 b 0x113dc8 <_Z9YYGML_minR8YYRValueiPPS_+0x1b4> */
/* @0x113d5c b 0x113d8c <_Z9YYGML_minR8YYRValueiPPS_+0x178> */
/* @0x113d60 b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4> */
/* @0x113d64 b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4> */
/* @0x113d68 b 0x113e30 <_Z9YYGML_minR8YYRValueiPPS_+0x21c> */
/* @0x113d6c b 0x113d8c <_Z9YYGML_minR8YYRValueiPPS_+0x178> */
/* @0x113d70 b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4> */
/* @0x113d74 b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4> */
/* @0x113d78 b 0x113db4 <_Z9YYGML_minR8YYRValueiPPS_+0x1a0> */
/* @0x113d7c b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4> */
/* @0x113d80 b 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4> */
/* @0x113d84 b 0x113db4 <_Z9YYGML_minR8YYRValueiPPS_+0x1a0> */
/* @0x113d88 b 0x113d8c <_Z9YYGML_minR8YYRValueiPPS_+0x178> */
/* @0x113d8c vmov.f64 d9, d8 */
/* @0x113d90 ldr r3, [r6] */
/* @0x113d94 str r3, [r4] */
/* @0x113d98 add r5, r5, #1 */
/* @0x113d9c cmp r5, r8 */
/* @0x113da0 bne 0x113cd4 <_Z9YYGML_minR8YYRValueiPPS_+0xc0> */
/* @0x113da4 mov r0, r4 */
/* @0x113da8 add sp, sp, #12 */
/* @0x113dac vpop {d8, d9} */
/* @0x113db0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x113db4 ldr r2, [r6] */
/* @0x113db8 vmov.f64 d9, d8 */
/* @0x113dbc ldr r3, [r6, #0x4] */
/* @0x113dc0 stm r4, {r2, r3} */
/* @0x113dc4 b 0x113d98 <_Z9YYGML_minR8YYRValueiPPS_+0x184> */
/* @0x113dc8 ldr r3, [r6] */
/* @0x113dcc cmp r3, #0 */
/* @0x113dd0 str r3, [r4] */
/* @0x113dd4 beq 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4> */
/* @0x113dd8 ldr r1, [r3, #0x8] */
/* @0x113ddc ldr r2, [r3] */
/* @0x113de0 cmp r1, #0 */
/* @0x113de4 streq r4, [r3, #0x8] */
/* @0x113de8 add r2, r2, #1 */
/* @0x113dec str r2, [r3] */
/* @0x113df0 vmoveq.f64 d9, d8 */
/* @0x113df4 beq 0x113d98 <_Z9YYGML_minR8YYRValueiPPS_+0x184> */
/* @0x113df8 vmov.f64 d9, d8 */
/* @0x113dfc b 0x113d98 <_Z9YYGML_minR8YYRValueiPPS_+0x184> */
/* @0x113e00 ldr r11, [r4] */
/* @0x113e04 cmp r11, #0 */
/* @0x113e08 beq 0x113e28 <_Z9YYGML_minR8YYRValueiPPS_+0x214> */
/* @0x113e0c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113e10 ldr r3, [r11, #0x4] */
/* @0x113e14 sub r3, r3, #1 */
/* @0x113e18 str r3, [r11, #0x4] */
/* @0x113e1c cmp r3, #0 */
/* @0x113e20 beq 0x113e78 <_Z9YYGML_minR8YYRValueiPPS_+0x264> */
/* @0x113e24 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113e28 str r9, [r4] */
/* @0x113e2c b 0x113d28 <_Z9YYGML_minR8YYRValueiPPS_+0x114> */
/* @0x113e30 ldr r3, [r6] */
/* @0x113e34 str r3, [r4] */
/* @0x113e38 ldr r3, [r6] */
/* @0x113e3c cmp r3, #0 */
/* @0x113e40 beq 0x113df8 <_Z9YYGML_minR8YYRValueiPPS_+0x1e4> */
/* @0x113e44 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x113e48 ldr r1, [r6] */
/* @0x113e4c vmov.f64 d9, d8 */
/* @0x113e50 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x113e54 b 0x113d98 <_Z9YYGML_minR8YYRValueiPPS_+0x184> */
/* @0x113e58 ldr r3, [r6] */
/* @0x113e5c vmov.f64 d9, d8 */
/* @0x113e60 cmp r3, #0 */
/* @0x113e64 ldrne r2, [r3, #0x4] */
/* @0x113e68 addne r2, r2, #1 */
/* @0x113e6c strne r2, [r3, #0x4] */
/* @0x113e70 str r3, [r4] */
/* @0x113e74 b 0x113d98 <_Z9YYGML_minR8YYRValueiPPS_+0x184> */
/* @0x113e78 ldr r0, [r11] */
/* @0x113e7c str r3, [sp, #0x4] */
/* @0x113e80 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113e84 ldr r3, [sp, #0x4] */
/* @0x113e88 str r3, [r11] */
/* @0x113e8c str r3, [r11, #0x8] */
/* @0x113e90 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113e94 ldr r3, [r11, #0x4] */
/* @0x113e98 sub r3, r3, #1 */
/* @0x113e9c str r3, [r11, #0x4] */
/* @0x113ea0 cmp r3, #0 */
/* @0x113ea4 beq 0x113ed0 <_Z9YYGML_minR8YYRValueiPPS_+0x2bc> */
/* @0x113ea8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113eac mov r0, r11 */
/* @0x113eb0 bl 0x27d1d0 <_ZdlPv> */
/* @0x113eb4 b 0x113e24 <_Z9YYGML_minR8YYRValueiPPS_+0x210> */
/* @0x113eb8 mov r0, r4 */
/* @0x113ebc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x113ec0 b 0x113d20 <_Z9YYGML_minR8YYRValueiPPS_+0x10c> */
/* @0x113ec4 ldm r5, {r2, r3} */
/* @0x113ec8 stm r0, {r2, r3} */
/* @0x113ecc b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98> */
/* @0x113ed0 ldr r0, [r11] */
/* @0x113ed4 str r3, [sp, #0x4] */
/* @0x113ed8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113edc ldr r3, [sp, #0x4] */
/* @0x113ee0 str r3, [r11] */
/* @0x113ee4 str r3, [r11, #0x8] */
/* @0x113ee8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113eec ldr r3, [r11, #0x4] */
/* @0x113ef0 sub r3, r3, #1 */
/* @0x113ef4 str r3, [r11, #0x4] */
/* @0x113ef8 cmp r3, #0 */
/* @0x113efc beq 0x113f78 <_Z9YYGML_minR8YYRValueiPPS_+0x364> */
/* @0x113f00 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113f04 mov r0, r11 */
/* @0x113f08 bl 0x27d1d0 <_ZdlPv> */
/* @0x113f0c b 0x113ea8 <_Z9YYGML_minR8YYRValueiPPS_+0x294> */
/* @0x113f10 ldr r3, [r5] */
/* @0x113f14 cmp r3, #0 */
/* @0x113f18 ldrne r2, [r3, #0x4] */
/* @0x113f1c addne r2, r2, #1 */
/* @0x113f20 strne r2, [r3, #0x4] */
/* @0x113f24 b 0x113ca8 <_Z9YYGML_minR8YYRValueiPPS_+0x94> */
/* @0x113f28 ldr r3, [r5] */
/* @0x113f2c cmp r3, #0 */
/* @0x113f30 str r3, [r0] */
/* @0x113f34 beq 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98> */
/* @0x113f38 ldr r1, [r3, #0x8] */
/* @0x113f3c ldr r2, [r3] */
/* @0x113f40 cmp r1, #0 */
/* @0x113f44 streq r0, [r3, #0x8] */
/* @0x113f48 add r2, r2, #1 */
/* @0x113f4c str r2, [r3] */
/* @0x113f50 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98> */
/* @0x113f54 ldr r3, [r5] */
/* @0x113f58 str r3, [r0] */
/* @0x113f5c ldr r3, [r5] */
/* @0x113f60 cmp r3, #0 */
/* @0x113f64 beq 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98> */
/* @0x113f68 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x113f6c ldr r1, [r5] */
/* @0x113f70 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x113f74 b 0x113cac <_Z9YYGML_minR8YYRValueiPPS_+0x98> */
/* @0x113f78 ldr r0, [r11] */
/* @0x113f7c str r3, [sp, #0x4] */
/* @0x113f80 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113f84 ldr r3, [sp, #0x4] */
/* @0x113f88 str r3, [r11] */
/* @0x113f8c str r3, [r11, #0x8] */
/* @0x113f90 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x113f94 ldr r3, [r11, #0x4] */
/* @0x113f98 sub r3, r3, #1 */
/* @0x113f9c str r3, [r11, #0x4] */
/* @0x113fa0 cmp r3, #0 */
/* @0x113fa4 bne 0x113fd0 <_Z9YYGML_minR8YYRValueiPPS_+0x3bc> */
/* @0x113fa8 ldr r0, [r11] */
/* @0x113fac str r3, [sp, #0x4] */
/* @0x113fb0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x113fb4 ldr r3, [sp, #0x4] */
/* @0x113fb8 mov r0, r11 */
/* @0x113fbc str r3, [r11] */
/* @0x113fc0 str r3, [r11, #0x8] */
/* @0x113fc4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x113fc8 mov r0, r11 */
/* @0x113fcc bl 0x27d1d0 <_ZdlPv> */
/* @0x113fd0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x113fd4 mov r0, r11 */
/* @0x113fd8 bl 0x27d1d0 <_ZdlPv> */
/* @0x113fdc b 0x113f00 <_Z9YYGML_minR8YYRValueiPPS_+0x2ec> */

/* ── FUNC 0x113fe0 · YYGML_max(YYRValue&, int, YYRValue**) · size=972 · insn=243 */
/* @0x113fe0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x113fe4 vpush {d8, d9} */
/* @0x113fe8 subs r8, r1, #0 */
/* @0x113fec mov r3, #0 */
/* @0x113ff0 sub sp, sp, #12 */
/* @0x113ff4 mov r4, r0 */
/* @0x113ff8 mov r7, r2 */
/* @0x113ffc str r3, [r0, #0xc] */
/* @0x114000 str r3, [r0] */
/* @0x114004 str r3, [r0, #0x4] */
/* @0x114008 beq 0x114170 <_Z9YYGML_maxR8YYRValueiPPS_+0x190> */
/* @0x11400c ldr r5, [r2] */
/* @0x114010 ldr r3, [r5, #0xc] */
/* @0x114014 ldr r2, [r5, #0x8] */
/* @0x114018 str r3, [r0, #0xc] */
/* @0x11401c ldr r3, [r5, #0xc] */
/* @0x114020 str r2, [r0, #0x8] */
/* @0x114024 bic r3, r3, #-16777216 */
/* @0x114028 cmp r3, #14 */
/* @0x11402c addls pc, pc, r3, lsl #2 */
/* @0x114030 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98> */
/* @0x114034 b 0x114290 <_Z9YYGML_maxR8YYRValueiPPS_+0x2b0> */
/* @0x114038 b 0x1142dc <_Z9YYGML_maxR8YYRValueiPPS_+0x2fc> */
/* @0x11403c b 0x1142f4 <_Z9YYGML_maxR8YYRValueiPPS_+0x314> */
/* @0x114040 b 0x114070 <_Z9YYGML_maxR8YYRValueiPPS_+0x90> */
/* @0x114044 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98> */
/* @0x114048 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98> */
/* @0x11404c b 0x114320 <_Z9YYGML_maxR8YYRValueiPPS_+0x340> */
/* @0x114050 b 0x114070 <_Z9YYGML_maxR8YYRValueiPPS_+0x90> */
/* @0x114054 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98> */
/* @0x114058 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98> */
/* @0x11405c b 0x114290 <_Z9YYGML_maxR8YYRValueiPPS_+0x2b0> */
/* @0x114060 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98> */
/* @0x114064 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98> */
/* @0x114068 b 0x114290 <_Z9YYGML_maxR8YYRValueiPPS_+0x2b0> */
/* @0x11406c b 0x114070 <_Z9YYGML_maxR8YYRValueiPPS_+0x90> */
/* @0x114070 ldr r3, [r5] */
/* @0x114074 str r3, [r4] */
/* @0x114078 ldr r0, [r7] */
/* @0x11407c mov r1, #0 */
/* @0x114080 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x114084 cmp r8, #1 */
/* @0x114088 vmov d9, r0, r1 */
/* @0x11408c ble 0x114170 <_Z9YYGML_maxR8YYRValueiPPS_+0x190> */
/* @0x114090 add r7, r7, #4 */
/* @0x114094 mov r5, #1 */
/* @0x114098 mov r9, #0 */
/* @0x11409c mov r10, #5 */
/* @0x1140a0 ldr r0, [r7], #4 */
/* @0x1140a4 mov r1, #0 */
/* @0x1140a8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1140ac vmov d8, r0, r1 */
/* @0x1140b0 vcmpe.f64 d8, d9 */
/* @0x1140b4 vmrs APSR_nzcv, fpscr */
/* @0x1140b8 ble 0x114164 <_Z9YYGML_maxR8YYRValueiPPS_+0x184> */
/* @0x1140bc ldr r2, [r4, #0xc] */
/* @0x1140c0 ldr r6, [r7, #-0x4] */
/* @0x1140c4 bic r3, r2, #-16777216 */
/* @0x1140c8 cmp r3, #1 */
/* @0x1140cc beq 0x1141cc <_Z9YYGML_maxR8YYRValueiPPS_+0x1ec> */
/* @0x1140d0 cmp r3, #2 */
/* @0x1140d4 bne 0x1140f4 <_Z9YYGML_maxR8YYRValueiPPS_+0x114> */
/* @0x1140d8 sub r2, r2, #1 */
/* @0x1140dc bic r2, r2, #-16777216 */
/* @0x1140e0 bic r2, r2, #3 */
/* @0x1140e4 cmp r2, #0 */
/* @0x1140e8 beq 0x114284 <_Z9YYGML_maxR8YYRValueiPPS_+0x2a4> */
/* @0x1140ec str r9, [r4, #0x8] */
/* @0x1140f0 str r10, [r4, #0xc] */
/* @0x1140f4 ldr r3, [r6, #0xc] */
/* @0x1140f8 ldr r2, [r6, #0x8] */
/* @0x1140fc str r9, [r4] */
/* @0x114100 str r3, [r4, #0xc] */
/* @0x114104 ldr r3, [r6, #0xc] */
/* @0x114108 str r2, [r4, #0x8] */
/* @0x11410c bic r3, r3, #-16777216 */
/* @0x114110 cmp r3, #14 */
/* @0x114114 addls pc, pc, r3, lsl #2 */
/* @0x114118 b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4> */
/* @0x11411c b 0x114180 <_Z9YYGML_maxR8YYRValueiPPS_+0x1a0> */
/* @0x114120 b 0x114224 <_Z9YYGML_maxR8YYRValueiPPS_+0x244> */
/* @0x114124 b 0x114194 <_Z9YYGML_maxR8YYRValueiPPS_+0x1b4> */
/* @0x114128 b 0x114158 <_Z9YYGML_maxR8YYRValueiPPS_+0x178> */
/* @0x11412c b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4> */
/* @0x114130 b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4> */
/* @0x114134 b 0x1141fc <_Z9YYGML_maxR8YYRValueiPPS_+0x21c> */
/* @0x114138 b 0x114158 <_Z9YYGML_maxR8YYRValueiPPS_+0x178> */
/* @0x11413c b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4> */
/* @0x114140 b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4> */
/* @0x114144 b 0x114180 <_Z9YYGML_maxR8YYRValueiPPS_+0x1a0> */
/* @0x114148 b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4> */
/* @0x11414c b 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4> */
/* @0x114150 b 0x114180 <_Z9YYGML_maxR8YYRValueiPPS_+0x1a0> */
/* @0x114154 b 0x114158 <_Z9YYGML_maxR8YYRValueiPPS_+0x178> */
/* @0x114158 vmov.f64 d9, d8 */
/* @0x11415c ldr r3, [r6] */
/* @0x114160 str r3, [r4] */
/* @0x114164 add r5, r5, #1 */
/* @0x114168 cmp r5, r8 */
/* @0x11416c bne 0x1140a0 <_Z9YYGML_maxR8YYRValueiPPS_+0xc0> */
/* @0x114170 mov r0, r4 */
/* @0x114174 add sp, sp, #12 */
/* @0x114178 vpop {d8, d9} */
/* @0x11417c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x114180 ldr r2, [r6] */
/* @0x114184 vmov.f64 d9, d8 */
/* @0x114188 ldr r3, [r6, #0x4] */
/* @0x11418c stm r4, {r2, r3} */
/* @0x114190 b 0x114164 <_Z9YYGML_maxR8YYRValueiPPS_+0x184> */
/* @0x114194 ldr r3, [r6] */
/* @0x114198 cmp r3, #0 */
/* @0x11419c str r3, [r4] */
/* @0x1141a0 beq 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4> */
/* @0x1141a4 ldr r1, [r3, #0x8] */
/* @0x1141a8 ldr r2, [r3] */
/* @0x1141ac cmp r1, #0 */
/* @0x1141b0 streq r4, [r3, #0x8] */
/* @0x1141b4 add r2, r2, #1 */
/* @0x1141b8 str r2, [r3] */
/* @0x1141bc vmoveq.f64 d9, d8 */
/* @0x1141c0 beq 0x114164 <_Z9YYGML_maxR8YYRValueiPPS_+0x184> */
/* @0x1141c4 vmov.f64 d9, d8 */
/* @0x1141c8 b 0x114164 <_Z9YYGML_maxR8YYRValueiPPS_+0x184> */
/* @0x1141cc ldr r11, [r4] */
/* @0x1141d0 cmp r11, #0 */
/* @0x1141d4 beq 0x1141f4 <_Z9YYGML_maxR8YYRValueiPPS_+0x214> */
/* @0x1141d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1141dc ldr r3, [r11, #0x4] */
/* @0x1141e0 sub r3, r3, #1 */
/* @0x1141e4 str r3, [r11, #0x4] */
/* @0x1141e8 cmp r3, #0 */
/* @0x1141ec beq 0x114244 <_Z9YYGML_maxR8YYRValueiPPS_+0x264> */
/* @0x1141f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1141f4 str r9, [r4] */
/* @0x1141f8 b 0x1140f4 <_Z9YYGML_maxR8YYRValueiPPS_+0x114> */
/* @0x1141fc ldr r3, [r6] */
/* @0x114200 str r3, [r4] */
/* @0x114204 ldr r3, [r6] */
/* @0x114208 cmp r3, #0 */
/* @0x11420c beq 0x1141c4 <_Z9YYGML_maxR8YYRValueiPPS_+0x1e4> */
/* @0x114210 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x114214 ldr r1, [r6] */
/* @0x114218 vmov.f64 d9, d8 */
/* @0x11421c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x114220 b 0x114164 <_Z9YYGML_maxR8YYRValueiPPS_+0x184> */
/* @0x114224 ldr r3, [r6] */
/* @0x114228 vmov.f64 d9, d8 */
/* @0x11422c cmp r3, #0 */
/* @0x114230 ldrne r2, [r3, #0x4] */
/* @0x114234 addne r2, r2, #1 */
/* @0x114238 strne r2, [r3, #0x4] */
/* @0x11423c str r3, [r4] */
/* @0x114240 b 0x114164 <_Z9YYGML_maxR8YYRValueiPPS_+0x184> */
/* @0x114244 ldr r0, [r11] */
/* @0x114248 str r3, [sp, #0x4] */
/* @0x11424c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x114250 ldr r3, [sp, #0x4] */
/* @0x114254 str r3, [r11] */
/* @0x114258 str r3, [r11, #0x8] */
/* @0x11425c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x114260 ldr r3, [r11, #0x4] */
/* @0x114264 sub r3, r3, #1 */
/* @0x114268 str r3, [r11, #0x4] */
/* @0x11426c cmp r3, #0 */
/* @0x114270 beq 0x11429c <_Z9YYGML_maxR8YYRValueiPPS_+0x2bc> */
/* @0x114274 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x114278 mov r0, r11 */
/* @0x11427c bl 0x27d1d0 <_ZdlPv> */
/* @0x114280 b 0x1141f0 <_Z9YYGML_maxR8YYRValueiPPS_+0x210> */
/* @0x114284 mov r0, r4 */
/* @0x114288 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x11428c b 0x1140ec <_Z9YYGML_maxR8YYRValueiPPS_+0x10c> */
/* @0x114290 ldm r5, {r2, r3} */
/* @0x114294 stm r0, {r2, r3} */
/* @0x114298 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98> */
/* @0x11429c ldr r0, [r11] */
/* @0x1142a0 str r3, [sp, #0x4] */
/* @0x1142a4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1142a8 ldr r3, [sp, #0x4] */
/* @0x1142ac str r3, [r11] */
/* @0x1142b0 str r3, [r11, #0x8] */
/* @0x1142b4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1142b8 ldr r3, [r11, #0x4] */
/* @0x1142bc sub r3, r3, #1 */
/* @0x1142c0 str r3, [r11, #0x4] */
/* @0x1142c4 cmp r3, #0 */
/* @0x1142c8 beq 0x114344 <_Z9YYGML_maxR8YYRValueiPPS_+0x364> */
/* @0x1142cc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1142d0 mov r0, r11 */
/* @0x1142d4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1142d8 b 0x114274 <_Z9YYGML_maxR8YYRValueiPPS_+0x294> */
/* @0x1142dc ldr r3, [r5] */
/* @0x1142e0 cmp r3, #0 */
/* @0x1142e4 ldrne r2, [r3, #0x4] */
/* @0x1142e8 addne r2, r2, #1 */
/* @0x1142ec strne r2, [r3, #0x4] */
/* @0x1142f0 b 0x114074 <_Z9YYGML_maxR8YYRValueiPPS_+0x94> */
/* @0x1142f4 ldr r3, [r5] */
/* @0x1142f8 cmp r3, #0 */
/* @0x1142fc str r3, [r0] */
/* @0x114300 beq 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98> */
/* @0x114304 ldr r1, [r3, #0x8] */
/* @0x114308 ldr r2, [r3] */
/* @0x11430c cmp r1, #0 */
/* @0x114310 streq r0, [r3, #0x8] */
/* @0x114314 add r2, r2, #1 */
/* @0x114318 str r2, [r3] */
/* @0x11431c b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98> */
/* @0x114320 ldr r3, [r5] */
/* @0x114324 str r3, [r0] */
/* @0x114328 ldr r3, [r5] */
/* @0x11432c cmp r3, #0 */
/* @0x114330 beq 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98> */
/* @0x114334 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x114338 ldr r1, [r5] */
/* @0x11433c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x114340 b 0x114078 <_Z9YYGML_maxR8YYRValueiPPS_+0x98> */
/* @0x114344 ldr r0, [r11] */
/* @0x114348 str r3, [sp, #0x4] */
/* @0x11434c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x114350 ldr r3, [sp, #0x4] */
/* @0x114354 str r3, [r11] */
/* @0x114358 str r3, [r11, #0x8] */
/* @0x11435c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x114360 ldr r3, [r11, #0x4] */
/* @0x114364 sub r3, r3, #1 */
/* @0x114368 str r3, [r11, #0x4] */
/* @0x11436c cmp r3, #0 */
/* @0x114370 bne 0x11439c <_Z9YYGML_maxR8YYRValueiPPS_+0x3bc> */
/* @0x114374 ldr r0, [r11] */
/* @0x114378 str r3, [sp, #0x4] */
/* @0x11437c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x114380 ldr r3, [sp, #0x4] */
/* @0x114384 mov r0, r11 */
/* @0x114388 str r3, [r11] */
/* @0x11438c str r3, [r11, #0x8] */
/* @0x114390 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x114394 mov r0, r11 */
/* @0x114398 bl 0x27d1d0 <_ZdlPv> */
/* @0x11439c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1143a0 mov r0, r11 */
/* @0x1143a4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1143a8 b 0x1142cc <_Z9YYGML_maxR8YYRValueiPPS_+0x2ec> */

/* ── FUNC 0x1143ac · YYGML_choose(YYRValue&, int, YYRValue**) · size=632 · insn=158 */
/* @0x1143ac push {r3, r4, r5, r6, r7, lr} */
/* @0x1143b0 mov r4, r0 */
/* @0x1143b4 mov r0, r1 */
/* @0x1143b8 mov r5, r2 */
/* @0x1143bc bl 0xc4600 <_Z8YYRandomi> */
/* @0x1143c0 vldr s15, [pc, #600] */
/* @0x1143c4 vmov s12, r0 */
/* @0x1143c8 vcvt.f32.u32 s14, s12 */
/* @0x1143cc vadd.f32 s15, s14, s15 */
/* @0x1143d0 vcvt.f64.f32 d6, s15 */
/* @0x1143d4 vmov r0, r1, d6 */
/* @0x1143d8 bl 0xb6598 <floor@plt> */
/* @0x1143dc ldr r12, [r4, #0xc] */
/* @0x1143e0 bic r3, r12, #-16777216 */
/* @0x1143e4 cmp r3, #1 */
/* @0x1143e8 vmov d7, r0, r1 */
/* @0x1143ec vcvt.s32.f64 s15, d7 */
/* @0x1143f0 vmov r0, s15 */
/* @0x1143f4 ldr r5, [r5, r0, lsl #2] */
/* @0x1143f8 beq 0x1144b0 <_Z12YYGML_chooseR8YYRValueiPPS_+0x104> */
/* @0x1143fc cmp r3, #2 */
/* @0x114400 bne 0x114428 <_Z12YYGML_chooseR8YYRValueiPPS_+0x7c> */
/* @0x114404 sub r12, r12, #1 */
/* @0x114408 bic r12, r12, #-16777216 */
/* @0x11440c bic r12, r12, #3 */
/* @0x114410 cmp r12, #0 */
/* @0x114414 beq 0x114584 <_Z12YYGML_chooseR8YYRValueiPPS_+0x1d8> */
/* @0x114418 mov r2, #0 */
/* @0x11441c mov r3, #5 */
/* @0x114420 str r2, [r4, #0x8] */
/* @0x114424 str r3, [r4, #0xc] */
/* @0x114428 ldr r3, [r5, #0xc] */
/* @0x11442c mov r1, #0 */
/* @0x114430 ldr r2, [r5, #0x8] */
/* @0x114434 str r1, [r4] */
/* @0x114438 str r3, [r4, #0xc] */
/* @0x11443c ldr r3, [r5, #0xc] */
/* @0x114440 str r2, [r4, #0x8] */
/* @0x114444 bic r3, r3, #-16777216 */
/* @0x114448 cmp r3, #14 */
/* @0x11444c addls pc, pc, r3, lsl #2 */
/* @0x114450 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec> */
/* @0x114454 b 0x1144a0 <_Z12YYGML_chooseR8YYRValueiPPS_+0xf4> */
/* @0x114458 b 0x114508 <_Z12YYGML_chooseR8YYRValueiPPS_+0x15c> */
/* @0x11445c b 0x114520 <_Z12YYGML_chooseR8YYRValueiPPS_+0x174> */
/* @0x114460 b 0x114490 <_Z12YYGML_chooseR8YYRValueiPPS_+0xe4> */
/* @0x114464 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec> */
/* @0x114468 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec> */
/* @0x11446c b 0x1144e4 <_Z12YYGML_chooseR8YYRValueiPPS_+0x138> */
/* @0x114470 b 0x114490 <_Z12YYGML_chooseR8YYRValueiPPS_+0xe4> */
/* @0x114474 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec> */
/* @0x114478 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec> */
/* @0x11447c b 0x1144a0 <_Z12YYGML_chooseR8YYRValueiPPS_+0xf4> */
/* @0x114480 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec> */
/* @0x114484 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec> */
/* @0x114488 b 0x1144a0 <_Z12YYGML_chooseR8YYRValueiPPS_+0xf4> */
/* @0x11448c b 0x114490 <_Z12YYGML_chooseR8YYRValueiPPS_+0xe4> */
/* @0x114490 ldr r3, [r5] */
/* @0x114494 str r3, [r4] */
/* @0x114498 mov r0, r4 */
/* @0x11449c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1144a0 ldm r5, {r2, r3} */
/* @0x1144a4 mov r0, r4 */
/* @0x1144a8 stm r4, {r2, r3} */
/* @0x1144ac pop {r3, r4, r5, r6, r7, pc} */
/* @0x1144b0 ldr r6, [r4] */
/* @0x1144b4 cmp r6, #0 */
/* @0x1144b8 beq 0x1144d8 <_Z12YYGML_chooseR8YYRValueiPPS_+0x12c> */
/* @0x1144bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1144c0 ldr r7, [r6, #0x4] */
/* @0x1144c4 sub r7, r7, #1 */
/* @0x1144c8 str r7, [r6, #0x4] */
/* @0x1144cc cmp r7, #0 */
/* @0x1144d0 beq 0x11454c <_Z12YYGML_chooseR8YYRValueiPPS_+0x1a0> */
/* @0x1144d4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1144d8 mov r3, #0 */
/* @0x1144dc str r3, [r4] */
/* @0x1144e0 b 0x114428 <_Z12YYGML_chooseR8YYRValueiPPS_+0x7c> */
/* @0x1144e4 ldr r3, [r5] */
/* @0x1144e8 str r3, [r4] */
/* @0x1144ec ldr r3, [r5] */
/* @0x1144f0 cmp r3, #0 */
/* @0x1144f4 beq 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec> */
/* @0x1144f8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1144fc ldr r1, [r5] */
/* @0x114500 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x114504 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec> */
/* @0x114508 ldr r3, [r5] */
/* @0x11450c cmp r3, #0 */
/* @0x114510 ldrne r2, [r3, #0x4] */
/* @0x114514 addne r2, r2, #1 */
/* @0x114518 strne r2, [r3, #0x4] */
/* @0x11451c b 0x114494 <_Z12YYGML_chooseR8YYRValueiPPS_+0xe8> */
/* @0x114520 ldr r3, [r5] */
/* @0x114524 cmp r3, #0 */
/* @0x114528 str r3, [r4] */
/* @0x11452c beq 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec> */
/* @0x114530 ldr r1, [r3, #0x8] */
/* @0x114534 ldr r2, [r3] */
/* @0x114538 cmp r1, #0 */
/* @0x11453c streq r4, [r3, #0x8] */
/* @0x114540 add r2, r2, #1 */
/* @0x114544 str r2, [r3] */
/* @0x114548 b 0x114498 <_Z12YYGML_chooseR8YYRValueiPPS_+0xec> */
/* @0x11454c ldr r0, [r6] */
/* @0x114550 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x114554 str r7, [r6] */
/* @0x114558 str r7, [r6, #0x8] */
/* @0x11455c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x114560 ldr r7, [r6, #0x4] */
/* @0x114564 sub r7, r7, #1 */
/* @0x114568 str r7, [r6, #0x4] */
/* @0x11456c cmp r7, #0 */
/* @0x114570 beq 0x114590 <_Z12YYGML_chooseR8YYRValueiPPS_+0x1e4> */
/* @0x114574 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x114578 mov r0, r6 */
/* @0x11457c bl 0x27d1d0 <_ZdlPv> */
/* @0x114580 b 0x1144d4 <_Z12YYGML_chooseR8YYRValueiPPS_+0x128> */
/* @0x114584 mov r0, r4 */
/* @0x114588 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x11458c b 0x114418 <_Z12YYGML_chooseR8YYRValueiPPS_+0x6c> */
/* @0x114590 ldr r0, [r6] */
/* @0x114594 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x114598 str r7, [r6] */
/* @0x11459c str r7, [r6, #0x8] */
/* @0x1145a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1145a4 ldr r7, [r6, #0x4] */
/* @0x1145a8 sub r7, r7, #1 */
/* @0x1145ac str r7, [r6, #0x4] */
/* @0x1145b0 cmp r7, #0 */
/* @0x1145b4 beq 0x1145c8 <_Z12YYGML_chooseR8YYRValueiPPS_+0x21c> */
/* @0x1145b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1145bc mov r0, r6 */
/* @0x1145c0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1145c4 b 0x114574 <_Z12YYGML_chooseR8YYRValueiPPS_+0x1c8> */
/* @0x1145c8 ldr r0, [r6] */
/* @0x1145cc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1145d0 str r7, [r6] */
/* @0x1145d4 str r7, [r6, #0x8] */
/* @0x1145d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1145dc ldr r7, [r6, #0x4] */
/* @0x1145e0 sub r7, r7, #1 */
/* @0x1145e4 str r7, [r6, #0x4] */
/* @0x1145e8 cmp r7, #0 */
/* @0x1145ec bne 0x114610 <_Z12YYGML_chooseR8YYRValueiPPS_+0x264> */
/* @0x1145f0 ldr r0, [r6] */
/* @0x1145f4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1145f8 mov r0, r6 */
/* @0x1145fc str r7, [r6] */
/* @0x114600 str r7, [r6, #0x8] */
/* @0x114604 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x114608 mov r0, r6 */
/* @0x11460c bl 0x27d1d0 <_ZdlPv> */
/* @0x114610 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x114614 mov r0, r6 */
/* @0x114618 bl 0x27d1d0 <_ZdlPv> */
/* @0x11461c b 0x1145b8 <_Z12YYGML_chooseR8YYRValueiPPS_+0x20c> */
/* @0x114620 andeq r0, r0, r0 */
