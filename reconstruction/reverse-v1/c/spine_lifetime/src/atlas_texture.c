/* _spAtlasPage_disposeTexture@[0xbd814,0xbd83c): 9 ARM instructions + literal.
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * Only reads page+0x1c and, when that is nonzero, g_bFreeingSpineSprite.
 * Nonzero flag enables GR_Texture_Free(id), including signed-negative id bits.
 * Static translation; no original execution or driver-equivalence claim. */
#include "yy_skel_deps.h"

void _spAtlasPage_disposeTexture(spAtlasPage *page)
{
    int32_t id = *(const int32_t *)((const unsigned char *)page + 0x1c); /* bd814 */
    if (id == 0) return;                         /* bd818 / bd81c bxeq */
    if (g_bFreeingSpineSprite == 0) return;       /* bd820..bd830 */
    GR_Texture_Free(id);                         /* bd834 tail b */
}
