cmake_minimum_required(VERSION 3.20)
project(tinyWebServerInit)

set(CMAKE_CXX_STANDARD 14)

add_executable(tinyWebServerInit main.cpp threadpool/thread_pool.h threadpool/thread_pool.cpp threadpool/my_task.h threadpool/my_task.cpp)
