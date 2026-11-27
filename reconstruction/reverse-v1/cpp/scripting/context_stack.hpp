#ifndef CALLY_CONTEXT_STACK_HPP
#define CALLY_CONTEXT_STACK_HPP
#include "../vm_exec/vm_entry_runtime.hpp"

/* tier: bytecode_anchored; PushContextStack0xd3968/204B,
 * PopContextStack0xd3a34/32B, GetContextStackTop0xd3a54/60B.
 * ARMv7 SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Canonical method declarations remain script_runtime.hpp/vm_entry_runtime.hpp.
 * Actual pointer/count variables, not default stack state or guessed class.
 * gap: initial/context-stack ownership, invalid/OOM/overflow fault domains,
 * retained caller LR/unwind and concurrent mutations remain unproved.
 */
extern volatile uint32_t g_ContextStackTop;  // actual WORD0x47f280; Pop/Get use signed tests
extern volatile uint32_t g_ContextStackMax;  // actual WORD0x47f27c
extern YYObjectBase **volatile g_ContextStack; // actual POINTER cell0x47f284
#endif
