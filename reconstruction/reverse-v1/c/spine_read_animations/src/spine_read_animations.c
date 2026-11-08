/*
 * spine_read_animations.c — byte-anchored C translation of five caller blocks
 * of spSkeletonJson_readSkeletonData (0x28b84c, 13044 B) in
 * libyoyo_armv7.so (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 *   B1  0x28d19c..0x28d290  244 B /  61 insns
 *      skeleton-wide events array (malloc line 1028) + EventData loop
 *      (malloc line 1034 for the string deep copy)
 *   B2  0x28d290..0x28d2d4   68 B /  17 insns
 *      animations array (malloc line 1043)
 *   B3  0x28d2d4..0x28d3b4  224 B /  56 insns
 *      per-animation preamble (4 cached key literals + 0x55555556 in
 *      [sp,#0x60]) and the 8-key Json_getItem lookup; no allocation
 *   B3b 0x28eb28..0x28eb40   24 B /   6 insns
 *      legacy "draworder" retry, out of line at the function tail; no allocation
 *   B4  0x28d3b4..0x28d4ec  312 B /  78 insns
 *      timelineCount sum + spAnimation_create; no allocation
 *
 * Evidence tier: bytecode_anchored. The original was not executed. Every
 * statement below carries the original instruction address it comes from.
 * Nothing is taken from a stock spine-c source: this build's key set and
 * field order were read from the instruction stream only.
 */

#include "spine_read_animations.h"
#include "../../spine_alloc/src/spine_alloc.h"

#include <stddef.h>

/* libc imports used by the original: 0xb6538 strlen@plt, 0xb65a4 strcpy@plt. */
extern size_t strlen(const char* s);
extern char* strcpy(char* dst, const char* src);

/* 0x357b08, resolved twice: 0x28d1bc/0x28d1c4 (B1) and 0x28d1ec/0x28d1fc
 * (B1 second copy) / 0x28d2b0/0x28d2b8 (B2). */
static const char* const TAG =
    "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";

/* spSkeletonData word offsets used by B1/B2 (the rest of the 84-byte record is
 * spine_skeleton_data's contract):
 *   +0x2c eventsCount      (0x28d1c0 str r0,[r9,#0x2c])
 *   +0x30 events array     (0x28d1d8 str r0,[r9,#0x30])
 *   +0x34 animationsCount  (NOT written by B2; per-item ++ at 0x28e778)
 *   +0x38 animations array (0x28d2cc str r0,[r9,#0x38]) */
#define SD_EVENTSCOUNT_OFF       0x2cu
#define SD_EVENTS_OFF            0x30u
#define SD_ANIMATIONS_OFF        0x38u

/*
 * B1 allocation half, 0x28d19c..0x28d1dc.
 *
 *   0x28d19c ldr r1,[pc,#-0x7cc]  -> pool 0x28c9d8, word 0xcabe8
 *   0x28d1a0 ldr r0,[sp,#0x24]    -> root tree
 *   0x28d1a4 add r1,pc,r1         -> 0x357d94 "events"
 *   0x28d1a8 bl  Json_getItem
 *   0x28d1ac subs r4,r0,#0
 *   0x28d1b0 beq 0x28d290         -> B2 (nothing written)
 *   0x28d1b4 ldr r0,[r4,#0xc]     -> Json size (the declared count)
 *   0x28d1b8 movw r2,#0x404       -> malloc line 1028
 *   0x28d1c0 str r0,[r9,#0x2c]    -> count published BEFORE the allocation
 *   0x28d1c8 lsl r0,r0,#2         -> size wraps at 32 bits
 *   0x28d1cc bl  _malloc
 *   0x28d1d0 ldr r4,[r4,#0x4]     -> events->child
 *   0x28d1d4 cmp r4,#0
 *   0x28d1d8 str r0,[r9,#0x30]    -> array published even when child == 0
 *   0x28d1dc beq 0x28d290         -> B2 (count+array already published)
 */
