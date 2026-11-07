/* Canonical complete ARM32 Skin/Entry records. Image SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a. */
#ifndef YY_SPINE_SKIN_H
#define YY_SPINE_SKIN_H
#include "spine_alloc.h"
#include "spine_skeleton_data.h"
typedef struct spSkinEntry spSkinEntry;
struct spSkinEntry {
    uint32_t slotIndex;         /* +00 */
    char *name;                /* +04 owned copy */
    spAttachment *attachment;  /* +08 owned through attachment's vtable */
    spSkinEntry *next;         /* +0c */
};
struct spSkin {
    char *name;                /* +00 owned copy */
    spSkinEntry *entries;      /* +04 head; newest entry first */
};
_Static_assert(sizeof(spSkin)==8,"skin calloc 1*8 at0x28ec64");
_Static_assert(sizeof(spSkinEntry)==16,"entry calloc 1*16 at0x28ebe0");
_Static_assert(offsetof(spSkinEntry,attachment)==8,"entry attachment");
_Static_assert(offsetof(spSkinEntry,next)==12,"entry next");
YOYO_NOINLINE spSkinEntry *_Entry_create(uint32_t slotIndex,const char *name,spAttachment *attachment);
spSkin *spSkin_create(const char *name);
void spSkin_addAttachment(spSkin *,uint32_t slotIndex,const char *name,spAttachment *);
spAttachment *spSkin_getAttachment(spSkin *,uint32_t slotIndex,const char *name);
#endif
