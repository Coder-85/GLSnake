#include <iostream>
class Snake;

void snakeMovement(int direction);
void printText(int x, int y, std::string text);
void setSnake(Snake *s);
void checkGame();
void setGamePaused(bool paused);
void setGameOver(bool gameOver);
bool getIsGamePaused();
bool getIsGameOver();