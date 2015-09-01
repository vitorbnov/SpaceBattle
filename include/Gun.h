#ifndef GUN_H
#define GUN_H

#include "Dot.h"

class Gun{
    public:
        Gun();
        Gun(float, Dot);

        void setDirection(float);
        void setPosition(Dot);

        float getDirection();
        Dot getPosition(void);

        virtual ~Gun();
    protected:
    private:
        float direction;
        Dot position;
};

#endif // GUN_H
