#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};

Node *top = NULL;
void push(int data){
    Node *newNode = new Node;
    newNode->data =data;
    newNode->next = top;
 
    top = newNode;
}

void pop(){
    if(top==NULL){
        cout << "Stack underflow";
    }
    else{
        top = top->next;
    }
}

void peek(){
    cout << "Data: " << top->data;
}

void display(){
    if(top==NULL){
        cout << "Nothing to display, the Stack is Empty";
    }
    else{
        Node *temp = top;
        while (temp!=NULL)
        {
            cout << "Data: " << temp->data <<endl;
            temp = temp->next;
        }
    }
}

int main(){
int choice, data;
    do{
        cout<<"1) Push" <<endl;
        cout<<"2) Pop" <<endl;
        cout<<"3) Peek" <<endl;
        cout<<"4) Display" <<endl;
        cout<<"5) Exit" <<endl;
        cout<< "Choice:";
        cin >> choice;
        
        switch (choice)
        {
        case 1:

            cout << "Enter data: ";
            cin >> data;
            push(data);
            break;

        case 2:
            pop();
            cout <<"Data Popped";
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