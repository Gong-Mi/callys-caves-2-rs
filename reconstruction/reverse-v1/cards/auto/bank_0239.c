/* libyoyo.so 覆盖卡组 0239
 * 函数 0x2894cc..0x28acf4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2894cc · spSkeleton_dispose · size=304 · insn=76 */
/* @0x2894cc push {r3, r4, r5, lr} */
/* @0x2894d0 mov r4, r0 */
/* @0x2894d4 ldr r0, [r0, #0x68] */
/* @0x2894d8 bl 0x285c80 <_free> */
/* @0x2894dc ldr r3, [r4, #0x4] */
/* @0x2894e0 cmp r3, #0 */
/* @0x2894e4 movgt r5, #0 */
/* @0x2894e8 ble 0x289508 <spSkeleton_dispose+0x3c> */
/* @0x2894ec ldr r3, [r4, #0x8] */
/* @0x2894f0 ldr r0, [r3, r5, lsl #2] */
/* @0x2894f4 add r5, r5, #1 */
/* @0x2894f8 bl 0x284efc <spBone_dispose> */
/* @0x2894fc ldr r3, [r4, #0x4] */
/* @0x289500 cmp r3, r5 */
/* @0x289504 bgt 0x2894ec <spSkeleton_dispose+0x20> */
/* @0x289508 ldr r0, [r4, #0x8] */
/* @0x28950c bl 0x285c80 <_free> */
/* @0x289510 ldr r3, [r4, #0x10] */
/* @0x289514 cmp r3, #0 */
/* @0x289518 movgt r5, #0 */
/* @0x28951c ble 0x28953c <spSkeleton_dispose+0x70> */
/* @0x289520 ldr r3, [r4, #0x14] */
/* @0x289524 ldr r0, [r3, r5, lsl #2] */
/* @0x289528 add r5, r5, #1 */
/* @0x28952c bl 0x28ee00 <spSlot_dispose> */
/* @0x289530 ldr r3, [r4, #0x10] */
/* @0x289534 cmp r3, r5 */
/* @0x289538 bgt 0x289520 <spSkeleton_dispose+0x54> */
/* @0x28953c ldr r0, [r4, #0x14] */
/* @0x289540 bl 0x285c80 <_free> */
/* @0x289544 ldr r3, [r4, #0x1c] */
/* @0x289548 cmp r3, #0 */
/* @0x28954c movgt r5, #0 */
/* @0x289550 ble 0x289570 <spSkeleton_dispose+0xa4> */
/* @0x289554 ldr r3, [r4, #0x20] */
/* @0x289558 ldr r0, [r3, r5, lsl #2] */
/* @0x28955c add r5, r5, #1 */
/* @0x289560 bl 0x285e2c <spIkConstraint_dispose> */
/* @0x289564 ldr r3, [r4, #0x1c] */
/* @0x289568 cmp r3, r5 */
/* @0x28956c bgt 0x289554 <spSkeleton_dispose+0x88> */
/* @0x289570 ldr r0, [r4, #0x20] */
/* @0x289574 bl 0x285c80 <_free> */
/* @0x289578 ldr r0, [r4, #0x24] */
/* @0x28957c bl 0x285c80 <_free> */
/* @0x289580 ldr r3, [r4, #0x28] */
/* @0x289584 cmp r3, #0 */
/* @0x289588 movgt r5, #0 */
/* @0x28958c ble 0x2895ac <spSkeleton_dispose+0xe0> */
/* @0x289590 ldr r3, [r4, #0x2c] */
/* @0x289594 ldr r0, [r3, r5, lsl #2] */
/* @0x289598 add r5, r5, #1 */
/* @0x28959c bl 0x28f0f4 <spTransformConstraint_dispose> */
/* @0x2895a0 ldr r3, [r4, #0x28] */
/* @0x2895a4 cmp r3, r5 */
/* @0x2895a8 bgt 0x289590 <spSkeleton_dispose+0xc4> */
/* @0x2895ac ldr r0, [r4, #0x2c] */
/* @0x2895b0 bl 0x285c80 <_free> */
/* @0x2895b4 ldr r3, [r4, #0x30] */
/* @0x2895b8 cmp r3, #0 */
/* @0x2895bc movgt r5, #0 */
/* @0x2895c0 ble 0x2895e0 <spSkeleton_dispose+0x114> */
/* @0x2895c4 ldr r3, [r4, #0x34] */
/* @0x2895c8 ldr r0, [r3, r5, lsl #2] */
/* @0x2895cc add r5, r5, #1 */
/* @0x2895d0 bl 0x287a70 <spPathConstraint_dispose> */
/* @0x2895d4 ldr r3, [r4, #0x30] */
/* @0x2895d8 cmp r3, r5 */
/* @0x2895dc bgt 0x2895c4 <spSkeleton_dispose+0xf8> */
/* @0x2895e0 ldr r0, [r4, #0x34] */
/* @0x2895e4 bl 0x285c80 <_free> */
/* @0x2895e8 ldr r0, [r4, #0x18] */
/* @0x2895ec bl 0x285c80 <_free> */
/* @0x2895f0 mov r0, r4 */
/* @0x2895f4 pop {r3, r4, r5, lr} */
/* @0x2895f8 b 0x285c80 <_free> */

