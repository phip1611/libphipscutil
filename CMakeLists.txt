cmake_minimum_required(VERSION 3.0)
project("phipscutil - Phips C utility library"
        VERSION 0.0.1
        DESCRIPTION "Utility library for C projects. I did this project mainly for fun and educational reasons."
        HOMEPAGE_URL "https://github.com/phip1611/libphipscutil"
)

# this repository consists of multiple targets
# we want latest C/C++ for all of them
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")

# set(libname libphipscutil)
# "lib" prefix is added automatically during buildtime!
# The library will be available via "#include <phipscutil-0.0.1/phipscutil.h>"
# for example!
set(libname "phipscutil-${CMAKE_PROJECT_VERSION}")
set(library_include_dir ${PROJECT_SOURCE_DIR}/lib/inc)

add_subdirectory(benches)
add_subdirectory(examples)
add_subdirectory(lib)
add_subdirectory(tests)
