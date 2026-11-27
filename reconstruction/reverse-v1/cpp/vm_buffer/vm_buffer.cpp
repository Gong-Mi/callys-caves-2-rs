/*
 * vm_buffer.cpp — recovered C++ method bodies for VMBuffer.
 *
 * tier: bytecode_anchored.  Every block below is pinned to original words of
 * libyoyo_armv7.so, sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * (intake index-*.tsv: 0xce43c, 0xce4c0, 0xec748, 0xec750..0xecb34).  The
 * original was read, never executed; this is not a runtime assembly and not
 * an equivalence proof against the original.
 *
 * Specific gaps left open by this module:
 *  - Cache writers: the lookup only reads the bucket hash (+0x08) and
 *    handlers (+0x04); who inserts/grows/evicts (count +0x04, growAt +0x0c
 *    are never touched here) is unproven.
 *  - The vptr re-establishment at 0xce448..0xce458 (pool word 0xce4bc) and
 *    the deleting clone 0xce4c0 (body + operator delete) are compiler-
 *    generated from the virtual destructor; they are not source statements.
 *  - Handler bodies, allocator failure semantics and the WAD loader remain
 *    separate internal dependencies, not implementations supplied here.
 * CALL2 exclusion is 499999: the raw MOVW 0xe30a211f at 0xec8c4 supplies
 * 0xa11f and MOVT 0xe3402007 at 0xec8cc supplies 7, forming 0x7a11f.
 * It is NOT 500000 (0x7a120). Both LLVM and GNU disassembly confirm this.
 */

#include "vm_buffer.hpp"

