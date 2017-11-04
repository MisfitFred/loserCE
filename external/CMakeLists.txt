
###################################  google test  ###################################

# target to update git submodules
add_custom_target(
    update_googletest
    COMMAND git submodule init
    COMMAND git submodule update
	COMMAND git checkout release-1.8.0
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/googletest
    )


#set(GOOGLETEST_ROOT googletest/googletest CACHE STRING "Google Test source root")

# google test includes
# include_directories(
    # ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    # ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    # )

# google test sources
set(GOOGLETEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/src/gtest-all.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/src/gtest_main.cc
    )
	
# mark these files as generated (they may not be present at configure time)
foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})
target_include_directories(googletest PUBLIC   
	${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest
    ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include
)

# update git submodules before building google test
add_dependencies(googletest update_googletest)

######################################  pthread  ###################################		
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
#Workaround for VS2015 maybe trouble with GCC
set_target_properties(googletest PROPERTIES COMPILE_DEFINITIONS GTEST_LANG_CXX11)

set(listOfPthreadFiles ChangeLog
	COPYING.LIB
	FAQ
	NEWS
	PROGRESS
	README
	README.Borland
	README.CV
	README.Watcom
	sha512.sum
	lib/x64/libpthreadGC2.a
	lib/x64/md5.sum
	lib/x64/pthreadVC2.lib
	lib/x64/sha512.sum
	lib/x86/libpthreadGC2.a
	lib/x86/libpthreadGCE2.a
	lib/x86/md5.sum
	lib/x86/pthreadVC2.lib
	lib/x86/pthreadVSE2.lib
	lib/x86/sha512.sum
	include/md5.sum      
	include/pthread.h    
	include/sched.h      
	include/semaphore.h  
	include/sha512.sum
)

foreach(filenameWithPath IN ITEMS  ${listOfPthreadFiles})
	if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/pthread/${filenameWithPath})
		message(STATUS "file does not exists ${CMAKE_CURRENT_SOURCE_DIR}/pthread/${filenameWithPath}")
		file(DOWNLOAD "http://ftp-stud.fht-esslingen.de/pub/Mirrors/sourceware.org/pthreads-win32/prebuilt-dll-2-9-1-release/${filenameWithPath}" "${CMAKE_CURRENT_SOURCE_DIR}/pthread/${filenameWithPath}" SHOW_PROGRESS)
	endif()
endforeach()

add_library(pthread STATIC IMPORTED GLOBAL)
set_property(TARGET pthread PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/pthread/lib/x64/pthreadVC2.lib)
#target_include_directories(pthread PUBLIC  "${CMAKE_CURRENT_SOURCE_DIR}/pthread/include")
set_property(TARGET pthread APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/pthread/include)
endif()	

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	set(THREADS_PREFER_PTHREAD_FLAG ON)
	find_package(Threads REQUIRED)
endif()

