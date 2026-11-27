#include "object_helpers.hpp"

extern "C" int strcmp(const char *, const char *);

namespace {
constexpr uint32_t kKindMask = 0x00ffffffu;

struct DoubleWords {
    uint32_t low;
    uint32_t high;
};
static_assert(sizeof(DoubleWords) == 8, "ARM32 double image must be two words");
static_assert(sizeof(double) == 8, "SameValue numeric payload is binary64");
}

uint32_t JS_SameValue(RValue *left, RValue *right) {
    const uint32_t left_image = object_wire::address(left);
    const uint32_t right_image = object_wire::address(right);
    const uint32_t left_kind_word = object_wire::read(left_image, 0x0c);
    const uint32_t right_kind_word = object_wire::read(right_image, 0x0c);
    if (((left_kind_word ^ right_kind_word) & kKindMask) != 0u) {
        return 0;
    }

    const uint32_t kind = left_kind_word & kKindMask;
    switch (kind) {
    case 0u:
    case 7u:
    case 8u:
    case 11u: {
        const DoubleWords left_words{object_wire::read(left_image, 0x00),
                                     object_wire::read(left_image, 0x04)};
        const DoubleWords right_words{object_wire::read(right_image, 0x00),
                                      object_wire::read(right_image, 0x04)};
        double left_number;
        double right_number;
        __builtin_memcpy(&left_number, &left_words, sizeof(left_number));
        __builtin_memcpy(&right_number, &right_words, sizeof(right_number));
        return left_number == right_number ? 1u : 0u;
    }
    case 1u: {
        const uint32_t left_wrapper = object_wire::read(left_image, 0x00);
        const uint32_t right_wrapper = object_wire::read(right_image, 0x00);
        const uint32_t left_text = object_wire::read(left_wrapper, 0x00);
        const uint32_t right_text = object_wire::read(right_wrapper, 0x00);
        const char *left_string = reinterpret_cast<const char *>(
            static_cast<uintptr_t>(left_text));
        const char *right_string = reinterpret_cast<const char *>(
            static_cast<uintptr_t>(right_text));
        return strcmp(left_string, right_string) == 0 ? 1u : 0u;
    }
    case 5u:
    case 12u:
        return 1;
    case 6u:
        return object_wire::read(left_image, 0x00) ==
                       object_wire::read(right_image, 0x00)
                   ? 1u
                   : 0u;
    default:
        return 0;
    }
}
