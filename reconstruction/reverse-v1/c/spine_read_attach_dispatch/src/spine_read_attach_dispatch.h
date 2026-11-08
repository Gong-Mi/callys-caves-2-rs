#ifndef SPINE_READ_ATTACH_DISPATCH_H
#define SPINE_READ_ATTACH_DISPATCH_H

#include "json_interface.h"

/*
 * Binary order (spAttachmentType): the createAttachment glue loads
 * r2 = region 0 (0x28cf2c mov r2,r0) / boundingbox 1 (0x28cfa0) /
 * mesh 2 (0x28cf24) / linkedmesh 3 (0x28cf34) / path 4 (0x28c7a0),
 * driven by the jump table at 0x28c7c8. The earlier REGION/MESH/
 * LINKEDMESH/BOUNDINGBOX order was a module-side invention; corrected
 * 2026-11-08 against the segment-chain census (word-verified).
 */
typedef enum {
    ATTACH_REGION = 0,
    ATTACH_BOUNDINGBOX,
    ATTACH_MESH,
    ATTACH_LINKEDMESH,
    ATTACH_PATH,
    ATTACH_UNKNOWN = -1
} attach_type_e;

attach_type_e readSkeletonData_classifyAttachment(
    Json* attachmentMap, void* data_raw,
    const char** out_name, const char** out_path, const char** out_type);

#endif