/* ── FUNC 0x2895fc · spSkeleton_updateCache · size=1348 · insn=337 */
/* @0x2895fc ldr r3, [r0, #0x1c] */
/* @0x289600 ldr r1, [r0, #0x4] */
/* @0x289604 ldr r2, [r0, #0x28] */
/* @0x289608 add r1, r1, r3 */
/* @0x28960c ldr r3, [r0, #0x30] */
/* @0x289610 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x289614 add r2, r1, r2 */
/* @0x289618 mov r4, r0 */
/* @0x28961c add r3, r2, r3 */
/* @0x289620 ldr r0, [r0, #0x68] */
/* @0x289624 sub sp, sp, #20 */
/* @0x289628 str r3, [r4, #0x64] */
/* @0x28962c bl 0x285c80 <_free> */
/* @0x289630 ldr r0, [r4, #0x64] */
/* @0x289634 ldr r1, [pc, #0x4fc] */
/* @0x289638 mov r2, #225 */
/* @0x28963c add r1, pc, r1 */
/* @0x289640 lsl r0, r0, #3 */
/* @0x289644 bl 0x285c10 <_malloc> */
/* @0x289648 ldr r2, [r4, #0x4] */
/* @0x28964c mov r1, #0 */
/* @0x289650 ldr r3, [r4, #0x8] */
/* @0x289654 cmp r2, r1 */
/* @0x289658 str r1, [r4, #0x60] */
/* @0x28965c str r0, [r4, #0x68] */
/* @0x289660 addgt r0, r3, r2, lsl #2 */
/* @0x289664 ble 0x289678 <spSkeleton_updateCache+0x7c> */
/* @0x289668 ldr r2, [r3], #4 */
/* @0x28966c cmp r3, r0 */
/* @0x289670 str r1, [r2, #0x54] */
/* @0x289674 bne 0x289668 <spSkeleton_updateCache+0x6c> */
/* @0x289678 ldr r0, [r4, #0x24] */
/* @0x28967c cmp r0, #0 */
/* @0x289680 beq 0x289688 <spSkeleton_updateCache+0x8c> */
/* @0x289684 bl 0x285c80 <_free> */
/* @0x289688 ldr r0, [r4, #0x1c] */
/* @0x28968c mov r2, #234 */
/* @0x289690 ldr r1, [pc, #0x4a4] */
/* @0x289694 lsl r0, r0, #2 */
/* @0x289698 add r1, pc, r1 */
/* @0x28969c bl 0x285c10 <_malloc> */
/* @0x2896a0 ldr r9, [r4, #0x1c] */
/* @0x2896a4 cmp r9, #0 */
/* @0x2896a8 str r0, [r4, #0x24] */
/* @0x2896ac ble 0x289790 <spSkeleton_updateCache+0x194> */
/* @0x2896b0 lsl r1, r9, #2 */
/* @0x2896b4 mov r3, #0 */
/* @0x2896b8 ldr r2, [r4, #0x20] */
/* @0x2896bc ldr r2, [r2, r3] */
/* @0x2896c0 str r2, [r0, r3] */
/* @0x2896c4 add r3, r3, #4 */
/* @0x2896c8 cmp r3, r1 */
/* @0x2896cc bne 0x2896b8 <spSkeleton_updateCache+0xbc> */
/* @0x2896d0 add lr, r3, r0 */
/* @0x2896d4 mov r1, r0 */
/* @0x2896d8 ldr r12, [r1], #4 */
/* @0x2896dc ldr r3, [r12, #0x8] */
/* @0x2896e0 ldr r3, [r3] */
/* @0x2896e4 ldr r3, [r3, #0x8] */
/* @0x2896e8 cmp r3, #0 */
/* @0x2896ec beq 0x289b1c <spSkeleton_updateCache+0x520> */
/* @0x2896f0 mov r2, #0 */
/* @0x2896f4 ldr r3, [r3, #0x8] */
/* @0x2896f8 add r2, r2, #1 */
/* @0x2896fc cmp r3, #0 */
/* @0x289700 bne 0x2896f4 <spSkeleton_updateCache+0xf8> */
/* @0x289704 cmp r1, lr */
/* @0x289708 str r2, [r12, #0x18] */
/* @0x28970c bne 0x2896d8 <spSkeleton_updateCache+0xdc> */
/* @0x289710 cmp r9, #1 */
/* @0x289714 ble 0x289a8c <spSkeleton_updateCache+0x490> */
/* @0x289718 sub r9, r9, #1 */
/* @0x28971c mov r12, r0 */
/* @0x289720 mov r6, #0 */
/* @0x289724 mov r7, r12 */
/* @0x289728 ldr r8, [r12, #0x4] */
/* @0x28972c ldr r2, [r7], #4 */
/* @0x289730 mov r3, r6 */
/* @0x289734 mov r1, r6 */
/* @0x289738 ldr r5, [r8, #0x18] */
/* @0x28973c ldr lr, [r2, #0x18] */
/* @0x289740 cmp r5, lr */
/* @0x289744 ble 0x28975c <spSkeleton_updateCache+0x160> */
/* @0x289748 b 0x289b30 <spSkeleton_updateCache+0x534> */
/* @0x28974c ldr r2, [r12, #-0x4]! */
/* @0x289750 ldr lr, [r2, #0x18] */
/* @0x289754 cmp r5, lr */
/* @0x289758 bgt 0x289774 <spSkeleton_updateCache+0x178> */
/* @0x28975c sub r3, r3, #1 */
/* @0x289760 add r1, r1, #1 */
/* @0x289764 cmn r3, #1 */
/* @0x289768 str r2, [r0, r1, lsl #2] */
/* @0x28976c mov r1, r3 */
/* @0x289770 bne 0x28974c <spSkeleton_updateCache+0x150> */
/* @0x289774 add r6, r6, #1 */
/* @0x289778 add r3, r3, #1 */
/* @0x28977c cmp r6, r9 */
/* @0x289780 str r8, [r0, r3, lsl #2] */
/* @0x289784 beq 0x289a8c <spSkeleton_updateCache+0x490> */
/* @0x289788 mov r12, r7 */
/* @0x28978c b 0x289724 <spSkeleton_updateCache+0x128> */
/* @0x289790 ldr r2, [r4, #0x30] */
/* @0x289794 ldr r3, [r4, #0x34] */
/* @0x289798 cmp r2, #0 */
/* @0x28979c str r2, [sp, #0xc] */
/* @0x2897a0 ble 0x289910 <spSkeleton_updateCache+0x314> */
/* @0x2897a4 mov r8, #1 */
/* @0x2897a8 sub r3, r3, #4 */
/* @0x2897ac mov r2, #0 */
/* @0x2897b0 str r3, [sp, #0x8] */
/* @0x2897b4 str r2, [sp, #0x4] */
/* @0x2897b8 ldr r3, [sp, #0x8] */
/* @0x2897bc ldr r1, [r4, #0x38] */
/* @0x2897c0 ldr r9, [r3, #0x4]! */
/* @0x2897c4 cmp r1, #0 */
/* @0x2897c8 ldr r10, [r9, #0xc] */
/* @0x2897cc str r3, [sp, #0x8] */
/* @0x2897d0 ldm r10, {r3, r5} */
/* @0x2897d4 ldr r6, [r3] */
/* @0x2897d8 beq 0x2897ec <spSkeleton_updateCache+0x1f0> */
/* @0x2897dc mov r0, r4 */
/* @0x2897e0 mov r2, r6 */
/* @0x2897e4 mov r3, r5 */
/* @0x2897e8 bl 0x289474 <spRegionAttachment_computeWorldVertices+0x300> */
/* @0x2897ec ldr r3, [r4] */
/* @0x2897f0 ldr r1, [r3, #0x28] */
/* @0x2897f4 cmp r1, #0 */
/* @0x2897f8 beq 0x28981c <spSkeleton_updateCache+0x220> */
/* @0x2897fc ldr r2, [r4, #0x38] */
/* @0x289800 cmp r1, r2 */
/* @0x289804 beq 0x28981c <spSkeleton_updateCache+0x220> */
/* @0x289808 mov r3, r5 */
/* @0x28980c mov r0, r4 */
/* @0x289810 mov r2, r6 */
/* @0x289814 bl 0x289474 <spRegionAttachment_computeWorldVertices+0x300> */
/* @0x289818 ldr r3, [r4] */
/* @0x28981c ldr r7, [r3, #0x20] */
/* @0x289820 cmp r7, #0 */
/* @0x289824 movgt r11, #0 */
/* @0x289828 bgt 0x289834 <spSkeleton_updateCache+0x238> */
/* @0x28982c b 0x289858 <spSkeleton_updateCache+0x25c> */
/* @0x289830 ldr r3, [r4] */
/* @0x289834 ldr r1, [r3, #0x24] */
/* @0x289838 mov r0, r4 */
/* @0x28983c mov r2, r6 */
/* @0x289840 mov r3, r5 */
/* @0x289844 ldr r1, [r1, r11, lsl #2] */
/* @0x289848 add r11, r11, #1 */
/* @0x28984c bl 0x289474 <spRegionAttachment_computeWorldVertices+0x300> */
/* @0x289850 cmp r11, r7 */
/* @0x289854 bne 0x289830 <spSkeleton_updateCache+0x234> */
/* @0x289858 ldr r1, [r10, #0x18] */
/* @0x28985c ldr r3, [r1, #0x4] */
/* @0x289860 cmp r3, #4 */
/* @0x289864 beq 0x289a60 <spSkeleton_updateCache+0x464> */
/* @0x289868 ldmib r9, {r5, r6} */
/* @0x28986c cmp r5, #0 */
/* @0x289870 ble 0x289a78 <spSkeleton_updateCache+0x47c> */
/* @0x289874 sub r11, r6, #4 */
/* @0x289878 mov r10, #0 */
/* @0x28987c mov r7, r11 */
/* @0x289880 b 0x28988c <spSkeleton_updateCache+0x290> */
/* @0x289884 cmp r10, r5 */
/* @0x289888 beq 0x2898b0 <spSkeleton_updateCache+0x2b4> */
/* @0x28988c ldr r1, [r7, #0x4]! */
/* @0x289890 add r10, r10, #1 */
/* @0x289894 ldr r3, [r1, #0x54] */
/* @0x289898 cmp r3, #0 */
/* @0x28989c bne 0x289884 <spSkeleton_updateCache+0x288> */
/* @0x2898a0 mov r0, r4 */
/* @0x2898a4 bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4> */
/* @0x2898a8 cmp r10, r5 */
/* @0x2898ac bne 0x28988c <spSkeleton_updateCache+0x290> */
/* @0x2898b0 mov r2, r9 */
/* @0x2898b4 mov r0, r4 */
/* @0x2898b8 mov r1, #2 */
/* @0x2898bc mov r7, r11 */
/* @0x2898c0 bl 0x2892ec <spRegionAttachment_computeWorldVertices+0x178> */
/* @0x2898c4 mov r9, #0 */
/* @0x2898c8 ldr r3, [r7, #0x4]! */
/* @0x2898cc add r9, r9, #1 */
/* @0x2898d0 ldr r0, [r3, #0x10] */
/* @0x2898d4 ldr r1, [r3, #0xc] */
/* @0x2898d8 bl 0x289294 <spRegionAttachment_computeWorldVertices+0x120> */
/* @0x2898dc cmp r9, r5 */
/* @0x2898e0 bne 0x2898c8 <spSkeleton_updateCache+0x2cc> */
/* @0x2898e4 add r9, r6, r9, lsl #2 */
/* @0x2898e8 ldr r3, [r6], #4 */
/* @0x2898ec cmp r6, r9 */
/* @0x2898f0 str r8, [r3, #0x54] */
/* @0x2898f4 bne 0x2898e8 <spSkeleton_updateCache+0x2ec> */
/* @0x2898f8 ldr r2, [sp, #0x4] */
/* @0x2898fc ldr r3, [sp, #0xc] */
/* @0x289900 add r2, r2, #1 */
/* @0x289904 str r2, [sp, #0x4] */
/* @0x289908 cmp r2, r3 */
/* @0x28990c bne 0x2897b8 <spSkeleton_updateCache+0x1bc> */
/* @0x289910 ldr r3, [r4, #0x28] */
/* @0x289914 ldr r9, [r4, #0x2c] */
/* @0x289918 cmp r3, #0 */
/* @0x28991c str r3, [sp, #0x4] */
/* @0x289920 subgt r9, r9, #4 */
/* @0x289924 movgt r8, #0 */
/* @0x289928 movgt r7, #1 */
/* @0x28992c ble 0x289a04 <spSkeleton_updateCache+0x408> */
/* @0x289930 ldr r6, [r9, #0x4]! */
/* @0x289934 ldr r1, [r6, #0xc] */
/* @0x289938 ldr r11, [r6, #0x8] */
/* @0x28993c ldr r3, [r1, #0x54] */
/* @0x289940 cmp r3, #0 */
/* @0x289944 beq 0x289a54 <spSkeleton_updateCache+0x458> */
/* @0x289948 ldr r0, [r6, #0x4] */
/* @0x28994c cmp r0, #0 */
/* @0x289950 subgt r10, r11, #4 */
/* @0x289954 movgt r5, #0 */
/* @0x289958 bgt 0x289968 <spSkeleton_updateCache+0x36c> */
/* @0x28995c b 0x289990 <spSkeleton_updateCache+0x394> */
/* @0x289960 cmp r0, r5 */
/* @0x289964 ble 0x289990 <spSkeleton_updateCache+0x394> */
/* @0x289968 ldr r1, [r10, #0x4]! */
/* @0x28996c add r5, r5, #1 */
/* @0x289970 ldr r2, [r1, #0x54] */
/* @0x289974 cmp r2, #0 */
/* @0x289978 bne 0x289960 <spSkeleton_updateCache+0x364> */
/* @0x28997c mov r0, r4 */
/* @0x289980 bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4> */
/* @0x289984 ldr r0, [r6, #0x4] */
/* @0x289988 cmp r0, r5 */
/* @0x28998c bgt 0x289968 <spSkeleton_updateCache+0x36c> */
/* @0x289990 mov r0, r4 */
/* @0x289994 mov r1, #3 */
/* @0x289998 mov r2, r6 */
/* @0x28999c bl 0x2892ec <spRegionAttachment_computeWorldVertices+0x178> */
/* @0x2899a0 ldr r3, [r6, #0x4] */
/* @0x2899a4 cmp r3, #0 */
/* @0x2899a8 subgt r10, r11, #4 */
/* @0x2899ac movgt r5, #0 */
/* @0x2899b0 ble 0x2899f4 <spSkeleton_updateCache+0x3f8> */
/* @0x2899b4 ldr r3, [r10, #0x4]! */
/* @0x2899b8 add r5, r5, #1 */
/* @0x2899bc ldr r0, [r3, #0x10] */
/* @0x2899c0 ldr r1, [r3, #0xc] */
/* @0x2899c4 bl 0x289294 <spRegionAttachment_computeWorldVertices+0x120> */
/* @0x2899c8 ldr r2, [r6, #0x4] */
/* @0x2899cc cmp r2, r5 */
/* @0x2899d0 bgt 0x2899b4 <spSkeleton_updateCache+0x3b8> */
/* @0x2899d4 cmp r2, #0 */
/* @0x2899d8 ble 0x2899f4 <spSkeleton_updateCache+0x3f8> */
/* @0x2899dc add r2, r11, r2, lsl #2 */
/* @0x2899e0 mov r3, r11 */
/* @0x2899e4 ldr r1, [r3], #4 */
/* @0x2899e8 cmp r3, r2 */
/* @0x2899ec str r7, [r1, #0x54] */
/* @0x2899f0 bne 0x2899e4 <spSkeleton_updateCache+0x3e8> */
/* @0x2899f4 ldr r3, [sp, #0x4] */
/* @0x2899f8 add r8, r8, #1 */
/* @0x2899fc cmp r8, r3 */
/* @0x289a00 bne 0x289930 <spSkeleton_updateCache+0x334> */
/* @0x289a04 ldr r2, [r4, #0x4] */
/* @0x289a08 cmp r2, #0 */
/* @0x289a0c movgt r5, #0 */
/* @0x289a10 bgt 0x289a20 <spSkeleton_updateCache+0x424> */
/* @0x289a14 b 0x289a4c <spSkeleton_updateCache+0x450> */
/* @0x289a18 cmp r2, r5 */
/* @0x289a1c ble 0x289a4c <spSkeleton_updateCache+0x450> */
/* @0x289a20 ldr r3, [r4, #0x8] */
/* @0x289a24 ldr r1, [r3, r5, lsl #2] */
/* @0x289a28 add r5, r5, #1 */
/* @0x289a2c ldr r3, [r1, #0x54] */
/* @0x289a30 cmp r3, #0 */
/* @0x289a34 bne 0x289a18 <spSkeleton_updateCache+0x41c> */
/* @0x289a38 mov r0, r4 */
/* @0x289a3c bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4> */
/* @0x289a40 ldr r2, [r4, #0x4] */
/* @0x289a44 cmp r2, r5 */
/* @0x289a48 bgt 0x289a20 <spSkeleton_updateCache+0x424> */
/* @0x289a4c add sp, sp, #20 */
/* @0x289a50 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x289a54 mov r0, r4 */
/* @0x289a58 bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4> */
/* @0x289a5c b 0x289948 <spSkeleton_updateCache+0x34c> */
/* @0x289a60 mov r2, r5 */
/* @0x289a64 mov r0, r4 */
/* @0x289a68 bl 0x28939c <spRegionAttachment_computeWorldVertices+0x228> */
/* @0x289a6c ldmib r9, {r5, r6} */
/* @0x289a70 cmp r5, #0 */
/* @0x289a74 bgt 0x289874 <spSkeleton_updateCache+0x278> */
/* @0x289a78 mov r2, r9 */
/* @0x289a7c mov r0, r4 */
/* @0x289a80 mov r1, #2 */
/* @0x289a84 bl 0x2892ec <spRegionAttachment_computeWorldVertices+0x178> */
/* @0x289a88 b 0x2898f8 <spSkeleton_updateCache+0x2fc> */
/* @0x289a8c sub r9, r0, #4 */
/* @0x289a90 mov r7, #0 */
/* @0x289a94 mov r10, #1 */
/* @0x289a98 b 0x289ae8 <spSkeleton_updateCache+0x4ec> */
/* @0x289a9c ldr r8, [r5, #0x8] */
/* @0x289aa0 ldr r6, [r8] */
/* @0x289aa4 ldr r3, [r6, #0x54] */
/* @0x289aa8 cmp r3, #0 */
/* @0x289aac beq 0x289b0c <spSkeleton_updateCache+0x510> */
/* @0x289ab0 mov r2, r5 */
/* @0x289ab4 mov r0, r4 */
/* @0x289ab8 mov r1, #1 */
/* @0x289abc bl 0x2892ec <spRegionAttachment_computeWorldVertices+0x178> */
/* @0x289ac0 ldr r0, [r6, #0x10] */
/* @0x289ac4 ldr r1, [r6, #0xc] */
/* @0x289ac8 bl 0x289294 <spRegionAttachment_computeWorldVertices+0x120> */
/* @0x289acc ldr r3, [r5, #0x4] */
/* @0x289ad0 ldr r2, [r4, #0x1c] */
/* @0x289ad4 sub r3, r3, #-1073741823 */
/* @0x289ad8 cmp r2, r7 */
/* @0x289adc ldr r3, [r8, r3, lsl #2] */
/* @0x289ae0 str r10, [r3, #0x54] */
/* @0x289ae4 ble 0x289790 <spSkeleton_updateCache+0x194> */
/* @0x289ae8 ldr r5, [r9, #0x4]! */
/* @0x289aec add r7, r7, #1 */
/* @0x289af0 ldr r1, [r5, #0xc] */
/* @0x289af4 ldr r3, [r1, #0x54] */
/* @0x289af8 cmp r3, #0 */
/* @0x289afc bne 0x289a9c <spSkeleton_updateCache+0x4a0> */
/* @0x289b00 mov r0, r4 */
/* @0x289b04 bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4> */
/* @0x289b08 b 0x289a9c <spSkeleton_updateCache+0x4a0> */
/* @0x289b0c mov r0, r4 */
/* @0x289b10 mov r1, r6 */
/* @0x289b14 bl 0x289358 <spRegionAttachment_computeWorldVertices+0x1e4> */
/* @0x289b18 b 0x289ab0 <spSkeleton_updateCache+0x4b4> */
/* @0x289b1c cmp r1, lr */
/* @0x289b20 mov r2, r3 */
/* @0x289b24 str r2, [r12, #0x18] */
/* @0x289b28 bne 0x2896d8 <spSkeleton_updateCache+0xdc> */
/* @0x289b2c b 0x289710 <spSkeleton_updateCache+0x114> */
/* @0x289b30 mov r3, r6 */
/* @0x289b34 b 0x289774 <spSkeleton_updateCache+0x178> */
/* @0x289b38 strdeq lr, pc, [r12], -r8 */
/* @0x289b3c muleq r12, r12, r3 */

