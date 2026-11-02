/*
 * fixture.c — local qemu-arm self-check for the reconstructed Atlas attachment
 * dispatch + lifetime chain.  No original bytecode is loaded or executed.
 *
 * The allocator below is the test provider for the six spine_alloc entry
 * points; it records (size, __FILE__, line) and frees so the fixture can assert
 * the call sites and ownership order without a real heap.
 */

#include "spine_atlas_attachment.h"
extern uintptr_t __stack_chk_guard;

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

static long sys_write (int fd, const char *b, unsigned long n)
{
	register long r7 __asm__ ("r7") = 4;
	register long r0 __asm__ ("r0") = fd;
	register const char *r1 __asm__ ("r1") = b;
	register unsigned long r2 __asm__ ("r2") = n;
	__asm__ volatile ("svc #0" : "+r" (r0) : "r" (r1), "r" (r2), "r" (r7) : "memory");
	return r0;
}
static void sys_exit (int c)
{
	register long r7 __asm__ ("r7") = 1;
	register long r0 __asm__ ("r0") = c;
	__asm__ volatile ("svc #0" : : "r" (r0), "r" (r7) : "memory");
	for (;;);
}
static void out (const char *s)
{
	unsigned long n = 0;
	while (s[n]) n++;
	sys_write (1, s, n);
}
static int same (const char *a, const char *b)
{
	while (*a && *a == *b) a++, b++;
	return *a == *b;
}
static unsigned fails;
static void ck (int ok, const char *what)
{
	out (ok ? "ok   " : "FAIL "), out (what), out ("\n");
	fails += !ok;
}

/* libc pieces used by the reconstructed module, freestanding versions. */
size_t strlen (const char *s) { const char *p = s; while (*p) p++; return (size_t)(p - s); }
char *strcpy (char *d, const char *s)
{
	char *r = d;
	while ((*d++ = *s++) != 0) { }
	return r;
}
int strcmp (const char *a, const char *b)
{
	while (*a && *a == *b) a++, b++;
	return (unsigned char)*a - (unsigned char)*b;
}
int sprintf (char *buf, const char *fmt, ...)
{
	__builtin_va_list ap;
	int v, neg = 0;
	char tmp[12];
	int i = 0, n = 0;

	__builtin_va_start (ap, fmt);
	v = __builtin_va_arg (ap, int);
	__builtin_va_end (ap);
	if (*fmt != '%' || fmt[1] != 'd' || fmt[2] != 0) { buf[0] = 0; return 0; }
	uint32_t magnitude=(uint32_t)v;
	if (v < 0) { neg = 1; magnitude = 0u - magnitude; }
	do { tmp[i++] = (char)('0' + magnitude % 10u); magnitude /= 10u; } while (magnitude);
	if (neg) tmp[i++] = '-';
	while (i) buf[n++] = tmp[--i];
	buf[n] = 0;
#ifdef FACTORY_GUARD_NEGATIVE
	__stack_chk_guard ^= 1u;
#endif
	return n;
}
void *memset (void *p, int c, size_t n)
{
	unsigned char *b = (unsigned char *)p;
	while (n--) *b++ = (unsigned char)c;
	return p;
}

/* __stack_chk hooks: the module object is built with -fstack-protector-strong
 * -mstack-protector-guard=global, like the original's global guard load. */
/* soft-float ABI: the fixture's own float comparisons call this helper. */
int __aeabi_fcmpeq (float a, float b)
{
	union { float f; uint32_t u; } x, y;
	x.f = a; y.f = b;
	uint32_t ax=x.u & 0x7fffffffu, by=y.u & 0x7fffffffu;
	if (ax>0x7f800000u || by>0x7f800000u) return 0;
	return x.u == y.u || (ax | by) == 0;
}

uintptr_t __stack_chk_guard = 0x5a5a5a5au;
void __stack_chk_fail (void) { out ("STACK SMASH\n"); sys_exit (2); }

/* ---- recording allocator ------------------------------------------------ */

#define ARENA 65536
#define MAXEV 64
static unsigned char arena[ARENA];
static unsigned used, nai, nfev;
static struct { void *p; unsigned total, line; const char *file; } ai[MAXEV];
static void *fev[MAXEV];

