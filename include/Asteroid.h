#ifndef ASTEROID_H
#define ASTEROID_H

#include "Polygon.h"
#include "Item.h"
#include <vector>

enum ASTEROID_SIZE{
    SMALL = 0,
    MEDIUM,
    BIG
};

class Asteroid : public Polygon{
    public:
        Asteroid(int);

        void setItem(Item*);
        void addPart(Asteroid*);
        Asteroid* backPart();
        Asteroid* popBackPart();
        bool hasParts();

        Item* getItem();

        virtual ~Asteroid();
    protected:
    private:
        std::vector<Asteroid*> parts;
        Item *item;
};

#endif // ASTEROID_H
