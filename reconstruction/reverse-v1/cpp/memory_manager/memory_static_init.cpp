/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU carries the .init_array body @0xba3e4..0xba594 (88 code words +
 * 20 literal-pool words, slot 0x3eb654 R_ARM_RELATIVE -> 0xba3e4)
 * and the CHashMap<const char*,int,3> D1/D2 body @0x27c42c..0x27c454
 * (10 words; both WEAK dynsym names share this entry).
 * Startup order, all through the GOT base the body materialises at
 * 0x3f1c58: the map at 0x3f1828 (BSS 0x756798) takes capacity=8, mask=7,
 * entries=NULL (count/+4 and growThreshold/+12 are NOT pre-written), then
 * the real MemoryManager::Alloc(96,"jni/../jni/yoyo/../../../Platform/
 * MemoryManager.h"@0x331038,70,true); the returned pointer is published to
 * +16 BEFORE the real memset(held,0,96); after the call the LIVE signed
 * capacity is read again, count is cleared, growThreshold gets the f32
 * multiply by 0x3f19999a truncated to int32, and only capacity>0 enters the
 * do/while that touches +8 hash per 12-byte entry through the original u32
 * address boundary. Do not elide it after memset: capacity and entries are
 * re-read from the live map and can differ from the first fill.  __aeabi_atexit receives the SAME map pointer, the
 * exact D1 symbol and the real crt __dso_handle; its return is unconsumed.
 * The seven buckets then take only their real C++ vptr in the original
 * order 8/16/32/64/128/256/16K: the object slots 0x3f1840,44,48,4c,50,54,
 * 0x3f1860 are the very bucketAlloc symbols _8byte.._16Kbyte, the vtable
 * slots 0x3f1870..0x3f1888 hold the table bases written +8, and neither
 * CBucket::Init nor the +4/+8/+c payload words may be touched here (the
 * lazy bucketAlloc path owns them).
 * Destructor: ONE entries read, NULL writes nothing; non-NULL calls the
 * real MemoryManager::Free(held) then performs the single entries=NULL.
 * gap: final image load/termination order, Insert @0x27d260,
 * exceptional/fault/concurrent behavior and original execution equivalence.
 * The four memory_state counters, g_MemoryMutex and the mutex guards belong
 * to the lifecycle line and are deliberately NOT defined in this TU.
 */

#include "memory_static_init.hpp"

extern "C" {
/* Real ARM EABI registration helper (0xb65f8 PLT in the original); the
 * int result is unconsumed exactly like the original BL. */
int __aeabi_atexit(void *object, void (*destructor)(void *), void *dso_handle);
/* Exact D1 linkage name of the map destructor defined below; the original
 * passes this same address through the GOT slot at 0x3f186c. */
void memStringsMapD1(void *) __asm__("_ZN8CHashMapIPKciLi3EED1Ev");
/* Provided by the target crt at link time; this TU never defines it. */
extern void *__dso_handle;
}

namespace {

typedef uint32_t MapWord __attribute__((may_alias));

/* The hash clear mirrors the original ldr/str [r3,#8] + cmp on u32
 * addresses; no C++ Entry object is walked here. */
inline void writeMapWord(uint32_t address, uint32_t value) {
    *reinterpret_cast<volatile MapWord *>(static_cast<uintptr_t>(address)) =
        value;
}

template<class B>
inline __attribute__((always_inline)) void constructBucket(BucketStaticStorage<B> &storage) {
    ::new (memory_startup::Placement{&storage.object}) B;
    // Keep this construction before the next one, without a hardware fence.
    asm volatile("" ::: "memory");
}

constexpr unsigned int kMapBytes = 96u;        /* 0xba3f8/0xba428 #96 */
constexpr int kMapCapacity = 8;                /* 0xba408 mov lr, #8 */
constexpr uint32_t kMapMask = 7u;              /* 0xba414 mov ip, #7 */
constexpr int kMapLine = 70;                   /* 0xba3e8 mov r2, #70 */
constexpr float kGrowRatio = 0x1.333334p-1f;             /* pool 0xba544 = 0x3f19999a */
constexpr uint32_t kEntryStride = 12u;         /* sizeof(Entry), LSL#2+base */

__attribute__((constructor)) void memoryImageStartup() {
    /* 0xba3e4-0xba420: activate the map over its aligned BSS storage and
     * write ONLY capacity/mask/entries; count and growThreshold stay
     * untouched until their original sites below. */
    MemoryStringsMap *const map =
        ::new (memory_startup::Placement{g_memStringsMap}) MemoryStringsMap;
    volatile MemoryStringsMap &live = *map;
    live.capacity = kMapCapacity;   /* 0xba418 str lr, [r5] */
    live.mask = kMapMask;           /* 0xba41c str ip, [r5, #8] */
    live.entries = nullptr;         /* 0xba420 str r6, [r5, #16] */

    /* 0xba424: the real four-argument Alloc edge. */
    void *const held =
        MemoryManager::Alloc(kMapBytes,
                             "jni/../jni/yoyo/../../../Platform/MemoryManager.h",
                             kMapLine, true);
    /* 0xba430: publish the held pointer, then 0xba434 the real memset of
     * the held block itself (r0 still carries it in the original). */
    live.entries = static_cast<MemoryStringsMap::Entry *>(held);
    memset(held, 0, kMapBytes);

    /* 0xba438-0xba458: LIVE signed capacity read after the call, count
     * clear, then f32 -> *0.6f -> toward-zero int32 threshold. */
    const int32_t capacity = live.capacity;
    live.count = 0;                                   /* 0xba440 */
    live.growThreshold =
        static_cast<int32_t>(static_cast<float>(capacity) * kGrowRatio);

    /* 0xba45c-0xba47c: signed capacity>0, then the do/while over the LIVE
     * entries word with u32 address boundary; +8 hash stores only. */
    if (capacity > 0) {
        const uint32_t begin =
            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(live.entries));
        const uint32_t end =
            begin + kEntryStride * static_cast<uint32_t>(capacity);
        uint32_t cursor = begin;
        do {
            writeMapWord(cursor + 8u, 0u);            /* 0xba470 */
            cursor += kEntryStride;
        } while (cursor != end);                      /* 0xba478 cmp/bne */
    }

    /* 0xba480-0xba494: same map pointer, exact D1, real __dso_handle. */
    __aeabi_atexit(static_cast<void *>(map), &memStringsMapD1, &__dso_handle);

    /* 0xba498-0xba53c: seven buckets in the original 8..16K order. Plain
     * default placement activates each object. O2 writes just the final
     * vptr at +0; O0 may materialize the intermediate base-constructor
     * vptr. Neither path writes +4/+8/+c/+10 or calls Init. */
    constructBucket(_8byte);
    constructBucket(_16byte);
    constructBucket(_32byte);
    constructBucket(_64byte);
    constructBucket(_128byte);
    constructBucket(_256byte);
    constructBucket(_16Kbyte);
}

} // namespace

