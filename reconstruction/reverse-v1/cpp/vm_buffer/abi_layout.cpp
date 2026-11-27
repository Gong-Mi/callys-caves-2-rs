#include "vm_buffer.hpp"

/* Clang's offsetof extension is deliberate for these polymorphic classes.
 * This checks the ARM32 layout, not source authenticity or behavior.
 * sizeof(VMBuffer)==28 is supported by CCode's allocation at 0xcf10c.
 * VMWriteBuffer represents the observed base + cursor prefix only; the
 * constructor has no independent full-size allocation at its own entry.
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
static_assert(sizeof(VMBuffer) == 0x1c, "VMBuffer allocation in CCode");
static_assert(__builtin_offsetof(VMBuffer, bufferSize) == 0x04, "buffer size");
static_assert(__builtin_offsetof(VMBuffer, metadata08) == 0x08, "CODE metadata");
static_assert(__builtin_offsetof(VMBuffer, metadata0c) == 0x0c, "CODE metadata");
static_assert(__builtin_offsetof(VMBuffer, code) == 0x10, "bytecode pointer");
static_assert(__builtin_offsetof(VMBuffer, handlers) == 0x14, "handler table");
static_assert(__builtin_offsetof(VMBuffer, offsetToSlot) == 0x18, "slot map");
static_assert(__builtin_offsetof(VMWriteBuffer, writeCursor) == 0x1c, "derived cursor");
static_assert(sizeof(VMWriteBuffer) == 0x20, "observed derived prefix");
#pragma clang diagnostic pop
static_assert(sizeof(VMInstructionHandler) == 4, "original table slot width");
static_assert(sizeof(VMBufferCacheBucket) == 12, "original cache bucket stride");
static_assert(offsetof(VMBufferCacheBucket, handlers) == 4, "cached handler table");
static_assert(offsetof(VMBufferCacheBucket, hash) == 8, "cached hash");
static_assert(offsetof(VMBufferDispatchCache, mask) == 8, "cache mask");
static_assert(offsetof(VMBufferDispatchCache, buckets) == 16, "cache bucket array");