Json* readSkeletonData_eventsArray(Json* tree, void* data_raw, uint32_t* out_count)
{
    Json* events;
    uint32_t count;
    void** array;

    events = Json_getItem(tree, "events");          /* 0x28d19c..0x28d1a8 */
    if (events == 0) return 0;                      /* 0x28d1ac/0x28d1b0 */

    count = events->unk_0c;                         /* 0x28d1b4 */
    *(uint32_t*)((char*)data_raw + SD_EVENTSCOUNT_OFF) = count; /* 0x28d1c0 */

    array = (void**)_malloc(count << 2, TAG, 1028u); /* 0x28d1b8/0x28d1c8/0x28d1cc */
    {
        Json* child = events->child;                /* 0x28d1d0 (after _malloc) */
        *(void***)((char*)data_raw + SD_EVENTS_OFF) = array; /* 0x28d1d8 */
        *out_count = count;
        return child;                               /* 0x28d1d4 cmp / 0x28d1dc beq */
    }
}

/*
 * B1 loop, 0x28d20c..0x28d28c.
 *
 *   0x28d20c ldr r0,[r4,#0x1c]    -> child->name, the JSON MEMBER KEY.
 *                                     No Json_getString("name") exists here.
 *   0x28d210 bl  spEventData_create(name)
 *   0x28d224 bl  Json_getInt(eventMap,"int",0)     -> +0x04
 *   0x28d238 bl  Json_getFloat(eventMap,"float",0) -> +0x08 (softfp bits)
 *   0x28d24c bl  Json_getString(eventMap,"string",0)
 *   0x28d250 subs r11,r0,#0
 *   0x28d254 beq 0x28d278         -> no string: +0x0c untouched
 *   0x28d258 bl  strlen
 *   0x28d260 movw r2,#0x40a       -> malloc line 1034
 *   0x28d264 add r0,r0,#1
 *   0x28d268 bl  _malloc
 *   0x28d270 str r0,[r5,#0xc]     -> pointer cached BEFORE strcpy
 *   0x28d274 bl  strcpy
 *   0x28d278 ldr r3,[r9,#0x30]    -> reload data->events after the callees
 *   0x28d27c str r5,[r3,r10]      -> publish at the byte cursor
 *   0x28d280 add r10,r10,#4
 *   0x28d284 ldr r4,[r4]          -> child = child->next
 *   0x28d288 cmp r4,#0
 *   0x28d28c bne 0x28d20c         -> loop condition is the CHILD LIST,
 *                                     never the declared count.
 */
void readSkeletonData_eventsSegment(Json* tree, void* data_raw)
{
    uint32_t count = 0;
    uint32_t byte_offset = 0;                       /* 0x28d1e4 mov r10,#0 */
    Json* eventMap;

    eventMap = readSkeletonData_eventsArray(tree, data_raw, &count);
    if (eventMap == 0) return;                      /* 0x28d1b0 or 0x28d1dc */

    while (eventMap != 0) {                         /* 0x28d288/0x28d28c */
        spEventData* eventData;
        const char* string_value;

        eventData = spEventData_create(eventMap->name); /* 0x28d20c/0x28d210 */

        eventData->intValue = Json_getInt(eventMap, "int", 0); /* 0x28d220..0x28d230 */
        eventData->floatValue = Json_getFloat(eventMap, "float", 0.0f); /* 0x28d234..0x28d244 */
        string_value = Json_getString(eventMap, "string", 0); /* 0x28d248..0x28d24c */

        if (string_value != 0) {                    /* 0x28d250/0x28d254 */
            char* copy = (char*)_malloc(
                (uint32_t)strlen(string_value) + 1u, TAG, 1034u); /* 0x28d264/0x28d268 */
            eventData->stringValue = copy;          /* 0x28d270 */
            strcpy(copy, string_value);             /* 0x28d274 */
        }

        {   /* 0x28d278: the array base is re-read after the callees. */
            void** events_array = *(void***)((char*)data_raw + SD_EVENTS_OFF);
            *(void**)((char*)events_array + byte_offset) = eventData; /* 0x28d27c */
        }
        byte_offset += 4u;                          /* 0x28d280 */
        eventMap = eventMap->next;                  /* 0x28d284 */
    }
}

