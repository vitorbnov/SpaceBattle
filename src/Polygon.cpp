#include "Polygon.h"
#include "../LUtil.h"
#include <cmath>

void Polygon::setColor(float red, float green, float blue){
    color[RED] = red;
    color[GREEN] = green;
    color[BLUE] = blue;
}
void Polygon::setPosition(Dot p){
    position = p;
}
void Polygon::setSpeed(Dot s){
    speed = s;
}
void Polygon::setDirection(float d){
    direction = d;
}
void Polygon::setAcceleration(float a){
    acceleration = a;
}
void Polygon::setHandling(float ){

}

float* Polygon::getColor(){
    return color;
}
Dot Polygon::getPosition(){
    return position;
}
Dot Polygon::getSpeed(){
    return speed;
}
float Polygon::getDirection(){
    return direction;
}
float Polygon::getAcceleration(){
    return acceleration;
}
float Polygon::getHandling(){
    return handling;
}


float Polygon::getSpeedModule(){
    return speed.module();
}

void Polygon::turnLeft(){
    direction += handling;
}

void Polygon::turnRight(){
    direction -= handling;
}

void Polygon::updatePosition(){
    position = position + speed;
}

void Polygon::updateSpeed(bool boosting){
    if(boosting){
        speed = speed + Dot((float)acceleration*cos(direction*PI/180), (float)acceleration*sin(direction*PI/180));
    }
}

void Polygon::iterate(bool boosting){
    updateSpeed(boosting);
    updatePosition();
}

void Polygon::draw(){
    unsigned int i;
    Dot d;

    glLoadIdentity();
    glTranslatef(position.getX(), position.getY(), 0);
    glRotated(direction, 0, 0, 1);
    glColor3f(color[RED], color[GREEN], color[BLUE]);
    glBegin(GL_LINES);
        for(i=0; i<lines_vertex.size(); i++){
            d = lines_vertex.at(i);
            glVertex2f(d.getX(), d.getY());
        }
    glEnd();
    glBegin(GL_LINE_STRIP);
        for(i=0; i<strip_vertex.size(); i++){
            d = strip_vertex.at(i);
            glVertex2f(d.getX(), d.getY());
        }
    glEnd();
    glBegin(GL_LINE_LOOP);
        for(i=0; i<loop_vertex.size(); i++){
            d = loop_vertex.at(i);
            glVertex2f(d.getX(), d.getY());
        }
    glEnd();
}

Polygon::~Polygon(){
    lines_vertex.clear();
    strip_vertex.clear();
    loop_vertex.clear();
}
