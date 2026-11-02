/* Synthetic boundary fixture for the recovered page texture callback. */
#include "yy_skel_deps.h"
#include "fx.h"
volatile uint8_t g_bFreeingSpineSprite;
static unsigned calls;
static int last;
void GR_Texture_Free(int id) { ++calls;last=id; }
#define CHECK(c,s) do {if(!(c)){fx_puts("FAIL " s "\n");return 1;}}while(0)
static int test_main(void)
{
    CHECK(fx_map_arena()==0,"arena");
    uint32_t p=fx_alloc(44);
    spAtlasPage *page=(spAtlasPage *)(uintptr_t)p;
    g_bFreeingSpineSprite=1;
    _spAtlasPage_disposeTexture(page);
    CHECK(calls==0,"zero_id_gate");
    fx_puts("PASS zero_id_gate\n");
    fx_w32(p+0x1c,19);
    g_bFreeingSpineSprite=0;
    _spAtlasPage_disposeTexture(page);
    CHECK(calls==0,"zero_flag_gate");
    fx_puts("PASS zero_flag_gate\n");
    g_bFreeingSpineSprite=1;
    _spAtlasPage_disposeTexture(page);
    CHECK(calls==1 && last==19 && g_bFreeingSpineSprite==1 && fx_r32(p+0x1c)==19,"positive_flag_forwards");
    fx_puts("PASS positive_flag_forwards\n");
    fx_w32(p+0x1c,0xffffffffu);
    g_bFreeingSpineSprite=0xff;
    _spAtlasPage_disposeTexture(page);
    CHECK(calls==2 && last==-1 && g_bFreeingSpineSprite==0xff,"any_nonzero_flag_forwards_bits");
    fx_puts("PASS any_nonzero_flag_forwards_bits\n");
    return 0;
}
#ifdef FX_FREESTANDING
void _start(void){fx_exit(test_main());}
#else
int main(void){return test_main();}
#endif
