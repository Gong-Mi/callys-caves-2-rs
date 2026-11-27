#ifndef SPINE_READ_IK_H
#define SPINE_READ_IK_H

#include "json_interface.h"

int readSkeletonData_ikSection(Json* tree, void* data_raw,
                               int* error_which, const char** error_name);

#endif
