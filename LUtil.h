/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 001

#ifndef LUTIL_H
#define LUTIL_H

#include "LOpenGL.h"
#include "include/Dot.h"
#include <iostream>
#include <cstdlib>

#define PI 3.14159265358979323846

#define XMIN -400
#define XMAX 400
#define YMIN -400
#define YMAX 400

//Screen Constants
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 920;
const int SCREEN_FPS = 60;

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

bool isInterceptingSegments(Dot, Dot, Dot, Dot);
void initGame();
void clearGame();
#endif
