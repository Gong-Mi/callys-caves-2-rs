/* context_stack.cpp — whole context-stack family, three complete original
 * free functions, 74 original words total.
 * tier: bytecode_anchored. ARMv7 image SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Anchors (word counts incl. constant pools):
 *   PopContextStack    0xd3a34 size  32 _Z15PopContextStackv      8 words
 *   GetContextStackTop 0xd3a54 size  60 _Z18GetContextStackTopv  15 words
 *   PushContextStack   0xd3968 size 204 _Z16PushContextStackP12YYObjectBase 51 words
 * Bindings frozen in context_stack.hpp / vm_entry_runtime.hpp: actual
 * g_fJSGarbageCollection BYTE, WORD g_ContextStackTop / g_ContextStackMax,
 * POINTER cell g_ContextStack; real MemoryManager::ReAlloc 5-param call with
 * the true tag string @0x331038, line 74, final bool FALSE (original pushes 0).
 * gap: initial array/capacity ownership, invalid or overflow fault domains,
 * NULL ReAlloc-return handling, caller LR/unwind and concurrent mutations
 * remain unproved. The original performs no early return on a NULL result;
 * publish is unconditional and no GC re-test, no slot clearing, no array-slot
 * initialization, no default-globals init is added here.
 */
#include "context_stack.hpp"
#include "../vm_buffer/vm_buffer.hpp"

/* 0xd3a34 — no GC gate. ONE LIVE Top load; signed > 0 test (subgt/strgt pair
 * share the GT predicate); write top-1 back; never clears a slot, never
 * touches Max, never reads the stack pointer. */
void PopContextStack() {
    const uint32_t top = g_ContextStackTop;                    // d3a3c ldr r2,[r3]
    if (static_cast<int32_t>(top) > 0) {                       // d3a40 cmp r2,#0 signed
        g_ContextStackTop = top - 1u;                          // d3a44/d3a48 subgt+strgt
    }
}

/* 0xd3a54 — no GC gate. signed <= 0 -> NULL; else LIVE g_ContextStack read
 * AFTER the test (d3a68..d3a74), then the raw entry load. The original
 * sub r2, r2, #-1073741823 is u32 top + 0x3FFFFFFF, and the [r3, r2, lsl #2]
 * access applies (wrapped << 2) as a wrapping 32-bit byte offset; both wraps
 * are preserved below instead of a plain signed index. No NULL guard and no
 * bounds check exist in the original. */
YYObjectBase *GetContextStackTop() {
    const uint32_t top = g_ContextStackTop;                    // d3a5c
    if (static_cast<int32_t>(top) <= 0) {                      // d3a60/d3a64 ble
        return nullptr;                                        // d3a80 mov r0,#0
    }
    const uint32_t wrapped = top + 0x3FFFFFFFu;                // d3a6c u32 wrap
    const uintptr_t base =
        reinterpret_cast<uintptr_t>(g_ContextStack);           // d3a74 ldr r3,[r3]
    return *reinterpret_cast<YYObjectBase *volatile *>(base + (wrapped << 2)); // d3a78, wraps
}

/* 0xd3968 — GC gate: byte == 0 is a COMPLETE no-op (any nonzero byte value
 * proceeds; it is not a bool==true test). Nonzero path reads LIVE Top, then
 * LIVE Max, and grows ONLY on the WORD equality cmp r1, r2 — never >=.
 * No-growth path: read LIVE stack POINTER cell value once (d39b0..d39b8),
 * publish Top = heldTop + 1 BEFORE storing the entry (d39bc..d39c4), entry
 * index is the held old top: [array + (heldTop << 2)] with u32 wrap.
 * Growth path: original LSLS sets Z from the uint32 (heldTop << 1) result;
 * double != 0 -> Max = double, bytes = heldTop << 3 (wrap); double == 0
 * (top 0x80000000 wrapped, and top 0 with max 0) -> Max = 1, bytes = 4.
 * It is NOT if(top == 0) and does NOT grow Max by adding. Max is published
 * BEFORE ReAlloc. The LIVE stack pointer is handed to the real
 * MemoryManager::ReAlloc(oldPtr, bytes, true tag, 74, false) — no early
 * return on NULL, no forced true. After the call: LIVE Top is re-read FIRST
 * (d3a0c ldr r1,[r4], before the d3a14 publish), then g_ContextStack is
 * published = returned, then Top = this live re-read + 1 is published BEFORE
 * the entry store into returned + (liveTop << 2). No array/base re-read, no
 * second GC test. */
void PushContextStack(YYObjectBase *obj) {
    if (g_fJSGarbageCollection == 0) {                         // d3984 ldrb/cmp #0/beq
        return;                                                // d39c8 epilogue only
    }
    const uint32_t heldTop = g_ContextStackTop;                // d39a0 ldr r1,[r4]
    const uint32_t heldMax = g_ContextStackMax;                // d39a4 ldr r2,[r3]
    if (heldTop == heldMax) {                                  // d39a8 cmp; d39ac beq grow
        const uint32_t doubled = heldTop << 1;                 // d39d4 lsls (Z from u32 result)
        uint32_t bytes;
        if (doubled != 0u) {
            g_ContextStackMax = doubled;                       // d39d8 strne — before ReAlloc
            bytes = heldTop << 3;                              // d39dc lslne, u32 wrap
        } else {
            g_ContextStackMax = 1u;                            // d39e0/d39e4 moveq/streq
            bytes = 4u;                                        // d39ec moveq r1,#4
        }
        void *oldPtr = reinterpret_cast<void *>(g_ContextStack); // d39e8 + d3a04 LIVE cell
        void *returned = MemoryManager::ReAlloc(               // d3a08 bl 0x27cedc
            oldPtr, bytes,
            "jni/../jni/yoyo/../../../Platform/MemoryManager.h", // real tag @0x331038
            74, false);                                        // line 74; 5th bool 0 (d39fc)
        const uint32_t liveTop = g_ContextStackTop;            // d3a0c LIVE re-read FIRST
        g_ContextStack = reinterpret_cast<YYObjectBase **>(returned); // d3a14 publish
        g_ContextStackTop = liveTop + 1u;                      // d39bc/d39c0 publish before store
        const uintptr_t base = reinterpret_cast<uintptr_t>(returned); // d3a10 mov r2, r0
        *reinterpret_cast<YYObjectBase *volatile *>(base + (liveTop << 2)) = obj; // d39c4
    } else {
        YYObjectBase **array = g_ContextStack;                 // d39b0..d39b8 LIVE pointer once
        g_ContextStackTop = heldTop + 1u;                      // d39bc/d39c0 BEFORE entry store
        const uintptr_t base = reinterpret_cast<uintptr_t>(array);
        *reinterpret_cast<YYObjectBase *volatile *>(base + (heldTop << 2)) = obj; // d39c4 str [r2, r1, lsl #2]
    }
}
