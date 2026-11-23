/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU recovers exactly four CGCGeneration bodies, word-ordered against
 * the sibling anchor windows (all dynsym GLOBAL):
 *   AddDynamicRoot(YYObjectBase*,bool) _ZN13CGCGeneration14AddDynamicRoot 0x19135c
 *   ResetDynamicRoots()                _ZN13CGCGeneration17ResetDynamicRoots 0x191400
 *   UpdateRange(int)                   _ZN13CGCGeneration11UpdateRange 0x19150c
 *   ResetClassStats()                  _ZN13CGCGeneration15ResetClassStats 0x191530
 * Each read, the compare sign, and the store-before/after-a-call placement
 * mirror the disassembly literally. gap: faults (ReAlloc/Free edges, a NULL
 * classStatsArray48 or dynamicRoots deref, opaque object+0x38 on a non-object),
 * unwind/EHABI records, and any equivalence-by-execution claim stay unproved;
 * the original was never run for this recovery.
 */
#include "gc_generation.hpp"

namespace {

typedef uint32_t RawWord __attribute__((may_alias));

/* Live 32-bit load at a computed address, mirroring the original `ldr`
 * against the opaque YYObjectBase+0x38 word (0x191378). No object model is
 * invented for the whole object; only the offset the anchor reads. */
inline uint32_t readRawWord(uint32_t address) {
    return *reinterpret_cast<const volatile RawWord *>(static_cast<uintptr_t>(address));
}

/* 0x331038 .rodata string consumed by the ReAlloc tag argument (literal pool
 * word at 0x1913fc: add r2,pc,r2 with pc=0x1913dc -> 0x331038), the same
 * MemoryManager.h path the seam's Alloc edge publishes, line 74. */
const char memoryManagerHeaderSourcePath[] =
    "jni/../jni/yoyo/../../../Platform/MemoryManager.h";

} // namespace

void CGCGeneration::AddDynamicRoot(YYObjectBase *obj, bool force) {
    volatile CGCGeneration &self = *this;

    /* 0x191360 subs r5,r1,#0 / 0x19136c beq: a NULL object returns first,
     * before the force test and before any field is touched. */
    if (obj == nullptr) {
        return;
    }

    /* 0x191370 cmp r2,#0 / 0x191374 bne: force==true skips the guard.
     * Otherwise (0x191378 ldr [obj,#56] THEN 0x19137c ldr [this,#16],
     * 0x191380 cmp, 0x191384 beq) the object's +0x38 word must equal
     * this+0x10; the read order and the address arithmetic stay as written. */
    if (!force) {
        const uint32_t objWord38 = readRawWord(
            static_cast<uint32_t>(reinterpret_cast<uintptr_t>(obj)) + 0x38u);
        const uint32_t selfWord10 = self.unknownWord10;
        if (objWord38 != selfWord10) {
            return;
        }
    }

    /* 0x191390 ldr r3,[r4,#8] (count), 0x191394 ldr r1,[r4,#12] (capacity),
     * 0x191398 cmp / 0x19139c bge: signed count >= capacity grows. */
    int32_t count = self.dynamicRootCount;
    const int32_t capacity = self.dynamicRootCapacity;
    YYObjectBase **array;

    if (count < capacity) {
        array = self.dynamicRoots; /* 0x1913a0 ldr r1,[r4,#4] */
    } else {
        /* 0x1913b8 lsls r3,r1,#1: new capacity is the 32-bit wrap of cap<<1.
         * ne/eq drive BOTH the +0x0c store and the byte size; the original
         * writes +0x0c BEFORE it re-reads +0x04. */
        const uint32_t doubled = static_cast<uint32_t>(capacity) << 1u;
        unsigned int bytes;
        if (doubled != 0u) { /* 0x1913c0 strne / 0x1913c4 lslne r1,r1,#3 */
            self.dynamicRootCapacity = static_cast<int32_t>(doubled);
            bytes = static_cast<unsigned int>(static_cast<uint32_t>(capacity) << 3u);
        } else { /* 0x1913c8 moveq r3,#1 / 0x1913cc moveq r1,#4 / 0x1913d0 streq */
            self.dynamicRootCapacity = 1;
            bytes = 4u;
        }

        /* 0x1913d8 ldr r0,[r4,#4] reads the held pointer AFTER +0x0c changed. */
        YYObjectBase **const held = self.dynamicRoots;

        /* 0x1913dc..0x1913e8 real edge: ReAlloc(held, bytes,
         * tag@0x331038, line 74, false). The stack slot is the false bool. */
        YYObjectBase **const grown = reinterpret_cast<YYObjectBase **>(
            MemoryManager::ReAlloc(held, bytes, memoryManagerHeaderSourcePath, 74, false));

        /* 0x1913ec ldr r3,[r4,#8]: LIVE count re-read after the call;
         * 0x1913f0 mov r1,r0 / 0x1913f4 str r0,[r4,#4]: publish the held
         * return, the slot is not re-read as the array base. */
        count = self.dynamicRootCount;
        self.dynamicRoots = grown;
        array = grown;
    }

    /* Both paths merge at 0x1913a4: publish count+1 (+0x08) first, then use
     * the OLD count to place the root pointer (0x1913ac str r5,[r1,r3,lsl#2]). */
    const uint32_t oldIndex = static_cast<uint32_t>(count);
    self.dynamicRootCount = static_cast<int32_t>(oldIndex + 1u);
    const uintptr_t slot = reinterpret_cast<uintptr_t>(array) + (oldIndex << 2u);
    *reinterpret_cast<YYObjectBase *volatile *>(slot) = obj;
}

