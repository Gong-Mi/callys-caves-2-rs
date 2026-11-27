/*
 * get_object_name.c — static C translation of _Z22Variable_GetObjectNameii
 * @0x001f3f8c in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * 71 instructions + 9 literal-pool words (0x001f40a8..0x001f40c8), seven
 * exits, four dispatch segments:
 *
 *   segment 1  entry + three compares           0x1f3f8c..0x1f3fac
 *   segment 2  instance id > 99999, ms_ID2InstanceE   0x1f3fb0..0x1f400c
 *   segment 3  id == -3, room instance chain    0x1f4010..0x1f4054
 *   segment 4  merge point: tail-jump Object_Name     0x1f4058
 *   segment 5  five "<unknown_object>" exits    0x1f405c..0x1f40a4
 *
 * What the body does, and what a differential must keep true:
 *
 *   * r1 (varid) is never read.  0x1f3f90 copies r0 to r2 and 0x1f3fb8
 *     overwrites r1 with the hash mask; nothing in between touches r1.  The
 *     translation keeps the parameter and marks it dead — the fixture drives
 *     it with different values over identical ids and requires identical
 *     records.
 *   * the id is copied to r2 because r0 has to survive as the return register
 *     for the `id <= 99999` path, where r0 is passed to Object_Name untouched.
 *   * only ONE of the five failure exits sets the failure byte 0x75505c: the
 *     `id == -3` / no live instance one, at 0x1f407c.  "flag set" therefore
 *     means "no instance in the room", not "this call failed".
 *   * the id > 99999 hash path checks +0x68 (destroyed) and NOT +0x69
 *     (deactivated) — the asymmetry with the room chain, which checks both.
 *     A deactivated instance still yields its object name through the hash.
 *   * the room chain loads the next pointer (0x1f403c) BEFORE testing whether
 *     the current instance is destroyed (0x1f4040); the order is preserved
 *     here because it is observable when the chain node sits at the end of a
 *     mapped page.
 *   * every failure exit returns the same rodata string, so the returned
 *     pointer is never NULL and never a stack buffer — the only success/failure
 *     signal besides content is that one byte.
 */
#include "variable_names.h"
#include <stddef.h>

typedef uint32_t u32;
typedef uint8_t u8;

static u32 rd32(const void *base, u32 off)
{
    u32 w;
    __builtin_memcpy(&w, (const u8 *)base + off, sizeof w);
    return w;
}

static u8 rdb(const void *base, u32 off)
{
    return ((const u8 *)base)[off];
}

