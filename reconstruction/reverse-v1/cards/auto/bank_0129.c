/* libyoyo.so 覆盖卡组 0129
 * 函数 0x1910e8..0x192a9c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1910e8 · CGCGeneration::IsRoot(YYObjectBase*) · size=224 · insn=56 */
/* @0x1910e8 cmp r1, #0 */
/* @0x1910ec mov r3, r0 */
/* @0x1910f0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1910f4 mov r0, r1 */
/* @0x1910f8 beq 0x1911bc <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xd4> */
/* @0x1910fc ldr r5, [r3] */
/* @0x191100 bl 0x190f34 <_Z21CHashMapCalculateHashIP12YYObjectBaseEjT_> */
/* @0x191104 ldr r1, [r5, #0x8] */
/* @0x191108 ldr r7, [r5, #0x10] */
/* @0x19110c bic r0, r0, #-2147483648 */
/* @0x191110 and r3, r0, r1 */
/* @0x191114 lsl r4, r3, #1 */
/* @0x191118 add r2, r4, r3 */
/* @0x19111c add r2, r7, r2, lsl #2 */
/* @0x191120 ldr r2, [r2, #0x8] */
/* @0x191124 cmp r2, #0 */
/* @0x191128 beq 0x1911c0 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xd8> */
/* @0x19112c cmp r0, r2 */
/* @0x191130 beq 0x1911a8 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xc0> */
/* @0x191134 ldr r8, [r5] */
/* @0x191138 and r2, r1, r2 */
/* @0x19113c add r12, r3, r8 */
/* @0x191140 rsb r2, r2, r12 */
/* @0x191144 tst r2, r1 */
/* @0x191148 bmi 0x191198 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xb0> */
/* @0x19114c mov r12, #0 */
/* @0x191150 b 0x191164 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0x7c> */
/* @0x191154 cmp r0, r2 */
/* @0x191158 beq 0x1911a0 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xb8> */
/* @0x19115c cmp r5, r12 */
/* @0x191160 blt 0x191198 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xb0> */
/* @0x191164 add r3, r3, #1 */
/* @0x191168 add r12, r12, #1 */
/* @0x19116c and r3, r1, r3 */
/* @0x191170 add r6, r3, r8 */
/* @0x191174 lsl r4, r3, #1 */
/* @0x191178 add r2, r4, r3 */
/* @0x19117c add r2, r7, r2, lsl #2 */
/* @0x191180 ldr r2, [r2, #0x8] */
/* @0x191184 and r5, r1, r2 */
/* @0x191188 cmp r2, #0 */
/* @0x19118c rsb r5, r5, r6 */
/* @0x191190 and r5, r5, r1 */
/* @0x191194 bne 0x191154 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0x6c> */
/* @0x191198 mov r0, #0 */
/* @0x19119c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1911a0 cmn r3, #1 */
/* @0x1911a4 beq 0x191198 <_ZN13CGCGeneration6IsRootEP12YYObjectBase+0xb0> */
/* @0x1911a8 add r0, r4, r3 */
/* @0x1911ac add r0, r7, r0, lsl #2 */
/* @0x1911b0 adds r0, r0, #4 */
/* @0x1911b4 movne r0, #1 */
/* @0x1911b8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1911bc pop {r4, r5, r6, r7, r8, pc} */
/* @0x1911c0 mov r0, r2 */
/* @0x1911c4 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x1911c8 · CGCGeneration::RemoveRoot(YYObjectBase*) · size=404 · insn=101 */
/* @0x1911c8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1911cc subs r9, r1, #0 */
/* @0x1911d0 sub sp, sp, #12 */
/* @0x1911d4 mov r3, r0 */
/* @0x1911d8 beq 0x19134c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x184> */
/* @0x1911dc mov r0, r9 */
/* @0x1911e0 ldr r6, [r3] */
/* @0x1911e4 bl 0x190f34 <_Z21CHashMapCalculateHashIP12YYObjectBaseEjT_> */
/* @0x1911e8 ldr r3, [r6, #0x8] */
/* @0x1911ec ldr r2, [r6, #0x10] */
/* @0x1911f0 bic r10, r0, #-2147483648 */
/* @0x1911f4 and r4, r10, r3 */
/* @0x1911f8 lsl r5, r4, #1 */
/* @0x1911fc add r1, r5, r4 */
/* @0x191200 add r2, r2, r1, lsl #2 */
/* @0x191204 ldr r7, [r2, #0x8] */
/* @0x191208 cmp r7, #0 */
/* @0x19120c beq 0x19134c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x184> */
/* @0x191210 mov r8, #0 */
/* @0x191214 b 0x19125c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x94> */
/* @0x191218 ldr r2, [r6] */
/* @0x19121c and r7, r7, r3 */
/* @0x191220 add r1, r4, #1 */
/* @0x191224 add r2, r4, r2 */
/* @0x191228 and r4, r1, r3 */
/* @0x19122c rsb r7, r7, r2 */
/* @0x191230 and r7, r7, r3 */
/* @0x191234 lsl r5, r4, #1 */
/* @0x191238 cmp r7, r8 */
/* @0x19123c add r2, r5, r4 */
/* @0x191240 add r8, r8, #1 */
/* @0x191244 blt 0x19134c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x184> */
/* @0x191248 ldr r1, [r6, #0x10] */
/* @0x19124c add r2, r1, r2, lsl #2 */
/* @0x191250 ldr r7, [r2, #0x8] */
/* @0x191254 cmp r7, #0 */
/* @0x191258 beq 0x19134c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x184> */
/* @0x19125c cmp r10, r7 */
/* @0x191260 bne 0x191218 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x50> */
/* @0x191264 ldr r0, [r2] */
/* @0x191268 mov r1, r9 */
/* @0x19126c bl 0x190f48 <_Z19CHashMapCompareKeysIP12YYObjectBaseEbT_S2_> */
/* @0x191270 cmp r0, #0 */
/* @0x191274 ldreq r3, [r6, #0x8] */
/* @0x191278 beq 0x191218 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x50> */
/* @0x19127c cmn r4, #1 */
/* @0x191280 beq 0x19134c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x184> */
/* @0x191284 ldr r12, [r6, #0x8] */
/* @0x191288 add r0, r4, #1 */
/* @0x19128c ldr r10, [r6, #0x10] */
/* @0x191290 and r0, r0, r12 */
/* @0x191294 add r1, r0, r0, lsl #1 */
/* @0x191298 add r1, r10, r1, lsl #2 */
/* @0x19129c ldr r2, [r1, #0x8] */
/* @0x1912a0 cmp r2, #0 */
/* @0x1912a4 beq 0x191354 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x18c> */
/* @0x1912a8 ldr r3, [r6] */
/* @0x1912ac str r3, [sp] */
/* @0x1912b0 and r3, r12, r2 */
/* @0x1912b4 ldr r8, [sp] */
/* @0x1912b8 add r7, r0, r8 */
/* @0x1912bc rsb r3, r3, r7 */
/* @0x1912c0 tst r3, r12 */
/* @0x1912c4 strne r6, [sp, #0x4] */
/* @0x1912c8 bne 0x1912dc <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x114> */
/* @0x1912cc b 0x191354 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x18c> */
/* @0x1912d0 tst r8, r12 */
/* @0x1912d4 beq 0x19132c <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x164> */
/* @0x1912d8 mov r0, r3 */
/* @0x1912dc add r3, r0, #1 */
/* @0x1912e0 add r7, r5, r4 */
/* @0x1912e4 and r3, r3, r12 */
/* @0x1912e8 ldr r11, [r1] */
/* @0x1912ec add r6, r10, r7, lsl #2 */
/* @0x1912f0 ldr r4, [sp] */
/* @0x1912f4 add r9, r3, r3, lsl #1 */
/* @0x1912f8 lsl r5, r0, #1 */
/* @0x1912fc str r2, [r6, #0x8] */
/* @0x191300 add r8, r4, r3 */
/* @0x191304 str r11, [r10, r7, lsl #2] */
/* @0x191308 mov r4, r0 */
/* @0x19130c ldr r7, [r1, #0x4] */
/* @0x191310 add r1, r10, r9, lsl #2 */
/* @0x191314 ldr r2, [r1, #0x8] */
/* @0x191318 str r7, [r6, #0x4] */
/* @0x19131c cmp r2, #0 */
/* @0x191320 and r6, r12, r2 */
/* @0x191324 rsb r8, r6, r8 */
/* @0x191328 bne 0x1912d0 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x108> */
/* @0x19132c ldr r6, [sp, #0x4] */
/* @0x191330 add r0, r0, r0, lsl #1 */
/* @0x191334 ldr r3, [r6, #0x4] */
/* @0x191338 mov r2, #0 */
/* @0x19133c add r0, r10, r0, lsl #2 */
/* @0x191340 sub r3, r3, #1 */
/* @0x191344 str r2, [r0, #0x8] */
/* @0x191348 str r3, [r6, #0x4] */
/* @0x19134c add sp, sp, #12 */
/* @0x191350 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x191354 mov r0, r4 */
/* @0x191358 b 0x191330 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase+0x168> */

/* ── FUNC 0x19135c · CGCGeneration::AddDynamicRoot(YYObjectBase*, bool) · size=164 · insn=41 */
/* @0x19135c push {r4, r5, lr} */
/* @0x191360 subs r5, r1, #0 */
/* @0x191364 sub sp, sp, #12 */
/* @0x191368 mov r4, r0 */
/* @0x19136c beq 0x191388 <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb+0x2c> */
/* @0x191370 cmp r2, #0 */
/* @0x191374 bne 0x191390 <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb+0x34> */
/* @0x191378 ldr r2, [r5, #0x38] */
/* @0x19137c ldr r3, [r0, #0x10] */
/* @0x191380 cmp r2, r3 */
/* @0x191384 beq 0x191390 <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb+0x34> */
/* @0x191388 add sp, sp, #12 */
/* @0x19138c pop {r4, r5, pc} */
/* @0x191390 ldr r3, [r4, #0x8] */
/* @0x191394 ldr r1, [r4, #0xc] */
/* @0x191398 cmp r3, r1 */
/* @0x19139c bge 0x1913b8 <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb+0x5c> */
/* @0x1913a0 ldr r1, [r4, #0x4] */
/* @0x1913a4 add r2, r3, #1 */
/* @0x1913a8 str r2, [r4, #0x8] */
/* @0x1913ac str r5, [r1, r3, lsl #2] */
/* @0x1913b0 add sp, sp, #12 */
/* @0x1913b4 pop {r4, r5, pc} */
/* @0x1913b8 lsls r3, r1, #1 */
/* @0x1913bc ldr r2, [pc, #0x38] */
/* @0x1913c0 strne r3, [r4, #0xc] */
/* @0x1913c4 lslne r1, r1, #3 */
/* @0x1913c8 moveq r3, #1 */
/* @0x1913cc moveq r1, #4 */
/* @0x1913d0 streq r3, [r4, #0xc] */
/* @0x1913d4 add r2, pc, r2 */
/* @0x1913d8 ldr r0, [r4, #0x4] */
/* @0x1913dc mov r3, #0 */
/* @0x1913e0 str r3, [sp] */
/* @0x1913e4 mov r3, #74 */
/* @0x1913e8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1913ec ldr r3, [r4, #0x8] */
/* @0x1913f0 mov r1, r0 */
/* @0x1913f4 str r0, [r4, #0x4] */
/* @0x1913f8 b 0x1913a4 <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb+0x48> */
/* @0x1913fc andseq pc, r9, r12, asr r12 */

/* ── FUNC 0x191400 · CGCGeneration::ResetDynamicRoots() · size=12 · insn=3 */
/* @0x191400 mov r3, #0 */
/* @0x191404 str r3, [r0, #0x8] */
/* @0x191408 bx lr */

