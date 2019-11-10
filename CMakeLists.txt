cmake_minimum_required(VERSION 2.8)

# Project name
project(DinoTracks)

# Allow using CMake find modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Find SFML
find_package(SFML COMPONENTS graphics window system audio network)
if(NOT SFML_FOUND)
    message(FATAL_ERROR "Could not find SFML")
endif()

# Find other libraries (as needed)

# Add libraries
include_directories(${SFML_INCLUDE_DIR})
link_libraries(${SFML_LIBRARIES})

# Get our sources
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/logic)
include_directories(${PROJECT_SOURCE_DIR}/include/views)
include_directories(${PROJECT_SOURCE_DIR}/include/components)
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*cpp)
file(GLOB LOGIC_SRC ${PROJECT_SOURCE_DIR}/src/logic/*cpp)
file(GLOB VIEW_SRC ${PROJECT_SOURCE_DIR}/src/views/*cpp)
file(GLOB COMPONENTS_SRC ${PROJECT_SOURCE_DIR}/src/components/*cpp)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Set target
add_executable(${PROJECT_NAME} ${SRC} ${LOGIC_SRC} ${VIEW_SRC} ${COMPONENTS_SRC} src/components/Energy.cpp include/components/Energy.hpp src/components/Health.cpp include/components/Health.hpp)