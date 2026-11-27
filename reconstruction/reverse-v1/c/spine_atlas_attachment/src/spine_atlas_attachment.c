/*
 * spine_atlas_attachment.c — ARM32 reconstruction of the AtlasAttachmentLoader
 * creation dispatch and the attachment lifetime chain of libyoyo_armv7.so
 *   sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Each function is a literal transcription of the frozen decode; the comment
 * above it gives the original VA, size, every call/offset that matters, and
 * which behaviour is *not* present (NULL guards, error returns, etc.).
 *
 * noinline is used only where the original has a real bl call boundary: it
 * keeps the same call graph in this TU and stops -O2 from erasing it.  It
 * changes neither the AAPCS32 contract nor behaviour.
 */

#include "spine_atlas_attachment.h"

/* __FILE__ strings, verbatim from .rodata of the original image. */
#define SP_FILE_ATLAS_LOADER \
	"jni/../jni/yoyo/../../../spine-c/src/spine/AtlasAttachmentLoader.c"
#define SP_FILE_ATTACHMENT \
	"jni/../jni/yoyo/../../../spine-c/src/spine/Attachment.c"
#define SP_FILE_ATTACHMENT_LOADER \
	"jni/../jni/yoyo/../../../spine-c/src/spine/AttachmentLoader.c"
#define SP_FILE_REGION \
	"jni/../jni/yoyo/../../../spine-c/src/spine/RegionAttachment.c"
#define SP_FILE_BBOX \
	"jni/../jni/yoyo/../../../spine-c/src/spine/BoundingBoxAttachment.c"
#define SP_FILE_MESH \
	"jni/../jni/yoyo/../../../spine-c/src/spine/MeshAttachment.c"
#define SP_FILE_PATH \
	"jni/../jni/yoyo/../../../spine-c/src/spine/PathAttachment.c"

/* libc imports are explicit; the original reaches them through its PLT. */
extern size_t strlen (const char *s);
extern char *strcpy (char *restrict dst, const char *restrict src);
extern int strcmp (const char *s1, const char *s2);
extern int sprintf (char *restrict buf, const char *restrict fmt, ...);

#define SP_NOINLINE __attribute__ ((noinline))
#if defined(__clang__) && __has_attribute(disable_tail_calls)
/* The original keeps a frame around these indirect calls (blx, then pop),
 * instead of returning through the callee.  Keeps the same call/return
 * boundary in the reconstruction. */
#define SP_NOTAIL __attribute__ ((disable_tail_calls))
#else
#define SP_NOTAIL
#endif

/*
 * 0x284a08  _spAtlasAttachmentLoader_createAttachment  (428 B)
 *
 * ABI: spAttachment *f(loader r0, skin r1, type r2, name r3, path [sp]).
 * skin is never read.  The dispatch is an ARM jump table:
 *
 *   0x284a18  cmp r2,#4
 *   0x284a1c  addls pc,pc,r2,lsl #2      ; unsigned type <= 4
 *   0x284a24  b region    (type 0)       ; 0x284ae0
 *   0x284a28  b bbox      (type 1)       ; 0x284ad0
 *   0x284a2c  b mesh      (type 2)       ; 0x284a48
 *   0x284a30  b mesh      (type 3)       ; 0x284a48
 *   0x284a34  b path      (type 4)       ; 0x284a38
 *   fallthrough / type > 4 / negative:   ; 0x284a20 -> 0x284b60
 *            setUnknownTypeError(loader, type); return 0
 *
 * region (0x284ae0):
 *   atlas = loader->atlas [+0x0c]; path = [sp,#0x20]
 *   region = spAtlas_findRegion(atlas, path)
 *   if (!region) { setError(loader, "Region not found: ", path); return 0; }
 *   a = spRegionAttachment_create(name)
 *   a->region = region                         [+0x40]
 *   spRegionAttachment_setUVs(a, region->u, region->v, region->u2,
 *                             region->v2, region->rotate)
 *   a->regionOffsetX..OriginalHeight = region->offsetX..originalHeight
 *                                              [+0x44..+0x58]
 *   return a
 *
 * mesh (0x284a48, both type 2 and type 3; linked mesh takes the same path):
 *   region = spAtlas_findRegion(loader->atlas, path)
 *   if (!region) { setError(loader, "Region not found: ", path); return 0; }
 *   a = spMeshAttachment_create(name)
 *   a->u/v/u2/v2  = region->u/v/u2/v2          [+0x40..+0x4c]
 *   a->rotate     = region->rotate             [+0x50]
 *   a->region     = region                     [+0x24]
 *   a->regionOffsetX/Y, regionWidth/Height,
 *   regionOriginalWidth/Height = region fields [+0x28..+0x3c]
 *   return a
 *
 * bbox (0x284ad0): spBoundingBoxAttachment_create(name)
 * path (0x284a38): spPathAttachment_create(name)
 *
 * No NULL test on loader, name or path before the first dereference.
 * The two "Region not found: " literals both resolve to 0x357604.
 */
