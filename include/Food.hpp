#pragma once
#include <iostream>

class Food 
{
private:
    float m_radius;
    int foodX;
    int foodY;

public:
    Food();
    ~Food();
    void draw();

    inline float getRadius() const { return m_radius; }
    inline int getFoodX() const { return foodX; }
    inline int getFoodY() const { return foodY; }

    inline void setRadius(float redius) { m_radius = redius; }
    inline void setFoodX(int x) { foodX = x; }
    inline void setFoodY(int y) { foodY = y; }
};