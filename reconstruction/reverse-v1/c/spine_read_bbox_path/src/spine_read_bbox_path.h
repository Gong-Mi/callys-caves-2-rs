#ifndef SPINE_READ_BBOX_PATH_H
#define SPINE_READ_BBOX_PATH_H

#include "json_interface.h"

void readSkeletonData_boundingBoxFields(Json* attachmentMap, void* attachment,
                                         void* json_raw, void* loader);
void readSkeletonData_pathAttachmentFields(Json* attachmentMap, void* attachment,
                                            void* json_raw, float json_scale);

#endif