const char *Variable_GetObjectName(int id, int varid)
{
    int idcopy;

    /* r1 (varid) is dead in this build: the first thing that happens to it is
     * 0x1f3fb8 overwriting it with the hash mask.  No instruction between
     * 0x1f3f8c and 0x1f3fb4 reads it. */
    (void)varid;

    /* 0x1f3f8c is `cmn r0,#3`: r0 + 3 == 0, i.e. id == -3 ("every instance"). */
    /* @0x1f3f8c cmn r0, #3 */
    /* @0x1f3f90 mov r2, r0 */
    /* @0x1f3f94 beq 0x1f4010 */
    idcopy = id;
    if (id == VN_ID_ALL)
        goto all_instances_branch;

    /* @0x1f3f98 cmp r0, #0 */
    /* 0x1f3f9c blt: any other negative id is "unknown", and this exit does NOT
     * set the failure byte (segment 5, 0x1f4084). */
    /* @0x1f3f9c blt 0x1f4084 */
    if (id < 0) {
        /* the "unknown" exit: three instructions and its own pool word, and
         * no store to 0x75505c anywhere in it */
        /* @0x1f4084 ldr r0, [pc, #0x34] */
        /* @0x1f4088 add r0, pc, r0 */
        /* @0x1f408c bx lr */
        return MSG_UNKNOWN_OBJECT;
    }

    /* @0x1f3fa0 movw r3, #0x869f */
    /* @0x1f3fa4 movt r3, #0x1 */
    /* @0x1f3fa8 cmp r0, r3 */
    /* 0x1f3fac ble: 0..99999 IS the object index — no table lookup at all, r0 is
     * never rewritten, so the tail jump gets the id itself. */
    /* @0x1f3fac ble 0x1f4058 */
    if (id <= VN_OBJINDEX_MAX) {
        /* r0 was never rewritten on this path, so the tail jump hands the id
         * itself to Object_Name.  0x1f4058 is documented at its first
         * occurrence (the hash path below) - it is one shared instruction. */
        return Object_Name(id);
    }

    /* ── 0x1f3fb0..0x1f400c: instance id -> ms_ID2InstanceE ─────────────── */
    {
        vn_hash_table *t = &g_objname_inst_table;
        vn_node *n;
        u32 bucket;

        /* The GOT cell (0x3edc4c) holds 0x536f28, which IS the table struct,
         * so one dereference reaches it and +0/+4 are bucket array and mask. */
        /* @0x1f3fb0 ldr r3, [pc, #0xf0] */
        /* @0x1f3fb4 ldr r3, [pc, r3] */
        /* @0x1f3fb8 ldr r1, [r3, #0x4] */
        /* @0x1f3fbc ldr r3, [r3] */
        /* @0x1f3fc0 and r1, r0, r1 */
        bucket = (u32)id & t->mask;
        /* 0x1f3fc4 scales by lsl #3: an 8-byte bucket whose +0 is the head. */
        /* @0x1f3fc4 ldr r3, [r3, r1, lsl #3] */
        n = *(vn_node **)(void *)((u8 *)t->buckets + (u32)bucket * VN_BUCKET_STRIDE);
        /* @0x1f3fc8 cmp r3, #0 */
        /* @0x1f3fcc bne 0x1f3fe0 */
        if (n == NULL) {
            /* 0x1f3fd0 jumps to the 0x1f4090 string exit */
            /* @0x1f3fd0 b 0x1f4090 */
            /* @0x1f4090 ldr r0, [pc, #0x2c] */
            /* @0x1f4094 add r0, pc, r0 */
            /* @0x1f4098 bx lr */
            return MSG_UNKNOWN_OBJECT;
        }

        for (;;) {
            const void *inst;

            /* The key compare uses the saved copy (r2), not r0: r0 must stay
             * untouched for the Object_Name call at 0x1f4058. */
            /* @0x1f3fe0 ldr r1, [r3, #0x8] */
            /* @0x1f3fe4 cmp r2, r1 */
            /* @0x1f3fe8 bne 0x1f3fd4 */
            if (idcopy != n->key) {
                /* @0x1f3fd4 ldr r3, [r3, #0x4] */
                n = n->next;
                /* @0x1f3fd8 cmp r3, #0 */
                /* @0x1f3fdc beq 0x1f405c */
                if (n == NULL) {
                    /* @0x1f405c ldr r0, [pc, #0x50] */
                    /* @0x1f4060 add r0, pc, r0 */
                    /* @0x1f4064 bx lr */
                    return MSG_UNKNOWN_OBJECT;
                }
                continue;
            }

            /* @0x1f3fec ldr r3, [r3, #0xc] */
            inst = n->value;
            /* @0x1f3ff0 cmp r3, #0 */
            /* @0x1f3ff4 beq 0x1f409c */
            if (inst == NULL) {
                /* @0x1f409c ldr r0, [pc, #0x24] */
                /* @0x1f40a0 add r0, pc, r0 */
                /* @0x1f40a4 bx lr */
                return MSG_UNKNOWN_OBJECT;
            }

            /* 0x1f3ff8 tests +0x68 ONLY.  +0x69 is not consulted on this path,
             * unlike the room chain below. */
            /* @0x1f3ff8 ldrb r2, [r3, #0x68] */
            /* @0x1f3ffc cmp r2, #0 */
            /* @0x1f4000 beq 0x1f4054 */
            if (rdb(inst, YYB_DESTROYED) != 0) {
                /* @0x1f4004 ldr r0, [pc, #0xa0] */
                /* @0x1f4008 add r0, pc, r0 */
                /* @0x1f400c bx lr */
                return MSG_UNKNOWN_OBJECT;          /* destroyed, no flag */
            }

            /* Shared merge point, documented in full at its first occurrence
             * in address order: the load of the object index, then the tail
             * jump both live paths end at. */
            /* @0x1f4054 ldr r0, [r3, #0x7c] */
            /* @0x1f4058 b 0x19ed54 */
            return Object_Name((int32_t)rd32(inst, YYB_OBJINDEX));
        }
    }

    /* ── 0x1f4010..0x1f4054: id == -3, first live instance of the room ──── */
all_instances_branch:
    {
        const u8 *cur;

        /* GOT 0x3ed930 holds 0x54298c, a POINTER variable (Run_Room), so this
         * is two loads before the field: [GOT] -> cell -> CRoom*, then +0x80. */
        /* @0x1f4010 ldr r3, [pc, #0x98] */
        /* @0x1f4014 ldr r3, [pc, r3] */
        /* @0x1f4018 ldr r3, [r3] */
        /* @0x1f401c ldr r3, [r3, #0x80] */
        cur = (const u8 *)(uintptr_t)rd32(g_run_room, ROOM_INST_CHAIN);
        /* @0x1f4020 cmp r3, #0 */
        /* @0x1f4024 bne 0x1f4038 */
        if (cur == NULL) {
            /* @0x1f4028 b 0x1f4068 */
            goto no_live_instance;
        }

        for (;;) {
            u8 destroyed, deact;
            const u8 *next;

            /* @0x1f4038 ldrb r1, [r3, #0x68] */
            destroyed = rdb(cur, YYB_DESTROYED);
            /* 0x1f403c loads next BEFORE 0x1f4040 tests destroyed: keep that
             * order, a lazy version would not fault where the original does. */
            /* @0x1f403c ldr r2, [r3, #0x178] */
            next = (const u8 *)(uintptr_t)rd32(cur, YYB_NEXT);
            /* @0x1f4040 cmp r1, #0 */
            /* @0x1f4044 bne 0x1f402c */
            if (destroyed == 0) {
                /* @0x1f4048 ldrb r1, [r3, #0x69] */
                deact = rdb(cur, YYB_DEACT);
                /* @0x1f404c cmp r1, #0 */
                /* @0x1f4050 bne 0x1f402c */
                if (deact == 0) {
                    /* 0x1f4054 / 0x1f4058 — the shared merge point, documented
                     * at its first occurrence (hash path) above. */
                    return Object_Name((int32_t)rd32(cur, YYB_OBJINDEX));
                }
            }

            /* @0x1f402c cmp r2, #0 */
            /* @0x1f4030 mov r3, r2 */
            /* @0x1f4034 beq 0x1f4068 */
            cur = next;
            if (cur == NULL)
                goto no_live_instance;
        }
    }

    /* ── segment 5: the failure exits that do NOT touch the flag ────────── */
    /* (0x1f405c / 0x1f4084 / 0x1f4090 / 0x1f409c are each three instructions:
     * ldr r0,[pc,#imm]; add r0,pc,r0; bx lr — every one of the five string
     * literals resolves to the same 0x3527e4.) */

no_live_instance:
    /* The only exit that sets 0x75505c.  0x1f4074 turns the GOT cell into the
     * address of the byte and 0x1f407c stores the 1 that 0x1f406c put in r2. */
    /* @0x1f4068 ldr r3, [pc, #0x48] */
    /* @0x1f406c mov r2, #1 */
    /* @0x1f4070 ldr r0, [pc, #0x44] */
    /* @0x1f4074 ldr r3, [pc, r3] */
    /* @0x1f4078 add r0, pc, r0 */
    /* @0x1f407c strb r2, [r3] */
    /* @0x1f4080 bx lr */
    g_objname_fail = 1;
    return MSG_UNKNOWN_OBJECT;
}

