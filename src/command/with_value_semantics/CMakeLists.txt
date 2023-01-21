add_executable(command_with_value_semantics
    main.cpp
    command/command.hpp
    command/add.hpp
    command/multiply.hpp
    calculator/calculator.cpp
    calculator/calculator.hpp
)

set_target_properties(command_with_value_semantics PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(command_with_value_semantics PUBLIC cxx_std_20)
target_compile_options(command_with_value_semantics PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(command_with_value_semantics PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(command_with_value_semantics PRIVATE ${SANITIZER_LINK_LIBRARIES} fmt::fmt)

# Tests
if(BUILD_TESTING)
    add_executable(command_with_value_semantics_tests
        tests.cpp
        command/command.hpp
        command/add.hpp
        command/multiply.hpp
        calculator/calculator.cpp
        calculator/calculator.hpp
    )

    set_target_properties(command_with_value_semantics_tests PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME tests)
    target_compile_features(command_with_value_semantics_tests PUBLIC cxx_std_20)
    target_compile_options(command_with_value_semantics_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(command_with_value_semantics_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(command_with_value_semantics_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} Catch2::Catch2WithMain fmt::fmt)

    add_test(NAME command_with_value_semantics_tests COMMAND command_with_value_semantics_tests)
endif()

# benchmark
add_executable(command_with_value_semantics_benchmark
        benchmark.cpp
        command/command.hpp
        command/add.hpp
        command/multiply.hpp
        calculator/calculator.cpp
        calculator/calculator.hpp
)

set_target_properties(command_with_value_semantics_benchmark PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME benchmark)
target_compile_features(command_with_value_semantics_benchmark PUBLIC cxx_std_20)
target_compile_options(command_with_value_semantics_benchmark PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(command_with_value_semantics_benchmark PRIVATE ${SANITIZER_LINK_OPTIONS})
target_include_directories(command_with_value_semantics_benchmark PRIVATE ${NANOBENCH_INCLUDE_DIRS})
