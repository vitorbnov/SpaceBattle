#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Polygon.h"
#include "Item.h"
#include "Shot.h"

#define MAX_HANDLING 7
#define MAX_ACCELERATION 0.2
#define NUM_SHOTS 16

class Aircraft : public Polygon{
    public:
        Aircraft(int);

        void catchItem(Item*);
        void upgradeStat(int);
        virtual ~Aircraft();
    protected:
    private:
        int model;
        int next_shot;
        Shot shots[NUM_SHOTS];
        std::vector<Dot> shot_dots;
        bool shielded;
};

#endif // AIRCRAFT_H
