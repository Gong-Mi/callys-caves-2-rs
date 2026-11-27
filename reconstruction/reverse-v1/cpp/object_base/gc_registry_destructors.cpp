/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 * This TU carries the two real C++ destructors the 0xb9814 .init fragment
 * registers directly through __aeabi_atexit, each one a WEAK same-address
 * D1/D2 alias pair exactly as the original dynsym spells it:
 *   _ZN6YYSlotI12YYObjectBaseED1Ev / D2Ev  @0x190d00  44B  STB_WEAK
 *   _ZN4HashI9CInstanceED1Ev / D2Ev        @0x190d2c 148B  STB_WEAK
 * Registration evidence in the frozen window gc-image-startup.asm.txt:
 *   0xb983c ldr r6,[r5,lr]  -> 0x3edc4c -> 0x536f28 CInstance::ms_ID2Instance
 *   0xb986c/0xb9874         -> 0x3f0698 -> 0x190d2c Hash<CInstance> D1/D2
 *   0xb9884/0xb9890         -> 0x3edc6c -> 0x536f0c g_slotObjects (16B YYSlot)
 *   0xb989c/0xb98b8         -> 0x3f069c -> 0x190d00 YYSlot<YYObjectBase> D1/D2
 * AAPCS: r0 carries `this` in, and both bodies finish with the original's
 * `mov r0, <this>` before the return, so the destructor result pointer is
 * preserved. Nothing here launches, loads or emulates the target.
 *
 * gap: this is the two destructor bodies only. The remaining 0xb9814 work
 * (the four CGCGeneration constructors at 0xb98cc..0xb98dc, the 0xb9908
 * pointer hand-off, and the storage plus initialisation of every startup
 * global) stays with the parent line; the two .init constructor fragments are
 * NOT claimed to be the whole 0xb9814 body. Unproved by this TU: the node
 * record extent past +0x0c, bucket+0x04, node+0x00/+0x08, the allocator size
 * class, the receiver's dynamic type and vtable, and whether the original
 * ever reaches a non-zero mask with a NULL table.
 */

#include "gc_instance_hash.hpp"                       /* sibling: Hash<CInstance> + InstanceHash* */
#include "object_internal.hpp"                        /* frozen ObjectSlotRegistry + object_wire  */
#include "../vm_exec/vm_entry_runtime.hpp"            /* canonical YYFree declaration */

/* ------------------------------------------------------------------ 0x190d00
 * YYSlot<YYObjectBase>::~YYSlot  (D1/D2 weak aliases, 44B):
 *   0x190d04 mov r4,r0                              this is pinned once
 *   0x190d08 ldr r0,[r0]                            one read of +0, never re-read
 *   0x190d0c bl  _Z6YYFreePKv                       UNCONDITIONAL, no null probe
 *   0x190d10 mov r3,#0 / 0x190d14 mov r0,r4         r0 = this for the AAPCS result
 *   0x190d18 str r3,[r4]      +0x00 slots    = 0
 *   0x190d1c str r3,[r4,#4]   +0x04 capacity = 0
 *   0x190d20 str r3,[r4,#8]   +0x08 count    = 0
 *   0x190d24 str r3,[r4,#12]  +0x0c firstFree= 0
 * The volatile view keeps all five original word accesses separate and in
 * address order; no null guard, no re-read and no partial clear stands in.
 */
__attribute__((weak))
YYSlot<YYObjectBase>::~YYSlot() noexcept(false) {
    volatile YYSlot<YYObjectBase> &live = *this;

    YYObjectBase *volatile *const held = live.slots;  /* 0x190d08 ldr r0,[r0]: one read, never re-read */
    YYFree(reinterpret_cast<const void *>(
        reinterpret_cast<uintptr_t>(held)));          /* 0x190d0c bl _Z6YYFreePKv, unconditional */

    live.slots = nullptr;                                /* 0x190d18 str r3,[r4] */
    live.capacity = 0u;                                  /* 0x190d1c str r3,[r4,#4] */
    live.count = 0u;                                     /* 0x190d20 str r3,[r4,#8] */
    live.firstFree = 0;                                  /* 0x190d24 str r3,[r4,#12] */
}

