/*
 * spine_mesh.c — literal ARM32 C transcription of
 *
 *   spMeshAttachment_updateUVs      0x287538..0x28764c  276 B code / 69 insns + 4 B pool
 *   spMeshAttachment_setParentMesh  0x287654..0x2876d0  128 B  32 insns
 *
 * of libyoyo_armv7.so
 *   sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * tier: bytecode_anchored.  No original machine code is executed here and no
 * equivalence with the original runtime is claimed.  Every VFP operation is a
 * separate minimal inline-asm instruction so that the target instruction kind
 * survives compilation: VFPv3 VMLA/VMLS round the product before the add /
 * subtract (they are NOT fused VFMA/VFMS), even when the tree is built with
 * -ffp-contract=off, and VADD's operand order (height + v) is preserved.
 *
 * Two snapshot layers in updateUVs, both observable through the replaceable
 * allocator callbacks:
 *   before _free : worldVerticesLength, u, v, u2, v2 (and old +0x5c pointer)
 *   after _malloc: rotate, +0x58, and u/v are re-read on every iteration.
 * The source pair is never cached as a pair: a provider may return a buffer
 * that overlaps +0x58, so the second source load must happen after the first
 * output store.  No restrict qualification is used anywhere.
 *
 * No NULL guards, no error returns, no bounds checks are added: the original
 * has none.
 */

#include "spine_mesh.h"

/* .rodata 0x357908, byte-exact, including the leading "jni/../jni/yoyo/../..". */
static const char sp_mesh_tag[] =
	"jni/../jni/yoyo/../../../spine-c/src/spine/MeshAttachment.c";

#define SP_AI static inline __attribute__ ((always_inline))

/* ARM32 add semantics: the low 32 bits of base + byte_off, no UB. */
SP_AI const void *sp_src_at (const void *base, uint32_t byte_off)
{
	return (const void *)(uintptr_t)((uint32_t)(uintptr_t)base + byte_off);
}

SP_AI void *sp_dst_at (void *base, uint32_t byte_off)
{
	return (void *)(uintptr_t)((uint32_t)(uintptr_t)base + byte_off);
}

SP_AI int32_t sp_s32 (uint32_t v)
{
	int32_t r;
	__builtin_memcpy (&r, &v, 4);
	return r;
}

/* ---- minimal VFP primitives: one target instruction each ---------------- */

SP_AI float sp_vldr (const void *p)
{
	float f;
	__asm__ volatile ("vldr %0, [%1]" : "=t"(f) : "r"(p) : "memory");
	return f;
}

SP_AI void sp_vstr (void *p, float f)
{
	__asm__ volatile ("vstr %0, [%1]" : : "t"(f), "r"(p) : "memory");
}

SP_AI float sp_vsub (float a, float b)
{
	float r;
	__asm__ volatile ("vsub.f32 %0, %1, %2" : "=t"(r) : "t"(a), "t"(b) : "memory");
	return r;
}

/* VFPv3 VMLA: rounded product, then rounded sum; not a fused FMA. */
SP_AI float sp_vmla (float acc, float a, float b)
{
	__asm__ volatile ("vmla.f32 %0, %1, %2" : "+t"(acc) : "t"(a), "t"(b) : "memory");
	return acc;
}

/* s15 = s16 + s15 ; operand order matters for NaN payload propagation. */
SP_AI float sp_vadd (float a, float b)
{
	float r;
	__asm__ volatile ("vadd.f32 %0, %1, %2" : "=t"(r) : "t"(a), "t"(b) : "memory");
	return r;
}

/* VFPv3 VMLS: rounded product, then rounded difference; not fused. */
SP_AI float sp_vmls (float acc, float a, float b)
{
	__asm__ volatile ("vmls.f32 %0, %1, %2" : "+t"(acc) : "t"(a), "t"(b) : "memory");
	return acc;
}

/* vmov r1, s15 : bit copy, no conversion, no FPSCR effect. */
SP_AI uint32_t sp_vmov_bits (float f)
{
	uint32_t r;
	__asm__ volatile ("vmov %0, %1" : "=r"(r) : "t"(f) : "memory");
	return r;
}

