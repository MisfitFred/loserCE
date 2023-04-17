#include "log.h"

#include <thread>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::HasSubstr;
/**
 * Some short thoughts about how to test the logger.
 * 
 * Points of variation (based on typical use cases):
 * 
 * - outStream: (std::cout | file)
 * - LogLevel logLevel: (DEBUG | INFO | WARNING | ERROR | FATAL)
 * - Std:string InstanceName: ("" | "GTest")
 * 
 * Methods to be tested with given variation points:      
 *      LogStream debug();
 *      LogStream info();
 *      LogStream warning();
 *      LogStream error();
 *      LogStream fatal();
 *  
 * Test decision: divide and conquer, "no brute force test all combinations method":
 * 
 * 1. Check Log level behavior: 
 * 2. Check string instanceName with two tests
 * 3. Check file output based on one log level  @todo
*/


class loggerTest : public ::testing::Test
{
protected:
    Log::Logger *myLogger;
    virtual void SetUp() { myLogger = new Log::Logger(); }

    virtual void TearDown() { delete myLogger; }

};

TEST_F(loggerTest, simpleLogTestToCout)
{
    std::string testMessage = "Test My Logger 13";

    testing::internal::CaptureStdout();    
    myLogger->info() << testMessage;
    std::string reference = testing::internal::GetCapturedStdout();

	std::string expMessage = testMessage + "\n";
    EXPECT_THAT(reference, HasSubstr(expMessage));
    EXPECT_THAT(reference, HasSubstr("info"));
}

TEST_F(loggerTest, simpleLogTestToCout_HandOverCoutWithConstructor)
{
	delete myLogger;
	myLogger = new Log::Logger(&std::cout);

    std::string testMessage = "Test My Logger 12";

    testing::internal::CaptureStdout();    
    myLogger->info() << testMessage;
    std::string reference = testing::internal::GetCapturedStdout();

	std::string expMessage = testMessage + "\n";
    EXPECT_THAT(reference, HasSubstr(expMessage));
    EXPECT_THAT(reference, HasSubstr("info"));
}


TEST_F(loggerTest, logLevel_DEBUG_debug)
{
    // Test preparation 
	std::string testMessage = "Test My Logger 11";
    myLogger->setLogLevel(Log::Logger::DEBUG);

    // Test execution
    testing::internal::CaptureStdout();    
    myLogger->debug() << testMessage;
    std::string reference = testing::internal::GetCapturedStdout();

	std::string expMessage = testMessage + "\n";
    
    EXPECT_THAT(reference, HasSubstr(expMessage));
    EXPECT_THAT(reference, HasSubstr("debug"));
}

TEST_F(loggerTest, logLevel_DEBUG_info)
{
    // Test preparation 
	std::string testMessage = "Test My Logger 0";
    myLogger->setLogLevel(Log::Logger::DEBUG);

    // Test execution
    testing::internal::CaptureStdout();    
    myLogger->info() << testMessage;
    std::string reference = testing::internal::GetCapturedStdout();

	std::string expMessage = testMessage + "\n";
    
    EXPECT_THAT(reference, HasSubstr(expMessage));
    EXPECT_THAT(reference, HasSubstr("info"));
}


TEST_F(loggerTest, logLevel_DEBUG_fatal)
{
    // Test preparation 
	std::string testMessage = "Test My Logger 1";
    myLogger->setLogLevel(Log::Logger::DEBUG);

    // Test execution
    testing::internal::CaptureStdout();    
    myLogger->fatal() << testMessage;
    std::string reference = testing::internal::GetCapturedStdout();

	std::string expMessage = testMessage + "\n";
    
    EXPECT_THAT(reference, HasSubstr(expMessage));
    EXPECT_THAT(reference, HasSubstr("fatal"));
}

TEST_F(loggerTest, logLevel_FATAL_fatal)
{
    // Test preparation 
	std::string testMessage = "Test My Logger 2";
    myLogger->setLogLevel(Log::Logger::FATAL);

    // Test execution
    testing::internal::CaptureStdout();    
    myLogger->fatal() << testMessage;
    std::string reference = testing::internal::GetCapturedStdout();

	std::string expMessage = testMessage + "\n";
    
    EXPECT_THAT(reference, HasSubstr(expMessage));
    EXPECT_THAT(reference, HasSubstr("fatal"));
}

TEST_F(loggerTest, logLevel_FATAL_warning)
{
    // Test preparation 
	std::string testMessage = "Test My Logger 3";
    myLogger->setLogLevel(Log::Logger::FATAL);

    // Test execution
    testing::internal::CaptureStdout();    
    myLogger->warning() << testMessage;
    std::string reference = testing::internal::GetCapturedStdout();

	std::string expMessage ="";;
    
    EXPECT_EQ(reference, expMessage);
}

TEST_F(loggerTest, logLevel_FATAL_debug)
{
    // Test preparation 
	std::string testMessage = "Test My Logger 4";
    myLogger->setLogLevel(Log::Logger::FATAL);

    // Test execution
    testing::internal::CaptureStdout();    
    myLogger->debug() << testMessage;
    std::string reference = testing::internal::GetCapturedStdout();

	std::string expMessage ="";;
    
    EXPECT_EQ(reference, expMessage);
}

TEST_F(loggerTest, checkInstance)
{
    // Test preparation 
	std::string testMessage = "Test My Logger 4";
    myLogger->setLogLevel(Log::Logger::DEBUG);
    myLogger->setInstanceName("#TETETETE->");

    // Test execution
    testing::internal::CaptureStdout();    
    myLogger->debug() << testMessage;
    std::string reference = testing::internal::GetCapturedStdout();

	std::string expMessage ="";

    EXPECT_EQ(reference, "#TETETETE->debug: Test My Logger 4\n");
}