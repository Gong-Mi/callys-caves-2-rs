#ifndef CALLY_GC_OBJECT_LIFECYCLE_HPP
#define CALLY_GC_OBJECT_LIFECYCLE_HPP
#include "gc_reset_runtime.hpp"
#include "object_internal.hpp"

/* tier: bytecode_anchored; libyoyo-armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * FreeAllObjects@0xd675c uses the existing guard byte, live g_slotObjects,
 * g_ShouldDispose and length_slot declarations. RemoveGCRoot@0xd5b60 uses
 * the same four g_GCGens instances as ResetGC; no new backing array.
 * The next four names denote observed raw ARM32 stores only; their source
 * pointee types and production paths are not recovered by these windows. */
namespace gc_object_state {
extern volatile uint32_t globalWord __asm__("g_pGlobal");
extern volatile uint32_t objectPrototypeWord __asm__("g_YYJSStandardBuiltInObjectPrototype");
extern volatile uint32_t functionPrototypeWord __asm__("JS_Standard_Builtin_Function_Prototype");
extern volatile uint32_t scopeHeadWord __asm__("g_pScopeHead");
}
void FreeAllObjects();                         // 0xd675c
void RemoveGCRoot(YYObjectBase *);              // 0xd5b60
#endif
