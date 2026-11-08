/* Reconstructed region consumer tests. Libm is an explicit synthetic input
 * boundary: cos/sin return values below are prescribed, NOT original outputs.
 * Only this new _start runs; the reused fixture's old entry is dead-stripped. */
#define _start mesh_fixture_unused_start
#define strcpy region_fixture_strcpy
#define strcasecmp region_fixture_strcasecmp
#define strlen region_fixture_strlen
#include "../../spine_read_mesh/fixture/check.c"
#undef _start
#undef strcpy
#undef strcasecmp
#undef strlen
#include "spine_read_region.h"

/* Generic factory's other type branches link sprintf. Type-0 tests must never
 * take them; reject rather than manufacture a formatted error/success. */
int sprintf(char *d,const char *format,...) {
    (void)d;(void)format;fail("undeclared sprintf boundary");return 0;
}

static unsigned region_mode,math_calls,config_calls,path_observed;
static spRegionAttachment *active_region;
static spSkeletonJson *active_parser;
static double supplied_cos,supplied_sin;
static uint64_t wanted_angle,cos_arg,sin_arg;
static const char *wanted_path;
static spAttachmentLoader *wanted_loader;
static struct spAttachmentLoaderVtable alternate_vtable;
static spAttachmentLoader alternate_loader={0,0,&alternate_vtable,0};
static uint64_t double_bits(double x) { uint64_t v;memcpy(&v,&x,8);return v; }
static double from_double_bits(uint64_t v) { double x;memcpy(&x,&v,8);return x; }
static void fpscr_clear(void) { uint32_t x=0;__asm__ volatile("vmsr fpscr,%0"::"r"(x):"memory"); }
static uint32_t fpscr(void) { uint32_t x;__asm__ volatile("vmrs %0,fpscr":"=r"(x)::"memory");return x; }
size_t strlen(const char *s) { CK(s!=0,"unexpected NULL libc strlen call");return region_fixture_strlen(s); }
char *strcpy(char *d,const char *s) {
    if(region_mode==4&&s==wanted_path) {
        CK(active_region&&active_region->owned_10==d,"path pointer published before strcpy");
        ++path_observed;active_parser->scale=bits(2.0f);
    }
    return region_fixture_strcpy(d,s);
}
int strcasecmp(const char *a,const char *b) {
    int n=region_fixture_strcasecmp(a,b);
    if(region_mode==3&&n==0) {
        if(strcmp(b,"x")==0)active_parser->scale=bits(2.0f);
        if(strcmp(b,"y")==0){CK(active_region->x==4.0f,"x stored before next lookup");active_parser->scale=bits(3.0f);}
        if(strcmp(b,"width")==0)active_parser->scale=bits(4.0f);
        if(strcmp(b,"height")==0){CK(active_region->width==24.0f,"width stored before height lookup");active_parser->scale=bits(5.0f);}
    }
    return n;
}
/* Core-register DOUBLE import ABI. No real libm implementation is replaced
 * in production; these definitions belong only to this synthetic executable. */
