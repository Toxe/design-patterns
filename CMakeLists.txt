cmake_minimum_required(VERSION 3.18)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project("Design Patterns" LANGUAGES CXX)

# testing settings
include(cmake/Testing.cmake)

# adjust or override some CMake defaults
include(cmake/OverrideCMakeDefaults.cmake)

# default compiler options and warnings
include(cmake/DefaultCompilerOptions.cmake)
include(cmake/DefaultCompilerWarnings.cmake)

# static analyzers
include(cmake/StaticAnalyzers.cmake)

# sanitizers
include(cmake/Sanitizers.cmake)

find_package(fmt CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

find_path(NANOBENCH_INCLUDE_DIRS nanobench.h)

add_subdirectory(src/abstract_factory)
add_subdirectory(src/adapter)
add_subdirectory(src/bridge)
add_subdirectory(src/command/examples/with_classes)
add_subdirectory(src/command/examples/with_functions)
add_subdirectory(src/command/with_reference_semantics)
add_subdirectory(src/state/with_return_state)
add_subdirectory(src/state/with_set_state)
add_subdirectory(src/strategy/with_reference_semantics)
add_subdirectory(src/strategy/with_value_semantics)
