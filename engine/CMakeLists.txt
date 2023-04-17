# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (engine 
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
	${CMAKE_CURRENT_SOURCE_DIR}/inc/engine.h
	
)
	
target_include_directories (engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# unit test executable
add_gtest(
	TARGET engine_unit_tests 
	LIBRARY engine 
	FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/emplacement_test.cpp
	      ${CMAKE_CURRENT_SOURCE_DIR}/test/chessmanPawn_test.cpp
)
