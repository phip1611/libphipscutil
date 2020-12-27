echo "Building project and installing lib + header files into /usr/local"
set -e

sh ./build.sh
cd build/ || exit 255
make install