/* Original .bss cells owned by this image-initializer TU (the sibling
 * allocator TUs only reference them): map storage 0x756798, anonymous
 * lazy-init byte 0x756699, page size 0x75669c, page table pointer 0x7566a0,
 * page count 0x7566a4, check counter 0x7566ac, seven 20B bucket pools. */
alignas(MemoryStringsMap) unsigned char g_memStringsMap[sizeof(MemoryStringsMap)];
BucketStaticStorage<CBucket<8, 131072, true>> _8byte;
BucketStaticStorage<CBucket<16, 262144, true>> _16byte;
BucketStaticStorage<CBucket<32, 262144, true>> _32byte;
BucketStaticStorage<CBucket<64, 524288, true>> _64byte;
BucketStaticStorage<CBucket<128, 524288, true>> _128byte;
BucketStaticStorage<CBucket<256, 1048576, true>> _256byte;
BucketStaticStorage<CBucket<16384, 262144, true>> _16Kbyte;
namespace bucket_state {
volatile uint8_t initialized;
} // namespace bucket_state
volatile uint32_t pagedata_size;
const volatile uint32_t *volatile g_pages;
volatile uint32_t g_bucketNumPages;
volatile uint32_t checkCounter;

/* D1/D2 shared body @0x27c42c..0x27c450: one live entries read, NULL
 * writes nothing, non-NULL frees the held block through the real
 * MemoryManager::Free then stores entries=NULL once. No catch/cleanup is
 * invented; the two WEAK names alias this body like the original. */
__attribute__((weak))
CHashMap<const char *, int, 3>::~CHashMap() noexcept(false) {
    volatile MemoryStringsMap &live = *this;
    Entry *const held = live.entries;   /* 0x27c434 ldr r0, [r0, #16] once */
    if (held != nullptr) {         /* 0x27c438-0x27c43c cmp/beq tail */
        MemoryManager::Free(held); /* 0x27c440 real Free edge */
        live.entries = nullptr;         /* 0x27c444-0x27c448 single store */
    }
}
