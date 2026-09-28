#!/usr/bin/env python3
"""
Test result collector and categorizer following Gong-Mi's four-bin rubric:
  - 成功 (SUCCESS): Ran and passed; behavior strictly matches expectations.
  - 跳过 (SKIPPED): Explicitly deferred / not yet implemented ("没做的就 标记好跳过").
  - 失败 (FAILED): Process failed to start / launch / compile / crash / timed out ("没启动 就算失败").
  - 错误 (ERROR): Ran, but assertions failed or state did not match expectations ("不符合预期就是错误").
"""

import concurrent.futures
import os
import re
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# Deferred / not yet implemented items tracked as SKIPPED ("没做的就 标记好跳过")
KNOWN_DEFERRED_FEATURES = [
    ("binary_ir_zero_copy", "Direct zero-copy mmap bytecode interpreter from game.droid"),
    ("pixel_perfect_collision_prec", "Pixel-perfect precise collision mask check (prec=true)"),
]

def run_cmd(cmd, cwd=ROOT, timeout=120):
    try:
        proc = subprocess.run(
            cmd,
            cwd=cwd,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            timeout=timeout
        )
        return proc.returncode, proc.stdout
    except subprocess.TimeoutExpired as e:
        out = e.stdout.decode("utf-8", errors="replace") if isinstance(e.stdout, bytes) else (e.stdout or "")
        return -1, out + f"\n[TIMED OUT after {timeout}s]"
    except Exception as e:
        return -2, f"[LAUNCH FAILED: {e}]"

def parse_cargo_test_output(output, exit_code, target_name):
    """
    Parses cargo test output lines into the 4 bins:
      - 成功: `test <name> ... ok`
      - 跳过: `test <name> ... ignored`
      - 错误: `test <name> ... FAILED` (ran but assertion failed / did not match expectation)
      - 失败: process failed to start, compile error, exit code != 0 without individual tests
    """
    results = {
        "success": [],
        "skipped": [],
        "failed": [],
        "error": [],
    }

    # If the process couldn't compile, launch, or timed out without running tests -> 失败
    if exit_code in (-1, -2) or ("error: could not compile" in output and "running" not in output):
        results["failed"].append({
            "target": target_name,
            "name": f"{target_name}::launch",
            "exit_code": exit_code,
            "detail": output[-500:] if len(output) > 500 else output
        })
        return results

    # Parse individual test lines
    # Matches: `test <test_name> ... ok`, `test <test_name> ... ignored`, `test <test_name> ... FAILED`
    pattern = re.compile(r"^test\s+([^\s]+)\s+\.\.\.\s+(ok|ignored|FAILED)", re.MULTILINE)
    matches = list(pattern.finditer(output))

    if not matches and exit_code != 0:
        results["failed"].append({
            "target": target_name,
            "name": f"{target_name}::execution",
            "exit_code": exit_code,
            "detail": output[-500:] if len(output) > 500 else output
        })
        return results

    for m in matches:
        tname, status = m.group(1), m.group(2)
        full_name = f"{target_name}::{tname}"
        if status == "ok":
            results["success"].append(full_name)
        elif status == "ignored":
            results["skipped"].append((full_name, "Marked #[ignore] in source"))
        elif status == "FAILED":
            # Extract failure detail from failures section
            failure_detail = extract_failure_detail(output, tname)
            results["error"].append({
                "target": target_name,
                "name": full_name,
                "exit_code": exit_code,
                "detail": failure_detail
            })

    # If compilation or run had non-zero exit code but some tests ran, check if unaccounted
    if exit_code != 0 and not results["error"] and not results["failed"]:
        results["failed"].append({
            "target": target_name,
            "name": f"{target_name}::exit_code_{exit_code}",
            "exit_code": exit_code,
            "detail": output[-300:]
        })

    return results

def extract_failure_detail(output, tname):
    # Search for `---- <tname> stdout ----` block
    marker = f"---- {tname} stdout ----"
    if marker in output:
        part = output.split(marker, 1)[1]
        end_marker = "failures:"
        if end_marker in part:
            return part.split(end_marker, 1)[0].strip()
        return part[:600].strip()
    return "Assertion failed or output did not match expectations."

def parse_python_unittest_output(output, exit_code, script_name):
    results = {
        "success": [],
        "skipped": [],
        "failed": [],
        "error": [],
    }
    if exit_code in (-1, -2):
        results["failed"].append({
            "target": script_name,
            "name": f"{script_name}::launch",
            "exit_code": exit_code,
            "detail": output
        })
        return results

    # Look for unittest summary: `Ran X tests in Ys` followed by `OK` or `FAILED (failures=A, errors=B, skipped=C)`
    ran_match = re.search(r"Ran (\d+) tests? in", output)
    if not ran_match and exit_code != 0:
        results["failed"].append({
            "target": script_name,
            "name": f"{script_name}::crash",
            "exit_code": exit_code,
            "detail": output[-400:]
        })
        return results

    total_ran = int(ran_match.group(1)) if ran_match else 0
    if exit_code == 0:
        for i in range(total_ran):
            results["success"].append(f"{script_name}::test_{i+1}")
    else:
        # FAILED or ERROR
        results["error"].append({
            "target": script_name,
            "name": f"{script_name}::suite",
            "exit_code": exit_code,
            "detail": output[-600:]
        })
    return results

