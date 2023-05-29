lexer grammar UCILexer;

UCI_COMMAND: 'uci';
DEBUG_COMMAND: 'debug';
ISREADY_COMMAND: 'isready';
SET_OPTION_COMMAND: 'setoption';
REGISTER_COMMAND: 'register';
UCINewGame_COMMAND: 'ucinewgame';
POSITION_COMMAND: 'position';
GO_COMMAND: 'go';
STOP_COMMAND: 'stop';
QUIT_COMMAND: 'quit';
PING_COMMAND: 'ping';
INVALID_COMMAND: ~[ \t\n\r]+;

option: 'option';
name: 'name';
value: 'value';

NUMBER: [0-9]+;
WORD: [a-zA-Z0-9_]+;
STRING: '"' (~["\r\n] | '""')* '"';

WHITESPACE: [ \t\r\n]+ -> skip;
