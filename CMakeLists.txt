cmake_minimum_required(VERSION 3.0)
project(Lisp)
#set(CMAKE_CXX_COMPILE clang++)
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_C_STANDARD 11)
include_directories(${CMAKE_SOURCE_DIR}/src/ ${CMAKE_SOURCE_DIR}/include/)

FIND_PACKAGE(BISON REQUIRED)
SET(BisonOutput ${CMAKE_SOURCE_DIR}/src/parser.cc)
IF(BISON_FOUND)
    ADD_CUSTOM_COMMAND(
      OUTPUT ${BisonOutput}
      COMMAND ${BISON_EXECUTABLE}
              --defines=${CMAKE_SOURCE_DIR}/src/tokens.h
              --output=${BisonOutput}
              ${CMAKE_SOURCE_DIR}/src/parser.y
      COMMENT "Generating parser.cc"
    )
ENDIF()

FIND_PACKAGE(FLEX REQUIRED)
SET(FlexOutput ${CMAKE_SOURCE_DIR}/src/scanner.cc)
IF(FLEX_FOUND)
    ADD_CUSTOM_COMMAND(
      OUTPUT ${FlexOutput}
      COMMAND ${FLEX_EXECUTABLE}
              --outfile=${FlexOutput}
              ${CMAKE_SOURCE_DIR}/src/scanner.l
      COMMENT "Generating scanner.c"
    )
ENDIF()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

set(JSON_SRC src/json.h src/json.cc ${FlexOutput} ${BisonOutput})
add_library(Json STATIC ${JSON_SRC})
add_executable(main main.cc)
target_link_libraries(main Json)

#gtest
set(GTEST_FILES tests/main-test.cc)
add_executable(main-test ${GTEST_FILES})
target_link_libraries(main-test ${CMAKE_SOURCE_DIR}/lib/libgtest.a)
find_package (Threads REQUIRED)
target_link_libraries(main-test Threads::Threads)
target_link_libraries(main-test Json)
