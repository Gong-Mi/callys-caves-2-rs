/* CBucket<ChunkBytes, AreaBytes, Mode>::Init / Check -- false-mode shard.
 * tier: bytecode_anchored; libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Covers exactly the two false instances from the intake:
 *   CBucket<16, 1048576, false>:   Init 0x190c40 (5 words), Check 0x190c54 (31 words)
 *   CBucket<32768, 1048576, false>: Init 0xd338c  (5 words), Check 0xd33a0  (31 words)
 * Free/GetSize belong to the sibling shard; this file does not define or
 * instantiate them, and it does not touch the committed true ipp
 * (cbucket_init_check.ipp), which keeps static_assert(Mode) on its side.
 *
 * Cross-instance literal comparison (anchors TSVs, words only):
 *   Init  0x190c40 vs 0xd338c: word-identical (shared body_sha256
 *           1f630b1aa5e8c2fc82df7551066e4f99cc202f1f5c4a3529b0ca5e93f3cc4b1e).
 *   Check 0x190c54 vs 0xd33a0: 31 words each, exactly ONE word differs --
 *           the .word pool at +0x78 (0x0025cf54 vs 0x0031a808). Every
 *           instruction word, including all PC-relative branch immediates,
 *           is identical because the two bodies have the same internal layout.
 *           Verified programmatically over the TSV word lists.
 *
 * Two-stage PC-relative checkCounter chain, resolved from the original words:
 *   Stage 1 (body+0x10): ldr r4,[pc,#0x60].
 *     inst1 @0x190c64: pool addr = 0x190c64+8+0x60 = 0x190ccc -> .word 0x0025cf54
 *     inst2 @0xd33b0:  pool addr = 0xd33b0 +8+0x60 = 0xd3418  -> .word 0x0031a808
 *   Stage 2 (body+0x1c): ldr r4,[pc,r4] (add-pc form, r4 is the unsigned offset).
 *     inst1 @0x190c70: GOT slot = 0x190c70+8+0x0025cf54 = 0x3EDBCC
 *     inst2 @0xd33bc:  GOT slot = 0xd33bc +8+0x0031a808 = 0x3EDBCC
 *   Relocation record (parsed statically from the original ELF): .rel.dyn holds
 *   exactly one entry with r_offset=0x3edbcc, type 23 = R_ARM_RELATIVE,
 *   sym index 0 (no symbol index -- the addend is the in-place file word).
 *   The file word at 0x3edbcc is 0x7566ac, and .dynsym names 0x7566ac
 *   "checkCounter" (size 4, shndx 19 = .bss). So at load time r4 = the
 *   runtime address of checkCounter; +0x5c/+0x64 (ldr r3,[r4] / str r3,[r4])
 *   are plain load-modify-store through that GOT-resolved pointer.
 *   CONCLUSION: both false slots resolve to GOT 0x3edbcc -- the SAME cell the
 *   seven true-mode Check bodies reach (true_mode_got_slot 0x3edbcc, intake
 *   bookkeeping_counter). All nine live Check bodies share one GOT cell and
 *   one counter. The per-instance pool word differs only because each body
 *   sits at a different pc; that is why the Check word sets differ in exactly
 *   one .word. No second GOT cell, no second provider: the source spelling is
 *   the shared "extern volatile uint32_t checkCounter;" already declared in
 *   cbucket_classes.hpp (0x7566ac, GOT 0x3edbcc, no new provider).
 *
 * Shape note vs true mode: the original caches &checkCounter in r4 once per
 * call (before the loop) and reuses it; the source expression below accesses
 * the extern variable at the same two program points (strictly after the
 * node->next link load, RMW before the loop-back test). Exact ARM addressing
 * of a rebuilt object is not claimed.
 * gap: false-mode runtime fault/ownership/concurrency and unwinding not
 * certified; the STR #42 to zero on chain exhaustion is preserved as observed
 * behaviour, no guard added.
 */
namespace {
using FalseCheckBucketWord = uint32_t __attribute__((may_alias));

__attribute__((always_inline)) inline uint32_t readFalseCheckBucketWord(uintptr_t address) {
    return *reinterpret_cast<const volatile FalseCheckBucketWord *>(address);
}

/* 0x190ca8 / 0xd33f4: the original STR r5(=42),[r6(=0)] when the page chain is
 * exhausted. Express the observed store, not undefined C++ null dereference;
 * do not insert a new return. The name is false-shard-specific so a future
 * same-TU merge with the true ipp's anonymous helpers cannot collide. */
__attribute__((always_inline)) inline void markUncheckedBucketNodeFalse() {
    asm volatile("str %[value], [%[address]]"
                 :
                 : [value] "r"(42u), [address] "r"(uintptr_t{0})
                 : "memory");
}
} // namespace

template<unsigned ChunkBytes, unsigned AreaBytes, bool Mode>
void CBucket<ChunkBytes, AreaBytes, Mode>::Init() {
    static_assert(!Mode, "only the two false-mode Init/Check pairs are recovered here");
    volatile CBucket *const self = this;
    self->pageHead = nullptr; // 0x190c44 (== 0xd3390): +4
    self->freeHead = nullptr; // +8
    self->activeCount = 0u;   // +0xc; no store to vptr (+0) or freeCount (+0x10)
}

template<unsigned ChunkBytes, unsigned AreaBytes, bool Mode>
void CBucket<ChunkBytes, AreaBytes, Mode>::Check() {
    static_assert(!Mode, "only the two false-mode Init/Check pairs are recovered here");
    const volatile CBucket *const self = this;
    uintptr_t node = reinterpret_cast<uintptr_t>(self->freeHead); // 0x190c54: single live read
    if (node == 0u) {
        return; // 0x190c60 beq -> +0x70 pop/bx lr: no page or counter reads
    }
    do {
        uintptr_t page = reinterpret_cast<uintptr_t>(self->pageHead); // 0x190c74, reloaded per node
        while (page != 0u) { // pageHead == 0 falls straight to the exhausted store @+0x54
            const uintptr_t lower = page + 8u;
            const uintptr_t upper = page + AreaBytes + 8u; // 0x190c84/0x190c8c: wrapping u32;
                                                           // AreaBytes == 1048576 in both instances
            if (node >= lower && node < upper) { // unsigned: blo @0x190c90, bhi @0x190c98
                break;
            }
            page = readFalseCheckBucketWord(page); // 0x190c9c: raw page->next, not its owner
        }
        if (page == 0u) {
            markUncheckedBucketNodeFalse(); // 0x190ca8: falls through to the ordinary tail
        }
        node = readFalseCheckBucketWord(node);      // 0x190cac: held node's next, read first
        const uint32_t before = checkCounter;      // 0x190cb0, strictly after the link load
        checkCounter = before + 1u;                // 0x190cb8/0x190cbc RMW via the GOT-resolved r4
    } while (node != 0u);                          // 0x190cb4 cmp then 0x190cc0 bne (str keeps flags)
}
