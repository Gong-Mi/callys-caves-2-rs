/* Integrated synthetic consumer: Loader -> Clear -> three recovered resources.
 * No original binary executes. Remaining allocator, graphics and skeleton/SWF
 * builder dependencies are explicitly test doubles from the Loader fixture. */
#include "fx.h"
#include "csprite_loadfromchunk.h"
#include "test_doubles.h"
#include "yy_skel_deps.h"
extern void *memset(void *dst, int value, size_t n);

static uint32_t events[64];
static unsigned char kinds[64];
static unsigned n;
static void event(unsigned char kind, uint32_t value)
{
    if (n >= 64) { fx_puts("FAIL chain log overflow\n"); fx_exit(90); }
    kinds[n] = kind; events[n++] = value;
}
void MemoryManager_Free(const void *p) { event('F', (uint32_t)(uintptr_t)p); }
void GR_Texture_Free(int id) __asm__("_Z15GR_Texture_Freei");
void GR_Texture_Free(int id) { event('T', (uint32_t)id); }
void Sprite_operator_delete(void *p) { event('D', (uint32_t)(uintptr_t)p); }

#define CHECK(c, label) do { if (!(c)) { fx_puts("FAIL " label "\n"); fx_exit(20); } } while (0)
static void expect(const unsigned char *tags, const uint32_t *values, unsigned count)
{
    CHECK(n == count, "chain event count");
    for (unsigned i = 0; i < n; ++i)
        CHECK(kinds[i] == tags[i] && events[i] == values[i], "chain event sequence");
}

yy_glob_479c98 g_yy_479c98;
volatile uint8_t g_bFreeingSpineSprite;
static char *current_name;
static int spine_build_calls;
spAtlas *spAtlas_create(const char *data, int length, const char *dir, void *renderer)
{
    CHECK(data == current_name+4 && length==4 && dir && !dir[0] && !renderer,"atlas ABI");
    CHECK(g_yy_479c98.end==(uint32_t)(uintptr_t)(current_name+8) &&
          g_yy_479c98.w04==11 && g_yy_479c98.w08==22 && g_yy_479c98.w0c==33,"anonymous producer context");
    ++spine_build_calls;
    return (spAtlas *)(uintptr_t)0x1001;
}
spSkeletonJson *spSkeletonJson_create(spAtlas *p)
{
    CHECK((uintptr_t)p==0x1001,"json input atlas"); ++spine_build_calls;
    return (spSkeletonJson *)(uintptr_t)0x1002;
}
spSkeletonData *spSkeletonJson_readSkeletonData(spSkeletonJson *p, const char *text)
{
    static const unsigned char want[8]={0xd6,0xf3,0x30,0xed,0xda,0xf7,0x34,0xf1};
    CHECK((uintptr_t)p==0x1002 && text==current_name,"readSkeletonData input");
    for(unsigned i=0;i<8;++i) CHECK((unsigned char)text[i]==want[i],"actual decode consumed by spine boundary");
    ++spine_build_calls;
    return (spSkeletonData *)(uintptr_t)0x1003;
}
void spSkeletonData_dispose(spSkeletonData *p) { event('d',(uint32_t)(uintptr_t)p); }
void spSkeletonJson_dispose(spSkeletonJson *p) { event('j',(uint32_t)(uintptr_t)p); }
void spAtlas_dispose(spAtlas *p)
{
    CHECK(g_bFreeingSpineSprite==1,"real D2 flag window");
    event('a',(uint32_t)(uintptr_t)p);
}

