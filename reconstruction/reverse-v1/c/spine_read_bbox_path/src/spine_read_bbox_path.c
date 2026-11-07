/*
 * readSkeletonData caller blocks, not standalone original functions.
 * Original SHA 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * tier: bytecode_anchored. Full loader assembly/animation paths remain open.
 * boundingbox 0x28cd6c..0x28cdac; path 0x28ca5c..0x28cb20 (exclusive ends).
 */
#include "spine_read_bbox_path.h"
static const char tag[] =
    "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";
static float load_scale(const void *json) {
    float f;
    __asm__ volatile("vldr %0, [%1]" : "=t"(f) : "r"(json) : "memory");
    return f;
}
void readSkeletonData_boundingBoxFields(Json *map, spBoundingBoxAttachment *a,
                                       const void *json, spAttachmentLoader *loader) {
    uint32_t count = (uint32_t)Json_getInt(map, "vertexCount", 0); /* 0x28cd7c */
    uint32_t vlen = count << 1; /* 0x28cd88; unsigned ARM32 wrap, no C UB. */
    _readVertices(json, map, &a->super, vlen); /* 0x28cd94 */
    /* 0x28cd98 REALLY writes +0x18, not +0x20. In weighted inputs this
     * overwrites the helper's float count; do not 'repair' the original. */
    a->super.opaque_18 = vlen;
    spAttachmentLoader_configureAttachment(loader, &a->super.super); /* 0x28cda4 */
}
void readSkeletonData_pathAttachmentFields(Json *map, spPathAttachment *a,
                                          const void *json) {
    a->opaque_2c = (uint32_t)Json_getInt(map, "closed", 0); /* 0x28ca6c/7c */
    a->opaque_30 = (uint32_t)Json_getInt(map, "constantSpeed", 1); /* 0x28ca84/94 */
    int32_t count = Json_getInt(map, "vertexCount", 0); /* 0x28ca9c */
    _readVertices(json, map, &a->super, (uint32_t)count << 1); /* 0x28cab4 */
    /* 0x28cac0..d0 signed magic divide, truncates toward zero. Count store
     * PRECEDES allocation, so debug allocator can observe/modify it. */
    uint32_t lengthCount = (uint32_t)(count / 3);
    a->opaque_24 = lengthCount;
    a->owned_28 = _malloc(lengthCount << 2, tag, 985u); /* 0x28cad8/cae4 */
    Json *lengths = Json_getItem(map, "lengths"); /* 0x28caec */
    Json *child = lengths->child; /* 0x28caf0: no missing-key NULL guard. */
    if (!child) return; /* 0x28caf4..f8 */
    float *out = a->owned_28;
    do {
        float x = child->float_value; /* 0x28cb00 */
        float scale = load_scale(json); /* 0x28cb04; not a caller snapshot. */
        float value;
        __asm__ volatile("vmul.f32 %0, %1, %2" : "=t"(value) : "t"(x), "t"(scale) : "memory");
        Json *next = child->next; /* 0x28cb0c before store. */
        *out++ = value; /* 0x28cb14; loop follows chain, not lengthCount. */
        child = next;
    } while (child);
}
