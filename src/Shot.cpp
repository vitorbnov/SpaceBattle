#include "Shot.h"
#include "Polygon.h"
#include "../LUtil.h"

Shot::Shot(){
    lines_vertex.push_back(Dot(0,0));
    lines_vertex.push_back(Dot(2,0));

    color[RED] = 0;
    color[GREEN] = 0;
    color[BLUE] = 1;
}

Shot::~Shot()
{
    //dtor
}