namespace {

/* 0xecb18 / 0xecb30 both resolve to the same complete VMBuffer.cpp path;
 * every Alloc in this function tags it with clear=true (VMBuffer.cpp:126/127). */
const char vmBufferSourcePath[] = "jni/../jni/yoyo/../../../Files/Code/VMBuffer.cpp";

/* 0xec83c / 0xec930 / 0xeca14: aligned word LDR over the CODE stream at the
 * wrapped 32-bit address (base + offset); not four byte loads. */
typedef uint32_t InstructionWord __attribute__((may_alias));

uint32_t readInstructionWord(const uint8_t *code, uint32_t byteOffset) {
    const uintptr_t address = reinterpret_cast<uintptr_t>(code) + byteOffset;
    return *reinterpret_cast<const volatile InstructionWord *>(address);
}

/* 0xec840..0xec85c (pass 1) and 0xec934..0xec950 (pass 2): the header is four
 * bytes, plus the declared payload when bit30 selects g_paramSize[bits19:16]. */
uint32_t instructionPayloadStep(uint32_t word) {
    if ((word & 0x40000000u) == 0u) {
        return 4u;
    }
    return 4u + g_paramSize[(word >> 16) & 0xFu];
}

/* 0xec954..0xec968: the original's signed round-toward-zero word index for a
 * byte offset (add r8,r3,#3 / movge r8,r3 / asr r8,#2).  Keep uint32 wrap. */
uint32_t slotWordIndexOf(uint32_t byteOffset) {
    uint32_t adjusted = byteOffset + 3u;
    if (static_cast<int32_t>(byteOffset) >= 0) {
        adjusted = byteOffset;
    }
    return static_cast<uint32_t>(static_cast<int32_t>(adjusted) >> 2);
}

/* 0xec780..0xec9b0: probe the anonymous dispatch cache at 0x47f3a0.  Returns
 * the hit bucket, or nullptr when the cold path must build fresh tables.
 * The home-bucket hit (0xec7b4) skips the probe-distance pre-check and the
 * idx sentinel; only the collision-walk hit (0xec7dc -> 0xec9ac) sees them. */
const volatile VMBufferCacheBucket *findCachedDispatchTable(uint32_t key) {
    const uint32_t mask = g_VMBufferDispatchCache.mask;                     /* +0x08, 0xec788 */
    const volatile VMBufferCacheBucket *buckets = g_VMBufferDispatchCache.buckets; /* +0x10, 0xec78c */
    uint32_t idx = key & mask;                                              /* 0xec794 */
    uint32_t bucketHash = buckets[idx].hash;                                /* 0xec798..0xec7a4, 12B buckets */
    if (bucketHash == 0u) {
        return nullptr;                                                     /* 0xec7ac beq -> cold */
    }
    if (bucketHash == key) {
        return &buckets[idx];                                               /* 0xec7b4 beq -> hit tail */
    }

    const uint32_t capacity = g_VMBufferDispatchCache.capacity;             /* +0x00, 0xec7b8 */
    const int32_t firstDiff = static_cast<int32_t>(
        ((idx + capacity) - (bucketHash & mask)) & mask);                   /* 0xec7bc..0xec7c8 tst */
    if (firstDiff < 0) {
        return nullptr;                                                     /* 0xec7cc bmi -> cold */
    }

    uint32_t probes = 0u;                                                   /* 0xec7d0 (r12 = handlers = 0) */
    for (;;) {
        idx = (idx + 1u) & mask;                                            /* 0xec7e8/0xec7f0 */
        probes += 1u;                                                       /* 0xec7ec */
        const uint32_t walkAccumulator = idx + capacity;                    /* 0xec7f4 */
        bucketHash = buckets[idx].hash;                                     /* 0xec7f8..0xec804 */
        const int32_t diff = static_cast<int32_t>(
            (walkAccumulator - (bucketHash & mask)) & mask);                /* 0xec808..0xec814 */
        if (bucketHash == 0u) {
            return nullptr;                                                 /* 0xec80c/0xec818 empty -> cold */
        }
        if (bucketHash == key) {                                            /* 0xec7d8 hit precedes distance */
            if (idx == 0xffffffffu) {
                return nullptr;                                             /* 0xec9ac cmn r3,#1 sentinel */
            }
            return &buckets[idx];
        }
        if (diff < static_cast<int32_t>(probes)) {
            return nullptr;                                                 /* 0xec7e0/0xec7e4 signed blt */
        }
    }
}

/* 0xec95c..0xeca50 / 0xec9d0..0xeca84 / 0xeca08..0xecab8 / 0xec8fc..0xec90c:
 * the dense-slot handler for one instruction word.  A special target replaces
 * the g_instructions[opcode] default only on the exact tested pattern; no
 * callback runs during selection. */
VMInstructionHandler selectSpecialHandler(uint32_t word, const uint8_t *code,
                                         uint32_t byteOffset) {
    const uint32_t opcode = (word >> 24) & 0x1Fu; /* 0xec95c ubfx bits28:24 */
    if (opcode == 7u) {
        /* 0xec974..0xec994: bits11:8 clear AND bits23:16 == 0x52. */
        if ((word & 0x00000F00u) == 0u && ((word >> 16) & 0xFFu) == 0x52u) {
            return DoConvIntToVariable; /* GOT slot 0x3edd7c, 0xec998..0xec9a4 */
        }
    } else if (opcode == 5u) {
        /* 0xec9d0..0xec9ec: nibbles 19:16 and 23:20 both 5, sxth(word) == -7,
         * and the bit30 flag saved at 0xec934 (cmp r11 at 0xeca6c). */
        if (((word >> 16) & 0xFu) == 5u && ((word >> 20) & 0xFu) == 5u &&
            static_cast<int16_t>(word) == -7 && (word & 0x40000000u) != 0u) {
            return DoPopLocalVariable; /* GOT slot 0x3edd84, 0xeca74..0xeca80 */
        }
    } else if (opcode == 25u && ((word >> 16) & 0xFu) == 2u) {
        /* 0xeca08..0xeca10: only CALL2 (nibble 19:16 == 2) reads the id word. */
        const uint32_t id = readInstructionWord(code, byteOffset + 4u); /* 0xeca14 ldr [r10,#4] */
        /* 0xeca1c..0xeca34: unsigned interval, excluding spilled 0x7a11f.
         * Thus 499999 uses the default table and 500000 selects GML. */
        if ((id - 100000u) <= 400000u && id != 499999u) {
            return DoCallGML; /* GOT slot 0x3edd80, 0xeca40..0xeca4c */
        }
        /* 0xeca88..0xeca90: signed compare against spilled 99999. */
        if (static_cast<int32_t>(id) <= 99999) {
            return DoCallLibrary; /* GOT slot 0x3edd88, 0xeca94..0xecaA0 */
        }
    }
    // No table read here: the caller must load its destination before reading
    // the default slot (0xec900..0xec90c), rather than reverse those accesses.
    return nullptr;
}

} // namespace

