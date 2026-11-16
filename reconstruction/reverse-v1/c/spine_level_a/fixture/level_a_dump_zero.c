/*
 * level_a_dump.c — rebuild-arm fixture for the Level A function-level
 * differential of spSkeletonJson_readSkeletonData @0x28b84c.
 *
 * qemu-arm executes ONLY the reconstructed C chain (c/spine_read_skeleton and
 * every segment/glue module it links).  The original libyoyo bytes are never
 * loaded here; the original arm is the Unicorn memory oracle in
 * tools/level_a_oracle.py.
 *
 * Synthetic providers (same family the chain checker already uses):
 *   heap/allocator, Json_create/Json_getError, the four local record creators,
 *   spSkeletonData_findSlot, all timeline creators/setters, spAnimation_create,
 *   spEventData_create/spEvent_create, the attachment-loader record/vtable,
 *   libc and the prescribed cos/sin (1.0/0.0 — identical to the oracle arm).
 *
 * The Json tree is NOT written here: build/level_a_tree.inc is generated from
 * tools/level_a_model.py (single source).  The driver also compares the
 * canonical tree bytes this fixture emits with the Python tree's bytes.
 *
 * The dump is a binary record stream on stdout; tools/level_a_dump.py decodes
 * it and the same decoder reads the Unicorn arm, so both arms are diffed in one
 * canonical shape.  See tools/level_a_dump.py for the record grammar.
 */
#define _start mesh_fixture_unused_start
#define free la_mesh_fixture_free
#define memset la_zero_memset
#include "../../spine_read_mesh/fixture/check.c"
#include <stddef.h>
void* la_zero_memset(void* p, int c, size_t n)
{ unsigned char* q = (unsigned char*)p; (void)c; while (n--) *q++ = 0; return p; }

#undef free
#undef _start

/* The chain's dispose path frees far more than the mesh fixture's 256-entry
 * observation roster allows, so this fixture keeps only the one free the
 * Level A contract needs to see: whether Json_dispose(ROOT) ran.  free() is the
 * default slot of c/spine_alloc's _free, so Json_dispose's _free(node) lands
 * here. */
static void* la_root_pointer;
static uint32_t la_root_frees;
void free(void* p) { if (p && p == la_root_pointer) ++la_root_frees; }

#include "spine_read_skeleton.h"
#include "spine_read_entry.h"
#include "../../spine_json_error/src/spine_json_error.h"
#include "../../spine_atlas_attachment/src/spine_atlas_attachment.h"
#include "../../spine_skin/src/spine_skin.h"
#include "../../spine_skeleton_data/src/spine_skeleton_data.h"

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

extern void fixture_install_error_reporter(void);

#define LEVEL_A_TAG "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"

/* ================================================================== */
/* observation                                                         */
/* ================================================================== */
static Json* la_tree;
static spSkeletonData* la_data;
static spSkeletonJson la_self;
static int la_json_create_calls;

static char la_reported[512];
static uint32_t la_report_count;

void fixture_report_sink(const char* fmt, const char* message)
{
    (void)fmt;
    ++la_report_count;
    strcpy(la_reported, message ? message : "");
}

/* ================================================================== */
/* libc supplements the mesh fixture does not provide                  */
/* ================================================================== */
char* _strdup(const char* s)
{
    uint32_t n = (uint32_t)strlen(s) + 1u;
    char* p = _malloc(n, LEVEL_A_TAG, 91u);
    strcpy(p, s);
    return p;
}
size_t _strlen(const char* s) { return strlen(s); }
char* _strcpy(char* d, const char* s) { return strcpy(d, s); }
int _strcmp(const char* a, const char* b) { return strcmp(a, b); }

char* strncat(char* d, const char* s, size_t n)
{
    char* r = d;
    d += strlen(d);
    while (n-- && *s) *d++ = *s++;
    *d = 0;
    return r;
}

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

/* Link-completing integer helpers (no libgcc in this freestanding build). */
uint32_t __aeabi_uidiv(uint32_t n, uint32_t d)
{
    uint32_t q = 0;
    if (!d) return 0;
    while (n >= d) { n -= d; ++q; }
    return q;
}
int32_t __aeabi_idiv(int32_t n, int32_t d)
{
    uint32_t q;
    if (!d) return 0;
    q = __aeabi_uidiv((uint32_t)(n < 0 ? -n : n),
                      (uint32_t)(d < 0 ? -d : d));
    return ((n < 0) != (d < 0)) ? -(int32_t)q : (int32_t)q;
}

/* Prescribed double imports — SAME values as tools/level_a_oracle.py. */
__attribute__((no_stack_protector)) double cos(double angle)
{
    (void)angle;
    return 1.0;
}
__attribute__((no_stack_protector)) double sin(double angle)
{
    (void)angle;
    return 0.0;
}

/* Named I/O gap of the file wrapper; never driven by this fixture. */
void* _readFile(const char* path, int32_t* out_size)
{
    (void)path;
    if (out_size) *out_size = 0;
    return 0;
}

/* ================================================================== */
/* synthetic record creators (shapes copied from the chain fixture)    */
/* ================================================================== */
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

static char* la_copy_string(const char* s, uint32_t line)
{
    uint32_t n = (uint32_t)strlen(s) + 1u;
    char* p = _malloc(n, LEVEL_A_TAG, line);
    strcpy(p, s);
    return p;
}

spBoneData* spBoneData_create(int index, const char* name,
                              const spBoneData* parent)
{
    ch_bone* b = (ch_bone*)_calloc(1, sizeof(ch_bone), LEVEL_A_TAG, 100u);
    b->index = index;
    b->name = la_copy_string(name, 101u);
    b->parent = (void*)parent;
    b->scaleX = 1.0f;
    b->scaleY = 1.0f;
    b->inheritRotation = 1;
    b->inheritScale = 1;
    return (spBoneData*)b;
}

