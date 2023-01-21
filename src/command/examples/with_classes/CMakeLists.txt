add_executable(command_with_classes
        main.cpp
        client/client.cpp
        client/client.h
        client/client_commands.h
        include/command.h
        include/keyboard_events.h
        invoker/invoker.cpp
        invoker/invoker.h
        receiver/receiver.cpp
        receiver/receiver.h
        receiver/receiver_commands.h)

set_target_properties(command_with_classes PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(command_with_classes PUBLIC cxx_std_20)
target_compile_options(command_with_classes PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(command_with_classes PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(command_with_classes PRIVATE ${SANITIZER_LINK_LIBRARIES} fmt::fmt)
target_include_directories(command_with_classes PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)

# Tests
if (BUILD_TESTING)
    add_executable(command_with_classes_tests
            tests.cpp
            client/client.cpp
            client/client.h
            client/client_commands.h
            include/command.h
            include/keyboard_events.h
            invoker/invoker.cpp
            invoker/invoker.h
            receiver/receiver.cpp
            receiver/receiver.h
            receiver/receiver_commands.h)

    set_target_properties(command_with_classes_tests PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME tests)
    target_compile_features(command_with_classes_tests PUBLIC cxx_std_20)
    target_compile_options(command_with_classes_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(command_with_classes_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(command_with_classes_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} Catch2::Catch2WithMain fmt::fmt)
    target_include_directories(command_with_classes_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)

    add_test(NAME command_with_classes_tests COMMAND command_with_classes_tests)
endif ()