/* ── FUNC 0x289b40 · spSkeleton_create · size=932 · insn=233 */
/* @0x289b40 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x289b44 mov r1, #108 */
/* @0x289b48 ldr r5, [pc, #0x37c] */
/* @0x289b4c mov r7, r0 */
/* @0x289b50 mov r3, #59 */
/* @0x289b54 mov r0, #1 */
/* @0x289b58 add r5, pc, r5 */
/* @0x289b5c mov r2, r5 */
/* @0x289b60 bl 0x285c4c <_calloc> */
/* @0x289b64 mov r1, r5 */
/* @0x289b68 mov r2, #64 */
/* @0x289b6c mov r4, r0 */
/* @0x289b70 ldr r0, [r7, #0x10] */
/* @0x289b74 str r7, [r4] */
/* @0x289b78 str r0, [r4, #0x4] */
/* @0x289b7c lsl r0, r0, #2 */
/* @0x289b80 bl 0x285c10 <_malloc> */
/* @0x289b84 mov r3, #65 */
/* @0x289b88 mov r2, r5 */
/* @0x289b8c mov r1, #4 */
/* @0x289b90 str r0, [r4, #0x8] */
/* @0x289b94 ldr r0, [r4, #0x4] */
/* @0x289b98 bl 0x285c4c <_calloc> */
/* @0x289b9c ldr r3, [r4, #0x4] */
/* @0x289ba0 cmp r3, #0 */
/* @0x289ba4 mov r6, r0 */
/* @0x289ba8 ble 0x289ec4 <spSkeleton_create+0x384> */
/* @0x289bac mov r5, #0 */
/* @0x289bb0 b 0x289bf0 <spSkeleton_create+0xb0> */
/* @0x289bb4 ldr r3, [r4, #0x8] */
/* @0x289bb8 ldr r2, [r2] */
/* @0x289bbc ldr r2, [r3, r2, lsl #2] */
/* @0x289bc0 bl 0x2853c8 <spBone_create> */
/* @0x289bc4 ldr r3, [r8, #0x8] */
/* @0x289bc8 ldr r3, [r3] */
/* @0x289bcc ldr r2, [r6, r3, lsl #2] */
/* @0x289bd0 add r2, r2, #1 */
/* @0x289bd4 str r2, [r6, r3, lsl #2] */
/* @0x289bd8 ldr r3, [r4, #0x4] */
/* @0x289bdc add r5, r5, #1 */
/* @0x289be0 ldr r2, [r4, #0x8] */
/* @0x289be4 cmp r3, r5 */
/* @0x289be8 str r0, [r2, r9] */
/* @0x289bec ble 0x289c1c <spSkeleton_create+0xdc> */
/* @0x289bf0 ldr r3, [r4] */
/* @0x289bf4 mov r1, r4 */
/* @0x289bf8 lsl r9, r5, #2 */
/* @0x289bfc ldr r3, [r3, #0x14] */
/* @0x289c00 ldr r8, [r3, r5, lsl #2] */
/* @0x289c04 ldr r2, [r8, #0x8] */
/* @0x289c08 mov r0, r8 */
/* @0x289c0c cmp r2, #0 */
/* @0x289c10 bne 0x289bb4 <spSkeleton_create+0x74> */
/* @0x289c14 bl 0x2853c8 <spBone_create> */
/* @0x289c18 b 0x289bd8 <spSkeleton_create+0x98> */
/* @0x289c1c cmp r3, #0 */
/* @0x289c20 ble 0x289ec4 <spSkeleton_create+0x384> */
/* @0x289c24 ldr r9, [pc, #0x2a4] */
/* @0x289c28 mov r5, #0 */
/* @0x289c2c add r9, pc, r9 */
/* @0x289c30 ldr r3, [r4] */
/* @0x289c34 mov r1, r9 */
/* @0x289c38 ldr r0, [r4, #0x8] */
/* @0x289c3c mov r2, #82 */
/* @0x289c40 ldr r3, [r3, #0x14] */
/* @0x289c44 ldr r8, [r0, r5, lsl #2] */
/* @0x289c48 ldr r3, [r3, r5, lsl #2] */
/* @0x289c4c add r5, r5, #1 */
/* @0x289c50 ldr r3, [r3] */
/* @0x289c54 ldr r0, [r6, r3, lsl #2] */
/* @0x289c58 lsl r0, r0, #2 */
/* @0x289c5c bl 0x285c10 <_malloc> */
/* @0x289c60 ldr r12, [r4, #0x4] */
/* @0x289c64 cmp r12, r5 */
/* @0x289c68 str r0, [r8, #0x10] */
/* @0x289c6c bgt 0x289c30 <spSkeleton_create+0xf0> */
/* @0x289c70 cmp r12, #0 */
/* @0x289c74 ble 0x289ec4 <spSkeleton_create+0x384> */
/* @0x289c78 ldr r0, [r4, #0x8] */
/* @0x289c7c mov r2, #0 */
/* @0x289c80 ldr r1, [r0, r2, lsl #2] */
/* @0x289c84 add r2, r2, #1 */
/* @0x289c88 ldr r3, [r1, #0x8] */
/* @0x289c8c cmp r3, #0 */
/* @0x289c90 beq 0x289cac <spSkeleton_create+0x16c> */
/* @0x289c94 ldr r0, [r3, #0xc] */
/* @0x289c98 ldr lr, [r3, #0x10] */
/* @0x289c9c add r5, r0, #1 */
/* @0x289ca0 str r5, [r3, #0xc] */
/* @0x289ca4 str r1, [lr, r0, lsl #2] */
/* @0x289ca8 ldr r0, [r4, #0x8] */
/* @0x289cac cmp r2, r12 */
/* @0x289cb0 bne 0x289c80 <spSkeleton_create+0x140> */
/* @0x289cb4 ldr r3, [r0] */
/* @0x289cb8 ldr r0, [r7, #0x18] */
/* @0x289cbc mov r2, #93 */
/* @0x289cc0 ldr r1, [pc, #0x20c] */
/* @0x289cc4 str r3, [r4, #0xc] */
/* @0x289cc8 str r0, [r4, #0x10] */
/* @0x289ccc add r1, pc, r1 */
/* @0x289cd0 lsl r0, r0, #2 */
/* @0x289cd4 bl 0x285c10 <_malloc> */
/* @0x289cd8 ldr r3, [r4, #0x10] */
/* @0x289cdc cmp r3, #0 */
/* @0x289ce0 str r0, [r4, #0x14] */
/* @0x289ce4 ble 0x289d28 <spSkeleton_create+0x1e8> */
/* @0x289ce8 mov r8, r0 */
/* @0x289cec mov r5, #0 */
/* @0x289cf0 b 0x289cf8 <spSkeleton_create+0x1b8> */
/* @0x289cf4 ldr r8, [r4, #0x14] */
/* @0x289cf8 ldr r2, [r7, #0x1c] */
/* @0x289cfc ldr r3, [r4, #0x8] */
/* @0x289d00 ldr r0, [r2, r5, lsl #2] */
/* @0x289d04 ldr r2, [r0, #0x8] */
/* @0x289d08 ldr r2, [r2] */
/* @0x289d0c ldr r1, [r3, r2, lsl #2] */
/* @0x289d10 bl 0x28eeec <spSlot_create> */
/* @0x289d14 ldr r3, [r4, #0x10] */
/* @0x289d18 str r0, [r8, r5, lsl #2] */
/* @0x289d1c add r5, r5, #1 */
/* @0x289d20 cmp r3, r5 */
/* @0x289d24 bgt 0x289cf4 <spSkeleton_create+0x1b4> */
/* @0x289d28 ldr r5, [pc, #0x1a8] */
/* @0x289d2c lsl r0, r3, #2 */
/* @0x289d30 mov r2, #100 */
/* @0x289d34 add r5, pc, r5 */
/* @0x289d38 mov r1, r5 */
/* @0x289d3c bl 0x285c10 <_malloc> */
/* @0x289d40 ldr r2, [r4, #0x10] */
/* @0x289d44 ldr r1, [r4, #0x14] */
/* @0x289d48 lsl r2, r2, #2 */
/* @0x289d4c str r0, [r4, #0x18] */
/* @0x289d50 bl 0xb65bc <memcpy@plt> */
/* @0x289d54 ldr r0, [r7, #0x3c] */
/* @0x289d58 mov r1, r5 */
/* @0x289d5c mov r2, #104 */
/* @0x289d60 str r0, [r4, #0x1c] */
/* @0x289d64 lsl r0, r0, #2 */
/* @0x289d68 bl 0x285c10 <_malloc> */
/* @0x289d6c ldr r3, [r4, #0x1c] */
/* @0x289d70 mov r1, r5 */
/* @0x289d74 mov r2, #105 */
/* @0x289d78 str r0, [r4, #0x20] */
/* @0x289d7c lsl r0, r3, #2 */
/* @0x289d80 bl 0x285c10 <_malloc> */
/* @0x289d84 ldr r3, [r4] */
/* @0x289d88 ldr r2, [r3, #0x3c] */
/* @0x289d8c cmp r2, #0 */
/* @0x289d90 movgt r5, #0 */
/* @0x289d94 str r0, [r4, #0x24] */
/* @0x289d98 ble 0x289dc8 <spSkeleton_create+0x288> */
/* @0x289d9c ldr r3, [r3, #0x40] */
/* @0x289da0 mov r1, r4 */
/* @0x289da4 ldr r8, [r4, #0x20] */
/* @0x289da8 ldr r0, [r3, r5, lsl #2] */
/* @0x289dac bl 0x285d64 <spIkConstraint_create> */
/* @0x289db0 str r0, [r8, r5, lsl #2] */
/* @0x289db4 add r5, r5, #1 */
/* @0x289db8 ldr r3, [r4] */
/* @0x289dbc ldr r2, [r3, #0x3c] */
/* @0x289dc0 cmp r2, r5 */
/* @0x289dc4 bgt 0x289d9c <spSkeleton_create+0x25c> */
/* @0x289dc8 ldr r0, [r7, #0x44] */
/* @0x289dcc mov r2, #110 */
/* @0x289dd0 ldr r1, [pc, #0x104] */
/* @0x289dd4 str r0, [r4, #0x28] */
/* @0x289dd8 add r1, pc, r1 */
/* @0x289ddc lsl r0, r0, #2 */
/* @0x289de0 bl 0x285c10 <_malloc> */
/* @0x289de4 ldr r3, [r4] */
/* @0x289de8 ldr r2, [r3, #0x44] */
/* @0x289dec cmp r2, #0 */
/* @0x289df0 movgt r5, #0 */
/* @0x289df4 str r0, [r4, #0x2c] */
/* @0x289df8 movgt r8, r0 */
/* @0x289dfc bgt 0x289e08 <spSkeleton_create+0x2c8> */
/* @0x289e00 b 0x289e30 <spSkeleton_create+0x2f0> */
/* @0x289e04 ldr r8, [r4, #0x2c] */
/* @0x289e08 ldr r3, [r3, #0x48] */
/* @0x289e0c mov r1, r4 */
/* @0x289e10 ldr r0, [r3, r5, lsl #2] */
/* @0x289e14 bl 0x28f01c <spTransformConstraint_create> */
/* @0x289e18 str r0, [r8, r5, lsl #2] */
/* @0x289e1c add r5, r5, #1 */
/* @0x289e20 ldr r3, [r4] */
/* @0x289e24 ldr r2, [r3, #0x44] */
/* @0x289e28 cmp r2, r5 */
/* @0x289e2c bgt 0x289e04 <spSkeleton_create+0x2c4> */
/* @0x289e30 ldr r0, [r7, #0x4c] */
/* @0x289e34 mov r2, #115 */
/* @0x289e38 ldr r1, [pc, #0xa0] */
/* @0x289e3c str r0, [r4, #0x30] */
/* @0x289e40 add r1, pc, r1 */
/* @0x289e44 lsl r0, r0, #2 */
/* @0x289e48 bl 0x285c10 <_malloc> */
/* @0x289e4c ldr r3, [r4] */
/* @0x289e50 ldr r2, [r3, #0x4c] */
/* @0x289e54 cmp r2, #0 */
/* @0x289e58 movgt r5, #0 */
/* @0x289e5c str r0, [r4, #0x34] */
/* @0x289e60 movgt r7, r0 */
/* @0x289e64 bgt 0x289e70 <spSkeleton_create+0x330> */
/* @0x289e68 b 0x289e98 <spSkeleton_create+0x358> */
/* @0x289e6c ldr r7, [r4, #0x34] */
/* @0x289e70 ldr r3, [r3, #0x50] */
/* @0x289e74 mov r1, r4 */
/* @0x289e78 ldr r0, [r3, r5, lsl #2] */
/* @0x289e7c bl 0x28796c <spPathConstraint_create> */
/* @0x289e80 str r0, [r7, r5, lsl #2] */
/* @0x289e84 add r5, r5, #1 */
/* @0x289e88 ldr r3, [r4] */
/* @0x289e8c ldr r2, [r3, #0x4c] */
/* @0x289e90 cmp r2, r5 */
/* @0x289e94 bgt 0x289e6c <spSkeleton_create+0x32c> */
/* @0x289e98 mov r3, #1065353216 */
/* @0x289e9c mov r0, r4 */
/* @0x289ea0 str r3, [r4, #0x3c] */
/* @0x289ea4 str r3, [r4, #0x40] */
/* @0x289ea8 str r3, [r4, #0x44] */
/* @0x289eac str r3, [r4, #0x48] */
/* @0x289eb0 bl 0x2895fc <spSkeleton_updateCache> */
/* @0x289eb4 mov r0, r6 */
/* @0x289eb8 bl 0x285c80 <_free> */
/* @0x289ebc mov r0, r4 */
/* @0x289ec0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x289ec4 mov r3, #0 */
/* @0x289ec8 b 0x289cb8 <spSkeleton_create+0x178> */
/* @0x289ecc ldrdeq sp, lr, [r12], -r12 */
/* @0x289ed0 andeq sp, r12, r8, lsl #28 */
/* @0x289ed4 andeq sp, r12, r8, ror #26 */
/* @0x289ed8 andeq sp, r12, r0, lsl #26 */
/* @0x289edc andeq sp, r12, r12, asr r12 */
/* @0x289ee0 strdeq sp, lr, [r12], -r4 */