/* ── FUNC 0x19140c · CGCGeneration::Reset() · size=256 · insn=64 */
/* @0x19140c push {r3, r4, r5, r6, r7, lr} */
/* @0x191410 mov r4, r0 */
/* @0x191414 bl 0x191400 <_ZN13CGCGeneration17ResetDynamicRootsEv> */
/* @0x191418 ldr r5, [r4] */
/* @0x19141c ldr r0, [r5, #0x10] */
/* @0x191420 cmp r0, #0 */
/* @0x191424 beq 0x19142c <_ZN13CGCGeneration5ResetEv+0x20> */
/* @0x191428 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19142c mov r6, #0 */
/* @0x191430 str r6, [r5, #0x10] */
/* @0x191434 ldr r5, [r4] */
/* @0x191438 mov r2, #70 */
/* @0x19143c ldr r1, [pc, #0xc0] */
/* @0x191440 mov r3, #1 */
/* @0x191444 ldr r0, [r5] */
/* @0x191448 add r1, pc, r1 */
/* @0x19144c sub r12, r0, #1 */
/* @0x191450 str r12, [r5, #0x8] */
/* @0x191454 add r0, r0, r0, lsl #1 */
/* @0x191458 lsl r7, r0, #2 */
/* @0x19145c mov r0, r7 */
/* @0x191460 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x191464 mov r2, r7 */
/* @0x191468 mov r1, r6 */
/* @0x19146c str r0, [r5, #0x10] */
/* @0x191470 bl 0xb65b0 <memset@plt> */
/* @0x191474 ldr r2, [r5] */
/* @0x191478 vldr s15, [pc, #128] */
/* @0x19147c str r6, [r5, #0x4] */
/* @0x191480 cmp r2, r6 */
/* @0x191484 vmov s13, r2 */
/* @0x191488 vcvt.f32.s32 s14, s13 */
/* @0x19148c vmul.f32 s15, s14, s15 */
/* @0x191490 vcvt.s32.f32 s15, s15 */
/* @0x191494 vstr s15, [r5, #12] */
/* @0x191498 ble 0x1914bc <_ZN13CGCGeneration5ResetEv+0xb0> */
/* @0x19149c ldr r3, [r5, #0x10] */
/* @0x1914a0 add r2, r2, r2, lsl #1 */
/* @0x1914a4 mov r1, r6 */
/* @0x1914a8 add r2, r3, r2, lsl #2 */
/* @0x1914ac str r1, [r3, #0x8] */
/* @0x1914b0 add r3, r3, #12 */
/* @0x1914b4 cmp r3, r2 */
/* @0x1914b8 bne 0x1914ac <_ZN13CGCGeneration5ResetEv+0xa0> */
/* @0x1914bc ldr r3, [pc, #0x44] */
/* @0x1914c0 mvn r2, #0 */
/* @0x1914c4 mvn r1, #-2147483648 */
/* @0x1914c8 str r2, [r4, #0x18] */
/* @0x1914cc ldr r3, [pc, r3] */
/* @0x1914d0 str r1, [r4, #0x14] */
/* @0x1914d4 str r2, [r4, #0x1c] */
/* @0x1914d8 ldr r3, [r3] */
/* @0x1914dc str r3, [r4, #0x2c] */
/* @0x1914e0 mov r3, #0 */
/* @0x1914e4 str r3, [r4, #0x20] */
/* @0x1914e8 str r3, [r4, #0x24] */
/* @0x1914ec str r3, [r4, #0x28] */
/* @0x1914f0 str r3, [r4, #0x30] */
/* @0x1914f4 str r3, [r4, #0x34] */
/* @0x1914f8 str r3, [r4, #0x38] */
/* @0x1914fc pop {r3, r4, r5, r6, r7, pc} */
/* @0x191500 svclo #0x19999a */
/* @0x191504 andseq pc, r9, r8, ror #23 */
/* @0x191508 eoreq r12, r5, r4, asr #15 */

/* ── FUNC 0x19150c · CGCGeneration::UpdateRange(int) · size=36 · insn=9 */
/* @0x19150c ldr r2, [r0, #0x14] */
/* @0x191510 ldr r3, [r0, #0x18] */
/* @0x191514 cmp r2, r1 */
/* @0x191518 strle r2, [r0, #0x14] */
/* @0x19151c strgt r1, [r0, #0x14] */
/* @0x191520 cmp r3, r1 */
/* @0x191524 strge r3, [r0, #0x18] */
/* @0x191528 strlt r1, [r0, #0x18] */
/* @0x19152c bx lr */

/* ── FUNC 0x191530 · CGCGeneration::ResetClassStats() · size=72 · insn=18 */
/* @0x191530 push {r3, r4, r5, lr} */
/* @0x191534 mov r5, r0 */
/* @0x191538 ldr r3, [r0, #0x4c] */
/* @0x19153c cmp r3, #0 */
/* @0x191540 movne r3, #0 */
/* @0x191544 movne r4, r3 */
/* @0x191548 beq 0x19156c <_ZN13CGCGeneration15ResetClassStatsEv+0x3c> */
/* @0x19154c ldr r2, [r5, #0x48] */
/* @0x191550 add r4, r4, #1 */
/* @0x191554 ldr r0, [r2, r3, lsl #3] */
/* @0x191558 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19155c ldr r2, [r5, #0x4c] */
/* @0x191560 mov r3, r4 */
/* @0x191564 cmp r4, r2 */
/* @0x191568 blo 0x19154c <_ZN13CGCGeneration15ResetClassStatsEv+0x1c> */
/* @0x19156c mov r3, #0 */
/* @0x191570 str r3, [r5, #0x4c] */
/* @0x191574 pop {r3, r4, r5, pc} */

/* ── FUNC 0x191578 · CGCGeneration::AddClassStat(char const*) · size=408 · insn=102 */
/* @0x191578 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x19157c subs r7, r1, #0 */
/* @0x191580 sub sp, sp, #12 */
/* @0x191584 mov r9, r0 */
/* @0x191588 ldr r6, [r0, #0x4c] */
/* @0x19158c ldr r5, [r0, #0x48] */
/* @0x191590 beq 0x1916b4 <_ZN13CGCGeneration12AddClassStatEPKc+0x13c> */
/* @0x191594 cmp r6, #0 */
/* @0x191598 movne r3, #0 */
/* @0x19159c movne r4, r3 */
/* @0x1915a0 beq 0x1915d4 <_ZN13CGCGeneration12AddClassStatEPKc+0x5c> */
/* @0x1915a4 ldr r0, [r5, r3, lsl #3] */
/* @0x1915a8 mov r1, r7 */
/* @0x1915ac add r4, r4, #1 */
/* @0x1915b0 add r8, r5, r3, lsl #3 */
/* @0x1915b4 cmp r0, #0 */
/* @0x1915b8 beq 0x1915c8 <_ZN13CGCGeneration12AddClassStatEPKc+0x50> */
/* @0x1915bc bl 0xb6574 <strcmp@plt> */
/* @0x1915c0 cmp r0, #0 */
/* @0x1915c4 beq 0x19164c <_ZN13CGCGeneration12AddClassStatEPKc+0xd4> */
/* @0x1915c8 cmp r4, r6 */
/* @0x1915cc mov r3, r4 */
/* @0x1915d0 bne 0x1915a4 <_ZN13CGCGeneration12AddClassStatEPKc+0x2c> */
/* @0x1915d4 ldr r3, [r9, #0x50] */
/* @0x1915d8 cmp r3, r6 */
/* @0x1915dc beq 0x191660 <_ZN13CGCGeneration12AddClassStatEPKc+0xe8> */
/* @0x1915e0 cmp r7, #0 */
/* @0x1915e4 streq r7, [r5, r6, lsl #3] */
/* @0x1915e8 addeq r5, r5, r6, lsl #3 */
/* @0x1915ec beq 0x191634 <_ZN13CGCGeneration12AddClassStatEPKc+0xbc> */
/* @0x1915f0 mov r0, r7 */
/* @0x1915f4 bl 0xb6538 <strlen@plt> */
/* @0x1915f8 ldr r1, [pc, #0x108] */
/* @0x1915fc mov r3, #1 */
/* @0x191600 mov r2, #70 */
/* @0x191604 add r1, pc, r1 */
/* @0x191608 add r0, r0, r3 */
/* @0x19160c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x191610 ldr r2, [r9, #0x4c] */
/* @0x191614 ldr r3, [r9, #0x48] */
/* @0x191618 mov r1, r7 */
/* @0x19161c str r0, [r5, r6, lsl #3] */
/* @0x191620 ldr r0, [r3, r2, lsl #3] */
/* @0x191624 bl 0xb65a4 <strcpy@plt> */
/* @0x191628 ldr r6, [r9, #0x4c] */
/* @0x19162c ldr r5, [r9, #0x48] */
/* @0x191630 add r5, r5, r6, lsl #3 */
/* @0x191634 add r6, r6, #1 */
/* @0x191638 mov r3, #1 */
/* @0x19163c str r3, [r5, #0x4] */
/* @0x191640 str r6, [r9, #0x4c] */
/* @0x191644 add sp, sp, #12 */
/* @0x191648 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x19164c ldr r3, [r8, #0x4] */
/* @0x191650 add r3, r3, #1 */
/* @0x191654 str r3, [r8, #0x4] */
/* @0x191658 add sp, sp, #12 */
/* @0x19165c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x191660 lsls r3, r6, #1 */
/* @0x191664 ldr r2, [pc, #0xa0] */
/* @0x191668 strne r3, [r9, #0x50] */
/* @0x19166c lslne r1, r6, #4 */
/* @0x191670 moveq r3, #1 */
/* @0x191674 moveq r1, #8 */
/* @0x191678 streq r3, [r9, #0x50] */
/* @0x19167c mov r0, r5 */
/* @0x191680 mov r3, #0 */
/* @0x191684 add r2, pc, r2 */
/* @0x191688 str r3, [sp] */
/* @0x19168c mov r3, #74 */
/* @0x191690 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x191694 ldr r6, [r9, #0x4c] */
/* @0x191698 cmp r7, #0 */
/* @0x19169c mov r5, r0 */
/* @0x1916a0 str r0, [r9, #0x48] */
/* @0x1916a4 streq r7, [r5, r6, lsl #3] */
/* @0x1916a8 addeq r5, r5, r6, lsl #3 */
/* @0x1916ac bne 0x1915f0 <_ZN13CGCGeneration12AddClassStatEPKc+0x78> */
/* @0x1916b0 b 0x191634 <_ZN13CGCGeneration12AddClassStatEPKc+0xbc> */
/* @0x1916b4 cmp r6, #0 */
/* @0x1916b8 beq 0x1915d4 <_ZN13CGCGeneration12AddClassStatEPKc+0x5c> */
/* @0x1916bc ldr r3, [r5] */
/* @0x1916c0 cmp r3, #0 */
/* @0x1916c4 addne r2, r5, #8 */
/* @0x1916c8 movne r3, r7 */
/* @0x1916cc bne 0x1916e0 <_ZN13CGCGeneration12AddClassStatEPKc+0x168> */
/* @0x1916d0 b 0x1916f4 <_ZN13CGCGeneration12AddClassStatEPKc+0x17c> */
/* @0x1916d4 ldr r1, [r2], #8 */
/* @0x1916d8 cmp r1, #0 */
/* @0x1916dc beq 0x1916f8 <_ZN13CGCGeneration12AddClassStatEPKc+0x180> */
/* @0x1916e0 add r3, r3, #1 */
/* @0x1916e4 mov r0, r2 */
/* @0x1916e8 cmp r3, r6 */
/* @0x1916ec bne 0x1916d4 <_ZN13CGCGeneration12AddClassStatEPKc+0x15c> */
/* @0x1916f0 b 0x1915d4 <_ZN13CGCGeneration12AddClassStatEPKc+0x5c> */
/* @0x1916f4 mov r0, r5 */
/* @0x1916f8 ldr r3, [r0, #0x4] */
/* @0x1916fc add r3, r3, #1 */
/* @0x191700 str r3, [r0, #0x4] */
/* @0x191704 b 0x191644 <_ZN13CGCGeneration12AddClassStatEPKc+0xcc> */
/* @0x191708 andseq pc, r9, r12, lsr #20 */
/* @0x19170c andseq pc, r9, r12, lsr #19 */

/* ── FUNC 0x191710 · DeterminePotentialRoot(YYObjectBase*, YYObjectBase*) · size=4 · insn=1 */
/* @0x191710 bx lr */

/* ── FUNC 0x191714 · YYObjectBase::GetDispose(YYObjectBase*) · size=128 · insn=32 */
/* @0x191714 push {r3, r4, r5, lr} */
/* @0x191718 mvn r5, #-16777216 */
/* @0x19171c ldr r3, [r1, #0x48] */
/* @0x191720 mov r4, r0 */
/* @0x191724 str r5, [r0, #0xc] */
/* @0x191728 cmp r3, #0 */
/* @0x19172c bne 0x19173c <_ZN12YYObjectBase10GetDisposeEPS_+0x28> */
/* @0x191730 ldr r3, [r1, #0x4] */
/* @0x191734 cmp r3, #0 */
/* @0x191738 beq 0x191744 <_ZN12YYObjectBase10GetDisposeEPS_+0x30> */
/* @0x19173c mov r0, r4 */
/* @0x191740 pop {r3, r4, r5, pc} */
/* @0x191744 ldr r3, [r1, #0x28] */
/* @0x191748 ands r3, r3, #2 */
/* @0x19174c bne 0x19173c <_ZN12YYObjectBase10GetDisposeEPS_+0x28> */
/* @0x191750 ldr r2, [pc, #0x38] */
/* @0x191754 str r3, [r0] */
/* @0x191758 mov r0, r1 */
/* @0x19175c str r3, [r4, #0x4] */
/* @0x191760 mov r1, r4 */
/* @0x191764 str r3, [r4, #0x8] */
/* @0x191768 add r2, pc, r2 */
/* @0x19176c bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x191770 ldr r3, [r4, #0xc] */
/* @0x191774 cmp r3, r5 */
/* @0x191778 beq 0x19173c <_ZN12YYObjectBase10GetDisposeEPS_+0x28> */
/* @0x19177c mov r0, r4 */
/* @0x191780 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x191784 cmp r0, #0 */
/* @0x191788 streq r5, [r4, #0xc] */
/* @0x19178c b 0x19173c <_ZN12YYObjectBase10GetDisposeEPS_+0x28> */
/* @0x191790 andseq r1, r10, r4, asr #32 */

