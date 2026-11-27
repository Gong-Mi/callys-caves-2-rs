/*
 * spine_atlas_texture.c — byte-anchored C reconstruction of the two texture
 * lifecycle entry points for spine atlas pages in libyoyo_armv7.so
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Evidence tier: bytecode_anchored.  Every branch, load, store and literal
 * below is tied to the original instruction address.  The original was not
 * executed for this file.
 *
 * Symbols:
 *   0xbd6e4 _spAtlasPage_createTexture   304 B  76 insns
 *   0xbd814 _spAtlasPage_disposeTexture   40 B  10 insns
 *   0xbd83c _spUtil_readFile (tail; 4 B  1 insn: bx lr)
 *
 * Direct dependencies (named boundaries, bodies not recovered here):
 *   ReadPNGFile             0x18a24c  void* ReadPNGFile(void*, int, int*, int*, bool)
 *   FreePNGFile             0x18a518  void FreePNGFile(void)
 *   GR_Texture_Create_And_Fill 0x173c18  int GR_Texture_Create_And_Fill(int w, int h, void* data, int bytes)
 *   GR_Texture_Free         0x173f84  void GR_Texture_Free(int id)
 *   LoadSave::SaveFileExists 0x18fb6c  bool SaveFileExists(const char*)
 *   LoadSave::ReadSaveFile   0x18fb08  void* ReadSaveFile(const char*, int*)
 *   LoadSave::BundleFileExists 0x18f8ac bool BundleFileExists(const char*)
 *   LoadSave::ReadBundleFile  0x18f848 void* ReadBundleFile(const char*, int*)
 *   MemoryManager::Free      0x27c2d0  void Free(void*)
 *
 * Global state:
 *   A 16-byte struct in .data accessed via GOT (pc-relative literal at 0xbd6ec):
 *     +0x00  void*  preloaded_data    (checked non-null at 0xbd700)
 *     +0x04  int    preloaded_len     (passed as r1 to ReadPNGFile)
 *     +0x08  int    declared_width    (stored to page->width from global, not decoded)
 *     +0x0c  int    declared_height   (stored to page->height from global, not decoded)
 *   A one-byte flag (GOT at 0xbd820) gates disposeTexture's GR_Texture_Free call.
 *
 * Control flow summary (createTexture):
 *   Path A (preloaded): global.data != 0 → ReadPNGFile(data, len, &w, &h, false)
 *     → if png: page->width = global.w; page->height = global.h;
 *       page->texture = GR_Texture_Create_And_Fill(w, h, png, w*h*4); FreePNGFile()
 *   Path B (save file): global.data == 0 → SaveFileExists(path)
 *     → if yes: data = ReadSaveFile(path, &size) → decode → free
 *   Path C (bundle): SaveFileExists returned 0 → BundleFileExists(path)
 *     → if yes: data = ReadBundleFile(path, &size) → decode → free
 *   Path B/C decode: ReadPNGFile(data, size, &w, &h, false)
 *     → if png: page->width = w; page->height = h;
 *       page->texture = GR_Texture_Create_And_Fill(w, h, png, w*h*4); FreePNGFile()
 *   MemoryManager::Free(data) runs in the save/bundle paths regardless of decode success.
 *
 * Semantics note: page->width/height come from the GLOBAL struct in path A
 * (the atlas-declared size), but from the DECODED PNG in paths B/C.  The
 * texture creation always uses the decoded w/h.  A mismatch between the
 * atlas-declared and decoded dimensions is preserved, not corrected.
 */

#include "spine_atlas_texture.h"

/*
 * ARM32 byte-level primitives.  The original code uses plain ldr/str on
 * aligned offsets; we keep the same access widths so the memory footprint
 * is identical.  No host-size adaptation.
 */

/* Literal-pool word at 0xbd81c (createTexture) and 0xbd830 (disposeTexture)
 * are data, not instructions.  The disassembler prints them as mlaseq /
 * ldrshteq; they are never executed. */

