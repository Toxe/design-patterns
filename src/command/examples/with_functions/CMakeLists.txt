add_executable(command_with_functions
        main.cpp
        client/client.cpp
        client/client.h
        client/client_commands.cpp
        client/client_commands.h
        include/command.h
        include/keyboard_events.h
        invoker/invoker.cpp
        invoker/invoker.h
        receiver/receiver.cpp
        receiver/receiver.h
        receiver/receiver_commands.cpp
        receiver/receiver_commands.h)

set_target_properties(command_with_functions PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(command_with_functions PUBLIC cxx_std_20)
target_compile_options(command_with_functions PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_include_directories(command_with_functions PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
target_link_libraries(command_with_functions PRIVATE ${SANITIZER_FLAGS} fmt::fmt)

# copy to build directory
add_custom_command(TARGET command_with_functions POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:command_with_functions> ${CMAKE_BINARY_DIR})

# Tests
if (BUILD_TESTING)
    add_executable(command_with_functions_tests
            tests.cpp
            client/client.cpp
            client/client.h
            client/client_commands.cpp
            client/client_commands.h
            include/command.h
            include/keyboard_events.h
            invoker/invoker.cpp
            invoker/invoker.h
            receiver/receiver.cpp
            receiver/receiver.h
            receiver/receiver_commands.cpp
            receiver/receiver_commands.h)

    set_target_properties(command_with_functions_tests PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME tests)
    target_compile_features(command_with_functions_tests PUBLIC cxx_std_20)
    target_compile_options(command_with_functions_tests PRIVATE ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
    target_include_directories(command_with_functions_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
    target_link_libraries(command_with_functions_tests PRIVATE Catch2::Catch2WithMain fmt::fmt)

    add_test(NAME command_with_functions_tests COMMAND command_with_functions_tests)
endif ()
