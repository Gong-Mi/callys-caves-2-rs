/*
 * variable_set.h — the instance resolver + dispatcher of libyoyo ARMv7.
 *
 * Entry: _Z17Variable_SetValueiiiP6RValue @0x1f4348
 *        (0x1f4348..0x1f476c, 265 words: 255 reachable instructions + 10 pool
 *         words, no jump table, 12-byte frame)
 * Pinned image SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Signature: int Variable_SetValue(int sel, int var, int index, void *value)
 *   r0 = sel    which instances this write is for: -3 = every active instance,
 *               0..99999 = object index, >99999 = instance id, any other
 *               negative = "nobody" (return 0, no message)
 *   r1 = var    passed through to Variable_SetValue_Direct untouched
 *   r2 = index  passed through untouched
 *   r3 = value  passed through untouched; this body never reads or writes it
 *
 * The body resolves a *set of instances* and calls
 * Variable_SetValue_Direct(obj, var, index, value) once per live instance.
 * It never touches an RValue payload, never calls FREE_RValue__Pre and never
 * reads a tag (all four `str` instructions land in its own 12-byte frame).
 *
 * Tier: bytecode_anchored — every instruction of the translation cites the
 * address and the verbatim llvm-objdump operand text.
 *
 * Callee status: Variable_SetValue_Direct (0x1f3c28) and YYError (0xd547c) are
 * LIBRARY-INTERNAL and not recovered, so they are declared extern here and
 * answered by an identical stub on both differential arms.  A green
 * differential proves THIS body's dispatch, ordering, field offsets and return
 * plumbing only — not those callees, and not device equivalence.
 */
#ifndef VARIABLE_SET_H
#define VARIABLE_SET_H

#include <stdint.h>

/* ── field offsets this body reads (nothing else about the objects is assumed) */
#define YYB_NAME        0x14u   /* 0x1f45e0 ldr  r2, [r3, #0x14]   object name     */
#define YYB_DESTROYED   0x68u   /* 0x1f4418 ldrb r3, [r0, #0x68]                    */
#define YYB_DEACT       0x69u   /* 0x1f4424 ldrb r11, [r0, #0x69]                   */
#define YYB_ACTIVE_CHAIN 0x80u  /* 0x1f448c ldr  r5, [r2, #0x80] / 0x1f460c         */
#define YYB_INST_CHAIN  0xD0u   /* 0x1f43dc ldr  r5, [r3, #0xd0]  CObjectGM chain   */
#define YYB_NEXT        0x178u  /* 0x1f4624 ldr  r4, [r0, #0x178] active-list next  */

/* ── the two hash tables */
#define HT_BUCKETS      0x0u    /* 0x1f4398/0x1f43ac and 0x1f46ac                   */
#define HT_MASK         0x4u    /* 0x1f4394 and 0x1f46a8                            */
#define BUCKET_STRIDE   8u      /* 0x1f43a0 ldr r3, [r3, r2, lsl #3]  (and 1f46b4)  */

/* object table node: {+4 next, +8 key, +0xc value}; +0 is never read here */
#define ON_NEXT         0x4u    /* 0x1f43b0 / 0x1f46c4                              */
#define ON_KEY          0x8u    /* 0x1f43bc / 0x1f46d0                              */
#define ON_VALUE        0xCu    /* 0x1f43c8 (CObjectGM) / 0x1f46dc (instance)       */

/* instance-chain node hanging off CObjectGM+0xd0: {+0 next, +8 instance} */
#define IC_NEXT         0x0u    /* 0x1f4414 ldr r5, [r5]                            */
#define IC_INST         0x8u    /* 0x1f4410 ldr r0, [r5, #0x8]                      */

/* fallback-container element chain node: {+0x18 key, +0x48 next} */
#define KE_KEY          0x18u   /* 0x1f4498 / 0x1f455c                              */
#define KE_NEXT         0x48u   /* 0x1f449c / 0x1f4560                              */