void
_spAtlasPage_createTexture(spAtlasPage* page, const char* path)
{
    /* 0xbd6e4 push {r4,r5,r6,lr}; 0xbd6f0 sub sp,sp,#24 */
    /* r5 = page (0xbd6e8); r6 = path (0xbd6f4) */

    /* 0xbd6ec ldr r4,[pc,#0x11c]; 0xbd6f8 add r4,pc,r4  → GOT-resolved global */
    const yy_atlas_texture_global* g = &yy_atlas_texture_global_instance;

    /* 0xbd6fc ldr r3,[r4]; 0xbd700 cmp r3,#0; 0xbd704 beq 0xbd764 */
    if (g->preloaded_data != NULL) {
        /* Path A: pre-loaded PNG blob */
        int w = 0, h = 0;                     /* sp+16, sp+20 */

        /* 0xbd708 ldr r1,[r4,#4]; 0xbd70c mov r0,r3; 0xbd710 add r2,sp,#16 */
        /* 0xbd714 mov r3,#0; 0xbd718 str r3,[sp]; 0xbd71c add r3,sp,#20 */
        void* png = yy_ReadPNGFile(g->preloaded_data, g->preloaded_len, &w, &h, 0);

        /* 0xbd724 subs r2,r0,#0; 0xbd728 beq 0xbd75c */
        if (png != NULL) {
            /* 0xbd72c ldr r3,[sp,#16] → w (decoded) */
            /* 0xbd730 ldr r1,[sp,#20] → h (decoded) */
            /* 0xbd734 ldr lr,[r4,#8]  → declared width (from global) */
            /* 0xbd73c ldr r12,[r4,#0xc] → declared height (from global) */

            /* 0xbd744 str lr,[r5,#0x20]  page->width = declared w */
            page->width = g->declared_width;

            /* 0xbd748 str r12,[r5,#0x24] page->height = declared h */
            page->height = g->declared_height;

            /* 0xbd738 mov r0,r3 (w); 0xbd740 mul r3,r1,r3 (w*h); 0xbd74c lsl r3,r3,#2 */
            /* 0xbd750 bl GR_Texture_Create_And_Fill */
            page->texture_id = yy_GR_Texture_Create_And_Fill(w, h, png, w * h * 4);

            /* 0xbd754 str r0,[r5,#0x1c] (store above); 0xbd758 bl FreePNGFile */
            yy_FreePNGFile();
        }
        /* 0xbd75c add sp,sp,#24; 0xbd760 pop {r4,r5,r6,pc} */
        return;
    }

    /* Path B/C: load from file system */
    /* 0xbd764 mov r0,r1 (path); 0xbd768 str r3,[sp,#0xc] (size out, init 0) */
    int size = 0;                             /* sp+12 */
    void* data = NULL;                        /* r4 */

    /* 0xbd76c bl SaveFileExists(path); 0xbd770 cmp r0,#0 */
    /* 0xbd774 mov r0,r6 (path); 0xbd778 beq 0xbd7ec */
    if (yy_SaveFileExists(path)) {
        /* 0xbd77c add r1,sp,#12; 0xbd780 bl ReadSaveFile(path,&size) */
        data = yy_ReadSaveFile(path, &size);
    } else {
        /* 0xbd7ec bl BundleFileExists(path); 0xbd7f0 cmp r0,#0 */
        /* 0xbd7f4 moveq r4,r0; 0xbd7f8 beq 0xbd7dc */
        if (!yy_BundleFileExists(path)) {
            /* Neither save file nor bundle: data stays NULL */
            /* 0xbd7dc mov r0,r4; 0xbd7e0 bl MemoryManager::Free(NULL) */
            /* 0xbd7e4 add sp,sp,#24; 0xbd7e8 pop */
            yy_MemoryManager_Free(NULL);
            return;
        }
        /* 0xbd7fc mov r0,r6 (path); 0xbd800 add r1,sp,#12 */
        /* 0xbd804 bl ReadBundleFile(path,&size) */
        data = yy_ReadBundleFile(path, &size);
    }

    /* 0xbd788 cmp r4,#0; 0xbd78c beq 0xbd7dc */
    if (data != NULL) {
        int w = 0, h = 0;                     /* sp+16, sp+20 */

        /* 0xbd790 mov r3,#0; 0xbd794 add r2,sp,#16; 0xbd798 str r3,[sp] */
        /* 0xbd79c mov r0,r4 (data); 0xbd7a0 ldr r1,[sp,#0xc] (size); 0xbd7a4 add r3,sp,#20 */
        /* 0xbd7a8 bl ReadPNGFile(data, size, &w, &h, false) */
        void* png = yy_ReadPNGFile(data, size, &w, &h, 0);

        /* 0xbd7ac subs r2,r0,#0; 0xbd7b0 beq 0xbd7dc */
        if (png != NULL) {
            /* 0xbd7b4 ldr r3,[sp,#16] → w; 0xbd7b8 ldr r1,[sp,#20] → h */
            /* 0xbd7bc str r3,[r5,#0x20] page->width = decoded w */
            page->width = w;
            /* 0xbd7c8 str r1,[r5,#0x24] page->height = decoded h */
            page->height = h;

            /* 0xbd7c0 mov r0,r3 (w); 0xbd7c4 mul r3,r1,r3; 0xbd7cc lsl r3,r3,#2 */
            /* 0xbd7d0 bl GR_Texture_Create_And_Fill(w, h, png, w*h*4) */
            page->texture_id = yy_GR_Texture_Create_And_Fill(w, h, png, w * h * 4);

            /* 0xbd7d4 str r0,[r5,#0x1c]; 0xbd7d8 bl FreePNGFile */
            yy_FreePNGFile();
        }
        /* Fall through to free */
    }

    /* 0xbd7dc mov r0,r4 (data); 0xbd7e0 bl MemoryManager::Free */
    yy_MemoryManager_Free(data);
    /* 0xbd7e4 add sp,sp,#24; 0xbd7e8 pop {r4,r5,r6,pc} */
}

void
_spAtlasPage_disposeTexture(spAtlasPage* page)
{
    /* 0xbd814 ldr r0,[r0,#0x1c] */
    int id = page->texture_id;

    /* 0xbd818 cmp r0,#0; 0xbd81c bxeq lr */
    if (id == 0)
        return;

    /* 0xbd820-0xbd830: GOT-resolved byte flag; if 0, return without freeing */
    if (!yy_texture_free_enabled)
        return;

    /* 0xbd834 b GR_Texture_Free(id) — tail call */
    yy_GR_Texture_Free(id);
}
