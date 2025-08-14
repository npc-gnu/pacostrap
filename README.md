![pacostrap logo](pacostrap.png)

# pacostrap-alpha
## pacstrap for offline installation(manuel arch installation)

Hello guys!
I finally developed pacostrap fully but i never tested it. But it should probably work.
And, one more argumant added too! `--skip` argumant.
You can use --skip=format for skip formatting, --skip=mount for skipping format and mount.

## Installation
```any linux shell
chmod +x compile && ./compile
```

## Usage
```any linux shell
sudo ./pacostrap --stage=1 # for first stage
sudo ./pacostrap --stage=2 # for second stage
sudo ./pacostrap --stage=1 --skip=format # For first stage and skipping formatting.
sudo ./pacostrap --stage=1 --skip=mount # For first stage and skipping formatting with mounting.
```
### BUT,
- At second stage, you need to mount USB at /usbmnt.
> If you are using skip argumants,
- In 1'st stage ---*skipping format*---> USB needs to be in a FS that Linux can recognize(exFAT, ext4, BTRFS, NTFS(maybe. Sometimes it needs extra packages.)) ----\
                \-----> USB needs to mounted at /mnt <-----------------------*skipping both format and mounting*---------------------------------------------------/
- In 2'nd stage ---*Skipping disk mounting*---> Disk should be mounted at /mnt and you need to make directory at /mnt/var/cache/pacman/pkg. 

## My New Ideas To Add `pacostrap`
- 1. Shorted argumants (Example: --stage=1 to -S=1, --skip=mount to -s=m )
- 2. Colors
- 3. Support to other linux distros in first stage

## License:
GNU General Public License version 3(GPLv3)
