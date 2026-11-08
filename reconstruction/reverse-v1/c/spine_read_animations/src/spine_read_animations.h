/*
 * spine_read_animations.h — readSkeletonData entry blocks for the
 * skeleton-wide events array, the animations array, and the per-animation
 * preamble / 8-key lookup / timeline-count + spAnimation_create blocks.
 *
 * Original image: libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Recovered here (caller blocks of spSkeletonJson_readSkeletonData @0x28b84c):
 *   B1   0x28d19c..0x28d290  61 insns  events array + EventData loop
 *   B2   0x28d290..0x28d2d4  17 insns  animations array allocation
 *   B3   0x28d2d4..0x28d3b4  56 insns  per-animation 8-key lookup + 0x55555556
 *   B3b  0x28eb28..0x28eb40   6 insns  legacy "draworder" retry (out of line)
 *   B4   0x28d3b4..0x28d4ec  78 insns  timelineCount sum + spAnimation_create
 *
 * These are BLOCKS of the parent loader, not standalone original symbols.
 * No original bytes are executed; every claim is instruction-anchored.
 */
#ifndef YY_SPINE_READ_ANIMATIONS_H
#define YY_SPINE_READ_ANIMATIONS_H

#include <stddef.h>
#include <stdint.h>
#include "json_interface.h"

/* The EventData record as observed by B1 only (spEventData_create is a
 * synthetic boundary in the fixture; its body is NOT recovered here).
 * Offsets are pinned by 0x28d230 (+0x04), 0x28d244 (+0x08), 0x28d270 (+0x0c);
 * +0x00 is written by the creator itself (0x285bd8 str r0,[r4]). */
typedef struct spEventData {
    const char* name;        /* +0x00 borrowed Json member key */
    int32_t     intValue;    /* +0x04 Json_getInt "int" */
    float       floatValue;  /* +0x08 Json_getFloat "float" */
    const char* stringValue; /* +0x0c owned copy, malloc line 1034 */
} spEventData;

/* spAnimation record — synthetic boundary. Its creator (0x2812b4, 116 B,
 * out of this batch's scope) is read statically for the fields B4 touches:
 *   0x2812b8 mov r3,#38 / 0x2812d8 bl _calloc(1,16,tag,38)   record = 16 B, zeroed
 *   0x2812fc str r0,[r4]        +0x00 = strcpy copy of arg0 (name)
 *   0x281304 str r7,[r4,#0x8]   +0x08 = arg1 (the timeline count)
 *   0x281308 lsl r0,r7,#2 / 0x281314 bl _malloc(line 41) / 0x281318 str r0,[r4,#0xc]
 * +0x04 is never written by the creator; calloc(1,16) leaves it zero.
 * B4 then overwrites +0x08 with 0 (0x28d4cc/0x28d4d4) and never touches +0x0c. */
typedef struct spAnimation {
    const char* name;          /* +0x00 */
    uint32_t    opaque_04;     /* +0x04 not written by the creator */
    int32_t     timelineCount; /* +0x08 arg1 at create time, zeroed by B4 */
    void*       timelines;     /* +0x0c _malloc(arg1<<2, tag, 41) inside the creator */
} spAnimation;

#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(sizeof(spEventData) == 16, "0x285ba4: _calloc(1,16,...) in spEventData_create");
_Static_assert(offsetof(spEventData, intValue) == 0x04, "0x28d230 str r0,[r5,#0x4]");
_Static_assert(offsetof(spEventData, floatValue) == 0x08, "0x28d244 str r0,[r5,#0x8]");
_Static_assert(offsetof(spEventData, stringValue) == 0x0c, "0x28d270 str r0,[r5,#0xc]");
_Static_assert(sizeof(spAnimation) == 16, "0x2812d8 _calloc(1,16,tag,38) in spAnimation_create");
_Static_assert(offsetof(spAnimation, name) == 0x00, "0x2812fc str r0,[r4]");
_Static_assert(offsetof(spAnimation, opaque_04) == 0x04, "creator writes only +0/+8/0xc");
_Static_assert(offsetof(spAnimation, timelineCount) == 0x08, "0x281304 str r7,[r4,#0x8]");
_Static_assert(offsetof(spAnimation, timelines) == 0x0c, "0x281318 str r0,[r4,#0xc]");
#endif

