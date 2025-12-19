![pacostrap logo](pacostrap.png)

# pacostrap-beta
## pacstrap for offline installation(manuel arch installation)

Stable ARCHISO Edition for `pacostrap`.

## Compiling
```bash
make --makefile build/Makefile -j$(nproc) 
```
## Usage
```ArchISO
pacostrap # For normal customized second stage
pacostrap --pass=usbmount / -P=U-M # For skipping USB mounting and doing mounting disk with installing packages.
pacostrap --pass=diskmount / -P=D-M # For skipping disk mounting and doing USB mounting with installing packages.
pacostrap --pass=diskmount,usbmount / --pass=usbmount,diskmount / -P=D,U-M / -P=U,D-M # For skipping both USB and disk mounting with doing only installing packages.
```
> Where is --stage / -S argumant?
> Answer is: Because you don't need first stage in archiso.  

## Notes for pass argumants.
- In 2nd stage ---*Skipping disk mounting*---> Disk should be mounted at /mnt and you need to make directory at /mnt/var/cache/pacman/pkg.
- *Skipping both USB and disk mounting*---> USB should make directory at /usbmnt and mount your USB to there. And disk mounting should be like up above.

## WORKFLOW
**Mounts your USB with installed packages on it at */usbmnt/* ---> Mounts your disk at */mnt* ---> Makes */mnt/var/cache/pacman/* directory ---> Copies your packages to */mnt/var/cache/pacman/* ---> Calls pacstrap to Install your packages ---> Completes offline installation.*


## My New Ideas To Add `pacostrap`
- 1st Making second stage Archinstall compatible.
- 2nd Prepare all the other documents. CHANGELOG.md, etc.
- 3rd Make you able to install packages by your own in first stage.

## Fork(s) Of pacostrap
[javav12/pacofstrap](https://github.com/javav12/pacofstrap)

## Functions That `pacostrap` Uses
- 1st command - A safe way to execute system commands for UNIX-based/Unix-like OS'ses [link](https://gitlab.com/pigames3/command)
- 2nd animatel - '.' or string animation function [link](https://gitlab.com/pigames3/animatel)
- 3rd archstrap - Archlinux's bootstrap tarball image [link](https://github.com/wick3dr0se/archstrap) 

## Contributors

<a href="https://github.com/npc-gnu/pacostrap/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=npc-gnu/pacostrap" />
</a>

## License:
Every source code of this project (All .cpp/.hpp source codes, all bash scripts, Makefiles and .md files) licensed by GNU General Public License version 3(GPLv3). [LICENSE file](https://github.com/npc-gnu/pacostrap/blob/ArchISO_Edition/LICENSE)
pacostrap.png, *logo* is licensed by V-Pi-Lv1. [Logos LICENSE file](https://github.com/npc-gnu/pacostrap/blob/ArchISO_Edition/LOGOS_LICENSE.md)

