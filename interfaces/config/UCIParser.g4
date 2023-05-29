parser grammar UCIParser;

options {
    tokenVocab = UCILexer;
}

uciCommand: UCI_COMMAND;
debugCommand: DEBUG_COMMAND;
isReadyCommand: ISREADY_COMMAND;
setOptionCommand: SET_OPTION_COMMAND option;
registerCommand: REGISTER_COMMAND;
uciNewGameCommand: UCINewGame_COMMAND;
positionCommand: POSITION_COMMAND;
goCommand: GO_COMMAND;
stopCommand: STOP_COMMAND;
quitCommand: QUIT_COMMAND;
pingCommand: PING_COMMAND;
invalidCommand: INVALID_COMMAND;

option: OPTION_COMMAND name STRING value STRING;
name: NAME_COMMAND STRING;
value: VALUE_COMMAND STRING;
