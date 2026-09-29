#!/usr/bin/env python3
"""Pure classification tests; never launch adb or clear device logs."""
import unittest

from headless_original_probe import classify


def result(rc=0, stdout="", timed_out=False):
    return {"rc": rc, "stdout": stdout, "stderr": "", "timed_out": timed_out}


class ClassificationTest(unittest.TestCase):
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


if __name__ == "__main__":
    unittest.main()
