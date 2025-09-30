#!/bin/bash

# Clean previous build
rm -rf BUILD

TOOLCHAIN="BSP/stm32/toolchain_stm32.cmake"

# Configure with CMake using the selected toolchain
cmake -G Ninja -B BUILD \
  -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN \

# Build the project
cmake --build build
