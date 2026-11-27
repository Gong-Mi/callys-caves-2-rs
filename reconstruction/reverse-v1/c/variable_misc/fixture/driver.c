/*
 * driver.c — the C arm of the Variable_Misc differential.
 *
 * Built freestanding for armv7a-none-eabi and run under qemu-arm, so a pointer
 * is 4 bytes: the 16 B name-table struct really has size@+0 / count@+4 /
 * data@+0xc, the hash-map entry really is 12 B with hash@+8, the builtin table
 * entry really is 16 B with writable@+0xc, and `lsl #4` / `lsl #2` in the
 * original mean what the translations say they mean.  A host build moves every
 * one of those by 4 and quietly stops testing them.
 *
 * It is a *fixture*, not a reconstruction: it stages the .bss objects the four
 * bodies reach through the .got, provides identical stubs for every unrecovered
 * callee, and calls the translated body once per case, printing a record stream
 * that harness/var_misc_diff.py reproduces from the original bytes.
 *
 * Case line (stdin), 8 integers: fn p0 p1 p2 p3 p4 p5 p6
 *
 *   fn=1  Variable_Global_Init
 *         p0 = byte the ReAlloc stub's block is prefilled with (0 or 170)
 *         p1 = 1 -> g_globdecl.data staged to the old block, 0 -> NULL
 *         p2 = failure byte 0x75505c staged value (0/1)
 *   fn=2  DoVariableInstanceExists
 *         p0 = builtin-find answer (-1 = not builtin, else the builtin id)
 *         p1 = slot-table path mode (0 slot lookup misses, 1 slot=3, 2 slot=7
 *              -> id 100007, 3 slot=0, 4 table==NULL -> InternalGetYYVar)
 *         p2 = RValue tag staged in the slot/builtin the getter copies out
 *         p3 = name tag (0 "alpha" 1 "" 2 "beta" 3 NULL)
 *         p4 = 1 -> stage the builtin table entry so a hit actually reads it
 *         p5 = failure byte 0x75505c staged value (0/1)
 *         p6 = 1 -> stage inst+0x24 (the "has instance variables" flag) to 0
 *   fn=3  Variable_GetName_Scope
 *         p0 = name tag  0 "scrA" 1 "other" 2 "" 3 NULL 4 "gml_Script_Par"
 *         p1 = type      (-5 -1 -7 -12 -9 -11 100001 0 3 INT_MIN ...)
 *         p2 = id
 *         p3 = gate 1 (g_subFunctionsOption) 0/1
 *         p4 = gate 2 (g_fJSGarbageCollection) 0/1
 *         p5 = table layout 0 empty / 1 consistent / 2 count>size + parent entry
 *         p6 = Script_Find_Parent 0 NULL / 1 a CScript whose +0x14 is a name
 *   fn=4  Variable_BuiltIn_Add
 *         p0 = name tag (0..5: three contents, each at two addresses)
 *         p1 = getter present (0/1)
 *         p2 = setter present (0/1)
 *         p3 = the DEAD 4th argument (0/1)
 *         p4 = pre-stage 0 fresh / 1 count=1 with table[1].name set (Free path)
 *         p5 = map mode 0 as initialised / 1 threshold=-1 (grow on insert) with
 *              3 occupied old entries / 2 threshold=-1, empty old table
 *         p6 = 1 -> drop the map pointer to 0 (never dereferenced before the
 *              500 check, so this must not matter)
 *
 * Record stream (stdout):
 *   CASE <fn> <p0..p6>
 *   RET <i32|void|CLS:hex>          fn=3 returns a pointer, normalised by
 *                                   content ("UNK", "NULL", "PTR:<bytes>")
 *   CALLS <n>
 *   C <tok> <tok> ...               one ordered callee-log entry per line
 *   EXT <key> <value>               per-function observed state, no spaces
 *   FLAG <0|1>                      the 0x75505c byte after the call
 *
 * No raw pointer is ever printed: every pointer becomes content (a string, or
 * "1"/"0" for "is this the block the stub returned").
 */
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

void *memcpy(void *d, const void *s, size_t n);
void *memset(void *d, int c, size_t n);

#include "variable_misc.h"

#define MARK 0x5c
#define UNUSED __attribute__((unused))

/* ── raw syscalls (no libc in a freestanding armv7 image) ───────────────── */
static long sys3(long nr, long a, long b, long c)
{
    register long r7 __asm__("r7") = nr;
    register long r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b;
    register long r2 __asm__("r2") = c;
    __asm__ volatile("svc #0" : "+r"(r0)
                     : "r"(r7), "r"(r1), "r"(r2) : "memory");
    return r0;
}
static void out(const char *s, uint32_t n) { sys3(4, 1, (long)(uintptr_t)s, n); }
__attribute__((noreturn)) static void quit(int code)
{
    sys3(1, code, 0, 0);
    for (;;) { }
}