void* spSlotData_create(int index, const char* name, void* bone)
{
    ch_slot* s = (ch_slot*)_calloc(1, sizeof(ch_slot), LEVEL_A_TAG, 102u);
    s->index = index;
    s->name = la_copy_string(name, 103u);
    s->bone = bone;
    s->r = s->g = s->b = s->a = 1.0f;
    return s;
}

void spSlotData_setAttachmentName(void* slotData, const char* name)
{
    ch_slot* s = (ch_slot*)slotData;
    _free(s->attachment);
    s->attachment = la_copy_string(name, 104u);
}

void* spIkConstraintData_create(const char* name)
{
    ch_ik* c = (ch_ik*)_calloc(1, sizeof(ch_ik), LEVEL_A_TAG, 105u);
    c->name = la_copy_string(name, 106u);
    c->bendDirection = 1;
    c->mix = 1.0f;
    return c;
}

void* spTransformConstraintData_create(const char* name)
{
    ch_tr* c = (ch_tr*)_calloc(1, sizeof(ch_tr), LEVEL_A_TAG, 107u);
    c->name = la_copy_string(name, 108u);
    c->rotateMix = 1.0f;
    c->translateMix = 1.0f;
    c->scaleMix = 1.0f;
    c->shearMix = 1.0f;
    return c;
}

void* spPathConstraintData_create(const char* name)
{
    ch_path* c = (ch_path*)_calloc(1, sizeof(ch_path), LEVEL_A_TAG, 109u);
    c->name = la_copy_string(name, 110u);
    return c;
}

/* 0x28b070, 92 B: not recovered by any module; same count/array/name scan. */
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

/* Synthetic find* boundaries (same scan shape the chain fixture supplies). */
static uint32_t la_word_at(const void* p, unsigned i)
{
    uint32_t w;
    __builtin_memcpy(&w, (const char*)p + i * 4u, 4u);
    return w;
}
static void* la_scan_named(void* data_raw, const char* name, unsigned count_off,
                           unsigned array_off, unsigned name_off)
{
    int32_t count = (int32_t)la_word_at(data_raw, count_off / 4u);
    if (count <= 0) return 0;
    void** array = (void**)(uintptr_t)la_word_at(data_raw, array_off / 4u);
    for (int32_t i = 0; i < count; ++i) {
        void* rec = array[i];
        const char* n = (const char*)(uintptr_t)la_word_at(rec, name_off / 4u);
        if (strcmp(n, name) == 0) return rec;
    }
    return 0;
}
void* spSkeletonData_findIkConstraint(void* data, const char* name)
{
    return la_scan_named(data, name, 0x3cu, 0x40u, 0x00u);
}
void* spSkeletonData_findTransformConstraint(void* data, const char* name)
{
    return la_scan_named(data, name, 0x44u, 0x48u, 0x00u);
}
void* spSkeletonData_findPathConstraint(void* data, const char* name)
{
    return la_scan_named(data, name, 0x4cu, 0x50u, 0x00u);
}
void* spSkeletonData_findEvent(void* data, const char* name)
{
    return la_scan_named(data, name, 0x2cu, 0x30u, 0x00u);
}

/* ================================================================== */
/* timeline / animation / event synthetic creators                     */
/* ================================================================== */
static uint32_t la_tl_vtable[2];
static void la_tl_dispose(spTimeline* self) { (void)self; }

static void* la_zero(uint32_t n)
{
    void* p = reserve(n);
    memset(p, 0, n);
    return p;
}

/*
 * CurveTimeline layout shared by every non-attachment timeline:
 *   +0x00 type, +0x04 vtable, +0x08 curves ((frameCount-1)*19 floats),
 *   +0x0c frameFloatCount, +0x10 frames, +0x14 family index.
 */
static void* la_curve_timeline(uint32_t type, int frameCount, int step)
{
    uint32_t* t = (uint32_t*)la_zero(24);
    uint32_t curve_floats = (uint32_t)((frameCount - 1) * 19);
    t[0] = type;
    t[1] = (uint32_t)(uintptr_t)la_tl_vtable;
    t[2] = (uint32_t)(uintptr_t)la_zero(curve_floats * 4u);
    t[3] = (uint32_t)(frameCount * step);
    t[4] = (uint32_t)(uintptr_t)la_zero((uint32_t)frameCount * (uint32_t)step * 4u);
    return t;
}

void* spRotateTimeline_create(int frameCount)
{
    return la_curve_timeline(1u, frameCount, 2);
}
void* spTranslateTimeline_create(int frameCount)
{
    return la_curve_timeline(2u, frameCount, 3);
}
void* spScaleTimeline_create(int frameCount)
{
    return la_curve_timeline(0u, frameCount, 3);   /* original type word is 0 */
}
void* spShearTimeline_create(int frameCount)
{
    return la_curve_timeline(3u, frameCount, 3);
}
void* spColorTimeline_create(int frameCount)
{
    return la_curve_timeline(4u, frameCount, 5);
}
void* spIkConstraintTimeline_create(int frameCount)
{
    return la_curve_timeline(9u, frameCount, 3);
}
void* spTransformConstraintTimeline_create(int frameCount)
{
    return la_curve_timeline(10u, frameCount, 5);
}
void* spPathConstraintPositionTimeline_create(int frameCount)
{
    return la_curve_timeline(11u, frameCount, 2);
}
void* spPathConstraintSpacingTimeline_create(int frameCount)
{
    return la_curve_timeline(12u, frameCount, 2);
}
void* spPathConstraintMixTimeline_create(int frameCount)
{
    return la_curve_timeline(13u, frameCount, 3);
}

static float* la_frames(void* timeline) { return (float*)*(uint32_t*)((char*)timeline + 0x10); }

