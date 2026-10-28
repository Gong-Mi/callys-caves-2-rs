/* libyoyo.so 覆盖卡组 0145
 * 函数 0x1b5f44..0x1b6e44，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1b5f44 · ObjectPool<CLayerBackgroundElement>::~ObjectPool() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1b5fec · ObjectPool<CLayerInstanceElement>::~ObjectPool() · size=168 · insn=42 */
/* @0x1b5fec push {r3, r4, r5, lr} */
/* @0x1b5ff0 mov r5, r0 */
/* @0x1b5ff4 ldr r3, [r0, #0xc] */
/* @0x1b5ff8 cmp r3, #0 */
/* @0x1b5ffc beq 0x1b6034 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x48> */
/* @0x1b6000 ldr r0, [r0] */
/* @0x1b6004 cmp r0, #0 */
/* @0x1b6008 beq 0x1b6034 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x48> */
/* @0x1b600c cmp r3, #2 */
/* @0x1b6010 beq 0x1b604c <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x60> */
/* @0x1b6014 cmp r3, #3 */
/* @0x1b6018 beq 0x1b6064 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x78> */
/* @0x1b601c cmp r3, #1 */
/* @0x1b6020 beq 0x1b607c <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x90> */
/* @0x1b6024 ldr r4, [r0, #0x14] */
/* @0x1b6028 cmp r4, #0 */
/* @0x1b602c mov r0, r4 */
/* @0x1b6030 bne 0x1b6024 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x38> */
/* @0x1b6034 mov r3, #0 */
/* @0x1b6038 mov r0, r5 */
/* @0x1b603c str r3, [r5, #0x8] */
/* @0x1b6040 str r3, [r5, #0x4] */
/* @0x1b6044 str r3, [r5] */
/* @0x1b6048 pop {r3, r4, r5, pc} */
/* @0x1b604c ldr r4, [r0, #0x14] */
/* @0x1b6050 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6054 cmp r4, #0 */
/* @0x1b6058 mov r0, r4 */
/* @0x1b605c bne 0x1b604c <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x60> */
/* @0x1b6060 b 0x1b6034 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x48> */
/* @0x1b6064 ldr r4, [r0, #0x14] */
/* @0x1b6068 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b606c cmp r4, #0 */
/* @0x1b6070 mov r0, r4 */
/* @0x1b6074 bne 0x1b6064 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x78> */
/* @0x1b6078 b 0x1b6034 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x48> */
/* @0x1b607c ldr r4, [r0, #0x14] */
/* @0x1b6080 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b6084 cmp r4, #0 */
/* @0x1b6088 mov r0, r4 */
/* @0x1b608c bne 0x1b607c <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x90> */
/* @0x1b6090 b 0x1b6034 <_ZN10ObjectPoolI21CLayerInstanceElementED2Ev+0x48> */

/* ── FUNC 0x1b5fec · ObjectPool<CLayerInstanceElement>::~ObjectPool() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1b6094 · ObjectPool<CLayerSpriteElement>::~ObjectPool() · size=168 · insn=42 */
/* @0x1b6094 push {r3, r4, r5, lr} */
/* @0x1b6098 mov r5, r0 */
/* @0x1b609c ldr r3, [r0, #0xc] */
/* @0x1b60a0 cmp r3, #0 */
/* @0x1b60a4 beq 0x1b60dc <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x48> */
/* @0x1b60a8 ldr r0, [r0] */
/* @0x1b60ac cmp r0, #0 */
/* @0x1b60b0 beq 0x1b60dc <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x48> */
/* @0x1b60b4 cmp r3, #2 */
/* @0x1b60b8 beq 0x1b60f4 <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x60> */
/* @0x1b60bc cmp r3, #3 */
/* @0x1b60c0 beq 0x1b610c <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x78> */
/* @0x1b60c4 cmp r3, #1 */
/* @0x1b60c8 beq 0x1b6124 <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x90> */
/* @0x1b60cc ldr r4, [r0, #0x14] */
/* @0x1b60d0 cmp r4, #0 */
/* @0x1b60d4 mov r0, r4 */
/* @0x1b60d8 bne 0x1b60cc <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x38> */
/* @0x1b60dc mov r3, #0 */
/* @0x1b60e0 mov r0, r5 */
/* @0x1b60e4 str r3, [r5, #0x8] */
/* @0x1b60e8 str r3, [r5, #0x4] */
/* @0x1b60ec str r3, [r5] */
/* @0x1b60f0 pop {r3, r4, r5, pc} */
/* @0x1b60f4 ldr r4, [r0, #0x14] */
/* @0x1b60f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b60fc cmp r4, #0 */
/* @0x1b6100 mov r0, r4 */
/* @0x1b6104 bne 0x1b60f4 <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x60> */
/* @0x1b6108 b 0x1b60dc <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x48> */
/* @0x1b610c ldr r4, [r0, #0x14] */
/* @0x1b6110 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6114 cmp r4, #0 */
/* @0x1b6118 mov r0, r4 */
/* @0x1b611c bne 0x1b610c <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x78> */
/* @0x1b6120 b 0x1b60dc <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x48> */
/* @0x1b6124 ldr r4, [r0, #0x14] */
/* @0x1b6128 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b612c cmp r4, #0 */
/* @0x1b6130 mov r0, r4 */
/* @0x1b6134 bne 0x1b6124 <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x90> */
/* @0x1b6138 b 0x1b60dc <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x48> */

/* ── FUNC 0x1b6094 · ObjectPool<CLayerSpriteElement>::~ObjectPool() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1b613c · ObjectPool<CLayerTilemapElement>::~ObjectPool() · size=168 · insn=42 */
/* @0x1b613c push {r3, r4, r5, lr} */
/* @0x1b6140 mov r5, r0 */
/* @0x1b6144 ldr r3, [r0, #0xc] */
/* @0x1b6148 cmp r3, #0 */
/* @0x1b614c beq 0x1b6184 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x48> */
/* @0x1b6150 ldr r0, [r0] */
/* @0x1b6154 cmp r0, #0 */
/* @0x1b6158 beq 0x1b6184 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x48> */
/* @0x1b615c cmp r3, #2 */
/* @0x1b6160 beq 0x1b619c <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x60> */
/* @0x1b6164 cmp r3, #3 */
/* @0x1b6168 beq 0x1b61b4 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x78> */
/* @0x1b616c cmp r3, #1 */
/* @0x1b6170 beq 0x1b61cc <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x90> */
/* @0x1b6174 ldr r4, [r0, #0x14] */
/* @0x1b6178 cmp r4, #0 */
/* @0x1b617c mov r0, r4 */
/* @0x1b6180 bne 0x1b6174 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x38> */
/* @0x1b6184 mov r3, #0 */
/* @0x1b6188 mov r0, r5 */
/* @0x1b618c str r3, [r5, #0x8] */
/* @0x1b6190 str r3, [r5, #0x4] */
/* @0x1b6194 str r3, [r5] */
/* @0x1b6198 pop {r3, r4, r5, pc} */
/* @0x1b619c ldr r4, [r0, #0x14] */
/* @0x1b61a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b61a4 cmp r4, #0 */
/* @0x1b61a8 mov r0, r4 */
/* @0x1b61ac bne 0x1b619c <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x60> */
/* @0x1b61b0 b 0x1b6184 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x48> */
/* @0x1b61b4 ldr r4, [r0, #0x14] */
/* @0x1b61b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b61bc cmp r4, #0 */
/* @0x1b61c0 mov r0, r4 */
/* @0x1b61c4 bne 0x1b61b4 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x78> */
/* @0x1b61c8 b 0x1b6184 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x48> */
/* @0x1b61cc ldr r4, [r0, #0x14] */
/* @0x1b61d0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b61d4 cmp r4, #0 */
/* @0x1b61d8 mov r0, r4 */
/* @0x1b61dc bne 0x1b61cc <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x90> */
/* @0x1b61e0 b 0x1b6184 <_ZN10ObjectPoolI20CLayerTilemapElementED2Ev+0x48> */

