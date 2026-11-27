/* Shared complete data type; no competing partial spSkeletonData/Bone/Slot.
 * Bone/slot objects stay opaque; their name word is read at proven +4. */
#ifndef YY_SKELETON_FIND_H
#define YY_SKELETON_FIND_H
#include "../../spine_skeleton_data/src/spine_skeleton_data.h"
spBoneData *spSkeletonData_findBone(spSkeletonData *,const char *);
int spSkeletonData_findSlotIndex(spSkeletonData *,const char *);
spSkin *spSkeletonData_findSkin(spSkeletonData *,const char *);
#endif
