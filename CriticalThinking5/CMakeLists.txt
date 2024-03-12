cmake_minimum_required(VERSION 3.25)
project(CriticalThinking5)

set(CMAKE_CXX_STANDARD 23)

add_executable(CriticalThinking5 CSC450_CT5_append_reverse.cpp)

#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/CSC450_CT5_mod5.txt
#        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
