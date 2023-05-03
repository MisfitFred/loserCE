#pragma once
#include <string>
#include "uci.h"

namespace chessInterface
{
	class uci;
	class inOutInterface
	{
	public:
		/**
		 * @brief Construct a new in Out Interface object
		 *
		 */
		inOutInterface(void){};

		/**
		 * @brief Destroy the in Out Interface object
		 *
		 */
		virtual ~inOutInterface(void){};

		/**
		 * @brief start the connection to the respective interface
		 *
		 */
		virtual void start(void) = 0;

		/**
		 * @brief stops the connection to the respective interface
		 *
		 */
		virtual void stop(void) = 0;

		/**
		 * @brief sent the output the respective interface
		 *
		 * @param output
		 */
		virtual void output(const std::string output) = 0;

		/**
		 * @brief receives an input
		 * @deprecated don't know if this interface is really needed.
		 *
		 * @param input
		 */
		virtual void input(const std::string input) = 0;

		/**
		 * @brief
		 *
		 * @param regParser
		 */
		void registerUci(chessInterface::uci *regParser)
		{
			this->parser = regParser;
		};

	protected:
		chessInterface::uci *parser = nullptr;
	};
}