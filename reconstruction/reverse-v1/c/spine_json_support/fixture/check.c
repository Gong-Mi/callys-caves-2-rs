/*
 * check.c — synthetic providers + real reconstructed consumers for
 * c/spine_json_error and c/spine_json_support.
 *
 * The original libyoyo.so is never loaded or executed.  Only our linked
 * ARM32 C runs under qemu-arm.  _readFile, the 13 KB loader and the
 * platform reporter constructor are named provider/gap boundaries; the
 * fake bodies below are test scaffolding, not original-function recovery.
 */
#include "spine_json_error.h"
#include "spine_json_support.h"
#include "spine_alloc.h"

#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

/* ------------------------------------------------------------------ */
/* freestanding runtime                                                */
/* ------------------------------------------------------------------ */
static long sys3(long n, long a, long b, long c)
{
    register long r7 __asm__("r7") = n, r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b, r2 __asm__("r2") = c;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r7), "r"(r1), "r"(r2) : "memory");
    return r0;
}
static void out(const char *s)
{
    size_t n = 0;
    while (s[n]) ++n;
    sys3(4, 1, (long)(uintptr_t)s, (long)n);
}
static void quit(int code) __attribute__((noreturn));
static void quit(int code) { sys3(1, code, 0, 0); for (;;) {} }
int write(int fd, const void *buf, size_t n)
{
    return (int)sys3(4, fd, (long)(uintptr_t)buf, (long)n);
}
void abort(void) { quit(1); }

size_t strlen(const char *s) { size_t n = 0; while (s[n]) ++n; return n; }
char *strcpy(char *d, const char *s) { char *p = d; while ((*d++ = *s++)) {} return p; }
char *strncat(char *d, const char *s, size_t n)
{
    char *p = d;
    while (*d) ++d;
    while (n-- && *s) *d++ = *s++;
    *d = 0;
    return p;
}
int strcmp(const char *a, const char *b)
{
    while (*a && *a == *b) { ++a; ++b; }
    return (int)(unsigned char)*a - (int)(unsigned char)*b;
}
int strcasecmp(const char *a, const char *b)
{
    for (;;) {
        unsigned x = (unsigned char)*a++, y = (unsigned char)*b++;
        if (x >= 'A' && x <= 'Z') x += 32;
        if (y >= 'A' && y <= 'Z') y += 32;
        if (x != y || !x) return (int)x - (int)y;
    }
}
void *memset(void *d, int v, size_t n)
{
    unsigned char *p = d;
    while (n--) *p++ = (unsigned char)v;
    return d;
}
void *memcpy(void *d, const void *s, size_t n)
{
    unsigned char *p = d;
    const unsigned char *q = s;
    while (n--) *p++ = *q++;
    return d;
}
void *memmove(void *d, const void *s, size_t n)
{
    unsigned char *p = d;
    const unsigned char *q = s;
    if (p < q) { while (n--) *p++ = *q++; }
    else { while (n--) p[n] = q[n]; }
    return d;
}
void __aeabi_memclr(void *p, size_t n) { memset(p, 0, n); }
void __aeabi_memclr4(void *p, size_t n) { memset(p, 0, n); }
void __aeabi_memclr8(void *p, size_t n) { memset(p, 0, n); }
void __aeabi_memcpy4(void *d, const void *s, size_t n) { memcpy(d, s, n); }

uintptr_t __stack_chk_guard = 0xc2331111u;
void __stack_chk_fail(void) { out("FAIL stack guard\n"); quit(1); }

/* ------------------------------------------------------------------ */
/* test state                                                          */
/* ------------------------------------------------------------------ */
static const char *test_name;
static void fail(const char *why)
{
    out("FAIL "); out(test_name); out(": "); out(why); out("\n");
    quit(1);
}
#define CK(x, why) do { if (!(x)) fail(why); } while (0)

