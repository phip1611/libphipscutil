set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_vec_vs_libphipscutil_vec_u64
        cpp_vec_vs_libphipscutil_vec_u64.cpp
)
target_include_directories(cpp_vec_vs_libphipscutil_vec_u64 PRIVATE ${library_include_dir})
target_link_libraries(cpp_vec_vs_libphipscutil_vec_u64 ${libname})

#############################################################

add_executable(cpp_vec_vs_libphipscutil_vec_u8
        cpp_vec_vs_libphipscutil_vec_u8.cpp
)
target_include_directories(cpp_vec_vs_libphipscutil_vec_u8 PRIVATE ${library_include_dir})
target_link_libraries(cpp_vec_vs_libphipscutil_vec_u8 ${libname})