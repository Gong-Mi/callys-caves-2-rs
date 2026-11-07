/* readSkeletonData mesh/linkedmesh caller blocks (NOT standalone functions).
 * tier: bytecode_anchored; source image SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Blocks: 0x28cb20..0x28cc68, 0x28cfa8..0x28d008, 0x28d008..0x28d144,
 * shared configure successor 0x28cd9c..0x28cda8. No original execution.
 * Deliberately preserves absent NULL/length guards and borrowed link strings.
 * Full loader, skin insertion and linked-parent resolution are NOT assembled. */
#include "spine_read_mesh.h"
#include "spine_mesh.h"
#include "spine_color.h"
extern size_t strlen(const char *);
extern char *strcpy(char *, const char *);
extern void *memcpy(void *, const void *, size_t);
static const char tag[] =
    "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";
static float scale_load(const spSkeletonJson *j) {
    float f;
    __asm__ volatile("vldr %0, [%1]" : "=t"(f) : "r"(j) : "memory");
    return f;
}
static uint32_t scaled_bits(float x, const spSkeletonJson *j) {
    float scale = scale_load(j), product; uint32_t bits;
    __asm__ volatile("vmul.f32 %0, %1, %2" : "=t"(product)
        : "t"(x), "t"(scale) : "memory");
    __builtin_memcpy(&bits, &product, 4);
    return bits;
}
static int32_t s32(uint32_t x) { int32_t s; __builtin_memcpy(&s,&x,4); return s; }

/* 0x28cc2c..0x28cc64 plus growth block 0x28cfa8..0x28d008.
 * Translation scaffolding only: no independent original entry. */
static void enqueue(spSkeletonJson *j, const char *skin, const char *parent,
                    uint32_t slot, spMeshAttachment *mesh) {
    uint32_t count = j->unk_10;
    spLinkedMesh *base;
    if (count == j->unk_14) {
        uint32_t doubled = count << 1, bytes;
        if (s32(doubled) > 7) { j->unk_14 = doubled; bytes = count << 5; }
        else { j->unk_14 = 8; bytes = 128; }
        /* Capacity is published BEFORE allocation; count/base are reloaded
         * after allocation; old base again after memcpy; count after free. */
        spLinkedMesh *replacement = _malloc(bytes, tag, 136u); /* 0x28cfd4 */
        uint32_t copy_count = j->unk_10; /* 0x28cfd8 */
        spLinkedMesh *copy_base = (spLinkedMesh *)(uintptr_t)j->unk_18; /* 0x28cfdc */
        memcpy(replacement, copy_base, copy_count << 4); /* 0x28cfe8 */
        _free((void *)(uintptr_t)j->unk_18); /* 0x28cfec/cff0 */
        count = j->unk_10; /* 0x28cff4 */
        j->unk_18 = (uint32_t)(uintptr_t)replacement; /* 0x28cffc */
        base = replacement;
    } else base = (spLinkedMesh *)(uintptr_t)j->unk_18; /* 0x28cc44 */
    volatile spLinkedMesh *entry = (spLinkedMesh *)(uintptr_t)
        ((uint32_t)(uintptr_t)base + (count << 4)); /* ARM32 address wrap */
    j->unk_10 = count + 1u; /* 0x28cc50 BEFORE entry stores */
    entry->skin = skin; /* 0x28cc54 */
    entry->mesh = mesh; /* 0x28cc5c */
    entry->slotIndex = slot; /* 0x28cc60 */
    entry->parent = parent; /* 0x28cc64: last */
}

int readSkeletonData_meshFields(Json *map, spMeshAttachment *a,
    const char *path, spSkeletonJson *j, uint32_t slotIndex) {
    char *path_copy = _malloc((uint32_t)strlen(path) + 1u, tag, 917u);
    a->owned_54 = path_copy; /* 0x28cb40; no region-style path NULL guard */
    strcpy(path_copy, path);
    const char *color = Json_getString(map, "color", 0); /* 0x28cb58 */
    if (color) {
        a->r = toColor(color,0); a->g = toColor(color,1);
        a->b = toColor(color,2); a->a = toColor(color,3); /* 0x28cb68..0x28cb9c */
    }
    float x = Json_getFloat(map,"width",32.0f);
    a->opaque_8c = scaled_bits(x,j); /* 0x28cbb4..0x28cbd0 */
    x = Json_getFloat(map,"height",32.0f);
    a->opaque_90 = scaled_bits(x,j); /* 0x28cbd8..0x28cbf0 */
    Json *parent = Json_getItem(map,"parent"); /* 0x28cbf4 */
    if (parent) { /* presence of Json, NOT non-NULL/nonempty parent string */
        a->opaque_80 = (uint32_t)Json_getInt(map,"deform",1); /* 0x28cc20 */
        const char *skin = Json_getString(map,"skin",0);
        const char *parent_name = parent->string_value; /* after getString */
        enqueue(j,skin,parent_name,slotIndex,a);
        return 1; /* 0x28cc68; no UV generation or configure yet */
    }
    Json *array = Json_getItem(map,"triangles"); /* 0x28d010, required */
    uint32_t count = array->unk_0c;
    a->opaque_60 = count; /* 0x28d028 before allocator callback */
    uint16_t *triangles = _malloc(count << 1,tag,935u); /* 0x28d030 */
    Json *child = array->child; /* AFTER allocation, 0x28d034 */
    a->owned_64 = triangles;
    while (child) {
        uint16_t value = (uint16_t)(uint32_t)child->int_value;
        Json *next = child->next; /* 0x28d04c BEFORE store */
        *triangles++ = value; child = next; /* chain, not declared count */
    }
    array = Json_getItem(map,"uvs"); /* 0x28d068, required */
    uint32_t uv_count = array->unk_0c; /* cached across allocator + copy */
    float *uvs = _malloc(uv_count << 2,tag,941u); /* 0x28d084 */
    child = array->child; /* 0x28d088 AFTER allocation */
    a->owned_58 = uvs;
    while (child) {
        float value; __builtin_memcpy(&value,&child->float_value,4);
        Json *next = child->next; /* 0x28d0a0 BEFORE bitcopy */
        __builtin_memcpy(uvs++, &value, 4); child = next;
    }
    _readVertices(j,map,&a->super,uv_count); /* 0x28d0c0 */
    spMeshAttachment_updateUVs(a); /* 0x28d0c8, actual recovered callee */
    a->opaque_78 = (uint32_t)Json_getInt(map,"hull",0); /* 0x28d0e8: NOT <<1 */
    array = Json_getItem(map,"edges"); /* 0x28d0f0 optional */
    if (array) {
        count = array->unk_0c;
        a->opaque_84 = count; /* 0x28d108 BEFORE allocation */
        int32_t *edges = _malloc(count << 2,tag,954u); /* 0x28d114 */
        child = array->child; /* 0x28d118 AFTER allocation */
        a->owned_88 = edges;
        while (child) {
            int32_t value = child->int_value;
            Json *next = child->next;
            *edges++ = value; child = next;
        }
    }
    spAttachmentLoader *loader = (spAttachmentLoader *)(uintptr_t)j->loader;
    spAttachmentLoader_configureAttachment(loader,&a->super.super); /* 0x28cda4 */
    return 0; /* caller scaffolding, original successor 0x28cc68 */
}
