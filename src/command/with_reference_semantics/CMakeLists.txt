add_executable(command_with_reference_semantics
    main.cpp
    command/command.hpp
    command/add.hpp
    command/multiply.hpp
    calculator/calculator.cpp
    calculator/calculator.hpp
)

set_target_properties(command_with_reference_semantics PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(command_with_reference_semantics PUBLIC cxx_std_20)
target_compile_options(command_with_reference_semantics PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(command_with_reference_semantics PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(command_with_reference_semantics PRIVATE ${SANITIZER_LINK_LIBRARIES} fmt::fmt)

# copy to build directory
add_custom_command(TARGET command_with_reference_semantics POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:command_with_reference_semantics> ${CMAKE_BINARY_DIR})

# Tests
if(BUILD_TESTING)
    add_executable(command_with_reference_semantics_tests
        tests.cpp
        command/command.hpp
        command/add.hpp
        command/multiply.hpp
        calculator/calculator.cpp
        calculator/calculator.hpp
    )

    set_target_properties(command_with_reference_semantics_tests PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME tests)
    target_compile_features(command_with_reference_semantics_tests PUBLIC cxx_std_20)
    target_compile_options(command_with_reference_semantics_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(command_with_reference_semantics_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(command_with_reference_semantics_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} Catch2::Catch2WithMain fmt::fmt)

    add_test(NAME command_with_reference_semantics_tests COMMAND command_with_reference_semantics_tests)
endif()
