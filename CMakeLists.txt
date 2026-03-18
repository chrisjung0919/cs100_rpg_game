cmake_minimum_required(VERSION 3.2)
project(character-testing)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS --coverage)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

# Reference: https://github.com/google/googletest/tree/main/googletest#incorporating-into-an-existing-cmake-project
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif ()

set(SOURCE_FILES character_class/character.cpp enemy_class/enemy.cpp hero_class/hero.cpp)

set(TEST_FILES test/character_test.cpp test/enemy_test.cpp test/hero_test.cpp)
add_executable(test ${TEST_FILES} ${SOURCE_FILES})

include_directories(${PROJECT_SOURCE_DIR}/character_class)
include_directories(${PROJECT_SOURCE_DIR}/enemy_class)
include_directories(${PROJECT_SOURCE_DIR}/hero_class)
target_link_libraries(test gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