static void print_i(int v);
static void UNUSED print_s(const char *s)
{
    uint32_t n = 0;
    while (s[n])
        n++;
    out(s, n);
}
static void UNUSED print_hex(const char *p, int n)
{
    static const char hex[] = "0123456789abcdef";
    for (int i = 0; i < n; i++) {
        char two[2];
        unsigned char b = (unsigned char)p[i];
        two[0] = hex[(b >> 4) & 0xf];
        two[1] = hex[b & 0xf];
        out(two, 2);
    }
}
static long read_all(char *buf, long cap)
{
    long total = 0;
    while (total < cap) {
        long n = sys3(3, 0, (long)(uintptr_t)(buf + total), cap - total);
        if (n <= 0)
            break;
        total += n;
    }
    return total;
}

uintptr_t __stack_chk_guard = 0xc2331111u;
void __stack_chk_fail(void) { quit(3); }

void *memcpy(void *d, const void *s, size_t n)
{
    unsigned char *a = d; const unsigned char *b = s;
    while (n--) *a++ = *b++;
    return d;
}
void *memset(void *d, int c, size_t n)
{
    unsigned char *a = d;
    while (n--) *a++ = (unsigned char)c;
    return d;
}

static void UNUSED wr32(void *p, uint32_t w) { memcpy(p, &w, 4); }
static uint32_t UNUSED rd32(const void *p) { uint32_t w; memcpy(&w, p, 4); return w; }
static int slen(const char *p)
{
    int n = 0;
    if (p == 0)
        return -1;
    while (p[n] && n < 60)
        n++;
    return n;
}
static int seq(const char *a, const char *b)
{
    int i = 0;
    if (a == 0 || b == 0)
        return a == b;
    while (a[i] && b[i] && a[i] == b[i])
        i++;
    return (a[i] == 0 && b[i] == 0);
}

/* ── the .bss objects ──────────────────────────────────────────────────── */
vm_globdecl g_globdecl;
unsigned char g_fail_flag;
void *g_varname_host;
unsigned char g_varname_mode;
int32_t g_builtin_numb;
vm_builtin_entry g_builtin_variables[VM_BUILTIN_CAP];
vm_map *g_builtinVarLookup;
unsigned char g_subFunctionsOption;
unsigned char g_fJSGarbageCollection;
int32_t g_numFunctionsForLocalVars;
vm_fntable **g_localVariableNamesForFunctions;
vm_nametable g_VarNamesGlobal;
vm_nametable g_VarNamesInstance;
vm_map *g_instanceVarLookup;

/* GET_RValue / InternalGetYYVar / the builtin getter all live one level below
 * the linked Variable_GetValue_Direct; stub log entries are printed instead of
 * kept, because the record stream is the only channel. */
static void UNUSED log_tok(const char *t) { out("C ", 2); print_s(t); out("\n", 1); }

/* ── the string arena every dumped name lives in (YYStrDup stand-in) ────── */
static char arena[4096];
static unsigned arena_used;
static char *UNUSED arena_put(const char *s)
{
    int n = slen(s);
    char *p;
    if (arena_used + (unsigned)n + 1u > sizeof arena)
        quit(5);
    p = arena + arena_used;
    for (int i = 0; i <= n; i++)
        p[i] = s[i];
    arena_used += ((unsigned)n + 1u + 7u) & ~7u;
    return p;
}
static int UNUSED in_arena(const void *p)
{
    return (const char *)p >= arena && (const char *)p < arena + sizeof arena;
}

/* ══ fn=1 Variable_Global_Init staging ══════════════════════════════════ */
static char realloc_block[VM_GLOBDECL_CAP];
static char old_block[VM_GLOBDECL_CAP];
static void *stage_old_data;

void *MemoryManager_ReAlloc(void *p, uint32_t size, const char *file,
                            int line, int zero)
{
    out("C Q ", 4);
    print_i((int)size); out(" ", 1);
    print_i(line); out(" ", 1);
    print_i(zero); out(" ", 1);
    print_i(p == stage_old_data && stage_old_data != 0); out(" ", 1);
    print_i(seq(file, VM_CARRAY_FILE)); out("\n", 1);
    return realloc_block;
}

/* The GOT slot Variable_GetValue_Direct loads through (0x003edc40 -> the
 * builtin table), and the four names a fn=2 case can pass. */
void *const g_builtin_var_table_slot = g_builtin_variables;

static const char *name_by_tag(int tag)
{
    static const char alpha[] = "alpha";
    static const char beta[] = "beta";
    static const char empty[] = "";
    switch (tag) {
    case 0: return alpha;
    case 1: return empty;
    case 2: return beta;
    default: return 0;                 /* NULL */
    }
}

/* ══ fn=2 DoVariableInstanceExists staging ══════════════════════════════ */
static unsigned char inst_obj[0x180];
static unsigned char slot_table[8 * VM_SLOT_STRIDE];
static vm_rvalue g_staged_rv;          /* what a getter copies into `out` */
static int g_builtin_find_ret;
static int g_slot_answer;
static int g_ncalls;

