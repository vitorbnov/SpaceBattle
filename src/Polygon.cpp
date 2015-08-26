#include "Polygon.h"
#include "../LUtil.h"
#include <cmath>
#include <climits>

Polygon::Polygon(){
    color[RED] = 1;
    color[GREEN] = 1;
    color[BLUE] = 1;

    position = Dot(0,0);
    speed = Dot(0,0);
    direction = 90;

    acceleration = 0.05;
    handling = 2.5;
}

void Polygon::setColor(float red, float green, float blue){
    color[RED] = red;
    color[GREEN] = green;
    color[BLUE] = blue;
}
void Polygon::setPosition(Dot p){
    position = p;
}
void Polygon::setSpeed(Dot s){
    speed = s;
}
void Polygon::setSpeed(float angle, float module){
    speed.setX(module*cos(angle));
    speed.setY(module*sin(angle));
}
void Polygon::setDirection(float d){
    direction = d;
}
void Polygon::setAcceleration(float a){
    acceleration = a;
}
void Polygon::setHandling(float h){
    handling = h;
}

float* Polygon::getColor(){
    return color;
}
Dot Polygon::getPosition(){
    return position;
}
Dot Polygon::getSpeed(){
    return speed;
}
float Polygon::getDirection(){
    return direction;
}
float Polygon::getAcceleration(){
    return acceleration;
}
float Polygon::getHandling(){
    return handling;
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

float Polygon::getSpeedModule(){
    return speed.module();
}

void Polygon::turnLeft(){
    direction += handling;
}

void Polygon::turnRight(){
    direction -= handling;
}

void Polygon::updatePosition(){
    position = position + speed;
}

void Polygon::updateSpeed(bool boosting){
    if(boosting){
        speed = speed + Dot((float)acceleration*cos(direction*PI/180), (float)acceleration*sin(direction*PI/180));
    }
}

void Polygon::limitPosition(){
    Dot pos = (Dot)getPosition();

    float x = pos.getX();
    float y = pos.getY();

    if(x < XMIN){
        pos = pos + Dot(2*XMAX, 0);
        setPosition(pos);
    }
    else if(x > XMAX){
        pos = pos + Dot(2*XMIN, 0);
        setPosition(pos);
    }
    if(y < YMIN){
        pos = pos + Dot(0, 2*YMAX);
        setPosition(pos);
    }
    else if(y > YMAX){
        pos = pos + Dot(0, 2*YMIN);
        setPosition(pos);
    }
}


void Polygon::limitSpeed(){
    float module = speed.module();
    float speed_angle = speed.angle();

    if(module > MAX_SPEED){
        speed.setX(MAX_SPEED*cos(speed_angle));//*PI/180
        speed.setY(MAX_SPEED*sin(speed_angle));//*PI/180
    }
}

void Polygon::iterate(bool boosting, bool turning_left, bool turning_right){
    if(turning_left)
        turnLeft();
    if(turning_right)
        turnRight();
    updateSpeed(boosting);
    updatePosition();
    limitPosition();
    limitSpeed();
}

// Dot Interception
bool Polygon::isInterceptingSegments(Dot A1, Dot A2, Dot B1, Dot B2){
    float SA1, SA2, SB1, SB2;

    SA1 = A1.whichSide(B1, B2);
    SA2 = A2.whichSide(B1, B2);

    SB1 = B1.whichSide(A1, A2);
    SB2 = B2.whichSide(A1, A2);

    if(((SB2 <= 0 && SB1 >= 0) || (SB1 <= 0 && SB2 >= 0)) && ((SA2 <= 0 && SA1 >= 0) || (SA1 <= 0 && SA2 >= 0)))
        return true;
    return false;
}

bool Polygon::isInterceptingPolygon(Polygon *p){
    Dot d1, d2, d3, d4;
    int m, n;

    m = loop_vertex.size();
    n = p->loop_vertex.size();

    d1 = loop_vertex.at(m-1);
    for(int i=0; i < m; i++){
        d2 = loop_vertex.at(i);
        d3 = p->loop_vertex.at(n-1);
        for(int j=0; j < n; j++){
            d4 = p->loop_vertex.at(j);
            if(isInterceptingSegments(d1.transf(direction, position), d2.transf(direction, position), d3.transf(p->direction, p->position), d4.transf(p->direction, p->position)))
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

bool Polygon::isInsideOfPolygon(Polygon *p){
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
    unsigned int i;
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

