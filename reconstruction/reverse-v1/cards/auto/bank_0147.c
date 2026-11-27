/* libyoyo.so 覆盖卡组 0147
 * 函数 0x1b8e0c..0x1bb430，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1b8e0c · CLayerManager::CleanOldTilemapElementRuntimeData(CLayerOldTilemapElement*) · size=180 · insn=45 */
/* @0x1b8e0c ldr r3, [r0, #0x24] */
/* @0x1b8e10 push {r4, r5, r6, r7, r8} */
/* @0x1b8e14 cmp r3, #0 */
/* @0x1b8e18 beq 0x1b8eb4 <_ZN13CLayerManager33CleanOldTilemapElementRuntimeDataEP23CLayerOldTilemapElement+0xa8> */
/* @0x1b8e1c ldr r7, [pc, #0x98] */
/* @0x1b8e20 mov r1, #0 */
/* @0x1b8e24 ldr r6, [r0, #0x2c] */
/* @0x1b8e28 ldr r7, [pc, r7] */
/* @0x1b8e2c ldr r4, [r7, #0x8] */
/* @0x1b8e30 ldr r12, [r7] */
/* @0x1b8e34 ldr r8, [r7, #0x4] */
/* @0x1b8e38 add r4, r4, #1 */
/* @0x1b8e3c b 0x1b8e48 <_ZN13CLayerManager33CleanOldTilemapElementRuntimeDataEP23CLayerOldTilemapElement+0x3c> */
/* @0x1b8e40 mov r12, r3 */
/* @0x1b8e44 mov r3, r2 */
/* @0x1b8e48 ldr r2, [r3, #0x708] */
/* @0x1b8e4c sub r6, r6, #1 */
/* @0x1b8e50 ldr r5, [r3, #0x704] */
/* @0x1b8e54 cmp r2, #0 */
/* @0x1b8e58 strne r5, [r2, #0x704] */
/* @0x1b8e5c ldrne r5, [r3, #0x704] */
/* @0x1b8e60 ldrne r2, [r3, #0x708] */
/* @0x1b8e64 streq r5, [r0, #0x24] */
/* @0x1b8e68 cmp r5, #0 */
/* @0x1b8e6c streq r2, [r0, #0x28] */
/* @0x1b8e70 strne r2, [r5, #0x708] */
/* @0x1b8e74 cmp r12, #0 */
/* @0x1b8e78 str r1, [r3, #0x704] */
/* @0x1b8e7c mov r5, r4 */
/* @0x1b8e80 str r1, [r3, #0x708] */
/* @0x1b8e84 moveq r8, r3 */
/* @0x1b8e88 str r1, [r3, #0x700] */
/* @0x1b8e8c add r4, r4, #1 */
/* @0x1b8e90 strne r3, [r12, #0x708] */
/* @0x1b8e94 strne r12, [r3, #0x704] */
/* @0x1b8e98 strne r1, [r3, #0x708] */
/* @0x1b8e9c ldr r2, [r0, #0x24] */
/* @0x1b8ea0 cmp r2, #0 */
/* @0x1b8ea4 bne 0x1b8e40 <_ZN13CLayerManager33CleanOldTilemapElementRuntimeDataEP23CLayerOldTilemapElement+0x34> */
/* @0x1b8ea8 str r6, [r0, #0x2c] */
/* @0x1b8eac str r5, [r7, #0x8] */
/* @0x1b8eb0 stm r7, {r3, r8} */
/* @0x1b8eb4 pop {r4, r5, r6, r7, r8} */
/* @0x1b8eb8 bx lr */
/* @0x1b8ebc eoreq r7, r3, r4, asr r10 */

/* ── FUNC 0x1b8ec0 · CLayerManager::CleanSpriteElementRuntimeData(CLayerSpriteElement*) · size=4 · insn=1 */
/* @0x1b8ec0 bx lr */

/* ── FUNC 0x1b8ec4 · CLayerManager::CleanTilemapElementRuntimeData(CLayerTilemapElement*) · size=4 · insn=1 */
/* @0x1b8ec4 bx lr */

/* ── FUNC 0x1b8ec8 · CLayerManager::CleanParticleElementRuntimeData(CLayerParticleElement*) · size=4 · insn=1 */
/* @0x1b8ec8 bx lr */

/* ── FUNC 0x1b8ecc · CLayerManager::CleanTileElementRuntimeData(CLayerTileElement*) · size=4 · insn=1 */
/* @0x1b8ecc bx lr */

/* ── FUNC 0x1b8ed0 · CLayerManager::CleanElementRuntimeData(CLayerElementBase*) · size=152 · insn=38 */
/* @0x1b8ed0 push {r4, lr} */
/* @0x1b8ed4 subs r4, r0, #0 */
/* @0x1b8ed8 popeq {r4, pc} */
/* @0x1b8edc ldr r3, [r4] */
/* @0x1b8ee0 sub r3, r3, #1 */
/* @0x1b8ee4 cmp r3, #6 */
/* @0x1b8ee8 addls pc, pc, r3, lsl #2 */
/* @0x1b8eec b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44> */
/* @0x1b8ef0 b 0x1b8f20 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x50> */
/* @0x1b8ef4 b 0x1b8f2c <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x5c> */
/* @0x1b8ef8 b 0x1b8f38 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x68> */
/* @0x1b8efc b 0x1b8f44 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x74> */
/* @0x1b8f00 b 0x1b8f50 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x80> */
/* @0x1b8f04 b 0x1b8f5c <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x8c> */
/* @0x1b8f08 b 0x1b8f0c <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x3c> */
/* @0x1b8f0c mov r0, r4 */
/* @0x1b8f10 bl 0x1b8ecc <_ZN13CLayerManager27CleanTileElementRuntimeDataEP17CLayerTileElement> */
/* @0x1b8f14 mov r3, #0 */
/* @0x1b8f18 strb r3, [r4, #0x8] */
/* @0x1b8f1c pop {r4, pc} */
/* @0x1b8f20 mov r0, r4 */
/* @0x1b8f24 bl 0x1b8d98 <_ZN13CLayerManager33CleanBackgroundElementRuntimeDataEP23CLayerBackgroundElement> */
/* @0x1b8f28 b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44> */
/* @0x1b8f2c mov r0, r4 */
/* @0x1b8f30 bl 0x1b8d9c <_ZN13CLayerManager31CleanInstanceElementRuntimeDataEP21CLayerInstanceElement> */
/* @0x1b8f34 b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44> */
/* @0x1b8f38 mov r0, r4 */
/* @0x1b8f3c bl 0x1b8e0c <_ZN13CLayerManager33CleanOldTilemapElementRuntimeDataEP23CLayerOldTilemapElement> */
/* @0x1b8f40 b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44> */
/* @0x1b8f44 mov r0, r4 */
/* @0x1b8f48 bl 0x1b8ec0 <_ZN13CLayerManager29CleanSpriteElementRuntimeDataEP19CLayerSpriteElement> */
/* @0x1b8f4c b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44> */
/* @0x1b8f50 mov r0, r4 */
/* @0x1b8f54 bl 0x1b8ec4 <_ZN13CLayerManager30CleanTilemapElementRuntimeDataEP20CLayerTilemapElement> */
/* @0x1b8f58 b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44> */
/* @0x1b8f5c mov r0, r4 */
/* @0x1b8f60 bl 0x1b8ec8 <_ZN13CLayerManager31CleanParticleElementRuntimeDataEP21CLayerParticleElement> */
/* @0x1b8f64 b 0x1b8f14 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase+0x44> */

/* ── FUNC 0x1b8f68 · CLayerManager::CleanRoomLayerRuntimeData(CRoom*) · size=116 · insn=29 */
/* @0x1b8f68 cmp r0, #0 */
/* @0x1b8f6c push {r3, r4, r5, lr} */
/* @0x1b8f70 beq 0x1b8fac <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom+0x44> */
/* @0x1b8f74 ldr r5, [r0, #0xd4] */
/* @0x1b8f78 cmp r5, #0 */
/* @0x1b8f7c beq 0x1b8fac <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom+0x44> */
/* @0x1b8f80 ldr r4, [r5, #0x58] */
/* @0x1b8f84 cmp r4, #0 */
/* @0x1b8f88 beq 0x1b8fa0 <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom+0x38> */
/* @0x1b8f8c mov r0, r4 */
/* @0x1b8f90 bl 0x1b8ed0 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase> */
/* @0x1b8f94 ldr r4, [r4, #0x14] */
/* @0x1b8f98 cmp r4, #0 */
/* @0x1b8f9c bne 0x1b8f8c <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom+0x24> */
/* @0x1b8fa0 ldr r5, [r5, #0x68] */
/* @0x1b8fa4 cmp r5, #0 */
/* @0x1b8fa8 bne 0x1b8f80 <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom+0x18> */
/* @0x1b8fac ldr r4, [pc, #0x24] */
/* @0x1b8fb0 ldr r4, [pc, r4] */
/* @0x1b8fb4 ldr r0, [r4] */
/* @0x1b8fb8 cmp r0, #0 */
/* @0x1b8fbc popeq {r3, r4, r5, pc} */
/* @0x1b8fc0 ldr r3, [r0] */
/* @0x1b8fc4 ldr r3, [r3, #0x4] */
/* @0x1b8fc8 blx r3 */
/* @0x1b8fcc mov r3, #0 */
/* @0x1b8fd0 str r3, [r4] */
/* @0x1b8fd4 pop {r3, r4, r5, pc} */
/* @0x1b8fd8 eoreq r4, r3, r0, asr #25 */

/* ── FUNC 0x1b8fdc · CLayerManager::RemoveElement(CRoom*, CLayer*, CLayerElementBase*, bool) · size=1004 · insn=251 */
/* @0x1b8fdc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b8fe0 cmp r2, #0 */
/* @0x1b8fe4 cmpne r1, #0 */
/* @0x1b8fe8 sub sp, sp, #28 */
/* @0x1b8fec mov r11, r0 */
/* @0x1b8ff0 movne r4, #0 */
/* @0x1b8ff4 moveq r4, #1 */
/* @0x1b8ff8 str r1, [sp, #0x8] */
/* @0x1b8ffc str r2, [sp, #0x4] */
/* @0x1b9000 str r3, [sp, #0x10] */
/* @0x1b9004 bne 0x1b9010 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x34> */
/* @0x1b9008 add sp, sp, #28 */
/* @0x1b900c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b9010 ldr r0, [r2, #0x4] */
/* @0x1b9014 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b9018 ldr r2, [r11, #0x100] */
/* @0x1b901c ldr r12, [r11, #0x108] */
/* @0x1b9020 bic r0, r0, #-2147483648 */
/* @0x1b9024 and r3, r0, r2 */
/* @0x1b9028 lsl r1, r3, #1 */
/* @0x1b902c add lr, r1, r3 */
/* @0x1b9030 add lr, r12, lr, lsl #2 */
/* @0x1b9034 ldr lr, [lr, #0x8] */
/* @0x1b9038 cmp lr, #0 */
/* @0x1b903c beq 0x1b90a8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0xcc> */
/* @0x1b9040 cmp r0, lr */
/* @0x1b9044 beq 0x1b9100 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x124> */
/* @0x1b9048 ldr r6, [r11, #0xf8] */
/* @0x1b904c and lr, r2, lr */
/* @0x1b9050 add r1, r3, r6 */
/* @0x1b9054 rsb lr, lr, r1 */
/* @0x1b9058 tst lr, r2 */
/* @0x1b905c bpl 0x1b9074 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x98> */
/* @0x1b9060 b 0x1b90a8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0xcc> */
/* @0x1b9064 cmp r0, lr */
/* @0x1b9068 beq 0x1b90f8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x11c> */
/* @0x1b906c cmp r5, r4 */
/* @0x1b9070 blt 0x1b90a8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0xcc> */
/* @0x1b9074 add r3, r3, #1 */
/* @0x1b9078 add r4, r4, #1 */
/* @0x1b907c and r3, r2, r3 */
/* @0x1b9080 add r7, r3, r6 */
/* @0x1b9084 lsl r1, r3, #1 */
/* @0x1b9088 add lr, r1, r3 */
/* @0x1b908c add lr, r12, lr, lsl #2 */
/* @0x1b9090 ldr lr, [lr, #0x8] */
/* @0x1b9094 and r5, r2, lr */
/* @0x1b9098 cmp lr, #0 */
/* @0x1b909c rsb r5, r5, r7 */
/* @0x1b90a0 and r5, r5, r2 */
/* @0x1b90a4 bne 0x1b9064 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x88> */
/* @0x1b90a8 ldr r3, [r11, #0x10c] */
/* @0x1b90ac ldr r1, [sp, #0x4] */
/* @0x1b90b0 ldr r0, [sp, #0x4] */
/* @0x1b90b4 cmp r3, r1 */
/* @0x1b90b8 moveq r3, #0 */
/* @0x1b90bc streq r3, [r11, #0x10c] */
/* @0x1b90c0 bl 0x1b8ed0 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase> */
/* @0x1b90c4 ldr r2, [sp, #0x4] */
/* @0x1b90c8 ldr r3, [r2] */
/* @0x1b90cc sub r3, r3, #1 */
/* @0x1b90d0 cmp r3, #6 */
/* @0x1b90d4 addls pc, pc, r3, lsl #2 */
/* @0x1b90d8 b 0x1b9008 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2c> */
/* @0x1b90dc b 0x1b91d8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x1fc> */
/* @0x1b90e0 b 0x1b91ec <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x210> */
/* @0x1b90e4 b 0x1b92a4 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2c8> */
/* @0x1b90e8 b 0x1b92e0 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x304> */
/* @0x1b90ec b 0x1b92b8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2dc> */
/* @0x1b90f0 b 0x1b92cc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2f0> */
/* @0x1b90f4 b 0x1b91c4 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x1e8> */
/* @0x1b90f8 cmn r3, #1 */
/* @0x1b90fc beq 0x1b90a8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0xcc> */
/* @0x1b9100 add r5, r3, #1 */
/* @0x1b9104 and r5, r5, r2 */
/* @0x1b9108 add r4, r5, r5, lsl #1 */
/* @0x1b910c add r4, r12, r4, lsl #2 */
/* @0x1b9110 ldr lr, [r4, #0x8] */
/* @0x1b9114 cmp lr, #0 */
/* @0x1b9118 beq 0x1b91bc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x1e0> */
/* @0x1b911c ldr r7, [r11, #0xf8] */
/* @0x1b9120 and r0, r2, lr */
/* @0x1b9124 add r6, r5, r7 */
/* @0x1b9128 rsb r0, r0, r6 */
/* @0x1b912c tst r0, r2 */
/* @0x1b9130 strne r11, [sp, #0xc] */
/* @0x1b9134 movne r11, r7 */
/* @0x1b9138 bne 0x1b914c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x170> */
/* @0x1b913c b 0x1b91bc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x1e0> */
/* @0x1b9140 tst r9, r2 */
/* @0x1b9144 beq 0x1b9198 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x1bc> */
/* @0x1b9148 mov r5, r0 */
/* @0x1b914c add r7, r1, r3 */
/* @0x1b9150 add r0, r5, #1 */
/* @0x1b9154 and r0, r0, r2 */
/* @0x1b9158 ldr r8, [r4, #0x4] */
/* @0x1b915c add r6, r12, r7, lsl #2 */
/* @0x1b9160 add r9, r0, r11 */
/* @0x1b9164 add r10, r0, r0, lsl #1 */
/* @0x1b9168 mov r3, r5 */
/* @0x1b916c str lr, [r6, #0x8] */
/* @0x1b9170 lsl r1, r5, #1 */
/* @0x1b9174 ldr r4, [r4] */
/* @0x1b9178 str r4, [r12, r7, lsl #2] */
/* @0x1b917c add r4, r12, r10, lsl #2 */
/* @0x1b9180 ldr lr, [r4, #0x8] */
/* @0x1b9184 str r8, [r6, #0x4] */
/* @0x1b9188 cmp lr, #0 */
/* @0x1b918c and r7, r2, lr */
/* @0x1b9190 rsb r9, r7, r9 */
/* @0x1b9194 bne 0x1b9140 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x164> */
/* @0x1b9198 ldr r11, [sp, #0xc] */
/* @0x1b919c add r5, r5, r5, lsl #1 */
/* @0x1b91a0 ldr r3, [r11, #0xfc] */
/* @0x1b91a4 mov r2, #0 */
/* @0x1b91a8 add r12, r12, r5, lsl #2 */
/* @0x1b91ac sub r3, r3, #1 */
/* @0x1b91b0 str r2, [r12, #0x8] */
/* @0x1b91b4 str r3, [r11, #0xfc] */
/* @0x1b91b8 b 0x1b90a8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0xcc> */
/* @0x1b91bc mov r5, r3 */
/* @0x1b91c0 b 0x1b919c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x1c0> */
/* @0x1b91c4 ldr r0, [sp, #0x8] */
/* @0x1b91c8 ldr r1, [sp, #0x4] */
/* @0x1b91cc add sp, sp, #28 */
/* @0x1b91d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b91d4 b 0x1b7f64 <_ZN13CLayerManager17RemoveTileElementEP6CLayerP17CLayerTileElement> */
/* @0x1b91d8 ldr r0, [sp, #0x8] */
/* @0x1b91dc ldr r1, [sp, #0x4] */
/* @0x1b91e0 add sp, sp, #28 */
/* @0x1b91e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b91e8 b 0x1b7a04 <_ZN13CLayerManager23RemoveBackgroundElementEP6CLayerP23CLayerBackgroundElement> */
/* @0x1b91ec ldr r6, [sp, #0x4] */
/* @0x1b91f0 ldr r0, [r6, #0x1c] */
/* @0x1b91f4 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b91f8 ldr r2, [r11, #0x118] */
/* @0x1b91fc ldr r10, [r11, #0x120] */
/* @0x1b9200 bic r0, r0, #-2147483648 */
/* @0x1b9204 and r3, r0, r2 */
/* @0x1b9208 lsl r1, r3, #1 */
/* @0x1b920c add r12, r1, r3 */
/* @0x1b9210 add r12, r10, r12, lsl #2 */
/* @0x1b9214 ldr r12, [r12, #0x8] */
/* @0x1b9218 cmp r12, #0 */
/* @0x1b921c beq 0x1b928c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2b0> */
/* @0x1b9220 cmp r0, r12 */
/* @0x1b9224 beq 0x1b92fc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x320> */
/* @0x1b9228 ldr r7, [r11, #0x110] */
/* @0x1b922c and r12, r2, r12 */
/* @0x1b9230 add r1, r7, r3 */
/* @0x1b9234 rsb r1, r12, r1 */
/* @0x1b9238 tst r1, r2 */
/* @0x1b923c bmi 0x1b928c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2b0> */
/* @0x1b9240 mov r4, #0 */
/* @0x1b9244 b 0x1b9258 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x27c> */
/* @0x1b9248 cmp r0, r12 */
/* @0x1b924c beq 0x1b92f4 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x318> */
/* @0x1b9250 cmp r5, r4 */
/* @0x1b9254 blt 0x1b928c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2b0> */
/* @0x1b9258 add r3, r3, #1 */
/* @0x1b925c add r4, r4, #1 */
/* @0x1b9260 and r3, r2, r3 */
/* @0x1b9264 add r6, r7, r3 */
/* @0x1b9268 lsl r1, r3, #1 */
/* @0x1b926c add r12, r1, r3 */
/* @0x1b9270 add r12, r10, r12, lsl #2 */
/* @0x1b9274 ldr r12, [r12, #0x8] */
/* @0x1b9278 and r5, r2, r12 */
/* @0x1b927c cmp r12, #0 */
/* @0x1b9280 rsb r5, r5, r6 */
/* @0x1b9284 and r5, r5, r2 */
/* @0x1b9288 bne 0x1b9248 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x26c> */
/* @0x1b928c ldr r0, [sp, #0x8] */
/* @0x1b9290 ldr r1, [sp, #0x4] */
/* @0x1b9294 ldr r2, [sp, #0x10] */
/* @0x1b9298 add sp, sp, #28 */
/* @0x1b929c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b92a0 b 0x1b7ac4 <_ZN13CLayerManager21RemoveInstanceElementEP6CLayerP21CLayerInstanceElementb> */
/* @0x1b92a4 ldr r0, [sp, #0x8] */
/* @0x1b92a8 ldr r1, [sp, #0x4] */
/* @0x1b92ac add sp, sp, #28 */
/* @0x1b92b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b92b4 b 0x1b7bac <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement> */
/* @0x1b92b8 ldr r0, [sp, #0x8] */
/* @0x1b92bc ldr r1, [sp, #0x4] */
/* @0x1b92c0 add sp, sp, #28 */
/* @0x1b92c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b92c8 b 0x1b7dcc <_ZN13CLayerManager20RemoveTilemapElementEP6CLayerP20CLayerTilemapElement> */
/* @0x1b92cc ldr r0, [sp, #0x8] */
/* @0x1b92d0 ldr r1, [sp, #0x4] */
/* @0x1b92d4 add sp, sp, #28 */
/* @0x1b92d8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b92dc b 0x1b7ec0 <_ZN13CLayerManager21RemoveParticleElementEP6CLayerP21CLayerParticleElement> */
/* @0x1b92e0 ldr r0, [sp, #0x8] */
/* @0x1b92e4 ldr r1, [sp, #0x4] */
/* @0x1b92e8 add sp, sp, #28 */
/* @0x1b92ec pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b92f0 b 0x1b7cf8 <_ZN13CLayerManager19RemoveSpriteElementEP6CLayerP19CLayerSpriteElement> */
/* @0x1b92f4 cmn r3, #1 */
/* @0x1b92f8 beq 0x1b928c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2b0> */
/* @0x1b92fc add r0, r3, #1 */
/* @0x1b9300 and r7, r0, r2 */
/* @0x1b9304 add r4, r7, r7, lsl #1 */
/* @0x1b9308 add r4, r10, r4, lsl #2 */
/* @0x1b930c ldr r12, [r4, #0x8] */
/* @0x1b9310 cmp r12, #0 */
/* @0x1b9314 beq 0x1b93c0 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x3e4> */
/* @0x1b9318 ldr r0, [r11, #0x110] */
/* @0x1b931c str r0, [sp, #0xc] */
/* @0x1b9320 and r0, r2, r12 */
/* @0x1b9324 ldr r6, [sp, #0xc] */
/* @0x1b9328 add r5, r7, r6 */
/* @0x1b932c rsb r0, r0, r5 */
/* @0x1b9330 tst r0, r2 */
/* @0x1b9334 strne r11, [sp, #0x14] */
/* @0x1b9338 bne 0x1b934c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x370> */
/* @0x1b933c b 0x1b93c0 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x3e4> */
/* @0x1b9340 tst r6, r2 */
/* @0x1b9344 beq 0x1b939c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x3c0> */
/* @0x1b9348 mov r7, r0 */
/* @0x1b934c add r6, r1, r3 */
/* @0x1b9350 add r0, r7, #1 */
/* @0x1b9354 and r0, r0, r2 */
/* @0x1b9358 ldr r8, [r4, #0x4] */
/* @0x1b935c add r5, r10, r6, lsl #2 */
/* @0x1b9360 ldr r1, [sp, #0xc] */
/* @0x1b9364 add r11, r0, r0, lsl #1 */
/* @0x1b9368 mov r3, r7 */
/* @0x1b936c str r12, [r5, #0x8] */
/* @0x1b9370 add r9, r1, r0 */
/* @0x1b9374 ldr r4, [r4] */
/* @0x1b9378 lsl r1, r7, #1 */
/* @0x1b937c str r4, [r10, r6, lsl #2] */
/* @0x1b9380 add r4, r10, r11, lsl #2 */
/* @0x1b9384 ldr r12, [r4, #0x8] */
/* @0x1b9388 str r8, [r5, #0x4] */
/* @0x1b938c cmp r12, #0 */
/* @0x1b9390 and r6, r2, r12 */
/* @0x1b9394 rsb r6, r6, r9 */
/* @0x1b9398 bne 0x1b9340 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x364> */
/* @0x1b939c ldr r11, [sp, #0x14] */
/* @0x1b93a0 add r3, r7, r7, lsl #1 */
/* @0x1b93a4 ldr r1, [r11, #0x114] */
/* @0x1b93a8 mov r2, #0 */
/* @0x1b93ac add r10, r10, r3, lsl #2 */
/* @0x1b93b0 sub r3, r1, #1 */
/* @0x1b93b4 str r2, [r10, #0x8] */
/* @0x1b93b8 str r3, [r11, #0x114] */
/* @0x1b93bc b 0x1b928c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2b0> */
/* @0x1b93c0 mov r7, r3 */
/* @0x1b93c4 b 0x1b93a0 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x3c4> */

