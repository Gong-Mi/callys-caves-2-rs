#include "vm_exec.hpp"

/* ARM32 observed prefixes only; no arm64 layout is inferred. */
#define FIELD(T, M, O) static_assert(offsetof(T, M) == (O), #T "." #M)
FIELD(VMExec, childExec, 0x00);
FIELD(VMExec, parentExec, 0x04);
FIELD(VMExec, stackAllocation, 0x08);
FIELD(VMExec, localsMode, 0x0c);
FIELD(VMExec, locals, 0x10);
FIELD(VMExec, self, 0x14);
FIELD(VMExec, other, 0x18);
FIELD(VMExec, argumentValues, 0x1c);
FIELD(VMExec, argumentCount, 0x20);
FIELD(VMExec, code, 0x24);
FIELD(VMExec, frameBase, 0x28);
FIELD(VMExec, buffer, 0x2c);
FIELD(VMExec, state30, 0x30);
FIELD(VMExec, name, 0x34);
FIELD(VMExec, debugBuffer, 0x38);
FIELD(VMExec, sourceText, 0x3c);
FIELD(VMExec, stackSpan, 0x40);
FIELD(VMExec, bytePc, 0x44);
FIELD(VMExec, nextSlot, 0x48);
FIELD(VMExec, frameDepth, 0x4c);
FIELD(VMExec, byteLimit, 0x50);
FIELD(VMExec, lastBytePc, 0x54);
FIELD(VMExec, handlers, 0x58);
FIELD(VMExec, offsetToSlot, 0x5c);
FIELD(VMCallFrame, callerBytePc, 0x00);
FIELD(VMCallFrame, callerState30, 0x04);
FIELD(VMCallFrame, callerArgumentCount, 0x08);
FIELD(VMCallFrame, callerFrameDistance, 0x0c);
FIELD(VMCallFrame, callerSelf, 0x10);
FIELD(VMCallFrame, callerOther, 0x14);
FIELD(VMCallFrame, callerBuffer, 0x18);
FIELD(VMCallFrame, callerDebugBuffer, 0x1c);
FIELD(VMCallFrame, callerSourceText, 0x20);
FIELD(VMCallFrame, callerName, 0x24);
FIELD(VMCallFrame, deleteOnReturn, 0x28);
FIELD(VMCallFrame, callerLocalsMode, 0x2c);
FIELD(VMCallFrame, callerLocals, 0x30);
FIELD(VMCallFrame, reserved34, 0x34);
FIELD(VMCallFrame, callerArgumentOffset, 0x38);
FIELD(VMStackPagePrefix, next, 0x00);
FIELD(VMStackPages, pageHead, 0x04);
FIELD(VMStackPages, freeHead, 0x08);
FIELD(VMStackPages, count0c, 0x0c);
FIELD(VMStackPages, count10, 0x10);
#undef FIELD
static_assert(sizeof(VMExec) == 0x60, "observed execution prefix");
static_assert(sizeof(VMCallFrame) == 0x3c, "producer control-frame stride");
static_assert(sizeof(VMStackPagePrefix) == 8, "observed page header prefix");
static_assert(sizeof(VMStackPages) == 20, "stackPages inline dynsym size");
static_assert(sizeof(CProfiler) == 128, "g_Profiler inline dynsym storage size");
static_assert(sizeof(VMInstructionHandler) == 4, "original handler pointer width");
