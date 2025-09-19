#!/usr/bin/env bash
# setup.sh runner
# FIXME AC means, "FIXME, Add colors"

set -euo pipefail

# 1st root control
if [[ $EUID -ne 0 ]]; then
    echo "You have to be root" #FIXME AC
    exit 1
fi

# 2nd Is arch-based control
if grep -qi "arch" /etc/os-release; then
    echo "Arch based system(or tarball) found. Compiling directly." # FIXME AC
    make -j$(nproc) --makefile $PWD/build\&setup/scripts\&makefiles/Makefile
    echo "Now you can run pacostrap." # FIXME AC
    exit 0
fi

# 3rd If not-arch based, tarball download
mountdir="/mnt/tarballrun"
mkdir -p "$mountdir"

script_path="$PWD/build&setup/scripts/archstrap"

if [[ ! -x "$script_path" ]]; then
    echo "Error: $script_path was not found!" # FIXME AC
    exit 1
fi

"$script_path" "$mountdir"

