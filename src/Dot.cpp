#include "../LUtil.h"
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

float Dot::operator*(Dot p){
    return (x*p.getX() + y*p.getY());
}

Dot Dot::operator*(float k){
    float a, b;

    a = x*k;
    b = x*k;

    return Dot(a, b);
}

float Dot::whichSide(Dot a, Dot b){
    float xa = a.getX();
    float ya = a.getY();
    float xb = b.getX();
    float yb = b.getY();

    return (xa*yb - ya*xb + y*(xb-xa) + x*(ya-yb));
}

float Dot::module(){
    return sqrt(x*x + y*y);
}

float Dot::angle(){
    return (atan2(y, x));//*180/PI
}

Dot Dot::transf(float rotatee, Dot translade){
    Dot p;
    p.setX(x*cos(rotatee*PI/180)-y*sin(rotatee*PI/180));
    p.setY(x*sin(rotatee*PI/180) + y*cos(rotatee*PI/180));
    return (p + translade);
}

Dot::~Dot(){

}

