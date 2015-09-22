#include "Polygon.h"
#include "../LUtil.h"
#include <cmath>
#include <climits>

Polygon::Polygon(){
}

//Adjust the center of polygon
void Polygon::centralize(){
    int i, n;

    Dot m(0,0);
    Dot dif;

    n = loop_vertex.size();
    for(i=0; i<n; i++){
        m = m + loop_vertex.at(i);
    }

    // This is the centroid
    m = m*(float)(1/n);

    // This is the difference to adjust
    dif = Dot(0,0) - m;

    for(i=0; i<n; i++){
        loop_vertex.at(i) = loop_vertex.at(i) + dif;
    }
}



bool Polygon::isInterceptingPolygon(Polygon *p){
    std::vector<Dot>::iterator d1, d2, d3, d4;
    //int m, n;

    //m = loop_vertex.size();
    //n = p->loop_vertex.size();

    //d1 = loop_vertex.at(m-1);
    //for(int i=0; i < m; i++){
    d1 = loop_vertex.end();
    for(d2 = loop_vertex.begin(); d2 != loop_vertex.end(); d2++){
        //d2 = loop_vertex.at(i);
        //d3 = p->loop_vertex.at(n-1);
        //for(int j=0; j < n; j++){
        d3 = p->loop_vertex.end();
        for(d4 = p->loop_vertex.begin(); d4 != p->loop_vertex.end(); d4++){
            //d4 = p->loop_vertex.at(j);
            if(isInterceptingSegments((*d1).transf(direction, position), (*d2).transf(direction, position), (*d3).transf(p->direction, p->position), (*d4).transf(p->direction, p->position)))
                return true;
            d3 = d4;
        }
        d1 = d2;
    }
    return false;
}


bool Polygon::hasDotInside(Dot p){
    int vertices, interceptions=0;

    Dot q(INT_MAX, INT_MAX);
    Dot r;
    Dot s;

    vertices = loop_vertex.size();
    r = loop_vertex.at(vertices-1);
    for(int i=0; i<vertices; i++){
        s = loop_vertex.at(i);
        if(isInterceptingSegments(p, q, r.transf(direction, position), s.transf(direction, position))){
            interceptions++;
        }
        r = s;
    }
    return (interceptions%2 == 0) ? false : true;
}

bool Polygon::hasPartsInsideOfPolygon(Polygon *p){
    Dot dot;
    int vertices;

    vertices = loop_vertex.size();
    for(int i=0; i<vertices; i++){
        dot = loop_vertex.at(i);
        if(p->hasDotInside(dot.transf(direction, position)))
            return true;
    }
    return false;
}


void Polygon::draw(){
    int i;
    Dot d;

    glLoadIdentity();
    glTranslatef(position.getX(), position.getY(), 0);
    glRotated(direction, 0, 0, 1);
    glColor3f(color[RED], color[GREEN], color[BLUE]);
    glBegin(GL_LINES);
    for(i=0; i<lines_vertex.size(); i++){
        d = lines_vertex.at(i);
        glVertex2f(d.getX(), d.getY());
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for(i=0; i<strip_vertex.size(); i++){
        d = strip_vertex.at(i);
        glVertex2f(d.getX(), d.getY());
    }
    glEnd();
    glBegin(GL_LINE_LOOP);
    for(i=0; i<loop_vertex.size(); i++){
        d = loop_vertex.at(i);
        glVertex2f(d.getX(), d.getY());
    }
    glEnd();
}

Polygon::~Polygon(){
    lines_vertex.clear();
    strip_vertex.clear();
    loop_vertex.clear();
}

