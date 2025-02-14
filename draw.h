#include <profan/syscall.h>
#include <stdlib.h>

extern uint32_t *g_buffer;

#define WX 480
#define WY 480

void init_graphic(void);
void close_graphic(void);
void update_screen(void);

#define FAST_PUT(x, y, color) (g_buffer[(y) * WX + (x)] = (color))
