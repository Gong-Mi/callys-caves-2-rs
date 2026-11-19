#include "vm_exec.hpp"

/* VM::ExecRelease — readable C++ recovery of the original static member
 * _ZN2VM11ExecReleaseER6VMExecP6RValue at 0xe4540..0xe47c8 (152 instructions
 * + 10 pool words), pinned ARMv7 ELF SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * tier: bytecode_anchored. Instruction ownership/anchors:
 * cards/VM_ExecRelease.c + asm/index-VM_ExecRelease.tsv.
 * This is a static reading of the disassembly, not a runtime-equivalence
 * claim: the original was not executed, handler/global providers and both
 * Free bodies stay external, and nothing here is an oracle.
 *
 * Literal-pool GOT slots (base r5 = 0x3f1c58 after e4558):
 *   e47a4 -> &g_execCount          e47a8 -> &g_ArgumentCount
 *   e47ac -> &g_pCurrentExec       e47b0 -> &g_fDoExceptionUnwind
 *   e47b4 -> &g_paramSize (array)  e47b8 -> &g_exceptionVar
 *   e47bc -> &g_caughtExec         e47c0 -> &g_pExceptionSP
 *   e47c4 -> &stackPages
 *
 * gap: +0x30 state30 semantics, whole-class extents, RValue/YYObjectBase/
 * CProfiler APIs remain incomplete; +0x40 stackSpan was traced to the
 * 0x4000 byte count in VM::Exec, and this body reads
 * neither it nor state30 (only PerformReturn consumes the call frame).
 */

namespace {

/* ARM word transfers over aligned, differently-typed memory: the 16-byte
 * RValue images (g_exceptionVar, optional result) and the free-list link
 * written into the released allocation. */
typedef uint32_t VMWord __attribute__((may_alias));

inline uint32_t loadWord(const volatile void *address)
{
    return *static_cast<const volatile VMWord *>(address);
}

inline void storeWord(volatile void *address, uint32_t word)
{
    *static_cast<volatile VMWord *>(address) = word;
}

/* e4610: plain 32-bit ARM ADD; the unsigned cast preserves the wrap. */
inline int32_t pcAdd(int32_t pc, uint32_t width)
{
    return static_cast<int32_t>(static_cast<uint32_t>(pc) + width);
}

} // namespace

