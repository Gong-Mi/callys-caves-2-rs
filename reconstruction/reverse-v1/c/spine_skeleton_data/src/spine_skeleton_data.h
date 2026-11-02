/* ARM32 spine data cleanup contract, recovered from libyoyo, not upstream headers.
 * Image SHA256: 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * Private helper functions below are translation scaffolding, not native entries. */
#ifndef YY_SPINE_SKELETON_DATA_H
#define YY_SPINE_SKELETON_DATA_H
#include <stdint.h>
#include <stddef.h>
_Static_assert(sizeof(void *)==4, "native function-pointer slots require an ARM32 build");
typedef struct spSkeletonData spSkeletonData;
typedef struct spBoneData spBoneData;
typedef struct spSlotData spSlotData;
typedef struct spSkin spSkin;
typedef struct spEventData spEventData;
typedef struct spAnimation spAnimation;
typedef struct spIkConstraintData spIkConstraintData;
typedef struct spTransformConstraintData spTransformConstraintData;
typedef struct spPathConstraintData spPathConstraintData;
typedef struct spTimeline spTimeline;
typedef struct spAttachment spAttachment;
struct spSkeletonData { uint32_t words[21]; };
_Static_assert(sizeof(spSkeletonData)==84, "0x28ade4: calloc(1,84,tag,37)");
spSkeletonData *spSkeletonData_create(void);
void spSkeletonData_dispose(spSkeletonData *);
void spBoneData_dispose(spBoneData *);
void spSlotData_dispose(spSlotData *);
void spSkin_dispose(spSkin *);
void spEventData_dispose(spEventData *);
void spAnimation_dispose(spAnimation *);
void spIkConstraintData_dispose(spIkConstraintData *);
void spTransformConstraintData_dispose(spTransformConstraintData *);
void spPathConstraintData_dispose(spPathConstraintData *);
void spTimeline_dispose(spTimeline *);
void spAttachment_dispose(spAttachment *);
void _Entry_dispose(void *);
void *_calloc(uint32_t, uint32_t, const char *, uint32_t);
void _free(void *);
#endif