/* ── FUNC 0x289ee4 · spSkeleton_updateWorldTransform · size=140 · insn=35 */
/* @0x289ee4 ldr r2, [r0, #0x60] */
/* @0x289ee8 push {r3, r4, r5, lr} */
/* @0x289eec cmp r2, #0 */
/* @0x289ef0 mov r5, r0 */
/* @0x289ef4 pople {r3, r4, r5, pc} */
/* @0x289ef8 mov r4, #0 */
/* @0x289efc ldr r3, [r5, #0x68] */
/* @0x289f00 add r1, r3, r4, lsl #3 */
/* @0x289f04 ldr r3, [r3, r4, lsl #3] */
/* @0x289f08 cmp r3, #3 */
/* @0x289f0c addls pc, pc, r3, lsl #2 */
/* @0x289f10 b 0x289f30 <spSkeleton_updateWorldTransform+0x4c> */
/* @0x289f14 b 0x289f50 <spSkeleton_updateWorldTransform+0x6c> */
/* @0x289f18 b 0x289f60 <spSkeleton_updateWorldTransform+0x7c> */
/* @0x289f1c b 0x289f40 <spSkeleton_updateWorldTransform+0x5c> */
/* @0x289f20 b 0x289f24 <spSkeleton_updateWorldTransform+0x40> */
/* @0x289f24 ldr r0, [r1, #0x4] */
/* @0x289f28 bl 0x28f110 <spTransformConstraint_apply> */
/* @0x289f2c ldr r2, [r5, #0x60] */
/* @0x289f30 add r4, r4, #1 */
/* @0x289f34 cmp r2, r4 */
/* @0x289f38 bgt 0x289efc <spSkeleton_updateWorldTransform+0x18> */
/* @0x289f3c pop {r3, r4, r5, pc} */
/* @0x289f40 ldr r0, [r1, #0x4] */
/* @0x289f44 bl 0x288788 <spPathConstraint_apply> */
/* @0x289f48 ldr r2, [r5, #0x60] */
/* @0x289f4c b 0x289f30 <spSkeleton_updateWorldTransform+0x4c> */
/* @0x289f50 ldr r0, [r1, #0x4] */
/* @0x289f54 bl 0x285348 <spBone_updateWorldTransform> */
/* @0x289f58 ldr r2, [r5, #0x60] */
/* @0x289f5c b 0x289f30 <spSkeleton_updateWorldTransform+0x4c> */
/* @0x289f60 ldr r0, [r1, #0x4] */
/* @0x289f64 bl 0x28667c <spIkConstraint_apply> */
/* @0x289f68 ldr r2, [r5, #0x60] */
/* @0x289f6c b 0x289f30 <spSkeleton_updateWorldTransform+0x4c> */

/* ── FUNC 0x289f70 · spSkeleton_setBonesToSetupPose · size=244 · insn=61 */
/* @0x289f70 push {r3, r4, r5, lr} */
/* @0x289f74 mov r5, r0 */
/* @0x289f78 ldr r3, [r0, #0x4] */
/* @0x289f7c cmp r3, #0 */
/* @0x289f80 movgt r4, #0 */
/* @0x289f84 ble 0x289fa4 <spSkeleton_setBonesToSetupPose+0x34> */
/* @0x289f88 ldr r3, [r5, #0x8] */
/* @0x289f8c ldr r0, [r3, r4, lsl #2] */
/* @0x289f90 add r4, r4, #1 */
/* @0x289f94 bl 0x285388 <spBone_setToSetupPose> */
/* @0x289f98 ldr r3, [r5, #0x4] */
/* @0x289f9c cmp r3, r4 */
/* @0x289fa0 bgt 0x289f88 <spSkeleton_setBonesToSetupPose+0x18> */
/* @0x289fa4 ldr r12, [r5, #0x1c] */
/* @0x289fa8 cmp r12, #0 */
/* @0x289fac ldrgt r2, [r5, #0x20] */
/* @0x289fb0 addgt r12, r2, r12, lsl #2 */
/* @0x289fb4 ble 0x289fd8 <spSkeleton_setBonesToSetupPose+0x68> */
/* @0x289fb8 ldr r3, [r2], #4 */
/* @0x289fbc cmp r2, r12 */
/* @0x289fc0 ldr r1, [r3] */
/* @0x289fc4 ldr r0, [r1, #0x14] */
/* @0x289fc8 ldr r1, [r1, #0x10] */
/* @0x289fcc str r0, [r3, #0x14] */
/* @0x289fd0 str r1, [r3, #0x10] */
/* @0x289fd4 bne 0x289fb8 <spSkeleton_setBonesToSetupPose+0x48> */
/* @0x289fd8 ldr r4, [r5, #0x28] */
/* @0x289fdc cmp r4, #0 */
/* @0x289fe0 ldrgt r1, [r5, #0x2c] */
/* @0x289fe4 addgt r4, r1, r4, lsl #2 */
/* @0x289fe8 ble 0x28a01c <spSkeleton_setBonesToSetupPose+0xac> */
/* @0x289fec ldr r3, [r1], #4 */
/* @0x289ff0 cmp r1, r4 */
/* @0x289ff4 ldr r2, [r3] */
/* @0x289ff8 ldr r0, [r2, #0x14] */
/* @0x289ffc ldr r12, [r2, #0x10] */
/* @0x28a000 str r0, [r3, #0x14] */
/* @0x28a004 ldr r0, [r2, #0x18] */
/* @0x28a008 ldr r2, [r2, #0x1c] */
/* @0x28a00c str r12, [r3, #0x10] */
/* @0x28a010 str r0, [r3, #0x18] */
/* @0x28a014 str r2, [r3, #0x1c] */
/* @0x28a018 bne 0x289fec <spSkeleton_setBonesToSetupPose+0x7c> */
/* @0x28a01c ldr r4, [r5, #0x30] */
/* @0x28a020 cmp r4, #0 */
/* @0x28a024 pople {r3, r4, r5, pc} */
/* @0x28a028 ldr r1, [r5, #0x34] */
/* @0x28a02c add r4, r1, r4, lsl #2 */
/* @0x28a030 ldr r3, [r1], #4 */
/* @0x28a034 cmp r1, r4 */
/* @0x28a038 ldr r2, [r3] */
/* @0x28a03c ldr r0, [r2, #0x24] */
/* @0x28a040 ldr r12, [r2, #0x20] */
/* @0x28a044 str r0, [r3, #0x14] */
/* @0x28a048 ldr r0, [r2, #0x28] */
/* @0x28a04c ldr r2, [r2, #0x2c] */
/* @0x28a050 str r12, [r3, #0x10] */
/* @0x28a054 str r0, [r3, #0x18] */
/* @0x28a058 str r2, [r3, #0x1c] */
/* @0x28a05c bne 0x28a030 <spSkeleton_setBonesToSetupPose+0xc0> */
/* @0x28a060 pop {r3, r4, r5, pc} */

/* ── FUNC 0x28a064 · spSkeleton_setSlotsToSetupPose · size=76 · insn=19 */
/* @0x28a064 ldr r2, [r0, #0x10] */
/* @0x28a068 push {r3, r4, r5, lr} */
/* @0x28a06c mov r5, r0 */
/* @0x28a070 ldr r1, [r5, #0x14] */
/* @0x28a074 lsl r2, r2, #2 */
/* @0x28a078 ldr r0, [r0, #0x18] */
/* @0x28a07c bl 0xb65bc <memcpy@plt> */
/* @0x28a080 ldr r3, [r5, #0x10] */
/* @0x28a084 cmp r3, #0 */
/* @0x28a088 pople {r3, r4, r5, pc} */
/* @0x28a08c mov r4, #0 */
/* @0x28a090 ldr r3, [r5, #0x14] */
/* @0x28a094 ldr r0, [r3, r4, lsl #2] */
/* @0x28a098 add r4, r4, #1 */
/* @0x28a09c bl 0x28ee80 <spSlot_setToSetupPose> */
/* @0x28a0a0 ldr r3, [r5, #0x10] */
/* @0x28a0a4 cmp r3, r4 */
/* @0x28a0a8 bgt 0x28a090 <spSkeleton_setSlotsToSetupPose+0x2c> */
/* @0x28a0ac pop {r3, r4, r5, pc} */

/* ── FUNC 0x28a0b0 · spSkeleton_setToSetupPose · size=24 · insn=6 */
/* @0x28a0b0 push {r4, lr} */
/* @0x28a0b4 mov r4, r0 */
/* @0x28a0b8 bl 0x289f70 <spSkeleton_setBonesToSetupPose> */
/* @0x28a0bc mov r0, r4 */
/* @0x28a0c0 pop {r4, lr} */
/* @0x28a0c4 b 0x28a064 <spSkeleton_setSlotsToSetupPose> */

