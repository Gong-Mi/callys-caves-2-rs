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
uint32_t JS_IsCallable_Object(YYObjectBase *) __attribute__((noinline)); // 0x240758, no null guard
uint32_t Call_ScriptRef(YYObjectBase *, RValue *, CScriptRef *, int, RValue *); // 0x249590
void YYError(const char *, ...);                             // original variadic C++ entry 0xd547c

struct RValuePagePoolPrefix {
    uint32_t unknown00;
    VMStackPagePrefix *pageHead;
    uint8_t *freeHead;
    uint32_t count0c;
    uint32_t count10;
};
namespace rvalue_state {
extern volatile RValuePagePoolPrefix pages __asm__("_rvalue"); // actual inline 20B object at 0x536d88
}
#endif
