/* tier: bytecode_anchored. Static recovery of four dynsym teardown
 * functions from original image libyoyo_armv7.so (ARMv7 ELF32), SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * (per gc-finalize-anchors/bindings.json, batch6_functions).
 *
 * Windows (authoritative census: the finalize-*.asm.txt files under
 * gc-finalize-anchors; code span / literal pool as recorded there):
 *   _Z23FINALIZE_Instance_Classv  0x1959f4, 436B  code 0x1959f4..0x195ba0,
 *                                                 literal 0x195ba4..0x195ba8
 *   _Z21FINALIZE_Object_Listsv    0x19e884, 132B  code 0x19e884..0x19e8fc,
 *                                                 pool 0x19e900..0x19e908
 *   _Z20FINALIZE_Object_Mainv     0x19f0c0, 348B  code 0x19f0c0..0x19f210,
 *                                                 pool 0x19f214..0x19f21c
 *   _Z21FINALIZE_Object_Classv    0x19e1c8, 4B    code 0x19e1c8..0x19e1c8
 *
 * These four are callees of the already-recovered Quit@0x2a27fc teardown
 * chain (declarations come from host_lifecycle/quit_runtime.hpp).
 * Real links in this slice:
 *   bl _ZN13MemoryManager4FreeEPKv -- RECOVERED/DEFINED in the cumulative
 *     set; referenced through the canonical class declaration in
 *     vm_buffer/vm_buffer.hpp, reached via memory_manager/memory_internal.hpp.
 *     No stub, no shadow prototype.
 *   bl _ZdlPv -- reproduced as the explicit call form ::operator delete(p)
 *     (declared in vm_buffer/vm_buffer.hpp at 0x27d1d0); no delete-expression.
 *   bl _ZN9CObjectGMD2Ev -- NOT recovered: extern-only declaration, no stub.
 *     A canonical CObjectGM declaration was checked for in the frozen seam
 *     tree (grep CObjectGM across ccode/ccode.hpp and object_base/): none
 *     exists, so a fallback minimal class carries the dynsym identity and
 *     the call site binds the exact mangled name through an extern "C"
 *     declaration (see the D1-vs-D2 note in notes.json).
 *   blx [vtable+4] -- two indirect (virtual-style) call sites inside
 *     FINALIZE_Instance_Class at 0x195ac4 and 0x195b64. Targets unresolved;
 *     reproduced as raw indirect calls with the exact slot path.
 *
 * Anonymous-slot resolution (each ldr [pc,#n] / ldr [pc,rX] pair, verified
 * against .rel.dyn in the original image):
 *   FINALIZE_Instance_Class literal 0x00258244 (0x195ba4) -> word at 0x3f3c4c
 *     (.data, NO R_ARM_RELATIVE backing; the file image there is packed
 *     string bytes, so the table pointer it holds is written at runtime by an
 *     unidentified producer -- slot does not resolve to a static target).
 *   FINALIZE_Object_Listsv literal 0x0025127c -> GOT 0x3efb14, R_ARM_RELATIVE,
 *     resolves to 0x53ab70 (.bss): 30720B bucket-descriptor table.
 *   FINALIZE_Object_Listsv literal 0x00251e00 -> GOT 0x3f06e8, R_ARM_RELATIVE,
 *     resolves to 0x536f68 (.bss): only word +4 is touched here.
 *   FINALIZE_Object_Mainv literal 0x0024eb6c -> GOT 0x3edc44, R_ARM_RELATIVE,
 *     resolves to 0x542374 (.bss): container-pointer word.
 *   FINALIZE_Object_Mainv literal 0x00251610 -> GOT 0x3f06ec, R_ARM_RELATIVE,
 *     resolves to 0x542370 (.bss): flag word cleared at the function head.
 * None of the five resolves onto a named dynsym OBJECT symbol (checked
 * against all 2243 OBJECT entries). They are represented per the prescribed
 * rule as extern "C" unsigned char arrays, left UNDEFINED in this
 * translation unit: no storage definition, no invented original names. The
 * final link must place them at the addresses encoded in their names.
 *
 * gap: the producers/writers of the five anonymous words are outside these
 * windows and unproven here -- notably 0x3f3c4c (whose pointed-to table
 * {buckets, mask, live count} is constructed somewhere unrecorded) and the
 * object type behind the two blx [vtable+4] sites (payload +0x78 key field,
 * payload class identity). The allocating producers of the chained nodes,
 * the meaning of the two-pass structure in FINALIZE_Object_Mainv (pass two
 * re-reads the same container and normally finds it drained), the
 * significance of the r8 = -1 sentinel paths in FINALIZE_Instance_Classv,
 * and why FINALIZE_Object_Classv is empty while its siblings free
 * registries, are all unproven. EHABI details (unwind tables, .ARM.exidx
 * entries) of the originals are not recovered; the compiled objects carry
 * the compiler's own EHABI, not the original's. Concurrency: whether these
 * finalizers ran under any lock is unproved. Final linked addresses (the
 * GOT/word bindings above, and every literal-to-anon resolution) hold only
 * if the final link honors the placement comments below. Nothing in this
 * file was executed; no instruction-sequence or behavior equivalence to the
 * original image is claimed -- instruction-address comments mark where each
 * recovered operation sits in the original, in original order. Register
 * mirrors carry the census register names (declared up front so the
 * reproduced gotos cross no initialization; mirror names keep the
 * instruction-window suffix, e.g. r7_mask = the r7 value after 0x195a04).
 * Internal b/bxx edges are reproduced as labels, not flattened -- including
 * the 0x19f210 tail-b into this_function+0x134, an internal branch, not a
 * tail call, and the four separate edges into 0x195a28 / the two edges into
 * 0x195a4c of FINALIZE_Instance_Classv.
 */

