#ifndef CALLY_GC_GENERATION_HPP
#define CALLY_GC_GENERATION_HPP

#include "../memory_manager/memory_alloc.hpp"

class YYObjectBase;

/* Recovered C++ interface, not the original source spelling.
 * tier: bytecode_anchored; ARMv7 image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Anchors: C1/C2 _ZN13CGCGenerationC1Ev/C2Ev 0x190f58/268B both GLOBAL
 * same entry (dynsym); D1/D2 _ZN13CGCGenerationD1Ev/D2Ev 0x191064/80B both
 * GLOBAL same entry (dynsym); the anonymous array-cleanup body occupies
 * 0x1910b4..0x1910e8 (52 bytes including one pool word, no dynsym name).
 * The 88B size and 4-instance array come from dynsym g_GCGens @0x536da8
 * (.bss, size 352) consumed by the image initializer loop at
 * 0xb98c8/0xb98d0 (4 × +88 through C1, then __aeabi_atexit(NULL-object,
 * 0x1910b4, DSO handle 0x3f2000) at 0xb98e0..0xb98f4).
 * Field roles marked "proven via" below are read from sibling CGCGeneration
 * methods (IsRoot 0x1910e8, RemoveRoot 0x1911c8, AddDynamicRoot 0x19135c,
 * ResetDynamicRoots 0x191400, Reset 0x19140c, UpdateRange 0x19150c,
 * ResetClassStats 0x191530, AddRoot 0x196210, all dynsym GLOBAL); those
 * bodies are NOT recovered in this seam.
 * gap: names/access levels are reconstructed; +0x10/+0x3c/+0x40/+0x44/+0x54
 * are never written by C1/D1/Reset and their producers/consumers are not
 * pinned here; faults, unwind, exceptions and concurrency remain unproved.
 * This file does not define any global and does not replace the seam.
 */
#if !defined(__arm__) || __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
#error "This recovered layout targets little-endian ARM32, not arm64"
#endif

/* The 20B header that C1 materializes over a raw operator new(20) block.
 * Only these five words are evidenced (C1 0x190f80..0x190fcc, D1
 * 0x191078..0x19108c, Reset 0x19141c..0x19146c, AddRoot/IsRoot probing
 * +0x00 capacity/+0x04 count/+0x08 mask/+0x0c threshold/+0x10 entries).
 * The template symbol spellings _Z21CHashMapCalculateHashIP12YYObjectBaseEjT_
 * (0x190f34) and _Z19CHashMapCompareKeysIP12YYObjectBaseEbT_S2_ (0x190f48)
 * fix the entry key type as YYObjectBase*; the 12B entry carries its hash
 * at +0x08 (the only word C1 clears per entry) and the +0x04 value word is
 * moved but never typed by the probe sites. The full map class type is
 * deliberately NOT asserted here. */
struct GCGenRootMapHeader {
    uint32_t capacity;      // +0x00: C1 writes 16, Reset re-derives halved mask
    uint32_t count;         // +0x04: C1 writes 0
    uint32_t mask;          // +0x08: C1 writes 15
    int32_t growThreshold;  // +0x0c: trunc(capacity * 0.6f) via the VFP chain
    void *entries;          // +0x10: 12B-stride blocks, MM-owned
};
static_assert(sizeof(GCGenRootMapHeader) == 20 && alignof(GCGenRootMapHeader) == 4,
              "GC root-map header is the 20B new(20) block");
static_assert(offsetof(GCGenRootMapHeader, count) == 4 &&
              offsetof(GCGenRootMapHeader, mask) == 8 &&
              offsetof(GCGenRootMapHeader, growThreshold) == 12 &&
              offsetof(GCGenRootMapHeader, entries) == 16, "GC root-map words");

class CGCGeneration {
public:
    CGCGeneration();      // C1/C2 @0x190f58, 268B, same GLOBAL entry
    /* The original C1, D1 and array callback have compact inline EHABI
     * records. Matching unwind metadata/propagation is outside this gate. */
    ~CGCGeneration() noexcept(false); // D1/D2 @0x191064, 80B, same GLOBAL entry

    bool IsRoot(YYObjectBase *);                      // 0x1910e8
    void AddDynamicRoot(YYObjectBase *, bool force); // 0x19135c
    void ResetDynamicRoots();                       // 0x191400
    void UpdateRange(int);                          // 0x19150c
    void ResetClassStats();                          // 0x191530

