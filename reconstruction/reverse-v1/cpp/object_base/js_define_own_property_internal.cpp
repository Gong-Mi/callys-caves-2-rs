/* JS_DefineOwnProperty_Internal 0x247d44..0x248394 (404 ARM-state words).
 * Original: libyoyo_armv7.so SHA-256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Static C++ recovery only. The two inline ARM jump tables are represented
 * by their actual dispatch cases below, including the first table's distinct
 * default branch and both default fall-through paths.
 * RValue and YYObjectBase stay partial wire/API views; no class layout,
 * ownership rule, helper body, error policy, or status name is added here.
 * Unresolved direct providers are listed in the delivery report.
 */
#include "object_helpers.hpp"
#include "../scripting/context_stack.hpp"
#include "../vm_exec/vm_entry_runtime.hpp"

namespace {
constexpr uint32_t kKindMask = 0x00ffffffu;
}

uint32_t JS_DefineOwnProperty_Internal(YYObjectBase *object, const char *name,
                                       RValue *descriptor, bool statusFlag) {
    /* The original 16-byte temporary begins at sp and is not value-initialized. */
    ObjectValueImage own;
    const uint32_t objectAddress = object_wire::address(object);
    const uint32_t descriptorAddress = object_wire::address(descriptor);
    uint32_t ownAddress;
    RValue *ownDescriptor;
    uint32_t status;
    uint32_t attributeMask;
    uint32_t ownRawKind;
    uint32_t ownKind;
    uint32_t objectFlags;
    uint32_t inputKindWord;
    uint32_t inputKind;
    uint32_t switchKind;
    uint32_t ownFlags;
    uint32_t inputFlags;
    uint32_t sameValue;
    uint32_t dataMask;
    uint32_t oldRawKind;
    uint32_t oldKind;
    uint32_t releaseTest;
    uint32_t variableBase;
    uint32_t slotOffset;
    uint32_t slotAddress;
    uint32_t inputLow;
    uint32_t inputHigh;
    uint32_t payloadAddress;
    uint32_t backPointer;
    uint32_t refCount;
    int32_t slotIndex;

    /* 0x247d5c: first context push. 0x247d64-0x247d80 maps the bool argument
     * to the raw status word used only by the own-property-missing return. */
    PushContextStack(object);
    status = statusFlag ? 2u : 0u;
    attributeMask = kKindMask;

    ownAddress = object_wire::address(&own);
    ownDescriptor = reinterpret_cast<RValue *>(
        static_cast<uintptr_t>(ownAddress));
    /* 0x247d7c, d84, d88, d8c: retain the original store order. */
    object_wire::write(ownAddress, 0x08u, 0u);
    object_wire::write(ownAddress, 0x04u, 0u);
    object_wire::write(ownAddress, 0x00u, 0u);
    object_wire::write(ownAddress, 0x0cu, kKindMask);
    JS_GetOwnProperty(object, ownDescriptor, name);                  // 0x247d90

    /* These are both live reads, in this order, after JS_GetOwnProperty. */
    ownRawKind = object_wire::read(ownAddress, 0x0cu);                // 0x247d94
    objectFlags = object_wire::read(objectAddress, 0x28u);            // 0x247d98
    ownKind = ownRawKind & kKindMask;                                 // 0x247d9c
    if (ownKind == 5u || ownKind == kKindMask) {                      // d9c-da8
        if ((objectFlags & 1u) != 0u) {                               // 0x247dac
            goto allocate_named_slot;
        }
        goto return_current_status;                                  // 0x247db4
    }

    /* 0x247dc8-dc: an unresolved incoming kind returns 1 after one pop. */
    inputKindWord = object_wire::read(descriptorAddress, 0x0cu);
    inputKind = inputKindWord & kKindMask;
    if (inputKind == kKindMask) {
        goto return_success_one_pop;
    }

    /* 0x247de0-df8. The two descriptor words are re-read after SameValue. */
    sameValue = JS_SameValue(ownDescriptor, descriptor);              // 0x247de0
    ownFlags = object_wire::read(ownAddress, 0x08u);                   // 0x247de4
    attributeMask = object_wire::read(descriptorAddress, 0x08u);      // 0x247de8
    if (sameValue != 0u && ownFlags == attributeMask) {                // dec-df8
        goto return_success_one_pop;
    }

    /* 0x247dfc-e10. A conflict in these observed low flag bits returns the
     * bool-derived status directly; the original does not re-test +0x28 here. */
    if ((ownFlags & 2u) == 0u) {
        if ((attributeMask & 2u) != 0u) {
            goto return_current_status;
        }
        if ((attributeMask & 1u) != 0u &&
            ((ownFlags ^ attributeMask) & 1u) != 0u) {
            goto return_current_status;                                // 0x248058-064
        }
    }

    /* 0x247e14 onward: generic descriptor fast path, then the original
     * descriptor-predicate comparison and its asymmetric error/return paths. */
    if (JS_IsGenericDescriptor(descriptor) == 0u) {                    // 0x247e18
        /* 0x247e28/e34: both calls are retained, in their observed order. */
        const uint32_t oldIsData = JS_IsDataDescriptor(ownDescriptor);
        const uint32_t newIsData = JS_IsDataDescriptor(descriptor);
        if (oldIsData != newIsData) {                                  // 0x247e38-03c
            ownFlags = object_wire::read(ownAddress, 0x08u);           // 0x247e40
            if ((ownFlags & 2u) == 0u) {                               // 0x247e44-048
                goto return_current_status;
            }
            /* 0x247e4c-054: two sequential MVN/shift operations, not a
             * simplified descriptor-attribute formula. */
            dataMask = ~(ownFlags << 30u);
            dataMask = ~(dataMask >> 30u);
            attributeMask &= dataMask;
        } else {
            /* 0x248254-278: the repeated predicate and exact error text are
             * observable; YYError is allowed to return by this source surface. */
            if (JS_IsDataDescriptor(ownDescriptor) == 0u) {           // 0x248254
                YYError("these are both accessors i guess??");       // 0x248264-26c
                goto find_existing_slot;
            }
            /* 0x2482e4-334: the second predicate is repeated after the call. */
            if (JS_IsDataDescriptor(descriptor) == 0u) {              // 0x2482e8
                YYError("these are both accessors i guess??");       // 0x248264-26c
                goto find_existing_slot;
            }
            ownFlags = object_wire::read(ownAddress, 0x08u);           // 0x2482f4
            if ((ownFlags & 6u) != 0u) {                              // 0x2482f8-2fc
                goto find_existing_slot;
            }
            inputFlags = object_wire::read(descriptorAddress, 0x08u);  // 0x248300
            if ((inputFlags & 4u) != 0u) {                            // 0x248304-308
                goto return_current_status;
            }
            inputKindWord = object_wire::read(descriptorAddress, 0x0cu);// 0x24830c
            if ((inputKindWord & kKindMask) == kKindMask) {            // 0x248310-31c
                goto find_existing_slot;
            }
            sameValue = JS_SameValue(ownDescriptor, descriptor);      // 0x248328
            if (sameValue != 0u) {                                    // 0x24832c-330
                goto find_existing_slot;
            }
            goto return_current_status;                                // 0x248334
        }
    }

    /* 0x247e58-80: existing-name lookup. A negative result goes to Add;
     * a null dense base uses the actual InternalGetYYVar provider. */
find_existing_slot:
    slotIndex = Code_Variable_Find_Slot_From_Name(object, name);       // 0x247e60
    if (slotIndex < 0) {
        goto add_property;
    }
    variableBase = object_wire::read(objectAddress, 0x04u);            // 0x247e6c
    if (variableBase == 0u) {                                          // 0x247e70-74
        slotAddress = object_wire::address(object->InternalGetYYVar(slotIndex)); // 0x24827c
    } else {
        slotOffset = static_cast<uint32_t>(slotIndex) << 4u;           // 0x247e78
        slotAddress = variableBase + slotOffset;
    }
    PushContextStack(object);                                          // 0x247e80
    goto clean_existing_slot;

    /* 0x247f50-78: allocation lookup has its own stack-push and slot-base
     * read order. The signed negative result is not merged with the -1 lookup. */
allocate_named_slot:
    slotIndex = Code_Variable_FindAlloc_Slot_From_Name(object, name);  // 0x247f58
    if (slotIndex < 0) {
        goto return_success_one_pop;                                   // 0x247f60
    }
    PushContextStack(object);                                          // 0x247f68
    variableBase = object_wire::read(objectAddress, 0x04u);            // 0x247f6c
    if (variableBase == 0u) {                                          // 0x247f70-74
        slotAddress = object_wire::address(object->InternalGetYYVar(slotIndex)); // 0x248240
    } else {
        slotOffset = static_cast<uint32_t>(slotIndex) << 4u;           // 0x247f78
        slotAddress = variableBase + slotOffset;
    }
    goto clean_allocated_slot;

    /* 0x247e84-ec0: release the old value in an already-found property slot.
     * The raw subtract/mask test is kept verbatim in unsigned 32-bit arithmetic. */
clean_existing_slot:
    oldRawKind = object_wire::read(slotAddress, 0x0cu);                 // 0x247e84
    oldKind = oldRawKind & kKindMask;                                  // 0x247e88
    if (oldKind == 1u) {
        goto release_existing_kind_one;
    }
    if (oldKind == 2u) {                                               // 0x247e94
        releaseTest = ((oldRawKind - 1u) & kKindMask) & ~3u;            // e9c-ea4
        if (releaseTest == 0u) {
            FREE_RValue__Pre(reinterpret_cast<RValue *>(
                static_cast<uintptr_t>(slotAddress)));                 // 0x248238
            object_wire::write(slotAddress, 0x08u, 0u);                 // 0x247eb8
            object_wire::write(slotAddress, 0x0cu, 5u);                 // 0x247ebc
        }
    }
    goto write_existing_descriptor;

    /* 0x248184-2481b4 and 0x2481fc-248394. Keep all live re-reads,
     * decrement wraps, repeated frees/deletes, and unlock order. */
release_existing_kind_one:
    payloadAddress = object_wire::read(slotAddress, 0x00u);             // 0x248184
    if (payloadAddress == 0u) {
        goto existing_kind_one_cleared;
    }
    LOCK_RVALUE_MUTEX();                                                // 0x248190
    refCount = object_wire::read(payloadAddress, 0x04u) - 1u;           // 0x248194-198
    object_wire::write(payloadAddress, 0x04u, refCount);                // 0x24819c
    if (refCount != 0u) {                                               // 0x2481a0-1a4
        UNLOCK_RVALUE_MUTEX();                                          // 0x2481a8
        goto existing_kind_one_cleared;
    }

    YYFree(reinterpret_cast<const void *>(static_cast<uintptr_t>(
        object_wire::read(payloadAddress, 0x00u))));                    // 0x2481fc-200
    object_wire::write(payloadAddress, 0x00u, refCount);                // 0x248204
    object_wire::write(payloadAddress, 0x08u, refCount);                // 0x248208
    LOCK_RVALUE_MUTEX();                                                // 0x24820c
    refCount = object_wire::read(payloadAddress, 0x04u) - 1u;           // 0x248210-214
    object_wire::write(payloadAddress, 0x04u, refCount);                // 0x248218
    if (refCount != 0u) {                                               // 0x24821c-220
        UNLOCK_RVALUE_MUTEX();                                          // 0x248224
        ::operator delete(reinterpret_cast<void *>(
            static_cast<uintptr_t>(payloadAddress)));                    // 0x24822c
        UNLOCK_RVALUE_MUTEX();                                          // 0x2481a8
        goto existing_kind_one_cleared;
    }

    /* 0x2482ac-2a8: another free/clear/decrement layer follows the second
     * zero branch; it is not collapsed into _RefThing::dec(). */
    YYFree(reinterpret_cast<const void *>(static_cast<uintptr_t>(
        object_wire::read(payloadAddress, 0x00u))));                    // 0x2482ac
    object_wire::write(payloadAddress, 0x00u, refCount);                // 0x2482b4
    object_wire::write(payloadAddress, 0x08u, refCount);                // 0x2482b8
    LOCK_RVALUE_MUTEX();                                                // 0x2482bc
    refCount = object_wire::read(payloadAddress, 0x04u) - 1u;           // 0x2482c0-2c4
    object_wire::write(payloadAddress, 0x04u, refCount);                // 0x2482c8
    if (refCount != 0u) {                                               // 0x2482cc-d0
        UNLOCK_RVALUE_MUTEX();                                          // 0x2482d4
        ::operator delete(reinterpret_cast<void *>(
            static_cast<uintptr_t>(payloadAddress)));                    // 0x2482dc
        UNLOCK_RVALUE_MUTEX();                                          // 0x248224
        ::operator delete(reinterpret_cast<void *>(
            static_cast<uintptr_t>(payloadAddress)));                    // 0x24822c
        UNLOCK_RVALUE_MUTEX();                                          // 0x2481a8
        goto existing_kind_one_cleared;
    }

    /* 0x248338-380: preserve the final conditional layer and its exact
     * YYFree -> raw clears -> _RefThing::dec -> repeated delete/unlock tail. */
    YYFree(reinterpret_cast<const void *>(static_cast<uintptr_t>(
        object_wire::read(payloadAddress, 0x00u))));                    // 0x248338-33c
    object_wire::write(payloadAddress, 0x00u, refCount);                // 0x248340
    object_wire::write(payloadAddress, 0x08u, refCount);                // 0x248344
    LOCK_RVALUE_MUTEX();                                                // 0x248348
    refCount = object_wire::read(payloadAddress, 0x04u) - 1u;           // 0x24834c-350
    object_wire::write(payloadAddress, 0x04u, refCount);                // 0x248354
    if (refCount != 0u) {                                               // 0x248358-35c
        UNLOCK_RVALUE_MUTEX();                                          // 0x248380
        ::operator delete(reinterpret_cast<void *>(
            static_cast<uintptr_t>(payloadAddress)));                    // 0x248388
        UNLOCK_RVALUE_MUTEX();                                          // 0x2482d4
        ::operator delete(reinterpret_cast<void *>(
            static_cast<uintptr_t>(payloadAddress)));                    // 0x2482dc
        UNLOCK_RVALUE_MUTEX();                                          // 0x248224
        ::operator delete(reinterpret_cast<void *>(
            static_cast<uintptr_t>(payloadAddress)));                    // 0x24822c
        UNLOCK_RVALUE_MUTEX();                                          // 0x2481a8
        goto existing_kind_one_cleared;
    }
    YYFree(reinterpret_cast<const void *>(static_cast<uintptr_t>(
        object_wire::read(payloadAddress, 0x00u))));                    // 0x248360-364
    object_wire::write(payloadAddress, 0x00u, refCount);                // 0x24836c
    object_wire::write(payloadAddress, 0x08u, refCount);                // 0x248370
    reinterpret_cast<_RefThing<const char *> *>(
        static_cast<uintptr_t>(payloadAddress))->dec();                  // 0x248374
    ::operator delete(reinterpret_cast<void *>(
        static_cast<uintptr_t>(payloadAddress)));                        // 0x24837c
    UNLOCK_RVALUE_MUTEX();                                              // 0x248380
    ::operator delete(reinterpret_cast<void *>(
        static_cast<uintptr_t>(payloadAddress)));                        // 0x248388
    UNLOCK_RVALUE_MUTEX();                                              // 0x2482d4
    ::operator delete(reinterpret_cast<void *>(
        static_cast<uintptr_t>(payloadAddress)));                        // 0x2482dc
    UNLOCK_RVALUE_MUTEX();                                              // 0x248224
    ::operator delete(reinterpret_cast<void *>(
        static_cast<uintptr_t>(payloadAddress)));                        // 0x24822c
    UNLOCK_RVALUE_MUTEX();                                              // 0x2481a8
existing_kind_one_cleared:
    object_wire::write(slotAddress, 0x00u, 0u);                         // 0x2481b0
    goto write_existing_descriptor;                                     // 0x2481b4

    /* 0x247ec0-eec: write and dispatch an existing property descriptor.
     * Preserve the two kind reads around writes, including possible aliasing. */
write_existing_descriptor:
    inputKindWord = object_wire::read(descriptorAddress, 0x0cu);         // 0x247ec0
    inputFlags = object_wire::read(descriptorAddress, 0x08u);            // 0x247ec8
    object_wire::write(slotAddress, 0x00u, 0u);                         // 0x247ecc
    object_wire::write(slotAddress, 0x0cu, inputKindWord);               // 0x247ed0
    switchKind = object_wire::read(descriptorAddress, 0x0cu) & kKindMask;// 0x247ed4-dc
    object_wire::write(slotAddress, 0x08u, inputFlags);                  // 0x247ed8

    /* 0x247ee4 is the actual ADDLS instruction (PC+8=0x247eec). The
     * default B is at 0x247ee8; indices 0..14 use branch words 0x247eec-
     * 0x247f24. Index 14 branches to 0x248040; the Add prelude starts at
     * 0x247f28 and is reached from the negative name-slot lookup instead. */
    switch (switchKind) {
    case 0u:
    case 10u:
    case 13u:                                                           // 0x248074 path
        inputLow = object_wire::read(descriptorAddress, 0x00u);
        inputHigh = object_wire::read(descriptorAddress, 0x04u);
        object_wire::write(slotAddress, 0x00u, inputLow);
        object_wire::write(slotAddress, 0x04u, inputHigh);
        goto first_switch_flags_completion;
    case 1u:                                                            // 0x24810c path
        payloadAddress = object_wire::read(descriptorAddress, 0x00u);
        if (payloadAddress != 0u) {
            refCount = object_wire::read(payloadAddress, 0x04u) + 1u;
            object_wire::write(payloadAddress, 0x04u, refCount);
        }
        object_wire::write(slotAddress, 0x00u,
                           object_wire::read(descriptorAddress, 0x00u)); // 0x248044
        goto switch_two_pop_completion;                                  // 0x248028
    case 2u:                                                            // 0x248124 path
        payloadAddress = object_wire::read(descriptorAddress, 0x00u);
        object_wire::write(slotAddress, 0x00u, payloadAddress);
        if (payloadAddress != 0u) {
            backPointer = object_wire::read(payloadAddress, 0x08u);
            refCount = object_wire::read(payloadAddress, 0x00u);
            if (backPointer == 0u) {
                object_wire::write(payloadAddress, 0x08u, slotAddress);
            }
            object_wire::write(payloadAddress, 0x00u, refCount + 1u);
        }
        goto first_switch_flags_completion;                               // 0x248048
    case 3u:
    case 7u:
    case 14u:                                                           // 0x248040 path
        object_wire::write(slotAddress, 0x00u,
                           object_wire::read(descriptorAddress, 0x00u));
        goto first_switch_flags_completion;
    case 6u:                                                            // 0x2480e8 path
        object_wire::write(slotAddress, 0x00u,
                           object_wire::read(descriptorAddress, 0x00u)); // 0x2480ec
        payloadAddress = object_wire::read(descriptorAddress, 0x00u);    // 0x2480f0
        if (payloadAddress != 0u) {
            YYObjectBase *const contextTop = GetContextStackTop();      // 0x2480fc
            payloadAddress = object_wire::read(descriptorAddress, 0x00u);// 0x248100
            DeterminePotentialRoot(
                contextTop, reinterpret_cast<YYObjectBase *>(
                    static_cast<uintptr_t>(payloadAddress)));            // 0x248104
        }
        goto first_switch_flags_completion;

    case 4u:
    case 5u:
    case 8u:
    case 9u:
    case 11u:
    case 12u:
    default:                                                            // default B at 0x247ee8
        goto first_switch_flags_completion;
    }

    /* 0x248048 then 0x247db8: two Pops, status 1, and the raw mask write. */
first_switch_flags_completion:
    PopContextStack();                                                  // 0x248048
    status = 1u;                                                        // 0x24804c
    object_wire::write(slotAddress, 0x08u, attributeMask);              // 0x248050
    goto return_after_outer_pop;                                        // 0x248054 -> 0x247db8

    /* 0x247f7c-0x247fb8: release old value in the allocated-name slot. */
clean_allocated_slot:
    oldRawKind = object_wire::read(slotAddress, 0x0cu);                 // 0x247f7c
    oldKind = oldRawKind & kKindMask;                                  // 0x247f80
    if (oldKind == 1u) {
        goto release_allocated_kind_one;
    }
    if (oldKind == 2u) {                                               // 0x247f8c
        releaseTest = ((oldRawKind - 1u) & kKindMask) & ~3u;            // f94-fa0
        if (releaseTest == 0u) {
            FREE_RValue__Pre(reinterpret_cast<RValue *>(
                static_cast<uintptr_t>(slotAddress)));                 // 0x2481f4
            object_wire::write(slotAddress, 0x08u, 0u);                 // 0x247fb0
            object_wire::write(slotAddress, 0x0cu, 5u);                 // 0x247fb4
        }
    }
    goto write_allocated_descriptor;

    /* 0x248150-2a8: preserve the separate allocation-path cleanup sequence. */
release_allocated_kind_one:
    payloadAddress = object_wire::read(slotAddress, 0x00u);             // 0x248150
    if (payloadAddress == 0u) {
        goto allocated_kind_one_cleared;
    }
    LOCK_RVALUE_MUTEX();                                                // 0x24815c
    refCount = object_wire::read(payloadAddress, 0x04u) - 1u;           // 0x248160-164
    object_wire::write(payloadAddress, 0x04u, refCount);                // 0x248168
    if (refCount == 0u) {                                               // 0x24816c-170
        goto allocated_kind_one_zero_count;
    }
    UNLOCK_RVALUE_MUTEX();                                              // 0x248174
    goto allocated_kind_one_cleared;                                    // 0x248178

allocated_kind_one_zero_count:
    YYFree(reinterpret_cast<const void *>(static_cast<uintptr_t>(
        object_wire::read(payloadAddress, 0x00u))));                    // 0x2481b8-1bc
    object_wire::write(payloadAddress, 0x00u, refCount);                // 0x2481c0
    object_wire::write(payloadAddress, 0x08u, refCount);                // 0x2481c4
    LOCK_RVALUE_MUTEX();                                                // 0x2481c8
    refCount = object_wire::read(payloadAddress, 0x04u) - 1u;           // 0x2481cc-d0
    object_wire::write(payloadAddress, 0x04u, refCount);                // 0x2481d4
    if (refCount == 0u) {                                               // 0x2481d8-dc
        goto allocated_kind_one_second_zero;
    }
    UNLOCK_RVALUE_MUTEX();                                              // 0x2481e0
    ::operator delete(reinterpret_cast<void *>(
        static_cast<uintptr_t>(payloadAddress)));                        // 0x2481e8
    UNLOCK_RVALUE_MUTEX();                                              // 0x248174
    goto allocated_kind_one_cleared;                                    // 0x248178

allocated_kind_one_second_zero:
    YYFree(reinterpret_cast<const void *>(static_cast<uintptr_t>(
        object_wire::read(payloadAddress, 0x00u))));                    // 0x248288-28c
    object_wire::write(payloadAddress, 0x00u, refCount);                // 0x248294
    object_wire::write(payloadAddress, 0x08u, refCount);                // 0x248298
    reinterpret_cast<_RefThing<const char *> *>(
        static_cast<uintptr_t>(payloadAddress))->dec();                  // 0x24829c
    ::operator delete(reinterpret_cast<void *>(
        static_cast<uintptr_t>(payloadAddress)));                        // 0x2482a4
    UNLOCK_RVALUE_MUTEX();                                              // 0x2481e0
    ::operator delete(reinterpret_cast<void *>(
        static_cast<uintptr_t>(payloadAddress)));                        // 0x2481e8
    UNLOCK_RVALUE_MUTEX();                                              // 0x248174

allocated_kind_one_cleared:
    object_wire::write(slotAddress, 0x00u, 0u);                         // 0x248178
    goto write_allocated_descriptor;                                    // 0x24817c

    /* 0x247fb8-248020: allocation path has its own second ARM jump table. */
write_allocated_descriptor:
    inputKindWord = object_wire::read(descriptorAddress, 0x0cu);         // 0x247fb8
    inputFlags = object_wire::read(descriptorAddress, 0x08u);            // 0x247fc0
    object_wire::write(slotAddress, 0x00u, 0u);                         // 0x247fc4
    object_wire::write(slotAddress, 0x0cu, inputKindWord);               // 0x247fc8
    switchKind = object_wire::read(descriptorAddress, 0x0cu) & kKindMask;// 0x247fcc-d4
    object_wire::write(slotAddress, 0x08u, inputFlags);                  // 0x247fd0

    /* 0x247fdc ADDLS has PC+8 = 0x247fe4; 0x247fe0 is the default B and
     * the 15 branch words at 0x247fe4..0x24801c map indices 0..14. */
    switch (switchKind) {
    case 0u:
    case 10u:
    case 13u:                                                           // 0x248068
        inputLow = object_wire::read(descriptorAddress, 0x00u);
        inputHigh = object_wire::read(descriptorAddress, 0x04u);
        object_wire::write(slotAddress, 0x00u, inputLow);
        object_wire::write(slotAddress, 0x04u, inputHigh);
        goto allocated_switch_completion;
    case 1u:                                                            // 0x2480ac
        payloadAddress = object_wire::read(descriptorAddress, 0x00u);
        if (payloadAddress != 0u) {
            refCount = object_wire::read(payloadAddress, 0x04u) + 1u;
            object_wire::write(payloadAddress, 0x04u, refCount);
        }
        object_wire::write(slotAddress, 0x00u,
                           object_wire::read(descriptorAddress, 0x00u)); // 0x248024
        goto allocated_switch_completion;
    case 2u:                                                            // 0x248080
        payloadAddress = object_wire::read(descriptorAddress, 0x00u);
        object_wire::write(slotAddress, 0x00u, payloadAddress);
        if (payloadAddress != 0u) {
            backPointer = object_wire::read(payloadAddress, 0x08u);
            refCount = object_wire::read(payloadAddress, 0x00u);
            if (backPointer == 0u) {
                object_wire::write(payloadAddress, 0x08u, slotAddress);
            }
            object_wire::write(payloadAddress, 0x00u, refCount + 1u);
        }
        goto allocated_switch_completion;
    case 3u:
    case 7u:
    case 14u:                                                           // 0x248020
        object_wire::write(slotAddress, 0x00u,
                           object_wire::read(descriptorAddress, 0x00u));
        goto allocated_switch_completion;
    case 6u:                                                            // 0x2480c4
        object_wire::write(slotAddress, 0x00u,
                           object_wire::read(descriptorAddress, 0x00u)); // 0x2480c8
        payloadAddress = object_wire::read(descriptorAddress, 0x00u);    // 0x2480cc
        if (payloadAddress != 0u) {
            YYObjectBase *const contextTop = GetContextStackTop();      // 0x2480d8
            payloadAddress = object_wire::read(descriptorAddress, 0x00u);// 0x2480dc
            DeterminePotentialRoot(
                contextTop, reinterpret_cast<YYObjectBase *>(
                    static_cast<uintptr_t>(payloadAddress)));            // 0x2480e0
        }
        goto allocated_switch_completion;
    case 4u:
    case 5u:
    case 8u:
    case 9u:
    case 11u:
    case 12u:
    default:                                                            // default B at 0x247fe0
        goto allocated_switch_completion;
    }

    /* Every second-table target reaches 0x248028: two ordered Pops total. */
allocated_switch_completion:
switch_two_pop_completion:
    PopContextStack();                                                  // 0x248028
    status = 1u;                                                        // 0x24802c
return_after_outer_pop:
    PopContextStack();                                                  // 0x248030 / 0x247db8
    return status;

    /* 0x247f28-4c: Add's uint32 result is deliberately ignored; the raw
     * argument word is passed through the frozen int parameter declaration. */
add_property:
    object->Add(name, *descriptor, static_cast<int>(attributeMask));     // 0x247f28-38
    PopContextStack();                                                  // 0x247f3c
    status = 1u;                                                        // 0x247f40
    return status;                                                      // 0x247f44-4c

return_success_one_pop:
    PopContextStack();                                                  // 0x247f3c
    status = 1u;                                                        // 0x247f40
    return status;

return_current_status:
    PopContextStack();                                                  // 0x247db8
    return status;                                                      // 0x247dbc-c4
}
