/* libyoyo.so 覆盖卡组 0230
 * 函数 0x27d1e0..0x27e148，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x27d1e0 · MemoryManager::GetSize(void const*) · size=84 · insn=21 */
/* @0x27d1e0 push {r3, r4, r5, lr} */
/* @0x27d1e4 subs r5, r0, #0 */
/* @0x27d1e8 moveq r4, r5 */
/* @0x27d1ec beq 0x27d21c <_ZN13MemoryManager7GetSizeEPKv+0x3c> */
/* @0x27d1f0 ldr r4, [pc, #0x38] */
/* @0x27d1f4 ldr r4, [pc, r4] */
/* @0x27d1f8 ldr r3, [r4] */
/* @0x27d1fc cmp r3, #0 */
/* @0x27d200 movne r0, r3 */
/* @0x27d204 beq 0x27d224 <_ZN13MemoryManager7GetSizeEPKv+0x44> */
/* @0x27d208 bl 0x27e084 <_ZN5Mutex4LockEv> */
/* @0x27d20c ldr r3, [r5, #-0x10] */
/* @0x27d210 ldr r0, [r4] */
/* @0x27d214 bic r4, r3, #-2147483648 */
/* @0x27d218 bl 0x27e09c <_ZN5Mutex6UnlockEv> */
/* @0x27d21c mov r0, r4 */
/* @0x27d220 pop {r3, r4, r5, pc} */
/* @0x27d224 bl 0x27b918 <_ZN7CBucketILj8ELj131072ELb1EE4FreeEPKv+0x38> */
/* @0x27d228 ldr r0, [r4] */
/* @0x27d22c b 0x27d208 <_ZN13MemoryManager7GetSizeEPKv+0x28> */
/* @0x27d230 andseq r4, r7, r8, lsr #12 */

/* ── FUNC 0x27d234 · DisplayMemoryError(unsigned int, char const*) · size=4 · insn=1 */
/* @0x27d234 bx lr */

/* ── FUNC 0x27d238 · MemoryManager::CheckMemory() · size=4 · insn=1 */
/* @0x27d238 bx lr */

/* ── FUNC 0x27d23c · MemoryManager::Memory_Tick() · size=28 · insn=7 */
/* @0x27d23c ldr r3, [pc, #0x10] */
/* @0x27d240 ldr r3, [pc, r3] */
/* @0x27d244 ldr r2, [r3] */
/* @0x27d248 add r2, r2, #1 */
/* @0x27d24c str r2, [r3] */
/* @0x27d250 bx lr */
/* @0x27d254 andseq r4, r7, r12, lsl r6 */

/* ── FUNC 0x27d258 · MemoryManager::GetStackTrace() · size=8 · insn=2 */
/* @0x27d258 mov r0, #0 */
/* @0x27d25c bx lr */

