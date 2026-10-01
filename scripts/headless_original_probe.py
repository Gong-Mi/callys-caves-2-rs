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


OOM_PATTERNS = re.compile(
    r"Out of memory|oom-kill|lowmemorykiller|page allocation failure"
    r"|BUG: |Oops|kernel panic|hung task|soft lockup|watchdog", re.I)
# Deliberately NOT matching a bare "killed process": normal cgroup/process
# cleanup prints `libprocessgroup: Successfully killed process cgroup …`, and
# treating that as an OOM hit made the first diagnostics run report a kernel
# problem that did not exist (run 36642821596).
BENIGN_KERNEL_LINES = re.compile(
    r"Perf NMI watchdog permanently disabled", re.I)
# `NMI watchdog: Perf NMI watchdog permanently disabled` is boot noise that
# appeared in the runner's dmesg both before and after the wedge (run
# 36651169057); it says nothing about the emulator's death.


def kernel_hits(lines, limit=25):
    """Kernel lines that actually indicate OOM/panic/lockup, not boot noise."""
    return [line[:300] for line in lines
            if OOM_PATTERNS.search(line) and not BENIGN_KERNEL_LINES.search(line)][-limit:]


def host_diagnostics(call_fn=None, crash_dir="/tmp/android-runner"):
    """Host-side facts around the wedge: the guest may leave no trace at all.

    emulator.log ended at boot lines in every failing run, which means the
    emulator process was removed before it could flush anything. The host
    kernel log and the runner's own memory state are then the only evidence
    for 'qemu was killed' versus 'qemu crashed'.
    """
    call_fn = call_fn or call
    report = {}
    free = call_fn("free", "-m", timeout=5, output_limit=20000)
    report["free_m"] = free["stdout"]
    dmesg = call_fn("sudo", "dmesg", "--ctime", timeout=15, output_limit=200000)
    report["host_dmesg_rc"] = dmesg["rc"]
    report["host_dmesg_timed_out"] = dmesg["timed_out"]
    hits = kernel_hits(dmesg["stdout"].splitlines(), limit=25)
    qemu_lines = [line[:300] for line in dmesg["stdout"].splitlines()
                  if "qemu" in line.lower() and line[:300] not in hits][-10:]
    report["host_dmesg_hits"] = hits + qemu_lines
    crash = Path(crash_dir)
    report["emulator_crash_dbs"] = (
        [f"{p.name}:{p.stat().st_size}" for p in sorted(crash.glob("emu-crash-*.db"))]
        if crash.is_dir() else []
    )
    return report


def guest_mem_available(text):
    match = re.search(r"MemAvailable:\s+(\d+) kB", text)
    return int(match.group(1)) if match else None


def pid_status_summary(text):
    """Cheap per-process numbers: RSS, virtual size, thread count."""
    out = {}
    for key in ("VmRSS", "VmSize", "Threads"):
        match = re.search(r"^" + key + r":\s+(\d+)", text, re.M)
        if match:
            out[key] = int(match.group(1))
    return out


def guest_diagnostics(enable_root=True, call_fn=None):
    """Guest-side kernel/memory evidence; the AVD dies without tombstones.

    A wedged guest (`adb` calls stall, qemu goes zombie-only) usually leaves
    its reason in the guest kernel log or the low-memory killer, not in the
    app's own logcat. `adb root` works on google_apis images; if it fails we
    say so instead of assuming the reads succeeded.
    """
    call_fn = call_fn or call
    report = {}
    if enable_root:
        report["root"] = call_fn("adb", "root", timeout=25)
    mem = call_fn("adb", "shell", "cat", "/proc/meminfo", timeout=12)
    report["mem_available_kb"] = guest_mem_available(mem["stdout"])
    report["meminfo_timed_out"] = mem["timed_out"]
    dmesg = call_fn("adb", "shell", "dmesg", timeout=15, output_limit=200000)
    report["dmesg_rc"] = dmesg["rc"]
    report["dmesg_timed_out"] = dmesg["timed_out"]
    report["kernel_hits"] = kernel_hits(dmesg["stdout"].splitlines(), limit=20)
    return report


