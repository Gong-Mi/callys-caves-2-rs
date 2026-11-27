/* Independent consumer fixture: inputs/expectations synthesized from the
 * static instruction contract, not from an execution of the original. */
#include "sprite_data.h"
#include <limits.h>
#include <stdio.h>

struct CSprite { int marker; };
SpriteItems g_SpriteItems;
int32_t g_NumberOfSprites;

static int check(const char *name, CSprite *got, CSprite *want)
{
    if (got == want) return 0;
    fprintf(stderr, "FAIL %s\n", name);
    return 1;
}
int main(void)
{
    struct CSprite a={11}, b={22}, wrong={33}, guard={44};
    CSprite *actual[] = { &a, NULL, &b, &guard };
    CSprite *decoys[] = { &wrong, &wrong, &wrong, &wrong };
    SpriteItems decoy = { 0, decoys };
    int bad = 0;
    g_SpriteItems.unknown0 = (uintptr_t)&decoy;
    g_SpriteItems.items = actual;
    g_NumberOfSprites = 3;
    bad += check("negative", Sprite_Data(-1), NULL);
    bad += check("int_min", Sprite_Data(INT32_MIN), NULL);
    bad += check("first from real +4", Sprite_Data(0), &a);
    bad += check("null slot", Sprite_Data(1), NULL);
    bad += check("last valid", Sprite_Data(2), &b);
    bad += check("count boundary", Sprite_Data(3), NULL);
    if (bad) return 1;  /* stop before NULL-table cases if a mutant crossed a bound */
    bad += check("int_max", Sprite_Data(INT32_MAX), NULL);
    g_NumberOfSprites = 0;
    g_SpriteItems.items = NULL;
    bad += check("empty count avoids table", Sprite_Data(0), NULL);
    g_NumberOfSprites = -1;
    bad += check("negative count", Sprite_Data(0), NULL);
    if (bad) return 1;
    puts("sprite_data static-contract fixture: 9/9 PASS");
    return 0;
}
