project(HelloMathplotPlusPlus)


find_package(Threads COMPONENTS REQUIRED)
include_directories(${matplot_SOURCE_DIR}/source/)


set(CMAKE_CXX_STANDARD 20)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


add_executable(HelloMathplot main.cpp )
#target_link_libraries(HelloMathplot PUBLIC matplot)
target_link_libraries(HelloMathplot Matplot++::matplot)

