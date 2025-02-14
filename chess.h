#ifndef _CHESS_H
#define _CHESS_H

#define CHESS_TO_BLACK(X) ((X) | 0b10000000)
#define CHESS_TO_WHITE(X) ((X) & 0b01111111)

enum {
	CHESS_NONE,
	CHESS_P, // pawn
	CHESS_R, // ROOK
	CHESS_H, // HORSE
	CHESS_B, // BISHOP
	CHESS_Q, // QUEEN
	CHESS_K, // KING

	CHESS_P_B = CHESS_TO_BLACK(CHESS_P), // pawn
	CHESS_R_B = CHESS_TO_BLACK(CHESS_R), // ROOK
	CHESS_H_B = CHESS_TO_BLACK(CHESS_H), // HORSE
	CHESS_B_B = CHESS_TO_BLACK(CHESS_B), // BISHOP
	CHESS_Q_B = CHESS_TO_BLACK(CHESS_Q), // QUEEN
	CHESS_K_B = CHESS_TO_BLACK(CHESS_K), // KING


};


#define CHESS_IS_WHITE(X) (((X) >> 7) == 0)
#define CHESS_IS_BLACK(X) (((X) >> 7) == 1)

#define CHESS_IS(X, TYPE) ((X) & (TYPE))

typedef char piece_t;

#endif