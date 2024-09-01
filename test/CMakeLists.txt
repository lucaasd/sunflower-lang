cmake_minimum_required(VERSION 3.10)

project(SunflowerCompilerTest)

file(GLOB_RECURSE LEXER_TEST_SOURCES ${CMAKE_SOURCE_DIR}/test/Lexer/*.cpp)
file(GLOB_RECURSE PARSER_TEST_SOURCES ${CMAKE_SOURCE_DIR}/test/Parser/*.cpp)
file(GLOB_RECURSE LEXER_SOURCES ${CMAKE_SOURCE_DIR}/src/Compiler/Lexer/*.cpp)
file(GLOB_RECURSE PARSER_SOURCES ${CMAKE_SOURCE_DIR}/src/Compiler/Parser/*.cpp)

# Add googletest

add_subdirectory(${CMAKE_SOURCE_DIR}/googletest build/googletest)

# Lexer tests


add_library(Lexer STATIC ${LEXER_SOURCES})

target_include_directories(Lexer PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(SunflowerLexerTest ${LEXER_TEST_SOURCES})

target_include_directories(SunflowerLexerTest PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(SunflowerLexerTest PUBLIC gtest gtest_main Lexer)

add_test(NAME LexerTest COMMAND SunflowerLexerTest)

# Parser tests


add_library(Parser STATIC ${PARSER_SOURCES})

target_include_directories(Parser PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(SunflowerParserTest ${PARSER_TEST_SOURCES})

target_include_directories(SunflowerParserTest PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(SunflowerParserTest PUBLIC gtest gtest_main Parser Lexer)

add_test(NAME ParserTest COMMAND SunflowerParserTest)