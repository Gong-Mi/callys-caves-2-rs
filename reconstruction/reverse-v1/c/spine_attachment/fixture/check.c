/* fixture.c — self-check for the four recovered entry points (qemu-arm).
 * _calloc/_free/_spAtlasAttachmentLoader_createAttachment below are recording
 * test providers; the last is a link stub only and must never be reached. */

#include "../src/spine_attachment.h"

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
	while (s[n])
		n++;
	sys_write (1, s, n);
}
static int same (const char *a, const char *b)
{
	while (*a && *a == *b)
		a++, b++;
	return *a == *b;
}
static unsigned fails;
static void ck (int ok, const char *what)
{
	out (ok ? "ok   " : "FAIL "), out (what), out ("\n");
	fails += !ok;
}

#define ARENA 512
#define MAXEV 12
static unsigned char arena[ARENA];
static unsigned used, nai, nfev;
static struct { void *p; unsigned total, line; const char *file; } ai[MAXEV];
static void *fev[MAXEV];
static spAttachmentLoader *live;
static int mutate;

void *_calloc (uint32_t n, uint32_t s, const char *file, uint32_t line)
{
	unsigned total = (unsigned) (n * s), i;
	void *p = arena + used;

	if (used + total > ARENA)
		return 0;
	for (i = 0; i < total; i++)
		((unsigned char *) p)[i] = 0;
	used += total;
	if (nai < MAXEV)
		ai[nai].p = p, ai[nai].total = total, ai[nai].file = file, ai[nai].line = line, nai++;
	return p;
}

void _free (void *p)
{
	if (nfev < MAXEV)
		fev[nfev++] = p;
	if (mutate && p == (void *) 0xaa00)
		live->error2 = (char *) 0xcc00;
}

static int stub_calls;
spAttachment *_spAtlasAttachmentLoader_createAttachment (spAttachmentLoader *l, spSkin *s,
                                                         int32_t t, const char *n, const char *p)
{
	(void) l, (void) s, (void) t, (void) n, (void) p;
	stub_calls++;
	return 0;
}
static int d_calls, c_calls;
static spAttachment *t_create (spAttachmentLoader *l, spSkin *s, int32_t t, const char *n,
                               const char *p)
{
	(void) l, (void) s, (void) t, (void) n, (void) p;
	c_calls++;
	return 0;
}
static void t_conf (spAttachmentLoader *l, spAttachment *a) { (void) l, (void) a; }
static void t_dispo (spAttachmentLoader *l, spAttachment *a) { (void) l, (void) a; }
static void t_dispose (spAttachmentLoader *l) { (void) l; d_calls++; }

static unsigned char atlas_storage;
static spAtlas *atlas_obj = (spAtlas *) &atlas_storage;

static void run (void)
{
	spAttachmentLoader *ld = spAtlasAttachmentLoader_create (atlas_obj);
	spAttachmentLoader s, r;
	spAttachmentLoaderVtable *vt, *block;

	ck (nai == 2 && ai[0].total == 16 && ai[1].total == 16, "two 16 B callocs");
	ck (ai[0].line == 93 &&
	    same (ai[0].file, "jni/../jni/yoyo/../../../spine-c/src/spine/AtlasAttachmentLoader.c"),
	    "create calloc line 93 / AtlasAttachmentLoader.c");
	ck (ai[1].line == 51 &&
	    same (ai[1].file, "jni/../jni/yoyo/../../../spine-c/src/spine/AttachmentLoader.c"),
	    "init calloc line 51 / AttachmentLoader.c");
	ck (ld == ai[0].p && ld->vtable == ai[1].p, "loader = calloc1, loader+8 = calloc2");
	ck (ld->atlas == atlas_obj && ld->error1 == 0 && ld->error2 == 0,
	    "atlas at +0xc, error fields calloc-zeroed");
	vt = ld->vtable;
	ck (vt->dispose == _spAttachmentLoader_deinit, "slot +0x0c = deinit");
	ck (vt->createAttachment == _spAtlasAttachmentLoader_createAttachment, "slot +0x00 = create");
	ck (vt->configureAttachment == 0 && vt->disposeAttachment == 0, "slots +0x04/+0x08 NULL");
	ck (stub_calls == 0, "create attachment body not dispatched");

	s.error1 = (char *) 0x1234, s.error2 = (char *) 0x5678, s.vtable = 0;
	s.atlas = (spAtlas *) 0x9abc;
	_spAttachmentLoader_init (&s, t_dispose, t_create, t_conf, t_dispo);
	vt = s.vtable;
	ck (vt && vt->createAttachment == t_create && vt->configureAttachment == t_conf &&
	    vt->disposeAttachment == t_dispo && vt->dispose == t_dispose, "init slot map");
	ck (s.error1 == (char *) 0x1234 && s.error2 == (char *) 0x5678 &&
	    s.atlas == (spAtlas *) 0x9abc, "init leaves +0x00/+0x04/+0x0c alone");

	nfev = 0;
	spAttachmentLoader_dispose (&s);
	ck (d_calls == 1 && c_calls == 0, "dispose dispatches vtable+0x0c only");
	ck (nfev == 1 && fev[0] == &s, "dispose frees the loader itself after the callback");

	block = ld->vtable;
	ld->error1 = (char *) 0x1111, ld->error2 = (char *) 0x2222;
	nfev = 0;
	spAttachmentLoader_dispose (ld);
	ck (nfev == 4 && fev[0] == block && fev[1] == (void *) 0x1111 &&
	    fev[2] == (void *) 0x2222 && fev[3] == ld,
	    "deinit order +0x08, +0x00, +0x04 then free(loader)");

	r.error1 = (char *) 0xaa00, r.error2 = (char *) 0xbb00, r.vtable = 0, r.atlas = 0;
	_spAttachmentLoader_init (&r, t_dispose, t_create, 0, 0);
	live = &r, mutate = 1, nfev = 0;
	_spAttachmentLoader_deinit (&r);
	mutate = 0;
	ck (nfev == 3 && fev[1] == (void *) 0xaa00 && fev[2] == (void *) 0xcc00,
	    "error2 re-read after the error1 free (0xbb00 -> 0xcc00)");
}

void _start (void)
{
	run ();
	out (fails ? "FAILURES\n" : "all checks passed\n");
	sys_exit (fails ? 1 : 0);
}