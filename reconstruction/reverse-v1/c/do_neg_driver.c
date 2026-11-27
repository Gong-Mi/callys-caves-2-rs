/* Stdin/stdout driver for the DoNeg reconstruction.
 *
 *   in  : <uint32 arg><64-byte arena>          (operand slot lives at arena+32)
 *   out : <int32 ret_delta><64-byte arena><128 err text, NUL padded>
 *
 * The arena has 32 bytes of slack *below* the operand slot on purpose: mode 1
 * and mode 2 write the result at `boxed - 16`, i.e. below the incoming sp, so a
 * 16-byte-only comparison would never see what those arms produce.
 * `ret_delta` is the returned pointer minus the slot address.
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

unsigned char *DoNeg(uint32_t arg, unsigned char *sp, const unsigned char *base, void *exec);
const char *do_neg_last_error(void);

#define SLOT_OFF 32

int main(void)
{
    unsigned char in[4 + 64];
    unsigned char out[4 + 64 + 128];

    while (fread(in, 1, sizeof in, stdin) == sizeof in) {
        uint32_t arg;
        memcpy(&arg, in, 4);
        unsigned char arena[64];
        memcpy(arena, in + 4, 64);
        memset(arena, 0xEE, SLOT_OFF);
        unsigned char *slot = arena + SLOT_OFF;
        unsigned char *ret = DoNeg(arg, slot, 0, 0);
        const char *err = do_neg_last_error();
        int32_t delta = (int32_t)(ret - slot);
        memcpy(out, &delta, 4);
        memcpy(out + 4, arena, 64);
        memset(out + 68, 0, 128);
        if (err)
            strncpy((char *)(out + 68), err, 127);
        if (fwrite(out, 1, sizeof out, stdout) != sizeof out)
            return 2;
    }
    return 0;
}
