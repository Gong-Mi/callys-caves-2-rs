#!/usr/bin/env python3
"""Serial, hash-bound acceptance of the recovered spine lifetime batch.

Default outputs auto-clean; --out preserves a fresh exclusively owned receipt.
Original executable code is never run: only static reads and reconstructed C.
"""
from pathlib import Path
import argparse
import hashlib
import json
import os
import shutil
import subprocess
import sys
import tempfile

ROOT=Path(__file__).resolve().parents[1]
C=ROOT.parent
REPO=C.parents[2]
SCRIPTS=[ROOT/'tools/test_json.py',ROOT/'tools/test_atlas.py',ROOT/'tools/test_chain.py',
         ROOT/'tools/test_gate_contracts.py',C/'cskeleton_lifetime/tools/run_tests.py',
         C/'csprite_resources/tools/test_chain.py',C/'csprite_loadfromchunk/tools/run_tests.py',
         REPO/'scripts/verify_reverse_v1.py']


def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def accept(out):
    paths=set()
    for sub in ('spine_lifetime','cskeleton_lifetime','csprite_resources','csprite_clear','csprite_loadfromchunk'):
        paths.update(p for p in (C/sub).rglob('*') if p.is_file() and p.suffix in ('.c','.h','.py'))
    paths.update(SCRIPTS)
    before={str(p.relative_to(REPO)):sha(p) for p in sorted(paths)}
    p=subprocess.run(['git','rev-parse','HEAD'],cwd=REPO,capture_output=True,text=True,check=True)
    receipt={'scope':'original static bytes + reconstructed C with synthetic dependencies',
             'original_executed':False,'source_head':p.stdout.strip(),'inputs':before,'results':[]}
    env=dict(os.environ,TMPDIR=str(out),LLVM_PROFILE_FILE='/dev/null',PYTHONDONTWRITEBYTECODE='1')
    for i,script in enumerate(SCRIPTS):
        log=out/f'{i+1:02d}-{script.parent.parent.name}-{script.name}.log'
        cmd=[sys.executable,'-B',str(script)]
        try:
            p=subprocess.run(cmd,cwd=REPO,env=env,capture_output=True,text=True,timeout=240)
            stdout=p.stdout+p.stderr;rc=p.returncode
        except subprocess.TimeoutExpired as e:
            def text(x):return x.decode(errors='replace') if isinstance(x,bytes) else (x or '')
            stdout=text(e.stdout)+text(e.stderr)+'\nTIMEOUT: acceptance incomplete\n';rc=124
        log.write_text(stdout)
        receipt['results'].append({'script':str(script.relative_to(REPO)),'command':cmd,
                                   'cwd':str(REPO),'exit_code':rc,'log':str(log),'log_sha256':sha(log)})
        print(('PASS' if rc==0 else 'FAIL'),script.relative_to(REPO),'rc='+str(rc),flush=True)
        print('\n'.join(stdout.splitlines()[-5:]),flush=True)
    after={str(p.relative_to(REPO)):sha(p) for p in sorted(paths)}
    receipt['inputs_unchanged']=before==after
    receipt['planned_scripts']=len(SCRIPTS)
    receipt['completed_scripts']=len(receipt['results'])
    receipt['status']='PASS' if (before==after and len(receipt['results'])==len(SCRIPTS)
        and all(r['exit_code']==0 for r in receipt['results'])) else 'FAIL'
    (out/'receipt.json').write_text(json.dumps(receipt,ensure_ascii=False,indent=2)+'\n')
    print('RECEIPT',out/'receipt.json',receipt['status'],flush=True)
    return 0 if receipt['status']=='PASS' else 1


def main():
    if not __debug__:
        raise SystemExit('refuse optimized Python: assertions are required')
    ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path);args=ap.parse_args()
    if not shutil.which('qemu-arm'):
        raise SystemExit('qemu-arm missing: mandatory ARM32 lane cannot be skipped')
    if args.out is not None:
        out=args.out.expanduser().absolute();out.mkdir(parents=True,exist_ok=False)
        return accept(out)
    with tempfile.TemporaryDirectory(prefix='cally-spine-accept-') as tmp:
        return accept(Path(tmp))


if __name__=='__main__':raise SystemExit(main())
