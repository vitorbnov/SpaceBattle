#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Polygon.h"
#include "Item.h"
#include "Shot.h"
#include "Gun.h"

#define MAX_HANDLING 7
#define MAX_ACCELERATION 0.2

class Aircraft : public Polygon{
    public:
        Aircraft(int);

        void setDelayTimeShooting(long);
        void setLastTimeShooting(long);
        void setIterationsRangeShooting(long);

        long getDelayTimeShooting();
        long getLastTimeShooting();
        long getIterationsRangeShooting();

        bool canShoot(long);
        void catchItem(Item*);
        void upgradeStat(int);
        int getGuns();
        Gun getGunAt(int);
        virtual ~Aircraft();
    protected:
    private:
        int model;
        bool shielded;
        bool dual;
        bool back_shot;
        long delay_time_shooting;
        long last_time_shooting;
        long iterations_range_shooting;
        std::vector<Gun> guns;
};

#endif // AIRCRAFT_H
