/* tier: bytecode_anchored. Static recovery of four dynsym teardown
 * functions from original image libyoyo_armv7.so (ARMv7 ELF32), SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * (per gc-finalize-anchors/bindings.json, batch8_functions).
 *
 * Windows (authoritative census: the finalize-*.asm.txt files under
 * gc-finalize-anchors; independently re-disassembled from the pinned image
 * with llvm-objdump and found byte-identical; code span / literal pool as
 * recorded there):
 *   _Z21FINALIZE_Sprite_Classv    0x1ee76c, 4B    code 0x1ee76c..0x1ee770
 *   _Z20FINALIZE_Sprite_Mainv     0x1ef514, 148B  code 0x1ef514..0x1ef59c,
 *                                                 pool 0x1ef59c..0x1ef5a8
 *   _Z18FINALIZE_Font_Mainv       0x0face8, 16B   code 0x0face8..0x0facf8
 *   _Z22FINALIZE_VertexFormatsv   0x1e3180, 296B  code 0x1e3180..0x1e32a0,
 *                                                 pool 0x1e32a0..0x1e32a8
 *
 * These four are callees of the already-recovered Quit@0x2a27fc teardown
 * chain (declarations come from host_lifecycle/quit_runtime.hpp).
 * Real links in this slice:
 *   bl _ZN13MemoryManager4FreeEPKv -- RECOVERED/DEFINED in the cumulative
 *     set; referenced through the canonical class declaration in
 *     vm_buffer/vm_buffer.hpp, reached via memory_manager/memory_internal.hpp.
 *     Call sites: Sprite_Main 0x1ef554 (per-element) and 0x1ef578 (array
 *     tail, may pass NULL by census shape); VertexFormats 0x1e3258 (per
 *     chain node, frees the node itself). No stub, no shadow prototype.
 *   bl _ZdlPv -- RECOVERED/DEFINED in the cumulative set (global operator
 *     delete, declared in vm_buffer/vm_buffer.hpp, defined in
 *     memory_manager/memory_operators.cpp). One call site, VertexFormats
 *     0x1e3250, freeing the RAW [node+0xc] word with NO null test before
 *     the call (census shape; an empty ::operator delete body makes the
 *     NULL case a no-op -- that property is a claim about the RECOVERED
 *     definition, not re-proved here).
 * NOT recovered, extern-only declarations, no stubs -- and NOTE a
 * correction against the dispatch context, which labeled these UND: every
 * one is dynsym-DEFINED in .text of the pinned image (shndx=8), like the
 * Room_Free@0x1b5044 precedent in batch7:
 *   _Z19Sprite_FreeTexturesv 0x1eee30, 84B   (bl 0x1ef584)
 *   _Z11Sprite_Freev         0x1eed3c, 148B  (tail b 0x1ef58c, after pop)
 *   _Z17Font_FreeTexturesv   0xfac94, 84B    (bl 0xfacec)
 *   _Z9Font_Initv            0xf9fb4, 288B   (tail b 0xfacf4, after pop)
 *   _ZN8Graphics5FlushEv     0x1852ec, 300B  (bl 0x1e3184)
 *   _Z16FreeVertexFormatP12VertexFormat 0x185640, 28B (bl 0x1e31d4)
 *
 * Slot resolution (each pc-relative pair verified against .rel.dyn of the
 * pinned image). DEVIATION from the prescribed R_ARM_RELATIVE pattern: all
 * four slots carry R_ARM_COPY (type 23, symidx 0); the in-slot word is the
 * pre-linked .bss target address, and each target matches a NAMED dynsym
 * GLOBAL OBJECT exactly, so all four resolve to named externs and NO anon
 * arrays are needed in this batch:
 *   Sprite_Main  pool 0x1ef59c/0x1ef5a0 + add  -> slot 0x3f0e18 ->
 *                0x7530d8 g_NumberOfSprites (OBJECT, 4B)
 *   Sprite_Main  pool 0x1ef5a4                  -> slot 0x3f0e14 ->
 *                0x7530dc g_SpriteNames (OBJECT, 4B, pointer-shaped word)
 *   VertexFmt    pool 0x1e32a0 (ldr [pc,r6])    -> slot 0x3f0da4 ->
 *                0x544ca0 g_vertexformats (OBJECT, 12B = dynsym size;
 *                words [+0] array pointer, [+4] count, [+8] live-node
 *                counter -- widths from the observed accesses, source-level
 *                type unproven)
 *   VertexFmt    pool 0x1e32a4 (ldr [pc,r3])    -> slot 0x3f0da0 ->
 *                0x544c9c g_lastVF (OBJECT, 4B)
 * The named declarations below carry only the dynsym identity and the
 * observed access widths; volatile mirrors the per-iteration reloads the
 * census performs inside the loops; it is not a claim about the original's
 * spelling. None of these objects is defined here; the final link must
 * place them at the dynsym-encoded addresses.
 *
 * gap: the producers/writers of the named words are outside these windows
 * and unproven here -- who allocates/fills the g_SpriteNames array and
 * sets g_NumberOfSprites, who allocates/fills the g_vertexformats array
 * (8B entries) and the chain nodes reached through it (observed shape:
 * node+0x4 next-pointer, node+0xc VertexFormat-style pointer; entry
 * stride 8; meanings unproven), and what writes g_lastVF. Sprite_Free /
 * Sprite_FreeTextures / Font_FreeTextures / Font_Init / Graphics::Flush /
 * FreeVertexFormat are unrecovered, so what FINALIZE_Sprite_Main,
 * FINALIZE_Font_Main and FINALIZE_VertexFormats actually release beyond
 * the enumerated Free/operator delete/FreeVertexFormat edges is unproven.
 * NOTE (deviation from the dispatch context, recorded in notes.json): the
 * context described FINALIZE_Sprite_Main as tail-branching "Sprite_Free
 * (UND), tail-b VertexFormats? (census decides exact edges)"; the
 * authoritative census and a direct llvm-objdump of the pinned image both
 * show ONE tail edge, b _Z11Sprite_Freev at 0x1ef58c (after the pop), and
 * NO edge into FINALIZE_VertexFormats from this window. FINALIZE_Font_Main
 * tail-branches to Font_Init (0xf9fb4): a FINALIZE calling an INIT looks
 * odd at the source level, but the image is authoritative and the body
 * below records exactly that. EHABI details (unwind tables, .ARM.exidx
 * entries) of the originals are not recovered; the compiled objects carry
 * the compiler's own EHABI, not the original's. Concurrency: whether these
 * finalizers ran under any lock is unproved (Graphics::Flush runs first in
 * FINALIZE_VertexFormats, which hints at a render-thread quiesce, but the
 * flush body is unrecovered). Final linked addresses (the four R_ARM_COPY
 * slot bindings above) hold only if the final link honors the placement
 * comments. Nothing in this file was executed; no instruction-sequence or
 * behavior equivalence to the original image is claimed -- instruction-
 * address comments mark where each recovered operation sits in the
 * original, in original order. Register mirrors carry the census register
 * roles (declared up front so the reproduced gotos cross no
 * initialization); all bgt/bge/blt/ble/blt-after-cmp-0 compares are
 * SIGNED per the census, and the cmn/bne sentinel at 0x1e327c is an
 * equality test against -1. Internal b/bxx edges are reproduced as
 * labels, not flattened -- including the first-entry b 0x1e31a4 that
 * SKIPS the bottom test at 0x1e319c (array[0] is examined even when the
 * count is 0) and the 0x1e3298 count-reload-then-b join into the release
 * phase.
 */

