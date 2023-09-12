cmake_minimum_required(VERSION 3.18)

project("hello-tensors-dataframes")

set(CMAKE_CXX_STANDARD 20)

FIND_PACKAGE(Threads COMPONENTS REQUIRED)

include(FetchContent)

message(STATUS "Fetching NumCpp library...")
FetchContent_Declare(
    NumCpp
    GIT_REPOSITORY https://github.com/dpilger26/NumCpp.git
)
FetchContent_MakeAvailable(NumCpp)



message(STATUS "Adding sub project folders...")
add_subdirectory("src/hello-numcpp")