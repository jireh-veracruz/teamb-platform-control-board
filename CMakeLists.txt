cmake_minimum_required(VERSION 3.13)
project(teamb_platform_control_board)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Option to build tests
option(BUILD_TESTS "Build unit tests" OFF)

# Add subdirectories
add_subdirectory(${CMAKE_SOURCE_DIR}/APP)
add_subdirectory(${CMAKE_SOURCE_DIR}/BSP)
add_subdirectory(${CMAKE_SOURCE_DIR}/CUSTOM)
add_subdirectory(${CMAKE_SOURCE_DIR}/UTIL_DRVR)

# Add tests if requested
if(BUILD_TESTS)
    add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
endif()