/* ── FUNC 0x1b613c · ObjectPool<CLayerTilemapElement>::~ObjectPool() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1b61e4 · ObjectPool<CLayerParticleElement>::~ObjectPool() · size=168 · insn=42 */
/* @0x1b61e4 push {r3, r4, r5, lr} */
/* @0x1b61e8 mov r5, r0 */
/* @0x1b61ec ldr r3, [r0, #0xc] */
/* @0x1b61f0 cmp r3, #0 */
/* @0x1b61f4 beq 0x1b622c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x48> */
/* @0x1b61f8 ldr r0, [r0] */
/* @0x1b61fc cmp r0, #0 */
/* @0x1b6200 beq 0x1b622c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x48> */
/* @0x1b6204 cmp r3, #2 */
/* @0x1b6208 beq 0x1b6244 <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x60> */
/* @0x1b620c cmp r3, #3 */
/* @0x1b6210 beq 0x1b625c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x78> */
/* @0x1b6214 cmp r3, #1 */
/* @0x1b6218 beq 0x1b6274 <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x90> */
/* @0x1b621c ldr r4, [r0, #0x14] */
/* @0x1b6220 cmp r4, #0 */
/* @0x1b6224 mov r0, r4 */
/* @0x1b6228 bne 0x1b621c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x38> */
/* @0x1b622c mov r3, #0 */
/* @0x1b6230 mov r0, r5 */
/* @0x1b6234 str r3, [r5, #0x8] */
/* @0x1b6238 str r3, [r5, #0x4] */
/* @0x1b623c str r3, [r5] */
/* @0x1b6240 pop {r3, r4, r5, pc} */
/* @0x1b6244 ldr r4, [r0, #0x14] */
/* @0x1b6248 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b624c cmp r4, #0 */
/* @0x1b6250 mov r0, r4 */
/* @0x1b6254 bne 0x1b6244 <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x60> */
/* @0x1b6258 b 0x1b622c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x48> */
/* @0x1b625c ldr r4, [r0, #0x14] */
/* @0x1b6260 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6264 cmp r4, #0 */
/* @0x1b6268 mov r0, r4 */
/* @0x1b626c bne 0x1b625c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x78> */
/* @0x1b6270 b 0x1b622c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x48> */
/* @0x1b6274 ldr r4, [r0, #0x14] */
/* @0x1b6278 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b627c cmp r4, #0 */
/* @0x1b6280 mov r0, r4 */
/* @0x1b6284 bne 0x1b6274 <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x90> */
/* @0x1b6288 b 0x1b622c <_ZN10ObjectPoolI21CLayerParticleElementED2Ev+0x48> */

/* ── FUNC 0x1b61e4 · ObjectPool<CLayerParticleElement>::~ObjectPool() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1b628c · ObjectPool<CLayerTileElement>::~ObjectPool() · size=168 · insn=42 */
/* @0x1b628c push {r3, r4, r5, lr} */
/* @0x1b6290 mov r5, r0 */
/* @0x1b6294 ldr r3, [r0, #0xc] */
/* @0x1b6298 cmp r3, #0 */
/* @0x1b629c beq 0x1b62d4 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x48> */
/* @0x1b62a0 ldr r0, [r0] */
/* @0x1b62a4 cmp r0, #0 */
/* @0x1b62a8 beq 0x1b62d4 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x48> */
/* @0x1b62ac cmp r3, #2 */
/* @0x1b62b0 beq 0x1b62ec <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x60> */
/* @0x1b62b4 cmp r3, #3 */
/* @0x1b62b8 beq 0x1b6304 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x78> */
/* @0x1b62bc cmp r3, #1 */
/* @0x1b62c0 beq 0x1b631c <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x90> */
/* @0x1b62c4 ldr r4, [r0, #0x14] */
/* @0x1b62c8 cmp r4, #0 */
/* @0x1b62cc mov r0, r4 */
/* @0x1b62d0 bne 0x1b62c4 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x38> */
/* @0x1b62d4 mov r3, #0 */
/* @0x1b62d8 mov r0, r5 */
/* @0x1b62dc str r3, [r5, #0x8] */
/* @0x1b62e0 str r3, [r5, #0x4] */
/* @0x1b62e4 str r3, [r5] */
/* @0x1b62e8 pop {r3, r4, r5, pc} */
/* @0x1b62ec ldr r4, [r0, #0x14] */
/* @0x1b62f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b62f4 cmp r4, #0 */
/* @0x1b62f8 mov r0, r4 */
/* @0x1b62fc bne 0x1b62ec <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x60> */
/* @0x1b6300 b 0x1b62d4 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x48> */
/* @0x1b6304 ldr r4, [r0, #0x14] */
/* @0x1b6308 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b630c cmp r4, #0 */
/* @0x1b6310 mov r0, r4 */
/* @0x1b6314 bne 0x1b6304 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x78> */
/* @0x1b6318 b 0x1b62d4 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x48> */
/* @0x1b631c ldr r4, [r0, #0x14] */
/* @0x1b6320 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b6324 cmp r4, #0 */
/* @0x1b6328 mov r0, r4 */
/* @0x1b632c bne 0x1b631c <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x90> */
/* @0x1b6330 b 0x1b62d4 <_ZN10ObjectPoolI17CLayerTileElementED2Ev+0x48> */

/* ── FUNC 0x1b628c · ObjectPool<CLayerTileElement>::~ObjectPool() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1b6334 · F_LayerSetTargetRoom(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1b6334 push {r3, lr} */
/* @0x1b6338 mov r1, #0 */
/* @0x1b633c ldr r0, [sp, #0x8] */
/* @0x1b6340 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b6344 ldr r3, [pc, #0x8] */
/* @0x1b6348 ldr r3, [pc, r3] */
/* @0x1b634c str r0, [r3] */
/* @0x1b6350 pop {r3, pc} */
/* @0x1b6354 eoreq r10, r3, r12, lsl #10 */

