/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU recovers the only body of _Z7ResetGCv 0xd66e0..0xd675c (124B,
 * dynsym GLOBAL) plus the two BSS words it clears
 * (reset-gc.asm.txt / reset-gc-binding.json):
 *   g_GenToCollect 4B .bss @0x47a1f8, str #0 at 0xd6714
 *   g_GCframe      4B .bss @0x47a1f4, str #0 at 0xd671c
 * The guard byte g_fJSGarbageCollection @0x47f295 (1B) is declared by the
 * existing vm_exec seam header (../vm_exec/vm_entry_runtime.hpp line 16);
 * its producer/writer is outside this slice and is neither defined nor
 * guessed here. The 4 x 88B array g_GCGens @0x536da8 and
 * CGCGeneration::Reset 0x19140c are the existing seam entities declared by
 * gc_generation.hpp; this TU references and calls them and never defines a
 * second gens array or a second Reset.
 *
 * Materialization split: in the original image every one of the four
 * globals was reached through a GOT slot filled by R_ARM_RELATIVE
 * (0x3edbc0->0x47f295, 0x3edc9c->0x47a1f8, 0x3edca0->0x47a1f4,
 * 0x3edc68->0x536da8; got_base 0x3f1c58) via pool-relative ldr at
 * 0xd66e0..0xd6720. The ET_REL object uses direct MOVW/MOVT symbol
 * relocations and direct call/branch relocations to the Reset symbol.
 * The GOT form and the ET_REL form are recorded separately;
 * neither certifies the other's final-link addresses.
 * gap: byte identity of the whole function body, EHABI/unwind records, the
 * runtime scheduling/locking protocol around these fields, and any
 * equivalence-by-execution claim stay unproved; the original was never
 * run, loaded or emulated for this recovery.
 */
#include "gc_reset_runtime.hpp"

/* Original names, 4B .bss each, defined only by this TU. The ordinary
 * definitions inherit C linkage from the declarations in the header,
 * so these are real 4-byte zero-initialized objects, not re-declarations.
 * The frozen binding pins width/role/write-site order, not VA. */
volatile uint32_t g_GenToCollect; // cleared at 0xd6714
volatile uint32_t g_GCframe;      // cleared at 0xd671c

void ResetGC() { // _Z7ResetGCv @0xd66e0
    /* 0xd66e0..0xd66f0 pool + GOT load of the byte address; 0xd66f4
     * e5d22000 ldrb reads g_fJSGarbageCollection exactly once; 0xd66f8
     * cmp r2,#0 / 0xd66fc 08bd8010 popeq returns with no other state read
     * or write when the byte is zero. */
    if (g_fJSGarbageCollection == 0u) {
        return;
    }
    /* True branch keeps both volatile stores in the literal order
     * 0xd6714 str r2,[ip] then 0xd671c str r2,[r0], with r2 = #0 set at
     * 0xd6704. No extra lifecycle calls exist on this path. */
    g_GenToCollect = 0u; // 0xd6714, GOT 0x3edc9c
    g_GCframe = 0u;      // 0xd671c, GOT 0x3edca0

    /* 0xd6720 ldr r4,[r3,r1]: &g_GCGens (GOT 0x3edc68) once; then Reset
     * on +0/+88/+176/+264 with BL sites 0xd6728/0xd6730/0xd6738 and,
     * after 0xd6740 pop {r4,lr}, the tail B at 0xd6744 — all four to
     * 0x19140c _ZN13CGCGeneration5ResetEv. liveGeneration reinterprets
     * the seam's own 88B storage entries in ascending order. */
    liveGeneration(g_GCGens[0]).Reset();
    liveGeneration(g_GCGens[1]).Reset();
    liveGeneration(g_GCGens[2]).Reset();
    liveGeneration(g_GCGens[3]).Reset();
}