#include "../memory_manager/memory_internal.hpp" /* canonical MemoryManager incl. Free; operator delete */
#include "quit_runtime.hpp"                      /* FINALIZE_* declarations (0x1959f4/0x19e884/0x19f0c0/0x19e1c8) */

/* Prescribed anonymous-BSS/.data representation. Each declaration binds the
 * final-link placement requirement; none is defined here. */
extern "C" unsigned char anon_0x3f3c4c[4];     // final link must place at 0x3f3c4c, 4B, .data; direct pc-relative word, NO R_ARM_RELATIVE; pointer value written at runtime
extern "C" unsigned char anon_0x53ab70[30720]; // final link must place at 0x53ab70, 30720B, R_ARM_RELATIVE GOT slot 0x3efb14
extern "C" unsigned char anon_0x536f68[8];     // final link must place at 0x536f68, >=8B (only word +4 touched), R_ARM_RELATIVE GOT slot 0x3f06e8; total extent unproven
extern "C" unsigned char anon_0x542370[4];     // final link must place at 0x542370, 4B, R_ARM_RELATIVE GOT slot 0x3f06ec
extern "C" unsigned char anon_0x542374[4];     // final link must place at 0x542374, 4B, R_ARM_RELATIVE GOT slot 0x3edc44

/* _ZN9CObjectGMD2Ev is NOT in the recovered set. Canonical CObjectGM
 * declaration checked for in the seam tree (grep CObjectGM across ccode/
 * and object_base/): none exists, so the fallback minimal extern-only class
 * below carries the dynsym identity. NOTE (deviation recorded in
 * notes.json): an explicit p->~CObjectGM() on this class emits a D1
 * (complete-object) reference, while the census bl edge names D2
 * (base-object). In the ORIGINAL the two are folded aliases at 0x19d558
 * (dynsym shows _ZN9CObjectGMD1Ev and D2 at the same value), so both are
 * address-identical; the call site still binds the exact census symbol name
 * through the extern "C" declaration below. No stub, no body. */
class CObjectGM {
public:
    ~CObjectGM();                                 // 0x19d558 _ZN9CObjectGMD2Ev (dynsym identity only)
};
extern "C" void _ZN9CObjectGMD2Ev(void *self);    // exact mangled edge: bl target at 0x19f128/0x19f1b4

/* _Z21FINALIZE_Object_Classv, 0x19e1c8, size 4. Census shows exactly one
 * instruction word e12fff1e (bx lr): the original body is EMPTY. Recorded as
 * an immediate-return function; nothing is invented. */
void FINALIZE_Object_Class() {
    // 0x19e1c8: e12fff1e  bx lr -- immediate return, empty body
}

/* _Z21FINALIZE_Object_Listsv, 0x19e884, size 132: code 0x19e884..0x19e8fc,
 * literal pool 0x19e900..0x19e908 holding 0x0025127c / 0x00251e00.
 * Table at 0x53ab70: 15 blocks x 256 descriptors of 8B {+0 count, +4 ptr};
 * a descriptor's ptr is freed only when its count is > 0 (signed test).
 * Second structure at 0x536f68: ptr at +4 freed once, slot +4 zeroed (+0
 * is NOT touched). */
void FINALIZE_Object_Lists() {
    // 0x19e884: e92d41f0  push {r4, r5, r6, r7, r8, lr}
    // 0x19e888: e3a07000  mov r7, #0            ; shared zero value (r7)
    const uint32_t zero = 0u;                    // r7 mirror
    // 0x19e88c: e59f606c  ldr r6, [pc, #0x6c]   ; pool 0x19e900 = 0x0025127c -> GOT 0x3efb14
    // 0x19e890: e79f6006  ldr r6, [pc, r6]      ; R_ARM_RELATIVE resolves to 0x53ab70
    uint32_t *r6_lists = reinterpret_cast<uint32_t *>(anon_0x53ab70);
    // 0x19e894: e2868b1e  add r8, r6, #30720    ; end pointer (15 blocks)
    uint32_t *r8_end = reinterpret_cast<uint32_t *>(
        reinterpret_cast<unsigned char *>(r6_lists) + 30720);
    uint32_t r4_idx = 0u;                        // 0x19e898: e3a04000 mov r4, #0
    uint32_t *r5_desc = nullptr;
    uint32_t r0_ptr = 0u;
L_lists_outer:                                   // 0x19e89c head (reached by 0x19e8cc and 0x19e8d8 bne)
    // 0x19e89c: e0865004  add r5, r6, r4
    r5_desc = reinterpret_cast<uint32_t *>(
        reinterpret_cast<unsigned char *>(r6_lists) + r4_idx);
    // 0x19e8a0: e5950004  ldr r0, [r5, #0x4]    ; descriptor ptr (+4)
    r0_ptr = r5_desc[1];
    // 0x19e8a4: e3500000  cmp r0, #0
    // 0x19e8a8: 0a000005  beq 0x19e8c4
    if (r0_ptr == 0u) goto L_lists_next;
    // 0x19e8ac: e7963004  ldr r3, [r6, r4]      ; descriptor count (+0)
    // 0x19e8b0: e3530000  cmp r3, #0
    // 0x19e8b4: da000002  ble 0x19e8c4          ; signed <= 0 skips the free
    if (static_cast<int32_t>(r6_lists[r4_idx / 4u]) <= 0) goto L_lists_next;
    // 0x19e8b8: eb037684  bl _ZN13MemoryManager4FreeEPKv  ; real edge: recovered Free
    MemoryManager::Free(reinterpret_cast<const void *>(r0_ptr));
    // 0x19e8bc: e5857004  str r7, [r5, #0x4]    ; clear descriptor ptr
    // 0x19e8c0: e7867004  str r7, [r6, r4]      ; clear descriptor count
    r5_desc[1] = zero;
    r6_lists[r4_idx / 4u] = zero;
L_lists_next:                                    // 0x19e8c4
    // 0x19e8c4: e2844008  add r4, r4, #8
    r4_idx += 8u;
    // 0x19e8c8: e3540b02  cmp r4, #2048
    // 0x19e8cc: 1afffff2  bne 0x19e89c
    if (r4_idx != 2048u) goto L_lists_outer;
    // 0x19e8d0: e2866b02  add r6, r6, #2048
    r6_lists = reinterpret_cast<uint32_t *>(reinterpret_cast<unsigned char *>(r6_lists) + 2048);
    // 0x19e8d4: e1560008  cmp r6, r8
    // 0x19e8d8: 1affffee  bne 0x19e89c          ; r4 resets per block; 15 blocks total
    if (r6_lists != r8_end) goto L_lists_outer;
    // 0x19e8dc: e59f4020  ldr r4, [pc, #0x20]   ; pool 0x19e904 = 0x00251e00 -> GOT 0x3f06e8
    // 0x19e8e0: e79f4004  ldr r4, [pc, r4]      ; R_ARM_RELATIVE resolves to 0x536f68
    uint32_t *r4_single = reinterpret_cast<uint32_t *>(anon_0x536f68);
    // 0x19e8e4: e5940004  ldr r0, [r4, #0x4]
    r0_ptr = r4_single[1];
    // 0x19e8e8: e3500000  cmp r0, #0
    // 0x19e8ec: 08bd81f0  popeq {r4, r5, r6, r7, r8, pc}
    if (r0_ptr == 0u) return;                    // 0x19e8ec tail (popeq)
    // 0x19e8f0: eb037676  bl _ZN13MemoryManager4FreeEPKv  ; real edge: recovered Free
    MemoryManager::Free(reinterpret_cast<const void *>(r0_ptr));
    // 0x19e8f4: e3a03000  mov r3, #0
    // 0x19e8f8: e5843004  str r3, [r4, #0x4]    ; clear +4 only; +0 untouched
    r4_single[1] = 0u;
    // 0x19e8fc: e8bd81f0  pop {r4, r5, r6, r7, r8, pc}
    return;
    // 0x19e900..0x19e908: literal pool (0x0025127c, 0x00251e00)
}

