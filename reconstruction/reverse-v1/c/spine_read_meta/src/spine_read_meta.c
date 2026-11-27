/*
 * readSkeletonData metadata + bones segments
 *   metadata: 0x28b8f4–0x28b9cc (~30 insn)
 *   bones array: 0x28b9cc–0x28ba40 (~10 insn)
 *
 * Recovery source: libyoyo_armv7.so @ 0x28b84c (bank_0240.c)
 * Cross-ref: reference/spine-c-3.8-SkeletonJson.c.txt
 *
 * Malloc anchors (tag = spine-c/src/spine/SkeletonJson.c):
 *   0x28b92c line 607: MALLOC_STR for "hash"  → data+0x04
 *   0x28b974:           MALLOC_STR for "spine" → data+0x00
 *   0x28b9f4 line 615:  data->bones = MALLOC(size*4) → data+0x14
 *
 * Store instructions pin the spSkeletonData layout (this binary):
 *   0x28b93c str r0,[r9,#0x4]  hash buffer
 *   0x28b984 str r0,[r9]       version buffer ("spine" key)
 *   0x28b9bc str r0,[r9,#0x8]  width float
 *   0x28b9c8 str r0,[r9,#0xc]  height float
 *   0x28ba00 str r0,[r9,#0x14] bones array
 * NOTE: hash/version are at SWAPPED offsets vs stock spine-c 3.8
 * (stock: hash +0x00, version +0x04). Binary is authoritative.
 *
 * GameMaker MALLOC_STR calls Json_getString TWICE (once for strlen,
 * once for strcpy) — 4 getString calls for 2 fields in the trace.
 *
 * Version guard: binary has NO "3.8.75" string — GameMaker adaptation
 * removed the version check present in stock spine-c 3.8.
 *
 * rodata: hash=0x357b68 spine=0x357b70 width=0x357b78 height=0x357b80
 *         bones=0x357b88
 */

#include "spine_read_meta.h"

extern void* _malloc(int size, const char* tag, int line);
extern unsigned int _strlen(const char* s);
extern void _strcpy(char* dst, const char* src);

extern Json* Json_getItem(Json* json, const char* key);
extern const char* Json_getString(Json* json, const char* key, const char* fallback);
extern float Json_getFloat(Json* json, const char* key, float fallback);

static const char* TAG = "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";

/* spSkeletonData field offsets (binary-observed, 84B struct) */
#define SD_VERSION_OFF 0x00
#define SD_HASH_OFF    0x04
#define SD_WIDTH_OFF   0x08
#define SD_HEIGHT_OFF  0x0c
#define SD_BONES_OFF   0x14

/* Raw word access — spSkeletonData is opaque (words[21]) */
static void* sd_ptr(void* data, unsigned int off) {
    return *(void**)((char*)data + off);
}
static void sd_store_ptr(void* data, unsigned int off, void* val) {
    *(void**)((char*)data + off) = val;
}
static void sd_store_f32(void* data, unsigned int off, float val) {
    *(float*)((char*)data + off) = val;
}

void readSkeletonData_metadata(Json* tree, void* data_raw) {
    Json* skeleton;
    const char* hash;
    const char* version;

    skeleton = Json_getItem(tree, "skeleton");
    if (skeleton == 0) return;  /* 28b8f0 beq skip */

    /* MALLOC_STR(data+0x04, Json_getString(skeleton, "hash", 0))
     * expanded: strlen → malloc(607) → getString again → strcpy */
    hash = Json_getString(skeleton, "hash", 0);
    {
        unsigned int len = _strlen(hash) + 1;
        sd_store_ptr(data_raw, SD_HASH_OFF,
                     _malloc((int)len, TAG, 607));
        hash = Json_getString(skeleton, "hash", 0);  /* re-fetch, 0x28b944 */
        _strcpy((char*)sd_ptr(data_raw, SD_HASH_OFF), hash);  /* 0x28b950 */
    }

    /* MALLOC_STR(data+0x00, Json_getString(skeleton, "spine", 0)) */
    version = Json_getString(skeleton, "spine", 0);
    {
        unsigned int len = _strlen(version) + 1;
        sd_store_ptr(data_raw, SD_VERSION_OFF,
                     _malloc((int)len, TAG, 608));
        version = Json_getString(skeleton, "spine", 0);  /* re-fetch */
        _strcpy((char*)sd_ptr(data_raw, SD_VERSION_OFF), version);
    }

    /* No 3.8.75 guard in this binary (verified: string absent) */

    sd_store_f32(data_raw, SD_WIDTH_OFF,
                 Json_getFloat(skeleton, "width", 0));   /* 0x28b9bc */
    sd_store_f32(data_raw, SD_HEIGHT_OFF,
                 Json_getFloat(skeleton, "height", 0));  /* 0x28b9c8 */
}

Json* readSkeletonData_bonesArray(Json* tree, void* data_raw, int* out_count) {
    Json* bones;
    unsigned int size;

    bones = Json_getItem(tree, "bones");       /* 0x28b9d8 */

    size = bones->unk_0c;                      /* 0x28b9ec: Json::size */

    sd_store_ptr(data_raw, SD_BONES_OFF,       /* 0x28ba00 */
                 _malloc((int)(size * 4), TAG, 615));  /* 0x28b9f4 */

    *out_count = (int)size;

    return bones->child;                       /* 0x28b9f8: iterate children */
}
