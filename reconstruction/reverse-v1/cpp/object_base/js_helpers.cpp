#include "object_helpers.hpp"

/* Recovered read-side JS property / callable / call-trampoline helpers, one
 * pinned ARMv7 image (SHA-256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a):
 *   JS_GetOwnProperty   0x241890,  76B  _Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc
 *   JS_GetProperty      0x2418dc,  72B  _Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc
 *   JS_IsCallable_Object 0x240758, 20B  _Z20JS_IsCallable_ObjectP12YYObjectBase
 *   JS_IsCallable(RValue&) 0x24076c, 124B _Z13JS_IsCallableR6RValue
 *   Call_RValue         0x249860,  56B  _Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_
 * tier: bytecode_anchored. These bodies mirror the recovered register dataflow,
 * not claimed source spelling or behavioural equivalence. gap: the callees
 * reached through raw pointers (OwnPropertyGetter targets, Call_ScriptRef's
 * 720B body, getter bodies) are real declarations still owed upstream, not
 * stubbed here; bad/cyclic inputs, faults and unwind domains stay unproved.
 * RValue/YYObjectBase remain incomplete nominal types; nothing is instantiated
 * and every raw read/write goes through object_wire (uint32 base = ARM32
 * wrapping, may_alias volatile words).
 */
namespace {
constexpr uint32_t kKindMask = 0x00ffffffu;      // bic rX, rX, #-16777216
constexpr uint32_t kNoPropertyKind = 0x00ffffffu; // mvn rX, #-16777216
constexpr uint32_t kObjectKind = 6u;              // low word carries a live pointer
constexpr uint32_t kCallableTypeTag = 3u;         // object+0x48 == 3 means callable
} // namespace

void JS_GetOwnProperty(YYObjectBase *object, RValue *out, const char *name) {
    const uint32_t objectAddress = object_wire::address(object);
    /* First read is the original object+0x4c getter pointer; as in the
     * original there is no null guard on `object` itself. */
    uint32_t getterAddress = object_wire::read(objectAddress, 0x4c);
    if (getterAddress == 0u) {
        /* Walk ancestors with a temporary cursor through +0x18; the original
         * r0 is never overwritten, so a getter found in an ancestor is still
         * invoked with the ORIGINAL object, same out and same name. */
        uint32_t cursor = object_wire::read(objectAddress, 0x18);
        while (cursor != 0u) {
            getterAddress = object_wire::read(cursor, 0x4c);
            if (getterAddress != 0u) {
                break;
            }
            cursor = object_wire::read(cursor, 0x18);
        }
        if (getterAddress == 0u) {
            /* Chain exhausted: only out+0x0c = 0x00ffffff is written; the
             * other words of the out image are left alone (single str). */
            object_wire::write(object_wire::address(out), 0x0c, kNoPropertyKind);
            return;
        }
    }
    reinterpret_cast<OwnPropertyGetter>(static_cast<uintptr_t>(getterAddress))(
        object, out, name);
}

void JS_GetProperty(YYObjectBase *object, RValue *out, const char *name) {
    const uint32_t outAddress = object_wire::address(out);
    uint32_t currentAddress = object_wire::address(object);
    /* Repeat the search each round; the two functions are deliberately not
     * merged under an "already know the getter" assumption. */
    for (;;) {
        JS_GetOwnProperty(
            reinterpret_cast<YYObjectBase *>(static_cast<uintptr_t>(currentAddress)),
            out, name);
        const uint32_t kind = object_wire::read(outAddress, 0x0c) & kKindMask;
        if (kind != kNoPropertyKind) {
            return; /* anything a getter produced (or rewrote) is final */
        }
        /* Prototype is read LIVE from the current object+0x18 after the call:
         * an invoked getter may have altered the chain under us. */
        currentAddress = object_wire::read(currentAddress, 0x18);
        if (currentAddress == 0u) {
            object_wire::write(outAddress, 0x0c, kNoPropertyKind); /* full word */
            return;
        }
    }
}

uint32_t JS_IsCallable_Object(YYObjectBase *object) {
    /* No null guard; subs/rsbs/adcs at 0x24075c..0x240764 is exactly the
     * unsigned test (word == 3) returning 1/0 in r0. */
    return object_wire::read(object_wire::address(object), 0x48) == kCallableTypeTag
               ? 1u
               : 0u;
}

uint32_t JS_IsCallable(RValue &value) {
    const uint32_t valueAddress = object_wire::address(&value);
    const uint32_t kind = object_wire::read(valueAddress, 0x0c) & kKindMask;
    switch (kind) {
    case 0u:
    case 1u:
    case 5u:
    case 7u:
    case 10u:
    case 12u:
    case 13u:
    case kNoPropertyKind:
        return 0u;
    case kObjectKind:
        /* Tail branch 0x240790: [this+0x00] becomes the YYObjectBase*. */
        return JS_IsCallable_Object(reinterpret_cast<YYObjectBase *>(
            static_cast<uintptr_t>(object_wire::read(valueAddress, 0x00))));
    default:
        /* r1 carried the masked kind from 0x240774 to the bl at 0x2407ac —
         * it is the real %d argument (no nearby MOV does not mean no
         * argument); string 0x355538 = "unhandled type for JS_IsCallable %d". */
        YYError("unhandled type for JS_IsCallable %d", static_cast<int>(kind));
        return 0u;
    }
}

uint32_t Call_RValue(YYObjectBase *receiver, RValue *out, RValue *ref, int argc,
                     RValue *argv) {
    const uint32_t refAddress = object_wire::address(ref);
    if ((object_wire::read(refAddress, 0x0c) & kKindMask) != kObjectKind) {
        return 1u; /* explicit r0=1 rejection; the old Free caller ignoring it
                    * does not make this function void */
    }
    /* 0x249880: the ref's low word is reinterpreted as the CScriptRef*, then
     * that object's +0x48 tag must read 3. */
    CScriptRef *scriptRef = reinterpret_cast<CScriptRef *>(
        static_cast<uintptr_t>(object_wire::read(refAddress, 0x00)));
    if (object_wire::read(object_wire::address(scriptRef), 0x48) != kCallableTypeTag) {
        return 1u;
    }
    /* Tail b at 0x249894 forwards receiver/out/ref/argc in r0-r3 with argv
     * still on the incoming stack; the word returned is Call_ScriptRef's. */
    return Call_ScriptRef(receiver, out, scriptRef, argc, argv);
}
