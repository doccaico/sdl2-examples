#include "game.h"

#include <stdlib.h>

uint8_t board[HEIGHT+2][WIDTH+2];

static int randomRange(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

static int countNeighbors(int y, int x) {
  // top-left
  return board[y-1][x-1] +
  // top-middle
  board[y-1][x] +
  // top-right
  board[y-1][x+1] +
  // left
  board[y][x-1] +
  // right
  board[y][x+1] +
  // bottom-left
  board[y+1][x-1] +
  // bottom-middle
  board[y+1][x] +
  // bottom-right
  board[y+1][x+1];
}

void nextGeneration(void) {
  uint8_t neighbors[HEIGHT+2][WIDTH+2];
  for (int i = 1; i < HEIGHT+1; i++) {
    for (int j = 1; j < WIDTH+1; j++) {
      neighbors[i][j] = countNeighbors(i, j);
    }
  }

  for (int i = 1; i < HEIGHT+1; i++) {
    for (int j = 1; j < WIDTH+1; j++) {
      switch (neighbors[i][j]) {
        case 2:
          // Do nothing
          break;
        case 3:
          board[i][j] = 1;
          break;
        default:
          board[i][j] = 0;
          break;
      }
    }
  }
}

void shuffleBoard(void) {
  for (int i = 1; i < HEIGHT+1; i++) {
    for (int j = 1; j < (int)(RATIO*WIDTH)+1; j++) {
      board[i][j] = 1;
    }
  }
  for (int i = 1; i < HEIGHT+1; i++) {
    for (int j = 1; j < WIDTH+1; j++) {
      int randomIndex = randomRange(1, WIDTH);
      uint8_t tmp = board[i][j];
      board[i][j] = board[i][randomIndex];
      board[i][randomIndex] = tmp;
    }
  }
}
