#ifndef CALLY_CBUCKET_CLASSES_HPP
#define CALLY_CBUCKET_CLASSES_HPP

#include <stddef.h>
#include <stdint.h>

class CBucketBase;
struct BucketPagePrefix {
    BucketPagePrefix *next;
    CBucketBase *owner; // page+4: recovered allocator writes the offset-zero base address
};
static_assert(sizeof(BucketPagePrefix) == 8 && offsetof(BucketPagePrefix, owner) == 4,
              "ARM32 page header");

/* tier: bytecode_anchored; nine ARMv7 CBucket specializations (seven true, two false).
 * Original ELF SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * CBucketBase table 0x3eb8f0 has four pure-virtual slots (shared Thumb
 * helper and literal 0x35c400), no destructor slot. The derived VMI RTTI
 * records contain one non-public, non-virtual base at offset zero; private
 * inheritance is the ABI representation, not proof of the original spelling.
 * The seven vtables run 0x3ec0f8..0x3ec1a0, with address points +8:
 * Init/+0, Check/+4, GetSize/+8, Free/+12. The live derived footprint is
 * 20 bytes; the evidence for startup lifetime is separate from these
 * method bodies. Base-field attribution and access spelling are not claimed. The two return-word shapes match the observed
 * callers (Free's original C++ return spelling is not in the mangle).
 * gap: target unwind, invalid-pointer faults, dynamic lifetime and
 * concurrency are not certified by this ABI declaration.
 */
class CBucketBase {
public:
    virtual void Init() = 0;
    virtual void Check() = 0;
    virtual uint32_t GetSize() = 0;
    virtual uint32_t Free(const void *block) = 0;
};

template<unsigned ChunkBytes, unsigned AreaBytes, bool Mode>
class CBucket : private CBucketBase {
public:
    void Init() override;
    void Check() override;
    uint32_t GetSize() override;
    uint32_t Free(const void *block) override;

    BucketPagePrefix *pageHead;
    uint8_t *freeHead;
    uint32_t activeCount;
    uint32_t freeCount;
};

extern volatile uint32_t checkCounter; // BSS 0x7566ac, GOT 0x3edbcc

static_assert(sizeof(CBucketBase) == 4, "ARM32 abstract virtual interface");
static_assert(!__has_virtual_destructor(CBucketBase), "the original base has no virtual destructor slots");

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
template<class B>
constexpr bool observedCBucketLayout() {
    return sizeof(B) == 20 && alignof(B) == 4 && __is_base_of(CBucketBase, B)
        && !__is_convertible(B *, CBucketBase *)
        && __builtin_offsetof(B, pageHead) == 4 && __builtin_offsetof(B, freeHead) == 8
        && __builtin_offsetof(B, activeCount) == 12 && __builtin_offsetof(B, freeCount) == 16;
}
static_assert(observedCBucketLayout<CBucket<8, 131072, true>>() &&
              observedCBucketLayout<CBucket<16, 262144, true>>() &&
              observedCBucketLayout<CBucket<32, 262144, true>>() &&
              observedCBucketLayout<CBucket<64, 524288, true>>() &&
              observedCBucketLayout<CBucket<128, 524288, true>>() &&
              observedCBucketLayout<CBucket<256, 1048576, true>>() &&
              observedCBucketLayout<CBucket<16384, 262144, true>>() &&
              observedCBucketLayout<CBucket<16, 1048576, false>>() &&
              observedCBucketLayout<CBucket<32768, 1048576, false>>(),
              "all seven observed ARM32 derived layouts (non-public base)");
#pragma clang diagnostic pop

/* Before the image constructor runs there is BSS storage, not a live
 * polymorphic C++ object. Placement default-initialization activates object
 * at the original phase and does not value-initialize the four payload words.
 * Use this same declaration in the writer and all typed consumers. */
template<class B>
union BucketStaticStorage {
    unsigned char bytes[sizeof(B)];
    B object;
    constexpr BucketStaticStorage() : bytes{} {}
};
static_assert(sizeof(BucketStaticStorage<CBucket<8, 131072, true>>) == 20,
              "the stored object starts at the symbol and occupies 20 bytes");

#endif
