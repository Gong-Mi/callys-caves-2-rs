/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU carries ONE complete body: 518 original words = 504 code words +
 * 14 literal-pool words (0x27cd1c-0x27cd50), bucketAlloc(unsigned,bool)
 * @ 0x27c53c..0x27cd54, size 2072, _Z11bucketAllocjb.
 * Direct callees: malloc@plt 0xb6544 (init 128-byte page table, NO null
 * guard), the real operator new 0x27c524 (_Znwj, seven fresh-page sizes,
 * NO null guard and NO provider), memset@plt 0xb65b0 (the 0x78 fresh-page
 * fill plus the six non-8B zero requests), addPageToGlobalPageList 0x27bcf8
 * (316B body in page_registry.cpp, called with base and base+newBytes-1
 * verbatim) and the console vptr slot +0xc variadic
 * print of "shouldn't get here - size %d - %08x\n" @0x35721c
 * (0x27c984-0x27c9b8).
 * Entry state (0x27c55c-0x27c578): the anonymous byte at 0x756699 is read
 * FIRST; only a zero value consults bucketsShouldInit 0x75669a, and a zero
 * enable byte returns 0 without initializing anything. The init block sets
 * pagedata_size = 16, publishes g_pages = malloc(128), then clears ONLY
 * +4/+8/+c of the seven inline 20B bucket objects (never the +0 vptr, never
 * the +10 freeCount) in the original order 8/16/32/64/128/256, stores
 * initialized = 1, and only then clears the last (_16Kbyte) three words.
 * There is no page-table memset, no count reset and no allocation guard.
 * Eligibility (0x27c644-0x27c654, CMP #16384 / CMPNE #256): the domain is
 * unsigned size <= 256 OR size == 16384; everything else returns 0. Size 0
 * IS eligible and dispatches into the 8-byte bucket (CMP #8 / BLS). The
 * MOVLS/MOVHI result register is kept live because the default block stores
 * #42 into it.
 * Every bucket case carries its own pop tail (0x27c6ac, 0x27c710, 0x27c760,
 * 0x27c7b0, 0x27c81c, 0x27c86c, 0x27c8bc) and its own far-away fresh-page
 * block that JOINS that tail in the middle: the fresh path skips the
 * freeCount(+10) and node(+0) loads, hands over the held "previous" word as
 * the new freeHead plus the case addend, and then performs the LIVE
 * activeCount(+c) read. The 8B zero path is EIGHT inline volatile byte
 * stores (0..7), never memset; the other six call memset(node, 0, BUCKET
 * STRIDE) - the stride, never the requested size - and its return value is
 * dropped, exactly like the original. The outer duplicate zero-fill in
 * _Alloc/Alloc belongs to other TUs and is not reproduced here.
 * gap: the private frame, LR, fault and unwind
 * behaviour, cross-thread concurrency, the raw noncanonical bool entry
 * domain and any original-execution/rebuilt-execution equivalence remain
 * unproved. The default diagnostic block is provably unreachable under the
 * normal eligibility predicate; its source is retained, not a promise that
 * an optimizer emits unreachable code. No YYError/abort is invented
 * for it and no fault is certified.
 */

#include "memory_buckets.hpp"

namespace {

/* Page words are touched as raw uint32 address maths through may-alias
 * volatile accesses, mirroring ldr/str [rN] and [rN,#post-index]: no C++
 * object is fabricated over a fresh operator new block beyond the two
 * observed prefix words, and no fake complete bucket class is introduced. */
typedef uint32_t BucketWord __attribute__((may_alias));
typedef uint8_t BucketByte __attribute__((may_alias));

inline uint32_t readBucketWord(uintptr_t address) {
    return *reinterpret_cast<const volatile BucketWord *>(address);
}

inline void writeBucketWord(uintptr_t address, uint32_t value) {
    *reinterpret_cast<volatile BucketWord *>(address) = value;
}

/* Fresh pages: the two header words are raw stores. The next link must
 * precede head publication; owner must follow both post-callback reads. */
static_assert(offsetof(BucketPagePrefix, next) == 0, "page next word");
static_assert(offsetof(BucketPagePrefix, owner) == 4, "page owner word");

/* 0x27c7d8-0x27c7f8: the 8-byte zero path writes one byte at a time. */
inline void writeBucketZeroByte(uintptr_t address) {
    *reinterpret_cast<volatile BucketByte *>(address) = 0u;
}

/* Keep the original external memset edge on the six non-8B zero paths.
 * The empty ARM register constraint delivers the exact size unchanged, but
 * prevents Clang from replacing the call with an inline constant-size fill. */
__attribute__((always_inline)) inline void clearBucketBlock(uintptr_t address, size_t size) {
    asm volatile("" : "+r"(size));
    memset(reinterpret_cast<void *>(address), 0, size);
}

/* 0x27c9b4 is a plain STR of #42 to the held eligibility-register value
 * (0 on the LS path). A real ARM str keeps that write outside C++ null
 * dereference UB; nothing here certifies the fault it would take. */
inline void storeWordByRawArmStr(uintptr_t address, uint32_t value) {
    asm volatile("str %[value], [%[address]]"
                 :
                 : [value] "r"(value), [address] "r"(address)
                 : "memory");
}

constexpr uint32_t kFreshFillByte = 0x78u; /* mov r1, #120 in all 7 blocks */
constexpr uintptr_t kFreshFillStart = 8u;  /* add r0, r0, #8 before memset */

} // namespace

void *bucketAlloc(unsigned int size, bool zero) {
    /* 0x27c55c-0x27c564: anonymous state byte read first; nonzero bypasses
     * the enable flag and falls straight into eligibility. */
    if (bucket_state::initialized == 0u) {
        /* 0x27c568-0x27c578: LIVE bucketsShouldInit byte; a zero enable
         * returns 0 with NOTHING initialized. */
        if (bucketsShouldInit == 0u) {
            return nullptr;
        }
        /* 0x27c57c-0x27c598: pagedata_size = 16 is stored BEFORE malloc. */
        pagedata_size = 16u;
        void *const pageTable = malloc(128u); /* 0x27c580/0x27c59c, no guard */
        g_pages = static_cast<const volatile uint32_t *>(pageTable); /* 0x27c5c4 */
        /* 0x27c5d0-0x27c62c: three stores per bucket (+4 pageHead,
         * +8 freeHead, +c activeCount) using the just-read state byte,
         * which is 0 on this path. +0 vptr and +10 freeCount are NOT
         * touched; the six buckets are cleared in this exact order. */
        const auto clearActiveState = [](auto &object) {
            volatile auto &live = object;
            live.pageHead = nullptr;
            live.freeHead = nullptr;
            live.activeCount = 0u;
        };
        clearActiveState(_8byte.object);
        clearActiveState(_16byte.object);
        clearActiveState(_32byte.object);
        clearActiveState(_64byte.object);
        clearActiveState(_128byte.object);
        clearActiveState(_256byte.object);
        /* 0x27c634: initialized = 1 lands BEFORE the last bucket's words. */
        bucket_state::initialized = 1u;
        clearActiveState(_16Kbyte.object);
    }

    /* 0x27c644-0x27c654: CMP #16384 / CMPNE #256 -> r4 = 0 for the
     * eligible domain, 1 otherwise; the HI result returns 0. The value is
     * held because the default block below stores #42 into it. */
    uintptr_t eligibilityWord = (size <= 256u || size == 16384u) ? 0u : 1u;
    if (eligibilityWord != 0u) {
        return nullptr; /* 0x27c6e8-0x27c6f0 */
    }

    /* ---- size <= 8: _8byte (0x27c658/0x27c65c, pop 0x27c794, fresh
     *      0x27c9bc) ---- */
    if (size <= 8u) {
        volatile auto *const pool = &_8byte.object; /* 0x27c794-0x27c798 */
        uintptr_t node = reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27c79c */
        uintptr_t next;
        uint32_t freeCount;
        if (node != 0u) { /* 0x27c7a0/0x27c7a4 */
            freeCount = pool->freeCount; /* 0x27c7a8: +10 LIVE */
            next = readBucketWord(node); /* 0x27c7ac: node+0 */
        } else {
            const uintptr_t base =
                reinterpret_cast<uintptr_t>(operator new(0x20010u)); /* 0x27c9bc/0x27c9c0 */
            memset(reinterpret_cast<void *>(base + kFreshFillStart), kFreshFillByte, 0x20008u); /* 0x27c9c8/0x27c9cc/0x27c9d4/0x27c9d8 */
            const uintptr_t first = (base + 0x10u) & ~0x7u; /* 0x27c9dc/0x27c9f4 */
            BucketPagePrefix *const page = reinterpret_cast<BucketPagePrefix *>(base);
            writeBucketWord(base, reinterpret_cast<uintptr_t>(pool->pageHead)); /* 0x27c9e4/0x27c9f8 */
            pool->pageHead = page;       /* 0x27c9fc: published BEFORE callback */
            addPageToGlobalPageList(page,
                                    reinterpret_cast<void *>(base + 0x2000fu)); /* 0x27c9e8/0x27c9f0/0x27ca00 */
            const uintptr_t oldFreeHead =
                reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27ca04: LIVE +8 */
            freeCount = pool->freeCount;                     /* 0x27ca10: LIVE +10 */
            writeBucketWord(base + 4u, reinterpret_cast<uintptr_t>(pool)); /* 0x27ca18 */
            const uintptr_t span = first + 0x1fc00u;   /* 0x27ca08 */
            const uintptr_t loopEnd = span + 0x3f8u;   /* 0x27ca14 -> first+0x1fff8 */
            uintptr_t cursor = first;                  /* 0x27ca0c mov r3, r6 */
            uintptr_t storeValue = first;              /* 0x27ca1c mov r2, r6 */
            writeBucketWord(cursor, static_cast<uint32_t>(oldFreeHead)); /* 0x27ca20 str r1,[r3],#8 */
            cursor = first + 8u;
            do {
                const uintptr_t current = cursor;              /* 0x27ca2c mov r1, r3 */
                writeBucketWord(current, storeValue);          /* 0x27ca30 str r2,[r3],#8 */
                cursor = current + 8u;
                if (cursor == loopEnd) {
                    break; /* 0x27ca34/0x27ca38: exit keeps the last previous */
                }
                storeValue = current; /* 0x27ca28 back edge only: mov r2, r1 */
            } while (true);
            node = span + 0x3f0u;     /* 0x27ca40 -> first+0x1fff0 */
            next = storeValue;        /* held previous register at the join */
            freeCount += 0x3fc0u;     /* 0x27ca3c */
            freeCount += 0x3fu;       /* 0x27ca44: +0x3fff, pop subtracts 1 */
        }
        uint32_t activeCount = pool->activeCount; /* 0x27c7b0: +c LIVE join read */
        pool->freeHead = reinterpret_cast<uint8_t *>(next); /* 0x27c7bc */
        pool->freeCount = freeCount - 1u;                   /* 0x27c7b8/0x27c7c0 */
        pool->activeCount = activeCount + 1u;               /* 0x27c7c4/0x27c7c8 */
        if (zero) { /* 0x27c7cc fall-through: NO memset here */
            writeBucketZeroByte(node + 0u); /* 0x27c7d8 */
            writeBucketZeroByte(node + 1u); /* 0x27c7e0 */
            writeBucketZeroByte(node + 2u); /* 0x27c7e4 */
            writeBucketZeroByte(node + 3u); /* 0x27c7e8 */
            writeBucketZeroByte(node + 4u); /* 0x27c7ec */
            writeBucketZeroByte(node + 5u); /* 0x27c7f0 */
            writeBucketZeroByte(node + 6u); /* 0x27c7f4 */
            writeBucketZeroByte(node + 7u); /* 0x27c7f8 */
        }
        return reinterpret_cast<void *>(node); /* 0x27c6e0 (r0 already node) */
    } else if (size <= 16u) {
        /* ---- _16byte (0x27c660/0x27c664, pop 0x27c800, fresh 0x27cadc) ---- */
        volatile auto *const pool = &_16byte.object;
        uintptr_t node = reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27c808 */
        uintptr_t next;
        uint32_t freeCount;
        if (node != 0u) {
            freeCount = pool->freeCount; /* 0x27c814 */
            next = readBucketWord(node); /* 0x27c818 */
        } else {
            const uintptr_t base =
                reinterpret_cast<uintptr_t>(operator new(0x40018u)); /* 0x27cadc/0x27cae0 */
            memset(reinterpret_cast<void *>(base + kFreshFillStart), kFreshFillByte, 0x40010u); /* 0x27cae8/0x27caec/0x27caf0/0x27caf8 */
            const uintptr_t first = (base + 0x18u) & ~0xfu; /* 0x27cb10/0x27cb18 */
            BucketPagePrefix *const page = reinterpret_cast<BucketPagePrefix *>(base);
            writeBucketWord(base, reinterpret_cast<uintptr_t>(pool->pageHead)); /* 0x27cb00/0x27cb14 */
            pool->pageHead = page;       /* 0x27cb1c */
            addPageToGlobalPageList(page,
                                    reinterpret_cast<void *>(base + 0x40017u)); /* 0x27cb04/0x27cb0c/0x27cb20 */
            const uintptr_t oldFreeHead = reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27cb24 */
            freeCount = pool->freeCount;                                           /* 0x27cb30 */
            writeBucketWord(base + 4u, reinterpret_cast<uintptr_t>(pool)); /* 0x27cb38 */
            const uintptr_t span = first + 0x3fc00u;  /* 0x27cb28 */
            const uintptr_t loopEnd = span + 0x3f0u;  /* 0x27cb34 -> first+0x3fff0 */
            uintptr_t cursor = first;
            uintptr_t storeValue = first;             /* 0x27cb3c */
            writeBucketWord(cursor, static_cast<uint32_t>(oldFreeHead)); /* 0x27cb40 str r1,[r3],#16 */
            cursor = first + 16u;
            do {
                const uintptr_t current = cursor;              /* 0x27cb4c */
                writeBucketWord(current, storeValue);          /* 0x27cb50 */
                cursor = current + 16u;
                if (cursor == loopEnd) {
                    break; /* 0x27cb54/0x27cb58 */
                }
                storeValue = current; /* 0x27cb48 back edge */
            } while (true);
            node = span + 0x3e0u;    /* 0x27cb60 -> first+0x3ffe0 */
            next = storeValue;
            freeCount += 0x3fc0u;    /* 0x27cb5c */
            freeCount += 0x3fu;      /* 0x27cb64: +0x3fff */
        }
        uint32_t activeCount = pool->activeCount; /* 0x27c81c */
        pool->freeHead = reinterpret_cast<uint8_t *>(next); /* 0x27c828 */
        pool->freeCount = freeCount - 1u;                   /* 0x27c824/0x27c82c */
        pool->activeCount = activeCount + 1u;               /* 0x27c830/0x27c834 */
        if (zero) {
            clearBucketBlock(node, 16u); /* 0x27c83c-0x27c848: stride, result dropped */
        }
        return reinterpret_cast<void *>(node); /* 0x27c6dc */
    } else if (size <= 32u) {
        /* ---- _32byte (0x27c668/0x27c66c, pop 0x27c6f4, fresh 0x27cb6c) ---- */
        volatile auto *const pool = &_32byte.object;
        uintptr_t node = reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27c6fc */
        uintptr_t next;
        uint32_t freeCount;
        if (node != 0u) {
            freeCount = pool->freeCount; /* 0x27c708 */
            next = readBucketWord(node); /* 0x27c70c */
        } else {
            const uintptr_t base =
                reinterpret_cast<uintptr_t>(operator new(0x40028u)); /* 0x27cb6c/0x27cb70 */
            memset(reinterpret_cast<void *>(base + kFreshFillStart), kFreshFillByte, 0x40020u); /* 0x27cb78/0x27cb7c/0x27cb80/0x27cb88 */
            const uintptr_t first = (base + 0x28u) & ~0x1fu; /* 0x27cba0/0x27cba8 */
            BucketPagePrefix *const page = reinterpret_cast<BucketPagePrefix *>(base);
            writeBucketWord(base, reinterpret_cast<uintptr_t>(pool->pageHead)); /* 0x27cb90/0x27cba4 */
            pool->pageHead = page;       /* 0x27cbac */
            addPageToGlobalPageList(page,
                                    reinterpret_cast<void *>(base + 0x40027u)); /* 0x27cb94/0x27cb9c/0x27cbb0 */
            const uintptr_t oldFreeHead = reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27cbb4 */
            freeCount = pool->freeCount;                                              /* 0x27cbc0 */
            writeBucketWord(base + 4u, reinterpret_cast<uintptr_t>(pool)); /* 0x27cbc8 */
            const uintptr_t span = first + 0x3fc00u;  /* 0x27cbb8 */
            const uintptr_t loopEnd = span + 0x3e0u;  /* 0x27cbc4 -> first+0x3ffe0 */
            uintptr_t cursor = first;
            uintptr_t storeValue = first;             /* 0x27cbcc */
            writeBucketWord(cursor, static_cast<uint32_t>(oldFreeHead)); /* 0x27cbd0 str r1,[r3],#32 */
            cursor = first + 32u;
            do {
                const uintptr_t current = cursor;              /* 0x27cbdc */
                writeBucketWord(current, storeValue);          /* 0x27cbe0 */
                cursor = current + 32u;
                if (cursor == loopEnd) {
                    break; /* 0x27cbe4/0x27cbe8 */
                }
                storeValue = current; /* 0x27cbd8 back edge */
            } while (true);
            node = span + 0x3c0u;    /* 0x27cbf0 -> first+0x3ffc0 */
            next = storeValue;
            freeCount += 0x1fc0u;    /* 0x27cbec */
            freeCount += 0x3fu;      /* 0x27cbf4: +0x1fff */
        }
        uint32_t activeCount = pool->activeCount; /* 0x27c710 */
        pool->freeHead = reinterpret_cast<uint8_t *>(next); /* 0x27c71c */
        pool->freeCount = freeCount - 1u;                   /* 0x27c718/0x27c720 */
        pool->activeCount = activeCount + 1u;               /* 0x27c724/0x27c728 */
        if (zero) {
            clearBucketBlock(node, 32u); /* 0x27c730-0x27c73c, result dropped */
        }
        return reinterpret_cast<void *>(node);
    } else if (size <= 64u) {
        /* ---- _64byte (0x27c670/0x27c674, pop 0x27c850, fresh 0x27cbfc) ---- */
        volatile auto *const pool = &_64byte.object;
        uintptr_t node = reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27c858 */
        uintptr_t next;
        uint32_t freeCount;
        if (node != 0u) {
            freeCount = pool->freeCount; /* 0x27c864 */
            next = readBucketWord(node); /* 0x27c868 */
        } else {
            const uintptr_t base =
                reinterpret_cast<uintptr_t>(operator new(0x80048u)); /* 0x27cbfc/0x27cc00 */
            memset(reinterpret_cast<void *>(base + kFreshFillStart), kFreshFillByte, 0x80040u); /* 0x27cc08/0x27cc0c/0x27cc10/0x27cc18 */
            const uintptr_t first = (base + 0x48u) & ~0x3fu; /* 0x27cc30/0x27cc38 */
            BucketPagePrefix *const page = reinterpret_cast<BucketPagePrefix *>(base);
            writeBucketWord(base, reinterpret_cast<uintptr_t>(pool->pageHead)); /* 0x27cc20/0x27cc34 */
            pool->pageHead = page;       /* 0x27cc3c */
            addPageToGlobalPageList(page,
                                    reinterpret_cast<void *>(base + 0x80047u)); /* 0x27cc24/0x27cc2c/0x27cc40 */
            const uintptr_t oldFreeHead = reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27cc44 */
            freeCount = pool->freeCount;                                              /* 0x27cc50 */
            writeBucketWord(base + 4u, reinterpret_cast<uintptr_t>(pool)); /* 0x27cc58 */
            const uintptr_t span = first + 0x7f000u;  /* 0x27cc48 */
            const uintptr_t loopEnd = span + 0xfc0u;  /* 0x27cc54 -> first+0x7ffc0 */
            uintptr_t cursor = first;
            uintptr_t storeValue = first;             /* 0x27cc5c */
            writeBucketWord(cursor, static_cast<uint32_t>(oldFreeHead)); /* 0x27cc60 str r1,[r3],#64 */
            cursor = first + 64u;
            do {
                const uintptr_t current = cursor;              /* 0x27cc6c */
                writeBucketWord(current, storeValue);          /* 0x27cc70 */
                cursor = current + 64u;
                if (cursor == loopEnd) {
                    break; /* 0x27cc74/0x27cc78 */
                }
                storeValue = current; /* 0x27cc68 back edge */
            } while (true);
            node = span + 0xf80u;    /* 0x27cc80 -> first+0x7ff80 */
            next = storeValue;
            freeCount += 0x1fc0u;    /* 0x27cc7c */
            freeCount += 0x3fu;      /* 0x27cc84: +0x1fff */
        }
        uint32_t activeCount = pool->activeCount; /* 0x27c86c */
        pool->freeHead = reinterpret_cast<uint8_t *>(next); /* 0x27c878 */
        pool->freeCount = freeCount - 1u;                   /* 0x27c874/0x27c87c */
        pool->activeCount = activeCount + 1u;               /* 0x27c880/0x27c884 */
        if (zero) {
            clearBucketBlock(node, 64u); /* 0x27c88c-0x27c898, result dropped */
        }
        return reinterpret_cast<void *>(node);
    } else if (size <= 128u) {
        /* ---- _128byte (0x27c678/0x27c67c, pop 0x27c8a0, fresh 0x27cc8c) ---- */
        volatile auto *const pool = &_128byte.object;
        uintptr_t node = reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27c8a8 */
        uintptr_t next;
        uint32_t freeCount;
        if (node != 0u) {
            freeCount = pool->freeCount; /* 0x27c8b4 */
            next = readBucketWord(node); /* 0x27c8b8 */
        } else {
            const uintptr_t base =
                reinterpret_cast<uintptr_t>(operator new(0x80088u)); /* 0x27cc8c/0x27cc90 */
            memset(reinterpret_cast<void *>(base + kFreshFillStart), kFreshFillByte, 0x80080u); /* 0x27cc98/0x27cc9c/0x27cca0/0x27cca8 */
            const uintptr_t first = (base + 0x88u) & ~0x7fu; /* 0x27ccc0/0x27ccc8 */
            BucketPagePrefix *const page = reinterpret_cast<BucketPagePrefix *>(base);
            writeBucketWord(base, reinterpret_cast<uintptr_t>(pool->pageHead)); /* 0x27ccb0/0x27ccc4 */
            pool->pageHead = page;       /* 0x27cccc */
            addPageToGlobalPageList(page,
                                    reinterpret_cast<void *>(base + 0x80087u)); /* 0x27ccb4/0x27ccbc/0x27ccd0 */
            const uintptr_t oldFreeHead = reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27ccd4 */
            freeCount = pool->freeCount;                                              /* 0x27cce0 */
            writeBucketWord(base + 4u, reinterpret_cast<uintptr_t>(pool)); /* 0x27cce8 */
            const uintptr_t span = first + 0x7f000u;  /* 0x27ccd8 */
            const uintptr_t loopEnd = span + 0xf80u;  /* 0x27cce4 -> first+0x7ff80 */
            uintptr_t cursor = first;
            uintptr_t storeValue = first;             /* 0x27ccec */
            writeBucketWord(cursor, static_cast<uint32_t>(oldFreeHead)); /* 0x27ccf0 str r1,[r3],#128 */
            cursor = first + 128u;
            do {
                const uintptr_t current = cursor;              /* 0x27ccfc */
                writeBucketWord(current, storeValue);          /* 0x27cd00 */
                cursor = current + 128u;
                if (cursor == loopEnd) {
                    break; /* 0x27cd04/0x27cd08 */
                }
                storeValue = current; /* 0x27ccf8 back edge */
            } while (true);
            node = span + 0xf00u;    /* 0x27cd10 -> first+0x7ff00 */
            next = storeValue;
            freeCount += 0xff0u;     /* 0x27cd0c */
            freeCount += 0xfu;       /* 0x27cd14: +0xfff */
        }
        uint32_t activeCount = pool->activeCount; /* 0x27c8bc */
        pool->freeHead = reinterpret_cast<uint8_t *>(next); /* 0x27c8c8 */
        pool->freeCount = freeCount - 1u;                   /* 0x27c8c4/0x27c8cc */
        pool->activeCount = activeCount + 1u;               /* 0x27c8d0/0x27c8d4 */
        if (zero) {
            clearBucketBlock(node, 128u); /* 0x27c8dc-0x27c8e8, result dropped */
        }
        return reinterpret_cast<void *>(node);
    } else if (size <= 256u) {
        /* ---- _256byte (0x27c680/0x27c684, pop 0x27c744, fresh 0x27c8f0) ---- */
        volatile auto *const pool = &_256byte.object;
        uintptr_t node = reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27c74c */
        uintptr_t next;
        uint32_t freeCount;
        if (node != 0u) {
            freeCount = pool->freeCount; /* 0x27c758 */
            next = readBucketWord(node); /* 0x27c75c */
        } else {
            const uintptr_t base =
                reinterpret_cast<uintptr_t>(operator new(0x100108u)); /* 0x27c8f0/0x27c8f4 */
            memset(reinterpret_cast<void *>(base + kFreshFillStart), kFreshFillByte, 0x100100u); /* 0x27c8fc/0x27c900/0x27c904/0x27c90c */
            const uintptr_t first = (base + 0x108u) & ~0xffu; /* 0x27c92c/0x27c930 */
            BucketPagePrefix *const page = reinterpret_cast<BucketPagePrefix *>(base);
            writeBucketWord(base, reinterpret_cast<uintptr_t>(pool->pageHead)); /* 0x27c914/0x27c928 */
            pool->pageHead = page;       /* 0x27c934 */
            addPageToGlobalPageList(page,
                                    reinterpret_cast<void *>(base + 0x100107u)); /* 0x27c918/0x27c91c/0x27c938 */
            const uintptr_t oldFreeHead = reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27c93c */
            freeCount = pool->freeCount;                                              /* 0x27c948 */
            writeBucketWord(base + 4u, reinterpret_cast<uintptr_t>(pool)); /* 0x27c950 */
            /* 0xff000 then 0xf00: the 0xfff00 loop end is an ADD result,
             * not an original immediate - keep both additions separate. */
            const uintptr_t span = first + 0xff000u;  /* 0x27c940 */
            const uintptr_t loopEnd = span + 0xf00u;  /* 0x27c94c -> first+0xfff00 */
            uintptr_t cursor = first;                 /* 0x27c944 mov r3, r7 */
            uintptr_t storeValue = first;             /* 0x27c954 mov r2, r7 */
            writeBucketWord(cursor, static_cast<uint32_t>(oldFreeHead)); /* 0x27c958 str r1,[r3],#256 */
            cursor = first + 256u;
            do {
                const uintptr_t current = cursor;              /* 0x27c964 */
                writeBucketWord(current, storeValue);          /* 0x27c968 */
                cursor = current + 256u;
                if (cursor == loopEnd) {
                    break; /* 0x27c96c/0x27c970 */
                }
                storeValue = current; /* 0x27c960 back edge */
            } while (true);
            node = span + 0xe00u;    /* 0x27c978 -> first+0xffe00 (never an fff00 immediate) */
            next = storeValue;
            freeCount += 0xff0u;     /* 0x27c974 */
            freeCount += 0xfu;       /* 0x27c97c: +0xfff */
        }
        uint32_t activeCount = pool->activeCount; /* 0x27c760 */
        pool->freeHead = reinterpret_cast<uint8_t *>(next); /* 0x27c76c */
        pool->freeCount = freeCount - 1u;                   /* 0x27c768/0x27c770 */
        pool->activeCount = activeCount + 1u;               /* 0x27c774/0x27c778 */
        if (zero) {
            clearBucketBlock(node, 256u); /* 0x27c780-0x27c78c, result dropped */
        }
        return reinterpret_cast<void *>(node);
    } else if (size == 16384u) {
        /* ---- _16Kbyte (0x27c688/0x27c690, pop 0x27c6ac, fresh 0x27ca4c) ---- */
        volatile auto *const pool = &_16Kbyte.object; /* 0x27c690-0x27c694 */
        uintptr_t node = reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27c698 */
        uintptr_t next;
        uint32_t freeCount;
        if (node != 0u) {
            freeCount = pool->freeCount; /* 0x27c6a4 */
            next = readBucketWord(node); /* 0x27c6a8 */
        } else {
            const uintptr_t base =
                reinterpret_cast<uintptr_t>(operator new(0x44008u)); /* 0x27ca4c/0x27ca50 */
            memset(reinterpret_cast<void *>(base + kFreshFillStart), kFreshFillByte, 0x44000u); /* 0x27ca58/0x27ca5c/0x27ca64 */
            const uintptr_t aligned = (base + 0x4000u + 8u) & ~0x3fc0u; /* 0x27ca70/0x27ca78/0x27ca84 */
            const uintptr_t first = aligned & ~0x3fu;                   /* 0x27ca8c */
            BucketPagePrefix *const page = reinterpret_cast<BucketPagePrefix *>(base);
            writeBucketWord(base, reinterpret_cast<uintptr_t>(pool->pageHead)); /* 0x27ca6c/0x27ca80 */
            pool->pageHead = page;       /* 0x27ca90 */
            addPageToGlobalPageList(page,
                                    reinterpret_cast<void *>(base + 0x44007u)); /* 0x27ca74/0x27ca7c/0x27ca94 */
            const uintptr_t oldFreeHead = reinterpret_cast<uintptr_t>(pool->freeHead); /* 0x27ca98 */
            freeCount = pool->freeCount;                                              /* 0x27caa0 */
            writeBucketWord(base + 4u, reinterpret_cast<uintptr_t>(pool)); /* 0x27caa8 */
            const uintptr_t step = 0x4000u;                 /* 0x27cac4 */
            const uintptr_t loopEnd = first + 0x3c000u;     /* 0x27caa4 */
            uintptr_t cursor = first + step;                /* 0x27ca9c */
            uintptr_t storeValue = first;                   /* 0x27caac */
            writeBucketWord(first, static_cast<uint32_t>(oldFreeHead)); /* 0x27cab0 str r0,[r5] */
            do {
                writeBucketWord(cursor, storeValue); /* 0x27cabc str r2,[r3] */
                const uintptr_t previousCursor = cursor; /* 0x27cac0 mov r0, r3 */
                cursor = previousCursor + step;
                if (cursor == loopEnd) {
                    break; /* 0x27cac8/0x27cacc */
                }
                storeValue = previousCursor; /* 0x27cab8 back edge mov r2, r0 */
            } while (true);
            /* 15 blocks of 0x4000: node is the last written slot. */
            node = first + 0x38000u; /* 0x27cad4 */
            next = storeValue;       /* = first + 0x34000 */
            freeCount += 15u;        /* 0x27cad0: +15, pop subtracts 1 */
        }
        uint32_t activeCount = pool->activeCount; /* 0x27c6ac */
        pool->freeHead = reinterpret_cast<uint8_t *>(next); /* 0x27c6b8 */
        pool->freeCount = freeCount - 1u;                   /* 0x27c6b4/0x27c6c0 */
        pool->activeCount = activeCount + 1u;               /* 0x27c6bc/0x27c6c4 */
        if (zero) {
            clearBucketBlock(node, 16384u); /* 0x27c6cc-0x27c6d8, result dropped */
        }
        return reinterpret_cast<void *>(node);
    } else {
        /* 0x27c68c bne 0x27c984: unreachable once the eligibility predicate
         * above has run, but kept because the original words contain it.
         * ONE snapshot of live dbg_csol (0x27c99c ldr r0,[r0]), then its
         * vptr slot +0xc variadic print (0x27c9a0-0x27c9a8) with the held
         * size twice (r2/r3, 0x27c988/0x27c990), then STR #42 into the held
         * eligibility word (0x27c9ac-0x27c9b4) and that same word returned
         * (0x27c9b0-0x27c9b8). No YYError, no abort, no fault claim. */
        VMDebugConsolePrefix *const console = dbg_csol; /* 0x27c984-0x27c99c */
        console->table->print(console, "shouldn't get here - size %d - %08x\n",
                              size, size);              /* 0x27c9a0-0x27c9a8 */
        storeWordByRawArmStr(eligibilityWord, 42u);     /* 0x27c9ac/0x27c9b4 */
        return reinterpret_cast<void *>(eligibilityWord); /* 0x27c9b0/0x27c9b8 */
    }
}
