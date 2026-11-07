#ifndef SPINE_READ_META_H
#define SPINE_READ_META_H

#include "json_interface.h"

/*
 * readSkeletonData metadata + bones array segments.
 * data_raw is spSkeletonData* (opaque 84B words[21]); field offsets are
 * binary-observed: +0x00 version, +0x04 hash, +0x08 width, +0x0c height,
 * +0x14 bones. See src/spine_read_meta.c for the full trace.
 */
void readSkeletonData_metadata(Json* tree, void* data_raw);
Json* readSkeletonData_bonesArray(Json* tree, void* data_raw, int* out_count);

#endif
