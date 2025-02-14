#include "chess.h"

/*

K B R P P . . .
B Q H P . . . .
R H P . . . . .
P P . . . . . P
P . . . . . P P
. . . . . P H R
. . . . P H Q B
. . . P P R B K
*/
static piece_t board_ref[8][8] = {
	{CHESS_K_B, CHESS_B_B, CHESS_R_B, CHESS_P_B, CHESS_P_B, 0,       0,       0},
	{CHESS_B_B, CHESS_Q_B, CHESS_H_B, CHESS_P_B, 0,         0,       0,       0},
	{CHESS_R_B, CHESS_H_B, CHESS_P_B, 0,         0,         0,       0,       0},
	{CHESS_P_B, CHESS_P_B, 0,         0,         0,         0,       0,       CHESS_P},
	{CHESS_P_B, 0,         0,         0,         0,         0,       CHESS_P, CHESS_P},  
	{0,         0,         0,         0,         0,         CHESS_P, CHESS_H, CHESS_R},
	{0,         0,         0,         0,         CHESS_P,   CHESS_H, CHESS_Q, CHESS_B},
	{0,         0,         0,         CHESS_P,   CHESS_P,   CHESS_R, CHESS_B, CHESS_K},
};

void init_board(piece_t **board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = board_ref[i][j];
        }
    }
}
