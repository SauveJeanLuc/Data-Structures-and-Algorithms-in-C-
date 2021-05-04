#include <iostream>
using namespace std;

// Program to illustrate Multi-Level Inheritance

class Vehicle{

    protected:
        string name;
        string operatingEnv;
        bool worksOnLand;
};

class Car : public Vehicle{
    protected:
        int numberOfWheels;
        string color;
};

class SportsCar : public Car{
    public:
        string manufacturer; 
};


int main(){

    SportsCar suden;
    

}