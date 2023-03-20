cmake_minimum_required(VERSION 3.20)
project(tinyWebServerInit)
include(cmake/CPM.cmake)
set(CMAKE_CXX_STANDARD 14)
CPMAddPackage(
        NAME jsoncpp
        URL https://github.com/open-source-parsers/jsoncpp/archive/1.9.4.tar.gz)

CPMAddPackage(NAME hiredis
        URL https://github.com/redis/hiredis/archive/refs/tags/v1.1.0.tar.gz)

CPMAddPackage(NAME redis_cli
        URL https://github.com/sewenew/redis-plus-plus/archive/refs/tags/1.3.7.tar.gz)

target_link_libraries(${PROJECT_NAME} hiredis)
find_path(HIREDIS_HEADER hiredis)
target_include_directories(target PUBLIC ${HIREDIS_HEADER})

add_executable(tinyWebServerInit main.cpp threadpool/thread_pool.h threadpool/thread_pool.cpp)

target_link_libraries(${PROJECT_NAME} jsoncpp_lib)
target_link_libraries(${PROJECT_NAME} redis_cli_lib)
