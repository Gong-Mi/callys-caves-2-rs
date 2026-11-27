/* tier: bytecode_anchored. Static recovery of four dynsym teardown
 * functions from original image libyoyo_armv7.so (ARMv7 ELF32), SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * (per gc-finalize-anchors/bindings.json, batch7_functions).
 *
 * Windows (authoritative census: the finalize-*.asm.txt files under
 * gc-finalize-anchors; independently re-disassembled from the pinned image
 * with llvm-objdump and found byte-identical; code span / literal pool as
 * recorded there):
 *   _Z18FINALIZE_Room_Mainv    0x1b5e54, 32B   code 0x1b5e54..0x1b5e6c,
 *                                              pool word 0x1b5e70..0x1b5e74
 *   _Z17FINALIZE_Run_Mainv     0x1d37cc, 276B  code 0x1d37cc..0x1d38d0,
 *                                              pool 0x1d38d4..0x1d38e0
 *   _Z20FINALIZE_Motion_Gridv  0x19c2cc, 140B  code 0x19c2cc..0x19c34c,
 *                                              pool 0x19c350..0x19c358
 *   _Z22FINALIZE_Code_Variablev 0xd2618, 4B    code 0xd2618..0xd261c
 *
 * These four are callees of the already-recovered Quit@0x2a27fc teardown
 * chain (declarations come from host_lifecycle/quit_runtime.hpp).
 * Real links in this slice:
 *   bl _ZN13MemoryManager4FreeEPKv -- RECOVERED/DEFINED in the cumulative
 *     set; referenced through the canonical class declaration in
 *     vm_buffer/vm_buffer.hpp, reached via memory_manager/memory_internal.hpp.
 *     Three call sites (0x1d38a8, 0x1d38c8, 0x19c33c); no stub, no shadow
 *     prototype. The 0x1d38c8 site passes a NULL argument by census shape.
 *   bl _Z9Room_Freev -- NOT recovered: extern-only declaration, no stub.
 *     The dynsym-defined target sits at 0x1b5044 (504B, .text, not UND).
 *   blx [vtable word +4] -- two indirect (virtual-style) call sites, at
 *     0x1d384c (per-array-element) and 0x19c318 (per-grid-element).
 *     Targets unresolved (no dynsym identity), no stubs; reproduced as raw
 *     indirect calls with the exact slot path.
 *
 * Slot resolution (each ldr [pc,#n] / ldr [pc,rX] pair, verified against
 * .rel.dyn of the pinned image -- every slot is GOT with R_ARM_RELATIVE and
 * its addend equals the final address; ALL SIX resolve onto NAMED dynsym
 * GLOBAL OBJECTs, so this batch needs no anon arrays):
 *   Room_Main  pool 0x1b5e70 0x0023a9dc -> GOT 0x3f0848 -> 0x542914
 *              Cursor_Subimage (OBJECT, 4B)
 *   Run_Main   pool 0x1d38d4 0x0021d370 -> GOT 0x3f0b50 -> 0x542a0c
 *              persinst (OBJECT, 8B: word +0 count, word +4 array pointer)
 *   Run_Main   pool 0x1d38d8 0x0021d368 -> GOT 0x3f0b4c -> 0x542a14
 *              persnumb (OBJECT, 4B)
 *   Run_Main   pool 0x1d38dc 0x0021a390 -> GOT 0x3edbc0 -> 0x47f295
 *              g_fJSGarbageCollection (OBJECT, 1B, byte-read via ldrb)
 *   Motion     pool 0x19c350 0x002543dc -> GOT 0x3f06b8 -> 0x536f4c
 *              gridstruct (OBJECT, 4B, pointer-shaped)
 *   Motion     pool 0x19c354 0x002543c4 -> GOT 0x3f06b4 -> 0x536f48
 *              gridcount (OBJECT, 4B)
 * The named declarations below carry only the dynsym identity and the
 * observed access widths (4B words, 1 byte); the source-level types are
 * unproven. volatile mirrors the per-iteration reloads the census performs
 * inside the loops; it is not a claim about the original's spelling. None of
 * these objects is defined here; the final link must place them at the
 * dynsym-encoded addresses.
 *
 * gap: the producers/writers of the six named words are outside these
 * windows and unproven here -- who allocates/fills the persinst array and
 * the gridstruct array, which site sets g_fJSGarbageCollection, and what the
 * element objects behind the two blx [vtable+4] sites are (class identity,
 * and the meaning of the +0x44 word with its -1 sentinel skip in Run_Main)
 * all remain unidentified. Cursor_Subimage is only stored (zeroed) here; its
 * producing reads are elsewhere. Room_Free@0x1b5044 is unrecovered, so what
 * FINALIZE_Room_Main releases before zeroing Cursor_Subimage is unproven.
 * NOTE (deviation from the dispatch context, recorded in notes.json): the
 * dispatch context described FINALIZE_Room_Main as tail-branching to
 * FINALIZE_Run_Main; the authoritative census AND a direct llvm-objdump of
 * the pinned image both show the window ending at 0x1b5e6c with e8bd8008
 * pop {r3, pc} -- a plain function return, no tail branch, and no other
 * edge into the sibling. The body below reflects the image, not the claim.
 * EHABI details (unwind tables, .ARM.exidx entries) of the originals are not
 * recovered; the compiled objects carry the compiler's own EHABI, not the
 * original's. Concurrency: whether these finalizers ran under any lock is
 * unproved; the guard byte g_fJSGarbageCollection read per element suggests
 * a mode flag but its writer is unknown. Final linked addresses (the six
 * GOT-slot bindings above) hold only if the final link honors the placement
 * comments. Nothing in this file was executed; no instruction-sequence or
 * behavior equivalence to the original image is claimed -- instruction-
 * address comments mark where each recovered operation sits in the original,
 * in original order. Register mirrors carry the census register names
 * (declared up front so the reproduced gotos cross no initialization); all
 * bgt/bge/blt/ble/poplt-style compares are SIGNED per the census. Internal
 * b/bxx edges are reproduced as labels, not flattened -- including the
 * 0x1d38d0 b 0x1d38b4 internal branch (a backward join edge, not a tail
 * call) and the two separate arrivals at the loop top 0x1d3800/0x1d3804.
 */

