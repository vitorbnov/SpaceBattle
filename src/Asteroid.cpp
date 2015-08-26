#include "../LUtil.h"
#include "Asteroid.h"
#include <cstdlib>
#include <cmath>
#include <ctime>

Asteroid::Asteroid(int ast_size){
    int i, gen, dots, interval, angle, radius, min_radius, delta_radius;
    Asteroid* ast;
    Dot d;

    item = NULL;
    dots = 3*pow(2,ast_size);
    interval = 360/dots;
    min_radius = 6*pow(2,ast_size);
    delta_radius = 1.5*min_radius;

    srand(time(NULL));
    //Generating vertex
    for(i=0; i<dots; i++){
        angle = rand()%interval + i*interval;
        radius = rand()%delta_radius + min_radius;

        d.setX(radius*cos(angle*PI/180));
        d.setY(radius*sin(angle*PI/180));
        loop_vertex.push_back(d);
    }


    if(ast_size != SMALL){
        //Generating subparts
        gen = 1+rand()%2;
        while(gen>0){
            ast = new Asteroid(SMALL);
            parts.push_back(ast);
            gen--;
        }
    }

    if(ast_size == BIG){
        //Generating item
        gen = rand()%21;
        if(gen%3 == 0){
            item = new Item(gen/3);
        }
    }

    //Adjusting centroid

    setColor(0, 1, 0);
    setHandling(1);
}

void Asteroid::setItem(Item* it){
    item = it;
}

void Asteroid::setParts(std::vector<Asteroid*> p){
    parts = p;
}

Item* Asteroid::getItem(){
    return item;
}

std::vector<Asteroid*> Asteroid::getParts(){
    return parts;
}

Asteroid::~Asteroid()
{
    //dtor
}