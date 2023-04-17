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

	// Singelton pattern
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
		delete inputWorkerThread;
	}

	/**
	 * \brief wait till all thread of stdInOut are terminated.
	 */
	void stdInOut::waitForTerminate(void)
	{
		aLog->debug() << "wait for Terminate called";
		inputWorkerThread->join();
		outputWorkerThread->join();
	}

	/**
	 *\brief  worker function (std::thread) to catch istream
	 */
	void stdInOut::inputWorker(void)
	{
		string stringIn;
		getline(*consoleInputBuffer_ptr, stringIn);

		inputQueue.emplace(stringIn);

		aLog->debug() << "receive:" << stringIn;
	};

	/**
	 *  \brief do not use,needed because base class function is virtual
	 *  \todo check for a more elegant solution
	 */
	void stdInOut::input(const std::string input)
	{
		//outputQueue.push(input);
		//outDataCondGui.notify_one();
	}

	/**
	 * \brief worker function to process data to cout
	 */
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

	/**
	 * \brief function to send a message to the UCI server 
	 * 
	 * \param output test which shall be sent
	*/
	void stdInOut::output(const std::string output)
	{
		aLog->debug() << "output:" << output;
		outputQueue.push(output);
		outDataCondGui.notify_one();
	}

#if 0
	void uci::workerLoop(void)
	{
		while (!(this->terminate))
		{
			worker();
		}		
	}
	
	
	void uci::dataOutput(void)
	{
	}
	void uci::stateMachine(void)
	{
	}
	

	void uci::log(const string & data)
	{
		logFile << data << endl;
		logFile.flush();
		return;
	}
	string uci::getResponse(const string)
	{
		return string();
	}
	void uci::getConsoleInput(std::string & inBuffer)
	{
		getline(cin, inBuffer);
	}
#endif

	/**
	 *  \brief no effect, , needed because base class function is virtual
	 *  \todo check for a more elegant solution
	 */
	void stdInOut::start(void)
	{
	}

	/**
	 *  \brief no effect, needed because base class function is virtual
	 *  \todo check for a more elegant solution
	 */
	void stdInOut::stop(void)
	{
	}

#if 0
	void uci::createWorkerThread(void)
	{
		workerThread = new std::thread(&uci::workerLoop, this);
	}

	void uci::cmdUci(void)
	{
		consoleOutput("id name loserCE 0.0a");
		consoleOutput("id author Matthias N.");
	}

	void uci::cmdQuit(void)
	{
		this->terminate = true;
	}
#endif
}
