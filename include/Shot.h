#ifndef SHOT_H
#define SHOT_H

#include "Polygon.h"

class Shot : public Polygon{
    public:
        Shot();

        void setIterationsLeft(long);
        long getIterationsLeft();

        bool hasIterationsLeft();

        void reduceIterationsLeft();
        virtual ~Shot();
    protected:
    private:
        long iterations_left;
};

#endif // SHOT_H
