#!/usr/bin/env python3
import struct
import json
import os

ASSET_DIR = "/data/data/com.termux/files/home/callys-caves-2-rs/assets"
DROID_PATH = "/data/data/com.termux/files/usr/tmp/cally_caves_2/apk/assets/game.droid"

os.makedirs(f"{ASSET_DIR}/textures", exist_ok=True)
os.makedirs(f"{ASSET_DIR}/audio", exist_ok=True)
os.makedirs(f"{ASSET_DIR}/json", exist_ok=True)

with open(DROID_PATH, "rb") as f:
    form = f.read(4)
    form_len = struct.unpack("<I", f.read(4))[0]

    chunks = {}
    while f.tell() < form_len + 8:
        pos = f.tell()
        name_buf = f.read(4)
        if not name_buf or len(name_buf) < 4: break
        csize = struct.unpack("<I", f.read(4))[0]
        cname = name_buf.decode("latin1", errors="ignore")
        chunks[cname] = (pos + 8, csize)
        pad = (csize + 3) & ~3
        f.seek(pos + 8 + pad)

    # 1. Dump Textures (TXTR)
    if "TXTR" in chunks:
        pos, size = chunks["TXTR"]
        f.seek(pos)
        count = struct.unpack("<I", f.read(4))[0]
        ptrs = [struct.unpack("<I", f.read(4))[0] for _ in range(count)]
        png_offsets = []
        for p in ptrs:
            f.seek(p + 4)
            png_offsets.append(struct.unpack("<I", f.read(4))[0])
        png_offsets.append(chunks["AUDO"][0] if "AUDO" in chunks else form_len + 8)

        for idx in range(count):
            start = png_offsets[idx]
            end = png_offsets[idx + 1]
            f.seek(start)
            data = f.read(end - start)
            with open(f"{ASSET_DIR}/textures/texture_{idx}.png", "wb") as out:
                out.write(data)
        print(f"[Asset Dump] Exported {count} texture atlases.")

    # 2. Dump TPAG
    tpag_dict = {}
    if "TPAG" in chunks:
        pos, size = chunks["TPAG"]
        f.seek(pos)
        count = struct.unpack("<I", f.read(4))[0]
        ptrs = [struct.unpack("<I", f.read(4))[0] for _ in range(count)]
        for idx in range(count):
            f.seek(ptrs[idx])
            x, y, w, h, rx, ry, bw, bh, sw, sh, tex_id = struct.unpack("<HHHHhHhhhhh", f.read(22))
            tpag_dict[idx] = {
                "x": x, "y": y, "w": w, "h": h,
                "rx": rx, "ry": ry, "bw": bw, "bh": bh,
                "sw": sw, "sh": sh, "tex_id": tex_id
            }
        with open(f"{ASSET_DIR}/json/tpag.json", "w") as out:
            json.dump(tpag_dict, out, indent=2)
        print(f"[Asset Dump] Exported {count} TPAG items.")

    # 3. Dump SPRT
    sprites_dict = {}
    if "SPRT" in chunks:
        pos, size = chunks["SPRT"]
        f.seek(pos)
        count = struct.unpack("<I", f.read(4))[0]
        ptrs = [struct.unpack("<I", f.read(4))[0] for _ in range(count)]
        for idx in range(count):
            f.seek(ptrs[idx])
            name_ptr = struct.unpack("<I", f.read(4))[0]
            w, h, bl, br, bb, bt, tr, sm, pr, bm, smask, ox, oy, tcount = struct.unpack("<IIiiiiIIIIiiii", f.read(56))
            
            tpag_indices = []
            for _ in range(tcount):
                tpag_indices.append(struct.unpack("<I", f.read(4))[0])

            f.seek(name_ptr)
            s_bytes = bytearray()
            while True:
                b = f.read(1)
                if not b or b == b"\x00": break
                s_bytes.extend(b)
            sname = s_bytes.decode("latin1", errors="ignore")

            sprites_dict[idx] = {
                "name": sname,
                "width": w,
                "height": h,
                "origin_x": ox,
                "origin_y": oy,
                "tpag_indices": tpag_indices
            }
        with open(f"{ASSET_DIR}/json/sprites.json", "w") as out:
            json.dump(sprites_dict, out, indent=2)
        print(f"[Asset Dump] Exported {count} sprites metadata.")

    # 4. Dump AUDO
    if "AUDO" in chunks:
        pos, size = chunks["AUDO"]
        f.seek(pos)
        count = struct.unpack("<I", f.read(4))[0]
        ptrs = [struct.unpack("<I", f.read(4))[0] for _ in range(count)]
        for idx in range(count):
            f.seek(ptrs[idx])
            slen = struct.unpack("<I", f.read(4))[0]
            data = f.read(slen)
            with open(f"{ASSET_DIR}/audio/sound_{idx}.wav", "wb") as out:
                out.write(data)
        print(f"[Asset Dump] Exported {count} audio files.")

print("[Asset Dump] Completed successfully!")