/* _Z20FINALIZE_Object_Mainv, 0x19f0c0, size 348: code 0x19f0c0..0x19f210,
 * literal pool 0x19f214..0x19f21c holding 0x0024eb6c / 0x00251610.
 * Two passes over the container C = *[GOT 0x3edc44] = word at 0x542374:
 * C = {+0 array of 8B bucket pairs {head, tail}, +4 count, +8 live counter};
 * each bucket chain node N {+4 next, +0xc CObjectGM*} gets
 * N->obj->~CObjectGM(); ::operator delete(N->obj); MemoryManager::Free(N);
 * and C+8 decrements per node freed. The word at 0x542370 is zeroed at the
 * function head. The final step frees the array (Free) and the container
 * itself (::operator delete), then stores 0 through the GOT-resolved word.
 * The 0x19f210 b 0x19f1f4 edge is an INTERNAL branch inside this function,
 * reproduced as a label, NOT a tail call. */
void FINALIZE_Object_Main() {
    // 0x19f0c0: e92d4ff8  push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    // 0x19f0c4: e3a0b000  mov r11, #0           ; shared zero value (r11)
    const uint32_t zero = 0u;                    // r11 mirror
    // 0x19f0c8: e59f8144  ldr r8, [pc, #0x144]  ; pool 0x19f214 = 0x0024eb6c -> GOT 0x3edc44
    // 0x19f0cc: e59f3144  ldr r3, [pc, #0x144]  ; pool 0x19f218 = 0x00251610 -> GOT 0x3f06ec
    // 0x19f0d0: e79f8008  ldr r8, [pc, r8]      ; R_ARM_RELATIVE resolves to 0x542374
    // 0x19f0d4: e79f3003  ldr r3, [pc, r3]      ; R_ARM_RELATIVE resolves to 0x542370
    uint32_t *r8_word = reinterpret_cast<uint32_t *>(anon_0x542374);
    uint32_t *r3_flag = reinterpret_cast<uint32_t *>(anon_0x542370);
    // 0x19f0d8: e5987000  ldr r7, [r8]          ; container C = *0x542374
    uint32_t *r7_C = reinterpret_cast<uint32_t *>(*r8_word);
    int32_t r10_count = 0;                       // mirror decls hoisted above every branch
    uint32_t r9_off = 0u;
    uint32_t *r3_arr = nullptr;                  // pass-1 array base
    uint32_t *r2_slot = nullptr;
    uint32_t *r4_node = nullptr;
    uint32_t *r5_obj = nullptr;
    uint32_t *r6_next = nullptr;
    uint32_t *r0_arr = nullptr;                  // pass-2 / drain array base
    uint32_t *r_free0 = nullptr;                 // the r0 argument across the Free bl
    // 0x19f0dc: e583b000  str r11, [r3]         ; zero *0x542370
    *r3_flag = zero;
    // 0x19f0e0: e157000b  cmp r7, r11
    // 0x19f0e4: 0a000045  beq 0x19f200
    if (r7_C == nullptr) goto L_main_clearret;
    // 0x19f0e8: e597a004  ldr r10, [r7, #0x4]   ; count
    r10_count = static_cast<int32_t>(r7_C[1]);
    // 0x19f0ec: e15a000b  cmp r10, r11
    // 0x19f0f0: ba000045  blt 0x19f20c          ; signed: negative count -> drain without walking
    if (r10_count < 0) goto L_main_negcount;
    // 0x19f0f4: e1a0918a  lsl r9, r10, #3       ; byte offset = count*8
    r9_off = static_cast<uint32_t>(r10_count) << 3;
L_main_slot:                                     // 0x19f0f8 (reached via 0x19f160 bne, base reloaded each pass)
    // 0x19f0f8: e5973000  ldr r3, [r7]          ; array base
    r3_arr = reinterpret_cast<uint32_t *>(r7_C[0]);
    // 0x19f0fc: e0832009  add r2, r3, r9
    r2_slot = reinterpret_cast<uint32_t *>(reinterpret_cast<unsigned char *>(r3_arr) + r9_off);
    // 0x19f100: e7934009  ldr r4, [r3, r9]      ; bucket head
    r4_node = reinterpret_cast<uint32_t *>(*r2_slot);
    // 0x19f104: e783b009  str r11, [r3, r9]     ; head = 0
    *r2_slot = zero;
    // 0x19f108: e3540000  cmp r4, #0
    // 0x19f10c: e582b004  str r11, [r2, #0x4]   ; tail = 0 (store sits between the two tests)
    r2_slot[1] = zero;
    // 0x19f110: 0a00000f  beq 0x19f154
    if (r4_node == nullptr) goto L_main_advance;
L_main_chain:                                    // 0x19f114
    // 0x19f114: e594500c  ldr r5, [r4, #0xc]    ; obj = node+0xc
    // 0x19f118: e5946004  ldr r6, [r4, #0x4]    ; next = node+4
    r5_obj = reinterpret_cast<uint32_t *>(r4_node[3]);
    r6_next = reinterpret_cast<uint32_t *>(r4_node[1]);
    // 0x19f11c: e3550000  cmp r5, #0
    // 0x19f120: e1a00005  mov r0, r5
    // 0x19f124: 0a000002  beq 0x19f134
    if (r5_obj != nullptr) {
        // 0x19f128: ebfff90a  bl _ZN9CObjectGMD2Ev ; extern dtor edge, no stub (unrecovered)
        _ZN9CObjectGMD2Ev(r5_obj);
        // 0x19f12c: e1a00005  mov r0, r5
        // 0x19f130: eb037826  bl _ZdlPv           ; explicit operator delete call form
        ::operator delete(r5_obj);
    }
    // 0x19f134: e1a00004  mov r0, r4            ; node moves to r0 BEFORE r4 := r6
    // 0x19f138: e1a04006  mov r4, r6
    r_free0 = r4_node;
    r4_node = r6_next;
    // 0x19f13c: eb037463  bl _ZN13MemoryManager4FreeEPKv  ; Free(OLD node); real edge
    MemoryManager::Free(reinterpret_cast<const void *>(r_free0));
    // 0x19f140: e5973008  ldr r3, [r7, #0x8]    ; live counter
    // 0x19f144: e3560000  cmp r6, #0
    // 0x19f148: e2433001  sub r3, r3, #1
    // 0x19f14c: e5873008  str r3, [r7, #0x8]
    r7_C[2] = r7_C[2] - 1u;
    // 0x19f150: 1affffef  bne 0x19f114
    if (r6_next != nullptr) goto L_main_chain;
L_main_advance:                                  // 0x19f154
    // 0x19f154: e24aa001  sub r10, r10, #1
    // 0x19f158: e2499008  sub r9, r9, #8
    r10_count = r10_count - 1;
    r9_off = r9_off - 8u;
    // 0x19f15c: e37a0001  cmn r10, #1
    // 0x19f160: 1affffe4  bne 0x19f0f8          ; first pass walks indices count..0
    if (r10_count != -1) goto L_main_slot;
    // 0x19f164: e5987000  ldr r7, [r8]          ; SECOND pass: reload container from 0x542374
    r7_C = reinterpret_cast<uint32_t *>(*r8_word);
    // 0x19f168: e3570000  cmp r7, #0
    // 0x19f16c: 0a000023  beq 0x19f200
    if (r7_C == nullptr) goto L_main_clearret;
    // 0x19f170: e597a004  ldr r10, [r7, #0x4]   ; count re-read
    r10_count = static_cast<int32_t>(r7_C[1]);
    // 0x19f174: e35a0000  cmp r10, #0
    // 0x19f178: ba000023  blt 0x19f20c          ; signed negative -> drain
    if (r10_count < 0) goto L_main_negcount;
    // 0x19f17c: e5970000  ldr r0, [r7]          ; array base kept in r0 this pass
    r0_arr = reinterpret_cast<uint32_t *>(r7_C[0]);
    // 0x19f180: e1a0918a  lsl r9, r10, #3
    r9_off = static_cast<uint32_t>(r10_count) << 3;
    // 0x19f184: e3a0b000  mov r11, #0           ; zero re-materialized (same value)
L_main_slot2:                                    // 0x19f188
    // 0x19f188: e7904009  ldr r4, [r0, r9]      ; bucket head
    r4_node = reinterpret_cast<uint32_t *>(*reinterpret_cast<uint32_t *>(
        reinterpret_cast<unsigned char *>(r0_arr) + r9_off));
    // 0x19f18c: e0803009  add r3, r0, r9
    r2_slot = reinterpret_cast<uint32_t *>(reinterpret_cast<unsigned char *>(r0_arr) + r9_off);
    // 0x19f190: e780b009  str r11, [r0, r9]     ; head = 0
    *r2_slot = zero;
    // 0x19f194: e3540000  cmp r4, #0
    // 0x19f198: e583b004  str r11, [r3, #0x4]   ; tail = 0
    r2_slot[1] = zero;
    // 0x19f19c: 0a000010  beq 0x19f1e4
    if (r4_node == nullptr) goto L_main_advance2;
L_main_chain2:                                   // 0x19f1a0
    // 0x19f1a0: e594500c  ldr r5, [r4, #0xc]    ; obj
    // 0x19f1a4: e5946004  ldr r6, [r4, #0x4]    ; next
    r5_obj = reinterpret_cast<uint32_t *>(r4_node[3]);
    r6_next = reinterpret_cast<uint32_t *>(r4_node[1]);
    // 0x19f1a8: e3550000  cmp r5, #0
    // 0x19f1ac: e1a00005  mov r0, r5
    // 0x19f1b0: 0a000002  beq 0x19f1c0
    if (r5_obj != nullptr) {
        // 0x19f1b4: ebfff8e7  bl _ZN9CObjectGMD2Ev ; extern dtor edge, no stub (unrecovered)
        _ZN9CObjectGMD2Ev(r5_obj);
        // 0x19f1b8: e1a00005  mov r0, r5
        // 0x19f1bc: eb037803  bl _ZdlPv           ; explicit operator delete call form
        ::operator delete(r5_obj);
    }
    // 0x19f1c0: e1a00004  mov r0, r4            ; node moves to r0 BEFORE r4 := r6
    // 0x19f1c4: e1a04006  mov r4, r6
    r_free0 = r4_node;
    r4_node = r6_next;
    // 0x19f1c8: eb037440  bl _ZN13MemoryManager4FreeEPKv  ; Free(OLD node); real edge
    MemoryManager::Free(reinterpret_cast<const void *>(r_free0));
    // 0x19f1cc: e5973008  ldr r3, [r7, #0x8]    ; live counter
    // 0x19f1d0: e2433001  sub r3, r3, #1
    // 0x19f1d4: e3560000  cmp r6, #0            ; cmp interleaved between load and store in census
    // 0x19f1d8: e5873008  str r3, [r7, #0x8]
    r7_C[2] = r7_C[2] - 1u;
    // 0x19f1dc: 1affffef  bne 0x19f1a0
    if (r6_next != nullptr) goto L_main_chain2;
    // 0x19f1e0: e5970000  ldr r0, [r7]          ; reload array base after chain drain
    r0_arr = reinterpret_cast<uint32_t *>(r7_C[0]);
L_main_advance2:                                 // 0x19f1e4
    // 0x19f1e4: e24aa001  sub r10, r10, #1
    // 0x19f1e8: e2499008  sub r9, r9, #8
    r10_count = r10_count - 1;
    r9_off = r9_off - 8u;
    // 0x19f1ec: e37a0001  cmn r10, #1
    // 0x19f1f0: 1affffe4  bne 0x19f188
    if (r10_count != -1) goto L_main_slot2;
    // fall-through 0x19f1f0 -> 0x19f1f4 with r0 = [r7] from 0x19f1e0 (or 0x19f184 path)
L_main_negcount:                                 // 0x19f20c (reached from either blt edge)
    // 0x19f20c: e5970000  ldr r0, [r7]          ; array base
    r0_arr = reinterpret_cast<uint32_t *>(r7_C[0]);
    // fall-through into 0x19f1f4; the 0x19f210 b 0x19f1f4 internal-branch target
    // is this same drain block (r0 = [r7] in both arrivals, so no separate label)
    // 0x19f1f4: eb037435  bl _ZN13MemoryManager4FreeEPKv  ; Free(array base); real edge
    MemoryManager::Free(reinterpret_cast<const void *>(r0_arr));
    // 0x19f1f8: e1a00007  mov r0, r7
    // 0x19f1fc: eb0377f3  bl _ZdlPv             ; ::operator delete(container); explicit call form
    ::operator delete(r7_C);
L_main_clearret:                                 // 0x19f200
    // 0x19f200: e3a03000  mov r3, #0
    // 0x19f204: e5883000  str r3, [r8]          ; *0x542374 = 0
    *r8_word = 0u;
    // 0x19f208: e8bd8ff8  pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    return;
    // 0x19f210: eafffff7  b 0x19f1f4            ; folded into the L_main_negcount fall-through above (r0 = [r7] in both)
    // 0x19f214..0x19f21c: literal pool (0x0024eb6c, 0x00251610)
}

