#ifndef CALLY_MEMORY_BUCKETS_HPP
#define CALLY_MEMORY_BUCKETS_HPP
#include "cbucket_classes.hpp"
#include "memory_alloc.hpp"
#include "page_lookup.hpp"
#include "../vm_exec/vm_entry_runtime.hpp"

/* tier: bytecode_anchored. bucketAlloc 0x27c53c and startup entry
 * 0xba3e4 resolve the SAME seven .bss symbols through the SAME GOT slots.
 * gap: dynamic startup/load equivalence, page fault/unwind and concurrency. */
extern BucketStaticStorage<CBucket<8, 131072, true>> _8byte;       // 0x756728
extern BucketStaticStorage<CBucket<16, 262144, true>> _16byte;     // 0x756714
extern BucketStaticStorage<CBucket<32, 262144, true>> _32byte;     // 0x756700
extern BucketStaticStorage<CBucket<64, 524288, true>> _64byte;     // 0x7566ec
extern BucketStaticStorage<CBucket<128, 524288, true>> _128byte;   // 0x7566d8
extern BucketStaticStorage<CBucket<256, 1048576, true>> _256byte; // 0x7566c4
extern BucketStaticStorage<CBucket<16384, 262144, true>> _16Kbyte; // 0x7566b0
extern volatile uint8_t bucketsShouldInit;  // actual symbol BYTE0x75669a
extern volatile uint32_t pagedata_size;    // actual symbol WORD0x75669c
namespace bucket_state {
/* Anonymous original byte at0x756699, separate from bucketsShouldInit.
 * The descriptive name is not an original symbol. BSS zero is the ELF
 * initial state; only bucketAlloc owns the lazy transition to one.
 */
extern volatile uint8_t initialized;
}
void addPageToGlobalPageList(void *, void *); // real 0x27bcf8; end argument is passed verbatim
void *operator new(size_t);                   // real0x27c524
#endif
