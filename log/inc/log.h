#pragma once
#include <fstream>
#include <iostream>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <map>

namespace Log
{

    class LogStream;

    class Logger
    {
    public:
        enum LogLevel
        {
            DEBUG = 0,
            INFO = 1,
            WARNING = 2,
            ERROR = 3,
            FATAL = 4
        };

        Logger(void);
        Logger(std::ostream *stream);
        Logger(std::string filename);
        Logger(std::ostream &outfile, LogLevel loglevel);
        ~Logger(void);

        LogStream operator()(LogLevel cLogLevel);
        LogStream debug();
        LogStream info();
        LogStream warning();
        LogStream error();
        LogStream fatal();

        void setInstanceName(std::string cString);
        void setLogLevel(LogLevel cLogLevel);
        //@todo shift to private
        void log(std::string logMessage);
        void log(std::string logMessage, LogLevel level);
    protected:


    private:
        std::ostream *outStream = &std::cout;
        std::ofstream *fileStream = nullptr;
        /// @brief as prefix to each each log message
        std::string instanceName = "";
        /// @brief Current log level for this logger instance.
        LogLevel logLevel = INFO;
        std::mutex mtx;

        std::map<LogLevel, std::string> LogLevelMap{
            {DEBUG, "debug: "},
            {INFO, "info: "},
            {WARNING, "warning: "},
            {ERROR, "error: "},
            {FATAL, "fatal error: "}};

        friend LogStream;
    };

    class LogStream : public std::ostringstream
    {
    public:
        LogStream(Logger *cLogger, Logger::LogLevel cLogLevel);
        LogStream(const LogStream &cLogStream);
        ~LogStream(void);

    private:
        Logger *log;
        Logger::LogLevel logLevel = Logger::LogLevel::INFO;
    };
} // namespace Log