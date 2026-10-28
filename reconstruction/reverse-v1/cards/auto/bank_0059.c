/* libyoyo.so 覆盖卡组 0059
 * 函数 0x12aef8..0x12bfb8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x12aef8 · F_ObjectGetPhysics(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x12aef8 push {r4, lr} */
/* @0x12aefc mov r1, #0 */
/* @0x12af00 mov r4, r0 */
/* @0x12af04 ldr r0, [sp, #0x8] */
/* @0x12af08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12af0c ldr r3, [pc, #0x80] */
/* @0x12af10 ldr r3, [pc, r3] */
/* @0x12af14 ldr r3, [r3] */
/* @0x12af18 ldr r2, [r3, #0x4] */
/* @0x12af1c ldr r3, [r3] */
/* @0x12af20 and r2, r0, r2 */
/* @0x12af24 ldr r3, [r3, r2, lsl #3] */
/* @0x12af28 cmp r3, #0 */
/* @0x12af2c bne 0x12af40 <_Z18F_ObjectGetPhysicsR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12af30 b 0x12af7c <_Z18F_ObjectGetPhysicsR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x12af34 ldr r3, [r3, #0x4] */
/* @0x12af38 cmp r3, #0 */
/* @0x12af3c beq 0x12af7c <_Z18F_ObjectGetPhysicsR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x12af40 ldr r2, [r3, #0x8] */
/* @0x12af44 cmp r0, r2 */
/* @0x12af48 bne 0x12af34 <_Z18F_ObjectGetPhysicsR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12af4c ldr r3, [r3, #0xc] */
/* @0x12af50 cmp r3, #0 */
/* @0x12af54 beq 0x12af7c <_Z18F_ObjectGetPhysicsR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x12af58 ldrb r3, [r3, #0x1c] */
/* @0x12af5c mov r2, #0 */
/* @0x12af60 str r2, [r4, #0xc] */
/* @0x12af64 cmp r3, r2 */
/* @0x12af68 movne r3, #0 */
/* @0x12af6c movtne r3, #0x3ff0 */
/* @0x12af70 beq 0x12af84 <_Z18F_ObjectGetPhysicsR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x12af74 stm r4, {r2, r3} */
/* @0x12af78 pop {r4, pc} */
/* @0x12af7c mov r3, #0 */
/* @0x12af80 str r3, [r4, #0xc] */
/* @0x12af84 mov r2, #0 */
/* @0x12af88 mov r3, r2 */
/* @0x12af8c stm r4, {r2, r3} */
/* @0x12af90 pop {r4, pc} */
/* @0x12af94 eoreq r2, r12, r12, lsr #26 */

/* ── FUNC 0x12af98 · F_ObjectIsAncestor(RValue&, CInstance*, CInstance*, int, RValue*) · size=240 · insn=60 */
/* @0x12af98 push {r3, r4, r5, r6, r7, lr} */
/* @0x12af9c mov r1, #0 */
/* @0x12afa0 ldr r7, [sp, #0x18] */
/* @0x12afa4 mov r5, r0 */
/* @0x12afa8 ldr r6, [pc, #0xd4] */
/* @0x12afac mov r0, r7 */
/* @0x12afb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12afb4 ldr r6, [pc, r6] */
/* @0x12afb8 ldr r3, [r6] */
/* @0x12afbc ldr r2, [r3, #0x4] */
/* @0x12afc0 ldr r3, [r3] */
/* @0x12afc4 and r2, r0, r2 */
/* @0x12afc8 ldr r3, [r3, r2, lsl #3] */
/* @0x12afcc cmp r3, #0 */
/* @0x12afd0 bne 0x12afe4 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x12afd4 b 0x12b058 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x12afd8 ldr r3, [r3, #0x4] */
/* @0x12afdc cmp r3, #0 */
/* @0x12afe0 beq 0x12b058 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x12afe4 ldr r2, [r3, #0x8] */
/* @0x12afe8 cmp r0, r2 */
/* @0x12afec bne 0x12afd8 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x12aff0 ldr r4, [r3, #0xc] */
/* @0x12aff4 cmp r4, #0 */
/* @0x12aff8 beq 0x12b058 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x12affc mov r0, r7 */
/* @0x12b000 mov r1, #1 */
/* @0x12b004 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b008 ldr r12, [r6] */
/* @0x12b00c ldr r1, [r4, #0xc] */
/* @0x12b010 cmp r0, r1 */
/* @0x12b014 beq 0x12b070 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x12b018 ldr r2, [r12, #0x4] */
/* @0x12b01c ldr r3, [r12] */
/* @0x12b020 and r2, r1, r2 */
/* @0x12b024 ldr r3, [r3, r2, lsl #3] */
/* @0x12b028 cmp r3, #0 */
/* @0x12b02c bne 0x12b040 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x12b030 b 0x12b058 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x12b034 ldr r3, [r3, #0x4] */
/* @0x12b038 cmp r3, #0 */
/* @0x12b03c beq 0x12b058 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x12b040 ldr r2, [r3, #0x8] */
/* @0x12b044 cmp r1, r2 */
/* @0x12b048 bne 0x12b034 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x12b04c ldr r4, [r3, #0xc] */
/* @0x12b050 cmp r4, #0 */
/* @0x12b054 bne 0x12b00c <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12b058 mov r3, #0 */
/* @0x12b05c str r3, [r5, #0xc] */
/* @0x12b060 mov r2, r3 */
/* @0x12b064 str r3, [r5] */
/* @0x12b068 str r2, [r5, #0x4] */
/* @0x12b06c pop {r3, r4, r5, r6, r7, pc} */
/* @0x12b070 mov r3, #0 */
/* @0x12b074 str r3, [r5, #0xc] */
/* @0x12b078 mov r2, r3 */
/* @0x12b07c movt r2, #0x3ff0 */
/* @0x12b080 b 0x12b064 <_Z18F_ObjectIsAncestorR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x12b084 eoreq r2, r12, r8, lsl #25 */

/* ── FUNC 0x12b088 · F_ObjectSetSprite(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x12b088 push {r3, r4, r5, lr} */
/* @0x12b08c mov r1, #0 */
/* @0x12b090 ldr r4, [sp, #0x10] */
/* @0x12b094 mov r0, r4 */
/* @0x12b098 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b09c ldr r3, [pc, #0x5c] */
/* @0x12b0a0 ldr r3, [pc, r3] */
/* @0x12b0a4 ldr r3, [r3] */
/* @0x12b0a8 ldr r2, [r3, #0x4] */
/* @0x12b0ac ldr r3, [r3] */
/* @0x12b0b0 and r2, r0, r2 */
/* @0x12b0b4 ldr r3, [r3, r2, lsl #3] */
/* @0x12b0b8 cmp r3, #0 */
/* @0x12b0bc bne 0x12b0d0 <_Z17F_ObjectSetSpriteR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12b0c0 pop {r3, r4, r5, pc} */
/* @0x12b0c4 ldr r3, [r3, #0x4] */
/* @0x12b0c8 cmp r3, #0 */
/* @0x12b0cc beq 0x12b0fc <_Z17F_ObjectSetSpriteR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12b0d0 ldr r2, [r3, #0x8] */
/* @0x12b0d4 cmp r0, r2 */
/* @0x12b0d8 bne 0x12b0c4 <_Z17F_ObjectSetSpriteR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12b0dc ldr r5, [r3, #0xc] */
/* @0x12b0e0 cmp r5, #0 */
/* @0x12b0e4 popeq {r3, r4, r5, pc} */
/* @0x12b0e8 mov r0, r4 */
/* @0x12b0ec mov r1, #1 */
/* @0x12b0f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b0f4 str r0, [r5, #0x4] */
/* @0x12b0f8 pop {r3, r4, r5, pc} */
/* @0x12b0fc pop {r3, r4, r5, pc} */
/* @0x12b100 mlaeq r12, r12, r11, r2 */

