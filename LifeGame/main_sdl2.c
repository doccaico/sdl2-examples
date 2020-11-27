#include <time.h>

#include <SDL2/SDL.h>

#include "game.h"

#define RECT_SIZE 10

extern uint8_t board[HEIGHT+2][WIDTH+2];

void drawBoard(SDL_Renderer *renderer) {
  for (int i = 1; i < WIDTH+1; i++) {
    for (int j = 1; j < HEIGHT+1; j++) {
      if (board[j][i]) {
        int x = (i-1)*RECT_SIZE;
        int y = (j-1)*RECT_SIZE;
        SDL_RenderFillRect(renderer, &(SDL_Rect){x, y, RECT_SIZE, RECT_SIZE});
      }
    }
  }
}

int main(void) {

  time_t t;
  srand((unsigned) time(&t));

  shuffleBoard();

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window* win = SDL_CreateWindow("Life Game (SDL2)",
      0, 0, WIDTH*RECT_SIZE, HEIGHT*RECT_SIZE, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

  while (1) {

    SDL_Event e;
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        break;
      }
    }

    // black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    // green
    SDL_SetRenderDrawColor(renderer, 0, 230, 64, 0);
    nextGeneration();
    drawBoard(renderer);

    SDL_RenderPresent(renderer);

    SDL_Delay(WAIT);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);
  SDL_Quit();

  return 0;
}
