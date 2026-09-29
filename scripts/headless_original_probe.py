#!/usr/bin/env python3
"""Diagnose the original APK on a CI emulator without screenshots.

This script runs only inside the disposable CI emulator. Never run it on a
personal device: am start changes foreground and logcat -c clears buffers.
A successful am start -W does NOT prove that the process survived. Likewise,
a blank pidof after a failed/timeout adb call does NOT prove it died.
"""
import argparse
import json
import re
import subprocess
import sys
import time
from pathlib import Path


def call(*cmd, timeout=12, output_limit=8000):
    try:
        p = subprocess.run(cmd, text=True, capture_output=True, timeout=timeout)
        return {"rc": p.returncode, "stdout": p.stdout.strip()[-output_limit:],
                "stderr": p.stderr.strip()[-4000:], "timed_out": False}
    except subprocess.TimeoutExpired as e:
        return {"rc": None, "stdout": (e.stdout or b"").decode(errors="replace")[-8000:] if isinstance(e.stdout, bytes) else (e.stdout or "")[-8000:],
                "stderr": (e.stderr or b"").decode(errors="replace")[-4000:] if isinstance(e.stderr, bytes) else (e.stderr or "")[-4000:], "timed_out": True}


def host_qemu_state():
    p = call("ps", "-eo", "stat=,comm=", timeout=5, output_limit=500000)
    if p["rc"] != 0:
        return "unknown"
    states = [x.split()[0] for x in p["stdout"].splitlines()
              if len(x.split()) >= 2 and x.split()[1].startswith("qemu-system")]
    if not states:
        return "absent"
    if any(not x.startswith("Z") for x in states):
        return "live"
    return "zombie-only"


def classify(launch, device, pid, qemu):
    if launch["timed_out"] or launch["rc"] != 0 or "Status: ok" not in launch["stdout"]:
        return "launch_unverified"
    if device["timed_out"] or device["rc"] != 0 or device["stdout"] != "device":
        return "transport_lost"  # pidof cannot establish an app death now
    if pid["timed_out"] or pid["rc"] not in (0, 1):
        return "pid_probe_inconclusive"
    if pid["rc"] == 0 and re.fullmatch(r"\d+(?:\s+\d+)*", pid["stdout"]):
        return "app_alive"
    if pid["rc"] == 1 and not pid["stdout"]:
        return "app_absent_on_live_device"  # cause requires runtime logs/exit-info
    return "pid_probe_inconclusive"


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--package", default="com.vdogames.callyscaves2")
    ap.add_argument("--activity", default=".RunnerActivity")
    ap.add_argument("--output", default="orig_probe.json")
    ap.add_argument("--log", default="orig_logcat.txt")
    ap.add_argument("--hold-seconds", type=float, default=4)
    args = ap.parse_args()
    # Clear historical boot logs BEFORE launch; the earlier capture spent its
    # entire 25s timeout on boot backlog and ended minutes before app launch.
    cleared = call("adb", "logcat", "-b", "main", "-b", "system",
                   "-b", "crash", "-b", "events", "-c", timeout=10)
    report = {"logcat_clear": cleared, "qemu_before": host_qemu_state()}
    if cleared["rc"] != 0:
        report["classification"] = "prelaunch_transport_unavailable"
        Path(args.output).write_text(json.dumps(report, indent=2) + "\n")
        print(json.dumps(report, indent=2), flush=True)
        return 1

    with open(args.log, "wb") as out:
        monitor = subprocess.Popen(["adb", "logcat", "-b", "main", "-b", "system",
                                    "-b", "crash", "-b", "events", "-v", "threadtime"],
                                   stdout=out, stderr=subprocess.STDOUT)
        try:
            report["launch"] = call("adb", "shell", "am", "start", "-W", "-n",
                                    args.package + "/" + args.activity, timeout=30)
            time.sleep(max(0, args.hold_seconds))
            report["qemu_after"] = host_qemu_state()
            report["device"] = call("adb", "get-state", timeout=8)
            if report["device"]["rc"] == 0 and report["device"]["stdout"] == "device":
                report["pidof"] = call("adb", "shell", "pidof", args.package, timeout=8)
                report["exit_info"] = call("adb", "shell", "dumpsys", "activity",
                                           "exit-info", args.package, timeout=12)
            else:
                report["pidof"] = {"rc": None, "stdout": "", "stderr": "skipped: transport unavailable", "timed_out": False}
        finally:
            monitor.terminate()
            try:
                monitor.wait(timeout=3)
            except subprocess.TimeoutExpired:
                monitor.kill()
                monitor.wait(timeout=3)
    logs = Path(args.log).read_text(errors="replace")
    report["log_bytes"] = Path(args.log).stat().st_size
    report["package_log_lines"] = [line[:500] for line in logs.splitlines() if args.package in line][-25:]
    report["log_first_last"] = [logs.splitlines()[0][:180], logs.splitlines()[-1][:180]] if logs.splitlines() else []
    report["classification"] = classify(report["launch"], report["device"],
                                         report["pidof"], report["qemu_after"])
    report["runtime_evidence"] = "package_lines_present" if report["package_log_lines"] else "no_package_lines_captured"
    Path(args.output).write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps(report, indent=2), flush=True)
    return 0 if report["classification"] == "app_alive" else 1


if __name__ == "__main__":
    sys.exit(main())