/* ── FUNC 0x12b104 · F_ObjectSetDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x12b104 push {r3, r4, r5, lr} */
/* @0x12b108 mov r1, #0 */
/* @0x12b10c ldr r4, [sp, #0x10] */
/* @0x12b110 mov r0, r4 */
/* @0x12b114 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b118 ldr r3, [pc, #0x5c] */
/* @0x12b11c ldr r3, [pc, r3] */
/* @0x12b120 ldr r3, [r3] */
/* @0x12b124 ldr r2, [r3, #0x4] */
/* @0x12b128 ldr r3, [r3] */
/* @0x12b12c and r2, r0, r2 */
/* @0x12b130 ldr r3, [r3, r2, lsl #3] */
/* @0x12b134 cmp r3, #0 */
/* @0x12b138 bne 0x12b14c <_Z16F_ObjectSetDepthR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12b13c pop {r3, r4, r5, pc} */
/* @0x12b140 ldr r3, [r3, #0x4] */
/* @0x12b144 cmp r3, #0 */
/* @0x12b148 beq 0x12b178 <_Z16F_ObjectSetDepthR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12b14c ldr r2, [r3, #0x8] */
/* @0x12b150 cmp r0, r2 */
/* @0x12b154 bne 0x12b140 <_Z16F_ObjectSetDepthR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12b158 ldr r5, [r3, #0xc] */
/* @0x12b15c cmp r5, #0 */
/* @0x12b160 popeq {r3, r4, r5, pc} */
/* @0x12b164 mov r0, r4 */
/* @0x12b168 mov r1, #1 */
/* @0x12b16c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b170 str r0, [r5, #0x8] */
/* @0x12b174 pop {r3, r4, r5, pc} */
/* @0x12b178 pop {r3, r4, r5, pc} */
/* @0x12b17c eoreq r2, r12, r0, lsr #22 */

/* ── FUNC 0x12b180 · F_ObjectSetMask(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x12b180 push {r3, r4, r5, lr} */
/* @0x12b184 mov r1, #0 */
/* @0x12b188 ldr r4, [sp, #0x10] */
/* @0x12b18c mov r0, r4 */
/* @0x12b190 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b194 ldr r3, [pc, #0x5c] */
/* @0x12b198 ldr r3, [pc, r3] */
/* @0x12b19c ldr r3, [r3] */
/* @0x12b1a0 ldr r2, [r3, #0x4] */
/* @0x12b1a4 ldr r3, [r3] */
/* @0x12b1a8 and r2, r0, r2 */
/* @0x12b1ac ldr r3, [r3, r2, lsl #3] */
/* @0x12b1b0 cmp r3, #0 */
/* @0x12b1b4 bne 0x12b1c8 <_Z15F_ObjectSetMaskR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12b1b8 pop {r3, r4, r5, pc} */
/* @0x12b1bc ldr r3, [r3, #0x4] */
/* @0x12b1c0 cmp r3, #0 */
/* @0x12b1c4 beq 0x12b1f4 <_Z15F_ObjectSetMaskR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x12b1c8 ldr r2, [r3, #0x8] */
/* @0x12b1cc cmp r0, r2 */
/* @0x12b1d0 bne 0x12b1bc <_Z15F_ObjectSetMaskR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12b1d4 ldr r5, [r3, #0xc] */
/* @0x12b1d8 cmp r5, #0 */
/* @0x12b1dc popeq {r3, r4, r5, pc} */
/* @0x12b1e0 mov r0, r4 */
/* @0x12b1e4 mov r1, #1 */
/* @0x12b1e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b1ec str r0, [r5, #0x10] */
/* @0x12b1f0 pop {r3, r4, r5, pc} */
/* @0x12b1f4 pop {r3, r4, r5, pc} */
/* @0x12b1f8 eoreq r2, r12, r4, lsr #21 */

/* ── FUNC 0x12b1fc · F_SpriteExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x12b1fc push {r3, r4, r5, lr} */
/* @0x12b200 mov r4, #0 */
/* @0x12b204 mov r5, r0 */
/* @0x12b208 mov r1, r4 */
/* @0x12b20c str r4, [r0, #0xc] */
/* @0x12b210 str r4, [r0] */
/* @0x12b214 str r4, [r0, #0x4] */
/* @0x12b218 ldr r0, [sp, #0x10] */
/* @0x12b21c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b220 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x12b224 cmp r0, r4 */
/* @0x12b228 strne r4, [r5] */
/* @0x12b22c movne r3, r4 */
/* @0x12b230 movtne r3, #0x3ff0 */
/* @0x12b234 strne r3, [r5, #0x4] */
/* @0x12b238 pop {r3, r4, r5, pc} */

/* ── FUNC 0x12b23c · F_SpriteGetName(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x12b23c push {r4, lr} */
/* @0x12b240 mov r1, #0 */
/* @0x12b244 mov r4, r0 */
/* @0x12b248 ldr r0, [sp, #0x8] */
/* @0x12b24c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b250 bl 0x1eeee0 <_Z11Sprite_Namei> */
/* @0x12b254 mov r1, r0 */
/* @0x12b258 mov r0, r4 */
/* @0x12b25c pop {r4, lr} */
/* @0x12b260 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x12b264 · F_SpriteGetSpeedType(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x12b264 push {r3, r4, r5, r6, r7, lr} */
/* @0x12b268 mov r5, #0 */
/* @0x12b26c ldr r6, [sp, #0x18] */
/* @0x12b270 mov r1, r5 */
/* @0x12b274 str r5, [r0, #0xc] */
/* @0x12b278 mov r4, r0 */
/* @0x12b27c str r5, [r0] */
/* @0x12b280 mov r3, r5 */
/* @0x12b284 movt r3, #0xbff0 */
/* @0x12b288 str r3, [r0, #0x4] */
/* @0x12b28c mov r0, r6 */
/* @0x12b290 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b294 mov r1, r5 */
/* @0x12b298 mov r7, r0 */
/* @0x12b29c mov r0, r6 */
/* @0x12b2a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b2a4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b2a8 cmp r0, #0 */
/* @0x12b2ac beq 0x12b2c8 <_Z20F_SpriteGetSpeedTypeR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x12b2b0 ldr r2, [r0, #0x70] */
/* @0x12b2b4 vmov s15, r2 */
/* @0x12b2b8 vcvt.f64.s32 d7, s15 */
/* @0x12b2bc vmov r2, r3, d7 */
/* @0x12b2c0 stm r4, {r2, r3} */
/* @0x12b2c4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x12b2c8 ldr r3, [pc, #0x20] */
/* @0x12b2cc mov r2, r7 */
/* @0x12b2d0 ldr r1, [pc, #0x1c] */
/* @0x12b2d4 ldr r3, [pc, r3] */
/* @0x12b2d8 add r1, pc, r1 */
/* @0x12b2dc ldr r0, [r3] */
/* @0x12b2e0 ldr r3, [r0] */
/* @0x12b2e4 ldr r3, [r3, #0xc] */
/* @0x12b2e8 blx r3 */
/* @0x12b2ec pop {r3, r4, r5, r6, r7, pc} */
/* @0x12b2f0 eoreq r2, r12, r0, asr #8 */
/* @0x12b2f4 eoreq r2, r1, r8, asr #3 */

