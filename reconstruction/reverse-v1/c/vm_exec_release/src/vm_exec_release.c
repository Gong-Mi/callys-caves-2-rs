/* VM::ExecRelease: original ARMv7 entry 0xe4540, 152 instructions + 10 pool words.
 * tier: bytecode_anchored; instruction ownership: cards/VM_ExecRelease.c.
 * gap: internal callees and global providers remain linkage dependencies;
 * this translation is not an original-execution oracle or a Rust integration.
 */
#include "vm_exec_release.h"

#define OFFSET(type, member, offset) \
    _Static_assert(offsetof(type, member) == (offset), #type "." #member)
OFFSET(VMExec, stack_allocation, 0x08);
OFFSET(VMExec, locals_mode, 0x0c);
OFFSET(VMExec, locals, 0x10);
OFFSET(VMExec, code, 0x24);
OFFSET(VMExec, frame_base, 0x28);
OFFSET(VMExec, byte_pc, 0x44);
OFFSET(VMExec, next_slot, 0x48);
OFFSET(VMExec, frame_depth, 0x4c);
OFFSET(VMExec, byte_limit, 0x50);
OFFSET(VMExec, last_byte_pc, 0x54);
OFFSET(VMExec, handlers, 0x58);
OFFSET(VMExec, offset_to_slot, 0x5c);
OFFSET(struct VMStackPage, next, 0x00);
OFFSET(struct VMStackPages, page_head, 0x04);
OFFSET(struct VMStackPages, free_head, 0x08);
OFFSET(struct VMStackPages, count_0c, 0x0c);
OFFSET(struct VMStackPages, count_10, 0x10);
#undef OFFSET
_Static_assert(sizeof(VMExecHandler) == 4, "ARMv7 handler stride");

/* ARM word transfers of aligned, possibly differently typed memory. */
typedef uint32_t VMWord __attribute__((may_alias));

static uint32_t load_word(const volatile void *ptr)
{
    return *(const volatile VMWord *)ptr;
}

static void store_word(volatile void *ptr, uint32_t word)
{
    *(volatile VMWord *)ptr = word;
}

static int32_t pc_add(int32_t pc, uint32_t width)
{
    /* ARM ADD wraps. On the required Clang ARM32 target the cast preserves bits. */
    return (int32_t)((uint32_t)pc + width);
}

void VM_ExecRelease(VMExec *exec, void *out)
{
    volatile VMExec *s = exec;
    /* e4560, e4570..e4594: snapshot frame base, increment count, publish
     * current exec, then save the argument count for the top-level exit. */
    uint8_t *sp = s->frame_base;
    g_execCount += 1u;
    g_pCurrentExec = exec;
    uint32_t saved_argument_count = g_ArgumentCount;
    int32_t pc;
    int32_t limit;
    uint32_t slot;
    VMExecHandler handler;

enter_frame:
    /* e4598..e45d0: read both tables and publish slot+1 even if at end.
     * The first map uses signed truncation toward zero, not the dense slot. */
    pc = s->byte_pc;
    const volatile uint32_t *map = s->offset_to_slot;
    limit = s->byte_limit;
    const volatile VMExecHandler *handlers = s->handlers;
    slot = map[pc / 4];
    s->next_slot = slot + 1u;
    handler = handlers[slot];
    if (pc >= limit)
        goto end_frame;

    for (;;) {
        /* e45dc..e4620: last PC, raw header and payload pointer; publish
         * next byte PC before giving the callback its writable VMExec. */
        const uint8_t *code = s->code;
        s->last_byte_pc = pc;
        const uint8_t *instruction = (const uint8_t *)((uintptr_t)code + (uint32_t)pc);
        uint32_t word = load_word(instruction);
        uint32_t width = 4u;
        if (word & 0x40000000u)
            width += g_paramSize[(word >> 16) & 15u];
        s->byte_pc = pc_add(pc, width);
        sp = handler(word, sp, instruction + 4, exec);

        /* e4624..e464c: sample unwind first, then re-read cursor/table and
         * prefetch before using that flag or testing the end-of-code PC. */
        uint8_t unwind = g_fDoExceptionUnwind;
        slot = s->next_slot;
        handlers = s->handlers;
        s->next_slot = slot + 1u;
        handler = handlers[slot];
        if (unwind) {
            /* e4650..e4660: compare the two LIVE globals, not caught==exec. */
            VMExec *current = g_pCurrentExec;
            VMExec *caught = g_caughtExec;
            if (current != caught)
                goto end_frame;
            /* e4664..e4688: read all four words, replace returned SP, copy
             * exception to exception_sp-16 and clear the unwind byte. */
            uint32_t a = g_exceptionVar[0];
            uint32_t b = g_exceptionVar[1];
            uint32_t c = g_exceptionVar[2];
            uint32_t d = g_exceptionVar[3];
            sp = g_pExceptionSP - 16;
            store_word(sp, a);
            store_word(sp + 4, b);
            store_word(sp + 8, c);
            store_word(sp + 12, d);
            g_fDoExceptionUnwind = 0;
        }
        /* e468c..e469c: handler/return paths may have changed both fields. */
        pc = s->byte_pc;
        limit = s->byte_limit;
        if (pc >= limit)
            break;
    }

end_frame:
    /* e46a0..e46a8/e4734..e4750: pop a live frame, zero exactly three
     * words (result+8 remains), then remap the restored byte PC. */
    if (s->frame_depth > 0) {
        uint8_t *ret = PerformReturn(sp, exec);
        store_word(ret - 4, 0u);
        sp = ret - 16;
        store_word(sp, 0u);
        store_word(sp + 4, 0u);
        goto enter_frame;
    }

    /* e46ac..e46c4/e477c..e479c: restore argument count before result handling;
     * copy four source words before the first store, including overlap. */
    g_ArgumentCount = saved_argument_count;
    if (out != NULL && (uintptr_t)s->frame_base > (uintptr_t)sp) {
        uint32_t a = load_word(sp);
        uint32_t b = load_word(sp + 4);
        uint32_t c = load_word(sp + 8);
        uint32_t d = load_word(sp + 12);
        uint8_t *dst = out;
        store_word(dst, a);
        store_word(dst + 4, b);
        store_word(dst + 8, c);
        store_word(dst + 12, d);
    }

    /* e46c8..e4708: search the live page chain by unsigned address. */
    void *allocation = s->stack_allocation;
    uintptr_t addr = (uintptr_t)allocation;
    const struct VMStackPage *page = stackPages.page_head;
    for (; page != NULL; page = ((const volatile struct VMStackPage *)page)->next) {
        uintptr_t base = (uintptr_t)page;
        if (addr >= base + 8u && addr < base + 0x100008u)
            break;
    }
    if (page == NULL) {
        MemoryManager_Free(allocation);
    } else {
        /* e4754..e4778: push the returned pointer on the free list and
         * update exactly these two counters, with ARM32 wrap semantics. */
        void *head = stackPages.free_head;
        uint32_t count_10 = stackPages.count_10;
        uint32_t count_0c = stackPages.count_0c;
        store_word(allocation, (uint32_t)(uintptr_t)head);
        stackPages.free_head = allocation;
        stackPages.count_10 = count_10 + 1u;
        stackPages.count_0c = count_0c - 1u;
    }

    /* e470c..e4730: re-read locals after releasing the stack; retain when
     * mode is nonzero. On the freeing path clear +0x10 after the call. */
    if (s->locals_mode == 0) {
        struct YYObjectBase *locals = s->locals;
        if (locals != NULL) {
            YYObjectBase_Free(locals);
            s->locals = NULL;
        }
    }
}
