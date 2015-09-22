#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include "Dot.h"
#define MAX_SPEED 5

#define NUM_COMMANDS 4

enum gameCommand{
    BOOST_COMMAND=0,
    TURN_LEFT,
    TURN_RIGHT,
    SHOOT
};


class GameObj{
    public:
        GameObj();

        //Setters
        void setPosition(Dot);
        void setSpeed(Dot);
        void setSpeed(float, float);
        void setDirection(float);
        void setAcceleration(float);
        void setHandling(float);
        void setCommand(int, bool);
        void setCommands(bool, bool, bool, bool);


        void sumSpeed(Dot);
        void sumSpeed(float, float);

        //Getters
        Dot getPosition();
        Dot getSpeed();
        float getDirection();
        float getAcceleration();
        float getHandling();
        bool* getCommands();
        bool* getCommandAddress(int);

        float getSpeedModule();
        void turnLeft();
        void turnRight();
        void updatePosition();
        void updateSpeed(bool);
        void limitPosition();
        void limitSpeed();
        void iterate();
        void specificIterations(bool);
        virtual ~GameObj();
    protected:
        bool commands[NUM_COMMANDS];
        Dot position;
        Dot speed;
        float direction;
        float acceleration;
        float handling;
    private:
};

#endif // GAMEOBJ_H