/*
 * B2, 0x28d290..0x28d2d4.
 *
 *   0x28d290 ldr r1,[pc,#-0x8a8]  -> pool 0x28c9f0, word 0xcabac -> 0x357e4c
 *   0x28d294 ldr r0,[sp,#0x24]    -> root tree
 *   0x28d298 add r1,pc,r1         -> "animations"
 *   0x28d29c bl  Json_getItem
 *   0x28d2a0 subs r4,r0,#0
 *   0x28d2a4 beq 0x28e7a4         -> segment end: Json_dispose + return data
 *   0x28d2a8 ldr r0,[r4,#0xc]     -> Json size
 *   0x28d2ac movw r2,#0x413       -> malloc line 1043
 *   0x28d2b4 lsl r0,r0,#2
 *   0x28d2bc bl  _malloc
 *   0x28d2c0 ldr r4,[r4,#0x4]     -> animations->child (first animation)
 *   0x28d2c4 cmp r4,#0
 *   0x28d2c8 str r4,[sp,#0x1c]    -> frame animation slot for B3/B4
 *   0x28d2cc str r0,[r9,#0x38]    -> animations array; +0x34 NOT touched
 *   0x28d2d0 beq 0x28e7a4
 */
Json* readSkeletonData_animationsArray(Json* tree, void* data_raw)
{
    Json* animations;
    uint32_t count;
    void** array;

    animations = Json_getItem(tree, "animations");  /* 0x28d290..0x28d29c */
    if (animations == 0) return 0;                  /* 0x28d2a0/0x28d2a4 */

    count = animations->unk_0c;                     /* 0x28d2a8 */
    array = (void**)_malloc(count << 2, TAG, 1043u); /* 0x28d2ac/0x28d2b4/0x28d2bc */
    {
        Json* child = animations->child;            /* 0x28d2c0 (after _malloc) */
        *(void***)((char*)data_raw + SD_ANIMATIONS_OFF) = array; /* 0x28d2cc */
        return child;                               /* 0x28d2c4 cmp / 0x28d2d0 beq */
    }
}

/* ===================================================================== */
/* B3 — per-animation preamble and 8-key lookup (0x28d2d4..0x28d3b4)      */
/* ===================================================================== */

/*
 * B3 preamble, 0x28d2d4..0x28d314. Reached by fall-through from B2's
 * 0x28d2d0 beq-not-taken and NEVER re-entered: the outer loop's back edge is
 * 0x28e79c bne 0x28d318, i.e. it re-enters at the loop head inside B3, not
 * here. So everything below is executed once per animations array.
 *
 *   0x28d2d4 ldr r0,[pc,#-0x8e4]  -> pool 0x28c9f8, word -> 0x357b88 "bones"
 *   0x28d2d8 movw r1,#0x5556
 *   0x28d2dc ldr r2,[pc,#-0x8e8]  -> pool 0x28c9fc -> 0x357b90 "slots"
 *   0x28d2e0 movt r1,#0x5555      -> r1 = 0x55555556
 *   0x28d2e4 add r0,pc,r0
 *   0x28d2e8 ldr r3,[pc,#-0x8f0]  -> pool 0x28ca00 -> 0x357bfc "ik"
 *   0x28d2ec str r0,[sp,#0x64]    -> cached key 1
 *   0x28d2f0 add r2,pc,r2
 *   0x28d2f4 ldr r0,[pc,#-0x8f8]  -> pool 0x28ca04 -> 0x357c48 "transform"
 *   0x28d2f8 add r3,pc,r3
 *   0x28d2fc str r2,[sp,#0x68]    -> cached key 2
 *   0x28d300 add r0,pc,r0
 *   0x28d304 str r1,[sp,#0x60]    -> the 0x55555556 word
 *   0x28d308 str r3,[sp,#0x6c]    -> cached key 3
 *   0x28d30c str r0,[sp,#0x70]    -> cached key 4
 *   0x28d310 str r9,[sp,#0x18]    -> data spill (re-read at 0x28e774/0x28ea50)
 *   0x28d314 str r8,[sp,#0x20]    -> skeletonJson spill (re-read at 0x28ea48)
 *
 * The 0x28d304 word: movw 0x5556 + movt 0x5555 = 0x55555556, the constant of a
 * signed truncating division by 3 (0x55555556*v >> 32, minus the sign bit).
 * Its only reader in the whole segment is 0x28e128 ldrne r1,[sp,#0x60] inside
 * the deform block (feeding 0x28e134 smull r1,r2,r1,r3 and 0x28e13c
 * subne r3,r2,r3,asr#31). That block is NOT recovered in this batch, so the
 * slot is written and documented here, never consumed: see functions.json
 * open[] item on 0x55555556.
 */