#include "../memory_manager/memory_internal.hpp" /* canonical MemoryManager incl. Free; vm_buffer.hpp incl. operator delete */
#include "quit_runtime.hpp"                      /* FINALIZE_* declarations (0x1ee76c/0x1ef514/0xface8/0x1e3180) */

/* Named dynsym OBJECTs behind the resolved GOT copy slots (resolution
 * table in the header comment). Declarations only -- no definitions, no
 * stubs; the final link must place each at its dynsym address. */
extern "C" volatile uint32_t g_NumberOfSprites;    // 0x7530d8, 4B; via R_ARM_RELATIVE GOT slot 0x3f0e18 (type re-verified in-image; worker comment said COPY); content type unproven (raw word)
extern "C" volatile uint32_t g_SpriteNames;        // 0x7530dc, 4B; via R_ARM_RELATIVE GOT slot 0x3f0e14 (type re-verified in-image); pointer-shaped word (array base)
extern "C" volatile uint32_t g_vertexformats[3];   // 0x544ca0, 12B (dynsym size); via R_ARM_RELATIVE GOT slot 0x3f0da4 (type re-verified in-image); [+0] array pointer word, [+4] count word, [+8] live-node counter word
extern "C" volatile uint32_t g_lastVF;             // 0x544c9c, 4B; via R_ARM_RELATIVE GOT slot 0x3f0da0 (type re-verified in-image); pointer-shaped word

