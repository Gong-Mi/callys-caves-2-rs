/* arm32_support.c — ARM32 freestanding 构建的最小运行时（不进 host 构建）
 *
 * 只用静态 BSS，不链接 libc：qemu-arm 直接跑自建译文，不加载原件、不依赖
 * 任何 ARM32 sysroot。除法助手是必要的，因为 armv7-a 默认没有 UDIV 指令，
 * clang 会把 /10 与 %10 变成 __aeabi_uidivmod。
 */
#include <stddef.h>
#include <stdint.h>

void *memcpy(void *dst, const void *src, size_t n)
{
    uint8_t *d = (uint8_t *)dst;
    const uint8_t *s = (const uint8_t *)src;
    for (size_t i = 0; i < n; ++i) d[i] = s[i];
    return dst;
}

void *memset(void *dst, int c, size_t n)
{
    uint8_t *d = (uint8_t *)dst;
    for (size_t i = 0; i < n; ++i) d[i] = (uint8_t)c;
    return dst;
}

void *memmove(void *dst, const void *src, size_t n)
{
    uint8_t *d = (uint8_t *)dst;
    const uint8_t *s = (const uint8_t *)src;
    if (d < s) { for (size_t i = 0; i < n; ++i) d[i] = s[i]; }
    else       { for (size_t i = n; i > 0; --i) d[i - 1] = s[i - 1]; }
    return dst;
}
