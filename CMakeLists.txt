cmake_minimum_required(VERSION 3.6)
project(data_structures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    #list1/q2.c
    #list2/q1.c
    #list2/q2.c
    #list3/q1.c
    #list4/exAula.c
    #list5/list.c
    #list5/q1.c
    #list5/q2.c
        list5/q3.c)

add_executable(data_structures ${SOURCE_FILES})