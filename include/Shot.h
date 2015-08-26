#ifndef SHOT_H
#define SHOT_H

#include "Polygon.h"

class Shot : public Polygon{
    public:
        Shot();

        void setActive(bool);
        bool getActive();

        virtual ~Shot();
    protected:
    private:
        bool active;
};

#endif // SHOT_H
