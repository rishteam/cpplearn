cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(my_list)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC include/
)