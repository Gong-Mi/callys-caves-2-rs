/* Slots segment outer loop (0x28bbe4-0x28bdd8) — real reconstructed chain:
 * slotsArray -> Json_getString/findBone condition -> oneSlot body ->
 * spSkeletonData_dispose -> _spSkeletonJson_setError -> ReportSpineError
 * (typed console vcall) -> Json_dispose(root).
 * Synthetic boundaries ONLY where no recovered body exists in the base tree:
 * spSlotData_create / spSlotData_setAttachmentName (SlotData.c), the fixture
 * heap, libc string providers, and the console object installed into dbg_csol
 * (via the shared reporter_adapter.c — the vcall itself is the real
 * ReportSpineError). Line-651 allocations are filled with a pointer to a
 * zeroed 16-byte record: that is a synthetic heap state so the REAL dispose
 * can walk the unpublished tail without faulting; the original's behavior on
 * malloc garbage there is undefined and is NOT asserted. Original not
 * executed; nothing here is an original-equivalence claim. */
#define _start mesh_fixture_unused_start
#include "../../spine_read_mesh/fixture/check.c"
#undef _start
#include "spine_read_slots.h"
#include "../../spine_json_error/src/spine_json_error.h"
#include "../../skeleton_find/src/skeleton_find.h"

/* Console adapter lives in spine_linked_postpass/fixture/reporter_adapter.c
 * (compiled as a separate translation unit). */
extern void fixture_install_error_reporter(void);

struct ProbeSlot { int32_t index;const char *name;void *bone;char *attachment;float r,g,b,a;int32_t blend; };
static struct ProbeSlot probes[4];
static spSkeletonJson seg_parser;
static unsigned report_count;
static char reported[512],report_format[128];
static void *safe_cell;

/* Multi-slot synthetic creator: one distinct probe per index, so publication
 * order and 0-based indexing are observable. Declared boundary, not a
 * recovered creator. */
void *spSlotData_create(int i,const char *n,void *b) {
    if((unsigned)i>=4)fail("probe table exhausted");
    struct ProbeSlot *p=&probes[i];
    memset(p,0,sizeof(*p));p->index=i;p->name=n;p->bone=b;p->r=p->g=p->b=p->a=1;
    return p;
}
void spSlotData_setAttachmentName(void *s,const char *n) {
    struct ProbeSlot *p=s;p->attachment=(char *)n;
}
/* setError imports strncat; the mesh fixture runtime has no strncat. */
char *strncat(char *d,const char *s,size_t n) {
    char *r=d;d+=strlen(d);while(n--&&*s)*d++=*s++;*d=0;return r;
}
/* Module seam: oneSlot's blend chain calls the _strcmp alias (original is
 * strcmp@plt); forward to the fixture strcmp. */
int _strcmp(const char *a,const char *b) { return strcmp(a,b); }
/* Real ReportSpineError sink (adapter lives in reporter_adapter.c). */
void fixture_report_sink(const char *fmt,const char *message) {
    ++report_count;strcpy(report_format,fmt);strcpy(reported,message);
}

/* Custom allocator: same roster as the mesh fixture, plus a synthetic
 * zeroed-record fill for the line-651 slots array (see header note). */
static void *seg_alloc(uint32_t n,const char *tag,uint32_t line) {
    CK(na<128&&tag,"segment allocation roster/tag");
    void *p=reserve(n);
    if(line==651) { uint32_t i=0;while(i+4<=n) { *(void **)((char *)p+i)=safe_cell;i+=4; } }
    aa[na++]=(struct alloc){p,n,line};
    return p;
}
static unsigned alloc_count(uint32_t line) {
    unsigned c=0;for(unsigned i=0;i<na;++i)if(aa[i].line==line)++c;return c;
}
static int freed(void *p) {
    for(unsigned i=0;i<nf;++i)if(ff[i]==p)return 1;return 0;
}
static void seg_begin(const char *name) {
    begin(name);_setDebugMalloc(seg_alloc);
    report_count=0;reported[0]=report_format[0]=0;
    memset(&seg_parser,0,sizeof(seg_parser));memset(probes,0,sizeof(probes));
}
/* Fake bone record: findBone (real) reads the name word at +4; dispose (real)
 * frees +4 then the record — roster free, so constants are safe. */
static void *make_bone(const char *name) {
    void **b=reserve(8);b[1]=(void *)(uintptr_t)name;return b;
}
static spSkeletonData *make_data(void **bones,unsigned count) {
    spSkeletonData *d=spSkeletonData_create();   /* real calloc(1,84,tag,37) */
    d->words[4]=count;d->words[5]=(uint32_t)(uintptr_t)bones;
    return d;
}
static Json *slot_node(const char *name,const char *bone) {
    Json *m=node(0);add(m,string("name",name));add(m,string("bone",bone));return m;
}