/* ── FUNC 0x1b93c8 · CLayerManager::CleanRoomLayers(CRoom*) · size=528 · insn=129 */
/* @0x1b93c8 push {r4, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b93cc vpush {d8, d9} */
/* @0x1b93d0 subs r7, r0, #0 */
/* @0x1b93d4 beq 0x1b955c <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x194> */
/* @0x1b93d8 ldr r6, [r7, #0xd4] */
/* @0x1b93dc cmp r6, #0 */
/* @0x1b93e0 beq 0x1b9544 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x17c> */
/* @0x1b93e4 ldr r9, [pc, #0x1e8] */
/* @0x1b93e8 mov r8, #0 */
/* @0x1b93ec mvn r10, #0 */
/* @0x1b93f0 mov r11, #1 */
/* @0x1b93f4 ldr r9, [pc, r9] */
/* @0x1b93f8 vldr s16, [pc, #464] */
/* @0x1b93fc vldr d9, [pc, #452] */
/* @0x1b9400 b 0x1b9414 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x4c> */
/* @0x1b9404 mov r0, r7 */
/* @0x1b9408 mov r1, r6 */
/* @0x1b940c mov r3, #0 */
/* @0x1b9410 bl 0x1b8fdc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1b9414 ldr r2, [r6, #0x58] */
/* @0x1b9418 cmp r2, #0 */
/* @0x1b941c bne 0x1b9404 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x3c> */
/* @0x1b9420 ldr r3, [r6, #0x6c] */
/* @0x1b9424 cmp r3, #0 */
/* @0x1b9428 beq 0x1b95ac <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x1e4> */
/* @0x1b942c ldr r2, [r6, #0x68] */
/* @0x1b9430 str r2, [r3, #0x68] */
/* @0x1b9434 ldr r2, [r6, #0x68] */
/* @0x1b9438 ldr r3, [r6, #0x6c] */
/* @0x1b943c cmp r2, #0 */
/* @0x1b9440 strne r3, [r2, #0x6c] */
/* @0x1b9444 streq r3, [r7, #0xd8] */
/* @0x1b9448 ldr r3, [r7, #0xdc] */
/* @0x1b944c ldr r0, [r6, #0x1c] */
/* @0x1b9450 sub r3, r3, #1 */
/* @0x1b9454 str r3, [r7, #0xdc] */
/* @0x1b9458 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1b945c cmp r0, #0 */
/* @0x1b9460 bne 0x1b946c <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xa4> */
/* @0x1b9464 ldr r0, [r6, #0x1c] */
/* @0x1b9468 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b946c ldr r3, [r6, #0x64] */
/* @0x1b9470 str r8, [r6, #0x1c] */
/* @0x1b9474 cmp r3, #0 */
/* @0x1b9478 beq 0x1b94b0 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xe8> */
/* @0x1b947c ldr r0, [r6, #0x58] */
/* @0x1b9480 cmp r0, #0 */
/* @0x1b9484 beq 0x1b94b0 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xe8> */
/* @0x1b9488 cmp r3, #2 */
/* @0x1b948c beq 0x1b9564 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x19c> */
/* @0x1b9490 cmp r3, #3 */
/* @0x1b9494 beq 0x1b957c <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x1b4> */
/* @0x1b9498 cmp r3, #1 */
/* @0x1b949c beq 0x1b9594 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x1cc> */
/* @0x1b94a0 ldr r4, [r0, #0x14] */
/* @0x1b94a4 cmp r4, #0 */
/* @0x1b94a8 mov r0, r4 */
/* @0x1b94ac bne 0x1b94a0 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xd8> */
/* @0x1b94b0 str r8, [r6, #0x60] */
/* @0x1b94b4 vstr s16, [r6, #8] */
/* @0x1b94b8 str r8, [r6, #0x5c] */
/* @0x1b94bc vstr s16, [r6, #12] */
/* @0x1b94c0 str r8, [r6, #0x58] */
/* @0x1b94c4 vstr s16, [r6, #16] */
/* @0x1b94c8 str r10, [r6] */
/* @0x1b94cc vstr s16, [r6, #20] */
/* @0x1b94d0 str r8, [r6, #0x4] */
/* @0x1b94d4 vstr d9, [r6, #72] */
/* @0x1b94d8 strb r11, [r6, #0x18] */
/* @0x1b94dc add r0, r6, #48 */
/* @0x1b94e0 strb r8, [r6, #0x19] */
/* @0x1b94e4 str r8, [r6, #0x1c] */
/* @0x1b94e8 str r10, [r6, #0x20] */
/* @0x1b94ec str r10, [r6, #0x24] */
/* @0x1b94f0 str r10, [r6, #0x28] */
/* @0x1b94f4 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1b94f8 ldr r3, [r9] */
/* @0x1b94fc ldr r2, [r9, #0x8] */
/* @0x1b9500 cmp r3, #0 */
/* @0x1b9504 str r8, [r6, #0x68] */
/* @0x1b9508 str r8, [r6, #0x6c] */
/* @0x1b950c add r2, r2, #1 */
/* @0x1b9510 str r8, [r6, #0x5c] */
/* @0x1b9514 str r8, [r6, #0x58] */
/* @0x1b9518 str r8, [r6, #0x60] */
/* @0x1b951c str r11, [r6, #0x64] */
/* @0x1b9520 str r2, [r9, #0x8] */
/* @0x1b9524 strne r6, [r3, #0x6c] */
/* @0x1b9528 strne r6, [r9] */
/* @0x1b952c strne r3, [r6, #0x68] */
/* @0x1b9530 strne r8, [r6, #0x6c] */
/* @0x1b9534 beq 0x1b95b8 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x1f0> */
/* @0x1b9538 ldr r6, [r7, #0xd4] */
/* @0x1b953c cmp r6, #0 */
/* @0x1b9540 bne 0x1b9414 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x4c> */
/* @0x1b9544 ldr r0, [r7, #0xf4] */
/* @0x1b9548 cmp r0, #0 */
/* @0x1b954c beq 0x1b9554 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x18c> */
/* @0x1b9550 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b9554 mov r3, #0 */
/* @0x1b9558 str r3, [r7, #0xf4] */
/* @0x1b955c vpop {d8, d9} */
/* @0x1b9560 pop {r4, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b9564 ldr r4, [r0, #0x14] */
/* @0x1b9568 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b956c cmp r4, #0 */
/* @0x1b9570 mov r0, r4 */
/* @0x1b9574 bne 0x1b9564 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x19c> */
/* @0x1b9578 b 0x1b94b0 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xe8> */
/* @0x1b957c ldr r4, [r0, #0x14] */
/* @0x1b9580 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b9584 cmp r4, #0 */
/* @0x1b9588 mov r0, r4 */
/* @0x1b958c bne 0x1b957c <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x1b4> */
/* @0x1b9590 b 0x1b94b0 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xe8> */
/* @0x1b9594 ldr r4, [r0, #0x14] */
/* @0x1b9598 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b959c cmp r4, #0 */
/* @0x1b95a0 mov r0, r4 */
/* @0x1b95a4 bne 0x1b9594 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x1cc> */
/* @0x1b95a8 b 0x1b94b0 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0xe8> */
/* @0x1b95ac ldr r2, [r6, #0x68] */
/* @0x1b95b0 str r2, [r7, #0xd4] */
/* @0x1b95b4 b 0x1b943c <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x74> */
/* @0x1b95b8 str r6, [r9, #0x4] */
/* @0x1b95bc str r6, [r9] */
/* @0x1b95c0 b 0x1b9538 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom+0x170> */
/* @0x1b95c4 nop */
/* @0x1b95d4 eoreq r7, r3, r8, ror #8 */

