/*
 * variable_getname_scope.c — static C translation of
 * _Z22Variable_GetName_ScopePKcii @0x000d2228 in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * 158 instructions + 13 literal-pool words (0x000d24a0..0x000d24d0),
 * 0x2ac = 684 B.  Frame: 9 registers + lr, then two `sub sp` (4096 + 12), so
 * the snprintf buffer is sp+4 .. sp+4100 and the stack canary sits at
 * sp+4100 = (sp+8192)-0xffc.
 *
 * Dispatch, and the address each decision comes from:
 *
 *   0xd2264  gate 1: g_subFunctionsOption == 0 -> Variable_GetName(id)
 *   0xd2270  slot = id - 100000 < 0            -> "<unknown variable>"
 *   0xd2278  type == -5                        -> global name table
 *   0xd2280  type == -12 or -7                 -> function-name-keyed table
 *   0xd2320  type == -1                        -> instance name table
 *   0xd23d4  (type & ~2) == -11 or type > 100000 -> instance name table
 *            anything else                      -> "<unknown variable>"
 *
 * The two subtables are inline in this one body, which is why they are written
 * here and not as helpers in the header:
 *
 *   arr_slot:    slot >= count -> unknown (global) / map fallback (instance);
 *                otherwise slot < size ? data[slot] : NULL
 *   fn_slot:     strcmp(entry->name, name) -> entry->names[slot], and the
 *                comparison is against entry->count NEVER - the one
 *                out-of-bounds read in this family (card open 1).  The
 *                differential stages 8 names behind a count of 4 so that
 *                reading names[5] is an *observable* answer, identical on both
 *                arms, instead of undefined behaviour.
 *
 * Three things this body does NOT do, and the translation keeps true:
 *   * it never writes to any of the three tables;
 *   * the instance map "reverse lookup" is a full LINEAR scan for value == slot
 *     over the i-th occupied entry, i from count-1 downwards - not a hash
 *     query (0xd2350..0xd2394), O(n^2) and all of it inline;
 *   * snprintf's return value is ignored and its truncation is not checked
 *     (0xd242c): a >4095-byte "gml_Script_<parent>" would silently rescan a
 *     truncated key.  The fixture cannot reach that without a 4000-byte script
 *     name, so the arm records the formatted buffer instead.
 *
 * Callee status: Variable_GetName 0x0d1d04 and Script_Find_Parent 0x1e06dc are
 * UNRECOVERED (identical stubs on both arms); strcmp@plt 0x0b6574 and
 * snprintf@plt 0x0b65c8 are libc, answered by the same tiny implementations on
 * both arms.  Nothing here is device equivalence.
 */
#include "variable_misc.h"

