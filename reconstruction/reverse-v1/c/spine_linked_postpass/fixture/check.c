/* Synthetic providers + real reconstructed consumers. Reuse the prior small
 * runtime fixture, NOT its 16 tests: mesh_fixture_unused_start is never run.
 * No original bytes are loaded or executed. */
#define _start mesh_fixture_unused_start
#define strcmp mesh_fixture_strcmp
#define strcpy mesh_fixture_strcpy
#define free mesh_fixture_free
#define strlen mesh_fixture_strlen
#include "../../spine_read_mesh/fixture/check.c"
#undef _start
#undef strcmp
#undef strcpy
#undef free
#undef strlen
#include "spine_skin.h"
#include "skeleton_find.h"
#include "spine_linked_postpass.h"
#include "spine_json_error.h"

static unsigned fx_mode,cmp_calls,report_count,configure_count,root_freed;
static char reported[512],report_format[128];
static spSkeletonData *root_data;
static spSkeletonJson *root_parser;
static spLinkedMesh *row,*alternate_queue;
static spSkinEntry *entry_observed,*skip_target;
static spSkin *skin_observed;
static spAttachment *replacement_attachment;
static spMeshAttachment *configured_last,*replacement_mesh;
static const char *trigger_string;
static spSkin *replacement_skins[2];
static uint32_t trace_clock,free_root_tick,report_tick,publication_observed;
static const char *watched_message;static char *watched_buffer;
static unsigned message_strlen_calls,append_calls;
static void *canary_free_target;
/* Implemented by a tiny fixture adapter after the error support ABI is frozen.
 * Adapter installs a real typed reporter object; it does not replace ReportSpineError. */
