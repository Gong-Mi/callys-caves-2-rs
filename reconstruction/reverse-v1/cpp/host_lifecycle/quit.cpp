/* Quit — teardown orchestrator, word-faithful recovery of _Z4Quitv.
 *
 * tier: bytecode_anchored
 * original image: libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * function window: 0x2a27fc..0x2a28ec (240 B: ARM code 0x2a27fc..0x2a28e0,
 * literal pool 0x2a28e0..0x2a28ec, 3 pool words).
 * Intended placement: cpp/host_lifecycle/quit.cpp (seam host_lifecycle dir).
 * Census: gc-object-lifecycle-anchors/quit-caller.asm.txt (60 words).
 * Bindings: gc-quit-seam/quit-bindings.json (42 branch sites + 3 pool words).
 *
 * Pool words are PIC GOT deltas (ldr [pc,#n] then ldr [pc,rn]); this file
 * records each instruction's address in a comment, in original order. The
 * delta/dereference pairs are link-resolved address materializations for
 * three dynsym globals, verified against the original image:
 *   pool@0x2a28e0 0x0014df50 -> GOT slot 0x3f07fc -> 0x542554 g_pMainWindow (size 4)
 *   pool@0x2a28e4 0x0014b2d4 -> GOT slot 0x3edb74 -> 0x757e80 g_Profiler    (size 128)
 *   pool@0x2a28e8 0x0014f1b4 -> GOT slot 0x3f1a80 -> 0x479a2f g_fDoFirstShow (size 1)
 *
 * gap: the producers of g_pMainWindow, g_fDoFirstShow and the CProfiler
 * object state are outside the recovered set; 40 of the 42 branch targets
 * are dynsym-identity declarations only (real recovered bodies in this
 * slice: FreeAllObjects 0xd675c, ResetGC 0xd66e0). Pointee types of the
 * three globals beyond storage width (4/4/1 bytes) are unproven. EHABI
 * unwind tables are outside this recovery; final linked addresses depend
 * on relocations, not on these static-slot arithmetic constants. Nothing
 * here was executed and no equivalence claim is made: this is a static,
 * bytecode-anchored reconstruction. */

#include "quit_runtime.hpp"

/* g_pMainWindow / g_fDoFirstShow are declared by the shared seam header; their GOT slots (0x3f07fc / 0x3f1a80), widths and producers are recorded there. */