/* ------------------------------------------------------------------ 0x190d2c
 * Hash<CInstance>::~Hash  (D1/D2 weak aliases, 148B), original word order:
 *   0x190d30 mov r6,r0 / 0x190d34 ldm r0,{r0,r8}   table and mask read together
 *   0x190d38 cmp r8,#0; 0x190d3c lslge r7,r8,#3; 0x190d40 movge r9,#0
 *   0x190d44 blt 0x190db4                          signed bound: mask < 0 skips
 *                                                  the whole walk and still
 *                                                  frees the held table
 *   0x190d48 ldr r4,[r0,r7]                        bucket head, mask down to 0
 *                                                  inclusive (0x190da4 sub r8,#1
 *                                                  + 0x190dac cmn r8,#1)
 *   0x190d50 str r9,[r0,r7] / 0x190d58 str r9,[r3,#4]   head then +0x04, both
 *                                                        cleared before the
 *                                                        0x190d5c null branch
 *   0x190d60 ldr r3,[r4,#12]                       receiver, read before the call
 *   0x190d64 ldr r5,[r4,#4]                        next, read before the call
 *   0x190d68..0x190d7c                             non-null receiver only: its own
 *                                                  vptr word +0x04, real blx
 *   0x190d88 bl MemoryManager::Free(node)          real free of the chain node
 *   0x190d8c/0x190d98 ldr+str [r6,#8]              live count, read after that
 *                                                  call and written back -1
 *   0x190da0 ldr r0,[r6]                           LIVE table re-read, taken only
 *                                                  once a chain drained; an empty
 *                                                  bucket 0x190d5c->0x190da4 keeps
 *                                                  the previously held pointer
 *   0x190db4 bl MemoryManager::Free(table)         unconditional tail free
 * Volatile views pin every reload the original performs after a call; no safe
 * early exit (null table, negative live count, empty mask) replaces one.
 */
__attribute__((weak))
Hash<CInstance>::~Hash() noexcept(false) {
    volatile Hash<CInstance> &live = *this;

    InstanceHashBucket *table = live.buckets;  /* 0x190d34 ldm word +0x00 */
    int32_t bucket = live.mask;                /* 0x190d34 ldm word +0x04, signed */

    if (bucket >= 0) {                         /* 0x190d38 cmp / 0x190d44 blt */
        for (; bucket >= 0; --bucket) {        /* 0x190da4..0x190db0 mask..0 inclusive */
            const uintptr_t address = reinterpret_cast<uintptr_t>(table) +
                                      static_cast<uint32_t>(bucket) * 8u;
            auto *const slot = reinterpret_cast<volatile InstanceHashBucket *>(address);
            InstanceHashNode *node = slot->head00;  /* 0x190d48 ldr r4,[r0,r7] */
            slot->head00 = nullptr;                 /* 0x190d50 str r9,[r0,r7] */
            slot->unknown04 = 0u;                   /* 0x190d58 str r9,[r3,#4] */
            if (node == nullptr) {                  /* 0x190d54 cmp / 0x190d5c beq */
                continue;                           /* no 0x190da0 reload on this path */
            }
            do {
                const volatile InstanceHashNode *held = node;
                void *value = held->value0c;             /* 0x190d60, before the call */
                InstanceHashNode *next = held->next04;   /* 0x190d64, before the call */
                if (value != nullptr) {                  /* 0x190d68 cmp / 0x190d70 beq */
                    // The vptr's concrete receiver type is not established.
                    typedef uint32_t AliasWord __attribute__((may_alias));
                    const uintptr_t vptr = *reinterpret_cast<const volatile AliasWord *>(value);
                    const uintptr_t target = *reinterpret_cast<const volatile AliasWord *>(vptr + 4u);
                    reinterpret_cast<void (*)(void *)>(target)(value);
                }
                MemoryManager::Free(node);                /* 0x190d88 real Free edge */
                live.liveCount = live.liveCount - 1u;      /* 0x190d8c ldr / 0x190d94 sub / 0x190d98 str */
                node = next;
            } while (node != nullptr);                    /* 0x190d90 cmp / 0x190d9c bne */
            table = live.buckets;                         /* 0x190da0 LIVE re-read after the drain */
        }
    }

    MemoryManager::Free(table);                           /* 0x190db4 unconditional */
}