/* ── FUNC 0x27d260 · CHashMap<char const*, int, 3>::Insert(char const*, int) · size=1640 · insn=410 */
/* @0x27d260 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x27d264 vpush {d8} */
/* @0x27d268 sub sp, sp, #60 */
/* @0x27d26c ldr r3, [r0, #0x4] */
/* @0x27d270 mov r11, r0 */
/* @0x27d274 str r2, [sp, #0x24] */
/* @0x27d278 ldr r2, [r0, #0xc] */
/* @0x27d27c str r1, [sp, #0x1c] */
/* @0x27d280 cmp r3, r2 */
/* @0x27d284 bgt 0x27d394 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x134> */
/* @0x27d288 add r3, r3, #1 */
/* @0x27d28c ldr r0, [sp, #0x1c] */
/* @0x27d290 str r3, [r11, #0x4] */
/* @0x27d294 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x27d298 ldr r4, [r11, #0x8] */
/* @0x27d29c ldr r6, [r11, #0x10] */
/* @0x27d2a0 bic r0, r0, #-2147483648 */
/* @0x27d2a4 and r3, r0, r4 */
/* @0x27d2a8 add r2, r3, r3, lsl #1 */
/* @0x27d2ac add r2, r6, r2, lsl #2 */
/* @0x27d2b0 ldr r12, [r2, #0x8] */
/* @0x27d2b4 cmp r12, #0 */
/* @0x27d2b8 beq 0x27d374 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x114> */
/* @0x27d2bc ldr r7, [r11] */
/* @0x27d2c0 mov r1, #0 */
/* @0x27d2c4 ldr r8, [sp, #0x1c] */
/* @0x27d2c8 ldr r9, [sp, #0x24] */
/* @0x27d2cc b 0x27d314 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0xb4> */
/* @0x27d2d0 ldr r10, [r2] */
/* @0x27d2d4 mov r1, r5 */
/* @0x27d2d8 ldr r5, [r2, #0x4] */
/* @0x27d2dc str r0, [r2, #0x8] */
/* @0x27d2e0 mov r0, r12 */
/* @0x27d2e4 str r8, [r2] */
/* @0x27d2e8 mov r8, r10 */
/* @0x27d2ec str r9, [r2, #0x4] */
/* @0x27d2f0 mov r9, r5 */
/* @0x27d2f4 add r3, r3, #1 */
/* @0x27d2f8 add r1, r1, #1 */
/* @0x27d2fc and r3, r3, r4 */
/* @0x27d300 add r2, r3, r3, lsl #1 */
/* @0x27d304 add r2, r6, r2, lsl #2 */
/* @0x27d308 ldr r12, [r2, #0x8] */
/* @0x27d30c cmp r12, #0 */
/* @0x27d310 beq 0x27d36c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x10c> */
/* @0x27d314 add r5, r7, r3 */
/* @0x27d318 and r10, r12, r4 */
/* @0x27d31c rsb r5, r10, r5 */
/* @0x27d320 and r5, r5, r4 */
/* @0x27d324 cmp r5, r1 */
/* @0x27d328 blt 0x27d2d0 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x70> */
/* @0x27d32c cmp r1, r5 */
/* @0x27d330 bne 0x27d2f4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x94> */
/* @0x27d334 cmp r0, r12 */
/* @0x27d338 bne 0x27d2f4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x94> */
/* @0x27d33c ldr r12, [r2] */
/* @0x27d340 cmp r8, r12 */
/* @0x27d344 bne 0x27d2f4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x94> */
/* @0x27d348 ldr r3, [r11, #0x4] */
/* @0x27d34c str r8, [sp, #0x1c] */
/* @0x27d350 str r8, [r2] */
/* @0x27d354 sub r3, r3, #1 */
/* @0x27d358 str r9, [r2, #0x4] */
/* @0x27d35c str r0, [r2, #0x8] */
/* @0x27d360 str r9, [sp, #0x24] */
/* @0x27d364 str r3, [r11, #0x4] */
/* @0x27d368 b 0x27d388 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x128> */
/* @0x27d36c str r8, [sp, #0x1c] */
/* @0x27d370 str r9, [sp, #0x24] */
/* @0x27d374 ldr r12, [sp, #0x1c] */
/* @0x27d378 str r0, [r2, #0x8] */
/* @0x27d37c str r12, [r2] */
/* @0x27d380 ldr r12, [sp, #0x24] */
/* @0x27d384 str r12, [r2, #0x4] */
/* @0x27d388 add sp, sp, #60 */
/* @0x27d38c vpop {d8} */
/* @0x27d390 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x27d394 ldr r12, [r0] */
/* @0x27d398 mov r3, #1 */
/* @0x27d39c ldr r1, [pc, #0x430] */
/* @0x27d3a0 mov r2, #70 */
/* @0x27d3a4 str r12, [sp, #0x20] */
/* @0x27d3a8 add r1, pc, r1 */
/* @0x27d3ac ldr r12, [r0, #0x10] */
/* @0x27d3b0 str r12, [sp, #0x30] */
/* @0x27d3b4 ldr r12, [sp, #0x20] */
/* @0x27d3b8 lsl r0, r12, r3 */
/* @0x27d3bc str r0, [r11] */
/* @0x27d3c0 add r4, r0, r12, lsl #2 */
/* @0x27d3c4 sub r0, r0, #1 */
/* @0x27d3c8 str r0, [r11, #0x8] */
/* @0x27d3cc lsl r4, r4, #2 */
/* @0x27d3d0 mov r0, r4 */
/* @0x27d3d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x27d3d8 mov r2, r4 */
/* @0x27d3dc mov r1, #0 */
/* @0x27d3e0 str r0, [r11, #0x10] */
/* @0x27d3e4 bl 0xb65b0 <memset@plt> */
/* @0x27d3e8 ldr r2, [r11] */
/* @0x27d3ec vldr s15, [pc, #988] */
/* @0x27d3f0 mov r1, #0 */
/* @0x27d3f4 cmp r2, r1 */
/* @0x27d3f8 str r1, [r11, #0x4] */
/* @0x27d3fc vmov s13, r2 */
/* @0x27d400 vcvt.f32.s32 s14, s13 */
/* @0x27d404 vmul.f32 s15, s14, s15 */
/* @0x27d408 vcvt.s32.f32 s15, s15 */
/* @0x27d40c vstr s15, [r11, #12] */
/* @0x27d410 ble 0x27d430 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x1d0> */
/* @0x27d414 add r2, r2, r2, lsl #1 */
/* @0x27d418 ldr r3, [r11, #0x10] */
/* @0x27d41c add r2, r3, r2, lsl #2 */
/* @0x27d420 str r1, [r3, #0x8] */
/* @0x27d424 add r3, r3, #12 */
/* @0x27d428 cmp r3, r2 */
/* @0x27d42c bne 0x27d420 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x1c0> */
/* @0x27d430 ldr r12, [sp, #0x20] */
/* @0x27d434 cmp r12, #0 */
/* @0x27d438 ble 0x27d5a0 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x340> */
/* @0x27d43c ldr r12, [pc, #0x394] */
/* @0x27d440 vldr s16, [pc, #904] */
/* @0x27d444 add r12, pc, r12 */
/* @0x27d448 str r12, [sp, #0x34] */
/* @0x27d44c mov r12, #0 */
/* @0x27d450 str r12, [sp, #0xc] */
/* @0x27d454 ldr r12, [pc, #0x380] */
/* @0x27d458 add r12, pc, r12 */
/* @0x27d45c str r12, [sp, #0x2c] */
/* @0x27d460 ldr r12, [sp, #0x30] */
/* @0x27d464 str r12, [sp, #0x8] */
/* @0x27d468 ldr r12, [sp, #0x8] */
/* @0x27d46c ldr r3, [r12, #0x8] */
/* @0x27d470 cmp r3, #0 */
/* @0x27d474 ble 0x27d578 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x318> */
/* @0x27d478 ldr r12, [r12] */
/* @0x27d47c ldr r3, [r11, #0x4] */
/* @0x27d480 ldr r2, [r11, #0xc] */
/* @0x27d484 str r12, [sp, #0x10] */
/* @0x27d488 ldr r12, [sp, #0x8] */
/* @0x27d48c cmp r3, r2 */
/* @0x27d490 ldr r12, [r12, #0x4] */
/* @0x27d494 str r12, [sp, #0x18] */
/* @0x27d498 bgt 0x27d5e8 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x388> */
/* @0x27d49c add r3, r3, #1 */
/* @0x27d4a0 ldr r0, [sp, #0x10] */
/* @0x27d4a4 str r3, [r11, #0x4] */
/* @0x27d4a8 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x27d4ac ldr lr, [r11, #0x8] */
/* @0x27d4b0 ldr r6, [r11, #0x10] */
/* @0x27d4b4 bic r0, r0, #-2147483648 */
/* @0x27d4b8 and r3, r0, lr */
/* @0x27d4bc add r2, r3, r3, lsl #1 */
/* @0x27d4c0 add r2, r6, r2, lsl #2 */
/* @0x27d4c4 ldr r1, [r2, #0x8] */
/* @0x27d4c8 cmp r1, #0 */
/* @0x27d4cc beq 0x27d5d0 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x370> */
/* @0x27d4d0 ldr r7, [r11] */
/* @0x27d4d4 mov r4, #0 */
/* @0x27d4d8 ldr r8, [sp, #0x10] */
/* @0x27d4dc ldr r9, [sp, #0x18] */
/* @0x27d4e0 b 0x27d524 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x2c4> */
/* @0x27d4e4 ldr r5, [r2] */
/* @0x27d4e8 ldr r4, [r2, #0x4] */
/* @0x27d4ec str r0, [r2, #0x8] */
/* @0x27d4f0 mov r0, r1 */
/* @0x27d4f4 str r8, [r2] */
/* @0x27d4f8 mov r8, r5 */
/* @0x27d4fc str r9, [r2, #0x4] */
/* @0x27d500 mov r9, r4 */
/* @0x27d504 add r3, r3, #1 */
/* @0x27d508 add r4, r12, #1 */
/* @0x27d50c and r3, r3, lr */
/* @0x27d510 add r2, r3, r3, lsl #1 */
/* @0x27d514 add r2, r6, r2, lsl #2 */
/* @0x27d518 ldr r1, [r2, #0x8] */
/* @0x27d51c cmp r1, #0 */
/* @0x27d520 beq 0x27d5c8 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x368> */
/* @0x27d524 add r12, r7, r3 */
/* @0x27d528 and r5, r1, lr */
/* @0x27d52c rsb r12, r5, r12 */
/* @0x27d530 and r12, r12, lr */
/* @0x27d534 cmp r12, r4 */
/* @0x27d538 blt 0x27d4e4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x284> */
/* @0x27d53c movne r12, r4 */
/* @0x27d540 bne 0x27d504 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x2a4> */
/* @0x27d544 cmp r1, r0 */
/* @0x27d548 bne 0x27d504 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x2a4> */
/* @0x27d54c ldr r4, [r2] */
/* @0x27d550 cmp r8, r4 */
/* @0x27d554 bne 0x27d504 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x2a4> */
/* @0x27d558 ldr r3, [r11, #0x4] */
/* @0x27d55c str r8, [sp, #0x10] */
/* @0x27d560 str r8, [r2] */
/* @0x27d564 sub r3, r3, #1 */
/* @0x27d568 str r9, [r2, #0x4] */
/* @0x27d56c str r1, [r2, #0x8] */
/* @0x27d570 str r9, [sp, #0x18] */
/* @0x27d574 str r3, [r11, #0x4] */
/* @0x27d578 ldr r12, [sp, #0xc] */
/* @0x27d57c ldr r0, [sp, #0x20] */
/* @0x27d580 add r12, r12, #1 */
/* @0x27d584 str r12, [sp, #0xc] */
/* @0x27d588 ldr r12, [sp, #0x8] */
/* @0x27d58c add r12, r12, #12 */
/* @0x27d590 str r12, [sp, #0x8] */
/* @0x27d594 ldr r12, [sp, #0xc] */
/* @0x27d598 cmp r12, r0 */
/* @0x27d59c bne 0x27d468 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x208> */
/* @0x27d5a0 ldr r0, [sp, #0x30] */
/* @0x27d5a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x27d5a8 vldr s13, [r11] */
/* @0x27d5ac vcvt.f32.s32 s14, s13 */
/* @0x27d5b0 vldr s15, [pc, #536] */
/* @0x27d5b4 ldr r3, [r11, #0x4] */
/* @0x27d5b8 vmul.f32 s15, s14, s15 */
/* @0x27d5bc vcvt.s32.f32 s15, s15 */
/* @0x27d5c0 vstr s15, [r11, #12] */
/* @0x27d5c4 b 0x27d288 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x28> */
/* @0x27d5c8 str r8, [sp, #0x10] */
/* @0x27d5cc str r9, [sp, #0x18] */
/* @0x27d5d0 ldr r12, [sp, #0x10] */
/* @0x27d5d4 str r0, [r2, #0x8] */
/* @0x27d5d8 str r12, [r2] */
/* @0x27d5dc ldr r12, [sp, #0x18] */
/* @0x27d5e0 str r12, [r2, #0x4] */
/* @0x27d5e4 b 0x27d578 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x318> */
/* @0x27d5e8 ldr r12, [r11] */
/* @0x27d5ec mov r3, #1 */
/* @0x27d5f0 ldr r1, [sp, #0x34] */
/* @0x27d5f4 mov r2, #70 */
/* @0x27d5f8 str r12, [sp, #0x14] */
/* @0x27d5fc ldr r12, [r11, #0x10] */
/* @0x27d600 str r12, [sp, #0x28] */
/* @0x27d604 ldr r12, [sp, #0x14] */
/* @0x27d608 lsl r0, r12, r3 */
/* @0x27d60c str r0, [r11] */
/* @0x27d610 add r4, r0, r12, lsl #2 */
/* @0x27d614 sub r0, r0, #1 */
/* @0x27d618 str r0, [r11, #0x8] */
/* @0x27d61c lsl r4, r4, #2 */
/* @0x27d620 mov r0, r4 */
/* @0x27d624 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x27d628 mov r2, r4 */
/* @0x27d62c mov r1, #0 */
/* @0x27d630 str r0, [r11, #0x10] */
/* @0x27d634 bl 0xb65b0 <memset@plt> */
/* @0x27d638 ldr r2, [r11] */
/* @0x27d63c mov r0, #0 */
/* @0x27d640 str r0, [r11, #0x4] */
/* @0x27d644 cmp r2, r0 */
/* @0x27d648 vmov s13, r2 */
/* @0x27d64c vcvt.f32.s32 s15, s13 */
/* @0x27d650 vmul.f32 s15, s15, s16 */
/* @0x27d654 vcvt.s32.f32 s15, s15 */
/* @0x27d658 vstr s15, [r11, #12] */
/* @0x27d65c ble 0x27d680 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x420> */
/* @0x27d660 add r2, r2, r2, lsl #1 */
/* @0x27d664 ldr r3, [r11, #0x10] */
/* @0x27d668 add r2, r3, r2, lsl #2 */
/* @0x27d66c mov r0, #0 */
/* @0x27d670 add r3, r3, #12 */
/* @0x27d674 str r0, [r3, #-0x4] */
/* @0x27d678 cmp r3, r2 */
/* @0x27d67c bne 0x27d66c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x40c> */
/* @0x27d680 ldr r12, [sp, #0x14] */
/* @0x27d684 cmp r12, #0 */
/* @0x27d688 ble 0x27d7a0 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x540> */
/* @0x27d68c ldr r6, [sp, #0x28] */
/* @0x27d690 mov r12, #0 */
/* @0x27d694 str r12, [sp, #0x4] */
/* @0x27d698 ldr r3, [r6, #0x8] */
/* @0x27d69c cmp r3, #0 */
/* @0x27d6a0 ble 0x27d784 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x524> */
/* @0x27d6a4 ldr r3, [r11, #0x4] */
/* @0x27d6a8 ldr r2, [r11, #0xc] */
/* @0x27d6ac ldr r4, [r6] */
/* @0x27d6b0 cmp r3, r2 */
/* @0x27d6b4 ldr r5, [r6, #0x4] */
/* @0x27d6b8 bgt 0x27d7e0 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x580> */
/* @0x27d6bc add r3, r3, #1 */
/* @0x27d6c0 mov r0, r4 */
/* @0x27d6c4 str r3, [r11, #0x4] */
/* @0x27d6c8 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x27d6cc ldr lr, [r11, #0x8] */
/* @0x27d6d0 ldr r9, [r11, #0x10] */
/* @0x27d6d4 bic r0, r0, #-2147483648 */
/* @0x27d6d8 and r3, r0, lr */
/* @0x27d6dc add r2, r3, r3, lsl #1 */
/* @0x27d6e0 add r2, r9, r2, lsl #2 */
/* @0x27d6e4 ldr r1, [r2, #0x8] */
/* @0x27d6e8 cmp r1, #0 */
/* @0x27d6ec ldrne r10, [r11] */
/* @0x27d6f0 movne r7, #0 */
/* @0x27d6f4 bne 0x27d73c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x4dc> */
/* @0x27d6f8 b 0x27d7c4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x564> */
/* @0x27d6fc ldr r8, [r2] */
/* @0x27d700 ldr r7, [r2, #0x4] */
/* @0x27d704 str r0, [r2, #0x8] */
/* @0x27d708 mov r0, r1 */
/* @0x27d70c str r4, [r2] */
/* @0x27d710 mov r4, r8 */
/* @0x27d714 str r5, [r2, #0x4] */
/* @0x27d718 mov r5, r7 */
/* @0x27d71c add r3, r3, #1 */
/* @0x27d720 add r7, r12, #1 */
/* @0x27d724 and r3, r3, lr */
/* @0x27d728 add r2, r3, r3, lsl #1 */
/* @0x27d72c add r2, r9, r2, lsl #2 */
/* @0x27d730 ldr r1, [r2, #0x8] */
/* @0x27d734 cmp r1, #0 */
/* @0x27d738 beq 0x27d7c4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x564> */
/* @0x27d73c add r12, r3, r10 */
/* @0x27d740 and r8, r1, lr */
/* @0x27d744 rsb r12, r8, r12 */
/* @0x27d748 and r12, r12, lr */
/* @0x27d74c cmp r12, r7 */
/* @0x27d750 blt 0x27d6fc <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x49c> */
/* @0x27d754 movne r12, r7 */
/* @0x27d758 bne 0x27d71c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x4bc> */
/* @0x27d75c cmp r1, r0 */
/* @0x27d760 bne 0x27d71c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x4bc> */
/* @0x27d764 ldr r7, [r2] */
/* @0x27d768 cmp r4, r7 */
/* @0x27d76c bne 0x27d71c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x4bc> */
/* @0x27d770 ldr r3, [r11, #0x4] */
/* @0x27d774 stm r2, {r4, r5} */
/* @0x27d778 sub r3, r3, #1 */
/* @0x27d77c str r1, [r2, #0x8] */
/* @0x27d780 str r3, [r11, #0x4] */
/* @0x27d784 ldr r12, [sp, #0x4] */
/* @0x27d788 add r6, r6, #12 */
/* @0x27d78c ldr r0, [sp, #0x14] */
/* @0x27d790 add r12, r12, #1 */
/* @0x27d794 str r12, [sp, #0x4] */
/* @0x27d798 cmp r12, r0 */
/* @0x27d79c bne 0x27d698 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x438> */
/* @0x27d7a0 ldr r0, [sp, #0x28] */
/* @0x27d7a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x27d7a8 vldr s13, [r11] */
/* @0x27d7ac vcvt.f32.s32 s15, s13 */
/* @0x27d7b0 ldr r3, [r11, #0x4] */
/* @0x27d7b4 vmul.f32 s15, s15, s16 */
/* @0x27d7b8 vcvt.s32.f32 s15, s15 */
/* @0x27d7bc vstr s15, [r11, #12] */
/* @0x27d7c0 b 0x27d49c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x23c> */
/* @0x27d7c4 stm r2, {r4, r5} */
/* @0x27d7c8 str r0, [r2, #0x8] */
/* @0x27d7cc b 0x27d784 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x524> */
/* @0x27d7d0 svclo #0x19999a */
/* @0x27d7d4 andeq r3, r11, r8, lsl #25 */
/* @0x27d7d8 andeq r3, r11, r12, ror #23 */
/* @0x27d7dc ldrdeq r3, r4, [r11], -r8 */
/* @0x27d7e0 ldr r8, [r11] */
/* @0x27d7e4 mov r3, #1 */
/* @0x27d7e8 ldr r1, [sp, #0x2c] */
/* @0x27d7ec mov r2, #70 */
/* @0x27d7f0 ldr r7, [r11, #0x10] */
/* @0x27d7f4 lsl r0, r8, r3 */
/* @0x27d7f8 str r0, [r11] */
/* @0x27d7fc add r9, r0, r8, lsl #2 */
/* @0x27d800 sub r0, r0, #1 */
/* @0x27d804 str r0, [r11, #0x8] */
/* @0x27d808 lsl r9, r9, #2 */
/* @0x27d80c mov r0, r9 */
/* @0x27d810 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x27d814 mov r2, r9 */
/* @0x27d818 mov r1, #0 */
/* @0x27d81c str r0, [r11, #0x10] */
/* @0x27d820 bl 0xb65b0 <memset@plt> */
/* @0x27d824 ldr r2, [r11] */
/* @0x27d828 mov r0, #0 */
/* @0x27d82c str r0, [r11, #0x4] */
/* @0x27d830 cmp r2, r0 */
/* @0x27d834 vmov s13, r2 */
/* @0x27d838 vcvt.f32.s32 s15, s13 */
/* @0x27d83c vmul.f32 s15, s15, s16 */
/* @0x27d840 vcvt.s32.f32 s15, s15 */
/* @0x27d844 vstr s15, [r11, #12] */
/* @0x27d848 ble 0x27d86c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x60c> */
/* @0x27d84c add r2, r2, r2, lsl #1 */
/* @0x27d850 ldr r3, [r11, #0x10] */
/* @0x27d854 add r2, r3, r2, lsl #2 */
/* @0x27d858 mov r0, #0 */
/* @0x27d85c add r3, r3, #12 */
/* @0x27d860 str r0, [r3, #-0x4] */
/* @0x27d864 cmp r3, r2 */
/* @0x27d868 bne 0x27d858 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x5f8> */
/* @0x27d86c cmp r8, #0 */
/* @0x27d870 movgt r9, r7 */
/* @0x27d874 movgt r10, #0 */
/* @0x27d878 ble 0x27d8a4 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x644> */
/* @0x27d87c ldr r3, [r9, #0x8] */
/* @0x27d880 mov r0, r11 */
/* @0x27d884 add r10, r10, #1 */
/* @0x27d888 cmp r3, #0 */
/* @0x27d88c ble 0x27d898 <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x638> */
/* @0x27d890 ldm r9, {r1, r2} */
/* @0x27d894 bl 0x27d260 <_ZN8CHashMapIPKciLi3EE6InsertES1_i> */
/* @0x27d898 cmp r10, r8 */
/* @0x27d89c add r9, r9, #12 */
/* @0x27d8a0 bne 0x27d87c <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x61c> */
/* @0x27d8a4 mov r0, r7 */
/* @0x27d8a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x27d8ac vldr s13, [r11] */
/* @0x27d8b0 vcvt.f32.s32 s15, s13 */
/* @0x27d8b4 ldr r3, [r11, #0x4] */
/* @0x27d8b8 vmul.f32 s15, s15, s16 */
/* @0x27d8bc vcvt.s32.f32 s15, s15 */
/* @0x27d8c0 vstr s15, [r11, #12] */
/* @0x27d8c4 b 0x27d6bc <_ZN8CHashMapIPKciLi3EE6InsertES1_i+0x45c> */

