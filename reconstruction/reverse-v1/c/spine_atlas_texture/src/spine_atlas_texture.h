/*
 * spine_atlas_texture.h — shared layout and ABI for the atlas texture lifecycle.
 * Canonical full ARM32 definitions; no host-size adaptation.
 */
#ifndef YY_SPINE_ATLAS_TEXTURE_H
#define YY_SPINE_ATLAS_TEXTURE_H

#include <stdint.h>
#include "spine_atlas_layout.h"

/*
 * Global struct in .data, GOT-accessed from 0xbd6ec.
 * Identity: the pre-loaded PNG blob and atlas-declared dimensions.
 * The exact .data address is a GOT slot; consumers bind it at link time.
 */
typedef struct yy_atlas_texture_global {
    void*    preloaded_data;   /* +0x00  non-null ⇒ use this blob */
    int32_t  preloaded_len;    /* +0x04  length for ReadPNGFile */
    int32_t  declared_width;   /* +0x08  atlas-declared w, written to page->width */
    int32_t  declared_height;  /* +0x0c  atlas-declared h, written to page->height */
} yy_atlas_texture_global;

/*
 * The single global instance.  The original accesses this through a GOT
 * slot; here it is a plain definition so test harnesses can override it.
 */
extern yy_atlas_texture_global yy_atlas_texture_global_instance;

/* One-byte flag (GOT at 0xbd820) gating GR_Texture_Free in disposeTexture. */
extern uint8_t yy_texture_free_enabled;

/* Named-boundary externs; bodies are not recovered in this module. */
extern void* yy_ReadPNGFile(void* data, int length, int* out_w, int* out_h, int flag);
extern void  yy_FreePNGFile(void);
extern int32_t yy_GR_Texture_Create_And_Fill(int w, int h, void* data, int bytes);
extern void  yy_GR_Texture_Free(int id);
extern int   yy_SaveFileExists(const char* path);
extern void* yy_ReadSaveFile(const char* path, int* out_size);
extern int   yy_BundleFileExists(const char* path);
extern void* yy_ReadBundleFile(const char* path, int* out_size);
extern void  yy_MemoryManager_Free(void* ptr);

/* Public API (matches dynsym). */
void _spAtlasPage_createTexture(spAtlasPage* page, const char* path);
void _spAtlasPage_disposeTexture(spAtlasPage* page);

#endif /* YY_SPINE_ATLAS_TEXTURE_H */
