#include "vm_debug_runtime.hpp"

/* VM::ExecDebug — readable C++ recovery of the original static member
 * _ZN2VM9ExecDebugER6VMExecP6RValueb at 0xe47c8..0xe4ba8 (248 words,
 * 992 bytes, seventeen tail pool words e4b64..e4ba4), pinned ARMv7 ELF
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * tier: bytecode_anchored. This is a static reading of
 * original-0xe47c8.asm.txt / index-0xe47c8.tsv, not a runtime-equivalence
 * claim: the original was not executed; handlers, the debugger server and
 * DebugInfo/DebugLineNumber stay external, and frame/LR/fault/concurrent
 * unwind domains remain unproved.
 *
 * GOT base r5 = 0x3f1c58 (e47d0/e47e0). Literal-pool bindings:
 *   e4b68 -> &g_execCount            e4b6c -> &g_ArgumentCount
 *   e4b70 -> &g_pServer              e4b74 -> &g_DebugStepType
 *   e4b78 -> &g_pCurrentExec         e4b7c -> &g_DoSingleStep
 *   e4b80 -> &g_instructions (inline 128B table, opcode-indexed, NOT the
 *          per-exec dense handler array used by ExecRelease)
 *   e4b84 -> &g_fDoExceptionUnwind   e4b88 -> &g_caughtExec
 *   e4b90 -> &g_SingleStepCurrentScript  e4b94 -> &g_SingleStepRetCount
 *   e4b8c -> &stackPages             e4b98 -> &g_paramSize
 *   e4b9c -> &g_SingleStepCurrentLine    e4ba0 -> &g_exceptionVar
 *   e4ba4 -> &g_pExceptionSP
 *
 * Differences from ExecRelease that the original CFG forces and keeps here:
 * entry captures frameBase BEFORE the g_execCount bump and never publishes
 * g_pCurrentExec at entry (publish only around handlers); the byte PC is
 * always +4 and only bit30 adds g_paramSize; the debug helper pair runs per
 * iteration when g_pServer is live and g_DebugStepType >= 0, with the loop
 * payload spilled to private +00 and reloaded from the same slot; the
 * step-type/source/ret-count decision re-reads the LIVE globals; the
 * synthesized single-step break (word 0xff0f0000, opcode 31, size index 15)
 * goes through the normal table dispatch instead of calling any DoBreak
 * helper; frame exit clears three words (ret-4/ret-16/ret-12) keeping the
 * slot +8 aux; cleanup frees locals only when the promoted bool is set AND
 * localsMode > 0 (the Release rule is localsMode == 0). No nextSlot/handlers
 * /offsetToSlot access at all.
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

/* Plain 32-bit ARM ADD: address arithmetic and PC/count updates wrap as u32. */
inline const uint8_t *byteAt(const uint8_t *base, uint32_t offset)
{
    return reinterpret_cast<const uint8_t *>(
        reinterpret_cast<uintptr_t>(base) + offset);
}

inline uint32_t wordAt(const uint8_t *base, uint32_t offset)
{
    return loadWord(byteAt(base, offset));
}

} // namespace

