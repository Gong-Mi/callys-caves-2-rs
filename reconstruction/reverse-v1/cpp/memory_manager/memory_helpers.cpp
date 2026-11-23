/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU carries the direct callees of MemoryManager::Free (0x27c2d0):
 * Mutex::Init 0x27e038 (56, _ZN5Mutex4InitEPKc), Mutex::Lock 0x27e084
 * (24), Mutex::Unlock 0x27e09c (8), bucketFree 0x27c20c (48,
 * _Z10bucketFreePKv), logLocation 0x27bcf4 (4, BX LR), and the anonymous
 * lazy init 0x27b918-0x27b948 recovered as initializeMemoryMutex
 * (delimited by the direct BL at 0x27c408, its prologue and the next
 * defined symbol at 0x27b948 - NOT the misleading nearest CBucket name
 * objdump prints for 0x27b918).
 * logLocation is deliberately kept in this TU, apart from
 * MemoryManager::Free, so separate compilation without LTO retains the
 * original explicit call; this is not a whole-program guarantee. The empty
 * body restores a genuine original no-op, not a placeholder.
 * gap: page_lookup.cpp provides the real globalPageListFindAddr. pthread attr_init /
 * settype failures are ignored exactly as the original does (no
 * attr_destroy, no error guards); non-0 lock return codes other than the
 * normalisation shown are unproved domains.
 */

#include "memory_internal.hpp"
#include "cbucket_classes.hpp"

int32_t Mutex::Init(const char *) {
    /* 0x27e03c-0x27e064: attr lives in the 12-byte scratch frame; the
     * name argument is never consumed by the original. Three raw pthread
     * calls, then the mutex_init result is the return value (last r0). */
    NativeMutexAttributes attributes;
    pthread_mutexattr_init(&attributes);
    pthread_mutexattr_settype(&attributes, 1); /* 0x27e054: mov r1, #1 */
    return pthread_mutex_init(&native, &attributes);
}

uint32_t Mutex::Lock() {
    /* 0x27e090-0x27e094: rsbs r0,r0,#1; movlo r0,#0 -> 1 only for a full
     * raw result of 0, every other result maps to 0. */
    return pthread_mutex_lock(&native) == 0 ? 1u : 0u;
}

int32_t Mutex::Unlock() {
    /* 0x27e09c: tail branch, the raw pthread result passes through. */
    return pthread_mutex_unlock(&native);
}

uint32_t bucketFree(const void *p) {
    /* 0x27c214 calls the real declared globalPageListFindAddr; a null
     * lookup returns 0 (0x27c234 mov r0,r3 with r3==0). */
    CBucketBase *const bucket = globalPageListFindAddr(p);
    if (bucket == nullptr) {
        return 0u;
    }
    /* 0x27c220-0x27c22c: self = bucket (r0), p (r4->r1) through the real
     * vptr slot +0xc; its 32-bit result is the pop{r4,pc} return value. */
    return bucket->Free(p);
}

void logLocation(ELogType, const void *, const void *, unsigned int) {
    /* Original 0x27bcf4 is literally BX LR: a true no-op, all four
     * arguments unconsumed. */
}

void initializeMemoryMutex() {
    /* 0x27b918-0x27b944: malloc(8), publish g_MemoryMutex with no null
     * check, then tail-call Init("MemoryManagerMutex") (string pointer
     * 0x34c5e4 from the literal pool at 0x27b944). malloc stays malloc;
     * this is not replaced by new. */
    Mutex *const allocated = static_cast<Mutex *>(malloc(8u));
    g_MemoryMutex = allocated;
    allocated->Init("MemoryManagerMutex");
}
