cmake_minimum_required(VERSION 3.20)
project(systemc_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE "Release")

include(${CMAKE_CURRENT_LIST_DIR}/src/src.cmake)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/external/systemc)
add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} SystemC::systemc)
