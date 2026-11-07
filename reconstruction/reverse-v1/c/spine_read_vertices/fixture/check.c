/* Reconstructed ARM32 consumer only. Providers below are explicit fixtures;
 * no original DSO/ART/Unicorn is loaded. Each PASS names its tested contract. */
#include "spine_read_bbox_path.h"
#include <stddef.h>
#include <stdint.h>
extern void *memcpy(void *, const void *, size_t);
extern void *memset(void *, int, size_t);
void __aeabi_memclr(void *p, size_t n) { memset(p, 0, n); }
void __aeabi_memclr4(void *p, size_t n) { memset(p, 0, n); }
void __aeabi_memclr8(void *p, size_t n) { memset(p, 0, n); }
static long sys3(long n, long a, long b, long c) {
    register long r7 __asm__("r7")=n, r0 __asm__("r0")=a;
    register long r1 __asm__("r1")=b, r2 __asm__("r2")=c;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r7),"r"(r1),"r"(r2) : "memory");
    return r0;
}
static void out(const char *s) { size_t n=0; while(s[n]) ++n; sys3(4,1,(long)(uintptr_t)s,n); }
static void quit(int code) __attribute__((noreturn));
static void quit(int code) { sys3(1,code,0,0); for(;;){} }
static const char *test_name;
static void fail(const char *s) { out("FAIL ");out(test_name);out(": ");out(s);out("\n");quit(1); }
#define CK(x,s) do {if(!(x)) fail(s);} while(0)
static void pass(const char *s) { out("PASS ");out(s);out("\n"); }
static uint8_t *heap;
static uint32_t used;
static void init_heap(void) {
    register long r7 __asm__("r7")=192, r0 __asm__("r0")=0;
    register long r1 __asm__("r1")=1<<20, r2 __asm__("r2")=3;
    register long r3 __asm__("r3")=34, r4 __asm__("r4")=-1, r5 __asm__("r5")=0;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r7),"r"(r1),"r"(r2),"r"(r3),"r"(r4),"r"(r5) : "memory");
    CK((uint32_t)r0 < 0xfffff001u,"mmap fixture heap"); heap=(uint8_t *)(uintptr_t)r0;
}
struct allocation { void *p; uint32_t size,line; };
static struct allocation allocations[96];
static void *freed[96];
static uint32_t na,nf;
static spVertexAttachment *active_a;
static uint32_t expected_world, mutate_count, mutate_child;
static Json *array_to_change, *replacement_child;
static spPathAttachment *active_path;
static uint32_t expected_lengths;
static void *reserve(uint32_t size) {
    /* Synthetic provider intentionally accepts oversized/zero requests. That
     * case tests request bytes/control flow, not real malloc feasibility. */
    uint32_t capacity=size>4096u ? 64u : (size<64u ? 64u : size);
    used=(used+7u)&~7u; CK(used+capacity<(1u<<20),"heap capacity");
    void *p=heap+used; used+=capacity; memset(p,0xee,capacity); return p;
}
void *malloc(uint32_t size) { return reserve(size); }
void free(void *p) { CK(nf<96,"free log capacity"); freed[nf++]=p; }
static void *record_alloc(uint32_t size, const char *tag, uint32_t line) {
    CK(na<96 && tag,"allocation log and tag");
    void *p=reserve(size); allocations[na++]=(struct allocation){p,size,line};
    if(line==513u) {
        CK(active_a && active_a->worldVerticesLength==expected_world,"entry write precedes allocator");
        if(mutate_child) array_to_change->child=replacement_child;
    }
    if(line==537u && mutate_count) active_a->opaque_10=7u;
    if(line==985u) CK(active_path && active_path->opaque_24==expected_lengths,"length count before malloc");
    return p;
}
size_t strlen(const char *s) { size_t n=0; while(s[n]) ++n; return n; }
char *strcpy(char *d,const char *s) { char *start=d; while((*d++=*s++)){} return start; }
int strcasecmp(const char *a,const char *b) {
    while(*a && *b) {
        unsigned x=(unsigned char)*a++,y=(unsigned char)*b++;
        if(x>='A' && x<='Z') x+=32;
        if(y>='A' && y<='Z') y+=32;
        if(x!=y) return (int)x-(int)y;
    }
    return (unsigned char)*a-(unsigned char)*b;
}
uintptr_t __stack_chk_guard=0xa5c31111u;
void __stack_chk_fail(void) { fail("stack guard"); }
static uint32_t bits(float f) { uint32_t v; memcpy(&v,&f,4); return v; }
static float float_bits(uint32_t v) { float f; memcpy(&f,&v,4); return f; }
static uint32_t word(const void *p,unsigned i) { uint32_t v; memcpy(&v,(const uint8_t *)p+4*i,4); return v; }
static void begin(const char *name) {
    test_name=name; used=na=nf=0; active_a=0; active_path=0;
    mutate_count=mutate_child=0; _setDebugMalloc(record_alloc); _setFree(free);
}
static Json *make_map(const uint32_t *words,uint32_t n,uint32_t declared,Json **array) {
    Json *map=reserve(sizeof(Json)), *a=reserve(sizeof(Json));
    memset(map,0,sizeof(*map));memset(a,0,sizeof(*a));
    map->child=a;a->name="VERTICES";a->unk_0c=declared;
    Json **next=&a->child;
    for(uint32_t i=0;i<n;++i) {
        Json *v=reserve(sizeof(Json));memset(v,0,sizeof(*v));
        v->float_value=float_bits(words[i]); *next=v; next=&v->next;
    }
    *array=a; return map;
}
static void direct_unweighted(uint32_t scale_bits) {
    begin("unweighted");
    const uint32_t raw[]={0x3fc00000u,0xc0000000u,0x80000000u,0x40600000u};
    Json *array,*map=make_map(raw,4,4,&array); (void)array;
    spVertexAttachment a={0}; a.opaque_10=0xeeeeeeeeu; a.owned_14=(void *)0x1110u;
    active_a=&a;expected_world=4;float scale=float_bits(scale_bits);
    _readVertices(&scale,map,&a,4);
    CK(na==1&&allocations[0].size==16&&allocations[0].line==513,"one source allocation");
    CK(a.owned_1c==allocations[0].p && a.opaque_18==4 && a.opaque_10==0 && a.owned_14==0,"unweighted layout/ownership");
    CK(nf==0,"unweighted not freed");
    const uint32_t twice[]={0x40400000u,0xc0800000u,0x80000000u,0x40e00000u};
    for(unsigned i=0;i<4;++i) CK(word(a.owned_1c,i)==(scale_bits==0x3f800000u?raw[i]:twice[i]),"coordinate bits");
    pass(scale_bits==0x3f800000u?"unweighted_unit_bitcopy":"unweighted_binary32_scale");
}
static void unit_nan_copy(void) {
    begin("unit_nan_copy");const uint32_t raw[]={0x7f800001u,0xffc12345u};
    Json *array,*map=make_map(raw,2,2,&array);(void)array;
    spVertexAttachment a={0};active_a=&a;expected_world=2;float scale=1;
    _readVertices(&scale,map,&a,2);
    CK(word(a.owned_1c,0)==raw[0]&&word(a.owned_1c,1)==raw[1],"unit scale must not quiet NaN");
    pass("unit_scale_skips_snan_multiply");
}
static void weighted(void) {
    begin("weighted_zero_group");
    const uint32_t raw[]={
        0x40000000u,0x40400000u,0x3fc00000u,0xc0000000u,0x3e800000u,
        0xc0980000u,0x80000000u,0x40500000u,0x3f400000u,
        0u,0x3f800000u,0x411e6666u,0x41000000u,0xbf800000u,0x7fc12345u};
    Json *array,*map=make_map(raw,15,15,&array);(void)array;
    spVertexAttachment a={0};active_a=&a;expected_world=6;float scale=2;
    _readVertices(&scale,map,&a,6);
    CK(na==3&&allocations[0].size==60&&allocations[1].size==36&&allocations[2].size==24,"weighted allocation sizes");
    CK(allocations[1].line==537&&allocations[2].line==538,"weighted source lines");
    CK(a.opaque_10==6&&a.opaque_18==9&&a.worldVerticesLength==6,"weighted count fields");
    const uint32_t bones[]={2,3,0xfffffffcu,0,1,9};
    const uint32_t verts[]={0x40400000u,0xc0800000u,0x3e800000u,0x80000000u,0x40d00000u,0x3f400000u,0x41800000u,0xc0000000u,0x7fc12345u};
    for(unsigned i=0;i<6;++i) CK(word(a.owned_14,i)==bones[i],"bone stream incl zero group");
    for(unsigned i=0;i<9;++i) CK(word(a.owned_1c,i)==verts[i],"x/y scaled, weight raw");
    CK(nf==1&&freed[0]==allocations[0].p,"weighted frees temporary only");
    pass("weighted_stream_zero_group_and_raw_weight");
}
static void conversion_indices(void) {
    const uint32_t input[]={0x7fc12345u,0x7f800000u,0xff800000u,0xc0980000u};
    const uint32_t want[]={0,0x7fffffffu,0x80000000u,0xfffffffcu};
    for(unsigned k=0;k<4;++k) {
        begin("vcvt_index");uint32_t raw[]={0x3ff33333u,input[k],0x3f800000u,0x40000000u,0x3f000000u};
        Json *array,*map=make_map(raw,5,5,&array);(void)array;
        spVertexAttachment a={0};active_a=&a;expected_world=2;float scale=1;
        _readVertices(&scale,map,&a,2);
        CK(a.opaque_10==2&&word(a.owned_14,0)==1&&word(a.owned_14,1)==want[k],"VCVT signed saturation/truncation");
    }
    pass("vfp_count_fraction_and_index_nan_inf_truncation");
}
static void nonpositive(void) {
    for(unsigned k=0;k<4;++k) {
        begin("nonpositive");uint32_t size=(k&1)?0xffffffffu:0u,world=(k&2)?2u:size;
        Json *array,*map=make_map(0,0,size,&array);(void)array;
        spVertexAttachment a={0};active_a=&a;expected_world=world;float scale=2;
        _readVertices(&scale,map,&a,world);
        CK(allocations[0].size==(size<<2),"wrapping request size");
        if(size==world) CK(na==1&&nf==0&&a.opaque_18==size,"nonpositive unweighted transfer");
        else CK(na==3&&nf==1&&a.opaque_10==0&&a.opaque_18==0&&allocations[1].size==0&&allocations[2].size==0,"nonpositive weighted still alloc/free");
    }
    pass("empty_and_signed_nonpositive_both_branches");
}
static void empty_snan_compare(void) {
    begin("empty_snan_compare");
    Json *array,*map=make_map(0,0,0,&array);(void)array;
    spVertexAttachment a={0};active_a=&a;expected_world=0;
    float scale=float_bits(0x7f800001u);uint32_t zero=0,flags;
    __asm__ volatile("vmsr fpscr, %0" : : "r"(zero) : "memory");
    _readVertices(&scale,map,&a,0);
    __asm__ volatile("vmrs %0, fpscr" : "=r"(flags) : : "memory");
    CK(flags&1u,"unconditional scale comparison sets FPSCR invalid on sNaN");
    __asm__ volatile("vmsr fpscr, %0" : : "r"(zero) : "memory");
    pass("empty_unweighted_snan_comparison_is_not_elided");
}
static void callback_reread(void) {
    begin("allocator_count_reread");const uint32_t raw[]={0x3f800000u,0x40a00000u,0x3f800000u,0x40000000u,0x3f000000u};
    Json *array,*map=make_map(raw,5,5,&array);(void)array;
    spVertexAttachment a={0};active_a=&a;expected_world=2;mutate_count=1;float scale=1;
    _readVertices(&scale,map,&a,2);
    CK(allocations[2].size==28&&a.opaque_10==7,"count reloaded after line537 callback");
    pass("allocator_mutation_count_reread");
}
static void child_reread(void) {
    begin("allocator_child_reread");const uint32_t raw[]={0x3f800000u,0x40000000u};
    Json *array,*map=make_map(raw,2,2,&array);
    Json replacement[2]={{0}}; replacement[0].float_value=3;replacement[1].float_value=4;replacement[0].next=&replacement[1];
    array_to_change=array;replacement_child=replacement;mutate_child=1;
    spVertexAttachment a={0};active_a=&a;expected_world=2;float scale=1;
    _readVertices(&scale,map,&a,2);
    CK(word(a.owned_1c,0)==bits(3)&&word(a.owned_1c,1)==bits(4),"child read after first malloc");
    pass("allocator_mutation_child_reread");
}
static unsigned configured;
static void configure(spAttachmentLoader *loader,spAttachment *a) {
    CK(loader&&a,"configure ABI");spVertexAttachment *v=(spVertexAttachment *)a;
    CK(v->opaque_18==2&&v->worldVerticesLength==2,"bbox posthelper write visible to configure");++configured;
}
static void consumers(void) {
    begin("bbox_real_chain");
    const uint32_t raw[]={0x3f800000u,0x40000000u,0x3f800000u,0x40000000u,0x3f000000u};
    Json *array,*map=make_map(raw,5,5,&array);(void)array;
    Json count={0};count.name="vertexCount";count.int_value=1;map->child->next=&count;
    spBoundingBoxAttachment *bbox=spBoundingBoxAttachment_create("bbox");
    active_a=&bbox->super;expected_world=2;float scale=2;
    spAttachmentLoaderVtable vt={0};vt.configureAttachment=configure;
    spAttachmentLoader loader={0};loader.vtable=&vt;configured=0;na=nf=0;
    readSkeletonData_boundingBoxFields(map,bbox,&scale,&loader);
    CK(configured==1&&bbox->super.opaque_18==2,"bbox overwrites weighted float count as original");
    void *bones=bbox->super.owned_14,*vertices=bbox->super.owned_1c;
    _spBoundingBoxAttachment_dispose(&bbox->super.super);
    CK(nf==6&&freed[3]==bones&&freed[4]==vertices&&freed[5]==bbox,"real destructor owns both buffers");
    pass("bbox_constructor_read_configure_real_dispose");

    begin("path_real_chain");
    const uint32_t xyz[]={0x3f800000u,0x40000000u,0x40400000u,0x40800000u,0x40a00000u,0x40c00000u};
    map=make_map(xyz,6,6,&array);
    Json fields[4]={{0}};fields[0].name="vertexCount";fields[0].int_value=3;
    fields[1].name="closed";fields[1].int_value=1;fields[2].name="lengths";
    fields[3].float_value=2.5f;fields[2].child=&fields[3];
    array->next=&fields[0];fields[0].next=&fields[1];fields[1].next=&fields[2];
    spPathAttachment *path=spPathAttachment_create("path");
    active_a=&path->super;active_path=path;expected_world=6;expected_lengths=1;na=nf=0;
    readSkeletonData_pathAttachmentFields(map,path,&scale);
    CK(path->opaque_2c==1&&path->opaque_30==1&&path->opaque_24==1,"path flags/default/division");
    CK(na==2&&allocations[1].line==985&&allocations[1].size==4&&word(path->owned_28,0)==bits(5),"path lengths real scale");
    _spPathAttachment_dispose(&path->super.super);
    CK(nf==6&&freed[3]==path->super.owned_1c&&freed[4]==path->owned_28&&freed[5]==path,"path full ownership chain");
    pass("path_constructor_vertices_lengths_real_dispose");
}
void _start(void) {
    test_name="setup";init_heap();
    direct_unweighted(0x3f800000u);direct_unweighted(0x40000000u);unit_nan_copy();
    weighted();conversion_indices();nonpositive();empty_snan_compare();callback_reread();child_reread();consumers();
    out("SUMMARY all declared reconstructed contracts passed; ORIGINAL NOT EXECUTED\n");quit(0);
}