/* ── FUNC 0x28a0c8 · spSkeleton_findBone · size=104 · insn=26 */
/* @0x28a0c8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x28a0cc mov r9, r0 */
/* @0x28a0d0 ldr r6, [r0, #0x4] */
/* @0x28a0d4 mov r7, r1 */
/* @0x28a0d8 cmp r6, #0 */
/* @0x28a0dc ble 0x28a128 <spSkeleton_findBone+0x60> */
/* @0x28a0e0 ldr r3, [r0] */
/* @0x28a0e4 mov r4, #0 */
/* @0x28a0e8 mov r5, r4 */
/* @0x28a0ec ldr r8, [r3, #0x14] */
/* @0x28a0f0 b 0x28a100 <spSkeleton_findBone+0x38> */
/* @0x28a0f4 cmp r5, r6 */
/* @0x28a0f8 add r4, r4, #4 */
/* @0x28a0fc beq 0x28a128 <spSkeleton_findBone+0x60> */
/* @0x28a100 ldr r3, [r8, r4] */
/* @0x28a104 mov r1, r7 */
/* @0x28a108 add r5, r5, #1 */
/* @0x28a10c ldr r0, [r3, #0x4] */
/* @0x28a110 bl 0xb6574 <strcmp@plt> */
/* @0x28a114 cmp r0, #0 */
/* @0x28a118 bne 0x28a0f4 <spSkeleton_findBone+0x2c> */
/* @0x28a11c ldr r3, [r9, #0x8] */
/* @0x28a120 ldr r0, [r3, r4] */
/* @0x28a124 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x28a128 mov r0, #0 */
/* @0x28a12c pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x28a130 · spSkeleton_findBoneIndex · size=92 · insn=23 */
/* @0x28a130 push {r3, r4, r5, r6, r7, lr} */
/* @0x28a134 mov r7, r1 */
/* @0x28a138 ldr r6, [r0, #0x4] */
/* @0x28a13c cmp r6, #0 */
/* @0x28a140 ble 0x28a184 <spSkeleton_findBoneIndex+0x54> */
/* @0x28a144 ldr r3, [r0] */
/* @0x28a148 mov r4, #0 */
/* @0x28a14c ldr r5, [r3, #0x14] */
/* @0x28a150 sub r5, r5, #4 */
/* @0x28a154 b 0x28a164 <spSkeleton_findBoneIndex+0x34> */
/* @0x28a158 add r4, r4, #1 */
/* @0x28a15c cmp r4, r6 */
/* @0x28a160 beq 0x28a184 <spSkeleton_findBoneIndex+0x54> */
/* @0x28a164 ldr r3, [r5, #0x4]! */
/* @0x28a168 mov r1, r7 */
/* @0x28a16c ldr r0, [r3, #0x4] */
/* @0x28a170 bl 0xb6574 <strcmp@plt> */
/* @0x28a174 cmp r0, #0 */
/* @0x28a178 bne 0x28a158 <spSkeleton_findBoneIndex+0x28> */
/* @0x28a17c mov r0, r4 */
/* @0x28a180 pop {r3, r4, r5, r6, r7, pc} */
/* @0x28a184 mvn r0, #0 */
/* @0x28a188 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x28a18c · spSkeleton_findSlot · size=104 · insn=26 */
/* @0x28a18c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x28a190 mov r9, r0 */
/* @0x28a194 ldr r6, [r0, #0x10] */
/* @0x28a198 mov r7, r1 */
/* @0x28a19c cmp r6, #0 */
/* @0x28a1a0 ble 0x28a1ec <spSkeleton_findSlot+0x60> */
/* @0x28a1a4 ldr r3, [r0] */
/* @0x28a1a8 mov r4, #0 */
/* @0x28a1ac mov r5, r4 */
/* @0x28a1b0 ldr r8, [r3, #0x1c] */
/* @0x28a1b4 b 0x28a1c4 <spSkeleton_findSlot+0x38> */
/* @0x28a1b8 cmp r5, r6 */
/* @0x28a1bc add r4, r4, #4 */
/* @0x28a1c0 beq 0x28a1ec <spSkeleton_findSlot+0x60> */
/* @0x28a1c4 ldr r3, [r8, r4] */
/* @0x28a1c8 mov r1, r7 */
/* @0x28a1cc add r5, r5, #1 */
/* @0x28a1d0 ldr r0, [r3, #0x4] */
/* @0x28a1d4 bl 0xb6574 <strcmp@plt> */
/* @0x28a1d8 cmp r0, #0 */
/* @0x28a1dc bne 0x28a1b8 <spSkeleton_findSlot+0x2c> */
/* @0x28a1e0 ldr r3, [r9, #0x14] */
/* @0x28a1e4 ldr r0, [r3, r4] */
/* @0x28a1e8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x28a1ec mov r0, #0 */
/* @0x28a1f0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x28a1f4 · spSkeleton_findSlotIndex · size=92 · insn=23 */
/* @0x28a1f4 push {r3, r4, r5, r6, r7, lr} */
/* @0x28a1f8 mov r7, r1 */
/* @0x28a1fc ldr r6, [r0, #0x10] */
/* @0x28a200 cmp r6, #0 */
/* @0x28a204 ble 0x28a248 <spSkeleton_findSlotIndex+0x54> */
/* @0x28a208 ldr r3, [r0] */
/* @0x28a20c mov r4, #0 */
/* @0x28a210 ldr r5, [r3, #0x1c] */
/* @0x28a214 sub r5, r5, #4 */
/* @0x28a218 b 0x28a228 <spSkeleton_findSlotIndex+0x34> */
/* @0x28a21c add r4, r4, #1 */
/* @0x28a220 cmp r4, r6 */
/* @0x28a224 beq 0x28a248 <spSkeleton_findSlotIndex+0x54> */
/* @0x28a228 ldr r3, [r5, #0x4]! */
/* @0x28a22c mov r1, r7 */
/* @0x28a230 ldr r0, [r3, #0x4] */
/* @0x28a234 bl 0xb6574 <strcmp@plt> */
/* @0x28a238 cmp r0, #0 */
/* @0x28a23c bne 0x28a21c <spSkeleton_findSlotIndex+0x28> */
/* @0x28a240 mov r0, r4 */
/* @0x28a244 pop {r3, r4, r5, r6, r7, pc} */
/* @0x28a248 mvn r0, #0 */
/* @0x28a24c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x28a250 · spSkeleton_setSkin · size=140 · insn=35 */
/* @0x28a250 push {r3, r4, r5, r6, r7, lr} */
/* @0x28a254 subs r7, r1, #0 */
/* @0x28a258 mov r5, r0 */
/* @0x28a25c beq 0x28a278 <spSkeleton_setSkin+0x28> */
/* @0x28a260 ldr r2, [r0, #0x38] */
/* @0x28a264 cmp r2, #0 */
/* @0x28a268 beq 0x28a280 <spSkeleton_setSkin+0x30> */
/* @0x28a26c mov r0, r7 */
/* @0x28a270 mov r1, r5 */
/* @0x28a274 bl 0x28ed9c <spSkin_attachAll> */
/* @0x28a278 str r7, [r5, #0x38] */
/* @0x28a27c pop {r3, r4, r5, r6, r7, pc} */
/* @0x28a280 ldr r12, [r0, #0x10] */
/* @0x28a284 cmp r12, #0 */
/* @0x28a288 movgt r4, r2 */
/* @0x28a28c ble 0x28a278 <spSkeleton_setSkin+0x28> */
/* @0x28a290 ldr r3, [r5, #0x14] */
/* @0x28a294 mov r1, r4 */
/* @0x28a298 mov r0, r7 */
/* @0x28a29c ldr r6, [r3, r4, lsl #2] */
/* @0x28a2a0 ldr r3, [r6] */
/* @0x28a2a4 ldr r2, [r3, #0xc] */
/* @0x28a2a8 cmp r2, #0 */
/* @0x28a2ac beq 0x28a2c8 <spSkeleton_setSkin+0x78> */
/* @0x28a2b0 bl 0x28ed00 <spSkin_getAttachment> */
/* @0x28a2b4 subs r1, r0, #0 */
/* @0x28a2b8 mov r0, r6 */
/* @0x28a2bc beq 0x28a2c4 <spSkeleton_setSkin+0x74> */
/* @0x28a2c0 bl 0x28ee1c <spSlot_setAttachment> */
/* @0x28a2c4 ldr r12, [r5, #0x10] */
/* @0x28a2c8 add r4, r4, #1 */
/* @0x28a2cc cmp r12, r4 */
/* @0x28a2d0 bgt 0x28a290 <spSkeleton_setSkin+0x40> */
/* @0x28a2d4 str r7, [r5, #0x38] */
/* @0x28a2d8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x28a2dc · spSkeleton_setSkinByName · size=56 · insn=14 */
/* @0x28a2dc cmp r1, #0 */
/* @0x28a2e0 push {r4, lr} */
/* @0x28a2e4 mov r4, r0 */
/* @0x28a2e8 beq 0x28a300 <spSkeleton_setSkinByName+0x24> */
/* @0x28a2ec ldr r0, [r0] */
/* @0x28a2f0 bl 0x28b124 <spSkeletonData_findSkin> */
/* @0x28a2f4 subs r1, r0, #0 */
/* @0x28a2f8 beq 0x28a30c <spSkeleton_setSkinByName+0x30> */
/* @0x28a2fc mov r0, r4 */
/* @0x28a300 bl 0x28a250 <spSkeleton_setSkin> */
/* @0x28a304 mov r0, #1 */
/* @0x28a308 pop {r4, pc} */
/* @0x28a30c mov r0, r1 */
/* @0x28a310 pop {r4, pc} */

/* ── FUNC 0x28a314 · spSkeleton_getAttachmentForSlotIndex · size=92 · insn=23 */
/* @0x28a314 cmn r1, #1 */
/* @0x28a318 push {r4, r5, r6, lr} */
/* @0x28a31c mov r4, r1 */
/* @0x28a320 mov r5, r0 */
/* @0x28a324 mov r6, r2 */
/* @0x28a328 beq 0x28a364 <spSkeleton_getAttachmentForSlotIndex+0x50> */
/* @0x28a32c ldr r0, [r0, #0x38] */
/* @0x28a330 cmp r0, #0 */
/* @0x28a334 beq 0x28a344 <spSkeleton_getAttachmentForSlotIndex+0x30> */
/* @0x28a338 bl 0x28ed00 <spSkin_getAttachment> */
/* @0x28a33c cmp r0, #0 */
/* @0x28a340 popne {r4, r5, r6, pc} */
/* @0x28a344 ldr r3, [r5] */
/* @0x28a348 ldr r0, [r3, #0x28] */
/* @0x28a34c cmp r0, #0 */
/* @0x28a350 beq 0x28a36c <spSkeleton_getAttachmentForSlotIndex+0x58> */
/* @0x28a354 mov r1, r4 */
/* @0x28a358 mov r2, r6 */
/* @0x28a35c pop {r4, r5, r6, lr} */
/* @0x28a360 b 0x28ed00 <spSkin_getAttachment> */
/* @0x28a364 mov r0, #0 */
/* @0x28a368 pop {r4, r5, r6, pc} */
/* @0x28a36c pop {r4, r5, r6, pc} */

/* ── FUNC 0x28a370 · spSkeleton_getAttachmentForSlotName · size=40 · insn=10 */
/* @0x28a370 push {r3, r4, r5, lr} */
/* @0x28a374 mov r4, r0 */
/* @0x28a378 ldr r0, [r0] */
/* @0x28a37c mov r5, r2 */
/* @0x28a380 bl 0x28b0cc <spSkeletonData_findSlotIndex> */
/* @0x28a384 mov r2, r5 */
/* @0x28a388 mov r1, r0 */
/* @0x28a38c mov r0, r4 */
/* @0x28a390 pop {r3, r4, r5, lr} */
/* @0x28a394 b 0x28a314 <spSkeleton_getAttachmentForSlotIndex> */

/* ── FUNC 0x28a398 · spSkeleton_setAttachment · size=160 · insn=40 */
/* @0x28a398 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x28a39c mov r9, r0 */
/* @0x28a3a0 ldr r7, [r0, #0x10] */
/* @0x28a3a4 mov r8, r1 */
/* @0x28a3a8 mov r10, r2 */
/* @0x28a3ac cmp r7, #0 */
/* @0x28a3b0 ble 0x28a41c <spSkeleton_setAttachment+0x84> */
/* @0x28a3b4 ldr r5, [r0, #0x14] */
/* @0x28a3b8 mov r4, #0 */
/* @0x28a3bc sub r5, r5, #4 */
/* @0x28a3c0 b 0x28a3d0 <spSkeleton_setAttachment+0x38> */
/* @0x28a3c4 add r4, r4, #1 */
/* @0x28a3c8 cmp r4, r7 */
/* @0x28a3cc beq 0x28a41c <spSkeleton_setAttachment+0x84> */
/* @0x28a3d0 ldr r6, [r5, #0x4]! */
/* @0x28a3d4 mov r1, r8 */
/* @0x28a3d8 ldr r3, [r6] */
/* @0x28a3dc ldr r0, [r3, #0x4] */
/* @0x28a3e0 bl 0xb6574 <strcmp@plt> */
/* @0x28a3e4 cmp r0, #0 */
/* @0x28a3e8 bne 0x28a3c4 <spSkeleton_setAttachment+0x2c> */
/* @0x28a3ec cmp r10, #0 */
/* @0x28a3f0 beq 0x28a424 <spSkeleton_setAttachment+0x8c> */
/* @0x28a3f4 mov r1, r4 */
/* @0x28a3f8 mov r0, r9 */
/* @0x28a3fc mov r2, r10 */
/* @0x28a400 bl 0x28a314 <spSkeleton_getAttachmentForSlotIndex> */
/* @0x28a404 subs r1, r0, #0 */
/* @0x28a408 beq 0x28a41c <spSkeleton_setAttachment+0x84> */
/* @0x28a40c mov r0, r6 */
/* @0x28a410 bl 0x28ee1c <spSlot_setAttachment> */
/* @0x28a414 mov r0, #1 */
/* @0x28a418 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x28a41c mov r0, #0 */
/* @0x28a420 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x28a424 mov r0, r6 */
/* @0x28a428 mov r1, r10 */
/* @0x28a42c bl 0x28ee1c <spSlot_setAttachment> */
/* @0x28a430 mov r0, #1 */
/* @0x28a434 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x28a438 · spSkeleton_findIkConstraint · size=96 · insn=24 */
/* @0x28a438 push {r4, r5, r6, r7, r8, lr} */
/* @0x28a43c mov r8, r1 */
/* @0x28a440 ldr r7, [r0, #0x1c] */
/* @0x28a444 cmp r7, #0 */
/* @0x28a448 ble 0x28a48c <spSkeleton_findIkConstraint+0x54> */
/* @0x28a44c ldr r6, [r0, #0x20] */
/* @0x28a450 mov r4, #0 */
/* @0x28a454 sub r6, r6, #4 */
/* @0x28a458 b 0x28a464 <spSkeleton_findIkConstraint+0x2c> */
/* @0x28a45c cmp r4, r7 */
/* @0x28a460 beq 0x28a48c <spSkeleton_findIkConstraint+0x54> */
/* @0x28a464 ldr r5, [r6, #0x4]! */
/* @0x28a468 mov r1, r8 */
/* @0x28a46c add r4, r4, #1 */
/* @0x28a470 ldr r3, [r5] */
/* @0x28a474 ldr r0, [r3] */
/* @0x28a478 bl 0xb6574 <strcmp@plt> */
/* @0x28a47c cmp r0, #0 */
/* @0x28a480 bne 0x28a45c <spSkeleton_findIkConstraint+0x24> */
/* @0x28a484 mov r0, r5 */
/* @0x28a488 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28a48c mov r5, #0 */
/* @0x28a490 mov r0, r5 */
/* @0x28a494 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x28a498 · spSkeleton_findTransformConstraint · size=96 · insn=24 */
/* @0x28a498 push {r4, r5, r6, r7, r8, lr} */
/* @0x28a49c mov r8, r1 */
/* @0x28a4a0 ldr r7, [r0, #0x28] */
/* @0x28a4a4 cmp r7, #0 */
/* @0x28a4a8 ble 0x28a4ec <spSkeleton_findTransformConstraint+0x54> */
/* @0x28a4ac ldr r6, [r0, #0x2c] */
/* @0x28a4b0 mov r4, #0 */
/* @0x28a4b4 sub r6, r6, #4 */
/* @0x28a4b8 b 0x28a4c4 <spSkeleton_findTransformConstraint+0x2c> */
/* @0x28a4bc cmp r4, r7 */
/* @0x28a4c0 beq 0x28a4ec <spSkeleton_findTransformConstraint+0x54> */
/* @0x28a4c4 ldr r5, [r6, #0x4]! */
/* @0x28a4c8 mov r1, r8 */
/* @0x28a4cc add r4, r4, #1 */
/* @0x28a4d0 ldr r3, [r5] */
/* @0x28a4d4 ldr r0, [r3] */
/* @0x28a4d8 bl 0xb6574 <strcmp@plt> */
/* @0x28a4dc cmp r0, #0 */
/* @0x28a4e0 bne 0x28a4bc <spSkeleton_findTransformConstraint+0x24> */
/* @0x28a4e4 mov r0, r5 */
/* @0x28a4e8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28a4ec mov r5, #0 */
/* @0x28a4f0 mov r0, r5 */
/* @0x28a4f4 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x28a4f8 · spSkeleton_findPathConstraint · size=96 · insn=24 */
/* @0x28a4f8 push {r4, r5, r6, r7, r8, lr} */
/* @0x28a4fc mov r8, r1 */
/* @0x28a500 ldr r7, [r0, #0x30] */
/* @0x28a504 cmp r7, #0 */
/* @0x28a508 ble 0x28a54c <spSkeleton_findPathConstraint+0x54> */
/* @0x28a50c ldr r6, [r0, #0x34] */
/* @0x28a510 mov r4, #0 */
/* @0x28a514 sub r6, r6, #4 */
/* @0x28a518 b 0x28a524 <spSkeleton_findPathConstraint+0x2c> */
/* @0x28a51c cmp r4, r7 */
/* @0x28a520 beq 0x28a54c <spSkeleton_findPathConstraint+0x54> */
/* @0x28a524 ldr r5, [r6, #0x4]! */
/* @0x28a528 mov r1, r8 */
/* @0x28a52c add r4, r4, #1 */
/* @0x28a530 ldr r3, [r5] */
/* @0x28a534 ldr r0, [r3] */
/* @0x28a538 bl 0xb6574 <strcmp@plt> */
/* @0x28a53c cmp r0, #0 */
/* @0x28a540 bne 0x28a51c <spSkeleton_findPathConstraint+0x24> */
/* @0x28a544 mov r0, r5 */
/* @0x28a548 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28a54c mov r5, #0 */
/* @0x28a550 mov r0, r5 */
/* @0x28a554 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x28a558 · spSkeleton_update · size=20 · insn=5 */
/* @0x28a558 vmov s14, r1 */
/* @0x28a55c vldr s15, [r0, #76] */
/* @0x28a560 vadd.f32 s15, s15, s14 */
/* @0x28a564 vstr s15, [r0, #76] */
/* @0x28a568 bx lr */

