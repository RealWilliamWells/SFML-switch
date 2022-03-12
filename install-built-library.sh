#! /bin/bash

cd build/

make

cd ../

sudo cp build/lib/* $DEVKITPRO/portlibs/switch/lib

sudo cp -r include/SFML/ $DEVKITPRO/portlibs/switch/include/
