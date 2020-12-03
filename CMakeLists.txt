cmake_minimum_required(VERSION 3.17)
project("c_wambo - Phips C utility library")

set(CMAKE_C_STANDARD 11)

add_library(c_wambo SHARED
        src/lib/cwambo.h

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
target_link_libraries(vec_example c_wambo)
##############################################################
add_executable(cpp_vec_vs_cwambo_vec_u64
        src/benches/cpp_vec_vs_cwambo_vec_u64.cpp
)
target_include_directories(cpp_vec_vs_cwambo_vec_u64 PRIVATE
        src/lib
)
target_link_libraries(cpp_vec_vs_cwambo_vec_u64 c_wambo)
##############################################################
add_executable(cpp_vec_vs_cwambo_vec_u8
        src/benches/cpp_vec_vs_cwambo_vec_u8.cpp
)
target_include_directories(cpp_vec_vs_cwambo_vec_u8 PRIVATE
        src/lib
)
target_link_libraries(cpp_vec_vs_cwambo_vec_u8 c_wambo)
##############################################################
add_executable(vec_test
        src/test/vec_test.c
)
target_include_directories(vec_test PRIVATE
        src/lib
)
target_link_libraries(vec_test c_wambo)
