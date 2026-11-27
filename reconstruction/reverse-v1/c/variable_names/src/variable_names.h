/*
 * variable_names.h — the two variable-name-side functions of libyoyo ARMv7.
 *
 * Entries (pinned image SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a):
 *
 *   _Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc @0x000d21ec
 *       0x000d21ec..0x000d2228, 0x3c = 60 B: 13 instructions + 2 literal-pool
 *       words at 0x000d2220 / 0x000d2224.  No frame, no saved register, no
 *       stack: both exits are tail jumps (`b`, not `bl`), so the caller's LR is
 *       still live and this body's return value IS the callee's.
 *
 *       int Code_Variable_Find_Slot_From_Name(YYObjectBase *self,
 *                                             const char *name)
 *         r0 = self   the object the lookup is for
 *         r1 = name   the GML variable name (only the pointer is forwarded)
 *
 *       Returns a *slot number*, not a pointer.  0 is a legal slot; only -1
 *       means "absent" (YYObjectBase::FindValue tests it with `cmn r0,#1`,
 *       not `cmp r0,#0`).
 *
 *   _Z22Variable_GetObjectNameii @0x001f3f8c
 *       0x001f3f8c..0x001f40cc, 0x140 = 320 B: 71 instructions + 9 literal-pool
 *       words at 0x001f40a8..0x001f40c8.
 *
 *       const char *Variable_GetObjectName(int id, int varid)
 *         r0 = id     -3 = any live instance | 0..99999 = object index |
 *                     >99999 = instance id | any other negative = unknown
 *         r1 = varid  DEAD PARAMETER in this build: no instruction between
 *                     0x1f3f8c and 0x1f3fb4 reads r1, and 0x1f3fb8 overwrites
 *                     it with the hash mask.  Kept in the signature because
 *                     the seven call sites pass it.
 *
 *       Never returns NULL.  Success = Object_Name()'s answer; every failure
 *       exit returns the same rodata string "<unknown_object>" (0x3527e4).
 *       Only the `id == -3 && no live instance` exit sets the failure byte
 *       0x75505c; the other four set nothing.
 *
 * Tier: bytecode_anchored — every instruction of both translations carries its
 * address and the verbatim llvm-objdump operand text, and
 * harness/var_names_diff.py machine-checks that comment set against the pinned
 * bytes (census gate).
 *
 * Callee status: every callee of both bodies is LIBRARY-INTERNAL and still
 * unrecovered, so each is declared extern here and answered by an identical
 * stub on both differential arms:
 *   Code_Variable_Find_Slot_From_Local_Name  0x000d1f74  CHashMap<char const*,int>
 *   Code_Variable_Find_Slot_From_Global_Name 0x000d2054  linear strcmp over an array
 *   Object_Name                              0x0019ed54  object index -> name string
 * A green differential therefore proves these two bodies' dispatch, field
 * offsets, pointer normalisation and return plumbing — not those callees, and
 * not device equivalence.
 */
#ifndef VARIABLE_NAMES_H
#define VARIABLE_NAMES_H

#include <stdint.h>

/* ── Code_Variable_Find_Slot_From_Name: the two .bss globals ──────────────
 * Both are reached through the GOT with one extra indirection step each, and
 * the .text of the whole library contains no absolute literal for either, so
 * they can only be addressed this way:
 *
 *   0x000d21ec ldr r3, [pc, #0x2c]   literal 0x0031b9c4 (pool 0x000d2220)
 *   0x000d21f0 ldr r3, [pc, r3]      pc 0x000d21f4 + 0x31b9c4 = GOT 0x003edbbc
 *                                    -> .bss 0x00544be0, a POINTER variable
 *   0x000d21f4 ldr r3, [r3]          *g_varname_host, the global host object
 *
 *   0x000d2208 ldr r3, [pc, #0x14]   literal 0x0031b9ac (pool 0x000d2224)
 *   0x000d220c ldr r3, [pc, r3]      pc 0x000d2210 + 0x31b9ac = GOT 0x003edbc0
 *                                    -> .bss 0x0047f295, a BYTE switch
 *   0x000d2210 ldrb r3, [r3]         no second dereference: the GOT cell holds
 *                                    the address of the byte itself
 *
 * The two GOT slots are the only way into either global: 0x544be0 is read by
 * this body, F_VariableGlobalGet and F_VariableGlobalSet (all three reads) and
 * 0x47f295 is read by six ldrb sites and written nowhere in .text.
 */
extern void          *g_varname_host;   /* .bss 0x00544be0, pointer variable */
extern unsigned char  g_varname_mode;   /* .bss 0x0047f295, 1-byte switch  */

