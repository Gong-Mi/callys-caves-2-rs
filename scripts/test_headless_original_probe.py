#!/usr/bin/env python3
"""Pure classification tests; never launch adb or clear device logs."""
import unittest

from headless_original_probe import (classify, package_native_metadata,
                                     sample_liveness, summarize_samples)


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
