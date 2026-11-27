/* Reconstructed ARM32 consumers only. All I/O/allocator/libc providers below
 * are SYNTHETIC. qemu executes our linked C, never original libyoyo bytes. */
#include "spine_read_mesh.h"
#include "spine_mesh.h"
#include "spine_color.h"
#include <stddef.h>
#include <stdint.h>
extern void *memcpy(void *,const void *,size_t);
extern void *memset(void *,int,size_t);
spSkeletonJson *spSkeletonJson_createWithLoader(void *);
void spSkeletonJson_dispose(spSkeletonJson *);
void __aeabi_memclr(void *p,size_t n) { memset(p,0,n); }
void __aeabi_memclr4(void *p,size_t n) { memset(p,0,n); }
void __aeabi_memclr8(void *p,size_t n) { memset(p,0,n); }
void __aeabi_memcpy4(void *p,const void *q,size_t n) { memcpy(p,q,n); }
static long sys3(long n,long a,long b,long c) {
    register long r7 __asm__("r7")=n,r0 __asm__("r0")=a;
    register long r1 __asm__("r1")=b,r2 __asm__("r2")=c;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r7),"r"(r1),"r"(r2) : "memory"); return r0;
}
size_t strlen(const char *s) { size_t n=0;while(s[n])++n;return n; }
char *strcpy(char *d,const char *s) { char *p=d;while((*d++=*s++)){}return p; }
int strcmp(const char *a,const char *b) { while(*a&&*a==*b){++a;++b;}return (unsigned char)*a-(unsigned char)*b; }
int strcasecmp(const char *a,const char *b) {
    for(;;) { unsigned x=(unsigned char)*a++,y=(unsigned char)*b++;
        if(x>='A'&&x<='Z')x+=32;if(y>='A'&&y<='Z')y+=32;
        if(x!=y||!x)return (int)x-(int)y; }
}
/* Imported strtoul boundary fixture, only two-character payloads from toColor.
 * Whitespace and optional sign follow libc; this is not a recovered libyoyo function. */
unsigned long strtoul(const char *s,char **end,int base) {
    const char *start=s;uint32_t v=0;int neg=0,any=0;(void)base;
    while(*s==' '||(*s>='\t'&&*s<='\r'))++s;
    if(*s=='-'||*s=='+'){neg=*s=='-';++s;}
    for(;;){unsigned c=(unsigned char)*s,d;
        if(c>='0'&&c<='9')d=c-'0';else if(c>='a'&&c<='f')d=c-'a'+10;
        else if(c>='A'&&c<='F')d=c-'A'+10;else break;
        any=1;v=v*16u+d;++s;
    }
    *end=(char *)(any?s:start);return neg?0u-v:v;
}
static void out(const char *s) { sys3(4,1,(long)(uintptr_t)s,strlen(s)); }
static void quit(int code) __attribute__((noreturn));
static void quit(int code) { sys3(1,code,0,0);for(;;){} }
static const char *test;
static void fail(const char *why) { out("FAIL ");out(test);out(": ");out(why);out("\n");quit(1); }
#define CK(x,why) do{if(!(x))fail(why);}while(0)
static void pass(const char *s) { out("PASS ");out(s);out("\n"); }
uintptr_t __stack_chk_guard=0xc2331111u;
void __stack_chk_fail(void) { fail("stack guard"); }
static uint32_t bits(float x) { uint32_t b;memcpy(&b,&x,4);return b; }
static float fb(uint32_t b) { float x;memcpy(&x,&b,4);return x; }
static uint32_t word(const void *p,unsigned i) { uint32_t w;memcpy(&w,(const char *)p+i*4,4);return w; }
static uint8_t *heap;static uint32_t used;
static void init_heap(void) {
    register long r7 __asm__("r7")=192,r0 __asm__("r0")=0;
    register long r1 __asm__("r1")=1<<20,r2 __asm__("r2")=3;
    register long r3 __asm__("r3")=34,r4 __asm__("r4")=-1,r5 __asm__("r5")=0;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r7),"r"(r1),"r"(r2),"r"(r3),"r"(r4),"r"(r5) : "memory");
    CK((uint32_t)r0<0xfffff001u,"mmap fixture heap");heap=(uint8_t *)(uintptr_t)r0;
}
static void *reserve(uint32_t n) {
    /* Oversized synthetic allocations support request-wrap and odd-count
     * footprint checks. They do NOT assert real malloc capacity/feasibility. */
    uint32_t cap=n>4096?128:(n<128?128:n);used=(used+7)&~7u;
    CK(used+cap<(1u<<20),"heap budget");void *p=heap+used;used+=cap;memset(p,0xee,cap);return p;
}
struct alloc { void *p;uint32_t bytes,line; };
static struct alloc aa[128];static void *ff[256];static unsigned na,nf,configured;
static unsigned mode;static spMeshAttachment *observed;static spSkeletonJson *parser;
static Json *tri_array,*uv_array;static Json *replacement_child;
static spLinkedMesh *copy_source;static void *uv_overlap;
static float replacement_uv[6];
void *malloc(uint32_t n) { return reserve(n); }
void free(void *p) {
    CK(nf<256,"free roster");ff[nf++]=p;
    if(mode==1&&observed) { observed->u=2;observed->v=3;observed->super.worldVerticesLength=2; }
    if(mode==3&&p==copy_source)parser->unk_10=1;
}
static void *record_alloc(uint32_t n,const char *tag,uint32_t line) {
    CK(na<128&&tag,"allocation roster/tag");void *p=reserve(n);
    if(line==64&&mode==2)p=uv_overlap;
    aa[na++]=(struct alloc){p,n,line};
    if(line==64&&mode==1){observed->u=4;observed->v=5;observed->u2=9;observed->v2=11;
        observed->rotate=1;observed->owned_58=replacement_uv;}
    if(line==136&&mode==3){CK(parser->unk_14==8,"capacity before grow callback");
        parser->unk_10=2;parser->unk_18=(uint32_t)(uintptr_t)copy_source;}
    if(line==935&&mode==4){CK(observed->opaque_60==1,"triangle count before malloc");tri_array->child=replacement_child;}
    if(line==941&&mode==5){uv_array->child=replacement_child;uv_array->unk_0c=2;}
    if(line==954)CK(observed&&observed->opaque_84==2,"edge count before malloc");
    return p;
}
static void begin(const char *name) { test=name;used=na=nf=configured=mode=0;observed=0;parser=0;
    _setDebugMalloc(record_alloc);_setFree(free); }
