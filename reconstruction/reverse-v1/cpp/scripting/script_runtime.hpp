#ifndef CALLY_SCRIPT_RUNTIME_HPP
#define CALLY_SCRIPT_RUNTIME_HPP
#include "../object_base/object_helpers.hpp"
#include "../ccode/ccode.hpp"

/* tier: bytecode_anchored, original ARMv7 SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Scope: Call_ScriptRef (0x249590), CScript::GetCode (0x1dfba8),
 * YYAllocLocalStackNew (0xd41e4). No target is executed.
 * This CScript layout is an OBSERVED 12B read prefix, not full original class
 * extent/inheritance/ownership proof. Never instantiate or delete it here.
 * gap: VM::Exec, object allocation/variable getters, arguments-object creation,
 * context-stack producers, script-ref construction and unwind/fault domains.
 */
class CScript {
public:
    CCode *GetCode() __attribute__((noinline)); // 0x1dfba8, sole read +8
    uint32_t unknown00[2];
    CCode *code;                               // observed +8 only
};
using NativeScriptCallback = void (*)(RValue *, YYObjectBase *, YYObjectBase *, int, RValue *);

YYObjectBase *YYAllocLocalStackNew(int) __attribute__((noinline)); // 0xd41e4, keep original helper frame
int Code_Variable_Find_Slot_From_Name(YYObjectBase *, const char *); // 0xd21ec
int Code_Variable_FindAlloc_Slot_From_Name(YYObjectBase *, const char *); // 0xd2c84, signed slot index
void PushContextStack(YYObjectBase *);   // 0xd3968, result not consumed here
void PopContextStack();                // 0xd3a34, result not consumed here
void CreateArgumentsObject(RValue &, YYObjectBase *, int, RValue *, bool); // 0x248b58
extern volatile int32_t g_nLocalVariables;
extern volatile int32_t length_slot;

/* Original sp+0x18..0x2f. +0x1c is reused: padded count temporarily,
 * then ZEROED at 0x249640 on BOTH paths before it is used as the fifth
 * CreateArgumentsObject argument. There is no reachable count->bool
 * noncanonical-byte transfer: padding branches to 0x249634, not 0x249644.
 * Only arguments.low is initially zeroed; the other image words remain raw.
 */
struct alignas(8) ScriptCallScratch {
    uint32_t untouched18;
    volatile uint32_t reused1c;
    ObjectValueImage arguments20;
};
static_assert(offsetof(CScript, code) == 8, "GetCode read prefix");
static_assert(offsetof(ScriptCallScratch, reused1c) == 4, "original shared +1c word");
static_assert(offsetof(ScriptCallScratch, arguments20) == 8, "original shared RValue image");
static_assert(sizeof(ScriptCallScratch) == 24, "observed +18..+2f private bytes only");

namespace script_wire {
/* Keep VCMPE and VCVT as actual VFP operations, not C casts. FPSCR effects
 * and invalid conversions remain those of the target opcodes; matching all
 * external trap/unwind behavior is still unproved. These are supporting
 * primitives, not newly recovered original entry points.
 */
inline uint32_t expectedGreater(uint32_t low, uint32_t high, int32_t argc) {
    uint32_t result;
    __asm__ volatile(
        "vmov s12, %3\n\t"
        "vcvt.f64.s32 d7, s12\n\t"
        "vmov d6, %1, %2\n\t"
        "vcmpe.f64 d6, d7\n\t"
        "vmrs APSR_nzcv, fpscr\n\t"
        "mov %0, #0\n\t"
        "movgt %0, #1"
        : "=&r"(result) : "r"(low), "r"(high), "r"(argc)
        : "d6", "d7", "cc", "memory");
    return result;
}
inline int32_t truncateExpected(uint32_t low, uint32_t high) {
    int32_t result;
    __asm__ volatile(
        "vmov d6, %1, %2\n\t"
        "vcvt.s32.f64 s13, d6\n\t"
        "vmov %0, s13"
        : "=r"(result) : "r"(low), "r"(high) : "d6", "memory");
    return result;
}
}
#endif
