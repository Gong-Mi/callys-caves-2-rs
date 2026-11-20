#ifndef CALLY_OBJECT_ALLOC_INTERNAL_HPP
#define CALLY_OBJECT_ALLOC_INTERNAL_HPP
#include "object_helpers.hpp"
#include "../ccode/ccode.hpp"

/* tier: bytecode_anchored; fixed ARMv7 image
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Alloc 0x19198c, InternalGetYYVar 0x196a70; declarations are real original
 * providers, not stubs. Never new/delete the nominal empty YYObjectBase type:
 * Alloc requests exactly 100 bytes via original operator new and calls the
 * unresolved C1 ABI below on that raw storage. The original constructor/type
 * lifetime and complete class are still a named internal recovery debt.
 */
extern "C" void constructYYObjectBaseRaw(YYObjectBase *, int, int)
    __asm__("_ZN12YYObjectBaseC1Eii"); // C1/C2 alias@0x19188c,256B; raw 3-GP constructor boundary

/* This is the ordinary overloaded function, NOT a template specialization:
 * original symbol _Z21CHashMapCalculateHashi, 0x1b6e44 (8B).
 */
unsigned int CHashMapCalculateHash(int) __attribute__((noinline));
RValue *GetRValue(); // 0x190dc0, actual internal allocator still owed
void *YYRealloc(void *, int) __attribute__((noinline)); // 0xcef64

template <typename K, typename V, int N> class CHashMap {
public:
    void Insert(K, V); // current caller ignores r0; real weak body for <int,RValue*,3> at0x196408
};
static_assert(sizeof(ObjectSlotRegistry) == 16 && offsetof(ObjectSlotRegistry, capacity) == 4,
              "inline slot registry capacity/count/firstFree at4/8/12");
#endif