/* "<len> <text>", len -1 for NULL, so NULL and "" stay different records */
static void print_name(const char *p)
{
    int n = slen(p);
    out(" ", 1); print_i(n); out(" ", 1);
    if (n <= 0) { out("-", 1); return; }   /* NULL and "" stay distinguishable */
    for (int i = 0; i < n; i++) {
        char c = p[i];
        if (c < 0x20 || c > 0x7e) c = '?';
        if (c == ' ') c = '_';             /* the record is space-separated */
        out(&c, 1);
    }
}
static int rv_zero_at(const void *p)
{
    const unsigned char *b = p;
    for (int i = 0; i < 16; i++)
        if (b[i]) return 0;
    return 1;
}
static int slot_index(const void *src)
{
    const unsigned char *s = src;
    const unsigned char *base = slot_table;
    if (s < base || s >= base + sizeof slot_table)
        return 99;
    return (int)((s - base) / VM_SLOT_STRIDE);
}

int Variable_BuiltIn_Find(const char *name)
{
    g_ncalls++;
    out("C B", 3); print_name(name); out("\n", 1);
    return g_builtin_find_ret;
}
int Code_Variable_Find_Slot_From_Local_Name(const char *name)
{
    g_ncalls++;
    out("C L", 3); print_name(name); out("\n", 1);
    return g_slot_answer;
}
int Code_Variable_Find_Slot_From_Global_Name(const char *name)
{
    g_ncalls++;
    out("C G", 3); print_name(name); out("\n", 1);
    return g_slot_answer;
}
int GET_RValue(void *dst, void *src, int arrindex)
{
    g_ncalls++;
    out("C V S ", 6); print_i(slot_index(src)); out(" ", 1);
    print_i(arrindex); out(" ", 1); print_i(rv_zero_at(dst)); out("\n", 1);
    memcpy(dst, src, 16);
    return 1;
}
void *InternalGetYYVar(void *self, int slot)
{
    (void)self;
    g_ncalls++;
    out("C I ", 4); print_i(slot); out("\n", 1);
    /* a dedicated slot so the following GET_RValue can still be named */
    return slot_table + 3 * VM_SLOT_STRIDE;
}
static int bvar_getter(void *obj, int arrindex, vm_rvalue *outv)
{
    (void)obj;
    g_ncalls++;
    out("C V B ", 6); print_i(arrindex); out(" ", 1);
    print_i(rv_zero_at(outv)); out("\n", 1);
    memcpy(outv, &g_staged_rv, 16);
    return 1;
}

static void run_f2(int p0, int p1, int p2, int p3, int p4, int p5, int p6)
{
    const char *name;
    int r;

    (void)p5;
    memset(inst_obj, 0, sizeof inst_obj);
    memset(slot_table, 0, sizeof slot_table);
    /* p1 == 4 walks Variable_GetValue_Direct's NULL-table (lazy) path */
    wr32(inst_obj + VM_INST_VAR_TABLE,
         p1 == 4 ? 0u : (uint32_t)(uintptr_t)slot_table);
    inst_obj[VM_INST_VAR_FLAG] = (unsigned char)(p6 ? 0 : 1);
    for (int k = 0; k < 8; k++) {
        wr32(slot_table + k * VM_SLOT_STRIDE + 0x0, 0x11111111u + (uint32_t)k);
        wr32(slot_table + k * VM_SLOT_STRIDE + 0xc, (uint32_t)p2);
    }
    memset(&g_staged_rv, 0, sizeof g_staged_rv);
    g_staged_rv.w[0] = 0x22222222u;
    g_staged_rv.w[3] = (uint32_t)p2;

    /* the builtin table is shared with fn=4; stage exactly one live entry.
     * builtin_numb is NOT read by this body - p4 only moves it so the record
     * shows that. */
    memset(g_builtin_variables, 0, sizeof g_builtin_variables);
    if (p0 >= 0 && p0 < VM_BUILTIN_CAP) {
        g_builtin_variables[p0].name = (char *)"bv";
        g_builtin_variables[p0].getter = bvar_getter;
        g_builtin_numb = p4 ? p0 + 1 : 0;
    } else {
        g_builtin_numb = p4 ? 1 : 0;
    }
    g_builtin_find_ret = p0;
    g_slot_answer = (p1 == 1 || p1 == 4) ? 3
                  : (p1 == 2) ? 7 : (p1 == 3) ? 0 : -1;
    g_varname_host = 0;            /* so the linked body takes the local arm */
    g_varname_mode = 0;
    g_ncalls = 0;
    name = name_by_tag(p3);

    r = DoVariableInstanceExists(inst_obj, name);
    out("RET ", 4); print_i(r); out("\n", 1);
}

/* ══ fn=3 Variable_GetName_Scope staging ════════════════════════════════
 * Three layouts, applied by both arms, chosen by the case:
 *   0  every table empty (global 0/0, instance 0/0, map count 0, no local)
 *   1  consistent: global 8/5, instance 8/3, map count 3 with one negative
 *      hash (must be skipped) and one zero slot, local 1 entry "scrA" whose
 *      names array has 8 live slots behind a count of 4
 *   2  inconsistent on purpose: global size 4 / count 6, instance 4/2, map
 *      count 2, local 2 entries with "gml_Script_Par" for the parent rescan
 */