/* ── FUNC 0x191794 · YYObjectBase::FreeAll() · size=72 · insn=18 */
/* @0x191794 push {r3, r4, r5, lr} */
/* @0x191798 ldr r5, [pc, #0x38] */
/* @0x19179c ldr r5, [pc, r5] */
/* @0x1917a0 ldr r3, [r5] */
/* @0x1917a4 cmp r3, #0 */
/* @0x1917a8 beq 0x1917cc <_ZN12YYObjectBase7FreeAllEv+0x38> */
/* @0x1917ac ldr r2, [r3] */
/* @0x1917b0 mov r0, r3 */
/* @0x1917b4 ldr r4, [r3, #0x8] */
/* @0x1917b8 ldr r3, [r2, #0x4] */
/* @0x1917bc blx r3 */
/* @0x1917c0 cmp r4, #0 */
/* @0x1917c4 mov r3, r4 */
/* @0x1917c8 bne 0x1917ac <_ZN12YYObjectBase7FreeAllEv+0x18> */
/* @0x1917cc mov r3, #0 */
/* @0x1917d0 str r3, [r5] */
/* @0x1917d4 pop {r3, r4, r5, pc} */
/* @0x1917d8 eoreq r12, r5, r4, ror r4 */

/* ── FUNC 0x1917dc · YYObjectBase::AllocVars() · size=176 · insn=44 */
/* @0x1917dc push {r4, r5, r6, lr} */
/* @0x1917e0 mov r6, r0 */
/* @0x1917e4 mov r5, #0 */
/* @0x1917e8 mov r0, #20 */
/* @0x1917ec str r5, [r6, #0x5c] */
/* @0x1917f0 bl 0x27c524 <_Znwj> */
/* @0x1917f4 ldr r1, [pc, #0x8c] */
/* @0x1917f8 mov r2, #8 */
/* @0x1917fc mov r3, #7 */
/* @0x191800 add r1, pc, r1 */
/* @0x191804 mov r4, r0 */
/* @0x191808 str r2, [r0] */
/* @0x19180c str r3, [r0, #0x8] */
/* @0x191810 mov r2, #70 */
/* @0x191814 str r5, [r0, #0x10] */
/* @0x191818 mov r3, #1 */
/* @0x19181c mov r0, #96 */
/* @0x191820 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x191824 mov r2, #96 */
/* @0x191828 mov r1, r5 */
/* @0x19182c str r0, [r4, #0x10] */
/* @0x191830 bl 0xb65b0 <memset@plt> */
/* @0x191834 ldr r2, [r4] */
/* @0x191838 vldr s15, [pc, #68] */
/* @0x19183c str r5, [r4, #0x4] */
/* @0x191840 cmp r2, r5 */
/* @0x191844 vmov s13, r2 */
/* @0x191848 vcvt.f32.s32 s14, s13 */
/* @0x19184c vmul.f32 s15, s14, s15 */
/* @0x191850 vcvt.s32.f32 s15, s15 */
/* @0x191854 vstr s15, [r4, #12] */
/* @0x191858 ble 0x19187c <_ZN12YYObjectBase9AllocVarsEv+0xa0> */
/* @0x19185c add r2, r2, r2, lsl #1 */
/* @0x191860 ldr r3, [r4, #0x10] */
/* @0x191864 mov r1, r5 */
/* @0x191868 add r2, r3, r2, lsl #2 */
/* @0x19186c str r1, [r3, #0x8] */
/* @0x191870 add r3, r3, #12 */
/* @0x191874 cmp r3, r2 */
/* @0x191878 bne 0x19186c <_ZN12YYObjectBase9AllocVarsEv+0x90> */
/* @0x19187c str r4, [r6, #0x60] */
/* @0x191880 pop {r4, r5, r6, pc} */
/* @0x191884 svclo #0x19999a */
/* @0x191888 andseq pc, r9, r0, lsr r8 */

/* ── FUNC 0x19188c · YYObjectBase::YYObjectBase(int, int) · size=256 · insn=64 */
/* @0x19188c ldr r12, [pc, #0xe0] */
/* @0x191890 push {r4, r5, r6, lr} */
/* @0x191894 add r12, pc, r12 */
/* @0x191898 mov r4, r0 */
/* @0x19189c ldr r0, [pc, #0xd4] */
/* @0x1918a0 ldr r5, [pc, #0xd4] */
/* @0x1918a4 add r0, pc, r0 */
/* @0x1918a8 ldrb r3, [r12] */
/* @0x1918ac ldr r5, [r0, r5] */
/* @0x1918b0 cmp r3, #0 */
/* @0x1918b4 add r5, r5, #8 */
/* @0x1918b8 str r5, [r4] */
/* @0x1918bc bne 0x1918dc <_ZN12YYObjectBaseC2Eii+0x50> */
/* @0x1918c0 ldr r5, [pc, #0xb8] */
/* @0x1918c4 mov r6, #1 */
/* @0x1918c8 ldr r5, [r0, r5] */
/* @0x1918cc strb r6, [r12] */
/* @0x1918d0 str r3, [r5, #0x4] */
/* @0x1918d4 str r3, [r5, #0x8] */
/* @0x1918d8 str r3, [r5, #0xc] */
/* @0x1918dc ldr r12, [pc, #0xa0] */
/* @0x1918e0 mov r3, #0 */
/* @0x1918e4 str r3, [r4, #0x18] */
/* @0x1918e8 mvn r5, #0 */
/* @0x1918ec str r3, [r4, #0x20] */
/* @0x1918f0 str r3, [r4, #0x1c] */
/* @0x1918f4 str r3, [r4, #0x30] */
/* @0x1918f8 ldr r12, [r0, r12] */
/* @0x1918fc str r3, [r4, #0x38] */
/* @0x191900 str r3, [r4, #0x48] */
/* @0x191904 ldr r12, [r12] */
/* @0x191908 str r3, [r4, #0x4] */
/* @0x19190c str r3, [r4, #0x60] */
/* @0x191910 ldr r3, [pc, #0x70] */
/* @0x191914 str r1, [r4, #0x24] */
/* @0x191918 str r1, [r4, #0x2c] */
/* @0x19191c mov r1, #1 */
/* @0x191920 str r2, [r4, #0x58] */
/* @0x191924 mov r2, #0 */
/* @0x191928 str r12, [r4, #0x34] */
/* @0x19192c str r12, [r4, #0x3c] */
/* @0x191930 str r5, [r4, #0x44] */
/* @0x191934 str r1, [r4, #0x28] */
/* @0x191938 str r2, [r4, #0x4c] */
/* @0x19193c ldr r3, [r0, r3] */
/* @0x191940 ldrb r3, [r3] */
/* @0x191944 cmp r3, r2 */
/* @0x191948 streq r3, [r4, #0x10] */
/* @0x19194c streq r3, [r4, #0x14] */
/* @0x191950 bne 0x19195c <_ZN12YYObjectBaseC2Eii+0xd0> */
/* @0x191954 mov r0, r4 */
/* @0x191958 pop {r4, r5, r6, pc} */
/* @0x19195c bl 0x27d258 <_ZN13MemoryManager13GetStackTraceEv> */
/* @0x191960 str r0, [r4, #0x10] */
/* @0x191964 bl 0xdb934 <_Z14vmGetCallStackv> */
/* @0x191968 str r0, [r4, #0x14] */
/* @0x19196c mov r0, r4 */
/* @0x191970 pop {r4, r5, r6, pc} */
/* @0x191974 ldrsbteq r5, [r10], -r12 */
/* @0x191978 eoreq r0, r6, r12, lsr #7 */
/* @0x19197c .word 0xffffea28 */
/* @0x191980 .word 0xffffea20 */
/* @0x191984 .word 0xffffbffc */
/* @0x191988 .word 0xffffc7cc */

