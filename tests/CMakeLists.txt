cmake_minimum_required(VERSION 3.13)
project(teamb_tests)

# Set C and C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

# Set CppUTest path
set(CPPUTEST_ROOT ${CMAKE_SOURCE_DIR}/../cpputest)
set(CPPUTEST_INCLUDE_DIRS ${CPPUTEST_ROOT}/include)
set(CPPUTEST_LIBRARIES ${CPPUTEST_ROOT}/build/src/CppUTest/libCppUTest.a)
set(CPPUTEST_EXT_LIBRARIES ${CPPUTEST_ROOT}/build/src/CppUTestExt/libCppUTestExt.a)

# Include CppUTest headers
include_directories(${CPPUTEST_INCLUDE_DIRS})

# Include project headers
include_directories(
    ${CMAKE_SOURCE_DIR}/../UTIL_DRVR/lib_teamb_handshake
    ${CMAKE_SOURCE_DIR}/../UTIL_DRVR/common
    ${CMAKE_SOURCE_DIR}/../APP/projects/connectivity/hal
    ${CMAKE_SOURCE_DIR}/../CUSTOM/log_service
    ${CMAKE_SOURCE_DIR}/unit_tests/mocks
)

# Add subdirectories
add_subdirectory(unit_tests)