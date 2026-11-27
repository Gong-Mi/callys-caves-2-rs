#ifndef CALLY_VM_DEBUG_INFO_HPP
#define CALLY_VM_DEBUG_INFO_HPP
#include "vm_exec.hpp"
#include "../memory_manager/memory_internal.hpp"

/* tier: bytecode_anchored; DebugInfo0xec144/100B and
 * DebugLineNumber0xec2b8/452B; pinned ARMv7 SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Eight-byte debug records follow bufferSize LOGICAL >>3 and +8 search
 * stride; both PC keys and source offsets are interpreted signed by users.
 * This recovers the observed record, not the whole debug/compiler system.
 * gap: record writer/ownership, utf8_extract_char body/source language,
 * imported ctype table producer, LR/fault/unwind and concurrency unproved.
 */
struct VMDebugInfo {
    int32_t instructionByteOffset; // +0, signed PC comparison
    int32_t sourceByteOffset;      // +4, read AFTER strlen
};
static_assert(sizeof(VMDebugInfo) == 8, "DebugInfo record stride8");
static_assert(offsetof(VMDebugInfo, sourceByteOffset) == 4, "source byte offset+4");

/* Original R_ARM_GLOB_DAT21 at GOT3ed988 names imported _ctype_. The
 * instruction then reads the table POINTER from that imported pointer cell;
 * it does not treat the GOT slot as the table. Hold it during marker loops.
 */
extern const uint8_t *volatile g_DebugCTypeTable __asm__("_ctype_");
extern "C" {
size_t strlen(const char *);
int strncmp(const char *, const char *, size_t);
int atoi(const char *);
uint32_t utf8_extract_char(const char **); // real C-linkage helper10fb38; not a UTF8 replacement
}
#endif