enum { EV_FREE = 1, EV_ALLOC = 2, EV_REPORT = 3, EV_LOADER = 4 };
struct event { uint32_t type; void *p; uint32_t line; const char *tag; };
static struct event events[512];
static unsigned event_count;

static void event(uint32_t type, void *p, uint32_t line, const char *tag)
{
    CK(event_count < 512, "event roster");
    events[event_count].type = type;
    events[event_count].p = p;
    events[event_count].line = line;
    events[event_count].tag = tag;
    ++event_count;
}
static int event_pos(uint32_t type, void *p)
{
    for (unsigned i = 0; i < event_count; ++i)
        if (events[i].type == type && (p == NULL || events[i].p == p))
            return (int)i;
    return -1;
}
static unsigned event_count_of(uint32_t type, void *p)
{
    unsigned n = 0;
    for (unsigned i = 0; i < event_count; ++i)
        if (events[i].type == type && (p == NULL || events[i].p == p)) ++n;
    return n;
}
static void order(int before, int after, const char *why)
{
    CK(before >= 0 && after >= 0 && before < after, why);
}

/* static arena; _free is a recording provider, not a real deallocator */
static uint8_t arena[1u << 17];
static uint32_t arena_used;
static void *reserve(uint32_t n)
{
    arena_used = (arena_used + 7u) & ~7u;
    if (n == 0) n = 1;
    CK(arena_used + n <= sizeof(arena), "arena budget");
    void *p = arena + arena_used;
    arena_used += n;
    memset(p, 0, n);
    return p;
}

struct alloc_rec { void *p; uint32_t size, line; const char *tag; };
static struct alloc_rec allocs[32];
static unsigned alloc_count;

/* hostile free hooks for the named negative controls */
static int free_mode;
static void *free_target;
static Json *free_parent;
static const char *free_new_string;
static const char *free_new_name;
static Json *free_new_next;

static void fixture_free(void *p)
{
    event(EV_FREE, p, 0, NULL);
    if (free_target != NULL && p == free_target) {
        if (free_mode == 1 && free_parent != NULL) {
            free_parent->string_value = free_new_string;
            free_parent->name = free_new_name;
        } else if (free_mode == 2 && free_parent != NULL) {
            free_parent->next = free_new_next;
        } else if (free_mode == 3 && free_parent != NULL) {
            free_parent->name = free_new_name;
        }
    }
}

static void *fixture_alloc(uint32_t n, const char *tag, uint32_t line)
{
    void *p = reserve(n);
    CK(alloc_count < 32, "allocation roster");
    allocs[alloc_count].p = p;
    allocs[alloc_count].size = n;
    allocs[alloc_count].line = line;
    allocs[alloc_count].tag = tag;
    ++alloc_count;
    event(EV_ALLOC, p, line, tag);
    return p;
}

/* default libc slots required by spine_alloc.c; never used after _set* */
void *malloc(uint32_t n) { return reserve(n); }
void free(void *p) { fixture_free(p); }

/* ------------------------------------------------------------------ */
/* real reporter vcall sink                                            */
/* ------------------------------------------------------------------ */
static struct SpineErrorConsole reporter_obj;
static struct SpineErrorConsoleVTable reporter_vt;
static unsigned report_count, wrong_slot_count;
static struct SpineErrorConsole *report_self;
static char report_format[64];
static char report_message[512];

