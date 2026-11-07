/*
 * spine_mesh.h — ARM32 reconstruction of the mesh attachment UV / linked-mesh
 * entry points of libyoyo_armv7.so
 *   sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 *   spMeshAttachment_updateUVs     0x287538  280 B  ARM
 *   spMeshAttachment_setParentMesh 0x287654  128 B  ARM
 *
 * The record layout is the canonical one recovered in
 *   ../../spine_atlas_attachment/src/spine_atlas_attachment.h
 * (spVertexAttachment 0x24, spMeshAttachment 0x94); this header adds no
 * fields and does not rename any.  Field roles proved by these two bodies:
 *   +0x20  worldVerticesLength / region-UV float count (read as one word)
 *   +0x40  u        +0x44  v        +0x48  u2       +0x4c  v2
 *   +0x50  rotate (non-zero selects the rotated mapping)
 *   +0x58  source region-UV float array (read only)
 *   +0x5c  derived UV float array (freed, re-allocated, written)
 * setParentMesh copies thirteen slots and nothing else; see SEMANTICS.md.
 *
 * ABI: both functions are void, core-register AAPCS32 (softfp).  They take
 * no floating-point arguments and return no value; the original leaves r0
 * undefined on return (leftover loop cursor in updateUVs).
 */

#ifndef YY_SPINE_MESH_H
#define YY_SPINE_MESH_H

#include "spine_atlas_attachment.h"
#include "spine_alloc.h"

#if !defined(__ARM_FP) || defined(__ARM_PCS_VFP)
#error "spine_mesh requires real ARM32 VFP instructions with the core-register ABI"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* 0x287538  void (spMeshAttachment *self) */
void spMeshAttachment_updateUVs (spMeshAttachment *self);

/* 0x287654  void (spMeshAttachment *self, spMeshAttachment *parentMesh) */
void spMeshAttachment_setParentMesh (spMeshAttachment *self,
                                     spMeshAttachment *parentMesh);

#ifdef __cplusplus
}
#endif

/* Byte pins for the slots these two bodies actually touch.  The canonical
 * header already pins the record sizes and the majority of the offsets. */
_Static_assert (sizeof (float) == 4, "binary32 float required");
_Static_assert (offsetof (spMeshAttachment, super.worldVerticesLength) == 0x20,
                "mesh+0x20 count");
_Static_assert (offsetof (spMeshAttachment, super.opaque_10) == 0x10, "mesh+0x10");
_Static_assert (offsetof (spMeshAttachment, super.owned_14) == 0x14, "mesh+0x14");
_Static_assert (offsetof (spMeshAttachment, super.opaque_18) == 0x18, "mesh+0x18");
_Static_assert (offsetof (spMeshAttachment, super.owned_1c) == 0x1c, "mesh+0x1c");
_Static_assert (offsetof (spMeshAttachment, u) == 0x40, "mesh+0x40 u");
_Static_assert (offsetof (spMeshAttachment, v) == 0x44, "mesh+0x44 v");
_Static_assert (offsetof (spMeshAttachment, u2) == 0x48, "mesh+0x48 u2");
_Static_assert (offsetof (spMeshAttachment, v2) == 0x4c, "mesh+0x4c v2");
_Static_assert (offsetof (spMeshAttachment, rotate) == 0x50, "mesh+0x50 rotate");
_Static_assert (offsetof (spMeshAttachment, owned_58) == 0x58, "mesh+0x58");
_Static_assert (offsetof (spMeshAttachment, owned_5c) == 0x5c, "mesh+0x5c");
_Static_assert (offsetof (spMeshAttachment, opaque_60) == 0x60, "mesh+0x60");
_Static_assert (offsetof (spMeshAttachment, owned_64) == 0x64, "mesh+0x64");
_Static_assert (offsetof (spMeshAttachment, opaque_78) == 0x78, "mesh+0x78");
_Static_assert (offsetof (spMeshAttachment, parentMesh) == 0x7c, "mesh+0x7c");
_Static_assert (offsetof (spMeshAttachment, opaque_84) == 0x84, "mesh+0x84");
_Static_assert (offsetof (spMeshAttachment, owned_88) == 0x88, "mesh+0x88");
_Static_assert (offsetof (spMeshAttachment, opaque_8c) == 0x8c, "mesh+0x8c");
_Static_assert (offsetof (spMeshAttachment, opaque_90) == 0x90, "mesh+0x90");

#endif /* YY_SPINE_MESH_H */
