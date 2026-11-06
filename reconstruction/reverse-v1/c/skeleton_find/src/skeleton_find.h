/*
 * skeleton_find.h — name-based lookup in spSkeletonData.
 */
#ifndef YY_SKELETON_FIND_H
#define YY_SKELETON_FIND_H

#include <stdint.h>
#include <stddef.h>

/* Forward declarations (layouts in spine_skeleton_data). */
struct spSkeletonData;
struct spBoneData;
struct spSlotData;
struct spSkin;

typedef struct spSkeletonData spSkeletonData;
typedef struct spBoneData spBoneData;
typedef struct spSlotData spSlotData;
typedef struct spSkin spSkin;

/* Partial spSkeletonData layout (fields used by these find functions). */
struct spSkeletonData {
    /* ... +0x00..0x0c unknown from this batch ... */
    uint32_t     unk_00;         /* +0x00 */
    uint32_t     unk_04;         /* +0x04 */
    uint32_t     unk_08;         /* +0x08 */
    uint32_t     unk_0c;         /* +0x0c */
    int32_t      bone_count;     /* +0x10  from findBone */
    spBoneData** bones;          /* +0x14  from findBone */
    int32_t      slot_count;     /* +0x18  from findSlotIndex */
    spSlotData** slots;          /* +0x1c  from findSlotIndex */
    int32_t      skin_count;     /* +0x20  from findSkin */
    spSkin**     skins;          /* +0x24  from findSkin */
    /* ... rest unknown from this batch ... */
};

/* Partial layouts — only the name offset is pinned by these functions. */
struct spBoneData { char* name; /* +0x04, from findBone ldr r0,[r5,#4] */ };
struct spSlotData { char* name; /* +0x04, from findSlotIndex ldr r0,[r3,#4] */ };
struct spSkin     { char* name; /* +0x00, from findSkin ldr r0,[r5] */ };

/* libc (bare-metal). */
extern int strcmp(const char* a, const char* b);

/* Public API (matches dynsym). */
spBoneData* spSkeletonData_findBone(spSkeletonData* self, const char* name);
int         spSkeletonData_findSlotIndex(spSkeletonData* self, const char* name);
spSkin*     spSkeletonData_findSkin(spSkeletonData* self, const char* name);

#endif /* YY_SKELETON_FIND_H */
