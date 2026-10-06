#!/usr/bin/env python3
"""Verify the ms_ID2InstanceE decode claims from live-findings-v2.md sec.4.

Claims under test (each prints PASS/FAIL with numbers):
  C1: header = {table, cap-1=511, count}
  C2: entries are 8 bytes; populated entry i holds node(s) whose id (+0x08)
      satisfies id & 511 == i  (direct-mapped, chains via +0x10)
  C3: walking +0x10 from each entry reaches a GLOBAL record list that is a
      superset of the 180 live entries (all-time allocated records)
  C4: node+0x0c points to a record whose first word is a vtable inside the
      libyoyo rw segment and whose +0x24..+0x2c words are {0x2b3(691), 1, 691}
  C5: Run_Room+0x94 <= live count (room-local subset; difference = instances
      alive but not in the current room's list, e.g. persistent globals)

Usage: verify_id2inst.py <pid> <rw_base_hex>
"""
import os, struct, sys

pid = int(sys.argv[1])
RW = int(sys.argv[2], 16)
OFF = 0x3F2000
def live(va): return RW + (va - OFF)
def rd(a, n):
    f = open(f"/proc/{pid}/mem", "rb", buffering=0)
    os.lseek(f.fileno(), a, os.SEEK_SET)
    b = os.read(f.fileno(), n)
    f.close()
    if len(b) < n: raise RuntimeError(f"short read @{a:#x}")
    return b
def u32(a): return struct.unpack("<I", rd(a, 4))[0]

results = []
def check(name, ok, detail=""):
    results.append(ok)
    print(f"{'PASS' if ok else 'FAIL'}  {name}  {detail}")

hdr = u32(live(0x536F28)); capm1 = u32(live(0x536F28)+4); count = u32(live(0x536F28)+8)
check("C1 header shape", capm1 == 511, f"table={hdr:#x} cap-1={capm1} count={count}")

# read 512 x 8-byte entries
raw = rd(hdr, 512*8)
entries = [struct.unpack_from("<II", raw, i*8) for i in range(512)]
pop = [(i, e) for i, e in enumerate(entries) if e[0] not in (0, 0xFFFFFFFF)]
dup_ok = all(a == b for _, (a, b) in pop)
check("C2a entries 8B with twin words", dup_ok, f"populated={len(pop)}/512")

# C2b: id at node+0x08, id & 511 == entry index
bad = []
nodes_by_entry = {}
for i, (a, b) in pop:
    try:
        nid = u32(a + 0x08)
    except Exception as ex:
        bad.append((i, "unreadable")); continue
    nodes_by_entry[i] = a
    if (nid & 511) != i:
        bad.append((i, f"id={nid} id&511={nid & 511}"))
check("C2b id&511 == entry index", not bad, f"violations={bad[:5]} n={len(bad)}")

# C3: chain-walk via +0x10 from each populated entry; collect unique nodes
seen = set(); total_visits = 0; chain_lens = []
for i, a in nodes_by_entry.items():
    n = a; ln = 0
    while n not in seen and 0xb0000000 <= n <= 0xf0000000 and ln < 64:
        try:
            nxt = u32(n + 0x10)
        except Exception:
            break
        seen.add(n); total_visits += 1; ln += 1
        if nxt in (0, 0xFFFFFFFF) or nxt == n: break
        n = nxt
    chain_lens.append(ln)
check("C3 +0x10 walk is superset of live set", len(seen) >= count,
      f"walked={len(seen)} live={count} chains={len(chain_lens)} max={max(chain_lens)}")

# C4: scope record shape
scope_bad = []
vt_ok = 0
for a in list(nodes_by_entry.values()):
    try:
        s = u32(a + 0x0c)
        vt = u32(s)
        if not (RW - 0x10000 <= vt <= RW + 0x200000):
            scope_bad.append((hex(a), f"vt={vt:#x} vs RW={RW:#x}")); continue
        w9 = u32(s + 0x24); w10 = u32(s + 0x28); w11 = u32(s + 0x2c)
        if not (w9 == 0x2b3 and w10 == 1 and w11 == 0x2b3):
            scope_bad.append((hex(a), f"words24..2c={w9:#x},{w10:#x},{w11:#x}")); continue
        vt_ok += 1
    except Exception as ex:
        scope_bad.append((hex(a), str(ex)))
check("C4 scope record shape", not scope_bad, f"sampled_ok={vt_ok}/{len(nodes_by_entry)} bad={scope_bad[:3]}")

# C5: room instance count
room = u32(live(0x54298C))
room_n = u32(room + 0x94)
live = count
check("C5 room+0x94 <= live count", room_n <= live,
      f"room+0x94={room_n} live={live} outside={live - room_n}")

print(f"\n{'ALL PASS' if all(results) else 'SOME FAIL'} ({sum(results)}/{len(results)})")
