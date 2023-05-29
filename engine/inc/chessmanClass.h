#pragma once
#include <vector>
#include "chessMove.h"
#include "chessmanSide.h"
#include "emplacement.h"
namespace engine
{

	class chessmanClass
	{
	public:
		const chessmanSide side;

		chessmanClass(chessmanSide cSide) : side{cSide} {};
		virtual std::vector<chessMove> getMoves(emplacement *board, unsigned int position, chessmanSide side) = 0;
	};

	class chessmanPawn : public chessmanClass
	{
	public:
		std::vector<chessMove> getMoves(emplacement *board, unsigned int position, chessmanSide side) override;
	};

	class chessmanRook : public chessmanClass
	{

		std::vector<chessMove> getMoves(emplacement *board, unsigned int position, chessmanSide side) override
		{
			std::vector<chessMove> ret;
			return ret;
		};
	};

	class chessmanKnight : public chessmanClass
	{

		std::vector<chessMove> getMoves(emplacement *board, unsigned int position, chessmanSide side) override
		{
			std::vector<chessMove> ret;
			return ret;
		};
	};

	class chessmanQueen : public chessmanClass
	{

		std::vector<chessMove> getMoves(emplacement *board, unsigned int position, chessmanSide side) override
		{
			std::vector<chessMove> ret;
			return ret;
		};
	};

	class chessmanKing : public chessmanClass
	{

		std::vector<chessMove> getMoves(emplacement *board, unsigned int position, chessmanSide side) override
		{
			std::vector<chessMove> ret;
			return ret;
		};
	};
}