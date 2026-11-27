/* tier:bytecode_anchored. Image SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * updateOffset@0x289040..0x289174:304B/76 ARM words +4B pool.
 * Math imports are DOUBLE cos/sin (core-register AAPCS), not cosf/sinf.
 * Keep every VFP operation/rounding/operand and store order, not an algebraic
 * rewrite of four corners. Exact malformed-memory/FP trap domains unproved. */
#include "spine_region_geometry.h"
extern double cos(double);
extern double sin(double);
#define AI static inline __attribute__((always_inline))
AI float ld(const void *p) { float x;__asm__ volatile("vldr %0,[%1]":"=t"(x):"r"(p):"memory");return x; }
AI void st(void *p,float x) { __asm__ volatile("vstr %0,[%1]"::"t"(x),"r"(p):"memory"); }
AI float i32f(float raw) { float x;__asm__ volatile("vcvt.f32.s32 %0,%1":"=t"(x):"t"(raw):"memory");return x; }
AI float div32(float a,float b) { float x;__asm__ volatile("vdiv.f32 %0,%1,%2":"=t"(x):"t"(a),"t"(b):"memory");return x; }
AI float mul32(float a,float b) { float x;__asm__ volatile("vmul.f32 %0,%1,%2":"=t"(x):"t"(a),"t"(b):"memory");return x; }
AI float nmul32(float a,float b) { float x;__asm__ volatile("vnmul.f32 %0,%1,%2":"=t"(x):"t"(a),"t"(b):"memory");return x; }
AI float mla32(float acc,float a,float b) { __asm__ volatile("vmla.f32 %0,%1,%2":"+t"(acc):"t"(a),"t"(b):"memory");return acc; }
AI float add32(float a,float b) { float x;__asm__ volatile("vadd.f32 %0,%1,%2":"=t"(x):"t"(a),"t"(b):"memory");return x; }
AI float sub32(float a,float b) { float x;__asm__ volatile("vsub.f32 %0,%1,%2":"=t"(x):"t"(a),"t"(b):"memory");return x; }
AI double widen(float a) { double x;__asm__ volatile("vcvt.f64.f32 %P0,%1":"=w"(x):"t"(a):"memory");return x; }
AI float narrow(double a) { float x;__asm__ volatile("vcvt.f32.f64 %0,%P1":"=t"(x):"w"(a):"memory");return x; }
void spRegionAttachment_updateOffset(spRegionAttachment *a) {
    float raw_ow=ld(&a->regionOriginalWidth); /*0x289040*/
    float raw_oh=ld(&a->regionOriginalHeight); /*0x289044*/
    float ow=i32f(raw_ow); /*0x289048*/
    float height=ld(&a->height),width=ld(&a->width); /*0x28904c/50*/
    float sx=ld(&a->scaleX),sy=ld(&a->scaleY); /*0x289054/58*/
    float raw_ox=ld(&a->regionOffsetX); /*0x28905c*/
    uint32_t degree_bits=0x3c8efa35u;float degree;__builtin_memcpy(&degree,&degree_bits,4); /*pool0x289170*/
    float rotation=ld(&a->rotation); /*0x28906c*/
    float oh=i32f(raw_oh); /*0x289074*/
    float rx=div32(width,ow),ry=div32(height,oh); /*0x289078/7c*/
    rx=mul32(rx,sx);ry=mul32(ry,sy); /*0x289080/84*/
    float half=0.5f;
    float ox=i32f(raw_ox); /*0x28908c*/
    float raw_oy=ld(&a->regionOffsetY),oy=i32f(raw_oy); /*0x289090/94*/
    float x1=mul32(ox,rx); /*0x289098*/
    float neg_hw=nmul32(width,half); /*0x28909c*/
    float y1=mul32(oy,ry); /*0x2890a0*/
    float neg_hh=nmul32(height,half); /*0x2890a4*/
    x1=mla32(x1,sx,neg_hw); /*0x2890a8*/
    float raw_rh=ld(&a->regionHeight); /*0x2890ac*/
    y1=mla32(y1,sy,neg_hh); /*0x2890b0*/
    float radians=mul32(rotation,degree); /*0x2890b4 BEFORE widening*/
    float raw_rw=ld(&a->regionWidth); /*0x2890b8*/
    double angle=widen(radians); /*0x2890bc*/
    float rw=i32f(raw_rw),rh=i32f(raw_rh); /*0x2890c0/c8*/
    float x2=mla32(x1,rw,rx),y2=mla32(y1,rh,ry); /*0x2890d4/d8*/
    double cos_result=cos(angle); /*0x2890dc cos@plt0xb67e4*/
    float co=narrow(cos_result); /*0x2890e8 BEFORE sin call*/
    double sin_result=sin(angle); /*0x2890ec sin@plt0xb67d8; same pre-cos angle*/
    float x=ld(&a->x),y=ld(&a->y); /*0x2890f0/f4 AFTER both imports*/
    float xa=mla32(x,x2,co); /*0x2890fc*/
    float xb=mla32(x,x1,co); /*0x289100*/
    float si=narrow(sin_result); /*0x289108 AFTER both x accumulations*/
    float yb=y;
    float x2s=mul32(x2,si); /*0x289110*/
    yb=mla32(yb,y1,co); /*0x289114*/
    float x1s=mul32(x1,si); /*0x289118*/
    float y1s=mul32(y1,si); /*0x28911c*/
    float y2s=mul32(y2,si); /*0x289120*/
    float ya=mla32(y,y2,co); /*0x289124*/
    float o0=sub32(xb,y1s); /*0x289128*/
    float o2=sub32(xb,y2s); /*0x28912c*/
    st(&a->offset[0],o0); /*0x289130*/
    float o4=sub32(xa,y2s); /*0x289134*/
    st(&a->offset[2],o2); /*0x289138*/
    float o6=sub32(xa,y1s); /*0x28913c*/
    st(&a->offset[4],o4); /*0x289140*/
    float o1=add32(yb,x1s); /*0x289144*/
    st(&a->offset[6],o6); /*0x289148*/
    float o3=add32(ya,x1s); /*0x28914c*/
    st(&a->offset[1],o1); /*0x289150*/
    float o5=add32(ya,x2s); /*0x289154*/
    st(&a->offset[3],o3); /*0x289158*/
    float o7=add32(yb,x2s); /*0x28915c*/
    st(&a->offset[5],o5);st(&a->offset[7],o7); /*0x289160/64*/
}
