#!/usr/bin/env python3
"""Independent SPRT reader for assets/game.droid (GMS1.4 / bytecode 16).

Reads the FORM chunk table, locates SPRT, follows the u32 record pointer table
(178 entries, absolute file offsets) and decodes each sprite record field by
field per reconstruction/contracts/asset-record-layouts.md:

    +0   name_ptr -> STRG payload (C string; u32 length word sits at name_ptr-4)
    +4   w u32,  +8 h u32
    +12  bbox left/right/bottom/top   4 x i32
    +28  transparent, smooth, preload, bboxmode, sepmasks   5 x u32
    +48  origin_x i32, +52 origin_y i32
    +56  tpag_count u32, then tpag_count x u32 TPAG pointers
    +60+4*tpag_count  mask_count u32, then mask_count x ceil(w/8)*h bytes
         (row-major, MSB-first, rows padded to whole bytes, blob padded to 4)

Guards are hard: a record either consumes exactly its span (minus 0..3 bytes of
alignment pad), or it is reported by id and the run exits non-zero. No threshold
is relaxed to make a record pass.

Usage:
    $PREFIX/bin/python3 sprite_records.py            # writes sprite_records.tsv
    $PREFIX/bin/python3 sprite_records.py --data PATH --out PATH
"""
import argparse
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, "..", "..", ".."))
DEFAULT_DATA = os.path.join(REPO, "assets", "game.droid")
DEFAULT_OUT = os.path.join(HERE, "sprite_records.tsv")

EXPECTED_COUNT = 178
ANCHOR_ID = 29
ANCHOR_NAME = "spr_player"
ANCHOR_W, ANCHOR_H = 32, 34
ANCHOR_ORIGIN = (15, 16)
MAX_PAD = 3

TSV_COLUMNS = [
    "id", "offset", "name", "w", "h",
    "bbox_left", "bbox_right", "bbox_bottom", "bbox_top",
    "transparent", "smooth", "preload", "bboxmode", "sepmasks",
    "origin_x", "origin_y",
    "tpag_count", "tpag_offsets", "mask_count", "mask_stride", "mask_bytes",
    "span", "consumed", "pad",
]


def align4(n):
    return (n + 3) & ~3


def chunk_table(data):
    """Walk the FORM chunk table: tag + u32 size at 8, next at +8+align4(size)."""
    if data[:4] != b"FORM":
        raise SystemExit("not a FORM container")
    total = struct.unpack_from("<I", data, 4)[0]
    chunks = []
    off = 8
    while off + 8 <= len(data):
        tag = data[off:off + 4]
        # chunk tags are 4 ASCII alnum bytes (GEN8, SPRT, TPAG...), not isalpha-safe
        if not all(0x30 <= b <= 0x5A or 0x61 <= b <= 0x7A for b in tag):
            break
        size = struct.unpack_from("<I", data, off + 4)[0]
        chunks.append((off, tag.decode("latin1"), size))
        off = off + 8 + align4(size)
        if off >= 8 + total:
            break
    return chunks


def find_chunk(chunks, tag):
    for off, t, size in chunks:
        if t == tag:
            return off, size
    raise SystemExit("chunk %r not present" % tag)


def read_cstr(data, ptr):
    """STRG payload: NUL-terminated bytes at `ptr`; u32 char count at ptr-4."""
    end = data.find(b"\x00", ptr)
    if end < 0:
        raise ValueError("unterminated STRG payload at 0x%x" % ptr)
    return data[ptr:end].decode("latin1")


def strg_len_word(data, ptr):
    return struct.unpack_from("<I", data, ptr - 4)[0]


