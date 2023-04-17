add_library (log
	${CMAKE_CURRENT_SOURCE_DIR}/src/log.cpp    
	${CMAKE_CURRENT_SOURCE_DIR}/inc/log.h     
)
target_include_directories (log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

#*********************************** UNIT TESTS ***************************************
# unit test executable: log
add_gtest(
	TARGET log_unit_tests
	LIBRARY log 
	FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/log_test.cpp
)
#--------------------------------------------------------------------------------------
