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

###################
# TEST
###################
# https://github.com/google/googletest/tree/main/googletest
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
# add_executable(example example.cpp)
target_link_libraries(${PROJECT_NAME} gtest_main)
# add_test(NAME example_test COMMAND example)

message(STATUS "HELLO WORLD: ${CMAKE_CURRENT_SOURCE_DIR}")