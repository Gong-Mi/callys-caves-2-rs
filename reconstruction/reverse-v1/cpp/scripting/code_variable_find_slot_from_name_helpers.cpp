/* Two C++ name-slot helpers recovered from the pinned ARMv7 ELF.
 * Image SHA256: 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Entries: _Z39Code_Variable_Find_Slot_From_Local_NamePKc @0xd1f74 (224B,
 * body SHA256 5975070a4e732a83169d488259363c39d2327a344551393180c6c80bdc70417d)
 * and _Z40Code_Variable_Find_Slot_From_Global_NamePKc @0xd2054 (108B,
 * body SHA256 b78799f4458a3ed0e54c566f6a7e4a5450c29b9b31a3b2824b6bf3a77d3f426e).
 * tier: bytecode_anchored; this is a static C++ candidate, not execution or
 * runtime-equivalence evidence. Unknown data fields remain raw +0xNN accesses.
 * Open dependencies: the map-object contents reached through g_instanceVarLookup,
 * the g_VarNamesGlobal table producer/state, and both specialized CHashMap helpers.
 */
#include "script_runtime.hpp"

#include <string.h>

/* These declarations preserve the original C++ specialization names. The
 * target library's murmurhash body remains a separate, not-yet-restored
 * internal dependency; it is declared only to preserve this provider's tail
 * call contract.
 */
template <typename Key>
uint32_t CHashMapCalculateHash(Key value);

template <typename Key>
bool CHashMapCompareKeys(Key left, Key right);

uint32_t murmurhash(const char *value, uint32_t length, uint32_t seed);

template <>
__attribute__((noinline)) uint32_t CHashMapCalculateHash<const char *>(const char *value) {
    /* @0x1eeb90 calls strlen@plt; @0x1eeba4 tail-branches to murmurhash.
     * The third argument is the literal zero loaded at @0x1eeb94.
     */
    const uint32_t length = static_cast<uint32_t>(strlen(value));
    return murmurhash(value, length, 0u);
}

template <>
__attribute__((noinline)) bool CHashMapCompareKeys<const char *>(const char *left, const char *right) {
    /* @0x1eebac calls strcmp@plt; RSBS + MOVLO at @0x1eebb0..b4 maps
     * exactly strcmp(...) == 0 to the returned bool.
     */
    return strcmp(left, right) == 0;
}

/* The relocation targets are data symbols in the pinned image. They are raw
 * storage declarations here; no complete source-level structures are claimed.
 */
extern "C" unsigned char g_instanceVarLookup[]; // 0x47a178, 4B object
extern "C" unsigned char g_VarNamesGlobal[];    // 0x47a19c, 16B object

namespace {
constexpr uint32_t kSignBit = 0x80000000u;
constexpr uint32_t kNoSlot = 0xffffffffu;

/* ARM CMP/B<cond> signed ordering, expressed on the original 32-bit words. */
inline bool arm_signed_less(uint32_t left, uint32_t right) {
    return (left ^ kSignBit) < (right ^ kSignBit);
}

inline uint32_t entry_byte_offset(uint32_t index) {
    /* The observed table stride is 3 words (0x0c), with 32-bit wrap. */
    return ((index << 1) + index) << 2;
}
} // namespace

