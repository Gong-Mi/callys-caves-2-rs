#ifndef CALLY_OBJECT_INTERNAL_HPP
#define CALLY_OBJECT_INTERNAL_HPP
#include "../vm_exec/vm_exec.hpp"

/* tier: bytecode_anchored; original ARMv7 image SHA-256:
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * YYObjectBase::Free 0x198f88..0x199110; FreeVars 0x198dac..0x198f88.
 * YYObjectBase/RValue stay declaration-only nominal types; these wire views
 * do NOT instantiate or assert the complete original C++ object layouts.
 * gap: full APIs, JS/value helper bodies, faults, object lifetime and unwind
 * domains remain unproved. No default globals or callback bodies are supplied.
 */
struct ObjectSlotRegistry {
    YYObjectBase *volatile *slots;                    // +0x00, read before writing selected slot
    uint32_t capacity;                               // +0x04, Alloc compares as signed and grows with wrap
    uint32_t count;                                  // +0x08, wrapping decrement
    int32_t firstFree;                               // +0x0c, signed minimum with object+0x44
};
extern volatile ObjectSlotRegistry g_slotObjects;    // original inline 16B object, 0x536f0c
extern volatile uint8_t g_ShouldDispose;             // actual 1B flag at 0x3f5050
namespace object_state {
extern YYObjectBase *volatile freeList __asm__("_ZN12YYObjectBase12ms_pFreeListE");
extern volatile uint32_t currentCounter __asm__("_ZN12YYObjectBase17ms_currentCounterE");
}

struct alignas(8) ObjectValueImage {
    uint32_t low, high, auxiliary, kind;              // 16-byte raw local image, no RValue ctor/dtor
};
struct ObjectVariableMapPrefix {
    int32_t word00;
    int32_t word04;
    uint32_t unknown08, unknown0c;
    uint32_t bucketsAddress;                         // +0x10; raw ARM32 address
};
struct ObjectVariableBucket {
    uint32_t unknown00;
    RValue *value;                                   // +4, reloaded after FREE_RValue callback
    int32_t stateWord;                               // +8, consumed as signed >0
};
struct ObjectDeleteTablePrefix {
    uint32_t unknownSlot00;
    void (*deleteSelf)(YYObjectBase *);               // +4 at the object's vptr address point
};

void JS_GetProperty(YYObjectBase *, RValue *, const char *); // 0x2418dc, result ignored
uint32_t JS_IsCallable(RValue &);                      // 0x24076c, caller tests full r0 != 0
uint32_t Call_RValue(YYObjectBase *, RValue *, RValue *, int, RValue *); // 0x249860, explicit r0=1 rejection path
void FreeRValue(RValue *, RValue **, RValue **);        // 0x190e84, page-pool body in value_pool.cpp
using PcreFreeEntry = void (*)(void *);
extern "C" PcreFreeEntry volatile pcre_free;           // function-pointer variable at 0x3f76dc

namespace object_wire {
using Word = uint32_t __attribute__((may_alias));
inline uint32_t address(const void *p) {
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(p));
}
inline uint32_t read(uint32_t base, uint32_t offset) {
    return *reinterpret_cast<const volatile Word *>(static_cast<uintptr_t>(base + offset));
}
inline void write(uint32_t base, uint32_t offset, uint32_t value) {
    *reinterpret_cast<volatile Word *>(static_cast<uintptr_t>(base + offset)) = value;
}
}
#endif
