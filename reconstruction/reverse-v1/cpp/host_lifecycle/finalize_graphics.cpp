/* tier: bytecode_anchored. Static recovery of three dynsym teardown
 * functions from original image libyoyo_armv7.so (ARMv7 ELF32), SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * (per gc-finalize-anchors/bindings.json, batch9_functions). Parent-direct
 * recovery after the dispatcher channels went down (dht quota, dahetao
 * deepseek channels, jing channel, google-free hang); census files were
 * parent-generated from the pinned image and re-read in full before this
 * translation unit was written.
 *
 * Windows (dynsym va+size; code span / literal pool recorded per census):
 *   _Z25FINALIZE_Graphics_Displayv 0x17dbb8, 20B  5 words, no pool
 *   _Z25FINALIZE_Graphics_Texturev 0x1767cc, 4B   1 word, no pool
 *   _Z22FINALIZE_Graphics_Textv    0x1738fc, 72B  code 0x1738fc..0x17393c,
 *                                                  pool 0x17393c..0x173944
 *
 * These three are callees of the already-recovered Quit@0x2a27fc teardown
 * chain (declarations come from host_lifecycle/quit_runtime.hpp). Every
 * callee edge in this slice is extern-only (DisplayReset 0x17dba0/156B,
 * InvalidateOGLResources 0x17daa8/84B, DeleteOGLResources 0x17dafc/16B,
 * GR_Texture_End 0x1740e0/280B, GR_Text_ResetToDefault 0x173884/120B --
 * NO stubs). The Graphics_Text GOT-delta pair was parent-verified:
 * ldr r4,[pc,#0x30] @0x173904 reads pool 0x17393c = 0x0027c988 and
 * ldr r4,[pc,r4] @0x17390c (pc base 0x173914) reaches slot 0x3f029c ->
 * 0x48ffd8 Graphics_Text::deffont; the identical-delta pair @0x173908/
 * 0x173910 (pc base 0x173918) reaches slot 0x3f02a0 -> 0x499330
 * g_pDebugFont; both R_ARM_RELATIVE (23) verified in-image, both named
 * dynsym objects, so the named-extern representation applies (no anon
 * arrays in this slice).
 *
 * gap: all five callee bodies and the producers/writers of deffont and
 * g_pDebugFont are outside the recovered set; the class behind the
 * [vtable+4] indirect destruct edge at 0x17392c is unidentified (the
 * indirect call is reproduced raw, no stub); EHABI unwind records of the
 * originals are not recovered (compiled objects carry compiler EHABI and
 * reference __aeabi_unwind_cpp_pr0, a final-link obligation); concurrency
 * and the final linked addresses of every slot stay unproved; nothing was
 * executed, loaded or emulated, and no equivalence-by-execution or
 * instruction-sequence equivalence is claimed -- address comments mark
 * where each recovered operation sits in the original, in original order.
 */

#include "quit_runtime.hpp" // FINALIZE_Graphics_* declarations + teardown chain decls

/* Extern-only teardown callees, declared from dynsym identity; bodies are
 * outside the recovered set and NO stub is provided for any of them. */
void DisplayReset();                              // _Z12DisplayResetv, 0x17dba0, 156B
void InvalidateOGLResources();                    // _Z22InvalidateOGLResourcesv, 0x17daa8, 84B
void DeleteOGLResources();                        // _Z18DeleteOGLResourcesv, 0x17dafc, 16B
void GR_Texture_End();                            // _Z14GR_Texture_Endv, 0x1740e0, 280B
void GR_Text_ResetToDefault();                    // _Z22GR_Text_ResetToDefaultv, 0x173884, 120B

/* Named dynsym object reached through GOT slot 0x3f029c (R_ARM_RELATIVE
 * verified): class-static, pointer-shaped word at 0x48ffd8. Declared not
 * defined; the final link must supply it at its dynsym address. Class kept
 * TU-local until a second consumer exists. */
class Graphics_Text {
public:
    static void *volatile deffont;                // _ZN13Graphics_Text7deffontE, 0x48ffd8, 4B
};

/* Named dynsym object reached through GOT slot 0x3f02a0 (R_ARM_RELATIVE
 * verified): raw 4B word at 0x499330, zeroed unconditionally at 0x173918. */
extern "C" void *volatile g_pDebugFont;           // 0x499330, 4B

void FINALIZE_Graphics_Display() { // _Z25FINALIZE_Graphics_Displayv @0x17dbb8
    /* 0x17dbb8 e92d4008 push {r3, lr}
     * 0x17dbbc ebfffff7 bl 0x17dba0 <_Z12DisplayResetv>
     * 0x17dbc0 ebffffb8 bl 0x17daa8 <_Z22InvalidateOGLResourcesv>
     * 0x17dbc4 e8bd4008 pop {r3, lr}
     * 0x17dbc8 eaffffcb b 0x17dafc <_Z18DeleteOGLResourcesv> (tail branch) */
    DisplayReset();
    InvalidateOGLResources();
    DeleteOGLResources();
}

void FINALIZE_Graphics_Texture() { // _Z25FINALIZE_Graphics_Texturev @0x1767cc
    /* 0x1767cc: eafff643 b 0x1740e0 <_Z14GR_Texture_Endv> -- the entire
     * 4B body is ONE tail branch into GR_Texture_End (not bx lr; recorded
     * exactly as the image has it). */
    GR_Texture_End();
}

void FINALIZE_Graphics_Text() { // _Z22FINALIZE_Graphics_Textv @0x1738fc
    /* 0x1738fc e92d4038 push {r3, r4, r5, lr}; 0x173900 mov r5, #0
     * 0x173904 ldr r4, [pc, #0x30] ; pool 0x17393c = 0x0027c988
     * 0x173908 ldr r3, [pc, #0x30] ; pool 0x173940 = 0x0027c988
     * 0x17390c ldr r4, [pc, r4]    ; pc 0x173914 + delta -> GOT 0x3f029c
     * 0x173910 ldr r3, [pc, r3]    ; pc 0x173918 + delta -> GOT 0x3f02a0 */
    void *obj = Graphics_Text::deffont;          /* 0x173914 ldr r0, [r4] : single
                                                  * live load feeding both the
                                                  * guard and the destruct edge */
    g_pDebugFont = nullptr;                      /* 0x173918 str r5, [r3] : unconditional
                                                  * zero-store of g_pDebugFont */
    /* 0x17391c cmp r0, r5 ; 0x173920 beq 0x173934 */
    if (obj != nullptr) {
        /* 0x173924 ldr r3, [r0]        ; object vtable pointer
         * 0x173928 ldr r3, [r3, #0x4]  ; vtable word +4
         * 0x17392c e12fff33 blx r3     ; INDIRECT virtual-style call; target
         *                              ; unresolved (no dynsym identity), no stub */
        reinterpret_cast<void (*)(void *)>(reinterpret_cast<uint32_t *>(obj)[1])(obj);
        /* 0x173930 str r5, [r4] : zero-store deffont after the destruct */
        Graphics_Text::deffont = nullptr;
    }
    /* 0x173934 e8bd4038 pop {r3, r4, r5, lr}
     * 0x173938 eaffffd1 b 0x173884 <_Z22GR_Text_ResetToDefaultv> (tail branch)
     * 0x17393c..0x173944: literal pool (0x0027c988 twice) */
    GR_Text_ResetToDefault();
}