static void copy_cstr(char *d, const char *s, unsigned cap)
{
    unsigned i = 0;
    while (s[i] && i + 1 < cap) { d[i] = s[i]; ++i; }
    d[i] = 0;
}
static void report_output(struct SpineErrorConsole *self, const char *fmt, ...)
{
    va_list ap;va_start(ap,fmt);const char *message=va_arg(ap,const char *);va_end(ap);
    ++report_count;
    report_self = self;
    copy_cstr(report_format, fmt, sizeof(report_format));
    copy_cstr(report_message, message, sizeof(report_message));
    event(EV_REPORT, (void *)message, 0, fmt);
}
static void wrong_destructor(struct SpineErrorConsole *self)
{
    (void)self; ++wrong_slot_count;
}
static void wrong_create(struct SpineErrorConsole *self, const char *name, int flag)
{
    (void)self; (void)name; (void)flag; ++wrong_slot_count;
}
static void reporter_install(void)
{
    memset(&reporter_obj, 0, sizeof(reporter_obj));
    memset(&reporter_vt, 0, sizeof(reporter_vt));
    reporter_vt.destructor_complete = wrong_destructor;
    reporter_vt.destructor_deleting = wrong_destructor;
    reporter_vt.create = wrong_create;
    reporter_vt.output = report_output;
    reporter_obj.vptr = &reporter_vt;
    dbg_csol = &reporter_obj;
    report_count = 0;
    wrong_slot_count = 0;
    report_self = NULL;
    report_format[0] = 0;
    report_message[0] = 0;
}

/* ------------------------------------------------------------------ */
/* Json tree helpers                                                   */
/* ------------------------------------------------------------------ */
static Json *jnode(void)
{
    Json *n = reserve(sizeof(Json));
    memset(n, 0, sizeof(*n));
    return n;
}
static int freed(void *p) { return event_pos(EV_FREE, p) >= 0; }
static unsigned free_count(void *p) { return event_count_of(EV_FREE, p); }

/* ------------------------------------------------------------------ */
/* fake file-I/O and loader boundaries                                 */
/* ------------------------------------------------------------------ */
static void *fake_read_data;
static int32_t fake_read_size;
static int fake_read_write_size;
static const char *fake_read_path;
static unsigned fake_read_calls;
static spSkeletonData *fake_loader_result;
static const void *fake_loader_data;
static unsigned fake_loader_calls;

void *_readFile(const char *path, int32_t *out_size)
{
    ++fake_read_calls;
    fake_read_path = path;
    if (fake_read_write_size) *out_size = fake_read_size;
    return fake_read_data;
}
spSkeletonData *spSkeletonJson_readSkeletonData(spSkeletonJson *self, const char *data)
{
    (void)self;
    ++fake_loader_calls;
    fake_loader_data = data;
    event(EV_LOADER, (void *)data, 0, NULL);
    return fake_loader_result;
}

/* ------------------------------------------------------------------ */
/* lifecycle                                                           */
/* ------------------------------------------------------------------ */
static void begin(const char *name)
{
    test_name = name;
    arena_used = 0;
    event_count = 0;
    alloc_count = 0;
    free_mode = 0;
    free_target = NULL;
    free_parent = NULL;
    free_new_string = NULL;
    free_new_name = NULL;
    free_new_next = NULL;
    fake_read_data = NULL;
    fake_read_size = 0;
    fake_read_write_size = 1;
    fake_read_path = NULL;
    fake_read_calls = 0;
    fake_loader_result = NULL;
    fake_loader_data = NULL;
    fake_loader_calls = 0;
    reporter_install();
    _setDebugMalloc(fixture_alloc);
    _setFree(fixture_free);
    _setMalloc(fixture_alloc);
}
static void pass(void) { out("PASS "); out(test_name); out("\n"); }

/* ------------------------------------------------------------------ */
/* ReportSpineError                                                    */
/* ------------------------------------------------------------------ */
static void test_report_exact_vcall(void)
{
    begin("report_exact_vcall_slot_0xc");
    ReportSpineError("boom");
    CK(report_count == 1, "Output called exactly once");
    CK(wrong_slot_count == 0, "only address-point +0xc is called");
    CK(report_self == &reporter_obj, "r0 is the dbg_csol object");
    CK(strcmp(report_format, "Spine Error:%s\n") == 0, "r1 exact format literal");
    CK(strcmp(report_message, "boom") == 0, "r2 exact message");
    pass();
}

