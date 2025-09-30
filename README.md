# Team B Platform Control Board
- Sample repository to demonstrate platform

## Building

To build the main project:
```bash
./build.sh
```

To build with tests enabled:
```bash
cmake -DBUILD_TESTS=ON -B build
cmake --build build
```

## Testing

This project includes unit testing using CppUTest framework.

### Quick Start
```bash
./run_tests.sh
```

### Manual Testing
```bash
cd tests/build
cmake ..
make
./unit_tests/unit_tests
```

For detailed testing documentation, see [TESTING.md](TESTING.md).

## Example Application

There is an example handshake application in `EXAMPLE_APP/lib_teamb_handshake/` that can be built and run:

```bash
cd EXAMPLE_APP/lib_teamb_handshake
./build_sample_app.sh
```

# Authors
<TBD>
