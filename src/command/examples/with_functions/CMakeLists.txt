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
target_compile_options(command_with_functions PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(command_with_functions PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(command_with_functions PRIVATE ${SANITIZER_LINK_LIBRARIES} fmt::fmt)
target_include_directories(command_with_functions PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)

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
    target_compile_options(command_with_functions_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(command_with_functions_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(command_with_functions_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} Catch2::Catch2WithMain fmt::fmt)
    target_include_directories(command_with_functions_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)

    add_test(NAME command_with_functions_tests COMMAND command_with_functions_tests)
endif ()