void readSkeletonData_animationFrameInit(spAnimationFrame* frame, void* data,
                                         void* skeletonJson)
{
    frame->bonesKey = "bones";                  /* 0x28d2d4/0x28d2e4/0x28d2ec */
    frame->slotsKey = "slots";                  /* 0x28d2dc/0x28d2f0/0x28d2fc */
    frame->ikKey = "ik";                        /* 0x28d2e8/0x28d2f8/0x28d308 */
    frame->transformKey = "transform";          /* 0x28d2f4/0x28d300/0x28d30c */
    frame->div3_magic = 0x55555556u;            /* 0x28d2d8/0x28d2e0/0x28d304 */
    frame->data = data;                         /* 0x28d310 str r9,[sp,#0x18] */
    frame->skeletonJson = skeletonJson;         /* 0x28d314 str r8,[sp,#0x20] */
}

/*
 * B3 loop head + 8-key lookup, 0x28d318..0x28d3b0.
 *
 * Repeated shape: ldr r1,[sp,#key_slot] / ldr r0,[sp,#0x1c] / bl Json_getItem /
 * store. The first four use the cached literals; the last four rebuild their
 * key from the literal pool every iteration:
 *   0x28d354 ldr r1,[pc,#-0x954] + 0x28d358 add -> 0x357e5c "paths"
 *   0x28d368 ldr r1,[pc,#-0x964] + 0x28d36c add -> 0x357de4 "deform"
 *   0x28d37c ldr r1,[pc,#-0x974] + 0x28d380 add -> 0x357e64 "drawOrder"
 *   0x28d390 ldr r1,[pc,#-0x984] + 0x28d394 add -> 0x357d94 "events"
 *
 *   0x28d328 str r0,[sp,#0x30]  bones
 *   0x28d338 mov r4,r0          slots (register, no stack slot)
 *   0x28d348 str r0,[sp,#0x34]  ik
 *   0x28d35c str r0,[sp,#0x38]  transform
 *   0x28d370 str r0,[sp,#0x44]  paths
 *   0x28d384 str r0,[sp,#0x50]  deform
 *   0x28d398 str r0,[sp,#0x28]  drawOrder
 *   0x28d3ac str r0,[sp,#0x4c]  events
 *   0x28d3a4 ldr r1,[sp,#0x28] / 0x28d3a8 cmp r1,#0 / 0x28d3b0 beq 0x28eb28
 */
