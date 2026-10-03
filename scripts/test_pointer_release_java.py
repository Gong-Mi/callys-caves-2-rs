#!/usr/bin/env python3
"""Execute actual Java mapping/queue implementations, not Android mocks."""
import pathlib
import subprocess
import tempfile

root = pathlib.Path(__file__).resolve().parents[1]
source = root / 'android-build/src/com/gongmi/callyscaves2'
tests = root / 'android-build/tests'
with tempfile.TemporaryDirectory(prefix='cally-pointer-') as output:
    subprocess.run(['javac', '--release', '17', '-d', output,
        str(source / 'InputViewport.java'), str(source / 'PointerReleaseQueue.java'),
        str(tests / 'PointerReleaseQueueTest.java'),
        str(tests / 'PointerCoordinateAgreementTest.java')], check=True)
    for name in ['PointerReleaseQueueTest', 'PointerCoordinateAgreementTest']:
        subprocess.run(['java', '-cp', output, 'com.gongmi.callyscaves2.' + name], check=True)
    # The app must use the tested mapping on both physical edges, rather than
    # recreating a second independent coordinate formula.
    app = (source / 'MainActivity.java').read_text()
    for pointer in ['index', 'i']:
        assert f'InputViewport.x(ev.getX({pointer}) - bounds.left, w)' in app
        assert f'InputViewport.y(ev.getY({pointer}) - bounds.top, hh)' in app