void CGCGeneration::ResetDynamicRoots() {
    /* 0x191400 mov r3,#0 / 0x191404 str r3,[r0,#8]: only +0x08 is cleared;
     * the array pointer, capacity and every other field are left untouched. */
    volatile CGCGeneration &self = *this;
    self.dynamicRootCount = 0;
}

void CGCGeneration::UpdateRange(int value) {
    volatile CGCGeneration &self = *this;

    /* 0x19150c / 0x191510: both old words are read before any store. */
    const int32_t oldMin = self.rangeMin14; /* +0x14 */
    const int32_t oldMax = self.rangeMax18; /* +0x18 */
    const int32_t arg = static_cast<int32_t>(value);

    /* Signed compares. Each field gets exactly one store even when the value
     * is unchanged: the predicated strle/strgt (min) and strge/strlt (max)
     * both keep-or-adopt, so this is min(old,arg) and max(old,arg). */
    self.rangeMin14 = (oldMin <= arg) ? oldMin : arg; /* 0x191514-0x19151c */
    self.rangeMax18 = (oldMax >= arg) ? oldMax : arg; /* 0x191520-0x191528 */
}

void CGCGeneration::ResetClassStats() {
    volatile CGCGeneration &self = *this;

    /* 0x191538 ldr r3,[r0,#76] / 0x19153c cmp #0 / 0x191548 beq: the loop
     * body runs only when +0x4c != 0; r3/r4 start at 0 (0x191540/0x191544). */
    if (self.classStatsCount4c != 0) {
        uint32_t index = 0u;
        for (;;) {
            /* 0x19154c re-reads the LIVE array pointer each round (8B stride). */
            const uintptr_t base =
                reinterpret_cast<uintptr_t>(self.classStatsArray48);
            /* 0x191554 ldr r0,[r2,r3,lsl#3]: the entry's +0 payload pointer. */
            void *const entryPayload =
                reinterpret_cast<void *>(static_cast<uintptr_t>(readRawWord(base + index * 8u)));
            MemoryManager::Free(entryPayload); /* 0x191558 real Free edge */

            /* 0x191550 add r4,r4,#1 then 0x19155c LIVE re-read of +0x4c;
             * 0x191564/0x191568 cmp/bcc UNSIGNED against that live bound. */
            index += 1u;
            const uint32_t liveCount =
                static_cast<uint32_t>(self.classStatsCount4c);
            if (index >= liveCount) {
                break;
            }
        }
    }

    /* 0x19156c mov r3,#0 / 0x191570 str r3,[r5,#76]: unconditional +0x4c clear.
     * Neither the array block (+0x48) nor any other field is freed or zeroed. */
    self.classStatsCount4c = 0;
}
