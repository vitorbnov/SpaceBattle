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
        Dot operator+(Dot);
        Dot operator-(Dot);

        // Scalar product
        float operator*(Dot);

        // Scalar multiply
        Dot operator*(float);

        //Module
        float module();

        //Angle
        float angle();

        //Transform point coordinates
        Dot transf(float, Dot);

        //Triangle Area between 3 points
        float whichSide(Dot,Dot);

        // Destructor
        virtual ~Dot();
    private:
        float x;
        float y;
};

#endif // DOT_H