extern void fixture_install_error_reporter(void);
void fixture_report_sink(const char *fmt,const char *message) {
    ++report_count;report_tick=++trace_clock;
    mesh_fixture_strcpy(report_format,fmt);mesh_fixture_strcpy(reported,message);
}
size_t strlen(const char *s) {
    if(fx_mode==11&&s==watched_message)++message_strlen_calls;
    return mesh_fixture_strlen(s);
}
char *strncat(char *d,const char *s,size_t n) {
    if(fx_mode==11) {
        CK(d==watched_buffer+mesh_fixture_strlen(watched_message),"strncat receives buffer+message_length, not buffer");
        CK(n==255u-mesh_fixture_strlen(watched_message),"original append bound");++append_calls;
    }
    char *r=d;d+=strlen(d);while(n--&&*s)*d++=*s++;*d=0;return r;
}
int strcmp(const char *a,const char *b) {
    int result=mesh_fixture_strcmp(a,b);++cmp_calls;
    if(fx_mode==1&&a==trigger_string&&result==0)entry_observed->attachment=replacement_attachment;
    if(fx_mode==2&&a==trigger_string&&result!=0)entry_observed->next=skip_target;
    if(fx_mode==3&&a==trigger_string) {
        root_data->words[8]=0;root_data->words[9]=(uint32_t)(uintptr_t)replacement_skins;
    }
    if(fx_mode==8&&a==trigger_string) {
        row->parent="second";row->slotIndex=8;
    }
    return result;
}
char *strcpy(char *d,const char *s) {
    if(fx_mode==11&&s==watched_message)watched_buffer=d;
    if(fx_mode==4&&entry_observed&&d==entry_observed->name) {
        CK(entry_observed->slotIndex==17&&entry_observed->attachment==0,"entry fields visible before strcpy");
        ++publication_observed;skin_observed->entries=skip_target;
    }
    return mesh_fixture_strcpy(d,s);
}
void free(void *p) {
    if(fx_mode==12&&p==canary_free_target)__stack_chk_guard^=1u;
    ++trace_clock;
    if(p==root_data){root_freed=1;free_root_tick=trace_clock;
        if(fx_mode==5)row->skin="AFTER_DISPOSE";
        if(fx_mode==6)row->parent="AFTER_DISPOSE";
    }
    mesh_fixture_free(p);
}
static void *linked_alloc(uint32_t n,const char *tag,uint32_t line) {
    void *p=record_alloc(n,tag,line);
    if(fx_mode==4&&line==36)entry_observed=p;
    if(fx_mode==7&&line==64&&row)row->mesh=replacement_mesh;
    return p;
}
static void linked_configure(spAttachmentLoader *l,spAttachment *a) {
    CK(l==&loader,"current loader passed");++configure_count;configured_last=(spMeshAttachment *)a;
    if(fx_mode==9&&configure_count==1) { root_parser->unk_10=2;root_parser->unk_18=(uint32_t)(uintptr_t)alternate_queue; }
    if(fx_mode==10)root_parser->unk_10=0;
}
static void start(const char *s) {
    begin(s);fx_mode=cmp_calls=report_count=configure_count=root_freed=trace_clock=free_root_tick=report_tick=0;
    root_data=0;root_parser=0;row=0;entry_observed=0;skin_observed=0;trigger_string=0;
    configured_last=0;publication_observed=0;lv.configureAttachment=linked_configure;
    _setDebugMalloc(linked_alloc);_setFree(free);fixture_install_error_reporter();
}
static spSkeletonData *data_one_skin(const char *name) {
    spSkeletonData *d=spSkeletonData_create();spSkin **table=reserve(8);
    table[0]=spSkin_create(name);d->words[8]=1;d->words[9]=(uint32_t)(uintptr_t)table;d->words[10]=(uint32_t)(uintptr_t)table[0];return d;
}
static spSkin *default_skin(spSkeletonData *d) {return (spSkin *)(uintptr_t)d->words[10];}
static spMeshAttachment *parent_in(spSkin *s,const char *name,uint32_t slot) {
    Json *map=basic_map(0);spMeshAttachment *m=make_mesh();observed=m;
    CK(readSkeletonData_meshFields(map,m,"asset",root_parser,slot)==0,"parent field consumer");
    spSkin_addAttachment(s,slot,name,&m->super.super);return m;
}
static spMeshAttachment *child_in(spSkin *s,const char *parent,const char *skin_name,uint32_t slot) {
    Json *map=node(0);add(map,string("parent",parent));if(skin_name)add(map,string("skin",skin_name));
    spMeshAttachment *m=make_mesh();observed=m;
    CK(readSkeletonData_meshFields(map,m,"asset",root_parser,slot)==1,"linked field consumer");
    spSkin_addAttachment(s,slot,"child",&m->super.super);return m;
}
static void constructors_lookup(void) {
    start("skin_create_entry_and_head_order");spSkin *s=spSkin_create("S");
    CK(s->entries==0&&strcmp(s->name,"S")==0,"skin complete8B object");
    spAttachment a={0},b={0};spSkin_addAttachment(s,17,"same",&a);spSkinEntry *old=s->entries;
    spSkin_addAttachment(s,17,"same",&b);
    CK(s->entries->next==old&&spSkin_getAttachment(s,17,"same")==&b,"duplicates are newest-first, not replace");
    CK(find_line(52)->bytes==8&&find_line(53)->bytes==2&&find_line(36)->bytes==16&&find_line(38)->bytes==5,"constructor byte sizes and tag lines");
    CK(spSkin_getAttachment(s,18,"same")==0&&spSkin_getAttachment(s,17,"missing")==0,"slot and name both required");
    pass("skin_constructors_duplicates_newest_first");
    start("get_after_strcmp_rereads");s=spSkin_create("S");spSkin_addAttachment(s,1,"key",&a);
    entry_observed=s->entries;trigger_string=entry_observed->name;replacement_attachment=&b;fx_mode=1;
    CK(spSkin_getAttachment(s,1,"key")==&b,"attachment loaded after comparator");
    fx_mode=0;spSkin_addAttachment(s,1,"middle",&a);spSkin_addAttachment(s,1,"wrong",&a);
    entry_observed=s->entries;skip_target=entry_observed->next->next;trigger_string=entry_observed->name;fx_mode=2;cmp_calls=0;
    CK(spSkin_getAttachment(s,1,"key")==&b,"next loaded after comparator");
    CK(cmp_calls==2,"next reread skips middle comparator, not merely same eventual result");fx_mode=0;
    pass("skin_get_comparator_mutates_attachment_and_next");
    start("add_reads_head_after_creation");s=spSkin_create("S");skin_observed=s;skip_target=reserve(sizeof(*skip_target));memset(skip_target,0,sizeof(*skip_target));
    /* Actual constructor calls publish slot/name before the strcpy callback.
     * That callback changes head DURING create, not in fixture prestate. */
    entry_observed=0;fx_mode=4;
    spSkin_addAttachment(s,17,"new",&b);fx_mode=0;
    CK(publication_observed==1&&s->entries->attachment==&b,"real creation/publication callback");
    CK(s->entries->next==skip_target,"add reads latest skin head after creation");
    pass("skin_entry_publication_and_latest_head");
}
static void find_lookups(void) {
    start("data_find_canonical_offsets");spSkeletonData d={0};
    struct name_record { const char *wrong;const char *name; } bone={"WRONG","bone"},slot={"WRONG","slot"};
    void *bones[]={&bone},*slots[]={&slot};d.words[4]=1;d.words[5]=(uint32_t)(uintptr_t)bones;
    d.words[6]=1;d.words[7]=(uint32_t)(uintptr_t)slots;
    CK(spSkeletonData_findBone(&d,"bone")== (spBoneData *)&bone,"bone name at+4 not+0");
    CK(spSkeletonData_findSlotIndex(&d,"slot")==0&&spSkeletonData_findSlotIndex(&d,"absent")==-1,"slot name+4/index");
    d.words[4]=0xffffffffu;d.words[5]=1;d.words[6]=0;d.words[7]=1;
    CK(!spSkeletonData_findBone(&d,"bone")&&spSkeletonData_findSlotIndex(&d,"slot")==-1,"signed nonpositive skips table");
    pass("data_find_uses_full_record_and_name_offsets");
    start("find_skin_snapshots");spSkin *a=spSkin_create("first"),*b=spSkin_create("second");spSkin *table[]={a,b};
    d=(spSkeletonData){0};d.words[8]=2;d.words[9]=(uint32_t)(uintptr_t)table;
    root_data=&d;trigger_string=a->name;fx_mode=3;replacement_skins[0]=a;replacement_skins[1]=a;
    CK(spSkeletonData_findSkin(&d,"second")==b,"count and table snapshotted before comparator");fx_mode=0;
    d.words[8]=0xffffffffu;d.words[9]=1;CK(!spSkeletonData_findSkin(&d,"second"),"signed negative skip");
    pass("find_skin_count_and_table_snapshot");
}
static void success(int named) {
    start(named?"postpass_named_skin":"postpass_default_skin");root_parser=spSkeletonJson_createWithLoader(&loader);
    root_data=data_one_skin("named");spSkin *s=default_skin(root_data);
    spSkin **old=(spSkin **)(uintptr_t)root_data->words[9],**table=reserve(8);
    table[0]=spSkin_create("other");table[1]=s;root_data->words[8]=2;root_data->words[9]=(uint32_t)(uintptr_t)table;_free(old);
    spMeshAttachment *p=parent_in(s,"P",3),*ch=child_in(s,"P",named?"named":0,3);
    row=links(root_parser);configure_count=0;unsigned before_free=nf;
    CK(readSkeletonData_resolveLinkedMeshes(root_parser,root_data)==1,"events continuation");
    CK(ch->parentMesh==p&&ch->super.owned_1c==p->super.owned_1c&&ch->owned_58==p->owned_58,"actual parent lookup/sharing");
    CK(ch->owned_5c&&ch->owned_5c!=p->owned_5c&&configure_count==1&&configured_last==ch,"derived UV is child-owned and configured");
    CK(root_parser->unk_10==1&&root_parser->unk_18==(uint32_t)(uintptr_t)row&&nf==before_free+1,"success neither clears nor frees queue");
    spSkeletonData_dispose(root_data);spSkeletonJson_dispose(root_parser);
    pass(named?"postpass_named_skin_lookup":"postpass_default_skin_lookup_and_real_cleanup");
}
static void empty_postpass(void) {
    start("postpass_signed_empty");spSkeletonJson j={0};j.unk_18=1;
    CK(readSkeletonData_resolveLinkedMeshes(&j,0)==1,"zero count skips all data/queue reads");
    j.unk_10=0xffffffffu;CK(readSkeletonData_resolveLinkedMeshes(&j,0)==1,"negative signed count skips");
    CK(na==0&&nf==0&&report_count==0&&configure_count==0,"empty no effects");pass("postpass_zero_and_negative_count_no_effects");
}
static void errors(int missing_skin) {
    start(missing_skin?"missing_skin":"missing_parent");root_parser=spSkeletonJson_createWithLoader(&loader);
    root_data=data_one_skin("named");spSkin *s=default_skin(root_data);
    child_in(s,"MISSING",missing_skin?"ABSENT":0,2);row=links(root_parser);
    fx_mode=missing_skin?5:6;configure_count=0;
    CK(readSkeletonData_resolveLinkedMeshes(root_parser,root_data)==0,"NULL return successor");fx_mode=0;
    CK(root_freed&&free_root_tick<report_tick&&report_count==1&&configure_count==0,"dispose precedes report, no configure");
    CK(strcmp(reported,missing_skin?"Skin not found: AFTER_DISPOSE":"Parent mesh not found: AFTER_DISPOSE")==0,"extra string reread after disposal");
    CK(strcmp((char *)(uintptr_t)root_parser->error,reported)==0,"stored error and report agree");
    CK(find_line(90)->bytes==strlen(reported)+1,"actual setError original allocation");
    spSkeletonJson_dispose(root_parser);
    pass(missing_skin?"missing_skin_disposes_then_rereads_error_extra":"missing_parent_disposes_then_rereads_error_extra");
}
static void live_mesh_after_uv(void) {
    start("postpass_mesh_after_allocator");root_parser=spSkeletonJson_createWithLoader(&loader);root_data=data_one_skin("named");spSkin *s=default_skin(root_data);
    parent_in(s,"P",1);spMeshAttachment *a=child_in(s,"P",0,1),*b=make_mesh();
    spSkin_addAttachment(s,1,"replacement",&b->super.super);row=links(root_parser);replacement_mesh=b;
    configure_count=0;fx_mode=7;CK(readSkeletonData_resolveLinkedMeshes(root_parser,root_data)==1,"resolve with allocator mutation");fx_mode=0;
    CK(a->owned_5c&&configured_last==b&&b->owned_5c==0,"configure rereads entry mesh after updateUVs allocator");
    spSkeletonData_dispose(root_data);spSkeletonJson_dispose(root_parser);pass("postpass_mesh_pointer_reread_after_uv_allocator");
}
static void live_parent_after_find(void) {
    start("postpass_parent_after_findskin");root_parser=spSkeletonJson_createWithLoader(&loader);root_data=data_one_skin("first");spSkin *s=default_skin(root_data);
    spMeshAttachment *a=parent_in(s,"first",7),*b=parent_in(s,"second",8);(void)a;
    spMeshAttachment *ch=child_in(s,"first","first",7);row=links(root_parser);trigger_string=s->name;fx_mode=8;configure_count=0;
    CK(readSkeletonData_resolveLinkedMeshes(root_parser,root_data)==1,"named resolver");fx_mode=0;
    CK(ch->parentMesh==b,"slot and parent reloaded after skin comparator");
    spSkeletonData_dispose(root_data);spSkeletonJson_dispose(root_parser);pass("postpass_parent_and_slot_read_after_skin_lookup");
}
static void dynamic_count(int grow) {
    start(grow?"postpass_configure_grow":"postpass_configure_shrink");root_parser=spSkeletonJson_createWithLoader(&loader);root_data=data_one_skin("named");spSkin *s=default_skin(root_data);
    parent_in(s,"P",1);spMeshAttachment *a=child_in(s,"P",0,1),*b=child_in(s,"P",0,1);
    row=links(root_parser);alternate_queue=reserve(32);memcpy(alternate_queue,row,32);
    if(grow){root_parser->unk_10=1;row[1].parent="WRONG";fx_mode=9;}else fx_mode=10;
    configure_count=0;CK(readSkeletonData_resolveLinkedMeshes(root_parser,root_data)==1,"dynamic count resolver");fx_mode=0;
    CK(configure_count==(grow?2u:1u)&&a->parentMesh&&((b->parentMesh!=0)==grow),"count after callback and queue per iteration");
    spSkeletonData_dispose(root_data);spSkeletonJson_dispose(root_parser);
    pass(grow?"postpass_callback_grows_count_and_replaces_queue":"postpass_callback_shrinks_count");
}
static void error_import_calls(void) {
    start("set_error_import_calls");spSkeletonJson *j=spSkeletonJson_createWithLoader(&loader);
    watched_message="prefix:";message_strlen_calls=append_calls=0;watched_buffer=0;fx_mode=11;
    _spSkeletonJson_setError(j,0,watched_message,"tail");fx_mode=0;
    CK(message_strlen_calls==1&&append_calls==1&&mesh_fixture_strcmp(reported,"prefix:tail")==0,"message strlen and append");
    message_strlen_calls=append_calls=0;fx_mode=11;
    _spSkeletonJson_setError(j,0,watched_message,0);fx_mode=0;
    CK(message_strlen_calls==1&&append_calls==0,"message strlen is unconditional even when extra is NULL");
    spSkeletonJson_dispose(j);pass("error_unconditional_strlen_and_end_pointer_strncat");
}
#ifndef TEST_CANARY
#define TEST_CANARY 0
#endif
void _start(void) {
    test="startup";init_heap();
    if(TEST_CANARY) {
        start("set_error_canary_after_dispose");spSkeletonJson *j=spSkeletonJson_createWithLoader(&loader);
        Json *n=node(0);canary_free_target=n;fx_mode=12;
        _spSkeletonJson_setError(j,n,"canary",0);
        fail("canary was not checked after Json_dispose");
    }
    constructors_lookup();find_lookups();empty_postpass();success(0);success(1);
    errors(1);errors(0);live_mesh_after_uv();live_parent_after_find();dynamic_count(1);dynamic_count(0);error_import_calls();
    out("SUMMARY all declared linked postpass contracts passed\n");quit(0);
}