static void test_report_wrong_slots(void)
{
    begin("neg_report_vtable_slot_0x0_0x4_0x8_not_called");
    ReportSpineError("x");
    CK(report_count == 1 && wrong_slot_count == 0,
       "a +0x0/+0x4/+0x8 vcall would hit a wrong-slot sentinel");
    pass();
}

static unsigned sink_a_calls, sink_b_calls;
static void sink_a(struct SpineErrorConsole *self, const char *fmt, ...)
{ (void)self; (void)fmt; ++sink_a_calls; }
static void sink_b(struct SpineErrorConsole *self, const char *fmt, ...)
{ (void)self; (void)fmt; ++sink_b_calls; }

static void test_report_global_reload(void)
{
    begin("neg_report_global_reloaded_each_call");
    static struct SpineErrorConsole oa, ob;
    static struct SpineErrorConsoleVTable va, vb;
    memset(&va, 0, sizeof(va)); memset(&vb, 0, sizeof(vb));
    va.output = sink_a; vb.output = sink_b;
    oa.vptr = &va; ob.vptr = &vb;
    sink_a_calls = sink_b_calls = 0;
    dbg_csol = &oa; ReportSpineError("a");
    dbg_csol = &ob; ReportSpineError("b");
    CK(sink_a_calls == 1 && sink_b_calls == 1,
       "a cached dbg_csol would send both calls to one sink");
    pass();
}

/* ------------------------------------------------------------------ */
/* Json_dispose                                                        */
/* ------------------------------------------------------------------ */
static void test_json_null(void)
{
    begin("json_dispose_null_is_noop");
    Json_dispose(NULL);
    CK(event_count == 0, "NULL json must not free anything");
    pass();
}

static void test_json_order(void)
{
    begin("json_dispose_order_depth_first_next_cached");
    Json *root = jnode(), *a = jnode(), *b = jnode(), *c = jnode(), *g = jnode();
    root->child = a; root->next = b;
    a->next = c; a->child = g;
    g->name = "gn";
    a->string_value = "as"; a->name = "an";
    c->string_value = "cs";
    b->name = "bn";

    Json_dispose(root);

    CK(freed("gn") && freed(g) && freed("as") && freed("an") && freed(a),
       "grandchild/subtree freed");
    CK(freed("cs") && freed(c), "child sibling freed");
    CK(freed(root), "root freed after its child list");
    CK(freed("bn") && freed(b), "root next sibling freed last");
    order(event_pos(EV_FREE, "gn"), event_pos(EV_FREE, g), "name before grandchild node");
    order(event_pos(EV_FREE, g), event_pos(EV_FREE, "as"), "grandchild before parent string");
    order(event_pos(EV_FREE, "as"), event_pos(EV_FREE, "an"), "string before name");
    order(event_pos(EV_FREE, "an"), event_pos(EV_FREE, a), "fields before node");
    order(event_pos(EV_FREE, a), event_pos(EV_FREE, "cs"), "child before its sibling");
    order(event_pos(EV_FREE, c), event_pos(EV_FREE, root), "child list before root");
    order(event_pos(EV_FREE, root), event_pos(EV_FREE, "bn"), "root before next sibling");
    pass();
}

static void test_json_null_fields(void)
{
    begin("json_dispose_skips_null_string_and_name");
    Json *n = jnode();
    Json_dispose(n);
    CK(free_count(n) == 1, "node freed once");
    CK(event_count == 1, "no NULL free calls for absent string/name");
    pass();
}

static void test_json_reread_fields(void)
{
    begin("neg_json_dispose_rereads_string_name_after_child");
    Json *root = jnode(), *child = jnode();
    root->child = child;
    root->string_value = "OLD_S";
    root->name = "OLD_N";
    free_mode = 1;
    free_target = child;
    free_parent = root;
    free_new_string = "NEW_S";
    free_new_name = "NEW_N";

    Json_dispose(root);

    CK(freed("NEW_S") && freed("NEW_N"),
       "fields changed while disposing child must be re-read");
    CK(!freed("OLD_S") && !freed("OLD_N"),
       "cached pre-child fields would free the stale pointers");
    pass();
}

