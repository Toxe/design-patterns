add_executable(command
    main.cpp
    client/client_commands.h
    client/client.cpp client/client.h
    include/command.h
    include/keyboard_events.h
    invoker/invoker.cpp invoker/invoker.h
    receiver/receiver_commands.h
    receiver/receiver.cpp receiver/receiver.h
)

set_target_properties(command PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(command PUBLIC cxx_std_20)
target_compile_options(command PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_include_directories(command PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
target_link_libraries(command PRIVATE ${SANITIZER_FLAGS} fmt::fmt spdlog::spdlog spdlog::spdlog_header_only)
