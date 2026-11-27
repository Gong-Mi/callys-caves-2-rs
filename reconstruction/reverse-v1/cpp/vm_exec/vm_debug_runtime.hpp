#ifndef CALLY_VM_DEBUG_RUNTIME_HPP
#define CALLY_VM_DEBUG_RUNTIME_HPP
#include "vm_entry_runtime.hpp"

/* tier: bytecode_anchored; VM::ExecDebug0xe47c8..0xe4ba8, fixed ARMv7
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * These real globals are bindings, not debug-state snapshots/default values.
 * gap: DebugInfo/DebugLineNumber/DoBreak and debugger server consumers,
 * complete debug records, private frame/LR/fault/unwind remain unproved.
 */
extern volatile int32_t g_DebugStepType;               // 0x3f2094
extern volatile uint8_t g_DoSingleStep;               // 0x47f297
extern const char *volatile g_SingleStepCurrentScript; // pointer variable0x47f290
extern volatile int32_t g_SingleStepRetCount;         // 0x47f28c
extern volatile int32_t g_SingleStepCurrentLine;      // 0x3f2098

struct VMDebugPrivateImage {
    volatile uint32_t payload00;          // saved r3 across DebugInfo/LineNumber
    volatile uint32_t argcCell04;         // address of g_ArgumentCount cell
    volatile uint32_t argcSnapshot08;
    volatile uint32_t freeLocals0c;       // bool promoted into original stack word
    uint32_t unobserved10;
};
static_assert(sizeof(VMDebugPrivateImage) == 20, "original private sp+00..13");
#endif
