/* CBucket<ChunkBytes, AreaBytes, Mode>::GetSize / Free.
 * tier: bytecode_anchored; libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Seven true GetSize entries: 0x27b8d8/898/858/818/7d8/798/758,
 * mov r0,#ChunkBytes; bx lr. Free entries at each of those addresses +8
 * all have the same 56 original bytes (SHA256
 * 61104ab3a38dc5091bac4da469aa4363c3b5501b1dd604f20ff92d619bc60b9f).
 * gap: no source-level claim of bool vs integer return spelling, or of
 * construction, invalid accesses, concurrency, and unwind equivalence.
 */
template<unsigned ChunkBytes, unsigned AreaBytes, bool Mode>
uint32_t CBucket<ChunkBytes, AreaBytes, Mode>::GetSize() {
    static_assert(Mode, "only the seven true-mode methods are recovered here");
    return ChunkBytes; // no receiver access
}

template<unsigned ChunkBytes, unsigned AreaBytes, bool Mode>
uint32_t CBucket<ChunkBytes, AreaBytes, Mode>::Free(const void *block) {
    static_assert(Mode, "only the seven true-mode methods are recovered here");
    volatile CBucket *const self = this;
    // 0x27b768, 0x27b770, 0x27b774: three independent live reads in order.
    uint8_t *const head = self->freeHead;
    const uint32_t heldFree = self->freeCount;
    const uint32_t heldActive = self->activeCount;

    using RawWord = uint32_t __attribute__((may_alias));
    const uintptr_t address = reinterpret_cast<uintptr_t>(block);
    *reinterpret_cast<volatile RawWord *>(address) = reinterpret_cast<uintptr_t>(head); // 0x27b77c

    self->freeHead = reinterpret_cast<uint8_t *>(address); // 0x27b784: +8
    self->freeCount = heldFree + 1u;                        // 0x27b788: +0x10
    self->activeCount = heldActive - 1u;                    // 0x27b78c: +0xc
    return 1u;
}
