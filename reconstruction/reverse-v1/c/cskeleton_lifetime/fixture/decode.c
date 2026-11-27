/* Synthetic vectors from the static byte/recurrence contract, not original I/O. */
#include "yy_skel_deps.h"
#if defined(YY_FIXTURE_ARM)
static long sys3(long nr,long a,long b,long c)
{
    register long r7 __asm__("r7")=nr;
    register long r0 __asm__("r0")=a;
    register long r1 __asm__("r1")=b;
    register long r2 __asm__("r2")=c;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r7),"r"(r1),"r"(r2) : "memory");
    return r0;
}
static void emit(const char*s) { size_t n=0;while(s[n])++n;sys3(4,1,(long)s,n); }
static void stop(int n) { sys3(1,n,0,0);for(;;){} }
#else
#include <stdio.h>
#include <stdlib.h>
static void emit(const char*s) { fputs(s,stdout); }
static void stop(int n) { exit(n); }
#endif
#define CHECK(c,n) do { if(!(c)) { emit("FAIL " n "\n");stop(1); } } while(0)
static int decode_main(void)
{
    unsigned char a[18], b[18];
    const unsigned char expected[16]={0xd6,0xf3,0x30,0xed,0x0a,0xe7,0x64,0xe1,0x3e,0xdb,0x98,0xd5,0x72,0xcf,0xcc,0xc9};
    for(unsigned i=0;i<18;++i) a[i]=b[i]=0xA5;
    CSkeletonSprite_SimpleDecode(NULL,NULL,0);
    CSkeletonSprite_SimpleDecode(NULL,NULL,-1);
    CSkeletonSprite_SimpleDecode(NULL,a+1,0);
    CHECK(a[0]==0xA5 && a[1]==0xA5 && a[17]==0xA5,"nonpositive_no_write");
    emit("PASS nonpositive_no_write\n");
    for(unsigned v=0;v<256;++v) {
        a[1]=(unsigned char)v;
        CSkeletonSprite_SimpleDecode(NULL,a+1,1);
        CHECK(a[1]==(unsigned char)(v-42u) && a[0]==0xA5 && a[2]==0xA5,"all_byte_one_step");
    }
    emit("PASS all_byte_one_step\n");
    for(unsigned i=0;i<16;++i) a[i+1]=b[i+1]=(unsigned char)i;
    CSkeletonSprite_SimpleDecode(NULL,a+1,16);
    for(unsigned i=0;i<16;++i) CHECK(a[i+1]==expected[i],"recurrence_vector");
    CHECK(a[0]==0xA5 && a[17]==0xA5,"exact_span_guard");
    emit("PASS recurrence_vector\n");
    CSkeletonSprite_SimpleDecode(NULL,b+1,16);
    for(unsigned i=0;i<18;++i) CHECK(a[i]==b[i],"reset_each_call");
    emit("PASS reset_each_call\n");
    return 0;
}
#if defined(YY_FIXTURE_ARM)
void _start(void) { stop(decode_main()); }
#else
int main(void) { return decode_main(); }
#endif
