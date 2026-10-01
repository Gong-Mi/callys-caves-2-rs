#!/usr/bin/env python3
"""Bounded exact-head watcher; one final output, no repeated notifications."""
import json, pathlib, subprocess, sys, time
repo, sha = sys.argv[1:3]
assert len(sha) == 40 and all(c in '0123456789abcdef' for c in sha)
expected = {'Recover original GML', 'Reverse CODE evidence', 'Rust CI & Desktop Build'}
output = pathlib.Path(__file__).parent / ('ci-' + sha + '.json')
deadline = time.monotonic() + 1800
errors = 0
while time.monotonic() < deadline:
    try:
        result = subprocess.run(
            ['gh', 'run', 'list', '--repo', repo, '--commit', sha, '--limit', '60',
             '--json', 'databaseId,headSha,workflowName,event,status,conclusion,url,createdAt'],
            check=True, capture_output=True, text=True, timeout=60
        )
        runs = json.loads(result.stdout)
        selected = {}
        for run in sorted(runs, key=lambda r: r['databaseId'], reverse=True):
            if run['headSha'] == sha and run['event'] == 'pull_request' and run['workflowName'] in expected:
                selected.setdefault(run['workflowName'], run)
        output.write_text(json.dumps({'repo': repo, 'sha': sha, 'expected': sorted(expected), 'runs': selected}, indent=2))
        errors = 0
        if set(selected) == expected and all(r['status'] == 'completed' for r in selected.values()):
            ok = all(r['conclusion'] == 'success' for r in selected.values())
            print(json.dumps({
                'result': 'SUCCESS' if ok else 'FAILED',
                'repo': repo,
                'sha': sha,
                'runs': selected,
                'continuation': 'Read exact-head logs and artifact, verify live tree, then update PR33 and Issue34 with actual results. Do not duplicate completion notification.'
            }, ensure_ascii=False), flush=True)
            sys.exit(0 if ok else 1)
    except (subprocess.SubprocessError, ValueError, OSError) as exc:
        errors += 1
        if errors >= 5:
            print('WATCHER ERROR: ' + str(exc), flush=True)
            sys.exit(2)
    time.sleep(15)
print('WATCHER TIMEOUT: ' + sha, flush=True)
sys.exit(2)
