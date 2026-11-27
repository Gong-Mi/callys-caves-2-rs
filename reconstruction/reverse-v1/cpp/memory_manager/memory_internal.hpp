#ifndef CALLY_RECOVERED_MEMORY_INTERNAL_HPP
#define CALLY_RECOVERED_MEMORY_INTERNAL_HPP

#include "../vm_buffer/vm_buffer.hpp"

/* tier: bytecode_anchored; ARM32 original SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Declaration/binding surface for MemoryManager::Free and direct callees.
 * Preserve the canonical MemoryManager declaration in vm_buffer.hpp.
 * gap: field access levels/full APIs, pthread failure/unwind semantics and
 * bad allocation-header fault domains remain unproved. No providers here.
 */
struct NativeMutexWord { uint32_t bits; };
struct NativeMutexAttributes { uint32_t bits; };
class Mutex {
public:
    int32_t Init(const char *name);                   // 0x27e038; name unused, raw init result
    uint32_t Lock();                                 // 0x27e084; normalised zero-success result
    int32_t Unlock();                                // 0x27e09c; raw pthread result
    uint32_t unknown00;                              // malloc(8); neither Init nor these methods write it
    NativeMutexWord native;                          // +4 passed to original pthread imports
};

/* Actual symbols, not copied snapshots or definitions. The canonical class
 * declaration is deliberately unchanged; these aliases bind its observed
 * static data without fabricating an instance or a second MemoryManager. */
namespace memory_state {
extern volatile uint8_t managerInitialized; // anonymous BSS 0x756698, distinct from bucket_state::initialized
extern volatile uint32_t inUse __asm__("_ZN13MemoryManager7m_InUseE");
extern volatile uint32_t total __asm__("_ZN13MemoryManager7m_TotalE");
extern volatile uint32_t standardCount __asm__("_ZN13MemoryManager15m_StandardCountE");
extern volatile uint32_t standardSize __asm__("_ZN13MemoryManager14m_StandardSizeE");
}
extern Mutex *volatile g_MemoryMutex;                 // ordinary .bss pointer via GOT, 0x756780

/* Original lazy-init call target 0x27b918..0x27b948 has no dynsym name.
 * This descriptive recovered name is not claimed as its source identifier. */
void initializeMemoryMutex();
enum ELogType : int;
void logLocation(ELogType, const void *, const void *, unsigned int); // original 0x27bcf4 is BX LR

/* The page lookup returns the offset-zero CBucketBase subobject. Its real
 * C++ GetSize / Free declarations are in cbucket_classes.hpp. */
class CBucketBase;
CBucketBase *globalPageListFindAddr(const void *); // 0x27be34, body in page_lookup.cpp
uint32_t bucketSize(const void *) __attribute__((noinline, disable_tail_calls)); // 0x27c1e4
uint32_t bucketFree(const void *) __attribute__((disable_tail_calls)); // 0x27c20c

extern "C" {
void *malloc(size_t);
void free(void *);
int32_t pthread_mutexattr_init(NativeMutexAttributes *);
int32_t pthread_mutexattr_settype(NativeMutexAttributes *, int32_t);
int32_t pthread_mutex_init(NativeMutexWord *, const NativeMutexAttributes *);
int32_t pthread_mutex_lock(NativeMutexWord *);
int32_t pthread_mutex_unlock(NativeMutexWord *);
}
#endif
