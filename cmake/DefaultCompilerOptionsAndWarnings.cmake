# Define default compiler options and warnings for Clang, GCC and MSVC.

# shared options between Clang, Clang-cl and GCC
set(SHARED_CLANG_AND_CLANG_CL_AND_GCC_OPTIONS
        -Wextra
        -Wconversion
        -Wsign-conversion
        -Wfloat-equal
        -Wold-style-cast
        -Wshadow
        -Wunused)

# Clang specific options
set(DEFAULT_CLANG_OPTIONS
        ${SHARED_CLANG_AND_CLANG_CL_AND_GCC_OPTIONS}
        -Wall
        -Wmost
        -pedantic
        -fcolor-diagnostics)

# GCC specific options
set(DEFAULT_GCC_OPTIONS
        ${SHARED_CLANG_AND_CLANG_CL_AND_GCC_OPTIONS}
        -Wall
        -pedantic
        -fdiagnostics-color)

# MSVC specific options
set(DEFAULT_MSVC_OPTIONS
        /W4)

# Clang-cl specific options (Clang + MSVC)
set(DEFAULT_CLANG_CL_OPTIONS
        ${SHARED_CLANG_AND_CLANG_CL_AND_GCC_OPTIONS}
        ${DEFAULT_MSVC_OPTIONS})

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND NOT CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    # Clang
    set(DEFAULT_COMPILER_OPTIONS_AND_WARNINGS ${DEFAULT_CLANG_OPTIONS})
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
    # Clang-cl
    set(DEFAULT_COMPILER_OPTIONS_AND_WARNINGS ${DEFAULT_CLANG_CL_OPTIONS})
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # GCC
    set(DEFAULT_COMPILER_OPTIONS_AND_WARNINGS ${DEFAULT_GCC_OPTIONS})
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # MSVC
    string(REGEX REPLACE " /W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    set(DEFAULT_COMPILER_OPTIONS_AND_WARNINGS ${DEFAULT_MSVC_OPTIONS})
endif ()