/* Dispatch targets — both unrecovered.  Only the name pointer is passed
 * (0x000d21fc mov r0, r1): self dies at the branch, which is also why the two
 * tables can have completely different shapes (hash map vs. linear scan). */
extern int Code_Variable_Find_Slot_From_Local_Name(const char *name);   /* 0x000d1f74 */
extern int Code_Variable_Find_Slot_From_Global_Name(const char *name);  /* 0x000d2054 */

int Code_Variable_Find_Slot_From_Name(void *self, const char *name);

/* ── Variable_GetObjectName: field offsets this body reads ────────────────
 * Nothing else about YYObjectBase / CObjectGM / CRoom is assumed.  The same
 * 0x68 / 0x69 / 0x178 triple is the one Variable_SetValue and Variable_GetValue
 * use, which is why the sibling arms can share a fixture shape. */
#define YYB_DESTROYED    0x68u   /* 0x1f3ff8 / 0x1f4038  ldrb r2, [r3, #0x68] */
#define YYB_DEACT        0x69u   /* 0x1f4048            ldrb r1, [r3, #0x69] */
#define YYB_OBJINDEX     0x7cu   /* 0x1f4054            ldr r0, [r3, #0x7c]    */
#define YYB_NEXT         0x178u  /* 0x1f403c            ldr r2, [r3, #0x178]   */
#define ROOM_INST_CHAIN  0x80u   /* 0x1f401c            ldr r3, [r3, #0x80]    */

/* ms_ID2InstanceE: the struct IS the .bss object (GOT 0x003edc4c holds
 * 0x00536f28), so one dereference reaches it — unlike the object table, which
 * is a pointer variable.  bucket stride 8 B = {head@0, tail@4}; only head is
 * ever read here. */
#define VN_HT_BUCKETS    0x0u    /* 0x1f3fbc ldr r3, [r3]                    */
#define VN_HT_MASK       0x4u    /* 0x1f3fb8 ldr r1, [r3, #0x4]              */
#define VN_BUCKET_STRIDE 8u      /* 0x1f3fc4 ldr r3, [r3, r1, lsl #3]        */

/* chain node: {+0 unread, +4 next, +8 id, +0xc instance} */
#define VN_N_NEXT        0x4u    /* 0x1f3fd4 ldr r3, [r3, #0x4]              */
#define VN_N_ID          0x8u    /* 0x1f3fe0 ldr r1, [r3, #0x8]              */
#define VN_N_INST        0xcu    /* 0x1f3fec ldr r3, [r3, #0xc]              */

/* id domain boundaries: 0x1f3f8c cmn r0,#3 (== -3) and
 * 0x1f3fa0 movw r3,#0x869f / 0x1f3fa4 movt r3,#0x1 (99999). */
#define VN_ID_ALL        (-3)
#define VN_OBJINDEX_MAX  99999

typedef struct {
    void    *buckets;            /* +0  ldr r3, [r3]      */
    uint32_t mask;               /* +4  ldr r1, [r3, #0x4] */
} vn_hash_table;

/* Four 4-byte fields, so +4/+8/+0xc are the offsets the original addresses.
 * Building this for a 64-bit host would move them and the test would stop
 * testing anything — that is why the claim arm is built for armv7a. */
typedef struct vn_node {
    void           *f0;          /* +0x0  never read by this body */
    struct vn_node *next;        /* +0x4  */
    int32_t         key;         /* +0x8  the instance id */
    void           *value;       /* +0xc  the instance */
} vn_node;

/* The three .bss globals, at the indirection depth the instructions have:
 *   0x1f3fb4 ldr r3,[pc,r3] -> 0x536f28 : the cell IS the instance table
 *   0x1f4014 ldr r3,[pc,r3] -> 0x54298c : the cell HOLDS a pointer (Run_Room)
 *   0x1f4074 ldr r3,[pc,r3] -> 0x75505c : the cell is the address of the byte
 */
extern vn_hash_table   g_objname_inst_table;  /* 0x00536f28, struct body      */
extern void           *g_run_room;            /* 0x0054298c, pointer variable */
extern unsigned char   g_objname_fail;        /* 0x0075505c, 1-byte flag      */

/* Callee, unrecovered: object index -> object name.  It has its own fallback
 * ("<undefined>" at 0x330ac8) which is OUTSIDE this body; the fixture stub
 * returns a name derived from the index so the index itself is observable. */
extern const char *Object_Name(int objindex);   /* 0x0019ed54 */

/* The one string every failure exit of Variable_GetObjectName returns:
 * rodata 0x3527e4, byte-identical to this literal (checked by the harness). */
#define MSG_UNKNOWN_OBJECT "<unknown_object>"

const char *Variable_GetObjectName(int id, int varid);

#endif /* VARIABLE_NAMES_H */
