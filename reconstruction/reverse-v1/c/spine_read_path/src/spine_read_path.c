/*
 * readSkeletonData path constraint segment (0x28c274–0x28c5ec, ~100 insn)
 *
 * Recovery source: libyoyo_armv7.so @ 0x28b84c (bank_0240.c)
 *
 * Malloc anchors:
 *   0x28c2a8 line 782 (0x30e): data+0x50 = path array = MALLOC(count*4)
 *   0x28c330 line 791 (0x317): constraint+0x08 = bones = MALLOC(n*4)
 *
 * spSkeletonData: +0x4c pathCount, +0x50 path array
 *
 * spPathConstraintData layout (from stores):
 *   +0x00 name (create), +0x04 bonesCount, +0x08 bones,
 *   +0x0c target (spSlotData* — findSlot, NOT findBone!),
 *   +0x10 positionMode (fixed=0, percent=1, def "percent"→1),
 *   +0x14 spacingMode (length=0, fixed=1, percent=2, def "length"→0),
 *   +0x18 rotateMode (tangent=0, chain=1, chainScale=2, def "tangent"→0),
 *   +0x1c..: position/spacing floats + 4 mix (see remaining section)
 *
 * KEY DIFFERENCE from IK/transform: target is a SLOT (findSlot at 0x28b070),
 * not a bone. Modes parsed via strcmp chains (streq pattern).
 */

#include "spine_read_path.h"

extern void* _malloc(int size, const char* tag, int line);

extern Json* Json_getItem(Json* json, const char* key);
extern const char* Json_getString(Json* json, const char* key, const char* fallback);
extern float Json_getFloat(Json* json, const char* key, float fallback);

extern void* spPathConstraintData_create(const char* name);
extern void* spSkeletonData_findBone(void* data, const char* name);
extern void* spSkeletonData_findSlot(void* data, const char* name);

static int strcmp_eq(const char* a, const char* b) {
    /* strcmp==0 helper (bare-metal, no libc) */
    while (*a && *a == *b) { a++; b++; }
    return *a == *b;
}

static const char* TAG = "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";

#define SD_PATHCOUNT_OFF 0x4c
#define SD_PATH_OFF      0x50

#define PC_BONESCOUNT_OFF 0x04
#define PC_BONES_OFF      0x08
#define PC_TARGET_OFF     0x0c
#define PC_POSMODE_OFF    0x10
#define PC_SPACINGMODE_OFF 0x14
#define PC_ROTATEMODE_OFF 0x18

/* Enum values (spine-c): */
#define SP_POSITION_FIXED   0
#define SP_POSITION_PERCENT 1
#define SP_SPACING_LENGTH   0
#define SP_SPACING_FIXED    1
#define SP_SPACING_PERCENT  2
#define SP_ROTATE_TANGENT   0
#define SP_ROTATE_CHAIN     1
#define SP_ROTATE_CHAINSCALE 2