void spRotateTimeline_setFrame(void* timeline, int frameIndex, float time,
                               float angle)
{
    float* f = la_frames(timeline);
    f[frameIndex * 2 + 0] = time;
    f[frameIndex * 2 + 1] = angle;
}
void spTranslateTimeline_setFrame(void* timeline, int frameIndex, float time,
                                  float x, float y)
{
    float* f = la_frames(timeline);
    f[frameIndex * 3 + 0] = time;
    f[frameIndex * 3 + 1] = x;
    f[frameIndex * 3 + 2] = y;
}
void spScaleTimeline_setFrame(void* timeline, int frameIndex, float time,
                              float x, float y)
{
    spTranslateTimeline_setFrame(timeline, frameIndex, time, x, y);
}
void spShearTimeline_setFrame(void* timeline, int frameIndex, float time,
                              float x, float y)
{
    spTranslateTimeline_setFrame(timeline, frameIndex, time, x, y);
}
void spColorTimeline_setFrame(void* timeline, int frameIndex, float time,
                              float r, float g, float b, float a)
{
    float* f = la_frames(timeline);
    uint32_t base = (uint32_t)frameIndex * 5u;
    f[base + 0] = time; f[base + 1] = r; f[base + 2] = g;
    f[base + 3] = b; f[base + 4] = a;
}
void spIkConstraintTimeline_setFrame(void* timeline, int frameIndex,
                                     float time, float mix, int bend)
{
    float* f = la_frames(timeline);
    uint32_t base = (uint32_t)frameIndex * 3u;
    f[base + 0] = time;
    f[base + 1] = mix;
    f[base + 2] = (float)bend;
}
void spTransformConstraintTimeline_setFrame(void* timeline, int frameIndex,
                                            float time, float rotateMix,
                                            float translateMix, float scaleMix,
                                            float shearMix)
{
    float* f = la_frames(timeline);
    uint32_t base = (uint32_t)frameIndex * 5u;
    f[base + 0] = time; f[base + 1] = rotateMix; f[base + 2] = translateMix;
    f[base + 3] = scaleMix; f[base + 4] = shearMix;
}
void spPathConstraintPositionTimeline_setFrame(void* timeline, int frameIndex,
                                               float time, float value)
{
    float* f = la_frames(timeline);
    f[frameIndex * 2 + 0] = time;
    f[frameIndex * 2 + 1] = value;
}
void spPathConstraintSpacingTimeline_setFrame(void* timeline, int frameIndex,
                                              float time, float value)
{
    spPathConstraintPositionTimeline_setFrame(timeline, frameIndex, time, value);
}
void spPathConstraintMixTimeline_setFrame(void* timeline, int frameIndex,
                                          float time, float rotateMix,
                                          float translateMix)
{
    float* f = la_frames(timeline);
    uint32_t base = (uint32_t)frameIndex * 3u;
    f[base + 0] = time; f[base + 1] = rotateMix; f[base + 2] = translateMix;
}

/* ---- CurveTimeline writers: exact original arithmetic ----------------- */
#define LA_AI static inline __attribute__((always_inline))
LA_AI float la_vadd(float a, float b)
{ float r; __asm__ volatile("vadd.f32 %0,%1,%2" : "=t"(r) : "t"(a), "t"(b) : "memory"); return r; }
LA_AI float la_vsub(float a, float b)
{ float r; __asm__ volatile("vsub.f32 %0,%1,%2" : "=t"(r) : "t"(a), "t"(b) : "memory"); return r; }
LA_AI float la_vmul(float a, float b)
{ float r; __asm__ volatile("vmul.f32 %0,%1,%2" : "=t"(r) : "t"(a), "t"(b) : "memory"); return r; }
LA_AI float la_vmla(float acc, float a, float b)
{ __asm__ volatile("vmla.f32 %0,%1,%2" : "+t"(acc) : "t"(a), "t"(b) : "memory"); return acc; }
LA_AI float la_vneg(float a)
{ float r; __asm__ volatile("vneg.f32 %0,%1" : "=t"(r) : "t"(a) : "memory"); return r; }

void spCurveTimeline_setStepped(void* timeline, int frameIndex)
{
    float* curves = (float*)*(uint32_t*)((char*)timeline + 0x08);
    curves[frameIndex * 19] = 1.0f;
}

void spCurveTimeline_setCurve(void* timeline, int frameIndex,
                              float cx1, float cy1, float cx2, float cy2)
{
    float* curves = (float*)*(uint32_t*)((char*)timeline + 0x08);
    float s14 = cx1, s6 = cx2, s15 = cy1, s9 = cy2;
    float s12 = la_vneg(s14); s12 = la_vadd(s12, s12);
    float s13 = la_vneg(s15); s13 = la_vadd(s13, s13);
    s12 = la_vadd(s12, s6);
    float s5 = la_vsub(s15, s9);
    s13 = la_vadd(s13, s9);
    s9 = 1.0f;
    s12 = la_vmul(s12, 0.03f);
    float s4 = la_vsub(s14, s6);
    s6 = 3.0f;
    s13 = la_vmul(s13, 0.03f);
    float s8 = s9;
    s9 = la_vmla(s9, s5, s6);
    s8 = la_vmla(s8, s4, s6);
    s6 = s12; s6 = la_vmla(s6, s14, 0.3f); s14 = s6;
    s6 = s13; s6 = la_vmla(s6, s15, 0.3f);
    s8 = la_vmul(s8, 0.006f);
    s9 = la_vmul(s9, 0.006f);
    s15 = s6;
    s14 = la_vmla(s14, s8, 0.16666667f);
    s15 = la_vmla(s15, s9, 0.16666667f);
    s12 = la_vadd(s12, s12); s13 = la_vadd(s13, s13);
    s12 = la_vadd(s12, s8); s13 = la_vadd(s13, s9);
    float s10 = s14, s11 = s15;
    uint32_t base = (uint32_t)frameIndex * 19u;
    curves[base] = 2.0f;
    for (uint32_t k = 0; k < 9u; ++k) {
        curves[base + 1u + 2u * k] = s10;
        curves[base + 2u + 2u * k] = s11;
        s14 = la_vadd(s14, s12);
        s15 = la_vadd(s15, s13);
        s10 = la_vadd(s10, s14);
        s11 = la_vadd(s11, s15);
        s12 = la_vadd(s12, s8);
        s13 = la_vadd(s13, s9);
    }
}

