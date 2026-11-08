/* Reconstructed ARM32 consumers only.  The heap, libc strings, JSON tree
 * nodes, the reporter, the attachment loader/vtable, the four local record
 * creators and the parser error model below are SYNTHETIC providers; qemu
 * executes our linked C, never original libyoyo bytes.  Original not executed;
 * this is not an original-equivalence claim.
 *
 * Subject: the assembled spSkeletonJson_readSkeletonData @0x28b84c (13044 B,
 * libyoyo_armv7.so SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a)
 * built by c/spine_read_skeleton: entry -> meta/bones -> slots -> ik ->
 * transform -> path -> skins(+dispatch/glue/parsers) -> linkedmesh postpass ->
 * events+animations(B1/B2/loop) -> B18.
 *
 * REAL recovered bodies linked into this executable (no stubs):
 *   readSkeletonData_entry / _metadata / _bonesArray / _boneLoop
 *   readSkeletonData_slotsSegment / _ikSection / _transformSection / _pathSection
 *   readSkeletonData_skinsArray / _oneSkin / _classifyAttachment
 *   readSkeletonData_skinsCreate* / _skinsAttachmentLevel / _skinsAdvance
 *   readSkeletonData_regionFields / _meshFields / _boundingBoxFields /
 *   _pathAttachmentFields / _readVertices / _resolveLinkedMeshes
 *   readSkeletonData_eventsSegment / _eventsArray / _animationsArray
 *   readSkeletonData_animationFrameInit / _animationKeys / _animationLegacyDrawOrder /
 *   _animationTimelines / _animationsLoop / _animationsSlotNotFound
 *   the nine timeline families
 *   Json_getItem/getString/getFloat/getInt, Json_dispose, ReportSpineError,
 *   _spSkeletonJson_setError, spSkeletonJson_readSkeletonDataFile,
 *   toColor, readCurve, spSkeletonData_create/dispose (+record disposers),
 *   spSkeletonData_findBone/findSlotIndex/findSkin, spSkin_create/add/get,
 *   spAttachmentLoader_createAttachment (+configure), the five sp*Attachment
 *   constructors and their disposers, spRegionAttachment_updateOffset,
 *   spMeshAttachment_updateUVs/setParentMesh, _malloc/_calloc/_free.
 *
 * SYNTHETIC boundaries (bodies not recovered anywhere in this tree):
 *   Json_create 0x287320 + Json_getError 0x2872b8 (parser entry; the fixture
 *     returns the staged tree and records the parse-error text),
 *   spBoneData_create 0x285ac8, spSlotData_create 0x28ef6c,
 *   spSlotData_setAttachmentName 0x28efd4, spIkConstraintData_create 0x28671c,
 *   spTransformConstraintData_create 0x28f5b8, spPathConstraintData_create 0x288ee0,
 *   spSkeletonData_findSlot 0x28b070 (92 B, .dynsym; no module recovered it),
 *   spAnimation_create / spEventData_create / spEvent_create and every timeline
 *     create/setFrame + spCurveTimeline_setStepped/setCurve,
 *   spSkeletonData_findEvent/findIkConstraint/findTransformConstraint/
 *     findPathConstraint, the attachment loader record + vtable + its
 *     createAttachment body, the fixture heap/allocator rosters, libc
 *     (strlen/strcpy/strcmp/strcasecmp/strtoul/strncat/_strlen/_strcpy/
 *     _strcmp/_strdup/_setlocale/cos/sin), and the hand-built Json nodes.
 *
 * ALLOCATOR NOTE: chain_alloc zero-fills and pre-points the eight skeleton
 * array allocations (and the animation timeline table) at zeroed "safe"
 * records.  That is a synthetic heap state, exactly like
 * c/spine_read_slots/fixture/segment_check.c's line-651 fill: several error
 * tails dispose a data record whose count was published BEFORE the array was
 * filled, and the original would walk uninitialized malloc words there.  The
 * fixture makes those walks land on inert records so the ERROR CONTRACTS
 * (dispose order, report text, root release) are observable; the original's
 * undefined behaviour on malloc garbage is recorded in functions.json open[]
 * and is NOT asserted.
 */

/*
 * The animations-loop fixture is reused for its timeline creators, curve
 * recorders, event creators, the four synthetic find* scans and the reporter
 * sink.  Two of its named-gap stubs collide with this batch (the loader symbol
 * this module DEFINES, and _readFile which the file-wrapper test drives), so
 * they are renamed for the duration of the include only.
 */
#define spSkeletonJson_readSkeletonData yy_animations_fixture_loader_stub
#define _readFile yy_animations_fixture_readfile_stub
#include "../../spine_animations_loop/fixture/check.c"
#undef spSkeletonJson_readSkeletonData
#undef _readFile

#include "spine_read_skeleton.h"
#include "../../spine_json_error/src/spine_json_error.h"
#include "../../spine_atlas_attachment/src/spine_atlas_attachment.h"
#include "../../spine_skin/src/spine_skin.h"
#include "../../spine_skeleton_data/src/spine_skeleton_data.h"

#include <stdarg.h>

/* From spine_linked_postpass/fixture/reporter_adapter.c. */
extern void fixture_install_error_reporter(void);

/* The file wrapper's named I/O gap, driven by the file-wrapper test only. */
extern void* _readFile(const char* path, int32_t* out_size);

#define CHAIN_TAG "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"

/* ================================================================== */
/* observation state                                                   */
/* ================================================================== */

static struct chain_alloc_rec {
    void* p;
    uint32_t bytes;
    uint32_t line;
    const char* tag;
} chain_allocs[1024];
static void* chain_frees[1024];
static unsigned chain_na, chain_nf;

static spSkeletonJson g_self;
static spSkeletonData* g_data_out;

/* Json_create / Json_getError seam (see the module header). */
static Json* g_tree;
static int json_create_calls;
static const char* json_create_arg;
static const char* g_parse_error = "parse failed at 1";
static int json_create_fail;

/* cos/sin observation (region geometry + mesh UV bodies) */
static uint64_t cos_arg_bits, sin_arg_bits;
static int cos_calls, sin_calls;

/* _setlocale observation */
static int locale_calls;
static const char* locale_args[8];
static int locale_null;
static int locale_calls_at_create;

/* attachment loader observation */
static spAttachmentLoader att_loader;
static spAttachmentLoaderVtable att_loader_vtable;
static spAttachment* att_loader_create(spAttachmentLoader*, spSkin*, int32_t,
                                       const char*, const char*);
static void att_loader_configure(spAttachmentLoader*, spAttachment*);
static int loader_mode;             /* 0 answer, 1 NULL silent, 2 NULL + pair */
static int create_calls;
static int32_t create_type[4];
static const char* create_name[4];
static const char* create_path[4];
static spSkin* create_skin[4];
static int configure_calls;
static void* configure_seen[4];
static spAttachment* answered[4];
static int answered_n;

/* Per-stage creator call sequence.  Each synthetic record creator appends one
 * letter, so the ORDER of the segment stages is observable in the composition
 * (bones B, slots S, ik I, transform X, path P) without reading any module's
 * internals. */
static char creator_log[32];
static unsigned creator_n;
static void chain_log(char c)
{
    if (creator_n + 1u < sizeof creator_log) {
        creator_log[creator_n++] = c;
        creator_log[creator_n] = 0;
    }
}

/* synthetic record creators: last arguments + produced pointers */
static void* made_bone[4];
static void* made_slot[2];
static void* made_ik[2];
static void* made_tr[2];
static void* made_path[2];
static char slot_name_copy[2][32];
static char slot_attachment_copy[2][32];

/* tree knobs (each error test moves exactly one) */
static const char* knob_parent;        /* bone "arm" parent      */
static const char* knob_slot_bone;     /* slot bone              */
static const char* knob_ik_bone0;      /* ik constraint bone 0   */
static const char* knob_ik_target;     /* ik target              */
static const char* knob_tr_bone0;      /* transform bone 0       */
static const char* knob_tr_target;     /* transform target       */
static const char* knob_path_bone0;    /* path bone 0            */
static const char* knob_path_target;   /* path target slot       */
static const char* knob_att_type;      /* region attachment type */
static const char* knob_link_skin;     /* linkedmesh "skin", 0 = absent */
static int tree_extra_linked;          /* add the linkedmesh attachment */

/* ================================================================== */
/* synthetic allocator (zero fill + inert array elements)              */
/* ================================================================== */

static uint32_t safe_bone[13];      /* 52 B */
static uint32_t safe_slot[9];       /* 36 B */
static uint32_t safe_skin[2];
static uint32_t safe_event[4];
static uint32_t safe_anim[4];
static uint32_t safe_ik[6];
static uint32_t safe_tr[14];
static uint32_t safe_path[12];
static uint32_t safe_tl[4];
static uint32_t safe_tl_vtable[2];

static void chain_fill_array(void* p, uint32_t bytes, const uint32_t* record)
{
    uint32_t i;
    for (i = 0; i + 4 <= bytes; i += 4)
        *(uint32_t*)((char*)p + i) = (uint32_t)(uintptr_t)record;
}

