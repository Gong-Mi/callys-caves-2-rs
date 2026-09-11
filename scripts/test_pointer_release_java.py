#!/usr/bin/env python3
"""Run the actual platform-independent Java input queue, not an Android mock."""
import pathlib
import subprocess
import tempfile

root = pathlib.Path(__file__).resolve().parents[1]
with tempfile.TemporaryDirectory(prefix='cally-pointer-') as output:
    subprocess.run(['javac', '--release', '17', '-d', output,
        str(root / 'android-build/src/com/gongmi/callyscaves2/PointerReleaseQueue.java'),
        str(root / 'android-build/tests/PointerReleaseQueueTest.java')], check=True)
    subprocess.run(['java', '-cp', output,
        'com.gongmi.callyscaves2.PointerReleaseQueueTest'], check=True)
