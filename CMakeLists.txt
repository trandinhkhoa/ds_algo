cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

# set the project name
project(HelloWorld)

# add the executable
add_executable(${PROJECT_NAME} helloWorld.cpp ./Adder/Adder.cpp)