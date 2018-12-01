cmake_minimum_required(VERSION 3.12)
project(malloc_library)

set(CMAKE_CXX_STANDARD 14)

add_executable(malloc_library main.c TreeNode.c TreeNode.h Driver.c Driver.h)