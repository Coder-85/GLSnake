#include <iostream>
#include <GL/freeglut.h>
#include <time.h>
#include <math.h>
#include "Food.hpp"
#include "Snake.hpp"
#include "vars.hpp"

Food::Food()
    : m_radius(0.5f) {}

Food::~Food() {}

void Food::draw()
{
    glColor3f(1.f, 0.f, 0.f);
    glBegin(GL_POLYGON);
        for(float i = 0; i < 2 * PI; i += PI / 4.f)
            glVertex3f(0.48f + foodX + cos(i) * m_radius, 0.48f + foodY + sin(i) * m_radius, 0.f);
    glEnd();
}