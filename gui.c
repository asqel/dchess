#include "draw.h"
#include "chess.h"
#include <stdio.h>

static void draw_rect(int x, int y, int w, int h, uint32_t color) {
    for (int i = y; i < y + h; i++) {
        for (int j = x; j < x + w; j++) {
            FAST_PUT(j, i, color);
        }
    }
}

char *img_pawn = ""
"                    "
"      ########      "
"    ############    "
"    ############    "
"    ############    "
"      ########      "
"        ####        "
"      ########      "
"    ############    "
"  ################  "
;

char *img_rook = ""
"                    "
"    ##  ####  ##    "
"    ############    "
"    ############    "
"    ############    "
"      ########      "
"      ########      "
"      ########      "
"    ############    "
"  ################  "
;

char *img_horse = ""// pf4 cant draw
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
;

char *img_bishop = ""
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
;

char *img_queen = ""
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
"####################"
;

char *img_king = ""
"##  ##  ##  ##  ##  "
"  ##  ##  ##  ##  ##"
"##  ##  ##  ##  ##  "
"  ##  ##  ##  ##  ##"
"##  ##  ##  ##  ##  "
"  ##  ##  ##  ##  ##"
"##  ##  ##  ##  ##  "
"  ##  ##  ##  ##  ##"
"##  ##  ##  ##  ##  "
"  ##  ##  ##  ##  ##"
;

void draw_piece(int x, int y, char *img, int is_white) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (img[(i * 10 + j) * 2] == '#') {
                draw_rect(j * 6 + x, i * 6 + y, 6, 6, is_white ? 0x6b011a : 0x2e2b2b);
            }
        }
    }
}

void printplat(piece_t **board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                draw_rect(j * 60, i * 60, 60, 60, 0xefd9b4);
            } else {
                draw_rect(j * 60, i * 60, 60, 60, 0xb38762);
            }
        }
    }

    char *imgs[] = {
        img_pawn, img_rook, img_horse, img_bishop, img_queen, img_king
    };

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == CHESS_NONE)
                continue;
            int id = (board[i][j] & 0b01111111) - 1;
            while (id < 0 || id >= 6) {
                printf("ASQEL STOP\n");
            }
            draw_piece(j * 60, i * 60, imgs[id], CHESS_IS_WHITE(board[i][j]));
        }
    }
}