Json* readSkeletonData_animationKeys(spAnimationFrame* frame)
{
    Json* slots;

    /* 0x28d318 ldr r1,[sp,#0x64] / 0x28d31c ldr r0,[sp,#0x1c]
     * 0x28d320 bl Json_getItem / 0x28d328 str r0,[sp,#0x30] */
    frame->bones = Json_getItem(frame->animation, frame->bonesKey);

    /* 0x28d324 ldr r1,[sp,#0x68] / 0x28d32c ldr r0,[sp,#0x1c]
     * 0x28d330 bl Json_getItem / 0x28d338 mov r4,r0 */
    slots = Json_getItem(frame->animation, frame->slotsKey);

    /* 0x28d334 ldr r1,[sp,#0x6c] / 0x28d33c ldr r0,[sp,#0x1c]
     * 0x28d340 bl Json_getItem / 0x28d348 str r0,[sp,#0x34] */
    frame->ik = Json_getItem(frame->animation, frame->ikKey);

    /* 0x28d344 ldr r1,[sp,#0x70] / 0x28d34c ldr r0,[sp,#0x1c]
     * 0x28d350 bl Json_getItem / 0x28d35c str r0,[sp,#0x38] */
    frame->transform = Json_getItem(frame->animation, frame->transformKey);

    /* 0x28d354 ldr r1,[pc,#-0x954] / 0x28d358 add r1,pc,r1
     * 0x28d360 ldr r0,[sp,#0x1c] / 0x28d364 bl Json_getItem
     * 0x28d370 str r0,[sp,#0x44] */
    frame->paths = Json_getItem(frame->animation, "paths");

    /* 0x28d368 ldr r1,[pc,#-0x964] / 0x28d36c add r1,pc,r1
     * 0x28d374 ldr r0,[sp,#0x1c] / 0x28d378 bl Json_getItem
     * 0x28d384 str r0,[sp,#0x50] */
    frame->deform = Json_getItem(frame->animation, "deform");

    /* 0x28d37c ldr r1,[pc,#-0x974] / 0x28d380 add r1,pc,r1
     * 0x28d388 ldr r0,[sp,#0x1c] / 0x28d38c bl Json_getItem
     * 0x28d398 str r0,[sp,#0x28] */
    frame->drawOrder = Json_getItem(frame->animation, "drawOrder");

    /* 0x28d390 ldr r1,[pc,#-0x984] / 0x28d394 add r1,pc,r1
     * 0x28d39c ldr r0,[sp,#0x1c] / 0x28d3a0 bl Json_getItem
     * 0x28d3ac str r0,[sp,#0x4c] */
    frame->events = Json_getItem(frame->animation, "events");

    if (frame->drawOrder == 0) {                /* 0x28d3a4/0x28d3a8/0x28d3b0 beq 0x28eb28 */
        readSkeletonData_animationLegacyDrawOrder(frame); /* out-of-line block, b 0x28d3b4 */
    }

    return slots;                               /* 0x28d338 mov r4,r0 -> r4 at 0x28d3e4 */
}

/*
 * B3b, 0x28eb28..0x28eb40 — placed at the function tail by the compiler and
 * reached only through 0x28d3b0 beq 0x28eb28 (the "drawOrder" lookup missed).
 *
 *   0x28eb28 ldr r1,[pc,#-0xc]    -> pool 0x28eb24 -> 0x357e70 "draworder"
 *   0x28eb2c ldr r0,[sp,#0x1c]    -> the same animation node
 *   0x28eb30 add r1,pc,r1
 *   0x28eb34 bl  Json_getItem
 *   0x28eb38 str r0,[sp,#0x28]    -> unconditional store into the drawOrder slot
 *   0x28eb3c b   0x28d3b4         -> B4
 *
 * No NULL test follows the store: on a second miss the slot is overwritten with
 * the NULL it already held. Note that Json_getItem compares case-insensitively
 * (0x287414 bl strcasecmp@plt), so this retry can never find a node that the
 * 0x28d38c lookup missed. Recovered as written; see functions.json open[].
 */
void readSkeletonData_animationLegacyDrawOrder(spAnimationFrame* frame)
{
    frame->drawOrder = Json_getItem(frame->animation, "draworder"); /* 0x28eb28..0x28eb38 */
}

/* ===================================================================== */
/* B4 — timelineCount sum + spAnimation_create (0x28d3b4..0x28d4ec)       */
/* ===================================================================== */

