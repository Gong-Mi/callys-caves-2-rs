/* tier:bytecode_anchored. Image SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * readSkeletonData caller BLOCK0x28cdac..0x28cf24 (not an original function).
 * Original default width/height32.0f and repeated scale reads are retained.
 * Full loader skin insertion/outer loops remain outside this block. */
#include "spine_read_region.h"
#include "spine_color.h"
extern size_t strlen(const char *);
extern char *strcpy(char *,const char *);
static const char tag[]="jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";
static float current_scale(const spSkeletonJson *j) {
    float x;__asm__ volatile("vldr %0,[%1]":"=t"(x):"r"(j):"memory");return x;
}
static float multiply(float a,float b) {
    float x;__asm__ volatile("vmul.f32 %0,%1,%2":"=t"(x):"t"(a),"t"(b):"memory");return x;
}
static void store(float *p,float x) {__asm__ volatile("vstr %0,[%1]"::"t"(x),"r"(p):"memory");}
void readSkeletonData_regionFields(Json *map,spRegionAttachment *a,const char *path,const spSkeletonJson *j) {
    if(path) { /*0x28cdac..cdd8, no free of old owned_10*/
        char *copy=_malloc((uint32_t)strlen(path)+1u,tag,891u);
        a->owned_10=copy;strcpy(copy,path);
    }
    float value=Json_getFloat(map,"x",0.0f); /*0x28cdec*/
    float scale=current_scale(j);store(&a->x,multiply(value,scale)); /*0x28cdf0..ce0c*/
    value=Json_getFloat(map,"y",0.0f);scale=current_scale(j);
    store(&a->y,multiply(value,scale)); /*0x28ce10..ce30*/
    value=Json_getFloat(map,"scaleX",1.0f);store(&a->scaleX,value); /*0x28ce34/44*/
    value=Json_getFloat(map,"scaleY",1.0f);store(&a->scaleY,value); /*0x28ce4c/5c*/
    value=Json_getFloat(map,"rotation",0.0f);store(&a->rotation,value); /*0x28ce64/74*/
    value=Json_getFloat(map,"width",32.0f);scale=current_scale(j);
    store(&a->width,multiply(value,scale)); /*0x28ce7c..ce9c*/
    value=Json_getFloat(map,"height",32.0f);scale=current_scale(j);
    store(&a->height,multiply(value,scale)); /*0x28cea0..cec0*/
    const char *color=Json_getString(map,"color",0); /*0x28cec4*/
    if(color) {
        store(&a->r,toColor(color,0));store(&a->g,toColor(color,1));
        store(&a->b,toColor(color,2));store(&a->a,toColor(color,3)); /*0x28ced4..cf08*/
    }
    spRegionAttachment_updateOffset(a); /*0x28cf10*/
    spAttachmentLoader *loader=(spAttachmentLoader *)(uintptr_t)j->loader; /*0x28cf14 AFTER math callbacks*/
    spAttachmentLoader_configureAttachment(loader,&a->super); /*0x28cf1c*/
}
