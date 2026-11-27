/*
 * readSkeletonData IK constraint segment (0x28bdd8–0x28bff8, ~90 insn)
 *
 * Recovery source: libyoyo_armv7.so @ 0x28b84c (bank_0240.c)
 *
 * Malloc anchors:
 *   0x28be10 line 697 (0x2b9): data+0x40 = ik array = MALLOC(count*4)
 *   0x28bea4 line 705 (0x2c1): constraint+0x08 = bones = MALLOC(n*4)
 *
 * spSkeletonData: +0x3c ikCount, +0x40 ik array
 *
 * spIkConstraintData layout (from this segment's stores):
 *   +0x00 name (set by create), +0x04 bonesCount, +0x08 bones,
 *   +0x0c target (spBoneData*), +0x10 bendDirection (±1),
 *   +0x14 mix (float, default 1.0f)
 *
 * VERSION MARKER: key "bendPositive" (spine 3.6/3.7) not 3.8's
 * "bendDirection". Semantics: getInt("bendPositive", 1) →
 *   0 → bendDirection = -1 (mvneq r3, #0 = ~0)
 *   non-zero → bendDirection = +1 (movne r3, #1)
 *
 * Error paths:
 *   IK bone not found → 0x28bf00 (dispose + setError)
 *   target bone not found → 0x28cf3c
 *
 * rodata: ik / name / bones / target / bendPositive / mix
 */

#include "spine_read_ik.h"

extern void* _malloc(int size, const char* tag, int line);

extern Json* Json_getItem(Json* json, const char* key);
extern const char* Json_getString(Json* json, const char* key, const char* fallback);
extern float Json_getFloat(Json* json, const char* key, float fallback);
extern int Json_getInt(Json* json, const char* key, int fallback);

extern void* spIkConstraintData_create(const char* name);
extern void* spSkeletonData_findBone(void* data, const char* name);

static const char* TAG = "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";

#define SD_IKCOUNT_OFF 0x3c
#define SD_IK_OFF      0x40

#define IKC_BONESCOUNT_OFF 0x04
#define IKC_BONES_OFF      0x08
#define IKC_TARGET_OFF     0x0c
#define IKC_BENDDIR_OFF    0x10
#define IKC_MIX_OFF        0x14

/*
 * IK array allocation + loop. Returns 0 on error (bone/target not found),
 * 1 on success. error_which/error_name carry the failure detail.
 */
int readSkeletonData_ikSection(Json* tree, void* data_raw,
                               int* error_which, const char** error_name) {
    Json* ik;
    Json* map;
    unsigned int count;
    unsigned int i;

    *error_which = 0;
    *error_name = 0;

    /* 0x28bdd8: ik = getItem(tree, "ik") */
    ik = Json_getItem(tree, "ik");
    if (ik == 0) return 1;  /* 0x28bdf0 beq → skip section */

    /* 0x28bdf4: count → data+0x3c */
    count = ik->unk_0c;
    *(int*)((char*)data_raw + SD_IKCOUNT_OFF) = (int)count;

    /* 0x28be10: malloc(count*4, TAG, 697) → data+0x40 */
    *(void***)((char*)data_raw + SD_IK_OFF) =
        _malloc((int)(count * 4), TAG, 697);

    /* 0x28be14: iterate children */
    for (map = ik->child, i = 0; map != 0; map = map->next, i++) {
        void* constraint;
        Json* bones_item;
        Json* bone_map;
        unsigned int bn;
        unsigned int j;
        const char* target_name;
        void* target;
        int bend_positive;

        /* 0x28be74: name = getString(map, "name", 0) */
        /* 0x28be78: constraint = create(name) */
        constraint = spIkConstraintData_create(
            Json_getString(map, "name", 0));

        /* 0x28be88: bonesItem = getItem(map, "bones") */
        bones_item = Json_getItem(map, "bones");
        if (bones_item == 0) bones_item = map;  /* defensive; binary
                                                   does not check null
                                                   (getItem always used) */

        /* 0x28be98: bonesCount = bonesItem->size → +0x04 */
        bn = bones_item->unk_0c;
        *(int*)((char*)constraint + IKC_BONESCOUNT_OFF) = (int)bn;

        /* 0x28bea4: malloc(bn*4, TAG, 705) → +0x08 */
        *(void***)((char*)constraint + IKC_BONES_OFF) =
            _malloc((int)(bn * 4), TAG, 705);

        /* bones sub-loop: find + store each bone (0x28bec4–0x28bef0) */
        for (bone_map = bones_item->child, j = 0;
             bone_map != 0; bone_map = bone_map->next, j++) {
            const char* bone_name =
                (const char*)*(void**)((char*)bone_map + 0x10);
            void* bone = spSkeletonData_findBone(data_raw, bone_name);
            /* 0x28bedc: constraint->bones[j] = bone */
            (*(void***)((char*)constraint + IKC_BONES_OFF))[j] = bone;
            /* 0x28bee4–0x28bef0: if (!bone) → error "IK bone not found" */
            if (bone == 0) {
                *error_which = 1;  /* ik bone */
                *error_name = bone_name;
                return 0;
            }
        }

        /* 0x28bf84: targetName = getString(map, "target", 0) */
        target_name = Json_getString(map, "target", 0);
        /* 0x28bf9c: target = findBone(data, targetName) → +0x0c */
        target = spSkeletonData_findBone(data_raw, target_name);
        *(void**)((char*)constraint + IKC_TARGET_OFF) = target;
        /* 0x28bfa8: if (!target) → error 0x28cf3c */
        if (target == 0) {
            *error_which = 2;  /* target */
            *error_name = target_name;
            return 0;
        }

        /* 0x28bfb8: bendPositive = getInt(map, "bendPositive", 1)
         * 0x28bfcc–0x28bfd4: 0 → bendDirection = -1 (mvneq); else +1 */
        bend_positive = Json_getInt(map, "bendPositive", 1);
        *(int*)((char*)constraint + IKC_BENDDIR_OFF) =
            (bend_positive == 0) ? -1 : 1;

        /* 0x28bfd8: mix = getFloat(map, "mix", 1.0f) → +0x14 */
        *(float*)((char*)constraint + IKC_MIX_OFF) =
            Json_getFloat(map, "mix", 1.0f);

        /* 0x28bfe4: data->ik[i] = constraint */
        (*(void***)((char*)data_raw + SD_IK_OFF))[i] = constraint;
    }

    return 1;
}