/* ---- attachment / event / animation creators ------------------------- */
typedef struct la_att_tl {
    uint32_t type;
    uint32_t vtable;
    int32_t frameCount;
    float* times;       /* +0x0c one time float per frame */
    int32_t slotIndex;  /* +0x10 written by B5 (spAttachmentTimelineShape) */
    char** names;       /* +0x14 attachment-name table */
} la_att_tl;

void* spAttachmentTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    la_att_tl* t = (la_att_tl*)la_zero(sizeof(*t));
    t->type = 5u;
    t->vtable = (uint32_t)(uintptr_t)la_tl_vtable;
    t->frameCount = frameCount;
    t->times = (float*)la_zero(n * 4u);
    t->names = (char**)la_zero(n * 4u);
    return t;
}
void spAttachmentTimeline_setFrame(void* timeline, int frameIndex, float time,
                                   const char* attachmentName)
{
    la_att_tl* t = (la_att_tl*)timeline;
    t->times[frameIndex] = time;
    t->names[frameIndex] = (char*)attachmentName;
}

typedef struct la_event_tl {
    uint32_t type;
    uint32_t vtable;
    int32_t frameCount;
    float* times;
    void** events;
} la_event_tl;

void* spEventTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    la_event_tl* t = (la_event_tl*)la_zero(sizeof(*t));
    t->type = 6u;
    t->vtable = (uint32_t)(uintptr_t)la_tl_vtable;
    t->frameCount = frameCount;
    t->times = (float*)la_zero(n * 4u);
    t->events = (void**)la_zero(n * 4u);
    return t;
}
void spEventTimeline_setFrame(void* timeline, int frameIndex, void* event)
{
    la_event_tl* t = (la_event_tl*)timeline;
    const float* e = (const float*)event;
    void* old = t->events[frameIndex];
    float time = 0.0f;
    if (e) __builtin_memcpy(&time, (const char*)e + 4, 4);
    t->times[frameIndex] = time;
    t->events[frameIndex] = event;
    _free(old);                     /* 0x282d34..0x282d3c frees the old slot */
}

/*
 * DrawOrder record, 24 B, layout taken from 0x282d4c (see
 * c/spine_read_tl_draworder/src/spine_read_tl_draworder.h):
 *   +0x00 type 7, +0x04 vtable, +0x08 frameCount, +0x0c times,
 *   +0x10 drawOrders (one owned int* per frame), +0x14 slotsCount.
 * setFrame keeps a COPY of the caller's array (0x282ddc: free old, malloc
 * slotsCount*4, memcpy), which is why the reader frees its own array.
 */
void* spDrawOrderTimeline_create(int frameCount, int slotsCount)
{
    uint32_t* t = (uint32_t*)la_zero(24);
    t[0] = 7u; t[1] = (uint32_t)(uintptr_t)la_tl_vtable;
    t[2] = (uint32_t)frameCount;
    t[3] = (uint32_t)(uintptr_t)la_zero((uint32_t)frameCount * 4u);
    t[4] = (uint32_t)(uintptr_t)la_zero((uint32_t)frameCount * 4u);
    t[5] = (uint32_t)slotsCount;
    return t;
}
void spDrawOrderTimeline_setFrame(void* timeline, int frameIndex, float time,
                                  const int32_t* drawOrder)
{
    uint32_t* t = (uint32_t*)timeline;
    float* times = (float*)t[3];
    int32_t** orders = (int32_t**)t[4];
    uint32_t slots = t[5];
    times[frameIndex] = time;
    _free(orders[frameIndex]);            /* 0x282df8 frees the old slot */
    if (!drawOrder) { orders[frameIndex] = 0; return; }
    int32_t* copy = (int32_t*)_malloc(slots * 4u, LEVEL_A_TAG, 690u);
    for (uint32_t k = 0; k < slots; ++k) copy[k] = drawOrder[k];
    orders[frameIndex] = copy;
}

/*
 * Deform record, 36 B, layout taken from 0x282e58 (see
 * c/spine_read_tl_deform/src/spine_read_tl_deform.h): +0x00 type 8,
 * +0x04 vtable, +0x08 curves ((frameCount-1)*19), +0x0c frameCount,
 * +0x10 times, +0x14 vertexFloatCount (create's 2nd argument),
 * +0x18 vertices (one owned float* per frame).
 */
void* spDeformTimeline_create(int frameCount, int vertexCount)
{
    uint32_t* t = (uint32_t*)la_zero(36);
    uint32_t curve_floats = (uint32_t)((frameCount - 1) * 19);
    t[0] = 8u; t[1] = (uint32_t)(uintptr_t)la_tl_vtable;
    t[2] = (uint32_t)(uintptr_t)la_zero(curve_floats * 4u);
    t[3] = (uint32_t)frameCount;
    t[4] = (uint32_t)(uintptr_t)la_zero((uint32_t)frameCount * 4u);
    t[5] = (uint32_t)vertexCount;
    t[6] = (uint32_t)(uintptr_t)la_zero((uint32_t)frameCount * 4u);
    return t;
}
void spDeformTimeline_setFrame(void* timeline, int frameIndex, float time,
                               const float* vertices)
{
    uint32_t* t = (uint32_t*)timeline;
    float* times = (float*)t[4];
    float** table = (float**)t[6];
    uint32_t count = t[5];
    times[frameIndex] = time;
    _free(table[frameIndex]);             /* 0x282f14/1c frees the old slot */
    if (!vertices) { table[frameIndex] = 0; return; }
    float* copy = (float*)_malloc(count * 4u, LEVEL_A_TAG, 799u);
    for (uint32_t k = 0; k < count; ++k) copy[k] = vertices[k];
    table[frameIndex] = copy;
}