/* Literal pool of the body, 0x001f40a8..0x001f40c8 (9 words).  Three are GOT
 * offsets, six are rodata offsets; every one of the six string words resolves
 * to 0x3527e4 once its own pc (the address of the matching `add`, +8) is
 * added.  llvm-objdump decodes these as instructions because it cannot tell
 * data from code here — the census gate documents them as words. */
/* @0x1f40a8 .word 0x001f9c90 */
/* 0x1f40a8 + pc 0x1f3fbc = GOT 0x3edc4c, cell holds 0x536f28 (the table) */
/* @0x1f40ac .word 0x0015e7d4 */
/* 0x1f40ac + pc 0x1f4010 = 0x3527e4 (destroyed instance) */
/* @0x1f40b0 .word 0x001f9914 */
/* 0x1f40b0 + pc 0x1f401c = GOT 0x3ed930, cell holds 0x54298c (Run_Room) */
/* @0x1f40b4 .word 0x0015e77c */
/* 0x1f40b4 + pc 0x1f4068 = 0x3527e4 (hash chain end) */
/* @0x1f40b8 .word 0x001f9cec */
/* 0x1f40b8 + pc 0x1f407c = GOT 0x3edd68, cell holds 0x75505c (the flag) */
/* @0x1f40bc .word 0x0015e764 */
/* 0x1f40bc + pc 0x1f4080 = 0x3527e4 (no live instance) */
/* @0x1f40c0 .word 0x0015e754 */
/* 0x1f40c0 + pc 0x1f4090 = 0x3527e4 (negative id) */
/* @0x1f40c4 .word 0x0015e748 */
/* 0x1f40c4 + pc 0x1f409c = 0x3527e4 (empty bucket) */
/* @0x1f40c8 .word 0x0015e73c */
/* 0x1f40c8 + pc 0x1f40a8 = 0x3527e4 (node value NULL) */
