/*
 * skeleton_find.c — name-based lookup in spSkeletonData arrays.
 *
 * Original image:
 *   libyoyo_armv7.so SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Evidence tier: bytecode_anchored.  Every branch, load, store and literal
 * below is tied to the original instruction address.  The original was not
 * executed.
 *
 * Symbols:
 *   0x28afbc  spSkeletonData_findBone      92 B  23 insns  → bone* or NULL
 *   0x28b0cc  spSkeletonData_findSlotIndex 88 B  22 insns  → index or -1
 *   0x28b124  spSkeletonData_findSkin      92 B  23 insns  → skin* or NULL
 *
 * spSkeletonData layout (from these accessors):
 *   +0x10  bone_count (int)
 *   +0x14  bones      (spBoneData**)
 *   +0x18  slot_count (int)
 *   +0x1c  slots      (spSlotData**)
 *   +0x20  skin_count (int)
 *   +0x24  skins      (spSkin**)
 *
 * Name field offsets:
 *   spBoneData: name at +0x04 (findBone: ldr r0, [r5, #0x4])
 *   spSlotData: name at +0x04 (findSlotIndex: ldr r0, [r3, #0x4])
 *   spSkin:     name at +0x00 (findSkin: ldr r0, [r5])
 *
 * findSlotIndex returns the array index (counter r4), not the pointer;
 * on not-found it returns -1 (0x28b11c mvn r0,#0).
 * findBone and findSkin return the object pointer or NULL.
 *
 * Named boundary: strcmp@plt.
 */

#include "skeleton_find.h"

spBoneData*
spSkeletonData_findBone(spSkeletonData* self, const char* name)
{
    /* 0x28afc4 ldr r7, [r0, #0x10] — bone count */
    int count = self->bone_count;

    /* 0x28afc8 cmp r7, #0; 0x28afcc ble return_null */
    if (count <= 0)
        return NULL;

    /* 0x28afd0 ldr r6, [r0, #0x14] — bones array; walk from end */
    spBoneData** arr = self->bones;
    spBoneData** p = arr + count; /* sub r6, r6, #4 → last slot */

    for (int i = 0; i < count; i++) {
        /* 0x28afe8 ldr r5, [r6, #0x4]! — pre-indexed: p++ then read */
        spBoneData* bone = *(--p);

        /* 0x28aff4 ldr r0, [r5, #0x4] — bone->name */
        /* 0x28aff8 bl strcmp */
        if (strcmp(bone->name, name) == 0) {
            /* 0x28b004 mov r0, r5 */
            return bone;
        }
    }

    /* 0x28b00c mov r5, #0; 0x28b010 mov r0, r5 */
    return NULL;
}

int
spSkeletonData_findSlotIndex(spSkeletonData* self, const char* name)
{
    /* 0x28b0d4 ldr r6, [r0, #0x18] — slot count */
    int count = self->slot_count;

    /* 0x28b0d8 cmp r6, #0; 0x28b0dc ble return_not_found */
    if (count <= 0)
        return -1;

    /* 0x28b0e0 ldr r5, [r0, #0x1c] — slots array */
    spSlotData** arr = self->slots;
    spSlotData** p = arr + count;

    for (int i = 0; i < count; i++) {
        /* 0x28b0fc ldr r3, [r5, #0x4]! — pre-indexed */
        spSlotData* slot = *(--p);

        /* 0x28b104 ldr r0, [r3, #0x4] — slot->name */
        /* 0x28b108 bl strcmp */
        if (strcmp(slot->name, name) == 0) {
            /* 0x28b114 mov r0, r4 — return index */
            return i;
        }
    }

    /* 0x28b11c mvn r0, #0 — return -1 */
    return -1;
}

spSkin*
spSkeletonData_findSkin(spSkeletonData* self, const char* name)
{
    /* 0x28b12c ldr r7, [r0, #0x20] — skin count */
    int count = self->skin_count;

    /* 0x28b130 cmp r7, #0; 0x28b134 ble return_null */
    if (count <= 0)
        return NULL;

    /* 0x28b138 ldr r6, [r0, #0x24] — skins array */
    spSkin** arr = self->skins;
    spSkin** p = arr + count;

    for (int i = 0; i < count; i++) {
        /* 0x28b150 ldr r5, [r6, #0x4]! — pre-indexed */
        spSkin* skin = *(--p);

        /* 0x28b15c ldr r0, [r5] — skin->name at +0x00 */
        /* 0x28b160 bl strcmp */
        if (strcmp(skin->name, name) == 0) {
            /* 0x28b16c mov r0, r5 */
            return skin;
        }
    }

    /* 0x28b174 mov r5, #0; 0x28b178 mov r0, r5 */
    return NULL;
}
