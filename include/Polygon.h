#ifndef POLYGON_H
#define POLYGON_H

#include "Dot.h"
#include <vector>

#define MAX_SPEED 5

class Polygon{
    public:
        // Setters
        void setColor(float, float, float);
        void setPosition(Dot);
        void setSpeed(Dot);
        void setDirection(float);
        void setAcceleration(float);
        void setHandling(float);

        // Getters
        float* getColor();
        Dot getPosition();
        Dot getSpeed();
        float getDirection();
        float getAcceleration();
        float getHandling();

        float getSpeedModule();
        void turnLeft();
        void turnRight();
        void updatePosition();
        void updateSpeed(bool);
        void iterate(bool);
        void draw();
        virtual ~Polygon();
    protected:
        std::vector<Dot> lines_vertex; // Drawn with GL_LINES
        std::vector<Dot> strip_vertex; // Drawn with GL_LINE_STRIP
        std::vector<Dot> loop_vertex; // Drawn with GL_LINE_LOOP
        float color[3];
        Dot position;
        Dot speed;
        float direction;
        float acceleration;
        float handling;
};

#endif // POLYGON_H