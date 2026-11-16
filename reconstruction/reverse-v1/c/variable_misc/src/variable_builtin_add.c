/*
 * variable_builtin_add.c — static C translation of
 * _Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b @0x001f4da8 in
 * libyoyo ARMv7 (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * 164 instructions + 6 literal-pool words (0x001f5038..0x001f504c), 0x2a8 =
 * 680 B.  This is the writer half of the builtin-variable table: it appends a
 * 16 B entry, computes the writable bit from the setter, and inserts the
 * name->id pair into a Robin-Hood open-addressing map that it grows by
 * doubling when loading crosses 0.6.
 *
 *   0x1f4da8  ldr r3,[pc,#0x28c]   runs BEFORE the push and overwrites r3,
 *                                  which is the FOURTH argument: `flag` is dead
 *                                  from the first instruction on
 *   0x1f4dcc  cmp r3,#500          equality, not >=: the table is fixed at
 *                                  500x16 B and rolling count back past 500 is
 *                                  not handled
 *   0x1f4ddc  entry->name != NULL  -> Free() it first (defensive: only
 *                                  reachable if count was rolled back)
 *   0x1f4e38  store order: name -> writable -> getter/setter (one stmib),
 *                                  i.e. the entry is complete before the map
 *                                  can point at it
 *   0x1f4e44  map->count > map->threshold -> grow, then insert
 *   0x1f4e48..0x1f4f18  the inlined Robin Hood probe
 *   0x1f4f1c  builtin_numb++ LAST, so the entry and the map are consistent
 *             before the table advertises the new count
 *
 * The probe, register for register (this is the part worth reading):
 *
 *   hash = CHashMapCalculateHash(name) & 0x7fffffff   (0 never marks an entry)
 *   idx  = hash & mask
 *   e = &entries[idx]; if (e->hash == 0) -> store
 *   dist = 0
 *   loop:
 *     r12 = (idx + cap - (e->hash & mask)) & mask   ; e's own distance
 *     if (r12 <  dist)  -> swap (evict the richer entry into our slot)
 *     if (r12 != dist)  -> dist = r12; advance
 *     if (e->hash != hash) -> advance
 *     if (e->key  != key)  -> advance          ; POINTER comparison only, so
 *                                              ; two equal strings at different
 *                                              ; addresses are two entries
 *     -> duplicate: overwrite value, undo the count++ done at 0x1f4e50
 *   advance: idx = (idx+1) & mask; dist = r12+1
 *
 * Three things this body does NOT do, and the translation keeps true:
 *   * the 500-entry table never grows; the map does.  count == 500 answers with
 *     ShowMessage("INTERNAL ERROR: Adding too many variables") and returns
 *     without touching anything (note: `beq`, so count > 500 would append out
 *     of bounds - unreachable, count only moves by +1 / -1);
 *   * `flag` (the 4th argument, the one 7 of the 212 call sites pass
 *     inconsistently) is never read: writable = (setter != NULL) instead;
 *   * duplicate detection is by KEY POINTER, not by string content, so the same
 *     name added twice from two different buffers becomes two table entries
 *     and two map entries.
 *
 * Callee status: YYStrDup 0x0db8c8, MemoryManager::Alloc 0x27ce78 /
 * Free 0x27c2d0, CHashMapCalculateHash 0x1eeb88 and CHashMap::Insert 0x0d261c
 * are UNRECOVERED and are answered by identical stubs on both arms; memset@plt
 * is implemented identically.  The hash stub therefore DEFINES the bucket
 * layout this test compares, and the Insert stub defines the post-grow map;
 * both are declared in the harness scope.  Nothing here is device equivalence.
 */
#include "variable_misc.h"

