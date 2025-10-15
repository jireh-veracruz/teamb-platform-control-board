
#!/bin/bash

rm -rf build

set -e

cd "$(dirname "$0")"

mkdir -p build
cd build

cmake ..
make

./handshake_app
