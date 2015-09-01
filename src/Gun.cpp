#include "Gun.h"

Gun::Gun(){
    direction = 0;
    position = Dot(0,0);
}

Gun::Gun(float dir, Dot pos){
    direction = dir;
    position = pos;
}


void Gun::setDirection(float degrees){
    direction = degrees;
}

void Gun::setPosition(Dot pos){
    position = pos;
}

float Gun::getDirection(){
    return direction;
}

Dot Gun::getPosition(){
    return position;
};


Gun::~Gun()
{
    //dtor
}
