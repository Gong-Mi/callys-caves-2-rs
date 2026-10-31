/* Stdin/stdout driver for the boxType reconstruction.
 *
 *   in  : <uint32 type><16 src bytes>
 *   out : <int32 consumed><16 dst bytes>
 * `consumed` is the returned source-pointer advance (the original returns
 * src + consumed, and every caller uses it that way).
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

unsigned char *boxType(unsigned char *dst, unsigned type, const unsigned char *src);

int main(void)
{
    unsigned char in[20];
    unsigned char out[20];
    unsigned char dst[16];
    unsigned char src[16];

    while (fread(in, 1, sizeof in, stdin) == sizeof in) {
        uint32_t type;
        memcpy(&type, in, 4);
        memcpy(src, in + 4, 16);
        memset(dst, 0xEE, sizeof dst);
        unsigned char *ret = boxType(dst, type, src);
        int32_t consumed = (int32_t)(ret - src);
        memcpy(out, &consumed, 4);
        memcpy(out + 4, dst, 16);
        if (fwrite(out, 1, sizeof out, stdout) != sizeof out)
            return 2;
    }
    return 0;
}