static void* chain_alloc(uint32_t n, const char* tag, uint32_t line)
{
    void* p;
    CK(chain_na < 1024 && tag, "chain allocation roster/tag");
    p = reserve(n);
    if (n <= 4096) memset(p, 0, n);
    switch (line) {
    case 615: case 705: case 743: case 791:
        chain_fill_array(p, n, safe_bone); break;      /* bone pointer arrays */
    case 651: chain_fill_array(p, n, safe_slot); break;
    case 839: chain_fill_array(p, n, safe_skin); break;
    case 1028: chain_fill_array(p, n, safe_event); break;
    case 1043: chain_fill_array(p, n, safe_anim); break;
    case 697: chain_fill_array(p, n, safe_ik); break;
    case 735: chain_fill_array(p, n, safe_tr); break;
    case 782: chain_fill_array(p, n, safe_path); break;
    case 41: chain_fill_array(p, n, safe_tl); break;
    default: break;
    }
    chain_allocs[chain_na].p = p;
    chain_allocs[chain_na].bytes = n;
    chain_allocs[chain_na].line = line;
    chain_allocs[chain_na].tag = tag;
    ++chain_na;
    return p;
}

static void chain_free(void* p)
{
    CK(chain_nf < 1024, "chain free roster");
    chain_frees[chain_nf++] = p;
}

static unsigned alloc_line_count(uint32_t line)
{
    unsigned i, c = 0;
    for (i = 0; i < chain_na; ++i) if (chain_allocs[i].line == line) ++c;
    return c;
}
static uint32_t alloc_line_bytes(uint32_t line)
{
    unsigned i;
    for (i = 0; i < chain_na; ++i) if (chain_allocs[i].line == line)
        return chain_allocs[i].bytes;
    fail("missing allocation line");
    return 0;
}
/* first allocation index of a line: the chain's stage order is read off the
 * MALLOC line sequence (meta 607/608, bones 615, slots 651, ik 697, transform
 * 735, path 782, skins 839, events 1028, animations 1043) */
static int chain_line_first(uint32_t line, int* out)
{
    unsigned i;
    for (i = 0; i < chain_na; ++i)
        if (chain_allocs[i].line == line) { *out = (int)i; return 1; }
    return 0;
}

static int chain_first(uint32_t line)
{
    int at = -1;
    (void)chain_line_first(line, &at);
    return at;
}

/* Same-slot check with a message that NAMES the two stages, so an exchanged
 * stage pair is reported as "X must precede Y" instead of a generic failure. */
static void expect_precedes(uint32_t before, uint32_t after,
                            const char* message)
{
    int a = chain_first(before);
    int b = chain_first(after);
    CK(a >= 0 && b >= 0, "stage order: both stages produced their own array");
    CK(a < b, message);
}

/*
 * The chain's order as OBSERVABLE SIDE EFFECTS, not as source line order:
 *   - every stage's own array allocation (line 607 meta ... 1043 animations),
 *     each of which is emitted by exactly one segment module;
 *   - the synthetic creator call sequence 'B'*3 'S' 'I' 'X' 'P', i.e. the
 *     order in which the bone, slot, ik, transform and path records are made.
 * An exchanged pair is therefore refused by name, even when both stages would
 * succeed on their own.
 */
static void expect_stage_order(void)
{
    expect_precedes(607u, 615u, "stage order: meta must precede bones");
    expect_precedes(615u, 651u, "stage order: bones must precede slots");
    expect_precedes(651u, 697u, "stage order: slots must precede ik");
    expect_precedes(697u, 735u, "stage order: ik must precede transform");
    expect_precedes(735u, 782u, "stage order: transform must precede path");
    expect_precedes(782u, 839u, "stage order: path must precede skins");
    expect_precedes(839u, 1028u, "stage order: skins must precede events");
    expect_precedes(1028u, 1043u, "stage order: events must precede animations");
    CK(strcmp(creator_log, "BBBSIXP") == 0,
       "stage order: creator calls run bones, slots, ik, transform, path");
}
static unsigned chain_free_hits(const void* p)
{
    unsigned i, c = 0;
    for (i = 0; i < chain_nf; ++i) if (chain_frees[i] == p) ++c;
    return c;
}

static void chain_begin(const char* name)
{
    test = name;
    used = 0;                       /* fixture heap cursor (mesh fixture) */
    chain_na = chain_nf = 0;
    creator_n = 0;
    creator_log[0] = 0;
    memset(&obs, 0, sizeof obs);
    memset(&g_self, 0, sizeof g_self);
    memset(&att_loader, 0, sizeof att_loader);
    memset(&att_loader_vtable, 0, sizeof att_loader_vtable);
    memset(made_bone, 0, sizeof made_bone);
    memset(made_slot, 0, sizeof made_slot);
    memset(made_ik, 0, sizeof made_ik);
    memset(made_tr, 0, sizeof made_tr);
    memset(made_path, 0, sizeof made_path);
    memset(slot_name_copy, 0, sizeof slot_name_copy);
    memset(slot_attachment_copy, 0, sizeof slot_attachment_copy);
    memset(configure_seen, 0, sizeof configure_seen);
    memset(answered, 0, sizeof answered);

    g_self.scale = bits(2.0f);      /* every scaled field below uses 2 */
    g_self.loader = (uint32_t)(uintptr_t)&att_loader;
    att_loader.vtable = &att_loader_vtable;
    att_loader_vtable.createAttachment = att_loader_create;
    att_loader_vtable.configureAttachment = att_loader_configure;

    g_tree = 0;
    g_data_out = 0;
    json_create_calls = 0;
    json_create_arg = 0;
    json_create_fail = 0;
    g_parse_error = "parse failed at 1";
    locale_calls = 0;
    locale_null = 0;
    locale_calls_at_create = 0;
    memset(locale_args, 0, sizeof locale_args);
    loader_mode = 0;
    cos_calls = 0;
    sin_calls = 0;
    cos_arg_bits = 0;
    sin_arg_bits = 0;
    create_calls = 0;
    memset(create_type, 0xff, sizeof create_type);
    memset(create_name, 0, sizeof create_name);
    memset(create_path, 0, sizeof create_path);
    memset(create_skin, 0, sizeof create_skin);
    configure_calls = 0;
    answered_n = 0;
    report_count = 0;
    reported[0] = 0;
    report_format[0] = 0;

    knob_parent = "root";
    knob_slot_bone = "root";
    knob_ik_bone0 = "root";
    knob_ik_target = "arm";
    knob_tr_bone0 = "hand";
    knob_tr_target = "arm";
    knob_path_bone0 = "root";
    knob_path_target = "slotA";
    knob_att_type = "region";
    knob_link_skin = 0;
    tree_extra_linked = 0;

    safe_tl[1] = (uint32_t)(uintptr_t)safe_tl_vtable;
    safe_tl_vtable[0] = 0;
    safe_tl_vtable[1] = (uint32_t)(uintptr_t)tl_dispose_probe;

    _setDebugMalloc(chain_alloc);
    _setFree(chain_free);
}

/* ================================================================== */
/* named boundary providers                                            */
/* ================================================================== */

Json* Json_create(const char* text)
{
    ++json_create_calls;
    json_create_arg = text;
    locale_calls_at_create = locale_calls;
    if (json_create_fail) {
        readSkeletonData_rootSlot = 0;
        return 0;
    }
    readSkeletonData_rootSlot = g_tree;      /* 0x28b8ac str r0,[sp,#0x24] */
    return g_tree;
}

const char* Json_getError(void)
{
    return g_parse_error;
}

char* _setlocale(int category, const char* locale)
{
    CK(category == 1, "LC_NUMERIC is bionic category 1");
    if (locale_calls < 8) locale_args[locale_calls] = locale;
    ++locale_calls;
    if (locale == 0) return locale_null ? (char*)0 : (char*)"C";
    return (char*)"C";
}

char* _strdup(const char* s)
{
    uint32_t n = (uint32_t)strlen(s) + 1u;
    char* p = _malloc(n, CHAIN_TAG, 91u);
    strcpy(p, s);
    return p;
}

size_t _strlen(const char* s) { return strlen(s); }

/* _spAttachmentLoader_setUnknownTypeError 0x284e68 formats the TYPE WORD with
 * sprintf(buffer,"%d",type).  Only "%d" is reachable; anything else is copied
 * verbatim.  No type > 4 can reach it on this chain (the dispatch never asks
 * for one), so this is a link-completing provider, not a semantic model. */
