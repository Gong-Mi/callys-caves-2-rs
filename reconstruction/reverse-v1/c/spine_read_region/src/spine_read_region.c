/*
 * readSkeletonData region attachment parse (0x28cdac–0x28ce9c, ~35 insn)
 *
 * Recovery source: libyoyo_armv7.so @ 0x28b84c (bank_0240.c)
 *
 * Malloc anchors:
 *   0x28cdcc line 891 (0x37b): attachment+0x10 = path = MALLOC_STR
 *
 * spRegionAttachment layout (from stores):
 *   +0x00 name (base spAttachment), +0x04 type (base), +0x08 refCount?,
 *   +0x10 path (char*), +0x14 x (×scale), +0x18 y (×scale),
 *   +0x1c scaleX (def 1.0f), +0x20 scaleY (def 1.0f),
 *   +0x24 rotation (def 0), +0x28 width (def 32.0f ×scale),
 *   +0x2c height (def 32.0f ×scale)
 *
 * DEFAULT DIVERGENCE: width/height default 32.0f (0x42000000) in this
 * binary; stock spine-c 3.8 has no default (0). GameMaker texture-size
 * assumption baked in.
 *
 * Called via the jump table at 0x28c7c8: case 0 (region) → 0x28cdac.
 * r5 = path string, r6 = attachment, r4 = attachmentMap, r8 = json.
 */

#include "spine_read_region.h"

extern void* _malloc(int size, const char* tag, int line);
extern unsigned int _strlen(const char* s);
extern void _strcpy(char* dst, const char* src);

extern float Json_getFloat(Json* json, const char* key, float fallback);
extern const char* Json_getString(Json* json, const char* key, const char* fallback);

static const char* TAG = "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";

void readSkeletonData_regionFields(Json* attachmentMap, void* attachment,
                                    const char* path, float json_scale) {
    /* 0x28cdac: if (path) MALLOC_STR(attachment+0x10, path) */
    if (path != 0) {
        unsigned int len = _strlen(path) + 1;
        *(void**)((char*)attachment + 0x10) =
            _malloc((int)len, TAG, 891);
        _strcpy((char*)*(void**)((char*)attachment + 0x10), path);
    }

    /* 0x28cde8: x × scale → +0x14 */
    *(float*)((char*)attachment + 0x14) =
        Json_getFloat(attachmentMap, "x", 0) * json_scale;

    /* 0x28ce10: y × scale → +0x18 */
    *(float*)((char*)attachment + 0x18) =
        Json_getFloat(attachmentMap, "y", 0) * json_scale;

    /* 0x28ce34: scaleX (def 1.0f) → +0x1c */
    *(float*)((char*)attachment + 0x1c) =
        Json_getFloat(attachmentMap, "scaleX", 1.0f);

    /* 0x28ce4c: scaleY (def 1.0f) → +0x20 */
    *(float*)((char*)attachment + 0x20) =
        Json_getFloat(attachmentMap, "scaleY", 1.0f);

    /* 0x28ce64: rotation (def 0) → +0x24 */
    *(float*)((char*)attachment + 0x24) =
        Json_getFloat(attachmentMap, "rotation", 0);

    /* 0x28ce7c: width (def 32.0f!) × scale → +0x28 */
    *(float*)((char*)attachment + 0x28) =
        Json_getFloat(attachmentMap, "width", 32.0f) * json_scale;

    /* 0x28ce94?: height (def 32.0f!) × scale → +0x2c */
    *(float*)((char*)attachment + 0x2c) =
        Json_getFloat(attachmentMap, "height", 32.0f) * json_scale;

    /* Color (toColor×4) follows — see next batch (sequence matches
     * the slots color pattern with the shared toColor at 0x28b680). */
}
