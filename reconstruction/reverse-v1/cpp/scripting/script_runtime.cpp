/* Call_ScriptRef 0x249590, CScript::GetCode 0x1dfba8 and
 * YYAllocLocalStackNew 0xd41e4 recovery for the pinned ARMv7 image
 * libyoyo_armv7.so SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * tier: bytecode_anchored. No target is executed here; every address comment
 * names the original instruction site. RValue/CScriptRef stay incomplete, so
 * all their fields go through object_wire raw uint32 wrap/may_alias volatile
 * access. VM::Exec, CreateArgumentsObject, YYObjectBase::Alloc/variable
 * storage and context-stack providers remain declarations; MMAlloc/MMFree
 * and the existing profiler Pop already have real recovered bodies.
 */
#include "script_runtime.hpp"

/* 0x1dfba8: ldr r0,[r0,#8]; bx lr. Sole read of the +8 code word, no guard. */
CCode *CScript::GetCode() {
    return reinterpret_cast<CCode *>(
        object_wire::read(object_wire::address(this), 0x8u)); // 0x1dfba8
}

/* 0xd41e4: mvn r1,#-16777216 (0x00ffffff); mov r2,#0;
 * bl YYObjectBase::Alloc(unsigned,int,bool) 0x19198c. The int count is handed
 * over as raw bits. Return value is NOT guarded, then +0xc=0 and
 * +0x40 = &"Locals" (0x332800). */
YYObjectBase *YYAllocLocalStackNew(int count) {
    YYObjectBase *const local =
        YYObjectBase::Alloc(static_cast<unsigned int>(count), 0x00ffffff, false); // 0xd41f0
    const uint32_t base = object_wire::address(local);
    object_wire::write(base, 0xcu, 0u);                                    // 0xd4200 str r1,[r0,#0xc]
    object_wire::write(base, 0x40u, object_wire::address("Locals"));       // 0xd4204 str r2,[r0,#0x40]
    return local;                                                          // 0xd4208 pop {r3,pc}
}

/* 0x249590..0x24983c: full-CFG recovery of Call_ScriptRef. Return convention:
 * tail 0x2496c8 yields g_fDoExceptionUnwind ? 2 : 0 on every path (native
 * null-callback too); 0/2 are the only observed return values. */
