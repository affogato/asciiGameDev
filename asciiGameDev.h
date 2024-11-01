#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef ASCII_GAME_DEV
#define ASCII_GAME_DEV

const int x = 16;
const int y = 4;

char screen[4][16];
char fill = ' ';

typedef struct
{
  char prompt[64];
  char mchar;
  int posX;
  int posY;
} Mchar;

void clear()
{
  memset(screen, fill, sizeof(screen));
}

void draw(Mchar mchar, Mchar mchar2)
{
  screen[mchar.posY][mchar.posX] = mchar.mchar;
  screen[mchar2.posY][mchar2.posX] = mchar2.mchar;
  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < x; j++)
    {
      printf("%c", screen[i][j]);
    }
    
    printf("\n");
  }
}

void prompt(Mchar* mchar)
{
  scanf("%s", mchar->prompt);
  if (strcmp(mchar->prompt, "w") == 0)
  {
    mchar->posY --;
  } else if (strcmp(mchar->prompt, "s") == 0)
  {
    mchar->posY ++;
  } else if (strcmp(mchar->prompt, "d") == 0)
  {
    mchar->posX ++;
  } else if (strcmp(mchar->prompt, "a") == 0)
  {
    mchar->posX --;
  }
}

int collide(Mchar mchar, Mchar mchar2)
{
  if (mchar.posX == mchar2.posX && mchar.posY == mchar2.posY)
  {
    return 0;
  } else
  {
    return 1;
  }
}
#endif
