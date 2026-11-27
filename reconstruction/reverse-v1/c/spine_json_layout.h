/* Canonical complete ARM32 parser/linked-mesh records.
 * tier: bytecode_anchored; image 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Creation 0x28b700, disposal 0x28b74c, queue writer 0x28cc2c..0x28cc64.
 * uint32 scale/loader retain the existing stored-word interfaces. */
#ifndef YY_SPINE_JSON_LAYOUT_H
#define YY_SPINE_JSON_LAYOUT_H
#include <stddef.h>
#include <stdint.h>
struct spMeshAttachment;
typedef struct spLinkedMesh {
    const char *parent;                 /* +00 borrowed Json string_value */
    const char *skin;                   /* +04 borrowed Json string_value */
    uint32_t slotIndex;                 /* +08 */
    struct spMeshAttachment *mesh;      /* +0c */
} spLinkedMesh;
typedef struct spSkeletonJson spSkeletonJson;
struct spSkeletonJson {
    uint32_t scale;             /* +00 binary32 bits */
    uint32_t loader;            /* +04 spAttachmentLoader* stored word */
    union { uint32_t error; uint32_t unk_08; }; /* +08 owned string pointer word */
    uint32_t owns_loader;       /* +0c */
    uint32_t unk_10;            /* +10 linkedMeshesCount (reset at 0x28b878) */
    uint32_t unk_14;            /* +14 linkedMeshesCapacity */
    uint32_t unk_18;            /* +18 spLinkedMesh* pointer word, owned array */
};
#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(sizeof(spSkeletonJson)==28, "spSkeletonJson complete 28-byte record");
_Static_assert(offsetof(spSkeletonJson,error)==8, "parser error");
_Static_assert(offsetof(spSkeletonJson,unk_10)==0x10, "linked count");
_Static_assert(offsetof(spSkeletonJson,unk_14)==0x14, "linked capacity");
_Static_assert(offsetof(spSkeletonJson,unk_18)==0x18, "linked array");
_Static_assert(sizeof(spLinkedMesh)==16, "linked mesh queue stride");
_Static_assert(offsetof(spLinkedMesh,mesh)==12, "linked mesh queue attachment");
#endif
#endif
