/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU carries the .init_array body @0xb959c..0xb95dc (13 code words +
 * 3 literal-pool words, entry .init_array@0x3eb5ec R_ARM_RELATIVE->0xb959c,
 * direct BX LR: no push, no loop, no __aeabi_atexit).
 * Recomputed anchors (slot raw word + 8-step PC chain, re-verified here):
 *   0xb95d0 pool 0x334788 -> ldr r2,[pc,r2] @0xb95ac+8=0xb95b4 -> GOT 0x3edd3c
 *     -> R_ARM_RELATIVE slot raw 0x47a1e0 = named 20B .bss "stackPages"
 *     (dynsym 1166 OBJECT GLOBAL size 20 shndx 19 .bss).
 *   0xb95d4 pool 0x3c0c04 -> add r3,pc,r3 @0xb95b0+8=0xb95b8 -> 0x47a1bc
 *     (NOT the old seed 0x47a6bc; dynsym gap: VarNames ends 0x47a1bc, next
 *     symbol g_execCount @0x47a1d4 -> anonymous three-word header 0x47a1bc..c7).
 *   0xb95d8 pool 0x3347b8 -> ldr r1,[pc,r1] @0xb95b4+8=0xb95bc -> GOT 0x3edd74
 *     -> slot raw 0x3eb908 = WEAK _ZTV7CBucketILj32768ELj1048576ELb0EE
 *     (24B .data.rel.ro), add r1,#8 -> address point 0x3eb910 (Init/+0 slot,
 *     Check/+4, GetSize/+8, Free/+12 read as 0xd338c/d33a0/d341c/d3314).
 * Complete original write order is exactly four stores:
 *   0xb95bc str r3,[r3]     header+0 = self
 *   0xb95c0 str r1,[r2]     stackPages+0 = vptr (table base +8)
 *   0xb95c4 str r3,[r3,#4]  header+4 = self
 *   0xb95c8 str r0,[r3,#8]  header+8 = 420 (0x1a4, 0xb95a0 mov r0,#420)
 * The header is anonymous: link00/link04/word08 are conservative field names,
 * no semantics invented for them. The VM consumer reads +0 "next" of its
 * allocated stack pages, not a proven read of this separate static header.
 * The allocator +0x04 owner interpretation is not asserted for VM pages.
 * No bucket Init call, no four payload-word writes, no destructor
 * registration (__aeabi_atexit absent, unlike the 0xba3e4 map initializer).
 * The lazy guard 0x47a1d0 gets its real BSS definition here (the header-only
 * declaration lives in vm_entry_runtime.hpp), but this initializer never
 * writes it: the original window contains no strb.
 * gap: eventual link/load order against other image init entries, the
 * header's original source spelling, and who else ever reads header+8=420
 * are not certified here; O0 may materialise the vptr through compiler
 * intermediate bases while O2 must keep the original four-store column.
 */

#include "vm_exec.hpp"                              // VMStackPages binding, extern stackPages
#include "vm_entry_runtime.hpp"                     // 0x47a1d0 guard declaration
#include "../memory_manager/memory_static_init.hpp" // shared placement helper

namespace {

/* Anonymous three-word header at original 0x47a1bc. Volatile accesses keep
 * each store observable; barrier-pinned vptr store stays between them. */
struct VmStackHeaderWords {
    volatile uint32_t link00;
    volatile uint32_t link04;
    volatile uint32_t word08;
};
static_assert(sizeof(VmStackHeaderWords) == 12 && offsetof(VmStackHeaderWords, link04) == 4 &&
              offsetof(VmStackHeaderWords, word08) == 8, "three original header words");
VmStackHeaderWords vmStackHeader;

constexpr uint32_t kHeaderWord08 = 420u; /* 0xb95a0 mov r0, #420 @ 0x1a4 */

/* Compiler barrier: pins the single vptr store between the header field
 * stores without inventing hardware side effects. */
inline void startupBarrier() { asm volatile("" ::: "memory"); }

__attribute__((constructor)) void vmStackImageStartup() {
    /* 0xb95bc str r3,[r3]: header+0 = self. */
    uint32_t const self =
        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(&vmStackHeader));
    vmStackHeader.link00 = self;

    startupBarrier();
    /* 0xb95c0 str r1,[r2]: stackPages+0 = _ZTV...+8. Plain default placement
     * activates the real typed object over its 20B BSS storage; the implicit
     * constructor writes exactly the +0 vptr and no payload field, so
     * +4/+8/+c/+10 stay exactly as BSS left them. No Init, no atexit. */
    ::new (memory_startup::Placement{&stackPages.object}) VMStackPages;
    startupBarrier();

    /* 0xb95c4 str r3,[r3,#4]: header+4 = self. */
    vmStackHeader.link04 = self;
    /* 0xb95c8 str r0,[r3,#8]: header+8 = 420. */
    vmStackHeader.word08 = kHeaderWord08;
}

} // namespace

/* Real typed BSS: the named 20-byte .bss object (original 0x47a1e0). The
 * constexpr union ctor zeroes bytes only, so this lands NOBITS, and the
 * declaration above is the one shared with the vm_exec consumers. */
BucketStaticStorage<VMStackPages> stackPages;

/* Original lazy guard 0x47a1d0: real BSS definition (1 byte), written by no
 * initializer in this window; VM::Exec's own path owns it. */
namespace vm_entry_state {
volatile uint8_t stackPoolInitialized;
} // namespace vm_entry_state
