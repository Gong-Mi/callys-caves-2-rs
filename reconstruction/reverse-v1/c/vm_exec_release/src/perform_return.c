/* PerformReturn: original ARMv7 entry 0xe42d8, 121 instructions + 6 pool words.
 * tier: bytecode_anchored; instruction ownership: cards/PerformReturn.c.
 * gap: the boundary providers declared in vm_exec_release.h are not full
 * replacements for the original VMBuffer conversion, profiling or frees.
 */
#include "vm_exec_release.h"

#define OFFSET(T, F, N) _Static_assert(offsetof(T, F) == (N), #T "." #F)
OFFSET(VMExec, locals_mode, 0x0c);
OFFSET(VMExec, locals, 0x10);
OFFSET(VMExec, self, 0x14);
OFFSET(VMExec, other, 0x18);
OFFSET(VMExec, frame_base, 0x28);
OFFSET(VMExec, buffer, 0x2c);
OFFSET(VMExec, state_30, 0x30);
OFFSET(VMExec, state_34, 0x34);
OFFSET(VMExec, state_38, 0x38);
OFFSET(VMExec, state_3c, 0x3c);
OFFSET(VMExec, frame_top, 0x40);
OFFSET(VMBuffer, byte_limit, 0x04);
OFFSET(VMBuffer, code, 0x10);
OFFSET(VMBuffer, handlers, 0x14);
OFFSET(VMBuffer, offset_to_slot, 0x18);
OFFSET(struct VMCallFrame, caller_pc, 0x00);
OFFSET(struct VMCallFrame, caller_state_30, 0x04);
OFFSET(struct VMCallFrame, caller_argc, 0x08);
OFFSET(struct VMCallFrame, caller_frame_distance, 0x0c);
OFFSET(struct VMCallFrame, caller_self, 0x10);
OFFSET(struct VMCallFrame, caller_other, 0x14);
OFFSET(struct VMCallFrame, caller_buffer, 0x18);
OFFSET(struct VMCallFrame, caller_state_38, 0x1c);
OFFSET(struct VMCallFrame, caller_state_3c, 0x20);
OFFSET(struct VMCallFrame, caller_state_34, 0x24);
OFFSET(struct VMCallFrame, delete_on_return, 0x28);
OFFSET(struct VMCallFrame, caller_locals_mode, 0x2c);
OFFSET(struct VMCallFrame, caller_locals, 0x30);
OFFSET(struct VMCallFrame, caller_argument_offset, 0x38);
_Static_assert(sizeof(struct VMCallFrame) == 60, "return frame stride");
#undef OFFSET

typedef uint32_t VMWord __attribute__((may_alias));

uint8_t *PerformReturn(uint8_t *sp, VMExec *exec)
{
    (void)sp; /* Incoming r0 is unused in this function, including the fast exit. */
    volatile VMExec *s = exec;

    /* e42f4..e4310/e449c..e44a8: count first, optional profiler pop before
     * either the frame pointer or the depth is obtained. */
    g_retCount += 1u;
    if (g_bProfile != 0)
        CProfiler_Pop(g_profiler);

    /* e4314..e4330: snapshot both frame and caller buffer before decrement. */
    const volatile struct VMCallFrame *f =
        (const volatile struct VMCallFrame *)s->frame_base;
    uint32_t depth = (uint32_t)s->frame_depth;
    uintptr_t result = (uintptr_t)f + 60u;
    VMBuffer *buffer = f->caller_buffer;
    s->frame_depth = (int32_t)(depth - 1u);
    if (buffer == NULL)
        return (uint8_t *)result;

    /* e4334..e43a8: retain raw reads and field publication order. */
    int32_t distance = f->caller_frame_distance;
    uint32_t v34 = f->caller_state_34;
    uint32_t v30 = f->caller_state_30;
    uint32_t v3c = f->caller_state_3c;
    struct YYObjectBase *self = f->caller_self;
    struct YYObjectBase *other = f->caller_other;
    int32_t pc = f->caller_pc;
    uint32_t v38 = f->caller_state_38;
    s->state_34 = v34;
    uintptr_t previous_frame = 0;
    if (distance >= 0)
        previous_frame = (uintptr_t)s->frame_top;
    s->state_30 = v30;
    if (distance >= 0)
        previous_frame = (previous_frame - (uint32_t)distance) + (uintptr_t)s->stack_allocation;
    s->state_3c = v3c;
    uint32_t current_locals_mode = s->locals_mode;
    const uint8_t *code = ((const volatile VMBuffer *)buffer)->code;
    int32_t limit = ((const volatile VMBuffer *)buffer)->byte_limit;
    s->self = self;
    s->other = other;
    s->byte_pc = pc;
    s->buffer = buffer;
    s->state_38 = v38;
    s->frame_base = (uint8_t *)previous_frame;
    s->code = code;
    s->byte_limit = limit;

    /* e44ac..e44b8: no null guard on this call; reload +0x2c afterwards. */
    if (current_locals_mode == 0) {
        YYObjectBase_Free(s->locals);
        buffer = s->buffer;
    }

    /* e43ac..e43f4: save current buffer across conversion for the handler
     * table; read the offset map from the separately reloaded exec buffer. */
    struct YYObjectBase *saved_locals = f->caller_locals;
    uint32_t saved_mode = f->caller_locals_mode;
    s->locals = saved_locals;
    s->locals_mode = saved_mode;
    VMBuffer_convertBuffer(buffer);
    pc = s->byte_pc;
    const volatile VMBuffer *map_buffer = s->buffer;
    const volatile VMExecHandler *handlers = ((const volatile VMBuffer *)buffer)->handlers;
    const volatile uint32_t *map = map_buffer->offset_to_slot;
    void *to_delete = f->delete_on_return;
    s->handlers = handlers;
    uint32_t slot = map[pc / 4];
    s->offset_to_slot = map;
    s->next_slot = slot;

    /* e43f8: original operator delete at 0x27d1d0 is one unconditional
     * tail branch to MemoryManager::Free (0x27c2d0), with r0 unchanged. */
    MemoryManager_Free(to_delete);

    /* e4410..e446c: SUBS followed by BMI tests the sign of the wrapped
     * count-1. The traversal is held across callbacks; only the later
     * pointer arithmetic re-reads argc when this loop executed. */
    uint32_t argc = g_ArgumentCount;
    uint32_t countdown = argc - 1u;
    volatile VMWord *value = (volatile VMWord *)Argument;
    if ((int32_t)countdown >= 0) {
        do {
            uint32_t tag = value[3];
            if (((tag - 1u) & 0x00fffffcu) == 0)
                FREE_RValue__Pre((void *)value);
            value[2] = 0;
            value[3] = 5;
            value[0] = 0;
            value += 4;
        } while (countdown-- != 0);
        argc = g_ArgumentCount;
    }

    /* e4470..e4498: use the live stack allocation, restore saved argc and
     * Argument offset, then return frame+60+16*argc (32-bit shifts/adds). */
    uintptr_t stack = (uintptr_t)s->stack_allocation;
    result += argc << 4;
    uint32_t argument_offset = f->caller_argument_offset;
    g_ArgumentCount = f->caller_argc;
    Argument = (uint8_t *)(stack + argument_offset);
    return (uint8_t *)result;
}
