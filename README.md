# The Preservation Project

This repo contains a modified decompilation of Super Mario 64 which aims to recreate the SpaceWorld 1995 build.

As of June 2022, The Preservation Project has become an open source project, meaning the community can contribute to it to make it a perpetually improving recreation.

Please create any issues you find and feel free to pull request, any contributions are appreciated.

Original assets, to-do lists and more can soon be found in a special repository.

## Credits

### Original "The Preservation Project" Team

#### Programming

*Fluvian*

*Marionova*

#### Textures

*EmmaNerd*

*CDi-Fails*

*Lurondor*

*Robichu*

*Zucchino*

*HoloMario*

#### Models

*CDi-Fails*

*Lurondor*

*Robichu*

*Zucchino*

#### Sound

*EmmaNerd*

#### Research

*Xiartic*

#### Playtesting

*Xiartic*

*lunr*

### Contributors

*The1UPGuy*

*Guestpiki*

*iProgramInCpp*

*Toru the Red Fox*

*CreamDream*

### Original Super Mario 64 Decompilation Team

## Installation

### Docker

#### 1. Copy baserom(s) for asset extraction

For each version (jp/us/eu) that you want to build a ROM for, put an existing ROM at
`./baserom.<version>.z64` for asset extraction.

#### 2. Create docker image

```bash
docker build -t tpp .
```

#### 3. Build

To build we simply have to mount our local filesystem into the docker container and build.

```bash
# for example if you have baserom.us.z64 in the project root
docker run --rm -v ${PWD}:/tpp tpp make VERSION=jp -j4

# if your host system is linux you need to tell docker what user should own the output files
docker run --rm -v ${PWD}:/tpp --user $UID:$UID tpp make VERSION=jp -j4
```

Resulting artifacts can be found in the `build` directory.

### Linux

#### 1. Copy baserom(s) for asset extraction

To build TPP, you must provide a japanese ROM `./baserom.jp.z64` in the root folder for asset extraction.

#### 2. Install build dependencies

The build system has the following package requirements:
 * binutils-mips >= 2.27
 * python3 >= 3.6
 * libaudiofile
 * libcapstone-dev

__Debian / Ubuntu__
```
sudo apt install build-essential pkg-config git binutils-mips-linux-gnu python3 zlib1g-dev libaudiofile-dev libcapstone-dev
```

Download latest package from [qemu-irix Releases](https://github.com/n64decomp/qemu-irix/releases)
```
sudo dpkg -i qemu-irix-2.11.0-2169-g32ab296eef_amd64.deb
```

(Optional) Clone https://github.com/n64decomp/qemu-irix and follow the install instructions in the README.

__Arch Linux__
```
sudo pacman -S base-devel python audiofile
```
Install the following AUR packages:
* [mips64-elf-binutils](https://aur.archlinux.org/packages/mips64-elf-binutils) (AUR)
* [qemu-irix-git](https://aur.archlinux.org/packages/qemu-irix-git) (AUR)

#### 3. Build ROM

Run `make` to build the ROM (defaults to `VERSION=jp`). Make sure your path to the repo 
is not too long or else this process will error, as the emulated IDO compiler cannot 
handle paths longer than 255 characters.
Examples:
```
make VERSION=jp -j4       # build (J) version instead with 4 jobs
make VERSION=eu COMPARE=0 # non-matching EU version still WIP
```

## Windows

For Windows, install WSL and a distro of your choice following
[Windows Subsystem for Linux Installation Guide for Windows 10](https://docs.microsoft.com/en-us/windows/wsl/install-win10)
We recommend either Debian or Ubuntu 18.04 Linux distributions under WSL.

Then follow the directions in the [Linux](#linux) installation section above.

## macOS

macOS is currently unsupported as qemu-irix is unable to be built for macOS host.
The recommended path is installing a Linux distribution under a VM.

## Project Structure

```
sm64
├── actors: object behaviors, geo layout, and display lists
├── asm: handwritten assembly code, rom header
│   └── non_matchings: asm for non-matching sections
├── assets: animation and demo data
│   ├── anims: animation data
│   └── demos: demo data
├── bin: asm files for ordering display lists and textures
├── build: output directory
├── data: behavior scripts, misc. data
├── doxygen: documentation infrastructure
├── enhancements: example source modifications
├── include: header files
├── levels: level scripts, geo layout, and display lists
├── lib: SDK library code
├── sound: sequences, sound samples, and sound banks
├── src: C source code for game
│   ├── audio: audio code
│   ├── buffers: stacks, heaps, and task buffers
│   ├── engine: script processing engines and utils
│   ├── game: behaviors and rest of game source
│   ├── goddard: Mario intro screen
│   └── menu: title screen and file, act, and debug level selection menus
├── text: dialog, level names, act names
├── textures: skybox and generic texture data
└── tools: build tools
```