static void test_json_next_cache(void)
{
    begin("neg_json_dispose_caches_next_before_child");
    Json *root = jnode(), *child = jnode(), *next = jnode();
    root->child = child;
    root->next = next;
    free_mode = 2;
    free_target = child;
    free_parent = root;
    free_new_next = NULL;

    Json_dispose(root);

    CK(freed(next),
       "next cached before child disposal must still be visited");
    pass();
}

static void test_json_name_reread(void)
{
    begin("neg_json_dispose_rereads_name_after_string_free");
    Json *root = jnode();
    root->string_value = "S";
    root->name = "N";
    free_mode = 3;
    free_target = (void *)"S";
    free_parent = root;
    free_new_name = "N2";

    Json_dispose(root);

    CK(freed("N2"), "name re-read after string free");
    CK(!freed("N"), "pre-string-free name cache would free N");
    pass();
}

/* ------------------------------------------------------------------ */
/* _spSkeletonJson_setError                                            */
/* ------------------------------------------------------------------ */
static const char *TAG =
    "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";
static const char *FMT = "Spine Error:%s\n";

static void test_set_error_basic(void)
{
    begin("set_error_tag_line_message_and_order");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    static char old_error[] = "OLD";
    j.error = (uint32_t)(uintptr_t)old_error;
    Json *root = jnode(), *child = jnode();
    root->child = child;
    child->string_value = "CS";
    child->name = "CN";

    _spSkeletonJson_setError(&j, root, "alpha", NULL);

    CK(alloc_count == 1, "exactly one allocation");
    struct alloc_rec *a = &allocs[0];
    CK(a->size == 6, "strlen(buffer)+1");
    CK(a->line == 90, "original line 0x5a");
    CK(a->tag != NULL && strcmp(a->tag, TAG) == 0, "full original malloc tag");
    CK(j.error == (uint32_t)(uintptr_t)a->p, "self->error points at allocation");
    CK(strcmp((const char *)(uintptr_t)j.error, "alpha") == 0, "owned copy");
    CK(report_count == 1, "reported once");
    CK(strcmp(report_format, FMT) == 0, "report format");
    CK(strcmp(report_message, "alpha") == 0, "report message");

    int f_old = event_pos(EV_FREE, old_error);
    int p_alloc = event_pos(EV_ALLOC, a->p);
    int p_report = event_pos(EV_REPORT, NULL);
    int f_child = event_pos(EV_FREE, child);
    order(f_old, p_alloc, "old self->error freed before allocation");
    order(p_alloc, p_report, "allocation before ReportSpineError");
    order(p_report, f_child, "ReportSpineError before Json_dispose");
    pass();
}

static void test_set_error_old_free(void)
{
    begin("neg_set_error_skips_old_error_free");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    static char old_error[] = "OLD2";
    j.error = (uint32_t)(uintptr_t)old_error;
    _spSkeletonJson_setError(&j, NULL, "m", NULL);
    CK(event_pos(EV_FREE, old_error) >= 0,
       "overwriting self->error without freeing the old string would leak");
    pass();
}

static void test_set_error_tag(void)
{
    begin("neg_set_error_short_malloc_tag");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    _spSkeletonJson_setError(&j, NULL, "m", NULL);
    CK(alloc_count == 1 && strcmp(allocs[0].tag, TAG) == 0,
       "a short tag (e.g. spine_json_err) is not the original literal");
    pass();
}

static void test_set_error_line(void)
{
    begin("neg_set_error_wrong_alloc_line");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    _spSkeletonJson_setError(&j, NULL, "m", NULL);
    CK(alloc_count == 1 && allocs[0].line == 90, "line must be 90");
    pass();
}