void Variable_BuiltIn_Add(const char *name, vm_getter_fn getter,
                          vm_getter_fn setter, int flag)
{
    const char *key = name;         /* r6 - the probe's current key */
    vm_getter_fn g = getter;        /* r5 - getter, then the probe's distance */
    vm_getter_fn s = setter;        /* r9 - setter, then swap scratch */
    int32_t *countp = &g_builtin_numb;   /* [sp+4] holds this address */
    int32_t count;                  /* r3 */
    vm_builtin_entry *table = g_builtin_variables;   /* r4 */
    vm_builtin_entry *entry;        /* r3 - &table[count] */
    int32_t slot;                   /* r10 - the entry index being filled */
    char *dup;                      /* r0 - YYStrDup's copy */
    vm_map *map;                    /* r8 */
    int32_t threshold;              /* r12 */
    int32_t mcount;                 /* r2 */
    int writable;                   /* r1 */
    uint32_t hash;                  /* r0 */
    uint32_t mask;                  /* r4, reused */
    uint32_t cap;                   /* r11 */
    vm_mapentry *entries;           /* r10, reused */
    vm_mapentry *e;                 /* r2 */
    uint32_t ehash;                 /* r1 */
    uint32_t dist;                  /* r5, reused */
    uint32_t r12;                   /* distance scratch */
    uint32_t idx;                   /* r3, reused */
    int32_t oldcap;                 /* r10 in the grow block */
    vm_mapentry *oldentries;        /* r9 in the grow block */
    uint32_t bytes;                 /* r4 in the grow block */
    vm_mapentry *block;             /* r0 in the grow block */
    int32_t i;                      /* r5 in the rehash loop */

    /* 0x1f4da8 is the dead-argument kill.  It also means this body can never
     * honour `flag`, whatever the caller passed - which is why the differential
     * varies it (p3) and expects no difference at all. */
    (void)flag;
    /* @0x1f4da8 ldr r3, [pc, #0x28c] */
    /* @0x1f4dac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
    /* @0x1f4db0 ldr r3, [pc, r3] */
    /* @0x1f4db4 sub sp, sp, #12 */
    /* @0x1f4db8 mov r6, r0 */
    /* @0x1f4dbc mov r5, r1 */
    /* @0x1f4dc0 mov r9, r2 */
    /* @0x1f4dc4 str r3, [sp, #0x4] */
    /* @0x1f4dc8 ldr r3, [r3] */
    count = *countp;

    /* ── the fixed 500-entry limit ───────────────────────────────────────────
     * `cmp #500` + `beq`, and the exit tail-jumps ShowMessage after popping:
     * it never returns to the caller, and builtin_numb is not written. */
    /* @0x1f4dcc cmp r3, #500 */
    /* @0x1f4dd0 beq 0x1f5024 */
    if (count == VM_BUILTIN_CAP) {
        /* @0x1f5024 ldr r0, [pc, #0x20] */
        /* @0x1f5028 add r0, pc, r0 */
        /* @0x1f502c add sp, sp, #12 */
        /* @0x1f5030 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
        /* @0x1f5034 b 0xc4b0c */
        ShowMessage(VM_MSG_TOO_MANY);
        return;
    }

    /* ── pick the slot: always `count`, and free a stale name first ──────────
     * The Free is defensive: with a purely append-only count it cannot fire,
     * which is exactly why the fixture stages a non-NULL table[1].name and
     * checks the call happens. */
    /* @0x1f4dd4 ldr r4, [pc, #0x264] */
    /* @0x1f4dd8 ldr r4, [pc, r4] */
    /* @0x1f4ddc ldr r0, [r4, r3, lsl #4] */
    /* @0x1f4de0 cmp r0, #0 */
    /* @0x1f4de4 moveq r10, r3 */
    /* @0x1f4de8 beq 0x1f4e04 */
    if (table[count].name != 0) {
        char *stale = table[count].name;
        /* @0x1f4dec bl 0x27c2d0 */
        MemoryManager_Free(stale);
        /* @0x1f4df0 ldr r3, [sp, #0x4] */
        /* @0x1f4df4 ldr r2, [r3] */
        /* @0x1f4df8 mov r3, #0 */
        /* @0x1f4dfc mov r10, r2 */
        /* @0x1f4e00 str r3, [r4, r2, lsl #4] */
        count = *countp;
        slot = count;
        table[count].name = 0;
    } else {
        slot = count;
    }

    /* ── write the four fields, in the original's order ─────────────────────
     * name is a YYStrDup copy (the table owns it), writable is COMPUTED from
     * the setter (`adds` + `movne`), and getter/setter go in with one stmib
     * from +4.  The map is not touched until the entry is complete. */
    /* @0x1f4e04 mov r0, r6 */
    /* @0x1f4e08 bl 0xdb8c8 */
    dup = YYStrDup(key);
    /* @0x1f4e0c ldr r3, [pc, #0x230] */
    /* @0x1f4e10 ldr r2, [sp, #0x4] */
    /* @0x1f4e14 adds r1, r9, #0 */
    writable = (s != 0) ? 1 : 0;
    /* @0x1f4e18 ldr r3, [pc, r3] */
    /* @0x1f4e1c movne r1, #1 */
    /* @0x1f4e20 ldr r8, [r3] */
    map = g_builtinVarLookup;
    /* @0x1f4e24 ldr r7, [r2] */
    slot = *countp;
    /* @0x1f4e28 ldr r12, [r8, #0xc] */
    threshold = map->threshold;
    /* @0x1f4e2c ldr r2, [r8, #0x4] */
    mcount = map->count;
    /* @0x1f4e30 add r3, r4, r7, lsl #4 */
    entry = &table[slot];
    /* @0x1f4e34 cmp r2, r12 */
    /* @0x1f4e38 str r0, [r4, r10, lsl #4] */
    table[slot].name = dup;
    /* @0x1f4e3c strb r1, [r3, #0xc] */
    entry->writable = (unsigned char)writable;
    /* @0x1f4e40 stmib r3, {r5, r9} */
    entry->getter = g;
    entry->setter = s;
    /* @0x1f4e44 bgt 0x1f4f34 */
    if (mcount > threshold)
        goto grow;

insert:
    /* ── insert: count first, then the hash and the probe ────────────────────
     * map->count is incremented BEFORE the probe so a duplicate key can undo
     * it (0x1f4f04); `bic r0,r0,#-2147483648` clears the sign bit so 0 remains
     * the "empty" sentinel. */
    /* @0x1f4e48 add r2, r2, #1 */
    mcount = mcount + 1;
    /* @0x1f4e4c mov r0, r6 */
    /* @0x1f4e50 str r2, [r8, #0x4] */
    map->count = mcount;
    /* @0x1f4e54 bl 0x1eeb88 */
    hash = CHashMap_CalculateHash(key);
    /* @0x1f4e58 ldr r4, [r8, #0x8] */
    mask = (uint32_t)map->mask;
    /* @0x1f4e5c ldr r10, [r8, #0x10] */
    entries = map->entries;
    /* @0x1f4e60 bic r0, r0, #-2147483648 */
    hash = hash & 0x7fffffffu;
    /* @0x1f4e64 and r3, r0, r4 */
    idx = hash & mask;
    /* @0x1f4e68 add r2, r3, r3, lsl #1 */
    /* @0x1f4e6c add r2, r10, r2, lsl #2 */
    e = &entries[idx];
    /* @0x1f4e70 ldr r1, [r2, #0x8] */
    ehash = e->hash;
    /* @0x1f4e74 cmp r1, #0 */
    if (ehash != 0) {
        /* @0x1f4e78 ldrne r11, [r8] */
        cap = (uint32_t)map->cap;
        /* @0x1f4e7c movne r5, #0 */
        dist = 0;
        /* @0x1f4e80 bne 0x1f4ec8 */
        goto probe;
    }
    /* @0x1f4e84 b 0x1f4f14 */
    goto store;

probe:
    /* ── Robin Hood comparison ───────────────────────────────────────────────
     * r12 = the resident entry's distance; if it is poorer (smaller) than the
     * one we carry, it moves out.  Equal distance falls through to the hash and
     * then the key POINTER. */
    /* @0x1f4ec8 add r12, r3, r11 */
    /* @0x1f4ecc and r9, r1, r4 */
    /* @0x1f4ed0 rsb r12, r9, r12 */
    /* @0x1f4ed4 and r12, r12, r4 */
    r12 = (idx + cap - (ehash & mask)) & mask;
    /* @0x1f4ed8 cmp r12, r5 */
    /* @0x1f4edc blt 0x1f4e88 */
    if ((int32_t)r12 < (int32_t)dist)
        goto swap;
    /* @0x1f4ee0 movne r12, r5 */
    /* @0x1f4ee4 bne 0x1f4ea8 */
    if (r12 != dist) {
        r12 = dist;
        goto advance;
    }
    /* @0x1f4ee8 cmp r1, r0 */
    /* @0x1f4eec bne 0x1f4ea8 */
    if (ehash != hash)
        goto advance;
    /* @0x1f4ef0 ldr r5, [r2] */
    /* @0x1f4ef4 cmp r6, r5 */
    /* @0x1f4ef8 bne 0x1f4ea8 */
    if ((const char *)e->key != key)
        goto advance;
    /* duplicate key (same pointer): overwrite and give the count back */
    /* @0x1f4efc ldr r3, [r8, #0x4] */
    /* @0x1f4f00 stm r2, {r6, r7} */
    /* @0x1f4f04 sub r3, r3, #1 */
    /* @0x1f4f08 str r1, [r2, #0x8] */
    /* @0x1f4f0c str r3, [r8, #0x4] */
    /* @0x1f4f10 b 0x1f4f1c */
    e->key = (char *)key;
    e->value = slot;
    map->count = map->count - 1;
    e->hash = ehash;
    goto count_up;

swap:
    /* `ldr r9,[r2]` / `ldr r5,[r2,#4]` save the evicted key and value, then the
     * carried key/hash/value become the evicted ones. */
    /* @0x1f4e88 ldr r9, [r2] */
    /* @0x1f4e8c ldr r5, [r2, #0x4] */
    /* @0x1f4e90 str r0, [r2, #0x8] */
    /* @0x1f4e94 mov r0, r1 */
    /* @0x1f4e98 str r6, [r2] */
    /* @0x1f4e9c mov r6, r9 */
    /* @0x1f4ea0 str r7, [r2, #0x4] */
    /* @0x1f4ea4 mov r7, r5 */
    {
        char *ekey = e->key;
        int32_t eval = e->value;
        e->hash = hash;
        hash = ehash;
        e->key = (char *)key;
        key = ekey;
        e->value = slot;
        slot = eval;
    }

advance:
    /* @0x1f4ea8 add r3, r3, #1 */
    idx = idx + 1;
    /* @0x1f4eac add r5, r12, #1 */
    dist = r12 + 1;
    /* @0x1f4eb0 and r3, r3, r4 */
    idx = idx & mask;
    /* @0x1f4eb4 add r2, r3, r3, lsl #1 */
    /* @0x1f4eb8 add r2, r10, r2, lsl #2 */
    e = &entries[idx];
    /* @0x1f4ebc ldr r1, [r2, #0x8] */
    ehash = e->hash;
    /* @0x1f4ec0 cmp r1, #0 */
    /* @0x1f4ec4 beq 0x1f4f14 */
    if (ehash == 0)
        goto store;
    goto probe;

store:
    /* ── an empty slot: key, value, hash ────────────────────────────────────
     * (0x1f4f00/0x1f4f14 are the same two stores; only the hash store differs
     * by which register holds it.) */
    /* @0x1f4f14 stm r2, {r6, r7} */
    /* @0x1f4f18 str r0, [r2, #0x8] */
    e->key = (char *)key;
    e->value = slot;
    e->hash = hash;

count_up:
    /* ── builtin_numb++ is the LAST write of the call ────────────────────────*/
    /* @0x1f4f1c ldr r2, [sp, #0x4] */
    /* @0x1f4f20 ldr r3, [r2] */
    /* @0x1f4f24 add r3, r3, #1 */
    /* @0x1f4f28 str r3, [r2] */
    *countp = *countp + 1;
    /* @0x1f4f2c add sp, sp, #12 */
    /* @0x1f4f30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
    return;

grow:
    /* ── doubling: cap*2, mask*2-1, 24c bytes, count 0, threshold 0.6*2c ────
     * Note the order: cap and mask are stored BEFORE the allocation, count is
     * zeroed before the threshold float work, and the old entries are rehashed
     * only after the clearing pass. */
    /* @0x1f4f34 ldr r10, [r8] */
    oldcap = map->cap;
    /* @0x1f4f38 mov r3, #1 */
    /* @0x1f4f3c ldr r1, [pc, #0x104] */
    /* @0x1f4f40 mov r2, #70 */
    /* @0x1f4f44 ldr r9, [r8, #0x10] */
    oldentries = map->entries;
    /* @0x1f4f48 lsl r0, r10, r3 */
    /* @0x1f4f4c add r1, pc, r1 */
    /* @0x1f4f50 add r4, r0, r10, lsl #2 */
    bytes = (uint32_t)((oldcap * 2) + (oldcap << 2));
    /* @0x1f4f54 str r0, [r8] */
    map->cap = oldcap * 2;
    /* @0x1f4f58 sub r0, r0, #1 */
    /* @0x1f4f5c str r0, [r8, #0x8] */
    map->mask = oldcap * 2 - 1;
    /* @0x1f4f60 lsl r4, r4, #2 */
    bytes = bytes << 2;                 /* 24c = (2c) * 12 */
    /* @0x1f4f64 mov r0, r4 */
    /* @0x1f4f68 bl 0x27ce78 */
    block = (vm_mapentry *)MemoryManager_Alloc(bytes, VM_MEMMGR_FILE,
                                              VM_BUILTIN_LINE, 1);
    /* @0x1f4f6c mov r2, r4 */
    /* @0x1f4f70 mov r1, #0 */
    /* @0x1f4f74 str r0, [r8, #0x10] */
    map->entries = block;
    /* @0x1f4f78 bl 0xb65b0 */
    memset(block, 0, bytes);
    /* @0x1f4f7c ldr r2, [r8] */
    /* @0x1f4f80 vldr s15, [pc, #176] */
    /* @0x1f4f84 mov r1, #0 */
    /* @0x1f4f88 cmp r2, r1 */
    /* @0x1f4f8c str r1, [r8, #0x4] */
    map->count = 0;
    /* @0x1f4f90 vmov s13, r2 */
    /* @0x1f4f94 vcvt.f32.s32 s14, s13 */
    /* @0x1f4f98 vmul.f32 s15, s14, s15 */
    /* @0x1f4f9c vcvt.s32.f32 s15, s15 */
    /* @0x1f4fa0 vstr s15, [r8, #12] */
    map->threshold = (int32_t)(VM_MAP_LOAD_FACTOR * (float)map->cap);
    /* @0x1f4fa4 ble 0x1f4fc4 */
    if (map->cap > 0) {
        /* @0x1f4fa8 add r2, r2, r2, lsl #1 */
        /* @0x1f4fac ldr r3, [r8, #0x10] */
        /* @0x1f4fb0 add r2, r3, r2, lsl #2 */
        /* @0x1f4fb4 str r1, [r3, #0x8] */
        /* @0x1f4fb8 add r3, r3, #12 */
        /* @0x1f4fbc cmp r3, r2 */
        /* @0x1f4fc0 bne 0x1f4fb4 */
        for (uint32_t k = 0; k < (uint32_t)map->cap; k++)
            block[k].hash = 0;          /* memset already did; the body redoes */
    }

    /* ── rehash the old table through the non-inlined Insert ─────────────────
     * Only hash > 0 entries are reinserted; the loop bound is the OLD cap. */
    /* @0x1f4fc4 cmp r10, #0 */
    if (oldcap > 0) {
        /* @0x1f4fc8 movgt r4, r9 */
        /* @0x1f4fcc movgt r5, #0 */
        for (i = 0; i < oldcap; i++) {
            /* @0x1f4fd4 ldr r3, [r4, #0x8] */
            /* @0x1f4fd8 mov r0, r8 */
            /* @0x1f4fdc add r5, r5, #1 */
            /* @0x1f4fe0 cmp r3, #0 */
            /* @0x1f4fe4 ble 0x1f4ff0 */
            if ((int32_t)oldentries[i].hash <= 0)
                continue;
            /* @0x1f4fe8 ldm r4, {r1, r2} */
            /* @0x1f4fec bl 0xd261c */
            CHashMap_Insert(map, oldentries[i].key, oldentries[i].value);
            /* @0x1f4ff0 cmp r5, r10 */
            /* @0x1f4ff4 add r4, r4, #12 */
            /* @0x1f4ff8 bne 0x1f4fd4 */
        }
    }
    /* @0x1f4fd0 ble 0x1f4ffc */
    /* @0x1f4ffc mov r0, r9 */
    /* @0x1f5000 bl 0x27c2d0 */
    MemoryManager_Free(oldentries);
    /* @0x1f5004 vldr s13, [r8] */
    /* @0x1f5008 vcvt.f32.s32 s14, s13 */
    /* @0x1f500c vldr s15, [pc, #36] */
    /* @0x1f5010 ldr r2, [r8, #0x4] */
    /* @0x1f5014 vmul.f32 s15, s14, s15 */
    /* @0x1f5018 vcvt.s32.f32 s15, s15 */
    /* @0x1f501c vstr s15, [r8, #12] */
    /* the rehash moved map->count, so the threshold is recomputed once more */
    map->threshold = (int32_t)(VM_MAP_LOAD_FACTOR * (float)map->cap);
    /* @0x1f5020 b 0x1f4e48 */
    mcount = map->count;        /* 0x1f5010 reloads it before the `b` */
    goto insert;
}

/* Literal pool (6 words).  0x1f5038 is the float, the rest are pc-relative
 * offsets that llvm-objdump can only decode as instructions: */
/* @0x1f5038 .word 0x3f19999a */
/* 0.6f, loaded by both vldr sites (0x1f4f80 and 0x1f500c) */
/* @0x1f503c .word 0x001f8e84 */
/* 0x1f4db8 + 0x1f8e84 = 0x003edc3c builtin_numb */
/* @0x1f5040 .word 0x001f8e60 */
/* 0x1f4de0 + 0x1f8e60 = 0x003edc40 builtin_variables */
/* @0x1f5044 .word 0x001fc014 */
/* 0x1f4e20 + 0x1fc014 = 0x003f0e34 g_builtinVarLookup */
/* @0x1f5048 .word 0x0013c0e4 */
/* 0x1f4f54 + 0x13c0e4 = 0x00331038 "jni/../jni/yoyo/../../../Platform/MemoryManager.h" */
/* @0x1f504c .word 0x0015d824 */
/* 0x1f5030 + 0x15d824 = 0x00352854 "INTERNAL ERROR: Adding too many variables" */