/* ── FUNC 0x28a56c · spPolygon_create · size=76 · insn=19 */
/* @0x28a56c push {r4, r5, r6, lr} */
/* @0x28a570 mov r3, #37 */
/* @0x28a574 ldr r6, [pc, #0x38] */
/* @0x28a578 mov r5, r0 */
/* @0x28a57c mov r1, #12 */
/* @0x28a580 mov r0, #1 */
/* @0x28a584 add r6, pc, r6 */
/* @0x28a588 mov r2, r6 */
/* @0x28a58c bl 0x285c4c <_calloc> */
/* @0x28a590 mov r1, r6 */
/* @0x28a594 mov r2, #39 */
/* @0x28a598 mov r4, r0 */
/* @0x28a59c str r5, [r0, #0x8] */
/* @0x28a5a0 lsl r0, r5, #2 */
/* @0x28a5a4 bl 0x285c10 <_malloc> */
/* @0x28a5a8 str r0, [r4] */
/* @0x28a5ac mov r0, r4 */
/* @0x28a5b0 pop {r4, r5, r6, pc} */
/* @0x28a5b4 andeq sp, r12, r8, ror #9 */

/* ── FUNC 0x28a5b8 · spPolygon_dispose · size=28 · insn=7 */
/* @0x28a5b8 push {r4, lr} */
/* @0x28a5bc mov r4, r0 */
/* @0x28a5c0 ldr r0, [r0] */
/* @0x28a5c4 bl 0x285c80 <_free> */
/* @0x28a5c8 mov r0, r4 */
/* @0x28a5cc pop {r4, lr} */
/* @0x28a5d0 b 0x285c80 <_free> */

/* ── FUNC 0x28a5d4 · spPolygon_containsPoint · size=212 · insn=53 */
/* @0x28a5d4 push {r4, r5, r6} */
/* @0x28a5d8 vmov s9, r1 */
/* @0x28a5dc ldr r5, [r0, #0x4] */
/* @0x28a5e0 vmov s14, r2 */
/* @0x28a5e4 cmp r5, #0 */
/* @0x28a5e8 sub r12, r5, #2 */
/* @0x28a5ec ble 0x28a6a0 <spPolygon_containsPoint+0xcc> */
/* @0x28a5f0 ldr r6, [r0] */
/* @0x28a5f4 mov r2, #0 */
/* @0x28a5f8 mov r0, r2 */
/* @0x28a5fc add r1, r6, r5, lsl #2 */
/* @0x28a600 add r3, r6, #4 */
/* @0x28a604 vldr s13, [r1, #-4] */
/* @0x28a608 b 0x28a650 <spPolygon_containsPoint+0x7c> */
/* @0x28a60c vcmpe.f32 s14, s13 */
/* @0x28a610 vmrs APSR_nzcv, fpscr */
/* @0x28a614 bhi 0x28a670 <spPolygon_containsPoint+0x9c> */
/* @0x28a618 vsub.f32 s13, s13, s15 */
/* @0x28a61c vldr s12, [r3, #-4] */
/* @0x28a620 vldr s11, [r4] */
/* @0x28a624 vsub.f32 s10, s14, s15 */
/* @0x28a628 vdiv.f32 s13, s10, s13 */
/* @0x28a62c vsub.f32 s11, s11, s12 */
/* @0x28a630 vmla.f32 s12, s13, s11 */
/* @0x28a634 vcmpe.f32 s12, s9 */
/* @0x28a638 vmrs APSR_nzcv, fpscr */
/* @0x28a63c eormi r0, r0, #1 */
/* @0x28a640 cmp r5, r1 */
/* @0x28a644 vmov.f32 s13, s15 */
/* @0x28a648 add r3, r3, #8 */
/* @0x28a64c ble 0x28a698 <spPolygon_containsPoint+0xc4> */
/* @0x28a650 vldr s15, [r3] */
/* @0x28a654 vcmpe.f32 s15, s14 */
/* @0x28a658 add r1, r2, #2 */
/* @0x28a65c add r4, r6, r12, lsl #2 */
/* @0x28a660 mov r12, r2 */
/* @0x28a664 mov r2, r1 */
/* @0x28a668 vmrs APSR_nzcv, fpscr */
/* @0x28a66c bmi 0x28a60c <spPolygon_containsPoint+0x38> */
/* @0x28a670 vcmpe.f32 s14, s13 */
/* @0x28a674 vmrs APSR_nzcv, fpscr */
/* @0x28a678 ble 0x28a640 <spPolygon_containsPoint+0x6c> */
/* @0x28a67c vcmpe.f32 s15, s14 */
/* @0x28a680 vmrs APSR_nzcv, fpscr */
/* @0x28a684 bge 0x28a618 <spPolygon_containsPoint+0x44> */
/* @0x28a688 cmp r5, r1 */
/* @0x28a68c vmov.f32 s13, s15 */
/* @0x28a690 add r3, r3, #8 */
/* @0x28a694 bgt 0x28a650 <spPolygon_containsPoint+0x7c> */
/* @0x28a698 pop {r4, r5, r6} */
/* @0x28a69c bx lr */
/* @0x28a6a0 mov r0, #0 */
/* @0x28a6a4 b 0x28a698 <spPolygon_containsPoint+0xc4> */

/* ── FUNC 0x28a6a8 · spPolygon_intersectsSegment · size=396 · insn=99 */
/* @0x28a6a8 vmov s1, r2 */
/* @0x28a6ac ldr r12, [r0, #0x4] */
/* @0x28a6b0 vmov s2, r3 */
/* @0x28a6b4 ldr r3, [r0] */
/* @0x28a6b8 vmov s3, r1 */
/* @0x28a6bc sub r2, r12, #-1073741822 */
/* @0x28a6c0 vmul.f32 s5, s1, s2 */
/* @0x28a6c4 cmp r12, #0 */
/* @0x28a6c8 vldr s0, [sp] */
/* @0x28a6cc add r2, r3, r2, lsl #2 */
/* @0x28a6d0 vldr s13, [r2] */
/* @0x28a6d4 vldr s9, [r2, #4] */
/* @0x28a6d8 vnmls.f32 s5, s3, s0 */
/* @0x28a6dc vsub.f32 s6, s3, s2 */
/* @0x28a6e0 vsub.f32 s4, s1, s0 */
/* @0x28a6e4 ble 0x28a824 <spPolygon_intersectsSegment+0x17c> */
/* @0x28a6e8 add r3, r3, #4 */
/* @0x28a6ec mov r2, #0 */
/* @0x28a6f0 b 0x28a784 <spPolygon_intersectsSegment+0xdc> */
/* @0x28a6f4 vcmpe.f32 s15, s14 */
/* @0x28a6f8 vmrs APSR_nzcv, fpscr */
/* @0x28a6fc blt 0x28a7bc <spPolygon_intersectsSegment+0x114> */
/* @0x28a700 vcmpe.f32 s3, s14 */
/* @0x28a704 vmrs APSR_nzcv, fpscr */
/* @0x28a708 bhi 0x28a7e0 <spPolygon_intersectsSegment+0x138> */
/* @0x28a70c vcmpe.f32 s2, s14 */
/* @0x28a710 vmrs APSR_nzcv, fpscr */
/* @0x28a714 blt 0x28a7e0 <spPolygon_intersectsSegment+0x138> */
/* @0x28a718 vmul.f32 s10, s4, s10 */
/* @0x28a71c vnmls.f32 s10, s5, s7 */
/* @0x28a720 vdiv.f32 s11, s10, s11 */
/* @0x28a724 vcmpe.f32 s11, s9 */
/* @0x28a728 vmrs APSR_nzcv, fpscr */
/* @0x28a72c blt 0x28a7fc <spPolygon_intersectsSegment+0x154> */
/* @0x28a730 vcmpe.f32 s12, s11 */
/* @0x28a734 vmrs APSR_nzcv, fpscr */
/* @0x28a738 blt 0x28a7fc <spPolygon_intersectsSegment+0x154> */
/* @0x28a73c vcmpe.f32 s1, s11 */
/* @0x28a740 vmrs APSR_nzcv, fpscr */
/* @0x28a744 bhi 0x28a754 <spPolygon_intersectsSegment+0xac> */
/* @0x28a748 vcmpe.f32 s0, s11 */
/* @0x28a74c vmrs APSR_nzcv, fpscr */
/* @0x28a750 bge 0x28a82c <spPolygon_intersectsSegment+0x184> */
/* @0x28a754 vcmpe.f32 s0, s11 */
/* @0x28a758 vmrs APSR_nzcv, fpscr */
/* @0x28a75c bhi 0x28a76c <spPolygon_intersectsSegment+0xc4> */
/* @0x28a760 vcmpe.f32 s1, s11 */
/* @0x28a764 vmrs APSR_nzcv, fpscr */
/* @0x28a768 bge 0x28a82c <spPolygon_intersectsSegment+0x184> */
/* @0x28a76c add r2, r2, #2 */
/* @0x28a770 add r3, r3, #8 */
/* @0x28a774 cmp r12, r2 */
/* @0x28a778 ble 0x28a824 <spPolygon_intersectsSegment+0x17c> */
/* @0x28a77c vmov.f32 s9, s12 */
/* @0x28a780 vmov.f32 s13, s15 */
/* @0x28a784 vldr s15, [r3, #-4] */
/* @0x28a788 vldr s12, [r3] */
/* @0x28a78c vmul.f32 s10, s9, s15 */
/* @0x28a790 vnmls.f32 s10, s13, s12 */
/* @0x28a794 vsub.f32 s8, s13, s15 */
/* @0x28a798 vmul.f32 s14, s6, s10 */
/* @0x28a79c vmul.f32 s11, s4, s8 */
/* @0x28a7a0 vsub.f32 s7, s9, s12 */
/* @0x28a7a4 vnmls.f32 s14, s5, s8 */
/* @0x28a7a8 vnmls.f32 s11, s6, s7 */
/* @0x28a7ac vdiv.f32 s14, s14, s11 */
/* @0x28a7b0 vcmpe.f32 s14, s13 */
/* @0x28a7b4 vmrs APSR_nzcv, fpscr */
/* @0x28a7b8 bge 0x28a6f4 <spPolygon_intersectsSegment+0x4c> */
/* @0x28a7bc vcmpe.f32 s15, s14 */
/* @0x28a7c0 vmrs APSR_nzcv, fpscr */
/* @0x28a7c4 bhi 0x28a76c <spPolygon_intersectsSegment+0xc4> */
/* @0x28a7c8 vcmpe.f32 s14, s13 */
/* @0x28a7cc vmrs APSR_nzcv, fpscr */
/* @0x28a7d0 bhi 0x28a76c <spPolygon_intersectsSegment+0xc4> */
/* @0x28a7d4 vcmpe.f32 s3, s14 */
/* @0x28a7d8 vmrs APSR_nzcv, fpscr */
/* @0x28a7dc bls 0x28a70c <spPolygon_intersectsSegment+0x64> */
/* @0x28a7e0 vcmpe.f32 s2, s14 */
/* @0x28a7e4 vmrs APSR_nzcv, fpscr */
/* @0x28a7e8 bhi 0x28a76c <spPolygon_intersectsSegment+0xc4> */
/* @0x28a7ec vcmpe.f32 s3, s14 */
/* @0x28a7f0 vmrs APSR_nzcv, fpscr */
/* @0x28a7f4 blt 0x28a76c <spPolygon_intersectsSegment+0xc4> */
/* @0x28a7f8 b 0x28a718 <spPolygon_intersectsSegment+0x70> */
/* @0x28a7fc vcmpe.f32 s12, s11 */
/* @0x28a800 vmrs APSR_nzcv, fpscr */
/* @0x28a804 bhi 0x28a76c <spPolygon_intersectsSegment+0xc4> */
/* @0x28a808 vcmpe.f32 s11, s9 */
/* @0x28a80c vmrs APSR_nzcv, fpscr */
/* @0x28a810 bls 0x28a73c <spPolygon_intersectsSegment+0x94> */
/* @0x28a814 add r2, r2, #2 */
/* @0x28a818 add r3, r3, #8 */
/* @0x28a81c cmp r12, r2 */
/* @0x28a820 bgt 0x28a77c <spPolygon_intersectsSegment+0xd4> */
/* @0x28a824 mov r0, #0 */
/* @0x28a828 bx lr */
/* @0x28a82c mov r0, #1 */
/* @0x28a830 bx lr */

