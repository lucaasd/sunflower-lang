cmake_minimum_required(VERSION 3.10)

project(SunflowerCompilerTest)

file(GLOB_RECURSE LEXER_TEST_SOURCES ${CMAKE_SOURCE_DIR}/test/Lexer/*.cpp)
file(GLOB_RECURSE COMPILER_SOURCES ${CMAKE_SOURCE_DIR}/src/Compiler/*.cpp)

add_subdirectory(${CMAKE_SOURCE_DIR}/googletest build/googletest)

add_library(Lexer STATIC ${COMPILER_SOURCES})

target_include_directories(Lexer PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(SunflowerLexerTest ${LEXER_TEST_SOURCES})

target_include_directories(SunflowerLexerTest PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(SunflowerLexerTest PUBLIC gtest gtest_main Lexer)
