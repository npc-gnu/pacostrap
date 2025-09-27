![pacostrap logo](pacostrap.png)

# pacostrap-beta
## pacstrap for offline installation(manuel arch installation)

Hello Arch lovers!
> 24 September 2025: Directories have been changed. Arch_ISO edition updated.

## Installation
```any linux shell
sudo bash build/setup.sh # This script will automatically detect if you are root or not, your machine have arch based distro or not and if it is not; then it will download tarball too.
```
*or*
```any linux shell
bash build/compile
# MAKE SURE YOUR DISTRO IS ARCH/ARCH BASED. And i would not recommend it. It uses g++ directly and would be slower. 
```
*or, 3rd and last option*
```any linux shell
make --makefile build/Makefile -j$(nproc) 
# MAKE SURE YOUR DISTRO IS ARCH/ARCH BASED. This can be faster than build/setup.sh. Because it just calls make, not an entire script. But this is not user-friendly if you are a beginner.
```
## Usage
### Normal
```Any GNU + Linux shell
sudo ./pacostrap --stage=1 / -S=1 # For first stage
 ./pacostrap --stage=2 / -S=2 # For second stage
sudo ./pacostrap -S=1 --pass=format / -P=F  # For first stage and skipping formatting.
sudo ./pacostrap -S=1 --pass=mount / -P=M # For first stage and skipping formatting with mounting.
 ./pacostrap -S=2 --pass=mount / -P=M # For second stage and skipping disk mount.
```
> If you asking, *Why using sudo in first stage but not in the second?*
> Answer is: You will be root in archiso(so in the second stage) but you will probably non-root in normal destkop using.
### You can check here if Arch developers add this software to ArchISO. (For normal usage, you probably won’t need this.) 
``` Any GNU + Linux shell
pacostrap # For normal customized second stage
pacostrap --pass=usbmount / -P=U-M # For skipping USB mounting and doing mounting disk with installing packages.
pacostrap --pass=diskmount / -P=D-M # For skipping disk mounting and doing USB mounting with installing packages.
pacostrap --pass=diskmount,usbmount / --pass=usbmount,diskmount / -P=D,U-M / -P=U,D-M # For skipping both USB and disk mounting with doing only installing packages.
```
> Where is --stage / -S argumant?
> Answer is: Because you don't need first stage in archiso.  

## NOTES,
#### Second Stage
- At second stage, you need to mount USB at /usbmnt . 
- And you need to enter /usbmnt/pacostrap/ and then you can run pacostrap in second stage.
#### > If you are using skip argumants,
- In 1'st stage ---*skipping format*---> USB needs to be in a FS that Linux can recognize(exFAT, ext4, BTRFS, NTFS(Maybe. Sometimes it needs extra packages.)) ----\
                \-----> USB needs to mounted at /mnt <-----------------------*skipping both format and mounting*---------------------------------------------------/
- In 2'nd stage ---*Skipping disk mounting*---> Disk should be mounted at /mnt and you need to make directory at /mnt/var/cache/pacman/pkg.

## WORKFLOW
### First Stage:
**Formatting USB as ext4 ---> Mounting USB at */mnt* ---> Makes Directory */mnt/pacostrap* ---> Copies itself to */mnt/pacostrap/* ---> Installing your selected packages to USB  ---> First stage ends.**

### Second Stage
If you are using **vanilla ArchISO**,
Firstly, you need to make directory at */usbmnt* then mount the USB at */usbmnt*.
You can do these steps by just running these following commands:
```ArchISO
mkdir /usbmnt
mount /dev/your-usb /usbmnt # You can learn your-usb by running lsblk
cd /usbmnt/pacostrap
```
Then,
**Mounts your disk at */mnt* ---> Makes */mnt/var/cache/pacman/* directory ---> Copies your packages to */mnt/var/cache/pacman/* ---> Calls pacstrap to Install your packages ---> Completes offline installation.**

Else if you are using **My OwN sUpEr DuPeR** custom ArchISO, then
**Mounts your USB with installed packages on it at */usbmnt* ---> *And same steps up above.*

## My New Ideas To Add `pacostrap`
- 1st Making second stage Archinstall compatible.
- 2nd Prepare all the other documents. CHANGELOG.md etc.
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
Every source code of this project (All .cpp/.hpp source codes, all bash scripts, Makefiles and .md files) licensed by GNU General Public License version 3(GPLv3). [LICENSE file](https://github.com/npc-gnu/pacostrap/blob/main/LICENSE)
pacostrap.png, *logo* is licensed by V-Pi-Lv1. [Logos LICENSE file](https://github.com/npc-gnu/pacostrap/blob/main/LOGOS_LICENSE.md)
