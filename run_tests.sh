#!/bin/bash

# Script to build and run unit tests using CppUTest

set -e

# Change to project root directory
cd "$(dirname "$0")"

echo "Building and running unit tests..."

# Create tests build directory
mkdir -p tests/build

# Build tests
echo "Configuring tests..."
cd tests/build
cmake ..

echo "Building tests..."
make

echo "Running tests..."
./unit_tests/unit_tests

echo "Tests completed!"