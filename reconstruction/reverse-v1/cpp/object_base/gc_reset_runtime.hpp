#ifndef CALLY_GC_RESET_RUNTIME_HPP
#define CALLY_GC_RESET_RUNTIME_HPP
#include "gc_generation.hpp"
#include "../vm_exec/vm_entry_runtime.hpp" // existing g_fJSGarbageCollection byte declaration

/* tier: bytecode_anchored; ResetGC 0xd66e0..0xd675c, original SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * 0xd6714 and 0xd671c clear these BSS words in sequence. Only their
 * storage/width and ResetGC write sites are bound here; other writers,
 * linked addresses and the runtime scheduling/locking protocol are open. */
extern "C" volatile uint32_t g_GenToCollect; // GOT 0x3edc9c -> 0x47a1f8
extern "C" volatile uint32_t g_GCframe;      // GOT 0x3edca0 -> 0x47a1f4
void ResetGC();                            // _Z7ResetGCv

#endif
