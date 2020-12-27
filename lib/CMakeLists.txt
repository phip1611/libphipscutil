set(CMAKE_C_STANDARD 11)


# all header files in "inc" var
set(inc
        # I don't know why but here "lib" prefix (absolute project path)
        # is not required
        ${library_include_dir}/phipscutil.h
        ${library_include_dir}/vec/vec.h
)

# all source files in "src" var
set(src
        # here the absolute project path is required
        lib/vec/vec.c
)

add_library(${libname} SHARED
        ${inc}
        ${src}
)

# TODO Versioning of installed target
# set(include_dest "include/${libname}-${CMAKE_PROJECT_VERSION}")
# set(main_lib_dest "lib/${libname}-${CMAKE_PROJECT_VERSION}")
set(include_dest "include/${libname}")
#set(main_lib_dest "lib/${libname}")
# shared object/dynlib must be directly under "lib/"
set(main_lib_dest "lib/")
# message(STATUS ${include_dest})
# message(STATUS ${main_lib_dest})

# install() will create cmake/makefile code that
# allows using "make install" and triggering an action.

# if DESTINATION path is relative then
# ${CMAKE_INSTALL_PREFIX} will be appended as prefix.
# It's /usr/local on UNIX
install(TARGETS ${libname}
        DESTINATION "${main_lib_dest}"
)

# install directory keeps the file structure (<phipscutil/*>
# trailing "/" seems to be important
install(DIRECTORY "${library_include_dir}/" DESTINATION "${include_dest}")

target_include_directories(${libname} PUBLIC ${library_include_dir})
