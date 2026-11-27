/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU carries the MemoryManager lifecycle trio recovered from
 * lifecycle.asm.txt and re-verified instruction-word by instruction-word
 * against the fixed original:
 *   MemoryManager::Init        0x27c23c..0x27c288 (16 ARM words + 3 pool words)
 *   MemoryManager::Quit        0x27c288..0x27c28c (single bx lr)
 *   MemoryManager::DumpMemory  0x27c28c..0x27c2d0 (14 ARM words + 3 pool words)
 * and the .bss definitions the trio and its sibling TUs require:
 *   memory_state::managerInitialized - anonymous BSS BYTE 0x756698
 *   bucketsShouldInit               - actual dynsym BYTE  0x75669a
 *   g_MemoryMutex                   - actual dynsym WORD 0x756780
 *   m_InUse/m_Total/m_StandardCount/m_StandardSize - mangled .bss counters
 *   at 0x756754/0x756758/0x75674c/0x756748 (memory_free.cpp GOT map).
 * The Init guard byte is 0x756698 read/written through base 0x756498 +
 * #0x200; 0x756699 (bucket_state::initialized) is a DIFFERENT lazy-init
 * guard owned by bucketAlloc and is never touched here.
 * gap: dynamic startup ordering, concurrent Init reentry, the dbg_csol
 * receiver's construction/vtable identity, and pthread failure domains
 * remain unproved. No original-execution equivalence is claimed by this
 * file alone.
 */

#include "memory_buckets.hpp"   /* typed dbg_csol via vm_entry_runtime.hpp,
                                 * bucketsShouldInit, pagedata_size */
#include "memory_internal.hpp"  /* MemoryManager class via vm_buffer.hpp,
                                 * memory_state decls, g_MemoryMutex,
                                 * initializeMemoryMutex (0x27b918) */

/* --- BSS definitions carried by this TU ---------------------------------
 * Zero-initialized definitions place these objects in .bss, matching the
 * original image where all of these sit in the zeroed RW segment; none
 * had an original initializer. The four counters repeat the header asm
 * labels so the emitted names stay the exact mangled dynsym spellings. */
volatile uint8_t bucketsShouldInit;   /* actual symbol, 0x75669a */
Mutex *volatile g_MemoryMutex;        /* actual symbol, 0x756780 */

namespace memory_state {
volatile uint8_t managerInitialized;  /* anonymous 0x756698 */
volatile uint32_t inUse __asm__("_ZN13MemoryManager7m_InUseE");         /* 0x756754 */
volatile uint32_t total __asm__("_ZN13MemoryManager7m_TotalE");         /* 0x756758 */
volatile uint32_t standardCount __asm__("_ZN13MemoryManager15m_StandardCountE"); /* 0x75674c */
volatile uint32_t standardSize __asm__("_ZN13MemoryManager14m_StandardSizeE");    /* 0x756748 */
} // namespace memory_state

/* --- MemoryManager::Init 0x27c23c ---------------------------------------
 * 0x27c23c-0x27c248: ldr r2,[pc,#56] = 0x4da248; add r2,pc(0x27c250),r2
 *   -> r2 = 0x756498 (PC-relative base, no GOT); mov r1,#1.
 * 0x27c244-0x27c24c: ldr r3,[pc,#52] = 0x175604; ldr r3,[pc,r3] with
 *   pc = 0x27c254 -> GOT slot 0x3f1858, whose word is 0x75669a
 *   (bucketsShouldInit).
 * 0x27c250: ldrb r0,[r2,#0x200] -> FIRST read of the old BYTE at
 *   0x756698 (memory_state::managerInitialized).
 * 0x27c254: strb r1,[r3] -> bucketsShouldInit = 1 happens BEFORE the
 *   guard branch, i.e. on both the first-pass and the early-return path.
 * 0x27c258-0x27c25c: cmp r0,#0; bxne lr -> early return on the OLD byte
 *   snapshot, no reload.
 * 0x27c264: strb r1,[r2,#0x200] -> publish the 0x756698 guard = 1.
 * 0x27c260-0x27c270: ldr r3,[pc,#28] = 0x1755b4; ldr r3,[pc,r3] with
 *   pc = 0x27c270 -> GOT slot 0x3f1824 (word 0x756780, g_MemoryMutex);
 *   ldr r3,[r3] is the LIVE pointer read.
 * 0x27c270-0x27c274: cmp r3,#0; bxne lr -> non-null mutex returns.
 * 0x27c278: b 0x27b918 -> tail BRANCH (not a call-and-return) into the
 *   anonymous lazy initializer recovered as initializeMemoryMutex in
 *   memory_helpers.cpp; the nearest-symbol CBucket::Free+0x38 spelling
 *   that objdump prints for 0x27b918 is misleading and not a callee. */
