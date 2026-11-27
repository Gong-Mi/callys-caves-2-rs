#!/usr/bin/env python3
"""Verify a real ARM32 callback LR against the exact wrapper ELF symbol.

This is reconstructed-code call-frame evidence, not an original-code oracle.
The C probe checks both arguments before printing the observed return address.
"""
from pathlib import Path
import argparse
import re
from elftools.elf.elffile import ELFFile


def check(binary: Path, log: Path):
    text=log.read_text()
    match=re.fullmatch(r"LR=([0-9a-f]{8})\n?",text)
    if not match:
        raise SystemExit("CALL_FRAME: missing or malformed real callback observation")
    observed=int(match[1],16)
    with binary.open("rb") as stream:
        elf=ELFFile(stream)
        if elf['e_machine']!='EM_ARM' or elf.elfclass!=32:
            raise SystemExit("CALL_FRAME: expected ARM32 executable")
        table=elf.get_section_by_name('.symtab')
        symbols=table.get_symbol_by_name('spAttachmentLoader_disposeAttachment') if table else None
        if not symbols or len(symbols)!=1:
            raise SystemExit("CALL_FRAME: exact wrapper symbol missing/ambiguous")
        symbol=symbols[0]
        if symbol['st_info']['type']!='STT_FUNC' or symbol['st_shndx']=='SHN_UNDEF' or not int(symbol['st_size']):
            raise SystemExit("CALL_FRAME: wrapper must be a defined nonempty function")
        start=int(symbol['st_value'])&~1
        end=start+int(symbol['st_size'])
        if not start<=observed<end:
            raise SystemExit(f"CALL_FRAME: callback LR {observed:#x} outside wrapper [{start:#x},{end:#x})")
    print(f"PASS callback_lr_inside_disposeAttachment {observed:#x}")


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('binary',type=Path)
    parser.add_argument('log',type=Path)
    args=parser.parse_args()
    check(args.binary,args.log)


if __name__=='__main__':
    main()
