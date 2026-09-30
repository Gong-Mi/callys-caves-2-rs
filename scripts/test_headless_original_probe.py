#!/usr/bin/env python3
"""Pure classification tests; never launch adb or clear device logs."""
import unittest

from headless_original_probe import (OOM_PATTERNS, classify, guest_diagnostics,
                                     guest_mem_available, host_diagnostics,
                                     package_native_metadata,
                                     pid_status_summary, sample_liveness,
                                     summarize_samples)


def result(rc=0, stdout="", timed_out=False):
    return {"rc": rc, "stdout": stdout, "stderr": "", "timed_out": timed_out}


class ClassificationTest(unittest.TestCase):
    def test_package_native_metadata_extracts_abi_and_paths(self):
        data = package_native_metadata("Package [com.vdogames.callyscaves2]\n primaryCpuAbi=x86 secondaryCpuAbi=null\n nativeLibraryDir=/data/app/pkg/lib/x86 codePath=/data/app/pkg/base.apk\n")
        self.assertEqual(data["primaryCpuAbi"], "x86")
        self.assertIsNone(data["secondaryCpuAbi"])
        self.assertEqual(data["nativeLibraryDir"], "/data/app/pkg/lib/x86")
        self.assertEqual(data["codePath"], "/data/app/pkg/base.apk")

    def test_package_native_metadata_missing_fields_are_none(self):
        self.assertEqual(package_native_metadata("no ABI data"), {
            "primaryCpuAbi": None, "secondaryCpuAbi": None,
            "nativeLibraryDir": None, "codePath": None,
        })

    def setUp(self):
        self.launch = result(stdout="Starting: Intent\nStatus: ok\nComplete")
        self.online = result(stdout="device")

    def test_qemu_zombie_is_emulator_loss_not_app_death(self):
        self.assertEqual(classify(self.launch, result(rc=1, stdout="offline"),
                                  result(rc=None), "zombie-only"), "emulator_process_gone")

    def test_offline_adb_with_live_qemu_is_transport_loss(self):
        self.assertEqual(classify(self.launch, result(rc=1, stdout="offline"),
                                  result(rc=None), "live"), "transport_lost")

    def test_failed_pidof_is_not_app_death(self):
        self.assertEqual(classify(self.launch, self.online, result(rc=255), "live"),
                         "pid_probe_inconclusive")

    def test_timed_out_pidof_is_not_app_death(self):
        self.assertEqual(classify(self.launch, self.online,
                                  result(rc=None, timed_out=True), "live"),
                         "pid_probe_inconclusive")

    def test_pidof_absent_only_on_live_device(self):
        self.assertEqual(classify(self.launch, self.online, result(rc=1), "live"),
                         "app_absent_on_live_device")

    def test_live_pid(self):
        self.assertEqual(classify(self.launch, self.online,
                                  result(stdout="1234"), "live"), "app_alive")

    def test_am_start_without_status_is_not_launch_proof(self):
        self.assertEqual(classify(result(stdout="Starting: Intent"), self.online,
                                  result(stdout="1234"), "live"), "launch_unverified")

    def test_sample_series_that_saw_a_pid_outranks_a_hung_final_probe(self):
        # The exact 88b2313 shape: live device throughout, app PID observed
        # early, final pidof wedged. That is not evidence of app death.
        series = [{"state": "device", "pid": "11276", "pid_rc": 0},
                  {"state": "device", "pid": None, "pid_rc": None, "pid_timed_out": True}]
        self.assertEqual(summarize_samples(series), "pid_seen_alive")
        self.assertEqual(classify(self.launch, self.online,
                                  result(rc=None, timed_out=True), "live",
                                  summarize_samples(series)), "app_alive")

    def test_alive_pid_then_offline_is_transport_loss_not_app_death(self):
        series = [{"state": "device", "pid": "11276", "pid_rc": 0},
                  {"state": None, "state_timed_out": True}]
        self.assertEqual(classify(self.launch, result(rc=1, stdout="offline"),
                                  result(rc=None), "live",
                                  summarize_samples(series)),
                         "app_alive_then_transport_lost")

    def test_series_with_absent_pid_on_live_device_is_app_absence(self):
        series = [{"state": "device", "pid": None, "pid_rc": 1}]
        self.assertEqual(summarize_samples(series), "pid_absent_on_live_device")
        self.assertEqual(classify(self.launch, self.online, result(rc=1), "live",
                                  summarize_samples(series)),
                         "app_absent_on_live_device")

    def test_series_of_only_timeouts_is_stalled_not_dead(self):
        series = [{"state": None, "state_timed_out": True},
                  {"state": None, "state_timed_out": True}]
        self.assertEqual(summarize_samples(series), "sample_transport_stalled")
        self.assertNotEqual(classify(self.launch, self.online,
                                     result(rc=None, timed_out=True), "live",
                                     summarize_samples(series)),
                            "app_absent_on_live_device")

    def test_guest_mem_available_parses_only_real_meminfo_lines(self):
        self.assertEqual(guest_mem_available("MemTotal: 100 kB\nMemAvailable: 123456 kB\n"), 123456)
        self.assertIsNone(guest_mem_available("cat: /proc/meminfo: Permission denied"))

    def test_pid_status_summary_reads_rss_size_threads(self):
        text = "Name:\tlibyoyo\nVmSize:\t 204800 kB\nVmRSS:\t 153600 kB\nThreads:\t11\n"
        self.assertEqual(pid_status_summary(text),
                         {"VmSize": 204800, "VmRSS": 153600, "Threads": 11})
        self.assertEqual(pid_status_summary("permission denied"), {})

    def test_kernel_hit_patterns_are_specific_enough(self):
        for line in ("Out of memory: Kill process 4321 (libyoyo)",
                     "lowmemorykiller: Killing 'com.vdogames.callyscaves2'",
                     "kernel BUG: unable to handle kernel NULL pointer dereference",
                     "watchdog: BUG: soft lockup - CPU#0 stuck",
                     "Kernel panic - not syncing: Attempted to kill init",
                     "INFO: task kworker blocked for more than 120 seconds, hung task"):
            self.assertTrue(OOM_PATTERNS.search(line), line)
        # Regression: the FIRST diagnostics run (36642821596) reported a kernel
        # hit that was only adb root restarting adbd — a bare 'killed process'
        # phrase inside a normal cgroup cleanup line. It must never count.
        benign = ("[  268.344224] libprocessgroup: Successfully killed process cgroup uid 0 pid 395 in 0ms",
                  "yoyo    : Attempting to set gamepadcount to 1",
                  "lowmemorykiller: sync_file_range completed")
        for line in benign[:1]:
            self.assertIsNone(OOM_PATTERNS.search(line), line)

    def test_host_diagnostics_collects_runner_memory_dmesg_and_crash_dbs(self):
        import tempfile, os
        with tempfile.TemporaryDirectory() as td:
            with open(os.path.join(td, "emu-crash-37.1.11.db"), "wb") as fh:
                fh.write(b"x" * 17)

            def fake_call(*cmd, timeout=None, output_limit=None):
                joined = " ".join(cmd)
                if cmd[:1] == ("free",):
                    return {"rc": 0, "stdout": "              total        used        free\nMem:          15872        9000        6872",
                            "stderr": "", "timed_out": False}
                return {"rc": 0, "stdout": "normal\nOut of memory: killed process 3002 (qemu-system-x86)\nnormal",
                        "stderr": "", "timed_out": False}

            report = host_diagnostics(call_fn=fake_call, crash_dir=td)
        self.assertIn("Mem:", report["free_m"])
        self.assertEqual(report["host_dmesg_hits"], ["Out of memory: killed process 3002 (qemu-system-x86)"])
        self.assertEqual(report["emulator_crash_dbs"], ["emu-crash-37.1.11.db:17"])

    def test_guest_diagnostics_reports_root_failure_and_filters_kernel_lines(self):
        def fake_call(*cmd, timeout=None, output_limit=None):
            if cmd[:2] == ("adb", "root"):
                return {"rc": 1, "stdout": "", "stderr": "adbd cannot run as root in production builds", "timed_out": False}
            if "/proc/meminfo" in " ".join(cmd):
                return {"rc": 0, "stdout": "MemAvailable: 900000 kB", "stderr": "", "timed_out": False}
            return {"rc": 0, "stdout": "normal line\nOut of memory: Kill process 9 (x)\nnormal line",
                    "stderr": "", "timed_out": False}

        report = guest_diagnostics(call_fn=fake_call)
        self.assertEqual(report["root"]["rc"], 1)
        self.assertEqual(report["mem_available_kb"], 900000)
        self.assertEqual(report["kernel_hits"], ["Out of memory: Kill process 9 (x)"])
        self.assertFalse(report["dmesg_timed_out"])

    def test_sampled_diagnostics_attach_mem_and_proc_numbers(self):
        def fake_call(*cmd, timeout=None, output_limit=None):
            joined = " ".join(cmd)
            if cmd[:2] == ("adb", "get-state"):
                return {"rc": 0, "stdout": "device", "stderr": "", "timed_out": False}
            if "pidof" in joined:
                return {"rc": 0, "stdout": "10878", "stderr": "", "timed_out": False}
            if "/proc/meminfo" in joined:
                return {"rc": 0, "stdout": "MemAvailable: 555000 kB", "stderr": "", "timed_out": False}
            return {"rc": 0, "stdout": "VmRSS:\t 112000 kB\nThreads:\t9", "stderr": "", "timed_out": False}

        series = sample_liveness("com.example", seconds=0, sleep=lambda _: None,
                                 call_fn=fake_call, diagnostics=True)
        self.assertEqual(series[0]["mem_available_kb"], 555000)
        self.assertEqual(series[0]["proc"], {"VmRSS": 112000, "Threads": 9})

    def test_sample_liveness_stops_at_the_deadline_and_records_pids(self):
        calls = []

        def fake_call(*cmd, timeout=None, output_limit=None):
            calls.append(cmd)
            if cmd[:2] == ("adb", "get-state"):
                return {"rc": 0, "stdout": "device", "stderr": "", "timed_out": False}
            return {"rc": 0, "stdout": "4321", "stderr": "", "timed_out": False}

        series = sample_liveness("com.example", seconds=0, sleep=lambda _: None,
                                 call_fn=fake_call)
        self.assertEqual(len(series), 1)
        self.assertEqual(series[0]["pid"], "4321")
        self.assertEqual(summarize_samples(series), "pid_seen_alive")
        self.assertTrue(any(c[:2] == ("adb", "shell") for c in calls))


if __name__ == "__main__":
    unittest.main()