/* ── FUNC 0x12b2f8 · F_SpriteGetSpeed(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x12b2f8 push {r3, r4, r5, r6, r7, lr} */
/* @0x12b2fc mov r5, #0 */
/* @0x12b300 ldr r6, [sp, #0x18] */
/* @0x12b304 mov r1, r5 */
/* @0x12b308 str r5, [r0, #0xc] */
/* @0x12b30c mov r4, r0 */
/* @0x12b310 str r5, [r0] */
/* @0x12b314 mov r3, r5 */
/* @0x12b318 movt r3, #0xbff0 */
/* @0x12b31c str r3, [r0, #0x4] */
/* @0x12b320 mov r0, r6 */
/* @0x12b324 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b328 mov r1, r5 */
/* @0x12b32c mov r7, r0 */
/* @0x12b330 mov r0, r6 */
/* @0x12b334 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b338 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b33c cmp r0, #0 */
/* @0x12b340 beq 0x12b358 <_Z16F_SpriteGetSpeedR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x12b344 vldr s15, [r0, #108] */
/* @0x12b348 vcvt.f64.f32 d6, s15 */
/* @0x12b34c vmov r2, r3, d6 */
/* @0x12b350 stm r4, {r2, r3} */
/* @0x12b354 pop {r3, r4, r5, r6, r7, pc} */
/* @0x12b358 ldr r3, [pc, #0x20] */
/* @0x12b35c mov r2, r7 */
/* @0x12b360 ldr r1, [pc, #0x1c] */
/* @0x12b364 ldr r3, [pc, r3] */
/* @0x12b368 add r1, pc, r1 */
/* @0x12b36c ldr r0, [r3] */
/* @0x12b370 ldr r3, [r0] */
/* @0x12b374 ldr r3, [r3, #0xc] */
/* @0x12b378 blx r3 */
/* @0x12b37c pop {r3, r4, r5, r6, r7, pc} */
/* @0x12b380 .word 0x002c23b0 */
/* @0x12b384 eoreq r2, r1, r8, lsr r1 */

/* ── FUNC 0x12b388 · F_SpriteGetNumber(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b388 push {r4, lr} */
/* @0x12b38c mov r1, #0 */
/* @0x12b390 mov r4, r0 */
/* @0x12b394 ldr r0, [sp, #0x8] */
/* @0x12b398 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b39c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b3a0 mov r1, #0 */
/* @0x12b3a4 cmp r0, #0 */
/* @0x12b3a8 ldrne r2, [r0, #0x18] */
/* @0x12b3ac moveq r3, #0 */
/* @0x12b3b0 moveq r2, #0 */
/* @0x12b3b4 movteq r3, #0xbff0 */
/* @0x12b3b8 str r1, [r4, #0xc] */
/* @0x12b3bc vmovne s15, r2 */
/* @0x12b3c0 vcvtne.f64.s32 d7, s15 */
/* @0x12b3c4 vmovne r2, r3, d7 */
/* @0x12b3c8 stm r4, {r2, r3} */
/* @0x12b3cc pop {r4, pc} */

/* ── FUNC 0x12b3d0 · F_SpriteGetWidth(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b3d0 push {r4, lr} */
/* @0x12b3d4 mov r1, #0 */
/* @0x12b3d8 mov r4, r0 */
/* @0x12b3dc ldr r0, [sp, #0x8] */
/* @0x12b3e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b3e4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b3e8 mov r1, #0 */
/* @0x12b3ec cmp r0, #0 */
/* @0x12b3f0 ldrne r2, [r0, #0x1c] */
/* @0x12b3f4 moveq r3, #0 */
/* @0x12b3f8 moveq r2, #0 */
/* @0x12b3fc movteq r3, #0xbff0 */
/* @0x12b400 str r1, [r4, #0xc] */
/* @0x12b404 vmovne s15, r2 */
/* @0x12b408 vcvtne.f64.s32 d7, s15 */
/* @0x12b40c vmovne r2, r3, d7 */
/* @0x12b410 stm r4, {r2, r3} */
/* @0x12b414 pop {r4, pc} */

/* ── FUNC 0x12b418 · F_SpriteGetHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b418 push {r4, lr} */
/* @0x12b41c mov r1, #0 */
/* @0x12b420 mov r4, r0 */
/* @0x12b424 ldr r0, [sp, #0x8] */
/* @0x12b428 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b42c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b430 mov r1, #0 */
/* @0x12b434 cmp r0, #0 */
/* @0x12b438 ldrne r2, [r0, #0x20] */
/* @0x12b43c moveq r3, #0 */
/* @0x12b440 moveq r2, #0 */
/* @0x12b444 movteq r3, #0xbff0 */
/* @0x12b448 str r1, [r4, #0xc] */
/* @0x12b44c vmovne s15, r2 */
/* @0x12b450 vcvtne.f64.s32 d7, s15 */
/* @0x12b454 vmovne r2, r3, d7 */
/* @0x12b458 stm r4, {r2, r3} */
/* @0x12b45c pop {r4, pc} */

/* ── FUNC 0x12b460 · F_SpriteGetTransparent(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b460 push {r4, lr} */
/* @0x12b464 mov r1, #0 */
/* @0x12b468 mov r4, r0 */
/* @0x12b46c ldr r0, [sp, #0x8] */
/* @0x12b470 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b474 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b478 mov r1, #0 */
/* @0x12b47c cmp r0, #0 */
/* @0x12b480 ldrbne r2, [r0, #0x32] */
/* @0x12b484 moveq r3, #0 */
/* @0x12b488 moveq r2, #0 */
/* @0x12b48c movteq r3, #0xbff0 */
/* @0x12b490 str r1, [r4, #0xc] */
/* @0x12b494 vmovne s15, r2 */
/* @0x12b498 vcvtne.f64.s32 d7, s15 */
/* @0x12b49c vmovne r2, r3, d7 */
/* @0x12b4a0 stm r4, {r2, r3} */
/* @0x12b4a4 pop {r4, pc} */

/* ── FUNC 0x12b4a8 · F_SpriteGetSmooth(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b4a8 push {r4, lr} */
/* @0x12b4ac mov r1, #0 */
/* @0x12b4b0 mov r4, r0 */
/* @0x12b4b4 ldr r0, [sp, #0x8] */
/* @0x12b4b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b4bc bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b4c0 mov r1, #0 */
/* @0x12b4c4 cmp r0, #0 */
/* @0x12b4c8 ldrbne r2, [r0, #0x33] */
/* @0x12b4cc moveq r3, #0 */
/* @0x12b4d0 moveq r2, #0 */
/* @0x12b4d4 movteq r3, #0xbff0 */
/* @0x12b4d8 str r1, [r4, #0xc] */
/* @0x12b4dc vmovne s15, r2 */
/* @0x12b4e0 vcvtne.f64.s32 d7, s15 */
/* @0x12b4e4 vmovne r2, r3, d7 */
/* @0x12b4e8 stm r4, {r2, r3} */
/* @0x12b4ec pop {r4, pc} */

/* ── FUNC 0x12b4f0 · F_SpriteGetPreload(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b4f0 push {r4, lr} */
/* @0x12b4f4 mov r1, #0 */
/* @0x12b4f8 mov r4, r0 */
/* @0x12b4fc ldr r0, [sp, #0x8] */
/* @0x12b500 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b504 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b508 mov r1, #0 */
/* @0x12b50c cmp r0, #0 */
/* @0x12b510 ldrbne r2, [r0, #0x34] */
/* @0x12b514 moveq r3, #0 */
/* @0x12b518 moveq r2, #0 */
/* @0x12b51c movteq r3, #0xbff0 */
/* @0x12b520 str r1, [r4, #0xc] */
/* @0x12b524 vmovne s15, r2 */
/* @0x12b528 vcvtne.f64.s32 d7, s15 */
/* @0x12b52c vmovne r2, r3, d7 */
/* @0x12b530 stm r4, {r2, r3} */
/* @0x12b534 pop {r4, pc} */

