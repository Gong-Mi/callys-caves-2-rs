#ifndef SPINE_READ_SKINS_H
#define SPINE_READ_SKINS_H

#include "json_interface.h"

Json* readSkeletonData_skinsArray(Json* tree, void* data_raw);
void* readSkeletonData_oneSkin(Json* skinMap, void* data_raw, int* is_default);

#endif
