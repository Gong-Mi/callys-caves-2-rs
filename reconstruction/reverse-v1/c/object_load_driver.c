/* Stdin/stdout driver for the CObjectGM::LoadFromChunk header reconstruction.
 *
 *   in  : <32-byte record>            (src+0x20.. stays zero: version-gated tail
 *                                      is outside this arm's domain)
 *   out : <int32 ret><0x20 dst bytes><uint32 hi_bits>
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int CObjectGM_LoadFromChunk(unsigned char *dst, const unsigned char *src);
void object_load_reset(void);
uint32_t object_load_hi_bits(void);

int main(void)
{
    unsigned char in[32];
    unsigned char out[4 + 0x20 + 4];
    unsigned char dst[0x100];

    while (fread(in, 1, sizeof in, stdin) == sizeof in) {
        memset(dst, 0, sizeof dst);
        object_load_reset();
        int ret = CObjectGM_LoadFromChunk(dst, in);
        uint32_t hi = object_load_hi_bits();
        memcpy(out, &ret, 4);
        memcpy(out + 4, dst, 0x20);
        memcpy(out + 4 + 0x20, &hi, 4);
        if (fwrite(out, 1, sizeof out, stdout) != sizeof out)
            return 2;
    }
    return 0;
}