/* ── FUNC 0x1b95d8 · CLayerManager::RemoveLayer(CRoom*, int, bool) · size=836 · insn=209 */
/* @0x1b95d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b95dc sub sp, sp, #12 */
/* @0x1b95e0 mov r9, r0 */
/* @0x1b95e4 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1b95e8 subs r4, r0, #0 */
/* @0x1b95ec bne 0x1b9604 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2c> */
/* @0x1b95f0 b 0x1b97e4 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x20c> */
/* @0x1b95f4 mov r0, r9 */
/* @0x1b95f8 mov r1, r4 */
/* @0x1b95fc mov r3, #1 */
/* @0x1b9600 bl 0x1b8fdc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1b9604 ldr r2, [r4, #0x58] */
/* @0x1b9608 cmp r2, #0 */
/* @0x1b960c bne 0x1b95f4 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x1c> */
/* @0x1b9610 ldr r3, [r4, #0x6c] */
/* @0x1b9614 cmp r3, #0 */
/* @0x1b9618 beq 0x1b9900 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x328> */
/* @0x1b961c ldr r2, [r4, #0x68] */
/* @0x1b9620 str r2, [r3, #0x68] */
/* @0x1b9624 ldr r2, [r4, #0x68] */
/* @0x1b9628 ldr r3, [r4, #0x6c] */
/* @0x1b962c cmp r2, #0 */
/* @0x1b9630 strne r3, [r2, #0x6c] */
/* @0x1b9634 streq r3, [r9, #0xd8] */
/* @0x1b9638 ldr r3, [r9, #0xdc] */
/* @0x1b963c ldr r0, [r4] */
/* @0x1b9640 sub r3, r3, #1 */
/* @0x1b9644 str r3, [r9, #0xdc] */
/* @0x1b9648 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b964c ldr r2, [r9, #0xec] */
/* @0x1b9650 ldr r12, [r9, #0xf4] */
/* @0x1b9654 bic r0, r0, #-2147483648 */
/* @0x1b9658 and r3, r0, r2 */
/* @0x1b965c lsl r1, r3, #1 */
/* @0x1b9660 add lr, r1, r3 */
/* @0x1b9664 add lr, r12, lr, lsl #2 */
/* @0x1b9668 ldr lr, [lr, #0x8] */
/* @0x1b966c cmp lr, #0 */
/* @0x1b9670 beq 0x1b96e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x108> */
/* @0x1b9674 cmp r0, lr */
/* @0x1b9678 beq 0x1b97f4 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x21c> */
/* @0x1b967c ldr r8, [r9, #0xe4] */
/* @0x1b9680 and lr, r2, lr */
/* @0x1b9684 add r1, r3, r8 */
/* @0x1b9688 rsb lr, lr, r1 */
/* @0x1b968c tst lr, r2 */
/* @0x1b9690 bmi 0x1b96e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x108> */
/* @0x1b9694 mov r5, #0 */
/* @0x1b9698 b 0x1b96ac <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0xd4> */
/* @0x1b969c cmp r0, lr */
/* @0x1b96a0 beq 0x1b97ec <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x214> */
/* @0x1b96a4 cmp r6, r5 */
/* @0x1b96a8 blt 0x1b96e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x108> */
/* @0x1b96ac add r3, r3, #1 */
/* @0x1b96b0 add r5, r5, #1 */
/* @0x1b96b4 and r3, r2, r3 */
/* @0x1b96b8 add r7, r3, r8 */
/* @0x1b96bc lsl r1, r3, #1 */
/* @0x1b96c0 add lr, r1, r3 */
/* @0x1b96c4 add lr, r12, lr, lsl #2 */
/* @0x1b96c8 ldr lr, [lr, #0x8] */
/* @0x1b96cc and r6, r2, lr */
/* @0x1b96d0 cmp lr, #0 */
/* @0x1b96d4 rsb r6, r6, r7 */
/* @0x1b96d8 and r6, r6, r2 */
/* @0x1b96dc bne 0x1b969c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0xc4> */
/* @0x1b96e0 ldr r0, [r4, #0x1c] */
/* @0x1b96e4 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1b96e8 cmp r0, #0 */
/* @0x1b96ec bne 0x1b96f8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x120> */
/* @0x1b96f0 ldr r0, [r4, #0x1c] */
/* @0x1b96f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b96f8 ldr r3, [r4, #0x64] */
/* @0x1b96fc mov r2, #0 */
/* @0x1b9700 str r2, [r4, #0x1c] */
/* @0x1b9704 cmp r3, r2 */
/* @0x1b9708 beq 0x1b973c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x164> */
/* @0x1b970c ldr r0, [r4, #0x58] */
/* @0x1b9710 cmp r0, #0 */
/* @0x1b9714 beq 0x1b973c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x164> */
/* @0x1b9718 cmp r3, #2 */
/* @0x1b971c beq 0x1b98b0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2d8> */
/* @0x1b9720 cmp r3, #3 */
/* @0x1b9724 beq 0x1b98c8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2f0> */
/* @0x1b9728 cmp r3, #1 */
/* @0x1b972c beq 0x1b98e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x308> */
/* @0x1b9730 ldr r0, [r0, #0x14] */
/* @0x1b9734 cmp r0, #0 */
/* @0x1b9738 bne 0x1b9730 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x158> */
/* @0x1b973c mov r5, #0 */
/* @0x1b9740 mvn r1, #0 */
/* @0x1b9744 mov r3, #0 */
/* @0x1b9748 mov r6, #1 */
/* @0x1b974c mov r2, #0 */
/* @0x1b9750 str r3, [r4, #0x8] */
/* @0x1b9754 str r3, [r4, #0xc] */
/* @0x1b9758 add r0, r4, #48 */
/* @0x1b975c str r3, [r4, #0x10] */
/* @0x1b9760 str r3, [r4, #0x14] */
/* @0x1b9764 mov r3, #0 */
/* @0x1b9768 str r1, [r4] */
/* @0x1b976c strd r2, r3, [r4, #72] */
/* @0x1b9770 str r1, [r4, #0x20] */
/* @0x1b9774 str r1, [r4, #0x24] */
/* @0x1b9778 str r1, [r4, #0x28] */
/* @0x1b977c str r5, [r4, #0x60] */
/* @0x1b9780 str r5, [r4, #0x5c] */
/* @0x1b9784 str r5, [r4, #0x58] */
/* @0x1b9788 str r5, [r4, #0x4] */
/* @0x1b978c strb r5, [r4, #0x19] */
/* @0x1b9790 str r5, [r4, #0x1c] */
/* @0x1b9794 strb r6, [r4, #0x18] */
/* @0x1b9798 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1b979c ldr r3, [pc, #0x174] */
/* @0x1b97a0 str r5, [r4, #0x68] */
/* @0x1b97a4 ldr r3, [pc, r3] */
/* @0x1b97a8 str r5, [r4, #0x6c] */
/* @0x1b97ac str r5, [r4, #0x5c] */
/* @0x1b97b0 ldr r2, [r3] */
/* @0x1b97b4 ldr r1, [r3, #0x8] */
/* @0x1b97b8 cmp r2, r5 */
/* @0x1b97bc str r5, [r4, #0x58] */
/* @0x1b97c0 str r5, [r4, #0x60] */
/* @0x1b97c4 add r1, r1, r6 */
/* @0x1b97c8 str r6, [r4, #0x64] */
/* @0x1b97cc str r1, [r3, #0x8] */
/* @0x1b97d0 strne r4, [r2, #0x6c] */
/* @0x1b97d4 strne r4, [r3] */
/* @0x1b97d8 strne r2, [r4, #0x68] */
/* @0x1b97dc strne r5, [r4, #0x6c] */
/* @0x1b97e0 beq 0x1b990c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x334> */
/* @0x1b97e4 add sp, sp, #12 */
/* @0x1b97e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b97ec cmn r3, #1 */
/* @0x1b97f0 beq 0x1b96e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x108> */
/* @0x1b97f4 add r6, r3, #1 */
/* @0x1b97f8 and r6, r6, r2 */
/* @0x1b97fc add r5, r6, r6, lsl #1 */
/* @0x1b9800 add r5, r12, r5, lsl #2 */
/* @0x1b9804 ldr lr, [r5, #0x8] */
/* @0x1b9808 cmp lr, #0 */
/* @0x1b980c beq 0x1b98f8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x320> */
/* @0x1b9810 ldr r8, [r9, #0xe4] */
/* @0x1b9814 and r0, r2, lr */
/* @0x1b9818 add r7, r6, r8 */
/* @0x1b981c rsb r0, r0, r7 */
/* @0x1b9820 tst r0, r2 */
/* @0x1b9824 beq 0x1b98f8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x320> */
/* @0x1b9828 stm sp, {r4, r9} */
/* @0x1b982c mov r9, r8 */
/* @0x1b9830 b 0x1b9840 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x268> */
/* @0x1b9834 tst r10, r2 */
/* @0x1b9838 beq 0x1b988c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2b4> */
/* @0x1b983c mov r6, r0 */
/* @0x1b9840 add r7, r1, r3 */
/* @0x1b9844 add r0, r6, #1 */
/* @0x1b9848 and r0, r0, r2 */
/* @0x1b984c ldr r8, [r5, #0x4] */
/* @0x1b9850 add r4, r12, r7, lsl #2 */
/* @0x1b9854 add r10, r0, r9 */
/* @0x1b9858 add r11, r0, r0, lsl #1 */
/* @0x1b985c mov r3, r6 */
/* @0x1b9860 str lr, [r4, #0x8] */
/* @0x1b9864 lsl r1, r6, #1 */
/* @0x1b9868 ldr r5, [r5] */
/* @0x1b986c str r5, [r12, r7, lsl #2] */
/* @0x1b9870 add r5, r12, r11, lsl #2 */
/* @0x1b9874 ldr lr, [r5, #0x8] */
/* @0x1b9878 str r8, [r4, #0x4] */
/* @0x1b987c cmp lr, #0 */
/* @0x1b9880 and r7, r2, lr */
/* @0x1b9884 rsb r10, r7, r10 */
/* @0x1b9888 bne 0x1b9834 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x25c> */
/* @0x1b988c ldm sp, {r4, r9} */
/* @0x1b9890 add r6, r6, r6, lsl #1 */
/* @0x1b9894 ldr r3, [r9, #0xe8] */
/* @0x1b9898 mov r2, #0 */
/* @0x1b989c add r12, r12, r6, lsl #2 */
/* @0x1b98a0 sub r3, r3, #1 */
/* @0x1b98a4 str r2, [r12, #0x8] */
/* @0x1b98a8 str r3, [r9, #0xe8] */
/* @0x1b98ac b 0x1b96e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x108> */
/* @0x1b98b0 ldr r5, [r0, #0x14] */
/* @0x1b98b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b98b8 cmp r5, #0 */
/* @0x1b98bc mov r0, r5 */
/* @0x1b98c0 bne 0x1b98b0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2d8> */
/* @0x1b98c4 b 0x1b973c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x164> */
/* @0x1b98c8 ldr r5, [r0, #0x14] */
/* @0x1b98cc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b98d0 cmp r5, #0 */
/* @0x1b98d4 mov r0, r5 */
/* @0x1b98d8 bne 0x1b98c8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2f0> */
/* @0x1b98dc b 0x1b973c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x164> */
/* @0x1b98e0 ldr r5, [r0, #0x14] */
/* @0x1b98e4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b98e8 cmp r5, #0 */
/* @0x1b98ec mov r0, r5 */
/* @0x1b98f0 bne 0x1b98e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x308> */
/* @0x1b98f4 b 0x1b973c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x164> */
/* @0x1b98f8 mov r6, r3 */
/* @0x1b98fc b 0x1b9890 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2b8> */
/* @0x1b9900 ldr r2, [r4, #0x68] */
/* @0x1b9904 str r2, [r9, #0xd4] */
/* @0x1b9908 b 0x1b962c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x54> */
/* @0x1b990c str r4, [r3, #0x4] */
/* @0x1b9910 str r4, [r3] */
/* @0x1b9914 b 0x1b97e4 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x20c> */
/* @0x1b9918 strhteq r7, [r3], -r8 */

/* ── FUNC 0x1b991c · CLayerManager::RemoveInstanceFromLayer(CRoom*, CLayer*, CInstance*) · size=1344 · insn=336 */
/* @0x1b991c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b9920 subs r11, r0, #0 */
/* @0x1b9924 sub sp, sp, #28 */
/* @0x1b9928 mov r10, r1 */
/* @0x1b992c mov r4, r2 */
/* @0x1b9930 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9934 cmp r1, #0 */
/* @0x1b9938 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b993c cmp r2, #0 */
/* @0x1b9940 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9944 ldrb r3, [r2, #0x174] */
/* @0x1b9948 cmp r3, #0 */
/* @0x1b994c bne 0x1b9958 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x3c> */
/* @0x1b9950 add sp, sp, #28 */
/* @0x1b9954 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b9958 ldr r0, [r2, #0x78] */
/* @0x1b995c bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b9960 ldr r1, [r11, #0x118] */
/* @0x1b9964 ldr r7, [r11, #0x120] */
/* @0x1b9968 bic r0, r0, #-2147483648 */
/* @0x1b996c and r3, r0, r1 */
/* @0x1b9970 lsl r5, r3, #1 */
/* @0x1b9974 add r2, r5, r3 */
/* @0x1b9978 add r2, r7, r2, lsl #2 */
/* @0x1b997c ldr r2, [r2, #0x8] */
/* @0x1b9980 cmp r2, #0 */
/* @0x1b9984 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9988 cmp r0, r2 */
/* @0x1b998c beq 0x1b9a00 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0xe4> */
/* @0x1b9990 ldr r8, [r11, #0x110] */
/* @0x1b9994 and r2, r1, r2 */
/* @0x1b9998 add r12, r8, r3 */
/* @0x1b999c rsb r2, r2, r12 */
/* @0x1b99a0 tst r2, r1 */
/* @0x1b99a4 bmi 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b99a8 mov r12, #0 */
/* @0x1b99ac b 0x1b99c0 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0xa4> */
/* @0x1b99b0 cmp r0, r2 */
/* @0x1b99b4 beq 0x1b99f8 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0xdc> */
/* @0x1b99b8 cmp r6, r12 */
/* @0x1b99bc blt 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b99c0 add r3, r3, #1 */
/* @0x1b99c4 add r12, r12, #1 */
/* @0x1b99c8 and r3, r1, r3 */
/* @0x1b99cc add r9, r8, r3 */
/* @0x1b99d0 lsl r5, r3, #1 */
/* @0x1b99d4 add r2, r5, r3 */
/* @0x1b99d8 add r2, r7, r2, lsl #2 */
/* @0x1b99dc ldr r2, [r2, #0x8] */
/* @0x1b99e0 and r6, r1, r2 */
/* @0x1b99e4 cmp r2, #0 */
/* @0x1b99e8 rsb r6, r6, r9 */
/* @0x1b99ec and r6, r6, r1 */
/* @0x1b99f0 bne 0x1b99b0 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x94> */
/* @0x1b99f4 b 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b99f8 cmn r3, #1 */
/* @0x1b99fc beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9a00 add r3, r5, r3 */
/* @0x1b9a04 add r7, r7, r3, lsl #2 */
/* @0x1b9a08 cmn r7, #4 */
/* @0x1b9a0c beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9a10 ldr r9, [r7, #0x4] */
/* @0x1b9a14 cmp r9, #0 */
/* @0x1b9a18 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9a1c ldr r3, [r9, #0x10] */
/* @0x1b9a20 cmp r3, #0 */
/* @0x1b9a24 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9a28 cmp r10, r3 */
/* @0x1b9a2c beq 0x1b9a60 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x144> */
/* @0x1b9a30 ldr r0, [pc, #0x418] */
/* @0x1b9a34 ldr r1, [pc, #0x418] */
/* @0x1b9a38 ldr r0, [pc, r0] */
/* @0x1b9a3c ldr r2, [r4, #0x78] */
/* @0x1b9a40 ldr r3, [r10] */
/* @0x1b9a44 add r1, pc, r1 */
/* @0x1b9a48 ldr r0, [r0] */
/* @0x1b9a4c ldr r12, [r0] */
/* @0x1b9a50 ldr r12, [r12, #0xc] */
/* @0x1b9a54 blx r12 */
/* @0x1b9a58 add sp, sp, #28 */
/* @0x1b9a5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b9a60 ldr r0, [r9, #0x4] */
/* @0x1b9a64 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b9a68 ldr r2, [r11, #0x100] */
/* @0x1b9a6c ldr r12, [r11, #0x108] */
/* @0x1b9a70 bic r0, r0, #-2147483648 */
/* @0x1b9a74 and r3, r0, r2 */
/* @0x1b9a78 lsl r1, r3, #1 */
/* @0x1b9a7c add lr, r1, r3 */
/* @0x1b9a80 add lr, r12, lr, lsl #2 */
/* @0x1b9a84 ldr lr, [lr, #0x8] */
/* @0x1b9a88 cmp lr, #0 */
/* @0x1b9a8c beq 0x1b9afc <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x1e0> */
/* @0x1b9a90 cmp r0, lr */
/* @0x1b9a94 beq 0x1b9c8c <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x370> */
/* @0x1b9a98 ldr r7, [r11, #0xf8] */
/* @0x1b9a9c and lr, r2, lr */
/* @0x1b9aa0 add r1, r3, r7 */
/* @0x1b9aa4 rsb r1, lr, r1 */
/* @0x1b9aa8 tst r1, r2 */
/* @0x1b9aac bmi 0x1b9afc <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x1e0> */
/* @0x1b9ab0 mov r5, #0 */
/* @0x1b9ab4 b 0x1b9ac8 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x1ac> */
/* @0x1b9ab8 cmp r0, lr */
/* @0x1b9abc beq 0x1b9c84 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x368> */
/* @0x1b9ac0 cmp r6, r5 */
/* @0x1b9ac4 blt 0x1b9afc <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x1e0> */
/* @0x1b9ac8 add r3, r3, #1 */
/* @0x1b9acc add r5, r5, #1 */
/* @0x1b9ad0 and r3, r2, r3 */
/* @0x1b9ad4 add r8, r3, r7 */
/* @0x1b9ad8 lsl r1, r3, #1 */
/* @0x1b9adc add lr, r1, r3 */
/* @0x1b9ae0 add lr, r12, lr, lsl #2 */
/* @0x1b9ae4 ldr lr, [lr, #0x8] */
/* @0x1b9ae8 and r6, r2, lr */
/* @0x1b9aec cmp lr, #0 */
/* @0x1b9af0 rsb r6, r6, r8 */
/* @0x1b9af4 and r6, r6, r2 */
/* @0x1b9af8 bne 0x1b9ab8 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x19c> */
/* @0x1b9afc ldr r0, [r9, #0x1c] */
/* @0x1b9b00 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b9b04 ldr r2, [r11, #0x118] */
/* @0x1b9b08 ldr r8, [r11, #0x120] */
/* @0x1b9b0c bic r0, r0, #-2147483648 */
/* @0x1b9b10 and r3, r0, r2 */
/* @0x1b9b14 lsl r1, r3, #1 */
/* @0x1b9b18 add r12, r1, r3 */
/* @0x1b9b1c add r12, r8, r12, lsl #2 */
/* @0x1b9b20 ldr r12, [r12, #0x8] */
/* @0x1b9b24 cmp r12, #0 */
/* @0x1b9b28 beq 0x1b9ba4 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x288> */
/* @0x1b9b2c cmp r0, r12 */
/* @0x1b9b30 beq 0x1b9d64 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x448> */
/* @0x1b9b34 ldr r6, [r11, #0x110] */
/* @0x1b9b38 and r12, r2, r12 */
/* @0x1b9b3c add r1, r6, r3 */
/* @0x1b9b40 rsb r1, r12, r1 */
/* @0x1b9b44 tst r1, r2 */
/* @0x1b9b48 bmi 0x1b9ba4 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x288> */
/* @0x1b9b4c str r9, [sp] */
/* @0x1b9b50 mov r5, #0 */
/* @0x1b9b54 mov r9, r6 */
/* @0x1b9b58 b 0x1b9b6c <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x250> */
/* @0x1b9b5c cmp r0, r12 */
/* @0x1b9b60 beq 0x1b9d58 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x43c> */
/* @0x1b9b64 cmp r6, r5 */
/* @0x1b9b68 blt 0x1b9ba0 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x284> */
/* @0x1b9b6c add r3, r3, #1 */
/* @0x1b9b70 add r5, r5, #1 */
/* @0x1b9b74 and r3, r2, r3 */
/* @0x1b9b78 add r7, r9, r3 */
/* @0x1b9b7c lsl r1, r3, #1 */
/* @0x1b9b80 add r12, r1, r3 */
/* @0x1b9b84 add r12, r8, r12, lsl #2 */
/* @0x1b9b88 ldr r12, [r12, #0x8] */
/* @0x1b9b8c and r6, r2, r12 */
/* @0x1b9b90 cmp r12, #0 */
/* @0x1b9b94 rsb r6, r6, r7 */
/* @0x1b9b98 and r6, r6, r2 */
/* @0x1b9b9c bne 0x1b9b5c <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x240> */
/* @0x1b9ba0 ldr r9, [sp] */
/* @0x1b9ba4 ldr r3, [r9, #0x18] */
/* @0x1b9ba8 mvn r0, #0 */
/* @0x1b9bac ldr r2, [r9, #0x14] */
/* @0x1b9bb0 mov r5, #2 */
/* @0x1b9bb4 cmp r3, #0 */
/* @0x1b9bb8 ldr r1, [r10, #0x60] */
/* @0x1b9bbc strne r2, [r3, #0x14] */
/* @0x1b9bc0 add r1, r1, r0 */
/* @0x1b9bc4 ldrne r2, [r9, #0x14] */
/* @0x1b9bc8 ldrne r3, [r9, #0x18] */
/* @0x1b9bcc streq r2, [r10, #0x58] */
/* @0x1b9bd0 cmp r2, #0 */
/* @0x1b9bd4 streq r3, [r10, #0x5c] */
/* @0x1b9bd8 strne r3, [r2, #0x18] */
/* @0x1b9bdc mov r3, #0 */
/* @0x1b9be0 ldr r2, [pc, #0x270] */
/* @0x1b9be4 str r1, [r10, #0x60] */
/* @0x1b9be8 ldr r2, [pc, r2] */
/* @0x1b9bec str r3, [r9, #0x14] */
/* @0x1b9bf0 str r3, [r9, #0x18] */
/* @0x1b9bf4 ldr r1, [r2] */
/* @0x1b9bf8 ldr r12, [r2, #0x8] */
/* @0x1b9bfc cmp r1, r3 */
/* @0x1b9c00 str r5, [r9] */
/* @0x1b9c04 strb r3, [r9, #0x8] */
/* @0x1b9c08 add r12, r12, #1 */
/* @0x1b9c0c str r0, [r9, #0x4] */
/* @0x1b9c10 str r3, [r9, #0xc] */
/* @0x1b9c14 str r3, [r9, #0x10] */
/* @0x1b9c18 str r3, [r9, #0x20] */
/* @0x1b9c1c str r0, [r9, #0x1c] */
/* @0x1b9c20 strne r9, [r1, #0x18] */
/* @0x1b9c24 strne r3, [r9, #0x18] */
/* @0x1b9c28 mov r3, #0 */
/* @0x1b9c2c strne r1, [r9, #0x14] */
/* @0x1b9c30 ldr r1, [r11, #0x10c] */
/* @0x1b9c34 streq r9, [r2, #0x4] */
/* @0x1b9c38 streq r9, [r2] */
/* @0x1b9c3c strne r9, [r2] */
/* @0x1b9c40 cmp r9, r1 */
/* @0x1b9c44 strb r3, [r4, #0x174] */
/* @0x1b9c48 str r12, [r2, #0x8] */
/* @0x1b9c4c mvn r2, #0 */
/* @0x1b9c50 str r2, [r4, #0x170] */
/* @0x1b9c54 streq r3, [r11, #0x10c] */
/* @0x1b9c58 ldrb r3, [r10, #0x19] */
/* @0x1b9c5c cmp r3, #0 */
/* @0x1b9c60 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9c64 ldr r2, [r10, #0x60] */
/* @0x1b9c68 cmp r2, #0 */
/* @0x1b9c6c bne 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9c70 mov r0, r11 */
/* @0x1b9c74 ldr r1, [r10] */
/* @0x1b9c78 add sp, sp, #28 */
/* @0x1b9c7c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b9c80 b 0x1b95d8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib> */
/* @0x1b9c84 cmn r3, #1 */
/* @0x1b9c88 beq 0x1b9afc <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x1e0> */
/* @0x1b9c8c add r6, r3, #1 */
/* @0x1b9c90 and r6, r6, r2 */
/* @0x1b9c94 add r5, r6, r6, lsl #1 */
/* @0x1b9c98 add r5, r12, r5, lsl #2 */
/* @0x1b9c9c ldr lr, [r5, #0x8] */
/* @0x1b9ca0 cmp lr, #0 */
/* @0x1b9ca4 beq 0x1b9e48 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x52c> */
/* @0x1b9ca8 ldr r8, [r11, #0xf8] */
/* @0x1b9cac and r0, r2, lr */
/* @0x1b9cb0 add r7, r6, r8 */
/* @0x1b9cb4 rsb r0, r0, r7 */
/* @0x1b9cb8 tst r0, r2 */
/* @0x1b9cbc beq 0x1b9e48 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x52c> */
/* @0x1b9cc0 str r4, [sp, #0x10] */
/* @0x1b9cc4 mov r4, r8 */
/* @0x1b9cc8 stmib sp, {r9, r11} */
/* @0x1b9ccc str r10, [sp, #0xc] */
/* @0x1b9cd0 b 0x1b9ce0 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x3c4> */
/* @0x1b9cd4 tst r10, r2 */
/* @0x1b9cd8 beq 0x1b9d2c <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x410> */
/* @0x1b9cdc mov r6, r0 */
/* @0x1b9ce0 add r8, r1, r3 */
/* @0x1b9ce4 add r0, r6, #1 */
/* @0x1b9ce8 and r0, r0, r2 */
/* @0x1b9cec ldr r9, [r5, #0x4] */
/* @0x1b9cf0 add r7, r12, r8, lsl #2 */
/* @0x1b9cf4 add r10, r0, r4 */
/* @0x1b9cf8 add r11, r0, r0, lsl #1 */
/* @0x1b9cfc mov r3, r6 */
/* @0x1b9d00 str lr, [r7, #0x8] */
/* @0x1b9d04 lsl r1, r6, #1 */
/* @0x1b9d08 ldr r5, [r5] */
/* @0x1b9d0c str r5, [r12, r8, lsl #2] */
/* @0x1b9d10 add r5, r12, r11, lsl #2 */
/* @0x1b9d14 ldr lr, [r5, #0x8] */
/* @0x1b9d18 str r9, [r7, #0x4] */
/* @0x1b9d1c cmp lr, #0 */
/* @0x1b9d20 and r8, r2, lr */
/* @0x1b9d24 rsb r10, r8, r10 */
/* @0x1b9d28 bne 0x1b9cd4 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x3b8> */
/* @0x1b9d2c ldmib sp, {r9, r11} */
/* @0x1b9d30 ldr r10, [sp, #0xc] */
/* @0x1b9d34 ldr r4, [sp, #0x10] */
/* @0x1b9d38 add r6, r6, r6, lsl #1 */
/* @0x1b9d3c ldr r3, [r11, #0xfc] */
/* @0x1b9d40 mov r2, #0 */
/* @0x1b9d44 add r12, r12, r6, lsl #2 */
/* @0x1b9d48 sub r3, r3, #1 */
/* @0x1b9d4c str r2, [r12, #0x8] */
/* @0x1b9d50 str r3, [r11, #0xfc] */
/* @0x1b9d54 b 0x1b9afc <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x1e0> */
/* @0x1b9d58 cmn r3, #1 */
/* @0x1b9d5c ldr r9, [sp] */
/* @0x1b9d60 beq 0x1b9ba4 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x288> */
/* @0x1b9d64 add r0, r3, #1 */
/* @0x1b9d68 and r6, r0, r2 */
/* @0x1b9d6c add r5, r6, r6, lsl #1 */
/* @0x1b9d70 add r5, r8, r5, lsl #2 */
/* @0x1b9d74 ldr r12, [r5, #0x8] */
/* @0x1b9d78 cmp r12, #0 */
/* @0x1b9d7c beq 0x1b9e40 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x524> */
/* @0x1b9d80 ldr r0, [r11, #0x110] */
/* @0x1b9d84 str r0, [sp, #0x4] */
/* @0x1b9d88 and r0, r2, r12 */
/* @0x1b9d8c ldr r7, [sp, #0x4] */
/* @0x1b9d90 add r7, r6, r7 */
/* @0x1b9d94 rsb r0, r0, r7 */
/* @0x1b9d98 tst r0, r2 */
/* @0x1b9d9c strne r9, [sp, #0x8] */
/* @0x1b9da0 strne r11, [sp, #0xc] */
/* @0x1b9da4 strne r10, [sp, #0x10] */
/* @0x1b9da8 strne r4, [sp, #0x14] */
/* @0x1b9dac bne 0x1b9dc0 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x4a4> */
/* @0x1b9db0 b 0x1b9e40 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x524> */
/* @0x1b9db4 tst r10, r2 */
/* @0x1b9db8 beq 0x1b9e10 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x4f4> */
/* @0x1b9dbc mov r6, r0 */
/* @0x1b9dc0 add r7, r1, r3 */
/* @0x1b9dc4 add r0, r6, #1 */
/* @0x1b9dc8 and r0, r0, r2 */
/* @0x1b9dcc ldr r9, [r5, #0x4] */
/* @0x1b9dd0 add r4, r8, r7, lsl #2 */
/* @0x1b9dd4 ldr r1, [sp, #0x4] */
/* @0x1b9dd8 add r11, r0, r0, lsl #1 */
/* @0x1b9ddc mov r3, r6 */
/* @0x1b9de0 str r12, [r4, #0x8] */
/* @0x1b9de4 add r10, r0, r1 */
/* @0x1b9de8 ldr r5, [r5] */
/* @0x1b9dec lsl r1, r6, #1 */
/* @0x1b9df0 str r5, [r8, r7, lsl #2] */
/* @0x1b9df4 add r5, r8, r11, lsl #2 */
/* @0x1b9df8 ldr r12, [r5, #0x8] */
/* @0x1b9dfc str r9, [r4, #0x4] */
/* @0x1b9e00 cmp r12, #0 */
/* @0x1b9e04 and r7, r2, r12 */
/* @0x1b9e08 rsb r10, r7, r10 */
/* @0x1b9e0c bne 0x1b9db4 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x498> */
/* @0x1b9e10 ldr r9, [sp, #0x8] */
/* @0x1b9e14 ldr r11, [sp, #0xc] */
/* @0x1b9e18 ldr r10, [sp, #0x10] */
/* @0x1b9e1c ldr r4, [sp, #0x14] */
/* @0x1b9e20 add r1, r6, r6, lsl #1 */
/* @0x1b9e24 ldr r3, [r11, #0x114] */
/* @0x1b9e28 mov r2, #0 */
/* @0x1b9e2c add r1, r8, r1, lsl #2 */
/* @0x1b9e30 sub r3, r3, #1 */
/* @0x1b9e34 str r2, [r1, #0x8] */
/* @0x1b9e38 str r3, [r11, #0x114] */
/* @0x1b9e3c b 0x1b9ba4 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x288> */
/* @0x1b9e40 mov r6, r3 */
/* @0x1b9e44 b 0x1b9e20 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x504> */
/* @0x1b9e48 mov r6, r3 */
/* @0x1b9e4c b 0x1b9d38 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x41c> */
/* @0x1b9e50 .word 0x00233cdc */
/* @0x1b9e54 andseq r3, r9, r4, lsl #25 */
/* @0x1b9e58 eoreq r6, r3, r12, ror r12 */