/* ── FUNC 0x1b6358 · F_TileSetEmpty(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x1b6358 cmp r3, #1 */
/* @0x1b635c mov r3, #0 */
/* @0x1b6360 push {r4, lr} */
/* @0x1b6364 mov r1, r3 */
/* @0x1b6368 mov r4, r0 */
/* @0x1b636c movt r3, #0xbff0 */
/* @0x1b6370 str r1, [r0, #0xc] */
/* @0x1b6374 stm r0, {r1, r3} */
/* @0x1b6378 ldr r0, [sp, #0x8] */
/* @0x1b637c beq 0x1b6390 <_Z14F_TileSetEmptyR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1b6380 ldr r0, [pc, #0x28] */
/* @0x1b6384 pop {r4, lr} */
/* @0x1b6388 add r0, pc, r0 */
/* @0x1b638c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b6390 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b6394 lsr r0, r0, #19 */
/* @0x1b6398 lsl r2, r0, #19 */
/* @0x1b639c vmov s15, r2 */
/* @0x1b63a0 vcvt.f64.s32 d7, s15 */
/* @0x1b63a4 vmov r2, r3, d7 */
/* @0x1b63a8 stm r4, {r2, r3} */
/* @0x1b63ac pop {r4, pc} */
/* @0x1b63b0 andseq r7, r9, r8, lsl r0 */

/* ── FUNC 0x1b63b4 · F_TileSetIndex(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x1b63b4 cmp r3, #2 */
/* @0x1b63b8 mov r3, #0 */
/* @0x1b63bc push {r4, r5, r6, lr} */
/* @0x1b63c0 mov r1, r3 */
/* @0x1b63c4 mov r4, r0 */
/* @0x1b63c8 movt r3, #0xbff0 */
/* @0x1b63cc str r1, [r0, #0xc] */
/* @0x1b63d0 stm r0, {r1, r3} */
/* @0x1b63d4 ldr r5, [sp, #0x10] */
/* @0x1b63d8 beq 0x1b63ec <_Z14F_TileSetIndexR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1b63dc ldr r0, [pc, #0x3c] */
/* @0x1b63e0 pop {r4, r5, r6, lr} */
/* @0x1b63e4 add r0, pc, r0 */
/* @0x1b63e8 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b63ec mov r0, r5 */
/* @0x1b63f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b63f4 mov r1, #1 */
/* @0x1b63f8 mov r6, r0 */
/* @0x1b63fc mov r0, r5 */
/* @0x1b6400 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b6404 lsr r6, r6, #19 */
/* @0x1b6408 orr r0, r0, r6, lsl #19 */
/* @0x1b640c vmov s15, r0 */
/* @0x1b6410 vcvt.f64.s32 d7, s15 */
/* @0x1b6414 vmov r2, r3, d7 */
/* @0x1b6418 stm r4, {r2, r3} */
/* @0x1b641c pop {r4, r5, r6, pc} */
/* @0x1b6420 andseq r6, r9, r12, ror #31 */

/* ── FUNC 0x1b6424 · F_TileSetFlip(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1b6424 cmp r3, #2 */
/* @0x1b6428 mov r3, #0 */
/* @0x1b642c push {r4, r5, r6, lr} */
/* @0x1b6430 vpush {d8} */
/* @0x1b6434 mov r5, r3 */
/* @0x1b6438 mov r4, r0 */
/* @0x1b643c movt r3, #0xbff0 */
/* @0x1b6440 str r5, [r0, #0xc] */
/* @0x1b6444 str r3, [r0, #0x4] */
/* @0x1b6448 str r5, [r0] */
/* @0x1b644c ldr r6, [sp, #0x18] */
/* @0x1b6450 beq 0x1b646c <_Z13F_TileSetFlipR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1b6454 vpop {d8} */
/* @0x1b6458 mov r1, r5 */
/* @0x1b645c ldr r0, [pc, #0x50] */
/* @0x1b6460 add r0, pc, r0 */
/* @0x1b6464 pop {r4, r5, r6, lr} */
/* @0x1b6468 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b646c mov r1, #1 */
/* @0x1b6470 mov r0, r6 */
/* @0x1b6474 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1b6478 mov r1, r5 */
/* @0x1b647c vmov s16, r0 */
/* @0x1b6480 mov r0, r6 */
/* @0x1b6484 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b6488 vmov.f32 s15, #5.000000e-01 */
/* @0x1b648c vcmpe.f32 s16, s15 */
/* @0x1b6490 vmrs APSR_nzcv, fpscr */
/* @0x1b6494 orrgt r2, r0, #536870912 */
/* @0x1b6498 bicle r2, r0, #536870912 */
/* @0x1b649c vmov s15, r2 */
/* @0x1b64a0 vcvt.f64.s32 d7, s15 */
/* @0x1b64a4 vmov r2, r3, d7 */
/* @0x1b64a8 stm r4, {r2, r3} */
/* @0x1b64ac vpop {d8} */
/* @0x1b64b0 pop {r4, r5, r6, pc} */
/* @0x1b64b4 andseq r6, r9, r0, lsr #31 */

/* ── FUNC 0x1b64b8 · F_TileSetMirror(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1b64b8 cmp r3, #2 */
/* @0x1b64bc mov r3, #0 */
/* @0x1b64c0 push {r4, r5, r6, lr} */
/* @0x1b64c4 vpush {d8} */
/* @0x1b64c8 mov r5, r3 */
/* @0x1b64cc mov r4, r0 */
/* @0x1b64d0 movt r3, #0xbff0 */
/* @0x1b64d4 str r5, [r0, #0xc] */
/* @0x1b64d8 str r3, [r0, #0x4] */
/* @0x1b64dc str r5, [r0] */
/* @0x1b64e0 ldr r6, [sp, #0x18] */
/* @0x1b64e4 beq 0x1b6500 <_Z15F_TileSetMirrorR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1b64e8 vpop {d8} */
/* @0x1b64ec mov r1, r5 */
/* @0x1b64f0 ldr r0, [pc, #0x50] */
/* @0x1b64f4 add r0, pc, r0 */
/* @0x1b64f8 pop {r4, r5, r6, lr} */
/* @0x1b64fc b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b6500 mov r1, #1 */
/* @0x1b6504 mov r0, r6 */
/* @0x1b6508 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1b650c mov r1, r5 */
/* @0x1b6510 vmov s16, r0 */
/* @0x1b6514 mov r0, r6 */
/* @0x1b6518 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b651c vmov.f32 s15, #5.000000e-01 */
/* @0x1b6520 vcmpe.f32 s16, s15 */
/* @0x1b6524 vmrs APSR_nzcv, fpscr */
/* @0x1b6528 orrgt r2, r0, #268435456 */
/* @0x1b652c bicle r2, r0, #268435456 */
/* @0x1b6530 vmov s15, r2 */
/* @0x1b6534 vcvt.f64.s32 d7, s15 */
/* @0x1b6538 vmov r2, r3, d7 */
/* @0x1b653c stm r4, {r2, r3} */
/* @0x1b6540 vpop {d8} */
/* @0x1b6544 pop {r4, r5, r6, pc} */
/* @0x1b6548 andseq r6, r9, r8, lsr pc */

