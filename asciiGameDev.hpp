#include <cstdlib>
#include <string>
#include <iostream>

#ifndef ASCII_GAME_DEV
#define ASCII_GAME_DEV

const int x = 16;
const int y = 4;

char screen[4][16];
char fill = ' ';

/*
  Data structure for a movable character
*/
typedef struct
{
  std::string prompt;
  char mchar;
  int posX;
  int posY;
} Mchar;

void clear()
{
  std::cout << "\033[2J\033[1;1H";

  for (int i = 0; i < y; i++)
    {
      for (int j = 0; j < x; j++)
      {
        screen[i][j] = fill;
      }
    }
}

/* 
  Draw the characters on the screen
*/
void draw(Mchar mchar, Mchar mchar2)
{
  screen[mchar.posY][mchar.posX] = mchar.mchar;
  screen[mchar2.posY][mchar2.posX] = mchar2.mchar;
  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < x; j++)
    {

      char thisChar = screen[i][j];
      
      if (thisChar == mchar.mchar)
      {
        // change colour to red
        std::cout << "\033[1;31m";
      }
      else if (thisChar == mchar2.mchar)
      {
        // change colour to green
        std::cout << "\033[1;32m";
      }
  
      std::cout << thisChar;

      // reset colour
      std::cout << "\033[0m";
      
    }
    


    std::cout << '\n';
  }
}

// a funciton to check if an MChar is out of bounds and if so wrap it around
void checkBounds(Mchar &mchar) {
  if (mchar.posX < 0)
  {
    mchar.posX = x - 1;
  }
  else if (mchar.posX >= x)
  {
    mchar.posX = 0;
  }

  if (mchar.posY < 0)
  {
    mchar.posY = y - 1;
  }
  else if (mchar.posY >= y)
  {
    mchar.posY = 0;
  }
} 

void prompt(Mchar& player)
{
  std::cin >> player.prompt;
  if (player.prompt == "w")
  {
    player.posY --;
  } else if (player.prompt == "s")
  {
    player.posY ++;
  } else if (player.prompt == "d")
  {
    player.posX ++;
  } else if (player.prompt == "a")
  {
    player.posX --;
  }

  checkBounds(player);
}

/*
  Return 0 if the two characters collide, otherwise return 1
*/ 
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
