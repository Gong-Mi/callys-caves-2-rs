/*
 * variable_resolve.c — static C translation of
 * _Z17Variable_GetValueiiiP6RValue @0x1f3ce0 in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Every instruction of the body appears below exactly once, in address order,
 * with its verbatim llvm-objdump operand text:
 *
 *   llvm-objdump -d --start-address=0x1f3ce0 --stop-address=0x1f3f8c \
 *       -M reg-names-std <libyoyo_armv7.so>
 *
 * 164 instructions + 7 literal-pool words.  Register roles: r0 = sel (until a
 * path overwrites it with the instance), r7 = &failure flag, r6 = .got base
 * (0x3f1c58, later reused as the scan-2 index), r4 = zero baseline, then a
 * scratch.  The body pushes r4..r11 and never lr: all five success exits are
 * `pop {r4..r11}` + `b 0x1f3b8c`, the single `bx lr` is the failure exit.
 *
 * Four dispatch paths, decided by three compares (0x1f3ce4 cmn #3,
 * 0x1f3d04 blt #0, 0x1f3d14 cmp #0x1869f):
 *
 *   sel == -3        the room instance chain *(*(0x54298c)) +0x80, next +0x178,
 *                    first instance with +0x68 and +0x69 both zero
 *   0..99999         object index: g_ObjectHash -> CObjectGM -> [0xd0] instance
 *                    list; then the two fallback scan lists
 *   > 99999          instance id: ms_ID2InstanceE, full 32-bit key compare,
 *                    only +0x68 is checked (+0x69 is NOT: a deactivated
 *                    instance is still readable by id)
 *   other negatives  immediate failure, no table is touched
 *
 * What this body does NOT do (the differential keeps all of it true):
 *   * it reads no RValue field and never writes `out` - on every failure exit
 *     the caller's preset tag survives untouched;
 *   * it never decodes varid or arrindex; both reach Direct in the same
 *     registers they arrived in;
 *   * the only store it performs is the 1-byte failure flag at 0x75505c,
 *     which it also clears unconditionally on entry.
 */
#include "variable_resolve.h"

typedef uint32_t u32;

static u32 rd32(const void *p)
{
    u32 v;
    __builtin_memcpy(&v, p, sizeof v);
    return v;
}

static unsigned rd8(const void *p)
{
    return *(const unsigned char *)p;
}