/* ── FUNC 0x1b654c · F_TileSetRotate(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1b654c cmp r3, #2 */
/* @0x1b6550 mov r3, #0 */
/* @0x1b6554 push {r4, r5, r6, lr} */
/* @0x1b6558 vpush {d8} */
/* @0x1b655c mov r5, r3 */
/* @0x1b6560 mov r4, r0 */
/* @0x1b6564 movt r3, #0xbff0 */
/* @0x1b6568 str r5, [r0, #0xc] */
/* @0x1b656c str r3, [r0, #0x4] */
/* @0x1b6570 str r5, [r0] */
/* @0x1b6574 ldr r6, [sp, #0x18] */
/* @0x1b6578 beq 0x1b6594 <_Z15F_TileSetRotateR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1b657c vpop {d8} */
/* @0x1b6580 mov r1, r5 */
/* @0x1b6584 ldr r0, [pc, #0x50] */
/* @0x1b6588 add r0, pc, r0 */
/* @0x1b658c pop {r4, r5, r6, lr} */
/* @0x1b6590 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b6594 mov r1, #1 */
/* @0x1b6598 mov r0, r6 */
/* @0x1b659c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1b65a0 mov r1, r5 */
/* @0x1b65a4 vmov s16, r0 */
/* @0x1b65a8 mov r0, r6 */
/* @0x1b65ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b65b0 vmov.f32 s15, #5.000000e-01 */
/* @0x1b65b4 vcmpe.f32 s16, s15 */
/* @0x1b65b8 vmrs APSR_nzcv, fpscr */
/* @0x1b65bc orrgt r2, r0, #1073741824 */
/* @0x1b65c0 bicle r2, r0, #1073741824 */
/* @0x1b65c4 vmov s15, r2 */
/* @0x1b65c8 vcvt.f64.s32 d7, s15 */
/* @0x1b65cc vmov r2, r3, d7 */
/* @0x1b65d0 stm r4, {r2, r3} */
/* @0x1b65d4 vpop {d8} */
/* @0x1b65d8 pop {r4, r5, r6, pc} */
/* @0x1b65dc ldrsbeq r6, [r9], -r4 */

/* ── FUNC 0x1b65e0 · F_TilemapTileGetEmpty(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x1b65e0 cmp r3, #1 */
/* @0x1b65e4 push {r3, r4, r5, lr} */
/* @0x1b65e8 mov r3, #0 */
/* @0x1b65ec mov r5, r3 */
/* @0x1b65f0 mov r4, r0 */
/* @0x1b65f4 movt r3, #0xbff0 */
/* @0x1b65f8 str r5, [r0, #0xc] */
/* @0x1b65fc str r3, [r0, #0x4] */
/* @0x1b6600 str r5, [r0] */
/* @0x1b6604 ldr r0, [sp, #0x10] */
/* @0x1b6608 beq 0x1b6620 <_Z21F_TilemapTileGetEmptyR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1b660c ldr r0, [pc, #0x40] */
/* @0x1b6610 mov r1, r5 */
/* @0x1b6614 pop {r3, r4, r5, lr} */
/* @0x1b6618 add r0, pc, r0 */
/* @0x1b661c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b6620 str r5, [r4] */
/* @0x1b6624 mov r1, r5 */
/* @0x1b6628 str r5, [r4, #0x4] */
/* @0x1b662c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b6630 ubfx r0, r0, #0x0, #0x13 */
/* @0x1b6634 cmp r0, #0 */
/* @0x1b6638 moveq r3, #0 */
/* @0x1b663c movne r3, r5 */
/* @0x1b6640 movteq r3, #0x3ff0 */
/* @0x1b6644 moveq r5, r0 */
/* @0x1b6648 str r3, [r4, #0x4] */
/* @0x1b664c str r5, [r4] */
/* @0x1b6650 pop {r3, r4, r5, pc} */
/* @0x1b6654 andseq r6, r9, r4, ror lr */

/* ── FUNC 0x1b6658 · F_TilemapTileGetIndex(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x1b6658 cmp r3, #1 */
/* @0x1b665c mov r3, #0 */
/* @0x1b6660 push {r4, lr} */
/* @0x1b6664 mov r1, r3 */
/* @0x1b6668 mov r4, r0 */
/* @0x1b666c movt r3, #0xbff0 */
/* @0x1b6670 str r1, [r0, #0xc] */
/* @0x1b6674 stm r0, {r1, r3} */
/* @0x1b6678 ldr r0, [sp, #0x8] */
/* @0x1b667c beq 0x1b6690 <_Z21F_TilemapTileGetIndexR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x1b6680 ldr r0, [pc, #0x2c] */
/* @0x1b6684 pop {r4, lr} */
/* @0x1b6688 add r0, pc, r0 */
/* @0x1b668c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b6690 str r1, [r4] */
/* @0x1b6694 str r1, [r4, #0x4] */
/* @0x1b6698 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b669c ubfx r2, r0, #0x0, #0x13 */
/* @0x1b66a0 vmov s15, r2 */
/* @0x1b66a4 vcvt.f64.s32 d7, s15 */
/* @0x1b66a8 vmov r2, r3, d7 */
/* @0x1b66ac stm r4, {r2, r3} */
/* @0x1b66b0 pop {r4, pc} */
/* @0x1b66b4 andseq r6, r9, r12, lsr lr */

/* ── FUNC 0x1b66b8 · F_TilemapTileGetFlip(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x1b66b8 cmp r3, #1 */
/* @0x1b66bc push {r3, r4, r5, lr} */
/* @0x1b66c0 mov r3, #0 */
/* @0x1b66c4 mov r5, r3 */
/* @0x1b66c8 mov r4, r0 */
/* @0x1b66cc movt r3, #0xbff0 */
/* @0x1b66d0 str r5, [r0, #0xc] */
/* @0x1b66d4 str r3, [r0, #0x4] */
/* @0x1b66d8 str r5, [r0] */
/* @0x1b66dc ldr r0, [sp, #0x10] */
/* @0x1b66e0 beq 0x1b66f8 <_Z20F_TilemapTileGetFlipR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1b66e4 ldr r0, [pc, #0x3c] */
/* @0x1b66e8 mov r1, r5 */
/* @0x1b66ec pop {r3, r4, r5, lr} */
/* @0x1b66f0 add r0, pc, r0 */
/* @0x1b66f4 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b66f8 str r5, [r4] */
/* @0x1b66fc mov r1, r5 */
/* @0x1b6700 str r5, [r4, #0x4] */
/* @0x1b6704 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b6708 ands r0, r0, #536870912 */
/* @0x1b670c moveq r5, r0 */
/* @0x1b6710 movne r3, #0 */
/* @0x1b6714 moveq r3, r5 */
/* @0x1b6718 movtne r3, #0x3ff0 */
/* @0x1b671c str r5, [r4] */
/* @0x1b6720 str r3, [r4, #0x4] */
/* @0x1b6724 pop {r3, r4, r5, pc} */
/* @0x1b6728 andseq r6, r9, r12, lsl #28 */

/* ── FUNC 0x1b672c · F_TilemapTileGetMirror(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x1b672c cmp r3, #1 */
/* @0x1b6730 push {r3, r4, r5, lr} */
/* @0x1b6734 mov r3, #0 */
/* @0x1b6738 mov r5, r3 */
/* @0x1b673c mov r4, r0 */
/* @0x1b6740 movt r3, #0xbff0 */
/* @0x1b6744 str r5, [r0, #0xc] */
/* @0x1b6748 str r3, [r0, #0x4] */
/* @0x1b674c str r5, [r0] */
/* @0x1b6750 ldr r0, [sp, #0x10] */
/* @0x1b6754 beq 0x1b676c <_Z22F_TilemapTileGetMirrorR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1b6758 ldr r0, [pc, #0x3c] */
/* @0x1b675c mov r1, r5 */
/* @0x1b6760 pop {r3, r4, r5, lr} */
/* @0x1b6764 add r0, pc, r0 */
/* @0x1b6768 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b676c str r5, [r4] */
/* @0x1b6770 mov r1, r5 */
/* @0x1b6774 str r5, [r4, #0x4] */
/* @0x1b6778 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b677c ands r0, r0, #268435456 */
/* @0x1b6780 moveq r5, r0 */
/* @0x1b6784 movne r3, #0 */
/* @0x1b6788 moveq r3, r5 */
/* @0x1b678c movtne r3, #0x3ff0 */
/* @0x1b6790 str r5, [r4] */
/* @0x1b6794 str r3, [r4, #0x4] */
/* @0x1b6798 pop {r3, r4, r5, pc} */
/* @0x1b679c andseq r6, r9, r12, asr #27 */

