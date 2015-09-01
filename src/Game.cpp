#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Game.h"
#include "Polygon.h"
#include "Aircraft.h"

Game::Game(){
    iterations = 0;
    interceptions = 0;
    //aircrafts[0] = new Aircraft(0);
    //aircrafts[1] = new Aircraft(1);
    //aircrafts[2] = new Aircraft(2);
    //player = aircrafts[0];
    player = new Aircraft(0);
    player->centralize();
    player->setColor(1, 1, 0);

    //player->upgradeStat(BACK);
    //player->upgradeStat(DUAL);
    //player->upgradeStat(FAST);
    //player->upgradeStat(FAST);

    //aircrafts[0]->setColor(1, 0.5, 0);
    //aircrafts[1]->setColor(1, 0.5, 0);
    //aircrafts[2]->setColor(1, 0.5, 0);

    Asteroid *asteroid = new Asteroid(BIG);
    //asteroid->setColor(0, 1, 0);
    asteroid->setSpeed(Dot(0.5, 1));
    asteroid->setHandling(1);
    asteroid->setPosition(Dot(0, 100));
    asteroid->centralize();
    asteroids.push_back(asteroid);

    Shot *shot;
    for(int i=0; i<SHOTS_MAX; i++){
        shot = new Shot();
        to_shot.push_back(shot);
    }
}

void Game::setPlayer(Aircraft *p){
    player = p;
}

Aircraft* Game::getPlayer(){
    return player;
}

void Game::shoot(Aircraft* aircraft_shooting){
    int guns;
    Shot *shot;
    Gun gun;

    Dot aircraft_position = aircraft_shooting->getPosition();
    float aircraft_direction = aircraft_shooting->getDirection();

    guns = aircraft_shooting->getGuns();

    for(int i=0; i<guns; i++){
        gun = aircraft_shooting->getGunAt(i);

        //Remove from to_shot list
        shot = to_shot.back();
        to_shot.pop_back();

        //set values from aircraft state
        shot->setPosition(gun.getPosition().transf(aircraft_direction, aircraft_position));
        shot->setDirection(gun.getDirection() + aircraft_direction);
        shot->setSpeed(gun.getDirection() + aircraft_direction, MAX_SPEED);
        shot->setIterationsLeft(aircraft_shooting->getIterationsRangeShooting());

        aircraft_shooting->sumSpeed(shot->getDirection() + 180, 1.0/MAX_SPEED);

        //colocar na lista shots
        shots.push_back(shot);
    }

    player->setLastTimeShooting(iterations);
}

void Game::crash(Asteroid *asteroid_crashed){
    int n;

    Item *drop = asteroid_crashed->getItem();
    std::vector<Asteroid*> *subparts = asteroid_crashed->getParts();

    if(drop != NULL){
        drop->setPosition(asteroid_crashed->getPosition());
        items.push_back(drop);
    }

    std::vector<Asteroid*>::iterator it;

    //Remove Asteroid from scene
    for(it = asteroids.begin(); it != asteroids.end(); it++){
        if(*it == asteroid_crashed){
            asteroids.erase(it);
            break;
        }
    }

    //Put in scene all asteroids parts
    if(subparts != NULL){
        for(int i=0; i<subparts->size(); i++){
            subparts->at(i)->setPosition(asteroid_crashed->getPosition());
            asteroids.push_back(subparts->at(i));
        }
    }

    //Put the crashed asteroid to the destroyed list
    destroyed.push_back(asteroid_crashed);
}

void Game::removeShot(Shot *obj){
    for(std::vector<Shot*>::iterator it = shots.begin(); it != shots.end(); it++){
        if(obj == *it){
            shots.erase(it);
            break;
        }
    }
    to_shot.push_back(obj);
}

void Game::destroy(Polygon* obj){
    if(obj == player){
        player = NULL;
    }
    destroyed.push_back(obj);
}

void Game::assignItem(Aircraft *a, Item *it){
    a->catchItem(it);
}

void Game::iterate(bool boosting, bool turning_left, bool turning_right, bool shooting){
    int i, j;

    Shot *s;
    Asteroid *a;

    if(player != NULL){
        if(shooting && player->canShoot(iterations) && to_shot.size() > 0){
            shoot(player);
        }
    }

    // Crashing Asteroid
    for(i=0; i<asteroids.size(); i++){
        for(j=0; j<shots.size(); j++){
            a = asteroids.at(i);
            s = shots.at(j);

            if(s->hasPartsInsideOfPolygon(a)){
                crash(a);
                removeShot(s);
                i--;
                j--;
                break;
                break;
            }
        }
    }

    // Check for player crashes
    for(std::vector<Asteroid*>::iterator iast = asteroids.begin(); player != NULL && iast != asteroids.end(); iast++){
        if(player->hasPartsInsideOfPolygon(*iast)){
            destroy(player);
            break;
        }
    }

    // Check for item catches
    for(std::vector<Item*>::iterator iit = items.begin(); player != NULL && iit != items.end(); iit++){
        if(player->isInterceptingPolygon(*iit)){
            assignItem(player, *iit);
            items.erase(iit);
            destroyed.push_back(*iit);
            break;
        }
    }


    // Iterating Objects movements
    if(player != NULL) player->iterate(boosting, turning_left, turning_right);
    for(i=0; i<asteroids.size(); i++){
        asteroids.at(i)->iterate(false, true, false);
    }
    for(i=0; i<items.size(); i++){
        items.at(i)->iterate(false, false, false);
    }
    for(i=0; i<shots.size(); i++){
        shots.at(i)->iterate(false, false, false);
        shots.at(i)->reduceIterationsLeft();
    }

    // Iterating shots life-time
    for(std::vector<Shot*>::iterator is = shots.begin(); is != shots.end(); is++){
        if(!((*is)->hasIterationsLeft()) == true){
            s = *is;
            removeShot(s);
            break;
        }
    }


    iterations++;
}

void Game::draw(void){
    int i;

    if(player != NULL) player->draw();

    for(i=0; i<asteroids.size(); i++)
        asteroids.at(i)->draw();

    for(i=0; i<items.size(); i++)
        items.at(i)->draw();

    for(i=0; i<shots.size(); i++){
        shots.at(i)->draw();
    }

/*    std::string word;
    word = std::to_string(interceptions);
    printWord(0, 0, word.c_str(), GLUT_BITMAP_TIMES_ROMAN_10);*/
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
    //delete aircrafts[0];
    //delete aircrafts[1];
    //delete aircrafts[2];
}