int sprintf(char* dst, const char* fmt, ...)
{
    va_list ap;
    int n = 0;
    va_start(ap, fmt);
    for (; *fmt != 0; ++fmt) {
        if (fmt[0] == '%' && fmt[1] == 'd') {
            int32_t v = va_arg(ap, int32_t);
            uint32_t u = (v < 0) ? (uint32_t)(-(int64_t)v) : (uint32_t)v;
            char tmp[12];
            int k = 0;
            if (v < 0) dst[n++] = '-';
            do { tmp[k++] = (char)('0' + (u % 10u)); u /= 10u; } while (u != 0u);
            while (k != 0) dst[n++] = tmp[--k];
            ++fmt;
        } else {
            dst[n++] = *fmt;
        }
    }
    dst[n] = 0;
    va_end(ap);
    return n;
}
char* _strcpy(char* d, const char* s) { return strcpy(d, s); }
int _strcmp(const char* a, const char* b) { return strcmp(a, b); }

/* Core-register DOUBLE imports the real geometry/UV bodies call.  The E2E
 * region has rotation 0, so cos(0)=1 and sin(0)=0 are the true values. */
__attribute__((no_stack_protector)) double cos(double angle)
{
    __builtin_memcpy(&cos_arg_bits, &angle, 8);
    ++cos_calls;
    return 1.0;
}
__attribute__((no_stack_protector)) double sin(double angle)
{
    __builtin_memcpy(&sin_arg_bits, &angle, 8);
    ++sin_calls;
    return 0.0;
}

/* ---- record creators (declared synthetic boundaries) ---------------- */

typedef struct ch_bone {
    int32_t index;
    char* name;
    void* parent;
    float length, x, y, rotation, scaleX, scaleY, shearX, shearY;
    int32_t inheritRotation, inheritScale;
} ch_bone;

typedef struct ch_slot {
    int32_t index;
    char* name;
    void* bone;
    char* attachment;
    float r, g, b, a;
    int32_t blend;
} ch_slot;

typedef struct ch_ik {
    char* name;
    int32_t bonesCount;
    void* bones;
    void* target;
    int32_t bendDirection;
    float mix;
} ch_ik;

typedef struct ch_tr {
    char* name;
    int32_t bonesCount;
    void* bones;
    void* target;
    float rotateMix, translateMix, scaleMix, shearMix;
    float rotation, x, y, scaleX, scaleY, shearY;
} ch_tr;

typedef struct ch_path {
    char* name;
    int32_t bonesCount;
    void* bones;
    void* target;
    int32_t positionMode, spacingMode, rotateMode;
    float rotation, position, spacing, rotateMix, translateMix;
} ch_path;

_Static_assert(sizeof(ch_bone) == 0x34, "spBoneData is 52 B");
_Static_assert(sizeof(ch_slot) == 0x24, "slot record covers +0x20 blend");
_Static_assert(sizeof(ch_ik) == 0x18, "ik record covers +0x14 mix");
_Static_assert(sizeof(ch_tr) == 0x38, "transform record covers +0x34 shearY");
_Static_assert(sizeof(ch_path) == 0x30, "path record covers +0x2c translateMix");

static char* copy_string(const char* s, uint32_t line)
{
    uint32_t n = (uint32_t)strlen(s) + 1u;
    char* p = _malloc(n, CHAIN_TAG, line);
    strcpy(p, s);
    return p;
}

spBoneData* spBoneData_create(int index, const char* name, const spBoneData* parent)
{
    ch_bone* b = (ch_bone*)_calloc(1, sizeof(ch_bone), CHAIN_TAG, 100u);
    b->index = index;
    chain_log('B');
    b->name = copy_string(name, 101u);
    b->parent = (void*)parent;
    if ((unsigned)index < 4) made_bone[index] = b;
    return (spBoneData*)b;
}

void* spSlotData_create(int index, const char* name, void* bone)
{
    ch_slot* s = (ch_slot*)_calloc(1, sizeof(ch_slot), CHAIN_TAG, 102u);
    s->index = index;
    chain_log('S');
    s->name = copy_string(name, 103u);
    s->bone = bone;
    s->r = s->g = s->b = s->a = 1.0f;
    if ((unsigned)index < 2) {
        made_slot[index] = s;
        strcpy(slot_name_copy[index], name);
    }
    return s;
}

void spSlotData_setAttachmentName(void* slotData, const char* name)
{
    ch_slot* s = (ch_slot*)slotData;
    _free(s->attachment);
    s->attachment = copy_string(name, 104u);
    if (s->index >= 0 && s->index < 2)
        strcpy(slot_attachment_copy[s->index], name);
}

void* spIkConstraintData_create(const char* name)
{
    ch_ik* c = (ch_ik*)_calloc(1, sizeof(ch_ik), CHAIN_TAG, 105u);
    chain_log('I');
    c->name = copy_string(name, 106u);
    if (made_ik[0] == 0) made_ik[0] = c; else made_ik[1] = c;
    return c;
}

void* spTransformConstraintData_create(const char* name)
{
    ch_tr* c = (ch_tr*)_calloc(1, sizeof(ch_tr), CHAIN_TAG, 107u);
    chain_log('X');
    c->name = copy_string(name, 108u);
    if (made_tr[0] == 0) made_tr[0] = c; else made_tr[1] = c;
    return c;
}

void* spPathConstraintData_create(const char* name)
{
    ch_path* c = (ch_path*)_calloc(1, sizeof(ch_path), CHAIN_TAG, 109u);
    chain_log('P');
    c->name = copy_string(name, 110u);
    if (made_path[0] == 0) made_path[0] = c; else made_path[1] = c;
    return c;
}

/* 0x28b070, 92 B: no module recovered it; same count/array/name scan shape as
 * c/skeleton_find's findSlotIndex, but it returns the record. */
void* spSkeletonData_findSlot(void* data_raw, const char* name)
{
    int32_t count;
    void** table;
    int32_t i;
    __builtin_memcpy(&count, (char*)data_raw + 0x18, 4);
    if (count <= 0) return 0;
    __builtin_memcpy(&table, (char*)data_raw + 0x1c, 4);
    for (i = 0; i < count; ++i) {
        void* rec = table[i];
        const char* n;
        __builtin_memcpy(&n, (char*)rec + 4, 4);
        if (strcmp(n, name) == 0) return rec;
    }
    return 0;
}

/* ---- attachment loader + vtable ------------------------------------ */

static spAttachment* att_loader_create(spAttachmentLoader* self, spSkin* skin,
                                   int32_t type, const char* name,
                                   const char* path)
{
    if (create_calls < 4) {
        create_type[create_calls] = type;
        create_name[create_calls] = name;
        create_path[create_calls] = path;
        create_skin[create_calls] = skin;
    }
    ++create_calls;
    if (loader_mode == 1) return 0;                 /* silent skip */
    if (loader_mode == 2) {                         /* loader reports */
        _spAttachmentLoader_setError(self, "loader boom", "detail");
        return 0;
    }
    switch (type) {
    case 0: {
        spRegionAttachment* r = spRegionAttachment_create(name);
        answered[answered_n++] = &r->super;
        return &r->super;
    }
    case 1: {
        spBoundingBoxAttachment* b = spBoundingBoxAttachment_create(name);
        answered[answered_n++] = &b->super.super;
        return &b->super.super;
    }
    case 2:
    case 3: {
        spMeshAttachment* m = spMeshAttachment_create(name);
        answered[answered_n++] = &m->super.super;
        return &m->super.super;
    }
    case 4: {
        spPathAttachment* p = spPathAttachment_create(name);
        answered[answered_n++] = &p->super.super;
        return &p->super.super;
    }
    default:
        _spAttachmentLoader_setUnknownTypeError(self, type);
        return 0;
    }
}

static void att_loader_configure(spAttachmentLoader* self, spAttachment* a)
{
    CK(self == &att_loader, "configure receives the parser's loader");
    if (configure_calls < 4) configure_seen[configure_calls] = a;
    ++configure_calls;
}

/* ================================================================== */
/* the JSON tree                                                       */
/* ================================================================== */

static Json* jarr(const char* key, uint32_t declared)
{
    Json* n = node(key);
    n->unk_0c = declared;
    return n;
}
static Json* names2(const char* key, const char* a, const char* b)
{
    Json* n = jarr(key, 2);
    Json* c = node(0);
    c->string_value = a;
    add(n, c);
    c = node(0);
    c->string_value = b;
    add(n, c);
    return n;
}
static Json* names1(const char* key, const char* a)
{
    Json* n = jarr(key, 1);
    Json* c = node(0);
    c->string_value = a;
    add(n, c);
    return n;
}

