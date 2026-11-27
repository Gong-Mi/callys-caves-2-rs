/* tier: bytecode_anchored. Static recovery of
 * _ZN13MemoryManager11IsAllocatedEPKv (0x27c454, 208B, dynsym GLOBAL) from
 * original image libyoyo_armv7.so (ARMv7 ELF32), SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * (census gc-finalize-anchors/mm-isallocated.asm.txt, batch12_functions).
 *
 * All edges are REAL links into the recovered set:
 *   bl 0x27e084 Mutex::Lock      -- canonical memory_internal.hpp class
 *                                   declaration, body in memory_helpers.cpp
 *   bl 0x27e09c Mutex::Unlock    -- same
 *   bl 0x27b918 initializeMemoryMutex -- anonymous_candidate (48B, no dynsym
 *                                   name), canonical declaration
 *                                   memory_internal.hpp, body in
 *                                   memory_helpers.cpp
 *   g_MemoryMutex (0x756780)     -- canonical memory_internal.hpp declaration
 *                                   (extern Mutex *volatile)
 * The GOT pair 0x27c460 (pool 0x27c520 = 0x001753b8) / 0x27c464 (pc base
 * 0x27c46c) reaches slot 0x3f1824 -> 0x756780 g_MemoryMutex; R_ARM_RELATIVE
 * (23) verified in-image.
 *
 * Allocator header contract observed by this body (recorded, not claimed as
 * a global contract): an allocated block pointer p carries {p-12: start
 * magic 0xdeadc0de, p-8: end magic 0xbaadb00b, p-4: size word with bit31
 * set; the size word's cleared value is the allocation size, and the block
 * header itself starts at p-16-size}, with a small-allocation cap of 8192.
 * The 0x27c504..0x27c50c subs/rsbs/adcs tail is the equality idiom
 * (return hdr[2] == 0xbaadb00b ? 1 : 0).
 *
 * gap: the producers/writers of the header words and of g_MemoryMutex's
 * lazy state (initializeMemoryMutex body IS recovered; its malloc edge
 * points into the allocator, recovered) are outside this window; the
 * mutex-null lazy-init call target 0x27b918 is the recovered
 * initializeMemoryMutex; EHABI unwind records are not recovered; the mutex
 * locking semantics (which threads, which contract) are unproved; nothing
 * was executed and no equivalence claim of any kind is made.
 */

#include "memory_internal.hpp" // Mutex, g_MemoryMutex, initializeMemoryMutex (sibling)

int MemoryManager::IsAllocated(const void *ptr) {
    /* 0x27c458 subs r5,r0,#0 ; 0x27c45c beq 0x27c4a4 : NULL -> return 0 */
    if (ptr == nullptr) {
        return 0;
    }
    /* 0x27c460 ldr r4,[pc,#0xb8] (pool 0x27c520 = 0x001753b8)
     * 0x27c464 ldr r4,[pc,r4] -> g_MemoryMutex (slot 0x3f1824)
     * 0x27c468 ldr r0,[r4] : mutex handle word
     * 0x27c46c cmp r0,#0 / 0x27c470 beq 0x27c514
     * 0x27c514 bl initializeMemoryMutex ; 0x27c518 ldr r0,[r4] reload
     * 0x27c51c b 0x27c474 : fall into Lock -- lazy init, then lock */
    Mutex *mutex = g_MemoryMutex; /* 0x27c464 : the mutex object pointer */
    if (*reinterpret_cast<volatile uint32_t *>(mutex) == 0u) { /* 0x27c468/0x27c46c/0x27c470 */
        initializeMemoryMutex(); /* 0x27c514 bl : lazy init */
    }
    mutex->Lock(); /* 0x27c474 bl 0x27e084 : real edge */
    int result = 0; /* 0x27c498 mov r5,#0 : the default returned on every
                     * not-allocated branch (the r5 register in the census) */
    const volatile uint32_t *p = static_cast<const volatile uint32_t *>(ptr);
    /* 0x27c478 ldr r2,[r5,#-0xc] : block start magic
     * 0x27c47c/0x27c480 movw/movt r3, 0xdeadc0de
     * 0x27c484 cmp r2,r3 / 0x27c488 beq 0x27c4ac : START magic present ->
     *   check the END magic directly */
    if (p[-3] == 0xdeadc0deu) {
        /* 0x27c4ac ldr r2,[r5,#-0x8] : end magic
         * 0x27c4b0/0x27c4b4 movw/movt r3, 0xbaadb00b
         * 0x27c4b8 cmp r2,r3 / 0x27c4bc moveq r5,#1 / 0x27c4c0 beq 0x27c49c */
        if (p[-2] == 0xbaadb00bu) {
            result = 1;
        }
    }
    /* 0x27c48c/0x27c4c4 ldr r3,[r5,#-0x4] : size word (bit31 set when sized)
     * 0x27c490/0x27c4cc cmp r3,#0 / blt 0x27c4d0 or bge 0x27c498:
     *   non-negative -> return 0; negative -> the header walk */
    const int32_t size_field = static_cast<int32_t>(p[-1]);
    if (size_field < 0) {
        /* 0x27c4d0 bic r3,r3,#-2147483648 : clear bit31 -> allocation size
         * 0x27c4d4 cmp r3,#8192 / 0x27c4d8 bhs 0x27c498 : >= 8192 -> return 0 */
        const uint32_t alloc_size = static_cast<uint32_t>(size_field) & 0x7fffffffu;
        if (alloc_size < 8192u) {
            /* 0x27c4dc sub r5,r5,#16 (r5 = p, so r5 = p-16)
             * 0x27c4e4 rsb r3,r3,r5 : block header base = p - 16 - size
             * 0x27c4ec ldr r1,[r3,#4] vs 0xdeadc0de (re-materialised at
             *   0x27c4e0/0x27c4e8) / 0x27c4f4 bne 0x27c498 : mismatch -> 0
             * 0x27c4f8 ldr r5,[r3,#8]
             * 0x27c4fc/0x27c500 movw/movt r3, 0xbaadb00b
             * 0x27c504 subs / 0x27c508 rsbs / 0x27c50c adcs : equality idiom
             *   -> result = (hdr[2] == 0xbaadb00b) ? 1 : 0 */
            const volatile uint32_t *header = reinterpret_cast<const volatile uint32_t *>(
                reinterpret_cast<uintptr_t>(p) - 16u - alloc_size);
            if (header[1] == 0xdeadc0deu) {
                if (header[2] == 0xbaadb00bu) {
                    result = 1;
                }
            }
        }
    }
    /* 0x27c498 mov r5,#0 : (default already in place)
     * 0x27c49c ldr r0,[r4] ; 0x27c4a0 bl 0x27e09c Mutex::Unlock : real edge
     * 0x27c4a4 mov r0,r5 ; 0x27c4a8 pop {r3,r4,r5,pc} */
    mutex->Unlock(); /* 0x27c4a0 */
    return result;
}
