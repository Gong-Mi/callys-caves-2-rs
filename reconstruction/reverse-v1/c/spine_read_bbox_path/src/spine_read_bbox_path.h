#ifndef SPINE_READ_BBOX_PATH_H
#define SPINE_READ_BBOX_PATH_H
#include "spine_read_vertices.h"
/* Recovered caller BLOCK APIs, not additional original function entries. */
void readSkeletonData_boundingBoxFields(Json *map, spBoundingBoxAttachment *a,
                                       const void *json, spAttachmentLoader *loader);
void readSkeletonData_pathAttachmentFields(Json *map, spPathAttachment *a,
                                          const void *json);
#endif
