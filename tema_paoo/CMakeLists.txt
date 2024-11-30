cmake_minimum_required(VERSION 3.0)

project(app_project)

add_executable(myapp main.cpp)

find_package(Threads REQUIRED)

target_link_libraries(myapp Threads::Threads)