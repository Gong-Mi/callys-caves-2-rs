# Execution coverage: which CODE bodies the suites actually run

The semantic census (`semantic-coverage.md`) can only see citations in text, so
a body that a suite drives end to end still reads as `structural` ("nothing
names it") unless somebody wrote its id down. `code_vm::coverage` closes that
gap by recording the id of every CODE body the VM enters:

```
CALLY_CODE_TRACE=/tmp/trace.txt cargo test -p callys-client --test <suite>
python3 scripts/code_trace_report.py /tmp/trace.txt
```

The hook is off unless `CALLY_CODE_TRACE` is set (one `OnceLock::get()` per
body otherwise), and it records only after the body has been validated and is
about to run: a missing id, an unsupported schema or a malformed span is not an
execution.

## Measured (4 green client suites, this machine)

`first_chapter_playthrough` (5 tests) + `boss_kill_chains` (1) +
`draw_stream_sensitivities` (2) + `core_trunk_playthrough` (4), all green:

- 88,547 VM entries -> **378 distinct CODE bodies** (27.9% of 1,354) executed;
- hottest bodies are the per-frame events: CODE 31 (20,524 entries), 32 (13,429),
  30 (12,562), 539 (4,433), 346 (3,842);
- cross-tab against the census tiers: `cited_contract` 153,
  `object_cited_contract` 81, `cited_test` 40, `cited_src` 7,
  `env_classified` 4, **`structural` 8**, and 85 ids outside 0..1353;
- of the 62 `with`-pending CODEs, the boss death alarms 160/164/168/196/212 ran.

Two honest caveats:

1. An execution is evidence that the body ran under a test. It is **not** a
   claim that its behaviour matches the original, and it is not a substitute for
   the per-site runtime argument in `env-semantics.md`.
2. The trace is append-only and untagged, so it cannot yet say *which* suite
   executed a body, and the 85 ids above 1353 are unexplained: `execute` is only
   ever called from `ir_scene.rs` with a binding's `code_id` or a code-chain
   entry, so an out-of-range id there is either a test fixture or a real defect.
   It is being attributed per suite before any coverage number is quoted
   anywhere else - do not publish the 378 as a percentage of anything until the
   id space is clean.