/* ── FUNC 0x1b67a0 · F_TilemapTileGetRotate(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x1b67a0 cmp r3, #1 */
/* @0x1b67a4 push {r3, r4, r5, lr} */
/* @0x1b67a8 mov r3, #0 */
/* @0x1b67ac mov r5, r3 */
/* @0x1b67b0 mov r4, r0 */
/* @0x1b67b4 movt r3, #0xbff0 */
/* @0x1b67b8 str r5, [r0, #0xc] */
/* @0x1b67bc str r3, [r0, #0x4] */
/* @0x1b67c0 str r5, [r0] */
/* @0x1b67c4 ldr r0, [sp, #0x10] */
/* @0x1b67c8 beq 0x1b67e0 <_Z22F_TilemapTileGetRotateR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x1b67cc ldr r0, [pc, #0x3c] */
/* @0x1b67d0 mov r1, r5 */
/* @0x1b67d4 pop {r3, r4, r5, lr} */
/* @0x1b67d8 add r0, pc, r0 */
/* @0x1b67dc b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b67e0 str r5, [r4] */
/* @0x1b67e4 mov r1, r5 */
/* @0x1b67e8 str r5, [r4, #0x4] */
/* @0x1b67ec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b67f0 ands r0, r0, #1073741824 */
/* @0x1b67f4 moveq r5, r0 */
/* @0x1b67f8 movne r3, #0 */
/* @0x1b67fc moveq r3, r5 */
/* @0x1b6800 movtne r3, #0x3ff0 */
/* @0x1b6804 str r5, [r4] */
/* @0x1b6808 str r3, [r4, #0x4] */
/* @0x1b680c pop {r3, r4, r5, pc} */
/* @0x1b6810 mulseq r9, r0, sp */

/* ── FUNC 0x1b6814 · F_TilemapSetGlobalMask(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x1b6814 cmp r3, #1 */
/* @0x1b6818 push {r3, lr} */
/* @0x1b681c mov r3, #0 */
/* @0x1b6820 mov r1, r3 */
/* @0x1b6824 movt r3, #0xbff0 */
/* @0x1b6828 str r1, [r0, #0xc] */
/* @0x1b682c stm r0, {r1, r3} */
/* @0x1b6830 ldr r0, [sp, #0x8] */
/* @0x1b6834 beq 0x1b6848 <_Z22F_TilemapSetGlobalMaskR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x1b6838 ldr r0, [pc, #0x1c] */
/* @0x1b683c pop {r3, lr} */
/* @0x1b6840 add r0, pc, r0 */
/* @0x1b6844 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b6848 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x1b684c ldr r3, [pc, #0xc] */
/* @0x1b6850 ldr r3, [pc, r3] */
/* @0x1b6854 str r0, [r3] */
/* @0x1b6858 pop {r3, pc} */
/* @0x1b685c andseq r6, r9, r0, ror #26 */
/* @0x1b6860 eoreq r9, r3, r8, asr #31 */

/* ── FUNC 0x1b6864 · F_LayerForceDrawDepth(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x1b6864 cmp r3, #2 */
/* @0x1b6868 push {r4, lr} */
/* @0x1b686c ldr r4, [sp, #0x8] */
/* @0x1b6870 beq 0x1b6888 <_Z21F_LayerForceDrawDepthR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x1b6874 ldr r0, [pc, #0x40] */
/* @0x1b6878 mov r1, #0 */
/* @0x1b687c pop {r4, lr} */
/* @0x1b6880 add r0, pc, r0 */
/* @0x1b6884 b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b6888 mov r1, #0 */
/* @0x1b688c mov r0, r4 */
/* @0x1b6890 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1b6894 ldr r3, [pc, #0x24] */
/* @0x1b6898 mov r1, #1 */
/* @0x1b689c ldr r3, [pc, r3] */
/* @0x1b68a0 strb r0, [r3] */
/* @0x1b68a4 mov r0, r4 */
/* @0x1b68a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b68ac ldr r3, [pc, #0x10] */
/* @0x1b68b0 ldr r3, [pc, r3] */
/* @0x1b68b4 str r0, [r3] */
/* @0x1b68b8 pop {r4, pc} */
/* @0x1b68bc andseq r6, r9, r8, asr sp */
/* @0x1b68c0 mlaeq r3, r4, pc, r9 */
/* @0x1b68c4 eoreq r9, r3, r4, lsl #31 */

