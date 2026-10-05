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

## A first measurement that had to be thrown away (kept as a warning)

The first traced run reported 378 distinct bodies and **85 ids above 1353**,
which looked like the VM executing CODE ids that do not exist. It was not: the
sink itself was racy. `writeln!(fh, "{code}")` issues more than one write, and a
test binary runs its tests in parallel threads, so appends interleaved into digit
concatenations (30 + 30 -> "3030", 1234 + 8 -> "12348", 51836 + 3 -> "518363").
Every symptom fitted: values that are not CODE ids, not code starts, not
literals in any test source, and no "missing CODE body" error anywhere.

Fixed by rendering the line once and taking a process-local lock around a single
`write_all`, then re-measured:

- `draw_stream_sensitivities` + `first_chapter_playthrough` (both green):
  51,235 entries, 172 distinct bodies, **0 ids above 1353**;
- all four suites again: 88,706 entries -> **293 distinct bodies** (21.6 percent of
  1,354), **0 ids above 1353**. The withdrawn run claimed 378 for the same four
  suites, so the race had inflated it by 85 bodies of pure garbage;
- cross-tab against the census tiers (highest evidence wins, so a body that is
  both with-pending and cited counts under the citation): `cited_contract` 153,
  `object_cited_contract` 81, `cited_test` 40, `cited_src` 7,
  `env_classified` 4, `structural` 8 - 293 in total, i.e. every executed body now
  maps into the census, which is exactly where the bogus ids used to land;
- of the 62 `with`-pending CODEs, **14 ran** here: 12, 14, 160, 164, 168, 172,
  184, 196, 212, 361, 549, 557, 675, 786 (the five boss death alarms among them);
- the 8 bodies the citation census calls `structural` that actually ran are
  347, 366, 367, 804, 809, 810, 811, 813.

Lesson, worth more than the number: a measurement harness is part of the
evidence, and a harness that formats while other threads write produces
plausible-looking garbage. The 378 figure and its tier cross-tab are
**withdrawn** until re-measured with the fixed sink.

## What an execution is and is not

An execution is evidence that the body ran under a test. It is **not** a claim
that its behaviour matches the original, and it is not a substitute for the
per-site runtime argument in `env-semantics.md`. The trace is also untagged
(append-only, one id per line), so it cannot yet say *which* suite ran a body;
per-suite attribution means one trace file per suite.
