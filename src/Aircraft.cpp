#include "Aircraft.h"
#include "../LUtil.h"

Aircraft::Aircraft(int m){

    switch(m){
        case 0:
            loop_vertex.push_back(Dot(-6,6));
            loop_vertex.push_back(Dot(5,0));
            loop_vertex.push_back(Dot(-6,-6));
            loop_vertex.push_back(Dot(0,0));
        break;
        case 1:
            loop_vertex.push_back(Dot(-3, 5));
            loop_vertex.push_back(Dot(-3, -5));
            loop_vertex.push_back(Dot(5, 0));
            lines_vertex.push_back(Dot(5, 0));
            lines_vertex.push_back(Dot(8, 0));
        break;
        case 2:
            loop_vertex.push_back(Dot(-3, 5));
            loop_vertex.push_back(Dot(5, 0));
            loop_vertex.push_back(Dot(-3, -5));
            lines_vertex.push_back(Dot(-3, 5));
            lines_vertex.push_back(Dot(1, 5));
            lines_vertex.push_back(Dot(-3, -5));
            lines_vertex.push_back(Dot(1, -5));
        break;
    }

    model = m;


    color[RED] = 1;
    color[GREEN] = 1;
    color[BLUE] = 1;

    position = Dot(0,0);
    speed = Dot(0,0);
    direction = 0;

    acceleration = 0.05;
    handling = 2.5;
}

void Aircraft::catchItem(Item *item){
    switch(item->getType()){
        case SHIELD:
            //
        break;
        case BACK:
            //
        break;
        case DUAL:
            //
        break;
        case FAST:
            //
        break;
        case LONG:
            //
        break;
        case HANDLING:
            if(handling < 6){
                handling += 1.5;
            }
        break;
        case BOOST:
            if(acceleration < 0.2){
                acceleration += 0.05;
            }
        break;
    }

    delete item;
}

Aircraft::~Aircraft()
{
    //dtor
}
