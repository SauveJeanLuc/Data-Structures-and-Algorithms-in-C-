#include <iostream>
using namespace std;

// Program to Illustrate Single Inheritance

class Parent{
    public: 
    string firstName;
    string nationality;

    private:
    string secondName;
};

class Child : public Parent{
    public: 
    string secondName;
};

int main(){

    Child Kenny;

    Kenny.firstName = "Kenny";
    Kenny.secondName = "Munezero";

    cout << "Names: " << Kenny.firstName <<" "<< Kenny.secondName << endl;
}