/* container {+0 pointer array, +4 (unread), +8 count} */
#define CT_ITEMS        0x0u    /* 0x1f4484 / 0x1f4548                              */
#define CT_COUNT        0x8u    /* 0x1f4458 / 0x1f451c                              */
#define ITEM_STRIDE     4u      /* 0x1f4488 ldr r2, [r3, r6, lsl #2]                */

/* sel boundaries: 0x1f4378 movw r3,#0x869f / 0x1f437c movt r3,#0x1 */
#define SEL_INSTANCE_MAX 99999
#define SEL_ALL_ACTIVE   (-3)

typedef struct {
    void    *buckets;            /* +0 */
    uint32_t mask;               /* +4 */
} var_hash_table;

typedef struct {
    void   *items;               /* +0 */
    uint32_t pad;                /* +4: never read by this body */
    int32_t  count;              /* +8 */
} var_container;

/* Object/instance-table node.  +0 is never read by this body (0x1f43c8 takes
 * +0xc, 0x1f46dc takes +0xc); the pad keeps the four fields 4 B apart on
 * ARMv7, which is the whole point of building the claim arm for the target. */
typedef struct obj_key_node {
    void                 *f0;    /* +0x0  unread */
    struct obj_key_node  *next;  /* +0x4 */
    int32_t               key;   /* +0x8 */
    void                 *value; /* +0xc  CObjectGM (S2) / instance (S5) */
} obj_key_node;

/* Instance-chain node hanging off CObjectGM+0xd0: {+0 next, +8 instance}. */
typedef struct inst_node {
    struct inst_node *next;      /* +0x0 (0x1f4414) */
    uint32_t          pad;       /* +0x4 unread */
    void             *inst;      /* +0x8 (0x1f4410) */
} inst_node;

/* The five GOT slots this body goes through.  They are modelled as the .bss
 * objects they relocate to, with the *indirection depth* the instruction
 * sequence actually has:
 *   GOT 0x3edc44 -> .bss 0x542374 : the cell HOLDS a pointer to the object
 *                                   table      (0x1f438c ldr then 0x1f4390 ldr)
 *   GOT 0x3edc4c -> .bss 0x536f28 : the cell IS the instance table
 *                                   (0x1f46a4 ldr then 0x1f46a8/0x1f46ac)
 *   GOT 0x3edc48 -> .bss 0x542a64 : the cell IS container C1
 *   GOT 0x3edc50 -> .bss 0x542a4c : the cell IS container C2
 *   GOT 0x3ed930 -> .bss 0x54298c : the cell HOLDS a pointer to the runtime
 *                                   object whose +0x80 is the active list
 *                                   (0x1f4604 ldr then 0x1f4608 ldr)
 */
extern void          *g_setvalue_object_table;   /* *(0x542374) */
extern var_hash_table g_setvalue_inst_table;     /*  0x536f28   */
extern var_container  g_setvalue_container_c1;   /*  0x542a64   */
extern var_container  g_setvalue_container_c2;   /*  0x542a4c   */
extern void          *g_setvalue_runtime;        /* *(0x54298c) */

/* Library-internal callees, unrecovered: extern on purpose. */
extern int Variable_SetValue_Direct(void *obj, int var, int index, void *value);
extern int YYError(const char *fmt, ...);

/* The three message strings, byte-identical to the rodata this body passes:
 *   0x334928  MSG_NO_INSTANCE_NAME
 *   0x352800  MSG_NO_INSTANCE        (E3 and E4 share it)
 *   0x3527f8  MSG_NULL               (the "%s" argument when the object is null)
 */
#define MSG_NO_INSTANCE_NAME \
    "Unable to find any instance for object index '%d' name '%s'"
#define MSG_NO_INSTANCE \
    "Unable to find any instance for object index '%d'"
#define MSG_NULL "(null)"

int Variable_SetValue(int sel, int var, int index, void *value);

#endif /* VARIABLE_SET_H */
