cmake_minimum_required(VERSION 3.22)
project(LR6)


add_library(String STATIC Task.cpp)

add_executable(AddressSan Task_Asan.cpp)
target_compile_options(AddressSan PRIVATE -fsanitize=address)
target_link_options(AddressSan PRIVATE -fsanitize=address)



add_executable(ThreadSan Task_Tsan.cpp)
target_compile_options(ThreadSan PRIVATE -fsanitize=thread)
target_link_options(ThreadSan PRIVATE -fsanitize=thread)

enable_testing()