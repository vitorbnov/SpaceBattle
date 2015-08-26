#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Game.h"
#include "Polygon.h"
#include "Aircraft.h"

Game::Game(){
    interceptions = 0;
    item = new Item(DUAL);
    aircrafts[0] = new Aircraft(0);
    aircrafts[1] = new Aircraft(1);
    aircrafts[2] = new Aircraft(2);
    player = aircrafts[0];

    aircrafts[0]->setColor(1, 0, 0);
    aircrafts[1]->setColor(1, 0, 0);
    aircrafts[2]->setColor(1, 0, 0);

    asteroid = new Asteroid(BIG);
    asteroid->setColor(0, 1, 0);
    asteroid->setSpeed(Dot(0.5, 1));
    asteroid->setHandling(1);
    asteroid->setPosition(Dot(0, 100));
    asteroid->centralize();

    item->setPosition(Dot(-50, 50));
    item->setSpeed(Dot(-1, -0.5));

    shot = new Shot();
    shot->setPosition(Dot(10,-10));
    shot->setDirection(-30);
    shot->setSpeed(330*PI/180, 2);
}

void Game::setPlayer(Aircraft *p){
    player = p;
}

Aircraft* Game::getPlayer(){
    return player;
}

void Game::iterate(bool boosting, bool turning_left, bool turning_right){
    player->iterate(boosting, turning_left, turning_right);
    asteroid->iterate(false, false, true);
    item->iterate(false, false, false);
    shot->iterate(false, false, false);

    if(player->isInterceptingPolygon(item)){
        interceptions++;
        player->catchItem(item);
    }
    if(player->isInsideOfPolygon(asteroid)){
        player->setColor(0,1,0);
        interceptions++;
    }
    if(player->isInterceptingPolygon(shot)){
        player->setColor(1,0.5,0);
        interceptions++;
    }
}

void Game::draw(void){
    if(player != NULL) player->draw();
    if(asteroid != NULL) asteroid->draw();
    if(item != NULL) item->draw();
    if(shot != NULL) shot->draw();

    std::string word;

    word = std::to_string(interceptions);

    printWord(0, 0, word.c_str(), GLUT_BITMAP_TIMES_ROMAN_10);
}

void Game::printWord(float x, float y, const char *str, void *font){
    glLoadIdentity();
    int len, i;
    glRasterPos2f(x, y);
    len = (int) strlen(str);
    for(i=0; i<len; i++){
        glutBitmapCharacter(font, str[i]);
    }
}

Game::~Game(){
    delete asteroid;
    delete aircrafts[0];
    delete aircrafts[1];
    delete aircrafts[2];
    delete item;
    delete shot;
}
