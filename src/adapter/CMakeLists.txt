add_executable(adapter_object
    main.cpp
    adaptee/adaptee.cpp adaptee/adaptee.h
    adapter/adapter.cpp adapter/adapter.h
    client/client.cpp client/client.h
    target/target.h
)

set_target_properties(adapter_object PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(adapter_object PUBLIC cxx_std_20)
target_compile_options(adapter_object PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_include_directories(adapter_object PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
target_link_libraries(adapter_object PRIVATE ${SANITIZER_FLAGS} fmt::fmt)

# copy to build directory
add_custom_command(TARGET adapter_object POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:adapter_object> ${CMAKE_BINARY_DIR})
