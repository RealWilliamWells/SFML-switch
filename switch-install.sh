#! /bin/bash

set -eu
cmake -B build-switch -S . -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchains/DevkitA64Libnx.cmake
cd build-switch/
make
cd ..

sudo cp build-switch/lib/* $DEVKITPRO/portlibs/switch/lib
sudo cp -r include/SFML/ $DEVKITPRO/portlibs/switch/include/