typedef struct la_event_data {
    char* name;
    int32_t intValue;
    float floatValue;
    char* stringValue;
} la_event_data;

spEventData* spEventData_create(const char* name)
{
    la_event_data* e = (la_event_data*)_calloc(1, sizeof(*e), LEVEL_A_TAG, 36u);
    e->name = la_copy_string(name, 37u);
    return (spEventData*)e;
}

typedef struct la_event {
    const void* data;
    float time;
    int32_t intValue;
    float floatValue;
    char* stringValue;
} la_event;

void* spEvent_create(float time, const void* data)
{
    la_event* e = (la_event*)_calloc(1, sizeof(*e), LEVEL_A_TAG, 36u);
    e->data = data;
    e->time = time;
    return e;
}

typedef struct la_anim {
    char* name;
    float duration;
    int32_t timelineCount;
    void** timelines;
} la_anim;

spAnimation* spAnimation_create(const char* name, int32_t timelineCount)
{
    la_anim* a = (la_anim*)_calloc(1, sizeof(*a), LEVEL_A_TAG, 38u);
    a->name = la_copy_string(name, 39u);
    a->timelineCount = timelineCount;
    a->timelines = (void**)_malloc((uint32_t)timelineCount * 4u, LEVEL_A_TAG, 41u);
    return (spAnimation*)a;
}

/* ================================================================== */
/* Json_create / Json_getError / setlocale seam                        */
/* ================================================================== */
Json* Json_create(const char* text)
{
    (void)text;
    ++la_json_create_calls;
#if LEVEL_A_JSON_FAIL
    return 0;                     /* the parser failed: entry reports and bails */
#else
    readSkeletonData_rootSlot = la_tree;
    return la_tree;
#endif
}

#ifndef LEVEL_A_JSON_ERROR
#define LEVEL_A_JSON_ERROR "parse failed at 1"
#endif
const char* Json_getError(void) { return LEVEL_A_JSON_ERROR; }

char* _setlocale(int category, const char* locale)
{
    (void)category; (void)locale;
    return (char*)"C";
}

/* ================================================================== */
/* attachment loader (declared synthetic boundary)                     */
/* ================================================================== */
static spAttachmentLoader la_loader;
static spAttachmentLoaderVtable la_loader_vtable;

static spAttachment* la_loader_create(spAttachmentLoader* self, spSkin* skin,
                                      int32_t type, const char* name,
                                      const char* path)
{
    (void)self; (void)skin; (void)path;
    switch (type) {
    case 0: {
        spRegionAttachment* a = spRegionAttachment_create(name);
        a->region = 0;
        a->regionOffsetX = 0;
        a->regionOffsetY = 0;
        a->regionWidth = 10;
        a->regionHeight = 20;
        a->regionOriginalWidth = 10;
        a->regionOriginalHeight = 20;
        a->uvs[0] = 0.0f; a->uvs[1] = 0.0f;
        a->uvs[2] = 1.0f; a->uvs[3] = 0.0f;
        a->uvs[4] = 1.0f; a->uvs[5] = 1.0f;
        a->uvs[6] = 0.0f; a->uvs[7] = 1.0f;
        return &a->super;
    }
    case 1: {
        spBoundingBoxAttachment* a = spBoundingBoxAttachment_create(name);
        return &a->super.super;
    }
    case 2:
    case 3: {
        spMeshAttachment* a = spMeshAttachment_create(name);
        a->u = 0.0f; a->v = 0.0f; a->u2 = 1.0f; a->v2 = 1.0f;
        return &a->super.super;
    }
    case 4: {
        spPathAttachment* a = spPathAttachment_create(name);
        return &a->super.super;
    }
    default:
        _spAttachmentLoader_setUnknownTypeError(self, type);
        return 0;
    }
}

static void la_loader_configure(spAttachmentLoader* self, spAttachment* a)
{
    (void)self; (void)a;
}

/* ================================================================== */
/* dump writer                                                         */
/* ================================================================== */
static unsigned char la_obuf[262144];
static unsigned la_on;

static void la_u8(unsigned v)
{
    CK(la_on < sizeof la_obuf, "dump buffer");
    la_obuf[la_on++] = (unsigned char)v;
}
static void la_u16(uint32_t v)
{
    la_u8(v & 0xffu); la_u8((v >> 8) & 0xffu);
}
static void la_u32(uint32_t v)
{
    la_u8(v & 0xffu); la_u8((v >> 8) & 0xffu);
    la_u8((v >> 16) & 0xffu); la_u8((v >> 24) & 0xffu);
}
static void la_i32(int32_t v) { la_u32((uint32_t)v); }
static void la_str(const char* s)
{
    uint32_t n = s ? (uint32_t)strlen(s) : 0u;
    la_u16(n);
    for (uint32_t k = 0; k < n; ++k) la_u8((unsigned char)s[k]);
}

enum {
    T_TREE = 1, T_META = 2, T_BONES = 3, T_SLOTS = 4, T_IK = 5,
    T_TRANSFORM = 6, T_PATH = 7, T_SKINS = 8, T_EVENTS = 9, T_ANIMS = 10,
    T_ERROR = 11, T_END = 0xff
};

static uint32_t lw(const void* p, unsigned off)
{
    uint32_t v; __builtin_memcpy(&v, (const char*)p + off, 4); return v;
}
static int32_t li(const void* p, unsigned off)
{
    int32_t v; __builtin_memcpy(&v, (const char*)p + off, 4); return v;
}
static void* vp(const void* p, unsigned off)
{
    return (void*)(uintptr_t)lw(p, off);
}

