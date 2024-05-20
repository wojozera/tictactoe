Game developed during one of the courses during my studies. Below are presented examples with commands.

NMK game solver(e.g. tic tac toe) using min-max algorithm
n - numer of rows
m - numer of columns
k - numer of characters in row to win


GEN_ALL_POS_MOV N M K ActivePlayer - generate all possible moves and the number of moves.

Examples:

Input:

GEN_ALL_POS_MOV 3 3 3 2

1 0 0

0 0 0

0 0 0

GEN_ALL_POS_MOV_CUT_IF_GAME_OVER N M K ActivePlayer - generate all feasible moves and the number of such moves. If one of the moves results in win or tie, then generate only the first such a move:
Input:

GEN_ALL_POS_MOV_CUT_IF_GAME_OVER 3 3 3 1

0 2 1

2 2 1

0 1 0

SOLVE_GAME_STATE N M K ActivePlayer - solving the game and stating one of the possible answers: FIRST_PLAYER_WINS, SECOND_PLAYER_WINS, BOTH_PLAYERS_TIE.

Examples:

Input:

SOLVE_GAME_STATE 3 3 3 2

1 0 0

0 0 0

0 0 0
