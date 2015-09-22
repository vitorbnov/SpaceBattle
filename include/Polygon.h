#ifndef POLYGON_H
#define POLYGON_H

#include "Dot.h"
#include "GameObj.h"
#include "Polygon.h"
#include "Drawing.h"
#include <vector>

class Polygon : public Drawing{
    public:
        Polygon();
        void centralize();

        bool isInterceptingPolygon(Polygon*);
        bool hasDotInside(Dot);
        bool hasPartsInsideOfPolygon(Polygon*);
        void draw();
        virtual ~Polygon();
    protected:
        std::vector<Dot> lines_vertex; // Drawn with GL_LINES
        std::vector<Dot> strip_vertex; // Drawn with GL_LINE_STRIP
        std::vector<Dot> loop_vertex; // Drawn with GL_LINE_LOOP
};

#endif // POLYGON_H
