cmake_minimum_required(VERSION 3.26)
project(Buddy_Heap_Memory C)

set(CMAKE_C_STANDARD 11)

add_executable(Buddy_Heap_Memory buddy_heap.c buddy_heap.h buddy_heap_test.c)
