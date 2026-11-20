#include "vm_entry_runtime.hpp"

/* tier: bytecode_anchored. VM::Exec, 0xe7fd0..0xe8588, 1464B including
 * twelve pool words; original ARMv7 SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Parent repair of the preserved worker delivery: original 0x78 pool fill,
 * +0x8008 alignment, separate empty/nonempty join reads, and same-storage
 * callback spills/reloads. No original or rebuilt target execution.
 * gap: complete classes, bad pointer/size domains, private garbage, original
 * LR, paired atomicity and unwind remain unproved; raw accesses express the
 * observed contract, not a general C++ lifetime or behavior equivalence proof.
 */
void VM::Exec(CCode *code, YYObjectBase *selfIn, YYObjectBase *otherIn,
              RValue *result, YYObjectBase *localsIn, int argcIn,
              RValue *argv, int eighthInt, YYObjectBase *argumentsObject) {
    (void)eighthInt; // original incoming sp+0xac is never consumed
    alignas(8) VMEntryPrivateImage image; // no value initialization
    VMExec &exec = image.exec18;
    const uint32_t ex = object_wire::address(&exec);
    const uint32_t cc = object_wire::address(code);
    const uint32_t selfWord = object_wire::address(selfIn);
    const uint32_t otherWord = object_wire::address(otherIn);

    // e7fe4 / e8210..e822c: separate anonymous guard, ONLY these pool fields.
    if (vm_entry_state::stackPoolInitialized == 0u) {
        vm_entry_state::stackPoolInitialized = 1u;
        stackPages.pageHead = nullptr;
        stackPages.freeHead = nullptr;
        stackPages.count0c = 0u;
    }
    // e8014/e8020/e8024/e8028/e8030/e8034: preserve actual read order.
    const uint32_t heldText = object_wire::read(cc, 0x58);
    const uint32_t heldName = object_wire::read(cc, 0x5c);
    const uint8_t trace = g_fVMTrace;
    const int32_t localCount = g_nLocalVariables;
    const uint32_t heldBuffer = object_wire::read(cc, 0x50);
    uint32_t debugWord = object_wire::read(cc, 0x54);
    image.localCount10 = static_cast<uint32_t>(localCount); // e8038
    image.text0c = heldText;                               // e803c
    if (trace != 0u) {
        // e82b4..e82cc: one global pointer read; same console is callback this.
        VMDebugConsolePrefix *const console = dbg_csol;
        const uint32_t table = object_wire::read(object_wire::address(console), 0u);
        VMTracePrint const print = reinterpret_cast<VMTracePrint>(
            static_cast<uintptr_t>(object_wire::read(table, 12u)));
        image.word04 = debugWord;
        print(console, "script = %s\n",
              reinterpret_cast<const char *>(static_cast<uintptr_t>(heldName)));
        debugWord = image.word04; // e82d0, not another CCode read
    }

    const uint32_t freeHead = object_wire::address(stackPages.freeHead); // e8044
    object_wire::write(ex, 0x14, selfWord);                             // e804c
    object_wire::write(ex, 0x18, otherWord);                            // e8054
    object_wire::write(ex, 0x40, 0x4000u);                             // e8058
    uint32_t chunk;
    uint32_t count10;
    uint32_t nextFree;
    uint32_t cursorOffset;
    if (freeHead == 0u) {
        image.word04 = debugWord; // e8334, retained across new and memset
        const uint32_t base = object_wire::address(operator new(0x108008u));
        memset(reinterpret_cast<void *>(static_cast<uintptr_t>(base + 8u)),
               0x78, 0x108000u); // e833c MOV r1,#120; e8340 length 0x108000
        const uint32_t oldFree = object_wire::address(stackPages.freeHead); // e8350
        const uint32_t oldPage = object_wire::address(stackPages.pageHead); // e8354
        const uint32_t aligned = ((base + 0x8000u + 8u) & ~0x7f00u) & ~0xffu;
        const uint32_t oldCount = stackPages.count10; // e8360
        image.word14 = oldFree;                      // e8364
        object_wire::write(base, 0u, oldPage);        // e836c
        stackPages.pageHead = reinterpret_cast<VMStackPagePrefix *>(
            static_cast<uintptr_t>(base));           // e8374
        debugWord = image.word04;                    // e838c
        object_wire::write(aligned, 0u, image.word14);// e837c/e8390
        stackPages.freeHead = reinterpret_cast<uint8_t *>(
            static_cast<uintptr_t>(aligned));        // e8394
        stackPages.count10 = oldCount + 1u;          // e8398
        uint32_t previous = aligned;
        uint32_t node = aligned + 0x8000u;
        const uint32_t end = aligned + 0xf8000u;
        do {
            object_wire::write(node, 0u, previous);   // e83a4
            nextFree = previous;                    // r0 retained on final iteration
            previous = node;                        // e83a8 r12=node
            node += 0x8000u;                        // e83ac
        } while (node != end);
        const uint32_t span = object_wire::read(ex, 0x40); // e83b8
        count10 = oldCount + 31u;                   // e83bc
        chunk = aligned + 0xf0000u;                 // e83c0
        cursorOffset = span - 16u;                  // e83c4
        // e83c8 joins e806c, BYPASSING e8068's memory read. nextFree is r0.
    } else {
        chunk = freeHead;
        count10 = stackPages.count10;               // e8060
        nextFree = object_wire::read(chunk, 0u);     // e8068, nonempty path only
        cursorOffset = 0x3ff0u;                      // e8064
    }
    const uint32_t argc = static_cast<uint32_t>(argcIn); // e806c
    const uint32_t cursor = chunk + cursorOffset;        // e8070
    stackPages.freeHead = reinterpret_cast<uint8_t *>(
        static_cast<uintptr_t>(nextFree));               // e8074
    count10 -= 1u;                                      // e8078
    const uint32_t byteLimit = object_wire::read(heldBuffer, 4u); // e807c
    const uint32_t bytes = argc << 4;                    // e8080
    const uint32_t codeBytes = object_wire::read(heldBuffer, 0x10); // e8084
    const uint32_t destination = cursor - bytes;         // e8088, ARM32 wrap
    object_wire::write(ex, 0x38, debugWord);              // e808c
    const uint32_t sourceText = image.text0c;             // e8090
    object_wire::write(ex, 8u, chunk);                    // e8094
    const uint32_t activeCount = stackPages.count0c;      // e8098
    object_wire::write(ex, 0x50, byteLimit);              // e80a0
    stackPages.count10 = count10;                        // e80a8
    object_wire::write(ex, 0x24, codeBytes);              // e80b0
    stackPages.count0c = activeCount + 1u;               // e80b8
    object_wire::write(ex, 0x2c, heldBuffer);              // e80bc
    object_wire::write(ex, 0x3c, sourceText);              // e80c0
    object_wire::write(ex, 0x34, heldName);                // e80c4

    const uint32_t copied = object_wire::address(memcpy(
        reinterpret_cast<void *>(static_cast<uintptr_t>(destination)), argv, bytes));
    object_wire::write(ex, 0x20, argc);                  // e80e8
    const uint32_t savedArgc = g_ArgumentCount;          // e80ec
    RValue *const savedArgument = Argument;             // e80f0
    const uint32_t frame = copied - 60u;                // e80f4, no C pointer-before-object UB
    object_wire::write(ex, 0x28, frame);                 // e80fc
    object_wire::write(ex, 0x1c, copied);                // e8108
    Argument = reinterpret_cast<RValue *>(static_cast<uintptr_t>(copied)); // e810c
    g_ArgumentCount = argc;                             // e8110
    memset(reinterpret_cast<void *>(static_cast<uintptr_t>(frame)), 0, 60u);
    const uint32_t recordOffset = object_wire::read(cc, 0x6c); // e8118
    const uint32_t liveFrame = object_wire::read(ex, 0x28);    // e8120
    object_wire::write(liveFrame, 0x0c, 0xffffffffu);         // e812c
    object_wire::write(ex, 0x44, recordOffset);               // e8130
    object_wire::write(ex, 0x4c, 0u);                         // e8138: sp+64 - exec base18 = frameDepth+4c
    VMExec *const oldCurrent = g_pCurrentExec;                // e8140
    if (oldCurrent != nullptr) {
        object_wire::write(object_wire::address(oldCurrent), 0u, ex); // e814c
    }
    object_wire::write(ex, 4u, object_wire::address(oldCurrent)); // e8150
    g_pCurrentExec = &exec;                                  // e8158
    object_wire::write(ex, 0u, 0u);                          // e815c
    image.word00 = heldBuffer;                              // e8160
    reinterpret_cast<VMBuffer *>(static_cast<uintptr_t>(heldBuffer))->convertBuffer();
    const uint32_t mapReceiver = object_wire::read(ex, 0x2c); // e8168
    const uint32_t handlerReceiver = image.word00;           // e816c
    const uint32_t providedLocals = object_wire::address(localsIn); // e8170
    const uint32_t map = object_wire::read(mapReceiver, 0x18); // e8174
    const uint32_t handlers = object_wire::read(handlerReceiver, 0x14); // e8178
    object_wire::write(ex, 0x5c, map);                        // e8180
    object_wire::write(ex, 0x58, handlers);                   // e8184
    if (providedLocals != 0u) {
        object_wire::write(ex, 0x10, providedLocals);         // e8190
        object_wire::write(ex, 0x0c, 1u);                    // e8194
    } else {
        YYObjectBase *const fresh = YYAllocLocalStackNew(static_cast<int>(image.localCount10));
        object_wire::write(ex, 0x0c, 0u);                    // e83d8
        object_wire::write(ex, 0x10, object_wire::address(fresh)); // e83dc
    }

    if (g_fJSGarbageCollection != 0u) {
        PushContextStack(reinterpret_cast<YYObjectBase *>(static_cast<uintptr_t>(
            object_wire::read(ex, 0x10))));                  // e8230/e8234
        const uint32_t local = object_wire::read(ex, 0x10);  // e8238, AFTER Push
        uint32_t slot = object_wire::read(local, 4u);        // e823c
        if (slot == 0u) {
            slot = object_wire::address(reinterpret_cast<YYObjectBase *>(
                static_cast<uintptr_t>(local))->InternalGetYYVar(0)); // e8454
        }
        const uint32_t rawKind = object_wire::read(slot, 0x0c);
        const uint32_t kind = rawKind & 0x00ffffffu;
        if (kind == 1u) {
            uint32_t ref = object_wire::read(slot, 0u);
            uint32_t count = 0u;
            uint32_t payload = 0u;
            if (ref != 0u) {
                image.word08 = slot; image.word04 = ref;     // e82e4/e82e8
                LOCK_RVALUE_MUTEX();
                ref = image.word04; slot = image.word08;    // e82f0/e82f4
                count = object_wire::read(ref, 4u) - 1u;
                object_wire::write(ref, 4u, count);
                if (count != 0u) goto tail0;

                payload = object_wire::read(ref, 0u);        // e83e4
                image.word00 = count; image.word04 = ref;    // e83e8 BEFORE YYFree
                YYFree(reinterpret_cast<const void *>(static_cast<uintptr_t>(payload)));
                count = image.word00; ref = image.word04;    // e83f0
                object_wire::write(ref, 0u, count);
                object_wire::write(ref, 8u, count);
                image.word04 = ref;
                LOCK_RVALUE_MUTEX();
                ref = image.word04; slot = image.word08;    // e8404/e8408
                count = object_wire::read(ref, 4u) - 1u;
                object_wire::write(ref, 4u, count);
                if (count == 0u) goto level2;
                goto tail1;
            level2:
                payload = object_wire::read(ref, 0u);        // e8460
                image.word00 = count; image.word04 = ref;    // e8464
                YYFree(reinterpret_cast<const void *>(static_cast<uintptr_t>(payload)));
                count = image.word00; ref = image.word04;    // e846c
                object_wire::write(ref, 0u, count);
                object_wire::write(ref, 8u, count);
                image.word04 = ref;
                LOCK_RVALUE_MUTEX();
                ref = image.word04; slot = image.word08;    // e8480/e8484
                count = object_wire::read(ref, 4u) - 1u;
                object_wire::write(ref, 4u, count);
                if (count == 0u) goto level3;
                goto tail2;
            level3:
                payload = object_wire::read(ref, 0u);        // e84c0
                image.word00 = count; image.word04 = ref;    // e84c4
                YYFree(reinterpret_cast<const void *>(static_cast<uintptr_t>(payload)));
                count = image.word00; ref = image.word04;    // e84cc
                object_wire::write(ref, 0u, count);
                object_wire::write(ref, 8u, count);
                image.word04 = ref;
                LOCK_RVALUE_MUTEX();
                ref = image.word04; slot = image.word08;    // e84e0/e84e4
                count = object_wire::read(ref, 4u) - 1u;
                object_wire::write(ref, 4u, count);
                if (count != 0u) goto tail3;

                payload = object_wire::read(ref, 0u);        // e84fc
                image.word00 = count; image.word04 = ref;    // e8500
                YYFree(reinterpret_cast<const void *>(static_cast<uintptr_t>(payload)));
                count = image.word00; ref = image.word04;    // e8508
                object_wire::write(ref, 0u, count);
                object_wire::write(ref, 8u, count);
                image.word04 = ref;
                reinterpret_cast<_RefThing<const char *> *>(static_cast<uintptr_t>(ref))->dec();
                ref = image.word04;                         // e8520
                operator delete(reinterpret_cast<void *>(static_cast<uintptr_t>(ref)));
                ref = image.word04; slot = image.word08;     // e852c/e8530
            tail3:
                image.word08 = slot; image.word04 = ref;
                UNLOCK_RVALUE_MUTEX();
                ref = image.word04;                         // e8540
                operator delete(reinterpret_cast<void *>(static_cast<uintptr_t>(ref)));
                ref = image.word04; slot = image.word08;     // e854c/e8550
            tail2:
                image.word08 = slot; image.word04 = ref;
                UNLOCK_RVALUE_MUTEX();
                ref = image.word04;                         // e84a8
                operator delete(reinterpret_cast<void *>(static_cast<uintptr_t>(ref)));
                ref = image.word04; slot = image.word08;     // e84b4/e84b8
            tail1:
                image.word08 = slot; image.word04 = ref;
                UNLOCK_RVALUE_MUTEX();
                ref = image.word04;                         // e842c
                operator delete(reinterpret_cast<void *>(static_cast<uintptr_t>(ref)));
                slot = image.word08;                        // e8438
            tail0:
                image.word08 = slot;
                UNLOCK_RVALUE_MUTEX();
                slot = image.word08;                        // e8314
            }
            object_wire::write(slot, 0u, 0u);               // e831c
        } else if (kind == 2u) {
            if ((((rawKind - 1u) & 0x00ffffffu) & ~3u) == 0u) {
                image.word08 = slot;
                FREE_RValue__Pre(reinterpret_cast<RValue *>(static_cast<uintptr_t>(slot)));
                slot = image.word08;                        // e844c
            }
        }
        const uint32_t argsObject = object_wire::address(argumentsObject); // e8274
        object_wire::write(slot, 0x0c, 6u);                 // e8280
        object_wire::write(slot, 8u, 5u);                   // e8288
        object_wire::write(slot, 0u, argsObject);            // e828c; high +4 untouched
        if (argsObject != 0u) {
            YYObjectBase *const top = GetContextStackTop();
            DeterminePotentialRoot(top, argumentsObject); // e8298 re-evaluates incoming arg9 after the call
        }
        PopContextStack();
    }
    if (g_pServer != nullptr) ExecDebug(exec, result, false);
    else ExecRelease(exec, result);

    const uint32_t parent = object_wire::read(ex, 4u);       // e81d0
    if (parent != 0u) object_wire::write(parent, 0u, 0u);     // e81dc
    const uint32_t mode = object_wire::read(ex, 0x0c);        // e81e0
    g_pCurrentExec = reinterpret_cast<VMExec *>(static_cast<uintptr_t>(parent));
    g_ArgumentCount = savedArgc;
    Argument = savedArgument;
    if (mode == 0u) {
        const uint32_t local = object_wire::read(ex, 0x10);  // e81f8
        if (local != 0u) YYObjectBase::Free(reinterpret_cast<YYObjectBase *>(
            static_cast<uintptr_t>(local)));
    }
}
