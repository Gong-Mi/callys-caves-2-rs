#ifndef CALLY_HOST_LIFECYCLE_QUIT_RUNTIME_HPP
#define CALLY_HOST_LIFECYCLE_QUIT_RUNTIME_HPP

#include "../object_base/gc_object_lifecycle.hpp" // FreeAllObjects 0xd675c, raw words, guard byte
                                                   // (gc_reset_runtime.hpp chain supplies ResetGC 0xd66e0)
#include "../vm_exec/vm_exec.hpp"                  // CProfiler (seam copy adds Clean), VM (adds Quit)

/* tier: bytecode_anchored; original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Teardown-orchestrator declarations for Quit@0x2a27fc (240B incl. pools).
 * Every callee below is declared from its dynsym identity only; the bodies
 * are outside the recovered set and NO stub is provided for any of them.
 * Real links in this slice: FreeAllObjects and ResetGC only. */
void CleanGestures();                              // 0x1dba70, 192B
void FreeAllDataStructures();                      // 0x20b27c, 508B
void QuitYoYoFunctions();                          // 0x15a0c0, 16B
void QuitNetworkingFunctions();                    // 0x2998b8, 32B
void FINALIZE_Score();                             // 0x1dc3bc, 580B
void FINALIZE_Code_Constant();                     // 0xf1bb0, 224B
void FINALIZE_Code_Function();                     // 0xce274, 68B
void FINALIZE_Code_Main();                         // 0xcf478, 4B
void FINALIZE_Code_Variable();                    // 0xd2618, 4B
void FINALIZE_Motion_Grid();                      // 0x19c2cc, 140B
void FINALIZE_Room_Main();                        // 0x1b5e54, 32B
void FINALIZE_Instance_Class();                   // 0x1959f4, 436B
void FINALIZE_Run_Main();                         // 0x1d37cc, 276B
void FINALIZE_Object_Lists();                     // 0x19e884, 132B
void FINALIZE_Object_Main();                      // 0x19f0c0, 348B
void FINALIZE_Object_Class();                     // 0x19e1c8, 4B
void FINALIZE_Particle_Main();                    // 0x1a5de8, 332B
void FINALIZE_Sprite_Class();                     // 0x1ee76c, 4B
void FINALIZE_Sprite_Main();                      // 0x1ef514, 148B
void FINALIZE_Support_File();                     // 0x214e14, 4B
void FINALIZE_VertexFormats();                    // 0x1e3180, 296B
void FINALIZE_Graphics_Display();                 // 0x17dbb8, 20B
void FINALIZE_Background();                       // 0xc42f4, 124B
void FINALIZE_Graphics_Texture();                 // 0x1767cc, 4B
void FINALIZE_Script_Main();                      // 0x1e0770, 4B
void FINALIZE_Variable_Main();                    // 0x1f4d10, 152B
void FINALIZE_Font_Main();                        // 0xface8, 16B
void FINALIZE_Graphics_Text();                    // 0x1738fc, 72B
void FINALIZE_Event_Action();                     // 0xf2c9c, 108B
void FINALIZE_Function_File();                    // 0x13cf04, 100B
void FINALIZE_Timeline_Main();                    // 0x1f3174, 420B
void FINALIZE_Runner_Form();                      // 0x1df90c, 200B
void FINALIZE_Sound();                            // 0x21f49c, 404B
void FINALIZE_All();                              // 0xc47f8, 4B
void GR_D3D_End();                                // 0x168c90, 28B
void yyDestroyWindow(void *);                     // 0x1a88c0, 4B
void FINALIZE_PlatformSpecific();                 // 0x28fe68, 4B
void FreeAllBuffers();                             // 0xc7b44, 100B; tail branch at 0x2a28dc
/* Declared from the original dynsym records (widths bound to st_size);
 * producers are outside the recovered set. */
extern "C" void *g_pMainWindow;           // 0x542554, 4B
extern "C" unsigned char g_fDoFirstShow;  // 0x479a2f, 1B
void Quit();                                       // 0x2a27fc, 240B

#endif