/* Extern-only declarations for the dynsym-defined, unrecovered callees
 * (identities and windows in the header comment). Each mangled name is
 * exactly the census bl/b target. No stubs, no bodies. */
void Sprite_FreeTextures();                        // 0x1eee30, 84B, DEFINED in .text
void Sprite_Free();                                // 0x1eed3c, 148B, DEFINED in .text
void Font_FreeTextures();                          // 0xfac94, 84B, DEFINED in .text
void Font_Init();                                  // 0xf9fb4, 288B, DEFINED in .text
struct VertexFormat;                               // forward-only; class identity/layout unproven (name from the mangled _Z16FreeVertexFormatP12VertexFormat)
void FreeVertexFormat(VertexFormat *);             // 0x185640, 28B, DEFINED in .text
class Graphics {
public:
    static void Flush();                           // 0x1852ec, 300B, DEFINED in .text; static because the census bl sets up no argument (this-pointer presence unproven -- a static spelling reproduces the observed _ZN8Graphics5FlushEv identity)
};

/* _Z21FINALIZE_Sprite_Classv, 0x1ee76c, size 4. Census confirmed against the
 * pinned image: exactly one instruction word e12fff1e (bx lr) -- the original
 * body is EMPTY, matching the dispatch-context "likely single bx lr" guess.
 * Recorded as an immediate-return function; nothing is invented. */
void FINALIZE_Sprite_Class() {
    // 0x1ee76c: e12fff1e  bx lr -- immediate return, empty body
}

/* _Z20FINALIZE_Sprite_Mainv, 0x1ef514, size 148: code 0x1ef514..0x1ef598,
 * literal pool 0x1ef59c..0x1ef5a4 (0x00202730 / 0xfffff1c0 / 0xfffff1bc).
 * Mirrors the sprite-name teardown:
 *   count = g_NumberOfSprites; if count <= 0 (SIGNED), still reload the
 *   array word and fall into the tail;
 *   else i=0: reload-free loop over g_SpriteNames entries --
 *     element = [g_SpriteNames + 4*i] (base from 0x1ef544 first, from the
 *     0x1ef560 reload after each free; the back edge 0x1ef570 targets
 *     0x1ef548, so 0x1ef544 runs once);
 *     non-null element: bl Free(element), then null the slot THROUGH A
 *     RELOADED base (0x1ef558/0x1ef55c) and reload the base (0x1ef560);
 *     null element: skip both (beq 0x1ef564) -- the base is NOT reloaded
 *     on that path, so the next iteration indexes the stale base;
 *     count is RELOADED from g_NumberOfSprites every iteration (0x1ef564);
 *   tail: Free(last-reloaded base -- possibly NULL: on the count<=0 path it
 *   is the [0x3f0e14]-target word itself), g_SpriteNames = 0, bl
 *   Sprite_FreeTextures, pop, TAIL b Sprite_Free (the only tail edge; see
 *   header: no edge into FINALIZE_VertexFormats). */