/* ── FUNC 0x27d8c8 · iffLogAddName(char const*, int*) · size=272 · insn=68 */
/* @0x27d8c8 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x27d8cc mov r7, r1 */
/* @0x27d8d0 mov r8, r0 */
/* @0x27d8d4 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x27d8d8 ldr r10, [pc, #0xf0] */
/* @0x27d8dc ldr r10, [pc, r10] */
/* @0x27d8e0 ldr r12, [r10, #0x8] */
/* @0x27d8e4 ldr r9, [r10, #0x10] */
/* @0x27d8e8 bic r0, r0, #-2147483648 */
/* @0x27d8ec and r3, r0, r12 */
/* @0x27d8f0 lsl r5, r3, #1 */
/* @0x27d8f4 add r2, r5, r3 */
/* @0x27d8f8 add r2, r9, r2, lsl #2 */
/* @0x27d8fc ldr r2, [r2, #0x8] */
/* @0x27d900 cmp r2, #0 */
/* @0x27d904 beq 0x27d974 <_Z13iffLogAddNamePKcPi+0xac> */
/* @0x27d908 cmp r0, r2 */
/* @0x27d90c beq 0x27d9b0 <_Z13iffLogAddNamePKcPi+0xe8> */
/* @0x27d910 ldr r11, [r10] */
/* @0x27d914 and r2, r12, r2 */
/* @0x27d918 add r1, r3, r11 */
/* @0x27d91c rsb r2, r2, r1 */
/* @0x27d920 tst r2, r12 */
/* @0x27d924 bmi 0x27d974 <_Z13iffLogAddNamePKcPi+0xac> */
/* @0x27d928 mov r4, #0 */
/* @0x27d92c b 0x27d940 <_Z13iffLogAddNamePKcPi+0x78> */
/* @0x27d930 cmp r0, r2 */
/* @0x27d934 beq 0x27d9a8 <_Z13iffLogAddNamePKcPi+0xe0> */
/* @0x27d938 cmp r6, r4 */
/* @0x27d93c blt 0x27d974 <_Z13iffLogAddNamePKcPi+0xac> */
/* @0x27d940 add r3, r3, #1 */
/* @0x27d944 add r4, r4, #1 */
/* @0x27d948 and r3, r3, r12 */
/* @0x27d94c add r6, r3, r11 */
/* @0x27d950 lsl r5, r3, #1 */
/* @0x27d954 add r2, r5, r3 */
/* @0x27d958 add r2, r9, r2, lsl #2 */
/* @0x27d95c ldr r2, [r2, #0x8] */
/* @0x27d960 and r1, r12, r2 */
/* @0x27d964 cmp r2, #0 */
/* @0x27d968 rsb r6, r1, r6 */
/* @0x27d96c and r6, r6, r12 */
/* @0x27d970 bne 0x27d930 <_Z13iffLogAddNamePKcPi+0x68> */
/* @0x27d974 ldr r4, [pc, #0x58] */
/* @0x27d978 mov r0, r10 */
/* @0x27d97c mov r1, r8 */
/* @0x27d980 ldr r4, [pc, r4] */
/* @0x27d984 ldr r5, [r4] */
/* @0x27d988 mov r2, r5 */
/* @0x27d98c bl 0x27d260 <_ZN8CHashMapIPKciLi3EE6InsertES1_i> */
/* @0x27d990 ldr r3, [r4] */
/* @0x27d994 mov r0, #1 */
/* @0x27d998 add r3, r3, r0 */
/* @0x27d99c str r3, [r4] */
/* @0x27d9a0 str r5, [r7] */
/* @0x27d9a4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x27d9a8 cmn r3, #1 */
/* @0x27d9ac beq 0x27d974 <_Z13iffLogAddNamePKcPi+0xac> */
/* @0x27d9b0 add r3, r5, r3 */
/* @0x27d9b4 add r9, r9, r3, lsl #2 */
/* @0x27d9b8 cmn r9, #4 */
/* @0x27d9bc beq 0x27d974 <_Z13iffLogAddNamePKcPi+0xac> */
/* @0x27d9c0 ldr r3, [r9, #0x4] */
/* @0x27d9c4 mov r0, #0 */
/* @0x27d9c8 str r3, [r7] */
/* @0x27d9cc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x27d9d0 andseq r3, r7, r4, asr #30 */
/* @0x27d9d4 andseq r3, r7, r0, ror #29 */

