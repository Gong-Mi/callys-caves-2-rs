/*
 * variable_misc.h — the variable-family remainders of libyoyo ARMv7.
 *
 * Entries (pinned image SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a):
 *
 *   _Z20Variable_Global_Initv                       @0x001f3354
 *       0x001f3354..0x001f33bc, 0x68 = 104 B: 24 instructions + 2 literal-pool
 *       words at 0x001f33b4 / 0x001f33b8.  void.
 *
 *   _Z24DoVariableInstanceExistsP9CInstancePKc      @0x001178b8
 *       0x001178b8..0x0011793c, 0x84 = 132 B: 33 instructions, NO literal pool
 *       (the next function starts at 0x0011793c).  int.
 *
 *   _Z22Variable_GetName_ScopePKcii                 @0x000d2228
 *       0x000d2228..0x000d24d4, 0x2ac = 684 B: 158 instructions + 13
 *       literal-pool words at 0x000d24a0..0x000d24d0.  const char *.
 *
 *   _Z20Variable_BuiltIn_AddPKcPFbP9CInstanceiP6RValueES6_b @0x001f4da8
 *       0x001f4da8..0x001f5050, 0x2a8 = 680 B: 164 instructions + 6
 *       literal-pool words at 0x001f5038..0x001f504c.  void.
 *
 * All four are reached only through the library's own .got, so every global
 * below is declared with the shape the instructions actually address (a byte,
 * a 4-byte scalar, a 16-byte CArray-style struct, or a pointer variable — the
 * difference matters: `ldr r3,[r8,r3]` then `ldrb r3,[r3]` means the cell is
 * the address of the byte, while `ldr r3,[r8,r3]` then `ldr r3,[r3]` means the
 * cell holds a pointer).
 *
 * Callee status, per function (this is the whole point of the tier note):
 *
 *   variable_global_init          MemoryManager::ReAlloc 0x27cedc   unrecovered
 *   do_variable_instance_exists   Variable_BuiltIn_Find   0x1f3a5c   unrecovered
 *                                 Code_Variable_Find_Slot_From_Name 0xd21ec
 *                                       RECOVERED -> c/variable_names, linked
 *                                       for real on both arms
 *                                 Variable_GetValue_Direct 0x1f3b8c
 *                                       RECOVERED -> c/variable_direct, linked
 *                                       for real on both arms
 *   variable_getname_scope        Variable_GetName 0xd1d04          unrecovered
 *                                 Script_Find_Parent 0x1e06dc       unrecovered
 *                                 strcmp / snprintf @plt           libc, answered
 *                                 identically on both arms
 *   variable_builtin_add          YYStrDup 0xdb8c8                  unrecovered
 *                                 MemoryManager::{Alloc,Free}      unrecovered
 *                                 CHashMapCalculateHash 0x1eeb88   unrecovered
 *                                 CHashMap::Insert 0xd261c         unrecovered
 *                                 memset@plt / ShowMessage 0xc4b0c libc / message
 *
 * A green differential proves these four bodies' dispatch, field offsets,
 * pointer normalisation, table walks and return plumbing.  It does not prove
 * any stubbed callee, the two linked callees' own callees (GET_RValue 0xd13bc,
 * InternalGetYYVar 0x196a70, the builtin getter fn, and the two name-lookup
 * tail targets), and it is not device equivalence.
 */
#ifndef VARIABLE_MISC_H
#define VARIABLE_MISC_H

#include <stdint.h>

/* ══ Variable_Global_Init ══════════════════════════════════════════════════
 * globdecl is the only object it writes: dynsym OBJECT 0x00753100, size 8 =
 * { int32_t cap; char *data; }.  The GOT cell 0x003f0e30 is R_ARM_RELATIVE
 * holding the addend 0x00753100, so one dereference reaches the struct.
 */
typedef struct {
    int32_t cap;     /* +0x0  0x1f3394 str r12, [r4]        */
    char   *data;    /* +0x4  0x1f3398 str r0,  [r4, #0x4]  */
} vm_globdecl;

#define VM_GLOBDECL_CAP   10000     /* 0x1f3368 movw r1, #0x2710 */
#define VM_GLOBDECL_LINE  106       /* 0x1f3370 mov r3, #106     */
#define VM_CARRAY_FILE \
    "jni/../jni/yoyo/../../../Files/Platform/cARRAY_STRUCTURE.h"  /* 0x34d23c */

extern vm_globdecl g_globdecl;      /* 0x00753100 */

/* MemoryManager::ReAlloc(void *p, uint32 size, char const *file, int line,
 * bool zero) @0x27cedc.  The 5th argument is on the stack (0x1f337c str r5,[sp]).
 * UNRECOVERED: identical stub on both arms. */
void *MemoryManager_ReAlloc(void *p, uint32_t size, const char *file,
                            int line, int zero);

void Variable_Global_Init(void);

