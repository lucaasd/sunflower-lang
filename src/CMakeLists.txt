cmake_minimum_required(VERSION 3.10)
project(sunflower)

file(GLOB_RECURSE SOURCES ./*.cpp)

add_executable(Sunflower ${SOURCES})

target_include_directories(Sunflower PUBLIC ${CMAKE_SOURCE_DIR}/include)