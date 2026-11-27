/* Original ARM32 static helper at 0x28b3fc; see functions.json. */
#ifndef YY_SPINE_READ_VERTICES_H
#define YY_SPINE_READ_VERTICES_H
#include "spine_atlas_attachment.h"
#include "json_interface.h"
#if !defined(__ARM_FP) || defined(__ARM_PCS_VFP)
#error "_readVertices requires real ARM32 VFP softfp, not hard-float or software FP"
#endif
/* json is an opaque complete parser handle. Only its first float is read;
 * no competing partial spSkeletonJson structure is introduced here. */
void _readVertices(const void *json, Json *attachmentMap,
                   spVertexAttachment *attachment, uint32_t verticesCount);
#endif
