/* tier: bytecode_anchored — separate-account body (分账)
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Recovers the anonymous array-cleanup body at 0x1910b4..0x1910e8 (the
 * 52-byte span between D1's last word and _ZN13CGCGeneration6IsRootEv;
 * no dynsym/symtab name exists for it, so the recovered name below is
 * descriptive only).
 * Registration words (owned by the image-startup line, NOT defined here):
 * the init loop at 0xb98c8/0xb98d0 runs C1 four times over GOT-resolved
 * &g_GCGens (slot 0x3edc68 R_ARM_RELATIVE -> 0x536da8, stride #88, stop
 * after +0x160), then 0xb98e0..0xb98f4 calls __aeabi_atexit with the real
 * arguments:
 *   r0 = 0          (0xb98e4 mov r0, #0; the object argument is NULL)
 *   r1 = 0x1910b4   (0xb98ec add r1, pc, r1; this body)
 *   r2 = 0x3f2000   (0xb98f0 add r2, pc, r2; the dso-handle cell)
 * The callback therefore IGNORES its object argument: the body loads the
 * pool word at 0x1910e4 (0x0025cba4), resolves GOT 0x3edc68 via
 * ldr r4,[pc,r4] at 0x1910bc, and destroys through the re-derived base:
 *   0x1910c0 add r0,r4,#0x108; bl D1   (index 3)
 *   0x1910c8 add r0,r4,#0xb0;  bl D1   (index 2)
 *   0x1910d0 add r0,r4,#0x58;  bl D1   (index 1)
 *   0x1910d8 mov r0,r4; pop; b D1      (index 0 via the tail branch)
 * No guard byte, no per-slot zeroing and no last-element hook exists in
 * the original words; reverse-order (3,2,1,0) is the destruction order.
 * gap: link/load/termination equivalence stays with the startup line; the
 * definition of g_GCGens is deliberately NOT in this seam.
 */
#include "gc_generation.hpp"

void gcGensArrayDtor(void *) {
    /* The original never reads the incoming pointer; it re-derives the
     * array base through the GOT exactly like the plain expression below
     * on a non-PIC-constant object. */
    GCGenerationStorage *const gens = g_GCGens;
    liveGeneration(gens[3]).~CGCGeneration(); /* 0x1910c0-0x1910c4 */
    liveGeneration(gens[2]).~CGCGeneration(); /* 0x1910c8-0x1910cc */
    liveGeneration(gens[1]).~CGCGeneration(); /* 0x1910d0-0x1910d4 */
    liveGeneration(gens[0]).~CGCGeneration(); /* 0x1910d8-0x1910e0 (tail branch in the image) */
}