void FINALIZE_Sprite_Main() {
    // 0x1ef514: e92d40f8  push {r3, r4, r5, r6, r7, lr}
    // 0x1ef518: e59f307c  ldr r3, [pc, #0x7c]   ; pool 0x1ef59c = 0x00202730
    // 0x1ef51c: e59f207c  ldr r2, [pc, #0x7c]   ; pool 0x1ef5a0 = 0xfffff1c0 (signed -0xE40)
    // 0x1ef520: e08f3003  add r3, pc, r3        ; r3 = 0x1ef528 + 0x202730 = 0x3f1c58
    // 0x1ef524: e7936002  ldr r6, [r3, r2]      ; r6 = [GOT copy-slot 0x3f0e18] -> &g_NumberOfSprites (0x7530d8)
    // 0x1ef528: e5962000  ldr r2, [r6]          ; r2 = g_NumberOfSprites
    // 0x1ef52c: e3520000  cmp r2, #0
    // 0x1ef530: e59f206c  ldr r2, [pc, #0x6c]   ; pool 0x1ef5a4 = 0xfffff1bc (signed -0xE44 -> slot 0x3f0e14; constant in C)
    // 0x1ef534: da000015  ble 0x1ef590          ; signed: count <= 0 -> skip the loop, still run the tail
    volatile uint32_t *r6_cnt = &g_NumberOfSprites;
    volatile uint32_t *r5_names = &g_SpriteNames;  // [0x3f1c58 - 0xE44] = [GOT copy-slot 0x3f0e14] -> &g_SpriteNames (0x7530dc)
    uint32_t r2_cnt = 0u;                          // count mirror (0x1ef528)
    uint32_t r2_arr = 0u;                          // array base word (loaded through r5)
    uint32_t r3_base = 0u;                         // base reload at 0x1ef558
    uint32_t r0_elem = 0u;                         // element word (0x1ef548)
    uint32_t r4_i = 0u;                            // element index
    uint32_t r7_zero = 0u;                         // null store value (0x1ef540: r7 = r4 = 0)
    int32_t r3_cnt = 0;                            // count reload (0x1ef564)
    r2_cnt = *r6_cnt;
    if (static_cast<int32_t>(r2_cnt) <= 0) {
        // 0x1ef590: e7935002  ldr r5, [r3, r2]  ; r5 = &g_SpriteNames (same address materialized on both paths)
        // 0x1ef594: e5952000  ldr r2, [r5]      ; r2 = g_SpriteNames (may be NULL -> Free(NULL) below)
        r2_arr = *r5_names;
        goto L_sprite_tail;                        // 0x1ef598: eafffff5  b 0x1ef574
    }
    // 0x1ef538: e7935002  ldr r5, [r3, r2]      ; r5 = &g_SpriteNames
    // 0x1ef53c: e3a04000  mov r4, #0
    // 0x1ef540: e1a07004  mov r7, r4            ; r7 = 0 (null store value)
    r4_i = 0u;
    r7_zero = 0u;
    // 0x1ef544: e5952000  ldr r2, [r5]          ; base -- FIRST ITERATION ONLY (back edge 0x1ef570 lands at 0x1ef548)
    r2_arr = *r5_names;
L_sprite_loop:                                     // 0x1ef548
    // 0x1ef548: e7920104  ldr r0, [r2, r4, lsl #2]  ; element = base[i]
    // 0x1ef54c: e3500000  cmp r0, #0
    // 0x1ef550: 0a000003  beq 0x1ef564          ; null element -> skip Free AND slot-nulling, keep stale base
    r0_elem = reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r2_arr))[r4_i];
    if (r0_elem != 0u) {
        // 0x1ef554: eb02335d  bl _ZN13MemoryManager4FreeEPKv  ; real edge: recovered Free
        MemoryManager::Free(reinterpret_cast<const void *>(static_cast<uintptr_t>(r0_elem)));
        // 0x1ef558: e5953000  ldr r3, [r5]          ; base RELOAD
        // 0x1ef55c: e7837104  str r7, [r3, r4, lsl #2]  ; null the slot through the reloaded base
        // 0x1ef560: e5952000  ldr r2, [r5]          ; base RELOAD (feeds next index + tail Free)
        r3_base = *r5_names;
        reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r3_base))[r4_i] = r7_zero;
        r2_arr = *r5_names;
    }
    // 0x1ef564: e5963000  ldr r3, [r6]          ; count RELOAD (a Free may have moved it -- reproduced)
    // 0x1ef568: e2844001  add r4, r4, #1
    // 0x1ef56c: e1530004  cmp r3, r4
    // 0x1ef570: cafffff4  bgt 0x1ef548          ; signed: loop while count > i
    r3_cnt = static_cast<int32_t>(*r6_cnt);
    r4_i = r4_i + 1u;
    if (r3_cnt > static_cast<int32_t>(r4_i)) goto L_sprite_loop;