spAttachment *SP_NOINLINE
_spAtlasAttachmentLoader_createAttachment (spAttachmentLoader *loader,
                                           spSkin *skin, int32_t type,
                                           const char *name, const char *path)
{
	spAtlasRegion *region;

	(void)skin; /* r1 is never read by the original body. */

	switch (type) {
	case 0: { /* region */
		spRegionAttachment *attachment;

		region = spAtlas_findRegion (loader->atlas, path);
		if (region == 0) {
			_spAttachmentLoader_setError (loader, "Region not found: ", path);
			return 0;
		}

		attachment = spRegionAttachment_create (name);
		attachment->region = region;
		spRegionAttachment_setUVs (attachment, region->u, region->v,
		                           region->u2, region->v2, region->rotate);
		attachment->regionOffsetX = region->offsetX;
		attachment->regionOffsetY = region->offsetY;
		attachment->regionWidth = region->width;
		attachment->regionHeight = region->height;
		attachment->regionOriginalWidth = region->originalWidth;
		attachment->regionOriginalHeight = region->originalHeight;
		return (spAttachment *)attachment;
	}
	case 1: /* bounding box */
		return (spAttachment *)spBoundingBoxAttachment_create (name);

	case 2: /* mesh */
	case 3: { /* linked mesh: same branch in the original */
		spMeshAttachment *attachment;

		region = spAtlas_findRegion (loader->atlas, path);
		if (region == 0) {
			_spAttachmentLoader_setError (loader, "Region not found: ", path);
			return 0;
		}

		attachment = spMeshAttachment_create (name);
		attachment->region = region;
		attachment->regionOffsetX = region->offsetX;
		attachment->regionOffsetY = region->offsetY;
		attachment->regionWidth = region->width;
		attachment->regionHeight = region->height;
		attachment->regionOriginalWidth = region->originalWidth;
		attachment->regionOriginalHeight = region->originalHeight;
		attachment->u = region->u;
		attachment->v = region->v;
		attachment->u2 = region->u2;
		attachment->v2 = region->v2;
		attachment->rotate = region->rotate;
		return (spAttachment *)attachment;
	}
	case 4: /* path */
		return (spAttachment *)spPathAttachment_create (name);

	default:
		_spAttachmentLoader_setUnknownTypeError (loader, type);
		return 0;
	}
}

/*
 * 0x284958  spAtlas_findRegion  (176 B)
 *
 * ABI: spAtlasRegion *f(const spAtlas *atlas r0, const char *name r1).
 *
 *   region = atlas->regions                     [r0+0x04]
 *   while (region) {
 *       if (strcmp(region->name, name) == 0) return region;   // full path
 *       if (name) {
 *           i = strlen(name) - 1;
 *           if (i >= 0 && name[i] != '/') {
 *               scan i downward to the previous '/';
 *               if found: strcmp(region->name, name + i + 1) == 0
 *                         -> return region
 *           }
 *       }
 *       region = region->next;                  [r5+0x4c]
 *   }
 *   return 0;
 *
 * The machine order is: full-path strcmp *first* (0x284978), then the
 * basename fallback.  A request whose last byte is '/' never gets a basename
 * match (0x2849a0/0x2849ac); an empty name and a name with no '/' do not
 * either (0x2849bc decrement-from-zero exits, 0x2849c4 advances).
 */
