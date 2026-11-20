/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Sole method: MemoryManager::Free(const void*) @ 0x27c2d0, size 348,
 * dynsym _ZN13MemoryManager4FreeEPKv (boundary: defined_dynsym).
 * Direct callees: lazy init 0x27b918 (anonymous, reached by BL 0x27c408),
 * Mutex::Lock 0x27e084, logLocation 0x27bcf4, bucketFree 0x27c20c,
 * libc free@plt 0xb655c.
 * Counter publish order on the standard-header path is proven from the
 * GOT-slot addends of this very function: 0x3f03ec -> 0x756754 m_InUse
 * (-size, 0x27c384-0x27c38c), 0x3f03e0 -> 0x756758 m_Total (-size,
 * 0x27c390-0x27c39c), 0x3f185c -> 0x75674c m_StandardCount (-1,
 * 0x27c3a0-0x27c3ac), 0x3f03e8 -> 0x756748 m_StandardSize (-size,
 * 0x27c3b0-0x27c3bc). The memory_state aliases bind those real symbols;
 * no counters are duplicated here.
 * gap: fault domains of corrupted headers, pthread failure semantics and
 * the exact meaning of the p[-4] back-reference field remain unproved;
 * 32-bit wrap behaviour of the counters is preserved, not sanitised.
 */

#include "memory_internal.hpp"

namespace {

/* Header words live immediately before the user pointer inside the same
 * malloc block (byte offsets -16/-12/-8/-4). may_alias keeps the alias
 * honest, volatile keeps every original load; the short-circuit order
 * below mirrors the original branch graph 1:1. */
typedef uint32_t HeaderWord __attribute__((may_alias));

constexpr uint32_t kStandardMagic = 0xdeadc0deu; /* 0x27c324 movw 0xc0de, 0x27c328 movt 0xdead */
constexpr uint32_t kBackrefMagic = 0xbaadb00bu;   /* 0x27c358/0x27c35c */
constexpr uint32_t kBit31ClearMask = 0x7fffffffu; /* 0x27c3c8: bic bit31 */
constexpr uint32_t kBackrefLimit = 8192u;         /* 0x27c3cc: cmp #8192 */

uint32_t readHeaderWord(uint32_t address) {
    return *reinterpret_cast<const volatile HeaderWord *>(
        static_cast<uintptr_t>(address));
}

} // namespace

void MemoryManager::Free(const void *p) {
    if (p == nullptr) {          /* 0x27c2d4 subs + 0x27c2e0 popeq: early exit */
        return;
    }

    /* 0x27c2e4-0x27c2f4: read the LIVE g_MemoryMutex; a null pointer calls
     * the original lazy initializer (BL 0x27c408 -> 0x27b918) and the
     * pointer is then re-read at 0x27c40c. */
    Mutex *mutex = g_MemoryMutex;
    if (mutex == nullptr) {
        initializeMemoryMutex();
        mutex = g_MemoryMutex;
    }

    mutex->Lock(); /* 0x27c2f8 */

    /* 0x27c2fc-0x27c30c: logLocation(ELogType 2, p, null, 0) strictly
     * before the bucket dispatch. */
    logLocation(static_cast<ELogType>(2), p, nullptr, 0u);

    /* 0x27c314-0x27c31c: nonzero bucketFree result means the block was
     * already released by the page-list bucket; jump to the unlock tail. */
    if (bucketFree(p) == 0u) {
        const uint32_t address = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(p));

        /* 0x27c320: p[-12] magic decides the standard-header attempt; the
         * p[-8] magic (0x27c354) is read only when the first one matched. */
        bool standardHeader = false;
        if (readHeaderWord(address - 12u) == kStandardMagic) {
            standardHeader = (readHeaderWord(address - 8u) == kBackrefMagic);
        }

        if (standardHeader) {
            /* Both header magics matched: 0x27c374 ldr r3,[r0,#-16]! grabs
             * the size at p[-16] and re-targets r0 to p-16. All four
             * counters are read/sub/stored in GOT-proven order first, then
             * free(p-16) at 0x27c3c0. Wrap is the original semantics. */
            const uint32_t size = readHeaderWord(address - 16u);
            memory_state::inUse -= size;
            memory_state::total -= size;
            memory_state::standardCount -= 1u;
            memory_state::standardSize -= size;
            free(reinterpret_cast<void *>(static_cast<uintptr_t>(address - 16u)));
        } else {
            /* 0x27c334: p[-4] as signed. Nonnegative (or bit31-cleared
             * distance >= 8192, or any magic mismatch) frees the raw p at
             * 0x27c344; a fully matched back-reference header only skips
             * the free WITHOUT adjusting any counter - that is the
             * original behaviour, deliberately not "fixed" here. */
            const int32_t rawOffset = static_cast<int32_t>(readHeaderWord(address - 4u));
            bool skipFree = false;
            if (rawOffset < 0) { /* 0x27c33c blt 0x27c3c8 */
                const uint32_t offset =
                    static_cast<uint32_t>(rawOffset) & kBit31ClearMask;
                if (offset < kBackrefLimit) { /* 0x27c3d0 bhs -> free(p) */
                    /* 0x27c3d4-0x27c3dc: base = (char*)p - 16 - offset
                     * (byte distance); words at base+4 / base+8. The +8
                     * read happens only when the +4 read already matched
                     * (0x27c3ec bne -> free(p)). */
                    const uint32_t backref = address - 16u - offset;
                    skipFree = readHeaderWord(backref + 4u) == kStandardMagic &&
                               readHeaderWord(backref + 8u) == kBackrefMagic;
                }
            }
            if (!skipFree) {
                free(const_cast<void *>(p));
            }
        }
    }

    /* 0x27c348-0x27c350 tail: ALWAYS re-read the live g_MemoryMutex and
     * tail-call Unlock. No RAII may hold the mutex captured at entry,
     * because initializeMemoryMutex (or another thread) can republish it. */
    g_MemoryMutex->Unlock();
}
