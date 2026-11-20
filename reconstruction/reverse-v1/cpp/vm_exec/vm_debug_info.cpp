#include "vm_debug_info.hpp"

/* Recovered C++ bodies, not the original source spelling.
 * tier: bytecode_anchored; VM::DebugInfo 0xec144/100B/25 words, zero pool;
 * VM::DebugLineNumber 0xec2b8/452B/113 words, tail pool 0xec474/0xec478;
 * ARMv7 image SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * DebugInfo consumes bufferSize as an unsigned word and shifts it LOGICALLY >>3
 * (LSRS ec158); record count 0 returns null yet the +0x10 code pointer is still
 * read (ldr ec154 precedes the shift). Only the +0 PC key of each stride-8 record
 * is loaded; both key comparisons interpret signed (cmp/blt ec164-ec168 signed
 * pc<firstKey, cmp/bgt ec178 signed nextKey>pc), and the returned record is the
 * held previous pointer via the [r2,#8]! pre-increment walk (record 0 when the
 * first following key already exceeds PC, last record when the loop exhausts).
 * DebugLineNumber returns -1 before any strlen on null info; the +0x04
 * sourceByteOffset word is read AFTER strlen completes and compared SIGNED
 * (cmp/sublt ec2dc-ec2e0), so only a shortening clamp is applied, then a
 * negative offset yields -1 and offset-equals-zero (scan==src) yields 1 with
 * out untouched. Every main-loop round refreshes one private cursor slot from
 * the HELD backwards scan and adopts only the utf8_extract_char result for the
 * 0x0a test, never the helper-advanced cursor (str r10,[sp,#4]/bl ec30c-ec310).
 * The non-LF step walks continuation bytes back to a lead/ASCII boundary with
 * no internal source lower bound and no UTF validity guard (ec31c..ec35c).
 * On LF the original strncmps scan+1 against pool 0x334b50 "#line " for 6:
 * failure bumps lineCount then shares that step (ec38c-ec39c); success reads
 * byte scan+7, resolves the imported _ctype_ POINTER cell through GOT 0x3ed988
 * exactly once (ldr [pc,r3]/ldr [r3] ec3bc-ec3c0) and classifies with
 * table[unsignedByte + 1] & 8 — not isspace/isdigit semantics. The filename
 * terminator writes through the LIVE re-read *out with the ANDS zero result,
 * never the held malloc pointer (str r0,[r9]/ldr r3,[r9] ec440-ec450).
 * gap: record writer/ownership, utf8_extract_char body/source language, _ctype_
 * provider, real LR, fault-domain unwind and concurrency are unproved; no
 * original or rebuilt execution backed this recovery, static source/ABI only.
 */
namespace {
typedef uint32_t AliasWord __attribute__((may_alias));

/* All traversal addresses stay plain uint32_t words so the +8 stride follows the
 * original u32 wrap instead of inventing C++ pointer arithmetic outside objects. */
inline uint32_t addressOf(const volatile void *place) {
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(const_cast<volatile void *>(place)));
}
inline uint32_t wordAt(uint32_t address) {
    return *reinterpret_cast<const volatile AliasWord *>(static_cast<uintptr_t>(address));
}
inline uint32_t byteAt(uint32_t address) {
    return *reinterpret_cast<const volatile uint8_t *>(static_cast<uintptr_t>(address));
}
template <typename Type> inline Type *pointerAt(uint32_t address) {
    return reinterpret_cast<Type *>(static_cast<uintptr_t>(address));
}
inline char *volatile *outSlotAt(uint32_t address) {
    return reinterpret_cast<char *volatile *>(static_cast<uintptr_t>(address));
}
} // namespace

VMDebugInfo *VM::DebugInfo(VMBuffer *buffer, int pc) {
    if (buffer == nullptr) {
        return nullptr; // cmp/beq ec144-ec14c: null buffer returns null, no field touched
    }
    /* Non-null order is literal: bufferSize+0x04 first (ldr ec150), then the code
     * pointer word at +0x10 (ldr ec154) — the code field itself is read even when
     * the LOGICAL >>3 count later proves zero. */
    const uint32_t bufferSizeBits = wordAt(addressOf(buffer) + 0x04u);
    const uint32_t codeAddress = wordAt(addressOf(buffer) + 0x10u);
    const uint32_t recordCount = bufferSizeBits >> 3u; // lsrs ec158: logical, never signed/ASR
    if (recordCount == 0u) {
        return pointerAt<VMDebugInfo>(recordCount); // mov r0,r4 ec198: zero count -> null
    }
    const int32_t firstKey = static_cast<int32_t>(wordAt(codeAddress)); // ldr [r2] ec160
    if (static_cast<int32_t>(pc) < firstKey) {
        return nullptr; // blt ec168: PC below the first signed key -> null
    }
    /* ldr r12,[r2,#8]! then mov r0,r2: held previous pointer, advanced key-only. */
    uint32_t heldPrevious = codeAddress;
    for (uint32_t index = 1u; index != recordCount; ++index) {
        const uint32_t nextAddress = heldPrevious + 8u;
        if (static_cast<int32_t>(wordAt(nextAddress)) > static_cast<int32_t>(pc)) {
            return pointerAt<VMDebugInfo>(heldPrevious); // bgt ec17c: previous record
        }
        heldPrevious = nextAddress;
    }
    return pointerAt<VMDebugInfo>(heldPrevious); // count exhausted: last record
}

