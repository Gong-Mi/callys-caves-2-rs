# Cross-reference: spine-c 3.8 SkeletonJson.c
# Source: https://github.com/EsotericSoftware/spine-runtimes/tree/3.8 (Spine Runtimes License, Esoteric Software)
# Usage: semantic cross-check ONLY. All C translations in c/ are derived from
# libyoyo_armv7.so disassembly (SHA256 3bbedd09...). Malloc tag evidence
# (jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c, lines 442-1043)
# proves the binary embeds a GameMaker-adapted spine-c 3.8.
# Layout confirmation: _spSkeletonJson internal struct at +0x0c ownsLoader,
# +0x10 linkedMeshCount, +0x14 linkedMeshCapacity, +0x18 linkedMeshes.

