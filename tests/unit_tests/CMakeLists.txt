# Unit test executable configuration

# Create mock implementations
set(MOCK_SOURCES
    mocks/mock_hal_comms.c
    mocks/mock_common.c
)

# Source files to test (excluding main.c files and placeholder files)
set(TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/../UTIL_DRVR/lib_teamb_handshake/handshake.c
)

# Test files
set(TEST_FILES
    AllTests.cpp
    UTIL_DRVR/HandshakeTest.cpp
    UTIL_DRVR/HandshakeAdvancedTest.cpp
)

# Create test executable
add_executable(unit_tests 
    ${TEST_FILES}
    ${TEST_SOURCES}
    ${MOCK_SOURCES}
)

# Link with CppUTest libraries
target_link_libraries(unit_tests 
    ${CPPUTEST_LIBRARIES} 
    ${CPPUTEST_EXT_LIBRARIES}
)

# Add compiler flags for warnings
target_compile_options(unit_tests PRIVATE -Wall -Wextra -g)

# Define compilation flags for testing
target_compile_definitions(unit_tests PRIVATE -DUNIT_TESTING)