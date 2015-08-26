#include "Aircraft.h"
#include "../LUtil.h"

Aircraft::Aircraft(int m){

    switch(m){
        case 0:
            loop_vertex.push_back(Dot(-6,6));
            loop_vertex.push_back(Dot(5,0));
            loop_vertex.push_back(Dot(-6,-6));
            loop_vertex.push_back(Dot(0,0));
            shot_dots.push_back(Dot(6,0));
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
    next_shot = 0;

    for(int i=0; i<NUM_SHOTS; i++){
        shots[i].setColor(0, 1, 1);
        shots[i].setActive(false);
    }
}

void Aircraft::catchItem(Item *item){
    upgradeStat(item->getType());

    //delete item;
}

void Aircraft::upgradeStat(int stat){
    switch(stat){
        case SHIELD:
            //
        break;
        case BACK:
            //shot_dots.push_back(Dot(-1,0));
        break;
        case DUAL:
            setColor(1, 0, 1);
            //shot_dots.erase(shot_dots.begin());
            //shot_dots.push_back(Dot(6, 0.5));
            //shot_dots.push_back(Dot(6, -0.5));
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
}

Aircraft::~Aircraft()
{
    //dtor
}
