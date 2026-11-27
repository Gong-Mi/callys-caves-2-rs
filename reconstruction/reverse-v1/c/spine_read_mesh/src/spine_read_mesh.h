#ifndef YY_SPINE_READ_MESH_H
#define YY_SPINE_READ_MESH_H
#include "../../spine_json_layout.h"
#include "spine_read_vertices.h"
/* A caller BLOCK, not an additional original function. Return indicates which
 * original successor was reached: ready for spSkin_addAttachment, or queued
 * for the still-unassembled linkedmesh postpass. Both skip the common skin
 * insertion/outer-loop code at 0x28cc68. */
int readSkeletonData_meshFields(Json *map, spMeshAttachment *mesh,
    const char *path, spSkeletonJson *json, uint32_t slotIndex);
#endif
