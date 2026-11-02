/*
 * spine_atlas_attachment.h — ARM32 layouts and entry points for the
 * AtlasAttachmentLoader creation dispatch and the attachment lifetime chain
 * in libyoyo_armv7.so
 *   sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * The three headers below are the canonical, read-only recovery headers in
 * the main tree; this file includes them rather than copying the allocator
 * ABI or the loader contract:
 *   c/spine_alloc/src/spine_alloc.h
 *   c/spine_attachment/src/spine_attachment.h
 *   c/spine_skeleton_data/src/spine_skeleton_data.h
 *
 * New bodies in this batch (VA / .dynsym size):
 *   _spAtlasAttachmentLoader_createAttachment 0x284a08 428
 *   spAtlas_findRegion                        0x284958 176
 *   spRegionAttachment_create                 0x288f78 100
 *   spRegionAttachment_setUVs                 0x288fdc 100
 *   spBoundingBoxAttachment_create            0x285af8  72
 *   spMeshAttachment_create                   0x2874dc  92
 *   spPathAttachment_create                   0x2876f4  72
 *   _spAttachment_init                        0x284c18 108
 *   _spAttachment_deinit                      0x284c84  48
 *   _spAttachmentLoader_setError              0x284df0 120
 *   _spAttachmentLoader_setUnknownTypeError   0x284e68 112
 *   spAttachmentLoader_createAttachment       0x284d58  96
 *   spAttachmentLoader_configureAttachment    0x284db8  28
 *   spAttachmentLoader_disposeAttachment      0x284dd4  28
 *   _spRegionAttachment_dispose               0x288f58  32
 *   _spBoundingBoxAttachment_dispose          0x285ae0  24
 *   _spMeshAttachment_dispose                 0x28747c  96
 *   _spPathAttachment_dispose                 0x2876d4  32
 *   _spVertexAttachment_deinit                0x28f62c  32
 *
 * Every offset below is read from the frozen decode plus the ELF's own
 * disassembly.  Fields whose role is not proven by this closure are named
 * opaque_NN or owned_NN (owned = freed by a recovered dispose body); no
 * upstream enum or struct name is assumed.
 */

#ifndef SPINE_ATLAS_ATTACHMENT_H
#define SPINE_ATLAS_ATTACHMENT_H

#include <stddef.h>
#include <stdint.h>

#include "spine_alloc.h"
#include "spine_attachment.h"
#include "spine_skeleton_data.h"

#if !defined(__arm__) || defined(__aarch64__) || defined(__LP64__)
#error "spine_atlas_attachment.h: ARM32 ABI only (layout pinned to ARMv7 libyoyo)"
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct spAtlasPage spAtlasPage;
typedef struct spAtlasRegion spAtlasRegion;
typedef struct spVertexAttachment spVertexAttachment;
typedef struct spAttachmentVtable spAttachmentVtable;
typedef struct spRegionAttachment spRegionAttachment;
typedef struct spBoundingBoxAttachment spBoundingBoxAttachment;
typedef struct spMeshAttachment spMeshAttachment;
typedef struct spPathAttachment spPathAttachment;

/* Shared parser/factory declarations: full 12/44/80-byte records. */
#include "../../spine_atlas_layout.h"

/* 4-byte block allocated by _spAttachment_init (calloc(1,4,...:43)). */
struct spAttachmentVtable {
	/* +0x00 */ void (*dispose) (spAttachment *self);
};

/*
 * spAttachment base, 16 bytes.  _spAttachment_init writes name/type/vtable;
 * +0x0c is only *tested* by _spAttachment_deinit before calling the loader's
 * disposeAttachment slot.  No recovered body writes +0x0c, so the calloc zero
 * from the constructors leaves it NULL unless code outside this closure sets
 * it.
 */
