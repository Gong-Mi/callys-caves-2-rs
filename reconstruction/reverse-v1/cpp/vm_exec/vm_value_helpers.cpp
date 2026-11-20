/* tier: bytecode_anchored. Same pinned original as every header here:
 * libyoyo_armv7.so SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Recovered C++, not original source spelling. This TU carries the five real
 * helper bodies VM::Exec and DoCallScript call:
 *   YYFree                 0xcef90  (4B: unconditional tail b MemoryManager::Free)
 *   LOCK_RVALUE_MUTEX      0x190f2c (4B: bx lr -- a true original no-op, NOT a lock)
 *   UNLOCK_RVALUE_MUTEX    0x190f30 (4B: bx lr -- true no-op)
 *   DeterminePotentialRoot 0x191710 (4B: bx lr -- true no-op, both pointer args unread)
 *   _RefThing<char const*>::dec() 0xc09f8 (132B, WEAK DEFAULT binding)
 * gap: lock names are historical only; no mutex, thread or DMB semantics is
 * claimed. The double operator delete on the zero/zero path and the tail
 * unlock duplication are literal original control flow, kept unsimplified.
 * No original execution; equivalence beyond the static anchors is unproved.
 *
 * The three no-op bodies carry an empty volatile asm barrier so the compiler
 * cannot drop or fold same-TU calls into VM::Exec (noinline is on the first
 * declaration in vm_entry_runtime.hpp). No DMB, lock or state is invented.
 */

#include "vm_entry_runtime.hpp"

namespace {

/* ARM word transfers over aligned, differently-typed memory (may_alias),
 * volatile keeps every original load/store visible. */
typedef uint32_t HelperWord __attribute__((may_alias));

inline void storeHelperWord(volatile void *address, uint32_t word) {
    *static_cast<volatile HelperWord *>(address) = word;
}

} // namespace

/* 0xcef90: e1a/eA tail branch -- the body IS MemoryManager::Free(p). */
void YYFree(const void *pointer) {
    MemoryManager::Free(pointer); // cef90: b 0x27c2d0 <MemoryManager::Free(void const*)>
}

/* 0x190f2c: bx lr. Original performs no lock. */
void LOCK_RVALUE_MUTEX() {
    __asm__ volatile("" ::: "memory");
}

/* 0x190f30: bx lr. Original performs no unlock. */
void UNLOCK_RVALUE_MUTEX() {
    __asm__ volatile("" ::: "memory");
}

/* 0x191710: bx lr. Both YYObjectBase* parameters are not consumed. */
void DeterminePotentialRoot(YYObjectBase *candidate, YYObjectBase *owner) {
    (void)candidate;
    (void)owner;
    __asm__ volatile("" ::: "memory");
}

/* 0xc09f8 <_RefThing<char const*>::dec()>: full 132B original path.
 * WEAK DEFAULT binding and noinline come from the frozen first declaration.
 * Structure kept exactly as the ARM words, including:
 *  - first LOCK, decrement, zero-test; nonzero exits via tail UNLOCK only;
 *  - on zero: YYFree(value00), then store the just-computed zero into +0/+8;
 *  - second LOCK, second decrement; nonzero jumps past the inner block;
 *  - on second zero: YYFree re-reads +0 live, re-stores zeros, RECURSIVE
 *    bl back into this same specialization with r0 = this, then delete;
 *  - fallthrough then does UNLOCK + a SECOND operator delete + tail UNLOCK;
 *  - the plain path also delete+tail-UNLOCKs. No refcount guard is invented.
 */
template <> void _RefThing<const char *>::dec() {
    _RefThing<const char *> *const self = this; // c09fc mov r4, r0
    LOCK_RVALUE_MUTEX();                        // c0a00
    const uint32_t first = count04 - 1u;        // c0a04 ldr / c0a08 sub (volatile read)
    count04 = first;                            // c0a0c str
    if (first != 0u) {                          // c0a10 cmp / c0a14 beq->zero path
        UNLOCK_RVALUE_MUTEX();                  // c0a18 pop + c0a1c tail b UNLOCK
        return;
    }
    YYFree(value00);                            // c0a20 ldr r0,[r4] / c0a24 bl YYFree
    storeHelperWord(&value00, first);           // c0a28 str r5(==0), [r4]
    storeHelperWord(&word08, first);            // c0a2c str r5(==0), [r4,#8]
    LOCK_RVALUE_MUTEX();                        // c0a30
    const uint32_t second = count04 - 1u;       // c0a34 ldr / c0a38 sub
    count04 = second;                           // c0a3c str
    if (second == 0u) {                         // c0a40 cmp / c0a44 bne skips block
        YYFree(value00);                        // c0a48 live re-read of +0 / c0a4c bl YYFree
        storeHelperWord(&value00, second);      // c0a54 str r5(==0), [r4]
        storeHelperWord(&word08, second);       // c0a58 str r5(==0), [r4,#8]
        self->dec();                            // c0a5c bl 0xc09f8 (recursive, same weak symbol)
        operator delete(static_cast<void *>(self)); // c0a60 mov / c0a64 bl 0x27d1d0
    }
    UNLOCK_RVALUE_MUTEX();                      // c0a68 bl UNLOCK
    operator delete(static_cast<void *>(self)); // c0a6c mov / c0a70 bl 0x27d1d0 (original deletes again)
    UNLOCK_RVALUE_MUTEX();                      // c0a74 pop + c0a78 tail b UNLOCK
}
