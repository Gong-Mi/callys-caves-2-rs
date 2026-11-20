#!/bin/sh
# Run the five oracle arms selected below; fail if any of them fails.
#
# A green run means: for each handler, the original function (executed in
# Unicorn) and the C reconstruction agree on every case in the fixed input set,
# the input set covers the declared domain, and each decision has a mutant that
# the set can actually catch. It does NOT mean the handler is "done" - the
# receipts' scope.not_covered lists the arms that are still unwired.
set -e
cd "$(dirname "$0")"

log=$(mktemp -t 'cally-oracle.XXXXXXXX')
trap 'rm -f -- "$log"' 0
trap 'exit 129' HUP
trap 'exit 130' INT
trap 'exit 143' TERM

status=0
for harness in box_type_diff.py do_neg_diff.py do_not_diff.py object_load_diff.py var_direct_diff.py; do
    printf '== %s\n' "$harness"
    # The display filter must not decide the child's verdict (including grep's
    # successful-empty case, exit 1). Save the child's status before filtering.
    child_rc=0
    python3 "$harness" >"$log" 2>&1 || child_rc=$?
    filter_rc=0
    grep -v 'LLVM Profile' "$log" || filter_rc=$?
    if [ "$filter_rc" -gt 1 ]; then
        printf '%s: log filter exit %s\n' "$harness" "$filter_rc" >&2
        status=1
    fi
    if [ "$child_rc" -ne 0 ]; then
        printf '%s: exit %s\n' "$harness" "$child_rc" >&2
        status=1
    fi
done
exit $status