/* ── FUNC 0x12b538 · F_SpriteGetXoffset(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b538 push {r4, lr} */
/* @0x12b53c mov r1, #0 */
/* @0x12b540 mov r4, r0 */
/* @0x12b544 ldr r0, [sp, #0x8] */
/* @0x12b548 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b54c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b550 mov r1, #0 */
/* @0x12b554 cmp r0, #0 */
/* @0x12b558 ldrne r2, [r0, #0x24] */
/* @0x12b55c moveq r3, #0 */
/* @0x12b560 moveq r2, #0 */
/* @0x12b564 movteq r3, #0xbff0 */
/* @0x12b568 str r1, [r4, #0xc] */
/* @0x12b56c vmovne s15, r2 */
/* @0x12b570 vcvtne.f64.s32 d7, s15 */
/* @0x12b574 vmovne r2, r3, d7 */
/* @0x12b578 stm r4, {r2, r3} */
/* @0x12b57c pop {r4, pc} */

/* ── FUNC 0x12b580 · F_SpriteGetYoffset(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b580 push {r4, lr} */
/* @0x12b584 mov r1, #0 */
/* @0x12b588 mov r4, r0 */
/* @0x12b58c ldr r0, [sp, #0x8] */
/* @0x12b590 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b594 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b598 mov r1, #0 */
/* @0x12b59c cmp r0, #0 */
/* @0x12b5a0 ldrne r2, [r0, #0x28] */
/* @0x12b5a4 moveq r3, #0 */
/* @0x12b5a8 moveq r2, #0 */
/* @0x12b5ac movteq r3, #0xbff0 */
/* @0x12b5b0 str r1, [r4, #0xc] */
/* @0x12b5b4 vmovne s15, r2 */
/* @0x12b5b8 vcvtne.f64.s32 d7, s15 */
/* @0x12b5bc vmovne r2, r3, d7 */
/* @0x12b5c0 stm r4, {r2, r3} */
/* @0x12b5c4 pop {r4, pc} */

/* ── FUNC 0x12b5c8 · F_SpriteGetBboxMode(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b5c8 push {r4, lr} */
/* @0x12b5cc mov r1, #0 */
/* @0x12b5d0 mov r4, r0 */
/* @0x12b5d4 ldr r0, [sp, #0x8] */
/* @0x12b5d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b5dc bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b5e0 mov r1, #0 */
/* @0x12b5e4 cmp r0, #0 */
/* @0x12b5e8 ldrne r2, [r0, #0x4] */
/* @0x12b5ec moveq r3, #0 */
/* @0x12b5f0 moveq r2, #0 */
/* @0x12b5f4 movteq r3, #0xbff0 */
/* @0x12b5f8 str r1, [r4, #0xc] */
/* @0x12b5fc vmovne s15, r2 */
/* @0x12b600 vcvtne.f64.s32 d7, s15 */
/* @0x12b604 vmovne r2, r3, d7 */
/* @0x12b608 stm r4, {r2, r3} */
/* @0x12b60c pop {r4, pc} */

/* ── FUNC 0x12b610 · F_SpriteGetPrecise(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b610 push {r4, lr} */
/* @0x12b614 mov r1, #0 */
/* @0x12b618 mov r4, r0 */
/* @0x12b61c ldr r0, [sp, #0x8] */
/* @0x12b620 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b624 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b628 mov r1, #0 */
/* @0x12b62c cmp r0, #0 */
/* @0x12b630 ldrbne r2, [r0, #0x30] */
/* @0x12b634 moveq r3, #0 */
/* @0x12b638 moveq r2, #0 */
/* @0x12b63c movteq r3, #0xbff0 */
/* @0x12b640 str r1, [r4, #0xc] */
/* @0x12b644 vmovne s15, r2 */
/* @0x12b648 vcvtne.f64.s32 d7, s15 */
/* @0x12b64c vmovne r2, r3, d7 */
/* @0x12b650 stm r4, {r2, r3} */
/* @0x12b654 pop {r4, pc} */

/* ── FUNC 0x12b658 · F_SpriteGetBboxLeft(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b658 push {r4, lr} */
/* @0x12b65c mov r1, #0 */
/* @0x12b660 mov r4, r0 */
/* @0x12b664 ldr r0, [sp, #0x8] */
/* @0x12b668 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b66c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b670 mov r1, #0 */
/* @0x12b674 cmp r0, #0 */
/* @0x12b678 ldrne r2, [r0, #0x8] */
/* @0x12b67c moveq r3, #0 */
/* @0x12b680 moveq r2, #0 */
/* @0x12b684 movteq r3, #0xbff0 */
/* @0x12b688 str r1, [r4, #0xc] */
/* @0x12b68c vmovne s15, r2 */
/* @0x12b690 vcvtne.f64.s32 d7, s15 */
/* @0x12b694 vmovne r2, r3, d7 */
/* @0x12b698 stm r4, {r2, r3} */
/* @0x12b69c pop {r4, pc} */

/* ── FUNC 0x12b6a0 · F_SpriteGetBboxRight(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b6a0 push {r4, lr} */
/* @0x12b6a4 mov r1, #0 */
/* @0x12b6a8 mov r4, r0 */
/* @0x12b6ac ldr r0, [sp, #0x8] */
/* @0x12b6b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b6b4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b6b8 mov r1, #0 */
/* @0x12b6bc cmp r0, #0 */
/* @0x12b6c0 ldrne r2, [r0, #0x10] */
/* @0x12b6c4 moveq r3, #0 */
/* @0x12b6c8 moveq r2, #0 */
/* @0x12b6cc movteq r3, #0xbff0 */
/* @0x12b6d0 str r1, [r4, #0xc] */
/* @0x12b6d4 vmovne s15, r2 */
/* @0x12b6d8 vcvtne.f64.s32 d7, s15 */
/* @0x12b6dc vmovne r2, r3, d7 */
/* @0x12b6e0 stm r4, {r2, r3} */
/* @0x12b6e4 pop {r4, pc} */

/* ── FUNC 0x12b6e8 · F_SpriteGetBboxTop(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b6e8 push {r4, lr} */
/* @0x12b6ec mov r1, #0 */
/* @0x12b6f0 mov r4, r0 */
/* @0x12b6f4 ldr r0, [sp, #0x8] */
/* @0x12b6f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b6fc bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b700 mov r1, #0 */
/* @0x12b704 cmp r0, #0 */
/* @0x12b708 ldrne r2, [r0, #0xc] */
/* @0x12b70c moveq r3, #0 */
/* @0x12b710 moveq r2, #0 */
/* @0x12b714 movteq r3, #0xbff0 */
/* @0x12b718 str r1, [r4, #0xc] */
/* @0x12b71c vmovne s15, r2 */
/* @0x12b720 vcvtne.f64.s32 d7, s15 */
/* @0x12b724 vmovne r2, r3, d7 */
/* @0x12b728 stm r4, {r2, r3} */
/* @0x12b72c pop {r4, pc} */

/* ── FUNC 0x12b730 · F_SpriteGetBboxBottom(RValue&, CInstance*, CInstance*, int, RValue*) · size=72 · insn=18 */
/* @0x12b730 push {r4, lr} */
/* @0x12b734 mov r1, #0 */
/* @0x12b738 mov r4, r0 */
/* @0x12b73c ldr r0, [sp, #0x8] */
/* @0x12b740 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b744 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b748 mov r1, #0 */
/* @0x12b74c cmp r0, #0 */
/* @0x12b750 ldrne r2, [r0, #0x14] */
/* @0x12b754 moveq r3, #0 */
/* @0x12b758 moveq r2, #0 */
/* @0x12b75c movteq r3, #0xbff0 */
/* @0x12b760 str r1, [r4, #0xc] */
/* @0x12b764 vmovne s15, r2 */
/* @0x12b768 vcvtne.f64.s32 d7, s15 */
/* @0x12b76c vmovne r2, r3, d7 */
/* @0x12b770 stm r4, {r2, r3} */
/* @0x12b774 pop {r4, pc} */

