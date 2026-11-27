/* Stdin/stdout driver for the DoNot reconstruction.
 *
 *   in  : <uint32 arg><64-byte arena>          (operand slot lives at arena+32)
 *   out : <int32 ret_delta><64-byte arena><128 err text, NUL padded>
 *
 * Same arena discipline as do_neg_driver.c: mode 1 writes its 1-byte boolean
 * at `boxed - 4`, which can land below the incoming sp, so the compared window
 * is 64 bytes with 32 bytes of poisoned slack underneath.
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

unsigned char *DoNot(uint32_t arg, unsigned char *sp, const unsigned char *base, void *exec);
const char *do_not_last_error(void);

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
        unsigned char *ret = DoNot(arg, slot, 0, 0);
        const char *err = do_not_last_error();
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
