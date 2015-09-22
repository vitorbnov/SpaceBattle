#ifndef DRAWING_H
#define DRAWING_H

#include "GameObj.h"

enum Color{
    RED=0,
    GREEN,
    BLUE
};

class Drawing : public GameObj{
    public:
        Drawing();

        // Setters
        void setColor(float, float, float);

        // Getters
        float* getColor();

        //virtual void draw();
        virtual ~Drawing();
    protected:
        float color[3];
    private:
};

#endif // DRAWING_H
