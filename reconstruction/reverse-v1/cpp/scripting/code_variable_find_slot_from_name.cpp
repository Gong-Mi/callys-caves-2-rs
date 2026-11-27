/* Code_Variable_Find_Slot_From_Name, recovered from the pinned ARMv7 ELF.
 * tier: bytecode_anchored; original libyoyo-armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Anchor: _Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc at
 * 0xd21ec..0xd2228 (60 bytes, body SHA256
 * a2d09e2a8e6779b606c53050f0bd9fc58bf329cddaa897df8e33b53f1962c3e5).
 * 0xd21ec/0xd21f0 load the R_ARM_RELATIVE slot 0x3edbbc, which resolves to
 * the 4-byte g_pGlobal cell at 0x544be0; 0xd21f4 loads its pointer word.
 * After the compare at 0xd21f8, the original tests the one-byte
 * g_fJSGarbageCollection cell at 0x47f295 only when self equals g_pGlobal.
 * The two helper edges are direct tail B transfers at 0xd2204/0xd221c.
 * Gap: both name-helper implementations remain unresolved; this is a static
 * reconstruction only, with no link or execution of either artifact.
 */
#include "script_runtime.hpp"
#include "../object_base/gc_object_lifecycle.hpp"
#include "../vm_exec/vm_entry_runtime.hpp"

/* These names have no declarations in the recovered headers yet. Their
 * exact one-argument signatures follow the original C++ ABI symbols:
 * _Z39Code_Variable_Find_Slot_From_Local_NamePKc and
 * _Z40Code_Variable_Find_Slot_From_Global_NamePKc.
 * They intentionally remain external dependencies here.
 */
int Code_Variable_Find_Slot_From_Local_Name(const char *);
int Code_Variable_Find_Slot_From_Global_Name(const char *);

/* Original static routing rule (0xd21ec..0xd2228): use the local-name helper
 * unless self is the object referenced by g_pGlobal and GC mode is zero.
 * Both helper results pass through unchanged; name is forwarded unchanged.
 */
int Code_Variable_Find_Slot_From_Name(YYObjectBase *self, const char *name) {
    const YYObjectBase *const globalObject = reinterpret_cast<YYObjectBase *>(
        static_cast<uintptr_t>(gc_object_state::globalWord));
    if (self != globalObject || g_fJSGarbageCollection != 0) {
        return Code_Variable_Find_Slot_From_Local_Name(name);
    }
    return Code_Variable_Find_Slot_From_Global_Name(name);
}