/* ── FUNC 0x27d9d8 · logName(char const*) · size=652 · insn=163 */
/* @0x27d9d8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x27d9dc sub sp, sp, #12 */
/* @0x27d9e0 mov r6, r0 */
/* @0x27d9e4 mov r1, sp */
/* @0x27d9e8 bl 0x27d8c8 <_Z13iffLogAddNamePKcPi> */
/* @0x27d9ec cmp r0, #0 */
/* @0x27d9f0 bne 0x27d9fc <_Z7logNamePKc+0x24> */
/* @0x27d9f4 add sp, sp, #12 */
/* @0x27d9f8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x27d9fc ldr r5, [pc, #0x23c] */
/* @0x27da00 ldr r5, [pc, r5] */
/* @0x27da04 ldr r4, [r5] */
/* @0x27da08 ldr r3, [r4, #0xc] */
/* @0x27da0c cmp r3, #0 */
/* @0x27da10 ble 0x27dc08 <_Z7logNamePKc+0x230> */
/* @0x27da14 ldr r7, [r4, #0x4] */
/* @0x27da18 add r2, r7, #4 */
/* @0x27da1c cmp r3, r2 */
/* @0x27da20 ble 0x27dad4 <_Z7logNamePKc+0xfc> */
/* @0x27da24 ldr r2, [pc, #0x218] */
/* @0x27da28 ldr r3, [r4] */
/* @0x27da2c add r2, pc, r2 */
/* @0x27da30 ldr r0, [r2] */
/* @0x27da34 str r0, [r3, r7] */
/* @0x27da38 ldr r3, [r4, #0x4] */
/* @0x27da3c add r3, r3, #4 */
/* @0x27da40 str r3, [r4, #0x4] */
/* @0x27da44 mov r0, r6 */
/* @0x27da48 bl 0xb6538 <strlen@plt> */
/* @0x27da4c ldr r4, [r5] */
/* @0x27da50 ldr r3, [r4, #0xc] */
/* @0x27da54 cmp r3, #0 */
/* @0x27da58 str r0, [sp, #0x4] */
/* @0x27da5c ble 0x27dba0 <_Z7logNamePKc+0x1c8> */
/* @0x27da60 ldr r7, [r4, #0x4] */
/* @0x27da64 add r2, r7, #4 */
/* @0x27da68 cmp r3, r2 */
/* @0x27da6c ble 0x27db5c <_Z7logNamePKc+0x184> */
/* @0x27da70 ldr r3, [r4] */
/* @0x27da74 ldr r0, [sp, #0x4] */
/* @0x27da78 str r0, [r3, r7] */
/* @0x27da7c ldr r3, [r4, #0x4] */
/* @0x27da80 add r3, r3, #4 */
/* @0x27da84 str r3, [r4, #0x4] */
/* @0x27da88 ldr r4, [r5] */
/* @0x27da8c ldr r5, [sp, #0x4] */
/* @0x27da90 ldr r3, [r4, #0xc] */
/* @0x27da94 cmp r3, #0 */
/* @0x27da98 ble 0x27dbd4 <_Z7logNamePKc+0x1fc> */
/* @0x27da9c ldr r7, [r4, #0x4] */
/* @0x27daa0 add r2, r5, r7 */
/* @0x27daa4 cmp r3, r2 */
/* @0x27daa8 ble 0x27db18 <_Z7logNamePKc+0x140> */
/* @0x27daac ldr r0, [r4] */
/* @0x27dab0 mov r2, r5 */
/* @0x27dab4 mov r1, r6 */
/* @0x27dab8 add r0, r0, r7 */
/* @0x27dabc bl 0xb65bc <memcpy@plt> */
/* @0x27dac0 ldr r3, [r4, #0x4] */
/* @0x27dac4 add r5, r3, r5 */
/* @0x27dac8 str r5, [r4, #0x4] */
/* @0x27dacc add sp, sp, #12 */
/* @0x27dad0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x27dad4 ldr r1, [pc, #0x16c] */
/* @0x27dad8 ldr r0, [r4, #0x8] */
/* @0x27dadc add r1, pc, r1 */
/* @0x27dae0 ldr r9, [r4] */
/* @0x27dae4 bl 0xb6844 <fopen@plt> */
/* @0x27dae8 mov r1, r7 */
/* @0x27daec mov r2, #1 */
/* @0x27daf0 mov r8, r0 */
/* @0x27daf4 mov r0, r9 */
/* @0x27daf8 mov r3, r8 */
/* @0x27dafc bl 0xb68bc <fwrite@plt> */
/* @0x27db00 mov r0, r8 */
/* @0x27db04 bl 0xb6850 <fclose@plt> */
/* @0x27db08 mov r3, #0 */
/* @0x27db0c mov r7, r3 */
/* @0x27db10 str r3, [r4, #0x4] */
/* @0x27db14 b 0x27da24 <_Z7logNamePKc+0x4c> */
/* @0x27db18 ldr r1, [pc, #0x12c] */
/* @0x27db1c ldr r0, [r4, #0x8] */
/* @0x27db20 add r1, pc, r1 */
/* @0x27db24 ldr r9, [r4] */
/* @0x27db28 bl 0xb6844 <fopen@plt> */
/* @0x27db2c mov r1, r7 */
/* @0x27db30 mov r2, #1 */
/* @0x27db34 mov r8, r0 */
/* @0x27db38 mov r0, r9 */
/* @0x27db3c mov r3, r8 */
/* @0x27db40 bl 0xb68bc <fwrite@plt> */
/* @0x27db44 mov r0, r8 */
/* @0x27db48 bl 0xb6850 <fclose@plt> */
/* @0x27db4c mov r3, #0 */
/* @0x27db50 mov r7, r3 */
/* @0x27db54 str r3, [r4, #0x4] */
/* @0x27db58 b 0x27daac <_Z7logNamePKc+0xd4> */
/* @0x27db5c ldr r1, [pc, #0xec] */
/* @0x27db60 ldr r0, [r4, #0x8] */
/* @0x27db64 add r1, pc, r1 */
/* @0x27db68 ldr r9, [r4] */
/* @0x27db6c bl 0xb6844 <fopen@plt> */
/* @0x27db70 mov r1, r7 */
/* @0x27db74 mov r2, #1 */
/* @0x27db78 mov r8, r0 */
/* @0x27db7c mov r0, r9 */
/* @0x27db80 mov r3, r8 */
/* @0x27db84 bl 0xb68bc <fwrite@plt> */
/* @0x27db88 mov r0, r8 */
/* @0x27db8c bl 0xb6850 <fclose@plt> */
/* @0x27db90 mov r3, #0 */
/* @0x27db94 mov r7, r3 */
/* @0x27db98 str r3, [r4, #0x4] */
/* @0x27db9c b 0x27da70 <_Z7logNamePKc+0x98> */
/* @0x27dba0 ldr r1, [pc, #0xac] */
/* @0x27dba4 ldr r0, [r4, #0x8] */
/* @0x27dba8 add r1, pc, r1 */
/* @0x27dbac bl 0xb6844 <fopen@plt> */
/* @0x27dbb0 mov r1, #4 */
/* @0x27dbb4 mov r2, #1 */
/* @0x27dbb8 mov r4, r0 */
/* @0x27dbbc mov r3, r0 */
/* @0x27dbc0 add r0, sp, #4 */
/* @0x27dbc4 bl 0xb68bc <fwrite@plt> */
/* @0x27dbc8 mov r0, r4 */
/* @0x27dbcc bl 0xb6850 <fclose@plt> */
/* @0x27dbd0 b 0x27da88 <_Z7logNamePKc+0xb0> */
/* @0x27dbd4 ldr r1, [pc, #0x7c] */
/* @0x27dbd8 ldr r0, [r4, #0x8] */
/* @0x27dbdc add r1, pc, r1 */
/* @0x27dbe0 bl 0xb6844 <fopen@plt> */
/* @0x27dbe4 mov r1, r5 */
/* @0x27dbe8 mov r2, #1 */
/* @0x27dbec mov r4, r0 */
/* @0x27dbf0 mov r0, r6 */
/* @0x27dbf4 mov r3, r4 */
/* @0x27dbf8 bl 0xb68bc <fwrite@plt> */
/* @0x27dbfc mov r0, r4 */
/* @0x27dc00 bl 0xb6850 <fclose@plt> */
/* @0x27dc04 b 0x27d9f4 <_Z7logNamePKc+0x1c> */
/* @0x27dc08 ldr r1, [pc, #0x4c] */
/* @0x27dc0c ldr r0, [r4, #0x8] */
/* @0x27dc10 add r1, pc, r1 */
/* @0x27dc14 bl 0xb6844 <fopen@plt> */
/* @0x27dc18 mov r1, #4 */
/* @0x27dc1c mov r2, #1 */
/* @0x27dc20 mov r4, r0 */
/* @0x27dc24 mov r3, r0 */
/* @0x27dc28 ldr r0, [pc, #0x30] */
/* @0x27dc2c add r0, pc, r0 */
/* @0x27dc30 bl 0xb68bc <fwrite@plt> */
/* @0x27dc34 mov r0, r4 */
/* @0x27dc38 bl 0xb6850 <fclose@plt> */
/* @0x27dc3c b 0x27da44 <_Z7logNamePKc+0x6c> */
/* @0x27dc40 andseq r3, r7, r4, lsr #28 */
/* @0x27dc44 andeq r9, sp, r8, asr #16 */
/* @0x27dc48 ldrdeq r9, r10, [sp], -r0 */
/* @0x27dc4c andeq r9, sp, r12, lsl #13 */
/* @0x27dc50 andeq r9, sp, r8, asr #12 */
/* @0x27dc54 andeq r9, sp, r4, lsl #12 */
/* @0x27dc58 ldrdeq r9, r10, [sp], -r0 */
/* @0x27dc5c muleq sp, r12, r5 */
/* @0x27dc60 andeq r9, sp, r8, asr #12 */