#include "../memory_manager/memory_internal.hpp" /* canonical MemoryManager incl. Free */
#include "quit_runtime.hpp"                      /* FINALIZE_* declarations (0x1b5e54/0x1d37cc/0x19c2cc/0xd2618) */

/* Named dynsym OBJECTs behind the resolved GOT slots (resolution table in
 * the header comment). Declarations only -- no definitions, no stubs; the
 * final link must place each at its dynsym address. */
extern "C" volatile uint32_t Cursor_Subimage;            // 0x542914, 4B; via R_ARM_RELATIVE GOT slot 0x3f0848; content type unproven (raw word)
extern "C" volatile uint32_t persinst[2];                // 0x542a0c, 8B; via GOT 0x3f0b50: [+0] signed count word, [+4] array-pointer word
extern "C" volatile uint32_t persnumb;                   // 0x542a14, 4B; via GOT 0x3f0b4c
// g_fJSGarbageCollection (0x47f295, 1B; via GOT 0x3edbc0) is already declared
// in the frozen seam (vm_exec/vm_entry_runtime.hpp: extern volatile uint8_t);
// this TU reuses that declaration -- byte-read at 0x1d382c (ldrb).
extern "C" volatile uint32_t gridcount;                  // 0x536f48, 4B; via GOT 0x3f06b4
extern "C" volatile uint32_t gridstruct;                 // 0x536f4c, 4B; via GOT 0x3f06b8; pointer-shaped word

/* _Z9Room_Freev is NOT in the recovered set (dynsym-defined at 0x1b5044,
 * 504B, .text). Extern-only declaration carrying the dynsym identity; the
 * mangled name of this declaration is exactly the census bl target symbol.
 * No stub, no body. */
void Room_Free(); // 0x1b5044, 504B

/* _Z22FINALIZE_Code_Variablev, 0xd2618, size 4. Census confirmed against the
 * pinned image: exactly one instruction word e12fff1e (bx lr) -- the original
 * body is EMPTY. Recorded as an immediate-return function; nothing is
 * invented. */
void FINALIZE_Code_Variable() {
    // 0xd2618: e12fff1e  bx lr -- immediate return, empty body
}

