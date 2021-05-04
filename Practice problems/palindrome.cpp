#include <iostream>
using namespace std;

struct Node{
    char data;
    Node * next;
};

Node *top = NULL;
Node *topChecking = NULL;

void push(char data){
    Node *newNode = new Node;
    newNode->data =data;
    newNode->next = top;
 
    top = newNode;
}

void pushSecondStack(char data){
    Node *newNode = new Node;
    newNode->data =data;
    newNode->next =topChecking;
 
    topChecking = newNode;
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

void displaySecondStack(){
    if(topChecking==NULL){
        cout << "Nothing to display, the Stack is Empty";
    }
    else{
        Node *temp = topChecking;
        while (temp!=NULL)
        {
            cout << "Data: " << temp->data <<endl;
            temp = temp->next;
        }
    }
}

bool checkPalindrome(int numberOfCharacters){
    if(top==NULL){
        cout << "Nothing to check, the Stack is Empty";
    }
    else{   
            Node *temp = top;
            Node *tempClone = top;
            // Fill second stack with the inverse of the first              
            for(int i=0; i<numberOfCharacters; i++){
                pushSecondStack(tempClone->data);
                tempClone = tempClone->next;
            }
            Node *tempTwo = topChecking;  

        while (temp!=NULL)
        {   

            if(temp->data != tempTwo->data){
                return false;
            }
            temp = temp->next;
            tempTwo = tempTwo->next;
        }
        return true;
    }
}

int main(){
    int numberOfChar;
    char givenCharacter;
    bool response;

    cout << "How many Characters does your String have?:  ";
    cin >> numberOfChar;
    cout << "Enter the characters one by one: "<<endl;

    for(int i=0; i<numberOfChar; i++){
        cin >> givenCharacter;
        push(givenCharacter);
    }

    response = checkPalindrome(numberOfChar);


    if(response){
        cout << "Your String is a palindrome";
    }
    else{
        cout << "Your String is a not a palindrome";
    }
    
}