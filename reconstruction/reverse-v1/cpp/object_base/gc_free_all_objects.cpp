/* gc_free_all_objects.cpp — FreeAllObjects@0xd675c..0xd6850 (244B, GLOBAL).
 * Original libyoyo-armv7.so SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Anchors (gc-object-lifecycle-anchors/free-all-objects.asm.txt + bindings.json):
 *   d6770 single ldrb of g_fJSGarbageCollection @0x47f295; d6778 0 -> return
 *   d678c strb g_ShouldDispose = 0 (one byte, 0x3f5050)
 *   d6794 held signed count (+8) of liveObjectSlots(), the same 16B g_slotObjects @0x536f0c
 *   d67a0 live cap (+4) each round; d67a8 cap<=0 -> d6798 predicate only, count NOT re-read
 *   d67b0 live slots (+0), d67b4 object, d67bc skip null, d67c4 bl YYObjectBase::Free @0x198f88
 *   d67d0 count re-read live ONLY after a full scan; d67d8 bgt -> d67a0
 *   d6800/08/10/18 clear g_pGlobal, g_YYJSStandardBuiltInObjectPrototype,
 *     JS_Standard_Builtin_Function_Prototype, g_pScopeHead in instruction order
 *   d6820 strb g_ShouldDispose = 1; d6824 length_slot = -1 (mvn #0, 0x3f7420)
 * Real caller: Quit 0x2a2804 (before ResetGC 0x2a2810 in the same Quit window).
 * This TU adds only the two .data initial objects still UND in the cumulative
 * set (g_ShouldDispose byte 01 at 0x3f5050, length_slot ffffffff at 0x3f7420);
 * the guard byte, g_slotObjects, YYObjectBase::Free and the four raw words stay
 * external references via the existing canonical declarations. No CRT init.
 * No target is executed here. */
#include "gc_object_lifecycle.hpp"          // FreeAllObjects decl, gc_object_state, object_internal, guard byte
#include "../scripting/script_runtime.hpp"  // canonical extern volatile int32_t length_slot declaration

/* bindings.json: .data 0x3f5050, 1B, image_bytes "01". */
volatile uint8_t g_ShouldDispose = 1u;
/* bindings.json: .data 0x3f7420, 4B, image_bytes "ffffffff". */
volatile int32_t length_slot = -1;

void FreeAllObjects() {
    if (g_fJSGarbageCollection == 0u) {                  // d6770 ldrb, d6774/78 cmp #0/beq
        return;
    }
    g_ShouldDispose = 0u;                                // d6780 mov r2,#0, d678c strb r2,[r8]

    volatile ObjectSlotRegistry &reg = liveObjectSlots(); // d6790 [r7, pool@0xd6838]
    int32_t count = static_cast<int32_t>(reg.count);      // d6794 held signed count (+8)
    while (count > 0) {                                   // d6798/9c ble d67dc; d67d8 bgt d67a0
        const int32_t cap = static_cast<int32_t>(reg.capacity); // d67a0 live cap (+4), fetched each round
        if (cap <= 0) {
            continue;                                     // d67a8 ble d6798: re-test held count only,
                                                          // reg.count is NOT re-read on this edge
        }
        for (uint32_t idx = 0; ; ) {                      // d67ac r4 = 0; held cap bounds idx
            YYObjectBase *obj = reg.slots[idx];           // d67b0 live slots (+0), d67b4 [r3,r4,lsl #2]
            ++idx;                                        // d67b8 add r4,#1
            if (obj != nullptr) {                         // d67bc/67c0 cmp #0, beq skip
                YYObjectBase::Free(obj);                  // d67c4 bl 0x198f88
            }
            if (idx == static_cast<uint32_t>(cap)) {      // d67c8/67cc cmp r4,r6, bne loop
                break;
            }
        }
        count = static_cast<int32_t>(reg.count);          // d67d0 live reload ONLY after full scan
    }

    gc_object_state::globalWord = 0u;              // d6800 g_pGlobal @0x544be0
    gc_object_state::objectPrototypeWord = 0u;     // d6808 g_YYJSStandardBuiltInObjectPrototype @0x756450
    gc_object_state::functionPrototypeWord = 0u;   // d6810 JS_Standard_Builtin_Function_Prototype @0x756454
    gc_object_state::scopeHeadWord = 0u;           // d6818 g_pScopeHead @0x544bdc
    g_ShouldDispose = 1u;                          // d681c/67f0+6820 mov r1,#1, strb r1,[r8]
    length_slot = -1;                              // d67e8 mvn r2,#0, d6824 str r2,[r3]
}
