#include "../LUtil.h"
#include "GameObj.h"
#include <math.h>

GameObj::GameObj(){
    position = Dot(0,0);
    speed = Dot(0,0);
    direction = 90;

    acceleration = 0.05;
    handling = 2.5;

    commands[0] = false;
    commands[1] = false;
    commands[2] = false;
    commands[3] = false;
}

void GameObj::setPosition(Dot p){
    position = p;
}
void GameObj::setSpeed(Dot s){
    speed = s;
}
void GameObj::setSpeed(float angle, float module){
    speed.setX(module*cos(angle*PI/180));
    speed.setY(module*sin(angle*PI/180));
}
void GameObj::setDirection(float d){
    direction = d;
}
void GameObj::setAcceleration(float a){
    acceleration = a;
}
void GameObj::setHandling(float h){
    handling = h;
}
void GameObj::setCommand(int command_id, bool flag_value){
    commands[command_id] = flag_value;
}

void GameObj::setCommands(bool boost_command, bool turn_left, bool turn_right, bool shoot){
    commands[BOOST_COMMAND] = boost_command;
    commands[TURN_LEFT] = turn_left;
    commands[TURN_RIGHT] = turn_right;
    commands[SHOOT] = shoot;
}



void GameObj::sumSpeed(Dot s){
    speed = speed + s;
}
void GameObj::sumSpeed(float angle, float module){
    Dot s;
    s.setX(module*cos(angle*PI/180));
    s.setY(module*sin(angle*PI/180));
    speed = speed + s;
}


Dot GameObj::getPosition(){
    return position;
}
Dot GameObj::getSpeed(){
    return speed;
}
float GameObj::getDirection(){
    return direction;
}
float GameObj::getAcceleration(){
    return acceleration;
}
float GameObj::getHandling(){
    return handling;
}

bool* GameObj::getCommands(){
    return &commands[0];
}

bool* GameObj::getCommandAddress(int coomand_id){
    return &(commands[coomand_id]);
}






float GameObj::getSpeedModule(){
    return speed.module();
}

void GameObj::turnLeft(){
    direction += handling;
}

void GameObj::turnRight(){
    direction -= handling;
}

void GameObj::updatePosition(){
    position = position + speed;
}

void GameObj::updateSpeed(bool boosting){
    if(boosting){
        speed = speed + Dot((float)acceleration*cos(direction*PI/180), (float)acceleration*sin(direction*PI/180));
    }
}

void GameObj::limitPosition(){
    Dot pos = (Dot)getPosition();

    float x = pos.getX();
    float y = pos.getY();

    if(x < XMIN){
        pos = pos + Dot(2*XMAX, 0);
        setPosition(pos);
    }
    else if(x > XMAX){
        pos = pos + Dot(2*XMIN, 0);
        setPosition(pos);
    }
    if(y < YMIN){
        pos = pos + Dot(0, 2*YMAX);
        setPosition(pos);
    }
    else if(y > YMAX){
        pos = pos + Dot(0, 2*YMIN);
        setPosition(pos);
    }
}


void GameObj::limitSpeed(){
    float module = speed.module();
    float speed_angle = speed.angle();

    if(module > MAX_SPEED){
        speed.setX(MAX_SPEED*cos(speed_angle));
        speed.setY(MAX_SPEED*sin(speed_angle));
    }
}

void GameObj::iterate(){
    if(commands[TURN_LEFT])
        turnLeft();
    if(commands[TURN_RIGHT])
        turnRight();
    updateSpeed(commands[BOOST_COMMAND]);
    updatePosition();
    limitPosition();
    limitSpeed();
}

GameObj::~GameObj(){
    //dtor
}
