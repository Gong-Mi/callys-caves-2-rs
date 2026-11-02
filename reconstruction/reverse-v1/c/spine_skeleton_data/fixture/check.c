/* Synthetic ARM32 check of translated bodies only; no original is executed. */
#include "spine_skeleton_data.h"
#include "fx.h"
static uint32_t got[128], want[128], rewrite_on, rewrite_at, rewrite_value;
static unsigned ng,nw;
static unsigned char got_kind[128],want_kind[128];
static void fail(const char *s){fx_puts("FAIL ");fx_puts(s);fx_puts("\n");fx_exit(1);}
#define CHECK(c,s) do{if(!(c))fail(s);}while(0)
static void event(unsigned char k,uint32_t v){CHECK(ng<128,"log bounds");got_kind[ng]=k;got[ng++]=v;}
static void expect(unsigned char k,uint32_t v){CHECK(nw<128,"expected bounds");want_kind[nw]=k;want[nw++]=v;}
static void eq(const char *s){CHECK(ng==nw,s);for(unsigned i=0;i<ng;++i)CHECK(got[i]==want[i]&&got_kind[i]==want_kind[i],s);}
static uint32_t obj(uint32_t n){uint32_t p=fx_alloc(n);for(uint32_t i=0;i<n;++i)*(uint8_t *)(uintptr_t)(p+i)=0;return p;}
static void reset(void){ng=nw=0;rewrite_on=rewrite_at=rewrite_value=0;}
void _free(void *p)
{
    uint32_t a=(uint32_t)(uintptr_t)p;event('F',a);
    if(rewrite_on && a==rewrite_on){fx_w32(rewrite_at,rewrite_value);rewrite_on=0;}
}
void *_calloc(uint32_t n,uint32_t size,const char *tag,uint32_t line)
{
    static const char original[]="jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonData.c";
    CHECK(n==1&&size==84&&line==37&&tag,"create ABI");
    for(unsigned i=0;i<sizeof original;++i)CHECK(tag[i]==original[i],"create metadata");
    return (void *)(uintptr_t)obj(84);
}
static void timeline_callback(spTimeline *p){event('T',(uint32_t)(uintptr_t)p);}
static void attachment_callback(spAttachment *p){event('A',(uint32_t)(uintptr_t)p);}
static const uint32_t count_off[8]={0x10,0x18,0x20,0x2c,0x34,0x3c,0x44,0x4c};
static uint32_t attachment(void)
{
    uint32_t a=obj(12),vt=obj(4);fx_w32(vt,(uint32_t)(uintptr_t)attachment_callback);fx_w32(a+8,vt);return a;
}
static void full_graph(void)
{
    uint32_t root=(uint32_t)(uintptr_t)spSkeletonData_create();
    for(unsigned i=0;i<21;++i)CHECK(fx_r32(root+4*i)==0,"create zeroed input");
    for(unsigned k=0;k<8;++k){
        uint32_t table=obj(4),child=obj(16),name=obj(4);
        fx_w32(root+count_off[k],1);fx_w32(root+count_off[k]+4,table);fx_w32(table,child);
        if(k==0){fx_w32(child+4,name);expect('F',name);expect('F',child);}
        else if(k==1){uint32_t p=obj(4);fx_w32(child+4,name);fx_w32(child+0xc,p);expect('F',name);expect('F',p);expect('F',child);}
        else if(k==2){
            uint32_t entry=obj(16),en=obj(4),a=attachment();fx_w32(child,name);fx_w32(child+4,entry);
            fx_w32(entry+4,en);fx_w32(entry+8,a);
            expect('A',a);expect('F',en);expect('F',entry);expect('F',name);expect('F',child);
        }else if(k==3){uint32_t p=obj(4);fx_w32(child+0xc,p);fx_w32(child,name);expect('F',p);expect('F',name);expect('F',child);}
        else if(k==4){
            uint32_t a=obj(4),t=obj(8),vt=obj(8);fx_w32(vt+4,(uint32_t)(uintptr_t)timeline_callback);
            fx_w32(t+4,vt);fx_w32(a,t);fx_w32(child+8,1);fx_w32(child+0xc,a);fx_w32(child,name);
            expect('T',t);expect('F',a);expect('F',name);expect('F',child);
        }else{uint32_t p=obj(4);fx_w32(child,name);fx_w32(child+8,p);expect('F',name);expect('F',p);expect('F',child);}
        expect('F',table);
    }
    uint32_t p0=obj(4),p4=obj(4);fx_w32(root,p0);fx_w32(root+4,p4);
    fx_w32(root+8,obj(4));fx_w32(root+0xc,obj(4));fx_w32(root+0x28,obj(4));
    expect('F',p4);expect('F',p0);expect('F',root);
    spSkeletonData_dispose((spSkeletonData *)(uintptr_t)root);eq("full graph");
    fx_puts("PASS full_graph_all_translated_entries\n");
}
static void nonpositive(void)
{
    uint32_t root=obj(84);
    for(unsigned k=0;k<8;++k){uint32_t t=obj(4);fx_w32(root+count_off[k],(k&1)?0:0x80000000u);fx_w32(root+count_off[k]+4,t);expect('F',t);}
    expect('F',0);expect('F',0);expect('F',root);
    spSkeletonData_dispose((spSkeletonData *)(uintptr_t)root);eq("nonpositive counts");
    fx_puts("PASS signed_nonpositive_still_releases_tables\n");
}
static void mutable_vector(int shrink)
{
    uint32_t root=obj(84),old=obj(8),replacement=obj(8),b0=obj(8),b1=obj(8),wrong=obj(8),n0=obj(4),n1=obj(4);
    fx_w32(b0+4,n0);fx_w32(b1+4,n1);fx_w32(old,b0);fx_w32(old+4,wrong);fx_w32(replacement+4,b1);
    fx_w32(root+0x10,2);fx_w32(root+0x14,old);
    rewrite_on=n0;rewrite_at=root+(shrink?0x10:0x14);rewrite_value=shrink?1:replacement;
    expect('F',n0);expect('F',b0);
    if(!shrink){expect('F',n1);expect('F',b1);}
    expect('F',shrink?old:replacement);
    for(unsigned k=1;k<8;++k)expect('F',0);
    expect('F',0);expect('F',0);expect('F',root);
    spSkeletonData_dispose((spSkeletonData *)(uintptr_t)root);eq("callback vector reread");
    fx_puts(shrink?"PASS count_reloaded_after_child\n":"PASS table_reloaded_after_child\n");
}
static void scalar_reread(void)
{
    uint32_t slot=obj(16),first=obj(4),old=obj(4),replacement=obj(4);
    fx_w32(slot+4,first);fx_w32(slot+0xc,old);
    rewrite_on=first;rewrite_at=slot+0xc;rewrite_value=replacement;
    expect('F',first);expect('F',replacement);expect('F',slot);
    spSlotData_dispose((spSlotData *)(uintptr_t)slot);eq("scalar reread");
    fx_puts("PASS scalar_reloaded_after_free\n");
}
static int test_main(void)
{
    CHECK(fx_map_arena()==0,"fixture arena");
    reset();full_graph();reset();nonpositive();reset();mutable_vector(1);reset();mutable_vector(0);reset();scalar_reread();return 0;
}
void _start(void){fx_exit(test_main());}