static char *g_glob_slots[8];
static char *g_inst_slots[8];
static char *g_fn0_names[8];
static char *g_fn1_names[8];
static vm_fntable g_fn_arr[2];
static vm_fntable *g_fn_arr_ptr;
static vm_mapentry g_scope_entries[8];
static vm_map g_scope_map;
static unsigned char g_script_obj[0x20];
static char g_vn_buf[24];
static int g_parent_on;
static int g_scanned_n;

vm_fntable **g_localVariableNamesForFunctions = &g_fn_arr_ptr;
vm_map *g_instanceVarLookup = &g_scope_map;
int32_t g_numFunctionsForLocalVars;
unsigned char g_subFunctionsOption;
unsigned char g_fJSGarbageCollection;
vm_nametable g_VarNamesGlobal;
vm_nametable g_VarNamesInstance;

static const char *scope_name_by_tag(int tag)
{
    switch (tag) {
    case 0: return "scrA";
    case 1: return "other";
    case 2: return "";
    case 3: return 0;
    case 4: return "gml_Script_Par";
    default: return 0;
    }
}

static void stage_scope(int layout)
{
    static char *g0[] = { "g0", "g1", 0, "g3", "g4", 0, 0, 0 };
    static char *i0[] = { "i0", 0, "i2", 0, 0, 0, 0, 0 };
    static char *l0[] = { "l0", "l1", "l2", "l3", "l4", "l5", "l6", "l7" };
    static char *p0[] = { "p0", "p1", "p2", "p3", "p4", "p5", "p6", "p7" };

    for (int k = 0; k < 8; k++) {
        g_glob_slots[k] = 0;
        g_inst_slots[k] = 0;
        g_fn0_names[k] = 0;
        g_fn1_names[k] = 0;
    }
    memset(g_scope_entries, 0, sizeof g_scope_entries);
    memset(&g_scope_map, 0, sizeof g_scope_map);
    g_scope_map.cap = 8;
    g_scope_map.mask = 7;
    g_scope_map.threshold = 4;
    g_scope_map.entries = g_scope_entries;
    memset(&g_fn_arr, 0, sizeof g_fn_arr);
    memset(&g_VarNamesGlobal, 0, sizeof g_VarNamesGlobal);
    memset(&g_VarNamesInstance, 0, sizeof g_VarNamesInstance);
    g_numFunctionsForLocalVars = 0;
    g_fn_arr_ptr = 0;

    if (layout == 0)
        return;

    for (int k = 0; k < 8; k++) {
        g_fn0_names[k] = l0[k];
        g_fn1_names[k] = p0[k];
    }

    if (layout == 1) {
        for (int k = 0; k < 8; k++)
            g_glob_slots[k] = g0[k];
        for (int k = 0; k < 8; k++)
            g_inst_slots[k] = i0[k];
        g_VarNamesGlobal.size = 8; g_VarNamesGlobal.count = 5;
        g_VarNamesGlobal.data = g_glob_slots;
        g_VarNamesInstance.size = 8; g_VarNamesInstance.count = 3;
        g_VarNamesInstance.data = g_inst_slots;
        /* count == the number of hash>0 entries, so the reverse scan's
         * "i-th occupied entry" walk always terminates inside the array; the
         * gaps at idx0 and the negative hash at idx2 are the two skip paths. */
        g_scope_map.count = 2;
        g_scope_entries[1].key = (char *)"m5";
        g_scope_entries[1].value = 5;
        g_scope_entries[1].hash = 1;
        g_scope_entries[2].key = (char *)"m6";
        g_scope_entries[2].value = 6;
        g_scope_entries[2].hash = (uint32_t)-3;   /* <= 0: skipped by the scan */
        g_scope_entries[3].key = (char *)"m7";
        g_scope_entries[3].value = 7;
        g_scope_entries[3].hash = 9;
        g_fn_arr[0].name = (char *)"scrA";
        g_fn_arr[0].count = 4;
        g_fn_arr[0].names = g_fn0_names;
        g_numFunctionsForLocalVars = 1;
        g_fn_arr_ptr = g_fn_arr;
    } else {
        /* data[5] is live on purpose: size is 4, so a dropped size gate would
         * answer "g5" where the original answers NULL */
        static char *g2[] = { "g0", "g1", "g2", "g3", 0, "g5", 0, 0 };
        static char *i2[] = { "i0", 0, 0, 0, 0, 0, 0, 0 };
        for (int k = 0; k < 8; k++) {
            g_glob_slots[k] = g2[k];
            g_inst_slots[k] = i2[k];
        }
        g_VarNamesGlobal.size = 4; g_VarNamesGlobal.count = 6;
        g_VarNamesGlobal.data = g_glob_slots;
        g_VarNamesInstance.size = 4; g_VarNamesInstance.count = 2;
        g_VarNamesInstance.data = g_inst_slots;
        g_scope_map.count = 2;
        g_scope_entries[0].key = (char *)"m5";
        g_scope_entries[0].value = 5;
        g_scope_entries[0].hash = 1;
        g_scope_entries[2].key = (char *)"m7";
        g_scope_entries[2].value = 7;
        g_scope_entries[2].hash = 3;
        g_fn_arr[0].name = (char *)"scrA";
        g_fn_arr[0].count = 4;
        g_fn_arr[0].names = g_fn0_names;
        g_fn_arr[1].name = (char *)"gml_Script_Par";
        g_fn_arr[1].count = 2;
        g_fn_arr[1].names = g_fn1_names;
        g_numFunctionsForLocalVars = 2;
        g_fn_arr_ptr = g_fn_arr;
    }
}

