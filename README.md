![pacostrap logo](pacostrap.png)

# pacostrap-beta
## pacstrap for offline installation(manuel arch installation)

Hello Arch lovers!
> 15 August 2025: Short argumants added. 
> --stage to -S , pass to -P .
> Now --pass argumant is get used and --skip argumant deleted.

## Installation
```any linux shell
chmod +x compile && ./compile
# or
make
# Note: I am still learning make, so i recommend to use compile script.
```

## Usage
```any linux shell
sudo ./pacostrap --stage=1 *or* -S=1 # For first stage
 ./pacostrap --stage=2 *or* -S=2 # For second stage
sudo ./pacostrap -S=1 --pass=format *or* -P=F  # For first stage and skipping formatting.
sudo ./pacostrap -S=1 --pass=mount *or -P=M # For first stage and skipping formatting with mounting.
 ./pacostrap -S=2 --pass=mount *or* -P=M # For second stage and skipping disk mount.
```
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
You can do this steps by just running these following commands:
```ArchISO
mkdir /usbmnt
mount **/dev/*your-usb-path.* You can learn it by running lsblk** /usbmnt
```
Then,
**Mounts your disk at */mnt* ---> Makes */mnt/var/cache/pacman/* directory ---> Copies your packages to */mnt/var/cache/pacman/* ---> Calls pacstrap to Install your packages ---> Completes offline installation.**

## My New Ideas To Add `pacostrap`
- 1st Colors
- 2nd Support to other linux distros in first stage
- 3rd Make second stage archiso compatible.

## License:
GNU General Public License version 3(GPLv3)
