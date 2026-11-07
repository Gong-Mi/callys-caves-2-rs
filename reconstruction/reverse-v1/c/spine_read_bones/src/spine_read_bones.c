/*
 * readSkeletonData bone loop body (0x28ba40–0x28bbcc, ~90 insn)
 *
 * Recovery source: libyoyo_armv7.so @ 0x28b84c (bank_0240.c)
 * Cross-ref: reference/spine-c-3.8-SkeletonJson.c.txt (bones section)
 *
 * spBoneData layout (52B = 0x34, from spBoneData_create calloc(1,52)):
 *   +0x00 index (int)           — passed INTO create (GameMaker mod;
 *                                  stock spine-c sets it in the caller)
 *   +0x04 name (char*)          — MALLOC_STR'd in create
 *   +0x08 parent (spBoneData*)  — from create's 3rd arg
 *   +0x0c length (float)        — × json->scale
 *   +0x10 x (float)             — × json->scale
 *   +0x14 y (float)             — × json->scale
 *   +0x18 rotation (float)      — NOT scaled
 *   +0x1c scaleX (float)        — default 1.0f, NOT scaled
 *   +0x20 scaleY (float)        — default 1.0f, NOT scaled
 *   +0x24 shearX (float)        — default 0
 *   +0x28 shearY (float)        — default 0
 *   +0x2c inheritRotation (int) — default 1
 *   +0x30 inheritScale (int)    — default 1
 *
 * Loop structure (for over linked list):
 *   for (boneMap = bones->child; boneMap; boneMap = boneMap->next) {
 *     parentName = Json_getString(boneMap, "parent", 0);
 *     parent = parentName ? findBone(data, parentName) : 0;
 *     if (parentName && !parent) → error "Bone not found"
 *     boneData = spBoneData_create(data->bonesCount, name, parent);
 *     ... fields ...
 *     data->bones[data->bonesCount] = boneData;   // str r5,[r1,r6]
 *     data->bonesCount++;                          // str r2,[r9,#0x10]
 *   }
 *
 * Error path: 0x28ba4c beq 0x28bf28 (parent not found)
 */

#include "spine_read_bones.h"

extern void* _malloc(int size, const char* tag, int line);
extern unsigned int _strlen(const char* s);

extern Json* Json_getItem(Json* json, const char* key);
extern const char* Json_getString(Json* json, const char* key, const char* fallback);
extern float Json_getFloat(Json* json, const char* key, float fallback);
extern int Json_getInt(Json* json, const char* key, int fallback);

extern spBoneData* spBoneData_create(int index, const char* name,
                                     const spBoneData* parent);
extern spBoneData* spSkeletonData_findBone(void* data, const char* name);

/* spSkeletonData offsets (binary-observed) */
#define SD_BONESCOUNT_OFF 0x10
#define SD_BONES_OFF      0x14

/* spBoneData field offsets (52B struct) */
#define BD_LENGTH_OFF        0x0c
#define BD_X_OFF             0x10
#define BD_Y_OFF             0x14
#define BD_ROTATION_OFF      0x18
#define BD_SCALEX_OFF        0x1c
#define BD_SCALEY_OFF        0x20
#define BD_SHEARX_OFF        0x24
#define BD_SHEARY_OFF        0x28
#define BD_INHERITROT_OFF    0x2c
#define BD_INHERITSCALE_OFF  0x30

static void bd_store_f32(void* bd, unsigned int off, float v) {
    *(float*)((char*)bd + off) = v;
}
static void bd_store_i32(void* bd, unsigned int off, int v) {
    *(int*)((char*)bd + off) = v;
}

/*
 * Process one bone from the JSON bone map.
 * Returns the created spBoneData, or 0 on parent-not-found error
 * (caller must check and jump to the error path 0x28bf28).
 *
 * json_scale is spSkeletonJson->scale (float at +0x00, default 1.0f).
 */
