cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

find_program(CLANG_PATH clang)
find_program(CLANG_CPP_PATH clang++)

if(NOT CLANG_PATH OR NOT CLANG_CPP_PATH)
    message(FATAL_ERROR "Clang or Clang++ not found")
else()
    message(STATUS "Clang found in ${CLANG_PATH}")
    message(STATUS "Clang++ found in ${CLANG_CPP_PATH}")
endif()

set(CMAKE_C_COMPILER ${CLANG_PATH})
set(CMAKE_CXX_COMPILER ${CLANG_CPP_PATH})
set(CMAKE_CXX_FLAGS_DEBUG "-g")

project(Sunflower)

include_directories(${CMAKE_SOURCE_DIR}/magic-enum/include)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