struct spAttachment {
	/* +0x00 */ char *name;              /* owned copy, freed by deinit */
	/* +0x04 */ int32_t type;            /* constructor immediate: 0/1/2/4 */
	/* +0x08 */ spAttachmentVtable *vtable; /* owned calloc(1,4) block */
	/* +0x0c */ spAttachmentLoader *loader; /* checked by deinit */
};

/*
 * Base of bounding-box/mesh/path attachments.  _spVertexAttachment_deinit
 * frees +0x14 then +0x1c (after _spAttachment_deinit).  The roles of those
 * two owned pointers are not pinned by this closure.
 */
struct spVertexAttachment {
	/* +0x00 */ spAttachment super;
	/* +0x10 */ uint32_t opaque_10;
	/* +0x14 */ void *owned_14;          /* freed by _spVertexAttachment_deinit */
	/* +0x18 */ uint32_t opaque_18;
	/* +0x1c */ void *owned_1c;          /* freed by _spVertexAttachment_deinit */
};

/* calloc(1,0x24,".../BoundingBoxAttachment.c",44). */
struct spBoundingBoxAttachment {
	/* +0x00 */ spVertexAttachment super;
	/* +0x20 */ uint32_t opaque_20;
};

/* calloc(1,0x34,".../PathAttachment.c",45). */
struct spPathAttachment {
	/* +0x00 */ spVertexAttachment super;
	/* +0x20 */ uint32_t opaque_20;
	/* +0x24 */ uint32_t opaque_24;
	/* +0x28 */ void *owned_28;          /* freed by _spPathAttachment_dispose */
	/* +0x2c */ uint32_t opaque_2c;
	/* +0x30 */ uint32_t opaque_30;
};

/*
 * calloc(1,0x94,".../MeshAttachment.c",50).
 * Slots +0x24..+0x50 are written by the Atlas loader from one spAtlasRegion;
 * +0x68..+0x74 are set to 1.0f by the constructor; +0x54/+0x58/+0x5c/+0x64/
 * +0x88 are freed by the dispose body; +0x7c is the parent-mesh gate written
 * by spMeshAttachment_setParentMesh (0x287654: str r1,[r0,#0x7c]) and tested
 * by the dispose body.
 */
struct spMeshAttachment {
	/* +0x00 */ spVertexAttachment super; /* actual common base subobject */
	/* +0x20 */ uint32_t opaque_20;
	/* +0x24 */ spAtlasRegion *region;
	/* +0x28 */ int32_t regionOffsetX;
	/* +0x2c */ int32_t regionOffsetY;
	/* +0x30 */ int32_t regionWidth;
	/* +0x34 */ int32_t regionHeight;
	/* +0x38 */ int32_t regionOriginalWidth;
	/* +0x3c */ int32_t regionOriginalHeight;
	/* +0x40 */ float u;
	/* +0x44 */ float v;
	/* +0x48 */ float u2;
	/* +0x4c */ float v2;
	/* +0x50 */ int32_t rotate;
	/* +0x54 */ void *owned_54;
	/* +0x58 */ void *owned_58;
	/* +0x5c */ void *owned_5c;
	/* +0x60 */ uint32_t opaque_60;
	/* +0x64 */ void *owned_64;
	/* +0x68 */ float r;
	/* +0x6c */ float g;
	/* +0x70 */ float b;
	/* +0x74 */ float a;
	/* +0x78 */ uint32_t opaque_78;
	/* +0x7c */ struct spMeshAttachment *parentMesh;
	/* +0x80 */ uint32_t opaque_80;
	/* +0x84 */ uint32_t opaque_84;
	/* +0x88 */ void *owned_88;
	/* +0x8c */ uint32_t opaque_8c;
	/* +0x90 */ uint32_t opaque_90;
};

/*
 * calloc(1,0x9c,".../RegionAttachment.c",43).
 * +0x10 is freed by _spRegionAttachment_dispose; the constructor leaves it
 * NULL.  +0x7c..+0x98 is the eight-float UV block written by setUVs.
 */
