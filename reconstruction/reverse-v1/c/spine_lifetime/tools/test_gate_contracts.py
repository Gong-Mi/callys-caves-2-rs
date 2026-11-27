#!/usr/bin/env python3
"""Falsify mandatory-runtime and assertion-enabled acceptance contracts."""
from pathlib import Path
import contextlib
import importlib.util
import io
import os
import subprocess
import sys
from unittest.mock import patch

ROOT=Path(__file__).resolve().parent


def main():
    if not __debug__:
        raise SystemExit('refuse optimized Python: assertions are required')
    for name in ('test_json.py','test_atlas.py','test_chain.py'):
        path=ROOT/name
        spec=importlib.util.spec_from_file_location('contract_'+path.stem,path)
        m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
        with patch.object(m.shutil,'which',return_value=None),patch.object(sys,'argv',[str(path)]),contextlib.redirect_stdout(io.StringIO()) as out:
            try:
                m.main()
            except SystemExit as e:
                if not e.code or 'qemu-arm missing' not in str(e):
                    raise AssertionError(f'{name}: wrong missing-runtime refusal: {e}')
            else:
                raise AssertionError(f'{name}: missing mandatory ARM32 runtime accepted')
        if 'ALL GREEN' in out.getvalue():
            raise AssertionError(f'{name}: false GREEN before refusal')
        env=dict(os.environ,LLVM_PROFILE_FILE='/dev/null',PYTHONDONTWRITEBYTECODE='1')
        p=subprocess.run([sys.executable,'-B','-O',path],capture_output=True,text=True,env=env,timeout=20)
        if p.returncode==0 or 'refuse optimized Python' not in p.stderr:
            raise AssertionError(f'{name}: -O accepted or refused for wrong reason\n{p.stdout}{p.stderr}')
        print('PASS gate-contract',name,'missing-qemu refused; optimized Python refused')
    return 0


if __name__=='__main__':raise SystemExit(main())
