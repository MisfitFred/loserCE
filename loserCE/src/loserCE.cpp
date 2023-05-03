// loserCE.cpp: Hauptprojektdatei.
/*

*/
#include "uci.h"
#include "engine.h"
#include "stdInOut.h"

using namespace std;

int main(int argc, char* argv[])
{
	/* start UCI*/
	chessInterface::stdInOut *inOut = chessInterface::stdInOut::instance();
	chessInterface::uci uci_object(inOut);

	inOut->registerUci(&uci_object);

	inOut->waitForTerminate();

    return 0;
}





