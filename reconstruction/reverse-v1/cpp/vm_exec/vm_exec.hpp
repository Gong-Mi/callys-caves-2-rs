#ifndef CALLY_RECOVERED_VM_EXEC_HPP
#define CALLY_RECOVERED_VM_EXEC_HPP

#include "../vm_buffer/vm_buffer.hpp"

/* Recovered C++ execution/return interface, not original source spelling.
 * tier: bytecode_anchored; original ARMv7 ELF SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Layout producers: VM::Exec 0xe804c..0xe8194 and DoCallScript
 * 0xe8614..0xe8714; consumers: ExecRelease 0xe4540, PerformReturn 0xe42d8.
 * gap: +0x30 meaning, whole-class extents, runner global producers and
 * original RValue/YYObjectBase/CProfiler APIs are not completely recovered.
 * This batch implements VM::ExecRelease, the free PerformReturn and its
 * direct CProfiler::Pop dependency. It neither redefines old C candidates
 * nor supplies a game runtime.
 */
struct RValue; // 16-byte transferred image; no invented constructors/ownership
struct RVariable;
class CCode;
struct VMDebugInfo;

/* Original static call surface only. No YYObjectBase layout, allocation or
 * lifetime implementation is claimed, and no such object is created here. */
class YYObjectBase {
public:
    static YYObjectBase *Alloc(unsigned int, int, bool); // 0x19198c, first call's raw r0/r1/r2
    RValue *InternalGetYYVar(int);                    // 0x196a70, returned storage address
    void AllocVars();                                // 0x1917dc, current caller ignores r0
    static void Free(YYObjectBase *);                  // 0x198f88
    static void FreeVars(YYObjectBase *, RValue **, RValue **,
                         RVariable **, RVariable **); // 0x198dac, last two parameters not consumed
};

/* g_Profiler is an INLINE 128-byte object, not a pointer variable.
 * Storage size is bound to its dynsym record; fields/alignment and Pop's
 * ignored source-level return spelling remain unknown. No instance is made. */
class CProfiler {
public:
    void Push(int, int);                              // 0x2a0738; caller ignores source return spelling
    uint32_t FindOrCreateNode(int, int);               // 0x2a04f4, node INDEX used by Pop, not a pointer
    void Pop();                                      // 0x2a08ac; result unused by PerformReturn
private:
    uint8_t unknownStorage[128];
};

struct VMExec {
    VMExec *childExec;                                // +0x00: older exec points to newly entered exec
    VMExec *parentExec;                               // +0x04: saved g_pCurrentExec
    uint8_t *stackAllocation;                         // +0x08: page chunk or separate allocation
    uint32_t localsMode;                              // +0x0c: zero permits local-object release
    YYObjectBase *locals;                             // +0x10
    YYObjectBase *self;                               // +0x14
    YYObjectBase *other;                              // +0x18
    RValue *argumentValues;                           // +0x1c: memcpy destination in VM::Exec
    uint32_t argumentCount;                           // +0x20: VM::Exec's count argument
    const uint8_t *code;                              // +0x24: raw bytecode
    uint8_t *frameBase;                               // +0x28: 60-byte control frame
    VMBuffer *buffer;                                 // +0x2c: active bytecode buffer
    uint32_t state30;                                 // +0x30: saved/restored; DoCallScript writes zero
    const char *name;                                 // +0x34: CCode+0x5c
    VMBuffer *debugBuffer;                            // +0x38: CCode+0x54
    const char *sourceText;                           // +0x3c: CCode+0x58 snapshot
    uint32_t stackSpan;                               // +0x40: initial 0x4000 BYTE COUNT, not a pointer
    int32_t bytePc;                                   // +0x44: byte offset, not dense slot
    uint32_t nextSlot;                                // +0x48: dense-handler prefetch cursor
    int32_t frameDepth;                               // +0x4c
    int32_t byteLimit;                                // +0x50: VMBuffer+0x04
    int32_t lastBytePc;                               // +0x54
    const volatile VMInstructionHandler *handlers;    // +0x58: dense slot -> handler
    const volatile uint32_t *offsetToSlot;            // +0x5c: bytePc/4 -> dense slot
};

/* Producer subtracts 60 from the argument pointer. +0x34 is reserved here:
 * PerformReturn does not consume it, so do not invent a restore operation. */
struct VMCallFrame {
    int32_t callerBytePc;                             // +0x00
    uint32_t callerState30;                           // +0x04
    uint32_t callerArgumentCount;                     // +0x08
    int32_t callerFrameDistance;                      // +0x0c: negative -> null frame
    YYObjectBase *callerSelf;                         // +0x10
    YYObjectBase *callerOther;                        // +0x14
    VMBuffer *callerBuffer;                           // +0x18: null -> fast return
    VMBuffer *callerDebugBuffer;                      // +0x1c
    const char *callerSourceText;                     // +0x20
    const char *callerName;                           // +0x24
    void *deleteOnReturn;                             // +0x28: raw operator delete, even null
    uint32_t callerLocalsMode;                        // +0x2c
    YYObjectBase *callerLocals;                       // +0x30
    uint32_t reserved34;                              // +0x34: not read by this consumer
    uint32_t callerArgumentOffset;                    // +0x38: relative to live stackAllocation
};

struct VMStackPagePrefix {
    VMStackPagePrefix *next;                          // original reads only +0x00
    uint32_t unknown04;                               // data range begins at page+8
};
struct VMStackPages {
    uint32_t unknown00;
    VMStackPagePrefix *pageHead;                      // +0x04
    uint8_t *freeHead;                                // +0x08
    uint32_t count0c;                                 // +0x0c: returned chunk decrements
    uint32_t count10;                                 // +0x10: returned chunk increments
};

class VM {
public:
    static void Exec(CCode *, YYObjectBase *, YYObjectBase *, RValue *,
                     YYObjectBase *, int, RValue *, int, YYObjectBase *); // 0xe7fd0, current caller ignores r0
    static void ExecRelease(VMExec &, RValue *result); // 0xe4540..0xe47c8, no implicit this
    static void ExecDebug(VMExec &, RValue *, bool);   // 0xe47c8, current caller ignores r0
    static VMDebugInfo *DebugInfo(VMBuffer *, int);    // 0xec144, opaque returned debug record
    static int DebugLineNumber(VMDebugInfo *, const char *, char **); // 0xec2b8
};
uint8_t *PerformReturn(uint8_t *stack, VMExec *exec);  // 0xe42d8..0xe44d4, ordinary C++ function
void FREE_RValue__Pre(RValue *);                      // 0xc0a7c, original internal dependency

extern volatile uint32_t g_execCount;
extern volatile uint32_t g_retCount;
extern volatile uint32_t g_ArgumentCount;
extern RValue *volatile Argument;
extern volatile uint8_t g_bProfile;
extern CProfiler g_Profiler;
extern VMExec *volatile g_pCurrentExec;
extern volatile uint8_t g_fDoExceptionUnwind;
extern RValue g_exceptionVar;                         // original object size 16; keep type opaque
extern VMExec *volatile g_caughtExec;
extern uint8_t *volatile g_pExceptionSP;
extern volatile VMStackPages stackPages;             // inline 20-byte object at 0x47a1e0

#endif