/* Declared synthetic boundaries: bodies NOT recovered in this batch. The
 * fixture stands in, records the arguments, and provides the records.
 *   0x285b94 spEventData_create(name)           88 B, calloc(1,16,tag,36)
 *   0x2812b4 spAnimation_create(name, count)   116 B, calloc(1,16,tag,38) */
extern spEventData* spEventData_create(const char* name);
extern spAnimation* spAnimation_create(const char* name, int32_t timelineCount);

/*
 * B3/B4 stack-frame slice.
 *
 * Base = the parent's sp+0x18; every member below is one slot of the original
 * frame, in original address order, with the writes/reads that pin it. The
 * parent keeps other blocks' slots inside the same frame (+0x3c, +0x40, +0x48,
 * +0x54, +0x58, +0x5c, +0x74 are scratch for B5..B17), so those are modelled
 * as reserved_* here and never touched by B1..B4.
 *
 * Ownership: the parent wrote the tree slot (+0x0c) and B2 wrote the animation
 * slot (+0x04) before B3 runs; B3 adds the two input spills (+0x00/+0x08), the
 * eight node slots (+0x10..+0x38) and the key/magic cache (+0x48..+0x58).
 */
typedef struct spAnimationFrame {
    void*       data;          /* +0x00  [sp,#0x18]  0x28d310 str r9 (spSkeletonData*) */
    Json*       animation;     /* +0x04  [sp,#0x1c]  B2 0x28d2c8, tail 0x28e798; B3 reads it 8x */
    void*       skeletonJson;  /* +0x08  [sp,#0x20]  0x28d314 str r8 (spSkeletonJson*, for setError) */
    Json*       tree;          /* +0x0c  [sp,#0x24]  parent's root Json 0x28b8ac; untouched by B1..B4 */
    Json*       drawOrder;     /* +0x10  [sp,#0x28]  0x28d398, B3b 0x28eb38, read 0x28d4a4 */
    Json*       slotsChild;    /* +0x14  [sp,#0x2c]  0x28d4e4, read by the B5 loop head 0x28d62c */
    Json*       bones;         /* +0x18  [sp,#0x30]  0x28d328, read 0x28d3b4 */
    Json*       ik;            /* +0x1c  [sp,#0x34]  0x28d348, read 0x28d40c */
    Json*       transform;     /* +0x20  [sp,#0x38]  0x28d35c, read 0x28d410 */
    uint32_t    reserved_3c;   /* +0x24  [sp,#0x3c]  scratch, read by the deform block 0x28e100 */
    uint32_t    reserved_40;   /* +0x28  [sp,#0x40]  scratch, B5 caches "color" here 0x28d510 */
    Json*       paths;         /* +0x2c  [sp,#0x44]  0x28d370, read 0x28d424 */
    uint32_t    reserved_48;   /* +0x30  [sp,#0x48]  scratch, B5 caches "attachment" here 0x28d518 */
    Json*       events;        /* +0x34  [sp,#0x4c]  0x28d3ac, read 0x28d4a8 */
    Json*       deform;        /* +0x38  [sp,#0x50]  0x28d384, read 0x28d460 */
    uint32_t    reserved_54;   /* +0x3c  [sp,#0x54]  scratch, B5 caches "name" here 0x28d51c */
    uint32_t    reserved_58;   /* +0x40  [sp,#0x58]  scratch */
    uint32_t    reserved_5c;   /* +0x44  [sp,#0x5c]  scratch */
    uint32_t    div3_magic;    /* +0x48  [sp,#0x60]  0x28d304 write; 0x28e128 ldrne (deform, NOT recovered) */
    const char* bonesKey;      /* +0x4c  [sp,#0x64]  0x28d2ec, read 0x28d318 */
    const char* slotsKey;      /* +0x50  [sp,#0x68]  0x28d2fc, read 0x28d324 */
    const char* ikKey;         /* +0x54  [sp,#0x6c]  0x28d308, read 0x28d334 */
    const char* transformKey;  /* +0x58  [sp,#0x70]  0x28d30c, read 0x28d344 */
    uint32_t    reserved_74;   /* +0x5c  [sp,#0x74]  scratch, color block 0x28d900/0x28d9d0 */
} spAnimationFrame;

