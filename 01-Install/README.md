# Z88dk Installation mini guide

## 1. Operating System used

We are using Ubuntu 18.04.03 Budgie when writing this mini guide.

## 2. FUSE Installation

FUSE is the ZX-Spectrum Emulator that we are going to use for Linux.

There are two versions available:

- Fuse (SDL): SDL (Simple DirectMedia Layer) 
- Fuse (GTK+)

We choose the __GTK+__ and install it from the software center.

When starting FUSE, it will indicate that it has not found the ZX-Spectrum ROMs.

To install the roms, we have to do:

```shell
$ sudo apt-get install spectrum-roms fuse-emulator-utils
```

With this, when starting FUSE, the system should already recognize the ROMs.

## 3. Z88dk softwared download

It can be downloaded from here:

```html
 https://sourceforge.net/projects/z88dk/
```

What we download the file z88dk-src-1.99B.

Or doing:

```shell
$ wget http://nightly.z88dk.org/z88dk-latest.tgz
```

What we download the file z88dk-latest-tgz.

We are going to keep the latest.

## 4. Unzip and copy to work folder

Unzip the file z88dk-latest.tgz and copy the content to the __Programs__ folder of our home directory.

## 5. Binary Files Creation

The / bin folder is initially empty, and we have to build the binaries of the z88dk.

Here it is explained how it is installed:

```html
https://www.z88dk.org/wiki/doku.php?id=temp:front#linux_unix
```

### 5.1 Previous Installations

We need the following libraries:

```
dos2unix
libboost-all-dev
texinfo
texi2html
libxml2-dev
subversion
bison
flex
zlib1g-dev
```

In addition, we add the m4 library


```shell
$ sudo apt-get update
$ sudo apt-get install dos2unix
$ sudo apt-get install libboost-all-dev
$ sudo apt-get install texinfo
$ sudo apt-get install texi2html
$ apt-cache search libxml2
$ sudo apt-get install libxml2-dev
$ sudo apt-get install subversion
$ sudo apt-get install bison
$ sudo apt-get install flex
$ sudo apt-get install zlib1g-dev
$ sudo apt-get install m4
```

### 5.3 Binary Construction

To do this, you have to run the build.sh file found in the z88dk main folder:

```
$ cd z88dk
$ chmod 777 build.sh
$ ./build.sh
```

The process will take several minutes, and in svn checkout seems to be locke, please be patient.

If all went well, in the end the following trace should appear:

```
ZX7: Optimal LZ77/LZSS compression by Einar Saukas
File converted from 13400 to 5886 bytes! (delta 3)
z80asm -mz80n  -xlib/sccz80/zxn @target/zxn/library/zxn_sccz80.lst
z80asm -mz80n  -xlib/sdcc_ix/zxn -D__SDCC -D__SDCC_IX @target/zxn/library/zxn_sdcc_ix.lst
z80asm -mz80n  --IXIY -xlib/sdcc_iy/zxn -D__SDCC -D__SDCC_IY @target/zxn/library/zxn_sdcc_iy.lst
make: se sale del directorio '/home/user/Programas/z88dk/libsrc/_DEVELOPMENT'
make: se entra en el directorio '/home/user/Programas/z88dk/include/_DEVELOPMENT'
cp -r sccz80/adt ../
cp -r sccz80/alloc ../
cp -r sccz80/arch/zx/esxdos.h ../arch/zx/esxdos.h
cp -r sccz80/arch/zxn/esxdos.h ../arch/zxn/esxdos.h
make: se sale del directorio '/home/user/Programas/z88dk/include/_DEVELOPMENT'
```

## 5. Setting environment variables

We add the following to the .profile file:

```
#z88dk
export PATH=${PATH}:${HOME}/Programs/z88dk/bin
export ZCCCFG=${HOME}/Programs/z88dk/lib/config
```

We leave and re-enter the session

It is done.

After this, you could try the Helloworld example.

Enjoy it!



