/* ARM32 global contract for Sprite_Data; source type names remain unknown.
 * The native fixture uses host pointers only to exercise control flow, not ABI.
 */
#ifndef REVERSE_V1_SPRITE_DATA_H
#define REVERSE_V1_SPRITE_DATA_H
#include <stddef.h>
#include <stdint.h>

typedef struct CSprite CSprite;
typedef struct SpriteItems {
    uintptr_t unknown0;
    CSprite **items;
} SpriteItems;
#if UINTPTR_MAX == 0xffffffffu
_Static_assert(offsetof(SpriteItems, items) == 4, "ARM32 items offset");
_Static_assert(sizeof(SpriteItems) == 8, "ARM32 g_SpriteItems size");
#endif
extern SpriteItems g_SpriteItems;
extern int32_t g_NumberOfSprites;
CSprite *Sprite_Data(int32_t index) __asm__("_Z11Sprite_Datai");
int32_t Sprite_Number(void) __asm__("_Z13Sprite_Numberv");
int32_t Sprite_Exists(int32_t index) __asm__("_Z13Sprite_Existsi");
#endif
