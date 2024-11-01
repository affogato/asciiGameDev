#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "../asciiGameDev.h"

int main()
{
  Mchar player = {"", '@', 0, 0,};
  Mchar collectable = {"", '#', rand() % x, rand() % y};

  int score = 0;
  int on = 1;
  fill = '-';

  printf("1)e to exit\n2)wasd to move\n3)collect the #\n4)have fun!\n");
  sleep(2);

  while (on)
  {
    clear();
    draw(player, collectable);

    printf("enter instruction: ");
    prompt(&player);

    if (collide(player, collectable) == 0)
    {
      printf("good job!\n");
      sleep(1);

      collectable.posX = rand() % x;
      collectable.posY = rand() % y;
      score ++;
    }
    if (strcmp(player.prompt, "e") == 0)
    {
      break;
    }
  }
  printf("score: %d\n", score);

  return 0;
}
