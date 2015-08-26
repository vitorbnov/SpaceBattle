#include "Shot.h"
#include "Polygon.h"
#include "../LUtil.h"

Shot::Shot(){
    loop_vertex.push_back(Dot(0,0));
    loop_vertex.push_back(Dot(3,0));

    color[RED] = 1;
    color[GREEN] = 0.5;
    color[BLUE] = 0;
}

void Shot::setActive(bool a){
    active = a;
}

bool Shot::getActive(){
    return active;
}

Shot::~Shot()
{
    //dtor
}
