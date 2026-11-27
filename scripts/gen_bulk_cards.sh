#!/data/data/com.termux/files/usr/bin/bash
# Generate bulk skeleton cards for every function of the binary until nothing is left.
set -u
cd "$(dirname "$0")/.." || exit 1
TSV="$HOME/.hermes/cache/scratch/allfuncs.tsv"
LOG="$HOME/.hermes/cache/scratch/bulk_cards.log"
: > "$LOG"
for i in $(seq 15 99); do
  out=$(python3 scripts/gen_func_cards.py "$TSV" --name All_$i --budget 7500 --min-size 4 2>&1 | head -1)
  echo "$i $out" >> "$LOG"
  case "$out" in
    *"no uncovered"*) echo "DONE at $i" >> "$LOG"; break ;;
  esac
done
echo "BULK_FINISHED" >> "$LOG"
