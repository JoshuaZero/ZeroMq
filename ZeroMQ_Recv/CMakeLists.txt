cmake_minimum_required(VERSION 3.12)
project(ZeroMQ_Recv)

set(CMAKE_CXX_STANDARD 14)

add_executable(ZeroMQ_Recv main.cpp)

target_link_libraries(
        ZeroMQ_Recv

        zmq
)