/* _Z18FINALIZE_Room_Mainv, 0x1b5e54, size 32: code 0x1b5e54..0x1b5e6c, pool
 * word 0x1b5e70. Frees the room through the unrecovered Room_Free extern,
 * zeroes the named word Cursor_Subimage via its GOT slot, then RETURNS.
 * The window contains no tail branch to FINALIZE_Run_Main (see header and
 * notes.json: dispatch-context claim refuted by census + image bytes). */
void FINALIZE_Room_Main() {
    // 0x1b5e54: e92d4008  push {r3, lr}
    // 0x1b5e58: ebfffc79  bl _Z9Room_Freev  ; extern-only edge, no stub (0x1b5044 unrecovered)
    Room_Free();
    // 0x1b5e5c: e3a02000  mov r2, #0
    // 0x1b5e60: e59f3008  ldr r3, [pc, #0x8]   ; pool 0x1b5e70 = 0x0023a9dc -> GOT 0x3f0848
    // 0x1b5e64: e79f3003  ldr r3, [pc, r3]     ; R_ARM_RELATIVE resolves to Cursor_Subimage 0x542914
    // 0x1b5e68: e5832000  str r2, [r3]         ; Cursor_Subimage = 0
    Cursor_Subimage = 0u;
    // 0x1b5e6c: e8bd8008  pop {r3, pc}         ; plain return -- NO tail branch to FINALIZE_Run_Main
    // 0x1b5e70: 0023a9dc  literal pool word (GOT byte offset, not an instruction)
}

/* _Z17FINALIZE_Run_Mainv, 0x1d37cc, size 276: code 0x1d37cc..0x1d38d0,
 * literal pool 0x1d38d4..0x1d38e0 (0x0021d370 / 0x0021d368 / 0x0021a390).
 * Mirrors the per-element teardown of the persinst array:
 *   persnumb = persinst[0] (unconditional store at 0x1d37e8, even when <=0);
 *   if persinst[0] > 0, walk i from 0 while persnumb(reloaded) > i:
 *     when i < persinst[0](reloaded), take element = persinst[1](reloaded)+4i;
 *     non-null elements: when the guard byte g_fJSGarbageCollection != 0,
 *     skip destruct if element+0x44 == -1, else blx [*(element)+4]; when the
 *     guard byte is 0, destruct unconditionally (0x1d3834 beq path);
 *     the element slot is then null-stored on EVERY iteration (also on the
 *     i>=count bge path at 0x1d3850, whose base slot address is reloaded);
 *   tail: if persinst[1] == 0, Free(NULL) at 0x1d38c8 and store 0 through
 *     +4 (0x1d38cc, register-identical); else zero persinst[0] words of the
 *     array (base reloaded per iteration at 0x1d389c), Free(base),
 *     persinst[1] = 0; join at 0x1d38b4: persinst[0] = 0, persnumb = 0, ret.
 * The 0x1d38d0 b 0x1d38b4 edge is an internal backward join, reproduced as a
 * label, not a tail call. */