/* the four callees fn=3 reaches ---------------------------------------- */
const char *Variable_GetName(int id)
{
    int i = 0, neg = 0;
    unsigned int u;
    g_ncalls++;
    g_vn_buf[i++] = 'v';
    g_vn_buf[i++] = 'n';
    u = (unsigned int)id;
    if (id < 0) { neg = 1; u = (unsigned int)(-(long)id); }
    char tmp[12];
    int t = 0;
    do { tmp[t++] = (char)('0' + (u % 10u)); u /= 10u; } while (u);
    if (neg) g_vn_buf[i++] = '-';
    while (t)
        g_vn_buf[i++] = tmp[--t];
    g_vn_buf[i] = 0;
    out("C N ", 4); print_i(id); out("\n", 1);
    return g_vn_buf;
}

void *Script_Find_Parent(const char *name)
{
    g_ncalls++;
    out("C P", 3); print_name(name); out("\n", 1);
    return g_parent_on ? (void *)g_script_obj : 0;
}

int snprintf(char *buf, unsigned int n, const char *fmt, ...)
{
    va_list ap;
    unsigned int k = 0;
    va_start(ap, fmt);
    for (const char *f = fmt; *f; f++) {
        if (*f == '%' && f[1] == 's') {
            const char *s = va_arg(ap, const char *);
            f++;
            if (s == 0)
                s = "(null)";
            while (*s) {
                if (k + 1 < n)
                    buf[k] = *s;
                k++;
                s++;
            }
        } else {
            if (k + 1 < n)
                buf[k] = *f;
            k++;
        }
    }
    va_end(ap);
    if (n)
        buf[k < n ? k : n - 1] = 0;
    out("C S ", 4); print_i((int)k); out(" ", 1);
    {   /* the formatted bytes, or '-' when the result is empty */
        int m = slen(buf);
        if (m <= 0) {
            out("-", 1);
        } else {
            for (int i = 0; i < m; i++) {
                char c = buf[i];
                if (c < 0x20 || c > 0x7e) c = '?';
                out(&c, 1);
            }
        }
    }
    out("\n", 1);
    return (int)k;
}

int strcmp(const char *a, const char *b)
{
    g_scanned_n++;
    if (a == 0 || b == 0)
        return a == b ? 0 : (a == 0 ? -1 : 1);
    while (*a && *a == *b) {
        a++;
        b++;
    }
    return (int)(unsigned char)*a - (int)(unsigned char)*b;
}

static void print_ret_ptr(const char *p)
{
    if (p == 0) {
        out("RET NULL\n", 9);
        return;
    }
    if (seq(p, VM_MSG_UNKNOWN_VARIABLE)) {
        out("RET UNK\n", 8);
        return;
    }
    out("RET PTR:", 8);
    print_hex(p, slen(p));
    out("\n", 1);
}

static void run_f3(int p0, int p1, int p2, int p3, int p4, int p5, int p6)
{
    const char *r;

    stage_scope(p5);
    g_parent_on = p6 & 1;          /* p6 bit0: Script_Find_Parent answers */
    memset(g_script_obj, 0, sizeof g_script_obj);
    wr32(g_script_obj + VM_SCRIPT_NAME_OFF, (uint32_t)(uintptr_t)"Par");
    g_subFunctionsOption = (unsigned char)p3;
    g_fJSGarbageCollection = (unsigned char)p4;
    g_ncalls = 0;
    g_scanned_n = 0;
    r = Variable_GetName_Scope(scope_name_by_tag(p0), p1, p2);
    print_ret_ptr(r);
    out("EXT SCANS ", 10); print_i(g_scanned_n); out("\n", 1);
}

/* ══ fn=4 Variable_BuiltIn_Add staging ══════════════════════════════════
 * The table is the real 500x16 B object; the map is 128 buckets with
 * threshold 76, exactly as INITIALIZE_Variable_BuiltIn builds it (0x1ffbe4..).
 * p4 chooses the pre-stage, p5 whether the insert must double the map.
 */
