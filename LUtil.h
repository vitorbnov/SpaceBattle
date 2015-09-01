/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 001

#ifndef LUTIL_H
#define LUTIL_H

#include "LOpenGL.h"
#include <iostream>
#include <cstdlib>

#define PI 3.14159265358979323846

#define XMIN -200
#define XMAX 200
#define YMIN -200
#define YMAX 200

//Screen Constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_FPS = 60;

enum Color{
    RED=0,
    GREEN,
    BLUE
};

// Key Handling
void initKeys(void);
void keyPressed(unsigned char, int, int); // Set the state of the current key to pressed
void keyUp(unsigned char, int, int); // Set the state of the current key to not pressed
void keyOperations(void); // Handle keys here
void keySpecial(int, int, int);
void keySpecialUp(int, int, int);
void keySpecialOperations(void);


bool initGL();
/*
Pre Condition:
 -A valid OpenGL context
Post Condition:
 -Initializes matrices and clear color
 -Reports to console if there was an OpenGL error
 -Returns false if there was an error in initialization
Side Effects:
 -Projection matrix is set to identity matrix
 -Modelview matrix is set to identity matrix
 -Matrix mode is set to modelview
 -Clear color is set to black
*/

void update();
/*
Pre Condition:
 -None
Post Condition:
 -Does per frame logic
Side Effects:
 -None
*/

void render();
/*
Pre Condition:
 -A valid OpenGL context
 -Active modelview matrix
Post Condition:
 -Renders the scene
Side Effects:
 -Clears the color buffer
 -Swaps the front/back buffer
*/

void initGame();
void clearGame();
#endif
