set(CMAKE_C_STANDARD 11)

add_executable(vec_example vec_example.c)
target_include_directories(vec_example PRIVATE ${library_include_dir})
# cmake will know here about the library "phipscutil"
target_link_libraries(vec_example ${libname})
