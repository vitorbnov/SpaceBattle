#include <time.h>

#include "../LUtil.h"
#include "Aircraft.h"

Aircraft::Aircraft(int m){

    switch(m){
        case 0:
            loop_vertex.push_back(Dot(-6,6));
            loop_vertex.push_back(Dot(5,0));
            loop_vertex.push_back(Dot(-6,-6));
            loop_vertex.push_back(Dot(0,0));
            guns.push_back(Gun(0,Dot(6,0)));
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
        case 3:
            loop_vertex.push_back(Dot(-3, 5));
            loop_vertex.push_back(Dot(5, 0));
            loop_vertex.push_back(Dot(-3, -5));
            lines_vertex.push_back(Dot(0,0));
            lines_vertex.push_back(Dot(-3, 5));
            lines_vertex.push_back(Dot(0,0));
            lines_vertex.push_back(Dot(5, 0));
            lines_vertex.push_back(Dot(0,0));
            lines_vertex.push_back(Dot(-3, -5));
            guns.push_back(Gun(0,Dot(5,0)));
            guns.push_back(Gun(120,Dot(-3,5)));
            guns.push_back(Gun(-120,Dot(-3,-5)));
        break;
        case 4:
            loop_vertex.push_back(Dot(5, 0));
            loop_vertex.push_back(Dot(0, 5));
            loop_vertex.push_back(Dot(-5, 0));
            loop_vertex.push_back(Dot(0, -5));
            lines_vertex.push_back(Dot(5, 0));
            lines_vertex.push_back(Dot(-5, 0));
            lines_vertex.push_back(Dot(0, 5));
            lines_vertex.push_back(Dot(0, -5));

            guns.push_back(Gun(0,Dot(5, 0)));
            guns.push_back(Gun(90,Dot(0, 5)));
            guns.push_back(Gun(180, Dot(-5,0)));
            guns.push_back(Gun(270, Dot(0, -5)));
        break;
        case 5:
            loop_vertex.push_back(Dot(5, 0));
            loop_vertex.push_back(Dot(2, 5));
            loop_vertex.push_back(Dot(-4, 3));
            loop_vertex.push_back(Dot(-4, -3));
            loop_vertex.push_back(Dot(2, -5));
            lines_vertex.push_back(Dot(5, 0));
            lines_vertex.push_back(Dot(0, 0));
            lines_vertex.push_back(Dot(2, 5));
            lines_vertex.push_back(Dot(0, 0));
            lines_vertex.push_back(Dot(-4, 3));
            lines_vertex.push_back(Dot(0, 0));
            lines_vertex.push_back(Dot(-4, -3));
            lines_vertex.push_back(Dot(0, 0));
            lines_vertex.push_back(Dot(2, -5));
            lines_vertex.push_back(Dot(0, 0));

            guns.push_back(Gun(0, Dot(5, 0)));
            guns.push_back(Gun(72, Dot(2, 5)));
            guns.push_back(Gun(144, Dot(-4, 3)));
            guns.push_back(Gun(-144, Dot(-4, -3)));
            guns.push_back(Gun(-72, Dot(2, -5)));
        break;
    }
    model = m;
    dual = false;
    back_shot = false;
    delay_time_shooting = 30;
    last_time_shooting = -delay_time_shooting;
    iterations_range_shooting = 40;
}

void Aircraft::setDelayTimeShooting(long number_of_iterations){
    delay_time_shooting = number_of_iterations;
}

void Aircraft::setLastTimeShooting(long last_iteration){
    last_time_shooting = last_iteration;
}

void Aircraft::setIterationsRangeShooting(long iterations_range){
    iterations_range_shooting = iterations_range;
}

long Aircraft::getDelayTimeShooting(){
    return delay_time_shooting;
}

long Aircraft::getLastTimeShooting(){
    return last_time_shooting;
}

long Aircraft::getIterationsRangeShooting(){
    return iterations_range_shooting;
}

bool Aircraft::canShoot(long iteration){
    return ( last_time_shooting + delay_time_shooting - iteration <= 0) ? true : false;
}

void Aircraft::catchItem(Item *item){
    upgradeStat(item->getType());
}

void Aircraft::upgradeStat(int stat){
    switch(stat){
        case SHIELD:
            //
        break;
        case BACK:
            if(model == 0 && !back_shot){
                lines_vertex.push_back(Dot(-2, 0));
                lines_vertex.push_back(Dot(0, 0));
                guns.push_back(Gun(180,Dot(-1, 0)));
                back_shot = true;
            }
        break;
        case DUAL:
            if(model == 0 && !dual){
                lines_vertex.push_back(Dot(-1, 3));
                lines_vertex.push_back(Dot(3, 3));
                lines_vertex.push_back(Dot(-1, -3));
                lines_vertex.push_back(Dot(3, -3));
                guns.erase(guns.begin());
                guns.push_back(Gun(0,Dot(3, 3)));
                guns.push_back(Gun(0,Dot(3, -3)));
                dual = true;
            }
        break;
        case FAST:
            delay_time_shooting /= 2;
        break;
        case LONG:
            iterations_range_shooting += 20;
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

int Aircraft::getGuns(){
    return guns.size();
}

Gun Aircraft::getGunAt(int index){
   return guns.at(index);
}

Aircraft::~Aircraft()
{
    //dtor
}
