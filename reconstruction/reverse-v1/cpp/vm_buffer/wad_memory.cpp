#include "vm_buffer.hpp"

/* MemoryInWad(void*), original 0x1aad50..0x1aadac (84 code bytes + 8 pool bytes).
 * tier: bytecode_anchored; original ELF SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * GOT 0x3f0810 -> g_pWADEndAddress @0x544c3c;
 * GOT 0x3ed94c -> g_pWADBaseAddress @0x544c44.
 * gap: the globals' producers/lifetime are not recovered here; this is a
 * predicate over the observed 32-bit pointer words, not a mapped-WAD loader.
 */
bool MemoryInWad(void *address)
{
    const uintptr_t pointerBits = reinterpret_cast<uintptr_t>(address);

    // 0x1aad68 then 0x1aad70: snapshot end before base, without short-circuiting
    // away either original global read. Volatile references retain that order.
    uint8_t *volatile &wadEnd = g_pWADEndAddress;
    uint8_t *volatile &wadBase = g_pWADBaseAddress;
    const uintptr_t endBits = reinterpret_cast<uintptr_t>(wadEnd);
    const uintptr_t baseBits = reinterpret_cast<uintptr_t>(wadBase);

    // 0x1aad74..0x1aad9c compares (sign-word, low-word) UNSIGNED. Sign-extending
    // uint32 pointer bits preserves their unsigned order, so these two 32-bit
    // comparisons express the same predicate. Both original endpoints are
    // INCLUSIVE: LS at 0x1aad84/88 and HS at 0x1aad98/9c. Do not change to <end.
    return pointerBits <= endBits && pointerBits >= baseBits;
}