/* str r1, [r0] : the second UV component is stored from a core register. */
SP_AI void sp_str_u32 (void *p, uint32_t v)
{
	__asm__ volatile ("str %1, [%0]" : : "r"(p), "r"(v) : "memory");
}

/* ------------------------------------------------------------------------ */
/* 0x287538  spMeshAttachment_updateUVs                                      */
/* ABI: void f(spMeshAttachment *self, r0).  r0 undefined on return.         */
/* ------------------------------------------------------------------------ */
void spMeshAttachment_updateUVs (spMeshAttachment *self)
{
	/* 0x28753c..0x287560 — first snapshot, all BEFORE the free callback.
	 * Load order follows the original instruction order. */
	float u   = sp_vldr (&self->u);                          /* 0x28753c */
	uint32_t word_count = self->super.worldVerticesLength;   /* 0x287548 */
	float u2  = sp_vldr (&self->u2);                         /* 0x28754c */
	void *old_uvs = self->owned_5c;                          /* 0x287550 */
	float v2  = sp_vldr (&self->v2);                         /* 0x287554 */
	float width = sp_vsub (u2, u);                           /* 0x287558 */
	float v   = sp_vldr (&self->v);                          /* 0x28755c */
	float height = sp_vsub (v2, v);                          /* 0x287560 */
	int32_t count = sp_s32 (word_count);                     /* cmp r5,#0 */

	_free (old_uvs);                                         /* 0x287564 */

	/* 0x287568 ldr r1,[pc,#0xdc] -> 0x28764c ; 0x287574 add r1,pc,r1
	 * -> .rodata 0x357908.  Size is lsl r0,r5,#2 (32-bit wrap), line 64. */
	float *uvs = (float *)_malloc (word_count << 2, sp_mesh_tag, 64u);
	                                                         /* 0x287578 */

	/* 0x28757c ldr r3,[r4,#0x50] AFTER the allocator; 0x287584 stores the
	 * new pointer before the rotate branch is taken. */
	int32_t rotate = self->rotate;
	self->owned_5c = uvs;

	if (rotate == 0) {
		/* ---- unrotated: u + (u2-u)*src[2i], v + (v2-v)*src[2i+1] ---- */
		if (count > 0) {                                 /* 0x28758c/590 */
			const void *src = self->owned_58;         /* 0x287598, after malloc */
			uint32_t pairs = ((uint32_t)count - 1u) >> 1; /* 0x2875a0 */
			uint32_t i = 0;

			for (;;) {
				/* 0x2875b0 vldr s14,[r3,#-4] ; 0x2875b4 reload u ;
				 * 0x2875b8 vmla ; 0x2875c8 vstr output-u. */
				float x = sp_vldr (sp_src_at (src, i << 3));
				float out_u = sp_vldr (&self->u);
				out_u = sp_vmla (out_u, width, x);
				sp_vstr (sp_dst_at (uvs, i << 3), out_u);

				/* 0x2875cc source-v is loaded AFTER the output-u store
				 * (an overlapping provider buffer makes this visible). */
				float y = sp_vldr (sp_src_at (src, (i << 3) + 4u));
				float out_v = sp_vldr (&self->v);
				out_v = sp_vmla (out_v, height, y);
				sp_str_u32 (sp_dst_at (uvs, (i << 3) + 4u),
				            sp_vmov_bits (out_v));

				if ((i << 3) == (pairs << 3)) break;             /* 0x2875e0 bne */
				++i;
			}
		}
		return;                                          /* 0x2875e4/5e8 */
	}

	/* ---- rotated: u + (u2-u)*src[2i+1], (v + (v2-v)) - (v2-v)*src[2i] -- */
	if (count > 0) {                                     /* 0x2875ec/5f0 */
		const void *src = self->owned_58;             /* 0x2875f8 */
		uint32_t pairs = ((uint32_t)count - 1u) >> 1; /* 0x287600 */
		uint32_t i = 0;

		for (;;) {
			/* 0x287610 vldr s14,[r3] ; 0x287614 reload u ; vmla ;
			 * 0x287620 vstr output-u. */
			float sv = sp_vldr (sp_src_at (src, (i << 3) + 4u));
			float out_u = sp_vldr (&self->u);
			out_u = sp_vmla (out_u, width, sv);
			sp_vstr (sp_dst_at (uvs, i << 3), out_u);

			/* 0x287624 vldr s15,[r4,#68] (base v, re-read) ;
			 * 0x287628 vadd.f32 s15,s16,s15 -> height + v ;
			 * 0x28762c vldr s14,[r3,#-12] (source-u, AFTER the store) ;
			 * 0x287634 vmls.f32 s15,s16,s14 -> out - height*src-u. */
			float base_v = sp_vldr (&self->v);
			float out_v = sp_vadd (height, base_v);
			float su = sp_vldr (sp_src_at (src, i << 3));
			out_v = sp_vmls (out_v, height, su);
			sp_str_u32 (sp_dst_at (uvs, (i << 3) + 4u),
			            sp_vmov_bits (out_v));

			if ((i << 3) == (pairs << 3)) break;                 /* 0x287640 bne */
			++i;
		}
	}
}                                                        /* 0x287644/648 */

