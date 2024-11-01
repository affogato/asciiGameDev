# Documentation

### clear
- clears screen with fill char
- no args
### draw
- 2 args Mchar
- draws args to screen
### prompt
- takes a pionter in c or a refrence in c++

moves Mchar arg
### collide
- 2 args Mchar
- checks for colision

### Mchar
**C**
```
typedef struct
{
  char prompt[64];
  char mchar;
  int posX;
  int posY;
} Mchar;
```

**C++**
```
typedef struct
{
  std::string prompt;
  char mchar;
  int posX;
  int posY;
} Mchar;

```
