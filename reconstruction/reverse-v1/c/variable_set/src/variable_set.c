/*
 * variable_set.c — static C translation of
 * _Z17Variable_SetValueiiiP6RValue @0x1f4348 in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Every instruction of the body appears below exactly once, in address order,
 * with its verbatim llvm-objdump operand text:
 *
 *   llvm-objdump -d --start-address=0x1f4348 --stop-address=0x1f476c \
 *       -M reg-names-std <libyoyo_armv7.so>
 *
 * Register roles after the prologue: r4 = sel, r8 = var, r7 = index,
 * r6 = value, r10 = return accumulator, r12 = "at least one Direct" flag.
 * r9 is the PIC anchor (0x3f1c58) until the C1 loop spills it to [sp+4]; the
 * two fallback-container loops rotate r6/r7/r9/r10 around the same registers,
 * which is why the C1 pass parks the return value in r0 and the C2 pass does
 * the same: the accumulator really is r0 inside those loops, not r10.
 *
 * What this body does NOT do (the differential keeps all three true):
 *   * no RValue byte is read or written, no tag is looked at, no FREE_RValue
 *     is called - all four `str` instructions store to its own 12-byte frame;
 *   * sel < 0 (and != -3) returns 0 without a message and without touching
 *     any global;
 *   * the S5 (sel > 99999) path checks only byte +0x68, while S1/S2/C1/C2
 *     check +0x68 *and* +0x69.
 *
 * The return value is "did anyone take this write", not "did the write
 * succeed": every exit that dispatched at least one instance returns the LAST
 * Variable_SetValue_Direct return value (r10), and S5 returns Direct's value
 * straight through the tail jump (0x1f4708).
 */
#include "variable_set.h"

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