#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(sizeof(spAnimationFrame) == 0x60, "frame slice [sp,#0x18]..[sp,#0x74]");
_Static_assert(offsetof(spAnimationFrame, data) == 0x00, "0x28d310 str r9,[sp,#0x18]");
_Static_assert(offsetof(spAnimationFrame, animation) == 0x04, "0x28d31c ldr r0,[sp,#0x1c]");
_Static_assert(offsetof(spAnimationFrame, skeletonJson) == 0x08, "0x28d314 str r8,[sp,#0x20]");
_Static_assert(offsetof(spAnimationFrame, tree) == 0x0c, "0x28d294 ldr r0,[sp,#0x24]");
_Static_assert(offsetof(spAnimationFrame, drawOrder) == 0x10, "0x28d398 str r0,[sp,#0x28]");
_Static_assert(offsetof(spAnimationFrame, slotsChild) == 0x14, "0x28d4e4 str r4,[sp,#0x2c]");
_Static_assert(offsetof(spAnimationFrame, bones) == 0x18, "0x28d328 str r0,[sp,#0x30]");
_Static_assert(offsetof(spAnimationFrame, ik) == 0x1c, "0x28d348 str r0,[sp,#0x34]");
_Static_assert(offsetof(spAnimationFrame, transform) == 0x20, "0x28d35c str r0,[sp,#0x38]");
_Static_assert(offsetof(spAnimationFrame, paths) == 0x2c, "0x28d370 str r0,[sp,#0x44]");
_Static_assert(offsetof(spAnimationFrame, events) == 0x34, "0x28d3ac str r0,[sp,#0x4c]");
_Static_assert(offsetof(spAnimationFrame, deform) == 0x38, "0x28d384 str r0,[sp,#0x50]");
_Static_assert(offsetof(spAnimationFrame, div3_magic) == 0x48, "0x28d304 str r1,[sp,#0x60]");
_Static_assert(offsetof(spAnimationFrame, bonesKey) == 0x4c, "0x28d2ec str r0,[sp,#0x64]");
_Static_assert(offsetof(spAnimationFrame, slotsKey) == 0x50, "0x28d2fc str r2,[sp,#0x68]");
_Static_assert(offsetof(spAnimationFrame, ikKey) == 0x54, "0x28d308 str r3,[sp,#0x6c]");
_Static_assert(offsetof(spAnimationFrame, transformKey) == 0x58, "0x28d30c str r0,[sp,#0x70]");
_Static_assert(offsetof(spAnimationFrame, reserved_74) == 0x5c, "0x28d900 str r7,[sp,#0x74]");
#endif

/*
 * B1 first half (0x28d19c..0x28d1dc):
 *   events = Json_getItem(tree, "events"); absent -> return NULL, nothing
 *   written. Otherwise data+0x2c = events->unk_0c (Json size) BEFORE the
 *   allocation, data+0x30 = _malloc(size*4, TAG, 1028). The array is stored
 *   even when events->child == NULL. Returns events->child (may be NULL).
 */
Json* readSkeletonData_eventsArray(Json* tree, void* data_raw, uint32_t* out_count);

/*
 * B1 loop (0x28d20c..0x28d28c): one EventData per child of the events node.
 * Name argument is child->name (+0x1c, the Json member key); there is NO
 * Json_getString("name") in this block. int/float/string keys with default 0;
 * a non-NULL string is deep-copied by _malloc(strlen+1,TAG,1034)+strcpy into
 * +0x0c. Each record is published into the reloaded data->events array with a
 * byte cursor (+=4), then the child list advances. Loop condition is the child
 * list, never the JSON size.
 */
void readSkeletonData_eventsSegment(Json* tree, void* data_raw);

/*
 * B2 (0x28d290..0x28d2d4):
 *   animations = Json_getItem(tree, "animations"); absent -> return NULL
 *   (caller goes straight to Json_dispose + return data).
 *   data+0x38 = _malloc(animations->unk_0c*4, TAG, 1043); data+0x34
 *   (animationsCount) is NOT written in this block. Returns animations->child
 *   (the first animation object, may be NULL) after the array is published.
 */
Json* readSkeletonData_animationsArray(Json* tree, void* data_raw);