static void segment_absent(void) {
    seg_begin("segment_absent");
    Json *tree=node(0);                              /* no "slots" key */
    spSkeletonData *d=make_data(0,0);
    CK(readSkeletonData_slotsSegment(tree,d,&seg_parser)==1,"SEG absent key returns 1");
    CK(d->words[6]==0&&d->words[7]==0,"SEG absent leaves count and array untouched");
    CK(alloc_count(651)==0,"SEG absent performs no slots-array malloc");
    CK(report_count==0,"SEG absent reports nothing");
    pass("segment_absent");
}
static void segment_empty_children(void) {
    seg_begin("segment_empty_children");
    Json *slots=node("slots");slots->unk_0c=2;       /* declared count, no child */
    Json *tree=node(0);add(tree,slots);
    spSkeletonData *d=make_data(0,0);
    CK(readSkeletonData_slotsSegment(tree,d,&seg_parser)==1,"SEG empty children returns 1");
    CK(d->words[6]==2&&d->words[7]!=0,"SEG empty children still publish declared count and array");
    CK(alloc_count(651)==1,"SEG empty children allocates the array (malloc line 651)");
    CK(probes[0].name==0&&probes[1].name==0,"SEG empty children skips the loop (no slot created)");
    pass("segment_empty_children");
}
static void segment_success(void) {
    seg_begin("segment_success");
    void *bones[2];bones[0]=make_bone("B0");bones[1]=make_bone("B1");
    Json *s0=slot_node("N0","B0");add(s0,string("color","ffffffff"));add(s0,string("attachment","gun"));
    Json *s1=slot_node("N1","B1");add(s1,string("blend","additive"));
    Json *slots=node("slots");slots->unk_0c=2;add(slots,s0);add(slots,s1);
    Json *tree=node(0);add(tree,slots);
    spSkeletonData *d=make_data(bones,2);
    CK(readSkeletonData_slotsSegment(tree,d,&seg_parser)==1,"SEG success returns 1");
    void **arr=(void *)(uintptr_t)d->words[7];
    CK(d->words[6]==2,"SEG success publishes the declared count");
    CK(arr[0]==&probes[0]&&arr[1]==&probes[1],"SEG success publishes both slots in order");
    CK(probes[0].index==0&&probes[1].index==1,"SEG creator receives 0-based slot index");
    CK(probes[0].name&&strcmp(probes[0].name,"N0")==0&&probes[0].bone==bones[0],"SEG slot0 name and bone");
    CK(probes[0].r==1.0f&&probes[0].g==1.0f&&probes[0].b==1.0f&&probes[0].a==1.0f,"SEG color flows through real toColor");
    CK(probes[0].attachment&&strcmp(probes[0].attachment,"gun")==0,"SEG attachment name forwarded");
    CK(probes[1].blend==1,"SEG blend mapping intact through the chain (additive is 1)");
    CK(nf==0,"SEG success frees nothing");
    CK(report_count==0,"SEG success reports nothing");
    pass("segment_success");
}
static void segment_error(void) {
    seg_begin("segment_error");
    void *bones[1];bones[0]=make_bone("B0");
    Json *s0=slot_node("N0","B0");
    Json *s1=slot_node("N1","missing");             /* bone lookup fails */
    Json *slots=node("slots");slots->unk_0c=2;add(slots,s0);add(slots,s1);
    Json *tree=node(0);add(tree,slots);
    spSkeletonData *d=make_data(bones,1);
    CK(readSkeletonData_slotsSegment(tree,d,&seg_parser)==0,"SEG returns 0 when a slot bone is missing");
    void **arr=(void *)(uintptr_t)d->words[7];      /* disposed memory; fixture observability only */
    CK(arr[0]==&probes[0]&&arr[1]==safe_cell,"SEG slot1 published, slot2 not published (condition-first)");
    CK(d->words[6]==2,"SEG count was published before the loop");
    CK(freed(&probes[0])==1,"SEG dispose frees the published slot and bones");
    CK(freed(bones[0])==1,"SEG dispose frees the bone record");
    CK(freed(tree)==1,"SEG root tree disposed via setError");
    CK(report_count==1&&strcmp(report_format,"Spine Error:%s\n")==0,"SEG report format via real console vcall");
    CK(report_count==1&&strcmp(reported,"Slot bone not found: missing")==0,"SEG error message exact");
    CK(seg_parser.error!=0&&strcmp((char *)(uintptr_t)seg_parser.error,"Slot bone not found: missing")==0,"SEG parser error set to the formatted message");
    CK(alloc_count(90)==1,"SEG setError owns a line-90 error copy");
    pass("segment_error");
}
void _start(void) {
    test="startup";init_heap();
    safe_cell=reserve(16);                            /* zeroed by reserve's 0xee fill? no: fill explicitly */
    memset(safe_cell,0,16);
    fixture_install_error_reporter();
    segment_absent();segment_empty_children();segment_success();segment_error();
    out("SUMMARY all declared slots segment contracts passed\n");quit(0);
}
