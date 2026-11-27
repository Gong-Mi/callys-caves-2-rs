#include "memory_internal.hpp"
#include "cbucket_classes.hpp"
static_assert(sizeof(Mutex) == 8, "observed malloc(8) prefix");
static_assert(offsetof(Mutex, native) == 4, "original pthread embedded-word offset");
static_assert(sizeof(NativeMutexWord) == 4 && sizeof(NativeMutexAttributes) == 4,
              "original ARM32 pthread ABI view");
static_assert(__is_polymorphic(CBucketBase) && sizeof(CBucketBase) == 4,
              "observed address point at the start of the bucket base subobject");
// Free slot +0xc is checked in the real compiled vtable and virtual caller.