/*
 * B4 sums one int per animation group and hands the total to
 * spAnimation_create, then resets the created record's +0x08 and publishes
 * slots->child for the B5 loop.
 *
 * bones (0x28d3b4..0x28d3e0):
 *   0x28d3b4 ldr r2,[sp,#0x30] / 0x28d3b8 cmp / 0x28d3bc beq 0x28ea80
 *   0x28ea80 ldr r3,[sp,#0x30]  -> r3 := bones (== 0) / 0x28ea84 b 0x28d3e4
 *   0x28d3c0 ldr r2,[r2,#0x4]   -> bones->child
 *   0x28d3c4 cmp / 0x28d3c8 beq 0x28ea40 -> 0x28ea40 mov r3,r2 (child == 0) / b 0x28d3e4
 *   0x28d3cc mov r3,#0          -> accumulator
 *   0x28d3d0 ldr r1,[r2,#0xc]   -> child->unk_0c
 *   0x28d3d4 ldr r2,[r2]        -> child = child->next
 *   0x28d3d8 add r3,r3,r1
 *   0x28d3dc cmp r2,#0 / 0x28d3e0 bne 0x28d3d0
 *
 * slots (0x28d3e4..0x28d408): same shape on r4 (the node returned by B3) into
 * the same r3 accumulator.
 *
 * ik / transform (0x28d40c..0x28d438): NOT a child loop — one field read each,
 *   and the NULL branch reloads the (zero) node word itself:
 *   0x28d414 cmp r0,#0 / 0x28d418 ldrne r2,[r0,#0xc] / 0x28d41c ldreq r2,[sp,#0x34]
 *   0x28d428 add r3,r3,r2
 *   0x28d42c ldrne r2,[r1,#0xc] / 0x28d430 ldreq r2,[sp,#0x38]
 *   0x28d438 add r1,r3,r2       -> accumulator moves from r3 to r1
 *
 * paths (0x28d43c..0x28d45c): child-chain loop on top of r1.
 * deform (0x28d460..0x28d4a0): two nested loops — deform->child are skins,
 *   skin->child are slots, and the summed field belongs to the slot node.
 * drawOrder / events (0x28d4a4..0x28d4bc): +1 each when the node exists.
 *
 *   0x28d4c0 ldr r0,[r2,#0x1c]  -> r2 = [sp,#0x1c] = the animation node,
 *                                  r0 = its Json member key (the name)
 *   0x28d4c4 bl spAnimation_create(name, count)
 *   0x28d4cc mov r3,#0 / 0x28d4d4 str r3,[r0,#0x8]  -> +0x08 := 0
 *   0x28d4c8 cmp r4,#0 / 0x28d4d8 beq 0x28d640       -> slots absent: next group
 *   0x28d4dc ldr r4,[r4,#0x4] / 0x28d4e0 cmp / 0x28d4e4 str r4,[sp,#0x2c]
 *   0x28d4e8 beq 0x28d640
 */
