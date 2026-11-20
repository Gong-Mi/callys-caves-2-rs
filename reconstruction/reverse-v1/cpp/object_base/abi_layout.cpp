#include "object_internal.hpp"
static_assert(sizeof(ObjectSlotRegistry) == 16, "g_slotObjects dynsym storage");
static_assert(offsetof(ObjectSlotRegistry, count) == 8, "slot count");
static_assert(offsetof(ObjectSlotRegistry, firstFree) == 12, "first free slot");
static_assert(sizeof(ObjectValueImage) == 16 && alignof(ObjectValueImage) == 8,
              "observed stack RValue image");
static_assert(offsetof(ObjectVariableMapPrefix, bucketsAddress) == 16, "map bucket pointer");
static_assert(sizeof(ObjectVariableBucket) == 12, "observed bucket stride");
static_assert(offsetof(ObjectVariableBucket, value) == 4, "bucket RValue pointer");
static_assert(offsetof(ObjectVariableBucket, stateWord) == 8, "active predicate word");
static_assert(offsetof(ObjectDeleteTablePrefix, deleteSelf) == 4, "deleting destructor slot");