/* _Z23FINALIZE_Instance_Classv, 0x1959f4, size 436: code 0x1959f4..0x195ba0,
 * literal word 0x195ba4..0x195ba8 (0x00258244). The ldr pair reads the word
 * at 0x3f3c4c (.data, no R_ARM_RELATIVE backing): a runtime-written pointer
 * to the table T = {+0 bucket array (8B entries {head, tail}), +4 mask,
 * +8 live count}. For every scanned chain node N {+4 next, +0xc payload},
 * key = payload->[+0x78] is hashed (mask & key) to locate the matching
 * entry E {+0 prev, +4 next, +8 key, +0xc payload} in the doubly-linked
 * bucket, unlink it, invoke payload->[vtable word +4] (blx, indirect),
 * Free(E) and decrement the live count. The chain walk, when a node's +4
 * is NULL, switches to a forward scan of later bucket slots (0x195ae4..)
 * feeding the same unlink site with the SAME stale payload register (0x195b08
 * bne 0x195a4c) -- reproduced register-for-register; unflattened. The two
 * r8 = -1 sentinel edges (0x195b14, 0x195b9c) and the bulk drain at
 * 0x195b1c (sweep slots mask..0, zero the pair, chain-drain: indirect
 * vtable call, Free(node), live-count--) close the function. All index-vs-
 * mask compares are SIGNED per bgt/bge/blt/poplt.
 * Register mirrors declared up front so no goto crosses an initialization;
 * the census r3 register aliases the scan index AND the bucket index at
 * different sites -- split into r3_i / r3_bkt mirrors, noted per site. */