spAtlasRegion *SP_NOINLINE
spAtlas_findRegion (const spAtlas *atlas, const char *name)
{
	spAtlasRegion *region = atlas->regions;

	while (region != 0) {
		if (strcmp (region->name, name) == 0)
			return region;

		if (name != 0) {
			int32_t i = (int32_t)((uint32_t)strlen (name) - 1u);

			if (i >= 0 && name[i] != '/') {
				while (i >= 0 && name[i] != '/')
					--i;
				if (i >= 0 && strcmp (region->name, name + i + 1) == 0)
					return region;
			}
		}

		region = region->next;
	}

	return 0;
}

/*
 * 0x288f78  spRegionAttachment_create  (100 B)
 *
 * ABI: spRegionAttachment *f(const char *name r0).
 *
 *   self = _calloc(1, 0x9c, ".../RegionAttachment.c", 43)   [no NULL check]
 *   self->+0x1c = +0x20 = 1.0f                              (scaleX, scaleY)
 *   self->+0x30 = +0x34 = +0x38 = +0x3c = 1.0f              (r,g,b,a)
 *   _spAttachment_init(&self->super, name, 0, _spRegionAttachment_dispose)
 *   return self
 *
 * The dispose pointer is the GOT slot at 0x3f1910 (R_ARM_RELATIVE ->
 * 0x288f58); taking the function address is the same value.
 */
spRegionAttachment *SP_NOINLINE
spRegionAttachment_create (const char *name)
{
	spRegionAttachment *self =
		(spRegionAttachment *)_calloc (1u, sizeof (*self), SP_FILE_REGION, 43u);

	self->scaleX = 1.0f;
	self->scaleY = 1.0f;
	self->r = 1.0f;
	self->g = 1.0f;
	self->b = 1.0f;
	self->a = 1.0f;

	_spAttachment_init (&self->super, name, 0, _spRegionAttachment_dispose);

	return self;
}

/*
 * 0x288fdc  spRegionAttachment_setUVs  (100 B)
 *
 * ABI: void f(self r0, u r1, v r2, u2 r3, v2 [sp], rotate [sp+4]).
 * 6th arg is a nonzero-int test, not a bool type.
 *
 * rotate == 0:  {u,v2, u,v, u2,v, u2,v2}
 * rotate != 0:  {u2,v2, u,v2, u,v, u2,v}
 * The two stores of u (or u2) and v are deliberate (0x288ff0..0x289008 and
 * 0x289018..0x289034); they are not a uniform 2x4 block.
 */
void SP_NOINLINE
spRegionAttachment_setUVs (spRegionAttachment *self, float u, float v,
                           float u2, float v2, int32_t rotate)
{
	if (rotate) {
		self->uvs[0] = u2;
		self->uvs[1] = v2;
		self->uvs[2] = u;
		self->uvs[3] = v2;
		self->uvs[4] = u;
		self->uvs[5] = v;
		self->uvs[6] = u2;
		self->uvs[7] = v;
	} else {
		self->uvs[0] = u;
		self->uvs[1] = v2;
		self->uvs[2] = u;
		self->uvs[3] = v;
		self->uvs[4] = u2;
		self->uvs[5] = v;
		self->uvs[6] = u2;
		self->uvs[7] = v2;
	}
}

/*
 * 0x285af8  spBoundingBoxAttachment_create  (72 B)
 *
 *   calloc(1, 0x24, ".../BoundingBoxAttachment.c", 44)
 *   _spAttachment_init(self, name, 1, _spBoundingBoxAttachment_dispose)
 *   return self
 */
