/*
 * spine_read_animations.c — byte-anchored C translation of two caller blocks
 * of spSkeletonJson_readSkeletonData (0x28b84c, 13044 B) in
 * libyoyo_armv7.so (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 *   B1 0x28d19c..0x28d290  244 B / 61 insns
 *      skeleton-wide events array (malloc line 1028) + EventData loop
 *      (malloc line 1034 for the string deep copy)
 *   B2 0x28d290..0x28d2d4   68 B / 17 insns
 *      animations array (malloc line 1043)
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

/* spSkeletonData word offsets used by these two blocks (the rest of the
 * 84-byte record is spine_skeleton_data's contract):
 *   +0x2c eventsCount      (0x28d1c0 str r0,[r9,#0x2c])
 *   +0x30 events array     (0x28d1d8 str r0,[r9,#0x30])
 *   +0x34 animationsCount  (NOT written here; per-item ++ at 0x28e778)
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
 *   0x28d2c8 str r4,[sp,#0x1c]    -> spill for the B3 outer loop
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