static int la_index_of(void** table, int32_t count, const void* p)
{
    for (int32_t k = 0; k < count; ++k)
        if (table[k] == p) return (int)k;
    return -1;
}

static void la_dump_tree_node(Json* n)
{
    if (!n) { la_u8('{'); la_u8(0); la_u8(0); la_u32(0); la_u32(0);
              la_u32(0); la_u32(0); la_u32(0); la_u8('}'); return; }
    la_u8('{');
    la_u8(n->name != 0); if (n->name) la_str(n->name);
    la_u8(n->string_value != 0); if (n->string_value) la_str(n->string_value);
    la_u32((uint32_t)n->int_value);
    uint32_t fbits; __builtin_memcpy(&fbits, &n->float_value, 4); la_u32(fbits);
    la_u32(n->unk_08);
    la_u32(n->unk_0c);
    uint32_t kids = 0;
    for (Json* c = n->child; c; c = c->next) ++kids;
    la_u32(kids);
    for (Json* c = n->child; c; c = c->next) la_dump_tree_node(c);
    la_u8('}');
}

static void la_dump_meta(const spSkeletonData* d)
{
    la_u8(T_META);
    for (unsigned k = 0; k < 21; ++k) la_u32(lw(d, k * 4));
    la_str((const char*)(uintptr_t)lw(d, 0x00));
    la_str((const char*)(uintptr_t)lw(d, 0x04));
}

static void la_dump_bones(const spSkeletonData* d)
{
    int32_t count = li(d, 0x10);
    void** table = (void**)vp(d, 0x14);
    la_u8(T_BONES); la_u32((uint32_t)count);
    for (int32_t k = 0; k < count; ++k) {
        void* b = table[k];
        la_i32(k);
        la_str((const char*)(uintptr_t)lw(b, 0x04));
        la_i32(la_index_of(table, count, vp(b, 0x08)));
        for (unsigned off = 0x0c; off <= 0x28; off += 4) la_u32(lw(b, off));
        la_i32(li(b, 0x2c));
        la_i32(li(b, 0x30));
    }
}

static void la_dump_slots(const spSkeletonData* d)
{
    int32_t count = li(d, 0x18);
    void** table = (void**)vp(d, 0x1c);
    int32_t bcount = li(d, 0x10);
    void** btable = (void**)vp(d, 0x14);
    la_u8(T_SLOTS); la_u32((uint32_t)count);
    for (int32_t k = 0; k < count; ++k) {
        void* s = table[k];
        la_i32(k);
        la_str((const char*)(uintptr_t)lw(s, 0x04));
        la_i32(la_index_of(btable, bcount, vp(s, 0x08)));
        la_str((const char*)(uintptr_t)lw(s, 0x0c));
        for (unsigned off = 0x10; off <= 0x1c; off += 4) la_u32(lw(s, off));
        la_i32(li(s, 0x20));
    }
}

static void la_dump_ik(const spSkeletonData* d)
{
    int32_t count = li(d, 0x3c);
    void** table = (void**)vp(d, 0x40);
    int32_t bcount = li(d, 0x10);
    void** btable = (void**)vp(d, 0x14);
    la_u8(T_IK); la_u32((uint32_t)count);
    for (int32_t k = 0; k < count; ++k) {
        void* c = table[k];
        int32_t n = li(c, 0x04);
        void** bones = (void**)vp(c, 0x08);
        la_i32(k);
        la_str((const char*)(uintptr_t)lw(c, 0x00));
        la_i32(n);
        for (int32_t j = 0; j < n; ++j)
            la_i32(la_index_of(btable, bcount, bones[j]));
        la_i32(la_index_of(btable, bcount, vp(c, 0x0c)));
        la_i32(li(c, 0x10));
        la_u32(lw(c, 0x14));
    }
}

static void la_dump_transform(const spSkeletonData* d)
{
    int32_t count = li(d, 0x44);
    void** table = (void**)vp(d, 0x48);
    int32_t bcount = li(d, 0x10);
    void** btable = (void**)vp(d, 0x14);
    la_u8(T_TRANSFORM); la_u32((uint32_t)count);
    for (int32_t k = 0; k < count; ++k) {
        void* c = table[k];
        int32_t n = li(c, 0x04);
        void** bones = (void**)vp(c, 0x08);
        la_i32(k);
        la_str((const char*)(uintptr_t)lw(c, 0x00));
        la_i32(n);
        for (int32_t j = 0; j < n; ++j)
            la_i32(la_index_of(btable, bcount, bones[j]));
        la_i32(la_index_of(btable, bcount, vp(c, 0x0c)));
        for (unsigned off = 0x10; off <= 0x34; off += 4) la_u32(lw(c, off));
    }
}

static void la_dump_path(const spSkeletonData* d)
{
    int32_t count = li(d, 0x4c);
    void** table = (void**)vp(d, 0x50);
    int32_t bcount = li(d, 0x10);
    void** btable = (void**)vp(d, 0x14);
    int32_t scount = li(d, 0x18);
    void** stable = (void**)vp(d, 0x1c);
    la_u8(T_PATH); la_u32((uint32_t)count);
    for (int32_t k = 0; k < count; ++k) {
        void* c = table[k];
        int32_t n = li(c, 0x04);
        void** bones = (void**)vp(c, 0x08);
        la_i32(k);
        la_str((const char*)(uintptr_t)lw(c, 0x00));
        la_i32(n);
        for (int32_t j = 0; j < n; ++j)
            la_i32(la_index_of(btable, bcount, bones[j]));
        la_i32(la_index_of(stable, scount, vp(c, 0x0c)));
        for (unsigned off = 0x10; off <= 0x2c; off += 4) la_u32(lw(c, off));
    }
}

