#ifndef ITEM_H
#define ITEM_H

#include "Polygon.h"

enum ICode{
    SHIELD = 0,
    BACK,
    DUAL,
    FAST,
    LONG,
    HANDLING,
    BOOST,
};

class Item : public Polygon{
    public:
        Item(int);
        void setType(int);
        int getType();
        ~Item();
    protected:
        int id;
};

#endif // ITEM_H
