#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Polygon.h"
#include "Item.h"

#define MAX_HANDLING 7
#define MAX_ACCELERATION 0.2


class Aircraft : public Polygon{
    public:
        Aircraft(int);
        void catchItem(Item*);
        virtual ~Aircraft();
    protected:
    private:
        int model;
};

#endif // AIRCRAFT_H
