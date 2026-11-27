/* tier: bytecode_anchored. Static recovery of three dynsym teardown
 * functions from original image libyoyo_armv7.so (ARMv7 ELF32), SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * (per gc-finalize-anchors/bindings.json).
 *
 * Windows (authoritative census: the finalize-*.asm.txt files under
 * gc-finalize-anchors):
 *   _Z12FINALIZE_Allv            0xc47f8, 4B   code 0xc47f8..0xc47f8
 *   _Z18FINALIZE_Code_Mainv      0xcf478, 4B   code 0xcf478..0xcf478
 *   _Z22FINALIZE_Code_Functionv  0xce274, 68B  code 0xce274..0xce2ac,
 *                                              literals 0xce2ac..0xce2b8
 *
 * These three are callees of the already-recovered Quit@0x2a27fc teardown
 * chain (Quit declarations come from host_lifecycle/quit_runtime.hpp).
 * MemoryManager::Free is RECOVERED and DEFINED in the cumulative set
 * (memory_manager body; canonical class declaration lives in
 * vm_buffer/vm_buffer.hpp, reached through memory_manager/memory_internal.hpp),
 * so the 0xce284 bl edge below is a REAL call through that declaration --
 * no stub, no shadow prototype.
 *
 * Anonymous BSS words cleared by FINALIZE_Code_Function are represented per
 * the prescribed rule as extern "C" unsigned char arrays, left UNDEFINED in
 * this translation unit: no storage definition, no invented original names.
 * The final link must place them at the addresses encoded in their names.
 *
 * gap: the producers/writers of the three anonymous words 0x47a14c, 0x47a148
 * and 0x48a148 are outside this window and unproven here -- 0x47a14c holds a
 * pointer-shaped value consumed only as Free's argument and then zeroed, so
 * its allocating producer is unidentified; the content semantics of 0x47a148
 * and 0x48a148 are likewise unidentified (pointer vs scalar vs counter).
 * EHABI details (unwind tables, .ARM.exidx entries) of the originals are not
 * recovered; the compiled objects carry the compiler's own EHABI, not the
 * original's. Concurrency: whether these finalizers ran under any lock is
 * unproved. Final linked addresses (GOT slots 0x3edb20/0x3edb1c resolving to
 * 0x47a14c/0x47a148, and the pc-relative materialization of 0x48a148) hold
 * only if the final link honors the placement comments below. Nothing in
 * this file was executed; no instruction-sequence or behavior equivalence to
 * the original image is claimed -- instruction-address comments mark where
 * each recovered operation sits in the original, in original order.
 */

#include "../memory_manager/memory_internal.hpp" /* canonical MemoryManager, incl. Free */
#include "quit_runtime.hpp"                      /* FINALIZE_* declarations (0xc47f8/0xcf478/0xce274) */

/* Prescribed anonymous-BSS representation. Each declaration binds the
 * final-link placement requirement; none is defined here. */
extern "C" unsigned char anon_0x47a14c[4]; // final link must place at 0x47a14c, 4B, R_ARM_RELATIVE GOT slot 0x3edb20
extern "C" unsigned char anon_0x47a148[4]; // final link must place at 0x47a148, 4B, R_ARM_RELATIVE GOT slot 0x3edb1c
extern "C" unsigned char anon_0x48a148[4]; // final link must place at 0x48a148, 4B, direct pc-relative target (no GOT)

/* _Z12FINALIZE_Allv, 0xc47f8, size 4. Census shows exactly one instruction
 * word e12fff1e (bx lr): the original body is EMPTY. Recorded as an
 * immediate-return function; nothing is invented. */
void FINALIZE_All() {
    // 0xc47f8: e12fff1e  bx lr -- immediate return, empty body
}

/* _Z18FINALIZE_Code_Mainv, 0xcf478, size 4. Same census shape: single word
 * e12fff1e (bx lr), original body EMPTY, immediate return. */
void FINALIZE_Code_Main() {
    // 0xcf478: e12fff1e  bx lr -- immediate return, empty body
}

/* _Z22FINALIZE_Code_Functionv, 0xce274, size 68: code 0xce274..0xce2ac,
 * literal pool 0xce2ac..0xce2b8 holding 0x0031f89c / 0x0031f880 / 0x003abea0.
 * Parent-verified slot bindings (gc-finalize-anchors/bindings.json):
 *   pool+0x00 0x0031f89c -> GOT 0x3edb20 -> anonymous word 0x47a14c (BSS 4B)
 *   pool+0x04 0x0031f880 -> GOT 0x3edb1c -> anonymous word 0x47a148 (BSS 4B)
 *   pool+0x08 0x003abea0 -> add r1,pc,r1 @0xce29c materializes direct
 *                          address 0x48a148 (BSS 4B, no GOT indirection)
 * 0xce284 bl _ZN13MemoryManager4FreeEPKv is the only call edge. */
void FINALIZE_Code_Function() {
    // 0xce274: e92d4010  push {r4, lr}
    // 0xce278: e59f402c  ldr r4, [pc, #0x2c]  ; pool 0xce2ac = 0x0031f89c -> GOT 0x3edb20
    // 0xce27c: e79f4004  ldr r4, [pc, r4]     ; resolves to BSS word 0x47a14c
    uint32_t *slot47a14c = reinterpret_cast<uint32_t *>(anon_0x47a14c);
    // 0xce280: e5940000  ldr r0, [r4]         ; the stored pointer-shaped value
    // 0xce284: eb06b811  bl _ZN13MemoryManager4FreeEPKv  ; real edge: recovered MemoryManager::Free
    MemoryManager::Free(reinterpret_cast<const void *>(*slot47a14c));
    // 0xce288: e59f2020  ldr r2, [pc, #0x20]  ; pool 0xce2b0 = 0x0031f880 -> GOT 0x3edb1c
    // 0xce28c: e59f1020  ldr r1, [pc, #0x20]  ; pool 0xce2b4 = 0x003abea0 (pc addend for 0xce29c)
    // 0xce290: e3a03000  mov r3, #0           ; shared zero value for the three stores
    uint32_t *slot47a148 = reinterpret_cast<uint32_t *>(anon_0x47a148);
    uint32_t *slot48a148 = reinterpret_cast<uint32_t *>(anon_0x48a148);
    // 0xce294: e79f2002  ldr r2, [pc, r2]     ; resolves to BSS word 0x47a148
    // 0xce298: e5843000  str r3, [r4]         ; zero 0x47a14c (source pointer already passed to Free)
    *slot47a14c = 0u;
    // 0xce29c: e08f1001  add r1, pc, r1       ; materializes direct address 0x48a148
    // 0xce2a0: e5823000  str r3, [r2]         ; zero 0x47a148
    *slot47a148 = 0u;
    // 0xce2a4: e5813000  str r3, [r1]         ; zero 0x48a148
    *slot48a148 = 0u;
    // 0xce2a8: e8bd8010  pop {r4, pc}         ; return
    // 0xce2ac..0xce2c4: literal pool (0x0031f89c, 0x0031f880, 0x003abea0)
}
