# SFML switch port
This is a Switch port of the SFML libraries

## Dependencies
Before building, you must have devKitPro setup.

You only need libNX to build, but you need these libraries to link against:

  + OpenAL / [MojoAL](https://github.com/TomBebb/mojoAL-switch)
  + SDL2 (if using MojoAL)
  + LibNX
  + FLAC
  + Vorbis libraries
  + LibOGG
  + Mesa
  + LibPNG
  + ZLib
  + Nouveau DRM driver
  + GLAD
  + BZip2


## Building

1. Make build directory:

```bash
mkdir build
```

2. Run CMake to generate makefile:

```bash
cmake .. -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchains/DevkitA64Libnx.cmake
```

3. Build binaries:

```bash
make -j 8
```

4. Static libraries were generated in the lib/ folder.

## Usage

I usually copy the .a libraries to $DEVKITPRO/portlibs/switch/lib after to simplify using the lib.


## Examples
Check out the examples [here](https://github.com/TomBebb/switch-examples/tree/master/sfml) for an example of how to set-up linking.




[![SFML logo](https://www.sfml-dev.org/images/logo.png)](https://www.sfml-dev.org)

# SFML — Simple and Fast Multimedia Library

SFML is a simple, fast, cross-platform and object-oriented multimedia API. It provides access to windowing, graphics, audio and network. It is written in C++, and has bindings for various languages such as C, .Net, Ruby, Python.

## Authors

  - Laurent Gomila — main developer (laurent@sfml-dev.org)
  - Marco Antognini — OS X developer (hiura@sfml-dev.org)
  - Jonathan De Wachter — Android developer (dewachter.jonathan@gmail.com)
  - Jan Haller (bromeon@sfml-dev.org)
  - Stefan Schindler (tank@sfml-dev.org)
  - Lukas Dürrenberger (eXpl0it3r@sfml-dev.org)
  - binary1248 (binary1248@hotmail.com)
  - Artur Moreira (artturmoreira@gmail.com)
  - Mario Liebisch (mario@sfml-dev.org)
  - And many other members of the SFML community

## Download

You can get the latest official release on [SFML's website](https://www.sfml-dev.org/download.php). You can also get the current development version from the [Git repository](https://github.com/SFML/SFML).

## Install

Follow the instructions of the [tutorials](https://www.sfml-dev.org/tutorials/), there is one for each platform/compiler that SFML supports.

## Learn

There are several places to learn SFML:

  * The [official tutorials](https://www.sfml-dev.org/tutorials/)
  * The [online API documentation](https://www.sfml-dev.org/documentation/)
  * The [community wiki](https://github.com/SFML/SFML/wiki/)
  * The [community forum](https://en.sfml-dev.org/forums/) ([French](https://fr.sfml-dev.org/forums/))

## Contribute

SFML is an open-source project, and it needs your help to go on growing and improving. If you want to get involved and suggest some additional features, file a bug report or submit a patch, please have a look at the [contribution guidelines](https://www.sfml-dev.org/contribute.php).
