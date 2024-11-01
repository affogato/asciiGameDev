# Download
- git
```
git clone https://github.com/mousegames/asciiGameDev.git
```
- github cli
```
gh clone https://github.com/mousegames/asciiGameDev.git
```

## Geting started
### dependencies
- none
### instructions
- download
- look at documentation
- have fun and make games!

## Examples
- c
```
#include <stdio.h>

#include "asciiGameDev.h"

int main()
{
  printf("-Moving @-\n");

  Mchar player = {"", '@', 0, 0};
  Mchar blank = {"", '-', 0, 0};
  fill = '-'

  while (1)
  {
    clear();
    draw(blank, player);
    prompt(&player);
  }
}

```
- c++
```
#include <iostream>

#include "asciiGameDev.hpp"

int main()
{
  std::cout << "-Moving @-"<< std::endl;
  Mchar player = {"", '@', 0, 0};
  Mchar blank = {"", '-', 0, 0};
  fill = '-'

  while (1)
  {
    clear();
    draw(blank, player);
    prompt(&player);
  }
}
```
see more examples in the examples folder
