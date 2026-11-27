/* tier: bytecode_anchored. Static recovery of the property-write eligibility
 * slice from libyoyo_armv7.so, SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 * Entries: JS_IsAccessorDescriptor@0x240828 (48B),
 * YYObjectBase::IsExtensible@0x19220c (12B), JS_CanPut@0x241cac (276B).
 * Direct consumers / providers in this slice: JS_CanPut calls the first and
 * second; it also calls recovered JS_GetOwnProperty@0x241890,
 * JS_GetProperty@0x2418dc, and YYObjectBase::InternalGetYYVar@0x196a70.
 * No RValue or complete YYObjectBase object is instantiated; local values are
 * raw 16-byte images and object fields are accessed by the observed offsets.
 *
 * Gap: original source-level return spellings and the complete YYObjectBase /
 * accessor-descriptor layouts remain unknown. Only the consumed fields,
 * predicates and branch results listed below are claimed. No target was run.
 */

#include "object_helpers.hpp"

namespace {
constexpr uint32_t kKindMask = 0x00ffffffu;
constexpr uint32_t kUndefinedKind = 5u;
constexpr uint32_t kUnresolvedKind = 0x00ffffffu;

uint32_t descriptor_kind(const ObjectValueImage &value) {
    return value.kind & kKindMask;
}
uint32_t metadata_bit_2(const ObjectValueImage &value) {
    return (value.auxiliary >> 2u) & 1u;
}
} // namespace

uint32_t JS_IsAccessorDescriptor(RValue *descriptor) {
    const uint32_t image = object_wire::address(descriptor);
    /* 0x240828 ldr r3,[r0,#0x0c]; 0x24082c bic r3,r3,#0xff000000
     * 0x240830 cmp r3,#6; the false path returns 0 at 0x240838..0x24083c. */
    if ((object_wire::read(image, 0x0cu) & kKindMask) != 6u) {
        return 0u;
    }
    /* 0x240840 ldr r3,[r0]; 0x240844 ldr r0,[r3,#0x48]. The following
     * subs/rsbs/adcs sequence returns exactly 1 iff this word equals 2. */
    const uint32_t object = object_wire::read(image, 0u);
    const uint32_t flags = object_wire::read(object, 0x48u);
    return flags == 2u ? 1u : 0u;
}

uint32_t YYObjectBase::IsExtensible() {
    /* 0x19220c ldr r0,[r0,#0x28]; 0x192210 and r0,r0,#1;
     * 0x192214 bx lr. This returns only the low bit, not the whole word. */
    return object_wire::read(object_wire::address(this), 0x28u) & 1u;
}

uint32_t JS_CanPut(YYObjectBase *object, const char *name) {
    /* 0x241cb0 allocates a 32-byte frame. The own-property result is an
     * intentionally otherwise-uninitialized stack RValue: only kind is set
     * to tag 5 before the real provider writes the descriptor. */
    ObjectValueImage own;
    own.kind = kUndefinedKind;                                      /* 0x241cc8 */
    JS_GetOwnProperty(object, reinterpret_cast<RValue *>(&own), name); /* 0x241ccc */

    /* 0x241cd0..0x241ce8: mask the high kind byte; tag 5 and the unresolved
     * 0x00ffffff sentinel both mean no own descriptor, so probe the prototype. */
    const uint32_t own_kind = descriptor_kind(own);
    if (own_kind != kUndefinedKind && own_kind != kUnresolvedKind) {
        /* 0x241cec..0x241cf8: a data descriptor returns bit 2 of its +8 word. */
        if (JS_IsAccessorDescriptor(reinterpret_cast<RValue *>(&own)) == 0u) {
            return metadata_bit_2(own);
        }

        /* Accessor descriptor: +0 is the descriptor-object pointer; its +4
         * word selects the value storage. Non-null storage is read at +0x1c
         * (add #16, then load +12 at 0x241d0c..0x241d10). If +4 is null,
         * InternalGetYYVar(1) supplies an RValue pointer and the code reads its
         * kind at +0x0c (0x241db4..0x241d10). No null guard is added. */
        const uint32_t descriptor_object = own.low;                   /* 0x241cfc */
        const uint32_t value_storage = object_wire::read(descriptor_object, 4u); /* 0x241d00 */
        uint32_t value_kind;
        if (value_storage == 0u) {                                     /* 0x241d04 */
            YYObjectBase *descriptor = reinterpret_cast<YYObjectBase *>(
                static_cast<uintptr_t>(descriptor_object));
            RValue *fallback = descriptor->InternalGetYYVar(1);       /* 0x241db4..0x241db8 */
            value_kind = object_wire::read(object_wire::address(fallback), 0x0cu);
        } else {
            value_kind = object_wire::read(value_storage, 0x1cu);
        }
        /* 0x241d14..0x241d24: exact (unmasked) tag tests; absent/unresolved
         * returns 0, any other observed kind returns 1. */
        return value_kind != kUnresolvedKind && value_kind != kUndefinedKind ? 1u : 0u;
    }

    /* 0x241d30..0x241d38: an absent own descriptor with no prototype falls
     * straight through to the object's low-bit extensibility result. */
    if (object_wire::read(object_wire::address(object), 0x18u) == 0u) {
        return object->IsExtensible();
    }

    /* 0x241d3c..0x241d54: inherited-property probe; again initialize only the
     * kind word, at stack RValue +0x1c, before the real provider writes it. */
    ObjectValueImage inherited;
    inherited.kind = kUndefinedKind;
    JS_GetProperty(object, reinterpret_cast<RValue *>(&inherited), name);

    /* 0x241d58..0x241d70: missing/unresolved inherited property => extensible. */
    const uint32_t inherited_kind = descriptor_kind(inherited);
    if (inherited_kind == kUndefinedKind || inherited_kind == kUnresolvedKind) {
        return object->IsExtensible();
    }
    /* 0x241d74..0x241d80: accessor descriptor => extensible result. */
    if (JS_IsAccessorDescriptor(reinterpret_cast<RValue *>(&inherited)) != 0u) {
        return object->IsExtensible();
    }
    /* 0x241d84..0x241d90: inherited data descriptor returns its +8 bit 2. */
    return metadata_bit_2(inherited);
}