static void test_set_error_order_malloc_report(void)
{
    begin("neg_set_error_reports_before_malloc");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    _spSkeletonJson_setError(&j, NULL, "m", NULL);
    int a = event_pos(EV_ALLOC, NULL), r = event_pos(EV_REPORT, NULL);
    order(a, r, "reporting before the owned copy exists would invert the original order");
    pass();
}

static void test_set_error_order_report_dispose(void)
{
    begin("neg_set_error_json_dispose_before_report");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    Json *root = jnode();
    root->name = "R";
    _spSkeletonJson_setError(&j, root, "m", NULL);
    int r = event_pos(EV_REPORT, NULL), f = event_pos(EV_FREE, "R");
    order(r, f, "Json_dispose before ReportSpineError would invert the original order");
    pass();
}

static void test_set_error_extra(void)
{
    begin("set_error_extra_append_exact");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    _spSkeletonJson_setError(&j, NULL, "0123456789", "XYZ");
    CK(strcmp((const char *)(uintptr_t)j.error, "0123456789XYZ") == 0,
       "extra appended after message");
    CK(report_count == 1 && strcmp(report_message, "0123456789XYZ") == 0,
       "reporter sees the appended buffer");
    pass();
}

static void test_set_error_extra_ignored(void)
{
    begin("neg_set_error_extra_ignored");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    _spSkeletonJson_setError(&j, NULL, "A", "B");
    CK(strcmp((const char *)(uintptr_t)j.error, "AB") == 0,
       "ignoring extra would store A");
    pass();
}

static void test_set_error_extra_bound(void)
{
    begin("neg_set_error_extra_bound_255");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    char msg[251], extra[11];
    for (unsigned i = 0; i < 250; ++i) msg[i] = 'a';
    msg[250] = 0;
    for (unsigned i = 0; i < 10; ++i) extra[i] = 'b';
    extra[10] = 0;
    _spSkeletonJson_setError(&j, NULL, msg, extra);
    const char *s = (const char *)(uintptr_t)j.error;
    CK(strlen(s) == 255, "strncat bound 255-strlen(message) => 255 total");
    for (unsigned i = 0; i < 250; ++i) CK(s[i] == 'a', "message prefix preserved");
    for (unsigned i = 250; i < 255; ++i) CK(s[i] == 'b', "five extra bytes appended");
    CK(s[255] == 0, "NUL terminator inside the 256-byte buffer");
    pass();
}

static void test_set_error_extra_null(void)
{
    begin("set_error_extra_null");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    _spSkeletonJson_setError(&j, NULL, "abc", NULL);
    CK(strcmp((const char *)(uintptr_t)j.error, "abc") == 0,
       "NULL extra leaves the message untouched");
    pass();
}

/* ------------------------------------------------------------------ */
/* spSkeletonJson_readSkeletonDataFile                                 */
/* ------------------------------------------------------------------ */
static uint32_t fake_blob = 0xfeedfaceu;

static void test_file_success(void)
{
    begin("file_wrapper_success_loader_then_free");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    fake_read_data = &fake_blob;
    fake_read_size = 4;
    fake_read_write_size = 1;
    fake_loader_result = (spSkeletonData *)(uintptr_t)0x1234;
    spSkeletonData *r = spSkeletonJson_readSkeletonDataFile(&j, "a.json");
    CK(r == fake_loader_result, "loader result returned");
    CK(fake_read_calls == 1 && strcmp(fake_read_path, "a.json") == 0,
       "_readFile called once with path");
    CK(fake_loader_calls == 1 && fake_loader_data == &fake_blob,
       "loader receives data");
    int l = event_pos(EV_LOADER, &fake_blob);
    int f = event_pos(EV_FREE, &fake_blob);
    order(l, f, "data freed only after the loader returns");
    pass();
}

