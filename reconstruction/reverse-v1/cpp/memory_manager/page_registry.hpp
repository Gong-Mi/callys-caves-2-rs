#ifndef CALLY_PAGE_REGISTRY_HPP
#define CALLY_PAGE_REGISTRY_HPP

#include "memory_buckets.hpp"

/* tier: bytecode_anchored; addPageToGlobalPageList(void *, void *)
 * 0x27bcf8..0x27be34 (316B), libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Keep the actual shared g_pages / g_bucketNumPages / pagedata_size cells
 * from page_lookup.hpp and memory_buckets.hpp. The record is only the two
 * observed u32 boundary words, not a separate container or a global definition.
 * gap: other table producers, initialization/ownership outside the bucket
 * and invalid-address faults, unwinding and concurrency are not certified.
 */
struct PageBoundaryWords {
    uint32_t begin;
    uint32_t end;
};
static_assert(sizeof(PageBoundaryWords) == 8, "original index LSL#3");
static_assert(offsetof(PageBoundaryWords, end) == 4, "original second store");

extern "C" void *realloc(void *, size_t);              // original 0xb6c28 PLT
extern "C" void *memmove(void *, const void *, size_t); // original 0xb6694 PLT

#endif