void *_calloc (uint32_t n, uint32_t s, const char *file, uint32_t line)
{
	unsigned total = (unsigned)(n * s);
	void *p;
	used = (used + 7u) & ~7u;
	p = arena + used;
	if (used + total > ARENA) return 0;
	memset (p, 0, total);
	used += total;
	if (nai < MAXEV)
		ai[nai].p = p, ai[nai].total = total, ai[nai].file = file, ai[nai].line = line, nai++;
	return p;
}
void *_malloc (uint32_t size, const char *file, uint32_t line)
{
	void *p;
	used = (used + 7u) & ~7u;
	p = arena + used;
	if (used + size > ARENA) return 0;
	used += size;
	if (nai < MAXEV)
		ai[nai].p = p, ai[nai].total = size, ai[nai].file = file, ai[nai].line = line, nai++;
	return p;
}
void _free (void *p)
{
	if (nfev < MAXEV) fev[nfev++] = p;
}

/* ---- fake atlas / loader ------------------------------------------------ */

static spAtlasRegion ra, rb, rc;
static spAtlas atlas;
static spAttachmentLoaderVtable vt;
static spAttachmentLoader loader;
static int skin_dummy;
static int cfg_calls, dis_calls;

static void on_cfg (spAttachmentLoader *l, spAttachment *a) { (void)l, (void)a; cfg_calls++; }
static void on_dis (spAttachmentLoader *l, spAttachment *a) { (void)l, (void)a; dis_calls++; }
static void on_loader_dispose (spAttachmentLoader *l) { (void)l; }

static void reset_events (void) { nai = 0; nfev = 0; }