/* 0xce43c..0xce4bc — _ZN8VMBufferD1Ev / D2Ev.
 * The base-class vptr re-establishment (0xce448..0xce458, pool 0xce4bc) and
 * the deleting clone _ZN8VMBufferD0Ev at 0xce4c0 (this body followed by
 * operator delete) are generated by the C++ compiler from this definition,
 * not written here. */
VMBuffer::~VMBuffer() {
    volatile VMBuffer *state = this;
    /* 0xce444..0xce468: hold the tested pointer across the Free call. */
    VMInstructionHandler *const oldHandlers = state->handlers;
    if (oldHandlers != nullptr) {
        MemoryManager::Free(oldHandlers); /* 0xce460 */
        state->handlers = nullptr;        /* 0xce468 */
    }
    /* 0xce46c..0xce480: release the offset->slot map, then clear it. */
    uint32_t *const oldMap = state->offsetToSlot;
    if (oldMap != nullptr) {
        MemoryManager::Free(oldMap);   /* 0xce478 */
        state->offsetToSlot = nullptr; /* 0xce480 */
    }
    /* 0xce484..0xce4b0: borrowed WAD memory keeps its pointer. A non-WAD
     * result re-reads code before delete[]; the pointer can be null then. */
    uint8_t *const inspectedCode = state->code;
    if (inspectedCode != nullptr && !MemoryInWad(inspectedCode)) {
        delete[] state->code; /* 0xce49c..0xce4a8 */
        state->code = nullptr; /* 0xce4b0 */
    }
}

/* 0xec748..0xec74c — _Z21CHashMapCalculateHashIPhEjT_: add r0,r0,#1; bx lr.
 * Plain 32-bit pointer value plus one, wrapping; no thumb bit, tag or
 * alignment normalisation. */
template <>
unsigned int CHashMapCalculateHash<unsigned char *>(unsigned char *value) {
    return static_cast<unsigned int>(reinterpret_cast<uintptr_t>(value)) + 1u;
}