/* ── FUNC 0x27dc64 · SMemoryArray::Init(int, int, int) · size=176 · insn=44 */
/* @0x27dc64 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x27dc68 add r7, r1, #2 */
/* @0x27dc6c mov r5, r0 */
/* @0x27dc70 str r1, [r0, #0x18] */
/* @0x27dc74 mul r7, r2, r7 */
/* @0x27dc78 str r2, [r5, #0x1c] */
/* @0x27dc7c mov r8, #0 */
/* @0x27dc80 str r8, [r0] */
/* @0x27dc84 mov r4, r2 */
/* @0x27dc88 mov r0, r7 */
/* @0x27dc8c bl 0xb6544 <malloc@plt> */
/* @0x27dc90 cmp r0, r8 */
/* @0x27dc94 str r0, [r5, #0x8] */
/* @0x27dc98 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x27dc9c ldr r12, [pc, #0x68] */
/* @0x27dca0 lsl r6, r4, #1 */
/* @0x27dca4 ldr r2, [pc, #0x64] */
/* @0x27dca8 rsb r7, r6, r7 */
/* @0x27dcac ldr r12, [pc, r12] */
/* @0x27dcb0 add r1, r0, r7 */
/* @0x27dcb4 ldr r2, [pc, r2] */
/* @0x27dcb8 cmp r4, r8 */
/* @0x27dcbc ldr r9, [r12] */
/* @0x27dcc0 sub r3, r4, #1 */
/* @0x27dcc4 ldr r0, [r2] */
/* @0x27dcc8 add r9, r6, r9 */
/* @0x27dccc str r1, [r5, #0xc] */
/* @0x27dcd0 add r7, r9, r7 */
/* @0x27dcd4 str r1, [r5, #0x10] */
/* @0x27dcd8 add r6, r6, r0 */
/* @0x27dcdc str r3, [r5, #0x14] */
/* @0x27dce0 str r7, [r12] */
/* @0x27dce4 subgt r1, r1, #2 */
/* @0x27dce8 str r6, [r2] */
/* @0x27dcec movgt r3, r8 */
/* @0x27dcf0 ble 0x27dd04 <_ZN12SMemoryArray4InitEiii+0xa0> */
/* @0x27dcf4 strh r3, [r1, #2]! */
/* @0x27dcf8 add r3, r3, #1 */
/* @0x27dcfc cmp r3, r4 */
/* @0x27dd00 bne 0x27dcf4 <_ZN12SMemoryArray4InitEiii+0x90> */
/* @0x27dd04 mov r0, #1 */
/* @0x27dd08 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x27dd0c andseq r2, r7, r12, lsr #14 */
/* @0x27dd10 andseq r2, r7, r0, lsr r7 */