spAnimation* readSkeletonData_animationTimelines(spAnimationFrame* frame, Json* slotsNode)
{
    uint32_t total;

    /* 0x28d3b4..0x28d3e0 */
    if (frame->bones == 0) {
        total = 0;                              /* 0x28ea80 ldr r3,[sp,#0x30] (bones == 0) */
    } else {
        Json* child = frame->bones->child;      /* 0x28d3c0 */
        if (child == 0) {
            total = 0;                          /* 0x28ea40 mov r3,r2 (child == 0) */
        } else {
            total = 0;                          /* 0x28d3cc mov r3,#0 */
            do {
                uint32_t size = child->unk_0c;  /* 0x28d3d0 */
                child = child->next;            /* 0x28d3d4 */
                total += size;                  /* 0x28d3d8 */
            } while (child != 0);               /* 0x28d3dc/0x28d3e0 */
        }
    }

    /* 0x28d3e4..0x28d408: the slots node is still in r4, exactly as B3 left it. */
    if (slotsNode != 0) {                       /* 0x28d3e4 cmp r4,#0 / 0x28d3e8 beq */
        Json* child = slotsNode->child;         /* 0x28d3ec */
        if (child != 0) {                       /* 0x28d3f0/0x28d3f4 */
            do {
                uint32_t size = child->unk_0c;  /* 0x28d3f8 */
                child = child->next;            /* 0x28d3fc */
                total += size;                  /* 0x28d400 */
            } while (child != 0);               /* 0x28d404/0x28d408 */
        }
    }

    /* 0x28d40c..0x28d438 */
    {
        Json* ik = frame->ik;                   /* 0x28d40c ldr r0,[sp,#0x34] */
        Json* transform = frame->transform;     /* 0x28d410 ldr r1,[sp,#0x38] */
        uint32_t count;

        if (ik != 0) count = ik->unk_0c;        /* 0x28d414/0x28d418 ldrne */
        else count = (uint32_t)(uintptr_t)frame->ik; /* 0x28d41c ldreq r2,[sp,#0x34] */
        total += count;                         /* 0x28d428 add r3,r3,r2 */

        if (transform != 0) count = transform->unk_0c; /* 0x28d42c ldrne */
        else count = (uint32_t)(uintptr_t)frame->transform; /* 0x28d430 ldreq */
        total += count;                         /* 0x28d438 add r1,r3,r2 */
    }

    /* 0x28d43c..0x28d45c */
    {
        Json* paths = frame->paths;             /* 0x28d424 ldr r0,[sp,#0x44] / 0x28d434 cmp */
        if (paths != 0) {                       /* 0x28d43c beq 0x28d460 */
            Json* child = paths->child;         /* 0x28d440 */
            if (child != 0) {                   /* 0x28d444/0x28d448 */
                do {
                    uint32_t size = child->unk_0c; /* 0x28d44c */
                    child = child->next;           /* 0x28d450 */
                    total += size;                 /* 0x28d454 */
                } while (child != 0);              /* 0x28d458/0x28d45c */
            }
        }
    }

    /* 0x28d460..0x28d4a0: deform -> skins -> slots */
    {
        Json* deform = frame->deform;           /* 0x28d460 ldr r2,[sp,#0x50] */
        if (deform != 0) {                      /* 0x28d464/0x28d468 beq 0x28d4a4 */
            Json* skin = deform->child;         /* 0x28d46c */
            if (skin != 0) {                    /* 0x28d470/0x28d474 beq 0x28d4a4 */
                do {                            /* 0x28d478 outer head */
                    Json* slot = skin->child;   /* 0x28d478 ldr r3,[r0,#0x4] */
                    if (slot != 0) {            /* 0x28d47c/0x28d480 beq 0x28d498 */
                        do {
                            uint32_t size = slot->unk_0c; /* 0x28d484 */
                            slot = slot->next;            /* 0x28d488 */
                            total += size;                /* 0x28d48c */
                        } while (slot != 0);              /* 0x28d490/0x28d494 */
                    }
                    skin = skin->next;          /* 0x28d498 ldr r0,[r0] */
                } while (skin != 0);            /* 0x28d49c/0x28d4a0 */
            }
        }
    }

    if (frame->drawOrder != 0) total += 1u;     /* 0x28d4a4/0x28d4b0/0x28d4b4 addne r1,r1,#1 */
    if (frame->events != 0) total += 1u;        /* 0x28d4a8/0x28d4b8/0x28d4bc addne r1,r1,#1 */

    {
        /* 0x28d4ac ldr r2,[sp,#0x1c] / 0x28d4c0 ldr r0,[r2,#0x1c]
         * 0x28d4c4 bl spAnimation_create — name is the Json MEMBER KEY. */
        spAnimation* animation =
            spAnimation_create(frame->animation->name, (int32_t)total);

        animation->timelineCount = 0;           /* 0x28d4cc mov r3,#0 / 0x28d4d4 str r3,[r0,#0x8] */

        if (slotsNode != 0) {                   /* 0x28d4c8 cmp r4,#0 / 0x28d4d8 beq 0x28d640 */
            frame->slotsChild = slotsNode->child; /* 0x28d4dc/0x28d4e4 str r4,[sp,#0x2c] */
        }                                       /* 0x28d4e0 cmp / 0x28d4e8 beq 0x28d640 */

        return animation;                       /* 0x28d4d0 mov r11,r0 */
    }
}
