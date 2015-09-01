#ifndef GAME_H
#define GAME_H

#include "../LUtil.h"
#include "Polygon.h"
#include "Aircraft.h"
#include "Asteroid.h"

#define SHOTS_MAX 64

class Game{
    public:
        Game();

        void setPlayer(Aircraft*);
        Aircraft *getPlayer();

        void shoot(Aircraft*);
        void crash(Asteroid*);
        void removeShot(Shot*);
        void destroy(Polygon*);
        void assignItem(Aircraft*, Item*);
        void iterate(bool, bool, bool, bool);
        void draw(void);
        void printWord(float, float, const char*, void*);
        virtual ~Game();
    protected:
    private:
        long iterations;
        //Aircraft *aircrafts[3];
        Aircraft *player;
        std::vector<Asteroid*> asteroids;
        //Shot *shot;
        std::vector<Item*> items;
        std::vector<Shot*> shots;
        std::vector<Shot*> to_shot;
        std::vector<Polygon*> destroyed;
        int interceptions;
        //vector<Polygon> enemies;
};

#endif // GAME_H