uint32_t Call_ScriptRef(YYObjectBase *context, RValue *out, CScriptRef *ref,
                        int argc, RValue *argv) {
    const uint32_t refAddr = object_wire::address(ref); // r8 = r2 @ 0x249594

    /* 0x249598..0x2495c4: read ref+0x88 FULL tag and ref+0x64 script before
     * any dispatch. tag==6 swaps the receiver to ref+0x7c raw word (no mask).
     * sp scratch (ScriptCallScratch) stays partially initialised by design:
     * untouched18 and the image high/aux/kind words are never pre-zeroed. */
    ScriptCallScratch scratch;
    const uint32_t receiverTag = object_wire::read(refAddr, 0x88u);       // 0x249598
    CScript *const script = reinterpret_cast<CScript *>(                 // 0x2495a0, before optional +7c read
        static_cast<uintptr_t>(object_wire::read(refAddr, 0x64u)));
    YYObjectBase *receiver = context;                                    // 0x24959c mov r7,r0
    if (receiverTag == 6u) {                                             // 0x2495a8 cmp r2,#6
        receiver = reinterpret_cast<YYObjectBase *>(                     // 0x2495b8 ldreq r7,[r8,#0x7c]
            static_cast<uintptr_t>(object_wire::read(refAddr, 0x7cu)));
    }


    if (script == nullptr) {
        /* 0x24976c..0x2497a0: native branch reads ref+0x68 callback FULL word.
         * Non-null: PushContextStack(receiver), real callback
         * (out, receiver, receiver, argc, argv), PopContextStack(). Null
         * falls straight to the shared unwind tail; no guard is invented. */
        const NativeScriptCallback callback =                            // 0x24976c ldr r5,[r8,#0x68]
            reinterpret_cast<NativeScriptCallback>(
                static_cast<uintptr_t>(object_wire::read(refAddr, 0x68u)));
        if (callback != nullptr) {
            PushContextStack(receiver);                                  // 0x24977c
            callback(out, receiver, receiver, argc, argv);               // 0x249798 blx r5
            PopContextStack();                                           // 0x24979c
        }
        return g_fDoExceptionUnwind != 0u ? 2u : 0u;                     // 0x2496c8..0x2496dc
    }

    /* 0x2495c8..0x2495e4: g_nLocalVariables live read feeds the real
     * allocator; then ref+0x78 FULL tag==6 publishes ref+0x6c into local+0xc. */
    YYObjectBase *const local = YYAllocLocalStackNew(g_nLocalVariables); // 0x2495d4
    const uint32_t localAddr = object_wire::address(local);
    if (object_wire::read(refAddr, 0x78u) == 6u) {                       // 0x2495dc cmp r3,#6
        object_wire::write(localAddr, 0xcu,                              // 0x2495e4 streq r3,[r0,#0xc]
                           object_wire::read(refAddr, 0x6cu));
    }

    /* 0x2495ec..0x249600: cached slot cell == -1 triggers the real name
     * lookup and publishes it into length_slot before any use. */
    int32_t slot = length_slot;                                          // 0x2495f4: one captured volatile read
    if (slot == -1) {                                                    // 0x2495f8 cmn r0,#1
        slot = Code_Variable_Find_Slot_From_Name(                        // 0x249824
            reinterpret_cast<YYObjectBase *>(ref), "length");            // string 0x330874
        length_slot = slot;                                              // 0x24982c str r0,[r11]
    }

    /* 0x249604..0x24961c: LIVE ref+4 dense base, uint32 slot<<4 wrap; a null
     * dense word calls the real InternalGetYYVar instead. Only the raw two
     * value words are read (no tag, no ToNumber). */
    uint32_t valueAddr;
    const uint32_t dense = object_wire::read(refAddr, 0x4u);             // 0x249604 ldr r3,[r8,#4]
    if (dense != 0u) {
        valueAddr = dense + (static_cast<uint32_t>(slot) << 4u);         // 0x249610 add r0,r3,r1,lsl #4
    } else {
        valueAddr = object_wire::address(                                // 0x249838
            reinterpret_cast<YYObjectBase *>(ref)->InternalGetYYVar(slot));
    }
    const uint32_t low = object_wire::read(valueAddr, 0x0u);             // 0x249618 ldm r0,{r2,r3}
    const uint32_t high = object_wire::read(valueAddr, 0x4u);

    /* 0x249614..0x249630 / 0x2496e8..0x2496f4: original VCMPE.F64 then, only
     * when greater, VCVT.S32.F64; signed argc >= truncated still skips
     * padding entirely. r11 is the padded flag (0 @ 0x249630, 1 @ 0x249764). */
    bool padded = false;
    int effectiveArgc = argc;                                            // r6
    RValue *effectiveArgv = argv;                                        // [sp,#0x58] slot
    if (script_wire::expectedGreater(low, high, argc) != 0u) {           // 0x249624 vcmpe + bgt
        const int32_t expected = script_wire::truncateExpected(low, high); // 0x2496e8 vcvt.s32.f64
        if (argc < expected) {
            /* 0x2496f8..0x249764: publish expected into shared reused1c
             * BEFORE Alloc (vstr s13,[sp,#28]); sizes are uint32 <<4 wraps.
             * MMAlloc(..., "jni/../jni/yoyo/../../../Platform/MemoryManager.h"
             * (0x331038), 70, true); fill base comes from memcpy's RETURN,
             * not from the held Alloc pointer; the tail do/while executes at
             * least once and its pointer-equality stop uses wrapped 16B
             * addresses (never rewritten as an index<expected for-loop).
             * effective argv/argc then take the new base and the re-read
             * shared expected word, and control merges at 0x249634. */
            const uint32_t expectedBytes = static_cast<uint32_t>(expected) << 4u; // 0x2496f8
            const uint32_t oldBytes = static_cast<uint32_t>(argc) << 4u;          // 0x249700
            scratch.reused1c = static_cast<uint32_t>(expected);                   // 0x249714 vstr
            void *const block = MemoryManager::Alloc(                             // 0x249718
                expectedBytes, "jni/../jni/yoyo/../../../Platform/MemoryManager.h", 70, true);
            const uint32_t newBase = object_wire::address(                        // 0x249724 bl memcpy
                memcpy(block, argv, oldBytes));
            const uint32_t expectedWord = scratch.reused1c;                       // 0x249728 ldr r12,[sp,#0x1c]
            uint32_t cursor = newBase + oldBytes;                                 // 0x249734/0x249740
            const uint32_t stop = newBase + expectedBytes;                        // 0x249738/0x249754
            do {
                object_wire::write(cursor, 0x0u, 0u);                             // 0x249740 str low
                cursor += 16u;                                                    // 0x249744 add r6,#16
                object_wire::write(cursor, -12u & 0xffffffffu, 0u);               // 0x249748 str high
                object_wire::write(cursor, -8u & 0xffffffffu, 0u);                // 0x24974c str aux
                object_wire::write(cursor, -4u & 0xffffffffu, 5u);                // 0x249750 str kind 5
            } while (cursor != stop);                                             // 0x249754/0x249758
            effectiveArgv = reinterpret_cast<RValue *>(static_cast<uintptr_t>(newBase)); // 0x24975c
            effectiveArgc = static_cast<int32_t>(expectedWord);                   // 0x249760 mov r6,r12
            padded = true;                                                        // 0x249764 mov r11,#1
        }
    }

    /* 0x249634..0x249654: BOTH paths zero image.low then the shared reused1c
     * word before GetCode; the post-GetCode reload of reused1c is what feeds
     * the fifth CreateArgumentsObject argument, so it is always 0 (false).
     * GetCode is never merged or cached: the cleanup/callback domain may
     * rewrite script+8 between calls. */
    object_wire::write(object_wire::address(&scratch.arguments20), 0u, 0u); // 0x24963c, actual word store
    scratch.reused1c = 0u;                                              // 0x249640 str r3,[sp,#0x1c]
    CCode *const code1 = script->GetCode();                             // 0x249644
    const uint32_t sharedWord = scratch.reused1c;                       // 0x249648 ldr r3,[sp,#0x1c]
    if ((object_wire::read(object_wire::address(code1), 0x78u) & 1u) != 0u) { // 0x249650 tst #1
        CreateArgumentsObject(*reinterpret_cast<RValue *>(&scratch.arguments20), // 0x249804 add r0,sp,#32
                              reinterpret_cast<YYObjectBase *>(ref),    // 0x249800 mov r1,r8
                              effectiveArgc,                            // 0x249808 mov r2,r6
                              effectiveArgv,                            // 0x24980c ldr r3,[sp,#0x58]
                              sharedWord != 0u);                        // 0x2497fc str r3,[sp]
    }

    /* 0x249658..0x24969c: g_bProfile is read live; Push consumes the LIVE
     * script+8 CCode's +0x60 word (its own inline load, not a cached
     * GetCode). VM::Exec keeps nine parameters with the live +8 reload and
     * the image.low word re-read at setup time as its ninth argument. */
    if (g_bProfile != 0u) {                                             // 0x249660 ldrb r3,[r8]
        const uint32_t codeLive = object_wire::read(object_wire::address(script), 8u); // 0x2497e8
        g_Profiler.Push(1, static_cast<int>(                            // 0x2497f0 ldr r2,[r3,#0x60]
            object_wire::read(codeLive, 0x60u)));                       // 0x2497f4
    }
    const uint32_t imageLowWord = object_wire::read(                    // 0x249674 ldr lr,[sp,#0x20]
        object_wire::address(&scratch.arguments20), 0u);
    const uint32_t codeExecWord = object_wire::read(object_wire::address(script), 8u); // 0x24967c
    VM::Exec(reinterpret_cast<CCode *>(static_cast<uintptr_t>(codeExecWord)), // 0x24969c
             receiver, receiver, out,                                   // r1,r2 = r7; r3 = r9
             local, effectiveArgc, effectiveArgv,                       // [sp], [sp,#4], [sp,#8]
             0,                                                         // [sp,#0xc] mov r12,#0
             reinterpret_cast<YYObjectBase *>(static_cast<uintptr_t>(imageLowWord))); // [sp,#0x10]

    /* 0x2496a0..0x2496c4: reload g_bProfile for Pop (no cache), then padded
     * frees the effective argv block via MemoryManager::Free, then GetCode is
     * re-called: flag bit1 (0x2496c0 tst #2) suppresses the whole locals
     * release; otherwise a THIRD GetCode + bit0 test guards it again. */
    if (g_bProfile != 0u) {                                             // 0x2496a0 ldrb r3,[r8]
        g_Profiler.Pop();                                               // 0x2497d8
    }
    if (padded) {
        MemoryManager::Free(effectiveArgv);                             // 0x2497c8
    }
    CCode *const code2 = script->GetCode();                             // 0x2496b8
    if ((object_wire::read(object_wire::address(code2), 0x78u) & 2u) == 0u) { // 0x2496c0 tst #2
        CCode *const code3 = script->GetCode();                         // 0x2497a8
        if ((object_wire::read(object_wire::address(code3), 0x78u) & 1u) == 0u) { // 0x2497b0 tst #1
            YYObjectBase::Free(local);                                  // 0x2497bc
        }
    }

    /* 0x2496c8..0x2496e4: single shared tail, no extra error returns. */
    return g_fDoExceptionUnwind != 0u ? 2u : 0u;
}
