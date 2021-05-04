#include <iostream>
using namespace std;

void printAllDgl(int N, int a[][4]){
    int i=0, j=0;

    //Loop to print each diagonal
    for (int cnt = 0; cnt < 2*N-1 ; cnt++)
    {
        if(cnt<N){
            i = cnt;
            j = 0;
        }
        else{
            i = N-1;
            j = (cnt+1) % N;
        }

        while (i>=0 && j<N){
            cout << a[i][j];
            i--; j++;
        }
    }

}
    

int main(){
    int list[4][4]=
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    printAllDgl(4, list);
}