struct spRegionAttachment {
	/* +0x00 */ spAttachment super;
	/* +0x10 */ void *owned_10;          /* freed by _spRegionAttachment_dispose */
	/* +0x14 */ float x;                 /* not written by this closure */
	/* +0x18 */ float y;                 /* not written by this closure */
	/* +0x1c */ float scaleX;            /* constructor writes 1.0f */
	/* +0x20 */ float scaleY;            /* constructor writes 1.0f */
	/* +0x24 */ float rotation;          /* not written by this closure */
	/* +0x28 */ float width;             /* not written by this closure */
	/* +0x2c */ float height;            /* not written by this closure */
	/* +0x30 */ float r;                 /* constructor writes 1.0f */
	/* +0x34 */ float g;                 /* constructor writes 1.0f */
	/* +0x38 */ float b;                 /* constructor writes 1.0f */
	/* +0x3c */ float a;                 /* constructor writes 1.0f */
	/* +0x40 */ spAtlasRegion *region;
	/* +0x44 */ int32_t regionOffsetX;
	/* +0x48 */ int32_t regionOffsetY;
	/* +0x4c */ int32_t regionWidth;
	/* +0x50 */ int32_t regionHeight;
	/* +0x54 */ int32_t regionOriginalWidth;
	/* +0x58 */ int32_t regionOriginalHeight;
	/* +0x5c */ float offset[8];         /* not written by this closure */
	/* +0x7c */ float uvs[8];            /* written by setUVs */
};

/* ---- recovered entry points ------------------------------------------- */

/* Already declared by spine_attachment.h with this exact contract. */

spAtlasRegion *spAtlas_findRegion (const spAtlas *atlas, const char *name);

spRegionAttachment *spRegionAttachment_create (const char *name);
void spRegionAttachment_setUVs (spRegionAttachment *self, float u, float v,
                                float u2, float v2, int32_t rotate);

spBoundingBoxAttachment *spBoundingBoxAttachment_create (const char *name);
spMeshAttachment *spMeshAttachment_create (const char *name);
spPathAttachment *spPathAttachment_create (const char *name);

void _spAttachment_init (spAttachment *self, const char *name, int32_t type,
                         void (*dispose) (spAttachment *self));
void _spAttachment_deinit (spAttachment *self);
/* spAttachment_dispose is declared by spine_skeleton_data.h and already
 * recovered in c/spine_skeleton_data/src/spine_skeleton_data.c; not repeated
 * here so linking both modules cannot produce a duplicate definition. */

void _spAttachmentLoader_setError (spAttachmentLoader *self,
                                   const char *error1, const char *error2);
void _spAttachmentLoader_setUnknownTypeError (spAttachmentLoader *self,
                                              int32_t type);

spAttachment *spAttachmentLoader_createAttachment (spAttachmentLoader *self,
                                                   spSkin *skin, int32_t type,
                                                   const char *name,
                                                   const char *path);
void spAttachmentLoader_configureAttachment (spAttachmentLoader *self,
                                             spAttachment *attachment);
/* Must decorate the first declaration: Clang can emit this symbol at its
 * earlier use in _spAttachment_deinit, before seeing the later definition. */
__attribute__ ((disable_tail_calls))
void spAttachmentLoader_disposeAttachment (spAttachmentLoader *self,
                                           spAttachment *attachment);

void _spRegionAttachment_dispose (spAttachment *self);
void _spBoundingBoxAttachment_dispose (spAttachment *self);
void _spMeshAttachment_dispose (spAttachment *self);
void _spPathAttachment_dispose (spAttachment *self);
void _spVertexAttachment_deinit (spAttachment *self);

#ifdef __cplusplus
}
#endif

/* ---- byte-pinned layout checks ---------------------------------------- */

