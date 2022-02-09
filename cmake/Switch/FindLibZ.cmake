## A CMake helper to find zlib on the system.
##
## On success, it will define:
## > ZLIB_FOUND        - The system has zlib
## > ZLIB_INCLUDE_DIRS - The zlib include directories
## > ZLIB_LIBRARIES    - The static zlib libraries
##
## It also adds an imported target named `switch::zlib`.
##
## ```
## target_link_libraries(my_executable switch::zlib)
## ```
## is equivalent to
## ```
## target_include_directories(my_executable PRIVATE ${ZLIB_INCLUDE_DIRS})
## target_link_libraries(my_executable ${ZLIB_LIBRARIES})
## ```
##
## By default, CMake will look for zlib in $DEVKITPRO/zlib.
## If you want to use a custom fork, you need to override the
## `ZLIB` variable within CMake before this file is used.

include(FindPackageHandleStandardArgs)

if(NOT SWITCH)
    message(FATAL_ERROR "This helper can only be used when cross-compiling for the Switch.")
endif()

set(ZLIB_PATHS ${ZLIB} $ENV{ZLIB} ${DEVKITPRO}/portlibs/switch zlib)

find_path(ZLIB_INCLUDE_DIR zlib.h
        PATHS ${ZLIB_PATHS}
        PATH_SUFFIXES include)

find_library(ZLIB_LIBRARY NAMES libz.a
        PATHS ${ZLIB_PATHS}
        PATH_SUFFIXES lib)

set(ZLIB_INCLUDE_DIRS ${ZLIB_INCLUDE_DIR})
set(ZLIB_LIBRARIES ${ZLIB_LIBRARY})

find_package_handle_standard_args(ZLIB DEFAULT_MSG
        ZLIB_INCLUDE_DIR ZLIB_LIBRARY)

mark_as_advanced(ZLIB_INCLUDE_DIR ZLIB_LIBRARY)

if(ZLIB_FOUND)
    set(ZLIB ${ZLIB_INCLUDE_DIR}/..)

    add_library(switch::zlib STATIC IMPORTED GLOBAL)
    set_target_properties(switch::zlib PROPERTIES
            IMPORTED_LOCATION "${ZLIB_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${ZLIB_INCLUDE_DIR}")
        
    include_directories(${ZLIB_INCLUDE_DIR})
endif()

if (NOT ZLIB_FOUND)
    message("ZLIB NOT FOUND: ${ZLIB_PATHS}; include: ${ZLIB_INCLUDE_DIR}; lib: ${ZLIB_LIBRARY}")
endif()