static void __attribute__((unused)) run (void)
{
	spAttachment *a;
	spRegionAttachment *raa;
	spMeshAttachment *ma;

	ra.name = "region_a"; ra.width = 32; ra.height = 16;
	ra.u = 0.125f; ra.v = 0.25f; ra.u2 = 0.375f; ra.v2 = 0.5f;
	ra.offsetX = 3; ra.offsetY = 4; ra.originalWidth = 40; ra.originalHeight = 20;
	ra.rotate = 0; ra.next = &rb;
	rb.name = "region_b"; rb.width = 64; rb.height = 48;
	rb.u = 0.5f; rb.v = 0.5f; rb.u2 = 1.0f; rb.v2 = 1.0f;
	rb.offsetX = 7; rb.offsetY = 8; rb.originalWidth = 80; rb.originalHeight = 60;
	rb.rotate = 0; rb.next = &rc;
	rc.name = "region_c"; rc.width = 8; rc.height = 4;
	rc.u = 0.1f; rc.v = 0.2f; rc.u2 = 0.3f; rc.v2 = 0.4f;
	rc.offsetX = 1; rc.offsetY = 2; rc.originalWidth = 9; rc.originalHeight = 5;
	rc.rotate = 1; rc.next = 0;
	atlas.pages = 0; atlas.regions = &ra; atlas.renderer = 0;

	vt.createAttachment = _spAtlasAttachmentLoader_createAttachment;
	vt.configureAttachment = on_cfg;
	vt.disposeAttachment = on_dis;
	vt.dispose = on_loader_dispose;
	loader.error1 = 0; loader.error2 = 0; loader.vtable = &vt; loader.atlas = &atlas;

	/* type 0, exact name, non-rotated UV order */
	reset_events ();
	a = spAttachmentLoader_createAttachment (&loader, (spSkin *)&skin_dummy, 0,
	                                         "hero_head", "region_a");
	ck (a != 0 && a->type == 0 && same (a->name, "hero_head"), "type 0 -> region attachment");
	ck ((uintptr_t)a->name >= (uintptr_t)arena &&
	    (uintptr_t)a->name < (uintptr_t)arena + used,
	    "attachment name is an owned arena copy");
	raa = (spRegionAttachment *)a;
	ck (raa->region == &ra, "region pointer at +0x40");
	ck (raa->scaleX == 1.0f && raa->scaleY == 1.0f && raa->r == 1.0f && raa->a == 1.0f,
	    "constructor sets scale/colour to 1.0f");
	ck (raa->regionOffsetX == 3 && raa->regionOffsetY == 4 &&
	    raa->regionWidth == 32 && raa->regionHeight == 16 &&
	    raa->regionOriginalWidth == 40 && raa->regionOriginalHeight == 20,
	    "region geometry copied to +0x44..+0x58");
	ck (raa->uvs[0] == 0.125f && raa->uvs[1] == 0.5f && raa->uvs[2] == 0.125f &&
	    raa->uvs[3] == 0.25f && raa->uvs[4] == 0.375f && raa->uvs[5] == 0.25f &&
	    raa->uvs[6] == 0.375f && raa->uvs[7] == 0.5f, "non-rotated UV order");
	ck (nai >= 3 && ai[0].line == 43 && same (ai[0].file, SP_FILE_REGION) &&
	    ai[0].total == 0x9c && ai[1].line == 43 && same (ai[1].file, SP_FILE_ATTACHMENT) &&
	    ai[2].line == 46 && same (ai[2].file, SP_FILE_ATTACHMENT),
	    "region calloc/line 43 + vtable 43 + name malloc 46");
	ck (loader.error1 == 0 && loader.error2 == 0, "successful call leaves errors NULL");
	spAttachment_dispose (a);
	ck (dis_calls == 0, "region attachment has no loader slot -> disposeAttachment not called");

	/* type 0, missing region */
	reset_events ();
	a = spAttachmentLoader_createAttachment (&loader, (spSkin *)&skin_dummy, 0, "x", "nope");
	ck (a == 0, "missing region returns NULL");
	ck (loader.error1 != 0 && same (loader.error1, "Region not found: ") &&
	    loader.error2 != 0 && same (loader.error2, "nope"), "missing-region error pair");
	ck (nai == 2 && ai[0].line == 91 && ai[1].line == 92 &&
	    same (ai[0].file, SP_FILE_ATTACHMENT_LOADER), "setError malloc lines 91/92");

	/* type 1 bounding box + loader disposeAttachment hook */
	reset_events ();
	a = spAttachmentLoader_createAttachment (&loader, (spSkin *)&skin_dummy, 1, "bb", "ignored");
	ck (a != 0 && a->type == 1, "type 1 -> bounding box (type 1)");
	ck (loader.error1 == 0 && loader.error2 == 0,
	    "createAttachment clears the previous error pair before dispatch");
	ck (nai == 3 && ai[1].line == 43 && same (ai[1].file, SP_FILE_ATTACHMENT),
	    "bbox init vtable line 43");
	ck (ai[0].line == 44 && ai[0].total == 0x24 && same (ai[0].file, SP_FILE_BBOX),
	    "bbox calloc 0x24 line 44");
	a->loader = &loader; /* body outside this closure normally wires this */
	dis_calls = 0;
	spAttachment_dispose (a);
	ck (dis_calls == 1, "_spAttachment_deinit dispatches loader+0x08 when +0x0c != 0");

	/* type 2 mesh, basename fallback */
	reset_events ();
	a = spAttachmentLoader_createAttachment (&loader, (spSkin *)&skin_dummy, 2,
	                                         "mesh", "art/dir/region_b");
	ck (a != 0 && a->type == 2, "type 2 -> mesh (type 2)");
	ma = (spMeshAttachment *)a;
	ck (ma->region == &rb && ma->regionOffsetX == 7 && ma->regionWidth == 64 &&
	    ma->regionOriginalHeight == 60, "mesh copies region geometry");
	ck (ma->u == 0.5f && ma->v == 0.5f && ma->u2 == 1.0f && ma->v2 == 1.0f &&
	    ma->rotate == 0, "mesh copies UVs/rotate");
	ck (ma->r == 1.0f && ma->g == 1.0f && ma->b == 1.0f && ma->a == 1.0f,
	    "mesh constructor sets colour to 1.0f");
	ck (ai[0].line == 50 && ai[0].total == 0x94 && same (ai[0].file, SP_FILE_MESH),
	    "mesh calloc 0x94 line 50");
	spAttachment_dispose (a);

	/* type 3 linked mesh takes the same branch / constructor type 2 */
	reset_events ();
	a = spAttachmentLoader_createAttachment (&loader, (spSkin *)&skin_dummy, 3,
	                                         "linked", "region_b");
	ck (a != 0 && a->type == 2 && ((spMeshAttachment *)a)->region == &rb,
	    "type 3 -> mesh branch, constructor type 2");
	spAttachment_dispose (a);

	/* type 4 path */
	reset_events ();
	a = spAttachmentLoader_createAttachment (&loader, (spSkin *)&skin_dummy, 4, "path", "ignored");
	ck (a != 0 && a->type == 4, "type 4 -> path (type 4)");
	ck (ai[0].line == 45 && ai[0].total == 0x34 && same (ai[0].file, SP_FILE_PATH),
	    "path calloc 0x34 line 45");
	spAttachment_dispose (a);

	/* rotated UV order (region_c) */
	reset_events ();
	a = spAttachmentLoader_createAttachment (&loader, (spSkin *)&skin_dummy, 0, "r", "dir/region_c");
	raa = (spRegionAttachment *)a;
	ck (raa->region == &rc && raa->uvs[0] == 0.3f && raa->uvs[1] == 0.4f &&
	    raa->uvs[2] == 0.1f && raa->uvs[3] == 0.4f && raa->uvs[4] == 0.1f &&
	    raa->uvs[5] == 0.2f && raa->uvs[6] == 0.3f && raa->uvs[7] == 0.2f,
	    "rotated UV order");
	spAttachment_dispose (a);

	/* default: type 5 and negative type */
	reset_events ();
	a = spAttachmentLoader_createAttachment (&loader, (spSkin *)&skin_dummy, 5, "x", "p");
	ck (a == 0 && same (loader.error1, "Unknown attachment type: ") &&
	    same (loader.error2, "5"), "type 5 -> unknown-type error");
	ck (nai == 2 && ai[0].line == 91 && ai[1].line == 92, "unknown-type setError lines");
	a = spAttachmentLoader_createAttachment (&loader, (spSkin *)&skin_dummy, -1, "x", "p");
	ck (a == 0 && same (loader.error2, "-1"), "negative type -> unknown-type error");
	a = spAttachmentLoader_createAttachment (&loader, (spSkin *)&skin_dummy,
	                                         (int32_t)0x80000000u, "x", "p");
	ck (a == 0 && same (loader.error2, "-2147483648"), "minimum int32 type preserves full decimal");

	/* Compare raw float representations, not IEEE == (NaN/negative zero). */
	{
		spRegionAttachment uv;
		union { uint32_t u; float f; } u, v, u2, v2, observed;
		u.u=0x80000000u; v.u=0x7fc12345u; u2.u=0x7f800000u; v2.u=0xff800000u;
		const uint32_t normal[8]={u.u,v2.u,u.u,v.u,u2.u,v.u,u2.u,v2.u};
		const uint32_t rotated[8]={u2.u,v2.u,u.u,v2.u,u.u,v.u,u2.u,v.u};
		int ok=1;
		spRegionAttachment_setUVs(&uv,u.f,v.f,u2.f,v2.f,0);
		for(unsigned i=0;i<8;++i){observed.f=uv.uvs[i];if(observed.u!=normal[i])ok=0;}
		ck(ok,"UV nonfinite/negative-zero raw bits normal");
		ok=1;spRegionAttachment_setUVs(&uv,u.f,v.f,u2.f,v2.f,-1);
		for(unsigned i=0;i<8;++i){observed.f=uv.uvs[i];if(observed.u!=rotated[i])ok=0;}
		ck(ok,"UV nonfinite/negative-zero raw bits rotated");
	}

	/* forwarding wrappers: configure NULL and non-NULL; dispose NULL. */
	cfg_calls = 0;
	loader.vtable->configureAttachment = 0;
	spAttachmentLoader_configureAttachment (&loader, 0);
	ck (cfg_calls == 0, "configureAttachment NULL slot is a no-op");
	loader.vtable->configureAttachment = on_cfg;
	spAttachmentLoader_configureAttachment (&loader, 0);
	ck (cfg_calls == 1, "configureAttachment non-NULL slot is called");

	/* spAttachment_dispose on a manually built attachment: vtable dispose only */
	{
		spAttachmentVtable av;
		spBoundingBoxAttachment one;
		memset (&one, 0, sizeof one);
		spAttachment *base = &one.super.super;
		av.dispose = _spBoundingBoxAttachment_dispose;
		base->name = (char *)"n"; base->type = 1; base->vtable = &av; base->loader = 0;
		dis_calls = 0;
		spAttachment_dispose (base);
		ck (dis_calls == 0, "dispose uses attachment vtable, not loader");
	}
}

