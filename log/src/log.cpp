
#include "log.h"
#include <iomanip>

namespace Log
{

    Logger::Logger(void) {}
    Logger::Logger(std::ostream *stream)
    {
        this->outStream = stream;
    }

    Logger::Logger(std::string filename)
    {
        fileStream = new std::ofstream(filename, std::fstream::out | std::fstream::ate | std::fstream::app);
        outStream = fileStream;
    }

    Logger::~Logger()
    {
        outStream->flush();
        if (fileStream != nullptr)
        {
            fileStream->close();
        }
    }

    void Logger::log(std::string logMessage)
    {
        this->mtx.lock();
        *(this->outStream) << logMessage << std::endl;
        this->mtx.unlock();
    }

    void Logger::log(std::string logMessage, LogLevel level)
    {
        if (level >= this->logLevel)
        {
            log(this->instanceName + this->LogLevelMap[level] + logMessage);
        }
    }

    void Logger::setInstanceName(std::string cString)
    {
        this->instanceName = cString;
    }

    void Logger::setLogLevel(LogLevel cLogLevel)
    {
        logLevel = cLogLevel;
    }

    LogStream Logger::operator()(LogLevel cLogLevel)
    {
        return LogStream(this, cLogLevel);
    }

    LogStream Logger::debug()
    {
        return (*this)(LogLevel::DEBUG);
    }

    LogStream Logger::info()
    {
        return (*this)(LogLevel::INFO);
    }

        LogStream Logger::warning()
    {
        return (*this)(LogLevel::WARNING);
    }

        LogStream Logger::fatal()
    {
        return (*this)(LogLevel::FATAL);
    }

        LogStream Logger::error()
    {
        return (*this)(LogLevel::ERROR);
    }

    LogStream::LogStream(Logger *cLogger, Logger::LogLevel cLogLevel)
    {
        this->logLevel = cLogLevel;
        this->log = cLogger;
    }

    LogStream::~LogStream(void)
    {
        this->log->log(this->str(), this->logLevel);
    }

} // namespace Log