/* ── FUNC 0x28a834 · spSkeletonBounds_create · size=36 · insn=9 */
/* @0x28a834 ldr r2, [pc, #0x18] */
/* @0x28a838 mov r1, #32 */
/* @0x28a83c push {r3, lr} */
/* @0x28a840 add r2, pc, r2 */
/* @0x28a844 mov r3, #93 */
/* @0x28a848 mov r0, #1 */
/* @0x28a84c bl 0x285c4c <_calloc> */
/* @0x28a850 pop {r3, pc} */
/* @0x28a854 andeq sp, r12, r12, lsr #4 */

/* ── FUNC 0x28a858 · spSkeletonBounds_dispose · size=92 · insn=23 */
/* @0x28a858 push {r3, r4, r5, lr} */
/* @0x28a85c mov r5, r0 */
/* @0x28a860 ldr r3, [r0, #0x1c] */
/* @0x28a864 ldr r2, [r0, #0x8] */
/* @0x28a868 cmp r3, #0 */
/* @0x28a86c movgt r4, #0 */
/* @0x28a870 ble 0x28a898 <spSkeletonBounds_dispose+0x40> */
/* @0x28a874 ldr r0, [r2, r4, lsl #2] */
/* @0x28a878 add r4, r4, #1 */
/* @0x28a87c cmp r0, #0 */
/* @0x28a880 beq 0x28a890 <spSkeletonBounds_dispose+0x38> */
/* @0x28a884 bl 0x28a5b8 <spPolygon_dispose> */
/* @0x28a888 ldr r2, [r5, #0x8] */
/* @0x28a88c ldr r3, [r5, #0x1c] */
/* @0x28a890 cmp r3, r4 */
/* @0x28a894 bgt 0x28a874 <spSkeletonBounds_dispose+0x1c> */
/* @0x28a898 mov r0, r2 */
/* @0x28a89c bl 0x285c80 <_free> */
/* @0x28a8a0 ldr r0, [r5, #0x4] */
/* @0x28a8a4 bl 0x285c80 <_free> */
/* @0x28a8a8 mov r0, r5 */
/* @0x28a8ac pop {r3, r4, r5, lr} */
/* @0x28a8b0 b 0x285c80 <_free> */

/* ── FUNC 0x28a8b4 · spSkeletonBounds_update · size=492 · insn=123 */
/* @0x28a8b4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x28a8b8 mov r10, r1 */
/* @0x28a8bc ldr r3, [r0, #0x1c] */
/* @0x28a8c0 mov r4, r0 */
/* @0x28a8c4 ldr r1, [r1, #0x10] */
/* @0x28a8c8 mov r9, r2 */
/* @0x28a8cc cmp r3, r1 */
/* @0x28a8d0 blt 0x28aa38 <spSkeletonBounds_update+0x184> */
/* @0x28a8d4 cmp r1, #0 */
/* @0x28a8d8 mov r2, #1325400064 */
/* @0x28a8dc mov r3, #-822083584 */
/* @0x28a8e0 mov r5, #0 */
/* @0x28a8e4 str r2, [r4, #0xc] */
/* @0x28a8e8 str r2, [r4, #0x10] */
/* @0x28a8ec str r3, [r4, #0x14] */
/* @0x28a8f0 str r3, [r4, #0x18] */
/* @0x28a8f4 str r5, [r4] */
/* @0x28a8f8 bgt 0x28a90c <spSkeletonBounds_update+0x58> */
/* @0x28a8fc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x28a900 add r5, r5, #1 */
/* @0x28a904 cmp r1, r5 */
/* @0x28a908 ble 0x28aa34 <spSkeletonBounds_update+0x180> */
/* @0x28a90c ldr r3, [r10, #0x14] */
/* @0x28a910 ldr r7, [r3, r5, lsl #2] */
/* @0x28a914 ldr r6, [r7, #0x18] */
/* @0x28a918 cmp r6, #0 */
/* @0x28a91c beq 0x28a900 <spSkeletonBounds_update+0x4c> */
/* @0x28a920 ldr r3, [r6, #0x4] */
/* @0x28a924 cmp r3, #1 */
/* @0x28a928 bne 0x28a900 <spSkeletonBounds_update+0x4c> */
/* @0x28a92c ldr r3, [r4] */
/* @0x28a930 ldr r2, [r4, #0x4] */
/* @0x28a934 str r6, [r2, r3, lsl #2] */
/* @0x28a938 ldr r2, [r4, #0x8] */
/* @0x28a93c add r11, r2, r3, lsl #2 */
/* @0x28a940 ldr r8, [r2, r3, lsl #2] */
/* @0x28a944 cmp r8, #0 */
/* @0x28a948 beq 0x28a970 <spSkeletonBounds_update+0xbc> */
/* @0x28a94c ldr r3, [r6, #0x20] */
/* @0x28a950 ldr r2, [r8, #0x8] */
/* @0x28a954 cmp r2, r3 */
/* @0x28a958 bge 0x28a984 <spSkeletonBounds_update+0xd0> */
/* @0x28a95c mov r0, r8 */
/* @0x28a960 bl 0x28a5b8 <spPolygon_dispose> */
/* @0x28a964 ldr r11, [r4] */
/* @0x28a968 ldr r3, [r4, #0x8] */
/* @0x28a96c add r11, r3, r11, lsl #2 */
/* @0x28a970 ldr r0, [r6, #0x20] */
/* @0x28a974 bl 0x28a56c <spPolygon_create> */
/* @0x28a978 ldr r3, [r6, #0x20] */
/* @0x28a97c mov r8, r0 */
/* @0x28a980 str r0, [r11] */
/* @0x28a984 str r3, [r8, #0x4] */
/* @0x28a988 mov r0, r6 */
/* @0x28a98c mov r1, r7 */
/* @0x28a990 ldr r2, [r8] */
/* @0x28a994 bl 0x285b40 <spBoundingBoxAttachment_computeWorldVertices> */
/* @0x28a998 cmp r9, #0 */
/* @0x28a99c beq 0x28aa18 <spSkeletonBounds_update+0x164> */
/* @0x28a9a0 ldr r2, [r8, #0x4] */
/* @0x28a9a4 cmp r2, #0 */
/* @0x28a9a8 ble 0x28aa18 <spSkeletonBounds_update+0x164> */
/* @0x28a9ac sub r2, r2, #1 */
/* @0x28a9b0 ldr r3, [r8] */
/* @0x28a9b4 lsr r2, r2, #1 */
/* @0x28a9b8 add r1, r3, #12 */
/* @0x28a9bc add r3, r3, #4 */
/* @0x28a9c0 add r2, r1, r2, lsl #3 */
/* @0x28a9c4 vldr s14, [r3, #-4] */
/* @0x28a9c8 vldr s15, [r4, #12] */
/* @0x28a9cc vcmpe.f32 s14, s15 */
/* @0x28a9d0 vldr s13, [r4, #16] */
/* @0x28a9d4 vldr s15, [r3] */
/* @0x28a9d8 add r3, r3, #8 */
/* @0x28a9dc vmrs APSR_nzcv, fpscr */
/* @0x28a9e0 vcmpe.f32 s15, s13 */
/* @0x28a9e4 vstrmi s14, [r4, #12] */
/* @0x28a9e8 vldr s13, [r4, #20] */
/* @0x28a9ec vmrs APSR_nzcv, fpscr */
/* @0x28a9f0 vcmpe.f32 s14, s13 */
/* @0x28a9f4 vstrmi s15, [r4, #16] */
/* @0x28a9f8 vmrs APSR_nzcv, fpscr */
/* @0x28a9fc vstrgt s14, [r4, #20] */
/* @0x28aa00 vldr s14, [r4, #24] */
/* @0x28aa04 vcmpe.f32 s15, s14 */
/* @0x28aa08 vmrs APSR_nzcv, fpscr */
/* @0x28aa0c vstrgt s15, [r4, #24] */
/* @0x28aa10 cmp r3, r2 */
/* @0x28aa14 bne 0x28a9c4 <spSkeletonBounds_update+0x110> */
/* @0x28aa18 ldr r1, [r10, #0x10] */
/* @0x28aa1c add r5, r5, #1 */
/* @0x28aa20 ldr r3, [r4] */
/* @0x28aa24 cmp r1, r5 */
/* @0x28aa28 add r3, r3, #1 */
/* @0x28aa2c str r3, [r4] */
/* @0x28aa30 bgt 0x28a90c <spSkeletonBounds_update+0x58> */
/* @0x28aa34 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x28aa38 ldr r0, [r0, #0x4] */
/* @0x28aa3c ldr r5, [pc, #0x58] */
/* @0x28aa40 bl 0x285c80 <_free> */
/* @0x28aa44 ldr r0, [r10, #0x10] */
/* @0x28aa48 mov r2, #113 */
/* @0x28aa4c add r5, pc, r5 */
/* @0x28aa50 lsl r0, r0, #2 */
/* @0x28aa54 mov r1, r5 */
/* @0x28aa58 bl 0x285c10 <_malloc> */
/* @0x28aa5c mov r2, r5 */
/* @0x28aa60 mov r3, #115 */
/* @0x28aa64 mov r1, #4 */
/* @0x28aa68 str r0, [r4, #0x4] */
/* @0x28aa6c ldr r0, [r10, #0x10] */
/* @0x28aa70 bl 0x285c4c <_calloc> */
/* @0x28aa74 ldr r1, [r4, #0x8] */
/* @0x28aa78 ldr r2, [r4, #0x1c] */
/* @0x28aa7c mov r5, r0 */
/* @0x28aa80 bl 0xb65bc <memcpy@plt> */
/* @0x28aa84 ldr r0, [r4, #0x8] */
/* @0x28aa88 bl 0x285c80 <_free> */
/* @0x28aa8c ldr r1, [r10, #0x10] */
/* @0x28aa90 str r5, [r4, #0x8] */
/* @0x28aa94 str r1, [r4, #0x1c] */
/* @0x28aa98 b 0x28a8d4 <spSkeletonBounds_update+0x20> */
/* @0x28aa9c andeq sp, r12, r0, lsr #32 */

