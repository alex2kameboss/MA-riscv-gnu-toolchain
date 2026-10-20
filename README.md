Custom RISC-V GNU Compiler Toolchain
=============================

This repository is a fork from [RISC-V GNU Compiler Toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain). This is a compiler for a [custom tightly coupled accelerator](https://github.com/alex2kameboss/MatrixAccelerator).

### Examples

[This header file](https://raw.githubusercontent.com/alex2kameboss/MatrixAcceleratorDemo/refs/heads/master/apps/common/include/ImtMatrixAccelerator.h) provide example for inline assembly usage in C code.

Source code for various matrix operations are available [here](https://github.com/alex2kameboss/MatrixAcceleratorDemo/tree/master/apps/matrix_accelerator).

###  Getting the sources

This repository uses submodules, but submodules will fetch automatically on demand,
so `--recursive` or `git submodule update --init --recursive` is not needed.

    $ git clone https://github.com/alex2kameboss/MA-riscv-gnu-toolchain

**Warning: git clone takes around 6.65 GB of disk and download size**

### Prerequisites

Several standard packages are needed to build the toolchain.  

On Ubuntu, executing the following command should suffice:

    $ sudo apt-get install autoconf automake autotools-dev curl python3 python3-pip libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev

On Fedora/CentOS/RHEL OS, executing the following command should suffice:

    $ sudo yum install autoconf automake python3 libmpc-devel mpfr-devel gmp-devel gawk  bison flex texinfo patchutils gcc gcc-c++ zlib-devel expat-devel libslirp-devel
    
On Arch Linux, executing the following command should suffice:

    $ sudo pacman -Syyu autoconf automake curl python3 libmpc mpfr gmp gawk base-devel bison flex texinfo gperf libtool patchutils bc zlib expat libslirp

Also available for Arch users on the AUR: [https://aur.archlinux.org/packages/riscv-gnu-toolchain-bin](https://aur.archlinux.org/packages/riscv-gnu-toolchain-bin)

On OS X, you can use [Homebrew](http://brew.sh) to install the dependencies:

    $ brew install python3 gawk gnu-sed gmp mpfr libmpc isl zlib expat texinfo flock libslirp

To build the glibc (Linux) on OS X, you will need to build within a case-sensitive file
system.  The simplest approach is to create and mount a new disk image with
a case sensitive format.  Make sure that the mount point does not contain spaces. This is not necessary to build newlib or gcc itself on OS X.

This process will start by downloading about 200 MiB of upstream sources, then
will patch, build, and install the toolchain.  If a local cache of the
upstream sources exists in $(DISTDIR), it will be used; the default location
is /var/cache/distfiles.  Your computer will need about 8 GiB of disk space to
complete the process.

### Installation (Newlib)

To build the Newlib cross-compiler, pick an install path (that is writeable).
If you choose, say, `/opt/riscv`, then add `/opt/riscv/bin` to your `PATH`.
Then, simply run the following command:

    ./configure --prefix=/opt/riscv
    make

You should now be able to use riscv64-unknown-elf-gcc and its cousins.

Note: If you're planning to use an external library that replaces part of newlib (for example `libgloss-htif`), [read the FAQ](#ensuring-code-model-consistency).

### Installation (Linux)

To build the Linux cross-compiler, pick an install path (that is writeable).
If you choose, say, `/opt/riscv`, then add `/opt/riscv/bin` to your `PATH`.
Then, simply run the following command:

    ./configure --prefix=/opt/riscv
    make linux

The build defaults to targeting RV64GC (64-bit) with glibc, even on a 32-bit
build environment. To build the 32-bit RV32GC toolchain, use:

    ./configure --prefix=/opt/riscv --with-arch=rv32gc --with-abi=ilp32d
    make linux

In case you prefer musl libc over glibc, configure just like above and opt for
`make musl` instead of `make linux`.

Supported architectures are rv32i or rv64i plus standard extensions (a)tomics,
(m)ultiplication and division, (f)loat, (d)ouble, or (g)eneral for MAFD.

Supported ABIs are ilp32 (32-bit soft-float), ilp32d (32-bit hard-float),
ilp32f (32-bit with single-precision in registers and double in memory, niche
use only), lp64 lp64f lp64d (same but with 64-bit long and pointers).

### Installation (Newlib/Linux multilib)

To build either cross-compiler with support for both 32-bit and
64-bit, run the following command:

    ./configure --prefix=/opt/riscv --enable-multilib
    
And then either `make`, `make linux` or `make musl` for the Newlib, Linux
glibc-based or Linux musl libc-based cross-compiler, respectively.

The multilib compiler will have the prefix riscv64-unknown-elf- or
riscv64-unknown-linux-gnu- but will be able to target both 32-bit and 64-bit
systems.
It will support the most common `-march`/`-mabi` options, which can be seen by
using the `--print-multi-lib` flag on either cross-compiler.

The musl compiler (riscv64-unknown-linux-musl-) will only be able to target
64-bit systems due to limitations in the upstream musl architecture support.
The `--enable-multilib` flag therefore does not actually enable multilib support
for musl libc.

### Acknowledgements

This work was supported by a grant of the Ministry of Research, Innovation and Digitization, CNCS/CCCDI - UEFISCDI, project number PN-IV-P8-8.1-PME-2024-0022, within PNCDI IV.

The ISOLDE project, nr. 101112274 is supported by the Chips Joint Undertaking and its members Austria, Czechia, France, Germany, Italy, Romania, Spain, Sweden, Switzerland.