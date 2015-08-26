#ifndef GAME_H
#define GAME_H

#include "../LUtil.h"
#include "Polygon.h"
#include "Aircraft.h"
#include "Asteroid.h"

class Game{
    public:
        Game();

        void setPlayer(Aircraft*);
        Aircraft *getPlayer();

        void checkPositions(Polygon*);
        void iterate(bool, bool, bool);
        void draw(void);
        void printWord(float, float,const char*, void*);
        virtual ~Game();
    protected:
    private:
        Aircraft *aircrafts[3];
        Aircraft *player;
        Asteroid *asteroid;
        Shot *shot;
        Item *item;
        int interceptions;
        //vector<Polygon> enemies;
};

#endif // GAME_H
