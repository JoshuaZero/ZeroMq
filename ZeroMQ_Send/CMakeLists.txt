cmake_minimum_required(VERSION 3.12)
project(ZeroMQ_Send)

set(CMAKE_CXX_STANDARD 14)

add_executable(ZeroMQ_Send main.cpp)

target_link_libraries(
        ZeroMQ_Send

        zmq
)