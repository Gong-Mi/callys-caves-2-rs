/* tier:bytecode_anchored; original image
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * readSkeletonData blocks0x28ccb8..0x28cd6c and0x28e880..0x28e8ac.
 * Parent full loader/event/animation assembly remains open. No original runs. */
#include "spine_linked_postpass.h"
#include "spine_skin.h"
#include "spine_mesh.h"
#include "skeleton_find.h"
#include "spine_json_error.h"
static int32_t signed32(uint32_t x) { int32_t y;__builtin_memcpy(&y,&x,4);return y; }
int readSkeletonData_resolveLinkedMeshes(spSkeletonJson *j,spSkeletonData *data) {
    if(signed32(j->unk_10)<=0)return 1; /*0x28ccb8..0x28ccc8*/
    uint32_t i=0;
    do {
        uint32_t base=j->unk_18,offset=i<<4; /*0x28cd0c/cd10, per-iteration*/
        spLinkedMesh *entry=(spLinkedMesh *)(uintptr_t)(base+offset);
        const char *skin_name=entry->skin; /*0x28cd1c*/
        spSkin *skin;
        if(!skin_name)skin=(spSkin *)(uintptr_t)data->words[10]; /*+0x28, not first skin*/
        else skin=spSkeletonData_findSkin(data,skin_name); /*0x28cd2c*/
        ++i; /*0x28cd38 before getAttachment and callbacks*/
        if(!skin) {
            spSkeletonData_dispose(data); /*0x28cd48 BEFORE extra string load*/
            _spSkeletonJson_setError(j,0,"Skin not found: ",entry->skin); /*0x28cd58/cd60*/
            return 0;
        }
        spAttachment *parent=spSkin_getAttachment(skin,entry->slotIndex,entry->parent); /*0x28ccd4*/
        if(!parent) {
            spSkeletonData_dispose(data); /*0x28e888 BEFORE extra string load*/
            _spSkeletonJson_setError(j,0,"Parent mesh not found: ",entry->parent); /*0x28e898/e8a0*/
            return 0;
        }
        /* No parent type validation in the original. A successful lookup may
         * return a different attachment type; malformed-layout faults unproved. */
        spMeshAttachment_setParentMesh(entry->mesh,(spMeshAttachment *)parent); /*0x28cce8*/
        spMeshAttachment_updateUVs(entry->mesh); /*0x28ccec/ccf0: re-read mesh*/
        spAttachment *attachment=(spAttachment *)entry->mesh; /*0x28ccf4, re-read after allocator*/
        spAttachmentLoader *loader=(spAttachmentLoader *)(uintptr_t)j->loader; /*0x28ccf8*/
        spAttachmentLoader_configureAttachment(loader,attachment); /*0x28ccfc*/
    } while(signed32(j->unk_10)>signed32(i)); /*0x28cd00..cd08, re-read after callback*/
    return 1; /*0x28d19c successor, no queue clear/free*/
}
