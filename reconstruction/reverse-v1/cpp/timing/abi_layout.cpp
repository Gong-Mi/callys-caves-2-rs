#include "timing.hpp"
static_assert(sizeof(RunnerTimespec32) == 8, "original two-word clock sample");
static_assert(offsetof(RunnerTimespec32, nanoseconds) == 4, "original sample+4");
static_assert(sizeof(TimingWords) == 8 && alignof(TimingWords) == 8,
              "paired epoch storage view");
