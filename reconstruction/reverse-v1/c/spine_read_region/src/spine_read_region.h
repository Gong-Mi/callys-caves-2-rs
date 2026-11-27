#ifndef SPINE_READ_REGION_H
#define SPINE_READ_REGION_H
#include "json_interface.h"
#include "spine_region_geometry.h"
#include "../../spine_json_layout.h"
/* Caller BLOCK0x28cdac..0x28cf24, not another original function.
 * Current parser scale/loader are read at the original callback boundaries. */
void readSkeletonData_regionFields(Json *,spRegionAttachment *,const char *path,const spSkeletonJson *);
#endif
