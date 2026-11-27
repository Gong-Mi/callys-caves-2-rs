/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU carries two complete bodies (98 original words total):
 *   MemoryManager::_Alloc(unsigned int,const char*,int,bool)
 *     @ 0x27cd54, size 292, _ZN13MemoryManager6_AllocEjPKcib
 *     (73 words incl. 6 tail pool words 0x27ce60-0x27ce74 slots), and
 *   MemoryManager::Alloc(unsigned int,const char*,int,bool)
 *     @ 0x27ce78, size 100, _ZN13MemoryManager5AllocEjPKcib
 *     (25 words, 0 pool words).
 * _Alloc direct callees: the anonymous lazy init 0x27b918 (recovered name
 * initializeMemoryMutex), Mutex::Lock 0x27e084, bucketAlloc 0x27c53c,
 * malloc@plt 0xb6544, Mutex::Unlock 0x27e09c; the shared unlock tail
 * 0x27cd98-0x27cda4 is reached from bucket success, gate/malloc failure
 * and full success alike. The four standard counters are LIVE-updated in
 * the original order total 0x3f03e0, inUse 0x3f03ec, standardCount
 * 0x3f185c, standardSize 0x3f03e8 (intake allocator_global_bindings).
 * Alloc direct callees: MemoryManager::_Alloc (kept as a real BL edge),
 * memset@plt 0xb65b0 and logLocation 0x27bcf4, whose body is BX LR in
 * this image; the call edge is preserved, not stubbed away.
 * The file/line ABI is retained but never consumed by _Alloc; bucketAlloc
 * receives the ORIGINAL bool (no forced TRUE from ReAlloc on this path).
 * _Alloc itself has NO zero-size guard: a direct _Alloc(0,...) still runs
 * bucketAlloc. The malloc fallback uses the 64-bit widened (size+16)
 * gate (ADDS/ADC at 0x27cda8-0x27cdb0 vs CMP/SBCS/BGE 0xfffffffe at
 * 0x27cdb4-0x27cdc4), so a wrapping u32 size never reaches malloc.
 * gap: full MemoryManager/CBucket class shape, bad-header fault domains,
 * private LR/unwind behaviour, cross-thread concurrency and the raw
 * noncanonical r3 bool entry domain remain unproved; the wrapper's
 * TST 0x27ce98 is read in the normal bool 0/1 ABI domain only.
 */

#include "memory_alloc.hpp"

namespace {

/* Raw header words via uint32 address maths and may-alias volatile
 * accesses, mirroring the str r7/r9/r2/r3 stores; no out-of-bounds C++
 * pointer arithmetic and no aliasing-unpermissioned casts. */
typedef uint32_t HeaderWord __attribute__((may_alias));

void writeHeaderWord(uint32_t address, uint32_t value) {
    *reinterpret_cast<volatile HeaderWord *>(static_cast<uintptr_t>(address)) =
        value;
}

constexpr uint32_t kStandardMagic = 0xdeadc0deu; /* 0x27cde0-0x27cde8 movw/movt */
constexpr uint32_t kStandardCookie = 0xbaadb00bu; /* 0x27cdf0-0x27cdf8 */
constexpr uint64_t kWidthGateLimit = 0xfffffffeull; /* 0x27cdb4 mvn #1 */

} // namespace

void *MemoryManager::_Alloc(unsigned int size, const char *, int, bool zero) {
    /* 0x27cd5c-0x27cd78: LIVE read of g_MemoryMutex through its GOT slot;
     * a null slot calls the anonymous lazy init 0x27b918, the slot is
     * re-read at 0x27ce58, then fall into Lock 0x27cd7c. No failure
     * guard exists in the original. */
    Mutex *mutex = g_MemoryMutex;
    if (mutex == nullptr) {
        initializeMemoryMutex();
        mutex = g_MemoryMutex;
    }
    mutex->Lock(); /* 0x27cd7c, result unconsumed */

    /* 0x27cd80-0x27cd94: real bucketAlloc(size, original bool); a nonzero
     * result becomes the held pointer and branches straight to the
     * shared unlock tail. */
    void *held = bucketAlloc(size, zero);
    if (held == nullptr) {
        /* 0x27cda8-0x27cdc4: widen size+16 to 64 bits (ADDS sets the
         * carry, ADC materialises the high word) and gate against
         * 0xfffffffe with CMP/SBCS/BGE. Only then malloc the low word;
         * a gated-out or NULL malloc leaves held == NULL. */
        const uint64_t need = static_cast<uint64_t>(size) + 16ull;
        void *block = nullptr;
        if (need <= kWidthGateLimit) {
            block = malloc(static_cast<unsigned int>(need)); /* 0x27cdd0 */
        }
        if (block != nullptr) {
            /* 0x27cddc-0x27ce00: standard header, original store order
             * +0 size, +c held failed bucket result (zero), +4 magic,
             * +8 cookie; the payload pointer is base+16. */
            const uint32_t base = static_cast<uint32_t>(
                reinterpret_cast<uintptr_t>(block));
            writeHeaderWord(base, size);
            writeHeaderWord(base + 12u, static_cast<uint32_t>(
                reinterpret_cast<uintptr_t>(held)));
            writeHeaderWord(base + 4u, kStandardMagic);
            writeHeaderWord(base + 8u, kStandardCookie);
            held = reinterpret_cast<void *>(
                static_cast<uintptr_t>(base + 16u));

            /* 0x27ce04-0x27ce4c: LIVE counter updates in the original
             * order, each a fresh load/store of the real global; no
             * pre-snapshot of the four counters. */
            memory_state::total += size;
            memory_state::inUse += size;
            memory_state::standardCount += 1u;
            memory_state::standardSize += size;
        }
    }

    /* 0x27cd98-0x27cda4 shared tail: the mutex pointer is re-read LIVE
     * from the g_MemoryMutex slot for the unlock; no RAII, no Lock
     * result check, no exception unwinding is invented. */
    g_MemoryMutex->Unlock();
    return held;
}

void *MemoryManager::Alloc(unsigned int size, const char *file, int line,
                           bool zero) {
    /* 0x27ce7c-0x27ce84: subs on size, beq exit; zero size returns NULL
     * before any _Alloc or logging. */
    if (size == 0u) {
        return nullptr;
    }

    /* 0x27ce88: real four-argument _Alloc call, r1/r2 (file/line) are
     * never touched in the original either; the call edge is kept. */
    void *const ptr = _Alloc(size, file, line, zero);

    /* 0x27ce8c-0x27ce94: normalise ptr!=NULL (r1) then 0x27ce98 TST it
     * against the bool; in the normal 0/1 bool ABI domain this is the
     * logical AND. A NULL result returns 0 with no log and no clearing. */
    if (ptr == nullptr) {
        return nullptr;
    }
    if (zero) {
        memset(ptr, 0, size); /* 0x27cecc: memset return is discarded */
    }

    /* 0x27cea8-0x27ceb8: ALWAYS the real logLocation(ELogType 0, NULL,
     * held ptr, size) on the success route; its body is BX LR here but
     * the call stays. 0x27cebc returns the held pointer, never the
     * memset/log return value. */
    logLocation(static_cast<ELogType>(0), nullptr, ptr, size);
    return ptr;
}
