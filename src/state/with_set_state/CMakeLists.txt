add_executable(state_with_set_state
    main.cpp
    concrete_states/concrete_state_a.h concrete_states/concrete_state_a.cpp
    concrete_states/concrete_state_b.h concrete_states/concrete_state_b.cpp
    concrete_states/concrete_state_c.h concrete_states/concrete_state_c.cpp
    context/context.cpp context/context.h
    state/state.cpp state/state.h
)

set_target_properties(state_with_set_state PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(state_with_set_state PUBLIC cxx_std_20)
target_compile_options(state_with_set_state PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_include_directories(state_with_set_state PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
target_link_libraries(state_with_set_state PRIVATE ${SANITIZER_FLAGS} fmt::fmt)

# copy to build directory
add_custom_command(TARGET state_with_set_state POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:state_with_set_state> ${CMAKE_BINARY_DIR})
