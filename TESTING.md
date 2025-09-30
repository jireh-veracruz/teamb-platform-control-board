# Unit Testing with CppUTest

This repository includes unit testing capabilities using CppUTest framework. This document explains how to build, run, and extend the tests.

## Prerequisites

- CMake 3.13 or later
- GCC compiler
- Git (for cloning CppUTest)

## Quick Start

To build and run all tests:

```bash
./run_tests.sh
```

This script will:
1. Clone and build CppUTest (if not already done)
2. Configure the test build using CMake
3. Build all test executables
4. Run the tests and display results

## Manual Testing Process

If you prefer to run tests manually:

```bash
# Create and enter test build directory
mkdir -p tests/build
cd tests/build

# Configure with CMake
cmake ..

# Build tests
make

# Run tests
./unit_tests/unit_tests
```

## Directory Structure

```
tests/
├── CMakeLists.txt              # Main test configuration
├── unit_tests/
│   ├── CMakeLists.txt          # Test executable configuration
│   ├── AllTests.cpp            # Main test runner
│   ├── UTIL_DRVR/
│   │   └── HandshakeTest.cpp   # Tests for handshake module
│   └── mocks/
│       ├── mock_hal_comms.c    # Mock implementations for HAL
│       ├── mock_hal_comms.h    # Mock control functions
│       └── mock_common.c       # Mock implementations for common
└── build/                      # Generated build files (ignored by git)
```

## Adding New Tests

### 1. Create a new test file

Create a new `.cpp` file in the appropriate subdirectory under `tests/unit_tests/`. For example:

```cpp
// tests/unit_tests/NEW_MODULE/NewModuleTest.cpp
#include "CppUTest/TestHarness.h"

extern "C" {
    #include "new_module.h"
}

TEST_GROUP(NewModuleTestGroup)
{
    void setup()
    {
        // Setup before each test
    }

    void teardown()
    {
        // Cleanup after each test
    }
};

TEST(NewModuleTestGroup, TestSomething)
{
    // Your test code here
    CHECK_EQUAL(expected_value, actual_value);
}
```

### 2. Update CMakeLists.txt

Add your test file to the `TEST_FILES` list in `tests/unit_tests/CMakeLists.txt`:

```cmake
set(TEST_FILES
    AllTests.cpp
    UTIL_DRVR/HandshakeTest.cpp
    NEW_MODULE/NewModuleTest.cpp  # Add your test file here
)
```

If you're testing a new source module, also add it to `TEST_SOURCES`:

```cmake
set(TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/../UTIL_DRVR/lib_teamb_handshake/handshake.c
    ${CMAKE_SOURCE_DIR}/../NEW_MODULE/new_module.c  # Add source file here
)
```

### 3. Create mocks if needed

If your module depends on external functions, create mock implementations:

```c
// tests/unit_tests/mocks/mock_new_dependency.c
#include "new_dependency.h"

// Mock implementations
int mock_function(void)
{
    return 42; // Mock return value
}
```

## CppUTest Features Used

### Basic Assertions
- `CHECK(condition)` - Check boolean condition
- `CHECK_EQUAL(expected, actual)` - Check equality
- `CHECK_TRUE(condition)` - Check true condition
- `CHECK_FALSE(condition)` - Check false condition

### String Assertions
- `STRCMP_EQUAL(expected, actual)` - Compare strings
- `STRNCMP_EQUAL(expected, actual, length)` - Compare strings with length

### Numeric Assertions
- `DOUBLES_EQUAL(expected, actual, tolerance)` - Compare floating point numbers
- `LONGS_EQUAL(expected, actual)` - Compare long integers

### Test Groups
Test groups allow you to organize related tests and provide common setup/teardown:

```cpp
TEST_GROUP(MyTestGroup)
{
    void setup()
    {
        // Called before each test in this group
    }

    void teardown()
    {
        // Called after each test in this group
    }
};
```

### Mocking Strategy

This project uses simple function replacement mocking:
1. Create mock implementations that replace the real functions
2. Use global variables to control mock behavior
3. Provide control functions to set up mock state and verify calls

Example mock control functions:
```c
void mock_hal_set_device_ready(int ready);  // Set up mock state
char* mock_hal_get_sent_data(void);         // Verify mock was called
void mock_hal_reset(void);                  // Reset mock state
```

## Running Specific Tests

You can run specific tests by using CppUTest's filtering options:

```bash
# Run only tests from a specific group
./unit_tests/unit_tests -g HandshakeTestGroup

# Run only a specific test
./unit_tests/unit_tests -n InitHandshakeDoesNotCrash

# Run tests with verbose output
./unit_tests/unit_tests -v
```

## Integration with Main Build

The main project CMakeLists.txt includes an option to build tests:

```bash
# Build project with tests
cmake -DBUILD_TESTS=ON -B build
cmake --build build

# Run tests from main build
./build/tests/unit_tests/unit_tests
```

## Troubleshooting

### Common Issues

1. **Missing CppUTest**: Ensure CppUTest is cloned and built in the `cpputest/` directory
2. **Linker errors**: Check that all required source files are listed in `TEST_SOURCES`
3. **Include errors**: Verify that header paths are correct in the CMakeLists.txt files
4. **Mock conflicts**: Ensure mock functions have the same signatures as the real functions

### Debugging Tests

Use GDB to debug failing tests:

```bash
cd tests/build
gdb ./unit_tests/unit_tests
(gdb) run
(gdb) bt  # Show backtrace when test fails
```

## Best Practices

1. **Keep tests focused**: Each test should verify one specific behavior
2. **Use descriptive names**: Test names should clearly describe what is being tested
3. **Reset state**: Always reset mock state in setup() or teardown()
4. **Test edge cases**: Include tests for boundary conditions and error cases
5. **Mock external dependencies**: Isolate the code under test from external systems
6. **Keep tests fast**: Unit tests should run quickly for rapid feedback

## Contributing

When adding new functionality:
1. Write tests for new code before implementing it (TDD approach)
2. Ensure all existing tests pass
3. Add appropriate documentation for new test utilities
4. Follow the existing test structure and naming conventions