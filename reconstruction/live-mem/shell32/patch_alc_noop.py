#!/usr/bin/env python3
"""Noop-patch the alc (device/context) layer in the SHELL's runtime libopenal copy.

Background (live-findings-v2 §8/§9): the previous round patched 25 al* leaf
exports to `mov r0,#0; bx lr`, but the INIT path dies before any of them
matters: Audio_Initialize (libyoyo 0x221a40..) calls
  alcOpenDevice -> alcCreateContext -> alcMakeContextCurrent
and each NULL result routes to the error paths (log codes 0x202/0x203/0x20a).
Under hbt the opensl backend fails, so the device never opens, the manager S
(0x7553AC) stays NULL and the whole audio state machine is dead — flipping the
F_ layer gate bytes alone changes nothing (re-verified this round: gates stay 0,
bump slot and mgr never move, obj_music soundplay frozen at 0).

Fix: make the three init calls succeed with fake tokens, and stub every other
imported alc function that would dereference the fake device/context pointers.
Encodings are pure leaf `mov r0,#imm; bx lr` — hbt-safe subset (no pc/lr/abs
addressing), same as the 25 al* patches.

Only the runtime copy under shell32/work/libs is touched; the .orig file is
pristine and the pinned evidence copy in the repo is never modified.
"""
import struct, sys, shutil, os

LIB = "/data/data/com.termux/files/home/cally-work/shell32/work/libs/libopenal.so"
ORIG = LIB + ".orig"

MOVR0_0 = struct.pack("<II", 0xE3A00001 & ~0xF, 0xE12FFF1E)  # placeholder, fixed below
INS1 = struct.pack("<II", 0xE3A00001, 0xE12FFF1E)  # mov r0,#1 ; bx lr
INS0 = struct.pack("<II", 0xE3A00000, 0xE12FFF1E)  # mov r0,#0 ; bx lr

# (name, vaddr, ret, why)
TARGETS = [
    ("alcOpenDevice",        0x197F8, INS1, "fake device token 1"),
    ("alcCreateContext",     0x1B7D0, INS1, "fake context token 1"),
    ("alcMakeContextCurrent",0x1D294, INS1, "ALC_TRUE"),
    ("alcGetCurrentContext", 0x189D4, INS1, "fake ctx so guards pass"),
    ("alcGetContextsDevice", 0x1D39C, INS1, "fake dev"),
    ("alcDestroyContext",    0x1D3CC, INS0, "must not deref fake ctx"),
    ("alcCloseDevice",       0x1D0FC, INS0, "must not deref fake dev"),
    ("alcGetString",         0x1AE9C, INS0, "NULL string (callers log it)"),
    ("alcGetIntegerv",       0x1B20C, INS0, "no writes; caller keeps old value"),
    ("alcGetError",          0x1AE30, INS0, "ALC_NO_ERROR"),
    ("alcPauseCurrentDevice",  0x1D4BC, INS1, "ALC_TRUE, no deref"),
    ("alcResumeCurrentDevice", 0x1D4F8, INS1, "ALC_TRUE, no deref"),
    ("alcCaptureOpenDevice",   0x1A0DC, INS0, "capture never works"),
    ("alcCaptureCloseDevice",  0x1C7B8, INS0, "no deref"),
    ("alcCaptureStart",        0x1C898, INS0, "no deref"),
    ("alcCaptureStop",         0x1C940, INS0, "no deref"),
    ("alcCaptureSamples",      0x1C9E4, INS0, "no deref"),
    # remaining imported al* still real in the runtime copy (previous round
    # patched only 25): any of them would deref the fake context token.
    ("alGetBufferi",           0x0F678, INS0, ""),
    ("alGetBufferiv",          0x0F7F4, INS0, ""),
    ("alIsBuffer",             0x0E4D4, INS0, "FALSE (also avoids ctx deref)"),
    ("alIsBufferFormatSupportedSOFT", 0x0E52C, INS0, ""),
    ("alGetSourcefv",          0x14C24, INS0, ""),
    ("alGetSourceiv",          0x15074, INS0, ""),
    ("alGetSourcei64SOFT",     0x15114, INS0, ""),
    ("alGetSourcei64vSOFT",    0x1528C, INS0, ""),
    ("alSourcePlayv",          0x17524, INS0, ""),
    ("alSourcePausev",         0x176D8, INS0, ""),
    ("alSourceStopv",          0x17824, INS0, ""),
    ("alSourcei64SOFT",        0x17158, INS0, ""),
    ("alSourcei64vSOFT",       0x17280, INS0, ""),
]

data = bytearray(open(LIB, "rb").read())
orig = open(ORIG, "rb").read()
assert len(orig) == len(data)

changed = 0
for name, va, ins, why in TARGETS:
    cur = bytes(data[va:va + 8])
    if cur == ins:
        print(f"{name:22s} @{va:#x} already patched")
        continue
    ob = bytes(orig[va:va + 8])
    # sanity: pristine bytes must be a real prologue (push/stmdb/fmrx/ldr), not a leaf stub
    w = struct.unpack("<I", ob[0:4])[0]
    ok_prologue = (w >> 24) in (0xE9, 0xE5, 0xEE, 0xE1, 0xF8, 0xF5) or (w >> 26) != 0x3A
    print(f"{name:22s} @{va:#x} orig={ob.hex()} -> {ins.hex()}  ({why})")
    if not ok_prologue:
        sys.exit(f"unexpected prologue at {name}; aborting")
    data[va:va + 8] = ins
    changed += 1

if "--write" in sys.argv and changed:
    bak = LIB + ".pre-alc"
    if not os.path.exists(bak):
        shutil.copyfile(LIB, bak)
    open(LIB, "wb").write(bytes(data))
    print(f"wrote {changed} patches; previous copy backed up at {bak}")
elif changed:
    print(f"dry-run: {changed} patches pending (rerun with --write)")
