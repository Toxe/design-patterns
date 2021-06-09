cmake_minimum_required(VERSION 3.13)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project("Design Patterns" LANGUAGES CXX)

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
add_subdirectory(src/command/examples/with_classes)
add_subdirectory(src/command/examples/with_functions)
