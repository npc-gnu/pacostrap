![pacostrap logo](pacostrap.png)

# pacostrap-beta/main branch
## pacstrap for offline installation(manuel arch installation)

## Installation
```Bash
sudo bash build/setup.sh # This script will automatically detect if you are root or not, your machine have arch based distro or not and if it is not; then it will download tarball too.
```
*or, 2nd  option* **using Make.**
```make --makefile setup/Makefile -j$(nproc) <option> # -j$(nproc) is not reqired but i recommend it. It compiles faster.``` 
|Option             |Description                                                                                          |
|-------------------|-----------------------------------------------------------------------------------------------------|  
|`fast`             |For optimized code. A bit faster binary.                                                             |
|`faster`           |For more optimized code. However, it can be a little tracky because of more optimization.            |
|`fastest`          |For most optimized code. This is most dangerous and fastest working code.                            |
|`smaller`          |For smaller binary.                                                                                  |
|`clang`            |For normal compiling with clang++ instead of g++. I would recommend g++ ones bcz well... I love GNU. |
|`cfast`            |Normal fast but with clang++.                                                                        |
|`cfaster`          |Normal faster but with clang++.                                                                      |
|`cfastest`         |Normal fastest but with clang++.                                                                     |
|`csmaller`         |Normal smaller but with clang++.                                                                     |
> **MAKE SURE YOUR DISTRO IS ARCH/ARCH BASED. This can be faster than build/setup.sh. Because it just calls make, not an entire script. But this is not user-friendly if you are a beginner."**

## Usage
### Normal
```[sudo] ./pacostrap <parameter>```
|Option                       |Description                                                                    |
|-----------------------------|-------------------------------------------------------------------------------|
|`--stage=1` *or* `-S=1`      |For first stage                                                                |
|`--stage=2` *or* `-S=2`      |For second stage                                                               |
|`--pass=format` *or* `-P=F`  |For skipping USB formatting, **only for first stage.**                         |
|`--pass=mount` *or* `-P=M`   |For skipping USB formatting and mounting; and again, **only for first stage.** |
|`--pass=mount` *or* `-P=M`   |For skipping disk mount, **only for second stage.**                            |

> If you are asking, *Why using sudo in first stage but not in the second?*
> Answer is: You will be root in archiso(so in the second stage) but you will probably non-root in normal destkop using.
### You can check here if Arch developers add this software to ArchISO. (For normal usage, you probably won’t need this.) 
Bash
pacostrap # For normal customized second stage
pacostrap --pass=usbmount / -P=U-M # For skipping USB mounting and doing mounting disk with installing packages.
pacostrap --pass=diskmount / -P=D-M # For skipping disk mounting and doing USB mounting with installing packages.
pacostrap --pass=diskmount,usbmount / --pass=usbmount,diskmount / -P=D,U-M / -P=U,D-M # For skipping both USB and disk mounting with doing only installing packages.

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
- 4th Use json to store installed packages. 

## Fork(s) Of pacostrap
[javav12/pacofstrap](https://github.com/javav12/pacofstrap)

## Functions/Librarys That `pacostrap` Uses
- 1st [nlohmann/json](https://github.com/nlohmann/json) Best C++ json library
- 2nd [`command`](https://github.com/npc-gnu/command) - A safe way to execute system commands for UNIX-based/Unix-like OS'ses
- 3rd [`animatel`](https://github.com/npc-gnu/animatel) - '.' or string animation function 
- 4th [`archstrap`](https://github.com/wick3dr0se/archstrap) - Archlinux's bootstrap tarball image 

## Contributors

<a href="https://github.com/npc-gnu/pacostrap/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=npc-gnu/pacostrap" />
</a>

## License:
Every source code of this project (All .cpp/.hpp source codes, all bash scripts, Makefiles and .md files) licensed by GNU General Public License version 3(GPLv3). [LICENSE file](https://github.com/npc-gnu/pacostrap/blob/main/LICENSE)
pacostrap.png, *logo* is licensed by V-Pi-Lv1. [Logos LICENSE file](https://github.com/npc-gnu/pacostrap/blob/main/LOGOS_LICENSE.md)
