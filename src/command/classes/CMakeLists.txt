add_executable(command_with_classes
    main.cpp
    client/client_commands.h
    client/client.cpp client/client.h
    include/command.h
    include/keyboard_events.h
    invoker/invoker.cpp invoker/invoker.h
    receiver/receiver_commands.h
    receiver/receiver.cpp receiver/receiver.h
)

set_target_properties(command_with_classes PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(command_with_classes PUBLIC cxx_std_20)
target_compile_options(command_with_classes PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_include_directories(command_with_classes PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
target_link_libraries(command_with_classes PRIVATE ${SANITIZER_FLAGS} fmt::fmt)
