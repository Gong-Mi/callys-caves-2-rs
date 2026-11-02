/*
 * spine_atlas_create.h - static ARM32 reconstruction of libyoyo's atlas loader.
 *
 * Original image:
 *   /data/data/com.termux/files/home/callys-caves-2-rs/reconstruction/live-mem/libyoyo_armv7.so
 *   sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Recovered entry points (all STB_GLOBAL / STV_DEFAULT FUNC in .dynsym):
 *   spAtlas_create        0x284174  1824 B  body sha256 a6cf2776...
 *   spAtlasPage_create    0x284058    96 B  body sha256 b3090dcc...
 *   spAtlasRegion_create  0x2840d8    28 B  body sha256 339c4207...
 *
 * Direct dependencies left as named boundaries (bodies NOT recovered here):
 *   spAtlas_dispose               0x284120   84 B  (recovered in main tree)
 *   _spAtlasPage_createTexture    0xbd6e4   304 B  (graphics side, open)
 *   _malloc/_calloc/_free         0x285c10 / 0x285c4c / 0x285c80 (spine_alloc.h)
 *
 * Layout facts are pinned by the machine code, not by an upstream release:
 *   spAtlas        12 B  calloc(1,12)  0x2841d0, renderer store 0x284230
 *   spAtlasPage    44 B  calloc(1,44)  0x28406c; next at +0x28 (0x2846e4)
 *   spAtlasRegion  80 B  calloc(1,80)  0x2840e0; next at +0x4c (0x28428c)
 *
 * Canonical full ARM32 definitions shared by parser and attachment factory.
 * Partial per-consumer structures are not compatible C declarations.
 * Host-size adaptation is intentionally not part of this native header.
 */
#ifndef YY_SPINE_ATLAS_LAYOUT_H
#define YY_SPINE_ATLAS_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

#define YY_ATLAS_SRC_FILE \
    "jni/../jni/yoyo/../../../spine-c/src/spine/Atlas.c"

#define SPATLAS_PAGES_OFF     0x00u
#define SPATLAS_REGIONS_OFF   0x04u
#define SPATLAS_RENDERER_OFF  0x08u
#define SPATLAS_SIZE          12u

#define SPATPAGE_ATLAS_OFF    0x00u
#define SPATPAGE_NAME_OFF     0x04u
#define SPATPAGE_FORMAT_OFF   0x08u
#define SPATPAGE_MINFILTER_OFF 0x0cu
#define SPATPAGE_MAGFILTER_OFF 0x10u
#define SPATPAGE_UWRAP_OFF    0x14u
#define SPATPAGE_VWRAP_OFF    0x18u
#define SPATPAGE_TEXTURE_OFF  0x1cu
#define SPATPAGE_WIDTH_OFF    0x20u
#define SPATPAGE_HEIGHT_OFF   0x24u
#define SPATPAGE_NEXT_OFF     0x28u
#define SPATPAGE_SIZE         44u

#define SPATREGION_NAME_OFF       0x00u
#define SPATREGION_X_OFF          0x04u
#define SPATREGION_Y_OFF          0x08u
#define SPATREGION_WIDTH_OFF      0x0cu
#define SPATREGION_HEIGHT_OFF     0x10u
#define SPATREGION_U_OFF          0x14u
#define SPATREGION_V_OFF          0x18u
#define SPATREGION_U2_OFF         0x1cu
#define SPATREGION_V2_OFF         0x20u
#define SPATREGION_OFFSETX_OFF    0x24u
#define SPATREGION_OFFSETY_OFF    0x28u
#define SPATREGION_ORIGW_OFF      0x2cu
#define SPATREGION_ORIGH_OFF      0x30u
#define SPATREGION_INDEX_OFF      0x34u
#define SPATREGION_ROTATE_OFF     0x38u
#define SPATREGION_3C_OFF         0x3cu
#define SPATREGION_SPLITS_OFF     0x40u
#define SPATREGION_PADS_OFF       0x44u
#define SPATREGION_PAGE_OFF       0x48u
#define SPATREGION_NEXT_OFF       0x4cu
#define SPATREGION_SIZE           80u

/* Values are the table indices returned by indexOf() over the two 8-entry
 * pointer tables at original VAs 0x3f7750 (format) and 0x3f7770 (filter).
 * Index 0 is the empty string, hence the explicit UNKNOWN members. */
typedef enum spAtlasFormat {
    SP_ATLAS_UNKNOWN_FORMAT = 0,
    SP_ATLAS_ALPHA,
    SP_ATLAS_INTENSITY,
    SP_ATLAS_LUMINANCE_ALPHA,
    SP_ATLAS_RGB565,
    SP_ATLAS_RGBA4444,
    SP_ATLAS_RGB888,
    SP_ATLAS_RGBA8888
} spAtlasFormat;

typedef enum spAtlasFilter {
    SP_ATLAS_UNKNOWN_FILTER = 0,
    SP_ATLAS_NEAREST,
    SP_ATLAS_LINEAR,
    SP_ATLAS_MIPMAP,
    SP_ATLAS_MIPMAP_NEAREST_NEAREST,
    SP_ATLAS_MIPMAP_LINEAR_NEAREST,
    SP_ATLAS_MIPMAP_NEAREST_LINEAR,
    SP_ATLAS_MIPMAP_LINEAR_LINEAR
} spAtlasFilter;

/* 0x284778/0x284780 write 1, 0x2847b8/0x2847bc write 2. */
typedef enum spAtlasWrap {
    SP_ATLAS_WRAP_ZERO_UNCLASSIFIED = 0,
    SP_ATLAS_CLAMPTOEDGE = 1,
    SP_ATLAS_REPEAT = 2
} spAtlasWrap;