def sample_liveness(package, seconds, interval=5.0, sleep=time.sleep, call_fn=None,
                    diagnostics=False):
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
            if diagnostics:
                mem = call_fn("adb", "shell", "cat", "/proc/meminfo", timeout=8)
                entry["mem_available_kb"] = guest_mem_available(mem["stdout"])
                if entry["pid"]:
                    target = entry["pid"].split()[0]
                    status = call_fn("adb", "shell", "cat",
                                     f"/proc/{target}/status", timeout=8)
                    entry["proc"] = pid_status_summary(status["stdout"])
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
    ap.add_argument("--guest-diagnostics", dest="guest_diagnostics",
                    action=argparse.BooleanOptionalAction, default=True,
                    help="adb root + guest dmesg/meminfo/RSS sampling")
    args = ap.parse_args()
    # `adb root` restarts adbd, so it must happen before the logcat monitor and
    # before any sampling; otherwise the first samples measure the restart.
    report = {"qemu_before": host_qemu_state()}
    if args.guest_diagnostics:
        report["guest_before"] = guest_diagnostics(call_fn=call)
        root_ok = report["guest_before"].get("root", {}).get("rc") == 0
        if root_ok:
            # Bounded wait: the adbd restart drops the device briefly.
            for _ in range(20):
                state = call("adb", "get-state", timeout=6)
                if state["rc"] == 0 and state["stdout"] == "device":
                    break
                time.sleep(1.5)
    # Clear historical boot logs BEFORE launch; only logs produced after this
    # point can be attributed to this launch.
    cleared = call("adb", "logcat", "-b", "main", "-b", "system",
                   "-b", "crash", "-b", "events", "-c", timeout=10)
    report["logcat_clear"] = cleared
    if cleared["rc"] != 0:
        report["classification"] = "prelaunch_transport_unavailable"
        Path(args.output).write_text(json.dumps(report, indent=2) + "\n")
        print(json.dumps(report, indent=2), flush=True)
        return 1
    report["device_abilist"] = call("adb", "shell", "getprop", "ro.product.cpu.abilist", timeout=8)
    report["installed_package"] = call("adb", "shell", "dumpsys", "package", args.package,
                                       timeout=15, output_limit=50000)
    report["installed_package_native"] = package_native_metadata(report["installed_package"]["stdout"])
    # Host-side baseline: emulator.log stops at boot lines in failing runs, so
    # the runner's own memory state and kernel log decide "qemu killed" vs
    # "qemu crashed" when the guest leaves no trace.
    report["host_before"] = host_diagnostics(call_fn=call)

    with open(args.log, "wb") as out:
        monitor = subprocess.Popen(["adb", "logcat", "-b", "main", "-b", "system",
                                    "-b", "crash", "-b", "events", "-v", "threadtime"],
                                   stdout=out, stderr=subprocess.STDOUT)
        # The guest's own kernel log is written up to the instant it dies, but
        # a post-mortem read is impossible once the device is offline. Keep a
        # second adb connection streaming `dmesg -w` for the whole window
        # (needs the adb root done above).
        guest_stream = None
        guest_stream_path = Path(args.log).with_name("guest_dmesg.txt")
        if args.guest_diagnostics:
            guest_stream = subprocess.Popen(["adb", "shell", "dmesg", "-w"],
                                            stdout=open(guest_stream_path, "wb"),
                                            stderr=subprocess.STDOUT)
        try:
            report["launch"] = call("adb", "shell", "am", "start", "-W", "-n",
                                    args.package + "/" + args.activity, timeout=30)
            report["samples"] = sample_liveness(args.package, args.hold_seconds,
                                                interval=args.sample_interval,
                                                diagnostics=args.guest_diagnostics)
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
            for proc in (monitor, guest_stream):
                if proc is None:
                    continue
                proc.terminate()
                try:
                    proc.wait(timeout=3)
                except subprocess.TimeoutExpired:
                    proc.kill()
                    proc.wait(timeout=3)
    if args.guest_diagnostics and guest_stream_path.exists():
        streamed = guest_stream_path.read_text(errors="replace").splitlines()
        report["guest_dmesg_bytes"] = guest_stream_path.stat().st_size
        report["guest_dmesg_tail"] = [line[:300] for line in streamed][-40:]
        report["guest_dmesg_hits"] = kernel_hits(streamed, limit=20)
    report["qemu_final"] = host_qemu_state()
    report["device_final"] = call("adb", "get-state", timeout=8)
    if args.guest_diagnostics:
        # Post-wedge guest evidence: the kernel log is often the only place the
        # reason survives (the app's own logcat stops at its last line).
        report["guest_after"] = guest_diagnostics(enable_root=False, call_fn=call)
    report["host_after"] = host_diagnostics(call_fn=call)
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
