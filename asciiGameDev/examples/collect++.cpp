#include <iostream>

#include "../asciiGameDev.hpp"

int main()
{
  Mchar player = {"", '@', 0, 0};
  Mchar collectable = {"", '#', rand() % x, rand() % y};

  int score = 0;
  int on = 1;
  fill = '-';

  std::cout << "1)e to exit\n2)wasd to move\n3)collect the #\n4)have fun!\n";

  while (on)
  {
    clear();
    draw(player, collectable);

    std::cout <<"enter instruction: ";
    prompt(*&player);

    if (collide(player, collectable) == 0)
    {
      std::cout << "good job!\n";
      collectable.posX = rand() % x;
      collectable.posY = rand() % y;
      score ++;
    }
    if (player.prompt == "e")
    {
      break;
    }
  }
  std::cout <<"score: " << score << std::endl;

  return 0;
}
