/* tier: bytecode_anchored
 * libyoyo-armv7.so SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Insert@0x195ba8..0x196210, WEAK; real caller AddRoot@0x1963c8.
 * The two inlined reinsert passes keep their own read and publication
 * order. Only the deepest rehash calls the public weak entry (0x1961dc).
 * Gap: original/final-image execution, faults, unwind, FP environment and
 * concurrency are not certified. Volatile pins the ordered word accesses,
 * not cross-thread synchronization.
 */
#include "gc_generation.hpp"

namespace {
using RootMap = GCGenRootMapHeader;
using Entry = GCRootMapEntry;

constexpr char kTag[] = "jni/../jni/yoyo/../../../Platform/MemoryManager.h";
constexpr float kGrowRatio = 0x1.333334p-1f; // 0x196118: 0x3f19999a
static_assert(__builtin_bit_cast(uint32_t, kGrowRatio) == 0x3f19999au);
constexpr uint32_t kStride = 12;

enum class EmptyOrder { HashFirst, HashLast };
enum class RehashPass { Public, InlineOne, InlineTwo };

inline volatile Entry *slotAt(const Entry *base, uint32_t index) {
    return reinterpret_cast<volatile Entry *>(
        reinterpret_cast<uintptr_t>(base) + index * kStride);
}

inline int32_t asSigned(uint32_t word) {
    return static_cast<int32_t>(word); // ARM32 signed interpretation of this word
}

inline int32_t threshold(uint32_t capacity) {
    return static_cast<int32_t>(static_cast<float>(asSigned(capacity)) * kGrowRatio);
}

template<EmptyOrder order>
inline void publishEmpty(volatile Entry &slot, YYObjectBase *key,
                         YYObjectBase *value, uint32_t hash) {
    // Public (0x195cc0) and InlineOne (0x195f1c) publish hash first.
    // InlineTwo (0x19610c/0x196110) publishes the pair first.
    if constexpr (order == EmptyOrder::HashFirst) {
        slot.hash = hash;
    }
    slot.key = key;
    slot.value = value;
    if constexpr (order == EmptyOrder::HashLast) {
        slot.hash = hash;
    }
}

template<EmptyOrder order>
__attribute__((always_inline)) inline void insertPending(
    RootMap &map, uint32_t heldCount, YYObjectBase *key, YYObjectBase *value) {
    volatile RootMap &live = map;
    // 0x195bd8 / 0x195dec / 0x19600c. The count is already held on each
    // incoming edge; there is no extra count read or threshold check here.
    live.count = heldCount + 1u;
    uint32_t hash = CHashMapCalculateHash<YYObjectBase *>(key);
    const uint32_t mask = live.mask;
    Entry *const entries = live.entries;
    hash &= 0x7fffffffu;
    uint32_t index = hash & mask;
    volatile Entry *slot = slotAt(entries, index);
    uint32_t occupantHash = slot->hash;
    if (occupantHash == 0u) {
        publishEmpty<order>(*slot, key, value, hash);
        return;
    }

    const uint32_t capacity = live.capacity; // read only on the collision path
    uint32_t distance = 0;
    do {
        // 0x195c5c / 0x195e6c / 0x196084. Comparison is signed after wrapping.
        const uint32_t occupantDistance =
            (capacity + index - (occupantHash & mask)) & mask;
        if (asSigned(occupantDistance) < asSigned(distance)) {
            // 0x195c18 / 0x195e2c / 0x196044: read key and value first, then
            // write hash/key/value. The displaced triple continues probing.
            YYObjectBase *const savedKey = slot->key;
            YYObjectBase *const savedValue = slot->value;
            slot->hash = hash;
            slot->key = key;
            slot->value = value;
            hash = occupantHash;
            key = savedKey;
            value = savedValue;
            distance = occupantDistance;
        } else if (occupantDistance == distance && occupantHash == hash &&
                   slot->key == key) {
            // 0x195c90 / 0x195ea0 / 0x1960b8. The hash words compare equal.
            const uint32_t count = live.count;
            slot->key = key;
            slot->value = value;
            slot->hash = occupantHash;
            live.count = count - 1u;
            return;
        }
        index = (index + 1u) & mask;
        distance += 1u;
        slot = slotAt(entries, index);
        occupantHash = slot->hash;
    } while (occupantHash != 0u);
    publishEmpty<order>(*slot, key, value, hash);
}

template<RehashPass pass>
__attribute__((always_inline)) inline uint32_t growAndReinsert(RootMap &map) {
    volatile RootMap &live = map;
    // 0x195cdc / 0x195f30 / 0x196128: hold capacity before the entries read.
    const uint32_t oldCapacity = live.capacity;
    Entry *const oldEntries = live.entries;
    const uint32_t newCapacity = oldCapacity << 1u;
    live.capacity = newCapacity;
    live.mask = newCapacity - 1u;
    const uint32_t bytes = (newCapacity + (oldCapacity << 2u)) << 2u;
    auto *const fresh = static_cast<Entry *>(MemoryManager::Alloc(bytes, kTag, 70, true));
    live.entries = fresh;
    memset(fresh, 0, bytes);

    // 0x195d30 / 0x195f80 / 0x19616c. These are LIVE, not the allocation
    // snapshots; the first clear happens before the wraparound end check.
    const uint32_t liveCapacity = live.capacity;
    live.count = 0u;
    live.growThreshold = threshold(liveCapacity);
    if (asSigned(liveCapacity) > 0) {
        auto cursor = reinterpret_cast<uintptr_t>(live.entries);
        const uintptr_t end = cursor + liveCapacity * kStride;
        do {
            reinterpret_cast<volatile Entry *>(cursor)->hash = 0u;
            cursor += kStride;
        } while (cursor != end);
    }

    if (asSigned(oldCapacity) > 0) {
        for (uint32_t index = 0; index != oldCapacity; ++index) {
            const volatile Entry &oldSlot = *slotAt(oldEntries, index);
            if (asSigned(oldSlot.hash) <= 0) {
                continue;
            }
            if constexpr (pass == RehashPass::Public) {
                // 0x195dc0..0x195de0: key, count, threshold, value. The
                // nested growth resumes at 0x195de4 with its held count.
                YYObjectBase *const key = oldSlot.key;
                uint32_t count = live.count;
                const int32_t limit = live.growThreshold;
                YYObjectBase *const value = oldSlot.value;
                if (asSigned(count) > limit) {
                    count = growAndReinsert<RehashPass::InlineOne>(map);
                }
                insertPending<EmptyOrder::HashFirst>(map, count, key, value);
            } else if constexpr (pass == RehashPass::InlineOne) {
                // 0x195fec..0x196000: count, threshold, key, value. This
                // pass resumes at 0x196004 and publishes empty hash last.
                uint32_t count = live.count;
                const int32_t limit = live.growThreshold;
                YYObjectBase *const key = oldSlot.key;
                YYObjectBase *const value = oldSlot.value;
                if (asSigned(count) > limit) {
                    count = growAndReinsert<RehashPass::InlineTwo>(map);
                }
                insertPending<EmptyOrder::HashLast>(map, count, key, value);
            } else {
                // 0x1961d8/0x1961dc: the one actual weak recursive edge.
                YYObjectBase *const key = oldSlot.key;
                YYObjectBase *const value = oldSlot.value;
                map.Insert(key, value);
            }
        }
    }
    MemoryManager::Free(oldEntries); // 0x195eec / 0x1960ec / 0x1961f0

    // 0x195ef0 / 0x1960f0 / 0x1961f4: capacity before count, then publish
    // the threshold and use the held count without re-testing the grow gate.
    const uint32_t postFreeCapacity = live.capacity;
    const uint32_t postFreeCount = live.count;
    live.growThreshold = threshold(postFreeCapacity);
    return postFreeCount;
}
} // namespace

__attribute__((weak))
void CHashMap<YYObjectBase *, YYObjectBase *, 4>::Insert(YYObjectBase *key,
                                                       YYObjectBase *value) {
    volatile RootMap &live = *this;
    uint32_t count = live.count; // 0x195bb4
    const int32_t limit = live.growThreshold; // 0x195bc0
    if (asSigned(count) > limit) {
        count = growAndReinsert<RehashPass::Public>(*this);
    }
    insertPending<EmptyOrder::HashFirst>(*this, count, key, value);
}