static vm_map f4_map;
static vm_mapentry f4_entries[128];
static unsigned char f4_alloc_mem[8192];
static unsigned f4_alloc_used;
static char f4_arena[1024];
static unsigned f4_arena_used;

static const char f4_n0[] = "alpha";
static const char f4_n1[] = "beta";
static const char f4_n2[] = "gamma";
static const char f4_n3[] = "alpha";        /* same bytes, other address */
static const char f4_n4[] = "beta";
static const char f4_n5[] = "gamma";

static const char *f4_name(int tag)
{
    switch (tag) {
    case 0: return f4_n0;
    case 1: return f4_n1;
    case 2: return f4_n2;
    case 3: return f4_n3;
    case 4: return f4_n4;
    default: return f4_n5;
    }
}

/* the same bytes at the other address: tags 0..2 and 3..5 are pairs */
static const char *f4_pair(int tag)
{
    return f4_name(tag < 3 ? tag + 3 : tag - 3);
}

char *YYStrDup(const char *s)
{
    char *p;
    g_ncalls++;
    out("C D", 3); print_name(s); out("\n", 1);
    p = f4_arena + f4_arena_used;
    {
        int n = slen(s);
        for (int i = 0; i <= n; i++)
            p[i] = s[i];
        f4_arena_used += ((unsigned)n + 1u + 7u) & ~7u;
        if (f4_arena_used > sizeof f4_arena)
            quit(7);
    }
    return p;
}

void MemoryManager_Free(const void *p)
{
    g_ncalls++;
    out("C F ", 4);
    if ((const char *)p >= f4_arena
            && (const char *)p < f4_arena + sizeof f4_arena) {
        out("n", 1);
        print_name((const char *)p);
    } else {
        out("b", 1);
    }
    out("\n", 1);
}

void *MemoryManager_Alloc(uint32_t bytes, const char *file, int line, int zero)
{
    void *p = f4_alloc_mem + f4_alloc_used;
    g_ncalls++;
    out("C A ", 4); print_i((int)bytes); out(" ", 1); print_i(line); out(" ", 1);
    print_i(zero); out(" ", 1); print_i(seq(file, VM_MEMMGR_FILE)); out("\n", 1);
    f4_alloc_used += (bytes + 7u) & ~7u;
    if (f4_alloc_used > sizeof f4_alloc_mem)
        quit(8);
    if (zero)
        memset(p, 0, bytes);
    return p;
}

uint32_t CHashMap_CalculateHash(const char *s)
{
    uint32_t h = 2166136261u;
    while (*s) {
        h ^= (unsigned char)*s++;
        h *= 16777619u;
    }
    return h;
}

void CHashMap_Insert(vm_map *m, char *key, int32_t value)
{
    uint32_t h = CHashMap_CalculateHash(key) & 0x7fffffffu;
    uint32_t mask = (uint32_t)m->mask;
    uint32_t idx = h & mask;
    for (;;) {
        vm_mapentry *e = &m->entries[idx];
        if (e->hash == 0) {
            e->key = key;
            e->value = value;
            e->hash = h;
            m->count = m->count + 1;
            break;
        }
        idx = (idx + 1) & mask;
    }
    g_ncalls++;
    out("C I", 3); print_name(key); out(" ", 1); print_i(value); out("\n", 1);
}

void ShowMessage(const char *s)
{
    g_ncalls++;
    out("C M", 3); print_name(s); out("\n", 1);
}

static int bvar_setter(void *obj, int arrindex, vm_rvalue *outv)
{
    (void)obj; (void)arrindex;
    if (outv)
        outv->w[3] = 0;
    return 0;
}

static void f4_dump(void)
{
    int nonempty = 0;

    out("RET void\n", 9);
    print_s("EXT COUNT "); print_i(g_builtin_numb); out("\n", 1);
    print_s("EXT MAP ");
    print_i(f4_map.cap); out(" ", 1);
    print_i(f4_map.count); out(" ", 1);
    print_i(f4_map.mask); out(" ", 1);
    print_i(f4_map.threshold); out("\n", 1);
    for (int i = 0; i < g_builtin_numb && i < VM_BUILTIN_CAP; i++)
        if (g_builtin_variables[i].name)
            nonempty++;
    print_s("EXT ENONEMPTY "); print_i(nonempty); out("\n", 1);
    for (int i = 0; i < g_builtin_numb && i < VM_BUILTIN_CAP; i++) {
        if (!g_builtin_variables[i].name)
            continue;
        print_s("EXT E."); print_i(i); out(" n", 2);
        print_name(g_builtin_variables[i].name);
        out(" ", 1);
        print_i(g_builtin_variables[i].getter != 0); out(" ", 1);
        print_i(g_builtin_variables[i].setter != 0); out(" ", 1);
        print_i(g_builtin_variables[i].writable); out("\n", 1);
    }
    for (int i = 0; i < f4_map.cap; i++) {
        static const char hx[] = "0123456789abcdef";
        uint32_t h = f4_map.entries[i].hash;
        if (h == 0)
            continue;
        print_s("EXT M."); print_i(i); out(" ", 1);
        /* most-significant nibble first, so the text matches "%08x" */
        for (int k = 28; k >= 0; k -= 4) {
            char c = hx[(h >> k) & 0xf];
            out(&c, 1);
        }
        out(" n", 2);
        print_name(f4_map.entries[i].key); out(" ", 1);
        print_i(f4_map.entries[i].value); out("\n", 1);
    }
}

