#!/usr/bin/env python3
"""Read-only validation for Cally readable-C++ static recovery modules.

This checks the pinned ELF identity, registered function/source identities, and
an exact ARM32 word-window ledger. It needs pyelftools, but neither compiles nor
executes either image.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import sys
from collections import defaultdict
from collections.abc import Callable
from pathlib import Path

WORD_FIELDS = ["entry", "va", "word", "mnemonic", "operands"]
SCHEMA = "cally-readable-cpp/1"
# Only non-symbol boundary kinds currently allowed by this schema's C++ ledger.
NON_SYMBOL_BOUNDARIES = {
    "init_array_relative_next_slot",
    "atexit_pointer_and_next_dynsym",
}


def parse_hex(value: object, label: str) -> int:
    """Parse ledger addresses/words, which are hexadecimal with or without 0x."""
    if isinstance(value, bool):
        raise ValueError(f"{label} must be a hexadecimal value")
    if isinstance(value, int):
        return value
    text = str(value).strip().lower()
    if text.startswith("0x"):
        text = text[2:]
    if not text:
        raise ValueError(f"{label} is empty")
    try:
        return int(text, 16)
    except ValueError as exc:
        raise ValueError(f"{label} is not hexadecimal: {value!r}") from exc


def verify_word_rows(
    functions: list[dict], rows: list[dict], read_vaddr: Callable[[int, int], bytes]
) -> list[str]:
    """Check full ARM32 word coverage and compare every word to ELF bytes."""
    errors: list[str] = []
    function_by_entry: dict[int, tuple[int, dict]] = {}
    grouped: dict[int, list[int]] = defaultdict(list)
    seen: set[tuple[int, int]] = set()

    for index, function in enumerate(functions):
        if not isinstance(function, dict):
            errors.append(f"function[{index}] is not an object")
            continue
        try:
            entry = parse_hex(function["entry"], f"function[{index}].entry")
            size = function["size"]
            if isinstance(size, bool) or not isinstance(size, int):
                raise ValueError("size must be an integer")
        except (KeyError, TypeError, ValueError) as exc:
            errors.append(f"function[{index}] has invalid entry/size: {exc}")
            continue
        if function.get("isa") != "arm":
            errors.append(f"function 0x{entry:x}: unsupported ISA {function.get('isa')!r}")
            continue
        if entry % 4:
            errors.append(f"function 0x{entry:x}: ARM entry is not absolutely word-aligned")
            continue
        if size <= 0 or size % 4:
            errors.append(f"function 0x{entry:x}: ARM size must be positive and word-aligned")
            continue
        if entry in function_by_entry:
            errors.append(f"duplicate function entry 0x{entry:x}")
            continue
        function_by_entry[entry] = (size, function)

    ordered_ranges = sorted((entry, entry + size) for entry, (size, _) in function_by_entry.items())
    furthest_start = 0
    furthest_end = -1
    for start, end in ordered_ranges:
        if start < furthest_end:
            errors.append(
                f"function ranges overlap: 0x{furthest_start:x}..0x{furthest_end:x} and "
                f"0x{start:x}..0x{end:x}"
            )
        if end > furthest_end:
            furthest_start, furthest_end = start, end

    for index, row in enumerate(rows):
        row_label = row.get("line", index + 2)
        try:
            entry = parse_hex(row["entry"], f"word row {row_label}.entry")
            va = parse_hex(row["va"], f"word row {row_label}.va")
            word = parse_hex(row["word"], f"word row {row_label}.word")
        except (KeyError, TypeError, ValueError) as exc:
            errors.append(f"word row {row_label} is invalid: {exc}")
            continue
        record = function_by_entry.get(entry)
        if record is None:
            errors.append(f"word row {row_label}: unknown function entry 0x{entry:x}")
            continue
        size, _ = record
        if va < entry or va + 4 > entry + size:
            errors.append(f"word row {row_label}: 0x{va:x} outside function 0x{entry:x}")
            continue
        if (va - entry) % 4:
            errors.append(f"word row {row_label}: 0x{va:x} is not on the ARM word grid")
            continue
        if word < 0 or word > 0xFFFFFFFF:
            errors.append(f"word row {row_label}: 0x{word:x} does not fit 32 bits")
            continue
        key = (entry, va)
        if key in seen:
            errors.append(f"duplicate word address 0x{va:x} for entry 0x{entry:x}")
            continue
        seen.add(key)
        grouped[entry].append(va)
        try:
            raw = read_vaddr(va, 4)
        except (KeyError, OSError, ValueError) as exc:
            errors.append(f"word row {row_label}: cannot read ELF bytes at 0x{va:x}: {exc}")
            continue
        if len(raw) != 4:
            errors.append(f"word row {row_label}: ELF read at 0x{va:x} returned {len(raw)} bytes")
            continue
        actual = int.from_bytes(raw, "little")
        if actual != word:
            errors.append(
                f"word mismatch at 0x{va:x}: ledger=0x{word:08x} ELF=0x{actual:08x}"
            )

    for entry, (size, _) in function_by_entry.items():
        expected = list(range(entry, entry + size, 4))
        actual = sorted(grouped.get(entry, []))
        if actual != expected:
            actual_set = set(actual)
            expected_set = set(expected)
            missing = len(expected_set - actual_set)
            extra = len(actual_set - expected_set)
            errors.append(
                f"coverage mismatch at 0x{entry:x}: missing={missing} extra={extra} "
                f"rows={len(actual)} expected={len(expected)}"
            )
    return errors


def sha256_file(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def read_word_rows(path: Path) -> list[dict]:
    with path.open("r", encoding="utf-8", newline="") as stream:
        reader = csv.DictReader(stream, delimiter="\t")
        if reader.fieldnames != WORD_FIELDS:
            raise ValueError(f"{path}: expected TSV fields {WORD_FIELDS!r}")
        rows = []
        for line, row in enumerate(reader, start=2):
            if None in row:
                raise ValueError(f"{path}:{line}: too many fields")
            if any(row.get(field) is None for field in WORD_FIELDS):
                raise ValueError(f"{path}:{line}: missing field value")
            rows.append(
                {
                    "entry": parse_hex(row["entry"], f"{path}:{line} entry"),
                    "va": parse_hex(row["va"], f"{path}:{line} va"),
                    "word": parse_hex(row["word"], f"{path}:{line} word"),
                    "line": line,
                }
            )
    return rows


def is_executable_code_range(
    address: int,
    size: int,
    load_segments: list[tuple[int, int, bytes, int]],
    executable_sections: list[tuple[int, int]],
) -> bool:
    """Require both an executable PT_LOAD mapping and an executable ELF section."""
    loads = [
        flags
        for start, end, _data, flags in load_segments
        if start <= address and address + size <= end
    ]
    sections = [
        (start, end)
        for start, end in executable_sections
        if start <= address and address + size <= end
    ]
    return len(loads) == 1 and bool(loads[0] & 1) and len(sections) == 1


def load_elf(
    path: Path,
) -> tuple[
    dict,
    Callable[[int, int], bytes],
    Callable[[int, int], bool],
    list[int | None],
]:
    """Load defined function symbols and file-backed ARM ELF segment readers."""
    try:
        from elftools.common.exceptions import ELFError  # pyright: ignore[reportMissingImports]
        from elftools.elf.elffile import ELFFile  # pyright: ignore[reportMissingImports]
        from elftools.elf.sections import SymbolTableSection  # pyright: ignore[reportMissingImports]
    except ImportError as exc:
        raise ValueError("pyelftools is required to inspect the ELF") from exc

    try:
        with path.open("rb") as stream:
            elf = ELFFile(stream)
            if (
                elf.elfclass != 32
                or not elf.little_endian
                or elf.header["e_machine"] != "EM_ARM"
                or elf.header["e_type"] != "ET_DYN"
            ):
                raise ValueError("expected a little-endian ELF32 ARM image")
            symbols: dict[tuple[str, str], set[tuple[int, int]]] = defaultdict(set)
            for section in elf.iter_sections():
                if not isinstance(section, SymbolTableSection) or section.name not in (
                    ".dynsym",
                    ".symtab",
                ):
                    continue
                for symbol in section.iter_symbols():
                    section_index = symbol["st_shndx"]
                    if (
                        not symbol.name
                        or symbol["st_info"]["type"] != "STT_FUNC"
                        or section_index in (0, "SHN_UNDEF")
                    ):
                        continue
                    symbols[(section.name, symbol.name)].add(
                        (int(symbol["st_value"]), int(symbol["st_size"]))
                    )
            segments: list[tuple[int, int, bytes, int]] = []
            for segment in elf.iter_segments():
                if segment["p_type"] == "PT_LOAD" and int(segment["p_filesz"]):
                    start = int(segment["p_vaddr"])
                    data = segment.data()
                    segments.append((start, start + len(data), data, int(segment["p_flags"])))
            executable_sections: list[tuple[int, int]] = []
            for section in elf.iter_sections():
                if (
                    int(section["sh_flags"]) & 0x4
                    and section["sh_type"] != "SHT_NOBITS"
                    and int(section["sh_size"]) > 0
                ):
                    start = int(section["sh_addr"])
                    executable_sections.append((start, start + int(section["sh_size"])))
            init_array_values: list[int | None] = []
            init_array = elf.get_section_by_name(".init_array")
            if init_array is not None:
                data = init_array.data()
                for offset in range(0, len(data) - 3, 4):
                    value = int.from_bytes(data[offset : offset + 4], "little")
                    init_array_values.append(value & ~1 if value else None)
    except ELFError as exc:
        raise ValueError(f"cannot parse ELF {path}: {exc}") from exc

    def read_vaddr(address: int, size: int) -> bytes:
        matches = [
            data[address - start : address - start + size]
            for start, end, data, _flags in segments
            if start <= address and address + size <= end
        ]
        if not matches:
            raise ValueError("range is not wholly backed by a PT_LOAD segment")
        if any(match != matches[0] for match in matches[1:]):
            raise ValueError("overlapping PT_LOAD segments disagree")
        return matches[0]

    def is_executable_range(address: int, size: int) -> bool:
        return is_executable_code_range(address, size, segments, executable_sections)

    return symbols, read_vaddr, is_executable_range, init_array_values


def resolve_module_file(module: Path, cpp_root: Path, relative: object, label: str) -> Path:
    if not isinstance(relative, str) or not relative:
        raise ValueError(f"{label} path is missing")
    relative_path = Path(relative)
    if relative_path.is_absolute():
        raise ValueError(f"{label} path must be module-relative: {relative}")
    resolved = (module / relative_path).resolve()
    try:
        resolved.relative_to(cpp_root)
    except ValueError as exc:
        raise ValueError(f"{label} path escapes the C++ root: {relative}") from exc
    return resolved


def verify_module(
    module_dir: Path,
    image_path: Path,
    functions_path: Path | None = None,
    words_path: Path | None = None,
) -> dict:
    module = module_dir.resolve()
    # Shared C++ translation units and headers may live in sibling module directories.
    cpp_root = module.parent
    image = image_path.resolve()
    functions_file = (functions_path or module / "functions.json").resolve()
    words_file = (words_path or module / "original-words.tsv").resolve()
    manifest = json.loads(functions_file.read_text(encoding="utf-8"))
    if not isinstance(manifest, dict):
        raise ValueError("functions.json root must be an object")
    if manifest.get("schema") != SCHEMA:
        raise ValueError(f"unsupported module schema {manifest.get('schema')!r}; expected {SCHEMA!r}")
    functions = manifest.get("functions")
    if not isinstance(functions, list) or not functions:
        raise ValueError("functions.json must contain a nonempty functions list")

    errors: list[str] = []
    image_sha = sha256_file(image)
    expected_image_sha = str(manifest.get("image_sha256", "")).lower()
    if image_sha != expected_image_sha:
        errors.append(f"image SHA mismatch: manifest={expected_image_sha} actual={image_sha}")

    symbols, read_vaddr, is_executable_range, init_array_values = load_elf(image)
    symbol_count = 0
    source_paths: set[Path] = set()
    additional_headers_checked = 0
    primary_header_checked = False
    canonical_header_checked = False
    parsed_functions: list[dict] = []

    for index, function in enumerate(functions):
        if not isinstance(function, dict):
            errors.append(f"functions[{index}] is not an object")
            continue
        try:
            entry = parse_hex(function["entry"], f"functions[{index}].entry")
            size = function["size"]
            if isinstance(size, bool) or not isinstance(size, int):
                raise ValueError("size must be an integer")
        except (KeyError, TypeError, ValueError) as exc:
            errors.append(f"functions[{index}] has invalid entry/size: {exc}")
            continue
        parsed_functions.append(function)
        if not is_executable_range(entry, size):
            errors.append(
                f"function 0x{entry:x}: range is not in one executable PT_LOAD and "
                "one SHF_EXECINSTR section"
            )
        try:
            body = read_vaddr(entry, size)
        except (OSError, ValueError) as exc:
            errors.append(f"function 0x{entry:x}: cannot read body: {exc}")
        else:
            actual_body_sha = hashlib.sha256(body).hexdigest()
            expected_body_sha = str(function.get("body_sha256", "")).lower()
            if actual_body_sha != expected_body_sha:
                errors.append(
                    f"function 0x{entry:x}: body SHA mismatch manifest={expected_body_sha} "
                    f"actual={actual_body_sha}"
                )

        names = function.get("symbols", [])
        boundary = function.get("boundary")
        isa = function.get("isa")
        if boundary is not None and not isinstance(boundary, str):
            errors.append(f"function 0x{entry:x}: boundary must be a string")
            boundary = None
        if not isinstance(names, list):
            errors.append(f"function 0x{entry:x}: symbols must be a list")
            names = []
        valid_names = [name for name in names if isinstance(name, str) and name]
        if len(valid_names) != len(names):
            errors.append(f"function 0x{entry:x}: symbols contains an invalid name")
        if len(set(valid_names)) != len(valid_names):
            errors.append(f"function 0x{entry:x}: duplicate symbol name")

        if boundary in ("defined_dynsym", "defined_symtab"):
            if not valid_names:
                errors.append(f"function 0x{entry:x}: symbol boundary has no symbols")
            tables = (".dynsym",) if boundary == "defined_dynsym" else (".symtab",)
        elif boundary is None and valid_names:
            tables = (".dynsym", ".symtab")
        elif boundary in NON_SYMBOL_BOUNDARIES and not valid_names:
            tables = ()
        else:
            errors.append(
                f"function 0x{entry:x}: unsupported non-symbol boundary {boundary!r}"
            )
            tables = ()

        if boundary in NON_SYMBOL_BOUNDARIES and valid_names:
            errors.append(f"function 0x{entry:x}: non-symbol boundary must not list symbols")
        if boundary == "init_array_relative_next_slot":
            slots = [index for index, value in enumerate(init_array_values) if value == entry]
            if len(slots) != 1:
                errors.append(f"function 0x{entry:x}: entry is not uniquely referenced by .init_array")
            else:
                next_slot = slots[0] + 1
                if next_slot >= len(init_array_values) or init_array_values[next_slot] is None:
                    errors.append(f"function 0x{entry:x}: .init_array has no following target boundary")
                elif entry + size != init_array_values[next_slot]:
                    errors.append(
                        f"function 0x{entry:x}: end 0x{entry + size:x} does not match "
                        f"next .init_array target 0x{init_array_values[next_slot]:x}"
                    )
        if boundary == "atexit_pointer_and_next_dynsym":
            next_dynsym = sorted(
                {
                    value & ~1
                    for (table, _name), definitions in symbols.items()
                    if table == ".dynsym"
                    for value, _symbol_size in definitions
                    if (value & ~1) > entry
                }
            )
            if not next_dynsym:
                errors.append(f"function 0x{entry:x}: no following defined dynsym boundary")
            elif entry + size != next_dynsym[0]:
                errors.append(
                    f"function 0x{entry:x}: end 0x{entry + size:x} does not match "
                    f"next dynsym 0x{next_dynsym[0]:x}"
                )

        for name in dict.fromkeys(valid_names):
            if tables:
                candidates = set().union(*(symbols.get((table, name), set()) for table in tables))
                if not candidates:
                    errors.append(f"function 0x{entry:x}: symbol {name!r} not defined in {tables}")
                    continue
                symbol_count += 1
                normalized = {
                    (value & ~1, symbol_size, value & 1)
                    for value, symbol_size in candidates
                }
                if len(normalized) != 1:
                    errors.append(f"function 0x{entry:x}: symbol {name!r} has conflicting ELF definitions")
                    continue
                symbol_entry, symbol_size, thumb_bit = next(iter(normalized))
                expected_thumb = 1 if isa == "thumb" else 0
                if symbol_entry != entry or symbol_size != size or thumb_bit != expected_thumb:
                    errors.append(
                        f"function 0x{entry:x}: symbol {name!r} range/ISA mismatch "
                        f"ELF=0x{symbol_entry:x}/{symbol_size}/thumb{thumb_bit} "
                        f"manifest=0x{entry:x}/{size}/thumb{expected_thumb}"
                    )

        source_path = resolve_module_file(
            module, cpp_root, function.get("translation_source"), "translation source"
        )
        expected_source_sha = str(function.get("translation_source_sha256", "")).lower()
        if not expected_source_sha:
            errors.append(f"function 0x{entry:x}: translation source SHA is missing")
        elif not source_path.is_file():
            errors.append(f"function 0x{entry:x}: translation source is missing: {source_path}")
        else:
            source_paths.add(source_path)
            actual_source_sha = sha256_file(source_path)
            if actual_source_sha != expected_source_sha:
                errors.append(
                    f"function 0x{entry:x}: translation source SHA mismatch "
                    f"manifest={expected_source_sha} actual={actual_source_sha}"
                )

    primary_header_path = manifest.get("header_path")
    primary_header_sha = manifest.get("header_sha256")
    if primary_header_path is not None or primary_header_sha is not None:
        if primary_header_path is None or primary_header_sha is None:
            errors.append("header_sha256 and header_path must be declared together")
        else:
            header_path = resolve_module_file(
                module, cpp_root, primary_header_path, "primary header"
            )
            if not isinstance(primary_header_sha, str) or len(primary_header_sha) != 64:
                errors.append("header_sha256 must be a 64-character SHA-256 hex string")
            elif not header_path.is_file():
                errors.append(f"primary header is missing: {header_path}")
            else:
                primary_header_checked = True
                actual_sha = sha256_file(header_path)
                if actual_sha != primary_header_sha.lower():
                    errors.append(
                        f"primary header SHA mismatch {primary_header_path}: "
                        f"manifest={primary_header_sha.lower()} actual={actual_sha}"
                    )

    canonical_paths = []
    for key in ("canonical_static_api_header", "canonical_api_header"):
        if key in manifest:
            value = manifest[key]
            if not isinstance(value, str) or not value:
                errors.append(f"{key} must be a nonempty relative path")
            else:
                canonical_paths.append(value)
    canonical_sha = manifest.get("canonical_api_header_sha256")
    if len(canonical_paths) > 1 and len(set(canonical_paths)) != 1:
        errors.append("canonical API header path fields disagree")
    canonical_path = canonical_paths[0] if canonical_paths else None
    if canonical_path is not None or canonical_sha is not None:
        if canonical_path is None or canonical_sha is None:
            errors.append("canonical API header path and SHA-256 must be declared together")
        else:
            canonical_file = resolve_module_file(
                module, cpp_root, canonical_path, "canonical API header"
            )
            if not isinstance(canonical_sha, str) or len(canonical_sha) != 64:
                errors.append("canonical_api_header_sha256 must be a 64-character SHA-256 hex string")
            elif not canonical_file.is_file():
                errors.append(f"canonical API header is missing: {canonical_file}")
            else:
                canonical_header_checked = True
                actual_sha = sha256_file(canonical_file)
                if actual_sha != canonical_sha.lower():
                    errors.append(
                        f"canonical API header SHA mismatch {canonical_path}: "
                        f"manifest={canonical_sha.lower()} actual={actual_sha}"
                    )

    known_top_level_hashes = {
        "image_sha256",
        "header_sha256",
        "canonical_api_header_sha256",
        "additional_headers_sha256",
    }
    for key in manifest:
        if key.endswith("_sha256") and key not in known_top_level_hashes:
            errors.append(f"unverified top-level hash claim {key!r}")

    header_hashes = manifest.get("additional_headers_sha256", {})
    if not isinstance(header_hashes, dict):
        errors.append("additional_headers_sha256 must be an object")
        header_hashes = {}
    for relative, expected in header_hashes.items():
        header_path = resolve_module_file(module, cpp_root, relative, "additional header")
        expected_sha = str(expected).lower()
        if not header_path.is_file():
            errors.append(f"additional header is missing: {header_path}")
            continue
        additional_headers_checked += 1
        actual_sha = sha256_file(header_path)
        if not isinstance(expected, str) or len(expected_sha) != 64:
            errors.append(f"additional header SHA is invalid: {relative}")
        elif actual_sha != expected_sha:
            errors.append(
                f"additional header SHA mismatch {relative}: manifest={expected_sha} actual={actual_sha}"
            )

    word_rows = read_word_rows(words_file)
    errors.extend(verify_word_rows(parsed_functions, word_rows, read_vaddr))
    return {
        "ok": not errors,
        "scope": "pinned ELF/source/header hash and raw ARM-word-column integrity only; atexit registration provenance is not checked; mnemonic/operands are not verified; no compile, link, or execution claim",
        "module": str(module),
        "image": str(image),
        "image_sha256": image_sha,
        "functions_checked": len(parsed_functions),
        "symbols_checked": symbol_count,
        "source_files_checked": len(source_paths),
        "primary_header_checked": primary_header_checked,
        "canonical_header_checked": canonical_header_checked,
        "additional_headers_checked": additional_headers_checked,
        "word_rows_seen": len(word_rows),
        "error_count": len(errors),
        "errors": errors[:100],
        "errors_truncated": len(errors) > 100,
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--module", type=Path, required=True, help="C++ module directory")
    parser.add_argument("--image", type=Path, required=True, help="pinned ELF image (read only)")
    parser.add_argument("--functions", type=Path, help="override module/functions.json")
    parser.add_argument("--words", type=Path, help="override module/original-words.tsv")
    args = parser.parse_args()
    try:
        report = verify_module(args.module, args.image, args.functions, args.words)
    except (OSError, ValueError, json.JSONDecodeError, KeyError) as exc:
        report = {"ok": False, "kind": "input_error", "error": str(exc)}
        exit_code = 2
    else:
        exit_code = 0 if report["ok"] else 1
    print(json.dumps(report, indent=2, sort_keys=True))
    return exit_code


if __name__ == "__main__":
    sys.exit(main())