int Code_Variable_Find_Slot_From_Local_Name(const char *name) {
    /* @0xd1f74 ldr r3,[pc,#0xd4]; @0xd1f7c ldr r3,[pc,r3]:
     * pool 0xd2050 -> R_ARM_RELATIVE slot 0x3edbac -> g_instanceVarLookup
     * (0x47a178). @0xd1f84 loads that cell's word; no null guard follows.
     */
    const uint32_t lookupCell = object_wire::address(g_instanceVarLookup);
    const uint32_t mapAddress = object_wire::read(lookupCell, 0x00u);

    /* @0xd1f88 is the real const-char-pointer hash specialization. */
    const uint32_t hash = CHashMapCalculateHash<const char *>(name);

    /* @0xd1f8c/+0x08 and @0xd1f90/+0x10 are the observed raw map words. */
    uint32_t mask = object_wire::read(mapAddress, 0x08u);
    const uint32_t initialTable = object_wire::read(mapAddress, 0x10u);
    const uint32_t normalizedHash = hash & 0x7fffffffu; // BIC at 0xd1f94
    uint32_t slot = normalizedHash & mask;              // AND at 0xd1f98
    uint32_t recordAddress = initialTable + entry_byte_offset(slot);
    uint32_t recordHash = object_wire::read(recordAddress, 0x08u);
    if (recordHash == 0u) {
        return -1; // 0xd1fac..0xd1fb0 -> 0xd2024
    }

    uint32_t attempts = 0u; // 0xd1fb4
    for (;;) {
        if (normalizedHash == recordHash) { // CMP at 0xd2000
            const uint32_t keyAddress = object_wire::read(recordAddress, 0x00u);
            const char *const storedName = reinterpret_cast<const char *>(
                static_cast<uintptr_t>(keyAddress));
            /* @0xd2010 calls the real CHashMapCompareKeys<const char*> body.
             * The original treats a nonzero result as a key match.
             */
            if (CHashMapCompareKeys<const char *>(storedName, name)) {
                /* CMN r4,#1 and CMN r4,#4 are preserved as the two raw-word
                 * wrap guards at 0xd202c/0xd2040.
                 */
                if (slot == kNoSlot) {
                    return -1;
                }
                const uint32_t liveTable = object_wire::read(mapAddress, 0x10u);
                const uint32_t resultRecord = liveTable + entry_byte_offset(slot);
                if (resultRecord == 0xfffffffcu) {
                    return -1;
                }
                /* The matched record's +0x04 word is returned unchanged. */
                return static_cast<int32_t>(object_wire::read(resultRecord, 0x04u));
            }

            /* Only the key-compare miss path reloads the +0x08 word (0xd201c). */
            mask = object_wire::read(mapAddress, 0x08u);
        }

        /* @0xd1fbc..0xd1fd4: use the raw +0x00 map word, then compute the
         * wrapped distance from the current bucket's masked hash.
         */
        const uint32_t bucketBase = object_wire::read(mapAddress, 0x00u);
        const uint32_t maskedRecordHash = recordHash & mask;
        const uint32_t nextSlot = (slot + 1u) & mask;
        const uint32_t distance =
            (bucketBase + slot - maskedRecordHash) & mask;
        const uint32_t previousAttempts = attempts;
        slot = nextSlot;      // r4 updated at 0xd1fcc
        attempts += 1u;        // r6 updated at 0xd1fe4
        if (arm_signed_less(distance, previousAttempts)) { // BLT at 0xd1fe8
            return -1;
        }

        /* @0xd1fec reloads +0x10 for each next probe; +0x08 is read at +8. */
        const uint32_t liveTable = object_wire::read(mapAddress, 0x10u);
        recordAddress = liveTable + entry_byte_offset(slot);
        recordHash = object_wire::read(recordAddress, 0x08u);
        if (recordHash == 0u) { // 0xd1ff8..0xd1ffc
            return -1;
        }
    }
}

int Code_Variable_Find_Slot_From_Global_Name(const char *name) {
    /* @0xd2054 ldr r3,[pc,#0x60]; @0xd205c ldr r3,[pc,r3]:
     * pool 0xd20bc -> R_ARM_RELATIVE slot 0x3edba4 -> g_VarNamesGlobal
     * (0x47a19c, 16B object).
     */
    const uint32_t tableAddress = object_wire::address(g_VarNamesGlobal);
    const uint32_t count = object_wire::read(tableAddress, 0x04u); // +0x04
    if (!arm_signed_less(0u, count)) { // CMP/BLE at 0xd2068..0xd206c
        return -1;
    }

    const uint32_t bound = object_wire::read(tableAddress, 0x00u); // +0x00
    const uint32_t namesAddress = object_wire::read(tableAddress, 0x0cu); // +0x0c
    uint32_t index = 0u; // 0xd2074
    for (;;) {
        /* The signed index-vs-+0x00 test gates only the names-array read. */
        if (arm_signed_less(index, bound)) { // CMP/BGE at 0xd207c..0xd2084
            const uint32_t nameAddress =
                object_wire::read(namesAddress, index << 2); // LDR at 0xd2088
            if (nameAddress != 0u) { // CMP/BEQ at 0xd208c..0xd2090
                const char *const candidate = reinterpret_cast<const char *>(
                    static_cast<uintptr_t>(nameAddress));
                if (strcmp(name, candidate) == 0) { // direct BL to strcmp@plt
                    return static_cast<int>(index); // 0xd2098..0xd20b8
                }
            }
        }

        ++index; // ADD at 0xd20a0
        if (index == count) { // CMP/BNE at 0xd20a4..0xd20a8
            return -1;
        }
    }
}
