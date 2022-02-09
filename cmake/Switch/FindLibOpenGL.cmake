## A CMake helper to find GL libs on the system.

include(FindPackageHandleStandardArgs)

if(NOT SWITCH)
    message(FATAL_ERROR "This helper can only be used when cross-compiling for the Switch.")
endif()

set(OPENGL_PATHS ${LIBOPENGL} $ENV{LIBOPENGL} ${DEVKITPRO}/portlibs/switch libOPENGL)
set(OPENGL_INCLUDE_DIR ${DEVKITPRO}/portlibs/switch/include)

find_library(OPENGL_opengl_LIBRARY NAMES libEGL.a
        PATHS ${OPENGL_PATHS}
        PATH_SUFFIXES lib)

set(OPENGL_INCLUDE_DIRS ${OPENGL_INCLUDE_DIR})
set(OPENGL_LIBRARIES ${OPENGL_opengl_LIBRARY})

find_package_handle_standard_args(LIBOPENGL DEFAULT_MSG
        OPENGL_INCLUDE_DIR OPENGL_opengl_LIBRARY)

mark_as_advanced(OPENGL_INCLUDE_DIR OPENGL_opengl_LIBRARY)

message("Include dir for OPENGL: ${OPENGL_PATHS}: ${OPENGL_INCLUDE_DIRS}")
if(OPENGL_FOUND)
    set(LIBOPENGL ${OPENGL_INCLUDE_DIR}/..)

    add_library(switch::libgl STATIC IMPORTED GLOBAL)
    set_target_properties(switch::libgl PROPERTIES
            IMPORTED_LOCATION "${OPENGL_opengl_LIBRARY}"
            INTERFACE_INCLUDE_DIRECTORIES "${OPENGL_INCLUDE_DIR}")
endif()