/* ── FUNC 0x27dd14 · SMemoryArray::Quit() · size=88 · insn=22 */
/* @0x27dd14 push {r3, r4, r5, lr} */
/* @0x27dd18 mov r4, r0 */
/* @0x27dd1c ldr r0, [r0, #0x8] */
/* @0x27dd20 bl 0xb655c <free@plt> */
/* @0x27dd24 ldr r1, [r4, #0x1c] */
/* @0x27dd28 ldr r3, [pc, #0x34] */
/* @0x27dd2c ldr r4, [r4, #0x18] */
/* @0x27dd30 ldr r3, [pc, r3] */
/* @0x27dd34 rsb r0, r1, r1, lsl #31 */
/* @0x27dd38 ldr r2, [pc, #0x28] */
/* @0x27dd3c ldr r5, [r3] */
/* @0x27dd40 lsl r0, r0, #1 */
/* @0x27dd44 ldr r2, [pc, r2] */
/* @0x27dd48 add r5, r0, r5 */
/* @0x27dd4c ldr r12, [r2] */
/* @0x27dd50 mls r1, r4, r1, r5 */
/* @0x27dd54 add r0, r0, r12 */
/* @0x27dd58 str r0, [r2] */
/* @0x27dd5c str r1, [r3] */
/* @0x27dd60 pop {r3, r4, r5, pc} */
/* @0x27dd64 andseq r2, r7, r8, lsr #13 */
/* @0x27dd68 andseq r2, r7, r0, lsr #13 */

/* ── FUNC 0x27dd6c · SMemoryArray::Alloc(int) · size=56 · insn=14 */
/* @0x27dd6c ldr r3, [r0, #0x14] */
/* @0x27dd70 str r4, [sp, #-0x4]! */
/* @0x27dd74 cmp r3, #0 */
/* @0x27dd78 lslge r1, r3, #1 */
/* @0x27dd7c subge r3, r3, #1 */
/* @0x27dd80 ldrge r4, [r0, #0x10] */
/* @0x27dd84 movlt r0, #0 */
/* @0x27dd88 ldrge r12, [r0, #0x18] */
/* @0x27dd8c ldrge r2, [r0, #0x8] */
/* @0x27dd90 ldrshge r1, [r4, r1] */
/* @0x27dd94 strge r3, [r0, #0x14] */
/* @0x27dd98 ldr r4, [sp], #4 */
/* @0x27dd9c mlage r0, r12, r1, r2 */
/* @0x27dda0 bx lr */

/* ── FUNC 0x27dda4 · SMemoryArray::Free(void*) · size=92 · insn=23 */
/* @0x27dda4 push {r4, lr} */
/* @0x27dda8 mov r4, r0 */
/* @0x27ddac ldr r0, [r0, #0x8] */
/* @0x27ddb0 cmp r0, r1 */
/* @0x27ddb4 bhi 0x27ddf4 <_ZN12SMemoryArray4FreeEPv+0x50> */
/* @0x27ddb8 ldr r3, [r4, #0xc] */
/* @0x27ddbc cmp r1, r3 */
/* @0x27ddc0 bhi 0x27ddf4 <_ZN12SMemoryArray4FreeEPv+0x50> */
/* @0x27ddc4 rsb r0, r0, r1 */
/* @0x27ddc8 ldr r1, [r4, #0x18] */
/* @0x27ddcc bl 0x318d10 <__divsi3> */
/* @0x27ddd0 ldr r2, [r4, #0x14] */
/* @0x27ddd4 mov r3, #1 */
/* @0x27ddd8 ldr r1, [r4, #0x10] */
/* @0x27dddc add r2, r2, r3 */
/* @0x27dde0 str r2, [r4, #0x14] */
/* @0x27dde4 lsl r2, r2, r3 */
/* @0x27dde8 strh r0, [r1, r2] */
/* @0x27ddec mov r0, r3 */
/* @0x27ddf0 pop {r4, pc} */
/* @0x27ddf4 mov r3, #0 */
/* @0x27ddf8 mov r0, r3 */
/* @0x27ddfc pop {r4, pc} */

