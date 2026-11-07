#ifndef SPINE_READ_ATTACH_DISPATCH_H
#define SPINE_READ_ATTACH_DISPATCH_H

#include "json_interface.h"

typedef enum {
    ATTACH_REGION = 0,
    ATTACH_MESH,
    ATTACH_LINKEDMESH,
    ATTACH_BOUNDINGBOX,
    ATTACH_PATH,
    ATTACH_UNKNOWN = -1
} attach_type_e;

attach_type_e readSkeletonData_classifyAttachment(
    Json* attachmentMap, void* data_raw,
    const char** out_name, const char** out_path, const char** out_type);

#endif
