
cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

project (loserCE)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#To ease the way of working with vscode
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


####################### Integrate gtest and coverage ###########################
find_package(GTest REQUIRED)
include(CheckIncludeFileCXX)
include(CTest)
enable_testing()

function(add_gtest)
    set(options DISABLE)
    set(oneValueArgs TARGET)
    set(multiValueArgs LIBRARY FILES)
    cmake_parse_arguments(ADD_GTEST "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

    if ( NOT ADD_GTEST_DISABLE)
        add_executable(${ADD_GTEST_TARGET} ${ADD_GTEST_FILES})
        target_link_libraries( ${ADD_GTEST_TARGET} ${ADD_GTEST_LIBRARY})

        set_target_properties(${ADD_GTEST_TARGET} PROPERTIES LINK_FLAGS "--coverage")
        set_target_properties(${ADD_GTEST_TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
        target_link_libraries(${ADD_GTEST_TARGET} GTest::gtest GTest::gtest_main Threads::Threads)
        gtest_discover_tests(${ADD_GTEST_TARGET})
    else ()
        message(WARNING, "UNIT TEST \"${ADD_GTEST_TARGET}\" DISABLED")
    endif()
endfunction()

add_custom_target (cov 
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/coverage
    COMMAND gcovr -r ../ --html-details ./coverage/cov.html  --html-details-syntax-highlightin -e '.*_test.cpp' .
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)



############# doxygen/sphinx integration: helper function  ##################
option(BUILD_DOC "Build documentation" ON) # todo

set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doc/doxygen)
set(DOXYGEN_INDEX_FILE ${DOXYGEN_OUTPUT_DIR}/html/index.html)
set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile)

find_package(Doxygen REQUIRED)
SET(DOXYGEN_HEADER_FILES  CACHE INTERNAL "doxygen header file list")
function(add_libraries_to_doxygen)
    set(options)
    set(oneValueArgs TARGET)
    set(multiValueArgs)
    cmake_parse_arguments(ADD_LIBRARIES_TO_DOXYGEN "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

    message("**********ADD_LIBRARIES_TO_DOXYGEN_TARGET ${ADD_LIBRARIES_TO_DOXYGEN_TARGET}")
    get_target_property(PUBLIC_HEADER_DIR ${ADD_LIBRARIES_TO_DOXYGEN_TARGET} INTERFACE_INCLUDE_DIRECTORIES)
    message("**********PUBLIC_HEADER_DIR ${PUBLIC_HEADER_DIR}")
    file(GLOB_RECURSE PUBLIC_HEADER ${PUBLIC_HEADER_DIR}/*.h)  
    
    SET(DOXYGEN_HEADER_FILES  ${DOXYGEN_HEADER_FILES} ${PUBLIC_HEADER} CACHE INTERNAL "doxygen header file list")
endfunction()

# only needed for sphinx yet 
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(DOXYGEN_GENERATE_XML YES)

add_subdirectory(doc)
###################### build the software ##########################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-sign-compare -Wwrite-strings -Wno-unused -fsanitize=leak")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# build executable 
add_executable(loserCE loserCE/src/loserCE.cpp)
target_link_libraries(loserCE engine)
target_link_libraries(loserCE interfaces)

# location of "global" header files  @TODO
include_directories(
    ${PROJECT_BINARY_DIR}
    loserCE/inc
    )
    
# add folders to diferent libraries
add_subdirectory(engine)
add_subdirectory(interfaces)
add_subdirectory(log)



############# doxygen integration: main target ##################
message("################## ${DOXYGEN_HEADER_FILES}")



find_package(Doxygen)
if (DOXYGEN_FOUND)

    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_MAN NO)

    doxygen_add_docs(
        Doxygen
        ${DOXYGEN_HEADER_FILES}
        COMMENT "Generate man pages"
        ) 
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

########################### CPACK ###############################

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)