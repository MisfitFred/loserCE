

#include <exception>
#include <string>
#include <algorithm>
// #include <array>
// #include <thread>
#include <iostream>
// #include <sstream>
// #include <atomic>
// #include <map>
// #include <iterator>
// #include <xutility>
// #include <iterator>
#include <vector>
#include "uci.h"
#include "log.h"

using namespace std;
namespace chessInterface
{

	uci::uci(inOutInterface *interfaceObject)
	{
		// preparation to set log file by constructor call
		// logFileNameWithPath = new string("C:\\temp\\log.txt");
		// logFile.open(*logFileNameWithPath, ios_base::out);

		/* Initialize command list --> assign processing methods to command list */
		uciGuiCommandListMap_fp["uci"] = &uci::cmdUci;
		uciGuiCommandListMap_fp["quit"] = &uci::cmdQuit;
		uciGuiCommandListMap_fp["debug"] = &uci::cmdDebug;
		uciGuiCommandListMap_fp["go"] = &uci::cmdGo;
		uciGuiCommandListMap_fp["isready"] = &uci::cmdIsReady;
		uciGuiCommandListMap_fp["ponderhit"] = &uci::cmdPonderHit;
		uciGuiCommandListMap_fp["position"] = &uci::cmdPosition;
		uciGuiCommandListMap_fp["register"] = &uci::cmdRegister;
		uciGuiCommandListMap_fp["set"] = &uci::cmdSetOption;
		uciGuiCommandListMap_fp["stop"] = &uci::cmdStop;
		uciGuiCommandListMap_fp["newgame"] = &uci::cmdUCINewGame;
		inOut = interfaceObject;
		// createWorkerThread();
	};

	uci::~uci()
	{
		// delete logFileNameWithPath;
		// logFile.close();
		// delete workerThread;
	}

	void uci::processCommand(std::string &inputData)
	{
		std::transform(inputData.begin(), inputData.end(), inputData.begin(), ::tolower);
		for (std::map<std::string, uci::Instruction>::iterator iter = uciGuiCommandListMap_fp.begin(); iter != uciGuiCommandListMap_fp.end(); ++iter)
		{
			string command = iter->first;
			uci::Instruction commandCall;
			std::size_t found = inputData.find(command);
			if (found != std::string::npos)
			{
				string parameter = inputData.substr(found + 1);
				commandCall = iter->second;
				(*this.*(commandCall))(parameter);
			}
		}
	}


#if 0
	void uci::waitForTerminate(void)
	{
		workerThread->join();
	}*/

	void uci::worker(void) {
		std::string receivedDataString = waitForDataInput();
		std::istringstream  receivedDataIss(receivedDataString);

		//seperate input stream by "blanks" and store each "word" int as an string element of a vector. 
		std::vector<std::string> keyWords(std::istream_iterator<std::string>{receivedDataIss}, std::istream_iterator<std::string>());

		//Search in keywords for a known key word which are stored in (uciGuiCommandListVector)
		auto element = std::find_first_of(keyWords.begin(), keyWords.end(), uciGuiCommandListVector.begin(), uciGuiCommandListVector.end());
		if (element != keyWords.end())
		{
			//key word should be known, search for a processing method.
			auto processingKeywordMethod = uciGuiCommandListMap_fp.find(*element);
			if (processingKeywordMethod != uciGuiCommandListMap_fp.end())
			{
				//call the method
				(*this.*(*processingKeywordMethod).second)();
			}
			else
			{
				/* command not found */
				log(string("Internal Error: received unknown could no be processed : \"") + receivedDataString + "\"");
			}
		}
		else
		{
			/* command not found */
			log(string("received unknown command: \"") + receivedDataString + "\"");
		}
	
	};
	void uci::workerLoop(void)
	{
		while (!(this->terminate))
		{
			worker();
		}		
	}
	
	std::string  uci::waitForDataInput(void)
	{
		string inBuffer;
		getline(*consoleInputBuffer_ptr, inBuffer);
		
		//getConsoleInput(inBuffer);
		log("receive:" + inBuffer);
		return inBuffer;
			
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


	void uci::createWorkerThread(void)
	{
		workerThread = new std::thread(&uci::workerLoop, this);
	}
#endif

	/**
	 * \brief Process the UCI "uci" command
	 * Requirement from UCI specification:
	 *	Tell engine to use the uci(universal chess interface), this will be
	 *  sent once as a first command after program boot to tell the engine
	 *  to switch to uci mode. After receiving the uci command the engine
	 *  must identify itself with the "id" command and send the "option"
	 *  commands to tell the GUI which engine settings the engine supports
	 *  if any. After that the engine should send "uciok" to acknowledge
	 *  the uci mode. If no uciok is sent within a certain time period, the
	 *  engine task will be killed by the GUI.
	 *********************************************************************/
	void uci::cmdUci(const std::string &parameter)
	{
		inOut->output("id name loserCE 0.0a");
		inOut->output("id author Fred C.");
	}

	void uci::cmdQuit(const std::string &parameter)
	{
		this->terminate = true;
	}

	void uci::cmdDebug(const std::string &parameter)
	{
	}

	void uci::cmdGo(const std::string &parameter)
	{
	}

	void uci::cmdIsReady(const std::string &parameter)
	{
	}

	void uci::cmdPonderHit(const std::string &parameter)
	{
	}

	void uci::cmdPosition(const std::string &parameter)
	{
	}

	void uci::cmdRegister(const std::string &parameter)
	{
	}

	void uci::cmdSetOption(const std::string &parameter)
	{
	}

	void uci::cmdStop(const std::string &parameter)
	{
	}

	void uci::cmdUCI(const std::string &parameter)
	{
	}

	void uci::cmdUCINewGame(const std::string &parameter)
	{
	}

}