void MemoryManager::Init() {
    const uint8_t oldManager = memory_state::managerInitialized;
    bucketsShouldInit = 1u;
    if (oldManager != 0u) {
        return;
    }
    memory_state::managerInitialized = 1u;
    if (g_MemoryMutex != nullptr) {
        return;
    }
    initializeMemoryMutex();
}

/* --- MemoryManager::Quit 0x27c288 ----------------------------------------
 * The original body is literally the single word e12fff1e bx lr: a real
 * empty method, not a placeholder to be filled later. */
void MemoryManager::Quit() {
}

/* --- MemoryManager::DumpMemory 0x27c28c ---------------------------------
 * The incoming __sFILE* (r0 at entry) is NEVER READ: r0 is redefined at
 * 0x27c29c before any use. push {r3,lr} only reserves alignment scratch.
 * 0x27c28c-0x27c29c: ldr r2,[pc,#48] = 0x171480; ldr r2,[pc,r2] with
 *   pc = 0x27c29c -> GOT slot 0x3ed71c (word 0x3eb70c = the dbg_csol
 *   pointer VARIABLE); ldr r0,[r2] -> ONE snapshot of the live dbg_csol
 *   value, which is the actual receiver. The original adds no null check
 *   on it and no alternate console provider is invented here.
 * 0x27c298-0x27c2a8: ldr r3,[pc,#40] = 0x174138; ldr r3,[pc,r3] with
 *   pc = 0x27c2a8 -> GOT slot 0x3f03e0 (word 0x756758 = m_Total);
 *   ldr r2,[r3] -> ONE raw 32-bit read of m_Total.
 * 0x27c2a4-0x27c2ac: ldr r1,[pc,#32] = 0xdaf0c; add r1,pc(0x27c2b4),r1
 *   -> format string 0x3571c0, independently recomputed from the image:
 *   "Total memory used = %d(0x%08lx) bytes\n".
 * 0x27c2b0-0x27c2bc: ldr ip,[r0] (receiver vptr); mov r3,r2 (SECOND
 *   vararg slot gets the SAME raw u32); ldr ip,[ip,#12] (vtable slot
 *   +0xc); blx ip with r0=receiver, r1=format, r2=int arm of %d,
 *   r3=unsigned long arm of %08lx. The prefix view from
 *   vm_entry_runtime.hpp (console->table->print, static_assert at +0xc)
 *   reproduces this two-stage load exactly.
 * 0x27c2c0: pop {r3,pc} return; the call result is discarded. */
void MemoryManager::DumpMemory(__sFILE *) {
    VMDebugConsolePrefix *const console = dbg_csol;
    const uint32_t raw = memory_state::total;
    const volatile VMDebugConsolePrefix *const receiver = console;
    const volatile VMDebugConsoleTablePrefix *const table = receiver->table;
    const VMTracePrint output = table->print;
    output(console, "Total memory used = %d(0x%08lx) bytes\n",
           static_cast<int>(raw), static_cast<unsigned long>(raw));
}
