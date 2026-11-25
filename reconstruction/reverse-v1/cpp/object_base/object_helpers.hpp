#ifndef CALLY_OBJECT_HELPERS_HPP
#define CALLY_OBJECT_HELPERS_HPP
#include "object_internal.hpp"

/* tier: bytecode_anchored. Same pinned ARMv7 image as object_internal.hpp.
 * These are ABI/read views, not instantiated original C++ object classes.
 * gap: page/prototype producers, getter and script-ref implementations,
 * bad/cyclic input, source API spelling, faults and unwind remain unproved.
 */
struct CScriptRef;
using OwnPropertyGetter = void (*)(YYObjectBase *, RValue *, const char *);
void JS_GetOwnProperty(YYObjectBase *, RValue *, const char *) __attribute__((noinline)); // 0x241890
uint32_t JS_IsAccessorDescriptor(RValue *) __attribute__((noinline)); // 0x240828
uint32_t JS_IsDataDescriptor(RValue *) __attribute__((noinline)); // 0x2407e8
uint32_t JS_IsGenericDescriptor(RValue *) __attribute__((noinline)); // 0x240858
uint32_t JS_CanPut(YYObjectBase *, const char *) __attribute__((noinline)); // 0x241cac
uint32_t JS_IsCallable_Object(YYObjectBase *) __attribute__((noinline)); // 0x240758, no null guard
uint32_t Call_ScriptRef(YYObjectBase *, RValue *, CScriptRef *, int, RValue *); // 0x249590
void YYError(const char *, ...);                             // original variadic C++ entry 0xd547c

namespace rvalue_state {
using RValuePagePool = CBucket<16, 1048576, false>;
extern BucketStaticStorage<RValuePagePool> pages __asm__("_rvalue"); // 0x536d88
inline __attribute__((always_inline)) volatile RValuePagePool &livePages() noexcept {
    return pages.object;
}
}
#endif
