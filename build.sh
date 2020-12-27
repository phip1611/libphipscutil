#!/usr/bin/env bash

# fail fast if build or tests fail!

set -e

cmake CMakeLists.txt -B build
cd build
make

cd tests/
# run all tests
# works at least on mac and linux
echo "Executing all tests in build/tests:"

# much shorter than previous version below
# "{}" is the placeholder for each file
# find will display each file with local dir prefix,
# i.e. "./vec_test". "+" is marker for exec end
find . -type f -executable -exec sh -c {} +

#ls -1 |                `# all files in test dir line by line`\
#  xargs file |         `# get filettype` \
#  grep -i executable | `# select executables` \
#  cut -d ':' -f1     | `# transform "vec_test: Mach-O 64-bit executable x86_64" into "vec_test"` \
#  awk '{print "./"$1}' | `# concatenate path with "./" prefix` \
#  awk '{print "exec "$1}' | `# concatenate to "exec <binary>"` \
#  xargs sh -c # execute in a new shell (exec will replace the shell process)