/* ── FUNC 0x12b778 · F_SpriteCreateFromScreen(RValue&, CInstance*, CInstance*, int, RValue*) · size=500 · insn=125 */
/* @0x12b778 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x12b77c sub sp, sp, #36 */
/* @0x12b780 mov r6, #0 */
/* @0x12b784 str r6, [r0, #0xc] */
/* @0x12b788 ldr r4, [sp, #0x48] */
/* @0x12b78c mov r5, r0 */
/* @0x12b790 mov r8, r3 */
/* @0x12b794 bl 0x1ef890 <_Z15Sprite_AddEmptyv> */
/* @0x12b798 mov r1, r6 */
/* @0x12b79c vmov s15, r0 */
/* @0x12b7a0 mov r7, r0 */
/* @0x12b7a4 mov r0, r4 */
/* @0x12b7a8 vcvt.f64.s32 d7, s15 */
/* @0x12b7ac vmov r2, r3, d7 */
/* @0x12b7b0 stm r5, {r2, r3} */
/* @0x12b7b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b7b8 mov r1, #1 */
/* @0x12b7bc mov r10, r0 */
/* @0x12b7c0 mov r0, r4 */
/* @0x12b7c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b7c8 mov r1, #2 */
/* @0x12b7cc mov r9, r0 */
/* @0x12b7d0 mov r0, r4 */
/* @0x12b7d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b7d8 mov r1, #3 */
/* @0x12b7dc mov r5, r0 */
/* @0x12b7e0 mov r0, r4 */
/* @0x12b7e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b7e8 mov r2, r5 */
/* @0x12b7ec mov r1, r9 */
/* @0x12b7f0 mov r3, r0 */
/* @0x12b7f4 mov r0, r10 */
/* @0x12b7f8 bl 0x169b34 <_Z22GR_D3D_Screenshot_Partiiii> */
/* @0x12b7fc subs r5, r0, #0 */
/* @0x12b800 beq 0x12b8d8 <_Z24F_SpriteCreateFromScreenR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x12b804 cmp r8, #8 */
/* @0x12b808 beq 0x12b8e0 <_Z24F_SpriteCreateFromScreenR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x12b80c mov r0, r7 */
/* @0x12b810 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b814 mov r1, #4 */
/* @0x12b818 mov r7, r0 */
/* @0x12b81c mov r0, r4 */
/* @0x12b820 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b824 mov r1, #5 */
/* @0x12b828 mov r10, r0 */
/* @0x12b82c mov r0, r4 */
/* @0x12b830 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b834 mov r1, #6 */
/* @0x12b838 mov r8, r0 */
/* @0x12b83c mov r0, r4 */
/* @0x12b840 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b844 mov r1, #7 */
/* @0x12b848 mov r3, r0 */
/* @0x12b84c mov r0, r4 */
/* @0x12b850 str r3, [sp, #0x1c] */
/* @0x12b854 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b858 mov r1, #8 */
/* @0x12b85c mov r11, r0 */
/* @0x12b860 mov r0, r4 */
/* @0x12b864 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b868 mov r1, #9 */
/* @0x12b86c mov r9, r0 */
/* @0x12b870 mov r0, r4 */
/* @0x12b874 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b878 ldr r3, [sp, #0x1c] */
/* @0x12b87c str r9, [sp, #0x8] */
/* @0x12b880 mov r1, r5 */
/* @0x12b884 cmp r3, #0 */
/* @0x12b888 str r6, [sp, #0x10] */
/* @0x12b88c movle r3, #0 */
/* @0x12b890 movgt r3, #1 */
/* @0x12b894 cmp r11, #0 */
/* @0x12b898 movle r11, #0 */
/* @0x12b89c movgt r11, #1 */
/* @0x12b8a0 cmp r10, #0 */
/* @0x12b8a4 stm sp, {r3, r11} */
/* @0x12b8a8 movle r2, #0 */
/* @0x12b8ac movgt r2, #1 */
/* @0x12b8b0 cmp r8, #0 */
/* @0x12b8b4 movle r3, #0 */
/* @0x12b8b8 movgt r3, #1 */
/* @0x12b8bc str r0, [sp, #0xc] */
/* @0x12b8c0 mov r0, r7 */
/* @0x12b8c4 bl 0x1e74ac <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib> */
/* @0x12b8c8 ldr r3, [r5] */
/* @0x12b8cc mov r0, r5 */
/* @0x12b8d0 ldr r3, [r3, #0x4] */
/* @0x12b8d4 blx r3 */
/* @0x12b8d8 add sp, sp, #36 */
/* @0x12b8dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x12b8e0 mov r1, #4 */
/* @0x12b8e4 mov r0, r4 */
/* @0x12b8e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b8ec cmp r0, r6 */
/* @0x12b8f0 mov r0, r7 */
/* @0x12b8f4 movle r6, #0 */
/* @0x12b8f8 movgt r6, #1 */
/* @0x12b8fc bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12b900 mov r1, #5 */
/* @0x12b904 mov r7, r0 */
/* @0x12b908 mov r0, r4 */
/* @0x12b90c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b910 mov r1, #6 */
/* @0x12b914 mov r9, r0 */
/* @0x12b918 mov r0, r4 */
/* @0x12b91c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b920 mov r1, #7 */
/* @0x12b924 mov r8, r0 */
/* @0x12b928 mov r0, r4 */
/* @0x12b92c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b930 cmp r9, #0 */
/* @0x12b934 mov r2, #1 */
/* @0x12b938 str r8, [sp, #0x8] */
/* @0x12b93c eor r1, r6, r2 */
/* @0x12b940 movle r9, #0 */
/* @0x12b944 movgt r9, #1 */
/* @0x12b948 str r1, [sp, #0x10] */
/* @0x12b94c str r9, [sp] */
/* @0x12b950 mov r3, r6 */
/* @0x12b954 str r2, [sp, #0x4] */
/* @0x12b958 mov r1, r5 */
/* @0x12b95c str r0, [sp, #0xc] */
/* @0x12b960 mov r0, r7 */
/* @0x12b964 bl 0x1e74ac <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib> */
/* @0x12b968 b 0x12b8c8 <_Z24F_SpriteCreateFromScreenR6RValueP9CInstanceS2_iPS_+0x150> */

