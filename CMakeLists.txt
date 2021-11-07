cmake_minimum_required(VERSION "3.21.4")

#Project Name
project("ebones")

#Getting every file from source
file(GLOB ebones_SRC CMAKE_CONFIGURE_DEPENDS "./src/include/*.h" "./src/*.cpp")

#Setting program to C++20
set(CMAKE_CXX_STANDARD 20)

#Adding executable
add_executable("${PROJECT_NAME}" "${ebones_SRC}")