spBoundingBoxAttachment *SP_NOINLINE
spBoundingBoxAttachment_create (const char *name)
{
	spBoundingBoxAttachment *self =
		(spBoundingBoxAttachment *)_calloc (1u, sizeof (*self), SP_FILE_BBOX, 44u);

	_spAttachment_init (&self->super.super, name, 1,
	                    _spBoundingBoxAttachment_dispose);

	return self;
}

/*
 * 0x2874dc  spMeshAttachment_create  (92 B)
 *
 *   calloc(1, 0x94, ".../MeshAttachment.c", 50)
 *   self->+0x68 = +0x6c = +0x70 = +0x74 = 1.0f     (r,g,b,a)
 *   _spAttachment_init(self, name, 2, _spMeshAttachment_dispose)
 *   return self
 */
spMeshAttachment *SP_NOINLINE
spMeshAttachment_create (const char *name)
{
	spMeshAttachment *self =
		(spMeshAttachment *)_calloc (1u, sizeof (*self), SP_FILE_MESH, 50u);

	self->r = 1.0f;
	self->g = 1.0f;
	self->b = 1.0f;
	self->a = 1.0f;

	_spAttachment_init (&self->super.super, name, 2, _spMeshAttachment_dispose);

	return self;
}

/*
 * 0x2876f4  spPathAttachment_create  (72 B)
 *
 *   calloc(1, 0x34, ".../PathAttachment.c", 45)
 *   _spAttachment_init(self, name, 4, _spPathAttachment_dispose)
 *   return self
 */
spPathAttachment *SP_NOINLINE
spPathAttachment_create (const char *name)
{
	spPathAttachment *self =
		(spPathAttachment *)_calloc (1u, sizeof (*self), SP_FILE_PATH, 45u);

	_spAttachment_init (&self->super.super, name, 4,
	                    _spPathAttachment_dispose);

	return self;
}

/*
 * 0x284c18  _spAttachment_init  (108 B)
 *
 * ABI: void f(self r0, name r1, type r2, dispose r3).
 *
 *   vtable = _calloc(1, 4, ".../Attachment.c", 43)   [no NULL check]
 *   self->vtable = vtable                 [+0x08]
 *   vtable->dispose = dispose             [+0x00]
 *   name_copy = _malloc(strlen(name)+1, ".../Attachment.c", 46)
 *   self->name = name_copy                [+0x00]
 *   strcpy(name_copy, name)
 *   self->type = type                     [+0x04]
 *
 * +0x0c (loader) is not written here.  The constructor's calloc is what
 * leaves it zero; _spAttachment_deinit tests it.
 */
void SP_NOINLINE
_spAttachment_init (spAttachment *self, const char *name, int32_t type,
                    void (*dispose) (spAttachment *self))
{
	spAttachmentVtable *vtable =
		(spAttachmentVtable *)_calloc (1u, sizeof (*vtable), SP_FILE_ATTACHMENT, 43u);

	self->vtable = vtable;
	vtable->dispose = dispose;

	self->name = (char *)_malloc ((uint32_t)strlen (name) + 1u,
	                              SP_FILE_ATTACHMENT, 46u);
	strcpy (self->name, name);

	self->type = type;
}

/*
 * 0x284c84  _spAttachment_deinit  (48 B)
 *
 *   if (self->loader) spAttachmentLoader_disposeAttachment(self->loader, self);
 *   _free(self->vtable);
 *   _free(self->name);        // tail call in the original
 *
 * The loader slot test is against NULL only; no type check, no clearing of
 * freed fields.
 */
void SP_NOINLINE
_spAttachment_deinit (spAttachment *self)
{
	if (self->loader != 0)
		spAttachmentLoader_disposeAttachment (self->loader, self);

	_free (self->vtable);
	_free (self->name);
}