#ifdef FACTORY_FRAME_PROBE
static uintptr_t frame_lr;
static spAttachmentLoader *frame_loader;
static spAttachment *frame_attachment;
static unsigned frame_bad_args;
static void __attribute__((noinline)) frame_callback(spAttachmentLoader *l,spAttachment *a)
{
    frame_lr=(uintptr_t)__builtin_return_address(0);
    frame_bad_args=l!=frame_loader || a!=frame_attachment;
}
static void frame_probe(void)
{
    spAttachmentLoaderVtable vt={0};spAttachmentLoader l={0};spAttachment a={0};
    l.vtable=&vt;vt.disposeAttachment=frame_callback;
    frame_loader=&l;frame_attachment=&a;
    spAttachmentLoader_disposeAttachment(&l,&a);
    char line[13]="LR=00000000\n";const char *digits="0123456789abcdef";
    for(unsigned i=0;i<8;++i)line[3+i]=digits[(frame_lr>>(28u-4u*i))&15u];
    out(line);
    sys_exit(frame_bad_args || fails ? 1 : 0);
}
#endif

void _start (void)
{
#ifdef FACTORY_FRAME_PROBE
    frame_probe();
#elif defined(FACTORY_GUARD_NEGATIVE)
	_spAttachmentLoader_setUnknownTypeError(&loader,7);
	sys_exit(fails ? 98 : 99); /* wrong: canary changed but failure path did not execute */
#else
	run ();
	out (fails ? "FAILURES\n" : "all checks passed\n");
	sys_exit (fails ? 1 : 0);
#endif
}
