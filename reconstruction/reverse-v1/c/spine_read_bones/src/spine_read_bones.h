#ifndef SPINE_READ_BONES_H
#define SPINE_READ_BONES_H

#include "json_interface.h"

typedef struct spBoneData spBoneData;

/*
 * readSkeletonData bone loop (0x28ba40-0x28bbcc).
 * spBoneData: 52B, layout in src/spine_read_bones.c header comment.
 * spBoneData_create takes (index, name, parent) — GameMaker mod,
 * stock spine-c passes index separately.
 */
spBoneData* readSkeletonData_oneBone(Json* boneMap, void* data_raw,
                                      float json_scale, int* error_parent);
int readSkeletonData_boneLoop(Json* first_bone, void* data_raw,
                              float json_scale);

#endif