/* ------------------------------------------------------------------------ */
/* 0x287654  spMeshAttachment_setParentMesh                                  */
/* ABI: void f(spMeshAttachment *self, spMeshAttachment *parentMesh).        */
/* The back-edge store to +0x7c happens BEFORE the NULL test.                */
/* ------------------------------------------------------------------------ */
void spMeshAttachment_setParentMesh (spMeshAttachment *self,
                                     spMeshAttachment *parentMesh)
{
	/* 0x287654 cmp r1,#0 ; 0x287658 str r1,[r0,#0x7c] */
	self->parentMesh = parentMesh;
	if (parentMesh == 0) return;                     /* 0x287660 beq */

	/* 0x287664..0x287694 — thirteen parent loads, all before the first
	 * store into self.  Shares the parent's arrays; no copy, no free. */
	uint32_t p_20 = parentMesh->super.worldVerticesLength; /* 0x287664 */
	float    p_8c = sp_vldr (&parentMesh->opaque_8c);      /* 0x287668 */
	void    *p_14 = parentMesh->super.owned_14;            /* 0x28766c */
	float    p_90 = sp_vldr (&parentMesh->opaque_90);      /* 0x287670 */
	uint32_t p_10 = parentMesh->super.opaque_10;           /* 0x287674 */
	void    *p_1c = parentMesh->super.owned_1c;            /* 0x287678 */
	uint32_t p_18 = parentMesh->super.opaque_18;           /* 0x28767c */
	void    *p_58 = parentMesh->owned_58;                  /* 0x287680 */
	void    *p_64 = parentMesh->owned_64;                  /* 0x287684 */
	uint32_t p_60 = parentMesh->opaque_60;                 /* 0x287688 */
	uint32_t p_78 = parentMesh->opaque_78;                 /* 0x28768c */
	void    *p_88 = parentMesh->owned_88;                  /* 0x287690 */
	uint32_t p_84 = parentMesh->opaque_84;                 /* 0x287694 */

	/* 0x287698..0x2876c8 — store order is the original order, not the
	 * load order.  The two float slots use vstr. */
	sp_vstr (&self->opaque_8c, p_8c);                      /* 0x287698 */
	self->super.worldVerticesLength = p_20;                /* 0x28769c */
	sp_vstr (&self->opaque_90, p_90);                      /* 0x2876a0 */
	self->super.owned_14 = p_14;                           /* 0x2876a4 */
	self->super.opaque_10 = p_10;                          /* 0x2876a8 */
	self->super.owned_1c = p_1c;                           /* 0x2876ac */
	self->super.opaque_18 = p_18;                          /* 0x2876b0 */
	self->owned_58 = p_58;                                 /* 0x2876b4 */
	self->owned_64 = p_64;                                 /* 0x2876b8 */
	self->opaque_60 = p_60;                                /* 0x2876bc */
	self->opaque_78 = p_78;                                /* 0x2876c0 */
	self->owned_88 = p_88;                                 /* 0x2876c4 */
	self->opaque_84 = p_84;                                /* 0x2876c8 */
}                                                          /* 0x2876cc/6d0 */
