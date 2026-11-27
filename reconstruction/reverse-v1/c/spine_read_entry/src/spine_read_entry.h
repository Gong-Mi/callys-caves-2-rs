/*
 * spine_read_entry — readSkeletonData 入口段 (0x28b84c–0x28b8f0)
 * See src/spine_read_entry.c for instruction trace.
 */
#ifndef SPINE_READ_ENTRY_H
#define SPINE_READ_ENTRY_H

#include "spine_json_error.h"   /* spSkeletonJson 28B layout */
#include "json_interface.h"     /* Json 32B layout + accessors */
#include "spine_skeleton_data.h" /* spSkeletonData */

Json* readSkeletonData_entry(spSkeletonJson* json, const char* path,
                             spSkeletonData** out_data);

#endif
