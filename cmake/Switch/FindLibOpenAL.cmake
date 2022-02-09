## A CMake helper to find GL libs on the system.

include(FindPackageHandleStandardArgs)

if(NOT SWITCH)
    message(FATAL_ERROR "This helper can only be used when cross-compiling for the Switch.")
endif()

set(OPENAL_PATHS ${LIBOPENAL} $ENV{LIBOPENAL} ${DEVKITPRO}/portlibs/switch libOPENAL)
set(OPENAL_INCLUDE_DIR ${DEVKITPRO}/portlibs/switch/include)

set(OPENAL_INCLUDE_DIRS ${OPENAL_INCLUDE_DIR})

if(OPENAL_FOUND)
    set(LIBOPENAL ${OPENAL_INCLUDE_DIR}/..)

    add_library(switch::libAl STATIC IMPORTED GLOBAL)
    set_target_properties(switch::libal PROPERTIES
            IMPORTED_LOCATION "${OPENAL_openal_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${OPENAL_INCLUDE_DIR}")
endif()
