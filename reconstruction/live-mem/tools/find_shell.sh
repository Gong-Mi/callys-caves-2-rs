#!/data/data/com.termux/files/usr/bin/sh
# Find the live CallyShell pid + libyoyo rw-p base. Prints "<pid> <rw_base_hex>".
# Must run as root (su -c).
for d in /proc/[0-9]*; do
  p=${d#/proc/}
  [ -r "$d/maps" ] || continue
  line=$(grep -m1 'libyoyo.so' "$d/maps" 2>/dev/null) || continue
  case "$line" in
    *cally-work*) ;;
    *) continue ;;
  esac
  rwline=$(grep 'libyoyo.so' "$d/maps" | grep 'rw-p' | head -1)
  [ -n "$rwline" ] || continue
  base=$(echo "$rwline" | awk '{print $1}' | cut -d- -f1)
  echo "$p $base"
done
