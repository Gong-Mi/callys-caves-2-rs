#ifndef CALLY_VM_ENTRY_RUNTIME_HPP
#define CALLY_VM_ENTRY_RUNTIME_HPP
#include "../scripting/script_runtime.hpp"

/* tier: bytecode_anchored; original ARMv7 SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * VM::Exec 0xe7fd0..0xe8588. No original source spelling, whole-class,
 * private-stack garbage, bad-pointer, original LR or unwind certification.
 * Anonymous-state binding follows g_TimingEpochBase/dispatch-cache policy:
 * declaration only, descriptive name, no default initializer or fixed VA.
 */
namespace vm_entry_state {
extern volatile uint8_t stackPoolInitialized; // anonymous original BYTE 0x47a1d0, distinct from stackPages20B
}
extern volatile uint8_t g_fVMTrace;
extern volatile uint8_t g_fJSGarbageCollection;
struct VMDebugServer;
extern VMDebugServer *volatile g_pServer;

/* Original console virtual slot +0xc receives this, format and name in
 * r0/r1/r2. The format is variadic ("script = %s\n"), not a fixed-arity stub.
 * These are prefix views, never instantiated as original object classes.
 */
struct VMDebugConsolePrefix;
using VMTracePrint = void (*)(VMDebugConsolePrefix *, const char *, ...);
struct VMDebugConsoleTablePrefix { uint32_t slots00[3]; VMTracePrint print; };
struct VMDebugConsolePrefix { VMDebugConsoleTablePrefix *table; };
extern VMDebugConsolePrefix *volatile dbg_csol; // actual 4B pointer variable @0x3eb70c

/* Compiler-independent read prefix for the original ref-counted object;
 * do not instantiate it or infer a complete source class from these bytes.
 */
template <typename T> class _RefThing {
public:
    void dec() __attribute__((noinline));
    T volatile value00;
    volatile uint32_t count04;
    volatile uint32_t word08;
};
template <> void _RefThing<const char *>::dec() __attribute__((weak, noinline)); // original WEAK DEFAULT 0xc09f8
void *YYAlloc(int) __attribute__((noinline)); // 0xcef4c, original wrapper
void YYFree(const void *) __attribute__((noinline)); // 0xcef90, real tail MemoryManager::Free
void LOCK_RVALUE_MUTEX() __attribute__((noinline));   // original BX LR @0x190f2c, not a real lock
void UNLOCK_RVALUE_MUTEX() __attribute__((noinline)); // original BX LR @0x190f30
void DeterminePotentialRoot(YYObjectBase *, YYObjectBase *) __attribute__((noinline)); // BX LR @0x191710
YYObjectBase *GetContextStackTop();                  // real unresolved 0xd3a54

/* Same storage coordinate for the prefix temporaries and published VMExec:
 * original sp+00/04 are reused for converter receiver and ref-release saves;
 * sp+08 retains a RValue pointer across callbacks. Only initialize bytes the
 * original writes. Local declaration may use alignas(8), not value-init.
 */
struct VMEntryPrivateImage {
    volatile uint32_t word00;
    volatile uint32_t word04;
    volatile uint32_t word08;
    volatile uint32_t text0c;
    volatile uint32_t localCount10;
    volatile uint32_t word14;
    VMExec exec18;
    uint32_t unobserved78;
};
static_assert(offsetof(VMEntryPrivateImage, exec18) == 0x18, "original published exec identity");
static_assert(offsetof(VMEntryPrivateImage, exec18) + offsetof(VMExec, frameDepth) == 0x64,
              "e8138 initializes frameDepth at original sp+64, NOT nextSlot at sp+60");
static_assert(sizeof(VMEntryPrivateImage) == 0x7c, "observed private sp+00..7b extent");
static_assert(offsetof(_RefThing<const char *>, count04) == 4, "ref-count word");
static_assert(offsetof(_RefThing<const char *>, word08) == 8, "ref state word");
static_assert(offsetof(VMDebugConsoleTablePrefix, print) == 12, "console vararg slot");
#endif