/* ── FUNC 0x19188c · YYObjectBase::YYObjectBase(int, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x19198c · YYObjectBase::Alloc(unsigned int, int, bool) · size=544 · insn=136 */
/* @0x19198c ldr r3, [pc, #0x204] */
/* @0x191990 push {r4, r5, r6, r7, r8, lr} */
/* @0x191994 ldr r3, [pc, r3] */
/* @0x191998 sub sp, sp, #8 */
/* @0x19199c mov r6, r0 */
/* @0x1919a0 ldr r5, [r3] */
/* @0x1919a4 mov r4, r1 */
/* @0x1919a8 mov r7, r2 */
/* @0x1919ac cmp r5, #0 */
/* @0x1919b0 beq 0x191b2c <_ZN12YYObjectBase5AllocEjib+0x1a0> */
/* @0x1919b4 ldr r1, [r5, #0x2c] */
/* @0x1919b8 ldr r2, [r5, #0x8] */
/* @0x1919bc cmp r1, r0 */
/* @0x1919c0 str r2, [r3] */
/* @0x1919c4 blo 0x191ab4 <_ZN12YYObjectBase5AllocEjib+0x128> */
/* @0x1919c8 cmp r4, #5 */
/* @0x1919cc mov r3, #0 */
/* @0x1919d0 str r6, [r5, #0x24] */
/* @0x1919d4 str r4, [r5, #0x58] */
/* @0x1919d8 str r3, [r5, #0x48] */
/* @0x1919dc beq 0x191a08 <_ZN12YYObjectBase5AllocEjib+0x7c> */
/* @0x1919e0 ldr r3, [r5, #0x4] */
/* @0x1919e4 cmp r3, #0 */
/* @0x1919e8 beq 0x191a08 <_ZN12YYObjectBase5AllocEjib+0x7c> */
/* @0x1919ec cmp r6, #0 */
/* @0x1919f0 mov r12, r6 */
/* @0x1919f4 ble 0x191a08 <_ZN12YYObjectBase5AllocEjib+0x7c> */
/* @0x1919f8 subs r12, r12, #1 */
/* @0x1919fc str r4, [r3, #0xc] */
/* @0x191a00 add r3, r3, #16 */
/* @0x191a04 bne 0x1919f8 <_ZN12YYObjectBase5AllocEjib+0x6c> */
/* @0x191a08 cmp r7, #0 */
/* @0x191a0c beq 0x191a1c <_ZN12YYObjectBase5AllocEjib+0x90> */
/* @0x191a10 ldr r0, [r5, #0x4] */
/* @0x191a14 cmp r0, #0 */
/* @0x191a18 beq 0x191b48 <_ZN12YYObjectBase5AllocEjib+0x1bc> */
/* @0x191a1c ldr r6, [pc, #0x178] */
/* @0x191a20 ldr r6, [pc, r6] */
/* @0x191a24 ldmib r6, {r4, r7} */
/* @0x191a28 cmp r7, r4 */
/* @0x191a2c bge 0x191ae8 <_ZN12YYObjectBase5AllocEjib+0x15c> */
/* @0x191a30 cmp r4, #0 */
/* @0x191a34 ldr r3, [r6, #0xc] */
/* @0x191a38 ble 0x191a80 <_ZN12YYObjectBase5AllocEjib+0xf4> */
/* @0x191a3c ldr r12, [r6] */
/* @0x191a40 mov r1, r4 */
/* @0x191a44 b 0x191a54 <_ZN12YYObjectBase5AllocEjib+0xc8> */
/* @0x191a48 subs r1, r1, #1 */
/* @0x191a4c add r3, r3, #1 */
/* @0x191a50 beq 0x191a80 <_ZN12YYObjectBase5AllocEjib+0xf4> */
/* @0x191a54 cmp r4, r3 */
/* @0x191a58 lsl r2, r3, #2 */
/* @0x191a5c movle r3, #0 */
/* @0x191a60 movle r2, r3 */
/* @0x191a64 add r0, r12, r2 */
/* @0x191a68 ldr r2, [r12, r2] */
/* @0x191a6c cmp r2, #0 */
/* @0x191a70 bne 0x191a48 <_ZN12YYObjectBase5AllocEjib+0xbc> */
/* @0x191a74 str r5, [r0] */
/* @0x191a78 str r3, [r6, #0xc] */
/* @0x191a7c b 0x191a84 <_ZN12YYObjectBase5AllocEjib+0xf8> */
/* @0x191a80 mvn r3, #0 */
/* @0x191a84 ldr r2, [pc, #0x114] */
/* @0x191a88 add r7, r7, #1 */
/* @0x191a8c str r3, [r5, #0x44] */
/* @0x191a90 mov r3, #0 */
/* @0x191a94 ldr r2, [pc, r2] */
/* @0x191a98 str r3, [r5, #0x38] */
/* @0x191a9c mov r0, r5 */
/* @0x191aa0 str r7, [r6, #0x8] */
/* @0x191aa4 ldr r3, [r2] */
/* @0x191aa8 str r3, [r5, #0x3c] */
/* @0x191aac add sp, sp, #8 */
/* @0x191ab0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x191ab4 cmp r7, #0 */
/* @0x191ab8 str r0, [r5, #0x2c] */
/* @0x191abc beq 0x1919c8 <_ZN12YYObjectBase5AllocEjib+0x3c> */
/* @0x191ac0 ldr r2, [pc, #0xdc] */
/* @0x191ac4 mov r3, #0 */
/* @0x191ac8 ldr r0, [r5, #0x4] */
/* @0x191acc lsl r1, r6, #4 */
/* @0x191ad0 str r3, [sp] */
/* @0x191ad4 add r2, pc, r2 */
/* @0x191ad8 mov r3, #74 */
/* @0x191adc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x191ae0 str r0, [r5, #0x4] */
/* @0x191ae4 b 0x1919c8 <_ZN12YYObjectBase5AllocEjib+0x3c> */
/* @0x191ae8 add r4, r4, r4, lsl #1 */
/* @0x191aec ldr r0, [r6] */
/* @0x191af0 add r4, r4, r4, lsr #31 */
/* @0x191af4 asr r8, r4, #1 */
/* @0x191af8 lsl r1, r8, #2 */
/* @0x191afc mov r4, r8 */
/* @0x191b00 bl 0xcef64 <_Z9YYReallocPvi> */
/* @0x191b04 ldr r3, [r6, #0x4] */
/* @0x191b08 mov r1, #0 */
/* @0x191b0c rsb r2, r3, r8 */
/* @0x191b10 lsl r2, r2, #2 */
/* @0x191b14 str r0, [r6] */
/* @0x191b18 add r0, r0, r3, lsl #2 */
/* @0x191b1c bl 0xb65b0 <memset@plt> */
/* @0x191b20 ldr r7, [r6, #0x8] */
/* @0x191b24 str r8, [r6, #0x4] */
/* @0x191b28 b 0x191a30 <_ZN12YYObjectBase5AllocEjib+0xa4> */
/* @0x191b2c mov r0, #100 */
/* @0x191b30 bl 0x27c524 <_Znwj> */
/* @0x191b34 mov r1, r6 */
/* @0x191b38 mov r2, r4 */
/* @0x191b3c mov r5, r0 */
/* @0x191b40 bl 0x19188c <_ZN12YYObjectBaseC2Eii> */
/* @0x191b44 b 0x191a08 <_ZN12YYObjectBase5AllocEjib+0x7c> */
/* @0x191b48 ldr r2, [pc, #0x58] */
/* @0x191b4c lsl r1, r6, #4 */
/* @0x191b50 str r0, [sp] */
/* @0x191b54 mov r3, #74 */
/* @0x191b58 add r2, pc, r2 */
/* @0x191b5c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x191b60 cmp r4, #5 */
/* @0x191b64 str r6, [r5, #0x2c] */
/* @0x191b68 str r0, [r5, #0x4] */
/* @0x191b6c beq 0x191a1c <_ZN12YYObjectBase5AllocEjib+0x90> */
/* @0x191b70 cmp r0, #0 */
/* @0x191b74 beq 0x191a1c <_ZN12YYObjectBase5AllocEjib+0x90> */
/* @0x191b78 ldr r3, [r5, #0x24] */
/* @0x191b7c cmp r3, #0 */
/* @0x191b80 ble 0x191a1c <_ZN12YYObjectBase5AllocEjib+0x90> */
/* @0x191b84 subs r3, r3, #1 */
/* @0x191b88 str r4, [r0, #0xc] */
/* @0x191b8c add r0, r0, #16 */
/* @0x191b90 bne 0x191b84 <_ZN12YYObjectBase5AllocEjib+0x1f8> */
/* @0x191b94 b 0x191a1c <_ZN12YYObjectBase5AllocEjib+0x90> */
/* @0x191b98 eoreq r12, r5, r12, ror r2 */
/* @0x191b9c eoreq r12, r5, r4, asr #4 */
/* @0x191ba0 .word 0x0025c1b8 */
/* @0x191ba4 andseq pc, r9, r12, asr r5 */
/* @0x191ba8 ldrsbeq pc, [r9], -r8 */

/* ── FUNC 0x191bac · RVALUE_GC_ADDROOT(RValue const*, CGCGeneration*) · size=48 · insn=12 */
/* @0x191bac ldr r2, [r0] */
/* @0x191bb0 cmp r2, #0 */
/* @0x191bb4 bxeq lr */
/* @0x191bb8 ldr r3, [r0, #0xc] */
/* @0x191bbc bic r3, r3, #-16777216 */
/* @0x191bc0 cmp r3, #6 */
/* @0x191bc4 cmpne r3, #11 */
/* @0x191bc8 bxne lr */
/* @0x191bcc mov r0, r1 */
/* @0x191bd0 mov r1, r2 */
/* @0x191bd4 mov r2, #1 */
/* @0x191bd8 b 0x19135c <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb> */

/* ── FUNC 0x191bdc · YYObjectBase::Mark4GC(unsigned int*, int) · size=476 · insn=119 */
/* @0x191bdc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x191be0 mov r8, r0 */
/* @0x191be4 ldr r3, [pc, #0x1b8] */
/* @0x191be8 mov r6, r2 */
/* @0x191bec ldr r0, [pc, #0x1b4] */
/* @0x191bf0 mov r7, r1 */
/* @0x191bf4 add r3, pc, r3 */
/* @0x191bf8 ldr r2, [r3, r0] */
/* @0x191bfc ldrb r1, [r2] */
/* @0x191c00 cmp r1, #0 */
/* @0x191c04 bne 0x191c20 <_ZN12YYObjectBase7Mark4GCEPji+0x44> */
/* @0x191c08 ldr r1, [pc, #0x19c] */
/* @0x191c0c ldr r0, [r8, #0x38] */
/* @0x191c10 ldr r1, [r3, r1] */
/* @0x191c14 ldr r1, [r1] */
/* @0x191c18 cmp r0, r1 */
/* @0x191c1c popgt {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x191c20 ldr r0, [pc, #0x188] */
/* @0x191c24 mov r1, #0 */
/* @0x191c28 strb r1, [r2] */
/* @0x191c2c ldr r1, [r8, #0x34] */
/* @0x191c30 ldr r2, [r3, r0] */
/* @0x191c34 ldr r2, [r2] */
/* @0x191c38 cmp r1, r2 */
/* @0x191c3c pophs {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x191c40 ldr r1, [pc, #0x16c] */
/* @0x191c44 str r2, [r8, #0x34] */
/* @0x191c48 ldr r2, [r8, #0x48] */
/* @0x191c4c ldr r3, [r3, r1] */
/* @0x191c50 cmp r2, #3 */
/* @0x191c54 ldr r1, [r8, #0x28] */
/* @0x191c58 ldr r2, [r3] */
/* @0x191c5c bic r1, r1, #2 */
/* @0x191c60 str r1, [r8, #0x28] */
/* @0x191c64 add r2, r2, #1 */
/* @0x191c68 str r2, [r3] */
/* @0x191c6c beq 0x191d80 <_ZN12YYObjectBase7Mark4GCEPji+0x1a4> */
/* @0x191c70 ldr r3, [r8, #0x44] */
/* @0x191c74 cmp r3, #0 */
/* @0x191c78 blt 0x191c84 <_ZN12YYObjectBase7Mark4GCEPji+0xa8> */
/* @0x191c7c cmp r6, r3 */
/* @0x191c80 bgt 0x191d64 <_ZN12YYObjectBase7Mark4GCEPji+0x188> */
/* @0x191c84 ldr r0, [r8, #0x18] */
/* @0x191c88 cmp r0, #0 */
/* @0x191c8c beq 0x191c9c <_ZN12YYObjectBase7Mark4GCEPji+0xc0> */
/* @0x191c90 mov r1, r7 */
/* @0x191c94 mov r2, r6 */
/* @0x191c98 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji> */
/* @0x191c9c ldr r12, [r8, #0x60] */
/* @0x191ca0 cmp r12, #0 */
/* @0x191ca4 beq 0x191d18 <_ZN12YYObjectBase7Mark4GCEPji+0x13c> */
/* @0x191ca8 ldr r3, [r12, #0x4] */
/* @0x191cac cmp r3, #0 */
/* @0x191cb0 ble 0x191d18 <_ZN12YYObjectBase7Mark4GCEPji+0x13c> */
/* @0x191cb4 mov r4, #0 */
/* @0x191cb8 mov r9, r4 */
/* @0x191cbc add r3, r4, r4, lsl #1 */
/* @0x191cc0 ldr r2, [r12, #0x10] */
/* @0x191cc4 ldr r5, [r12] */
/* @0x191cc8 add r3, r2, r3, lsl #2 */
/* @0x191ccc b 0x191cdc <_ZN12YYObjectBase7Mark4GCEPji+0x100> */
/* @0x191cd0 ldr lr, [r12, #0x8] */
/* @0x191cd4 cmp lr, #0 */
/* @0x191cd8 bgt 0x191d5c <_ZN12YYObjectBase7Mark4GCEPji+0x180> */
/* @0x191cdc add r4, r4, #1 */
/* @0x191ce0 mov r12, r3 */
/* @0x191ce4 cmp r5, r4 */
/* @0x191ce8 add r3, r3, #12 */
/* @0x191cec bge 0x191cd0 <_ZN12YYObjectBase7Mark4GCEPji+0xf4> */
/* @0x191cf0 mov r12, #0 */
/* @0x191cf4 ldr r0, [r12] */
/* @0x191cf8 mov r1, r7 */
/* @0x191cfc mov r2, r6 */
/* @0x191d00 add r9, r9, #1 */
/* @0x191d04 bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji> */
/* @0x191d08 ldr r12, [r8, #0x60] */
/* @0x191d0c ldr r3, [r12, #0x4] */
/* @0x191d10 cmp r3, r9 */
/* @0x191d14 bgt 0x191cbc <_ZN12YYObjectBase7Mark4GCEPji+0xe0> */
/* @0x191d18 ldr r4, [r8, #0x4] */
/* @0x191d1c cmp r4, #0 */
/* @0x191d20 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x191d24 ldr r3, [r8, #0x24] */
/* @0x191d28 cmp r3, #0 */
/* @0x191d2c popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x191d30 mov r5, #0 */
/* @0x191d34 mov r0, r4 */
/* @0x191d38 mov r1, r7 */
/* @0x191d3c mov r2, r6 */
/* @0x191d40 add r5, r5, #1 */
/* @0x191d44 bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji> */
/* @0x191d48 ldr r3, [r8, #0x24] */
/* @0x191d4c add r4, r4, #16 */
/* @0x191d50 cmp r3, r5 */
/* @0x191d54 bhi 0x191d34 <_ZN12YYObjectBase7Mark4GCEPji+0x158> */
/* @0x191d58 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x191d5c add r12, r12, #4 */
/* @0x191d60 b 0x191cf4 <_ZN12YYObjectBase7Mark4GCEPji+0x118> */
/* @0x191d64 asr r2, r3, #5 */
/* @0x191d68 mov r0, #1 */
/* @0x191d6c and r3, r3, #31 */
/* @0x191d70 ldr r1, [r7, r2, lsl #2] */
/* @0x191d74 orr r3, r1, r0, lsl r3 */
/* @0x191d78 str r3, [r7, r2, lsl #2] */
/* @0x191d7c b 0x191c84 <_ZN12YYObjectBase7Mark4GCEPji+0xa8> */
/* @0x191d80 add r0, r8, #108 */
/* @0x191d84 mov r1, r7 */
/* @0x191d88 mov r2, r6 */
/* @0x191d8c bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji> */
/* @0x191d90 add r0, r8, #124 */
/* @0x191d94 mov r1, r7 */
/* @0x191d98 mov r2, r6 */
/* @0x191d9c bl 0x191db8 <_Z9RVALUE_GCPK6RValuePji> */
/* @0x191da0 b 0x191c70 <_ZN12YYObjectBase7Mark4GCEPji+0x94> */
/* @0x191da4 eoreq r0, r6, r12, asr r0 */
/* @0x191da8 .word 0xffffc03c */
/* @0x191dac .word 0xffffc038 */
/* @0x191db0 .word 0xffffbffc */
/* @0x191db4 .word 0xffffc034 */

