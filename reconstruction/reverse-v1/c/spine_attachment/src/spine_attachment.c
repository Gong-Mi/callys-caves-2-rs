/*
 * spine_attachment.c — reconstruction of the four attachment-loader lifetime
 * entry points of libyoyo_armv7.so
 *   sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Each function below is a straight-line body in the original: no compare, no
 * branch, no NULL guard.  The comments give the original VA + the machine
 * events being reproduced, so this file can be diffed against the frozen JSON
 * decode line by line.
 */

#include "spine_attachment.h"

/*
 * __FILE__ strings, verbatim from .rodata of the original image:
 *   0x357618 "jni/../jni/yoyo/../../../spine-c/src/spine/AtlasAttachmentLoader.c"
 *   0x357694 "jni/../jni/yoyo/../../../spine-c/src/spine/AttachmentLoader.c"
 * Line numbers come from the decoded immediates (r3=#93 / r3=#51).
 */
#define SP_FILE_ATLAS_LOADER "jni/../jni/yoyo/../../../spine-c/src/spine/AtlasAttachmentLoader.c"
#define SP_FILE_LOADER "jni/../jni/yoyo/../../../spine-c/src/spine/AttachmentLoader.c"

/*
 * Re-read of an owned error field.  The original deinit reloads [r4] and then
 * [r4,#4] *after* the preceding _free call (0x284d24, 0x284d2c: each ldr comes
 * after the bl).  A plain `_free(self->error1)` would already be reloaded here
 * because _free is an opaque extern, but the volatile-qualified slot makes the
 * re-read a source-level guarantee instead of a codegen accident (survives LTO
 * if the allocator ever lands in the same TU).
 */
static void free_error_reloaded (char *volatile *slot)
{
	_free (*slot);
}

/*
 * 0x284bb4  spAtlasAttachmentLoader_create(spAtlas *atlas) -> loader
 *
 *   0x284bb4  r2 = file literal, r1 = 16, r0 = 1, r3 = 93   (calloc args)
 *   0x284bd4  bl _calloc
 *   0x284be8  r1 = *(0x3f18fc) -> _spAttachmentLoader_deinit     (R_ARM_RELATIVE)
 *   0x284bf0  r2 = *(0x3f1900) -> _spAtlasAttachmentLoader_createAttachment
 *   0x284be0  r3 = 0, [sp] = 0                              (configure/disposeAttachment)
 *   0x284bf8  bl _spAttachmentLoader_init(self, deinit, create, 0, 0)
 *   0x284c00  str atlas -> self+0x0c     (after init returns, not inside it)
 *   0x284bfc  return self                (r0 = r4; no calloc-NULL check)
 *
 * The two GOT loads are a PIC artifact of the original build, not semantics:
 * both slots carry R_ARM_RELATIVE and resolve to those two definitions, so
 * taking the function addresses directly is the same value.
 */
spAttachmentLoader *spAtlasAttachmentLoader_create (spAtlas *atlas)
{
	spAttachmentLoader *self = _calloc (1, 16u, SP_FILE_ATLAS_LOADER, 93u);

	_spAttachmentLoader_init (self, _spAttachmentLoader_deinit,
	                          _spAtlasAttachmentLoader_createAttachment, 0, 0);

	self->atlas = atlas;

	return self;
}

/*
 * 0x284cc8  _spAttachmentLoader_init(self r0, dispose r1, create r2,
 *                                    configure r3, disposeAttachment [sp])
 *
 *   0x284cf4  bl _calloc(1, 16, ".../AttachmentLoader.c", 51)
 *   0x284cf8  self+0x08   = block
 *   0x284cfc  block+0x0c  = arg1 (dispose)
 *   0x284d00  block+0x00  = arg2 (createAttachment)
 *   0x284d04  block+0x04  = arg3 (configureAttachment)
 *   0x284d08  block+0x08  = stacked arg4 (disposeAttachment)
 *
 * Store order is the machine order.  self+0x00, +0x04 and +0x0c are not
 * touched here; the create caller owns +0x0c, calloc zeroing owns +0/+0x04.
 * No NULL check on self and no NULL check on the incoming callbacks: the
 * wrappers at 0x284db8/0x284dd4 are the ones that test +0x04/+0x08 before
 * calling, while slot +0x0c is called unconditionally by dispose.
 *
 * noinline only keeps create's `bl _spAttachmentLoader_init` visible (the
 * original does not inline it); it changes neither ABI nor behaviour.
 */
void __attribute__ ((noinline)) _spAttachmentLoader_init (spAttachmentLoader *self,
                               void (*dispose) (spAttachmentLoader *loader),
                               spAttachment *(*createAttachment) (spAttachmentLoader *loader,
                                                                 spSkin *skin, int32_t type,
                                                                 const char *name,
                                                                 const char *path),
                               void (*configureAttachment) (spAttachmentLoader *loader,
                                                            spAttachment *attachment),
                               void (*disposeAttachment) (spAttachmentLoader *loader,
                                                          spAttachment *attachment))
{
	spAttachmentLoaderVtable *vtable = _calloc (1, 16u, SP_FILE_LOADER, 51u);
	/* Ordered stores: the block is fresh, so C would allow reordering, but the
	   original emits +0x0c, +0x00, +0x04, +0x08 in exactly that sequence
	   (0x284cfc, 0x284d00, 0x284d04, 0x284d08).  Volatile stores keep it. */
	volatile spAttachmentLoaderVtable *ordered = vtable;

	*(spAttachmentLoaderVtable *volatile *)&self->vtable = vtable;
	ordered->dispose = dispose;
	ordered->createAttachment = createAttachment;
	ordered->configureAttachment = configureAttachment;
	ordered->disposeAttachment = disposeAttachment;
}

/*
 * 0x284d14  _spAttachmentLoader_deinit(self)
 *
 *   0x284d1c  r0 = [r0,#8];  bl _free      -> the 16 B vtable block goes first
 *   0x284d24  r0 = [r4];     bl _free      -> error1, re-read from the loader
 *   0x284d30  r0 = [r4,#4];  b  _free      -> error2, re-read again (tail call)
 *
 * Order is +0x08, +0x00, +0x04 — not a reverse-order destructor.  No NULL
 * checks, no clearing of the freed fields, no call into the vtable: this body
 * only frees the three owned allocations.
 */
void _spAttachmentLoader_deinit (spAttachmentLoader *self)
{
	_free (self->vtable);
	free_error_reloaded (&self->error1);
	free_error_reloaded (&self->error2);
}

/*
 * 0x284d38  spAttachmentLoader_dispose(self)
 *
 *   0x284d38  r3 = [r0,#8]
 *   0x284d44  r3 = [r3,#0xc]     -> vtable->dispose
 *   0x284d48  blx r3             -> r0 is still self (loader is the only arg)
 *   0x284d4c  r0 = r4;  b _free  -> free the loader itself (tail call)
 *
 * The dispatch is unconditional: no test of self, no test of vtable, no test
 * of the slot.  The vtable block is freed by the dispatched callback (the
 * deinit body above), not here.
 */
void spAttachmentLoader_dispose (spAttachmentLoader *self)
{
	spAttachmentLoaderVtable *vtable = self->vtable;

	vtable->dispose (self);
	_free (self);
}
