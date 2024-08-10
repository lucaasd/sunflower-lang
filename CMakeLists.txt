cmake_minimum_required(VERSION 3.10)

find_program(CLANG_PATH clang)
find_program(CLANG_CPP_PATH clang++)

if(NOT CLANG_PATH OR NOT CLANG_CPP_PATH)
    message(FATAL_ERROR "clang or clang++ not found")
else()
    message(STATUS "Clang found in ${CLANG_PATH}")
    message(STATUS "Clang++ found in ${CLANG_CPP_PATH}")
endif()

set(CMAKE_C_COMPILER ${CLANG_PATH})
set(CMAKE_CXX_COMPILER ${CLANG_CPP_PATH})

project(sunflower)

add_executable(Sunflower src/main.cpp)

add_custom_command(TARGET Sunflower
    POST_BUILD
    COMMAND ${CMAKE_C_COMPILER} -S -emit-llvm -o $<TARGET_FILE:Sunflower>.ll ${CMAKE_SOURCE_DIR}/src/main.cpp
    COMMENT "Generating LLVM IR"
)