/* ── FUNC 0x191db8 · RVALUE_GC(RValue const*, unsigned int*, int) · size=40 · insn=10 */
/* @0x191db8 ldr r12, [r0] */
/* @0x191dbc cmp r12, #0 */
/* @0x191dc0 bxeq lr */
/* @0x191dc4 ldr r3, [r0, #0xc] */
/* @0x191dc8 bic r3, r3, #-16777216 */
/* @0x191dcc cmp r3, #6 */
/* @0x191dd0 cmpne r3, #11 */
/* @0x191dd4 bxne lr */
/* @0x191dd8 mov r0, r12 */
/* @0x191ddc b 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji> */

/* ── FUNC 0x191de0 · CScriptRef::CScriptRef(int, int) · size=300 · insn=75 */
/* @0x191de0 push {r3, r4, r5, r6, r7, lr} */
/* @0x191de4 mov r4, r0 */
/* @0x191de8 bl 0x19188c <_ZN12YYObjectBaseC2Eii> */
/* @0x191dec ldr r6, [pc, #0x110] */
/* @0x191df0 mov r5, #0 */
/* @0x191df4 ldr r3, [pc, #0x10c] */
/* @0x191df8 mov r2, #3 */
/* @0x191dfc ldr r6, [pc, r6] */
/* @0x191e00 str r2, [r4, #0x48] */
/* @0x191e04 ldr r3, [pc, r3] */
/* @0x191e08 str r5, [r4, #0x64] */
/* @0x191e0c ldr r7, [r6, #0x8] */
/* @0x191e10 add r3, r3, #8 */
/* @0x191e14 ldr r0, [r6, #0x4] */
/* @0x191e18 str r5, [r4, #0x68] */
/* @0x191e1c cmp r7, r0 */
/* @0x191e20 str r3, [r4] */
/* @0x191e24 str r5, [r4, #0x8c] */
/* @0x191e28 mvn r3, #-16777216 */
/* @0x191e2c str r5, [r4, #0x90] */
/* @0x191e30 str r5, [r4, #0x94] */
/* @0x191e34 str r5, [r4, #0x6c] */
/* @0x191e38 str r5, [r4, #0x70] */
/* @0x191e3c str r5, [r4, #0x74] */
/* @0x191e40 str r5, [r4, #0x7c] */
/* @0x191e44 str r5, [r4, #0x80] */
/* @0x191e48 str r5, [r4, #0x84] */
/* @0x191e4c str r3, [r4, #0x78] */
/* @0x191e50 str r3, [r4, #0x88] */
/* @0x191e54 bge 0x191ec0 <_ZN10CScriptRefC2Eii+0xe0> */
/* @0x191e58 cmp r0, #0 */
/* @0x191e5c ldr r3, [r6, #0xc] */
/* @0x191e60 ble 0x191ea8 <_ZN10CScriptRefC2Eii+0xc8> */
/* @0x191e64 ldr r12, [r6] */
/* @0x191e68 mov r1, r0 */
/* @0x191e6c b 0x191e7c <_ZN10CScriptRefC2Eii+0x9c> */
/* @0x191e70 subs r1, r1, #1 */
/* @0x191e74 add r3, r3, #1 */
/* @0x191e78 beq 0x191ea8 <_ZN10CScriptRefC2Eii+0xc8> */
/* @0x191e7c cmp r3, r0 */
/* @0x191e80 lsl r2, r3, #2 */
/* @0x191e84 movge r3, #0 */
/* @0x191e88 movge r2, r3 */
/* @0x191e8c add r5, r12, r2 */
/* @0x191e90 ldr r2, [r12, r2] */
/* @0x191e94 cmp r2, #0 */
/* @0x191e98 bne 0x191e70 <_ZN10CScriptRefC2Eii+0x90> */
/* @0x191e9c str r4, [r5] */
/* @0x191ea0 str r3, [r6, #0xc] */
/* @0x191ea4 b 0x191eac <_ZN10CScriptRefC2Eii+0xcc> */
/* @0x191ea8 mvn r3, #0 */
/* @0x191eac add r7, r7, #1 */
/* @0x191eb0 str r3, [r4, #0x44] */
/* @0x191eb4 str r7, [r6, #0x8] */
/* @0x191eb8 mov r0, r4 */
/* @0x191ebc pop {r3, r4, r5, r6, r7, pc} */
/* @0x191ec0 add r7, r0, r0, lsl #1 */
/* @0x191ec4 ldr r0, [r6] */
/* @0x191ec8 add r7, r7, r7, lsr #31 */
/* @0x191ecc asr r7, r7, #1 */
/* @0x191ed0 lsl r1, r7, #2 */
/* @0x191ed4 bl 0xcef64 <_Z9YYReallocPvi> */
/* @0x191ed8 ldr r3, [r6, #0x4] */
/* @0x191edc mov r1, r5 */
/* @0x191ee0 rsb r2, r3, r7 */
/* @0x191ee4 lsl r2, r2, #2 */
/* @0x191ee8 str r0, [r6] */
/* @0x191eec add r0, r0, r3, lsl #2 */
/* @0x191ef0 bl 0xb65b0 <memset@plt> */
/* @0x191ef4 str r7, [r6, #0x4] */
/* @0x191ef8 mov r0, r7 */
/* @0x191efc ldr r7, [r6, #0x8] */
/* @0x191f00 b 0x191e58 <_ZN10CScriptRefC2Eii+0x78> */
/* @0x191f04 eoreq r11, r5, r8, ror #28 */
/* @0x191f08 eoreq lr, r5, r8, ror r8 */

/* ── FUNC 0x191de0 · CScriptRef::CScriptRef(int, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x191f0c · YYObjectBase::MarkThisOnly4GC(unsigned int*, int) · size=80 · insn=20 */
/* @0x191f0c ldr r3, [pc, #0x44] */
/* @0x191f10 ldr r12, [r0, #0x34] */
/* @0x191f14 ldr r3, [pc, r3] */
/* @0x191f18 ldr r3, [r3] */
/* @0x191f1c cmp r12, r3 */
/* @0x191f20 bxhs lr */
/* @0x191f24 ldr r12, [r0, #0x44] */
/* @0x191f28 str r3, [r0, #0x34] */
/* @0x191f2c cmp r12, #0 */
/* @0x191f30 bxlt lr */
/* @0x191f34 cmp r12, r2 */
/* @0x191f38 bxge lr */
/* @0x191f3c asr r3, r12, #5 */
/* @0x191f40 mov r0, #1 */
/* @0x191f44 and r12, r12, #31 */
/* @0x191f48 ldr r2, [r1, r3, lsl #2] */
/* @0x191f4c orr r12, r2, r0, lsl r12 */
/* @0x191f50 str r12, [r1, r3, lsl #2] */
/* @0x191f54 bx lr */
/* @0x191f58 eoreq r11, r5, r8, lsr sp */

/* ── FUNC 0x191f5c · RVALUE_GC_THISONLY(RValue const*, unsigned int*, int) · size=40 · insn=10 */
/* @0x191f5c ldr r12, [r0] */
/* @0x191f60 cmp r12, #0 */
/* @0x191f64 bxeq lr */
/* @0x191f68 ldr r3, [r0, #0xc] */
/* @0x191f6c bic r3, r3, #-16777216 */
/* @0x191f70 cmp r3, #6 */
/* @0x191f74 cmpne r3, #11 */
/* @0x191f78 bxne lr */
/* @0x191f7c mov r0, r12 */
/* @0x191f80 b 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji> */

/* ── FUNC 0x191f84 · YYObjectBase::MarkOnlyChildren4GC(unsigned int*, int) · size=232 · insn=58 */
/* @0x191f84 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x191f88 mov r6, r0 */
/* @0x191f8c ldr r0, [r0, #0x18] */
/* @0x191f90 mov r7, r1 */
/* @0x191f94 mov r8, r2 */
/* @0x191f98 cmp r0, #0 */
/* @0x191f9c beq 0x191fa4 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x20> */
/* @0x191fa0 bl 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji> */
/* @0x191fa4 ldr r2, [r6, #0x60] */
/* @0x191fa8 cmp r2, #0 */
/* @0x191fac beq 0x192020 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x9c> */
/* @0x191fb0 ldr r3, [r2, #0x4] */
/* @0x191fb4 cmp r3, #0 */
/* @0x191fb8 ble 0x192020 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x9c> */
/* @0x191fbc mov r4, #0 */
/* @0x191fc0 mov r9, r4 */
/* @0x191fc4 add r3, r4, r4, lsl #1 */
/* @0x191fc8 ldr r1, [r2, #0x10] */
/* @0x191fcc ldr r5, [r2] */
/* @0x191fd0 add r3, r1, r3, lsl #2 */
/* @0x191fd4 b 0x191fe4 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x60> */
/* @0x191fd8 ldr lr, [r12, #0x8] */
/* @0x191fdc cmp lr, #0 */
/* @0x191fe0 bgt 0x192064 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0xe0> */
/* @0x191fe4 add r4, r4, #1 */
/* @0x191fe8 mov r12, r3 */
/* @0x191fec cmp r5, r4 */
/* @0x191ff0 add r3, r3, #12 */
/* @0x191ff4 bge 0x191fd8 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x54> */
/* @0x191ff8 mov r12, #0 */
/* @0x191ffc mov r2, r8 */
/* @0x192000 ldr r0, [r12] */
/* @0x192004 mov r1, r7 */
/* @0x192008 add r9, r9, #1 */
/* @0x19200c bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji> */
/* @0x192010 ldr r2, [r6, #0x60] */
/* @0x192014 ldr r3, [r2, #0x4] */
/* @0x192018 cmp r3, r9 */
/* @0x19201c bgt 0x191fc4 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x40> */
/* @0x192020 ldr r4, [r6, #0x4] */
/* @0x192024 cmp r4, #0 */
/* @0x192028 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x19202c ldr r3, [r6, #0x24] */
/* @0x192030 cmp r3, #0 */
/* @0x192034 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x192038 mov r5, #0 */
/* @0x19203c mov r0, r4 */
/* @0x192040 mov r1, r7 */
/* @0x192044 mov r2, r8 */
/* @0x192048 add r5, r5, #1 */
/* @0x19204c bl 0x191f5c <_Z18RVALUE_GC_THISONLYPK6RValuePji> */
/* @0x192050 ldr r3, [r6, #0x24] */
/* @0x192054 add r4, r4, #16 */
/* @0x192058 cmp r3, r5 */
/* @0x19205c bhi 0x19203c <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0xb8> */
/* @0x192060 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x192064 add r12, r12, #4 */
/* @0x192068 b 0x191ffc <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji+0x78> */

