add_executable(abstract_factory
        main.cpp
        abstract_products/abstract_factory.h
        abstract_products/abstract_product_a.h
        abstract_products/abstract_product_b.h
        client/client.cpp
        client/client.h
        product1/factory1.h
        product1/product_a1.h
        product1/product_b1.h
        product2/factory2.h
        product2/product_a2.h
        product2/product_b2.h)

set_target_properties(abstract_factory PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(abstract_factory PUBLIC cxx_std_20)
target_compile_options(abstract_factory PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
target_include_directories(abstract_factory PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} include)
target_link_libraries(abstract_factory PRIVATE ${SANITIZER_FLAGS} fmt::fmt)

# copy to build directory
add_custom_command(TARGET abstract_factory POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:abstract_factory> ${CMAKE_BINARY_DIR})

# Tests
if (BUILD_TESTING)
    add_executable(abstract_factory_tests
            tests.cpp
            abstract_products/abstract_factory.h
            abstract_products/abstract_product_a.h
            abstract_products/abstract_product_b.h
            product1/factory1.h
            product1/product_a1.h
            product1/product_b1.h
            product2/factory2.h
            product2/product_a2.h
            product2/product_b2.h)

    set_target_properties(abstract_factory_tests PROPERTIES CXX_EXTENSIONS OFF OUTPUT_NAME tests)
    target_compile_features(abstract_factory_tests PUBLIC cxx_std_20)
    target_compile_options(abstract_factory_tests PRIVATE ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
    target_link_libraries(abstract_factory_tests PRIVATE Catch2::Catch2WithMain)

    add_test(NAME abstract_factory_tests COMMAND abstract_factory_tests)
endif ()
