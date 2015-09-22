#ifndef CIRCLE_H
#define CIRCLE_H

#include "GameObj.h"
#include "Drawing.h"

class Circle : public Drawing{
    public:
        Circle(int);
        void draw();
        virtual ~Circle();
    protected:
    private:
        int radius;
};

#endif // CIRCLE_H