def parse_sprite(data, off, next_off):
    (name_ptr,) = struct.unpack_from("<I", data, off)
    w, h = struct.unpack_from("<II", data, off + 4)
    left, right, bottom, top = struct.unpack_from("<4i", data, off + 12)
    transparent, smooth, preload, bboxmode, sepmasks = struct.unpack_from("<5I", data, off + 28)
    origin_x, origin_y = struct.unpack_from("<2i", data, off + 48)
    (tpag_count,) = struct.unpack_from("<I", data, off + 56)
    tpag_offsets = list(struct.unpack_from("<%dI" % tpag_count, data, off + 60))
    mask_count_off = off + 60 + 4 * tpag_count
    (mask_count,) = struct.unpack_from("<I", data, mask_count_off)

    stride = ((w + 7) // 8) * h          # bytes per 1bpp mask: ceil(w/8) rows of h
    mask_bytes = mask_count * stride     # raw blob
    mask_padded = align4(mask_bytes)     # blob padded to 4
    consumed = 60 + 4 * tpag_count + 4 + mask_padded

    return {
        "offset": off,
        "name": read_cstr(data, name_ptr),
        "name_ptr": name_ptr,
        "w": w, "h": h,
        "bbox_left": left, "bbox_right": right, "bbox_bottom": bottom, "bbox_top": top,
        "transparent": transparent, "smooth": smooth, "preload": preload,
        "bboxmode": bboxmode, "sepmasks": sepmasks,
        "origin_x": origin_x, "origin_y": origin_y,
        "tpag_count": tpag_count,
        "tpag_offsets": tpag_offsets,
        "mask_count": mask_count,
        "mask_stride": stride,
        "mask_bytes": mask_bytes,
        "mask_padded": mask_padded,
        "mask_start": mask_count_off + 4,
        "span": next_off - off,
        "consumed": consumed,
    }


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--data", default=DEFAULT_DATA)
    ap.add_argument("--out", default=DEFAULT_OUT)
    args = ap.parse_args(argv)

    with open(args.data, "rb") as fh:
        data = fh.read()

    chunks = chunk_table(data)
    sprt_off, sprt_size = find_chunk(chunks, "SPRT")
    body = sprt_off + 8
    (count,) = struct.unpack_from("<I", data, body)
    table = [struct.unpack_from("<I", data, body + 4 + 4 * i)[0] for i in range(count)]

    records = []
    for i, off in enumerate(table):
        next_off = table[i + 1] if i + 1 < count else body + sprt_size
        records.append(parse_sprite(data, off, next_off))

    # ---- guard 1: count, monotonic table, exact span consumption (pad 0..3) ----
    g1 = []
    if count != EXPECTED_COUNT:
        g1.append("count=%d expected %d" % (count, EXPECTED_COUNT))
    if table != sorted(table):
        g1.append("record offset table is not increasing")
    if table[0] < body or table[-1] >= body + sprt_size:
        g1.append("record offset outside SPRT body")
    span_fail = []
    for r in records:
        pad = r["span"] - r["consumed"]
        if pad < 0 or pad > MAX_PAD:
            span_fail.append(r)
    if span_fail:
        g1.append("%d/%d records miss their span" % (len(span_fail), len(records)))

    # ---- guard 2: mask region length == mask_count * ceil(w/8) * h, padded to 4 ----
    g2 = []
    for r in records:
        expect_stride = ((r["w"] + 7) // 8) * r["h"]
        expect_blob = r["mask_count"] * expect_stride
        if r["mask_stride"] != expect_stride:
            g2.append(r)
        elif r["mask_padded"] != align4(expect_blob):
            g2.append(r)
        elif 60 + 4 * r["tpag_count"] + 4 + r["mask_padded"] != r["consumed"]:
            g2.append(r)
    if count == EXPECTED_COUNT and len(table) != count:
        g2.append("table length mismatch")

    # ---- guard 3: known anchor spr_player = id 29, 32x34, origin (15,16) ----
    g3 = []
    anchor = records[ANCHOR_ID] if len(records) > ANCHOR_ID else None
    if anchor is None:
        g3.append("record %d absent" % ANCHOR_ID)
    else:
        if anchor["name"] != ANCHOR_NAME:
            g3.append("name=%r expected %r" % (anchor["name"], ANCHOR_NAME))
        if (anchor["w"], anchor["h"]) != (ANCHOR_W, ANCHOR_H):
            g3.append("w,h=%d,%d expected %d,%d" % (anchor["w"], anchor["h"], ANCHOR_W, ANCHOR_H))
        if (anchor["origin_x"], anchor["origin_y"]) != ANCHOR_ORIGIN:
            g3.append("origin=%d,%d expected %d,%d"
                      % (anchor["origin_x"], anchor["origin_y"], *ANCHOR_ORIGIN))

    # ---- guard 4: every mask's set-pixel ink stays inside the record bbox ----
    # Independent of the span arithmetic: if the field order at +12 were taken
    # as (l, r, b, t) but the bytes were (l, r, t, b), a 1bpp mask's ink would
    # fall outside the box. Nothing is clipped here; the masks are decoded in
    # full (row-major, MSB-first).
    g4 = []
    for i, r in enumerate(records):
        rb = (r["w"] + 7) // 8
        stride = r["mask_stride"]
        blob = data[r["mask_start"]:r["mask_start"] + stride * r["mask_count"]]
        for k in range(r["mask_count"]):
            sub = blob[k * stride:(k + 1) * stride]
            x0, x1, y0, y1 = r["w"], -1, r["h"], -1
            for y in range(r["h"]):
                row = sub[y * rb:(y + 1) * rb]
                for x in range(r["w"]):
                    if row[x >> 3] & (0x80 >> (x & 7)):
                        if x < x0:
                            x0 = x
                        if x > x1:
                            x1 = x
                        if y < y0:
                            y0 = y
                        if y > y1:
                            y1 = y
            if x1 < 0:
                continue  # blank mask carries no ink to contain
            if not (r["bbox_left"] <= x0 and x1 <= r["bbox_right"]
                    and r["bbox_top"] <= y0 and y1 <= r["bbox_bottom"]):
                g4.append((i, r["name"], k, (x0, x1, y0, y1),
                           (r["bbox_left"], r["bbox_right"], r["bbox_top"], r["bbox_bottom"])))

    # ---- informational: STRG length word at name_ptr-4 must equal strlen ----
    strg_bad = []
    for i, r in enumerate(records):
        if strg_len_word(data, r["name_ptr"]) != len(r["name"]):
            strg_bad.append((i, r["name"], strg_len_word(data, r["name_ptr"])))

    rows = []
    for i, r in enumerate(records):
        rows.append([
            i, "0x%x" % r["offset"], r["name"], r["w"], r["h"],
            r["bbox_left"], r["bbox_right"], r["bbox_bottom"], r["bbox_top"],
            r["transparent"], r["smooth"], r["preload"], r["bboxmode"], r["sepmasks"],
            r["origin_x"], r["origin_y"],
            r["tpag_count"], ",".join("0x%x" % t for t in r["tpag_offsets"]),
            r["mask_count"], r["mask_stride"], r["mask_bytes"],
            r["span"], r["consumed"], r["span"] - r["consumed"],
        ])

    with open(args.out, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("\t".join(TSV_COLUMNS) + "\n")
        for row in rows:
            fh.write("\t".join(str(c) for c in row) + "\n")

    pads = {}
    for r in records:
        p = r["span"] - r["consumed"]
        pads[p] = pads.get(p, 0) + 1

    print("data        : %s (%d bytes)" % (args.data, len(data)))
    print("chunks      : %d (%s)" % (len(chunks), " ".join(t for _, t, _ in chunks)))
    print("SPRT        : offset 0x%x size %d body 0x%x" % (sprt_off, sprt_size, body))
    print("records     : %d" % count)
    print("first/last  : 0x%x .. 0x%x" % (table[0], table[-1]))
    print("span pad    : %s" % ", ".join("%d byte(s) x%d" % (k, v) for k, v in sorted(pads.items())))
    print("")
    print("guard 1 (178 records, each consumes its span, remainder 0..3): %s"
          % ("PASS" if not g1 else "FAIL"))
    for msg in g1:
        print("  - %s" % msg)
    for r in span_fail:
        i = records.index(r)
        print("  - record %d %s: span %d consumed %d pad %d"
              % (i, r["name"], r["span"], r["consumed"], r["span"] - r["consumed"]))
    print("guard 2 (mask region == mask_count*ceil(w/8)*h, padded to 4): %s"
          % ("PASS" if not g2 else "FAIL"))
    for item in g2:
        if isinstance(item, dict):
            i = records.index(item)
            print("  - record %d %s: w=%d h=%d mask_count=%d stride=%d"
                  % (i, item["name"], item["w"], item["h"], item["mask_count"], item["mask_stride"]))
        else:
            print("  - %s" % item)
    print("guard 3 (spr_player = id %d, %dx%d, origin %s): %s"
          % (ANCHOR_ID, ANCHOR_W, ANCHOR_H, ANCHOR_ORIGIN, "PASS" if not g3 else "FAIL"))
    for msg in g3:
        print("  - %s" % msg)
    if anchor is not None:
        print("  anchor   : id=%d %s %dx%d origin (%d,%d) bbox (%d,%d,%d,%d) tpag=%d masks=%d"
              % (ANCHOR_ID, anchor["name"], anchor["w"], anchor["h"],
                 anchor["origin_x"], anchor["origin_y"],
                 anchor["bbox_left"], anchor["bbox_right"], anchor["bbox_bottom"], anchor["bbox_top"],
                 anchor["tpag_count"], anchor["mask_count"]))
    print("guard 4 (every mask's ink inside bbox left/right/bottom/top): %s"
          % ("PASS" if not g4 else "FAIL"))
    for i, name, k, ink, box in g4:
        print("  - record %d %s mask %d: ink (x0,x1,y0,y1)=%s outside bbox=%s"
              % (i, name, k, ink, box))
    print("STRG len==strlen at name_ptr-4: %s"
          % ("PASS" if not strg_bad else "FAIL %r" % (strg_bad[:5],)))
    # cross-references (reported, not gated: they describe this asset, not the layout)
    tpag_all = [t for r in records for t in r["tpag_offsets"]]
    tpag_lo, tpag_hi = 0x38a198 + 8, 0x38a198 + 8 + 46572
    print("")
    print("flags       : transparent=%s smooth=%s preload=%s bboxmode=%s sepmasks=%s"
          % tuple(sorted({r[k] for r in records}) for k in
                  ("transparent", "smooth", "preload", "bboxmode", "sepmasks")))
    print("tpag ptrs   : %d, range 0x%x..0x%x, inside TPAG body: %s"
          % (len(tpag_all), min(tpag_all), max(tpag_all),
             all(tpag_lo <= t < tpag_hi for t in tpag_all)))
    multi = [(i, r["name"], r["mask_count"]) for i, r in enumerate(records) if r["mask_count"] != 1]
    print("mask_count!=1: %s" % (multi or "none"))
    print("w x h range : %dx%d .. %dx%d"
          % (min(r["w"] for r in records), min(r["h"] for r in records),
             max(r["w"] for r in records), max(r["h"] for r in records)))
    print("")
    print("wrote %s (%d rows)" % (args.out, len(rows)))
    ok = not (g1 or g2 or g3 or g4)
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
