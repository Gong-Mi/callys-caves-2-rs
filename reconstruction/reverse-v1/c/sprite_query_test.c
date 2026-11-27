/* Synthetic consumer for the statically recovered Sprite_Number / Sprite_Exists.
 * Does not execute the original binary. */
#include "sprite_data.h"
#include <stdint.h>
#include <stdio.h>

int32_t Sprite_Number(void) __asm__("_Z13Sprite_Numberv");
int32_t Sprite_Exists(int32_t index) __asm__("_Z13Sprite_Existsi");
struct CSprite { int marker; };
SpriteItems g_SpriteItems;
int32_t g_NumberOfSprites;

#define CHECK(name, expression, expected) do { \
    int32_t actual_ = (expression); ++checks; \
    if (actual_ != (expected)) { \
        fprintf(stderr, "FAIL %s: got=%d expected=%d\n", (name), actual_, (expected)); \
        ++bad; \
    } \
} while (0)

int main(void)
{
    struct CSprite a = {1}, b = {2}, wrong = {3}, guard = {4};
    CSprite *real[] = { &a, NULL, &b, &guard };
    CSprite *decoys[] = { NULL, &wrong, NULL, &wrong };
    SpriteItems decoy = { 0, decoys };
    int checks = 0, bad = 0;
    g_SpriteItems.unknown0 = (uintptr_t)&decoy;
    g_SpriteItems.items = real;
    g_NumberOfSprites = 3;
    CHECK("number-three", Sprite_Number(), 3);
    CHECK("negative", Sprite_Exists(-1), 0);
    CHECK("int-min", Sprite_Exists(INT32_MIN), 0);
    CHECK("first-real-table", Sprite_Exists(0), 1);
    CHECK("null-slot", Sprite_Exists(1), 0);
    CHECK("last-valid", Sprite_Exists(2), 1);
    CHECK("upper-bound", Sprite_Exists(3), 0);
    CHECK("int-max", Sprite_Exists(INT32_MAX), 0);
    CHECK("data-consumer-first", Sprite_Exists(0) == (Sprite_Data(0) != NULL), 1);
    CHECK("data-consumer-null", Sprite_Exists(1) == (Sprite_Data(1) != NULL), 1);
    CHECK("data-consumer-negative", Sprite_Exists(-1) == (Sprite_Data(-1) != NULL), 1);
    /* Stop before the NULL table cases if a bound mutant already failed. */
    if (bad) return 1;
    g_NumberOfSprites = 0;
    g_SpriteItems.items = NULL;
    CHECK("number-zero", Sprite_Number(), 0);
    CHECK("empty-avoids-table", Sprite_Exists(0), 0);
    g_NumberOfSprites = -1;
    CHECK("negative-count", Sprite_Exists(0), 0);
    if (bad) return 1;
    printf("sprite-query synthetic fixture: %d/14 PASS\n", checks);
    return checks == 14 ? 0 : 1;
}
