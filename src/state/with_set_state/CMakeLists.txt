add_executable(state_with_set_state
        main.cpp
        concrete_states/concrete_state_a.cpp
        concrete_states/concrete_state_a.h
        concrete_states/concrete_state_b.cpp
        concrete_states/concrete_state_b.h
        concrete_states/concrete_state_c.cpp
        concrete_states/concrete_state_c.h
        context/context.cpp
        context/context.h
        state/state.cpp
        state/state.h)

set_target_properties(state_with_set_state PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(state_with_set_state PUBLIC cxx_std_20)
target_compile_options(state_with_set_state PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(state_with_set_state PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(state_with_set_state PRIVATE ${SANITIZER_LINK_LIBRARIES} fmt::fmt)
target_include_directories(state_with_set_state PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# copy to build directory
add_custom_command(TARGET state_with_set_state POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:state_with_set_state> ${CMAKE_BINARY_DIR})

# Tests
if (BUILD_TESTING)
    add_executable(state_with_set_state_tests
            tests.cpp
            concrete_states/concrete_state_a.cpp
            concrete_states/concrete_state_a.h
            concrete_states/concrete_state_b.cpp
            concrete_states/concrete_state_b.h
            concrete_states/concrete_state_c.cpp
            concrete_states/concrete_state_c.h
            context/context.cpp
            context/context.h
            state/state.cpp
            state/state.h)

    set_target_properties(state_with_set_state_tests PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME tests)
    target_compile_features(state_with_set_state_tests PUBLIC cxx_std_20)
    target_compile_options(state_with_set_state_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(state_with_set_state_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(state_with_set_state_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} Catch2::Catch2WithMain fmt::fmt)
    target_include_directories(state_with_set_state_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

    add_test(NAME state_with_set_state_tests COMMAND state_with_set_state_tests)
endif ()
