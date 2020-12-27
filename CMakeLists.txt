cmake_minimum_required(VERSION 3.0)
project("phipscutil - Phips C utility library"
        VERSION 0.0.1
        DESCRIPTION "Utility library for C projects. I did this project mainly for fun and educational reasons."
        HOMEPAGE_URL "https://github.com/phip1611/libphipscutil"
)

set(CMAKE_C_STANDARD 11)

add_library(phipscutil SHARED
        src/lib/phipscutil.h

        src/lib/vec.h
        src/lib/vec.c
)

##############################################################
add_executable(vec_example
    src/examples/vec_example.c
)
target_include_directories(vec_example PRIVATE
    src/lib
)
target_link_libraries(vec_example phipscutil)
##############################################################
add_executable(cpp_vec_vs_libphipscutil_vec_u64
        src/benches/cpp_vec_vs_libphipscutil_vec_u64.cpp
)
target_include_directories(cpp_vec_vs_libphipscutil_vec_u64 PRIVATE
        src/lib
)
target_link_libraries(cpp_vec_vs_libphipscutil_vec_u64 phipscutil)
##############################################################
add_executable(cpp_vec_vs_libphipscutil_vec_u8
        src/benches/cpp_vec_vs_libphipscutil_vec_u8.cpp
)
target_include_directories(cpp_vec_vs_libphipscutil_vec_u8 PRIVATE
        src/lib
)
target_link_libraries(cpp_vec_vs_libphipscutil_vec_u8 phipscutil)
##############################################################
add_executable(vec_test
        src/test/vec_test.c
)
target_include_directories(vec_test PRIVATE
        src/lib
)
target_link_libraries(vec_test phipscutil)
