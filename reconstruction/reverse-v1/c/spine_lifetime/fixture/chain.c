/* Synthetic consumer of the recovered Loader -> skeleton -> spine lifetime.
 * Executes reconstructed C only. Atlas/data parsing, allocation and GPU release
 * remain explicitly typed test boundaries. Mutable callbacks check load order;
 * zeroing freed arena blocks checks that next is captured before release. */
#include "fx.h"
#include "test_doubles.h"
#include "yy_skel_deps.h"
#include "atlas_dispose.h"
extern void *memset(void *, int, size_t);

volatile uint8_t g_bFreeingSpineSprite;
yy_glob_479c98 g_yy_479c98;
static unsigned mode, count, want_count, block_count;
static unsigned char kinds[64], want_kinds[64];
static uint32_t values[64], want_values[64], blocks[64], sizes[64];
static struct {
    char *text;
    uint32_t atlas, json, loader, data;
    uint32_t page[3], name[3], region[2], rn[2], rs[2], rp[2];
    uint32_t p08, p18, new08, new18, new_name;
} g;

static void fail(const char *name)
{
    fx_puts("FAIL "); fx_puts(name); fx_puts("\n"); fx_exit(1);
}
#define CHECK(c,n) do { if (!(c)) fail(n); } while (0)
static void event(unsigned char k, uint32_t v)
{
    if (count == 64) { fx_puts("FIXTURE log overflow\n"); fx_exit(90); }
    kinds[count] = k; values[count++] = v;
}
static void want(unsigned char k, uint32_t v)
{
    if (want_count == 64) { fx_puts("FIXTURE expected log overflow\n"); fx_exit(90); }
    want_kinds[want_count] = k; want_values[want_count++] = v;
}
static void compare(void)
{
    CHECK(count == want_count, "chain_release_trace");
    for (unsigned i=0; i<count; ++i)
        CHECK(kinds[i] == want_kinds[i] && values[i] == want_values[i], "chain_release_trace");
}
static uint32_t alloc(uint32_t n)
{
    if (block_count == 64) { fx_puts("FIXTURE block overflow\n"); fx_exit(90); }
    uint32_t a=fx_alloc(n);
    blocks[block_count]=a; sizes[block_count++]=n;
    memset((void *)(uintptr_t)a, 0, n);
    return a;
}
void MemoryManager_Free(const void *p) { event('F',(uint32_t)(uintptr_t)p); }
void Sprite_operator_delete(void *p) { event('D',(uint32_t)(uintptr_t)p); }
void GR_Texture_Free(int id)
{
    CHECK(g_bFreeingSpineSprite == 1, "chain_texture_flag_window");
    event('T',(uint32_t)id);
    if (id == 19 && mode == 0) {
        /* The page helper must read name AFTER its texture callback. The atlas
         * must have read next BEFORE entering that same callback. */
        fx_w32(g.page[0]+SPATPAGE_NAME,g.new_name);
        fx_w32(g.page[0]+SPATPAGE_NEXT,0);
    }
}
void *_calloc(uint32_t n, uint32_t size, const char *tag, uint32_t line)
{
    static const char expected[]="jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";
    CHECK(n==1 && size==28 && line==62 && tag, "chain_json_allocator_abi");
    for (unsigned i=0;i<sizeof expected;++i)
        CHECK(tag[i]==expected[i], "chain_json_allocator_metadata");
    return (void *)(uintptr_t)alloc(n*size);
}
void _free(void *p)
{
    uint32_t a=(uint32_t)(uintptr_t)p;
    event('F',a);
    /* The second JSON field must be re-read after the first free callback. */
    if (mode==0 && a==g.new18) fx_w32(g.json+8,g.new08);
    for (unsigned i=0;i<block_count;++i)
        if (a==blocks[i]) memset(p,0,sizes[i]);
}
void *spAtlasAttachmentLoader_create(spAtlas *a)
{
    CHECK((uint32_t)(uintptr_t)a==g.atlas, "chain_loader_gets_created_atlas");
    g.loader=alloc(16);
    return (void *)(uintptr_t)g.loader;
}
void spAttachmentLoader_dispose(void *p)
{
    CHECK((uint32_t)(uintptr_t)p==g.loader, "chain_attachment_loader_dispose_abi");
    event('L',g.loader);
    /* JSON's +0x18 load is after this call in the original. */
    if (mode==0) fx_w32(g.json+0x18,g.new18);
}
spAtlas *spAtlas_create(const char *data, int len, const char *dir, void *renderer)
{
    CHECK(data==g.text+4 && len==4 && dir && !*dir && !renderer, "chain_atlas_factory_abi");
    CHECK(g_yy_479c98.end==(uint32_t)(uintptr_t)(g.text+8) &&
          g_yy_479c98.w04==11 && g_yy_479c98.w08==22 && g_yy_479c98.w0c==33,
          "chain_constructor_context");
    if (mode==2) return NULL;
    g.atlas=alloc(SPATLAS_SIZE);
    if (mode==0) {
        for (unsigned i=0;i<3;++i) {
            g.page[i]=alloc(SPATPAGE_SIZE); g.name[i]=alloc(8);
            fx_w32(g.page[i]+SPATPAGE_ATLAS,g.atlas);
            fx_w32(g.page[i]+SPATPAGE_NAME,g.name[i]);
        }
        fx_w32(g.page[0]+SPATPAGE_NEXT,g.page[1]);
        fx_w32(g.page[1]+SPATPAGE_NEXT,g.page[2]);
        fx_w32(g.page[0]+0x1c,19); fx_w32(g.page[2]+0x1c,0xffffffffu);
        for (unsigned i=0;i<2;++i) {
            g.region[i]=alloc(SPATREGION_SIZE); g.rn[i]=alloc(8);
            g.rs[i]=alloc(8); g.rp[i]=alloc(8);
            fx_w32(g.region[i]+SPATREGION_NAME,g.rn[i]);
            fx_w32(g.region[i]+SPATREGION_SPLITS,g.rs[i]);
            fx_w32(g.region[i]+SPATREGION_PADS,g.rp[i]);
        }
        fx_w32(g.region[0]+SPATREGION_NEXT,g.region[1]);
        fx_w32(g.atlas+SPATLAS_PAGES,g.page[0]);
        fx_w32(g.atlas+SPATLAS_REGIONS,g.region[0]);
        fx_w32(g.atlas+SPATLAS_RENDERER,0x12345678u);
        g.new_name=alloc(8);
    }
    return (spAtlas *)(uintptr_t)g.atlas;
}
spSkeletonData *spSkeletonJson_readSkeletonData(spSkeletonJson *j, const char *text)
{
    static const unsigned char decoded[8]={0xd6,0xf3,0x30,0xed,0xda,0xf7,0x34,0xf1};
    g.json=(uint32_t)(uintptr_t)j;
    CHECK(text==g.text && fx_r32(g.json)==0x3f800000u &&
          fx_r32(g.json+4)==g.loader && fx_r32(g.json+0xc)==1,
          "chain_json_result_consumed");
    for (unsigned i=0;i<8;++i)
        CHECK((unsigned char)text[i]==decoded[i], "chain_real_decode_consumed");
    g.p08=alloc(8); g.p18=alloc(8); g.new08=alloc(8); g.new18=alloc(8);
    fx_w32(g.json+8,g.p08); fx_w32(g.json+0x18,g.p18);
    if (mode==2) return NULL;
    g.data=alloc(8);
    return (spSkeletonData *)(uintptr_t)g.data;
}
void spSkeletonData_dispose(spSkeletonData *p)
{
    event('d',(uint32_t)(uintptr_t)p);
}