/* one skeleton JSON tree; every error test moves a knob afterwards */
static Json* build_tree(void)
{
    Json* tree = node(0);

    /* skeleton ------------------------------------------------------- */
    {
        Json* sk = node("skeleton");
        add(sk, string("hash", "abc123"));
        add(sk, string("spine", "3.8.99"));
        add(sk, node("width"));
        add(sk, node("height"));
        {
            Json* w = Json_getItem(sk, "width"); w->float_value = 100.0f;
            w = Json_getItem(sk, "height"); w->float_value = 200.0f;
        }
        add(tree, sk);
    }

    /* bones: root <- arm <- hand ------------------------------------- */
    {
        Json* bones = jarr("bones", 3);
        Json* b = node("b0");
        add(b, string("name", "root"));
        add(b, node("length")); add(b, node("x")); add(b, node("y"));
        add(b, node("rotation")); add(b, node("scaleX")); add(b, node("scaleY"));
        add(b, node("shearX")); add(b, node("shearY"));
        add(b, node("inheritRotation")); add(b, node("inheritScale"));
        Json_getItem(b, "length")->float_value = 10.0f;
        Json_getItem(b, "x")->float_value = 1.0f;
        Json_getItem(b, "y")->float_value = 2.0f;
        Json_getItem(b, "rotation")->float_value = 30.0f;
        Json_getItem(b, "scaleX")->float_value = 2.0f;
        Json_getItem(b, "scaleY")->float_value = 3.0f;
        Json_getItem(b, "shearX")->float_value = 4.0f;
        Json_getItem(b, "shearY")->float_value = 5.0f;
        add(bones, b);

        b = node("b1");
        add(b, string("name", "arm"));
        add(b, string("parent", knob_parent));
        add(b, node("length"));
        Json_getItem(b, "length")->float_value = 5.0f;
        add(bones, b);

        b = node("b2");
        add(b, string("name", "hand"));
        add(b, string("parent", "arm"));
        add(bones, b);
        add(tree, bones);
    }

    /* slots: one slot on "root" -------------------------------------- */
    {
        Json* slots = jarr("slots", 1);
        Json* s = node("slotA");
        add(s, string("bone", knob_slot_bone));
        add(s, string("name", "slotA"));
        add(s, string("color", "ff000080"));
        add(s, string("attachment", "reg"));
        add(s, string("blend", "additive"));
        add(slots, s);
        add(tree, slots);
    }

    /* ik: two bones, target "arm", bendPositive 0 -------------------- */
    {
        Json* ik = jarr("ik", 1);
        Json* c = node("ik0");
        add(c, string("name", "ikCon"));
        add(c, names2("bones", knob_ik_bone0, "arm"));
        add(c, string("target", knob_ik_target));
        add(c, node("bendPositive"));
        add(c, node("mix"));
        Json_getItem(c, "bendPositive")->int_value = 0;
        Json_getItem(c, "mix")->float_value = 0.5f;
        add(ik, c);
        add(tree, ik);
    }

    /* transform: one bone "hand", target "arm" ----------------------- */
    {
        Json* tr = jarr("transform", 1);
        Json* c = node("t0");
        add(c, string("name", "tCon"));
        add(c, names1("bones", knob_tr_bone0));
        add(c, string("target", knob_tr_target));
        add(c, node("rotation")); add(c, node("x")); add(c, node("y"));
        add(c, node("scaleX")); add(c, node("scaleY")); add(c, node("shearY"));
        add(c, node("rotateMix")); add(c, node("translateMix"));
        add(c, node("scaleMix")); add(c, node("shearMix"));
        Json_getItem(c, "rotation")->float_value = 5.0f;
        Json_getItem(c, "x")->float_value = 1.0f;
        Json_getItem(c, "y")->float_value = 2.0f;
        Json_getItem(c, "scaleX")->float_value = 2.0f;
        Json_getItem(c, "scaleY")->float_value = 3.0f;
        Json_getItem(c, "shearY")->float_value = 4.0f;
        Json_getItem(c, "rotateMix")->float_value = 0.25f;
        Json_getItem(c, "translateMix")->float_value = 0.5f;
        Json_getItem(c, "scaleMix")->float_value = 0.75f;
        Json_getItem(c, "shearMix")->float_value = 0.125f;
        add(tr, c);
        add(tree, tr);
    }

    /* path: one bone "root", target slot "slotA" --------------------- */
    {
        Json* p = jarr("path", 1);
        Json* c = node("p0");
        add(c, string("name", "pCon"));
        add(c, names1("bones", knob_path_bone0));
        add(c, string("target", knob_path_target));
        add(c, string("positionMode", "fixed"));
        add(c, string("spacingMode", "fixed"));
        add(c, string("rotateMode", "chain"));
        add(c, node("rotation")); add(c, node("position")); add(c, node("spacing"));
        add(c, node("rotateMix")); add(c, node("translateMix"));
        Json_getItem(c, "rotation")->float_value = 0.0f;
        Json_getItem(c, "position")->float_value = 3.0f;
        Json_getItem(c, "spacing")->float_value = 4.0f;
        Json_getItem(c, "rotateMix")->float_value = 0.5f;
        Json_getItem(c, "translateMix")->float_value = 0.25f;
        add(p, c);
        add(tree, p);
    }

    /* skins: default -> slotA -> region + mesh (+ optional linkedmesh)- */
    {
        Json* skins = jarr("skins", 1);
        Json* def = node("default");
        Json* slot = node("slotA");

        Json* reg = node("reg");
        add(reg, string("name", "reg"));
        add(reg, string("path", "asset"));
        add(reg, string("type", knob_att_type));
        add(reg, node("x")); add(reg, node("y"));
        add(reg, node("scaleX")); add(reg, node("scaleY"));
        add(reg, node("rotation")); add(reg, node("width")); add(reg, node("height"));
        add(reg, string("color", "ffffffff"));
        Json_getItem(reg, "x")->float_value = 1.0f;
        Json_getItem(reg, "y")->float_value = 2.0f;
        Json_getItem(reg, "scaleX")->float_value = 1.0f;
        Json_getItem(reg, "scaleY")->float_value = 1.0f;
        Json_getItem(reg, "rotation")->float_value = 0.0f;
        Json_getItem(reg, "width")->float_value = 10.0f;
        Json_getItem(reg, "height")->float_value = 20.0f;
        add(slot, reg);

        Json* mesh = node("meshA");
        add(mesh, string("name", "meshA"));
        add(mesh, string("type", "mesh"));
        add(mesh, string("color", "80ff00ff"));
        add(mesh, node("width")); add(mesh, node("height"));
        Json_getItem(mesh, "width")->float_value = 8.0f;
        Json_getItem(mesh, "height")->float_value = 8.0f;
        {
            const int32_t tri[3] = {0, 1, 2};
            const float uv[6] = {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f};
            const float xy[6] = {0.0f, 0.0f, 1.0f, 1.0f, 2.0f, 2.0f};
            add(mesh, ints("triangles", tri, 3, 3));
            add(mesh, floats("uvs", uv, 6, 6));
            add(mesh, floats("vertices", xy, 6, 6));
        }
        add(mesh, node("hull"));
        Json_getItem(mesh, "hull")->int_value = 3;
        add(slot, mesh);

        if (tree_extra_linked) {
            Json* lm = node("linkedA");
            add(lm, string("name", "linkedA"));
            add(lm, string("type", "linkedmesh"));
            add(lm, string("parent", "P"));
            if (knob_link_skin != 0) add(lm, string("skin", knob_link_skin));
            add(lm, node("deform"));
            Json_getItem(lm, "deform")->int_value = 1;
            add(slot, lm);
        }

        add(def, slot);
        add(skins, def);
        add(tree, skins);
    }

    /* events -------------------------------------------------------- */
    {
        Json* events = jarr("events", 1);
        Json* e = node("step");
        add(e, node("int")); add(e, node("float")); add(e, string("string", "snd"));
        Json_getItem(e, "int")->int_value = 3;
        Json_getItem(e, "float")->float_value = 1.5f;
        add(events, e);
        add(tree, events);
    }

    /* animations: walk -> bones.arm {rotate,translate} + events -------- */
    {
        Json* anims = jarr("animations", 1);
        Json* a = node("walk");
        Json* bones = jarr("bones", 1);
        Json* arm = jarr("arm", 2);

        Json* rot = jarr("rotate", 2);
        Json* f = node(0);
        add(f, node("time")); add(f, node("angle"));
        Json_getItem(f, "time")->float_value = 0.25f;
        Json_getItem(f, "angle")->float_value = 30.0f;
        add(f, jcurve());
        add(rot, f);
        f = node(0);
        add(f, node("time")); add(f, node("angle"));
        Json_getItem(f, "time")->float_value = 0.5f;
        Json_getItem(f, "angle")->float_value = 60.0f;
        add(f, jstepped());
        add(rot, f);
        add(arm, rot);

        Json* trn = jarr("translate", 2);
        f = node(0);
        add(f, node("time")); add(f, node("x")); add(f, node("y"));
        Json_getItem(f, "time")->float_value = 0.375f;
        Json_getItem(f, "x")->float_value = 1.0f;
        Json_getItem(f, "y")->float_value = 2.0f;
        add(trn, f);
        f = node(0);
        add(f, node("time")); add(f, node("x")); add(f, node("y"));
        Json_getItem(f, "time")->float_value = 0.625f;
        Json_getItem(f, "x")->float_value = 3.0f;
        Json_getItem(f, "y")->float_value = 4.0f;
        add(trn, f);
        add(arm, trn);

        add(bones, arm);
        add(a, bones);

        Json* ev = jarr("events", 1);
        f = node(0);
        add(f, string("name", "step"));
        add(f, node("time"));
        Json_getItem(f, "time")->float_value = 0.8f;
        add(ev, f);
        add(a, ev);

        add(anims, a);
        add(tree, anims);
    }

    return tree;
}