/* ── FUNC 0x1b68c8 · F_DrawTile(RValue&, CInstance*, CInstance*, int, RValue*) · size=300 · insn=75 */
/* @0x1b68c8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1b68cc cmp r3, #5 */
/* @0x1b68d0 sub sp, sp, #16 */
/* @0x1b68d4 ldr r4, [pc, #0x100] */
/* @0x1b68d8 mov r2, #0 */
/* @0x1b68dc mov r6, r1 */
/* @0x1b68e0 add r4, pc, r4 */
/* @0x1b68e4 mov r1, r2 */
/* @0x1b68e8 movt r2, #0xbff0 */
/* @0x1b68ec str r1, [r0, #0xc] */
/* @0x1b68f0 stm r0, {r1, r2} */
/* @0x1b68f4 ldr r5, [sp, #0x30] */
/* @0x1b68f8 beq 0x1b6910 <_Z10F_DrawTileR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1b68fc ldr r0, [pc, #0xdc] */
/* @0x1b6900 add r0, pc, r0 */
/* @0x1b6904 add sp, sp, #16 */
/* @0x1b6908 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1b690c b 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1b6910 mov r0, r5 */
/* @0x1b6914 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b6918 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1b691c subs r7, r0, #0 */
/* @0x1b6920 beq 0x1b69cc <_Z10F_DrawTileR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x1b6924 mov r0, r5 */
/* @0x1b6928 mov r1, #1 */
/* @0x1b692c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b6930 ldr r3, [r7, #0x34] */
/* @0x1b6934 ubfx r2, r0, #0x0, #0x13 */
/* @0x1b6938 mov r8, r0 */
/* @0x1b693c cmp r2, r3 */
/* @0x1b6940 blt 0x1b696c <_Z10F_DrawTileR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x1b6944 ldr r1, [pc, #0x98] */
/* @0x1b6948 ldr r3, [pc, #0x98] */
/* @0x1b694c add r1, pc, r1 */
/* @0x1b6950 ldr r3, [r4, r3] */
/* @0x1b6954 ldr r0, [r3] */
/* @0x1b6958 ldr r3, [r0] */
/* @0x1b695c ldr r3, [r3, #0xc] */
/* @0x1b6960 blx r3 */
/* @0x1b6964 add sp, sp, #16 */
/* @0x1b6968 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b696c mov r0, r5 */
/* @0x1b6970 mov r1, #2 */
/* @0x1b6974 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1b6978 mov r1, #3 */
/* @0x1b697c mov r10, r0 */
/* @0x1b6980 mov r0, r5 */
/* @0x1b6984 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1b6988 mov r1, #4 */
/* @0x1b698c mov r9, r0 */
/* @0x1b6990 mov r0, r5 */
/* @0x1b6994 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1b6998 ldr r12, [pc, #0x4c] */
/* @0x1b699c ldr lr, [r6, #0x180] */
/* @0x1b69a0 mov r3, r10 */
/* @0x1b69a4 mov r1, r7 */
/* @0x1b69a8 mov r2, r8 */
/* @0x1b69ac ldr r12, [r4, r12] */
/* @0x1b69b0 str r9, [sp] */
/* @0x1b69b4 str lr, [sp, #0x8] */
/* @0x1b69b8 str r0, [sp, #0x4] */
/* @0x1b69bc mov r0, r12 */
/* @0x1b69c0 bl 0x1b1d08 <_Z8DrawTileP9tagYYRECTP11CBackgroundjifff> */
/* @0x1b69c4 add sp, sp, #16 */
/* @0x1b69c8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1b69cc ldr r1, [pc, #0x1c] */
/* @0x1b69d0 ldr r3, [pc, #0x10] */
/* @0x1b69d4 add r1, pc, r1 */
/* @0x1b69d8 b 0x1b6950 <_Z10F_DrawTileR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1b69dc eoreq r11, r3, r0, ror r3 */
/* @0x1b69e0 andseq r6, r9, r8, lsl #26 */
/* @0x1b69e4 andseq r6, r9, r4, lsl sp */
/* @0x1b69e8 .word 0xffffbac4 */
/* @0x1b69ec .word 0xffffe4fc */
/* @0x1b69f0 andseq r6, r9, r12, asr r12 */

/* ── FUNC 0x1b69f4 · ObjectPool<CTileSlab>::~ObjectPool() · size=168 · insn=42 */
/* @0x1b69f4 push {r3, r4, r5, lr} */
/* @0x1b69f8 mov r5, r0 */
/* @0x1b69fc ldr r3, [r0, #0xc] */
/* @0x1b6a00 cmp r3, #0 */
/* @0x1b6a04 beq 0x1b6a3c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x48> */
/* @0x1b6a08 ldr r0, [r0] */
/* @0x1b6a0c cmp r0, #0 */
/* @0x1b6a10 beq 0x1b6a3c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x48> */
/* @0x1b6a14 cmp r3, #2 */
/* @0x1b6a18 beq 0x1b6a54 <_ZN10ObjectPoolI9CTileSlabED2Ev+0x60> */
/* @0x1b6a1c cmp r3, #3 */
/* @0x1b6a20 beq 0x1b6a6c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x78> */
/* @0x1b6a24 cmp r3, #1 */
/* @0x1b6a28 beq 0x1b6a84 <_ZN10ObjectPoolI9CTileSlabED2Ev+0x90> */
/* @0x1b6a2c ldr r4, [r0, #0x704] */
/* @0x1b6a30 cmp r4, #0 */
/* @0x1b6a34 mov r0, r4 */
/* @0x1b6a38 bne 0x1b6a2c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x38> */
/* @0x1b6a3c mov r3, #0 */
/* @0x1b6a40 mov r0, r5 */
/* @0x1b6a44 str r3, [r5, #0x8] */
/* @0x1b6a48 str r3, [r5, #0x4] */
/* @0x1b6a4c str r3, [r5] */
/* @0x1b6a50 pop {r3, r4, r5, pc} */
/* @0x1b6a54 ldr r4, [r0, #0x704] */
/* @0x1b6a58 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6a5c cmp r4, #0 */
/* @0x1b6a60 mov r0, r4 */
/* @0x1b6a64 bne 0x1b6a54 <_ZN10ObjectPoolI9CTileSlabED2Ev+0x60> */
/* @0x1b6a68 b 0x1b6a3c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x48> */
/* @0x1b6a6c ldr r4, [r0, #0x704] */
/* @0x1b6a70 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6a74 cmp r4, #0 */
/* @0x1b6a78 mov r0, r4 */
/* @0x1b6a7c bne 0x1b6a6c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x78> */
/* @0x1b6a80 b 0x1b6a3c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x48> */
/* @0x1b6a84 ldr r4, [r0, #0x704] */
/* @0x1b6a88 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b6a8c cmp r4, #0 */
/* @0x1b6a90 mov r0, r4 */
/* @0x1b6a94 bne 0x1b6a84 <_ZN10ObjectPoolI9CTileSlabED2Ev+0x90> */
/* @0x1b6a98 b 0x1b6a3c <_ZN10ObjectPoolI9CTileSlabED2Ev+0x48> */

