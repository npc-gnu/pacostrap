#!/usr/bin/env bash


printf 'Changed root\n'

systemd-machine-id-setup

pacman-key --init
pacman-key --populate

pacman -Syu --needed --noconfirm&&
    printf 'Updated & synced repositories\n'

printf '%s\n' 'Arch bootstrap environment for pacostrap.' \
    "Proceed with: ./pacostrap -S=1 " \
    'Welcome to Arch Linux!'


bash --login

## pacostrap's things now
cd /root/
pacman -S git --noconfirm > /dev/null
git clone https://github.com/npc-gnu/pacostrap.git pacostrap
cd pacostrap
chmod +x /root/pacostrap/setup/setup.sh
bash /root/pacostrap/setup/setup.sh
