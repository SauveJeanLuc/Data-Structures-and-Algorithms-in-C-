#include <iostream>
using namespace std;

int arrayDeclared[100], n = 100, top = -1;

void push(int data){

    if(top >= n-1)
        cout << "Stack Overflow" << endl;
    else{
        top++;
        arrayDeclared[top] = data;
        cout << "Data Pushed" << endl;
    }

}

void pop(){

    if( top <= -1){
        cout << "Stack UnderFlow" << endl;
    }
    else{
        top--;
        cout << "Data deleted";
    }
}

void peek(){

    if(top <= -1){
        cout << "Can't print any Data, The stack is Empty";
    }
    else{
        cout << "Data: " << arrayDeclared[top]<<endl;
    }
}

void display(){

    for(int i=top; i>=0; i--){
        cout << "Data: "<< arrayDeclared[i]<<endl;
    }
}

int main(){

    int choice, data;
    cout << "What size do you want your Stack to have: ";
    cin >> n;
    arrayDeclared[n];
    do{
        cout << endl;
        cout<<"1) Push" <<endl;
        cout<<"2) Pop" <<endl;
        cout<<"3) Peek" <<endl;
        cout<<"4) Display" <<endl;
        cout<<"5) Exit" <<endl;
        cout<< "Choice:";
        cin >> choice;
        cout << endl;
        
        switch (choice)
        {
        case 1:

            cout << "Enter data: ";
            cin >> data;
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;
            break;                                    
        default:
            break;
        }
    }while (choice!=5);
    
}