/* convenience: build the tree, publish it for Json_create, run the chain */
static spSkeletonData* run_chain(void)
{
    g_tree = build_tree();
    g_data_out = spSkeletonJson_readSkeletonData(&g_self, "{\"skeleton\":{}}");
    return g_data_out;
}

static void expect_report(const char* text, const char* why)
{
    CK(report_count == 1, why);
    CK(strcmp(reported, text) == 0, why);
}

static void expect_parser_error(const char* text, const char* why)
{
    CK(g_self.error != 0, why);
    CK(strcmp((const char*)(uintptr_t)g_self.error, text) == 0, why);
}

static uint32_t dw(const void* p, unsigned off)
{
    uint32_t w;
    __builtin_memcpy(&w, (const char*)p + off, 4);
    return w;
}
static float fw(const void* p, unsigned off)
{
    uint32_t w = dw(p, off);
    float f;
    __builtin_memcpy(&f, &w, 4);
    return f;
}
static const char* pw(const void* p, unsigned off)
{
    uint32_t w = dw(p, off);
    return (const char*)(uintptr_t)w;
}
static void* vp(const void* p, unsigned off)
{
    return (void*)(uintptr_t)dw(p, off);
}

/* ================================================================== */
/* 1. the full chain                                                   */
/* ================================================================== */
static ch_bone* bone_at(spSkeletonData* d, unsigned i)
{
    void** arr = (void**)vp(d, 0x14);
    return (ch_bone*)arr[i];
}
static ch_slot* slot_at(spSkeletonData* d, unsigned i)
{
    void** arr = (void**)vp(d, 0x1c);
    return (ch_slot*)arr[i];
}

