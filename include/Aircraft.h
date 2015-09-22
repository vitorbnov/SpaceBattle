#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Polygon.h"
#include "Item.h"
#include "Shot.h"
#include "Gun.h"

#define MAX_SHIELD 50
#define MAX_HANDLING 5
#define MAX_ACCELERATION 0.11
#define MIN_DELAY_TIME_SHOOTING 5
#define MAX_ITERATIONS_RANGE_SHOOTING 75

class Aircraft : public Polygon{
    public:
        Aircraft(int);

        void setShield(int);
        void setDelayTimeShooting(int);
        void setLastTimeShooting(int);
        void setIterationsRangeShooting(long);

        int getModel();
        int getShield();
        int getDelayTimeShooting();
        int getLastTimeShooting();
        long getIterationsRangeShooting();

        bool isShielded();

        bool canShoot(long);
        void catchItem(Item*);
        void upgradeStat(int);
        int getGuns();
        Gun getGunAt(int);
        void damageShield(int);
        void resetStats();
        //void iterate();
        void draw();
        virtual ~Aircraft();
    protected:
    private:
        int model;
        int shield;
        bool dual;
        bool back_shot;
        int delay_time_shooting;
        int last_time_shooting;
        long iterations_range_shooting;
        std::vector<Dot> shield_vertex;
        std::vector<Gun> guns;
};

#endif // AIRCRAFT_H
