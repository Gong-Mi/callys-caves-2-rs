/* do_add.h — the C translation of libyoyo's DoAdd (ARMv7, SHA256 3bbedd09…).
 *
 *     unsigned char *DoAdd(uint32 arg, unsigned char *sp,
 *                          const unsigned char *base, void *exec)
 *
 * DoAdd is the VM's `+` handler.  `arg` carries two fields:
 *     mode = (arg >> 8) & 0xF     0 strong-typed, 1 generic (+), 2 numeric
 *     cls  = (arg >> 16) & 0xFF   a PAIR BYTE: low nibble = the type of the
 *                                 operand at sp, high nibble = the type of the
 *                                 operand right after it.
 * The two operands are packed back to back on the value stack, with no 16-byte
 * alignment between them; the handler rewrites the tail of that span with the
 * result and returns the new stack pointer.
 *
 * Operand sizes by type nibble (the two tables at 0xdc564 / 0xdc598):
 *     0 real   8 B      1 float  4 B      2 int32  4 B      3 int64  8 B
 *     4 bool   4 B      5 RValue 16 B     6 string 4 B      7..15  refused
 * Type 5 is a *boxed* operand: its real type comes from the tag word at +0xC,
 * which the handler resolves first (tables at 0xdc908 / 0xdc964) and then
 * re-runs the pair dispatch with the resolved nibble.
 *
 * Scope of this translation (see harness/do_add_diff.py for the receipts):
 *   * mode 0 / fall-through modes 3..15 — the whole strong-typed arm: every
 *     pair byte 0..102, every RValue tag 0..15 in both operand positions, the
 *     type tower (int32/int64/real), the 4/8/16-byte result placement and the
 *     :1:/:2: error strings.
 *   * mode 1 / mode 2 — the numeric limb only (types 0/2/3/4 and the
 *     "no tag written" ReferenceError limb).  The string limb of mode 1 needs
 *     F_JS_ToString, which is not recovered, and is not claimed.
 *   * string+string (pair 0x66) — covered, including the concat order, the
 *     length arithmetic and the input refcount decrement.  The inputs are
 *     staged with refcount >= 2 so the "free the operand" branch (0xdcea0 /
 *     0xdcef8: YYFree + _RefThing::dec + operator delete) is never taken; that
 *     chain is NOT recovered and is not claimed.
 */
#ifndef DO_ADD_H
#define DO_ADD_H

#include <stdint.h>

unsigned char *DoAdd(uint32_t arg, unsigned char *sp, const unsigned char *base,
                     void *exec);

/* The text the handler would have handed to VMError/JSThrow*, byte for byte,
 * or 0 when the call emitted nothing.  The differential compares this string
 * with what the original passes to the real VMError in Unicorn. */
const char *do_add_last_error(void);

#endif
