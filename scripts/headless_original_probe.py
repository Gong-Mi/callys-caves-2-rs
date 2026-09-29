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


def package_native_metadata(text):
    """Extract only PackageManager ABI/path fields; retain nulls as None."""
    fields = ("primaryCpuAbi", "secondaryCpuAbi", "nativeLibraryDir", "codePath")
    out = {}
    for key in fields:
        match = re.search(r"\b" + re.escape(key) + r"=([^\s]+)", text)
        value = match.group(1) if match else None
        out[key] = None if value in (None, "null", "(null)") else value
    return out


def sample_liveness(package, seconds, interval=5.0, sleep=time.sleep, call_fn=None):
    """Poll device+PID repeatedly through the hold window.

    One hung `adb` call cannot tell 'the process died early' from 'the
    transport wedged now'. A series can: a PID seen alive then absent on a
    live device is an app death with a time; a series that never once
    produced a device state is a transport failure.
    """
    call_fn = call_fn or call
    samples = []
    deadline = time.time() + max(0.0, seconds)
    while True:
        state = call_fn("adb", "get-state", timeout=6)
        entry = {"state": state["stdout"] or None,
                 "state_timed_out": state["timed_out"]}
        if state["rc"] == 0 and state["stdout"] == "device":
            pid = call_fn("adb", "shell", "pidof", package, timeout=10)
            entry["pid"] = pid["stdout"] or None
            entry["pid_rc"] = pid["rc"]
            entry["pid_timed_out"] = pid["timed_out"]
        samples.append(entry)
        if time.time() >= deadline:
            break
        sleep(interval)
    return samples


def summarize_samples(samples):
    """Classify a liveness series without promoting transport loss to app death."""
    if not samples:
        return "no_samples"
    if any(s.get("pid") for s in samples):
        return "pid_seen_alive"
    if any(s.get("state") == "device" and s.get("pid_rc") == 1 and not s.get("pid")
           for s in samples):
        return "pid_absent_on_live_device"
    if any(s.get("state_timed_out") or s.get("pid_timed_out") for s in samples):
        return "sample_transport_stalled"
    if any(s.get("state") not in (None, "device") for s in samples):
        return "device_not_ready"
    return "no_pid_evidence"


def classify(launch, device, pid, qemu, sample_summary=None):
    if qemu in ("absent", "zombie-only"):
        return "emulator_process_gone"  # do not attribute the guest loss to the app
    if launch["timed_out"] or launch["rc"] != 0 or "Status: ok" not in launch["stdout"]:
        return "launch_unverified"
    transport_ok = (not device["timed_out"] and device["rc"] == 0
                    and device["stdout"] == "device")
    # The liveness series outranks a single final probe: a PID observed alive
    # earlier proves the process started even if adb wedges afterwards.
    if sample_summary == "pid_seen_alive":
        return "app_alive" if transport_ok else "app_alive_then_transport_lost"
    if sample_summary == "pid_absent_on_live_device" and transport_ok:
        return "app_absent_on_live_device"  # cause requires runtime logs/exit-info
    if not transport_ok:
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
    ap.add_argument("--hold-seconds", type=float, default=25)
    ap.add_argument("--sample-interval", type=float, default=5.0,
                    help="Seconds between liveness samples during the hold window")
    args = ap.parse_args()
    # Clear historical boot logs BEFORE launch; only logs produced after this
    # point can be attributed to this launch.
    cleared = call("adb", "logcat", "-b", "main", "-b", "system",
                   "-b", "crash", "-b", "events", "-c", timeout=10)
    report = {"logcat_clear": cleared, "qemu_before": host_qemu_state()}
    if cleared["rc"] != 0:
        report["classification"] = "prelaunch_transport_unavailable"
        Path(args.output).write_text(json.dumps(report, indent=2) + "\n")
        print(json.dumps(report, indent=2), flush=True)
        return 1
    report["device_abilist"] = call("adb", "shell", "getprop", "ro.product.cpu.abilist", timeout=8)
    report["installed_package"] = call("adb", "shell", "dumpsys", "package", args.package,
                                       timeout=15, output_limit=50000)
    report["installed_package_native"] = package_native_metadata(report["installed_package"]["stdout"])

    with open(args.log, "wb") as out:
        monitor = subprocess.Popen(["adb", "logcat", "-b", "main", "-b", "system",
                                    "-b", "crash", "-b", "events", "-v", "threadtime"],
                                   stdout=out, stderr=subprocess.STDOUT)
        try:
            report["launch"] = call("adb", "shell", "am", "start", "-W", "-n",
                                    args.package + "/" + args.activity, timeout=30)
            report["samples"] = sample_liveness(args.package, args.hold_seconds,
                                                interval=args.sample_interval)
            report["sample_summary"] = summarize_samples(report["samples"])
            report["qemu_after"] = host_qemu_state()
            report["device"] = call("adb", "get-state", timeout=8)
            if report["device"]["rc"] == 0 and report["device"]["stdout"] == "device":
                report["pidof"] = call("adb", "shell", "pidof", args.package, timeout=25)
                if report["pidof"]["rc"] == 1 and not report["pidof"]["stdout"]:
                    report["exit_info"] = call("adb", "shell", "dumpsys", "activity",
                                               "exit-info", args.package, timeout=12)
                else:
                    report["exit_info"] = {"rc": None, "stdout": "", "stderr": "not queried: PID is alive or PID probe inconclusive", "timed_out": False}
            else:
                report["pidof"] = {"rc": None, "stdout": "", "stderr": "skipped: transport unavailable", "timed_out": False}
                report["exit_info"] = {"rc": None, "stdout": "", "stderr": "skipped: transport unavailable", "timed_out": False}
        finally:
            monitor.terminate()
            try:
                monitor.wait(timeout=3)
            except subprocess.TimeoutExpired:
                monitor.kill()
                monitor.wait(timeout=3)
    report["qemu_final"] = host_qemu_state()
    report["device_final"] = call("adb", "get-state", timeout=8)
    logs = Path(args.log).read_text(errors="replace")
    report["log_bytes"] = Path(args.log).stat().st_size
    report["package_log_lines"] = [line[:500] for line in logs.splitlines() if args.package in line][-40:]
    report["runtime_events"] = [line[:500] for line in logs.splitlines()
                                 if re.search(r"am_proc_start|am_proc_died|am_crash|am_anr|Fatal signal|SIGSEGV|SIGABRT|FATAL EXCEPTION|ANR in", line, re.I)][-40:]
    report["yoyo_lines"] = [line[:500] for line in logs.splitlines() if re.search(r"\byoyo\s*:", line)][-30:]
    report["package_pid_candidates"] = sorted({
        match.group(1) for line in logs.splitlines() if args.package in line
        for match in [re.match(r"^\d{2}-\d{2} \d\d:\d\d:\d\d\.\d+\s+(\d+)\s+\d+\s", line)]
        if match
    })
    report["log_first_last"] = [logs.splitlines()[0][:180], logs.splitlines()[-1][:180]] if logs.splitlines() else []
    report["classification"] = classify(report["launch"], report["device_final"],
                                         report["pidof"], report["qemu_final"],
                                         report.get("sample_summary"))
    report["runtime_evidence"] = "package_lines_present" if report["package_log_lines"] else "no_package_lines_captured"
    Path(args.output).write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps(report, indent=2), flush=True)
    return 0 if report["classification"] == "app_alive" else 1


if __name__ == "__main__":
    sys.exit(main())
