/*
 * spine_attachment.h — byte-pinned native layout + the four attachment-loader
 * lifetime entry points recovered from
 *   /data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so
 *   sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Recovered bodies:
 *   spAtlasAttachmentLoader_create   0x284bb4  100 B
 *   _spAttachmentLoader_init         0x284cc8   76 B
 *   _spAttachmentLoader_deinit       0x284d14   36 B
 *   spAttachmentLoader_dispose       0x284d38   32 B
 *
 * Every offset/size below is read off the frozen decode in
 * .hermes/reports/cally-native-static-20261102/attachment-original.json and
 * re-checked against the ELF's own disassembly.  Comments say which.
 * Nothing here is a guess about upstream source; names are labels, layout is
 * the contract.
 */

#ifndef SPINE_ATTACHMENT_H
#define SPINE_ATTACHMENT_H

#include <stddef.h>
#include <stdint.h>

#if !defined(__arm__) || defined(__aarch64__) || defined(__LP64__)
#error "spine_attachment.h: ARM32 ABI only (layout pinned to ARMv7 libyoyo)"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Opaque: only pointer-width identity is asserted by the recovered bodies. */
typedef struct spAtlas spAtlas;
typedef struct spSkin spSkin;
typedef struct spAttachment spAttachment;
typedef struct spAttachmentLoader spAttachmentLoader;
typedef struct spAttachmentLoaderVtable spAttachmentLoaderVtable;

/*
 * 16 bytes, allocated by _spAttachmentLoader_init itself (calloc(1,16,...:51)).
 * Slot order is pinned twice:
 *   - init's stores            (0x284cfc..0x284d08)
 *   - the call sites in this DSO (0x284d84/0x284d98 slot +0x00,
 *     0x284dbc/0x284dc0 slot +0x04, 0x284dd8/0x284ddc slot +0x08,
 *     0x284d44/0x284d48 slot +0x0c) plus spAttachmentLoader_dispose.
 * Slot +0x00 takes 5 arguments: the exported forwarding wrapper
 * spAttachmentLoader_createAttachment (0x284d58) passes loader, skin, type,
 * name, path straight through, and the library body at 0x284a08 reads
 * r3 as the attachment name and the stacked argument as the region path.
 */
struct spAttachmentLoaderVtable {
	/* +0x00 */ spAttachment *(*createAttachment) (spAttachmentLoader *loader, spSkin *skin,
	                                               int32_t type, const char *name,
	                                               const char *path);
	/* +0x04 */ void (*configureAttachment) (spAttachmentLoader *loader, spAttachment *attachment);
	/* +0x08 */ void (*disposeAttachment) (spAttachmentLoader *loader, spAttachment *attachment);
	/* +0x0c */ void (*dispose) (spAttachmentLoader *loader);
};

/*
 * 16 bytes, allocated by spAtlasAttachmentLoader_create (calloc(1,16,...:93)).
 * +0x00 / +0x04 are the two owned, heap-copied error strings: the sibling
 * body _spAttachmentLoader_setError (0x284df0) frees both, then _malloc +
 * strcpy's into them; spAttachmentLoader_createAttachment (0x284d58) frees
 * both and NULLs both before dispatching slot +0x00.
 * +0x08 holds the vtable block allocated by init; +0x0c is the atlas, stored
 * by spAtlasAttachmentLoader_create after init returns (0x284c00).
 */
struct spAttachmentLoader {
	/* +0x00 */ char *error1;
	/* +0x04 */ char *error2;
	/* +0x08 */ spAttachmentLoaderVtable *vtable;
	/* +0x0c */ spAtlas *atlas;
};

/* ---- recovered entry points ------------------------------------------- */

/* 0x284bb4: calloc(1,16,".../AtlasAttachmentLoader.c",93) -> init -> atlas. */
spAttachmentLoader *spAtlasAttachmentLoader_create (spAtlas *atlas);

/* 0x284cc8: calloc(1,16,".../AttachmentLoader.c",51) and fill the vtable. */
void _spAttachmentLoader_init (spAttachmentLoader *self,
                               void (*dispose) (spAttachmentLoader *loader),
                               spAttachment *(*createAttachment) (spAttachmentLoader *loader,
                                                                  spSkin *skin, int32_t type,
                                                                  const char *name,
                                                                  const char *path),
                               void (*configureAttachment) (spAttachmentLoader *loader,
                                                            spAttachment *attachment),
                               void (*disposeAttachment) (spAttachmentLoader *loader,
                                                          spAttachment *attachment));

/* 0x284d14: free(+0x08), free(+0x00), free(+0x04) — in that order. */
void _spAttachmentLoader_deinit (spAttachmentLoader *self);

/* 0x284d38: vtable->dispose(self) (unchecked), then free(self). */
void spAttachmentLoader_dispose (spAttachmentLoader *self);

/* ---- external providers (declared, never defined in this batch) -------- */

/* Allocator line owns the six alloc entries; signatures are the agreed ones. */
extern void *_calloc (uint32_t nmemb, uint32_t size, const char *file, uint32_t line);
extern void _free (void *ptr);

/*
 * 0x284a08, 428 B.  NOT recovered here: it is an explicit internal gap (it
 * dispatches region/boundingbox/mesh/linkedmesh/path through spAtlas and the
 * five sp*Attachment_create constructors).  spAtlasAttachmentLoader_create
 * only needs its address for vtable slot +0x00, so it stays a hard extern:
 * no weak symbol, no stub, no "0x284a08" fallback.  Link must fail if the
 * provider is missing.
 */
extern spAttachment *_spAtlasAttachmentLoader_createAttachment (spAttachmentLoader *loader,
                                                                spSkin *skin, int32_t type,
                                                                const char *name,
                                                                const char *path);

#ifdef __cplusplus
}
#endif

/* ARM32-only belts: 32-bit pointers and the two heap objects are 16 B each. */
_Static_assert (sizeof (void *) == 4, "ARM32 only: pointer width must be 4");
_Static_assert (sizeof (spAttachmentLoaderVtable) == 16, "vtable block is 16 B (calloc(1,16,...:51))");
_Static_assert (sizeof (spAttachmentLoader) == 16, "loader is 16 B (calloc(1,16,...:93))");
_Static_assert (offsetof (spAttachmentLoader, error1) == 0x00, "loader->error1 is +0x00");
_Static_assert (offsetof (spAttachmentLoader, error2) == 0x04, "loader->error2 is +0x04");
_Static_assert (offsetof (spAttachmentLoader, vtable) == 0x08, "loader->vtable is +0x08");
_Static_assert (offsetof (spAttachmentLoader, atlas) == 0x0c, "loader->atlas is +0x0c");
_Static_assert (offsetof (spAttachmentLoaderVtable, createAttachment) == 0x00, "vtable slot +0x00");
_Static_assert (offsetof (spAttachmentLoaderVtable, configureAttachment) == 0x04, "vtable slot +0x04");
_Static_assert (offsetof (spAttachmentLoaderVtable, disposeAttachment) == 0x08, "vtable slot +0x08");
_Static_assert (offsetof (spAttachmentLoaderVtable, dispose) == 0x0c, "vtable slot +0x0c");

#endif /* SPINE_ATTACHMENT_H */