typedef struct spAtlas spAtlas;
typedef struct spAtlasPage spAtlasPage;
typedef struct spAtlasRegion spAtlasRegion;

struct spAtlas {
    spAtlasPage* pages;        /* +0x00  0x2846ec first page store */
    spAtlasRegion* regions;    /* +0x04  0x284294 first region store */
    void* renderer;            /* +0x08  0x284230 caller's 4th argument */
};

struct spAtlasPage {
    spAtlas* atlas;            /* +0x00  0x284084 (param 0 of create) */
    char* name;                /* +0x04  0x2840a4 strdup'ed name */
    spAtlasFormat format;      /* +0x08  0x284718 */
    spAtlasFilter minFilter;   /* +0x0c  0x28473c */
    spAtlasFilter magFilter;   /* +0x10  0x284750 */
    spAtlasWrap uWrap;         /* +0x14  0x284778 / 0x2847b8 / 0x284860 */
    spAtlasWrap vWrap;         /* +0x18  0x284780 / 0x2847bc / 0x284870 */
    int32_t texture_id;      /* +0x1c  written by _spAtlasPage_createTexture;
                                *        read as int id by 0xbd814 */
    int width;                 /* +0x20  0x2847f4 */
    int height;                /* +0x24  0x284808 */
    spAtlasPage* next;         /* +0x28  0x2846e4 */
};

struct spAtlasRegion {
    char* name;                /* +0x00  0x2842ac */
    int x;                     /* +0x04  0x28431c */
    int y;                     /* +0x08  0x284330 */
    int width;                 /* +0x0c  0x28435c */
    int height;                /* +0x10  0x2843a0 */
    float u;                   /* +0x14  0x2843a8 */
    float v;                   /* +0x18  0x2843ac */
    float u2;                  /* +0x1c  0x2843d8 / 0x2844b0 */
    float v2;                  /* +0x20  0x2843d4 / 0x2844b4 */
    int offsetX;               /* +0x24  0x28444c */
    int offsetY;               /* +0x28  0x284460 */
    int originalWidth;         /* +0x2c  0x284414 */
    int originalHeight;        /* +0x30  0x284428 */
    int index;                 /* +0x34  0x284488 */
    int rotate;                /* +0x38  0x2842e8 */
    int32_t reserved_3c;       /* +0x3c  calloc-zeroed; no reader/writer in the
                                *        three recovered bodies.  Not renamed:
                                *        identity unknown. */
    int* splits;               /* +0x40  0x2844ec _malloc(16) */
    int* pads;                 /* +0x44  0x2845a8 _malloc(16) */
    spAtlasPage* page;         /* +0x48  0x284298 */
    spAtlasRegion* next;       /* +0x4c  0x28428c */
};

#if !defined(__arm__) || defined(__aarch64__)
#error "canonical atlas layout requires ARM32"
#endif
_Static_assert(sizeof(void*) == 4, "yoyo spine atlas is ARM32 only");
_Static_assert(sizeof(int) == 4, "32-bit int required");
_Static_assert(sizeof(float) == 4, "32-bit float required");
_Static_assert(sizeof(spAtlas) == SPATLAS_SIZE, "spAtlas 12B");
_Static_assert(offsetof(spAtlas, pages) == SPATLAS_PAGES_OFF, "atlas pages");
_Static_assert(offsetof(spAtlas, regions) == SPATLAS_REGIONS_OFF, "atlas regions");
_Static_assert(offsetof(spAtlas, renderer) == SPATLAS_RENDERER_OFF, "atlas renderer");
_Static_assert(sizeof(spAtlasPage) == SPATPAGE_SIZE, "spAtlasPage 44B");
_Static_assert(offsetof(spAtlasPage, next) == SPATPAGE_NEXT_OFF, "page next");
_Static_assert(offsetof(spAtlasPage, texture_id) == SPATPAGE_TEXTURE_OFF,
               "page texture id +0x1c");
_Static_assert(sizeof(spAtlasRegion) == SPATREGION_SIZE, "spAtlasRegion 80B");
_Static_assert(offsetof(spAtlasRegion, splits) == SPATREGION_SPLITS_OFF, "splits");
_Static_assert(offsetof(spAtlasRegion, pads) == SPATREGION_PADS_OFF, "pads");
_Static_assert(offsetof(spAtlasRegion, page) == SPATREGION_PAGE_OFF, "page");
_Static_assert(offsetof(spAtlasRegion, next) == SPATREGION_NEXT_OFF, "next");

/* Original allocation widths, not host sizeof substitutions. */
#define YY_ATLAS_ALLOC_ATLAS SPATLAS_SIZE
#define YY_ATLAS_ALLOC_PAGE SPATPAGE_SIZE
#define YY_ATLAS_ALLOC_REGION SPATREGION_SIZE

/* Exact exported ABI: AAPCS32, r0..r3 only, no stack arguments. */
spAtlas* spAtlas_create(const char* data, int dataLen, const char* dir, void* renderer);
spAtlasPage* spAtlasPage_create(spAtlas* atlas, const char* name);
spAtlasRegion* spAtlasRegion_create(void);

/* Named boundaries.  spAtlas_dispose is already recovered elsewhere; the
 * texture callback is deliberately left unimplemented. */
void spAtlas_dispose(spAtlas* atlas);
void _spAtlasPage_createTexture(spAtlasPage* page, const char* path);

#endif /* YY_SPINE_ATLAS_LAYOUT_H */
