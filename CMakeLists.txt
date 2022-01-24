cmake_minimum_required(VERSION 3.15)
project(Probeklausur VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads REQUIRED)
link_libraries (${CMAKE_THREAD_LIBS_INIT})

add_executable(hello src/hello.cpp)
add_executable(constructors src/constructors/main.cpp src/constructors/constructors.cpp)
add_executable(operators src/operators/main.cpp src/operators/roman.cpp)
add_executable(data_types src/data_types/main.cpp)