void FINALIZE_Run_Main() {
    // 0x1d37cc: e92d41f0  push {r4, r5, r6, r7, r8, lr}
    // 0x1d37d0: e59f60fc  ldr r6, [pc, #0xfc]   ; pool 0x1d38d4 = 0x0021d370 -> GOT 0x3f0b50
    // 0x1d37d4: e59f70fc  ldr r7, [pc, #0xfc]   ; pool 0x1d38d8 = 0x0021d368 -> GOT 0x3f0b4c
    // 0x1d37d8: e79f6006  ldr r6, [pc, r6]      ; R_ARM_RELATIVE resolves to persinst 0x542a0c
    // 0x1d37dc: e79f7007  ldr r7, [pc, r7]      ; R_ARM_RELATIVE resolves to persnumb 0x542a14
    volatile uint32_t *r6_pers = &persinst[0];
    volatile uint32_t *r7_numb = &persnumb;
    uint32_t r2_cnt = 0u;                        // 0x1d37e0 ldr r2,[r6] mirror (declared hoisted)
    uint32_t r1_raw = 0u;                        // element word at 0x1d3818 (single volatile read)
    uint32_t r4_off = 0u;                        // byte offset within the array (movgt r4,#0 site; unused when count<=0)
    uint32_t r5_idx = 0u;                        // element counter   (movgt r5,r4 site)
    uint32_t r8_zero = 0u;                       // constant zero value (movgt r8,r4 site) -- null store operand
    volatile uint32_t *r2_slot = nullptr;        // element-slot address carried to the 0x1d3864 store
    volatile uint32_t *r1_elem = nullptr;        // element pointer (0x1d3818 load)
    int32_t r3_numb = 0;                         // persnumb reload at 0x1d3858
    int32_t r3_guardword = 0;                    // element+0x44 word (0x1d3838)
    uint32_t r4_base = 0u;                       // persinst[1] raw word in the tail (0x1d3870)
    uint32_t zf_i = 0u;                          // zero-fill index (r3 at 0x1d3888)
    // 0x1d37e0: e5962000  ldr r2, [r6]          ; r2 = persinst[0]
    r2_cnt = *r6_pers;
    // 0x1d37e4: e3520000  cmp r2, #0
    // 0x1d37e8: e5872000  str r2, [r7]          ; persnumb = persinst[0] -- UNCONDITIONAL (executes for zero/negative too)
    *r7_numb = r2_cnt;
    // 0x1d37ec: c3a04000  movgt r4, #0          ; r4/r5/r8 are predicated-initialized; mirrors
    // 0x1d37f0: c1a05004  movgt r5, r4          ; above start at 0, which is exactly their
    // 0x1d37f4: c1a08004  movgt r8, r4          ; value on the taken (count>0) path
    // 0x1d37f8: ca000001  bgt 0x1d3804          ; signed: enter loop when persinst[0] > 0
    // 0x1d37fc: ea00001b  b 0x1d3870            ; else straight to the tail
    if (!(static_cast<int32_t>(r2_cnt) > 0)) goto L_run_tail;
    goto L_run_entry;                            // first entry skips the 0x1d3800 reload (r2 already loaded)
L_run_top:                                       // 0x1d3800 (loop-continue target)
    // 0x1d3800: e5962000  ldr r2, [r6]          ; count RELOAD (a destructor call may have moved it)
    r2_cnt = *r6_pers;
L_run_entry:                                     // 0x1d3804 (first-entry target)
    // 0x1d3804: e1550002  cmp r5, r2
    // 0x1d3808: e59f30cc  ldr r3, [pc, #0xcc]   ; pool 0x1d38dc = 0x0021a390 -> GOT 0x3edbc0 (guard-byte address, materialized at 0x1d3828; constant in C)
    // 0x1d380c: aa00000f  bge 0x1d3850          ; signed: i >= count -> skip destruct, still null-store
    if (static_cast<int32_t>(r5_idx) >= static_cast<int32_t>(r2_cnt)) goto L_run_storenull;
    // 0x1d3810: e5961004  ldr r1, [r6, #0x4]    ; array base = persinst[1]
    // 0x1d3814: e0812004  add r2, r1, r4        ; element slot address
    r2_slot = reinterpret_cast<volatile uint32_t *>(
        reinterpret_cast<unsigned char *>(static_cast<uintptr_t>(r6_pers[1])) + r4_off);
    // 0x1d3818: e7911004  ldr r1, [r1, r4]      ; element pointer
    // 0x1d381c: e3510000  cmp r1, #0
    // 0x1d3820: e1a00001  mov r0, r1            ; the blx self-argument moves to r0 here
    r1_raw = *r2_slot;                           // single load; cmp/mov/beq all use this one value
    r1_elem = reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r1_raw));
    // 0x1d3824: 0a00000b  beq 0x1d3858          ; null element -> skip destruct (r2 slot address kept)
    if (r1_raw == 0u) goto L_run_iterend;
    // 0x1d3828: e79f3003  ldr r3, [pc, r3]      ; R_ARM_RELATIVE resolves to g_fJSGarbageCollection 0x47f295
    // 0x1d382c: e5d33000  ldrb r3, [r3]         ; guard byte
    // 0x1d3830: e3530000  cmp r3, #0
    // 0x1d3834: 0a000002  beq 0x1d3844          ; guard CLEAR -> destruct unconditionally (skip the +0x44 test)
    if (g_fJSGarbageCollection != 0u) {
        // 0x1d3838: e5913044  ldr r3, [r1, #0x44]  ; element word +0x44
        // 0x1d383c: e3730001  cmn r3, #1
        // 0x1d3840: 0a000004  beq 0x1d3858          ; == -1 -> skip destruct (slot address kept)
        r3_guardword = static_cast<int32_t>(r1_elem[17u]); // 0x44/4
        if (r3_guardword == -1) goto L_run_iterend;
    }
    // 0x1d3844 (beq landing pad == this fall-through point; no separate edge needed):
    // 0x1d3844: e5913000  ldr r3, [r1]          ; vtable pointer = [element+0]
    // 0x1d3848: e5933004  ldr r3, [r3, #0x4]    ; vtable word +4
    // 0x1d384c: e12fff33  blx r3                ; INDIRECT virtual-style call; target unresolved (no dynsym identity), no stub; r0 = element
    reinterpret_cast<void (*)(void *)>(
        reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(r1_elem[0]))[1])(
        reinterpret_cast<void *>(static_cast<uintptr_t>(r1_raw)));  // r0 == element (r1_raw from 0x1d3818)