static struct alloc *find_line(unsigned line) { for(unsigned i=0;i<na;++i)if(aa[i].line==line)return &aa[i];fail("missing allocation line");return 0; }
static void configure(spAttachmentLoader *l,spAttachment *a) {
    (void)l;spMeshAttachment *m=(spMeshAttachment *)a;++configured;
    CK(m->super.worldVerticesLength==4&&m->opaque_78==3,"configure after geometry+hull");
}
static spAttachmentLoaderVtable lv={0,configure,0,0};
static spAttachmentLoader loader={0,0,&lv,0};
static spMeshAttachment *make_mesh(void) {
    spMeshAttachment *m=spMeshAttachment_create("mesh");
    m->u=.25f;m->v=.5f;m->u2=.75f;m->v2=1;return m;
}
static Json *node(const char *key) { Json *n=reserve(sizeof(*n));memset(n,0,sizeof(*n));n->name=key;return n; }
static void add(Json *map,Json *n) { Json **p=&map->child;while(*p)p=&(*p)->next;*p=n; }
static Json *floats(const char *name,const float *v,unsigned count,uint32_t declared) {
    Json *a=node(name);a->unk_0c=declared;for(unsigned i=0;i<count;++i){Json *n=node(0);memcpy(&n->float_value,v+i,4);add(a,n);}return a;
}
static Json *ints(const char *name,const int32_t *v,unsigned count,uint32_t declared) {
    Json *a=node(name);a->unk_0c=declared;for(unsigned i=0;i<count;++i){Json *n=node(0);n->int_value=v[i];add(a,n);}return a;
}
static Json *string(const char *name,const char *v) { Json *n=node(name);n->string_value=v;return n; }
static Json *basic_map(int edges) {
    Json *m=node(0);const int32_t tri[]={0,65537,-1},ev[]={-7,9};
    const float uv[]={0,.25f,1,.75f},xy[]={1,2,3,4};
    tri_array=ints("triangles",tri,3,1);add(m,tri_array); /* deliberately distinct capacity vs chain */
    uv_array=floats("uvs",uv,4,4);add(m,uv_array);add(m,floats("vertices",xy,4,4));
    Json *h=node("hull");h->int_value=3;add(m,h);if(edges)add(m,ints("edges",ev,2,2));return m;
}
static void check_color(void) {
    begin("color_strtoul_signed_and_s0");
    CK(bits(toColor("ff000000",0))==0x3f800000u,"hex channel");
    CK(bits(toColor("+1000000",0))==0x3b808081u,"plus accepted by strtoul");
    CK(bits(toColor(" 1000000",0))==0x3b808081u,"space accepted by strtoul");
    CK(bits(toColor("-1000000",0))==0xbb808081u,"signed VCVT after strtoul");
    CK(toColor("z1000000",0)==-1&&toColor("123",0)==-1,"parse and length failures");
    pass("color_strtoul_signed_and_s0");
}
static void uv_basic(void) {
    for(unsigned rotate=0;rotate<2;++rotate){begin("uv_two_modes");
        spMeshAttachment *m=make_mesh();float uv[]={0,.25f,1,.75f};m->super.worldVerticesLength=4;
        m->owned_58=uv;m->rotate=(int)rotate;na=nf=0;spMeshAttachment_updateUVs(m);
        const float a[]={.25f,.625f,.75f,.875f},b[]={.375f,1,.625f,.5f};
        for(unsigned i=0;i<4;++i)CK(word(m->owned_5c,i)==bits((rotate?b:a)[i]),"UV mapping bits");
        CK(na==1&&aa[0].line==64&&aa[0].bytes==16&&nf==1&&ff[0]==0,"free/allocate incl NULL");
    }pass("uv_rotated_and_unrotated");
}
static void uv_callback(void) {
    begin("uv_callback_snapshots");spMeshAttachment *m=make_mesh();float uv[]={0,.25f,1,.75f};
    m->super.worldVerticesLength=4;m->owned_58=uv;observed=m;mode=1;
    replacement_uv[0]=0;replacement_uv[1]=.25f;replacement_uv[2]=1;replacement_uv[3]=.75f;na=nf=0;
    spMeshAttachment_updateUVs(m);mode=0;
    const float want[]={4.125f,5.5f,4.375f,5};
    CK(aa[0].bytes==16,"world length cached before free");
    for(unsigned i=0;i<4;++i)CK(word(m->owned_5c,i)==bits(want[i]),"stale spans/live bases/rotate/source");
    pass("uv_callback_snapshot_and_live_reloads");
}
static void uv_alias(void) {
    for(unsigned rotate=0;rotate<2;++rotate){begin("uv_overlapping_source_destination");spMeshAttachment *m=make_mesh();
        float source[]={.5f,.25f,1,.75f,0,0};m->owned_58=source;m->super.worldVerticesLength=4;m->rotate=(int)rotate;
        mode=2;uv_overlap=source+1;spMeshAttachment_updateUVs(m);mode=0;
        const float a[]={.5f,.75f,.625f,.8125f},b[]={.375f,.75f,.625f,.625f};
        for(unsigned i=0;i<4;++i)CK(word(m->owned_5c,i)==bits((rotate?b:a)[i]),"store before next source read");
    }pass("uv_overlap_preserves_instruction_read_write_order");
}
static void uv_counts(void) {
    for(unsigned k=0;k<3;++k){begin("uv_nonpositive_odd");spMeshAttachment *m=make_mesh();float uv[]={0,.25f,1,.75f};
        uint32_t n=k==0?0:k==1?0xffffffffu:3;m->super.worldVerticesLength=n;m->owned_58=uv;na=nf=0;
        spMeshAttachment_updateUVs(m);CK(aa[0].bytes==(n<<2)&&nf==1,"wrap request even when nonpositive");
        CK(word(m->owned_5c,3)==(k==2?bits(.875f):0xeeeeeeeeu),"odd rounds pairs up, nonpositive no writes");
    }pass("uv_zero_negative_and_odd_pair_footprint");
}
static void uv_fp(void) {
    begin("uv_vmla_not_fma");spMeshAttachment *m=make_mesh();float uv[]={fb(0x3f7ffffeu),0};
    m->u=-1;m->u2=fb(0x34000000u);m->owned_58=uv;m->super.worldVerticesLength=2;spMeshAttachment_updateUVs(m);
    CK(word(m->owned_5c,0)==0,"VMLA rounds multiply before addition");
    m->rotate=1;m->v=fb(0xb4000000u);m->v2=1;spMeshAttachment_updateUVs(m);
    CK(word(m->owned_5c,1)==0,"VMLS rounds multiply before subtraction");
    pass("uv_vmla_vmls_nonfused_rounding");
    begin("uv_empty_snan");m=make_mesh();m->u=fb(0x7f800001u);m->super.worldVerticesLength=0;
    uint32_t z=0,f;__asm__ volatile("vmsr fpscr,%0"::"r"(z):"memory");spMeshAttachment_updateUVs(m);
    __asm__ volatile("vmrs %0,fpscr":"=r"(f)::"memory");CK(f&1,"spans computed even on empty mesh");
    __asm__ volatile("vmsr fpscr,%0"::"r"(z):"memory");pass("uv_empty_snan_span_computation");
}
static void parent_mesh(void) {
    begin("parent_sharing");spMeshAttachment *p=make_mesh(),*c=make_mesh();
    float vertices[4]={1,2,3,4},uv[4]={0,0,1,1};int32_t bones[3]={1,2,3},edges[2]={8,9};uint16_t tri[3]={0,1,2};
    p->super.worldVerticesLength=4;p->super.opaque_10=3;p->super.owned_14=bones;p->super.opaque_18=4;p->super.owned_1c=vertices;
    p->owned_58=uv;p->owned_64=tri;p->opaque_60=3;p->opaque_78=2;p->owned_88=edges;p->opaque_84=2;
    p->opaque_8c=bits(32);p->opaque_90=bits(64);c->opaque_80=7;c->r=.25f;c->u=.125f;na=nf=0;
    spMeshAttachment_setParentMesh(c,p);
    CK(c->parentMesh==p&&c->super.worldVerticesLength==4&&c->super.owned_14==bones&&c->super.opaque_10==3&&c->super.opaque_18==4&&c->super.owned_1c==vertices,"vertex sharing");
    CK(c->owned_58==uv&&c->owned_64==tri&&c->opaque_60==3&&c->opaque_78==2&&c->owned_88==edges&&c->opaque_84==2,"mesh sharing");
    CK(c->opaque_8c==bits(32)&&c->opaque_90==bits(64)&&c->opaque_80==7&&c->r==.25f&&c->u==.125f,"dimensions copied, independent metadata preserved");
    CK(na==0&&nf==0,"setter no allocator effects");spMeshAttachment snapshot=*c;
    spMeshAttachment_setParentMesh(c,0);snapshot.parentMesh=0;
    for(unsigned i=0;i<sizeof(*c)/4;++i)CK(word(c,i)==word(&snapshot,i),"NULL parent only clears pointer");
    pass("parent_mesh_shares_geometry_null_keeps_fields");
}
static void parse_mesh(int with_edges,unsigned cbmode) {
    begin("mesh_consumer_chain");Json *map=basic_map(with_edges);spMeshAttachment *m=make_mesh();observed=m;
    spSkeletonJson *j=spSkeletonJson_createWithLoader(&loader);j->scale=bits(2);parser=j;na=nf=0;mode=cbmode;
    if(cbmode==4){replacement_child=node(0);replacement_child->int_value=70001;}
    if(cbmode==5){const float a[]={.5f,.5f,.25f,.25f};Json *x=floats(0,a,4,4);replacement_child=x->child;}
    CK(readSkeletonData_meshFields(map,m,"asset",j,9)==0,"unlinked branch");mode=0;
    CK(configured==1&&m->opaque_8c==bits(64)&&m->opaque_90==bits(64),"default dimensions and configure");
    CK(find_line(917)->bytes==6&&find_line(935)->bytes==2&&find_line(941)->bytes==16,"original request units/lines");
    CK(((uint16_t *)m->owned_64)[0]==(cbmode==4?(uint16_t)70001:0),"triangle callback child reload");
    if(cbmode!=4)CK(((uint16_t *)m->owned_64)[1]==1&&((uint16_t *)m->owned_64)[2]==65535,"triangle follows chain/truncates halfword");
    CK(m->super.worldVerticesLength==4&&m->super.opaque_18==4&&word(m->super.owned_1c,0)==bits(2)&&word(m->super.owned_1c,3)==bits(8),"actual readVertices dependency");
    CK(word(m->owned_58,0)==bits(cbmode==5?.5f:0),"UV child after allocator; cached UV count still 4");
    CK(m->opaque_78==3,"hull raw integer, NOT doubled");
    if(with_edges)CK(m->opaque_84==2&&((int32_t *)m->owned_88)[0]==-7,"optional edge copy");
    else CK(m->opaque_84==0&&m->owned_88==0,"absent edges untouched");
    void *own[]={m->owned_54,m->owned_58,m->owned_5c,m->owned_64,m->owned_88,m->super.owned_1c};
    spAttachment_dispose(&m->super.super);
    for(unsigned k=0;k<6;++k)if(own[k]){unsigned hits=0;for(unsigned i=0;i<nf;++i)hits+=ff[i]==own[k];CK(hits==1,"real destructor frees owned arrays once");}
    spSkeletonJson_dispose(j);
    pass(cbmode==4?"mesh_triangle_allocator_rereads_child":cbmode==5?"mesh_uv_allocator_rereads_child_caches_count":with_edges?"mesh_full_consumer_and_real_cleanup":"mesh_absent_optional_edges");
}
static spLinkedMesh *links(spSkeletonJson *j) { return (spLinkedMesh *)(uintptr_t)j->unk_18; }
static Json *link_map(void) { Json *m=node(0);add(m,string("parent","P"));return m; }
static void linked_queue(void) {
    begin("linked_queue_growth");spSkeletonJson *j=spSkeletonJson_createWithLoader(&loader);parser=j;Json *map=link_map();
    for(unsigned i=0;i<9;++i){spMeshAttachment *m=make_mesh();observed=m;
        CK(readSkeletonData_meshFields(map,m,"asset",j,i)==1,"deferred linked branch");
        CK(m->opaque_80==1&&m->owned_58==0&&m->owned_5c==0&&configured==0,"deform default; defer geometry/configure");
        CK(j->unk_10==i+1&&links(j)[i].slotIndex==i&&links(j)[i].mesh==m&&links(j)[i].skin==0&&strcmp(links(j)[i].parent,"P")==0,"queue record fields");
    }
    CK(j->unk_14==16&&links(j)[0].slotIndex==0,"second grow preserves earlier entry");
    unsigned ng=0;for(unsigned i=0;i<na;++i)if(aa[i].line==136){CK(aa[i].bytes==(ng?256:128),"grow bytes");++ng;}CK(ng==2,"first and ninth grow only");
    pass("linked_queue_first_and_capacity_growth");
    /* Bind sharing helpers to actual constructors/destructors. This manually
     * selects a parent; it is NOT the still-missing original name postpass. */
    spMeshAttachment *parent=links(j)[0].mesh,*child=links(j)[1].mesh;
    parent->super.worldVerticesLength=2;parent->owned_58=reserve(8);float uv[2]={.5f,.25f};memcpy(parent->owned_58,uv,8);
    spMeshAttachment_setParentMesh(child,parent);spMeshAttachment_updateUVs(child);void *shared=parent->owned_58;
    nf=0;spAttachment_dispose(&child->super.super);for(unsigned i=0;i<nf;++i)CK(ff[i]!=shared,"linked destructor must not free shared UVs");
    spAttachment_dispose(&parent->super.super);unsigned hits=0;for(unsigned i=0;i<nf;++i)hits+=ff[i]==shared;CK(hits==1,"parent frees shared UVs once");
    spSkeletonJson_dispose(j);pass("linked_geometry_ownership_real_destructors");
}
static void queue_callback(void) {
    begin("linked_queue_allocator_reload");spSkeletonJson *j=spSkeletonJson_createWithLoader(&loader);parser=j;
    Json *map=link_map();spMeshAttachment *m=make_mesh();observed=m;copy_source=reserve(128);memset(copy_source,0,128);
    copy_source[0].slotIndex=42;copy_source[1].slotIndex=43;mode=3;
    CK(readSkeletonData_meshFields(map,m,"asset",j,7)==1,"linked result");mode=0;
    CK(j->unk_10==2&&links(j)[0].slotIndex==42&&links(j)[1].slotIndex==7,"count/base after malloc then count after free");
    CK(nf==1&&ff[0]==copy_source,"free reloaded old array");
    pass("linked_queue_callback_rereads_count_and_source");
    begin("linked_parent_key_presence");j=spSkeletonJson_createWithLoader(&loader);map=basic_map(0);add(map,string("parent",0));
    m=make_mesh();CK(readSkeletonData_meshFields(map,m,"asset",j,0)==1&&links(j)[0].parent==0,"parent Json presence, not string truth");
    pass("linked_parent_json_presence_even_null_string");
}
void _start(void) {
    test="startup";init_heap();check_color();uv_basic();uv_callback();uv_alias();uv_counts();uv_fp();parent_mesh();
    parse_mesh(1,0);parse_mesh(0,0);parse_mesh(0,4);parse_mesh(0,5);linked_queue();queue_callback();
    out("SUMMARY all declared reconstructed mesh contracts passed\n");quit(0);
}