/* ── FUNC 0x27de00 · InitFastCRC() · size=100 · insn=25 */
/* @0x27de00 ldr r12, [pc, #0x54] */
/* @0x27de04 mov r0, #0 */
/* @0x27de08 ldr r12, [pc, r12] */
/* @0x27de0c sub r12, r12, #4 */
/* @0x27de10 mov r3, r0 */
/* @0x27de14 mov r2, #8 */
/* @0x27de18 tst r3, #1 */
/* @0x27de1c lsr r1, r3, #1 */
/* @0x27de20 lsreq r3, r3, #1 */
/* @0x27de24 movwne r3, #0x8320 */
/* @0x27de28 movtne r3, #0xedb8 */
/* @0x27de2c eorne r3, r1, r3 */
/* @0x27de30 subs r2, r2, #1 */
/* @0x27de34 bne 0x27de18 <_Z11InitFastCRCv+0x18> */
/* @0x27de38 add r0, r0, #1 */
/* @0x27de3c str r3, [r12, #0x4]! */
/* @0x27de40 cmp r0, #256 */
/* @0x27de44 bne 0x27de10 <_Z11InitFastCRCv+0x10> */
/* @0x27de48 ldr r3, [pc, #0x10] */
/* @0x27de4c mov r2, #1 */
/* @0x27de50 ldr r3, [pc, r3] */
/* @0x27de54 strb r2, [r3] */
/* @0x27de58 bx lr */
/* @0x27de5c andseq r2, r7, r8, lsl pc */
/* @0x27de60 andseq r3, r7, r4, lsr r10 */

/* ── FUNC 0x27de64 · CheckFastCRC() · size=92 · insn=23 */
/* @0x27de64 ldr r12, [pc, #0x50] */
/* @0x27de68 mov r1, #0 */
/* @0x27de6c ldr r12, [pc, r12] */
/* @0x27de70 sub r12, r12, #4 */
/* @0x27de74 mov r3, r1 */
/* @0x27de78 mov r0, #8 */
/* @0x27de7c tst r3, #1 */
/* @0x27de80 lsr r2, r3, #1 */
/* @0x27de84 lsreq r3, r3, #1 */
/* @0x27de88 movwne r3, #0x8320 */
/* @0x27de8c movtne r3, #0xedb8 */
/* @0x27de90 eorne r3, r2, r3 */
/* @0x27de94 subs r0, r0, #1 */
/* @0x27de98 bne 0x27de7c <_Z12CheckFastCRCv+0x18> */
/* @0x27de9c ldr r2, [r12, #0x4]! */
/* @0x27dea0 cmp r3, r2 */
/* @0x27dea4 bxne lr */
/* @0x27dea8 add r1, r1, #1 */
/* @0x27deac cmp r1, #256 */
/* @0x27deb0 bne 0x27de74 <_Z12CheckFastCRCv+0x10> */
/* @0x27deb4 mov r0, #1 */
/* @0x27deb8 bx lr */
/* @0x27debc ldrheq r2, [r7], -r4 */

/* ── FUNC 0x27dec0 · CalcCRC(char const*, unsigned int) · size=108 · insn=27 */
/* @0x27dec0 push {r3, r4, r5, lr} */
/* @0x27dec4 mov r5, r0 */
/* @0x27dec8 ldr r3, [pc, #0x54] */
/* @0x27decc mov r4, r1 */
/* @0x27ded0 ldr r3, [pc, r3] */
/* @0x27ded4 ldrb r3, [r3] */
/* @0x27ded8 cmp r3, #0 */
/* @0x27dedc beq 0x27df1c <_Z7CalcCRCPKcj+0x5c> */
/* @0x27dee0 ldrb r3, [r5] */
/* @0x27dee4 cmp r3, #0 */
/* @0x27dee8 beq 0x27df14 <_Z7CalcCRCPKcj+0x54> */
/* @0x27deec ldr r1, [pc, #0x34] */
/* @0x27def0 mov r0, r5 */
/* @0x27def4 ldr r1, [pc, r1] */
/* @0x27def8 eor r2, r4, r3 */
/* @0x27defc ldrb r3, [r0, #0x1]! */
/* @0x27df00 uxtb r2, r2 */
/* @0x27df04 cmp r3, #0 */
/* @0x27df08 ldr r2, [r1, r2, lsl #2] */
/* @0x27df0c eor r4, r2, r4, lsr #8 */
/* @0x27df10 bne 0x27def8 <_Z7CalcCRCPKcj+0x38> */
/* @0x27df14 mov r0, r4 */
/* @0x27df18 pop {r3, r4, r5, pc} */
/* @0x27df1c bl 0x27de00 <_Z11InitFastCRCv> */
/* @0x27df20 b 0x27dee0 <_Z7CalcCRCPKcj+0x20> */
/* @0x27df24 ldrheq r3, [r7], -r4 */
/* @0x27df28 andseq r2, r7, r12, lsr #28 */

/* ── FUNC 0x27df2c · CalcCRC(char const*) · size=8 · insn=2 */
/* @0x27df2c mvn r1, #0 */
/* @0x27df30 b 0x27dec0 <_Z7CalcCRCPKcj> */

/* ── FUNC 0x27df34 · CalcCRC(char const*, int, unsigned int) · size=108 · insn=27 */
/* @0x27df34 ldr r3, [pc, #0x5c] */
/* @0x27df38 push {r4, r5, r6, lr} */
/* @0x27df3c ldr r3, [pc, r3] */
/* @0x27df40 mov r5, r0 */
/* @0x27df44 mov r6, r1 */
/* @0x27df48 ldrb r3, [r3] */
/* @0x27df4c mov r4, r2 */
/* @0x27df50 cmp r3, #0 */
/* @0x27df54 beq 0x27df90 <_Z7CalcCRCPKcij+0x5c> */
/* @0x27df58 cmp r6, #0 */
/* @0x27df5c ble 0x27df88 <_Z7CalcCRCPKcij+0x54> */
/* @0x27df60 ldr r2, [pc, #0x34] */
/* @0x27df64 add r1, r5, r6 */
/* @0x27df68 ldr r2, [pc, r2] */
/* @0x27df6c ldrb r3, [r5], #1 */
/* @0x27df70 eor r3, r3, r4 */
/* @0x27df74 cmp r5, r1 */
/* @0x27df78 uxtb r3, r3 */
/* @0x27df7c ldr r3, [r2, r3, lsl #2] */
/* @0x27df80 eor r4, r3, r4, lsr #8 */
/* @0x27df84 bne 0x27df6c <_Z7CalcCRCPKcij+0x38> */
/* @0x27df88 mov r0, r4 */
/* @0x27df8c pop {r4, r5, r6, pc} */
/* @0x27df90 bl 0x27de00 <_Z11InitFastCRCv> */
/* @0x27df94 b 0x27df58 <_Z7CalcCRCPKcij+0x24> */
/* @0x27df98 andseq r3, r7, r8, asr #18 */
/* @0x27df9c ldrheq r2, [r7], -r8 */

/* ── FUNC 0x27dfa0 · CalcCRC(char const*, int) · size=8 · insn=2 */
/* @0x27dfa0 mvn r2, #0 */
/* @0x27dfa4 b 0x27df34 <_Z7CalcCRCPKcij> */