/* ── FUNC 0x1b9e5c · CLayerManager::RemoveInstance(CRoom*, CInstance*) · size=72 · insn=18 */
/* @0x1b9e5c push {r3, r4, r5, lr} */
/* @0x1b9e60 subs r4, r1, #0 */
/* @0x1b9e64 mov r5, r0 */
/* @0x1b9e68 popeq {r3, r4, r5, pc} */
/* @0x1b9e6c ldrb r3, [r4, #0x174] */
/* @0x1b9e70 cmp r3, #0 */
/* @0x1b9e74 popeq {r3, r4, r5, pc} */
/* @0x1b9e78 ldr r1, [r4, #0x170] */
/* @0x1b9e7c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1b9e80 subs r1, r0, #0 */
/* @0x1b9e84 strbeq r1, [r4, #0x174] */
/* @0x1b9e88 mvneq r3, #0 */
/* @0x1b9e8c streq r3, [r4, #0x170] */
/* @0x1b9e90 popeq {r3, r4, r5, pc} */
/* @0x1b9e94 mov r0, r5 */
/* @0x1b9e98 mov r2, r4 */
/* @0x1b9e9c pop {r3, r4, r5, lr} */
/* @0x1b9ea0 b 0x1b991c <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance> */

/* ── FUNC 0x1b9ea4 · CLayerManager::RemoveStorageInstanceFromLayer(CRoom*, CLayer*, int) · size=1300 · insn=325 */
/* @0x1b9ea4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b9ea8 subs r4, r0, #0 */
/* @0x1b9eac sub sp, sp, #20 */
/* @0x1b9eb0 mov r11, r1 */
/* @0x1b9eb4 mov r9, r2 */
/* @0x1b9eb8 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9ebc cmp r1, #0 */
/* @0x1b9ec0 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9ec4 cmn r2, #1 */
/* @0x1b9ec8 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9ecc mov r0, r2 */
/* @0x1b9ed0 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b9ed4 ldr r12, [r4, #0x118] */
/* @0x1b9ed8 ldr r8, [r4, #0x120] */
/* @0x1b9edc bic r0, r0, #-2147483648 */
/* @0x1b9ee0 and r3, r0, r12 */
/* @0x1b9ee4 lsl r6, r3, #1 */
/* @0x1b9ee8 add r2, r6, r3 */
/* @0x1b9eec add r2, r8, r2, lsl #2 */
/* @0x1b9ef0 ldr r1, [r2, #0x8] */
/* @0x1b9ef4 cmp r1, #0 */
/* @0x1b9ef8 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9efc cmp r0, r1 */
/* @0x1b9f00 beq 0x1b9f78 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xd4> */
/* @0x1b9f04 ldr r2, [r4, #0x110] */
/* @0x1b9f08 and r1, r12, r1 */
/* @0x1b9f0c add r5, r2, r3 */
/* @0x1b9f10 rsb r1, r1, r5 */
/* @0x1b9f14 tst r1, r12 */
/* @0x1b9f18 bmi 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9f1c mov r5, #0 */
/* @0x1b9f20 b 0x1b9f34 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x90> */
/* @0x1b9f24 cmp r0, r1 */
/* @0x1b9f28 beq 0x1b9f70 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xcc> */
/* @0x1b9f2c cmp r7, r5 */
/* @0x1b9f30 blt 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9f34 add r3, r3, #1 */
/* @0x1b9f38 add r5, r5, #1 */
/* @0x1b9f3c and r3, r12, r3 */
/* @0x1b9f40 add r10, r2, r3 */
/* @0x1b9f44 lsl r6, r3, #1 */
/* @0x1b9f48 add r1, r6, r3 */
/* @0x1b9f4c add r1, r8, r1, lsl #2 */
/* @0x1b9f50 ldr r1, [r1, #0x8] */
/* @0x1b9f54 and r7, r12, r1 */
/* @0x1b9f58 cmp r1, #0 */
/* @0x1b9f5c rsb r7, r7, r10 */
/* @0x1b9f60 and r7, r7, r12 */
/* @0x1b9f64 bne 0x1b9f24 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x80> */
/* @0x1b9f68 add sp, sp, #20 */
/* @0x1b9f6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b9f70 cmn r3, #1 */
/* @0x1b9f74 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9f78 add r3, r6, r3 */
/* @0x1b9f7c add r8, r8, r3, lsl #2 */
/* @0x1b9f80 cmn r8, #4 */
/* @0x1b9f84 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9f88 ldr r8, [r8, #0x4] */
/* @0x1b9f8c cmp r8, #0 */
/* @0x1b9f90 str r8, [sp] */
/* @0x1b9f94 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9f98 ldr r3, [r8, #0x10] */
/* @0x1b9f9c cmp r3, #0 */
/* @0x1b9fa0 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9fa4 cmp r11, r3 */
/* @0x1b9fa8 beq 0x1b9fdc <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x138> */
/* @0x1b9fac ldr r0, [pc, #0x3f8] */
/* @0x1b9fb0 mov r2, r9 */
/* @0x1b9fb4 ldr r1, [pc, #0x3f4] */
/* @0x1b9fb8 ldr r0, [pc, r0] */
/* @0x1b9fbc ldr r3, [r11] */
/* @0x1b9fc0 add r1, pc, r1 */
/* @0x1b9fc4 ldr r0, [r0] */
/* @0x1b9fc8 ldr r12, [r0] */
/* @0x1b9fcc ldr r12, [r12, #0xc] */
/* @0x1b9fd0 blx r12 */
/* @0x1b9fd4 add sp, sp, #20 */
/* @0x1b9fd8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b9fdc ldr r1, [sp] */
/* @0x1b9fe0 ldr r0, [r1, #0x4] */
/* @0x1b9fe4 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b9fe8 ldr r2, [r4, #0x100] */
/* @0x1b9fec ldr r12, [r4, #0x108] */
/* @0x1b9ff0 bic r0, r0, #-2147483648 */
/* @0x1b9ff4 and r3, r0, r2 */
/* @0x1b9ff8 lsl r1, r3, #1 */
/* @0x1b9ffc add lr, r1, r3 */
/* @0x1ba000 add lr, r12, lr, lsl #2 */
/* @0x1ba004 ldr lr, [lr, #0x8] */
/* @0x1ba008 cmp lr, #0 */
/* @0x1ba00c beq 0x1ba07c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x1d8> */
/* @0x1ba010 cmp r0, lr */
/* @0x1ba014 beq 0x1ba210 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x36c> */
/* @0x1ba018 ldr r8, [r4, #0xf8] */
/* @0x1ba01c and lr, r2, lr */
/* @0x1ba020 add r1, r3, r8 */
/* @0x1ba024 rsb r1, lr, r1 */
/* @0x1ba028 tst r1, r2 */
/* @0x1ba02c bmi 0x1ba07c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x1d8> */
/* @0x1ba030 mov r5, #0 */
/* @0x1ba034 b 0x1ba048 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x1a4> */
/* @0x1ba038 cmp r0, lr */
/* @0x1ba03c beq 0x1ba208 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x364> */
/* @0x1ba040 cmp r6, r5 */
/* @0x1ba044 blt 0x1ba07c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x1d8> */
/* @0x1ba048 add r3, r3, #1 */
/* @0x1ba04c add r5, r5, #1 */
/* @0x1ba050 and r3, r2, r3 */
/* @0x1ba054 add r7, r3, r8 */
/* @0x1ba058 lsl r1, r3, #1 */
/* @0x1ba05c add lr, r1, r3 */
/* @0x1ba060 add lr, r12, lr, lsl #2 */
/* @0x1ba064 ldr lr, [lr, #0x8] */
/* @0x1ba068 and r6, r2, lr */
/* @0x1ba06c cmp lr, #0 */
/* @0x1ba070 rsb r6, r6, r7 */
/* @0x1ba074 and r6, r6, r2 */
/* @0x1ba078 bne 0x1ba038 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x194> */
/* @0x1ba07c ldr r2, [sp] */
/* @0x1ba080 ldr r0, [r2, #0x1c] */
/* @0x1ba084 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1ba088 ldr r2, [r4, #0x118] */
/* @0x1ba08c ldr r12, [r4, #0x120] */
/* @0x1ba090 bic r0, r0, #-2147483648 */
/* @0x1ba094 and r3, r0, r2 */
/* @0x1ba098 lsl r1, r3, #1 */
/* @0x1ba09c add r5, r1, r3 */
/* @0x1ba0a0 add r5, r12, r5, lsl #2 */
/* @0x1ba0a4 ldr r5, [r5, #0x8] */
/* @0x1ba0a8 cmp r5, #0 */
/* @0x1ba0ac beq 0x1ba11c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x278> */
/* @0x1ba0b0 cmp r0, r5 */
/* @0x1ba0b4 beq 0x1ba2d4 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x430> */
/* @0x1ba0b8 ldr r8, [r4, #0x110] */
/* @0x1ba0bc and r5, r2, r5 */
/* @0x1ba0c0 add r1, r8, r3 */
/* @0x1ba0c4 rsb r1, r5, r1 */
/* @0x1ba0c8 tst r1, r2 */
/* @0x1ba0cc bmi 0x1ba11c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x278> */
/* @0x1ba0d0 mov r6, #0 */
/* @0x1ba0d4 b 0x1ba0e8 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x244> */
/* @0x1ba0d8 cmp r0, r5 */
/* @0x1ba0dc beq 0x1ba2cc <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x428> */
/* @0x1ba0e0 cmp r7, r6 */
/* @0x1ba0e4 blt 0x1ba11c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x278> */
/* @0x1ba0e8 add r3, r3, #1 */
/* @0x1ba0ec add r6, r6, #1 */
/* @0x1ba0f0 and r3, r2, r3 */
/* @0x1ba0f4 add r9, r8, r3 */
/* @0x1ba0f8 lsl r1, r3, #1 */
/* @0x1ba0fc add r5, r1, r3 */
/* @0x1ba100 add r5, r12, r5, lsl #2 */
/* @0x1ba104 ldr r5, [r5, #0x8] */
/* @0x1ba108 and r7, r2, r5 */
/* @0x1ba10c cmp r5, #0 */
/* @0x1ba110 rsb r7, r7, r9 */
/* @0x1ba114 and r7, r7, r2 */
/* @0x1ba118 bne 0x1ba0d8 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x234> */
/* @0x1ba11c ldr r10, [sp] */
/* @0x1ba120 mvn r0, #0 */
/* @0x1ba124 ldr r6, [sp] */
/* @0x1ba128 mov r5, #2 */
/* @0x1ba12c ldr r3, [r10, #0x18] */
/* @0x1ba130 cmp r3, #0 */
/* @0x1ba134 ldrne r1, [sp] */
/* @0x1ba138 ldreq r2, [r10, #0x14] */
/* @0x1ba13c ldrne r2, [r1, #0x14] */
/* @0x1ba140 streq r2, [r11, #0x58] */
/* @0x1ba144 strne r2, [r3, #0x14] */
/* @0x1ba148 ldrne r3, [r1, #0x18] */
/* @0x1ba14c ldrne r2, [r1, #0x14] */
/* @0x1ba150 ldr r1, [r11, #0x60] */
/* @0x1ba154 cmp r2, #0 */
/* @0x1ba158 streq r3, [r11, #0x5c] */
/* @0x1ba15c strne r3, [r2, #0x18] */
/* @0x1ba160 add r1, r1, r0 */
/* @0x1ba164 ldr r2, [pc, #0x248] */
/* @0x1ba168 mov r3, #0 */
/* @0x1ba16c str r1, [r11, #0x60] */
/* @0x1ba170 ldr r2, [pc, r2] */
/* @0x1ba174 str r3, [r6, #0xc] */
/* @0x1ba178 str r3, [r6, #0x10] */
/* @0x1ba17c ldr r1, [r2] */
/* @0x1ba180 ldr r12, [r2, #0x8] */
/* @0x1ba184 cmp r1, r3 */
/* @0x1ba188 str r5, [r6] */
/* @0x1ba18c strb r3, [r6, #0x8] */
/* @0x1ba190 add r12, r12, #1 */
/* @0x1ba194 ldrne r8, [sp] */
/* @0x1ba198 str r0, [r6, #0x4] */
/* @0x1ba19c str r3, [r6, #0x14] */
/* @0x1ba1a0 str r3, [r6, #0x18] */
/* @0x1ba1a4 str r3, [r6, #0x20] */
/* @0x1ba1a8 str r0, [r6, #0x1c] */
/* @0x1ba1ac streq r6, [r2, #0x4] */
/* @0x1ba1b0 strne r8, [r1, #0x18] */
/* @0x1ba1b4 streq r6, [r2] */
/* @0x1ba1b8 strne r8, [r2] */
/* @0x1ba1bc strne r1, [r8, #0x14] */
/* @0x1ba1c0 str r12, [r2, #0x8] */
/* @0x1ba1c4 strne r3, [r8, #0x18] */
/* @0x1ba1c8 ldr r3, [r4, #0x10c] */
/* @0x1ba1cc ldr r10, [sp] */
/* @0x1ba1d0 cmp r10, r3 */
/* @0x1ba1d4 moveq r3, #0 */
/* @0x1ba1d8 streq r3, [r4, #0x10c] */
/* @0x1ba1dc ldrb r3, [r11, #0x19] */
/* @0x1ba1e0 cmp r3, #0 */
/* @0x1ba1e4 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1ba1e8 ldr r2, [r11, #0x60] */
/* @0x1ba1ec cmp r2, #0 */
/* @0x1ba1f0 bne 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1ba1f4 mov r0, r4 */
/* @0x1ba1f8 ldr r1, [r11] */
/* @0x1ba1fc add sp, sp, #20 */
/* @0x1ba200 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ba204 b 0x1b95d8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib> */
/* @0x1ba208 cmn r3, #1 */
/* @0x1ba20c beq 0x1ba07c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x1d8> */
/* @0x1ba210 add r6, r3, #1 */
/* @0x1ba214 and r6, r6, r2 */
/* @0x1ba218 add r5, r6, r6, lsl #1 */
/* @0x1ba21c add r5, r12, r5, lsl #2 */
/* @0x1ba220 ldr lr, [r5, #0x8] */
/* @0x1ba224 cmp lr, #0 */
/* @0x1ba228 beq 0x1ba3a4 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x500> */
/* @0x1ba22c ldr r8, [r4, #0xf8] */
/* @0x1ba230 and r0, r2, lr */
/* @0x1ba234 add r7, r6, r8 */
/* @0x1ba238 rsb r0, r0, r7 */
/* @0x1ba23c tst r0, r2 */
/* @0x1ba240 beq 0x1ba3a4 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x500> */
/* @0x1ba244 stmib sp, {r4, r11} */
/* @0x1ba248 mov r11, r8 */
/* @0x1ba24c b 0x1ba25c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x3b8> */
/* @0x1ba250 tst r9, r2 */
/* @0x1ba254 beq 0x1ba2a8 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x404> */
/* @0x1ba258 mov r6, r0 */
/* @0x1ba25c add r7, r1, r3 */
/* @0x1ba260 add r0, r6, #1 */
/* @0x1ba264 and r0, r0, r2 */
/* @0x1ba268 ldr r8, [r5, #0x4] */
/* @0x1ba26c add r4, r12, r7, lsl #2 */
/* @0x1ba270 add r9, r0, r11 */
/* @0x1ba274 add r10, r0, r0, lsl #1 */
/* @0x1ba278 mov r3, r6 */
/* @0x1ba27c str lr, [r4, #0x8] */
/* @0x1ba280 lsl r1, r6, #1 */
/* @0x1ba284 ldr r5, [r5] */
/* @0x1ba288 str r5, [r12, r7, lsl #2] */
/* @0x1ba28c add r5, r12, r10, lsl #2 */
/* @0x1ba290 ldr lr, [r5, #0x8] */
/* @0x1ba294 str r8, [r4, #0x4] */
/* @0x1ba298 cmp lr, #0 */
/* @0x1ba29c and r7, r2, lr */
/* @0x1ba2a0 rsb r9, r7, r9 */
/* @0x1ba2a4 bne 0x1ba250 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x3ac> */
/* @0x1ba2a8 ldmib sp, {r4, r11} */
/* @0x1ba2ac add r6, r6, r6, lsl #1 */
/* @0x1ba2b0 ldr r3, [r4, #0xfc] */
/* @0x1ba2b4 mov r2, #0 */
/* @0x1ba2b8 add r12, r12, r6, lsl #2 */
/* @0x1ba2bc sub r3, r3, #1 */
/* @0x1ba2c0 str r2, [r12, #0x8] */
/* @0x1ba2c4 str r3, [r4, #0xfc] */
/* @0x1ba2c8 b 0x1ba07c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x1d8> */
/* @0x1ba2cc cmn r3, #1 */
/* @0x1ba2d0 beq 0x1ba11c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x278> */
/* @0x1ba2d4 add r0, r3, #1 */
/* @0x1ba2d8 and r9, r0, r2 */
/* @0x1ba2dc add r6, r9, r9, lsl #1 */
/* @0x1ba2e0 add r6, r12, r6, lsl #2 */
/* @0x1ba2e4 ldr r5, [r6, #0x8] */
/* @0x1ba2e8 cmp r5, #0 */
/* @0x1ba2ec beq 0x1ba39c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x4f8> */
/* @0x1ba2f0 ldr r8, [r4, #0x110] */
/* @0x1ba2f4 and r0, r2, r5 */
/* @0x1ba2f8 add r7, r9, r8 */
/* @0x1ba2fc rsb r0, r0, r7 */
/* @0x1ba300 str r8, [sp, #0x4] */
/* @0x1ba304 tst r0, r2 */
/* @0x1ba308 strne r4, [sp, #0x8] */
/* @0x1ba30c strne r11, [sp, #0xc] */
/* @0x1ba310 bne 0x1ba324 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x480> */
/* @0x1ba314 b 0x1ba39c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x4f8> */
/* @0x1ba318 tst r10, r2 */
/* @0x1ba31c beq 0x1ba374 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x4d0> */
/* @0x1ba320 mov r9, r0 */
/* @0x1ba324 add r7, r1, r3 */
/* @0x1ba328 add r0, r9, #1 */
/* @0x1ba32c and r0, r0, r2 */
/* @0x1ba330 ldr r11, [sp, #0x4] */
/* @0x1ba334 add r4, r12, r7, lsl #2 */
/* @0x1ba338 ldr r8, [r6, #0x4] */
/* @0x1ba33c add r10, r0, r11 */
/* @0x1ba340 add r11, r0, r0, lsl #1 */
/* @0x1ba344 str r5, [r4, #0x8] */
/* @0x1ba348 mov r3, r9 */
/* @0x1ba34c ldr r6, [r6] */
/* @0x1ba350 lsl r1, r9, #1 */
/* @0x1ba354 str r6, [r12, r7, lsl #2] */
/* @0x1ba358 add r6, r12, r11, lsl #2 */
/* @0x1ba35c ldr r5, [r6, #0x8] */
/* @0x1ba360 str r8, [r4, #0x4] */
/* @0x1ba364 cmp r5, #0 */
/* @0x1ba368 and r7, r2, r5 */
/* @0x1ba36c rsb r10, r7, r10 */
/* @0x1ba370 bne 0x1ba318 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x474> */
/* @0x1ba374 ldr r4, [sp, #0x8] */
/* @0x1ba378 ldr r11, [sp, #0xc] */
/* @0x1ba37c add r1, r9, r9, lsl #1 */
/* @0x1ba380 ldr r3, [r4, #0x114] */
/* @0x1ba384 mov r2, #0 */
/* @0x1ba388 add r12, r12, r1, lsl #2 */
/* @0x1ba38c sub r3, r3, #1 */
/* @0x1ba390 str r2, [r12, #0x8] */
/* @0x1ba394 str r3, [r4, #0x114] */
/* @0x1ba398 b 0x1ba11c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x278> */
/* @0x1ba39c mov r9, r3 */
/* @0x1ba3a0 b 0x1ba37c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x4d8> */
/* @0x1ba3a4 mov r6, r3 */
/* @0x1ba3a8 b 0x1ba2ac <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x408> */
/* @0x1ba3ac eoreq r3, r3, r12, asr r7 */
/* @0x1ba3b0 andseq r3, r9, r8, lsl #14 */
/* @0x1ba3b4 .word 0x002366f4 */