static void la_dump_attachment(const void* a)
{
    int32_t type = li(a, 0x04);
    la_i32(type);
    la_str((const char*)(uintptr_t)lw(a, 0x00));
    if (type == 0) la_str((const char*)(uintptr_t)lw(a, 0x10));
    else if (type == 2 || type == 3) la_str((const char*)(uintptr_t)lw(a, 0x54));
    else la_str("");
    if (type == 0) {
        for (unsigned off = 0x14; off <= 0x3c; off += 4) la_u32(lw(a, off));
        for (unsigned off = 0x44; off <= 0x58; off += 4) la_i32(li(a, off));
        for (unsigned off = 0x5c; off < 0x7c; off += 4) la_u32(lw(a, off));
        for (unsigned off = 0x7c; off < 0x9c; off += 4) la_u32(lw(a, off));
    } else if (type == 2 || type == 3) {
        uint32_t float_count = lw(a, 0x18);
        uint32_t tri_count = lw(a, 0x60);
        la_u32(lw(a, 0x10));
        la_u32(float_count);
        la_u32(lw(a, 0x20));
        const float* verts = (const float*)vp(a, 0x1c);
        for (uint32_t k = 0; k < float_count && k < 16u; ++k) la_u32(lw(verts, k * 4));
        for (unsigned off = 0x40; off <= 0x4c; off += 4) la_u32(lw(a, off));
        for (unsigned off = 0x68; off <= 0x74; off += 4) la_u32(lw(a, off));
        for (unsigned off = 0x30; off <= 0x3c; off += 4) la_i32(li(a, off));
        la_u32(tri_count);
        const uint16_t* tri = (const uint16_t*)vp(a, 0x64);
        for (uint32_t k = 0; k < tri_count && k < 12u; ++k) la_u16(tri[k]);
        la_u32(lw(a, 0x78));
        /* +0x7c parentMesh (set only by the linkedmesh postpass); dumped as the
         * parent's name so the link survives the heap-address gap. */
        const void* parent_mesh = vp(a, 0x7c);
        la_str(parent_mesh ? *(const char* const*)parent_mesh : 0);
    } else {
        uint32_t float_count = lw(a, 0x18);
        la_u32(lw(a, 0x10));
        la_u32(float_count);
        la_u32(lw(a, 0x20));
        const float* verts = (const float*)vp(a, 0x1c);
        for (uint32_t k = 0; k < float_count && k < 16u; ++k) la_u32(lw(verts, k * 4));
        if (type == 4) {
            la_i32(li(a, 0x24)); la_i32(li(a, 0x2c)); la_i32(li(a, 0x30));
        }
    }
}

static void la_dump_skins(const spSkeletonData* d)
{
    int32_t count = li(d, 0x20);
    void** table = (void**)vp(d, 0x24);
    la_u8(T_SKINS); la_u32((uint32_t)count);
    la_i32(la_index_of(table, count, vp(d, 0x28)));
    for (int32_t k = 0; k < count; ++k) {
        void* skin = table[k];
        la_i32(k);
        la_str((const char*)(uintptr_t)lw(skin, 0x00));
        uint32_t entries = 0;
        for (void* e = vp(skin, 0x04); e; e = vp(e, 0x0c)) ++entries;
        la_u32(entries);
        for (void* e = vp(skin, 0x04); e; e = vp(e, 0x0c)) {
            la_i32(li(e, 0x00));
            la_str((const char*)(uintptr_t)lw(e, 0x04));
            la_dump_attachment(vp(e, 0x08));
        }
    }
}

static void la_dump_events(const spSkeletonData* d)
{
    int32_t count = li(d, 0x2c);
    void** table = (void**)vp(d, 0x30);
    la_u8(T_EVENTS); la_u32((uint32_t)count);
    for (int32_t k = 0; k < count; ++k) {
        void* e = table[k];
        la_i32(k);
        la_str((const char*)(uintptr_t)lw(e, 0x00));
        la_i32(li(e, 0x04));
        la_u32(lw(e, 0x08));
        la_str((const char*)(uintptr_t)lw(e, 0x0c));
    }
}

static int la_timeline_step(uint32_t type)
{
    switch (type) {
    case 1u: return 2;              /* rotate */
    case 2u: case 0u: case 3u: return 3;  /* translate / scale / shear */
    case 4u: return 5;              /* color */
    case 9u: return 3;              /* ik */
    case 10u: return 5;             /* transform */
    case 11u: case 12u: return 2;   /* path position / spacing */
    case 13u: return 3;             /* path mix */
    default: return 0;
    }
}

