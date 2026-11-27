/* Canonical ARM32 lookup translations, original SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Bone@0x28afbc/92B; SlotIndex@0x28b0cc/88B; Skin@0x28b124/92B.
 * All three snapshot count/table; object pointer cached across strcmp, while
 * each next table entry is read fresh. No before-array C pointer arithmetic. */
#include "skeleton_find.h"
extern int strcmp(const char *,const char *);
static uint32_t rd(const void *p,uint32_t off) {
    uint32_t x,address=(uint32_t)(uintptr_t)p+off;
    __asm__ volatile("ldr %0,[%1]":"=r"(x):"r"(address):"memory");
    return x;
}
static void *ptr(uint32_t x) { return (void *)(uintptr_t)x; }
static int32_t signed32(uint32_t x) { int32_t y;__builtin_memcpy(&y,&x,4);return y; }
spBoneData *spSkeletonData_findBone(spSkeletonData *s,const char *name) {
    uint32_t count=rd(s,0x10); /*0x28afc4*/
    if(signed32(count)<=0)return 0;
    uint32_t table=rd(s,0x14),i=0; /*0x28afd0 snapshot*/
    do {
        spBoneData *bone=ptr(rd(ptr(table),i<<2)); /*0x28afe8*/
        ++i; /*0x28aff0*/
        if(strcmp(ptr(rd(bone,4)),name)==0)return bone; /*0x28aff4/aff8*/
    } while(i!=count); /*0x28afe0/afe4*/
    return 0;
}
int spSkeletonData_findSlotIndex(spSkeletonData *s,const char *name) {
    uint32_t count=rd(s,0x18); /*0x28b0d4*/
    if(signed32(count)<=0)return -1;
    uint32_t table=rd(s,0x1c),i=0; /*0x28b0e0 snapshot*/
    do {
        spSlotData *slot=ptr(rd(ptr(table),i<<2));
        if(strcmp(ptr(rd(slot,4)),name)==0)return (int)i; /*0x28b104/b108*/
        ++i; /*0x28b0f0*/
    } while(i!=count);
    return -1;
}
spSkin *spSkeletonData_findSkin(spSkeletonData *s,const char *name) {
    uint32_t count=rd(s,0x20); /*0x28b12c*/
    if(signed32(count)<=0)return 0;
    uint32_t table=rd(s,0x24),i=0; /*0x28b138 snapshot*/
    do {
        spSkin *skin=ptr(rd(ptr(table),i<<2));
        ++i; /*0x28b158*/
        if(strcmp(ptr(rd(skin,0)),name)==0)return skin; /*0x28b15c/b160*/
    } while(i!=count);
    return 0;
}
