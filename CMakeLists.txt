cmake_minimum_required(VERSION 3.18)

project(bayestest VERSION 0.1.1 LANGUAGES C)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    add_library(bayestest INTERFACE)
    add_library(bayestest::bayestest ALIAS bayestest)

    if(NOT MSVC)
        target_link_libraries(bayestest INTERFACE m)
    endif()

    target_include_directories(
        bayestest
        INTERFACE
        "${PROJECT_SOURCE_DIR}/include/"
    )

    option(BUILD_TESTING "" ON)

    if(BUILD_TESTING)
        add_executable(test test/main.c)
        target_link_libraries(test PRIVATE bayestest::bayestest)
        if(NOT MSVC)
            target_compile_options(test PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Werror)
        endif()
    endif()
endif()
