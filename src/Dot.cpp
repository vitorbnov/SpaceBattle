#include "Dot.h"
#include <cmath>

Dot::Dot(){
    x = 0;
    y = 0;
}

Dot::Dot(float xin, float yin){
    x = xin;
    y = yin;
}

// Setters
void Dot::setX(float value){
    x = value;
}
void Dot::setY(float value){
    y = value;
}

// Getters
float Dot::getX(){
    return x;
}
float Dot::getY(){
    return y;
}

Dot Dot::operator+(Dot p){
    float a, b;

    a = x + p.x;
    b = y + p.y;

    return Dot(a, b);
}

Dot Dot::operator-(Dot p){
    float a, b;

    a = x - p.x;
    b = y - p.y;

    return Dot(a, b);
}

float Dot::triangleArea(Dot b, Dot c){
    float bx = b.getX();
    float by = b.getY();
    float cx = c.getX();
    float cy = c.getY();
    return 0.5*(x*by + y*bx + y*cx - x*cy + bx*cy + by*cx);
}

float Dot::module(){
    return sqrt(x*x + y*y);
}

Dot::~Dot(){

}
