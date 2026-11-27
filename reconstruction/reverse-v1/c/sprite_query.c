/* Static ARM32 translation candidates; original ELF has NOT been executed.
 * Sample SHA-256: 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * Sprite_Number: [0x1eee84,0x1eee98), final word literal pool.
 * Sprite_Exists: [0x1eee98,0x1eeee0), final two words literal pool.
 * Valid in-range lookups require a readable table and slot. The original does
 * not check the table pointer. Invalid pointers and races are outside the C
 * contract; behavior equivalence with the original remains unverified.
 */
#include "sprite_data.h"

int32_t Sprite_Number(void)
{
    return g_NumberOfSprites;              /* 1eee84..1eee90 */
}

int32_t Sprite_Exists(int32_t index)
{
    if (index < 0)                         /* 1eee98 cmp / 1eee9c blt */
        return 0;
    if (index >= g_NumberOfSprites)        /* 1eeea0..1eeeb0 */
        return 0;
    return g_SpriteItems.items[index] != NULL; /* 1eeeb4..1eeecc */
}