L_sprite_tail:                                     // 0x1ef574
    // 0x1ef574: e1a00002  mov r0, r2            ; last-reloaded base (or 0x1ef544 value on a stale-base exit, or the 0x1ef594 value on the count<=0 path)
    // 0x1ef578: eb023354  bl _ZN13MemoryManager4FreeEPKv  ; real edge: recovered Free (NULL argument possible by census shape)
    MemoryManager::Free(reinterpret_cast<const void *>(static_cast<uintptr_t>(r2_arr)));
    // 0x1ef57c: e3a03000  mov r3, #0
    // 0x1ef580: e5853000  str r3, [r5]          ; g_SpriteNames = 0
    *r5_names = 0u;
    // 0x1ef584: ebfffe29  bl _Z19Sprite_FreeTexturesv  ; extern-only edge, no stub (0x1eee30 unrecovered)
    Sprite_FreeTextures();
    // 0x1ef588: e8bd40f8  pop {r3, r4, r5, r6, r7, lr}
    // 0x1ef58c: eafffdea  b _Z11Sprite_Freev    ; TAIL branch after the pop; extern-only (0x1eed3c unrecovered). THE ONLY tail edge.
    Sprite_Free();
    // 0x1ef59c..0x1ef5a4: literal pool (0x00202730, 0xfffff1c0, 0xfffff1bc)
}

/* _Z18FINALIZE_Font_Mainv, 0xface8, size 16: code 0xface8..0xfacf8, no pool.
 * bl Font_FreeTextures, pop, then a TAIL BRANCH to Font_Init@0xf9fb4
 * (288B, dynsym-DEFINED in .text, unrecovered). A FINALIZE naming an Init
 * call looks odd at the source level; the census and the pinned image are
 * byte-identical on this window, and the image is authoritative -- recorded
 * exactly as the image behaves, with no claim about why. */
void FINALIZE_Font_Main() {
    // 0xface8: e92d4008  push {r3, lr}
    // 0xfacec: ebffffe8  bl _Z17Font_FreeTexturesv  ; extern-only edge, no stub (0xfac94 unrecovered)
    Font_FreeTextures();
    // 0xfacf0: e8bd4008  pop {r3, lr}
    // 0xfacf4: eafffcae  b _Z9Font_Initv          ; TAIL BRANCH TO FONT_INIT after the pop; extern-only edge, no stub (0xf9fb4 unrecovered)
    Font_Init();
}

/* _Z22FINALIZE_VERTEXFORMATSv, 0x1e3180, size 296: code 0x1e3180..0x1e3294,
 * literal pool 0x1e3298..0x1e32a4... (pool words 0x0020dc0c / 0x0020db0c at
 * 0x1e32a0/0x1e32a4; the word at 0x1e3298 is an INSTRUCTION -- beq landing
 * code, not pool data).
 * Phase structure, faithfully reproduced including every reload:
 *   0. bl Graphics::Flush (extern-only edge); GOT pair -> r6 =
 *      &g_vertexformats; r2 = [+0] array, r8 = [+4] count. FIRST ENTRY
 *      (0x1e3198 b 0x1e31a4) SKIPS the bottom test 0x1e319c -- entry 0 is
 *      touched even when count is 0/negative (a negative r8 makes the
 *      later blt/cmp pair walk nothing).
 *   1. Chain-walk phase (0x1e31a4..0x1e3218): node = array[i] (word [0] of
 *      the 8B entry, base as of the last 0x1e3194/0x1e31f4 load). Null
 *      node -> bottom test (count < i+1 -> release). Non-null: node+0xc
 *      is the VertexFormat-style pointer -- if 0, straight to release
 *      (0x1e31c4, WITHOUT reloading the count); else bl
 *      FreeVertexFormat(node+0xc), advance to node+4; at each chain step
 *      a null node+0xc (0x1e31d0 beq) goes to 0x1e3298: reload count,
 *      join release. When a chain ends (node+4 == 0): reload count,
 *      i' = saved+1; if i' > count (SIGNED) -> release; else reload base,
 *      PEEK loop at 0x1e31fc reads array[j]+0 for j = saved+1, saved+2,
 *      ... (each non-null peeked node re-enters the chain walk at
 *      0x1e31c8; the saved index r5 and byte cursor r2 advance per
 *      peek). No entry slot is nulled in phase 1 -- only phase 2 stores
 *      zeroes.
 *   2. Release phase (0x1e321c..0x1e3280): if count >= 0, walk byte
 *      offset r7 = count*8 DOWN to 0 (loop-until cmn -1): per entry,
 *      base RELOADED from [r6] (0x1e322c), word0 -> node, both words
 *      zeroed ([r3+r7]=0 then [r2+4]=0 -- the second store is
 *      UNCONDITIONAL, executing even for null nodes, at the reloaded
 *      base). Non-null node: inner chain -- next = node+4, fmt = node+0xc
 *      (NO null test), bl _ZdlPv (REAL link: operator delete(fmt)),
 *      bl Free(node) (REAL link: MemoryManager::Free on the node word
 *      itself), then live-counter g_vertexformats[+8] = reload-1 AFTER
 *      both frees, node = next, loop while next != 0.
 *   3. Tail (0x1e3284..): second GOT pair -> r3 = &g_lastVF; g_lastVF = 0;
 *      pop. All compares signed per the census. */