/*
 * 0x284cb4  spAttachment_dispose (20 B) is NOT redeclared here: it is already
 * recovered in the main tree at
 *   reconstruction/reverse-v1/c/spine_skeleton_data/src/spine_skeleton_data.c
 * (vtable = self+0x08; call slot +0x00; no free of self).  Keeping the single
 * owner avoids a duplicate definition when the modules are linked together.
 * The prototype comes from spine_skeleton_data.h, included above.
 */

/*
 * 0x284df0  _spAttachmentLoader_setError  (120 B)
 *
 *   _free(self->error1);                                  [+0x00]
 *   _free(self->error2);                                  [+0x04]
 *   self->error1 = _malloc(strlen(error1)+1, ".../AttachmentLoader.c", 91);
 *   strcpy(self->error1, error1);
 *   self->error2 = _malloc(strlen(error2)+1, ".../AttachmentLoader.c", 92);
 *   strcpy(self->error2, error2);
 *
 * Both frees happen before either allocation; the slots are not NULLed first
 * and a failed allocation is not checked (strcpy would fault).
 */
void SP_NOINLINE
_spAttachmentLoader_setError (spAttachmentLoader *self,
                              const char *error1, const char *error2)
{
	_free (self->error1);
	_free (self->error2);

	self->error1 = (char *)_malloc ((uint32_t)strlen (error1) + 1u,
	                                SP_FILE_ATTACHMENT_LOADER, 91u);
	strcpy (self->error1, error1);

	self->error2 = (char *)_malloc ((uint32_t)strlen (error2) + 1u,
	                                SP_FILE_ATTACHMENT_LOADER, 92u);
	strcpy (self->error2, error2);
}

/*
 * 0x284e68  _spAttachmentLoader_setUnknownTypeError  (112 B)
 *
 *   char buffer[16];                    // sp+4..sp+0x13, canary at sp+0x14
 *   sprintf(buffer, "%d", type);
 *   _spAttachmentLoader_setError(self, "Unknown attachment type: ", buffer);
 *
 * The original is stack-protected (__stack_chk_guard load at 0x3ed958); that
 * is a build flag, not a semantic branch.  Buffer size follows the frame
 * (sub sp,#0x18; buffer at sp+4; canary at sp+0x14).
 */
void SP_NOINLINE SP_NOTAIL
_spAttachmentLoader_setUnknownTypeError (spAttachmentLoader *self, int32_t type)
{
	char buffer[16];

	sprintf (buffer, "%d", type);
	_spAttachmentLoader_setError (self, "Unknown attachment type: ", buffer);
}

/*
 * 0x284d58  spAttachmentLoader_createAttachment  (96 B)
 *
 * ABI: spAttachment *f(loader r0, skin r1, type r2, name r3, path [sp]).
 *
 *   _free(loader->error1);
 *   _free(loader->error2);
 *   loader->error1 = 0;
 *   loader->error2 = 0;
 *   return loader->vtable->createAttachment(loader, skin, type, name, path);
 *
 * Both errors are cleared *before* the indirect call, so a callee that calls
 * setError (the Atlas loader's missing-region path) installs fresh strings.
 * The vtable slot is not NULL-checked.
 */
spAttachment *SP_NOINLINE SP_NOTAIL
spAttachmentLoader_createAttachment (spAttachmentLoader *self, spSkin *skin,
                                     int32_t type, const char *name,
                                     const char *path)
{
	spAttachment *attachment;

	_free (self->error1);
	_free (self->error2);
	self->error1 = 0;
	self->error2 = 0;

	attachment = self->vtable->createAttachment (self, skin, type, name, path);
	return attachment;
}

/*
 * 0x284db8  spAttachmentLoader_configureAttachment  (28 B)
 *
 *   fn = loader->vtable->configureAttachment;
 *   if (fn) fn(loader, attachment);
 */