/*
 * B3 preamble (0x28d2d4..0x28d314) — runs ONCE per animations array, straight
 * after B2's non-NULL fall-through. It caches four key literals and writes the
 * 0x55555556 word into the [sp,#0x60] slot:
 *   [sp,#0x64] "bones"      pool 0x28c9f8 / add 0x28d2e4 -> 0x357b88
 *   [sp,#0x68] "slots"      pool 0x28c9fc / add 0x28d2f0 -> 0x357b90
 *   [sp,#0x6c] "ik"         pool 0x28ca00 / add 0x28d2f8 -> 0x357bfc
 *   [sp,#0x70] "transform"  pool 0x28ca04 / add 0x28d300 -> 0x357c48
 *   [sp,#0x60] 0x55555556   movw 0x5556 (0x28d2d8) / movt 0x5555 (0x28d2e0)
 *                           / str r1,[sp,#0x60] (0x28d304)
 * It also spills the two block inputs: [sp,#0x18] = data (r9), [sp,#0x20] =
 * spSkeletonJson (r8). The frame's animation slot (+0x04) is written by B2 at
 * 0x28d2c8, not here. Nothing else is touched; there is no allocation.
 */
void readSkeletonData_animationFrameInit(spAnimationFrame* frame, void* data,
                                         void* skeletonJson);

/*
 * B3 loop head + 8-key lookup (0x28d318..0x28d3b0) — executes per animation.
 * The back edge 0x28e79c -> 0x28d318 re-enters HERE, so the four cached keys
 * above are loop-invariant while the last four keys are re-materialised from
 * the literal pool on every iteration:
 *   0x28d354/0x28d358 "paths"      -> 0x357e5c
 *   0x28d368/0x28d36c "deform"     -> 0x357de4
 *   0x28d37c/0x28d380 "drawOrder"  -> 0x357e64
 *   0x28d390/0x28d394 "events"     -> 0x357d94
 * Eight Json_getItem(animation, key) calls in address order, results stored to
 *   bones [sp,#0x30], slots r4, ik [sp,#0x34], transform [sp,#0x38],
 *   paths [sp,#0x44], deform [sp,#0x50], drawOrder [sp,#0x28], events [sp,#0x4c].
 * `slots` is kept in r4 (no stack slot); it is returned here so B4 can reuse
 * it exactly as 0x28d3e4/0x28d4c8 read r4.
 * Last instruction: 0x28d3a8 cmp r1,#0 / 0x28d3b0 beq 0x28eb28 (B3b).
 */
Json* readSkeletonData_animationKeys(spAnimationFrame* frame);

/*
 * B3b (0x28eb28..0x28eb40), out of line at the function tail:
 *   drawOrder = Json_getItem(animation, "draworder")   pool 0x28eb24 /
 *              add 0x28eb30 -> 0x357e70 (lowercase legacy key)
 * then 0x28eb3c b 0x28d3b4 (B4). The store is UNCONDITIONAL: a second miss
 * overwrites the slot with NULL (it is already NULL on the only entry path).
 *
 * Evidence note (not a guess): Json_getItem compares with strcasecmp
 * (0x287414 bl strcasecmp@plt), so "drawOrder" and "draworder" select the same
 * children and this retry can never find a node the first lookup missed. The
 * block is recovered as written; see functions.json open[] for the consequence.
 */
void readSkeletonData_animationLegacyDrawOrder(spAnimationFrame* frame);

/*
 * B4 (0x28d3b4..0x28d4ec): timelineCount sum + spAnimation_create.
 * Reads the eight node slots, sums an int per group and calls
 *   spAnimation_create(frame->animation->name, count)   0x28d4c0/0x28d4c4
 * then zeroes animation+0x08 (0x28d4cc/0x28d4d4) and, when the slots node is
 * non-NULL, publishes slots->child into [sp,#0x2c] (0x28d4dc/0x28d4e4).
 * Sum shape (per instruction, NOT from a stock spine-c source):
 *   bones   : sum of child->unk_0c over bones->child chain   (0x28d3d0..0x28d3e0)
 *   slots   : same over slots->child chain                   (0x28d3f8..0x28d408)
 *   ik      : ik->unk_0c, once                               (0x28d418)
 *   transform: transform->unk_0c, once                        (0x28d42c)
 *   paths   : sum over paths->child chain                     (0x28d44c..0x28d45c)
 *   deform  : double loop, sum over each skin->child chain    (0x28d478..0x28d4a0)
 *   drawOrder: +1 when the node exists                        (0x28d4b4)
 *   events  : +1 when the node exists                        (0x28d4bc)
 */
spAnimation* readSkeletonData_animationTimelines(spAnimationFrame* frame, Json* slotsNode);

#endif /* YY_SPINE_READ_ANIMATIONS_H */
