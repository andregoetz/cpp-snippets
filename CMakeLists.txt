cmake_minimum_required(VERSION 3.15)
project(Probeklausur VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads REQUIRED)
link_libraries (${CMAKE_THREAD_LIBS_INIT})

add_executable(hello src/hello.cpp)
add_executable(constructors src/constructors/main.cpp src/constructors/constructors.cpp)
add_executable(operators src/operators/main.cpp src/operators/roman.cpp)
add_executable(data_types src/data_types/main.cpp)
add_executable(template_meta src/template/template_meta.cpp)
add_executable(template_types src/template/template_types.cpp)
add_executable(template_example src/template/template_example.cpp)
add_executable(simple_threads src/threads/simple_threads.cpp)
add_executable(threads_mutex_guard_etc src/threads/threads_mutex_guard_etc.cpp)