/* ── FUNC 0x12b96c · F_SpriteCreateFromSurface(RValue&, CInstance*, CInstance*, int, RValue*) · size=532 · insn=133 */
/* @0x12b96c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x12b970 sub sp, sp, #28 */
/* @0x12b974 mov r7, #0 */
/* @0x12b978 str r7, [r0, #0xc] */
/* @0x12b97c ldr r4, [sp, #0x40] */
/* @0x12b980 mov r5, r0 */
/* @0x12b984 mov r8, r3 */
/* @0x12b988 bl 0x1ef890 <_Z15Sprite_AddEmptyv> */
/* @0x12b98c mov r1, r7 */
/* @0x12b990 vmov s15, r0 */
/* @0x12b994 mov r0, r4 */
/* @0x12b998 vcvt.f64.s32 d7, s15 */
/* @0x12b99c vmov r2, r3, d7 */
/* @0x12b9a0 stm r5, {r2, r3} */
/* @0x12b9a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b9a8 mov r1, #1 */
/* @0x12b9ac mov r6, r0 */
/* @0x12b9b0 mov r0, r4 */
/* @0x12b9b4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b9b8 mov r1, #2 */
/* @0x12b9bc mov r11, r0 */
/* @0x12b9c0 mov r0, r4 */
/* @0x12b9c4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b9c8 mov r1, #3 */
/* @0x12b9cc mov r10, r0 */
/* @0x12b9d0 mov r0, r4 */
/* @0x12b9d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b9d8 mov r1, #4 */
/* @0x12b9dc mov r9, r0 */
/* @0x12b9e0 mov r0, r4 */
/* @0x12b9e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12b9e8 mov r1, r11 */
/* @0x12b9ec mov r2, r10 */
/* @0x12b9f0 mov r3, r9 */
/* @0x12b9f4 str r0, [sp] */
/* @0x12b9f8 mov r0, r6 */
/* @0x12b9fc bl 0x1720e4 <_Z26GR_Surface_Screenshot_Partiiiii> */
/* @0x12ba00 subs r6, r0, #0 */
/* @0x12ba04 beq 0x12bab4 <_Z25F_SpriteCreateFromSurfaceR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x12ba08 cmp r8, #11 */
/* @0x12ba0c beq 0x12babc <_Z25F_SpriteCreateFromSurfaceR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x12ba10 mov r1, #5 */
/* @0x12ba14 mov r0, r4 */
/* @0x12ba18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ba1c ldm r5, {r2, r3} */
/* @0x12ba20 mov r1, r3 */
/* @0x12ba24 cmp r0, #0 */
/* @0x12ba28 mov r0, r2 */
/* @0x12ba2c movle r5, #0 */
/* @0x12ba30 movgt r5, #1 */
/* @0x12ba34 bl 0xb66e8 <lrint@plt> */
/* @0x12ba38 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12ba3c mov r1, #6 */
/* @0x12ba40 mov r8, r0 */
/* @0x12ba44 mov r0, r4 */
/* @0x12ba48 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ba4c mov r1, #7 */
/* @0x12ba50 mov r10, r0 */
/* @0x12ba54 mov r0, r4 */
/* @0x12ba58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ba5c mov r1, #8 */
/* @0x12ba60 mov r9, r0 */
/* @0x12ba64 mov r0, r4 */
/* @0x12ba68 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12ba6c cmp r10, #0 */
/* @0x12ba70 eor r2, r5, #1 */
/* @0x12ba74 str r9, [sp, #0x8] */
/* @0x12ba78 movle r10, #0 */
/* @0x12ba7c movgt r10, #1 */
/* @0x12ba80 str r2, [sp, #0x10] */
/* @0x12ba84 mov r3, r5 */
/* @0x12ba88 str r10, [sp] */
/* @0x12ba8c mov r1, r6 */
/* @0x12ba90 str r7, [sp, #0x4] */
/* @0x12ba94 mov r2, #1 */
/* @0x12ba98 str r0, [sp, #0xc] */
/* @0x12ba9c mov r0, r8 */
/* @0x12baa0 bl 0x1e74ac <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib> */
/* @0x12baa4 ldr r3, [r6] */
/* @0x12baa8 mov r0, r6 */
/* @0x12baac ldr r3, [r3, #0x4] */
/* @0x12bab0 blx r3 */
/* @0x12bab4 add sp, sp, #28 */
/* @0x12bab8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x12babc ldm r5, {r0, r1} */
/* @0x12bac0 bl 0xb66e8 <lrint@plt> */
/* @0x12bac4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12bac8 mov r1, #5 */
/* @0x12bacc mov r5, r0 */
/* @0x12bad0 mov r0, r4 */
/* @0x12bad4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bad8 mov r1, #6 */
/* @0x12badc mov r9, r0 */
/* @0x12bae0 mov r0, r4 */
/* @0x12bae4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bae8 mov r1, #7 */
/* @0x12baec mov r7, r0 */
/* @0x12baf0 mov r0, r4 */
/* @0x12baf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12baf8 mov r1, #8 */
/* @0x12bafc mov r11, r0 */
/* @0x12bb00 mov r0, r4 */
/* @0x12bb04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bb08 mov r1, #9 */
/* @0x12bb0c mov r10, r0 */
/* @0x12bb10 mov r0, r4 */
/* @0x12bb14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bb18 mov r1, #10 */
/* @0x12bb1c mov r8, r0 */
/* @0x12bb20 mov r0, r4 */
/* @0x12bb24 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bb28 cmp r11, #0 */
/* @0x12bb2c mov r12, #1 */
/* @0x12bb30 str r8, [sp, #0x8] */
/* @0x12bb34 movle r11, #0 */
/* @0x12bb38 movgt r11, #1 */
/* @0x12bb3c cmp r10, #0 */
/* @0x12bb40 str r11, [sp] */
/* @0x12bb44 mov r1, r6 */
/* @0x12bb48 str r12, [sp, #0x10] */
/* @0x12bb4c movle r10, #0 */
/* @0x12bb50 movgt r10, #1 */
/* @0x12bb54 cmp r9, #0 */
/* @0x12bb58 str r10, [sp, #0x4] */
/* @0x12bb5c movle r2, #0 */
/* @0x12bb60 movgt r2, #1 */
/* @0x12bb64 cmp r7, #0 */
/* @0x12bb68 movle r3, #0 */
/* @0x12bb6c movgt r3, #1 */
/* @0x12bb70 str r0, [sp, #0xc] */
/* @0x12bb74 mov r0, r5 */
/* @0x12bb78 bl 0x1e74ac <_ZN7CSprite16CreateFromBitmapEP7IBitmapbbbbiib> */
/* @0x12bb7c b 0x12baa4 <_Z25F_SpriteCreateFromSurfaceR6RValueP9CInstanceS2_iPS_+0x138> */

