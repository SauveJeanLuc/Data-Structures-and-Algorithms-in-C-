#include <iostream>
using namespace std;


class Polygon{
    protected:
    int numVertices;
    float xCoord, yCoord;

    public: 
    void set(float x,float y){
        xCoord = x;
        yCoord = y;
    }
    float getX(){
        return xCoord;
    }
    float area();
};

class Rectangle: public Polygon{
    public:
        float area(){
            return xCoord*yCoord;
        }
};

class Triangle: public Polygon{
    public:
        float area(){
            return (xCoord*yCoord)/2;
        }
};

int main(){

    Polygon matrix;
    matrix.set(6.9,7.8);
    cout << "X coord: " << matrix.getX() << endl;

    Rectangle ourRectangle;
    ourRectangle.set(5,6);
    cout << "Area of Rectangle: " << ourRectangle.area()<< endl;

    Triangle ourTriangle;
    ourTriangle.set(5,6);
    cout << "Area of Triangle: " << ourTriangle.area()<< endl;

    return 0;
}
