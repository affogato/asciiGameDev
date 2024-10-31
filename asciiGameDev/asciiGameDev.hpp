#include <cstdlib>
#include <string>
#include <iostream>

#ifndef ASCII_GAME_DEV
#define ASCII_GAME_DEV

const int x = 16;
const int y = 4;

char screen[4][16];
char fill = ' ';

typedef struct
{
  std::string prompt;
  char mchar;
  int posX;
  int posY;
} Mchar;

void clear()
{
  for (int i = 0; i < y; i++)
    {
      for (int j = 0; j < x; j++)
      {
        screen[i][j] = fill;
      }
    }
}
void draw(Mchar mchar, Mchar mchar2)
{
  screen[mchar.posY][mchar.posX] = mchar.mchar;
  screen[mchar2.posY][mchar2.posX] = mchar2.mchar;
  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < x; j++)
    {
      std::cout << screen[i][j];
    }
    
    std::cout << '\n';
  }
}

void prompt(Mchar& mchar)
{
  std::cin >> mchar.prompt;
  if (mchar.prompt == "w")
  {
    mchar.posY --;
  } else if (mchar.prompt == "s")
  {
    mchar.posY ++;
  } else if (mchar.prompt == "d")
  {
    mchar.posX ++;
  } else if (mchar.prompt == "a")
  {
    mchar.posX --;
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
