## A CMake helper to find SDL2 libs on the system.
##
## On success, it will define:
## > SDL2_FOUND        - The system has SDL2
## > SDL2_INCLUDE_DIRS - The SDL2 include directories
## > SDL2_LIBRARIES    - The static SDL2 libraries
##
## It also adds an imported target named `switch::sdl2`.
##
## ```
## target_link_libraries(my_executable switch::sdl2)
## ```
## is equivalent to
## ```
## target_include_directories(my_executable PRIVATE ${SDL2_INCLUDE_DIRS})
## target_link_libraries(my_executable ${SDL2_LIBRARIES})
## ```
##
## By default, CMake will look for libSDL in $DEVKITPRO/portlibs/switch.

include(FindPackageHandleStandardArgs)

if(NOT SWITCH)
    message(FATAL_ERROR "This helper can only be used when cross-compiling for the Switch.")
endif()

set(LIBSDL2_PATHS ${LIBSDL2} $ENV{LIBSDL2} ${DEVKITPRO}/portlibs/switch libsdl2)

find_path(LIBSDL2_INCLUDE_DIR SDL.h
        PATHS ${LIBSDL2_PATHS}
        PATH_SUFFIXES include)

find_library(LIBSDL2_LIBRARY NAMES libSDL.a
        PATHS ${LIBSDL2_PATHS}
        PATH_SUFFIXES lib)

set(LIBSDL2_INCLUDE_DIRS ${LIBSDL2_INCLUDE_DIR})
set(LIBSDL2_LIBRARIES ${LIBSDL2_LIBRARY})

find_package_handle_standard_args(LIBSDL2 DEFAULT_MSG
        LIBSDL2_INCLUDE_DIR LIBSDL2_LIBRARY)

mark_as_advanced(LIBSDL2_INCLUDE_DIR LIBSDL2_LIBRARY)

if(LIBSDL2_FOUND)
    set(LIBSDL2 ${LIBSDL2_INCLUDE_DIR}/..)

    add_library(switch::libsdl2 STATIC IMPORTED GLOBAL)
    set_target_properties(switch::libsdl2 PROPERTIES
            IMPORTED_LOCATION "${LIBSDL2_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${LIBSDL2_INCLUDE_DIR}")
endif()
