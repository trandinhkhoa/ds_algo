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

target_include_directories(${PROJECT_NAME}
                              PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Sort")
set (libSort_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/Sort/bubbleSort.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sort/quickSort.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sort/mergeSort.cpp)
add_library(libSort SHARED ${libSort_SOURCE})
target_link_libraries(${PROJECT_NAME} libSort)

# target_include_directories(${PROJECT_NAME}
#                               PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/cracking/arraysAndStrings")
set (libCrackingArrayAndStrings_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/arraysAndStrings/isUnique.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/arraysAndStrings/checkPermutation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/arraysAndStrings/urlify.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/arraysAndStrings/palindromePermutation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/arraysAndStrings/oneAway.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/arraysAndStrings/stringCompression.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/arraysAndStrings/rotateMatrix.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/arraysAndStrings/zeroMatrix.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/arraysAndStrings/stringRotation.cpp)
set (libCrackingLinkedLists_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/linkedLists/removeDups.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/linkedLists/returnKthToLast.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/linkedLists/deleteMiddleNode.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/linkedLists/partition.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/linkedLists/sumLists.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/linkedLists/palindrome.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/linkedLists/intersection.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/linkedLists/loopDetection.cpp)
set (libCrackingStacksAndQueues_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/stacksAndQueues/stackMin.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/stacksAndQueues/stackOfPlates.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/stacksAndQueues/queueViaStacks.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/stacksAndQueues/sortStack.cpp)
set (libCrackingTreesAndGraphs_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/treesAndGraphs/routeBetweenNodes.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/treesAndGraphs/minimalTree.cpp)
set (libCrackingCAndCpp_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/cAndCpp/lastKlines.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/cAndCpp/reverseString.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cracking/cAndCpp/copyNode.cpp)

add_library(libCrackingArrayAndStrings SHARED ${libCrackingArrayAndStrings_SOURCE})

add_library(libCrackingLinkedLists SHARED ${libCrackingLinkedLists_SOURCE})
target_include_directories(libCrackingLinkedLists
                              PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/dataStructures")

add_library(libCrackingStacksAndQueues SHARED ${libCrackingStacksAndQueues_SOURCE})

add_library(libCrackingTreesAndGraphs SHARED ${libCrackingTreesAndGraphs_SOURCE})

add_library(libCrackingCAndCpp SHARED ${libCrackingCAndCpp_SOURCE})
target_link_libraries(${PROJECT_NAME} libCrackingArrayAndStrings libCrackingLinkedLists libCrackingCAndCpp libCrackingStacksAndQueues libCrackingTreesAndGraphs)

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