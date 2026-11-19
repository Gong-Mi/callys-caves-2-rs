#ifndef CALLY_RECOVERED_CCODE_HPP
#define CALLY_RECOVERED_CCODE_HPP

#include "../vm_buffer/vm_buffer.hpp"

/* Recovered C++ interface for CCode, not original source spelling.
 * tier: bytecode_anchored; original ARMv7 ELF SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Constructor 0xcefc8..0xcf324, destructor 0xce2b8..0xce36c,
 * deleting destructor 0xce36c..0xce388, GetText 0xcf470..0xcf478.
 * gap: unknown state arrays and option names retain descriptive labels;
 * this is the observed object prefix through +0x78, not a claim that every
 * CCode member or its whole runtime has been recovered. All pointer/offset
 * arithmetic below is for the original 32-bit address space, not arm64.
 */
struct YYCCodeEntry {
    const char *name;                                  // original first word
    uint32_t word04;                                  // not read by CCode(int,bool)
};
struct LLVMVariablesPrefix {
    uint8_t unknown00[0x1c];
    YYCCodeEntry *codeEntries;                         // g_pLLVMVars[+0x1c], 8-byte entries
};

class CCode {
public:
    CCode(int codeIndex, bool selectKindTwo);           // 0xcefc8, C1/C2 aliases
    virtual ~CCode();                                 // 0xce2b8; D0 0xce36c
    const char *GetText();                            // 0xcf470, reads +0x10

    // The C++ ABI supplies the vptr at +0x00.
    CCode *nextCode;                                  // +0x04: g_pFirstCode registry link
    int32_t kind;                                     // +0x08: bool parameter selects 1 or 2
    uint8_t byte0c;                                   // +0x0c: constructor writes 1
    uint8_t padding0d[3];                             // not initialised by constructor
    const char *text;                                 // +0x10: GetText's result
    uint8_t state14[0x2c];                            // +0x14: first original memset range
    uint8_t state40[0x10];                            // +0x40: second original memset range
    VMBuffer *buffer;                                 // +0x50: primary bytecode, deleted virtually
    VMBuffer *debugBuffer;                            // +0x54: optional DEBUG view, NOT deleted here
    const char *initialText;                          // +0x58: captured text for VM::Exec
    const char *name;                                 // +0x5c: borrowed CODE/YYC name
    int32_t index;                                    // +0x60: original constructor index
    YYCCodeEntry *compiledEntry;                      // +0x64: YYC record, else null
    uint8_t skipRegistryRemoval;                      // +0x68: nonzero skips unlink AND decrement
    uint8_t padding69[3];                             // not initialised by constructor
    uint32_t recordOffset;                            // +0x6c: CODE[+0x10], new layout only
    uint32_t localsCount;                             // +0x70: CODE[+8]; DoCallScript -> YYAllocLocalStackNew
    uint32_t argumentCount;                           // +0x74: low 13 bits in new CODE layout
    uint32_t codeFlags;                               // +0x78: CODE[+0x0a] >> 13; bit2 read by DoCallScript
};

/* Original relocation-backed globals. These are supplied by the runner,
 * not replaced here with synthetic values or captured WAD snapshots.
 * WAD/DEBUG table elements are uint32 offsets, NOT native host pointers.
 */
extern uint8_t g_fYYC;
extern LLVMVariablesPrefix *g_pLLVMVars;
extern int32_t g_nYYCode;
extern uint32_t *g_ppYYCode;
extern uint32_t *g_ppDebugScript;
extern uint8_t *g_pDEBUGBaseAddress;
extern uint8_t g_subFunctionsOption;
extern uint32_t *g_ppDebugInfo;
extern CCode *g_pFirstCode;
extern uint32_t g_TotalCodeBlocks;

void *operator new(size_t);                           // original internal 0x27c524
extern "C" void *memset(void *, int, size_t);          // libc import, two distinct constructor calls

#endif
