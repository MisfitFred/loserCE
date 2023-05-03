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
	 /**
	 * @brief utilize the stdIn and stdOut to communicate with the chess engine.
	 *
	 */
	class stdInOut : public inOutInterface
	{
	public:
		/**
		 * @brief Destroy the std In Out object
		 *
		 */
		~stdInOut();
		/**
		 *  \brief no effect, needed because base class function is virtual
		 *  \todo check for a more elegant solution
		 */
		void start(void);

		/**
		 *  \brief no effect, needed because base class function is virtual
		 *  \todo check for a more elegant solution
		 */
		void stop(void);

		/**
		 * \brief function to send a message to the UCI server
		 *
		 * \param output test which shall be sent
		 */
		void output(const std::string output);

		/**
		 *  \brief do not use,needed because base class function is virtual
		 *  \todo check for a more elegant solution
		 */
		void input(const std::string input);

		/**
		 * @brief provide the unique instance of this class
		 *
		 * @return stdInOut*
		 */
		static stdInOut *instance(void);

		/**
		 * \brief wait till all thread of stdInOut are terminated.
		 */
		void waitForTerminate(void);

	protected:
		/**
		 * @brief Construct a new std In Out object
		 *
		 */
		stdInOut();

		/**
		 *\brief  worker function (std::thread) to catch istream
		 */
		void inputWorker(void);

		/**
		 * \brief worker function to process data to cout
		 */
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
		static stdInOut *_instance;
		Log::Logger *aLog;
	};
}