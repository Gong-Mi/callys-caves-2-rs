/* tier: bytecode_anchored
 * CGCGeneration::Reset,
 * _ZN13CGCGeneration5ResetEv @0x19140c (window 0x19140c..0x19150c, 256B
 * including the three pool words at 0x191500/0x191504/0x191508), pinned ARMv7
 * image libyoyo-armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU defines the Reset body ONLY; ResetDynamicRoots stays defined in
 * gc_mutable_roots.cpp and the g_GCinitialcollectionefficiency word is
 * read here, not defined.
 * Word order mirrors the disassembly literally: real call to
 * ResetDynamicRoots (0x191414); held this->rootMap read (0x191418); its
 * +0x10 entries freed ONLY when non-NULL (0x19141c..0x191428); the merged
 * path clears the HELD map's +0x10 (0x191430) — no replacement map is
 * built; this->rootMap is RE-READ live afterwards (0x191434); capacity is
 * read (0x191444), +0x08 = capacity-1 written (0x19144c/50), the 32-bit
 * wrapping capacity*12 size fed to the real MemoryManager::Alloc edge
 * (0x191454..0x191460, tag 0x331038, line 70, bool true), the return
 * PUBLISHED into the same held map's +0x10 (0x19146c) and only then
 * memset (0x191470); capacity re-read live after memset (0x191474), +0x04
 * count cleared (0x19147c), +0x0c threshold = trunc((float)(int32_t)capacity *
 * 0.6f) written unconditionally with the SIGNED capacity>0 test
 * selecting the per-entry +0x08 hash clear (0x191480..0x1914b8); tail
 * writes this+0x18=-1, +0x14=INT_MAX, +0x1c=-1, copies the LIVE
 * g_GCinitialcollectionefficiency word (GOT slot 0x3edc98 -> 0x3f504c)
 * into +0x2c, then zeroes +0x20/24/28/30/34/38 (0x1914c0..0x1914f8).
 * classStats (+0x48/+0x4c) and dynamicRoots (+0x04/08/0c) are NOT written
 * except through the ResetDynamicRoots call, exactly as the original.
 * gap: faults (Alloc/MemoryManager edges, a NULL rootMap deref),
 * unwind/EHABI records, exceptions and concurrency remain unproved; the
 * original was never run for this recovery.
 */
#include "gc_generation.hpp"

namespace {

/* .rodata path word consumed by the Alloc tag argument (literal pool word
 * 0x191504: add r1,pc,r1 with pc=0x191450 -> 0x331038), the same
 * MemoryManager.h path the seam publishes, here with line 70. */
const char memoryManagerHeaderSourcePath[] =
    "jni/../jni/yoyo/../../../Platform/MemoryManager.h";

/* Pool word at 0x191500: the F32 bit pattern used for the grow threshold. */
constexpr float kEfficiencyFactor = 0.6f; // exactly 0x3f19999a
static_assert(__builtin_bit_cast(uint32_t, kEfficiencyFactor) == 0x3f19999au,
              "Reset threshold multiplier bit pattern");

} // namespace

