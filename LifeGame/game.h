#ifndef _GAME_H
#define _GAME_H	1

#include <stdint.h>

#if defined TERMINAL_BUILD
#define WIDTH (40)
#define HEIGHT (20)
#define WAIT (1000000*0.25) // 0.25 sec
#endif

#if defined SDL2_BUILD
#define WIDTH (60)
#define HEIGHT (60)
#define WAIT (1000*0.25) // 0.25 sec
#endif

#define RATIO (0.5)

uint8_t board[HEIGHT+2][WIDTH+2];

void shuffleBoard(void);
void nextGeneration(void);

#endif /* game.h */
