#include "Item.h"
#include "../LUtil.h"

Item::Item(int value){
    switch(value){
        case SHIELD:
            loop_vertex.push_back(Dot(0,3));
            loop_vertex.push_back(Dot(1,3));
            loop_vertex.push_back(Dot(4,2));
            loop_vertex.push_back(Dot(3,-3));
            loop_vertex.push_back(Dot(1,-5));
            loop_vertex.push_back(Dot(0,-6));
            loop_vertex.push_back(Dot(-1,-5));
            loop_vertex.push_back(Dot(-3,-3));
            loop_vertex.push_back(Dot(-4, 2));
            loop_vertex.push_back(Dot(-1,3));
            strip_vertex.push_back(Dot(0, 2));
            strip_vertex.push_back(Dot(3, 1));
            strip_vertex.push_back(Dot(2, -3));
            strip_vertex.push_back(Dot(0, -5));
            strip_vertex.push_back(Dot(-2, -3));
            strip_vertex.push_back(Dot(-3, 1));
            strip_vertex.push_back(Dot(0, 2));
        break;
        case BACK:
            loop_vertex.push_back(Dot(-3, 5));
            loop_vertex.push_back(Dot(-3, -5));
            loop_vertex.push_back(Dot(6, 0));
            lines_vertex.push_back(Dot(-3, 0));
            lines_vertex.push_back(Dot(-1, 0));
        break;
        case DUAL:
            loop_vertex.push_back(Dot(-3, 5));
            loop_vertex.push_back(Dot(-3, -5));
            loop_vertex.push_back(Dot(6, 0));
            lines_vertex.push_back(Dot(-3, 1));
            lines_vertex.push_back(Dot(0, 1));
            lines_vertex.push_back(Dot(-3, -1));
            lines_vertex.push_back(Dot(0, -1));
        break;
        case FAST:
            loop_vertex.push_back(Dot(-3, 5));
            loop_vertex.push_back(Dot(-3, -5));
            loop_vertex.push_back(Dot(6, 0));
            lines_vertex.push_back(Dot(-3, 0));
            lines_vertex.push_back(Dot(-1, 0));
            lines_vertex.push_back(Dot(6, 0));
            lines_vertex.push_back(Dot(2, 0));
        break;
        case LONG:
            loop_vertex.push_back(Dot(-3, 5));
            loop_vertex.push_back(Dot(-3, -5));
            loop_vertex.push_back(Dot(6, 0));
            lines_vertex.push_back(Dot(-3, 0));
            lines_vertex.push_back(Dot(6, 0));
        break;
        case HANDLING:
            loop_vertex.push_back(Dot(-3, 5));
            loop_vertex.push_back(Dot(-3, -5));
            loop_vertex.push_back(Dot(6, 0));
            strip_vertex.push_back(Dot(-3, 3));
            strip_vertex.push_back(Dot(4, 0));
            strip_vertex.push_back(Dot(-3, -3));
        break;
        case BOOST:
            loop_vertex.push_back(Dot(-3, 5));
            loop_vertex.push_back(Dot(-3, -5));
            loop_vertex.push_back(Dot(6, 0));
            strip_vertex.push_back(Dot(-2,2));
            strip_vertex.push_back(Dot(2,0));
            strip_vertex.push_back(Dot(-2, -2));
        break;
    }

    id = value;

    color[RED] = 1;
    color[GREEN] = 0;
    color[BLUE] = 1;

}

int Item::getType(){
    return id;
}

Item::~Item()
{
    //dtor
}
