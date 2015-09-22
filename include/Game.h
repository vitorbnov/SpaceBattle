#ifndef GAME_H
#define GAME_H

#include <random>
#include "../LUtil.h"
#include "Polygon.h"
#include "Aircraft.h"
#include "Asteroid.h"
#include "Circle.h"

#define SHOTS_MAX 128

enum gameType{
    CAMPAIGN=0,
    ARCADE,
    CHALLENGE
};


class Game{
    public:
        Game();

        void setPlayer(Aircraft*);
        void pause();
        void continuee();
        void pauseOrContinue();

        Aircraft *getPlayer();
        bool isPaused();

        void resetPlayer();

        void setUpLevel(int, int);
        void advanceLevel();
        void clearLevel();

        void shoot(Aircraft*);
        void crash(Asteroid*);
        void removeShot(Shot*);
        void moveToDestroyed(GameObj*);
        void assignItem(Aircraft*, Item*);

        void iterate();

        void draw(void);
        void printWord(float, float, const char*, void*);

        virtual ~Game();
    protected:
    private:
        long iterations;

        int game_mode;
        int level;
        bool paused;
        Aircraft *player;
        Aircraft *player_dead;
        std::vector<Asteroid*> asteroids;
        //Shot *shot;
        std::vector<Item*> items;
        std::vector<Shot*> shots;
        std::vector<Shot*> to_shot;
        std::vector<GameObj*> destroyed;
        //std::poisson_distribution<long> enemies_comming();
        int interceptions;
        //vector<Polygon> enemies;
};

#endif // GAME_H