L_run_storenull:                                 // 0x1d3850
    // 0x1d3850: e5962004  ldr r2, [r6, #0x4]    ; base RELOAD (bge path and post-blx fall-through)
    // 0x1d3854: e0822004  add r2, r2, r4
    r2_slot = reinterpret_cast<volatile uint32_t *>(
        reinterpret_cast<unsigned char *>(static_cast<uintptr_t>(r6_pers[1])) + r4_off);
L_run_iterend:                                   // 0x1d3858
    // 0x1d3858: e5973000  ldr r3, [r7]          ; persnumb RELOAD (a destructor may have written it)
    // 0x1d385c: e2855001  add r5, r5, #1
    // 0x1d3860: e2844004  add r4, r4, #4
    // 0x1d3864: e5828000  str r8, [r2]          ; null the element slot (r8 == 0)
    // 0x1d3868: e1530005  cmp r3, r5
    // 0x1d386c: caffffe3  bgt 0x1d3800          ; signed: loop while persnumb > i
    r3_numb = static_cast<int32_t>(*r7_numb);
    r5_idx = r5_idx + 1u;
    r4_off = r4_off + 4u;
    *r2_slot = r8_zero;
    if (r3_numb > static_cast<int32_t>(r5_idx)) goto L_run_top;
L_run_tail:                                      // 0x1d3870
    // 0x1d3870: e5964004  ldr r4, [r6, #0x4]    ; base
    // 0x1d3874: e3540000  cmp r4, #0
    // 0x1d3878: 0a000011  beq 0x1d38c4          ; null base -> Free(NULL) path
    r4_base = r6_pers[1];
    if (r4_base == 0u) goto L_run_freenull;
    // 0x1d387c: e5962000  ldr r2, [r6]          ; count
    // 0x1d3880: e3520000  cmp r2, #0
    // 0x1d3884: da000006  ble 0x1d38a4          ; signed: count <= 0 -> free without zero-fill
    r2_cnt = *r6_pers;
    if (static_cast<int32_t>(r2_cnt) <= 0) goto L_run_free;
    // 0x1d3888: e3a03000  mov r3, #0            ; zero-fill index
    // 0x1d388c: e1a01003  mov r1, r3            ; zero value for the stores
    zf_i = 0u;
L_run_zf:                                        // 0x1d3890
    // 0x1d3890: e7841103  str r1, [r4, r3, lsl #2]  ; base[i] = 0 (base as of previous load)
    // 0x1d3894: e2833001  add r3, r3, #1
    // 0x1d3898: e1530002  cmp r3, r2
    // 0x1d389c: e5964004  ldr r4, [r6, #0x4]    ; base RELOAD each iteration
    // 0x1d38a0: 1afffffa  bne 0x1d3890          ; until i == count
    reinterpret_cast<volatile uint32_t *>(
        reinterpret_cast<unsigned char *>(static_cast<uintptr_t>(r4_base)))[zf_i] = 0u;
    zf_i = zf_i + 1u;
    r4_base = r6_pers[1];
    if (zf_i != r2_cnt) goto L_run_zf;