    GCGenRootMapHeader *rootMap; // +0x00: the new(20) block, freed by D1
    YYObjectBase **dynamicRoots; // +0x04: four-byte pointer slots, AddDynamicRoot 0x1913ac
                                 // (line 74); D1 frees it unconditionally
    int32_t dynamicRootCount;    // +0x08: AddDynamicRoot ++, ResetDynamicRoots =0
    int32_t dynamicRootCapacity; // +0x0c: doubles (min 1) at AddDynamicRoot
    uint32_t unknownWord10;      // +0x10: NOT written by C1; compared against
                                 // object+0x38 at 0x19137c (proven reader only)
    int32_t rangeMin14;          // +0x14: UpdateRange keeps min; C1/Reset INT_MAX
    int32_t rangeMax18;          // +0x18: UpdateRange keeps max; C1/Reset -1
    int32_t word1c;              // +0x1c: -1 in C1 and Reset; UpdateRange skips it
    int32_t zeroWord20;          // +0x20: 0 in C1 and Reset
    int32_t zeroWord24;          // +0x24: 0 in C1 and Reset
    int32_t zeroWord28;          // +0x28: 0 in C1 and Reset
    uint32_t efficiencyWord2c;   // +0x2c: raw 32-bit copy of the
                                 // g_GCinitialcollectionefficiency word (C1
                                 // 0x191020, re-copied by Reset 0x1914dc)
    int32_t zeroWord30;          // +0x30: 0 in C1 and Reset
    int32_t zeroWord34;          // +0x34: 0 in C1 and Reset
    int32_t zeroWord38;          // +0x38: 0 in C1 and Reset
    uint32_t unknownWord3c;      // +0x3c: untouched by C1/D1/Reset (no write proven)
    uint32_t unknownWord40;      // +0x40: untouched by C1/D1/Reset (no write proven)
    uint32_t unknownWord44;      // +0x44: untouched by C1/D1/Reset (no write proven)
    void *classStatsArray48;     // +0x48: 8B-stride entries. ResetClassStats frees
                                 // entry +0 payloads, retaining the array itself.
    int32_t classStatsCount4c;   // +0x4c: ResetClassStats loop bound + clear
    int32_t word50;              // +0x50: 0 in C1; AddClassStat consumer not recovered
    uint32_t unknownWord54;      // +0x54: untouched by C1/D1/Reset (no write proven)
};
static_assert(sizeof(CGCGeneration) == 88 && alignof(CGCGeneration) == 4,
              "g_GCGens stride 88 = dynsym 352 / 4");
static_assert(offsetof(CGCGeneration, rootMap) == 0x00 &&
              offsetof(CGCGeneration, dynamicRoots) == 0x04 &&
              offsetof(CGCGeneration, dynamicRootCount) == 0x08 &&
              offsetof(CGCGeneration, dynamicRootCapacity) == 0x0c &&
              offsetof(CGCGeneration, unknownWord10) == 0x10 &&
              offsetof(CGCGeneration, rangeMin14) == 0x14 &&
              offsetof(CGCGeneration, rangeMax18) == 0x18 &&
              offsetof(CGCGeneration, word1c) == 0x1c &&
              offsetof(CGCGeneration, efficiencyWord2c) == 0x2c &&
              offsetof(CGCGeneration, classStatsArray48) == 0x48 &&
              offsetof(CGCGeneration, classStatsCount4c) == 0x4c &&
              offsetof(CGCGeneration, unknownWord54) == 0x54, "CGCGeneration words");

/* Seam spelling for the real allocating operator new @0x27c524 (_Znwj);
 * memory_buckets.hpp/ccode.hpp declare the same entity for their lines. */
void *operator new(size_t);

/* dynsym-pinned array (GLOBAL OBJECT @0x536da8, 352B = 4 x 88). Declared
 * only: the image-startup line owns the definition and the C1 loop; this
 * seam never defines it and never invents a second backing store. */
struct alignas(CGCGeneration) GCGenerationStorage {
    unsigned char bytes[sizeof(CGCGeneration)];
};
static_assert(sizeof(GCGenerationStorage) == 88, "array stride");
extern GCGenerationStorage g_GCGens[4];
inline __attribute__((always_inline)) CGCGeneration &liveGeneration(GCGenerationStorage &storage) noexcept {
    return *__builtin_launder(reinterpret_cast<CGCGeneration *>(storage.bytes));
}

/* The .data global behind two-level SLOT 0x3edc98 -> 0x3f504c (verified
 * R_ARM_RELATIVE pair; the name is the literal dynsym GLOBAL OBJECT
 * @0x3f504c size 4). Observed accesses in this image are plain 32-bit
 * loads (C1 0x191004+0x191014, Reset 0x1914cc+0x1914d8); the image word
 * is 0x45800000. Declared as a raw 4-byte word because NO F32 arithmetic
 * against it is evidenced on this seam — C1/Reset only copy the word.
 * Its writer, if any, is out of scope; declared only, never defined here. */
extern "C" volatile uint32_t g_GCinitialcollectionefficiency;

/* Descriptive recovered name for the anonymous original array cleanup at
 * 0x1910b4..0x1910e8; NOT claimed as a source identifier. The original
 * ignores the __aeabi_atexit object argument (registered as NULL at
 * 0xb98e4) and re-derives &g_GCGens through GOT slot 0x3edc68
 * (R_ARM_RELATIVE -> 0x536da8, verified in-file), destroys instances 3,
 * 2, 1 via BL and 0 via the pop/tail-B at 0x1910dc..0x1910e0. */
void gcGensArrayDtor(void *ignoredObjectArgument);

#endif