void VM::ExecRelease(VMExec &exec, RValue *out)
{
    /* Handlers may rewrite VMExec while they run, so every field access
     * below stays volatile and is re-read at the original site. */
    VMExec volatile &s = exec;

    uint8_t *sp = s.frameBase;                                  // e4560
    g_execCount += 1u;                                          // e4570..e4578
    g_pCurrentExec = &exec;                                     // e458c
    const uint32_t savedArgumentCount = g_ArgumentCount;   // e4590..e4594

    /* Outer frame loop. exit_frame with frameDepth > 0 re-enters at e4598,
     * so the mapping prologue runs once per frame, not once per call. */
    for (;;) {
        /* e4598..e45d0 — prologue: the table reads, the nextSlot publish and
         * the handler prefetch all happen before the PC/limit branch (flags
         * set at e45b8 are only consumed at e45d0). nextSlot = slot+1 is
         * published even when the frame is already finished. */
        int32_t pc = s.bytePc;                             // e4598
        const volatile uint32_t *slotMap = s.offsetToSlot; // e459c
        int32_t limit = s.byteLimit;                       // e45a8
        const volatile VMInstructionHandler *handlers = s.handlers; // e45b0
        /* Signed byte-PC / 4 truncating toward zero (e45a0..e45b4: the
         * +3-when-negative trick equals C++11 int division by 4). */
        const uint32_t slot = slotMap[pc / 4];             // e45c0
        s.nextSlot = slot + 1u;                                 // e45c4..e45c8
        VMInstructionHandler handler = handlers[slot];          // e45cc

        bool frameFinished = pc >= limit;                       // e45d0

        /* Inner dispatch loop, body e45dc..e469c. */
        while (!frameFinished) {
            const uint8_t *const code = s.code;                 // e45dc
            s.lastBytePc = pc;                                  // e45e4
            const uint8_t *const instruction =
                reinterpret_cast<const uint8_t *>(
                    reinterpret_cast<uintptr_t>(code) +
                    static_cast<uint32_t>(pc));            // e45ec..e45f4
            const uint32_t word = loadWord(instruction);   // e45ec
            uint32_t width = 4u;                           // e45e0
            /* e45f8..e460c: only with bit30 set is the paramSize table read
             * (predicated ldrne), at bits19:16 of the instruction word. */
            if (word & 0x40000000u)
                width += g_paramSize[(word >> 16) & 0xFu];
            s.bytePc = pcAdd(pc, width);                        // e4610..e4618
            /* e4614/e461c/e4620: (word, current SP, payload = instruction+4,
             * &exec); the returned SP is committed at e4644 (a register move
             * around the prefetch below, with no memory effect of its own). */
            sp = handler(word, sp, instruction + 4, &exec);

            /* e4624..e4640 — after the handler: sample the unwind byte
             * first, then re-read nextSlot and the handler table, publish
             * nextSlot+1 and prefetch the next handler, all before the
             * exception branch or the end-of-code test. */
            const uint8_t unwind = g_fDoExceptionUnwind;   // e4624
            const uint32_t nextSlot = s.nextSlot;          // e4628
            handlers = s.handlers;                              // e4630
            s.nextSlot = nextSlot + 1u;                         // e4634..e463c
            handler = handlers[nextSlot];                       // e4640

            if (unwind != 0u) {
                /* e4650..e4660: compare the two LIVE globals; &exec is not
                 * consulted. Mismatch ends this frame immediately. */
                VMExec *const current = g_pCurrentExec;
                VMExec *const caught = g_caughtExec;
                if (current != caught) {
                    frameFinished = true;
                } else {
                    /* e4664..e4688: read all four words of the exception
                     * image before g_pExceptionSP is read, then push the
                     * image at exceptionSP-16 and clear the unwind byte. */
                    const uint8_t *const excBase =
                        reinterpret_cast<const uint8_t *>(&g_exceptionVar);
                    const uint32_t excA = loadWord(excBase);       // e466c
                    const uint32_t excB = loadWord(excBase + 4);   // e466c
                    const uint32_t excC = loadWord(excBase + 8);   // e466c
                    const uint32_t excD = loadWord(excBase + 12);  // e466c
                    sp = g_pExceptionSP - 16;                     // e4670..e4674
                    storeWord(sp, excA);                          // e4678
                    storeWord(sp + 4, excB);                      // e467c
                    storeWord(sp + 8, excC);                      // e4680
                    storeWord(sp + 12, excD);                     // e4684
                    g_fDoExceptionUnwind = 0u;                    // e4688
                }
            }
            if (!frameFinished) {
                /* e468c..e469c: handler, PerformReturn-free callees or the
                 * exception path may have rewritten both fields. */
                pc = s.bytePc;                                    // e468c
                limit = s.byteLimit;                              // e4690
                frameFinished = pc >= limit;                      // e4694
            }
        }

        /* e46a0..e4750 — frame exit. Not the top level: return through the
         * real PerformReturn, then zero exactly three words below the
         * returned SP (offset +8 in the 16-byte slot stays live), and remap
         * the restored byte PC from the prologue. */
        if (s.frameDepth > 0) {                                   // e46a0..e46a8
            uint8_t *const ret = ::PerformReturn(sp, &exec);      // e4734..e473c
            storeWord(ret - 4, 0u);                               // e4740
            sp = ret - 16;                                        // e4744
            storeWord(sp, 0u);                                    // e4748
            storeWord(sp + 4, 0u);                                // e474c
            continue;                                             // e4750
        }
        break;                                                    // e46ac
    }

    /* Top-level exit. e46ac..e46b4: restore the entry argument count before
     * any result handling, even if nested returns changed the global. */
    g_ArgumentCount = savedArgumentCount;

    /* e46b0..e479c — optional result copy: out non-null AND the freshly
     * re-read frame base strictly above the current SP (unsigned). All four
     * source words are read before the first store, so overlapping source
     * and destination transfer the original 16-byte image. RValue is
     * deliberately incomplete: word-wise volatile access only, no invented
     * construction, assignment or destruction. */
    if (out != nullptr &&
        reinterpret_cast<uintptr_t>(s.frameBase) >
            reinterpret_cast<uintptr_t>(sp)) {               // e46bc..e46c4
        const uint32_t resA = loadWord(sp);                  // e477c
        const uint32_t resB = loadWord(sp + 4);              // e4780
        const uint32_t resC = loadWord(sp + 8);              // e4784
        const uint32_t resD = loadWord(sp + 12);             // e4788
        uint8_t *const dst = reinterpret_cast<uint8_t *>(out);
        storeWord(dst, resA);                                     // e478c
        storeWord(dst + 4, resB);                                 // e4790
        storeWord(dst + 8, resC);                                 // e4794
        storeWord(dst + 12, resD);                                // e4798
    }

    /* e46c8..e4778 — release the stack allocation. Walk the live page chain
     * with unsigned comparisons; a chunk inside [page+8, page+0x100008)
     * goes back on the free list, anything else (including no chain) takes
     * the generic MemoryManager::Free. Only +0x00 of each page node is
     * read; unknown04 is not accessed and its meaning is not inferred. */
    uint8_t *const allocation = s.stackAllocation;                // e46cc
    const uintptr_t address =
        reinterpret_cast<uintptr_t>(allocation);
    VMStackPagePrefix *page = stackPages.pageHead;                // e46d4
    while (page != nullptr) {
        const uintptr_t base =
            reinterpret_cast<uintptr_t>(page);
        if (address >= base + 8u && address < base + 0x100008u)   // e46e0..e46f8
            break;
        page = static_cast<volatile VMStackPagePrefix *>(page)->next; // e46fc
    }
    if (page == nullptr) {
        MemoryManager::Free(allocation);                          // e4708
    } else {
        /* e4754..e4774: three reads, then link-store into the released
         * chunk, free-head publish, count10++ and count0c-- with 32-bit
         * wrap, in this exact order. */
        uint8_t *const freeHead = stackPages.freeHead;            // e4754
        const uint32_t count10 = stackPages.count10;         // e4758
        const uint32_t count0c = stackPages.count0c;         // e475c
        storeWord(allocation,
                  static_cast<uint32_t>(
                      reinterpret_cast<uintptr_t>(freeHead)));// e4764
        stackPages.freeHead = allocation;                         // e476c
        stackPages.count10 = count10 + 1u;                        // e4770
        stackPages.count0c = count0c - 1u;                        // e4774
    }

    /* e470c..e4728: re-read localsMode/locals only after the stack release.
     * Nonzero mode keeps the locals object; on the freeing path the original
     * stores the already-loaded mode (necessarily 0 here) into +0x10, so
     * clearing via nullptr is the same word. */
    const uint32_t localsMode = s.localsMode;                // e470c
    if (localsMode == 0u) {
        YYObjectBase *const locals = s.locals;                    // e4718
        if (locals != nullptr) {
            YYObjectBase::Free(locals);                           // e4724
            s.locals = nullptr;                                   // e4728
        }
    }
}                                                                 // e472c..e4730
