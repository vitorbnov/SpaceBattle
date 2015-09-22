#include "GameObj.h"
#include "Drawing.h"

Drawing::Drawing(){
    setColor(1, 1, 1);
}

void Drawing::setColor(float red, float green, float blue){
    color[RED] = red;
    color[GREEN] = green;
    color[BLUE] = blue;
}

float* Drawing::getColor(){
    return color;
}


Drawing::~Drawing(){
    //dtor
}