void VM::ExecDebug(VMExec &exec, RValue *out, bool freeLocals)
{
    /* Handlers and debug helpers may rewrite VMExec while they run, so every
     * field access below stays volatile and is re-read at the original site.
     * The private 20-byte image mirrors original sp+00..0c exactly. */
    VMExec volatile &s = exec;
    VMDebugPrivateImage priv;

    priv.freeLocals0c = freeLocals ? 1u : 0u;                   // e47e4
    uint8_t *sp = s.frameBase;                                  // e47f4
    g_execCount = g_execCount + 1u;                             // e47f8..e4800
    const uint32_t savedArgc = g_ArgumentCount;                 // e4808 BEFORE both private stores
    priv.argcCell04 = static_cast<uint32_t>(                    // e4804..e480c
        reinterpret_cast<uintptr_t>(&g_ArgumentCount));
    priv.argcSnapshot08 = savedArgc;                            // e4810
    /* e4814: no g_pCurrentExec publish at entry — the original leaves the
     * caller's published exec in place until a dispatch is imminent. */

    /* Hoisted so the original register lifetimes (r6/r3/r14/r12/r9) survive
     * the non-structured gotos below; vacuous initialization keeps every
     * forward goto legal. */
    int32_t oldPC;
    uint32_t inst;
    const uint8_t *payload;
    uint32_t opcode;
    uint32_t sizeIndex;

loop_head:                                                      // e4814
    oldPC = s.bytePc;                                           // e4814
    if (oldPC >= s.byteLimit)                                   // e4818..e4820
        goto frame_exit;
    {
        const uint8_t *const code = s.code;                     // e4824
        const uint32_t nextPC =                                 // e4828
            static_cast<uint32_t>(oldPC) + 4u;
        s.lastBytePc = oldPC;                                   // e4830
        inst = wordAt(code, static_cast<uint32_t>(oldPC));      // e4834
        payload = byteAt(code, nextPC);                         // e4838
        s.bytePc = static_cast<int32_t>(nextPC);                // e483c
    }

    if (g_pServer == nullptr) {                                 // e4840..e484c
        /* No debugger server: skip step checks; still publish and dispatch. */
        opcode = (inst >> 24) & 31u;                            // e4a88
        g_pCurrentExec = &exec;                                 // e4a90
        if ((inst & 0x40000000u) == 0u)
            goto dispatch;                                      // e4a94
        sizeIndex = (inst >> 16) & 15u;                         // e4a98
        goto advance_param;                                     // e4a98..e4a44
    }
    if (g_DebugStepType >= 0) {                                 // e4850..e4860
        priv.payload00 = static_cast<uint32_t>(                 // e488c
            reinterpret_cast<uintptr_t>(payload));
        /* r1 still holds the pre-advance byte PC at e4890. */
        VMDebugInfo *const info = VM::DebugInfo(s.debugBuffer, oldPC); // e4988..e4990
        const int32_t line =                                    // e4994..e499c
            VM::DebugLineNumber(info, s.sourceText, nullptr);
        payload = reinterpret_cast<const uint8_t *>(            // e49a4 reload
            static_cast<uintptr_t>(priv.payload00));
        uint32_t depth = 0u;                                    // e49ac..e49d0
        VMExec *node = g_pCurrentExec;
        while (node != nullptr) {
            volatile VMExec &n = *node;
            const int32_t nodeDepth = n.frameDepth;             // +4c
            depth = depth + 1u;
            node = n.parentExec;                                // +04
            depth = depth + static_cast<uint32_t>(nodeDepth);   // u32 wrap
        }
        const char *const source = s.sourceText;                // e49d4
        if (source == nullptr)
            goto single_step_check;                             // e49dc
        const char *const currentScript =                       // e49e0..e49ec
            g_SingleStepCurrentScript;
        if (source == currentScript &&
            line == g_SingleStepCurrentLine)                    // e4aa4..e4ab4
            goto single_step_check;                             // e4ab8
        const int32_t stepType = g_DebugStepType;               // e49f4 LIVE
        if (stepType == 0)
            goto inject_break;                                  // e49fc
        if (stepType == 2) {                                    // e4a00..e4a04
            if (g_SingleStepRetCount <                          // e4abc..e4acc
                static_cast<int32_t>(depth))
                goto single_step_check;
            if (source == currentScript)                        // e4ad0..e4ad4
                goto single_step_check;                         // e4ad8
            goto inject_break;                                  // e4ad4 bne
        }
        if (g_SingleStepRetCount <                              // e4a08..e4a18
            static_cast<int32_t>(depth))
            goto single_step_check;
        goto inject_break;                                      // e4a1c
    }

single_step_check:                                              // e4864..e487c
    if (g_DoSingleStep != 0u)
        goto inject_break;
    g_pCurrentExec = &exec;                                     // e4884
    opcode = (inst >> 24) & 31u;                                // e4888
    if ((inst & 0x40000000u) != 0u) {                           // e488c
        sizeIndex = (inst >> 16) & 15u;                         // e4a98
        goto advance_param;
    }

dispatch:                                                       // e4890
    {
        /* inst, held SP, the ORIGINAL instruction's payload (code+oldPC+4,
         * never re-derived) and &exec; the inline g_instructions table is
         * indexed by opcode directly. */
        const VMInstructionHandler handler = g_instructions[opcode]; // e48a4/e48a8
        uint8_t *const returned = handler(inst, sp, payload, &exec); // e48ac
        g_pCurrentExec = &exec;                                 // e48b4
        const uint8_t unwind = g_fDoExceptionUnwind;            // e48bc
        sp = returned;                                          // e48c4
        if (unwind == 0u)
            goto loop_head;                                     // e48c8
        if (g_caughtExec != &exec)                              // e48cc..e48dc
            goto frame_exit;                                    // fall to e48e0
        /* e4b0c..e4b3c: all four exception words are read BEFORE
         * g_pExceptionSP; the same image is pushed at exceptionSP-16 and
         * only then is the unwind byte cleared. */
        const uint8_t *const excBase =
            reinterpret_cast<const uint8_t *>(&g_exceptionVar); // e4b1c ldm
        const uint32_t excA = loadWord(excBase);
        const uint32_t excB = loadWord(byteAt(excBase, 4u));
        const uint32_t excC = loadWord(byteAt(excBase, 8u));
        const uint32_t excD = loadWord(byteAt(excBase, 12u));
        sp = reinterpret_cast<uint8_t *>(static_cast<uintptr_t>(
            object_wire::address(g_pExceptionSP) - 16u));       // e4b20..e4b24, ARM32 wrap
        storeWord(sp, excA);                                    // e4b28
        storeWord(const_cast<uint8_t *>(byteAt(sp, 4u)), excB);   // e4b2c
        storeWord(const_cast<uint8_t *>(byteAt(sp, 8u)), excC);   // e4b30
        storeWord(const_cast<uint8_t *>(byteAt(sp, 12u)), excD);  // e4b34
        g_fDoExceptionUnwind = 0u;                              // e4b38 strb
        goto loop_head;                                         // e4b3c
    }

inject_break:                                                   // e4a24
    /* Synthesized break goes through the SAME table dispatch: word
     * 0xff0f0000, opcode 31, size index 15 added to the LIVE byte PC. No
     * DoBreak helper and no server-vtable call is invented here. */
    inst = 0xff0f0000u;                                         // e4a24/e4a28
    opcode = 31u;                                               // e4a2c
    sizeIndex = 15u;                                            // e4a30
    g_DoSingleStep = 0u;                                        // e4a34 strb
    g_pCurrentExec = &exec;                                     // e4a3c
    g_DebugStepType = -1;                                       // e4a40 mvn

advance_param:                                                  // e4a44
    {
        const uint32_t heldPc = static_cast<uint32_t>(s.bytePc); // e4a48 FIRST volatile read
        const uint32_t parameterBytes = g_paramSize[sizeIndex]; // e4a50 AFTER PC read
        s.bytePc = static_cast<int32_t>(heldPc + parameterBytes); // e4a54/e4a58
    }
    goto dispatch;                                              // e4a5c

frame_exit:                                                     // e48e0
    if (s.frameDepth > 0) {                                     // e48e4..e48e8
        /* Not the top level: real PerformReturn, then clear exactly the
         * kind word (ret-4) and the 16-byte slot's low two words
         * (ret-16/ret-12); the +8 aux word stays live. */
        uint8_t *const ret = ::PerformReturn(sp, &exec);        // e4a60..e4a68
        const uint32_t returned = object_wire::address(ret);
        storeWord(reinterpret_cast<void *>(static_cast<uintptr_t>(returned - 4u)), 0u); // e4a6c
        sp = reinterpret_cast<uint8_t *>(static_cast<uintptr_t>(returned - 16u)); // e4a70
        storeWord(sp, 0u);                                     // e4a74
        storeWord(reinterpret_cast<void *>(static_cast<uintptr_t>(returned - 12u)), 0u); // e4a78
        goto loop_head;                                         // e4a7c
    }

    /* Top level. e48ec..e48f8: restore the saved argument count through the
     * cell address kept in the private image, before any result handling. */
    *reinterpret_cast<volatile uint32_t *>(
        static_cast<uintptr_t>(priv.argcCell04)) = priv.argcSnapshot08;
    if (out != nullptr) {                                       // e48f0
        if (reinterpret_cast<uintptr_t>(s.frameBase) >          // e4900..e4908
            reinterpret_cast<uintptr_t>(sp)) {
            /* All four words are read before the first store, so the
             * original 16-byte image survives overlap. */
            const uint32_t resA = loadWord(sp);                 // e4b40
            const uint32_t resB = loadWord(byteAt(sp, 4u));     // e4b44
            const uint32_t resC = loadWord(byteAt(sp, 8u));     // e4b48
            const uint32_t resD = loadWord(byteAt(sp, 12u));    // e4b4c
            uint8_t *const dst = reinterpret_cast<uint8_t *>(out);
            storeWord(dst, resA);                               // e4b50
            storeWord(const_cast<uint8_t *>(byteAt(dst, 4u)), resB); // e4b54
            storeWord(const_cast<uint8_t *>(byteAt(dst, 8u)), resC); // e4b58
            storeWord(const_cast<uint8_t *>(byteAt(dst, 12u)), resD); // e4b5c
        }
    }

    /* e490c..e4b00: release the stack allocation. Walk the live page chain
     * with unsigned comparisons; a chunk inside [page+8, page+0x100008)
     * goes back on the free list, anything else (including no chain) takes
     * the real MemoryManager::Free. Only +0x00 of each page node is read. */
    {
        uint8_t *const allocation = s.stackAllocation;          // e4910
        const uintptr_t address = reinterpret_cast<uintptr_t>(allocation);
        VMStackPagePrefix *page = stackPages.pageHead;          // e4918
        while (page != nullptr) {
            const uintptr_t base = reinterpret_cast<uintptr_t>(page);
            if (address >= base + 8u && address < base + 0x100008u) // e492c..
                break;
            page = static_cast<volatile VMStackPagePrefix *>(page)->next;
        }
        if (page == nullptr) {
            MemoryManager::Free(allocation);                    // e494c
        } else {
            /* e4adc..e4afc: freeHead/count10/count0c reads, then link-store
             * into the released chunk, free-head publish, count10++ and
             * count0c-- with 32-bit wrap, in this exact order. */
            uint8_t *const freeHead = stackPages.freeHead;      // e4adc
            const uint32_t count10 = stackPages.count10;        // e4ae0
            const uint32_t count0c = stackPages.count0c;        // e4ae4
            storeWord(allocation, static_cast<uint32_t>(        // e4aec
                reinterpret_cast<uintptr_t>(freeHead)));
            stackPages.freeHead = allocation;                   // e4af4
            stackPages.count10 = count10 + 1u;                  // e4af8
            stackPages.count0c = count0c - 1u;                  // e4afc
        }
    }

    /* e4950..e497c: locals are released only when the caller's promoted
     * bool (private +0c) is nonzero AND localsMode reads LIVE > 0 (signed,
     * NOT the Release ==0 rule) AND locals is live non-null. The top-level
     * caller (VM::Exec outer frames) owns the current-caller restore; this
     * body performs none. */
    if (priv.freeLocals0c != 0u) {
        if (static_cast<int32_t>(s.localsMode) > 0) {
            YYObjectBase *const locals = s.locals;              // e4968
            if (locals != nullptr) {
                YYObjectBase::Free(locals);                     // e4974
                s.locals = nullptr;                             // e497c
            }
        }
    }
    return;                                                     // e4980..e4984
}