/* ── FUNC 0x27dfa8 · CalcCRC_string(char const*) · size=120 · insn=30 */
/* @0x27dfa8 ldr r3, [pc, #0x68] */
/* @0x27dfac push {r4, lr} */
/* @0x27dfb0 ldr r3, [pc, r3] */
/* @0x27dfb4 mov r4, r0 */
/* @0x27dfb8 ldrb r3, [r3] */
/* @0x27dfbc cmp r3, #0 */
/* @0x27dfc0 beq 0x27e010 <_Z14CalcCRC_stringPKc+0x68> */
/* @0x27dfc4 cmp r4, #0 */
/* @0x27dfc8 beq 0x27e008 <_Z14CalcCRC_stringPKc+0x60> */
/* @0x27dfcc ldrb r3, [r4] */
/* @0x27dfd0 cmp r3, #0 */
/* @0x27dfd4 beq 0x27e008 <_Z14CalcCRC_stringPKc+0x60> */
/* @0x27dfd8 ldr r12, [pc, #0x3c] */
/* @0x27dfdc mov r2, r4 */
/* @0x27dfe0 mvn r0, #0 */
/* @0x27dfe4 ldr r12, [pc, r12] */
/* @0x27dfe8 eor r1, r0, r3 */
/* @0x27dfec ldrb r3, [r2, #0x1]! */
/* @0x27dff0 uxtb r1, r1 */
/* @0x27dff4 cmp r3, #0 */
/* @0x27dff8 ldr r1, [r12, r1, lsl #2] */
/* @0x27dffc eor r0, r1, r0, lsr #8 */
/* @0x27e000 bne 0x27dfe8 <_Z14CalcCRC_stringPKc+0x40> */
/* @0x27e004 pop {r4, pc} */
/* @0x27e008 mvn r0, #0 */
/* @0x27e00c pop {r4, pc} */
/* @0x27e010 bl 0x27de00 <_Z11InitFastCRCv> */
/* @0x27e014 b 0x27dfc4 <_Z14CalcCRC_stringPKc+0x1c> */
/* @0x27e018 ldrsbeq r3, [r7], -r4 */
/* @0x27e01c andseq r2, r7, r12, lsr sp */

/* ── FUNC 0x27e020 · Mutex::~Mutex() · size=24 · insn=6 */
/* @0x27e020 push {r4, lr} */
/* @0x27e024 mov r4, r0 */
/* @0x27e028 add r0, r0, #4 */
/* @0x27e02c bl 0xb6c94 <pthread_mutex_destroy@plt> */
/* @0x27e030 mov r0, r4 */
/* @0x27e034 pop {r4, pc} */

/* ── FUNC 0x27e020 · Mutex::~Mutex() · alias of the symbol above · insn=0 */

/* ── FUNC 0x27e038 · Mutex::Init(char const*) · size=56 · insn=14 */
/* @0x27e038 push {r4, r5, lr} */
/* @0x27e03c sub sp, sp, #12 */
/* @0x27e040 add r4, sp, #4 */
/* @0x27e044 mov r5, r0 */
/* @0x27e048 mov r0, r4 */
/* @0x27e04c bl 0xb6ca0 <pthread_mutexattr_init@plt> */
/* @0x27e050 mov r0, r4 */
/* @0x27e054 mov r1, #1 */
/* @0x27e058 bl 0xb6cac <pthread_mutexattr_settype@plt> */
/* @0x27e05c add r0, r5, #4 */
/* @0x27e060 mov r1, r4 */
/* @0x27e064 bl 0xb6cb8 <pthread_mutex_init@plt> */
/* @0x27e068 add sp, sp, #12 */
/* @0x27e06c pop {r4, r5, pc} */

/* ── FUNC 0x27e070 · Mutex::Mutex(char const*) · size=20 · insn=5 */
/* @0x27e070 push {r4, lr} */
/* @0x27e074 mov r4, r0 */
/* @0x27e078 bl 0x27e038 <_ZN5Mutex4InitEPKc> */
/* @0x27e07c mov r0, r4 */
/* @0x27e080 pop {r4, pc} */

/* ── FUNC 0x27e070 · Mutex::Mutex(char const*) · alias of the symbol above · insn=0 */

/* ── FUNC 0x27e084 · Mutex::Lock() · size=24 · insn=6 */
/* @0x27e084 push {r3, lr} */
/* @0x27e088 add r0, r0, #4 */
/* @0x27e08c bl 0xb6cc4 <pthread_mutex_lock@plt> */
/* @0x27e090 rsbs r0, r0, #1 */
/* @0x27e094 movlo r0, #0 */
/* @0x27e098 pop {r3, pc} */

/* ── FUNC 0x27e09c · Mutex::Unlock() · size=8 · insn=2 */
/* @0x27e09c add r0, r0, #4 */
/* @0x27e0a0 b 0xb6cd0 <pthread_mutex_unlock@plt> */

/* ── FUNC 0x27e0a4 · anon_27e0a4 · size=24 · insn=7 */
/* @0x27e0a4 push {r4, lr} */
/* @0x27e0a8 mov r4, r0 */
/* @0x27e0ac ldr r3, [r0, #0x10] */
/* @0x27e0b0 blx r3 */
/* @0x27e0b4 mov r3, #0 */
/* @0x27e0b8 strb r3, [r4, #0x9] */
/* @0x27e0bc pop {r4, pc} */

/* ── FUNC 0x27e0c0 · CThread::Start(void* (*)(void*), void*, CThread::ePriority) · size=72 · insn=18 */
/* @0x27e0c0 push {r3, r4, r5, lr} */
/* @0x27e0c4 mov r5, #1 */
/* @0x27e0c8 str r2, [r0, #0xc] */
/* @0x27e0cc mov r3, r0 */
/* @0x27e0d0 ldr r2, [pc, #0x2c] */
/* @0x27e0d4 mov r4, r0 */
/* @0x27e0d8 str r1, [r0, #0x10] */
/* @0x27e0dc mov r1, #0 */
/* @0x27e0e0 strb r5, [r0, #0x9] */
/* @0x27e0e4 add r2, pc, r2 */
/* @0x27e0e8 bl 0xb6cdc <pthread_create@plt> */
/* @0x27e0ec cmp r0, #0 */
/* @0x27e0f0 str r0, [r4, #0x4] */
/* @0x27e0f4 movne r0, #0 */
/* @0x27e0f8 strbne r0, [r4, #0x9] */
/* @0x27e0fc moveq r0, r5 */
/* @0x27e100 pop {r3, r4, r5, pc} */
/* @0x27e104 .word 0xffffffb8 */

/* ── FUNC 0x27e108 · CThread::WaitForExit() · size=12 · insn=3 */
/* @0x27e108 ldr r0, [r0] */
/* @0x27e10c mov r1, #0 */
/* @0x27e110 b 0xb6ce8 <pthread_join@plt> */

/* ── FUNC 0x27e114 · CThread::Sleep(int) · size=48 · insn=12 */
/* @0x27e114 movw r3, #0x4240 */
/* @0x27e118 movt r3, #0xf */
/* @0x27e11c str lr, [sp, #-0x4]! */
/* @0x27e120 sub sp, sp, #12 */
/* @0x27e124 mul r3, r3, r0 */
/* @0x27e128 mov r1, #0 */
/* @0x27e12c mov r0, sp */
/* @0x27e130 str r1, [sp] */
/* @0x27e134 str r3, [sp, #0x4] */
/* @0x27e138 bl 0xb6c04 <nanosleep@plt> */
/* @0x27e13c add sp, sp, #12 */
/* @0x27e140 ldr pc, [sp], #4 */

/* ── FUNC 0x27e144 · FlushProfile() · size=4 · insn=1 */
/* @0x27e144 bx lr */

/* ── FUNC 0x27e148 · InitProfile() · size=4 · insn=1 */
/* @0x27e148 bx lr */
