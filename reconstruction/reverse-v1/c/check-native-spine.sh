#!/data/data/com.termux/files/usr/bin/sh
# Build/run reconstructed ARM32 C only; never load the original library.
set -eu
C=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
if [ "$#" -gt 0 ]; then
    B=$1
    mkdir -- "$B"
else
    B=$(mktemp -d "${TMPDIR:?set TMPDIR to private scratch}/cally-native-spine.XXXXXXXX")
    trap 'rm -rf -- "$B"' EXIT HUP INT TERM
fi
build_run() {
    name=$1; shift
    clang --target=armv7a-none-eabi -march=armv7-a -marm -mfloat-abi=soft \
      -std=c11 -O2 -ffreestanding -fno-builtin -fno-stack-protector \
      -Wall -Wextra -Werror -nostdlib -static -fuse-ld=lld -Wl,-e,_start \
      -DFX_FREESTANDING -I"$C/spine_alloc/src" -I"$C/spine_attachment/src" \
      -I"$C/spine_skeleton_data/src" -I"$C/spine_lifetime/src" \
      -I"$C/cskeleton_lifetime/src" -I"$C/csprite_resources/fixture" \
      "$@" -o "$B/$name.arm"
    qemu-arm "$B/$name.arm" > "$B/$name.log"
    printf 'PASS %s\n' "$name"
}
build_run allocation "$C/spine_alloc/src/spine_alloc.c" "$C/spine_alloc/fixture/check.c"
build_run attachment "$C/spine_attachment/src/spine_attachment.c" "$C/spine_attachment/fixture/check.c"
build_run skeleton_data "$C/spine_skeleton_data/src/spine_skeleton_data.c" \
  "$C/spine_skeleton_data/fixture/check.c" "$C/csprite_resources/fixture/arm32_support.c"
build_run native_chain "$C/spine_alloc/src/spine_alloc.c" \
  "$C/spine_attachment/src/spine_attachment.c" "$C/spine_skeleton_data/src/spine_skeleton_data.c" \
  "$C/spine_lifetime/src/spine_json_lifetime.c" "$C/spine_lifetime/src/atlas_dispose.c" \
  "$C/spine_lifetime/src/atlas_texture.c" "$C/cskeleton_lifetime/src/skeleton_lifetime.c" \
  "$C/cskeleton_lifetime/src/simple_decode.c" "$C/spine_skeleton_data/fixture/integration.c" \
  "$C/csprite_resources/fixture/arm32_support.c"
printf 'BOUNDARY: reconstructed ARM32 plus declared providers; original not executed\n'
printf 'OUTPUT %s\n' "$B"