def collect_all(quick=False):
    summary = {
        "success": [],
        "skipped": [],
        "failed": [],
        "error": [],
    }

    # 1. Register known deferred items as "跳过" ("没做的就 标记好跳过")
    for feat_id, desc in KNOWN_DEFERRED_FEATURES:
        summary["skipped"].append((f"deferred::{feat_id}", desc))

    # 2. Key client integration suites
    client_tests = [
        "town_entry_and_controls",
        "first_chapter_playthrough",
        "challenge_rooms_playthrough",
        "prologue_layers_consumption",
        "prologue_render_regression",
        "view_projection_consumption",
        "store_mouse_press_ir",
    ]
    if not quick:
        client_tests += [
            "save_io",
            "level2_loop",
            "warp_reachability",
            "death_release_ir",
            "coin_pickup_ir",
            "gem_pickup_ir",
            "water_hazard_and_dissolution_ir",
            "audio_gate_drain_integration",
            "bgm_loop_seam",
        ]

    # Task executor list: (task_type, name, cmd_args)
    tasks = []
    for t in client_tests:
        tasks.append(("cargo", f"callys-client::{t}", ["cargo", "test", "--offline", "-p", "callys-client", "--test", t, "--", "--nocapture"]))

    tasks.append(("cargo", "callys-asset", ["cargo", "test", "--offline", "-p", "callys-asset", "--test", "room_views", "--test", "font_chunk"]))

    core_tests = [
        "code_vm",
        "boss1_arena_loop",
        "death_restart_ir",
        "entity_flashing_ir",
        "draw_gui_subtype65_ir",
        "mp_potential_step_avoidance_ir",
        "ini_savefile_section_roundtrip_ir",
        "shop_upgrades_and_intros_ir",
        "lloyd_tutorial_all_sheets_ir",
    ]
    for t in core_tests:
        tasks.append(("cargo", f"callys-core::{t}", ["cargo", "test", "--offline", "-p", "callys-core", "--test", t]))

    py_scripts = [
        "scripts/test_reverse_code.py",
        "scripts/test_reverse_cfg.py",
        "scripts/test_reverse_startup.py",
        "scripts/test_reverse_player_combat.py",
    ]
    for s in py_scripts:
        tasks.append(("python", s, ["python3", s]))

    def run_single(task):
        kind, name, cmd = task
        if kind == "python":
            spath = os.path.join(ROOT, name)
            if not os.path.exists(spath):
                return {"failed": [{"target": name, "name": f"{name}::missing", "exit_code": -1, "detail": "Script not on disk"}]}
            code, out = run_cmd(cmd, timeout=45)
            return parse_python_unittest_output(out, code, name)
        else:
            t_timeout = 120 if ("first_chapter" in name or "challenge_rooms" in name) else 60
            code, out = run_cmd(cmd, timeout=t_timeout)
            return parse_cargo_test_output(out, code, name)

    # Run tests concurrently with 4 workers to saturate CPU without thrashing
    max_workers = 4 if not quick else 2
    with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:
        future_map = {executor.submit(run_single, t): t[1] for t in tasks}
        for future in concurrent.futures.as_completed(future_map):
            name = future_map[future]
            try:
                sub = future.result()
                merge_results(summary, sub)
            except Exception as e:
                summary["failed"].append({
                    "target": name,
                    "name": f"{name}::exception",
                    "exit_code": -1,
                    "detail": str(e)
                })

    return summary

def merge_results(total, sub):
    total["success"].extend(sub["success"])
    total["skipped"].extend(sub["skipped"])
    total["failed"].extend(sub["failed"])
    total["error"].extend(sub["error"])

def print_report(summary):
    n_succ = len(summary["success"])
    n_skip = len(summary["skipped"])
    n_fail = len(summary["failed"])
    n_err = len(summary["error"])
    total = n_succ + n_skip + n_fail + n_err

    print("=" * 64)
    print(f"Cally's Caves 2 自动化测试收集与分类账单 (总计: {total})")
    print(f"  [成功 (SUCCESS)]: {n_succ:3d} 项")
    print(f"  [跳过 (SKIPPED)]: {n_skip:3d} 项")
    print(f"  [失败 (FAILED)]:  {n_fail:3d} 项 (未启动/加载崩溃/异常退出)")
    print(f"  [错误 (ERROR)]:   {n_err:3d} 项 (已运行但不符合预期/断言失败)")
    print("=" * 64)

    if summary["error"]:
        print("\n>>> 错误 (ERROR) 详细清单 (不符合预期):")
        for e in summary["error"]:
            print(f"  - [{e['target']}] {e['name']} (exit_code: {e['exit_code']})")
            for line in e["detail"].splitlines()[:5]:
                print(f"      {line}")

    if summary["failed"]:
        print("\n>>> 失败 (FAILED) 详细清单 (未启动/加载崩溃):")
        for f in summary["failed"]:
            print(f"  - [{f['target']}] {f['name']} (exit_code: {f['exit_code']})")
            for line in f["detail"].splitlines()[:5]:
                print(f"      {line}")

    if summary["skipped"]:
        print("\n>>> 跳过 (SKIPPED) 清单 (未施工/已推迟项):")
        for name, reason in summary["skipped"][:8]:
            print(f"  - {name}: {reason}")
        if len(summary["skipped"]) > 8:
            print(f"    ... 以及其余 {len(summary['skipped']) - 8} 项")

    print("\n" + "=" * 64)

if __name__ == "__main__":
    quick = "--quick" in sys.argv
    print(f"Collecting test results (mode: {'quick' if quick else 'full'})...")
    s = collect_all(quick=quick)
    print_report(s)
    # Exit with non-zero if there are failures or errors
    if s["error"] or s["failed"]:
        sys.exit(1)
    sys.exit(0)
