![pacostrap logo](pacostrap.png)

# pacostrap-beta
## pacstrap for offline installation(manuel arch installation)

Hello Arch lovers!
> 17 August 2025: Colors fully added. 

## Installation
```any linux shell
chmod +x compile && ./compile
# or
make
# Note: I am still learning make, so i recommend to use compile script.
```

## Usage
```any linux shell
sudo ./pacostrap --stage=1 / -S=1 # For first stage
 ./pacostrap --stage=2 / -S=2 # For second stage
sudo ./pacostrap -S=1 --pass=format / -P=F  # For first stage and skipping formatting.
sudo ./pacostrap -S=1 --pass=mount / -P=M # For first stage and skipping formatting with mounting.
 ./pacostrap -S=2 --pass=mount / -P=M # For second stage and skipping disk mount.
```
> If you asking, *Why using sudo in first stage but not in the second?*
> Answer is: You will be root in archiso(so in the second stage) but you will probably non-root in normal destkop using.
### NOTES,
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
Firstly, you need to make directory at */usbmnt* then mount the USB at */usbmnt*.
You can do these steps by just running these following commands:
```ArchISO
mkdir /usbmnt
mount /dev/your-usb /usbmnt # You can learn your-usb by running lsblk
cd /usbmnt/pacostrap
```
Then,
**Mounts your disk at */mnt* ---> Makes */mnt/var/cache/pacman/* directory ---> Copies your packages to */mnt/var/cache/pacman/* ---> Calls pacstrap to Install your packages ---> Completes offline installation.**

## My New Ideas To Add `pacostrap`
- 1st Making second stage Archinstall compatible
- 2nd Support to other linux distros in first stage
- 3rd Make second stage archiso compatible.

## Fork(s) Of pacostrap
[javav12/pacofstrap](https://github.com/javav12/pacofstrap)

## Contributors

<a href="https://github.com/npc-gnu/pacostrap/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=npc-gnu/pacostrap" />
</a>

## License:
GNU General Public License version 3(GPLv3)