static void la_dump_animations(const spSkeletonData* d)
{
    int32_t count = li(d, 0x34);
    void** table = (void**)vp(d, 0x38);
    la_u8(T_ANIMS); la_u32((uint32_t)count);
    for (int32_t k = 0; k < count; ++k) {
        void* a = table[k];
        int32_t tcount = li(a, 0x08);
        void** timelines = (void**)vp(a, 0x0c);
        la_i32(k);
        la_str((const char*)(uintptr_t)lw(a, 0x00));
        la_u32(lw(a, 0x04));
        la_i32(tcount);
        for (int32_t j = 0; j < tcount; ++j) {
            void* t = timelines[j];
            uint32_t type = lw(t, 0x00);
            int32_t ffc = li(t, 0x0c);
            int step = la_timeline_step(type);
            int32_t frame_count;
            if (type == 5u) frame_count = li(t, 0x08);
            else if (type == 6u || type == 7u) frame_count = li(t, 0x08);
            else if (type == 8u) frame_count = li(t, 0x0c);   /* deform +0x0c */
            else frame_count = step ? (int32_t)((uint32_t)ffc / (uint32_t)step) : 0;
            la_u32(type);
            la_u32((uint32_t)frame_count);
            la_u32((type >= 5u && type <= 8u) ? 0u : (uint32_t)ffc);  /* only attachment/event/drawOrder/deform lack the curve-timeline ffc; 9..13 DO have it */
            la_i32((type == 5u || type == 6u || type == 7u || type == 8u)
                   ? 0 : li(t, 0x14));
            if (type == 7u) {
                /* drawOrder: +0x14 slotsCount, +0x0c times, +0x10 one int* per
                 * frame (setFrame keeps its own copy). */
                int32_t slots = li(t, 0x14);
                la_i32(slots);
                const float* dtimes = (const float*)vp(t, 0x0c);
                void** orders = (void**)(uintptr_t)lw(t, 0x10);
                for (int32_t q = 0; q < frame_count; ++q) {
                    const int32_t* order = orders ? (const int32_t*)orders[q] : 0;
                    la_u32(lw(dtimes, (unsigned)q * 4));
                    for (int32_t k = 0; k < slots; ++k)
                        la_i32(order ? order[k] : 0x7fffffff);
                }
            } else if (type == 8u) {
                /* deform: +0x14 vertexFloatCount, +0x10 times, +0x18 one
                 * float* per frame. */
                int32_t vcount = li(t, 0x14);
                la_i32(vcount);
                const float* vtimes = (const float*)vp(t, 0x10);
                void** table = (void**)(uintptr_t)lw(t, 0x18);
                for (int32_t q = 0; q < frame_count; ++q) {
                    const float* verts = table ? (const float*)table[q] : 0;
                    la_u32(lw(vtimes, (unsigned)q * 4));
                    for (int32_t k = 0; k < vcount; ++k)
                        la_u32(verts ? lw(verts, (unsigned)k * 4) : 0x7fffffff);
                }
            } else if (step) {
                const float* frames = (const float*)vp(t, 0x10);
                for (int32_t q = 0; q < ffc; ++q) la_u32(lw(frames, (unsigned)q * 4));
                const float* curves = (const float*)vp(t, 0x08);
                int32_t cn = (frame_count - 1) * 19;
                if (cn < 0) cn = 0;
                for (int32_t q = 0; q < cn; ++q) la_u32(lw(curves, (unsigned)q * 4));
            } else if (type == 5u) {
                const float* times = (const float*)vp(t, 0x0c);
                char** names = (char**)vp(t, 0x14);
                la_i32(li(t, 0x10));            /* slotIndex written by B5 */
                for (int32_t q = 0; q < frame_count; ++q) {
                    la_u32(lw(times, (unsigned)q * 4));
                    la_str(names[q]);
                }
            } else if (type == 6u) {
                const float* times = (const float*)vp(t, 0x0c);
                void** events = (void**)vp(t, 0x10);
                for (int32_t q = 0; q < frame_count; ++q) {
                    void* e = events[q];
                    la_u32(lw(times, (unsigned)q * 4));
                    if (e) {
                        la_i32(li(e, 0x08));
                        la_u32(lw(e, 0x0c));
                        la_str((const char*)(uintptr_t)lw(e, 0x10));
                    } else {
                        la_i32(0); la_u32(0); la_str("");
                    }
                }
            }
        }
    }
}

/* ================================================================== */
/* generated tree                                                      */
/* ================================================================== */
#include "level_a_tree.inc"

/* ================================================================== */
/* entry                                                               */
/* ================================================================== */
static void la_mark(const char* s)
{
    size_t n = 0; while (s[n]) ++n;
    sys3(4, 2, (long)(uintptr_t)s, (long)n);
}

void level_a_start(void)
{
    test = "level_a";
    init_heap();
    fixture_install_error_reporter();
    la_mark("m0 init\n");
    la_tl_vtable[0] = 0u;
    la_tl_vtable[1] = (uint32_t)(uintptr_t)la_tl_dispose;

    la_mark("m1 pre-build\n");
    la_tree = build_level_a_tree();
    la_root_pointer = la_tree;      /* free() counts only this pointer */
    la_mark("m2 tree-built\n");
    la_u8(T_TREE);
    la_dump_tree_node(la_tree);

    memset(&la_self, 0, sizeof la_self);
    la_self.scale = LEVEL_A_SCALE_BITS;
    la_self.loader = (uint32_t)(uintptr_t)&la_loader;
    memset(&la_loader, 0, sizeof la_loader);
    memset(&la_loader_vtable, 0, sizeof la_loader_vtable);
    la_loader.vtable = &la_loader_vtable;
    la_loader_vtable.createAttachment = la_loader_create;
    la_loader_vtable.configureAttachment = la_loader_configure;

    la_mark("m3 pre-chain\n");
    la_data = spSkeletonJson_readSkeletonData(&la_self, "{}");
    la_mark("m4 chain-done\n");
    if (la_data) {
        la_dump_meta(la_data);
        la_mark("m5 meta\n");
        la_dump_bones(la_data);
        la_mark("m6 bones\n");
        la_dump_slots(la_data);
        la_mark("m7 slots\n");
        la_dump_ik(la_data);
        la_mark("m8 ik\n");
        la_dump_transform(la_data);
        la_mark("m9 transform\n");
        la_dump_path(la_data);
        la_mark("m10 path\n");
        la_dump_skins(la_data);
        la_mark("m11 skins\n");
        la_dump_events(la_data);
        la_mark("m12 events\n");
        la_dump_animations(la_data);
        la_mark("m13 anims\n");
    }
    la_u8(T_ERROR);
    la_u32(la_data ? 0u : 1u);
    la_str((const char*)(uintptr_t)la_self.error);
    la_str(la_reported);
    la_u32((uint32_t)la_json_create_calls);
    la_u32((uint32_t)la_report_count);
    la_u32(la_root_frees);          /* Json_dispose(ROOT) count: 1 released, 0 leak */
    la_u8(T_END);

    sys3(4, 1, (long)(uintptr_t)la_obuf, (long)la_on);
    quit(0);
}