static void chain_full_end_to_end(void)
{
    spSkeletonData* d;
    Json* tree;

    chain_begin("chain_full_end_to_end");
    d = run_chain();
    tree = g_tree;

    CK(d != 0, "full chain returns the data record");
    CK(d == g_data_out, "the returned pointer is the created data record");

    /* --- meta ------------------------------------------------------ */
    CK(strcmp(pw(d, 0x00), "3.8.99") == 0, "meta: data+0x00 is the \"spine\" copy");
    CK(strcmp(pw(d, 0x04), "abc123") == 0, "meta: data+0x04 is the \"hash\" copy");
    CK(fw(d, 0x08) == 100.0f && fw(d, 0x0c) == 200.0f,
       "meta: width/height land at +0x08/+0x0c");
    CK(alloc_line_count(607) == 1 && alloc_line_count(608) == 1,
       "meta: each MALLOC_STR runs once (lines 607/608)");

    /* --- bones ----------------------------------------------------- */
    CK(dw(d, 0x10) == 3, "bones: bonesCount is 3");
    CK(alloc_line_count(615) == 1 && alloc_line_bytes(615) == 12,
       "bones: one line-615 array of count*4");
    {
        ch_bone* b0 = bone_at(d, 0);
        ch_bone* b1 = bone_at(d, 1);
        ch_bone* b2 = bone_at(d, 2);
        CK(b0->index == 0 && b1->index == 1 && b2->index == 2,
           "bones: index is the running bonesCount");
        CK(strcmp(b0->name, "root") == 0 && strcmp(b1->name, "arm") == 0 &&
           strcmp(b2->name, "hand") == 0, "bones: names in list order");
        CK(b0->parent == 0 && b1->parent == (void*)b0 && b2->parent == (void*)b1,
           "bones: parent links resolve in list order");
        CK(b0->length == 20.0f && b0->x == 2.0f && b0->y == 4.0f,
           "bones: length/x/y are scaled by json->scale");
        CK(b0->rotation == 30.0f && b0->scaleX == 2.0f && b0->scaleY == 3.0f,
           "bones: rotation/scale are NOT scaled");
        CK(b0->shearX == 4.0f && b0->shearY == 5.0f,
           "bones: shear is stored unscaled");
        CK(b0->inheritRotation == 0 && b0->inheritScale == 0,
           "bones: inheritRotation/inheritScale read the key");
        CK(b1->scaleX == 1.0f && b1->scaleY == 1.0f && b1->inheritRotation == 1,
           "bones: absent keys take the 1.0f/1 defaults");
        CK(b1->length == 10.0f, "bones: second bone length is scaled too");
    }

    /* --- slots ----------------------------------------------------- */
    CK(dw(d, 0x18) == 1, "slots: slotsCount is 1");
    CK(alloc_line_count(651) == 1 && alloc_line_bytes(651) == 4,
       "slots: one line-651 array of count*4");
    {
        ch_slot* s = slot_at(d, 0);
        CK(s == made_slot[0], "slots: the created record is published");
        CK(strcmp(s->name, "slotA") == 0, "slots: name from the \"name\" key");
        CK(s->bone == (void*)bone_at(d, 0), "slots: bone resolved by findBone");
        CK(s->r == 1.0f && s->g == 0.0f && s->b == 0.0f && s->a == 128.0f / 255.0f,
           "slots: color components come from toColor");
        CK(s->blend == 1, "slots: \"additive\" stores blend 1");
        CK(strcmp(s->attachment, "reg") == 0,
           "slots: attachment name from the attachment node's string_value");
    }

    /* --- ik -------------------------------------------------------- */
    CK(dw(d, 0x3c) == 1 && alloc_line_count(697) == 1 &&
       alloc_line_bytes(697) == 4, "ik: count published and count*4 allocated");
    {
        ch_ik* c = ((ch_ik**)vp(d, 0x40))[0];
        void** bones;
        CK(c == made_ik[0], "ik: the constraint record is published");
        CK(strcmp(c->name, "ikCon") == 0, "ik: name from the \"name\" key");
        CK(c->bonesCount == 2 && alloc_line_bytes(705) == 8,
           "ik: bones array is count*4 at line 705");
        bones = (void**)c->bones;
        CK(bones[0] == (void*)bone_at(d, 0) && bones[1] == (void*)bone_at(d, 1),
           "ik: bones resolve through findBone");
        CK(c->target == (void*)bone_at(d, 1), "ik: target is a bone");
        CK(c->bendDirection == -1, "ik: bendPositive 0 becomes -1");
        CK(c->mix == 0.5f, "ik: mix from the key");
    }

    /* --- transform ------------------------------------------------- */
    CK(dw(d, 0x44) == 1 && alloc_line_count(735) == 1,
       "transform: count published and array allocated");
    {
        ch_tr* c = ((ch_tr**)vp(d, 0x48))[0];
        CK(c == made_tr[0], "transform: the constraint record is published");
        CK(c->bonesCount == 1 && ((void**)c->bones)[0] == (void*)bone_at(d, 2),
           "transform: bone resolves to hand");
        CK(c->target == (void*)bone_at(d, 1), "transform: target is a bone");
        CK(c->rotation == 5.0f && c->x == 2.0f && c->y == 4.0f,
           "transform: rotation unscaled, x/y scaled");
        CK(c->scaleX == 2.0f && c->scaleY == 3.0f && c->shearY == 4.0f,
           "transform: scale/shear unscaled");
        CK(c->rotateMix == 0.25f && c->translateMix == 0.5f &&
           c->scaleMix == 0.75f && c->shearMix == 0.125f,
           "transform: the four mixes from the keys");
    }

    /* --- path ------------------------------------------------------ */
    CK(dw(d, 0x4c) == 1 && alloc_line_count(782) == 1,
       "path: count published and array allocated");
    {
        ch_path* c = ((ch_path**)vp(d, 0x50))[0];
        CK(c == made_path[0], "path: the constraint record is published");
        CK(c->bonesCount == 1 && ((void**)c->bones)[0] == (void*)bone_at(d, 0),
           "path: bone resolves to root");
        CK(c->target == (void*)slot_at(d, 0), "path: target is a SLOT");
        CK(c->positionMode == 0 && c->spacingMode == 1 && c->rotateMode == 1,
           "path: fixed/fixed/chain mode words");
        CK(c->rotation == 0.0f && c->position == 6.0f && c->spacing == 8.0f,
           "path: position/spacing scaled only for fixed/length modes");
        CK(c->rotateMix == 0.5f && c->translateMix == 0.25f,
           "path: rotateMix/translateMix from the keys");
    }

    /* --- skins ----------------------------------------------------- */
    CK(dw(d, 0x20) == 1 && alloc_line_count(839) == 1,
       "skins: running count and line-839 array");
    {
        spSkin* skin = ((spSkin**)vp(d, 0x24))[0];
        spSkin* def = (spSkin*)vp(d, 0x28);
        spSkinEntry* e;
        CK(skin != 0 && def == skin, "skins: \"default\" becomes defaultSkin");
        CK(strcmp(skin->name, "default") == 0, "skins: skin name is the JSON key");
        e = skin->entries;
        CK(e != 0 && e->slotIndex == 0 && strcmp(e->name, "meshA") == 0,
           "skins: the mesh attachment is the newest entry");
        e = e->next;
        CK(e != 0 && e->slotIndex == 0 && strcmp(e->name, "reg") == 0,
           "skins: the region attachment is the older entry");
        CK(e->next == 0, "skins: exactly two attachments for one slot");
    }

    /* region attachment (parser window 0x28cdac..0x28cf24) */
    {
        spRegionAttachment* r = (spRegionAttachment*)answered[0];
        CK(dw(r, 0x04) == 0, "region: stored type is 0");
        CK(strcmp(pw(r, 0x00), "reg") == 0, "region: name from the loader");
        CK(r->x == 2.0f && r->y == 4.0f, "region: x/y scaled");
        CK(r->width == 20.0f && r->height == 40.0f, "region: width/height scaled");
        CK(r->scaleX == 1.0f && r->scaleY == 1.0f && r->rotation == 0.0f,
           "region: scale/rotation from the keys");
        CK(r->r == 1.0f && r->g == 1.0f && r->b == 1.0f && r->a == 1.0f,
           "region: color from toColor");
        CK(strcmp((const char*)r->owned_10, "asset") == 0,
           "region: the path string is deep-copied");
        CK(alloc_line_count(891) == 1, "region: one line-891 path copy");
        CK(cos_calls == 1 && sin_calls == 1 && cos_arg_bits == 0 && sin_arg_bits == 0,
           "region: updateOffset runs cos/sin once with the zeroed rotation");
    }

    /* mesh attachment (0x28cb20..0x28cc68) */
    {
        spMeshAttachment* m = (spMeshAttachment*)answered[1];
        const float* uvs = (const float*)m->owned_58;
        const float* verts = (const float*)m->super.owned_1c;
        const uint16_t* tri = (const uint16_t*)m->owned_64;
        CK(dw(m, 0x04) == 2, "mesh: stored type is 2");
        CK(m->r == 128.0f / 255.0f && m->g == 1.0f && m->b == 0.0f && m->a == 1.0f,
           "mesh: color from toColor");
        CK(fw(m, 0x8c) == 16.0f && fw(m, 0x90) == 16.0f,
           "mesh: width/height scaled into +0x8c/+0x90");
        CK(m->opaque_60 == 3 && tri[0] == 0 && tri[1] == 1 && tri[2] == 2,
           "mesh: triangle count and values");
        CK(alloc_line_count(935) == 1 && alloc_line_bytes(935) == 6,
           "mesh: triangles are count<<1 bytes at line 935");
        CK(uvs[0] == 0.0f && uvs[2] == 1.0f && uvs[5] == 1.0f,
           "mesh: raw uvs copied");
        CK(alloc_line_count(941) == 1 && alloc_line_bytes(941) == 24,
           "mesh: uvs are count<<2 bytes at line 941");
        CK(m->super.worldVerticesLength == 6 && m->super.opaque_18 == 6 &&
           m->super.opaque_10 == 0,
           "mesh: readVertices takes the unweighted branch");
        CK(verts[0] == 0.0f && verts[2] == 2.0f && verts[4] == 4.0f &&
           verts[5] == 4.0f, "mesh: vertices are scaled by json->scale");
        CK(m->opaque_78 == 3, "mesh: hull is the raw integer");
        CK(m->owned_88 == 0 && m->opaque_84 == 0, "mesh: absent edges stay empty");
        CK(m->parentMesh == 0, "mesh: unlinked mesh has no parent");
    }
    CK(create_calls == 2, "skins: exactly two createAttachment calls");
    CK(create_type[0] == 0 && strcmp(create_name[0], "reg") == 0 &&
       strcmp(create_path[0], "asset") == 0,
       "skins: the region call carries type 0, its \"name\" and its \"path\"");
    CK(create_type[1] == 2 && strcmp(create_name[1], "meshA") == 0 &&
       strcmp(create_path[1], "meshA") == 0,
       "skins: the mesh call carries type 2 and a path defaulting to the name");
    CK(create_skin[0] == ((spSkin**)vp(d, 0x24))[0] &&
       create_skin[1] == ((spSkin**)vp(d, 0x24))[0],
       "skins: createAttachment receives the skin being filled");
    CK(json_create_arg != 0 && strcmp(json_create_arg, "{\"skeleton\":{}}") == 0,
       "entry: Json_create receives the loader text");
    CK(locale_calls_at_create == 3 && locale_args[1] == 0 &&
       locale_args[2] != 0 && strcmp(locale_args[2], "C") == 0,
       "entry: the guard probes, saves, then installs \"C\" before Json_create");
    CK(configure_calls == 2, "skins: configure ran for both attachments");
    CK(configure_seen[0] == answered[0] && configure_seen[1] == answered[1],
       "skins: configure receives the created attachment, in order");

    /* --- events ---------------------------------------------------- */
    CK(dw(d, 0x2c) == 1 && alloc_line_count(1028) == 1,
       "events: count published and line-1028 array");
    {
        spEventData* e = ((spEventData**)vp(d, 0x30))[0];
        CK(strcmp(e->name, "step") == 0, "events: name is the JSON member key");
        CK(e->intValue == 3 && e->floatValue == 1.5f,
           "events: int/float values");
        CK(strcmp(e->stringValue, "snd") == 0, "events: string value");
        CK(alloc_line_count(1034) == 1 && alloc_line_bytes(1034) == 4,
           "events: string deep copy is strlen+1 at line 1034");
    }

    /* --- animations ------------------------------------------------ */
    CK(dw(d, 0x34) == 1 && alloc_line_count(1043) == 1,
       "animations: animationsCount and the line-1043 array");
    {
        spAnimation* a = ((spAnimation**)vp(d, 0x38))[0];
        CK(strcmp(a->name, "walk") == 0, "animations: name is the JSON member key");
        CK(obs.acreate_n == 1 && obs.acreate_count[0] == 3,
           "animations: B4 hands spAnimation_create the asymmetric sum "
           "(2 bone timelines + 1 event = 3)");
        CK(a->timelineCount == 3, "animations: three timelines published");
        CK(fw(a, 0x04) == 0.8f, "animations: duration is the max last frame time");
        CK(obs.create_n == 3 && obs.creates[0] == 'R' && obs.creates[1] == 'T' &&
           obs.creates[2] == 'E',
           "animations: rotate, translate then event timeline creation order");
        CK(obs.curve_n == 2 && obs.curve_kind[0] == 2 && obs.curve_kind[1] == 1,
           "animations: array curve then stepped curve on the rotate frames");
        CK(obs.curve_frame[0] == 0 && obs.curve_frame[1] == 1,
           "animations: curve calls carry the frame index");
        CK(obs.curve_args[0][0] == bits(0.125f) && obs.curve_args[0][3] == bits(0.5f),
           "animations: the four curve control values");
        CK(obs.devents_n == 1 && obs.devents_data[0] == (void*)((spEventData**)vp(d, 0x30))[0],
           "animations: the event timeline frame binds the EventData record");
        CK(obs.devents_time[0] == bits(0.8f), "animations: event frame time");
    }

    /* --- the single chain order ------------------------------------- */
    expect_stage_order();

    /* --- lifetimes -------------------------------------------------- */
    CK(chain_free_hits(tree) == 1, "B18: the root tree is disposed exactly once");
    CK(chain_free_hits(d) == 0, "success: the data record is NOT disposed");
    CK(g_self.error == 0, "success: parser error stays cleared");
    CK(json_create_calls == 1, "entry: Json_create runs exactly once");

    pass("chain_full_end_to_end");
}

/* ================================================================== */
/* 2. every error tail the segment modules report as a code            */
/* ================================================================== */

/* the one spSkeletonData record this run created (SkeletonData.c line 37) */
static const char* const SPINE_DATA_TAG =
    "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonData.c";
static void* chain_data_record(void)
{
    unsigned i;
    for (i = 0; i < chain_na; ++i)
        if (chain_allocs[i].line == 37 && chain_allocs[i].tag != 0 &&
            strcmp(chain_allocs[i].tag, SPINE_DATA_TAG) == 0)
            return chain_allocs[i].p;
    return 0;
}

/* message composer: "tag: what" into one of four rotating buffers */
static char why_buf[4][128];
static int why_slot;
static const char* why(const char* tag, const char* what)
{
    char* d;
    why_slot = (why_slot + 1) & 3;
    d = why_buf[why_slot];
    while (*tag != 0) *d++ = *tag++;
    *d++ = ':';
    *d++ = ' ';
    while (*what != 0) *d++ = *what++;
    *d = 0;
    return why_buf[why_slot];
}

/* one disposition shared by the ten dispose-bearing tails */
static void expect_error_epilogue(spSkeletonData* d, Json* tree,
                                  const char* text, const char* tag)
{
    CK(d == 0, why(tag, "the loader returns NULL"));
    expect_report(text, why(tag, "one report with the exact literal"));
    expect_parser_error(text, why(tag, "json->error holds the formatted message"));
    CK(chain_data_record() != 0, why(tag, "the data record was created"));
    CK(chain_free_hits(chain_data_record()) == 1,
       why(tag, "dispose(data) runs exactly once"));
    CK(chain_free_hits(tree) == 1, why(tag, "setError disposes the root once"));
}

