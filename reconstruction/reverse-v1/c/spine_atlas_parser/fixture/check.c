/* Real reconstructed API chain: text -> atlas -> attachment dispatch -> dispose.
 * Only libc/heap/ctype/texture providers are synthetic. Original not executed. */
#include "spine_atlas_create.h"
#include "spine_atlas_attachment.h"
#include "spine_alloc.h"
#include "support.h"
static uint32_t bits(float value){union {float f;uint32_t u;} v;v.f=value;return v.u;}
static const char normal[]=
"page.png\nsize: 64, 32\nformat: RGBA8888\nfilter: Nearest, Linear\nrepeat: none\n"
"r\nrotate: false\nxy: 1, 2\nsize: 16, 8\norig: 16, 8\noffset: 3, 4\nindex: -1\n";
static const char rotated[]=
"rot.png\nformat: RGBA8888\nfilter: Linear, Nearest\nrepeat: xy\n"
"r\nrotate:\nxy: 1, 2\nsize: 16, 8\norig: 16, 8\noffset: 0, 0\nindex: 0\n";
static const char ninepatch[]=
"nine.png\nsize: 64, 32\nformat: RGBA8888\nfilter: Nearest, Linear\nrepeat: x\n"
"r\nrotate: false\nxy: 1, 2\nsize: 16, 8\nsplit: 1, 2, 3, 4\npad: 5, 6, 7, 8\n"
"orig: 16, 8\noffset: 0, 0\nindex: 7\n";
void _start(void)
{
    fixture_init();
    uint32_t renderer=0x13572468u;
    spAtlas *atlas=spAtlas_create("",0,"",&renderer);
    fixture_check(atlas && !atlas->pages && !atlas->regions && atlas->renderer==&renderer,"empty_atlas_preserves_renderer");
    spAtlas_dispose(atlas);
    fixture_check(fixture_live()==0,"empty_atlas_releases_container");
    atlas=spAtlas_create(normal,sizeof normal-1,"assets",&renderer);
    fixture_check(atlas && atlas->pages && atlas->regions,"normal_atlas_materialized");
    if(!atlas || !atlas->pages || !atlas->regions)fixture_exit(88);
    spAtlasPage *page=atlas->pages;spAtlasRegion *region=atlas->regions;
    fixture_check(!strcmp(fixture_last_path,"assets/page.png"),"texture_receives_joined_path");
    fixture_check(fixture_width_at_texture==64 && fixture_height_at_texture==32,"page_size_forwarded_before_texture_provider");
    fixture_check(page->atlas==atlas && !page->next && !region->next && region->page==page,"canonical_shared_pointer_graph");
    fixture_check(page->width==64 && page->height==32 && page->format==7 && page->minFilter==1 && page->magFilter==2,"page_size_format_filter_fields");
    fixture_check(page->uWrap==1 && page->vWrap==1,"page_none_wrap_values");
    fixture_check(!strcmp(region->name,"r") && region->x==1 && region->y==2 && region->width==16 && region->height==8 && region->index==-1,"region_scalar_fields");
    fixture_check(bits(region->u)==0x3c800000u && bits(region->v)==0x3d800000u && bits(region->u2)==0x3e880000u && bits(region->v2)==0x3ea00000u,"normal_uv_independent_ieee_bits");
    fixture_check(region->offsetX==3 && region->offsetY==4 && region->originalWidth==16 && region->originalHeight==8,"region_original_and_offset_fields");
    spAttachmentLoader *loader=spAtlasAttachmentLoader_create(atlas);
    const int expected[5]={0,1,2,2,4};
    const char *dispatch_ids[5]={"dispatch_type0_region","dispatch_type1_bbox","dispatch_type2_mesh","dispatch_type3_constructs_mesh2","dispatch_type4_path"};
    const char *dispose_ids[5]={"dispose_type0_region","dispose_type1_bbox","dispose_type2_mesh","dispose_type3_mesh","dispose_type4_path"};
    for(int type=0;type<=4;++type){
        size_t before=fixture_live();
        spAttachment *attachment=spAttachmentLoader_createAttachment(loader,0,type,"part","prefix/r");
        fixture_check(attachment && attachment->type==expected[type] && !attachment->loader,dispatch_ids[type]);
        if(!attachment)fixture_exit(87);
        if(type==0){
            spRegionAttachment *r=(spRegionAttachment *)attachment;
            fixture_check(r->region==region && r->regionOffsetX==3 && r->regionOffsetY==4 && bits(r->uvs[0])==0x3c800000u && bits(r->uvs[1])==0x3ea00000u,"region_attachment_consumes_parsed_geometry");
        }
        if(type==2 || type==3){
            spMeshAttachment *m=(spMeshAttachment *)attachment;
            fixture_check(m->region==region && m->regionWidth==16 && bits(m->u2)==0x3e880000u,type==2?"mesh2_consumes_parsed_geometry":"linked3_consumes_parsed_geometry");
        }
        spAttachment_dispose(attachment);
        fixture_check(fixture_live()==before,dispose_ids[type]);
    }
    spAttachmentLoader_dispose(loader);
    spAtlas_dispose(atlas);
    fixture_check(fixture_live()==0 && fixture_texture_calls==1 && fixture_texture_frees==1,"normal_chain_balanced_heap_and_texture_requests");
    atlas=spAtlas_create(rotated,sizeof rotated-1,"assets/",0);
    fixture_check(atlas && atlas->regions && atlas->pages,"rotated_optional_size_materialized");
    if(!atlas || !atlas->regions || !atlas->pages)fixture_exit(86);
    region=atlas->regions;page=atlas->pages;
    fixture_check(fixture_width_at_texture==0 && fixture_height_at_texture==0,"optional_page_size_remains_absent_at_provider");
    fixture_check(!strcmp(fixture_last_path,"assets/rot.png") && page->width==64 && page->height==32,"optional_size_filled_by_texture_provider");
    fixture_check(region->rotate==1 && page->uWrap==2 && page->vWrap==2,"terminal_colon_empty_value_and_xy_wrap");
    fixture_check(bits(region->u2)==0x3e100000u && bits(region->v2)==0x3f100000u,"rotated_uv_swaps_integer_dimensions");
    spAtlas_dispose(atlas);
    fixture_check(fixture_live()==0 && fixture_texture_frees==2,"rotated_chain_balanced");
    atlas=spAtlas_create(ninepatch,sizeof ninepatch-1,"",0);
    fixture_check(atlas && atlas->regions && atlas->regions->splits && atlas->regions->pads,"split_and_pad_arrays_materialized");
    if(!atlas || !atlas->regions || !atlas->regions->splits || !atlas->regions->pads)fixture_exit(85);
    region=atlas->regions;
    fixture_check(region->splits[0]==1 && region->splits[3]==4 && region->pads[0]==5 && region->pads[3]==8,"split_and_pad_values");
    fixture_check(fixture_live_at_line(269)==1 && fixture_live_at_line(277)==1 && atlas->pages->uWrap==2 && atlas->pages->vWrap==1,"array_allocation_tags_and_x_wrap");
    spAtlas_dispose(atlas);
    fixture_check(fixture_live()==0 && fixture_texture_frees==3,"arrays_and_atlas_disposed_by_real_helpers");
    const char broken[]="broken.png\nnotacolon\n";
    atlas=spAtlas_create(broken,sizeof broken-1,"",0);
    fixture_check(!atlas && fixture_texture_calls==3 && fixture_texture_frees==3,"abort_disposes_half_page_without_texture_call");
    fixture_check(fixture_live()==1 && fixture_live_at_line(190)==1,"original_abort_keeps_unpublished_path_leak");
    fixture_finish();
}
