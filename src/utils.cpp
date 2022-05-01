#include <iostream>
#include <string>
#include <GL/freeglut.h>
#include "Snake.h"

Snake *s;
bool isGameOver = false;
bool isGamePaused = false;

void setSnake(Snake *newSnake)
{
    s = newSnake;
}

void setGameOver(bool gameOver)
{
    isGameOver = gameOver;
}

void setGamePaused(bool paused)
{
    isGamePaused = paused;
}

bool getIsGameOver()
{
    return isGameOver;
}

bool getIsGamePaused()
{
    return isGamePaused;
}

void snakeMovement(int direction)
{
    if (!isGamePaused)
    {
        if (s->isGrowing())
        {
            for (int i = s->getLength(); i > 0; i--)
            {
                s->pos[i + 1][0] = s->pos[i][0];
                s->pos[i + 1][1] = s->pos[i][1];
            }

            s->pos[1][0] = s->pos[0][0];
            s->pos[1][1] = s->pos[0][1];
            s->setLength(s->getLength() + 1);
            s->setGrowing(false);
        }

        else
        {
            s->grid[s->pos[s->getLength()-1][0]][s->pos[s->getLength()-1][1]] = 0;
            for (int i = s->getLength() - 1; i > 0; i--)
            {
                s->pos[i][0] = s->pos[i - 1][0];
                s->pos[i][1] = s->pos[i - 1][1];
            }   
        }

        switch(direction)
        {
            case SnakeDirection::Up:
                s->pos[0][1]++;
                break;
            case SnakeDirection::Down:
                s->pos[0][1]--;
                break;
            case SnakeDirection::Left:
                s->pos[0][0]--;
                break;
            case SnakeDirection::Right:
                s->pos[0][0]++;
                break;
        }

        if(s->grid[(s->pos[0][0])][(s->pos[0][1])] == 1)
        {
            isGameOver = true;
        }
        
        else
        {
            s->grid[s->pos[0][0]][s->pos[0][1]] = 1;
        }
        
        s->setChangingDirection(true);

        if((s->pos[0][0] < 0 || s->pos[0][0] > (COLS-1) || s->pos[0][1] < 0 || s->pos[0][1] > (ROWS-1)) || isGameOver)
        {
            isGameOver = true;
        }

        else
        {
            glutTimerFunc(150, snakeMovement, s->getDirection());
        }
    }

    else
    {
        glutTimerFunc(150, snakeMovement, s->getDirection());
    }
}

void printText(int x, int y, std::string text, void *font = GLUT_BITMAP_TIMES_ROMAN_24) 
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, COLS, 0, ROWS, -1.f, 1.f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glPushAttrib(GL_DEPTH_TEST);
    glDisable(GL_DEPTH_TEST);
    glRasterPos2i(x, y);
    for (int i = 0; i < (int)text.size(); i++)
    {
        glScaled(0.2, 0.2, 1);
        glutBitmapCharacter(font, text[i]);
    }
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void checkGame()
{
    if (!isGameOver && !isGamePaused)
    {
        printText(17, 39, "Score: " + std::to_string((s->getLength() - 3) * 10), GLUT_BITMAP_HELVETICA_18);
    }

    if (isGamePaused)
    {
        glColor4d(0, 0, 0, 0.8);
        glBegin(GL_QUADS);
            glVertex2d(0, 0);
            glVertex2d(0, 40);
            glVertex2d(40, 40);
            glVertex2d(40, 0);
        glEnd();
        glColor3d(1, 1, 1);
        printText(17, 20, "PAUSED");
        printText(14, 18, "Press 'P' to resume");
        printText(15, 16, "  Your score: " + std::to_string((s->getLength() - 3) * 10));
    }

    else if(isGameOver)
    {
        glColor4d(0, 0, 0, 0.8);
        glBegin(GL_QUADS);
            glVertex2d(0, 0);
            glVertex2d(0, 40);
            glVertex2d(40, 40);
            glVertex2d(40, 0);
        glEnd();
        glColor3d(1, 1, 1);
        printText(15, 20, "GAME OVER");
        printText(14, 18, "       Your score: " + std::to_string((s->getLength() - 3) * 10), GLUT_BITMAP_HELVETICA_18);
        printText(14, 16, "Press 'R' to restart");
    }
}