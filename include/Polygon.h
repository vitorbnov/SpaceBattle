#ifndef POLYGON_H
#define POLYGON_H

#include "Dot.h"
#include <vector>

#define MAX_SPEED 5

class Polygon{
    public:
        Polygon();

        // Setters
        void setColor(float, float, float);
        void setPosition(Dot);
        void setSpeed(Dot);
        void setSpeed(float, float);
        void setDirection(float);
        void setAcceleration(float);
        void setHandling(float);
        void sumSpeed(Dot);
        void sumSpeed(float, float);


        // Getters
        float* getColor();
        Dot getPosition();
        Dot getSpeed();
        float getDirection();
        float getAcceleration();
        float getHandling();

        void centralize();
        float getSpeedModule();
        void turnLeft();
        void turnRight();
        void updatePosition();
        void updateSpeed(bool);
        void limitPosition();
        void limitSpeed();
        void iterate(bool, bool, bool);
        void specificIterations(bool);
        bool isInterceptingSegments(Dot, Dot, Dot, Dot);
        bool isInterceptingPolygon(Polygon*);
        bool hasDotInside(Dot);
        bool hasPartsInsideOfPolygon(Polygon*);
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
