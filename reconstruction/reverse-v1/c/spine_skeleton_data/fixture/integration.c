/* Cumulative reconstructed consumer, ARM32 only. No original is executed.
 * Real ctor/decode, JSON/attachment/allocation/data/atlas cleanup are linked.
 * Remaining synthetic boundaries: atlas/data parsing, imported libc/graphics,
 * and the address-only createAttachment provider (must not execute). */
#include "spine_alloc.h"
#include "spine_attachment.h"
#include "spine_skeleton_data.h"
#include "yy_skel_deps.h"
#include "atlas_dispose.h"
#include "fx.h"
volatile uint8_t g_bFreeingSpineSprite;
yy_glob_479c98 g_yy_479c98;
struct spAtlas { uint32_t words[3]; };
static uint32_t values[64],expected[64];
static unsigned char kinds[64],ekinds[64];
static unsigned count,nexpect,debug_calls,creation_callback_calls;
static char *input;
static uint32_t atlas_addr,page_addr,name_addr,json_addr,data_addr,loader_addr,vtable_addr;
static int failed;
static void check(int ok,const char *label){if(!ok){fx_puts("FAIL ");fx_puts(label);fx_puts("\n");failed=1;}}
static void event(unsigned char k,uint32_t v){if(count==64)fx_exit(90);kinds[count]=k;values[count++]=v;}
static void want(unsigned char k,uint32_t v){if(nexpect==64)fx_exit(90);ekinds[nexpect]=k;expected[nexpect++]=v;}
void *malloc(uint32_t n){return (void *)(uintptr_t)fx_alloc(n?n:8);}
void free(void *p){event('F',(uint32_t)(uintptr_t)p);}
static void *debug_malloc(uint32_t n,const char *tag,uint32_t line)
{
    ++debug_calls;
    check(tag!=0,"debug allocator receives tag");
    check(line==0||line==37||line==51||line==62||line==93,"real allocator metadata reaches debug provider");
    return malloc(n);
}
void GR_Texture_Free(int id){check(g_bFreeingSpineSprite==1,"real D2 texture flag");event('T',(uint32_t)id);}
spAttachment *_spAtlasAttachmentLoader_createAttachment(spAttachmentLoader *l,spSkin *s,int32_t t,const char *n,const char *p)
{(void)l;(void)s;(void)t;(void)n;(void)p;++creation_callback_calls;return 0;}
spAtlas *spAtlas_create(const char *data,int len,const char *dir,void *renderer)
{
    check(data==input+4&&len==4&&dir&&!*dir&&!renderer,"actual constructor atlas ABI");
    spAtlas *a=_calloc(1,12,"fixture",0);atlas_addr=(uint32_t)(uintptr_t)a;
    page_addr=(uint32_t)(uintptr_t)_calloc(1,44,"fixture",0);
    name_addr=(uint32_t)(uintptr_t)_calloc(1,8,"fixture",0);
    fx_w32(page_addr+4,name_addr);fx_w32(page_addr+0x1c,19);fx_w32(atlas_addr,page_addr);
    return a;
}
spSkeletonData *spSkeletonJson_readSkeletonData(spSkeletonJson *j,const char *text)
{
    static const uint8_t bytes[8]={0xd6,0xf3,0x30,0xed,0xda,0xf7,0x34,0xf1};
    json_addr=(uint32_t)(uintptr_t)j;
    check(text==input,"real JSON parser forwarding");
    for(unsigned i=0;i<8;++i)check((uint8_t)text[i]==bytes[i],"real decoder output forwarded");
    loader_addr=fx_r32(json_addr+4);
    spAttachmentLoader *ld=(spAttachmentLoader *)(uintptr_t)loader_addr;
    check((uint32_t)(uintptr_t)ld->atlas==atlas_addr,"real attachment object consumed by JSON");
    check(ld->vtable->dispose==_spAttachmentLoader_deinit,"real attachment deinit registered");
    vtable_addr=(uint32_t)(uintptr_t)ld->vtable;
    spSkeletonData *d=spSkeletonData_create();data_addr=(uint32_t)(uintptr_t)d;
    return d;
}
static void scenario(int debug)
{
    char bytes[8]={0,1,2,3,4,5,6,7};input=bytes;
    yy_skel12 sk;debug_calls=0;creation_callback_calls=0;
    _setDebugMalloc(debug?debug_malloc:0);
    check(CSkeletonSprite_ctor(&sk,bytes,4,4,11,22,33)==&sk,"real ctor return");
    check(sk.slot_00_json==json_addr&&sk.slot_04_data==data_addr&&sk.slot_08_atlas==atlas_addr,"real published handles");
    check(debug?debug_calls>0:debug_calls==0,"selected allocator route consumed");
    check(creation_callback_calls==0,"unrecovered attachment creation callback not executed");
    count=nexpect=0;
    for(unsigned i=0;i<10;++i)want('F',0); /* 8 tables, +4, +0 */
    want('F',data_addr);
    want('F',vtable_addr);want('F',0);want('F',0);want('F',loader_addr);
    want('F',0);want('F',0);want('F',json_addr);
    want('T',19);want('F',name_addr);want('F',page_addr);want('F',atlas_addr);
    g_bFreeingSpineSprite=0xa5;
    check(CSkeletonSprite_D2(&sk)==&sk,"real destructor return");
    check(count==nexpect,"real cleanup event count");
    for(unsigned i=0;i<count&&i<nexpect;++i)check(kinds[i]==ekinds[i]&&values[i]==expected[i],"real cleanup event sequence");
    check(g_bFreeingSpineSprite==0,"real destructor closes flag window");
    fx_puts(debug?"PASS real_chain_debug_allocator\n":"PASS real_chain_initial_libc_slot\n");
}
static int test_main(void){if(fx_map_arena())return 90;scenario(0);scenario(1);return failed?1:0;}
void _start(void){fx_exit(test_main());}
