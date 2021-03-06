cmake_minimum_required(VERSION 3.18)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project("Design Patterns" LANGUAGES CXX)

# testing settings
include(cmake/Testing.cmake)

# adjust or override some CMake defaults
include(cmake/OverrideCMakeDefaults.cmake)

# default compiler options and warnings
include(cmake/DefaultCompilerOptionsAndWarnings.cmake)

# static analyzers
include(cmake/StaticAnalyzers.cmake)

# sanitizers
include(cmake/Sanitizers.cmake)

find_package(fmt CONFIG REQUIRED)

add_subdirectory(src/abstract_factory)
add_subdirectory(src/adapter)
add_subdirectory(src/bridge)
add_subdirectory(src/command/examples/with_classes)
add_subdirectory(src/command/examples/with_functions)
add_subdirectory(src/state/with_return_state)
add_subdirectory(src/state/with_set_state)
