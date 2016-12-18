cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT_NAME uncle)

project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

set(CURSES_NEED_NCURSES TRUE)

find_package(Curses REQUIRED)

include_directories(src ${CURSES_INCLUDE_DIR})

add_executable(${PROJECT_NAME}
    src/main.cc
    src/uncle/buffer.cc
    src/uncle/buffer.h
    src/uncle/commands.h
    src/uncle/cursor.cc
    src/uncle/cursor.h
    src/uncle/input_handler.cc
)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
