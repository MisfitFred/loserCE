#include <exception>
#include <array>
#include <thread>
#include <iostream>
#include <sstream>
#include <atomic>
#include <map>
#include <iterator>
#include <vector>
#include "stdInOut.h"
#include "log.h"

using namespace std;
namespace chessInterface
{
	// unique initialization
	stdInOut *stdInOut::_instance = nullptr;

	stdInOut *stdInOut::instance(void)
	{
		if (nullptr == _instance)
		{
			_instance = new stdInOut;
		}
		return _instance;
	}

	stdInOut::stdInOut(void)
	{
		// preparation to set log file by constructor call
		aLog = new Log::Logger("stdInOut.log");
		aLog->setLogLevel(Log::Logger::DEBUG);
		aLog->debug() << "create stdInOut";

		this->inputWorkerThread = new std::thread(&stdInOut::inputWorker, this);
		this->outputWorkerThread = new std::thread(&stdInOut::outputWorker, this);
	};

	stdInOut::~stdInOut(void)
	{
		delete aLog;
			inputWorkerThread->join();
		outputWorkerThread->join();
		delete inputWorkerThread;
		delete outputWorkerThread;
	}

	void stdInOut::waitForTerminate(void)
	{
		aLog->debug() << "wait for Terminate called";
		inputWorkerThread->join();
		outputWorkerThread->join();
	}

	void stdInOut::inputWorker(void)
	{
		while (1)
		{
			string stringIn;
			getline(*consoleInputBuffer_ptr, stringIn);

			inputQueue.emplace(stringIn);
			if (nullptr != this->parser)
				this->parser->processCommand(stringIn);

			aLog->debug() << "receive:" << stringIn;
		}
	};

	void stdInOut::input(const std::string input)
	{
		// outputQueue.push(input);
		// outDataCondGui.notify_one();
	}

	void stdInOut::outputWorker(void)
	{
		std::unique_lock<std::mutex> outDataLock(outDataMutex);
		string stringOut;
		while (1)
		{
			while (outputQueue.empty())
				outDataCondGui.wait(outDataLock);

			stringOut = outputQueue.front();
			outputQueue.pop();
			aLog->debug() << "outputWorker:" << stringOut;
			cout << stringOut << endl;
		}
	}

	void stdInOut::output(const std::string output)
	{
		aLog->debug() << "output:" << output;
		outputQueue.push(output);
		outDataCondGui.notify_one();
	}

	void stdInOut::start(void)
	{
	}

	void stdInOut::stop(void)
	{
	}
}
