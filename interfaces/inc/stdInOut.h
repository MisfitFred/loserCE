#pragma once
#include <fstream>
#include <string>
#include <thread>
#include <map>
#include <vector>
#include <iostream>
#include "queueTs.h"
#include <list>
#include "inOutInterface.h"
#include "log.h"
#include <condition_variable>
namespace chessInterface
{

	class stdInOut : public inOutInterface
	{
	public:
		~stdInOut();
		void start(void);
		void stop(void);
		void output(const std::string output);
		void input(const std::string input);
		static stdInOut *instance(void);
		void waitForTerminate(void);

	protected:
		stdInOut();
		void inputWorker(void);

		void outputWorker(void);

		bool terminate = false;
		std::thread *inputWorkerThread;
		std::thread *outputWorkerThread;

		std::ostream *consoleOutputBuffer_ptr = &std::cout;
		std::istream *consoleInputBuffer_ptr = &std::cin;

		queueTs<std::string> inputQueue;
		queueTs<std::string> outputQueue;

		std::mutex inDataMutex;
		std::mutex outDataMutex;
		std::condition_variable inDataCondGui;
		std::condition_variable inDataCondEngine;
		std::condition_variable outDataCondGui;
		std::condition_variable outDataCondEngine;

	private:
		static stdInOut* _instance;
		Log::Logger *aLog;
	};

}