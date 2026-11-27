#ifndef SPINE_READ_TRANSFORM_H
#define SPINE_READ_TRANSFORM_H

#include "json_interface.h"

int readSkeletonData_transformSection(Json* tree, void* data_raw,
                                       float json_scale,
                                       int* error_which, const char** error_name);

#endif