int VM::DebugLineNumber(VMDebugInfo *info, const char *src, char **out) {
    if (info == nullptr) {
        return -1; // mvn ec46c: null info short-circuits before any strlen
    }
    /* Literal order: bl strlen ec2d4 completes, then sourceByteOffset+0x04 is
     * read live at ec2d8; the clamp comparison is signed on both sides. */
    const uint32_t lengthBits = static_cast<uint32_t>(strlen(src));
    uint32_t offset = wordAt(addressOf(info) + 0x04u);
    if (static_cast<int32_t>(lengthBits) < static_cast<int32_t>(offset)) {
        offset = lengthBits - 1u; // sublt ec2e0: shortening only
    }
    if (static_cast<int32_t>(offset) < 0) {
        return -1; // blt ec2e8
    }
    const uint32_t source = addressOf(src);
    uint32_t scan = source + offset; // add ec2ec: u32 wrap address
    if (scan == source) {
        return 1; // beq ec2f4: zero offset returns 1, out never touched
    }
    uint32_t lineCount = 0u; // r7 stays unsigned through ec364/ec390
    const char *cursor; // one private slot, lifetime spans every loop iteration
    for (;;) {
        /* str r10,[sp,#4]/mov r0,r6 ec308-ec30c: one private cursor slot is
         * re-seeded from the held scan each round; only the returned code point
         * is consumed, the helper-advanced cursor is dropped. */
        cursor = pointerAt<const char>(scan);
        bool ordinaryNewline = false;
        if (utf8_extract_char(&cursor) == 10u) {
            if (strncmp(pointerAt<const char>(scan + 1u), "#line ", 6u) != 0) {
                ordinaryNewline = true; // ec38c byte read precedes ec390 increment below
            } else {
                const uint32_t fileStart = scan + 7u; // add r5 ec3b4
                const uint32_t firstByte = byteAt(fileStart); // ldrb [r10,#7] ec3b8
                /* ldr [pc,r3]/ldr [r3] ec3bc-ec3c0: the GOT 0x3ed988 slot yields
                 * the imported _ctype_ POINTER cell address; the table pointer it
                 * holds is taken exactly once and kept across both scan loops. */
                const uint32_t ctypeAddress = addressOf(g_DebugCTypeTable);
                const auto inClass8 = [ctypeAddress](uint32_t byteValue) {
                    /* table[unsignedByte + 1] & 8, per add/ldrb/tst ec3c4-ec3f0. */
                    return (byteAt(ctypeAddress + byteValue + 1u) & 8u) != 0u;
                };
                uint32_t nameEnd;
                if (inClass8(firstByte)) {
                    nameEnd = fileStart; // bne ec464: mov r4,r5, empty-name shape
                } else {
                    nameEnd = scan + 8u; // ec3d4: first blank from scan+8
                    while (!inClass8(byteAt(nameEnd))) {
                        nameEnd = nameEnd + 1u; // ec3d8-ec3f0, no NUL/bound guard
                    }
                }
                uint32_t digits = nameEnd + 1u; // ec3f4
                while (inClass8(byteAt(digits))) {
                    digits = digits + 1u; // ands r6 ec410: leaves the zero below
                }
                const int32_t parsed = atoi(pointerAt<const char>(digits)); // bl atoi ec418
                const uint32_t result = static_cast<uint32_t>(parsed) + lineCount - 1u;
                if (out == nullptr) {
                    return static_cast<int>(result); // beq ec428: direct return
                }
                const uint32_t nameLength = nameEnd - fileStart; // rsb ec42c
                void *const allocation = malloc(static_cast<size_t>(nameLength) + 1u);
                *outSlotAt(addressOf(out)) = pointerAt<char>(addressOf(allocation)); // ec440
                memcpy(allocation, pointerAt<const char>(fileStart),
                       static_cast<size_t>(nameLength)); // ec444: return is NOT consumed
                /* ldr r3,[r9] ec448: LIVE re-read of *out, not the held allocation. */
                const uint32_t liveOut = wordAt(addressOf(out));
                *reinterpret_cast<volatile uint8_t *>(static_cast<uintptr_t>(
                    liveOut + nameLength)) = 0u; // ec450, r6==0; unconditional even if memcpy returned0
                return static_cast<int>(result);
            }
        }
        const uint32_t previousByte = byteAt(scan - 1u); // ldr/tst ec31c-ec324/ec38c-ec398
        if (ordinaryNewline) {
            ++lineCount; // ec38c read first, ec390 increment second
        }
        if ((previousByte & 0x80u) == 0u || (previousByte & 0xC0u) == 0xC0u) {
            scan = scan - 1u; // beq ec3a0: ASCII or lead steps by one
        } else {
            uint32_t walk = scan - 2u; // continuation byte: hunt backwards (ec338)
            for (;;) {
                const uint32_t walkByte = byteAt(walk); // ldrb [r3],#-1 ec34c
                if ((walkByte & 0x80u) == 0u || (walkByte & 0xC0u) == 0xC0u) {
                    scan = walk; // lead/ASCII stop position
                    break;
                }
                walk = walk - 1u; // no source lower bound here, per original
            }
        }
        if (scan == source) {
            ++lineCount; // cmp/beq ec35c-ec364 / ec3a4-ec3ac
            return static_cast<int>(lineCount);
        }
        /* unequal to source: next main-loop round (bne ec308). */
    }
}
