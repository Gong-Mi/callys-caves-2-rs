/* libyoyo.so 覆盖卡组 0205
 * 函数 0x22825c..0x22f554，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x22825c · vorbis_book_decodevs_add · size=1272 · insn=318 */
/* @0x22825c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x228260 add r11, sp, #32 */
/* @0x228264 ldr r4, [pc, #0x4e4] */
/* @0x228268 sub sp, sp, #44 */
/* @0x22826c mov r7, r0 */
/* @0x228270 ldr r4, [pc, r4] */
/* @0x228274 mov r6, r2 */
/* @0x228278 ldr r0, [r0, #0x8] */
/* @0x22827c ldr r2, [r4] */
/* @0x228280 cmp r0, #0 */
/* @0x228284 str r1, [r11, #-0x44] */
/* @0x228288 str r4, [r11, #-0x3c] */
/* @0x22828c str r2, [r11, #-0x28] */
/* @0x228290 ble 0x2284b4 <vorbis_book_decodevs_add+0x258> */
/* @0x228294 ldr r5, [r7] */
/* @0x228298 mov r0, r3 */
/* @0x22829c mov r1, r5 */
/* @0x2282a0 bl 0x318d10 <__divsi3> */
/* @0x2282a4 ldr r8, [r7, #0xc] */
/* @0x2282a8 ldr r1, [r11, #0x4] */
/* @0x2282ac subs r8, r1, r8 */
/* @0x2282b0 lsl r12, r0, #2 */
/* @0x2282b4 str r0, [r11, #-0x30] */
/* @0x2282b8 add r3, r12, #14 */
/* @0x2282bc str r12, [r11, #-0x40] */
/* @0x2282c0 bic r3, r3, #7 */
/* @0x2282c4 sub sp, sp, r3 */
/* @0x2282c8 str sp, [r11, #-0x38] */
/* @0x2282cc sub sp, sp, r3 */
/* @0x2282d0 str sp, [r11, #-0x34] */
/* @0x2282d4 bmi 0x228510 <vorbis_book_decodevs_add+0x2b4> */
/* @0x2282d8 ldr r2, [r11, #-0x30] */
/* @0x2282dc cmp r2, #0 */
/* @0x2282e0 ble 0x228444 <vorbis_book_decodevs_add+0x1e8> */
/* @0x2282e4 mov r9, #0 */
/* @0x2282e8 str r8, [r11, #-0x48] */
/* @0x2282ec mov r8, r9 */
/* @0x2282f0 mov r0, r6 */
/* @0x2282f4 ldr r1, [r7, #0x24] */
/* @0x2282f8 ldr r5, [r7, #0x28] */
/* @0x2282fc bl 0x23388c <oggpack_look> */
/* @0x228300 cmp r0, #0 */
/* @0x228304 blt 0x228504 <vorbis_book_decodevs_add+0x2a8> */
/* @0x228308 ldr r3, [r7, #0x20] */
/* @0x22830c ldr r4, [r3, r0, lsl #2] */
/* @0x228310 cmp r4, #0 */
/* @0x228314 bge 0x2284d4 <vorbis_book_decodevs_add+0x278> */
/* @0x228318 ldr r2, [r7, #0x8] */
/* @0x22831c ubfx r3, r4, #0x0, #0xf */
/* @0x228320 ubfx r4, r4, #0xf, #0xf */
/* @0x228324 rsb r10, r3, r2 */
/* @0x228328 b 0x228330 <vorbis_book_decodevs_add+0xd4> */
/* @0x22832c sub r5, r5, #1 */
/* @0x228330 mov r0, r6 */
/* @0x228334 mov r1, r5 */
/* @0x228338 bl 0x23388c <oggpack_look> */
/* @0x22833c cmp r5, #1 */
/* @0x228340 movle r3, #0 */
/* @0x228344 movgt r3, #1 */
/* @0x228348 ands r3, r3, r0, lsr #31 */
/* @0x22834c bne 0x22832c <vorbis_book_decodevs_add+0xd0> */
/* @0x228350 cmp r0, #0 */
/* @0x228354 blt 0x22873c <vorbis_book_decodevs_add+0x4e0> */
/* @0x228358 rev r0, r0 */
/* @0x22835c movw r3, #0xf0f */
/* @0x228360 movw r1, #0xf0f0 */
/* @0x228364 bfi r3, r3, #16, #16 */
/* @0x228368 bfi r1, r1, #16, #16 */
/* @0x22836c and r3, r3, r0, lsr #4 */
/* @0x228370 and r0, r1, r0, lsl #4 */
/* @0x228374 movw r1, #0x3333 */
/* @0x228378 orr r0, r0, r3 */
/* @0x22837c bfi r1, r1, #16, #16 */
/* @0x228380 movw r3, #0xcccc */
/* @0x228384 bfi r3, r3, #16, #16 */
/* @0x228388 and r1, r1, r0, lsr #2 */
/* @0x22838c and r3, r3, r0, lsl #2 */
/* @0x228390 orr r12, r3, r1 */
/* @0x228394 rsb r3, r4, r10 */
/* @0x228398 movw r0, #0xaaaa */
/* @0x22839c movw r1, #0x5555 */
/* @0x2283a0 bfi r0, r0, #16, #16 */
/* @0x2283a4 bfi r1, r1, #16, #16 */
/* @0x2283a8 cmp r3, #1 */
/* @0x2283ac and r0, r0, r12, lsl #1 */
/* @0x2283b0 and r1, r1, r12, lsr #1 */
/* @0x2283b4 orr r0, r0, r1 */
/* @0x2283b8 ble 0x2283f4 <vorbis_book_decodevs_add+0x198> */
/* @0x2283bc ldr lr, [r7, #0x14] */
/* @0x2283c0 asr r3, r3, #1 */
/* @0x2283c4 add r2, r3, r4 */
/* @0x2283c8 ldr r2, [lr, r2, lsl #2] */
/* @0x2283cc cmp r2, r0 */
/* @0x2283d0 movls r1, r3 */
/* @0x2283d4 movhi r1, #0 */
/* @0x2283d8 cmp r2, r0 */
/* @0x2283dc add r4, r4, r1 */
/* @0x2283e0 movls r3, #0 */
/* @0x2283e4 rsb r10, r3, r10 */
/* @0x2283e8 rsb r3, r4, r10 */
/* @0x2283ec cmp r3, #1 */
/* @0x2283f0 bgt 0x2283c0 <vorbis_book_decodevs_add+0x164> */
/* @0x2283f4 ldr r3, [r7, #0x1c] */
/* @0x2283f8 mov r0, r6 */
/* @0x2283fc ldrb r1, [r3, r4] */
/* @0x228400 cmp r1, r5 */
/* @0x228404 bgt 0x22872c <vorbis_book_decodevs_add+0x4d0> */
/* @0x228408 bl 0x233a7c <oggpack_adv> */
/* @0x22840c ldr r12, [r11, #-0x38] */
/* @0x228410 str r4, [r12, r9] */
/* @0x228414 ldr r5, [r7] */
/* @0x228418 add r8, r8, #1 */
/* @0x22841c ldr r3, [r7, #0x10] */
/* @0x228420 ldr r2, [r11, #-0x30] */
/* @0x228424 mul r4, r4, r5 */
/* @0x228428 cmp r8, r2 */
/* @0x22842c add r4, r3, r4, lsl #2 */
/* @0x228430 ldr r3, [r11, #-0x34] */
/* @0x228434 str r4, [r3, r9] */
/* @0x228438 add r9, r9, #4 */
/* @0x22843c bne 0x2282f0 <vorbis_book_decodevs_add+0x94> */
/* @0x228440 ldr r8, [r11, #-0x48] */
/* @0x228444 cmp r5, #0 */
/* @0x228448 ble 0x2284b4 <vorbis_book_decodevs_add+0x258> */
/* @0x22844c ldr r2, [r11, #-0x40] */
/* @0x228450 ldr r4, [r11, #-0x34] */
/* @0x228454 ldr r6, [r11, #-0x44] */
/* @0x228458 ldr r7, [r11, #-0x30] */
/* @0x22845c add r12, r4, r2 */
/* @0x228460 ldr r10, [r11, #-0x34] */
/* @0x228464 mov r4, #0 */
/* @0x228468 mov r9, r2 */
/* @0x22846c cmp r7, #0 */
/* @0x228470 ble 0x2284a4 <vorbis_book_decodevs_add+0x248> */
/* @0x228474 lsl r0, r4, #2 */
/* @0x228478 mov r2, r10 */
/* @0x22847c mov r3, r6 */
/* @0x228480 str r4, [r11, #-0x30] */
/* @0x228484 ldr r1, [r2], #4 */
/* @0x228488 ldr r4, [r3] */
/* @0x22848c cmp r2, r12 */
/* @0x228490 ldr r1, [r1, r0] */
/* @0x228494 add r1, r4, r1, asr r8 */
/* @0x228498 str r1, [r3], #4 */
/* @0x22849c bne 0x228484 <vorbis_book_decodevs_add+0x228> */
/* @0x2284a0 ldr r4, [r11, #-0x30] */
/* @0x2284a4 add r4, r4, #1 */
/* @0x2284a8 add r6, r6, r9 */
/* @0x2284ac cmp r4, r5 */
/* @0x2284b0 bne 0x22846c <vorbis_book_decodevs_add+0x210> */
/* @0x2284b4 mov r0, #0 */
/* @0x2284b8 ldr r12, [r11, #-0x3c] */
/* @0x2284bc ldr r2, [r11, #-0x28] */
/* @0x2284c0 ldr r3, [r12] */
/* @0x2284c4 cmp r2, r3 */
/* @0x2284c8 bne 0x22874c <vorbis_book_decodevs_add+0x4f0> */
/* @0x2284cc sub sp, r11, #32 */
/* @0x2284d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2284d4 ldr r3, [r7, #0x1c] */
/* @0x2284d8 mov r0, r6 */
/* @0x2284dc add r3, r3, r4 */
/* @0x2284e0 sub r4, r4, #1 */
/* @0x2284e4 ldrb r1, [r3, #-0x1] */
/* @0x2284e8 bl 0x233a7c <oggpack_adv> */
/* @0x2284ec ldr r3, [r11, #-0x38] */
/* @0x2284f0 cmn r4, #1 */
/* @0x2284f4 str r4, [r3, r9] */
/* @0x2284f8 bne 0x228414 <vorbis_book_decodevs_add+0x1b8> */
/* @0x2284fc mvn r0, #0 */
/* @0x228500 b 0x2284b8 <vorbis_book_decodevs_add+0x25c> */
/* @0x228504 ldr r10, [r7, #0x8] */
/* @0x228508 mov r4, #0 */
/* @0x22850c b 0x228330 <vorbis_book_decodevs_add+0xd4> */
/* @0x228510 cmp r0, #0 */
/* @0x228514 strgt r8, [r11, #-0x48] */
/* @0x228518 movgt r9, #0 */
/* @0x22851c movgt r3, r9 */
/* @0x228520 movgt r8, r3 */
/* @0x228524 ble 0x22867c <vorbis_book_decodevs_add+0x420> */
/* @0x228528 mov r0, r6 */
/* @0x22852c ldr r1, [r7, #0x24] */
/* @0x228530 ldr r5, [r7, #0x28] */
/* @0x228534 bl 0x23388c <oggpack_look> */
/* @0x228538 cmp r0, #0 */
/* @0x22853c blt 0x228720 <vorbis_book_decodevs_add+0x4c4> */
/* @0x228540 ldr r3, [r7, #0x20] */
/* @0x228544 ldr r4, [r3, r0, lsl #2] */
/* @0x228548 cmp r4, #0 */
/* @0x22854c bge 0x2286f4 <vorbis_book_decodevs_add+0x498> */
/* @0x228550 ldr r2, [r7, #0x8] */
/* @0x228554 ubfx r3, r4, #0x0, #0xf */
/* @0x228558 ubfx r4, r4, #0xf, #0xf */
/* @0x22855c rsb r10, r3, r2 */
/* @0x228560 b 0x228568 <vorbis_book_decodevs_add+0x30c> */
/* @0x228564 sub r5, r5, #1 */
/* @0x228568 mov r0, r6 */
/* @0x22856c mov r1, r5 */
/* @0x228570 bl 0x23388c <oggpack_look> */
/* @0x228574 cmp r5, #1 */
/* @0x228578 movle r3, #0 */
/* @0x22857c movgt r3, #1 */
/* @0x228580 ands r3, r3, r0, lsr #31 */
/* @0x228584 bne 0x228564 <vorbis_book_decodevs_add+0x308> */
/* @0x228588 cmp r0, #0 */
/* @0x22858c blt 0x22873c <vorbis_book_decodevs_add+0x4e0> */
/* @0x228590 rev r0, r0 */
/* @0x228594 movw r12, #0xf0f */
/* @0x228598 movw r3, #0xf0f0 */
/* @0x22859c bfi r12, r12, #16, #16 */
/* @0x2285a0 bfi r3, r3, #16, #16 */
/* @0x2285a4 and r12, r12, r0, lsr #4 */
/* @0x2285a8 and r0, r3, r0, lsl #4 */
/* @0x2285ac movw r1, #0x3333 */
/* @0x2285b0 orr r0, r0, r12 */
/* @0x2285b4 bfi r1, r1, #16, #16 */
/* @0x2285b8 movw r3, #0xcccc */
/* @0x2285bc bfi r3, r3, #16, #16 */
/* @0x2285c0 and r1, r1, r0, lsr #2 */
/* @0x2285c4 and r12, r3, r0, lsl #2 */
/* @0x2285c8 orr r12, r12, r1 */
/* @0x2285cc rsb r3, r4, r10 */
/* @0x2285d0 movw r0, #0xaaaa */
/* @0x2285d4 movw r1, #0x5555 */
/* @0x2285d8 bfi r0, r0, #16, #16 */
/* @0x2285dc bfi r1, r1, #16, #16 */
/* @0x2285e0 cmp r3, #1 */
/* @0x2285e4 and r0, r0, r12, lsl #1 */
/* @0x2285e8 and r1, r1, r12, lsr #1 */
/* @0x2285ec orr r0, r0, r1 */
/* @0x2285f0 ble 0x22862c <vorbis_book_decodevs_add+0x3d0> */
/* @0x2285f4 ldr lr, [r7, #0x14] */
/* @0x2285f8 asr r3, r3, #1 */
/* @0x2285fc add r2, r3, r4 */
/* @0x228600 ldr r2, [lr, r2, lsl #2] */
/* @0x228604 cmp r2, r0 */
/* @0x228608 movls r1, r3 */
/* @0x22860c movhi r1, #0 */
/* @0x228610 cmp r2, r0 */
/* @0x228614 add r4, r4, r1 */
/* @0x228618 movls r3, #0 */
/* @0x22861c rsb r10, r3, r10 */
/* @0x228620 rsb r3, r4, r10 */
/* @0x228624 cmp r3, #1 */
/* @0x228628 bgt 0x2285f8 <vorbis_book_decodevs_add+0x39c> */
/* @0x22862c ldr r3, [r7, #0x1c] */
/* @0x228630 mov r0, r6 */
/* @0x228634 ldrb r1, [r3, r4] */
/* @0x228638 cmp r1, r5 */
/* @0x22863c bgt 0x22872c <vorbis_book_decodevs_add+0x4d0> */
/* @0x228640 bl 0x233a7c <oggpack_adv> */
/* @0x228644 ldr r2, [r11, #-0x38] */
/* @0x228648 str r4, [r2, r9] */
/* @0x22864c ldr r5, [r7] */
/* @0x228650 add r8, r8, #1 */
/* @0x228654 ldr r3, [r11, #-0x30] */
/* @0x228658 ldr r12, [r11, #-0x34] */
/* @0x22865c mul r4, r4, r5 */
/* @0x228660 cmp r8, r3 */
/* @0x228664 ldr r3, [r7, #0x10] */
/* @0x228668 add r4, r3, r4, lsl #2 */
/* @0x22866c str r4, [r12, r9] */
/* @0x228670 add r9, r9, #4 */
/* @0x228674 bne 0x228528 <vorbis_book_decodevs_add+0x2cc> */
/* @0x228678 ldr r8, [r11, #-0x48] */
/* @0x22867c cmp r5, #0 */
/* @0x228680 ble 0x2284b4 <vorbis_book_decodevs_add+0x258> */
/* @0x228684 ldr r2, [r11, #-0x34] */
/* @0x228688 rsb r8, r8, #0 */
/* @0x22868c ldr r3, [r11, #-0x40] */
/* @0x228690 mov r4, #0 */
/* @0x228694 ldr r6, [r11, #-0x44] */
/* @0x228698 ldr r7, [r11, #-0x30] */
/* @0x22869c add r12, r2, r3 */
/* @0x2286a0 mov r9, r3 */
/* @0x2286a4 mov r10, r2 */
/* @0x2286a8 cmp r7, #0 */
/* @0x2286ac ble 0x2286e0 <vorbis_book_decodevs_add+0x484> */
/* @0x2286b0 lsl r0, r4, #2 */
/* @0x2286b4 mov r2, r10 */
/* @0x2286b8 mov r3, r6 */
/* @0x2286bc str r4, [r11, #-0x30] */
/* @0x2286c0 ldr r1, [r2], #4 */
/* @0x2286c4 ldr r4, [r3] */
/* @0x2286c8 cmp r2, r12 */
/* @0x2286cc ldr r1, [r1, r0] */
/* @0x2286d0 add r1, r4, r1, lsl r8 */
/* @0x2286d4 str r1, [r3], #4 */
/* @0x2286d8 bne 0x2286c0 <vorbis_book_decodevs_add+0x464> */
/* @0x2286dc ldr r4, [r11, #-0x30] */
/* @0x2286e0 add r4, r4, #1 */
/* @0x2286e4 add r6, r6, r9 */
/* @0x2286e8 cmp r4, r5 */
/* @0x2286ec bne 0x2286a8 <vorbis_book_decodevs_add+0x44c> */
/* @0x2286f0 b 0x2284b4 <vorbis_book_decodevs_add+0x258> */
/* @0x2286f4 ldr r3, [r7, #0x1c] */
/* @0x2286f8 mov r0, r6 */
/* @0x2286fc add r3, r3, r4 */
/* @0x228700 sub r4, r4, #1 */
/* @0x228704 ldrb r1, [r3, #-0x1] */
/* @0x228708 bl 0x233a7c <oggpack_adv> */
/* @0x22870c ldr r12, [r11, #-0x38] */
/* @0x228710 cmn r4, #1 */
/* @0x228714 str r4, [r12, r9] */
/* @0x228718 bne 0x22864c <vorbis_book_decodevs_add+0x3f0> */
/* @0x22871c b 0x2284fc <vorbis_book_decodevs_add+0x2a0> */
/* @0x228720 ldr r10, [r7, #0x8] */
/* @0x228724 mov r4, #0 */
/* @0x228728 b 0x228568 <vorbis_book_decodevs_add+0x30c> */
/* @0x22872c add r1, r5, #1 */
/* @0x228730 bl 0x233a7c <oggpack_adv> */
/* @0x228734 mvn r0, #0 */
/* @0x228738 b 0x2284b8 <vorbis_book_decodevs_add+0x25c> */
/* @0x22873c mov r0, r6 */
/* @0x228740 mov r1, #1 */
/* @0x228744 bl 0x233a7c <oggpack_adv> */
/* @0x228748 b 0x2284fc <vorbis_book_decodevs_add+0x2a0> */
/* @0x22874c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x228750 andseq r5, r12, r0, ror #13 */

/* ── FUNC 0x228754 · vorbis_book_decodev_add · size=936 · insn=234 */
/* @0x228754 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x228758 sub sp, sp, #12 */
/* @0x22875c mov r8, r0 */
/* @0x228760 mov r6, r2 */
/* @0x228764 str r1, [sp, #0x4] */
/* @0x228768 mov r10, r3 */
/* @0x22876c ldr r1, [r0, #0x8] */
/* @0x228770 cmp r1, #0 */
/* @0x228774 ble 0x2288f8 <vorbis_book_decodev_add+0x1a4> */
/* @0x228778 ldr r7, [r0, #0xc] */
/* @0x22877c ldr r1, [sp, #0x30] */
/* @0x228780 subs r7, r1, r7 */
/* @0x228784 bmi 0x228948 <vorbis_book_decodev_add+0x1f4> */
/* @0x228788 cmp r3, #0 */
/* @0x22878c ble 0x2288f8 <vorbis_book_decodev_add+0x1a4> */
/* @0x228790 mov r9, #0 */
/* @0x228794 mov r0, r6 */
/* @0x228798 ldr r1, [r8, #0x24] */
/* @0x22879c ldr r4, [r8, #0x28] */
/* @0x2287a0 bl 0x23388c <oggpack_look> */
/* @0x2287a4 cmp r0, #0 */
/* @0x2287a8 blt 0x22892c <vorbis_book_decodev_add+0x1d8> */
/* @0x2287ac ldr r3, [r8, #0x20] */
/* @0x2287b0 ldr r5, [r3, r0, lsl #2] */
/* @0x2287b4 cmp r5, #0 */
/* @0x2287b8 bge 0x228904 <vorbis_book_decodev_add+0x1b0> */
/* @0x2287bc ldr r2, [r8, #0x8] */
/* @0x2287c0 ubfx r3, r5, #0x0, #0xf */
/* @0x2287c4 ubfx r5, r5, #0xf, #0xf */
/* @0x2287c8 rsb r11, r3, r2 */
/* @0x2287cc b 0x2287d4 <vorbis_book_decodev_add+0x80> */
/* @0x2287d0 sub r4, r4, #1 */
/* @0x2287d4 mov r0, r6 */
/* @0x2287d8 mov r1, r4 */
/* @0x2287dc bl 0x23388c <oggpack_look> */
/* @0x2287e0 cmp r4, #1 */
/* @0x2287e4 movle r3, #0 */
/* @0x2287e8 movgt r3, #1 */
/* @0x2287ec ands r3, r3, r0, lsr #31 */
/* @0x2287f0 bne 0x2287d0 <vorbis_book_decodev_add+0x7c> */
/* @0x2287f4 cmp r0, #0 */
/* @0x2287f8 blt 0x228aec <vorbis_book_decodev_add+0x398> */
/* @0x2287fc rev r0, r0 */
/* @0x228800 movw r3, #0xf0f */
/* @0x228804 movw r1, #0xf0f0 */
/* @0x228808 bfi r3, r3, #16, #16 */
/* @0x22880c bfi r1, r1, #16, #16 */
/* @0x228810 and r3, r3, r0, lsr #4 */
/* @0x228814 and r0, r1, r0, lsl #4 */
/* @0x228818 movw r1, #0x3333 */
/* @0x22881c orr r0, r0, r3 */
/* @0x228820 bfi r1, r1, #16, #16 */
/* @0x228824 movw r3, #0xcccc */
/* @0x228828 bfi r3, r3, #16, #16 */
/* @0x22882c and r1, r1, r0, lsr #2 */
/* @0x228830 and r3, r3, r0, lsl #2 */
/* @0x228834 orr r12, r3, r1 */
/* @0x228838 rsb r3, r5, r11 */
/* @0x22883c movw r0, #0xaaaa */
/* @0x228840 movw r1, #0x5555 */
/* @0x228844 bfi r0, r0, #16, #16 */
/* @0x228848 bfi r1, r1, #16, #16 */
/* @0x22884c cmp r3, #1 */
/* @0x228850 and r0, r0, r12, lsl #1 */
/* @0x228854 and r1, r1, r12, lsr #1 */
/* @0x228858 orr r0, r0, r1 */
/* @0x22885c ble 0x228898 <vorbis_book_decodev_add+0x144> */
/* @0x228860 ldr r12, [r8, #0x14] */
/* @0x228864 asr r3, r3, #1 */
/* @0x228868 add r1, r3, r5 */
/* @0x22886c ldr r1, [r12, r1, lsl #2] */
/* @0x228870 cmp r1, r0 */
/* @0x228874 movls lr, r3 */
/* @0x228878 movhi lr, #0 */
/* @0x22887c cmp r1, r0 */
/* @0x228880 add r5, r5, lr */
/* @0x228884 movls r3, #0 */
/* @0x228888 rsb r11, r3, r11 */
/* @0x22888c rsb r3, r5, r11 */
/* @0x228890 cmp r3, #1 */
/* @0x228894 bgt 0x228864 <vorbis_book_decodev_add+0x110> */
/* @0x228898 ldr r3, [r8, #0x1c] */
/* @0x22889c mov r0, r6 */
/* @0x2288a0 ldrb r1, [r3, r5] */
/* @0x2288a4 cmp r1, r4 */
/* @0x2288a8 bgt 0x228938 <vorbis_book_decodev_add+0x1e4> */
/* @0x2288ac bl 0x233a7c <oggpack_adv> */
/* @0x2288b0 ldr r12, [r8] */
/* @0x2288b4 ldr r3, [r8, #0x10] */
/* @0x2288b8 cmp r12, #0 */
/* @0x2288bc mul r5, r5, r12 */
/* @0x2288c0 add r5, r3, r5, lsl #2 */
/* @0x2288c4 ble 0x2288f0 <vorbis_book_decodev_add+0x19c> */
/* @0x2288c8 ldr r2, [sp, #0x4] */
/* @0x2288cc add r0, r5, r12, lsl #2 */
/* @0x2288d0 add r3, r2, r9, lsl #2 */
/* @0x2288d4 ldr r1, [r5], #4 */
/* @0x2288d8 ldr r2, [r3] */
/* @0x2288dc cmp r5, r0 */
/* @0x2288e0 add r2, r2, r1, asr r7 */
/* @0x2288e4 str r2, [r3], #4 */
/* @0x2288e8 bne 0x2288d4 <vorbis_book_decodev_add+0x180> */
/* @0x2288ec add r9, r9, r12 */
/* @0x2288f0 cmp r10, r9 */
/* @0x2288f4 bgt 0x228794 <vorbis_book_decodev_add+0x40> */
/* @0x2288f8 mov r0, #0 */
/* @0x2288fc add sp, sp, #12 */
/* @0x228900 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x228904 ldr r3, [r8, #0x1c] */
/* @0x228908 mov r0, r6 */
/* @0x22890c add r3, r3, r5 */
/* @0x228910 ldrb r1, [r3, #-0x1] */
/* @0x228914 bl 0x233a7c <oggpack_adv> */
/* @0x228918 subs r5, r5, #1 */
/* @0x22891c bhs 0x2288b0 <vorbis_book_decodev_add+0x15c> */
/* @0x228920 mvn r0, #0 */
/* @0x228924 add sp, sp, #12 */
/* @0x228928 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22892c ldr r11, [r8, #0x8] */
/* @0x228930 mov r5, #0 */
/* @0x228934 b 0x2287d4 <vorbis_book_decodev_add+0x80> */
/* @0x228938 add r1, r4, #1 */
/* @0x22893c bl 0x233a7c <oggpack_adv> */
/* @0x228940 mvn r0, #0 */
/* @0x228944 b 0x228924 <vorbis_book_decodev_add+0x1d0> */
/* @0x228948 cmp r3, #0 */
/* @0x22894c movgt r9, #0 */
/* @0x228950 ble 0x2288f8 <vorbis_book_decodev_add+0x1a4> */
/* @0x228954 mov r0, r6 */
/* @0x228958 ldr r1, [r8, #0x24] */
/* @0x22895c ldr r4, [r8, #0x28] */
/* @0x228960 bl 0x23388c <oggpack_look> */
/* @0x228964 cmp r0, #0 */
/* @0x228968 blt 0x228ae0 <vorbis_book_decodev_add+0x38c> */
/* @0x22896c ldr r3, [r8, #0x20] */
/* @0x228970 ldr r5, [r3, r0, lsl #2] */
/* @0x228974 cmp r5, #0 */
/* @0x228978 bge 0x228ac0 <vorbis_book_decodev_add+0x36c> */
/* @0x22897c ldr r2, [r8, #0x8] */
/* @0x228980 ubfx r3, r5, #0x0, #0xf */
/* @0x228984 ubfx r5, r5, #0xf, #0xf */
/* @0x228988 rsb r11, r3, r2 */
/* @0x22898c b 0x228994 <vorbis_book_decodev_add+0x240> */
/* @0x228990 sub r4, r4, #1 */
/* @0x228994 mov r0, r6 */
/* @0x228998 mov r1, r4 */
/* @0x22899c bl 0x23388c <oggpack_look> */
/* @0x2289a0 cmp r4, #1 */
/* @0x2289a4 movle r3, #0 */
/* @0x2289a8 movgt r3, #1 */
/* @0x2289ac ands r3, r3, r0, lsr #31 */
/* @0x2289b0 bne 0x228990 <vorbis_book_decodev_add+0x23c> */
/* @0x2289b4 cmp r0, #0 */
/* @0x2289b8 blt 0x228aec <vorbis_book_decodev_add+0x398> */
/* @0x2289bc rev r0, r0 */
/* @0x2289c0 movw r1, #0xf0f */
/* @0x2289c4 movw r3, #0xf0f0 */
/* @0x2289c8 bfi r1, r1, #16, #16 */
/* @0x2289cc bfi r3, r3, #16, #16 */
/* @0x2289d0 and r12, r1, r0, lsr #4 */
/* @0x2289d4 and r0, r3, r0, lsl #4 */
/* @0x2289d8 movw r1, #0x3333 */
/* @0x2289dc orr r0, r0, r12 */
/* @0x2289e0 bfi r1, r1, #16, #16 */
/* @0x2289e4 movw r3, #0xcccc */
/* @0x2289e8 bfi r3, r3, #16, #16 */
/* @0x2289ec and r1, r1, r0, lsr #2 */
/* @0x2289f0 and r3, r3, r0, lsl #2 */
/* @0x2289f4 orr r12, r3, r1 */
/* @0x2289f8 rsb r3, r5, r11 */
/* @0x2289fc movw r0, #0xaaaa */
/* @0x228a00 movw r1, #0x5555 */
/* @0x228a04 bfi r0, r0, #16, #16 */
/* @0x228a08 bfi r1, r1, #16, #16 */
/* @0x228a0c cmp r3, #1 */
/* @0x228a10 and r0, r0, r12, lsl #1 */
/* @0x228a14 and r1, r1, r12, lsr #1 */
/* @0x228a18 orr r0, r0, r1 */
/* @0x228a1c ble 0x228a58 <vorbis_book_decodev_add+0x304> */
/* @0x228a20 ldr r12, [r8, #0x14] */
/* @0x228a24 asr r3, r3, #1 */
/* @0x228a28 add r1, r3, r5 */
/* @0x228a2c ldr r1, [r12, r1, lsl #2] */
/* @0x228a30 cmp r1, r0 */
/* @0x228a34 movls lr, r3 */
/* @0x228a38 movhi lr, #0 */
/* @0x228a3c cmp r1, r0 */
/* @0x228a40 add r5, r5, lr */
/* @0x228a44 movls r3, #0 */
/* @0x228a48 rsb r11, r3, r11 */
/* @0x228a4c rsb r3, r5, r11 */
/* @0x228a50 cmp r3, #1 */
/* @0x228a54 bgt 0x228a24 <vorbis_book_decodev_add+0x2d0> */
/* @0x228a58 ldr r3, [r8, #0x1c] */
/* @0x228a5c mov r0, r6 */
/* @0x228a60 ldrb r1, [r3, r5] */
/* @0x228a64 cmp r1, r4 */
/* @0x228a68 bgt 0x228938 <vorbis_book_decodev_add+0x1e4> */
/* @0x228a6c bl 0x233a7c <oggpack_adv> */
/* @0x228a70 ldr r4, [r8] */
/* @0x228a74 ldr r3, [r8, #0x10] */
/* @0x228a78 cmp r4, #0 */
/* @0x228a7c mul r5, r5, r4 */
/* @0x228a80 add r3, r3, r5, lsl #2 */
/* @0x228a84 ble 0x228ab4 <vorbis_book_decodev_add+0x360> */
/* @0x228a88 ldr r1, [sp, #0x4] */
/* @0x228a8c rsb r12, r7, #0 */
/* @0x228a90 add r0, r3, r4, lsl #2 */
/* @0x228a94 add r2, r1, r9, lsl #2 */
/* @0x228a98 ldr r5, [r3], #4 */
/* @0x228a9c ldr r1, [r2] */
/* @0x228aa0 cmp r3, r0 */
/* @0x228aa4 add r1, r1, r5, lsl r12 */
/* @0x228aa8 str r1, [r2], #4 */
/* @0x228aac bne 0x228a98 <vorbis_book_decodev_add+0x344> */
/* @0x228ab0 add r9, r9, r4 */
/* @0x228ab4 cmp r10, r9 */
/* @0x228ab8 bgt 0x228954 <vorbis_book_decodev_add+0x200> */
/* @0x228abc b 0x2288f8 <vorbis_book_decodev_add+0x1a4> */
/* @0x228ac0 ldr r3, [r8, #0x1c] */
/* @0x228ac4 mov r0, r6 */
/* @0x228ac8 add r3, r3, r5 */
/* @0x228acc ldrb r1, [r3, #-0x1] */
/* @0x228ad0 bl 0x233a7c <oggpack_adv> */
/* @0x228ad4 subs r5, r5, #1 */
/* @0x228ad8 bhs 0x228a70 <vorbis_book_decodev_add+0x31c> */
/* @0x228adc b 0x228920 <vorbis_book_decodev_add+0x1cc> */
/* @0x228ae0 ldr r11, [r8, #0x8] */
/* @0x228ae4 mov r5, #0 */
/* @0x228ae8 b 0x228994 <vorbis_book_decodev_add+0x240> */
/* @0x228aec mov r0, r6 */
/* @0x228af0 mov r1, #1 */
/* @0x228af4 bl 0x233a7c <oggpack_adv> */
/* @0x228af8 b 0x228920 <vorbis_book_decodev_add+0x1cc> */

/* ── FUNC 0x228afc · vorbis_book_decodev_set · size=1060 · insn=265 */
/* @0x228afc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x228b00 sub sp, sp, #12 */
/* @0x228b04 mov r8, r0 */
/* @0x228b08 mov r6, r2 */
/* @0x228b0c str r1, [sp, #0x4] */
/* @0x228b10 mov r5, r3 */
/* @0x228b14 ldr r1, [r0, #0x8] */
/* @0x228b18 cmp r1, #0 */
/* @0x228b1c ble 0x228d08 <vorbis_book_decodev_set+0x20c> */
/* @0x228b20 ldr r7, [r0, #0xc] */
/* @0x228b24 ldr r3, [sp, #0x30] */
/* @0x228b28 subs r7, r3, r7 */
/* @0x228b2c bmi 0x228d3c <vorbis_book_decodev_set+0x240> */
/* @0x228b30 cmp r5, #0 */
/* @0x228b34 ble 0x228cb4 <vorbis_book_decodev_set+0x1b8> */
/* @0x228b38 mov r9, #0 */
/* @0x228b3c mov r0, r6 */
/* @0x228b40 ldr r1, [r8, #0x24] */
/* @0x228b44 ldr r4, [r8, #0x28] */
/* @0x228b48 bl 0x23388c <oggpack_look> */
/* @0x228b4c cmp r0, #0 */
/* @0x228b50 blt 0x228cfc <vorbis_book_decodev_set+0x200> */
/* @0x228b54 ldr r3, [r8, #0x20] */
/* @0x228b58 ldr r11, [r3, r0, lsl #2] */
/* @0x228b5c cmp r11, #0 */
/* @0x228b60 bge 0x228cd4 <vorbis_book_decodev_set+0x1d8> */
/* @0x228b64 ldr r2, [r8, #0x8] */
/* @0x228b68 ubfx r3, r11, #0x0, #0xf */
/* @0x228b6c ubfx r11, r11, #0xf, #0xf */
/* @0x228b70 rsb r10, r3, r2 */
/* @0x228b74 b 0x228b7c <vorbis_book_decodev_set+0x80> */
/* @0x228b78 sub r4, r4, #1 */
/* @0x228b7c mov r0, r6 */
/* @0x228b80 mov r1, r4 */
/* @0x228b84 bl 0x23388c <oggpack_look> */
/* @0x228b88 cmp r4, #1 */
/* @0x228b8c movle r3, #0 */
/* @0x228b90 movgt r3, #1 */
/* @0x228b94 ands r3, r3, r0, lsr #31 */
/* @0x228b98 bne 0x228b78 <vorbis_book_decodev_set+0x7c> */
/* @0x228b9c cmp r0, #0 */
/* @0x228ba0 blt 0x228f10 <vorbis_book_decodev_set+0x414> */
/* @0x228ba4 rev r0, r0 */
/* @0x228ba8 movw r1, #0xf0f */
/* @0x228bac movw r3, #0xf0f0 */
/* @0x228bb0 bfi r1, r1, #16, #16 */
/* @0x228bb4 bfi r3, r3, #16, #16 */
/* @0x228bb8 and r12, r1, r0, lsr #4 */
/* @0x228bbc and r0, r3, r0, lsl #4 */
/* @0x228bc0 movw r1, #0x3333 */
/* @0x228bc4 orr r0, r0, r12 */
/* @0x228bc8 bfi r1, r1, #16, #16 */
/* @0x228bcc movw r3, #0xcccc */
/* @0x228bd0 bfi r3, r3, #16, #16 */
/* @0x228bd4 and r1, r1, r0, lsr #2 */
/* @0x228bd8 and r3, r3, r0, lsl #2 */
/* @0x228bdc orr r12, r3, r1 */
/* @0x228be0 rsb r3, r11, r10 */
/* @0x228be4 movw r0, #0xaaaa */
/* @0x228be8 movw r1, #0x5555 */
/* @0x228bec bfi r0, r0, #16, #16 */
/* @0x228bf0 bfi r1, r1, #16, #16 */
/* @0x228bf4 cmp r3, #1 */
/* @0x228bf8 and r0, r0, r12, lsl #1 */
/* @0x228bfc and r1, r1, r12, lsr #1 */
/* @0x228c00 orr r0, r0, r1 */
/* @0x228c04 ble 0x228c40 <vorbis_book_decodev_set+0x144> */
/* @0x228c08 ldr r12, [r8, #0x14] */
/* @0x228c0c asr r3, r3, #1 */
/* @0x228c10 add r1, r3, r11 */
/* @0x228c14 ldr r1, [r12, r1, lsl #2] */
/* @0x228c18 cmp r1, r0 */
/* @0x228c1c movls lr, r3 */
/* @0x228c20 movhi lr, #0 */
/* @0x228c24 cmp r1, r0 */
/* @0x228c28 add r11, r11, lr */
/* @0x228c2c movls r3, #0 */
/* @0x228c30 rsb r10, r3, r10 */
/* @0x228c34 rsb r3, r11, r10 */
/* @0x228c38 cmp r3, #1 */
/* @0x228c3c bgt 0x228c0c <vorbis_book_decodev_set+0x110> */
/* @0x228c40 ldr r3, [r8, #0x1c] */
/* @0x228c44 mov r0, r6 */
/* @0x228c48 ldrb r1, [r3, r11] */
/* @0x228c4c cmp r1, r4 */
/* @0x228c50 bgt 0x228d2c <vorbis_book_decodev_set+0x230> */
/* @0x228c54 bl 0x233a7c <oggpack_adv> */
/* @0x228c58 ldr r1, [r8] */
/* @0x228c5c ldr r3, [r8, #0x10] */
/* @0x228c60 cmp r1, #0 */
/* @0x228c64 mul r11, r11, r1 */
/* @0x228c68 add r2, r3, r11, lsl #2 */
/* @0x228c6c ble 0x228cc0 <vorbis_book_decodev_set+0x1c4> */
/* @0x228c70 ldr r0, [r3, r11, lsl #2] */
/* @0x228c74 add r12, r9, #1 */
/* @0x228c78 ldr r4, [sp, #0x4] */
/* @0x228c7c cmp r5, r12 */
/* @0x228c80 asr r0, r0, r7 */
/* @0x228c84 add r3, r4, r9, lsl #2 */
/* @0x228c88 str r0, [r4, r9, lsl #2] */
/* @0x228c8c ble 0x228cb4 <vorbis_book_decodev_set+0x1b8> */
/* @0x228c90 add r9, r1, r9 */
/* @0x228c94 cmp r12, r9 */
/* @0x228c98 beq 0x228cc4 <vorbis_book_decodev_set+0x1c8> */
/* @0x228c9c ldr r1, [r2, #0x4]! */
/* @0x228ca0 add r12, r12, #1 */
/* @0x228ca4 cmp r12, r5 */
/* @0x228ca8 asr r1, r1, r7 */
/* @0x228cac str r1, [r3, #0x4]! */
/* @0x228cb0 bne 0x228c94 <vorbis_book_decodev_set+0x198> */
/* @0x228cb4 mov r0, #0 */
/* @0x228cb8 add sp, sp, #12 */
/* @0x228cbc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x228cc0 mov r12, r9 */
/* @0x228cc4 cmp r5, r12 */
/* @0x228cc8 ble 0x228cb4 <vorbis_book_decodev_set+0x1b8> */
/* @0x228ccc mov r9, r12 */
/* @0x228cd0 b 0x228b3c <vorbis_book_decodev_set+0x40> */
/* @0x228cd4 ldr r3, [r8, #0x1c] */
/* @0x228cd8 mov r0, r6 */
/* @0x228cdc add r3, r3, r11 */
/* @0x228ce0 ldrb r1, [r3, #-0x1] */
/* @0x228ce4 bl 0x233a7c <oggpack_adv> */
/* @0x228ce8 subs r11, r11, #1 */
/* @0x228cec bhs 0x228c58 <vorbis_book_decodev_set+0x15c> */
/* @0x228cf0 mvn r0, #0 */
/* @0x228cf4 add sp, sp, #12 */
/* @0x228cf8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x228cfc ldr r10, [r8, #0x8] */
/* @0x228d00 mov r11, #0 */
/* @0x228d04 b 0x228b7c <vorbis_book_decodev_set+0x80> */
/* @0x228d08 cmp r3, #0 */
/* @0x228d0c ble 0x228cb4 <vorbis_book_decodev_set+0x1b8> */
/* @0x228d10 ldr r10, [sp, #0x4] */
/* @0x228d14 add r5, r10, r3, lsl #2 */
/* @0x228d18 mov r3, #0 */
/* @0x228d1c str r3, [r10], #4 */
/* @0x228d20 cmp r10, r5 */
/* @0x228d24 bne 0x228d1c <vorbis_book_decodev_set+0x220> */
/* @0x228d28 b 0x228cb4 <vorbis_book_decodev_set+0x1b8> */
/* @0x228d2c add r1, r4, #1 */
/* @0x228d30 bl 0x233a7c <oggpack_adv> */
/* @0x228d34 mvn r0, #0 */
/* @0x228d38 b 0x228cf4 <vorbis_book_decodev_set+0x1f8> */
/* @0x228d3c cmp r5, #0 */
/* @0x228d40 movgt r10, #0 */
/* @0x228d44 ble 0x228cb4 <vorbis_book_decodev_set+0x1b8> */
/* @0x228d48 mov r0, r6 */
/* @0x228d4c ldr r1, [r8, #0x24] */
/* @0x228d50 ldr r4, [r8, #0x28] */
/* @0x228d54 bl 0x23388c <oggpack_look> */
/* @0x228d58 cmp r0, #0 */
/* @0x228d5c blt 0x228efc <vorbis_book_decodev_set+0x400> */
/* @0x228d60 ldr r3, [r8, #0x20] */
/* @0x228d64 ldr r11, [r3, r0, lsl #2] */
/* @0x228d68 cmp r11, #0 */
/* @0x228d6c bge 0x228edc <vorbis_book_decodev_set+0x3e0> */
/* @0x228d70 ldr r2, [r8, #0x8] */
/* @0x228d74 ubfx r3, r11, #0x0, #0xf */
/* @0x228d78 ubfx r11, r11, #0xf, #0xf */
/* @0x228d7c rsb r9, r3, r2 */
/* @0x228d80 b 0x228d88 <vorbis_book_decodev_set+0x28c> */
/* @0x228d84 sub r4, r4, #1 */
/* @0x228d88 mov r0, r6 */
/* @0x228d8c mov r1, r4 */
/* @0x228d90 bl 0x23388c <oggpack_look> */
/* @0x228d94 cmp r4, #1 */
/* @0x228d98 movle r3, #0 */
/* @0x228d9c movgt r3, #1 */
/* @0x228da0 ands r3, r3, r0, lsr #31 */
/* @0x228da4 bne 0x228d84 <vorbis_book_decodev_set+0x288> */
/* @0x228da8 cmp r0, #0 */
/* @0x228dac blt 0x228f10 <vorbis_book_decodev_set+0x414> */
/* @0x228db0 rev r0, r0 */
/* @0x228db4 movw r1, #0xf0f */
/* @0x228db8 movw r3, #0xf0f0 */
/* @0x228dbc bfi r1, r1, #16, #16 */
/* @0x228dc0 bfi r3, r3, #16, #16 */
/* @0x228dc4 and r12, r1, r0, lsr #4 */
/* @0x228dc8 and r0, r3, r0, lsl #4 */
/* @0x228dcc movw r1, #0x3333 */
/* @0x228dd0 orr r0, r0, r12 */
/* @0x228dd4 bfi r1, r1, #16, #16 */
/* @0x228dd8 movw r3, #0xcccc */
/* @0x228ddc bfi r3, r3, #16, #16 */
/* @0x228de0 and r1, r1, r0, lsr #2 */
/* @0x228de4 and r3, r3, r0, lsl #2 */
/* @0x228de8 orr r12, r3, r1 */
/* @0x228dec rsb r3, r11, r9 */
/* @0x228df0 movw r0, #0xaaaa */
/* @0x228df4 movw r1, #0x5555 */
/* @0x228df8 bfi r0, r0, #16, #16 */
/* @0x228dfc bfi r1, r1, #16, #16 */
/* @0x228e00 cmp r3, #1 */
/* @0x228e04 and r0, r0, r12, lsl #1 */
/* @0x228e08 and r1, r1, r12, lsr #1 */
/* @0x228e0c orr r0, r0, r1 */
/* @0x228e10 ble 0x228e4c <vorbis_book_decodev_set+0x350> */
/* @0x228e14 ldr r12, [r8, #0x14] */
/* @0x228e18 asr r3, r3, #1 */
/* @0x228e1c add r1, r3, r11 */
/* @0x228e20 ldr r1, [r12, r1, lsl #2] */
/* @0x228e24 cmp r1, r0 */
/* @0x228e28 movls lr, r3 */
/* @0x228e2c movhi lr, #0 */
/* @0x228e30 cmp r1, r0 */
/* @0x228e34 add r11, r11, lr */
/* @0x228e38 movls r3, #0 */
/* @0x228e3c rsb r9, r3, r9 */
/* @0x228e40 rsb r3, r11, r9 */
/* @0x228e44 cmp r3, #1 */
/* @0x228e48 bgt 0x228e18 <vorbis_book_decodev_set+0x31c> */
/* @0x228e4c ldr r3, [r8, #0x1c] */
/* @0x228e50 mov r0, r6 */
/* @0x228e54 ldrb r1, [r3, r11] */
/* @0x228e58 cmp r1, r4 */
/* @0x228e5c bgt 0x228d2c <vorbis_book_decodev_set+0x230> */
/* @0x228e60 bl 0x233a7c <oggpack_adv> */
/* @0x228e64 ldr r0, [r8] */
/* @0x228e68 ldr r3, [r8, #0x10] */
/* @0x228e6c cmp r0, #0 */
/* @0x228e70 mul r11, r11, r0 */
/* @0x228e74 add r1, r3, r11, lsl #2 */
/* @0x228e78 ble 0x228f08 <vorbis_book_decodev_set+0x40c> */
/* @0x228e7c ldr r4, [r3, r11, lsl #2] */
/* @0x228e80 add r3, r10, #1 */
/* @0x228e84 ldr r9, [sp, #0x4] */
/* @0x228e88 cmp r5, r3 */
/* @0x228e8c rsb r12, r7, #0 */
/* @0x228e90 lsl r4, r4, r12 */
/* @0x228e94 add r2, r9, r10, lsl #2 */
/* @0x228e98 str r4, [r9, r10, lsl #2] */
/* @0x228e9c ble 0x228cb4 <vorbis_book_decodev_set+0x1b8> */
/* @0x228ea0 add r9, r10, r0 */
/* @0x228ea4 cmp r3, r9 */
/* @0x228ea8 beq 0x228ecc <vorbis_book_decodev_set+0x3d0> */
/* @0x228eac ldr r0, [r1, #0x4]! */
/* @0x228eb0 add r3, r3, #1 */
/* @0x228eb4 cmp r3, r5 */
/* @0x228eb8 lsl r0, r0, r12 */
/* @0x228ebc str r0, [r2, #0x4]! */
/* @0x228ec0 beq 0x228cb4 <vorbis_book_decodev_set+0x1b8> */
/* @0x228ec4 cmp r3, r9 */
/* @0x228ec8 bne 0x228eac <vorbis_book_decodev_set+0x3b0> */
/* @0x228ecc cmp r5, r3 */
/* @0x228ed0 ble 0x228cb4 <vorbis_book_decodev_set+0x1b8> */
/* @0x228ed4 mov r10, r3 */
/* @0x228ed8 b 0x228d48 <vorbis_book_decodev_set+0x24c> */
/* @0x228edc ldr r3, [r8, #0x1c] */
/* @0x228ee0 mov r0, r6 */
/* @0x228ee4 add r3, r3, r11 */
/* @0x228ee8 ldrb r1, [r3, #-0x1] */
/* @0x228eec bl 0x233a7c <oggpack_adv> */
/* @0x228ef0 subs r11, r11, #1 */
/* @0x228ef4 bhs 0x228e64 <vorbis_book_decodev_set+0x368> */
/* @0x228ef8 b 0x228cf0 <vorbis_book_decodev_set+0x1f4> */
/* @0x228efc ldr r9, [r8, #0x8] */
/* @0x228f00 mov r11, #0 */
/* @0x228f04 b 0x228d88 <vorbis_book_decodev_set+0x28c> */
/* @0x228f08 mov r3, r10 */
/* @0x228f0c b 0x228ecc <vorbis_book_decodev_set+0x3d0> */
/* @0x228f10 mov r0, r6 */
/* @0x228f14 mov r1, #1 */
/* @0x228f18 bl 0x233a7c <oggpack_adv> */
/* @0x228f1c b 0x228cf0 <vorbis_book_decodev_set+0x1f4> */

/* ── FUNC 0x228f20 · vorbis_book_decodevv_add · size=1136 · insn=284 */
/* @0x228f20 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x228f24 mov r9, r1 */
/* @0x228f28 ldr r1, [r0, #0x8] */
/* @0x228f2c sub sp, sp, #20 */
/* @0x228f30 mov r11, r0 */
/* @0x228f34 mov r5, r2 */
/* @0x228f38 cmp r1, #0 */
/* @0x228f3c mov r10, r3 */
/* @0x228f40 ble 0x229130 <vorbis_book_decodevv_add+0x210> */
/* @0x228f44 ldr r3, [r0, #0xc] */
/* @0x228f48 ldr r2, [sp, #0x40] */
/* @0x228f4c subs r3, r2, r3 */
/* @0x228f50 str r3, [sp, #0x8] */
/* @0x228f54 bmi 0x229180 <vorbis_book_decodevv_add+0x260> */
/* @0x228f58 ldr r2, [sp, #0x3c] */
/* @0x228f5c mov r4, #0 */
/* @0x228f60 add r2, r5, r2 */
/* @0x228f64 str r2, [sp, #0xc] */
/* @0x228f68 ldr r3, [sp, #0xc] */
/* @0x228f6c cmp r5, r3 */
/* @0x228f70 bge 0x229130 <vorbis_book_decodevv_add+0x210> */
/* @0x228f74 ldr r0, [sp, #0x38] */
/* @0x228f78 ldr r1, [r11, #0x24] */
/* @0x228f7c ldr r6, [r11, #0x28] */
/* @0x228f80 bl 0x23388c <oggpack_look> */
/* @0x228f84 cmp r0, #0 */
/* @0x228f88 blt 0x229164 <vorbis_book_decodevv_add+0x244> */
/* @0x228f8c ldr r3, [r11, #0x20] */
/* @0x228f90 ldr r7, [r3, r0, lsl #2] */
/* @0x228f94 cmp r7, #0 */
/* @0x228f98 bge 0x22913c <vorbis_book_decodevv_add+0x21c> */
/* @0x228f9c ldr r2, [r11, #0x8] */
/* @0x228fa0 ubfx r3, r7, #0x0, #0xf */
/* @0x228fa4 ubfx r7, r7, #0xf, #0xf */
/* @0x228fa8 rsb r8, r3, r2 */
/* @0x228fac ldr r0, [sp, #0x38] */
/* @0x228fb0 mov r1, r6 */
/* @0x228fb4 bl 0x23388c <oggpack_look> */
/* @0x228fb8 cmp r6, #1 */
/* @0x228fbc movle r3, #0 */
/* @0x228fc0 movgt r3, #1 */
/* @0x228fc4 ands r3, r3, r0, lsr #31 */
/* @0x228fc8 beq 0x229014 <vorbis_book_decodevv_add+0xf4> */
/* @0x228fcc str r4, [sp, #0x4] */
/* @0x228fd0 mov r3, r5 */
/* @0x228fd4 ldr r4, [sp, #0x38] */
/* @0x228fd8 mov r5, r6 */
/* @0x228fdc mov r6, r3 */
/* @0x228fe0 sub r5, r5, #1 */
/* @0x228fe4 mov r0, r4 */
/* @0x228fe8 mov r1, r5 */
/* @0x228fec bl 0x23388c <oggpack_look> */
/* @0x228ff0 cmp r5, #1 */
/* @0x228ff4 movle r2, #0 */
/* @0x228ff8 movgt r2, #1 */
/* @0x228ffc ands r2, r2, r0, lsr #31 */
/* @0x229000 bne 0x228fe0 <vorbis_book_decodevv_add+0xc0> */
/* @0x229004 ldr r4, [sp, #0x4] */
/* @0x229008 mov r3, r6 */
/* @0x22900c mov r6, r5 */
/* @0x229010 mov r5, r3 */
/* @0x229014 cmp r0, #0 */
/* @0x229018 blt 0x229380 <vorbis_book_decodevv_add+0x460> */
/* @0x22901c rev r0, r0 */
/* @0x229020 movw r3, #0xf0f */
/* @0x229024 movw r1, #0xf0f0 */
/* @0x229028 bfi r3, r3, #16, #16 */
/* @0x22902c bfi r1, r1, #16, #16 */
/* @0x229030 and r3, r3, r0, lsr #4 */
/* @0x229034 and r0, r1, r0, lsl #4 */
/* @0x229038 movw r1, #0x3333 */
/* @0x22903c orr r0, r0, r3 */
/* @0x229040 bfi r1, r1, #16, #16 */
/* @0x229044 movw r3, #0xcccc */
/* @0x229048 bfi r3, r3, #16, #16 */
/* @0x22904c and r1, r1, r0, lsr #2 */
/* @0x229050 and r3, r3, r0, lsl #2 */
/* @0x229054 orr r12, r3, r1 */
/* @0x229058 rsb r3, r7, r8 */
/* @0x22905c movw r0, #0xaaaa */
/* @0x229060 movw r1, #0x5555 */
/* @0x229064 bfi r0, r0, #16, #16 */
/* @0x229068 bfi r1, r1, #16, #16 */
/* @0x22906c cmp r3, #1 */
/* @0x229070 and r0, r0, r12, lsl #1 */
/* @0x229074 and r1, r1, r12, lsr #1 */
/* @0x229078 orr r0, r0, r1 */
/* @0x22907c ble 0x2290b8 <vorbis_book_decodevv_add+0x198> */
/* @0x229080 ldr lr, [r11, #0x14] */
/* @0x229084 asr r3, r3, #1 */
/* @0x229088 add r2, r3, r7 */
/* @0x22908c ldr r2, [lr, r2, lsl #2] */
/* @0x229090 cmp r2, r0 */
/* @0x229094 movls r1, r3 */
/* @0x229098 movhi r1, #0 */
/* @0x22909c cmp r2, r0 */
/* @0x2290a0 add r7, r7, r1 */
/* @0x2290a4 movls r3, #0 */
/* @0x2290a8 rsb r8, r3, r8 */
/* @0x2290ac rsb r3, r7, r8 */
/* @0x2290b0 cmp r3, #1 */
/* @0x2290b4 bgt 0x229084 <vorbis_book_decodevv_add+0x164> */
/* @0x2290b8 ldr r3, [r11, #0x1c] */
/* @0x2290bc ldr r0, [sp, #0x38] */
/* @0x2290c0 ldrb r1, [r3, r7] */
/* @0x2290c4 cmp r1, r6 */
/* @0x2290c8 bgt 0x229170 <vorbis_book_decodevv_add+0x250> */
/* @0x2290cc bl 0x233a7c <oggpack_adv> */
/* @0x2290d0 ldr r1, [r11] */
/* @0x2290d4 ldr r3, [r11, #0x10] */
/* @0x2290d8 cmp r1, #0 */
/* @0x2290dc mul r7, r7, r1 */
/* @0x2290e0 add r7, r3, r7, lsl #2 */
/* @0x2290e4 ble 0x228f68 <vorbis_book_decodevv_add+0x48> */
/* @0x2290e8 ldr r12, [sp, #0x8] */
/* @0x2290ec add r1, r7, r1, lsl #2 */
/* @0x2290f0 mov r3, r4 */
/* @0x2290f4 ldr r3, [r9, r3, lsl #2] */
/* @0x2290f8 add r4, r4, #1 */
/* @0x2290fc ldr r0, [r7], #4 */
/* @0x229100 cmp r4, r10 */
/* @0x229104 ldr r2, [r3, r5, lsl #2] */
/* @0x229108 moveq r4, #0 */
/* @0x22910c add r2, r2, r0, asr r12 */
/* @0x229110 str r2, [r3, r5, lsl #2] */
/* @0x229114 addeq r5, r5, #1 */
/* @0x229118 cmp r7, r1 */
/* @0x22911c mov r3, r4 */
/* @0x229120 bne 0x2290f4 <vorbis_book_decodevv_add+0x1d4> */
/* @0x229124 ldr r3, [sp, #0xc] */
/* @0x229128 cmp r5, r3 */
/* @0x22912c blt 0x228f74 <vorbis_book_decodevv_add+0x54> */
/* @0x229130 mov r0, #0 */
/* @0x229134 add sp, sp, #20 */
/* @0x229138 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22913c ldr r3, [r11, #0x1c] */
/* @0x229140 ldr r0, [sp, #0x38] */
/* @0x229144 add r3, r3, r7 */
/* @0x229148 ldrb r1, [r3, #-0x1] */
/* @0x22914c bl 0x233a7c <oggpack_adv> */
/* @0x229150 subs r7, r7, #1 */
/* @0x229154 bhs 0x2290d0 <vorbis_book_decodevv_add+0x1b0> */
/* @0x229158 mvn r0, #0 */
/* @0x22915c add sp, sp, #20 */
/* @0x229160 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x229164 ldr r8, [r11, #0x8] */
/* @0x229168 mov r7, #0 */
/* @0x22916c b 0x228fac <vorbis_book_decodevv_add+0x8c> */
/* @0x229170 add r1, r6, #1 */
/* @0x229174 bl 0x233a7c <oggpack_adv> */
/* @0x229178 mvn r0, #0 */
/* @0x22917c b 0x22915c <vorbis_book_decodevv_add+0x23c> */
/* @0x229180 ldr r3, [sp, #0x3c] */
/* @0x229184 mov r4, #0 */
/* @0x229188 add r3, r5, r3 */
/* @0x22918c str r3, [sp, #0xc] */
/* @0x229190 ldr r3, [sp, #0xc] */
/* @0x229194 cmp r5, r3 */
/* @0x229198 bge 0x229130 <vorbis_book_decodevv_add+0x210> */
/* @0x22919c ldr r0, [sp, #0x38] */
/* @0x2291a0 ldr r1, [r11, #0x24] */
/* @0x2291a4 ldr r6, [r11, #0x28] */
/* @0x2291a8 bl 0x23388c <oggpack_look> */
/* @0x2291ac cmp r0, #0 */
/* @0x2291b0 blt 0x229374 <vorbis_book_decodevv_add+0x454> */
/* @0x2291b4 ldr r3, [r11, #0x20] */
/* @0x2291b8 ldr r7, [r3, r0, lsl #2] */
/* @0x2291bc cmp r7, #0 */
/* @0x2291c0 bge 0x229354 <vorbis_book_decodevv_add+0x434> */
/* @0x2291c4 ldr r2, [r11, #0x8] */
/* @0x2291c8 ubfx r3, r7, #0x0, #0xf */
/* @0x2291cc ubfx r7, r7, #0xf, #0xf */
/* @0x2291d0 rsb r8, r3, r2 */
/* @0x2291d4 ldr r0, [sp, #0x38] */
/* @0x2291d8 mov r1, r6 */
/* @0x2291dc bl 0x23388c <oggpack_look> */
/* @0x2291e0 cmp r6, #1 */
/* @0x2291e4 movle r3, #0 */
/* @0x2291e8 movgt r3, #1 */
/* @0x2291ec ands r3, r3, r0, lsr #31 */
/* @0x2291f0 beq 0x22923c <vorbis_book_decodevv_add+0x31c> */
/* @0x2291f4 str r4, [sp, #0x4] */
/* @0x2291f8 mov r3, r5 */
/* @0x2291fc ldr r4, [sp, #0x38] */
/* @0x229200 mov r5, r6 */
/* @0x229204 mov r6, r3 */
/* @0x229208 sub r5, r5, #1 */
/* @0x22920c mov r0, r4 */
/* @0x229210 mov r1, r5 */
/* @0x229214 bl 0x23388c <oggpack_look> */
/* @0x229218 cmp r5, #1 */
/* @0x22921c movle r2, #0 */
/* @0x229220 movgt r2, #1 */
/* @0x229224 ands r2, r2, r0, lsr #31 */
/* @0x229228 bne 0x229208 <vorbis_book_decodevv_add+0x2e8> */
/* @0x22922c ldr r4, [sp, #0x4] */
/* @0x229230 mov r3, r6 */
/* @0x229234 mov r6, r5 */
/* @0x229238 mov r5, r3 */
/* @0x22923c cmp r0, #0 */
/* @0x229240 blt 0x229380 <vorbis_book_decodevv_add+0x460> */
/* @0x229244 rev r0, r0 */
/* @0x229248 movw r1, #0xf0f */
/* @0x22924c movw r3, #0xf0f0 */
/* @0x229250 bfi r1, r1, #16, #16 */
/* @0x229254 bfi r3, r3, #16, #16 */
/* @0x229258 and r12, r1, r0, lsr #4 */
/* @0x22925c and r0, r3, r0, lsl #4 */
/* @0x229260 movw r1, #0x3333 */
/* @0x229264 orr r0, r0, r12 */
/* @0x229268 bfi r1, r1, #16, #16 */
/* @0x22926c movw r3, #0xcccc */
/* @0x229270 bfi r3, r3, #16, #16 */
/* @0x229274 and r1, r1, r0, lsr #2 */
/* @0x229278 and r3, r3, r0, lsl #2 */
/* @0x22927c orr r12, r3, r1 */
/* @0x229280 rsb r3, r7, r8 */
/* @0x229284 movw r0, #0xaaaa */
/* @0x229288 movw r1, #0x5555 */
/* @0x22928c bfi r0, r0, #16, #16 */
/* @0x229290 bfi r1, r1, #16, #16 */
/* @0x229294 cmp r3, #1 */
/* @0x229298 and r0, r0, r12, lsl #1 */
/* @0x22929c and r1, r1, r12, lsr #1 */
/* @0x2292a0 orr r0, r0, r1 */
/* @0x2292a4 ble 0x2292e0 <vorbis_book_decodevv_add+0x3c0> */
/* @0x2292a8 ldr r12, [r11, #0x14] */
/* @0x2292ac asr r3, r3, #1 */
/* @0x2292b0 add r2, r3, r7 */
/* @0x2292b4 ldr r2, [r12, r2, lsl #2] */
/* @0x2292b8 cmp r2, r0 */
/* @0x2292bc movls r1, r3 */
/* @0x2292c0 movhi r1, #0 */
/* @0x2292c4 cmp r2, r0 */
/* @0x2292c8 add r7, r7, r1 */
/* @0x2292cc movls r3, #0 */
/* @0x2292d0 rsb r8, r3, r8 */
/* @0x2292d4 rsb r3, r7, r8 */
/* @0x2292d8 cmp r3, #1 */
/* @0x2292dc bgt 0x2292ac <vorbis_book_decodevv_add+0x38c> */
/* @0x2292e0 ldr r3, [r11, #0x1c] */
/* @0x2292e4 ldr r0, [sp, #0x38] */
/* @0x2292e8 ldrb r1, [r3, r7] */
/* @0x2292ec cmp r1, r6 */
/* @0x2292f0 bgt 0x229170 <vorbis_book_decodevv_add+0x250> */
/* @0x2292f4 bl 0x233a7c <oggpack_adv> */
/* @0x2292f8 ldr r0, [r11] */
/* @0x2292fc ldr r3, [r11, #0x10] */
/* @0x229300 cmp r0, #0 */
/* @0x229304 mul r7, r7, r0 */
/* @0x229308 add r3, r3, r7, lsl #2 */
/* @0x22930c ble 0x229190 <vorbis_book_decodevv_add+0x270> */
/* @0x229310 ldr r2, [sp, #0x8] */
/* @0x229314 add r0, r3, r0, lsl #2 */
/* @0x229318 rsb r12, r2, #0 */
/* @0x22931c mov r2, r4 */
/* @0x229320 ldr r2, [r9, r2, lsl #2] */
/* @0x229324 add r4, r4, #1 */
/* @0x229328 ldr r6, [r3], #4 */
/* @0x22932c cmp r4, r10 */
/* @0x229330 ldr r1, [r2, r5, lsl #2] */
/* @0x229334 moveq r4, #0 */
/* @0x229338 add r1, r1, r6, lsl r12 */
/* @0x22933c str r1, [r2, r5, lsl #2] */
/* @0x229340 addeq r5, r5, #1 */
/* @0x229344 cmp r3, r0 */
/* @0x229348 mov r2, r4 */
/* @0x22934c bne 0x229320 <vorbis_book_decodevv_add+0x400> */
/* @0x229350 b 0x229190 <vorbis_book_decodevv_add+0x270> */
/* @0x229354 ldr r3, [r11, #0x1c] */
/* @0x229358 ldr r0, [sp, #0x38] */
/* @0x22935c add r3, r3, r7 */
/* @0x229360 ldrb r1, [r3, #-0x1] */
/* @0x229364 bl 0x233a7c <oggpack_adv> */
/* @0x229368 subs r7, r7, #1 */
/* @0x22936c bhs 0x2292f8 <vorbis_book_decodevv_add+0x3d8> */
/* @0x229370 b 0x229158 <vorbis_book_decodevv_add+0x238> */
/* @0x229374 ldr r8, [r11, #0x8] */
/* @0x229378 mov r7, #0 */
/* @0x22937c b 0x2291d4 <vorbis_book_decodevv_add+0x2b4> */
/* @0x229380 ldr r0, [sp, #0x38] */
/* @0x229384 mov r1, #1 */
/* @0x229388 bl 0x233a7c <oggpack_adv> */
/* @0x22938c b 0x229158 <vorbis_book_decodevv_add+0x238> */

/* ── FUNC 0x229390 · anon_229390 · size=1308 · insn=327 */
/* @0x229390 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x229394 add r11, r0, #4 */
/* @0x229398 ldr r4, [r1, #0x10] */
/* @0x22939c sub sp, sp, #12 */
/* @0x2293a0 mov r5, r1 */
/* @0x2293a4 mov r9, r0 */
/* @0x2293a8 mov r0, r11 */
/* @0x2293ac ldr r1, [r4, #0xc] */
/* @0x2293b0 bl 0x233b28 <oggpack_read> */
/* @0x2293b4 subs r6, r0, #0 */
/* @0x2293b8 ble 0x2294d4 <vorbis_book_decodevv_add+0x5b4> */
/* @0x2293bc ldr r0, [r4, #0x14] */
/* @0x2293c0 ldr r7, [r4, #0xc] */
/* @0x2293c4 ldr r8, [r4, #0x10] */
/* @0x2293c8 bl 0x22eaf0 <_ilog> */
/* @0x2293cc mov r1, r0 */
/* @0x2293d0 mov r0, r11 */
/* @0x2293d4 bl 0x233b28 <oggpack_read> */
/* @0x2293d8 cmn r0, #1 */
/* @0x2293dc beq 0x2294d4 <vorbis_book_decodevv_add+0x5b4> */
/* @0x2293e0 ldr r3, [r4, #0x14] */
/* @0x2293e4 cmp r0, r3 */
/* @0x2293e8 bge 0x2294d4 <vorbis_book_decodevv_add+0x5b4> */
/* @0x2293ec ldr r3, [r9, #0x40] */
/* @0x2293f0 add r0, r0, #6 */
/* @0x2293f4 ldr r1, [r5, #0x8] */
/* @0x2293f8 mov r10, #52 */
/* @0x2293fc ldr r2, [r4, r0, lsl #2] */
/* @0x229400 mov r0, r9 */
/* @0x229404 ldr r3, [r3, #0x4] */
/* @0x229408 add r1, r1, #1 */
/* @0x22940c lsl r1, r1, #2 */
/* @0x229410 ldr r3, [r3, #0x1c] */
/* @0x229414 ldr r3, [r3, #0xc20] */
/* @0x229418 mla r10, r10, r2, r3 */
/* @0x22941c bl 0x2270e4 <_vorbis_block_alloc> */
/* @0x229420 ldr r3, [r5, #0x8] */
/* @0x229424 mov r2, r11 */
/* @0x229428 mov r1, r0 */
/* @0x22942c mov r9, r0 */
/* @0x229430 mvn r0, #23 */
/* @0x229434 str r0, [sp] */
/* @0x229438 mov r0, r10 */
/* @0x22943c bl 0x228afc <vorbis_book_decodev_set> */
/* @0x229440 cmn r0, #1 */
/* @0x229444 beq 0x2294d4 <vorbis_book_decodevv_add+0x5b4> */
/* @0x229448 ldr r4, [r5, #0x8] */
/* @0x22944c cmp r4, #0 */
/* @0x229450 ble 0x229498 <vorbis_book_decodevv_add+0x578> */
/* @0x229454 ldr lr, [r10] */
/* @0x229458 mov r1, #0 */
/* @0x22945c mov r3, r1 */
/* @0x229460 cmp lr, #0 */
/* @0x229464 ble 0x2294c0 <vorbis_book_decodevv_add+0x5a0> */
/* @0x229468 add r2, r9, r3, lsl #2 */
/* @0x22946c add r0, r3, lr */
/* @0x229470 b 0x22947c <vorbis_book_decodevv_add+0x55c> */
/* @0x229474 cmp r3, r0 */
/* @0x229478 beq 0x2294c0 <vorbis_book_decodevv_add+0x5a0> */
/* @0x22947c ldr r12, [r2] */
/* @0x229480 add r3, r3, #1 */
/* @0x229484 add r12, r12, r1 */
/* @0x229488 str r12, [r2], #4 */
/* @0x22948c ldr r4, [r5, #0x8] */
/* @0x229490 cmp r4, r3 */
/* @0x229494 bgt 0x229474 <vorbis_book_decodevv_add+0x554> */
/* @0x229498 mul r0, r6, r8 */
/* @0x22949c mvn r1, #0 */
/* @0x2294a0 mvn r1, r1, lsl r7 */
/* @0x2294a4 lsl r0, r0, #4 */
/* @0x2294a8 bl 0x318d10 <__divsi3> */
/* @0x2294ac mov r3, r9 */
/* @0x2294b0 str r0, [r9, r4, lsl #2] */
/* @0x2294b4 mov r0, r3 */
/* @0x2294b8 add sp, sp, #12 */
/* @0x2294bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2294c0 sub r2, r3, #-1073741823 */
/* @0x2294c4 cmp r3, r4 */
/* @0x2294c8 ldr r1, [r9, r2, lsl #2] */
/* @0x2294cc blt 0x229460 <vorbis_book_decodevv_add+0x540> */
/* @0x2294d0 b 0x229498 <vorbis_book_decodevv_add+0x578> */
/* @0x2294d4 mov r3, #0 */
/* @0x2294d8 mov r0, r3 */
/* @0x2294dc add sp, sp, #12 */
/* @0x2294e0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2294e4 push {r4, lr} */
/* @0x2294e8 subs r4, r0, #0 */
/* @0x2294ec popeq {r4, pc} */
/* @0x2294f0 ldr r0, [r4, #0xc] */
/* @0x2294f4 cmp r0, #0 */
/* @0x2294f8 beq 0x229500 <vorbis_book_decodevv_add+0x5e0> */
/* @0x2294fc bl 0xb655c <free@plt> */
/* @0x229500 ldr r0, [r4, #0x14] */
/* @0x229504 cmp r0, #0 */
/* @0x229508 beq 0x229510 <vorbis_book_decodevv_add+0x5f0> */
/* @0x22950c bl 0xb655c <free@plt> */
/* @0x229510 mov r0, r4 */
/* @0x229514 mov r1, #0 */
/* @0x229518 mov r2, #24 */
/* @0x22951c bl 0xb65b0 <memset@plt> */
/* @0x229520 mov r0, r4 */
/* @0x229524 pop {r4, lr} */
/* @0x229528 b 0xb655c <free@plt> */
/* @0x22952c push {r4, lr} */
/* @0x229530 subs r4, r0, #0 */
/* @0x229534 popeq {r4, pc} */
/* @0x229538 mov r1, #0 */
/* @0x22953c mov r2, #88 */
/* @0x229540 bl 0xb65b0 <memset@plt> */
/* @0x229544 mov r0, r4 */
/* @0x229548 pop {r4, lr} */
/* @0x22954c b 0xb655c <free@plt> */
/* @0x229550 push {r4, r5, r6, r7, r8, lr} */
/* @0x229554 mov r8, r1 */
/* @0x229558 ldr r7, [r0, #0x1c] */
/* @0x22955c mov r0, #88 */
/* @0x229560 bl 0xb6544 <malloc@plt> */
/* @0x229564 mov r1, #8 */
/* @0x229568 mov r6, r0 */
/* @0x22956c mov r0, r8 */
/* @0x229570 bl 0x233b28 <oggpack_read> */
/* @0x229574 mov r1, #16 */
/* @0x229578 str r0, [r6] */
/* @0x22957c mov r0, r8 */
/* @0x229580 bl 0x233b28 <oggpack_read> */
/* @0x229584 mov r1, #16 */
/* @0x229588 str r0, [r6, #0x4] */
/* @0x22958c mov r0, r8 */
/* @0x229590 bl 0x233b28 <oggpack_read> */
/* @0x229594 mov r1, #6 */
/* @0x229598 str r0, [r6, #0x8] */
/* @0x22959c mov r0, r8 */
/* @0x2295a0 bl 0x233b28 <oggpack_read> */
/* @0x2295a4 mov r1, #8 */
/* @0x2295a8 str r0, [r6, #0xc] */
/* @0x2295ac mov r0, r8 */
/* @0x2295b0 bl 0x233b28 <oggpack_read> */
/* @0x2295b4 mov r1, #4 */
/* @0x2295b8 str r0, [r6, #0x10] */
/* @0x2295bc mov r0, r8 */
/* @0x2295c0 bl 0x233b28 <oggpack_read> */
/* @0x2295c4 ldr r3, [r6] */
/* @0x2295c8 cmp r3, #0 */
/* @0x2295cc add r0, r0, #1 */
/* @0x2295d0 str r0, [r6, #0x14] */
/* @0x2295d4 ble 0x22965c <vorbis_book_decodevv_add+0x73c> */
/* @0x2295d8 ldr r3, [r6, #0x4] */
/* @0x2295dc cmp r3, #0 */
/* @0x2295e0 ble 0x22965c <vorbis_book_decodevv_add+0x73c> */
/* @0x2295e4 ldr r3, [r6, #0x8] */
/* @0x2295e8 cmp r3, #0 */
/* @0x2295ec ble 0x22965c <vorbis_book_decodevv_add+0x73c> */
/* @0x2295f0 cmp r0, #0 */
/* @0x2295f4 ble 0x22965c <vorbis_book_decodevv_add+0x73c> */
/* @0x2295f8 mov r4, r6 */
/* @0x2295fc mov r5, #0 */
/* @0x229600 b 0x229638 <vorbis_book_decodevv_add+0x718> */
/* @0x229604 ldr r1, [r7, #0x1c] */
/* @0x229608 cmp r0, r1 */
/* @0x22960c bge 0x22965c <vorbis_book_decodevv_add+0x73c> */
/* @0x229610 ldr r3, [r7, r2, lsl #2] */
/* @0x229614 ldr r2, [r3, #0xc] */
/* @0x229618 cmp r2, #0 */
/* @0x22961c beq 0x22965c <vorbis_book_decodevv_add+0x73c> */
/* @0x229620 ldr r3, [r3] */
/* @0x229624 cmp r3, #0 */
/* @0x229628 ble 0x22965c <vorbis_book_decodevv_add+0x73c> */
/* @0x22962c ldr r3, [r6, #0x14] */
/* @0x229630 cmp r3, r5 */
/* @0x229634 ble 0x22966c <vorbis_book_decodevv_add+0x74c> */
/* @0x229638 mov r0, r8 */
/* @0x22963c mov r1, #8 */
/* @0x229640 bl 0x233b28 <oggpack_read> */
/* @0x229644 add r5, r5, #1 */
/* @0x229648 add r4, r4, #4 */
/* @0x22964c cmp r0, #0 */
/* @0x229650 str r0, [r4, #0x14] */
/* @0x229654 add r2, r0, #520 */
/* @0x229658 bge 0x229604 <vorbis_book_decodevv_add+0x6e4> */
/* @0x22965c mov r0, r6 */
/* @0x229660 bl 0x22952c <vorbis_book_decodevv_add+0x60c> */
/* @0x229664 mov r0, #0 */
/* @0x229668 pop {r4, r5, r6, r7, r8, pc} */
/* @0x22966c mov r0, r6 */
/* @0x229670 pop {r4, r5, r6, r7, r8, pc} */
/* @0x229674 ldr r3, [r0, #0x4] */
/* @0x229678 mov r0, #1 */
/* @0x22967c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x229680 mov r5, r1 */
/* @0x229684 sub sp, sp, #20 */
/* @0x229688 mov r1, #24 */
/* @0x22968c mov r4, r2 */
/* @0x229690 ldr r6, [r3, #0x1c] */
/* @0x229694 bl 0xb6c34 <calloc@plt> */
/* @0x229698 ldr r2, [r5] */
/* @0x22969c ldr r3, [r4] */
/* @0x2296a0 ldr r5, [r4, #0x8] */
/* @0x2296a4 ldr r8, [r6, r2, lsl #2] */
/* @0x2296a8 add r8, r8, r8, lsr #31 */
/* @0x2296ac asr r8, r8, #1 */
/* @0x2296b0 add r6, r8, #1 */
/* @0x2296b4 lsl r6, r6, #2 */
/* @0x2296b8 str r3, [r0, #0x8] */
/* @0x2296bc str r0, [sp, #0xc] */
/* @0x2296c0 str r4, [r0, #0x10] */
/* @0x2296c4 str r5, [r0, #0x4] */
/* @0x2296c8 str r8, [r0] */
/* @0x2296cc mov r0, r6 */
/* @0x2296d0 bl 0xb6544 <malloc@plt> */
/* @0x2296d4 ldr r3, [sp, #0xc] */
/* @0x2296d8 cmp r8, #0 */
/* @0x2296dc mov r9, r0 */
/* @0x2296e0 str r0, [r3, #0xc] */
/* @0x2296e4 ble 0x22989c <vorbis_book_decodevv_add+0x97c> */
/* @0x2296e8 ldr r11, [r4, #0x4] */
/* @0x2296ec mov r4, #0 */
/* @0x2296f0 ldr r10, [pc, #0x1ac] */
/* @0x2296f4 sub r6, r6, #4 */
/* @0x2296f8 str r6, [sp, #0x8] */
/* @0x2296fc mov r6, r4 */
/* @0x229700 add r11, r11, r11, lsr #31 */
/* @0x229704 add r10, pc, r10 */
/* @0x229708 sub r7, r10, #4 */
/* @0x22970c add r10, r10, #104 */
/* @0x229710 asr r11, r11, #1 */
/* @0x229714 mov r0, r6 */
/* @0x229718 mov r1, r8 */
/* @0x22971c bl 0x318d10 <__divsi3> */
/* @0x229720 mov r3, r7 */
/* @0x229724 mov r2, #1 */
/* @0x229728 ldr r1, [r3, #0x4]! */
/* @0x22972c sub r12, r2, #1 */
/* @0x229730 add r2, r2, #1 */
/* @0x229734 cmp r0, r1 */
/* @0x229738 blt 0x229748 <vorbis_book_decodevv_add+0x828> */
/* @0x22973c ldr lr, [r3, #0x4] */
/* @0x229740 cmp r0, lr */
/* @0x229744 blt 0x229848 <vorbis_book_decodevv_add+0x928> */
/* @0x229748 cmp r3, r10 */
/* @0x22974c bne 0x229728 <vorbis_book_decodevv_add+0x808> */
/* @0x229750 mov r12, #1811939328 */
/* @0x229754 mov r3, r7 */
/* @0x229758 mov r2, #1 */
/* @0x22975c ldr r1, [r3, #0x4]! */
/* @0x229760 sub lr, r2, #1 */
/* @0x229764 add r2, r2, #1 */
/* @0x229768 cmp r1, r11 */
/* @0x22976c bgt 0x22977c <vorbis_book_decodevv_add+0x85c> */
/* @0x229770 ldr r0, [r3, #0x4] */
/* @0x229774 cmp r0, r11 */
/* @0x229778 bgt 0x229870 <vorbis_book_decodevv_add+0x950> */
/* @0x22977c cmp r3, r10 */
/* @0x229780 bne 0x22975c <vorbis_book_decodevv_add+0x83c> */
/* @0x229784 mov r1, #884736 */
/* @0x229788 mov r0, r12 */
/* @0x22978c add r6, r6, r11 */
/* @0x229790 bl 0x318d10 <__divsi3> */
/* @0x229794 ldr r2, [sp, #0x8] */
/* @0x229798 mul r0, r0, r5 */
/* @0x22979c asr r3, r0, #11 */
/* @0x2297a0 cmp r5, r3 */
/* @0x2297a4 suble r3, r5, #1 */
/* @0x2297a8 str r3, [r9, r4] */
/* @0x2297ac add r4, r4, #4 */
/* @0x2297b0 cmp r4, r2 */
/* @0x2297b4 bne 0x229714 <vorbis_book_decodevv_add+0x7f4> */
/* @0x2297b8 lsl r0, r5, #2 */
/* @0x2297bc mvn r3, #0 */
/* @0x2297c0 str r3, [r9, r4] */
/* @0x2297c4 bl 0xb6544 <malloc@plt> */
/* @0x2297c8 ldr r3, [sp, #0xc] */
/* @0x2297cc cmp r5, #0 */
/* @0x2297d0 str r0, [r3, #0x14] */
/* @0x2297d4 ble 0x22983c <vorbis_book_decodevv_add+0x91c> */
/* @0x2297d8 ldr r8, [pc, #0xc8] */
/* @0x2297dc sub r6, r0, #4 */
/* @0x2297e0 lsl r7, r5, #16 */
/* @0x2297e4 mov r4, #0 */
/* @0x2297e8 add r8, pc, r8 */
/* @0x2297ec mov r0, r4 */
/* @0x2297f0 mov r1, r5 */
/* @0x2297f4 bl 0x318d10 <__divsi3> */
/* @0x2297f8 add r4, r4, #65536 */
/* @0x2297fc ubfx r3, r0, #0x0, #0x11 */
/* @0x229800 cmp r3, #65536 */
/* @0x229804 rsbgt r3, r3, #131072 */
/* @0x229808 cmp r4, r7 */
/* @0x22980c ubfx r1, r3, #0x0, #0x9 */
/* @0x229810 asr r3, r3, #9 */
/* @0x229814 add r2, r8, r3, lsl #2 */
/* @0x229818 mov r3, r2 */
/* @0x22981c ldr r2, [r2, #0x70] */
/* @0x229820 ldr r3, [r3, #0x74] */
/* @0x229824 rsb r3, r2, r3 */
/* @0x229828 mul r3, r3, r1 */
/* @0x22982c add r2, r3, r2, lsl #9 */
/* @0x229830 asr r2, r2, #9 */
/* @0x229834 str r2, [r6, #0x4]! */
/* @0x229838 bne 0x2297ec <vorbis_book_decodevv_add+0x8cc> */
/* @0x22983c ldr r0, [sp, #0xc] */
/* @0x229840 add sp, sp, #20 */
/* @0x229844 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x229848 rsb r0, r1, r0 */
/* @0x22984c rsb r1, r1, lr */
/* @0x229850 lsl r12, r12, #15 */
/* @0x229854 str r12, [sp] */
/* @0x229858 lsl r0, r0, #15 */
/* @0x22985c bl 0x318d10 <__divsi3> */
/* @0x229860 ldr r12, [sp] */
/* @0x229864 add r0, r12, r0 */
/* @0x229868 lsl r12, r0, #11 */
/* @0x22986c b 0x229754 <vorbis_book_decodevv_add+0x834> */
/* @0x229870 rsb r3, r1, r11 */
/* @0x229874 rsb r1, r1, r0 */
/* @0x229878 lsl r2, lr, #15 */
/* @0x22987c str r12, [sp] */
/* @0x229880 lsl r0, r3, #15 */
/* @0x229884 str r2, [sp, #0x4] */
/* @0x229888 bl 0x318d10 <__divsi3> */
/* @0x22988c ldr r2, [sp, #0x4] */
/* @0x229890 ldr r12, [sp] */
/* @0x229894 add r1, r2, r0 */
/* @0x229898 b 0x229788 <vorbis_book_decodevv_add+0x868> */
/* @0x22989c mov r4, #0 */
/* @0x2298a0 b 0x2297b8 <vorbis_book_decodevv_add+0x898> */
/* @0x2298a4 andseq r4, r3, r8, lsl #19 */
/* @0x2298a8 andseq r4, r3, r4, lsr #17 */

/* ── FUNC 0x2298ac · vorbis_lsp_to_curve · size=1400 · insn=350 */
/* @0x2298ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2298b0 add r11, sp, #32 */
/* @0x2298b4 sub sp, sp, #84 */
/* @0x2298b8 ldr r3, [pc, #0x550] */
/* @0x2298bc str r2, [r11, #-0x44] */
/* @0x2298c0 ldr r4, [r11, #0x8] */
/* @0x2298c4 ldr r3, [pc, r3] */
/* @0x2298c8 ldr r5, [r11, #0x14] */
/* @0x2298cc mov r8, r1 */
/* @0x2298d0 str r3, [r11, #-0x48] */
/* @0x2298d4 cmp r4, #0 */
/* @0x2298d8 lsl r2, r4, #2 */
/* @0x2298dc ldr r3, [r3] */
/* @0x2298e0 add r2, r2, #14 */
/* @0x2298e4 ldr r6, [r11, #0x4] */
/* @0x2298e8 bic r2, r2, #7 */
/* @0x2298ec str r5, [r11, #-0x50] */
/* @0x2298f0 sub sp, sp, r2 */
/* @0x2298f4 str r3, [r11, #-0x28] */
/* @0x2298f8 str sp, [r11, #-0x34] */
/* @0x2298fc ble 0x229998 <vorbis_lsp_to_curve+0xec> */
/* @0x229900 ldr r2, [r6] */
/* @0x229904 movw r7, #0x7cc2 */
/* @0x229908 movt r7, #0x51 */
/* @0x22990c smull r2, r3, r2, r7 */
/* @0x229910 cmp r3, #0 */
/* @0x229914 mov r5, r3 */
/* @0x229918 blt 0x229d58 <vorbis_lsp_to_curve+0x4ac> */
/* @0x22991c asr r3, r3, #9 */
/* @0x229920 cmp r3, #127 */
/* @0x229924 bgt 0x229d58 <vorbis_lsp_to_curve+0x4ac> */
/* @0x229928 ldr r4, [pc, #0x4e4] */
/* @0x22992c mov r12, #0 */
/* @0x229930 mov r1, r12 */
/* @0x229934 ldr r9, [r11, #-0x34] */
/* @0x229938 add r4, pc, r4 */
/* @0x22993c ldr r10, [r11, #0x8] */
/* @0x229940 b 0x229968 <vorbis_lsp_to_curve+0xbc> */
/* @0x229944 ldr r2, [r6, #0x4]! */
/* @0x229948 lsl r12, r1, #2 */
/* @0x22994c smull r2, r3, r2, r7 */
/* @0x229950 cmp r3, #0 */
/* @0x229954 mov r5, r3 */
/* @0x229958 blt 0x229d58 <vorbis_lsp_to_curve+0x4ac> */
/* @0x22995c asr r3, r3, #9 */
/* @0x229960 cmp r3, #127 */
/* @0x229964 bgt 0x229d58 <vorbis_lsp_to_curve+0x4ac> */
/* @0x229968 add r2, r4, r3, lsl #2 */
/* @0x22996c ubfx r5, r5, #0x0, #0x9 */
/* @0x229970 add r1, r1, #1 */
/* @0x229974 mov r3, r2 */
/* @0x229978 ldr r2, [r2, #0x70] */
/* @0x22997c ldr r3, [r3, #0x74] */
/* @0x229980 cmp r1, r10 */
/* @0x229984 rsb r3, r3, r2 */
/* @0x229988 mul r5, r3, r5 */
/* @0x22998c sub r2, r2, r5, asr #9 */
/* @0x229990 str r2, [r9, r12] */
/* @0x229994 bne 0x229944 <vorbis_lsp_to_curve+0x98> */
/* @0x229998 ldr r6, [r11, #-0x44] */
/* @0x22999c cmp r6, #0 */
/* @0x2299a0 ble 0x229d68 <vorbis_lsp_to_curve+0x4bc> */
/* @0x2299a4 ldr r12, [r11, #0x8] */
/* @0x2299a8 mov r10, #0 */
/* @0x2299ac ldr r2, [pc, #0x464] */
/* @0x2299b0 mov r9, r8 */
/* @0x2299b4 add r1, r12, #1 */
/* @0x2299b8 sub r3, r12, #4 */
/* @0x2299bc ldr r7, [r11, #-0x34] */
/* @0x2299c0 add r2, pc, r2 */
/* @0x2299c4 asr r1, r1, #1 */
/* @0x2299c8 lsr r3, r3, #1 */
/* @0x2299cc str r2, [r11, #-0x40] */
/* @0x2299d0 and r4, r12, #1 */
/* @0x2299d4 sub r1, r1, r1, lsl #3 */
/* @0x2299d8 add r2, r7, r3, lsl #3 */
/* @0x2299dc add r2, r2, #8 */
/* @0x2299e0 str r2, [r11, #-0x60] */
/* @0x2299e4 lsl r1, r1, #1 */
/* @0x2299e8 ldr r2, [r11, #-0x40] */
/* @0x2299ec str r1, [r11, #-0x70] */
/* @0x2299f0 sub r6, r12, r12, lsl #3 */
/* @0x2299f4 ldr r1, [r11, #0x10] */
/* @0x2299f8 lsl r3, r3, #1 */
/* @0x2299fc ldr r5, [pc, #0x418] */
/* @0x229a00 add r3, r3, #5 */
/* @0x229a04 ldr r12, [pc, #0x414] */
/* @0x229a08 add r5, pc, r5 */
/* @0x229a0c lsl r1, r1, #12 */
/* @0x229a10 add r12, pc, r12 */
/* @0x229a14 str r4, [r11, #-0x58] */
/* @0x229a18 str r5, [r11, #-0x68] */
/* @0x229a1c str r6, [r11, #-0x6c] */
/* @0x229a20 str r12, [r11, #-0x5c] */
/* @0x229a24 str r3, [r11, #-0x64] */
/* @0x229a28 str r1, [r11, #-0x54] */
/* @0x229a2c str r2, [r11, #-0x3c] */
/* @0x229a30 ldr r4, [r11, #0x8] */
/* @0x229a34 lsl r8, r10, #2 */
/* @0x229a38 ldr r3, [r9, r10, lsl #2] */
/* @0x229a3c ldr r5, [r11, #-0x50] */
/* @0x229a40 cmp r4, #1 */
/* @0x229a44 str r3, [r11, #-0x38] */
/* @0x229a48 ldr r4, [r5, r3, lsl #2] */
/* @0x229a4c ble 0x229de8 <vorbis_lsp_to_curve+0x53c> */
/* @0x229a50 ldr r6, [r11, #-0x34] */
/* @0x229a54 movw r2, #0xb505 */
/* @0x229a58 ldr r7, [r11, #0x8] */
/* @0x229a5c ldm r6, {r1, r12} */
/* @0x229a60 rsb r1, r4, r1 */
/* @0x229a64 rsb r12, r4, r12 */
/* @0x229a68 cmp r1, #0 */
/* @0x229a6c rsblt r1, r1, #0 */
/* @0x229a70 cmp r12, #0 */
/* @0x229a74 rsblt r12, r12, #0 */
/* @0x229a78 cmp r7, #3 */
/* @0x229a7c mul r1, r2, r1 */
/* @0x229a80 movle r5, #0 */
/* @0x229a84 mul r12, r2, r12 */
/* @0x229a88 movle r6, #3 */
/* @0x229a8c orrle r2, r12, r1 */
/* @0x229a90 lsrle r3, r2, #25 */
/* @0x229a94 ble 0x229b34 <vorbis_lsp_to_curve+0x288> */
/* @0x229a98 ldr r2, [r11, #-0x34] */
/* @0x229a9c mov r5, #0 */
/* @0x229aa0 ldr r7, [r11, #-0x60] */
/* @0x229aa4 ldr r6, [r11, #-0x68] */
/* @0x229aa8 str r10, [r11, #-0x4c] */
/* @0x229aac mov r10, r0 */
/* @0x229ab0 str r8, [r11, #-0x30] */
/* @0x229ab4 orr r0, r12, r1 */
/* @0x229ab8 add r3, r6, r0, lsr #25 */
/* @0x229abc ldrb r3, [r3, #0x274] */
/* @0x229ac0 cmp r3, #0 */
/* @0x229ac4 bne 0x229adc <vorbis_lsp_to_curve+0x230> */
/* @0x229ac8 add r3, r6, r0, lsr #19 */
/* @0x229acc ldrb r3, [r3, #0x2b4] */
/* @0x229ad0 cmp r3, #0 */
/* @0x229ad4 addeq r0, r6, r0, lsr #16 */
/* @0x229ad8 ldrbeq r3, [r0, #0x2f4] */
/* @0x229adc ldr r8, [r2, #0x8] */
/* @0x229ae0 add r2, r2, #8 */
/* @0x229ae4 ldr r0, [r2, #0x4] */
/* @0x229ae8 lsr r1, r1, r3 */
/* @0x229aec rsb r8, r4, r8 */
/* @0x229af0 lsr r12, r12, r3 */
/* @0x229af4 rsb r0, r4, r0 */
/* @0x229af8 cmp r8, #0 */
/* @0x229afc rsblt r8, r8, #0 */
/* @0x229b00 cmp r0, #0 */
/* @0x229b04 rsblt r0, r0, #0 */
/* @0x229b08 cmp r2, r7 */
/* @0x229b0c add r5, r5, r3 */
/* @0x229b10 mul r1, r8, r1 */
/* @0x229b14 mul r12, r0, r12 */
/* @0x229b18 bne 0x229ab4 <vorbis_lsp_to_curve+0x208> */
/* @0x229b1c orr r2, r1, r12 */
/* @0x229b20 mov r0, r10 */
/* @0x229b24 ldr r8, [r11, #-0x30] */
/* @0x229b28 ldr r10, [r11, #-0x4c] */
/* @0x229b2c lsr r3, r2, #25 */
/* @0x229b30 ldr r6, [r11, #-0x64] */
/* @0x229b34 ldr r7, [r11, #-0x40] */
/* @0x229b38 add r3, r7, r3 */
/* @0x229b3c ldrb r3, [r3, #0x274] */
/* @0x229b40 cmp r3, #0 */
/* @0x229b44 bne 0x229b5c <vorbis_lsp_to_curve+0x2b0> */
/* @0x229b48 add r3, r7, r2, lsr #19 */
/* @0x229b4c ldrb r3, [r3, #0x2b4] */
/* @0x229b50 cmp r3, #0 */
/* @0x229b54 addeq r2, r7, r2, lsr #16 */
/* @0x229b58 ldrbeq r3, [r2, #0x2f4] */
/* @0x229b5c ldr r2, [r11, #-0x58] */
/* @0x229b60 cmp r2, #0 */
/* @0x229b64 beq 0x229d98 <vorbis_lsp_to_curve+0x4ec> */
/* @0x229b68 lsr r1, r1, r3 */
/* @0x229b6c lsr r12, r12, r3 */
/* @0x229b70 add r3, r5, r3 */
/* @0x229b74 ldr r5, [r11, #-0x34] */
/* @0x229b78 sub r6, r6, #-1073741823 */
/* @0x229b7c lsl r12, r12, #14 */
/* @0x229b80 ldr r2, [r5, r6, lsl #2] */
/* @0x229b84 ldr r6, [r11, #-0x5c] */
/* @0x229b88 rsb r2, r4, r2 */
/* @0x229b8c cmp r2, #0 */
/* @0x229b90 rsblt r2, r2, #0 */
/* @0x229b94 mul r1, r2, r1 */
/* @0x229b98 orr r5, r12, r1 */
/* @0x229b9c add r2, r6, r5, lsr #25 */
/* @0x229ba0 ldrb r2, [r2, #0x274] */
/* @0x229ba4 cmp r2, #0 */
/* @0x229ba8 bne 0x229bc0 <vorbis_lsp_to_curve+0x314> */
/* @0x229bac add r2, r6, r5, lsr #19 */
/* @0x229bb0 ldrb r2, [r2, #0x2b4] */
/* @0x229bb4 cmp r2, #0 */
/* @0x229bb8 addeq r5, r6, r5, lsr #16 */
/* @0x229bbc ldrbeq r2, [r5, #0x2f4] */
/* @0x229bc0 lsr r12, r12, r2 */
/* @0x229bc4 lsr r1, r1, r2 */
/* @0x229bc8 mul r4, r4, r4 */
/* @0x229bcc ldr r7, [r11, #-0x70] */
/* @0x229bd0 mul r12, r12, r12 */
/* @0x229bd4 add r2, r7, r2 */
/* @0x229bd8 mul r1, r1, r1 */
/* @0x229bdc add r3, r2, r3 */
/* @0x229be0 asr r4, r4, #14 */
/* @0x229be4 ldr r5, [r11, #0x8] */
/* @0x229be8 rsb r4, r4, #16384 */
/* @0x229bec lsr r12, r12, #16 */
/* @0x229bf0 add r3, r5, r3, lsl #1 */
/* @0x229bf4 mul r12, r4, r12 */
/* @0x229bf8 lsr r12, r12, #14 */
/* @0x229bfc add r1, r12, r1, lsr #16 */
/* @0x229c00 lsrs r12, r1, #16 */
/* @0x229c04 bne 0x229d84 <vorbis_lsp_to_curve+0x4d8> */
/* @0x229c08 cmp r1, #0 */
/* @0x229c0c bne 0x229c20 <vorbis_lsp_to_curve+0x374> */
/* @0x229c10 b 0x229e04 <vorbis_lsp_to_curve+0x558> */
/* @0x229c14 lsls r1, r1, #1 */
/* @0x229c18 sub r3, r3, #1 */
/* @0x229c1c beq 0x229e04 <vorbis_lsp_to_curve+0x558> */
/* @0x229c20 tst r1, #32768 */
/* @0x229c24 beq 0x229c14 <vorbis_lsp_to_curve+0x368> */
/* @0x229c28 ubfx r2, r1, #0x9, #0x6 */
/* @0x229c2c ubfx r1, r1, #0x0, #0xa */
/* @0x229c30 ldr r4, [r11, #-0x3c] */
/* @0x229c34 ldr r5, [r11, #-0x3c] */
/* @0x229c38 add r2, r4, r2, lsl #2 */
/* @0x229c3c and r4, r3, #1 */
/* @0x229c40 asr r3, r3, #1 */
/* @0x229c44 ldr r6, [r11, #0xc] */
/* @0x229c48 ldr r12, [r2, #0x400] */
/* @0x229c4c add r4, r5, r4, lsl #2 */
/* @0x229c50 ldr r2, [r2, #0x2fc] */
/* @0x229c54 add r3, r3, #21 */
/* @0x229c58 ldr r4, [r4, #0x500] */
/* @0x229c5c mul r1, r12, r1 */
/* @0x229c60 ldr r7, [r11, #-0x54] */
/* @0x229c64 sub r1, r2, r1, asr #10 */
/* @0x229c68 mul r1, r4, r1 */
/* @0x229c6c asr r3, r1, r3 */
/* @0x229c70 mls r3, r3, r6, r7 */
/* @0x229c74 asrs r2, r3, #9 */
/* @0x229c78 bmi 0x229ddc <vorbis_lsp_to_curve+0x530> */
/* @0x229c7c cmp r2, #1120 */
/* @0x229c80 movge r2, #0 */
/* @0x229c84 movge r3, #0 */
/* @0x229c88 bge 0x229cac <vorbis_lsp_to_curve+0x400> */
/* @0x229c8c asr r3, r3, #14 */
/* @0x229c90 and r2, r2, #31 */
/* @0x229c94 add r3, r5, r3, lsl #2 */
/* @0x229c98 add r2, r5, r2, lsl #2 */
/* @0x229c9c ldr r3, [r3, #0x508] */
/* @0x229ca0 ldr r2, [r2, #0x594] */
/* @0x229ca4 mul r2, r2, r3 */
/* @0x229ca8 asr r3, r2, #31 */
/* @0x229cac ldr r4, [r0, r8] */
/* @0x229cb0 add r1, r8, #4 */
/* @0x229cb4 add r10, r10, #1 */
/* @0x229cb8 asr r7, r4, #31 */
/* @0x229cbc mul r12, r4, r3 */
/* @0x229cc0 umull r4, r5, r4, r2 */
/* @0x229cc4 mla r12, r2, r7, r12 */
/* @0x229cc8 add r12, r12, r5 */
/* @0x229ccc lsr r4, r4, #15 */
/* @0x229cd0 orr r12, r4, r12, lsl #17 */
/* @0x229cd4 ldr r4, [r11, #-0x38] */
/* @0x229cd8 str r12, [r0, r8] */
/* @0x229cdc ldr r12, [r9, r1] */
/* @0x229ce0 cmp r12, r4 */
/* @0x229ce4 str r12, [r11, #-0x30] */
/* @0x229ce8 bne 0x229d48 <vorbis_lsp_to_curve+0x49c> */
/* @0x229cec add r12, r8, #8 */
/* @0x229cf0 mov r7, r9 */
/* @0x229cf4 mov r8, r2 */
/* @0x229cf8 mov r9, r3 */
/* @0x229cfc b 0x229d08 <vorbis_lsp_to_curve+0x45c> */
/* @0x229d00 mov r1, r12 */
/* @0x229d04 mov r12, r6 */
/* @0x229d08 ldr r2, [r0, r1] */
/* @0x229d0c add r10, r10, #1 */
/* @0x229d10 add r6, r12, #4 */
/* @0x229d14 asr r5, r2, #31 */
/* @0x229d18 mul r4, r2, r9 */
/* @0x229d1c umull r2, r3, r2, r8 */
/* @0x229d20 mla r4, r8, r5, r4 */
/* @0x229d24 ldr r5, [r11, #-0x30] */
/* @0x229d28 add r4, r4, r3 */
/* @0x229d2c lsr r2, r2, #15 */
/* @0x229d30 orr r2, r2, r4, lsl #17 */
/* @0x229d34 str r2, [r0, r1] */
/* @0x229d38 ldr r3, [r7, r12] */
/* @0x229d3c cmp r3, r5 */
/* @0x229d40 beq 0x229d00 <vorbis_lsp_to_curve+0x454> */
/* @0x229d44 mov r9, r7 */
/* @0x229d48 ldr r6, [r11, #-0x44] */
/* @0x229d4c cmp r6, r10 */
/* @0x229d50 bgt 0x229a30 <vorbis_lsp_to_curve+0x184> */
/* @0x229d54 b 0x229d68 <vorbis_lsp_to_curve+0x4bc> */
/* @0x229d58 ldr r7, [r11, #-0x44] */
/* @0x229d5c mov r1, #0 */
/* @0x229d60 lsl r2, r7, #2 */
/* @0x229d64 bl 0xb65b0 <memset@plt> */
/* @0x229d68 ldr r7, [r11, #-0x48] */
/* @0x229d6c ldr r2, [r11, #-0x28] */
/* @0x229d70 ldr r3, [r7] */
/* @0x229d74 cmp r2, r3 */
/* @0x229d78 bne 0x229e0c <vorbis_lsp_to_curve+0x560> */
/* @0x229d7c sub sp, r11, #32 */
/* @0x229d80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x229d84 lsr r1, r1, #1 */
/* @0x229d88 add r3, r3, #1 */
/* @0x229d8c ubfx r2, r1, #0x9, #0x6 */
/* @0x229d90 ubfx r1, r1, #0x0, #0xa */
/* @0x229d94 b 0x229c30 <vorbis_lsp_to_curve+0x384> */
/* @0x229d98 lsr r12, r12, r3 */
/* @0x229d9c lsr r1, r1, r3 */
/* @0x229da0 rsb r2, r4, #16384 */
/* @0x229da4 add r4, r4, #16384 */
/* @0x229da8 mul r12, r12, r12 */
/* @0x229dac ldr r6, [r11, #-0x6c] */
/* @0x229db0 mul r1, r1, r1 */
/* @0x229db4 add r3, r6, r3 */
/* @0x229db8 add r3, r3, r5 */
/* @0x229dbc ldr r7, [r11, #0x8] */
/* @0x229dc0 lsr r12, r12, #16 */
/* @0x229dc4 add r3, r7, r3, lsl #1 */
/* @0x229dc8 lsr r1, r1, #16 */
/* @0x229dcc mul r12, r2, r12 */
/* @0x229dd0 mla r1, r4, r1, r12 */
/* @0x229dd4 lsr r1, r1, #14 */
/* @0x229dd8 b 0x229c00 <vorbis_lsp_to_curve+0x354> */
/* @0x229ddc mvn r2, #-2147483648 */
/* @0x229de0 mov r3, #0 */
/* @0x229de4 b 0x229cac <vorbis_lsp_to_curve+0x400> */
/* @0x229de8 movw r2, #0xb505 */
/* @0x229dec mov r3, #0 */
/* @0x229df0 mov r5, r3 */
/* @0x229df4 mov r1, r2 */
/* @0x229df8 mov r12, r2 */
/* @0x229dfc mov r6, #1 */
/* @0x229e00 b 0x229b34 <vorbis_lsp_to_curve+0x288> */
/* @0x229e04 mov r2, r1 */
/* @0x229e08 b 0x229c30 <vorbis_lsp_to_curve+0x384> */
/* @0x229e0c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x229e10 andseq r4, r12, r12, lsl #1 */
/* @0x229e14 andseq r4, r3, r4, asr r7 */
/* @0x229e18 andseq r4, r3, r12, asr #13 */
/* @0x229e1c andseq r4, r3, r4, lsl #13 */
/* @0x229e20 andseq r4, r3, r12, ror r6 */

/* ── FUNC 0x229e24 · anon_229e24 · size=3164 · insn=791 */
/* @0x229e24 push {r4, lr} */
/* @0x229e28 subs r4, r2, #0 */
/* @0x229e2c sub sp, sp, #24 */
/* @0x229e30 mov r12, r1 */
/* @0x229e34 ldr lr, [r1, #0x10] */
/* @0x229e38 beq 0x229e7c <vorbis_lsp_to_curve+0x5d0> */
/* @0x229e3c ldr r2, [r1, #0x8] */
/* @0x229e40 mov r0, r3 */
/* @0x229e44 str r4, [sp] */
/* @0x229e48 ldr r1, [r1, #0xc] */
/* @0x229e4c str r2, [sp, #0x4] */
/* @0x229e50 ldr r4, [r4, r2, lsl #2] */
/* @0x229e54 ldm r12, {r2, r3} */
/* @0x229e58 str r4, [sp, #0x8] */
/* @0x229e5c ldr r4, [r12, #0x14] */
/* @0x229e60 ldr r12, [lr, #0x10] */
/* @0x229e64 str r4, [sp, #0x10] */
/* @0x229e68 str r12, [sp, #0xc] */
/* @0x229e6c bl 0x2298ac <vorbis_lsp_to_curve> */
/* @0x229e70 mov r0, #1 */
/* @0x229e74 add sp, sp, #24 */
/* @0x229e78 pop {r4, pc} */
/* @0x229e7c ldr r2, [r1] */
/* @0x229e80 mov r0, r3 */
/* @0x229e84 mov r1, r4 */
/* @0x229e88 lsl r2, r2, #2 */
/* @0x229e8c bl 0xb65b0 <memset@plt> */
/* @0x229e90 mov r0, r4 */
/* @0x229e94 add sp, sp, #24 */
/* @0x229e98 pop {r4, pc} */
/* @0x229e9c ldr r3, [r0] */
/* @0x229ea0 ldr r2, [r1] */
/* @0x229ea4 ldr r0, [r3] */
/* @0x229ea8 ldr r3, [r2] */
/* @0x229eac rsb r0, r3, r0 */
/* @0x229eb0 bx lr */
/* @0x229eb4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x229eb8 sub sp, sp, #44 */
/* @0x229ebc cmp r2, #0 */
/* @0x229ec0 str r1, [sp, #0x18] */
/* @0x229ec4 str r3, [sp, #0x14] */
/* @0x229ec8 ldr r3, [sp, #0x18] */
/* @0x229ecc str r2, [sp, #0x8] */
/* @0x229ed0 ldr r2, [r0, #0x40] */
/* @0x229ed4 ldr r3, [r3, #0x308] */
/* @0x229ed8 ldr r1, [r0, #0x1c] */
/* @0x229edc str r3, [sp, #0x10] */
/* @0x229ee0 ldr r3, [r2, #0x4] */
/* @0x229ee4 ldr r3, [r3, #0x1c] */
/* @0x229ee8 ldr r3, [r3, r1, lsl #2] */
/* @0x229eec add r3, r3, r3, lsr #31 */
/* @0x229ef0 asr r3, r3, #1 */
/* @0x229ef4 str r3, [sp, #0x1c] */
/* @0x229ef8 beq 0x22a0e0 <vorbis_lsp_to_curve+0x834> */
/* @0x229efc ldr r12, [sp, #0x8] */
/* @0x229f00 ldr r2, [sp, #0x10] */
/* @0x229f04 ldr r3, [r12] */
/* @0x229f08 ldr r4, [r2, #0x340] */
/* @0x229f0c ldr r12, [sp, #0x18] */
/* @0x229f10 mul r4, r4, r3 */
/* @0x229f14 ldr r1, [r12, #0x2fc] */
/* @0x229f18 cmp r1, #1 */
/* @0x229f1c usat r4, #0x8, r4 */
/* @0x229f20 ble 0x22a0fc <vorbis_lsp_to_curve+0x850> */
/* @0x229f24 ldr r7, [pc, #0x1dc] */
/* @0x229f28 mov r10, #0 */
/* @0x229f2c ldr r2, [pc, #0x1d8] */
/* @0x229f30 mov r8, r12 */
/* @0x229f34 ldr r3, [sp, #0x14] */
/* @0x229f38 add r7, pc, r7 */
/* @0x229f3c add r2, pc, r2 */
/* @0x229f40 str r10, [sp, #0x4] */
/* @0x229f44 sub r3, r3, #4 */
/* @0x229f48 str r2, [sp, #0x24] */
/* @0x229f4c str r3, [sp, #0x20] */
/* @0x229f50 mov r6, #1 */
/* @0x229f54 b 0x229f64 <vorbis_lsp_to_curve+0x6b8> */
/* @0x229f58 add r6, r6, #1 */
/* @0x229f5c cmp r1, r6 */
/* @0x229f60 ble 0x22a088 <vorbis_lsp_to_curve+0x7dc> */
/* @0x229f64 ldr r2, [r8, #0x4]! */
/* @0x229f68 ldr r12, [sp, #0x8] */
/* @0x229f6c ldr r3, [r12, r2, lsl #2] */
/* @0x229f70 ubfx r0, r3, #0x0, #0xf */
/* @0x229f74 cmp r3, r0 */
/* @0x229f78 bne 0x229f58 <vorbis_lsp_to_curve+0x6ac> */
/* @0x229f7c ldr r12, [sp, #0x10] */
/* @0x229f80 add r2, r12, r2, lsl #2 */
/* @0x229f84 ldr r1, [r12, #0x340] */
/* @0x229f88 ldr r2, [r2, #0x344] */
/* @0x229f8c mul r3, r1, r3 */
/* @0x229f90 rsb r5, r10, r2 */
/* @0x229f94 str r2, [sp, #0x4] */
/* @0x229f98 mov r1, r5 */
/* @0x229f9c usat r3, #0x8, r3 */
/* @0x229fa0 str r3, [sp, #0xc] */
/* @0x229fa4 rsb r9, r4, r3 */
/* @0x229fa8 eor r3, r9, r9, asr #31 */
/* @0x229fac sub r3, r3, r9, asr #31 */
/* @0x229fb0 str r3, [sp] */
/* @0x229fb4 mov r0, r9 */
/* @0x229fb8 bl 0x318d10 <__divsi3> */
/* @0x229fbc ldr r11, [sp, #0x4] */
/* @0x229fc0 ldr r2, [sp, #0x1c] */
/* @0x229fc4 cmp r9, #0 */
/* @0x229fc8 ldr r3, [sp] */
/* @0x229fcc mul r1, r0, r5 */
/* @0x229fd0 sublt r9, r0, #1 */
/* @0x229fd4 addge r9, r0, #1 */
/* @0x229fd8 cmp r11, r2 */
/* @0x229fdc movge r11, r2 */
/* @0x229fe0 cmp r1, #0 */
/* @0x229fe4 rsblt r1, r1, #0 */
/* @0x229fe8 cmp r11, r10 */
/* @0x229fec rsb r1, r1, r3 */
/* @0x229ff0 ble 0x22a018 <vorbis_lsp_to_curve+0x76c> */
/* @0x229ff4 ldr r3, [sp, #0x14] */
/* @0x229ff8 ldr r12, [sp, #0x24] */
/* @0x229ffc ldr r2, [r3, r10, lsl #2] */
/* @0x22a000 ldr r3, [r12, r4, lsl #2] */
/* @0x22a004 smull r2, r3, r2, r3 */
/* @0x22a008 lsr r2, r2, #15 */
/* @0x22a00c orr r2, r2, r3, lsl #17 */
/* @0x22a010 ldr r3, [sp, #0x14] */
/* @0x22a014 str r2, [r3, r10, lsl #2] */
/* @0x22a018 add r3, r10, #1 */
/* @0x22a01c cmp r11, r3 */
/* @0x22a020 ble 0x22a0cc <vorbis_lsp_to_curve+0x820> */
/* @0x22a024 ldr r2, [sp, #0x20] */
/* @0x22a028 ldr r12, [sp, #0x14] */
/* @0x22a02c add r11, r2, r11, lsl #2 */
/* @0x22a030 add r10, r12, r10, lsl #2 */
/* @0x22a034 mov r12, #0 */
/* @0x22a038 add r12, r12, r1 */
/* @0x22a03c ldr r2, [r10, #0x4] */
/* @0x22a040 cmp r5, r12 */
/* @0x22a044 addle r4, r4, r9 */
/* @0x22a048 addgt r4, r4, r0 */
/* @0x22a04c rsble r12, r5, r12 */
/* @0x22a050 ldr r3, [r7, r4, lsl #2] */
/* @0x22a054 smull r2, r3, r2, r3 */
/* @0x22a058 lsr r2, r2, #15 */
/* @0x22a05c orr r3, r2, r3, lsl #17 */
/* @0x22a060 str r3, [r10, #0x4]! */
/* @0x22a064 cmp r10, r11 */
/* @0x22a068 bne 0x22a038 <vorbis_lsp_to_curve+0x78c> */
/* @0x22a06c ldr r2, [sp, #0x18] */
/* @0x22a070 add r6, r6, #1 */
/* @0x22a074 ldr r4, [sp, #0xc] */
/* @0x22a078 ldr r10, [sp, #0x4] */
/* @0x22a07c ldr r1, [r2, #0x2fc] */
/* @0x22a080 cmp r1, r6 */
/* @0x22a084 bgt 0x229f64 <vorbis_lsp_to_curve+0x6b8> */
/* @0x22a088 ldr r12, [sp, #0x1c] */
/* @0x22a08c ldr r2, [sp, #0x4] */
/* @0x22a090 cmp r12, r2 */
/* @0x22a094 ble 0x22a0c0 <vorbis_lsp_to_curve+0x814> */
/* @0x22a098 ldr r2, [sp, #0x4] */
/* @0x22a09c ldr r12, [sp, #0x14] */
/* @0x22a0a0 add r3, r12, r2, lsl #2 */
/* @0x22a0a4 ldr r2, [sp, #0x1c] */
/* @0x22a0a8 add r1, r12, r2, lsl #2 */
/* @0x22a0ac ldr r2, [r3] */
/* @0x22a0b0 mul r2, r4, r2 */
/* @0x22a0b4 str r2, [r3], #4 */
/* @0x22a0b8 cmp r3, r1 */
/* @0x22a0bc bne 0x22a0ac <vorbis_lsp_to_curve+0x800> */
/* @0x22a0c0 mov r0, #1 */
/* @0x22a0c4 add sp, sp, #44 */
/* @0x22a0c8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22a0cc ldr r12, [sp, #0x18] */
/* @0x22a0d0 ldr r4, [sp, #0xc] */
/* @0x22a0d4 ldr r10, [sp, #0x4] */
/* @0x22a0d8 ldr r1, [r12, #0x2fc] */
/* @0x22a0dc b 0x229f58 <vorbis_lsp_to_curve+0x6ac> */
/* @0x22a0e0 ldr r3, [sp, #0x1c] */
/* @0x22a0e4 ldr r0, [sp, #0x14] */
/* @0x22a0e8 ldr r1, [sp, #0x8] */
/* @0x22a0ec lsl r2, r3, #2 */
/* @0x22a0f0 bl 0xb65b0 <memset@plt> */
/* @0x22a0f4 ldr r0, [sp, #0x8] */
/* @0x22a0f8 b 0x22a0c4 <vorbis_lsp_to_curve+0x818> */
/* @0x22a0fc mov r3, #0 */
/* @0x22a100 str r3, [sp, #0x4] */
/* @0x22a104 b 0x22a088 <vorbis_lsp_to_curve+0x7dc> */
/* @0x22a108 andseq r4, r3, r8, ror #14 */
/* @0x22a10c andseq r4, r3, r4, ror #14 */
/* @0x22a110 ldr r3, [r0, #0x40] */
/* @0x22a114 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22a118 sub sp, sp, #36 */
/* @0x22a11c ldr r3, [r3, #0x4] */
/* @0x22a120 add r9, r0, #4 */
/* @0x22a124 str r1, [sp, #0x14] */
/* @0x22a128 mov r4, r0 */
/* @0x22a12c ldr r2, [sp, #0x14] */
/* @0x22a130 mov r0, r9 */
/* @0x22a134 ldr r3, [r3, #0x1c] */
/* @0x22a138 mov r1, #1 */
/* @0x22a13c ldr r7, [r2, #0x308] */
/* @0x22a140 ldr r10, [r3, #0xc20] */
/* @0x22a144 bl 0x233b28 <oggpack_read> */
/* @0x22a148 cmp r0, #1 */
/* @0x22a14c bne 0x22a424 <vorbis_lsp_to_curve+0xb78> */
/* @0x22a150 ldr r3, [sp, #0x14] */
/* @0x22a154 mov r0, r4 */
/* @0x22a158 ldr r1, [r3, #0x2fc] */
/* @0x22a15c lsl r1, r1, #2 */
/* @0x22a160 bl 0x2270e4 <_vorbis_block_alloc> */
/* @0x22a164 ldr r2, [sp, #0x14] */
/* @0x22a168 ldr r3, [r2, #0x304] */
/* @0x22a16c subs r3, r3, #1 */
/* @0x22a170 str r0, [sp, #0x1c] */
/* @0x22a174 beq 0x22a430 <vorbis_lsp_to_curve+0xb84> */
/* @0x22a178 mov r1, #0 */
/* @0x22a17c lsrs r3, r3, #1 */
/* @0x22a180 add r1, r1, #1 */
/* @0x22a184 bne 0x22a17c <vorbis_lsp_to_curve+0x8d0> */
/* @0x22a188 mov r0, r9 */
/* @0x22a18c bl 0x233b28 <oggpack_read> */
/* @0x22a190 ldr r3, [sp, #0x1c] */
/* @0x22a194 ldr r2, [sp, #0x14] */
/* @0x22a198 str r0, [r3] */
/* @0x22a19c ldr r3, [r2, #0x304] */
/* @0x22a1a0 subs r3, r3, #1 */
/* @0x22a1a4 beq 0x22a438 <vorbis_lsp_to_curve+0xb8c> */
/* @0x22a1a8 mov r1, #0 */
/* @0x22a1ac lsrs r3, r3, #1 */
/* @0x22a1b0 add r1, r1, #1 */
/* @0x22a1b4 bne 0x22a1ac <vorbis_lsp_to_curve+0x900> */
/* @0x22a1b8 mov r0, r9 */
/* @0x22a1bc bl 0x233b28 <oggpack_read> */
/* @0x22a1c0 ldr r3, [sp, #0x1c] */
/* @0x22a1c4 str r0, [r3, #0x4] */
/* @0x22a1c8 ldr r3, [r7] */
/* @0x22a1cc cmp r3, #0 */
/* @0x22a1d0 ble 0x22a2dc <vorbis_lsp_to_curve+0xa30> */
/* @0x22a1d4 mov r3, #0 */
/* @0x22a1d8 mov r2, #2 */
/* @0x22a1dc str r3, [sp, #0xc] */
/* @0x22a1e0 str r7, [sp, #0x18] */
/* @0x22a1e4 str r2, [sp, #0x10] */
/* @0x22a1e8 str r10, [sp, #0x4] */
/* @0x22a1ec str r9, [sp, #0x8] */
/* @0x22a1f0 ldr r3, [sp, #0x18] */
/* @0x22a1f4 ldr r5, [r3, #0x4]! */
/* @0x22a1f8 add r2, r7, r5, lsl #2 */
/* @0x22a1fc str r3, [sp, #0x18] */
/* @0x22a200 mov r3, #1 */
/* @0x22a204 ldr r8, [r2, #0xc0] */
/* @0x22a208 ldr r11, [r2, #0x80] */
/* @0x22a20c cmp r8, #0 */
/* @0x22a210 lsl r6, r3, r8 */
/* @0x22a214 bne 0x22a400 <vorbis_lsp_to_curve+0xb54> */
/* @0x22a218 mov r4, r8 */
/* @0x22a21c cmp r11, #0 */
/* @0x22a220 ble 0x22a2b4 <vorbis_lsp_to_curve+0xa08> */
/* @0x22a224 ldr r3, [sp, #0x10] */
/* @0x22a228 sub r10, r6, #1 */
/* @0x22a22c ldr r2, [sp, #0x1c] */
/* @0x22a230 lsl r9, r5, #3 */
/* @0x22a234 mov r5, #0 */
/* @0x22a238 add r6, r2, r3, lsl #2 */
/* @0x22a23c mov r3, r10 */
/* @0x22a240 mov r10, r8 */
/* @0x22a244 mov r8, r11 */
/* @0x22a248 mov r11, r3 */
/* @0x22a24c b 0x22a26c <vorbis_lsp_to_curve+0x9c0> */
/* @0x22a250 bl 0x2280d0 <vorbis_book_decode> */
/* @0x22a254 cmn r0, #1 */
/* @0x22a258 str r0, [r6] */
/* @0x22a25c beq 0x22a424 <vorbis_lsp_to_curve+0xb78> */
/* @0x22a260 cmp r5, r8 */
/* @0x22a264 add r6, r6, #4 */
/* @0x22a268 beq 0x22a2b0 <vorbis_lsp_to_curve+0xa04> */
/* @0x22a26c and r0, r4, r11 */
/* @0x22a270 ldr r3, [sp, #0x4] */
/* @0x22a274 add r0, r9, r0 */
/* @0x22a278 mov r2, #52 */
/* @0x22a27c add r0, r0, #80 */
/* @0x22a280 add r5, r5, #1 */
/* @0x22a284 ldr r1, [sp, #0x8] */
/* @0x22a288 asr r4, r4, r10 */
/* @0x22a28c ldr r0, [r7, r0, lsl #2] */
/* @0x22a290 cmp r0, #0 */
/* @0x22a294 mla r0, r2, r0, r3 */
/* @0x22a298 bge 0x22a250 <vorbis_lsp_to_curve+0x9a4> */
/* @0x22a29c cmp r5, r8 */
/* @0x22a2a0 mov r2, #0 */
/* @0x22a2a4 add r6, r6, #4 */
/* @0x22a2a8 str r2, [r6, #-0x4] */
/* @0x22a2ac bne 0x22a26c <vorbis_lsp_to_curve+0x9c0> */
/* @0x22a2b0 mov r11, r8 */
/* @0x22a2b4 ldr r3, [sp, #0xc] */
/* @0x22a2b8 ldr r2, [r7] */
/* @0x22a2bc add r3, r3, #1 */
/* @0x22a2c0 str r3, [sp, #0xc] */
/* @0x22a2c4 ldr r3, [sp, #0x10] */
/* @0x22a2c8 add r3, r3, r11 */
/* @0x22a2cc str r3, [sp, #0x10] */
/* @0x22a2d0 ldr r3, [sp, #0xc] */
/* @0x22a2d4 cmp r2, r3 */
/* @0x22a2d8 bgt 0x22a1f0 <vorbis_lsp_to_curve+0x944> */
/* @0x22a2dc ldr r2, [sp, #0x14] */
/* @0x22a2e0 ldr r3, [r2, #0x2fc] */
/* @0x22a2e4 cmp r3, #2 */
/* @0x22a2e8 ble 0x22a440 <vorbis_lsp_to_curve+0xb94> */
/* @0x22a2ec ldr r4, [sp, #0x14] */
/* @0x22a2f0 add r9, r7, #840 */
/* @0x22a2f4 ldr r5, [sp, #0x1c] */
/* @0x22a2f8 mov r6, #2 */
/* @0x22a2fc mov r11, r4 */
/* @0x22a300 mov r8, r5 */
/* @0x22a304 b 0x22a35c <vorbis_lsp_to_curve+0xab0> */
/* @0x22a308 cmp r2, r0 */
/* @0x22a30c rsble r3, r2, r3 */
/* @0x22a310 rsbgt r3, r0, r3 */
/* @0x22a314 mvnle r3, r3 */
/* @0x22a318 add r0, r3, r0 */
/* @0x22a31c ubfx r0, r0, #0x0, #0xf */
/* @0x22a320 str r0, [r5, #0x8] */
/* @0x22a324 ldr r3, [r4, #0x200] */
/* @0x22a328 ldr r2, [r8, r3, lsl #2] */
/* @0x22a32c ubfx r2, r2, #0x0, #0xf */
/* @0x22a330 str r2, [r8, r3, lsl #2] */
/* @0x22a334 ldr r3, [r4, #0x104] */
/* @0x22a338 ldr r2, [r8, r3, lsl #2] */
/* @0x22a33c ubfx r2, r2, #0x0, #0xf */
/* @0x22a340 str r2, [r8, r3, lsl #2] */
/* @0x22a344 ldr r3, [r11, #0x2fc] */
/* @0x22a348 add r6, r6, #1 */
/* @0x22a34c add r4, r4, #4 */
/* @0x22a350 add r5, r5, #4 */
/* @0x22a354 cmp r3, r6 */
/* @0x22a358 ble 0x22a440 <vorbis_lsp_to_curve+0xb94> */
/* @0x22a35c ldr r3, [r4, #0x104] */
/* @0x22a360 ldr r2, [r4, #0x200] */
/* @0x22a364 ldr r0, [r9, #0x4]! */
/* @0x22a368 ldr r10, [r8, r3, lsl #2] */
/* @0x22a36c add r1, r7, r3, lsl #2 */
/* @0x22a370 ldr r12, [r8, r2, lsl #2] */
/* @0x22a374 add r2, r7, r2, lsl #2 */
/* @0x22a378 ubfx r10, r10, #0x0, #0xf */
/* @0x22a37c ldr r1, [r1, #0x344] */
/* @0x22a380 ldr r3, [r2, #0x344] */
/* @0x22a384 ubfx r12, r12, #0x0, #0xf */
/* @0x22a388 rsb r10, r12, r10 */
/* @0x22a38c str r12, [sp] */
/* @0x22a390 eor r2, r10, r10, asr #31 */
/* @0x22a394 sub r2, r2, r10, asr #31 */
/* @0x22a398 rsb r0, r3, r0 */
/* @0x22a39c rsb r1, r3, r1 */
/* @0x22a3a0 mul r0, r0, r2 */
/* @0x22a3a4 bl 0x318d10 <__divsi3> */
/* @0x22a3a8 ldr r12, [sp] */
/* @0x22a3ac ldr r3, [r5, #0x8] */
/* @0x22a3b0 cmp r10, #0 */
/* @0x22a3b4 ldr r2, [r11, #0x304] */
/* @0x22a3b8 rsblt r0, r0, r12 */
/* @0x22a3bc addge r0, r12, r0 */
/* @0x22a3c0 cmp r3, #0 */
/* @0x22a3c4 orreq r0, r0, #32768 */
/* @0x22a3c8 streq r0, [r5, #0x8] */
/* @0x22a3cc beq 0x22a344 <vorbis_lsp_to_curve+0xa98> */
/* @0x22a3d0 rsb r2, r0, r2 */
/* @0x22a3d4 cmp r2, r0 */
/* @0x22a3d8 movlt r1, r2 */
/* @0x22a3dc movge r1, r0 */
/* @0x22a3e0 cmp r3, r1, lsl #1 */
/* @0x22a3e4 bge 0x22a308 <vorbis_lsp_to_curve+0xa5c> */
/* @0x22a3e8 tst r3, #1 */
/* @0x22a3ec addne r3, r3, #1 */
/* @0x22a3f0 asreq r3, r3, #1 */
/* @0x22a3f4 asrne r3, r3, #1 */
/* @0x22a3f8 rsbne r3, r3, #0 */
/* @0x22a3fc b 0x22a318 <vorbis_lsp_to_curve+0xa6c> */
/* @0x22a400 ldr r0, [r2, #0x100] */
/* @0x22a404 mov r2, #52 */
/* @0x22a408 ldr r3, [sp, #0x4] */
/* @0x22a40c ldr r1, [sp, #0x8] */
/* @0x22a410 mla r0, r2, r0, r3 */
/* @0x22a414 bl 0x2280d0 <vorbis_book_decode> */
/* @0x22a418 cmn r0, #1 */
/* @0x22a41c mov r4, r0 */
/* @0x22a420 bne 0x22a21c <vorbis_lsp_to_curve+0x970> */
/* @0x22a424 mov r0, #0 */
/* @0x22a428 add sp, sp, #36 */
/* @0x22a42c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22a430 mov r1, r3 */
/* @0x22a434 b 0x22a188 <vorbis_lsp_to_curve+0x8dc> */
/* @0x22a438 mov r1, r3 */
/* @0x22a43c b 0x22a1b8 <vorbis_lsp_to_curve+0x90c> */
/* @0x22a440 ldr r0, [sp, #0x1c] */
/* @0x22a444 b 0x22a428 <vorbis_lsp_to_curve+0xb7c> */
/* @0x22a448 push {r4, lr} */
/* @0x22a44c subs r4, r0, #0 */
/* @0x22a450 popeq {r4, pc} */
/* @0x22a454 mov r1, #0 */
/* @0x22a458 mov r2, #780 */
/* @0x22a45c bl 0xb65b0 <memset@plt> */
/* @0x22a460 mov r0, r4 */
/* @0x22a464 pop {r4, lr} */
/* @0x22a468 b 0xb655c <free@plt> */
/* @0x22a46c push {r4, lr} */
/* @0x22a470 subs r4, r0, #0 */
/* @0x22a474 popeq {r4, pc} */
/* @0x22a478 mov r1, #0 */
/* @0x22a47c movw r2, #0x448 */
/* @0x22a480 bl 0xb65b0 <memset@plt> */
/* @0x22a484 mov r0, r4 */
/* @0x22a488 pop {r4, lr} */
/* @0x22a48c b 0xb655c <free@plt> */
/* @0x22a490 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22a494 mov r1, #780 */
/* @0x22a498 sub sp, sp, #284 */
/* @0x22a49c mov r0, #1 */
/* @0x22a4a0 mov r4, r2 */
/* @0x22a4a4 bl 0xb6c34 <calloc@plt> */
/* @0x22a4a8 ldr r1, [r4] */
/* @0x22a4ac ldr r3, [r4, #0x348] */
/* @0x22a4b0 cmp r1, #0 */
/* @0x22a4b4 str r0, [sp, #0xc] */
/* @0x22a4b8 str r4, [r0, #0x308] */
/* @0x22a4bc str r3, [r0, #0x300] */
/* @0x22a4c0 ble 0x22a69c <vorbis_lsp_to_curve+0xdf0> */
/* @0x22a4c4 add r1, r4, r1, lsl #2 */
/* @0x22a4c8 mov r3, r4 */
/* @0x22a4cc mov r7, #0 */
/* @0x22a4d0 ldr r2, [r3, #0x4]! */
/* @0x22a4d4 add r2, r2, #32 */
/* @0x22a4d8 cmp r3, r1 */
/* @0x22a4dc ldr r2, [r4, r2, lsl #2] */
/* @0x22a4e0 add r7, r7, r2 */
/* @0x22a4e4 bne 0x22a4d0 <vorbis_lsp_to_curve+0xc24> */
/* @0x22a4e8 add r5, r7, #2 */
/* @0x22a4ec ldr r3, [sp, #0xc] */
/* @0x22a4f0 subs r1, r5, #0 */
/* @0x22a4f4 str r5, [r3, #0x2fc] */
/* @0x22a4f8 ble 0x22a684 <vorbis_lsp_to_curve+0xdd8> */
/* @0x22a4fc add r6, r4, #836 */
/* @0x22a500 add r2, sp, #16 */
/* @0x22a504 mov r0, #0 */
/* @0x22a508 mov r3, r6 */
/* @0x22a50c add r0, r0, #1 */
/* @0x22a510 str r3, [r2, #0x4]! */
/* @0x22a514 cmp r5, r0 */
/* @0x22a518 add r3, r3, #4 */
/* @0x22a51c bgt 0x22a50c <vorbis_lsp_to_curve+0xc60> */
/* @0x22a520 add r8, sp, #20 */
/* @0x22a524 ldr r3, [pc, #0x18c] */
/* @0x22a528 mov r2, #4 */
/* @0x22a52c add r3, pc, r3 */
/* @0x22a530 mov r0, r8 */
/* @0x22a534 bl 0xb66dc <qsort@plt> */
/* @0x22a538 ldr r1, [sp, #0xc] */
/* @0x22a53c mov r3, #0 */
/* @0x22a540 mov r12, r3 */
/* @0x22a544 ldr r2, [r8, r3] */
/* @0x22a548 add r12, r12, #1 */
/* @0x22a54c cmp r5, r12 */
/* @0x22a550 rsb r2, r6, r2 */
/* @0x22a554 asr r2, r2, #2 */
/* @0x22a558 str r2, [r1, r3] */
/* @0x22a55c add r3, r3, #4 */
/* @0x22a560 bgt 0x22a544 <vorbis_lsp_to_curve+0xc98> */
/* @0x22a564 ldr r3, [r4, #0x340] */
/* @0x22a568 sub r3, r3, #1 */
/* @0x22a56c cmp r3, #3 */
/* @0x22a570 addls pc, pc, r3, lsl #2 */
/* @0x22a574 b 0x22a594 <vorbis_lsp_to_curve+0xce8> */
/* @0x22a578 b 0x22a588 <vorbis_lsp_to_curve+0xcdc> */
/* @0x22a57c b 0x22a674 <vorbis_lsp_to_curve+0xdc8> */
/* @0x22a580 b 0x22a664 <vorbis_lsp_to_curve+0xdb8> */
/* @0x22a584 b 0x22a654 <vorbis_lsp_to_curve+0xda8> */
/* @0x22a588 ldr r2, [sp, #0xc] */
/* @0x22a58c mov r3, #256 */
/* @0x22a590 str r3, [r2, #0x304] */
/* @0x22a594 cmp r7, #0 */
/* @0x22a598 ble 0x22a648 <vorbis_lsp_to_curve+0xd9c> */
/* @0x22a59c ldr r3, [sp, #0xc] */
/* @0x22a5a0 mov r9, #1 */
/* @0x22a5a4 ldr r2, [sp, #0xc] */
/* @0x22a5a8 add r11, r4, #840 */
/* @0x22a5ac str r7, [sp, #0x8] */
/* @0x22a5b0 add r4, r4, #832 */
/* @0x22a5b4 ldr r3, [r3, #0x300] */
/* @0x22a5b8 add r10, r2, #508 */
/* @0x22a5bc str r4, [sp, #0x4] */
/* @0x22a5c0 str r3, [sp] */
/* @0x22a5c4 ldr r6, [r11, #0x4]! */
/* @0x22a5c8 mov r1, #0 */
/* @0x22a5cc ldm sp, {r0, r5} */
/* @0x22a5d0 mov r8, r9 */
/* @0x22a5d4 add r9, r9, #1 */
/* @0x22a5d8 mov r4, r1 */
/* @0x22a5dc mov r2, r1 */
/* @0x22a5e0 mov r12, #1 */
/* @0x22a5e4 ldr r3, [r5, #0x4]! */
/* @0x22a5e8 cmp r3, r1 */
/* @0x22a5ec movle r7, #0 */
/* @0x22a5f0 movgt r7, #1 */
/* @0x22a5f4 cmp r3, r6 */
/* @0x22a5f8 movge r7, #0 */
/* @0x22a5fc cmp r7, #0 */
/* @0x22a600 movne r4, r2 */
/* @0x22a604 movne r1, r3 */
/* @0x22a608 cmp r3, r0 */
/* @0x22a60c movge r7, #0 */
/* @0x22a610 movlt r7, #1 */
/* @0x22a614 cmp r3, r6 */
/* @0x22a618 movle r7, #0 */
/* @0x22a61c cmp r7, #0 */
/* @0x22a620 movne r12, r2 */
/* @0x22a624 add r2, r2, #1 */
/* @0x22a628 movne r0, r3 */
/* @0x22a62c cmp r9, r2 */
/* @0x22a630 bne 0x22a5e4 <vorbis_lsp_to_curve+0xd38> */
/* @0x22a634 ldr r3, [sp, #0x8] */
/* @0x22a638 str r4, [r10, #0x4]! */
/* @0x22a63c cmp r8, r3 */
/* @0x22a640 str r12, [r10, #-0xfc] */
/* @0x22a644 bne 0x22a5c4 <vorbis_lsp_to_curve+0xd18> */
/* @0x22a648 ldr r0, [sp, #0xc] */
/* @0x22a64c add sp, sp, #284 */
/* @0x22a650 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22a654 ldr r2, [sp, #0xc] */
/* @0x22a658 mov r3, #64 */
/* @0x22a65c str r3, [r2, #0x304] */
/* @0x22a660 b 0x22a594 <vorbis_lsp_to_curve+0xce8> */
/* @0x22a664 ldr r2, [sp, #0xc] */
/* @0x22a668 mov r3, #86 */
/* @0x22a66c str r3, [r2, #0x304] */
/* @0x22a670 b 0x22a594 <vorbis_lsp_to_curve+0xce8> */
/* @0x22a674 ldr r2, [sp, #0xc] */
/* @0x22a678 mov r3, #128 */
/* @0x22a67c str r3, [r2, #0x304] */
/* @0x22a680 b 0x22a594 <vorbis_lsp_to_curve+0xce8> */
/* @0x22a684 ldr r3, [pc, #0x30] */
/* @0x22a688 add r0, sp, #20 */
/* @0x22a68c mov r2, #4 */
/* @0x22a690 add r3, pc, r3 */
/* @0x22a694 bl 0xb66dc <qsort@plt> */
/* @0x22a698 b 0x22a564 <vorbis_lsp_to_curve+0xcb8> */
/* @0x22a69c ldr r2, [sp, #0xc] */
/* @0x22a6a0 mov r3, #2 */
/* @0x22a6a4 mov r7, #0 */
/* @0x22a6a8 mov r1, r3 */
/* @0x22a6ac mov r5, r3 */
/* @0x22a6b0 str r3, [r2, #0x2fc] */
/* @0x22a6b4 b 0x22a4fc <vorbis_lsp_to_curve+0xc50> */
/* @0x22a6b8 .word 0xfffff968 */
/* @0x22a6bc .word 0xfffff804 */
/* @0x22a6c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22a6c4 mov r5, r1 */
/* @0x22a6c8 sub sp, sp, #276 */
/* @0x22a6cc ldr r8, [r0, #0x1c] */
/* @0x22a6d0 movw r1, #0x448 */
/* @0x22a6d4 mov r0, #1 */
/* @0x22a6d8 bl 0xb6c34 <calloc@plt> */
/* @0x22a6dc mov r1, #5 */
/* @0x22a6e0 mov r7, r0 */
/* @0x22a6e4 mov r0, r5 */
/* @0x22a6e8 bl 0x233b28 <oggpack_read> */
/* @0x22a6ec cmp r0, #0 */
/* @0x22a6f0 str r0, [r7] */
/* @0x22a6f4 movgt r9, r7 */
/* @0x22a6f8 mvngt r6, #0 */
/* @0x22a6fc movgt r4, #0 */
/* @0x22a700 bgt 0x22a71c <vorbis_lsp_to_curve+0xe70> */
/* @0x22a704 b 0x22a828 <vorbis_lsp_to_curve+0xf7c> */
/* @0x22a708 ldr r2, [r7] */
/* @0x22a70c cmp r6, r0 */
/* @0x22a710 movlt r6, r0 */
/* @0x22a714 cmp r2, r4 */
/* @0x22a718 ble 0x22a74c <vorbis_lsp_to_curve+0xea0> */
/* @0x22a71c mov r0, r5 */
/* @0x22a720 mov r1, #4 */
/* @0x22a724 bl 0x233b28 <oggpack_read> */
/* @0x22a728 add r4, r4, #1 */
/* @0x22a72c cmp r0, #0 */
/* @0x22a730 str r0, [r9, #0x4]! */
/* @0x22a734 bge 0x22a708 <vorbis_lsp_to_curve+0xe5c> */
/* @0x22a738 mov r0, r7 */
/* @0x22a73c bl 0x22a46c <vorbis_lsp_to_curve+0xbc0> */
/* @0x22a740 mov r0, #0 */
/* @0x22a744 add sp, sp, #276 */
/* @0x22a748 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22a74c mov r10, r7 */
/* @0x22a750 mov r4, #1 */
/* @0x22a754 add r3, r7, #316 */
/* @0x22a758 str r3, [sp] */
/* @0x22a75c mov r3, #0 */
/* @0x22a760 str r3, [sp, #0x4] */
/* @0x22a764 mov r1, #3 */
/* @0x22a768 mov r0, r5 */
/* @0x22a76c bl 0x233b28 <oggpack_read> */
/* @0x22a770 mov r1, #2 */
/* @0x22a774 add r3, r0, #1 */
/* @0x22a778 mov r0, r5 */
/* @0x22a77c str r3, [r10, #0x80] */
/* @0x22a780 bl 0x233b28 <oggpack_read> */
/* @0x22a784 cmp r0, #0 */
/* @0x22a788 str r0, [r10, #0xc0] */
/* @0x22a78c blt 0x22a738 <vorbis_lsp_to_curve+0xe8c> */
/* @0x22a790 bne 0x22a8c8 <vorbis_lsp_to_curve+0x101c> */
/* @0x22a794 ldr r3, [r10, #0x100] */
/* @0x22a798 cmp r3, #0 */
/* @0x22a79c blt 0x22a738 <vorbis_lsp_to_curve+0xe8c> */
/* @0x22a7a0 ldr r2, [r8, #0x1c] */
/* @0x22a7a4 cmp r2, r3 */
/* @0x22a7a8 ble 0x22a738 <vorbis_lsp_to_curve+0xe8c> */
/* @0x22a7ac ldr r3, [r10, #0xc0] */
/* @0x22a7b0 lsl r3, r4, r3 */
/* @0x22a7b4 cmp r3, #0 */
/* @0x22a7b8 ldrgt r9, [sp] */
/* @0x22a7bc movgt r11, #0 */
/* @0x22a7c0 bgt 0x22a7e0 <vorbis_lsp_to_curve+0xf34> */
/* @0x22a7c4 b 0x22a804 <vorbis_lsp_to_curve+0xf58> */
/* @0x22a7c8 ldr r1, [r8, #0x1c] */
/* @0x22a7cc cmp r0, r1 */
/* @0x22a7d0 bge 0x22a738 <vorbis_lsp_to_curve+0xe8c> */
/* @0x22a7d4 ldr r3, [r10, #0xc0] */
/* @0x22a7d8 cmp r11, r4, lsl r3 */
/* @0x22a7dc bge 0x22a804 <vorbis_lsp_to_curve+0xf58> */
/* @0x22a7e0 mov r0, r5 */
/* @0x22a7e4 mov r1, #8 */
/* @0x22a7e8 bl 0x233b28 <oggpack_read> */
/* @0x22a7ec add r11, r11, #1 */
/* @0x22a7f0 sub r0, r0, #1 */
/* @0x22a7f4 str r0, [r9, #0x4]! */
/* @0x22a7f8 cmn r0, #1 */
/* @0x22a7fc bge 0x22a7c8 <vorbis_lsp_to_curve+0xf1c> */
/* @0x22a800 b 0x22a738 <vorbis_lsp_to_curve+0xe8c> */
/* @0x22a804 ldr r3, [sp, #0x4] */
/* @0x22a808 add r10, r10, #4 */
/* @0x22a80c add r3, r3, #1 */
/* @0x22a810 str r3, [sp, #0x4] */
/* @0x22a814 cmp r3, r6 */
/* @0x22a818 ldr r3, [sp] */
/* @0x22a81c add r3, r3, #32 */
/* @0x22a820 str r3, [sp] */
/* @0x22a824 ble 0x22a764 <vorbis_lsp_to_curve+0xeb8> */
/* @0x22a828 mov r1, #2 */
/* @0x22a82c mov r0, r5 */
/* @0x22a830 bl 0x233b28 <oggpack_read> */
/* @0x22a834 mov r1, #4 */
/* @0x22a838 add r3, r0, #1 */
/* @0x22a83c mov r0, r5 */
/* @0x22a840 str r3, [r7, #0x340] */
/* @0x22a844 bl 0x233b28 <oggpack_read> */
/* @0x22a848 subs r6, r0, #0 */
/* @0x22a84c blt 0x22a738 <vorbis_lsp_to_curve+0xe8c> */
/* @0x22a850 ldr r3, [r7] */
/* @0x22a854 cmp r3, #0 */
/* @0x22a858 ble 0x22a918 <vorbis_lsp_to_curve+0x106c> */
/* @0x22a85c ldr r2, [r7, #0x4] */
/* @0x22a860 add r2, r2, #32 */
/* @0x22a864 ldr r4, [r7, r2, lsl #2] */
/* @0x22a868 cmp r4, #63 */
/* @0x22a86c bgt 0x22a738 <vorbis_lsp_to_curve+0xe8c> */
/* @0x22a870 mov r8, #1 */
/* @0x22a874 mov r9, #0 */
/* @0x22a878 lsl r8, r8, r6 */
/* @0x22a87c mov r11, r9 */
/* @0x22a880 str r7, [sp] */
/* @0x22a884 cmp r11, r4 */
/* @0x22a888 bge 0x22a8e4 <vorbis_lsp_to_curve+0x1038> */
/* @0x22a88c add r3, r7, r11, lsl #2 */
/* @0x22a890 add r10, r3, #840 */
/* @0x22a894 b 0x22a8a8 <vorbis_lsp_to_curve+0xffc> */
/* @0x22a898 cmp r0, r8 */
/* @0x22a89c bge 0x22a738 <vorbis_lsp_to_curve+0xe8c> */
/* @0x22a8a0 cmp r11, r4 */
/* @0x22a8a4 beq 0x22a8e0 <vorbis_lsp_to_curve+0x1034> */
/* @0x22a8a8 mov r0, r5 */
/* @0x22a8ac mov r1, r6 */
/* @0x22a8b0 bl 0x233b28 <oggpack_read> */
/* @0x22a8b4 add r11, r11, #1 */
/* @0x22a8b8 cmp r0, #0 */
/* @0x22a8bc str r0, [r10, #0x4]! */
/* @0x22a8c0 bge 0x22a898 <vorbis_lsp_to_curve+0xfec> */
/* @0x22a8c4 b 0x22a738 <vorbis_lsp_to_curve+0xe8c> */
/* @0x22a8c8 mov r0, r5 */
/* @0x22a8cc mov r1, #8 */
/* @0x22a8d0 bl 0x233b28 <oggpack_read> */
/* @0x22a8d4 mov r3, r0 */
/* @0x22a8d8 str r0, [r10, #0x100] */
/* @0x22a8dc b 0x22a798 <vorbis_lsp_to_curve+0xeec> */
/* @0x22a8e0 ldr r3, [r7] */
/* @0x22a8e4 add r9, r9, #1 */
/* @0x22a8e8 cmp r3, r9 */
/* @0x22a8ec ble 0x22a9bc <vorbis_lsp_to_curve+0x1110> */
/* @0x22a8f0 ldr r1, [sp] */
/* @0x22a8f4 add r1, r1, #4 */
/* @0x22a8f8 ldr r2, [r1, #0x4] */
/* @0x22a8fc str r1, [sp] */
/* @0x22a900 add r2, r2, #32 */
/* @0x22a904 ldr r2, [r7, r2, lsl #2] */
/* @0x22a908 add r4, r4, r2 */
/* @0x22a90c cmp r4, #63 */
/* @0x22a910 ble 0x22a884 <vorbis_lsp_to_curve+0xfd8> */
/* @0x22a914 b 0x22a738 <vorbis_lsp_to_curve+0xe8c> */
/* @0x22a918 mov r3, #1 */
/* @0x22a91c mov r1, #2 */
/* @0x22a920 mov r5, r3 */
/* @0x22a924 mov r2, #0 */
/* @0x22a928 lsl r3, r3, r6 */
/* @0x22a92c str r2, [r7, #0x344] */
/* @0x22a930 str r3, [r7, #0x348] */
/* @0x22a934 add r2, r7, #836 */
/* @0x22a938 add r0, sp, #8 */
/* @0x22a93c mov r3, #0 */
/* @0x22a940 add r3, r3, #1 */
/* @0x22a944 str r2, [r0, #0x4]! */
/* @0x22a948 cmp r3, r5 */
/* @0x22a94c add r2, r2, #4 */
/* @0x22a950 ble 0x22a940 <vorbis_lsp_to_curve+0x1094> */
/* @0x22a954 add r6, sp, #12 */
/* @0x22a958 ldr r3, [pc, #0x90] */
/* @0x22a95c mov r2, #4 */
/* @0x22a960 add r3, pc, r3 */
/* @0x22a964 mov r0, r6 */
/* @0x22a968 bl 0xb66dc <qsort@plt> */
/* @0x22a96c cmp r5, #0 */
/* @0x22a970 ble 0x22a9e8 <vorbis_lsp_to_curve+0x113c> */
/* @0x22a974 ldr r2, [sp, #0xc] */
/* @0x22a978 ldr r3, [sp, #0x10] */
/* @0x22a97c ldr r2, [r2] */
/* @0x22a980 ldr r3, [r3] */
/* @0x22a984 cmp r2, r3 */
/* @0x22a988 beq 0x22a738 <vorbis_lsp_to_curve+0xe8c> */
/* @0x22a98c mov r2, r6 */
/* @0x22a990 mov r3, #1 */
/* @0x22a994 add r3, r3, #1 */
/* @0x22a998 cmp r3, r5 */
/* @0x22a99c bgt 0x22a9e8 <vorbis_lsp_to_curve+0x113c> */
/* @0x22a9a0 ldr r0, [r2, #0x4]! */
/* @0x22a9a4 ldr r1, [r2, #0x4] */
/* @0x22a9a8 ldr r0, [r0] */
/* @0x22a9ac ldr r1, [r1] */
/* @0x22a9b0 cmp r0, r1 */
/* @0x22a9b4 bne 0x22a994 <vorbis_lsp_to_curve+0x10e8> */
/* @0x22a9b8 b 0x22a738 <vorbis_lsp_to_curve+0xe8c> */
/* @0x22a9bc adds r5, r4, #1 */
/* @0x22a9c0 mov r3, #0 */
/* @0x22a9c4 add r1, r4, #2 */
/* @0x22a9c8 str r8, [r7, #0x348] */
/* @0x22a9cc str r3, [r7, #0x344] */
/* @0x22a9d0 bpl 0x22a934 <vorbis_lsp_to_curve+0x1088> */
/* @0x22a9d4 ldr r3, [pc, #0x18] */
/* @0x22a9d8 add r0, sp, #12 */
/* @0x22a9dc mov r2, #4 */
/* @0x22a9e0 add r3, pc, r3 */
/* @0x22a9e4 bl 0xb66dc <qsort@plt> */
/* @0x22a9e8 mov r0, r7 */
/* @0x22a9ec b 0x22a744 <vorbis_lsp_to_curve+0xe98> */
/* @0x22a9f0 .word 0xfffff534 */
/* @0x22a9f4 .word 0xfffff4b4 */
/* @0x22a9f8 cmp r2, #0 */
/* @0x22a9fc str r4, [sp, #-0x4]! */
/* @0x22aa00 ble 0x22aa64 <vorbis_lsp_to_curve+0x11b8> */
/* @0x22aa04 ldr r3, [pc, #0x70] */
/* @0x22aa08 ldrb r4, [r0] */
/* @0x22aa0c ldr r3, [pc, r3] */
/* @0x22aa10 ldrb r12, [r1] */
/* @0x22aa14 ldr r3, [r3] */
/* @0x22aa18 add r4, r3, r4, lsl #1 */
/* @0x22aa1c add r12, r3, r12, lsl #1 */
/* @0x22aa20 ldrsh r4, [r4, #2] */
/* @0x22aa24 ldrsh r12, [r12, #2] */
/* @0x22aa28 cmp r4, r12 */
/* @0x22aa2c bne 0x22aa70 <vorbis_lsp_to_curve+0x11c4> */
/* @0x22aa30 sub r4, r0, #1 */
/* @0x22aa34 add r4, r4, r2 */
/* @0x22aa38 b 0x22aa5c <vorbis_lsp_to_curve+0x11b0> */
/* @0x22aa3c ldrb r12, [r0, #0x1]! */
/* @0x22aa40 ldrb r2, [r1, #0x1]! */
/* @0x22aa44 add r12, r3, r12, lsl #1 */
/* @0x22aa48 add r2, r3, r2, lsl #1 */
/* @0x22aa4c ldrsh r12, [r12, #2] */
/* @0x22aa50 ldrsh r2, [r2, #2] */
/* @0x22aa54 cmp r12, r2 */
/* @0x22aa58 bne 0x22aa70 <vorbis_lsp_to_curve+0x11c4> */
/* @0x22aa5c cmp r0, r4 */
/* @0x22aa60 bne 0x22aa3c <vorbis_lsp_to_curve+0x1190> */
/* @0x22aa64 mov r0, #0 */
/* @0x22aa68 ldr r4, [sp], #4 */
/* @0x22aa6c bx lr */
/* @0x22aa70 mov r0, #1 */
/* @0x22aa74 ldr r4, [sp], #4 */
/* @0x22aa78 bx lr */
/* @0x22aa7c andseq r2, r12, r12, ror pc */

/* ── FUNC 0x22aa80 · vorbis_comment_init · size=12 · insn=3 */
/* @0x22aa80 mov r1, #0 */
/* @0x22aa84 mov r2, #16 */
/* @0x22aa88 b 0xb65b0 <memset@plt> */

/* ── FUNC 0x22aa8c · vorbis_comment_query · size=244 · insn=61 */
/* @0x22aa8c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22aa90 add r11, sp, #32 */
/* @0x22aa94 ldr r3, [pc, #0xdc] */
/* @0x22aa98 sub sp, sp, #20 */
/* @0x22aa9c str r2, [r11, #-0x30] */
/* @0x22aaa0 ldr r3, [pc, r3] */
/* @0x22aaa4 mov r9, r0 */
/* @0x22aaa8 mov r0, r1 */
/* @0x22aaac mov r5, r1 */
/* @0x22aab0 ldr r2, [r3] */
/* @0x22aab4 str r3, [r11, #-0x34] */
/* @0x22aab8 str r2, [r11, #-0x28] */
/* @0x22aabc bl 0xb6538 <strlen@plt> */
/* @0x22aac0 mov r1, r5 */
/* @0x22aac4 add r2, r0, #16 */
/* @0x22aac8 mov r4, r0 */
/* @0x22aacc bic r2, r2, #7 */
/* @0x22aad0 add r8, r0, #1 */
/* @0x22aad4 sub sp, sp, r2 */
/* @0x22aad8 mov r2, r0 */
/* @0x22aadc mov r0, sp */
/* @0x22aae0 mov r6, sp */
/* @0x22aae4 bl 0xb65bc <memcpy@plt> */
/* @0x22aae8 ldr r2, [pc, #0x8c] */
/* @0x22aaec ldr r7, [r9, #0x8] */
/* @0x22aaf0 add r2, pc, r2 */
/* @0x22aaf4 cmp r7, #0 */
/* @0x22aaf8 ldrh r2, [r2] */
/* @0x22aafc strh r2, [sp, r4] */
/* @0x22ab00 ble 0x22ab4c <vorbis_comment_query+0xc0> */
/* @0x22ab04 ldr r3, [r9] */
/* @0x22ab08 mov r5, #0 */
/* @0x22ab0c mov r4, r5 */
/* @0x22ab10 sub r9, r3, #4 */
/* @0x22ab14 ldr r10, [r9, #0x4]! */
/* @0x22ab18 mov r1, r6 */
/* @0x22ab1c mov r2, r8 */
/* @0x22ab20 mov r0, r10 */
/* @0x22ab24 bl 0x22a9f8 <vorbis_lsp_to_curve+0x114c> */
/* @0x22ab28 cmp r0, #0 */
/* @0x22ab2c bne 0x22ab40 <vorbis_comment_query+0xb4> */
/* @0x22ab30 ldr r3, [r11, #-0x30] */
/* @0x22ab34 cmp r3, r5 */
/* @0x22ab38 beq 0x22ab6c <vorbis_comment_query+0xe0> */
/* @0x22ab3c add r5, r5, #1 */
/* @0x22ab40 add r4, r4, #1 */
/* @0x22ab44 cmp r4, r7 */
/* @0x22ab48 bne 0x22ab14 <vorbis_comment_query+0x88> */
/* @0x22ab4c mov r0, #0 */
/* @0x22ab50 ldr r1, [r11, #-0x34] */
/* @0x22ab54 ldr r2, [r11, #-0x28] */
/* @0x22ab58 ldr r3, [r1] */
/* @0x22ab5c cmp r2, r3 */
/* @0x22ab60 bne 0x22ab74 <vorbis_comment_query+0xe8> */
/* @0x22ab64 sub sp, r11, #32 */
/* @0x22ab68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22ab6c add r0, r10, r8 */
/* @0x22ab70 b 0x22ab50 <vorbis_comment_query+0xc4> */
/* @0x22ab74 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x22ab78 ldrheq r2, [r12], -r0 */
/* @0x22ab7c andseq r10, r2, r0, ror #11 */

/* ── FUNC 0x22ab80 · vorbis_comment_query_count · size=204 · insn=51 */
/* @0x22ab80 push {r4, r5, r6, r7, r8, r9, r11, lr} */
/* @0x22ab84 add r11, sp, #28 */
/* @0x22ab88 ldr r9, [pc, #0xb4] */
/* @0x22ab8c sub sp, sp, #8 */
/* @0x22ab90 mov r6, r0 */
/* @0x22ab94 ldr r9, [pc, r9] */
/* @0x22ab98 mov r0, r1 */
/* @0x22ab9c mov r5, r1 */
/* @0x22aba0 ldr r3, [r9] */
/* @0x22aba4 str r3, [r11, #-0x20] */
/* @0x22aba8 bl 0xb6538 <strlen@plt> */
/* @0x22abac mov r1, r5 */
/* @0x22abb0 add r3, r0, #16 */
/* @0x22abb4 mov r4, r0 */
/* @0x22abb8 bic r3, r3, #7 */
/* @0x22abbc mov r2, r0 */
/* @0x22abc0 sub sp, sp, r3 */
/* @0x22abc4 add r7, r0, #1 */
/* @0x22abc8 mov r0, sp */
/* @0x22abcc mov r5, sp */
/* @0x22abd0 bl 0xb65bc <memcpy@plt> */
/* @0x22abd4 ldr r3, [pc, #0x6c] */
/* @0x22abd8 ldr r8, [r6, #0x8] */
/* @0x22abdc add r3, pc, r3 */
/* @0x22abe0 cmp r8, #0 */
/* @0x22abe4 ldrh r3, [r3] */
/* @0x22abe8 strh r3, [sp, r4] */
/* @0x22abec ble 0x22ac38 <vorbis_comment_query_count+0xb8> */
/* @0x22abf0 ldr r4, [r6] */
/* @0x22abf4 mov r6, #0 */
/* @0x22abf8 add r8, r4, r8, lsl #2 */
/* @0x22abfc ldr r0, [r4], #4 */
/* @0x22ac00 mov r1, r5 */
/* @0x22ac04 mov r2, r7 */
/* @0x22ac08 bl 0x22a9f8 <vorbis_lsp_to_curve+0x114c> */
/* @0x22ac0c cmp r0, #0 */
/* @0x22ac10 addeq r6, r6, #1 */
/* @0x22ac14 cmp r4, r8 */
/* @0x22ac18 bne 0x22abfc <vorbis_comment_query_count+0x7c> */
/* @0x22ac1c ldr r2, [r11, #-0x20] */
/* @0x22ac20 mov r0, r6 */
/* @0x22ac24 ldr r3, [r9] */
/* @0x22ac28 cmp r2, r3 */
/* @0x22ac2c bne 0x22ac40 <vorbis_comment_query_count+0xc0> */
/* @0x22ac30 sub sp, r11, #28 */
/* @0x22ac34 pop {r4, r5, r6, r7, r8, r9, r11, pc} */
/* @0x22ac38 mov r6, #0 */
/* @0x22ac3c b 0x22ac1c <vorbis_comment_query_count+0x9c> */
/* @0x22ac40 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x22ac44 ldrheq r2, [r12], -r12 */
/* @0x22ac48 ldrsheq r10, [r2], -r4 */

/* ── FUNC 0x22ac4c · vorbis_comment_clear · size=136 · insn=34 */
/* @0x22ac4c push {r3, r4, r5, lr} */
/* @0x22ac50 subs r5, r0, #0 */
/* @0x22ac54 popeq {r3, r4, r5, pc} */
/* @0x22ac58 ldr r3, [r5] */
/* @0x22ac5c cmp r3, #0 */
/* @0x22ac60 beq 0x22aca0 <vorbis_comment_clear+0x54> */
/* @0x22ac64 ldr r2, [r5, #0x8] */
/* @0x22ac68 cmp r2, #0 */
/* @0x22ac6c ble 0x22ac98 <vorbis_comment_clear+0x4c> */
/* @0x22ac70 mov r4, #0 */
/* @0x22ac74 ldr r0, [r3, r4, lsl #2] */
/* @0x22ac78 add r4, r4, #1 */
/* @0x22ac7c cmp r0, #0 */
/* @0x22ac80 beq 0x22ac90 <vorbis_comment_clear+0x44> */
/* @0x22ac84 bl 0xb655c <free@plt> */
/* @0x22ac88 ldr r3, [r5] */
/* @0x22ac8c ldr r2, [r5, #0x8] */
/* @0x22ac90 cmp r2, r4 */
/* @0x22ac94 bgt 0x22ac74 <vorbis_comment_clear+0x28> */
/* @0x22ac98 mov r0, r3 */
/* @0x22ac9c bl 0xb655c <free@plt> */
/* @0x22aca0 ldr r0, [r5, #0x4] */
/* @0x22aca4 cmp r0, #0 */
/* @0x22aca8 beq 0x22acb0 <vorbis_comment_clear+0x64> */
/* @0x22acac bl 0xb655c <free@plt> */
/* @0x22acb0 ldr r0, [r5, #0xc] */
/* @0x22acb4 cmp r0, #0 */
/* @0x22acb8 beq 0x22acc0 <vorbis_comment_clear+0x74> */
/* @0x22acbc bl 0xb655c <free@plt> */
/* @0x22acc0 mov r0, r5 */
/* @0x22acc4 mov r1, #0 */
/* @0x22acc8 mov r2, #16 */
/* @0x22accc pop {r3, r4, r5, lr} */
/* @0x22acd0 b 0xb65b0 <memset@plt> */

/* ── FUNC 0x22acd4 · vorbis_info_blocksize · size=20 · insn=5 */
/* @0x22acd4 ldr r3, [r0, #0x1c] */
/* @0x22acd8 cmp r3, #0 */
/* @0x22acdc ldrne r0, [r3, r1, lsl #2] */
/* @0x22ace0 mvneq r0, #0 */
/* @0x22ace4 bx lr */

/* ── FUNC 0x22ace8 · vorbis_info_init · size=40 · insn=10 */
/* @0x22ace8 push {r4, lr} */
/* @0x22acec mov r1, #0 */
/* @0x22acf0 mov r2, #32 */
/* @0x22acf4 mov r4, r0 */
/* @0x22acf8 bl 0xb65b0 <memset@plt> */
/* @0x22acfc mov r0, #1 */
/* @0x22ad00 movw r1, #0xca8 */
/* @0x22ad04 bl 0xb6c34 <calloc@plt> */
/* @0x22ad08 str r0, [r4, #0x1c] */
/* @0x22ad0c pop {r4, pc} */

/* ── FUNC 0x22ad10 · vorbis_info_clear · size=436 · insn=109 */
/* @0x22ad10 push {r4, r5, r6, r7, r8, lr} */
/* @0x22ad14 mov r8, r0 */
/* @0x22ad18 ldr r4, [r0, #0x1c] */
/* @0x22ad1c cmp r4, #0 */
/* @0x22ad20 beq 0x22aea4 <vorbis_info_clear+0x194> */
/* @0x22ad24 ldr r3, [r4, #0x8] */
/* @0x22ad28 cmp r3, #0 */
/* @0x22ad2c addgt r6, r4, #28 */
/* @0x22ad30 movgt r5, #0 */
/* @0x22ad34 ble 0x22ad58 <vorbis_info_clear+0x48> */
/* @0x22ad38 ldr r0, [r6, #0x4]! */
/* @0x22ad3c add r5, r5, #1 */
/* @0x22ad40 cmp r0, #0 */
/* @0x22ad44 beq 0x22ad50 <vorbis_info_clear+0x40> */
/* @0x22ad48 bl 0xb655c <free@plt> */
/* @0x22ad4c ldr r3, [r4, #0x8] */
/* @0x22ad50 cmp r3, r5 */
/* @0x22ad54 bgt 0x22ad38 <vorbis_info_clear+0x28> */
/* @0x22ad58 ldr r2, [r4, #0xc] */
/* @0x22ad5c cmp r2, #0 */
/* @0x22ad60 addgt r6, r4, #540 */
/* @0x22ad64 movgt r5, #0 */
/* @0x22ad68 ble 0x22ada0 <vorbis_info_clear+0x90> */
/* @0x22ad6c ldr r0, [r6, #0x4]! */
/* @0x22ad70 add r5, r5, #1 */
/* @0x22ad74 ldr r3, [pc, #0x13c] */
/* @0x22ad78 cmp r0, #0 */
/* @0x22ad7c beq 0x22ad98 <vorbis_info_clear+0x88> */
/* @0x22ad80 ldr r2, [r6, #-0x100] */
/* @0x22ad84 ldr r3, [pc, r3] */
/* @0x22ad88 ldr r3, [r3, r2, lsl #2] */
/* @0x22ad8c ldr r3, [r3, #0x8] */
/* @0x22ad90 blx r3 */
/* @0x22ad94 ldr r2, [r4, #0xc] */
/* @0x22ad98 cmp r2, r5 */
/* @0x22ad9c bgt 0x22ad6c <vorbis_info_clear+0x5c> */
/* @0x22ada0 ldr r2, [r4, #0x14] */
/* @0x22ada4 cmp r2, #0 */
/* @0x22ada8 addgt r6, r4, #1296 */
/* @0x22adac movgt r5, #0 */
/* @0x22adb0 addgt r6, r6, #12 */
/* @0x22adb4 ble 0x22adec <vorbis_info_clear+0xdc> */
/* @0x22adb8 ldr r0, [r6, #0x4]! */
/* @0x22adbc add r5, r5, #1 */
/* @0x22adc0 ldr r3, [pc, #0xf4] */
/* @0x22adc4 cmp r0, #0 */
/* @0x22adc8 beq 0x22ade4 <vorbis_info_clear+0xd4> */
/* @0x22adcc ldr r2, [r6, #-0x100] */
/* @0x22add0 ldr r3, [pc, r3] */
/* @0x22add4 ldr r3, [r3, r2, lsl #2] */
/* @0x22add8 ldr r3, [r3, #0x8] */
/* @0x22addc blx r3 */
/* @0x22ade0 ldr r2, [r4, #0x14] */
/* @0x22ade4 cmp r2, r5 */
/* @0x22ade8 bgt 0x22adb8 <vorbis_info_clear+0xa8> */
/* @0x22adec ldr r2, [r4, #0x18] */
/* @0x22adf0 cmp r2, #0 */
/* @0x22adf4 addgt r6, r4, #1808 */
/* @0x22adf8 movgt r5, #0 */
/* @0x22adfc addgt r6, r6, #12 */
/* @0x22ae00 ble 0x22ae38 <vorbis_info_clear+0x128> */
/* @0x22ae04 ldr r0, [r6, #0x4]! */
/* @0x22ae08 add r5, r5, #1 */
/* @0x22ae0c ldr r3, [pc, #0xac] */
/* @0x22ae10 cmp r0, #0 */
/* @0x22ae14 beq 0x22ae30 <vorbis_info_clear+0x120> */
/* @0x22ae18 ldr r2, [r6, #-0x100] */
/* @0x22ae1c ldr r3, [pc, r3] */
/* @0x22ae20 ldr r3, [r3, r2, lsl #2] */
/* @0x22ae24 ldr r3, [r3, #0x8] */
/* @0x22ae28 blx r3 */
/* @0x22ae2c ldr r2, [r4, #0x18] */
/* @0x22ae30 cmp r2, r5 */
/* @0x22ae34 bgt 0x22ae04 <vorbis_info_clear+0xf4> */
/* @0x22ae38 ldr r3, [r4, #0x1c] */
/* @0x22ae3c cmp r3, #0 */
/* @0x22ae40 addgt r7, r4, #2064 */
/* @0x22ae44 movgt r5, #0 */
/* @0x22ae48 addgt r7, r7, #12 */
/* @0x22ae4c movgt r6, r5 */
/* @0x22ae50 ble 0x22ae8c <vorbis_info_clear+0x17c> */
/* @0x22ae54 ldr r0, [r7, #0x4]! */
/* @0x22ae58 add r6, r6, #1 */
/* @0x22ae5c cmp r0, #0 */
/* @0x22ae60 beq 0x22ae68 <vorbis_info_clear+0x158> */
/* @0x22ae64 bl 0x22f554 <vorbis_staticbook_destroy> */
/* @0x22ae68 ldr r3, [r4, #0xc20] */
/* @0x22ae6c cmp r3, #0 */
/* @0x22ae70 add r0, r3, r5 */
/* @0x22ae74 add r5, r5, #52 */
/* @0x22ae78 beq 0x22ae80 <vorbis_info_clear+0x170> */
/* @0x22ae7c bl 0x22f598 <vorbis_book_clear> */
/* @0x22ae80 ldr r3, [r4, #0x1c] */
/* @0x22ae84 cmp r3, r6 */
/* @0x22ae88 bgt 0x22ae54 <vorbis_info_clear+0x144> */
/* @0x22ae8c ldr r0, [r4, #0xc20] */
/* @0x22ae90 cmp r0, #0 */
/* @0x22ae94 beq 0x22ae9c <vorbis_info_clear+0x18c> */
/* @0x22ae98 bl 0xb655c <free@plt> */
/* @0x22ae9c mov r0, r4 */
/* @0x22aea0 bl 0xb655c <free@plt> */
/* @0x22aea4 mov r0, r8 */
/* @0x22aea8 mov r1, #0 */
/* @0x22aeac mov r2, #32 */
/* @0x22aeb0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x22aeb4 b 0xb65b0 <memset@plt> */
/* @0x22aeb8 ldrsheq r6, [r12], -r12 */
/* @0x22aebc ldrheq r6, [r12], -r4 */
/* @0x22aec0 andseq r6, r12, r12, ror #12 */

/* ── FUNC 0x22aec4 · vorbis_synthesis_idheader · size=160 · insn=40 */
/* @0x22aec4 push {r4, r5, r6, r7, lr} */
/* @0x22aec8 subs r4, r0, #0 */
/* @0x22aecc sub sp, sp, #36 */
/* @0x22aed0 beq 0x22aef0 <vorbis_synthesis_idheader+0x2c> */
/* @0x22aed4 add r5, sp, #12 */
/* @0x22aed8 ldm r4, {r1, r2} */
/* @0x22aedc mov r0, r5 */
/* @0x22aee0 bl 0x23385c <oggpack_readinit> */
/* @0x22aee4 ldr r3, [r4, #0x8] */
/* @0x22aee8 cmp r3, #0 */
/* @0x22aeec bne 0x22aefc <vorbis_synthesis_idheader+0x38> */
/* @0x22aef0 mov r0, #0 */
/* @0x22aef4 add sp, sp, #36 */
/* @0x22aef8 pop {r4, r5, r6, r7, pc} */
/* @0x22aefc mov r0, r5 */
/* @0x22af00 mov r1, #8 */
/* @0x22af04 bl 0x233b28 <oggpack_read> */
/* @0x22af08 cmp r0, #1 */
/* @0x22af0c bne 0x22aef0 <vorbis_synthesis_idheader+0x2c> */
/* @0x22af10 add r7, sp, #4 */
/* @0x22af14 add r4, sp, #3 */
/* @0x22af18 add r6, sp, #9 */
/* @0x22af1c mov r3, #0 */
/* @0x22af20 strh r3, [r7, #4] */
/* @0x22af24 str r3, [sp, #0x4] */
/* @0x22af28 mov r0, r5 */
/* @0x22af2c mov r1, #8 */
/* @0x22af30 bl 0x233b28 <oggpack_read> */
/* @0x22af34 strb r0, [r4, #0x1]! */
/* @0x22af38 cmp r4, r6 */
/* @0x22af3c bne 0x22af28 <vorbis_synthesis_idheader+0x64> */
/* @0x22af40 ldr r1, [pc, #0x18] */
/* @0x22af44 mov r0, r7 */
/* @0x22af48 mov r2, #6 */
/* @0x22af4c add r1, pc, r1 */
/* @0x22af50 bl 0xb6c40 <memcmp@plt> */
/* @0x22af54 rsbs r0, r0, #1 */
/* @0x22af58 movlo r0, #0 */
/* @0x22af5c b 0x22aef4 <vorbis_synthesis_idheader+0x30> */
/* @0x22af60 andseq r10, r2, r8, lsl #3 */

/* ── FUNC 0x22af64 · vorbis_synthesis_headerin · size=1716 · insn=429 */
/* @0x22af64 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22af68 subs r7, r2, #0 */
/* @0x22af6c sub sp, sp, #44 */
/* @0x22af70 mov r11, r0 */
/* @0x22af74 mov r9, r1 */
/* @0x22af78 beq 0x22b004 <vorbis_synthesis_headerin+0xa0> */
/* @0x22af7c add r5, sp, #20 */
/* @0x22af80 ldm r7, {r1, r2} */
/* @0x22af84 add r8, sp, #12 */
/* @0x22af88 add r4, sp, #11 */
/* @0x22af8c mov r0, r5 */
/* @0x22af90 add r6, sp, #17 */
/* @0x22af94 bl 0x23385c <oggpack_readinit> */
/* @0x22af98 mov r0, r5 */
/* @0x22af9c mov r1, #8 */
/* @0x22afa0 bl 0x233b28 <oggpack_read> */
/* @0x22afa4 mov r3, #0 */
/* @0x22afa8 strh r3, [r8, #4] */
/* @0x22afac str r3, [sp, #0xc] */
/* @0x22afb0 mov r10, r0 */
/* @0x22afb4 mov r0, r5 */
/* @0x22afb8 mov r1, #8 */
/* @0x22afbc bl 0x233b28 <oggpack_read> */
/* @0x22afc0 strb r0, [r4, #0x1]! */
/* @0x22afc4 cmp r4, r6 */
/* @0x22afc8 bne 0x22afb4 <vorbis_synthesis_headerin+0x50> */
/* @0x22afcc ldr r1, [pc, #0x634] */
/* @0x22afd0 mov r0, r8 */
/* @0x22afd4 mov r2, #6 */
/* @0x22afd8 add r1, pc, r1 */
/* @0x22afdc bl 0xb6c40 <memcmp@plt> */
/* @0x22afe0 subs r8, r0, #0 */
/* @0x22afe4 mvnne r8, #131 */
/* @0x22afe8 bne 0x22b008 <vorbis_synthesis_headerin+0xa4> */
/* @0x22afec cmp r10, #3 */
/* @0x22aff0 beq 0x22b198 <vorbis_synthesis_headerin+0x234> */
/* @0x22aff4 cmp r10, #5 */
/* @0x22aff8 beq 0x22b120 <vorbis_synthesis_headerin+0x1bc> */
/* @0x22affc cmp r10, #1 */
/* @0x22b000 beq 0x22b014 <vorbis_synthesis_headerin+0xb0> */
/* @0x22b004 mvn r8, #132 */
/* @0x22b008 mov r0, r8 */
/* @0x22b00c add sp, sp, #44 */
/* @0x22b010 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22b014 ldr r3, [r7, #0x8] */
/* @0x22b018 cmp r3, #0 */
/* @0x22b01c beq 0x22b004 <vorbis_synthesis_headerin+0xa0> */
/* @0x22b020 ldr r3, [r11, #0x8] */
/* @0x22b024 cmp r3, #0 */
/* @0x22b028 bne 0x22b004 <vorbis_synthesis_headerin+0xa0> */
/* @0x22b02c ldr r4, [r11, #0x1c] */
/* @0x22b030 cmp r4, #0 */
/* @0x22b034 beq 0x22b524 <vorbis_synthesis_headerin+0x5c0> */
/* @0x22b038 mov r0, r5 */
/* @0x22b03c mov r1, #32 */
/* @0x22b040 bl 0x233b28 <oggpack_read> */
/* @0x22b044 cmp r0, #0 */
/* @0x22b048 str r0, [r11] */
/* @0x22b04c bne 0x22b49c <vorbis_synthesis_headerin+0x538> */
/* @0x22b050 mov r1, #8 */
/* @0x22b054 mov r0, r5 */
/* @0x22b058 bl 0x233b28 <oggpack_read> */
/* @0x22b05c mov r1, #32 */
/* @0x22b060 str r0, [r11, #0x4] */
/* @0x22b064 mov r0, r5 */
/* @0x22b068 bl 0x233b28 <oggpack_read> */
/* @0x22b06c mov r1, #32 */
/* @0x22b070 str r0, [r11, #0x8] */
/* @0x22b074 mov r0, r5 */
/* @0x22b078 bl 0x233b28 <oggpack_read> */
/* @0x22b07c mov r1, #32 */
/* @0x22b080 str r0, [r11, #0xc] */
/* @0x22b084 mov r0, r5 */
/* @0x22b088 bl 0x233b28 <oggpack_read> */
/* @0x22b08c mov r1, #32 */
/* @0x22b090 str r0, [r11, #0x10] */
/* @0x22b094 mov r0, r5 */
/* @0x22b098 bl 0x233b28 <oggpack_read> */
/* @0x22b09c mov r1, #4 */
/* @0x22b0a0 str r0, [r11, #0x14] */
/* @0x22b0a4 mov r0, r5 */
/* @0x22b0a8 bl 0x233b28 <oggpack_read> */
/* @0x22b0ac mov r1, #4 */
/* @0x22b0b0 lsl r3, r10, r0 */
/* @0x22b0b4 mov r0, r5 */
/* @0x22b0b8 str r3, [r4] */
/* @0x22b0bc bl 0x233b28 <oggpack_read> */
/* @0x22b0c0 ldr r3, [r11, #0x8] */
/* @0x22b0c4 cmp r3, #0 */
/* @0x22b0c8 lsl r0, r10, r0 */
/* @0x22b0cc str r0, [r4, #0x4] */
/* @0x22b0d0 ble 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b0d4 ldr r3, [r11, #0x4] */
/* @0x22b0d8 cmp r3, #0 */
/* @0x22b0dc ble 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b0e0 ldr r3, [r4] */
/* @0x22b0e4 cmp r3, #63 */
/* @0x22b0e8 ble 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b0ec cmp r0, r3 */
/* @0x22b0f0 blt 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b0f4 cmp r0, #8192 */
/* @0x22b0f8 bgt 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b0fc mov r0, r5 */
/* @0x22b100 mov r1, #1 */
/* @0x22b104 bl 0x233b28 <oggpack_read> */
/* @0x22b108 cmp r0, #1 */
/* @0x22b10c beq 0x22b008 <vorbis_synthesis_headerin+0xa4> */
/* @0x22b110 mov r0, r11 */
/* @0x22b114 mvn r8, #132 */
/* @0x22b118 bl 0x22ad10 <vorbis_info_clear> */
/* @0x22b11c b 0x22b008 <vorbis_synthesis_headerin+0xa4> */
/* @0x22b120 ldr r3, [r11, #0x8] */
/* @0x22b124 cmp r3, #0 */
/* @0x22b128 beq 0x22b004 <vorbis_synthesis_headerin+0xa0> */
/* @0x22b12c ldr r3, [r9, #0xc] */
/* @0x22b130 cmp r3, #0 */
/* @0x22b134 beq 0x22b004 <vorbis_synthesis_headerin+0xa0> */
/* @0x22b138 ldr r6, [r11, #0x1c] */
/* @0x22b13c cmp r6, #0 */
/* @0x22b140 beq 0x22b524 <vorbis_synthesis_headerin+0x5c0> */
/* @0x22b144 mov r0, r5 */
/* @0x22b148 mov r1, #8 */
/* @0x22b14c bl 0x233b28 <oggpack_read> */
/* @0x22b150 add r0, r0, #1 */
/* @0x22b154 str r0, [r6, #0x1c] */
/* @0x22b158 cmp r0, #0 */
/* @0x22b15c addgt r7, r6, #2064 */
/* @0x22b160 movgt r4, r8 */
/* @0x22b164 addgt r7, r7, #12 */
/* @0x22b168 bgt 0x22b17c <vorbis_synthesis_headerin+0x218> */
/* @0x22b16c b 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b170 ldr r3, [r6, #0x1c] */
/* @0x22b174 cmp r4, r3 */
/* @0x22b178 bge 0x22b338 <vorbis_synthesis_headerin+0x3d4> */
/* @0x22b17c mov r0, r5 */
/* @0x22b180 add r4, r4, #1 */
/* @0x22b184 bl 0x227d30 <vorbis_staticbook_unpack> */
/* @0x22b188 cmp r0, #0 */
/* @0x22b18c str r0, [r7, #0x4]! */
/* @0x22b190 bne 0x22b170 <vorbis_synthesis_headerin+0x20c> */
/* @0x22b194 b 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b198 ldr r3, [r11, #0x8] */
/* @0x22b19c cmp r3, #0 */
/* @0x22b1a0 beq 0x22b004 <vorbis_synthesis_headerin+0xa0> */
/* @0x22b1a4 mov r0, r5 */
/* @0x22b1a8 mov r1, #32 */
/* @0x22b1ac bl 0x233b28 <oggpack_read> */
/* @0x22b1b0 subs r4, r0, #0 */
/* @0x22b1b4 blt 0x22b328 <vorbis_synthesis_headerin+0x3c4> */
/* @0x22b1b8 mov r0, r5 */
/* @0x22b1bc ldr r6, [sp, #0x24] */
/* @0x22b1c0 bl 0x233e28 <oggpack_bytes> */
/* @0x22b1c4 rsb r0, r0, r6 */
/* @0x22b1c8 cmp r4, r0 */
/* @0x22b1cc bgt 0x22b328 <vorbis_synthesis_headerin+0x3c4> */
/* @0x22b1d0 add r0, r4, #1 */
/* @0x22b1d4 mov r1, #1 */
/* @0x22b1d8 bl 0xb6c34 <calloc@plt> */
/* @0x22b1dc cmp r0, #0 */
/* @0x22b1e0 mov r6, r0 */
/* @0x22b1e4 str r0, [r9, #0xc] */
/* @0x22b1e8 beq 0x22b328 <vorbis_synthesis_headerin+0x3c4> */
/* @0x22b1ec cmp r4, #0 */
/* @0x22b1f0 beq 0x22b20c <vorbis_synthesis_headerin+0x2a8> */
/* @0x22b1f4 mov r0, r5 */
/* @0x22b1f8 mov r1, #8 */
/* @0x22b1fc bl 0x233b28 <oggpack_read> */
/* @0x22b200 subs r4, r4, #1 */
/* @0x22b204 strb r0, [r6], #1 */
/* @0x22b208 bne 0x22b1f4 <vorbis_synthesis_headerin+0x290> */
/* @0x22b20c mov r0, r5 */
/* @0x22b210 mov r1, #32 */
/* @0x22b214 bl 0x233b28 <oggpack_read> */
/* @0x22b218 cmn r0, #-2147483647 */
/* @0x22b21c mov r4, r0 */
/* @0x22b220 movne r3, #0 */
/* @0x22b224 moveq r3, #1 */
/* @0x22b228 orrs r7, r3, r0, lsr #31 */
/* @0x22b22c bne 0x22b328 <vorbis_synthesis_headerin+0x3c4> */
/* @0x22b230 mov r0, r5 */
/* @0x22b234 ldr r6, [sp, #0x24] */
/* @0x22b238 bl 0x233e28 <oggpack_bytes> */
/* @0x22b23c rsb r0, r0, r6 */
/* @0x22b240 cmp r4, r0, asr #2 */
/* @0x22b244 bgt 0x22b328 <vorbis_synthesis_headerin+0x3c4> */
/* @0x22b248 add r10, r4, #1 */
/* @0x22b24c mov r1, #4 */
/* @0x22b250 mov r0, r10 */
/* @0x22b254 bl 0xb6c34 <calloc@plt> */
/* @0x22b258 mov r1, #4 */
/* @0x22b25c mov r6, r0 */
/* @0x22b260 str r0, [r9] */
/* @0x22b264 mov r0, r10 */
/* @0x22b268 bl 0xb6c34 <calloc@plt> */
/* @0x22b26c cmp r6, #0 */
/* @0x22b270 str r0, [r9, #0x4] */
/* @0x22b274 beq 0x22b328 <vorbis_synthesis_headerin+0x3c4> */
/* @0x22b278 cmp r0, #0 */
/* @0x22b27c beq 0x22b328 <vorbis_synthesis_headerin+0x3c4> */
/* @0x22b280 cmp r4, #0 */
/* @0x22b284 str r4, [r9, #0x8] */
/* @0x22b288 ble 0x22b314 <vorbis_synthesis_headerin+0x3b0> */
/* @0x22b28c mov r0, r5 */
/* @0x22b290 mov r1, #32 */
/* @0x22b294 bl 0x233b28 <oggpack_read> */
/* @0x22b298 subs r4, r0, #0 */
/* @0x22b29c blt 0x22b328 <vorbis_synthesis_headerin+0x3c4> */
/* @0x22b2a0 mov r0, r5 */
/* @0x22b2a4 ldr r6, [sp, #0x24] */
/* @0x22b2a8 bl 0x233e28 <oggpack_bytes> */
/* @0x22b2ac rsb r0, r0, r6 */
/* @0x22b2b0 cmp r4, r0 */
/* @0x22b2b4 bgt 0x22b328 <vorbis_synthesis_headerin+0x3c4> */
/* @0x22b2b8 ldr r3, [r9, #0x4] */
/* @0x22b2bc add r0, r4, #1 */
/* @0x22b2c0 ldr r6, [r9] */
/* @0x22b2c4 mov r1, #1 */
/* @0x22b2c8 str r4, [r3, r7, lsl #2] */
/* @0x22b2cc bl 0xb6c34 <calloc@plt> */
/* @0x22b2d0 str r0, [r6, r7, lsl #2] */
/* @0x22b2d4 ldr r3, [r9] */
/* @0x22b2d8 ldr r6, [r3, r7, lsl #2] */
/* @0x22b2dc cmp r6, #0 */
/* @0x22b2e0 beq 0x22b410 <vorbis_synthesis_headerin+0x4ac> */
/* @0x22b2e4 cmp r4, #0 */
/* @0x22b2e8 beq 0x22b304 <vorbis_synthesis_headerin+0x3a0> */
/* @0x22b2ec mov r0, r5 */
/* @0x22b2f0 mov r1, #8 */
/* @0x22b2f4 bl 0x233b28 <oggpack_read> */
/* @0x22b2f8 subs r4, r4, #1 */
/* @0x22b2fc strb r0, [r6], #1 */
/* @0x22b300 bne 0x22b2ec <vorbis_synthesis_headerin+0x388> */
/* @0x22b304 ldr r3, [r9, #0x8] */
/* @0x22b308 add r7, r7, #1 */
/* @0x22b30c cmp r7, r3 */
/* @0x22b310 blt 0x22b28c <vorbis_synthesis_headerin+0x328> */
/* @0x22b314 mov r0, r5 */
/* @0x22b318 mov r1, #1 */
/* @0x22b31c bl 0x233b28 <oggpack_read> */
/* @0x22b320 cmp r0, #1 */
/* @0x22b324 beq 0x22b008 <vorbis_synthesis_headerin+0xa4> */
/* @0x22b328 mov r0, r9 */
/* @0x22b32c mvn r8, #132 */
/* @0x22b330 bl 0x22ac4c <vorbis_comment_clear> */
/* @0x22b334 b 0x22b008 <vorbis_synthesis_headerin+0xa4> */
/* @0x22b338 mov r0, r5 */
/* @0x22b33c mov r1, #6 */
/* @0x22b340 bl 0x233b28 <oggpack_read> */
/* @0x22b344 add r0, r0, #1 */
/* @0x22b348 str r0, [r6, #0x10] */
/* @0x22b34c cmp r0, #0 */
/* @0x22b350 addgt r9, r6, #796 */
/* @0x22b354 movgt r7, #0 */
/* @0x22b358 bgt 0x22b36c <vorbis_synthesis_headerin+0x408> */
/* @0x22b35c b 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b360 ldr r3, [r6, #0x10] */
/* @0x22b364 cmp r7, r3 */
/* @0x22b368 bge 0x22b390 <vorbis_synthesis_headerin+0x42c> */
/* @0x22b36c mov r0, r5 */
/* @0x22b370 mov r1, #16 */
/* @0x22b374 bl 0x233b28 <oggpack_read> */
/* @0x22b378 add r7, r7, #1 */
/* @0x22b37c cmp r0, #0 */
/* @0x22b380 mov r4, r0 */
/* @0x22b384 str r0, [r9, #0x4]! */
/* @0x22b388 beq 0x22b360 <vorbis_synthesis_headerin+0x3fc> */
/* @0x22b38c b 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b390 mov r0, r5 */
/* @0x22b394 mov r1, #6 */
/* @0x22b398 bl 0x233b28 <oggpack_read> */
/* @0x22b39c add r0, r0, #1 */
/* @0x22b3a0 str r0, [r6, #0x14] */
/* @0x22b3a4 cmp r0, #0 */
/* @0x22b3a8 addgt r7, r6, #1040 */
/* @0x22b3ac addgt r7, r7, #12 */
/* @0x22b3b0 bgt 0x22b3e0 <vorbis_synthesis_headerin+0x47c> */
/* @0x22b3b4 b 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b3b8 ldr r2, [pc, r2] */
/* @0x22b3bc ldr r3, [r2, r3, lsl #2] */
/* @0x22b3c0 ldr r3, [r3] */
/* @0x22b3c4 blx r3 */
/* @0x22b3c8 cmp r0, #0 */
/* @0x22b3cc str r0, [r7, #0x100] */
/* @0x22b3d0 beq 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b3d4 ldr r3, [r6, #0x14] */
/* @0x22b3d8 cmp r4, r3 */
/* @0x22b3dc bge 0x22b418 <vorbis_synthesis_headerin+0x4b4> */
/* @0x22b3e0 mov r1, #16 */
/* @0x22b3e4 mov r0, r5 */
/* @0x22b3e8 bl 0x233b28 <oggpack_read> */
/* @0x22b3ec add r4, r4, #1 */
/* @0x22b3f0 ldr r2, [pc, #0x214] */
/* @0x22b3f4 mov r1, r5 */
/* @0x22b3f8 mov r3, r0 */
/* @0x22b3fc cmp r3, #1 */
/* @0x22b400 mov r0, r11 */
/* @0x22b404 str r3, [r7, #0x4]! */
/* @0x22b408 bls 0x22b3b8 <vorbis_synthesis_headerin+0x454> */
/* @0x22b40c b 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b410 str r7, [r9, #0x8] */
/* @0x22b414 b 0x22b328 <vorbis_synthesis_headerin+0x3c4> */
/* @0x22b418 mov r0, r5 */
/* @0x22b41c mov r1, #6 */
/* @0x22b420 bl 0x233b28 <oggpack_read> */
/* @0x22b424 add r0, r0, #1 */
/* @0x22b428 str r0, [r6, #0x18] */
/* @0x22b42c cmp r0, #0 */
/* @0x22b430 addgt r4, r6, #1552 */
/* @0x22b434 movgt r7, #0 */
/* @0x22b438 addgt r4, r4, #12 */
/* @0x22b43c bgt 0x22b46c <vorbis_synthesis_headerin+0x508> */
/* @0x22b440 b 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b444 ldr r3, [pc, r3] */
/* @0x22b448 ldr r3, [r3, r2, lsl #2] */
/* @0x22b44c ldr r3, [r3] */
/* @0x22b450 blx r3 */
/* @0x22b454 cmp r0, #0 */
/* @0x22b458 str r0, [r4, #0x100] */
/* @0x22b45c beq 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b460 ldr r3, [r6, #0x18] */
/* @0x22b464 cmp r7, r3 */
/* @0x22b468 bge 0x22b4a4 <vorbis_synthesis_headerin+0x540> */
/* @0x22b46c mov r1, #16 */
/* @0x22b470 mov r0, r5 */
/* @0x22b474 bl 0x233b28 <oggpack_read> */
/* @0x22b478 add r7, r7, #1 */
/* @0x22b47c ldr r3, [pc, #0x18c] */
/* @0x22b480 mov r1, r5 */
/* @0x22b484 mov r2, r0 */
/* @0x22b488 cmp r2, #2 */
/* @0x22b48c mov r0, r11 */
/* @0x22b490 str r2, [r4, #0x4]! */
/* @0x22b494 bls 0x22b444 <vorbis_synthesis_headerin+0x4e0> */
/* @0x22b498 b 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b49c mvn r8, #133 */
/* @0x22b4a0 b 0x22b008 <vorbis_synthesis_headerin+0xa4> */
/* @0x22b4a4 mov r0, r5 */
/* @0x22b4a8 mov r1, #6 */
/* @0x22b4ac bl 0x233b28 <oggpack_read> */
/* @0x22b4b0 add r0, r0, #1 */
/* @0x22b4b4 str r0, [r6, #0xc] */
/* @0x22b4b8 cmp r0, #0 */
/* @0x22b4bc addgt r9, r6, #284 */
/* @0x22b4c0 movgt r7, #0 */
/* @0x22b4c4 bgt 0x22b4f4 <vorbis_synthesis_headerin+0x590> */
/* @0x22b4c8 b 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b4cc ldr r3, [pc, r3] */
/* @0x22b4d0 ldr r3, [r3] */
/* @0x22b4d4 ldr r3, [r3] */
/* @0x22b4d8 blx r3 */
/* @0x22b4dc cmp r0, #0 */
/* @0x22b4e0 str r0, [r9, #0x100] */
/* @0x22b4e4 beq 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b4e8 ldr r3, [r6, #0xc] */
/* @0x22b4ec cmp r7, r3 */
/* @0x22b4f0 bge 0x22b52c <vorbis_synthesis_headerin+0x5c8> */
/* @0x22b4f4 mov r1, #16 */
/* @0x22b4f8 mov r0, r5 */
/* @0x22b4fc bl 0x233b28 <oggpack_read> */
/* @0x22b500 add r7, r7, #1 */
/* @0x22b504 ldr r3, [pc, #0x108] */
/* @0x22b508 mov r1, r5 */
/* @0x22b50c mov r4, r0 */
/* @0x22b510 cmp r4, #0 */
/* @0x22b514 mov r0, r11 */
/* @0x22b518 str r4, [r9, #0x4]! */
/* @0x22b51c beq 0x22b4cc <vorbis_synthesis_headerin+0x568> */
/* @0x22b520 b 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b524 mvn r8, #128 */
/* @0x22b528 b 0x22b008 <vorbis_synthesis_headerin+0xa4> */
/* @0x22b52c mov r0, r5 */
/* @0x22b530 mov r1, #6 */
/* @0x22b534 bl 0x233b28 <oggpack_read> */
/* @0x22b538 add r0, r0, #1 */
/* @0x22b53c str r0, [r6, #0x8] */
/* @0x22b540 cmp r0, #0 */
/* @0x22b544 movgt r7, r4 */
/* @0x22b548 movgt r4, r6 */
/* @0x22b54c bgt 0x22b584 <vorbis_synthesis_headerin+0x620> */
/* @0x22b550 b 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b554 ldr r2, [r3, #0x8] */
/* @0x22b558 cmp r2, #0 */
/* @0x22b55c bgt 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b560 ldr r3, [r3, #0xc] */
/* @0x22b564 ldr r2, [r6, #0xc] */
/* @0x22b568 cmp r3, r2 */
/* @0x22b56c bge 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b570 cmp r3, #0 */
/* @0x22b574 blt 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b578 ldr r3, [r6, #0x8] */
/* @0x22b57c cmp r7, r3 */
/* @0x22b580 bge 0x22b0fc <vorbis_synthesis_headerin+0x198> */
/* @0x22b584 mov r1, #16 */
/* @0x22b588 mov r0, #1 */
/* @0x22b58c bl 0xb6c34 <calloc@plt> */
/* @0x22b590 mov r1, #1 */
/* @0x22b594 add r7, r7, r1 */
/* @0x22b598 add r4, r4, #4 */
/* @0x22b59c mov r9, r0 */
/* @0x22b5a0 str r0, [r4, #0x1c] */
/* @0x22b5a4 mov r0, r5 */
/* @0x22b5a8 bl 0x233b28 <oggpack_read> */
/* @0x22b5ac ldr r3, [r4, #0x1c] */
/* @0x22b5b0 mov r1, #16 */
/* @0x22b5b4 str r0, [r9] */
/* @0x22b5b8 mov r0, r5 */
/* @0x22b5bc str r3, [sp, #0x4] */
/* @0x22b5c0 bl 0x233b28 <oggpack_read> */
/* @0x22b5c4 ldr r3, [sp, #0x4] */
/* @0x22b5c8 mov r1, #16 */
/* @0x22b5cc ldr r10, [r4, #0x1c] */
/* @0x22b5d0 str r0, [r3, #0x4] */
/* @0x22b5d4 mov r0, r5 */
/* @0x22b5d8 bl 0x233b28 <oggpack_read> */
/* @0x22b5dc ldr r9, [r4, #0x1c] */
/* @0x22b5e0 mov r1, #8 */
/* @0x22b5e4 str r0, [r10, #0x8] */
/* @0x22b5e8 mov r0, r5 */
/* @0x22b5ec bl 0x233b28 <oggpack_read> */
/* @0x22b5f0 ldr r3, [r4, #0x1c] */
/* @0x22b5f4 ldr r2, [r3, #0x4] */
/* @0x22b5f8 cmp r2, #0 */
/* @0x22b5fc str r0, [r9, #0xc] */
/* @0x22b600 ble 0x22b554 <vorbis_synthesis_headerin+0x5f0> */
/* @0x22b604 b 0x22b110 <vorbis_synthesis_headerin+0x1ac> */
/* @0x22b608 ldrsheq r10, [r2], -r12 */
/* @0x22b60c andseq r6, r12, r12, asr #1 */
/* @0x22b610 andseq r6, r12, r4, asr #32 */
/* @0x22b614 ldrheq r5, [r12], -r4 */

/* ── FUNC 0x22b618 · anon_22b618 · size=2404 · insn=601 */
/* @0x22b618 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22b61c add r11, sp, #32 */
/* @0x22b620 sub sp, sp, #68 */
/* @0x22b624 mov r5, r0 */
/* @0x22b628 ldr r0, [pc, #0x4b4] */
/* @0x22b62c mov r8, r1 */
/* @0x22b630 ldr r3, [r5, #0x40] */
/* @0x22b634 ldr r0, [pc, r0] */
/* @0x22b638 str r0, [r11, #-0x40] */
/* @0x22b63c ldr r0, [r0] */
/* @0x22b640 ldr r10, [r3, #0x4] */
/* @0x22b644 ldr r3, [r3, #0x48] */
/* @0x22b648 ldr r1, [r5, #0x1c] */
/* @0x22b64c ldr r2, [r10, #0x4] */
/* @0x22b650 str r3, [r11, #-0x48] */
/* @0x22b654 ldr r3, [r10, #0x1c] */
/* @0x22b658 cmp r2, #0 */
/* @0x22b65c str r0, [r11, #-0x28] */
/* @0x22b660 ldr r4, [r8, #0x4] */
/* @0x22b664 str r3, [r11, #-0x44] */
/* @0x22b668 lsl r3, r2, #2 */
/* @0x22b66c ldr r0, [r11, #-0x44] */
/* @0x22b670 add r3, r3, #14 */
/* @0x22b674 bic r3, r3, #7 */
/* @0x22b678 sub sp, sp, r3 */
/* @0x22b67c ldr r1, [r0, r1, lsl #2] */
/* @0x22b680 str r1, [r11, #-0x3c] */
/* @0x22b684 add r1, sp, #8 */
/* @0x22b688 sub sp, sp, r3 */
/* @0x22b68c str r1, [r11, #-0x38] */
/* @0x22b690 add r0, sp, #8 */
/* @0x22b694 sub sp, sp, r3 */
/* @0x22b698 add r6, sp, #8 */
/* @0x22b69c sub sp, sp, r3 */
/* @0x22b6a0 ldr r3, [r11, #-0x3c] */
/* @0x22b6a4 add r1, sp, #8 */
/* @0x22b6a8 str r0, [r11, #-0x50] */
/* @0x22b6ac str r1, [r11, #-0x4c] */
/* @0x22b6b0 str r3, [r5, #0x24] */
/* @0x22b6b4 ble 0x22b740 <vorbis_synthesis_headerin+0x7dc> */
/* @0x22b6b8 ldr r1, [r11, #-0x3c] */
/* @0x22b6bc mov r7, #0 */
/* @0x22b6c0 ldr r3, [r11, #-0x4c] */
/* @0x22b6c4 str r4, [r11, #-0x54] */
/* @0x22b6c8 lsl r2, r1, #2 */
/* @0x22b6cc sub r9, r3, #4 */
/* @0x22b6d0 str r6, [r11, #-0x30] */
/* @0x22b6d4 lsr r2, r2, #1 */
/* @0x22b6d8 str r2, [r11, #-0x34] */
/* @0x22b6dc ldr r1, [r4, #0x4]! */
/* @0x22b6e0 mov r0, r5 */
/* @0x22b6e4 ldr r12, [r8, #0x10] */
/* @0x22b6e8 lsl r6, r7, #2 */
/* @0x22b6ec ldr lr, [r8, #0x8] */
/* @0x22b6f0 ldr r12, [r12, r1, lsl #2] */
/* @0x22b6f4 ldr r1, [lr, r1, lsl #2] */
/* @0x22b6f8 ldr r12, [r12, #0x10] */
/* @0x22b6fc blx r12 */
/* @0x22b700 ldr r12, [r5] */
/* @0x22b704 ldr r3, [r11, #-0x30] */
/* @0x22b708 mov r1, #0 */
/* @0x22b70c ldr r2, [r11, #-0x34] */
/* @0x22b710 cmp r0, #0 */
/* @0x22b714 str r0, [r9, #0x4]! */
/* @0x22b718 movne r0, #1 */
/* @0x22b71c str r0, [r3, r7, lsl #2] */
/* @0x22b720 ldr r0, [r12, r6] */
/* @0x22b724 add r7, r7, #1 */
/* @0x22b728 bl 0xb65b0 <memset@plt> */
/* @0x22b72c ldr r2, [r10, #0x4] */
/* @0x22b730 cmp r2, r7 */
/* @0x22b734 bgt 0x22b6dc <vorbis_synthesis_headerin+0x778> */
/* @0x22b738 ldr r4, [r11, #-0x54] */
/* @0x22b73c ldr r6, [r11, #-0x30] */
/* @0x22b740 ldr r0, [r4, #0x48c] */
/* @0x22b744 cmp r0, #0 */
/* @0x22b748 str r0, [r11, #-0x30] */
/* @0x22b74c ble 0x22b79c <vorbis_synthesis_headerin+0x838> */
/* @0x22b750 ldr r0, [r11, #-0x30] */
/* @0x22b754 add r3, r4, #1152 */
/* @0x22b758 add r3, r3, #12 */
/* @0x22b75c mov r12, #1 */
/* @0x22b760 add r7, r3, r0, lsl #2 */
/* @0x22b764 ldr r1, [r3, #0x4]! */
/* @0x22b768 ldr r0, [r6, r1, lsl #2] */
/* @0x22b76c cmp r0, #0 */
/* @0x22b770 ldr r0, [r3, #0x400] */
/* @0x22b774 addne r0, r6, r0, lsl #2 */
/* @0x22b778 bne 0x22b78c <vorbis_synthesis_headerin+0x828> */
/* @0x22b77c ldr r9, [r6, r0, lsl #2] */
/* @0x22b780 add r0, r6, r0, lsl #2 */
/* @0x22b784 cmp r9, #0 */
/* @0x22b788 beq 0x22b794 <vorbis_synthesis_headerin+0x830> */
/* @0x22b78c str r12, [r6, r1, lsl #2] */
/* @0x22b790 str r12, [r0] */
/* @0x22b794 cmp r3, r7 */
/* @0x22b798 bne 0x22b764 <vorbis_synthesis_headerin+0x800> */
/* @0x22b79c ldr r3, [r4] */
/* @0x22b7a0 cmp r3, #0 */
/* @0x22b7a4 ble 0x22b8a4 <vorbis_synthesis_headerin+0x940> */
/* @0x22b7a8 cmp r2, #0 */
/* @0x22b7ac str r6, [r11, #-0x30] */
/* @0x22b7b0 str r8, [r11, #-0x34] */
/* @0x22b7b4 mov r7, #0 */
/* @0x22b7b8 mov r9, #1 */
/* @0x22b7bc ldr r6, [r11, #-0x38] */
/* @0x22b7c0 ldr r8, [r11, #-0x50] */
/* @0x22b7c4 ble 0x22b88c <vorbis_synthesis_headerin+0x928> */
/* @0x22b7c8 mov r1, #0 */
/* @0x22b7cc mov r12, r1 */
/* @0x22b7d0 mov r3, r1 */
/* @0x22b7d4 b 0x22b7e8 <vorbis_synthesis_headerin+0x884> */
/* @0x22b7d8 add r3, r3, #1 */
/* @0x22b7dc add r1, r1, #4 */
/* @0x22b7e0 cmp r2, r3 */
/* @0x22b7e4 ble 0x22b838 <vorbis_synthesis_headerin+0x8d4> */
/* @0x22b7e8 add r0, r4, r1 */
/* @0x22b7ec ldr r0, [r0, #0x4] */
/* @0x22b7f0 cmp r0, r7 */
/* @0x22b7f4 bne 0x22b7d8 <vorbis_synthesis_headerin+0x874> */
/* @0x22b7f8 ldr lr, [r11, #-0x30] */
/* @0x22b7fc add r3, r3, #1 */
/* @0x22b800 ldr r2, [lr, r1] */
/* @0x22b804 ldr lr, [r5] */
/* @0x22b808 cmp r2, #0 */
/* @0x22b80c strne r9, [r8, r12, lsl #2] */
/* @0x22b810 streq r2, [r8, r12, lsl #2] */
/* @0x22b814 lslne r0, r12, #2 */
/* @0x22b818 ldr r2, [r10, #0x4] */
/* @0x22b81c lsleq r0, r12, #2 */
/* @0x22b820 ldr lr, [lr, r1] */
/* @0x22b824 add r12, r12, #1 */
/* @0x22b828 cmp r2, r3 */
/* @0x22b82c add r1, r1, #4 */
/* @0x22b830 str lr, [r6, r0] */
/* @0x22b834 bgt 0x22b7e8 <vorbis_synthesis_headerin+0x884> */
/* @0x22b838 ldr r0, [r11, #-0x34] */
/* @0x22b83c mov r3, r8 */
/* @0x22b840 ldr lr, [r11, #-0x34] */
/* @0x22b844 mov r2, r6 */
/* @0x22b848 ldr r1, [r0, #0x14] */
/* @0x22b84c mov r0, r5 */
/* @0x22b850 ldr lr, [lr, #0xc] */
/* @0x22b854 ldr r1, [r1, r7, lsl #2] */
/* @0x22b858 str r1, [r11, #-0x38] */
/* @0x22b85c ldr r1, [lr, r7, lsl #2] */
/* @0x22b860 add r7, r7, #1 */
/* @0x22b864 ldr lr, [r11, #-0x38] */
/* @0x22b868 str r12, [sp] */
/* @0x22b86c ldr r12, [lr, #0x10] */
/* @0x22b870 blx r12 */
/* @0x22b874 ldr r3, [r4] */
/* @0x22b878 cmp r3, r7 */
/* @0x22b87c ble 0x22b894 <vorbis_synthesis_headerin+0x930> */
/* @0x22b880 ldr r2, [r10, #0x4] */
/* @0x22b884 cmp r2, #0 */
/* @0x22b888 bgt 0x22b7c8 <vorbis_synthesis_headerin+0x864> */
/* @0x22b88c mov r12, #0 */
/* @0x22b890 b 0x22b838 <vorbis_synthesis_headerin+0x8d4> */
/* @0x22b894 ldr r0, [r4, #0x48c] */
/* @0x22b898 ldr r8, [r11, #-0x34] */
/* @0x22b89c ldr r6, [r11, #-0x30] */
/* @0x22b8a0 str r0, [r11, #-0x30] */
/* @0x22b8a4 ldr r1, [r11, #-0x30] */
/* @0x22b8a8 subs r9, r1, #1 */
/* @0x22b8ac bmi 0x22b96c <vorbis_synthesis_headerin+0xa08> */
/* @0x22b8b0 ldr r2, [r11, #-0x3c] */
/* @0x22b8b4 ldr r0, [r11, #-0x30] */
/* @0x22b8b8 ldr r1, [r5] */
/* @0x22b8bc add r3, r2, r2, lsr #31 */
/* @0x22b8c0 add r7, r0, #292 */
/* @0x22b8c4 str r10, [r11, #-0x30] */
/* @0x22b8c8 asr r2, r3, #1 */
/* @0x22b8cc add r7, r4, r7, lsl #2 */
/* @0x22b8d0 str r4, [r11, #-0x34] */
/* @0x22b8d4 mov r4, r1 */
/* @0x22b8d8 lsl r3, r2, #2 */
/* @0x22b8dc str r6, [r11, #-0x38] */
/* @0x22b8e0 mov r6, r2 */
/* @0x22b8e4 mov r10, r3 */
/* @0x22b8e8 ldr r3, [r7, #-0x4]! */
/* @0x22b8ec cmp r6, #0 */
/* @0x22b8f0 ldr r2, [r7, #0x400] */
/* @0x22b8f4 ldr r3, [r4, r3, lsl #2] */
/* @0x22b8f8 ldr r1, [r4, r2, lsl #2] */
/* @0x22b8fc addgt r12, r3, r10 */
/* @0x22b900 bgt 0x22b928 <vorbis_synthesis_headerin+0x9c4> */
/* @0x22b904 b 0x22b958 <vorbis_synthesis_headerin+0x9f4> */
/* @0x22b908 cmp r0, #0 */
/* @0x22b90c strle r2, [r1, #-0x4] */
/* @0x22b910 rsbgt r2, r0, r2 */
/* @0x22b914 addle r2, r2, r0 */
/* @0x22b918 strgt r2, [r1, #-0x4] */
/* @0x22b91c strle r2, [r3, #-0x4] */
/* @0x22b920 cmp r3, r12 */
/* @0x22b924 beq 0x22b958 <vorbis_synthesis_headerin+0x9f4> */
/* @0x22b928 ldr r2, [r3], #4 */
/* @0x22b92c ldr r0, [r1], #4 */
/* @0x22b930 cmp r2, #0 */
/* @0x22b934 bgt 0x22b908 <vorbis_synthesis_headerin+0x9a4> */
/* @0x22b938 cmp r0, #0 */
/* @0x22b93c strle r2, [r1, #-0x4] */
/* @0x22b940 addgt r2, r2, r0 */
/* @0x22b944 rsble r2, r0, r2 */
/* @0x22b948 strgt r2, [r1, #-0x4] */
/* @0x22b94c strle r2, [r3, #-0x4] */
/* @0x22b950 cmp r3, r12 */
/* @0x22b954 bne 0x22b928 <vorbis_synthesis_headerin+0x9c4> */
/* @0x22b958 subs r9, r9, #1 */
/* @0x22b95c bhs 0x22b8e8 <vorbis_synthesis_headerin+0x984> */
/* @0x22b960 ldr r10, [r11, #-0x30] */
/* @0x22b964 ldr r4, [r11, #-0x34] */
/* @0x22b968 ldr r6, [r11, #-0x38] */
/* @0x22b96c ldr r3, [r10, #0x4] */
/* @0x22b970 cmp r3, #0 */
/* @0x22b974 ble 0x22ba74 <vorbis_synthesis_headerin+0xb10> */
/* @0x22b978 str r6, [r11, #-0x30] */
/* @0x22b97c mov r7, #0 */
/* @0x22b980 ldr r6, [r11, #-0x4c] */
/* @0x22b984 mov r9, r7 */
/* @0x22b988 add r3, r4, r7 */
/* @0x22b98c ldr r12, [r8, #0x10] */
/* @0x22b990 ldr r1, [r8, #0x8] */
/* @0x22b994 mov r0, r5 */
/* @0x22b998 ldr r3, [r3, #0x4] */
/* @0x22b99c add r9, r9, #1 */
/* @0x22b9a0 ldr lr, [r5] */
/* @0x22b9a4 ldr r2, [r6, r7] */
/* @0x22b9a8 ldr r12, [r12, r3, lsl #2] */
/* @0x22b9ac ldr r1, [r1, r3, lsl #2] */
/* @0x22b9b0 ldr r3, [lr, r7] */
/* @0x22b9b4 add r7, r7, #4 */
/* @0x22b9b8 ldr r12, [r12, #0x14] */
/* @0x22b9bc blx r12 */
/* @0x22b9c0 ldr r3, [r10, #0x4] */
/* @0x22b9c4 cmp r3, r9 */
/* @0x22b9c8 bgt 0x22b988 <vorbis_synthesis_headerin+0xa24> */
/* @0x22b9cc cmp r3, #0 */
/* @0x22b9d0 ldr r6, [r11, #-0x30] */
/* @0x22b9d4 ble 0x22ba74 <vorbis_synthesis_headerin+0xb10> */
/* @0x22b9d8 ldr r7, [r11, #-0x3c] */
/* @0x22b9dc mov r4, #0 */
/* @0x22b9e0 ldr r3, [r5] */
/* @0x22b9e4 mov r0, r7 */
/* @0x22b9e8 ldr r1, [r3, r4, lsl #2] */
/* @0x22b9ec add r4, r4, #1 */
/* @0x22b9f0 mov r2, r1 */
/* @0x22b9f4 bl 0x22bf7c <mdct_backward> */
/* @0x22b9f8 ldr r2, [r10, #0x4] */
/* @0x22b9fc cmp r2, r4 */
/* @0x22ba00 mov r3, r2 */
/* @0x22ba04 bgt 0x22b9e0 <vorbis_synthesis_headerin+0xa7c> */
/* @0x22ba08 cmp r2, #0 */
/* @0x22ba0c ble 0x22ba74 <vorbis_synthesis_headerin+0xb10> */
/* @0x22ba10 ldr r1, [r11, #-0x3c] */
/* @0x22ba14 mov r7, #0 */
/* @0x22ba18 mov r8, r7 */
/* @0x22ba1c mov r4, r7 */
/* @0x22ba20 lsl r9, r1, #2 */
/* @0x22ba24 mov r12, r9 */
/* @0x22ba28 mov r9, r1 */
/* @0x22ba2c ldr r1, [r6, r7] */
/* @0x22ba30 ldr r3, [r5] */
/* @0x22ba34 cmp r1, #0 */
/* @0x22ba38 ldr r0, [r3, r7] */
/* @0x22ba3c bne 0x22baa8 <vorbis_synthesis_headerin+0xb44> */
/* @0x22ba40 cmp r9, #0 */
/* @0x22ba44 movgt r3, r0 */
/* @0x22ba48 addgt r2, r3, r12 */
/* @0x22ba4c ble 0x22ba60 <vorbis_synthesis_headerin+0xafc> */
/* @0x22ba50 str r4, [r3], #4 */
/* @0x22ba54 cmp r3, r2 */
/* @0x22ba58 bne 0x22ba50 <vorbis_synthesis_headerin+0xaec> */
/* @0x22ba5c ldr r2, [r10, #0x4] */
/* @0x22ba60 add r8, r8, #1 */
/* @0x22ba64 add r7, r7, #4 */
/* @0x22ba68 cmp r2, r8 */
/* @0x22ba6c mov r3, r2 */
/* @0x22ba70 bgt 0x22ba2c <vorbis_synthesis_headerin+0xac8> */
/* @0x22ba74 ldr r1, [r11, #-0x40] */
/* @0x22ba78 mov r0, #0 */
/* @0x22ba7c ldr r2, [pc, #0x64] */
/* @0x22ba80 ldr r4, [r11, #-0x28] */
/* @0x22ba84 add r2, pc, r2 */
/* @0x22ba88 ldr r12, [r1] */
/* @0x22ba8c ldr r1, [r2] */
/* @0x22ba90 cmp r4, r12 */
/* @0x22ba94 add r3, r3, r1 */
/* @0x22ba98 str r3, [r2] */
/* @0x22ba9c bne 0x22bae0 <vorbis_synthesis_headerin+0xb7c> */
/* @0x22baa0 sub sp, r11, #32 */
/* @0x22baa4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22baa8 ldr lr, [r5, #0x20] */
/* @0x22baac ldr r3, [r5, #0x18] */
/* @0x22bab0 ldr r2, [r11, #-0x44] */
/* @0x22bab4 str lr, [r11, #-0x30] */
/* @0x22bab8 ldr lr, [r5, #0x1c] */
/* @0x22babc ldr r1, [r11, #-0x48] */
/* @0x22bac0 str r12, [r11, #-0x5c] */
/* @0x22bac4 str lr, [sp] */
/* @0x22bac8 ldr lr, [r11, #-0x30] */
/* @0x22bacc str lr, [sp, #0x4] */
/* @0x22bad0 bl 0x23311c <_vorbis_apply_window> */
/* @0x22bad4 ldr r2, [r10, #0x4] */
/* @0x22bad8 ldr r12, [r11, #-0x5c] */
/* @0x22badc b 0x22ba60 <vorbis_synthesis_headerin+0xafc> */
/* @0x22bae0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x22bae4 andseq r2, r12, r12, lsl r3 */
/* @0x22bae8 ldrsheq r9, [r2], #-212 */
/* @0x22baec push {r3, r4, r5, lr} */
/* @0x22baf0 subs r5, r0, #0 */
/* @0x22baf4 popeq {r3, r4, r5, pc} */
/* @0x22baf8 ldr r3, [r5, #0x4] */
/* @0x22bafc ldr r3, [r3] */
/* @0x22bb00 cmp r3, #0 */
/* @0x22bb04 movgt r4, #0 */
/* @0x22bb08 ble 0x22bb50 <vorbis_synthesis_headerin+0xbec> */
/* @0x22bb0c ldr r3, [r5, #0x10] */
/* @0x22bb10 ldr r2, [r5, #0x8] */
/* @0x22bb14 ldr r3, [r3, r4, lsl #2] */
/* @0x22bb18 ldr r0, [r2, r4, lsl #2] */
/* @0x22bb1c ldr r3, [r3, #0xc] */
/* @0x22bb20 blx r3 */
/* @0x22bb24 ldr r3, [r5, #0x14] */
/* @0x22bb28 ldr r2, [r5, #0xc] */
/* @0x22bb2c ldr r3, [r3, r4, lsl #2] */
/* @0x22bb30 ldr r0, [r2, r4, lsl #2] */
/* @0x22bb34 add r4, r4, #1 */
/* @0x22bb38 ldr r3, [r3, #0xc] */
/* @0x22bb3c blx r3 */
/* @0x22bb40 ldr r3, [r5, #0x4] */
/* @0x22bb44 ldr r3, [r3] */
/* @0x22bb48 cmp r3, r4 */
/* @0x22bb4c bgt 0x22bb0c <vorbis_synthesis_headerin+0xba8> */
/* @0x22bb50 ldr r0, [r5, #0x10] */
/* @0x22bb54 bl 0xb655c <free@plt> */
/* @0x22bb58 ldr r0, [r5, #0x14] */
/* @0x22bb5c bl 0xb655c <free@plt> */
/* @0x22bb60 ldr r0, [r5, #0x8] */
/* @0x22bb64 bl 0xb655c <free@plt> */
/* @0x22bb68 ldr r0, [r5, #0xc] */
/* @0x22bb6c bl 0xb655c <free@plt> */
/* @0x22bb70 mov r0, r5 */
/* @0x22bb74 mov r1, #0 */
/* @0x22bb78 mov r2, #32 */
/* @0x22bb7c bl 0xb65b0 <memset@plt> */
/* @0x22bb80 mov r0, r5 */
/* @0x22bb84 pop {r3, r4, r5, lr} */
/* @0x22bb88 b 0xb655c <free@plt> */
/* @0x22bb8c push {r4, lr} */
/* @0x22bb90 subs r4, r0, #0 */
/* @0x22bb94 popeq {r4, pc} */
/* @0x22bb98 mov r1, #0 */
/* @0x22bb9c mov r2, #3216 */
/* @0x22bba0 bl 0xb65b0 <memset@plt> */
/* @0x22bba4 mov r0, r4 */
/* @0x22bba8 pop {r4, lr} */
/* @0x22bbac b 0xb655c <free@plt> */
/* @0x22bbb0 ldr r3, [r0, #0x4] */
/* @0x22bbb4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22bbb8 sub sp, sp, #20 */
/* @0x22bbbc mov r8, r1 */
/* @0x22bbc0 mov r7, r0 */
/* @0x22bbc4 mov r1, #32 */
/* @0x22bbc8 mov r0, #1 */
/* @0x22bbcc str r2, [sp, #0x4] */
/* @0x22bbd0 str r3, [sp, #0xc] */
/* @0x22bbd4 ldr r9, [r3, #0x1c] */
/* @0x22bbd8 bl 0xb6c34 <calloc@plt> */
/* @0x22bbdc ldr r3, [sp, #0x4] */
/* @0x22bbe0 mov r1, #4 */
/* @0x22bbe4 ldr r4, [r3] */
/* @0x22bbe8 mov r5, r0 */
/* @0x22bbec str r3, [r0, #0x4] */
/* @0x22bbf0 str r8, [r0] */
/* @0x22bbf4 mov r0, r4 */
/* @0x22bbf8 bl 0xb6c34 <calloc@plt> */
/* @0x22bbfc mov r1, #4 */
/* @0x22bc00 str r0, [r5, #0x8] */
/* @0x22bc04 mov r0, r4 */
/* @0x22bc08 bl 0xb6c34 <calloc@plt> */
/* @0x22bc0c mov r1, #4 */
/* @0x22bc10 str r0, [r5, #0xc] */
/* @0x22bc14 mov r0, r4 */
/* @0x22bc18 bl 0xb6c34 <calloc@plt> */
/* @0x22bc1c mov r1, #4 */
/* @0x22bc20 mov r6, r0 */
/* @0x22bc24 mov r0, r4 */
/* @0x22bc28 str r6, [r5, #0x10] */
/* @0x22bc2c bl 0xb6c34 <calloc@plt> */
/* @0x22bc30 cmp r4, #0 */
/* @0x22bc34 str r0, [r5, #0x14] */
/* @0x22bc38 ble 0x22bcfc <vorbis_synthesis_headerin+0xd98> */
/* @0x22bc3c ldr r12, [pc, #0xd0] */
/* @0x22bc40 mov lr, r6 */
/* @0x22bc44 ldr r3, [pc, #0xcc] */
/* @0x22bc48 mov r4, #0 */
/* @0x22bc4c ldr r6, [sp, #0x4] */
/* @0x22bc50 ldr r12, [pc, r12] */
/* @0x22bc54 ldr r3, [pc, r3] */
/* @0x22bc58 str r3, [sp, #0x8] */
/* @0x22bc5c b 0x22bc64 <vorbis_synthesis_headerin+0xd00> */
/* @0x22bc60 ldr lr, [r5, #0x10] */
/* @0x22bc64 ldr r3, [r6, #0x404] */
/* @0x22bc68 mov r1, r8 */
/* @0x22bc6c ldr r11, [r6, #0x444] */
/* @0x22bc70 mov r0, r7 */
/* @0x22bc74 add r6, r6, #4 */
/* @0x22bc78 add r3, r9, r3, lsl #2 */
/* @0x22bc7c add r11, r9, r11, lsl #2 */
/* @0x22bc80 ldr r2, [r3, #0x420] */
/* @0x22bc84 ldr r2, [r12, r2, lsl #2] */
/* @0x22bc88 str r2, [lr, r4, lsl #2] */
/* @0x22bc8c ldr lr, [r5, #0x10] */
/* @0x22bc90 ldr r2, [r3, #0x520] */
/* @0x22bc94 ldr r10, [r5, #0x8] */
/* @0x22bc98 ldr r3, [lr, r4, lsl #2] */
/* @0x22bc9c ldr r3, [r3, #0x4] */
/* @0x22bca0 str r12, [sp] */
/* @0x22bca4 blx r3 */
/* @0x22bca8 ldr lr, [sp, #0x8] */
/* @0x22bcac mov r1, r8 */
/* @0x22bcb0 str r0, [r10, r4, lsl #2] */
/* @0x22bcb4 mov r0, r7 */
/* @0x22bcb8 ldr r2, [r11, #0x620] */
/* @0x22bcbc ldr r3, [r5, #0x14] */
/* @0x22bcc0 ldr r2, [lr, r2, lsl #2] */
/* @0x22bcc4 str r2, [r3, r4, lsl #2] */
/* @0x22bcc8 ldr r3, [r5, #0x14] */
/* @0x22bccc ldr r2, [r11, #0x720] */
/* @0x22bcd0 ldr r10, [r5, #0xc] */
/* @0x22bcd4 ldr r3, [r3, r4, lsl #2] */
/* @0x22bcd8 ldr r3, [r3, #0x4] */
/* @0x22bcdc blx r3 */
/* @0x22bce0 ldr r2, [sp, #0x4] */
/* @0x22bce4 ldr r12, [sp] */
/* @0x22bce8 ldr r3, [r2] */
/* @0x22bcec str r0, [r10, r4, lsl #2] */
/* @0x22bcf0 add r4, r4, #1 */
/* @0x22bcf4 cmp r3, r4 */
/* @0x22bcf8 bgt 0x22bc60 <vorbis_synthesis_headerin+0xcfc> */
/* @0x22bcfc ldr r2, [sp, #0xc] */
/* @0x22bd00 mov r0, r5 */
/* @0x22bd04 ldr r3, [r2, #0x4] */
/* @0x22bd08 str r3, [r5, #0x18] */
/* @0x22bd0c add sp, sp, #20 */
/* @0x22bd10 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22bd14 andseq r5, r12, r4, lsr r8 */
/* @0x22bd18 andseq r5, r12, r4, lsr r8 */
/* @0x22bd1c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x22bd20 mov r5, r0 */
/* @0x22bd24 mov r4, r1 */
/* @0x22bd28 mov r0, #1 */
/* @0x22bd2c mov r1, #3216 */
/* @0x22bd30 bl 0xb6c34 <calloc@plt> */
/* @0x22bd34 mov r1, #0 */
/* @0x22bd38 mov r2, #3216 */
/* @0x22bd3c ldr r9, [r5, #0x1c] */
/* @0x22bd40 mov r6, r0 */
/* @0x22bd44 bl 0xb65b0 <memset@plt> */
/* @0x22bd48 mov r0, r4 */
/* @0x22bd4c mov r1, #1 */
/* @0x22bd50 bl 0x233b28 <oggpack_read> */
/* @0x22bd54 cmp r0, #0 */
/* @0x22bd58 blt 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22bd5c moveq r3, #1 */
/* @0x22bd60 streq r3, [r6] */
/* @0x22bd64 bne 0x22bf54 <vorbis_synthesis_headerin+0xff0> */
/* @0x22bd68 mov r0, r4 */
/* @0x22bd6c mov r1, #1 */
/* @0x22bd70 bl 0x233b28 <oggpack_read> */
/* @0x22bd74 cmp r0, #0 */
/* @0x22bd78 blt 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22bd7c beq 0x22be48 <vorbis_synthesis_headerin+0xee4> */
/* @0x22bd80 mov r0, r4 */
/* @0x22bd84 mov r1, #8 */
/* @0x22bd88 bl 0x233b28 <oggpack_read> */
/* @0x22bd8c add r0, r0, #1 */
/* @0x22bd90 str r0, [r6, #0x48c] */
/* @0x22bd94 cmp r0, #0 */
/* @0x22bd98 ble 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22bd9c add r7, r6, #2176 */
/* @0x22bda0 ldr r1, [r5, #0x4] */
/* @0x22bda4 add r7, r7, #12 */
/* @0x22bda8 mov r8, #0 */
/* @0x22bdac cmp r1, #0 */
/* @0x22bdb0 beq 0x22bdd0 <vorbis_synthesis_headerin+0xe6c> */
/* @0x22bdb4 subs r3, r1, #1 */
/* @0x22bdb8 moveq r1, r3 */
/* @0x22bdbc beq 0x22bdd0 <vorbis_synthesis_headerin+0xe6c> */
/* @0x22bdc0 mov r1, #0 */
/* @0x22bdc4 lsrs r3, r3, #1 */
/* @0x22bdc8 add r1, r1, #1 */
/* @0x22bdcc bne 0x22bdc4 <vorbis_synthesis_headerin+0xe60> */
/* @0x22bdd0 mov r0, r4 */
/* @0x22bdd4 bl 0x233b28 <oggpack_read> */
/* @0x22bdd8 ldr r1, [r5, #0x4] */
/* @0x22bddc cmp r1, #0 */
/* @0x22bde0 mov r10, r0 */
/* @0x22bde4 str r0, [r7, #-0x3fc] */
/* @0x22bde8 beq 0x22be08 <vorbis_synthesis_headerin+0xea4> */
/* @0x22bdec subs r3, r1, #1 */
/* @0x22bdf0 moveq r1, r3 */
/* @0x22bdf4 beq 0x22be08 <vorbis_synthesis_headerin+0xea4> */
/* @0x22bdf8 mov r1, #0 */
/* @0x22bdfc lsrs r3, r3, #1 */
/* @0x22be00 add r1, r1, #1 */
/* @0x22be04 bne 0x22bdfc <vorbis_synthesis_headerin+0xe98> */
/* @0x22be08 mov r0, r4 */
/* @0x22be0c bl 0x233b28 <oggpack_read> */
/* @0x22be10 orrs r3, r10, r0 */
/* @0x22be14 str r0, [r7, #0x4]! */
/* @0x22be18 bmi 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22be1c cmp r10, r0 */
/* @0x22be20 beq 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22be24 ldr r1, [r5, #0x4] */
/* @0x22be28 cmp r10, r1 */
/* @0x22be2c bge 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22be30 cmp r0, r1 */
/* @0x22be34 bge 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22be38 ldr r3, [r6, #0x48c] */
/* @0x22be3c add r8, r8, #1 */
/* @0x22be40 cmp r3, r8 */
/* @0x22be44 bgt 0x22bdac <vorbis_synthesis_headerin+0xe48> */
/* @0x22be48 mov r0, r4 */
/* @0x22be4c mov r1, #2 */
/* @0x22be50 bl 0x233b28 <oggpack_read> */
/* @0x22be54 cmp r0, #0 */
/* @0x22be58 bne 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22be5c ldr r3, [r6] */
/* @0x22be60 cmp r3, #1 */
/* @0x22be64 ble 0x22bec4 <vorbis_synthesis_headerin+0xf60> */
/* @0x22be68 ldr r3, [r5, #0x4] */
/* @0x22be6c cmp r3, #0 */
/* @0x22be70 movgt r7, r0 */
/* @0x22be74 movgt r8, r6 */
/* @0x22be78 bgt 0x22be94 <vorbis_synthesis_headerin+0xf30> */
/* @0x22be7c b 0x22becc <vorbis_synthesis_headerin+0xf68> */
/* @0x22be80 cmp r0, #0 */
/* @0x22be84 blt 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22be88 ldr r2, [r5, #0x4] */
/* @0x22be8c cmp r2, r7 */
/* @0x22be90 ble 0x22bec4 <vorbis_synthesis_headerin+0xf60> */
/* @0x22be94 mov r0, r4 */
/* @0x22be98 mov r1, #4 */
/* @0x22be9c bl 0x233b28 <oggpack_read> */
/* @0x22bea0 add r7, r7, #1 */
/* @0x22bea4 str r0, [r8, #0x4]! */
/* @0x22bea8 ldr r3, [r6] */
/* @0x22beac cmp r0, r3 */
/* @0x22beb0 blt 0x22be80 <vorbis_synthesis_headerin+0xf1c> */
/* @0x22beb4 mov r0, r6 */
/* @0x22beb8 bl 0x22bb8c <vorbis_synthesis_headerin+0xc28> */
/* @0x22bebc mov r0, #0 */
/* @0x22bec0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x22bec4 cmp r3, #0 */
/* @0x22bec8 ble 0x22bf74 <vorbis_synthesis_headerin+0x1010> */
/* @0x22becc mov r5, r6 */
/* @0x22bed0 mov r7, #0 */
/* @0x22bed4 b 0x22bf2c <vorbis_synthesis_headerin+0xfc8> */
/* @0x22bed8 bl 0x233b28 <oggpack_read> */
/* @0x22bedc ldr r2, [r9, #0x14] */
/* @0x22bee0 mov r1, #8 */
/* @0x22bee4 mov r3, r0 */
/* @0x22bee8 cmp r3, r2 */
/* @0x22beec mov r0, r4 */
/* @0x22bef0 str r3, [r5, #0x404] */
/* @0x22bef4 bge 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22bef8 cmp r3, #0 */
/* @0x22befc blt 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22bf00 bl 0x233b28 <oggpack_read> */
/* @0x22bf04 ldr r3, [r9, #0x18] */
/* @0x22bf08 add r5, r5, #4 */
/* @0x22bf0c cmp r0, r3 */
/* @0x22bf10 str r0, [r5, #0x440] */
/* @0x22bf14 bge 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22bf18 cmp r0, #0 */
/* @0x22bf1c blt 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22bf20 ldr r3, [r6] */
/* @0x22bf24 cmp r3, r7 */
/* @0x22bf28 ble 0x22bf74 <vorbis_synthesis_headerin+0x1010> */
/* @0x22bf2c mov r1, #8 */
/* @0x22bf30 mov r0, r4 */
/* @0x22bf34 bl 0x233b28 <oggpack_read> */
/* @0x22bf38 ldr r3, [r9, #0x10] */
/* @0x22bf3c mov r1, #8 */
/* @0x22bf40 add r7, r7, #1 */
/* @0x22bf44 cmp r0, r3 */
/* @0x22bf48 mov r0, r4 */
/* @0x22bf4c blt 0x22bed8 <vorbis_synthesis_headerin+0xf74> */
/* @0x22bf50 b 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22bf54 mov r0, r4 */
/* @0x22bf58 mov r1, #4 */
/* @0x22bf5c bl 0x233b28 <oggpack_read> */
/* @0x22bf60 add r0, r0, #1 */
/* @0x22bf64 str r0, [r6] */
/* @0x22bf68 cmp r0, #0 */
/* @0x22bf6c bgt 0x22bd68 <vorbis_synthesis_headerin+0xe04> */
/* @0x22bf70 b 0x22beb4 <vorbis_synthesis_headerin+0xf50> */
/* @0x22bf74 mov r0, r6 */
/* @0x22bf78 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x22bf7c · mdct_backward · size=8040 · insn=2010 */
/* @0x22bf7c push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x22bf80 tst r0, #64 */
/* @0x22bf84 sub sp, sp, #256 */
/* @0x22bf88 mov r11, r1 */
/* @0x22bf8c asr r1, r0, #1 */
/* @0x22bf90 str r2, [sp, #0xf4] */
/* @0x22bf94 str r1, [sp, #0x88] */
/* @0x22bf98 asr r1, r0, #2 */
/* @0x22bf9c bne 0x22de9c <mdct_backward+0x1f20> */
/* @0x22bfa0 mov r3, #6 */
/* @0x22bfa4 add r3, r3, #1 */
/* @0x22bfa8 asr r2, r0, r3 */
/* @0x22bfac tst r2, #1 */
/* @0x22bfb0 beq 0x22bfa4 <mdct_backward+0x28> */
/* @0x22bfb4 rsb r2, r3, #13 */
/* @0x22bfb8 str r2, [sp, #0x9c] */
/* @0x22bfbc ldr r4, [sp, #0x9c] */
/* @0x22bfc0 mov r2, #2 */
/* @0x22bfc4 sub r3, r3, #6 */
/* @0x22bfc8 str r3, [sp, #0x90] */
/* @0x22bfcc lsl r2, r2, r4 */
/* @0x22bfd0 str r2, [sp, #0xf8] */
/* @0x22bfd4 lsl r5, r2, #2 */
/* @0x22bfd8 asr r6, r2, #2 */
/* @0x22bfdc rsb r7, r5, #0 */
/* @0x22bfe0 str r5, [sp, #0xe4] */
/* @0x22bfe4 str r6, [sp, #0xec] */
/* @0x22bfe8 str r7, [sp, #0xcc] */
/* @0x22bfec ldr r3, [sp, #0x88] */
/* @0x22bff0 ldr r4, [sp, #0xf4] */
/* @0x22bff4 sub r2, r3, #-1073741817 */
/* @0x22bff8 add r3, r1, r3 */
/* @0x22bffc ldr r9, [pc, #0x7d4] */
/* @0x22c000 lsl r1, r1, #2 */
/* @0x22c004 lsl r2, r2, #2 */
/* @0x22c008 add r3, r4, r3, lsl #2 */
/* @0x22c00c ldr r6, [sp, #0xe4] */
/* @0x22c010 add r9, pc, r9 */
/* @0x22c014 ldr r10, [sp, #0xe4] */
/* @0x22c018 add r12, r11, r2 */
/* @0x22c01c mov r8, r3 */
/* @0x22c020 add r5, r11, r1 */
/* @0x22c024 lsl r6, r6, #1 */
/* @0x22c028 str r1, [sp, #0xfc] */
/* @0x22c02c str r2, [sp, #0x20] */
/* @0x22c030 str r3, [sp, #0xe8] */
/* @0x22c034 str r5, [sp, #0x10] */
/* @0x22c038 str r6, [sp, #0xc8] */
/* @0x22c03c str r11, [sp, #0x28] */
/* @0x22c040 ldm r9, {r2, r4} */
/* @0x22c044 sub r8, r8, #16 */
/* @0x22c048 ldr r0, [r12, #0x10] */
/* @0x22c04c add r11, r9, r10 */
/* @0x22c050 ldr r3, [r12, #0x18] */
/* @0x22c054 sub r12, r12, #32 */
/* @0x22c058 smull r6, r7, r3, r4 */
/* @0x22c05c smull r4, r5, r0, r4 */
/* @0x22c060 smull r0, r1, r0, r2 */
/* @0x22c064 lsl r0, r7, #1 */
/* @0x22c068 smull r2, r3, r2, r3 */
/* @0x22c06c lsl r2, r5, #1 */
/* @0x22c070 ldr r7, [sp, #0x10] */
/* @0x22c074 add r0, r0, r1, lsl #1 */
/* @0x22c078 str r0, [r8, #0x8] */
/* @0x22c07c rsb r3, r2, r3, lsl #1 */
/* @0x22c080 str r3, [r8, #0xc] */
/* @0x22c084 ldr r4, [r11, #0x4] */
/* @0x22c088 ldr r0, [r12, #0x20] */
/* @0x22c08c ldr r3, [r12, #0x28] */
/* @0x22c090 cmp r12, r7 */
/* @0x22c094 ldr r2, [r9, r10] */
/* @0x22c098 ldr r11, [sp, #0xc8] */
/* @0x22c09c smull r6, r7, r3, r4 */
/* @0x22c0a0 add r9, r9, r11 */
/* @0x22c0a4 smull r4, r5, r0, r4 */
/* @0x22c0a8 smull r0, r1, r0, r2 */
/* @0x22c0ac lsl r0, r7, #1 */
/* @0x22c0b0 smull r2, r3, r2, r3 */
/* @0x22c0b4 lsl r2, r5, #1 */
/* @0x22c0b8 add r0, r0, r1, lsl #1 */
/* @0x22c0bc str r0, [r8] */
/* @0x22c0c0 rsb r3, r2, r3, lsl #1 */
/* @0x22c0c4 str r3, [r8, #0x4] */
/* @0x22c0c8 bhs 0x22c040 <mdct_backward+0xc4> */
/* @0x22c0cc ldr r0, [sp, #0xcc] */
/* @0x22c0d0 ldr r10, [sp, #0xcc] */
/* @0x22c0d4 lsl r0, r0, #1 */
/* @0x22c0d8 str r0, [sp, #0xd4] */
/* @0x22c0dc mov r11, r9 */
/* @0x22c0e0 ldr r3, [r12, #0x18] */
/* @0x22c0e4 ldr r0, [r12, #0x10] */
/* @0x22c0e8 sub r8, r8, #16 */
/* @0x22c0ec ldr r4, [r11], r10 */
/* @0x22c0f0 sub r12, r12, #32 */
/* @0x22c0f4 ldr r2, [r9, #0x4] */
/* @0x22c0f8 smull r6, r7, r3, r4 */
/* @0x22c0fc smull r4, r5, r0, r4 */
/* @0x22c100 smull r0, r1, r0, r2 */
/* @0x22c104 lsl r0, r7, #1 */
/* @0x22c108 smull r2, r3, r2, r3 */
/* @0x22c10c lsl r2, r5, #1 */
/* @0x22c110 ldr r5, [sp, #0xd4] */
/* @0x22c114 add r0, r0, r1, lsl #1 */
/* @0x22c118 str r0, [r8, #0x8] */
/* @0x22c11c ldr r1, [sp, #0x28] */
/* @0x22c120 rsb r3, r2, r3, lsl #1 */
/* @0x22c124 str r3, [r8, #0xc] */
/* @0x22c128 ldr r0, [r12, #0x20] */
/* @0x22c12c ldr r3, [r12, #0x28] */
/* @0x22c130 cmp r1, r12 */
/* @0x22c134 ldr r4, [r9, r10] */
/* @0x22c138 add r9, r9, r5 */
/* @0x22c13c ldr r2, [r11, #0x4] */
/* @0x22c140 smull r6, r7, r3, r4 */
/* @0x22c144 smull r4, r5, r0, r4 */
/* @0x22c148 smull r0, r1, r0, r2 */
/* @0x22c14c lsl r0, r7, #1 */
/* @0x22c150 smull r2, r3, r2, r3 */
/* @0x22c154 lsl r2, r5, #1 */
/* @0x22c158 add r0, r0, r1, lsl #1 */
/* @0x22c15c str r0, [r8] */
/* @0x22c160 rsb r3, r2, r3, lsl #1 */
/* @0x22c164 str r3, [r8, #0x4] */
/* @0x22c168 bls 0x22c0dc <mdct_backward+0x160> */
/* @0x22c16c ldr r9, [pc, #0x668] */
/* @0x22c170 ldr r11, [sp, #0x28] */
/* @0x22c174 ldr r6, [sp, #0x20] */
/* @0x22c178 add r9, pc, r9 */
/* @0x22c17c ldr r7, [sp, #0xe4] */
/* @0x22c180 ldr r12, [sp, #0xe8] */
/* @0x22c184 sub r6, r6, #4 */
/* @0x22c188 add r9, r9, r7 */
/* @0x22c18c add r8, r11, r6 */
/* @0x22c190 str r11, [sp, #0x20] */
/* @0x22c194 mov r11, r7 */
/* @0x22c198 str r6, [sp, #0x28] */
/* @0x22c19c ldr r2, [r8, #0x18] */
/* @0x22c1a0 add r10, r9, r11 */
/* @0x22c1a4 ldr r4, [r9, #0x4] */
/* @0x22c1a8 add r12, r12, #16 */
/* @0x22c1ac ldr r0, [r8, #0x10] */
/* @0x22c1b0 ldr r3, [r9] */
/* @0x22c1b4 smull r6, r7, r2, r4 */
/* @0x22c1b8 smull r4, r5, r0, r4 */
/* @0x22c1bc smull r0, r1, r3, r0 */
/* @0x22c1c0 lsl r0, r7, #1 */
/* @0x22c1c4 smull r2, r3, r2, r3 */
/* @0x22c1c8 lsl r2, r5, #1 */
/* @0x22c1cc ldr r5, [sp, #0x10] */
/* @0x22c1d0 add r0, r0, r1, lsl #1 */
/* @0x22c1d4 str r0, [r12, #-0xc] */
/* @0x22c1d8 ldr r1, [sp, #0xc8] */
/* @0x22c1dc rsb r3, r2, r3, lsl #1 */
/* @0x22c1e0 str r3, [r12, #-0x10] */
/* @0x22c1e4 ldr r2, [r8, #0x8] */
/* @0x22c1e8 ldr r4, [r10, #0x4] */
/* @0x22c1ec ldr r0, [r8], #-32 */
/* @0x22c1f0 ldr r3, [r9, r11] */
/* @0x22c1f4 add r9, r9, r1 */
/* @0x22c1f8 smull r6, r7, r2, r4 */
/* @0x22c1fc cmp r8, r5 */
/* @0x22c200 smull r4, r5, r0, r4 */
/* @0x22c204 smull r0, r1, r3, r0 */
/* @0x22c208 lsl r0, r7, #1 */
/* @0x22c20c smull r2, r3, r2, r3 */
/* @0x22c210 lsl r2, r5, #1 */
/* @0x22c214 add r0, r0, r1, lsl #1 */
/* @0x22c218 str r0, [r12, #-0x4] */
/* @0x22c21c rsb r3, r2, r3, lsl #1 */
/* @0x22c220 str r3, [r12, #-0x8] */
/* @0x22c224 bhs 0x22c19c <mdct_backward+0x220> */
/* @0x22c228 ldr r9, [sp, #0xcc] */
/* @0x22c22c ldr r11, [sp, #0x20] */
/* @0x22c230 add r2, r10, r9 */
/* @0x22c234 ldr r0, [r8, #0x18] */
/* @0x22c238 ldr r3, [r8, #0x10] */
/* @0x22c23c add r12, r12, #16 */
/* @0x22c240 ldr r4, [r10, r9] */
/* @0x22c244 ldr r2, [r2, #0x4] */
/* @0x22c248 ldr r6, [sp, #0xd4] */
/* @0x22c24c add r10, r10, r6 */
/* @0x22c250 smull r6, r7, r3, r4 */
/* @0x22c254 smull r4, r5, r0, r4 */
/* @0x22c258 smull r0, r1, r0, r2 */
/* @0x22c25c lsl r0, r7, #1 */
/* @0x22c260 smull r2, r3, r2, r3 */
/* @0x22c264 lsl r2, r5, #1 */
/* @0x22c268 rsb r0, r0, r1, lsl #1 */
/* @0x22c26c str r0, [r12, #-0x10] */
/* @0x22c270 add r3, r2, r3, lsl #1 */
/* @0x22c274 str r3, [r12, #-0xc] */
/* @0x22c278 ldr r2, [r8, #0x8] */
/* @0x22c27c ldr r4, [r10] */
/* @0x22c280 ldr r0, [r8], #-32 */
/* @0x22c284 ldr r3, [r10, #0x4] */
/* @0x22c288 smull r6, r7, r2, r4 */
/* @0x22c28c cmp r11, r8 */
/* @0x22c290 smull r4, r5, r0, r4 */
/* @0x22c294 smull r0, r1, r3, r0 */
/* @0x22c298 lsl r0, r7, #1 */
/* @0x22c29c smull r2, r3, r2, r3 */
/* @0x22c2a0 lsl r2, r5, #1 */
/* @0x22c2a4 add r0, r0, r1, lsl #1 */
/* @0x22c2a8 str r0, [r12, #-0x4] */
/* @0x22c2ac rsb r3, r2, r3, lsl #1 */
/* @0x22c2b0 str r3, [r12, #-0x8] */
/* @0x22c2b4 bls 0x22c230 <mdct_backward+0x2b4> */
/* @0x22c2b8 ldr r7, [sp, #0x90] */
/* @0x22c2bc ldr r8, [sp, #0x28] */
/* @0x22c2c0 str r9, [sp, #0xcc] */
/* @0x22c2c4 cmp r7, #0 */
/* @0x22c2c8 ldr r9, [sp, #0xf4] */
/* @0x22c2cc add r3, r8, #32 */
/* @0x22c2d0 add r3, r9, r3 */
/* @0x22c2d4 str r3, [sp, #0xbc] */
/* @0x22c2d8 beq 0x22cc14 <mdct_backward+0xc98> */
/* @0x22c2dc ldr r2, [pc, #0x4fc] */
/* @0x22c2e0 mov r10, #0 */
/* @0x22c2e4 ldr r3, [pc, #0x4f8] */
/* @0x22c2e8 ldr r11, [pc, #0x4f8] */
/* @0x22c2ec add r2, pc, r2 */
/* @0x22c2f0 ldr r12, [pc, #0x4f4] */
/* @0x22c2f4 add r3, pc, r3 */
/* @0x22c2f8 ldr r0, [pc, #0x4f0] */
/* @0x22c2fc add r2, r2, #4096 */
/* @0x22c300 add r3, r3, #4096 */
/* @0x22c304 add r11, pc, r11 */
/* @0x22c308 add r12, pc, r12 */
/* @0x22c30c add r0, pc, r0 */
/* @0x22c310 str r10, [sp, #0x98] */
/* @0x22c314 str r2, [sp, #0x54] */
/* @0x22c318 str r3, [sp, #0x5c] */
/* @0x22c31c str r11, [sp, #0x84] */
/* @0x22c320 str r12, [sp, #0x58] */
/* @0x22c324 str r0, [sp, #0x60] */
/* @0x22c328 ldr r10, [sp, #0x98] */
/* @0x22c32c mov r9, #1 */
/* @0x22c330 lsl r9, r9, r10 */
/* @0x22c334 str r9, [sp, #0x70] */
/* @0x22c338 cmp r9, #0 */
/* @0x22c33c ble 0x22cbfc <mdct_backward+0xc80> */
/* @0x22c340 ldr r12, [sp, #0x88] */
/* @0x22c344 mov r1, #4 */
/* @0x22c348 ldr r11, [sp, #0x9c] */
/* @0x22c34c mov r4, #0 */
/* @0x22c350 str r4, [sp, #0x78] */
/* @0x22c354 add r3, r10, r11 */
/* @0x22c358 asr r0, r12, r10 */
/* @0x22c35c lsl r3, r1, r3 */
/* @0x22c360 sub r2, r0, #-1073741816 */
/* @0x22c364 asr r0, r0, #1 */
/* @0x22c368 ldr r12, [sp, #0xbc] */
/* @0x22c36c lsl r5, r3, #2 */
/* @0x22c370 sub r0, r0, #-1073741816 */
/* @0x22c374 rsb r1, r5, #0 */
/* @0x22c378 lsl r2, r2, #2 */
/* @0x22c37c rsb r0, r2, r0, lsl #2 */
/* @0x22c380 lsl r6, r3, #3 */
/* @0x22c384 lsl r7, r1, #1 */
/* @0x22c388 lsl r8, r1, #2 */
/* @0x22c38c sub r9, r0, #32 */
/* @0x22c390 add r10, r2, #32 */
/* @0x22c394 str r0, [sp, #0x68] */
/* @0x22c398 add r1, r7, r1 */
/* @0x22c39c add r2, r12, r2 */
/* @0x22c3a0 lsl r3, r3, #4 */
/* @0x22c3a4 add r0, r6, r5 */
/* @0x22c3a8 str r5, [sp, #0x20] */
/* @0x22c3ac str r6, [sp, #0x38] */
/* @0x22c3b0 str r7, [sp, #0x30] */
/* @0x22c3b4 str r8, [sp, #0x50] */
/* @0x22c3b8 str r1, [sp, #0x48] */
/* @0x22c3bc str r9, [sp, #0x80] */
/* @0x22c3c0 str r10, [sp, #0x7c] */
/* @0x22c3c4 str r2, [sp, #0x64] */
/* @0x22c3c8 str r3, [sp, #0x4c] */
/* @0x22c3cc str r0, [sp, #0x40] */
/* @0x22c3d0 ldr r2, [sp, #0x64] */
/* @0x22c3d4 ldr r1, [sp, #0x68] */
/* @0x22c3d8 ldr r3, [sp, #0x80] */
/* @0x22c3dc sub r11, r2, #32 */
/* @0x22c3e0 ldr r9, [sp, #0x84] */
/* @0x22c3e4 add r8, r1, r2 */
/* @0x22c3e8 add r10, r3, r2 */
/* @0x22c3ec mov r12, r2 */
/* @0x22c3f0 ldr r1, [r8, #0x18] */
/* @0x22c3f4 sub r11, r11, #32 */
/* @0x22c3f8 ldr r0, [r12, #0x18] */
/* @0x22c3fc sub r10, r10, #32 */
/* @0x22c400 ldr r4, [sp, #0x20] */
/* @0x22c404 sub r12, r12, #32 */
/* @0x22c408 ldr r3, [r12, #0x3c] */
/* @0x22c40c sub r8, r8, #32 */
/* @0x22c410 add r4, r9, r4 */
/* @0x22c414 str r4, [sp, #0x18] */
/* @0x22c418 add r4, r0, r1 */
/* @0x22c41c str r4, [r12, #0x38] */
/* @0x22c420 ldr r4, [r8, #0x3c] */
/* @0x22c424 rsb r0, r1, r0 */
/* @0x22c428 ldr r5, [sp, #0x38] */
/* @0x22c42c add r1, r4, r3 */
/* @0x22c430 str r1, [r12, #0x3c] */
/* @0x22c434 ldr r1, [r9, #0x4] */
/* @0x22c438 rsb r4, r3, r4 */
/* @0x22c43c add r5, r5, r9 */
/* @0x22c440 str r5, [sp, #0x28] */
/* @0x22c444 ldr r3, [r8, #0x30] */
/* @0x22c448 smull r6, r7, r0, r1 */
/* @0x22c44c strd r6, r7, [sp, #16] */
/* @0x22c450 smull r6, r7, r4, r1 */
/* @0x22c454 ldr r1, [r9] */
/* @0x22c458 ldr r2, [sp, #0x14] */
/* @0x22c45c ldr r6, [sp, #0x20] */
/* @0x22c460 smull r4, r5, r4, r1 */
/* @0x22c464 lsl r4, r2, #1 */
/* @0x22c468 smull r0, r1, r1, r0 */
/* @0x22c46c lsl r0, r7, #1 */
/* @0x22c470 add r4, r4, r5, lsl #1 */
/* @0x22c474 str r4, [r8, #0x38] */
/* @0x22c478 ldr r4, [sp, #0x40] */
/* @0x22c47c ldr r5, [sp, #0x18] */
/* @0x22c480 add r4, r4, r9 */
/* @0x22c484 rsb r0, r0, r1, lsl #1 */
/* @0x22c488 str r4, [sp, #0x10] */
/* @0x22c48c str r0, [r8, #0x3c] */
/* @0x22c490 ldr r4, [r12, #0x30] */
/* @0x22c494 ldr r1, [r12, #0x34] */
/* @0x22c498 add r0, r4, r3 */
/* @0x22c49c str r0, [r12, #0x30] */
/* @0x22c4a0 ldr r0, [r8, #0x34] */
/* @0x22c4a4 rsb r3, r3, r4 */
/* @0x22c4a8 add r4, r0, r1 */
/* @0x22c4ac str r4, [r12, #0x34] */
/* @0x22c4b0 ldr r4, [r5, #0x4] */
/* @0x22c4b4 rsb r0, r1, r0 */
/* @0x22c4b8 ldr r2, [r9, r6] */
/* @0x22c4bc smull r6, r7, r3, r4 */
/* @0x22c4c0 ldr r6, [r8, #0x28] */
/* @0x22c4c4 smull r4, r5, r0, r4 */
/* @0x22c4c8 smull r0, r1, r0, r2 */
/* @0x22c4cc lsl r0, r7, #1 */
/* @0x22c4d0 smull r2, r3, r2, r3 */
/* @0x22c4d4 lsl r2, r5, #1 */
/* @0x22c4d8 add r0, r0, r1, lsl #1 */
/* @0x22c4dc str r0, [r8, #0x30] */
/* @0x22c4e0 rsb r2, r2, r3, lsl #1 */
/* @0x22c4e4 str r2, [r8, #0x34] */
/* @0x22c4e8 ldr r2, [r12, #0x28] */
/* @0x22c4ec ldr r3, [r12, #0x2c] */
/* @0x22c4f0 add r1, r2, r6 */
/* @0x22c4f4 str r1, [r12, #0x28] */
/* @0x22c4f8 ldr r0, [r8, #0x2c] */
/* @0x22c4fc rsb r2, r6, r2 */
/* @0x22c500 ldr r7, [sp, #0x28] */
/* @0x22c504 add r1, r0, r3 */
/* @0x22c508 str r1, [r12, #0x2c] */
/* @0x22c50c ldr r1, [sp, #0x38] */
/* @0x22c510 rsb r0, r3, r0 */
/* @0x22c514 ldr r4, [r7, #0x4] */
/* @0x22c518 ldr r3, [r1, r9] */
/* @0x22c51c smull r6, r7, r2, r4 */
/* @0x22c520 ldr r6, [sp, #0x40] */
/* @0x22c524 smull r4, r5, r0, r4 */
/* @0x22c528 smull r0, r1, r0, r3 */
/* @0x22c52c lsl r0, r7, #1 */
/* @0x22c530 smull r2, r3, r3, r2 */
/* @0x22c534 lsl r2, r5, #1 */
/* @0x22c538 ldr r5, [sp, #0x10] */
/* @0x22c53c add r0, r0, r1, lsl #1 */
/* @0x22c540 str r0, [r8, #0x28] */
/* @0x22c544 ldr r7, [sp, #0x4c] */
/* @0x22c548 rsb r2, r2, r3, lsl #1 */
/* @0x22c54c str r2, [r8, #0x2c] */
/* @0x22c550 ldr r0, [r11, #0x40] */
/* @0x22c554 ldr r3, [r10, #0x40] */
/* @0x22c558 add r2, r0, r3 */
/* @0x22c55c rsb r0, r3, r0 */
/* @0x22c560 str r2, [r11, #0x40] */
/* @0x22c564 ldr r3, [r12, #0x24] */
/* @0x22c568 ldr r2, [r8, #0x24] */
/* @0x22c56c add r1, r2, r3 */
/* @0x22c570 str r1, [r12, #0x24] */
/* @0x22c574 ldr r4, [r5, #0x4] */
/* @0x22c578 rsb r2, r3, r2 */
/* @0x22c57c ldr r3, [r6, r9] */
/* @0x22c580 add r9, r9, r7 */
/* @0x22c584 ldr r1, [sp, #0x54] */
/* @0x22c588 smull r6, r7, r2, r4 */
/* @0x22c58c cmp r9, r1 */
/* @0x22c590 smull r4, r5, r0, r4 */
/* @0x22c594 smull r0, r1, r3, r0 */
/* @0x22c598 lsl r0, r7, #1 */
/* @0x22c59c smull r2, r3, r2, r3 */
/* @0x22c5a0 lsl r2, r5, #1 */
/* @0x22c5a4 rsb r0, r0, r1, lsl #1 */
/* @0x22c5a8 add r2, r2, r3, lsl #1 */
/* @0x22c5ac str r2, [r10, #0x40] */
/* @0x22c5b0 str r0, [r8, #0x24] */
/* @0x22c5b4 blo 0x22c3f0 <mdct_backward+0x474> */
/* @0x22c5b8 sub r3, r8, #32 */
/* @0x22c5bc sub r2, r12, #32 */
/* @0x22c5c0 str r3, [sp, #0x28] */
/* @0x22c5c4 mov r11, r3 */
/* @0x22c5c8 str r2, [sp, #0x10] */
/* @0x22c5cc mov r10, r11 */
/* @0x22c5d0 mov r11, r2 */
/* @0x22c5d4 b 0x22c5e8 <mdct_backward+0x66c> */
/* @0x22c5d8 sub r2, r12, #32 */
/* @0x22c5dc sub r3, r8, #32 */
/* @0x22c5e0 str r2, [sp, #0x10] */
/* @0x22c5e4 str r3, [sp, #0x28] */
/* @0x22c5e8 ldr r0, [r8, #0x18] */
/* @0x22c5ec sub r11, r11, #32 */
/* @0x22c5f0 ldr r4, [r12, #0x18] */
/* @0x22c5f4 sub r10, r10, #32 */
/* @0x22c5f8 ldr r2, [r12, #0x1c] */
/* @0x22c5fc add r3, r4, r0 */
/* @0x22c600 ldr r5, [sp, #0x20] */
/* @0x22c604 str r3, [r12, #0x18] */
/* @0x22c608 rsb r4, r0, r4 */
/* @0x22c60c ldr r3, [r8, #0x1c] */
/* @0x22c610 rsb r1, r5, r9 */
/* @0x22c614 ldr r6, [sp, #0x30] */
/* @0x22c618 add r0, r2, r3 */
/* @0x22c61c str r0, [r12, #0x1c] */
/* @0x22c620 ldr r5, [r9, #0x4] */
/* @0x22c624 rsb r2, r3, r2 */
/* @0x22c628 add r6, r6, r9 */
/* @0x22c62c str r6, [sp, #0x2c] */
/* @0x22c630 ldr r0, [r8, #0x10] */
/* @0x22c634 smull r6, r7, r2, r5 */
/* @0x22c638 strd r6, r7, [sp, #24] */
/* @0x22c63c smull r6, r7, r4, r5 */
/* @0x22c640 ldr r3, [sp, #0x1c] */
/* @0x22c644 lsl r5, r3, #1 */
/* @0x22c648 strd r6, r7, [sp, #192] */
/* @0x22c64c ldr r7, [r9] */
/* @0x22c650 smull r6, r7, r4, r7 */
/* @0x22c654 ldr r4, [r9] */
/* @0x22c658 smull r2, r3, r4, r2 */
/* @0x22c65c strd r6, r7, [sp, #160] */
/* @0x22c660 ldr r6, [sp, #0xc4] */
/* @0x22c664 rsb r4, r5, r7, lsl #1 */
/* @0x22c668 str r4, [r8, #0x18] */
/* @0x22c66c ldr r7, [sp, #0x48] */
/* @0x22c670 lsl r2, r6, #1 */
/* @0x22c674 add r2, r2, r3, lsl #1 */
/* @0x22c678 str r2, [r8, #0x1c] */
/* @0x22c67c ldr r4, [r12, #0x10] */
/* @0x22c680 add r7, r7, r9 */
/* @0x22c684 ldr r2, [r12, #0x14] */
/* @0x22c688 add r3, r4, r0 */
/* @0x22c68c str r3, [r12, #0x10] */
/* @0x22c690 ldr r3, [r8, #0x14] */
/* @0x22c694 rsb r0, r0, r4 */
/* @0x22c698 str r7, [sp, #0x18] */
/* @0x22c69c add r4, r2, r3 */
/* @0x22c6a0 str r4, [r12, #0x14] */
/* @0x22c6a4 ldr r4, [r1, #0x4] */
/* @0x22c6a8 rsb r2, r3, r2 */
/* @0x22c6ac ldr r3, [r1] */
/* @0x22c6b0 smull r6, r7, r2, r4 */
/* @0x22c6b4 ldr r6, [r8, #0x8] */
/* @0x22c6b8 smull r4, r5, r0, r4 */
/* @0x22c6bc smull r0, r1, r0, r3 */
/* @0x22c6c0 lsl r0, r7, #1 */
/* @0x22c6c4 smull r2, r3, r3, r2 */
/* @0x22c6c8 lsl r2, r5, #1 */
/* @0x22c6cc rsb r0, r0, r1, lsl #1 */
/* @0x22c6d0 str r0, [r8, #0x10] */
/* @0x22c6d4 add r2, r2, r3, lsl #1 */
/* @0x22c6d8 str r2, [r8, #0x14] */
/* @0x22c6dc ldr r0, [r12, #0x8] */
/* @0x22c6e0 ldr r2, [r12, #0xc] */
/* @0x22c6e4 add r3, r0, r6 */
/* @0x22c6e8 str r3, [r12, #0x8] */
/* @0x22c6ec ldr r3, [r8, #0xc] */
/* @0x22c6f0 rsb r0, r6, r0 */
/* @0x22c6f4 ldr r5, [sp, #0x30] */
/* @0x22c6f8 add r1, r2, r3 */
/* @0x22c6fc str r1, [r12, #0xc] */
/* @0x22c700 ldr r1, [sp, #0x2c] */
/* @0x22c704 rsb r2, r3, r2 */
/* @0x22c708 ldr r3, [r5, r9] */
/* @0x22c70c ldr r4, [r1, #0x4] */
/* @0x22c710 smull r6, r7, r2, r4 */
/* @0x22c714 ldr r6, [sp, #0x18] */
/* @0x22c718 smull r4, r5, r0, r4 */
/* @0x22c71c smull r0, r1, r0, r3 */
/* @0x22c720 lsl r0, r7, #1 */
/* @0x22c724 smull r2, r3, r3, r2 */
/* @0x22c728 lsl r2, r5, #1 */
/* @0x22c72c ldr r7, [sp, #0x48] */
/* @0x22c730 rsb r0, r0, r1, lsl #1 */
/* @0x22c734 str r0, [r8, #0x8] */
/* @0x22c738 add r2, r2, r3, lsl #1 */
/* @0x22c73c str r2, [r8, #0xc] */
/* @0x22c740 ldr r0, [r11, #0x40] */
/* @0x22c744 ldr r3, [r10, #0x40] */
/* @0x22c748 add r2, r0, r3 */
/* @0x22c74c rsb r0, r3, r0 */
/* @0x22c750 str r2, [r11, #0x40] */
/* @0x22c754 ldr r3, [r8, #0x4] */
/* @0x22c758 ldr r2, [r12, #0x4] */
/* @0x22c75c add r1, r2, r3 */
/* @0x22c760 str r1, [r12, #0x4] */
/* @0x22c764 ldr r4, [r6, #0x4] */
/* @0x22c768 rsb r2, r3, r2 */
/* @0x22c76c ldr r12, [sp, #0x50] */
/* @0x22c770 ldr r3, [r7, r9] */
/* @0x22c774 ldr r1, [sp, #0x58] */
/* @0x22c778 add r9, r9, r12 */
/* @0x22c77c smull r6, r7, r2, r4 */
/* @0x22c780 cmp r9, r1 */
/* @0x22c784 smull r4, r5, r0, r4 */
/* @0x22c788 ldr r12, [sp, #0x10] */
/* @0x22c78c smull r0, r1, r0, r3 */
/* @0x22c790 lsl r0, r7, #1 */
/* @0x22c794 smull r2, r3, r3, r2 */
/* @0x22c798 lsl r2, r5, #1 */
/* @0x22c79c rsb r0, r0, r1, lsl #1 */
/* @0x22c7a0 str r0, [r10, #0x40] */
/* @0x22c7a4 add r2, r2, r3, lsl #1 */
/* @0x22c7a8 str r2, [r8, #0x4] */
/* @0x22c7ac ldr r8, [sp, #0x28] */
/* @0x22c7b0 bhi 0x22c5d8 <mdct_backward+0x65c> */
/* @0x22c7b4 ldr r4, [sp, #0x10] */
/* @0x22c7b8 ldr r5, [sp, #0x28] */
/* @0x22c7bc sub r4, r4, #32 */
/* @0x22c7c0 str r4, [sp, #0x10] */
/* @0x22c7c4 sub r5, r5, #32 */
/* @0x22c7c8 str r5, [sp, #0x28] */
/* @0x22c7cc mov r11, r4 */
/* @0x22c7d0 mov r10, r5 */
/* @0x22c7d4 b 0x22c810 <mdct_backward+0x894> */
/* @0x22c7d8 mulseq r3, r0, r10 */
/* @0x22c7dc andseq r2, r3, r8, lsr #18 */
/* @0x22c7e0 ldrheq r2, [r3], -r4 */
/* @0x22c7e4 andseq r2, r3, r12, lsr #15 */
/* @0x22c7e8 mulseq r3, r12, r7 */
/* @0x22c7ec mulseq r3, r8, r7 */
/* @0x22c7f0 mulseq r3, r4, r7 */
/* @0x22c7f4 andseq r1, r3, r12, lsl #12 */
/* @0x22c7f8 andseq r3, r3, r12, ror #11 */
/* @0x22c7fc ldrsbeq r3, [r3], -r0 */
/* @0x22c800 sub r0, r12, #32 */
/* @0x22c804 sub r1, r8, #32 */
/* @0x22c808 str r0, [sp, #0x10] */
/* @0x22c80c str r1, [sp, #0x28] */
/* @0x22c810 ldr r1, [r12, #0x18] */
/* @0x22c814 sub r11, r11, #32 */
/* @0x22c818 ldr r4, [r8, #0x18] */
/* @0x22c81c sub r10, r10, #32 */
/* @0x22c820 ldr r3, [r12, #0x1c] */
/* @0x22c824 add r2, r4, r1 */
/* @0x22c828 str r2, [r12, #0x18] */
/* @0x22c82c ldr r2, [r8, #0x1c] */
/* @0x22c830 rsb r4, r1, r4 */
/* @0x22c834 ldr r6, [sp, #0x20] */
/* @0x22c838 add r1, r2, r3 */
/* @0x22c83c str r1, [r12, #0x1c] */
/* @0x22c840 ldr r5, [r9, #0x4] */
/* @0x22c844 rsb r2, r3, r2 */
/* @0x22c848 ldr r3, [r9] */
/* @0x22c84c add r6, r9, r6 */
/* @0x22c850 ldr r7, [sp, #0x38] */
/* @0x22c854 smull r0, r1, r2, r5 */
/* @0x22c858 str r6, [sp, #0xa8] */
/* @0x22c85c add r7, r7, r9 */
/* @0x22c860 str r7, [sp, #0x2c] */
/* @0x22c864 smull r6, r7, r4, r5 */
/* @0x22c868 ldr r6, [sp, #0x20] */
/* @0x22c86c smull r4, r5, r4, r3 */
/* @0x22c870 strd r0, r1, [sp, #24] */
/* @0x22c874 smull r2, r3, r3, r2 */
/* @0x22c878 ldr r0, [sp, #0x1c] */
/* @0x22c87c lsl r2, r7, #1 */
/* @0x22c880 ldr r1, [r8, #0x10] */
/* @0x22c884 lsl r4, r0, #1 */
/* @0x22c888 add r4, r4, r5, lsl #1 */
/* @0x22c88c str r4, [r8, #0x18] */
/* @0x22c890 ldr r4, [sp, #0x40] */
/* @0x22c894 rsb r2, r2, r3, lsl #1 */
/* @0x22c898 str r2, [r8, #0x1c] */
/* @0x22c89c add r4, r4, r9 */
/* @0x22c8a0 str r4, [sp, #0x18] */
/* @0x22c8a4 ldr r4, [r12, #0x10] */
/* @0x22c8a8 ldr r5, [sp, #0xa8] */
/* @0x22c8ac ldr r3, [r12, #0x14] */
/* @0x22c8b0 add r2, r1, r4 */
/* @0x22c8b4 str r2, [r12, #0x10] */
/* @0x22c8b8 rsb r1, r4, r1 */
/* @0x22c8bc ldr r2, [r8, #0x14] */
/* @0x22c8c0 add r4, r2, r3 */
/* @0x22c8c4 str r4, [r12, #0x14] */
/* @0x22c8c8 ldr r4, [r5, #0x4] */
/* @0x22c8cc rsb r2, r3, r2 */
/* @0x22c8d0 ldr r3, [r9, r6] */
/* @0x22c8d4 smull r6, r7, r2, r4 */
/* @0x22c8d8 ldr r6, [r8, #0x8] */
/* @0x22c8dc smull r4, r5, r1, r4 */
/* @0x22c8e0 smull r0, r1, r1, r3 */
/* @0x22c8e4 lsl r0, r7, #1 */
/* @0x22c8e8 smull r2, r3, r3, r2 */
/* @0x22c8ec lsl r2, r5, #1 */
/* @0x22c8f0 add r0, r0, r1, lsl #1 */
/* @0x22c8f4 str r0, [r8, #0x10] */
/* @0x22c8f8 rsb r2, r2, r3, lsl #1 */
/* @0x22c8fc str r2, [r8, #0x14] */
/* @0x22c900 ldr r0, [r12, #0x8] */
/* @0x22c904 ldr r3, [r12, #0xc] */
/* @0x22c908 add r2, r6, r0 */
/* @0x22c90c str r2, [r12, #0x8] */
/* @0x22c910 ldr r2, [r8, #0xc] */
/* @0x22c914 rsb r0, r0, r6 */
/* @0x22c918 ldr r7, [sp, #0x2c] */
/* @0x22c91c add r1, r2, r3 */
/* @0x22c920 str r1, [r12, #0xc] */
/* @0x22c924 ldr r1, [sp, #0x38] */
/* @0x22c928 rsb r2, r3, r2 */
/* @0x22c92c ldr r4, [r7, #0x4] */
/* @0x22c930 ldr r3, [r1, r9] */
/* @0x22c934 smull r6, r7, r2, r4 */
/* @0x22c938 ldr r6, [sp, #0x40] */
/* @0x22c93c smull r4, r5, r0, r4 */
/* @0x22c940 smull r0, r1, r0, r3 */
/* @0x22c944 lsl r0, r7, #1 */
/* @0x22c948 smull r2, r3, r3, r2 */
/* @0x22c94c lsl r2, r5, #1 */
/* @0x22c950 ldr r5, [sp, #0x18] */
/* @0x22c954 add r0, r0, r1, lsl #1 */
/* @0x22c958 str r0, [r8, #0x8] */
/* @0x22c95c ldr r7, [sp, #0x4c] */
/* @0x22c960 rsb r2, r2, r3, lsl #1 */
/* @0x22c964 str r2, [r8, #0xc] */
/* @0x22c968 ldr r3, [r11, #0x40] */
/* @0x22c96c ldr r0, [r10, #0x40] */
/* @0x22c970 add r2, r0, r3 */
/* @0x22c974 rsb r0, r3, r0 */
/* @0x22c978 str r2, [r11, #0x40] */
/* @0x22c97c ldr r3, [r12, #0x4] */
/* @0x22c980 ldr r2, [r8, #0x4] */
/* @0x22c984 add r1, r2, r3 */
/* @0x22c988 str r1, [r12, #0x4] */
/* @0x22c98c ldr r4, [r5, #0x4] */
/* @0x22c990 rsb r2, r3, r2 */
/* @0x22c994 ldr r3, [r6, r9] */
/* @0x22c998 add r9, r7, r9 */
/* @0x22c99c ldr r12, [sp, #0x5c] */
/* @0x22c9a0 smull r6, r7, r2, r4 */
/* @0x22c9a4 cmp r9, r12 */
/* @0x22c9a8 smull r4, r5, r0, r4 */
/* @0x22c9ac ldr r12, [sp, #0x10] */
/* @0x22c9b0 smull r0, r1, r0, r3 */
/* @0x22c9b4 lsl r0, r7, #1 */
/* @0x22c9b8 smull r2, r3, r3, r2 */
/* @0x22c9bc lsl r2, r5, #1 */
/* @0x22c9c0 add r0, r0, r1, lsl #1 */
/* @0x22c9c4 str r0, [r10, #0x40] */
/* @0x22c9c8 rsb r2, r2, r3, lsl #1 */
/* @0x22c9cc str r2, [r8, #0x4] */
/* @0x22c9d0 ldr r8, [sp, #0x28] */
/* @0x22c9d4 blo 0x22c800 <mdct_backward+0x884> */
/* @0x22c9d8 ldr r2, [sp, #0x10] */
/* @0x22c9dc ldr r3, [sp, #0x28] */
/* @0x22c9e0 sub r2, r2, #32 */
/* @0x22c9e4 str r2, [sp, #0x10] */
/* @0x22c9e8 sub r3, r3, #32 */
/* @0x22c9ec str r3, [sp, #0x28] */
/* @0x22c9f0 mov r11, r2 */
/* @0x22c9f4 mov r10, r3 */
/* @0x22c9f8 ldr r1, [r8, #0x18] */
/* @0x22c9fc sub r11, r11, #32 */
/* @0x22ca00 ldr r0, [r12, #0x18] */
/* @0x22ca04 sub r10, r10, #32 */
/* @0x22ca08 ldr r4, [sp, #0x20] */
/* @0x22ca0c ldr r2, [r12, #0x1c] */
/* @0x22ca10 rsb r3, r4, r9 */
/* @0x22ca14 add r4, r0, r1 */
/* @0x22ca18 str r4, [r12, #0x18] */
/* @0x22ca1c rsb r0, r1, r0 */
/* @0x22ca20 ldr r4, [r8, #0x1c] */
/* @0x22ca24 ldr r6, [sp, #0x30] */
/* @0x22ca28 add r1, r4, r2 */
/* @0x22ca2c str r1, [r12, #0x1c] */
/* @0x22ca30 ldr r1, [r9, #0x4] */
/* @0x22ca34 add r6, r6, r9 */
/* @0x22ca38 str r6, [sp, #0x2c] */
/* @0x22ca3c rsb r4, r2, r4 */
/* @0x22ca40 ldr r5, [r9] */
/* @0x22ca44 smull r6, r7, r0, r1 */
/* @0x22ca48 ldr r2, [r8, #0x10] */
/* @0x22ca4c strd r6, r7, [sp, #24] */
/* @0x22ca50 smull r6, r7, r4, r1 */
/* @0x22ca54 smull r0, r1, r5, r0 */
/* @0x22ca58 strd r6, r7, [sp, #192] */
/* @0x22ca5c smull r6, r7, r4, r5 */
/* @0x22ca60 ldr r4, [sp, #0xc4] */
/* @0x22ca64 lsl r0, r4, #1 */
/* @0x22ca68 add r0, r0, r1, lsl #1 */
/* @0x22ca6c str r0, [r8, #0x1c] */
/* @0x22ca70 strd r6, r7, [sp, #160] */
/* @0x22ca74 ldr r7, [sp, #0x1c] */
/* @0x22ca78 ldr r5, [sp, #0xa4] */
/* @0x22ca7c lsl r6, r7, #1 */
/* @0x22ca80 rsb r4, r6, r5, lsl #1 */
/* @0x22ca84 str r4, [r8, #0x18] */
/* @0x22ca88 ldr r4, [r12, #0x10] */
/* @0x22ca8c ldr r1, [r12, #0x14] */
/* @0x22ca90 add r0, r4, r2 */
/* @0x22ca94 str r0, [r12, #0x10] */
/* @0x22ca98 ldr r0, [r8, #0x14] */
/* @0x22ca9c rsb r2, r2, r4 */
/* @0x22caa0 ldr r6, [sp, #0x48] */
/* @0x22caa4 add r4, r0, r1 */
/* @0x22caa8 str r4, [r12, #0x14] */
/* @0x22caac ldr r4, [r3, #0x4] */
/* @0x22cab0 rsb r0, r1, r0 */
/* @0x22cab4 ldr r3, [r3] */
/* @0x22cab8 add r6, r6, r9 */
/* @0x22cabc str r6, [sp, #0x18] */
/* @0x22cac0 smull r6, r7, r2, r4 */
/* @0x22cac4 ldr r6, [r8, #0x8] */
/* @0x22cac8 smull r4, r5, r0, r4 */
/* @0x22cacc smull r0, r1, r0, r3 */
/* @0x22cad0 lsl r0, r7, #1 */
/* @0x22cad4 smull r2, r3, r3, r2 */
/* @0x22cad8 lsl r2, r5, #1 */
/* @0x22cadc rsb r0, r0, r1, lsl #1 */
/* @0x22cae0 str r0, [r8, #0x10] */
/* @0x22cae4 add r2, r2, r3, lsl #1 */
/* @0x22cae8 str r2, [r8, #0x14] */
/* @0x22caec ldr r2, [r12, #0x8] */
/* @0x22caf0 ldr r3, [r12, #0xc] */
/* @0x22caf4 add r1, r2, r6 */
/* @0x22caf8 str r1, [r12, #0x8] */
/* @0x22cafc ldr r0, [r8, #0xc] */
/* @0x22cb00 rsb r2, r6, r2 */
/* @0x22cb04 ldr r7, [sp, #0x2c] */
/* @0x22cb08 add r1, r0, r3 */
/* @0x22cb0c str r1, [r12, #0xc] */
/* @0x22cb10 ldr r1, [sp, #0x30] */
/* @0x22cb14 rsb r0, r3, r0 */
/* @0x22cb18 ldr r4, [r7, #0x4] */
/* @0x22cb1c ldr r3, [r1, r9] */
/* @0x22cb20 smull r6, r7, r2, r4 */
/* @0x22cb24 ldr r6, [sp, #0x48] */
/* @0x22cb28 smull r4, r5, r0, r4 */
/* @0x22cb2c smull r0, r1, r0, r3 */
/* @0x22cb30 lsl r0, r7, #1 */
/* @0x22cb34 smull r2, r3, r3, r2 */
/* @0x22cb38 lsl r2, r5, #1 */
/* @0x22cb3c ldr r5, [sp, #0x18] */
/* @0x22cb40 rsb r0, r0, r1, lsl #1 */
/* @0x22cb44 str r0, [r8, #0x8] */
/* @0x22cb48 ldr r7, [sp, #0x50] */
/* @0x22cb4c add r2, r2, r3, lsl #1 */
/* @0x22cb50 str r2, [r8, #0xc] */
/* @0x22cb54 ldr r0, [r11, #0x40] */
/* @0x22cb58 ldr r3, [r10, #0x40] */
/* @0x22cb5c add r2, r0, r3 */
/* @0x22cb60 rsb r0, r3, r0 */
/* @0x22cb64 str r2, [r11, #0x40] */
/* @0x22cb68 ldr r3, [r12, #0x4] */
/* @0x22cb6c ldr r2, [r8, #0x4] */
/* @0x22cb70 add r1, r2, r3 */
/* @0x22cb74 str r1, [r12, #0x4] */
/* @0x22cb78 ldr r12, [sp, #0x60] */
/* @0x22cb7c rsb r2, r3, r2 */
/* @0x22cb80 ldr r4, [r5, #0x4] */
/* @0x22cb84 ldr r3, [r6, r9] */
/* @0x22cb88 add r9, r7, r9 */
/* @0x22cb8c cmp r9, r12 */
/* @0x22cb90 ldr r12, [sp, #0x10] */
/* @0x22cb94 smull r6, r7, r2, r4 */
/* @0x22cb98 sub r1, r12, #32 */
/* @0x22cb9c smull r4, r5, r0, r4 */
/* @0x22cba0 str r1, [sp, #0x10] */
/* @0x22cba4 smull r0, r1, r3, r0 */
/* @0x22cba8 lsl r0, r7, #1 */
/* @0x22cbac smull r2, r3, r2, r3 */
/* @0x22cbb0 lsl r2, r5, #1 */
/* @0x22cbb4 add r0, r0, r1, lsl #1 */
/* @0x22cbb8 rsb r2, r2, r3, lsl #1 */
/* @0x22cbbc str r2, [r10, #0x40] */
/* @0x22cbc0 str r0, [r8, #0x4] */
/* @0x22cbc4 ldr r8, [sp, #0x28] */
/* @0x22cbc8 sub r2, r8, #32 */
/* @0x22cbcc str r2, [sp, #0x28] */
/* @0x22cbd0 bhi 0x22c9f8 <mdct_backward+0xa7c> */
/* @0x22cbd4 ldr r3, [sp, #0x78] */
/* @0x22cbd8 ldr r6, [sp, #0x70] */
/* @0x22cbdc add r3, r3, #1 */
/* @0x22cbe0 ldr r4, [sp, #0x64] */
/* @0x22cbe4 ldr r5, [sp, #0x7c] */
/* @0x22cbe8 cmp r3, r6 */
/* @0x22cbec str r3, [sp, #0x78] */
/* @0x22cbf0 add r4, r4, r5 */
/* @0x22cbf4 str r4, [sp, #0x64] */
/* @0x22cbf8 bne 0x22c3d0 <mdct_backward+0x454> */
/* @0x22cbfc ldr r7, [sp, #0x98] */
/* @0x22cc00 ldr r8, [sp, #0x90] */
/* @0x22cc04 add r7, r7, #1 */
/* @0x22cc08 str r7, [sp, #0x98] */
/* @0x22cc0c cmp r7, r8 */
/* @0x22cc10 bne 0x22c328 <mdct_backward+0x3ac> */
/* @0x22cc14 ldr r1, [sp, #0x88] */
/* @0x22cc18 cmp r1, #0 */
/* @0x22cc1c ble 0x22d47c <mdct_backward+0x1500> */
/* @0x22cc20 ldr r4, [sp, #0x88] */
/* @0x22cc24 movw r5, #0xaf3d */
/* @0x22cc28 movw r6, #0xc54d */
/* @0x22cc2c movt r5, #0x7641 */
/* @0x22cc30 sub r3, r4, #1 */
/* @0x22cc34 movt r6, #0x30fb */
/* @0x22cc38 movw r7, #0x799a */
/* @0x22cc3c mov r8, #0 */
/* @0x22cc40 lsr r3, r3, #5 */
/* @0x22cc44 movt r7, #0x5a82 */
/* @0x22cc48 add r3, r3, #1 */
/* @0x22cc4c str r5, [sp, #0x28] */
/* @0x22cc50 str r6, [sp, #0x20] */
/* @0x22cc54 lsl r3, r3, #7 */
/* @0x22cc58 str r7, [sp, #0x10] */
/* @0x22cc5c str r8, [sp, #0x38] */
/* @0x22cc60 str r3, [sp, #0xf0] */
/* @0x22cc64 ldr r9, [sp, #0xbc] */
/* @0x22cc68 ldr r10, [sp, #0x38] */
/* @0x22cc6c add r12, r9, r10 */
/* @0x22cc70 ldr r11, [r9, r10] */
/* @0x22cc74 ldr r0, [r12, #0x70] */
/* @0x22cc78 ldr r3, [r12, #0x30] */
/* @0x22cc7c ldr r1, [r12, #0x74] */
/* @0x22cc80 rsb r4, r3, r0 */
/* @0x22cc84 ldr r2, [r12, #0x34] */
/* @0x22cc88 str r4, [sp, #0x30] */
/* @0x22cc8c add r3, r0, r3 */
/* @0x22cc90 ldr r4, [r12, #0x10] */
/* @0x22cc94 rsb r9, r2, r1 */
/* @0x22cc98 str r3, [sp, #0x40] */
/* @0x22cc9c add r2, r1, r2 */
/* @0x22cca0 ldr r3, [r12, #0x50] */
/* @0x22cca4 str r2, [sp, #0x48] */
/* @0x22cca8 rsb r7, r3, r4 */
/* @0x22ccac ldr r2, [r12, #0x60] */
/* @0x22ccb0 add r3, r4, r3 */
/* @0x22ccb4 str r3, [sp, #0x60] */
/* @0x22ccb8 ldr r3, [r12, #0x20] */
/* @0x22ccbc ldr r0, [r12, #0x14] */
/* @0x22ccc0 rsb r4, r3, r2 */
/* @0x22ccc4 add r3, r2, r3 */
/* @0x22ccc8 ldr r2, [sp, #0x20] */
/* @0x22cccc str r3, [sp, #0x54] */
/* @0x22ccd0 ldr r3, [sp, #0x30] */
/* @0x22ccd4 ldr r1, [r12, #0x54] */
/* @0x22ccd8 ldr r5, [r12, #0x64] */
/* @0x22ccdc smull r2, r3, r3, r2 */
/* @0x22cce0 ldr r10, [r12, #0x24] */
/* @0x22cce4 rsb r8, r1, r0 */
/* @0x22cce8 add r1, r0, r1 */
/* @0x22ccec rsb r6, r10, r5 */
/* @0x22ccf0 ldr r0, [r12, #0x40] */
/* @0x22ccf4 ldr r10, [r12, #0x44] */
/* @0x22ccf8 str r11, [sp, #0xc] */
/* @0x22ccfc rsb r11, r0, r11 */
/* @0x22cd00 strd r2, r3, [sp, #24] */
/* @0x22cd04 ldr r3, [r12, #0x4] */
/* @0x22cd08 ldr r2, [sp, #0x20] */
/* @0x22cd0c rsb r5, r10, r3 */
/* @0x22cd10 str r11, [sp, #0x78] */
/* @0x22cd14 ldr r3, [sp, #0x28] */
/* @0x22cd18 ldr r11, [sp, #0x28] */
/* @0x22cd1c str r1, [sp, #0x64] */
/* @0x22cd20 smull r0, r1, r7, r11 */
/* @0x22cd24 smull r10, r11, r9, r2 */
/* @0x22cd28 smull r2, r3, r8, r3 */
/* @0x22cd2c strd r2, r3, [sp, #136] */
/* @0x22cd30 ldr r3, [sp, #0x28] */
/* @0x22cd34 smull r2, r3, r4, r3 */
/* @0x22cd38 strd r2, r3, [sp, #104] */
/* @0x22cd3c ldr r3, [sp, #0x78] */
/* @0x22cd40 ldr r2, [sp, #0x20] */
/* @0x22cd44 smull r2, r3, r3, r2 */
/* @0x22cd48 strd r2, r3, [sp, #144] */
/* @0x22cd4c ldr r3, [sp, #0x1c] */
/* @0x22cd50 lsl r10, r3, #1 */
/* @0x22cd54 ldr r3, [sp, #0x28] */
/* @0x22cd58 smull r2, r3, r9, r3 */
/* @0x22cd5c lsl r9, r1, #1 */
/* @0x22cd60 str r9, [sp, #0x2c] */
/* @0x22cd64 ldr r9, [sp, #0x8c] */
/* @0x22cd68 strd r2, r3, [sp, #112] */
/* @0x22cd6c ldr r2, [sp, #0x28] */
/* @0x22cd70 ldr r3, [sp, #0x20] */
/* @0x22cd74 smull r0, r1, r6, r2 */
/* @0x22cd78 lsl r0, r11, #1 */
/* @0x22cd7c smull r2, r3, r5, r3 */
/* @0x22cd80 lsl r11, r9, #1 */
/* @0x22cd84 ldr r9, [sp, #0x20] */
/* @0x22cd88 lsl r1, r1, #1 */
/* @0x22cd8c strd r2, r3, [sp, #160] */
/* @0x22cd90 ldr r3, [sp, #0x20] */
/* @0x22cd94 smull r2, r3, r8, r3 */
/* @0x22cd98 ldr r8, [sp, #0x6c] */
/* @0x22cd9c lsl r8, r8, #1 */
/* @0x22cda0 str r8, [sp, #0x18] */
/* @0x22cda4 smull r8, r9, r7, r9 */
/* @0x22cda8 strd r2, r3, [sp, #136] */
/* @0x22cdac ldr r3, [sp, #0x30] */
/* @0x22cdb0 ldr r2, [sp, #0x28] */
/* @0x22cdb4 smull r2, r3, r3, r2 */
/* @0x22cdb8 strd r8, r9, [sp, #104] */
/* @0x22cdbc ldr r8, [sp, #0xa4] */
/* @0x22cdc0 ldr r9, [sp, #0x28] */
/* @0x22cdc4 strd r2, r3, [sp, #48] */
/* @0x22cdc8 ldr r3, [sp, #0x94] */
/* @0x22cdcc ldr r2, [sp, #0x20] */
/* @0x22cdd0 lsl r3, r3, #1 */
/* @0x22cdd4 str r3, [sp, #0x4c] */
/* @0x22cdd8 lsl r3, r8, #1 */
/* @0x22cddc smull r8, r9, r5, r9 */
/* @0x22cde0 smull r6, r7, r6, r2 */
/* @0x22cde4 ldr r2, [sp, #0x74] */
/* @0x22cde8 strd r8, r9, [sp, #144] */
/* @0x22cdec add r10, r10, r2, lsl #1 */
/* @0x22cdf0 ldr r8, [sp, #0x20] */
/* @0x22cdf4 ldr r2, [sp, #0x8c] */
/* @0x22cdf8 ldr r9, [sp, #0x2c] */
/* @0x22cdfc smull r4, r5, r4, r8 */
/* @0x22ce00 rsb r9, r9, r2, lsl #1 */
/* @0x22ce04 ldr r8, [sp, #0x28] */
/* @0x22ce08 str r9, [sp, #0xb0] */
/* @0x22ce0c ldr r9, [sp, #0x78] */
/* @0x22ce10 rsb r1, r1, r5, lsl #1 */
/* @0x22ce14 smull r8, r9, r9, r8 */
/* @0x22ce18 strd r8, r9, [sp, #160] */
/* @0x22ce1c ldr r9, [sp, #0x34] */
/* @0x22ce20 ldr r2, [sp, #0x18] */
/* @0x22ce24 ldr r8, [sp, #0xa4] */
/* @0x22ce28 rsb r0, r0, r9, lsl #1 */
/* @0x22ce2c str r0, [sp, #0x88] */
/* @0x22ce30 ldr r0, [sp, #0x6c] */
/* @0x22ce34 add r2, r2, r7, lsl #1 */
/* @0x22ce38 ldr r7, [sp, #0x94] */
/* @0x22ce3c add r3, r3, r8, lsl #1 */
/* @0x22ce40 ldr r6, [sp, #0x4c] */
/* @0x22ce44 add r11, r11, r0, lsl #1 */
/* @0x22ce48 str r1, [sp, #0x90] */
/* @0x22ce4c ldr r0, [r12, #0x68] */
/* @0x22ce50 ldr r1, [r12, #0x28] */
/* @0x22ce54 str r11, [sp, #0xa8] */
/* @0x22ce58 rsb r11, r6, r7, lsl #1 */
/* @0x22ce5c rsb r9, r1, r0 */
/* @0x22ce60 str r2, [sp, #0xac] */
/* @0x22ce64 str r3, [sp, #0xa0] */
/* @0x22ce68 ldr r2, [r12, #0x6c] */
/* @0x22ce6c ldr r3, [r12, #0x2c] */
/* @0x22ce70 ldr r4, [r12, #0x8] */
/* @0x22ce74 ldr r5, [r12, #0x48] */
/* @0x22ce78 rsb r8, r3, r2 */
/* @0x22ce7c ldr r6, [r12, #0xc] */
/* @0x22ce80 ldr r7, [r12, #0x4c] */
/* @0x22ce84 rsb r0, r5, r4 */
/* @0x22ce88 ldr r1, [sp, #0xb0] */
/* @0x22ce8c rsb r2, r7, r6 */
/* @0x22ce90 ldr r3, [sp, #0x88] */
/* @0x22ce94 rsb r5, r1, r10 */
/* @0x22ce98 ldr r4, [sp, #0xa8] */
/* @0x22ce9c ldr r1, [r12, #0x24] */
/* @0x22cea0 ldr r6, [r12, #0x64] */
/* @0x22cea4 rsb r7, r4, r3 */
/* @0x22cea8 ldr r4, [sp, #0xac] */
/* @0x22ceac add r6, r6, r1 */
/* @0x22ceb0 ldr r1, [r12, #0x40] */
/* @0x22ceb4 str r6, [sp, #0x58] */
/* @0x22ceb8 rsb r3, r4, r11 */
/* @0x22cebc ldr r6, [sp, #0xc] */
/* @0x22cec0 ldr r4, [sp, #0xa0] */
/* @0x22cec4 add r6, r6, r1 */
/* @0x22cec8 str r6, [sp, #0x7c] */
/* @0x22cecc ldr r6, [sp, #0x90] */
/* @0x22ced0 rsb r1, r6, r4 */
/* @0x22ced4 ldr r6, [r12, #0x44] */
/* @0x22ced8 ldr r4, [r12, #0x4] */
/* @0x22cedc add r4, r4, r6 */
/* @0x22cee0 add r6, r9, r8 */
/* @0x22cee4 str r4, [sp, #0x80] */
/* @0x22cee8 rsb r8, r8, r9 */
/* @0x22ceec str r8, [sp, #0x18] */
/* @0x22cef0 rsb r4, r0, r2 */
/* @0x22cef4 ldr r8, [sp, #0x10] */
/* @0x22cef8 add r2, r0, r2 */
/* @0x22cefc add r0, r7, r5 */
/* @0x22cf00 rsb r5, r5, r7 */
/* @0x22cf04 ldr r9, [sp, #0x7c] */
/* @0x22cf08 smull r6, r7, r6, r8 */
/* @0x22cf0c str r2, [sp, #0x98] */
/* @0x22cf10 str r5, [sp, #0xb8] */
/* @0x22cf14 rsb r2, r1, r3 */
/* @0x22cf18 smull r4, r5, r4, r8 */
/* @0x22cf1c add r3, r1, r3 */
/* @0x22cf20 ldr r8, [sp, #0x58] */
/* @0x22cf24 lsl r4, r7, #1 */
/* @0x22cf28 ldr r1, [sp, #0x54] */
/* @0x22cf2c str r3, [sp, #0xb4] */
/* @0x22cf30 ldr r3, [sp, #0x80] */
/* @0x22cf34 rsb r6, r1, r9 */
/* @0x22cf38 ldr r7, [sp, #0x40] */
/* @0x22cf3c rsb r9, r8, r3 */
/* @0x22cf40 ldr r3, [sp, #0x10] */
/* @0x22cf44 ldr r8, [sp, #0x60] */
/* @0x22cf48 smull r0, r1, r0, r3 */
/* @0x22cf4c lsl r0, r5, #1 */
/* @0x22cf50 smull r2, r3, r2, r3 */
/* @0x22cf54 rsb r5, r8, r7 */
/* @0x22cf58 ldr r7, [sp, #0x48] */
/* @0x22cf5c ldr r8, [sp, #0x64] */
/* @0x22cf60 rsb r2, r8, r7 */
/* @0x22cf64 rsb r8, r6, r9 */
/* @0x22cf68 add r9, r6, r9 */
/* @0x22cf6c str r8, [sp, #0xd8] */
/* @0x22cf70 str r9, [sp, #0xc0] */
/* @0x22cf74 add r9, r5, r2 */
/* @0x22cf78 ldr r8, [sp, #0x18] */
/* @0x22cf7c lsl r7, r1, #1 */
/* @0x22cf80 str r9, [sp, #0xe0] */
/* @0x22cf84 rsb r2, r2, r5 */
/* @0x22cf88 ldr r9, [sp, #0x10] */
/* @0x22cf8c lsl r6, r3, #1 */
/* @0x22cf90 ldr r5, [r12, #0x28] */
/* @0x22cf94 ldr r3, [r12, #0x2c] */
/* @0x22cf98 str r2, [sp, #0xdc] */
/* @0x22cf9c ldr r1, [r12, #0x68] */
/* @0x22cfa0 ldr r2, [r12, #0x6c] */
/* @0x22cfa4 add r1, r1, r5 */
/* @0x22cfa8 str r7, [sp, #0xd0] */
/* @0x22cfac add r2, r2, r3 */
/* @0x22cfb0 str r6, [sp, #0x84] */
/* @0x22cfb4 ldr r3, [r12, #0x4c] */
/* @0x22cfb8 smull r6, r7, r8, r9 */
/* @0x22cfbc ldr r5, [r12, #0x8] */
/* @0x22cfc0 ldr r8, [r12, #0x48] */
/* @0x22cfc4 ldr r9, [r12, #0xc] */
/* @0x22cfc8 ldr r6, [r12, #0x38] */
/* @0x22cfcc add r5, r5, r8 */
/* @0x22cfd0 add r9, r9, r3 */
/* @0x22cfd4 str r1, [sp, #0x4c] */
/* @0x22cfd8 str r2, [sp, #0x50] */
/* @0x22cfdc lsl r8, r7, #1 */
/* @0x22cfe0 ldr r1, [r12, #0x78] */
/* @0x22cfe4 ldr r2, [r12, #0x1c] */
/* @0x22cfe8 str r5, [sp, #0x5c] */
/* @0x22cfec str r9, [sp, #0x78] */
/* @0x22cff0 rsb r9, r4, r0 */
/* @0x22cff4 ldr r5, [sp, #0xb0] */
/* @0x22cff8 add r0, r4, r0 */
/* @0x22cffc ldr r3, [r12, #0x5c] */
/* @0x22d000 add r10, r10, r5 */
/* @0x22d004 rsb r5, r6, r1 */
/* @0x22d008 str r10, [sp, #0xb0] */
/* @0x22d00c add r6, r1, r6 */
/* @0x22d010 ldr r10, [sp, #0x98] */
/* @0x22d014 rsb r1, r3, r2 */
/* @0x22d018 str r6, [sp, #0x30] */
/* @0x22d01c add r3, r2, r3 */
/* @0x22d020 ldr r6, [sp, #0x10] */
/* @0x22d024 str r3, [sp, #0x2c] */
/* @0x22d028 ldr r7, [sp, #0x88] */
/* @0x22d02c smull r2, r3, r10, r6 */
/* @0x22d030 ldr r10, [sp, #0xac] */
/* @0x22d034 ldr r6, [sp, #0xa0] */
/* @0x22d038 add r11, r10, r11 */
/* @0x22d03c str r8, [sp, #0x18] */
/* @0x22d040 str r11, [sp, #0x68] */
/* @0x22d044 ldr r8, [sp, #0xa8] */
/* @0x22d048 ldr r11, [sp, #0x90] */
/* @0x22d04c add r7, r7, r8 */
/* @0x22d050 ldr r8, [sp, #0xd0] */
/* @0x22d054 add r11, r11, r6 */
/* @0x22d058 str r11, [sp, #0x70] */
/* @0x22d05c ldr r11, [sp, #0x84] */
/* @0x22d060 ldr r2, [sp, #0xb4] */
/* @0x22d064 rsb r8, r11, r8 */
/* @0x22d068 lsl r11, r3, #1 */
/* @0x22d06c ldr r3, [sp, #0x10] */
/* @0x22d070 str r7, [sp, #0x88] */
/* @0x22d074 rsb r7, r1, r5 */
/* @0x22d078 str r0, [sp, #0x98] */
/* @0x22d07c add r1, r5, r1 */
/* @0x22d080 str r1, [sp, #0x90] */
/* @0x22d084 smull r0, r1, r2, r3 */
/* @0x22d088 ldr r3, [sp, #0xb8] */
/* @0x22d08c ldr r2, [sp, #0x10] */
/* @0x22d090 ldr r5, [sp, #0x7c] */
/* @0x22d094 ldr r4, [sp, #0x54] */
/* @0x22d098 smull r2, r3, r3, r2 */
/* @0x22d09c add r4, r4, r5 */
/* @0x22d0a0 str r4, [sp, #0x7c] */
/* @0x22d0a4 ldr r4, [sp, #0x80] */
/* @0x22d0a8 ldr r10, [r12, #0x7c] */
/* @0x22d0ac ldr r6, [r12, #0x3c] */
/* @0x22d0b0 strd r2, r3, [sp, #160] */
/* @0x22d0b4 ldr r3, [sp, #0x58] */
/* @0x22d0b8 str r8, [sp, #0xac] */
/* @0x22d0bc add r3, r3, r4 */
/* @0x22d0c0 ldr r8, [r12, #0x58] */
/* @0x22d0c4 str r3, [sp, #0x80] */
/* @0x22d0c8 ldr r3, [sp, #0x10] */
/* @0x22d0cc ldr r2, [sp, #0xd8] */
/* @0x22d0d0 smull r4, r5, r2, r3 */
/* @0x22d0d4 lsl r2, r1, #1 */
/* @0x22d0d8 ldr r1, [sp, #0xe0] */
/* @0x22d0dc str r2, [sp, #0xd8] */
/* @0x22d0e0 smull r0, r1, r1, r3 */
/* @0x22d0e4 strd r0, r1, [sp] */
/* @0x22d0e8 ldr r0, [sp, #0xc0] */
/* @0x22d0ec ldr r1, [sp, #0xa4] */
/* @0x22d0f0 lsl r1, r1, #1 */
/* @0x22d0f4 str r1, [sp, #0x54] */
/* @0x22d0f8 mov r1, r3 */
/* @0x22d0fc smull r2, r3, r0, r3 */
/* @0x22d100 lsl r0, r5, #1 */
/* @0x22d104 str r0, [sp, #0xa8] */
/* @0x22d108 ldr r0, [sp, #0xdc] */
/* @0x22d10c ldr r2, [sp, #0xd0] */
/* @0x22d110 smull r4, r5, r0, r1 */
/* @0x22d114 ldr r0, [sp, #0x60] */
/* @0x22d118 ldr r1, [sp, #0x40] */
/* @0x22d11c ldr r4, [sp, #0x18] */
/* @0x22d120 add r1, r1, r0 */
/* @0x22d124 ldr r0, [sp, #0x64] */
/* @0x22d128 str r1, [sp, #0xa0] */
/* @0x22d12c ldr r1, [sp, #0x48] */
/* @0x22d130 add r1, r1, r0 */
/* @0x22d134 str r1, [sp, #0xb4] */
/* @0x22d138 ldr r1, [sp, #0x4] */
/* @0x22d13c lsl r0, r3, #1 */
/* @0x22d140 str r0, [sp, #0x64] */
/* @0x22d144 rsb r0, r9, r7 */
/* @0x22d148 add r7, r9, r7 */
/* @0x22d14c ldr r9, [sp, #0xbc] */
/* @0x22d150 lsl r1, r1, #1 */
/* @0x22d154 str r1, [sp, #0xb8] */
/* @0x22d158 ldr r1, [sp, #0x84] */
/* @0x22d15c str r7, [sp, #0x58] */
/* @0x22d160 add r1, r1, r2 */
/* @0x22d164 ldr r7, [sp, #0x38] */
/* @0x22d168 str r1, [sp, #0x48] */
/* @0x22d16c ldr r1, [sp, #0xac] */
/* @0x22d170 str r0, [sp, #0x60] */
/* @0x22d174 add r2, r1, r0 */
/* @0x22d178 ldr r0, [sp, #0xf0] */
/* @0x22d17c ldr r3, [r12, #0x18] */
/* @0x22d180 lsl r1, r5, #1 */
/* @0x22d184 str r2, [r9, r7] */
/* @0x22d188 add r7, r7, #128 */
/* @0x22d18c ldr r5, [sp, #0x78] */
/* @0x22d190 cmp r7, r0 */
/* @0x22d194 ldr r0, [sp, #0x50] */
/* @0x22d198 rsb r2, r6, r10 */
/* @0x22d19c rsb r9, r3, r8 */
/* @0x22d1a0 str r7, [sp, #0x38] */
/* @0x22d1a4 add r3, r8, r3 */
/* @0x22d1a8 str r1, [sp, #0x84] */
/* @0x22d1ac rsb r8, r9, r2 */
/* @0x22d1b0 add r1, r0, r5 */
/* @0x22d1b4 add r9, r2, r9 */
/* @0x22d1b8 str r1, [sp, #0x78] */
/* @0x22d1bc ldr r2, [sp, #0x30] */
/* @0x22d1c0 rsb r7, r0, r5 */
/* @0x22d1c4 add r6, r10, r6 */
/* @0x22d1c8 rsb r10, r11, r4 */
/* @0x22d1cc rsb r5, r3, r2 */
/* @0x22d1d0 add r11, r4, r11 */
/* @0x22d1d4 add r3, r2, r3 */
/* @0x22d1d8 ldr r4, [sp, #0x5c] */
/* @0x22d1dc str r3, [sp, #0xd0] */
/* @0x22d1e0 ldr r3, [sp, #0x4c] */
/* @0x22d1e4 rsb r0, r4, r3 */
/* @0x22d1e8 add r2, r3, r4 */
/* @0x22d1ec ldr r3, [sp, #0x2c] */
/* @0x22d1f0 ldr r4, [sp, #0x54] */
/* @0x22d1f4 rsb r1, r3, r6 */
/* @0x22d1f8 add r6, r6, r3 */
/* @0x22d1fc ldr r3, [sp, #0xd8] */
/* @0x22d200 rsb r4, r3, r4 */
/* @0x22d204 str r4, [sp, #0x40] */
/* @0x22d208 ldr r4, [sp, #0x54] */
/* @0x22d20c add r4, r3, r4 */
/* @0x22d210 str r4, [sp, #0x30] */
/* @0x22d214 rsb r4, r10, r8 */
/* @0x22d218 add r8, r10, r8 */
/* @0x22d21c ldr r10, [sp, #0x68] */
/* @0x22d220 str r8, [sp, #0xc0] */
/* @0x22d224 ldr r8, [sp, #0xb0] */
/* @0x22d228 ldr r3, [sp, #0xb0] */
/* @0x22d22c rsb r8, r10, r8 */
/* @0x22d230 str r8, [sp, #0x18] */
/* @0x22d234 ldr r8, [sp, #0x90] */
/* @0x22d238 add r3, r10, r3 */
/* @0x22d23c str r3, [sp, #0x50] */
/* @0x22d240 rsb r10, r11, r8 */
/* @0x22d244 ldr r3, [sp, #0x70] */
/* @0x22d248 add r11, r11, r8 */
/* @0x22d24c ldr r8, [sp, #0x88] */
/* @0x22d250 str r11, [sp, #0x2c] */
/* @0x22d254 ldr r11, [sp, #0x88] */
/* @0x22d258 add r8, r3, r8 */
/* @0x22d25c str r8, [sp, #0x4c] */
/* @0x22d260 rsb r11, r3, r11 */
/* @0x22d264 ldr r3, [sp, #0x98] */
/* @0x22d268 str r11, [sp, #0xb0] */
/* @0x22d26c ldr r11, [sp, #0x98] */
/* @0x22d270 ldr r8, [sp, #0xb8] */
/* @0x22d274 rsb r11, r11, r9 */
/* @0x22d278 add r9, r3, r9 */
/* @0x22d27c str r11, [sp, #0x54] */
/* @0x22d280 ldr r3, [sp, #0xb8] */
/* @0x22d284 ldr r11, [sp, #0xa8] */
/* @0x22d288 rsb r8, r11, r8 */
/* @0x22d28c add r3, r11, r3 */
/* @0x22d290 ldr r11, [sp, #0x84] */
/* @0x22d294 str r3, [sp, #0x70] */
/* @0x22d298 ldr r3, [sp, #0x64] */
/* @0x22d29c str r8, [sp, #0x68] */
/* @0x22d2a0 rsb r8, r7, r5 */
/* @0x22d2a4 add r5, r7, r5 */
/* @0x22d2a8 str r8, [sp, #0x88] */
/* @0x22d2ac add r7, r3, r11 */
/* @0x22d2b0 str r5, [sp, #0x98] */
/* @0x22d2b4 str r7, [sp, #0x5c] */
/* @0x22d2b8 rsb r5, r3, r11 */
/* @0x22d2bc rsb r7, r0, r1 */
/* @0x22d2c0 ldr r11, [sp, #0x80] */
/* @0x22d2c4 add r1, r0, r1 */
/* @0x22d2c8 ldr r8, [sp, #0xb4] */
/* @0x22d2cc ldr r0, [sp, #0xb4] */
/* @0x22d2d0 ldr r3, [sp, #0xd0] */
/* @0x22d2d4 rsb r8, r11, r8 */
/* @0x22d2d8 add r0, r11, r0 */
/* @0x22d2dc str r8, [sp, #0x90] */
/* @0x22d2e0 ldr r11, [sp, #0x7c] */
/* @0x22d2e4 ldr r8, [sp, #0xa0] */
/* @0x22d2e8 str r0, [sp, #0x84] */
/* @0x22d2ec rsb r0, r2, r3 */
/* @0x22d2f0 rsb r8, r11, r8 */
/* @0x22d2f4 add r2, r2, r3 */
/* @0x22d2f8 str r8, [sp, #0x80] */
/* @0x22d2fc str r2, [sp, #0xa8] */
/* @0x22d300 ldr r8, [sp, #0x78] */
/* @0x22d304 ldr r2, [sp, #0xa0] */
/* @0x22d308 ldr r3, [sp, #0x78] */
/* @0x22d30c add r2, r11, r2 */
/* @0x22d310 ldr r11, [sp, #0x60] */
/* @0x22d314 rsb r3, r3, r6 */
/* @0x22d318 str r2, [sp, #0x64] */
/* @0x22d31c add r6, r8, r6 */
/* @0x22d320 ldr r2, [sp, #0xac] */
/* @0x22d324 ldr r8, [sp, #0x40] */
/* @0x22d328 str r3, [sp, #0x7c] */
/* @0x22d32c rsb r3, r2, r11 */
/* @0x22d330 rsb r2, r8, r4 */
/* @0x22d334 ldr r11, [sp, #0x58] */
/* @0x22d338 add r4, r8, r4 */
/* @0x22d33c ldr r8, [sp, #0x30] */
/* @0x22d340 str r2, [r12, #0x4] */
/* @0x22d344 str r3, [r12, #0x8] */
/* @0x22d348 rsb r2, r8, r11 */
/* @0x22d34c add r3, r8, r11 */
/* @0x22d350 str r4, [r12, #0xc] */
/* @0x22d354 ldr r11, [sp, #0xc0] */
/* @0x22d358 ldr r4, [sp, #0x48] */
/* @0x22d35c str r2, [r12, #0x10] */
/* @0x22d360 add r8, r4, r11 */
/* @0x22d364 rsb r2, r4, r11 */
/* @0x22d368 ldr r11, [sp, #0x18] */
/* @0x22d36c ldr r4, [sp, #0xb0] */
/* @0x22d370 str r2, [r12, #0x14] */
/* @0x22d374 ldr r2, [sp, #0x54] */
/* @0x22d378 str r3, [r12, #0x18] */
/* @0x22d37c add r3, r11, r10 */
/* @0x22d380 str r8, [r12, #0x1c] */
/* @0x22d384 rsb r10, r11, r10 */
/* @0x22d388 str r3, [r12, #0x20] */
/* @0x22d38c add r11, r4, r2 */
/* @0x22d390 str r10, [r12, #0x28] */
/* @0x22d394 rsb r3, r4, r2 */
/* @0x22d398 ldr r8, [sp, #0x2c] */
/* @0x22d39c ldr r10, [sp, #0x4c] */
/* @0x22d3a0 str r11, [r12, #0x2c] */
/* @0x22d3a4 ldr r11, [sp, #0x50] */
/* @0x22d3a8 add r2, r10, r8 */
/* @0x22d3ac ldr r4, [sp, #0x88] */
/* @0x22d3b0 str r3, [r12, #0x24] */
/* @0x22d3b4 rsb r3, r10, r8 */
/* @0x22d3b8 str r2, [r12, #0x38] */
/* @0x22d3bc ldr r10, [sp, #0x5c] */
/* @0x22d3c0 ldr r2, [sp, #0x68] */
/* @0x22d3c4 str r3, [r12, #0x30] */
/* @0x22d3c8 rsb r3, r11, r9 */
/* @0x22d3cc add r9, r11, r9 */
/* @0x22d3d0 str r9, [r12, #0x3c] */
/* @0x22d3d4 ldr r9, [sp, #0x98] */
/* @0x22d3d8 ldr r11, [sp, #0x70] */
/* @0x22d3dc ldr r8, [sp, #0x64] */
/* @0x22d3e0 str r3, [r12, #0x34] */
/* @0x22d3e4 add r3, r2, r4 */
/* @0x22d3e8 rsb r2, r2, r4 */
/* @0x22d3ec str r3, [r12, #0x40] */
/* @0x22d3f0 ldr r4, [sp, #0x7c] */
/* @0x22d3f4 rsb r3, r5, r7 */
/* @0x22d3f8 str r2, [r12, #0x48] */
/* @0x22d3fc add r5, r5, r7 */
/* @0x22d400 add r2, r10, r9 */
/* @0x22d404 ldr r7, [sp, #0xa8] */
/* @0x22d408 str r3, [r12, #0x44] */
/* @0x22d40c rsb r3, r10, r9 */
/* @0x22d410 str r5, [r12, #0x4c] */
/* @0x22d414 ldr r9, [sp, #0x84] */
/* @0x22d418 ldr r5, [sp, #0x80] */
/* @0x22d41c str r2, [r12, #0x58] */
/* @0x22d420 ldr r2, [sp, #0x90] */
/* @0x22d424 str r3, [r12, #0x50] */
/* @0x22d428 rsb r3, r11, r1 */
/* @0x22d42c add r1, r11, r1 */
/* @0x22d430 str r3, [r12, #0x54] */
/* @0x22d434 str r1, [r12, #0x5c] */
/* @0x22d438 add r3, r2, r0 */
/* @0x22d43c rsb r0, r2, r0 */
/* @0x22d440 str r3, [r12, #0x60] */
/* @0x22d444 add r2, r5, r4 */
/* @0x22d448 rsb r3, r5, r4 */
/* @0x22d44c str r2, [r12, #0x6c] */
/* @0x22d450 add r2, r8, r7 */
/* @0x22d454 str r3, [r12, #0x64] */
/* @0x22d458 rsb r3, r8, r7 */
/* @0x22d45c str r0, [r12, #0x68] */
/* @0x22d460 str r3, [r12, #0x70] */
/* @0x22d464 rsb r3, r9, r6 */
/* @0x22d468 str r2, [r12, #0x78] */
/* @0x22d46c add r6, r9, r6 */
/* @0x22d470 str r3, [r12, #0x74] */
/* @0x22d474 str r6, [r12, #0x7c] */
/* @0x22d478 bne 0x22cc64 <mdct_backward+0xce8> */
/* @0x22d47c ldr r2, [sp, #0xf8] */
/* @0x22d480 cmp r2, #3 */
/* @0x22d484 ble 0x22daf0 <mdct_backward+0x1b74> */
/* @0x22d488 ldr r10, [sp, #0xf8] */
/* @0x22d48c ldr r3, [pc, #-0xca0] */
/* @0x22d490 asr r2, r10, #1 */
/* @0x22d494 add r3, pc, r3 */
/* @0x22d498 add r9, r3, r2, lsl #2 */
/* @0x22d49c ldr r11, [pc, #-0xcac] */
/* @0x22d4a0 add r12, r9, #4096 */
/* @0x22d4a4 ldr r10, [sp, #0xbc] */
/* @0x22d4a8 mov r0, #0 */
/* @0x22d4ac add r11, pc, r11 */
/* @0x22d4b0 str r11, [sp, #0x20] */
/* @0x22d4b4 ldr r11, [sp, #0xf4] */
/* @0x22d4b8 str r12, [sp, #0x48] */
/* @0x22d4bc mov r12, r10 */
/* @0x22d4c0 str r0, [sp, #0x10] */
/* @0x22d4c4 str r11, [sp, #0x28] */
/* @0x22d4c8 mov r11, r10 */
/* @0x22d4cc ldr r1, [sp, #0x10] */
/* @0x22d4d0 mov r7, r9 */
/* @0x22d4d4 ldr r4, [sp, #0x10] */
/* @0x22d4d8 sub r11, r11, #16 */
/* @0x22d4dc ldr r3, [sp, #0x20] */
/* @0x22d4e0 and r2, r1, #15 */
/* @0x22d4e4 ldr r5, [sp, #0x20] */
/* @0x22d4e8 ubfx r1, r1, #0x4, #0x4 */
/* @0x22d4ec add r2, r3, r2 */
/* @0x22d4f0 add r3, r3, r4, asr #8 */
/* @0x22d4f4 add r1, r5, r1 */
/* @0x22d4f8 ldr r6, [sp, #0xe4] */
/* @0x22d4fc ldrb r2, [r2, #0x10] */
/* @0x22d500 add r0, r4, #1 */
/* @0x22d504 ldrb r3, [r3, #0x10] */
/* @0x22d508 and r4, r0, #15 */
/* @0x22d50c ldrb r1, [r1, #0x10] */
/* @0x22d510 add r4, r5, r4 */
/* @0x22d514 orr r2, r3, r2, lsl #8 */
/* @0x22d518 ldr r10, [sp, #0x9c] */
/* @0x22d51c ldr r3, [r7], r6 */
/* @0x22d520 orr r2, r2, r1, lsl #4 */
/* @0x22d524 ldrb r6, [r4, #0x10] */
/* @0x22d528 eor r1, r2, #4080 */
/* @0x22d52c ldr r8, [sp, #0x10] */
/* @0x22d530 eor r1, r1, #15 */
/* @0x22d534 asr r2, r2, r10 */
/* @0x22d538 str r7, [sp, #0x38] */
/* @0x22d53c ubfx r7, r0, #0x4, #0x4 */
/* @0x22d540 asr r1, r1, r10 */
/* @0x22d544 add r0, r5, r0, asr #8 */
/* @0x22d548 sub r1, r1, #-1073741823 */
/* @0x22d54c add r7, r5, r7 */
/* @0x22d550 add r4, r12, r2, lsl #2 */
/* @0x22d554 ldrb r0, [r0, #0x10] */
/* @0x22d558 add r5, r12, r1, lsl #2 */
/* @0x22d55c add r8, r8, #2 */
/* @0x22d560 ldr r4, [r4, #0x4] */
/* @0x22d564 orr r0, r0, r6, lsl #8 */
/* @0x22d568 str r8, [sp, #0x10] */
/* @0x22d56c ldrb r8, [r7, #0x10] */
/* @0x22d570 ldr r6, [r5, #0x4] */
/* @0x22d574 str r4, [sp, #0x18] */
/* @0x22d578 orr r8, r0, r8, lsl #4 */
/* @0x22d57c rsb r0, r6, r4 */
/* @0x22d580 ldr r4, [sp, #0x9c] */
/* @0x22d584 eor r7, r8, #4080 */
/* @0x22d588 eor r7, r7, #15 */
/* @0x22d58c ldr r10, [r12, r1, lsl #2] */
/* @0x22d590 asr r8, r8, r4 */
/* @0x22d594 ldr r1, [r12, r2, lsl #2] */
/* @0x22d598 smull r4, r5, r0, r3 */
/* @0x22d59c add r2, r10, r1 */
/* @0x22d5a0 rsb r10, r1, r10 */
/* @0x22d5a4 asr r10, r10, #1 */
/* @0x22d5a8 strd r4, r5, [sp, #64] */
/* @0x22d5ac ldr r5, [sp, #0x9c] */
/* @0x22d5b0 asr r4, r7, r5 */
/* @0x22d5b4 ldr r7, [sp, #0x18] */
/* @0x22d5b8 sub r4, r4, #-1073741823 */
/* @0x22d5bc add r5, r7, r6 */
/* @0x22d5c0 ldr r7, [r9, #0x4] */
/* @0x22d5c4 asr r5, r5, #1 */
/* @0x22d5c8 str r5, [sp, #0x2c] */
/* @0x22d5cc smull r6, r7, r2, r7 */
/* @0x22d5d0 smull r2, r3, r2, r3 */
/* @0x22d5d4 add r2, r12, r8, lsl #2 */
/* @0x22d5d8 strd r6, r7, [sp, #48] */
/* @0x22d5dc ldr r7, [r9, #0x4] */
/* @0x22d5e0 ldr r1, [sp, #0x34] */
/* @0x22d5e4 smull r6, r7, r7, r0 */
/* @0x22d5e8 ldr r0, [sp, #0x44] */
/* @0x22d5ec rsb r3, r3, r7 */
/* @0x22d5f0 add r5, r1, r0 */
/* @0x22d5f4 add r0, r12, r4, lsl #2 */
/* @0x22d5f8 strd r6, r7, [sp, #24] */
/* @0x22d5fc ldr r7, [sp, #0x28] */
/* @0x22d600 ldr r6, [sp, #0x2c] */
/* @0x22d604 add r1, r6, r5 */
/* @0x22d608 str r1, [r7] */
/* @0x22d60c add r1, r10, r3 */
/* @0x22d610 str r1, [r7, #0x4] */
/* @0x22d614 ldr r1, [sp, #0x38] */
/* @0x22d618 rsb r5, r5, r6 */
/* @0x22d61c rsb r3, r10, r3 */
/* @0x22d620 str r5, [r11, #0x8] */
/* @0x22d624 str r3, [r11, #0xc] */
/* @0x22d628 ldr r5, [r12, r4, lsl #2] */
/* @0x22d62c ldr r10, [r12, r8, lsl #2] */
/* @0x22d630 ldr r4, [r0, #0x4] */
/* @0x22d634 ldr r0, [r1, #0x4] */
/* @0x22d638 ldr r8, [r2, #0x4] */
/* @0x22d63c add r2, r5, r10 */
/* @0x22d640 rsb r10, r10, r5 */
/* @0x22d644 ldr r6, [sp, #0xe4] */
/* @0x22d648 rsb r1, r4, r8 */
/* @0x22d64c add r7, r8, r4 */
/* @0x22d650 smull r4, r5, r2, r0 */
/* @0x22d654 ldr r3, [r9, r6] */
/* @0x22d658 asr r8, r7, #1 */
/* @0x22d65c ldr r6, [sp, #0x48] */
/* @0x22d660 asr r10, r10, #1 */
/* @0x22d664 strd r4, r5, [sp, #48] */
/* @0x22d668 ldr r5, [sp, #0xc8] */
/* @0x22d66c ldr r7, [sp, #0x34] */
/* @0x22d670 add r9, r9, r5 */
/* @0x22d674 smull r4, r5, r1, r3 */
/* @0x22d678 cmp r6, r9 */
/* @0x22d67c smull r0, r1, r0, r1 */
/* @0x22d680 smull r2, r3, r2, r3 */
/* @0x22d684 add r2, r7, r5 */
/* @0x22d688 rsb r3, r3, r1 */
/* @0x22d68c add r1, r8, r2 */
/* @0x22d690 rsb r2, r2, r8 */
/* @0x22d694 ldr r8, [sp, #0x28] */
/* @0x22d698 add r8, r8, #16 */
/* @0x22d69c str r1, [r8, #-0x8] */
/* @0x22d6a0 add r1, r10, r3 */
/* @0x22d6a4 rsb r3, r10, r3 */
/* @0x22d6a8 str r1, [r8, #-0x4] */
/* @0x22d6ac str r8, [sp, #0x28] */
/* @0x22d6b0 stm r11, {r2, r3} */
/* @0x22d6b4 bhi 0x22d4cc <mdct_backward+0x1550> */
/* @0x22d6b8 ldr r12, [pc, #-0xec4] */
/* @0x22d6bc mov r10, r11 */
/* @0x22d6c0 mov r11, r8 */
/* @0x22d6c4 str r10, [sp, #0x28] */
/* @0x22d6c8 add r12, pc, r12 */
/* @0x22d6cc str r12, [sp, #0x20] */
/* @0x22d6d0 ldr r12, [sp, #0xbc] */
/* @0x22d6d4 mov r10, r9 */
/* @0x22d6d8 ldr r1, [sp, #0x10] */
/* @0x22d6dc add r11, r11, #16 */
/* @0x22d6e0 ldr r3, [sp, #0x10] */
/* @0x22d6e4 ldr r2, [sp, #0x20] */
/* @0x22d6e8 and r0, r1, #15 */
/* @0x22d6ec ldr r4, [sp, #0x20] */
/* @0x22d6f0 ubfx r1, r1, #0x4, #0x4 */
/* @0x22d6f4 add r0, r2, r0 */
/* @0x22d6f8 add r2, r2, r3, asr #8 */
/* @0x22d6fc add r1, r4, r1 */
/* @0x22d700 ldr r5, [sp, #0xcc] */
/* @0x22d704 ldrb r4, [r0, #0x10] */
/* @0x22d708 ldrb r2, [r2, #0x10] */
/* @0x22d70c add r3, r10, r5 */
/* @0x22d710 ldrb r1, [r1, #0x10] */
/* @0x22d714 ldr r7, [sp, #0x10] */
/* @0x22d718 orr r2, r2, r4, lsl #8 */
/* @0x22d71c ldr r8, [r10, r5] */
/* @0x22d720 orr r1, r2, r1, lsl #4 */
/* @0x22d724 add r0, r7, #1 */
/* @0x22d728 eor r7, r1, #4080 */
/* @0x22d72c ldr r9, [sp, #0x9c] */
/* @0x22d730 eor r7, r7, #15 */
/* @0x22d734 ldr r6, [sp, #0x28] */
/* @0x22d738 ldr r5, [sp, #0x20] */
/* @0x22d73c and r2, r0, #15 */
/* @0x22d740 str r8, [sp, #0x8] */
/* @0x22d744 asr r7, r7, r9 */
/* @0x22d748 ldr r8, [sp, #0x20] */
/* @0x22d74c asr r1, r1, r9 */
/* @0x22d750 ldr r4, [sp, #0x10] */
/* @0x22d754 sub r7, r7, #-1073741823 */
/* @0x22d758 sub r6, r6, #16 */
/* @0x22d75c add r2, r5, r2 */
/* @0x22d760 str r6, [sp, #0x28] */
/* @0x22d764 ubfx r6, r0, #0x4, #0x4 */
/* @0x22d768 add r6, r8, r6 */
/* @0x22d76c add r0, r8, r0, asr #8 */
/* @0x22d770 ldrb r5, [r2, #0x10] */
/* @0x22d774 add r4, r4, #2 */
/* @0x22d778 add r2, r12, r7, lsl #2 */
/* @0x22d77c str r4, [sp, #0x10] */
/* @0x22d780 add r4, r12, r1, lsl #2 */
/* @0x22d784 ldrb r0, [r0, #0x10] */
/* @0x22d788 ldrb r6, [r6, #0x10] */
/* @0x22d78c ldr r8, [r4, #0x4] */
/* @0x22d790 orr r0, r0, r5, lsl #8 */
/* @0x22d794 ldr r2, [r2, #0x4] */
/* @0x22d798 ldr r3, [r3, #0x4] */
/* @0x22d79c orr r6, r0, r6, lsl #4 */
/* @0x22d7a0 rsb r0, r2, r8 */
/* @0x22d7a4 ldr r9, [r12, r7, lsl #2] */
/* @0x22d7a8 ldr r7, [r12, r1, lsl #2] */
/* @0x22d7ac add r2, r8, r2 */
/* @0x22d7b0 smull r4, r5, r0, r3 */
/* @0x22d7b4 ldr r8, [sp, #0x8] */
/* @0x22d7b8 eor r1, r6, #4080 */
/* @0x22d7bc str r2, [sp, #0x18] */
/* @0x22d7c0 eor r1, r1, #15 */
/* @0x22d7c4 add r2, r9, r7 */
/* @0x22d7c8 rsb r7, r7, r9 */
/* @0x22d7cc str r7, [sp, #0x2c] */
/* @0x22d7d0 ldr r9, [sp, #0x18] */
/* @0x22d7d4 strd r4, r5, [sp, #48] */
/* @0x22d7d8 ldr r5, [sp, #0x9c] */
/* @0x22d7dc asr r4, r6, r5 */
/* @0x22d7e0 smull r6, r7, r2, r8 */
/* @0x22d7e4 asr r6, r1, r5 */
/* @0x22d7e8 ldr r5, [sp, #0x2c] */
/* @0x22d7ec sub r6, r6, #-1073741823 */
/* @0x22d7f0 smull r0, r1, r8, r0 */
/* @0x22d7f4 asr r8, r9, #1 */
/* @0x22d7f8 smull r2, r3, r2, r3 */
/* @0x22d7fc asr r9, r5, #1 */
/* @0x22d800 ldr r5, [sp, #0x34] */
/* @0x22d804 add r0, r12, r4, lsl #2 */
/* @0x22d808 rsb r3, r3, r1 */
/* @0x22d80c add r2, r7, r5 */
/* @0x22d810 add r1, r8, r2 */
/* @0x22d814 rsb r2, r2, r8 */
/* @0x22d818 str r1, [r11, #-0x10] */
/* @0x22d81c add r1, r9, r3 */
/* @0x22d820 ldr r7, [sp, #0x28] */
/* @0x22d824 rsb r3, r9, r3 */
/* @0x22d828 ldr r8, [sp, #0xd4] */
/* @0x22d82c str r1, [r11, #-0xc] */
/* @0x22d830 str r2, [r7, #0x8] */
/* @0x22d834 add r2, r12, r6, lsl #2 */
/* @0x22d838 str r3, [r7, #0xc] */
/* @0x22d83c ldr r1, [r10, r8]! */
/* @0x22d840 ldr r5, [r0, #0x4] */
/* @0x22d844 ldr r4, [r12, r4, lsl #2] */
/* @0x22d848 ldr r8, [r2, #0x4] */
/* @0x22d84c ldr r9, [r12, r6, lsl #2] */
/* @0x22d850 ldr r3, [r10, #0x4] */
/* @0x22d854 rsb r0, r8, r5 */
/* @0x22d858 add r2, r9, r4 */
/* @0x22d85c add r8, r5, r8 */
/* @0x22d860 rsb r9, r4, r9 */
/* @0x22d864 smull r6, r7, r2, r1 */
/* @0x22d868 asr r8, r8, #1 */
/* @0x22d86c smull r4, r5, r0, r3 */
/* @0x22d870 asr r4, r9, #1 */
/* @0x22d874 smull r0, r1, r1, r0 */
/* @0x22d878 ldr r9, [sp, #0x28] */
/* @0x22d87c smull r2, r3, r2, r3 */
/* @0x22d880 add r0, r7, r5 */
/* @0x22d884 add r2, r8, r0 */
/* @0x22d888 str r2, [r11, #-0x8] */
/* @0x22d88c rsb r3, r3, r1 */
/* @0x22d890 rsb r0, r0, r8 */
/* @0x22d894 add r2, r4, r3 */
/* @0x22d898 str r2, [r11, #-0x4] */
/* @0x22d89c cmp r9, r11 */
/* @0x22d8a0 rsb r3, r4, r3 */
/* @0x22d8a4 str r0, [r9] */
/* @0x22d8a8 str r3, [r9, #0x4] */
/* @0x22d8ac bhi 0x22d6d8 <mdct_backward+0x175c> */
/* @0x22d8b0 ldr r10, [sp, #0xec] */
/* @0x22d8b4 cmp r10, #0 */
/* @0x22d8b8 beq 0x22dcd0 <mdct_backward+0x1d54> */
/* @0x22d8bc cmp r10, #1 */
/* @0x22d8c0 beq 0x22db00 <mdct_backward+0x1b84> */
/* @0x22d8c4 cmp r10, #3 */
/* @0x22d8c8 ble 0x22de90 <mdct_backward+0x1f14> */
/* @0x22d8cc ldr r3, [pc, #0x600] */
/* @0x22d8d0 asr r10, r10, #1 */
/* @0x22d8d4 add r3, pc, r3 */
/* @0x22d8d8 add r10, r3, r10, lsl #2 */
/* @0x22d8dc ldr r12, [sp, #0xec] */
/* @0x22d8e0 ldr r9, [sp, #0xe8] */
/* @0x22d8e4 lsl r0, r12, #3 */
/* @0x22d8e8 lsl r11, r12, #2 */
/* @0x22d8ec lsl r1, r12, #4 */
/* @0x22d8f0 ldr r12, [sp, #0xf4] */
/* @0x22d8f4 mov r8, r9 */
/* @0x22d8f8 add r2, r0, r11 */
/* @0x22d8fc str r0, [sp, #0x10] */
/* @0x22d900 str r1, [sp, #0x40] */
/* @0x22d904 str r2, [sp, #0x28] */
/* @0x22d908 ldr r3, [r12, #0x4] */
/* @0x22d90c add r5, r10, r11 */
/* @0x22d910 ldr r4, [r10, #0x4] */
/* @0x22d914 sub r8, r8, #16 */
/* @0x22d918 ldr r0, [r12] */
/* @0x22d91c rsb r3, r3, #0 */
/* @0x22d920 ldr r2, [r10] */
/* @0x22d924 add r12, r12, #32 */
/* @0x22d928 smull r6, r7, r3, r4 */
/* @0x22d92c str r5, [sp, #0x20] */
/* @0x22d930 smull r4, r5, r0, r4 */
/* @0x22d934 ldr r6, [sp, #0x10] */
/* @0x22d938 smull r0, r1, r0, r2 */
/* @0x22d93c lsl r0, r7, #1 */
/* @0x22d940 smull r2, r3, r2, r3 */
/* @0x22d944 lsl r2, r5, #1 */
/* @0x22d948 ldr r7, [sp, #0x28] */
/* @0x22d94c add r6, r10, r6 */
/* @0x22d950 add r0, r0, r1, lsl #1 */
/* @0x22d954 str r0, [r8, #0xc] */
/* @0x22d958 ldr r0, [sp, #0x20] */
/* @0x22d95c add r7, r10, r7 */
/* @0x22d960 str r6, [sp, #0x38] */
/* @0x22d964 add r9, r9, #16 */
/* @0x22d968 rsb r2, r2, r3, lsl #1 */
/* @0x22d96c str r2, [r9, #-0x10] */
/* @0x22d970 ldr r3, [r12, #-0x14] */
/* @0x22d974 ldr r4, [r0, #0x4] */
/* @0x22d978 ldr r2, [r10, r11] */
/* @0x22d97c rsb r3, r3, #0 */
/* @0x22d980 ldr r0, [r12, #-0x18] */
/* @0x22d984 str r7, [sp, #0x30] */
/* @0x22d988 smull r6, r7, r3, r4 */
/* @0x22d98c smull r4, r5, r0, r4 */
/* @0x22d990 smull r0, r1, r0, r2 */
/* @0x22d994 lsl r0, r7, #1 */
/* @0x22d998 smull r2, r3, r2, r3 */
/* @0x22d99c lsl r2, r5, #1 */
/* @0x22d9a0 ldr r5, [sp, #0x10] */
/* @0x22d9a4 add r0, r0, r1, lsl #1 */
/* @0x22d9a8 ldr r1, [sp, #0x38] */
/* @0x22d9ac str r0, [r8, #0x8] */
/* @0x22d9b0 rsb r2, r2, r3, lsl #1 */
/* @0x22d9b4 str r2, [r9, #-0xc] */
/* @0x22d9b8 ldr r3, [r12, #-0xc] */
/* @0x22d9bc ldr r0, [r12, #-0x10] */
/* @0x22d9c0 ldr r4, [r1, #0x4] */
/* @0x22d9c4 rsb r3, r3, #0 */
/* @0x22d9c8 ldr r2, [r10, r5] */
/* @0x22d9cc smull r6, r7, r3, r4 */
/* @0x22d9d0 ldr r6, [sp, #0x30] */
/* @0x22d9d4 smull r4, r5, r0, r4 */
/* @0x22d9d8 smull r0, r1, r0, r2 */
/* @0x22d9dc lsl r0, r7, #1 */
/* @0x22d9e0 smull r2, r3, r2, r3 */
/* @0x22d9e4 ldr r7, [sp, #0x28] */
/* @0x22d9e8 lsl r2, r5, #1 */
/* @0x22d9ec add r0, r0, r1, lsl #1 */
/* @0x22d9f0 str r0, [r8, #0x4] */
/* @0x22d9f4 ldr r1, [sp, #0x40] */
/* @0x22d9f8 rsb r3, r2, r3, lsl #1 */
/* @0x22d9fc str r3, [r9, #-0x8] */
/* @0x22da00 ldr r3, [r12, #-0x4] */
/* @0x22da04 ldr r0, [r12, #-0x8] */
/* @0x22da08 cmp r8, r12 */
/* @0x22da0c ldr r4, [r6, #0x4] */
/* @0x22da10 rsb r3, r3, #0 */
/* @0x22da14 ldr r2, [r10, r7] */
/* @0x22da18 add r10, r10, r1 */
/* @0x22da1c smull r6, r7, r3, r4 */
/* @0x22da20 smull r4, r5, r0, r4 */
/* @0x22da24 smull r0, r1, r0, r2 */
/* @0x22da28 lsl r0, r7, #1 */
/* @0x22da2c smull r2, r3, r2, r3 */
/* @0x22da30 lsl r2, r5, #1 */
/* @0x22da34 add r0, r0, r1, lsl #1 */
/* @0x22da38 str r0, [r8] */
/* @0x22da3c rsb r3, r2, r3, lsl #1 */
/* @0x22da40 str r3, [r9, #-0x4] */
/* @0x22da44 bhi 0x22d908 <mdct_backward+0x198c> */
/* @0x22da48 ldr r2, [sp, #0xf4] */
/* @0x22da4c ldr r3, [sp, #0xfc] */
/* @0x22da50 add r1, r2, r3 */
/* @0x22da54 ldr r2, [sp, #0xe8] */
/* @0x22da58 mov r3, r1 */
/* @0x22da5c sub r2, r2, #16 */
/* @0x22da60 ldr r0, [r2, #0xc] */
/* @0x22da64 sub r1, r1, #16 */
/* @0x22da68 add r3, r3, #16 */
/* @0x22da6c rsb r12, r0, #0 */
/* @0x22da70 str r0, [r1, #0xc] */
/* @0x22da74 str r12, [r3, #-0x10] */
/* @0x22da78 ldr r0, [r2, #0x8] */
/* @0x22da7c rsb r12, r0, #0 */
/* @0x22da80 str r0, [r1, #0x8] */
/* @0x22da84 str r12, [r3, #-0xc] */
/* @0x22da88 ldr r0, [r2, #0x4] */
/* @0x22da8c rsb r12, r0, #0 */
/* @0x22da90 str r0, [r1, #0x4] */
/* @0x22da94 str r12, [r3, #-0x8] */
/* @0x22da98 ldr r0, [r2] */
/* @0x22da9c rsb r12, r0, #0 */
/* @0x22daa0 str r0, [r1] */
/* @0x22daa4 str r12, [r3, #-0x4] */
/* @0x22daa8 cmp r2, r3 */
/* @0x22daac bhi 0x22da5c <mdct_backward+0x1ae0> */
/* @0x22dab0 ldr r3, [sp, #0xe8] */
/* @0x22dab4 ldr r0, [sp, #0xbc] */
/* @0x22dab8 mov r2, r3 */
/* @0x22dabc ldr r1, [r3, #0xc] */
/* @0x22dac0 str r1, [r2, #-0x10]! */
/* @0x22dac4 cmp r0, r2 */
/* @0x22dac8 ldr r1, [r3, #0x8] */
/* @0x22dacc str r1, [r2, #0x4] */
/* @0x22dad0 ldr r1, [r3, #0x4] */
/* @0x22dad4 str r1, [r2, #0x8] */
/* @0x22dad8 ldr r1, [r3], #16 */
/* @0x22dadc str r1, [r2, #0xc] */
/* @0x22dae0 blo 0x22dabc <mdct_backward+0x1b40> */
/* @0x22dae4 add sp, sp, #256 */
/* @0x22dae8 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x22daec bx lr */
/* @0x22daf0 ldr r3, [pc, #0x3e0] */
/* @0x22daf4 add r3, pc, r3 */
/* @0x22daf8 sub r9, r3, #4080 */
/* @0x22dafc b 0x22d49c <mdct_backward+0x1520> */
/* @0x22db00 ldr r5, [sp, #0xe8] */
/* @0x22db04 mov r1, #0 */
/* @0x22db08 ldr r3, [pc, #0x3cc] */
/* @0x22db0c ldr r4, [sp, #0x20] */
/* @0x22db10 add r3, pc, r3 */
/* @0x22db14 ldr r12, [sp, #0xf4] */
/* @0x22db18 mov r8, r5 */
/* @0x22db1c str r5, [sp, #0x28] */
/* @0x22db20 sub r10, r4, #4080 */
/* @0x22db24 mvn r5, #-1073741824 */
/* @0x22db28 add r11, r3, #24 */
/* @0x22db2c str r8, [sp, #0x10] */
/* @0x22db30 mov r9, r5 */
/* @0x22db34 mov r8, r1 */
/* @0x22db38 ldr r1, [r10, #0x4] */
/* @0x22db3c add r12, r12, #32 */
/* @0x22db40 ldr r3, [r12, #-0x1c] */
/* @0x22db44 add r10, r10, #16 */
/* @0x22db48 ldr r6, [sp, #0x10] */
/* @0x22db4c asr r1, r1, #1 */
/* @0x22db50 rsb r3, r3, #0 */
/* @0x22db54 add r4, r1, r9 */
/* @0x22db58 sub r6, r6, #16 */
/* @0x22db5c str r6, [sp, #0x10] */
/* @0x22db60 smull r6, r7, r3, r4 */
/* @0x22db64 ldr r0, [r12, #-0x20] */
/* @0x22db68 ldr r2, [r10, #-0x10] */
/* @0x22db6c ldr r5, [sp, #0x10] */
/* @0x22db70 asr r9, r2, #1 */
/* @0x22db74 strd r6, r7, [sp, #48] */
/* @0x22db78 add r2, r9, r8 */
/* @0x22db7c smull r6, r7, r0, r4 */
/* @0x22db80 ldr r8, [sp, #0x34] */
/* @0x22db84 strd r6, r7, [sp, #24] */
/* @0x22db88 smull r6, r7, r0, r2 */
/* @0x22db8c ldr r4, [sp, #0x1c] */
/* @0x22db90 smull r2, r3, r2, r3 */
/* @0x22db94 ldr r6, [sp, #0x28] */
/* @0x22db98 lsl r2, r4, #1 */
/* @0x22db9c lsl r0, r8, #1 */
/* @0x22dba0 add r0, r0, r7, lsl #1 */
/* @0x22dba4 str r0, [r5, #0xc] */
/* @0x22dba8 rsb r3, r2, r3, lsl #1 */
/* @0x22dbac str r3, [r6] */
/* @0x22dbb0 ldr r8, [r11, #-0xc] */
/* @0x22dbb4 ldr r3, [r12, #-0x14] */
/* @0x22dbb8 ldr r2, [r11, #-0x10] */
/* @0x22dbbc asr r8, r8, #1 */
/* @0x22dbc0 rsb r3, r3, #0 */
/* @0x22dbc4 add r4, r8, r1 */
/* @0x22dbc8 ldr r7, [r12, #-0x18] */
/* @0x22dbcc asr r6, r2, #1 */
/* @0x22dbd0 smull r0, r1, r3, r4 */
/* @0x22dbd4 add r2, r6, r9 */
/* @0x22dbd8 smull r4, r5, r7, r4 */
/* @0x22dbdc ldr r9, [sp, #0x10] */
/* @0x22dbe0 strd r0, r1, [sp, #32] */
/* @0x22dbe4 smull r0, r1, r7, r2 */
/* @0x22dbe8 ldr r7, [sp, #0x24] */
/* @0x22dbec smull r2, r3, r2, r3 */
/* @0x22dbf0 lsl r0, r7, #1 */
/* @0x22dbf4 lsl r2, r5, #1 */
/* @0x22dbf8 add r0, r0, r1, lsl #1 */
/* @0x22dbfc str r0, [r9, #0x8] */
/* @0x22dc00 ldr r0, [sp, #0x28] */
/* @0x22dc04 rsb r3, r2, r3, lsl #1 */
/* @0x22dc08 str r3, [r0, #0x4] */
/* @0x22dc0c ldr r1, [r10, #-0x4] */
/* @0x22dc10 ldr r0, [r12, #-0x10] */
/* @0x22dc14 ldr r2, [r10, #-0x8] */
/* @0x22dc18 asr r5, r1, #1 */
/* @0x22dc1c ldr r3, [r12, #-0xc] */
/* @0x22dc20 add r4, r5, r8 */
/* @0x22dc24 rsb r3, r3, #0 */
/* @0x22dc28 asr r1, r2, #1 */
/* @0x22dc2c smull r8, r9, r0, r4 */
/* @0x22dc30 add r2, r1, r6 */
/* @0x22dc34 smull r6, r7, r3, r4 */
/* @0x22dc38 ldr r6, [sp, #0x10] */
/* @0x22dc3c strd r8, r9, [sp, #32] */
/* @0x22dc40 smull r8, r9, r0, r2 */
/* @0x22dc44 ldr r4, [sp, #0x24] */
/* @0x22dc48 smull r2, r3, r2, r3 */
/* @0x22dc4c lsl r0, r7, #1 */
/* @0x22dc50 ldr r7, [sp, #0x28] */
/* @0x22dc54 lsl r2, r4, #1 */
/* @0x22dc58 add r0, r0, r9, lsl #1 */
/* @0x22dc5c str r0, [r6, #0x4] */
/* @0x22dc60 rsb r3, r2, r3, lsl #1 */
/* @0x22dc64 str r3, [r7, #0x8] */
/* @0x22dc68 ldmdb r11, {r8, r9} */
/* @0x22dc6c add r11, r11, #16 */
/* @0x22dc70 ldr r3, [r12, #-0x4] */
/* @0x22dc74 ldr r0, [r12, #-0x8] */
/* @0x22dc78 asr r9, r9, #1 */
/* @0x22dc7c add r4, r9, r5 */
/* @0x22dc80 rsb r3, r3, #0 */
/* @0x22dc84 asr r8, r8, #1 */
/* @0x22dc88 cmp r6, r12 */
/* @0x22dc8c add r2, r8, r1 */
/* @0x22dc90 smull r6, r7, r3, r4 */
/* @0x22dc94 smull r4, r5, r0, r4 */
/* @0x22dc98 smull r0, r1, r0, r2 */
/* @0x22dc9c lsl r0, r7, #1 */
/* @0x22dca0 smull r2, r3, r2, r3 */
/* @0x22dca4 lsl r2, r5, #1 */
/* @0x22dca8 add r0, r0, r1, lsl #1 */
/* @0x22dcac ldr r1, [sp, #0x10] */
/* @0x22dcb0 rsb r3, r2, r3, lsl #1 */
/* @0x22dcb4 ldr r2, [sp, #0x28] */
/* @0x22dcb8 str r0, [r1] */
/* @0x22dcbc add r2, r2, #16 */
/* @0x22dcc0 str r3, [r2, #-0x4] */
/* @0x22dcc4 str r2, [sp, #0x28] */
/* @0x22dcc8 bhi 0x22db38 <mdct_backward+0x1bbc> */
/* @0x22dccc b 0x22da48 <mdct_backward+0x1acc> */
/* @0x22dcd0 ldr r11, [sp, #0xe8] */
/* @0x22dcd4 mvn r7, #-2147483648 */
/* @0x22dcd8 ldr r5, [sp, #0xec] */
/* @0x22dcdc mov r12, r7 */
/* @0x22dce0 ldr r3, [pc, #0x1f8] */
/* @0x22dce4 ldr r9, [sp, #0xf4] */
/* @0x22dce8 mov r10, r11 */
/* @0x22dcec ldr r4, [sp, #0x20] */
/* @0x22dcf0 add r3, pc, r3 */
/* @0x22dcf4 mov r8, r5 */
/* @0x22dcf8 add r3, r3, #16 */
/* @0x22dcfc sub r4, r4, #4080 */
/* @0x22dd00 str r3, [sp, #0x28] */
/* @0x22dd04 str r4, [sp, #0x20] */
/* @0x22dd08 str r11, [sp, #0x10] */
/* @0x22dd0c ldr r5, [sp, #0x20] */
/* @0x22dd10 sub r10, r10, #16 */
/* @0x22dd14 ldr r7, [sp, #0x20] */
/* @0x22dd18 add r9, r9, #32 */
/* @0x22dd1c ldr r1, [r9, #-0x20] */
/* @0x22dd20 ldr r6, [r5, #0x4] */
/* @0x22dd24 add r7, r7, #8 */
/* @0x22dd28 str r7, [sp, #0x20] */
/* @0x22dd2c rsb r7, r12, r6 */
/* @0x22dd30 ldr r5, [r5] */
/* @0x22dd34 ldr r11, [r9, #-0x1c] */
/* @0x22dd38 asr r7, r7, #2 */
/* @0x22dd3c rsb r3, r8, r5 */
/* @0x22dd40 add r4, r7, r12 */
/* @0x22dd44 rsb r11, r11, #0 */
/* @0x22dd48 asr r12, r3, #2 */
/* @0x22dd4c rsb r7, r7, r6 */
/* @0x22dd50 smull r0, r1, r1, r4 */
/* @0x22dd54 add r8, r12, r8 */
/* @0x22dd58 smull r2, r3, r11, r4 */
/* @0x22dd5c ldr r4, [r9, #-0x20] */
/* @0x22dd60 rsb r12, r12, r5 */
/* @0x22dd64 strd r0, r1, [sp, #56] */
/* @0x22dd68 smull r0, r1, r4, r8 */
/* @0x22dd6c lsl r0, r3, #1 */
/* @0x22dd70 smull r2, r3, r8, r11 */
/* @0x22dd74 ldr r8, [sp, #0x3c] */
/* @0x22dd78 ldr r11, [sp, #0x28] */
/* @0x22dd7c add r0, r0, r1, lsl #1 */
/* @0x22dd80 str r0, [r10, #0xc] */
/* @0x22dd84 ldr r0, [sp, #0x10] */
/* @0x22dd88 lsl r2, r8, #1 */
/* @0x22dd8c add r11, r11, #8 */
/* @0x22dd90 rsb r3, r2, r3, lsl #1 */
/* @0x22dd94 str r3, [r0] */
/* @0x22dd98 ldr r8, [r9, #-0x14] */
/* @0x22dd9c ldr r4, [r9, #-0x18] */
/* @0x22dda0 rsb r8, r8, #0 */
/* @0x22dda4 smull r0, r1, r4, r7 */
/* @0x22dda8 smull r2, r3, r8, r7 */
/* @0x22ddac ldr r7, [sp, #0x10] */
/* @0x22ddb0 strd r2, r3, [sp, #56] */
/* @0x22ddb4 smull r2, r3, r4, r12 */
/* @0x22ddb8 lsl r2, r1, #1 */
/* @0x22ddbc smull r0, r1, r12, r8 */
/* @0x22ddc0 ldr r4, [sp, #0x3c] */
/* @0x22ddc4 ldr r8, [sp, #0x28] */
/* @0x22ddc8 str r11, [sp, #0x28] */
/* @0x22ddcc lsl r0, r4, #1 */
/* @0x22ddd0 add r3, r0, r3, lsl #1 */
/* @0x22ddd4 str r3, [r10, #0x8] */
/* @0x22ddd8 rsb r2, r2, r1, lsl #1 */
/* @0x22dddc str r2, [r7, #0x4] */
/* @0x22dde0 ldmdb r8, {r8, r12} */
/* @0x22dde4 ldr r3, [r9, #-0xc] */
/* @0x22dde8 rsb r11, r6, r12 */
/* @0x22ddec rsb r1, r5, r8 */
/* @0x22ddf0 ldr r0, [r9, #-0x10] */
/* @0x22ddf4 rsb r3, r3, #0 */
/* @0x22ddf8 asr r11, r11, #2 */
/* @0x22ddfc asr r1, r1, #2 */
/* @0x22de00 add r4, r11, r6 */
/* @0x22de04 add r2, r1, r5 */
/* @0x22de08 rsb r1, r1, r8 */
/* @0x22de0c str r1, [sp, #0x38] */
/* @0x22de10 smull r6, r7, r3, r4 */
/* @0x22de14 rsb r11, r11, r12 */
/* @0x22de18 smull r4, r5, r0, r4 */
/* @0x22de1c smull r0, r1, r0, r2 */
/* @0x22de20 lsl r0, r7, #1 */
/* @0x22de24 smull r2, r3, r2, r3 */
/* @0x22de28 lsl r2, r5, #1 */
/* @0x22de2c add r0, r0, r1, lsl #1 */
/* @0x22de30 str r0, [r10, #0x4] */
/* @0x22de34 ldr r0, [sp, #0x10] */
/* @0x22de38 rsb r3, r2, r3, lsl #1 */
/* @0x22de3c str r3, [r0, #0x8] */
/* @0x22de40 ldr r2, [r9, #-0x4] */
/* @0x22de44 ldr r0, [r9, #-0x8] */
/* @0x22de48 cmp r10, r9 */
/* @0x22de4c ldr r3, [sp, #0x38] */
/* @0x22de50 rsb r2, r2, #0 */
/* @0x22de54 smull r6, r7, r2, r11 */
/* @0x22de58 smull r4, r5, r0, r11 */
/* @0x22de5c smull r0, r1, r0, r3 */
/* @0x22de60 lsl r0, r7, #1 */
/* @0x22de64 smull r2, r3, r3, r2 */
/* @0x22de68 lsl r2, r5, #1 */
/* @0x22de6c add r0, r0, r1, lsl #1 */
/* @0x22de70 str r0, [r10] */
/* @0x22de74 ldr r4, [sp, #0x10] */
/* @0x22de78 rsb r3, r2, r3, lsl #1 */
/* @0x22de7c add r4, r4, #16 */
/* @0x22de80 str r3, [r4, #-0x4] */
/* @0x22de84 str r4, [sp, #0x10] */
/* @0x22de88 bhi 0x22dd0c <mdct_backward+0x1d90> */
/* @0x22de8c b 0x22da48 <mdct_backward+0x1acc> */
/* @0x22de90 ldr r11, [sp, #0x20] */
/* @0x22de94 sub r10, r11, #4080 */
/* @0x22de98 b 0x22d8dc <mdct_backward+0x1960> */
/* @0x22de9c mov r8, #64512 */
/* @0x22dea0 mov r9, #0 */
/* @0x22dea4 movt r8, #0xffff */
/* @0x22dea8 mov r10, #64 */
/* @0x22deac mov r12, #1024 */
/* @0x22deb0 mov r0, #256 */
/* @0x22deb4 mov r2, #7 */
/* @0x22deb8 str r8, [sp, #0xcc] */
/* @0x22debc str r9, [sp, #0x90] */
/* @0x22dec0 str r10, [sp, #0xec] */
/* @0x22dec4 str r12, [sp, #0xe4] */
/* @0x22dec8 str r0, [sp, #0xf8] */
/* @0x22decc str r2, [sp, #0x9c] */
/* @0x22ded0 b 0x22bfec <mdct_backward+0x70> */
/* @0x22ded4 andseq r1, r3, r12, asr #3 */
/* @0x22ded8 andseq r2, r3, r4, lsr #31 */
/* @0x22dedc mulseq r3, r0, pc */
/* @0x22dee0 ldrheq r0, [r3], -r0 */

/* ── FUNC 0x22dee4 · res0_free_info · size=36 · insn=9 */
/* @0x22dee4 push {r4, lr} */
/* @0x22dee8 subs r4, r0, #0 */
/* @0x22deec popeq {r4, pc} */
/* @0x22def0 mov r1, #0 */
/* @0x22def4 movw r2, #0x918 */
/* @0x22def8 bl 0xb65b0 <memset@plt> */
/* @0x22defc mov r0, r4 */
/* @0x22df00 pop {r4, lr} */
/* @0x22df04 b 0xb655c <free@plt> */

/* ── FUNC 0x22df08 · res0_free_look · size=156 · insn=39 */
/* @0x22df08 push {r3, r4, r5, lr} */
/* @0x22df0c subs r4, r0, #0 */
/* @0x22df10 popeq {r3, r4, r5, pc} */
/* @0x22df14 ldr r3, [r4, #0x8] */
/* @0x22df18 ldr r2, [r4, #0x18] */
/* @0x22df1c cmp r3, #0 */
/* @0x22df20 movgt r5, #0 */
/* @0x22df24 ble 0x22df4c <res0_free_look+0x44> */
/* @0x22df28 ldr r0, [r2, r5, lsl #2] */
/* @0x22df2c add r5, r5, #1 */
/* @0x22df30 cmp r0, #0 */
/* @0x22df34 beq 0x22df44 <res0_free_look+0x3c> */
/* @0x22df38 bl 0xb655c <free@plt> */
/* @0x22df3c ldr r2, [r4, #0x18] */
/* @0x22df40 ldr r3, [r4, #0x8] */
/* @0x22df44 cmp r3, r5 */
/* @0x22df48 bgt 0x22df28 <res0_free_look+0x20> */
/* @0x22df4c mov r0, r2 */
/* @0x22df50 bl 0xb655c <free@plt> */
/* @0x22df54 ldr r3, [r4, #0x1c] */
/* @0x22df58 cmp r3, #0 */
/* @0x22df5c movgt r5, #0 */
/* @0x22df60 ble 0x22df80 <res0_free_look+0x78> */
/* @0x22df64 ldr r3, [r4, #0x20] */
/* @0x22df68 ldr r0, [r3, r5, lsl #2] */
/* @0x22df6c add r5, r5, #1 */
/* @0x22df70 bl 0xb655c <free@plt> */
/* @0x22df74 ldr r3, [r4, #0x1c] */
/* @0x22df78 cmp r3, r5 */
/* @0x22df7c bgt 0x22df64 <res0_free_look+0x5c> */
/* @0x22df80 ldr r0, [r4, #0x20] */
/* @0x22df84 bl 0xb655c <free@plt> */
/* @0x22df88 mov r0, r4 */
/* @0x22df8c mov r1, #0 */
/* @0x22df90 mov r2, #36 */
/* @0x22df94 bl 0xb65b0 <memset@plt> */
/* @0x22df98 mov r0, r4 */
/* @0x22df9c pop {r3, r4, r5, lr} */
/* @0x22dfa0 b 0xb655c <free@plt> */

/* ── FUNC 0x22dfa4 · res0_unpack · size=564 · insn=141 */
/* @0x22dfa4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x22dfa8 mov r4, r1 */
/* @0x22dfac mov r5, r0 */
/* @0x22dfb0 movw r1, #0x918 */
/* @0x22dfb4 mov r0, #1 */
/* @0x22dfb8 bl 0xb6c34 <calloc@plt> */
/* @0x22dfbc mov r1, #24 */
/* @0x22dfc0 ldr r8, [r5, #0x1c] */
/* @0x22dfc4 mov r7, r0 */
/* @0x22dfc8 mov r0, r4 */
/* @0x22dfcc bl 0x233b28 <oggpack_read> */
/* @0x22dfd0 mov r1, #24 */
/* @0x22dfd4 str r0, [r7] */
/* @0x22dfd8 mov r0, r4 */
/* @0x22dfdc bl 0x233b28 <oggpack_read> */
/* @0x22dfe0 mov r1, #24 */
/* @0x22dfe4 str r0, [r7, #0x4] */
/* @0x22dfe8 mov r0, r4 */
/* @0x22dfec bl 0x233b28 <oggpack_read> */
/* @0x22dff0 mov r1, #6 */
/* @0x22dff4 add r3, r0, #1 */
/* @0x22dff8 mov r0, r4 */
/* @0x22dffc str r3, [r7, #0x8] */
/* @0x22e000 bl 0x233b28 <oggpack_read> */
/* @0x22e004 mov r1, #8 */
/* @0x22e008 add r3, r0, #1 */
/* @0x22e00c mov r0, r4 */
/* @0x22e010 str r3, [r7, #0xc] */
/* @0x22e014 bl 0x233b28 <oggpack_read> */
/* @0x22e018 cmp r0, #0 */
/* @0x22e01c str r0, [r7, #0x14] */
/* @0x22e020 blt 0x22e0d0 <res0_unpack+0x12c> */
/* @0x22e024 ldr r3, [r7, #0xc] */
/* @0x22e028 cmp r3, #0 */
/* @0x22e02c ble 0x22e1c4 <res0_unpack+0x220> */
/* @0x22e030 mov r5, #0 */
/* @0x22e034 add r6, r7, #20 */
/* @0x22e038 mov r10, r5 */
/* @0x22e03c mov r1, #3 */
/* @0x22e040 mov r0, r4 */
/* @0x22e044 bl 0x233b28 <oggpack_read> */
/* @0x22e048 mov r1, #1 */
/* @0x22e04c mov r9, r0 */
/* @0x22e050 mov r0, r4 */
/* @0x22e054 bl 0x233b28 <oggpack_read> */
/* @0x22e058 cmp r0, #0 */
/* @0x22e05c blt 0x22e0d0 <res0_unpack+0x12c> */
/* @0x22e060 bne 0x22e0e0 <res0_unpack+0x13c> */
/* @0x22e064 subs r3, r9, #0 */
/* @0x22e068 str r9, [r6, #0x4]! */
/* @0x22e06c beq 0x22e104 <res0_unpack+0x160> */
/* @0x22e070 mov r2, #0 */
/* @0x22e074 and r12, r3, #1 */
/* @0x22e078 lsrs r3, r3, #1 */
/* @0x22e07c add r2, r12, r2 */
/* @0x22e080 bne 0x22e074 <res0_unpack+0xd0> */
/* @0x22e084 ldr r3, [r7, #0xc] */
/* @0x22e088 add r10, r10, #1 */
/* @0x22e08c add r5, r5, r2 */
/* @0x22e090 cmp r3, r10 */
/* @0x22e094 bgt 0x22e03c <res0_unpack+0x98> */
/* @0x22e098 cmp r5, #0 */
/* @0x22e09c addgt r9, r7, #276 */
/* @0x22e0a0 movgt r6, #0 */
/* @0x22e0a4 bgt 0x22e0b8 <res0_unpack+0x114> */
/* @0x22e0a8 b 0x22e10c <res0_unpack+0x168> */
/* @0x22e0ac cmp r6, r5 */
/* @0x22e0b0 str r0, [r9, #0x4]! */
/* @0x22e0b4 beq 0x22e10c <res0_unpack+0x168> */
/* @0x22e0b8 mov r0, r4 */
/* @0x22e0bc mov r1, #8 */
/* @0x22e0c0 bl 0x233b28 <oggpack_read> */
/* @0x22e0c4 add r6, r6, #1 */
/* @0x22e0c8 cmp r0, #0 */
/* @0x22e0cc bge 0x22e0ac <res0_unpack+0x108> */
/* @0x22e0d0 mov r0, r7 */
/* @0x22e0d4 bl 0x22dee4 <res0_free_info> */
/* @0x22e0d8 mov r0, #0 */
/* @0x22e0dc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x22e0e0 mov r0, r4 */
/* @0x22e0e4 mov r1, #5 */
/* @0x22e0e8 bl 0x233b28 <oggpack_read> */
/* @0x22e0ec cmp r0, #0 */
/* @0x22e0f0 blt 0x22e0d0 <res0_unpack+0x12c> */
/* @0x22e0f4 orr r9, r9, r0, lsl #3 */
/* @0x22e0f8 str r9, [r6, #0x4]! */
/* @0x22e0fc subs r3, r9, #0 */
/* @0x22e100 bne 0x22e070 <res0_unpack+0xcc> */
/* @0x22e104 mov r2, r9 */
/* @0x22e108 b 0x22e084 <res0_unpack+0xe0> */
/* @0x22e10c ldr r4, [r7, #0x14] */
/* @0x22e110 ldr r12, [r8, #0x1c] */
/* @0x22e114 cmp r12, r4 */
/* @0x22e118 ble 0x22e0d0 <res0_unpack+0x12c> */
/* @0x22e11c cmp r5, #0 */
/* @0x22e120 ble 0x22e17c <res0_unpack+0x1d8> */
/* @0x22e124 ldr r3, [r7, #0x118] */
/* @0x22e128 cmp r12, r3 */
/* @0x22e12c ble 0x22e0d0 <res0_unpack+0x12c> */
/* @0x22e130 add r3, r3, #520 */
/* @0x22e134 ldr r3, [r8, r3, lsl #2] */
/* @0x22e138 ldr r3, [r3, #0xc] */
/* @0x22e13c cmp r3, #0 */
/* @0x22e140 beq 0x22e0d0 <res0_unpack+0x12c> */
/* @0x22e144 add r1, r7, #280 */
/* @0x22e148 mov r3, #0 */
/* @0x22e14c b 0x22e170 <res0_unpack+0x1cc> */
/* @0x22e150 ldr r2, [r1, #0x4]! */
/* @0x22e154 cmp r12, r2 */
/* @0x22e158 add r0, r2, #520 */
/* @0x22e15c ble 0x22e0d0 <res0_unpack+0x12c> */
/* @0x22e160 ldr r2, [r8, r0, lsl #2] */
/* @0x22e164 ldr r2, [r2, #0xc] */
/* @0x22e168 cmp r2, #0 */
/* @0x22e16c beq 0x22e0d0 <res0_unpack+0x12c> */
/* @0x22e170 add r3, r3, #1 */
/* @0x22e174 cmp r3, r5 */
/* @0x22e178 bne 0x22e150 <res0_unpack+0x1ac> */
/* @0x22e17c add r4, r4, #520 */
/* @0x22e180 ldr r3, [r8, r4, lsl #2] */
/* @0x22e184 ldr r2, [r3] */
/* @0x22e188 ldr r0, [r3, #0x4] */
/* @0x22e18c cmp r2, #0 */
/* @0x22e190 ble 0x22e0d0 <res0_unpack+0x12c> */
/* @0x22e194 ldr r1, [r7, #0xc] */
/* @0x22e198 mov r3, #1 */
/* @0x22e19c b 0x22e1a8 <res0_unpack+0x204> */
/* @0x22e1a0 subs r2, r2, #1 */
/* @0x22e1a4 beq 0x22e1b8 <res0_unpack+0x214> */
/* @0x22e1a8 mul r3, r1, r3 */
/* @0x22e1ac cmp r0, r3 */
/* @0x22e1b0 bge 0x22e1a0 <res0_unpack+0x1fc> */
/* @0x22e1b4 b 0x22e0d0 <res0_unpack+0x12c> */
/* @0x22e1b8 str r3, [r7, #0x10] */
/* @0x22e1bc mov r0, r7 */
/* @0x22e1c0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x22e1c4 ldr r3, [r8, #0x1c] */
/* @0x22e1c8 cmp r0, r3 */
/* @0x22e1cc bge 0x22e0d0 <res0_unpack+0x12c> */
/* @0x22e1d0 mov r4, r0 */
/* @0x22e1d4 b 0x22e17c <res0_unpack+0x1d8> */

/* ── FUNC 0x22e1d8 · res0_look · size=600 · insn=150 */
/* @0x22e1d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22e1dc mov r6, r0 */
/* @0x22e1e0 sub sp, sp, #36 */
/* @0x22e1e4 mov r5, r1 */
/* @0x22e1e8 mov r0, #1 */
/* @0x22e1ec mov r1, #36 */
/* @0x22e1f0 mov r11, r2 */
/* @0x22e1f4 bl 0xb6c34 <calloc@plt> */
/* @0x22e1f8 ldr r3, [r6, #0x4] */
/* @0x22e1fc mov r4, #52 */
/* @0x22e200 ldr r12, [r11, #0x14] */
/* @0x22e204 mov r1, #4 */
/* @0x22e208 ldr lr, [r5, #0xc] */
/* @0x22e20c ldr r3, [r3, #0x1c] */
/* @0x22e210 mul r12, r4, r12 */
/* @0x22e214 ldr r10, [r11, #0xc] */
/* @0x22e218 ldr r2, [r3, #0xc20] */
/* @0x22e21c str r10, [sp, #0x1c] */
/* @0x22e220 mov r8, r0 */
/* @0x22e224 mov r0, r10 */
/* @0x22e228 str lr, [r8, #0x4] */
/* @0x22e22c add lr, r2, r12 */
/* @0x22e230 ldr r12, [r2, r12] */
/* @0x22e234 str r2, [r8, #0x10] */
/* @0x22e238 str r3, [sp, #0x4] */
/* @0x22e23c str r11, [r8] */
/* @0x22e240 str lr, [r8, #0x14] */
/* @0x22e244 str r12, [sp, #0x18] */
/* @0x22e248 str r10, [r8, #0x8] */
/* @0x22e24c bl 0xb6c34 <calloc@plt> */
/* @0x22e250 cmp r10, #0 */
/* @0x22e254 mov r2, #0 */
/* @0x22e258 ldr r3, [sp, #0x4] */
/* @0x22e25c str r2, [sp, #0x10] */
/* @0x22e260 str r0, [r8, #0x18] */
/* @0x22e264 ble 0x22e330 <res0_look+0x158> */
/* @0x22e268 add r12, r11, #20 */
/* @0x22e26c mov r6, #0 */
/* @0x22e270 str r10, [sp, #0x14] */
/* @0x22e274 mov r2, r4 */
/* @0x22e278 mov r10, r3 */
/* @0x22e27c mov r9, r6 */
/* @0x22e280 mov r3, r12 */
/* @0x22e284 ldr r7, [r3, #0x4]! */
/* @0x22e288 cmp r7, #0 */
/* @0x22e28c mov r4, r7 */
/* @0x22e290 beq 0x22e31c <res0_look+0x144> */
/* @0x22e294 mov r5, #0 */
/* @0x22e298 lsrs r4, r4, #1 */
/* @0x22e29c add r5, r5, #1 */
/* @0x22e2a0 bne 0x22e298 <res0_look+0xc0> */
/* @0x22e2a4 ldr r12, [r8, #0x18] */
/* @0x22e2a8 mov r1, #4 */
/* @0x22e2ac mov r0, r5 */
/* @0x22e2b0 str r2, [sp, #0x8] */
/* @0x22e2b4 str r3, [sp, #0x4] */
/* @0x22e2b8 str r12, [sp, #0xc] */
/* @0x22e2bc bl 0xb6c34 <calloc@plt> */
/* @0x22e2c0 ldr r1, [sp, #0x10] */
/* @0x22e2c4 ldr r12, [sp, #0xc] */
/* @0x22e2c8 ldr r3, [sp, #0x4] */
/* @0x22e2cc cmp r1, r5 */
/* @0x22e2d0 movlt r1, r5 */
/* @0x22e2d4 ldr r2, [sp, #0x8] */
/* @0x22e2d8 str r1, [sp, #0x10] */
/* @0x22e2dc lsl r1, r9, #2 */
/* @0x22e2e0 str r0, [r12, r9, lsl #2] */
/* @0x22e2e4 asr r0, r7, r4 */
/* @0x22e2e8 add r12, r6, #70 */
/* @0x22e2ec tst r0, #1 */
/* @0x22e2f0 beq 0x22e310 <res0_look+0x138> */
/* @0x22e2f4 ldr lr, [r11, r12, lsl #2] */
/* @0x22e2f8 add r6, r6, #1 */
/* @0x22e2fc ldr r12, [r10, #0xc20] */
/* @0x22e300 ldr r0, [r8, #0x18] */
/* @0x22e304 mla r12, r2, lr, r12 */
/* @0x22e308 ldr r0, [r0, r1] */
/* @0x22e30c str r12, [r0, r4, lsl #2] */
/* @0x22e310 add r4, r4, #1 */
/* @0x22e314 cmp r4, r5 */
/* @0x22e318 blt 0x22e2e4 <res0_look+0x10c> */
/* @0x22e31c ldr r1, [sp, #0x14] */
/* @0x22e320 add r9, r9, #1 */
/* @0x22e324 cmp r9, r1 */
/* @0x22e328 bne 0x22e284 <res0_look+0xac> */
/* @0x22e32c mov r10, r1 */
/* @0x22e330 ldr r3, [sp, #0x18] */
/* @0x22e334 mov r4, r10 */
/* @0x22e338 str r10, [r8, #0x1c] */
/* @0x22e33c cmp r3, #1 */
/* @0x22e340 ble 0x22e364 <res0_look+0x18c> */
/* @0x22e344 ldr r2, [sp, #0x18] */
/* @0x22e348 mov r3, #1 */
/* @0x22e34c add r3, r3, #1 */
/* @0x22e350 cmp r3, r2 */
/* @0x22e354 mul r4, r10, r4 */
/* @0x22e358 bne 0x22e34c <res0_look+0x174> */
/* @0x22e35c str r4, [r8, #0x1c] */
/* @0x22e360 str r4, [sp, #0x1c] */
/* @0x22e364 ldr r2, [sp, #0x1c] */
/* @0x22e368 ldr r3, [sp, #0x10] */
/* @0x22e36c lsl r0, r2, #2 */
/* @0x22e370 str r3, [r8, #0xc] */
/* @0x22e374 bl 0xb6544 <malloc@plt> */
/* @0x22e378 cmp r4, #0 */
/* @0x22e37c str r0, [r8, #0x20] */
/* @0x22e380 ble 0x22e424 <res0_look+0x24c> */
/* @0x22e384 ldr r2, [sp, #0x18] */
/* @0x22e388 mov r5, r0 */
/* @0x22e38c mov r7, #0 */
/* @0x22e390 mov r0, r4 */
/* @0x22e394 lsl r2, r2, #2 */
/* @0x22e398 str r2, [sp, #0x10] */
/* @0x22e39c mov r1, r10 */
/* @0x22e3a0 bl 0x318d10 <__divsi3> */
/* @0x22e3a4 mov r4, r0 */
/* @0x22e3a8 ldr r0, [sp, #0x10] */
/* @0x22e3ac bl 0xb6544 <malloc@plt> */
/* @0x22e3b0 ldr r3, [sp, #0x18] */
/* @0x22e3b4 cmp r3, #0 */
/* @0x22e3b8 str r0, [r5, r7, lsl #2] */
/* @0x22e3bc ble 0x22e40c <res0_look+0x234> */
/* @0x22e3c0 ldr r3, [r8, #0x20] */
/* @0x22e3c4 mov r5, r7 */
/* @0x22e3c8 ldr r2, [sp, #0x10] */
/* @0x22e3cc ldr r11, [r3, r7, lsl #2] */
/* @0x22e3d0 add r6, r11, r2 */
/* @0x22e3d4 b 0x22e3dc <res0_look+0x204> */
/* @0x22e3d8 ldr r10, [r8, #0x8] */
/* @0x22e3dc mov r1, r4 */
/* @0x22e3e0 mov r0, r5 */
/* @0x22e3e4 bl 0x318d10 <__divsi3> */
/* @0x22e3e8 mov r1, r10 */
/* @0x22e3ec mov r9, r0 */
/* @0x22e3f0 mov r0, r4 */
/* @0x22e3f4 bl 0x318d10 <__divsi3> */
/* @0x22e3f8 str r9, [r11], #4 */
/* @0x22e3fc cmp r11, r6 */
/* @0x22e400 mls r5, r4, r9, r5 */
/* @0x22e404 mov r4, r0 */
/* @0x22e408 bne 0x22e3d8 <res0_look+0x200> */
/* @0x22e40c ldr r0, [r8, #0x1c] */
/* @0x22e410 add r7, r7, #1 */
/* @0x22e414 cmp r0, r7 */
/* @0x22e418 ldrgt r10, [r8, #0x8] */
/* @0x22e41c ldrgt r5, [r8, #0x20] */
/* @0x22e420 bgt 0x22e39c <res0_look+0x1c4> */
/* @0x22e424 mov r0, r8 */
/* @0x22e428 add sp, sp, #36 */
/* @0x22e42c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x22e430 · anon_22e430 · size=780 · insn=195 */
/* @0x22e430 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22e434 add r11, sp, #32 */
/* @0x22e438 sub sp, sp, #84 */
/* @0x22e43c ldr r7, [pc, #0x2f4] */
/* @0x22e440 str r2, [r11, #-0x3c] */
/* @0x22e444 ldr r7, [pc, r7] */
/* @0x22e448 mov r4, r0 */
/* @0x22e44c ldr r9, [r1] */
/* @0x22e450 mov r10, r3 */
/* @0x22e454 ldr r2, [r0, #0x24] */
/* @0x22e458 mov r8, r1 */
/* @0x22e45c str r7, [r11, #-0x4c] */
/* @0x22e460 ldr r3, [r9] */
/* @0x22e464 ldr r0, [r9, #0x4] */
/* @0x22e468 asr r2, r2, #1 */
/* @0x22e46c ldr r1, [r1, #0x14] */
/* @0x22e470 cmp r2, r0 */
/* @0x22e474 rsble r0, r3, r2 */
/* @0x22e478 rsbgt r0, r3, r0 */
/* @0x22e47c ldr r3, [r7] */
/* @0x22e480 ldr r7, [r9, #0x8] */
/* @0x22e484 cmp r0, #0 */
/* @0x22e488 ldr r1, [r1] */
/* @0x22e48c str r3, [r11, #-0x28] */
/* @0x22e490 str r7, [r11, #-0x34] */
/* @0x22e494 ldr r7, [r11, #0x4] */
/* @0x22e498 str r1, [r11, #-0x54] */
/* @0x22e49c str r7, [r11, #-0x40] */
/* @0x22e4a0 ble 0x22e6b0 <res0_look+0x4d8> */
/* @0x22e4a4 ldr r1, [r11, #-0x34] */
/* @0x22e4a8 bl 0x318d10 <__divsi3> */
/* @0x22e4ac ldr r7, [r11, #-0x54] */
/* @0x22e4b0 mov r1, r7 */
/* @0x22e4b4 str r0, [r11, #-0x58] */
/* @0x22e4b8 add r0, r0, r7 */
/* @0x22e4bc sub r0, r0, #1 */
/* @0x22e4c0 bl 0x318d10 <__divsi3> */
/* @0x22e4c4 lsl r3, r10, #2 */
/* @0x22e4c8 add r3, r3, #14 */
/* @0x22e4cc cmp r10, #0 */
/* @0x22e4d0 bic r3, r3, #7 */
/* @0x22e4d4 sub sp, sp, r3 */
/* @0x22e4d8 add r7, sp, #8 */
/* @0x22e4dc str r7, [r11, #-0x5c] */
/* @0x22e4e0 ble 0x22e510 <res0_look+0x338> */
/* @0x22e4e4 lsl r5, r0, #2 */
/* @0x22e4e8 ldr r0, [r11, #-0x5c] */
/* @0x22e4ec mov r6, #0 */
/* @0x22e4f0 sub r7, r0, #4 */
/* @0x22e4f4 mov r0, r4 */
/* @0x22e4f8 mov r1, r5 */
/* @0x22e4fc bl 0x2270e4 <_vorbis_block_alloc> */
/* @0x22e500 add r6, r6, #1 */
/* @0x22e504 cmp r6, r10 */
/* @0x22e508 str r0, [r7, #0x4]! */
/* @0x22e50c bne 0x22e4f4 <res0_look+0x31c> */
/* @0x22e510 ldr r3, [r8, #0xc] */
/* @0x22e514 cmp r3, #0 */
/* @0x22e518 addgt r4, r4, #4 */
/* @0x22e51c strgt r4, [r11, #-0x44] */
/* @0x22e520 movgt r7, #0 */
/* @0x22e524 strgt r7, [r11, #-0x60] */
/* @0x22e528 ble 0x22e6b0 <res0_look+0x4d8> */
/* @0x22e52c ldr r7, [r11, #-0x58] */
/* @0x22e530 cmp r7, #0 */
/* @0x22e534 ble 0x22e69c <res0_look+0x4c4> */
/* @0x22e538 ldr r0, [r11, #-0x60] */
/* @0x22e53c mov r7, #1 */
/* @0x22e540 mov r6, #0 */
/* @0x22e544 str r6, [r11, #-0x50] */
/* @0x22e548 lsl r7, r7, r0 */
/* @0x22e54c str r7, [r11, #-0x64] */
/* @0x22e550 lsl r7, r0, #2 */
/* @0x22e554 str r7, [r11, #-0x30] */
/* @0x22e558 ldr r7, [r11, #-0x60] */
/* @0x22e55c cmp r7, #0 */
/* @0x22e560 beq 0x22e6d0 <res0_look+0x4f8> */
/* @0x22e564 ldr r7, [r11, #-0x58] */
/* @0x22e568 ldr r0, [r11, #-0x50] */
/* @0x22e56c ldr r1, [r11, #-0x54] */
/* @0x22e570 cmp r7, r0 */
/* @0x22e574 cmpgt r1, #0 */
/* @0x22e578 ble 0x22e684 <res0_look+0x4ac> */
/* @0x22e57c ldr r7, [r11, #-0x50] */
/* @0x22e580 mov r12, r8 */
/* @0x22e584 ldr r0, [r11, #-0x34] */
/* @0x22e588 ldr r8, [r11, #-0x64] */
/* @0x22e58c mul r7, r7, r0 */
/* @0x22e590 str r7, [r11, #-0x38] */
/* @0x22e594 mov r7, #0 */
/* @0x22e598 str r7, [r11, #-0x48] */
/* @0x22e59c cmp r10, #0 */
/* @0x22e5a0 ble 0x22e640 <res0_look+0x468> */
/* @0x22e5a4 ldr r2, [r11, #-0x5c] */
/* @0x22e5a8 mov r4, #0 */
/* @0x22e5ac ldr r1, [r11, #-0x48] */
/* @0x22e5b0 sub r5, r2, #4 */
/* @0x22e5b4 lsl r7, r1, #2 */
/* @0x22e5b8 str r7, [r11, #-0x6c] */
/* @0x22e5bc ldr r3, [r5, #0x4]! */
/* @0x22e5c0 ldr r7, [r11, #-0x6c] */
/* @0x22e5c4 ldr r1, [r9] */
/* @0x22e5c8 ldr r3, [r3, r6] */
/* @0x22e5cc ldr r3, [r3, r7] */
/* @0x22e5d0 add r2, r3, #6 */
/* @0x22e5d4 ldr r2, [r9, r2, lsl #2] */
/* @0x22e5d8 tst r8, r2 */
/* @0x22e5dc beq 0x22e634 <res0_look+0x45c> */
/* @0x22e5e0 ldr r2, [r12, #0x18] */
/* @0x22e5e4 ldr r7, [r11, #-0x30] */
/* @0x22e5e8 ldr r3, [r2, r3, lsl #2] */
/* @0x22e5ec ldr r0, [r3, r7] */
/* @0x22e5f0 cmp r0, #0 */
/* @0x22e5f4 beq 0x22e634 <res0_look+0x45c> */
/* @0x22e5f8 ldr r7, [r11, #-0x38] */
/* @0x22e5fc mvn r2, #7 */
/* @0x22e600 add r1, r7, r1 */
/* @0x22e604 ldr r7, [r11, #-0x3c] */
/* @0x22e608 ldr r3, [r7, r4, lsl #2] */
/* @0x22e60c str r2, [sp] */
/* @0x22e610 add r1, r3, r1, lsl #2 */
/* @0x22e614 str r12, [r11, #-0x68] */
/* @0x22e618 ldr r2, [r11, #-0x44] */
/* @0x22e61c ldr r3, [r11, #-0x34] */
/* @0x22e620 ldr r7, [r11, #-0x40] */
/* @0x22e624 blx r7 */
/* @0x22e628 ldr r12, [r11, #-0x68] */
/* @0x22e62c cmn r0, #1 */
/* @0x22e630 beq 0x22e6b0 <res0_look+0x4d8> */
/* @0x22e634 add r4, r4, #1 */
/* @0x22e638 cmp r4, r10 */
/* @0x22e63c bne 0x22e5bc <res0_look+0x3e4> */
/* @0x22e640 ldr r7, [r11, #-0x48] */
/* @0x22e644 ldr r0, [r11, #-0x58] */
/* @0x22e648 add r7, r7, #1 */
/* @0x22e64c str r7, [r11, #-0x48] */
/* @0x22e650 ldr r7, [r11, #-0x50] */
/* @0x22e654 ldr r1, [r11, #-0x54] */
/* @0x22e658 ldr r2, [r11, #-0x48] */
/* @0x22e65c add r7, r7, #1 */
/* @0x22e660 str r7, [r11, #-0x50] */
/* @0x22e664 cmp r0, r7 */
/* @0x22e668 cmpgt r1, r2 */
/* @0x22e66c ldr r7, [r11, #-0x38] */
/* @0x22e670 ldr r0, [r11, #-0x34] */
/* @0x22e674 add r7, r7, r0 */
/* @0x22e678 str r7, [r11, #-0x38] */
/* @0x22e67c bgt 0x22e59c <res0_look+0x3c4> */
/* @0x22e680 mov r8, r12 */
/* @0x22e684 ldr r7, [r11, #-0x58] */
/* @0x22e688 add r6, r6, #4 */
/* @0x22e68c ldr r0, [r11, #-0x50] */
/* @0x22e690 cmp r7, r0 */
/* @0x22e694 bgt 0x22e558 <res0_look+0x380> */
/* @0x22e698 ldr r3, [r8, #0xc] */
/* @0x22e69c ldr r7, [r11, #-0x60] */
/* @0x22e6a0 add r7, r7, #1 */
/* @0x22e6a4 str r7, [r11, #-0x60] */
/* @0x22e6a8 cmp r3, r7 */
/* @0x22e6ac bgt 0x22e52c <res0_look+0x354> */
/* @0x22e6b0 ldr r7, [r11, #-0x4c] */
/* @0x22e6b4 mov r0, #0 */
/* @0x22e6b8 ldr r2, [r11, #-0x28] */
/* @0x22e6bc ldr r3, [r7] */
/* @0x22e6c0 cmp r2, r3 */
/* @0x22e6c4 bne 0x22e734 <res0_look+0x55c> */
/* @0x22e6c8 sub sp, r11, #32 */
/* @0x22e6cc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22e6d0 cmp r10, #0 */
/* @0x22e6d4 ble 0x22e564 <res0_look+0x38c> */
/* @0x22e6d8 ldr r7, [r11, #-0x5c] */
/* @0x22e6dc ldr r5, [r11, #-0x60] */
/* @0x22e6e0 sub r4, r7, #4 */
/* @0x22e6e4 ldr r7, [r11, #-0x44] */
/* @0x22e6e8 b 0x22e71c <res0_look+0x544> */
/* @0x22e6ec ldr r3, [r9, #0x10] */
/* @0x22e6f0 cmp r0, r3 */
/* @0x22e6f4 bge 0x22e6b0 <res0_look+0x4d8> */
/* @0x22e6f8 ldr r3, [r8, #0x20] */
/* @0x22e6fc ldr r2, [r4, #0x4]! */
/* @0x22e700 ldr r3, [r3, r0, lsl #2] */
/* @0x22e704 cmp r3, #0 */
/* @0x22e708 str r3, [r2, r6] */
/* @0x22e70c beq 0x22e6b0 <res0_look+0x4d8> */
/* @0x22e710 add r5, r5, #1 */
/* @0x22e714 cmp r5, r10 */
/* @0x22e718 beq 0x22e564 <res0_look+0x38c> */
/* @0x22e71c ldr r0, [r8, #0x14] */
/* @0x22e720 mov r1, r7 */
/* @0x22e724 bl 0x2280d0 <vorbis_book_decode> */
/* @0x22e728 cmn r0, #1 */
/* @0x22e72c bne 0x22e6ec <res0_look+0x514> */
/* @0x22e730 b 0x22e6b0 <res0_look+0x4d8> */
/* @0x22e734 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x22e738 andseq pc, r11, r12, lsl #10 */

/* ── FUNC 0x22e73c · res0_inverse · size=108 · insn=27 */
/* @0x22e73c push {r4, r5, r6} */
/* @0x22e740 ldr r6, [sp, #0xc] */
/* @0x22e744 cmp r6, #0 */
/* @0x22e748 ble 0x22e780 <res0_inverse+0x44> */
/* @0x22e74c mov r12, #0 */
/* @0x22e750 lsl r6, r6, #2 */
/* @0x22e754 mov r5, r12 */
/* @0x22e758 ldr r4, [r3, r12] */
/* @0x22e75c cmp r4, #0 */
/* @0x22e760 ldrne r4, [r2, r12] */
/* @0x22e764 add r12, r12, #4 */
/* @0x22e768 strne r4, [r2, r5, lsl #2] */
/* @0x22e76c addne r5, r5, #1 */
/* @0x22e770 cmp r12, r6 */
/* @0x22e774 bne 0x22e758 <res0_inverse+0x1c> */
/* @0x22e778 cmp r5, #0 */
/* @0x22e77c bne 0x22e78c <res0_inverse+0x50> */
/* @0x22e780 mov r0, #0 */
/* @0x22e784 pop {r4, r5, r6} */
/* @0x22e788 bx lr */
/* @0x22e78c ldr r12, [pc, #0x10] */
/* @0x22e790 mov r3, r5 */
/* @0x22e794 ldr r12, [pc, r12] */
/* @0x22e798 str r12, [sp, #0xc] */
/* @0x22e79c pop {r4, r5, r6} */
/* @0x22e7a0 b 0x22e430 <res0_look+0x258> */
/* @0x22e7a4 ldrsheq r2, [r12], -r8 */

/* ── FUNC 0x22e7a8 · res1_inverse · size=108 · insn=27 */
/* @0x22e7a8 push {r4, r5, r6} */
/* @0x22e7ac ldr r6, [sp, #0xc] */
/* @0x22e7b0 cmp r6, #0 */
/* @0x22e7b4 ble 0x22e7ec <res1_inverse+0x44> */
/* @0x22e7b8 mov r12, #0 */
/* @0x22e7bc lsl r6, r6, #2 */
/* @0x22e7c0 mov r5, r12 */
/* @0x22e7c4 ldr r4, [r3, r12] */
/* @0x22e7c8 cmp r4, #0 */
/* @0x22e7cc ldrne r4, [r2, r12] */
/* @0x22e7d0 add r12, r12, #4 */
/* @0x22e7d4 strne r4, [r2, r5, lsl #2] */
/* @0x22e7d8 addne r5, r5, #1 */
/* @0x22e7dc cmp r12, r6 */
/* @0x22e7e0 bne 0x22e7c4 <res1_inverse+0x1c> */
/* @0x22e7e4 cmp r5, #0 */
/* @0x22e7e8 bne 0x22e7f8 <res1_inverse+0x50> */
/* @0x22e7ec mov r0, #0 */
/* @0x22e7f0 pop {r4, r5, r6} */
/* @0x22e7f4 bx lr */
/* @0x22e7f8 ldr r12, [pc, #0x10] */
/* @0x22e7fc mov r3, r5 */
/* @0x22e800 ldr r12, [pc, r12] */
/* @0x22e804 str r12, [sp, #0xc] */
/* @0x22e808 pop {r4, r5, r6} */
/* @0x22e80c b 0x22e430 <res0_look+0x258> */
/* @0x22e810 mulseq r12, r0, r12 */

/* ── FUNC 0x22e814 · res2_inverse · size=604 · insn=151 */
/* @0x22e814 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22e818 sub sp, sp, #60 */
/* @0x22e81c mov r4, r0 */
/* @0x22e820 mov r6, r3 */
/* @0x22e824 ldr r0, [r0, #0x24] */
/* @0x22e828 mov r11, r1 */
/* @0x22e82c ldr r3, [sp, #0x60] */
/* @0x22e830 ldr r10, [r1] */
/* @0x22e834 str r2, [sp, #0x24] */
/* @0x22e838 mul r0, r0, r3 */
/* @0x22e83c ldr r2, [r1, #0x14] */
/* @0x22e840 ldr r3, [r10] */
/* @0x22e844 ldr r1, [r10, #0x4] */
/* @0x22e848 ldr r2, [r2] */
/* @0x22e84c ldr r5, [r10, #0x8] */
/* @0x22e850 asr r0, r0, #1 */
/* @0x22e854 cmp r0, r1 */
/* @0x22e858 rsble r0, r3, r0 */
/* @0x22e85c rsbgt r0, r3, r1 */
/* @0x22e860 str r2, [sp, #0x1c] */
/* @0x22e864 cmp r0, #0 */
/* @0x22e868 ble 0x22e8e4 <res2_inverse+0xd0> */
/* @0x22e86c mov r1, r5 */
/* @0x22e870 bl 0x318d10 <__divsi3> */
/* @0x22e874 ldr lr, [sp, #0x1c] */
/* @0x22e878 mov r1, lr */
/* @0x22e87c mov r8, r0 */
/* @0x22e880 add r0, r0, lr */
/* @0x22e884 sub r0, r0, #1 */
/* @0x22e888 bl 0x318d10 <__divsi3> */
/* @0x22e88c lsl r1, r0, #2 */
/* @0x22e890 mov r0, r4 */
/* @0x22e894 bl 0x2270e4 <_vorbis_block_alloc> */
/* @0x22e898 ldr r1, [sp, #0x60] */
/* @0x22e89c mov r9, r0 */
/* @0x22e8a0 ldr r0, [r10] */
/* @0x22e8a4 bl 0x318d10 <__divsi3> */
/* @0x22e8a8 str r0, [sp, #0x34] */
/* @0x22e8ac ldr r0, [sp, #0x60] */
/* @0x22e8b0 cmp r0, #0 */
/* @0x22e8b4 ble 0x22e8f0 <res2_inverse+0xdc> */
/* @0x22e8b8 ldr r2, [r6] */
/* @0x22e8bc cmp r2, #0 */
/* @0x22e8c0 bne 0x22e8f4 <res2_inverse+0xe0> */
/* @0x22e8c4 mov r3, r6 */
/* @0x22e8c8 b 0x22e8d8 <res2_inverse+0xc4> */
/* @0x22e8cc ldr r1, [r3, #0x4]! */
/* @0x22e8d0 cmp r1, #0 */
/* @0x22e8d4 bne 0x22e8f4 <res2_inverse+0xe0> */
/* @0x22e8d8 add r2, r2, #1 */
/* @0x22e8dc cmp r2, r0 */
/* @0x22e8e0 bne 0x22e8cc <res2_inverse+0xb8> */
/* @0x22e8e4 mov r0, #0 */
/* @0x22e8e8 add sp, sp, #60 */
/* @0x22e8ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22e8f0 beq 0x22e8e4 <res2_inverse+0xd0> */
/* @0x22e8f4 mov r0, r5 */
/* @0x22e8f8 ldr r1, [sp, #0x60] */
/* @0x22e8fc bl 0x318d10 <__divsi3> */
/* @0x22e900 ldr r3, [r11, #0xc] */
/* @0x22e904 cmp r3, #0 */
/* @0x22e908 mov r7, r0 */
/* @0x22e90c ble 0x22e8e4 <res2_inverse+0xd0> */
/* @0x22e910 mov r12, r10 */
/* @0x22e914 mov r10, r8 */
/* @0x22e918 add r4, r4, #4 */
/* @0x22e91c mov r2, #0 */
/* @0x22e920 str r4, [sp, #0x2c] */
/* @0x22e924 str r2, [sp, #0x30] */
/* @0x22e928 cmp r10, #0 */
/* @0x22e92c ble 0x22ea18 <res2_inverse+0x204> */
/* @0x22e930 ldr r3, [sp, #0x30] */
/* @0x22e934 mov r8, #0 */
/* @0x22e938 mov r2, #1 */
/* @0x22e93c mov r5, r8 */
/* @0x22e940 lsl r2, r2, r3 */
/* @0x22e944 str r2, [sp, #0x20] */
/* @0x22e948 lsl r0, r3, #2 */
/* @0x22e94c str r0, [sp, #0x28] */
/* @0x22e950 ldr r3, [sp, #0x30] */
/* @0x22e954 cmp r3, #0 */
/* @0x22e958 beq 0x22ea30 <res2_inverse+0x21c> */
/* @0x22e95c ldr r0, [sp, #0x1c] */
/* @0x22e960 cmp r10, r5 */
/* @0x22e964 cmpgt r0, #0 */
/* @0x22e968 ble 0x22ea08 <res2_inverse+0x1f4> */
/* @0x22e96c ldr r2, [sp, #0x34] */
/* @0x22e970 mov r4, #0 */
/* @0x22e974 str r10, [sp, #0x14] */
/* @0x22e978 mla r6, r5, r7, r2 */
/* @0x22e97c ldr r3, [r9, r8] */
/* @0x22e980 add r5, r5, #1 */
/* @0x22e984 ldr r10, [sp, #0x20] */
/* @0x22e988 ldr r0, [r3, r4, lsl #2] */
/* @0x22e98c add r4, r4, #1 */
/* @0x22e990 add r3, r0, #6 */
/* @0x22e994 ldr r3, [r12, r3, lsl #2] */
/* @0x22e998 tst r10, r3 */
/* @0x22e99c beq 0x22e9ec <res2_inverse+0x1d8> */
/* @0x22e9a0 ldr r10, [r11, #0x18] */
/* @0x22e9a4 mov r2, r6 */
/* @0x22e9a8 ldr r1, [sp, #0x24] */
/* @0x22e9ac ldr r3, [sp, #0x60] */
/* @0x22e9b0 ldr r0, [r10, r0, lsl #2] */
/* @0x22e9b4 ldr r10, [sp, #0x28] */
/* @0x22e9b8 ldr r0, [r0, r10] */
/* @0x22e9bc cmp r0, #0 */
/* @0x22e9c0 beq 0x22e9ec <res2_inverse+0x1d8> */
/* @0x22e9c4 ldr r10, [sp, #0x2c] */
/* @0x22e9c8 mvn lr, #7 */
/* @0x22e9cc str r7, [sp, #0x4] */
/* @0x22e9d0 str lr, [sp, #0x8] */
/* @0x22e9d4 str r10, [sp] */
/* @0x22e9d8 str r12, [sp, #0x18] */
/* @0x22e9dc bl 0x228f20 <vorbis_book_decodevv_add> */
/* @0x22e9e0 ldr r12, [sp, #0x18] */
/* @0x22e9e4 cmn r0, #1 */
/* @0x22e9e8 beq 0x22e8e4 <res2_inverse+0xd0> */
/* @0x22e9ec ldr r10, [sp, #0x1c] */
/* @0x22e9f0 add r6, r6, r7 */
/* @0x22e9f4 ldr r0, [sp, #0x14] */
/* @0x22e9f8 cmp r10, r4 */
/* @0x22e9fc cmpgt r0, r5 */
/* @0x22ea00 bgt 0x22e97c <res2_inverse+0x168> */
/* @0x22ea04 mov r10, r0 */
/* @0x22ea08 cmp r10, r5 */
/* @0x22ea0c add r8, r8, #4 */
/* @0x22ea10 bgt 0x22e950 <res2_inverse+0x13c> */
/* @0x22ea14 ldr r3, [r11, #0xc] */
/* @0x22ea18 ldr r0, [sp, #0x30] */
/* @0x22ea1c add r0, r0, #1 */
/* @0x22ea20 str r0, [sp, #0x30] */
/* @0x22ea24 cmp r3, r0 */
/* @0x22ea28 bgt 0x22e928 <res2_inverse+0x114> */
/* @0x22ea2c b 0x22e8e4 <res2_inverse+0xd0> */
/* @0x22ea30 ldr r0, [r11, #0x14] */
/* @0x22ea34 ldr r1, [sp, #0x2c] */
/* @0x22ea38 str r12, [sp, #0x18] */
/* @0x22ea3c bl 0x2280d0 <vorbis_book_decode> */
/* @0x22ea40 ldr r12, [sp, #0x18] */
/* @0x22ea44 cmn r0, #1 */
/* @0x22ea48 beq 0x22e8e4 <res2_inverse+0xd0> */
/* @0x22ea4c ldr r3, [r12, #0x10] */
/* @0x22ea50 cmp r0, r3 */
/* @0x22ea54 bge 0x22e8e4 <res2_inverse+0xd0> */
/* @0x22ea58 ldr r3, [r11, #0x20] */
/* @0x22ea5c ldr r3, [r3, r0, lsl #2] */
/* @0x22ea60 cmp r3, #0 */
/* @0x22ea64 str r3, [r9, r8] */
/* @0x22ea68 bne 0x22e95c <res2_inverse+0x148> */
/* @0x22ea6c b 0x22e8e4 <res2_inverse+0xd0> */

/* ── FUNC 0x22ea70 · anon_22ea70 · size=128 · insn=32 */
/* @0x22ea70 rev r0, r0 */
/* @0x22ea74 movw r2, #0xf0f */
/* @0x22ea78 movw r3, #0xf0f0 */
/* @0x22ea7c bfi r2, r2, #16, #16 */
/* @0x22ea80 bfi r3, r3, #16, #16 */
/* @0x22ea84 and r2, r2, r0, lsr #4 */
/* @0x22ea88 and r0, r3, r0, lsl #4 */
/* @0x22ea8c movw r3, #0x3333 */
/* @0x22ea90 orr r0, r0, r2 */
/* @0x22ea94 bfi r3, r3, #16, #16 */
/* @0x22ea98 movw r2, #0xcccc */
/* @0x22ea9c bfi r2, r2, #16, #16 */
/* @0x22eaa0 and r3, r3, r0, lsr #2 */
/* @0x22eaa4 and r2, r2, r0, lsl #2 */
/* @0x22eaa8 orr r1, r2, r3 */
/* @0x22eaac movw r2, #0xaaaa */
/* @0x22eab0 movw r3, #0x5555 */
/* @0x22eab4 bfi r2, r2, #16, #16 */
/* @0x22eab8 bfi r3, r3, #16, #16 */
/* @0x22eabc and r2, r2, r1, lsl #1 */
/* @0x22eac0 and r0, r3, r1, lsr #1 */
/* @0x22eac4 orr r0, r2, r0 */
/* @0x22eac8 bx lr */
/* @0x22eacc ldr r3, [r0] */
/* @0x22ead0 ldr r1, [r1] */
/* @0x22ead4 ldr r2, [r3] */
/* @0x22ead8 ldr r3, [r1] */
/* @0x22eadc cmp r2, r3 */
/* @0x22eae0 movls r0, #0 */
/* @0x22eae4 movhi r0, #1 */
/* @0x22eae8 sublo r0, r0, #1 */
/* @0x22eaec bx lr */

/* ── FUNC 0x22eaf0 · _ilog · size=36 · insn=9 */
/* @0x22eaf0 subs r3, r0, #0 */
/* @0x22eaf4 beq 0x22eb0c <_ilog+0x1c> */
/* @0x22eaf8 mov r0, #0 */
/* @0x22eafc lsrs r3, r3, #1 */
/* @0x22eb00 add r0, r0, #1 */
/* @0x22eb04 bne 0x22eafc <_ilog+0xc> */
/* @0x22eb08 bx lr */
/* @0x22eb0c mov r0, r3 */
/* @0x22eb10 bx lr */

/* ── FUNC 0x22eb14 · _make_words · size=628 · insn=157 */
/* @0x22eb14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22eb18 cmp r2, #0 */
/* @0x22eb1c sub sp, sp, #164 */
/* @0x22eb20 add r9, sp, #28 */
/* @0x22eb24 str r1, [sp, #0x10] */
/* @0x22eb28 ldreq r3, [sp, #0x10] */
/* @0x22eb2c str r0, [sp, #0x14] */
/* @0x22eb30 lslne r0, r2, #2 */
/* @0x22eb34 str r2, [sp, #0xc] */
/* @0x22eb38 lsleq r0, r3, #2 */
/* @0x22eb3c bl 0xb6544 <malloc@plt> */
/* @0x22eb40 mov r1, #0 */
/* @0x22eb44 mov r2, #132 */
/* @0x22eb48 mov r8, r0 */
/* @0x22eb4c mov r0, r9 */
/* @0x22eb50 bl 0xb65b0 <memset@plt> */
/* @0x22eb54 ldr r3, [sp, #0x10] */
/* @0x22eb58 cmp r3, #0 */
/* @0x22eb5c ble 0x22ec6c <_make_words+0x158> */
/* @0x22eb60 ldr r3, [sp, #0x14] */
/* @0x22eb64 mov r7, #0 */
/* @0x22eb68 str r8, [sp, #0x8] */
/* @0x22eb6c add r12, sp, #152 */
/* @0x22eb70 sub r10, r3, #4 */
/* @0x22eb74 mov r6, r7 */
/* @0x22eb78 ldr r8, [sp, #0x10] */
/* @0x22eb7c ldr r0, [r10, #0x4]! */
/* @0x22eb80 cmp r0, #0 */
/* @0x22eb84 ble 0x22ec4c <_make_words+0x138> */
/* @0x22eb88 add r1, sp, #160 */
/* @0x22eb8c cmp r0, #31 */
/* @0x22eb90 add r3, r1, r0, lsl #2 */
/* @0x22eb94 ldr r4, [r3, #-0x84] */
/* @0x22eb98 bgt 0x22eba4 <_make_words+0x90> */
/* @0x22eb9c lsrs r2, r4, r0 */
/* @0x22eba0 bne 0x22ed70 <_make_words+0x25c> */
/* @0x22eba4 ldr r2, [sp, #0x8] */
/* @0x22eba8 sub r5, r0, #1 */
/* @0x22ebac add r11, r7, #1 */
/* @0x22ebb0 str r4, [sp, #0x4] */
/* @0x22ebb4 mov r3, r0 */
/* @0x22ebb8 add r1, r9, r5, lsl #2 */
/* @0x22ebbc str r4, [r2, r7, lsl #2] */
/* @0x22ebc0 mov r2, r4 */
/* @0x22ebc4 b 0x22ebcc <_make_words+0xb8> */
/* @0x22ebc8 ldr r2, [r1], #-4 */
/* @0x22ebcc tst r2, #1 */
/* @0x22ebd0 add r2, r2, #1 */
/* @0x22ebd4 bne 0x22ecb0 <_make_words+0x19c> */
/* @0x22ebd8 subs r3, r3, #1 */
/* @0x22ebdc str r2, [r1, #0x4] */
/* @0x22ebe0 bne 0x22ebc8 <_make_words+0xb4> */
/* @0x22ebe4 add r0, r0, #1 */
/* @0x22ebe8 cmp r0, #32 */
/* @0x22ebec bgt 0x22ec30 <_make_words+0x11c> */
/* @0x22ebf0 add r2, sp, #160 */
/* @0x22ebf4 add r0, r2, r0, lsl #2 */
/* @0x22ebf8 ldr r2, [r0, #-0x84] */
/* @0x22ebfc cmp r4, r2, lsr #1 */
/* @0x22ec00 bne 0x22ec30 <_make_words+0x11c> */
/* @0x22ec04 add r5, r9, r5, lsl #2 */
/* @0x22ec08 b 0x22ec1c <_make_words+0x108> */
/* @0x22ec0c ldr r3, [r5, #0x8] */
/* @0x22ec10 cmp r2, r3, lsr #1 */
/* @0x22ec14 mov r2, r3 */
/* @0x22ec18 bne 0x22ec30 <_make_words+0x11c> */
/* @0x22ec1c ldr r3, [r5, #0x4]! */
/* @0x22ec20 cmp r5, r12 */
/* @0x22ec24 lsl r3, r3, #1 */
/* @0x22ec28 str r3, [r5, #0x4] */
/* @0x22ec2c bne 0x22ec0c <_make_words+0xf8> */
/* @0x22ec30 add r6, r6, #1 */
/* @0x22ec34 cmp r6, r8 */
/* @0x22ec38 beq 0x22ec68 <_make_words+0x154> */
/* @0x22ec3c ldr r0, [r10, #0x4]! */
/* @0x22ec40 mov r7, r11 */
/* @0x22ec44 cmp r0, #0 */
/* @0x22ec48 bgt 0x22eb88 <_make_words+0x74> */
/* @0x22ec4c ldr r3, [sp, #0xc] */
/* @0x22ec50 add r6, r6, #1 */
/* @0x22ec54 cmp r3, #0 */
/* @0x22ec58 addeq r11, r7, #1 */
/* @0x22ec5c movne r11, r7 */
/* @0x22ec60 cmp r6, r8 */
/* @0x22ec64 bne 0x22ec3c <_make_words+0x128> */
/* @0x22ec68 ldr r8, [sp, #0x8] */
/* @0x22ec6c ldr r3, [sp, #0xc] */
/* @0x22ec70 cmp r3, #1 */
/* @0x22ec74 movne r3, #31 */
/* @0x22ec78 mvnne r1, #0 */
/* @0x22ec7c bne 0x22ec8c <_make_words+0x178> */
/* @0x22ec80 b 0x22ecdc <_make_words+0x1c8> */
/* @0x22ec84 cmn r3, #1 */
/* @0x22ec88 beq 0x22ecdc <_make_words+0x1c8> */
/* @0x22ec8c ldr r2, [r9, #0x4]! */
/* @0x22ec90 ands r2, r2, r1, lsr r3 */
/* @0x22ec94 sub r3, r3, #1 */
/* @0x22ec98 beq 0x22ec84 <_make_words+0x170> */
/* @0x22ec9c mov r0, r8 */
/* @0x22eca0 bl 0xb655c <free@plt> */
/* @0x22eca4 mov r0, #0 */
/* @0x22eca8 add sp, sp, #164 */
/* @0x22ecac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22ecb0 cmp r3, #1 */
/* @0x22ecb4 addne r1, sp, #160 */
/* @0x22ecb8 addne r2, r1, r3, lsl #2 */
/* @0x22ecbc ldreq r3, [sp, #0x20] */
/* @0x22ecc0 movne r3, r2 */
/* @0x22ecc4 ldrne r2, [r2, #-0x88] */
/* @0x22ecc8 addeq r3, r3, #1 */
/* @0x22eccc streq r3, [sp, #0x20] */
/* @0x22ecd0 lslne r2, r2, #1 */
/* @0x22ecd4 strne r2, [r3, #-0x84] */
/* @0x22ecd8 b 0x22ebe4 <_make_words+0xd0> */
/* @0x22ecdc ldr r3, [sp, #0x10] */
/* @0x22ece0 cmp r3, #0 */
/* @0x22ece4 ble 0x22ed3c <_make_words+0x228> */
/* @0x22ece8 ldr r5, [sp, #0x14] */
/* @0x22ecec mov r4, #0 */
/* @0x22ecf0 ldr r9, [sp, #0xc] */
/* @0x22ecf4 add r7, r5, r3, lsl #2 */
/* @0x22ecf8 ldr r0, [r5], #4 */
/* @0x22ecfc cmp r0, #0 */
/* @0x22ed00 ble 0x22ed48 <_make_words+0x234> */
/* @0x22ed04 ldr r12, [r8, r4, lsl #2] */
/* @0x22ed08 mov r2, #0 */
/* @0x22ed0c add r6, r8, r4, lsl #2 */
/* @0x22ed10 mov r3, r2 */
/* @0x22ed14 lsr r1, r12, r3 */
/* @0x22ed18 add r3, r3, #1 */
/* @0x22ed1c cmp r3, r0 */
/* @0x22ed20 and r1, r1, #1 */
/* @0x22ed24 orr r2, r1, r2, lsl #1 */
/* @0x22ed28 bne 0x22ed14 <_make_words+0x200> */
/* @0x22ed2c add r4, r4, #1 */
/* @0x22ed30 str r2, [r6] */
/* @0x22ed34 cmp r5, r7 */
/* @0x22ed38 bne 0x22ecf8 <_make_words+0x1e4> */
/* @0x22ed3c mov r0, r8 */
/* @0x22ed40 add sp, sp, #164 */
/* @0x22ed44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22ed48 cmp r9, #0 */
/* @0x22ed4c beq 0x22ed64 <_make_words+0x250> */
/* @0x22ed50 cmp r0, #0 */
/* @0x22ed54 addne r6, r8, r4, lsl #2 */
/* @0x22ed58 movne r2, #0 */
/* @0x22ed5c bne 0x22ed2c <_make_words+0x218> */
/* @0x22ed60 b 0x22ed34 <_make_words+0x220> */
/* @0x22ed64 add r6, r8, r4, lsl #2 */
/* @0x22ed68 mov r2, r9 */
/* @0x22ed6c b 0x22ed2c <_make_words+0x218> */
/* @0x22ed70 ldr r8, [sp, #0x8] */
/* @0x22ed74 mov r0, r8 */
/* @0x22ed78 bl 0xb655c <free@plt> */
/* @0x22ed7c mov r0, #0 */
/* @0x22ed80 add sp, sp, #164 */
/* @0x22ed84 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x22ed88 · _book_maptype1_quantvals · size=144 · insn=36 */
/* @0x22ed88 push {r3, r4, r5, lr} */
/* @0x22ed8c mov r5, r0 */
/* @0x22ed90 ldr r0, [r0, #0x4] */
/* @0x22ed94 bl 0x22eaf0 <_ilog> */
/* @0x22ed98 ldm r5, {r4, r5} */
/* @0x22ed9c sub r3, r4, #1 */
/* @0x22eda0 mov r1, r4 */
/* @0x22eda4 sub r0, r0, #1 */
/* @0x22eda8 mul r0, r3, r0 */
/* @0x22edac bl 0x318d10 <__divsi3> */
/* @0x22edb0 asr r0, r5, r0 */
/* @0x22edb4 cmp r4, #0 */
/* @0x22edb8 mov r2, #1 */
/* @0x22edbc ble 0x22ee00 <_book_maptype1_quantvals+0x78> */
/* @0x22edc0 add r1, r0, r2 */
/* @0x22edc4 mov r12, r2 */
/* @0x22edc8 mov r3, #0 */
/* @0x22edcc add r3, r3, #1 */
/* @0x22edd0 cmp r3, r4 */
/* @0x22edd4 mul r12, r0, r12 */
/* @0x22edd8 mul r2, r1, r2 */
/* @0x22eddc bne 0x22edcc <_book_maptype1_quantvals+0x44> */
/* @0x22ede0 cmp r5, r12 */
/* @0x22ede4 blt 0x22ee0c <_book_maptype1_quantvals+0x84> */
/* @0x22ede8 cmp r5, r2 */
/* @0x22edec blt 0x22ee14 <_book_maptype1_quantvals+0x8c> */
/* @0x22edf0 cmp r4, #0 */
/* @0x22edf4 add r0, r0, #1 */
/* @0x22edf8 mov r2, #1 */
/* @0x22edfc bgt 0x22edc0 <_book_maptype1_quantvals+0x38> */
/* @0x22ee00 mov r12, r2 */
/* @0x22ee04 cmp r5, r12 */
/* @0x22ee08 bge 0x22ede8 <_book_maptype1_quantvals+0x60> */
/* @0x22ee0c sub r0, r0, #1 */
/* @0x22ee10 b 0x22edb4 <_book_maptype1_quantvals+0x2c> */
/* @0x22ee14 pop {r3, r4, r5, pc} */

/* ── FUNC 0x22ee18 · _book_unquantize · size=1852 · insn=463 */
/* @0x22ee18 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x22ee1c sub sp, sp, #60 */
/* @0x22ee20 mov r4, r0 */
/* @0x22ee24 str r1, [sp, #0x30] */
/* @0x22ee28 ldr r1, [r0, #0xc] */
/* @0x22ee2c str r2, [sp, #0x8] */
/* @0x22ee30 sub r1, r1, #1 */
/* @0x22ee34 str r3, [sp, #0x14] */
/* @0x22ee38 cmp r1, #1 */
/* @0x22ee3c movhi r0, #0 */
/* @0x22ee40 bhi 0x22f130 <_book_unquantize+0x318> */
/* @0x22ee44 ldr r3, [r4, #0x10] */
/* @0x22ee48 ubfx r2, r3, #0x0, #0x15 */
/* @0x22ee4c str r2, [sp, #0x1c] */
/* @0x22ee50 cmp r2, #0 */
/* @0x22ee54 bne 0x22f138 <_book_unquantize+0x320> */
/* @0x22ee58 movw r3, #0xd8f1 */
/* @0x22ee5c movt r3, #0xffff */
/* @0x22ee60 str r3, [sp, #0x28] */
/* @0x22ee64 ldr r3, [r4, #0x14] */
/* @0x22ee68 ubfx r12, r3, #0x0, #0x15 */
/* @0x22ee6c str r12, [sp, #0x18] */
/* @0x22ee70 cmp r12, #0 */
/* @0x22ee74 beq 0x22f234 <_book_unquantize+0x41c> */
/* @0x22ee78 ubfx r2, r3, #0x15, #0xa */
/* @0x22ee7c sub r2, r2, #788 */
/* @0x22ee80 str r2, [sp, #0x24] */
/* @0x22ee84 ldr r1, [sp, #0x24] */
/* @0x22ee88 mov r2, r12 */
/* @0x22ee8c lsl r2, r2, #1 */
/* @0x22ee90 sub r1, r1, #1 */
/* @0x22ee94 tst r2, #1073741824 */
/* @0x22ee98 beq 0x22ee8c <_book_unquantize+0x74> */
/* @0x22ee9c cmp r3, #0 */
/* @0x22eea0 str r2, [sp, #0x18] */
/* @0x22eea4 str r1, [sp, #0x24] */
/* @0x22eea8 rsblt r2, r2, #0 */
/* @0x22eeac strlt r2, [sp, #0x18] */
/* @0x22eeb0 ldr r12, [sp, #0x30] */
/* @0x22eeb4 mov r1, #4 */
/* @0x22eeb8 ldr r8, [r4] */
/* @0x22eebc mul r5, r12, r8 */
/* @0x22eec0 mov r0, r5 */
/* @0x22eec4 bl 0xb6c34 <calloc@plt> */
/* @0x22eec8 mov r1, #4 */
/* @0x22eecc str r0, [sp, #0xc] */
/* @0x22eed0 mov r0, r5 */
/* @0x22eed4 bl 0xb6c34 <calloc@plt> */
/* @0x22eed8 ldr r2, [sp, #0x28] */
/* @0x22eedc ldr r3, [sp, #0x14] */
/* @0x22eee0 str r2, [r3] */
/* @0x22eee4 ldr r7, [r4, #0xc] */
/* @0x22eee8 cmp r7, #1 */
/* @0x22eeec mov r6, r0 */
/* @0x22eef0 beq 0x22f244 <_book_unquantize+0x42c> */
/* @0x22eef4 cmp r7, #2 */
/* @0x22eef8 bne 0x22f0e4 <_book_unquantize+0x2cc> */
/* @0x22eefc ldr r1, [r4, #0x4] */
/* @0x22ef00 cmp r1, #0 */
/* @0x22ef04 ble 0x22f0e4 <_book_unquantize+0x2cc> */
/* @0x22ef08 ldr r3, [sp, #0x1c] */
/* @0x22ef0c mov r2, #0 */
/* @0x22ef10 ldr r6, [sp, #0x14] */
/* @0x22ef14 mov r5, r2 */
/* @0x22ef18 str r2, [sp, #0x20] */
/* @0x22ef1c asr r3, r3, #1 */
/* @0x22ef20 str r3, [sp, #0x2c] */
/* @0x22ef24 mov r3, r8 */
/* @0x22ef28 str r0, [sp, #0x10] */
/* @0x22ef2c ldr r12, [sp, #0x8] */
/* @0x22ef30 cmp r12, #0 */
/* @0x22ef34 beq 0x22ef48 <_book_unquantize+0x130> */
/* @0x22ef38 ldr r2, [r4, #0x8] */
/* @0x22ef3c ldr r2, [r2, r5, lsl #2] */
/* @0x22ef40 cmp r2, #0 */
/* @0x22ef44 beq 0x22f0cc <_book_unquantize+0x2b4> */
/* @0x22ef48 cmp r3, #0 */
/* @0x22ef4c ble 0x22f0c0 <_book_unquantize+0x2a8> */
/* @0x22ef50 ldr r12, [sp, #0x20] */
/* @0x22ef54 mov r8, #0 */
/* @0x22ef58 ldr r1, [sp, #0x18] */
/* @0x22ef5c mov r11, r8 */
/* @0x22ef60 ldr r2, [sp, #0x8] */
/* @0x22ef64 mov r10, r8 */
/* @0x22ef68 subs r1, r1, r8 */
/* @0x22ef6c add r9, r2, r12, lsl #2 */
/* @0x22ef70 movne r1, #1 */
/* @0x22ef74 str r1, [sp, #0x4] */
/* @0x22ef78 mla r3, r3, r5, r10 */
/* @0x22ef7c ldr r2, [r4, #0x20] */
/* @0x22ef80 ldr r2, [r2, r3, lsl #2] */
/* @0x22ef84 eor r7, r2, r2, asr #31 */
/* @0x22ef88 sub r7, r7, r2, asr #31 */
/* @0x22ef8c mov r0, r7 */
/* @0x22ef90 bl 0x22eaf0 <_ilog> */
/* @0x22ef94 ldr r1, [sp, #0x4] */
/* @0x22ef98 sub r0, r0, #31 */
/* @0x22ef9c rsb r3, r0, #0 */
/* @0x22efa0 lsls r2, r7, r3 */
/* @0x22efa4 moveq r3, #0 */
/* @0x22efa8 andne r3, r1, #1 */
/* @0x22efac cmp r3, #0 */
/* @0x22efb0 beq 0x22f53c <_book_unquantize+0x724> */
/* @0x22efb4 ldr r12, [sp, #0x18] */
/* @0x22efb8 smull r2, r3, r12, r2 */
/* @0x22efbc ldr r12, [sp, #0x1c] */
/* @0x22efc0 cmp r12, #0 */
/* @0x22efc4 ldr r12, [sp, #0x24] */
/* @0x22efc8 add r0, r12, r0 */
/* @0x22efcc add r1, r0, #32 */
/* @0x22efd0 mov lr, r3 */
/* @0x22efd4 beq 0x22f048 <_book_unquantize+0x230> */
/* @0x22efd8 cmp r3, #0 */
/* @0x22efdc bne 0x22eff4 <_book_unquantize+0x1dc> */
/* @0x22efe0 cmp r11, #0 */
/* @0x22efe4 bne 0x22f174 <_book_unquantize+0x35c> */
/* @0x22efe8 ldr r1, [sp, #0x28] */
/* @0x22efec ldr lr, [sp, #0x1c] */
/* @0x22eff0 b 0x22f060 <_book_unquantize+0x248> */
/* @0x22eff4 ldr r12, [sp, #0x28] */
/* @0x22eff8 cmp r12, r1 */
/* @0x22effc ble 0x22f1f8 <_book_unquantize+0x3e0> */
/* @0x22f000 rsb lr, r1, r12 */
/* @0x22f004 add r1, r12, #1 */
/* @0x22f008 add r0, lr, #1 */
/* @0x22f00c cmp r0, #31 */
/* @0x22f010 bgt 0x22f228 <_book_unquantize+0x410> */
/* @0x22f014 mov r12, #1 */
/* @0x22f018 add r3, r3, r12, lsl lr */
/* @0x22f01c ldr lr, [sp, #0x2c] */
/* @0x22f020 asr r3, r3, r0 */
/* @0x22f024 add lr, lr, r3 */
/* @0x22f028 ands r2, lr, #-1073741824 */
/* @0x22f02c movne r3, #0 */
/* @0x22f030 moveq r3, #1 */
/* @0x22f034 cmp r2, #-1073741824 */
/* @0x22f038 orreq r3, r3, #1 */
/* @0x22f03c cmp r3, #0 */
/* @0x22f040 lslne lr, lr, #1 */
/* @0x22f044 subne r1, r1, #1 */
/* @0x22f048 cmp r11, #0 */
/* @0x22f04c beq 0x22f060 <_book_unquantize+0x248> */
/* @0x22f050 cmp lr, #0 */
/* @0x22f054 moveq r1, r8 */
/* @0x22f058 moveq lr, r11 */
/* @0x22f05c bne 0x22f17c <_book_unquantize+0x364> */
/* @0x22f060 ldr r3, [r4, #0x1c] */
/* @0x22f064 ldr r2, [sp, #0x8] */
/* @0x22f068 cmp r3, #0 */
/* @0x22f06c movne r8, r1 */
/* @0x22f070 movne r11, lr */
/* @0x22f074 cmp r2, #0 */
/* @0x22f078 ldrne r2, [r4] */
/* @0x22f07c ldreq r3, [r4] */
/* @0x22f080 ldrne r0, [r9] */
/* @0x22f084 ldreq r12, [sp, #0x20] */
/* @0x22f088 movne r3, r2 */
/* @0x22f08c mlane r2, r0, r2, r10 */
/* @0x22f090 mlaeq r2, r12, r3, r10 */
/* @0x22f094 ldr r12, [sp, #0xc] */
/* @0x22f098 add r10, r10, #1 */
/* @0x22f09c str lr, [r12, r2, lsl #2] */
/* @0x22f0a0 ldr r12, [sp, #0x10] */
/* @0x22f0a4 str r1, [r12, r2, lsl #2] */
/* @0x22f0a8 ldr r2, [r6] */
/* @0x22f0ac cmp r2, r1 */
/* @0x22f0b0 strlt r1, [r6] */
/* @0x22f0b4 cmp r10, r3 */
/* @0x22f0b8 blt 0x22ef78 <_book_unquantize+0x160> */
/* @0x22f0bc ldr r1, [r4, #0x4] */
/* @0x22f0c0 ldr r2, [sp, #0x20] */
/* @0x22f0c4 add r2, r2, #1 */
/* @0x22f0c8 str r2, [sp, #0x20] */
/* @0x22f0cc add r5, r5, #1 */
/* @0x22f0d0 cmp r1, r5 */
/* @0x22f0d4 bgt 0x22ef2c <_book_unquantize+0x114> */
/* @0x22f0d8 ldr r12, [sp, #0x30] */
/* @0x22f0dc ldr r6, [sp, #0x10] */
/* @0x22f0e0 mul r5, r3, r12 */
/* @0x22f0e4 cmp r5, #0 */
/* @0x22f0e8 ble 0x22f124 <_book_unquantize+0x30c> */
/* @0x22f0ec ldr r2, [sp, #0x14] */
/* @0x22f0f0 lsl r5, r5, #2 */
/* @0x22f0f4 mov r1, #0 */
/* @0x22f0f8 ldr r12, [r2] */
/* @0x22f0fc ldr r2, [sp, #0xc] */
/* @0x22f100 ldr r3, [r6, r1] */
/* @0x22f104 cmp r3, r12 */
/* @0x22f108 rsb r3, r3, r12 */
/* @0x22f10c ldrlt r0, [r2, r1] */
/* @0x22f110 asrlt r3, r0, r3 */
/* @0x22f114 strlt r3, [r2, r1] */
/* @0x22f118 add r1, r1, #4 */
/* @0x22f11c cmp r1, r5 */
/* @0x22f120 bne 0x22f100 <_book_unquantize+0x2e8> */
/* @0x22f124 mov r0, r6 */
/* @0x22f128 bl 0xb655c <free@plt> */
/* @0x22f12c ldr r0, [sp, #0xc] */
/* @0x22f130 add sp, sp, #60 */
/* @0x22f134 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x22f138 ubfx r2, r3, #0x15, #0xa */
/* @0x22f13c sub r2, r2, #788 */
/* @0x22f140 str r2, [sp, #0x28] */
/* @0x22f144 ldr r1, [sp, #0x28] */
/* @0x22f148 ldr r2, [sp, #0x1c] */
/* @0x22f14c lsl r2, r2, #1 */
/* @0x22f150 sub r1, r1, #1 */
/* @0x22f154 tst r2, #1073741824 */
/* @0x22f158 beq 0x22f14c <_book_unquantize+0x334> */
/* @0x22f15c cmp r3, #0 */
/* @0x22f160 str r2, [sp, #0x1c] */
/* @0x22f164 str r1, [sp, #0x28] */
/* @0x22f168 rsblt r2, r2, #0 */
/* @0x22f16c strlt r2, [sp, #0x1c] */
/* @0x22f170 b 0x22ee64 <_book_unquantize+0x4c> */
/* @0x22f174 ldr lr, [sp, #0x1c] */
/* @0x22f178 ldr r1, [sp, #0x28] */
/* @0x22f17c cmp r1, r8 */
/* @0x22f180 bge 0x22f1d0 <_book_unquantize+0x3b8> */
/* @0x22f184 rsb r0, r1, r8 */
/* @0x22f188 asr r3, r11, #1 */
/* @0x22f18c add r2, r0, #1 */
/* @0x22f190 add r1, r8, #1 */
/* @0x22f194 cmp r2, #31 */
/* @0x22f198 movgt lr, #0 */
/* @0x22f19c movle r12, #1 */
/* @0x22f1a0 addle lr, lr, r12, lsl r0 */
/* @0x22f1a4 asrle lr, lr, r2 */
/* @0x22f1a8 add lr, r3, lr */
/* @0x22f1ac ands r2, lr, #-1073741824 */
/* @0x22f1b0 movne r3, #0 */
/* @0x22f1b4 moveq r3, #1 */
/* @0x22f1b8 cmp r2, #-1073741824 */
/* @0x22f1bc orreq r3, r3, #1 */
/* @0x22f1c0 cmp r3, #0 */
/* @0x22f1c4 lslne lr, lr, #1 */
/* @0x22f1c8 subne r1, r1, #1 */
/* @0x22f1cc b 0x22f060 <_book_unquantize+0x248> */
/* @0x22f1d0 rsb r2, r8, r1 */
/* @0x22f1d4 asr lr, lr, #1 */
/* @0x22f1d8 add r3, r2, #1 */
/* @0x22f1dc add r1, r1, #1 */
/* @0x22f1e0 cmp r3, #31 */
/* @0x22f1e4 movle r0, #1 */
/* @0x22f1e8 movgt r3, #0 */
/* @0x22f1ec addle r2, r11, r0, lsl r2 */
/* @0x22f1f0 asrle r3, r2, r3 */
/* @0x22f1f4 b 0x22f1a8 <_book_unquantize+0x390> */
/* @0x22f1f8 ldr r12, [sp, #0x28] */
/* @0x22f1fc asr r3, r3, #1 */
/* @0x22f200 rsb r2, r12, r1 */
/* @0x22f204 add r1, r0, #33 */
/* @0x22f208 add lr, r2, #1 */
/* @0x22f20c cmp lr, #31 */
/* @0x22f210 movgt lr, #0 */
/* @0x22f214 ldrle r12, [sp, #0x1c] */
/* @0x22f218 movle r0, #1 */
/* @0x22f21c addle r2, r12, r0, lsl r2 */
/* @0x22f220 asrle lr, r2, lr */
/* @0x22f224 b 0x22f024 <_book_unquantize+0x20c> */
/* @0x22f228 ldr lr, [sp, #0x2c] */
/* @0x22f22c mov r3, #0 */
/* @0x22f230 b 0x22f024 <_book_unquantize+0x20c> */
/* @0x22f234 movw r2, #0xd8f1 */
/* @0x22f238 movt r2, #0xffff */
/* @0x22f23c str r2, [sp, #0x24] */
/* @0x22f240 b 0x22eeb0 <_book_unquantize+0x98> */
/* @0x22f244 mov r0, r4 */
/* @0x22f248 bl 0x22ed88 <_book_maptype1_quantvals> */
/* @0x22f24c ldr r1, [r4, #0x4] */
/* @0x22f250 cmp r1, #0 */
/* @0x22f254 mov r8, r0 */
/* @0x22f258 ble 0x22f514 <_book_unquantize+0x6fc> */
/* @0x22f25c ldr r12, [sp, #0x1c] */
/* @0x22f260 mov r3, #0 */
/* @0x22f264 ldr r2, [r4] */
/* @0x22f268 str r3, [sp, #0x2c] */
/* @0x22f26c asr r12, r12, #1 */
/* @0x22f270 str r3, [sp, #0x4] */
/* @0x22f274 str r12, [sp, #0x34] */
/* @0x22f278 str r6, [sp, #0x20] */
/* @0x22f27c ldr r12, [sp, #0x8] */
/* @0x22f280 cmp r12, #0 */
/* @0x22f284 beq 0x22f29c <_book_unquantize+0x484> */
/* @0x22f288 ldr r3, [r4, #0x8] */
/* @0x22f28c ldr r12, [sp, #0x4] */
/* @0x22f290 ldr r3, [r3, r12, lsl #2] */
/* @0x22f294 cmp r3, #0 */
/* @0x22f298 beq 0x22f48c <_book_unquantize+0x674> */
/* @0x22f29c cmp r2, #0 */
/* @0x22f2a0 ble 0x22f480 <_book_unquantize+0x668> */
/* @0x22f2a4 ldr r2, [sp, #0x18] */
/* @0x22f2a8 mov r9, #0 */
/* @0x22f2ac ldr r12, [sp, #0x8] */
/* @0x22f2b0 mov r6, r9 */
/* @0x22f2b4 subs r2, r2, r9 */
/* @0x22f2b8 mov r5, r9 */
/* @0x22f2bc mov r11, #1 */
/* @0x22f2c0 movne r2, #1 */
/* @0x22f2c4 str r2, [sp, #0x10] */
/* @0x22f2c8 ldr r2, [sp, #0x2c] */
/* @0x22f2cc add r10, r12, r2, lsl #2 */
/* @0x22f2d0 ldr r0, [sp, #0x4] */
/* @0x22f2d4 mov r1, r11 */
/* @0x22f2d8 bl 0x318d10 <__divsi3> */
/* @0x22f2dc mov r1, r8 */
/* @0x22f2e0 bl 0x318dec <__aeabi_idivmod> */
/* @0x22f2e4 ldr r3, [r4, #0x20] */
/* @0x22f2e8 ldr r2, [r3, r1, lsl #2] */
/* @0x22f2ec eor r7, r2, r2, asr #31 */
/* @0x22f2f0 sub r7, r7, r2, asr #31 */
/* @0x22f2f4 mov r0, r7 */
/* @0x22f2f8 bl 0x22eaf0 <_ilog> */
/* @0x22f2fc sub r0, r0, #31 */
/* @0x22f300 rsb r3, r0, #0 */
/* @0x22f304 lsls r2, r7, r3 */
/* @0x22f308 ldr r3, [sp, #0x10] */
/* @0x22f30c moveq r1, #0 */
/* @0x22f310 andne r1, r3, #1 */
/* @0x22f314 cmp r1, #0 */
/* @0x22f318 beq 0x22f524 <_book_unquantize+0x70c> */
/* @0x22f31c ldr r12, [sp, #0x18] */
/* @0x22f320 smull r2, r3, r12, r2 */
/* @0x22f324 ldr r12, [sp, #0x1c] */
/* @0x22f328 cmp r12, #0 */
/* @0x22f32c ldr r12, [sp, #0x24] */
/* @0x22f330 add r0, r12, r0 */
/* @0x22f334 add r1, r0, #32 */
/* @0x22f338 mov lr, r3 */
/* @0x22f33c beq 0x22f400 <_book_unquantize+0x5e8> */
/* @0x22f340 cmp r3, #0 */
/* @0x22f344 bne 0x22f3ac <_book_unquantize+0x594> */
/* @0x22f348 cmp r6, #0 */
/* @0x22f34c ldr r1, [sp, #0x28] */
/* @0x22f350 ldr lr, [sp, #0x1c] */
/* @0x22f354 beq 0x22f418 <_book_unquantize+0x600> */
/* @0x22f358 cmp r1, r9 */
/* @0x22f35c bge 0x22f4b0 <_book_unquantize+0x698> */
/* @0x22f360 rsb r0, r1, r9 */
/* @0x22f364 asr r3, r6, #1 */
/* @0x22f368 add r2, r0, #1 */
/* @0x22f36c add r1, r9, #1 */
/* @0x22f370 cmp r2, #31 */
/* @0x22f374 movgt lr, #0 */
/* @0x22f378 movle r12, #1 */
/* @0x22f37c addle lr, lr, r12, lsl r0 */
/* @0x22f380 asrle lr, lr, r2 */
/* @0x22f384 add lr, r3, lr */
/* @0x22f388 ands r2, lr, #-1073741824 */
/* @0x22f38c movne r3, #0 */
/* @0x22f390 moveq r3, #1 */
/* @0x22f394 cmp r2, #-1073741824 */
/* @0x22f398 orreq r3, r3, #1 */
/* @0x22f39c cmp r3, #0 */
/* @0x22f3a0 lslne lr, lr, #1 */
/* @0x22f3a4 subne r1, r1, #1 */
/* @0x22f3a8 b 0x22f418 <_book_unquantize+0x600> */
/* @0x22f3ac ldr r12, [sp, #0x28] */
/* @0x22f3b0 cmp r12, r1 */
/* @0x22f3b4 ble 0x22f4d8 <_book_unquantize+0x6c0> */
/* @0x22f3b8 rsb lr, r1, r12 */
/* @0x22f3bc add r1, r12, #1 */
/* @0x22f3c0 add r0, lr, #1 */
/* @0x22f3c4 cmp r0, #31 */
/* @0x22f3c8 bgt 0x22f508 <_book_unquantize+0x6f0> */
/* @0x22f3cc mov r12, #1 */
/* @0x22f3d0 add r3, r3, r12, lsl lr */
/* @0x22f3d4 ldr lr, [sp, #0x34] */
/* @0x22f3d8 asr r3, r3, r0 */
/* @0x22f3dc add lr, lr, r3 */
/* @0x22f3e0 ands r2, lr, #-1073741824 */
/* @0x22f3e4 movne r3, #0 */
/* @0x22f3e8 moveq r3, #1 */
/* @0x22f3ec cmp r2, #-1073741824 */
/* @0x22f3f0 orreq r3, r3, #1 */
/* @0x22f3f4 cmp r3, #0 */
/* @0x22f3f8 lslne lr, lr, #1 */
/* @0x22f3fc subne r1, r1, #1 */
/* @0x22f400 cmp r6, #0 */
/* @0x22f404 beq 0x22f418 <_book_unquantize+0x600> */
/* @0x22f408 cmp lr, #0 */
/* @0x22f40c moveq r1, r9 */
/* @0x22f410 moveq lr, r6 */
/* @0x22f414 bne 0x22f358 <_book_unquantize+0x540> */
/* @0x22f418 ldr r3, [r4, #0x1c] */
/* @0x22f41c ldr r2, [sp, #0x8] */
/* @0x22f420 cmp r3, #0 */
/* @0x22f424 mul r11, r8, r11 */
/* @0x22f428 movne r9, r1 */
/* @0x22f42c movne r6, lr */
/* @0x22f430 cmp r2, #0 */
/* @0x22f434 ldrne r3, [r4] */
/* @0x22f438 ldreq r2, [r4] */
/* @0x22f43c ldrne r0, [r10] */
/* @0x22f440 ldreq r12, [sp, #0x2c] */
/* @0x22f444 movne r2, r3 */
/* @0x22f448 mlane r3, r0, r3, r5 */
/* @0x22f44c mlaeq r3, r12, r2, r5 */
/* @0x22f450 ldr r12, [sp, #0xc] */
/* @0x22f454 add r5, r5, #1 */
/* @0x22f458 str lr, [r12, r3, lsl #2] */
/* @0x22f45c ldr r12, [sp, #0x20] */
/* @0x22f460 str r1, [r12, r3, lsl #2] */
/* @0x22f464 ldr r12, [sp, #0x14] */
/* @0x22f468 ldr r3, [r12] */
/* @0x22f46c cmp r3, r1 */
/* @0x22f470 strlt r1, [r12] */
/* @0x22f474 cmp r5, r2 */
/* @0x22f478 blt 0x22f2d0 <_book_unquantize+0x4b8> */
/* @0x22f47c ldr r1, [r4, #0x4] */
/* @0x22f480 ldr r3, [sp, #0x2c] */
/* @0x22f484 add r3, r3, #1 */
/* @0x22f488 str r3, [sp, #0x2c] */
/* @0x22f48c ldr r12, [sp, #0x4] */
/* @0x22f490 add r12, r12, #1 */
/* @0x22f494 str r12, [sp, #0x4] */
/* @0x22f498 cmp r1, r12 */
/* @0x22f49c bgt 0x22f27c <_book_unquantize+0x464> */
/* @0x22f4a0 ldr r12, [sp, #0x30] */
/* @0x22f4a4 ldr r6, [sp, #0x20] */
/* @0x22f4a8 mul r5, r2, r12 */
/* @0x22f4ac b 0x22f0e4 <_book_unquantize+0x2cc> */
/* @0x22f4b0 rsb r2, r9, r1 */
/* @0x22f4b4 asr lr, lr, #1 */
/* @0x22f4b8 add r3, r2, #1 */
/* @0x22f4bc add r1, r1, #1 */
/* @0x22f4c0 cmp r3, #31 */
/* @0x22f4c4 movle r0, #1 */
/* @0x22f4c8 movgt r3, #0 */
/* @0x22f4cc addle r2, r6, r0, lsl r2 */
/* @0x22f4d0 asrle r3, r2, r3 */
/* @0x22f4d4 b 0x22f384 <_book_unquantize+0x56c> */
/* @0x22f4d8 ldr r12, [sp, #0x28] */
/* @0x22f4dc asr r3, r3, #1 */
/* @0x22f4e0 rsb r2, r12, r1 */
/* @0x22f4e4 add r1, r0, #33 */
/* @0x22f4e8 add lr, r2, #1 */
/* @0x22f4ec cmp lr, #31 */
/* @0x22f4f0 movgt lr, #0 */
/* @0x22f4f4 ldrle r12, [sp, #0x1c] */
/* @0x22f4f8 movle r0, #1 */
/* @0x22f4fc addle r2, r12, r0, lsl r2 */
/* @0x22f500 asrle lr, r2, lr */
/* @0x22f504 b 0x22f3dc <_book_unquantize+0x5c4> */
/* @0x22f508 ldr lr, [sp, #0x34] */
/* @0x22f50c mov r3, #0 */
/* @0x22f510 b 0x22f3dc <_book_unquantize+0x5c4> */
/* @0x22f514 ldr r5, [r4] */
/* @0x22f518 ldr r12, [sp, #0x30] */
/* @0x22f51c mul r5, r5, r12 */
/* @0x22f520 b 0x22f0e4 <_book_unquantize+0x2cc> */
/* @0x22f524 ldr r3, [sp, #0x1c] */
/* @0x22f528 cmp r3, #0 */
/* @0x22f52c bne 0x22f348 <_book_unquantize+0x530> */
/* @0x22f530 ldr lr, [sp, #0x1c] */
/* @0x22f534 mov r1, lr */
/* @0x22f538 b 0x22f400 <_book_unquantize+0x5e8> */
/* @0x22f53c ldr r12, [sp, #0x1c] */
/* @0x22f540 cmp r12, #0 */
/* @0x22f544 bne 0x22efe0 <_book_unquantize+0x1c8> */
/* @0x22f548 ldr lr, [sp, #0x1c] */
/* @0x22f54c mov r1, lr */
/* @0x22f550 b 0x22f048 <_book_unquantize+0x230> */

/* ── FUNC 0x22f554 · vorbis_staticbook_destroy · size=68 · insn=17 */
/* @0x22f554 push {r4, lr} */
/* @0x22f558 mov r4, r0 */
/* @0x22f55c ldr r0, [r0, #0x20] */
/* @0x22f560 cmp r0, #0 */
/* @0x22f564 beq 0x22f56c <vorbis_staticbook_destroy+0x18> */
/* @0x22f568 bl 0xb655c <free@plt> */
/* @0x22f56c ldr r0, [r4, #0x8] */
/* @0x22f570 cmp r0, #0 */
/* @0x22f574 beq 0x22f57c <vorbis_staticbook_destroy+0x28> */
/* @0x22f578 bl 0xb655c <free@plt> */
/* @0x22f57c mov r0, r4 */
/* @0x22f580 mov r1, #0 */
/* @0x22f584 mov r2, #36 */
/* @0x22f588 bl 0xb65b0 <memset@plt> */
/* @0x22f58c mov r0, r4 */
/* @0x22f590 pop {r4, lr} */
/* @0x22f594 b 0xb655c <free@plt> */