const char *Variable_GetName_Scope(const char *name, int type, int id)
{
    char buf[VM_SNPRINTF_CAP];  /* sp+4, the snprintf destination */
    const char *r9 = name;      /* r9 - the "key" every scan compares against */
    int slot;                   /* r7 - id - 100000 */
    int n;                      /* r10 - entry count, reloaded after the rescan */
    int i;                      /* r5 - scan index */
    int key_hits;               /* r2 - normalisation temp in the last block */
    int dist;                   /* r12 - reverse-scan index i, then j */
    int j;                      /* r2 - occupied-entry counter */
    vm_fntable *fe = 0;         /* r4 - element being compared */
    vm_nametable *t;            /* r3 - table being read */
    vm_map *m;                  /* r5 - hash map, then scratch */
    vm_mapentry *me;            /* r3 - map entry cursor */
    const char *parent;         /* r0 - Script_Find_Parent's answer */

    /* ── prologue ───────────────────────────────────────────────────────────
     * The canary is read through .got 0x3ed958 (R_ARM_GLOB_DAT) and stored at
     * sp+4100; the C compiler emits the same check for the same reason. */
    /* @0xd2228 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
    /* @0xd222c sub sp, sp, #4096 */
    /* @0xd2230 ldr r8, [pc, #0x268] */
    /* @0xd2234 sub sp, sp, #12 */
    /* @0xd2238 ldr r3, [pc, #0x264] */
    /* @0xd223c mov r9, r0 */
    /* @0xd2240 add r8, pc, r8 */
    /* @0xd2244 ldr r12, [pc, #0x25c] */
    /* @0xd2248 add r0, sp, #8192 */
    /* @0xd224c ldr r6, [r8, r3] */
    /* @0xd2250 ldr r3, [r6] */
    /* @0xd2254 str r3, [r0, #-0xffc] */
    /* @0xd2258 ldr r3, [r8, r12] */
    /* @0xd225c ldrb r3, [r3] */
    /* @0xd2260 cmp r3, #0 */

    /* ── gate 1 ──────────────────────────────────────────────────────────────
     * 0xd2264 `beq` short-circuits EVERYTHING, including the id < 100000 test:
     * with the gate closed the body answers from the (count, names) pair at
     * 0x47a1b4/0x47a1b8 via Variable_GetName, and neither `type` nor the
     * tables of this function are looked at. */
    /* @0xd2264 beq 0xd239c */
    if (g_subFunctionsOption == 0) {
        /* @0xd239c mov r0, r2 */
        /* @0xd23a0 bl 0xd1d04 */
        /* @0xd23a4 b 0xd22fc */
        return Variable_GetName(id);
    }

    /* ── id domain ───────────────────────────────────────────────────────────
     * 100000 in two `sub`s (99328 + 672); `subs` then `bmi`, i.e. a SIGNED
     * slot < 0 test.  0 is a legal slot: only negatives are refused. */
    /* @0xd2268 sub r7, r2, #99328 */
    /* @0xd226c subs r7, r7, #672 */
    slot = id - 99328;
    slot = slot - 672;
    /* @0xd2270 bmi 0xd22f4 */
    if (slot < 0)
        return VM_MSG_UNKNOWN_VARIABLE;

    /* ── type dispatch, first three cases ────────────────────────────────────
     * `cmn r1,#5` is "type == -5"; `cmn r1,#12` / `cmnne r1,#7` test -12 and
     * -7, with `cmnne` executing only when -12 was false. */
    /* @0xd2274 cmn r1, #5 */
    /* @0xd2278 beq 0xd23a8 */
    if (type == VM_TYPE_GLOBAL)
        goto global;
    /* @0xd227c cmn r1, #12 */
    /* @0xd2280 cmnne r1, #7 */
    /* @0xd2284 bne 0xd231c */
    if (type == VM_TYPE_LOCAL_12 || type == VM_TYPE_LOCAL_FN)
        goto local_fn;
    goto head_231c;

    /* ── the function-name-keyed local table ─────────────────────────────────
     * 0x47a1ac is the count (r11 is its ADDRESS, reloaded after the rescan at
     * 0xd2430); 0x47a1b0 is a pointer variable holding the array; elements are
     * 12 B.  The key compared is the SCRIPT/FUNCTION name (r9), not the
     * variable name. */
local_fn:
    /* @0xd2288 ldr r3, [pc, #0x21c] */
    /* @0xd228c ldr r11, [r8, r3] */
    /* @0xd2290 ldr r10, [r11] */
    /* @0xd2294 cmp r10, #0 */
    n = g_numFunctionsForLocalVars;
    /* @0xd2298 ble 0xd22e0 */
    if (n <= 0)
        goto gate2;
    /* @0xd229c ldr r3, [pc, #0x20c] */
    /* @0xd22a0 mov r5, #0 */
    /* @0xd22a4 ldr r3, [r8, r3] */
    /* @0xd22a8 ldr r4, [r3] */
    fe = *g_localVariableNamesForFunctions;
    i = 0;
    /* @0xd22ac b 0xd22c0 */
    for (;;) {
        /* @0xd22c0 ldr r0, [r4] */
        /* @0xd22c4 mov r1, r9 */
        /* @0xd22c8 bl 0xb6574 */
        /* @0xd22cc cmp r0, #0 */
        /* @0xd22d0 bne 0xd22b0 */
        if (strcmp(fe->name, r9) == 0)
            goto fn_slot;
        /* @0xd22b0 add r5, r5, #1 */
        /* @0xd22b4 add r4, r4, #12 */
        /* @0xd22b8 cmp r5, r10 */
        /* @0xd22bc beq 0xd22e0 */
        i = i + 1;
        fe = fe + 1;            /* 12 B per element */
        if (i == n)
            goto gate2;
    }

fn_slot:
    /* ── the shared value block (also reached from the parent rescan) ────────
     * names[slot] with NO comparison against fe->count. */
    /* @0xd22d4 ldr r3, [r4, #0x8] */
    /* @0xd22d8 ldr r0, [r3, r7, lsl #2] */
    /* @0xd22dc b 0xd22fc */
    return fe->names[slot];

gate2:
    /* ── gate 2: is the parent-script fallback allowed at all ────────────────
     * Same byte as the GC switch (0x47f295, card open 6), read with ldrb. */
    /* @0xd22e0 ldr r3, [pc, #0x1cc] */
    /* @0xd22e4 ldr r3, [r8, r3] */
    /* @0xd22e8 ldrb r3, [r3] */
    /* @0xd22ec cmp r3, #0 */
    /* @0xd22f0 bne 0xd2404 */
    if (g_fJSGarbageCollection == 0)
        goto unknown;           /* falls into the same pool word load */

    /* ── Script_Find_Parent + "gml_Script_%s" + rescan ───────────────────────
     * r9 is REUSED as the buffer pointer, so from 0xd2414 the old key is gone:
     * the rescan compares the table's names against the formatted string. */
    /* @0xd2404 mov r0, r9 */
    /* @0xd2408 bl 0x1e06dc */
    /* @0xd240c cmp r0, #0 */
    parent = Script_Find_Parent(r9);
    /* @0xd2410 beq 0xd22f4 */
    if (parent == 0)
        goto unknown;
    /* @0xd2414 add r9, sp, #4 */
    /* @0xd2418 ldr r2, [pc, #0xa8] */
    /* @0xd241c ldr r3, [r0, #0x14] */
    /* @0xd2420 mov r1, #4096 */
    /* @0xd2424 add r2, pc, r2 */
    /* @0xd2428 mov r0, r9 */
    /* @0xd242c bl 0xb65c8 */
    r9 = buf;
    snprintf(buf, VM_SNPRINTF_CAP, VM_FMT_SCRIPT,
             *(const char **)((const char *)parent + VM_SCRIPT_NAME_OFF));

    /* @0xd2430 ldr r10, [r11] */
    /* @0xd2434 cmp r10, #0 */
    n = g_numFunctionsForLocalVars;
    /* @0xd2438 ble 0xd2484 */
    if (n <= 0)
        goto unknown;
    /* @0xd243c ldr r3, [pc, #0x6c] */
    /* @0xd2440 mov r5, #0 */
    /* @0xd2444 ldr r3, [r8, r3] */
    /* @0xd2448 ldr r4, [r3] */
    fe = *g_localVariableNamesForFunctions;
    i = 0;
    /* @0xd244c b 0xd2460 */
    for (;;) {
        /* @0xd2460 ldr r0, [r4] */
        /* @0xd2464 mov r1, r9 */
        /* @0xd2468 bl 0xb6574 */
        /* @0xd246c cmp r0, #0 */
        /* @0xd2470 bne 0xd2450 */
        if (strcmp(fe->name, r9) == 0)
            goto fn_slot;
        /* @0xd2450 add r5, r5, #1 */
        /* @0xd2454 add r4, r4, #12 */
        /* @0xd2458 cmp r5, r10 */
        /* @0xd245c beq 0xd2478 */
        i = i + 1;
        fe = fe + 1;
        if (i == n)
            goto unknown;
    }

    /* ── the rescan's own two landings ──────────────────────────────────────
     * HIT re-uses the shared value block (0xd22d4, i.e. `b 0xd22d4`), MISS
     * falls to the two unknown-string loads that close the body.  Both of
     * those load the SAME rodata string from different pool words. */
    /* @0xd2474 b 0xd22d4 */
    /* @0xd2478 ldr r0, [pc, #0x4c] */
    /* @0xd247c add r0, pc, r0 */
    /* @0xd2480 b 0xd22fc */
    /* @0xd2484 ldr r0, [pc, #0x44] */
    /* @0xd2488 add r0, pc, r0 */
    /* @0xd248c b 0xd22fc */

head_231c:
    /* ── type == -1, else normalise ──────────────────────────────────────────
     * `cmn r1,#1`; a `bne` here is the ONLY way into the -9/-11/>100000
     * normalisation block. */
    /* @0xd231c cmn r1, #1 */
    /* @0xd2320 bne 0xd23d4 */
    if (type != VM_TYPE_INSTANCE)
        goto normalize;

instance:
    /* ── the instance name table, plus its reverse map ───────────────────────
     * slot < count takes the shared value block; otherwise the body scans the
     * map for an entry whose VALUE equals the slot and answers its KEY. */
    /* @0xd2324 ldr r3, [pc, #0x190] */
    /* @0xd2328 ldr r3, [r8, r3] */
    /* @0xd232c ldr r2, [r3, #0x4] */
    /* @0xd2330 cmp r7, r2 */
    t = &g_VarNamesInstance;
    /* @0xd2334 blt 0xd23bc */
    if (slot < t->count)
        goto arr_slot;

    /* @0xd2338 ldr r3, [pc, #0x180] */
    /* @0xd233c ldr r3, [r8, r3] */
    /* @0xd2340 ldr r5, [r3] */
    /* @0xd2344 ldr r4, [r5, #0x4] */
    /* @0xd2348 subs r12, r4, #1 */
    m = g_instanceVarLookup;
    dist = m->count - 1;            /* i, the "i-th occupied entry" selector */
    /* @0xd234c bmi 0xd22f4 */
    if (dist < 0)
        goto unknown;
    /* @0xd2350 cmp r4, r12 */
    /* @0xd2354 blt 0xd2494 */
    if (m->count < dist)
        goto unreachable_2494;      /* signed: only count == INT_MIN */
    for (;;) {
        /* @0xd2358 ldr r3, [r5, #0x10] */
        /* @0xd235c mov r2, #0 */
        me = m->entries;
        j = 0;
        /* @0xd2360 b 0xd236c */
        for (;;) {
            /* @0xd236c ldr r1, [r3, #0x8] */
            /* @0xd2370 cmp r1, #0 */
            /* @0xd2374 ble 0xd2368 */
            if ((int32_t)me->hash <= 0) {
                /* @0xd2368 add r3, r3, #12 */
                me = me + 1;        /* skip: advance the cursor only */
                continue;
            }
            /* @0xd2378 cmp r12, r2 */
            /* @0xd237c bne 0xd2364 */
            if (dist != j) {
                /* @0xd2364 add r2, r2, #1 */
                /* ... then falls into the same 0xd2368 cursor advance */
                j = j + 1;
                me = me + 1;
                continue;
            }
            /* @0xd2380 ldr r0, [r3], #4 */
            /* @0xd2384 ldr r3, [r3] */
            /* @0xd2388 cmp r3, r7 */
            /* @0xd238c beq 0xd22fc */
            if (me->value == slot)
                return me->key;
            /* @0xd2390 subs r12, r12, #1 */
            break;                  /* the mismatch path decrements i */
        }
        dist = dist - 1;
        /* @0xd2394 bhs 0xd2350 */
        if ((uint32_t)dist >= 0x80000000u) {
            /* i went negative: the unsigned `bhs` fails -> unknown */
            /* @0xd2398 b 0xd22f4 */
            goto unknown;
        }
        /* back to 0xd2350, which re-tests count < i and reloads entries */
        if (m->count < dist)
            goto unreachable_2494;
    }

global:
    /* ── the global name table: two checks, count then size ──────────────────
     * slot >= count answers "<unknown variable>"; a slot that passes count but
     * not size answers NULL - two different failures, still visible here. */
    /* @0xd23a8 ldr r3, [pc, #0x114] */
    /* @0xd23ac ldr r3, [r8, r3] */
    /* @0xd23b0 ldr r2, [r3, #0x4] */
    /* @0xd23b4 cmp r7, r2 */
    t = &g_VarNamesGlobal;
    /* @0xd23b8 bge 0xd22f4 */
    if (slot >= t->count)
        goto unknown;

arr_slot:
    /* ── the shared value block (global path and instance in-range path) ─────
     * 0xd23bc..0xd23d0 is ONE block, reached from 0xd23b8 falling through and
     * from 0xd2334's `blt`, with r3 = whichever table was selected. */
    /* @0xd23bc ldr r2, [r3] */
    /* @0xd23c0 cmp r7, r2 */
    /* @0xd23c4 ldrlt r3, [r3, #0xc] */
    /* @0xd23c8 movge r0, #0 */
    /* @0xd23cc ldrlt r0, [r3, r7, lsl #2] */
    /* @0xd23d0 b 0xd22fc */
    if (slot < t->size)
        return t->data[slot];
    return 0;                       /* ge: NULL, NOT the unknown string */

normalize:
    /* ── everything else folds into the instance domain ─────────────────────
     * (type & ~2) == -11 catches -9 and -11; any type > 100000 is accepted
     * outright (`orrgt r3,r2,#1`).  Note `movle` takes the AND result and
     * `orrgt` forces it to 1. */
    /* @0xd23d4 bic r2, r1, #2 */
    /* @0xd23d8 movw r3, #0x86a0 */
    /* @0xd23dc cmn r2, #11 */
    /* @0xd23e0 movt r3, #0x1 */
    /* @0xd23e4 movne r2, #0 */
    /* @0xd23e8 moveq r2, #1 */
    /* @0xd23ec cmp r1, r3 */
    /* @0xd23f0 movle r3, r2 */
    /* @0xd23f4 orrgt r3, r2, #1 */
    /* @0xd23f8 cmp r3, #0 */
    key_hits = ((type & ~2) == -11) ? 1 : 0;
    if (type > 100000)
        key_hits = key_hits | 1;
    /* @0xd23fc beq 0xd22f4 */
    if (key_hits == 0)
        goto unknown;
    /* @0xd2400 b 0xd2324 */
    goto instance;

unknown:
    /* ── the one unknown string, and the single exit ────────────────────────
     * Six `b`/`beq` sites plus this fall-through all land on 0xd22fc, which
     * verifies the canary and pops.  0xd22f4/0xd22f8 load the rodata string
     * 0x332760 - the SAME string from four pool words (0xd24b8, 0xd24cc,
     * 0xd24d0 and the direct 0x0d22f4 path). */
    /* @0xd22f4 ldr r0, [pc, #0x1bc] */
    /* @0xd22f8 add r0, pc, r0 */
    /* @0xd22fc add r3, sp, #8192 */
    /* @0xd2300 ldr r2, [r3, #-0xffc] */
    /* @0xd2304 ldr r3, [r6] */
    /* @0xd2308 cmp r2, r3 */
    /* @0xd230c bne 0xd2490 */
    /* @0xd2310 add sp, sp, #4096 */
    /* @0xd2314 add sp, sp, #12 */
    /* @0xd2318 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
    return VM_MSG_UNKNOWN_VARIABLE;

unreachable_2494:
    /* 0xd2354's `blt` is unreachable for any count that is not INT_MIN
     * (count < count-1 cannot hold otherwise).  It is documented, not
     * translated: 0xd2494 sets key=0 and r3=0 and jumps back into 0xd2384,
     * which then loads from address 0 and faults. */
    /* @0xd2490 bl 0xb65d4 */
    /* @0xd2494 mov r0, #0 */
    /* @0xd2498 mov r3, r0 */
    /* @0xd249c b 0xd2384 */
    return VM_MSG_UNKNOWN_VARIABLE;
}

