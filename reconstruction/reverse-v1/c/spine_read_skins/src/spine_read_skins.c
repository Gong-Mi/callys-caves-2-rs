/*
 * readSkeletonData skins segment — skin level (0x28c5ec–0x28c6b0)
 *
 * Recovery source: libyoyo_armv7.so @ 0x28b84c (bank_0240.c)
 *
 * Malloc anchors:
 *   0x28c618 line 839 (0x347): data+0x24 = skins array = MALLOC(count*4)
 *
 * spSkeletonData: +0x20 skinsCount, +0x24 skins, +0x28 defaultSkin
 *
 * Skin level: for each skinMap in skins->child:
 *   skin = spSkin_create(skinMap->name [+0x1c])
 *   data->skinsCount++ (r11+0x20 = count+1)
 *   data->skins[count] = skin
 *   if strcmp(skinMap->name, "default") == 0 → data->defaultSkin = skin
 *   then slot loop (skinMap->child [+0x4]) → attachment loop (next batch)
 *
 * Note the count is a RUNNING counter at data+0x20 (like bonesCount),
 * initialized to 0 by calloc, incremented before the array store:
 *   0x28c680 add r0, r3, #1 → count+1
 *   0x28c684 str r0, [r11, #0x20] → data+0x20 = count+1
 *   0x28c688 str r9, [r2, r3, lsl #2] → skins[count] = skin
 *
 * The "default" skin comparison happens AFTER the skin is stored:
 *   0x28c690 ldr r0, [skinMap, #0x1c] — name
 *   0x28c694 bl strcmp(name, "default" at sp+0x4c)
 *   0x28c6a4 cmp r0, #0
 *   0x28c6a8 streq r9, [r11, #0x28] — if equal → defaultSkin = skin
 */

#include "spine_read_skins.h"

extern void* _malloc(int size, const char* tag, int line);
extern int _strcmp(const char* a, const char* b);

extern Json* Json_getItem(Json* json, const char* key);

extern void* spSkin_create(const char* name);

static const char* TAG = "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";

#define SD_SKINSCOUNT_OFF 0x20
#define SD_SKINS_OFF      0x24
#define SD_DEFAULTSKIN_OFF 0x28

/*
 * Skins array + skin-level loop. Returns the first skinMap for the
 * caller's slot/attachment loops, or 0 if no skins.
 * out_skins receives the malloc'd array pointer.
 */
Json* readSkeletonData_skinsArray(Json* tree, void* data_raw) {
    Json* skins;
    unsigned int count;

    skins = Json_getItem(tree, "skins");
    if (skins == 0) return 0;  /* 0x28c600 beq skip */

    count = skins->unk_0c;
    /* 0x28c618: malloc(count*4, TAG, 839) → data+0x24 */
    *(void***)((char*)data_raw + SD_SKINS_OFF) =
        _malloc((int)(count * 4), TAG, 839);
    /* NOTE: skinsCount is NOT set from Json size here — it's a running
     * counter incremented per skin (unlike bonesCount/slotsCount which
     * are set from the Json size upfront). calloc already zeroed +0x20. */

    return skins->child;
}

/*
 * One skin: create + store + default check.
 * Returns the spSkin, stores *is_default.
 */
void* readSkeletonData_oneSkin(Json* skinMap, void* data_raw,
                               int* is_default) {
    const char* name;
    void* skin;
    int count;

    /* 0x28c668: name = skinMap->name [+0x1c] (skin's key, not getString) */
    name = (const char*)*(void**)((char*)skinMap + 0x1c);

    /* 0x28c66c: skin = spSkin_create(name) */
    skin = spSkin_create(name);

    /* 0x28c680–0x28c688: running count + store */
    count = *(int*)((char*)data_raw + SD_SKINSCOUNT_OFF);
    *(int*)((char*)data_raw + SD_SKINSCOUNT_OFF) = count + 1;
    (*(void***)((char*)data_raw + SD_SKINS_OFF))[count] = skin;

    /* 0x28c694: strcmp(name, "default") */
    *is_default = (_strcmp(name, "default") == 0);
    if (*is_default) {
        /* 0x28c6a8: data->defaultSkin = skin */
        *(void**)((char*)data_raw + SD_DEFAULTSKIN_OFF) = skin;
    }

    /* 0x28c69c: slot iteration via skinMap->child [+0x4] */
    return skin;
}