L_run_free:                                      // 0x1d38a4
    // 0x1d38a4: e1a00004  mov r0, r4            ; r4 = reloaded base (or 0x1d3870 value if ble taken)
    // 0x1d38a8: eb02a288  bl _ZN13MemoryManager4FreeEPKv  ; real edge: recovered Free
    MemoryManager::Free(reinterpret_cast<const void *>(static_cast<uintptr_t>(r4_base)));
    // 0x1d38ac: e3a03000  mov r3, #0
    // 0x1d38b0: e5863004  str r3, [r6, #0x4]    ; persinst[1] = 0
    r6_pers[1] = 0u;
    goto L_run_join;                             // fall-through 0x1d38b0 -> 0x1d38b4
L_run_freenull:                                  // 0x1d38c4
    // 0x1d38c4: e1a00004  mov r0, r4            ; r4 == 0 here: the census calls Free(NULL)
    // 0x1d38c8: eb02a280  bl _ZN13MemoryManager4FreeEPKv  ; real edge: recovered Free (NULL argument by census shape)
    MemoryManager::Free(reinterpret_cast<const void *>(static_cast<uintptr_t>(r4_base)));
    // 0x1d38cc: e5864004  str r4, [r6, #0x4]    ; stores the same 0 through +4 (register path, value-identical)
    r6_pers[1] = r4_base;
L_run_join:                                      // 0x1d38b4 (target of the 0x1d38d0 b, an internal join, not a tail call)
    // 0x1d38b4: e3a03000  mov r3, #0            ; zero re-materialized (value already 0)
    // 0x1d38b8: e5863000  str r3, [r6]          ; persinst[0] = 0
    // 0x1d38bc: e5873000  str r3, [r7]          ; persnumb = 0
    // 0x1d38c0: e8bd81f0  pop {r4, r5, r6, r7, r8, pc}
    *r6_pers = 0u;
    *r7_numb = 0u;
    return;
    // 0x1d38d4..0x1d38e0: literal pool (0x0021d370, 0x0021d368, 0x0021a390)
}

/* _Z20FINALIZE_Motion_Gridv, 0x19c2cc, size 140: code 0x19c2cc..0x19c34c,
 * literal pool 0x19c350..0x19c358 (0x002543dc / 0x002543c4).
 * If gridstruct == 0: popeq immediate return. Else walk i from 0 while
 * gridcount(reloaded) > i: element = gridstruct[i] (base as of the previous
 * load); non-null elements destruct through blx [*(element)+4]; then the
 * slot is nulled THROUGH A RELOADED gridstruct base (0x19c31c) and r2 is
 * reloaded (0x19c324) -- so Free's argument below is the last-reloaded
 * gridstruct, possibly written by a destructor; on the gridcount<=0 path it
 * is the original load. Then Free(that pointer), gridstruct = 0,
 * gridcount = 0, return. All compares signed per census. */