int Variable_SetValue(int sel, int var, int index, void *value)
{
    unsigned char *obj = 0;   /* [sp]: the CObjectGM S2 found (name source)  */
    int ret = 0;              /* r10 : last Direct return / 0                */
    int hit = 0;              /* r12 : at least one Direct was issued        */

    /* 0x1f4348 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
    /* 0x1f434c cmn  r0, #3            -- Z iff sel == -3 */
    /* 0x1f4350 ldr  r9, [pc, #0x3ec]  -- pool @0x1f4744 = 0x001fd8e8 */
    /* 0x1f4354 sub  sp, sp, #12       -- [sp] obj, [sp+4] spill only */
    /* 0x1f4358 mov  r4, r0            -- r4 = sel */
    /* 0x1f435c mov  r8, r1            -- r8 = var */
    /* 0x1f4360 mov  r7, r2            -- r7 = index */
    /* 0x1f4364 mov  r6, r3            -- r6 = value */
    /* 0x1f4368 add  r9, pc, r9        -- r9 = 0x1f4370 + 0x1fd8e8 = 0x3f1c58 */
    /* 0x1f436c beq  0x1f4600          -- sel == -3 -> S1 */
    if (sel == SEL_ALL_ACTIVE)
        goto S1;

    /* 0x1f4370 cmp  r0, #0 */
    /* 0x1f4374 blt  0x1f4684          -- sel < 0 (E1): return 0, no message */
    if (sel < 0)
        goto RET_ZERO;

    /* 0x1f4378 movw r3, #0x869f */
    /* 0x1f437c movt r3, #0x1        -- r3 = 99999 */
    /* 0x1f4380 cmp  r0, r3 */
    /* 0x1f4384 bgt  0x1f46a0        -- sel > 99999 -> S5 */
    if (sel > SEL_INSTANCE_MAX)
        goto S5;

    /* ── S2 (0 <= sel <= 99999): object table -> CObjectGM -> instance chain */
    {
        /* 0x1f4388 ldr  r3, [pc, #0x3b8]      -- pool @0x1f4748 = 0xffffbfec */
        /* 0x1f438c ldr  r3, [r9, r3]          -- GOT 0x3edc44 -> &(.bss 0x542374) */
        /* 0x1f4390 ldr  r3, [r3]              -- *(0x542374): the {bucket,mask} table */
        var_hash_table *tbl = *(var_hash_table **)&g_setvalue_object_table;
        /* 0x1f4394 ldr  r2, [r3, #0x4]        -- mask */
        /* 0x1f4398 ldr  r3, [r3]              -- bucket array */
        /* 0x1f439c and  r2, r0, r2            -- bucket = sel & mask */
        /* 0x1f43a0 ldr  r3, [r3, r2, lsl #3]  -- 8 B/bucket, +0 = chain head */
        obj_key_node *n;

        n = *(obj_key_node **)(void *)((unsigned char *)tbl->buckets +
                                       ((u32)sel & tbl->mask) * BUCKET_STRIDE);
        /* 0x1f43a4 cmp  r3, #0 */
        /* 0x1f43a8 bne  0x1f43bc             -- non-empty bucket -> compare */
        if (n == 0)
            goto S2_EMPTY;                  /* 0x1f43ac b 0x1f4690 */

        for (;;) {
            /* 0x1f43bc ldr  r2, [r3, #0x8]    -- node key */
            /* 0x1f43c0 cmp  r4, r2 */
            /* 0x1f43c4 bne  0x1f43b0         -- key != sel -> next node */
            if (n->key == sel)
                break;
            /* 0x1f43b0 ldr  r3, [r3, #0x4]    -- node next */
            n = n->next;
            /* 0x1f43b4 cmp  r3, #0 */
            /* 0x1f43b8 beq  0x1f4690         -- chain ended without a hit */
            if (n == 0)
                goto S2_EMPTY;
        }

        /* 0x1f43c8 ldr  r3, [r3, #0xc]        -- node value = CObjectGM */
        /* 0x1f43cc cmp  r3, #0 */
        /* 0x1f43d0 str  r3, [sp]              -- [sp] = CObjectGM (name source) */
        obj = (unsigned char *)n->value;
        /* 0x1f43d4 beq  0x1f4694             -- value NULL -> r12 = r10 = 0 */
        if (obj == 0)
            goto S2_VALUE_NULL;

        /* 0x1f43d8 ldr  r3, [sp] */
        /* 0x1f43dc ldr  r5, [r3, #0xd0]       -- CObjectGM's instance-chain head */
        {
            inst_node *cn = *(inst_node **)(void *)(obj + YYB_INST_CHAIN);
            /* 0x1f43e0 cmp  r5, #0 */
            /* 0x1f43e4 beq  0x1f4738         -- no instance chain at all */
            if (cn == 0)
                goto S2_NO_CHAIN;
            /* 0x1f43e8 ldr  r12, [r5, #0x8]   -- first node's instance */
            /* 0x1f43ec cmp  r12, #0 */
            /* 0x1f43f0 moveq r10, r12 */
            /* 0x1f43f4 beq  0x1f4450         -- first node empty -> S3 */
            if (cn->inst == 0) {
                ret = 0;
                goto S3;
            }
            /* 0x1f43f8 mov  r12, #0 */
            hit = 0;
            /* 0x1f43fc mov  r10, r12 */
            ret = hit;
            /* 0x1f4400 b    0x1f4410 */
            for (;;) {
                /* 0x1f4410 ldr  r0, [r5, #0x8] -- this node's instance */
                unsigned char *cur = (unsigned char *)cn->inst;
                /* 0x1f4414 ldr  r5, [r5]       -- advance BEFORE the callback */
                cn = cn->next;
                /* 0x1f4418 ldrb r3, [r0, #0x68] */
                /* 0x1f441c cmp  r3, #0 */
                /* 0x1f4420 bne  0x1f4448        -- destroyed -> skip */
                if (rd8(cur + YYB_DESTROYED) == 0) {
                    /* 0x1f4424 ldrb r11, [r0, #0x69] */
                    /* 0x1f4428 mov  r1, r8 */
                    /* 0x1f442c mov  r2, r7 */
                    /* 0x1f4430 mov  r3, r6 */
                    /* 0x1f4434 cmp  r11, #0 */
                    /* 0x1f4438 bne  0x1f4448        -- deactivated -> skip */
                    if (rd8(cur + YYB_DEACT) == 0) {
                        /* 0x1f443c bl   0x1f3c28    -- Direct(inst, var, index, value) */
                        ret = Variable_SetValue_Direct(cur, var, index, value);
                        /* 0x1f4440 mov  r12, #1 */
                        hit = 1;
                        /* 0x1f4444 mov  r10, r0 */
                    }
                }
                /* 0x1f4448 cmp  r5, #0 */
                /* 0x1f444c bne  0x1f4404 */
                if (cn == 0)
                    break;
                /* 0x1f4404 ldr  r3, [r5, #0x8] */
                /* 0x1f4408 cmp  r3, #0 */
                /* 0x1f440c beq  0x1f4450        -- next node has no instance -> S3 */
                if (cn->inst == 0)
                    break;
            }
        }
    }

    /* ── S3 (0x1f4450): fallback container C1 — runs whatever S2 did ─────── */
S3:
    {
        /* 0x1f4450 ldr  r3, [pc, #0x2f4]      -- pool @0x1f474c = 0xffffbff0 */
        /* 0x1f4454 ldr  r11, [r9, r3]         -- GOT 0x3edc48 -> &(.bss 0x542a64) */
        var_container *c1 = &g_setvalue_container_c1;
        /* 0x1f4458 ldr  r3, [r11, #0x8]       -- element count */
        /* 0x1f445c cmp  r3, #0 */
        /* 0x1f4460 ble  0x1f4514              -- count <= 0 (signed) -> skip C1 */
        if (c1->count > 0) {
            /* 0x1f4464 mov  r5, #0 */
            int32_t i = 0;                    /* r6 */
            /* 0x1f4468 mov  r0, r10 */
            int acc = ret;                    /* r0: accumulator inside the loops */
            /* 0x1f446c str  r9, [sp, #0x4] */
            /* 0x1f4470 mov  r10, r6 */
            /* 0x1f4474 mov  r9, r7 */
            /* 0x1f4478 mov  r1, r12 */
            int flag = hit;                   /* r1: hit flag moves to r1 here */
            /* 0x1f447c mov  r6, r5 */
            /* 0x1f4480 mov  r7, r11 */
            for (;;) {
                /* 0x1f4484 ldr  r3, [r7] */
                unsigned char *items = (unsigned char *)c1->items;
                /* 0x1f4488 ldr  r2, [r3, r6, lsl #2] */
                unsigned char *x = *(unsigned char **)(void *)
                    (items + (u32)i * ITEM_STRIDE);
                /* 0x1f448c ldr  r5, [r2, #0x80] */
                unsigned char *cn = *(unsigned char **)(void *)(x + YYB_ACTIVE_CHAIN);
                /* 0x1f4490 cmp  r5, #0 */
                /* 0x1f4494 beq  0x1f44f0              -- element has no chain */
                if (cn != 0) {
                    int32_t ckey = 0;
                    u32 eq = 0;
                    for (;;) {
                        /* 0x1f4498 ldr  r12, [r5, #0x18] */
                        ckey = (int32_t)rd32(cn + KE_KEY);
                        /* 0x1f449c ldr  r5, [r5, #0x48] */
                        cn = (unsigned char *)(uintptr_t)rd32(cn + KE_NEXT);
                        /* 0x1f44a0 subs r11, r4, r12 */
                        /* 0x1f44a4 rsbs r3, r11, #0 */
                        /* 0x1f44a8 adcs r3, r3, r11 */
                        eq = (sel == ckey) ? 1u : 0u;   /* r3: 1 iff sel-key==0 */
                        /* 0x1f44ac cmp  r4, r12 */
                        /* 0x1f44b0 cmpne r5, #0 */
                        /* 0x1f44b4 bne  0x1f4498             -- keep walking */
                        if (!(sel != ckey && cn != 0))
                            break;
                    }
                    /* 0x1f44b8 cmp  r3, #0 */
                    /* 0x1f44bc beq  0x1f44f0              -- no key hit */
                    if (eq != 0) {
                        /* 0x1f44c0 ldrb r3, [r2, #0x68] */
                        /* 0x1f44c4 cmp  r3, #0 */
                        /* 0x1f44c8 bne  0x1f44f0          -- destroyed */
                        if (rd8(x + YYB_DESTROYED) == 0) {
                            /* 0x1f44cc ldrb r3, [r2, #0x69] */
                            /* 0x1f44d0 cmp  r3, #0 */
                            /* 0x1f44d4 bne  0x1f44f0      -- deactivated */
                            if (rd8(x + YYB_DEACT) == 0) {
                                /* 0x1f44d8 mov  r0, r2 */
                                /* 0x1f44dc mov  r1, r8 */
                                /* 0x1f44e0 mov  r2, r9 */
                                /* 0x1f44e4 mov  r3, r10 */
                                /* 0x1f44e8 bl   0x1f3c28 */
                                acc = Variable_SetValue_Direct(x, var, index, value);
                                /* 0x1f44ec mov  r1, #1 */
                                flag = 1;
                            }
                        }
                    }
                }
                /* 0x1f44f0 ldr  r3, [r7, #0x8]           -- count re-read each pass */
                /* 0x1f44f4 add  r6, r6, #1 */
                i++;
                /* 0x1f44f8 cmp  r3, r6 */
                /* 0x1f44fc bgt  0x1f4484                  -- signed: count > i */
                if (!(c1->count > i))
                    break;
            }
            /* 0x1f4500 mov  r7, r9 */
            /* 0x1f4504 ldr  r9, [sp, #0x4] */
            /* 0x1f4508 mov  r6, r10 */
            /* 0x1f450c mov  r12, r1 */
            hit = flag;
            /* 0x1f4510 mov  r10, r0 */
            ret = acc;
        }
    }

    /* ── S4 (0x1f4514): fallback container C2 — same shape, second pass ──── */
    {
        /* 0x1f4514 ldr  r3, [pc, #0x234]      -- pool @0x1f4750 = 0xffffbff8 */
        /* 0x1f4518 ldr  r9, [r9, r3]          -- GOT 0x3edc50 -> &(.bss 0x542a4c) */
        var_container *c2 = &g_setvalue_container_c2;
        /* 0x1f451c ldr  r3, [r9, #0x8]        -- element count */
        /* 0x1f4520 cmp  r3, #0 */
        /* 0x1f4524 ble  0x1f45cc              -- count <= 0 -> skip C2 */
        if (c2->count > 0) {
            /* 0x1f4528 mov  r5, #0 */
            int32_t j = 0;                    /* r7 */
            /* 0x1f452c mov  r0, r10 */
            int acc = ret;
            /* 0x1f4530 str  r8, [sp, #0x4]     -- var spilled, not the anchor */
            /* 0x1f4534 mov  r2, r12 */
            int flag = hit;                   /* r2: hit flag moves to r2 here */
            /* 0x1f4538 mov  r8, r9             -- r8 = C2 */
            /* 0x1f453c mov  r10, r6            -- r10 = value */
            /* 0x1f4540 mov  r9, r7             -- r9 = index */
            /* 0x1f4544 mov  r7, r5 */
            for (;;) {
                /* 0x1f4548 ldr  r3, [r8] */
                unsigned char *items = (unsigned char *)c2->items;
                /* 0x1f454c ldr  r3, [r3, r7, lsl #2] */
                unsigned char *x = *(unsigned char **)(void *)
                    (items + (u32)j * ITEM_STRIDE);
                /* 0x1f4550 ldr  r11, [r3, #0x80] */
                unsigned char *cn = *(unsigned char **)(void *)(x + YYB_ACTIVE_CHAIN);
                /* 0x1f4554 cmp  r11, #0 */
                /* 0x1f4558 beq  0x1f45b4             -- element has no chain */
                if (cn != 0) {
                    int32_t ckey = 0;
                    u32 eq = 0;
                    for (;;) {
                        /* 0x1f455c ldr  r5, [r11, #0x18] */
                        ckey = (int32_t)rd32(cn + KE_KEY);
                        /* 0x1f4560 ldr  r11, [r11, #0x48] */
                        cn = (unsigned char *)(uintptr_t)rd32(cn + KE_NEXT);
                        /* 0x1f4564 subs r1, r4, r5 */
                        /* 0x1f4568 rsbs r6, r1, #0 */
                        /* 0x1f456c adcs r6, r6, r1 */
                        eq = (sel == ckey) ? 1u : 0u;   /* r6: 1 iff sel-key==0 */
                        /* 0x1f4570 cmp  r4, r5 */
                        /* 0x1f4574 cmpne r11, #0 */
                        /* 0x1f4578 bne  0x1f455c */
                        if (!(sel != ckey && cn != 0))
                            break;
                    }
                    /* 0x1f457c cmp  r6, #0 */
                    /* 0x1f4580 beq  0x1f45b4             -- no key hit */
                    if (eq != 0) {
                        /* 0x1f4584 ldrb r1, [r3, #0x68] */
                        /* 0x1f4588 cmp  r1, #0 */
                        /* 0x1f458c bne  0x1f45b4         -- destroyed */
                        if (rd8(x + YYB_DESTROYED) == 0) {
                            /* 0x1f4590 ldrb r1, [r3, #0x69] */
                            /* 0x1f4594 cmp  r1, #0 */
                            /* 0x1f4598 bne  0x1f45b4     -- deactivated */
                            if (rd8(x + YYB_DEACT) == 0) {
                                /* 0x1f459c mov  r0, r3 */
                                /* 0x1f45a0 mov  r2, r9 */
                                /* 0x1f45a4 ldr  r1, [sp, #0x4] */
                                /* 0x1f45a8 mov  r3, r10 */
                                /* 0x1f45ac bl   0x1f3c28 */
                                acc = Variable_SetValue_Direct(x, var, index, value);
                                /* 0x1f45b0 mov  r2, #1 */
                                flag = 1;
                            }
                        }
                    }
                }
                /* 0x1f45b4 ldr  r3, [r8, #0x8] */
                /* 0x1f45b8 add  r7, r7, #1 */
                j++;
                /* 0x1f45bc cmp  r3, r7 */
                /* 0x1f45c0 bgt  0x1f4548 */
                if (!(c2->count > j))
                    break;
            }
            /* 0x1f45c4 mov  r10, r0 */
            ret = acc;
            /* 0x1f45c8 mov  r12, r2 */
            hit = flag;
        }
    }

    /* 0x1f45cc cmp  r12, #0 */
    /* 0x1f45d0 bne  0x1f4668           -- something was written -> return it */
    if (hit != 0)
        goto RET_ACC;

    /* E5: nothing was written at all; S2/S3/S4 empty (name in %s) */
    {
        const char *name;
        /* 0x1f45d4 ldr  r3, [sp] */
        /* 0x1f45d8 cmp  r3, #0 */
        /* 0x1f45dc beq  0x1f472c        -- no CObjectGM -> "(null)" */
        if (obj == 0)
            /* 0x1f472c ldr  r2, [pc, #0x34]   -- pool @0x1f4768 = 0x0015e0c0 */
            /* 0x1f4730 add  r2, pc, r2       -- 0x3527f8 "(null)" */
            /* 0x1f4734 b    0x1f45e4 */
            name = MSG_NULL;
        else
            /* 0x1f45e0 ldr  r2, [r3, #0x14]  -- *(CObjectGM+0x14) = object name */
            name = *(const char **)(void *)(obj + YYB_NAME);
        /* 0x1f45e4 ldr  r0, [pc, #0x168]  -- pool @0x1f4754 = 0x00140334 */
        /* 0x1f45e8 mov  r1, r4 */
        /* 0x1f45ec add  r0, pc, r0        -- 0x334928 (the '%d'/'%s' message) */
        /* 0x1f45f0 bl   0xd547c */
        YYError(MSG_NO_INSTANCE_NAME, sel, name);
    }
    /* 0x1f45f4 mov  r0, r10 */
    /* 0x1f45f8 add  sp, sp, #12 */
    /* 0x1f45fc pop  {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
    return ret;

    /* ── S1 (0x1f4600): sel == -3, walk the whole active-instance list ───── */
S1:
    {
        /* 0x1f4600 ldr  r3, [pc, #0x150]  -- pool @0x1f4758 = 0xffffbcd8 */
        /* 0x1f4604 ldr  r3, [r9, r3]      -- GOT 0x3ed930 -> &(.bss 0x54298c) */
        /* 0x1f4608 ldr  r3, [r3]          -- *(0x54298c) */
        /* 0x1f460c ldr  r0, [r3, #0x80]   -- active-instance chain head */
        unsigned char *cur =
            *(unsigned char **)(void *)((unsigned char *)g_setvalue_runtime +
                                        YYB_ACTIVE_CHAIN);
        /* 0x1f4610 cmp  r0, #0 */
        /* 0x1f4614 beq  0x1f470c          -- empty list */
        if (cur == 0) {
            ret = 0;                      /* 0x1f470c mov  r10, r0 */
            goto ERR_S1_NOHIT;
        }
        /* 0x1f4618 mov  r5, #0 */
        int found = 0;
        /* 0x1f461c mov  r10, r5 */
        ret = found;
        for (;;) {
            /* 0x1f4620 ldrb r12, [r0, #0x68] */
            unsigned bs = rd8(cur + YYB_DESTROYED);
            /* 0x1f4624 ldr  r4, [r0, #0x178] -- next fetched before the callback */
            unsigned char *nx = *(unsigned char **)(void *)(cur + YYB_NEXT);
            /* 0x1f4628 cmp  r12, #0 */
            /* 0x1f462c bne  0x1f4654         -- destroyed */
            if (bs == 0) {
                /* 0x1f4630 ldrb r12, [r0, #0x69] */
                unsigned bd = rd8(cur + YYB_DEACT);
                /* 0x1f4634 mov  r1, r8 */
                /* 0x1f4638 mov  r2, r7 */
                /* 0x1f463c mov  r3, r6 */
                /* 0x1f4640 cmp  r12, #0 */
                /* 0x1f4644 bne  0x1f4654     -- deactivated */
                if (bd == 0) {
                    /* 0x1f4648 bl   0x1f3c28 */
                    ret = Variable_SetValue_Direct(cur, var, index, value);
                    /* 0x1f464c mov  r5, #1 */
                    found = 1;
                    /* 0x1f4650 mov  r10, r0 */
                }
            }
            /* 0x1f4654 cmp  r4, #0 */
            /* 0x1f4658 mov  r0, r4 */
            /* 0x1f465c bne  0x1f4620 */
            if (nx == 0)
                break;
            cur = nx;
        }
        /* 0x1f4660 cmp  r5, #0 */
        /* 0x1f4664 beq  0x1f4710         -- nothing written -> message, -3 */
        if (found == 0)
            goto ERR_S1_NOHIT;
        /* 0x1f4668 mov  r0, r10 */
        goto RET_ACC;
    }

RET_ACC:
    /* 0x1f4668 mov  r0, r10 */
    /* 0x1f466c add  sp, sp, #12 */
    /* 0x1f4670 pop  {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
    return ret;

ERR_S5:                           /* 0x1f4674: S5 missed or +0x68 set */
    /* 0x1f4674 ldr  r0, [pc, #0xe0]  -- pool @0x1f475c = 0x0015e17c */
    /* 0x1f4678 mov  r1, r4 */
    /* 0x1f467c add  r0, pc, r0        -- 0x352800 */
    /* 0x1f4680 bl   0xd547c */
    YYError(MSG_NO_INSTANCE, sel);

RET_ZERO:
    /* 0x1f4684 mov  r0, #0 */
    /* 0x1f4688 add  sp, sp, #12 */
    /* 0x1f468c pop  {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
    return 0;

S2_EMPTY:                         /* 0x1f4690: S2 bucket empty / chain ended */
    /* 0x1f4690 str  r3, [sp]          -- r3 is the null bucket/next word */
    obj = 0;

S2_VALUE_NULL:                    /* 0x1f4694: S2 hit but the value was null */
    /* 0x1f4694 mov  r12, r3 */
    /* 0x1f4698 mov  r10, r3 */
    /* 0x1f469c b    0x1f4450 */
    hit = 0;
    ret = 0;
    goto S3;

    /* ── S5 (0x1f46a0): sel > 99999, instance table -> tail call ─────────── */
S5:
    {
        /* 0x1f46a0 ldr  r3, [pc, #0xb8]     -- pool @0x1f4760 = 0xffffbff4 */
        /* 0x1f46a4 ldr  r3, [r9, r3]         -- GOT 0x3edc4c -> &(.bss 0x536f28) */
        /* 0x1f46a8 ldr  r2, [r3, #0x4]       -- mask: the cell IS the table here */
        /* 0x1f46ac ldr  r3, [r3]             -- bucket array */
        /* 0x1f46b0 and  r2, r0, r2 */
        /* 0x1f46b4 ldr  r3, [r3, r2, lsl #3] */
        obj_key_node *n;

        n = *(obj_key_node **)(void *)((unsigned char *)g_setvalue_inst_table.buckets +
                                       ((u32)sel & g_setvalue_inst_table.mask) *
                                       BUCKET_STRIDE);
        /* 0x1f46b8 cmp  r3, #0 */
        /* 0x1f46bc bne  0x1f46d0 */
        if (n == 0)
            goto ERR_S5;                 /* 0x1f46c0 b 0x1f4674 */

        for (;;) {
            /* 0x1f46d0 ldr  r2, [r3, #0x8] */
            /* 0x1f46d4 cmp  r4, r2 */
            /* 0x1f46d8 bne  0x1f46c4 */
            if (n->key == sel)
                break;
            /* 0x1f46c4 ldr  r3, [r3, #0x4] */
            n = n->next;
            /* 0x1f46c8 cmp  r3, #0 */
            /* 0x1f46cc beq  0x1f4674 */
            if (n == 0)
                goto ERR_S5;
        }

        /* 0x1f46dc ldr  r0, [r3, #0xc]        -- the single instance */
        {
            unsigned char *cur = (unsigned char *)n->value;
            /* 0x1f46e0 cmp  r0, #0 */
            /* 0x1f46e4 beq  0x1f4674 */
            if (cur == 0)
                goto ERR_S5;
            /* 0x1f46e8 ldrb r3, [r0, #0x68]   -- +0x69 is NOT checked on this path */
            /* 0x1f46ec cmp  r3, #0 */
            /* 0x1f46f0 bne  0x1f4674 */
            if (rd8(cur + YYB_DESTROYED) != 0)
                goto ERR_S5;
            /* 0x1f46f4 mov  r1, r8 */
            /* 0x1f46f8 mov  r2, r7 */
            /* 0x1f46fc mov  r3, r6 */
            /* 0x1f4700 add  sp, sp, #12 */
            /* 0x1f4704 pop  {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
            /* 0x1f4708 b    0x1f3c28       -- tail call, its r0 is our return value */
            return Variable_SetValue_Direct(cur, var, index, value);
        }
    }

ERR_S1_NOHIT:                     /* 0x1f470c/0x1f4710: sel == -3 wrote nothing */
    /* 0x1f470c mov  r10, r0          -- r0 == 0 when the list was empty */
    /* 0x1f4710 ldr  r0, [pc, #0x4c]  -- pool @0x1f4764 = 0x0015e0e0 */
    /* 0x1f4714 mvn  r1, #2           -- r1 = -3 */
    /* 0x1f4718 add  r0, pc, r0       -- 0x352800 */
    /* 0x1f471c bl   0xd547c */
    YYError(MSG_NO_INSTANCE, SEL_ALL_ACTIVE);
    /* 0x1f4720 mov  r0, r10 */
    /* 0x1f4724 add  sp, sp, #12 */
    /* 0x1f4728 pop  {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
    return ret;

S2_NO_CHAIN:                      /* 0x1f4738: CObjectGM has no instance chain */
    /* 0x1f4738 mov  r12, r5 */
    /* 0x1f473c mov  r10, r5 */
    /* 0x1f4740 b    0x1f4450 */
    hit = 0;
    ret = 0;
    goto S3;

    /* ── literal pool 0x1f4744..0x1f476c (never executed) ───────────────────
     * @0x1f4744 .word 0x001fd8e8            objdump: andseq sp, pc, r8, ror #17
     * @0x1f4748 .word 0xffffbfec            GOT 0x3edc44 (object table cell)
     * @0x1f474c .word 0xffffbff0            GOT 0x3edc48 (container C1)
     * @0x1f4750 .word 0xffffbff8            GOT 0x3edc50 (container C2)
     * @0x1f4754 .word 0x00140334            0x334928 (MSG_NO_INSTANCE_NAME)
     * @0x1f4758 .word 0xffffbcd8            GOT 0x3ed930 (runtime root cell)
     * @0x1f475c .word 0x0015e17c            0x352800 (MSG_NO_INSTANCE, E3)
     * @0x1f4760 .word 0xffffbff4            GOT 0x3edc4c (instance table cell)
     * @0x1f4764 .word 0x0015e0e0            0x352800 (MSG_NO_INSTANCE, E4)
     * @0x1f4768 .word 0x0015e0c0            0x3527f8 (MSG_NULL)
     */
}
