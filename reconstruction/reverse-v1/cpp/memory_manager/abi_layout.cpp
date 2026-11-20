#include "memory_internal.hpp"
static_assert(sizeof(Mutex) == 8, "observed malloc(8) prefix");
static_assert(offsetof(Mutex, native) == 4, "original pthread embedded-word offset");
static_assert(sizeof(NativeMutexWord) == 4 && sizeof(NativeMutexAttributes) == 4,
              "original ARM32 pthread ABI view");
static_assert(offsetof(BucketPrefix, vptr) == 0, "observed bucket vptr");
static_assert(offsetof(BucketVtablePrefix, freeEntry) == 12, "observed virtual Free slot");
