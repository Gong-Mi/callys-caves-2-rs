# SUPERSEDED: hbt 下 .text 补丁不可行（见 contracts/live-oracle.md §3）;
# 保留仅作失败过程记录。可用子集是「纯直链 bl + 不依赖 pc/lr」的指令。
#!/usr/bin/env python3
"""Patch the shell's libyoyo copy: log every Audio_PlaySound(index,prio,loop).

Hook: Audio_PlaySound entry (0x21b5d8) -> 8-byte ldr-pc trampoline into a cave
carved over F_YoYo_FacebookGraphRequest (0x1572ac, 0x7c bytes, unreachable in
this game). Logger calls __android_log_vprint@plt (0xb661c):
  tag "sndhook", fmt "SNDHOOK idx=%d" (+loop stacked, logged via fmt later).

Only the shell runtime copy is patched; the pinned evidence copy
(reconstruction/live-mem/libyoyo_armv7.so) is never touched.
"""
import shutil, struct

LIB = '/data/data/com.termux/files/home/cally-work/shell32/work/libs/libyoyo.so'
ENTRY = 0x21b5d8
CAVE  = 0x1572ac
VPRINT_PLT = 0xb661c

data = bytearray(open(LIB, 'rb').read())
assert data[:4] == b'\x7fELF', 'not an ELF'
open(LIB + '.orig', 'ab').close()
if open(LIB + '.orig', 'rb').read(4) != data[:4] or \
   len(open(LIB + '.orig', 'rb').read()) != len(data):
    shutil.copyfile(LIB, LIB + '.orig')

orig = bytes(data[ENTRY:ENTRY+8])
push_mask = struct.unpack('<I', orig[0:4])[0]
print(f'entry orig: {orig.hex()}  (expect e92d43f0 push{{r4-r9,lr}} + vpush)')

code  = b''
code += struct.pack('<I', 0xE92D400F)          # push {r0-r3, lr}
code += struct.pack('<I', 0xE59D0014)          # ldr r0, [sp, #20]   (loop, entry stack arg)
code += struct.pack('<I', 0xE92D0001)          # push {r0}           (vararg slot)
code += struct.pack('<I', 0xE1A0300D)          # mov r3, sp          (ap)
code += struct.pack('<I', 0xE3A00004)          # mov r0, #4          (INFO)
code += struct.pack('<I', 0xE59F1024)          # ldr r1, [pc, #0x24] -> tag
code += struct.pack('<I', 0xE59F2028)          # ldr r2, [pc, #0x28] -> fmt
code += struct.pack('<I', 0xE59FC034)          # ldr r12,[pc, #0x34] -> vprint PLT
code += struct.pack('<I', 0xE12FFF3C)          # blx r12
code += struct.pack('<I', 0xE28DD004)          # add sp, sp, #4
code += struct.pack('<I', 0xE8BD400F)          # pop {r0-r3, lr}
code += orig                                    # replay relocated entry instrs
code += struct.pack('<I', 0xE51FF004)          # ldr pc, [pc, #-4]
code += struct.pack('<I', ENTRY + 8)           # return address
code += b'sndhook\x00\x00'                      # Ltag
code += b'SNDHOOK idx=%d\x00\x00\x00\x00'       # Lfmt (16)
code += struct.pack('<I', VPRINT_PLT)          # Lvprint
assert len(code) <= 0x7c, f'cave overflow: {len(code)}'

# entry trampoline
data[ENTRY:ENTRY+8] = struct.pack('<II', 0xE51FF004, CAVE)
data[CAVE:CAVE+len(code)] = code
open(LIB, 'wb').write(bytes(data))
print(f'patched: entry@{ENTRY:#x} -> cave@{CAVE:#x} ({len(code)} bytes), '
      f'backup at {LIB}.orig')
