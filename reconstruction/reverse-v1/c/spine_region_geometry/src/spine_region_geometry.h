/* Original ARM32 region geometry. Full canonical region record remains in
 * spine_atlas_attachment; helper C functions are not extra original entries. */
#ifndef YY_SPINE_REGION_GEOMETRY_H
#define YY_SPINE_REGION_GEOMETRY_H
#include "spine_atlas_attachment.h"
#if !defined(__ARM_FP) || defined(__ARM_PCS_VFP)
#error "region geometry requires actual ARM32 VFP softfp"
#endif
/* Original has no stack canary; preserve that per-function property. */
__attribute__((noinline,no_stack_protector))
void spRegionAttachment_updateOffset(spRegionAttachment *);
_Static_assert(offsetof(spRegionAttachment,offset)==0x5c,"region offsets output");
_Static_assert(offsetof(spRegionAttachment,regionOriginalWidth)==0x54,"original width");
_Static_assert(offsetof(spRegionAttachment,regionOriginalHeight)==0x58,"original height");
#endif
