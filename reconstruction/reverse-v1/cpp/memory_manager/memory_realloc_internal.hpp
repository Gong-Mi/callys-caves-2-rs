#ifndef CALLY_MEMORY_REALLOC_INTERNAL_HPP
#define CALLY_MEMORY_REALLOC_INTERNAL_HPP
#include "memory_internal.hpp"
#include "../vm_exec/vm_entry_runtime.hpp" // same canonical console prefix and object_wire primitives

/* tier: bytecode_anchored, ReAlloc0x27cedc and bucketSize0x27c1e4;
 * fixed SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * bucketSize dispatches bucket.vptr+8 with ONLY the bucket receiver in r0;
 * it does not forward the original pointer as another argument.
 * gap: Alloc implementation, corrupt-header abort callback, actual buckets,
 * recursive locking/thread/fault/unwind remain unproved. No default globals.
 */
extern "C" __attribute__((noreturn)) void abort(); // imported real abort@plt
// Actual size/free slots are checked against the compiled CBucket vtable.
#endif
