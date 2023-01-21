add_executable(adapter_object
        main.cpp
        adaptee/adaptee.cpp
        adaptee/adaptee.h
        adapter/adapter.cpp
        adapter/adapter.h
        client/client.cpp
        client/client.h
        target/target.h)

set_target_properties(adapter_object PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(adapter_object PUBLIC cxx_std_20)
target_compile_options(adapter_object PRIVATE PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(adapter_object PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(adapter_object PRIVATE ${SANITIZER_LINK_LIBRARIES} fmt::fmt)
target_include_directories(adapter_object PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Tests
if (BUILD_TESTING)
    add_executable(adapter_object_tests
            tests.cpp
            adaptee/adaptee.cpp
            adaptee/adaptee.h
            adapter/adapter.cpp
            adapter/adapter.h
            client/client.cpp
            client/client.h
            target/target.h)

    set_target_properties(adapter_object_tests PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME tests)
    target_compile_features(adapter_object_tests PUBLIC cxx_std_20)
    target_compile_options(adapter_object_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(adapter_object_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(adapter_object_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} Catch2::Catch2WithMain)
    target_include_directories(adapter_object_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

    add_test(NAME adapter_object_tests COMMAND adapter_object_tests)
endif ()
