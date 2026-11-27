/*
 * variable_global_init.c — static C translation of
 * _Z20Variable_Global_Initv @0x001f3354 in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * 24 instructions + 2 literal-pool words, 0x68 = 104 B.  Control flow, in
 * order, with the address every instruction was read from:
 *
 *   0x1f3354 push {r4, r5, lr}      frame; lr saved because of the one bl
 *   0x1f3358 sub  sp, sp, #12       12 B: one stack argument + 8 B alignment
 *   0x1f335c ldr  r4, [pc, #0x50]   pool 0x1f33b4 = 0x001fdabc (GOT offset)
 *   0x1f3360 mov  r5, #0            r5 is BOTH the zero byte and ReAlloc's
 *                                   "don't zero" flag
 *   0x1f3364 ldr  r2, [pc, #0x4c]   pool 0x1f33b8 = 0x00159ec0 (rodata offset)
 *   0x1f3368 movw r1, #0x2710       10000, hard-coded
 *   0x1f336c ldr  r4, [pc, r4]      pc 0x1f3374 + 0x1fdabc = .got 0x003f0e30,
 *                                   whose addend is 0x00753100 = globdecl
 *   0x1f3370 mov  r3, #106          line number, hard-coded
 *   0x1f3374 add  r2, pc, r2        0x1f337c + 0x159ec0 = 0x0034d23c, the
 *                                   cARRAY_STRUCTURE.h string
 *   0x1f3378 ldr  r0, [r4, #0x4]    ReAlloc's first argument: the OLD data
 *                                   pointer, read before any store
 *   0x1f337c str  r5, [sp]          5th argument (bool zero) = 0
 *   0x1f3380 bl   0x27cedc          MemoryManager::ReAlloc(p, 10000, file,106,0)
 *   0x1f3384 movw r12, #0x2710      10000 again, now as the cap to store AND
 *                                   as the clear loop's bound
 *   0x1f3388 mov  r3, r5            i = 0
 *   0x1f338c mov  r1, r12           bound = 10000
 *   0x1f3390 mov  r2, r5            store value = 0
 *   0x1f3394 str  r12, [r4]         cap = 10000   (BEFORE data)
 *   0x1f3398 str  r0, [r4, #0x4]    data = new base
 *   0x1f339c strb r2, [r0, r3]      data[i] = 0 -- ONE BYTE per iteration
 *   0x1f33a0 add  r3, r3, #1
 *   0x1f33a4 cmp  r3, r1
 *   0x1f33a8 bne  0x1f339c          do { store } while (i != 10000)
 *   0x1f33ac add  sp, sp, #12
 *   0x1f33b0 pop  {r4, r5, pc}
 *
 * Three things this body does NOT do, and the translation keeps true:
 *   * no "already initialised" short circuit - a second call re-runs ReAlloc
 *     and clears whatever the table held (card open 4);
 *   * no NULL check on ReAlloc's answer: the clear loop dereferences it
 *     unconditionally (0x1f339c is reached with r0 straight from the bl);
 *   * no size comparison - 10000 is written twice as an immediate, never read
 *     back from the struct, so there is no "size already right, skip" path.
 *
 * What the differential can see: the cap word, the data word (as "is it the
 * block the stub returned"), the 10000 bytes after the call, and the ordered
 * ReAlloc argument list.  Nothing else exists in this body.
 */
#include "variable_misc.h"

void Variable_Global_Init(void)
{
    char *base;      /* r0 */
    int   i;         /* r3 */
    int   bound;     /* r1 */

    /* 0x1f335c / 0x1f336c: one ldr of the GOT offset, then `ldr r4,[pc,r4]`
     * against pc = 0x1f3374, lands on .got 0x003f0e30 whose addend is
     * 0x00753100.  In C the struct is simply g_globdecl. */
    /* @0x1f3354 push {r4, r5, lr} */
    /* @0x1f3358 sub sp, sp, #12 */
    /* @0x1f335c ldr r4, [pc, #0x50] */
    /* @0x1f3360 mov r5, #0 */
    /* @0x1f3364 ldr r2, [pc, #0x4c] */
    /* @0x1f3368 movw r1, #0x2710 */
    /* @0x1f336c ldr r4, [pc, r4] */
    /* @0x1f3370 mov r3, #106 */
    /* @0x1f3374 add r2, pc, r2 */

    /* 0x1f3378 reads +0x4 BEFORE 0x1f3398 writes it: the pointer handed to
     * ReAlloc is the previous table, not the new one. */
    /* @0x1f3378 ldr r0, [r4, #0x4] */
    /* @0x1f337c str r5, [sp] */
    /* @0x1f3380 bl 0x27cedc */
    base = (char *)MemoryManager_ReAlloc(g_globdecl.data, VM_GLOBDECL_CAP,
                                         VM_CARRAY_FILE, VM_GLOBDECL_LINE, 0);

    /* 0x1f3394 stores the cap before 0x1f3398 stores the pointer, so a
     * concurrent reader could see {new cap, old pointer}; single-threaded
     * startup is the only caller (DoTheWork 0x2a16f8), and this translation
     * keeps the same order rather than "fixing" it. */
    /* @0x1f3384 movw r12, #0x2710 */
    /* @0x1f3388 mov r3, r5 */
    /* @0x1f338c mov r1, r12 */
    /* @0x1f3390 mov r2, r5 */
    /* @0x1f3394 str r12, [r4] */
    /* @0x1f3398 str r0, [r4, #0x4] */
    g_globdecl.cap = VM_GLOBDECL_CAP;
    g_globdecl.data = base;

    /* 0x1f339c is strb, i.e. the clear is per BYTE and the table is treated
     * as a 10000-byte array (card open 1: what one byte means is unproven).
     * Layout: test at the bottom, exactly as bne 0x1f339c has it. */
    /* @0x1f339c strb r2, [r0, r3] */
    /* @0x1f33a0 add r3, r3, #1 */
    /* @0x1f33a4 cmp r3, r1 */
    /* @0x1f33a8 bne 0x1f339c */
    i = 0;
    bound = VM_GLOBDECL_CAP;
    do {
        base[i] = 0;
        i = i + 1;
    } while (i != bound);

    /* @0x1f33ac add sp, sp, #12 */
    /* @0x1f33b0 pop {r4, r5, pc} */
    /* no return value: r0 at the exit is the bl's leftover (the new base) */
}

/* Literal pool of the body.  Both words are pc-relative offsets, so
 * llvm-objdump decodes them as instructions; the census gate documents them as
 * words instead: */
/* @0x1f33b4 .word 0x001fdabc */
/* 0x1f33b4 + pc 0x1f3374 = 0x003f0e30 -> .bss 0x00753100 (globdecl) */
/* @0x1f33b8 .word 0x00159ec0 */
/* 0x1f33b8 + pc 0x1f337c = 0x0034d23c -> cARRAY_STRUCTURE.h */
