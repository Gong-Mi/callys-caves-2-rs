/*
 * family_includes.h — one include point for the nine family modules.
 *
 * WHY THIS FILE EXISTS
 * --------------------
 * c/spine_read_tl_slots/src/spine_read_tl_slots.h and
 * c/spine_read_tl_bones/src/spine_read_tl_bones.h both typedef a 16-byte
 * spAnimation convenience record under the SAME name `spAnimationShape`.  The
 * two records are byte-identical (name +0x00, duration +0x04, timelineCount
 * +0x08, timelines +0x0c) and neither family's entry points mention the name,
 * but C11 rejects the second typedef of a distinct anonymous struct, so a
 * translation unit that needs both families cannot include both headers
 * verbatim.  Renaming each typedef at inclusion time keeps every existing
 * header untouched and every layout assertion live.
 *
 * Nothing else in the family headers collides (checked by building the union
 * with -Werror); helper in c/spine_animations_loop/tools/check_animations_loop.py
 * links all nine modules together.
 */
#ifndef YY_SPINE_ANIMATIONS_LOOP_FAMILY_INCLUDES_H
#define YY_SPINE_ANIMATIONS_LOOP_FAMILY_INCLUDES_H

#define spAnimationShape spAnimationShape_tl_slots
#include "spine_read_tl_slots.h"
#undef spAnimationShape

#define spAnimationShape spAnimationShape_tl_bones
#include "spine_read_tl_bones.h"
#undef spAnimationShape

#include "spine_read_tl_ik.h"
#include "spine_read_tl_transform.h"
#include "spine_read_tl_path.h"
#include "spine_read_tl_deform.h"
#include "spine_read_tl_draworder.h"
#include "spine_read_tl_event.h"
#include "spine_read_tl_path_mix.h"

#endif /* YY_SPINE_ANIMATIONS_LOOP_FAMILY_INCLUDES_H */