void FINALIZE_VertexFormats() {
    // 0x1e3180: e92d43f8  push {r3, r4, r5, r6, r7, r8, r9, lr}
    // 0x1e3184: ebfe8858  bl _ZN8Graphics5FlushEv  ; extern-only edge, no stub (0x1852ec unrecovered); no argument set up at the site
    Graphics::Flush();
    // 0x1e3188: e3a03000  mov r3, #0            ; i
    // 0x1e318c: e59f610c  ldr r6, [pc, #0x10c]  ; pool 0x1e32a0 = 0x0020dc0c
    // 0x1e3190: e79f6006  ldr r6, [pc, r6]      ; pc 0x1e3198 + 0x20dc0c -> GOT copy-slot 0x3f0da4 -> &g_vertexformats (0x544ca0)
    // 0x1e3194: e8960104  ldm r6, {r2, r8}      ; r2 = g_vertexformats[0] array, r8 = g_vertexformats[4] count
    // 0x1e3198: ea000001  b 0x1e31a4            ; first entry SKIPS the bottom test (0x1e319c)
    volatile uint32_t *r6_vf = &g_vertexformats[0];
    uint32_t r3_i = 0u;                          // index / phase-2 scratch (0x1e3188)
    uint32_t r2_arr = 0u;                        // array base word (0x1e3194/0x1e31f4 loads)
    uint32_t r8_cnt = 0u;                        // count word (0x1e3194/0x1e31e4/0x1e3298 loads)
    uint32_t r4_node = 0u;                       // chain-node word
    uint32_t r5_idx = 0u;                        // saved entry index
    uint32_t r0_fmt = 0u;                        // node+0xc pointer word
    uint32_t r7_off = 0u;                        // phase-2 byte offset (count*8, down to 0)
    uint32_t r9_zero = 0u;                       // phase-2 null store value
    uint32_t r3_base = 0u;                       // phase-2 reloaded array base
    uint32_t r2_byt = 0u;                        // byte-address cursor mirror (0x1e31f8/0x1e3204/0x1e3230)
    uint32_t r3_live = 0u;                       // live-counter word (0x1e325c/0x1e3268)
    r2_arr = r6_vf[0];
    r8_cnt = r6_vf[4];
    goto L_vf_entry;
L_vf_next:                                       // 0x1e319c
    // 0x1e319c: e1580003  cmp r8, r3
    // 0x1e31a0: ba00001d  blt 0x1e321c          ; signed: count < i -> release
    if (static_cast<int32_t>(r8_cnt) < static_cast<int32_t>(r3_i)) goto L_vf_release;
L_vf_entry:                                      // 0x1e31a4
    // 0x1e31a4: e7924183  ldr r4, [r2, r3, lsl #3]  ; node = array[i] (8B entries)
    // 0x1e31a8: e1a05003  mov r5, r3            ; save i
    // 0x1e31ac: e2833001  add r3, r3, #1        ; i++ BEFORE the tests
    // 0x1e31b0: e3540000  cmp r4, #0
    // 0x1e31b4: 0afffff8  beq 0x1e319c          ; null node -> bottom test
    r4_node = reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r2_arr))[r3_i * 2u];
    r5_idx = r3_i;
    r3_i = r3_i + 1u;
    if (r4_node == 0u) goto L_vf_next;
    // 0x1e31b8: e594000c  ldr r0, [r4, #0xc]
    // 0x1e31bc: e3500000  cmp r0, #0
    // 0x1e31c0: 1a000003  bne 0x1e31d4
    // 0x1e31c4: ea000014  b 0x1e321c            ; head node+0xc == 0 -> release WITHOUT reloading the count
    r0_fmt = reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r4_node))[3u];
    if (r0_fmt != 0u) goto L_vf_freefmt;         // 0x1e31c0: bne 0x1e31d4 (explicit edge, not a fall-through)
    goto L_vf_release;                           // 0x1e31c4: b 0x1e321c