int Variable_GetValue(int id, int varid, int arrindex, void *out)
{
    const unsigned char *inst;      /* the instance under test             */
    const unsigned char *node;      /* a hash-table node / chain node      */
    const unsigned char *obj;       /* a CObjectGM                         */
    const unsigned char *items;     /* a fallback list's item array        */
    u32 mask, count, i, idx, nexto, hit, d, c2;
    int sel = id;

    /* 0x1f3ce0 push {r4, r5, r6, r7, r8, r9, r10, r11}   -- no lr: success exits are pop + tail b */
    /* 0x1f3ce4 cmn  r0, #3                 -- Z iff sel == -3 */
    /* 0x1f3ce8 ldr  r6, [pc, #0x280]       -- pool @0x1f3f70 = 0x001fdf5c */
    /* 0x1f3cec mov  r4, #0                 -- r4 = 0: the flag value, then the null baseline */
    /* 0x1f3cf0 ldr  r12, [pc, #0x27c]      -- pool @0x1f3f74 = 0xffffc110 = -0x3ef0 */
    /* 0x1f3cf4 add  r6, pc, r6             -- r6 = 0x1f3cfc + 0x1fdf5c = 0x3f1c58 (.got) */
    /* 0x1f3cf8 ldr  r7, [r6, r12]          -- r7 = *(0x3edd68) = &failure flag */
    /* 0x1f3cfc strb r4, [r7]               -- flag = 0 on entry, unconditionally */
    g_var_resolve_failed = 0;

    /* 0x1f3d00 beq  0x1f3f0c               -- sel == -3 -> room instance chain */
    if (sel == SEL_ALL_INSTANCES)
        goto ROOM;

    /* 0x1f3d04 cmp  r0, #0 */
    /* 0x1f3d08 blt  0x1f3e68               -- sel < 0 (and != -3) -> fail, no table touched */
    if (sel < 0)
        goto FAIL;

    /* 0x1f3d0c movw r12, #0x869f */
    /* 0x1f3d10 movt r12, #0x1              -- r12 = 99999 */
    /* 0x1f3d14 cmp  r0, r12 */
    /* 0x1f3d18 ble  0x1f3e7c               -- sel <= 99999 -> object index branch */
    if (sel <= SEL_INSTANCE_MAX)
        goto OBJECT_HASH;

    /* ── instance id (sel > 99999): ms_ID2InstanceE, full 32-bit key ────────
     * The GOT slot holds the table body itself (0x536f28), so 0x1f3d20 is a
     * symbol load, not a pointer-variable dereference. */
    /* 0x1f3d1c ldr  r12, [pc, #0x254]      -- pool @0x1f3f78 = 0xffffbff4 = -0x400c */
    /* 0x1f3d20 ldr  r12, [r6, r12]         -- r12 = 0x536f28 = ms_ID2InstanceE */
    /* 0x1f3d24 ldr  r4, [r12, #0x4]        -- mask */
    /* 0x1f3d28 ldr  r12, [r12]             -- bucket array */
    /* 0x1f3d2c and  r4, r0, r4             -- bucket = sel & mask */
    /* 0x1f3d30 ldr  r12, [r12, r4, lsl #3] -- 8 B per bucket, +0 = chain head */
    {
        const var_hash_table *t = &g_inst_table;
        mask = t->mask;
        node = (const unsigned char *)(uintptr_t)rd32(
                   (const unsigned char *)(uintptr_t)t->buckets +
                   ((u32)sel & mask) * BUCKET_STRIDE);

        /* 0x1f3d34 cmp  r12, #0 */
        /* 0x1f3d38 bne  0x1f3d4c             -- non-empty bucket -> compare key */
        if (node == 0) {
            /* 0x1f3d3c b 0x1f3e68 */
            goto FAIL;
        }
        for (;;) {
            /* 0x1f3d40 ldr  r12, [r12, #0x4] -- node = node->next (hash node next is +4) */
            /* 0x1f3d44 cmp  r12, #0 */
            /* 0x1f3d48 beq  0x1f3e68         -- chain ended without a hit */
            /* 0x1f3d4c ldr  r4, [r12, #0x8]  -- node->id (full 32-bit; the bucket is only the index) */
            /* 0x1f3d50 cmp  r0, r4 */
            /* 0x1f3d54 bne  0x1f3d40         -- collision -> next node */
            if ((u32)rd32(node + HNODE_KEY) == (u32)sel)
                break;
            node = (const unsigned char *)(uintptr_t)rd32(node + HNODE_NEXT);
            if (node == 0)
                goto FAIL;                  /* 0x1f3d48 */
        }
        /* 0x1f3d58 ldr  r0, [r12, #0xc]      -- node->instance */
        inst = (const unsigned char *)(uintptr_t)rd32(node + HNODE_VALUE);
        /* 0x1f3d5c cmp  r0, #0 */
        /* 0x1f3d60 beq  0x1f3e68             -- null value -> fail */
        if (inst == 0)
            goto FAIL;
        /* 0x1f3d64 ldrb r12, [r0, #0x68]     -- the destroyed byte */
        /* 0x1f3d68 cmp  r12, #0 */
        /* 0x1f3d6c bne  0x1f3e68             -- destroyed -> fail (+0x69 is never read here) */
        if (rd8(inst + INST_DESTROYED) != 0)
            goto FAIL;
        /* 0x1f3d70 pop  {r4, r5, r6, r7, r8, r9, r10, r11} */
        /* 0x1f3d74 b    0x1f3b8c             -- tail jump Direct(inst, varid, arrindex, out) */
        return Variable_GetValue_Direct((void *)(uintptr_t)inst, varid,
                                        arrindex, out);
    }

    /* ── fallback scan list 1 (0x542a64) ───────────────────────────────────
     * Reached from the object-index branch, never from the id branch.  The
     * membership test is not "same CObjectGM": it walks inst->[0x80] up the
     * +0x48 parent chain comparing +0x18 object indices, i.e. "this instance
     * belongs to sel or to one of sel's descendants" = the `with (sel)` member
     * predicate.  Only then are the two liveness bytes checked. */
SCAN1:
    /* 0x1f3d78 ldr  r12, [pc, #0x1fc]      -- pool @0x1f3f7c = 0xffffbff0 = -0x4010 */
    /* 0x1f3d7c ldr  r10, [r6, r12]         -- r10 = 0x542a64 (cell IS the list) */
    /* 0x1f3d80 ldr  r11, [r10, #0x8]       -- count */
    /* 0x1f3d84 cmp  r11, #0 */
    /* 0x1f3d88 ble  0x1f3df0               -- count <= 0 -> skip to list 2 */
    count = (u32)g_scan_list1.count;
    if ((int32_t)count <= 0)
        goto SCAN2;
    /* 0x1f3d8c mov  r8, #0                 -- i = 0 */
    i = 0;
    for (;;) {
        /* 0x1f3d90 ldr  r12, [r10]         -- item array (re-read every pass) */
        /* 0x1f3d94 ldr  r9, [r12, r8, lsl #2] -- inst = items[i], 4 B elements */
        items = (const unsigned char *)(uintptr_t)g_scan_list1.items;
        inst = (const unsigned char *)(uintptr_t)rd32(items + i * LIST_ITEM_STRIDE);
        /* 0x1f3d98 ldr  r12, [r9, #0x80]    -- inst->[0x80] = CObjectGM* */
        /* 0x1f3d9c cmp  r12, #0 */
        /* 0x1f3da0 beq  0x1f3de4            -- no object -> next item */
        obj = (const unsigned char *)(uintptr_t)rd32(inst + INST_OBJ);
        if (obj != 0) {
            /* 0x1f3da4 ldr  r4, [r12, #0x18] -- this level's object index */
            /* 0x1f3da8 ldr  r12, [r12, #0x48] -- its parent */
            /* 0x1f3dac cmp  r0, r4 */
            /* 0x1f3db0 movne r5, #0          -- not this level */
            /* 0x1f3db4 moveq r5, #1          -- this level matches */
            /* 0x1f3db8 cmp  r0, r4           -- (re-compare: the loop condition) */
            /* 0x1f3dbc cmpne r12, #0         -- continue only while sel != index AND parent != 0 */
            /* 0x1f3dc0 bne  0x1f3da4 */
            node = obj;
            for (;;) {
                idx = rd32(node + OGM_INDEX);
                nexto = rd32(node + OGM_PARENT);
                hit = ((u32)sel == idx) ? 1u : 0u;
                if ((u32)sel == idx || nexto == 0)
                    break;
                node = (const unsigned char *)(uintptr_t)nexto;
            }
            /* 0x1f3dc4 cmp  r5, #0 */
            /* 0x1f3dc8 beq  0x1f3de4         -- ancestor chain had no match -> next item */
            if (hit != 0) {
                /* 0x1f3dcc ldrb r12, [r9, #0x68] */
                /* 0x1f3dd0 cmp  r12, #0 */
                /* 0x1f3dd4 bne  0x1f3de4         -- destroyed -> next item */
                /* 0x1f3dd8 ldrb r12, [r9, #0x69] */
                /* 0x1f3ddc cmp  r12, #0 */
                /* 0x1f3de0 beq  0x1f3f58         -- both bytes zero -> HIT1 */
                if (rd8(inst + INST_DESTROYED) == 0 &&
                    rd8(inst + INST_DEACTIVATED) == 0)
                    goto HIT1;
            }
        }
        /* 0x1f3de4 add  r8, r8, #1 */
        /* 0x1f3de8 cmp  r8, r11 */
        /* 0x1f3dec bne  0x1f3d90 */
        i++;
        if (i != count)
            continue;
        break;
    }

    /* ── fallback scan list 2 (0x542a4c) ───────────────────────────────────
     * Same body, three differences: the global, the "equal" bit is derived
     * arithmetically (subs/rsbs/adcs instead of movne/moveq) and the loop bound
     * lives in r10 (r11 is the scratch there).  The arithmetic collapses to
     * "1 iff sel == index" exactly like list 1 - see the comment at adcs. */
SCAN2:
    /* 0x1f3df0 ldr  r12, [pc, #0x188]      -- pool @0x1f3f80 = 0xffffbff8 = -0x4008 */
    /* 0x1f3df4 ldr  r9, [r6, r12]          -- r9 = 0x542a4c (cell IS the list) */
    /* 0x1f3df8 ldr  r10, [r9, #0x8]        -- count */
    /* 0x1f3dfc cmp  r10, #0 */
    /* 0x1f3e00 ble  0x1f3e68               -- both lists empty -> fail (last gate) */
    count = (u32)g_scan_list2.count;
    if ((int32_t)count <= 0)
        goto FAIL;
    /* 0x1f3e04 mov  r6, #0                 -- i = 0 (r6 held the .got base, now dead) */
    i = 0;
    for (;;) {
        /* 0x1f3e08 ldr  r12, [r9] */
        /* 0x1f3e0c ldr  r8, [r12, r6, lsl #2] -- inst = items[i] */
        items = (const unsigned char *)(uintptr_t)g_scan_list2.items;
        inst = (const unsigned char *)(uintptr_t)rd32(items + i * LIST_ITEM_STRIDE);
        /* 0x1f3e10 ldr  r12, [r8, #0x80] */
        /* 0x1f3e14 cmp  r12, #0 */
        /* 0x1f3e18 beq  0x1f3e5c            -- no object -> next item */
        obj = (const unsigned char *)(uintptr_t)rd32(inst + INST_OBJ);
        if (obj != 0) {
            /* 0x1f3e1c ldr  r4, [r12, #0x18] */
            /* 0x1f3e20 ldr  r12, [r12, #0x48] */
            /* 0x1f3e24 subs r11, r0, r4       -- d = sel - index, C = (sel >= index) unsigned */
            /* 0x1f3e28 rsbs r5, r11, #0       -- r5 = -d, C = (d == 0) */
            /* 0x1f3e2c adcs r5, r5, r11       -- r5 = -d + d + C2 = 1 iff d == 0 */
            /* 0x1f3e30 cmp  r0, r4            -- loop condition, recomputed */
            /* 0x1f3e34 cmpne r12, #0 */
            /* 0x1f3e38 bne  0x1f3e1c */
            node = obj;
            for (;;) {
                idx = rd32(node + OGM_INDEX);
                nexto = rd32(node + OGM_PARENT);
                d = (u32)sel - idx;                 /* subs */
                c2 = (d == 0u) ? 1u : 0u;           /* rsbs 0-d: C set iff d == 0 */
                hit = (0u - d) + d + c2;            /* adcs: 1 iff d == 0 */
                if ((u32)sel == idx || nexto == 0)
                    break;
                node = (const unsigned char *)(uintptr_t)nexto;
            }
            /* 0x1f3e3c cmp  r5, #0 */
            /* 0x1f3e40 beq  0x1f3e5c            -- no match -> next item */
            if (hit != 0) {
                /* 0x1f3e44 ldrb r12, [r8, #0x68] */
                /* 0x1f3e48 cmp  r12, #0 */
                /* 0x1f3e4c bne  0x1f3e5c          -- destroyed -> next item */
                /* 0x1f3e50 ldrb r12, [r8, #0x69] */
                /* 0x1f3e54 cmp  r12, #0 */
                /* 0x1f3e58 beq  0x1f3f64          -- both bytes zero -> HIT2 */
                if (rd8(inst + INST_DESTROYED) == 0 &&
                    rd8(inst + INST_DEACTIVATED) == 0)
                    goto HIT2;
            }
        }
        /* 0x1f3e5c add  r6, r6, #1 */
        /* 0x1f3e60 cmp  r6, r10 */
        /* 0x1f3e64 bne  0x1f3e08 */
        i++;
        if (i != count)
            continue;
        break;
    }

    /* ── failure exit: the whole function's only `bx lr` ──────────────────── */
FAIL:
    /* 0x1f3e68 mov  r3, #1                 -- r3 = 1: the flag's value */
    /* 0x1f3e6c mov  r0, #0                 -- return 0 = "not resolved" */
    /* 0x1f3e70 strb r3, [r7]               -- flag = 1 (this call failed) */
    /* 0x1f3e74 pop  {r4, r5, r6, r7, r8, r9, r10, r11} */
    /* 0x1f3e78 bx   lr                     -- out is NOT written: the caller's tag survives */
    g_var_resolve_failed = 1;
    return 0;

    /* ── object index (0 <= sel <= 99999) ──────────────────────────────────
     * Here the GOT slot holds a POINTER VARIABLE (0x542374), so 0x1f3e84 is a
     * second dereference that the id branch does not have. */
OBJECT_HASH:
    /* 0x1f3e7c ldr  r12, [pc, #0x100]      -- pool @0x1f3f84 = 0xffffbfec = -0x4014 */
    /* 0x1f3e80 ldr  r12, [r6, r12]         -- r12 = 0x542374 = value of g_ObjectHash */
    /* 0x1f3e84 ldr  r12, [r12]             -- ★ the extra load: the table body */
    /* 0x1f3e88 ldr  r4, [r12, #0x4]        -- mask */
    /* 0x1f3e8c ldr  r12, [r12]             -- bucket array */
    /* 0x1f3e90 and  r4, r0, r4             -- bucket = sel & mask */
    /* 0x1f3e94 ldr  r12, [r12, r4, lsl #3] -- chain head */
    {
        const var_hash_table *t = g_object_hash;
        mask = t->mask;
        node = (const unsigned char *)(uintptr_t)rd32(
                   (const unsigned char *)(uintptr_t)t->buckets +
                   ((u32)sel & mask) * BUCKET_STRIDE);

        /* 0x1f3e98 cmp  r12, #0 */
        /* 0x1f3e9c bne  0x1f3eb0             -- non-empty -> compare key */
        if (node == 0) {
            /* 0x1f3ea0 b 0x1f3d78 */
            goto SCAN1;
        }
        for (;;) {
            /* 0x1f3ea4 ldr  r12, [r12, #0x4] */
            /* 0x1f3ea8 cmp  r12, #0 */
            /* 0x1f3eac beq  0x1f3d78            -- chain ended -> scan list 1 */
            /* 0x1f3eb0 ldr  r4, [r12, #0x8]     -- node key = object index */
            /* 0x1f3eb4 cmp  r0, r4 */
            /* 0x1f3eb8 bne  0x1f3ea4            -- collision -> next node */
            if ((u32)rd32(node + HNODE_KEY) == (u32)sel)
                break;
            node = (const unsigned char *)(uintptr_t)rd32(node + HNODE_NEXT);
            if (node == 0)
                goto SCAN1;                     /* 0x1f3eac */
        }
        /* 0x1f3ebc ldr  r12, [r12, #0xc]     -- node value = CObjectGM* */
        /* 0x1f3ec0 cmp  r12, #0 */
        /* 0x1f3ec4 ldrne r12, [r12, #0xd0]  -- conditional load: the instance list head */
        /* 0x1f3ec8 beq  0x1f3d78             -- value NULL -> scan list 1 */
        obj = (const unsigned char *)(uintptr_t)rd32(node + HNODE_VALUE);
        if (obj == 0)
            goto SCAN1;
        node = (const unsigned char *)(uintptr_t)rd32(obj + OGM_INST_CHAIN);
        /* 0x1f3ecc cmp  r12, #0 */
        /* 0x1f3ed0 beq  0x1f3d78             -- no instance chain -> scan list 1 */
        for (;;) {
            if (node == 0)
                goto SCAN1;
            /* 0x1f3ed4 ldr  r4, [r12, #0x8] -- node->inst */
            /* 0x1f3ed8 cmp  r4, #0 */
            /* 0x1f3edc beq  0x1f3d78        -- head node without an instance -> scan list 1 */
            inst = (const unsigned char *)(uintptr_t)rd32(node + CHAIN_INST);
            if (inst == 0)
                goto SCAN1;
            /* 0x1f3ee0 ldr  r4, [r12, #0x8] -- read again (the previous value went to the compare) */
            inst = (const unsigned char *)(uintptr_t)rd32(node + CHAIN_INST);
            /* 0x1f3ee4 ldr  r12, [r12]      -- node = node->next, at +0 in this 12 B node */
            node = (const unsigned char *)(uintptr_t)rd32(node + CHAIN_NEXT);
            /* 0x1f3ee8 ldrb r5, [r4, #0x68] */
            /* 0x1f3eec cmp  r5, #0 */
            /* 0x1f3ef0 bne  0x1f3ecc        -- destroyed -> next node */
            if (rd8(inst + INST_DESTROYED) != 0)
                continue;
            /* 0x1f3ef4 ldrb r5, [r4, #0x69] */
            /* 0x1f3ef8 cmp  r5, #0 */
            /* 0x1f3efc bne  0x1f3ecc        -- deactivated -> next node */
            if (rd8(inst + INST_DEACTIVATED) != 0)
                continue;
            /* 0x1f3f00 mov  r0, r4          -- r0 = the instance */
            /* 0x1f3f04 pop  {r4, r5, r6, r7, r8, r9, r10, r11} */
            /* 0x1f3f08 b    0x1f3b8c        -- tail jump Direct(inst, varid, arrindex, out) */
            return Variable_GetValue_Direct((void *)(uintptr_t)inst, varid,
                                            arrindex, out);
        }
    }

    /* ── sel == -3: the room's instance chain ──────────────────────────────
     * *(0x54298c) is a pointer variable; its target's first word is the
     * CRoom*, whose +0x80 is the instance list head.  `next` (+0x178) is
     * loaded BEFORE the liveness bytes are tested, so an instance that is
     * unlinked during the test still yields a valid successor. */
ROOM:
    /* 0x1f3f0c ldr  r0, [pc, #0x74]        -- pool @0x1f3f88 = 0xffffbcd8 = -0x4328 */
    /* 0x1f3f10 ldr  r0, [r6, r0]           -- r0 = 0x54298c, the address of Run_Room */
    /* 0x1f3f14 ldr  r0, [r0]               -- r0 = CRoom* : one deref of the pointer variable */
    /* 0x1f3f18 ldr  r0, [r0, #0x80]        -- the room's instance chain head */
    /* 0x1f3f1c cmp  r0, r4                 -- r4 is still the entry's 0 */
    /* 0x1f3f20 bne  0x1f3f34               -- non-empty -> judge the head */
    inst = (const unsigned char *)(uintptr_t)rd32(
               (const unsigned char *)(uintptr_t)g_run_room + ROOM_INST_HEAD);
    if (inst == 0) {
        /* 0x1f3f24 b 0x1f3e68 */
        goto FAIL;
    }
    for (;;) {
        /* 0x1f3f34 ldrb r4, [r0, #0x68] */
        /* 0x1f3f38 ldr  r12, [r0, #0x178]   -- next first, then the gates */
        /* 0x1f3f3c cmp  r4, #0 */
        /* 0x1f3f40 bne  0x1f3f28            -- destroyed -> advance */
        idx = rd8(inst + INST_DESTROYED);
        nexto = rd32(inst + INST_ROOM_NEXT);
        if (idx != 0)
            goto ROOM_NEXT;
        /* 0x1f3f44 ldrb r4, [r0, #0x69] */
        /* 0x1f3f48 cmp  r4, #0 */
        /* 0x1f3f4c bne  0x1f3f28            -- deactivated -> advance */
        if (rd8(inst + INST_DEACTIVATED) != 0)
            goto ROOM_NEXT;
        /* 0x1f3f50 pop  {r4, r5, r6, r7, r8, r9, r10, r11} */
        /* 0x1f3f54 b    0x1f3b8c            -- first live instance wins */
        return Variable_GetValue_Direct((void *)(uintptr_t)inst, varid,
                                        arrindex, out);
    ROOM_NEXT:
        /* 0x1f3f28 cmp  r12, #0 */
        /* 0x1f3f2c mov  r0, r12 */
        /* 0x1f3f30 beq  0x1f3e68            -- chain end -> fail */
        if (nexto == 0)
            goto FAIL;
        inst = (const unsigned char *)(uintptr_t)nexto;
    }

    /* ── the two scan-list hit exits ──────────────────────────────────────── */
HIT1:
    /* 0x1f3f58 mov  r0, r9                 -- the list-1 instance */
    /* 0x1f3f5c pop  {r4, r5, r6, r7, r8, r9, r10, r11} */
    /* 0x1f3f60 b    0x1f3b8c */
    return Variable_GetValue_Direct((void *)(uintptr_t)inst, varid, arrindex,
                                    out);
HIT2:
    /* 0x1f3f64 mov  r0, r8                 -- the list-2 instance */
    /* 0x1f3f68 pop  {r4, r5, r6, r7, r8, r9, r10, r11} */
    /* 0x1f3f6c b    0x1f3b8c */
    return Variable_GetValue_Direct((void *)(uintptr_t)inst, varid, arrindex,
                                    out);

    /* ── literal pool (0x1f3f70..0x1f3f88) ────────────────────────────────
     * .got-relative offsets, all R_ARM_RELATIVE to this module's own .bss.
     * 0x1f3f70 is shown by llvm-objdump as an instruction (`andseq sp, pc,
     * r12, asr pc`) because it is decoded as data reached by `ldr`; it is a
     * pool word, not code. */
    /* 0x1f3f70 .word 0x001fdf5c */    /* GOT bias, consumed by 0x1f3cf4 */
    /* 0x1f3f74 .word 0xffffc110 */    /* -0x3ef0  -> flag slot 0x3edd68 */
    /* 0x1f3f78 .word 0xffffbff4 */    /* -0x400c  -> ms_ID2InstanceE 0x3edc4c */
    /* 0x1f3f7c .word 0xffffbff0 */    /* -0x4010  -> list 1 0x3edc48 */
    /* 0x1f3f80 .word 0xffffbff8 */    /* -0x4008  -> list 2 0x3edc50 */
    /* 0x1f3f84 .word 0xffffbfec */    /* -0x4014  -> g_ObjectHash 0x3edc44 */
    /* 0x1f3f88 .word 0xffffbcd8 */    /* -0x4328  -> Run_Room slot 0x3ed930 */
}
