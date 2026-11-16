/*
 * variable_direct.h — the value-read dispatcher of libyoyo ARMv7.
 *
 * Entry: _Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue @0x1f3b8c
 *        (156 B / 0x1f3b8c..0x1f3c28, literal pool at 0x1f3c24)
 * Pinned image SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Signature: int Variable_GetValue_Direct(YYObjectBase* obj, int varid,
 *                                         int arrindex, RValue* out)
 *   r0 = obj      the resolved object (the resolver Variable_GetValue 0x1f3ce0
 *                 has already turned -3 / object index / instance id into this)
 *   r1 = varid    builtin variable number (0..9999) or variable id (>=10000)
 *   r2 = arrindex INT_MIN = scalar, anything else = array index (consumed by
 *                 GET_RValue only when the source slot is tag 2)
 *   r3 = out      destination RValue; this function never writes it directly
 *
 * Tier: bytecode_anchored (every instruction below cites its address).
 * The callees GET_RValue (0xd13bc), YYObjectBase::InternalGetYYVar (0x196a70)
 * and the builtin-variable table entry's fn are LIBRARY-INTERNAL and still
 * unrecovered, so this module declares them extern.  A differential arm that
 * stages identical stubs for them proves this body's dispatch, ordering and
 * slot arithmetic only - not those callees.
 */
#ifndef VARIABLE_DIRECT_H
#define VARIABLE_DIRECT_H

#include <stdint.h>

/* Offsets this body reads.  Nothing else about YYObjectBase is assumed. */
#define YYB_VAR_TABLE  0x04u   /* 0x1f3bb0 ldr r4,[r0,#0x4]  */
#define YYB_VAR_FLAG   0x24u   /* 0x1f3ba4 ldr r1,[r0,#0x24] */

/* Slot stride: 16 B per variable (0x1f3bc4 add r1,r4,r1,lsl #4) and 16 B per
 * builtin-variable table entry (0x1f3bf4 add r12,lr,r12,lsl #4). */
#define RV_SLOT_STRIDE 16

/* varid < 100000 is a builtin variable number; >= 100000 addresses a slot.
 * The two subtractions are 0x1f3bb4 sub r12,r12,#99328 (0x18400) and
 * 0x1f3bb8 sub r1,r12,#672 (0x2a0): 99328 + 672 = 100000. */
#define VARID_BUILTIN_MAX 0x270fu   /* 0x1f3b90 movw r1,#0x270f / 0x1f3b94 cmp */
#define VARID_SLOT_BASE   100000

/* Caller-side image: the GOT slot 0x3edc40 that holds the builtin-variable
 * table base.  0x1f3be4 ldr lr,[pc,#0x38] -> literal 0x1fa048 (0x1f3c24);
 * 0x1f3bf0 ldr lr,[pc,lr] with pc = 0x1f3bf8 resolves to 0x3edc40. */
extern void *const g_builtin_var_table_slot;

/* Builtin-variable table entry: fn lives at +4 (0x1f3bf8 ldr r3,[r12,#0x4]).
 * Called as fn(obj, arrindex, out) — r0 is left untouched, 0x1f3be8 moves
 * r1 = arrindex and 0x1f3bec moves r2 = out. */
typedef int (*bvar_getter)(void *obj, int arrindex, void *out);

typedef struct {
    const char *name;      /* +0 */
    bvar_getter fn;        /* +4 */
} bvar_entry;

/* Library-internal callees, unrecovered: declared extern on purpose. */
extern int GET_RValue(void *dst, void *src, int arrindex);
extern void *InternalGetYYVar(void *self, int slot);

int Variable_GetValue_Direct(void *obj, int varid, int arrindex, void *out);

#endif /* VARIABLE_DIRECT_H */