/* ── FUNC 0x19206c · YYObjectBase::Mark4GenGC(unsigned int**, int, YYObjectBase*) · size=360 · insn=90 */
/* @0x19206c ldr r3, [pc, #0x158] */
/* @0x192070 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x192074 ldr r3, [pc, r3] */
/* @0x192078 mov r7, r0 */
/* @0x19207c mov r8, r2 */
/* @0x192080 ldr r0, [r0, #0x34] */
/* @0x192084 mov r9, r1 */
/* @0x192088 ldr r2, [r3] */
/* @0x19208c cmp r0, r2 */
/* @0x192090 pophs {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x192094 ldr r3, [pc, #0x134] */
/* @0x192098 ldr r1, [r7, #0x44] */
/* @0x19209c ldr r3, [pc, r3] */
/* @0x1920a0 str r2, [r7, #0x34] */
/* @0x1920a4 cmp r1, #0 */
/* @0x1920a8 ldr r2, [r3] */
/* @0x1920ac add r2, r2, #1 */
/* @0x1920b0 str r2, [r3] */
/* @0x1920b4 blt 0x1920e0 <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x74> */
/* @0x1920b8 cmp r1, r8 */
/* @0x1920bc bge 0x1920e0 <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x74> */
/* @0x1920c0 ldr r3, [r7, #0x38] */
/* @0x1920c4 asr r2, r1, #5 */
/* @0x1920c8 mov r12, #1 */
/* @0x1920cc and r1, r1, #31 */
/* @0x1920d0 ldr r3, [r9, r3, lsl #2] */
/* @0x1920d4 ldr r0, [r3, r2, lsl #2] */
/* @0x1920d8 orr r1, r0, r12, lsl r1 */
/* @0x1920dc str r1, [r3, r2, lsl #2] */
/* @0x1920e0 ldr r0, [r7, #0x18] */
/* @0x1920e4 cmp r0, #0 */
/* @0x1920e8 beq 0x1920fc <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x90> */
/* @0x1920ec mov r1, r9 */
/* @0x1920f0 mov r2, r8 */
/* @0x1920f4 mov r3, r7 */
/* @0x1920f8 bl 0x19206c <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_> */
/* @0x1920fc ldr r3, [r7, #0x60] */
/* @0x192100 cmp r3, #0 */
/* @0x192104 beq 0x19217c <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x110> */
/* @0x192108 ldr r2, [r3, #0x4] */
/* @0x19210c cmp r2, #0 */
/* @0x192110 ble 0x19217c <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x110> */
/* @0x192114 mov r4, #0 */
/* @0x192118 mov r10, r4 */
/* @0x19211c add r12, r4, r4, lsl #1 */
/* @0x192120 ldr r2, [r3, #0x10] */
/* @0x192124 ldr r6, [r3] */
/* @0x192128 add r12, r2, r12, lsl #2 */
/* @0x19212c b 0x19213c <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0xd0> */
/* @0x192130 ldr r5, [lr, #0x8] */
/* @0x192134 cmp r5, #0 */
/* @0x192138 bgt 0x1921c4 <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x158> */
/* @0x19213c add r4, r4, #1 */
/* @0x192140 mov lr, r12 */
/* @0x192144 cmp r6, r4 */
/* @0x192148 add r12, r12, #12 */
/* @0x19214c bge 0x192130 <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0xc4> */
/* @0x192150 mov lr, #0 */
/* @0x192154 mov r2, r8 */
/* @0x192158 mov r3, r7 */
/* @0x19215c ldr r0, [lr] */
/* @0x192160 mov r1, r9 */
/* @0x192164 bl 0x1921d4 <_Z13RVALUE_GEN_GCPK6RValuePPjiP12YYObjectBase> */
/* @0x192168 ldr r3, [r7, #0x60] */
/* @0x19216c add r10, r10, #1 */
/* @0x192170 ldr r2, [r3, #0x4] */
/* @0x192174 cmp r2, r10 */
/* @0x192178 bgt 0x19211c <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0xb0> */
/* @0x19217c ldr r4, [r7, #0x4] */
/* @0x192180 cmp r4, #0 */
/* @0x192184 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x192188 ldr r3, [r7, #0x24] */
/* @0x19218c cmp r3, #0 */
/* @0x192190 popeq {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x192194 mov r5, #0 */
/* @0x192198 mov r0, r4 */
/* @0x19219c mov r3, r7 */
/* @0x1921a0 mov r1, r9 */
/* @0x1921a4 mov r2, r8 */
/* @0x1921a8 bl 0x1921d4 <_Z13RVALUE_GEN_GCPK6RValuePPjiP12YYObjectBase> */
/* @0x1921ac ldr r3, [r7, #0x24] */
/* @0x1921b0 add r5, r5, #1 */
/* @0x1921b4 add r4, r4, #16 */
/* @0x1921b8 cmp r3, r5 */
/* @0x1921bc bhi 0x192198 <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0x12c> */
/* @0x1921c0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1921c4 add lr, lr, #4 */
/* @0x1921c8 b 0x192154 <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_+0xe8> */
/* @0x1921cc .word 0x0025bbd8 */
/* @0x1921d0 eoreq r11, r5, r8, ror #23 */

/* ── FUNC 0x1921d4 · RVALUE_GEN_GC(RValue const*, unsigned int**, int, YYObjectBase*) · size=56 · insn=14 */
/* @0x1921d4 str r4, [sp, #-0x4]! */
/* @0x1921d8 ldr r4, [r0] */
/* @0x1921dc cmp r4, #0 */
/* @0x1921e0 beq 0x1921f8 <_Z13RVALUE_GEN_GCPK6RValuePPjiP12YYObjectBase+0x24> */
/* @0x1921e4 ldr r12, [r0, #0xc] */
/* @0x1921e8 bic r12, r12, #-16777216 */
/* @0x1921ec cmp r12, #6 */
/* @0x1921f0 cmpne r12, #11 */
/* @0x1921f4 beq 0x192200 <_Z13RVALUE_GEN_GCPK6RValuePPjiP12YYObjectBase+0x2c> */
/* @0x1921f8 ldr r4, [sp], #4 */
/* @0x1921fc bx lr */
/* @0x192200 mov r0, r4 */
/* @0x192204 ldr r4, [sp], #4 */
/* @0x192208 b 0x19206c <_ZN12YYObjectBase10Mark4GenGCEPPjiPS_> */

/* ── FUNC 0x19220c · YYObjectBase::IsExtensible() · size=12 · insn=3 */
/* @0x19220c ldr r0, [r0, #0x28] */
/* @0x192210 and r0, r0, #1 */
/* @0x192214 bx lr */

/* ── FUNC 0x192218 · YYObjectBase::HasValue(char const*) · size=244 · insn=61 */
/* @0x192218 ldr r3, [r0, #0x60] */
/* @0x19221c push {r4, r5, r6, r7, r8, lr} */
/* @0x192220 cmp r3, #0 */
/* @0x192224 mov r4, r0 */
/* @0x192228 beq 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc> */
/* @0x19222c bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0x192230 cmn r0, #1 */
/* @0x192234 beq 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc> */
/* @0x192238 ldr r5, [r4, #0x60] */
/* @0x19223c bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x192240 ldr r1, [r5, #0x8] */
/* @0x192244 ldr r7, [r5, #0x10] */
/* @0x192248 bic r0, r0, #-2147483648 */
/* @0x19224c and r3, r0, r1 */
/* @0x192250 lsl r4, r3, #1 */
/* @0x192254 add r2, r4, r3 */
/* @0x192258 add r2, r7, r2, lsl #2 */
/* @0x19225c ldr r2, [r2, #0x8] */
/* @0x192260 cmp r2, #0 */
/* @0x192264 beq 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc> */
/* @0x192268 cmp r0, r2 */
/* @0x19226c beq 0x1922e4 <_ZN12YYObjectBase8HasValueEPKc+0xcc> */
/* @0x192270 ldr r8, [r5] */
/* @0x192274 and r2, r1, r2 */
/* @0x192278 add r12, r3, r8 */
/* @0x19227c rsb r2, r2, r12 */
/* @0x192280 tst r2, r1 */
/* @0x192284 bmi 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc> */
/* @0x192288 mov r12, #0 */
/* @0x19228c b 0x1922a0 <_ZN12YYObjectBase8HasValueEPKc+0x88> */
/* @0x192290 cmp r0, r2 */
/* @0x192294 beq 0x1922dc <_ZN12YYObjectBase8HasValueEPKc+0xc4> */
/* @0x192298 cmp r5, r12 */
/* @0x19229c blt 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc> */
/* @0x1922a0 add r3, r3, #1 */
/* @0x1922a4 add r12, r12, #1 */
/* @0x1922a8 and r3, r1, r3 */
/* @0x1922ac add r6, r3, r8 */
/* @0x1922b0 lsl r4, r3, #1 */
/* @0x1922b4 add r2, r4, r3 */
/* @0x1922b8 add r2, r7, r2, lsl #2 */
/* @0x1922bc ldr r2, [r2, #0x8] */
/* @0x1922c0 and r5, r1, r2 */
/* @0x1922c4 cmp r2, #0 */
/* @0x1922c8 rsb r5, r5, r6 */
/* @0x1922cc and r5, r5, r1 */
/* @0x1922d0 bne 0x192290 <_ZN12YYObjectBase8HasValueEPKc+0x78> */
/* @0x1922d4 mov r0, #0 */
/* @0x1922d8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1922dc cmn r3, #1 */
/* @0x1922e0 beq 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc> */
/* @0x1922e4 add r3, r4, r3 */
/* @0x1922e8 add r7, r7, r3, lsl #2 */
/* @0x1922ec cmn r7, #4 */
/* @0x1922f0 beq 0x1922d4 <_ZN12YYObjectBase8HasValueEPKc+0xbc> */
/* @0x1922f4 ldr r2, [r7, #0x4] */
/* @0x1922f8 mvn r3, #-16777216 */
/* @0x1922fc ldr r0, [r2, #0xc] */
/* @0x192300 subs r0, r0, r3 */
/* @0x192304 movne r0, #1 */
/* @0x192308 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x19230c · CInstance::SetDeactivated(bool) · size=52 · insn=13 */
/* @0x19230c ldr r3, [pc, #0x24] */
/* @0x192310 strb r1, [r0, #0x69] */
/* @0x192314 ldr r3, [pc, r3] */
/* @0x192318 ldrb r3, [r3] */
/* @0x19231c cmp r3, #0 */
/* @0x192320 bxeq lr */
/* @0x192324 ldr r3, [pc, #0x10] */
/* @0x192328 mov r1, r0 */
/* @0x19232c ldr r3, [pc, r3] */
/* @0x192330 ldr r0, [r3] */
/* @0x192334 b 0x1b8a28 <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance> */
/* @0x192338 eoreq r11, r5, r0, lsl r6 */
/* @0x19233c .word 0x0025b5fc */