int fx_main(void)
{
    CHECK(fx_map_arena() == 0, "low arena");
    CSprite *s = (CSprite *)(uintptr_t)fx_alloc(sizeof(CSprite));
    memset(s, 0, sizeof(*s));
    uint32_t rec = fx_alloc(84), ents = fx_alloc(24), obj = fx_alloc(0x60), objs = fx_alloc(4);
    fx_w32(ents, rec); fx_w32(obj, 1); fx_w32(obj+8, ents); fx_w32(obj+0x1c, 1); fx_w32(objs, obj);
    uint32_t value = fx_alloc(8), darr = fx_alloc(24), dict = fx_alloc(0x20);
    fx_w32(darr, value); fx_w32(dict, darr); fx_w32(dict+0x18, 1);
    uint32_t ids = fx_alloc(8), maskdata = fx_alloc(8), rows = fx_alloc(8);
    fx_w32(ids, 7); fx_w32(ids+4, 0xffffffffu);
    fx_w32(rows, 8); fx_w32(rows+4, maskdata);
    s->type = 1; s->swf_objects = objs; s->swf_object_count = 1; s->swf_dictionary = dict;
    s->texture_count = 2; s->texture_ids = ids;
    s->has_mask = 1; s->mask_count = 1; s->mask_rows = rows;
    n = 0;
    CSprite_Clear(s);
    {
        const unsigned char tags[] = {'F','F','F','F','F','F','F','T','F','F','F','F'};
        const uint32_t values[] = {rec,ents,obj,objs,value,darr,dict,7,0,ids,maskdata,rows};
        expect(tags, values, 12);
    }
    CHECK(s->swf_objects == 0 && s->swf_object_count == 0 && s->swf_dictionary == 0, "SWF handoff");
    CHECK(s->mask_rows == 0 && s->mask_count == 0 && s->has_mask == 0, "mask handoff");
    CHECK(s->texture_ids == 0 && s->texture_count == 0, "texture handoff");
    CHECK(fx_r32(ids) == 0xffffffffu && fx_r32(rows) == 0 && fx_r32(rows+4) == 0, "freed slot writes");
    CHECK(s->width == 1 && s->height == 1 && s->type == 0, "Clear defaults");
    fx_puts("PASS chain C1 all resources via Clear\n");
    n = 0;
    CSprite_Clear(s);
    {
        const unsigned char tags[] = {'F','F'};
        const uint32_t values[] = {0,0};
        expect(tags, values, 2);
    }
    fx_puts("PASS chain C2 repeated Clear\n");
    uint32_t wad = fx_alloc(512);
    YYSprite *yy = (YYSprite *)(uintptr_t)wad;
    yy->width = 3; yy->height = 4; yy->textureCount = 1;
    fx_w32(wad+0x3c, 0x100); fx_w32(wad+0x40, 0);
    td_reset(); g_isZeus = 0; g_pWADBaseAddress = (unsigned char *)(uintptr_t)wad;
    CHECK(CSprite_LoadFromChunk(s, yy, NULL) == 1, "real Loader return");
    CHECK(s->frame_count == 1 && s->width == 3 && s->height == 4 && s->field_2c == 5, "real Loader fields");
    CHECK(fx_r32(s->local_tpe) == wad+0x100, "real Loader table");
    CSprite_Clear(s);
    CHECK(s->frame_count == 0 && s->local_tpe == 0 && s->type == 0, "real Load-Clear handoff");
    fx_puts("PASS chain C3 Loader plus all cleanup translations\n");
    uint32_t wad2 = fx_alloc(512);
    YYSprite *yy2 = (YYSprite *)(uintptr_t)wad2;
    yy2->width=3; yy2->height=4; yy2->textureCount=-1;
    fx_w32(wad2+0x40,2);
    fx_w32(wad2+0x48,4); fx_w32(wad2+0x4c,4);
    fx_w32(wad2+0x50,11); fx_w32(wad2+0x54,22); fx_w32(wad2+0x58,33);
    current_name=(char *)(uintptr_t)(wad2+0x5c);
    for(unsigned i=0;i<8;++i) current_name[i]=(char)i;
    g_pWADBaseAddress=(unsigned char *)(uintptr_t)wad2;
    g_bFreeingSpineSprite=0; spine_build_calls=0;
    CHECK(CSprite_LoadFromChunk(s,yy2,NULL)==1,"real skeleton Loader return");
    CHECK(s->type==2 && s->frame_count==0x7fffffff && s->skeleton!=0 && spine_build_calls==3,"real skeleton construction path");
    uint32_t sk=s->skeleton;
    n=0;
    CSprite_Clear(s);
    {
        const unsigned char tags[]={'d','j','a','D','F','F'};
        const uint32_t values[]={0x1003,0x1002,0x1001,sk,0,0};
        expect(tags,values,6);
    }
    CHECK(s->skeleton==0 && g_bFreeingSpineSprite==0,"real skeleton destruction handoff");
    fx_puts("PASS chain C4 real skeleton ctor-decode-dtor via Loader-Clear\n");
    fx_puts("ALL CHAIN OK\n");
    return 0;
}
#ifdef FX_FREESTANDING
void _start(void) { fx_exit(fx_main()); }
#else
int main(void) { return fx_main(); }
#endif