/* 0x28bf28..0x28bf58: the parent-bone tail the bones module reports as 0 */
static void chain_error_parent_bone(void)
{
    spSkeletonData* d;

    chain_begin("chain_error_parent_bone");
    knob_parent = "ghost";
    d = run_chain();
    expect_error_epilogue(d, g_tree, "Parent bone not found: ghost", "parent-bone");
    CK(chain_free_hits((void*)made_bone[0]) == 1,
       "parent-bone: the bones already created are disposed by the tail");
    pass("chain_error_parent_bone");
}

/* 0x28bf00..0x28bf24: the ik "IK bone not found" tail */
static void chain_error_ik_bone(void)
{
    spSkeletonData* d;
    chain_begin("chain_error_ik_bone");
    knob_ik_bone0 = "ghost";
    d = run_chain();
    expect_error_epilogue(d, g_tree, "IK bone not found: ghost", "ik-bone");
    CK(create_calls == 0, "ik-bone: the chain never reaches the skins window");
    pass("chain_error_ik_bone");
}

/* 0x28bfa8 beq 0x28cf3c: the glue's ik "Target bone not found" block */
static void chain_error_ik_target(void)
{
    spSkeletonData* d;
    chain_begin("chain_error_ik_target");
    knob_ik_target = "ghost";
    d = run_chain();
    expect_error_epilogue(d, g_tree, "Target bone not found: ghost", "ik-target");
    pass("chain_error_ik_target");
}

/* 0x28c104..0x28c12c: the transform "Transform bone not found" tail */
static void chain_error_transform_bone(void)
{
    spSkeletonData* d;
    chain_begin("chain_error_transform_bone");
    knob_tr_bone0 = "ghost";
    d = run_chain();
    expect_error_epilogue(d, g_tree, "Transform bone not found: ghost", "tr-bone");
    pass("chain_error_transform_bone");
}

/* 0x28c154 beq 0x28d144 */
static void chain_error_transform_target(void)
{
    spSkeletonData* d;
    chain_begin("chain_error_transform_target");
    knob_tr_target = "ghost";
    d = run_chain();
    expect_error_epilogue(d, g_tree, "Target bone not found: ghost", "tr-target");
    pass("chain_error_transform_target");
}

/* 0x28c384..0x28c3b0 */
static void chain_error_path_bone(void)
{
    spSkeletonData* d;
    chain_begin("chain_error_path_bone");
    knob_path_bone0 = "ghost";
    d = run_chain();
    expect_error_epilogue(d, g_tree, "Path bone not found: ghost", "path-bone");
    pass("chain_error_path_bone");
}

/* 0x28c3fc beq 0x28d170 */
static void chain_error_path_target(void)
{
    spSkeletonData* d;
    chain_begin("chain_error_path_target");
    knob_path_target = "ghost";
    d = run_chain();
    expect_error_epilogue(d, g_tree, "Target slot not found: ghost", "path-target");
    pass("chain_error_path_target");
}

/* 0x28bda4..0x28bdc8: the slots module emits its own tail; the assembly must
 * not add a second dispose or a second report */
static void chain_error_slot_bone(void)
{
    spSkeletonData* d;
    chain_begin("chain_error_slot_bone");
    knob_slot_bone = "ghost";
    d = run_chain();
    expect_error_epilogue(d, g_tree, "Slot bone not found: ghost", "slot-bone");
    CK(alloc_line_count(651) == 1 && alloc_line_bytes(651) == 4,
       "slot-bone: the slots array was already published before the failure");
    pass("chain_error_slot_bone");
}

/* 0x28c79c bne 0x28e7f4: the out-of-window "Unknown attachment type" tail */
static void chain_error_unknown_attachment(void)
{
    spSkeletonData* d;
    chain_begin("chain_error_unknown_attachment");
    knob_att_type = "point";
    d = run_chain();
    expect_error_epilogue(d, g_tree, "Unknown attachment type: point", "unknown-att");
    CK(create_calls == 0,
       "unknown-att: the dispatch fails before createAttachment is called");
    pass("chain_error_unknown_attachment");
}

/* 0x28cf74 beq 0x28cc7c: createAttachment NULL with no loader error is a
 * silent skip — the chain still succeeds and the skin stays empty */
static void chain_attachment_create_null_silent(void)
{
    spSkeletonData* d;
    chain_begin("chain_attachment_create_null_silent");
    loader_mode = 1;
    d = run_chain();
    CK(d != 0, "null-create: the chain succeeds");
    CK(create_calls == 2, "null-create: both attachments were attempted");
    CK(dw(d, 0x20) == 1, "null-create: the skin is still counted");
    CK(((spSkin*)((spSkin**)vp(d, 0x24))[0])->entries == 0,
       "null-create: the skin has no entries");
    CK(report_count == 0, "null-create: the skip is silent");
    CK(chain_free_hits(g_tree) == 1, "null-create: the root is disposed once");
    pass("chain_attachment_create_null_silent");
}

/* 0x28cf78..0x28cfa0: the loader's error pair is the report text+argument */
static void chain_error_loader_report(void)
{
    spSkeletonData* d;
    chain_begin("chain_error_loader_report");
    loader_mode = 2;
    d = run_chain();
    expect_error_epilogue(d, g_tree, "loader boomdetail", "loader-report");
    pass("chain_error_loader_report");
}

/* 0x28cd48..0x28cd60: "Skin not found" with root = 0 -> the original leaks
 * the tree.  The assembly must keep the leak. */
static void chain_error_linked_skin_leak(void)
{
    spSkeletonData* d;
    chain_begin("chain_error_linked_skin_leak");
    tree_extra_linked = 1;
    knob_link_skin = "ghost";
    d = run_chain();
    CK(d == 0, "linked-skin: the postpass returns NULL");
    expect_report("Skin not found: ghost", "linked-skin: one report with the literal");
    expect_parser_error("Skin not found: ghost", "linked-skin: json->error");
    CK(chain_free_hits(chain_data_record()) == 1, "linked-skin: data disposed once");
    CK(chain_free_hits(g_tree) == 0,
       "linked-skin: setError got root = 0, so the tree LEAKS (original quirk)");
    pass("chain_error_linked_skin_leak");
}

/* 0x28e880..0x28e8ac: "Parent mesh not found" also passes root = 0 */
static void chain_error_linked_parent_leak(void)
{
    spSkeletonData* d;
    chain_begin("chain_error_linked_parent_leak");
    tree_extra_linked = 1;
    d = run_chain();
    CK(d == 0, "linked-parent: the postpass returns NULL");
    expect_report("Parent mesh not found: P", "linked-parent: one report with the literal");
    CK(chain_free_hits(chain_data_record()) == 1, "linked-parent: data disposed once");
    CK(chain_free_hits(g_tree) == 0,
       "linked-parent: setError got root = 0, so the tree LEAKS (original quirk)");
    pass("chain_error_linked_parent_leak");
}

/* 0x28c3b4..0x28c3d8: Json_create returned NULL */
static void chain_json_create_failure(void)
{
    spSkeletonData* d;
    chain_begin("chain_json_create_failure");
    json_create_fail = 1;
    g_parse_error = "expected value at 1";
    d = run_chain();
    CK(d == 0, "json-failure: the loader returns NULL");
    expect_report("Invalid skeleton JSON: expected value at 1",
                  "json-failure: message plus Json_getError()");
    expect_parser_error("Invalid skeleton JSON: expected value at 1",
                        "json-failure: json->error");
    CK(json_create_calls == 1, "json-failure: Json_create ran once");
    CK(readSkeletonData_rootSlot == 0, "json-failure: the root slot stays NULL");
    CK(chain_data_record() == 0, "json-failure: no data record was created");
    CK(chain_free_hits(g_tree) == 0, "json-failure: nothing disposed the tree");
    pass("chain_json_create_failure");
}

/* 0x28bf58..0x28bf84: the setlocale(LC_NUMERIC,NULL) fallback */
static void chain_locale_fallback(void)
{
    spSkeletonData* d;
    chain_begin("chain_locale_fallback");
    locale_null = 1;
    d = run_chain();
    CK(d != 0, "locale-fallback: the chain still succeeds");
    CK(locale_calls == 4, "locale-fallback: probe, C, entry save, reset");
    CK(locale_args[0] == 0 && locale_args[1] != 0 &&
       strcmp(locale_args[1], "C") == 0,
       "locale-fallback: the assembly installs C before entry runs");
    CK(locale_args[2] == 0 && locale_args[3] == 0,
       "locale-fallback: the locale is reset to NULL after the parse (no restore)");
    CK(locale_calls_at_create == 3,
       "locale-fallback: Json_create runs after the C install");
    CK(json_create_calls == 1, "locale-fallback: Json_create runs once");
    pass("chain_locale_fallback");
}

