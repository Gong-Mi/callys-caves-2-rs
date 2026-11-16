/*
 * find_name.c — static C translation of
 * _Z23Code_Variable_Find_NamePKcii @0x000d25fc in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Seven instructions, 28 bytes, no literal pool, no frame, no saved register.
 * Both exits are `b` (tail jumps, not `bl`), so this body's return value is its
 * callee's return value and its own frame is whatever its caller had.
 *
 *   0xd25fc movw r3, #0x869f    \  r3 = 0x0001869f = 99999, assembled from two
 *   0xd2600 movt r3, #0x1       /  halves because the constant does not fit
 *                                  in a 16-bit immediate
 *   0xd2604 cmp  r2, r3           the THIRD parameter (id) is the only key
 *   0xd2608 bgt  0xd2614          signed ">": id > 99999, i.e. id >= 100000
 *   0xd260c mov  r0, r2           built-in path: the id becomes the first and
 *                                 only argument; name and type die here
 *   0xd2610 b    0x1f3b38         tail-jump Variable_BuiltIn_Find_Name(int)
 *   0xd2614 b    0xd2228          tail-jump Variable_GetName_Scope(name,type,id)
 *
 * The comparison is SIGNED (bgt, not bhi): every id >= 0x80000000 — and every
 * ordinary negative id — takes the built-in branch, which is the branch that
 * throws `name` away.  An unsigned rewrite of this one instruction changes
 * behaviour on exactly those inputs; the differential carries them.
 *
 * 99999 = 100000 - 1 and the same 100000 reappears, independently, in the
 * callee Variable_GetName_Scope (sub r7, r2, #99328; subs r7, r7, #672) and in
 * DoPopLocalVariable below (sub r6, r6, #99328; sub r1, r6, #672).  Three
 * separate sites, one constant: the variable-id base.
 *
 * This body touches no global memory and no rodata: it references nothing but
 * its own registers, so there is no GOT chain to stage for it.
 */
#include "variable_ops.h"

const char *Code_Variable_Find_Name(const char *name, int type, int id)
{
    /* @0xd25fc movw r3, #0x869f */
    /* @0xd2600 movt r3, #0x1 */
    /* @0xd2604 cmp r2, r3 */
    /* 0xd2608 bgt is signed, and 0xd2614 is the only way into the scope path. */
    /* @0xd2608 bgt 0xd2614 */
    if (id > VARID_BUILTIN_MAX)
        /* 0xd2614: all three registers are still live here — the scope lookup
         * is the only branch that ever sees `name` and `type`. */
        /* @0xd2614 b 0xd2228 */
        return Variable_GetName_Scope(name, type, id);

    /* 0xd260c overwrites the first parameter with the id: on this branch
     * `name` and `type` are unreachable by the callee. */
    /* @0xd260c mov r0, r2 */
    /* @0xd2610 b 0x1f3b38 */
    (void)name;
    (void)type;
    return Variable_BuiltIn_Find_Name(id);
}
