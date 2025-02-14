
#include <profan/syscall.h>
#include <profan.h>
#include "draw.h"
#include "chess.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printplat(piece_t **board);
void init_board(piece_t **board);

#define FPS 25

int main(void) {

    init_graphic();

    piece_t **board = malloc(sizeof(piece_t *) * 8);
    for (int i = 0; i < 8; i++)
        board[i] = malloc(sizeof(piece_t) * 8);

    init_board(board);


    char is_runing_now_the_game_of_chess = 1;
    while (is_runing_now_the_game_of_chess) {
        uint32_t t0 = syscall_timer_get_ms();

        printplat(board);
        update_screen();

        uint32_t t1 = syscall_timer_get_ms();
        if (t1 - t0 < (1000 / FPS)) {
            usleep((1000 / FPS - (t1 - t0)) * 1000);
        }
        t1 = syscall_timer_get_ms();
        serial_debug("fps: %d\n", 1000 / (t1 - t0));
    }
    for (int i = 0; i < 8; i++)
        free(board[i]);
    free(board);
    close_graphic();
    return 0;
}
