#include <iostream>
using namespace std;

int main(){
    int var = 20;
    int *pointing;
    pointing = &var;

    cout<< "Value of Pointing: " << pointing << endl;
    cout<< "Value of *Pointing: " << *pointing << endl;

    

}