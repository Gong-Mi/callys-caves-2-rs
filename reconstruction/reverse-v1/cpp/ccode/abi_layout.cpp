#include "ccode.hpp"

// This is an observed ARM32 object-prefix check, not a source-identity proof.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#define CCODE_FIELD(member, offset) \
    static_assert(__builtin_offsetof(CCode, member) == offset, #member)
CCODE_FIELD(nextCode, 0x04);
CCODE_FIELD(kind, 0x08);
CCODE_FIELD(byte0c, 0x0c);
CCODE_FIELD(text, 0x10);
CCODE_FIELD(state14, 0x14);
CCODE_FIELD(state40, 0x40);
CCODE_FIELD(buffer, 0x50);
CCODE_FIELD(debugBuffer, 0x54);
CCODE_FIELD(initialText, 0x58);
CCODE_FIELD(name, 0x5c);
CCODE_FIELD(index, 0x60);
CCODE_FIELD(compiledEntry, 0x64);
CCODE_FIELD(skipRegistryRemoval, 0x68);
CCODE_FIELD(recordOffset, 0x6c);
CCODE_FIELD(localsCount, 0x70);
CCODE_FIELD(argumentCount, 0x74);
CCODE_FIELD(codeFlags, 0x78);
#undef CCODE_FIELD
static_assert(sizeof(CCode) == 0x7c, "observed CCode prefix");
#pragma clang diagnostic pop
static_assert(sizeof(YYCCodeEntry) == 8, "YYC code-entry stride");
static_assert(offsetof(LLVMVariablesPrefix, codeEntries) == 0x1c, "LLVM prefix code table");
