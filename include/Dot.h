#ifndef DOT_H
#define DOT_H

class Dot{
    public:
        // Constructor
        Dot(void);
        Dot(float, float);

        // Setters
        void setX(float);
        void setY(float);

        // Getters
        float getX();
        float getY();

        // Sum of Dots
        Dot operator+(Dot p);
        Dot operator-(Dot p);

        //Module
        float module();

        //Triangle Area between 3 points
        float triangleArea(Dot,Dot);

        // Destructor
        virtual ~Dot();
    private:
        float x;
        float y;
};

#endif // DOT_H