/* ── FUNC 0x1b69f4 · ObjectPool<CTileSlab>::~ObjectPool() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1b6a9c · ObjectPool<CLayer>::~ObjectPool() · size=496 · insn=124 */
/* @0x1b6a9c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1b6aa0 mov r9, r0 */
/* @0x1b6aa4 ldr r7, [r0, #0xc] */
/* @0x1b6aa8 cmp r7, #0 */
/* @0x1b6aac beq 0x1b6afc <_ZN10ObjectPoolI6CLayerED2Ev+0x60> */
/* @0x1b6ab0 ldr r4, [r0] */
/* @0x1b6ab4 cmp r4, #0 */
/* @0x1b6ab8 beq 0x1b6afc <_ZN10ObjectPoolI6CLayerED2Ev+0x60> */
/* @0x1b6abc mov r8, #0 */
/* @0x1b6ac0 b 0x1b6ae0 <_ZN10ObjectPoolI6CLayerED2Ev+0x44> */
/* @0x1b6ac4 cmp r7, #3 */
/* @0x1b6ac8 beq 0x1b6b14 <_ZN10ObjectPoolI6CLayerED2Ev+0x78> */
/* @0x1b6acc cmp r7, #1 */
/* @0x1b6ad0 beq 0x1b6bb8 <_ZN10ObjectPoolI6CLayerED2Ev+0x11c> */
/* @0x1b6ad4 cmp r6, #0 */
/* @0x1b6ad8 beq 0x1b6afc <_ZN10ObjectPoolI6CLayerED2Ev+0x60> */
/* @0x1b6adc mov r4, r6 */
/* @0x1b6ae0 cmp r7, #2 */
/* @0x1b6ae4 ldr r6, [r4, #0x68] */
/* @0x1b6ae8 bne 0x1b6ac4 <_ZN10ObjectPoolI6CLayerED2Ev+0x28> */
/* @0x1b6aec mov r0, r4 */
/* @0x1b6af0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6af4 cmp r6, #0 */
/* @0x1b6af8 bne 0x1b6adc <_ZN10ObjectPoolI6CLayerED2Ev+0x40> */
/* @0x1b6afc mov r3, #0 */
/* @0x1b6b00 mov r0, r9 */
/* @0x1b6b04 str r3, [r9, #0x8] */
/* @0x1b6b08 str r3, [r9, #0x4] */
/* @0x1b6b0c str r3, [r9] */
/* @0x1b6b10 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1b6b14 ldr r0, [r4, #0x1c] */
/* @0x1b6b18 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1b6b1c cmp r0, #0 */
/* @0x1b6b20 bne 0x1b6b2c <_ZN10ObjectPoolI6CLayerED2Ev+0x90> */
/* @0x1b6b24 ldr r0, [r4, #0x1c] */
/* @0x1b6b28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6b2c ldr r3, [r4, #0x64] */
/* @0x1b6b30 str r8, [r4, #0x1c] */
/* @0x1b6b34 cmp r3, #0 */
/* @0x1b6b38 beq 0x1b6b70 <_ZN10ObjectPoolI6CLayerED2Ev+0xd4> */
/* @0x1b6b3c ldr r0, [r4, #0x58] */
/* @0x1b6b40 cmp r0, #0 */
/* @0x1b6b44 beq 0x1b6b70 <_ZN10ObjectPoolI6CLayerED2Ev+0xd4> */
/* @0x1b6b48 cmp r3, #2 */
/* @0x1b6b4c beq 0x1b6b88 <_ZN10ObjectPoolI6CLayerED2Ev+0xec> */
/* @0x1b6b50 cmp r3, #3 */
/* @0x1b6b54 beq 0x1b6ba0 <_ZN10ObjectPoolI6CLayerED2Ev+0x104> */
/* @0x1b6b58 cmp r3, #1 */
/* @0x1b6b5c beq 0x1b6c74 <_ZN10ObjectPoolI6CLayerED2Ev+0x1d8> */
/* @0x1b6b60 ldr r5, [r0, #0x14] */
/* @0x1b6b64 cmp r5, #0 */
/* @0x1b6b68 mov r0, r5 */
/* @0x1b6b6c bne 0x1b6b60 <_ZN10ObjectPoolI6CLayerED2Ev+0xc4> */
/* @0x1b6b70 str r8, [r4, #0x60] */
/* @0x1b6b74 mov r0, r4 */
/* @0x1b6b78 str r8, [r4, #0x5c] */
/* @0x1b6b7c str r8, [r4, #0x58] */
/* @0x1b6b80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6b84 b 0x1b6ad4 <_ZN10ObjectPoolI6CLayerED2Ev+0x38> */
/* @0x1b6b88 ldr r5, [r0, #0x14] */
/* @0x1b6b8c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6b90 cmp r5, #0 */
/* @0x1b6b94 mov r0, r5 */
/* @0x1b6b98 bne 0x1b6b88 <_ZN10ObjectPoolI6CLayerED2Ev+0xec> */
/* @0x1b6b9c b 0x1b6b70 <_ZN10ObjectPoolI6CLayerED2Ev+0xd4> */
/* @0x1b6ba0 ldr r5, [r0, #0x14] */
/* @0x1b6ba4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6ba8 cmp r5, #0 */
/* @0x1b6bac mov r0, r5 */
/* @0x1b6bb0 bne 0x1b6ba0 <_ZN10ObjectPoolI6CLayerED2Ev+0x104> */
/* @0x1b6bb4 b 0x1b6b70 <_ZN10ObjectPoolI6CLayerED2Ev+0xd4> */
/* @0x1b6bb8 ldr r0, [r4, #0x1c] */
/* @0x1b6bbc bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1b6bc0 cmp r0, #0 */
/* @0x1b6bc4 bne 0x1b6bd0 <_ZN10ObjectPoolI6CLayerED2Ev+0x134> */
/* @0x1b6bc8 ldr r0, [r4, #0x1c] */
/* @0x1b6bcc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6bd0 ldr r3, [r4, #0x64] */
/* @0x1b6bd4 str r8, [r4, #0x1c] */
/* @0x1b6bd8 cmp r3, #0 */
/* @0x1b6bdc beq 0x1b6c14 <_ZN10ObjectPoolI6CLayerED2Ev+0x178> */
/* @0x1b6be0 ldr r0, [r4, #0x58] */
/* @0x1b6be4 cmp r0, #0 */
/* @0x1b6be8 beq 0x1b6c14 <_ZN10ObjectPoolI6CLayerED2Ev+0x178> */
/* @0x1b6bec cmp r3, #2 */
/* @0x1b6bf0 beq 0x1b6c2c <_ZN10ObjectPoolI6CLayerED2Ev+0x190> */
/* @0x1b6bf4 cmp r3, #3 */
/* @0x1b6bf8 beq 0x1b6c44 <_ZN10ObjectPoolI6CLayerED2Ev+0x1a8> */
/* @0x1b6bfc cmp r3, #1 */
/* @0x1b6c00 beq 0x1b6c5c <_ZN10ObjectPoolI6CLayerED2Ev+0x1c0> */
/* @0x1b6c04 ldr r5, [r0, #0x14] */
/* @0x1b6c08 cmp r5, #0 */
/* @0x1b6c0c mov r0, r5 */
/* @0x1b6c10 bne 0x1b6c04 <_ZN10ObjectPoolI6CLayerED2Ev+0x168> */
/* @0x1b6c14 str r8, [r4, #0x60] */
/* @0x1b6c18 mov r0, r4 */
/* @0x1b6c1c str r8, [r4, #0x5c] */
/* @0x1b6c20 str r8, [r4, #0x58] */
/* @0x1b6c24 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b6c28 b 0x1b6ad4 <_ZN10ObjectPoolI6CLayerED2Ev+0x38> */
/* @0x1b6c2c ldr r5, [r0, #0x14] */
/* @0x1b6c30 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6c34 cmp r5, #0 */
/* @0x1b6c38 mov r0, r5 */
/* @0x1b6c3c bne 0x1b6c2c <_ZN10ObjectPoolI6CLayerED2Ev+0x190> */
/* @0x1b6c40 b 0x1b6c14 <_ZN10ObjectPoolI6CLayerED2Ev+0x178> */
/* @0x1b6c44 ldr r5, [r0, #0x14] */
/* @0x1b6c48 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6c4c cmp r5, #0 */
/* @0x1b6c50 mov r0, r5 */
/* @0x1b6c54 bne 0x1b6c44 <_ZN10ObjectPoolI6CLayerED2Ev+0x1a8> */
/* @0x1b6c58 b 0x1b6c14 <_ZN10ObjectPoolI6CLayerED2Ev+0x178> */
/* @0x1b6c5c ldr r5, [r0, #0x14] */
/* @0x1b6c60 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b6c64 cmp r5, #0 */
/* @0x1b6c68 mov r0, r5 */
/* @0x1b6c6c bne 0x1b6c5c <_ZN10ObjectPoolI6CLayerED2Ev+0x1c0> */
/* @0x1b6c70 b 0x1b6c14 <_ZN10ObjectPoolI6CLayerED2Ev+0x178> */
/* @0x1b6c74 ldr r5, [r0, #0x14] */
/* @0x1b6c78 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b6c7c cmp r5, #0 */
/* @0x1b6c80 mov r0, r5 */
/* @0x1b6c84 bne 0x1b6c74 <_ZN10ObjectPoolI6CLayerED2Ev+0x1d8> */
/* @0x1b6c88 b 0x1b6b70 <_ZN10ObjectPoolI6CLayerED2Ev+0xd4> */

