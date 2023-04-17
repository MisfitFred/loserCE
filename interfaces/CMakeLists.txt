add_library (interfaces STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/src/uci.cpp    
	${CMAKE_CURRENT_SOURCE_DIR}/inc/uci.h     
	${CMAKE_CURRENT_SOURCE_DIR}/src/stdInOut.cpp    
	${CMAKE_CURRENT_SOURCE_DIR}/inc/stdInOut.h 
	${CMAKE_CURRENT_SOURCE_DIR}/inc/inOutInterface.h 
	${CMAKE_CURRENT_SOURCE_DIR}/inc/queueTs.h
)

target_link_libraries(interfaces log)

target_include_directories (interfaces PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

#*********************************** UNIT TESTS ***************************************
add_gtest(
	TARGET uci_unit_tests 
	LIBRARY interfaces 
	FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/uci_test.cpp
	DISABLE
)
#--------------------------------------------------------------------------------------
# unit test executable: protocollInterface
add_gtest(
	TARGET protocollInterface_unit_tests 
	LIBRARY interfaces 
	FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/protocollInterface_test.cpp
)
#--------------------------------------------------------------------------------------

# unit test executable: stdInOutInterface
add_gtest(
	TARGET stdInOutInterface_unit_tests 
	LIBRARY interfaces 
	FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/stdInOutInterface_test.cpp
)
#--------------------------------------------------------------------------------------	