/* nothing but skeleton+bones: every later section must skip cleanly */
static Json* build_minimal_tree(void)
{
    Json* tree = node(0);
    Json* sk = node("skeleton");
    add(sk, string("hash", "mini"));
    add(sk, string("spine", "3.8.99"));
    add(tree, sk);

    Json* bones = jarr("bones", 1);
    Json* b = node("b0");
    add(b, string("name", "root"));
    add(bones, b);
    add(tree, bones);
    return tree;
}

static void chain_optional_sections_absent(void)
{
    spSkeletonData* d;
    chain_begin("chain_optional_sections_absent");
    g_tree = build_minimal_tree();
    d = spSkeletonJson_readSkeletonData(&g_self, "{}");
    CK(d != 0, "minimal: the loader returns the data record");
    CK(dw(d, 0x10) == 1, "minimal: one bone");
    CK(dw(d, 0x18) == 0 && vp(d, 0x1c) == 0, "minimal: no slots count/array");
    CK(dw(d, 0x3c) == 0 && vp(d, 0x40) == 0, "minimal: no ik");
    CK(dw(d, 0x44) == 0 && vp(d, 0x48) == 0, "minimal: no transform");
    CK(dw(d, 0x4c) == 0 && vp(d, 0x50) == 0, "minimal: no path");
    CK(dw(d, 0x20) == 0 && vp(d, 0x24) == 0, "minimal: no skins");
    CK(dw(d, 0x2c) == 0 && vp(d, 0x30) == 0, "minimal: no events");
    CK(dw(d, 0x34) == 0 && vp(d, 0x38) == 0, "minimal: no animations");
    CK(alloc_line_count(651) == 0 && alloc_line_count(839) == 0 &&
       alloc_line_count(1028) == 0 && alloc_line_count(1043) == 0,
       "minimal: the absent sections allocate nothing");
    CK(report_count == 0, "minimal: no report");
    CK(chain_free_hits(g_tree) == 1, "minimal: B18 disposes the root once");
    CK(chain_free_hits(d) == 0, "minimal: the data record is returned alive");
    pass("chain_optional_sections_absent");
}

/* json->scale is read at every scaling site, never cached across calls */
static void chain_scale_read_per_call(void)
{
    spSkeletonData* a;
    spSkeletonData* b;
    float first;

    chain_begin("chain_scale_read_per_call");
    g_self.scale = bits(2.0f);
    g_tree = build_tree();
    a = spSkeletonJson_readSkeletonData(&g_self, "{}");
    CK(a != 0, "scale: first run succeeds");
    first = bone_at(a, 0)->length;
    CK(first == 20.0f, "scale: first run scales by 2");
    spSkeletonData_dispose(a);

    g_self.scale = bits(1.0f);
    g_tree = build_tree();
    b = spSkeletonJson_readSkeletonData(&g_self, "{}");
    CK(b != 0, "scale: second run succeeds");
    CK(bone_at(b, 0)->length == 10.0f,
       "scale: the second run re-reads json->scale (no cached scale)");
    CK(bone_at(b, 0)->x == 1.0f && bone_at(b, 0)->y == 2.0f,
       "scale: x/y follow the new scale");
    spSkeletonData_dispose(b);
    pass("chain_scale_read_per_call");
}

/* the real spSkeletonJson_readSkeletonDataFile (0x28eb40) reaches this
 * assembly through the public symbol */
static const char* const FILE_PAYLOAD = "{\"skeleton\":{\"spine\":\"3.8.99\"}}";
static void* file_buffer;
void* _readFile(const char* path, int32_t* out_size)
{
    uint32_t n = (uint32_t)strlen(FILE_PAYLOAD) + 1u;
    CK(strcmp(path, "x.json") == 0, "file: the path is forwarded");
    file_buffer = _malloc(n, CHAIN_TAG, 0u);
    strcpy((char*)file_buffer, FILE_PAYLOAD);
    *out_size = (int32_t)n;
    return file_buffer;
}

static void chain_file_wrapper(void)
{
    spSkeletonData* d;
    chain_begin("chain_file_wrapper");
    file_buffer = 0;
    g_tree = build_tree();
    d = spSkeletonJson_readSkeletonDataFile(&g_self, "x.json");
    CK(d != 0, "file: the wrapper returns the data record");
    CK(json_create_calls == 1, "file: the wrapper reaches the assembled loader once");
    CK(json_create_arg != 0 && strcmp(json_create_arg, FILE_PAYLOAD) == 0,
       "file: the parsed text is the file buffer");
    CK(file_buffer != 0 && chain_free_hits(file_buffer) == 1,
       "file: the wrapper frees the file buffer once");
    CK(chain_free_hits(g_tree) == 1, "file: the root is disposed once");
    pass("chain_file_wrapper");
}

/* ================================================================== */
/* 0. per-segment attribution                                          */
/* ================================================================== */
/*
 * One discriminating value per segment, each assertion NAMING the module that
 * produced it.  This is the composition-level "broken single segment" control:
 * a wrong semantic constant inside any segment lands on a failure line that
 * says which segment it was.  It runs first so the attribution is the first
 * thing a broken segment can trip.
 */
static void chain_segment_attribution(void)
{
    spSkeletonData* d;

    chain_begin("chain_segment_attribution");
    d = run_chain();
    CK(d != 0, "segment attribution: the assembled chain returns data");
    CK(strcmp(pw(d, 0x00), "3.8.99") == 0 && fw(d, 0x08) == 100.0f,
       "segment spine_read_meta: spine copy and width float");
    CK(dw(d, 0x10) == 3 && vp(d, 0x14) != 0 &&
       ((ch_bone**)vp(d, 0x14))[0] != 0 &&
       bone_at(d, 0)->length == 20.0f && bone_at(d, 0)->scaleX == 2.0f,
       "segment spine_read_bones: scaled length and the +0x1c scaleX slot");
    CK(dw(d, 0x18) == 1 && vp(d, 0x1c) != 0 &&
       ((ch_slot**)vp(d, 0x1c))[0] != 0 &&
       slot_at(d, 0)->blend == 1 && slot_at(d, 0)->r == 1.0f,
       "segment spine_read_slots: additive stores blend 1 and color r");
    CK(vp(d, 0x40) != 0 && ((ch_ik**)vp(d, 0x40))[0] != 0 &&
       ((ch_ik*)((ch_ik**)vp(d, 0x40))[0])->bendDirection == -1,
       "segment spine_read_ik: bendPositive 0 stores -1 at +0x10");
    CK(vp(d, 0x48) != 0 && ((ch_tr**)vp(d, 0x48))[0] != 0 &&
       ((ch_tr*)((ch_tr**)vp(d, 0x48))[0])->scaleMix == 0.75f,
       "segment spine_read_transform: scaleMix at +0x18");
    CK(vp(d, 0x50) != 0 && ((ch_path**)vp(d, 0x50))[0] != 0 &&
       ((ch_path*)((ch_path**)vp(d, 0x50))[0])->spacing == 8.0f,
       "segment spine_read_path: fixed spacing scaled into +0x24");
    CK(vp(d, 0x24) != 0 && ((spSkin**)vp(d, 0x24))[0] != 0 &&
       ((spSkin*)((spSkin**)vp(d, 0x24))[0])->entries != 0,
       "segment spine_read_skins (with skins_glue): the skin has entries");
    CK(answered_n == 2 && ((spRegionAttachment*)answered[0])->width == 20.0f,
       "segment spine_read_region: scaled width");
    CK(answered_n == 2 && ((spMeshAttachment*)answered[1])->opaque_60 == 3,
       "segment spine_read_mesh: triangle count");
    CK(vp(d, 0x30) != 0 && ((spEventData**)vp(d, 0x30))[0] != 0 &&
       ((spEventData**)vp(d, 0x30))[0]->intValue == 3,
       "segment spine_read_animations: event int value");
    CK(obs.acreate_count[0] == 3 && obs.create_n == 3,
       "segment spine_read_animations_loop: B4 sum and three timelines");
    pass("chain_segment_attribution");
}

void chain_start(void)
{
    test = "startup";
    init_heap();
    fixture_install_error_reporter();
    g_tl_vtable[0] = 0;
    g_tl_vtable[1] = (uint32_t)(uintptr_t)tl_dispose_probe;
    chain_segment_attribution();
    chain_full_end_to_end();
    chain_error_parent_bone();
    chain_error_ik_bone();
    chain_error_ik_target();
    chain_error_transform_bone();
    chain_error_transform_target();
    chain_error_path_bone();
    chain_error_path_target();
    chain_error_slot_bone();
    chain_error_unknown_attachment();
    chain_attachment_create_null_silent();
    chain_error_loader_report();
    chain_error_linked_skin_leak();
    chain_error_linked_parent_leak();
    chain_json_create_failure();
    chain_locale_fallback();
    chain_optional_sections_absent();
    chain_scale_read_per_call();
    chain_file_wrapper();
    out("SUMMARY all declared skeleton chain contracts passed\n");
    quit(0);
}
