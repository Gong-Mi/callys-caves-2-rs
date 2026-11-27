/*
 * find_slot_from_name.c — static C translation of
 * _Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc @0x000d21ec in
 * libyoyo ARMv7 (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Control flow, instruction by instruction (13 instructions, one literal pool
 * pair at 0x000d2220 / 0x000d2224):
 *
 *   0xd21ec ldr  r3,[pc,#0x2c]     literal 0x0031b9c4 = GOT offset
 *   0xd21f0 ldr  r3,[pc,r3]        -> GOT 0x3edbbc, whose cell holds 0x544be0
 *   0xd21f4 ldr  r3,[r3]           *g_varname_host
 *   0xd21f8 cmp  r3,r0             is this lookup for the global host object?
 *   0xd21fc mov  r0,r1             name becomes the only argument
 *   0xd2200 beq  0xd2208           host -> go look at the mode byte
 *   0xd2204 b    0xd1f74           else tail-jump the local (hash) name table
 *   0xd2208 ldr  r3,[pc,#0x14]     literal 0x0031b9ac = GOT offset
 *   0xd220c ldr  r3,[pc,r3]        -> GOT 0x3edbc0, whose cell holds 0x47f295
 *   0xd2210 ldrb r3,[r3]           the mode byte, read straight off the cell
 *   0xd2214 cmp  r3,#0
 *   0xd2218 bne  0xd2204           mode != 0 -> still the local table
 *   0xd221c b    0xd2054           mode == 0 -> tail-jump the global name table
 *
 * Three things this body does NOT do, and the differential arm must keep true:
 *   * it never touches `self`'s fields — the only thing it does with the object
 *     is compare its address against one global pointer, so no object layout is
 *     assumed anywhere in this translation;
 *   * it never looks at the name: `name` is only forwarded (0xd21fc).  No
 *     strlen, no empty-name special case, no NULL check — an empty or NULL name
 *     reaches the callee unchanged, and whether that is a hit or a miss is the
 *     callee's answer, not this body's;
 *   * it builds no frame and saves nothing: both exits are `b`, so the return
 *     value is the callee's return value verbatim, including a legal slot 0.
 *
 * Consequence worth pinning (byte-confirmed, and the reason this body has no
 * "lazy slot creation" arm): the function is a *dispatcher over two name
 * tables*.  The `table == 0 -> create the slot` path lives in
 * Variable_GetValue_Direct / YYObjectBase::InternalGetYYVar, one level down the
 * value-read line, and is covered by c/variable_direct/.  Nothing here creates
 * a slot.
 */
#include "variable_names.h"

int Code_Variable_Find_Slot_From_Name(void *self, const char *name)
{
    void *host;

    /* 0xd21ec: first word of the literal pool is the GOT *offset* 0x0031b9c4,
     * not an address; the pool is at 0x000d2220, i.e. past the end of the body. */
    /* @0xd21ec ldr r3, [pc, #0x2c] */
    /* @0xd21f0 ldr r3, [pc, r3] */
    /* 0xd21f4: the cell at 0x3edbbc holds 0x544be0, and this load is the extra
     * indirection — 0x544be0 is a pointer variable, the global host object. */
    /* @0xd21f4 ldr r3, [r3] */
    host = g_varname_host;

    /* @0xd21f8 cmp r3, r0 */
    /* @0xd2200 beq 0xd2208 */
    if (host != self) {
        /* 0xd21fc is where self dies: from here the only argument is the name,
         * which is exactly what both tail-jump targets take. */
        /* @0xd21fc mov r0, r1 */
        /* @0xd2204 b 0xd1f74 */
        return Code_Variable_Find_Slot_From_Local_Name(name);
    }

    /* @0xd2208 ldr r3, [pc, #0x14] */
    /* @0xd220c ldr r3, [pc, r3] */
    /* 0xd2210 is ldrb, not ldr: the GOT cell holds the byte's own address. */
    /* @0xd2210 ldrb r3, [r3] */
    /* @0xd2214 cmp r3, #0 */
    /* 0xd2218 bne, so a non-zero mode falls back to the LOCAL table: the global
     * namespace is only live while this switch is 0. */
    /* @0xd2218 bne 0xd2204 */
    if (g_varname_mode != 0)
        return Code_Variable_Find_Slot_From_Local_Name(name);

    /* @0xd221c b 0xd2054 */
    return Code_Variable_Find_Slot_From_Global_Name(name);
}

/* Literal pool of the body (0x000d2220 / 0x000d2224).  Both words are GOT
 * offsets added to a pc that is one instruction ahead, so llvm-objdump decodes
 * them as instructions (`eorseq r11, r1, r4, asr #19` and friends) — it cannot
 * tell data from code here.  The census gate documents them as words: */
/* @0xd2220 .word 0x0031b9c4 */
/* 0xd2220 + pc 0xd21f4 = 0x3edbbc -> .bss 0x544be0 (host pointer variable) */
/* @0xd2224 .word 0x0031b9ac */
/* 0xd2224 + pc 0xd2210 = 0x3edbc0 -> .bss 0x47f295 (the mode byte) */
