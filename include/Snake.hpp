#include <iostream>
#include "macros.hpp"

enum SnakeDirection 
{
    Up,
    Down,
    Left,
    Right
};

class Snake
{
private:
    int m_direction;
    int m_length;
    bool m_isGrowing;
    bool m_isChangingDirection;
public:
    int pos[(ROWS * COLS)+1][2];
    int grid[ROWS][COLS];

    Snake();
    ~Snake();
    
    void draw();
    void moveSnake(int direction);
    void handleKeyPress(unsigned char key);
    void handleSpecialKeyPress(int key);

    inline int getDirection() const { return m_direction; }
    inline int getLength() const { return m_length; }
    inline bool isGrowing() const { return m_isGrowing; }
    inline bool isChangingDirection() const { return m_isChangingDirection; }

    inline void setDirection(int direction) { m_direction = direction; }
    inline void setLength(int length) { m_length = length; }
    inline void setGrowing(bool isGrowing) { m_isGrowing = isGrowing; }
    inline void setChangingDirection(bool isChangingDirection) { m_isChangingDirection = isChangingDirection; }
};