void FINALIZE_Instance_Class() {
    // 0x1959f4: e92d43f8  push {r3, r4, r5, r6, r7, r8, r9, lr}
    // 0x1959f8: e3a03000  mov r3, #0            ; scan index
    uint32_t r3_i = 0u;
    // 0x1959fc: e59f61a0  ldr r6, [pc, #0x1a0]  ; literal 0x195ba4 = 0x00258244 -> word 0x3f3c4c (.data, NO R_ARM_RELATIVE)
    // 0x195a00: e79f6006  ldr r6, [pc, r6]      ; pointer value written at runtime -- content NOT statically resolved (see notes.json)
    uint32_t *r6_T = reinterpret_cast<uint32_t *>(*reinterpret_cast<uint32_t *>(anon_0x3f3c4c));
    // 0x195a04: e8960084  ldm r6, {r2, r7}      ; r2 = T+0 bucket array, r7 = T+4 mask
    uint32_t *r2_arr = reinterpret_cast<uint32_t *>(r6_T[0]);
    int32_t r7_mask = static_cast<int32_t>(r6_T[1]);
    // 0x195a08: ea000001  b 0x195a14            ; first scan check skipped
    uint32_t r8_idx = 0u;                        // 0x195b14/0x195b9c mvn sites set 0xffffffff
    uint32_t *r5_node = nullptr;                 // chain-node cursor / next slot head
    uint32_t *r0_arrb = nullptr;                 // bucket-array base (re-loaded at 0x195a28 from [r6])
    uint32_t *r1_obj = nullptr;                  // payload pointer
    uint32_t *r4_ent = nullptr;                  // hash-table entry cursor
    uint32_t *r12_slot = nullptr;                // bucket slot address
    uint32_t key_r2 = 0u;                        // key word held in r2 (0x195a4c..0x195a84; r2 aliases prev at the unlink)
    uint32_t r3_bkt = 0u;                        // bucket index (r3 aliases the scan index; split mirror)
    uint32_t *r2_prev = nullptr;
    uint32_t *r0_payl = nullptr;
    uint32_t *r1_next = nullptr;
    uint32_t *r3_ptr = nullptr;                  // forward/bulk slot cursor
    uint32_t r2_cand = 0u;                       // candidate index in the forward scan
    uint32_t r9_zero = 0u;                       // bulk-path zero value
    uint32_t *r0_free = nullptr;                 // the r0 argument across the bulk Free bl
    goto L_inst_scan;                            // 0x195a08 b 0x195a14
L_inst_checkidx:                                 // 0x195a0c
    // 0x195a0c: e1530007  cmp r3, r7
    // 0x195a10: ca000061  bgt 0x195b9c          ; signed index-vs-mask test
    if (static_cast<int32_t>(r3_i) > r7_mask) goto L_inst_over;
L_inst_scan:                                     // 0x195a14
    // 0x195a14: e1a08003  mov r8, r3
    // 0x195a18: e2833001  add r3, r3, #1
    r8_idx = r3_i;
    r3_i = r3_i + 1u;
    // 0x195a1c: e7925188  ldr r5, [r2, r8, lsl #3]  ; bucket head at slot r8
    r5_node = reinterpret_cast<uint32_t *>(r2_arr[r8_idx * 2u]);
    // 0x195a20: e3550000  cmp r5, #0
    // 0x195a24: 0afffff8  beq 0x195a0c          ; empty slot -> index check
    if (r5_node == nullptr) goto L_inst_checkidx;
L_inst_body:                                     // 0x195a28 -- four separate edges arrive here: 0x195a60, 0x195a74, 0x195ae0 b, 0x195b9c b (kept as one shared label, like the original)
    // 0x195a28: e5960000  ldr r0, [r6]          ; reload bucket-array base from T+0
    r0_arrb = reinterpret_cast<uint32_t *>(r6_T[0]);
    // 0x195a2c: e3550000  cmp r5, #0
    // 0x195a30: 0a000039  beq 0x195b1c          ; null node -> bulk drain
    if (r5_node == nullptr) goto L_inst_bulk;
    // 0x195a34: e595100c  ldr r1, [r5, #0xc]    ; payload
    r1_obj = reinterpret_cast<uint32_t *>(r5_node[3]);
    // 0x195a38: e3510000  cmp r1, #0
    // 0x195a3c: 0a000036  beq 0x195b1c          ; null payload -> bulk drain
    if (r1_obj == nullptr) goto L_inst_bulk;
    // 0x195a40: e5955004  ldr r5, [r5, #0x4]    ; next node
    r5_node = reinterpret_cast<uint32_t *>(r5_node[1]);
    // 0x195a44: e3550000  cmp r5, #0
    // 0x195a48: 0a000025  beq 0x195ae4          ; chain done -> forward slot scan
    if (r5_node == nullptr) goto L_inst_fwdscan;
L_inst_unlink:                                   // 0x195a4c -- also entered from 0x195b08, 0x195b10 b and 0x195b18 b with the r1 payload register STALE by census design; preserved
    // 0x195a4c: e5912078  ldr r2, [r1, #0x78]   ; key word at payload+0x78
    key_r2 = r1_obj[30u];
    // 0x195a50: e0073002  and r3, r7, r2        ; bucket index = mask & key
    r3_bkt = static_cast<uint32_t>(r7_mask) & key_r2;
    // 0x195a54: e7904183  ldr r4, [r0, r3, lsl #3]  ; bucket head
    r4_ent = reinterpret_cast<uint32_t *>(r0_arrb[r3_bkt * 2u]);
    // 0x195a58: e080c183  add r12, r0, r3, lsl #3   ; slot address
    r12_slot = reinterpret_cast<uint32_t *>(reinterpret_cast<unsigned char *>(r0_arrb) + r3_bkt * 8u);
    // 0x195a5c: e3540000  cmp r4, #0
    // 0x195a60: 0afffff1  beq 0x195a2c          ; empty bucket -> body re-check of r5
    if (r4_ent == nullptr) goto L_inst_body;
    // 0x195a64: e5941008  ldr r1, [r4, #0x8]    ; entry key
    // 0x195a68: e1520001  cmp r2, r1
    // 0x195a6c: 0a000005  beq 0x195a88          ; match -> unlink
    if (key_r2 == r4_ent[2]) goto L_inst_found;
L_inst_walk:                                     // 0x195a70
    // 0x195a70: e5944004  ldr r4, [r4, #0x4]    ; entry next
    r4_ent = reinterpret_cast<uint32_t *>(r4_ent[1]);
    // 0x195a74: e3540000  cmp r4, #0
    // 0x195a78: 0affffeb  beq 0x195a2c          ; chain exhausted without match -> body (r5 node test)
    if (r4_ent == nullptr) goto L_inst_body;
    // 0x195a7c: e5943008  ldr r3, [r4, #0x8]    ; next entry key
    // 0x195a80: e1520003  cmp r2, r3
    // 0x195a84: 1afffff9  bne 0x195a70
    if (key_r2 != r4_ent[2]) goto L_inst_walk;
L_inst_found:                                    // 0x195a88 -- unlink entry from the doubly-linked bucket {head@slot+0, tail@slot+4}
    // 0x195a88: e5942000  ldr r2, [r4]          ; entry prev (r2 mirror moves to r2_prev)
    // 0x195a8c: e594000c  ldr r0, [r4, #0xc]    ; entry payload
    r2_prev = reinterpret_cast<uint32_t *>(r4_ent[0]);
    r0_payl = reinterpret_cast<uint32_t *>(r4_ent[3]);
    // 0x195a90: e3520000  cmp r2, #0
    // 0x195a94: 15943004  ldrne r3, [r4, #0x4]  ; next (prev path)
    // 0x195a98: 05941004  ldreq r1, [r4, #0x4]  ; next (no-prev path)
    // 0x195a9c: 15823004  strne r3, [r2, #0x4]  ; prev->next = next
    // 0x195aa0: 15941004  ldrne r1, [r4, #0x4]  ; next (prev path, reload)
    // 0x195aa4: 058c1000  streq r1, [r12]       ; head = next (no prev)
    // both predicated paths load the same [r4+4] word into the next register
    r1_next = reinterpret_cast<uint32_t *>(r4_ent[1]);
    if (r2_prev != nullptr) {
        r2_prev[1] = reinterpret_cast<uint32_t>(r1_next);
    } else {
        r12_slot[0] = reinterpret_cast<uint32_t>(r1_next);
    }
    // 0x195aa8: e3510000  cmp r1, #0
    // 0x195aac: 058c2004  streq r2, [r12, #0x4] ; tail = prev (entry was last)
    // 0x195ab0: 15812000  strne r2, [r1]        ; next->prev = prev
    if (r1_next == nullptr) {
        r12_slot[1] = reinterpret_cast<uint32_t>(r2_prev);
    } else {
        r1_next[0] = reinterpret_cast<uint32_t>(r2_prev);
    }
    // 0x195ab4: e3500000  cmp r0, #0
    // 0x195ab8: 0a000002  beq 0x195ac8
    if (r0_payl != nullptr) {
        // 0x195abc: e5903000  ldr r3, [r0]      ; payload vtable pointer
        // 0x195ac0: e5933004  ldr r3, [r3, #0x4] ; vtable word +4
        // 0x195ac4: e12fff33  blx r3            ; INDIRECT virtual-style call; target unresolved (no dynsym identity), no stub
        reinterpret_cast<void (*)(void *)>(reinterpret_cast<uint32_t *>(r0_payl[0])[1])(r0_payl);
    }
    // 0x195ac8: e1a00004  mov r0, r4
    // 0x195acc: eb0399ff  bl _ZN13MemoryManager4FreeEPKv  ; Free(entry); real edge
    MemoryManager::Free(reinterpret_cast<const void *>(r4_ent));
    // 0x195ad0: e5963008  ldr r3, [r6, #0x8]    ; live counter T+8
    // 0x195ad4: e5967004  ldr r7, [r6, #0x4]    ; reload mask T+4
    // 0x195ad8: e2433001  sub r3, r3, #1
    // 0x195adc: e5863008  str r3, [r6, #0x8]
    r6_T[2] = r6_T[2] - 1u;
    r7_mask = static_cast<int32_t>(r6_T[1]);
    // 0x195ae0: eaffffd0  b 0x195a28            ; internal branch back to body
    goto L_inst_body;
L_inst_fwdscan:                                  // 0x195ae4 -- node chain done: scan later slots for the next non-empty head
    // 0x195ae4: e2882001  add r2, r8, #1
    r2_cand = r8_idx + 1u;
    // 0x195ae8: e1520007  cmp r2, r7
    // 0x195aec: ca000008  bgt 0x195b14          ; signed; past mask -> sentinel r8 = -1
    if (static_cast<int32_t>(r2_cand) > r7_mask) goto L_inst_neg1;
    // 0x195af0: e0803188  add r3, r0, r8, lsl #3 ; slot address of the current index
    r3_ptr = reinterpret_cast<uint32_t *>(reinterpret_cast<unsigned char *>(r0_arrb) + r8_idx * 8u);
L_inst_fwdloop:                                  // 0x195af4
    // 0x195af4: e5935008  ldr r5, [r3, #0x8]    ; head of the NEXT slot
    r5_node = reinterpret_cast<uint32_t *>(r3_ptr[2]);
    // 0x195af8: e1a08002  mov r8, r2
    r8_idx = r2_cand;
    // 0x195afc: e2833008  add r3, r3, #8
    r3_ptr = reinterpret_cast<uint32_t *>(reinterpret_cast<unsigned char *>(r3_ptr) + 8u);
    // 0x195b00: e2822001  add r2, r2, #1
    r2_cand = r2_cand + 1u;
    // 0x195b04: e3550000  cmp r5, #0
    // 0x195b08: 1affffcf  bne 0x195a4c          ; non-empty slot -> unlink site with STALE r1 (mirror preserved)
    if (r5_node != nullptr) goto L_inst_unlink;
    // 0x195b0c: e1570002  cmp r7, r2
    // 0x195b10: aafffff7  bge 0x195af4          ; signed: keep scanning while mask >= cand
    if (r7_mask >= static_cast<int32_t>(r2_cand)) goto L_inst_fwdloop;
L_inst_neg1:                                     // 0x195b14 -- ran off the array end
    // 0x195b14: e3e08000  mvn r8, #0            ; r8 = -1
    // 0x195b18: eaffffcb  b 0x195a4c            ; final unlink attempt with stale r1 (internal branch)
    r8_idx = 0xffffffffu;
    goto L_inst_unlink;
L_inst_over:                                     // 0x195b9c -- initial scan passed the mask with r5 == 0
    // 0x195b9c: e3e08000  mvn r8, #0            ; r8 = -1
    // 0x195ba0: eaffffa0  b 0x195a28            ; internal branch (r5 == 0 -> bulk drain)
    r8_idx = 0xffffffffu;
    goto L_inst_body;
L_inst_bulk:                                     // 0x195b1c -- bulk drain, slots mask down to 0
    // 0x195b1c: e3570000  cmp r7, #0
    // 0x195b20: b8bd83f8  poplt {r3, r4, r5, r6, r7, r8, r9, pc}  ; signed mask < 0 -> immediate return
    if (r7_mask < 0) return;
    // 0x195b24: e1a08187  lsl r8, r7, #3        ; byte offset = mask*8
    // 0x195b28: e3a09000  mov r9, #0            ; zero value for the slot stores
    r9_zero = 0u;
    r3_i = static_cast<uint32_t>(r7_mask);       // r7 carries the sweep counter (sub r7,#1 at 0x195b88)
    r8_idx = static_cast<uint32_t>(r7_mask) * 8u;
L_inst_bslot:                                    // 0x195b2c (0x195b94 bne loops back)
    // 0x195b2c: e5963000  ldr r3, [r6]          ; reload array base every slot
    // 0x195b30: e0832008  add r2, r3, r8
    r3_ptr = reinterpret_cast<uint32_t *>(reinterpret_cast<unsigned char *>(
        reinterpret_cast<uint32_t *>(r6_T[0])) + r8_idx);
    // 0x195b34: e7934008  ldr r4, [r3, r8]      ; bucket head
    // 0x195b38: e7839008  str r9, [r3, r8]      ; head = 0
    r4_ent = reinterpret_cast<uint32_t *>(*r3_ptr);
    *r3_ptr = r9_zero;
    // 0x195b3c: e3540000  cmp r4, #0
    // 0x195b40: e5829004  str r9, [r2, #0x4]    ; tail = 0 (store sits between the two tests)
    r3_ptr[1] = r9_zero;
    // 0x195b44: 0a00000f  beq 0x195b88          ; empty bucket -> next slot down
    if (r4_ent == nullptr) goto L_inst_badvance;
L_inst_bchain:                                   // 0x195b48 -- drain this bucket chain
    // 0x195b48: e594300c  ldr r3, [r4, #0xc]    ; payload
    // 0x195b4c: e5945004  ldr r5, [r4, #0x4]    ; next node
    r1_obj = reinterpret_cast<uint32_t *>(r4_ent[3]);
    r5_node = reinterpret_cast<uint32_t *>(r4_ent[1]);
    // 0x195b50: e3530000  cmp r3, #0
    // 0x195b54: e1a00003  mov r0, r3
    // 0x195b58: 0a000002  beq 0x195b68
    if (r1_obj != nullptr) {
        // 0x195b5c: e5933000  ldr r3, [r3]      ; vtable pointer
        // 0x195b60: e5933004  ldr r3, [r3, #0x4] ; vtable word +4
        // 0x195b64: e12fff33  blx r3            ; INDIRECT virtual-style call; target unresolved (no dynsym identity), no stub
        reinterpret_cast<void (*)(void *)>(reinterpret_cast<uint32_t *>(r1_obj[0])[1])(r1_obj);
    }
    // 0x195b68: e1a00004  mov r0, r4            ; node
    // 0x195b6c: e1a04005  mov r4, r5
    r0_free = r4_ent;
    r4_ent = r5_node;
    // 0x195b70: eb0399d6  bl _ZN13MemoryManager4FreeEPKv  ; Free(OLD node); real edge
    MemoryManager::Free(reinterpret_cast<const void *>(r0_free));
    // 0x195b74: e5963008  ldr r3, [r6, #0x8]    ; live counter
    // 0x195b78: e3550000  cmp r5, #0
    // 0x195b7c: e2433001  sub r3, r3, #1
    // 0x195b80: e5863008  str r3, [r6, #0x8]
    r6_T[2] = r6_T[2] - 1u;
    // 0x195b84: 1affffef  bne 0x195b48          ; more chain nodes
    if (r5_node != nullptr) goto L_inst_bchain;
L_inst_badvance:                                 // 0x195b88
    // 0x195b88: e2477001  sub r7, r7, #1
    // 0x195b8c: e2488008  sub r8, r8, #8
    r3_i = r3_i - 1u;
    r8_idx = r8_idx - 8u;
    // 0x195b90: e3770001  cmn r7, #1
    // 0x195b94: 1affffe4  bne 0x195b2c          ; sweep until r7 == -1
    if (r3_i != 0xffffffffu) goto L_inst_bslot;
    // 0x195b98: e8bd83f8  pop {r3, r4, r5, r6, r7, r8, r9, pc}
    return;
    // 0x195ba4..0x195ba8: literal pool (0x00258244 -> word 0x3f3c4c)
}
