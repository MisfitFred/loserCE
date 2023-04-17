add_library (template
	${CMAKE_CURRENT_SOURCE_DIR}/src/template.cpp    
	${CMAKE_CURRENT_SOURCE_DIR}/inc/template.h     
)
target_include_directories (template PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

#*********************************** UNIT TESTS ***************************************
# unit test executable: log
add_executable(template_test   ${CMAKE_CURRENT_SOURCE_DIR}/test/template_test.cpp )
set_target_properties(template_test PROPERTIES COMPILE_DEFINITIONS GTEST_LANG_CXX11)	
target_link_libraries(
    template_test
    GTest::gtest 
    GTest::gtest_main
    Threads::Threads
	template
)

add_gtest(template_test)
#--------------------------------------------------------------------------------------
