#include <iostream>
#define FREEGLUT_STATIC
#include <GL/freeglut.h>
#include <time.h>
#include <math.h>
#include "Snake.hpp"
#include "Food.hpp"
#include "utils.hpp"

#ifdef WIN32
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

Food f;
Snake s;

void genRandomNumbers(int &x, int &y)
{
    do
    {
        x = rand() % 40;
        y = rand() % 40;
    } while(s.grid[x][y] == 1);

    x = rand() % 40;
    y = rand() % 40;
}

void checkFoodEaten()
{
    if (s.pos[0][0] == f.getFoodX() && s.pos[0][1] == f.getFoodY())
    {
        int x, y;
        genRandomNumbers(x, y);
        f.setFoodX(x);
        f.setFoodY(y);
        s.setGrowing(true);
    }
}

void init()
{
    setGameOver(false);
    setGamePaused(false);
    s = Snake();
    f = Food();
    int x, y;
    genRandomNumbers(x, y);
    f.setFoodX(x);
    f.setFoodY(y);
    setSnake(&s);
    glutTimerFunc(150, snakeMovement, s.getDirection());
}

static void keyPressHandle(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
            break;

        case 'p':
            setGamePaused(!getIsGamePaused());
            break;

        case 'r':
            if (getIsGameOver())
            {
                init();
            }
            break;

        default:
            s.handleKeyPress(key);
            break;
    }

    glutPostRedisplay();
}

static void specialKeyPressHandle(int key, int x, int y)
{
    s.handleSpecialKeyPress(key);

    glutPostRedisplay();
}

static void idleFunc()
{
    glutPostRedisplay();
}

static void resizeFunc(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, COLS, 0.0, ROWS, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glutReshapeWindow(700, 700);
    glLoadIdentity();
}

static void displayFunc()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    s.draw();
    f.draw();
    checkFoodEaten();
    checkGame();

    glutSwapBuffers();
}

int main(int argc, char **argv) 
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    glutCreateWindow("GLSnake");
    glutDisplayFunc(displayFunc);
    glutReshapeFunc(resizeFunc);
    glutKeyboardFunc(keyPressHandle);
    glutSpecialFunc(specialKeyPressHandle);
    glutIdleFunc(idleFunc);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(0, 0, 0, 1);
    glCullFace(GL_BACK);

    srand(time(NULL));
    init();

    glutMainLoop();
}