spBoneData* readSkeletonData_oneBone(Json* boneMap, void* data_raw,
                                      float json_scale, int* error_parent) {
    const char* parent_name;
    spBoneData* parent;
    spBoneData* bone;
    const char* name;
    int index;
    void** bones_array;

    *error_parent = 0;

    /* 0x28bba4: parentName = getString(boneMap, "parent", 0) */
    parent_name = Json_getString(boneMap, "parent", 0);
    if (parent_name != 0) {
        /* 0x28ba44: parent = findBone(data, parentName) */
        parent = spSkeletonData_findBone(data_raw, parent_name);
        if (parent == 0) {
            /* 0x28ba4c beq 0x28bf28 — error "Bone not found" */
            *error_parent = 1;
            return 0;
        }
    } else {
        parent = 0;  /* 0x28bbc4: mov r5, r10 (=0) */
    }

    /* 0x28ba5c: index = data->bonesCount (running counter) */
    index = *(int*)((char*)data_raw + SD_BONESCOUNT_OFF);

    /* 0x28ba60: name = getString(boneMap, "name", 0) */
    name = Json_getString(boneMap, "name", 0);

    /* 0x28ba70: bone = spBoneData_create(index, name, parent)
     * create does calloc(1,52) + MALLOC_STR(name) + parent store */
    bone = spBoneData_create(index, name, parent);

    /* 0x28ba84: length × scale → +0x0c */
    bd_store_f32(bone, BD_LENGTH_OFF,
                 Json_getFloat(boneMap, "length", 0) * json_scale);

    /* 0x28baa4: x × scale → +0x10 */
    bd_store_f32(bone, BD_X_OFF,
                 Json_getFloat(boneMap, "x", 0) * json_scale);

    /* 0x28bac4: y × scale → +0x14 */
    bd_store_f32(bone, BD_Y_OFF,
                 Json_getFloat(boneMap, "y", 0) * json_scale);

    /* 0x28bae8: rotation (no scale) → +0x18 */
    bd_store_f32(bone, BD_ROTATION_OFF,
                 Json_getFloat(boneMap, "rotation", 0));

    /* 0x28bb00: scaleX, default 1.0f (0x3f800000) → +0x1c */
    bd_store_f32(bone, BD_SCALEX_OFF,
                 Json_getFloat(boneMap, "scaleX", 1.0f));

    /* 0x28bb18: scaleY, default 1.0f → +0x20 */
    bd_store_f32(bone, BD_SCALEY_OFF,
                 Json_getFloat(boneMap, "scaleY", 1.0f));

    /* 0x28bb30: shearX, default 0 → +0x24 */
    bd_store_f32(bone, BD_SHEARX_OFF,
                 Json_getFloat(boneMap, "shearX", 0));

    /* 0x28bb48: shearY, default 0 → +0x28 */
    bd_store_f32(bone, BD_SHEARY_OFF,
                 Json_getFloat(boneMap, "shearY", 0));

    /* 0x28bb60: inheritRotation, default 1 → +0x2c */
    bd_store_i32(bone, BD_INHERITROT_OFF,
                 Json_getInt(boneMap, "inheritRotation", 1));

    /* 0x28bb78: inheritScale, default 1 → +0x30 */
    bd_store_i32(bone, BD_INHERITSCALE_OFF,
                 Json_getInt(boneMap, "inheritScale", 1));

    /* 0x28bb8c: bones[bonesCount] = bone
     * (str r5, [r1, r6] where r6 = bonesCount*4) */
    bones_array = *(void***)((char*)data_raw + SD_BONES_OFF);
    bones_array[index] = bone;

    /* 0x28bb98: bonesCount++ */
    *(int*)((char*)data_raw + SD_BONESCOUNT_OFF) = index + 1;

    return bone;
}

/*
 * Full bones loop. Returns 0 on parent-not-found (error path 0x28bf28),
 * 1 on success.
 */
int readSkeletonData_boneLoop(Json* first_bone, void* data_raw, float json_scale) {
    Json* boneMap;
    int err;

    for (boneMap = first_bone; boneMap != 0; boneMap = boneMap->next) {
        /* 0x28bb94: ldr r4, [r4] — advance via ->next */
        (void)readSkeletonData_oneBone(boneMap, data_raw,
                                        json_scale, &err);
        if (err) {
            return 0;  /* 0x28bf28 error path */
        }
    }
    return 1;
}