__attribute__((no_stack_protector)) double cos(double angle) {
    CK(math_calls==0,"cos import is first");cos_arg=double_bits(angle);++math_calls;
    CK(cos_arg==wanted_angle,"cos gets float32 multiply then widened angle");
    if(region_mode==1) {
        active_region->width=999;active_region->height=888;active_region->scaleX=77;active_region->scaleY=66;
        active_region->regionWidth=2;active_region->regionHeight=3;active_region->regionOriginalWidth=4;active_region->regionOriginalHeight=5;
        active_region->rotation=1000;active_region->x=111;active_region->y=222;
    }
    if(region_mode==7)__stack_chk_guard^=1u;
    return supplied_cos;
}
__attribute__((no_stack_protector)) double sin(double angle) {
    CK(math_calls==1,"sin import follows cos");sin_arg=double_bits(angle);++math_calls;
    CK(sin_arg==wanted_angle&&sin_arg==cos_arg,"same angle snapshot passed to sin");
    if(region_mode==1){active_region->x=7;active_region->y=-3;}
    if(region_mode==2)CK(fpscr()&16u,"cos f64-to-f32 narrowing occurs BEFORE sin call");
    if(region_mode==5)active_parser->loader=(uint32_t)(uintptr_t)&alternate_loader;
    return supplied_sin;
}
static void region_configure(spAttachmentLoader *l,spAttachment *p) {
    CK(l==wanted_loader&&p==&active_region->super,"configure uses current loader and exact region");
    CK(math_calls==2,"actual geometry helper runs before configure");++config_calls;
}
static void *region_alloc(uint32_t n,const char *tag,uint32_t line) {
    if(line==891)CK(strcmp(tag,"jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c")==0,"original path allocation tag");
    return record_alloc(n,tag,line);
}
static void start_region(const char *name) {
    begin(name);region_mode=math_calls=config_calls=path_observed=0;active_region=0;active_parser=0;
    wanted_path=0;wanted_angle=0;cos_arg=sin_arg=0;supplied_cos=1;supplied_sin=0;
    wanted_loader=&loader;lv.createAttachment=_spAtlasAttachmentLoader_createAttachment;lv.configureAttachment=region_configure;alternate_vtable=lv;
    _setDebugMalloc(region_alloc);fpscr_clear();
}
static spAtlas atlas;
static spAtlasRegion metadata;
static spRegionAttachment *factory_region(void) {
    memset(&metadata,0,sizeof(metadata));metadata.name=(char *)"asset";
    metadata.width=64;metadata.height=32;metadata.originalWidth=64;metadata.originalHeight=32;
    metadata.u=.125f;metadata.v=.25f;metadata.u2=.5f;metadata.v2=.75f;
    atlas=(spAtlas){0};atlas.regions=&metadata;loader.atlas=&atlas;
    spAttachment *p=spAttachmentLoader_createAttachment(&loader,0,0,"R","asset");
    CK(p&&p->type==0,"real atlas factory creates region");active_region=(spRegionAttachment *)p;
    return active_region;
}
static void shape(spRegionAttachment *a) {
    a->width=40;a->height=20;a->scaleX=2;a->scaleY=3;
    a->regionOriginalWidth=80;a->regionOriginalHeight=40;a->regionOffsetX=10;a->regionOffsetY=5;
    a->regionWidth=40;a->regionHeight=20;a->x=7;a->y=-3;
}
static void offsets(spRegionAttachment *a,const uint32_t *want) {
    for(unsigned i=0;i<8;++i)CK(bits(a->offset[i])==want[i],"all eight offset bit patterns");
}
static void offset_scope(spRegionAttachment *a,const spRegionAttachment *before) {
    for(unsigned i=0;i<sizeof(*a)/4;++i)
        if(i<offsetof(spRegionAttachment,offset)/4||i>=offsetof(spRegionAttachment,offset)/4+8)
            CK(word(a,i)==word(before,i),"geometry writes only offset[8]");
}
static void default_geometry(void) {
    start_region("geometry_identity");spRegionAttachment *a=factory_region();
    a->width=a->height=32;spRegionAttachment before=*a;
    static const uint32_t q[]={0xc1800000u,0xc1800000u,0xc1800000u,0x41800000u,0x41800000u,0x41800000u,0x41800000u,0xc1800000u};
    na=nf=0;spRegionAttachment_updateOffset(a);offsets(a,q);offset_scope(a,&before);
    CK(math_calls==2&&na==0&&nf==0,"geometry only imports cos/sin, no allocation");
    pass("geometry_identity_and_exact_write_scope");
}
static void trimmed_geometry(int rotate) {
    start_region(rotate?"geometry_supplied_rotation":"geometry_trim");spRegionAttachment *a=factory_region();shape(a);
    supplied_cos=rotate?0:.75;supplied_sin=rotate?1:-.25;spRegionAttachment before=*a;
    static const uint32_t trim[]={0xc1a90000u,0xc1460000u,0xc15a0000u,0x41220000u,0x41830000u,0x3e000000u,0x410e0000u,0xc1b30000u};
    static const uint32_t turn[]={0x41ec0000u,0xc2040000u,0xbf000000u,0xc2040000u,0xbf000000u,0x40e00000u,0x41ec0000u,0x40e00000u};
    spRegionAttachment_updateOffset(a);offsets(a,rotate?turn:trim);offset_scope(a,&before);
    pass(rotate?"geometry_supplied_cos0_sin1":"geometry_trim_scale_and_prescribed_math_results");
}
static void negative_dimensions(void) {
    start_region("geometry_signed_dimensions");spRegionAttachment *a=factory_region();a->width=a->height=32;
    a->regionOriginalWidth=-64;a->regionOriginalHeight=-32;a->regionOffsetX=16;a->regionOffsetY=-4;a->regionWidth=32;a->regionHeight=16;
    static const uint32_t q[]={0xc1c00000u,0xc1400000u,0xc1c00000u,0xc1e00000u,0xc2200000u,0xc1e00000u,0xc2200000u,0xc1400000u};
    spRegionAttachment_updateOffset(a);offsets(a,q);pass("geometry_signed_integer_dimensions_and_trim");
}
static void math_snapshots(void) {
    start_region("geometry_math_callbacks");spRegionAttachment *a=factory_region();shape(a);a->x=0;a->y=0;a->rotation=123.456f;
    supplied_cos=.75;supplied_sin=-.25;wanted_angle=UINT64_C(0x40013cda80000000);region_mode=1;
    static const uint32_t q[]={0xc1a90000u,0xc1460000u,0xc15a0000u,0x41220000u,0x41830000u,0x3e000000u,0x410e0000u,0xc1b30000u};
    spRegionAttachment_updateOffset(a);region_mode=0;offsets(a,q);
    CK(a->width==999&&a->rotation==1000,"callback really changed geometry fields");
    pass("geometry_snapshots_before_math_and_xy_after_sin");
}
static void narrowing_and_zero(void) {
    start_region("geometry_cos_narrowing");spRegionAttachment *a=factory_region();a->width=a->height=32;
    supplied_cos=from_double_bits(UINT64_C(0x3ff0000008000000));region_mode=2;
    spRegionAttachment_updateOffset(a);region_mode=0;CK(fpscr()&16u,"conversion inexact retained");
    pass("geometry_double_cos_narrowing_precedes_sin");
    start_region("geometry_zero_original_dimensions");a=factory_region();a->width=a->height=32;a->regionOriginalWidth=a->regionOriginalHeight=0;
    spRegionAttachment_updateOffset(a);CK(math_calls==2&&(fpscr()&2u),"no safe denominator guard; VDIV divide-by-zero observed");
    for(unsigned i=0;i<8;++i){uint32_t v=bits(a->offset[i]);CK((v&0x7f800000u)==0x7f800000u&&(v&0x7fffffu),"zero denominator produces NaN offsets in declared mode");}
    pass("geometry_zero_dimensions_keeps_vfp_effects");
}
static void no_geometry_canary(void) {
    start_region("geometry_original_has_no_canary");spRegionAttachment *a=factory_region();a->width=a->height=32;
    uintptr_t saved=__stack_chk_guard;region_mode=7;spRegionAttachment_updateOffset(a);__stack_chk_guard=saved;region_mode=0;
    CK(math_calls==2,"geometry returns despite provider changing global guard");pass("geometry_retains_original_no_canary_property");
}
static Json *float_map(void) {
    Json *m=node(0);const char *names[]={"x","y","scaleX","scaleY","rotation","width","height"};
    const float values[]={2,-1,1.5f,-.5f,0,6,8};
    for(unsigned i=0;i<7;++i){Json *n=node(names[i]);n->float_value=values[i];add(m,n);}return m;
}
static void reader_defaults(void) {
    start_region("region_reader_defaults");spRegionAttachment *a=factory_region();Json *m=node(0);
    spSkeletonJson j={0};j.scale=bits(1);j.loader=(uint32_t)(uintptr_t)&loader;active_parser=&j;
    float before_uvs[8];memcpy(before_uvs,a->uvs,sizeof(before_uvs));
    readSkeletonData_regionFields(m,a,"asset",&j);
    CK(a->region==&metadata,"parser preserves factory atlas-region identity");
    for(unsigned i=0;i<8;++i)CK(bits(a->uvs[i])==bits(before_uvs[i]),"parser geometry leaves factory UVs unchanged");
    CK(a->width==32&&a->height==32&&a->scaleX==1&&a->scaleY==1&&a->rotation==0,"original fallback fields");
    CK(a->r==1&&a->g==1&&a->b==1&&a->a==1&&config_calls==1,"missing color retains constructor color; configured");
    static const uint32_t q[]={0xc1800000u,0xc1800000u,0xc1800000u,0x41800000u,0x41800000u,0x41800000u,0x41800000u,0xc1800000u};offsets(a,q);
    CK(find_line(891)->bytes==6&&strcmp(a->owned_10,"asset")==0,"path copy request and bytes");
    void *path=a->owned_10;spAttachment_dispose(&a->super);unsigned hits=0;for(unsigned i=0;i<nf;++i)hits+=ff[i]==path;CK(hits==1,"actual region destructor frees path once");
    pass("reader_default_fields_factory_geometry_configure_cleanup");
}
static void reader_live_scale(void) {
    start_region("reader_scale_after_each_getter");spRegionAttachment *a=factory_region();Json *m=float_map();spSkeletonJson j={0};
    j.scale=bits(99);j.loader=(uint32_t)(uintptr_t)&loader;active_parser=&j;region_mode=3;
    readSkeletonData_regionFields(m,a,0,&j);region_mode=0;
    CK(a->x==4&&a->y==-3&&a->width==24&&a->height==40&&a->scaleX==1.5f&&a->scaleY==-.5f,"per-key live scale, unscaled scaleX/Y");
    pass("reader_scale_reloaded_after_each_json_lookup");
}
static void reader_color(int invalid) {
    start_region(invalid?"reader_invalid_color":"reader_color");spRegionAttachment *a=factory_region();Json *m=node(0);add(m,string("color",invalid?"abc":"ff800040"));
    spSkeletonJson j={0};j.scale=bits(1);j.loader=(uint32_t)(uintptr_t)&loader;active_parser=&j;
    readSkeletonData_regionFields(m,a,0,&j);
    if(invalid)CK(a->r==-1&&a->g==-1&&a->b==-1&&a->a==-1,"all invalid channels retained as -1");
    else CK(bits(a->r)==0x3f800000u&&bits(a->g)==0x3f008081u&&bits(a->b)==0&&bits(a->a)==0x3e808081u,"all four raw color channels");
    pass(invalid?"reader_invalid_color_uses_actual_color_helper":"reader_color_uses_actual_s0_return_helper");
}
static void reader_path_and_loader(void) {
    start_region("reader_path_publication");spRegionAttachment *a=factory_region();Json *m=node(0);spSkeletonJson j={0};j.scale=bits(1);j.loader=(uint32_t)(uintptr_t)&loader;active_parser=&j;
    wanted_path="asset";region_mode=4;readSkeletonData_regionFields(m,a,wanted_path,&j);region_mode=0;
    CK(path_observed==1&&a->width==64&&a->height==64,"path callback precedes current scale reads");
    unsigned count=na;void *path=a->owned_10;math_calls=0;readSkeletonData_regionFields(m,a,0,&j);
    CK(na==count&&a->owned_10==path,"NULL path skips libc/alloc and retains existing owned path");
    pass("reader_path_publication_and_null_path_skip");
    start_region("reader_loader_after_math");a=factory_region();m=node(0);j=(spSkeletonJson){0};j.scale=bits(1);j.loader=(uint32_t)(uintptr_t)&loader;active_parser=&j;
    wanted_loader=&alternate_loader;region_mode=5;readSkeletonData_regionFields(m,a,0,&j);region_mode=0;
    CK(config_calls==1,"configure receives loader installed by sin callback");pass("reader_loader_reloaded_after_geometry_math_callbacks");
}
void _start(void) {
    test="startup";init_heap();default_geometry();trimmed_geometry(0);trimmed_geometry(1);negative_dimensions();math_snapshots();narrowing_and_zero();no_geometry_canary();
    reader_defaults();reader_live_scale();reader_color(0);reader_color(1);reader_path_and_loader();
    out("SUMMARY all declared reconstructed region contracts passed\n");quit(0);
}