static void test_file_success_free_order(void)
{
    begin("neg_file_wrapper_frees_before_loader");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    fake_read_data = &fake_blob;
    fake_read_size = 4;
    fake_loader_result = (spSkeletonData *)(uintptr_t)0x5678;
    (void)spSkeletonJson_readSkeletonDataFile(&j, "b.json");
    int l = event_pos(EV_LOADER, &fake_blob), f = event_pos(EV_FREE, &fake_blob);
    order(l, f, "freeing before the loader call would hand out freed data");
    pass();
}

static void test_file_size_zero(void)
{
    begin("neg_file_wrapper_size_zero_is_error");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    fake_read_data = &fake_blob;
    fake_read_size = 0;
    fake_read_write_size = 1;
    fake_loader_result = (spSkeletonData *)(uintptr_t)0x9abc;
    spSkeletonData *r = spSkeletonJson_readSkeletonDataFile(&j, "c.json");
    CK(r == NULL, "size==0 must return NULL");
    CK(fake_loader_calls == 0, "loader not called");
    CK(report_count == 1, "one error report");
    CK(strcmp(report_message, "Unable to read skeleton file: c.json") == 0,
       "original 0x357f70 prefix plus path");
    CK(j.error != 0 &&
       strcmp((const char *)(uintptr_t)j.error,
              "Unable to read skeleton file: c.json") == 0,
       "self->error owns the same text");
    pass();
}

static void test_file_size_zero_no_free(void)
{
    begin("neg_file_wrapper_size_zero_no_free");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    fake_read_data = &fake_blob;
    fake_read_size = 0;
    fake_read_write_size = 1;
    (void)spSkeletonJson_readSkeletonDataFile(&j, "d.json");
    CK(!freed(&fake_blob),
       "the original error branch does not free non-NULL data with size==0");
    pass();
}

static void test_file_null_data(void)
{
    begin("neg_file_wrapper_null_data_is_error");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    fake_read_data = NULL;
    fake_read_size = 4;
    fake_read_write_size = 1;
    fake_loader_result = (spSkeletonData *)(uintptr_t)0xdef0;
    spSkeletonData *r = spSkeletonJson_readSkeletonDataFile(&j, "e.json");
    CK(r == NULL, "NULL data must return NULL");
    CK(fake_loader_calls == 0, "loader not called");
    CK(report_count == 1 &&
       strcmp(report_message, "Unable to read skeleton file: e.json") == 0,
       "NULL-data branch uses the same original prefix");
    pass();
}

static void test_file_prefix_exact(void)
{
    begin("neg_file_wrapper_exact_prefix");
    spSkeletonJson j;
    memset(&j, 0, sizeof(j));
    fake_read_data = NULL;
    fake_read_size = 0;
    fake_read_write_size = 1;
    (void)spSkeletonJson_readSkeletonDataFile(&j, "f");
    CK(strcmp(report_message, "Unable to read skeleton file: f") == 0,
       "the old 'Error reading skeleton file: ' text is wrong");
    pass();
}

/* ------------------------------------------------------------------ */
/* driver                                                              */
/* ------------------------------------------------------------------ */
void _start(void)
{
    test_report_exact_vcall();
    test_report_wrong_slots();
    test_report_global_reload();
    test_json_null();
    test_json_order();
    test_json_null_fields();
    test_json_reread_fields();
    test_json_next_cache();
    test_json_name_reread();
    test_set_error_basic();
    test_set_error_old_free();
    test_set_error_tag();
    test_set_error_line();
    test_set_error_order_malloc_report();
    test_set_error_order_report_dispose();
    test_set_error_extra();
    test_set_error_extra_ignored();
    test_set_error_extra_bound();
    test_set_error_extra_null();
    test_file_success();
    test_file_success_free_order();
    test_file_size_zero();
    test_file_size_zero_no_free();
    test_file_null_data();
    test_file_prefix_exact();
    out("ALL PASS spine_json_error/support\n");
    quit(0);
}