L_vf_chainload:                                  // 0x1e31c8
    // 0x1e31c8: e594000c  ldr r0, [r4, #0xc]
    // 0x1e31cc: e3500000  cmp r0, #0
    // 0x1e31d0: 0a000030  beq 0x1e3298          ; chain node with null format -> reload count (0x1e3298) -> release
    r0_fmt = reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r4_node))[3u];
    if (r0_fmt == 0u) {
        // 0x1e3298: e5968004  ldr r8, [r6, #0x4]  ; count RELOAD
        // 0x1e329c: eaffffde  b 0x1e321c          ; join release
        r8_cnt = r6_vf[4];
        goto L_vf_release;
    }
L_vf_freefmt:                                    // 0x1e31d4
    // 0x1e31d4: ebfe8919  bl _Z16FreeVertexFormatP12VertexFormat  ; extern-only edge, no stub (0x185640 unrecovered)
    FreeVertexFormat(reinterpret_cast<VertexFormat *>(static_cast<uintptr_t>(r0_fmt)));
    // 0x1e31d8: e5944004  ldr r4, [r4, #0x4]    ; next chain node
    // 0x1e31dc: e3540000  cmp r4, #0
    // 0x1e31e0: 1afffff8  bne 0x1e31c8          ; chain walk
    r4_node = reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r4_node))[1u];
    if (r4_node != 0u) goto L_vf_chainload;
    // 0x1e31e4: e5968004  ldr r8, [r6, #0x4]    ; count RELOAD
    // 0x1e31e8: e2853001  add r3, r5, #1        ; r3 = saved + 1
    // 0x1e31ec: e1530008  cmp r3, r8
    // 0x1e31f0: ca000009  bgt 0x1e321c          ; signed: saved+1 > count -> release
    // 0x1e31f4: e5962000  ldr r2, [r6]          ; base RELOAD
    // 0x1e31f8: e0822185  add r2, r2, r5, lsl #3  ; r2 = &entry[saved]
    r8_cnt = r6_vf[4];
    r3_i = r5_idx + 1u;
    if (static_cast<int32_t>(r3_i) > static_cast<int32_t>(r8_cnt)) goto L_vf_release;
    r2_arr = r6_vf[0];
    r2_byt = r2_arr + r5_idx * 8u;
L_vf_peek:                                       // 0x1e31fc
    // 0x1e31fc: e5924008  ldr r4, [r2, #0x8]    ; NEXT entry's node word (cursor at &entry[saved], reads +8)
    // 0x1e3200: e1a05003  mov r5, r3
    // 0x1e3204: e2822008  add r2, r2, #8        ; cursor advance
    // 0x1e3208: e2833001  add r3, r3, #1
    // 0x1e320c: e3540000  cmp r4, #0
    // 0x1e3210: 1affffec  bne 0x1e31c8          ; non-null peeked node -> re-enter the chain walk
    // 0x1e3214: e1530008  cmp r3, r8
    // 0x1e3218: dafffff7  ble 0x1e31fc          ; signed: keep peeking while i <= count
    //          ; else fall through to 0x1e321c   (release)
    r4_node = reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r2_byt))[2u];
    r5_idx = r3_i;
    r2_byt = r2_byt + 8u;
    r3_i = r3_i + 1u;
    if (r4_node != 0u) goto L_vf_chainload;
    if (static_cast<int32_t>(r3_i) <= static_cast<int32_t>(r8_cnt)) goto L_vf_peek;
L_vf_release:                                    // 0x1e321c
    // 0x1e321c: e3580000  cmp r8, #0
    // 0x1e3220: a1a07188  lslge r7, r8, #3      ; r8 >= 0: r7 = count*8 (byte offset of the last entry)
    // 0x1e3224: a3a09000  movge r9, #0          ; r9 = 0 (null store value)
    // 0x1e3228: ba000015  blt 0x1e3284          ; signed: count < 0 -> tail
    if (static_cast<int32_t>(r8_cnt) < 0) goto L_vf_tail;
    r7_off = r8_cnt * 8u;
    r9_zero = 0u;
