cmake_minimum_required(VERSION 3.16)
project(smart_pointer)

set(CMAKE_CXX_STANDARD 17)

add_executable(smart_pointer main.cpp)

find_package(fmt REQUIRED)
target_link_libraries(smart_pointer fmt::fmt)