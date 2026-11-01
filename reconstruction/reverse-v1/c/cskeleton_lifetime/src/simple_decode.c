/* CSkeletonSprite::SimpleDecode@0xbd840 [0xbd840,0xbd86c), 11 ARM instructions.
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * Static translation only; self is not read. For length>0 the buffer must be
 * writable for length bytes without address-space wrap. Original not executed. */
#include "yy_skel_deps.h"

void CSkeletonSprite_SimpleDecode(void *self, unsigned char *buf, int len)
{
    (void)self;
    if (len <= 0) return;                       /* bd840 cmp / bd844 bxle */
    uint32_t key = 42;                          /* bd84c */
    for (uint32_t i = 0; i < (uint32_t)len; ++i) {
        buf[i] = (unsigned char)((uint32_t)buf[i] - key); /* bd850..bd858 */
        key = key * key + key;                  /* bd860 mla, mod 2^32 */
    }
}
