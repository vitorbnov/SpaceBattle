#include <time.h>

#include "../LUtil.h"
#include "Aircraft.h"

Aircraft::Aircraft(int m){
    model = m;
    shield = 0;
    dual = false;
    back_shot = false;
    delay_time_shooting = 40;
    last_time_shooting = -delay_time_shooting;
    iterations_range_shooting = 30;

    switch(m){
        case 0:
            loop_vertex.push_back(Dot(-6,6));
            loop_vertex.push_back(Dot(5,0));
            loop_vertex.push_back(Dot(-6,-6));
            loop_vertex.push_back(Dot(0,0));
            guns.push_back(Gun(0, Dot(7,0)));
            shield_vertex.push_back(Dot(-8, 10));
            shield_vertex.push_back(Dot(-8, -10));
            shield_vertex.push_back(Dot(9, 0));
        break;
        case 1:
            loop_vertex.push_back(Dot(-3, 5));
            loop_vertex.push_back(Dot(-3, -5));
            loop_vertex.push_back(Dot(5, 0));
            lines_vertex.push_back(Dot(5, 0));
            lines_vertex.push_back(Dot(8, 0));
            guns.push_back(Gun(0, Dot(10, 0)));
            shield_vertex.push_back(Dot(-5, 8));
            shield_vertex.push_back(Dot(-5, -8));
            shield_vertex.push_back(Dot(9, 0));
            upgradeStat(LONG);
        break;
        case 2:
            loop_vertex.push_back(Dot(-3, 5));
            loop_vertex.push_back(Dot(5, 0));
            loop_vertex.push_back(Dot(-3, -5));
            lines_vertex.push_back(Dot(-3, 5));
            lines_vertex.push_back(Dot(1, 5));
            lines_vertex.push_back(Dot(-3, -5));
            lines_vertex.push_back(Dot(1, -5));
            guns.push_back(Gun(0,Dot(2, 5)));
            guns.push_back(Gun(0,Dot(2, -5)));
            shield_vertex.push_back(Dot(-4, 7));
            shield_vertex.push_back(Dot(0, 7));
            shield_vertex.push_back(Dot(8, 0));
            shield_vertex.push_back(Dot(0, -7));
            shield_vertex.push_back(Dot(-4, -7));
            dual = true;
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
            guns.push_back(Gun(0,Dot(7,0)));
            guns.push_back(Gun(120,Dot(-3,5)));
            guns.push_back(Gun(-120,Dot(-3,-5)));
            shield_vertex.push_back(Dot(8, 0));
            shield_vertex.push_back(Dot(-4.5, 8));
            shield_vertex.push_back(Dot(-4.5, -8));
        break;
        /*case 4:
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
        break;*/
    }
}

void Aircraft::setShield(int value){
    shield = value;
}

void Aircraft::setDelayTimeShooting(int number_of_iterations){
    delay_time_shooting = number_of_iterations;
}

void Aircraft::setLastTimeShooting(int last_iteration){
    last_time_shooting = last_iteration;
}

void Aircraft::setIterationsRangeShooting(long iterations_range){
    iterations_range_shooting = iterations_range;
}

int Aircraft::getModel(){
    return model;
}

int Aircraft::getShield(){
    return shield;
}

int Aircraft::getDelayTimeShooting(){
    return delay_time_shooting;
}

int Aircraft::getLastTimeShooting(){
    return last_time_shooting;
}

long Aircraft::getIterationsRangeShooting(){
    return iterations_range_shooting;
}

bool Aircraft::isShielded(){
    return (shield > 0) ? true : false;
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
            setShield(MAX_SHIELD);
        break;
        /*case BACK:
            if(model == 0 && !back_shot){
                lines_vertex.push_back(Dot(-2, 0));
                lines_vertex.push_back(Dot(0, 0));
                guns.push_back(Gun(180,Dot(-1, 0)));
                back_shot = true;
            }
        break;*/
        case DUAL:
            if(model != 2 && !dual){
                lines_vertex.push_back(Dot(0, 3));
                lines_vertex.push_back(Dot(3, 3));
                lines_vertex.push_back(Dot(0, -3));
                lines_vertex.push_back(Dot(3, -3));
                guns.erase(guns.begin());
                guns.push_back(Gun(0,Dot(3, 3)));
                guns.push_back(Gun(0,Dot(3, -3)));
                dual = true;
            }
        break;
        case FAST:
            if(delay_time_shooting > MIN_DELAY_TIME_SHOOTING){
                delay_time_shooting /= 2;
            }
        break;
        case LONG:
            if(iterations_range_shooting < MAX_ITERATIONS_RANGE_SHOOTING){
                iterations_range_shooting += 15;
            }
        break;
        case HANDLING:
            if(handling < MAX_HANDLING){
                handling++;
            }
        break;
        case BOOST_ITEM:
            if(acceleration < MAX_ACCELERATION){
                acceleration += 0.02;
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

void Aircraft::damageShield(int damage_val){
    if(shield > damage_val){
        shield -= damage_val;
    }
    else{
        shield = 0;
    }
}
/*
void Aircraft::resetStats(){

        int shield;
        bool dual;
        bool back_shot;
        long delay_time_shooting;
        long last_time_shooting;
        long iterations_range_shooting;
        std::vector<Dot> shield_vertex;
        std::vector<Gun> guns;

    switch(model){
        case 0:
            if(dual){
                lines_vertex.pop_back();
                lines_vertex.pop_back();
                lines_vertex.pop_back();
                lines_vertex.pop_back();
                guns.pop_back();
                guns.pop_back();
                guns.push_back(Gun(0, Dot(7,0)));
            }
            if(back_shot){


            }
            break;
        case 1:

            break;
        case 2:

            break;
    }
    setShield(0);
}
*/

/*void Aircraft::iterate(){
    Polygon::iterate();

}*/

void Aircraft::draw(){
    Polygon::draw();
    Dot d;
    if(shield > 0){
        glColor3f((GLfloat)shield/50, (GLfloat)shield/50, (GLfloat)shield/50);
        glBegin(GL_LINE_LOOP);
        for(int i=0; i<shield_vertex.size(); i++){
            d = shield_vertex.at(i);
            glVertex2f(d.getX(), d.getY());
        }
        glEnd();
    }
}

Aircraft::~Aircraft()
{
    //dtor
}
