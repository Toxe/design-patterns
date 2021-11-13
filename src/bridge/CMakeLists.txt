add_executable(bridge
        main.cpp
        abstraction/abstraction.cpp
        abstraction/abstraction.h
        client/client.cpp
        client/client.h
        concrete_implementors/concrete_implementor1.cpp
        concrete_implementors/concrete_implementor1.h
        concrete_implementors/concrete_implementor2.cpp
        concrete_implementors/concrete_implementor2.h
        implementor/implementor.h
        refined_abstractions/refined_abstraction_a.cpp
        refined_abstractions/refined_abstraction_a.h
        refined_abstractions/refined_abstraction_b.cpp
        refined_abstractions/refined_abstraction_b.h)

set_target_properties(bridge PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(bridge PUBLIC cxx_std_20)
target_compile_options(bridge PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_include_directories(bridge PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(bridge PRIVATE ${SANITIZER_FLAGS} fmt::fmt)

# copy to build directory
add_custom_command(TARGET bridge POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:bridge> ${CMAKE_BINARY_DIR})

# Tests
if (BUILD_TESTING)
    add_executable(bridge_tests
            tests.cpp
            abstraction/abstraction.cpp
            abstraction/abstraction.h
            client/client.cpp
            client/client.h
            concrete_implementors/concrete_implementor1.cpp
            concrete_implementors/concrete_implementor1.h
            concrete_implementors/concrete_implementor2.cpp
            concrete_implementors/concrete_implementor2.h
            implementor/implementor.h
            refined_abstractions/refined_abstraction_a.cpp
            refined_abstractions/refined_abstraction_a.h
            refined_abstractions/refined_abstraction_b.cpp
            refined_abstractions/refined_abstraction_b.h)

    set_target_properties(bridge_tests PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME tests)
    target_compile_features(bridge_tests PUBLIC cxx_std_20)
    target_compile_options(bridge_tests PRIVATE ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
    target_include_directories(bridge_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(bridge_tests PRIVATE Catch2::Catch2WithMain fmt::fmt)

    add_test(NAME bridge_tests COMMAND bridge_tests)
endif ()