/* 0xec750..0xecb34 — _ZN8VMBuffer13convertBufferEv. */
void VMBuffer::convertBuffer() {
    volatile VMBuffer *state = this;
    /* 0xec758..0xec774: already converted — return without touching anything. */
    if (state->handlers != nullptr) {
        return;
    }

    /* 0xec778..0xec790: hash the reloaded code field, clear bit31 for the key. */
    const uint32_t key =
        CHashMapCalculateHash<unsigned char *>(state->code) & 0x7FFFFFFFu;

    /* 0xec780..0xec9cc: cache lookup.  A hit writes handlers (+0x14) only —
     * never the map (+0x18), never the bucket, even when the bucket stores a
     * NULL table.  The wrapped NULL bucket slot (address +4 == 0, 0xec9bc)
     * rejects to the cold path. */
    const volatile VMBufferCacheBucket *hit = findCachedDispatchTable(key);
    const uintptr_t hitAddress = reinterpret_cast<uintptr_t>(hit);
    if (hit != nullptr && hitAddress + 4u != 0u) {
        state->handlers = hit->handlers;
        return;
    }

    /* 0xec81c..0xec824: reload the signed span once; it drives both passes. */
    const int32_t span = state->bufferSize;

    if (span <= 0) {
        /* 0xecac0..0xecb08: non-positive span reads no code word at all.
         * Fixed 4-byte handler table (:126), published before the map
         * Alloc (:127).  The add/movlt/bic pair is the original's signed
         * expression with uint32 wrap kept: span -4 allocates zero bytes. */
        state->handlers = static_cast<VMInstructionHandler *>(
            MemoryManager::Alloc(4u, vmBufferSourcePath, 126, true)); /* 0xecad8/0xecaf8 */
        uint32_t rounded = static_cast<uint32_t>(span);               /* 0xecae0 cmp */
        if (span < 0) {
            rounded += 3u;                                            /* 0xecadc/0xecaec movlt */
        }
        state->offsetToSlot = static_cast<uint32_t *>(MemoryManager::Alloc(
            (rounded & ~3u) + 4u, vmBufferSourcePath, 127, true));    /* 0xecaf0..0xecb04 */
        return;
    }

    /* Pass 1, 0xec828..0xec868: count instruction heads over the CODE stream.
     * The original commits the increment only on the continue edge, so it
     * leaves (count+2)<<2 == (heads+1)*4 here — handlers capacity heads+1. */
    const uint8_t *stream = state->code; /* 0xec82c */
    uint32_t heads = 0u;
    uint32_t offset = 0u;
    for (;;) {
        const uint32_t word = readInstructionWord(stream, offset); /* 0xec83c */
        heads += 1u;
        offset += instructionPayloadStep(word);                    /* 0xec840..0xec860 */
        if (static_cast<int32_t>(offset) >= span) {
            break;                                                 /* 0xec864/0xec868 ble exit */
        }
    }

    /* 0xec86c..0xec890: handler table, tag VMBuffer.cpp:126, clear=true. */
    state->handlers = static_cast<VMInstructionHandler *>(MemoryManager::Alloc(
        (heads + 1u) << 2, vmBufferSourcePath, 126, true));

    /* 0xec894..0xec8b8: map table, 4*(trunc(span/4)+1) bytes (:127).  The
     * first table is published (+0x14, 0xec8b0) BEFORE the second Alloc. */
    const uint32_t mapSize = (static_cast<uint32_t>(span) & ~3u) + 4u;
    uint32_t *const firstMap = static_cast<uint32_t *>(
        MemoryManager::Alloc(mapSize, vmBufferSourcePath, 127, true));
    state->offsetToSlot = firstMap;

    /* Pass 2, 0xec8bc..0xeca50: fields are re-read from `this` at the
     * original points (code at 0xec928, handlers at 0xec900, map at 0xec924). */
    uint32_t slot = 0u;         /* r6 @0xec8d0 */
    uint32_t handlerBytes = 0u; /* r12 @0xec8bc */
    offset = 0u;                /* r3 @0xec8d4 */
    volatile uint32_t *mapForInstruction = firstMap; // 0xec8e8 skips first reload
    for (;;) {
        const uint8_t *currentCode = state->code; /* 0xec928 */
        const uint32_t word = readInstructionWord(currentCode, offset);
        const uint32_t step = instructionPayloadStep(word); /* 0xec934..0xec950 */

        /* 0xec954..0xec96c: the map is written at instruction heads only. */
        const uintptr_t mapCell = reinterpret_cast<uintptr_t>(mapForInstruction) +
                                  (slotWordIndexOf(offset) << 2);
        *reinterpret_cast<volatile uint32_t *>(mapCell) = slot;

        /* 0xec95c..0xeca50: handler selection, stored into the dense array. */
        const VMInstructionHandler special = selectSpecialHandler(word, currentCode, offset);
        const uintptr_t handlerCell = reinterpret_cast<uintptr_t>(state->handlers) + handlerBytes;
        const VMInstructionHandler selected = special != nullptr
            ? special : g_instructions[(word >> 24) & 0x1fu];
        *reinterpret_cast<volatile VMInstructionHandler *>(handlerCell) = selected;

        offset += step;         /* 0xec910 */
        slot += 1u;             /* 0xec914 */
        if (span <= static_cast<int32_t>(offset)) {
            return;             /* 0xec918/0xec920 ble -> 0xec770 */
        }
        handlerBytes += 4u;     /* 0xec91c */
        mapForInstruction = state->offsetToSlot; /* 0xec924 */
    }
}
