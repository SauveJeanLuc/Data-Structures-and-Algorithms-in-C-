#include <iostream>
using namespace std;

int * changeValues(int anyArray[],int length){
    anyArray[0]= 8;

    return anyArray;
}
int main(){
 int list[3]  = {1,2,3};
 changeValues(list,sizeof(list)/4);

 cout << "Value of element: " << list[0] <<endl;
}