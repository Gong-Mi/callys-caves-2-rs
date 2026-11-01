/* Sprite_Data: static ARM32 translation candidate, NOT oracle verified.
 * Sample SHA-256: 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * _Z11Sprite_Datai @0x1ef03c..0x1ef074; trailing two words are literal data.
 * Source anchors: reconstruction/reverse-v1/cards/Sprite_Data.c.
 * Contract: g_NumberOfSprites and g_SpriteItems are external host-provided
 * globals; if 0<=index<count, the items pointer and indexed slot must be
 * readable. Original does not check NULL or allocation size. Invalid pointer
 * and races are outside defined C semantics; no replacement behavior is added.
 * Runtime behavior and binary equivalence have not been compared to original.
 */
#include "sprite_data.h"

CSprite *Sprite_Data(int32_t index)
{
    if (index < 0)                         /* 0x1ef03c cmp / 0x1ef040 blt */
        return NULL;                       /* 0x1ef06c mov / 0x1ef070 bx */
    if (index >= g_NumberOfSprites)        /* 0x1ef044..0x1ef054 */
        return NULL;
    return g_SpriteItems.items[index];     /* 0x1ef058..0x1ef068 */
}
