cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

# set the project name
project(HelloWorld)

# add the executable
add_executable(${PROJECT_NAME} helloWorld.cpp)

# # PUBLIC ./Add also works
target_include_directories(${PROJECT_NAME}
                              PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Adder")

add_library(libAdder SHARED ${CMAKE_CURRENT_SOURCE_DIR}/Adder/Adder.cpp)

target_link_libraries(${PROJECT_NAME} libAdder)