/* ── FUNC 0x12bb80 · F_SpriteReplace(RValue&, CInstance*, CInstance*, int, RValue*) · size=484 · insn=121 */
/* @0x12bb80 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x12bb84 sub sp, sp, #36 */
/* @0x12bb88 mov r1, #0 */
/* @0x12bb8c mov r5, r0 */
/* @0x12bb90 ldr r4, [sp, #0x48] */
/* @0x12bb94 mov r6, r3 */
/* @0x12bb98 mov r0, r4 */
/* @0x12bb9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bba0 mov r7, r0 */
/* @0x12bba4 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x12bba8 cmp r0, #0 */
/* @0x12bbac beq 0x12bcac <_Z15F_SpriteReplaceR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x12bbb0 cmp r6, #7 */
/* @0x12bbb4 beq 0x12bccc <_Z15F_SpriteReplaceR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x12bbb8 cmp r6, #9 */
/* @0x12bbbc bne 0x12bcac <_Z15F_SpriteReplaceR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x12bbc0 mov r1, #1 */
/* @0x12bbc4 mov r0, r4 */
/* @0x12bbc8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12bbcc mov r1, #2 */
/* @0x12bbd0 mov r9, r0 */
/* @0x12bbd4 mov r0, r4 */
/* @0x12bbd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bbdc mov r1, #3 */
/* @0x12bbe0 mov r8, r0 */
/* @0x12bbe4 mov r0, r4 */
/* @0x12bbe8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bbec mov r1, #4 */
/* @0x12bbf0 mov r6, r0 */
/* @0x12bbf4 mov r0, r4 */
/* @0x12bbf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bbfc mov r1, #5 */
/* @0x12bc00 mov r2, r0 */
/* @0x12bc04 mov r0, r4 */
/* @0x12bc08 str r2, [sp, #0x18] */
/* @0x12bc0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bc10 mov r1, #6 */
/* @0x12bc14 mov r3, r0 */
/* @0x12bc18 mov r0, r4 */
/* @0x12bc1c str r3, [sp, #0x1c] */
/* @0x12bc20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bc24 mov r1, #7 */
/* @0x12bc28 mov r11, r0 */
/* @0x12bc2c mov r0, r4 */
/* @0x12bc30 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bc34 mov r1, #8 */
/* @0x12bc38 mov r10, r0 */
/* @0x12bc3c mov r0, r4 */
/* @0x12bc40 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bc44 ldr r2, [sp, #0x18] */
/* @0x12bc48 ldr r3, [sp, #0x1c] */
/* @0x12bc4c mov r1, r9 */
/* @0x12bc50 cmp r2, #0 */
/* @0x12bc54 str r10, [sp, #0xc] */
/* @0x12bc58 movle r2, #0 */
/* @0x12bc5c movgt r2, #1 */
/* @0x12bc60 cmp r3, #0 */
/* @0x12bc64 movle r3, #0 */
/* @0x12bc68 movgt r3, #1 */
/* @0x12bc6c cmp r11, #0 */
/* @0x12bc70 stm sp, {r2, r3} */
/* @0x12bc74 mov r2, r8 */
/* @0x12bc78 movle r11, #0 */
/* @0x12bc7c movgt r11, #1 */
/* @0x12bc80 cmp r6, #0 */
/* @0x12bc84 str r11, [sp, #0x8] */
/* @0x12bc88 movle r3, #0 */
/* @0x12bc8c movgt r3, #1 */
/* @0x12bc90 str r0, [sp, #0x10] */
/* @0x12bc94 mov r0, r7 */
/* @0x12bc98 bl 0x1ef5a8 <_Z14Sprite_ReplaceiPKcibbbbii> */
/* @0x12bc9c vmov s15, r0 */
/* @0x12bca0 vcvt.f64.s32 d7, s15 */
/* @0x12bca4 vmov r2, r3, d7 */
/* @0x12bca8 b 0x12bcb8 <_Z15F_SpriteReplaceR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x12bcac mov r3, #0 */
/* @0x12bcb0 movt r3, #0xbff0 */
/* @0x12bcb4 mov r2, #0 */
/* @0x12bcb8 mov r1, #0 */
/* @0x12bcbc stm r5, {r2, r3} */
/* @0x12bcc0 str r1, [r5, #0xc] */
/* @0x12bcc4 add sp, sp, #36 */
/* @0x12bcc8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x12bccc mov r1, #1 */
/* @0x12bcd0 mov r0, r4 */
/* @0x12bcd4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12bcd8 mov r1, #2 */
/* @0x12bcdc mov r9, r0 */
/* @0x12bce0 mov r0, r4 */
/* @0x12bce4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bce8 mov r1, #3 */
/* @0x12bcec mov r8, r0 */
/* @0x12bcf0 mov r0, r4 */
/* @0x12bcf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bcf8 mov r1, #4 */
/* @0x12bcfc mov r11, r0 */
/* @0x12bd00 mov r0, r4 */
/* @0x12bd04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bd08 mov r1, #5 */
/* @0x12bd0c mov r10, r0 */
/* @0x12bd10 mov r0, r4 */
/* @0x12bd14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bd18 mov r1, #6 */
/* @0x12bd1c mov r6, r0 */
/* @0x12bd20 mov r0, r4 */
/* @0x12bd24 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bd28 cmp r11, #0 */
/* @0x12bd2c mov r12, #1 */
/* @0x12bd30 mov r1, r9 */
/* @0x12bd34 movle r11, #0 */
/* @0x12bd38 movgt r11, #1 */
/* @0x12bd3c cmp r10, #0 */
/* @0x12bd40 str r11, [sp] */
/* @0x12bd44 mov r2, r8 */
/* @0x12bd48 str r6, [sp, #0xc] */
/* @0x12bd4c movle r10, #0 */
/* @0x12bd50 movgt r10, #1 */
/* @0x12bd54 mov r3, r12 */
/* @0x12bd58 str r10, [sp, #0x4] */
/* @0x12bd5c str r12, [sp, #0x8] */
/* @0x12bd60 b 0x12bc90 <_Z15F_SpriteReplaceR6RValueP9CInstanceS2_iPS_+0x110> */

/* ── FUNC 0x12bd64 · F_FontAddEnableAA(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x12bd64 push {r3, lr} */
/* @0x12bd68 mov r1, #0 */
/* @0x12bd6c ldr r0, [sp, #0x8] */
/* @0x12bd70 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12bd74 ldr r3, [pc, #0x8] */
/* @0x12bd78 ldr r3, [pc, r3] */
/* @0x12bd7c strb r0, [r3] */
/* @0x12bd80 pop {r3, pc} */
/* @0x12bd84 eoreq r2, r12, r0, ror #1 */

/* ── FUNC 0x12bd88 · F_ObjectSetSolid(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x12bd88 push {r3, r4, r5, lr} */
/* @0x12bd8c mov r1, #0 */
/* @0x12bd90 ldr r4, [sp, #0x10] */
/* @0x12bd94 mov r0, r4 */
/* @0x12bd98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bd9c ldr r3, [pc, #0x6c] */
/* @0x12bda0 ldr r3, [pc, r3] */
/* @0x12bda4 ldr r3, [r3] */
/* @0x12bda8 ldr r2, [r3, #0x4] */
/* @0x12bdac ldr r3, [r3] */
/* @0x12bdb0 and r2, r0, r2 */
/* @0x12bdb4 ldr r3, [r3, r2, lsl #3] */
/* @0x12bdb8 cmp r3, #0 */
/* @0x12bdbc bne 0x12bdd0 <_Z16F_ObjectSetSolidR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12bdc0 pop {r3, r4, r5, pc} */
/* @0x12bdc4 ldr r3, [r3, #0x4] */
/* @0x12bdc8 cmp r3, #0 */
/* @0x12bdcc beq 0x12be0c <_Z16F_ObjectSetSolidR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x12bdd0 ldr r2, [r3, #0x8] */
/* @0x12bdd4 cmp r0, r2 */
/* @0x12bdd8 bne 0x12bdc4 <_Z16F_ObjectSetSolidR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12bddc ldr r5, [r3, #0xc] */
/* @0x12bde0 cmp r5, #0 */
/* @0x12bde4 popeq {r3, r4, r5, pc} */
/* @0x12bde8 mov r0, r4 */
/* @0x12bdec mov r1, #1 */
/* @0x12bdf0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12bdf4 ldr r3, [r5] */
/* @0x12bdf8 cmp r0, #0 */
/* @0x12bdfc orrne r3, r3, #1 */
/* @0x12be00 biceq r3, r3, #1 */
/* @0x12be04 str r3, [r5] */
/* @0x12be08 pop {r3, r4, r5, pc} */
/* @0x12be0c pop {r3, r4, r5, pc} */
/* @0x12be10 mlaeq r12, r12, lr, r1 */

