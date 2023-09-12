project(HelloNumCpp)


find_package(Threads COMPONENTS REQUIRED)
include_directories(${NumCpp_SOURCE_DIR}/include/)


set(CMAKE_CXX_STANDARD 20)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


add_executable(HelloNumCpp main.cpp )
target_link_libraries(HelloNumCpp NumCpp::NumCpp)

