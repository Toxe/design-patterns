add_executable(strategy_with_reference_semantics
    main.cpp
    print_strategy/json_circle_print_strategy.cpp
    print_strategy/json_circle_print_strategy.hpp
    print_strategy/json_rectangle_print_strategy.cpp
    print_strategy/json_rectangle_print_strategy.hpp
    print_strategy/print_strategy.hpp
    print_strategy/simple_circle_print_strategy.cpp
    print_strategy/simple_circle_print_strategy.hpp
    print_strategy/simple_rectangle_print_strategy.cpp
    print_strategy/simple_rectangle_print_strategy.hpp
    shape/circle.hpp
    shape/rectangle.hpp
    shape/shape.hpp
)

set_target_properties(strategy_with_reference_semantics PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(strategy_with_reference_semantics PUBLIC cxx_std_20)
target_compile_options(strategy_with_reference_semantics PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(strategy_with_reference_semantics PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(strategy_with_reference_semantics PRIVATE ${SANITIZER_LINK_LIBRARIES} fmt::fmt nlohmann_json::nlohmann_json)

# Tests
if(BUILD_TESTING)
    add_executable(strategy_with_reference_semantics_tests
        tests.cpp
        print_strategy/json_circle_print_strategy.cpp
        print_strategy/json_circle_print_strategy.hpp
        print_strategy/json_rectangle_print_strategy.cpp
        print_strategy/json_rectangle_print_strategy.hpp
        print_strategy/print_strategy.hpp
        print_strategy/simple_circle_print_strategy.cpp
        print_strategy/simple_circle_print_strategy.hpp
        print_strategy/simple_rectangle_print_strategy.cpp
        print_strategy/simple_rectangle_print_strategy.hpp
        shape/circle.hpp
        shape/rectangle.hpp
        shape/shape.hpp
    )

    set_target_properties(strategy_with_reference_semantics_tests PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME tests)
    target_compile_features(strategy_with_reference_semantics_tests PUBLIC cxx_std_20)
    target_compile_options(strategy_with_reference_semantics_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(strategy_with_reference_semantics_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(strategy_with_reference_semantics_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} Catch2::Catch2WithMain fmt::fmt nlohmann_json::nlohmann_json)

    add_test(NAME strategy_with_reference_semantics_tests COMMAND strategy_with_reference_semantics_tests)
endif()
