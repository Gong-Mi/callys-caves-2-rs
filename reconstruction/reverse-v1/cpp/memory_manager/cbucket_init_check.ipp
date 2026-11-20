/* CBucket<ChunkBytes, AreaBytes, Mode>::Init / Check.
 * tier: bytecode_anchored; libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Seven true Init bodies: 0x27b650/664/678/68c/6a0/6b4/6c8, five
 * words each. Seven true Check bodies: 0x27b368/3e4/460/4dc/558/5d4/6dc,
 * 31 words each, including the PIC literal. The Check variants differ
 * in the AreaBytes immediate and the literal leading to the same
 * checkCounter GOT slot 0x3edbcc (R_ARM_RELATIVE to 0x7566ac).
 * gap: false mode, runtime fault/ownership/concurrency and unwinding not certified.
 */
namespace {
using CheckBucketWord = uint32_t __attribute__((may_alias));

__attribute__((always_inline)) inline uint32_t readCheckBucketWord(uintptr_t address) {
    return *reinterpret_cast<const volatile CheckBucketWord *>(address);
}

/* 0x27b3bc family: the original STR #42 at the zero address on an
 * unmatched page. Express the observed store, not undefined C++ null
 * dereference; do not insert a new return or claim runtime fault parity. */
__attribute__((always_inline)) inline void markUncheckedBucketNode() {
    asm volatile("str %[value], [%[address]]"
                 :
                 : [value] "r"(42u), [address] "r"(uintptr_t{0})
                 : "memory");
}
} // namespace

template<unsigned ChunkBytes, unsigned AreaBytes, bool Mode>
void CBucket<ChunkBytes, AreaBytes, Mode>::Init() {
    static_assert(Mode, "only the seven true-mode methods are recovered here");
    volatile CBucket *const self = this;
    self->pageHead = nullptr; // 0x27b654 and its siblings: +4
    self->freeHead = nullptr; // +8
    self->activeCount = 0u;   // +0xc; no store to vptr/freeCount
}

template<unsigned ChunkBytes, unsigned AreaBytes, bool Mode>
void CBucket<ChunkBytes, AreaBytes, Mode>::Check() {
    static_assert(Mode, "only the seven true-mode methods are recovered here");
    const volatile CBucket *const self = this;
    uintptr_t node = reinterpret_cast<uintptr_t>(self->freeHead); // 0x27b368
    if (node == 0u) {
        return; // 0x27b374 -> 0x27b3d8: no page or counter reads
    }
    do {
        uintptr_t page = reinterpret_cast<uintptr_t>(self->pageHead); // 0x27b388, live per node
        while (page != 0u) { // 0x27b38c..390
            const uintptr_t lower = page + 8u;
            const uintptr_t upper = page + AreaBytes + 8u; // 0x27b398/0x27b3a0: wrapping u32
            if (node >= lower && node < upper) { // unsigned BLO, then BHI @ 0x27b3a4..3ac
                break;
            }
            page = readCheckBucketWord(page); // 0x27b3b0: page->next, not its owner
        }
        if (page == 0u) {
            markUncheckedBucketNode(); // 0x27b3bc: falls through to the ordinary tail
        }
        node = readCheckBucketWord(node);        // 0x27b3c0: held node's next
        const uint32_t before = checkCounter;   // 0x27b3c4, strictly after the link load
        checkCounter = before + 1u;             // 0x27b3cc..3d0
    } while (node != 0u);                       // 0x27b3c8/0x27b3d4
}