/* ── FUNC 0x28aaa0 · spSkeletonBounds_aabbContainsPoint · size=88 · insn=22 */
/* @0x28aaa0 vmov s15, r1 */
/* @0x28aaa4 vldr s14, [r0, #12] */
/* @0x28aaa8 vmov s13, r2 */
/* @0x28aaac vcmpe.f32 s14, s15 */
/* @0x28aab0 vmrs APSR_nzcv, fpscr */
/* @0x28aab4 bhi 0x28aaf0 <spSkeletonBounds_aabbContainsPoint+0x50> */
/* @0x28aab8 vldr s14, [r0, #20] */
/* @0x28aabc vcmpe.f32 s15, s14 */
/* @0x28aac0 vmrs APSR_nzcv, fpscr */
/* @0x28aac4 bhi 0x28aaf0 <spSkeletonBounds_aabbContainsPoint+0x50> */
/* @0x28aac8 vldr s15, [r0, #16] */
/* @0x28aacc vcmpe.f32 s15, s13 */
/* @0x28aad0 vmrs APSR_nzcv, fpscr */
/* @0x28aad4 bhi 0x28aaf0 <spSkeletonBounds_aabbContainsPoint+0x50> */
/* @0x28aad8 vldr s15, [r0, #24] */
/* @0x28aadc vcmpe.f32 s13, s15 */
/* @0x28aae0 vmrs APSR_nzcv, fpscr */
/* @0x28aae4 movhi r0, #0 */
/* @0x28aae8 movls r0, #1 */
/* @0x28aaec bx lr */
/* @0x28aaf0 mov r0, #0 */
/* @0x28aaf4 bx lr */

/* ── FUNC 0x28aaf8 · spSkeletonBounds_aabbIntersectsSegment · size=308 · insn=77 */
/* @0x28aaf8 vmov s15, r1 */
/* @0x28aafc vldr s13, [r0, #12] */
/* @0x28ab00 vmov s14, r2 */
/* @0x28ab04 vldr s9, [sp] */
/* @0x28ab08 vcmpe.f32 s13, s15 */
/* @0x28ab0c vmov s11, r3 */
/* @0x28ab10 vmrs APSR_nzcv, fpscr */
/* @0x28ab14 blt 0x28ab24 <spSkeletonBounds_aabbIntersectsSegment+0x2c> */
/* @0x28ab18 vcmpe.f32 s13, s11 */
/* @0x28ab1c vmrs APSR_nzcv, fpscr */
/* @0x28ab20 bge 0x28ac1c <spSkeletonBounds_aabbIntersectsSegment+0x124> */
/* @0x28ab24 vldr s12, [r0, #16] */
/* @0x28ab28 vcmpe.f32 s12, s14 */
/* @0x28ab2c vmrs APSR_nzcv, fpscr */
/* @0x28ab30 blt 0x28ab40 <spSkeletonBounds_aabbIntersectsSegment+0x48> */
/* @0x28ab34 vcmpe.f32 s12, s9 */
/* @0x28ab38 vmrs APSR_nzcv, fpscr */
/* @0x28ab3c bge 0x28ac1c <spSkeletonBounds_aabbIntersectsSegment+0x124> */
/* @0x28ab40 vldr s10, [r0, #20] */
/* @0x28ab44 vcmpe.f32 s15, s10 */
/* @0x28ab48 vmrs APSR_nzcv, fpscr */
/* @0x28ab4c blt 0x28ab5c <spSkeletonBounds_aabbIntersectsSegment+0x64> */
/* @0x28ab50 vcmpe.f32 s11, s10 */
/* @0x28ab54 vmrs APSR_nzcv, fpscr */
/* @0x28ab58 bge 0x28ac1c <spSkeletonBounds_aabbIntersectsSegment+0x124> */
/* @0x28ab5c vldr s8, [r0, #24] */
/* @0x28ab60 vcmpe.f32 s14, s8 */
/* @0x28ab64 vmrs APSR_nzcv, fpscr */
/* @0x28ab68 bge 0x28ac10 <spSkeletonBounds_aabbIntersectsSegment+0x118> */
/* @0x28ab6c vsub.f32 s9, s9, s14 */
/* @0x28ab70 vsub.f32 s11, s11, s15 */
/* @0x28ab74 vdiv.f32 s11, s9, s11 */
/* @0x28ab78 vsub.f32 s9, s13, s15 */
/* @0x28ab7c vmov.f32 s7, s14 */
/* @0x28ab80 vmla.f32 s7, s9, s11 */
/* @0x28ab84 vcmpe.f32 s12, s7 */
/* @0x28ab88 vmrs APSR_nzcv, fpscr */
/* @0x28ab8c bpl 0x28ab9c <spSkeletonBounds_aabbIntersectsSegment+0xa4> */
/* @0x28ab90 vcmpe.f32 s8, s7 */
/* @0x28ab94 vmrs APSR_nzcv, fpscr */
/* @0x28ab98 bgt 0x28ac24 <spSkeletonBounds_aabbIntersectsSegment+0x12c> */
/* @0x28ab9c vsub.f32 s9, s10, s15 */
/* @0x28aba0 vmov.f32 s7, s14 */
/* @0x28aba4 vmla.f32 s7, s9, s11 */
/* @0x28aba8 vcmpe.f32 s12, s7 */
/* @0x28abac vmrs APSR_nzcv, fpscr */
/* @0x28abb0 bpl 0x28abc0 <spSkeletonBounds_aabbIntersectsSegment+0xc8> */
/* @0x28abb4 vcmpe.f32 s8, s7 */
/* @0x28abb8 vmrs APSR_nzcv, fpscr */
/* @0x28abbc bgt 0x28ac24 <spSkeletonBounds_aabbIntersectsSegment+0x12c> */
/* @0x28abc0 vsub.f32 s12, s12, s14 */
/* @0x28abc4 vdiv.f32 s12, s12, s11 */
/* @0x28abc8 vadd.f32 s12, s12, s15 */
/* @0x28abcc vcmpe.f32 s13, s12 */
/* @0x28abd0 vmrs APSR_nzcv, fpscr */
/* @0x28abd4 bpl 0x28abe4 <spSkeletonBounds_aabbIntersectsSegment+0xec> */
/* @0x28abd8 vcmpe.f32 s10, s12 */
/* @0x28abdc vmrs APSR_nzcv, fpscr */
/* @0x28abe0 bgt 0x28ac24 <spSkeletonBounds_aabbIntersectsSegment+0x12c> */
/* @0x28abe4 vsub.f32 s14, s8, s14 */
/* @0x28abe8 vdiv.f32 s11, s14, s11 */
/* @0x28abec vadd.f32 s15, s11, s15 */
/* @0x28abf0 vcmpe.f32 s13, s15 */
/* @0x28abf4 vmrs APSR_nzcv, fpscr */
/* @0x28abf8 bpl 0x28ac1c <spSkeletonBounds_aabbIntersectsSegment+0x124> */
/* @0x28abfc vcmpe.f32 s10, s15 */
/* @0x28ac00 vmrs APSR_nzcv, fpscr */
/* @0x28ac04 movle r0, #0 */
/* @0x28ac08 movgt r0, #1 */
/* @0x28ac0c bx lr */
/* @0x28ac10 vcmpe.f32 s9, s8 */
/* @0x28ac14 vmrs APSR_nzcv, fpscr */
/* @0x28ac18 blt 0x28ab6c <spSkeletonBounds_aabbIntersectsSegment+0x74> */
/* @0x28ac1c mov r0, #0 */
/* @0x28ac20 bx lr */
/* @0x28ac24 mov r0, #1 */
/* @0x28ac28 bx lr */

/* ── FUNC 0x28ac2c · spSkeletonBounds_aabbIntersectsSkeleton · size=96 · insn=24 */
/* @0x28ac2c vldr s14, [r0, #12] */
/* @0x28ac30 vldr s15, [r1, #20] */
/* @0x28ac34 vcmpe.f32 s14, s15 */
/* @0x28ac38 vmrs APSR_nzcv, fpscr */
/* @0x28ac3c bpl 0x28ac84 <spSkeletonBounds_aabbIntersectsSkeleton+0x58> */
/* @0x28ac40 vldr s14, [r0, #20] */
/* @0x28ac44 vldr s15, [r1, #12] */
/* @0x28ac48 vcmpe.f32 s14, s15 */
/* @0x28ac4c vmrs APSR_nzcv, fpscr */
/* @0x28ac50 ble 0x28ac84 <spSkeletonBounds_aabbIntersectsSkeleton+0x58> */
/* @0x28ac54 vldr s14, [r0, #16] */
/* @0x28ac58 vldr s15, [r1, #24] */
/* @0x28ac5c vcmpe.f32 s14, s15 */
/* @0x28ac60 vmrs APSR_nzcv, fpscr */
/* @0x28ac64 bpl 0x28ac84 <spSkeletonBounds_aabbIntersectsSkeleton+0x58> */
/* @0x28ac68 vldr s14, [r0, #24] */
/* @0x28ac6c vldr s15, [r1, #16] */
/* @0x28ac70 vcmpe.f32 s14, s15 */
/* @0x28ac74 vmrs APSR_nzcv, fpscr */
/* @0x28ac78 movle r0, #0 */
/* @0x28ac7c movgt r0, #1 */
/* @0x28ac80 bx lr */
/* @0x28ac84 mov r0, #0 */
/* @0x28ac88 bx lr */

/* ── FUNC 0x28ac8c · spSkeletonBounds_containsPoint · size=104 · insn=26 */
/* @0x28ac8c ldr r3, [r0] */
/* @0x28ac90 push {r4, r5, r6, r7, r8, lr} */
/* @0x28ac94 cmp r3, #0 */
/* @0x28ac98 mov r5, r0 */
/* @0x28ac9c mov r6, r1 */
/* @0x28aca0 mov r7, r2 */
/* @0x28aca4 movgt r4, #0 */
/* @0x28aca8 bgt 0x28acbc <spSkeletonBounds_containsPoint+0x30> */
/* @0x28acac b 0x28acec <spSkeletonBounds_containsPoint+0x60> */
/* @0x28acb0 ldr r3, [r5] */
/* @0x28acb4 cmp r3, r4 */
/* @0x28acb8 ble 0x28acec <spSkeletonBounds_containsPoint+0x60> */
/* @0x28acbc ldr r3, [r5, #0x8] */
/* @0x28acc0 mov r1, r6 */
/* @0x28acc4 mov r2, r7 */
/* @0x28acc8 lsl r8, r4, #2 */
/* @0x28accc ldr r0, [r3, r4, lsl #2] */
/* @0x28acd0 add r4, r4, #1 */
/* @0x28acd4 bl 0x28a5d4 <spPolygon_containsPoint> */
/* @0x28acd8 cmp r0, #0 */
/* @0x28acdc beq 0x28acb0 <spSkeletonBounds_containsPoint+0x24> */
/* @0x28ace0 ldr r3, [r5, #0x4] */
/* @0x28ace4 ldr r0, [r3, r8] */
/* @0x28ace8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x28acec mov r0, #0 */
/* @0x28acf0 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x28acf4 · spSkeletonBounds_intersectsSegment · size=132 · insn=33 */
/* @0x28acf4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x28acf8 mov r6, r1 */
/* @0x28acfc ldr r1, [r0] */
/* @0x28ad00 sub sp, sp, #8 */
/* @0x28ad04 mov r5, r0 */
/* @0x28ad08 mov r7, r2 */
/* @0x28ad0c cmp r1, #0 */
/* @0x28ad10 mov r8, r3 */
/* @0x28ad14 ldr r10, [sp, #0x28] */
/* @0x28ad18 movgt r4, #0 */
/* @0x28ad1c bgt 0x28ad30 <spSkeletonBounds_intersectsSegment+0x3c> */
/* @0x28ad20 b 0x28ad6c <spSkeletonBounds_intersectsSegment+0x78> */
/* @0x28ad24 ldr r0, [r5] */
/* @0x28ad28 cmp r0, r4 */
/* @0x28ad2c ble 0x28ad6c <spSkeletonBounds_intersectsSegment+0x78> */
/* @0x28ad30 ldr r0, [r5, #0x8] */
/* @0x28ad34 mov r1, r6 */
/* @0x28ad38 mov r2, r7 */
/* @0x28ad3c mov r3, r8 */
/* @0x28ad40 lsl r9, r4, #2 */
/* @0x28ad44 ldr r0, [r0, r4, lsl #2] */
/* @0x28ad48 add r4, r4, #1 */
/* @0x28ad4c str r10, [sp] */
/* @0x28ad50 bl 0x28a6a8 <spPolygon_intersectsSegment> */
/* @0x28ad54 cmp r0, #0 */
/* @0x28ad58 beq 0x28ad24 <spSkeletonBounds_intersectsSegment+0x30> */
/* @0x28ad5c ldr r3, [r5, #0x4] */
/* @0x28ad60 ldr r0, [r3, r9] */
/* @0x28ad64 add sp, sp, #8 */
/* @0x28ad68 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x28ad6c mov r0, #0 */
/* @0x28ad70 add sp, sp, #8 */
/* @0x28ad74 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