L_vf_outer:                                      // 0x1e322c
    // 0x1e322c: e5963000  ldr r3, [r6]          ; base RELOAD per entry
    // 0x1e3230: e0832007  add r2, r3, r7        ; slot byte address
    // 0x1e3234: e7934007  ldr r4, [r3, r7]      ; node = base[r7]
    // 0x1e3238: e7839007  str r9, [r3, r7]      ; base[r7] = 0
    // 0x1e323c: e3540000  cmp r4, #0            ; flags live ACROSS the next str
    // 0x1e3240: e5829004  str r9, [r2, #0x4]    ; slot+4 = 0 -- UNCONDITIONAL (null node still writes)
    // 0x1e3244: 0a00000a  beq 0x1e3274          ; null node -> entry decrement
    r3_base = r6_vf[0];
    r2_byt = r3_base + r7_off;
    r4_node = reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r3_base))[r7_off / 4u];
    reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r3_base))[r7_off / 4u] = r9_zero;
    reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r2_byt))[1u] = r9_zero;
    if (r4_node == 0u) goto L_vf_decrement;
L_vf_inner:                                      // 0x1e3248
    // 0x1e3248: e5945004  ldr r5, [r4, #0x4]    ; next chain node
    // 0x1e324c: e594000c  ldr r0, [r4, #0xc]    ; format pointer -- NO null test
    // 0x1e3250: eb0267de  bl _ZdlPv             ; real edge: explicit ::operator delete (recovered 0x27d1d0)
    // 0x1e3254: e1a00004  mov r0, r4
    // 0x1e3258: eb02641c  bl _ZN13MemoryManager4FreeEPKv  ; real edge: recovered Free on the node itself
    // 0x1e325c: e5963008  ldr r3, [r6, #0x8]    ; live counter RELOAD after both frees
    // 0x1e3260: e3550000  cmp r5, #0            ; flags live across mov/sub/str
    // 0x1e3264: e1a04005  mov r4, r5
    // 0x1e3268: e2433001  sub r3, r3, #1
    // 0x1e326c: e5863008  str r3, [r6, #0x8]    ; live counter store per node
    // 0x1e3270: 1afffff4  bne 0x1e3248          ; chain loop
    r5_idx = reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r4_node))[1u];
    r0_fmt = reinterpret_cast<volatile uint32_t *>(static_cast<uintptr_t>(r4_node))[3u];
    operator delete(reinterpret_cast<void *>(static_cast<uintptr_t>(r0_fmt)));
    MemoryManager::Free(reinterpret_cast<const void *>(static_cast<uintptr_t>(r4_node)));
    r3_live = r6_vf[2];
    r4_node = r5_idx;
    r6_vf[2] = r3_live - 1u;
    if (r5_idx != 0u) goto L_vf_inner;
L_vf_decrement:                                  // 0x1e3274
    // 0x1e3274: e2488001  sub r8, r8, #1
    // 0x1e3278: e2477008  sub r7, r7, #8
    // 0x1e327c: e3780001  cmn r8, #1
    // 0x1e3280: 1affffe9  bne 0x1e322c          ; walk DOWN until r8 == -1 (entries count-1..0)
    r8_cnt = r8_cnt - 1u;
    r7_off = r7_off - 8u;
    if (static_cast<int32_t>(r8_cnt) != -1) goto L_vf_outer;
L_vf_tail:                                       // 0x1e3284
    // 0x1e3284: e59f3018  ldr r3, [pc, #0x18]   ; pool 0x1e32a4 = 0x0020db0c
    // 0x1e3288: e3a02000  mov r2, #0
    // 0x1e328c: e79f3003  ldr r3, [pc, r3]      ; pc 0x1e3294 + 0x20db0c -> GOT copy-slot 0x3f0da0 -> &g_lastVF (0x544c9c)
    // 0x1e3290: e5832000  str r2, [r3]          ; g_lastVF = 0
    g_lastVF = 0u;
    // 0x1e3294: e8bd83f8  pop {r3, r4, r5, r6, r7, r8, r9, pc}
    // 0x1e3298: e5968004  ldr r8, [r6, #0x4]    ; beq 0x1e31d0 landing code (instruction, not pool)
    // 0x1e329c: eaffffde  b 0x1e321c
    // 0x1e32a0..0x1e32a4: literal pool (0x0020dc0c, 0x0020db0c)
}
