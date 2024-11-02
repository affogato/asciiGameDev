#include <iostream>

#include "../asciiGameDev.hpp"


void updateCollectable(Mchar &collectable) {
  // generate random direction for collectable
  int direction = rand() % 4;

  // update collectable position
  switch (direction)
  {
  case 0:
    collectable.posX ++;
    break;
  case 1:
    collectable.posX --;
    break;
  case 2:
    collectable.posY ++;
    break;
  case 3:
    collectable.posY --;
    break;
  default:
    break;
  }

  // check if collectable is out of bounds
  checkBounds(collectable);

}

void instructions() {

  // change colour to green
  std::cout << "\033[1;32m";

  std::cout << "1) e to exit\n"
            << "2) wasd to move\n"
            << "3) collect the #\n"
            << "4) have fun!\n\n";

  // reset colour
  std::cout << "\033[0m";
}

void print_score(int score) {

  // print score in yellow colour
  std::cout << "\033[1;33m";
  std::cout << "score: " << score << std::endl << std::endl;

  // reset colour
  std::cout << "\033[0m";
} 

int main()
{
  Mchar player = {"", '@', 0, 0};
  Mchar collectable = {"", '#', rand() % x, rand() % y};
  fill = '-';

  int score = 0;
  int on = 1;
  fill = '-';

  // clear escape sequence
  std::cout << "\033[2J\033[1;1H";


  while (on)
  {
    clear();
    
    instructions();                   // print instructions
    print_score(score);               // print score

    updateCollectable(collectable);   // update collectable position

    draw(player, collectable);        // render player and environment
    
    prompt(player);                   // get instructions and update player position

    // check if player has collided with collectable
    if (collide(player, collectable) == 0)
    {
      std::cout << "Good job!\n";
      collectable.posX = rand() % x;
      collectable.posY = rand() % y;
      score ++;
    }

    // check if player has exited
    if (player.prompt == "e")
    {
      break;
    }
  }
  std::cout << "score: " << score << std::endl;

  return 0;
}
