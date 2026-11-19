#include "ccode.hpp"

/* CCode::CCode(int,bool), C1/C2 @0xcefc8..0xcf324.
 * tier: bytecode_anchored; original ARMv7 ELF SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * gap: global/table producers, invalid/null-record fault domains and C++
 * exception unwinding are not certified. Names are descriptive, not recovered
 * source spellings. This is not a host-native WAD loader or an arm64 port.
 */
namespace {
// Pool cf2f4 + ADD cf02c and pool cf304 + ADD cf0fc both resolve to 0x32eb3e.
const char emptyCodeText[] = "";
typedef uint32_t CodeWord __attribute__((may_alias));
typedef uint16_t CodeHalf __attribute__((may_alias));

uint8_t *offsetBytes(const void *base, uint32_t offset) {
    return reinterpret_cast<uint8_t *>(reinterpret_cast<uintptr_t>(base) + offset);
}
uint32_t readWord(const void *base, uint32_t offset = 0) {
    return *reinterpret_cast<const volatile CodeWord *>(offsetBytes(base, offset));
}
uint16_t readHalf(const void *base, uint32_t offset) {
    return *reinterpret_cast<const volatile CodeHalf *>(offsetBytes(base, offset));
}
} // namespace

CCode::CCode(int codeIndex, bool selectKindTwo) {
    volatile CCode *state = this;
    const char *capturedText;

    // 0xcefec..0xcf00c; no initialisation of padding, +0x74 or +0x78 here.
    state->index = codeIndex;
    state->skipRegistryRemoval = 0;
    state->buffer = nullptr;
    state->debugBuffer = nullptr;
    state->compiledEntry = nullptr;
    state->recordOffset = 0;
    state->localsCount = 0;

    if (g_fYYC != 0) {
        // 0xcf020..0xcf04c. YYC has no index guard and no VMBuffer allocation.
        YYCCodeEntry *const table = g_pLLVMVars->codeEntries;
        YYCCodeEntry *const entry = reinterpret_cast<YYCCodeEntry *>(
            offsetBytes(table, static_cast<uint32_t>(codeIndex) << 3));
        const char *const entryName = reinterpret_cast<const char *>(
            static_cast<uintptr_t>(readWord(entry))); // 0xcf040 precedes the stores
        state->compiledEntry = entry;
        state->text = emptyCodeText;
        state->name = entryName;
        capturedText = emptyCodeText;
    } else if (codeIndex < 0 || codeIndex >= g_nYYCode) {
        // 0xcf0d4..0xcf108. Do not turn this path into a failed constructor.
        state->name = nullptr;
        state->text = emptyCodeText;
        capturedText = emptyCodeText;
    } else {
        // 0xcf10c..0xcf144: default-init, not value-init; publish before loading CODE.
        VMBuffer *const primary = new VMBuffer;
        volatile VMBuffer *const primaryState = primary;
        primaryState->code = nullptr;
        primaryState->handlers = nullptr;
        primaryState->offsetToSlot = nullptr;
        state->buffer = primary;

        const uint32_t tableOffset = static_cast<uint32_t>(codeIndex) << 2;
        const uint32_t codeOffset = readWord(g_ppYYCode, tableOffset);
        // 0xcf150..0xcf168: zero offset remains null, then is still dereferenced.
        // This preserves the original invalid-input path rather than inventing a guard.
        const uint8_t *const record = codeOffset != 0
            ? offsetBytes(g_pWADBaseAddress, codeOffset) : nullptr;
        const uint32_t nameOffset = readWord(record);
        state->name = nameOffset != 0
            ? reinterpret_cast<const char *>(offsetBytes(g_pWADBaseAddress, nameOffset))
            : nullptr;
        state->text = nullptr;

        // 0xcf194..0xcf1c8 / 0xcf2d0..0xcf2e0: two DEBUG-relative relocations.
        uint32_t *const debugScripts = g_ppDebugScript;
        if (debugScripts != nullptr) {
            const uint32_t scriptOffset = readWord(debugScripts, tableOffset);
            const uint8_t *const script = scriptOffset != 0
                ? offsetBytes(g_pDEBUGBaseAddress, scriptOffset) : nullptr;
            const uint32_t textOffset = readWord(script);
            state->text = textOffset != 0
                ? reinterpret_cast<const char *>(offsetBytes(g_pDEBUGBaseAddress, textOffset))
                : nullptr;
        }

        // 0xcf1d0 precedes the sub-functions option byte read at 0xcf1d8.
        const uint32_t byteLength = readWord(record, 4);
        if (g_subFunctionsOption != 0) {
            // 0xcf1e4..0xcf20c: preserve flags -> locals -> extra -> relative load order.
            const uint16_t packedArguments = readHalf(record, 0x0a);
            const uint16_t localSlots = readHalf(record, 0x08);
            const uint32_t extraOffset = readWord(record, 0x10);
            const uint32_t relativeBytecode = readWord(record, 0x0c);
            primaryState->bufferSize = static_cast<int32_t>(byteLength);
            primaryState->metadata08 = localSlots;
            primaryState->metadata0c = packedArguments;
            primaryState->code = offsetBytes(offsetBytes(record, 12), relativeBytecode);
            state->localsCount = localSlots;
            state->recordOffset = extraOffset;
            state->argumentCount = packedArguments & 0x1fffu;
            state->codeFlags = packedArguments >> 13;
        } else {
            // 0xcf2a4..0xcf2cc -> shared 0xcf218. The halfwords overlap inline
            // bytecode in this older layout; do not reinterpret them as new metadata.
            const uint16_t word08 = readHalf(record, 0x08);
            const uint16_t word0a = readHalf(record, 0x0a);
            primaryState->bufferSize = static_cast<int32_t>(byteLength);
            primaryState->metadata08 = word08;
            primaryState->metadata0c = word0a;
            primaryState->code = offsetBytes(record, 8);
            state->localsCount = 0;
            state->recordOffset = 0;
            state->argumentCount = 0;
            state->codeFlags = word0a >> 13;
        }

        uint32_t *const debugInfo = g_ppDebugInfo; // 0xcf22c
        if (debugInfo == nullptr) {
            capturedText = state->text;           // 0xcf234
        } else {
            // 0xcf23c..0xcf29c. The view is held across new[], but text is read
            // AFTER the allocation and BEFORE publishing debugBuffer (+0x54).
            const uint32_t infoOffset = readWord(debugInfo, tableOffset);
            const uint8_t *const info = infoOffset != 0
                ? offsetBytes(g_pDEBUGBaseAddress, infoOffset) : nullptr;
            uint8_t *const infoWords = offsetBytes(info, 4); // zero -> literal address 4
            VMBuffer *const debugView = new VMBuffer;
            const uint32_t infoBytes = readWord(info) << 2;
            volatile VMBuffer *const debugState = debugView;
            debugState->handlers = nullptr;
            debugState->offsetToSlot = nullptr;
            capturedText = state->text;           // 0xcf290
            state->debugBuffer = debugView;       // 0xcf294
            debugState->bufferSize = static_cast<int32_t>(infoBytes);
            debugState->code = infoWords;
        }
    }

    // 0xcf050..0xcf084: captured pointer, byte, kind, then TWO distinct calls.
    state->initialText = capturedText;
    state->byte0c = 1;
    state->kind = selectKindTwo ? 2 : 1;
    memset(this->state14, 0, 0x2c);
    memset(this->state40, 0, 0x10);

    // 0xcf088..0xcf0c4: registration uses the post-call member, not the parameter.
    if (state->index >= 0) {
        CCode *volatile &registryHead = g_pFirstCode;
        uint32_t volatile &blockCount = g_TotalCodeBlocks;
        CCode *const oldHead = registryHead;
        registryHead = this;
        state->nextCode = oldHead;
        const uint32_t previousCount = blockCount;
        blockCount = previousCount + 1u;
    }
}
