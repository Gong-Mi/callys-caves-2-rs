#ifndef SPINE_READ_REGION_H
#define SPINE_READ_REGION_H

#include "json_interface.h"

void readSkeletonData_regionFields(Json* attachmentMap, void* attachment,
                                    const char* path, float json_scale);

#endif
