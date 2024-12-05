cmake_minimum_required(VERSION 3.27)
project(11)

set(CMAKE_CXX_STANDARD 20)

add_executable(11 main.cpp
        fiber.cpp
        scheduler.h
        context.h
        scheduler.cpp
        context.cpp)
