#ifndef ITEM_H
#define ITEM_H

#include "Polygon.h"

#define NUM_ITEMS 6

enum itemCode{
    SHIELD = 0,
    //BACK,
    DUAL,
    FAST,
    LONG,
    HANDLING,
    BOOST_ITEM,
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