static void one_case(unsigned which, CSprite *s)
{
    mode=which; memset(&g,0,sizeof g); count=want_count=block_count=0;
    uint32_t wad=alloc(512); YYSprite *yy=(YYSprite *)(uintptr_t)wad;
    yy->width=3; yy->height=4; yy->textureCount=-1;
    fx_w32(wad+0x40,2); fx_w32(wad+0x48,4); fx_w32(wad+0x4c,4);
    fx_w32(wad+0x50,11); fx_w32(wad+0x54,22); fx_w32(wad+0x58,33);
    g.text=(char *)(uintptr_t)(wad+0x5c);
    for (unsigned i=0;i<8;++i) g.text[i]=(char)i;
    g_isZeus=0; g_pWADBaseAddress=(unsigned char *)(uintptr_t)wad;
    CHECK(CSprite_LoadFromChunk(s,yy,NULL)==1 && s->type==2 && s->skeleton,
          "chain_loader_constructs_skeleton");
    uint32_t sk=s->skeleton;
    CHECK(fx_r32(sk)==g.json && fx_r32(sk+4)==g.data && fx_r32(sk+8)==g.atlas,
          "chain_constructor_publishes_real_handles");
    if (mode==1) fx_w32(g.json+0xc,0); /* supported unowned-loader disposal arm */
    count=want_count=0;
    if (g.data) want('d',g.data);
    if (mode!=1) want('L',g.loader);
    want('F',mode==0?g.new18:g.p18); want('F',mode==0?g.new08:g.p08); want('F',g.json);
    if (mode==0) {
        want('T',19); want('F',g.new_name); want('F',g.page[0]);
        want('F',g.name[1]); want('F',g.page[1]);
        want('T',0xffffffffu); want('F',g.name[2]); want('F',g.page[2]);
        for (unsigned i=0;i<2;++i) {
            want('F',g.rn[i]); want('F',g.rs[i]); want('F',g.rp[i]); want('F',g.region[i]);
        }
    }
    if (g.atlas) want('F',g.atlas);
    want('D',sk); want('F',0); want('F',0);
    g_bFreeingSpineSprite=0xa5;
    CSprite_Clear(s); compare();
    CHECK(s->skeleton==0 && s->type==0 && s->width==1 && s->height==1 &&
          g_bFreeingSpineSprite==0, "chain_clear_retires_graph");
    count=want_count=0; want('F',0); want('F',0);
    CSprite_Clear(s); compare();
}
static int test_main(void)
{
    if (fx_map_arena()) { fx_puts("FIXTURE low arena unavailable\n"); return 90; }
    td_reset();
    CSprite *s=(CSprite *)(uintptr_t)alloc(sizeof *s);
    one_case(0,s); fx_puts("PASS chain_populated_spine\n");
    one_case(1,s); fx_puts("PASS chain_unowned_json_empty_atlas\n");
    one_case(2,s); fx_puts("PASS chain_null_atlas_and_data\n");
    yy_skel12 empty={0,0,0}; count=want_count=0;
    g_bFreeingSpineSprite=0xff;
    CHECK(CSkeletonSprite_D2(&empty)==&empty && g_bFreeingSpineSprite==0 && count==0,
          "chain_empty_dtor");
    fx_puts("PASS chain_empty_dtor\n");
    return 0;
}
#ifdef FX_FREESTANDING
void _start(void) { fx_exit(test_main()); }
#else
int main(void) { return test_main(); }
#endif
