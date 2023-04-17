#pragma once
#include <string>
namespace chessInterface
{
	class inOutInterface
	{
	public:
		inOutInterface(void){};
		virtual ~inOutInterface(void){};
		virtual void start(void) = 0;
		virtual void stop(void) = 0;
		virtual void output(const std::string output) = 0;
		virtual void input(const std::string input) = 0;
	};
}