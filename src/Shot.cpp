#include "Shot.h"
#include "Polygon.h"
#include "../LUtil.h"

Shot::Shot(){
    loop_vertex.push_back(Dot(0,0));
    loop_vertex.push_back(Dot(4,0));

    color[RED] = 0;
    color[GREEN] = 1;
    color[BLUE] = 1;

    iterations_left = 0;
}

void Shot::setIterationsLeft(long iterations){
    iterations_left = iterations;
}

long Shot::getIterationsLeft(){
    return iterations_left;
}

void Shot::reduceIterationsLeft(){
    iterations_left--;
}

bool Shot::hasIterationsLeft(){
    return (iterations_left > 0)? true : false;
}

Shot::~Shot()
{
    //dtor
}