/* ── FUNC 0x12be14 · F_ObjectSetVisible(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x12be14 push {r3, r4, r5, lr} */
/* @0x12be18 mov r1, #0 */
/* @0x12be1c ldr r4, [sp, #0x10] */
/* @0x12be20 mov r0, r4 */
/* @0x12be24 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12be28 ldr r3, [pc, #0x6c] */
/* @0x12be2c ldr r3, [pc, r3] */
/* @0x12be30 ldr r3, [r3] */
/* @0x12be34 ldr r2, [r3, #0x4] */
/* @0x12be38 ldr r3, [r3] */
/* @0x12be3c and r2, r0, r2 */
/* @0x12be40 ldr r3, [r3, r2, lsl #3] */
/* @0x12be44 cmp r3, #0 */
/* @0x12be48 bne 0x12be5c <_Z18F_ObjectSetVisibleR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12be4c pop {r3, r4, r5, pc} */
/* @0x12be50 ldr r3, [r3, #0x4] */
/* @0x12be54 cmp r3, #0 */
/* @0x12be58 beq 0x12be98 <_Z18F_ObjectSetVisibleR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x12be5c ldr r2, [r3, #0x8] */
/* @0x12be60 cmp r0, r2 */
/* @0x12be64 bne 0x12be50 <_Z18F_ObjectSetVisibleR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12be68 ldr r5, [r3, #0xc] */
/* @0x12be6c cmp r5, #0 */
/* @0x12be70 popeq {r3, r4, r5, pc} */
/* @0x12be74 mov r0, r4 */
/* @0x12be78 mov r1, #1 */
/* @0x12be7c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12be80 ldr r3, [r5] */
/* @0x12be84 cmp r0, #0 */
/* @0x12be88 orrne r3, r3, #2 */
/* @0x12be8c biceq r3, r3, #2 */
/* @0x12be90 str r3, [r5] */
/* @0x12be94 pop {r3, r4, r5, pc} */
/* @0x12be98 pop {r3, r4, r5, pc} */
/* @0x12be9c eoreq r1, r12, r0, lsl lr */

/* ── FUNC 0x12bea0 · F_ObjectSetPersistent(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x12bea0 push {r3, r4, r5, lr} */
/* @0x12bea4 mov r1, #0 */
/* @0x12bea8 ldr r4, [sp, #0x10] */
/* @0x12beac mov r0, r4 */
/* @0x12beb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12beb4 ldr r3, [pc, #0x6c] */
/* @0x12beb8 ldr r3, [pc, r3] */
/* @0x12bebc ldr r3, [r3] */
/* @0x12bec0 ldr r2, [r3, #0x4] */
/* @0x12bec4 ldr r3, [r3] */
/* @0x12bec8 and r2, r0, r2 */
/* @0x12becc ldr r3, [r3, r2, lsl #3] */
/* @0x12bed0 cmp r3, #0 */
/* @0x12bed4 bne 0x12bee8 <_Z21F_ObjectSetPersistentR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12bed8 pop {r3, r4, r5, pc} */
/* @0x12bedc ldr r3, [r3, #0x4] */
/* @0x12bee0 cmp r3, #0 */
/* @0x12bee4 beq 0x12bf24 <_Z21F_ObjectSetPersistentR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x12bee8 ldr r2, [r3, #0x8] */
/* @0x12beec cmp r0, r2 */
/* @0x12bef0 bne 0x12bedc <_Z21F_ObjectSetPersistentR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12bef4 ldr r5, [r3, #0xc] */
/* @0x12bef8 cmp r5, #0 */
/* @0x12befc popeq {r3, r4, r5, pc} */
/* @0x12bf00 mov r0, r4 */
/* @0x12bf04 mov r1, #1 */
/* @0x12bf08 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12bf0c ldr r3, [r5] */
/* @0x12bf10 cmp r0, #0 */
/* @0x12bf14 orrne r3, r3, #4 */
/* @0x12bf18 biceq r3, r3, #4 */
/* @0x12bf1c str r3, [r5] */
/* @0x12bf20 pop {r3, r4, r5, pc} */
/* @0x12bf24 pop {r3, r4, r5, pc} */
/* @0x12bf28 eoreq r1, r12, r4, lsl #27 */

/* ── FUNC 0x12bf2c · F_ObjectSetCollisions(RValue&, CInstance*, CInstance*, int, RValue*) · size=140 · insn=35 */
/* @0x12bf2c push {r3, r4, r5, lr} */
/* @0x12bf30 mov r1, #0 */
/* @0x12bf34 ldr r4, [sp, #0x10] */
/* @0x12bf38 mov r0, r4 */
/* @0x12bf3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bf40 ldr r3, [pc, #0x6c] */
/* @0x12bf44 ldr r3, [pc, r3] */
/* @0x12bf48 ldr r3, [r3] */
/* @0x12bf4c ldr r2, [r3, #0x4] */
/* @0x12bf50 ldr r3, [r3] */
/* @0x12bf54 and r2, r0, r2 */
/* @0x12bf58 ldr r3, [r3, r2, lsl #3] */
/* @0x12bf5c cmp r3, #0 */
/* @0x12bf60 bne 0x12bf74 <_Z21F_ObjectSetCollisionsR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x12bf64 pop {r3, r4, r5, pc} */
/* @0x12bf68 ldr r3, [r3, #0x4] */
/* @0x12bf6c cmp r3, #0 */
/* @0x12bf70 beq 0x12bfb0 <_Z21F_ObjectSetCollisionsR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x12bf74 ldr r2, [r3, #0x8] */
/* @0x12bf78 cmp r0, r2 */
/* @0x12bf7c bne 0x12bf68 <_Z21F_ObjectSetCollisionsR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x12bf80 ldr r5, [r3, #0xc] */
/* @0x12bf84 cmp r5, #0 */
/* @0x12bf88 popeq {r3, r4, r5, pc} */
/* @0x12bf8c mov r0, r4 */
/* @0x12bf90 mov r1, #1 */
/* @0x12bf94 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12bf98 ldr r3, [r5] */
/* @0x12bf9c cmp r0, #0 */
/* @0x12bfa0 orrne r3, r3, #16 */
/* @0x12bfa4 biceq r3, r3, #16 */
/* @0x12bfa8 str r3, [r5] */
/* @0x12bfac pop {r3, r4, r5, pc} */
/* @0x12bfb0 pop {r3, r4, r5, pc} */
/* @0x12bfb4 .word 0x002c1cf8 */

/* ── FUNC 0x12bfb8 · F_SpriteAddAlpha(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x12bfb8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x12bfbc sub sp, sp, #8 */
/* @0x12bfc0 mov r5, r0 */
/* @0x12bfc4 mov r1, #0 */
/* @0x12bfc8 ldr r4, [sp, #0x28] */
/* @0x12bfcc str r1, [r0, #0xc] */
/* @0x12bfd0 mov r0, r4 */
/* @0x12bfd4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x12bfd8 mov r1, #1 */
/* @0x12bfdc mov r6, r0 */
/* @0x12bfe0 mov r0, r4 */
/* @0x12bfe4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bfe8 mov r1, #2 */
/* @0x12bfec mov r9, r0 */
/* @0x12bff0 mov r0, r4 */
/* @0x12bff4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12bff8 mov r1, #3 */
/* @0x12bffc mov r8, r0 */
/* @0x12c000 mov r0, r4 */
/* @0x12c004 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x12c008 mov r1, #4 */
/* @0x12c00c mov r7, r0 */
/* @0x12c010 mov r0, r4 */
/* @0x12c014 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c018 mov r1, #5 */
/* @0x12c01c mov r10, r0 */
/* @0x12c020 mov r0, r4 */
/* @0x12c024 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x12c028 cmp r8, #0 */
/* @0x12c02c mov r1, r9 */
/* @0x12c030 mov r3, r7 */
/* @0x12c034 movle r2, #0 */
/* @0x12c038 movgt r2, #1 */
/* @0x12c03c str r10, [sp] */
/* @0x12c040 str r0, [sp, #0x4] */
/* @0x12c044 mov r0, r6 */
/* @0x12c048 bl 0x1f03cc <_Z16Sprite_Add_AlphaPKcibbii> */
/* @0x12c04c vmov s15, r0 */
/* @0x12c050 vcvt.f64.s32 d7, s15 */
/* @0x12c054 vmov r0, r1, d7 */
/* @0x12c058 vmov r2, s14 */
/* @0x12c05c mov r3, r1 */
/* @0x12c060 stm r5, {r2, r3} */
/* @0x12c064 add sp, sp, #8 */
/* @0x12c068 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