/* staging strings go into the same arena YYStrDup uses, but are not calls:
 * the record must only contain what the body under judgement actually did. */
static char *f4_stage_str(const char *s)
{
    char *p = f4_arena + f4_arena_used;
    int n = slen(s);
    for (int i = 0; i <= n; i++)
        p[i] = s[i];
    f4_arena_used += ((unsigned)n + 1u + 7u) & ~7u;
    if (f4_arena_used > sizeof f4_arena)
        quit(9);
    return p;
}

static void run_f4(int p0, int p1, int p2, int p3, int p4, int p5, int p6)
{
    const char *nm;

    (void)p6;
    f4_arena_used = 0;
    f4_alloc_used = 0;
    memset(g_builtin_variables, 0, sizeof g_builtin_variables);
    memset(f4_entries, 0, sizeof f4_entries);
    memset(&f4_map, 0, sizeof f4_map);
    f4_map.cap = 128;
    f4_map.mask = 127;
    f4_map.threshold = 76;
    f4_map.entries = f4_entries;
    g_builtinVarLookup = &f4_map;
    g_builtin_numb = 0;
    nm = f4_name(p0);

    if (p4 == 1) {
        /* a stale name in the slot the append is about to reuse */
        g_builtin_numb = 1;
        g_builtin_variables[1].name = f4_stage_str("stale");
    } else if (p4 == 2) {
        /* the same NAME POINTER already in the map at its home slot, so the
         * probe's pointer comparison is what decides duplicate vs new */
        uint32_t h = CHashMap_CalculateHash(nm) & 0x7fffffffu;
        uint32_t idx = h & (uint32_t)f4_map.mask;
        g_builtin_variables[0].name = f4_stage_str("pre");
        g_builtin_numb = 1;
        f4_entries[idx].key = (char *)nm;
        f4_entries[idx].value = 0;
        f4_entries[idx].hash = h;
        f4_map.count = 1;
    } else if (p4 == 5) {
        /* two occupied neighbours: one at our home slot (distance 0, a
         * different key) and one at home+1 (distance 0 again).  Walking in with
         * distance 1 at the second one is what makes Robin Hood swap. */
        uint32_t h = CHashMap_CalculateHash(nm) & 0x7fffffffu;
        uint32_t idx = h & (uint32_t)f4_map.mask;
        uint32_t nxt = (idx + 1u) & (uint32_t)f4_map.mask;
        g_builtin_variables[0].name = f4_stage_str("pre");
        g_builtin_numb = 1;
        f4_entries[idx].key = (char *)"yy";
        f4_entries[idx].value = 70;
        f4_entries[idx].hash = idx ? idx : 1u;
        f4_entries[nxt].key = (char *)"zz";
        f4_entries[nxt].value = 90;
        f4_entries[nxt].hash = nxt ? nxt : 1u;
        f4_map.count = 2;
    } else if (p4 == 8) {
        /* our home slot already holds the SAME BYTES at a DIFFERENT address:
         * only the pointer comparison can tell them apart */
        uint32_t h = CHashMap_CalculateHash(nm) & 0x7fffffffu;
        uint32_t idx = h & (uint32_t)f4_map.mask;
        g_builtin_variables[0].name = f4_stage_str("pre");
        g_builtin_numb = 1;
        f4_entries[idx].key = (char *)f4_pair(p0);
        f4_entries[idx].value = 55;
        f4_entries[idx].hash = h;
        f4_map.count = 1;
    } else if (p4 == 6) {
        /* an entry sitting in OUR home slot whose own home is two slots back:
         * its distance (2) is greater than ours (0), so the walk moves on */
        uint32_t h = CHashMap_CalculateHash(nm) & 0x7fffffffu;
        uint32_t idx = h & (uint32_t)f4_map.mask;
        uint32_t home = (idx - 2u) & (uint32_t)f4_map.mask;
        g_builtin_variables[0].name = f4_stage_str("pre");
        g_builtin_numb = 1;
        f4_entries[idx].key = (char *)"ww";
        f4_entries[idx].value = 80;
        f4_entries[idx].hash = home ? home : 1u;
        f4_map.count = 1;
    } else if (p4 == 7) {
        /* the same hash and a different key POINTER: the hash test passes and
         * only the pointer comparison rejects it */
        uint32_t h = CHashMap_CalculateHash(nm) & 0x7fffffffu;
        uint32_t idx = h & (uint32_t)f4_map.mask;
        g_builtin_variables[0].name = f4_stage_str("pre");
        g_builtin_numb = 1;
        f4_entries[idx].key = (char *)"vv";
        f4_entries[idx].value = 60;
        f4_entries[idx].hash = h;
        f4_map.count = 1;
    } else if (p4 == 3) {
        g_builtin_numb = 499;
    } else if (p4 == 4) {
        g_builtin_numb = 500;
    }

    if (p5 == 1) {
        f4_map.threshold = -1;          /* 0 > -1: the first insert doubles */
        f4_entries[0].key = f4_stage_str("old0");
        f4_entries[0].value = 100;
        f4_entries[0].hash = 1;
        f4_entries[1].key = f4_stage_str("old1");
        f4_entries[1].value = 101;
        f4_entries[1].hash = 2;
        f4_entries[2].key = f4_stage_str("old2");
        f4_entries[2].value = 102;
        f4_entries[2].hash = 3;
        f4_map.count = 3;
    } else if (p5 == 2) {
        f4_map.threshold = -1;          /* doubling with nothing to rehash */
    }

    Variable_BuiltIn_Add(nm, p1 ? bvar_getter : 0, p2 ? bvar_setter : 0, p3);
    f4_dump();
}

