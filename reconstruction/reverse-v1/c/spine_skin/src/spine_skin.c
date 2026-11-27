/* tier: bytecode_anchored. Whole library/original equivalence NOT claimed.
 * Image3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Original ARM entries: _Entry_create 0x28ebb8/104B (last4B pool),
 * spSkin_create 0x28ec44/88B (last4B pool), add0x28ecd8/40B, get0x28ed00/88B.
 * Existing generic raw-ABI disposers stay in spine_skeleton_data, not duplicated. */
#include "spine_skin.h"
extern size_t strlen(const char *);
extern char *strcpy(char *,const char *);
extern int strcmp(const char *,const char *);
static const char tag[]="jni/../jni/yoyo/../../../spine-c/src/spine/Skin.c";
spSkinEntry *_Entry_create(uint32_t slotIndex,const char *name,spAttachment *attachment) {
    spSkinEntry *e=_calloc(1,16,tag,36); /*0x28ebe0*/
    e->slotIndex=slotIndex; /*0x28ebe8 before strlen/malloc*/
    uint32_t size=(uint32_t)strlen(name)+1u;
    char *copy=_malloc(size,tag,38); /*0x28ec00*/
    e->name=copy; /*0x28ec08 BEFORE strcpy*/
    strcpy(copy,name); /*0x28ec0c: pointer returned by malloc, not a reread*/
    e->attachment=attachment; /*0x28ec10 AFTER strcpy*/
    return e;
}
spSkin *spSkin_create(const char *name) {
    spSkin *s=_calloc(1,8,tag,52); /*0x28ec64*/
    char *copy=_malloc((uint32_t)strlen(name)+1u,tag,53); /*0x28ec80*/
    s->name=copy; /*0x28ec88*/
    strcpy(copy,name); /*0x28ec8c*/
    return s;
}
void spSkin_addAttachment(spSkin *s,uint32_t slotIndex,const char *name,spAttachment *a) {
    spSkinEntry *e=_Entry_create(slotIndex,name,a); /*0x28ecec*/
    e->next=s->entries; /*0x28ecf0/f4: head AFTER all callbacks in create*/
    s->entries=e; /*0x28ecf8: head insertion, duplicates not replaced*/
}
spAttachment *spSkin_getAttachment(spSkin *s,uint32_t slotIndex,const char *name) {
    spSkinEntry *e=s->entries; /*0x28ed08*/
    while(e) {
        if(e->slotIndex==slotIndex && strcmp(e->name,name)==0)
            return e->attachment; /*0x28ed48: AFTER comparison callback*/
        e=e->next; /*0x28ed1c: AFTER callback, never a prefetched next*/
    }
    return 0;
}