/* Literal pool (13 words).  llvm-objdump decodes the first as `eorseq pc, ...`
 * and the rest as <unknown>, which is why the census documents them as words: */
/* @0xd24a0 .word 0x0031fa10 */
/* 0xd24a0 + pc 0xd2248 = 0x003f1c58, the body's GOT base (r8) */
/* @0xd24a4 .word 0xffffbd00 */
/* -0x4300 -> 0x003ed958 __stack_chk_guard */
/* @0xd24a8 .word 0xffffbf04 */
/* -0x40fc -> 0x003edb5c g_subFunctionsOption (gate 1) */
/* @0xd24ac .word 0xffffbf5c */
/* -0x40a4 -> 0x003edbb4 g_numFunctionsForLocalVars */
/* @0xd24b0 .word 0xffffbf60 */
/* -0x40a0 -> 0x003edbb8 g_localVariableNamesForFunctions */
/* @0xd24b4 .word 0xffffbf68 */
/* -0x4098 -> 0x003edbc0 g_fJSGarbageCollection (gate 2) */
/* @0xd24b8 .word 0x00260460 */
/* 0xd2300 + 0x260460 = 0x00332760 "<unknown variable>" */
/* @0xd24bc .word 0xffffbf50 */
/* -0x40b0 -> 0x003edba8 g_VarNamesInstance */
/* @0xd24c0 .word 0xffffbf54 */
/* -0x40ac -> 0x003edbac g_instanceVarLookup */
/* @0xd24c4 .word 0xffffbf4c */
/* -0x40b4 -> 0x003edba4 g_VarNamesGlobal */
/* @0xd24c8 .word 0x00260348 */
/* 0xd242c + 0x260348 = 0x00332774 "gml_Script_%s" */
/* @0xd24cc .word 0x002602dc */
/* 0xd247c + 0x2602dc = 0x00332760 "<unknown variable>" (rescan miss) */
/* @0xd24d0 .word 0x002602d0 */
/* 0xd2488 + 0x2602d0 = 0x00332760 "<unknown variable>" (empty table) */