/* ══ DoVariableInstanceExists ══════════════════════════════════════════════
 * int DoVariableInstanceExists(CInstance *inst, const char *name)
 *   id = Variable_BuiltIn_Find(name);          key < 0 -> not a builtin
 *   if (id < 0) { slot = Find_Slot_From_Name(inst, name);
 *                 if (slot < 0) return 0;
 *                 id = slot + 100000; }
 *   Variable_GetValue_Direct(inst, id, INT_MIN, &v);   v zeroed first
 *   return (v.tag & 0x00ffffff) != 0x00ffffff;
 */
typedef struct {
    uint32_t w[4];                  /* 16 B; the tag is the 4th word */
} vm_rvalue;

/* UNRECOVERED: identical stub on both arms. */
int Variable_BuiltIn_Find(const char *name);         /* 0x1f3a5c */

/* RECOVERED, linked for real: c/variable_names/src/find_slot_from_name.c
 * (0xd21ec, 13 instructions) and c/variable_direct/src/variable_direct.c
 * (0x1f3b8c, 39 instructions).  Both bodies therefore run on both arms. */
int  Code_Variable_Find_Slot_From_Name(void *self, const char *name);
int  Variable_GetValue_Direct(void *obj, int varid, int arrindex, void *out);

/* The two .bss objects the linked Find_Slot_From_Name reads (see
 * c/variable_names/src/variable_names.h): 0x00544be0 is a POINTER variable,
 * 0x0047f295 a byte.  Staged by this fixture, never by the body. */
extern void          *g_varname_host;
extern unsigned char  g_varname_mode;
/* Its two unrecovered tail targets. */
int Code_Variable_Find_Slot_From_Local_Name(const char *name);   /* 0xd1f74 */
int Code_Variable_Find_Slot_From_Global_Name(const char *name);  /* 0xd2054 */

/* CInstance fields Variable_GetValue_Direct addresses (0x04 slot table,
 * 0x24 "has instance variables" flag) plus the 16 B slot stride. */
#define VM_INST_VAR_TABLE 0x04u
#define VM_INST_VAR_FLAG  0x24u
#define VM_SLOT_STRIDE    16
#define VM_VARID_BASE     100000
#define VM_ARR_SCALAR     (-2147483647 - 1)     /* 0x80000000, "no index" */
#define VM_RV_UNSET       0x00ffffffu           /* the "unresolved" tag */

/* The linked Variable_GetValue_Direct's own unrecovered callees, and the GOT
 * slot holding the builtin-variable table base (0x003edc40 -> 0x0075310c). */
extern void *const g_builtin_var_table_slot;
int   GET_RValue(void *dst, void *src, int arrindex);        /* 0xd13bc  */
void *InternalGetYYVar(void *self, int slot);                /* 0x196a70 */

int DoVariableInstanceExists(void *inst, const char *name);

/* ══ the shared failure byte ═══════════════════════════════════════════════
 * 0x0075505c, dynsym OBJECT size 1.  None of the four bodies in this module
 * contains a single store to it; the fixture stages it before every call and
 * reads it back after, so "touched" is decided by the bytes, not by the card.
 */
extern unsigned char g_fail_flag;

/* ══ Variable_GetName_Scope ════════════════════════════════════════════════
 * const char *Variable_GetName_Scope(const char *name, int type, int id)
 *
 * type is a negative enumeration (-5 global, -1 instance, -7/-12 function
 * locals, -9/-11 and any type > 100000 folded into the instance domain).
 * id < 100000 means "builtin variable number", which this body refuses.
 */
#define VM_TYPE_GLOBAL   (-5)
#define VM_TYPE_INSTANCE (-1)
#define VM_TYPE_LOCAL_FN (-7)
#define VM_TYPE_LOCAL_12 (-12)

/* CArray-style name table, 16 B: the body reads +0 (size), +4 (count) and
 * +0xc (data).  +8 is never read by any of the four bodies. */
typedef struct {
    int32_t  size;      /* +0x0  0x0d23bc ldr r2, [r3]        */
    int32_t  count;     /* +0x4  0x0d23b0 ldr r2, [r3, #0x4]  */
    int32_t  unused;    /* +0x8  never read                    */
    char   **data;      /* +0xc  0x0d23c4 ldrlt r3, [r3, #0xc] */
} vm_nametable;

/* CHashMap<const char*, int, 7>: 20 B header + 12 B entries. */
typedef struct {
    char    *key;       /* +0x0 */
    int32_t  value;     /* +0x4 */
    uint32_t hash;      /* +0x8  0 means empty; <= 0 is skipped by the scan */
} vm_mapentry;

typedef struct {
    int32_t      cap;        /* +0x00 */
    int32_t      count;      /* +0x04 */
    int32_t      mask;       /* +0x08 */
    int32_t      threshold;  /* +0x0c */
    vm_mapentry *entries;    /* +0x10 */
} vm_map;

#define VM_MAP_ENTRY_STRIDE 12      /* add r3,#12 / add r2,r2,lsl#1 + lsl#2 */
#define VM_MAP_LOAD_FACTOR  0.6f    /* 0x3f19999a, pool 0x001f5038 / 0x000d24a0 family */

