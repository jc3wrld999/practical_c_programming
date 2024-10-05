cmake_minimum_required(VERSION 3.29)
project(LearningC)

set(CMAKE_CXX_STANDARD 20)

add_executable(1071 codeup/1070_1099/1071.c
        data_structure/stack/stack.c
        data_structure/stack/stack.h
        data_structure/linked_list/linked_list.c
        data_structure/linked_list/linked_list.h)
add_executable(1072 codeup/1070_1099/1072.c)
add_executable(1073 codeup/1070_1099/1073.c)


add_executable(cpp_basic_1 cpp/basics/Lib/lib.cpp cpp/basics/Lib/lib.h
        cpp/basics/Lib/main.cpp)
add_executable(arraylist data_structure/array_list/main.c
        data_structure/array_list/array_list.c)
add_executable(new_target python-list/callback.c)