void CGCGeneration::Reset() {
    volatile CGCGeneration &self = *this;

    /* 0x191414 bl 0x191400: the real ResetDynamicRoots call runs FIRST
     * (it clears only this+0x08); nothing before it touches any field. */
    ResetDynamicRoots();

    /* 0x191418 ldr r5,[r4]: the HELD map. 0x19141c..0x191428: its +0x10
     * entries go to the real Free edge ONLY when non-NULL — a NULL table
     * skips the call entirely. */
    volatile GCGenRootMapHeader *const held = self.rootMap;
    GCRootMapEntry *const oldEntries = held->entries;
    if (oldEntries != nullptr) {
        MemoryManager::Free(oldEntries); /* 0x191428 */
    }

    /* 0x19142c mov r6,#0 / 0x191430 str r6,[r5,#16]: BOTH paths merge here
     * and the cleared +0x10 is written to the SAME held map — no new map
     * is substituted; r5 still holds the 0x191418 value. */
    held->entries = nullptr;

    /* 0x191434 ldr r5,[r4]: this->rootMap is RE-READ live from the object. */
    volatile GCGenRootMapHeader *const map = self.rootMap;

    /* 0x191444 ldr r0,[r5]: capacity is read, never written here.
     * 0x19144c sub ip,r0,#1 / 0x191450 str ip,[r5,#8]: mask = capacity-1
     * (32-bit wrap). 0x191454 add r0,r0,r0,lsl#1 / 0x191458 lsl r7,r0,#2:
     * the requested size is the 32-bit wrapping capacity*3*4 = capacity*12.
     * 0x191460 bl 0x27ce78: the real Alloc(size, 0x331038, 70, true) edge;
     * r2=70 and r3=1 sit in the literal argument registers. */
    const uint32_t allocCapacity = map->capacity;
    map->mask = allocCapacity - 1u;
    const uint32_t bytes = (allocCapacity + (allocCapacity << 1u)) << 2u;
    void *const fresh = MemoryManager::Alloc(bytes, memoryManagerHeaderSourcePath,
                                             70, true);

    /* 0x19146c str r0,[r5,#16] BEFORE 0x191470 bl memset: the Alloc return
     * is PUBLISHED into the held map's +0x10 first, then the same held
     * register value is memset(entries, 0, bytes). */
    GCRootMapEntry *const entries = static_cast<GCRootMapEntry *>(fresh);
    map->entries = entries;
    memset(entries, 0, bytes);

    /* 0x191474 ldr r2,[r5]: capacity re-read live after memset (0x19147c
     * clears +0x04 count between the read and the use). +0x0c receives
     * trunc((float)(int32)capacity * 0.6f) UNCONDITIONALLY,
     * signed-conversion and truncating-back toward zero as the
     * vcvt.f32.s32 / vmul.f32 / vcvt.s32.f32 triple spells it
     * (-ffp-contract=off keeps the lone vmul). The 0x191480 cmp r2,#0 /
     * 0x191498 ble is a SIGNED test issued before the threshold store but
     * consumed after it: only capacity>0 enters the hash clear. */
    const uint32_t liveCapacity = map->capacity;
    map->count = 0u;
    map->growThreshold =
        static_cast<int32_t>(static_cast<float>(static_cast<int32_t>(liveCapacity)) *
                             kEfficiencyFactor);
    if (static_cast<int32_t>(liveCapacity) > 0) {
        // 0x19149c reads the LIVE entries pointer; neither pointer nor
        // byte size comes from the earlier Alloc/memset snapshot.
        uintptr_t cursor = reinterpret_cast<uintptr_t>(map->entries);
        const uintptr_t end = cursor + liveCapacity * 12u;
        do {
            reinterpret_cast<volatile GCRootMapEntry *>(cursor)->hash = 0u; // 0x1914ac
            cursor += 12u;
        } while (cursor != end);
    }

    /* Tail 0x1914bc..0x1914f8 against this (r4): +0x18 = -1, +0x14 =
     * INT_MAX, +0x1c = -1; the LIVE g_GCinitialcollectionefficiency word is
     * loaded once (0x1914cc ldr [pc,r3] resolves GOT slot 0x3edc98 to the
     * object address, 0x1914d8 ldr [r3] reads the word) and copied raw into
     * +0x2c (0x1914dc); then +0x20, +0x24, +0x28, +0x30, +0x34 and +0x38
     * are zeroed. No other field is touched. */
    self.rangeMax18 = -1;                       /* +0x18, mvn r2,#0 */
    self.rangeMin14 = 0x7fffffff;               /* +0x14, mvn r1,0x80000000 */
    self.word1c = -1;                           /* +0x1c */
    const uint32_t efficiencyWord = g_GCinitialcollectionefficiency;
    self.efficiencyWord2c = efficiencyWord;     /* +0x2c, raw copy */
    self.zeroWord20 = 0;
    self.zeroWord24 = 0;
    self.zeroWord28 = 0;
    self.zeroWord30 = 0;
    self.zeroWord34 = 0;
    self.zeroWord38 = 0;
}
