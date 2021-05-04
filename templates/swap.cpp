#include <iostream>
using namespace std;

template <class T> void swapy(T &a, T &b){

    T c =a;
    //c= a;
    a = b;
    b = c;
}

int main(){
    int x,y; x=5, y=7;

    double a, b;
    a = 100.50;
    b = 200.400;

    swapy(x,y);
    // swapy(a,b);
    cout << x <<endl;
    cout << y;
}