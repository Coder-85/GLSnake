#include <iostream>
#include <GL/freeglut.h>
#include "Snake.h"

Snake::Snake()
    : m_direction(SnakeDirection::Up), m_length(3),
      m_isGrowing(false), m_isChangingDirection(false)
{
    pos[0][0] = 20;
    pos[0][1] = 21;
    pos[1][0] = 20;
    pos[1][1] = 20;
    pos[2][0] = 20;
    pos[2][1] = 19;
}

Snake::~Snake() {}

void Snake::draw()
{
    glColor3f(1.f, 1.f, 1.f);
    glBegin(GL_QUADS);
        glVertex2d(pos[0][0] + 0.1, pos[0][1] + 0.1);
        glVertex2d(pos[0][0] + 0.9, pos[0][1] + 0.1);
        glVertex2d(pos[0][0] + 0.9, pos[0][1] + 0.9);
        glVertex2d(pos[0][0] + 0.1, pos[0][1] + 0.9);
    glEnd();

    glColor3f(1.f, 1.f, 0.f);
    for(int i = 1; i < getLength(); i++)
    {
        glBegin(GL_QUADS);
            glVertex2d(pos[i][0] + 0.1, pos[i][1] + 0.1);
            glVertex2d(pos[i][0] + 0.9, pos[i][1] + 0.1);
            glVertex2d(pos[i][0] + 0.9, pos[i][1] + 0.9);
            glVertex2d(pos[i][0] + 0.1, pos[i][1] + 0.9);
        glEnd();
    }
}

void Snake::handleKeyPress(unsigned char key)
{
    if (isChangingDirection())
    {
        setChangingDirection(false);
        switch(key)
        {
            case 'w':
            if (getDirection() != SnakeDirection::Down)
                setDirection(SnakeDirection::Up);
            break;

            case 'a':
            if (getDirection() != SnakeDirection::Right)
                setDirection(SnakeDirection::Left);
            break;

            case 's':
            if (getDirection() != SnakeDirection::Up)
                setDirection(SnakeDirection::Down);
            break;

            case 'd':
            if (getDirection() != SnakeDirection::Left)
                setDirection(SnakeDirection::Right);
            break;

            default:
            break;
        }
    }
}

void Snake::handleSpecialKeyPress(int key)
{
    if (isChangingDirection())
    {
        setChangingDirection(false);
        switch(key)
        {
            case GLUT_KEY_UP:
            if (getDirection() != SnakeDirection::Down)
                setDirection(SnakeDirection::Up);
            break;

            case GLUT_KEY_LEFT:
            if (getDirection() != SnakeDirection::Right)
                setDirection(SnakeDirection::Left);
            break;

            case GLUT_KEY_DOWN:
            if (getDirection() != SnakeDirection::Up)
                setDirection(SnakeDirection::Down);
            break;

            case GLUT_KEY_RIGHT:
            if (getDirection() != SnakeDirection::Left)
                setDirection(SnakeDirection::Right);
            break;

            default:
            break;
        }
    }
}