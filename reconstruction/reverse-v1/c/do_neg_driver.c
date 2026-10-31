/* Stdin/stdout driver for the DoNeg reconstruction.
 *
 * Protocol (little endian, fixed record size so a truncated stream cannot be
 * mistaken for a shorter run):
 *   in  : <uint32 arg><16 raw slot bytes>            per case
 *   out : <uint32 ret_delta><16 raw slot bytes><128 err text, NUL padded>
 * ret_delta is 0 when the handler returned its `sp` argument unchanged, 1 when
 * it returned anything else (the arm under test never does).
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

unsigned char *DoNeg(uint32_t arg, unsigned char *sp, const unsigned char *base, void *exec);
const char *do_neg_last_error(void);

int main(void)
{
    unsigned char in[20];
    unsigned char out[4 + 16 + 128];
    unsigned char slot[16];

    while (fread(in, 1, sizeof in, stdin) == sizeof in) {
        uint32_t arg;
        memcpy(&arg, in, 4);
        memcpy(slot, in + 4, 16);
        unsigned char *ret = DoNeg(arg, slot, 0, 0);
        const char *err = do_neg_last_error();
        uint32_t delta = (ret == slot) ? 0u : 1u;
        memcpy(out, &delta, 4);
        memcpy(out + 4, slot, 16);
        memset(out + 20, 0, 128);
        if (err)
            strncpy((char *)(out + 20), err, 127);
        if (fwrite(out, 1, sizeof out, stdout) != sizeof out)
            return 2;
    }
    return 0;
}
