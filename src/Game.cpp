#include <iostream>
#include <cstdlib>
#include <cstring>
#include <random>
#include "../LUtil.h"
#include "Game.h"
#include "Polygon.h"
#include "Aircraft.h"

Game::Game(){
    iterations = 0;
    paused = false;

    player_dead = NULL;
    player = new Aircraft(0);
    player->centralize();
    player->setColor(1, 0, 0);

    //player->setAcceleration(0.11);
    //player->setDelayTimeShooting(10);
    //player->upgradeStat(HANDLING);

/*    Asteroid *asteroid = new Asteroid(BIG);
    //asteroid->setColor(0, 1, 0);
    asteroid->setSpeed(Dot(0.5, 1));
    asteroid->setHandling(1);
    asteroid->setPosition(Dot(0, 100));
    asteroid->centralize();
    asteroids.push_back(asteroid);

    asteroid = new Asteroid(BIG);
    //asteroid->setColor(0, 1, 0);
    asteroid->setSpeed(Dot(-0.5, 1));
    asteroid->setHandling(1);
    asteroid->setPosition(Dot(0, -100));
    asteroid->centralize();
    asteroids.push_back(asteroid);

    asteroid = new Asteroid(BIG);
    //asteroid->setColor(0, 1, 0);
    asteroid->setSpeed(Dot(-0.5, 1));
    asteroid->setHandling(1);
    asteroid->setPosition(Dot(-100, 0));
    asteroid->centralize();
    asteroids.push_back(asteroid);
*/

    Shot *shot;
    for(int i=0; i<SHOTS_MAX; i++){
        shot = new Shot();
        to_shot.push_back(shot);
    }

    srand(time(NULL));

    setUpLevel(ARCADE, 1);
}

void Game::setPlayer(Aircraft *p){
    player = p;
}

void Game::pause(){
    paused = true;
}

void Game::continuee(){
    paused = false;
}

void Game::pauseOrContinue(){
    paused = !paused;
}

Aircraft* Game::getPlayer(){
    return player;
}

bool Game::isPaused(){
    return paused;
}


void Game::resetPlayer(){
    int model = player->getModel();

    delete player;

    player = new Aircraft(model);
}

void Game::setUpLevel(int game_mode, int level_number){
    clearLevel();
    Asteroid *asteroid;

    int radius = XMAX;
    int angle = 360/level_number;
    int d_angle = rand()%angle;

    for(int i=0; i<level_number; i++){
        asteroid = new Asteroid(BIG);
        asteroid->setPosition(Dot(radius*cos((i*angle+d_angle)*PI/180), radius*sin((i*angle+d_angle)*PI/180)));
        asteroid->setSpeed(rand()%360, 0.5+(rand()%150)*0.01);
        asteroids.push_back(asteroid);
    }

    /*if(player_dead != NULL){
        player = player_dead;
        player_dead = NULL;
    }*/
    player->setPosition(Dot(0,0));
    player->setSpeed(Dot(0,0));
    player->setDirection(90);
    player->setLastTimeShooting(-(player->getDelayTimeShooting()));

    continuee();
    level = level_number;
    iterations = 0;
}

void Game::advanceLevel(){
    setUpLevel(game_mode, level+1);
}

void Game::clearLevel(){
    Asteroid *asteroid;
    Item *item;
    GameObj *gameobj;
    Shot *shot;

    /*while(!asteroids.empty()){
        asteroid = asteroids.back();
        asteroids.pop_back();
        delete asteroid;
    }

    while(!items.empty()){
        delete items.back();
        items.pop_back();
    }

    while(!destroyed.empty()){
        delete destroyed.back();
        destroyed.pop_back();
    }
    */
    asteroids.clear();
    items.clear();
    destroyed.clear();

    while(!shots.empty()){
        shot = shots.back();
        shots.pop_back();
        to_shot.push_back(shot);
    }
}

void Game::shoot(Aircraft* aircraft_to_shot){
    int guns;
    Shot *shot;
    Gun gun;

    Dot aircraft_position = aircraft_to_shot->getPosition();
    float aircraft_direction = aircraft_to_shot->getDirection();

    guns = aircraft_to_shot->getGuns();

    for(int i=0; i<guns; i++){
        gun = aircraft_to_shot->getGunAt(i);

        if(!to_shot.empty()){
            //Remove from to_shot list
            shot = to_shot.back();
            to_shot.pop_back();

            //set values from aircraft stateŝ
            shot->setPosition(gun.getPosition().transf(aircraft_direction, aircraft_position));
            shot->setDirection(gun.getDirection() + aircraft_direction);
            shot->setSpeed(gun.getDirection() + aircraft_direction, MAX_SPEED);
            shot->setIterationsLeft(aircraft_to_shot->getIterationsRangeShooting());

            aircraft_to_shot->sumSpeed(shot->getDirection() + 180, 1.0/MAX_SPEED);

            //colocar na lista shots
            shots.push_back(shot);

            player->setLastTimeShooting(iterations);
        }
    }
}

void Game::crash(Asteroid *asteroid_crashed){

    Item *drop = asteroid_crashed->getItem();
    std::vector<Asteroid*> crashed_parts;
    Asteroid *asteroid;

    if(drop != NULL){
        asteroid_crashed->setItem(NULL);
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
    while(asteroid_crashed->hasParts()){
        asteroid = asteroid_crashed->popBackPart();
        asteroid->setPosition(asteroid_crashed->getPosition());
        asteroids.push_back(asteroid);
    }
    /*
    if(asteroid_crashed.hasParts()){
        for(int i=0; i<subparts->size(); i++){
            subparts->at(i)->setPosition(asteroid_crashed->getPosition());
            asteroids.push_back(subparts->at(i));
        }
    }*/

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

void Game::moveToDestroyed(GameObj* obj){
    if(obj == player){
        player_dead = (Aircraft*)obj;
        player = NULL;
    }
    else{
        destroyed.push_back(obj);
    }
}

void Game::assignItem(Aircraft *a, Item *it){
    a->catchItem(it);
}

void Game::iterate(){
    int i, j;

    Shot *s;
    Asteroid *a;


    // Player shooting
    if(player != NULL){
        if(*(player->getCommandAddress(SHOOT)) && player->canShoot(iterations) && to_shot.size() > 0){
            shoot(player);
        }
    }

    // Shootings at Asteroids
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
            if(player->isShielded()){
                player->damageShield(1);
            }
            else{
                moveToDestroyed(player);
            }
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
    if(player != NULL) player->iterate();
    for(i=0; i<asteroids.size(); i++){
        asteroids.at(i)->iterate();
    }
    for(i=0; i<items.size(); i++){
        items.at(i)->iterate();
    }
    for(i=0; i<shots.size(); i++){
        shots.at(i)->iterate();
    }

    // Iterating shots life-time
    for(std::vector<Shot*>::iterator is = shots.begin(); is != shots.end(); is++){
        if(!((*is)->hasIterationsLeft())){
            s = *is;
            removeShot(s);
            break;
        }
    }

    if(!destroyed.empty()){
        //delete destroyed.back();
        //destroyed.pop_back();
    }

    iterations++;

    // Is level clear
    if(asteroids.size() == 0){
        advanceLevel();
    }

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


    glColor3f(0.5, 0.5, 0);
    std::string word;
    word = "level ";
    word += std::to_string(level);
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
    delete player;
    delete player_dead;
    clearLevel();
}

