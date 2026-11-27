#include "vm_exec.hpp"

/* PerformReturn: original C++ free function _Z13PerformReturnPhP6VMExec at
 * 0xe42d8..0xe44d4 (121 instructions + 6 literal-pool words, 508 bytes).
 * tier: bytecode_anchored; original ARMv7 ELF SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Per-instruction ownership: ../../asm/index-PerformReturn.tsv. The earlier
 * C candidate ../../c/vm_exec_release/src/perform_return.c is a semantic
 * reference only; this TU is the readable C++ recovery target.
 * gap: the incoming stack pointer is never consumed (r0 dies at 0xe42f8);
 * VMBuffer::convertBuffer and CProfiler::Pop have separate source contracts;
 * YYObjectBase::Free, operator delete 0x27d1d0 and FREE_RValue__Pre still
 * owe internal bodies. Frame +0x34 is deliberately not read here. No equivalence between
 * this source and the original machine code is claimed by this file.
 */

/* 0xe4434..0xe443c writes through raw 32-bit words: the 16-byte RValue
 * bitmap is touched as (0,+0x00)(keep,+0x04)(0,+0x08)(5,+0x0c) without
 * ever materializing the still-incomplete RValue type. */
typedef uint32_t VMWord __attribute__((may_alias));

static_assert(sizeof(VMCallFrame) == 60, "frame+60 fast-return stride");

