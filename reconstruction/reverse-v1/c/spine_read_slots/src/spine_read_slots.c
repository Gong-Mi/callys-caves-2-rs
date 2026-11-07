/*
 * readSkeletonData slots segment (0x28bbcc–0x28bdd8, ~100 insn)
 * toColor helper (0x28b680, ~30 insn, called 16×)
 *
 * Recovery source: libyoyo_armv7.so @ 0x28b84c (bank_0240.c)
 * Cross-ref: reference/spine-c-3.8-SkeletonJson.c.txt (slots + toColor)
 *
 * Malloc anchors:
 *   0x28bbfc line 651: data+0x1c = slots = MALLOC(size*4)
 *
 * spSkeletonData field offsets (binary-observed):
 *   +0x18 slotsCount, +0x1c slots array
 *   (followed by +0x3c ikCount, +0x40 ik array in next segment)
 *
 * toColor (0x28b680) — previously mislabeled "findPathConstraint+0x390".
 * Takes (const char* hexcolor, int index) → float [0,1] or -1 on error.
 * Called 4× per color (r/g/b/a) × slots/skins/attachments = 16× total.
 *
 * Slot loop structure (for over slots->child linked list):
 *   CONDITION (0x28bd7c): boneName = getString(slotMap, "bone");
 *     bone = findBone(data, boneName);
 *     if (!bone) → dispose + setError("Slot bone not found") → return 0
 *   BODY (0x28bc5c):
 *     name = getString(slotMap, "name");
 *     slotData = spSlotData_create(index, name, bone);
 *     color = getString(slotMap, "color");
 *     if (color) { +16/+20/+24/+28 = toColor(color, 0..3); }
 *     attachment = getItem(slotMap, "attachment");
 *     if (attachment) setAttachmentName(slotData, attachment->string_value);
 *     blend = getItem(slotMap, "blend");
 *     if (blend) { strcmp "multiply"/"screen"/"additive" → blendMode; }
 *     data->slots[index] = slotData; index++;
 *
 * rodata: slots=0x357b90 color(→str@) bone attachment name blend additive
 */

#include "spine_read_slots.h"

extern void* _malloc(int size, const char* tag, int line);
extern unsigned int _strlen(const char* s);
extern int _strcmp(const char* a, const char* b);

extern Json* Json_getItem(Json* json, const char* key);
extern const char* Json_getString(Json* json, const char* key, const char* fallback);

extern void* spSlotData_create(int index, const char* name, void* bone);
extern void spSlotData_setAttachmentName(void* slotData, const char* name);
extern void* spSkeletonData_findBone(void* data, const char* name);
#include "../../spine_color/src/spine_color.h"

static const char* TAG = "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";

#define SD_SLOTSCOUNT_OFF 0x18
#define SD_SLOTS_OFF      0x1c

/* toColor is now the shared byte-anchored ARM32 helper in c/spine_color/. */

/*
 * Slots array allocation (0x28bbcc–0x28bc0c).
 * Returns the first slot Json child for iteration.
 */
Json* readSkeletonData_slotsArray(Json* tree, void* data_raw, int* out_count) {
    Json* slots;
    unsigned int size;

    slots = Json_getItem(tree, "slots");
    if (slots == 0) return 0;  /* 0x28bbe0 beq skip */

    size = slots->unk_0c;      /* Json::size at +0x0c */
    *(int*)((char*)data_raw + SD_SLOTSCOUNT_OFF) = (int)size;  /* 0x28bbf0 */

    *(void***)((char*)data_raw + SD_SLOTS_OFF) =                /* 0x28bc08 */
        _malloc((int)(size * 4), TAG, 651);                     /* 0x28bbfc */

    *out_count = (int)size;
    return slots->child;
}

/*
 * One slot from the JSON slot map (0x28bc5c body).
 * bone must be pre-resolved by the caller (from the loop condition).
 * Returns slotData or 0 on create failure.
 */
void* readSkeletonData_oneSlot(Json* slotMap, void* data_raw,
                               void* bone, int index) {
    const char* name;
    void* slotData;
    const char* color;
    Json* attachment;
    Json* blend;

    /* 0x28bc68: name = getString(slotMap, "name", 0) */
    name = Json_getString(slotMap, "name", 0);

    /* 0x28bc78: slotData = spSlotData_create(index, name, bone) */
    slotData = spSlotData_create(index, name, bone);
    if (slotData == 0) return 0;

    /* 0x28bc8c: color = getString(slotMap, "color", 0) */
    color = Json_getString(slotMap, "color", 0);
    if (color != 0) {
        /* 0x28bc9c–0x28bcd0: 4 components via toColor */
        *(float*)((char*)slotData + 16) = toColor(color, 0);  /* r */
        *(float*)((char*)slotData + 20) = toColor(color, 1);  /* g */
        *(float*)((char*)slotData + 24) = toColor(color, 2);  /* b */
        *(float*)((char*)slotData + 28) = toColor(color, 3);  /* a */
    }

    /* 0x28bcdc: attachment = getItem(slotMap, "attachment") */
    attachment = Json_getItem(slotMap, "attachment");
    if (attachment != 0) {
        /* 0x28bce8: name from [attachment+0x10] (string_value) */
        const char* att_name = (const char*)*(void**)((char*)attachment + 0x10);
        /* 0x28bcf0: spSlotData_setAttachmentName(slotData, att_name) */
        spSlotData_setAttachmentName(slotData, att_name);
    }

    /* 0x28bcf8: blend = getItem(slotMap, "blend") */
    blend = Json_getItem(slotMap, "blend");
    if (blend != 0) {
        /* 0x28bd08: blend string from [blend+0x10] */
        const char* blend_str = (const char*)*(void**)((char*)blend + 0x10);
        int blend_mode = 0;  /* default normal */
        /* strcmp against "multiply"(1) / "screen"(2) / "additive"(3) */
        if (_strcmp(blend_str, "additive") == 0) blend_mode = 3;
        else if (_strcmp(blend_str, "multiply") == 0) blend_mode = 1;
        else if (_strcmp(blend_str, "screen") == 0) blend_mode = 2;
        /* blend_mode store is at slotData+0x20 (inferred from card layout) */
        *(int*)((char*)slotData + 0x20) = blend_mode;
    }

    /* 0x28bd68: data->slots[index] = slotData */
    {
        void** slots_arr = *(void***)((char*)data_raw + SD_SLOTS_OFF);
        slots_arr[index] = slotData;
    }

    return slotData;
}
