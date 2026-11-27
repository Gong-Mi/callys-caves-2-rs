/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU recovers exactly two bodies, word-ordered against the windows:
 *   CGCGeneration::CGCGeneration()   _ZN13CGCGenerationC1Ev/C2Ev
 *                                    0x190f58..0x191054, 268B span, both
 *                                    GLOBAL dynsym names share this entry
 *   CGCGeneration::~CGCGeneration()  _ZN13CGCGenerationD1Ev/D2Ev
 *                                    0x191064..0x1910b0, 80B span, both
 *                                    GLOBAL dynsym names share this entry
 * There is no vptr, no guard byte, no extra zero write and no early
 * termination path in either body: every path in C1 reaches the single
 * pop at 0x191054, every path in D1 reaches the pop at 0x1910b0, and the
 * complete-object/base-object (r0 = this) pair is the same entry, so the
 * two-level C1/C2 and D1/D2 naming is pure ABI aliasing here.
 * gap: AddRoot/IsRoot/RemoveRoot/AddDynamicRoot/Reset/ResetClassStats
 * bodies, the +0x10/+0x3c/+0x40/+0x44/+0x54 producers, g_GCinitialcollection
 * efficiency writers outside this window, faults (operator new bad_alloc,
 * Alloc failure), unwind tables, FPSCR/trap behaviour, concurrency and any
 * equivalence-by-execution claim remain unproved; the original was never
 * run for this recovery.
 */
#include "gc_generation.hpp"
#include "../memory_manager/memory_static_init.hpp" // placement overload

namespace {

typedef uint32_t RawWord __attribute__((may_alias));

/* The hash-word clear mirrors the original ldr [r5,#16] + str [r3,#8] +
 * cmp on u32 addresses (0x190fd8..0x190ff0); no Entry object is walked
 * and the 12B stride stays raw. */
inline void writeRawWord(uint32_t address, uint32_t value) {
    *reinterpret_cast<volatile RawWord *>(static_cast<uintptr_t>(address)) = value;
}

/* 0x331038 .rodata string consumed by MemoryManager::Alloc (r1 via the
 * pc-relative add at 0x190f78, literal pool word at 0x19105c). */
const char memoryManagerHeaderSourcePath[] =
    "jni/../jni/yoyo/../../../Platform/MemoryManager.h";

constexpr unsigned int kMapBytes = 192u;      /* 0x190f90/0x190f9c #0xc0 = 16*12 */
constexpr uint32_t kMapCapacity = 16u;        /* 0x190f70 mov r2, #16 -> +0x00 */
constexpr uint32_t kMapMask = 15u;            /* 0x190f74 mov r3, #15 -> +0x08 */
constexpr int kMapLine = 70;                  /* 0x190f88 mov r2, #70 */
constexpr float kGrowRatio = 0x1.333334p-1f;  /* pool 0x191058 = 0x3f19999a */
constexpr uint32_t kEntryStride = 12u;        /* ADD r2,r2,r2 LSL#1 then LSL#2 */

} // namespace