/* ── FUNC 0x1ba3b8 · CLayerManager::GetTilesFromPool(int) · size=348 · insn=87 */
/* @0x1ba3b8 adds r3, r1, #31 */
/* @0x1ba3bc addmi r1, r1, #62 */
/* @0x1ba3c0 movpl r1, r3 */
/* @0x1ba3c4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1ba3c8 asr r9, r1, #5 */
/* @0x1ba3cc mov r8, #0 */
/* @0x1ba3d0 cmp r9, r8 */
/* @0x1ba3d4 mov r7, r0 */
/* @0x1ba3d8 str r8, [r0, #0x4] */
/* @0x1ba3dc str r8, [r0] */
/* @0x1ba3e0 str r8, [r0, #0x8] */
/* @0x1ba3e4 str r8, [r0, #0xc] */
/* @0x1ba3e8 ble 0x1ba504 <_ZN13CLayerManager16GetTilesFromPoolEi+0x14c> */
/* @0x1ba3ec ldr r4, [pc, #0x118] */
/* @0x1ba3f0 mov r5, r8 */
/* @0x1ba3f4 ldr r6, [pc, #0x114] */
/* @0x1ba3f8 ldr r4, [pc, r4] */
/* @0x1ba3fc add r6, pc, r6 */
/* @0x1ba400 ldr r10, [r4, #0x8] */
/* @0x1ba404 cmp r10, #0 */
/* @0x1ba408 bne 0x1ba48c <_ZN13CLayerManager16GetTilesFromPoolEi+0xd4> */
/* @0x1ba40c ldr r3, [r4, #0x10] */
/* @0x1ba410 cmp r3, #0 */
/* @0x1ba414 ble 0x1ba484 <_ZN13CLayerManager16GetTilesFromPoolEi+0xcc> */
/* @0x1ba418 mov r2, #63 */
/* @0x1ba41c mov r3, #1 */
/* @0x1ba420 movw r0, #0x70c */
/* @0x1ba424 mov r1, r6 */
/* @0x1ba428 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ba42c ldr r3, [r4] */
/* @0x1ba430 add r10, r10, #1 */
/* @0x1ba434 ldr r2, [r4, #0x8] */
/* @0x1ba438 add r2, r2, #1 */
/* @0x1ba43c str r2, [r4, #0x8] */
/* @0x1ba440 cmp r0, #0 */
/* @0x1ba444 strne r5, [r0, #0x704] */
/* @0x1ba448 strne r5, [r0, #0x708] */
/* @0x1ba44c strne r5, [r0, #0x700] */
/* @0x1ba450 cmp r3, #0 */
/* @0x1ba454 strne r0, [r3, #0x708] */
/* @0x1ba458 streq r3, [r0, #0x708] */
/* @0x1ba45c streq r3, [r0, #0x704] */
/* @0x1ba460 strne r3, [r0, #0x704] */
/* @0x1ba464 ldr r3, [r4, #0x10] */
/* @0x1ba468 streq r0, [r4, #0x4] */
/* @0x1ba46c streq r0, [r4] */
/* @0x1ba470 strne r0, [r4] */
/* @0x1ba474 strne r5, [r0, #0x708] */
/* @0x1ba478 cmp r10, r3 */
/* @0x1ba47c blt 0x1ba418 <_ZN13CLayerManager16GetTilesFromPoolEi+0x60> */
/* @0x1ba480 ldr r10, [r4, #0x8] */
/* @0x1ba484 lsl r3, r3, #1 */
/* @0x1ba488 str r3, [r4, #0x10] */
/* @0x1ba48c ldr r3, [r4] */
/* @0x1ba490 sub r10, r10, #1 */
/* @0x1ba494 add r8, r8, #1 */
/* @0x1ba498 ldr r2, [r3, #0x708] */
/* @0x1ba49c ldr r1, [r3, #0x704] */
/* @0x1ba4a0 cmp r2, #0 */
/* @0x1ba4a4 strne r1, [r2, #0x704] */
/* @0x1ba4a8 ldrne r1, [r3, #0x704] */
/* @0x1ba4ac ldrne r2, [r3, #0x708] */
/* @0x1ba4b0 streq r1, [r4] */
/* @0x1ba4b4 cmp r1, #0 */
/* @0x1ba4b8 streq r2, [r4, #0x4] */
/* @0x1ba4bc strne r2, [r1, #0x708] */
/* @0x1ba4c0 ldr r2, [r7, #0x4] */
/* @0x1ba4c4 str r10, [r4, #0x8] */
/* @0x1ba4c8 cmp r2, #0 */
/* @0x1ba4cc ldr r1, [r7, #0x8] */
/* @0x1ba4d0 streq r3, [r7, #0x4] */
/* @0x1ba4d4 add r1, r1, #1 */
/* @0x1ba4d8 str r1, [r7, #0x8] */
/* @0x1ba4dc strne r3, [r2, #0x704] */
/* @0x1ba4e0 ldrne r2, [r7, #0x4] */
/* @0x1ba4e4 streq r3, [r7] */
/* @0x1ba4e8 streq r2, [r3, #0x708] */
/* @0x1ba4ec strne r2, [r3, #0x708] */
/* @0x1ba4f0 streq r2, [r3, #0x704] */
/* @0x1ba4f4 strne r3, [r7, #0x4] */
/* @0x1ba4f8 strne r5, [r3, #0x704] */
/* @0x1ba4fc cmp r8, r9 */
/* @0x1ba500 bne 0x1ba400 <_ZN13CLayerManager16GetTilesFromPoolEi+0x48> */
/* @0x1ba504 mov r0, r7 */
/* @0x1ba508 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1ba50c eoreq r6, r3, r4, lsl #9 */
/* @0x1ba510 mulseq r9, r8, r2 */

