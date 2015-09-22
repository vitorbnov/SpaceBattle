#include "../LUtil.h"
#include "GameObj.h"
#include "Circle.h"
#include <cmath>

Circle::Circle(int r){
    radius = r;
    setColor(0.5, 0.5, 0.5);
}

void Circle::draw(){
    float x, y;

    x = 0;
    y = radius;

    glLoadIdentity();
    glTranslatef(position.getX(), position.getY(), 0);
    glColor3f(color[RED], color[GREEN], color[BLUE]);
    glBegin(GL_POINTS);
        while(y/x >= 1){
            glVertex2f(x, y);
            glVertex2f(x, -y);
            glVertex2f(-x, y);
            glVertex2f(-x, -y);
            glVertex2f(y, x);
            glVertex2f(y, -x);
            glVertex2f(-y, x);
            glVertex2f(-y, -x);
            if(pow(x+1, 2) + pow(y-0.5, 2) - radius*radius > 0){
                y--;
            }
            x++;
        }
    glEnd();
}

Circle::~Circle()
{
    //dtor
}
