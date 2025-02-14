#include <profan/syscall.h>
#include <stdlib.h>

#include "draw.h"
#include <stdio.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

uint32_t *g_buffer, *g_fb, g_pitch;

void init_graphic(void) {
	g_buffer = malloc(WX * WY * sizeof(uint32_t));

    g_pitch = syscall_vesa_pitch();
    g_fb = syscall_vesa_fb();
}

void close_graphic(void) {
    free(g_buffer);
}

void update_screen(void) {
    for (int y = 0; y < WY; y++) {
        for (int x = 0; x < WX; x++) {
            g_fb[y * g_pitch + x] = g_buffer[y * WX + x];
        }
    }
}
