/*
 * spine_read_animations.h — readSkeletonData entry blocks for the
 * skeleton-wide events array and the animations array.
 *
 * Original image: libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Recovered here (caller blocks of spSkeletonJson_readSkeletonData @0x28b84c):
 *   B1 0x28d19c..0x28d290  61 insns  events array + EventData loop
 *   B2 0x28d290..0x28d2d4  17 insns  animations array allocation
 *
 * These are BLOCKS of the parent loader, not standalone original symbols.
 * No original bytes are executed; every claim is instruction-anchored.
 */
#ifndef YY_SPINE_READ_ANIMATIONS_H
#define YY_SPINE_READ_ANIMATIONS_H

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

#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(sizeof(spEventData) == 16, "0x285ba4: _calloc(1,16,...) in spEventData_create");
_Static_assert(offsetof(spEventData, intValue) == 0x04, "0x28d230 str r0,[r5,#0x4]");
_Static_assert(offsetof(spEventData, floatValue) == 0x08, "0x28d244 str r0,[r5,#0x8]");
_Static_assert(offsetof(spEventData, stringValue) == 0x0c, "0x28d270 str r0,[r5,#0xc]");
#endif

/* Declared synthetic boundary (EventData.c). 0x285b94: calloc(1,16,tag,36)
 * then a strcpy of the single argument into +0x00. Not recovered here. */
extern spEventData* spEventData_create(const char* name);

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

#endif /* YY_SPINE_READ_ANIMATIONS_H */
