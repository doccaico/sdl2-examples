#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>

#include "game.h"

extern uint8_t board[HEIGHT+2][WIDTH+2];

void echoBoard() {
  for (int i = 1; i < HEIGHT+1; i++) {
    for (int j = 1; j < WIDTH+1; j++) {
      if (board[i][j]) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main(void) {

  time_t t;
  srand((unsigned) time(&t));

  shuffleBoard();

  while(1) {
    system("clear");
    nextGeneration();
    echoBoard();
    usleep(WAIT);
  }

  return 0;
}