void FINALIZE_Motion_Grid() {
    // 0x19c2cc: e92d40f8  push {r3, r4, r5, r6, r7, lr}
    // 0x19c2d0: e59f5078  ldr r5, [pc, #0x78]   ; pool 0x19c350 = 0x002543dc -> GOT 0x3f06b8
    // 0x19c2d4: e79f5005  ldr r5, [pc, r5]      ; R_ARM_RELATIVE resolves to gridstruct 0x536f4c
    volatile uint32_t *r5_gs = &gridstruct;
    uint32_t r2_arr = 0u;                        // gridstruct value mirror (0x19c2d8)
    uint32_t r4_i = 0u;                          // element index (0x19c2f8)
    uint32_t r3_elem = 0u;                       // element pointer word (0x19c300)
    uint32_t r7_zero = 0u;                       // null store value (0x19c2fc)
    int32_t r3_cnt = 0;                          // gridcount reload (0x19c328)
    // 0x19c2d8: e5952000  ldr r2, [r5]
    r2_arr = *r5_gs;
    // 0x19c2dc: e3520000  cmp r2, #0
    // 0x19c2e0: 08bd80f8  popeq {r3, r4, r5, r6, r7, pc}  ; null array -> immediate return
    if (r2_arr == 0u) return;                    // 0x19c2e0 tail (popeq)
    // 0x19c2e4: e59f6068  ldr r6, [pc, #0x68]   ; pool 0x19c354 = 0x002543c4 -> GOT 0x3f06b4
    // 0x19c2e8: e79f6006  ldr r6, [pc, r6]      ; R_ARM_RELATIVE resolves to gridcount 0x536f48
    volatile uint32_t *r6_gc = &gridcount;
    // 0x19c2ec: e5963000  ldr r3, [r6]
    // 0x19c2f0: e3530000  cmp r3, #0
    // 0x19c2f4: da00000f  ble 0x19c338          ; signed: gridcount <= 0 -> free without walking
    r3_cnt = static_cast<int32_t>(*r6_gc);
    if (r3_cnt <= 0) goto L_motion_free;
    // 0x19c2f8: e3a04000  mov r4, #0            ; i
    // 0x19c2fc: e1a07004  mov r7, r4            ; r7 = 0 (null store value)
    r4_i = 0u;
    r7_zero = 0u;
L_motion_loop:                                   // 0x19c300
    // 0x19c300: e7923104  ldr r3, [r2, r4, lsl #2]  ; element (base as of previous load)
    // 0x19c304: e3530000  cmp r3, #0
    // 0x19c308: e1a00003  mov r0, r3            ; the blx self-argument moves to r0 here
    // 0x19c30c: 0a000005  beq 0x19c328          ; null element -> skip destruct and slot-nulling
    r3_elem = reinterpret_cast<volatile uint32_t *>(
        reinterpret_cast<unsigned char *>(static_cast<uintptr_t>(r2_arr)))[r4_i];
    if (r3_elem == 0u) goto L_motion_adv;
    // 0x19c310: e5933000  ldr r3, [r3]          ; vtable pointer = [element+0]
    // 0x19c314: e5933004  ldr r3, [r3, #0x4]    ; vtable word +4
    // 0x19c318: e12fff33  blx r3                ; INDIRECT virtual-style call; target unresolved (no dynsym identity), no stub; r0 = element
    reinterpret_cast<void (*)(void *)>(
        reinterpret_cast<uint32_t *>(static_cast<uintptr_t>(
            *reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r3_elem))))[1])(
        reinterpret_cast<void *>(static_cast<uintptr_t>(r3_elem)));
    // 0x19c31c: e5953000  ldr r3, [r5]          ; gridstruct RELOAD
    // 0x19c320: e7837104  str r7, [r3, r4, lsl #2]  ; null the slot through the reloaded base
    // 0x19c324: e5952000  ldr r2, [r5]          ; gridstruct RELOAD (feeds the later Free)
    reinterpret_cast<volatile uint32_t *>(
        reinterpret_cast<unsigned char *>(static_cast<uintptr_t>(*r5_gs)))[r4_i] = r7_zero;
    r2_arr = *r5_gs;
L_motion_adv:                                    // 0x19c328
    // 0x19c328: e5963000  ldr r3, [r6]          ; gridcount RELOAD (a destructor may have written it)
    // 0x19c32c: e2844001  add r4, r4, #1
    // 0x19c330: e1530004  cmp r3, r4
    // 0x19c334: cafffff1  bgt 0x19c300          ; signed: loop while gridcount > i
    r3_cnt = static_cast<int32_t>(*r6_gc);
    r4_i = r4_i + 1u;
    if (r3_cnt > static_cast<int32_t>(r4_i)) goto L_motion_loop;
L_motion_free:                                   // 0x19c338
    // 0x19c338: e1a00002  mov r0, r2            ; r2 = last-reloaded gridstruct (0x19c324) or the head load (0x19c2d8)
    // 0x19c33c: eb037fe3  bl _ZN13MemoryManager4FreeEPKv  ; real edge: recovered Free
    MemoryManager::Free(reinterpret_cast<const void *>(static_cast<uintptr_t>(r2_arr)));
    // 0x19c340: e3a03000  mov r3, #0
    // 0x19c344: e5853000  str r3, [r5]          ; gridstruct = 0
    // 0x19c348: e5863000  str r3, [r6]          ; gridcount = 0
    // 0x19c34c: e8bd80f8  pop {r3, r4, r5, r6, r7, pc}
    *r5_gs = 0u;
    *r6_gc = 0u;
    return;
    // 0x19c350..0x19c358: literal pool (0x002543dc, 0x002543c4)
}