/* ══ case loop ══════════════════════════════════════════════════════════ */
static int read_int(const char **pp)
{
    const char *p = *pp;
    int neg = 0, v = 0;
    while (*p == ' ' || *p == '\t' || *p == '\n') p++;
    if (*p == '-') { neg = 1; p++; }
    while (*p >= '0' && *p <= '9') { v = v * 10 + (*p - '0'); p++; }
    *pp = p;
    return neg ? -v : v;
}

static void print_i(int v)
{
    char b[16];
    int i = 0, neg = 0;
    unsigned int u = (unsigned int)v;
    if (v < 0) { neg = 1; u = (unsigned int)(-(long)v); }
    do { b[i++] = (char)('0' + (u % 10u)); u /= 10u; } while (u);
    if (neg) out("-", 1);
    while (i) out(&b[--i], 1);
}

static void run_f1(int p0, int p1, int p2)
{
    int nz = 0, fz = -1;

    (void)p2;      /* only the caller stages the failure byte for fn=1 */

    for (unsigned i = 0; i < sizeof realloc_block; i++)
        realloc_block[i] = (char)p0;
    for (unsigned i = 0; i < sizeof old_block; i++)
        old_block[i] = 0x5a;
    stage_old_data = p1 ? old_block : 0;
    g_globdecl.cap = 0;
    g_globdecl.data = stage_old_data;

    Variable_Global_Init();

    for (unsigned i = 0; i < sizeof realloc_block; i++)
        if (realloc_block[i]) { nz++; if (fz < 0) fz = (int)i; }

    out("RET void\n", 9);
    out("EXT CAP ", 8); print_i(g_globdecl.cap); out("\n", 1);
    out("EXT DATAPTR ", 12); print_i(g_globdecl.data == realloc_block); out("\n", 1);
    out("EXT NZ ", 7); print_i(nz); out("\n", 1);
    out("EXT FZ ", 7); print_i(fz); out("\n", 1);
}

int main(void)
{
    static char inbuf[8192];
    long n = read_all(inbuf, (long)sizeof inbuf - 1);
    if (n <= 0) quit(2);
    inbuf[n] = 0;
    const char *p = inbuf;

    while (*p) {
        int fn = read_int(&p);
        int p0 = read_int(&p), p1 = read_int(&p), p2 = read_int(&p);
        int p3 = read_int(&p), p4 = read_int(&p), p5 = read_int(&p);
        int p6 = read_int(&p);
        if (*p == 0 && fn == 0)
            break;
        if (fn < 1 || fn > 4)
            quit(4);                    /* malformed case line, loudly */

        out("CASE ", 5);
        print_i(fn); out(" ", 1);
        print_i(p0); out(" ", 1); print_i(p1); out(" ", 1);
        print_i(p2); out(" ", 1); print_i(p3); out(" ", 1);
        print_i(p4); out(" ", 1); print_i(p5); out(" ", 1);
        print_i(p6); out("\n", 1);

        g_fail_flag = 0;
        g_ncalls = 0;
        if (fn == 1) {
            g_fail_flag = (unsigned char)p2;
            run_f1(p0, p1, p2);
        } else if (fn == 2) {
            g_fail_flag = (unsigned char)p5;
            run_f2(p0, p1, p2, p3, p4, p5, p6);
        } else if (fn == 4) {
            g_fail_flag = (unsigned char)0;
            run_f4(p0, p1, p2, p3, p4, p5, p6);
        } else if (fn == 3) {
            g_fail_flag = (unsigned char)((p6 >> 1) & 1);  /* p6 bit1 */
            run_f3(p0, p1, p2, p3, p4, p5, p6);
        }
        out("CALLS ", 6); print_i(g_ncalls); out("\n", 1);
        out("FLAG ", 5); print_i(g_fail_flag ? 1 : 0); out("\n", 1);
    }
    quit(0);            /* no CRT: returning from main would jump to nothing */
}
