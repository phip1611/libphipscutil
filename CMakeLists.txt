cmake_minimum_required(VERSION 3.0)
project("phipscutil - Phips C utility library"
        VERSION 0.0.1
        DESCRIPTION "Utility library for C projects. I did this project mainly for fun and educational reasons."
        HOMEPAGE_URL "https://github.com/phip1611/libphipscutil"
)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -Werror -Wno-gnu-binary-literal")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")

# set(libname libphipscutil)
# "lib" prefix is added automatically during buildtime!
set(libname phipscutil)
set(library_include_dir ${PROJECT_SOURCE_DIR}/lib/inc)

add_subdirectory(benches)
add_subdirectory(examples)
add_subdirectory(lib)
add_subdirectory(tests)
