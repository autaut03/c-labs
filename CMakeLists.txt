# cmake_minimum_required(VERSION <specify CMake version here>)
project(CLion)

cmake_minimum_required(VERSION 3.9)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)
set(CMAKE_C_STANDARD 99)

add_executable(main main.cpp)