/* ── FUNC 0x1ba514 · CLayerManager::BuildOldTilemapElementRuntimeData(CRoom*, CLayer*, CLayerOldTilemapElement*) · size=424 · insn=106 */
/* @0x1ba514 ldr r3, [r2, #0x1c] */
/* @0x1ba518 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ba51c sub sp, sp, #20 */
/* @0x1ba520 ldr r9, [r3] */
/* @0x1ba524 mov r8, r2 */
/* @0x1ba528 mov r0, sp */
/* @0x1ba52c str r9, [r2, #0x20] */
/* @0x1ba530 mov r1, r9 */
/* @0x1ba534 bl 0x1ba3b8 <_ZN13CLayerManager16GetTilesFromPoolEi> */
/* @0x1ba538 ldm sp, {r0, r1, r2, r3} */
/* @0x1ba53c add r12, r8, #36 */
/* @0x1ba540 ldr r4, [sp, #0xc] */
/* @0x1ba544 cmp r4, #0 */
/* @0x1ba548 stm r12, {r0, r1, r2, r3} */
/* @0x1ba54c beq 0x1ba580 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x6c> */
/* @0x1ba550 ldr r0, [sp] */
/* @0x1ba554 cmp r0, #0 */
/* @0x1ba558 beq 0x1ba580 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x6c> */
/* @0x1ba55c cmp r4, #2 */
/* @0x1ba560 beq 0x1ba670 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x15c> */
/* @0x1ba564 cmp r4, #3 */
/* @0x1ba568 beq 0x1ba688 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x174> */
/* @0x1ba56c cmp r4, #1 */
/* @0x1ba570 beq 0x1ba6a0 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x18c> */
/* @0x1ba574 ldr r0, [r0, #0x704] */
/* @0x1ba578 cmp r0, #0 */
/* @0x1ba57c bne 0x1ba574 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x60> */
/* @0x1ba580 cmp r9, #0 */
/* @0x1ba584 ble 0x1ba660 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x14c> */
/* @0x1ba588 ldr r12, [r8, #0x24] */
/* @0x1ba58c ldr r6, [r8, #0x1c] */
/* @0x1ba590 cmp r12, #0 */
/* @0x1ba594 beq 0x1ba660 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x14c> */
/* @0x1ba598 mov r4, #0 */
/* @0x1ba59c mov r11, #1 */
/* @0x1ba5a0 mov r5, r4 */
/* @0x1ba5a4 vldr s11, [pc, #268] */
/* @0x1ba5a8 ldr r2, [r6, #0x4]! */
/* @0x1ba5ac vldr s10, [r2] */
/* @0x1ba5b0 vcvt.f32.s32 s14, s10 */
/* @0x1ba5b4 rsb r5, r5, r5, lsl #3 */
/* @0x1ba5b8 ldr r1, [r12, #0x700] */
/* @0x1ba5bc vldr s13, [r2, #4] */
/* @0x1ba5c0 ldr r0, [r2, #0x2c] */
/* @0x1ba5c4 add r3, r12, r5, lsl #3 */
/* @0x1ba5c8 vldr s12, [r2, #36] */
/* @0x1ba5cc ldr r10, [r2, #0xc] */
/* @0x1ba5d0 add r4, r4, #1 */
/* @0x1ba5d4 add r1, r1, #1 */
/* @0x1ba5d8 lsr r7, r0, #24 */
/* @0x1ba5dc ands r5, r4, #31 */
/* @0x1ba5e0 bic r0, r0, #-16777216 */
/* @0x1ba5e4 vmov s15, r7 */
/* @0x1ba5e8 ldr r7, [r2, #0x8] */
/* @0x1ba5ec vstr s14, [r3] */
/* @0x1ba5f0 vldr s14, [r2, #28] */
/* @0x1ba5f4 vcvt.f32.s32 s15, s15 */
/* @0x1ba5f8 str r7, [r3, #0x8] */
/* @0x1ba5fc ldr r7, [r2, #0x10] */
/* @0x1ba600 str r7, [r3, #0x10] */
/* @0x1ba604 ldr r7, [r2, #0x14] */
/* @0x1ba608 vdiv.f32 s15, s15, s11 */
/* @0x1ba60c str r10, [r3, #0xc] */
/* @0x1ba610 ldr r10, [r2, #0x18] */
/* @0x1ba614 str r7, [r3, #0x14] */
/* @0x1ba618 ldr r7, [r2, #0x20] */
/* @0x1ba61c ldr r2, [r2, #0x28] */
/* @0x1ba620 vstr s12, [r3, #36] */
/* @0x1ba624 str r10, [r3, #0x18] */
/* @0x1ba628 str r7, [r3, #0x20] */
/* @0x1ba62c str r2, [r3, #0x28] */
/* @0x1ba630 strb r11, [r3, #0x34] */
/* @0x1ba634 str r0, [r3, #0x2c] */
/* @0x1ba638 vcvt.f32.s32 s13, s13 */
/* @0x1ba63c vstr s15, [r3, #48] */
/* @0x1ba640 vcvt.f32.s32 s14, s14 */
/* @0x1ba644 vstr s13, [r3, #4] */
/* @0x1ba648 vstr s14, [r3, #28] */
/* @0x1ba64c str r1, [r12, #0x700] */
/* @0x1ba650 ldreq r12, [r12, #0x704] */
/* @0x1ba654 cmp r12, #0 */
/* @0x1ba658 cmpne r9, r4 */
/* @0x1ba65c bgt 0x1ba5a8 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x94> */
/* @0x1ba660 mov r3, #1 */
/* @0x1ba664 strb r3, [r8, #0x8] */
/* @0x1ba668 add sp, sp, #20 */
/* @0x1ba66c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ba670 ldr r4, [r0, #0x704] */
/* @0x1ba674 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ba678 cmp r4, #0 */
/* @0x1ba67c mov r0, r4 */
/* @0x1ba680 bne 0x1ba670 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x15c> */
/* @0x1ba684 b 0x1ba580 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x6c> */
/* @0x1ba688 ldr r4, [r0, #0x704] */
/* @0x1ba68c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ba690 cmp r4, #0 */
/* @0x1ba694 mov r0, r4 */
/* @0x1ba698 bne 0x1ba688 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x174> */
/* @0x1ba69c b 0x1ba580 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x6c> */
/* @0x1ba6a0 ldr r4, [r0, #0x704] */
/* @0x1ba6a4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1ba6a8 cmp r4, #0 */
/* @0x1ba6ac mov r0, r4 */
/* @0x1ba6b0 bne 0x1ba6a0 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x18c> */
/* @0x1ba6b4 b 0x1ba580 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement+0x6c> */
/* @0x1ba6b8 cmnmi pc, #0 */

/* ── FUNC 0x1ba6bc · CLayerManager::BuildElementRuntimeData(CRoom*, CLayer*, CLayerElementBase*) · size=116 · insn=29 */
/* @0x1ba6bc cmp r0, #0 */
/* @0x1ba6c0 bxeq lr */
/* @0x1ba6c4 cmp r1, #0 */
/* @0x1ba6c8 bxeq lr */
/* @0x1ba6cc cmp r2, #0 */
/* @0x1ba6d0 bxeq lr */
/* @0x1ba6d4 ldrb r3, [r2, #0x8] */
/* @0x1ba6d8 cmp r3, #0 */
/* @0x1ba6dc bxne lr */
/* @0x1ba6e0 ldr r3, [r2] */
/* @0x1ba6e4 sub r3, r3, #1 */
/* @0x1ba6e8 cmp r3, #6 */
/* @0x1ba6ec addls pc, pc, r3, lsl #2 */
/* @0x1ba6f0 b 0x1ba710 <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x54> */
/* @0x1ba6f4 b 0x1ba72c <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x70> */
/* @0x1ba6f8 b 0x1ba728 <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x6c> */
/* @0x1ba6fc b 0x1ba724 <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x68> */
/* @0x1ba700 b 0x1ba720 <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x64> */
/* @0x1ba704 b 0x1ba71c <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x60> */
/* @0x1ba708 b 0x1ba718 <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x5c> */
/* @0x1ba70c b 0x1ba714 <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase+0x58> */
/* @0x1ba710 bx lr */
/* @0x1ba714 b 0x1b81f4 <_ZN13CLayerManager27BuildTileElementRuntimeDataEP5CRoomP6CLayerP17CLayerTileElement> */
/* @0x1ba718 b 0x1b81e8 <_ZN13CLayerManager31BuildParticleElementRuntimeDataEP5CRoomP6CLayerP21CLayerParticleElement> */
/* @0x1ba71c b 0x1b81dc <_ZN13CLayerManager30BuildTilemapElementRuntimeDataEP5CRoomP6CLayerP20CLayerTilemapElement> */
/* @0x1ba720 b 0x1b81d0 <_ZN13CLayerManager29BuildSpriteElementRuntimeDataEP5CRoomP6CLayerP19CLayerSpriteElement> */
/* @0x1ba724 b 0x1ba514 <_ZN13CLayerManager33BuildOldTilemapElementRuntimeDataEP5CRoomP6CLayerP23CLayerOldTilemapElement> */
/* @0x1ba728 b 0x1b8048 <_ZN13CLayerManager31BuildInstanceElementRuntimeDataEP5CRoomP6CLayerP21CLayerInstanceElement> */
/* @0x1ba72c b 0x1b803c <_ZN13CLayerManager33BuildBackgroundElementRuntimeDataEP5CRoomP6CLayerP23CLayerBackgroundElement> */

/* ── FUNC 0x1ba730 · CLayerManager::GetTargetRoomObj() · size=72 · insn=18 */
/* @0x1ba730 push {r4, lr} */
/* @0x1ba734 ldr r4, [pc, #0x30] */
/* @0x1ba738 ldr r3, [pc, #0x30] */
/* @0x1ba73c add r4, pc, r4 */
/* @0x1ba740 ldr r3, [r4, r3] */
/* @0x1ba744 ldr r0, [r3] */
/* @0x1ba748 cmn r0, #1 */
/* @0x1ba74c beq 0x1ba75c <_ZN13CLayerManager16GetTargetRoomObjEv+0x2c> */
/* @0x1ba750 bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x1ba754 cmp r0, #0 */
/* @0x1ba758 popne {r4, pc} */
/* @0x1ba75c ldr r3, [pc, #0x10] */
/* @0x1ba760 ldr r3, [r4, r3] */
/* @0x1ba764 ldr r0, [r3] */
/* @0x1ba768 pop {r4, pc} */
/* @0x1ba76c eoreq r7, r3, r4, lsl r5 */
/* @0x1ba770 .word 0xffffec04 */
/* @0x1ba774 .word 0xffffbcd8 */

/* ── FUNC 0x1ba778 · F_LayerGetId(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x1ba778 cmp r3, #1 */
/* @0x1ba77c push {r3, r4, r5, r6, r7, lr} */
/* @0x1ba780 mov r3, #0 */
/* @0x1ba784 mov r5, r3 */
/* @0x1ba788 mov r4, r0 */
/* @0x1ba78c movt r3, #0xbff0 */
/* @0x1ba790 str r5, [r0, #0xc] */
/* @0x1ba794 str r3, [r0, #0x4] */
/* @0x1ba798 str r5, [r0] */
/* @0x1ba79c ldr r6, [sp, #0x18] */
/* @0x1ba7a0 beq 0x1ba7b8 <_Z12F_LayerGetIdR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1ba7a4 ldr r0, [pc, #0x50] */
/* @0x1ba7a8 mov r1, r5 */
/* @0x1ba7ac pop {r3, r4, r5, r6, r7, lr} */
/* @0x1ba7b0 add r0, pc, r0 */
/* @0x1ba7b4 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1ba7b8 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1ba7bc subs r7, r0, #0 */
/* @0x1ba7c0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1ba7c4 mov r1, r5 */
/* @0x1ba7c8 mov r0, r6 */
/* @0x1ba7cc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1ba7d0 mov r1, r0 */
/* @0x1ba7d4 mov r0, r7 */
/* @0x1ba7d8 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1ba7dc cmp r0, #0 */
/* @0x1ba7e0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1ba7e4 ldr r2, [r0] */
/* @0x1ba7e8 vmov s15, r2 */
/* @0x1ba7ec vcvt.f64.s32 d7, s15 */
/* @0x1ba7f0 vmov r2, r3, d7 */
/* @0x1ba7f4 stm r4, {r2, r3} */
/* @0x1ba7f8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1ba7fc andseq r2, r9, r12, asr pc */

/* ── FUNC 0x1ba800 · F_LayerGetIdAtDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=396 · insn=99 */
/* @0x1ba800 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ba804 sub sp, sp, #4 */
/* @0x1ba808 mov r6, r0 */
/* @0x1ba80c mov r4, r3 */
/* @0x1ba810 ldr r5, [sp, #0x28] */
/* @0x1ba814 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1ba818 subs r8, r0, #0 */
/* @0x1ba81c beq 0x1ba838 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1ba820 cmp r4, #1 */
/* @0x1ba824 beq 0x1ba858 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x1ba828 ldr r0, [pc, #0x154] */
/* @0x1ba82c mov r1, #0 */
/* @0x1ba830 add r0, pc, r0 */
/* @0x1ba834 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1ba838 mov r0, r6 */
/* @0x1ba83c mov r1, #1 */
/* @0x1ba840 mov r2, #0 */
/* @0x1ba844 mov r3, #0 */
/* @0x1ba848 movt r3, #0xbff0 */
/* @0x1ba84c add sp, sp, #4 */
/* @0x1ba850 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ba854 b 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x1ba858 mov r0, r5 */
/* @0x1ba85c mov r1, #0 */
/* @0x1ba860 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1ba864 ldr r4, [r8, #0xd4] */
/* @0x1ba868 cmp r4, #0 */
/* @0x1ba86c mov r5, r0 */
/* @0x1ba870 beq 0x1ba838 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1ba874 mov r7, #0 */
/* @0x1ba878 ldrb r3, [r4, #0x19] */
/* @0x1ba87c cmp r3, #0 */
/* @0x1ba880 bne 0x1ba890 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1ba884 ldr r3, [r4, #0x4] */
/* @0x1ba888 cmp r3, r5 */
/* @0x1ba88c addeq r7, r7, #1 */
/* @0x1ba890 ldr r4, [r4, #0x68] */
/* @0x1ba894 cmp r4, #0 */
/* @0x1ba898 bne 0x1ba878 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1ba89c cmp r7, #0 */
/* @0x1ba8a0 beq 0x1ba838 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1ba8a4 mov r3, #2 */
/* @0x1ba8a8 mov r0, r6 */
/* @0x1ba8ac str r3, [r6, #0xc] */
/* @0x1ba8b0 mov r10, #1 */
/* @0x1ba8b4 bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x1ba8b8 ldr r11, [pc, #0xc8] */
/* @0x1ba8bc mov r3, r10 */
/* @0x1ba8c0 mov r2, #2688 */
/* @0x1ba8c4 add r11, pc, r11 */
/* @0x1ba8c8 mov r1, r11 */
/* @0x1ba8cc mov r9, r0 */
/* @0x1ba8d0 str r0, [r6] */
/* @0x1ba8d4 str r10, [r0, #0x10] */
/* @0x1ba8d8 mov r0, #8 */
/* @0x1ba8dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ba8e0 mov r1, r11 */
/* @0x1ba8e4 mov r3, r10 */
/* @0x1ba8e8 movw r2, #0xa81 */
/* @0x1ba8ec str r0, [r9, #0x4] */
/* @0x1ba8f0 lsl r0, r7, #4 */
/* @0x1ba8f4 ldr r12, [r6] */
/* @0x1ba8f8 ldr r9, [r12, #0x4] */
/* @0x1ba8fc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ba900 ldr r1, [r8, #0xd4] */
/* @0x1ba904 cmp r1, #0 */
/* @0x1ba908 str r0, [r9, #0x4] */
/* @0x1ba90c ldr r3, [r6] */
/* @0x1ba910 ldr r3, [r3, #0x4] */
/* @0x1ba914 str r7, [r3] */
/* @0x1ba918 beq 0x1ba97c <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x1ba91c mov r7, r4 */
/* @0x1ba920 b 0x1ba930 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x1ba924 ldr r1, [r1, #0x68] */
/* @0x1ba928 cmp r1, #0 */
/* @0x1ba92c beq 0x1ba97c <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x1ba930 ldr r3, [r1, #0x4] */
/* @0x1ba934 cmp r3, r5 */
/* @0x1ba938 bne 0x1ba924 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1ba93c vldr s15, [r1] */
/* @0x1ba940 vcvt.f64.s32 d7, s15 */
/* @0x1ba944 ldr r3, [r6] */
/* @0x1ba948 lsl r12, r4, #4 */
/* @0x1ba94c ldr r8, [r3, #0x4] */
/* @0x1ba950 vmov r2, r3, d7 */
/* @0x1ba954 ldr r8, [r8, #0x4] */
/* @0x1ba958 mov r0, r8 */
/* @0x1ba95c add r8, r8, r12 */
/* @0x1ba960 str r7, [r8, #0xc] */
/* @0x1ba964 str r2, [r0, r4, lsl #4] */
/* @0x1ba968 add r4, r4, #1 */
/* @0x1ba96c str r3, [r8, #0x4] */
/* @0x1ba970 ldr r1, [r1, #0x68] */
/* @0x1ba974 cmp r1, #0 */
/* @0x1ba978 bne 0x1ba930 <_Z19F_LayerGetIdAtDepthR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x1ba97c add sp, sp, #4 */
/* @0x1ba980 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ba984 andseq r2, r9, r8, lsl #30 */
/* @0x1ba988 andseq r2, r9, r8, lsr #29 */

