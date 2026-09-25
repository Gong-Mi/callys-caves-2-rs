#!/usr/bin/env python3
import json
from pathlib import Path
from reverse_code import Reader

def main():
    data = Path('assets/game.droid').read_bytes()
    reader = Reader(data)
    lo, hi = reader.chunks['FUNC']
    count = reader.u32(lo)
    funcs = []
    for idx in range(count):
        pos = lo + 4 + idx * 12
        name = reader.string(reader.u32(pos))
        occurrences = reader.u32(pos + 4)
        funcs.append((occurrences, name))
    funcs.sort(reverse=True)
    for occ, name in funcs:
        print(f"{name:35} {occ}")

if __name__ == '__main__':
    main()