int readSkeletonData_pathSection(Json* tree, void* data_raw, float json_scale,
                                  int* error_which, const char** error_name) {
    Json* path;
    Json* map;
    unsigned int count;
    unsigned int i;

    *error_which = 0;
    *error_name = 0;

    /* 0x28c274: path = getItem(tree, "path") */
    path = Json_getItem(tree, "path");
    if (path == 0) return 1;

    /* 0x28c294: count → data+0x4c */
    count = path->unk_0c;
    *(int*)((char*)data_raw + SD_PATHCOUNT_OFF) = (int)count;

    /* 0x28c2a8: malloc(count*4, TAG, 782) → data+0x50 */
    *(void***)((char*)data_raw + SD_PATH_OFF) =
        _malloc((int)(count * 4), TAG, 782);

    for (map = path->child, i = 0; map != 0; map = map->next, i++) {
        void* constraint;
        Json* bones_item;
        Json* bone_map;
        unsigned int bn;
        unsigned int j;
        const char* target_name;
        void* target;
        const char* mode_str;

        /* 0x28c300: name = getString(map, "name", 0) → create */
        constraint = spPathConstraintData_create(
            Json_getString(map, "name", 0));

        /* 0x28c314: bonesItem = getItem(map, "bones") */
        bones_item = Json_getItem(map, "bones");
        if (bones_item == 0) bones_item = map;

        bn = bones_item->unk_0c;
        *(int*)((char*)constraint + PC_BONESCOUNT_OFF) = (int)bn;

        /* 0x28c330: malloc(bn*4, TAG, 791) → +0x08 */
        *(void***)((char*)constraint + PC_BONES_OFF) =
            _malloc((int)(bn * 4), TAG, 791);

        /* bones sub-loop (0x28c350–0x28c380) */
        for (bone_map = bones_item->child, j = 0;
             bone_map != 0; bone_map = bone_map->next, j++) {
            const char* bone_name =
                (const char*)*(void**)((char*)bone_map + 0x10);
            void* bone = spSkeletonData_findBone(data_raw, bone_name);
            (*(void***)((char*)constraint + PC_BONES_OFF))[j] = bone;
            if (bone == 0) {
                *error_which = 1;
                *error_name = bone_name;
                return 0;
            }
        }

        /* 0x28c3e4: targetName = getString(map, "target", 0)
         * 0x28c3f0: target = findSlot(data, targetName) → +0x0c  (SLOT!) */
        target_name = Json_getString(map, "target", 0);
        target = spSkeletonData_findSlot(data_raw, target_name);
        *(void**)((char*)constraint + PC_TARGET_OFF) = target;
        if (target == 0) {
            *error_which = 2;
            *error_name = target_name;
            return 0;
        }

        /* 0x28c414: positionMode = getString(map, "positionMode", "percent")
         * strcmp chain: "fixed"→0, "percent"→1 (0x28c42c/0x28c448) */
        mode_str = Json_getString(map, "positionMode", "percent");
        if (strcmp_eq(mode_str, "fixed")) {
            *(int*)((char*)constraint + PC_POSMODE_OFF) = SP_POSITION_FIXED;
        } else if (strcmp_eq(mode_str, "percent")) {
            *(int*)((char*)constraint + PC_POSMODE_OFF) = SP_POSITION_PERCENT;
        }

        /* 0x28c464: spacingMode = getString(map, "spacingMode", "length")
         * strcmp chain: "length"→0, "fixed"→1, "percent"→2 */
        mode_str = Json_getString(map, "spacingMode", "length");
        if (strcmp_eq(mode_str, "length")) {
            *(int*)((char*)constraint + PC_SPACINGMODE_OFF) = SP_SPACING_LENGTH;
        } else if (strcmp_eq(mode_str, "fixed")) {
            *(int*)((char*)constraint + PC_SPACINGMODE_OFF) = SP_SPACING_FIXED;
        } else if (strcmp_eq(mode_str, "percent")) {
            *(int*)((char*)constraint + PC_SPACINGMODE_OFF) = SP_SPACING_PERCENT;
        }

        /* 0x28c4d4: rotateMode = getString(map, "rotateMode", "tangent")
         * strcmp chain: "tangent"→0, "chain"→1, "chainScale"→2 */
        mode_str = Json_getString(map, "rotateMode", "tangent");
        if (strcmp_eq(mode_str, "tangent")) {
            *(int*)((char*)constraint + PC_ROTATEMODE_OFF) = SP_ROTATE_TANGENT;
        } else if (strcmp_eq(mode_str, "chain")) {
            *(int*)((char*)constraint + PC_ROTATEMODE_OFF) = SP_ROTATE_CHAIN;
        } else if (strcmp_eq(mode_str, "chainScale")) {
            *(int*)((char*)constraint + PC_ROTATEMODE_OFF) = SP_ROTATE_CHAINSCALE;
        }

        /* Float tail (0x28c52c–0x28c5d4):
         * rotation → +0x1c (offsetRotation, unscaled)
         * position → +0x20 (×scale if positionMode==FIXED(0))
         * spacing → +0x24 (×scale if spacingMode<=FIXED(1), i.e. LENGTH|FIXED)
         * rotateMix → +0x28 (default 1.0f)
         * translateMix → +0x2c (default 1.0f)
         * Path constraints have only 2 mixes (3.8 layout); the 4-mix
         * set is transform-only. */
        *(float*)((char*)constraint + 0x1c) =
            Json_getFloat(map, "rotation", 0);

        {
            float pos = Json_getFloat(map, "position", 0);
            *(float*)((char*)constraint + 0x20) = pos;
            if (*(int*)((char*)constraint + PC_POSMODE_OFF) == SP_POSITION_FIXED) {
                *(float*)((char*)constraint + 0x20) = pos * json_scale;
            }
        }

        {
            float sp = Json_getFloat(map, "spacing", 0);
            *(float*)((char*)constraint + 0x24) = sp;
            {
                int sm = *(int*)((char*)constraint + PC_SPACINGMODE_OFF);
                if (sm == SP_SPACING_LENGTH || sm == SP_SPACING_FIXED) {
                    *(float*)((char*)constraint + 0x24) = sp * json_scale;
                }
            }
        }

        *(float*)((char*)constraint + 0x28) =
            Json_getFloat(map, "rotateMix", 1.0f);
        *(float*)((char*)constraint + 0x2c) =
            Json_getFloat(map, "translateMix", 1.0f);

        /* 0x28c5d8: data->path[i] = constraint */
        (*(void***)((char*)data_raw + SD_PATH_OFF))[i] = constraint;
    }

    return 1;
}