/* ── FUNC 0x1b6a9c · ObjectPool<CLayer>::~ObjectPool() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1b6c8c · ObjectPool<CLayerOldTilemapElement>::~ObjectPool() · size=440 · insn=110 */
/* @0x1b6c8c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1b6c90 mov r9, r0 */
/* @0x1b6c94 ldr r7, [r0, #0xc] */
/* @0x1b6c98 cmp r7, #0 */
/* @0x1b6c9c beq 0x1b6cec <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x60> */
/* @0x1b6ca0 ldr r4, [r0] */
/* @0x1b6ca4 cmp r4, #0 */
/* @0x1b6ca8 beq 0x1b6cec <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x60> */
/* @0x1b6cac mov r8, #0 */
/* @0x1b6cb0 b 0x1b6cd0 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x44> */
/* @0x1b6cb4 cmp r7, #3 */
/* @0x1b6cb8 beq 0x1b6d04 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x78> */
/* @0x1b6cbc cmp r7, #1 */
/* @0x1b6cc0 beq 0x1b6d8c <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x100> */
/* @0x1b6cc4 cmp r6, #0 */
/* @0x1b6cc8 beq 0x1b6cec <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x60> */
/* @0x1b6ccc mov r4, r6 */
/* @0x1b6cd0 cmp r7, #2 */
/* @0x1b6cd4 ldr r6, [r4, #0x14] */
/* @0x1b6cd8 bne 0x1b6cb4 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x28> */
/* @0x1b6cdc mov r0, r4 */
/* @0x1b6ce0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6ce4 cmp r6, #0 */
/* @0x1b6ce8 bne 0x1b6ccc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x40> */
/* @0x1b6cec mov r3, #0 */
/* @0x1b6cf0 mov r0, r9 */
/* @0x1b6cf4 str r3, [r9, #0x8] */
/* @0x1b6cf8 str r3, [r9, #0x4] */
/* @0x1b6cfc str r3, [r9] */
/* @0x1b6d00 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1b6d04 ldr r3, [r4, #0x30] */
/* @0x1b6d08 cmp r3, #0 */
/* @0x1b6d0c beq 0x1b6d44 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xb8> */
/* @0x1b6d10 ldr r0, [r4, #0x24] */
/* @0x1b6d14 cmp r0, #0 */
/* @0x1b6d18 beq 0x1b6d44 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xb8> */
/* @0x1b6d1c cmp r3, #2 */
/* @0x1b6d20 beq 0x1b6d5c <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xd0> */
/* @0x1b6d24 cmp r3, #3 */
/* @0x1b6d28 beq 0x1b6d74 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xe8> */
/* @0x1b6d2c cmp r3, #1 */
/* @0x1b6d30 beq 0x1b6e2c <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x1a0> */
/* @0x1b6d34 ldr r5, [r0, #0x704] */
/* @0x1b6d38 cmp r5, #0 */
/* @0x1b6d3c mov r0, r5 */
/* @0x1b6d40 bne 0x1b6d34 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xa8> */
/* @0x1b6d44 str r8, [r4, #0x2c] */
/* @0x1b6d48 mov r0, r4 */
/* @0x1b6d4c str r8, [r4, #0x28] */
/* @0x1b6d50 str r8, [r4, #0x24] */
/* @0x1b6d54 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6d58 b 0x1b6cc4 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x38> */
/* @0x1b6d5c ldr r5, [r0, #0x704] */
/* @0x1b6d60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6d64 cmp r5, #0 */
/* @0x1b6d68 mov r0, r5 */
/* @0x1b6d6c bne 0x1b6d5c <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xd0> */
/* @0x1b6d70 b 0x1b6d44 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xb8> */
/* @0x1b6d74 ldr r5, [r0, #0x704] */
/* @0x1b6d78 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6d7c cmp r5, #0 */
/* @0x1b6d80 mov r0, r5 */
/* @0x1b6d84 bne 0x1b6d74 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xe8> */
/* @0x1b6d88 b 0x1b6d44 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xb8> */
/* @0x1b6d8c ldr r3, [r4, #0x30] */
/* @0x1b6d90 cmp r3, #0 */
/* @0x1b6d94 beq 0x1b6dcc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x140> */
/* @0x1b6d98 ldr r0, [r4, #0x24] */
/* @0x1b6d9c cmp r0, #0 */
/* @0x1b6da0 beq 0x1b6dcc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x140> */
/* @0x1b6da4 cmp r3, #2 */
/* @0x1b6da8 beq 0x1b6de4 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x158> */
/* @0x1b6dac cmp r3, #3 */
/* @0x1b6db0 beq 0x1b6dfc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x170> */
/* @0x1b6db4 cmp r3, #1 */
/* @0x1b6db8 beq 0x1b6e14 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x188> */
/* @0x1b6dbc ldr r5, [r0, #0x704] */
/* @0x1b6dc0 cmp r5, #0 */
/* @0x1b6dc4 mov r0, r5 */
/* @0x1b6dc8 bne 0x1b6dbc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x130> */
/* @0x1b6dcc str r8, [r4, #0x2c] */
/* @0x1b6dd0 mov r0, r4 */
/* @0x1b6dd4 str r8, [r4, #0x28] */
/* @0x1b6dd8 str r8, [r4, #0x24] */
/* @0x1b6ddc bl 0x27d1d0 <_ZdlPv> */
/* @0x1b6de0 b 0x1b6cc4 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x38> */
/* @0x1b6de4 ldr r5, [r0, #0x704] */
/* @0x1b6de8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6dec cmp r5, #0 */
/* @0x1b6df0 mov r0, r5 */
/* @0x1b6df4 bne 0x1b6de4 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x158> */
/* @0x1b6df8 b 0x1b6dcc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x140> */
/* @0x1b6dfc ldr r5, [r0, #0x704] */
/* @0x1b6e00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b6e04 cmp r5, #0 */
/* @0x1b6e08 mov r0, r5 */
/* @0x1b6e0c bne 0x1b6dfc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x170> */
/* @0x1b6e10 b 0x1b6dcc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x140> */
/* @0x1b6e14 ldr r5, [r0, #0x704] */
/* @0x1b6e18 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b6e1c cmp r5, #0 */
/* @0x1b6e20 mov r0, r5 */
/* @0x1b6e24 bne 0x1b6e14 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x188> */
/* @0x1b6e28 b 0x1b6dcc <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x140> */
/* @0x1b6e2c ldr r5, [r0, #0x704] */
/* @0x1b6e30 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b6e34 cmp r5, #0 */
/* @0x1b6e38 mov r0, r5 */
/* @0x1b6e3c bne 0x1b6e2c <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0x1a0> */
/* @0x1b6e40 b 0x1b6d44 <_ZN10ObjectPoolI23CLayerOldTilemapElementED2Ev+0xb8> */

/* ── FUNC 0x1b6c8c · ObjectPool<CLayerOldTilemapElement>::~ObjectPool() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1b6e44 · CHashMapCalculateHash(int) · size=8 · insn=2 */
/* @0x1b6e44 add r0, r0, #1 */
/* @0x1b6e48 bx lr */
