/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU carries two complete bodies:
 *   MemoryManager::ReAlloc(void*,unsigned int,const char*,int,bool)
 *     @ 0x27cedc, size 396, _ZN13MemoryManager7ReAllocEPvjPKcib
 *     (defined_dynsym), and
 *   bucketSize(const void*) @ 0x27c1e4, size 40, _Z10bucketSizePKv
 *     (defined_dynsym), declared noinline so ReAlloc keeps the original
 *     helper edge (BL 0x27c1e4 at 0x27cf10).
 * Direct ReAlloc callees: MemoryManager::Alloc 0x27ce78 (null-ptr tail
 * 0x27d04c and grow 0x27cfe0, forced TRUE fourth arg), bucketSize,
 * Mutex::Lock 0x27e084, MemoryManager::Free 0x27c2d0 (grow 0x27d018 and
 * dead zero-size branch 0x27cfbc), Mutex::Unlock 0x27e09c via the shared
 * tail 0x27cfc0, console vptr slot +0xc variadic print of
 * "Why are we reallocing a block that we didn't alloc?!\n" @0x357244
 * (0x27cf40-0x27cf5c), libc memset@plt 0xb65b0, memcpy@plt 0xb65bc and
 * abort@plt 0xb6c88. lazy-init 0x27b918 -> initializeMemoryMutex.
 * bucketSize dispatches vptr+0x8 with ONLY the bucket receiver in r0:
 * the original body contains no mov r1, so the looked-up block pointer
 * is deliberately not forwarded (unlike bucketFree's +0xc call).
 * The fifth bool parameter of ReAlloc is never read (no stack slot load)
 * and never forwarded; the TRUE passed to Alloc on the null-pointer tail
 * and on the grow path is the original's own forced value, not a caller
 * policy relay.
 * gap: fault domains of bad headers, the console print's callee-side
 * behaviour, abort unwinding, recursive locking and cross-thread mutex
 * republication remain unproved. The p[-4] raw word kept as oldSize on
 * the validated-backref path is the original NEGATIVE WORD (0x27cfa0
 * cmp uses it unsigned), not a decoded capacity; the backref header's
 * real size word is deliberately never consulted to "fix" it. The
 * zero-newsize Free branch (0x27cfb4) is unreachable because the oldSize
 * >= newsize test is unsigned, yet it is preserved verbatim rather than
 * reinterpreted as realloc(p,0). All address adds/subs and size maths
 * wrap as 32-bit, per the original.
 */

#include "memory_realloc_internal.hpp"

/* memset@plt 0xb65b0 (call 0x27cff4) and memcpy@plt 0xb65bc (call
 * 0x27d00c) are the real libc imports, declared once by the canonical
 * frozen chain (ccode.hpp / vm_buffer.hpp); no duplicate declaration
 * here, -fno-builtin keeps both calls real. */

namespace {

/* Offsets are uint32 address maths mirroring ldr rN,[r5,#-off]; volatile
 * reads keep every original load, short-circuit order mirrors the branch
 * graph 1:1 (p[-16] is read before the p[-12] compare; p[-8] only when
 * p[-12] matched; p[-4] only on the backref route). */
typedef uint32_t HeaderWord __attribute__((may_alias));

constexpr uint32_t kStandardMagic = 0xdeadc0deu; /* 0x27cf20-0x27cf24 movw/movt */
constexpr uint32_t kBackrefMagic = 0xbaadb00bu;  /* 0x27d024-0x27d028 */
constexpr uint32_t kBit31ClearMask = 0x7fffffffu; /* 0x27cf64 bic */
constexpr uint32_t kBackrefLimit = 8192u;         /* 0x27cf68 cmp #8192 */

uint32_t readHeaderWord(uint32_t address) {
    return *reinterpret_cast<const volatile HeaderWord *>(
        static_cast<uintptr_t>(address));
}

/* 0x27cf40-0x27cf60 shared bad-header exit, reached from signed-r6>=0,
 * distance>=8192 and both backref magic mismatches. ONE snapshot of the
 * live dbg_csol (ldr r0,[r3]), then its vptr slot +0xc variadic print
 * (format only, no extra args set), then the real abort. The mutex is
 * still held on this path: no cleanup, no catch, no unlock is added. */
[[noreturn]] void reallocBadHeaderExit() {
    VMDebugConsolePrefix *const console = dbg_csol;
    console->table->print(console,
                          "Why are we reallocing a block that we didn't alloc?!\n");
    abort(); /* imported noreturn abort@plt 0xb6c88 */
}

} // namespace

uint32_t bucketSize(const void *p) {
    /* 0x27c1e8: real declared globalPageListFindAddr (0x27be34), body in
     * page_lookup.cpp. 0x27c1ec-0x27c1f0: a null lookup returns 0 via
     * mov r0,r3 with r3==0. */
    BucketPrefix *bucket = globalPageListFindAddr(p);
    if (bucket == nullptr) {
        return 0u;
    }
    /* 0x27c1f4-0x27c1fc: r3=[[r0]], r3=[[r3,#8]], blx r3 with r0 still
     * holding the bucket. Receiver only: the original pointer argument
     * p is NOT forwarded as a second GP parameter. */
    const volatile BucketPrefix *const state = bucket;
    const volatile BucketVtablePrefix *const table = state->vptr;
    const BucketSizeEntry invoke = table->sizeEntry; /* +0x08 */
    return invoke(bucket);
}

void *MemoryManager::ReAlloc(void *p, unsigned int newsize, const char *file,
                             int line, bool /* 0x27cedc never reads arg4 */) {
    /* 0x27cee0-0x27cef0: null block tail-branches to Alloc(newsize, file,
     * line, TRUE) with the original prologue popped; no mutex is read or
     * initialised on this path. */
    if (p == nullptr) {
        return Alloc(newsize, file, line, true);
    }

    /* 0x27cef4-0x27cf04: read the LIVE g_MemoryMutex; a null pointer
     * calls the anonymous lazy init 0x27b918 and the slot is re-read at
     * 0x27d054. No null-failure guard exists in the original. */
    Mutex *mutex = g_MemoryMutex;
    if (mutex == nullptr) {
        initializeMemoryMutex();
        mutex = g_MemoryMutex;
    }
    mutex->Lock(); /* 0x27cf08, result unconsumed */

    /* 0x27cf10-0x27cf18: nonzero bucketSize IS the old size. */
    uint32_t oldSize = bucketSize(p);
    if (oldSize == 0u) {
        const uint32_t address =
            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(p));

        /* 0x27cf1c-0x27cf28: the p[-16] size word is fetched before the
         * p[-12] magic compare, so it is read even on routes that then
         * discard it. */
        const uint32_t headerMagic = readHeaderWord(address - 12u); // 0x27cf1c FIRST
        const uint32_t headerSize = readHeaderWord(address - 16u);  // 0x27cf28, still before compare
        if (headerMagic == kStandardMagic &&
            readHeaderWord(address - 8u) == kBackrefMagic) {
            /* 0x27cf2c/0x27d020-0x27d034: both direct magics matched. */
            oldSize = headerSize;
        } else {
            /* 0x27cf34-0x27cf9c: p[-4] as signed; nonneg or too-far or a
             * magic mismatch at base+4/+8 all go to the shared bad-header
             * exit (base = (p-16) - bit31-cleared word). */
            const int32_t rawOffset =
                static_cast<int32_t>(readHeaderWord(address - 4u));
            if (rawOffset >= 0) {
                reallocBadHeaderExit();
            }
            const uint32_t offset =
                static_cast<uint32_t>(rawOffset) & kBit31ClearMask;
            if (offset >= kBackrefLimit) {
                reallocBadHeaderExit();
            }
            const uint32_t backref = address - 16u - offset;
            if (readHeaderWord(backref + 4u) != kStandardMagic ||
                readHeaderWord(backref + 8u) != kBackrefMagic) {
                reallocBadHeaderExit();
            }
            /* Validation passed with r6 STILL the raw p[-4] word (0x27cfa0
             * cmp r6,r7), a negative int viewed unsigned here. The real
             * backref capacity is never read; not "fixed" on purpose. */
            oldSize = static_cast<uint32_t>(rawOffset);
        }
    }

    /* 0x27cfa0-0x27cfa8: UNSIGNED compare; fits (including newsize==0)
     * return the original pointer. 0x27cfac-0x27cfbc: the shrink-to-zero
     * Free is preserved verbatim although unreachable under the unsigned
     * predicate; it is NOT reinterpreted as realloc(p,0) semantics. */
    if (oldSize >= newsize) {
        /* 0x27cfc0: unlock receiver is a fresh LIVE read of g_MemoryMutex
         * (ldr r0,[r4]), not the entry snapshot; no RAII may capture it. */
        g_MemoryMutex->Unlock();
        return p;
    }
    if (newsize == 0u) {
        Free(p);
        g_MemoryMutex->Unlock();
        return nullptr;
    }

    /* 0x27cfd0-0x27cfe0: grow ALLOCATES with the original's own forced
     * TRUE (arg4 of the caller is never relayed), still holding the
     * mutex; held across memset/memcpy/Free until the shared tail. */
    void *grown = Alloc(newsize, file, line, true);
    /* 0x27cfe4-0x27cff4: memset(grown + oldSize, 0, newsize - oldSize);
     * both are uint32 wrap operations, exactly ldr-add-rsb. */
    const uint32_t grownAddress = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(grown));
    memset(reinterpret_cast<void *>(static_cast<uintptr_t>(grownAddress + oldSize)),
           0, newsize - oldSize); // explicit ARM32 address wrap, not C pointer arithmetic
    /* 0x27cff8-0x27d00c: memcpy(grown, p, min unsigned(oldSize, newsize));
     * the movlo/movhs pair is the compare-select, return value discarded. */
    memcpy(grown, p, oldSize < newsize ? oldSize : newsize);
    /* 0x27d010-0x27d01c: real MemoryManager::Free(p) under the held lock,
     * return holder r8 = grown (0x27d014), then the shared unlock tail
     * re-reads the live global. */
    Free(p);
    g_MemoryMutex->Unlock();
    return grown;
}