/* ── FUNC 0x192340 · CInstance::Compute_BoundingBox(bool) · size=1428 · insn=357 */
/* @0x192340 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x192344 vpush {d8, d9, d10, d11} */
/* @0x192348 mov r4, r0 */
/* @0x19234c ldr r7, [pc, #0x480] */
/* @0x192350 sub sp, sp, #20 */
/* @0x192354 ldr r3, [pc, #0x47c] */
/* @0x192358 mov r10, r1 */
/* @0x19235c add r7, pc, r7 */
/* @0x192360 ldr r9, [r7, r3] */
/* @0x192364 ldrb r3, [r9] */
/* @0x192368 cmp r3, #0 */
/* @0x19236c bne 0x192664 <_ZN9CInstance19Compute_BoundingBoxEb+0x324> */
/* @0x192370 add r6, r4, #232 */
/* @0x192374 ldr r12, [r4, #0xac] */
/* @0x192378 ldm r6, {r0, r1, r2, r3} */
/* @0x19237c cmp r12, #0 */
/* @0x192380 stm sp, {r0, r1, r2, r3} */
/* @0x192384 movge r0, r12 */
/* @0x192388 ldrlt r0, [r4, #0x8c] */
/* @0x19238c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x192390 cmp r0, #0 */
/* @0x192394 mov r5, r0 */
/* @0x192398 beq 0x1928ac <_ZN9CInstance19Compute_BoundingBoxEb+0x56c> */
/* @0x19239c vldr s14, [r4, #160] */
/* @0x1923a0 vcmp.f32 s14, #0 */
/* @0x1923a4 vmrs APSR_nzcv, fpscr */
/* @0x1923a8 beq 0x19267c <_ZN9CInstance19Compute_BoundingBoxEb+0x33c> */
/* @0x1923ac ldr r2, [r0, #0x8] */
/* @0x1923b0 vldr s15, [r4, #152] */
/* @0x1923b4 ldr r3, [r0, #0x10] */
/* @0x1923b8 vldr s13, [r4, #156] */
/* @0x1923bc ldr r1, [r0, #0x24] */
/* @0x1923c0 cmp r2, r3 */
/* @0x1923c4 rsblt r3, r1, r3 */
/* @0x1923c8 rsbge r2, r1, r2 */
/* @0x1923cc rsblt r1, r1, r2 */
/* @0x1923d0 rsbge r1, r1, r3 */
/* @0x1923d4 addlt r3, r3, #1 */
/* @0x1923d8 addge r2, r2, #1 */
/* @0x1923dc vmovlt s21, r1 */
/* @0x1923e0 vmovlt s18, r3 */
/* @0x1923e4 ldr r3, [r0, #0x14] */
/* @0x1923e8 vmovge s21, r1 */
/* @0x1923ec ldr r1, [r0, #0x28] */
/* @0x1923f0 vmovge s18, r2 */
/* @0x1923f4 ldr r2, [r0, #0xc] */
/* @0x1923f8 vcvt.f32.s32 s21, s21 */
/* @0x1923fc cmp r2, r3 */
/* @0x192400 vcvt.f32.s32 s18, s18 */
/* @0x192404 vmul.f32 s21, s15, s21 */
/* @0x192408 vmul.f32 s18, s15, s18 */
/* @0x19240c blt 0x1925a8 <_ZN9CInstance19Compute_BoundingBoxEb+0x268> */
/* @0x192410 rsb r2, r1, r2 */
/* @0x192414 rsb r1, r1, r3 */
/* @0x192418 add r2, r2, #1 */
/* @0x19241c vmov s22, r1 */
/* @0x192420 vmov s11, r2 */
/* @0x192424 vcvt.f32.s32 s22, s22 */
/* @0x192428 vcvt.f32.s32 s23, s11 */
/* @0x19242c vmul.f32 s22, s13, s22 */
/* @0x192430 vmul.f32 s23, s13, s23 */
/* @0x192434 vldr s19, [pc, #912] */
/* @0x192438 vldr s15, [pc, #912] */
/* @0x19243c vmul.f32 s14, s14, s19 */
/* @0x192440 vdiv.f32 s19, s14, s15 */
/* @0x192444 vmov r0, s19 */
/* @0x192448 bl 0xb658c <cosf@plt> */
/* @0x19244c vmov s17, r0 */
/* @0x192450 vmov r0, s19 */
/* @0x192454 bl 0xb6580 <sinf@plt> */
/* @0x192458 vmul.f32 s20, s17, s21 */
/* @0x19245c ldr r3, [pc, #0x378] */
/* @0x192460 ldr r6, [r7, r3] */
/* @0x192464 ldrb r3, [r6] */
/* @0x192468 vmul.f32 s13, s17, s18 */
/* @0x19246c vcmpe.f32 s13, s20 */
/* @0x192470 vmrs APSR_nzcv, fpscr */
/* @0x192474 vmovpl.f32 s15, s20 */
/* @0x192478 vmov s16, r0 */
/* @0x19247c vmovpl.f32 s20, s13 */
/* @0x192480 vmul.f32 s14, s16, s23 */
/* @0x192484 vmul.f32 s19, s16, s22 */
/* @0x192488 vcmpe.f32 s14, s19 */
/* @0x19248c vmovpl.f32 s13, s15 */
/* @0x192490 vmrs APSR_nzcv, fpscr */
/* @0x192494 vmovpl.f32 s15, s19 */
/* @0x192498 vmovpl.f32 s19, s14 */
/* @0x19249c vmovpl.f32 s14, s15 */
/* @0x1924a0 cmp r3, #0 */
/* @0x1924a4 beq 0x192610 <_ZN9CInstance19Compute_BoundingBoxEb+0x2d0> */
/* @0x1924a8 ldr r3, [pc, #0x330] */
/* @0x1924ac ldr r3, [r7, r3] */
/* @0x1924b0 ldrb r3, [r3] */
/* @0x1924b4 cmp r3, #0 */
/* @0x1924b8 bne 0x192610 <_ZN9CInstance19Compute_BoundingBoxEb+0x2d0> */
/* @0x1924bc vldr s15, [r4, #180] */
/* @0x1924c0 vadd.f32 s20, s20, s15 */
/* @0x1924c4 mov r3, #1 */
/* @0x1924c8 vadd.f32 s19, s20, s19 */
/* @0x1924cc vadd.f32 s13, s15, s13 */
/* @0x1924d0 vcvt.s32.f32 s19, s19 */
/* @0x1924d4 vmov r1, s19 */
/* @0x1924d8 vadd.f32 s14, s13, s14 */
/* @0x1924dc vcvt.s32.f32 s14, s14 */
/* @0x1924e0 vstr s14, [r4, #232] */
/* @0x1924e4 sub r2, r1, #1 */
/* @0x1924e8 str r2, [r4, #0xf0] */
/* @0x1924ec vmul.f32 s15, s17, s23 */
/* @0x1924f0 vmul.f32 s17, s17, s22 */
/* @0x1924f4 vmul.f32 s18, s16, s18 */
/* @0x1924f8 vmul.f32 s16, s16, s21 */
/* @0x1924fc vcmpe.f32 s15, s17 */
/* @0x192500 vmrs APSR_nzcv, fpscr */
/* @0x192504 vcmpe.f32 s18, s16 */
/* @0x192508 vmovpl.f32 s14, s17 */
/* @0x19250c vmovpl.f32 s17, s15 */
/* @0x192510 vmovpl.f32 s15, s14 */
/* @0x192514 vmrs APSR_nzcv, fpscr */
/* @0x192518 vmovpl.f32 s14, s16 */
/* @0x19251c vmovpl.f32 s16, s18 */
/* @0x192520 vmovpl.f32 s18, s14 */
/* @0x192524 cmp r3, #0 */
/* @0x192528 beq 0x1925d0 <_ZN9CInstance19Compute_BoundingBoxEb+0x290> */
/* @0x19252c ldr r3, [pc, #0x2ac] */
/* @0x192530 ldr r3, [r7, r3] */
/* @0x192534 ldrb r3, [r3] */
/* @0x192538 cmp r3, #0 */
/* @0x19253c bne 0x1925d0 <_ZN9CInstance19Compute_BoundingBoxEb+0x290> */
/* @0x192540 vldr s14, [r4, #184] */
/* @0x192544 vadd.f32 s17, s17, s14 */
/* @0x192548 vsub.f32 s18, s17, s18 */
/* @0x19254c vadd.f32 s15, s14, s15 */
/* @0x192550 vcvt.s32.f32 s18, s18 */
/* @0x192554 vmov r1, s18 */
/* @0x192558 vsub.f32 s16, s15, s16 */
/* @0x19255c vcvt.s32.f32 s16, s16 */
/* @0x192560 vstr s16, [r4, #236] */
/* @0x192564 sub r3, r1, #1 */
/* @0x192568 str r3, [r4, #0xf4] */
/* @0x19256c ldrb r3, [r5, #0x30] */
/* @0x192570 strb r3, [r4, #0xb0] */
/* @0x192574 cmp r10, #0 */
/* @0x192578 mov r3, #0 */
/* @0x19257c strb r3, [r4, #0x64] */
/* @0x192580 bne 0x192654 <_ZN9CInstance19Compute_BoundingBoxEb+0x314> */
/* @0x192584 ldrb r3, [r9] */
/* @0x192588 cmp r3, #0 */
/* @0x19258c beq 0x19259c <_ZN9CInstance19Compute_BoundingBoxEb+0x25c> */
/* @0x192590 ldr r3, [pc, #0x24c] */
/* @0x192594 ldr r0, [r7, r3] */
/* @0x192598 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x19259c add sp, sp, #20 */
/* @0x1925a0 vpop {d8, d9, d10, d11} */
/* @0x1925a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1925a8 rsb r3, r1, r3 */
/* @0x1925ac rsb r1, r1, r2 */
/* @0x1925b0 add r3, r3, #1 */
/* @0x1925b4 vmov s22, r1 */
/* @0x1925b8 vmov s15, r3 */
/* @0x1925bc vcvt.f32.s32 s22, s22 */
/* @0x1925c0 vcvt.f32.s32 s23, s15 */
/* @0x1925c4 vmul.f32 s22, s13, s22 */
/* @0x1925c8 vmul.f32 s23, s13, s23 */
/* @0x1925cc b 0x192434 <_ZN9CInstance19Compute_BoundingBoxEb+0xf4> */
/* @0x1925d0 vldr s14, [r4, #184] */
/* @0x1925d4 vadd.f32 s15, s15, s14 */
/* @0x1925d8 vsub.f32 s16, s15, s16 */
/* @0x1925dc vcvt.f64.f32 d6, s16 */
/* @0x1925e0 vmov r0, r1, d6 */
/* @0x1925e4 bl 0xb66e8 <lrint@plt> */
/* @0x1925e8 vldr s15, [r4, #184] */
/* @0x1925ec vadd.f32 s17, s17, s15 */
/* @0x1925f0 vsub.f32 s18, s17, s18 */
/* @0x1925f4 vcvt.f64.f32 d7, s18 */
/* @0x1925f8 str r0, [r4, #0xec] */
/* @0x1925fc vmov r0, r1, d7 */
/* @0x192600 bl 0xb66e8 <lrint@plt> */
/* @0x192604 sub r0, r0, #1 */
/* @0x192608 str r0, [r4, #0xf4] */
/* @0x19260c b 0x19256c <_ZN9CInstance19Compute_BoundingBoxEb+0x22c> */
/* @0x192610 vldr s15, [r4, #180] */
/* @0x192614 vadd.f32 s13, s13, s15 */
/* @0x192618 vadd.f32 s14, s13, s14 */
/* @0x19261c vcvt.f64.f32 d6, s14 */
/* @0x192620 vmov r0, r1, d6 */
/* @0x192624 bl 0xb66e8 <lrint@plt> */
/* @0x192628 vldr s15, [r4, #180] */
/* @0x19262c vadd.f32 s20, s20, s15 */
/* @0x192630 vadd.f32 s19, s20, s19 */
/* @0x192634 vcvt.f64.f32 d7, s19 */
/* @0x192638 str r0, [r4, #0xe8] */
/* @0x19263c vmov r0, r1, d7 */
/* @0x192640 bl 0xb66e8 <lrint@plt> */
/* @0x192644 ldrb r3, [r6] */
/* @0x192648 sub r0, r0, #1 */
/* @0x19264c str r0, [r4, #0xf0] */
/* @0x192650 b 0x1924ec <_ZN9CInstance19Compute_BoundingBoxEb+0x1ac> */
/* @0x192654 mov r0, r4 */
/* @0x192658 mov r1, sp */
/* @0x19265c bl 0x1cdc1c <_Z15CollisionUpdateP9CInstanceR9tagYYRECT> */
/* @0x192660 b 0x192584 <_ZN9CInstance19Compute_BoundingBoxEb+0x244> */
/* @0x192664 ldr r3, [pc, #0x178] */
/* @0x192668 mov r1, #6 */
/* @0x19266c mov r2, #2 */
/* @0x192670 ldr r0, [r7, r3] */
/* @0x192674 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x192678 b 0x192370 <_ZN9CInstance19Compute_BoundingBoxEb+0x30> */
/* @0x19267c mov r3, r0 */
/* @0x192680 ldr r2, [pc, #0x154] */
/* @0x192684 ldr r12, [r3, #0x8]! */
/* @0x192688 ldr r0, [r3, #0x4] */
/* @0x19268c ldr r1, [r3, #0x8] */
/* @0x192690 ldr r3, [r3, #0xc] */
/* @0x192694 str r12, [r4, #0xe8] */
/* @0x192698 str r0, [r6, #0x4] */
/* @0x19269c str r1, [r6, #0x8] */
/* @0x1926a0 str r3, [r6, #0xc] */
/* @0x1926a4 ldr r6, [r7, r2] */
/* @0x1926a8 ldr r0, [r4, #0xf0] */
/* @0x1926ac ldr r3, [r4, #0xe8] */
/* @0x1926b0 ldrb r2, [r6] */
/* @0x1926b4 add r0, r0, #1 */
/* @0x1926b8 ldr r1, [r4, #0xf4] */
/* @0x1926bc rsb r0, r3, r0 */
/* @0x1926c0 cmp r2, #0 */
/* @0x1926c4 ldr r2, [r4, #0xec] */
/* @0x1926c8 add r1, r1, #1 */
/* @0x1926cc vmov s16, r0 */
/* @0x1926d0 rsb r11, r2, r1 */
/* @0x1926d4 beq 0x1927e8 <_ZN9CInstance19Compute_BoundingBoxEb+0x4a8> */
/* @0x1926d8 ldr r1, [pc, #0x100] */
/* @0x1926dc ldr r1, [r7, r1] */
/* @0x1926e0 ldrb r1, [r1] */
/* @0x1926e4 cmp r1, #0 */
/* @0x1926e8 bne 0x1927e8 <_ZN9CInstance19Compute_BoundingBoxEb+0x4a8> */
/* @0x1926ec ldr r1, [r5, #0x24] */
/* @0x1926f0 vldr s14, [r4, #152] */
/* @0x1926f4 vldr s15, [r4, #180] */
/* @0x1926f8 vcvt.f32.s32 s16, s16 */
/* @0x1926fc rsb r3, r1, r3 */
/* @0x192700 mov r1, r2 */
/* @0x192704 mov r12, #1 */
/* @0x192708 vmov s11, r3 */
/* @0x19270c vcvt.f32.s32 s13, s11 */
/* @0x192710 vmla.f32 s15, s14, s13 */
/* @0x192714 vcvt.s32.f32 s15, s15 */
/* @0x192718 vmov r3, s15 */
/* @0x19271c vcvt.f32.s32 s15, s15 */
/* @0x192720 vmla.f32 s15, s14, s16 */
/* @0x192724 str r3, [r4, #0xe8] */
/* @0x192728 vcvt.s32.f32 s15, s15 */
/* @0x19272c vmov r2, s15 */
/* @0x192730 vstr s15, [r4, #240] */
/* @0x192734 cmp r2, r3 */
/* @0x192738 strlt r2, [r4, #0xe8] */
/* @0x19273c strlt r3, [r4, #0xf0] */
/* @0x192740 cmp r12, #0 */
/* @0x192744 beq 0x19284c <_ZN9CInstance19Compute_BoundingBoxEb+0x50c> */
/* @0x192748 ldr r3, [pc, #0x90] */
/* @0x19274c ldr r3, [r7, r3] */
/* @0x192750 ldrb r3, [r3] */
/* @0x192754 cmp r3, #0 */
/* @0x192758 bne 0x19284c <_ZN9CInstance19Compute_BoundingBoxEb+0x50c> */
/* @0x19275c ldr r2, [r5, #0x28] */
/* @0x192760 vmov s11, r11 */
/* @0x192764 vldr s14, [r4, #156] */
/* @0x192768 vldr s15, [r4, #184] */
/* @0x19276c rsb r2, r2, r1 */
/* @0x192770 vcvt.f32.s32 s13, s11 */
/* @0x192774 vmov s11, r2 */
/* @0x192778 vcvt.f32.s32 s12, s11 */
/* @0x19277c vmla.f32 s15, s14, s12 */
/* @0x192780 vcvt.s32.f32 s15, s15 */
/* @0x192784 vmov r2, s15 */
/* @0x192788 vcvt.f32.s32 s15, s15 */
/* @0x19278c vmla.f32 s15, s14, s13 */
/* @0x192790 str r2, [r4, #0xec] */
/* @0x192794 vcvt.s32.f32 s15, s15 */
/* @0x192798 vmov r3, s15 */
/* @0x19279c vstr s15, [r4, #244] */
/* @0x1927a0 cmp r3, r2 */
/* @0x1927a4 strlt r3, [r4, #0xec] */
/* @0x1927a8 movlt r3, r2 */
/* @0x1927ac ldrb r2, [r5, #0x30] */
/* @0x1927b0 sub r1, r3, #1 */
/* @0x1927b4 ldr r3, [r4, #0xf0] */
/* @0x1927b8 str r1, [r4, #0xf4] */
/* @0x1927bc sub r3, r3, #1 */
/* @0x1927c0 strb r2, [r4, #0xb0] */
/* @0x1927c4 str r3, [r4, #0xf0] */
/* @0x1927c8 b 0x192574 <_ZN9CInstance19Compute_BoundingBoxEb+0x234> */
/* @0x1927cc ldrdmi r0, r1, [r9], #-251 */
/* @0x1927d0 teqmi r4, #0 */
/* @0x1927d4 .word 0x0025f8f4 */
/* @0x1927d8 .word 0xffffbf18 */
/* @0x1927dc .word 0xffffea30 */
/* @0x1927e0 .word 0xffffea34 */
/* @0x1927e4 .word 0xffffbf1c */
/* @0x1927e8 ldr r2, [r5, #0x24] */
/* @0x1927ec vldr s14, [r4, #152] */
/* @0x1927f0 vldr s15, [r4, #180] */
/* @0x1927f4 rsb r3, r2, r3 */
/* @0x1927f8 vmov s12, r3 */
/* @0x1927fc vcvt.f32.s32 s13, s12 */
/* @0x192800 vmla.f32 s15, s13, s14 */
/* @0x192804 vcvt.f64.f32 d6, s15 */
/* @0x192808 vmov r0, r1, d6 */
/* @0x19280c bl 0xb66e8 <lrint@plt> */
/* @0x192810 vldr s14, [r4, #152] */
/* @0x192814 vcvt.f32.s32 s16, s16 */
/* @0x192818 vmov s13, r0 */
/* @0x19281c str r0, [r4, #0xe8] */
/* @0x192820 vcvt.f32.s32 s15, s13 */
/* @0x192824 vmla.f32 s15, s16, s14 */
/* @0x192828 vcvt.f64.f32 d6, s15 */
/* @0x19282c vmov r0, r1, d6 */
/* @0x192830 bl 0xb66e8 <lrint@plt> */
/* @0x192834 ldrb r12, [r6] */
/* @0x192838 ldr r3, [r4, #0xe8] */
/* @0x19283c ldr r1, [r4, #0xec] */
/* @0x192840 mov r2, r0 */
/* @0x192844 str r0, [r4, #0xf0] */
/* @0x192848 b 0x192734 <_ZN9CInstance19Compute_BoundingBoxEb+0x3f4> */
/* @0x19284c ldr r2, [r5, #0x28] */
/* @0x192850 vldr s14, [r4, #156] */
/* @0x192854 vldr s15, [r4, #184] */
/* @0x192858 rsb r2, r2, r1 */
/* @0x19285c vmov s12, r2 */
/* @0x192860 vcvt.f32.s32 s13, s12 */
/* @0x192864 vmla.f32 s15, s13, s14 */
/* @0x192868 vcvt.f64.f32 d6, s15 */
/* @0x19286c vmov r0, r1, d6 */
/* @0x192870 bl 0xb66e8 <lrint@plt> */
/* @0x192874 vldr s14, [r4, #156] */
/* @0x192878 vmov s11, r11 */
/* @0x19287c vmov s13, r0 */
/* @0x192880 str r0, [r4, #0xec] */
/* @0x192884 vcvt.f32.s32 s15, s13 */
/* @0x192888 vcvt.f32.s32 s13, s11 */
/* @0x19288c vmla.f32 s15, s13, s14 */
/* @0x192890 vcvt.f64.f32 d6, s15 */
/* @0x192894 vmov r0, r1, d6 */
/* @0x192898 bl 0xb66e8 <lrint@plt> */
/* @0x19289c ldr r2, [r4, #0xec] */
/* @0x1928a0 mov r3, r0 */
/* @0x1928a4 str r0, [r4, #0xf4] */
/* @0x1928a8 b 0x1927a0 <_ZN9CInstance19Compute_BoundingBoxEb+0x460> */
/* @0x1928ac vldr s14, [r4, #180] */
/* @0x1928b0 vldr s15, [r4, #184] */
/* @0x1928b4 vcvt.s32.f32 s14, s14 */
/* @0x1928b8 strb r0, [r4, #0xb0] */
/* @0x1928bc vcvt.s32.f32 s15, s15 */
/* @0x1928c0 vstr s14, [r4, #232] */
/* @0x1928c4 vstr s14, [r4, #240] */
/* @0x1928c8 vstr s15, [r4, #236] */
/* @0x1928cc vstr s15, [r4, #244] */
/* @0x1928d0 b 0x192574 <_ZN9CInstance19Compute_BoundingBoxEb+0x234> */

