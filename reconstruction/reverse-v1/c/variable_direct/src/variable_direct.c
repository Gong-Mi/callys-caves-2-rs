/*
 * variable_direct.c — static C translation of
 * _Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue @0x1f3b8c in
 * libyoyo ARMv7 (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Control flow, instruction by instruction (39 instructions, one literal pool
 * word at 0x1f3c24):
 *
 *   0x1f3b8c mov  r12,r1              varid -> r12
 *   0x1f3b90 movw r1,#0x270f
 *   0x1f3b94 cmp  r12,r1              9999
 *   0x1f3b98 push {r4,lr}
 *   0x1f3b9c sub  sp,sp,#8            (framing for the call paths)
 *   0x1f3ba0 bls  0x1f3be4            varid <= 9999 -> builtin variable path
 *   0x1f3ba4 ldr  r1,[r0,#0x24]       instance-level variable flag
 *   0x1f3ba8 cmp  r1,#0
 *   0x1f3bac beq  0x1f3bd8            flag == 0 -> return 0
 *   0x1f3bb0 ldr  r4,[r0,#0x4]        slot table base
 *   0x1f3bb4 sub  r12,r12,#99328      varid - 0x18400
 *   0x1f3bb8 sub  r1,r12,#672         ... - 0x2a0 = varid - 100000  (slot index)
 *   0x1f3bbc cmp  r4,#0
 *   0x1f3bc0 beq  0x1f3c08            table == 0 -> lazy slot creation
 *   0x1f3bc4 add  r1,r4,r1,lsl #4     slot address = base + index*16
 *   0x1f3bc8 mov  r0,r3               GET_RValue dst = out
 *   0x1f3bcc add  sp,sp,#8
 *   0x1f3bd0 pop  {r4,lr}
 *   0x1f3bd4 b    0xd13bc             tail call GET_RValue(out, slot, arrindex)
 *   0x1f3bd8 mov  r0,#0               return 0 (out untouched)
 *   0x1f3bdc add  sp,sp,#8
 *   0x1f3be0 pop  {r4,pc}
 *   0x1f3be4 ldr  lr,[pc,#0x38]       literal 0x1fa048
 *   0x1f3be8 mov  r1,r2               arg1 = arrindex
 *   0x1f3bec mov  r2,r3               arg2 = out
 *   0x1f3bf0 ldr  lr,[pc,lr]          GOT 0x3edc40 -> builtin table base
 *   0x1f3bf4 add  r12,lr,r12,lsl #4   entry = base + varid*16
 *   0x1f3bf8 ldr  r3,[r12,#0x4]       fn
 *   0x1f3bfc blx  r3                  fn(obj, arrindex, out)
 *   0x1f3c00 add  sp,sp,#8            (fn's r0 is the return value)
 *   0x1f3c04 pop  {r4,pc}
 *   0x1f3c08 str  r2,[sp,#0x4]        save arrindex
 *   0x1f3c0c str  r3,[sp]             save out
 *   0x1f3c10 bl   0x196a70            InternalGetYYVar(self, slot)
 *   0x1f3c14 ldr  r3,[sp]
 *   0x1f3c18 ldr  r2,[sp,#0x4]
 *   0x1f3c1c mov  r1,r0               slot address comes back in r0
 *   0x1f3c20 b    0x1f3bc8            -> GET_RValue(out, returned slot, arrindex)
 *   0x1f3c24 .word 0x001fa048         GOT addend
 *
 * Three things this body does NOT do, and the differential arm must keep true:
 *   * it never reads or writes the RValue payload itself;
 *   * on the flag==0 exit it returns 0 without touching `out`;
 *   * the lazy path (0x1f3c08) does NOT apply the base + index*16 arithmetic -
 *     InternalGetYYVar's r0 is used as the slot address verbatim.
 *
 * open (inherited from the variable family cards): varid in [10000, 99999] is
 * not rejected here either - varid - 100000 goes negative and the slot address
 * lands BELOW the table (0x1f3bc4 multiplies the negative index by 16). Whether
 * the name table can ever emit such an id is unproven; the case set below pins
 * the observed arithmetic so a later fix cannot silently change it.
 */
#include "variable_direct.h"

typedef uint32_t u32;

static u32 rd(const void *base, u32 off)
{
    const unsigned char *p = (const unsigned char *)base + off;
    u32 w;
    __builtin_memcpy(&w, p, sizeof w);
    return w;
}

int Variable_GetValue_Direct(void *obj, int varid, int arrindex, void *out)
{
    int v = varid;                                   /* 0x1f3b8c */
    void *table;

    /* 0x1f3b90..0x1f3ba0: signed compare against 0x270f, bls -> builtin path.
     * bls is unsigned; the original compares r12 against 0x270f with cmp and
     * takes bls, i.e. varid<=0x270f as UNSIGNED - a negative varid is huge and
     * therefore takes the slot path, it does not index the builtin table. */
    if ((u32)v <= (u32)VARID_BUILTIN_MAX) {
        void *base = (void *)(uintptr_t)rd(&g_builtin_var_table_slot, 0);  /* 0x1f3bf0/0x1f3bf8 */
        bvar_entry *entry = (bvar_entry *)((unsigned char *)base +
                                           (u32)v * RV_SLOT_STRIDE);  /* 0x1f3bf4 */
        return entry->fn(obj, arrindex, out);                    /* 0x1f3bf8..0x1f3bfc */
    }

    if (rd(obj, YYB_VAR_FLAG) == 0)                  /* 0x1f3ba4..0x1f3bac */
        return 0;                                    /* 0x1f3bd8 */

    table = (void *)(uintptr_t)rd(obj, YYB_VAR_TABLE);   /* 0x1f3bb0 */
    {
        int slot = v - VARID_SLOT_BASE;              /* 0x1f3bb4 + 0x1f3bb8 */
        void *src;

        if (table == 0) {                            /* 0x1f3bbc..0x1f3bc0 */
            src = InternalGetYYVar(obj, slot);       /* 0x1f3c08..0x1f3c1c */
        } else {
            src = (unsigned char *)table + (intptr_t)((int32_t)slot * RV_SLOT_STRIDE);
        }
        return GET_RValue(out, src, arrindex);       /* 0x1f3bc8..0x1f3bd4 */
    }
}