/* ── FUNC 0x1ba98c · F_LayerGetAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=328 · insn=82 */
/* @0x1ba98c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1ba990 subs r4, r3, #0 */
/* @0x1ba994 mov r2, #0 */
/* @0x1ba998 mov r5, r0 */
/* @0x1ba99c mov r1, r2 */
/* @0x1ba9a0 movt r2, #0xbff0 */
/* @0x1ba9a4 str r1, [r0, #0xc] */
/* @0x1ba9a8 stm r0, {r1, r2} */
/* @0x1ba9ac bne 0x1baab0 <_Z13F_LayerGetAllR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1ba9b0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1ba9b4 subs r8, r0, #0 */
/* @0x1ba9b8 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1ba9bc ldr r2, [r8, #0xd4] */
/* @0x1ba9c0 cmp r2, #0 */
/* @0x1ba9c4 beq 0x1baac0 <_Z13F_LayerGetAllR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1ba9c8 ldrb r1, [r2, #0x19] */
/* @0x1ba9cc ldr r2, [r2, #0x68] */
/* @0x1ba9d0 cmp r1, #0 */
/* @0x1ba9d4 addeq r4, r4, #1 */
/* @0x1ba9d8 cmp r2, #0 */
/* @0x1ba9dc bne 0x1ba9c8 <_Z13F_LayerGetAllR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1ba9e0 lsl r10, r4, #4 */
/* @0x1ba9e4 mov r3, #2 */
/* @0x1ba9e8 mov r0, r5 */
/* @0x1ba9ec str r3, [r5, #0xc] */
/* @0x1ba9f0 mov r7, #1 */
/* @0x1ba9f4 bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x1ba9f8 ldr r9, [pc, #0xcc] */
/* @0x1ba9fc mov r3, r7 */
/* @0x1baa00 movw r2, #0x1483 */
/* @0x1baa04 add r9, pc, r9 */
/* @0x1baa08 mov r1, r9 */
/* @0x1baa0c mov r6, r0 */
/* @0x1baa10 str r0, [r5] */
/* @0x1baa14 str r7, [r0, #0x10] */
/* @0x1baa18 mov r0, #8 */
/* @0x1baa1c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1baa20 mov r1, r9 */
/* @0x1baa24 mov r3, r7 */
/* @0x1baa28 movw r2, #0x1484 */
/* @0x1baa2c str r0, [r6, #0x4] */
/* @0x1baa30 mov r0, r10 */
/* @0x1baa34 ldr r12, [r5] */
/* @0x1baa38 ldr r6, [r12, #0x4] */
/* @0x1baa3c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1baa40 ldr r1, [r8, #0xd4] */
/* @0x1baa44 cmp r1, #0 */
/* @0x1baa48 str r0, [r6, #0x4] */
/* @0x1baa4c ldr r3, [r5] */
/* @0x1baa50 ldr r3, [r3, #0x4] */
/* @0x1baa54 str r4, [r3] */
/* @0x1baa58 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1baa5c mov r12, #0 */
/* @0x1baa60 ldrb r4, [r1, #0x19] */
/* @0x1baa64 lsl r0, r12, #4 */
/* @0x1baa68 cmp r4, #0 */
/* @0x1baa6c bne 0x1baaa0 <_Z13F_LayerGetAllR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x1baa70 vldr s15, [r1] */
/* @0x1baa74 vcvt.f64.s32 d7, s15 */
/* @0x1baa78 ldr r3, [r5] */
/* @0x1baa7c ldr r7, [r3, #0x4] */
/* @0x1baa80 vmov r2, r3, d7 */
/* @0x1baa84 ldr r7, [r7, #0x4] */
/* @0x1baa88 mov r6, r7 */
/* @0x1baa8c add r7, r7, r0 */
/* @0x1baa90 str r4, [r7, #0xc] */
/* @0x1baa94 str r2, [r6, r12, lsl #4] */
/* @0x1baa98 add r12, r12, #1 */
/* @0x1baa9c str r3, [r7, #0x4] */
/* @0x1baaa0 ldr r1, [r1, #0x68] */
/* @0x1baaa4 cmp r1, #0 */
/* @0x1baaa8 bne 0x1baa60 <_Z13F_LayerGetAllR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x1baaac pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1baab0 ldr r0, [pc, #0x18] */
/* @0x1baab4 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1baab8 add r0, pc, r0 */
/* @0x1baabc b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1baac0 mov r10, r2 */
/* @0x1baac4 mov r4, r2 */
/* @0x1baac8 b 0x1ba9e4 <_Z13F_LayerGetAllR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x1baacc andseq r2, r9, r8, ror #26 */
/* @0x1baad0 andseq r2, r9, r8, ror #25 */

/* ── FUNC 0x1baad4 · F_LayerGetDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x1baad4 cmp r3, #1 */
/* @0x1baad8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1baadc mov r3, #0 */
/* @0x1baae0 mov r5, r3 */
/* @0x1baae4 mov r4, r0 */
/* @0x1baae8 movt r3, #0xbff0 */
/* @0x1baaec str r5, [r0, #0xc] */
/* @0x1baaf0 str r3, [r0, #0x4] */
/* @0x1baaf4 str r5, [r0] */
/* @0x1baaf8 ldr r6, [sp, #0x18] */
/* @0x1baafc beq 0x1bab14 <_Z15F_LayerGetDepthR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1bab00 ldr r0, [pc, #0x94] */
/* @0x1bab04 mov r1, r5 */
/* @0x1bab08 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bab0c add r0, pc, r0 */
/* @0x1bab10 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bab14 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bab18 ldr r3, [r6, #0xc] */
/* @0x1bab1c mov r1, r5 */
/* @0x1bab20 bic r3, r3, #-16777216 */
/* @0x1bab24 cmp r3, #1 */
/* @0x1bab28 mov r7, r0 */
/* @0x1bab2c mov r0, r6 */
/* @0x1bab30 beq 0x1bab64 <_Z15F_LayerGetDepthR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1bab34 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bab38 mov r1, r0 */
/* @0x1bab3c mov r0, r7 */
/* @0x1bab40 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bab44 cmp r0, #0 */
/* @0x1bab48 beq 0x1bab78 <_Z15F_LayerGetDepthR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x1bab4c ldr r2, [r0, #0x4] */
/* @0x1bab50 vmov s15, r2 */
/* @0x1bab54 vcvt.f64.s32 d7, s15 */
/* @0x1bab58 vmov r2, r3, d7 */
/* @0x1bab5c stm r4, {r2, r3} */
/* @0x1bab60 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bab64 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bab68 mov r1, r0 */
/* @0x1bab6c mov r0, r7 */
/* @0x1bab70 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bab74 b 0x1bab44 <_Z15F_LayerGetDepthR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1bab78 ldr r3, [pc, #0x20] */
/* @0x1bab7c ldr r1, [pc, #0x20] */
/* @0x1bab80 ldr r3, [pc, r3] */
/* @0x1bab84 add r1, pc, r1 */
/* @0x1bab88 ldr r0, [r3] */
/* @0x1bab8c ldr r3, [r0] */
/* @0x1bab90 ldr r3, [r3, #0xc] */
/* @0x1bab94 blx r3 */
/* @0x1bab98 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bab9c andseq r2, r9, r4, asr #25 */
/* @0x1baba0 mlaeq r3, r4, r11, r2 */
/* @0x1baba4 andseq r2, r9, r12, ror r12 */

/* ── FUNC 0x1baba8 · F_LayerHasInstance(RValue&, CInstance*, CInstance*, int, RValue*) · size=556 · insn=139 */
/* @0x1baba8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1babac cmp r3, #2 */
/* @0x1babb0 ldr r6, [pc, #0x200] */
/* @0x1babb4 mov r3, #0 */
/* @0x1babb8 mov r4, r3 */
/* @0x1babbc mov r5, r0 */
/* @0x1babc0 movt r3, #0xbff0 */
/* @0x1babc4 add r6, pc, r6 */
/* @0x1babc8 str r4, [r0, #0xc] */
/* @0x1babcc str r3, [r0, #0x4] */
/* @0x1babd0 str r4, [r0] */
/* @0x1babd4 ldr r7, [sp, #0x18] */
/* @0x1babd8 beq 0x1babf0 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1babdc ldr r0, [pc, #0x1d8] */
/* @0x1babe0 mov r1, r4 */
/* @0x1babe4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1babe8 add r0, pc, r0 */
/* @0x1babec b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1babf0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1babf4 ldr r3, [r7, #0xc] */
/* @0x1babf8 mov r1, r4 */
/* @0x1babfc bic r3, r3, #-16777216 */
/* @0x1bac00 cmp r3, #1 */
/* @0x1bac04 mov r8, r0 */
/* @0x1bac08 mov r0, r7 */
/* @0x1bac0c beq 0x1bad04 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x1bac10 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bac14 mov r1, r0 */
/* @0x1bac18 mov r0, r8 */
/* @0x1bac1c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bac20 mov r4, r0 */
/* @0x1bac24 ldr r1, [pc, #0x194] */
/* @0x1bac28 cmp r4, #0 */
/* @0x1bac2c ldr r3, [pc, #0x190] */
/* @0x1bac30 mov r2, r4 */
/* @0x1bac34 add r1, pc, r1 */
/* @0x1bac38 beq 0x1bad74 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x1bac3c mov r0, r7 */
/* @0x1bac40 mov r1, #1 */
/* @0x1bac44 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bac48 movw r3, #0x869f */
/* @0x1bac4c movt r3, #0x1 */
/* @0x1bac50 cmp r0, r3 */
/* @0x1bac54 mov r7, r0 */
/* @0x1bac58 bgt 0x1bad1c <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x1bac5c ldr r4, [r4, #0x58] */
/* @0x1bac60 cmp r4, #0 */
/* @0x1bac64 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1bac68 ldr r3, [r4] */
/* @0x1bac6c cmp r3, #2 */
/* @0x1bac70 beq 0x1bac84 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x1bac74 ldr r4, [r4, #0x14] */
/* @0x1bac78 cmp r4, #0 */
/* @0x1bac7c bne 0x1bac68 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x1bac80 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1bac84 ldr r3, [r4, #0x20] */
/* @0x1bac88 ldr r12, [r3, #0x7c] */
/* @0x1bac8c cmp r7, r12 */
/* @0x1bac90 beq 0x1bace8 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1bac94 ldr r3, [pc, #0x12c] */
/* @0x1bac98 ldr r3, [r6, r3] */
/* @0x1bac9c ldr r3, [r3] */
/* @0x1baca0 ldr r2, [r3, #0x4] */
/* @0x1baca4 ldr r3, [r3] */
/* @0x1baca8 and r2, r12, r2 */
/* @0x1bacac ldr r3, [r3, r2, lsl #3] */
/* @0x1bacb0 cmp r3, #0 */
/* @0x1bacb4 bne 0x1bacc8 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x1bacb8 b 0x1bacfc <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x1bacbc ldr r3, [r3, #0x4] */
/* @0x1bacc0 cmp r3, #0 */
/* @0x1bacc4 beq 0x1bacfc <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x1bacc8 ldr r2, [r3, #0x8] */
/* @0x1baccc cmp r12, r2 */
/* @0x1bacd0 bne 0x1bacbc <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x1bacd4 ldr r0, [r3, #0xc] */
/* @0x1bacd8 mov r1, r7 */
/* @0x1bacdc bl 0x19ddb0 <_ZN9CObjectGM13IsDecendentOfEi> */
/* @0x1bace0 cmp r0, #0 */
/* @0x1bace4 beq 0x1bac74 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x1bace8 mov r3, #0 */
/* @0x1bacec mov r2, r3 */
/* @0x1bacf0 movt r3, #0x3ff0 */
/* @0x1bacf4 stm r5, {r2, r3} */
/* @0x1bacf8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1bacfc mov r0, r3 */
/* @0x1bad00 b 0x1bacd8 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x1bad04 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bad08 mov r1, r0 */
/* @0x1bad0c mov r0, r8 */
/* @0x1bad10 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bad14 mov r4, r0 */
/* @0x1bad18 b 0x1bac24 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x1bad1c ldr r3, [pc, #0xa8] */
/* @0x1bad20 ldr r3, [r6, r3] */
/* @0x1bad24 ldr r2, [r3, #0x4] */
/* @0x1bad28 ldr r3, [r3] */
/* @0x1bad2c and r2, r0, r2 */
/* @0x1bad30 ldr r3, [r3, r2, lsl #3] */
/* @0x1bad34 cmp r3, #0 */
/* @0x1bad38 beq 0x1bad64 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x1bad3c ldr r2, [r3, #0x8] */
/* @0x1bad40 cmp r0, r2 */
/* @0x1bad44 bne 0x1bad58 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x1bad48 b 0x1bad8c <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x1bad4c ldr r1, [r3, #0x8] */
/* @0x1bad50 cmp r7, r1 */
/* @0x1bad54 beq 0x1bad8c <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x1bad58 ldr r3, [r3, #0x4] */
/* @0x1bad5c cmp r3, #0 */
/* @0x1bad60 bne 0x1bad4c <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x1bad64 ldr r1, [pc, #0x64] */
/* @0x1bad68 mov r2, #0 */
/* @0x1bad6c ldr r3, [pc, #0x50] */
/* @0x1bad70 add r1, pc, r1 */
/* @0x1bad74 ldr r3, [r6, r3] */
/* @0x1bad78 ldr r0, [r3] */
/* @0x1bad7c ldr r3, [r0] */
/* @0x1bad80 ldr r3, [r3, #0xc] */
/* @0x1bad84 blx r3 */
/* @0x1bad88 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1bad8c ldr r3, [r3, #0xc] */
/* @0x1bad90 cmp r3, #0 */
/* @0x1bad94 beq 0x1bad64 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x1bad98 ldrb r2, [r3, #0x174] */
/* @0x1bad9c cmp r2, #0 */
/* @0x1bada0 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1bada4 ldr r2, [r3, #0x170] */
/* @0x1bada8 ldr r3, [r4] */
/* @0x1badac cmp r2, r3 */
/* @0x1badb0 popne {r4, r5, r6, r7, r8, pc} */
/* @0x1badb4 b 0x1bace8 <_Z18F_LayerHasInstanceR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1badb8 eoreq r7, r3, r12, lsl #1 */
/* @0x1badbc andseq r2, r9, r0, asr r12 */
/* @0x1badc0 andseq r2, r9, r8, lsr r12 */
/* @0x1badc4 .word 0xffffbac4 */
/* @0x1badc8 .word 0xffffbfec */
/* @0x1badcc .word 0xffffbff4 */
/* @0x1badd0 andseq r2, r9, r4, asr #22 */

/* ── FUNC 0x1badd4 · F_LayerSetVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0x1badd4 cmp r3, #2 */
/* @0x1badd8 mov r3, #0 */
/* @0x1baddc push {r4, r5, r6, lr} */
/* @0x1bade0 mov r4, r3 */
/* @0x1bade4 ldr r5, [sp, #0x10] */
/* @0x1bade8 movt r3, #0xbff0 */
/* @0x1badec str r4, [r0, #0xc] */
/* @0x1badf0 str r3, [r0, #0x4] */
/* @0x1badf4 str r4, [r0] */
/* @0x1badf8 beq 0x1bae10 <_Z17F_LayerSetVisibleR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1badfc ldr r0, [pc, #0x9c] */
/* @0x1bae00 mov r1, r4 */
/* @0x1bae04 pop {r4, r5, r6, lr} */
/* @0x1bae08 add r0, pc, r0 */
/* @0x1bae0c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bae10 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bae14 ldr r3, [r5, #0xc] */
/* @0x1bae18 mov r1, r4 */
/* @0x1bae1c bic r3, r3, #-16777216 */
/* @0x1bae20 cmp r3, #1 */
/* @0x1bae24 mov r6, r0 */
/* @0x1bae28 mov r0, r5 */
/* @0x1bae2c beq 0x1bae60 <_Z17F_LayerSetVisibleR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1bae30 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bae34 mov r1, r0 */
/* @0x1bae38 mov r0, r6 */
/* @0x1bae3c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bae40 mov r4, r0 */
/* @0x1bae44 cmp r4, #0 */
/* @0x1bae48 beq 0x1bae78 <_Z17F_LayerSetVisibleR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x1bae4c mov r0, r5 */
/* @0x1bae50 mov r1, #1 */
/* @0x1bae54 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1bae58 strb r0, [r4, #0x18] */
/* @0x1bae5c pop {r4, r5, r6, pc} */
/* @0x1bae60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bae64 mov r1, r0 */
/* @0x1bae68 mov r0, r6 */
/* @0x1bae6c bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bae70 mov r4, r0 */
/* @0x1bae74 b 0x1bae44 <_Z17F_LayerSetVisibleR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1bae78 ldr r3, [pc, #0x24] */
/* @0x1bae7c mov r2, r4 */
/* @0x1bae80 ldr r1, [pc, #0x20] */
/* @0x1bae84 ldr r3, [pc, r3] */
/* @0x1bae88 add r1, pc, r1 */
/* @0x1bae8c ldr r0, [r3] */
/* @0x1bae90 ldr r3, [r0] */
/* @0x1bae94 ldr r3, [r3, #0xc] */
/* @0x1bae98 blx r3 */
/* @0x1bae9c pop {r4, r5, r6, pc} */
/* @0x1baea0 andseq r2, r9, r8, ror #21 */
/* @0x1baea4 mlaeq r3, r0, r8, r2 */
/* @0x1baea8 mulseq r9, r8, r10 */

/* ── FUNC 0x1baeac · F_LayerGetVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x1baeac cmp r3, #1 */
/* @0x1baeb0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1baeb4 mov r4, #0 */
/* @0x1baeb8 mov r5, r0 */
/* @0x1baebc ldr r6, [sp, #0x18] */
/* @0x1baec0 str r4, [r0, #0xc] */
/* @0x1baec4 str r4, [r0] */
/* @0x1baec8 str r4, [r0, #0x4] */
/* @0x1baecc beq 0x1baee4 <_Z17F_LayerGetVisibleR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1baed0 ldr r0, [pc, #0xa4] */
/* @0x1baed4 mov r1, r4 */
/* @0x1baed8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1baedc add r0, pc, r0 */
/* @0x1baee0 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1baee4 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1baee8 ldr r3, [r6, #0xc] */
/* @0x1baeec mov r1, r4 */
/* @0x1baef0 bic r3, r3, #-16777216 */
/* @0x1baef4 cmp r3, #1 */
/* @0x1baef8 mov r7, r0 */
/* @0x1baefc mov r0, r6 */
/* @0x1baf00 beq 0x1baf40 <_Z17F_LayerGetVisibleR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x1baf04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1baf08 mov r1, r0 */
/* @0x1baf0c mov r0, r7 */
/* @0x1baf10 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1baf14 cmp r0, #0 */
/* @0x1baf18 beq 0x1baf54 <_Z17F_LayerGetVisibleR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x1baf1c ldrb r3, [r0, #0x18] */
/* @0x1baf20 cmp r3, #0 */
/* @0x1baf24 movne r2, #0 */
/* @0x1baf28 moveq r2, r3 */
/* @0x1baf2c movne r3, r2 */
/* @0x1baf30 movtne r2, #0x3ff0 */
/* @0x1baf34 str r3, [r5] */
/* @0x1baf38 str r2, [r5, #0x4] */
/* @0x1baf3c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1baf40 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1baf44 mov r1, r0 */
/* @0x1baf48 mov r0, r7 */
/* @0x1baf4c bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1baf50 b 0x1baf14 <_Z17F_LayerGetVisibleR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x1baf54 ldr r3, [pc, #0x24] */
/* @0x1baf58 mov r2, r0 */
/* @0x1baf5c ldr r1, [pc, #0x20] */
/* @0x1baf60 ldr r3, [pc, r3] */
/* @0x1baf64 add r1, pc, r1 */
/* @0x1baf68 ldr r0, [r3] */
/* @0x1baf6c ldr r3, [r0] */
/* @0x1baf70 ldr r3, [r3, #0xc] */
/* @0x1baf74 blx r3 */
/* @0x1baf78 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1baf7c andseq r2, r9, r12, lsl #21 */
/* @0x1baf80 .word 0x002327b4 */
/* @0x1baf84 andseq r2, r9, r4, lsr r10 */

