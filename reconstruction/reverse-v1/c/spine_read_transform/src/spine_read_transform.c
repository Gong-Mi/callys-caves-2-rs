/*
 * readSkeletonData transform constraint segment (0x28bff8–0x28c274, ~90 insn)
 *
 * Recovery source: libyoyo_armv7.so @ 0x28b84c (bank_0240.c)
 *
 * Malloc anchors:
 *   0x28c02c line 735 (0x2df): data+0x48 = transform array = MALLOC(count*4)
 *   0x28c0b4 line 743 (0x2e7): constraint+0x08 = bones = MALLOC(n*4)
 *
 * spSkeletonData: +0x44 transformCount, +0x48 transform array
 *
 * spTransformConstraintData layout (from this segment's stores):
 *   +0x00 name (create), +0x04 bonesCount, +0x08 bones, +0x0c target,
 *   +0x10 rotateMix (def 1.0f), +0x14 translateMix (def 1.0f),
 *   +0x18 scaleMix (def 1.0f), +0x1c shearMix (def 1.0f),
 *   +0x20 offset.rotation, +0x24 offset.x (×scale),
 *   +0x28 offset.y (×scale), +0x2c offset.scaleX,
 *   +0x30 offset.scaleY, +0x34 offset.shearY
 *
 * Key order in binary: rotation, x(×scale), y(×scale), scaleX, scaleY,
 * shearY, then rotateMix/translateMix/scaleMix/shearMix (all default
 * 1.0f = 1065353216). Matches spine-c 3.8 transform constraints.
 *
 * Error paths: bones not found (0x28c104), target not found (0x28d144).
 */

#include "spine_read_transform.h"

extern void* _malloc(int size, const char* tag, int line);

extern Json* Json_getItem(Json* json, const char* key);
extern const char* Json_getString(Json* json, const char* key, const char* fallback);
extern float Json_getFloat(Json* json, const char* key, float fallback);

extern void* spTransformConstraintData_create(const char* name);
extern void* spSkeletonData_findBone(void* data, const char* name);

static const char* TAG = "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";

#define SD_TRANSFORMCOUNT_OFF 0x44
#define SD_TRANSFORM_OFF      0x48

#define TC_BONESCOUNT_OFF 0x04
#define TC_BONES_OFF      0x08
#define TC_TARGET_OFF     0x0c
#define TC_ROTATEMIX_OFF  0x10
#define TC_TRANSLATEMIX_OFF 0x14
#define TC_SCALEMIX_OFF   0x18
#define TC_SHEARMIX_OFF   0x1c
#define TC_ROTATION_OFF   0x20
#define TC_X_OFF          0x24
#define TC_Y_OFF          0x28
#define TC_SCALEX_OFF     0x2c
#define TC_SCALEY_OFF     0x30
#define TC_SHEARY_OFF     0x34

int readSkeletonData_transformSection(Json* tree, void* data_raw,
                                       float json_scale,
                                       int* error_which, const char** error_name) {
    Json* transform;
    Json* map;
    unsigned int count;
    unsigned int i;

    *error_which = 0;
    *error_name = 0;

    /* 0x28bff8: transform = getItem(tree, "transform") */
    transform = Json_getItem(tree, "transform");
    if (transform == 0) return 1;  /* 0x28c00c beq skip */

    /* 0x28c018: count → data+0x44 */
    count = transform->unk_0c;
    *(int*)((char*)data_raw + SD_TRANSFORMCOUNT_OFF) = (int)count;

    /* 0x28c02c: malloc(count*4, TAG, 735) → data+0x48 */
    *(void***)((char*)data_raw + SD_TRANSFORM_OFF) =
        _malloc((int)(count * 4), TAG, 735);

    for (map = transform->child, i = 0; map != 0; map = map->next, i++) {
        void* constraint;
        Json* bones_item;
        Json* bone_map;
        unsigned int bn;
        unsigned int j;
        const char* target_name;
        void* target;

        /* 0x28c084: name = getString(map, "name", 0) → create */
        constraint = spTransformConstraintData_create(
            Json_getString(map, "name", 0));

        /* 0x28c098: bonesItem = getItem(map, "bones") */
        bones_item = Json_getItem(map, "bones");
        if (bones_item == 0) bones_item = map;

        /* 0x28c0ac: bonesCount → +0x04 */
        bn = bones_item->unk_0c;
        *(int*)((char*)constraint + TC_BONESCOUNT_OFF) = (int)bn;

        /* 0x28c0b4: malloc(bn*4, TAG, 743) → +0x08 */
        *(void***)((char*)constraint + TC_BONES_OFF) =
            _malloc((int)(bn * 4), TAG, 743);

        /* bones sub-loop with findBone (0x28c0d4–0x28c100) */
        for (bone_map = bones_item->child, j = 0;
             bone_map != 0; bone_map = bone_map->next, j++) {
            const char* bone_name =
                (const char*)*(void**)((char*)bone_map + 0x10);
            void* bone = spSkeletonData_findBone(data_raw, bone_name);
            (*(void***)((char*)constraint + TC_BONES_OFF))[j] = bone;
            if (bone == 0) {
                *error_which = 1;
                *error_name = bone_name;
                return 0;
            }
        }

        /* 0x28c130: targetName = getString(map, "target", 0) */
        target_name = Json_getString(map, "target", 0);
        /* 0x28c148: target = findBone(data, targetName) → +0x0c */
        target = spSkeletonData_findBone(data_raw, target_name);
        *(void**)((char*)constraint + TC_TARGET_OFF) = target;
        if (target == 0) {
            *error_which = 2;
            *error_name = target_name;
            return 0;
        }

        /* offset fields (0x28c158–0x28c204) */
        *(float*)((char*)constraint + TC_ROTATION_OFF) =
            Json_getFloat(map, "rotation", 0);                        /* +0x20 */
        *(float*)((char*)constraint + TC_X_OFF) =
            Json_getFloat(map, "x", 0) * json_scale;                  /* +0x24 */
        *(float*)((char*)constraint + TC_Y_OFF) =
            Json_getFloat(map, "y", 0) * json_scale;                  /* +0x28 */
        *(float*)((char*)constraint + TC_SCALEX_OFF) =
            Json_getFloat(map, "scaleX", 0);                          /* +0x2c */
        *(float*)((char*)constraint + TC_SCALEY_OFF) =
            Json_getFloat(map, "scaleY", 0);                          /* +0x30 */
        *(float*)((char*)constraint + TC_SHEARY_OFF) =
            Json_getFloat(map, "shearY", 0);                          /* +0x34 */

        /* mix fields (0x28c1f8–0x28c25c), all default 1.0f */
        *(float*)((char*)constraint + TC_ROTATEMIX_OFF) =
            Json_getFloat(map, "rotateMix", 1.0f);                    /* +0x10 */
        *(float*)((char*)constraint + TC_TRANSLATEMIX_OFF) =
            Json_getFloat(map, "translateMix", 1.0f);                 /* +0x14 */
        *(float*)((char*)constraint + TC_SCALEMIX_OFF) =
            Json_getFloat(map, "scaleMix", 1.0f);                     /* +0x18 */
        *(float*)((char*)constraint + TC_SHEARMIX_OFF) =
            Json_getFloat(map, "shearMix", 1.0f);                     /* +0x1c */

        /* 0x28c260: data->transform[i] = constraint */
        (*(void***)((char*)data_raw + SD_TRANSFORM_OFF))[i] = constraint;
    }

    return 1;
}
