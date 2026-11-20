#ifndef CALLY_MEMORY_BUCKETS_HPP
#define CALLY_MEMORY_BUCKETS_HPP
#include "memory_alloc.hpp"
#include "page_lookup.hpp"
#include "../vm_exec/vm_entry_runtime.hpp"

/* tier: bytecode_anchored; bucketAlloc0x27c53c..27cd54/2072B.
 * ARMv7 SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * These are observed read/write prefixes, NOT full original CBucket classes.
 * Inline20B objects are real named globals; no default instances are defined.
 * gap: complete CBucket virtual API/construction, page-list producer body,
 * anonymous-state initialization, private frame/LR/fault/unwind/concurrency.
 */
struct BucketPagePrefix { BucketPagePrefix *next; BucketPrefix *owner; };
struct BucketPoolPrefix {
    BucketPrefix base;              // +0 actual vptr prefix, never rewritten here
    BucketPagePrefix *pageHead;     // +4
    uint8_t *freeHead;              // +8
    uint32_t activeCount;           // +c
    uint32_t freeCount;             // +10, init block does NOT clear it
};
static_assert(sizeof(BucketPoolPrefix) == 20, "original inline bucket20");
static_assert(offsetof(BucketPoolPrefix, base) == 0, "real base subobject");
static_assert(offsetof(BucketPoolPrefix, freeHead) == 8, "free head+8");
static_assert(offsetof(BucketPoolPrefix, freeCount) == 16, "free count+10");
static_assert(sizeof(BucketPagePrefix) == 8, "page next/owner header8");
extern volatile BucketPoolPrefix _8byte;    // 0x756728
extern volatile BucketPoolPrefix _16byte;   // 0x756714
extern volatile BucketPoolPrefix _32byte;   // 0x756700
extern volatile BucketPoolPrefix _64byte;   // 0x7566ec
extern volatile BucketPoolPrefix _128byte;  // 0x7566d8
extern volatile BucketPoolPrefix _256byte;  // 0x7566c4
extern volatile BucketPoolPrefix _16Kbyte;  // 0x7566b0
extern volatile uint8_t bucketsShouldInit;  // actual symbol BYTE0x75669a
extern volatile uint32_t pagedata_size;    // actual symbol WORD0x75669c
namespace bucket_state {
/* Anonymous original byte at0x756699, separate from bucketsShouldInit.
 * Descriptive symbolic input, matching vm_entry_state binding policy: no
 * invented original name/default value and no hardcoded VA in the body.
 */
extern volatile uint8_t initialized;
}
void addPageToGlobalPageList(void *, void *); // real0x27bcf8; end argument is passed verbatim
void *operator new(size_t);                   // real0x27c524
#endif
