#ifndef SPINE_READ_SLOTS_H
#define SPINE_READ_SLOTS_H

#include "json_interface.h"

/*
 * readSkeletonData slots segment (0x28bbcc-0x28bdd8) + toColor (0x28b680).
 * toColor was previously mislabeled "findPathConstraint+0x390" —
 * it is the static color parser, called 16× (4 comps × slots/skins/attachments).
 */
#include "../../spine_color/src/spine_color.h"
Json* readSkeletonData_slotsArray(Json* tree, void* data_raw, int* out_count);
void* readSkeletonData_oneSlot(Json* slotMap, void* data_raw,
                               void* bone, int index);

#endif
