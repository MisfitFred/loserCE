#pragma once
#include <string>
#include <map>
#include <vector>
#include "inOutInterface.h"
namespace chessInterface
{
	class uci
	{
	public:
		uci(chessInterface::inOutInterface *interfaceObject);
		~uci();

		/**
		 * @brief parse the command and starts processing
		 *
		 * @param command
		 */
		void processCommand(std::string &command);

	protected:
		/* uci command handler */
		void cmdUci(const std::string &parameter);
		void cmdQuit(const std::string &parameter);
		void cmdDebug(const std::string &parameter);
		void cmdGo(const std::string &parameter);
		void cmdIsReady(const std::string &parameter);
		void cmdPonderHit(const std::string &parameter);
		void cmdPosition(const std::string &parameter);
		void cmdRegister(const std::string &parameter);
		void cmdSetOption(const std::string &parameter);
		void cmdStop(const std::string &parameter);
		void cmdUCI(const std::string &parameter);
		void cmdUCINewGame(const std::string &parameter);

		typedef void (uci::*Instruction)(const std::string &parameter);

		std::vector<std::string> uciGuiCommandListVector;
		std::map<std::string, uci::Instruction> uciGuiCommandListMap_fp;
		bool terminate = false;

		inOutInterface *inOut;
	};
}