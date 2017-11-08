# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (Engine 
	${CMAKE_CURRENT_SOURCE_DIR}/src/chessmanClass.cpp    
	${CMAKE_CURRENT_SOURCE_DIR}/src/emplacement.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/chessMove.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/inc/chessmanType.h  
	${CMAKE_CURRENT_SOURCE_DIR}/inc/chessmanClass.h  
	${CMAKE_CURRENT_SOURCE_DIR}/inc/emplacement.h
	${CMAKE_CURRENT_SOURCE_DIR}/inc/chessMove.h
	${CMAKE_CURRENT_SOURCE_DIR}/inc/chessmanSide.h
	${CMAKE_CURRENT_SOURCE_DIR}/inc/emplacementNode.h
	${CMAKE_CURRENT_SOURCE_DIR}/inc/emplacementTree.h
	${CMAKE_CURRENT_SOURCE_DIR}/inc/Engine.h
	
)
	
target_include_directories (Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# unit test executable
add_executable(
    Engine_unit_tests
    ${CMAKE_CURRENT_SOURCE_DIR}/test/emplacement_test.cpp
    )
set_target_properties(Engine_unit_tests PROPERTIES COMPILE_DEFINITIONS GTEST_LANG_CXX11)
	
add_dependencies(Engine_unit_tests gtest_main)

# link unit test executable against google test
# todo need to find a clean solution
if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
   target_link_libraries(
    Engine_unit_tests
    gtest_main
    pthread
	Engine
    )
endif()
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
target_link_libraries(
    Engine_unit_tests
    gtest_main
    Threads::Threads
	Engine
    )
endif()

# define a test
add_test(Engine_unit_tests ${PROJECT_BINARY_DIR}/Engine_unit_tests)
	