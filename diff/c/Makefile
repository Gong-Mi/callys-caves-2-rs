# diff/c — C reference implementation for the milestone-1 opcode diff.
# Build:  make -C diff/c        →  clang -O2 -std=c11
# Override the compiler with:  make -C diff/c CC=gcc
TARGET  := vm_ref
CC      := clang
CFLAGS  := -O2 -std=c11 -Wall -Wextra -Wno-unused-parameter
LDLIBS  := -lm

all: $(TARGET)

$(TARGET): vm_ref.c
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

check: $(TARGET)
	./smoke.sh

clean:
	rm -f $(TARGET)

.PHONY: all check clean