void SP_NOINLINE SP_NOTAIL
spAttachmentLoader_configureAttachment (spAttachmentLoader *self,
                                        spAttachment *attachment)
{
	void (*configure) (spAttachmentLoader *, spAttachment *) =
		self->vtable->configureAttachment;

	if (configure != 0)
		configure (self, attachment);
}

/*
 * 0x284dd4  spAttachmentLoader_disposeAttachment  (28 B)
 *
 *   fn = loader->vtable->disposeAttachment;
 *   if (fn) fn(loader, attachment);
 *
 * This is the body called by _spAttachment_deinit for attachments whose
 * +0x0c loader slot is non-NULL.
 */
void SP_NOINLINE SP_NOTAIL
spAttachmentLoader_disposeAttachment (spAttachmentLoader *self,
                                      spAttachment *attachment)
{
	void (*dispose) (spAttachmentLoader *, spAttachment *) =
		self->vtable->disposeAttachment;

	if (dispose != 0)
		dispose (self, attachment);
}

/*
 * 0x288f58  _spRegionAttachment_dispose  (32 B)
 *
 *   _spAttachment_deinit(self);
 *   _free(self->+0x10);
 *   _free(self);
 */
void SP_NOINLINE
_spRegionAttachment_dispose (spAttachment *self)
{
	spRegionAttachment *region = (spRegionAttachment *)self;

	_spAttachment_deinit (self);
	_free (region->owned_10);
	_free (self);
}

/*
 * 0x285ae0  _spBoundingBoxAttachment_dispose  (24 B)
 *
 *   _spVertexAttachment_deinit(self);
 *   _free(self);
 */
void SP_NOINLINE
_spBoundingBoxAttachment_dispose (spAttachment *self)
{
	_spVertexAttachment_deinit (self);
	_free (self);
}

/*
 * 0x2876d4  _spPathAttachment_dispose  (32 B)
 *
 *   _spVertexAttachment_deinit(self);
 *   _free(self->+0x28);
 *   _free(self);
 */
void SP_NOINLINE
_spPathAttachment_dispose (spAttachment *self)
{
	spPathAttachment *path = (spPathAttachment *)self;

	_spVertexAttachment_deinit (self);
	_free (path->owned_28);
	_free (self);
}

/*
 * 0x28747c  _spMeshAttachment_dispose  (96 B)
 *
 *   _free(self->+0x54);
 *   _free(self->+0x5c);
 *   if (self->+0x7c != 0) {          // parent mesh: shared arrays
 *       _spAttachment_deinit(self);
 *   } else {
 *       _spVertexAttachment_deinit(self);
 *       _free(self->+0x58);
 *       _free(self->+0x64);
 *       _free(self->+0x88);
 *   }
 *   _free(self);
 *
 * +0x7c is written by spMeshAttachment_setParentMesh (0x287654), so the
 * branch is "has parent mesh", not a type tag.
 */
void SP_NOINLINE
_spMeshAttachment_dispose (spAttachment *self)
{
	spMeshAttachment *mesh = (spMeshAttachment *)self;

	_free (mesh->owned_54);
	_free (mesh->owned_5c);

	if (mesh->parentMesh != 0) {
		_spAttachment_deinit (self);
	} else {
		_spVertexAttachment_deinit (self);
		_free (mesh->owned_58);
		_free (mesh->owned_64);
		_free (mesh->owned_88);
	}

	_free (self);
}

/*
 * 0x28f62c  _spVertexAttachment_deinit  (32 B)
 *
 *   _spAttachment_deinit(self);
 *   _free(self->+0x14);
 *   _free(self->+0x1c);     // tail call in the original
 *
 * There is no recovered _spVertexAttachment_init: the constructors call
 * _spAttachment_init directly and rely on calloc zeroing +0x14/+0x1c.
 */
void SP_NOINLINE
_spVertexAttachment_deinit (spAttachment *self)
{
	spVertexAttachment *vertex = (spVertexAttachment *)self;

	_spAttachment_deinit (self);
	_free (vertex->owned_14);
	_free (vertex->owned_1c);
}