/* Function-name-keyed local table element, 12 B.  The key is the SCRIPT or
 * FUNCTION name, not the variable name; names[slot] is read with no bound
 * check against `count` (card open 1). */
typedef struct {
    char   *name;       /* +0x0  0x0d22c0 ldr r0, [r4]     */
    int32_t count;      /* +0x4  read by New_Code_Variable_Find, never here */
    char  **names;      /* +0x8  0x0d22d4 ldr r3, [r4, #0x8] */
} vm_fntable;

extern unsigned char   g_subFunctionsOption;   /* 0x00544b5c, byte  (gate 1) */
extern unsigned char   g_fJSGarbageCollection; /* 0x0047f295, byte  (gate 2) */
extern int32_t         g_numFunctionsForLocalVars;    /* 0x0047a1ac, 4 B   */
extern vm_fntable    **g_localVariableNamesForFunctions;
                                                      /* 0x0047a1b0, POINTER */
extern vm_nametable    g_VarNamesGlobal;       /* 0x0047a19c, 16 B struct    */
extern vm_nametable    g_VarNamesInstance;     /* 0x0047a18c, 16 B struct    */
extern vm_map          *g_instanceVarLookup;   /* 0x0047a178, POINTER        */

/* rodata 0x332760 and 0x332774, byte-checked by the harness. */
#define VM_MSG_UNKNOWN_VARIABLE "<unknown variable>"
#define VM_FMT_SCRIPT           "gml_Script_%s"
#define VM_SNPRINTF_CAP         4096        /* 0x0d2420 mov r1, #4096 */
#define VM_SCRIPT_NAME_OFF      0x14        /* 0x0d241c ldr r3, [r0, #0x14] */

/* UNRECOVERED: identical stubs on both arms. */
const char *Variable_GetName(int id);                 /* 0x0d1d04 */
void       *Script_Find_Parent(const char *name);     /* 0x1e06dc */
int snprintf(char *buf, unsigned int n, const char *fmt, ...);  /* @plt */
int strcmp(const char *a, const char *b);                       /* @plt */

const char *Variable_GetName_Scope(const char *name, int type, int id);

/* ══ Variable_BuiltIn_Add ══════════════════════════════════════════════════
 * void Variable_BuiltIn_Add(char const *name,
 *                           bool (*getter)(CInstance*, int, RValue*),
 *                           bool (*setter)(CInstance*, int, RValue*),
 *                           bool flag)          <-- DEAD: 0x1f4da8 overwrites
 *                                                   r3 before it is ever read
 * The table is FIXED at 500 entries of 16 B (dynsym size 8000):
 *   +0x0 char *name (owned strdup)  +0x4 getter  +0x8 setter
 *   +0xc uint8 writable == (setter != NULL)
 */
typedef int (*vm_getter_fn)(void *inst, int arrindex, vm_rvalue *out);

typedef struct {
    char        *name;      /* +0x0  0x1f4e38 str r0, [r4, r10, lsl #4] */
    vm_getter_fn getter;    /* +0x4  0x1f4e40 stmib r3, {r5, r9}        */
    vm_getter_fn setter;    /* +0x8  ... second register of the stmib    */
    unsigned char writable; /* +0xc  0x1f4e3c strb r1, [r3, #0xc]      */
    unsigned char pad[3];   /* +0xd  untouched, there to make 16        */
} vm_builtin_entry;

#define VM_BUILTIN_CAP   500        /* 0x1f4dcc cmp r3, #500 (equality)    */
#define VM_BUILTIN_LINE  70         /* 0x1f4f40 mov r2, #70                */
#define VM_MEMMGR_FILE \
    "jni/../jni/yoyo/../../../Platform/MemoryManager.h"          /* 0x331038 */
#define VM_MSG_TOO_MANY   "INTERNAL ERROR: Adding too many variables" /* 0x352854 */

extern int32_t          g_builtin_numb;        /* 0x00753108, count (not cap) */
extern vm_builtin_entry g_builtin_variables[VM_BUILTIN_CAP];  /* 0x0075310c */
/* 0x007530fc is a POINTER variable: 0x1f4e20 ldr r8, [r3] */
extern vm_map          *g_builtinVarLookup;

/* UNRECOVERED: identical stubs on both arms. */
char     *YYStrDup(const char *s);                            /* 0x0db8c8 */
void      MemoryManager_Free(const void *p);                  /* 0x27c2d0 */
void     *MemoryManager_Alloc(uint32_t bytes, const char *file,
                              int line, int zero);            /* 0x27ce78 */
uint32_t  CHashMap_CalculateHash(const char *s);              /* 0x1eeb88 */
void      CHashMap_Insert(vm_map *m, char *key, int32_t value);/* 0x0d261c */
void      ShowMessage(const char *s);                         /* 0x0c4b0c */
void     *memset(void *d, int c, unsigned int n);             /* @plt    */

void Variable_BuiltIn_Add(const char *name, vm_getter_fn getter,
                          vm_getter_fn setter, int flag);

#endif /* VARIABLE_MISC_H */
