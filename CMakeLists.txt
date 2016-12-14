cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT_NAME unclde)

project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

set(CURSES_NEED_NCURSES TRUE)

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

set(SOURCE_FILES
	src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
