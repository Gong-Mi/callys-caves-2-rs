/* tier: bytecode_anchored, ARMv7 libyoyo SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * .init_array[11] 0x3eb60c -> 0xb9814..0xb9944 (304B, 12 pool words).
 * gap: whole-image load/exit order, callback/fault/unwind/concurrency
 * equivalence, and original writers of the efficiency cell are not certified.
 */
#include "gc_generation.hpp"
#include "gc_instance_hash.hpp"
#include "object_helpers.hpp"
#include "../memory_manager/memory_static_init.hpp"
#include "../vm_exec/vm_entry_runtime.hpp"

extern "C" {
int __aeabi_atexit(void *, void (*)(void *), void *);
extern void *__dso_handle;
void instanceHashD1(void *) __asm__("_ZN4HashI9CInstanceED1Ev");
void objectSlotsD1(void *) __asm__("_ZN6YYSlotI12YYObjectBaseED1Ev");
// The original .data initializer is a literal word, not a computed float.
volatile uint32_t g_GCinitialcollectionefficiency = 0x45800000u; // 0x3f504c
}

alignas(Hash<CInstance>) unsigned char ms_ID2Instance[sizeof(Hash<CInstance>)]; // 0x536f28
alignas(ObjectSlotRegistry) unsigned char g_slotObjects[sizeof(ObjectSlotRegistry)]; // 0x536f0c
GCGenerationStorage g_GCGens[4]; // 0x536da8, runtime stride 88
namespace rvalue_state {
BucketStaticStorage<RValuePagePool> pages;
}

// 0xcef4c..0xcef64: no size gate; preserve the r0 bit pattern and false flag.
void *YYAlloc(int bytes) {
    return MemoryManager::Alloc(static_cast<unsigned>(bytes),
                                "jni/../jni/yoyo/../../../Files/Code/Code_Main.cpp",
                                1293, false);
}

namespace {
__attribute__((constructor)) void gcImageStartup() {
    // 0xb9848..0xb9878: two header writes, publish real Alloc result,
    // clear held 4KiB, then register the same Hash object's D1.
    auto *const hash = ::new (memory_startup::Placement{ms_ID2Instance}) Hash<CInstance>;
    volatile auto &imageHash = *hash;
    imageHash.mask = 511;
    imageHash.liveCount = 0u;
    void *const table = MemoryManager::Alloc(4096u,
        "jni/../jni/yoyo/../../../Platform/Hash.h", 187, true);
    imageHash.buckets = static_cast<InstanceHashBucket *>(table);
    memset(table, 0, 4096u);
    __aeabi_atexit(hash, &instanceHashD1, &__dso_handle);

    // 0xb987c..0xb98bc: allocate using YYAlloc (not the earlier Alloc tag).
    // Publish +0 before memset, then +8/+c/+4 in that precise order.
    void *const slots = YYAlloc(512);
    auto *const registry = ::new (memory_startup::Placement{g_slotObjects}) ObjectSlotRegistry;
    volatile auto &imageSlots = *registry;
    imageSlots.slots = static_cast<YYObjectBase *volatile *>(slots);
    memset(slots, 0, 512u);
    imageSlots.count = 0u;
    imageSlots.firstFree = 0;
    imageSlots.capacity = 128u;
    __aeabi_atexit(registry, &objectSlotsD1, &__dso_handle);

    // 0xb98c8..0xb98f4: four ordinary C1 calls, with +0x58 stride.
    // The array exit callback ignores the (null) object argument.
    for (auto &storage : g_GCGens) {
        ::new (memory_startup::Placement{storage.bytes}) CGCGeneration;
    }
    __aeabi_atexit(nullptr, &gcGensArrayDtor, &__dso_handle);

    // 0xb98f8..0xb990c: GOT 0x3f0678 -> _rvalue, vtable slot 0x3f06a0.
    // Default initialization only installs the vptr, not the four pool fields.
    ::new (memory_startup::Placement{&rvalue_state::pages.object}) rvalue_state::RValuePagePool;
}
} // namespace
