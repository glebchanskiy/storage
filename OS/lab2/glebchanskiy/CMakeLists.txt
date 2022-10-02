cmake_minimum_required(VERSION 2.8...3.22)

project(run_program)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall")
set(SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

aux_source_directory(${SOURCES_DIR} SOURCES)

include_directories(${SOURCES_DIR})

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