void Quit() {
    // 0x2a27fc e92d4010 push {r4, lr}      ; r4 holds the pool delta, then
    //                                        the materialized address of
    //                                        g_pMainWindow; lr for the bl runs
    CleanGestures();                        // 0x2a2800 ebfce49a bl 1dba70 <_Z13CleanGesturesv>
    FreeAllObjects();                       // 0x2a2804 ebf8cfd4 bl d675c <_Z14FreeAllObjectsv>  (real recovered body)
    // 0x2a2808 e59f40d0 ldr r4, [pc, #208] ; pool@0x2a28e0 = 0x0014df50: GOT
    //                                        delta for g_pMainWindow. r4 is
    //                                        AAPCS callee-saved: it survives
    //                                        every bl below unchanged until
    //                                        its second life at 0x2a28a4.
    FreeAllDataStructures();                // 0x2a280c ebfda29a bl 20b27c <_Z21FreeAllDataStructuresv>
    ResetGC();                              // 0x2a2810 ebf8cfb2 bl d66e0 <_Z7ResetGCv>  (real recovered body)
    QuitYoYoFunctions();                    // 0x2a2814 ebfade29 bl 15a0c0 <_Z17QuitYoYoFunctionsv>
    QuitNetworkingFunctions();              // 0x2a2818 ebffdc26 bl 2998b8 <_Z23QuitNetworkingFunctionsv>
    FINALIZE_Score();                       // 0x2a281c ebfce6e6 bl 1dc3bc <_Z14FINALIZE_Scorev>
    FINALIZE_Code_Constant();               // 0x2a2820 ebf93ce2 bl f1bb0 <_Z22FINALIZE_Code_Constantv>
    FINALIZE_Code_Function();               // 0x2a2824 ebf8ae92 bl ce274 <_Z22FINALIZE_Code_Functionv>
    FINALIZE_Code_Main();                   // 0x2a2828 ebf8b312 bl cf478 <_Z18FINALIZE_Code_Mainv>
    FINALIZE_Code_Variable();               // 0x2a282c ebf8bf79 bl d2618 <_Z22FINALIZE_Code_Variablev>
    FINALIZE_Motion_Grid();                 // 0x2a2830 ebfbe6a5 bl 19c2cc <_Z20FINALIZE_Motion_Gridv>
    FINALIZE_Room_Main();                   // 0x2a2834 ebfc4d86 bl 1b5e54 <_Z18FINALIZE_Room_Mainv>
    FINALIZE_Instance_Class();              // 0x2a2838 ebfbcc6d bl 1959f4 <_Z23FINALIZE_Instance_Classv>
    FINALIZE_Run_Main();                    // 0x2a283c ebfcc3e2 bl 1d37cc <_Z17FINALIZE_Run_Mainv>
    FINALIZE_Object_Lists();                // 0x2a2840 ebfbf00f bl 19e884 <_Z21FINALIZE_Object_Listsv>
    FINALIZE_Object_Main();                 // 0x2a2844 ebfbf21d bl 19f0c0 <_Z20FINALIZE_Object_Mainv>
    FINALIZE_Object_Class();                // 0x2a2848 ebfbee5e bl 19e1c8 <_Z21FINALIZE_Object_Classv>
    FINALIZE_Particle_Main();               // 0x2a284c ebfc0d65 bl 1a5de8 <_Z22FINALIZE_Particle_Mainv>
    FINALIZE_Sprite_Class();                // 0x2a2850 ebfd2fc5 bl 1ee76c <_Z21FINALIZE_Sprite_Classv>
    FINALIZE_Sprite_Main();                 // 0x2a2854 ebfd332e bl 1ef514 <_Z20FINALIZE_Sprite_Mainv>
    FINALIZE_Support_File();                // 0x2a2858 ebfdc96d bl 214e14 <_Z21FINALIZE_Support_Filev>
    FINALIZE_VertexFormats();               // 0x2a285c ebfd0247 bl 1e3180 <_Z22FINALIZE_VertexFormatsv>
    FINALIZE_Graphics_Display();            // 0x2a2860 ebfb6cd4 bl 17dbb8 <_Z25FINALIZE_Graphics_Displayv>
    FINALIZE_Background();                  // 0x2a2864 ebf886a2 bl c42f4 <_Z19FINALIZE_Backgroundv>
    FINALIZE_Graphics_Texture();            // 0x2a2868 ebfb4fd7 bl 1767cc <_Z25FINALIZE_Graphics_Texturev>
    FINALIZE_Script_Main();                 // 0x2a286c ebfcf7bf bl 1e0770 <_Z20FINALIZE_Script_Mainv>
    FINALIZE_Variable_Main();               // 0x2a2870 ebfd4926 bl 1f4d10 <_Z22FINALIZE_Variable_Mainv>
    FINALIZE_Font_Main();                   // 0x2a2874 ebf9611b bl face8 <_Z18FINALIZE_Font_Mainv>
    FINALIZE_Graphics_Text();               // 0x2a2878 ebfb441f bl 1738fc <_Z22FINALIZE_Graphics_Textv>
    FINALIZE_Event_Action();                // 0x2a287c ebf94106 bl f2c9c <_Z21FINALIZE_Event_Actionv>
    FINALIZE_Function_File();               // 0x2a2880 ebfa699f bl 13cf04 <_Z22FINALIZE_Function_Filev>
    FINALIZE_Timeline_Main();               // 0x2a2884 ebfd423a bl 1f3174 <_Z22FINALIZE_Timeline_Mainv>
    FINALIZE_Runner_Form();                 // 0x2a2888 ebfcf41f bl 1df90c <_Z20FINALIZE_Runner_Formv>
    FINALIZE_Sound();                       // 0x2a288c ebfdf302 bl 21f49c <_Z14FINALIZE_Soundv>
    FINALIZE_All();                         // 0x2a2890 ebf887d8 bl c47f8 <_Z12FINALIZE_Allv>
    // 0x2a2894 e59f0048 ldr r0, [pc, #72]  ; pool@0x2a28e4 = 0x0014b2d4: GOT delta for g_Profiler
    // 0x2a2898 e79f0000 ldr r0, [pc, r0]   ; GOT slot 0x3edb74 -> 0x757e80 = &g_Profiler
    //                                        (dynsym size 128: the inline
    //                                        object itself, not a pointer
    //                                        variable — receiver setup is
    //                                        exactly this-call's this pointer)
    g_Profiler.Clean();                     // 0x2a289c ebfff6b0 bl 2a0364 <_ZN9CProfiler5CleanEv>
    GR_D3D_End();                           // 0x2a28a0 ebfb18fa bl 168c90 <_Z10GR_D3D_Endv>
    // 0x2a28a4 e79f4004 ldr r4, [pc, r4]   ; pool@0x2a28e0 delta + PC -> GOT
    //                                        slot 0x3f07fc -> 0x542554: r4
    //                                        becomes &g_pMainWindow. This is
    //                                        r4's only consumer site.
    // 0x2a28a8 e5940000 ldr r0, [r4]       ; single load of g_pMainWindow,
    // 0x2a28ac e3500000 cmp r0, #0         ;   test, and beq:
    // 0x2a28b0 0a000006 beq 0x2a28d0       ; NULL handle -> skip destroy/stores
    if (g_pMainWindow != nullptr) {         //        (same loaded value feeds the call below)
        yyDestroyWindow(g_pMainWindow);     // 0x2a28b4 ebfc1801 bl 1a88c0 <_Z15yyDestroyWindowPv>
        // 0x2a28b8 e59f3028 ldr r3, [pc, #40] ; pool@0x2a28e8 = 0x0014f1b4: GOT delta for g_fDoFirstShow
        // 0x2a28bc e3a02001 mov r2, #1     ; byte value stored at 0x2a28cc
        // 0x2a28c0 e3a01000 mov r1, #0     ; word value stored at 0x2a28c8
        // 0x2a28c4 e79f3003 ldr r3, [pc, r3] ; GOT slot 0x3f1a80 -> 0x479a2f = &g_fDoFirstShow
        g_pMainWindow = nullptr;            // 0x2a28c8 e5841000 str r1, [r4]  (word store, before the byte store)
        g_fDoFirstShow = 1;                 // 0x2a28cc e5c32000 strb r2, [r3] (byte store)
    }                                       //        0x2a28d0 is the beq landing pad: the call below is unconditional
    FINALIZE_PlatformSpecific();            // 0x2a28d0 ebffb564 bl 28fe68 <_Z25FINALIZE_PlatformSpecificv>
    VM::Quit();                             // 0x2a28d4 ebf8d664 bl d826c <_ZN2VM4QuitEv>  (static member: plain bl, no receiver)
    // 0x2a28d8 e8bd4010 pop {r4, lr}       ; epilogue runs before the branch
    FreeAllBuffers();                       // 0x2a28dc eaf89498 b c7b44 <_Z14FreeAllBuffersv>  (original tail branch; this
                                            //  is the last statement, so the linked call below returns to Quit's caller)
    // pool words (data, not instructions):
    // 0x2a28e0 0014df50  ; GOT delta -> g_pMainWindow   (consumed 0x2a2808 -> 0x2a28a4)
    // 0x2a28e4 0014b2d4  ; GOT delta -> g_Profiler      (consumed 0x2a2894 -> 0x2a2898)
    // 0x2a28e8 0014f1b4  ; GOT delta -> g_fDoFirstShow  (consumed 0x2a28b8 -> 0x2a28c4)
}
