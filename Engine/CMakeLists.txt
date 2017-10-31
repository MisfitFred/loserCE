# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (Engine 
	${CMAKE_CURRENT_SOURCE_DIR}/src/chessman.cpp   
	${CMAKE_CURRENT_SOURCE_DIR}/src/emplacement.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/chessMove.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/inc/chessmanClass.h  
	${CMAKE_CURRENT_SOURCE_DIR}/inc/emplacement.h
	${CMAKE_CURRENT_SOURCE_DIR}/inc/chessMove.h
)
	
target_include_directories (Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)