/* ── FUNC 0x1baf88 · F_LayerExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x1baf88 cmp r3, #1 */
/* @0x1baf8c push {r3, r4, r5, r6, r7, lr} */
/* @0x1baf90 mov r4, #0 */
/* @0x1baf94 mov r5, r0 */
/* @0x1baf98 ldr r6, [sp, #0x18] */
/* @0x1baf9c str r4, [r0, #0xc] */
/* @0x1bafa0 str r4, [r0] */
/* @0x1bafa4 str r4, [r0, #0x4] */
/* @0x1bafa8 beq 0x1bafc0 <_Z13F_LayerExistsR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1bafac ldr r0, [pc, #0x70] */
/* @0x1bafb0 mov r1, r4 */
/* @0x1bafb4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bafb8 add r0, pc, r0 */
/* @0x1bafbc b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bafc0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bafc4 ldr r3, [r6, #0xc] */
/* @0x1bafc8 mov r1, r4 */
/* @0x1bafcc bic r3, r3, #-16777216 */
/* @0x1bafd0 cmp r3, #1 */
/* @0x1bafd4 mov r7, r0 */
/* @0x1bafd8 mov r0, r6 */
/* @0x1bafdc beq 0x1bb010 <_Z13F_LayerExistsR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1bafe0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bafe4 mov r1, r0 */
/* @0x1bafe8 mov r0, r7 */
/* @0x1bafec bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1baff0 cmp r0, #0 */
/* @0x1baff4 streq r0, [r5] */
/* @0x1baff8 streq r0, [r5, #0x4] */
/* @0x1baffc movne r3, #0 */
/* @0x1bb000 movne r2, r3 */
/* @0x1bb004 movtne r3, #0x3ff0 */
/* @0x1bb008 stmne r5, {r2, r3} */
/* @0x1bb00c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb010 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb014 mov r1, r0 */
/* @0x1bb018 mov r0, r7 */
/* @0x1bb01c bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb020 b 0x1baff0 <_Z13F_LayerExistsR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x1bb024 andseq r2, r9, r8, lsr #20 */

/* ── FUNC 0x1bb028 · F_LayerX(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1bb028 cmp r3, #2 */
/* @0x1bb02c mov r3, #0 */
/* @0x1bb030 push {r4, r5, r6, lr} */
/* @0x1bb034 mov r4, r3 */
/* @0x1bb038 ldr r5, [sp, #0x10] */
/* @0x1bb03c movt r3, #0xbff0 */
/* @0x1bb040 str r4, [r0, #0xc] */
/* @0x1bb044 str r3, [r0, #0x4] */
/* @0x1bb048 str r4, [r0] */
/* @0x1bb04c beq 0x1bb064 <_Z8F_LayerXR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bb050 ldr r0, [pc, #0x7c] */
/* @0x1bb054 mov r1, r4 */
/* @0x1bb058 pop {r4, r5, r6, lr} */
/* @0x1bb05c add r0, pc, r0 */
/* @0x1bb060 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb064 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb068 ldr r3, [r5, #0xc] */
/* @0x1bb06c mov r1, r4 */
/* @0x1bb070 bic r3, r3, #-16777216 */
/* @0x1bb074 cmp r3, #1 */
/* @0x1bb078 mov r6, r0 */
/* @0x1bb07c mov r0, r5 */
/* @0x1bb080 beq 0x1bb0b4 <_Z8F_LayerXR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1bb084 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb088 mov r1, r0 */
/* @0x1bb08c mov r0, r6 */
/* @0x1bb090 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb094 mov r4, r0 */
/* @0x1bb098 cmp r4, #0 */
/* @0x1bb09c popeq {r4, r5, r6, pc} */
/* @0x1bb0a0 mov r0, r5 */
/* @0x1bb0a4 mov r1, #1 */
/* @0x1bb0a8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bb0ac str r0, [r4, #0x8] */
/* @0x1bb0b0 pop {r4, r5, r6, pc} */
/* @0x1bb0b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb0b8 mov r1, r0 */
/* @0x1bb0bc mov r0, r6 */
/* @0x1bb0c0 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb0c4 mov r4, r0 */
/* @0x1bb0c8 cmp r4, #0 */
/* @0x1bb0cc bne 0x1bb0a0 <_Z8F_LayerXR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1bb0d0 pop {r4, r5, r6, pc} */
/* @0x1bb0d4 ldrheq r2, [r9], -r0 */

/* ── FUNC 0x1bb0d8 · F_LayerY(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1bb0d8 cmp r3, #2 */
/* @0x1bb0dc mov r3, #0 */
/* @0x1bb0e0 push {r4, r5, r6, lr} */
/* @0x1bb0e4 mov r4, r3 */
/* @0x1bb0e8 ldr r5, [sp, #0x10] */
/* @0x1bb0ec movt r3, #0xbff0 */
/* @0x1bb0f0 str r4, [r0, #0xc] */
/* @0x1bb0f4 str r3, [r0, #0x4] */
/* @0x1bb0f8 str r4, [r0] */
/* @0x1bb0fc beq 0x1bb114 <_Z8F_LayerYR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bb100 ldr r0, [pc, #0x7c] */
/* @0x1bb104 mov r1, r4 */
/* @0x1bb108 pop {r4, r5, r6, lr} */
/* @0x1bb10c add r0, pc, r0 */
/* @0x1bb110 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb114 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb118 ldr r3, [r5, #0xc] */
/* @0x1bb11c mov r1, r4 */
/* @0x1bb120 bic r3, r3, #-16777216 */
/* @0x1bb124 cmp r3, #1 */
/* @0x1bb128 mov r6, r0 */
/* @0x1bb12c mov r0, r5 */
/* @0x1bb130 beq 0x1bb164 <_Z8F_LayerYR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1bb134 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb138 mov r1, r0 */
/* @0x1bb13c mov r0, r6 */
/* @0x1bb140 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb144 mov r4, r0 */
/* @0x1bb148 cmp r4, #0 */
/* @0x1bb14c popeq {r4, r5, r6, pc} */
/* @0x1bb150 mov r0, r5 */
/* @0x1bb154 mov r1, #1 */
/* @0x1bb158 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bb15c str r0, [r4, #0xc] */
/* @0x1bb160 pop {r4, r5, r6, pc} */
/* @0x1bb164 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb168 mov r1, r0 */
/* @0x1bb16c mov r0, r6 */
/* @0x1bb170 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb174 mov r4, r0 */
/* @0x1bb178 cmp r4, #0 */
/* @0x1bb17c bne 0x1bb150 <_Z8F_LayerYR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1bb180 pop {r4, r5, r6, pc} */
/* @0x1bb184 andseq r2, r9, r8, lsr #18 */

/* ── FUNC 0x1bb188 · F_LayerGetX(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x1bb188 cmp r3, #1 */
/* @0x1bb18c push {r3, r4, r5, r6, r7, lr} */
/* @0x1bb190 mov r4, #0 */
/* @0x1bb194 mov r5, r0 */
/* @0x1bb198 ldr r6, [sp, #0x18] */
/* @0x1bb19c str r4, [r0, #0xc] */
/* @0x1bb1a0 str r4, [r0] */
/* @0x1bb1a4 str r4, [r0, #0x4] */
/* @0x1bb1a8 beq 0x1bb1c0 <_Z11F_LayerGetXR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1bb1ac ldr r0, [pc, #0x74] */
/* @0x1bb1b0 mov r1, r4 */
/* @0x1bb1b4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bb1b8 add r0, pc, r0 */
/* @0x1bb1bc b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb1c0 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb1c4 ldr r3, [r6, #0xc] */
/* @0x1bb1c8 mov r1, r4 */
/* @0x1bb1cc bic r3, r3, #-16777216 */
/* @0x1bb1d0 cmp r3, #1 */
/* @0x1bb1d4 mov r7, r0 */
/* @0x1bb1d8 mov r0, r6 */
/* @0x1bb1dc beq 0x1bb20c <_Z11F_LayerGetXR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1bb1e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb1e4 mov r1, r0 */
/* @0x1bb1e8 mov r0, r7 */
/* @0x1bb1ec bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb1f0 cmp r0, #0 */
/* @0x1bb1f4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bb1f8 vldr s15, [r0, #8] */
/* @0x1bb1fc vcvt.f64.f32 d6, s15 */
/* @0x1bb200 vmov r2, r3, d6 */
/* @0x1bb204 stm r5, {r2, r3} */
/* @0x1bb208 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb20c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb210 mov r1, r0 */
/* @0x1bb214 mov r0, r7 */
/* @0x1bb218 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb21c cmp r0, #0 */
/* @0x1bb220 bne 0x1bb1f8 <_Z11F_LayerGetXR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1bb224 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb228 andseq r2, r9, r4, lsr #17 */

/* ── FUNC 0x1bb22c · F_LayerGetY(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x1bb22c cmp r3, #1 */
/* @0x1bb230 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bb234 mov r4, #0 */
/* @0x1bb238 mov r5, r0 */
/* @0x1bb23c ldr r6, [sp, #0x18] */
/* @0x1bb240 str r4, [r0, #0xc] */
/* @0x1bb244 str r4, [r0] */
/* @0x1bb248 str r4, [r0, #0x4] */
/* @0x1bb24c beq 0x1bb264 <_Z11F_LayerGetYR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1bb250 ldr r0, [pc, #0x74] */
/* @0x1bb254 mov r1, r4 */
/* @0x1bb258 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bb25c add r0, pc, r0 */
/* @0x1bb260 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb264 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb268 ldr r3, [r6, #0xc] */
/* @0x1bb26c mov r1, r4 */
/* @0x1bb270 bic r3, r3, #-16777216 */
/* @0x1bb274 cmp r3, #1 */
/* @0x1bb278 mov r7, r0 */
/* @0x1bb27c mov r0, r6 */
/* @0x1bb280 beq 0x1bb2b0 <_Z11F_LayerGetYR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1bb284 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb288 mov r1, r0 */
/* @0x1bb28c mov r0, r7 */
/* @0x1bb290 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb294 cmp r0, #0 */
/* @0x1bb298 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bb29c vldr s15, [r0, #12] */
/* @0x1bb2a0 vcvt.f64.f32 d6, s15 */
/* @0x1bb2a4 vmov r2, r3, d6 */
/* @0x1bb2a8 stm r5, {r2, r3} */
/* @0x1bb2ac pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb2b0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb2b4 mov r1, r0 */
/* @0x1bb2b8 mov r0, r7 */
/* @0x1bb2bc bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb2c0 cmp r0, #0 */
/* @0x1bb2c4 bne 0x1bb29c <_Z11F_LayerGetYR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1bb2c8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb2cc andseq r2, r9, r12, lsr #16 */

/* ── FUNC 0x1bb2d0 · F_LayerHspeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1bb2d0 cmp r3, #2 */
/* @0x1bb2d4 mov r3, #0 */
/* @0x1bb2d8 push {r4, r5, r6, lr} */
/* @0x1bb2dc mov r4, r3 */
/* @0x1bb2e0 ldr r5, [sp, #0x10] */
/* @0x1bb2e4 movt r3, #0xbff0 */
/* @0x1bb2e8 str r4, [r0, #0xc] */
/* @0x1bb2ec str r3, [r0, #0x4] */
/* @0x1bb2f0 str r4, [r0] */
/* @0x1bb2f4 beq 0x1bb30c <_Z13F_LayerHspeedR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bb2f8 ldr r0, [pc, #0x7c] */
/* @0x1bb2fc mov r1, r4 */
/* @0x1bb300 pop {r4, r5, r6, lr} */
/* @0x1bb304 add r0, pc, r0 */
/* @0x1bb308 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb30c bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb310 ldr r3, [r5, #0xc] */
/* @0x1bb314 mov r1, r4 */
/* @0x1bb318 bic r3, r3, #-16777216 */
/* @0x1bb31c cmp r3, #1 */
/* @0x1bb320 mov r6, r0 */
/* @0x1bb324 mov r0, r5 */
/* @0x1bb328 beq 0x1bb35c <_Z13F_LayerHspeedR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1bb32c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb330 mov r1, r0 */
/* @0x1bb334 mov r0, r6 */
/* @0x1bb338 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb33c mov r4, r0 */
/* @0x1bb340 cmp r4, #0 */
/* @0x1bb344 popeq {r4, r5, r6, pc} */
/* @0x1bb348 mov r0, r5 */
/* @0x1bb34c mov r1, #1 */
/* @0x1bb350 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bb354 str r0, [r4, #0x10] */
/* @0x1bb358 pop {r4, r5, r6, pc} */
/* @0x1bb35c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb360 mov r1, r0 */
/* @0x1bb364 mov r0, r6 */
/* @0x1bb368 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb36c mov r4, r0 */
/* @0x1bb370 cmp r4, #0 */
/* @0x1bb374 bne 0x1bb348 <_Z13F_LayerHspeedR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1bb378 pop {r4, r5, r6, pc} */
/* @0x1bb37c ldrheq r2, [r9], -r0 */

/* ── FUNC 0x1bb380 · F_LayerVspeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=176 · insn=44 */
/* @0x1bb380 cmp r3, #2 */
/* @0x1bb384 mov r3, #0 */
/* @0x1bb388 push {r4, r5, r6, lr} */
/* @0x1bb38c mov r4, r3 */
/* @0x1bb390 ldr r5, [sp, #0x10] */
/* @0x1bb394 movt r3, #0xbff0 */
/* @0x1bb398 str r4, [r0, #0xc] */
/* @0x1bb39c str r3, [r0, #0x4] */
/* @0x1bb3a0 str r4, [r0] */
/* @0x1bb3a4 beq 0x1bb3bc <_Z13F_LayerVspeedR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x1bb3a8 ldr r0, [pc, #0x7c] */
/* @0x1bb3ac mov r1, r4 */
/* @0x1bb3b0 pop {r4, r5, r6, lr} */
/* @0x1bb3b4 add r0, pc, r0 */
/* @0x1bb3b8 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb3bc bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb3c0 ldr r3, [r5, #0xc] */
/* @0x1bb3c4 mov r1, r4 */
/* @0x1bb3c8 bic r3, r3, #-16777216 */
/* @0x1bb3cc cmp r3, #1 */
/* @0x1bb3d0 mov r6, r0 */
/* @0x1bb3d4 mov r0, r5 */
/* @0x1bb3d8 beq 0x1bb40c <_Z13F_LayerVspeedR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x1bb3dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb3e0 mov r1, r0 */
/* @0x1bb3e4 mov r0, r6 */
/* @0x1bb3e8 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb3ec mov r4, r0 */
/* @0x1bb3f0 cmp r4, #0 */
/* @0x1bb3f4 popeq {r4, r5, r6, pc} */
/* @0x1bb3f8 mov r0, r5 */
/* @0x1bb3fc mov r1, #1 */
/* @0x1bb400 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1bb404 str r0, [r4, #0x14] */
/* @0x1bb408 pop {r4, r5, r6, pc} */
/* @0x1bb40c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb410 mov r1, r0 */
/* @0x1bb414 mov r0, r6 */
/* @0x1bb418 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb41c mov r4, r0 */
/* @0x1bb420 cmp r4, #0 */
/* @0x1bb424 bne 0x1bb3f8 <_Z13F_LayerVspeedR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1bb428 pop {r4, r5, r6, pc} */
/* @0x1bb42c andseq r2, r9, r12, lsr #14 */

/* ── FUNC 0x1bb430 · F_LayerGetHspeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x1bb430 cmp r3, #1 */
/* @0x1bb434 push {r3, r4, r5, r6, r7, lr} */
/* @0x1bb438 mov r4, #0 */
/* @0x1bb43c mov r5, r0 */
/* @0x1bb440 ldr r6, [sp, #0x18] */
/* @0x1bb444 str r4, [r0, #0xc] */
/* @0x1bb448 str r4, [r0] */
/* @0x1bb44c str r4, [r0, #0x4] */
/* @0x1bb450 beq 0x1bb468 <_Z16F_LayerGetHspeedR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1bb454 ldr r0, [pc, #0x74] */
/* @0x1bb458 mov r1, r4 */
/* @0x1bb45c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1bb460 add r0, pc, r0 */
/* @0x1bb464 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1bb468 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv> */
/* @0x1bb46c ldr r3, [r6, #0xc] */
/* @0x1bb470 mov r1, r4 */
/* @0x1bb474 bic r3, r3, #-16777216 */
/* @0x1bb478 cmp r3, #1 */
/* @0x1bb47c mov r7, r0 */
/* @0x1bb480 mov r0, r6 */
/* @0x1bb484 beq 0x1bb4b4 <_Z16F_LayerGetHspeedR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1bb488 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1bb48c mov r1, r0 */
/* @0x1bb490 mov r0, r7 */
/* @0x1bb494 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1bb498 cmp r0, #0 */
/* @0x1bb49c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1bb4a0 vldr s15, [r0, #16] */
/* @0x1bb4a4 vcvt.f64.f32 d6, s15 */
/* @0x1bb4a8 vmov r2, r3, d6 */
/* @0x1bb4ac stm r5, {r2, r3} */
/* @0x1bb4b0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb4b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1bb4b8 mov r1, r0 */
/* @0x1bb4bc mov r0, r7 */
/* @0x1bb4c0 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1bb4c4 cmp r0, #0 */
/* @0x1bb4c8 bne 0x1bb4a0 <_Z16F_LayerGetHspeedR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x1bb4cc pop {r3, r4, r5, r6, r7, pc} */
/* @0x1bb4d0 andseq r2, r9, r12, lsr #13 */
