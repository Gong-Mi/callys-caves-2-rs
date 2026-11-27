#include "script_runtime.hpp"
static_assert(sizeof(void *) == 4, "pinned ARM32 call ABI");
static_assert(offsetof(CScript, code) == 8, "GetCode reads +8");
static_assert(sizeof(ObjectValueImage) == 16, "raw argument image");
static_assert(offsetof(ScriptCallScratch, reused1c) == 4, "shared count/zero word");
static_assert(offsetof(ScriptCallScratch, arguments20) == 8, "same image passed to arguments creation");
static_assert(sizeof(ScriptCallScratch) == 24, "private observed +18..+2f image");
