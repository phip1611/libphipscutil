# this test is .cpp because C doesn't have binary integer literals (0b..)
add_executable(cpp_vec_test cpp_vec_test.cpp)
target_include_directories(cpp_vec_test PRIVATE ${library_include_dir})
# cmake will know here about the library "phipscutil"
target_link_libraries(cpp_vec_test ${libname})

###########################
add_executable(c_vec_test c_vec_test.c)
target_include_directories(c_vec_test PRIVATE ${library_include_dir})
# cmake will know here about the library "phipscutil"
target_link_libraries(c_vec_test ${libname})
