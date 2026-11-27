#ifndef CALLY_PAGE_LOOKUP_HPP
#define CALLY_PAGE_LOOKUP_HPP
#include "memory_internal.hpp"

/* Original globalPageListFindAddr: 0x27be34..0x27bee0.
 * tier: bytecode_anchored; ARMv7 image SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Raw ARM32 boundary-address words, not a reconstructed generic container.
 * gap: list producers, full page/bucket shapes, corrupt/overflow input domains
 * and concurrency are unproved. Both are actual original pointer/count vars.
 */
extern const volatile uint32_t *volatile g_pages;     // .bss 0x7566a0: boundary-word array pointer
extern volatile uint32_t g_bucketNumPages;           // .bss 0x7566a4: loop starts with count << 1
#endif