/* ── FUNC 0x1928d4 · anon_1928d4 · size=4 · insn=1 */
/* @0x1928d4 andeq r0, r0, r0 */

/* ── FUNC 0x1928d8 · CInstance::Compute_Speed1() · size=452 · insn=110 */
/* @0x1928d8 vldr s15, [r0, #224] */
/* @0x1928dc vcmp.f32 s15, #0 */
/* @0x1928e0 push {r4, lr} */
/* @0x1928e4 vpush {d8} */
/* @0x1928e8 mov r4, r0 */
/* @0x1928ec vldr s16, [pc, #396] */
/* @0x1928f0 vmrs APSR_nzcv, fpscr */
/* @0x1928f4 bne 0x1929f4 <_ZN9CInstance14Compute_Speed1Ev+0x11c> */
/* @0x1928f8 vldr s15, [r0, #228] */
/* @0x1928fc vcmpe.f32 s15, s16 */
/* @0x192900 vmrs APSR_nzcv, fpscr */
/* @0x192904 ble 0x192a3c <_ZN9CInstance14Compute_Speed1Ev+0x164> */
/* @0x192908 vldr s16, [pc, #372] */
/* @0x19290c vldr d7, [pc, #340] */
/* @0x192910 vstr s16, [r0, #204] */
/* @0x192914 vmov r0, r1, d7 */
/* @0x192918 bl 0xb66e8 <lrint@plt> */
/* @0x19291c vldr s15, [pc, #356] */
/* @0x192920 vmov s13, r0 */
/* @0x192924 vcvt.f32.s32 s14, s13 */
/* @0x192928 vsub.f32 s16, s16, s14 */
/* @0x19292c vabs.f32 s16, s16 */
/* @0x192930 vcmpe.f32 s16, s15 */
/* @0x192934 vldr s15, [r4, #204] */
/* @0x192938 vmrs APSR_nzcv, fpscr */
/* @0x19293c bmi 0x1929d8 <_ZN9CInstance14Compute_Speed1Ev+0x100> */
/* @0x192940 vmov r0, s15 */
/* @0x192944 mov r1, #0 */
/* @0x192948 movt r1, #0x43b4 */
/* @0x19294c bl 0xb6790 <fmodf@plt> */
/* @0x192950 vldr s15, [r4, #228] */
/* @0x192954 vmul.f32 s15, s15, s15 */
/* @0x192958 vldr s14, [r4, #224] */
/* @0x19295c vmla.f32 s15, s14, s14 */
/* @0x192960 str r0, [r4, #0xcc] */
/* @0x192964 vsqrt.f32 s16, s15 */
/* @0x192968 vcmp.f32 s16, s16 */
/* @0x19296c vmrs APSR_nzcv, fpscr */
/* @0x192970 bne 0x192a54 <_ZN9CInstance14Compute_Speed1Ev+0x17c> */
/* @0x192974 vcvt.f64.f32 d7, s16 */
/* @0x192978 vstr s16, [r4, #208] */
/* @0x19297c vmov r0, r1, d7 */
/* @0x192980 bl 0xb66e8 <lrint@plt> */
/* @0x192984 vldr s15, [pc, #252] */
/* @0x192988 vmov s12, r0 */
/* @0x19298c vcvt.f32.s32 s14, s12 */
/* @0x192990 vsub.f32 s16, s16, s14 */
/* @0x192994 vabs.f32 s16, s16 */
/* @0x192998 vcmpe.f32 s16, s15 */
/* @0x19299c vmrs APSR_nzcv, fpscr */
/* @0x1929a0 bpl 0x1929c0 <_ZN9CInstance14Compute_Speed1Ev+0xe8> */
/* @0x1929a4 vldr s15, [r4, #208] */
/* @0x1929a8 vcvt.f64.f32 d6, s15 */
/* @0x1929ac vmov r0, r1, d6 */
/* @0x1929b0 bl 0xb66e8 <lrint@plt> */
/* @0x1929b4 vmov s13, r0 */
/* @0x1929b8 vcvt.f32.s32 s15, s13 */
/* @0x1929bc vstr s15, [r4, #208] */
/* @0x1929c0 vpop {d8} */
/* @0x1929c4 mov r3, #1 */
/* @0x1929c8 mov r0, r4 */
/* @0x1929cc strb r3, [r4, #0x64] */
/* @0x1929d0 pop {r4, lr} */
/* @0x1929d4 b 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */
/* @0x1929d8 vcvt.f64.f32 d6, s15 */
/* @0x1929dc vmov r0, r1, d6 */
/* @0x1929e0 bl 0xb66e8 <lrint@plt> */
/* @0x1929e4 vmov s13, r0 */
/* @0x1929e8 vcvt.f32.s32 s15, s13 */
/* @0x1929ec vstr s15, [r4, #204] */
/* @0x1929f0 b 0x192940 <_ZN9CInstance14Compute_Speed1Ev+0x68> */
/* @0x1929f4 vmov r1, s15 */
/* @0x1929f8 vldr s16, [pc, #140] */
/* @0x1929fc ldr r0, [r0, #0xe4] */
/* @0x192a00 bl 0xb6778 <atan2f@plt> */
/* @0x192a04 vldr s15, [pc, #132] */
/* @0x192a08 vmov s12, r0 */
/* @0x192a0c vmul.f32 s16, s12, s16 */
/* @0x192a10 vdiv.f32 s16, s16, s15 */
/* @0x192a14 vcmpe.f32 s16, #0 */
/* @0x192a18 vmrs APSR_nzcv, fpscr */
/* @0x192a1c vldrhi s15, [pc, #112] */
/* @0x192a20 vsubhi.f32 s16, s15, s16 */
/* @0x192a24 vnegls.f32 s16, s16 */
/* @0x192a28 vstrhi s16, [r4, #204] */
/* @0x192a2c vstrls s16, [r4, #204] */
/* @0x192a30 vcvtls.f64.f32 d7, s16 */
/* @0x192a34 vcvthi.f64.f32 d7, s16 */
/* @0x192a38 b 0x192914 <_ZN9CInstance14Compute_Speed1Ev+0x3c> */
/* @0x192a3c vldrmi s16, [pc, #84] */
/* @0x192a40 vldrmi d7, [pc, #40] */
/* @0x192a44 vstrmi s16, [r0, #204] */
/* @0x192a48 vstrpl s16, [r0, #204] */
/* @0x192a4c vldrpl d7, [pc, #36] */
/* @0x192a50 b 0x192914 <_ZN9CInstance14Compute_Speed1Ev+0x3c> */
/* @0x192a54 vmov r0, s15 */
/* @0x192a58 bl 0xb6700 <sqrtf@plt> */
/* @0x192a5c vmov s16, r0 */
/* @0x192a60 b 0x192974 <_ZN9CInstance14Compute_Speed1Ev+0x9c> */
/* @0x192a64 nop */
/* @0x192a68 andeq r0, r0, r0 */
/* @0x192a6c rsbsmi lr, r0, r0 */
/* @0x192a70 andeq r0, r0, r0 */
/* @0x192a74 subsmi r8, r6, r0 */
/* @0x192a84 orrmi r0, r7, #0 */
/* @0x192a88 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x192a8c teqmi r4, #0 */
/* @0x192a90 ldrdmi r0, r1, [r9], #-251 */
/* @0x192a94 .word 0x43b40000 */
/* @0x192a98 adcsmi r0, r4, #0 */

/* ── FUNC 0x192a9c · anon_192a9c · size=4 · insn=1 */
/* @0x192a9c nop */