_Static_assert (sizeof (void *) == 4, "ARM32 only: pointer width must be 4");
_Static_assert (sizeof (spAttachment) == 16, "spAttachment is 16 B");
_Static_assert (offsetof (spAttachment, name) == 0x00, "attachment+0x00 name");
_Static_assert (offsetof (spAttachment, type) == 0x04, "attachment+0x04 type");
_Static_assert (offsetof (spAttachment, vtable) == 0x08, "attachment+0x08 vtable");
_Static_assert (offsetof (spAttachment, loader) == 0x0c, "attachment+0x0c loader");
_Static_assert (sizeof (spAttachmentVtable) == 4, "attachment vtable is 4 B");
_Static_assert (sizeof (spVertexAttachment) == 0x20, "spVertexAttachment is 0x20");
_Static_assert (offsetof (spVertexAttachment, owned_14) == 0x14, "vertex+0x14");
_Static_assert (offsetof (spVertexAttachment, owned_1c) == 0x1c, "vertex+0x1c");
_Static_assert (sizeof (spBoundingBoxAttachment) == 0x24, "bbox is 0x24");
_Static_assert (sizeof (spPathAttachment) == 0x34, "path is 0x34");
_Static_assert (offsetof (spPathAttachment, owned_28) == 0x28, "path+0x28");
_Static_assert (sizeof (spMeshAttachment) == 0x94, "mesh is 0x94");
_Static_assert (offsetof (spMeshAttachment, region) == 0x24, "mesh+0x24 region");
_Static_assert (offsetof (spMeshAttachment, regionOffsetX) == 0x28, "mesh+0x28");
_Static_assert (offsetof (spMeshAttachment, regionOriginalHeight) == 0x3c, "mesh+0x3c");
_Static_assert (offsetof (spMeshAttachment, u) == 0x40, "mesh+0x40 u");
_Static_assert (offsetof (spMeshAttachment, rotate) == 0x50, "mesh+0x50 rotate");
_Static_assert (offsetof (spMeshAttachment, r) == 0x68, "mesh+0x68 r");
_Static_assert (offsetof (spMeshAttachment, parentMesh) == 0x7c, "mesh+0x7c parent");
_Static_assert (offsetof (spMeshAttachment, owned_88) == 0x88, "mesh+0x88");
_Static_assert (sizeof (spRegionAttachment) == 0x9c, "region is 0x9c");
_Static_assert (offsetof (spRegionAttachment, owned_10) == 0x10, "region+0x10");
_Static_assert (offsetof (spRegionAttachment, scaleX) == 0x1c, "region+0x1c");
_Static_assert (offsetof (spRegionAttachment, scaleY) == 0x20, "region+0x20");
_Static_assert (offsetof (spRegionAttachment, r) == 0x30, "region+0x30");
_Static_assert (offsetof (spRegionAttachment, region) == 0x40, "region+0x40");
_Static_assert (offsetof (spRegionAttachment, regionOriginalHeight) == 0x58, "region+0x58");
_Static_assert (offsetof (spRegionAttachment, uvs) == 0x7c, "region+0x7c uvs");
_Static_assert (offsetof (spAtlasRegion, width) == 0x0c, "atlasRegion+0x0c");
_Static_assert (offsetof (spAtlasRegion, height) == 0x10, "atlasRegion+0x10");
_Static_assert (offsetof (spAtlasRegion, u) == 0x14, "atlasRegion+0x14");
_Static_assert (offsetof (spAtlasRegion, v2) == 0x20, "atlasRegion+0x20");
_Static_assert (offsetof (spAtlasRegion, offsetX) == 0x24, "atlasRegion+0x24");
_Static_assert (offsetof (spAtlasRegion, originalHeight) == 0x30, "atlasRegion+0x30");
_Static_assert (offsetof (spAtlasRegion, rotate) == 0x38, "atlasRegion+0x38");
_Static_assert (offsetof (spAtlasRegion, next) == 0x4c, "atlasRegion+0x4c next");
_Static_assert (offsetof (spAtlas, regions) == 0x04, "atlas+0x04 regions");

#endif /* SPINE_ATLAS_ATTACHMENT_H */
