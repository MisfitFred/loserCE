# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)
project (loserCE)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

# location of additional cmake modules
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake
    )

# some helper function to get a proper build. (Define release type, forbidden in source build)
include(safeguards)

message(STATUS "Processor type: ${CMAKE_HOST_SYSTEM_PROCESSOR}")

message(STATUS "Operating system: ${CMAKE_SYSTEM_NAME}")
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_definitions(-DSYSTEM_WINDOWS)
endif()
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_definitions(-DSYSTEM_LINUX)
endif()


if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -sdt=c++11 -Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused")
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()
message (STATUS "CompilerID = ${CMAKE_CXX_COMPILER_ID}")
if(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} /EHc /std:c++latest")
    #set(CMAKE_CXX_FLAGS_DEBUG   "")
    #set(CMAKE_CXX_FLAGS_RELEASE "")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

# build executable
add_executable(loserCE loserCE/src/loserCE.cpp)
target_link_libraries(loserCE Engine)


# location of header files
include_directories(
    ${PROJECT_BINARY_DIR}
    loserCE/inc
    )

# get git hash
include(git_revision)

# configure header file
configure_file(
    ${PROJECT_SOURCE_DIR}/cmake/config.h.in
    ${PROJECT_BINARY_DIR}/config.h
    )

#TODO
find_package(PythonInterp)
if(NOT PYTHONINTERP_FOUND)
    message(FATAL_ERROR "ERROR: Python interpreter not found. Cannot continue - sorry.")
endif()


# generate the file
# add_custom_target(
    # generate_file
    # COMMAND ${PYTHON_EXECUTABLE} ${PROJECT_SOURCE_DIR}/src/generate.py > ${PROJECT_BINARY_DIR}/mylib_generated.cpp
    # )

# mark the file as generated
# set_source_files_properties(${PROJECT_BINARY_DIR}/mylib_generated.cpp PROPERTIES GENERATED 1)

# static library
# add_library(mylib_static STATIC src/mylib.cpp ${PROJECT_BINARY_DIR}/mylib_generated.cpp)
# add_dependencies(mylib_static generate_file)

# shared library
# add_library(mylib_shared SHARED src/mylib.cpp)

# compile main executable
# add_executable(main.x src/main.cpp)

# link library
# target_link_libraries(main.x mylib_static)

# library that holds sources to test
# add_library(example src/example.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_subdirectory(Engine)
add_subdirectory(External)

# unit test executable
add_executable(
    unit_tests
    test/main.cpp
    test/emplacement_test.cpp
    )

# unit test executable depends on google test
add_dependencies(unit_tests googletest)



# link unit test executable against google test
target_link_libraries(
    unit_tests
    googletest
    Threads::Threads
	Engine
    )

set_target_properties(unit_tests
                      PROPERTIES COMPILE_DEFINITIONS GTEST_LANG_CXX11)
					  
# set cdash buildname
set(BUILDNAME
    "${CMAKE_SYSTEM_NAME}-${CMAKE_HOST_SYSTEM_PROCESSOR}-${CMAKE_CXX_COMPILER_ID}-${cmake_build_type_tolower}"
    CACHE STRING
    "Name of build on the dashboard"
    )

# activate ctest
include(CTest)
enable_testing()

# define a test
add_test(unit ${PROJECT_BINARY_DIR}/unit_tests)

# make install and cpack
include(install_target)


