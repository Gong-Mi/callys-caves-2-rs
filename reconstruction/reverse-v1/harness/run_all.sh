#!/bin/sh
# Run every oracle arm and fail if any gate fails.
#
# A green run means: for each handler, the original function (executed in
# Unicorn) and the C reconstruction agree on every case in the fixed input set,
# the input set covers the declared domain, and each decision has a mutant that
# the set can actually catch. It does NOT mean the handler is "done" - the
# receipts' scope.not_covered lists the arms that are still unwired.
set -e
cd "$(dirname "$0")"

status=0
for harness in box_type_diff.py do_neg_diff.py do_not_diff.py object_load_diff.py; do
    printf '== %s\n' "$harness"
    if python3 "$harness" 2>&1 | grep -v 'LLVM Profile'; then :; else
        status=1
    fi
done
exit $status