uint8_t *PerformReturn(uint8_t *stack, VMExec *exec)
{
    (void)stack; /* 0xe42dc keeps only r1=exec; r0 is dead for every path. */

    volatile VMExec *s = exec;

    /* 0xe42f4..0xe4310 with the 0xe449c..0xe44a8 side call: g_retCount is
     * incremented first, then Pop runs optionally; the frame pointer and
     * the depth are not touched before that pair. */
    g_retCount += 1u;
    if (g_bProfile != 0)
        g_Profiler.Pop();

    /* 0xe4314..0xe4330: frame and callerBuffer are snapshotted around the
     * depth decrement; the null-buffer exit still returns frame+60 AFTER
     * the decrement was stored (depth store at 0xe4328 precedes beq). */
    const volatile VMCallFrame *f =
        reinterpret_cast<const volatile VMCallFrame *>(s->frameBase);
    const uint32_t depth = static_cast<uint32_t>(s->frameDepth);
    uintptr_t result = reinterpret_cast<uintptr_t>(f) + 60u;
    VMBuffer *buffer = f->callerBuffer;
    s->frameDepth = static_cast<int32_t>(depth - 1u);
    if (buffer == nullptr)
        return reinterpret_cast<uint8_t *>(result);

    /* 0xe4334..0xe4358: every consumed frame field is read here, before any
     * exec field is written. callerFrameDistance < 0 selects the null
     * frameBase via movlt (0xe434c), not via a later guard. */
    const int32_t distance = f->callerFrameDistance;
    const char *callerName = f->callerName;
    const uint32_t callerState30 = f->callerState30;
    const char *callerSourceText = f->callerSourceText;
    YYObjectBase *callerSelf = f->callerSelf;
    YYObjectBase *callerOther = f->callerOther;
    const int32_t callerBytePc = f->callerBytePc;
    VMBuffer *callerDebugBuffer = f->callerDebugBuffer;

    /* 0xe435c..0xe43a4: publication order, including the conditional
     * ldrge loads of stackSpan (0xe4360) and stackAllocation (0xe4368)
     * interleaved between the volatile stores. stackSpan is the byte count
     * the caller wrote as 0x4000, not a frame-top pointer; the recovery
     * stackAllocation + (stackSpan - distance) wraps in 32 bits
     * (rsbge 0xe436c + addge 0xe4378). */
    s->name = callerName;
    uint32_t span = 0u;
    if (distance >= 0)
        span = s->stackSpan;
    s->state30 = callerState30;
    uintptr_t allocationBits = 0u;
    if (distance >= 0)
        allocationBits = reinterpret_cast<uintptr_t>(s->stackAllocation);
    s->sourceText = callerSourceText;
    const uint32_t localsMode = s->localsMode;
    uint32_t previousFrame = 0u;
    if (distance >= 0)
        previousFrame = static_cast<uint32_t>(allocationBits) +
                        (span - static_cast<uint32_t>(distance));
    const volatile VMBuffer *const callerBuffer = buffer;
    const uint8_t *callerCode = callerBuffer->code;            /* +0x10 at 0xe437c */
    const int32_t callerByteLimit = callerBuffer->bufferSize;  /* +0x04 at 0xe4380 */
    s->self = callerSelf;
    s->other = callerOther;
    s->bytePc = callerBytePc;
    s->buffer = buffer;
    s->debugBuffer = callerDebugBuffer;
    s->frameBase = reinterpret_cast<uint8_t *>(previousFrame);
    s->code = callerCode;
    s->byteLimit = callerByteLimit;

    /* 0xe43a8 branch to 0xe44ac..0xe44b8: with the just-read localsMode
     * zero, YYObjectBase::Free runs on exec->locals WITHOUT a null guard
     * (unconditional original call), then r4 reloads exec->buffer. */
    if (localsMode == 0u) {
        YYObjectBase::Free(s->locals);
        buffer = s->buffer;
    }

    /* 0xe43ac..0xe43c0: caller locals pair restores, then the held buffer
     * converts itself through the real VMBuffer::convertBuffer. */
    YYObjectBase *const callerLocals = f->callerLocals;
    const uint32_t callerLocalsMode = f->callerLocalsMode;
    s->locals = callerLocals;
    s->localsMode = callerLocalsMode;
    buffer->convertBuffer();

    /* 0xe43c4..0xe43f4: bytePc and the offset map come from live re-reads
     * of exec after the conversion (0xe43c4, 0xe43c8); handlers come from
     * the held converted buffer (0xe43d4). deleteOnReturn is fetched at
     * 0xe43e4 before the three publications. bytePc/4 is signed division
     * truncating toward zero, which the original spells as cmp/add #3/
     * movlt/asr #2 (0xe43cc..0xe43e0), so a small negative pc indexes 0. */
    const int32_t bytePc = s->bytePc;
    const volatile VMBuffer *const mapBuffer = s->buffer;
    const volatile VMBuffer *const heldBuffer = buffer;
    const volatile VMInstructionHandler *heldHandlers = heldBuffer->handlers;
    const volatile uint32_t *map = mapBuffer->offsetToSlot;
    void *toDelete = f->deleteOnReturn;
    s->handlers = heldHandlers;
    const uint32_t slot = map[bytePc / 4];
    s->offsetToSlot = map;
    s->nextSlot = slot;

    /* 0xe43f8: unconditional ::operator delete (0x27d1d0) even for null;
     * do not spell this as a `delete` expression (which elapses the null
     * check into the caller) nor route it through MemoryManager::Free. */
    ::operator delete(toDelete);

    /* 0xe43fc..0xe446c: g_ArgumentCount and Argument are read once up
     * front (0xe4410, 0xe441c). The loop guard is the sign of the WRAPPED
     * argc-1 (subs 0xe4418 + bmi 0xe4420): zero and 0x80000001..0xffffffff
     * skip, but 0x80000000 enters; do not rewrite this as signed argc > 0. The
     * traversal pointer and countdown survive the FREE_RValue__Pre
     * callback in callee-saved registers; only when the loop actually ran
     * is argc re-read live at 0xe446c (the skip path keeps 0xe4410's
     * value). Tag window: (tag-1) & 0x00FFFFFC == 0 (bic 0xe4450/0xe4454). */
    uint32_t argc = g_ArgumentCount;
    uint32_t countdown = argc - 1u;
    volatile VMWord *value = reinterpret_cast<volatile VMWord *>(Argument);
    if (static_cast<int32_t>(countdown) >= 0) {
        do {
            const uint32_t tag = value[3];
            if (((tag - 1u) & 0x00fffffcu) == 0)
                FREE_RValue__Pre(const_cast<RValue *>(
                    reinterpret_cast<volatile RValue *>(value)));
            value[2] = 0u; /* clear +0x08 first, as the original does */
            value[3] = 5u; /* then kind = 5 */
            value[0] = 0u; /* then +0x00; +0x04 is never cleared */
            value += 4;    /* 16-byte raw image per step */
        } while (countdown-- != 0u);
        argc = g_ArgumentCount;
    }

    /* 0xe4470..0xe4498: frame+60 advances by argc<<4 in 32-bit arithmetic
     * (the live re-read argc on the loop path, the up-front argc on the
     * skip path); Argument is rebuilt from the LIVE exec->stackAllocation
     * (0xe4470) plus f->callerArgumentOffset, and g_ArgumentCount is
     * published (0xe4488) before Argument (0xe448c). */
    const uintptr_t allocation =
        reinterpret_cast<uintptr_t>(s->stackAllocation);
    result += static_cast<uintptr_t>(argc << 4);
    const uint32_t argumentOffset = f->callerArgumentOffset;
    const uint32_t callerArgumentCount = f->callerArgumentCount;
    g_ArgumentCount = callerArgumentCount;
    Argument = reinterpret_cast<RValue *>(allocation + argumentOffset);
    return reinterpret_cast<uint8_t *>(result);
}