CGCGeneration::CGCGeneration() {
    /* 0x190f60-0x190f7c: the real allocating operator new(_Znwj@0x27c524)
     * for exactly 20 bytes; the block is filled in place below. */
    void *const storage = operator new(20u);
    GCGenRootMapHeader *const map =
        ::new (memory_startup::Placement{storage}) GCGenRootMapHeader;
    volatile GCGenRootMapHeader &live = *map;

    /* 0x190f80-0x190f94: ONLY capacity/mask/entries are written before the
     * Alloc edge (r6=0 is materialized at 0x190f64); count and
     * growThreshold stay untouched until their original sites. */
    live.capacity = kMapCapacity; /* 0x190f80 str r2, [r0] */
    live.mask = kMapMask;         /* 0x190f84 str r3, [r0, #8] */
    live.entries = nullptr;       /* 0x190f94 str r6, [r5, #16] */

    /* 0x190f98: the real four-argument Alloc edge
     * Alloc(192, "jni/../jni/yoyo/../../../Platform/MemoryManager.h"
     *       @0x331038, 70, true). */
    void *const held = MemoryManager::Alloc(kMapBytes,
                                            memoryManagerHeaderSourcePath,
                                            kMapLine, true);

    /* 0x190fa4: publish the held pointer at +0x10 BEFORE the real
     * memset(held, 0, 192) at 0x190fa8 (r0 still carries held). */
    live.entries = static_cast<GCRootMapEntry *>(held);
    memset(held, 0, kMapBytes);

    /* 0x190fac-0x190fcc: LIVE signed capacity re-read after the calls,
     * count clear at +0x04, then the VFP chain vcvt.f32.s32 / vmul by
     * 0x3f19999a / vcvt.s32.f32 (toward zero) stored UNCONDITIONALLY to
     * +0x0c before the signed compare decides the loop. */
    const int32_t capacity = static_cast<int32_t>(live.capacity); /* 0x190fac */
    live.count = 0u;                                              /* 0x190fb4 */
    live.growThreshold =
        static_cast<int32_t>(static_cast<float>(capacity) * kGrowRatio);

    /* 0x190fd0-0x190ff0: signed capacity > 0, then the do/while over the
     * LIVE entries word (0x190fd8 re-read, not the publish-time copy) with
     * u32 wrapping end arithmetic cap*3<<2; each 12B entry gets ONLY its
     * +0x08 word zeroed — key/value words stay as memset left them and no
     * null guard is invented (fault behaviour unproved). */
    if (capacity > 0) {
        const uint32_t begin =
            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(live.entries));
        const uint32_t end =
            begin + (static_cast<uint32_t>(capacity) +
                     (static_cast<uint32_t>(capacity) << 1u)) *
                        4u; /* add r2,r2,r2 lsl #1 + LSL#2, u32 wrap */
        uint32_t cursor = begin;
        do {
            writeRawWord(cursor + 8u, 0u); /* 0x190fe4 str r1, [r3, #8] */
            cursor += kEntryStride;        /* 0x190fe8 add r3, r3, #12 */
        } while (cursor != end);           /* 0x190fec-0x190ff0 cmp/bne */
    }

    /* 0x191000..0x191050: preserve the live global read between
     * publishing the capacity and writing the count (0x191014). */
    volatile CGCGeneration &self = *this;
    self.rootMap = map;                    /* 0x191000 */
    self.dynamicRoots = nullptr;           /* 0x191008 */
    self.dynamicRootCapacity = 0;          /* 0x19100c */
    const uint32_t efficiencyWord = g_GCinitialcollectionefficiency; /* 0x191014 */
    self.dynamicRootCount = 0;             /* 0x191018 */
    self.zeroWord20 = 0;                   /* 0x19101c */
    self.efficiencyWord2c = efficiencyWord; /* 0x191020 */
    self.zeroWord24 = 0;                   /* 0x191028 str r3, [r4, #36] */
    self.zeroWord28 = 0;                   /* 0x19102c str r3, [r4, #40] */
    self.zeroWord30 = 0;                   /* 0x191030 str r3, [r4, #48] */
    self.zeroWord34 = 0;                   /* 0x191034 str r3, [r4, #52] */
    self.zeroWord38 = 0;                   /* 0x191038 str r3, [r4, #56] */
    self.classStatsArray48 = nullptr;      /* 0x19103c str r3, [r4, #72] */
    self.classStatsCount4c = 0;            /* 0x191040 str r3, [r4, #76] */
    self.classStatsCapacity50 = 0;                       /* 0x191044 str r3, [r4, #80] */
    self.word1c = -1;                      /* 0x191048 str r1, [r4, #28] */
    self.rangeMax18 = -1;                  /* 0x19104c str r1, [r4, #24] */
    self.rangeMin14 = 0x7fffffff;          /* 0x191050 str r2, [r4, #20] */
    /* +0x10/+0x3c/+0x40/+0x44/+0x54 have NO store in the original window
     * and receive none here; 0x191010 mov r0,r4 / 0x191054 pop is the
     * ABI return-this, written by the compiler, not by source. */
}

/* Definition repeats the header's exception specification exactly like the
 * seam's map-destructor precedent (memory_static_init.cpp:157). */
CGCGeneration::~CGCGeneration() noexcept(false) {
    /* 0x19106c: the held map pointer is taken exactly ONCE. */
    volatile CGCGeneration &self = *this;
    GCGenRootMapHeader *const map = self.rootMap;
    if (map != nullptr) {
        volatile GCGenRootMapHeader &live = *map;
        /* 0x191078-0x19108c: one entries read; NULL skips everything,
         * non-NULL calls the real MemoryManager::Free(held) and only then
         * stores entries=NULL at +0x10 (the store sits inside the branch). */
        void *const entries = live.entries; /* 0x191078 ldr r0, [r5, #16] */
        if (entries != nullptr) {           /* 0x19107c-0x191080 cmp/beq */
            MemoryManager::Free(entries);   /* 0x191084 real Free edge */
            live.entries = nullptr;         /* 0x191088-0x19108c single store */
        }
        /* 0x191090-0x191094: the real ::operator delete over the whole
         * 20B header block (_ZdlPv @0x27d1d0), no header fields are
         * rewritten before it. */
        ::operator delete(static_cast<void *>(map));
    }

    /* 0x19109c-0x1910a8: shared tail, unconditional on both paths. The
     * LIVE this+4 read happens BEFORE this+0 is cleared, Free() consumes
     * the read value even when it is NULL (the original always calls), and
     * only afterwards does this+4 store 0. No second map read, no guard,
     * no extra zero write; 0x1910ac mov r0,r4 is compiler return-this. */
    void *const dynamicRootsHeld = self.dynamicRoots; /* 0x19109c ldr r0,[r4,#4] */
    self.rootMap = nullptr;                            /* 0x1910a0 str r5, [r4] */
    MemoryManager::Free(dynamicRootsHeld);              /* 0x1910a4 real Free edge */
    self.dynamicRoots = nullptr;                       /* 0x1910a8 str r5, [r4,#4] */
}
