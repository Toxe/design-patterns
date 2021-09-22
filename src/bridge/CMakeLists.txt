add_executable(bridge
    main.cpp
    client/client.cpp client/client.h
    abstraction/abstraction.cpp abstraction/abstraction.h
    refined_abstractions/refined_abstraction_a.cpp refined_abstractions/refined_abstraction_a.h
    refined_abstractions/refined_abstraction_b.cpp refined_abstractions/refined_abstraction_b.h
    implementor/implementor.h
    concrete_implementors/concrete_implementor1.cpp concrete_implementors/concrete_implementor1.h
    concrete_implementors/concrete_implementor2.cpp concrete_implementors/concrete_implementor2.h
)

set_target_properties(bridge PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(bridge PUBLIC cxx_std_20)
target_compile_options(bridge PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_include_directories(bridge PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
target_link_libraries(bridge PRIVATE ${SANITIZER_FLAGS} fmt::fmt)

# copy to build directory
add_custom_command(TARGET bridge POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:bridge> ${CMAKE_BINARY_DIR})
