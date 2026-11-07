/*
 * readSkeletonData boundingbox + path attachment parses
 *   boundingbox: 0x28cd6c–0x28cda8 (jump table case 1)
 *   path:        0x28ca5c–0x28cb1c (jump table case 4)
 *
 * Recovery source: libyoyo_armv7.so @ 0x28b84c (bank_0240.c)
 *
 * Shared helper: _readVertices @ 0x28b3fc (mislabeled
 * findPathConstraint+0x10c in cards) — 644B/~160 insn, parses the
 * "vertices" JSON array with weighted/unweighted branches.
 *
 * boundingbox:
 *   vertexCount = getInt(map, "vertexCount", 0)
 *   vlen = vertexCount << 1
 *   _readVertices(json, map, attachment, vlen)
 *   attachment+0x18 = vlen (verticesLength)
 *   configureAttachment(loader, attachment)
 *
 * path:
 *   +0x2c = getInt(map, "closed", 0)
 *   +0x30 = getInt(map, "constantSpeed", 1)
 *   vertexCount = getInt(map, "vertexCount", 0)
 *   _readVertices(json, map, attachment, vertexCount << 1)
 *   +0x24 = vertexCount / 3   (smull 0x55555556 magic division, signed,
 *                              NO +1 — spine-c 3.8 reference may differ)
 *   +0x28 = malloc((vertexCount/3) * 4, TAG, 985)
 *   lengths = getItem(map, "lengths") → each child's float_value
 *   [+0x18 direct read] × scale → sequential store (vstmia r2!)
 */

#include "spine_read_bbox_path.h"

extern void* _malloc(int size, const char* tag, int line);

extern Json* Json_getItem(Json* json, const char* key);
extern int Json_getInt(Json* json, const char* key, int fallback);

extern void _readVertices(void* json, Json* attachmentMap,
                          void* attachment, int verticesCount);
extern void spAttachmentLoader_configureAttachment(void* loader, void* attachment);

static const char* TAG = "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";

/*
 * Boundingbox attachment (jump table case 1).
 * json_raw = spSkeletonJson*, loader = json->attachmentLoader.
 */
void readSkeletonData_boundingBoxFields(Json* attachmentMap, void* attachment,
                                         void* json_raw, void* loader) {
    int vertexCount;
    int vlen;

    /* 0x28cd7c: vertexCount = getInt(map, "vertexCount", 0) */
    vertexCount = Json_getInt(attachmentMap, "vertexCount", 0);

    /* 0x28cd88: vlen = vertexCount << 1 */
    vlen = vertexCount << 1;

    /* 0x28cd94: _readVertices(json, map, attachment, vlen) */
    _readVertices(json_raw, attachmentMap, attachment, vlen);

    /* 0x28cd98: attachment+0x18 = vlen */
    *(int*)((char*)attachment + 0x18) = vlen;

    /* 0x28cda4: configureAttachment(loader, attachment) */
    spAttachmentLoader_configureAttachment(loader, attachment);
}

/*
 * Path attachment (jump table case 4).
 * json_scale = spSkeletonJson->scale.
 */
void readSkeletonData_pathAttachmentFields(Json* attachmentMap, void* attachment,
                                            void* json_raw, float json_scale) {
    int vertexCount;
    int lengthsLength;
    Json* lengths;
    Json* child;
    float* out;

    /* 0x28ca6c: +0x2c = getInt(map, "closed", 0) */
    *(int*)((char*)attachment + 0x2c) =
        Json_getInt(attachmentMap, "closed", 0);

    /* 0x28ca84: +0x30 = getInt(map, "constantSpeed", 1) */
    *(int*)((char*)attachment + 0x30) =
        Json_getInt(attachmentMap, "constantSpeed", 1);

    /* 0x28ca9c: vertexCount = getInt(map, "vertexCount", 0) */
    vertexCount = Json_getInt(attachmentMap, "vertexCount", 0);

    /* 0x28cab4: _readVertices(json, map, attachment, vertexCount << 1) */
    _readVertices(json_raw, attachmentMap, attachment, vertexCount << 1);

    /* 0x28cab8–0x28cad0: lengthsLength = vertexCount / 3
     * (smull with 0x55555556 magic + sign correction — signed division,
     * NO +1 adjustment) */
    lengthsLength = vertexCount / 3;

    /* 0x28cad4–0x28cad8: malloc(lengthsLength*4, TAG, 985) → +0x28 */
    *(void**)((char*)attachment + 0x28) =
        _malloc(lengthsLength * 4, TAG, 985);
    *(int*)((char*)attachment + 0x24) = lengthsLength;

    /* 0x28caec: lengths = getItem(map, "lengths") */
    lengths = Json_getItem(attachmentMap, "lengths");
    if (lengths == 0) return;
    if (lengths->child == 0) return;  /* 0x28caf4 cmp r3,#0 */

    /* 0x28cb00–0x28cb18: for each child: float_value [+0x18] × scale
     * → sequential store into lengths array (vstmia r2!, {s15}) */
    out = (float*)*(void**)((char*)attachment + 0x28);
    for (child = lengths->child; child != 0; child = child->next) {
        *out++ = *(float*)((char*)child + 0x18) * json_scale;
    }
}
